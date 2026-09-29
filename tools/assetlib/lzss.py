"""Rare's LZSS: the second decompressor func_8028B4C4 can pick (arg5 == 2,
func_802C41C0 in hd_code's handwritten 7F8B0).

It is Mark Nelson's LZSS from "The Data Compression Book" (1991): a bit
stream, most significant bit first; a 1 bit and eight bits is a literal, a 0
bit is a match of an `index_bits` window position and a `16 - index_bits`
length; position 0 ends the stream.  The window starts empty at position 1.
Rare's one change is BREAK_EVEN = 2 (Nelson derives 1 from the bit counts),
so a match is 3 to (1 << (16 - index_bits)) + 2 bytes.  The decoder skips to
an even input address at the end, and the files have a zero byte there.

The callers pass index_bits: 13 for the sound banks' .ctl and the three
320x240 background images, 10 for static_data.

encode() is Nelson's binary-tree encoder with that BREAK_EVEN; it reproduces
every compressed file in all four ROMs byte for byte (ties in the tree go to
the later node, as his `if (i >= match_length)` does).
"""


def decode(src, pos, index_bits):
    """Inflate the stream at src[pos:].  Returns (data, bytes consumed,
    including the pad to an even length)."""
    mask = (1 << index_bits) - 1
    len_bits = 16 - index_bits
    window = bytearray(1 << index_bits)
    wp = 1
    out = bytearray()
    bit_mask = 0x80
    cur = 0
    p = pos

    def bits(k):
        nonlocal bit_mask, cur, p
        v = 0
        for _ in range(k):
            if bit_mask == 0x80:
                cur = src[p]
                p += 1
            v = (v << 1) | (1 if cur & bit_mask else 0)
            bit_mask >>= 1
            if bit_mask == 0:
                bit_mask = 0x80
        return v

    while True:
        if bits(1):
            c = bits(8)
            out.append(c)
            window[wp] = c
            wp = (wp + 1) & mask
        else:
            off = bits(index_bits)
            if off == 0:
                break
            n = bits(len_bits) + 3
            for k in range(n):
                c = window[(off + k) & mask]
                out.append(c)
                window[wp] = c
                wp = (wp + 1) & mask
    if (p - pos) & 1:
        p += 1
    return bytes(out), p - pos


def encode(data, index_bits, break_even=2):
    """Compress data; the result is padded to an even length."""
    W = 1 << index_bits
    M = W - 1
    LA = (1 << (16 - index_bits)) + break_even
    ROOT = W
    window = bytearray(W)
    parent = [0] * (W + 1)
    small = [0] * (W + 1)
    large = [0] * (W + 1)
    out = bytearray()
    mask = 0x80
    rack = 0

    def put(v, k):
        nonlocal mask, rack
        b = 1 << (k - 1)
        while b:
            if v & b:
                rack |= mask
            mask >>= 1
            if mask == 0:
                out.append(rack)
                rack = 0
                mask = 0x80
            b >>= 1

    def contract(old, new):
        parent[new] = parent[old]
        p = parent[old]
        if large[p] == old:
            large[p] = new
        else:
            small[p] = new
        parent[old] = 0

    def replace(old, new):
        p = parent[old]
        if small[p] == old:
            small[p] = new
        else:
            large[p] = new
        parent[new] = parent[old]
        small[new] = small[old]
        large[new] = large[old]
        parent[small[new]] = new
        parent[large[new]] = new
        parent[old] = 0

    def delete(p):
        if parent[p] == 0:
            return
        if large[p] == 0:
            contract(p, small[p])
        elif small[p] == 0:
            contract(p, large[p])
        else:
            r = small[p]
            while large[r] != 0:
                r = large[r]
            delete(r)
            replace(p, r)

    def add(new):
        t = large[ROOT]
        ml = mp = 0
        while True:
            i = 0
            delta = 0
            while i < LA:
                delta = window[(new + i) & M] - window[(t + i) & M]
                if delta:
                    break
                i += 1
            if i >= ml:
                ml, mp = i, t
                if ml >= LA:
                    replace(t, new)
                    return ml, mp
            child = large if delta >= 0 else small
            if child[t] == 0:
                child[t] = new
                parent[new] = t
                large[new] = small[new] = 0
                return ml, mp
            t = child[t]

    cur = 1
    n = min(LA, len(data))
    window[cur:cur + n] = data[:n]
    pos = look_ahead = n
    large[ROOT] = cur
    parent[cur] = ROOT
    ml = mp = 0
    while look_ahead > 0:
        ml = min(ml, look_ahead)
        if ml <= break_even:
            count = 1
            put(1, 1)
            put(window[cur], 8)
        else:
            put(0, 1)
            put(mp, index_bits)
            put(ml - (break_even + 1), 16 - index_bits)
            count = ml
        for _ in range(count):
            delete((cur + LA) & M)
            if pos >= len(data):
                look_ahead -= 1
            else:
                window[(cur + LA) & M] = data[pos]
                pos += 1
            cur = (cur + 1) & M
            if look_ahead:
                if cur == 0:
                    ml = 0
                else:
                    ml, mp = add(cur)
    put(0, 1)
    put(0, index_bits)
    if mask != 0x80:
        out.append(rack)
    if len(out) & 1:
        out.append(0)
    return bytes(out)

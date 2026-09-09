# Blast Corps decompilation

A matching decompilation of Blast Corps / Blastdozer. Nothing is decompiled to C
yet beyond one proof-of-concept function; the repo currently guarantees that the
disassembly reassembles into the original ROMs byte for byte.

## Build

Needs `mips-linux-gnu-` binutils on `PATH` and splat's Python deps in a venv.
`VERSION` is one of `us.v10 us.v11 jp eu`, default `us.v11`.

```
make VERSION=us.v11 extract                  # stage 1: split the ROM
make VERSION=us.v11                          # stage 1: relink, sha1-checked
make VERSION=us.v11 decompress               # inflate the gzipped code modules
make VERSION=us.v11 -C blastcorps extract    # stage 2: disassemble
make VERSION=us.v11 -C blastcorps            # stage 2: reassemble, sha1-checked
make VERSION=us.v11 -C blastcorps compress   # re-deflate into assets/
make VERSION=us.v11                          # relink the ROM from that
```

`asm/` and `assets/` hold one version at a time. Switching `VERSION` without
`make clean` (both directories) is rejected by the `stamp` target — that guard
exists because stale output from another version otherwise links in silently and
surfaces only as a confusing sha1 mismatch.

## What "matching" depends on

The sha1 checks are the arbiter. Everything below is a way to keep them passing.

- **gzip mtimes are part of the compressed stream.** The `*_TIMESTAMP` values in
  `blastcorps/Makefile` come from each ROM's own gzip headers. A wrong one makes
  a rebuilt section differ even when the code inside it is identical.
- **Padding must stay outside the code sections.** `hd_code_*` and
  `hd_front_end_*` get inflated and re-deflated, so a recompressed section is the
  bare gzip stream. Any inter-section padding folded into a segment shifts
  everything after it. Asset segments are opaque and may absorb their padding.
  This was a live bug in `blastcorps.us.v10.yaml` (`0x7f9c76` should have been
  `0x7f9c75`).
- **Config offsets are generated, not hand-written.** `tools/gen_build_yaml.py`
  reads the top-level split straight out of the ROM (gzip members are
  self-delimiting); `tools/gen_code_yaml.py` runs splat once for file boundaries
  and emits the stage-2 module configs. Both reproduce the hand-maintained US
  configs, so prefer regenerating over editing offsets by hand.

## Layout notes

Load addresses, identical across all four revisions:

| module         | VRAM         | notes                                          |
| ---            | ---          | ---                                            |
| `init`         | `0x8021ED00` | uncompressed at ROM `0x1000`                   |
| `hd_code`      | `0x802447C0` | staged at `0x80000400`, inflated by `init`     |
| `hd_front_end` | `0x801E7000` | inflated by `func_8028B3E0` in `hd_code`       |

Regions kept as `bin` because they are not r4300 code:

- The last `0xFB0` bytes of every `hd_front_end` `.text` are RSP microcode
  (`sp = 0x110`, loads from DMEM `0xFC4`, exactly IMEM-sized).
- Four data blobs inside each `hd_code` `.text`; sizes are `0x1140`, `0x28C0`,
  `0xF60` and `0x36F0` in `jp`/`eu`. Find them by assembling every `asm/hd_code/*.s`
  and bracketing the failures — capstone decodes data as Octeon opcodes
  (`bbit0`, `synci`, `dlsa`) that `-march=vr4300` then rejects.

Landing a `bin` region slightly wide or narrow is harmless: a data word that
happens to decode as a real instruction reassembles to the same bytes. Only the
sha1 decides.

## Conventions

- Straight to `main`; this project does not use branches.
- `docs/sm64tools-configs/` are queueRAM's original configs, kept for reference.
  Their offsets are not always right (the `jp` `hd_front_end_data` end is wrong),
  so verify against the ROM before trusting one.

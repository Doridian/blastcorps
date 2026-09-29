#!/usr/bin/env python3
"""Compare two pacing logs, the port's (PORT_PACE=FILE) and mupen64plus's
(port/tools/m64p_pace.c): for each run of one game mode (D_80364A90), the
game frames, the retraces they took and the retrace it started at.

    port/tools/pace_cmp.py port.csv mupen/pace.csv
"""
import csv, sys
def segs(p):
    rows=list(csv.DictReader(open(p)))
    out=[];prev=None;start=None
    for r in rows+[None]:
        if r is None or r['mode']!=prev:
            if prev is not None:
                end=r or rows[-1]
                out.append((prev,int(end['poll'])-int(start['poll']),int(end['retraces'])-int(start['retraces']),int(start['retraces'])))
            if r: prev=r['mode'];start=r
    return out,rows
a,ra=segs(sys.argv[1]); b,rb=segs(sys.argv[2])
print('%-18s | %-26s | %-26s'%('mode','port frames/retr (start)','mupen frames/retr (start)'))
for i in range(max(len(a),len(b))):
    x=a[i] if i<len(a) else None; y=b[i] if i<len(b) else None
    f=lambda s: '%5d/%5d=%.2f @%5d'%(s[1],s[2],s[2]/max(s[1],1),s[3]) if s else ''
    print('%-18s | %-26s | %-26s %s'%((x or y)[0],f(x),f(y),'' if (x and y and x[0]==y[0]) else 'MODE DIFFERS'))

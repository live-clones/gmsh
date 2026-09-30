#!/usr/bin/env python3
# Compares two runs of run.py (e.g. of the build before and after a change):
# the images of every step, the picks, and the timings.
#
#   python3 compare.py reference_dir new_dir [--slower factor]
#
# An image differs when more than a small fraction of its pixels do; a timing
# is reported when it is slower than the reference by more than the factor
# (default 1.5) and by more than a millisecond. Writes compare.html in the new
# directory; exits with 1 if images or picks differ (timings only warn).

import argparse
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import pngdiff
from run import TOL, MAXFRAC


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('ref')
    ap.add_argument('new')
    ap.add_argument('--slower', type=float, default=1.5)
    args = ap.parse_args()
    ref = json.load(open(os.path.join(args.ref, 'summary.json')))
    new = json.load(open(os.path.join(args.new, 'summary.json')))
    steps = {c['name']: c['steps'] for c in new['cases']}
    failed, rows, slow = 0, [], []
    for key, r in sorted(new['results'].items()):
        if key not in ref['results']:
            continue
        q = ref['results'][key]
        if 'error' in r or 'error' in q:
            continue
        name = key.rsplit('_s', 1)[0]
        imgs = ['_init'] + ['_%02d' % k for k in range(len(steps[name]))]
        for k, suffix in enumerate(imgs):
            a = os.path.join(args.ref, key + suffix + '.png')
            b = os.path.join(args.new, key + suffix + '.png')
            if not (os.path.exists(a) and os.path.exists(b)):
                continue
            n, tot = pngdiff.diff(a, b, TOL)
            if n < 0 or n > MAXFRAC * tot:
                failed += 1
                what = '(opened)' if k == 0 else steps[name][k - 1]
                rows.append((key, what, a, b, n))
                print('%s%s: %s pixels differ (%s)' %
                      (key, suffix, n if n >= 0 else 'size', what))
        pa, pb = q.get('pick', {}).get('picks'), r.get('pick', {}).get('picks')
        if pa and pb and pa != pb:
            failed += 1
            diff = [(x, y) for x, y in zip(pa, pb) if x != y]
            print('%s: %d picks differ, e.g. %s -> %s' %
                  (key, len(diff), diff[0][0], diff[0][1]))
        for what in ('first', 'frames'):
            ta, tb = q[what], r[what]
            if tb > args.slower * ta and tb - ta > 1e-3:
                slow.append((key, what, ta, tb))
        ta, tb = sum(q['steps']), sum(r['steps'])
        if tb > args.slower * ta and tb - ta > 1e-3:
            slow.append((key, 'steps', ta, tb))
    for key, what, ta, tb in slow:
        print('slower: %s %s %.4f s -> %.4f s' % (key, what, ta, tb))
    h = ['<!DOCTYPE html><html><head><meta charset="utf-8">'
         '<title>Graphics comparison</title><style>body{font-family:'
         'sans-serif;margin:16px}img{width:300px;border:1px solid #ccc}'
         'td{vertical-align:top;font-size:12px}</style></head><body>'
         '<h1>Graphics comparison</h1><p>%s (left) and %s (right)</p><table>'
         % (args.ref, args.new)]
    for key, what, a, b, n in rows:
        h.append('<tr><td>%s<br><code>%s</code><br>%s pixels</td>'
                 '<td><img src="file://%s"></td><td><img src="%s"></td></tr>'
                 % (key, what, n, os.path.abspath(a), os.path.basename(b)))
    h.append('</table><h2>Slower</h2><ul>')
    for key, what, ta, tb in slow:
        h.append('<li>%s %s: %.4f s &rarr; %.4f s</li>' % (key, what, ta, tb))
    h.append('</ul></body></html>')
    open(os.path.join(args.new, 'compare.html'), 'w').write('\n'.join(h))
    print('%d difference(s), %d slower timing(s)' % (failed, len(slow)))
    return 1 if failed else 0


if __name__ == '__main__':
    sys.exit(main())

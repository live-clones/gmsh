#!/usr/bin/env python3
"""Isolate quality QT swaps/acceptable TT merges and verify their fixed point and boundary."""
import argparse
import json
import math
import re
import subprocess
from pathlib import Path
from testTerminalMandatory import mesh


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--runner', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    source = Path(__file__).resolve().parent
    records = []
    for kind, fixture, geometry in (
        ('qt', 'testOptimizeQuadsFastMixedSwap.msh', 'testOptimizeQuadsFastMixedSwap.geo'),
        ('tt', 'testOptimizeQuadsFastTriangleQuadStrip0.msh', 'testOptimizeQuadsFastTriangleQuadStrips.geo')):
        geo = args.output / (kind + '.geo')
        geo.write_text(re.sub(r'(?m)^\s*(?:Merge|OptimizeMesh)\b[^;]*;', '',
                             (source / geometry).read_text()))
        original = mesh(source / fixture)
        for mode in ('disabled', 'enabled', 'combined', 'idle', 'budget_zero'):
            prefix = args.output / (kind + '_' + mode)
            inp = args.output / (kind + '_enabled.msh') if mode == 'idle' else source / fixture
            cmd = [str(args.runner.resolve()), '--input', str(inp.resolve()),
                   '--geometry', str(geo.resolve()), '--output', str(prefix.with_suffix('.msh').resolve()),
                   '--report', str(prefix.with_suffix('.json').resolve()), '--max-passes', '-1',
                   '--smoothing-passes', '0', '--final-winslow-passes', '0', '--terminal-winslow-passes', '0',
                   '--valence', '0', '--swaps', '1' if (kind == 'qt' or mode == 'combined') and mode != 'disabled' else '0',
                   '--merge-tt', '1' if (kind == 'tt' or mode == 'combined') and mode != 'disabled' else '0',
                   '--max-accepted', '0' if mode == 'budget_zero' else '100',
                   '--target-size', '3', '--min-edge', '0', '--max-edge', '100', '--verbosity', '6']
            run = subprocess.run(cmd, capture_output=True, text=True, check=True)
            log = run.stdout + run.stderr
            prefix.with_suffix('.log').write_text(log)
            data = json.loads(prefix.with_suffix('.json').read_text())
            final = mesh(prefix.with_suffix('.msh'))
            assert original.keys() == final.keys()
            assert max(math.dist(original[t], final[t]) for t in original) < 1.e-12
            qt, tt = (data['optimizer'][f] for f in ('finalQtSwaps', 'finalTtMerges'))
            if mode in ('enabled', 'combined'):
                assert (qt, tt) == ((1, 0) if kind == 'qt' else (0, 1)), (kind, data)
                assert ('stage=swap' if kind == 'qt' else 'stage=merge') in log
                assert log.index('phase=swap begin' if kind == 'qt' else 'phase=merge begin') < log.index('stage=swap' if kind == 'qt' else 'stage=merge')
            else:
                assert qt == tt == 0, (kind, mode, data)
            assert data['final']['invalidQuadrangles'] == data['final']['invalidTriangles'] == 0
            if kind == 'tt':
                assert data['final']['triangles'] == (0 if mode in ('enabled', 'combined', 'idle') else 2)
            records.append(dict(case=kind + '_' + mode, qt=qt, tt=tt, passed=True))
    (args.output / 'loop.pairs-tests.json').write_text(json.dumps(records, indent=2) + '\n')
    print('PASS terminal QT/TT: isolated operations, fixed nodes, disable, budget and fixed point')


if __name__ == '__main__':
    main()

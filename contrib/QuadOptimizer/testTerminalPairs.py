#!/usr/bin/env python3
"""Isolate quality QT swaps/acceptable TT merges and verify their fixed point and boundary."""
import argparse
import json
import math
import re
import subprocess
from pathlib import Path
from testTerminalMandatory import mesh


def preferred_tradeoff_fixture(directory):
    # Two triangles with angles 55, 62.5, 62.5 meet every preferred target.
    # Their rhombus has angles 55/125 and skewing 140: absolutely acceptable,
    # but its preferred skewing deficit is one. Quad preference must win.
    c, s = math.cos(math.radians(55)), math.sin(math.radians(55))
    points = [(0., 0., 0.), (1., 0., 0.), (1. + c, s, 0.), (c, s, 0.)]
    geometry = directory / 'tt_preferred.geo'
    geometry.write_text('\n'.join(
        f'Point({i}) = {{{x:.17g}, {y:.17g}, {z:.17g}}};'
        for i, (x, y, z) in enumerate(points, 1)) + '\n' +
        'Line(1) = {1,2}; Line(2) = {2,3}; Line(3) = {3,4}; Line(4) = {4,1};\n'
        'Curve Loop(1) = {1,2,3,4}; Plane Surface(1) = {1};\n')
    fixture = directory / 'tt_preferred_input.msh'
    fixture.write_text('$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n4\n' +
        '\n'.join(f'{i} {x:.17g} {y:.17g} {z:.17g}'
                  for i, (x, y, z) in enumerate(points, 1)) +
        '\n$EndNodes\n$Elements\n10\n' +
        '\n'.join(f'{i} 15 2 0 {i} {i}' for i in range(1, 5)) + '\n' +
        '\n'.join(f'{i+4} 1 2 0 {i} {i} {i % 4 + 1}' for i in range(1, 5)) +
        '\n9 2 2 0 1 1 2 4\n10 2 2 0 1 2 3 4\n$EndElements\n')
    return fixture, geometry


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--runner', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    source = Path(__file__).resolve().parent
    records = []
    preferred_fixture, preferred_geometry = preferred_tradeoff_fixture(args.output)
    for kind, fixture, geometry in (
        ('qt', source / 'testOptimizeQuadsFastMixedSwap.msh', source / 'testOptimizeQuadsFastMixedSwap.geo'),
        ('tt', source / 'testOptimizeQuadsFastTriangleQuadStrip0.msh', source / 'testOptimizeQuadsFastTriangleQuadStrips.geo'),
        ('tt_preferred', preferred_fixture, preferred_geometry)):
        triangle_pair = kind != 'qt'
        geo = args.output / (kind + '.geo')
        geo.write_text(re.sub(r'(?m)^\s*(?:Merge|OptimizeMesh)\b[^;]*;', '',
                             geometry.read_text()))
        original = mesh(fixture)
        for mode in ('disabled', 'enabled', 'combined', 'idle', 'budget_zero'):
            prefix = args.output / (kind + '_' + mode)
            inp = args.output / (kind + '_enabled.msh') if mode == 'idle' else fixture
            cmd = [str(args.runner.resolve()), '--input', str(inp.resolve()),
                   '--geometry', str(geo.resolve()), '--output', str(prefix.with_suffix('.msh').resolve()),
                   '--report', str(prefix.with_suffix('.json').resolve()), '--max-passes', '-1',
                   '--smoothing-passes', '0', '--final-winslow-passes', '0', '--terminal-winslow-passes', '0',
                   '--valence', '0', '--swaps', '1' if (kind == 'qt' or mode == 'combined') and mode != 'disabled' else '0',
                   '--merge-tt', '1' if (triangle_pair or mode == 'combined') and mode != 'disabled' else '0',
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
            if triangle_pair:
                assert data['final']['triangles'] == (0 if mode in ('enabled', 'combined', 'idle') else 2)
            if kind == 'tt_preferred':
                if mode != 'idle':
                    for criterion in ('edgeRatio', 'triangleMinimumAngle', 'triangleMaximumAngle', 'skewing'):
                        assert data['initial'][criterion]['preferredPass'] == 2, (mode, criterion, data)
                merged = mode in ('enabled', 'combined', 'idle')
                assert data['final']['quadrangles'] == int(merged), (mode, data)
                if merged:
                    assert data['final']['skewing'] == dict(applicable=1, preferredPass=0, absolutePass=1), data
                    assert abs(data['final']['maximumQuadrangleSkewingDegrees'] - 140.) < 1.e-10, data
                    for criterion in ('warping', 'edgeRatio', 'quadrangleMinimumAngle', 'quadrangleMaximumAngle'):
                        assert data['final'][criterion]['absolutePass'] == 1, (mode, criterion, data)
            records.append(dict(case=kind + '_' + mode, qt=qt, tt=tt, passed=True))
    (args.output / 'loop.pairs-tests.json').write_text(json.dumps(records, indent=2) + '\n')
    print('PASS terminal QT/TT: isolated operations, quad preference over preferred quotas, fixed nodes, disable, budget and fixed point')


if __name__ == '__main__':
    main()

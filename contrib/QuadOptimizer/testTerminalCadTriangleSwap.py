#!/usr/bin/env python3
"""Terminal TT swaps improve CAD fit while preserving the fixed boundary."""
import argparse
import collections
import json
import math
import subprocess
import sys
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bindings', type=Path, required=True)
    parser.add_argument('--runner', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    sys.path.insert(0, str(args.bindings.resolve()))
    import gmsh
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    gmsh.initialize()
    gmsh.option.setNumber('General.Terminal', 0)
    records = []
    try:
        gmsh.model.occ.addSphere(0, 0, 0, 1)
        gmsh.model.occ.synchronize()
        face = gmsh.model.getEntities(2)[0][1]
        uv = [(0.9446935104177, -0.49459036228301095),
              (2.004838977505863, -0.17689306305691),
              (2.903548553680608, 0.600281611626578),
              (1.8122584713971972, 0.18291995597179866)]
        xyz = [list(gmsh.model.getValue(2, face, p)) for p in uv]
        geo = out / 'cadtt.brep'
        initial = out / 'cadtt.input.msh'
        gmsh.write(str(geo))
        gmsh.model.mesh.addNodes(2, face, [1, 2, 3, 4],
                                [x for p in xyz for x in p], [x for p in uv for x in p])
        gmsh.model.mesh.addElementsByType(face, 2, [1, 2], [1, 2, 3, 3, 4, 1])
        gmsh.option.setNumber('Mesh.SaveAll', 1)
        gmsh.option.setNumber('Mesh.SaveParametric', 1)
        gmsh.write(str(initial))

        def cad_error(cells):
            # Independent analytic sphere distance, including triangle interiors.
            maximum = integral = area = 0.
            weights = [(1/3,)*3, (.5,.5,0), (0,.5,.5), (.5,0,.5),
                       (.6,.2,.2), (.2,.6,.2), (.2,.2,.6)]
            for c in cells:
                pts = [xyz[i-1] for i in c]
                a = [pts[1][k]-pts[0][k] for k in range(3)]
                b = [pts[2][k]-pts[0][k] for k in range(3)]
                normal = [a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]]
                weight = math.hypot(*normal)/2/len(weights)
                for w in weights:
                    p = [sum(w[i]*pts[i][k] for i in range(3)) for k in range(3)]
                    assert sum(normal[k]*p[k] for k in range(3)) > 0
                    d = abs(1-math.hypot(*p))
                    maximum = max(maximum, d)
                    integral += weight*d*d
                    area += weight
            return maximum, integral, integral/area

        before = cad_error([[1,2,3], [3,4,1]])
        for mode in ('disabled', 'enabled', 'idle', 'budget_zero'):
            prefix = out / ('cadtt.' + mode)
            inp = out / 'cadtt.enabled.msh' if mode == 'idle' else initial
            output = Path(str(prefix) + '.msh')
            report = Path(str(prefix) + '.json')
            command = [str(args.runner.resolve()), '--input', str(inp), '--geometry', str(geo),
                       '--output', str(output), '--report', str(report), '--max-passes', '0',
                       '--smoothing-passes', '0', '--final-winslow-passes', '0', '--terminal-winslow-passes', '0',
                       '--terminal-mandatory', '0', '--final-pairs', '1',
                       '--swaps', '0' if mode == 'disabled' else '1',
                       '--max-accepted', '0' if mode == 'budget_zero' else '100',
                       '--target-size', '1', '--min-edge', '0', '--max-edge', '100', '--verbosity', '6']
            result = subprocess.run(command, capture_output=True, text=True, check=True)
            Path(str(prefix) + '.log').write_text(result.stdout + result.stderr)
            data = json.loads(report.read_text())
            assert data['optimizer']['finalTtCadSwaps'] == (1 if mode == 'enabled' else 0), data
            assert data['optimizer']['finalTtMerges'] == 0, data
            gmsh.clear()
            gmsh.open(str(output))
            tags, coords, _ = gmsh.model.mesh.getNodes()
            assert len(tags) == 4
            for i, tag in enumerate(tags):
                assert math.dist(coords[3*i:3*i+3], xyz[int(tag)-1]) < 1.e-12
            ttags, conn = gmsh.model.mesh.getElementsByType(2)
            assert len(ttags) == 2
            cells = [list(map(int, conn[i:i+3])) for i in (0,3)]
            edges = collections.Counter(tuple(sorted((c[i],c[(i+1)%3]))) for c in cells for i in range(3))
            assert {e for e,n in edges.items() if n == 1} == {(1,2),(2,3),(3,4),(1,4)}
            diagonal = next(e for e,n in edges.items() if n == 2)
            after = cad_error(cells)
            if mode in ('enabled', 'idle'):
                assert diagonal == (2,4), (mode, cells)
                assert after[0] < before[0] - 1.e-12, (mode, before, after)
                assert after[1] < before[1] - 1.e-12, (mode, before, after)
                assert after[2] < before[2] - 1.e-12, (mode, before, after)
                if mode == 'enabled':
                    enabled_cells, enabled_error = cells, after
                else:
                    assert cells == enabled_cells, (mode, cells, enabled_cells)
                    assert after == enabled_error, (mode, after, enabled_error)
            else:
                assert diagonal == (1,3), (mode, cells)
                assert all(math.isclose(a, b, abs_tol=1.e-12)
                           for a, b in zip(after, before)), (mode, before, after)
            records.append(dict(case=mode, passed=True, diagonal=diagonal, cad_before=before, cad_after=after))
    finally:
        gmsh.finalize()
    (out / 'cadtt.tests.json').write_text(json.dumps(records, indent=2) + '\n')
    print('PASS terminal TT CAD improvement, fixed point, disabled and zero-budget guards')


if __name__ == '__main__':
    main()

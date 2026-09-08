#!/usr/bin/env python3
"""Regression: repeated improvement rounds followed by a strictly final split."""
import argparse
import collections
import json
from pathlib import Path
import re
import subprocess
import sys


def qqtqqt_stars(gmsh):
    result = []
    for _, face in gmsh.model.getEntities(2):
        incident = collections.defaultdict(list)
        for typ, tags, nodes in zip(*gmsh.model.mesh.getElements(2, face)):
            count = gmsh.model.mesh.getElementProperties(int(typ))[3]
            if count not in (3, 4):
                continue
            for i, tag in enumerate(tags):
                cell = list(map(int, nodes[count*i:count*(i+1)]))
                for vertex in cell:
                    incident[vertex].append((int(tag), cell))
        for vertex, cells in incident.items():
            if len(cells) != 6:
                continue
            steps = {c[(c.index(vertex)+1) % len(c)]:
                     (c[c.index(vertex)-1], tag, len(c)) for tag, c in cells}
            if len(steps) != 6:
                continue
            start = current = next(iter(steps))
            pattern, visited = [], set()
            for _ in range(6):
                if current not in steps or current in visited:
                    break
                visited.add(current)
                current, tag, count = steps[current]
                pattern.append(count)
            if len(pattern) == 6 and current == start and any(
                    pattern[i:] + pattern[:i] == [3,4,4,3,4,4] for i in range(6)):
                result.append(dict(face=face, node=vertex, pattern=pattern))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bindings', type=Path, required=True)
    parser.add_argument('--command', type=Path, required=True,
                        help='Native Doghouse h4 PACK command JSON')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    command = json.loads(args.command.read_text())
    mesh = out / 'closure-regression.msh'
    command[command.index('-o')+1] = str(mesh)
    run = subprocess.run(command, cwd=out, capture_output=True, text=True, check=True)
    log = run.stdout + run.stderr
    (out / 'closure-regression.log').write_text(log)
    assert log.index('initial smoothing end') < log.index('loop round=1 phase=valence begin')
    rounds = re.findall(r'loop round=(\d+) end valence=(\d+) swaps=(\d+) merges=(\d+) moved=(\d+)', log)
    assert len(rounds) > 1 and all(int(v) == 0 for v in rounds[-1][1:]), rounds
    assert any(int(v) for row in rounds[:-1] for v in row[1:]), rounds
    for row in rounds:
        n = row[0]
        order = [log.index(f'loop round={n} phase={phase} begin')
                 for phase in ('valence', 'swap', 'merge')]
        assert order == sorted(order)
    assert 'reason=topology-idle' in log
    assert len(re.findall(r'terminal Winslow sweep=\d+ moved=\d+', log)) == 4
    assert log.index('loop end') < log.index('terminal Winslow begin') < log.index('terminal Winslow end') < log.index('final split begin')
    assert 'loop round=' not in log[log.index('terminal Winslow begin'):]
    assert log.index('loop end') < log.index('final split begin')
    tail = log[log.index('final split begin'):]
    assert not re.search(r'stage=(valence|swap|merge|initial|round|polish)', tail)
    assert 'loop round=' not in tail
    assert 'validity=PASS invalid[T/Q]=0/0' in log
    sys.path.insert(0, str(args.bindings.resolve()))
    import gmsh
    gmsh.initialize()
    gmsh.option.setNumber('General.Terminal', 0)
    try:
        gmsh.open(str(mesh))
        survivors = qqtqqt_stars(gmsh)
        # Final splitting may expose patterns; restarting would violate its contract.
        quads = len(gmsh.model.mesh.getElementsByType(3)[0])
        triangles = len(gmsh.model.mesh.getElementsByType(2)[0])
    finally:
        gmsh.finalize()
    (out / 'closure-regression.json').write_text(json.dumps(dict(
        passed=True, rounds=len(rounds), survivorsAfterFinalSplit=survivors, quadrangles=quads, triangles=triangles), indent=2)+'\n')
    print('PASS improvement loop: ordered productive rounds to idle, final split is last, valid mesh')


if __name__ == '__main__':
    main()

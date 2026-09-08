#!/usr/bin/env python3
"""Check the valence QQTQQT transaction using the standalone V2 runner."""
import argparse
import json
import math
import re
import subprocess
from pathlib import Path


def mesh(path):
    text = path.read_text()
    nodes = {}
    # The input fixture is MSH2; the driver writes ASCII MSH4.
    section = text.split("$Nodes\n", 1)[1].split("$EndNodes", 1)[0].split()
    version = float(text.split("$MeshFormat\n", 1)[1].split()[0])
    if version < 4:
        for i in range(int(section[0])):
            j = 1 + 4 * i
            nodes[int(section[j])] = tuple(map(float, section[j + 1:j + 4]))
    else:
        cursor = 4
        for _ in range(int(section[0])):
            dim, entity, parametric, count = map(int, section[cursor:cursor + 4])
            cursor += 4
            tags = list(map(int, section[cursor:cursor + count]))
            cursor += count
            for tag in tags:
                nodes[tag] = tuple(map(float, section[cursor:cursor + 3]))
                cursor += 3 + (dim if parametric else 0)
    return nodes


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--runner", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    source = Path(__file__).resolve().parent
    fixture = source / "testOptimizeQuadsFastInteriorQQTQQT.msh"
    geometry = args.output / "geometry.geo"
    geometry.write_text(re.sub(r"(?m)^\s*(?:Merge|OptimizeMesh)\b[^;]*;", "",
        fixture.with_suffix(".geo").read_text()))
    original = mesh(fixture)
    records = []
    for name, enabled, budget, maximum in (
        ("disabled", 0, 100, 100), ("enabled", 1, 100, 100), ("pass_budget", 1, 100, 100),
        ("zero_budget", 1, 0, 100), ("size_guard", 1, 100, .5)):
        output = args.output / (name + ".msh")
        report = args.output / (name + ".json")
        command = [str(args.runner.resolve()), "--input", str(fixture),
                   "--geometry", str(geometry.resolve()), "--output", str(output.resolve()),
                   "--report", str(report.resolve()), "--max-passes", "1" if name == "pass_budget" else "-1", "--swaps", "0", "--merge-tt", "0",
                   "--max-accepted", str(budget), "--target-size", "3",
                   "--min-edge", "0", "--max-edge", str(maximum),
                   "--smoothing-passes", "0", "--final-winslow-passes", "0", "--terminal-winslow-passes", "0",
                   "--terminal-mandatory", str(enabled), "--verbosity", "6"]
        result = subprocess.run(command, capture_output=True, text=True, check=True)
        log = result.stdout + result.stderr
        (args.output / (name + ".log")).write_text(log)
        data = json.loads(report.read_text())
        after = mesh(output)
        for tag in range(1, 11):
            assert math.dist(original[tag], after[tag]) < 1.e-12, (name, tag)
        accepted = data["optimizer"]["acceptedTerminalMandatoryCavities"]
        if name in ("enabled", "pass_budget"):
            assert accepted == 1
            assert data["final"]["triangles"] == 0
            assert data["final"]["quadrangles"] == 6
            assert len(after) == 12
            assert "C=6 B=10 points=2 unknowns=4 success=1" in log
            start = log.index("phase=valence begin")
            assert "accepted QQTQQT->6Q" not in log[:start]
            assert re.search(r"accepted QQTQQT->6Q.*stage=valence", log[start:])
            assert data["final"]["invalidTriangles"] == 0
            assert data["final"]["invalidQuadrangles"] == 0
        elif name == "size_guard":
            # QQTQQT is size-rejected, but a shorter valence strip can still
            # reduce the existing size error without violating its bounds.
            assert "accepted QQTQQT->6Q" not in log
            assert data["optimizer"]["rejectedBySize"] > 0
            for old_worst, new_worst, old_penalty, new_penalty in re.findall(
                    r"acceptedGuard kind=topology sizeWorst=([\d.e+-]+)->([\d.e+-]+) sizePenalty=([\d.e+-]+)->([\d.e+-]+)", log):
                assert float(new_worst) <= float(old_worst) + 1.e-12
                assert float(new_penalty) <= float(old_penalty) + 1.e-12
        else:
            assert accepted == 0
            assert data["final"]["triangles"] == 2
            assert data["final"]["quadrangles"] == 4
            assert original.keys() == after.keys()
            assert max(math.dist(original[t], after[t]) for t in original) < 1.e-12
        if name == "pass_budget":
            assert "reason=iteration-budget" in log
        elif name == "zero_budget":
            assert "reason=cavity-budget" in log
        else:
            assert "reason=topology-idle" in log
        records.append(dict(case=name, accepted=accepted, status="passed"))
    (args.output / "loop.mandatory-tests.json").write_text(json.dumps(records, indent=2) + "\n")
    print("PASS terminal QQTQQT: two coupled points, fixed boundary, disable/budget/size guards")


if __name__ == "__main__":
    main()

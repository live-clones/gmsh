#!/usr/bin/env python3
"""Replay the MAT corpus: mid-surface of each case, scored against its truth.

For every case of corpus.json (or those named with --case):

  1. gmshMat --raw tet --filter collapse     filtered MAT of the solid
  2. facepair/fuse.py --gentle --part        fusion with the face-pairing walls
  3. tools/evaluation/projected_quality.py   score against <case>_midsurface.brep

and the verdict obtained is compared with the one recorded in corpus.json.
The exit code is nonzero if a case fails or falls below "good".

Needs gmshMat and the shared Gmsh library in the build directory, Python with
numpy and scipy, and, for the tessellator of the evaluator, a C++ compiler
(CXX, default c++) with OpenCASCADE (prefix MATGMSH_OCC_ROOT, default
/opt/homebrew/opt/opencascade) and nlohmann/json.hpp (directory
MATGMSH_JSON_INCLUDE_DIR, default /opt/homebrew/include).

The fusion and evaluation scripts are unmodified copies; they expect the
directory layout of their original repository, which is recreated under
<output>/stage (see contrib/MatGmsh/tools/README.txt).
"""
import argparse
import json
import os
import platform
import shutil
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ORDER = {"review": 0, "good": 1, "perfect": 2}

EVALUATE = r"""
import json, sys
from pathlib import Path
stage, case_dir, run_dir, out = (Path(p) for p in sys.argv[1:5])
sys.path.insert(0, str(stage / "MatGmsh-cleanup/tests/corpus"))
import projected_quality
quality = projected_quality.measure(case_dir, run_dir, 4000, "surface", True)
out.write_text(json.dumps(quality, indent=1, default=float) + "\n")
"""


def make_stage(stage, root, build):
    """The layout fuse.py and projected_quality.py were written for."""
    library = "libgmsh.dylib" if platform.system() == "Darwin" else "libgmsh.so"
    if not (build / library).is_file() or not (build / "gmshMat").is_file():
        raise SystemExit(f"{build} must hold gmshMat and {library}: build the targets shared and gmshMat")
    module = root / "contrib/MatGmsh"
    copies = [(module / "facepair/fuse.py", "MatGmsh-cleanup/tools/facepair"),
              (module / "facepair/hybrid.py", "MatGmsh-cleanup/tools/facepair"),
              (module / "tools/evaluation/direct_midsurface_cases.py", "MatGmsh-cleanup/tests"),
              (root / "api/gmsh.py", "gmsh/api")]
    copies += [(module / "tools/evaluation" / name, "MatGmsh-cleanup/tests/corpus")
               for name in ("projected_quality.py", "label_branches.py", "run_corpus.py",
                            "generate_corpus.py", "tessellate.cpp")]
    for source, target in copies:
        (stage / target).mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, stage / target / source.name)
    (stage / "gmsh/build").mkdir(parents=True)
    (stage / "gmsh/build" / library).symlink_to(build / library)


def run(command, log, environment):
    with log.open("w") as stream:
        return subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT, env=environment).returncode


def one_case(case, corpus, output, stage, build, threads, environment):
    name = case["name"]
    source = corpus / name
    work = output / "cases" / name
    work.mkdir(parents=True)
    result = dict(name=name, expected=case["verdict"], verdict="failed", stage="mat")
    started = time.monotonic()
    command = [str(build / "gmshMat"), str(source / f"{name}.stp"), "--thickness", repr(case["thickness"]),
               "--threads", str(threads), "--raw", "tet", "--filter", "collapse", "--output", str(work / "mat")]
    if run(command, work / "mat.log", environment):
        return result
    report = json.loads((work / "mat/report.json").read_text())
    result.update(certified=report["tet"]["certified"], stage="fusion", mat_seconds=time.monotonic() - started)
    started = time.monotonic()
    command = [sys.executable, str(stage / "MatGmsh-cleanup/tools/facepair/fuse.py"),
               str(work / "mat/filtered.msh"), str(source / f"{name}_mid_ext.brep"),
               repr(case["fusion_thickness"]), str(work / "fusion.msh"), "--gentle", "--part",
               str(source / f"{name}.stp")]
    if run(command, work / "fusion.log", environment) or not (work / "fusion.msh").is_file():
        return result
    result.update(stage="evaluation", fusion_seconds=time.monotonic() - started)
    started = time.monotonic()
    # Names and places the evaluator expects; the tessellator is shared.
    case_dir = output / "evaluation/corpus" / name
    run_dir = output / "evaluation/run" / name
    case_dir.mkdir(parents=True)
    run_dir.mkdir(parents=True)
    for suffix in (".stp", "_midsurface.brep", ".json"):
        (case_dir / (name + suffix)).symlink_to(source / (name + suffix))
    (run_dir / f"{name}_surface.msh").symlink_to(work / "fusion.msh")
    command = [sys.executable, "-c", EVALUATE, str(stage), str(case_dir), str(run_dir), str(work / "quality.json")]
    if run(command, work / "evaluation.log", environment):
        return result
    quality = json.loads((work / "quality.json").read_text())
    result.update(stage="done", verdict=quality["verdict"], missing_area=quality["missing_area"],
                  off_truth_area=quality["off_truth_area"], interior_coverage=quality["interior_coverage"],
                  evaluation_seconds=time.monotonic() - started)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--output", type=Path, required=True, help="new working directory")
    parser.add_argument("--root", type=Path, default=HERE.parents[1], help="Gmsh source tree")
    parser.add_argument("--build", type=Path, help="Gmsh build directory (default <root>/build)")
    parser.add_argument("--corpus", type=Path, default=HERE / "corpus")
    parser.add_argument("--manifest", type=Path, default=HERE / "corpus.json")
    parser.add_argument("--case", action="append", help="case name; may be repeated (default: all)")
    parser.add_argument("--threads", type=int, default=1)
    args = parser.parse_args()
    root = args.root.resolve()
    build = (args.build or root / "build").resolve()
    output = args.output.resolve()
    cases = json.loads(args.manifest.read_text())["cases"]
    if args.case:
        known = {case["name"] for case in cases}
        missing = [name for name in args.case if name not in known]
        if missing:
            raise SystemExit("Not in the manifest: " + ", ".join(missing))
        cases = [case for case in cases if case["name"] in args.case]
    output.mkdir(parents=True, exist_ok=False)
    make_stage(output / "stage", root, build)
    environment = dict(os.environ, OMP_NUM_THREADS="1", OPENBLAS_NUM_THREADS="1", MKL_NUM_THREADS="1",
                       PYTHONDONTWRITEBYTECODE="1")
    results = []
    print(f"{'case':32} {'expected':9} {'obtained':9} {'missing':>9} {'off truth':>9} {'seconds':>8}")
    for case in cases:
        started = time.monotonic()
        result = one_case(case, args.corpus.resolve(), output, output / "stage", build, args.threads, environment)
        result["seconds"] = time.monotonic() - started
        results.append(result)
        obtained = result["verdict"] if result["stage"] == "done" else "failed:" + result["stage"]
        areas = (f"{result['missing_area']:9.3f} {result['off_truth_area']:9.3f}" if result["stage"] == "done"
                 else f"{'':9} {'':9}")
        print(f"{result['name']:32} {result['expected']:9} {obtained:9} {areas} {result['seconds']:8.1f}", flush=True)
    (output / "results.json").write_text(json.dumps(results, indent=1) + "\n")
    below = [r["name"] for r in results if ORDER.get(r["verdict"], -1) < ORDER["good"]]
    lower = [r["name"] for r in results if ORDER.get(r["verdict"], -1) < ORDER[r["expected"]]]
    uncertified = [r["name"] for r in results if r.get("certified") is False]
    print(f"\n{len(results) - len(below)} of {len(results)} cases are good or perfect.")
    if lower:
        print("Below the recorded verdict: " + ", ".join(lower))
    if uncertified:
        print("MAT certificate failed: " + ", ".join(uncertified))
    if below:
        print("Below good: " + ", ".join(below))
    return 1 if below else 0


if __name__ == "__main__":
    sys.exit(main())

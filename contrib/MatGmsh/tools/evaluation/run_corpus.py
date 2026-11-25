#!/usr/bin/env python3
"""Run MatGmsh on the synthetic corpus and measure its MAT against the exact
mid-surface of every case (built by generate_corpus.py).

Per case, every distance in units of the local thickness t of the sheet it is
measured against (a junction line takes its thinnest sheet):
  mat_to_truth     distance from the final MAT nodes to the mid-surface sheets
                   (mean, p95, max, in units of t)
  coverage         fraction of the mid-surface area within 0.1 t and 0.6 t of
                   the MAT (the MAT stops about t/2 short of a free edge)
  free_edge_gap    distance from the free edges of the mid-surface to the MAT
  junction_gap     distance from the junction lines (curves shared by three or
                   more sheet faces) to the MAT
Writes <runs>/<case>/metrics.json and <runs>/summary.csv, and prints a table.
"""

from __future__ import annotations

import argparse
import csv
import fnmatch
import json
import math
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE.parent))
from direct_midsurface_cases import load_gmsh  # noqa: E402

gmsh = None


def run_matgmsh(matgmsh: Path, case_dir: Path, runs: Path, threads: int, extra):
    meta = json.loads((case_dir / f"{case_dir.name}.json").read_text())
    out = runs / case_dir.name
    out.mkdir(parents=True, exist_ok=True)
    command = [str(matgmsh), "--input", str(case_dir / f"{case_dir.name}.stp"),
               "--thickness", repr(min(meta["thickness"])), "--output-directory", str(out),
               "--surface-mesh-threads", str(threads)] + list(extra)
    start = time.monotonic()
    with open(out / "matgmsh.log", "w") as log:
        code = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT).returncode
    seconds = time.monotonic() - start
    error = ""
    if code != 0:
        lines = (out / "matgmsh.log").read_text(errors="replace").splitlines()
        errors = [l for l in lines if "error" in l.lower()]
        error = (errors[-1] if errors else (lines[-1] if lines else "")).strip()[:200]
    return dict(code=code, seconds=seconds, error=error)


def closest_on_face(surface, point):
    q, uv = gmsh.model.getClosestPoint(2, surface, point)
    if gmsh.model.isInside(2, surface, list(uv), parametric=True):
        return math.dist(point, q)
    best = math.inf
    for _, c in gmsh.model.getBoundary([(2, surface)], oriented=False):
        qc, _ = gmsh.model.getClosestPoint(1, abs(c), point)
        best = min(best, math.dist(point, qc))
    return best


def box_distance(point, box):
    d2 = 0.0
    for k in range(3):
        lo, hi = box[k], box[k + 3]
        e = lo - point[k] if point[k] < lo else point[k] - hi if point[k] > hi else 0.0
        d2 += e * e
    return math.sqrt(d2)


def distance_to_truth(points, faces, boxes, thickness):
    """Distance of every point to the nearest sheet, and that sheet's thickness."""
    out, local = [], []
    for p in points:
        p = [float(x) for x in p]
        order = sorted(range(len(faces)), key=lambda i: box_distance(p, boxes[i]))
        best, t = math.inf, None
        for i in order:
            if box_distance(p, boxes[i]) >= best:
                break
            d = closest_on_face(faces[i], p)
            if d < best:
                best, t = d, thickness[faces[i]]
        out.append(best)
        local.append(t)
    return np.array(out), np.array(local)


def load_mat(path: Path):
    gmsh.model.add("mat")
    gmsh.merge(str(path))
    tags, coords, _ = gmsh.model.mesh.getNodes()
    nodes = coords.reshape(-1, 3)
    index = {int(t): i for i, t in enumerate(tags)}
    triangles = []
    types, _, element_nodes = gmsh.model.mesh.getElements(2)
    for kind, conn in zip(types, element_nodes):
        if kind == 2:
            triangles.append(np.array([index[int(n)] for n in conn]).reshape(-1, 3))
    gmsh.model.remove()
    triangles = np.vstack(triangles) if triangles else np.zeros((0, 3), int)
    return nodes, triangles


def dense_cloud(nodes, triangles):
    """Nodes plus points inside the triangles: distances to this cloud
    approximate distances to the triangulated MAT within its edge length / 4."""
    if len(triangles) == 0:
        return nodes
    a, b, c = (nodes[triangles[:, k]] for k in range(3))
    extra = [(a + b + c) / 3, (a + b) / 2, (b + c) / 2, (c + a) / 2,
             (4 * a + b + c) / 6, (a + 4 * b + c) / 6, (a + b + 4 * c) / 6]
    return np.vstack([nodes] + extra)


def truth_samples(t, face_thickness):
    """Area-weighted centroids of a fine mesh of the sheets, and points on the
    free edges and junction lines, each with its local thickness."""
    gmsh.option.setNumber("Mesh.MeshSizeMax", 0.25 * t)
    gmsh.option.setNumber("Mesh.MeshSizeMin", 0.0)
    gmsh.model.mesh.generate(2)
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = dict(zip(tags.tolist(), coords.reshape(-1, 3)))
    centroids, areas, local = [], [], []
    for _, s in gmsh.model.getEntities(2):
        types, _, conn = gmsh.model.mesh.getElements(2, s)
        for kind, nodes in zip(types, conn):
            if kind != 2:
                continue
            tri = np.array([xyz[n] for n in nodes.tolist()]).reshape(-1, 3, 3)
            centroids.append(tri.mean(axis=1))
            local.append(np.full(len(tri), face_thickness[s]))
            areas.append(0.5 * np.linalg.norm(np.cross(tri[:, 1] - tri[:, 0],
                                                       tri[:, 2] - tri[:, 0]), axis=1))
    free, junction, free_t, junction_t = [], [], [], []
    for _, c in gmsh.model.getEntities(1):
        faces = gmsh.model.getAdjacencies(1, c)[0]
        if len(faces) == 2:
            continue
        tc = min(face_thickness[int(f)] for f in faces)
        lo, hi = gmsh.model.getParametrizationBounds(1, c)
        length = gmsh.model.occ.getMass(1, c)
        n = max(2, int(length / (0.25 * t)))
        u = [lo[0] + (i + 0.5) / n * (hi[0] - lo[0]) for i in range(n)]
        points = np.array(gmsh.model.getValue(1, c, u)).reshape(-1, 3)
        (free if len(faces) == 1 else junction).append(points)
        (free_t if len(faces) == 1 else junction_t).append(np.full(len(points), tc))
    gmsh.model.mesh.clear()
    stack = lambda arrays: np.vstack(arrays) if arrays else np.zeros((0, 3))
    flat = lambda arrays: np.concatenate(arrays) if arrays else np.zeros(0)
    return (stack(centroids), flat(areas), flat(local), stack(free), flat(free_t),
            stack(junction), flat(junction_t))


def face_thickness_map(meta, faces):
    """Match the imported mid-surface faces to the recorded ones by center."""
    out = {}
    for s in faces:
        c = gmsh.model.occ.getCenterOfMass(2, s)
        best = min(meta["midsurface_faces"], key=lambda f: math.dist(c, f["center"]))
        out[s] = best["thickness"]
    return out


def stats(values, t):
    if len(values) == 0:
        return None
    v = np.asarray(values) / t
    return dict(mean=float(v.mean()), p95=float(np.percentile(v, 95)), max=float(v.max()))


def measure(case_dir: Path, mat_path: Path, max_mat_nodes: int):
    meta = json.loads((case_dir / f"{case_dir.name}.json").read_text())
    t = min(meta["thickness"])
    nodes, triangles = load_mat(mat_path)
    tree = cKDTree(dense_cloud(nodes, triangles))
    gmsh.model.add("truth")
    gmsh.model.occ.importShapes(str(case_dir / f"{case_dir.name}_midsurface.brep"))
    gmsh.model.occ.synchronize()
    faces = [s for _, s in gmsh.model.getEntities(2)]
    boxes = [gmsh.model.getBoundingBox(2, s) for s in faces]
    thickness = face_thickness_map(meta, faces)
    centroids, areas, local, free, free_t, junction, junction_t = truth_samples(t, thickness)
    step = max(1, len(nodes) // max_mat_nodes)
    to_truth, to_truth_t = distance_to_truth(nodes[::step], faces, boxes, thickness)
    gmsh.model.remove()
    d_area = tree.query(centroids)[0] / local
    result = dict(
        thickness=sorted(set(meta["thickness"])), mat_nodes=len(nodes),
        mat_triangles=len(triangles),
        mat_to_truth=stats(to_truth / to_truth_t, 1.0),
        coverage_0p1t=float(areas[d_area < 0.1].sum() / areas.sum()),
        coverage_0p6t=float(areas[d_area < 0.6].sum() / areas.sum()),
        free_edge_gap=stats(tree.query(free)[0] / free_t, 1.0) if len(free) else None,
        junction_gap=stats(tree.query(junction)[0] / junction_t, 1.0)
        if len(junction) else None)
    return result


def fmt(value, key="p95"):
    if value is None:
        return "-"
    return f"{value[key]:.3f}"


def main():
    global gmsh
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--corpus", type=Path, default=ROOT / "build/corpus")
    parser.add_argument("--runs", type=Path, default=ROOT / "build/corpus_runs")
    parser.add_argument("--matgmsh", type=Path, default=ROOT / "build/MatGmsh")
    parser.add_argument("--only", default="*")
    parser.add_argument("--levels", default="", help="comma-separated levels (default: all)")
    parser.add_argument("--jobs", type=int, default=6)
    parser.add_argument("--threads", type=int, default=2, help="Gmsh threads per run")
    parser.add_argument("--max-mat-nodes", type=int, default=3000)
    parser.add_argument("--mat", default="mat_all_filtered_proj",
                        help="MAT file to measure: <case>_<mat>.msh (e.g. mat_extended)")
    parser.add_argument("--summary", default="summary.csv")
    parser.add_argument("--measure-only", action="store_true",
                        help="reuse the existing MatGmsh outputs")
    parser.add_argument("extra", nargs="*", help="extra MatGmsh options, after --")
    args = parser.parse_args()
    def level(d):
        return str(json.loads((d / f"{d.name}.json").read_text())["level"])
    cases = sorted(d for d in args.corpus.iterdir()
                   if (d / f"{d.name}.json").is_file() and fnmatch.fnmatch(d.name, args.only)
                   and (not args.levels or level(d) in args.levels.split(",")))
    if not args.measure_only:
        with ThreadPoolExecutor(args.jobs) as pool:
            runs = list(pool.map(lambda d: run_matgmsh(args.matgmsh, d, args.runs,
                                                       args.threads, args.extra), cases))
        for d, r in zip(cases, runs):
            (args.runs / d.name / "run.json").write_text(json.dumps(r, indent=1) + "\n")

    gmsh = load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    # Never fall back to MeshAdapt on a failed face: it can loop forever.
    gmsh.option.setNumber("Mesh.AlgorithmSwitchOnFailure", 0)
    rows = []
    header = (f"{'case':34s} {'lvl':>3s} {'status':8s} {'sec':>6s} {'d95/t':>7s} "
              f"{'dmax/t':>7s} {'cov.1t':>7s} {'cov.6t':>7s} {'free/t':>7s} {'junc/t':>7s}")
    print(header)
    for d in cases:
        meta = json.loads((d / f"{d.name}.json").read_text())
        run = json.loads((args.runs / d.name / "run.json").read_text())
        mat = args.runs / d.name / f"{d.name}_{args.mat}.msh"
        row = dict(case=d.name, level=meta["level"], family=meta["family"],
                   seconds=round(run["seconds"], 2), status="ok", error=run["error"])
        if run["code"] != 0 or not mat.is_file():
            row["status"] = "error"
        elif not (d / f"{d.name}_midsurface.brep").is_file():
            # A real part (level 9) has no exact mid-surface: run, not measured.
            row["status"] = "ran"
        else:
            try:
                m = measure(d, mat, args.max_mat_nodes)
                (args.runs / d.name / "metrics.json").write_text(json.dumps(m, indent=1) + "\n")
                row.update(
                    mat_to_truth_p95=m["mat_to_truth"]["p95"], mat_to_truth_max=m["mat_to_truth"]["max"],
                    coverage_0p1t=m["coverage_0p1t"], coverage_0p6t=m["coverage_0p6t"],
                    free_edge_gap_mean=m["free_edge_gap"]["mean"] if m["free_edge_gap"] else None,
                    junction_gap_max=m["junction_gap"]["max"] if m["junction_gap"] else None)
            except Exception as error:
                row["status"] = "measure"
                row["error"] = str(error)[:200]
                for name in gmsh.model.list():
                    gmsh.model.setCurrent(name)
                    gmsh.model.remove()
        rows.append(row)
        g = lambda k: "-" if row.get(k) is None else f"{row[k]:.3f}"
        print(f"{d.name:34s} {row['level']:3d} {row['status']:8s} {row['seconds']:6.1f} "
              f"{g('mat_to_truth_p95'):>7s} {g('mat_to_truth_max'):>7s} {g('coverage_0p1t'):>7s} "
              f"{g('coverage_0p6t'):>7s} {g('free_edge_gap_mean'):>7s} {g('junction_gap_max'):>7s}"
              + (f"  {row['error']}" if row["status"] not in ("ok", "ran") else ""))
    gmsh.finalize()
    keys = ["case", "level", "family", "status", "seconds", "mat_to_truth_p95",
            "mat_to_truth_max", "coverage_0p1t", "coverage_0p6t", "free_edge_gap_mean",
            "junction_gap_max", "error"]
    # Merge with the cases of earlier runs that were not run now.
    summary = args.runs / args.summary
    names = {r["case"] for r in rows}
    if summary.is_file():
        rows += [r for r in csv.DictReader(open(summary)) if r["case"] not in names
                 and (args.corpus / r["case"]).is_dir()]
    rows.sort(key=lambda r: r["case"])
    with open(summary, "w", newline="") as f:
        w = csv.DictWriter(f, keys, extrasaction="ignore")
        w.writeheader()
        w.writerows(rows)
    ok = sum(r["status"] in ("ok", "ran") for r in rows if r["case"] in names)
    print(f"{ok}/{len(names)} cases ran and were measured")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

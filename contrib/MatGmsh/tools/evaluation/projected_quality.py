#!/usr/bin/env python3
"""Quality of the projected MAT (before any extension) against the exact
mid-surface of every corpus case.

The MAT stops short of a free edge, by the radius of the ball inscribed in the
part there (half the thickness, more at the foot of a filleted junction or
along a thicker sheet): that band is the job of the extension, not an error of
the projected MAT. A point of the true mid-surface is in that band when it is
closer to a free edge of the truth than 1.15 times its distance to the part
surface plus 0.05 t. Every distance is in units of the local thickness t of
the truth sheet. Per case:
  interior_coverage  fraction of the true mid-surface outside that band that
                     lies within 0.1 t of the MAT
  missing_area       area of that interior not covered, in t^2
  off_truth_area     MAT area farther than 0.1 t from the true mid-surface, in t^2
  misoriented_area   MAT area within 0.1 t of it but not parallel to it (folds,
                     slivers), in t^2
  mat_to_truth       distance of the MAT nodes to the true mid-surface (p95, max)
  junction_gap       distance of the true junction lines (curves shared by three
                     or more sheets), outside that band, to the MAT (mean, max)
Along a crease of the truth (two sheets meeting at an angle of more than 15
degrees) the MAT rounds the corner and that is accepted: 1.5 t on each side
are left out of every measure above (crease_deviation_max reports the largest
distance of the MAT nodes there).
and the largest missing and off-truth regions (area, center), where the MAT
and the junction lines are farthest from the truth (far_regions,
junction_gap_regions: largest distance beyond 0.1 t, center), then a verdict:
  perfect  interior coverage >= 0.999, off-truth <= 0.1 t^2, max distances <= 0.1 t
  good     interior coverage >= 0.99, off-truth <= 1 t^2, max distances <= 0.25 t
  review   otherwise.
Writes <runs>/<case>/projected_quality.json and <runs>/projected_quality.csv.

With --mat mat_extended --full, the same measures judge the MAT extended up to
the part: nothing is left out along the free edges (the whole true mid-surface
is the interior, every junction line is measured), and free_edge_gap gives the
distance of the true free edges to the MAT (mean, max), the gap the extension
must close. Output: extended_quality.json / extended_quality.csv.
"""

from __future__ import annotations

import argparse
import csv
import fnmatch
import json
import math
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(HERE.parent))
import label_branches  # noqa: E402
import run_corpus  # noqa: E402
from direct_midsurface_cases import load_gmsh  # noqa: E402

TOLERANCE = 0.1
CREASE_BAND = 0.0


def closest_on_face(surface, point):
    """Distance to a CAD face (its boundary curves when the projection falls
    outside); degenerate curves (the pole of a sphere) are skipped."""
    gmsh = run_corpus.gmsh
    q, uv = gmsh.model.getClosestPoint(2, surface, point)
    if gmsh.model.isInside(2, surface, list(uv), parametric=True):
        return math.dist(point, q)
    best = math.inf
    for _, c in gmsh.model.getBoundary([(2, surface)], oriented=False):
        try:
            qc, _ = gmsh.model.getClosestPoint(1, abs(c), point)
        except Exception:
            continue
        best = min(best, math.dist(point, qc))
    return best


def part_cloud(case_dir: Path, t: float, gmsh):
    """Points every t/8 or so on the part surface, from OpenCASCADE's
    tessellation (Gmsh's mesher can loop on some faces), in a KD-tree: the
    distance to it overestimates the distance to the part by at most t/16."""
    import subprocess
    import tempfile
    from generate_corpus import compile_tool
    tool = compile_tool(case_dir.parent / "bin", "tessellate")
    with tempfile.TemporaryDirectory() as scratch:
        gmsh.model.add("part")
        gmsh.model.occ.importShapes(str(case_dir / f"{case_dir.name}.stp"))
        gmsh.model.occ.synchronize()
        brep = Path(scratch) / "part.brep"
        gmsh.write(str(brep))
        gmsh.model.remove()
        text = Path(scratch) / "part.txt"
        subprocess.run([str(tool), str(brep), repr(t / 20), str(text)], check=True,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        rows = [l for l in text.read_text().splitlines() if l and not l.startswith("face")]
    triangles = np.array([[float(x) for x in l.split()] for l in rows if len(l.split()) == 9]).reshape(-1, 3, 3)
    points = [triangles.reshape(-1, 3)]
    h = t / 8
    for tri in triangles:
        a, b, c = tri
        n = int(max(np.linalg.norm(b - a), np.linalg.norm(c - b), np.linalg.norm(a - c)) / h)
        if n < 1:
            continue
        i, j = np.meshgrid(np.arange(n + 1), np.arange(n + 1))
        keep = i + j <= n
        u, v = i[keep] / n, j[keep] / n
        points.append(a + u[:, None] * (b - a) + v[:, None] * (c - a))
    return cKDTree(np.vstack(points))


def expected_missing(point_sets, thickness_sets, free, part):
    """For every set of points of the true mid-surface: those closer to a free
    edge than 1.15 R + 0.05 t, where R is the largest radius of the balls
    inscribed in the part, centered on the true mid-surface near the free
    edges, that contain the point (at the foot of a filleted junction the
    medial ball that stops the MAT is centered above the junction and larger
    than half the thickness). The MAT does not reach them before its
    extension."""
    outs = [np.zeros(len(points), dtype=bool) for points in point_sets]
    if len(free) == 0:
        return outs
    tree = cKDTree(free)
    near, d_free = [], []
    for points, local_t in zip(point_sets, thickness_sets):
        d = tree.query(points)[0] if len(points) else np.zeros(0)
        near.append(np.where(d < 2.5 * local_t)[0])
        d_free.append(d)
    centers = np.vstack([points[i] for points, i in zip(point_sets, near)] + [np.zeros((0, 3))])
    if len(centers) == 0:
        return outs
    radius = part.query(centers)[0]
    ball_tree = cKDTree(centers)
    reach = float(radius.max())
    offset = 0
    for k, (points, local_t) in enumerate(zip(point_sets, thickness_sets)):
        index = near[k]
        if len(index) == 0:
            continue
        own = radius[offset:offset + len(index)]
        largest = own.copy()
        pairs = cKDTree(points[index]).sparse_distance_matrix(ball_tree, reach, output_type="coo_matrix")
        inside = pairs.data <= radius[pairs.col]
        np.maximum.at(largest, pairs.row[inside], radius[pairs.col[inside]])
        outs[k][index] = d_free[k][index] < 1.15 * largest + 0.05 * local_t[index]
        offset += len(index)
    return outs


def edge_samples(case_dir: Path, meta, gmsh):
    """Points every t/10 on the free edges (curves of one sheet) and on the
    junction lines (curves of three or more sheets) of the truth, with the
    thickness of their thinnest sheet."""
    gmsh.model.add("edges")
    gmsh.model.occ.importShapes(str(case_dir / f"{case_dir.name}_midsurface.brep"))
    gmsh.model.occ.synchronize()
    t = min(meta["thickness"])
    thickness = {}
    for _, s in gmsh.model.getEntities(2):
        c = gmsh.model.occ.getCenterOfMass(2, s)
        thickness[s] = min(meta["midsurface_faces"], key=lambda f: math.dist(c, f["center"]))["thickness"]
    free, free_t, junction, junction_t, crease = [], [], [], [], []
    for _, c in gmsh.model.getEntities(1):
        faces = gmsh.model.getAdjacencies(1, c)[0]
        if len(faces) == 0:
            continue
        if len(faces) == 2:
            # A crease: two sheets meeting at an angle (more than 15 degrees).
            lo, hi = gmsh.model.getParametrizationBounds(1, c)
            mid = gmsh.model.getValue(1, c, [0.5 * (lo[0] + hi[0])])
            normals = []
            for f in faces:
                _, uv = gmsh.model.getClosestPoint(2, int(f), mid)
                normals.append(np.array(gmsh.model.getNormal(int(f), list(uv))))
            if abs(normals[0] @ normals[1]) > math.cos(math.radians(15)):
                continue
            n = max(2, int(gmsh.model.occ.getMass(1, c) / (0.1 * t)))
            u = [lo[0] + (i + 0.5) / n * (hi[0] - lo[0]) for i in range(n)]
            crease.append(np.array(gmsh.model.getValue(1, c, u)).reshape(-1, 3))
            continue
        tc = min(thickness[int(f)] for f in faces)
        lo, hi = gmsh.model.getParametrizationBounds(1, c)
        n = max(2, int(gmsh.model.occ.getMass(1, c) / (0.1 * t)))
        u = [lo[0] + (i + 0.5) / n * (hi[0] - lo[0]) for i in range(n)]
        points = np.array(gmsh.model.getValue(1, c, u)).reshape(-1, 3)
        (free if len(faces) == 1 else junction).append(points)
        (free_t if len(faces) == 1 else junction_t).append(np.full(len(points), tc))
    gmsh.model.remove()
    stack = lambda a: np.vstack(a) if a else np.zeros((0, 3))
    flat = lambda a: np.concatenate(a) if a else np.zeros(0)
    return stack(free), flat(free_t), stack(junction), flat(junction_t), stack(crease)


def on_truth(truth, centroid, normal):
    """For every triangle: within 0.1 t of the true mid-surface (distance to
    the tangent plane of one of its 8 nearest truth samples, in-plane offset
    below half a thickness), and also parallel to it there (normals within
    25 degrees): a triangle near but not parallel is a fold or a sliver."""
    k = min(8, len(truth["t"]))
    d, i = truth["tree"].query(centroid, k=k)
    d, i = d.reshape(len(centroid), k), i.reshape(len(centroid), k)
    delta = centroid[:, None, :] - truth["centroid"][i]
    n = truth["normal"][i]
    off_plane = np.abs(np.einsum("ijk,ijk->ij", delta, n))
    in_plane = np.sqrt(np.maximum(d * d - off_plane * off_plane, 0.0))
    tk = truth["t"][i]
    near = (off_plane / tk < TOLERANCE) & (in_plane / tk < 0.5)
    parallel = np.abs(np.einsum("ik,ijk->ij", normal, n)) > 0.9
    return near.any(axis=1), (near & parallel).any(axis=1), truth["t"][i[:, 0]]


def regions(points, areas, scale, count=3):
    """Largest groups of points closer than scale to each other: (area, center)."""
    if len(points) == 0:
        return []
    pairs = cKDTree(points).query_pairs(scale, output_type="ndarray")
    parent = np.arange(len(points))

    def find(i):
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    for a, b in pairs:
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[ra] = rb
    roots = np.array([find(i) for i in range(len(points))])
    out = []
    for r in np.unique(roots):
        m = roots == r
        out.append((float(areas[m].sum()), points[m].mean(axis=0).round(2).tolist()))
    return sorted(out, reverse=True)[:count]


def peaks(points, values, scale, threshold=TOLERANCE, count=3):
    """Groups of points closer than scale whose value exceeds threshold:
    (largest value, center), largest first."""
    keep = values > threshold
    if not keep.any():
        return []
    points, values = points[keep], values[keep]
    groups = {}
    tree = cKDTree(points)
    label = np.full(len(points), -1)
    for i in np.argsort(-values):
        if label[i] >= 0:
            continue
        stack, label[i] = [i], i
        while stack:
            j = stack.pop()
            for k in tree.query_ball_point(points[j], scale):
                if label[k] < 0:
                    label[k] = i
                    stack.append(k)
        m = label == i
        groups[i] = (float(values[m].max()), points[m].mean(axis=0).round(2).tolist())
    return sorted(groups.values(), reverse=True)[:count]


def measure(case_dir: Path, run_dir: Path, max_mat_nodes: int, mat: str = "mat_all_filtered_proj",
            full: bool = False):
    gmsh = load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    label_branches.gmsh = gmsh
    run_corpus.gmsh = gmsh
    run_corpus.closest_on_face = closest_on_face
    name = case_dir.name
    meta = json.loads((case_dir / f"{name}.json").read_text())
    t0 = min(meta["thickness"])
    msh = run_dir / f"{name}_{mat}.msh"
    nodes, triangles = run_corpus.load_mat(msh)
    if len(triangles) == 0:
        raise RuntimeError("empty projected MAT")
    truth = label_branches.truth_cloud(case_dir, meta)
    free, free_t, junction, junction_t, crease = edge_samples(case_dir, meta, gmsh)

    # Interior of the truth: outside the band the MAT leaves to the extension.
    t = truth["t"]
    part = part_cloud(case_dir, t0, gmsh)
    band_truth, band_junction = expected_missing([truth["centroid"], junction], [t, junction_t],
                                                 free, part)
    # Along a crease of the truth (two sheets meeting at an angle, as a
    # flange joined edge to edge with a fillet inside) the MAT may round the
    # corner: 1.5 t on each side are not measured.
    crease_tree = cKDTree(crease) if len(crease) else None
    def near_crease(points, local_t):
        if crease_tree is None or len(points) == 0:
            return np.zeros(len(points), dtype=bool)
        return crease_tree.query(points)[0] < CREASE_BAND * local_t
    if full:
        # Judging an extended MAT: the band along the free edges is its job.
        band_truth = np.zeros_like(band_truth)
        band_junction = np.zeros_like(band_junction)
    interior = ~band_truth & ~near_crease(truth["centroid"], t)
    mat_cloud = cKDTree(run_corpus.dense_cloud(nodes, triangles))
    d_mat = mat_cloud.query(truth["centroid"])[0] / t
    covered = d_mat < TOLERANCE
    area = truth["area"]
    interior_area = area[interior].sum()
    missing = interior & ~covered
    result = dict(
        thickness=sorted(set(meta["thickness"])),
        interior_coverage=float(area[interior & covered].sum() / interior_area) if interior_area > 0 else 1.0,
        missing_area=float((area[missing] / t[missing] ** 2).sum()),
        missing_regions=regions(truth["centroid"][missing], area[missing] / t[missing] ** 2, 0.5 * t0))

    # Precision of the MAT.
    a, b, c = (nodes[triangles[:, k]] for k in range(3))
    cross = np.cross(b - a, c - a)
    norm = np.linalg.norm(cross, axis=1)
    centroid = (a + b + c) / 3
    near, aligned, tm = on_truth(truth, centroid, cross / np.maximum(norm, 1e-300)[:, None])
    mat_area = 0.5 * norm / tm ** 2
    rounded = near_crease(centroid, tm)
    near, aligned = near | rounded, aligned | rounded
    result["off_truth_area"] = float(mat_area[~near].sum())
    result["off_truth_regions"] = regions(centroid[~near], mat_area[~near], 0.5 * t0)
    tilted = near & ~aligned
    result["misoriented_area"] = float(mat_area[tilted].sum())
    result["misoriented_regions"] = regions(centroid[tilted], mat_area[tilted], 0.5 * t0)

    gmsh.model.add("truth_brep")
    gmsh.model.occ.importShapes(str(case_dir / f"{name}_midsurface.brep"))
    gmsh.model.occ.synchronize()
    faces = [s for _, s in gmsh.model.getEntities(2)]
    boxes = [gmsh.model.getBoundingBox(2, s) for s in faces]
    face_t = run_corpus.face_thickness_map(meta, faces)
    step = max(1, len(nodes) // max_mat_nodes)
    sampled = nodes[::step]
    d, dt = run_corpus.distance_to_truth(sampled, faces, boxes, face_t)
    at_crease = near_crease(sampled, dt)
    result["crease_deviation_max"] = float((d / dt)[at_crease].max()) if at_crease.any() else None
    d, dt = d[~at_crease], dt[~at_crease]
    gmsh.model.remove()
    result["mat_to_truth"] = run_corpus.stats(d / dt, 1.0)
    # Where the MAT is farthest from the truth (beyond 0.1 t).
    result["far_regions"] = peaks(sampled[~at_crease], d / dt, 0.5 * t0)

    if full:
        result["free_edge_gap"] = (run_corpus.stats(mat_cloud.query(free)[0] / free_t, 1.0)
                                   if len(free) else None)
    if len(junction):
        keep = ~band_junction
        gap = mat_cloud.query(junction[keep])[0] / junction_t[keep] if keep.any() else np.zeros(0)
        result["junction_gap"] = run_corpus.stats(gap, 1.0) if len(gap) else None
        result["junction_gap_regions"] = peaks(junction[keep], gap, 0.5 * t0) if len(gap) else []
    else:
        result["junction_gap"] = None

    worst = max(result["mat_to_truth"]["max"],
                result["junction_gap"]["max"] if result["junction_gap"] else 0.0,
                result["free_edge_gap"]["max"] if result.get("free_edge_gap") else 0.0)
    if result["interior_coverage"] >= 0.999 and result["off_truth_area"] <= 0.1 and worst <= 0.1:
        verdict = "perfect"
    elif result["interior_coverage"] >= 0.99 and result["off_truth_area"] <= 1.0 and worst <= 0.25:
        verdict = "good"
    else:
        verdict = "review"
    result["verdict"] = verdict
    gmsh.finalize()
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--corpus", type=Path, default=ROOT / "build" / "corpus")
    parser.add_argument("--runs", type=Path, default=ROOT / "build" / "corpus_runs_bt")
    parser.add_argument("--only", default="*", help="comma-separated case patterns")
    parser.add_argument("--levels", default="")
    parser.add_argument("--jobs", type=int, default=4)
    parser.add_argument("--max-mat-nodes", type=int, default=4000)
    parser.add_argument("--mat", default="mat_all_filtered_proj",
                        help="MAT to judge: <case>_<mat>.msh (mat_extended with --full)")
    parser.add_argument("--full", action="store_true",
                        help="judge the whole mid-surface (an extended MAT): no free-edge band")
    parser.add_argument("--one", default="", help=argparse.SUPPRESS)
    args = parser.parse_args()
    output = "extended_quality.json" if args.full else "projected_quality.json"

    if args.one:
        case_dir, run_dir = args.corpus / args.one, args.runs / args.one
        try:
            result = measure(case_dir, run_dir, args.max_mat_nodes, args.mat, args.full)
        except Exception as error:  # reported in the table
            result = dict(verdict="error", error=str(error)[:200])
        (run_dir / output).write_text(json.dumps(result, indent=1))
        return

    levels = set(args.levels.split(",")) if args.levels else None
    cases = []
    for case_dir in sorted(p for p in args.corpus.iterdir() if p.is_dir()):
        meta_path = case_dir / f"{case_dir.name}.json"
        if not meta_path.exists() or not any(fnmatch.fnmatch(case_dir.name, o) for o in args.only.split(",")):
            continue
        if levels and str(json.loads(meta_path.read_text())["level"]) not in levels:
            continue
        if not (args.runs / case_dir.name / f"{case_dir.name}_{args.mat}.msh").exists():
            continue
        if not (case_dir / f"{case_dir.name}_midsurface.brep").exists():
            continue  # a real part: no exact mid-surface
        cases.append(case_dir.name)

    def one(name):
        subprocess.run([sys.executable, __file__, "--corpus", str(args.corpus), "--runs", str(args.runs),
                        "--max-mat-nodes", str(args.max_mat_nodes), "--mat", args.mat]
                       + (["--full"] if args.full else []) + ["--one", name],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        path = args.runs / name / output
        return name, json.loads(path.read_text()) if path.exists() else dict(verdict="error", error="no result")

    with ThreadPoolExecutor(args.jobs) as pool:
        results = dict(pool.map(one, cases))

    fields = ["case", "verdict", "interior_coverage", "missing_area", "off_truth_area", "misoriented_area",
              "mat_to_truth_p95", "mat_to_truth_max", "junction_gap_mean", "junction_gap_max",
              "free_edge_gap_mean", "free_edge_gap_max", "largest_missing", "largest_off_truth", "error"]
    rows = []
    for name, r in results.items():
        g = lambda key, sub: r[key][sub] if r.get(key) else None
        rows.append(dict(case=name, verdict=r["verdict"], interior_coverage=r.get("interior_coverage"),
                         missing_area=r.get("missing_area"), off_truth_area=r.get("off_truth_area"),
                         misoriented_area=r.get("misoriented_area"),
                         mat_to_truth_p95=g("mat_to_truth", "p95"), mat_to_truth_max=g("mat_to_truth", "max"),
                         junction_gap_mean=g("junction_gap", "mean"), junction_gap_max=g("junction_gap", "max"),
                         free_edge_gap_mean=g("free_edge_gap", "mean"), free_edge_gap_max=g("free_edge_gap", "max"),
                         largest_missing=r.get("missing_regions", [None])[0] if r.get("missing_regions") else None,
                         largest_off_truth=r.get("off_truth_regions", [None])[0] if r.get("off_truth_regions") else None,
                         error=r.get("error", "")))
    order = {"error": 0, "review": 1, "good": 2, "perfect": 3}
    rows.sort(key=lambda row: (order[row["verdict"]], -(row["missing_area"] or 0) - (row["off_truth_area"] or 0)))
    with open(args.runs / output.replace(".json", ".csv"), "w", newline="") as out:
        writer = csv.DictWriter(out, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)

    fmt = lambda v, f=".3f": "-" if v is None else format(v, f)
    print(f"{'case':34s} {'verdict':8s} {'cov.int':>7s} {'miss':>7s} {'off':>7s} {'tilt':>6s} {'d95':>6s} {'dmax':>6s} "
          f"{'jmax':>6s} {'fgap':>6s}  largest missing / off-truth region (t^2 @ center)")
    for row in rows:
        lm, lo = row["largest_missing"], row["largest_off_truth"]
        where = (f"{lm[0]:.2f}@{lm[1]}" if lm else "-") + " / " + (f"{lo[0]:.2f}@{lo[1]}" if lo else "-")
        print(f"{row['case']:34s} {row['verdict']:8s} {fmt(row['interior_coverage'], '.4f'):>7s} "
              f"{fmt(row['missing_area'], '.2f'):>7s} {fmt(row['off_truth_area'], '.2f'):>7s} "
              f"{fmt(row['misoriented_area'], '.2f'):>6s} "
              f"{fmt(row['mat_to_truth_p95']):>6s} {fmt(row['mat_to_truth_max']):>6s} "
              f"{fmt(row['junction_gap_max']):>6s} {fmt(row['free_edge_gap_max']):>6s}  "
              f"{where if not row['error'] else row['error']}")
    counts = {v: sum(r["verdict"] == v for r in rows) for v in order}
    print(f"{len(rows)} cases: " + ", ".join(f"{counts[v]} {v}" for v in ["perfect", "good", "review", "error"]))


if __name__ == "__main__":
    main()

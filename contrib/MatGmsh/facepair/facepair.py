#!/usr/bin/env python3
"""Learned face pairing for mid-surfaces (after MidSurfNet, Ye et al. 2026),
on the synthetic corpus, with OpenCASCADE alone for the geometry.

A wall of a thin part is bounded by two groups of CAD faces, one on each side.
Every unordered pair of faces gets a score: is it an opposing-face support
relation (the two faces bound the same wall from opposite sides)? Pairs above
one threshold, chosen on validation cases, are kept; the support graph is then
split into connected components and each one two-coloured (Algorithm 1 of the
paper): a bipartite component is a wall group (A, B), a non-bipartite one a
composition failure. The mid-surface of a group is made of the midpoints of
the rays between its retained pairs, meshed on the sampling grids of the
faces.

Evidence comes from facepair.cpp (rays along the inward normals, faces, edges):
  criteria   distance (over the bounding-box diagonal and over the typical
             thickness of the part), cosine of the normals, overlaps min and max
             (fraction of each face whose rays land on the other), spread of the
             distance along the pair (a wall keeps its gap), parallel fraction
  shape      surface types, area ratio, loops, Gaussian-curvature sign fractions
  topology   graph distance on the face-adjacency graph, adjacency and dihedral,
             common neighbours (and those joined by convex edges, the lateral
             faces of a wall), concave-edge fractions, degrees
A gradient-boosted classifier stands for the paper's two-stream network (no
PyTorch here): the paper reports F1 0.79 for XGBoost on the same features
against 0.87 for its network.

Labels need no annotation: a pair is a support relation when, over half of
the area of its rays, the faces face each other (normals opposite within 18
degrees) and the midpoints lie on the true mid-surface (within 0.1 t).

  facepair.py prepare  [--only a,b] [--levels 1,2] [--jobs N]   rays, features, labels
  facepair.py train                                              split, fit, threshold
  facepair.py evaluate [--only ...] [--jobs N]                   groups, mid-surfaces, measures
Outputs under build/facepair/ (one <case>.npz per case, model.pkl, report.json,
<case>_facepair.msh and <case>_facepair.json per evaluated case).
"""

from __future__ import annotations

import argparse
import fnmatch
import hashlib
import json
import math
import pickle
import subprocess
import sys
from collections import defaultdict, deque
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
CORPUS = ROOT / "build/corpus"
OUT = ROOT / "build/facepair"
TOOL = ROOT / "build/facepair_tool"
sys.path[:0] = [str(ROOT / "tests/corpus"), str(ROOT / "tests")]

TYPES = ["Plane", "Cylinder", "Cone", "Sphere", "Torus", "BSpline", "Bezier", "Revolution", "Extrusion",
         "Offset", "Other"]
FEATURES = ["d_diag", "d_thick", "cos", "o_min", "o_max", "spread", "parallel", "both_ways",
            "same_type", "both_plane", "type_a", "type_b", "area_ratio", "loops_min", "loops_max",
            "kpos_diff", "kneg_diff", "curv_ratio",
            "hops", "adjacent", "dihedral", "common", "common_convex", "concave_min", "concave_max",
            "degree_min", "degree_max"]


def compile_tool():
    source = HERE / "facepair.cpp"
    if TOOL.is_file() and TOOL.stat().st_mtime > source.stat().st_mtime:
        return TOOL
    import os
    occ = Path(os.environ.get("OCC_ROOT", "/opt/homebrew/opt/opencascade"))
    libs = ["TKernel", "TKMath", "TKG2d", "TKG3d", "TKGeomBase", "TKBRep", "TKGeomAlgo", "TKTopAlgo",
            "TKMesh", "TKDESTEP", "TKDEIGES", "TKDE", "TKXSBase", "TKShHealing", "TKBool", "TKBO"]
    subprocess.run(["c++", "-std=c++17", "-O2", f"-I{occ}/include/opencascade", str(source), "-o", str(TOOL),
                    f"-L{occ}/lib", f"-Wl,-rpath,{occ}/lib"] + [f"-l{lib}" for lib in libs], check=True)
    return TOOL


def cases(only="*", levels=""):
    wanted = {int(x) for x in levels.split(",") if x}
    out = []
    for d in sorted(CORPUS.iterdir()):
        meta = d / f"{d.name}.json"
        if not meta.is_file() or not (d / f"{d.name}_midsurface.brep").is_file():
            continue
        if not any(fnmatch.fnmatch(d.name, o) for o in only.split(",")):
            continue
        if wanted and json.loads(meta.read_text()).get("level") not in wanted:
            continue
        out.append(d.name)
    return out


def split_of(case):
    """Deterministic split by case name: 70 % train, 15 % validation, 15 % test."""
    r = int(hashlib.sha1(case.encode()).hexdigest()[:8], 16) / 0xFFFFFFFF
    return "train" if r < 0.70 else ("val" if r < 0.85 else "test")


def load_rays(prefix: Path):
    # Case names may contain dots (saddle_k0.01): no with_suffix.
    info = json.loads(Path(f"{prefix}.json").read_text())
    nodes = np.fromfile(f"{prefix}.nodes", dtype=np.float32).reshape(-1, info["node_columns"])
    tris = np.fromfile(f"{prefix}.tris", dtype=np.int32).reshape(-1, 3)
    return info, nodes, tris


# ---------------------------------------------------------------------------
# Features and labels.


def graph(info):
    n = len(info["faces"]) + 1
    neighbours = [dict() for _ in range(n)]
    for a, b, length, c, convex in info["edges"]:
        for x, y in ((a, b), (b, a)):
            old = neighbours[x].get(y)
            neighbours[x][y] = (c, convex) if old is None else (min(old[0], c), old[1] or convex)
    return neighbours


def hops(neighbours, source, cap=6):
    dist = {source: 0}
    queue = deque([source])
    while queue:
        u = queue.popleft()
        if dist[u] >= cap:
            continue
        for w in neighbours[u]:
            if w not in dist:
                dist[w] = dist[u] + 1
                queue.append(w)
    return dist


def pair_features(info, nodes):
    """Candidate pairs (faces whose rays land on each other) and their features."""
    faces = {f["id"]: f for f in info["faces"]}
    face_of, area, hit, dist, cos = nodes[:, 0].astype(int), nodes[:, 7], nodes[:, 8].astype(int), nodes[:, 9], nodes[:, 10]
    face_area = np.bincount(face_of, weights=area, minlength=len(faces) + 1)
    good = (hit > 0) & (cos < -0.9)
    typical = float(np.median(dist[good])) if good.any() else 1.0
    directed = defaultdict(list)
    for k, i, j in zip(*((lambda k: (k, face_of[k], hit[k]))(np.nonzero(hit > 0)[0]))):
        directed[(int(i), int(j))].append(int(k))
    neighbours = graph(info)
    hop_cache = {}
    rows, keys = [], []
    for i, j in sorted({tuple(sorted(p)) for p in directed if p[0] != p[1]}):
        ij, ji = directed.get((i, j), []), directed.get((j, i), [])
        idx = np.array(ij + ji, dtype=int)
        w = area[idx]
        if w.sum() <= 0:  # nodes on the rim of a sampling grid carry no area
            w = np.ones(len(idx))
        o_ij = area[ij].sum() / max(face_area[i], 1e-12) if ij else 0.0
        o_ji = area[ji].sum() / max(face_area[j], 1e-12) if ji else 0.0
        d = dist[idx]
        order = np.argsort(d)
        cw = np.cumsum(w[order]) / max(w.sum(), 1e-300)
        quantile = lambda q: float(d[order][min(np.searchsorted(cw, q), len(d) - 1)])
        median = quantile(0.5)
        fi, fj = faces[i], faces[j]
        if i not in hop_cache:
            hop_cache[i] = hops(neighbours, i)
        h = hop_cache[i].get(j, 7)
        common = set(neighbours[i]) & set(neighbours[j])
        convex_common = sum(1 for k in common if neighbours[i][k][1] == 1 and neighbours[j][k][1] == 1)
        concave = lambda f: (sum(1 for v in neighbours[f].values() if v[1] == -1) / max(len(neighbours[f]), 1))
        ti, tj = sorted((TYPES.index(fi["type"]) if fi["type"] in TYPES else len(TYPES) - 1,
                         TYPES.index(fj["type"]) if fj["type"] in TYPES else len(TYPES) - 1))
        rows.append([
            median / info["diagonal"], median / typical, float((cos[idx] * w).sum() / w.sum()),
            min(o_ij, o_ji), max(o_ij, o_ji), (quantile(0.75) - quantile(0.25)) / max(median, 1e-12),
            float(w[cos[idx] < -0.98].sum() / w.sum()), float(bool(ij) and bool(ji)),
            float(fi["type"] == fj["type"]), float(fi["type"] == fj["type"] == "Plane"), ti, tj,
            min(fi["area"], fj["area"]) / max(fi["area"], fj["area"], 1e-12),
            min(fi["loops"], fj["loops"]), max(fi["loops"], fj["loops"]),
            abs(fi["k_pos"] - fj["k_pos"]), abs(fi["k_neg"] - fj["k_neg"]),
            min(fi["mean_curvature"], fj["mean_curvature"]) / max(fi["mean_curvature"], fj["mean_curvature"], 1e-12)
            if max(fi["mean_curvature"], fj["mean_curvature"]) > 0 else 1.0,
            h, float(j in neighbours[i]), neighbours[i][j][0] if j in neighbours[i] else 2.0,
            len(common), convex_common, min(concave(i), concave(j)), max(concave(i), concave(j)),
            min(len(neighbours[i]), len(neighbours[j])), max(len(neighbours[i]), len(neighbours[j]))])
        keys.append((i, j))
    return np.array(keys, dtype=int).reshape(-1, 2), np.array(rows, dtype=float).reshape(-1, len(FEATURES)), directed


def midpoints(nodes, idx):
    return nodes[idx, 1:4] - 0.5 * nodes[idx, 9:10] * nodes[idx, 4:7]


def labels(case, nodes, keys, directed):
    """Positive when, over half of their area, the midpoints of the pair's rays
    lie within 0.1 t of the true mid-surface."""
    import label_branches as lb
    gmsh = lb.load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    lb.gmsh = gmsh
    meta = json.loads((CORPUS / case / f"{case}.json").read_text())
    truth = lb.truth_cloud(CORPUS / case, meta)
    gmsh.finalize()
    out = np.zeros(len(keys), dtype=int)
    share = np.zeros(len(keys))
    for n, (i, j) in enumerate(keys):
        idx = np.array(directed.get((i, j), []) + directed.get((j, i), []), dtype=int)
        on = on_truth(truth, midpoints(nodes, idx))
        w = nodes[idx, 7]
        # Facing walls: normals opposite within 18 degrees. A fillet facing a
        # plate puts midpoints on the truth too, but it bounds no wall.
        facing = nodes[idx, 10] < -0.95
        share[n] = float(w[on & facing].sum() / max(w.sum(), 1e-300))
        out[n] = int(share[n] >= 0.5)
    return out, share, truth


def on_truth(truth, points, tolerance=0.1):
    if len(points) == 0:
        return np.zeros(0, dtype=bool)
    k = min(8, len(truth["t"]))
    d, i = truth["tree"].query(points, k=k)
    d, i = d.reshape(len(points), k), i.reshape(len(points), k)
    off = np.abs(np.einsum("ijk,ijk->ij", points[:, None, :] - truth["centroid"][i], truth["normal"][i]))
    inplane = np.sqrt(np.maximum(d * d - off * off, 0.0))
    tk = truth["t"][i]
    return ((off / tk < tolerance) & (inplane / tk < 0.5)).any(axis=1)


def prepare_one(case):
    meta = json.loads((CORPUS / case / f"{case}.json").read_text())
    t = min(meta["thickness"])
    prefix = OUT / "rays" / case
    prefix.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([str(compile_tool()), str(CORPUS / case / f"{case}.stp"), str(prefix), repr(t / 4),
                    repr(3 * max(meta["thickness"]))], check=True, capture_output=True)
    info, nodes, _ = load_rays(prefix)
    keys, X, directed = pair_features(info, nodes)
    y, share, _ = labels(case, nodes, keys, directed)
    np.savez_compressed(OUT / f"{case}.npz", keys=keys, X=X, y=y, share=share,
                        level=meta.get("level", 0), faces=len(info["faces"]))
    return dict(case=case, faces=len(info["faces"]), pairs=len(keys), positives=int(y.sum()))


# ---------------------------------------------------------------------------
# Training.


def load_split():
    data = defaultdict(lambda: dict(X=[], y=[], w=[], case=[]))
    for path in sorted(OUT.glob("*.npz")):
        z = np.load(path)
        if len(z["y"]) == 0:
            continue
        s = data[split_of(path.stem)]
        y = z["y"]
        # Classes balanced within each part (eq. 14 of the paper).
        w = np.where(y == 1, 0.5 / max(y.sum(), 1), 0.5 / max((1 - y).sum(), 1))
        s["X"].append(z["X"])
        s["y"].append(y)
        s["w"].append(w)
        s["case"] += [path.stem] * len(y)
    return {k: dict(X=np.vstack(v["X"]), y=np.concatenate(v["y"]), w=np.concatenate(v["w"]),
                    case=np.array(v["case"])) for k, v in data.items()}


def prf(y, p):
    tp = int((y & p).sum())
    precision = tp / max(int(p.sum()), 1)
    recall = tp / max(int(y.sum()), 1)
    return precision, recall, 2 * precision * recall / max(precision + recall, 1e-12)


def train():
    from sklearn.ensemble import HistGradientBoostingClassifier
    data = load_split()
    model = HistGradientBoostingClassifier(max_iter=400, learning_rate=0.08, max_leaf_nodes=31,
                                           l2_regularization=1e-3, categorical_features=[10, 11],
                                           random_state=1003)
    model.fit(data["train"]["X"], data["train"]["y"], sample_weight=data["train"]["w"])
    val = data["val"]
    score = model.predict_proba(val["X"])[:, 1]
    best = max(((prf(val["y"].astype(bool), score >= th)[2], th) for th in np.linspace(0.05, 0.95, 91)))
    threshold = float(best[1])
    report = dict(threshold=threshold, features=FEATURES)
    for name in ("train", "val", "test"):
        s = data[name]
        p = model.predict_proba(s["X"])[:, 1] >= threshold
        precision, recall, f1 = prf(s["y"].astype(bool), p)
        report[name] = dict(cases=len(set(s["case"])), pairs=len(s["y"]), positives=int(s["y"].sum()),
                            precision=precision, recall=recall, f1=f1)
    # The classical criteria as one rule, for comparison: gap within 20 % of
    # the typical thickness, normals within 25 degrees, overlap at least 50 %.
    s = data["test"]
    rule = (np.abs(s["X"][:, 1] - 1) < 0.2) & (s["X"][:, 2] < -math.cos(math.radians(25))) & (s["X"][:, 3] >= 0.5)
    report["rule_test"] = dict(zip(("precision", "recall", "f1"), prf(s["y"].astype(bool), rule)))
    OUT.mkdir(parents=True, exist_ok=True)
    pickle.dump(dict(model=model, threshold=threshold), open(OUT / "model.pkl", "wb"))
    (OUT / "report.json").write_text(json.dumps(report, indent=1))
    print(json.dumps(report, indent=1))


# ---------------------------------------------------------------------------
# Composition, mid-surfaces, measures.


def compose(keys, keep, weight=None):
    """Wall groups from the retained relations (Algorithm 1 of the paper, made
    robust): relations are taken by decreasing facing area and kept only if
    they do not close an odd cycle (union-find with parity), so that a small
    contact bridging two walls is dropped instead of invalidating the whole
    component. Each component is two-coloured into its sides (A, B).
    Returns the groups and the dropped relations."""
    weight = np.ones(len(keys)) if weight is None else np.asarray(weight)
    parent, parity = {}, {}

    def find(u):
        path = []
        while parent[u] != u:
            path.append(u)
            u = parent[u]
        root, acc = u, 0
        for v in reversed(path):
            acc ^= parity[v]
            parity[v], parent[v] = acc, root
        return root

    order = sorted((k for k in range(len(keys)) if keep[k]),
                   key=lambda k: (-weight[k], int(keys[k][0]), int(keys[k][1])))
    dropped = []
    for k in order:
        i, j = int(keys[k][0]), int(keys[k][1])
        for u in (i, j):
            if u not in parent:
                parent[u], parity[u] = u, 0
        ri, rj = find(i), find(j)
        if ri != rj:
            parent[rj], parity[rj] = ri, parity[i] ^ parity[j] ^ 1
        elif parity[i] == parity[j]:
            dropped.append((i, j))
    sides = defaultdict(lambda: ([], []))
    for u in sorted(parent):
        root = find(u)
        sides[root][parity[u]].append(u)
    return [(a, b) for a, b in (sides[r] for r in sorted(sides))], dropped


def pair_areas(nodes, keys, directed):
    """Area of the rays of each pair, both ways: how much the two faces face
    each other."""
    w = nodes[:, 7]
    return np.array([w[directed.get((int(i), int(j)), []) + directed.get((int(j), int(i)), [])].sum()
                     for i, j in keys])


def evaluate_one(case, model, threshold):
    meta = json.loads((CORPUS / case / f"{case}.json").read_text())
    info, nodes, tris = load_rays(OUT / "rays" / case)
    z = np.load(OUT / f"{case}.npz")
    keys, X, y = z["keys"], z["X"], z["y"]
    _, _, directed = pair_features(info, nodes)
    weight = pair_areas(nodes, keys, directed)
    score = model.predict_proba(X)[:, 1] if len(X) else np.zeros(0)
    keep = score >= threshold
    groups, bad = compose(keys, keep, weight)
    truth_groups, truth_bad = compose(keys, y.astype(bool), weight)
    # Dropped relations are not used for the mid-surface.
    dropped = {tuple(sorted(e)) for e in bad}
    keep = np.array([bool(k) and (int(i), int(j)) not in dropped for (i, j), k in zip(keys, keep)], dtype=bool)
    as_set = lambda gs: {frozenset((frozenset(a), frozenset(b))) for a, b in gs}
    exact = len(as_set(groups) & as_set(truth_groups))
    # Mid-surface: triangles of the sampling grids whose three nodes land on
    # a face retained with theirs, in a valid group.
    in_group = {f for a, b in groups for f in a + b}
    kept = {(int(i), int(j)) for (i, j), k in zip(keys, keep) if k and i in in_group}
    kept |= {(j, i) for i, j in kept}
    face_of, hit = nodes[:, 0].astype(int), nodes[:, 8].astype(int)
    ok = np.array([(f, h) in kept for f, h in zip(face_of, hit)], dtype=bool)
    tri_ok = ok[tris].all(axis=1)
    mid = midpoints(nodes, np.arange(len(nodes)))
    mid_tris = tris[tri_ok]
    # Measures against the truth.
    import label_branches as lb
    gmsh = lb.load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    lb.gmsh = gmsh
    truth = lb.truth_cloud(CORPUS / case, meta)
    t = truth["t"]
    if len(mid_tris):
        a, b, c = (mid[mid_tris[:, k]] for k in range(3))
        cloud = cKDTree(np.vstack([a, b, c, (a + b + c) / 3, (a + b) / 2, (b + c) / 2, (c + a) / 2]))
        covered = cloud.query(truth["centroid"])[0] / t < 0.1
        centroid = (a + b + c) / 3
        tri_area = 0.5 * np.linalg.norm(np.cross(b - a, c - a), axis=1)
        near = on_truth(truth, centroid)
        k = truth["tree"].query(centroid)[1]
        off_area = float((tri_area[~near] / t[k[~near]] ** 2).sum()) / 2  # each wall meshed from both sides
    else:
        covered = np.zeros(len(t), dtype=bool)
        off_area = 0.0
    area = truth["area"]
    # Away from the junctions (1.5 t from the true junction lines), where face
    # pairing has nothing to pair and the MAT gives the mid-surface.
    import projected_quality as pq
    import run_corpus
    run_corpus.gmsh = gmsh
    _, _, junction, _, _ = pq.edge_samples(CORPUS / case, meta, gmsh)
    away = cKDTree(junction).query(truth["centroid"])[0] / t > 1.5 if len(junction) else np.ones(len(t), bool)
    precision, recall, f1 = prf(y.astype(bool), keep)
    result = dict(case=case, level=meta.get("level"), split=split_of(case), faces=len(info["faces"]),
                  pairs=len(keys), positives=int(y.sum()), predicted=int(keep.sum()),
                  precision=precision, recall=recall, f1=f1,
                  groups=len(groups), truth_groups=len(truth_groups), exact_groups=exact,
                  dropped=len(bad), truth_dropped=len(truth_bad),
                  coverage=float(area[covered].sum() / area.sum()),
                  missing_area=float((area[~covered] / t[~covered] ** 2).sum()), off_truth_area=off_area,
                  coverage_away=float(area[covered & away].sum() / max(area[away].sum(), 1e-300)),
                  missing_away=float((area[~covered & away] / t[~covered & away] ** 2).sum()))
    # The mid-surface for viewing.
    gmsh.model.add("facepair")
    if len(mid_tris):
        used = np.unique(mid_tris)
        gmsh.model.addDiscreteEntity(2, 1)
        gmsh.model.mesh.addNodes(2, 1, (used + 1).tolist(), mid[used].ravel().tolist())
        gmsh.model.mesh.addElementsByType(1, 2, [], (mid_tris + 1).ravel().tolist())
        gmsh.write(str(OUT / f"{case}_facepair.msh"))
    gmsh.finalize()
    result["groups_list"] = [[[int(f) for f in a], [int(f) for f in b]] for a, b in groups]
    result["dropped_list"] = [[int(i), int(j)] for i, j in bad]
    (OUT / f"{case}_facepair.json").write_text(json.dumps(result, indent=1))
    return result


BREP_TOOL = ROOT / "build/facepair_brep_tool"


def compile_brep_tool():
    source = HERE / "facepair_brep.cpp"
    if BREP_TOOL.is_file() and BREP_TOOL.stat().st_mtime > source.stat().st_mtime:
        return BREP_TOOL
    import os
    occ = Path(os.environ.get("OCC_ROOT", "/opt/homebrew/opt/opencascade"))
    libs = ["TKernel", "TKMath", "TKG2d", "TKG3d", "TKGeomBase", "TKBRep", "TKGeomAlgo", "TKTopAlgo",
            "TKMesh", "TKDESTEP", "TKDE", "TKXSBase", "TKShHealing", "TKOffset", "TKBool", "TKBO", "TKPrim",
            "TKFillet"]
    subprocess.run(["c++", "-std=c++17", "-O2", f"-I{occ}/include/opencascade", str(source), "-o",
                    str(BREP_TOOL), f"-L{occ}/lib", f"-Wl,-rpath,{occ}/lib"] + [f"-l{lib}" for lib in libs],
                   check=True)
    return BREP_TOOL


def cover(a, b, kept, weight):
    """Faces to offset in a wall group (sides a and b): every retained pair
    must have one of its two faces offset (both would give the same mid
    face): a minimum weighted vertex cover of the bipartite pair graph, i.e.
    a minimum cut; faces of weight None are avoided."""
    from scipy.sparse import csr_matrix
    from scipy.sparse.csgraph import maximum_flow
    a, b = list(a), list(b)
    n = len(a) + len(b) + 2
    source, sink = n - 2, n - 1
    position = {f: k for k, f in enumerate(a + b)}
    # Integer capacities (int32): weights of wall faces from 1 to 1e4, faces
    # to avoid (weight None) far above.
    largest = max([w for w in weight.values() if w is not None] + [1e-12])
    cap = lambda f: 200000 if weight[f] is None else max(1, int(round(1e4 * weight[f] / largest)))
    rows, cols, caps = [], [], []
    for f in a:
        rows.append(source); cols.append(position[f]); caps.append(cap(f))
    for f in b:
        rows.append(position[f]); cols.append(sink); caps.append(cap(f))
    big = 2 ** 30
    for f in a:
        for g in b:
            if (f, g) in kept:
                rows.append(position[f]); cols.append(position[g]); caps.append(big)
    graph = csr_matrix((np.array(caps, dtype=np.int32), (rows, cols)), shape=(n, n))
    flow = maximum_flow(graph, source, sink).flow
    # The flow is antisymmetric: capacity minus flow is the residual graph,
    # reverse edges included.
    residual = (graph - flow).tocsr()
    reached = {source}
    stack = [source]
    while stack:
        u = stack.pop()
        row = residual.getrow(u)
        for v, c in zip(row.indices, row.data):
            if c > 0 and v not in reached:
                reached.add(v)
                stack.append(v)
    return [f for f in a if position[f] not in reached] + [f for f in b if position[f] in reached]


def mid_plan(groups, kept, nodes, area_of, curvature_of=None):
    """Faces to offset and their offsets: in each group, the cover of the
    retained pairs among the faces that mostly face their partners (a fillet
    meets the other side only along its tangent line and its offset would
    leave the mid-surface), each offset by half the gap to its main partner
    (the one it faces over the largest area with opposite normals; other
    partners may be reached obliquely). Returns the plan and the number of
    faces whose gap varies by more than 10 %."""
    face_of, hit, dist, weight, cos = (nodes[:, 0].astype(int), nodes[:, 8].astype(int), nodes[:, 9], nodes[:, 7],
                                       nodes[:, 10])
    plan, variable = [], 0
    for a, b in groups:
        wall_like, gap_of = {}, {}
        for side, other in ((a, b), (b, a)):
            for f in side:
                partners = [p for p in other if (f, p) in kept]
                own = face_of == f
                m = own & np.isin(hit, partners)
                wall_like[f] = bool(m.any() and weight[m].sum() >= 0.5 * weight[own].sum())
                # A face curved too much for its offset (an edge rounding of
                # radius 1.5 offset by 2) would turn over: the face opposite
                # is offset instead.
                if wall_like[f] and curvature_of and m.any():
                    wall_like[f] = 2 * curvature_of.get(f, 0.0) * 0.5 * float(np.median(dist[m])) <= 0.8
                best = None
                for p in partners:
                    mp = own & (hit == p) & (cos < -0.95)
                    if mp.any() and (best is None or weight[mp].sum() > weight[best].sum()):
                        best = mp
                if best is None:
                    continue
                d, w = dist[best], weight[best]
                order = np.argsort(d)
                cw = np.cumsum(w[order]) / w.sum()
                q = lambda x: float(d[order][min(np.searchsorted(cw, x), len(d) - 1)])
                gap_of[f] = (q(0.5), (q(0.9) - q(0.1)) > 0.1 * q(0.5))
        # Weight 1 / area: the cover prefers a few large faces, which run on
        # under the features (the bottom of a plate under its ribs) where the
        # smaller faces opposite are cut.
        for f in cover(a, b, kept, {f: 1.0 / max(area_of[f], 1e-12) if wall_like[f] else None for f in a + b}):
            if wall_like[f] and f in gap_of:
                plan.append((int(f), -0.5 * gap_of[f][0]))
                variable += gap_of[f][1]
    return plan, variable


def extend_to_material(gmsh, brep_path, part_path, t, out_path, plan=()):
    """Planar mid faces prolonged in their plane up to where the material
    ends, across their free edges only (those farther than t / 2 from every
    other mid face; at a bend or a junction the neighbour covers the rest):
    the section of the plane by the part, within delta = 0.75 t of those
    edges (tubes of that radius around them), outside the face and touching
    it (a rounded or chamfered edge). Writes the mid faces and the pieces;
    returns the number of pieces. (plan: unused, kept for the callers.)"""
    delta = 0.75 * t
    occ = gmsh.model.occ
    gmsh.model.add("extend")
    part = occ.importShapes(str(part_path))
    mids = [tag for dim, tag in occ.importShapes(str(brep_path)) if dim == 2]
    occ.synchronize()
    solids = [(d, tg) for d, tg in part if d == 3]
    kept = []
    for m in mids:
        if gmsh.model.getType(2, m) != "Plane":
            continue
        # Free edges, sampled about every delta.
        free = []
        for _, cv in gmsh.model.getBoundary([(2, m)], oriented=False):
            cv = abs(cv)
            if all(occ.getDistance(1, cv, 2, o)[0] > 0.5 * t for o in mids if o != m):
                lo, hi = gmsh.model.getParametrizationBounds(1, cv)
                k = max(2, int(math.ceil(occ.getMass(1, cv) / delta)) + 1)
                free.append(np.array(gmsh.model.getValue(1, cv, list(np.linspace(lo[0], hi[0], k)))).reshape(-1, 3))
        if not free:
            continue
        lo = gmsh.model.getParametrizationBounds(2, m)
        n = np.array(gmsh.model.getNormal(m, [0.5 * (lo[0][0] + lo[1][0]), 0.5 * (lo[0][1] + lo[1][1])]))
        x0, y0, z0, x1, y1, z1 = gmsh.model.getBoundingBox(2, m)
        c = np.array(gmsh.model.getClosestPoint(2, m, [0.5 * (x0 + x1), 0.5 * (y0 + y1), 0.5 * (z0 + z1)])[0])
        e1 = np.cross(n, [1, 0, 0] if abs(n[0]) < 0.9 else [0, 1, 0])
        e1 /= np.linalg.norm(e1)
        e2 = np.cross(n, e1)
        half = 0.5 * math.dist((x0, y0, z0), (x1, y1, z1)) + 2 * delta
        corners = [c + half * (a * e1 + b * e2) for a, b in ((-1, -1), (1, -1), (1, 1), (-1, 1))]
        points = [occ.addPoint(*p) for p in corners]
        sheet = occ.addPlaneSurface([occ.addCurveLoop([occ.addLine(points[k], points[(k + 1) % 4]) for k in range(4)])])
        tubes = []
        for chain in free:
            for p, q in zip(chain[:-1], chain[1:]):
                if np.linalg.norm(q - p) > 1e-9:
                    tubes.append((3, occ.addCylinder(*p, *(q - p), delta)))
                tubes.append((3, occ.addSphere(*p, delta)))
            tubes.append((3, occ.addSphere(*chain[-1], delta)))
        try:
            section, _ = occ.intersect([(2, sheet)], solids, removeObject=True, removeTool=False)
            near, _ = occ.intersect(section, tubes, removeObject=True, removeTool=True) if section else ([], [])
            rest, _ = occ.cut(near, [(2, m)], removeObject=True, removeTool=False) if near else ([], [])
        except Exception:  # noqa: BLE001
            occ.synchronize()
            continue
        occ.synchronize()
        for dim, piece in rest:
            if dim == 2 and occ.getDistance(2, piece, 2, m)[0] < 1e-6 * max(t, 1.0):
                kept.append(piece)
            elif dim == 2:
                occ.remove([(2, piece)], recursive=True)
        occ.synchronize()
    occ.remove(part, recursive=True)
    occ.synchronize()
    # Only the mid faces and the kept pieces are written: tubes left by an
    # empty section or a failed boolean (volumes and their spheres) go.
    keep = set(mids) | set(kept)
    leftovers = gmsh.model.getEntities(3) + [(2, s) for _, s in gmsh.model.getEntities(2) if s not in keep]
    if leftovers:
        occ.remove(leftovers, recursive=False)
        occ.synchronize()
        orphans = [(d, e) for d in (1, 0) for _, e in gmsh.model.getEntities(d)
                   if not gmsh.model.getAdjacencies(d, e)[0].size]
        if orphans:
            occ.remove(orphans, recursive=False)
            occ.synchronize()
    gmsh.write(str(out_path))
    gmsh.model.remove()
    return len(kept)


def brep_one(case, model, threshold):
    """Mid faces as a BRep: in each wall group, a set of faces covering every
    retained pair (cover), preferring large faces, is offset into the material by half
    the gap of its rays to its partners; then measured against the truth like
    the mesh."""
    meta = json.loads((CORPUS / case / f"{case}.json").read_text())
    info, nodes, _ = load_rays(OUT / "rays" / case)
    z = np.load(OUT / f"{case}.npz")
    keys, X = z["keys"], z["X"]
    keep = model.predict_proba(X)[:, 1] >= threshold if len(X) else np.zeros(0, dtype=bool)
    _, _, directed = pair_features(info, nodes)
    groups, bad = compose(keys, keep, pair_areas(nodes, keys, directed))
    dropped = {tuple(sorted(e)) for e in bad}
    keep = np.array([bool(k) and (int(i), int(j)) not in dropped for (i, j), k in zip(keys, keep)], dtype=bool)
    area_of = {f["id"]: f["area"] for f in info["faces"]}
    kept = {(int(i), int(j)) for (i, j), k in zip(keys, keep) if k}
    kept |= {(j, i) for i, j in kept}
    face_of, hit, dist, weight = nodes[:, 0].astype(int), nodes[:, 8].astype(int), nodes[:, 9], nodes[:, 7]
    plan, variable = mid_plan(groups, kept, nodes, area_of, {f["id"]: f["mean_curvature"] for f in info["faces"]})
    plan_path, brep_path = OUT / f"{case}_plan.txt", OUT / f"{case}_mid.brep"
    plan_path.write_text("".join(f"{f} {o:.9g}\n" for f, o in plan))
    run = subprocess.run([str(compile_brep_tool()), str(CORPUS / case / f"{case}.stp"), str(plan_path),
                          str(brep_path)], capture_output=True, text=True)
    failed = run.stderr.count("failed")
    import label_branches as lb
    import projected_quality as pq
    import run_corpus
    gmsh = lb.load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    lb.gmsh = gmsh
    run_corpus.gmsh = gmsh
    truth = lb.truth_cloud(CORPUS / case, meta)
    t, area = truth["t"], truth["area"]
    _, _, junction, _, _ = pq.edge_samples(CORPUS / case, meta, gmsh)
    away = cKDTree(junction).query(truth["centroid"])[0] / t > 1.5 if len(junction) else np.ones(len(t), bool)
    # Prolonged up to the material at the free edges.
    # In a process of its own: a crash of a boolean operation (it happens)
    # leaves the offsets as they are.
    extended_path = OUT / f"{case}_mid_ext.brep"
    run = subprocess.run([sys.executable, str(HERE / "steps.py"), "extend", str(CORPUS / case / f"{case}.stp"),
                          str(brep_path), str(plan_path), repr(min(meta["thickness"])), str(extended_path)],
                         capture_output=True, text=True)
    if run.returncode == 0 and "pieces added" in run.stdout:
        pieces = int(run.stdout.split(" pieces added")[0].split()[-1])
    else:
        pieces = -1
        extended_path = brep_path
    gmsh.model.add("mid")
    gmsh.model.occ.importShapes(str(extended_path))
    gmsh.model.occ.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", min(meta["thickness"]) / 4)
    gmsh.model.mesh.generate(2)
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = coords.reshape(-1, 3)
    index = np.zeros(int(tags.max()) + 1 if len(tags) else 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    tri = [xyz[index[c.reshape(-1, 3).astype(np.int64)]] for ty, c in
           zip(*gmsh.model.mesh.getElements(2)[::2]) if ty == 2]
    gmsh.finalize()
    tri = np.vstack(tri) if tri else np.zeros((0, 3, 3))
    if len(tri):
        a_, b_, c_ = tri[:, 0], tri[:, 1], tri[:, 2]
        cloud = cKDTree(np.vstack([a_, b_, c_, (a_ + b_ + c_) / 3, (a_ + b_) / 2, (b_ + c_) / 2, (c_ + a_) / 2]))
        covered = cloud.query(truth["centroid"])[0] / t < 0.1
        centroid = (a_ + b_ + c_) / 3
        tri_area = 0.5 * np.linalg.norm(np.cross(b_ - a_, c_ - a_), axis=1)
        near = on_truth(truth, centroid)
        k = truth["tree"].query(centroid)[1]
        off = float((tri_area[~near] / t[k[~near]] ** 2).sum())
        # Off the truth beyond 1.5 t from its junction lines (overshoot of a
        # wall into the thickness of the one it meets is a trimming matter).
        far = cKDTree(junction).query(centroid)[0] / t[k] > 1.5 if len(junction) else np.ones(len(k), bool)
        off_away = float((tri_area[~near & far] / t[k[~near & far]] ** 2).sum())
    else:
        covered, off, off_away = np.zeros(len(t), dtype=bool), 0.0, 0.0
    result = dict(case=case, level=meta.get("level"), split=split_of(case), mid_faces=len(plan), extension_pieces=pieces,
                  offset_failed=failed, variable_gap=int(variable),
                  coverage=float(area[covered].sum() / area.sum()),
                  missing_area=float((area[~covered] / t[~covered] ** 2).sum()), off_truth_area=off,
                  off_truth_away=off_away,
                  coverage_away=float(area[covered & away].sum() / max(area[away].sum(), 1e-300)),
                  missing_away=float((area[~covered & away] / t[~covered & away] ** 2).sum()))
    (OUT / f"{case}_brep.json").write_text(json.dumps(result, indent=1))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("command", choices=["prepare", "train", "evaluate", "brep"])
    parser.add_argument("--only", default="*")
    parser.add_argument("--levels", default="")
    parser.add_argument("--jobs", type=int, default=3)
    parser.add_argument("--one", default="", help=argparse.SUPPRESS)
    args = parser.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)
    if args.command == "train":
        train()
        return
    if args.one:
        if args.command == "prepare":
            print("RESULT " + json.dumps(prepare_one(args.one)))
        elif args.command == "brep":
            m = pickle.load(open(OUT / "model.pkl", "rb"))
            print("RESULT " + json.dumps(brep_one(args.one, m["model"], m["threshold"])))
        else:
            m = pickle.load(open(OUT / "model.pkl", "rb"))
            r = evaluate_one(args.one, m["model"], m["threshold"])
            r.pop("groups_list")
            r.pop("dropped_list")
            print("RESULT " + json.dumps(r))
        return
    if args.command == "prepare":
        compile_tool()
    todo = cases(args.only, args.levels)
    if args.command in ("evaluate", "brep"):
        todo = [c for c in todo if (OUT / f"{c}.npz").is_file()]
    if args.command == "brep":
        compile_brep_tool()

    def one(case):
        done = OUT / f"{case}_facepair.json"
        if args.command == "evaluate" and done.is_file() and done.stat().st_mtime > (OUT / "model.pkl").stat().st_mtime:
            r = json.loads(done.read_text())
            if "coverage_away" in r:
                r.pop("groups_list", None)
                r.pop("dropped_list", None)
                return r
        r = subprocess.run([sys.executable, __file__, args.command, "--one", case], capture_output=True, text=True,
                           errors="replace")
        for line in r.stdout.splitlines():
            if line.startswith("RESULT "):
                return json.loads(line[7:])
        print(case, "failed:", r.stderr[-500:], file=sys.stderr)
        return None

    with ThreadPoolExecutor(args.jobs) as pool:
        results = [r for r in pool.map(one, todo) if r]
    if args.command == "prepare":
        print(f"{len(results)} cases prepared, {sum(r['pairs'] for r in results)} candidate pairs, "
              f"{sum(r['positives'] for r in results)} positive")
        return
    if args.command == "brep":
        (OUT / "brep_evaluation.json").write_text(json.dumps(results, indent=1))
        print(f"{'case':32s} {'split':5s} {'faces':>5s} {'fail':>4s} {'var':>3s} {'cover':>6s} {'miss t2':>8s} "
              f"{'off t2':>7s} {'cov.away':>8s} {'miss.away':>9s} {'off.away':>8s}")
        for r in sorted(results, key=lambda r: (r["level"] or 0, r["case"])):
            print(f"{r['case']:32s} {r['split']:5s} {r['mid_faces']:5d} {r['offset_failed']:4d} "
                  f"{r['variable_gap']:3d} {r['coverage']:6.3f} {r['missing_area']:8.2f} {r['off_truth_area']:7.2f} "
                  f"{r['coverage_away']:8.4f} {r['missing_away']:9.2f} {r['off_truth_away']:8.2f}")
        return
    (OUT / "evaluation.json").write_text(json.dumps(results, indent=1))
    print(f"{'case':32s} {'split':5s} {'faces':>5s} {'P':>6s} {'R':>6s} {'F1':>6s} {'groups':>9s} {'drop':>4s} "
          f"{'cover':>6s} {'miss t2':>8s} {'off t2':>7s} {'cov.away':>8s} {'miss.away':>9s}")
    for r in sorted(results, key=lambda r: (r["split"], r["level"] or 0, r["case"])):
        print(f"{r['case']:32s} {r['split']:5s} {r['faces']:5d} {r['precision']:6.3f} {r['recall']:6.3f} "
              f"{r['f1']:6.3f} {r['exact_groups']:3d}/{r['truth_groups']:<3d}  {r['dropped']:3d} "
              f"{r['coverage']:6.3f} {r['missing_area']:8.2f} {r['off_truth_area']:7.2f} "
              f"{r['coverage_away']:8.4f} {r['missing_away']:9.2f}")
    for split in ("train", "val", "test"):
        rs = [r for r in results if r["split"] == split]
        if rs:
            exact = sum(r["exact_groups"] == r["truth_groups"] for r in rs)
            print(f"{split}: {len(rs)} cases, all groups exact in {exact}, "
                  f"mean coverage {np.mean([r['coverage'] for r in rs]):.4f}, "
                  f"away from junctions {np.mean([r['coverage_away'] for r in rs]):.4f}")


if __name__ == "__main__":
    main()

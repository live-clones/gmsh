#!/usr/bin/env python3
"""The face-pairing chain one step at a time, for use from a terminal.

  steps.py compile                                   build the two C++ tools, print their paths
  steps.py thickness <rays prefix>                   typical gap between opposing faces (t, 95th percentile)
  steps.py pairs <rays prefix> <plan> [--model M]    scores, wall groups, faces to offset, and the walls
                                                     (offset face, main partner) for MatGmsh --face-pairs
  steps.py extend <part> <mid.brep> <plan> <t> <out.brep>
                                                     prolong planar mid faces up to the material
  steps.py measure <case> <brep>                     coverage of the true mid-surface (corpus cases)

The rays come from build/facepair_tool, the offset faces from
build/facepair_brep_tool (see README.md for the whole sequence).
"""

from __future__ import annotations

import argparse
import json
import pickle
import sys
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import facepair as fp  # noqa: E402


def gmsh_session():
    import label_branches as lb
    gmsh = lb.load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    lb.gmsh = gmsh
    return gmsh


def thickness(prefix):
    _, nodes, _ = fp.load_rays(Path(prefix))
    hit, cos, dist, area = nodes[:, 8], nodes[:, 10], nodes[:, 9], nodes[:, 7]
    facing = (hit > 0) & (cos < -0.95)
    if not facing.any():
        print("no opposing faces")
        return
    order = np.argsort(dist[facing])
    d, w = dist[facing][order], area[facing][order]
    cw = np.cumsum(w) / w.sum()
    q = lambda x: float(d[min(np.searchsorted(cw, x), len(d) - 1)])
    print(f"t = {q(0.5):.6g}   (95th percentile {q(0.95):.6g}; {facing.sum()} facing rays)")


def pairs(prefix, plan_path, model_path):
    prefix = Path(prefix)
    info, nodes, _ = fp.load_rays(prefix)
    keys, X, directed = fp.pair_features(info, nodes)
    m = pickle.load(open(model_path, "rb"))
    score = m["model"].predict_proba(np.nan_to_num(X))[:, 1] if len(X) else np.zeros(0)
    keep = score >= m["threshold"]
    weight = fp.pair_areas(nodes, keys, directed)
    groups, dropped = fp.compose(keys, keep, weight)
    gone = {tuple(sorted(e)) for e in dropped}
    keep = np.array([bool(k) and (int(i), int(j)) not in gone for (i, j), k in zip(keys, keep)], dtype=bool)
    kept = {(int(i), int(j)) for (i, j), k in zip(keys, keep) if k}
    kept |= {(j, i) for i, j in kept}
    area_of = {f["id"]: f["area"] for f in info["faces"]}
    plan, variable = fp.mid_plan(groups, kept, nodes, area_of, {f["id"]: f["mean_curvature"] for f in info["faces"]})
    Path(plan_path).write_text("".join(f"{f} {o:.9g}\n" for f, o in plan))
    # The walls: every offset face with its main partner (the retained
    # partner it faces over the largest area, normals opposite), for the
    # CAD projection of the MAT (MatGmsh --face-pairs). The other retained
    # pairs (a fillet with the face it meets obliquely) are not walls.
    face_of, hit, weight, cos = nodes[:, 0].astype(int), nodes[:, 8].astype(int), nodes[:, 7], nodes[:, 10]
    walls = []
    for f, _ in plan:
        partners = [b for a, b in kept if a == f]
        best, area = None, 0.0
        for q in partners:
            facing = (face_of == f) & (hit == q) & (cos < -0.95)
            if weight[facing].sum() > area:
                best, area = q, float(weight[facing].sum())
        if best is not None:
            walls.append((f, best))
    Path(f"{prefix}.walls.txt").write_text("".join(f"{a} {b}\n" for a, b in walls))
    report = dict(faces=len(info["faces"]), candidate_pairs=len(keys), threshold=m["threshold"],
                  pairs=[dict(faces=[int(i), int(j)], score=float(s), facing_area=float(a), kept=bool(k))
                         for (i, j), s, a, k in zip(keys, score, weight, keep)],
                  groups=[[[int(f) for f in a], [int(f) for f in b]] for a, b in groups],
                  dropped=[[int(i), int(j)] for i, j in dropped], plan=[[f, o] for f, o in plan],
                  variable_gap=int(variable))
    out = Path(f"{prefix}.pairs.json")
    out.write_text(json.dumps(report, indent=1))
    print(f"{len(keys)} candidate pairs, {int(keep.sum())} retained, {len(dropped)} dropped (odd cycles), "
          f"{len(groups)} wall groups, {len(plan)} faces to offset ({variable} with a varying gap)")
    print(f"-> {out}\n-> {plan_path}\n-> {prefix}.walls.txt ({len(walls)} walls)")


def extend(part, brep, plan_path, t, out):
    plan = [(int(a), float(b)) for a, b in (line.split() for line in Path(plan_path).read_text().splitlines() if line)]
    gmsh = gmsh_session()
    pieces = fp.extend_to_material(gmsh, Path(brep), Path(part), float(t), Path(out), plan)
    gmsh.finalize()
    print(f"{pieces} pieces added -> {out}")


def measure(case, brep):
    import projected_quality as pq
    import run_corpus
    gmsh = gmsh_session()
    run_corpus.gmsh = gmsh
    meta = json.loads((fp.CORPUS / case / f"{case}.json").read_text())
    import label_branches as lb
    truth = lb.truth_cloud(fp.CORPUS / case, meta)
    t, area = truth["t"], truth["area"]
    _, _, junction, _, _ = pq.edge_samples(fp.CORPUS / case, meta, gmsh)
    away = cKDTree(junction).query(truth["centroid"])[0] / t > 1.5 if len(junction) else np.ones(len(t), bool)
    gmsh.model.add("mid")
    gmsh.model.occ.importShapes(str(brep))
    gmsh.model.occ.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", min(meta["thickness"]) / 4)
    gmsh.model.mesh.generate(2)
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = coords.reshape(-1, 3)
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    types, _, conn = gmsh.model.mesh.getElements(2)
    tri = np.vstack([xyz[index[c.reshape(-1, 3).astype(np.int64)]] for ty, c in zip(types, conn) if ty == 2])
    gmsh.finalize()
    a, b, c = tri[:, 0], tri[:, 1], tri[:, 2]
    covered = cKDTree(np.vstack([a, b, c, (a + b + c) / 3])).query(truth["centroid"])[0] / t < 0.1
    centroid = (a + b + c) / 3
    near = fp.on_truth(truth, centroid)
    k = truth["tree"].query(centroid)[1]
    off = float((0.5 * np.linalg.norm(np.cross(b - a, c - a), axis=1)[~near] / t[k[~near]] ** 2).sum())
    print(f"coverage {area[covered].sum() / area.sum():.4f}  missing {(area[~covered] / t[~covered] ** 2).sum():.2f} t2  "
          f"off truth {off:.2f} t2  |  away from junctions: coverage "
          f"{area[covered & away].sum() / max(area[away].sum(), 1e-300):.4f}, "
          f"missing {(area[~covered & away] / t[~covered & away] ** 2).sum():.2f} t2")


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("compile")
    p = sub.add_parser("thickness")
    p.add_argument("prefix")
    p = sub.add_parser("pairs")
    p.add_argument("prefix")
    p.add_argument("plan")
    p.add_argument("--model", default=str(fp.OUT / "model.pkl"))
    p = sub.add_parser("extend")
    for name in ("part", "brep", "plan", "t", "out"):
        p.add_argument(name)
    p = sub.add_parser("measure")
    p.add_argument("case")
    p.add_argument("brep")
    args = parser.parse_args()
    if args.command == "compile":
        print(fp.compile_tool())
        print(fp.compile_brep_tool())
    elif args.command == "thickness":
        thickness(args.prefix)
    elif args.command == "pairs":
        pairs(args.prefix, args.plan, args.model)
    elif args.command == "extend":
        extend(args.part, args.brep, args.plan, args.t, args.out)
    else:
        measure(args.case, args.brep)


if __name__ == "__main__":
    main()

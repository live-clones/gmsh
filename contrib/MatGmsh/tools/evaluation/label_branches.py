#!/usr/bin/env python3
"""Label every raw MAT branch of the corpus runs with the ground truth and
confront the labels with MatGmsh's decisions.

Needs runs made with --write-branch-table (run_corpus.py ... -- --write-branch-table).
For each branch of the classified MAT (<case>_mat_all.msh), the fraction of
its area within 0.1 t of the true mid-surface (t: local sheet thickness) gives
its label: keep (>= 0.5), reject (<= 0.2) or mixed. Writes
<runs>/<case>/branch_labels.csv and prints, over all cases, the areas (in t^2)
of true mid-surface lost (keep branches removed) and of wrong MAT kept (reject
branches retained), by deciding stage and by tree class.
"""

from __future__ import annotations

import argparse
import csv
import fnmatch
import json
import math
import sys
from collections import defaultdict
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE.parent))
from direct_midsurface_cases import load_gmsh  # noqa: E402

gmsh = None
KEEP, REJECT = 0.5, 0.2


def truth_cloud(case_dir: Path, meta):
    """Triangles of a fine mesh of the true mid-surface: centroids (in a
    KD-tree), unit normals, areas and local thickness."""
    gmsh.model.add("truth")
    gmsh.model.occ.importShapes(str(case_dir / f"{case_dir.name}_midsurface.brep"))
    gmsh.model.occ.synchronize()
    t = min(meta["thickness"])
    gmsh.option.setNumber("Mesh.MeshSizeMax", t / 6)
    gmsh.option.setNumber("Mesh.MeshSizeMin", 0.0)
    gmsh.option.setNumber("Mesh.Algorithm", 6)
    gmsh.model.mesh.generate(2)
    tags, coords, _ = gmsh.model.mesh.getNodes()
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    xyz = coords.reshape(-1, 3)
    centroids, normals, areas, local, triangles = [], [], [], [], []
    for _, s in gmsh.model.getEntities(2):
        c = gmsh.model.occ.getCenterOfMass(2, s)
        face = min(meta["midsurface_faces"], key=lambda f: math.dist(c, f["center"]))
        types, _, nodes = gmsh.model.mesh.getElements(2, s)
        tri = [n.reshape(-1, 3) for k, n in zip(types, nodes) if k == 2]
        if not tri:
            continue
        q = xyz[index[np.vstack(tri).astype(np.int64)]]
        triangles.append(q)
        cross = np.cross(q[:, 1] - q[:, 0], q[:, 2] - q[:, 0])
        norm = np.linalg.norm(cross, axis=1)
        centroids.append(q.mean(axis=1))
        normals.append(cross / np.maximum(norm, 1e-300)[:, None])
        areas.append(0.5 * norm)
        local.append(np.full(len(q), face["thickness"]))
    gmsh.model.remove()
    return dict(tree=cKDTree(np.vstack(centroids)), normal=np.vstack(normals),
                area=np.concatenate(areas), t=np.concatenate(local),
                centroid=np.vstack(centroids), triangles=np.vstack(triangles))


def on_truth(truth, centroid, normal):
    """Triangles within 0.1 t of the true mid-surface and parallel to it. The
    distance is taken to the tangent plane of the nearest truth sample (a
    point at the very edge of a sheet lies beyond the last samples), with an
    in-plane offset below half a thickness."""
    # Near a junction the nearest sample may belong to the other sheet: a
    # triangle is on the truth when it fits any of its nearest samples.
    k = min(8, len(truth["t"]))
    d, i = truth["tree"].query(centroid, k=k)
    d, i = d.reshape(len(centroid), k), i.reshape(len(centroid), k)
    t = truth["t"][i[:, 0]]
    delta = centroid[:, None, :] - truth["centroid"][i]
    n = truth["normal"][i]
    off_plane = np.abs(np.einsum("ijk,ijk->ij", delta, n))
    in_plane = np.sqrt(np.maximum(d * d - off_plane * off_plane, 0.0))
    aligned = np.abs(np.einsum("ik,ijk->ij", normal, n)) > 0.9
    tk = truth["t"][i]
    fits = (off_plane / tk < 0.1) & (in_plane / tk < 0.5) & aligned
    return fits.any(axis=1), t


def coverage(truth, centroid):
    """Truth triangles with a given triangle centroid within 0.15 t."""
    covered = np.zeros(len(truth["area"]), dtype=bool)
    if len(centroid):
        d, _ = cKDTree(centroid).query(truth["centroid"])
        covered = d / truth["t"] < 0.15
    return covered


def entity_triangles(msh: Path):
    """Centroids and areas of the triangles of every surface entity."""
    gmsh.model.add("mat")
    gmsh.merge(str(msh))
    tags, coords, _ = gmsh.model.mesh.getNodes()
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    xyz = coords.reshape(-1, 3)
    out = {}
    for _, s in gmsh.model.getEntities(2):
        types, _, nodes = gmsh.model.mesh.getElements(2, s)
        tri = [n.reshape(-1, 3) for k, n in zip(types, nodes) if k == 2]
        if not tri:
            continue
        p = xyz[index[np.vstack(tri).astype(np.int64)]]
        cross = np.cross(p[:, 1] - p[:, 0], p[:, 2] - p[:, 0])
        norm = np.linalg.norm(cross, axis=1)
        out[s] = (p.mean(axis=1), 0.5 * norm, cross / np.maximum(norm, 1e-300)[:, None])
    gmsh.model.remove()
    return out


def label_case(case_dir: Path, run_dir: Path):
    name = case_dir.name
    meta = json.loads((case_dir / f"{name}.json").read_text())
    table = run_dir / f"{name}_mat_branch_decisions.csv"
    msh = run_dir / f"{name}_mat_all.msh"
    if not table.is_file() or not msh.is_file():
        return None
    truth = truth_cloud(case_dir, meta)
    entities = entity_triangles(msh)
    final = run_dir / f"{name}_mat_all_filtered_proj.msh"
    final_entities = entity_triangles(final) if final.is_file() else {}
    rows = list(csv.DictReader(open(table)))
    # Branches sharing classified entities (merged or selection-homogeneous
    # groups) cannot be told apart in the classified MAT: label and score each
    # group of branches with the same entities. Faces of branches merged into
    # another one are counted in that branch's final faces.
    groups = defaultdict(list)
    for row in rows:
        if row["classified_entity_tags"]:
            groups[row["classified_entity_tags"]].append(row)
    out = []
    for key, members in groups.items():
        tags = [int(t) for t in key.split(";") if t]
        centroids = [entities[t][0] for t in tags if t in entities]
        areas = [entities[t][1] for t in tags if t in entities]
        normals = [entities[t][2] for t in tags if t in entities]
        if not centroids:
            continue
        c, a = np.vstack(centroids), np.concatenate(areas)
        near, t_local = on_truth(truth, c, np.vstack(normals))
        fraction = float(a[near].sum() / a.sum()) if a.sum() > 0 else 0.0
        label = "keep" if fraction >= KEEP else "reject" if fraction <= REJECT else "mixed"
        raw = sum(int(m["stage_raw_faces"] or 0) for m in members)
        removers = defaultdict(int)
        for m in members:
            for part in filter(None, m["removed_faces_by"].split(";")):
                stage, _, count = part.partition(":")
                removers[stage] += int(count or 0)
        # Only the faces removed by a filtering stage count: the final face
        # count also drops by the faces made degenerate (zero area) by the
        # post-projection vertex merge.
        kept = max(0.0, 1.0 - sum(removers.values()) / raw) if raw else 0.0
        t2 = float(np.mean(t_local)) ** 2
        classes = sorted({m["automatic_status"] for m in members})
        stages = sorted({m["deciding_stage"] for m in members})
        out.append(dict(branch_ids=";".join(m["branch_id"] for m in members), label=label,
                        on_truth_fraction=fraction, area_t2=float(a.sum()) / t2,
                        on_truth_area_t2=float(a[near].sum()) / t2,
                        tree_class="+".join(classes), deciding_stage="+".join(stages),
                        retained_fraction=kept,
                        removed_faces_by=max(removers, key=removers.get) if removers else ""))
    with open(run_dir / "branch_labels.csv", "w", newline="") as f:
        w = csv.DictWriter(f, list(out[0].keys()))
        w.writeheader()
        w.writerows(out)
    # Coverage of the truth: reachable from the raw MAT (near and parallel
    # triangles of any branch) and reached by the final MAT.
    raw_c = [e[0] for e in entities.values()]
    raw_n = [e[2] for e in entities.values()]
    good = np.vstack(raw_c)[on_truth(truth, np.vstack(raw_c), np.vstack(raw_n))[0]]
    reachable = coverage(truth, good)
    fc = np.vstack([e[0] for e in final_entities.values()]) if final_entities else np.zeros((0, 3))
    fn = np.vstack([e[2] for e in final_entities.values()]) if final_entities else np.zeros((0, 3))
    fa = np.concatenate([e[1] for e in final_entities.values()]) if final_entities else np.zeros(0)
    reached = coverage(truth, fc)
    ok_final, tf = on_truth(truth, fc, fn) if len(fc) else (np.zeros(0, bool), np.ones(0))
    area = truth["area"].sum()
    summary = dict(case=name, reachable=float(truth["area"][reachable].sum() / area),
                   reached=float(truth["area"][reached].sum() / area),
                   reachable_not_reached_t2=float((truth["area"] / truth["t"] ** 2)
                                                  [reachable & ~reached].sum()),
                   final_off_truth_t2=float((fa / tf ** 2)[~ok_final].sum()) if len(fa) else 0.0)
    return out, summary


def main():
    global gmsh
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--corpus", type=Path, default=ROOT / "build/corpus")
    parser.add_argument("--runs", type=Path, default=ROOT / "build/corpus_runs")
    parser.add_argument("--only", default="*")
    parser.add_argument("--top", type=int, default=15, help="worst cases to list")
    args = parser.parse_args()
    gmsh = load_gmsh()
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    # Never fall back to MeshAdapt on a failed face: it can loop forever.
    gmsh.option.setNumber("Mesh.AlgorithmSwitchOnFailure", 0)
    lost = defaultdict(float)      # true mid-surface removed, by stage
    wrong = defaultdict(float)     # off-truth MAT retained, by stage
    by_tree = defaultdict(lambda: [0.0, 0.0])
    per_case, summaries = [], []
    for case_dir in sorted(args.corpus.iterdir()):
        if not (case_dir / f"{case_dir.name}.json").is_file():
            continue
        if not fnmatch.fnmatch(case_dir.name, args.only):
            continue
        result = label_case(case_dir, args.runs / case_dir.name)
        if result is None:
            continue
        rows, summary = result
        summaries.append(summary)
        case_lost = case_wrong = 0.0
        for r in rows:
            # Area of truth removed, and of non-truth retained, by this branch.
            removed_truth = r["on_truth_area_t2"] * (1 - r["retained_fraction"])
            kept_wrong = (r["area_t2"] - r["on_truth_area_t2"]) * r["retained_fraction"]
            stage = r["removed_faces_by"] or r["deciding_stage"]
            if r["label"] != "reject" and removed_truth > 0:
                lost[stage] += removed_truth
                by_tree[r["tree_class"]][0] += removed_truth
                case_lost += removed_truth
            if r["label"] != "keep" and kept_wrong > 0:
                wrong[r["deciding_stage"]] += kept_wrong
                by_tree[r["tree_class"]][1] += kept_wrong
                case_wrong += kept_wrong
        per_case.append((case_dir.name, case_lost, case_wrong))
    gmsh.finalize()
    print(f"{len(per_case)} cases labeled")
    print("true mid-surface removed (t^2), by removing stage:")
    for k, v in sorted(lost.items(), key=lambda kv: -kv[1]):
        print(f"  {k:12s} {v:10.1f}")
    print("off-truth MAT retained (t^2), by deciding stage:")
    for k, v in sorted(wrong.items(), key=lambda kv: -kv[1]):
        print(f"  {k:12s} {v:10.1f}")
    print("by tree class: removed truth / retained off-truth (t^2)")
    for k, (a, b) in sorted(by_tree.items()):
        print(f"  {k:12s} {a:10.1f} {b:10.1f}")
    print("coverage of the true mid-surface: reachable from the raw MAT / reached")
    print(f"  mean {np.mean([x['reachable'] for x in summaries]):.3f} / "
          f"{np.mean([x['reached'] for x in summaries]):.3f}")
    print("worst filtering losses (reachable not reached, t^2; final MAT off truth, t^2):")
    for x in sorted(summaries, key=lambda x: -(x["reachable_not_reached_t2"]
                                                + x["final_off_truth_t2"]))[:args.top]:
        print(f"  {x['case']:34s} {x['reachable_not_reached_t2']:9.1f} "
              f"{x['final_off_truth_t2']:9.1f}   reachable {x['reachable']:.3f} "
              f"reached {x['reached']:.3f}")
    with open(args.runs / "filtering_summary.csv", "w", newline="") as f:
        w = csv.DictWriter(f, list(summaries[0].keys()))
        w.writeheader()
        w.writerows(summaries)
    print(f"worst cases by branch labels (removed truth, retained off-truth, t^2):")
    for name, a, b in sorted(per_case, key=lambda x: -(x[1] + x[2]))[:args.top]:
        print(f"  {name:34s} {a:9.1f} {b:9.1f}")


if __name__ == "__main__":
    raise SystemExit(main())

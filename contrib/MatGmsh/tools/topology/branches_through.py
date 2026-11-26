#!/usr/bin/env python3
"""Where a branch of a mid-surface goes through another one.

Reads the MSH file written by "Save..." of the Midsurfacer window (one surface
per branch). An edge shared by two triangles of a branch goes through another
branch when its middle is within EPS of a triangle of that branch, more than
CLEAR inside it, with the two triangles on opposite sides of it by more than
CLEAR. An extended branch must stop on the sheets it meets: its edges along
them have one triangle, and nothing is reported. Prints, per pair of surfaces,
the number and the total length of the edges found.

  python3 branches_through.py MESH.msh [EPS [CLEAR]]     (defaults 1e-6, 0.02)

Needs numpy, scipy and the Gmsh Python module.
"""
import sys
import gmsh, numpy as np
from scipy.spatial import cKDTree
msh = sys.argv[1]
eps = float(sys.argv[2]) if len(sys.argv) > 2 else 1e-6
clear = float(sys.argv[3]) if len(sys.argv) > 3 else 0.02
gmsh.initialize(); gmsh.option.setNumber("General.Terminal", 0)
gmsh.open(msh)
tags, xyz, _ = gmsh.model.mesh.getNodes()
pos = np.zeros((int(tags.max()) + 1, 3)); pos[tags.astype(int)] = xyz.reshape(-1, 3)
tri, branch = [], []
for dim, tag in gmsh.model.getEntities(2):
    types, _, nodes = gmsh.model.mesh.getElements(dim, tag)
    for ty, nn in zip(types, nodes):
        if ty == 2:
            t = nn.astype(int).reshape(-1, 3); tri.append(t); branch.append(np.full(len(t), tag))
gmsh.finalize()
tri = np.vstack(tri); branch = np.concatenate(branch)
P = pos[tri]; cen = P.mean(axis=1); rad = np.linalg.norm(P - cen[:, None, :], axis=2).max(axis=1)
# interior edges of a branch: two triangles of the same branch, with their opposite vertices
e = np.vstack([tri[:, [0, 1]], tri[:, [1, 2]], tri[:, [2, 0]]]); opp = np.concatenate([tri[:, 2], tri[:, 0], tri[:, 1]]); eb = np.tile(branch, 3)
es = np.sort(e, axis=1); order = np.lexsort((eb, es[:, 1], es[:, 0])); es, opp, eb = es[order], opp[order], eb[order]
same = (es[1:] == es[:-1]).all(axis=1) & (eb[1:] == eb[:-1])
# keep the edges that appear exactly twice in their branch
run = np.r_[True, ~same]; ids = np.cumsum(run) - 1; n = np.bincount(ids)
twice = n[ids] == 2
first = np.flatnonzero(twice & run)
ea, ebr, o1, o2 = es[first], eb[first], opp[first], opp[first + 1]
mid = .5 * (pos[ea[:, 0]] + pos[ea[:, 1]]); length = np.linalg.norm(pos[ea[:, 1]] - pos[ea[:, 0]], axis=1)
sizes = {b: int((branch == b).sum()) for b in np.unique(branch)}
big = [b for b, c in sizes.items() if c > 50000]
total = {}
def test(edge_sel, tri_sel):
    if not len(edge_sel) or not len(tri_sel): return
    tree = cKDTree(cen[tri_sel]); r = rad[tri_sel].max() + eps
    for s in range(0, len(edge_sel), 2000):
        idx = edge_sel[s:s + 2000]
        near = tree.query_ball_point(mid[idx], r)
        ei = np.repeat(idx, [len(x) for x in near])
        if not len(ei): continue
        ti = tri_sel[np.concatenate([np.asarray(x, dtype=int) for x in near])]
        keep = branch[ti] != ebr[ei]; ei, ti = ei[keep], ti[keep]
        if not len(ei): continue
        v0, e1, e2 = P[ti, 0], P[ti, 1] - P[ti, 0], P[ti, 2] - P[ti, 0]
        nrm = np.cross(e1, e2); nl = np.linalg.norm(nrm, axis=1); ok = nl > 1e-12; nl[~ok] = 1; nrm = nrm / nl[:, None]
        w = mid[ei] - v0; dist = np.einsum('ij,ij->i', w, nrm)
        # barycentric coordinates of the projection
        d11 = np.einsum('ij,ij->i', e1, e1); d12 = np.einsum('ij,ij->i', e1, e2); d22 = np.einsum('ij,ij->i', e2, e2)
        w1 = np.einsum('ij,ij->i', w, e1); w2 = np.einsum('ij,ij->i', w, e2); den = d11 * d22 - d12 * d12; den[den == 0] = 1
        u = (d22 * w1 - d12 * w2) / den; v = (d11 * w2 - d12 * w1) / den
        size = np.sqrt(nl)
        inside = (u > clear / size) & (v > clear / size) & (u + v < 1 - clear / size)
        s1 = np.einsum('ij,ij->i', pos[o1[ei]] - v0, nrm); s2 = np.einsum('ij,ij->i', pos[o2[ei]] - v0, nrm)
        hit = ok & (np.abs(dist) <= eps) & inside & (s1 * s2 < 0) & (np.minimum(np.abs(s1), np.abs(s2)) > clear)
        seen = set()
        for i, j in zip(ei[hit], branch[ti[hit]]):
            if (i, j) in seen: continue
            seen.add((i, j)); c = total.setdefault((int(ebr[i]), int(j)), [0, 0.]); c[0] += 1; c[1] += length[i]
alltri = np.arange(len(tri))
small_edges = np.flatnonzero(~np.isin(ebr, big)); big_edges = np.flatnonzero(np.isin(ebr, big))
test(small_edges, alltri)
test(big_edges, np.flatnonzero(~np.isin(branch, big)))
print(msh.split('/')[-1], ":", len(tri), "triangles,", len(ea), "edges inside a branch; within", eps, "of another branch, clearance", clear)
if not total: print("  no branch goes through another one")
for (i, j), (c, l) in sorted(total.items()):
    print("  surface %d goes through surface %d along %d edges of total length %.2f" % (i, j, c, l))

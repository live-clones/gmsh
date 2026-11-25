#!/usr/bin/env python3
"""The exact mid faces of the face pairing joined to the projected MAT, as one mesh.

  python3 tools/facepair/hybrid.py <mat.msh> <mid.brep> <thickness> <out.msh> [--size h]

The walls come from the face pairing (mid.brep: CAD faces offset to half the
gap of their wall, exact, but stopping at the edges of their CAD faces); the
bends, junctions and fillets from the projected MAT, which runs through them.
The mid faces are meshed (size h, default t/2); the MAT triangles that lie on
a mid face (their nodes within a fraction of the thickness of it) are
removed; the nodes of the MAT along the cut are moved onto the nearest edge
of the mid faces, so that the two meet. The result is one mesh with two
groups of surfaces, "walls" (one surface per mid face) and "mat"; the two
are joined geometrically, not conformally (their nodes along the seams are
not shared).
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

import numpy as np
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[1] / "tests"))
from direct_midsurface_cases import load_gmsh  # noqa: E402

gmsh = load_gmsh()


def closest_on_triangles(p, a, b, c):
    """Closest points of the points p on the triangles (a, b, c), row by row
    (Ericson, Real-Time Collision Detection, 5.1.5)."""
    ab, ac, ap = b - a, c - a, p - a
    d1, d2 = np.einsum("ij,ij->i", ab, ap), np.einsum("ij,ij->i", ac, ap)
    bp = p - b
    d3, d4 = np.einsum("ij,ij->i", ab, bp), np.einsum("ij,ij->i", ac, bp)
    cp = p - c
    d5, d6 = np.einsum("ij,ij->i", ab, cp), np.einsum("ij,ij->i", ac, cp)
    va, vb, vc = d3 * d6 - d5 * d4, d5 * d2 - d1 * d6, d1 * d4 - d3 * d2
    with np.errstate(divide="ignore", invalid="ignore"):
        denom = 1.0 / (va + vb + vc)
        v, w = vb * denom, vc * denom
        out = a + ab * v[:, None] + ac * w[:, None]
        # Vertex and edge regions, from the last to the first, so that the
        # first that applies wins.
        bc_ = (va <= 0) & (d4 - d3 >= 0) & (d5 - d6 >= 0)
        t = (d4 - d3) / ((d4 - d3) + (d5 - d6))
        out[bc_] = (b + (c - b) * t[:, None])[bc_]
        ac_ = (vb <= 0) & (d2 >= 0) & (d6 <= 0)
        t = d2 / (d2 - d6)
        out[ac_] = (a + ac * t[:, None])[ac_]
        ab_ = (vc <= 0) & (d1 >= 0) & (d3 <= 0)
        t = d1 / (d1 - d3)
        out[ab_] = (a + ab * t[:, None])[ab_]
    out[(d6 >= 0) & (d5 <= d6)] = c[(d6 >= 0) & (d5 <= d6)]
    out[(d3 >= 0) & (d4 <= d3)] = b[(d3 >= 0) & (d4 <= d3)]
    out[(d1 <= 0) & (d2 <= 0)] = a[(d1 <= 0) & (d2 <= 0)]
    return out


def distance_to_mesh(points, xyz, tri, k=12, which=False):
    """Distance from each point to a triangle mesh, and the closest point
    (among the k triangles with the nearest centroids); with which, also the
    triangle of the closest point."""
    tree = cKDTree(xyz[tri].mean(axis=1))
    k = min(k, len(tri))
    _, near = tree.query(points, k=k)
    near = near.reshape(len(points), k)
    best = np.full(len(points), np.inf)
    foot = np.zeros_like(points)
    owner = np.zeros(len(points), dtype=np.int64)
    for j in range(k):
        t = tri[near[:, j]]
        q = closest_on_triangles(points, xyz[t[:, 0]], xyz[t[:, 1]], xyz[t[:, 2]])
        d = np.linalg.norm(q - points, axis=1)
        better = d < best
        best[better], foot[better], owner[better] = d[better], q[better], near[better, j]
    return (best, foot, owner) if which else (best, foot)


def closest_on_segments(points, a, b, k=8):
    """Closest points of the points on a set of segments (a, b)."""
    tree = cKDTree(0.5 * (a + b))
    k = min(k, len(a))
    _, near = tree.query(points, k=k)
    near = near.reshape(len(points), k)
    best = np.full(len(points), np.inf)
    foot = np.zeros_like(points)
    for j in range(k):
        s, e = a[near[:, j]], b[near[:, j]]
        d = e - s
        t = np.clip(np.einsum("ij,ij->i", points - s, d) / np.maximum(np.einsum("ij,ij->i", d, d), 1e-300), 0, 1)
        q = s + d * t[:, None]
        dist = np.linalg.norm(q - points, axis=1)
        better = dist < best
        best[better], foot[better] = dist[better], q[better]
    return best, foot


def mesh_walls(brep: Path, size: float):
    """The mid faces meshed: nodes, and triangles with their face."""
    gmsh.model.add("walls")
    gmsh.model.occ.importShapes(str(brep))
    gmsh.model.occ.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", size)
    gmsh.option.setNumber("Mesh.MeshSizeMin", size / 20)
    gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 12)
    gmsh.option.setNumber("Mesh.Algorithm", 6)
    gmsh.option.setNumber("Mesh.AlgorithmSwitchOnFailure", 0)
    gmsh.option.setNumber("General.AbortOnError", 0)
    try:
        gmsh.model.mesh.generate(2)
    except Exception as e:  # noqa: BLE001
        print(f"meshing the mid faces: {e}")
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = coords.reshape(-1, 3)
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    tris, face_of = [], []
    for _, s in gmsh.model.getEntities(2):
        types, _, conn = gmsh.model.mesh.getElements(2, s)
        for ty, c in zip(types, conn):
            if ty == 2:
                t = index[c.astype(np.int64)].reshape(-1, 3)
                tris.append(t)
                face_of.append(np.full(len(t), s))
    gmsh.model.remove()
    tri = np.vstack(tris) if tris else np.zeros((0, 3), dtype=np.int64)
    return xyz, tri, np.concatenate(face_of) if face_of else np.zeros(0, int)


def read_mat(msh: Path):
    gmsh.model.add("mat")
    gmsh.merge(str(msh))
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = coords.reshape(-1, 3)
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    tris = []
    for _, s in gmsh.model.getEntities(2):
        types, _, conn = gmsh.model.mesh.getElements(2, s)
        for ty, c in zip(types, conn):
            if ty == 2:
                tris.append(index[c.astype(np.int64)].reshape(-1, 3))
    gmsh.model.remove()
    return xyz, np.vstack(tris)


def face_edges(wall_tri, wall_face):
    """The boundary edges of the mesh of every mid face: {face: (m, 2) nodes}."""
    out = {}
    for f in np.unique(wall_face):
        t = wall_tri[wall_face == f]
        e = np.sort(np.vstack([t[:, [0, 1]], t[:, [1, 2]], t[:, [2, 0]]]), axis=1)
        u, count = np.unique(e, axis=0, return_counts=True)
        out[int(f)] = u[count == 1]
    return out


def supported(wall_xyz, wall_tri, mat_xyz, mat_tri, t, on=0.25, reach=0.75):
    """The triangles of the mid faces to keep: all but those past a junction
    line of the MAT (off its sheets, within `reach` thicknesses of a junction
    line and nearer to it than to a free edge). A mid face keeps the outline
    of the CAD face it is offset from, which is not that of the mid-surface
    where the face beyond is inclined (a tube through a plate: the hole of
    the skin is not above the hole of the mid-surface). Past a free edge of
    the MAT, the face prolongs the mid-surface up to the material; along a
    bend, the MAT leaves the face but the face is right."""
    def unit(v):
        return v / np.maximum(np.linalg.norm(v, axis=1, keepdims=True), 1e-300)
    w = wall_xyz[wall_tri]
    centroid = w.mean(axis=1)
    d, _, owner = distance_to_mesh(centroid, mat_xyz, mat_tri, which=True)
    n_wall = unit(np.cross(w[:, 1] - w[:, 0], w[:, 2] - w[:, 0]))
    m = mat_xyz[mat_tri[owner]]
    n_mat = unit(np.cross(m[:, 1] - m[:, 0], m[:, 2] - m[:, 0]))
    ok = (d < on * t) & (np.abs(np.einsum("ij,ij->i", n_wall, n_mat)) > 0.9)
    rest = np.flatnonzero(~ok)
    if len(rest):
        e = np.sort(np.vstack([mat_tri[:, [0, 1]], mat_tri[:, [1, 2]], mat_tri[:, [2, 0]]]), axis=1)
        edge, count = np.unique(e, axis=0, return_counts=True)
        free, junction = edge[count == 1], edge[count >= 3]
        d_free = closest_on_segments(centroid[rest], mat_xyz[free[:, 0]], mat_xyz[free[:, 1]])[0] \
            if len(free) else np.full(len(rest), np.inf)
        d_junction = closest_on_segments(centroid[rest], mat_xyz[junction[:, 0]], mat_xyz[junction[:, 1]])[0] \
            if len(junction) else np.full(len(rest), np.inf)
        ok[rest] = ~((d_junction < reach * t) & (d_junction < d_free))
    return ok


def hybrid(mat_xyz, mat_tri, wall_xyz, wall_tri, wall_face, t, on=0.15, snap=1.0, over_band=0.5,
           inside_margin=0.1, island_area=2.0, edge_band=0.25):
    """The MAT without its triangles on the mid faces, its cut boundary moved
    onto the edges of the mid faces. Returns the new MAT nodes and triangles,
    and statistics."""
    used = np.unique(mat_tri)
    d = np.full(len(mat_xyz), np.inf)
    d[used], _ = distance_to_mesh(mat_xyz[used], wall_xyz, wall_tri)
    centroid = mat_xyz[mat_tri].mean(axis=1)
    dc, foot, owner = distance_to_mesh(centroid, wall_xyz, wall_tri, which=True)
    covered = (d[mat_tri] < on * t).all(axis=1) & (dc < on * t)
    # Also the triangles over a mid face, a little off it where the MAT
    # leaves the wall for a bend: nearly parallel to the face, within half a
    # thickness, and over its inside (the foot away from its edges).
    def unit(v):
        return v / np.maximum(np.linalg.norm(v, axis=1, keepdims=True), 1e-300)
    m = mat_xyz[mat_tri]
    n_mat = unit(np.cross(m[:, 1] - m[:, 0], m[:, 2] - m[:, 0]))
    w = wall_xyz[wall_tri[owner]]
    n_wall = unit(np.cross(w[:, 1] - w[:, 0], w[:, 2] - w[:, 0]))
    over = ~covered & (dc < over_band * t) & (np.abs(np.einsum("ij,ij->i", n_mat, n_wall)) > 0.9)
    edges = face_edges(wall_tri, wall_face)
    if over.any():
        # Away from the edges of the face it lies over (not of any face).
        idx = np.flatnonzero(over)
        face = wall_face[owner[idx]]
        for f in np.unique(face):
            sel = idx[face == f]
            seg = edges.get(int(f))
            if seg is None or not len(seg):
                continue
            edge, _ = closest_on_segments(foot[sel], wall_xyz[seg[:, 0]], wall_xyz[seg[:, 1]])
            over[sel[edge < inside_margin * t]] = False
    covered |= over
    # Islands: the small pieces of the MAT left that lie wholly over the mid
    # faces (bumps of the MAT, a little too rough for the tests above); not
    # the strips of the junctions, near the mid faces too but large.
    left = np.flatnonzero(~covered)
    if len(left):
        from scipy.sparse import coo_matrix
        from scipy.sparse.csgraph import connected_components
        rows = np.repeat(np.arange(len(left)), 3)
        graph = coo_matrix((np.ones(len(rows)), (rows, mat_tri[left].ravel())),
                           shape=(len(left), len(mat_xyz))).tocsr()
        _, component = connected_components(graph @ graph.T, directed=False)
        near = dc[left] < over_band * t
        whole = np.bincount(component, weights=near.astype(float)) == np.bincount(component)
        m = mat_xyz[mat_tri[left]]
        area = 0.5 * np.linalg.norm(np.cross(m[:, 1] - m[:, 0], m[:, 2] - m[:, 0]), axis=1)
        small = np.bincount(component, weights=area) < island_area * t * t
        islands = (whole & small)[component]
        covered[left[islands]] = True
        over[left[islands]] = True
    kept = mat_tri[~covered]
    # The cut: nodes of kept triangles that also belong to removed ones.
    cut = np.zeros(len(mat_xyz), dtype=bool)
    cut[np.unique(mat_tri[covered])] = True
    on_kept = np.zeros(len(mat_xyz), dtype=bool)
    on_kept[np.unique(kept)] = True
    cut &= on_kept
    xyz = mat_xyz.copy()
    moved = 0
    if cut.any():
        # A node of the cut goes onto the mid face that cut it: onto its edge
        # when near it, onto the face itself otherwise (under a rib, the face
        # of the plate runs on, and the foot of the rib meets it inside; the
        # edge nearest may be that of another face, the rib's, a thickness
        # away).
        nodes = np.flatnonzero(cut)
        dist, foot, owner = distance_to_mesh(xyz[nodes], wall_xyz, wall_tri, which=True)
        face = wall_face[owner]
        target = foot.copy()
        for f in np.unique(face):
            sel = np.flatnonzero(face == f)
            seg = edges.get(int(f))
            if seg is None or not len(seg):
                continue
            d, q = closest_on_segments(foot[sel], wall_xyz[seg[:, 0]], wall_xyz[seg[:, 1]])
            edge = d < edge_band * t
            target[sel[edge]] = q[edge]
        ok = dist < snap * t
        xyz[nodes[ok]] = target[ok]
        moved = int(ok.sum())
    # Kept triangles that the move flattened.
    a, b, c = xyz[kept[:, 0]], xyz[kept[:, 1]], xyz[kept[:, 2]]
    area = 0.5 * np.linalg.norm(np.cross(b - a, c - a), axis=1)
    kept = kept[area > 1e-12 * t * t]
    return xyz, kept, dict(removed=int(covered.sum()), over=int(over.sum()), kept=len(kept), cut=int(cut.sum()), moved=moved)


def write(out: Path, wall_xyz, wall_tri, wall_face, mat_xyz, mat_tri):
    gmsh.model.add("hybrid")
    offset = len(wall_xyz)
    groups = {"walls": [], "mat": []}
    tag = 1
    element = 1
    node_tag = np.arange(1, offset + len(mat_xyz) + 1)
    for face in np.unique(wall_face):
        sel = wall_tri[wall_face == face]
        nodes = np.unique(sel)
        gmsh.model.addDiscreteEntity(2, tag)
        gmsh.model.mesh.addNodes(2, tag, node_tag[nodes].tolist(), wall_xyz[nodes].ravel().tolist())
        gmsh.model.mesh.addElementsByType(tag, 2, list(range(element, element + len(sel))),
                                          node_tag[sel].ravel().tolist())
        element += len(sel)
        groups["walls"].append(tag)
        tag += 1
    if len(mat_tri):
        nodes = np.unique(mat_tri)
        gmsh.model.addDiscreteEntity(2, tag)
        gmsh.model.mesh.addNodes(2, tag, node_tag[offset + nodes].tolist(), mat_xyz[nodes].ravel().tolist())
        gmsh.model.mesh.addElementsByType(tag, 2, list(range(element, element + len(mat_tri))),
                                          node_tag[offset + mat_tri].ravel().tolist())
        groups["mat"].append(tag)
    for name, tags in groups.items():
        if tags:
            gmsh.model.setPhysicalName(2, gmsh.model.addPhysicalGroup(2, tags), name)
    gmsh.option.setNumber("Mesh.Binary", 1)
    gmsh.option.setNumber("Mesh.SaveAll", 1)
    gmsh.write(str(out))
    gmsh.model.remove()


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    parser.add_argument("mat", type=Path)
    parser.add_argument("brep", type=Path)
    parser.add_argument("thickness", type=float)
    parser.add_argument("out", type=Path)
    parser.add_argument("--size", type=float, default=0.0, help="mesh size of the mid faces (default t/2)")
    args = parser.parse_args()
    t = args.thickness
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    try:
        wall_xyz, wall_tri, wall_face = mesh_walls(args.brep, args.size or t / 2)
        mat_xyz, mat_tri = read_mat(args.mat)
        keep = supported(wall_xyz, wall_tri, mat_xyz, mat_tri, t)
        wall_tri, wall_face = wall_tri[keep], wall_face[keep]
        xyz, tri, stats = hybrid(mat_xyz, mat_tri, wall_xyz, wall_tri, wall_face, t)
        stats["unsupported"] = int((~keep).sum())
        write(args.out, wall_xyz, wall_tri, wall_face, xyz, tri)
    finally:
        gmsh.finalize()
    print(f"mid faces: {len(np.unique(wall_face))} ({len(wall_tri)} triangles, {stats['unsupported']} past a "
          f"junction of the MAT dropped); MAT: {stats['removed']} triangles "
          f"on the mid faces removed ({stats['over']} of them off it, over it), {stats['kept']} kept, {stats['moved']} of {stats['cut']} nodes of the cut "
          f"moved onto the edges -> {args.out}")


if __name__ == "__main__":
    main()

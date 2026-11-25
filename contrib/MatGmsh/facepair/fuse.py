#!/usr/bin/env python3
"""The walls of the face pairing and the extended MAT, arbitrated triangle by triangle, as one mesh.

  python3 tools/facepair/fuse.py <mat.msh> <walls.brep> <thickness> <out.msh> [--size h]

The walls (walls.brep: mid faces offset from the CAD faces, prolonged up to
the material, or the pieces of facepair_trim) have the exact geometry but
may run past the place where the mid-surface leaves them: past a junction,
over a transition (a dimple, a pocket, a bend) the CAD face does not stop
at, or at the wrong height on a face facing two thicknesses. The MAT has
the topology but a rougher geometry and holes. Every triangle of the walls
is judged by the MAT around it (within `reach` thicknesses):

  agree     the MAT passes within `on` thicknesses of it, parallel to it:
            the wall is kept (and replaces the MAT);
  medial    otherwise (a prolongation past the end of the MAT, a hole of
            the MAT, a flap past a bend, a wall at the wrong height): with
            --part, kept only at mid-thickness of the material (equal
            distances to the skins on both sides along its normal); without
            it, kept only when no MAT is within reach;
  disagree  the others are dropped.

Wall triangles past a junction line of the MAT are dropped too (hybrid.supported).

Small kept islands of a wall (below `island` t^2) are dropped. Then the
composition of hybrid.py: the MAT triangles on the kept walls are removed
and the nodes of the cut are moved onto the edges of the walls. The output
has the groups "walls" and "mat"; the seams are not conformal.
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

import numpy as np
from scipy.sparse import coo_matrix
from scipy.sparse.csgraph import connected_components
from scipy.spatial import cKDTree

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import hybrid as hy  # noqa: E402

gmsh = hy.gmsh


def unit(v):
    return v / np.maximum(np.linalg.norm(v, axis=1, keepdims=True), 1e-300)


def part_mesh(part, size):
    """The surface of the part (STEP) meshed: nodes and triangles."""
    gmsh.model.add("part")
    gmsh.model.occ.importShapes(str(part))
    gmsh.model.occ.synchronize()
    gmsh.option.setNumber("Mesh.MeshSizeMax", size)
    gmsh.option.setNumber("Mesh.MeshSizeMin", size / 20)
    try:
        gmsh.model.mesh.generate(2)
    except Exception as e:  # noqa: BLE001
        print(f"meshing the part: {e}")
    tags, coords, _ = gmsh.model.mesh.getNodes()
    xyz = coords.reshape(-1, 3)
    index = np.zeros(int(tags.max()) + 1, dtype=np.int64)
    index[tags.astype(np.int64)] = np.arange(len(tags))
    tri = [index[c.astype(np.int64)].reshape(-1, 3) for ty, c in zip(*gmsh.model.mesh.getElements(2)[::2]) if ty == 2]
    gmsh.model.remove()
    return xyz, np.vstack(tri)


def ray_hits(origins, directions, xyz, tri, reach):
    """Distance along each ray to the first triangle of the mesh (inf: none
    within reach); Moller-Trumbore on the triangles near the segment."""
    a, b, c = xyz[tri[:, 0]], xyz[tri[:, 1]], xyz[tri[:, 2]]
    centroid = (a + b + c) / 3
    radius = np.max(np.linalg.norm(np.stack([a, b, c], 1) - centroid[:, None], axis=2), axis=1)
    tree = cKDTree(centroid)
    out = np.full(len(origins), np.inf)
    for i, (o, d) in enumerate(zip(origins, directions)):
        mid = o + 0.5 * reach * d
        cand = np.array(tree.query_ball_point(mid, 0.5 * reach + radius.max()), dtype=np.int64)
        if not len(cand):
            continue
        e1, e2 = b[cand] - a[cand], c[cand] - a[cand]
        h = np.cross(d, e2)
        det = np.einsum("ij,ij->i", e1, h)
        ok = np.abs(det) > 1e-14
        inv = np.where(ok, 1.0 / np.where(ok, det, 1.0), 0.0)
        sv = o - a[cand]
        u = np.einsum("ij,ij->i", sv, h) * inv
        q = np.cross(sv, e1)
        v = (q @ d) * inv
        dist = np.einsum("ij,ij->i", e2, q) * inv
        hit = ok & (u >= -1e-9) & (v >= -1e-9) & (u + v <= 1 + 1e-9) & (dist > 1e-9) & (dist < reach)
        if hit.any():
            out[i] = dist[hit].min()
    return out


def medial(part, points, normals, t, reach, tolerance=0.2):
    """Whether each point is at mid-thickness of the part: inside it, and
    the skins along its normal, on both sides, at the same distance (within
    `tolerance` thicknesses). A wall offset by half the gap of a face that
    faces two thicknesses is not, over the thicker one."""
    xyz, tri = part_mesh(part, t / 2)
    up = ray_hits(points, normals, xyz, tri, reach)
    down = ray_hits(points, -normals, xyz, tri, reach)
    return np.isfinite(up) & np.isfinite(down) & (np.abs(up - down) < tolerance * t)


def arbitrate(wall_xyz, wall_tri, mat_xyz, mat_tri, t, on=0.1, reach=1.0, island=1.0, part=None):
    """Keep mask of the wall triangles, and counts of the three cases."""
    w = wall_xyz[wall_tri]
    centroid = w.mean(axis=1)
    n_wall = unit(np.cross(w[:, 1] - w[:, 0], w[:, 2] - w[:, 0]))
    # The nearest point of the MAT and the triangle it lies on.
    exact, _, owner = hy.distance_to_mesh(centroid, mat_xyz, mat_tri, which=True)
    m = mat_xyz[mat_tri[owner]]
    n_mat = unit(np.cross(m[:, 1] - m[:, 0], m[:, 2] - m[:, 0]))
    parallel = np.abs(np.einsum("ij,ij->i", n_wall, n_mat)) > 0.97
    agree = parallel & (exact < on * t)
    # The others (a prolongation past the end of the MAT, a hole of the
    # MAT, a flap past a bend or a junction, a wall at the wrong height):
    # kept only at mid-thickness of the material (with the part), or when
    # no MAT is within reach (without it).
    alone = ~agree if part is not None else exact > reach * t
    if part is not None and alone.any():
        idx = np.flatnonzero(alone)
        alone[idx] = medial(part, centroid[idx], n_wall[idx], t, reach=20 * t)
    keep = agree | alone
    # Small islands of kept triangles (noise of the judgement) are dropped.
    sel = np.flatnonzero(keep)
    if len(sel):
        rows = np.repeat(np.arange(len(sel)), 3)
        graph = coo_matrix((np.ones(len(rows)), (rows, wall_tri[sel].ravel())),
                           shape=(len(sel), len(wall_xyz))).tocsr()
        _, comp = connected_components(graph @ graph.T, directed=False)
        area = 0.5 * np.linalg.norm(np.cross(w[sel, 1] - w[sel, 0], w[sel, 2] - w[sel, 0]), axis=1)
        small = np.bincount(comp, weights=area) < island * t * t
        keep[sel[small[comp]]] = False
    return keep, dict(agree=int(agree.sum()), alone=int((alone & ~agree).sum()),
                      disagree=int((~agree & ~alone).sum()))


def gentle(mat_xyz, mat_tri, wall_xyz, wall_tri, t, on=0.05):
    """The MAT without the triangles a kept wall covers (their three nodes
    and their centroid within `on` thicknesses of it); nothing moves, the
    MAT and the walls overlap a little along the seams."""
    used = np.unique(mat_tri)
    d = np.full(len(mat_xyz), np.inf)
    d[used], _ = hy.distance_to_mesh(mat_xyz[used], wall_xyz, wall_tri)
    dc, _ = hy.distance_to_mesh(mat_xyz[mat_tri].mean(axis=1), wall_xyz, wall_tri)
    covered = (d[mat_tri] < on * t).all(axis=1) & (dc < on * t)
    kept = mat_tri[~covered]
    return mat_xyz, kept, dict(removed=int(covered.sum()), kept=len(kept), moved=0, cut=0, over=0)


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    parser.add_argument("mat", type=Path)
    parser.add_argument("brep", type=Path)
    parser.add_argument("thickness", type=float)
    parser.add_argument("out", type=Path)
    parser.add_argument("--size", type=float, default=0.0, help="mesh size of the walls (default t/4)")
    parser.add_argument("--on", type=float, default=0.1)
    parser.add_argument("--reach", type=float, default=1.0)
    parser.add_argument("--gentle", action="store_true",
                        help="remove only the MAT triangles a wall covers wholly, move no node")
    parser.add_argument("--part", type=Path, help="the part (STEP): a wall with no MAT around must lie inside it")
    args = parser.parse_args()
    t = args.thickness
    gmsh.initialize(["-noenv"], readConfigFiles=False)
    gmsh.option.setNumber("General.Terminal", 0)
    try:
        try:
            wall_xyz, wall_tri, wall_face = hy.mesh_walls(args.brep, args.size or t / 4)
        except Exception as e:  # noqa: BLE001
            # OCC cannot always fix the wires of trimmed pieces: without.
            print(f"walls: {e}; again without the OCC fixes")
            gmsh.model.remove()
            gmsh.option.setNumber("Geometry.OCCAutoFix", 0)
            wall_xyz, wall_tri, wall_face = hy.mesh_walls(args.brep, args.size or t / 4)
        mat_xyz, mat_tri = hy.read_mat(args.mat)
        keep, judged = arbitrate(wall_xyz, wall_tri, mat_xyz, mat_tri, t, on=args.on, reach=args.reach,
                                 part=args.part)
        # Past a junction line of the MAT, a wall in the plane of its own
        # sheet still agrees: hybrid.supported drops it.
        keep &= hy.supported(wall_xyz, wall_tri, mat_xyz, mat_tri, t)
        wall_tri, wall_face = wall_tri[keep], wall_face[keep]
        if len(wall_tri) and args.gentle:
            xyz, tri, stats = gentle(mat_xyz, mat_tri, wall_xyz, wall_tri, t)
        elif len(wall_tri):
            xyz, tri, stats = hy.hybrid(mat_xyz, mat_tri, wall_xyz, wall_tri, wall_face, t)
        else:
            xyz, tri, stats = mat_xyz, mat_tri, dict(removed=0, kept=len(mat_tri), moved=0, cut=0, over=0)
        hy.write(args.out, wall_xyz, wall_tri, wall_face, xyz, tri)
    finally:
        gmsh.finalize()
    print(f"walls: {judged['agree']} triangles agree with the MAT, {judged['alone']} at mid-thickness, "
          f"{judged['disagree']} disagree (dropped), {len(wall_tri)} kept; MAT: {stats['removed']} triangles "
          f"on the walls removed, {stats['kept']} kept, {stats['moved']} of {stats['cut']} nodes of the cut "
          f"moved -> {args.out}")


if __name__ == "__main__":
    main()

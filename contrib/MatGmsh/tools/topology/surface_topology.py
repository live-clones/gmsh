#!/usr/bin/env python3
"""Topology of a filtered MAT and of the exact mid-surface, by the same code.

Both are triangle meshes with indexed vertices (the MAT: filtered.msh of
gmshMat; the truth: <case>_midsurface.brep meshed by Gmsh). For each:

  components   connected components
  euler        vertices - edges + triangles
  sheets       sets of triangles connected through edges of two triangles
  junctions    connected sets of edges of three or more triangles
  boundaries   connected sets of edges of one triangle

with the area of each sheet and component in t^2 and the length of each
junction network and boundary in t. Nothing is repaired or filtered.

  python3 surface_topology.py --name CASE --mat filtered.msh --thickness T
          [--truth CASE_midsurface.brep] --output CASE.json

Needs numpy, scipy and pandas, and the Gmsh Python module for --truth.
"""
import argparse
import json
import sys
import time
from pathlib import Path

import numpy as np
from scipy.sparse import coo_matrix
from scipy.sparse.csgraph import connected_components


def read_msh2(path):
    """Nodes and triangles of an MSH 2.2 ASCII file written by gmshMat."""
    import pandas as pd
    with open(path, "rb") as f:
        head = [f.readline().strip() for _ in range(5)]
    if head[0] != b"$MeshFormat" or not head[1].startswith(b"2.2 0") or head[3] != b"$Nodes":
        raise RuntimeError(f"{path}: not an MSH 2.2 ASCII file")
    n = int(head[4])
    nodes = pd.read_csv(path, sep=" ", header=None, skiprows=5, nrows=n,
                        dtype={0: np.int64, 1: np.float64, 2: np.float64, 3: np.float64}).to_numpy()
    if not np.array_equal(nodes[:, 0], np.arange(1, n + 1)):
        raise RuntimeError(f"{path}: node tags are not 1..n")
    with open(path, "rb") as f:
        m = None
        for i, line in enumerate(f):
            if i == 5 + n + 2:
                m = int(line)
                break
            if i == 5 + n and line.strip() != b"$EndNodes":
                raise RuntimeError(f"{path}: $EndNodes expected")
    elements = pd.read_csv(path, sep=" ", header=None, skiprows=5 + n + 3, nrows=m, dtype=np.int64).to_numpy()
    if elements.shape[1] != 8 or (elements[:, 1] != 2).any() or (elements[:, 2] != 2).any():
        raise RuntimeError(f"{path}: elements are not all triangles with two tags")
    return nodes[:, 1:4].copy(), elements[:, 5:8] - 1


def graph_components(n, a, b):
    g = coo_matrix((np.ones(len(a), np.int8), (a, b)), shape=(n, n))
    return connected_components(g, directed=False)


def edge_sets(edges, length):
    """Lengths of the connected sets of the given edges, largest first."""
    if len(edges) == 0:
        return []
    nodes, inverse = np.unique(edges, return_inverse=True)
    inverse = inverse.reshape(-1, 2)
    k, label = graph_components(len(nodes), inverse[:, 0], inverse[:, 1])
    return sorted(np.bincount(label[inverse[:, 0]], weights=length, minlength=k).tolist(), reverse=True)


def stratify(xyz, tri, t, keep=60):
    tri = np.asarray(tri, np.int64)
    flat = (tri[:, 0] == tri[:, 1]) | (tri[:, 1] == tri[:, 2]) | (tri[:, 0] == tri[:, 2])
    repeated = int(flat.sum())
    tri = tri[~flat]
    m, n = len(tri), len(xyz)
    p, q, r = xyz[tri[:, 0]], xyz[tri[:, 1]], xyz[tri[:, 2]]
    area = 0.5 * np.linalg.norm(np.cross(q - p, r - p), axis=1) / t ** 2
    del p, q, r
    e = np.concatenate([tri[:, [0, 1]], tri[:, [1, 2]], tri[:, [2, 0]]])
    e.sort(axis=1)
    key = e[:, 0] * n + e[:, 1]
    order = np.argsort(key, kind="stable")
    key = key[order]
    first = np.r_[True, key[1:] != key[:-1]]
    start = np.flatnonzero(first)
    count = np.diff(np.r_[start, len(key)])
    del key, first
    owner = order % m  # triangle of each half-edge
    edges = e[order[start]]
    del e
    length = np.linalg.norm(xyz[edges[:, 0]] - xyz[edges[:, 1]], axis=1) / t

    used, compact = np.unique(tri, return_inverse=True)
    compact = compact.reshape(-1, 3)
    euler = int(len(used) - len(edges) + m)

    # Components: triangles connected through any shared edge or vertex.
    position = np.searchsorted(used, edges)
    ncomp, node_label = graph_components(len(used), position[:, 0], position[:, 1])
    comp_area = np.bincount(node_label[compact[:, 0]], weights=area, minlength=ncomp)

    # Sheets: triangles connected through edges of exactly two triangles.
    two = start[count == 2]
    nsheets, sheet = graph_components(m, owner[two], owner[two + 1])
    sheet_area = np.bincount(sheet, weights=area, minlength=nsheets)
    sheet_comp = np.zeros(nsheets, np.int64)
    sheet_comp[sheet] = node_label[compact[:, 0]]

    free = count == 1
    junction = count >= 3
    junction_sets = edge_sets(edges[junction], length[junction])
    boundary_sets = edge_sets(edges[free], length[free])
    valence = np.bincount(count)
    result = dict(
        vertices=int(len(used)), edges=int(len(edges)), triangles=int(m), repeated_node_triangles=repeated,
        euler=euler, components=int(ncomp), area=float(area.sum()),
        component_areas=sorted(comp_area.tolist(), reverse=True)[:keep],
        sheets=int(nsheets), sheet_areas=sorted(sheet_area.tolist(), reverse=True)[:keep],
        sheets_over_1=int((sheet_area >= 1.0).sum()), sheets_over_0p1=int((sheet_area >= 0.1).sum()),
        small_sheet_area=float(sheet_area[sheet_area < 1.0].sum()),
        junctions=len(junction_sets), junction_lengths=junction_sets[:keep],
        junctions_over_1=int(sum(x >= 1.0 for x in junction_sets)),
        junction_length=float(length[junction].sum()),
        boundaries=len(boundary_sets), boundary_lengths=boundary_sets[:keep],
        boundaries_over_1=int(sum(x >= 1.0 for x in boundary_sets)),
        boundary_length=float(length[free].sum()),
        edge_valence={str(v): int(c) for v, c in enumerate(valence) if c and v},
        sheets_per_component=sorted(np.bincount(sheet_comp, minlength=ncomp).tolist(), reverse=True)[:keep])
    return result


def truth_mesh(brep, h):
    import gmsh
    gmsh.initialize()
    try:
        gmsh.option.setNumber("General.Terminal", 0)
        gmsh.option.setNumber("General.NumThreads", 1)
        gmsh.model.add("truth")
        gmsh.model.occ.importShapes(str(brep))
        gmsh.model.occ.synchronize()
        faces = [s for _, s in gmsh.model.getEntities(2)]
        adjacency = {}
        for _, c in gmsh.model.getEntities(1):
            k = len(gmsh.model.getAdjacencies(1, c)[0])
            adjacency[k] = adjacency.get(k, 0) + 1
        gmsh.option.setNumber("Mesh.MeshSizeMin", h / 4)
        gmsh.option.setNumber("Mesh.MeshSizeMax", h)
        gmsh.option.setNumber("Mesh.MeshSizeFromCurvature", 12)
        gmsh.option.setNumber("Mesh.ElementOrder", 1)
        gmsh.model.mesh.generate(2)
        tags, xyz, _ = gmsh.model.mesh.getNodes()
        xyz = np.asarray(xyz).reshape(-1, 3)
        empty, chunks = [], []
        for s in faces:
            types, _, nodes = gmsh.model.mesh.getElements(2, s)
            got = [np.asarray(x, np.int64).reshape(-1, 3) for k, x in zip(types, nodes) if k == 2]
            if not got or not len(got[0]):
                empty.append(int(s))
            chunks.extend(got)
        tri = np.vstack(chunks)
        order = np.argsort(tags)
        tri = order[np.searchsorted(np.asarray(tags, np.int64)[order], tri)]
        # Nodes at the same place with different tags would mean curves that
        # are not shared between faces.
        used = np.unique(tri)
        scale = max(np.ptp(xyz[used], axis=0).max(), 1.0)
        cells = np.unique(np.round(xyz[used] / (1e-7 * scale)).astype(np.int64), axis=0)
        info = dict(faces=len(faces), curves_by_number_of_faces={str(k): v for k, v in sorted(adjacency.items())},
                    faces_without_mesh=empty, coincident_nodes=int(len(used) - len(cells)), mesh_size=h)
        return xyz, tri, info
    finally:
        gmsh.finalize()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--name", required=True)
    parser.add_argument("--mat", required=True)
    parser.add_argument("--thickness", type=float, required=True)
    parser.add_argument("--truth")
    parser.add_argument("--output", required=True)
    a = parser.parse_args()
    result = dict(name=a.name, thickness=a.thickness)
    clock = time.time()
    xyz, tri = read_msh2(a.mat)
    result["mat"] = stratify(xyz, tri, a.thickness)
    result["mat_seconds"] = time.time() - clock
    del xyz, tri
    if a.truth:
        clock = time.time()
        try:
            xyz, tri, info = truth_mesh(a.truth, a.thickness / 3)
            result["truth"] = stratify(xyz, tri, a.thickness)
            result["truth"].update(info)
        except Exception as error:  # reported, not hidden
            result["truth_error"] = f"{type(error).__name__}: {error}"
        result["truth_seconds"] = time.time() - clock
    Path(a.output).write_text(json.dumps(result, indent=1) + "\n")
    m, tr = result["mat"], result.get("truth")
    line = f"TOPO {a.name} mat c{m['components']} e{m['euler']} s{m['sheets']} j{m['junctions']} b{m['boundaries']}"
    if tr:
        line += f" | truth c{tr['components']} e{tr['euler']} s{tr['sheets']} j{tr['junctions']} b{tr['boundaries']}"
    print(line, flush=True)


if __name__ == "__main__":
    sys.exit(main())

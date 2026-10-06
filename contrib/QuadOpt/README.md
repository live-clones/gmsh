# QuadOpt

Quad-dominant surface meshing on top of a triangulation: recombination by
advancing fronts (Q-Morph) or by Blossom, then local optimization of the
triangle/quad mesh. One face at a time, on a half-edge complex.

## Flows

| Flow | How |
| --- | --- |
| PACK, Blossom, optimizer | `Mesh.Algorithm = 9`, `Mesh.PackRecombination = 0` (default) |
| PACK, Q-Morph, optimizer | `Mesh.Algorithm = 9`, `Mesh.PackRecombination = 1` |
| Any triangulation, Q-Morph, optimizer | `OptimizeMesh "QMorph"` or `gmsh.model.mesh.optimize("QMorph")` after a 2D mesh, typically Frontal-Delaunay |
| Optimizer alone | `OptimizeMesh "OptimizeQuads"` on a mixed mesh |

Q-Morph needs a pure triangulation; in a PACK flow, faces already made of
quads (patterns) are only optimized.

## Files

- `qoHalfEdge.h`: directed-edge map, vertex stars, cavities, transactional
  replacement.
- `qoFace.h/.cpp`: `FaceMesh`, shared by everything below: import, orientation,
  protected curves, CAD projection and normals, export; and the geometric
  measures (`quality`, `warping`, `alignment`).
- `qoOptimizer.cpp`: `FaceOptimizer`. A cavity is a small disk of cells; every
  re-meshing of it (with up to two interior points) is a candidate, accepted if
  a single energy decreases (cell shape, triangle count, valence after Kinney
  1997) and all cells are valid. Nodal moves are tangent-plane Winslow. A work
  queue schedules cavities; at the end, invalid or too warped quads are split
  along the diagonal closest to the CAD.
- `qoQMorph.cpp`: `FrontAdvance`, the fronts only (Owen et al. 1999, nine front
  types of Wang et al. 2025). It asks the optimizer to smooth and to re-mesh.
- `qoPack.cpp`: PACK settings scope and finalization.
- `intrinsicTriangulation.*`, `smallCavityWinslow.*`: used by PACK and by the
  nodal smoothing.

## Limits

- Boundary and embedded-curve meshes are never changed; triangles forced by
  the boundary discretization (corners, odd boundaries) remain.
- Not supported: high-order elements, partitioned meshes, periodic slaves
  (Q-Morph), faces with a non-orientable or non-manifold mesh (left unchanged
  with a warning).
- A quad warped above 25 degrees is split if the two triangles are acceptable.

## Tests

`benchmarks/quads` holds 20 cases, 19 of them with a `Flow` parameter selecting one
of the three first flows (see the comment in each `.geo`), and `audit.py`,
an independent check of the result against the CAD normal.

# QuadOpt

Local optimization of the triangle/quad surface meshes obtained by recombining
a triangulation (Blossom). One face at a time, on a half-edge complex.

## Flows

| Flow | How |
| --- | --- |
| PACK, Blossom, optimizer | `Mesh.Algorithm = 9`, `Mesh.RecombineAll = 1`, `Mesh.RecombinationAlgorithm = 1` |
| Optimizer alone | `OptimizeMesh "OptimizeQuads"` on a mixed mesh |

## Options

The algorithms take a `QuadOpt::Options` (`qoOptions.h`) in their signatures
and never read Gmsh's global context: `optimizeQuads`, `optimizeFace`,
`finishPackMesh`. Gmsh options are translated into it in one place
(`quadOptOptions()` in `Generator.cpp`); the intrinsic edge-length factor is a
parameter of `intrinsicDelaunayizePackedSurface`. Gmsh options in use:
`Mesh.PackCleanupMethod`, `Mesh.PackPatterns`,
`Mesh.PackIntrinsicEdgeLengthFactor` (and the PACK sampling options, which
belong to PACK).

## Files

- `qoHalfEdge.h`: directed-edge map, vertex stars, cavities, transactional
  replacement.
- `qoFace.h/.cpp`: `FaceMesh`, shared by everything below: import, orientation,
  protected curves, CAD projection and normals, export; and the geometric
  measures (`quality`, `shear`, `warping`, `alignment`).
- `qoOptimizer.cpp`: `FaceOptimizer`. A cavity is a small disk of cells; every
  re-meshing of it (with up to two interior points) is a candidate, accepted if
  a single energy decreases (cell shape, triangle count, valence after Kinney
  1997) and all cells are valid. The shape of a quad counts all its corners, not
  only the worst one: a quad sheared at 45 degrees costs about as much as a
  triangle. Where a node of the boundary has fewer cells than its angle
  asks for (a quad with two edges on the boundary), a row of quads along the
  boundary is a candidate too (Kinney 1997, Fig. 13). Nodal moves are
  tangent-plane Winslow. A work queue schedules cavities; at the end, invalid or
  too warped quads are split along the diagonal closest to the CAD.
- `qoPatch.h/.cpp`: search of patches with 3 to 6 corners (Bunin 2006) and the
  patterns that re-mesh them: the star (a grid for four corners) and the split,
  a straight chord cutting the patch into two stars (3 + 5 corners: a pair of
  singular vertices). A pattern must keep the cell count of the patch within
  25 %. The optimizer applies a pattern after the local rewrites have converged:
  new points from the transfinite guess, Winslow, kept only if the energy of the
  cavity decreases, undone otherwise. A cavity already seen in the same state
  (hash of its cells and positions) is not tried again.
  A face with no movable vertex (a thin strip, a small face) is only a polygon:
  its triangulation of least energy (dynamic programming over the loop) replaces
  the mesh if it is better and does not cut the CAD more.
- `qoPack.cpp`: PACK finalization (seams, patterns of simple faces, optimizer).
- `intrinsicTriangulation.*`, `smallCavityWinslow.*`: used by PACK and by the
  nodal smoothing.

## Limits

- Boundary and embedded-curve meshes are never changed; triangles forced by
  the boundary discretization (corners, odd boundaries) remain.
- Not supported: high-order elements, partitioned meshes, faces with a
  non-orientable or non-manifold mesh (left unchanged with a warning).
- A quad warped above 25 degrees is split if the two triangles are acceptable.

## Tests

`benchmarks/quads` holds ten cases that need no CAD file and are run by the
automatic tests (`ctest`). Each one meshes in its script (PACK, Blossom,
optimizer) and raises an error if there is no quadrangle, if the triangles
exceed 5 % of the quadrangles or if an element is invalid. Seven are analytic
shapes (`analytic_*`: plates with holes and a graded size, a drilled cylinder, a
sphere, a torus, a pipe tee, a notched box meshed with `Mesh.PackPatterns = 1`).
Three (`quadqs_fallback_*`) are scripts written for the quasi-structured quad
algorithm (`Mesh.Algorithm = 11`, `Mesh.Quadqs*` options), which has been
removed: they check that the algorithm falls back to PACK, that its options are
still accepted and that the mesh is the one of PACK selected explicitly.

`run_all.sh` meshes every case of the directory and `audit.py` checks the result
independently against the CAD normal and an element specification (angles,
warping, edge ratio, skew).

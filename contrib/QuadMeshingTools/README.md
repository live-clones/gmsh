# Content of contrib/QuadMeshingTools

Tools written by Maxence Reberol for the quasi-structured quad mesher, which
has been removed. What remains is what the packing of parallelograms
(`Mesh.Algorithm = 9`) uses, through `src/mesh/meshQuadQuasiStructured.{h,cpp}`:

- Heat-based cross/asterisk field solver, in qmtCrossField.h/cpp
- Conformal scaling solver (least-square, based on angle gradients), in
  qmtCrossField.h/cpp
- Size map tools (distance to curves, one-way smoothing), in qmtSizeMap.h/cpp
- Quad patterns for simple CAD faces (`Mesh.PackPatterns`), in
  qmtQuadCavityRemeshing.h/cpp
- Geometry smoothers (global UV Laplacian, Winslow/angle-based local kernel,
  DMO UV kernel), in qmtMeshGeometryOptimization.h/cpp
- Mesh utilities (patches, mesh diffs, background mesh queries), in
  qmtMeshUtils.h/cpp
- GeoLog: wrapper around Gmsh views for debugging, in geolog.h/cpp

Removed with the quasi-structured mesher: the disk quadrangulation remeshing
and its data, the cavity remeshing and the curve quantization.

# What the tools rely on elsewhere in Gmsh

- Eigen-based sparse solver, in src/solver/linearSystemEigen.{h,cpp}
- libOL octree, in src/common/libol1.{h,c} (MIT license), and the
  SurfaceProjector built on it, in src/mesh/meshOctreeLibOL.{h,cpp}
- Background mesh data structures, in src/mesh/BackgroundMesh.{h,cpp}
- Larger bounding boxes for the sampling of the guiding field, in
  src/post/OctreePost.cpp

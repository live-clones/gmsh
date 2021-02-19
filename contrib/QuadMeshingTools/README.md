# Quadqs behavior

### Usage:

- in GUI:

select "Quasi-structured quad (experimental)" in Mesh > 2D algorithm

- in command line:

gmsh -algo quadqs -2 <other options>

The mesh size is mainly controled by the -clscale option.

### General pipeline:

1. generate initial triangulation
2. compute cross field
3. compute size map 
4. apply curve quantization constraints (including transfinite)
5. generate curve meshes
6. generate transfinite quad meshes
7. generate unstructured quad-dominant meshes with algo pack (or fallback meshers)
8. midpoint subdivision
9. improve quad mesh topology with disk quadrangulation and cavity remeshing
10. geometry smoothing

### Shortcuts:

- If triangulation available: start at step 2
- If scaled cross field available: start at step 4
- If scalar size map available: import it in step 3
- If quad mesh available: start at step 9


# Content of contrib/QuadMeshingTools

- Heat-based cross/asterisk field solver in qmtCrossField.h/cpp
- Conformal scaling solver (least-square, for angles) in qmtCrossField.h/cpp
- Size map tools (dist to curves, one-way smoothing) in qmtSizeMap.h/cpp
- GeoLog: convenient wrapper around gmsh views for debugging, geolog.h/cpp
- Disk quadrangulation remeshing, qmtDiskQuadrangulationRemeshing.h/cpp
- Pattern-based cavity remeshing, qmtQuadCavityRemeshing.h/cpp
- Various geometry smoothers (global UV Laplacian, Winslow/Angled-based local kernel, DMO UV kernel), in qmtMeshGeometryOptimization.h/cpp


# Changes to gmsh

- Main files at Mesh/meshQuadQuasiStructured.h/cpp, to call the QuadMeshingTools functions
- Add Eigen-based sparse solver in Solver/linearSystemEigen.h/cpp
- Add robin_hood fast unordered_set/map hash maps, at Common/robin_hood.h, MIT license
- Add libOL octree for meshing library at Common/libol1.h/c, MIT license
- Add SurfaceProjector based on libOL octree, in Mesh/meshOctreeLibOL.h/cpp
- Add background mesh datastructures, in Mesh/BackgroundMesh.h/cpp
- contrib/domhex replaced by the version from quadMeshingTools branch (contains JF changes to algo pack)
- Post/OctreePost.cpp: use larger bounding boxes. Required for the background field sampling
- ALGO_2D_PACK_PRLGRMS_CSTR deprecated
- Add implicit conversion from SPoint3/SVector3 to std::array<double,3>
- Many Msg::Warning switch to Msg::Debug in CAD/Post projections
- Special case for quadqs in bbox sizing in Post/OctreePost.cpp, should find something better

# Todo

- Support for user-prescribed size map
- Add options in global context for better control
- Ensure robustness (quality > 0) of each step, as in quadMeshingTools branch
- Add raw quantization / transfinite on simple faces, as in quadMeshingTools branch
- Faster cavity remeshing implementation, as in quadMeshingTools branch



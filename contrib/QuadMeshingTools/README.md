# Quadqs behavior

### Usage:

- in GUI:

select "Quasi-structured quad (experimental)" in Mesh > 2D algorithm

- in command line:

gmsh -algo quadqs -2 <other options>

The mesh size is mainly controlled by the -clscale option.

### General pipeline:

1. generate initial triangulation
2. compute cross field
3. compute size map 
4. save as background mesh, background field, delete mesh
5. apply curve quantization constraints (including transfinite) (not re-implemented yet)
6. generate curve meshes
7. generate transfinite quad meshes (not re-implemented yet)
8. generate unstructured quad-dominant meshes with algo pack
9. midpoint subdivision
10. mesh simple CAD faces with patterns
11. improve quad mesh topology with disk quadrangulation remeshing
12. improve quad mesh topology with cavity remeshing
13. geometry smoothing (also applied during the previous steps)

### Shortcuts:

- If triangulation available: start at step 2
- If scaled cross field available: start at step 5
- If scalar size map available: import it in step 3
- If quad mesh available: start at step 10

# Content of contrib/QuadMeshingTools

- Heat-based cross/asterisk field solver in qmtCrossField.h/cpp
- Conformal scaling solver (least-square, based on angle gradients) in qmtCrossField.h/cpp
- Size map tools (dist to curves, one-way smoothing) in qmtSizeMap.h/cpp
- Disk quadrangulation remeshing, qmtDiskQuadrangulationRemeshing.h/cpp
- Pattern-based cavity remeshing, qmtQuadCavityRemeshing.h/cpp
- Various geometry smoothers (global UV Laplacian, Winslow/Angled-based local kernel, DMO UV kernel), in qmtMeshGeometryOptimization.h/cpp
- GeoLog: convenient wrapper around gmsh views for debugging, geolog.h/cpp


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
- Add MUMPS solver (with analysis / factorize)
- Split raw string literal for MSVC



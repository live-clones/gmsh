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
5. apply curve quantization constraints (using automatic transfinite for the moment)
6. generate curve meshes
7. generate transfinite quad meshes
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
- Curve quantization simple CAD faces to get regular meshes, in progress, not usable yet, in qmtCurveQuantization.h/cpp
- GeoLog: convenient wrapper around gmsh views for debugging, geolog.h/cpp


# Changes to gmsh

- Main files at src/mesh/meshQuadQuasiStructured.{h,cpp}, to call the QuadMeshingTools functions
- Add Eigen-based sparse solver in src/solver/linearSystemEigen.{h,cpp}
- Add robin_hood fast unordered_set/map hash maps, at src/common/robin_hood.h, MIT license
- Add libOL octree for meshing library at src/common/libol1.{h,c}, MIT license
- Add SurfaceProjector based on libOL octree, in src/mesh/meshOctreeLibOL.{h,cpp}
- Add background mesh datastructures, in src/mesh/BackgroundMesh.{h,cpp}
- contrib/domhex replaced by the version from quadMeshingTools branch (contains JF changes to algo pack)
- src/post/OctreePost.cpp: use larger bounding boxes. Required for the background field sampling
- ALGO_2D_PACK_PRLGRMS_CSTR deprecated
- Add implicit conversion from SPoint3/SVector3 to std::array<double,3>
- Many Msg::Warning switch to Msg::Debug in CAD/Post projections
- Special case for quadqs in bbox sizing in src/post/OctreePost.cpp, should find something better
- Add an option quadqsSizemapMethod in global context CTX::instance()->mesh
- Add a curve transfinite method (ge->meshAttributes.typeTransfinite = 4) to get vertex positioning via size map

# Todo

- Support for user-prescribed size map (requires quality metric taking size map into account)
- Add options in global context for better control
- Add MUMPS solver (with analysis / factorize)
- Better cavity initialization strategies (e.g. pathes between irregular vertices)
- Better CAD quantization (support for T-junctions, rings, etc)
- Filter anisotropy after cavity remeshing to avoid some distorted patches

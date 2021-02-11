# Quadqs behavior

Options:

- algo: quadqs

Pipeline:

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

Shortcuts:

- If triangulation available: start at step 2
- If scaled cross field available: start at step 4
- If scalar size map available: import it in step 3
- If quad mesh available: start at step 9


# Change log

- Add heat-based cross field solver in contrib/QuadMeshingTools/qmtCrossField.h/cpp
- Add background mesh datastructures in Mesh/BackgroundMesh.h/cpp
- Add Eigen-based sparse solver in Solver/linearSystemEigen.h/cpp
- New file to drive the quad meshing pipeline in Mesh/meshQuadQuasiStructured.h/cpp
- Add conformal scaling solver in contrib/QuadMeshingTools/qmtCrossField.h
- Add size map tools (dist to curves, one-way smoothing) in contrib/QuadMeshingTools/qmtSizeMap.h
- Add convenient wrapper around gmsh views for debugging (contrib/QuadMeshingTools/geolog.h/cpp)
- Add implicit conversion from SPoint3/SVector3 to std::array<double,3>, is it ok ?
- In Mesh2D(): use a switch from ALGO_2D_QUAD_QUASI_STRUCT to ALGO_2D_PACK_PRLGRMS
- packingOfParallelograms() replaced by the version in quadMeshingTools (Filler2D::pointInsertion2D removed)
- in Post/OctreePost.cpp: use larger bounding boxes. Required for the background field sampling
- change the xyz2uvw() function for triangles in Post/shapeFunctions.cpp. Required to sample triangles in 3D.
- ALGO_2D_PACK_PRLGRMS_CSTR deprecated
- ALGO_2D_PACK_PRLGRMS (algo pack) improved, works on surfaces now
- Add disk quadrangulation remeshing
- Add patch smoothing (UV laplacian + DMO)
- Add cavity remeshing (contrib/QuadMeshingTools/qmtQuadCavityRemeshing.h/cpp)

# Todo




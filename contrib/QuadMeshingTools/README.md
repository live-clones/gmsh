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

# Todo

- Conformal scaling in progress



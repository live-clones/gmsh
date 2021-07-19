# Background

This module re-implements the constrained 2d/3d untangler described in the paper:

    Foldover-free maps in 50 lines of code.
    Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., & Sokolov, D. (2021). 
    arXiv preprint arXiv:2102.03069.
    reference implementation: https://github.com/ssloy/invertible-maps

# State of the implementation

- The 2D untangler/smoother works on planar faces (with fixed vertices on curves).
  Quads are subdivided into four (overlapping) triangles for the smoothing.

- The 3D untangler/smoother works (with fixed vertices on curves and surfaces).
  Hexahedron are subdivided into 32 (overlapping) tetrahedra for the smoothing.

# Todo

- Write the decomposition of pyramids and prisms into tetrahedra to
  smooth hybrid hex-dominant meshes.

- Use the CAD parametrization for surface untangling/smoothing. Requires to change
  the formulation a bit, but definitely possible.

- Optimize all the curve/surface/volume vertices at the same time.

- For better performance on large models, only smooth regions around low-quality elements.

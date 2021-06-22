# Background

This module re-implements the constrained 2d/3d untangler described in the paper:

    Foldover-free maps in 50 lines of code.
    Garanzha, V., Kaporin, I., Kudryavtseva, L., Protais, F., Ray, N., & Sokolov, D. (2021). 
    arXiv preprint arXiv:2102.03069.

whose reference implementation is available at: https://github.com/ssloy/invertible-maps

The untangler is re-implemented here to avoid the dependencies of the reference
implementation and to use the LBFGS solver available in Gmsh (ALGLIB). The goal
is to have the same behavior.

# State of the implementation

- The 2D untangler/smoother works.

- The 3D untangler/smoother is still buggy and not usable.

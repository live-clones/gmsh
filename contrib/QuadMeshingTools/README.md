# QuadMeshingTools

## Features

### 1. Fast cross field computation on surfaces

- Discretization: one cross per edge (Crouzeix-Raviart), with vector representation (cos(4*theta),sin(4*theta))
- Boundary conditions: fixed crosses on mesh open boundary, on lines and on non-manifold surface edges
- Scheme: successive heat diffusion (ie (M+dt*L) u_i+1 = M u_i) followed by cross projection (normalization of the vectors)
- WARNING: optimizations (one sparsity analysis, one factorization per time-step) are only done when using the MUMPS solver. 
See detailed algorithm.  Install and enable MUMPS for fast computations. 
- Main implementation in `qmt_cross_field.cpp`, linear system calls in `qmt_linalg_solver.cpp`, custom MUMPS interface (to call analysis and factorization) in `linearSystemMUMPS2.cpp`.
- Detailed algorithm:

    - assemble M^(-1)*K (Crouzeix-Raviat coefficients)
    - sparsity analysis of M^(-1)*K  (if MUMPS)
    - dt_init = 0.1 * bbox diagonal
    - dt_f = (2*edge_min)^2
    - for each step i:
      - dt = dt_init + (dt_f-dt_init) * i/(nbSteps-1)
      - update matrix to get (I/dt+M^(-1)*K) x_i = x_(i-1)/dt
      - factorize matrix (if MUMPS)
      - while dnorm_max > 1.e-3:
        - update rhs
        - solve linear system (if MUMPS: almost free as matrix factorized, else: full solver cost)
        - project crosses (i.e. normalize representation vectors)
        - dnorm_max = max(norm_crosses-previous_norm_crosses)


### 2. Quad mesh generation from quadrilateral patches

- Generate a block-structured quad mesh from a classified triangulation that contains only quadrilateral patches (i.e. 4 boundary curves)
- Implementation in `qmt_simplification.cpp`

### 3. Quad mesh topological simplification

- Simplification of quad structure via successive quad collapses
- Implementation in `qmt_simplification.cpp`

### 4. Quad mesh smoothing

- Smoothing of the quad mesh geometry with a finite difference discretization of the Winslow PDE
- Implementation in `qmt_smoothing.cpp`

## Remarks

- All the main methods are exposed in the single header `quad_meshing_tools.h`
- The mesh structures (QMesh and TMesh) are defined in `qmt_types.hpp`
- Communication with gmsh mainly via the C++ API, with direct access to gmsh for the linear algebra solver
- To link `gmsh` with the MPI-free version of `mumps` on ArchLinux (`mumps-seq-shared` package in AUR), use the following CMake
command: cmake .. -DCMAKE_CXX_FLAGS=-I/usr/include/mumps-seq-shared -DENABLE_MUMPS=YES -DSMUMPS_INC=/usr/include/mumps-seq-shared -DSMUMPS_INC=/usr/include/mumps-seq-shared -DCMUMPS_INC=/usr/include/mumps-seq-shared -DZMUMPS_INC=/usr/include/mumps-seq-shared -DDMUMPS_INC=/usr/include/mumps-seq-shared
- On Ubuntu, use the package `libmumps-seq-5.1.2` and adapt the CMake command

## Authors

- Maxence Reberol (UCLouvain, maxence.reberol@uclouvain.be)



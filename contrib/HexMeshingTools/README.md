# hexbl: all-hex boundary layer meshing

## Paper

    All-hexahedral boundary layer meshing, 2021
    Reberol. M, Verhetsel K., Henrotte F., Bommes D., Remacle J.F.

Links: [PDF](https://raw.githubusercontent.com/mxncr/mxncr.github.io/master/pdf/hexbl_2021.pdf),
[Supplemental with results](https://www.hextreme.eu/data/hexbl_supplemental.pdf)


## Usage

- in GUI:

  - generate the all-hex layer from a quad/quad-dominant mesh:

        select "Hexdom with All-Hex Boundary Layer" as "3D algorithm" in Options - Mesh

  - generate the quad mesh and the all-hex layer:

        select "Quasi-structured quad" as "2D algorithm" in Options - Mesh
        select "Hexdom with All-Hex Boundary Layer" as "3D algorithm" in Options - Mesh

- in command line:

  - generate the all-hex layer from a quad/quad-dominant mesh:

        ./gmsh quad_mesh.msh -algo hexbl -3

  - generate a quad mesh, then the all-hex layer:

        ./gmsh model.step -algo quadqs -algo hexbl -3

The mesh size is mainly controlled by the -clscale option.

## Dependencies

This module requires:

- the [Gecode](https://www.gecode.org/) library (MIT license) to solve the
(highly non-linear) integer problem which determines the topology of the all-hex layer.

  Gmsh must be compiled with the `HAVE_GECODE` option enabled.

  Warning: the Gecode library is not included in the gmsh sources and must be installed independently.

  On ArchLinux, Gecode can be installed from the AUR community package repository:

      yay -S gecode

- the WinslowUntangler module, which is used to build the mesh geometry.

  Gmsh must be compiled with the `HAVE_WINSLOWUNTANGLER` option enabled.

CMake example:

    cmake .. -DENABLE_GECODE=YES -DENABLE_WINSLOWUNTANGLER=YES -DENABLE_HEXMESHINGTOOLS=YES



## Meshing pipeline

- Input: 
  - quad or quad-dominant mesh 
  - must be valid: watertight, positive jacobians and no self-intersections

- Output: 
  - hex-tet mesh with all-hex boundary layer and interior tet mesh
  - the volume mesh matches the midpoint subdivision of the input surface mesh

- Pipeline:
  - compute an initial tet mesh matching the input surface mesh
  - compute the ideal hexahedral valences at boundary edges
  - solve the global integer problem to find boundary layer topology (see paper)
  - optimize the all-hex layer geometry (with winslow untangling and anisotropic target shapes)
  - tet mesh the remaining volume 
    - if interior quad mesh (after hex-layer) have no self-intersections: call constrained tet mesher (HXT3D)
    - else: generate a tet mesh with topological padding. Topologically robust but will result in inverted tetrahedra



## TODO list

- Fill the interior volume (full tet mesh for the moment) with high-quality
  (frame-field guided ?) hex-dominant mesh

- To deal with tangled hexahedra (if any): smooth the input surface mesh (no
  longer respecting the CAD) or subdivide hexahedra into other element types




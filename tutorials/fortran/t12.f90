! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 12
!
!  Cross-patch meshing with compounds
!
! ------------------------------------------------------------------------------

! "Compound" meshing constraints allow to generate meshes across surface
! boundaries, which can be useful e.g. for imported CAD models (e.g. STEP) with
! undesired small features.

! When a `setCompound()' meshing constraint is given, at mesh generation time
! Gmsh
!  1. meshes the underlying elementary geometrical entities, individually
!  2. creates a discrete entity that combines all the individual meshes
!  3. computes a discrete parametrization (i.e. a piece-wise linear mapping)
!     on this discrete entity
!  4. meshes the discrete entity using this discrete parametrization instead
!     of the underlying geometrical description of the underlying elementary
!     entities making up the compound
!  5. optionally, reclassifies the mesh elements and nodes on the original
!     entities

! Step 3. above can only be performed if the mesh resulting from the
! combination of the individual meshes can be reparametrized, i.e. if the shape
! is "simple enough". If the shape is not amenable to reparametrization, you
! should create a full mesh of the geometry and first re-classify it to
! generate patches amenable to reparametrization (see `t13.f90').

! The mesh of the individual entities performed in Step 1. should usually be
! finer than the desired final mesh; this can be controlled with the
! `Mesh.CompoundMeshSizeFactor' option.

! The optional reclassification on the underlying elementary entities in Step
! 5. is governed by the `Mesh.CompoundClassify' option.

program t12

use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret
real(c_double), parameter :: lc = .1
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

ret = gmsh%model%geo%addPoint(0.0d0, 0.0d0, 0.0d0, lc, 1)
ret = gmsh%model%geo%addPoint(1.0d0, 0.0d0, 0.0d0, lc, 2)
ret = gmsh%model%geo%addPoint(1.0d0, 1.0d0, 0.5d0, lc, 3)
ret = gmsh%model%geo%addPoint(0.0d0, 1.0d0, 0.4d0, lc, 4)
ret = gmsh%model%geo%addPoint(0.3d0, 0.2d0, 0.0d0, lc, 5)
ret = gmsh%model%geo%addPoint(0.0d0, 0.01d0, 0.01d0, lc, 6)
ret = gmsh%model%geo%addPoint(0.0d0, 0.02d0, 0.02d0, lc, 7)
ret = gmsh%model%geo%addPoint(1.0d0, 0.05d0, 0.02d0, lc, 8)
ret = gmsh%model%geo%addPoint(1.0d0, 0.32d0, 0.02d0, lc, 9)

ret = gmsh%model%geo%addLine(1, 2, 1)
ret = gmsh%model%geo%addLine(2, 8, 2)
ret = gmsh%model%geo%addLine(8, 9, 3)
ret = gmsh%model%geo%addLine(9, 3, 4)
ret = gmsh%model%geo%addLine(3, 4, 5)
ret = gmsh%model%geo%addLine(4, 7, 6)
ret = gmsh%model%geo%addLine(7, 6, 7)
ret = gmsh%model%geo%addLine(6, 1, 8)
ret = gmsh%model%geo%addSpline([7, 5, 9], 9)
ret = gmsh%model%geo%addLine(6, 8, 10)

ret = gmsh%model%geo%addCurveLoop([5, 6, 9, 4], 11)
ret = gmsh%model%geo%addSurfaceFilling([11], 1)

ret = gmsh%model%geo%addCurveLoop([-9, 3, 10, 7], 13)
ret = gmsh%model%geo%addSurfaceFilling([13], 5)

ret = gmsh%model%geo%addCurveLoop([-10, 2, 1, 8], 15)
ret = gmsh%model%geo%addSurfaceFilling([15], 10)

call gmsh%model%geo%synchronize()

! Treat curves 2, 3 and 4 as a single curve when meshing (i.e. mesh across
! points 6 and 7)
call gmsh%model%mesh%setCompound(1, [2, 3, 4])

! Idem with curves 6, 7 and 8
call gmsh%model%mesh%setCompound(1, [6, 7, 8])

! Treat surfaces 1, 5 and 10 as a single surface when meshing (i.e. mesh across
! curves 9 and 10)
call gmsh%model%mesh%setCompound(2, [1, 5, 10])

call gmsh%model%mesh%generate(2)
call gmsh%write('t12.msh')

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t12

! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 7
!
!  Background meshes
!
! ------------------------------------------------------------------------------

program t7

use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret
real(c_double), parameter :: lc = 1e-2
character(len=GMSH_API_MAX_STR_LEN) :: cmd

! Mesh sizes can be specified very accurately by providing a background mesh,
! i.e., a post-processing view that contains the target mesh sizes.

call gmsh%initialize()

! Merge a list-based post-processing view containing the target mesh sizes:
call gmsh%merge('../t7_bgmesh.pos')  ! Only works on UNIX systems.

! If the post-processing view was model-based instead of list-based (i.e. if it
! was based on an actual mesh), we would need to create a new model to contain
! the geometry so that meshing it does not destroy the background mesh. It's not
! necessary here since the view is list-based, but it does no harm:
call gmsh%model%add("t7")

! Create a simple rectangular geometry:
ret = gmsh%model%geo%addPoint(.0d0, .0d0, 0d0, lc, 1)
ret = gmsh%model%geo%addPoint(.1d0, .0d0, 0d0, lc, 2)
ret = gmsh%model%geo%addPoint(.1d0, .3d0, 0d0, lc, 3)
ret = gmsh%model%geo%addPoint(.0d0, .3d0, 0d0, lc, 4)
ret = gmsh%model%geo%addLine(1, 2, 1)
ret = gmsh%model%geo%addLine(3, 2, 2)
ret = gmsh%model%geo%addLine(3, 4, 3)
ret = gmsh%model%geo%addLine(4, 1, 4)
ret = gmsh%model%geo%addCurveLoop([4, 1, -2, 3], 1)
ret = gmsh%model%geo%addPlaneSurface([1], 1)
call gmsh%model%geo%synchronize()

! Add the post-processing view as a new size field:
ret = gmsh%model%mesh%field%add("PostView")
call gmsh%model%mesh%field%setNumber(ret, "ViewIndex", 0d0)

! Apply the view as the current background mesh size field:
call gmsh%model%mesh%field%setAsBackgroundMesh(ret)

! In order to compute the mesh sizes from the background mesh only, and
! disregard any other size constraints, one can set:
call gmsh%option%setNumber("Mesh.MeshSizeExtendFromBoundary", 0d0)
call gmsh%option%setNumber("Mesh.MeshSizeFromPoints", 0d0)
call gmsh%option%setNumber("Mesh.MeshSizeFromCurvature", 0d0)

! See `t10.f90' for additional information: background meshes are actually a
! particular case of general "mesh size fields".

call gmsh%model%mesh%generate(2)
call gmsh%write("t7.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t7

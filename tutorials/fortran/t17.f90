! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 17
!
!  Anisotropic background mesh
!
! ------------------------------------------------------------------------------

! As seen in `t7.f90', mesh sizes can be specified very accurately by providing a
! background mesh, i.e., a post-processing view that contains the target mesh
! sizes.

! Here, the background mesh is represented as a metric tensor field defined on a
! square. One should use bamg as 2d mesh generator to enable anisotropic meshes
! in 2D.
program t17

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: bg_field, ret
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

call gmsh%model%add("t17")

! Create a square
ret = gmsh%model%occ%addRectangle(-2d0, -2d0, 0d0, 4d0, 4d0)
call gmsh%model%occ%synchronize()

! Merge a post-processing view containing the target anisotropic mesh sizes
call gmsh%merge('../t17_bgmesh.pos')

! Apply the view as the current background mesh
bg_field = gmsh%model%mesh%field%add("PostView")
call gmsh%model%mesh%field%setNumber(bg_field, "ViewIndex", 0d0)
call gmsh%model%mesh%field%setAsBackgroundMesh(bg_field)

! Use bamg
call gmsh%option%setNumber("Mesh.SmoothRatio", 3d0)
call gmsh%option%setNumber("Mesh.AnisoMax", 1000d0)
call gmsh%option%setNumber("Mesh.Algorithm", 7d0)

call gmsh%model%mesh%generate(2)
call gmsh%write("t17.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t17

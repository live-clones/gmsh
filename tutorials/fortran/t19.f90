! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 19
!
!  Thrusections, fillets, pipes, mesh size from curvature
!
! ------------------------------------------------------------------------------

! The OpenCASCADE geometry kernel supports several useful features for solid
! modelling.

program t19

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: ret, i, npts
integer(c_int), allocatable :: tags(:,:), out(:,:), tmp(:,:), e(:,:), p(:)
real(c_double) :: nturns, r, h, theta
character(len=GMSH_API_MAX_STR_LEN) :: cmd


call gmsh%initialize()

call gmsh%model%add("t19")

! Volumes can be constructed from (closed) curve loops thanks to the
! `addThruSections()' function
ret = gmsh%model%occ%addCircle(0d0, 0d0, 0d0, 0.5d0, 1)
ret = gmsh%model%occ%addCurveLoop([1], 1)
ret = gmsh%model%occ%addCircle(0.1d0, 0.05d0, 1d0, 0.1d0, 2)
ret = gmsh%model%occ%addCurveLoop([2], 2)
ret = gmsh%model%occ%addCircle(-0.1d0, -0.1d0, 2d0, 0.3d0, 3)
ret = gmsh%model%occ%addCurveLoop([3], 3)
call gmsh%model%occ%addThruSections([1, 2, 3], outdimtags=tags, tag=1)
call gmsh%model%occ%synchronize()
deallocate(tags)

! We can also force the creation of ruled surfaces:
ret = gmsh%model%occ%addCircle(2 + 0d0, 0d0, 0d0, 0.5d0, 11)
ret = gmsh%model%occ%addCurveLoop([11], 11)
ret = gmsh%model%occ%addCircle(2 + 0.1d0, 0.05d0, 1d0, 0.1d0, 12)
ret = gmsh%model%occ%addCurveLoop([12], 12)
ret = gmsh%model%occ%addCircle(2 - 0.1d0, -0.1d0, 2d0, 0.3d0, 13)
ret = gmsh%model%occ%addCurveLoop([13], 13)
call gmsh%model%occ%addThruSections([11, 12, 13], tags, 11, .true., .true.)
call gmsh%model%occ%synchronize()
deallocate(tags)

! We copy the first volume, and fillet all its edges:
call gmsh%model%occ%copy(reshape([3, 1], [2, 1]), out)
call gmsh%model%occ%translate(out, 4d0, 0d0, 0d0)
call gmsh%model%occ%synchronize()
call gmsh%model%getBoundary(out, tags);
call gmsh%model%getBoundary(tags, e, .false.)
call gmsh%model%occ%fillet([out(2, 1)], abs(e(2,:)), [0.1d0], tmp); deallocate(tmp)
call gmsh%model%occ%synchronize()

! OpenCASCADE also allows general extrusions along a smooth path. Let's first
! define a spline curve:
nturns = 1.
npts = 20
r = 1.
h = 1. * nturns
p = [(1000 + i, i = 0, npts)]
do i = 0, npts
    theta = i * 2 * M_PI * nturns / npts
    ret = gmsh%model%occ%addPoint(r * cos(theta), r * sin(theta), i * h / npts, 1d0, 1000 + i)
end do
ret = gmsh%model%occ%addSpline(p, 1000)

! A wire is like a curve loop, but open:
ret = gmsh%model%occ%addWire([1000], 1000)

! We define the shape we would like to extrude along the spline (a disk):
ret = gmsh%model%occ%addDisk(1d0, 0d0, 0d0, 0.2d0, 0.2d0, 1000)
call gmsh%model%occ%rotate(reshape([2, 1000], [2, 1]), 0d0, 0d0, 0d0, 1d0, 0d0, 0d0, M_PI / 2)

! We extrude the disk along the spline to create a pipe (other sweeping types
! can be specified; try e.g. 'Frenet' instead of 'DiscreteTrihedron'):
call gmsh%model%occ%addPipe(reshape([2, 1000], [2, 1]), 1000, out, 'DiscreteTrihedron')
deallocate(out)

! We delete the source surface, and increase the number of sub-edges for a
! nicer display of the geometry:
call gmsh%model%occ%remove(reshape([2, 1000], [2, 1]))
call gmsh%option%setNumber("Geometry.NumSubEdges", 1000d0)

call gmsh%model%occ%synchronize()

! We can activate the calculation of mesh element sizes based on curvature
! (here with a target of 20 elements per 2*Pi radians):
call gmsh%option%setNumber("Mesh.MeshSizeFromCurvature", 20d0)

! We can constraint the min and max element sizes to stay within reasonnable
! values (see `t10.f90' for more details):
call gmsh%option%setNumber("Mesh.MeshSizeMin", 0.001d0)
call gmsh%option%setNumber("Mesh.MeshSizeMax", 0.3d0)

call gmsh%model%mesh%generate(3)
call gmsh%write("t19.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t19

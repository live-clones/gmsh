! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 6
!
!  Transfinite meshes, deleting entities
!
! ------------------------------------------------------------------------------

program t6
use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret, i
integer(c_int) :: p1, p2, l1, l2, l3
real(c_double), parameter :: lc = 1e-2
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()
call gmsh%model%add("t6")

! Copied from `t1.py'...
ret = gmsh%model%geo%addPoint(0.0d0, 0.0d0, 0.0d0, lc, 1)
ret = gmsh%model%geo%addPoint(0.1d0, 0.0d0, 0.0d0, lc, 2)
ret = gmsh%model%geo%addPoint(0.1d0, 0.3d0, 0.0d0, lc, 3)
ret = gmsh%model%geo%addPoint(0.0d0, 0.3d0, 0.0d0, lc, 4)
ret = gmsh%model%geo%addLine(1, 2, 1)
ret = gmsh%model%geo%addLine(3, 2, 2)
ret = gmsh%model%geo%addLine(3, 4, 3)
ret = gmsh%model%geo%addLine(4, 1, 4)
ret = gmsh%model%geo%addCurveLoop([4, 1, -2, 3], 1)
ret = gmsh%model%geo%addPlaneSurface([1], 1)

! Delete the surface and the left line, and replace the line with 3 new ones:
call gmsh%model%geo%remove(reshape([2, 1, 1, 4], [2, 2]))

p1 = gmsh%model%geo%addPoint(-0.05d0, 0.05d0, 0.0d0, lc)
p2 = gmsh%model%geo%addPoint(-0.05d0, 0.10d0, 0.0d0, lc)
l1 = gmsh%model%geo%addLine(1, p1)
l2 = gmsh%model%geo%addLine(p1, p2)
l3 = gmsh%model%geo%addLine(p2, 4)

! Create surface
ret = gmsh%model%geo%addCurveLoop([2, -1, l1, l2, l3, -3], 2)
ret = gmsh%model%geo%addPlaneSurface([-2], 1)

! The `setTransfiniteCurve()' meshing constraints explicitly specifies the
! location of the nodes on the curve. For example, the following command forces
! 20 uniformly placed nodes on curve 2 (including the nodes on the two end
! points):
call gmsh%model%geo%mesh%setTransfiniteCurve(2, 20)

! Let's put 20 points total on combination of curves `l1', `l2' and `l3' (beware
! that the points `p1' and `p2' are shared by the curves, so we do not create 6
! + 6 + 10 = 22 nodes, but 20!)
call gmsh%model%geo%mesh%setTransfiniteCurve(l1, 6)
call gmsh%model%geo%mesh%setTransfiniteCurve(l2, 6)
call gmsh%model%geo%mesh%setTransfiniteCurve(l3, 10)

! Finally, we put 30 nodes following a geometric progression on curve 1
! (reversed) and on curve 3: Put 30 points following a geometric progression
call gmsh%model%geo%mesh%setTransfiniteCurve(1, 30, "Progression", -1.2d0)
call gmsh%model%geo%mesh%setTransfiniteCurve(3, 30, "Progression", +1.2d0)

! The `setTransfiniteSurface()' meshing constraint uses a transfinite
! interpolation algorithm in the parametric plane of the surface to connect the
! nodes on the boundary using a structured grid. If the surface has more than 4
! corner points, the corners of the transfinite interpolation have to be
! specified by hand:
call gmsh%model%geo%mesh%setTransfiniteSurface(1, "Left", [1, 2, 3, 4])

! To create quadrangles instead of triangles, one can use the `setRecombine'
! constraint:
call gmsh%model%geo%mesh%setRecombine(2, 1)

! When the surface has only 3 or 4 points on its boundary the list of corners
! can be omitted in the `setTransfiniteSurface()' call:
ret = gmsh%model%geo%addPoint(0.20d0, 0.2d0, 0.0d0, 1.0d0, 7)
ret = gmsh%model%geo%addPoint(0.20d0, 0.1d0, 0.0d0, 1.0d0, 8)
ret = gmsh%model%geo%addPoint(0.25d0, 0.2d0, 0.0d0, 1.0d0, 9)
ret = gmsh%model%geo%addPoint(0.30d0, 0.1d0, 0.0d0, 1.0d0, 10)
ret = gmsh%model%geo%addLine(8, 10, 10)
ret = gmsh%model%geo%addLine(10, 9, 11)
ret = gmsh%model%geo%addLine(9, 7, 12)
ret = gmsh%model%geo%addLine(7, 8, 13)
ret = gmsh%model%geo%addCurveLoop([10, 11, 12, 13], 14)
ret = gmsh%model%geo%addPlaneSurface([14], 15)
do i = 10, 13
    call gmsh%model%geo%mesh%setTransfiniteCurve(i, 10)
end do
call gmsh%model%geo%mesh%setTransfiniteSurface(15)

! The way triangles are generated can be controlled by specifying "Left",
! "Right" or "Alternate" in `setTransfiniteSurface()'. Try e.g.
!
! gmsh%model%geo%mesh%setTransfiniteSurface(15, "Alternate")

call gmsh%model%geo%synchronize()

! Finally we apply an elliptic smoother to the grid to have a more regular
! mesh:
call gmsh%option%setNumber("Mesh.Smoothing", 100d0)

call gmsh%model%mesh%generate(2)
call gmsh%write("t6.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()
call gmsh%finalize()

end program t6

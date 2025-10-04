! ---------------------------------------------------------------------------
!
!   Gmsh Fortran tutorial 2
!
!   Transformations, extruded geometries, volumes
!
! ---------------------------------------------------------------------------


program t2
use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: t(2,1), ss(2,8), r, i
real (c_double) :: lc
integer(c_int), allocatable :: ov(:,:), ov2(:,:)
character(len=GMSH_API_MAX_STR_LEN), allocatable :: argv(:)
real(c_double), allocatable :: xyz(:)

allocate(argv(command_argument_count() + 1))
do i = 0, size(argv) - 1
    call get_command_argument(i, argv(i+1))
    argv(i+1) = trim(argv(i+1))
end do
call gmsh%initialize(argv)

call gmsh%model%add("t2")

! Copied from `t1.f90'...
lc = 0.01
r = gmsh%model%geo%addPoint(0.0d0, 0.0d0, 0.0d0, lc, 1)
r = gmsh%model%geo%addPoint(0.1d0, 0.0d0, 0.0d0, lc, 2)
r = gmsh%model%geo%addPoint(0.1d0, 0.3d0, 0.0d0, lc, 3)
r = gmsh%model%geo%addPoint(0.0d0, 0.3d0, 0.0d0, lc, 4)
r = gmsh%model%geo%addLine(1, 2, 1)
r = gmsh%model%geo%addLine(3, 2, 2)
r = gmsh%model%geo%addLine(3, 4, 3)
r = gmsh%model%geo%addLine(4, 1, 4)
r = gmsh%model%geo%addCurveLoop([4, 1, -2, 3], 1)
r = gmsh%model%geo%addPlaneSurface([1], 1)
call gmsh%model%geo%synchronize()
r = gmsh%model%addPhysicalGroup(1, [1, 2, 4], 5)
r = gmsh%model%addPhysicalGroup(2, [1], -1, "My surface")

! We can then add new points and curves in the same way as we did in `t1.f90':
r = gmsh%model%geo%addPoint(0.0d0, 0.4d0, 0.0d0, lc, 5)
r = gmsh%model%geo%addLine(4, 5, 5)

t = reshape([0, 5], shape(t))
! But Gmsh also provides tools to transform (translate, rotate, etc.)
! elementary entities or copies of elementary entities.  Geometrical
! transformations take a vector of pairs of integers as first argument, which
! contains the list of entities, represented by (dimension, tag) pairs.  For
! example, the point 5 (dimension=0, tag=5) can be moved by 0.02 to the left
! (dx=-0.02, dy=0, dz=0) with
call gmsh%model%geo%translate(t, -0.02d0, 0.0d0, 0.0d0)

! And it can be further rotated by -Pi/4 around (0, 0.3, 0) (with the rotation
! along the z axis) with:
call gmsh%model%geo%rotate(t, 0.0d0, 0.3d0, 0.0d0, 0.0d0, 0.0d0, 1.0d0, -acos(1.0d0) / 4.0d0)

! Note that there are no units in Gmsh: coordinates are just numbers - it's
! up to the user to associate a meaning to them.

! Point 3 can be duplicated and translated by 0.05 along the y axis by using
! the `copy()' function, which takes a vector of (dim, tag) pairs as input,
! and returns another vector of (dim, tag) pairs:
call gmsh%model%geo%copy(reshape([0, 3], [2, 1]), ov)
call gmsh%model%geo%translate(ov, 0.0d0, 0.05d0, 0.0d0)

! The new point tag is available in ov[0].second, and can be used to create
! new lines:
r = gmsh%model%geo%addLine(3, ov(2,1), 7)
r = gmsh%model%geo%addLine(ov(2,1), 5, 8)
r = gmsh%model%geo%addCurveLoop([5, -8, -7, 3], 10)
r = gmsh%model%geo%addPlaneSurface([10], 11)

! In the same way, we can translate copies of the two surfaces 1 and 11 to
! the right with the following command:
deallocate(ov)
call gmsh%model%geo%copy(reshape([2, 1, 2, 11], [2, 2]), ov)
call gmsh%model%geo%translate(ov, 0.12d0, 0d0, 0d0)

print *, "New surfaces ", ov(2,1), " and ", ov(2,2)

! Volumes are the fourth type of elementary entities in Gmsh. In the same way
! one defines curve loops to build surfaces, one has to define surface loops
! (i.e. `shells') to build volumes. The following volume does not have holes
! and thus consists of a single surface loop:
r = gmsh%model%geo%addPoint(0.0d0, 0.30d0, 0.12d0, lc, 100)
r = gmsh%model%geo%addPoint(0.1d0, 0.30d0, 0.12d0, lc, 101)
r = gmsh%model%geo%addPoint(0.1d0, 0.35d0, 0.12d0, lc, 102)

! We would like to retrieve the coordinates of point 5 to create point 103,
! so we synchronize the model, and use `getValue()'
call gmsh%model%geo%synchronize()
call gmsh%model%getValue(0, 5, [real(c_double)::], xyz)
r = gmsh%model%geo%addPoint(xyz(1), xyz(2), 0.12d0, lc, 103)

r = gmsh%model%geo%addLine(4, 100, 110)
r = gmsh%model%geo%addLine(3, 101, 111)
r = gmsh%model%geo%addLine(6, 102, 112)
r = gmsh%model%geo%addLine(5, 103, 113)
r = gmsh%model%geo%addLine(103, 100, 114)
r = gmsh%model%geo%addLine(100, 101, 115)
r = gmsh%model%geo%addLine(101, 102, 116)
r = gmsh%model%geo%addLine(102, 103, 117)

r = gmsh%model%geo%addCurveLoop([115, -111, 3, 110], 118)
r = gmsh%model%geo%addPlaneSurface([118], 119)
r = gmsh%model%geo%addCurveLoop([111, 116, -112, -7], 120)
r = gmsh%model%geo%addPlaneSurface([120], 121)
r = gmsh%model%geo%addCurveLoop([112, 117, -113, -8], 122)
r = gmsh%model%geo%addPlaneSurface([122], 123)
r = gmsh%model%geo%addCurveLoop([114, -110, 5, 113], 124)
r = gmsh%model%geo%addPlaneSurface([124], 125)
r = gmsh%model%geo%addCurveLoop([115, 116, 117, 114], 126)
r = gmsh%model%geo%addPlaneSurface([126], 127)

r = gmsh%model%geo%addSurfaceLoop([127, 119, 121, 123, 125, 11], 128)
r = gmsh%model%geo%addVolume([128], 129)

! When a volume can be extruded from a surface, it is usually easier to use the
! `extrude()' function directly instead of creating all the points, curves and
! surfaces by hand. For example, the following command extrudes the surface 11
! along the z axis and automatically creates a new volume (as well as all the
! needed points, curves and surfaces). As expected, the function takes a vector
! of (dim, tag) pairs as input as well as the translation vector, and returns a
! vector of (dim, tag) pairs as output:
call gmsh%model%geo%extrude(reshape(ov(:,2), [2,1]), 0.0d0, 0.0d0, 0.12d0, ov2)

! Mesh sizes associated to geometrical points can be set by passing a vector of
! (dim, tag) pairs for the corresponding points:
ss = reshape([0, 103, 0, 105, 0, 109, 0, 102, 0, 28, 0, 24, 0, 6, 0, 5], shape(ss))
call gmsh%model%geo%mesh%setSize(ss, lc * 3)

! We finish by synchronizing the data from the built-in CAD kernel with the Gmsh
! model:
call gmsh%model%geo%synchronize()

! We group volumes 129 and 130 in a single physical group with tag `1' and
! name "The volume":
r = gmsh%model%addPhysicalGroup(3, [129, 130], 1, "The volume")

! call gmsh%model%setPhysicalName(3, 1, "The volume")
! We finally generate and save the mesh:
call gmsh%model%mesh%generate(3)
call gmsh%write("t2.msh")

! Note that, if the transformation tools are handy to create complex geometries,
! it is also sometimes useful to generate the `flat' geometry, with an explicit
! representation of all the elementary entities.
!
! This can be achieved by saving the model in the `Gmsh Unrolled GEO' format:
!
! call gmsh%write("t2.geo_unrolled");

! Launch the GUI to see the results. Providing an option file name (here
! "t2.opt") to the run() function will automatically load all the options and
! visibility information from that option file before running the GUI, and save
! all the options and visibility information to the file when the GUI is closed.
if (.not. any(argv == "-nopopup")) call gmsh%fltk%run("t2.opt")
call gmsh%finalize()
deallocate(ov, ov2, argv, xyz)

end program t2

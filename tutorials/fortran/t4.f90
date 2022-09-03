! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 4
!
!  Holes in surfaces, annotations, entity colors
!
! ------------------------------------------------------------------------------

program t4
use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
type(gmsh_model_geo_t) :: factory

integer(c_int) :: i, ret, v
real(c_double), parameter :: cm = 1e-02
real(c_double), parameter :: e1 = 4.5 * cm
real(c_double), parameter :: e2 = 6 * cm / 2
real(c_double), parameter :: e3 = 5 * cm / 2
real(c_double), parameter :: h1 = 5 * cm
real(c_double), parameter :: h2 = 10 * cm
real(c_double), parameter :: h3 = 5 * cm
real(c_double), parameter :: h4 = 2 * cm
real(c_double), parameter :: h5 = 4.5 * cm
real(c_double), parameter :: R1 = 1 * cm
real(c_double), parameter :: R2 = 1.5 * cm
real(c_double), parameter :: r = 1 * cm
real(c_double), parameter :: Lc1 = 0.01
real(c_double), parameter :: Lc2 = 0.003
real(c_double), parameter :: ccos = (-h5 * R1 + e2 * hypot(h5, hypot(e2, R1))) / (h5 * h5 + e2 * e2)
real(c_double), parameter :: ssin = sqrt(1 - ccos * ccos)

character(len=GMSH_API_MAX_STR_LEN), allocatable :: argv(:)

allocate(argv(command_argument_count() + 1))
do i = 0, size(argv) - 1
  call get_command_argument(i, argv(i+1))
  argv(i+1) = trim(argv(i+1))
end do

call gmsh%initialize(argv)
call gmsh%model%add("t4")

ret = factory%addPoint(-e1 - e2, 0d0, 0d0, Lc1, 1)
ret = factory%addPoint(-e1 - e2, h1, 0d0, Lc1, 2)
ret = factory%addPoint(-e3 - r, h1, 0d0, Lc2, 3)
ret = factory%addPoint(-e3 - r, h1 + r, 0d0, Lc2, 4)
ret = factory%addPoint(-e3, h1 + r, 0d0, Lc2, 5)
ret = factory%addPoint(-e3, h1 + h2, 0d0, Lc1, 6)
ret = factory%addPoint(e3, h1 + h2, 0d0, Lc1, 7)
ret = factory%addPoint(e3, h1 + r, 0d0, Lc2, 8)
ret = factory%addPoint(e3 + r, h1 + r, 0d0, Lc2, 9)
ret = factory%addPoint(e3 + r, h1, 0d0, Lc2, 10)
ret = factory%addPoint(e1 + e2, h1, 0d0, Lc1, 11)
ret = factory%addPoint(e1 + e2, 0d0, 0d0, Lc1, 12)
ret = factory%addPoint(e2, 0d0, 0d0, Lc1, 13)

ret = factory%addPoint(R1 / ssin, h5 + R1 * ccos, 0d0, Lc2, 14)
ret = factory%addPoint(0d0, h5, 0d0, Lc2, 15)
ret = factory%addPoint(-R1 / ssin, h5 + R1 * ccos, 0d0, Lc2, 16)
ret = factory%addPoint(-e2, 0d0, 0d0, Lc1, 17)

ret = factory%addPoint(-R2, h1 + h3, 0d0, Lc2, 18)
ret = factory%addPoint(-R2, h1 + h3 + h4, 0d0, Lc2, 19)
ret = factory%addPoint(0d0, h1 + h3 + h4, 0d0, Lc2, 20)
ret = factory%addPoint(R2, h1 + h3 + h4, 0d0, Lc2, 21)
ret = factory%addPoint(R2, h1 + h3, 0d0, Lc2, 22)
ret = factory%addPoint(0d0, h1 + h3, 0d0, Lc2, 23)

ret = factory%addPoint(0d0, h1 + h3 + h4 + R2, 0d0, Lc2, 24)
ret = factory%addPoint(0d0, h1 + h3 - R2, 0d0, Lc2, 25)

ret = factory%addLine(1, 17, 1)
ret = factory%addLine(17, 16, 2)

! Gmsh provides other curve primitives than straight lines: splines, B-splines,
! circle arcs, ellipse arcs, etc. Here we define a new circle arc, starting at
! point 14 and ending at point 16, with the circle's center being the point 15:
ret = factory%addCircleArc(14, 15, 16, 3)

! Note that, in Gmsh, circle arcs should always be smaller than Pi. The
! OpenCASCADE geometry kernel does not have this limitation.

! We can then define additional lines and circles, as well as a new surface:
ret = factory%addLine(14, 13, 4)
ret = factory%addLine(13, 12, 5)
ret = factory%addLine(12, 11, 6)
ret = factory%addLine(11, 10, 7)
ret = factory%addCircleArc(8, 9, 10, 8)
ret = factory%addLine(8, 7, 9)
ret = factory%addLine(7, 6, 10)
ret = factory%addLine(6, 5, 11)
ret = factory%addCircleArc(3, 4, 5, 12)
ret = factory%addLine(3, 2, 13)
ret = factory%addLine(2, 1, 14)
ret = factory%addLine(18, 19, 15)
ret = factory%addCircleArc(21, 20, 24, 16)
ret = factory%addCircleArc(24, 20, 19, 17)
ret = factory%addCircleArc(18, 23, 25, 18)
ret = factory%addCircleArc(25, 23, 22, 19)
ret = factory%addLine(21, 22, 20)

ret = factory%addCurveLoop([17, -15, 18, 19, -20, 16], 21)
ret = factory%addPlaneSurface([21], 22)

! But we still need to define the exterior surface. Since this surface has a
! hole, its definition now requires two curves loops:
ret = factory%addCurveLoop([11, -12, 13, 14, 1, 2, -3, 4, 5, 6, 7, -8, 9, 10], 23)
ret = factory%addPlaneSurface([23, 21], 24)

! As a general rule, if a surface has N holes, it is defined by N+1 curve loops:
! the first loop defines the exterior boundary; the other loops define the
! boundaries of the holes.

call factory%synchronize()

! Finally, we can add some comments by creating a post-processing view
! containing some strings:
v = gmsh%view%add("comments")

! Add a text string in window coordinates, 10 pixels from the left and 10 pixels
! from the bottom:
call gmsh%view%addListDataString(v, [10d0, -10d0], ["Created with Gmsh"])


! Add a text string in model coordinates centered at (X,Y,Z) = (0, 0.11, 0),
! with some style attributes:
call gmsh%view%addListDataString(v, [0d0, 0.11d0, 0d0], ["Hole"], &
                            ["Align    ", "Center   ", "Font     ", "Helvetica"])

! If a string starts with `file://', the rest is interpreted as an image
! file. For 3D annotations, the size in model coordinates can be specified after
! a `@' symbol in the form `widthxheight' (if one of `width' or `height' is
! zero, natural scaling is used; if both are zero, original image dimensions in
! pixels are used):
call gmsh%view%addListDataString(v, [0d0, 0.09d0, 0d0], ["file://../t4_image.png@0.01x0"], &
                            ["Align ", "Center"])

! The 3D orientation of the image can be specified by proving the direction
! of the bottom and left edge of the image in model space:
call gmsh%view%addListDataString(v, [-0.01d0, 0.09d0, 0d0], &
                            ["file://../t4_image.png@0.01x0,0,0,1,0,1,0"])

! The image can also be drawn in "billboard" mode, i.e. always parallel to
! the camera, by using the `!' symbol:
call gmsh%view%addListDataString(v, [0d0, 0.12d0, 0d0], &
                            ["file://../t4_image.png@0.01x0!"], &
                            ["Align ", "Center"])

! The size of 2D annotations is given directly in pixels:
call gmsh%view%addListDataString(v, [150d0, -7d0], ["file://../t4_image.png@20x0"])

! These annotations are handled by a list-based post-processing view. For
! large post-processing datasets, that contain actual field values defined on
! a mesh, you should use model-based post-processing views instead, which
! allow to efficiently store continuous or discontinuous scalar, vector and
! tensor fields, or arbitrary polynomial order.

! Views and geometrical entities can be made to respond to double-click
! events, here to print some messages to the console:
call gmsh%view%option%setString(v, "DoubleClickedCommand", &
                            "Printf('View[0] has been double-clicked!');")
call gmsh%option%setString(&
    "Geometry.DoubleClickedLineCommand", &
    "Printf('Curve %g has been double-clicked!', "//&
    "Geometry.DoubleClickedEntityTag);")

! We can also change the color of some entities:
call gmsh%model%setColor(reshape([2, 22], [2, 1]), 127, 127, 127)  ! Gray50
call gmsh%model%setColor(reshape([2, 24], [2, 1]), 160, 32, 240)  ! Purple
call gmsh%model%setColor(reshape([([1, i], i = 1, 15)], [2,14]), 255, 0, 0)  ! Red
call gmsh%model%setColor(reshape([([1, i], i = 15, 20)], [2,5]), 255, 255, 0)  ! Yellow

call gmsh%model%mesh%generate(2)

call gmsh%write("t4.msh")

! Launch the GUI to see the results:
if (.not. any(argv == "-nopopup")) call gmsh%fltk%run()

call gmsh%finalize()

end program t4

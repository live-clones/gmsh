! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 10
!
!  Mesh size fields
!
! ------------------------------------------------------------------------------

! In addition to specifying target mesh sizes at the points of the geometry (see
! `t1.f90') or using a background mesh (see `t7.f90'), you can use general mesh
! size "Fields".
program t10

use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret
real(c_double), parameter :: lc = .15
character(len=GMSH_API_MAX_STR_LEN) :: cmd, str

call gmsh%initialize()

call gmsh%model%add("t10")

! Let's create a simple rectangular geometry:
ret = gmsh%model%geo%addPoint(0.0d0, 0.0d0, 0d0, lc, 1)
ret = gmsh%model%geo%addPoint(1.0d0, 0.0d0, 0d0, lc, 2)
ret = gmsh%model%geo%addPoint(1.0d0, 1.0d0, 0d0, lc, 3)
ret = gmsh%model%geo%addPoint(0.0d0, 1.0d0, 0d0, lc, 4)
ret = gmsh%model%geo%addPoint(0.2d0, 0.5d0, 0d0, lc, 5)

ret = gmsh%model%geo%addLine(1, 2, 1)
ret = gmsh%model%geo%addLine(2, 3, 2)
ret = gmsh%model%geo%addLine(3, 4, 3)
ret = gmsh%model%geo%addLine(4, 1, 4)

ret = gmsh%model%geo%addCurveLoop([1, 2, 3, 4], 5)
ret = gmsh%model%geo%addPlaneSurface([5], 6)

call gmsh%model%geo%synchronize()

! Say we would like to obtain mesh elements with size lc/30 near curve 2 and
! point 5, and size lc elsewhere. To achieve this, we can use two fields:
! "Distance", and "Threshold". We first define a Distance field (`Field[1]') on
! points 5 and on curve 2. This field returns the distance to point 5 and to
! (100 equidistant points on) curve 2.
ret = gmsh%model%mesh%field%add("Distance", 1)
call gmsh%model%mesh%field%setNumbers(1, "PointsList", [5d0])
call gmsh%model%mesh%field%setNumbers(1, "CurvesList", [2d0])
call gmsh%model%mesh%field%setNumber(1, "Sampling", 100d0)

! We then define a `Threshold' field, which uses the return value of the
! `Distance' field 1 in order to define a simple change in element size
! depending on the computed distances
!
! SizeMax -                     /------------------
!                              /
!                             /
!                            /
! SizeMin -o----------------/
!          |                |    |
!        Point         DistMin  DistMax
ret = gmsh%model%mesh%field%add("Threshold", 2)
call gmsh%model%mesh%field%setNumber(2, "InField", 1d0)
call gmsh%model%mesh%field%setNumber(2, "SizeMin", lc / 30)
call gmsh%model%mesh%field%setNumber(2, "SizeMax", lc)
call gmsh%model%mesh%field%setNumber(2, "DistMin", 0.15d0)
call gmsh%model%mesh%field%setNumber(2, "DistMax", 0.5d0)

! Say we want to modulate the mesh element sizes using a mathematical function
! of the spatial coordinates. We can do this with the MathEval field:
ret = gmsh%model%mesh%field%add("MathEval", 3)
call gmsh%model%mesh%field%setString(3, "F", &
                                "cos(4*3.14*x) * sin(4*3.14*y) / 10 + 0.101")

! We could also combine MathEval with values coming from other fields. For
! example, let's define a `Distance' field around point 1
ret = gmsh%model%mesh%field%add("Distance", 4)
call gmsh%model%mesh%field%setNumbers(4, "PointsList", [1d0])

! We can then create a `MathEval' field with a function that depends on the
! return value of the `Distance' field 4, i.e., depending on the distance to
! point 1 (here using a cubic law, with minimum element size = lc / 100)
ret = gmsh%model%mesh%field%add("MathEval", 5)
write(str, '(f10.3)') lc / 100
call gmsh%model%mesh%field%setString(5, "F", "F4^3 + "//trim(str))

! We could also use a `Box' field to impose a step change in element sizes
! inside a box
ret = gmsh%model%mesh%field%add("Box", 6)
call gmsh%model%mesh%field%setNumber(6, "VIn", lc / 15)
call gmsh%model%mesh%field%setNumber(6, "VOut", lc)
call gmsh%model%mesh%field%setNumber(6, "XMin", 0.3d0)
call gmsh%model%mesh%field%setNumber(6, "XMax", 0.6d0)
call gmsh%model%mesh%field%setNumber(6, "YMin", 0.3d0)
call gmsh%model%mesh%field%setNumber(6, "YMax", 0.6d0)
call gmsh%model%mesh%field%setNumber(6, "Thickness", 0.3d0)

! Many other types of fields are available: see the reference manual for a
! complete list. You can also create fields directly in the graphical user
! interface by selecting `Define->Size fields' in the `Mesh' module.

! Let's use the minimum of all the fields as the background mesh size field:
ret = gmsh%model%mesh%field%add("Min", 7)
call gmsh%model%mesh%field%setNumbers(7, "FieldsList", [2d0, 3d0, 5d0, 6d0])

call gmsh%model%mesh%field%setAsBackgroundMesh(7)

! The API also allows to set a global mesh size callback, which is called each
! time the mesh size is queried
call gmsh%model%mesh%setSizeCallback(c_funloc(meshSizeCallback))

! To determine the size of mesh elements, Gmsh locally computes the minimum of
!
! 1) the size of the model bounding box;
! 2) if `Mesh.MeshSizeFromPoints' is set, the mesh size specified at geometrical
!    points;
! 3) if `Mesh.MeshSizeFromCurvature' is positive, the mesh size based on
!    curvature (the value specifying the number of elements per 2 * pi rad);
! 4) the background mesh field;
! 5) any per-entity mesh size constraint;
!
! The value can then be further modified by the mesh size callback, if any,
! before being constrained in the interval [`Mesh.MeshSizeMin',
! `Mesh.MeshSizeMax'] and multiplied by `Mesh.MeshSizeFactor'.  In addition,
! boundary mesh sizes are interpolated inside surfaces and/or volumes depending
! on the value of `Mesh.MeshSizeExtendFromBoundary' (which is set by default).
!
! When the element size is fully specified by a mesh size field (as it is in
! this example), it is thus often desirable to set

call gmsh%option%setNumber("Mesh.MeshSizeExtendFromBoundary", 0d0)
call gmsh%option%setNumber("Mesh.MeshSizeFromPoints", 0d0)
call gmsh%option%setNumber("Mesh.MeshSizeFromCurvature", 0d0)

! This will prevent over-refinement due to small mesh sizes on the boundary.

! Finally, while the default "Frontal-Delaunay" 2D meshing algorithm
! (Mesh.Algorithm = 6) usually leads to the highest quality meshes, the
! "Delaunay" algorithm (Mesh.Algorithm = 5) will handle complex mesh size fields
! better - in particular size fields with large element size gradients:

call gmsh%option%setNumber("Mesh.Algorithm", 5d0)

call gmsh%model%mesh%generate(2)
call gmsh%write("t10.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

contains

real(c_double) function meshSizeCallback(dim, tag, x, y, z, lc) result(val)
  integer(c_int), value, intent(in) :: dim, tag
  real(c_double), value, intent(in) :: x, y, z, lc
  val = min(lc, 0.02 * x + 0.01)
end function meshSizeCallback

end program t10

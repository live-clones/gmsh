! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 9
!
!  Plugins
!
! ------------------------------------------------------------------------------

program t9

! Plugins can be added to Gmsh in order to extend its capabilities. For example,
! post-processing plugins can modify views, or create new views based on
! previously loaded views. Several default plugins are statically linked with
! Gmsh, e.g. Isosurface, CutPlane, CutSphere, Skin, Transform or Smooth.
!
! Plugins can be controlled through the API functions with the `gmsh%plugin'
! prefix, or from the graphical interface (right click on the view button, then
! `Plugins').
use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret, v1, v2
integer(c_int), allocatable :: v(:)
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

! Let us for example include a three-dimensional scalar view:
call gmsh%merge('../view3.pos')
call gmsh%view%getTags(v)
if (size(v) /= 1) then
  call gmsh%logger%write("Wrong number of views!", "error")
  call gmsh%finalize()
  call abort()
endif

! We then set some options for the `Isosurface' plugin (which extracts an
! isosurface from a 3D scalar view), and run it:
call gmsh%plugin%setNumber("Isosurface", "Value", 0.67d0)
call gmsh%plugin%setNumber("Isosurface", "View", 0d0)
v1 = gmsh%plugin%run("Isosurface")

! We also set some options for the `CutPlane' plugin (which computes a section
! of a 3D view using the plane A*x+B*y+C*z+D=0), and then run it:
call gmsh%plugin%setNumber("CutPlane", "A", 0d0)
call gmsh%plugin%setNumber("CutPlane", "B", 0.2d0)
call gmsh%plugin%setNumber("CutPlane", "C", 1d0)
call gmsh%plugin%setNumber("CutPlane", "D", 0d0)
call gmsh%plugin%setNumber("CutPlane", "View", 0d0)
v2 = gmsh%plugin%run("CutPlane")

! Add a title (By convention, for window coordinates a value greater than 99999
! represents the center. We could also use `General.GraphicsWidth / 2', but that
! would only center the string for the current window size.):
call gmsh%plugin%setString("Annotate", "Text", "A nice title")
call gmsh%plugin%setNumber("Annotate", "X", 1.e5_c_double)
call gmsh%plugin%setNumber("Annotate", "Y", 50d0)
call gmsh%plugin%setString("Annotate", "Font", "Times-BoldItalic")
call gmsh%plugin%setNumber("Annotate", "FontSize", 28d0)
call gmsh%plugin%setString("Annotate", "Align", "Center")
call gmsh%plugin%setNumber("Annotate", "View", 0d0)
ret = gmsh%plugin%run("Annotate")

call gmsh%plugin%setString("Annotate", "Text", "(and a small subtitle)")
call gmsh%plugin%setNumber("Annotate", "Y", 70d0)
call gmsh%plugin%setString("Annotate", "Font", "Times-Roman")
call gmsh%plugin%setNumber("Annotate", "FontSize", 12d0)
ret = gmsh%plugin%run("Annotate")

! We finish by setting some options:
call gmsh%view%option%setNumber(v(1), "Light", 1d0)
call gmsh%view%option%setNumber(v(1), "IntervalsType", 1d0)
call gmsh%view%option%setNumber(v(1), "NbIso", 6d0)
call gmsh%view%option%setNumber(v(1), "SmoothNormals", 1d0)
call gmsh%view%option%setNumber(v1, "IntervalsType", 2d0)
call gmsh%view%option%setNumber(v2, "IntervalsType", 2d0)

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t9

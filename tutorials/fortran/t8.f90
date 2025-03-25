! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 8
!
!  Post-processing, image export and animations
!
! ------------------------------------------------------------------------------

program t8

! In addition to creating geometries and meshes, the Fortran API can also be used
! to manipulate post-processing datasets (called "views" in Gmsh).


use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret, num, num2, vv, t, frames
integer(c_int), allocatable :: v(:)
real(c_double) :: max_step, current_step, tmp, tmp_max
real(c_double), parameter :: lc = 1e-2
character(len=GMSH_API_MAX_STR_LEN) :: cmd, num2_str
integer(c_int), parameter :: white(3) = [255,255,255], black(3) = [0,0,0]

call gmsh%initialize()

! We first create a simple geometry
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

! We merge some post-processing views to work on
call gmsh%merge('../view1.pos')
call gmsh%merge('../view1.pos')
call gmsh%merge('../view4.pos')  ! contains 2 views inside

! Gmsh can read post-processing views in various formats. Here the `view1.pos'
! and `view4.pos' files are in the Gmsh "parsed" format, which is interpreted by
! the GEO script parser. The parsed format should only be used for relatively
! small datasets of course: for larger datasets using e.g. MSH files is much
! more efficient. Post-processing views can also be created directly from the
! Fortran API.

! We then set some general options:
call gmsh%option%setNumber("General.Trackball", 0d0)
call gmsh%option%setNumber("General.RotationX", 0d0)
call gmsh%option%setNumber("General.RotationY", 0d0)
call gmsh%option%setNumber("General.RotationZ", 0d0)

! Color options are special
! Setting a color option of "X.Y" actually sets the option "X.Color.Y"
! Sets "General.Color.Background", etc.
call gmsh%option%setColor("General.Background", white(1), white(2), white(3))
call gmsh%option%setColor("General.Foreground", black(1), black(2), black(3))
call gmsh%option%setColor("General.Text", black(1), black(2), black(3))

call gmsh%option%setNumber("General.Orthographic", 0d0)
call gmsh%option%setNumber("General.Axes", 0d0)
call gmsh%option%setNumber("General.SmallAxes", 0d0)

! Show the GUI:
call get_command(cmd)
! Launch the GUI to see the results:
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

! We also set some options for each post-processing view:

! If we were to follow the geo example blindly, we would read the number of
! views from the relevant option value, and use the gmsh%option%setNumber() and
! gmsh%option%setString() functions. A nicer way is to use gmsh%view%getTags()
! and to use the gmsh%view%option%setNumber() and gmsh%view%option%setString()
! functions.
call gmsh%view%getTags(v)
if (size(v) /= 4) then
    call gmsh%logger%write("Wrong number of views!", "error")
    call gmsh%finalize()
    call abort()
end if

! We set some options for each post-processing view:
call gmsh%view%option%setNumber(v(1), "IntervalsType", 2d0)
call gmsh%view%option%setNumber(v(1), "OffsetZ", 0.05d0)
call gmsh%view%option%setNumber(v(1), "RaiseZ", 0d0)
call gmsh%view%option%setNumber(v(1), "Light", 1d0)
call gmsh%view%option%setNumber(v(1), "ShowScale", 0d0)
call gmsh%view%option%setNumber(v(1), "SmoothNormals", 1d0)

call gmsh%view%option%setNumber(v(2), "IntervalsType", 1d0)
! Note that we can't yet set the ColorTable in API
call gmsh%view%option%setNumber(v(2), "NbIso", 10d0)
call gmsh%view%option%setNumber(v(2), "ShowScale", 0d0)

call gmsh%view%option%setString(v(3), "Name", "Test...")
call gmsh%view%option%setNumber(v(3), "Axes", 1d0)
call gmsh%view%option%setNumber(v(3), "IntervalsType", 2d0)
call gmsh%view%option%setNumber(v(3), "Type", 2d0)
call gmsh%view%option%setNumber(v(3), "AutoPosition", 0d0)
call gmsh%view%option%setNumber(v(3), "PositionX", 85d0)
call gmsh%view%option%setNumber(v(3), "PositionY", 50d0)
call gmsh%view%option%setNumber(v(3), "Width", 200d0)
call gmsh%view%option%setNumber(v(3), "Height", 130d0)

call gmsh%view%option%setNumber(v(4), "Visible", 0d0)

! You can save an MPEG movie directly by selecting `File->Export' in the
! GUI. Several predefined animations are setup, for looping on all the time
! steps in views, or for looping between views.

! But the API can be used to build much more complex animations, by changing
! options at run-time and re-rendering the graphics. Each frame can then be
! saved to disk as an image, and multiple frames can be encoded to form a
! movie. Below is an example of such a custom animation.

t = 0  ! Initial step

do num = 1, 3

  ! Set time step
  do vv = v(1), v(size(v))
      call gmsh%view%option%setNumber(vv, "TimeStep", real(t, c_double))
  end do

  call gmsh%view%option%getNumber(v(1), "TimeStep", current_step)
  call gmsh%view%option%getNumber(v(1), "NbTimeStep", max_step)
  max_step = max_step - 1
  if (current_step < max_step) then
    t = t + 1
  else
    t = 0
  end if

  call gmsh%view%option%getNumber(v(1), "RaiseZ", tmp)
  call gmsh%view%option%getNumber(v(1), "Max", tmp_max)
  call gmsh%view%option%setNumber(v(1), "RaiseZ", tmp +  0.01 / tmp_max * t)

  if (num == 3) then
    ! Resize the graphics when num == 3, to create 640x480 frames
    call gmsh%option%getNumber("General.MenuWidth", tmp)
    call gmsh%option%setNumber("General.GraphicsWidth", tmp + 640)
    call gmsh%option%setNumber("General.GraphicsHeight", 480d0)
  end if

  frames = 50
  do num2 = 1, frames-1
    ! Incrementally rotate the scene
    call gmsh%option%getNumber("General.RotationX", tmp)
    call gmsh%option%setNumber("General.RotationX", tmp + 10)
    call gmsh%option%getNumber("General.RotationX", tmp)
    call gmsh%option%setNumber("General.RotationY", tmp / 3)
    call gmsh%option%getNumber("General.RotationZ", tmp)
    call gmsh%option%setNumber("General.RotationZ", tmp + 0.1)

    ! Draw the scene
    call gmsh%graphics%draw()

    if (num == 3) then
      ! Uncomment the following lines to save each frame to an image file
      write(num2_str, *) num2
      ! call gmsh%write("t8-"//trim(num2)//".gif")
      ! call gmsh%write("t8-"//trim(num2)//".ppm")
      ! call gmsh%write("t8-"//trim(num2)//".jpg")
    end if
  end do
  if (num == 3) then
    ! Here we could make a system call to generate a movie. For example,
    ! with ffmeg:
    end if
end do

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t8

! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 3
!
!  Extruded meshes, ONELAB parameters, options
!
! ------------------------------------------------------------------------------
program t3
use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: i, r, g, b, a
real(c_double) :: lc
character(len=GMSH_API_MAX_STR_LEN), allocatable :: argv(:)

allocate(argv(command_argument_count() + 1))
do i = 0, size(argv) - 1
    call get_command_argument(i, argv(i+1))
    argv(i+1) = trim(argv(i+1))
end do
call gmsh%initialize(argv)

! Let us now change some options... Since all interactive options are accessible
! through the API, we can for example make point tags visible or redefine some
! colors:
call gmsh%option%setNumber("Geometry.PointNumbers", 1d0)
call gmsh%option%setColor("Geometry.Color.Points", 255, 165, 0)
call gmsh%option%setColor("General.Color.Text", 255, 255, 255)
call gmsh%option%setColor("Mesh.Color.Points", 255, 0, 0)

! Note that for conciseness "Color." can be omitted in color options:
call gmsh%option%getColor("Geometry.Points", r, g, b, a)
call gmsh%option%setColor("Geometry.Surfaces", r, g, b, a)

! We create a ONELAB parameter to define the angle of the twist. ONELAB
! parameters can be modified interactively in the GUI, and can be exchanged with
! other codes connected to the same ONELAB database. The database can be
! accessed through the Gmsh Fortran API using JSON-formatted strings (see
! https://gitlab.onelab.info/doc/tutorials/-/wikis/ONELAB-JSON-interface for
! more information):
call gmsh%onelab%set('['//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/Twisting angle",'//&
    '"values":[90],'//&
    '"min":0,'//&
    '"max":120,'//&
    '"step":1'//&
  '}'//&
']')

! Create the geometry and mesh it:
call createGeometryAndMesh()

if (.not. any(argv == "-nopopup")) then
call gmsh%fltk%initialize()
  do while (transfer(gmsh%fltk%isAvailable(), .true.) .and. checkForEvent())
    call gmsh%fltk%wait()
  end do
end if

! When the GUI is launched, you can use the `Help->Current Options and
! Workspace' menu to see the current values of all options. To save the options
! in a file, use `File->Export->Gmsh Options', or through the api:

! gmsh%write("t3.opt");

call gmsh%finalize()

contains
  subroutine createGeometryAndMesh()
    integer(c_int) :: ret
    real(c_double) :: h
    integer(c_int), allocatable :: ov(:,:)
    real(c_double), allocatable :: angles(:)
    ! Clear all models and create a new one
    call gmsh%clear()
    call gmsh%model%add("t3")

    ! Copied from `t1.f90'...
    lc = 1e-2
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
    ret = gmsh%model%addPhysicalGroup(1, [1, 2, 4], 5)
    ret = gmsh%model%addPhysicalGroup(2, [1], name="My surface")

    ! As in `t2.f90', we plan to perform an extrusion along the z axis.  But
    ! here, instead of only extruding the geometry, we also want to extrude the
    ! 2D mesh. This is done with the same `extrude()' function, but by
    ! specifying element 'Layers' (2 layers in this case, the first one with 8
    ! subdivisions and the second one with 2 subdivisions, both with a height of
    ! h/2). The number of elements for each layer and the (end) height of each
    ! layer are specified in two vectors:
    h = 0.1
    call gmsh%model%geo%extrude(reshape([2, 1], [2,1]), &
                                0d0, 0d0, h, &
                                outDimTags=ov, &
                                numElements=[8, 2], &
                                heights=[0.5d0, 1d0])

    ! The extrusion can also be performed with a rotation instead of a
    ! translation, and the resulting mesh can be recombined into prisms (we use
    ! only one layer here, with 7 subdivisions). All rotations are specified by
    ! an an axis point (-0.1, 0, 0.1), an axis direction (0, 1, 0), and a
    ! rotation angle (-Pi/2):
    deallocate(ov)
    call gmsh%model%geo%revolve(reshape([2, 28], [2,1]), &
                                -0.1d0, 0d0, 0.1d0, &
                                0d0, 1d0, 0d0, -M_PI / 2d0, &
                                outDimTags=ov, &
                                numElements=[7])

    ! Using the built-in geometry kernel, only rotations with angles < Pi are
    ! supported. To do a full turn, you will thus need to apply at least 3
    ! rotations. The OpenCASCADE geometry kernel does not have this limitation.

    ! A translation (-2 * h, 0, 0) and a rotation ((0, 0.15, 0.25), (1, 0, 0),
    ! angle * Pi / 180) can also be combined to form a "twist".  The last
    ! (optional) argument for the extrude() and twist() functions specifies
    ! whether the extruded mesh should be recombined or not. The `angle'
    ! parameter is retrieved from the ONELAB database (it can be set
    ! interactively in the GUI -- see below):
    deallocate(ov)
    call gmsh%onelab%getNumber('Parameters/Twisting angle', angles)
    call gmsh%model%geo%twist(reshape([2, 50], [2,1]), &
                              0d0, 0.15d0, 0.25d0, -2 * h, 0d0, 0d0, 1d0, 0d0, 0d0, &
                              angles(1) * (-M_PI / 180d0), &
                              outDimTags=ov, &
                              numElements=[10], &
                              heights=[real(c_double)::], &
                              recombine=.true.)

    call gmsh%model%geo%synchronize()

    ! All the extrusion functions return a vector of extruded entities: the
    ! "top" of the extruded surface (in `ov[0]'), the newly created volume (in
    ! `ov[1]') and the tags of the lateral surfaces (in `ov[2]', `ov[3]', ...).

    ! We can then define a new physical volume (with tag 101) to group all the
    ! elementary volumes:
    ret = gmsh%model%addPhysicalGroup(3, [1, 2, ov(2,2)], 101)

    call gmsh%model%mesh%generate(3)
    call gmsh%write("t3.msh")
  end subroutine createGeometryAndMesh

  ! Launch the GUI and handle the "check" event (recorded in the "ONELAB/Action"
  ! parameter) to recreate the geometry with a new twisting angle if necessary:
  logical function checkForEvent() result(val)
    character(len=GMSH_API_MAX_STR_LEN), allocatable :: action(:)

    val = .false.
    call gmsh%onelab%getString("ONELAB/Action", action)
    if (size(action) > 0) then
      if (trim(action(1)) == "check") then
        call gmsh%onelab%setString("ONELAB/Action", [c_null_char])
        call createGeometryAndMesh()
        call gmsh%graphics%draw()
      end if
    end if
    val = .true.
  end function checkForEvent

end program t3

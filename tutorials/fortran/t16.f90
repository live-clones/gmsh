! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 16
!
!  Constructive Solid Geometry, OpenCASCADE geometry kernel
!
! ------------------------------------------------------------------------------

! Instead of constructing a model in a bottom-up fashion with Gmsh's built-in
! geometry kernel, starting with version 3 Gmsh allows you to directly use
! alternative geometry kernels. Here we will use the OpenCASCADE kernel.

program t16

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: ret, p, t
integer(c_int), allocatable :: ov(:,:), ovv(:,:), holes(:,:)
integer(c_size_t), allocatable :: ovv_n(:)
real(c_double) :: x, y, z, r, lcar1, lcar2, lcar3, eps
character(len=GMSH_API_MAX_STR_LEN) :: cmd, str
character(len=GMSH_API_MAX_STR_LEN), allocatable :: log(:)

call gmsh%initialize()

call gmsh%model%add("t16")

! Let's build the same model as in `t5.f90', but using constructive solid
! geometry.

! We can log all messages for further processing with:
call gmsh%logger%start()

! We first create two cubes:
ret = gmsh%model%occ%addBox(0.0d0, 0.0d0, 0.0d0, 1.0d0, 1.0d0, 1.0d0, 1)
ret = gmsh%model%occ%addBox(0.0d0, 0.0d0, 0.0d0, 0.5d0, 0.5d0, 0.5d0, 2)

! We apply a boolean difference to create the "cube minus one eighth" shape:
call gmsh%model%occ%cut(objectDimTags=reshape([3, 1], [2, 1]), &
                        toolDimTags=reshape([3, 2], [2, 1]), &
                        outDimTags=ov, &
                        outDimTagsMap=ovv, &
                        outDimTagsMap_n=ovv_n, &
                        tag=3)
print*, "ovv_n =", ovv_n
print*, "ovv =", ovv
print*, "ov =", ov
! stop
deallocate(ov, ovv, ovv_n)

! Boolean operations with OpenCASCADE always create new entities. By default the
! extra arguments `removeObject' and `removeTool' in `cut()' are set to `True',
! which will delete the original entities.

! We then create the five spheres:
x = 0
y = 0.75
z = 0
r = 0.09
holes = reshape([(3, 3 + t, t = 1, 5)], [1, 10])
do t = 1, 5
    x = x + 0.166
    z = z + 0.166
    ret = gmsh%model%occ%addSphere(xc=x, yc=y, zc=z, radius=r, tag=(3 + t))
end do

! If we had wanted five empty holes we would have used `cut()' again. Here we
! want five spherical inclusions, whose mesh should be conformal with the mesh
! of the cube: we thus use `fragment()', which intersects all volumes in a
! conformal manner (without creating duplicate interfaces):
call gmsh%model%occ%fragment(objectDimTags=reshape([3, 3], [2, 1]), &
                             toolDimTags=holes, &
                             outDimTags=ov, &
                             outDimTagsMap=ovv, &
                             outDimTagsMap_n=ovv_n)

! ov contains all the generated entities of the same dimension as the input
! entities:
print*, "fragment produced volumes:"
print'(A,g0,A,g0,A)', ('(', ov(1,t), ',', ov(2,t), ')', t = 1, size(ov, 2))

! ovv contains the parent-child relationships for all the input entities:
print*, "before/after fragment relations:"

call gmsh%model%occ%synchronize()

! When the boolean operation leads to simple modifications of entities, and if
! one deletes the original entities, Gmsh tries to assign the same tag to the
! new entities. (This behavior is governed by the
! `Geometry.OCCBooleanPreserveNumbering' option.)

! Here the `Physical Volume' definitions can thus be made for the 5 spheres
! directly, as the five spheres (volumes 4, 5, 6, 7 and 8), which will be
! deleted by the fragment operations, will be recreated identically (albeit with
! new surfaces) with the same tags:
do t = 1, 5
    ret = gmsh%model%addPhysicalGroup(3, [3 + t], t)
end do

! The tag of the cube will change though, so we need to access it
! programmatically:
ret = gmsh%model%addPhysicalGroup(3, [ov(2, 0)], 10)
deallocate(ov, ovv, ovv_n)

! Creating entities using constructive solid geometry is very powerful, but can
! lead to practical issues for e.g. setting mesh sizes at points, or identifying
! boundaries.

! To identify points or other bounding entities you can take advantage of the
! `getEntities()', `getBoundary()' and `getEntitiesInBoundingBox()' functions:

lcar1 = .1
lcar2 = .0005
lcar3 = .055

! Assign a mesh size to all the points:
call gmsh%model%getEntities(ov, 0)
call gmsh%model%mesh%setSize(ov, lcar1)
deallocate(ov)

! Override this constraint on the points of the five spheres:
call gmsh%model%getBoundary(holes, ov, .false., .false., .true.)
call gmsh%model%mesh%setSize(ov, lcar3)
deallocate(ov)

! Select the corner point by searching for it geometrically:
eps = 1e-3
call gmsh%model%getEntitiesInBoundingBox(0.5 - eps, 0.5 - eps, 0.5 - eps, &
                                         0.5 + eps, 0.5 + eps, 0.5 + eps, ov, 0)
call gmsh%model%mesh%setSize(ov, lcar2)

call gmsh%model%mesh%generate(3)

call gmsh%write("t16.msh")

! Additional examples created with the OpenCASCADE geometry kernel are available
! in `t18.f90', `t19.f90' and `t20.f90', as well as in the `examples/api'
! directory.

! Inspect the log:
call gmsh%logger%get(log)
write(str, '(A)') size(log)
print*, "Logger has recorded "//trim(str)//" lines"
call gmsh%logger%stop()

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t16

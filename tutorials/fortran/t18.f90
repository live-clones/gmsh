! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 18
!
!  Periodic meshes
!
! ------------------------------------------------------------------------------

! Periodic meshing constraints can be imposed on surfaces and curves.

program t18

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: ret, i, j
integer(c_int), allocatable :: tags(:,:), out(:,:), out_map(:,:), p(:,:), sxmin(:,:), sxmax(:,:), tmp(:)
integer(c_size_t), allocatable :: out_map_n(:)
real(c_double), allocatable :: translation(:)
real(c_double) :: xmin, ymin, zmin, xmax, ymax, zmax, xmin2, ymin2, zmin2, xmax2, ymax2, zmax2, x, y, z, eps
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

call gmsh%model%add("t18")

! Let's use the OpenCASCADE geometry kernel to build two geometries.

! The first geometry is very simple: a unit cube with a non-uniform mesh size
! constraint (set on purpose to be able to verify visually that the periodicity
! constraint works!):

ret = gmsh%model%occ%addBox(0d0, 0d0, 0d0, 1d0, 1d0, 1d0, 1)
call gmsh%model%occ%synchronize()

call gmsh%model%getEntities(tags, 0)
call gmsh%model%mesh%setSize(tags, 0.1d0)
call gmsh%model%mesh%setSize(reshape([0, 1], [2, 1]), 0.02d0)
deallocate(tags)

! To impose that the mesh on surface 2 (the right side of the cube) should
! match the mesh from surface 1 (the left side), the following periodicity
! constraint is set:
translation = [1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
call gmsh%model%mesh%setPeriodic(2, [2], [1], translation)

! The periodicity transform is provided as a 4x4 affine transformation matrix,
! given by row.

! During mesh generation, the mesh on surface 2 will be created by copying
! the mesh from surface 1.

! Multiple periodicities can be imposed in the same way:
call gmsh%model%mesh%setPeriodic(2, [6], [5], &
                            [real(c_double) :: 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1])
call gmsh%model%mesh%setPeriodic(2, [4], [3], &
                            [real(c_double) :: 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1])

! For more complicated cases, finding the corresponding surfaces by hand can
! be tedious, especially when geometries are created through solid
! modelling. Let's construct a slightly more complicated geometry.

! We start with a cube and some spheres:
ret = gmsh%model%occ%addBox(2d0, 0d0, 0d0, 1d0, 1d0, 1d0, 10)
x = 2 - 0.3
y = 0
z = 0
ret = gmsh%model%occ%addSphere(x, y, z, 0.35d0, 11)
ret = gmsh%model%occ%addSphere(x + 1, y, z, 0.35d0, 12)
ret = gmsh%model%occ%addSphere(x, y + 1, z, 0.35d0, 13)
ret = gmsh%model%occ%addSphere(x, y, z + 1, 0.35d0, 14)
ret = gmsh%model%occ%addSphere(x + 1, y + 1, z, 0.35d0, 15)
ret = gmsh%model%occ%addSphere(x, y + 1, z + 1, 0.35d0, 16)
ret = gmsh%model%occ%addSphere(x + 1, y, z + 1, 0.35d0, 17)
ret = gmsh%model%occ%addSphere(x + 1, y + 1, z + 1, 0.35d0, 18)

! We first fragment all the volumes, which will leave parts of spheres
! protruding outside the cube:
tags = reshape([(3, i, i = 11, 18)], [2, 19-11])
call gmsh%model%occ%fragment(reshape([3, 10], [2, 1]), tags, &
                             out, out_map, out_map_n)
deallocate(tags, out_map, out_map_n)

call gmsh%model%occ%synchronize()

! Ask OpenCASCADE to compute more accurate bounding boxes of entities using
! the STL mesh:
call gmsh%option%setNumber("Geometry.OCCBoundsUseStl", 1d0)

! We then retrieve all the volumes in the bounding box of the original cube,
! and delete all the parts outside it:
eps = 1e-3
call gmsh%model%getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + 1 + eps, &
                                         1 + eps, 1 + eps, dim=3, dimTags=tags)

remove_volumes_outside_bounding_box: block
    integer(c_int), allocatable :: res(:)
    res = pack(out(2,:), .not. [(any(out(2,i) == tags(2,:)), i=1, size(out, dim=2))])
    deallocate(out); allocate(out(2, size(res)))
    out(1,:) = 3
    out(2,:) = res
end block remove_volumes_outside_bounding_box

call gmsh%model%removeEntities(out, .true.)  ! Delete outside parts recursively
deallocate(out)

! We now set a non-uniform mesh size constraint (again to check results
! visually):
call gmsh%model%getBoundary(tags, p, .false., .false., .true.)  ! Get all points
call gmsh%model%mesh%setSize(p, 0.1d0)
deallocate(p)

call gmsh%model%getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + eps, eps, eps,&
                                         dim=0, dimtags=p)

call gmsh%model%mesh%setSize(p, 0.001d0)

! We now identify corresponding surfaces on the left and right sides of the
! geometry automatically.

! First we get all surfaces on the left:
call gmsh%model%getEntitiesInBoundingBox(2 - eps, -eps, -eps, 2 + eps, &
                                         1 + eps, 1 + eps, dim=2, dimTags=sxmin)

do i = 1, size(sxmin, 2)
    ! Then we get the bounding box of each left surface
    call gmsh%model%getBoundingBox(sxmin(1,i), sxmin(2,i), xmin, ymin, zmin, xmax, ymax, zmax)
    ! We translate the bounding box to the right and look for surfaces inside
    ! it:
    if (allocated(sxmax)) deallocate(sxmax)
    call gmsh%model%getEntitiesInBoundingBox(xmin - eps + 1, ymin - eps, &
                                             zmin - eps, xmax + eps + 1, &
                                             ymax + eps, zmax + eps, dim=2, dimTags=sxmax)

    ! For all the matches, we compare the corresponding bounding boxes...
    do j = 1, size(sxmax, 2)
        call gmsh%model%getBoundingBox( &
            sxmax(1,j), sxmax(2,j), xmin2, ymin2, zmin2, xmax2, ymax2, zmax2)
        xmin2 = xmin2 - 1
        xmax2 = xmax2 - 1
        ! ...and if they match, we apply the periodicity constraint
        if (abs(xmin2 - xmin) < eps .and. abs(xmax2 - xmax) < eps &
                .and. abs(ymin2 - ymin) < eps .and. abs(ymax2 - ymax) < eps &
                .and. abs(zmin2 - zmin) < eps .and. abs(zmax2 - zmax) < eps) then
            call gmsh%model%mesh%setPeriodic(2, [sxmax(2,j)], [sxmin(2,i)], translation)
        end if
    end do
end do

call gmsh%model%mesh%generate(3)
call gmsh%write("t18.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t18

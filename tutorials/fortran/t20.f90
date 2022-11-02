! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 20
!
!  STEP import and manipulation, geometry partitioning
!
! ------------------------------------------------------------------------------

! The OpenCASCADE CAD kernel allows to import STEP files and to modify them. In
! this tutorial we will load a STEP geometry and partition it into slices.

program t20

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: i, n
integer(c_int), allocatable :: rm(:), tags(:,:), s(:,:), dels(:,:), v(:,:), tmp(:,:), tmp_map(:,:)
integer(c_size_t), allocatable :: tmp_map_n(:)
real(c_double) :: h, tx, ty, tz, eps
real(c_double) :: xmin, ymin, zmin, xmax, ymax, zmax, dx, dy, dz, L, xx, yy, zz
character(len=GMSH_API_MAX_STR_LEN) :: cmd, dir
logical :: surf

call gmsh%initialize()

call gmsh%model%add("t20")

! Load a STEP file (using `importShapes' instead of `merge' allows to directly
! retrieve the tags of the highest dimensional imported entities):
call gmsh%model%occ%importShapes('../t20_data.step', v)

! If we had specified
!
! call gmsh%option%setString('Geometry.OCCTargetUnit', 'M')
!
! before merging the STEP file, OpenCASCADE would have converted the units to
! meters (instead of the default, which is millimeters).

! Get the bounding box of the volume:
call gmsh%model%occ%getBoundingBox(v(1,1), v(2,1), xmin, ymin, zmin, xmax, ymax, zmax)

! We want to slice the model into N slices, and either keep the volume slices
! or just the surfaces obtained by the cutting:

N = 5  ! Number of slices
dir = 'X' ! Direction: 'X', 'Y' or 'Z'
surf = .false.  ! Keep only surfaces?

dx = (xmax - xmin)
dy = (ymax - ymin)
dz = (zmax - zmin)
L = dz; if (trim(dir) /= 'X') L = dx
H = dz; if (trim(dir) /= 'X') L = dy

! Create the first cutting plane:
s = reshape([2, gmsh%model%occ%addRectangle(xmin, ymin, zmin, L, H)], [2, 1])

if (trim(dir) == 'X') then
    call gmsh%model%occ%rotate(s, xmin, ymin, zmin, 0d0, 1d0, 0d0, -M_PI/2)
else if (trim(dir) == 'Y') then
    call gmsh%model%occ%rotate(s, xmin, ymin, zmin, 1d0, 0d0, 0d0, M_PI/2)
end if
tx = dx / N; if (dir /= 'X') tx = 0
ty = dy / N; if (dir /= 'Y') ty = 0
tz = dz / N; if (dir /= 'Z') tz = 0
call gmsh%model%occ%translate(s, tx, ty, tz)

! Create the other cutting planes:
do i = 1, N-2
    call gmsh%model%occ%copy(reshape(s(:, 1), [2, 1]), tags)
    s = reshape([s, tags], [2, size(s, 2) + size(tags, 2)])
    call gmsh%model%occ%translate(reshape(s(:,size(s,2)), [2,1]), i * tx, i * ty, i * tz)
    deallocate(tags)
end do

! Fragment (i.e. intersect) the volume with all the cutting planes:
call gmsh%model%occ%fragment(v, s, tmp, tmp_map, tmp_map_n)
deallocate(tmp, tmp_map, tmp_map_n)

! Now remove all the surfaces (and their bounding entities) that are not on the
! boundary of a volume, i.e. the parts of the cutting planes that "stick out" of
! the volume:
call gmsh%model%occ%getEntities(tags, 2)
call gmsh%model%occ%remove(tags, .true.); deallocate(tags)

call gmsh%model%occ%synchronize()

if (surf) then
    ! If we want to only keep the surfaces, retrieve the surfaces in bounding
    ! boxes around the cutting planes...
    eps = 1e-4
    if (allocated(s)) deallocate(s)
    s = reshape([integer(c_int) ::], [2,0])
    do i = 1, N-1
        xx = xmin; if (dir /= 'X') xx = xmax
        yy = ymin; if (dir /= 'Y') yy = ymax
        zz = zmin; if (dir /= 'Z') zz = zmax
        call gmsh%model%getEntitiesInBoundingBox( &
            xmin - eps + i * tx, ymin - eps + i * ty, zmin - eps + i * tz, &
            xx + eps + i * tx, yy + eps + i * ty, zz + eps + i * tz, tags, 2)
        s = reshape([s, tags], [2, size(s,2) + size(tags,2)])
    end do
    ! ...and remove all the other entities (here directly in the model, as we
    ! won't modify any OpenCASCADE entities later on):
    call gmsh%model%getEntities(dels, 2)
    ! This removal is not entirely accurate, it misses the 1-6 tuple values
    ! but it works good enough for this example:
    rm = pack(dels, dels /= s)
    dels = reshape(rm, [2, size(rm)/2])

    if (allocated(tmp)) deallocate(tmp)
    call gmsh%model%getEntities(tmp, 3)
    call gmsh%model%removeEntities(tmp); deallocate(tmp)
    call gmsh%model%removeEntities(dels); deallocate(dels)
    call gmsh%model%getEntities(tmp, 1)
    call gmsh%model%removeEntities(tmp); deallocate(tmp)
    call gmsh%model%getEntities(tmp, 0)
    call gmsh%model%removeEntities(tmp); deallocate(tmp)
end if

! Finally, let's specify a global mesh size and mesh the partitioned model:
call gmsh%option%setNumber("Mesh.MeshSizeMin", 3d0)
call gmsh%option%setNumber("Mesh.MeshSizeMax", 3d0)
call gmsh%model%mesh%generate(3)
call gmsh%write("t20.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t20

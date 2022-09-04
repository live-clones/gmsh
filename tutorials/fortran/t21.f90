! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 21
!
!  Mesh partitioning
!
! ------------------------------------------------------------------------------

! Gmsh can partition meshes using different algorithms, e.g. the graph
! partitioner Metis or the `SimplePartition' plugin. For all the partitioning
! algorithms, the relationship between mesh elements and mesh partitions is
! encoded through the creation of new (discrete) elementary entities, called
! "partition entities".
!
! Partition entities behave exactly like other discrete elementary entities; the
! only difference is that they keep track of both a mesh partition index and
! their parent elementary entity.
!
! The major advantage of this approach is that it allows to maintain a full
! boundary representation of the partition entities, which Gmsh creates
! automatically if `Mesh.PartitionCreateTopology' is set.

program t21

use, intrinsic :: iso_c_binding
use gmsh

implicit none

type(gmsh_t) :: gmsh
integer(c_int) :: ret
integer(c_int), allocatable :: tags(:,:), tags_map(:,:)
integer(c_size_t), allocatable :: tags_map_n(:)
character(len=GMSH_API_MAX_STR_LEN) :: cmd


call gmsh%initialize()

! Let us start by creating a simple geometry with two adjacent squares sharing
! an edge:
call gmsh%model%add("t21")
ret = gmsh%model%occ%addRectangle(0d0, 0d0, 0d0, 1d0, 1d0, 1)
ret = gmsh%model%occ%addRectangle(1d0, 0d0, 0d0, 1d0, 1d0, 2)
call gmsh%model%occ%fragment(reshape([2, 1], [2, 1]), reshape([2, 2], [2, 1]), tags, tags_map, tags_map_n)
call gmsh%model%occ%synchronize()
call gmsh%model%getEntities(tags, 0)
call gmsh%model%mesh%setSize(tags, 0.05d0)

! We create one physical group for each square, and we mesh the resulting
! geometry:
ret = gmsh%model%addPhysicalGroup(2, [1], 100, "Left")
ret = gmsh%model%addPhysicalGroup(2, [2], 200, "Right")
call gmsh%model%mesh%generate(2)

! We now define several ONELAB parameters to fine-tune how the mesh will be
! partitioned:
call gmsh%onelab%set('['//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/0Mesh partitioner",'//&
    '"values":[0],'//&
    '"choices":[0, 1],'//&
    '"valueLabels":{"Metis":0, "SimplePartition":1}'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/1Number of partitions",'//&
    '"values":[3],'//&
    '"min":1,'//&
    '"max":256,'//&
    '"step":1'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/2Create partition topology (BRep)?",'//&
    '"values":[1],'//&
    '"choices":[0, 1]'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/3Create ghost cells?",'//&
    '"values":[0],'//&
    '"choices":[0, 1]'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/3Create new physical groups?",'//&
    '"values":[0],'//&
    '"choices":[0, 1]'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/3Write file to disk?",'//&
    '"values":[1],'//&
    '"choices":[0, 1]'//&
  '},'//&
  '{'//&
    '"type":"number",'//&
    '"name":"Parameters/4Write one file per partition?",'//&
    '"values":[0],'//&
    '"choices":[0, 1]'//&
  '}'//&
']')

call partitionMesh()

call get_command(cmd)
if (index(cmd, "-nopopup") == 0) then
    call gmsh%fltk%initialize()
    do while (transfer(gmsh%fltk%isAvailable(), .true.) .and. checkForEvent())
        call gmsh%fltk%wait()
    end do
end if

call gmsh%finalize()

contains
subroutine partitionMesh()
    real(c_double), allocatable :: val(:)
    integer(c_int) :: N
    ! Number of partitions

    call gmsh%onelab%getNumber("Parameters/1Number of partitions", val)
    N = int(val(1), kind=c_int); deallocate(val)

    ! Should we create the boundary representation of the partition entities?
    call gmsh%onelab%getNumber("Parameters/2Create partition topology (BRep)?", val)
    call gmsh%option%setNumber("Mesh.PartitionCreateTopology", val(1)); deallocate(val)

    ! Should we create ghost cells?
    call gmsh%onelab%getNumber("Parameters/3Create ghost cells?", val)
    call gmsh%option%setNumber("Mesh.PartitionCreateGhostCells", val(1)); deallocate(val)

    ! Should we automatically create new physical groups on the partition
    ! entities?
    call gmsh%onelab%getNumber("Parameters/3Create new physical groups?", val)
    call gmsh%option%setNumber("Mesh.PartitionCreatePhysicals", val(1)); deallocate(val)

    ! Should we keep backward compatibility with pre-Gmsh 4, e.g. to save the
    ! mesh in MSH2 format?
    call gmsh%option%setNumber("Mesh.PartitionOldStyleMsh2", 0d0)

    ! Should we save one mesh file per partition?
    call gmsh%onelab%getNumber("Parameters/4Write one file per partition?", val)
    call gmsh%option%setNumber("Mesh.PartitionSplitMeshFiles", val(1)); deallocate(val)

    call gmsh%onelab%getNumber("Parameters/0Mesh partitioner", val)
    if (val(1) == 0) then
        ! Use Metis to create N partitions
        call gmsh%model%mesh%partition(N)
        ! Several options can be set to control Metis: `Mesh.MetisAlgorithm' (1:
        ! Recursive, 2: K-way), `Mesh.MetisObjective' (1: min. edge-cut, 2:
        ! min. communication volume), `Mesh.PartitionTriWeight' (weight of
        ! triangles), `Mesh.PartitionQuadWeight' (weight of quads), ...
    else
        ! Use the `SimplePartition' plugin to create chessboard-like partitions
        call gmsh%plugin%setNumber("SimplePartition", "NumSlicesX", real(N, c_double))
        call gmsh%plugin%setNumber("SimplePartition", "NumSlicesY", 1d0)
        call gmsh%plugin%setNumber("SimplePartition", "NumSlicesZ", 1d0)
        ret = gmsh%plugin%run("SimplePartition")
    end if
    deallocate(val)

    ! Save mesh file (or files, if `Mesh.PartitionSplitMeshFiles' is set):
    call gmsh%onelab%getNumber("Parameters/3Write file to disk?", val)
    if (val(1) == 1) then
        call gmsh%write("t21.msh")
    end if
    ! Iterate over partitioned entities and print some info (see the first
    ! extended tutorial `x1.f90' for additional information):
    ! call gmsh%model%getEntities(entities)
    ! do e = 1, size(entities)
    !     partitions = call gmsh%model%getPartitions(e[0], e[1])
    !     if (size(partitions)) then
    !         print*, "Entity " + str(e) + " of type " // &
    !               call gmsh%model%getType(e[0], e[1]))
    !         print*, " - Partition(s): " + str(partitions)
    !         print*, " - Parent: " + str(call gmsh%model%getParent(e[0], e[1]))
    !         print*, " - Boundary: " + str(call gmsh%model%getBoundary([e]))
    !     end if
    ! end do
end subroutine partitionMesh

! Launch the GUI and handle the "check" event (recorded in the "ONELAB/Action"
! parameter) to recreate the geometry with a new twisting angle if necessary:
logical function checkForEvent() result(val)
  character(len=GMSH_API_MAX_STR_LEN), allocatable :: action(:)

  val = .false.
  call gmsh%onelab%getString("ONELAB/Action", action)
  if (size(action) > 0) then
    if (trim(action(1)) == "check") then
      call gmsh%onelab%setString("ONELAB/Action", [c_null_char])
      call partitionMesh()
      call gmsh%graphics%draw()
    end if
  end if
  val = .true.
end function checkForEvent

end program t21

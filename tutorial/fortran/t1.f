c ---------------------------------------------------------------------------
c
c   Gmsh Fortran tutorial 1
c
c   Elementary entities (points, curves, surfaces), physical groups
c
c ---------------------------------------------------------------------------

      include 'gmshf.h'

      program main
      use, intrinsic :: iso_c_binding
      use gmsh_fortran

      implicit none
      integer(c_int) :: ierr, p4, argc, itmp, i, ps, status, len
      real(c_double) :: lc

      integer(c_int) :: cl1(4) = (/4, 1, -2, 3/)
      integer(c_int) :: s1(1) = (/1/)
      integer(c_int) :: g5(3) = (/1, 2, 4/)
      integer(c_int) :: g6(1) = (/1/)

      type(c_ptr), allocatable :: argv(:)

      type string
        character(len = :, kind = c_char), allocatable :: item
      end type string
      type(string), allocatable, target :: tmp(:)

      character(80) :: buf

      lc = 1d - 2

      argc = command_argument_count()
      allocate(argv(argc + 2))
      allocate(tmp(argc + 1))

      do i = 0, argc
        call get_command_argument(i, buf, len)
        tmp(i + 1) % item = buf(1 : len) // c_null_char
        argv(i + 1) = c_loc(tmp(i + 1) % item)
      enddo
      argv(argc + 2) = c_null_ptr

      call gmshInitialize(argc + 1, argv, 1, ierr)

      call gmshModelAdd('t1', ierr)
      itmp = gmshModelGeoAddPoint(0d0, 0d0, 0d0, lc, 1, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0d0, 0d0, lc, 2, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0d0, lc, 3, ierr)
      p4 = gmshModelGeoAddPoint(0d0, 0.3d0, 0d0, lc, -1, ierr)

      itmp = gmshModelGeoAddLine(1, 2, 1, ierr)
      itmp = gmshModelGeoAddLine(3, 2, 2, ierr)
      itmp = gmshModelGeoAddLine(3, p4, 3, ierr)
      itmp = gmshModelGeoAddLine(p4, 1, 4, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl1, 4_8, 1, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s1, 1_8, 1, ierr)

      call gmshModelGeoSynchronize(ierr)
      itmp = gmshModelAddPhysicalGroup(1, g5, 3_8, 5, ierr)
      ps = gmshModelAddPhysicalGroup(2, g6, 1_8, -1, ierr)
      call gmshModelSetPhysicalName(2, ps, 'My surface', ierr)

      call gmshModelMeshGenerate(2, ierr)
      call gmshWrite('t1.msh', ierr)

c     call gmshFltkRun(ierr)

      call gmshFinalize(ierr)

      deallocate(tmp)
      deallocate(argv)

      stop
      end

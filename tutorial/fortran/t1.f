c ---------------------------------------------------------------------------
c
c   Gmsh Fortran tutorial 1
c
c   Elementary entities (points, curves, surfaces), physical groups
c
c --------------------------------------------------------------------------- 

      include 'gmshf.h'

      program main      
      use, intrinsic :: ISO_C_BINDING
      use gmsh_fortran

      implicit none
      integer (C_INT) :: ierr, p4, argc, itmp, i, ps, status
      real (C_DOUBLE) :: lc

      integer (C_INT) :: cl1(4) = (/4,1,-2,3/)
      integer (C_INT) :: s1(1) = (/1/)
      integer (C_INT) :: g5(3) = (/1,2,4/)
      integer (C_INT) :: g6(1) = (/1/)

      type (C_PTR), allocatable :: argv(:)

      TYPE string
        CHARACTER (LEN=:,KIND=C_CHAR), ALLOCATABLE :: item
        END TYPE string
      TYPE (string), ALLOCATABLE, TARGET :: tmp(:)

      character (80) :: buf

      lc=1d-2

      argc = NARGS()
      allocate(argv(argc+1))
      if (argc > 0) then
        allocate(tmp(argc))
        endif

      do i=1,argc
        call GETARG(i-1, buf, status)
        tmp(i)%item=TRIM(buf) // C_NULL_CHAR
        argv(i)=C_LOC(tmp(i)%item)
        enddo
      argv(argc+1)=C_NULL_PTR

      call gmshInitialize(argc, argv, 1, ierr)

      call gmshModelAdd('t1', ierr)
      itmp = gmshModelGeoAddPoint(0d0, 0d0, 0d0, lc, 1, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0d0, 0d0, lc, 2, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0d0, lc, 3, ierr)
      p4 = gmshModelGeoAddPoint(0d0, 0.3d0, 0d0, lc, -1, ierr)

      itmp = gmshModelGeoAddLine(1, 2, 1, ierr)
      itmp = gmshModelGeoAddLine(3, 2, 2, ierr)
      itmp = gmshModelGeoAddLine(3, p4, 3, ierr)
      itmp = gmshModelGeoAddLine(p4, 1, 4, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl1, 4, 1, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s1, 1, 1, ierr)

      call gmshModelGeoSynchronize(ierr)
      itmp = gmshModelAddPhysicalGroup(1, g5, 3, 5, ierr)
      ps = gmshModelAddPhysicalGroup(2, g6, 1, -1, ierr)
      call gmshModelSetPhysicalName(2, ps, 'My surface', ierr)

      call gmshModelMeshGenerate(2, ierr)
      call gmshWrite('t1.msh', ierr)

c      call gmshFltkRun(ierr)

      call gmshFinalize(ierr)

c      if (argc > 0) then
c        deallocate(tmp)
c        endif
c      deallocate(argv)

      stop
      end

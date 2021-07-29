c ---------------------------------------------------------------------------
c
c   Gmsh Fortran tutorial 6
c
c   Transfinite meshes
c
c --------------------------------------------------------------------------- 

      include 'gmshf.h'

      program main      
      use, intrinsic :: ISO_C_BINDING
      use gmsh_fortran

      implicit none
      integer (C_INT) :: ierr, argc, itmp, i, status
      integer (C_INT) :: p1, p2, l1, l2, l3
      real (C_DOUBLE) :: lc

      integer (C_INT) :: cl1(4) = (/4,1,-2,3/)
      integer (C_INT) :: cl2(6) = (/2, -1, 0, 0, 0, -3/)
      integer (C_INT) :: cl3(4) = (/13, 10, 11, 12/)
      integer (C_INT) :: s1(1) = (/1/)
      integer (C_INT) :: s2(1) = (/-2/)
      integer (C_INT) :: s3(1) = (/14/)

      integer (C_INT) :: r4(4) = (/2, 1, 1, 4/)
      integer (C_INT) :: ts(4) = (/1, 2, 3, 4/)

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

      call gmshModelAdd('t6', ierr)

      itmp = gmshModelGeoAddPoint(0d0, 0d0, 0d0, lc, 1, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0d0, 0d0, lc, 2, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0d0, lc, 3, ierr)
      itmp = gmshModelGeoAddPoint(0d0, 0.3d0, 0d0, lc, 4, ierr)

      itmp = gmshModelGeoAddLine(1, 2, 1, ierr)
      itmp = gmshModelGeoAddLine(3, 2, 2, ierr)
      itmp = gmshModelGeoAddLine(3, 4, 3, ierr)
      itmp = gmshModelGeoAddLine(4, 1, 4, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl1, 4, 1, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s1, 1, 1, ierr)

      call gmshModelGeoRemove(r4, 4, 0, ierr)

      p1 = gmshModelGeoAddPoint(-0.05d0, 0.05d0, 0d0, lc, -1, ierr)
      p2 = gmshModelGeoAddPoint(-0.05d0, 0.1d0, 0d0, lc, -1, ierr)

      l1 = gmshModelGeoAddLine(1, p1, -1, ierr)
      l2 = gmshModelGeoAddLine(p1, p2, -1, ierr)
      l3 = gmshModelGeoAddLine(p2, 4, -1, ierr)

      cl2(3) = l1
      cl2(4) = l2
      cl2(5) = l3
      itmp = gmshModelGeoAddCurveLoop(cl2, 6, 2, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s2, 1, 1, ierr)

      call gmshModelGeoMeshSetTransfiniteCurve(2, 20, "Progression", 
     &                                         1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l1, 6, "Progression", 
     &                                         1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l2, 6, "Progression", 
     &                                         1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l3, 10, "Progression", 
     &                                         1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(1, 30, "Progression", 
     &                                         -1.2d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(3, 30, "Progression", 
     &                                         1.2d0, ierr)

      call gmshModelGeoMeshSetTransfiniteSurface(1, "Left", ts, 4, ierr)
      call gmshModelGeoMeshSetRecombine(2, 1, 45d0, ierr)

      itmp = gmshModelGeoAddPoint(0.2d0, 0.2d0, 0d0, 1d0, 7, ierr)
      itmp = gmshModelGeoAddPoint(0.2d0, 0.1d0, 0d0, 1d0, 8, ierr)
      itmp = gmshModelGeoAddPoint(0d0, 0.3d0, 0d0, 1d0, 9, ierr)
      itmp = gmshModelGeoAddPoint(0.25d0, 0.2d0, 0d0, 1d0, 10, ierr)
      itmp = gmshModelGeoAddPoint(0.3d0, 0.1d0, 0d0, 1d0, 11, ierr)

      itmp = gmshModelGeoAddLine(8, 11, 10, ierr)
      itmp = gmshModelGeoAddLine(11, 10, 11, ierr)
      itmp = gmshModelGeoAddLine(10, 7, 12, ierr)
      itmp = gmshModelGeoAddLine(7, 8, 13, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl3, 4, 14, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s3, 1, 15, ierr)

      do i=10,13
        call gmshModelGeoMeshSetTransfiniteCurve(i, 10, "Progression", 
     &                                           1d0, ierr)
        enddo 

      call gmshModelGeoMeshSetTransfiniteSurface(15, "Left", ts, 0, 
     &                                           ierr)

      call gmshOptionSetNumber("Mesh.Smoothing", 100, ierr)

      call gmshModelGeoSynchronize(ierr)                              

      call gmshModelMeshGenerate(2, ierr)
      call gmshWrite('t6.msh', ierr)

c      call gmshFltkRun(ierr)

      call gmshFinalize(ierr)
      stop
      end

c ---------------------------------------------------------------------------
c
c   Gmsh Fortran tutorial 2
c
c   Transformations, extruded geometries, volumes
c
c --------------------------------------------------------------------------- 

      include 'gmshf.h'

      program main      
      use, intrinsic :: ISO_C_BINDING
      use gmsh_fortran

      implicit none
      integer (C_INT) :: ierr, argc, itmp, i, ps, status
      integer (C_INT) :: recombine
      integer (C_SIZE_T) :: ov_n, xyz_n, numElements_n, heights_n, ov2_n
      real (C_DOUBLE) :: lc

      integer (C_INT) :: cl1(4) = (/4,1,-2,3/)
      integer (C_INT) :: cl2(4) = (/5,-8,-7,3/)
      integer (C_INT) :: cl3(4) = (/115,-111,3,110/)

      integer (C_INT) :: cl4(4) = (/111,116,-112,-7/)
      integer (C_INT) :: cl5(4) = (/112,117,-113,-8/)
      integer (C_INT) :: cl6(4) = (/114,-110,5,113/)
      integer (C_INT) :: cl7(4) = (/115,116,117,114/)
      integer (C_INT) :: s1(1) = (/1/)
      integer (C_INT) :: s2(1) = (/10/)
      integer (C_INT) :: s3(1) = (/118/)
      integer (C_INT) :: s4(1) = (/120/)
      integer (C_INT) :: s5(1) = (/122/)
      integer (C_INT) :: s6(1) = (/124/)
      integer (C_INT) :: s7(1) = (/126/)
      integer (C_INT) :: g5(3) = (/1,2,4/)
      integer (C_INT) :: g6(1) = (/1/)
      integer (C_INT) :: g7(2) = (/129,130/)
      integer (C_INT) :: t(2) = (/0,5/)
      integer (C_INT) :: iv(2) = (/0,3/)
      integer (C_INT) :: iv2(4) = (/2,1,2,11/)
      integer (C_INT) :: numElements(0)
      real (C_DOUBLE) :: iv0(0)
      real (C_DOUBLE) :: heights(0)
      integer (C_INT) :: sl1(6) = (/127,119,121,123,125,11/)
      integer (C_INT) :: v1(1) = (/128/)
      integer (C_INT) :: ss(16) = 
     &                   (/0,103,0,105,0,109,0,102,0,28,0,24,0,6,0,5/)

      type (C_PTR), allocatable :: argv(:)
      type (C_PTR) :: ov, xyz, ov2, ov_3

      TYPE string
        CHARACTER (LEN=:,KIND=C_CHAR), ALLOCATABLE :: item
        END TYPE string
      TYPE (string), ALLOCATABLE, TARGET :: tmp(:)

      character (80) :: buf

      integer (kind=C_INT), pointer :: pf_ov(:), pf_ov3(:), pf_ov2(:)
      real (kind=C_DOUBLE), pointer :: pf_xyz(:)

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

      call gmshModelAdd('t2', ierr)

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

      call gmshModelGeoSynchronize(ierr)
      itmp = gmshModelAddPhysicalGroup(1, g5, 3, 5, ierr)
      ps = gmshModelAddPhysicalGroup(2, g6, 1, -1, ierr)
      call gmshModelSetPhysicalName(2, ps, 'My surface', ierr)

      itmp = gmshModelGeoAddPoint(0d0, 0.4d0, 0d0, lc, 5, ierr)

      itmp = gmshModelGeoAddLine(4, 5, 5, ierr)

      call gmshModelGeoTranslate(t, 2, -0.02d0, 0d0, 0d0, ierr)

      call gmshModelGeoRotate(t, 2, 0d0, 0.3d0, 0d0, 0d0, 0d0, 1d0,
     &                        -M_PI/4d0, ierr)

      call gmshModelGeoCopy(iv, 2, ov, ov_n, ierr)

      call C_F_POINTER(ov, pf_ov, [ov_n])
      call gmshModelGeoTranslate(pf_ov, ov_n, 0d0, 0.05d0, 0d0, ierr)

      itmp = gmshModelGeoAddLine(3, pf_ov(2), 7, ierr)
      itmp = gmshModelGeoAddLine(pf_ov(2), 5, 8, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl2, 4, 10, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s2, 1, 11, ierr)

      call gmshModelGeoCopy(iv2, 4, ov, ov_n, ierr)

      call C_F_POINTER(ov, pf_ov, [ov_n])
      call gmshModelGeoTranslate(pf_ov, ov_n, 0.12d0, 0d0, 0d0, ierr)

      print *, 'New surfaces ', pf_ov(2), ' and ', pf_ov(4)

      itmp = gmshModelGeoAddPoint(0d0, 0.3d0, 0.12d0, lc, 100, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0.12d0, lc, 101, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.35d0, 0.12d0, lc, 102, ierr)

      call gmshModelGeoSynchronize(ierr)                              

      call gmshModelGetValue(0, 5, iv0, 0, xyz, xyz_n, ierr)

      call C_F_POINTER(xyz, pf_xyz, [xyz_n])
      itmp = gmshModelGeoAddPoint(pf_xyz(1), pf_xyz(2), 0.12d0, lc, 103, 
     &                            ierr)

      itmp = gmshModelGeoAddLine(4, 100, 110, ierr)
      itmp = gmshModelGeoAddLine(3, 101, 111, ierr)
      itmp = gmshModelGeoAddLine(6, 102, 112, ierr);
      itmp = gmshModelGeoAddLine(5, 103, 113, ierr)
      itmp = gmshModelGeoAddLine(103, 100, 114, ierr)
      itmp = gmshModelGeoAddLine(100, 101, 115, ierr)
      itmp = gmshModelGeoAddLine(101, 102, 116, ierr)
      itmp = gmshModelGeoAddLine(102, 103, 117, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl3, 4, 118, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s3, 1, 119, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl4, 4, 120, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s4, 1, 121, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl5, 4, 122, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s5, 1, 123, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl6, 4, 124, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s6, 1, 125, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl7, 4, 126, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s7, 1, 127, ierr)

      itmp = gmshModelGeoAddSurfaceLoop(sl1, 6, 128, ierr)
      itmp = gmshModelGeoAddVolume(v1, 1, 129, ierr)

      numElements_n = 0
      heights_n = 0
      recombine=0
      ov_3 = C_LOC(pf_ov(3))
      call C_F_POINTER(ov_3, pf_ov3, [ov_n-2])
      call gmshModelGeoExtrude(pf_ov3, 2, 0d0, 0d0, 0.12d0, 
     &                 ov2, ov2_n, numElements, numElements_n, 
     &                 heights, heights_n, recombine, ierr)

      call gmshModelGeoMeshSetSize(ss, 16, lc * 3, ierr)

      call gmshModelGeoSynchronize(ierr)                              

      itmp = gmshModelAddPhysicalGroup(3, g7, 2, 1, ierr)

      call gmshModelSetPhysicalName(3, 1, 'The volume', ierr)

      call gmshModelMeshGenerate(3, ierr)
      call gmshWrite('t2.msh', ierr)

c      call gmshFltkRun(ierr)

      call gmshFinalize(ierr)
      stop
      end

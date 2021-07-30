c ---------------------------------------------------------------------------
c
c   Gmsh Fortran tutorial 6
c
c   Transfinite meshes
c
c ---------------------------------------------------------------------------

      include "gmshf.h"

      program main
      use, intrinsic :: iso_c_binding
      use gmsh_fortran

      implicit none
      integer(c_int) :: ierr, argc, itmp, i, status, len
      integer(c_int) :: p1, p2, l1, l2, l3
      real(c_double) :: lc

      integer(c_int) :: cl1(4) = (/4, 1, -2, 3/)
      integer(c_int) :: cl2(6) = (/2, -1, 0, 0, 0, -3/)
      integer(c_int) :: cl3(4) = (/13, 10, 11, 12/)
      integer(c_int) :: s1(1) = (/1/)
      integer(c_int) :: s2(1) = (/-2/)
      integer(c_int) :: s3(1) = (/14/)

      integer(c_int) :: r4(4) = (/2, 1, 1, 4/)
      integer(c_int) :: ts(4) = (/1, 2, 3, 4/)

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

      call gmshModelAdd("t6" // c_null_char, ierr)

      itmp = gmshModelGeoAddPoint(0d0, 0d0, 0d0, lc, 1, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0d0, 0d0, lc, 2, ierr)
      itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0d0, lc, 3, ierr)
      itmp = gmshModelGeoAddPoint(0d0, 0.3d0, 0d0, lc, 4, ierr)

      itmp = gmshModelGeoAddLine(1, 2, 1, ierr)
      itmp = gmshModelGeoAddLine(3, 2, 2, ierr)
      itmp = gmshModelGeoAddLine(3, 4, 3, ierr)
      itmp = gmshModelGeoAddLine(4, 1, 4, ierr)

      itmp = gmshModelGeoAddCurveLoop(cl1, 4_8, 1, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s1, 1_8, 1, ierr)

      call gmshModelGeoRemove(r4, 4_8, 0, ierr)

      p1 = gmshModelGeoAddPoint(-0.05d0, 0.05d0, 0d0, lc, -1, ierr)
      p2 = gmshModelGeoAddPoint(-0.05d0, 0.1d0, 0d0, lc, -1, ierr)

      l1 = gmshModelGeoAddLine(1, p1, -1, ierr)
      l2 = gmshModelGeoAddLine(p1, p2, -1, ierr)
      l3 = gmshModelGeoAddLine(p2, 4, -1, ierr)

      cl2(3) = l1
      cl2(4) = l2
      cl2(5) = l3
      itmp = gmshModelGeoAddCurveLoop(cl2, 6_8, 2, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s2, 1_8, 1, ierr)

      call gmshModelGeoMeshSetTransfiniteCurve(2, 20,
     &     "Progression" // c_null_char, 1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l1, 6,
     &     "Progression" // c_null_char, 1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l2, 6,
     &     "Progression" // c_null_char, 1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(l3, 10,
     &     "Progression" // c_null_char, 1d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(1, 30,
     &     "Progression" // c_null_char, -1.2d0, ierr)
      call gmshModelGeoMeshSetTransfiniteCurve(3, 30,
     &     "Progression" // c_null_char, 1.2d0, ierr)

      call gmshModelGeoMeshSetTransfiniteSurface(1,
     &     "Left" // c_null_char, ts, 4_8, ierr)
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

      itmp = gmshModelGeoAddCurveLoop(cl3, 4_8, 14, 0, ierr)
      itmp = gmshModelGeoAddPlaneSurface(s3, 1_8, 15, ierr)

      do i = 10, 13
         call gmshModelGeoMeshSetTransfiniteCurve(i, 10,
     &        "Progression" // c_null_char, 1d0, ierr)
      enddo

      call gmshModelGeoMeshSetTransfiniteSurface(15,
     &     "Left" // c_null_char, ts, 0_8, ierr)

      call gmshOptionSetNumber("Mesh.Smoothing" // c_null_char,
     &     100d0, ierr)

      call gmshModelGeoSynchronize(ierr)

      call gmshModelMeshGenerate(2, ierr)
      call gmshWrite("t6.msh" // c_null_char, ierr)

c     call gmshFltkRun(ierr)

      call gmshFinalize(ierr)

      deallocate(tmp)
      deallocate(argv)

      stop
      end

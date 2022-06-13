! ---------------------------------------------------------------------------
!
!   Gmsh Fortran tutorial 2
!
!   Transformations, extruded geometries, volumes
!
! ---------------------------------------------------------------------------


program main
    use, intrinsic :: iso_c_binding
    use gmsh

    implicit none
    integer(c_int) :: ierr, argc, itmp, i, ps, len
    integer(c_int) :: recombine
    integer(c_size_t) :: ov_n, xyz_n, numElements_n, heights_n, ov2_n
    real(c_double) :: lc

    integer(c_int) :: cl1(4) = [4, 1, -2, 3]
    integer(c_int) :: cl2(4) = [5, -8, -7, 3]
    integer(c_int) :: cl3(4) = [115, -111, 3, 110]
    integer(c_int) :: cl4(4) = [111, 116, -112, -7]
    integer(c_int) :: cl5(4) = [112, 117, -113, -8]
    integer(c_int) :: cl6(4) = [114, -110, 5, 113]
    integer(c_int) :: cl7(4) = [115, 116, 117, 114]
    integer(c_int) :: s1(1) = [1]
    integer(c_int) :: s2(1) = [10]
    integer(c_int) :: s3(1) = [118]
    integer(c_int) :: s4(1) = [120]
    integer(c_int) :: s5(1) = [122]
    integer(c_int) :: s6(1) = [124]
    integer(c_int) :: s7(1) = [126]
    integer(c_int) :: g5(3) = [1, 2, 4]
    integer(c_int) :: g6(1) = [1]
    integer(c_int) :: g7(2) = [129, 130]
    integer(c_int) :: t(2) = [0, 5]
    integer(c_int) :: iv(2) = [0, 3]
    integer(c_int) :: iv2(4) = [2, 1, 2, 11]
    integer(c_int) :: numElements(0)
    real (c_double) :: iv0(0)
    real(c_double) :: heights(0)
    integer(c_int) :: sl1(6) = [127, 119, 121, 123, 125, 11]
    integer(c_int) :: v1(1) = [128]
    integer(c_int) :: ss(16) = [0, 103, 0, 105, 0, 109, 0, 102, 0, 28, 0, 24, 0, 6, 0, 5]

    type(c_ptr), allocatable :: argv(:)
    type(c_ptr) :: ov, xyz, ov2, ov_3

    type string
        character(len = :, kind = c_char), allocatable :: item
    end type string
    type(string), allocatable, target :: tmp(:)

    character(80) :: buf

    integer(c_int), pointer :: pf_ov(:), pf_ov3(:)
    real(c_double), pointer :: pf_xyz(:)

    lc = 0.01

    argc = command_argument_count()
    allocate(argv(argc + 2))
    allocate(tmp(argc + 1))

    do i = 0, argc
        call get_command_argument(i, buf, len)
        tmp(i + 1) % item = buf(1 : len) // c_null_char
        argv(i + 1) = c_loc(tmp(i + 1) % item)
    enddo
    argv(argc + 2) = c_null_ptr

    call gmshInitialize(argc + 1, argv, 1, 0, ierr)

    call gmshModelAdd("t2" // c_null_char, ierr)

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

    call gmshModelGeoSynchronize(ierr)
    itmp = gmshModelAddPhysicalGroup(1, g5, 3_8, 5, "", ierr)
    ps = gmshModelAddPhysicalGroup(2, g6, 1_8, -1, "", ierr)
    call gmshModelSetPhysicalName(2, ps, "My surface" // c_null_char, ierr)

    itmp = gmshModelGeoAddPoint(0d0, 0.4d0, 0d0, lc, 5, ierr)

    itmp = gmshModelGeoAddLine(4, 5, 5, ierr)

    call gmshModelGeoTranslate(t, 2_8, -0.02d0, 0d0, 0d0, ierr)

    call gmshModelGeoRotate(t, 2_8, 0d0, 0.3d0, 0d0, 0d0, 0d0, 1d0, -M_PI / 4d0, ierr)

    call gmshModelGeoCopy(iv, 2_8, ov, ov_n, ierr)

    call c_f_pointer(ov, pf_ov, [ov_n])
    call gmshModelGeoTranslate(pf_ov, ov_n, 0d0, 0.05d0, 0d0, ierr)

    itmp = gmshModelGeoAddLine(3, pf_ov(2), 7, ierr)
    itmp = gmshModelGeoAddLine(pf_ov(2), 5, 8, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl2, 4_8, 10, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s2, 1_8, 11, ierr)

    call gmshModelGeoCopy(iv2, 4_8, ov, ov_n, ierr)

    call c_f_pointer(ov, pf_ov, [ov_n])
    call gmshModelGeoTranslate(pf_ov, ov_n, 0.12d0, 0d0, 0d0, ierr)

    print *, "New surfaces ", pf_ov(2), " and ", pf_ov(4)

    itmp = gmshModelGeoAddPoint(0d0, 0.3d0, 0.12d0, lc, 100, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0.12d0, lc, 101, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.35d0, 0.12d0, lc, 102, ierr)

    call gmshModelGeoSynchronize(ierr)

    call gmshModelGetValue(0, 5, iv0, 0_8, xyz, xyz_n, ierr)

    call c_f_pointer(xyz, pf_xyz, [xyz_n])
    itmp = gmshModelGeoAddPoint(pf_xyz(1), pf_xyz(2), 0.12d0, lc, 103, ierr)

    itmp = gmshModelGeoAddLine(4, 100, 110, ierr)
    itmp = gmshModelGeoAddLine(3, 101, 111, ierr)
    itmp = gmshModelGeoAddLine(6, 102, 112, ierr);
    itmp = gmshModelGeoAddLine(5, 103, 113, ierr)
    itmp = gmshModelGeoAddLine(103, 100, 114, ierr)
    itmp = gmshModelGeoAddLine(100, 101, 115, ierr)
    itmp = gmshModelGeoAddLine(101, 102, 116, ierr)
    itmp = gmshModelGeoAddLine(102, 103, 117, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl3, 4_8, 118, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s3, 1_8, 119, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl4, 4_8, 120, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s4, 1_8, 121, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl5, 4_8, 122, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s5, 1_8, 123, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl6, 4_8, 124, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s6, 1_8, 125, ierr)

    itmp = gmshModelGeoAddCurveLoop(cl7, 4_8, 126, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s7, 1_8, 127, ierr)

    itmp = gmshModelGeoAddSurfaceLoop(sl1, 6_8, 128, ierr)
    itmp = gmshModelGeoAddVolume(v1, 1_8, 129, ierr)

    numElements_n = 0
    heights_n = 0
    recombine=0
    ov_3 = c_loc(pf_ov(3))
    call c_f_pointer(ov_3, pf_ov3, [ov_n - 2])
    call gmshModelGeoExtrude(pf_ov3, 2_8, 0d0, 0d0, 0.12d0, ov2, ov2_n, &
                             numElements, numElements_n, heights, heights_n, recombine, ierr)

    call gmshModelGeoMeshSetSize(ss, 16_8, lc * 3, ierr)

    call gmshModelGeoSynchronize(ierr)

    itmp = gmshModelAddPhysicalGroup(3, g7, 2_8, 1, "", ierr)

    call gmshModelSetPhysicalName(3, 1, "The volume" // c_null_char, ierr)

    call gmshModelMeshGenerate(3, ierr)
    call gmshWrite("t2.msh" // c_null_char, ierr)

    ! call gmshFltkRun(ierr)

    call gmshFinalize(ierr)

    deallocate(tmp)
    deallocate(argv)

end program main

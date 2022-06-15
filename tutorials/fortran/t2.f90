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
    integer(c_size_t) :: ov_n, xyz_n, numElements_n, heights_n, ov2_n
    integer(c_int) :: cl1(4), cl2(4), cl3(4), cl4(4), cl5(4), cl6(4), cl7(4), &
                      s1(1), s2(1), s3(1), s4(1), s5(1), s6(1), s7(1), g5(3), &
                      g6(1), g7(2), t(2), iv(2), iv2(4), numElements(0),      &
                      sl1(6), v1(1), ss(16), recombine, ierr, argc, itmp, i, len
    real (c_double) :: lc, iv0(0), heights(0)
    type(c_ptr) :: ov, xyz, ov2
    type(c_ptr), allocatable :: argv(:)

    type string
        character(len = :, kind = c_char), allocatable :: item
    end type string
    type(string), allocatable, target :: tmp(:)

    character(80) :: buf

    integer(c_int), pointer :: pf_ov(:), pf_ov3(:)
    real(c_double), pointer :: pf_xyz(:)

    argc = command_argument_count()
    allocate(argv(argc + 2))
    allocate(tmp(argc + 1))

    do i = 0, argc
        call get_command_argument(i, buf, len)
        tmp(i + 1) % item = buf(1 : len)//c_null_char
        argv(i + 1) = c_loc(tmp(i + 1) % item)
    end do
    argv(argc + 2) = c_null_ptr

    call gmshInitialize(argc + 1, argv, 1, 0, ierr)

    call gmshModelAdd("t2"//c_null_char, ierr)

    ! Copied from `t1.f90'...
    lc = 0.01
    itmp = gmshModelGeoAddPoint(0.0d0, 0.0d0, 0.0d0, lc, 1, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.0d0, 0.0d0, lc, 2, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.3d0, 0.0d0, lc, 3, ierr)
    itmp = gmshModelGeoAddPoint(0.0d0, 0.3d0, 0.0d0, lc, 4, ierr)

    itmp = gmshModelGeoAddLine(1, 2, 1, ierr)
    itmp = gmshModelGeoAddLine(3, 2, 2, ierr)
    itmp = gmshModelGeoAddLine(3, 4, 3, ierr)
    itmp = gmshModelGeoAddLine(4, 1, 4, ierr)

    cl1 = [4, 1, -2, 3]; s1 = [1]
    itmp = gmshModelGeoAddCurveLoop(cl1, size(cl1, kind=c_size_t), 1, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s1, size(s1, kind=c_size_t), 1, ierr)

    call gmshModelGeoSynchronize(ierr)

    g5 = [1, 2, 4]; g6 = [1]
    itmp = gmshModelAddPhysicalGroup(1, g5, size(g5, kind=c_size_t), 5, ""//c_null_char, ierr)
    itmp = gmshModelAddPhysicalGroup(2, g6, size(g6, kind=c_size_t), -1, "My surface"//c_null_char, ierr)
    call gmshModelSetPhysicalName(2, itmp, "My surface"//c_null_char, ierr)

    itmp = gmshModelGeoAddPoint(0.0d0, 0.4d0, 0.0d0, lc, 5, ierr)
    itmp = gmshModelGeoAddLine(4, 5, 5, ierr)

    t = [0, 5]
    call gmshModelGeoTranslate(t, size(t, kind=c_size_t), -0.02d0, 0.0d0, 0.0d0, ierr)
    call gmshModelGeoRotate(t, size(t, kind=c_size_t), 0.0d0, 0.3d0, 0.0d0, &
                            0.0d0, 0.0d0, 1.0d0, -acos(1.0d0) / 4.0d0, ierr)

    ! Note that there are no units in Gmsh: coordinates are just numbers - it's
    ! up to the user to associate a meaning to them.

    ! Point 3 can be duplicated and translated by 0.05 along the y axis by using
    ! the `copy()' function, which takes a vector of (dim, tag) pairs as input,
    ! and returns another vector of (dim, tag) pairs:
    iv = [0, 3]
    call gmshModelGeoCopy(iv, size(iv, kind=c_size_t), ov, ov_n, ierr)
    call c_f_pointer(ov, pf_ov, [ov_n])
    call gmshModelGeoTranslate(pf_ov, ov_n, 0.0d0, 0.05d0, 0.0d0, ierr)

    ! The new point tag is available in ov[0].second, and can be used to create
    ! new lines:
    itmp = gmshModelGeoAddLine(3, pf_ov(2), 7, ierr)
    itmp = gmshModelGeoAddLine(pf_ov(2), 5, 8, ierr)

    cl2 = [5, -8, -7, 3]; s2 = [10]
    itmp = gmshModelGeoAddCurveLoop(cl2, size(cl2, kind=c_size_t), 10, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s2, size(s2, kind=c_size_t), 11, ierr)

    ! In the same way, we can translate copies of the two surfaces 1 and 11 to
    ! the right with the following command:
    iv2 = [2, 1, 2, 11]
    call gmshModelGeoCopy(iv2, 4_8, ov, ov_n, ierr)

    call c_f_pointer(ov, pf_ov, [ov_n])
    call gmshModelGeoTranslate(pf_ov, ov_n, 0.12d0, 0d0, 0d0, ierr)

    print *, "New surfaces ", pf_ov(2), " and ", pf_ov(4)

    ! Volumes are the fourth type of elementary entities in Gmsh. In the same way
    ! one defines curve loops to build surfaces, one has to define surface loops
    ! (i.e. `shells') to build volumes. The following volume does not have holes
    ! and thus consists of a single surface loop:
    itmp = gmshModelGeoAddPoint(0.0d0, 0.30d0, 0.12d0, lc, 100, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.30d0, 0.12d0, lc, 101, ierr)
    itmp = gmshModelGeoAddPoint(0.1d0, 0.35d0, 0.12d0, lc, 102, ierr)

    ! We would like to retrieve the coordinates of point 5 to create point 103,
    ! so we synchronize the model, and use `getValue()'
    call gmshModelGeoSynchronize(ierr)

    call gmshModelGetValue(0, 5, iv0, size(iv0, kind=c_size_t), xyz, xyz_n, ierr)
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

    cl3 = [115, -111, 3, 110]; s3 = [118]
    itmp = gmshModelGeoAddCurveLoop(cl3, 4_8, 118, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s3, 1_8, 119, ierr)

    cl4 = [111, 116, -112, -7]; s4 = [120]
    itmp = gmshModelGeoAddCurveLoop(cl4, 4_8, 120, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s4, 1_8, 121, ierr)

    cl5 = [112, 117, -113, -8]; s5 = [122]
    itmp = gmshModelGeoAddCurveLoop(cl5, 4_8, 122, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s5, 1_8, 123, ierr)

    cl6 = [114, -110, 5, 113]; s6 = [124]
    itmp = gmshModelGeoAddCurveLoop(cl6, 4_8, 124, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s6, 1_8, 125, ierr)

    cl7 = [115, 116, 117, 114]; s7 = [126]
    itmp = gmshModelGeoAddCurveLoop(cl7, 4_8, 126, 0, ierr)
    itmp = gmshModelGeoAddPlaneSurface(s7, 1_8, 127, ierr)

    sl1 = [127, 119, 121, 123, 125, 11]; v1 = [128]
    itmp = gmshModelGeoAddSurfaceLoop(sl1, 6_8, 128, ierr)
    itmp = gmshModelGeoAddVolume(v1, 1_8, 129, ierr)

    ! When a volume can be extruded from a surface, it is usually easier to use
    ! the `extrude()' function directly instead of creating all the points,
    ! curves and surfaces by hand. For example, the following command extrudes
    ! the surface 11 along the z axis and automatically creates a new volume (as
    ! well as all the needed points, curves and surfaces). As expected, the
    ! function takes a vector of (dim, tag) pairs as input as well as the
    ! translation vector, and returns a vector of (dim, tag) pairs as output:
    numElements_n = 0
    heights_n = 0
    recombine=0
    call c_f_pointer(c_loc(pf_ov(3)), pf_ov3, [ov_n - 2])
    call gmshModelGeoExtrude(pf_ov3, 2_8, 0.0d0, 0.0d0, 0.12d0, ov2, ov2_n, &
                             numElements, numElements_n, heights, heights_n, recombine, ierr)

    ! Mesh sizes associated to geometrical points can be set by passing a vector
    ! of (dim, tag) pairs for the corresponding points:
    ss = [0, 103, 0, 105, 0, 109, 0, 102, 0, 28, 0, 24, 0, 6, 0, 5]
    call gmshModelGeoMeshSetSize(ss, 16_8, lc * 3, ierr)

    ! We finish by synchronizing the data from the built-in CAD kernel with the
    ! Gmsh model:
    call gmshModelGeoSynchronize(ierr)

    ! We group volumes 129 and 130 in a single physical group with tag `1' and
    ! name "The volume":
    g7 = [129, 130]
    itmp = gmshModelAddPhysicalGroup(3, g7, size(g7, kind=c_size_t), 1, ""//c_null_char, ierr)

    call gmshModelSetPhysicalName(3, 1, "The volume"//c_null_char, ierr)

    ! We finally generate and save the mesh:
    call gmshModelMeshGenerate(3, ierr)
    call gmshWrite("t2.msh"//c_null_char, ierr)

    ! call gmshFltkRun(ierr)

    call gmshFinalize(ierr)

    deallocate(tmp)
    deallocate(argv)

end program main

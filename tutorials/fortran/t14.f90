! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 14
!
!  Homology and cohomology computation
!
! ------------------------------------------------------------------------------

! Homology computation in Gmsh finds representative chains of (relative)
! (co)homology space bases using a mesh of a model%  The representative basis
! chains are stored in the mesh as physical groups of Gmsh, one for each chain.

program t14

use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
integer(c_int) :: ret, domain_tag, domain_physical_tag, terminals_physical_tag, &
                  boundary_physical_tag, complement_physical_tag, i
integer(c_int), allocatable :: e(:,:), terminal_tags(:), boundary_dimtags(:,:), &
                               boundary_tags(:), complement_tags(:)
real(c_double), parameter :: lc = .1
real(c_double) :: m, h
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

! Create an example geometry
call gmsh%model%add("t14")

m = 0.5  ! mesh size
h = 2  ! geometry height in the z-direction

ret = gmsh%model%geo%addPoint(00d0, 00d0, 0d0, m, 1)
ret = gmsh%model%geo%addPoint(10d0, 00d0, 0d0, m, 2)
ret = gmsh%model%geo%addPoint(10d0, 10d0, 0d0, m, 3)
ret = gmsh%model%geo%addPoint(00d0, 10d0, 0d0, m, 4)

ret = gmsh%model%geo%addPoint(4d0, 4d0, 0d0, m, 5)
ret = gmsh%model%geo%addPoint(6d0, 4d0, 0d0, m, 6)
ret = gmsh%model%geo%addPoint(6d0, 6d0, 0d0, m, 7)
ret = gmsh%model%geo%addPoint(4d0, 6d0, 0d0, m, 8)

ret = gmsh%model%geo%addPoint(2d0, 0d0, 0d0, m, 9)
ret = gmsh%model%geo%addPoint(8d0, 0d0, 0d0, m, 10)
ret = gmsh%model%geo%addPoint(2d0, 10d0, 0d0, m, 11)
ret = gmsh%model%geo%addPoint(8d0, 10d0, 0d0, m, 12)

ret = gmsh%model%geo%addLine(1, 9, 1)
ret = gmsh%model%geo%addLine(9, 10, 2)
ret = gmsh%model%geo%addLine(10, 2, 3)

ret = gmsh%model%geo%addLine(2, 3, 4)
ret = gmsh%model%geo%addLine(3, 12, 5)
ret = gmsh%model%geo%addLine(12, 11, 6)

ret = gmsh%model%geo%addLine(11, 4, 7)
ret = gmsh%model%geo%addLine(4, 1, 8)
ret = gmsh%model%geo%addLine(5, 6, 9)

ret = gmsh%model%geo%addLine(6, 7, 10)
ret = gmsh%model%geo%addLine(7, 8, 11)
ret = gmsh%model%geo%addLine(8, 5, 12)

ret = gmsh%model%geo%addCurveLoop([6, 7, 8, 1, 2, 3, 4, 5], 13)
ret = gmsh%model%geo%addCurveLoop([11, 12, 9, 10], 14)
ret = gmsh%model%geo%addPlaneSurface([13, 14], 15)

call gmsh%model%geo%extrude(reshape([2, 15], [2, 1]), 0d0, 0d0, h, outDimTags=e)

call gmsh%model%geo%synchronize()

! Create physical groups, which are used to define the domain of the
! (co)homology computation and the subdomain of the relative (co)homology
! computation.

! Whole domain
domain_tag = e(2,2)
domain_physical_tag = 1001
ret = gmsh%model%addPhysicalGroup(dim=3, tags=[domain_tag], tag=domain_physical_tag, name="Whole domain")

! Four "terminals" of the model
terminal_tags = [e(2,4), e(2,6), e(2,8), e(2,10)]
terminals_physical_tag = 2001
ret = gmsh%model%addPhysicalGroup(dim=2, &
                                  tags=terminal_tags, &
                                  tag=terminals_physical_tag, &
                                  name="Terminals")

! Find domain boundary tags
call gmsh%model%getBoundary(dimTags=reshape([3, domain_tag], [2, 1]), &
                            oriented=.false.,&
                            outDimTags=boundary_dimtags)

boundary_tags = boundary_dimtags(2,:)
complement_tags = pack(boundary_tags, .not.[(any(terminal_tags == boundary_tags(i)), i=1, size(boundary_tags))])

! Whole domain surface
boundary_physical_tag = 2002
ret = gmsh%model%addPhysicalGroup(dim=2, &
                                  tags=boundary_tags, &
                                  tag=boundary_physical_tag, &
                                  name="Boundary")

! Complement of the domain surface with respect to the four terminals
complement_physical_tag = 2003
ret = gmsh%model%addPhysicalGroup(dim=2, &
                                  tags=complement_tags, &
                                  tag=complement_physical_tag, &
                                  name="Complement")

! Find bases for relative homology spaces of the domain modulo the four
! terminals.
call gmsh%model%mesh%addHomologyRequest("Homology", domainTags=[domain_physical_tag], &
                                        subdomainTags=[terminals_physical_tag], &
                                        dims=[0, 1, 2, 3])

! Find homology space bases isomorphic to the previous bases: homology spaces
! modulo the non-terminal domain surface, a.k.a the thin cuts.
call gmsh%model%mesh%addHomologyRequest("Homology", domainTags=[domain_physical_tag], &
                                        subdomainTags=[complement_physical_tag], &
                                        dims=[0, 1, 2, 3])

! Find cohomology space bases isomorphic to the previous bases: cohomology
! spaces of the domain modulo the four terminals, a.k.a the thick cuts.
call gmsh%model%mesh%addHomologyRequest("Cohomology", domainTags=[domain_physical_tag], &
                                        subdomainTags=[terminals_physical_tag], &
                                        dims=[0, 1, 2, 3])

! more examples
! call gmsh%model%mesh%addHomologyRequest()
! call gmsh%model%mesh%addHomologyRequest("Homology", domainTags=[domain_physical_tag])
! call gmsh%model%mesh%addHomologyRequest("Homology", domainTags=[domain_physical_tag], &
!                                         subdomainTags=[boundary_physical_tag], &
!                                         dims=[0,1,2,3])

! Generate the mesh and perform the requested homology computations
call gmsh%model%mesh%generate(3)

! For more information, see M. Pellikka, S. Suuriniemi, L. Kettunen and
! C. Geuzaine. Homology and cohomology computation in finite element
! modeling. SIAM Journal on Scientific Computing 35(5), pp. 1195-1214, 2013.

call gmsh%write("t14.msh")

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t14

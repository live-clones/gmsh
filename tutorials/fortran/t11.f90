! ------------------------------------------------------------------------------
!
!  Gmsh Fortran tutorial 11
!
!  Unstructured quadrangular meshes
!
! ------------------------------------------------------------------------------

program t11

use, intrinsic :: iso_c_binding
use gmsh

implicit none
type(gmsh_t) :: gmsh
type(gmsh_model_mesh_field_t) :: field
integer(c_int) :: ret, p1, p2, p3, p4, l1, l2, l3, l4, cl, pl
real(c_double), parameter :: lc = .15
character(len=GMSH_API_MAX_STR_LEN) :: cmd

call gmsh%initialize()

call gmsh%model%add("t11")

! We have seen in tutorials `t3.f90' and `t6.f90' that extruded and transfinite
! meshes can be "recombined" into quads, prisms or hexahedra. Unstructured
! meshes can be recombined in the same way. Let's define a simple geometry with
! an analytical mesh size field:

p1 = gmsh%model%geo%addPoint(-1.25d0, -.5d0, 0d0)
p2 = gmsh%model%geo%addPoint(+1.25d0, -.5d0, 0d0)
p3 = gmsh%model%geo%addPoint(+1.25d0, 1.25d0, 0d0)
p4 = gmsh%model%geo%addPoint(-1.25d0, 1.25d0, 0d0)

l1 = gmsh%model%geo%addLine(p1, p2)
l2 = gmsh%model%geo%addLine(p2, p3)
l3 = gmsh%model%geo%addLine(p3, p4)
l4 = gmsh%model%geo%addLine(p4, p1)

cl = gmsh%model%geo%addCurveLoop([l1, l2, l3, l4])
pl = gmsh%model%geo%addPlaneSurface([cl])

call gmsh%model%geo%synchronize()

ret = field%add("MathEval", 1)
call field%setString(1, "F", "0.01*(1.0+30.*(y-x*x)*(y-x*x) + (1-x)*(1-x))")
call field%setAsBackgroundMesh(1)

! To generate quadrangles instead of triangles, we can simply add
call gmsh%model%mesh%setRecombine(2, pl)

! If we'd had several surfaces, we could have used the global option
! "Mesh.RecombineAll":
!
! gmsh%option.setNumber("Mesh.RecombineAll", 1)

! The default recombination algorithm is called "Blossom": it uses a minimum
! cost perfect matching algorithm to generate fully quadrilateral meshes from
! triangulations. More details about the algorithm can be found in the
! following paper: J.-F. Remacle, J. Lambrechts, B. Seny, E. Marchandise,
! A. Johnen and C. Geuzaine, "Blossom-Quad: a non-uniform quadrilateral mesh
! generator using a minimum cost perfect matching algorithm", International
! Journal for Numerical Methods in Engineering 89, pp. 1102-1119, 2012.

! For even better 2D (planar) quadrilateral meshes, you can try the
! experimental "Frontal-Delaunay for quads" meshing algorithm, which is a
! triangulation algorithm that enables to create right triangles almost
! everywhere: J.-F. Remacle, F. Henrotte, T. Carrier-Baudouin, E. Bechet,
! E. Marchandise, C. Geuzaine and T. Mouton. A frontal Delaunay quad mesh
! generator using the L^inf norm. International Journal for Numerical Methods
! in Engineering, 94, pp. 494-512, 2013. Uncomment the following line to try
! the Frontal-Delaunay algorithms for quads:
!
! gmsh%option.setNumber("Mesh.Algorithm", 8)

! The default recombination algorithm might leave some triangles in the mesh, if
! recombining all the triangles leads to badly shaped quads. In such cases, to
! generate full-quad meshes, you can either subdivide the resulting hybrid mesh
! (with `Mesh.SubdivisionAlgorithm' set to 1), or use the full-quad
! recombination algorithm, which will automatically perform a coarser mesh
! followed by recombination, smoothing and subdivision. Uncomment the following
! line to try the full-quad algorithm:
!
! gmsh%option.setNumber("Mesh.RecombinationAlgorithm", 2) ! or 3

! You can also set the subdivision step alone, with
!
! gmsh%option.setNumber("Mesh.SubdivisionAlgorithm", 1)

call gmsh%model%mesh%generate(2)

! Note that you could also apply the recombination algorithm and/or the
! subdivision step explicitly after meshing, as follows:
!
! gmsh%model%mesh%generate(2)
! gmsh%model%mesh%recombine()
! gmsh%option.setNumber("Mesh.SubdivisionAlgorithm", 1)
! gmsh%model%mesh%refine()

! Launch the GUI to see the results:
call get_command(cmd)
if (index(cmd, "-nopopup") == 0) call gmsh%fltk%run()

call gmsh%finalize()

end program t11

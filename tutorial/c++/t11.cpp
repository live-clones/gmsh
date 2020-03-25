// This file reimplements gmsh/tutorial/t11.geo in C++.

#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t11");

  int p1 = gmsh::model::geo::addPoint(-1.25, -.5, 0);
  int p2 = gmsh::model::geo::addPoint(1.25, -.5, 0);
  int p3 = gmsh::model::geo::addPoint(1.25, 1.25, 0);
  int p4 = gmsh::model::geo::addPoint(-1.25, 1.25, 0);

  int l1 = gmsh::model::geo::addLine(p1, p2);
  int l2 = gmsh::model::geo::addLine(p2, p3);
  int l3 = gmsh::model::geo::addLine(p3, p4);
  int l4 = gmsh::model::geo::addLine(p4, p1);

  int cl = gmsh::model::geo::addCurveLoop({l1, l2, l3, l4});
  int pl = gmsh::model::geo::addPlaneSurface({cl});

  gmsh::model::geo::synchronize();

  // add an analytical size field with tag 1
  gmsh::model::mesh::field::add("MathEval", 1);
  gmsh::model::mesh::field::setString
    (1, "F", "0.01*(1.0+30.*(y-x*x)*(y-x*x) + (1-x)*(1-x))");
  gmsh::model::mesh::field::setAsBackgroundMesh(1);

  // to generate quadrangles instead of triangles for the plane surface, add the
  // recombine constraint before meshing
  gmsh::model::mesh::setRecombine(2, pl);
  gmsh::model::mesh::generate(2);

  // you could also set the option "Mesh.RecombineAll"
  // gmsh::option::setNumber("Mesh.RecombineAll", 1);
  // gmsh::model::mesh::generate(2);

  // You could also apply the recombination algo after meshing
  // gmsh::model::mesh::generate(2);
  // gmsh::model::mesh::recombine();

  // Better 2D planar quadrilateral meshes with the Frontal-Delaunay for quads
  // algorithm:
  // gmsh::option::setNumber("Mesh.Algorithm", 8);
  // gmsh::model::mesh::generate(2);

  // Force a full-quad mesh with either option
  // gmsh::option::setNumber("Mesh.SubdivisionAlgorithm", 1);
  // gmsh::option::setNumber("Mesh.RecombinationAlgorithm", 2); // or 3
  // gmsh::model::mesh::generate(2);

  gmsh::finalize();
  return 0;
}

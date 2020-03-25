// This file reimplements gmsh/tutorial/t7.geo in C++.
//
// Background mesh

#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t7");

  // Copied from t1.cpp...
  double lc = 1e-2;
  factory::addPoint(0, 0, 0, lc, 1);
  factory::addPoint(.1, 0,  0, lc, 2);
  factory::addPoint(.1, .3, 0, lc, 3);
  factory::addPoint(0,  .3, 0, lc, 4);
  factory::addLine(1, 2, 1);
  factory::addLine(3, 2, 2);
  factory::addLine(3, 4, 3);
  factory::addLine(4, 1, 4);
  factory::addCurveLoop({4, 1, -2, 3}, 1);
  factory::addPlaneSurface({1}, 1);
  factory::synchronize();

  // add the background mesh file as a view
  gmsh::merge("../t7_bgmesh.pos");

  // add the post-processing view as a new size field
  int bg_field = model::mesh::field::add("PostView");
  model::mesh::field::setAsBackgroundMesh(bg_field);

  model::mesh::generate(2);
  gmsh::write("t7.msh");

  // show the mesh file
  gmsh::fltk::run();

  gmsh::finalize();
  return 0;
}

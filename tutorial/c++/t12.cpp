// This file reimplements gmsh/tutorial/t12.geo in C++.

#include <gmsh.h>

namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t12");

  double lc = 0.1;

  factory::addPoint(0, 0, 0, lc, 1);
  factory::addPoint(1, 0, 0, lc, 2);
  factory::addPoint(1, 1, 0.5, lc, 3);
  factory::addPoint(0, 1, 0.4, lc, 4);
  factory::addPoint(0.3, 0.2, 0, lc, 5);
  factory::addPoint(0, 0.01, 0.01, lc, 6);
  factory::addPoint(0, 0.02, 0.02, lc, 7);
  factory::addPoint(1, 0.05, 0.02, lc, 8);
  factory::addPoint(1, 0.32, 0.02, lc, 9);

  factory::addLine(1, 2, 1);
  factory::addLine(2, 8, 2);
  factory::addLine(8, 9, 3);
  factory::addLine(9, 3, 4);
  factory::addLine(3, 4, 5);
  factory::addLine(4, 7, 6);
  factory::addLine(7, 6, 7);
  factory::addLine(6, 1, 8);
  factory::addSpline({7, 5, 9}, 9);
  factory::addLine(6, 8, 10);

  factory::addCurveLoop({5, 6, 9, 4}, 11);
  factory::addSurfaceFilling({11}, 1);

  factory::addCurveLoop({-9, 3, 10, 7}, 13);
  factory::addSurfaceFilling({13}, 5);

  factory::addCurveLoop({-10, 2, 1, 8}, 15);
  factory::addSurfaceFilling({15}, 10);

  factory::synchronize();

  // set compound curve (dim 1); of curves 2, 3, 4
  gmsh::model::mesh::setCompound(1, {2, 3, 4});
  // set compound curve of curves 6, 7, 8
  gmsh::model::mesh::setCompound(1, {6, 7, 8});

  // set compound surface from surfaces 1, 5, 10
  gmsh::model::mesh::setCompound(2, {1, 5, 10});

  gmsh::fltk::run();

  gmsh::finalize();

  return 0;
}

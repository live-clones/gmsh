// This files reimplements gmsh/tutorial/t3.geo in C++.

#include <cmath>
#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t3");

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
  model::addPhysicalGroup(0, {1, 2}, 1);
  model::addPhysicalGroup(1, {1, 2}, 2);
  model::addPhysicalGroup(2, {1}, 6);
  model::setPhysicalName(2, 6, "My surface");
  // ...end of copy

  double h = 0.1, angle = 90.;
  std::vector<std::pair<int, int> > ov;

  // Extruding the mesh in addition to the geometry works as in .geo files: the
  // number of elements for each layer and the (end) height of each layer are
  // specified in two vectors.
  factory::extrude({{2,1}}, 0, 0, h, ov, {8,2}, {0.5,1});

  // Rotational and twisted extrusions are available as well with the built-in
  // CAD kernel. The last (optional) argument for the Extrude/Revolve/Twist
  // commands specifies whether the extruded mesh should be recombined or not.
  factory::revolve({{2,28}}, -0.1,0,0.1, 0,1,0, -M_PI/2, ov, {7});
  factory::twist({{2,50}}, 0,0.15,0.25, -2*h,0,0, 1,0,0, angle*M_PI/180.,
                 ov, {10}, {}, true);

  factory::synchronize();

  model::addPhysicalGroup(3, {1, 2, ov[1].second}, 101);

  model::mesh::generate(3);
  gmsh::write("t3.msh");
  gmsh::finalize();

  return 0;
}

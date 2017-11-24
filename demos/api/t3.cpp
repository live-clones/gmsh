// This files reimplements gmsh/tutorial/t3.geo in C++.

#include <cmath>
#include <gmsh.h>

using namespace gmsh;

int main(int argc, char **argv)
{
  initialize(argc, argv);
  option::setNumber("General.Terminal", 1);

  model::add("t3");

  // Copied from t1.cpp...
  double lc = 1e-2;
  model::geo::addPoint(0, 0, 0, lc, 1);
  model::geo::addPoint(.1, 0,  0, lc, 2);
  model::geo::addPoint(.1, .3, 0, lc, 3);
  model::geo::addPoint(0,  .3, 0, lc, 4);
  model::geo::addLine(1, 2, 1);
  model::geo::addLine(3, 2, 2);
  model::geo::addLine(3, 4, 3);
  model::geo::addLine(4, 1, 4);
  model::geo::addLineLoop({4, 1, -2, 3}, 1);
  model::geo::addPlaneSurface({1}, 1);
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
  model::geo::extrude({{2,1}}, 0, 0, h, ov, {8,2}, {0.5,1});

  // Rotational and twisted extrusions are available as well with the built-in
  // CAD kernel. The last (optional) argument for the Extrude/Revolve/Twist
  // commands specified whether the extruded mesh should be recombined or not.
  model::geo::revolve({{2,28}}, -0.1,0,0.1, 0,1,0, -M_PI/2, ov, {7});
  model::geo::twist({{2,50}}, 0,0.15,0.25, -2*h,0,0, 1,0,0, angle*M_PI/180.,
                    ov, {10}, {}, true);

  model::geo::synchronize();

  model::addPhysicalGroup(3, {1, 2, ov[1].second}, 101);

  model::mesh::generate(3);
  write("t3.msh");
  finalize();

  return 0;
}

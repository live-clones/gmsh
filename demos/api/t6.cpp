// This file reimplements gmsh/tutorial/t6.geo in C++.

#include <gmsh.h>

using namespace gmsh;

int main(int argc, char **argv)
{
  initialize();
  option::setNumber("General.Terminal", 1);

  model::add("t2");

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

  // Delete surface 1 and left boundary (line 4)
  model::geo::remove({{2,1}, {1,4}});

  // Replace left boundary with 3 new lines
  int p1 = model::geo::addPoint(-0.05, 0.05, 0, lc);
  int p2 = model::geo::addPoint(-0.05, 0.1, 0, lc);
  int l1 = model::geo::addLine(1, p1);
  int l2 = model::geo::addLine(p1, p2);
  int l3 = model::geo::addLine(p2, 4);

  // Recreate surface
  model::geo::addLineLoop({2, -1, l1, l2, l3, -3}, 2);
  model::geo::addPlaneSurface({-2}, 1);

  // Put 20 points with a refinement toward the extremities on curve 2
  model::geo::mesh::setTransfiniteLine(2, 20, "Bump", 0.05);

  // Put 20 points total on combination of curves l1, l2 and l3 (beware that the
  // points p1 and p2 are shared by the curves, so we do not create 6 + 6 + 10 =
  // 22 points, but 20!)
  model::geo::mesh::setTransfiniteLine(l1, 6);
  model::geo::mesh::setTransfiniteLine(l2, 6);
  model::geo::mesh::setTransfiniteLine(l3, 10);

  // Put 30 points following a geometric progression on curve 1 (reversed) and
  // on curve 3
  model::geo::mesh::setTransfiniteLine(1, 30, "Progression", -1.2);
  model::geo::mesh::setTransfiniteLine(3, 30, "Progression", 1.2);

  // Define the Surface as transfinite, by specifying the four corners of the
  // transfinite interpolation
  model::geo::mesh::setTransfiniteSurface(1, "Left", {1,2,3,4});

  // Recombine the triangles into quads
  model::geo::mesh::setRecombine(2, 1);

  // Apply an elliptic smoother to the grid
  option::setNumber("Mesh.Smoothing", 100);
  model::addPhysicalGroup(2, {1}, 1);

  // When the surface has only 3 or 4 control points, the transfinite constraint
  // can be applied automatically (without specifying the corners explictly).
  model::geo::addPoint(0.2, 0.2, 0, 1.0, 7);
  model::geo::addPoint(0.2, 0.1, 0, 1.0, 8);
  model::geo::addPoint(0, 0.3, 0, 1.0, 9);
  model::geo::addPoint(0.25, 0.2, 0, 1.0, 10);
  model::geo::addPoint(0.3, 0.1, 0, 1.0, 11);
  model::geo::addLine(8, 11, 10);
  model::geo::addLine(11, 10, 11);
  model::geo::addLine(10, 7, 12);
  model::geo::addLine(7, 8, 13);
  model::geo::addLineLoop({13, 10, 11, 12}, 14);
  model::geo::addPlaneSurface({14}, 15);
  for(int i = 10; i <= 13; i++)
    model::geo::mesh::setTransfiniteLine(i, 10);
  model::geo::mesh::setTransfiniteSurface(15);

  model::addPhysicalGroup(2, {15}, 2);

  model::geo::synchronize();
  model::mesh::generate(2);
  write("t6.msh");
  finalize();
  return 0;
}

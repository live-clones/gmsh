// This file reimplements gmsh/tutorial/t2.geo in C++. Comments focus on the new
// API functions used, compared to the ones introduced in t1.cpp.

#include <gmsh.h>

// give nice shortcuts for some namespaces
namespace model = gmsh::model;
namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  // If argc/argv are passed, Gmsh will parse the commandline in the same way as
  // the standalone Gmsh app.
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t2");

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

  factory::addPoint(0, .4, 0, lc, 5);
  factory::addLine(4, 5, 5);

  // Geometrical transformations take a vector of pairs of integers as first
  // argument, which contains the list of entities, represented by (dimension,
  // tag) pairs. Here we thus translate point 3 (dimension=0, tag=3), by
  // dx=-0.05, dy=0, dz=0.
  factory::translate({{0, 3}}, -0.05, 0, 0);

  // The "Duplicata" functionality in .geo files is handled by
  // model::geo::copy(), which takes a vector of (dim, tag) pairs as input, and
  // returns another vector of (dim, tag) pairs.
  std::vector<std::pair<int, int> > ov;
  factory::copy({{0, 3}}, ov);
  factory::translate(ov, 0, 0.1, 0);

  factory::addLine(3, ov[0].second, 7);
  factory::addLine(ov[0].second, 5, 8);
  factory::addCurveLoop({5,-8,-7,3}, 10);
  factory::addPlaneSurface({10}, 11);

  factory::copy({{2, 1}, {2, 11}}, ov);
  factory::translate(ov, 0.12, 0, 0);

  std::printf("New surfaces '%d' and '%d'\n", ov[0].second, ov[1].second);

  factory::addPoint(0., 0.3, 0.13, lc, 100);
  factory::addPoint(0.08, 0.3, 0.1, lc, 101);
  factory::addPoint(0.08, 0.4, 0.1, lc, 102);
  factory::addPoint(0., 0.4, 0.13, lc, 103);

  factory::addLine(4, 100, 110);
  factory::addLine(3, 101, 111);
  factory::addLine(6, 102, 112);
  factory::addLine(5, 103, 113);
  factory::addLine(103, 100, 114);
  factory::addLine(100, 101, 115);
  factory::addLine(101, 102, 116);
  factory::addLine(102, 103, 117);

  factory::addCurveLoop({115, -111, 3, 110}, 118);
  factory::addPlaneSurface({118}, 119);
  factory::addCurveLoop({111, 116, -112, -7}, 120);
  factory::addPlaneSurface({120}, 121);
  factory::addCurveLoop({112, 117, -113, -8}, 122);
  factory::addPlaneSurface({122}, 123);
  factory::addCurveLoop({114, -110, 5, 113}, 124);
  factory::addPlaneSurface({124}, 125);
  factory::addCurveLoop({115, 116, 117, 114}, 126);
  factory::addPlaneSurface({126}, 127);

  // The API to create surface loops ("shells") and volumes is similar to the
  // one used to create curve loops and surfaces.
  factory::addSurfaceLoop({127, 119, 121, 123, 125, 11}, 128);
  factory::addVolume({128}, 129);

  // Extrusion works as expected, by providing a vector of (dim, tag) pairs as
  // input, the translation vector, and a vector of (dim, tag) pairs as output.
  std::vector<std::pair<int, int> > ov2;
  factory::extrude({ov[1]}, 0, 0, 0.12, ov2);

  // Mesh sizes associated to geometrical points can be set by passing a vector
  // of (dim, tag) pairs for the corresponding points.
  factory::mesh::setSize({{0,103}, {0,105}, {0,109}, {0,102}, {0,28},
                          {0, 24}, {0,6}, {0,5}}, lc * 3);

  model::addPhysicalGroup(3, {129,130}, 1);
  model::setPhysicalName(3, 1, "The volume");

  factory::synchronize();

  model::mesh::generate(3);

  gmsh::write("t2.msh");

  gmsh::finalize();
  return 0;
}

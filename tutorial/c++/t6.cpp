// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 6
//
//  Transfinite meshes
//
// -----------------------------------------------------------------------------

#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  gmsh::initialize();
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

  // Delete the surface and the left line, and replace the line with 3 new ones:
  factory::remove({{2,1}, {1,4}});

  int p1 = factory::addPoint(-0.05, 0.05, 0, lc);
  int p2 = factory::addPoint(-0.05, 0.1, 0, lc);
  int l1 = factory::addLine(1, p1);
  int l2 = factory::addLine(p1, p2);
  int l3 = factory::addLine(p2, 4);

  // Create surface:
  factory::addCurveLoop({2, -1, l1, l2, l3, -3}, 2);
  factory::addPlaneSurface({-2}, 1);

  // The `setTransfiniteCurve()' meshing constraints explicitly specifies the
  // location of the nodes on the curve. For example, the following command
  // forces 20 uniformly placed nodes on curve 2 (including the nodes on the two
  // end points):
  factory::mesh::setTransfiniteCurve(2, 20, "Bump", 0.05);

  // Let's put 20 points total on combination of curves `l1', `l2' and `l3'
  // (beware that the points `p1' and `p2' are shared by the curves, so we do
  // not create 6 + 6 + 10 = 22 nodes, but 20!)
  factory::mesh::setTransfiniteCurve(l1, 6);
  factory::mesh::setTransfiniteCurve(l2, 6);
  factory::mesh::setTransfiniteCurve(l3, 10);

  // Finally, we put 30 nodes following a geometric progression on curve 1
  // (reversed) and on curve 3: Put 30 points following a geometric progression
  factory::mesh::setTransfiniteCurve(1, 30, "Progression", -1.2);
  factory::mesh::setTransfiniteCurve(3, 30, "Progression", 1.2);

  // The `setTransfiniteSurface()' meshing constraint uses a transfinite
  // interpolation algorithm in the parametric plane of the surface to connect
  // the nodes on the boundary using a structured grid. If the surface has more
  // than 4 corner points, the corners of the transfinite interpolation have to
  // be specified by hand:
  factory::mesh::setTransfiniteSurface(1, "Left", {1,2,3,4});

  // To create quadrangles instead of triangles, one can use the `setRecombine'
  // constraint:
  factory::mesh::setRecombine(2, 1);

  // When the surface has only 3 or 4 points on its boundary the list of corners
  // can be omitted in the `setTransfiniteSurface()' call:
  factory::addPoint(0.2, 0.2, 0, 1.0, 7);
  factory::addPoint(0.2, 0.1, 0, 1.0, 8);
  factory::addPoint(0, 0.3, 0, 1.0, 9);
  factory::addPoint(0.25, 0.2, 0, 1.0, 10);
  factory::addPoint(0.3, 0.1, 0, 1.0, 11);
  factory::addLine(8, 11, 10);
  factory::addLine(11, 10, 11);
  factory::addLine(10, 7, 12);
  factory::addLine(7, 8, 13);
  factory::addCurveLoop({13, 10, 11, 12}, 14);
  factory::addPlaneSurface({14}, 15);
  for(int i = 10; i <= 13; i++)
    factory::mesh::setTransfiniteCurve(i, 10);
  factory::mesh::setTransfiniteSurface(15);

  // The way triangles are generated can be controlled by specifying "Left",
  // "Right" or "Alternate" in `setTransfiniteSurface()' command. Try e.g.
  //
  // factory::mesh::setTransfiniteSurface(15, "Alternate");

  // Finally we apply an elliptic smoother to the grid to have a more regular
  // mesh:
  gmsh::option::setNumber("Mesh.Smoothing", 100);

  factory::synchronize();
  model::mesh::generate(2);
  gmsh::write("t6.msh");
  gmsh::finalize();
  return 0;
}

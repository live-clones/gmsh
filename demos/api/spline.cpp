#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::occ;

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("spline");

  for(unsigned int i = 1; i < 11; i++)
    factory::addPoint(i + 1, sin(i/9.*2.*M_PI), 0, 0.1, i);

  factory::addSpline({1,2,3,4,5,6,7,8,9,10}, 1);
  factory::addBSpline({1,2,3,4,5,6,7,8,9,10}, 2);
  factory::addBezier({1,2,3,4,5,6,7,8,9,10}, 3);

  factory::addPoint(0.2,-1.6,0,0.1, 101);
  factory::addPoint(1.2,-1.6,0,0.1, 102);
  factory::addPoint(1.2,-1.1,0,0.1, 103);
  factory::addPoint(0.3,-1.1,0,0.1, 104);
  factory::addPoint(0.7,-1,0,0.1, 105);

  // periodic bspline through the control points
  factory::addSpline({103,102,101,104,105,103}, 100);

  // periodic bspline from given control points and default parameters - will
  // create a new vertex
  factory::addBSpline({103,102,101,104,105,103}, 101);

  // general bspline with explicit degree, knots and multiplicities
  factory::addPoint(0,-2,0,0.1,201);
  factory::addPoint(1,-2,0,0.1,202);
  factory::addPoint(1,-3,0,0.1,203);
  factory::addPoint(0,-3,0,0.1,204);
  factory::addBSpline({201,202,203,204}, 200, 2, {}, {0,0.5,1}, {3,1,3});

  factory::synchronize();
  gmsh::fltk::run();
  gmsh::finalize();
  return 0;
}

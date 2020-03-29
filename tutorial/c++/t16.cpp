/*******************************************************************************
 *
 *  Gmsh C++ tutorial 16
 *
 *  Constructive Solid Geometry, OpenCASCADE geometry kernel
 *
 *******************************************************************************/

// Instead of constructing a model in a bottom-up fashion with Gmsh's built-in
// geometry kernel, starting with version 3 Gmsh allows you to directly use
// alternative geometry kernels. Here we will use the OpenCASCADE kernel.

#include <iostream>
#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::occ;

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t16");

  // Let's build the same model as in `t5.geo', but using constructive solid
  // geometry.

  // We can log all messages for further processing with:
  gmsh::logger::start();

  // We first create two cubes:
  try {
    factory::addBox(0,0,0, 1,1,1, 1);
    factory::addBox(0,0,0, 0.5,0.5,0.5, 2);
  }
  catch(...) {
    gmsh::logger::write("Could not create OpenCASCADE shapes: bye!");
    return 0;
  }

  // We apply a boolean difference to create the "cube minus one eigth" shape:
  std::vector<std::pair<int, int> > ov;
  std::vector<std::vector<std::pair<int, int> > > ovv;
  factory::cut({{3,1}}, {{3,2}}, ov, ovv, 3);

  // Boolean operations with OpenCASCADE always create new entities. By default
  // the extra arguments `removeObject' and `removeTool' in `occ::cut()' are set
  // to `true', which will delete the original entities.

  // We then create the five spheres:
  double x = 0, y = 0.75, z = 0, r = 0.09 ;
  std::vector<std::pair<int, int> > holes;
  for(int t = 1; t <= 5; t++){
    x += 0.166 ;
    z += 0.166 ;
    factory::addSphere(x,y,z,r, 3 + t);
    holes.push_back({3, 3 + t});
  }

  // If we had wanted five empty holes we would have used `cut()' again. Here we
  // want five spherical inclusions, whose mesh should be conformal with the
  // mesh of the cube: we thus use `fragment()', which intersects all volumes in
  // a conformal manner (without creating duplicate interfaces):
  factory::fragment({{3,3}}, holes, ov, ovv);

  factory::synchronize();

  // When the boolean operation leads to simple modifications of entities, and
  // if one deletes the original entities, Gmsh tries to assign the same tag to
  // the new entities. (This behavior is governed by the
  // `Geometry.OCCBooleanPreserveNumbering' option.)

  // Here the `Physical Volume' definitions can thus be made for the 5 spheres
  // directly, as the five spheres (volumes 4, 5, 6, 7 and 8), which will be
  // deleted by the fragment operations, will be recreated identically (albeit
  // with new surfaces) with the same tags.:
  for(int i = 1; i <= 5; i++)
    gmsh::model::addPhysicalGroup(3, {3 + i}, i);

  // The tag of the cube will change though, so we need to access it
  // programmatically:
  gmsh::model::addPhysicalGroup(3, {ov[ov.size() - 1].second}, 10);

  // Creating entities using constructive solid geometry is very powerful, but can
  // lead to small pratical issues for e.g. setting mesh sizes at points, or
  // identifying boundaries.

  // To identify point or other bounding entities you can take advantage of the
  // `getEntities()', `getBoundary()' and `getEntitiesInBoundingBox()'
  // functions:

  double lcar1 = .1;
  double lcar2 = .0005;
  double lcar3 = .055;

  // Assign a mesh size to all the points:
  model::getEntities(ov, 0);
  model::mesh::setSize(ov, lcar1);

  // Override this constraint on the points of the five spheres:
  model::getBoundary(holes, ov, false, false, true);
  model::mesh::setSize(ov, lcar3);

  // Select the corner point by searching for it geometrically:
  double eps = 1e-3;
  model::getEntitiesInBoundingBox(0.5-eps, 0.5-eps, 0.5-eps,
                                  0.5+eps, 0.5+eps, 0.5+eps, ov, 0);
  model::mesh::setSize(ov, lcar2);

  model::mesh::generate(3);

  gmsh::write("t16.msh");

  // Additional examples created with the OpenCASCADE geometry kernel are
  // available in `t18.cpp', `t19.cpp' as well as in the `demos/api' directory.

  std::vector<std::string> log;
  gmsh::logger::get(log);
  std::cout << "Logger has recorded " << log.size() << " lines" << std::endl;
  gmsh::logger::stop();

  gmsh::finalize();
  return 0;
}

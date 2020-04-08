// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 7
//
//  Background meshes
//
// -----------------------------------------------------------------------------

#include <gmsh.h>

// Mesh sizes can be specified very accurately by providing a background mesh,
// i.e., a post-processing view that contains the target characteristic lengths.

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t7");

  // Create a simple rectangular geometry
  double lc = 1e-2;
  gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
  gmsh::model::geo::addPoint(.1, 0,  0, lc, 2);
  gmsh::model::geo::addPoint(.1, .3, 0, lc, 3);
  gmsh::model::geo::addPoint(0,  .3, 0, lc, 4);
  gmsh::model::geo::addLine(1, 2, 1);
  gmsh::model::geo::addLine(3, 2, 2);
  gmsh::model::geo::addLine(3, 4, 3);
  gmsh::model::geo::addLine(4, 1, 4);
  gmsh::model::geo::addCurveLoop({4, 1, -2, 3}, 1);
  gmsh::model::geo::addPlaneSurface({1}, 1);

  gmsh::model::geo::synchronize();

  // Merge a post-processing view containing the target mesh sizes
  try {
    gmsh::merge("../t7_bgmesh.pos");
  }
  catch(...) {
    gmsh::logger::write("Could not load background mesh: bye!");
    gmsh::finalize();
    return 0;
  }

  // Add the post-processing view as a new size field
  int bg_field = gmsh::model::mesh::field::add("PostView");

  // Apply the view as the current background mesh
  gmsh::model::mesh::field::setAsBackgroundMesh(bg_field);

  // Background meshes are one particular case of general mesh size fields: see
  // `t10.cpp' for more mesh size field examples.

  gmsh::model::mesh::generate(2);
  gmsh::write("t7.msh");

  // Show the mesh
  // gmsh::fltk::run();

  gmsh::finalize();
  return 0;
}

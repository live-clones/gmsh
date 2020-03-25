// This file reimplements gmsh/tutorial/t17.geo in C++.

#include <gmsh.h>
#include <math.h>

namespace factory = gmsh::model::geo;
namespace model = gmsh::model;

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::occ::addRectangle(-1, -1, 0, 2, 2);
  gmsh::model::occ::synchronize();

  // add a post-processing view to use as a size field
  try {
    gmsh::merge("../t17_bgmesh.pos");
  }
  catch(...) {
    gmsh::logger::write("Could not load background mesh: bye!");
    gmsh::finalize();
    return 0;
  }

  int bg_field = gmsh::model::mesh::field::add("PostView");
  gmsh::model::mesh::field::setAsBackgroundMesh(bg_field);

  // use bamg
  gmsh::option::setNumber("Mesh.SmoothRatio", 3);
  gmsh::option::setNumber("Mesh.AnisoMax", 1000);
  gmsh::option::setNumber("Mesh.Algorithm", 7);

  gmsh::model::mesh::generate(2);

  gmsh::write("t17.msh");

  gmsh::finalize();
  return 0;
}

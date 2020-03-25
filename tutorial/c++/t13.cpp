// This file reimplements gmsh/tutorial/t13.geo in C++.

#include <gmsh.h>
#include <math.h>

namespace factory = gmsh::model::geo;

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t13");

  // Let's merge an STL mesh that we would like to remesh (from the parent
  // directory):
  try {
    gmsh::merge("../t13_data.stl");
  }
  catch(...) {
    gmsh::logger::write("Could not load STL mesh: bye!");
    gmsh::finalize();
    return 0;
  }

  // We first classify ("color") the surfaces by splitting the original surface
  // along sharp geometrical features. This will create new discrete surfaces,
  // curves and points.

  double angle = 40; // Angle for surface detection
  bool forceParametrizablePatches = false; // Create surfaces guaranteed to be parametrizable?
  bool includeBoundary = true;

  gmsh::model::mesh::classifySurfaces(angle * M_PI / 180.,
                                      includeBoundary,
                                      forceParametrizablePatches);

  // Create a geometry for all the discrete curves and surfaces in the mesh, by
  // computing a parametrization for each one
  gmsh::model::mesh::createGeometry();

  // Create a volume from all the surfaces
  std::vector<std::pair<int, int> > s;
  gmsh::model::getEntities(s, 2);

  std::vector<int> sl;
  for(std::size_t i = 0; i < s.size(); i++) sl.push_back(s[i].second);
  int l = gmsh::model::geo::addSurfaceLoop(sl);

  gmsh::model::geo::addVolume({l});

  gmsh::model::geo::synchronize();

  // element size imposed by a size field, just because we can :-)
  bool funny = true;//false;
  int f = gmsh::model::mesh::field::add("MathEval");
  if(funny)
    gmsh::model::mesh::field::setString(f, "F", "2*Sin((x+y)/5) + 3");
  else
    gmsh::model::mesh::field::setString(f, "F", "4");
  gmsh::model::mesh::field::setAsBackgroundMesh(f);

  gmsh::model::mesh::generate(3);

  gmsh::finalize();
  return 0;
}

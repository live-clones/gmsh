// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 13
//
//  Remeshing an STL file without an underlying CAD model
//
// -----------------------------------------------------------------------------

#include <gmsh.h>
#include <math.h>

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t13");

  // Let's merge an STL mesh that we would like to remesh (from the parent
  // directory):
  try {
    gmsh::merge("../t13_data.stl");
  } catch(...) {
    gmsh::logger::write("Could not load STL mesh: bye!");
    gmsh::finalize();
    return 0;
  }

  // We first classify ("color") the surfaces by splitting the original surface
  // along sharp geometrical features. This will create new discrete surfaces,
  // curves and points.


  // Angle between two triangles above which an edge is considered as sharp:
  double angle = 40;

  // For complex geometries, patches can be too complex, too elongated or too
  // large to be parametrized; setting the following option will force the
  // creation of patches that are amenable to reparametrization:
  bool forceParametrizablePatches = false;

  // For open surfaces include the boundary edges in the classification process:
  bool includeBoundary = true;

  // Force curves to be split on given angle:
  double curveAngle = 180;

  gmsh::model::mesh::classifySurfaces(angle * M_PI / 180., includeBoundary,
                                      forceParametrizablePatches,
                                      curveAngle * M_PI / 180.);

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

  // We specify element sizes imposed by a size field, just because we can :-)
  bool funny = true; // false;
  int f = gmsh::model::mesh::field::add("MathEval");
  if(funny)
    gmsh::model::mesh::field::setString(f, "F", "2*Sin((x+y)/5) + 3");
  else
    gmsh::model::mesh::field::setString(f, "F", "4");
  gmsh::model::mesh::field::setAsBackgroundMesh(f);

  gmsh::model::mesh::generate(3);

  // gmsh::fltk::run();

  gmsh::finalize();
  return 0;
}

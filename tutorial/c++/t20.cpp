// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 20
//
//  STEP import and manipulation, geometry partitioning
//
// -----------------------------------------------------------------------------

// The OpenCASCADE geometry kernel allows to import STEP files and to modify
// them. In this tutorial we will load a STEP geometry and partition it into
// slices.

#include <cmath>
#include <cstdlib>
#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t20");

  // Load a STEP file (using `importShapes' instead of `merge' allows to
  // directly retrieve the tags of the highest dimensional imported entities):
  std::vector<std::pair<int, int> > v;
  gmsh::model::occ::importShapes("../t20_data.step", v);

  // If we had specified
  //
  // gmsh::option::setString("OCCTargetUnit", "M");
  //
  // before merging the STEP file, OpenCASCADE would have converted the units to
  // meters (instead of the default, which is millimeters).

  // Get the bounding box of the volume:
  gmsh::model::occ::synchronize();
  double xmin, ymin, zmin, xmax, ymax, zmax;
  gmsh::model::getBoundingBox(v[0].first, v[0].second, xmin, ymin, zmin,
                              xmax, ymax, zmax);

  // Note that the synchronization step can be avoided in Gmsh >= 4.6 by using
  // `gmsh::model::occ::getBoundingBox()' instead of
  // `gmsh::model::getBoundingBox()'.

  // We want to slice the model into N slices, and either keep the volume slices
  // or just the surfaces obtained by the cutting:

  int N = 5; // Number of slices
  bool surf = false; // Keep only surfaces?

  double dz = (zmax - zmin) / N;

  // Define the cutting planes
  for(int i = 1; i < N; i++)
    gmsh::model::occ::addRectangle(xmin, ymin, zmin + i * dz,
                                   xmax-xmin, ymax-ymin,
                                   1000 + i);

  // Fragment (i.e. intersect) the volume with all the cutting planes:
  std::vector<std::pair<int, int> > p;
  for(int i = 1000 + 1; i < 1000 + N; i++)
    p.push_back(std::pair<int, int>(2, i));
  std::vector<std::pair<int, int> > ov;
  std::vector<std::vector<std::pair<int, int> > > ovv;
  gmsh::model::occ::fragment(v, p, ov, ovv);

  // Now remove all the surfaces (and their bounding entities) that are not on
  // the boundary of a volume, i.e. the parts of the cutting planes that "stick
  // out" of the volume:

  gmsh::model::occ::synchronize();

  std::vector<std::pair<int, int> > tmp;
  gmsh::model::getEntities(tmp, 2);
  gmsh::model::occ::remove(tmp, true);

  // The previous synchronization step can be avoided in Gmsh >= 4.6 by using
  // `gmsh::model::occ::getEntities()' instead of `gmsh::model::getEntities()'.

  gmsh::model::occ::synchronize();

  if(surf) {
    // If we want to only keep the surfaces, retrieve the surfaces in bounding
    // boxes around the cutting planes...
    double eps = 1e-4;
    std::vector<std::pair<int, int> > s;
    for(int i = 1; i < N; i++) {
      std::vector<std::pair<int, int> > e;
      gmsh::model::getEntitiesInBoundingBox
        (xmin-eps,ymin-eps,zmin + i * dz - eps,
         xmax+eps,ymax+eps,zmin + i * dz + eps, e, 2);
      s.insert(s.end(), e.begin(), e.end());
    }
    // ...and remove all the other entities (here directly in the model, as we
    // won't modify any OpenCASCADE entities later on):
    std::vector<std::pair<int, int> > dels;
    gmsh::model::getEntities(dels, 2);
    for(auto it = s.begin(); it != s.end(); ++it) {
      auto it2 = std::find(dels.begin(), dels.end(), *it);
      if(it2 != dels.end()) dels.erase(it2);
    }
    gmsh::model::getEntities(tmp, 3);
    gmsh::model::removeEntities(tmp);
    gmsh::model::removeEntities(dels);
    gmsh::model::getEntities(tmp, 1);
    gmsh::model::removeEntities(tmp);
    gmsh::model::getEntities(tmp, 0);
    gmsh::model::removeEntities(tmp);
  }

  // Finally, let's specify a global mesh size and mesh the partitioned model:
  gmsh::option::setNumber("Mesh.CharacteristicLengthMin", 3);
  gmsh::option::setNumber("Mesh.CharacteristicLengthMax", 3);
  gmsh::model::mesh::generate(3);
  gmsh::write("t20.msh");

  // Show the result:
  // gmsh::fltk::run();

  gmsh::finalize();
  return 0;
}

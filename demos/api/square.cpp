#include <gmsh.h>
int main()
{
  gmsh::initialize();
  gmsh::model::occ::addRectangle(0, 0, 0, 1, 1, 1);
  gmsh::model::occ::synchronize();
  gmsh::model::mesh::setTransfiniteSurface(1);
  gmsh::option::setNumber("Mesh.CharacteristicLengthMin", 1);
  gmsh::option::setNumber("Mesh.CharacteristicLengthMax", 1);
  gmsh::model::mesh::generate();
  gmsh::fltk::run();
  gmsh::finalize();
}

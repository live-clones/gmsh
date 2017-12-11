#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);
  gmsh::model::add("square");
  gmsh::model::occ::addRectangle(0, 0, 0, 1, 1, 100);
  gmsh::model::occ::synchronize();
  gmsh::model::mesh::setTransfiniteSurface(100);
  gmsh::model::mesh::generate(2);
  gmsh::plugin::run("NewView");
  std::cout << "before get" << std::endl;
  std::string type; std::vector<int> tags;
  std::vector<std::vector<double> > data; double time; int numComp;
  gmsh::view::getModelData(0, 0, type, tags, data, time, numComp);
  std::cout << "after get" << std::endl;
  gmsh::finalize();
  return 0;
}

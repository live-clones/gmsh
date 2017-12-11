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
  gmsh::plugin::setNumber("QuadratureData", "Order", 5);
  gmsh::plugin::setNumber("QuadratureData", "Dimension", 2);
  gmsh::plugin::setNumber("QuadratureData", "ViewTag", 90);
  gmsh::plugin::run("QuadratureData");
  std::cout << "before get" << std::endl;
  std::string type; std::vector<int> tags;
  std::vector<std::vector<double> > data; double time; int numComp;
  gmsh::view::getModelData(90, 0, type, tags, data, time, numComp);
  std::cout << "after get" << std::endl;
  gmsh::view::remove(90);
  gmsh::finalize();
  return 0;
}

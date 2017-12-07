#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  // Copied from discrete.cpp...
  gmsh::model::add("test");
  gmsh::model::addDiscreteEntity(2, 1);
  gmsh::model::mesh::setVertices(2, 1, {1, 2, 3, 4},
                                 {0., 0., 0.,
                                  1., 0., 0.,
                                  1., 1., 0.,
                                  0., 1., 0.});
  gmsh::model::mesh::setElements(2, 1, {2}, {{1, 2}},
                                 {{1, 2, 3,
                                   1, 3, 4}});
  // ... end of copy

  // create a view with some data
  int t = gmsh::view::add("some data");
  gmsh::view::addModelData(t, "test", "NodeData", 0,
                           {1, 2, 3, 4},
                           {{1.},{10.},{20.},{1.}});

  // compute the iso-curve at value 11
  gmsh::plugin::setNumber("Isosurface", "Value", 11.);
  gmsh::plugin::run("Isosurface");

  // delete the source view
  gmsh::view::remove(t);

  // check how many views the plugin created (a priori, a single one)
  std::vector<int> tags;
  gmsh::view::getTags(tags);
  if(tags.size() == 1)
    gmsh::view::write(tags[0], "iso.msh");

  gmsh::finalize();
  return 0;
}


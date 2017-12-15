#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("test");

  // add discrete surface with tag 1
  gmsh::model::addDiscreteEntity(2, 1);

  // add 4 mesh vertices
  gmsh::model::mesh::setVertices(2, 1,
                                 {1, 2, 3, 4}, // vertex tags: 1, 2, 3, and 4
                                 {0., 0., 0., // coordinates of vertex 1
                                  1., 0., 0., // coordinates of vertex 2
                                  1., 1., 0., // ...
                                  0., 1., 0.});

  // add 2 triangles
  gmsh::model::mesh::setElements(2, 1,
                                 {2}, // single type : 3-node triangle
                                 {{1, 2}}, // triangle tags: 1 and 2
                                 {{1, 2, 3, // triangle 1: vertices 1, 2, 3
                                   1, 3, 4}}); // triangle 2: vertices 1, 3, 4

  // export the mesh ; use explore.cpp to read and examine the mesh
  gmsh::write("test.msh");

  gmsh::finalize();
  return 0;
}

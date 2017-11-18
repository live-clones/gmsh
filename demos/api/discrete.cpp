#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("test");

  // add discrete surface with tag 1
  gmshModelAddDiscreteEntity(2, 1);

  // add 4 mesh vertices
  gmshModelSetMeshVertices(2, 1,
                           {1, 2, 3, 4}, // vertex tags: 1, 2, 3, and 4
                           {0., 0., 0., // coordinates of vertex 1
                            1., 0., 0., // coordinates of vertex 2
                            1., 1., 0., // ...
                            0., 1., 0.});

  // add 2 triangles
  gmshModelSetMeshElements(2, 1,
                           {2}, // single type : 3-node triangle
                           {{1, 2}}, // triangle tags: 1 and 2
                           {{1, 2, 3, // triangle 1: vertices 1, 2, 3
                             1, 3, 4}}); // triangle 2: vertices 1, 3, 4

  // export the mesh ; use explore.cpp to read and examine the mesh
  gmshExport("test.msh");

  gmshFinalize();
  return 0;
}

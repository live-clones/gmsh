#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);

  // Copied from discrete.cpp...
  gmshModelCreate("test");
  gmshModelAddDiscreteEntity(2, 1);
  gmshModelSetMeshVertices(2, 1, {1, 2, 3, 4},
                           {0., 0., 0.,
                            1., 0., 0.,
                            1., 1., 0.,
                            0., 1., 0.});
  gmshModelSetMeshElements(2, 1, {2}, {{1, 2}},
                           {{1, 2, 3,
                             1, 3, 4}});
  // ... end of copy


  // Create a new post-processing view
  int t = gmshViewCreate("some data");

  // add 10 steps of model-based data, on the nodes of the mesh
  for(int step = 0; step < 10; step++)
    gmshViewAddModelData(t, "test", "NodeData",
                         {1, 2, 3, 4}, // tags of nodes
                         {{10.},{10.},{12.+step},{13.+step}}, // data, per node
                         step);

  gmshViewExport(t, "data.msh");

  gmshFinalize();
  return 0;
}


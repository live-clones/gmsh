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

  // create a view with some data
  int t = gmshViewCreate("some data");
  gmshViewAddModelData(t, "test", "NodeData",
                       {1, 2, 3, 4},
                       {{1.},{10.},{20.},{1.}});

  // compute the iso-curve at value 11
  gmshPluginSetNumber("Isosurface", "Value", 11.);
  gmshPluginRun("Isosurface");

  // delete the source view
  gmshViewDelete(t);

  // check how many views the plugin created (a priori, a single one)
  std::vector<int> tags;
  gmshViewGetTags(tags);
  if(tags.size() == 1)
    gmshViewExport(tags[0], "iso.msh");

  gmshFinalize();
  return 0;
}


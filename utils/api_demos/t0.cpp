#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);
  gmshOptionSetNumber("Mesh.Algorithm", 5);
  gmshOpen("test.geo");
  gmshModelMesh(3);
  gmshExport("test.msh");
  gmshExport("test.unv");
  gmshFinalize();
}

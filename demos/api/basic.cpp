#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2){
    std::cout << "Usage: " << argv[0] << " file.geo [options]" << std::endl;
    return 1;
  }

  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);
  gmshOpen(argv[1]);
  gmshModelMesh(3);
  gmshExport("test.msh");
  gmshFinalize();

  return 0;
}

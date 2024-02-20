#include <iostream>
#include <gmsh.h>

int main(int argc, char **argv)
{
  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " file [options]" << std::endl;
    return 0;
  }

  gmsh::initialize();

  try{
    gmsh::open(argv[1]);
  }
  catch(...) {
    return 0;
  }

  gmsh::onelab::run();

  std::string json;
  gmsh::onelab::get(json);
  std::cout << json;

  gmsh::finalize();

  return 0;
}


#include "tetlib.h"

int main(int argc, char* argv[])
{
  mesh3d mymesh;

  mymesh.triangulate(argc, argv);

  return 0;
}

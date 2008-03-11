// configure, compile and install Gmsh as a library with
//
//   ./configure --disable-gui
//   make install-lib
//
// Then compile this driver with "g++ driver.cpp -lGmsh -lgsl -lgslcblas"

#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();
  m->readGEO("../../tutorial/t5.geo");
  m->mesh(3);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    printf("volume %d contains %d elements:\n", (*it)->tag(), (*it)->getNumMeshElements());
    for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++)
      printf(" %d", (*it)->getMeshElement(i)->getNum());
    printf("\n");
  }
  m->writeMSH("test.msh");
  m->writeUNV("test.unv");
  GmshFinalize();
}

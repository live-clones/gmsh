// configure, compile and install Gmsh as a library with
//
//   ./configure --disable-gui
//   make install-lib
//
// Then compile this driver with "g++ driver.cpp -lGmsh -llapack -lblas"

#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  //GmshSetOption("Mesh", "Algorithm", 5);
  GModel *m = new GModel();
  //m->readGEO("../../tutorial/t5.geo");
  GmshMergeFile("../../tutorial/t5.geo"); // will also set the bbox
  m->mesh(3);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    GRegion *r = *it;
    printf("volume %d contains %d elements:\n", r->tag(), r->getNumMeshElements());
    for(unsigned int i = 0; i < r->getNumMeshElements(); i++)
      printf(" %d", r->getMeshElement(i)->getNum());
    printf("\n");
  }
  m->writeMSH("test.msh");
  m->writeUNV("test.unv");
  delete m;
  GmshFinalize();
}

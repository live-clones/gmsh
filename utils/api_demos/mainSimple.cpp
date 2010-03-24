#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  //GmshSetOption("Mesh", "Algorithm", 5);
  GModel *m = new GModel();
  m->readGEO("../../tutorial/t5.geo");
  //GmshMergeFile("../../tutorial/t5.geo"); // will also set the bbox
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

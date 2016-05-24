#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "discreteRegion.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GmshSetOption("Mesh", "CharacteristicLengthExtendFromBoundary", 1.);
  GmshSetOption("Mesh", "OldRefinement", 1.);
  GmshSetOption("Mesh", "CharacteristicLengthMin", 0.1);
  GmshSetOption("Mesh", "CharacteristicLengthMax", 0.1);

  GModel *m = new GModel();
  m->readMSH("cube.msh");

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    discreteRegion *r = dynamic_cast<discreteRegion*>(*it);
    if(r){
      printf("found a discrete region (%d) with %d tetrahedra\n", r->tag(), r->tetrahedra.size());
      r->remesh();
      printf("after remeshing: %d tetrahedra\n", r->tetrahedra.size());
    }
  }
  m->writeMSH("new.msh");
  delete m;
  GmshFinalize();
}

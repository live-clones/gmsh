#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MTetrahedron.h"
#include "MTriangle.h"

int main(int argc, char **argv)
{
  GmshInitialize(argc, argv);
  GModel *m = new GModel();
  m->readMSH("../problem.msh");
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    GRegion *r = *it;
    for(unsigned int i = 0; i < r->tetrahedra.size(); i++)
      printf(" tet %d: vertices %d %d %d %d\n", r->tetrahedra[i]->getNum(),
             r->tetrahedra[i]->getVertex(0)->getNum(),
             r->tetrahedra[i]->getVertex(1)->getNum(),
             r->tetrahedra[i]->getVertex(2)->getNum(),
             r->tetrahedra[i]->getVertex(3)->getNum());
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    GFace *f = *it;
    for(unsigned int i = 0; i < f->triangles.size(); i++)
      printf(" tri %d: vertices %d %d %d\n", f->triangles[i]->getNum(),
             f->triangles[i]->getVertex(0)->getNum(),
             f->triangles[i]->getVertex(1)->getNum(),
             f->triangles[i]->getVertex(2)->getNum());
  }
  delete m;
  GmshFinalize();
}

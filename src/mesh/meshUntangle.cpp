#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshUntangle.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTetrahedron.h"
#include "MVertex.h"

#ifdef HAVE_UNTANGLE
int untangle3dTet(std::vector<double>& verts,
		  std::vector<int>& tets, int itermax);
void untangleMesh(GRegion *gr){
  for (auto t : gr->tetrahedra){
    t->getVertex(0)->setIndex(-1);
    t->getVertex(1)->setIndex(-1);
    t->getVertex(2)->setIndex(-1);
    t->getVertex(3)->setIndex(-1);
  }
  int current = 0;
  std::vector<double> verts;
  std::vector<int> tets;
  std::vector<MVertex*> vs;
  for (auto t : gr->tetrahedra){
    for (int i=0;i<4;i++){
      if (t->getVertex(i)->getIndex() == -1){
	t->getVertex(i)->setIndex(current++);
	vs.push_back(t->getVertex(i));
	verts.push_back(t->getVertex(i)->x());
	verts.push_back(t->getVertex(i)->y());
	verts.push_back(t->getVertex(i)->z());
      }
      tets.push_back(t->getVertex(i)->getIndex());
    }
  }
  
  int result = untangle3dTet(verts,tets,100);

  if (result == 0){
    Msg::Info("Untangling of volume %d successful",gr->tag());
    for (size_t i=0;i<vs.size();i++){
      vs[i]->x() = verts[3*i];
      vs[i]->y() = verts[3*i+1];
      vs[i]->z() = verts[3*i+2];
    }
    
  }
  
  
}
#else
void untangleMesh(GRegion *gr){
  Msg::Error("Gmsh must be compiled with the UNTANGLE lib to be able to untangle a tet mesh");
}
#endif

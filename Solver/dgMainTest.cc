#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"


#include "MElement.h"
void print (const char *filename,const dgGroupOfElements &els, double *v);
std::vector<MElement *> getAllTri(GModel *model);

int main(int argc, char **argv){
  GmshMergeFile("input/mesh1.msh");
  std::vector<MElement *> allTri=getAllTri(GModel::current());
  int order=1;
  dgGroupOfElements elements(allTri,order);
  dgGroupOfFaces faces(elements,order);
  int nbNodes=elements.getNbNodes();
  fullMatrix<double> sol(nbNodes,elements.getNbElements());
  fullMatrix<double> solInterface(nbNodes,faces.getNbElements()*2);
  fullMatrix<double> residu(nbNodes,elements.getNbElements());
  fullMatrix<double> residuInterface(nbNodes,faces.getNbElements()*2);
  dgAlgorithm algo;
  dgConservationLaw *law = dgNewConservationLawAdvection();
  algo.residualVolume(*law,elements,sol,residu);
  faces.mapToInterface(1, sol, sol, solInterface);
  algo.residualInterface(*law,faces,solInterface,residuInterface);
  faces.mapFromInterface(1, residuInterface, residu, residu);
  for(int i=0;i<elements.getNbElements();i++) {
    fullMatrix<double> residuEl(residu,i,1);
    fullMatrix<double> solEl(sol,i,1);
    solEl.gemm(elements.getInverseMassMatrix(i),residuEl);
  }
  print("test.pos",elements,&sol(0,0));
}

std::vector<MElement *> getAllTri(GModel *model){
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::vector<MElement *> all_tri;
  for(std::vector<GEntity *>::iterator itent=entities.begin(); itent!=entities.end(); itent++){
    if ((*itent)->dim()!=2) continue;
    for (int iel=0; iel<(*itent)->getNumMeshElements(); iel++)
      all_tri.push_back((*itent)->getMeshElement(iel));
  }
  return all_tri;
}

void print (const char *filename,const dgGroupOfElements &els, double *v) {
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"%s\" {\n", filename);
  for(int iel=0;iel<els.getNbElements();iel++){
    MElement *el = els.getElement(iel);
    fprintf(file,"ST (");
    for (int iv=0; iv<el->getNumVertices(); iv++) {
      MVertex *vertex = el->getVertex(iv);
      SPoint3 coord = vertex->point();
      fprintf(file,"%e, %e, %e%c ",coord.x(),coord.y(),coord.z(),iv==el->getNumVertices()-1?')':',');
    }
    fprintf(file,"{");
    for (int iv=0; iv<el->getNumVertices(); iv++)
      fprintf(file,"%e%c ",*(v++),iv==el->getNumVertices()-1?'}':',');
    fprintf(file,";\n");
  }
  fprintf(file,"};");
  fclose(file);
}

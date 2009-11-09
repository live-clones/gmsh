#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"


#include "MElement.h"
void print (const char *filename,const dgGroupOfElements &els, double *v);
void buildGroupAllTri(GModel *model, int order, //in
                         std::vector<dgGroupOfElements*> &elements, //out
                         std::vector<dgGroupOfFaces*> &faces); //out

int main(int argc, char **argv){
  GmshMergeFile("input/mesh1.msh");
  std::vector<dgGroupOfElements*> elements;
  std::vector<dgGroupOfFaces*> faces;
  buildGroupAllTri(GModel::current(),1,elements,faces);
  int nbNodes=elements[0]->getNbNodes();
  fullMatrix<double> sol(nbNodes,elements[0]->getNbElements());
  fullMatrix<double> residu(nbNodes,elements[0]->getNbElements());
  dgAlgorithm algo;
  dgConservationLaw *law = dgNewConservationLawAdvection();
  algo.residualVolume(*law,*elements[0],sol,residu);
  for(int i=0;i<elements[0]->getNbElements();i++) {
    fullMatrix<double> residuEl(residu,i,1);
    fullMatrix<double> solEl(sol,i,1);
    solEl.gemm(elements[0]->getInverseMassMatrix(i),residuEl);
  }
  print("test.pos",*elements[0],&sol(0,0));
}

void buildGroupAllTri(GModel *model, int order, //in
                         std::vector<dgGroupOfElements*> &elements, //out
                         std::vector<dgGroupOfFaces*> &faces){ //out
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::vector<MElement *> all_tri;
  for(std::vector<GEntity *>::iterator itent=entities.begin(); itent!=entities.end(); itent++){
    if ((*itent)->dim()!=2) continue;
    for (int iel=0; iel<(*itent)->getNumMeshElements(); iel++)
      all_tri.push_back((*itent)->getMeshElement(iel));
  }
  elements.push_back(new dgGroupOfElements(all_tri,order));
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

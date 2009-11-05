#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"


#include "MElement.h"
void print (const char *filename, std::vector<MElement *> &els, double *v);
std::vector<MElement *> get_all_tri(GModel *model);


int main(int argc, char **argv){
  GmshMergeFile("input/mesh1.msh");
  std::vector<MElement *> all_tri=get_all_tri(GModel::current());
  dgGroupOfElements group(all_tri,1);
  fullMatrix<double> sol(3,all_tri.size());
  fullMatrix<double> residu(3,all_tri.size());
  dgAlgorithm algo;
  dgConservationLaw *law = dgNewConservationLawAdvection();
  algo.residualVolume(*law,group,sol,residu);
  sol.gemm(group.getInverseMassMatrix(),residu);
  print("test.pos",all_tri,&sol(0,0));
}



std::vector<MElement *> get_all_tri(GModel *model){
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

void print (const char *filename, std::vector<MElement *> &els, double *v) {
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"%s\" {\n", filename);
  int i=0;
  for(std::vector<MElement *>::iterator itel= els.begin();itel!=els.end();itel++){
    MElement *el = *itel;
    fprintf(file,"ST (");
    for (int iv=0; iv<el->getNumVertices(); iv++) {
      MVertex *vertex = el->getVertex(iv);
      SPoint3 coord = vertex->point();
      fprintf(file,"%e, %e, %e%c ",coord.x(),coord.y(),coord.z(),iv==el->getNumVertices()-1?')':',');
    }
    fprintf(file,"{");
    for (int iv=0; iv<el->getNumVertices(); iv++)
      fprintf(file,"%e%c ",v[i++],iv==el->getNumVertices()-1?'}':',');
    fprintf(file,";\n");
  }
  fprintf(file,"};");
  fclose(file);
}

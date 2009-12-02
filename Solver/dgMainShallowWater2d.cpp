#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"
#include "function.h"


#include "MElement.h"
void print (const char *filename,const dgGroupOfElements &els, double *v,int iField=1, int nbFields=1);

int main(int argc, char **argv) {
  GmshMergeFile("input/stommel.msh");
  //we probably need a class to group those three ones
  std::vector<dgGroupOfElements*> elementGroups;
  std::vector<dgGroupOfFaces*> faceGroups;
  std::vector<dgGroupOfFaces*> boundaryGroups;
  int order=1;
  int dimension=2;
  dgAlgorithm algo;
  function::registerDefaultFunctions();
  algo.buildGroups(GModel::current(),dimension,order,elementGroups,faceGroups,boundaryGroups);

  //for now, we suppose there is only one group of elements
  int nbNodes = elementGroups[0]->getNbNodes();
  fullMatrix<double> sol(nbNodes,elementGroups[0]->getNbElements()*3);
  fullMatrix<double> residu(nbNodes,elementGroups[0]->getNbElements()*3);

  dgConservationLaw *law = dgNewConservationLawShallowWater2d();
  law->addBoundaryCondition("Wall",dgNewBoundaryConditionShallowWater2dWall());
  
  for(int iT=0; iT<10000; iT++) {
    if(iT%100==0){
      printf("%i\n",iT);
      char name[100];
      sprintf(name,"output/eta_%05i.pos",iT/100);
      print(name,*elementGroups[0],&sol(0,0),0,3);
      sprintf(name,"output/u_%05i.pos",iT/100);
      print(name,*elementGroups[0],&sol(0,0),1,3);
      sprintf(name,"output/v_%05i.pos",iT/100);
      print(name,*elementGroups[0],&sol(0,0),2,3);
    }
    algo.rungeKutta(*law,elementGroups,faceGroups,boundaryGroups,50,residu,sol);
  }
  delete law;
}

void print (const char *filename,const dgGroupOfElements &els, double *v,int iField, int nbFields) {
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
    v+=(iField)*el->getNumVertices();
    for (int iv=0; iv<el->getNumVertices(); iv++){
      fprintf(file,"%e%c ",*(v++),iv==el->getNumVertices()-1?'}':',');
    }
    v+=(nbFields-1-iField)*el->getNumVertices();
    fprintf(file,";\n");
  }
  fprintf(file,"};");
  fclose(file);
}

#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"
#include "function.h"
#include "functionDerivator.h"


#include "MElement.h"
void print (const char *filename,const dgGroupOfElements &els, double *v,int iField=1, int nbFields=1);
void print_vector (const char *filename,const dgGroupOfElements &els, double *v,int iField, int nbFields);

class dgConservationLawInitialCondition : public dgConservationLaw {
  class gaussian : public dataCacheDouble {
    dataCacheDouble &xyz;
    double _xc,_yc;
    public:
    gaussian(dataCacheMap &cacheMap,double xc, double yc):xyz(cacheMap.get("XYZ",this)),_xc(xc),_yc(yc){};
    void _eval () { 
      if(_value.size1() != xyz().size1())
        _value=fullMatrix<double>(xyz().size1(),3);
      for(int i=0; i< _value.size1(); i++) {
        _value(i,0)=exp(-(pow(xyz(i,0)-_xc,2)+pow(xyz(i,1)-_yc,2))*100)+1;
      }
    }
  };
  public:
  dgConservationLawInitialCondition() {
    _nbf = 3;
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    //return new gaussian(cacheMap,0.2,0.3);
    return new gaussian(cacheMap,0.5,0.5);
  }
};

int main(int argc, char **argv){
  GmshMergeFile("input/square1.msh");
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
  dgConservationLaw *law = dgNewConservationLawWaveEquation();
  fullMatrix<double> sol(nbNodes,elementGroups[0]->getNbElements()*law->nbFields());
  fullMatrix<double> residu(nbNodes,elementGroups[0]->getNbElements()*law->nbFields());
  /*{ // use this block to test functionDerivator
    dgConservationLawInitialCondition initLaw;
    dataCacheMap cacheMap;
    dataCacheElement &cacheElement = cacheMap.getElement();
    cacheMap.provideData("UVW").set(elementGroups[0]->getIntegrationPointsMatrix());
    cacheElement.set(elementGroups[0]->getElement(0));
    dataCacheDouble &xyz = cacheMap.get("XYZ");
    dataCacheDouble *source = initLaw.newSourceTerm(cacheMap);
    functionDerivator fd (*source, xyz, 1e-12);
    xyz().print();
    fd.compute();
    exit(0);
  }*/
  // initial condition
  {
    dgConservationLawInitialCondition initLaw;
    algo.residualVolume(initLaw,*elementGroups[0],sol,residu);
    algo.multAddInverseMassMatrix(*elementGroups[0],residu,sol);
  }

  law->addBoundaryCondition("Left",dgNewBoundaryConditionWaveEquationWall());
  law->addBoundaryCondition("Right",dgNewBoundaryConditionWaveEquationWall());
  law->addBoundaryCondition("Top",dgNewBoundaryConditionWaveEquationWall());
  law->addBoundaryCondition("Bottom",dgNewBoundaryConditionWaveEquationWall());
  
 print("output/p.pos",*elementGroups[0],&sol(0,0),0,3);
 print_vector("output/uv.pos",*elementGroups[0],&sol(0,0),1,3);
  for(int iT=0; iT<10000; iT++) {
    algo.rungeKutta(*law,elementGroups,faceGroups,boundaryGroups,1e-3,residu,sol);
    if(iT%10==0){
      char name[100];
      printf("%i\n",iT);
      sprintf(name,"output/p_%05i.pos",iT);
      print(name,*elementGroups[0],&sol(0,0),0,3);
      sprintf(name,"output/uv_%05i.pos",iT);
      print_vector(name,*elementGroups[0],&sol(0,0),1,3);
      sprintf(name,"output/v_%05i.pos",iT);
      print(name,*elementGroups[0],&sol(0,0),2,3);
      sprintf(name,"output/u_%05i.pos",iT);
      print(name,*elementGroups[0],&sol(0,0),1,3);
    }
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
void print_vector (const char *filename,const dgGroupOfElements &els, double *v,int iField, int nbFields) {
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"%s\" {\n", filename);
  for(int iel=0;iel<els.getNbElements();iel++){
    MElement *el = els.getElement(iel);
    fprintf(file,"VT (");
    for (int iv=0; iv<el->getNumVertices(); iv++) {
      MVertex *vertex = el->getVertex(iv);
      SPoint3 coord = vertex->point();
      fprintf(file,"%e, %e, %e%c ",coord.x(),coord.y(),coord.z(),iv==el->getNumVertices()-1?')':',');
    }
    v+=(iField)*el->getNumVertices();
    fprintf(file,"{%e, %e, 0, %e, %e, 0, %e, %e, 0};\n", v[0],v[3],v[1],v[4],v[2],v[5]);
    v+=(nbFields-iField)*el->getNumVertices();
  }
  fprintf(file,"};");
  fclose(file);
}

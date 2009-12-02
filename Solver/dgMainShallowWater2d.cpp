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

class dgConservationLawInitialCondition : public dgConservationLaw {
  class gaussian : public dataCacheDouble {
    dataCacheDouble &xyz;
    double _xc,_yc;
    public:
    gaussian(dataCacheMap &cacheMap,double xc, double yc):xyz(cacheMap.get("XYZ",this)),_xc(xc),_yc(yc){};
    void _eval () { 
      if(_value.size1() != xyz().size1())
        _value=fullMatrix<double>(xyz().size1(),1);
      for(int i=0; i< _value.size1(); i++) {
        _value(i,0)=exp(-(pow(xyz(i,0)-_xc,2)+pow(xyz(i,1)-_yc,2))*100);
      }
    }
  };
  public:
  dgConservationLawInitialCondition() {
    _nbf = 1;
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    return new gaussian(cacheMap,0.2,0.3);
  }
};

/*int main(int argc, char **argv) {
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
  fullMatrix<double> sol(nbNodes,elementGroups[0]->getNbElements());
  fullMatrix<double> residu(nbNodes,elementGroups[0]->getNbElements());
  // initial condition
  {
    dgConservationLawInitialCondition initLaw;
    algo.residualVolume(initLaw,*elementGroups[0],sol,residu);
    algo.multAddInverseMassMatrix(*elementGroups[0],residu,sol);
  }

  fullMatrix<double> advectionSpeed(3,1);
  advectionSpeed(0,0)=0.15;
  advectionSpeed(1,0)=0.05;
  advectionSpeed(2,0)=0.;
  function::add("advectionSpeed",function::newFunctionConstant(advectionSpeed));

  dgConservationLaw *law = dgNewConservationLawAdvection("advectionSpeed");

  fullMatrix<double> outsideValue(1,1);
  outsideValue(0,0)=0;
  function::add("outsideValue",function::newFunctionConstant(outsideValue));
  law->addBoundaryCondition("Left",dgBoundaryCondition::newOutsideValueCondition(*law,"outsideValue"));
  law->addBoundaryCondition("Right",dgBoundaryCondition::newOutsideValueCondition(*law,"outsideValue"));

  law->addBoundaryCondition("Top",dgBoundaryCondition::new0FluxCondition(*law));
  law->addBoundaryCondition("Bottom",dgBoundaryCondition::new0FluxCondition(*law));

  
  
 print("output/init.pos",*elementGroups[0],&sol(0,0));
  for(int iT=0; iT<100; iT++) {
    algo.rungeKutta(*law,elementGroups,faceGroups,boundaryGroups,0.01,residu,sol);
    if(iT%10==0){
      char name[100];
      sprintf(name,"output/test_%05i.pos",iT/10);
      printf("%i\n",iT);
      print(name,*elementGroups[0],&sol(0,0));
    }
  }
  delete law;
}*/
class dgConservationLawStommel : public dgConservationLaw {
  class initbath : public dataCacheDouble {
    dataCacheDouble &uvw;
    public:
    initbath(dataCacheMap &cacheMap):
      uvw(cacheMap.get("UVW"))
    {}
    void _eval () { 
      if(_value.size1() != uvw().size1())
        _value=fullMatrix<double>(uvw().size1(),3);
      for(int i=0; i< _value.size1(); i++) {
        _value(i,0)=1000;
        _value(i,1)=0;
        _value(i,2)=0;
      }
    }
  };
  public:
  dgConservationLawStommel() {
    _nbf = 3;
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    return new initbath(cacheMap);
  }
};
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
  // initial condition
  {
    dgConservationLawStommel initLaw;
    algo.residualVolume(initLaw,*elementGroups[0],sol,residu);
    algo.multAddInverseMassMatrix(*elementGroups[0],residu,sol);
  }

  dgConservationLaw *law = dgNewConservationLawShallowWater2d();

  law->addBoundaryCondition("Top",dgBoundaryCondition::new0FluxCondition(*law));
  law->addBoundaryCondition("Bottom",dgBoundaryCondition::new0FluxCondition(*law));
  law->addBoundaryCondition("Left",dgBoundaryCondition::new0FluxCondition(*law));
  law->addBoundaryCondition("Right",dgBoundaryCondition::new0FluxCondition(*law));
  
  for(int iT=0; iT<100; iT++) {
    if(iT%10==0){
      printf("%i\n",iT);
      char name[100];
      sprintf(name,"output/H_%05i.pos",iT/10);
      print(name,*elementGroups[0],&sol(0,0),0,3);
      sprintf(name,"output/U_%05i.pos",iT/10);
      print(name,*elementGroups[0],&sol(0,0),1,3);
      sprintf(name,"output/V_%05i.pos",iT/10);
      print(name,*elementGroups[0],&sol(0,0),2,3);
    }
    algo.rungeKutta(*law,elementGroups,faceGroups,boundaryGroups,1e-8,residu,sol);
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

#include <stdio.h>
#include <vector>
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"
#include "function.h"


#include "MElement.h"
void print (const char *filename,const dgGroupOfElements &els, double *v);


class dgConservationLawInitialCondition : public dgConservationLaw {
  class gaussian : public dataCacheDouble {
    dataCacheDouble &xyz;
    double _xc;
    public:
    gaussian(dataCacheMap &cacheMap,double xc):xyz(cacheMap.get("XYZ",this)),_xc(xc){};
    void _eval () { 
      if(_value.size1() != xyz().size1())
        _value=fullMatrix<double>(xyz().size1(),1);
      for(int i=0; i< _value.size1(); i++) {
        _value(i,0)= exp(-pow(xyz(i,0)-_xc,2)*100); //1.0-xyz(i,0);//
      }
    }
  };
  public:
  dgConservationLawInitialCondition() {
    _nbf = 1;
  }
  dataCacheDouble *newSourceTerm(dataCacheMap &cacheMap)const {
    return new gaussian(cacheMap,-0.8);
  }
};

int main(int argc, char **argv){
  GmshMergeFile("input/edge.msh");
  //we probably need a class to group those three ones
  std::vector<dgGroupOfElements*> elementGroups;
  std::vector<dgGroupOfFaces*> faceGroups;
  std::vector<dgGroupOfFaces*> boundaryGroups;
  int order=1;
  int dimension=1;
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
  advectionSpeed(0,0)=1.0;
  advectionSpeed(1,0)=0;
  advectionSpeed(2,0)=0.;
  function::add("advectionSpeed",function::newFunctionConstant(advectionSpeed));

  dgConservationLaw *law = dgNewConservationLawAdvection("advectionSpeed");

  fullMatrix<double> outsideValue(1,1);
  outsideValue(0,0)=0;
  function::add("outsideValue",function::newFunctionConstant(outsideValue));
  law->addBoundaryCondition("Left",dgBoundaryCondition::newOutsideValueCondition(*law,"outsideValue"));
  law->addBoundaryCondition("Right",dgBoundaryCondition::newOutsideValueCondition(*law,"outsideValue"));  
  
 print("output/init.pos",*elementGroups[0],&sol(0,0));
 int n_visu = 10;
  for(int iT=0; iT<100*n_visu; iT++) {
    algo.rungeKutta(*law,elementGroups,faceGroups,boundaryGroups,0.002,residu,sol);
    if(iT%n_visu==0){
      char name[100];
      sprintf(name,"output/test_%05i.pos",iT/n_visu);
      printf("%i\n",iT);
      print(name,*elementGroups[0],&sol(0,0));
    }
  }
  delete law;
}

void print (const char *filename,const dgGroupOfElements &els, double *v) {
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"%s\" {\n", filename);
  for(int iel=0;iel<els.getNbElements();iel++){
    MElement *el = els.getElement(iel);
    fprintf(file,"SL (");
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

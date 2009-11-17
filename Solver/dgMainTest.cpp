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

class testSourceTerm : public dgTerm {
  void operator () (const dgElement &el, fullMatrix<double> fcx[]) const{
    const fullMatrix<double> &sol = el.solution();
    const fullMatrix<double> &qp = el.integration();
    SPoint3 p;
    for(int i=0; i< sol.size1(); i++) {
      el.element()->pnt(qp(i,0),qp(i,1),qp(i,2),p);
      fcx[0](i,0)=exp(-(pow(p.x()-0.2,2)+pow(p.y(),2))*100);
    }
  }
};

class dgConservationLawInitialCondition : public dgConservationLaw {
  public:
  dgConservationLawInitialCondition() {
    _nbf = 1;
    _source = new testSourceTerm;
  }
  ~dgConservationLawInitialCondition() {
    delete _source;
  }
};

int main(int argc, char **argv){
  GmshMergeFile("mesh1.msh");
  //GmshMergeFile("square2.msh");
  std::vector<MElement *> allTri=getAllTri(GModel::current());
  int order=1;
  dgGroupOfElements elements(allTri,order);
  dgGroupOfFaces faces(elements,order);
  //dgGroupOfFaces faces(elements0,elements1,order);
  int nbNodes = elements.getNbNodes();
  fullMatrix<double> sol(nbNodes,elements.getNbElements());
  fullMatrix<double> residu(nbNodes,elements.getNbElements());
  dgAlgorithm algo;
  // initial condition
  {
    dgConservationLawInitialCondition initLaw;
    algo.residualVolume(initLaw,elements,sol,residu);
    algo.multAddInverseMassMatrix(elements,residu,sol);
  }
  print("init.pos",elements,&sol(0,0));
  //advection
  dgConservationLaw *law = dgNewConservationLawAdvection();
  for(int iT=0; iT<1000; iT++) {
    residu.scale(0);
    algo.residualVolume(*law,elements,sol,residu);
    { //interface term
      fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*2);
      fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*2);
      faces.mapToInterface(1, sol, sol, solInterface);
      algo.residualInterface(*law,faces,solInterface,residuInterface);
      faces.mapFromInterface(1, residuInterface, residu, residu);
    }
    residu.scale(0.01);
    algo.multAddInverseMassMatrix(elements,residu,sol);
    if(iT%10==0){
      char name[100];
      sprintf(name,"test_%05i.pos",iT/10);
      printf("%i\n",iT);
      print(name,elements,&sol(0,0));
    }
  }
  delete law;
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

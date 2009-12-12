#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
#include "groupOfElements.h"
#include <iterator>
int main (int argc, char* argv[])
{
  
  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  }

  
  GmshInitialize(argc, argv);
  // globals are still present in Gmsh

  // instanciate a solver
  MyelasticitySolver mySolver (1000);
  //elasticitySolver mySolver (1000);
  // read some input file
  mySolver.readInputFile(argv[1]);

  // solve the problem
  mySolver.solve();

  PView *pv = mySolver.buildDisplacementView("displacement");
  pv->getData()->writeMSH("disp.msh", false);
  delete pv;
 	
  // stop gmsh
  GmshFinalize();
  
}



/*
  groupOfElements *g = new groupOfElements (2, 7);

  MElement *e=*(g->begin());
  std::cout << e->getNumPrimaryVertices() << "vertices" << std::endl;
  const double uvw[3]={0.,0.,0.};
  std::vector<Dof> dofs;
  std::vector<double> vals;
  std::vector<SVector3> grads;
  std::vector<SVector3> vals2;
  std::vector<STensor3> grads2;

  std::ostream_iterator< double > output( std::cout, " " );

  ScalarLagrangeFunctionSpace L(100);
  std::cout << L.getNumKeys(e) << "fonctions de formes L" << std::endl;
  L.getKeys(e,dofs);
  for (int i=0;i<dofs.size();++i) std::cout << "entity: " << dofs[i].getEntity() << " id: " << dofs[i].getType() << std::endl; 
  dofs.clear();
  L.f(e,0.1,0.1,0,vals);
  L.gradf(e,0.1,0.1,0,grads);
  std::copy(vals.begin(),vals.end(),output); std::cout << std::endl;
  for (std::vector<SVector3>::iterator it=grads.begin();it!=grads.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }
  
  VectorLagrangeFunctionSpace L1(100,VectorLagrangeFunctionSpace::VECTOR_X);
  VectorLagrangeFunctionSpace L2(100,VectorLagrangeFunctionSpace::VECTOR_Y);
  std::cout << L2.getNumKeys(e) << "fonctions de formes L2" << std::endl;
  L2.f(e,0.1,0.1,0,vals2);
  L2.gradf(e,0.1,0.1,0,grads2);
  for (std::vector<SVector3>::iterator it=vals2.begin();it!=vals2.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }
  for (std::vector<STensor3>::iterator it=grads2.begin();it!=grads2.end();++it) { (*it).print(""); }

  VectorLagrangeFunctionSpace L3(100,VectorLagrangeFunctionSpace::VECTOR_Z);

  VectorLagrangeFunctionSpace P123(100);
  std::cout << P123.getNumKeys(e) << "fonctions de formes P123" << std::endl;
  P123.getKeys(e,dofs);
  std::cout << dofs.size() << std::endl;
  for (int i=0;i<dofs.size();++i) std::cout << "entity: " << dofs[i].getEntity() << " id: " << dofs[i].getType() << std::endl; 

  vals2.clear();
  grads2.clear();
  P123.f(e,0.1,0.1,0,vals2);
  P123.gradf(e,0.1,0.1,0,grads2);
  for (std::vector<SVector3>::iterator it=vals2.begin();it!=vals2.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }
  for (std::vector<STensor3>::iterator it=grads2.begin();it!=grads2.end();++it) { (*it).print(""); }



  FormBilinear<TermBilinearMeca,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > f(L,L);
  f.func();
  f.Accumulate(e,uvw);


  FormBilinear<TermBilinearMecaNL,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > fnl(L,L);
  fnl.func();
  
*/






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
  elasticitySolver mySolver (1000);
  
  // read some input file
  mySolver.readInputFile(argv[1]);


  groupOfElements *g = new groupOfElements (2, 7);

  MElement *e=*(g->begin());
  std::cout << e->getNumPrimaryVertices() << "vertices" << std::endl;
  const double uvw[3]={0.,0.,0.};
  std::vector<Dof> dofs;
  std::vector<double> vals;
  std::ostream_iterator< double > output( std::cout, " " );
  ScalarLagrangeFunctionSpace L(100);
  std::cout << L.getNumKeys(e) << "fonctions de formes L" << std::endl;
  L.f(e,0.1,0.1,0,vals);
  std::copy(vals.begin(),vals.end(),output);
  
  VectorLagrangeFunctionSpace L1(101,VectorLagrangeFunctionSpace::VECTOR_X);
  std::cout << L1.getNumKeys(e) << "fonctions de formes L1" << std::endl;
  VectorLagrangeFunctionSpace L2(102,VectorLagrangeFunctionSpace::VECTOR_Y);
  VectorLagrangeFunctionSpace L3(103,VectorLagrangeFunctionSpace::VECTOR_Z);

  ProductFunctionSpace<VectorLagrangeFunctionSpace::ValType> P123(L1,L2,L3);
  std::cout << P123.getNumKeys(e) << "fonctions de formes P123" << std::endl;
  P123.getKeys(e,dofs);
  std::cout << dofs.size() << std::endl;

  FormBilinear<TermBilinearMeca,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > f(L,L);
  f.func();
  f.Accumulate(e,uvw);


  FormBilinear<TermBilinearMecaNL,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > fnl(L,L);
  fnl.func();
  




 
  // solve the problem
  mySolver.solve();

  PView *pv = mySolver.buildDisplacementView("displacement");
  pv->getData()->writeMSH("disp.msh", false);
  delete pv;
 	
  // stop gmsh
  GmshFinalize();
  
}

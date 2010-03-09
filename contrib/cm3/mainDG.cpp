#include "Gmsh.h"
#include "DgC0PlateSolver.h"
#include "PView.h"
#include "PViewData.h"
#include "../arc/highlevel.h"
#include "groupOfElements.h"
#include <iterator>
#include <iostream>

int main (int argc, char* argv[])
{

  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  }
  GmshInitialize(argc, argv);
  // globals are still present in Gmsh

  // instanciate a solver
  DgC0PlateSolver mySolver (1000);

  // read some input file
  mySolver.readInputFile(argv[1]);

  // solve the problem
  mySolver.solve();

  PView *pv = mySolver.buildDisplacementView("displacement");
  pv->getData()->writeMSH("disp.msh", false);
  delete pv;
  //pv = mySolver.buildElasticEnergyView("elastic energy"); //error ??
  //pv->getData()->writeMSH("energ.msh", false);
  //delete pv;

  // stop gmsh
  GmshFinalize();

}

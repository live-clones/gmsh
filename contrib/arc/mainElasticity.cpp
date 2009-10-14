#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
int main (int argc, char* argv[]){
  
  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  } 
  
  // globals are still present in Gmsh
  GmshInitialize(argc, argv);
  
  // instanciate a solver
  elasticitySolver mySolver (1000);
  
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

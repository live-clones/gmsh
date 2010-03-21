#include <gmsh/Gmsh.h>
#include <gmsh/elasticitySolver.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>

int main (int argc, char* argv[]){
  
  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  } 
  
  // globals are still present in Gmsh
  GmshInitialize(argc, argv);
  GmshSetOption("General","Terminal",1.);
  
  // instanciate a solver
  elasticitySolver mySolver (1000);
  
  // read some input file
  mySolver.readInputFile(argv[1]);
  
  // solve the problem
  mySolver.solve(); printf("problem solved\n");

  PView *pv = mySolver.buildDisplacementView("displacement");
  pv->getData()->writeMSH("disp.msh", false);
  delete pv;
        
  // stop gmsh
  GmshFinalize();
  
}

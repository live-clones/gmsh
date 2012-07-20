#include <iostream>
#include "Mesh.h"
#include "Gmsh.h"

#include "QuadNodeBasis.h"
#include "QuadEdgeBasis.h"

#include "TriNodeBasis.h"
#include "TriEdgeBasis.h"
#include "TriNedelecBasis.h"

#include "HexNodeBasis.h"
#include "HexEdgeBasis.h"

#include "PlotBasis.h"

using namespace std;

int main(int argc, char** argv){
  // Init Gmsh //
  GmshInitialize(argc, argv);

  // Get Mesh //
  Mesh msh(argv[1]);

  // Plot Basis //
  QuadEdgeBasis b(1);
  
  PlotBasis plot(msh.getGroup(2), b);
  plot.write("basis");
  
  // Stop Gmsh //
  GmshFinalize();
  
  return 0;
}


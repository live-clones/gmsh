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
#include "WriterMsh.h"

using namespace std;

int main(int argc, char** argv){
  // Init Gmsh //
  GmshInitialize(argc, argv);

  // Get Mesh //
  Mesh msh(argv[1]);

  // Writer for .msh
  WriterMsh writer(msh.getGroup(2).getAll());

  // Plot Basis //
  TriEdgeBasis b(5);
  
  PlotBasis plot(msh.getGroup(2), b, writer);
  plot.plot("basis");
  
  // Stop Gmsh //
  GmshFinalize();
  
  return 0;
}


#include <iostream>

#include "Gmsh.h"
#include "Mesh.h"
#include "GroupOfElement.h"

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

int basisTest(int argc, char** argv){
  // Init Gmsh //
  GmshInitialize(argc, argv);

  // Get Mesh //
  Mesh msh(argv[1]);
  GroupOfElement goe = msh.getFromPhysical(7);

  // Writer for .msh
  WriterMsh writer;
  writer.setDomain(goe.getAll());

  // Plot Basis //
  TriNodeBasis b(3);
  
  cout << "Size: " << b.getSize() << endl;

  PlotBasis plot(b, goe, writer);
  plot.plot("basis");
  
  // Stop Gmsh //
  GmshFinalize();
  
  return 0;
}


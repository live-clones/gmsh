// THIS FILE WILL BE REMOVED AS SOON AS THE NEW SOLVER INTERFACE IS READY

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "gmshConvexCombination.h"
#include "Numeric.h"

void gmshConvexCombinationTerm::elementMatrix(MElement *e, gmshMatrix<double> &m) const
{
  m.set_all(0.);
  int nbNodes = e->getNumVertices();
  //double x = 0.3*(e->getVertex(0)->x()+e->getVertex(1)->x()+e->getVertex(2)->x());
  //double y = 0.3*(e->getVertex(0)->y()+e->getVertex(1)->y()+e->getVertex(2)->y());
  //double z = 0.3*(e->getVertex(0)->z()+e->getVertex(1)->z()+e->getVertex(2)->z());
  const double _diff = 1.0; 
  
  for (int j = 0; j < nbNodes; j++){
    for (int k = 0; k < nbNodes; k++){
      m(j,k) = -1.*_diff;
    }
    m(j,j) = (nbNodes-1)*_diff;
  }
  
}

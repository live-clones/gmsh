// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef BASISFACTORY_H
#define BASISFACTORY_H

#include "MElement.h"
#include "MPyramid.h"
#include "nodalBasis.h"

class BasisFactory
{
  private:
    static std::map<int, nodalBasis*> fs;

  public:
    // Caution: the returned pointer should be
    // checked against 0.
    static const nodalBasis* create(int elementType);
};

#endif

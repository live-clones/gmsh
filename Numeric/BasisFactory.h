// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef BASISFACTORY_H
#define BASISFACTORY_H

#include "MElement.h"
#include "MPyramid.h"
#include "nodalBasis.h"
#include "JacobianBasis.h"


class BasisFactory
{
  private:
    static std::map<int, nodalBasis*> fs;
    static std::map<int, bezierBasis*> bs;
    static std::map<int, JacobianBasis*> js;

  public:
    // Caution: the returned pointer can be NULL
    static const nodalBasis* getNodalBasis(int elementType);
    static const bezierBasis* getBezierBasis(int elementType);
    static const JacobianBasis* getJacobianBasis(int elementType);

    static void clearAll();
};

#endif

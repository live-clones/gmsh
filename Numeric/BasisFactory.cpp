// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-B-> Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"

std::map<int, nodalBasis*> BasisFactory::fs;

const nodalBasis* BasisFactory::create(int elementType) {

  // If the Basis has already been built, return it.
  std::map<int, nodalBasis*>::const_iterator it = fs.find(elementType);
  if (it != fs.end()) {
    return it->second;
  }
  // Get the parent type to see which kind of basis
  // we want to create
  int parentType = MElement::ParentTypeFromTag(elementType);
  nodalBasis* B = 0;

  switch(parentType) {
    case(TYPE_PNT):
    case(TYPE_LIN):
    case(TYPE_TRI):
    case(TYPE_QUA):
    case(TYPE_PRI):
    case(TYPE_TET):
    case(TYPE_HEX):
      B = new polynomialBasis(elementType);
      break;
    case(TYPE_PYR):
      B = new pyramidalBasis(elementType);
      break;
    default:
      Msg::Error("Unknown type of element.");
      return 0;
  }

  fs.insert(std::make_pair(elementType, B));

  return fs[elementType];

}

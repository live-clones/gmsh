// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-B-> Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"

std::map<int, nodalBasis*> BasisFactory::fs;
std::map<int, JacobianBasis*> BasisFactory::js;
std::map<int, bezierBasis*> BasisFactory::bs;

const nodalBasis* BasisFactory::getNodalBasis(int elementType)
{
  // If the Basis has already been built, return it.
  std::map<int, nodalBasis*>::const_iterator it = fs.find(elementType);
  if (it != fs.end()) {
    return it->second;
  }
  // Get the parent type to see which kind of basis
  // we want to create
  int parentType = MElement::ParentTypeFromTag(elementType);
  nodalBasis* F = NULL;

  switch(parentType) {
    case(TYPE_PNT):
    case(TYPE_LIN):
    case(TYPE_TRI):
    case(TYPE_QUA):
    case(TYPE_PRI):
    case(TYPE_TET):
    case(TYPE_HEX):
      F = new polynomialBasis(elementType);
      break;
    case(TYPE_PYR):
      F = new pyramidalBasis(elementType);
      break;
    default:
      Msg::Error("Unknown type of element %d (in BasisFactory)", elementType);
      return NULL;
  }

  // FIXME: check if already exists to deallocate if necessary
  fs.insert(std::make_pair(elementType, F));

  return fs[elementType];
}

const bezierBasis* BasisFactory::getBezierBasis(int elementType)
{
  std::map<int, bezierBasis*>::const_iterator it = bs.find(elementType);
  if (it != bs.end())
    return it->second;

  bezierBasis* B = new bezierBasis(elementType);
  if (B) bs.insert(std::make_pair(elementType, B));
  return B;
}

const JacobianBasis* BasisFactory::getJacobianBasis(int elementType)
{
  std::map<int, JacobianBasis*>::const_iterator it = js.find(elementType);
  if (it != js.end())
    return it->second;

  JacobianBasis* J = new JacobianBasis(elementType);
  if (J) js.insert(std::make_pair(elementType, J));
  return J;
}

void BasisFactory::clearAll()
{
  std::map<int, nodalBasis*>::iterator itF = fs.begin();
  while (itF != fs.end()) {
    delete itF->second;
    itF++;
  }
  fs.clear();

  std::map<int, JacobianBasis*>::iterator itJ = js.begin();
  while (itJ != js.end()) {
    delete itJ->second;
    itJ++;
  }
  js.clear();

  std::map<int, bezierBasis*>::iterator itB = bs.begin();
  while (itB != bs.end()) {
    delete itB->second;
    itB++;
  }
  bs.clear();
}

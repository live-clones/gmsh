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
#include "MElement.h"

std::map<int, nodalBasis*> BasisFactory::fs;
std::map<int, JacobianBasis*> BasisFactory::js;
BasisFactory::Cont_bezierBasis BasisFactory::bs;

const nodalBasis* BasisFactory::getNodalBasis(int tag)
{
  // If the Basis has already been built, return it.
  std::map<int, nodalBasis*>::const_iterator it = fs.find(tag);
  if (it != fs.end()) {
    return it->second;
  }
  // Get the parent type to see which kind of basis
  // we want to create
  int parentType = ElementType::ParentTypeFromTag(tag);
  nodalBasis* F = NULL;

  switch(parentType) {
    case(TYPE_PNT):
    case(TYPE_LIN):
    case(TYPE_TRI):
    case(TYPE_QUA):
    case(TYPE_PRI):
    case(TYPE_TET):
    case(TYPE_HEX):
      F = new polynomialBasis(tag);
      break;
    case(TYPE_PYR):
      F = new pyramidalBasis(tag);
      break;
    default:
      Msg::Error("Unknown type of element %d (in BasisFactory)", tag);
      return NULL;
  }

  // FIXME: check if already exists to deallocate if necessary
  std::pair<std::map<int, nodalBasis*>::const_iterator, bool> inserted;

  #pragma omp critical
    {
      inserted = fs.insert(std::make_pair(tag, F));

      if (!inserted.second)
        delete F;
    }

  return inserted.first->second;
}

const JacobianBasis* BasisFactory::getJacobianBasis(int tag)
{
  std::map<int, JacobianBasis*>::const_iterator it = js.find(tag);
  if (it != js.end())
    return it->second;

  JacobianBasis* J = new JacobianBasis(tag);
  js.insert(std::make_pair(tag, J));
  return J;
}

const bezierBasis* BasisFactory::getBezierBasis(int parentType, int order)
{
  Cont_bezierBasis::iterator it = bs.find(std::make_pair(parentType, order));
  if (it != bs.end())
    return it->second;

  bezierBasis* B = new bezierBasis(parentType, order);
  bs.insert(std::make_pair(std::make_pair(parentType, order), B));
  return B;
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

  Cont_bezierBasis::iterator itB = bs.begin();
  while (itB != bs.end()) {
    delete itB->second;
    itB++;
  }
  bs.clear();
}

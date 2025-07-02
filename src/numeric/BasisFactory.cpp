// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "BasisFactory.h"
#include "GmshDefines.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "bezierBasis.h"
#include "miniBasis.h"
#include "CondNumBasis.h"
#include "JacobianBasis.h"
#include <map>
#include <cstddef>

std::map<int, nodalBasis *> BasisFactory::fs;
std::map<int, CondNumBasis *> BasisFactory::cs;
std::map<FuncSpaceData, JacobianBasis *> BasisFactory::js;
std::map<FuncSpaceData, bezierBasis *> BasisFactory::bs;
std::map<FuncSpaceData, GradientBasis *> BasisFactory::gs;

const nodalBasis *BasisFactory::getNodalBasis(int tag)
{
  // If the Basis has already been built, return it.
  auto it = fs.find(tag);
  if(it != fs.end()) { return it->second; }

  // Get the parent type to see which kind of basis we want to create
  nodalBasis *F = nullptr;
  if(tag == MSH_TRI_MINI)
    F = new miniBasisTri();
  else if(tag == MSH_TET_MINI)
    F = new miniBasisTet();
  else {
    int parentType = ElementType::getParentType(tag);
    switch(parentType) {
    case(TYPE_PNT):
    case(TYPE_LIN):
    case(TYPE_TRI):
    case(TYPE_QUA):
    case(TYPE_PRI):
    case(TYPE_TET):
    case(TYPE_HEX): F = new polynomialBasis(tag); break;
    case(TYPE_PYR): F = new pyramidalBasis(tag); break;
    default:
      Msg::Error("Unknown type of element %d (in BasisFactory)", tag);
      return nullptr;
    }
  }

  std::pair<std::map<int, nodalBasis *>::const_iterator, bool> inserted;
#pragma omp critical(getNodalBasis)
  {
    inserted = fs.insert(std::make_pair(tag, F));
    if(!inserted.second) delete F;
  }

  return inserted.first->second;
}

const JacobianBasis *BasisFactory::getJacobianBasis(int tag, FuncSpaceData fsd)
{
  FuncSpaceData data = fsd.getForNonSerendipitySpace();

  auto it = js.find(data);
  if(it != js.end()) return it->second;

  JacobianBasis *J = new JacobianBasis(tag, data);

  std::pair<std::map<FuncSpaceData, JacobianBasis *>::const_iterator, bool> inserted;
#pragma omp critical(getJacobianBasis)
  {
    inserted = js.insert(std::make_pair(data, J));
    if(!inserted.second) delete J;
  }
  return inserted.first->second;
}

const JacobianBasis *BasisFactory::getJacobianBasis(int tag, int order)
{
  const int type = ElementType::getParentType(tag);
  if(type != TYPE_PYR)
    return getJacobianBasis(tag, FuncSpaceData(type, order, false));
  else
    return getJacobianBasis(
      tag, FuncSpaceData(type, false, order + 1, order, false));
}

const JacobianBasis *BasisFactory::getJacobianBasis(int tag)
{
  const int jacOrder = JacobianBasis::jacobianOrder(tag);
  const int type = ElementType::getParentType(tag);
  if(type != TYPE_PYR)
    return getJacobianBasis(tag, FuncSpaceData(type, jacOrder, false));
  else
    return getJacobianBasis(
      tag, FuncSpaceData(type, false, jacOrder + 2, jacOrder, false));
}

const CondNumBasis *BasisFactory::getCondNumBasis(int tag, int cnOrder)
{
  auto it = cs.find(tag);
  if(it != cs.end()) return it->second;

  CondNumBasis *M = new CondNumBasis(tag, cnOrder);

  std::pair<std::map<int, CondNumBasis *>::const_iterator, bool> inserted;
#pragma omp critical(getCondNumBasis)
  {
    inserted = cs.insert(std::make_pair(tag, M));
    if(!inserted.second) delete M;
  }
  return inserted.first->second;
}

const GradientBasis *BasisFactory::getGradientBasis(int tag, FuncSpaceData fsd)
{
  FuncSpaceData data = fsd.getForNonSerendipitySpace();

  auto it = gs.find(data);
  if(it != gs.end()) return it->second;

  GradientBasis *G = new GradientBasis(tag, data);

  std::pair<std::map<FuncSpaceData, GradientBasis *>::const_iterator, bool> inserted;
#pragma omp critical(getGradientBasis)
  {
    inserted = gs.insert(std::make_pair(data, G));
    if(!inserted.second) delete G;
  }
  return inserted.first->second;
}

const GradientBasis *BasisFactory::getGradientBasis(int tag, int order)
{
  const int type = ElementType::getParentType(tag);
  return getGradientBasis(tag, FuncSpaceData(type, order, false));
}

const GradientBasis *BasisFactory::getGradientBasis(int tag)
{
  return getGradientBasis(tag, FuncSpaceData(tag));
}

const bezierBasis *BasisFactory::getBezierBasis(FuncSpaceData fsd)
{
  FuncSpaceData data = fsd.getForNonSerendipitySpace();

  auto it = bs.find(data);
  if(it != bs.end()) return it->second;

  bezierBasis *B = new bezierBasis(data);

  std::pair<std::map<FuncSpaceData, bezierBasis *>::const_iterator, bool> inserted;
#pragma omp critical(getBezierBasis)
  {
    inserted = bs.insert(std::make_pair(data, B));
    if(!inserted.second) delete B;
  }
  return inserted.first->second;
}

const bezierBasis *BasisFactory::getBezierBasis(int parentType, int order)
{
  return getBezierBasis(FuncSpaceData(parentType, order, false));
}

const bezierBasis *BasisFactory::getBezierBasis(int tag)
{
  return getBezierBasis(FuncSpaceData(tag));
}

void BasisFactory::clearAll()
{
  auto itF = fs.begin();
  while(itF != fs.end()) {
    delete itF->second;
    itF++;
  }
  fs.clear();

  auto itJ = js.begin();
  while(itJ != js.end()) {
    delete itJ->second;
    itJ++;
  }
  js.clear();

  auto itC = cs.begin();
  while(itC != cs.end()) {
    delete itC->second;
    itC++;
  }
  cs.clear();

  auto itG = gs.begin();
  while(itG != gs.end()) {
    delete itG->second;
    itG++;
  }
  gs.clear();

  auto itB = bs.begin();
  while(itB != bs.end()) {
    delete itB->second;
    itB++;
  }
  bs.clear();
}

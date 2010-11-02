// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "MLine.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"

const polynomialBasis* MLine::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  
  switch (order) {
  case 0: return polynomialBases::find(MSH_LIN_1);
  case 1: return polynomialBases::find(MSH_LIN_2);
  case 2: return polynomialBases::find(MSH_LIN_3);
  case 3: return polynomialBases::find(MSH_LIN_4);
  case 4: return polynomialBases::find(MSH_LIN_5);
  case 5: return polynomialBases::find(MSH_LIN_6);
  case 6: return polynomialBases::find(MSH_LIN_7);
  case 7: return polynomialBases::find(MSH_LIN_8);
  case 8: return polynomialBases::find(MSH_LIN_9);
  case 9: return polynomialBases::find(MSH_LIN_10);
  case 10: return polynomialBases::find(MSH_LIN_11);
  default: Msg::Error("Order %d line function space not implemented", order);
  }
  return 0;
}

const JacobianBasis* MLine::getJacobianFuncSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  
  switch (order) {
  case 1: return JacobianBases::find(MSH_LIN_2);
  case 2: return JacobianBases::find(MSH_LIN_3);
  case 3: return JacobianBases::find(MSH_LIN_4);
  case 4: return JacobianBases::find(MSH_LIN_5);
  case 5: return JacobianBases::find(MSH_LIN_6);
  case 6: return JacobianBases::find(MSH_LIN_7);
  case 7: return JacobianBases::find(MSH_LIN_8);
  case 8: return JacobianBases::find(MSH_LIN_9);
  case 9: return JacobianBases::find(MSH_LIN_10);
  case 10: return JacobianBases::find(MSH_LIN_11);
  default: Msg::Error("Order %d line function space not implemented", order);
  }
  return 0;
}

void MLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQLPts(pOrder);
  *pts = getGQLPts(pOrder);
}

double MLine::getInnerRadius()
{
  return _v[0]->distance(_v[1]);
}

#include "Bindings.h"
static MLine* MLine_binding(std::vector<MVertex*> v) {
  if (v.size() == 2)
    return new MLine(v);
  if (v.size() == 3)
    return new MLine3(v);
  return new MLineN(v);
}

void MLine::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<MLine>("MLine");
  cb->setDescription("A line mesh element.");

  methodBinding *cm;
  cm = cb->addMethod("MLine",&MLine_binding);
  cm->setArgNames("vectorOfVertices", NULL);
  cm->setDescription("Create a new line mesh element with the given vertices. "
                     "First 2 vertices must correspond to the beginning/end of the line.");
//   cm = cb->setConstructor<MLine,MVertex*,MVertex*>();
//   cm->setArgNames("v0","v1", NULL);
//   cm->setDescription("Create a new line mesh element between v0 and v1.");
  cb->setParentClass<MElement>();
}

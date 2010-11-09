//
// C++ Interface: quadratureRules
//
// Description:
//
//
// Author:  <Eric Bechet>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _QUADRATURERULES_H_
#define _QUADRATURERULES_H_

#include "Gauss.h"
#include "MElement.h"

class QuadratureBase
{
  public :
  virtual ~QuadratureBase(){}
  virtual int getIntPoints(MElement *e,IntPt **GP) =0;
};


class GaussQuadrature : public QuadratureBase
{
 public :
  enum IntegCases {Other,Val,Grad,ValVal,GradGrad};
 private :
  int order;
  IntegCases info;
 public :
  GaussQuadrature(int order_=0):order(order_),info(Other) {}
  GaussQuadrature(IntegCases info_):order(0),info(info_) {}
  virtual ~GaussQuadrature(){}
  int getIntPoints(MElement *e,IntPt **GP)
  {
    int integrationOrder;
    int npts;
    int geoorder=e->getPolynomialOrder();
    switch(info)
    {
    case Other :
      integrationOrder = order;
      break;
    case Val :
      integrationOrder=geoorder+1;
      break;
    case Grad :
      integrationOrder=geoorder;
      break;
    case ValVal :
      integrationOrder=2*geoorder;
      break;
    case GradGrad :
      integrationOrder=3*(geoorder-1)+1;
      break;
    default : integrationOrder=1;
    }
    e->getIntegrationPoints(integrationOrder, &npts, GP);
    return npts;
  }
};


#endif //_QUADRATURERULES_H_

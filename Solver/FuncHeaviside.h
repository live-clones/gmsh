// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Boris Sedji
//

#ifndef _FUNCHEAVISIDE_H_
#define _FUNCHEAVISIDE_H_

#include "simpleFunction.h"
#include "gmshLevelset.h"

class FuncHeaviside : public  simpleFunctionOnElement<double> {
 private :

 gLevelset *_ls;

 public :
  FuncHeaviside(gLevelset *ls) : _ls(ls) { }
  virtual double operator() (double x, double y, double z) const {
    if (_ls->isInsideDomain (x, y, z))
      return 1;
    else
      return -1;
  }
  virtual double operator() (double x,double y,double z, MElement *e) const {
    if (_ls->isInsideDomain (x, y, z))
      return 1;
    else
      return -1;
  }
  virtual void gradient (double x, double y, double z,
			 double &dfdx, double &dfdy, double &dfdz) const
  { dfdx = dfdy = dfdz = 0.0; }
  virtual void gradient (double x, double y, double z,
			 double &dfdx, double &dfdy, double &dfdz, MElement *e) const
  { dfdx = dfdy = dfdz = 0.0; }
};

#endif

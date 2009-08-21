// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_LEVELSET_H_
#define _GMSH_LEVELSET_H_

#include <string>
#include <vector>
#include "GmshConfig.h"

#if defined(HAVE_DINTEGRATION)

#include "DILevelset.h"
#include "mathEvaluator.h"

class gLevelsetMathEval: public gLevelsetPrimitive
{
  mathEvaluator *_expr;
public:
  gLevelsetMathEval(std::string f, int &tag) : gLevelsetPrimitive(tag)
  {
    std::vector<std::string> expressions(1, f);
    std::vector<std::string> variables(3);
    variables[0] = "x";
    variables[1] = "y";
    variables[2] = "z";
    _expr = new mathEvaluator(expressions, variables);
  }
  ~gLevelsetMathEval(){ delete _expr; }
  virtual double operator () (const double &x, const double &y, const double &z) const
  {
    std::vector<double> values(3), res(1);
    values[0] = x;
    values[1] = y;
    values[2] = z;
    if(_expr->eval(values, res)) return res[0];
    return 0.;
  }
  int type() const { return UNKNOWN; }
};

#endif

#endif

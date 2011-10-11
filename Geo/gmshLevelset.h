// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
  gLevelsetMathEval(std::string f, int tag) : gLevelsetPrimitive(tag)
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
    return 1.;
  }
  int type() const { return UNKNOWN; }
};

#if defined(HAVE_POST)

#include "PView.h"
#include "OctreePost.h"

class gLevelsetPostView : public gLevelsetPrimitive
{
  int _viewIndex;
  OctreePost *_octree;
public:
  gLevelsetPostView(int index, int tag) : gLevelsetPrimitive(tag), _viewIndex(index)
  {
    if(_viewIndex >= 0 && _viewIndex < (int)PView::list.size()){
      PView *view = PView::list[_viewIndex];
      _octree = new OctreePost(view);
    }
    else{
      Msg::Error("Unknown View[%d] in PostView levelset", _viewIndex);
      _octree = 0;
    }
  }
  ~gLevelsetPostView(){ if(_octree) delete _octree; }
  virtual double operator () (const double &x, const double &y, const double &z) const
  {
    if(!_octree) return 1.;
    double val = 1.;
    _octree->searchScalar(x, y, z, &val, 0);
    return val;
  }
  int type() const { return UNKNOWN; }
};

#endif

#endif

#endif

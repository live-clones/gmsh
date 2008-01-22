#ifndef _DISCRETE_EDGE_H_
#define _DISCRETE_EDGE_H_

#include "GModel.h"
#include "GEdge.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

class discreteEdge : public GEdge {
 public:
  discreteEdge(GModel *model, int num) : GEdge(model, num, 0, 0) 
  {
#if !defined(HAVE_GMSH_EMBEDDED)
    Curve *c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
    Tree_Add(model->getGEOInternals()->Curves, &c);
    CreateReversedCurve(c);
#endif
  }
  virtual ~discreteEdge() {}
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const { throw; }
  virtual int containsParam(double pt) const { throw; }
  virtual SVector3 firstDer(double par) const { throw; }
  virtual double parFromPoint(const SPoint3 &pt) const { throw; }
};

#endif

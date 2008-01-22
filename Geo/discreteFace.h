#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GModel.h"
#include "GFace.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

class discreteFace : public GFace {
 public:
  discreteFace(GModel *model, int num) : GFace(model, num)
  {
#if !defined(HAVE_GMSH_EMBEDDED)
    Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
    Tree_Add(model->getGEOInternals()->Surfaces, &s);
#endif
    meshStatistics.status = GFace::DONE;    
  }
  virtual ~discreteFace() {}
  virtual GPoint point(double par1, double par2) const { throw; }
  virtual SPoint2 parFromPoint(const SPoint3 &p) const { throw; }
  virtual int containsParam(const SPoint2 &pt) const { throw; }
  virtual SVector3 normal(const SPoint2 &param) const { throw; }
  virtual GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const { throw; }
};

#endif


#ifndef _DISCRETE_REGION_H_
#define _DISCRETE_REGION_H_

#include "GRegion.h"

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

class discreteRegion : public GRegion {
 public:
  discreteRegion(GModel *model, int num) : GRegion(model, num)
  {
#if !defined(HAVE_GMSH_EMBEDDED)
    ::Volume *v = Create_Volume(num, MSH_VOLUME_DISCRETE);
    Tree_Add(model->getGEOInternals()->Volumes, &v);
#endif
  }
  virtual ~discreteRegion() {}
  virtual GeomType geomType() const { return DiscreteVolume; }
};

#endif

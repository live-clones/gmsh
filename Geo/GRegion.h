#ifndef H_GRegion
#define H_GRegion

#include "GEntity.h"

/** A model region. */
class GRegion : public GEntity {
 protected:
  std::list<GFace *> l_faces;
  std::list<int>     l_dirs;
public:
  GRegion(GModel *model, int tag) : GEntity (model,tag) {}
  virtual ~GRegion();
  virtual int dim() const {return 3;}
  virtual GeomType geomType() const {return ThreeDimVolume;}
};

#endif


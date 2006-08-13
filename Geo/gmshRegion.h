#ifndef _GMSH_REGION_H_
#define _GMSH_REGION_H_

#include "Mesh.h"
#include "gmshModel.h"
#include "GRegion.h"

class gmshRegion : public GRegion {
 protected:
  ::Volume *v;

 public:
  gmshRegion(GModel *m, ::Volume *_v);
  gmshRegion(GModel *m, int num);
  virtual ~gmshRegion() {}
  virtual GeomType geomType() const;
  void * getNativePtr() const { return v; }
};

#endif

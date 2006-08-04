#ifndef _GMSH_REGION_H_
#define _GMSH_REGION_H_

#include "Mesh.h"
#include "gmshModel.h"
#include "GRegion.h"

class gmshRegion : public GRegion {
public:
  gmshRegion(GModel *m, ::Volume *_v);
  gmshRegion(GModel *m, int num);
  virtual ~gmshRegion() {}
  void * getNativePtr() const {return v;}
  ::Volume *v;
protected:

};

#endif

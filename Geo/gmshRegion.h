#ifndef _GMSH_REGION_H_
#define _GMSH_REGION_H_

#include "Mesh.h"
#include "gmshModel.h"
#include "GRegion.h"

class gmshRegion : public GRegion {
public:
  gmshRegion(GModel *m, ::Volume *_v);
  virtual ~gmshRegion() {}

  //  virtual GeoRep * geometry(){return 0;}

  virtual double tolerance() const {return 1.e-14;}

  void * getNativePtr() const {return v;}
  ::Volume *v;
protected:

};

#endif

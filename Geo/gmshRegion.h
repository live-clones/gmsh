#ifndef _H_GMSH_REGION_
#define _H_GMSH_REGION_

#include "Mesh.h"
#include "gmshModel.h"
#include "GRegion.h"

class gmshRegion : public GRegion {
public:
  gmshRegion(GModel *m, Volume *_v);
  virtual ~gmshRegion() {}

  //  virtual GeoRep * geometry(){return 0;}

  virtual double tolerance() const {return 1.e-14;}

  void * getNativePtr() const {return v;}
  Volume *v;
protected:

};
#endif


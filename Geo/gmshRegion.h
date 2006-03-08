#ifndef _H_GMSH_REGION_
#define _H_GMSH_REGION_

#include "Mesh.h"
#include "gmshModel.h"
#ifdef _HAVE_SGMODEL_
#include "GRegion.h"
#else
class GRegion {
 public:
  GRegion(SGModel *m, int tag){}
};
#endif

class gmshRegion : public GRegion {
public:
  gmshRegion(SGModel *m, Volume *_v)
    : GRegion(m, _v->Num), v(_v)
    {
      
    }
  virtual ~gmshRegion() {}

  virtual GeoRep * geometry(){return 0;}

  virtual double tolerance() const {return 1.e-14;}

  void * getNativePtr() {return v;}
  Volume *v;
protected:

};
#endif


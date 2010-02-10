// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_REGION_H_
#define _GMSH_REGION_H_

#include "Geo.h"
#include "GRegion.h"

class gmshRegion : public GRegion {
 protected:
  ::Volume *v;
 public:
  gmshRegion(GModel *m, ::Volume *_v);
  virtual ~gmshRegion() {}
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return v; }
  virtual void resetMeshAttributes();
};

#endif

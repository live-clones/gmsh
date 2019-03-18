// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_REGION_H
#define GMSH_REGION_H

#include "GRegion.h"

class Volume;

class gmshRegion : public GRegion {
protected:
  ::Volume *v;

public:
  gmshRegion(GModel *m, ::Volume *_v);
  virtual ~gmshRegion() {}
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return v; }
  virtual void resetMeshAttributes();
  void resetNativePtr(::Volume *_v);
};

#endif

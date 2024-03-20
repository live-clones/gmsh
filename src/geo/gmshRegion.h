// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_REGION_H
#define GMSH_REGION_H

#include "GRegion.h"

class Volume;

class gmshRegion : public GRegion {
private:
  ::Volume *_v;

public:
  gmshRegion(GModel *m, ::Volume *v);
  virtual ~gmshRegion() {}
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return _v; }
  virtual void resetMeshAttributes();
  void resetNativePtr(::Volume *v);
};

#endif

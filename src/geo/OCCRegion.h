// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCC_REGION_H
#define OCC_REGION_H

#include "GmshConfig.h"
#include "GRegion.h"

#if defined(HAVE_OCC)

#include <TopoDS_Solid.hxx>

class OCCRegion : public GRegion {
private:
  TopoDS_Solid _s;
  void _setup();

public:
  OCCRegion(GModel *m, TopoDS_Solid s, int num);
  virtual ~OCCRegion() {}
  virtual SBoundingBox3d bounds(bool fast = false);
  virtual GeomType geomType() const;
  virtual ModelType getNativeType() const { return OpenCascadeModel; }
  virtual void *getNativePtr() const { return (void *)&_s; }
  virtual bool containsPoint(const SPoint3 &pt) const;
  void writeBREP(const char *filename);
};

#endif

#endif

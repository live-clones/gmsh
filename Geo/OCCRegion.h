// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCC_REGION_H
#define OCC_REGION_H

#include "GmshConfig.h"
#include "GRegion.h"

#if defined(HAVE_OCC)

#include <TopoDS_Solid.hxx>

class OCCRegion : public GRegion {
protected:
  TopoDS_Solid s;
  void setup();

public:
  OCCRegion(GModel *m, TopoDS_Solid s, int num);
  virtual ~OCCRegion();
  virtual SBoundingBox3d bounds(bool fast = false) const;
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return OpenCascadeModel; }
  void *getNativePtr() const { return (void *)&s; }
  TopoDS_Solid getTopoDS_Shape() { return s; }
  void writeBREP(const char *filename);
};

#endif

#endif

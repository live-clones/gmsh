// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCC_REGION_H_
#define _OCC_REGION_H_

#include "GmshConfig.h"
#include "GRegion.h"

#if defined(HAVE_OCC)

class OCCRegion : public GRegion {
 protected:
  TopoDS_Solid s;
  void replaceFacesInternal (std::list<GFace*> &);
  void setup();
 public:
  OCCRegion(GModel *m, TopoDS_Solid s, int num);
  virtual ~OCCRegion() {}
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&s; }
  TopoDS_Solid getTopoDS_Shape() {return s;}
};

GRegion *getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind);

#endif

#endif

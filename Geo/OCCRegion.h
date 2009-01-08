// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
 public:
  OCCRegion(GModel *m, TopoDS_Solid s, int num, TopTools_IndexedMapOfShape &fmap);
  virtual ~OCCRegion() {}
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&s; }
};

#endif

#endif

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GREGION_COMPOUND_H_
#define _GREGION_COMPOUND_H_

#include <list>
#include <map>
#include "GRegion.h"
#include "GFace.h"
#include "GFaceCompound.h"

/*
A GRegionCompound is a model region that is the compound of model regions.

It is assumed that all the regions of the compound have been meshed
first and that all the faces of the compound region are compound surfaces.

The compound can therefore be re-meshed using any surface mesh
generator of gmsh!
*/

class GRegionCompound : public GRegion {
 public:
  GRegionCompound(GModel *m, int tag, std::vector<GRegion*> &compound);
  virtual ~GRegionCompound();
  virtual SBoundingBox3d bounds() const;
  virtual double curvature(double t) const;
  virtual GPoint point(double par) const; 
  virtual SVector3 firstDer(double par) const; 
  virtual GEntity::GeomType geomType() const { return CompoundVolume; }
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }

 protected:
 std::vector<GRegion*> _compound;
void getBoundingFaces();

};

#endif


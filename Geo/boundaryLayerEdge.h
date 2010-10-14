// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BOUNDARY_LAYER_EDGE_H_
#define _BOUNDARY_LAYER_EDGE_H_

#include "discreteEdge.h"

class Field;

class boundaryLayerEdge : public discreteEdge {
 private:
  // original entity from which this part of the boundary layer is
  // extruded
  GEntity *_orig;
 public:
  boundaryLayerEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1, 
                    GEntity *orig) 
    : discreteEdge(model, num, _v0, _v1), _orig(orig)  {}
  virtual ~boundaryLayerEdge() {}
  virtual GeomType geomType() const { return BoundaryLayerCurve; }
  GEntity *getOriginalEntity(){ return _orig; }
};

#endif

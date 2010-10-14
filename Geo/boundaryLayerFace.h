// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BOUNDARY_LAYER_FACE_H_
#define _BOUNDARY_LAYER_FACE_H_

#include "discreteFace.h"

class Field;

class boundaryLayerFace : public discreteFace {
 private:
  // list of entities from which the whole boundary layer is created
  std::vector<GEntity*> _source;
  // field providing extrude information
  Field *_field;
  // original entity from which this part of the boundary layer is
  // extruded
  GEntity *_orig;
 public:
  boundaryLayerFace(GModel *model, int num, std::vector<GEntity*> source, 
                    Field *field, GEntity *orig) 
    : discreteFace(model, num), _source(source), _field(field), _orig(orig){}
  virtual ~boundaryLayerFace() {}
  GEntity::GeomType geomType() const { return BoundaryLayerSurface; }
  std::vector<GEntity*> &getSourceEntities(){ return _source; }
  Field * getField(){ return _field; }
  GEntity *getSourceEntity(){ return _orig; }
};

#endif

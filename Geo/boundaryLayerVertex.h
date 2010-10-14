// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BOUNDARY_LAYER_VERTEX_H_
#define _BOUNDARY_LAYER_VERTEX_H_

#include "discreteVertex.h"

class boundaryLayerVertex : public discreteVertex {
 private:
  // original entity from which this part of the boundary layer is
  // extruded
  GVertex *_orig;
 public:
  boundaryLayerVertex(GModel *m, int num, GVertex *orig) 
    : discreteVertex(m, num), _orig(orig)
  {
    // don't wait for Mesh0D to create the mesh vertex, as it is used
    // to remove duplicates during model creation (before any mesh
    // generation is performed)
    mesh_vertices.push_back(new MVertex(orig->x(), orig->y(), orig->z(), this));
  }
  virtual ~boundaryLayerVertex(){}
  virtual GeomType geomType() const { return BoundaryLayerPoint; }
};

#endif

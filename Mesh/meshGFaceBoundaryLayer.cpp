// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <set>
#include "GModel.h"
#include "boundaryLayerEdge.h"
#include "boundaryLayerFace.h"

int MeshBoundaryLayerSurface(GFace *gf)
{
  // old boundary layers
  if(gf->geomType() == GEntity::BoundaryLayerSurface &&
     gf->getNativeType() == GEntity::GmshModel) 
    return 1;
  
  if(gf->geomType() != GEntity::BoundaryLayerSurface)
    return 0;
  
  Msg::Info("Meshing surface %d (boundary layer)", gf->tag());

  boundaryLayerFace *bf = static_cast<boundaryLayerFace*>(gf);

  std::vector<GEntity*> &source(bf->getSourceEntities());
  if(source.empty()){
    Msg::Error("No source entities for boundary layer mesh");
    return 0;
  }
  if(source[0]->dim() != 1){
    Msg::Error("New boundary layer code only implemented in 2D");
    return 0;
  }

  GEdge *ge = static_cast<GEdge*>(source[0]);
  if(ge->getNormals().empty()){
    Msg::Info("Computing smoothed normal field on source curves");
  }

  gf->meshStatistics.status = GFace::DONE;
  return 1;
}

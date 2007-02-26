// $Id: BoundaryLayer.cpp,v 1.1 2007-02-26 08:25:39 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "BoundaryLayer.h"
#include "ExtrudeParams.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "Message.h"

template<class T>
static void addExtrudeNormals(std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    for(int j = 0; j < ele->getNumFaces(); j++){
      MFace fac = ele->getFace(j);
      SVector3 n = fac.normal();
      if(n[0] || n[1] || n[2]){
	double nn[3] = {n[0], n[1], n[2]};
	for(int k = 0; k < fac.getNumVertices(); k++){
	  MVertex *v = fac.getVertex(k);
	  SPoint3 p(v->x(), v->y(), v->z());
	  ExtrudeParams::normals->add(p[0], p[1], p[2], 3, nn);
	}
      }
    }
  }
}
  
int MeshBoundaryLayerFaces(GModel *m)
{
  bool haveBoundaryLayers = false;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      haveBoundaryLayers = true;
      break;
    }
  }
  if(!haveBoundaryLayers) return 0;

  // make sure the surface mesh is oriented correctly (normally we do
  // this only after the 3D mesh is done; but here it's critical since
  // we use the normals for the extrusion)
  std::for_each(m->firstFace(), m->lastFace(), orientMeshGFace());

  // compute a smooth normal field on all the surfaces giving rise to
  // boundary layers
  if(ExtrudeParams::normals) delete ExtrudeParams::normals;
  ExtrudeParams::normals = new smooth_data();
  ExtrudeParams *myep = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      ExtrudeParams *ep = myep = gf->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
	GFace *from = gf->model()->faceByTag(std::abs(ep->geo.Source));
	if(!from){
	  Msg(GERROR, "Unknown source face %d for boundary layer", ep->geo.Source);
	  continue;
	}
	addExtrudeNormals(from->triangles);
	addExtrudeNormals(from->quadrangles);
      }
    }
  }
  if(!myep) return 0;

  // set the position of bounding points (FIXME: should check
  // coherence of all extrude parameters)
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++){
    GVertex *gv = *it;
    if(gv->geomType() == GEntity::BoundaryLayerPoint){
      double x = gv->x();
      double y = gv->y();
      double z = gv->z();
      myep->Extrude(myep->mesh.NbLayer - 1, myep->mesh.NbElmLayer[myep->mesh.NbLayer - 1],
		    x, y, z);
      gv->mesh_vertices[0]->x() = x;
      gv->mesh_vertices[0]->y() = y;
      gv->mesh_vertices[0]->z() = z;
    }
  }
  
  // mesh the curves bounding the boundary layers by extrusion using
  // the smooth normal field
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++){
    GEdge *ge = *it;
    if(ge->geomType() == GEntity::BoundaryLayerCurve){
      Msg(INFO, "Meshing curve %d", ge->tag());
      deMeshGEdge dem;
      dem(ge);
      MeshExtrudedCurve(ge);
    }
  }

  // mesh the surfaces bounding the boundary layers by extrusion using
  // the smooth normal field
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      Msg(STATUS2, "Meshing surface %d (%s)", gf->tag(), gf->getTypeString().c_str());
      deMeshGFace dem;
      dem(gf);
      MeshExtrudedSurface(gf);
    }
  }

  return 1;
}

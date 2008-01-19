// $Id: BoundaryLayer.cpp,v 1.7 2008-01-19 22:06:03 geuzaine Exp $
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

#include "GModel.h"
#include "MElement.h"
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

int Mesh2DWithBoundaryLayers(GModel *m)
{
  std::set<GFace*> sourceFaces, otherFaces;
  std::set<GEdge*> sourceEdges, otherEdges;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      ExtrudeParams *ep = gf->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
	GFace *from = m->faceByTag(std::abs(ep->geo.Source));
	if(!from){
	  Msg(GERROR, "Unknown source face %d for boundary layer", ep->geo.Source);
	  return 0;
	}
	sourceFaces.insert(from);
	std::list<GEdge*> e = from->edges();
	sourceEdges.insert(e.begin(), e.end());
      }
    }
  }
  if(sourceFaces.empty()) return 0;

  // compute set of non-source edges and faces
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
    if(sourceEdges.find(*it) == sourceEdges.end()) otherEdges.insert(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
    if(sourceFaces.find(*it) == sourceFaces.end()) otherFaces.insert(*it);

  // mesh source surfaces
  std::for_each(sourceFaces.begin(), sourceFaces.end(), meshGFace());  
  
  // make sure the source surfaces for the boundary layers are
  // oriented correctly (normally we do this only after the 3D mesh is
  // done; but here it's critical since we use the normals for the
  // extrusion)
  std::for_each(sourceFaces.begin(), sourceFaces.end(), orientMeshGFace());

  // compute a normal field for all the source faces
  if(ExtrudeParams::normals) delete ExtrudeParams::normals;
  ExtrudeParams::normals = new smooth_data();
  for(std::set<GFace*>::iterator it = sourceFaces.begin(); 
      it != sourceFaces.end(); it++){
    GFace *gf = *it;
    addExtrudeNormals(gf->triangles);
    addExtrudeNormals(gf->quadrangles);
  }
  ExtrudeParams::normals->normalize();

  // set the position of boundary layer points using the smooth normal
  // field 
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++){
    GEdge *ge = *it;
    if(ge->geomType() == GEntity::BoundaryLayerCurve){
      ExtrudeParams *ep = ge->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY){
	GVertex *vsrc, *vdest;
	if(ge->getBeginVertex()->geomType() == GEntity::BoundaryLayerPoint){
	  vsrc = ge->getEndVertex();
	  vdest = ge->getBeginVertex();
	}
	else{
	  vsrc = ge->getBeginVertex();
	  vdest = ge->getEndVertex();
	}
	GPoint p = vsrc->point();
	ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
		    p.x(), p.y(), p.z());
	vdest->setPosition(p);
      }
    }
  }
  
  // remesh non-source edges (since they might have been modified by
  // the change in boundary layer points)
  std::for_each(otherFaces.begin(), otherFaces.end(), deMeshGFace());
  std::for_each(otherEdges.begin(), otherEdges.end(), meshGEdge());

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

  // mesh non-source surfaces
  std::for_each(otherFaces.begin(), otherFaces.end(), meshGFace());  

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

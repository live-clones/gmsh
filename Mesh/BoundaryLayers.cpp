// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MElement.h"
#include "BoundaryLayers.h"
#include "ExtrudeParams.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "GmshMessage.h"

template<class T>
static void addExtrudeNormals(std::vector<T*> &elements, int invert)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *ele = elements[i];
    for(int j = 0; j < ele->getNumFaces(); j++){
      MFace fac = ele->getFace(j);
      SVector3 n = fac.normal();
      if(invert) n *= -1.;
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
  std::map<int, bool> sourceFaceInvert;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      ExtrudeParams *ep = gf->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
        GFace *from = m->getFaceByTag(std::abs(ep->geo.Source));
        if(!from){
          Msg::Error("Unknown source face %d for boundary layer", ep->geo.Source);
          return 0;
        }
	if(ep->geo.Source < 0) sourceFaceInvert[from->tag()] = true;
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
    addExtrudeNormals(gf->triangles, sourceFaceInvert.count(gf->tag()));
    addExtrudeNormals(gf->quadrangles, sourceFaceInvert.count(gf->tag()));
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
      Msg::Info("Meshing curve %d", ge->tag());
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
      Msg::StatusBar(2, true, "Meshing surface %d (%s)", gf->tag(), 
		     gf->getTypeString().c_str());
      deMeshGFace dem;
      dem(gf);
      MeshExtrudedSurface(gf);
    }
  }

  return 1;
}

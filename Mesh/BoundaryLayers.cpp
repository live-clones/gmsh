// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "BoundaryLayers.h"
#include "ExtrudeParams.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "GmshMessage.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "OctreePost.h"
#else
class OctreePost{ int dummy; };
#endif

template<class T>
static void addExtrudeNormals(std::vector<T*> &elements, int invert,
                              OctreePost *octree, bool gouraud, int index)
{
  if(index < 0 || index > 1){
    Msg::Error("Boundary layer index should be 0 or 1");
    return;
  }
 
  if(octree && !gouraud){ // get extrusion direction from post-processing view
    std::set<MVertex*> verts;
    for(unsigned int i = 0; i < elements.size(); i++)
      for(int j = 0; j < elements[i]->getNumVertices(); j++)
        verts.insert(elements[i]->getVertex(j));
    for(std::set<MVertex*>::iterator it = verts.begin(); it != verts.end(); it++){
      MVertex *v = *it;
      double nn[3] = {0., 0., 0.};
#if defined(HAVE_POST)
      octree->searchVector(v->x(), v->y(), v->z(), nn, 0);
#endif
      ExtrudeParams::normals[index]->add(v->x(), v->y(), v->z(), 3, nn);
    }
  }
  else{ // get extrusion direction from Gouraud-shaded element normals
    printf("get extrusion from normals \n");
    for(unsigned int i = 0; i < elements.size(); i++){
      MElement *ele = elements[i];
      SVector3 n(0, 0, 0);
      if(ele->getDim() == 2)
        n = ele->getFace(0).normal();
      else if(ele->getDim() == 1) // FIXME: generalize this!
        n = crossprod(ele->getEdge(0).tangent(), SVector3(0., 0., 1.));
      if(invert) n *= -1.;
      double nn[3] = {n[0], n[1], n[2]};
      for(int k = 0; k < ele->getNumVertices(); k++){
        MVertex *v = ele->getVertex(k);
        ExtrudeParams::normals[index]->add(v->x(), v->y(), v->z(), 3, nn);
      }
    }
  }
}

typedef std::set<std::pair<bool, std::pair<int, int> > > infoset;

template<class T>
static void addExtrudeNormals(std::set<T*> &entities,
                              std::map<int, infoset> &infos)
{
  bool normalize = true, special3dbox = false;
  std::vector<OctreePost*> octrees;

  for(typename std::set<T*>::iterator it = entities.begin(); it != entities.end(); it++){
    T *ge = *it;
    infoset info = infos[ge->tag()];
    for(infoset::iterator it2 = info.begin(); it2 != info.end(); it2++){
      bool invert = it2->first;
      int index = it2->second.first;
      int view = it2->second.second;
      bool gouraud = true;
      OctreePost *octree = 0;
#if defined(HAVE_POST)
      if(view != -1){
	printf("extrude normals with view %d \n", view);
        if(view >= 0 && view < (int)PView::list.size()){
          octree = new OctreePost(PView::list[view]);
          if(PView::list[view]->getData()->getNumVectors())
            gouraud = false;
          octrees.push_back(octree);
        }
        else if(view == -3){
          // Force extrusion normals along x,y,z axes for single
          // normals or at 45 degrees for multiple normals (allows to
          // build nice 3D "boxes")
          special3dbox = true;
        }
        else
          Msg::Error("Unknown View[%d]: using normals instead", view);
      }
#endif
      if(ge->dim() == 1)
        addExtrudeNormals(((GEdge*)ge)->lines, invert, octree, gouraud, index);
      else if(ge->dim() == 2){
        addExtrudeNormals(((GFace*)ge)->triangles, invert, octree, gouraud, index);
        addExtrudeNormals(((GFace*)ge)->quadrangles, invert, octree, gouraud, index);
      }
      if(!gouraud) normalize = false;
    }
  }

  // enforce coherent normals at some points if necessary
  for(unsigned int i = 0; i < ExtrudeParams::normalsCoherence.size(); i++){
    SPoint3 &p(ExtrudeParams::normalsCoherence[i]);
    double n0[3], n1[3];
    ExtrudeParams::normals[0]->get(p.x(), p.y(), p.z(), 3, n0);
    ExtrudeParams::normals[1]->get(p.x(), p.y(), p.z(), 3, n1);
    ExtrudeParams::normals[0]->add(p.x(), p.y(), p.z(), 3, n1);
    ExtrudeParams::normals[1]->add(p.x(), p.y(), p.z(), 3, n0);
  }

  // normalize extrusion directions if not using explicit vector
  // post-processing views
  if(normalize){
    for(int i = 0; i < 2; i++){
      ExtrudeParams::normals[i]->normalize();
      if(special3dbox){ // force normals for 3d "box" along x,y,z
        for(smooth_data::iter it = ExtrudeParams::normals[i]->begin();
            it != ExtrudeParams::normals[i]->end(); it++){
          for(int j = 0; j < 3; j++){
            if(it->vals[j] < -0.1) it->vals[j] = -1.;
            else if(it->vals[j] > 0.1) it->vals[j] = 1.;
            else it->vals[j] = 0.;
          }
        }
      }
#if defined(HAVE_POST)
      if(octrees.size()){ // scale normals by scalar views
        for(smooth_data::iter it = ExtrudeParams::normals[i]->begin();
            it != ExtrudeParams::normals[i]->end(); it++){
          for(unsigned int j = 0; j < octrees.size(); j++){
            double d;
            if(octrees[j]->searchScalarWithTol(it->x, it->y, it->z, &d, 0)){
              for(int k = 0; k < 3; k++) it->vals[k] *= d;
              break;
            }
          }
        }
      }
#endif
    }
  }

  for(unsigned int i = 0; i < octrees.size(); i++)
    delete octrees[i];
}

static void checkDepends(GModel *m, GFace *f, std::set<GFace*> &dep)
{
  ExtrudeParams *ep = f->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
    GFace *from = m->getFaceByTag(std::abs(ep->geo.Source));
    if(!from){
      Msg::Error("Unknown origin face %d", ep->geo.Source);
      return;
    }
    dep.insert(from);
    checkDepends(m, from, dep);
  }
}

int Mesh2DWithBoundaryLayers(GModel *m)
{
  std::set<GFace*> sourceFaces, otherFaces;
  std::set<GEdge*> sourceEdges, otherEdges;
  std::map<int, infoset> sourceFaceInfo, sourceEdgeInfo;

  // 2D boundary layers
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++){
    GEdge *ge = *it;
    if(ge->getNativeType() == GEntity::GmshModel &&
       ge->geomType() == GEntity::BoundaryLayerCurve){
      ExtrudeParams *ep = ge->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
        GEdge *from = m->getEdgeByTag(std::abs(ep->geo.Source));
        if(!from){
          Msg::Error("Unknown source curve %d for boundary layer", ep->geo.Source);
          return 0;
        }
	//printf("index edge (%d)  =%d \n", ge->tag(), ep->mesh.BoundaryLayerIndex);
        std::pair<bool, std::pair<int, int> > tags
          (ep->geo.Source < 0, std::pair<int, int>
           (ep->mesh.BoundaryLayerIndex, ep->mesh.ViewIndex));
        sourceEdgeInfo[from->tag()].insert(tags);
        sourceEdges.insert(from);
      }
    }
  }

  // 3D boundary layers
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->getNativeType() == GEntity::GmshModel &&
       gf->geomType() == GEntity::BoundaryLayerSurface){
      ExtrudeParams *ep = gf->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY){
        GFace *from = m->getFaceByTag(std::abs(ep->geo.Source));
        if(!from){
          Msg::Error("Unknown source face %d for boundary layer", ep->geo.Source);
          return 0;
        }
	//printf("index surface (%d)  =%d \n", gf->tag(), ep->mesh.BoundaryLayerIndex);
        std::pair<bool, std::pair<int, int> > tags
          (ep->geo.Source < 0, std::pair<int, int>
           (ep->mesh.BoundaryLayerIndex, ep->mesh.ViewIndex));
        sourceFaceInfo[from->tag()].insert(tags);
        sourceFaces.insert(from);
        std::list<GEdge*> e = from->edges();
        sourceEdges.insert(e.begin(), e.end());
      }
    }
  }

  if(sourceEdges.empty() && sourceFaces.empty()) return 0;

  // compute mesh dependencies in source faces (so we can e.g. create
  // a boundary layer on an extruded mesh)
  std::set<GFace*> sourceFacesDependencies;
  for(std::set<GFace*>::iterator it = sourceFaces.begin(); it != sourceFaces.end(); it++)
    checkDepends(m, *it, sourceFacesDependencies);
  Msg::Info("%d dependencies in mesh of source faces", sourceFacesDependencies.size());
  for(std::set<GFace*>::iterator it = sourceFacesDependencies.begin();
      it != sourceFacesDependencies.end(); it++){
    std::list<GEdge*> e = (*it)->edges();
    sourceEdges.insert(e.begin(), e.end());
  }

  // compute set of non-source edges and faces
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
    if(sourceEdges.find(*it) == sourceEdges.end()) otherEdges.insert(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
    if(sourceFaces.find(*it) == sourceFaces.end() &&
       sourceFacesDependencies.find(*it) == sourceFacesDependencies.end())
      otherFaces.insert(*it);

  // mesh source surfaces (and dependencies)
  for(int i = 0; i < 10; i++) // FIXME: should check PENDING status instead!
    std::for_each(sourceFacesDependencies.begin(), sourceFacesDependencies.end(),
                  meshGFace());
  std::for_each(sourceFaces.begin(), sourceFaces.end(), meshGFace());

  // make sure the source surfaces for the boundary layers are
  // oriented correctly (normally we do this only after the 3D mesh is
  // done; but here it's critical since we use the normals for the
  // extrusion)
  std::for_each(sourceFaces.begin(), sourceFaces.end(), orientMeshGFace());

  // compute a normal field for all the source edges or faces
  for(int i = 0; i < 2; i++){
    if(ExtrudeParams::normals[i]) delete ExtrudeParams::normals[i];
    ExtrudeParams::normals[i] = new smooth_data();
  }
  if(sourceFaces.empty())
    addExtrudeNormals(sourceEdges, sourceEdgeInfo);
  else
    addExtrudeNormals(sourceFaces, sourceFaceInfo);

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

  // recompute mean plane for plane surfaces just in case
  for(std::set<GFace*>::iterator it = otherFaces.begin(); it != otherFaces.end(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::Plane)
      gf->computeMeanPlane();
  }

  // mesh non-source surfaces
  std::for_each(otherFaces.begin(), otherFaces.end(), meshGFace());

  // mesh the surfaces bounding the boundary layers by extrusion using
  // the smooth normal field
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++){
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface){
      Msg::Info("Meshing surface %d (%s)", gf->tag(), gf->getTypeString().c_str());
      deMeshGFace dem;
      dem(gf);
      MeshExtrudedSurface(gf);
    }
  }

  return 1;
}

// give it a try : add one quad layer on the
  /*
void addOneLayerOnContour(GFace *gf, GVertex *gv){
, int nbLayers, double hplus, double factor){
  // for each vertex
  std::map<MVertex*,std::vector<MVertex*> >layers;
  std::vector<MQuadrangle*> newQuads;
  std::vector<MTriangle*> newTris;

  std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin();
  for (; it != gf->edgeLoops.end(); ++it){
    bool found = false;
    std::list<GEdge*> ed;
    for (GEdgeLoop::iter it2 = it->begin(); it2 != it->end(); ++it2){
      if (it2->ge->getBeginVertex() == gv || it2->ge->getEndVertex() == gv) {
	found = true;
      }
      ed.push_back(it2->ge);
    }
    // we found an edge loop with the GVertex that was specified
    if (found){
      // compute model vertices that will produce fans
      for (GEdgeLoop::iter it2 = it->begin(); it2 != it->end(); ++it2){
	GEdgeLoop::iter it3 = it2; ++it3;
	GVertex *gv = it2->getEndVertex();
	GEdgeSigned *before,*after = *it2;
	if (it3 == it->end()){
	  before = *(it->begin());
	}
	else{
	  before = *it2;
	}
      }

      for (std::list<GEdge*>::iterator it = ed.begin(); it != ed.end(); ++it){
	GEdge *ge = *it;
	for (int i=0;i<ge->lines.size();i++){
	  SPoint2 p[2];
	  reparamMeshEdgeOnFace ( ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1),gf,p[0],p[1]);
	  MVertex *vd[2];
	  for (int j=0;j<2;j++){
	    MVertex *v = ge->lines[i]->getVertex(j);
	    std::map<MVertex*,MVertex*>::iterator itv = duplicates.find(v);
	    if (itv == duplicates.end()){
	      vd[j] = new MFaceVertex(v->x(),v->y(),v->z(),gf,p[j].x(),p[j].y());
	      duplicates[v] = vd[j];
	      gf->mesh_vertices.push_back(vd[j]);
	    }
	    else
	      vd[j] = itv->second;
	  }
	  newQuads.push_back(new MQuadrangle(ge->lines[i]->getVertex(0), ge->lines[i]->getVertex(1),vd[1],vd[0]));
	}
      }
      for (int i=0;i<gf->quadrangles.size();i++){
	MQuadrangle *q = gf->quadrangles[i];
	MVertex *vs[4];
	for (int j=0;j<4;j++){
	  MVertex *v = q->getVertex(j);
	  std::map<MVertex*,MVertex*>::iterator itv = duplicates.find(v);
	  if (itv == duplicates.end()){
	    vs[j] = v;
	  }
	  else{
	    vs[j] = itv->second;
	  }
	}
	newQuads.push_back(new MQuadrangle(vs[0],vs[1],vs[2],vs[3]));
	delete q;
      }
      for (int i=0;i<gf->triangles.size();i++){
	MTriangle *t = gf->triangles[i];
	MVertex *vs[3];
	for (int j=0;j<3;j++){
	  MVertex *v = t->getVertex(j);
	  std::map<MVertex*,MVertex*>::iterator itv = duplicates.find(v);
	  if (itv == duplicates.end()){
	    vs[j] = v;
	  }
	  else{
	    vs[j] = itv->second;
	  }
	}
	newTris.push_back(new MTriangle(vs[0],vs[1],vs[2]));
	delete t;
      }

      gf->triangles = newTris;
      gf->quadrangles = newQuads;
    }
  }
}
*/

void addBoundaryLayers(GFace *gf)
{
  //if (backgroundMesh::current()){
  //}
  // first compute the cross field if it is not computed yet
  // start from a selection of edges and create points in the boundary layer
  // connect everybody with delaunay 
}

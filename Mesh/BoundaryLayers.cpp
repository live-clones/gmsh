// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "BoundaryLayers.h"
#include "ExtrudeParams.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "GmshMessage.h"
#include "Field.h"
#include "Context.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "OctreePost.h"
#else
class OctreePost {
  int dummy;
};
#endif

static double GetAveEdgeLength(std::vector<MVertex *> &elem_verts)
{
  double ave = 0.0;
  int size = elem_verts.size();
  if(!size) return 0.0;
  for(int i = 0; i < size - 1; i++)
    ave += elem_verts[i]->distance(elem_verts[i + 1]);
  ave += elem_verts[0]->distance(elem_verts[size - 1]);
  ave /= size;
  return ave;
}

template <class T>
static void addExtrudeNormals(std::vector<T *> &elements, int invert,
                              OctreePost *octree, bool gouraud, int index,
                              bool skipScaleCalc)
{
  if(index < 0 || index > 1) {
    Msg::Error("Boundary layer index should be 0 or 1");
    return;
  }

  if(octree && !gouraud) { // get extrusion direction from post-processing view
    std::set<MVertex *> verts;
    for(std::size_t i = 0; i < elements.size(); i++) {
      if(!ExtrudeParams::calcLayerScaleFactor[index]) {
        for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++)
          verts.insert(elements[i]->getVertex(j));
      }
      else {
        std::vector<MVertex *> elem_verts;
        elements[i]->getVertices(elem_verts);

        double aveLength = skipScaleCalc ? 1.0 : GetAveEdgeLength(elem_verts);

        for(std::size_t j = 0; j < elem_verts.size(); j++) {
          verts.insert(elem_verts[j]);
          // if scaleLastLayer selection, but not doing gouraud, then still
          // scale the last layer...  This might create weird behavior for the
          // unprepared...
          if(aveLength != 0.0)
            ExtrudeParams::normals[index]->add_scale(
              elem_verts[j]->x(), elem_verts[j]->y(), elem_verts[j]->z(),
              aveLength);
        }
      }
    }
    for(auto it = verts.begin(); it != verts.end(); it++) {
      MVertex *v = *it;
      double nn[3] = {0., 0., 0.};
#if defined(HAVE_POST)
      octree->searchVector(v->x(), v->y(), v->z(), nn, 0);
#endif
      ExtrudeParams::normals[index]->add(v->x(), v->y(), v->z(), 3, nn);
    }
  }
  else { // get extrusion direction from Gouraud-shaded element normals
    for(std::size_t i = 0; i < elements.size(); i++) {
      MElement *ele = elements[i];
      SVector3 n(0, 0, 0);
      if(ele->getDim() == 2)
        n = ele->getFace(0).normal();
      else if(ele->getDim() == 1) // FIXME: generalize this!
        n = crossprod(ele->getEdge(0).tangent(), SVector3(0., 0., 1.));
      if(invert) n *= -1.;
      double nn[3] = {n[0], n[1], n[2]};
      if(!ExtrudeParams::calcLayerScaleFactor[index]) {
        for(std::size_t k = 0; k < ele->getNumVertices(); k++) {
          MVertex *v = ele->getVertex(k);
          ExtrudeParams::normals[index]->add(v->x(), v->y(), v->z(), 3, nn);
        }
      }
      else {
        std::vector<MVertex *> elem_verts;
        double aveLength = 0.0;
        elements[i]->getVertices(elem_verts);
        if(skipScaleCalc)
          aveLength = 1.0;
        else
          aveLength = GetAveEdgeLength(elem_verts);
        for(std::size_t j = 0; j < elem_verts.size(); j++) {
          ExtrudeParams::normals[index]->add(
            elem_verts[j]->x(), elem_verts[j]->y(), elem_verts[j]->z(), 3, nn);
          if(aveLength != 0.0)
            ExtrudeParams::normals[index]->add_scale(
              elem_verts[j]->x(), elem_verts[j]->y(), elem_verts[j]->z(),
              aveLength);
        }
      }
    }
  }
}

typedef std::set<std::pair<bool, std::pair<int, int> > > infoset;

// skipScaleCalcMap maps an entity tag to a flag telling whether to skip the
// scale calc when extruding only that entity.  The flag is false when an
// extrusion is not scaleLast when in a boundary layer that has at least one
// scaleLast region.  Effectively, this makes the vertices on the boundary
// between a scaled and not scaled region 'average' between being scaled and not
// scaled.
template <class T>
static void addExtrudeNormals(std::set<T *> &entities,
                              std::map<int, infoset> &infos,
                              std::map<int, bool> &skipScaleCalcMap)
{
  bool normalize = true, special3dbox = false, extrudeField = false;
  std::vector<OctreePost *> octrees;

  for(auto it = entities.begin(); it != entities.end(); it++) {
    T *ge = *it;
    infoset info = infos[ge->tag()];
    for(auto it2 = info.begin(); it2 != info.end(); it2++) {
      bool invert = it2->first;
      int index = it2->second.first;
      int view = it2->second.second;
      bool gouraud = true;
      OctreePost *octree = nullptr;
#if defined(HAVE_POST)
      if(view != -1) {
        if(view >= 0 && view < (int)PView::list.size()) {
          octree = new OctreePost(PView::list[view]);
          if(PView::list[view]->getData()->getNumVectors()) gouraud = false;
          octrees.push_back(octree);
        }
        else if(view == -3) {
          // Force extrusion normals along x,y,z axes for single normals or at
          // 45 degrees for multiple normals (allows to build nice 3D "boxes")
          special3dbox = true;
        }
        else if(view == -5) {
          // Force extrusion normals with a field
          extrudeField = true;
        }
        else
          Msg::Error("Unknown View[%d]: using normals instead", view);
      }
#endif
      bool skipScaleCalc = true;
      auto itskip = skipScaleCalcMap.find(ge->tag());
      if(itskip != skipScaleCalcMap.end())
        skipScaleCalc = skipScaleCalcMap[ge->tag()];
      if(ge->dim() == 1)
        addExtrudeNormals(((GEdge *)ge)->lines, invert, octree, gouraud, index,
                          skipScaleCalc);
      else if(ge->dim() == 2) {
        addExtrudeNormals(((GFace *)ge)->triangles, invert, octree, gouraud,
                          index, skipScaleCalc);
        addExtrudeNormals(((GFace *)ge)->quadrangles, invert, octree, gouraud,
                          index, skipScaleCalc);
      }
      if(!gouraud) normalize = false;
    }
  }

  // enforce coherent normals at some points if necessary
  for(std::size_t i = 0; i < ExtrudeParams::normalsCoherence.size(); i++) {
    SPoint3 &p(ExtrudeParams::normalsCoherence[i]);
    double n0[3], n1[3];
    ExtrudeParams::normals[0]->get(p.x(), p.y(), p.z(), 3, n0);
    ExtrudeParams::normals[1]->get(p.x(), p.y(), p.z(), 3, n1);
    ExtrudeParams::normals[0]->add(p.x(), p.y(), p.z(), 3, n1);
    ExtrudeParams::normals[1]->add(p.x(), p.y(), p.z(), 3, n0);
  }

  // normalize extrusion directions if not using explicit vector post-processing
  // views
  if(normalize) {
    for(int i = 0; i < 2; i++) {
      ExtrudeParams::normals[i]->normalize();
      if(special3dbox) { // force normals for 3d "box" along x,y,z
        for(auto it = ExtrudeParams::normals[i]->begin();
            it != ExtrudeParams::normals[i]->end(); it++) {
          for(int j = 0; j < 3; j++) {
            if(it->vals[j] < -0.1)
              it->vals[j] = -1.;
            else if(it->vals[j] > 0.1)
              it->vals[j] = 1.;
            else
              it->vals[j] = 0.;
          }
        }
      }
      if(extrudeField) { // force normals according to field
        for(auto it = ExtrudeParams::normals[i]->begin();
            it != ExtrudeParams::normals[i]->end(); it++) {
          GEntity *ge = (GEntity *)(*entities.begin());
          FieldManager *fields = ge->model()->getFields();
          if(fields->getBackgroundField() > 0) {
            Field *f = fields->get(fields->getBackgroundField());
            double radius = (*f)(it->x, it->y, it->z);
            for(int k = 0; k < 3; k++) it->vals[k] *= radius;
          }
        }
      }
#if defined(HAVE_POST)
      if(octrees.size()) { // scale normals by scalar views
        for(auto it = ExtrudeParams::normals[i]->begin();
            it != ExtrudeParams::normals[i]->end(); it++) {
          for(std::size_t j = 0; j < octrees.size(); j++) {
            double d;
            if(octrees[j]->searchScalarWithTol(it->x, it->y, it->z, &d, 0)) {
              for(int k = 0; k < 3; k++) it->vals[k] *= d;
              break;
            }
          }
        }
      }
#endif
    }
  }

  for(std::size_t i = 0; i < octrees.size(); i++) delete octrees[i];
}

static void checkDepends(GModel *m, GFace *f, std::set<GFace *> &dep)
{
  ExtrudeParams *ep = f->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY) {
    GFace *from = m->getFaceByTag(std::abs(ep->geo.Source));
    if(!from) {
      Msg::Error("Unknown origin face %d", ep->geo.Source);
      return;
    }
    dep.insert(from);
    checkDepends(m, from, dep);
  }
}

static unsigned int
FixErasedExtrScaleFlags(GModel *m, std::map<int, bool> &faceSkipScaleCalc,
                        std::map<int, bool> &edgeSkipScaleCalc)
{
  unsigned int num_changed = 0;
  // fix all extruded faces bordering ScaleLast regions
  for(auto itreg = m->firstRegion(); itreg != m->lastRegion(); itreg++) {
    ExtrudeParams *r_ep = (*itreg)->meshAttributes.extrude;
    if(!r_ep || !r_ep->mesh.ExtrudeMesh || r_ep->geo.Mode != EXTRUDED_ENTITY ||
       !r_ep->mesh.ScaleLast)
      continue;
    std::vector<GFace *> reg_faces = (*itreg)->faces();
    for(auto itface = reg_faces.begin(); itface != reg_faces.end(); itface++) {
      if(m->getFaceByTag(std::abs(r_ep->geo.Source)) != (*itface)) {
        ExtrudeParams *f_ep = (*itface)->meshAttributes.extrude;
        if(f_ep && f_ep->mesh.ExtrudeMesh && !f_ep->mesh.ScaleLast) {
          num_changed++;
          f_ep->mesh.ScaleLast = true;
          faceSkipScaleCalc[(*itface)->tag()] = false;
        }
      }
    }
  }
  // fix all extruded curves bordering ScaleLast faces...the previous loop
  // should have fixed any replaced extruded faces.  if a face is not bordering
  // a region, then it would not have been replaced except by a pointless
  // degenerate extrusion right on it...which makes no sense anyway.  So... just
  // loop through faces.
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    ExtrudeParams *f_ep = (*it)->meshAttributes.extrude;
    if(!f_ep || !f_ep->mesh.ExtrudeMesh || !f_ep->mesh.ScaleLast) continue;
    std::vector<GEdge *> f_edges = (*it)->edges();
    for(auto itedge = f_edges.begin(); itedge != f_edges.end(); itedge++) {
      if(m->getEdgeByTag(std::abs(f_ep->geo.Source)) != (*itedge)) {
        ExtrudeParams *e_ep = (*itedge)->meshAttributes.extrude;
        if(e_ep && e_ep->mesh.ExtrudeMesh && !e_ep->mesh.ScaleLast) {
          num_changed++;
          e_ep->mesh.ScaleLast = true;
          edgeSkipScaleCalc[(*itedge)->tag()] = false;
        }
      }
    }
  }

  return num_changed;
}

int Mesh2DWithBoundaryLayers(GModel *m)
{
  std::set<GFace *> sourceFaces, otherFaces;
  std::set<GEdge *> sourceEdges, otherEdges;
  std::map<int, infoset> sourceFaceInfo, sourceEdgeInfo;
  std::map<int, bool> faceSkipScaleCalc, edgeSkipScaleCalc; // Trevor Strickler
  ExtrudeParams::calcLayerScaleFactor[0] = 0; // Trevor Strickler
  ExtrudeParams::calcLayerScaleFactor[1] = 0; // Trevor Strickler

  // 2D boundary layers
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
    GEdge *ge = *it;
    if(ge->getNativeType() == GEntity::GmshModel &&
       ge->geomType() == GEntity::BoundaryLayerCurve) {
      ExtrudeParams *ep = ge->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY) {
        GEdge *from = m->getEdgeByTag(std::abs(ep->geo.Source));
        if(!from) {
          Msg::Error("Unknown source curve %d for boundary layer",
                     ep->geo.Source);
          return 0;
        }
        std::pair<bool, std::pair<int, int> > tags(
          ep->geo.Source < 0,
          std::pair<int, int>(ep->mesh.BoundaryLayerIndex, ep->mesh.ViewIndex));
        sourceEdgeInfo[from->tag()].insert(tags);
        sourceEdges.insert(from);
        // Added to scale last layer size locally: Do not worry if one section
        // of the boundary layer index = 0 or 1 is not supposed to be
        // scaled...that section's normals will have scaleFactor = 1.0 (exactly
        // 1.0 to all sig figs) ...however, if that non-scaled section borders a
        // scaled section, the boundary normals will extrude scaled.
        if(!ep->mesh.ScaleLast) { edgeSkipScaleCalc[from->tag()] = true; }
        else {
          edgeSkipScaleCalc[from->tag()] = false;
          ExtrudeParams::calcLayerScaleFactor[ep->mesh.BoundaryLayerIndex] =
            true;
        }
      }
    }
  }

  // 3D boundary layers
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *gf = *it;
    if(gf->getNativeType() == GEntity::GmshModel &&
       gf->geomType() == GEntity::BoundaryLayerSurface) {
      ExtrudeParams *ep = gf->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == COPIED_ENTITY) {
        GFace *from = m->getFaceByTag(std::abs(ep->geo.Source));
        if(!from) {
          Msg::Error("Unknown source face %d for boundary layer",
                     ep->geo.Source);
          return 0;
        }
        std::pair<bool, std::pair<int, int> > tags(
          ep->geo.Source < 0,
          std::pair<int, int>(ep->mesh.BoundaryLayerIndex, ep->mesh.ViewIndex));
        sourceFaceInfo[from->tag()].insert(tags);
        sourceFaces.insert(from);
        // Added to scale last layer size locally: Do not worry if one section
        // of the boundary layer index = 0 or 1 is not supposed to be
        // scaled...that section's normals will have scaleFactor = 1.0 (exactly
        // 1.0 to all sig figs) ...however, if that non-scaled section borders a
        // scaled section, the boundary normals will extrude scaled
        if(!ep->mesh.ScaleLast) { faceSkipScaleCalc[from->tag()] = true; }
        else {
          faceSkipScaleCalc[from->tag()] = false;
          ExtrudeParams::calcLayerScaleFactor[ep->mesh.BoundaryLayerIndex] =
            true;
        }
        std::vector<GEdge *> const &e = from->edges();
        sourceEdges.insert(e.begin(), e.end());
        for(auto ite = e.begin(); ite != e.end(); ite++) {
          if(edgeSkipScaleCalc.find((*ite)->tag()) == edgeSkipScaleCalc.end())
            edgeSkipScaleCalc[(*ite)->tag()] = true; // a default
          if(ep->mesh.ScaleLast) edgeSkipScaleCalc[(*ite)->tag()] = false;
        }
      }
    }
  }

  if(sourceEdges.empty() && sourceFaces.empty()) return 0;

  // Just in case ReplaceDuplicates() erases the ExtrudeParams::mesh.scaleLast
  // flag, should check all bounding regions of this curve to see if scaleLast
  // is set.  if so, reset it in the extrudeParams (maybe this could be done in
  // the TreeUtils....  but I do not want to change the code too much and create
  // a bug.  The developers should decide that.
  if(ExtrudeParams::calcLayerScaleFactor[0] ||
     ExtrudeParams::calcLayerScaleFactor[1]) {
    unsigned int num_changed =
      FixErasedExtrScaleFlags(m, faceSkipScaleCalc, edgeSkipScaleCalc);
    if(num_changed)
      Msg::Warning(
        "%d entities were changed from ScaleLast = false to ScaleLast = true",
        num_changed);
  }
  // compute mesh dependencies in source faces (so we can e.g. create a boundary
  // layer on an extruded mesh)
  std::set<GFace *> sourceFacesDependencies;
  for(auto it = sourceFaces.begin(); it != sourceFaces.end(); it++)
    checkDepends(m, *it, sourceFacesDependencies);
  Msg::Info("%d dependencies in mesh of source faces",
            sourceFacesDependencies.size());
  for(auto it = sourceFacesDependencies.begin();
      it != sourceFacesDependencies.end(); it++) {
    std::vector<GEdge *> const &e = (*it)->edges();
    sourceEdges.insert(e.begin(), e.end());
  }

  // compute set of non-source edges and faces
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
    if(sourceEdges.find(*it) == sourceEdges.end()) otherEdges.insert(*it);
  for(auto it = m->firstFace(); it != m->lastFace(); it++)
    if(sourceFaces.find(*it) == sourceFaces.end() &&
       sourceFacesDependencies.find(*it) == sourceFacesDependencies.end())
      otherFaces.insert(*it);

  // mesh source surfaces (and dependencies)
  int nIter = 0;
  while(1) {
    int nPending = 0;
    for(auto it = sourceFacesDependencies.begin();
        it != sourceFacesDependencies.end(); it++) {
      if((*it)->meshStatistics.status == GFace::PENDING) {
        (*it)->mesh(true);
        nPending++;
      }
    }
    if(!nPending) break;
    if(nIter++ > CTX::instance()->mesh.maxRetries) break;
  }
  for(auto it = sourceFaces.begin(); it != sourceFaces.end(); it++)
    (*it)->mesh(true);

  // make sure the source surfaces for the boundary layers are oriented
  // correctly (normally we do this only after the 3D mesh is done; but here
  // it's critical since we use the normals for the extrusion)
  std::for_each(sourceFaces.begin(), sourceFaces.end(), orientMeshGFace());

  // compute a normal field for all the source edges or faces
  for(int i = 0; i < 2; i++) {
    if(ExtrudeParams::normals[i]) delete ExtrudeParams::normals[i];
    ExtrudeParams::normals[i] = new smooth_data();
  }
  if(sourceFaces.empty())
    addExtrudeNormals(sourceEdges, sourceEdgeInfo, edgeSkipScaleCalc);
  else
    addExtrudeNormals(sourceFaces, sourceFaceInfo, faceSkipScaleCalc);

  // set the position of boundary layer points using the smooth normal field
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
    GEdge *ge = *it;
    if(ge->geomType() == GEntity::BoundaryLayerCurve) {
      ExtrudeParams *ep = ge->meshAttributes.extrude;
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) {
        GVertex *vsrc, *vdest;
        if(ge->getBeginVertex() &&
           ge->getBeginVertex()->geomType() == GEntity::BoundaryLayerPoint) {
          vsrc = ge->getEndVertex();
          vdest = ge->getBeginVertex();
        }
        else {
          vsrc = ge->getBeginVertex();
          vdest = ge->getEndVertex();
        }
        if(vsrc && vdest) {
          GPoint p = vsrc->point();
          ep->Extrude(ep->mesh.NbLayer - 1,
                      ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], p.x(), p.y(),
                      p.z());
          vdest->setPosition(p);
        }
      }
    }
  }

  // remesh non-source edges (since they might have been modified by the change
  // in boundary layer points)
  std::for_each(otherFaces.begin(), otherFaces.end(), deMeshGFace());
  for(auto it = otherEdges.begin(); it != otherEdges.end(); it++)
    (*it)->mesh(true);

  // mesh the curves bounding the boundary layers by extrusion using the smooth
  // normal field
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++) {
    GEdge *ge = *it;
    if(ge->geomType() == GEntity::BoundaryLayerCurve) {
      Msg::Info("Meshing curve %d", ge->tag());
      deMeshGEdge dem;
      dem(ge);
      MeshExtrudedCurve(ge);
    }
  }

  // recompute mean plane for plane surfaces just in case
  for(auto it = otherFaces.begin(); it != otherFaces.end(); it++) {
    GFace *gf = *it;
    if(gf->geomType() == GEntity::Plane) gf->computeMeanPlane();
  }

  // mesh non-source surfaces
  for(auto it = otherFaces.begin(); it != otherFaces.end(); it++)
    (*it)->mesh(true);

  // mesh the surfaces bounding the boundary layers by extrusion using the
  // smooth normal field
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *gf = *it;
    if(gf->geomType() == GEntity::BoundaryLayerSurface) {
      Msg::Info("Meshing surface %d (%s)", gf->tag(),
                gf->getTypeString().c_str());
      deMeshGFace dem;
      dem(gf);
      MeshExtrudedSurface(gf);
    }
  }

  return 1;
}

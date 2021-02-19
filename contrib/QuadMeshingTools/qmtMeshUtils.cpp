// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtMeshUtils.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <math.h>
#include <algorithm>
#include <queue>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "robin_hood.h"
#include "meshOctreeLibOL.h"
#include "BackgroundMesh.h"

// /* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"
#include "gmsh.h"

using namespace CppUtils;
using std::unordered_map;
using std::unordered_set;

std::vector<GFace*> model_faces(const GModel* gm) {
  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }
  return faces;
}

std::vector<GEdge*> face_edges(const GFace* gf) {
  std::vector<GEdge*> edges;
  for (GEdge* ge: gf->edges()) {
    edges.push_back(ge);
  }
  GFace* gfc = const_cast<GFace*>(gf);
  for (GEdge* ge: gfc->embeddedEdges()) {
    edges.push_back(ge);
  }
  sort_unique(edges);
  return edges;
}

std::vector<GEdge*> model_edges(const GModel* gm) {
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) append(edges,face_edges(gf));
  sort_unique(edges);
  return edges;
}

bool haveNiceParametrization(GFace* gf) {
  if (!gf->haveParametrization()) return false;
  if (gf->geomType() == GFace::GeomType::Sphere) return false;

  // if (gf->periodic(0) || gf->periodic(1)) return false;

  return true;
}

bool buildVertexToVertexMap(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MVertex*,std::vector<MVertex*> >& v2v) {
  v2v.clear();
  v2v.rehash(3*triangles.size());

  size_t N = 3;
  for (MTriangle* f: triangles) {
    for (size_t le = 0; le < N; ++le) {
      MVertex* v1 = f->getVertex(le);
      MVertex* v2 = f->getVertex((le+1)%N);
      v2v[v1].push_back(v2);
      v2v[v2].push_back(v1);
    }
  }
  for (auto& kv: v2v) {
    sort_unique(kv.second);
  }

  return true;
}

bool buildBoundary (const std::vector<MElement*>& elements, std::vector<MVertex*>& bnd){
  std::vector<MEdge> eds,veds;

  for (MElement* e: elements) {
    for (size_t j=0;j<(size_t)e->getNumEdges();j++){
      eds.push_back(e->getEdge(j));
    }
  }

  MEdgeLessThan melt;
  std::sort(eds.begin(),eds.end(), melt);
  for(size_t i=0;i<eds.size();i++){
    if (i != eds.size()-1 && eds[i] == eds[i+1])i++;
    else veds.push_back(eds[i]);
  }

  std::vector<std::vector<MVertex *> > vsorted;
  bool oks = SortEdgeConsecutive(veds, vsorted);
  if (!oks) {
    return false;
  }
  if (vsorted.empty()){
    return false;
  }
  else if (vsorted.size() > 1){
    Msg::Debug("buildBoundary(): %li loops instead of one\n",vsorted.size());
    return false;
  }

  /* Reverse vertices if necessary, to keep coherent with elements orientation */
  {
    MEdge e = veds[0];
    MVertex* v1 = e.getVertex(0);
    MVertex* v2 = e.getVertex(1);
    auto it = std::find(vsorted[0].begin(),vsorted[0].end(),v1);
    if (it == vsorted[0].end()) {
      Msg::Error("buildBoundary(): vertex not found in sorted vertices, weird");
      return false;
    }
    size_t i = it - vsorted[0].begin();
    size_t i_next = (i+1)%vsorted[0].size();
    size_t i_prev = (i-1+vsorted[0].size())%vsorted[0].size();
    if (vsorted[0][i_next] == v2) { 
      // good ordering
    } else if (vsorted[0][i_prev] == v2) { // apply reverse
      std::reverse(vsorted[0].begin(),vsorted[0].end());
    } else {
      Msg::Error("buildBoundary(): second vertex not found in adjacent sorted vertices, weird");
      return false;
    }
  }
  bnd = vsorted[0];
  return true;
}

bool buildBoundaries(const std::vector<MElement*>& elements, std::vector<std::vector<MVertex*> >& loops) {
  loops.clear();
  std::vector<MEdge> eds,veds;

  for (MElement* e: elements) {
    for (size_t j=0;j<(size_t)e->getNumEdges();j++){
      eds.push_back(e->getEdge(j));
    }
  }

  MEdgeLessThan melt;
  std::sort(eds.begin(),eds.end(), melt);
  for(size_t i=0;i<eds.size();i++){
    if (i != eds.size()-1 && eds[i] == eds[i+1])i++;
    else veds.push_back(eds[i]);
  }

  if (veds.size() == 0) return true; /* No boundary, e.g. sphere */

  std::vector<std::vector<MVertex *> > vsorted;
  bool oks = SortEdgeConsecutive(veds, vsorted);
  if (!oks || vsorted.empty()) {
    return false;
  }

  /* Reverse vertices if necessary, to keep coherent with elements orientation */
  for (size_t l = 0; l < vsorted.size(); ++l) {
    std::vector<MVertex*>& loop = vsorted[l];
    /* Find a MEdge on the loop */
    MVertex* a = nullptr;
    MVertex* b = nullptr;
    for (MEdge e: veds) {
      MVertex* v1 = e.getVertex(0);
      MVertex* v2 = e.getVertex(1);
      auto it = std::find(loop.begin(),loop.end(),v1);
      if (it != loop.end()) {
        /* v1 from the MEdge found on the loop */
        a = v1;
        b = v2;
        break;
      }
    }
    if (a == nullptr || b == nullptr) {
      Msg::Error("buildBoundaries(): vertex not found in sorted vertices, weird");
      return false;
    }

    auto it = std::find(loop.begin(),loop.end(),a);
    size_t i = it - loop.begin();
    size_t i_next = (i+1)%loop.size();
    size_t i_prev = (i-1+loop.size())%loop.size();
    if (loop[i_next] == b) { 
      // good ordering
    } else if (loop[i_prev] == b) { // apply reverse
      std::reverse(loop.begin(),loop.end());
    } else {
      Msg::Error("buildBoundaries(): second vertex not found in adjacent sorted vertices, weird");
      return false;
    }
  }

  loops = vsorted;
  return true;
}

bool getConnectedComponents(const std::vector<MElement*>& elements,
    std::vector<std::vector<MElement*> >& components) {
  components.clear();

  unordered_map<MVertex *, std::vector<MElement *> > v2q;
  for (MElement* e: elements) {
    for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      v2q[e->getVertex(lv)].push_back(e);
    }
  }

  unordered_map<MElement*,int> color;
  int no = 0;
  for (MElement* e0: elements) {
    auto it = color.find(e0);
    if (it != color.end()) continue;
    no += 1;

    std::vector<MElement*> current;
    std::queue<MElement*> Q;
    color[e0] = no;
    Q.push(e0);
    current.push_back(e0);

    while (Q.size() > 0) {
      MElement* e = Q.front();
      Q.pop();
      for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
        MVertex* v = e->getVertex(lv);
        auto it = v2q.find(v);
        if (it == v2q.end()) continue;
        for (MElement* e2: it->second) if (e2 != e) {
          auto it2 = color.find(e2);
          if (it2 == color.end()) {
            color[e2] = no;
            Q.push(e2);
            current.push_back(e2);
          }
        }
      }
    }

    sort_unique(current);
    components.push_back(current);
  }

  return true;
}

bool patchFromElements(GFace* gf, const std::vector<MElement*>& elements, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary) {
  patch.gf = gf;
  bool okb = buildBoundaries(elements, patch.bdrVertices);
  if (!okb) {
    if (forceEvenIfBadBoundary) {
      /* Boundaries are not manifold, put all vertices in a unordered loop */
      patch.bdrVertices.resize(1);
      patch.bdrVertices[0].clear();
      for (MElement* e: elements)  {
        for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
          MVertex* v = e->getVertex(lv);
          if (v->onWhat() != gf) {
            patch.bdrVertices[0].push_back(v);
          }
        }
      }
      sort_unique(patch.bdrVertices[0]);
    } else {
      return false;
    }
  }

  /* Ensure no repetition in the boundary loops */
  for (std::vector<MVertex*>& loop: patch.bdrVertices) {
    if (loop.back() == loop.front()) loop.pop_back();
  }

  patch.intVertices.reserve(4*elements.size());
  for (MElement* e: elements)  {
    if (e == nullptr) {
      Msg::Error("patchFromElements: given MElement* is nullptr");
      return false;
    }
    for (size_t lv = 0; lv < e->getNumVertices(); ++lv) {
      patch.intVertices.push_back(e->getVertex(lv));
    }
  }
  std::vector<MVertex*> bdr;
  for (size_t i = 0; i < patch.bdrVertices.size(); ++i) append(bdr, patch.bdrVertices[i]);
  patch.intVertices = difference(patch.intVertices, bdr);
  patch.elements = elements;

  return true;
}

bool patchFromQuads(GFace* gf, const std::vector<MQuadrangle*>& quads, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary) {
  std::vector<MElement*> elts = dynamic_cast_vector<MQuadrangle*,MElement*>(quads);
  return patchFromElements(gf, elts, patch, forceEvenIfBadBoundary);
}

struct as2Hash {
  size_t operator()(std::array<size_t,2> p) const noexcept {
    return size_t(p[0]) << 32 | p[1];
  }
};

bool patchIsTopologicallyValid(const GFaceMeshPatch& patch) {
  std::unordered_map<std::array<size_t,2>, size_t, as2Hash> edgeVal;
  for (MElement* f: patch.elements) {
    size_t n = f->getNumVertices();
    for (size_t lv = 0; lv < n; ++lv) {
      MVertex* v = f->getVertex(lv);
      MVertex* v2 = f->getVertex((lv+1)%n);
      if (v->getNum() < v2->getNum()) {
        std::array<size_t,2> vpair = {v->getNum(),v2->getNum()};
        edgeVal[vpair] += 1;
      } else {
        std::array<size_t,2> vpair =  {v2->getNum(),v->getNum()};
        edgeVal[vpair] += 1;
      }
    }
  }

  for (auto& kv: edgeVal) {
    if (kv.second > 2) {
      Msg::Debug("patchIsTopologicallyValid | edge (%i,%i) non manifold, valence =  %i", kv.first[0],kv.first[1], kv.second);
      return false;
    }
  }

  return true;
}

bool GFaceMeshDiff::execute(bool verifyPatchTopology) {
  if (gf != before.gf || gf != after.gf) return false;
  if (after.elements.size() == 0) return false;
  if (done) return false;
  if (verifyPatchTopology) {
    bool ok = patchIsTopologicallyValid(after);
    if (!ok) return false;
  }
  if (before.bdrVertices.size() != after.bdrVertices.size()) {
    Msg::Error("GFaceMeshDiff::execute(): different boundary size before/after, should not happen");
    return false;
  }

  /* Replace the interior vertices */
  while (before.intVertices.size() > 0) {
    MVertex* ov = before.intVertices.back();
    before.intVertices.pop_back();
    auto it = std::find(gf->mesh_vertices.begin(),gf->mesh_vertices.end(), ov);
    if (it == gf->mesh_vertices.end()) {
      Msg::Error("GFaceMeshDiff::execute(): vertex %li (entity dim=%i) not found in gf->mesh_vertices (size %li), should NEVER happen, memory corrupted",
          ov->getNum(), ov->onWhat()->dim(), gf->mesh_vertices.size());
      gmsh::initialize();
      GeoLog::add(ov->point(),0.,"bad_property_v" + std::to_string(ov->getNum()));
      GeoLog::flush();
      gmsh::fltk::run();
      abort();
    }
    if (after.intVertices.size() > 0) {
      /* Replace old vertex by new one, in place */
      MVertex* nv = after.intVertices.back();
      after.intVertices.pop_back();
      *it = nv;
    } else {
      it = gf->mesh_vertices.erase(it);
    }
    delete ov;
  }
  /* Append remaining vertices */
  while (after.intVertices.size() > 0) {
    MVertex* nv = after.intVertices.back();
    after.intVertices.pop_back();
    gf->addMeshVertex(nv);
  }

  /* Replace the elements */
  while (before.elements.size() > 0) {
    MElement* oe = before.elements.back();
    before.elements.pop_back();
    MQuadrangle* oq = dynamic_cast<MQuadrangle*>(oe);
    MTriangle* ot = dynamic_cast<MTriangle*>(oe);
    if (oq != nullptr) {
      auto it = std::find(gf->quadrangles.begin(),gf->quadrangles.end(), oq);
      if (it == gf->quadrangles.end()) {
        Msg::Error("GFaceMeshDiff::execute(): quad not found in gf->quadrangles, should NEVER happen, memory corrupted");
        abort();
      }
      if (after.elements.size() > 0) {
        /* Replace old quad by new one, in place */
        MQuadrangle* nq = dynamic_cast<MQuadrangle*>(after.elements.back());
        if (nq != nullptr) {
          after.elements.pop_back();
          *it = nq;
        } else {
          it = gf->quadrangles.erase(it);
        }
      } else {
        it = gf->quadrangles.erase(it);
      }
      delete oq;
    } else if (ot != nullptr) {
      auto it = std::find(gf->triangles.begin(),gf->triangles.end(), ot);
      if (it == gf->triangles.end()) {
        Msg::Error("GFaceMeshDiff::execute(): quad not found in gf->triangles, should NEVER happen, memory corrupted");
        abort();
      }
      if (after.elements.size() > 0) {
        /* Replace old triangle by new one, in place */
        MTriangle* nt = dynamic_cast<MTriangle*>(after.elements.back());
        if (nt != nullptr) {
          after.elements.pop_back();
          *it = nt;
        } else {
          it = gf->triangles.erase(it);
        }
      } else {
        it = gf->triangles.erase(it);
      }
      delete ot;
    } else {
      Msg::Error("GFaceMeshDiff::execute(): element is not MQuadrangle and not MTriangle, should NEVER happen, memory corrupted");
      abort();
    }
  }
  /* Append remaining elements */
  while (after.elements.size() > 0) {
    MElement* ne = after.elements.back();
    after.elements.pop_back();
    gf->addElement(ne->getType(), ne);
  }

  done = true;
  return true;
}

GFaceMeshDiff::~GFaceMeshDiff() {
  if (done) { 
    /* execute() should have already cleared these vectors, just doing by security */
    for (MVertex* v: before.intVertices) if (v != nullptr) {
      delete v;
      v = nullptr;
    }
    for (MElement* e: before.elements) if (e != nullptr) {
      delete e;
      e = nullptr;
    }
  } else {
    for (MVertex* v: after.intVertices) if (v != nullptr) {
      delete v;
      v = nullptr;
    }
    for (MElement* e: after.elements) if (e != nullptr) {
      delete e;
      e = nullptr;
    }
  }
}

PatchGeometryBackup::PatchGeometryBackup(GFaceMeshPatch& p, bool includeBoundary) {
  for (MVertex* v: p.intVertices) {
    SPoint2 uv(DBL_MAX,DBL_MAX);
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf != nullptr) {
      v->getParameter(0,uv.data()[0]);
      v->getParameter(1,uv.data()[1]);
    }
    old[v] = {uv,v->point()};
  }
  if (includeBoundary) {
    for (std::vector<MVertex*>& bdr : p.bdrVertices) {
      for (MVertex* v: bdr) {
        SPoint2 uv(DBL_MAX,DBL_MAX);
        GFace* gf = dynamic_cast<GFace*>(v->onWhat());
        if (gf != nullptr) {
          v->getParameter(0,uv.data()[0]);
          v->getParameter(1,uv.data()[1]);
        }
        old[v] = {uv,v->point()};
      }
    }
  }
}

bool PatchGeometryBackup::restore() {
  for (auto& kv: old) {
    MVertex* v = kv.first;
    SPoint2 uv = kv.second.first;
    SPoint3 pt = kv.second.second;
    if (uv.x() != DBL_MAX) {
      v->setParameter(0,uv.x());
      v->setParameter(1,uv.y());
    }
    v->setXYZ(pt.x(),pt.y(),pt.z());
  }
  return true;
}

MVertex* centerOfElements(const std::vector<MElement*>& elements) {
  if (elements.size() == 0) return NULL;

  std::map<std::array<MVertex*,2>,size_t> vPairCount;
  unordered_map<MVertex*, unordered_set<MVertex*> > v2v;
  for (MElement* f: elements) {
    size_t N = f->getNumEdges();
    for (size_t le = 0; le < N; ++le) {
      MVertex* v1 = f->getVertex(le);
      MVertex* v2 = f->getVertex((le+1)%N);
      v2v[v1].insert(v2);
      v2v[v2].insert(v1);
      std::array<MVertex*,2> vPair = {v1,v2};
      if (v2 < v1) {
        vPair = {v2,v1};
      }
      vPairCount[vPair] += 1;
    }
  }

  /* Init from boundary */
  unordered_map<MVertex*,double> dist;
  std::priority_queue<std::pair<double,MVertex*>,  std::vector<std::pair<double,MVertex*> >,  std::greater<std::pair<double,MVertex*> > > Q; 
  for (const auto& kv: vPairCount) if (kv.second == 1) {
    dist[kv.first[0]] = 0.;
    dist[kv.first[1]] = 0.;
    Q.push({0.,kv.first[0]});
    Q.push({0.,kv.first[1]});
  }

  /* Dijkstra propagation */
  while (Q.size() > 0) {
    MVertex* v = Q.top().second;
    double cdist = Q.top().first;
    Q.pop();
    for (MVertex* v2: v2v[v]) {
      double w_ij = v->distance(v2);
      auto it = dist.find(v2);
      if (it == dist.end() || cdist + w_ij < it->second) {
        double new_dist = cdist + w_ij;
        dist[v2] = cdist + w_ij;
        Q.push({new_dist,v2});
      }
    }
  }

  double dmax = 0.;
  MVertex* center = NULL;
  for (const auto& kv: dist) {
    if (kv.second > dmax) {
      dmax = kv.second;
      center = kv.first;
    }
  }
  return center;
}

bool setVertexGFaceUV(GFace* gf, MVertex* v, double uv[2]) {
  bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
  if (onGf) {
    v->getParameter(0,uv[0]);
    v->getParameter(1,uv[1]);
    return true;
  } else {
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge != NULL) {
      double t;
      v->getParameter(0,t);
      SPoint2 uvp = ge->reparamOnFace(gf, t, -1);
      uv[0] = uvp.x();
      uv[1] = uvp.y();
      return true;
    } else {
      GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
      if (gv != NULL) {
        SPoint2 uvp = gv->reparamOnFace(gf,0);
        uv[0] = uvp.x();
        uv[1] = uvp.y();
        return true;
      }
    }
  }
  uv[0] = 0.;
  uv[1] = 0.;
  return false;
}

bool orientElementsAccordingToBoundarySegment(MVertex* a, MVertex* b, std::vector<MElement*>& elements) {
  int reorient = 0;
  for (MElement* e: elements) {
    size_t n = e->getNumVertices();
    for (size_t lv = 0; lv < n; ++lv) {
      MVertex* v0 = e->getVertex(lv);
      MVertex* v1 = e->getVertex((lv+1)%n);
      if (v0 == a && v1 == b) {
        reorient = -1;
        break;
      } else if (v0 == b && v1 == a) {
        reorient = 1;
        break;
      }
    }
    if (reorient != 0) break;
  }
  if (reorient == 1) {
    for (MElement* e: elements) {
      e->reverse();
    }
  } else if (reorient == 0) {
    Msg::Error("orientElementsAccordingToBoundarySegment: bdr quad edge not found, weird");
    return false;
  }
  return true;
}

void getAllParametersWithPeriodJump(MVertex *v, GFace *gf, std::vector<SPoint2> &params)
{
  params.clear();

  if(gf->geomType() == GEntity::DiscreteSurface) {
    params.push_back(gf->parFromPoint(SPoint3(v->x(), v->y(), v->z())));
    return;
  }

  if(v->onWhat()->dim() == 0) {
    GVertex *gv = (GVertex *)v->onWhat();
    std::vector<GEdge *> const &ed = gv->edges();
    bool seam = false;
    for(auto it = ed.begin(); it != ed.end(); it++) {
      if((*it)->isSeam(gf)) {
        Range<double> range = (*it)->parBounds(0);
        if(gv == (*it)->getBeginVertex()) {
          params.push_back((*it)->reparamOnFace(gf, range.low(), -1));
          params.push_back((*it)->reparamOnFace(gf, range.low(), 1));
        }
        if(gv == (*it)->getEndVertex()) {
          params.push_back((*it)->reparamOnFace(gf, range.high(), -1));
          params.push_back((*it)->reparamOnFace(gf, range.high(), 1));
        }
        if(gv != (*it)->getBeginVertex() && gv != (*it)->getEndVertex()) {
          Msg::Warning("Strange!");
        }
        seam = true;
      }
    }
    if(!seam) params.push_back(gv->reparamOnFace(gf, 1));
  }
  else if(v->onWhat()->dim() == 1) {
    GEdge *ge = (GEdge *)v->onWhat();
    if(!ge->haveParametrization()) return;
    double UU;
    v->getParameter(0, UU);
    if(UU == 0.0) UU = ge->parFromPoint(v->point());
    params.push_back(ge->reparamOnFace(gf, UU, 1));
    if(ge->isSeam(gf)) params.push_back(ge->reparamOnFace(gf, UU, -1));
  }
  else {
    double UU, VV;
    if(v->onWhat() == gf && v->getParameter(0, UU) && v->getParameter(1, VV)) {
      params.push_back(SPoint2(UU, VV));
      if (gf->periodic(0) && gf->periodic(1)) {
        double Tu = gf->period(0);
        double Tv = gf->period(1);
        params.push_back(SPoint2(UU+Tu, VV+Tv));
        params.push_back(SPoint2(UU+Tu, VV-Tv));
        params.push_back(SPoint2(UU-Tu, VV+Tv));
        params.push_back(SPoint2(UU-Tu, VV-Tv));
      } else if (gf->periodic(0)) {
        double Tu = gf->period(0);
        params.push_back(SPoint2(UU+Tu, VV));
        params.push_back(SPoint2(UU-Tu, VV));
      } else if (gf->periodic(1)) {
        double Tv = gf->period(1);
        params.push_back(SPoint2(UU, VV+Tv));
        params.push_back(SPoint2(UU, VV-Tv));
      }
    }
  }
}

bool reparamMeshVertexOnFaceWithRef(GFace* gf, MVertex* v, const SPoint2& ref, SPoint2& param) {
  std::vector<SPoint2> p1s;
  getAllParametersWithPeriodJump(v, gf, p1s);
  if (p1s.size() == 0) {
    return false;
  } else if (p1s.size() == 0) {
    param = p1s[0];
    return true;
  }

  double dmin2 = DBL_MAX;
  for (size_t i = 0; i < p1s.size(); ++i) {
    const SPoint2& uv = p1s[i];
    double d2 = std::pow(uv.x()-ref.x(),2)+ std::pow(uv.y()-ref.y(),2);
    if (d2 < dmin2) {
      dmin2 = d2;
      param = uv;
    }
  }
  return true;
}

std::vector<SPoint2> paramOnElement(GFace* gf, MElement* t) {
  if (t == nullptr) return {};
  const size_t n = t->getNumVertices();
  std::vector<SPoint2> uvs(n,SPoint2(0.,0.));

  bool reparam = false;
  for (size_t lv = 0; lv < n; ++lv) {
    MVertex* v = t->getVertex(lv);
    bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
    if (onGf) {
      v->getParameter(0,uvs[lv][0]);
      v->getParameter(1,uvs[lv][1]);
    } else {
      reparam = true;
    }
  }

  if (reparam) {
    bool found = false;
    for (size_t lv = 0; lv < n; ++lv) {
      MVertex* v = t->getVertex(lv);
      bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
      if (onGf) { 
        v->getParameter(0,uvs[lv][0]);
        v->getParameter(1,uvs[lv][1]);
        for (size_t k = 1; k < n; ++k) {
          MVertex* v2 = t->getVertex((lv+k)%n);
          reparamMeshVertexOnFaceWithRef(gf, v2, uvs[lv], uvs[(lv+k)%n]);
        }
        found = true;
        break;
      }
    }
    if (!found) {
      /* Element with no vertex inside the GFace, difficult to get
       * good UV parametrization, we use center projection to get
       * a initial guess */
      SPoint3 center = t->barycenter();
      double initialGuess[2] = {0.,0.};
      GPoint proj = gf->closestPoint(center,initialGuess);
      if (proj.succeeded()) {
        SPoint2 ref(proj.u(),proj.v());
        for (size_t k = 0; k < n; ++k) {
          MVertex* v = t->getVertex(k);
          reparamMeshVertexOnFaceWithRef(gf, v, ref, uvs[k]);
        }
      } else {
        Msg::Error("parametrization not found for element");
      }
    }
  }
  return uvs;
}

std::vector<MTriangle*> trianglesFromQuads(const std::vector<MQuadrangle*>& quads) {
  std::vector<MTriangle*> tris;
  tris.reserve(2*quads.size());
  for (MQuadrangle* q: quads) {
    MTriangle *t11 = new MTriangle(q->getVertex(0), q->getVertex(1), q->getVertex(2));
    MTriangle *t12 = new MTriangle(q->getVertex(0), q->getVertex(2), q->getVertex(3));
    tris.push_back(t11);
    tris.push_back(t12);
  }
  return tris;
}

bool fillSurfaceProjector(GFace* gf, SurfaceProjector* sp) {
  if (sp == nullptr) {
    Msg::Error("fillSurfaceProjector: given SurfaceProjector* is null !");
    abort();
  }

  if (gf->geomType() == GFace::GeomType::Sphere) {
    bool oka = sp->setAnalyticalProjection(gf);
    return oka;
  }

  bool deleteTheTris = false;
  std::vector<MTriangle*> triangles;

  /* warning: name should be the same a in meshQuadQuasiStructured.cpp
   * for this to work ! */
  const std::string BMESH_NAME = "bmesh_quadqs"; 
  if (backgroudMeshExists(BMESH_NAME)) {
    GlobalBackgroundMesh& bmesh = getBackgroundMesh(BMESH_NAME);
    auto it = bmesh.faceBackgroundMeshes.find(gf);
    if (it != bmesh.faceBackgroundMeshes.end() && it->second.triangles.size() > 0) {
      /* Get pointers to triangles in the background mesh */
      triangles.resize(it->second.triangles.size());
      for (size_t i = 0; i < it->second.triangles.size(); ++i) {
        triangles[i] = &(it->second.triangles[i]);
      }
      deleteTheTris = false;
    }
  } 

  if (triangles.size() == 0) {
    if (gf->triangles.size() > 0 && gf->quadrangles.size() == 0) {
      triangles = gf->triangles;
      deleteTheTris = false;
    } else if (gf->triangles.size() == 0 && gf->quadrangles.size() > 0) {
      triangles = trianglesFromQuads(gf->quadrangles);
      deleteTheTris = true;
    } else {
      Msg::Error("fillSurfaceProjector: case not supported");
      return false;
    }
  }

  if (triangles.size() == 0) {
    Msg::Error("fillSurfaceProjector: no triangles to use");
    return false;
  }

  bool oki = sp->initialize(gf, triangles);
  if (!oki) {
    Msg::Error("failed to initialize the surface projector");
  }

  if (deleteTheTris){
    for (MTriangle* t: triangles) delete t;
  }

  return true;
}

int surfaceEulerCharacteristicDiscrete(const std::vector<MTriangle*>& triangles) {
  if (triangles.size() == 0) {
    Msg::Error("no triangulation for face, cannot compute discrete Euler characteristic");
    return std::numeric_limits<int>::max();
  }
  std::vector<size_t> vertices;
  std::vector<std::array<size_t,2> > edges;
  vertices.reserve(3*triangles.size());
  edges.reserve(3*triangles.size());
  for (MTriangle* t: triangles) {
    for (size_t lv = 0; lv < 3; ++lv) {
      size_t v1 = t->getVertex(lv)->getNum();
      size_t v2 = t->getVertex((lv+1)%3)->getNum();
      std::array<size_t,2> vPair = {v1,v2};
      if (v1 > v2) vPair = {v2,v1};
      edges.push_back(vPair);
      vertices.push_back(v1);
    }
  }
  sort_unique(vertices);
  sort_unique(edges);
  int S = triangles.size();
  int E = edges.size();
  int V = vertices.size();
  return V - E + S;
}

inline void normalize_accurate(SVector3& a) {
  double amp = std::abs(a.data()[0]);
  amp = std::max(amp,std::abs(a.data()[1]));
  amp = std::max(amp,std::abs(a.data()[2]));
  if (amp == 0.) {
    return;
  }
  a = amp * a;
  a.normalize();
}

inline double angleVectors(SVector3 a, SVector3 b) {
  if (a.normSq() == 0. || b.normSq() == 0.) return DBL_MAX;
  normalize_accurate(a);
  normalize_accurate(b);
  return acos(ArrayGeometry::clamp(dot(a,b),-1.,1.)); 
}

bool fillGFaceInfo(GFace* gf, GFaceInfo& info) {
  info.gf = gf;
  info.chi = 0;
  info.cornerIsNonManifold.clear();
  for (auto& a: info.bdrValVertices) a.clear();
  info.intSumVal3mVal5 = 0;

  std::vector<MTriangle*> triangles;
  bool delTriangles = false;
  if (gf->triangles.size() > 0 && gf->quadrangles.size() == 0) {
    triangles = gf->triangles;
  } else if (gf->quadrangles.size() > 0 && gf->triangles.size() == 0) {
    triangles.reserve(2*gf->quadrangles.size());
    for (MQuadrangle* f: gf->quadrangles) {
      MVertex* v0 = f->getVertex(0);
      MVertex* v1 = f->getVertex(1);
      MVertex* v2 = f->getVertex(2);
      MVertex* v3 = f->getVertex(3);
      MTriangle* t1 = new MTriangle(v0,v1,v2);
      MTriangle* t2 = new MTriangle(v0,v2,v3);
      triangles.push_back(t1);
      triangles.push_back(t2);
    }
    delTriangles = true;
  } else {
    Msg::Error("fillGFaceInfo: no triangles and no quads, cannot compute");
    return false;
  }

  /* Compute geometric info */
  robin_hood::unordered_map<GVertex*,std::vector<MElement*> > corner2tris;
  robin_hood::unordered_map<GVertex*,double> corner2angle;
  for (MTriangle* t: triangles) {
    for (size_t lv = 0; lv < 3; ++lv) {
      MVertex* v = t->getVertex(lv);
      GVertex* gv = v->onWhat()->cast2Vertex();
      if (gv != nullptr) {
        MVertex* vPrev = t->getVertex((3+lv-1)%3);
        MVertex* vNext = t->getVertex((lv+1)%3);
        SVector3 pNext = vNext->point();
        SVector3 pPrev = vPrev->point();
        SVector3 pCurr = v->point();
        double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
        corner2tris[gv].push_back(t);
        corner2angle[gv] += agl;
      }
    }
  }
  robin_hood::unordered_set<GVertex*> boundaryCADcorners;
  for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
    boundaryCADcorners.insert(gv);
  }

  for (const auto& kv: corner2tris) {
    GVertex* gv = kv.first;
    /* Check if corner is manifold */
    {
      auto it = boundaryCADcorners.find(gv);
      if (it == boundaryCADcorners.end()) continue; /* ignore interior GVertex */
    }
    std::vector<MElement*> elts = kv.second;
    std::vector<MVertex*> bnd;
    bool okb = buildBoundary(elts, bnd);
    if (!okb) {
      info.cornerIsNonManifold.insert(gv);
      continue;
    }
    double angle = corner2angle[gv];
    double angle_deg = 180. / M_PI * angle;
    if (angle_deg < 90. + 45.) {
      info.bdrValVertices[1].insert(gv);
    } else if (angle_deg < 180. + 45.) {
      info.bdrValVertices[2].insert(gv);
    } else if (angle_deg < 270. + 45.) {
      info.bdrValVertices[3].insert(gv);
    } else if (angle_deg < 360.) {
      info.bdrValVertices[4].insert(gv);
    } else {
      Msg::Warning("CAD vertex (surf=%i,node=%i) has angle = %f deg (interior node ?)", gf->tag(), gv->tag(), angle_deg);
      continue;
    }
  }
  info.chi = surfaceEulerCharacteristicDiscrete(triangles);

  /* discrete topological relations between irregular vertices:
   *  sum3m5 = n_val3 - n_val5 = 4 \chi + m_val3 - m_val1  + 2 m_val4 */
  info.intSumVal3mVal5 = 4*info.chi + int(info.bdrValVertices[3].size()) 
    - int(info.bdrValVertices[1].size()) + 2 * int(info.bdrValVertices[4].size());

  if (delTriangles) {
    for (MTriangle* t: triangles) delete t;
  }

  return true;
}

bool appendCADStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix) {
  stats[prefix+"n_corners"] = double(gm->getVertices().size());
  stats[prefix+"n_curves"] = double(model_edges(gm).size());
  stats[prefix+"n_faces"] = double(model_faces(gm).size());
  stats[prefix+"n_volumes"] = double(gm->getRegions().size());
  return true;
}

bool appendQuadMeshStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix) {
  Msg::Debug("compute quad mesh statistics ...");
  /* Stats on regularity of vertices */
  std::vector<MQuadrangle*> all_quads;
  {
    std::vector<int> nValFace(10,0);
    std::vector<int> nValCurve(10,0);
    std::vector<int> nValCorner(10,0);
    double nVert = 0.; /* repetition on shared GVertex / GEdge */
    double nQuad = 0.;
    for (GFace* gf: model_faces(gm)) {
      append(all_quads,gf->quadrangles);
      unordered_map<MVertex *, std::vector<MElement *> > adj;
      for (MQuadrangle* f: gf->quadrangles) {
        nQuad += 1.;
        for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v = f->getVertex(lv);
          adj[v].push_back(f);
        }
      }
      for (auto& kv: adj) {
        nVert += 1.;
        MVertex* v = kv.first;
        GEntity* ent = v->onWhat();
        bool onCorner = (dynamic_cast<GVertex*>(ent) != NULL);
        bool onCurve = (dynamic_cast<GEdge*>(ent) != NULL);
        bool onFace = (dynamic_cast<GFace*>(ent) != NULL);
        int val = (int) kv.second.size();
        if (onCorner) {
          if ((size_t)val >= nValCorner.size()) nValCorner.resize(val+1);
          nValCorner[val] += 1;
        } else if (onCurve) {
          if ((size_t)val >= nValCurve.size()) nValCurve.resize(val+1);
          nValCurve[val] += 1;
        } else if (onFace) {
          if ((size_t)val >= nValFace.size()) nValFace.resize(val+1);
          nValFace[val] += 1;
        }
      }
    }
    double regular = 0.;
    double irregular = 0.;
    double very_irregular = 0.;
    double val3 = 0.;
    double val5 = 0.;
    for (size_t val = 0; val < nValCurve.size(); ++val) {
      if (val == 2) {
        regular += double(nValCurve[val]);
      } else if (val == 1 || val == 3){
        irregular += double(nValCurve[val]);
      } else {
        very_irregular += double(nValCurve[val]);
      }
    }
    for (size_t val = 0; val < nValFace.size(); ++val) {
      if (val == 4) {
        regular += double(nValFace[val]);
      } else if (val == 3) {
        irregular += double(nValFace[val]);
        val3 += double(nValFace[val]);
      } else if (val == 5) {
        irregular += double(nValFace[val]);
        val5 += double(nValFace[val]);
      } else {
        very_irregular += double(nValFace[val]);
      }
    }
    stats[prefix+"n_quads"] = nQuad;
    stats[prefix+"n_vertices"] = nVert;
    stats[prefix+"n_regular"] = regular;
    stats[prefix+"n_irregular"] = irregular;
    stats[prefix+"n_very_irregular"] = very_irregular;
    stats[prefix+"n_val3"] = val3;
    stats[prefix+"n_val5"] = val5;
  }

  /* Quality stats */
  if (all_quads.size() > 0){
    std::vector<double> quality(all_quads.size());
    std::vector<double> edgeLen(4*all_quads.size());
    double edge_len_min = DBL_MAX;
    double edge_len_avg = 0.;
    double edge_len_max = 0.;
    double edge_n = 0.;
    double avg = 0.;
    for (size_t f = 0; f < all_quads.size(); ++f) {
      quality[f] = all_quads[f]->minSICNShapeMeasure();
      avg += quality[f];
      for (size_t le = 0; le < 4; ++le) {
        SPoint3 p1 = all_quads[f]->getVertex(le)->point();
        SPoint3 p2 = all_quads[f]->getVertex((le+1)%4)->point();
        double len = p1.distance(p2);
        edgeLen[4*f+le] = len;
        edge_len_min = std::min(edge_len_min, len);
        edge_len_max = std::max(edge_len_max, len);
        edge_len_avg += len;
        edge_n += 1.;
      }
    }
    avg /= quality.size();
    edge_len_avg /= edge_n;
    std::sort(quality.begin(),quality.end());
    std::sort(edgeLen.begin(),edgeLen.end());
    stats[prefix+"SICN_min"] = quality[0];
    stats[prefix+"SICN_avg"] = avg;
    stats[prefix+"SICN_max"] = quality.back();
    stats[prefix+"SICN_med"] = quality[size_t(0.50*double(quality.size()))];
    // stats[prefix+"SICN_01% <"] = quality[size_t(0.01*double(quality.size()))];
    // stats[prefix+"SICN_10% <"] = quality[size_t(0.10*double(quality.size()))];
    // stats[prefix+"SICN_25% <"] = quality[size_t(0.25*double(quality.size()))];
    // stats[prefix+"SICN_50% <"] = quality[size_t(0.50*double(quality.size()))];
    // stats[prefix+"SICN_75% <"] = quality[size_t(0.75*double(quality.size()))];
    // stats[prefix+"SICN_90% <"] = quality[size_t(0.90*double(quality.size()))];
    // stats[prefix+"SICN_99% <"] = quality[size_t(0.99*double(quality.size()))];

    stats[prefix+"edge_min"] = edgeLen.front();
    stats[prefix+"edge_avg"] = edge_len_avg;
    stats[prefix+"edge_med"] = edgeLen[size_t(0.5*double(edgeLen.size()))];
    stats[prefix+"edge_max"] = edgeLen.back();
  }


  return true;
}

void printStatistics(const unordered_map<std::string,double>& stats, const std::string& title) {
  std::vector<std::string> keys;
  for (auto& kv: stats) keys.push_back(kv.first);
  std::sort(keys.begin(),keys.end());
  Msg::Info("%s", title.c_str());;
  for (std::string key: keys) {
    double val = stats.at(key);
    if (std::trunc(val) == val) {
      Msg::Info("- %s: %i", key.c_str(),int(val));
    } else {
      Msg::Info("- %s: %f", key.c_str(),val);
    }
  }
}

void writeStatistics(const unordered_map<std::string,double>& stats, const std::string& path) {
  std::vector<std::string> keys;
  for (auto& kv: stats) keys.push_back(kv.first);
  std::sort(keys.begin(),keys.end());

  std::ofstream out(path);
  out << "{\n";
  for (size_t i = 0; i < keys.size(); ++i) {
    std::string key = keys[i];
    double val = stats.at(key);
    if (std::trunc(val) == val) {
      out << "\"" << key << "\"" << ": " << int(val);
    } else {
      out << "\"" << key << "\"" << ": " << val;
    }
    if ((int)i < (int)keys.size()-1) {
      out << ",\n";
    } else {
      out << "\n";
    }
  }
  out << "}\n";
  out.close();
}

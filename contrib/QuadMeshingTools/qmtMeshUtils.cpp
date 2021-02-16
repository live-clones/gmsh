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

// /* QuadMeshingTools includes */
#include "cppUtils.h"
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

bool patchFromElements(GFace* gf, const std::vector<MElement*>& elements, GFaceMeshPatch& patch) {
  patch.gf = gf;
  bool okb = buildBoundaries(elements, patch.bdrVertices);
  if (!okb) return false;

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

bool patchFromQuads(GFace* gf, const std::vector<MQuadrangle*>& quads, GFaceMeshPatch& patch) {
  std::vector<MElement*> elts = dynamic_cast_vector<MQuadrangle*,MElement*>(quads);
  return patchFromElements(gf, elts, patch);
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

std::array<SPoint2,3> paramOnTriangle(GFace* gf, MTriangle* t) {
  std::array<SPoint2,3> tri_uvs = {SPoint2{0.,0.},SPoint2{0.,0.},SPoint2{0.,0.}};
  if (t == nullptr) return tri_uvs;
  bool check_periodicity = false;
  for (size_t lv = 0; lv < t->getNumVertices(); ++lv) {
    MVertex* v = t->getVertex(lv);
    bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
    if (onGf) {
      v->getParameter(0,tri_uvs[lv][0]);
      v->getParameter(1,tri_uvs[lv][1]);
    } else {
      check_periodicity = true;
    }
  }

  if (check_periodicity) {
    bool found = false;
    for (size_t lv = 0; lv < t->getNumVertices(); ++lv) {
      MVertex* v1 = t->getVertex(lv);
      bool onGf = (dynamic_cast<GFace*>(v1->onWhat()) == gf);
      if (onGf) {
        MVertex* v2 = t->getVertex((lv+1)%3);
        MVertex* v3 = t->getVertex((lv+2)%3);
        SPoint2 param1;
        SPoint2 param2;
        SPoint2 param3;
        reparamMeshEdgeOnFace(v1, v2, gf, param1, param2);
        reparamMeshEdgeOnFace(v1, v3, gf, param1, param3);
        tri_uvs[(lv+0)%3] = {param1.x(),param1.y()};
        tri_uvs[(lv+1)%3] = {param2.x(),param2.y()};
        tri_uvs[(lv+2)%3] = {param3.x(),param3.y()};
        found = true;
        break;
      }
    }
    if (!found) {
      /* Triangle with no vertex inside the GFace, difficult to get
       * good UV parametrization, we use center projection to get
       * a initial guess */
      SPoint3 center = t->barycenter();
      double initialGuess[2] = {0.,0.};
      GPoint proj = gf->closestPoint(center,initialGuess);
      if (proj.succeeded()) {
        MFaceVertex cv(proj.x(),proj.y(),proj.z(),gf,proj.u(),proj.v());
        MVertex* v1 = t->getVertex(0);
        MVertex* v2 = t->getVertex(1);
        MVertex* v3 = t->getVertex(2);
        SPoint2 paramc;
        SPoint2 param1;
        SPoint2 param2;
        SPoint2 param3;
        reparamMeshEdgeOnFace(&cv, v1, gf, paramc, param1);
        reparamMeshEdgeOnFace(&cv, v2, gf, paramc, param2);
        reparamMeshEdgeOnFace(&cv, v3, gf, paramc, param3);
        tri_uvs[0] = {param1.x(),param1.y()};
        tri_uvs[1] = {param2.x(),param2.y()};
        tri_uvs[2] = {param3.x(),param3.y()};
      } else {
        tri_uvs[0] = {0.,0.};
        tri_uvs[1] = {0.,0.};
        tri_uvs[2] = {0.,0.};
      }
    }
  }

  return tri_uvs;
}

std::array<SPoint2,4> paramOnQuad(GFace* gf, MQuadrangle* t) {
  std::array<SPoint2,4> uvs = {SPoint2{0.,0.},SPoint2{0.,0.},
    SPoint2{0.,0.},SPoint2{0.,0.}};
  if (t == nullptr) return uvs;
  bool check_periodicity = false;
  for (size_t lv = 0; lv < t->getNumVertices(); ++lv) {
    MVertex* v = t->getVertex(lv);
    bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
    if (onGf) {
      v->getParameter(0,uvs[lv][0]);
      v->getParameter(1,uvs[lv][1]);
    } else {
      check_periodicity = true;
    }
  }

  if (check_periodicity) {
    bool found = false;
    for (size_t lv = 0; lv < t->getNumVertices(); ++lv) {
      MVertex* v1 = t->getVertex(lv);
      bool onGf = (dynamic_cast<GFace*>(v1->onWhat()) == gf);
      if (onGf || lv == 3) { /* If neither of the 3 are on surface, takes random ... */
        MVertex* v2 = t->getVertex((lv+1)%4);
        MVertex* v3 = t->getVertex((lv+2)%4);
        MVertex* v4 = t->getVertex((lv+3)%4);
        SPoint2 param1;
        SPoint2 param2;
        SPoint2 param3;
        SPoint2 param4;
        reparamMeshEdgeOnFace(v1, v2, gf, param1, param2);
        reparamMeshEdgeOnFace(v1, v3, gf, param1, param3);
        reparamMeshEdgeOnFace(v1, v4, gf, param1, param4);
        uvs[(lv+0)%4] = {param1.x(),param1.y()};
        uvs[(lv+1)%4] = {param2.x(),param2.y()};
        uvs[(lv+2)%4] = {param3.x(),param3.y()};
        uvs[(lv+3)%4] = {param4.x(),param4.y()};
        break;
      }
    }
    if (!found) {
      /* Quad with no vertex inside the GFace, difficult to get
       * good UV parametrization, we use center projection to get
       * a initial guess */
      SPoint3 center = t->barycenter();
      double initialGuess[2] = {0.,0.};
      GPoint proj = gf->closestPoint(center,initialGuess);
      if (proj.succeeded()) {
        MFaceVertex cv(proj.x(),proj.y(),proj.z(),gf,proj.u(),proj.v());
        MVertex* v1 = t->getVertex(0);
        MVertex* v2 = t->getVertex(1);
        MVertex* v3 = t->getVertex(2);
        MVertex* v4 = t->getVertex(3);
        SPoint2 paramc;
        SPoint2 param1;
        SPoint2 param2;
        SPoint2 param3;
        SPoint2 param4;
        reparamMeshEdgeOnFace(&cv, v1, gf, paramc, param1);
        reparamMeshEdgeOnFace(&cv, v2, gf, paramc, param2);
        reparamMeshEdgeOnFace(&cv, v3, gf, paramc, param3);
        reparamMeshEdgeOnFace(&cv, v4, gf, paramc, param4);
        uvs[0] = {param1.x(),param1.y()};
        uvs[1] = {param2.x(),param2.y()};
        uvs[2] = {param3.x(),param3.y()};
        uvs[3] = {param4.x(),param4.y()};
      } else {
        uvs[0] = {0.,0.};
        uvs[1] = {0.,0.};
        uvs[2] = {0.,0.};
        uvs[3] = {0.,0.};
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

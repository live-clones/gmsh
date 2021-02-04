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

// /* QuadMeshingTools includes */
#include "cppUtils.h"

using namespace CppUtils;
using std::unordered_map;

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
  bool okb = buildBoundary(elements, patch.bdrVertices);
  if (!okb) return false;

  /* Ensure no repetition in the boundary loop */
  if (patch.bdrVertices.back() == patch.bdrVertices.front()) patch.bdrVertices.pop_back();

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
  patch.intVertices = difference(patch.intVertices, patch.bdrVertices);
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

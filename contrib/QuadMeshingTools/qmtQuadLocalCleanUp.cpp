// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtQuadLocalCleanUp.h"

/* System includes */
// #include <vector>
// #include <array>
// #include <unordered_map>
// #include <cstdint>
// #include <cmath>
#include <queue>
#include <unordered_set>
#include <cassert>
// #include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "meshOctreeLibOL.h"
#include "meshPolyMesh.h"
#include "meshTriangulation.h"
#include "gmsh.h" // api

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "qmtMeshGeometryOptimization.h"
#include "robin_hood.h" // fast unordered_set and unordered_map
#include "geolog.h"

using namespace CppUtils;

inline void laplacianSmoothing(PolyMesh::Vertex* v) {
  SVector3 avg(0.,0.,0.);
  double n = 0.;
  PolyMesh::HalfEdge *he = v->he;
  do {
    he = he->opposite;
    if(he == NULL) return;
    avg = avg + he->v->position;
    n += 1;
    he = he->next;
  } while(he != v->he);
  if (n == 0.) return;
  v->position = avg * double(1./n);
}

inline double angleAcosDot(const SVector3& a, const SVector3& b) {
  double dp = dot(a,b);
  if (dp < -1.) {
    dp = -1.;
  } else if (dp > 1.) {
    dp = 1.;
  }
  return acos(dp);
}

inline double quadQuality(PolyMesh* pm, PolyMesh::Face* f) {
  if (pm->num_sides(f->he) == 4) {
    PolyMesh::Vertex *v0 = f->he->v;
    PolyMesh::Vertex *v1 = f->he->next->v;
    PolyMesh::Vertex *v2 = f->he->next->next->v;
    PolyMesh::Vertex *v3 = f->he->next->next->next->v;
    MVertex a(v0->position.x(),v0->position.y(),v0->position.z());
    MVertex b(v1->position.x(),v1->position.y(),v1->position.z());
    MVertex c(v2->position.x(),v2->position.y(),v2->position.z());
    MVertex d(v3->position.x(),v3->position.y(),v3->position.z());
    MQuadrangle q(&a,&b,&c,&d);
    double sicn = q.minSICNShapeMeasure();
    if (std::isnan(sicn)) sicn = -999.;
    return sicn;
  }
  Msg::Error("quadQuality: not a quad");
  return -1.;
}

inline SVector3 face_center(PolyMesh::Face* f) { 
  const PolyMesh::HalfEdge *he = f->he;
  SVector3 avg(0.,0.,0.);
  double sum = 0.;
  do {
    avg = avg + he->v->position;
    sum += 1.;
    he = he->next;
  } while(he != f->he);
  if (sum > 0.) avg = 1./sum * avg;
  return avg;
}

inline void clearHalfEdge(PolyMesh::HalfEdge* he) {
  he->v = nullptr;
  he->next = nullptr;
  he->prev = nullptr;
  he->f = nullptr;
  he->opposite = nullptr;
}

inline void setOpposite(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->opposite = b;
  b->opposite = a;
}

inline void setConsecutive(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->next = b;
  b->prev = a;
}

inline void setTriRelations(PolyMesh::Face* f, 
    PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b, PolyMesh::HalfEdge* c) {
  f->he = a;
  a->f = f;
  b->f = f;
  c->f = f;
  setConsecutive(a,b);
  setConsecutive(b,c);
  setConsecutive(c,a);
}

inline void setQuadRelations(PolyMesh::Face* f, 
    PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b,
    PolyMesh::HalfEdge* c, PolyMesh::HalfEdge* d) {
  f->he = a;
  a->f = f;
  b->f = f;
  c->f = f;
  d->f = f;
  setConsecutive(a,b);
  setConsecutive(b,c);
  setConsecutive(c,d);
  setConsecutive(d,a);
}

bool fixFlatBoundaryQuadWithInterior(PolyMesh* pm, PolyMesh::HalfEdge* he0) {
  PolyMesh::Face* f0 = he0->f;
  PolyMesh::HalfEdge* he1 = he0->next;
  PolyMesh::HalfEdge* he2 = he1->next;
  PolyMesh::HalfEdge* he3 = he2->next;
  PolyMesh::Vertex* v2 = he2->v;

  int valInterior = pm->degree(v2);
  if (valInterior == 5) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 5, fixing ...");
    PolyMesh::HalfEdge* he4 = he1->opposite->prev->opposite->prev;
    PolyMesh::HalfEdge* he4b = he4->opposite;

    /* New vertices */
    PolyMesh::Vertex* v5 = new PolyMesh::Vertex(he1->opposite->prev->center(),-1);
    PolyMesh::Vertex* v6 = new PolyMesh::Vertex(he2->opposite->next->center(),-1);
    pm->vertices.push_back(v5);
    pm->vertices.push_back(v6);
    v5->he = he1->opposite;
    v6->he = he2;
    v2->position = 0.8 * v2->position  + 0.2 * he0->v->position;

    /* Update halfedge vertex outside the three quads */
    he1->opposite->v = v5;
    he4->next->v = v5;
    he2->opposite->next->v = v6;
    he4b->v = v6;
    /* Update halfedge vertex inside the three quads */
    he2->v = v6;

    /* New halfedges and new quads */
    PolyMesh::HalfEdge* sp = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* s = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sb = new PolyMesh::HalfEdge(he0->v);
    PolyMesh::HalfEdge* sbn = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* spb = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sbnb = new PolyMesh::HalfEdge(v6);
    PolyMesh::HalfEdge* he4o = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* he4bo = new PolyMesh::HalfEdge(he4->v);
    pm->hedges.push_back(sp);
    pm->hedges.push_back(s);
    pm->hedges.push_back(sb);
    pm->hedges.push_back(sbn);
    pm->hedges.push_back(spb);
    pm->hedges.push_back(sbnb);
    pm->hedges.push_back(he4o);
    pm->hedges.push_back(he4bo);
    setOpposite(s,sb);
    setOpposite(sp,spb);
    setOpposite(sbn,sbnb);
    setOpposite(he4,he4o);
    setOpposite(he4b,he4bo);

    PolyMesh::Face* nfr = new PolyMesh::Face(he3);
    PolyMesh::Face* nft = new PolyMesh::Face(sbnb);
    nfr->data = f0->data;
    nft->data = f0->data;
    pm->faces.push_back(nfr);
    pm->faces.push_back(nft);

    setQuadRelations(f0,he0,he1,sp,s);
    setQuadRelations(nfr,he2,he3,sb,sbn);
    setQuadRelations(nft,spb,he4o,he4bo,sbnb);

    laplacianSmoothing(v5);
    laplacianSmoothing(v6);

    return true;
  } else if (valInterior == 4) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 4, fixing ...");
    PolyMesh::HalfEdge* tl = he1->opposite->prev->opposite;
    PolyMesh::HalfEdge* tr = tl->prev;
    PolyMesh::Vertex* vtop = tl->next->next->v;
    PolyMesh::Face* ftl = tl->f;

    /* New vertices */
    PolyMesh::Vertex* v5 = new PolyMesh::Vertex(face_center(he1->opposite->f),-1);
    PolyMesh::Vertex* v6 = new PolyMesh::Vertex(face_center(he2->opposite->f),-1);
    pm->vertices.push_back(v5);
    pm->vertices.push_back(v6);
    v5->he = he1->opposite;
    v6->he = he2;

    /* In bottom quads (adjacent to bdr) */
    PolyMesh::HalfEdge* sp = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* s = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sb = new PolyMesh::HalfEdge(he0->v);
    PolyMesh::HalfEdge* sbn = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* spb = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sbnb = new PolyMesh::HalfEdge(v6);
    pm->hedges.push_back(sp);
    pm->hedges.push_back(s);
    pm->hedges.push_back(sb);
    pm->hedges.push_back(sbn);
    pm->hedges.push_back(spb);
    pm->hedges.push_back(sbnb);
    setOpposite(s,sb);
    setOpposite(sp,spb);
    setOpposite(sbn,sbnb);

    PolyMesh::Face* nfr = new PolyMesh::Face(he3);
    nfr->data = f0->data;
    pm->faces.push_back(nfr);

    v2->he = s;
    setQuadRelations(f0,he0,he1,sp,s);
    setQuadRelations(nfr,he2,he3,sb,sbn);

    /* In top quads */
    PolyMesh::HalfEdge* tm = new PolyMesh::HalfEdge(vtop);
    PolyMesh::HalfEdge* tmb = new PolyMesh::HalfEdge(v2);
    pm->hedges.push_back(tm);
    pm->hedges.push_back(tmb);
    setOpposite(tm,tmb);

    PolyMesh::Face* nftr = new PolyMesh::Face(tr);
    nftr->data = f0->data;
    pm->faces.push_back(nftr);

    setQuadRelations(ftl,tl,tl->next,tm,spb);
    setQuadRelations(nftr,tr->prev,tr,sbnb,tmb);

    /* Update halfedge vertex inside the four quads */
    tl->v = v5;
    he2->v = v6;
    /* Update halfedge vertex outside the four quads */
    he1->opposite->v = v5;
    he2->opposite->next->v = v6;

    laplacianSmoothing(v5);
    laplacianSmoothing(v6);

    return true;
  } else if (valInterior == 3) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 3, fixing ...");
    PolyMesh::Face* f1 = he1->opposite->f;
    PolyMesh::Face* f2 = he2->opposite->f;

    setQuadRelations(f1, 
        he0, 
        he1->opposite->next,
        he1->opposite->next->next,
        he1->opposite->next->next->next);

    setQuadRelations(f2, 
        he3, 
        he2->opposite->next,
        he2->opposite->next->next,
        he2->opposite->next->next->next);

    /* Update vertex to half edges */
    he1->v->he = he1->opposite->next;
    he3->v->he = he3;
    he0->v->he = he0;
    he2->opposite->next->v = he0->v;

    /* Flag for delete by pm->clean */
    f0->he = nullptr;
    v2->he = nullptr;
    clearHalfEdge(he1->opposite);
    clearHalfEdge(he1);
    clearHalfEdge(he2->opposite);
    clearHalfEdge(he2);

    return true;
  }

  Msg::Warning("flat boundary quad but interior valence %i, no rule to fix it", valInterior);
  return false;
}

bool fixFlatBoundaryQuadWithNeighbor(PolyMesh* pm, PolyMesh::HalfEdge* he0) {
  PolyMesh::Face* f0 = he0->f;
  PolyMesh::HalfEdge* he1 = he0->next;
  PolyMesh::HalfEdge* he2 = he1->next;
  PolyMesh::HalfEdge* he3 = he2->next;
  PolyMesh::Vertex* v2 = he2->v;
  if (he1->opposite != nullptr) {
    Msg::Debug("fixFlatBoundaryQuadWithNeighbor: quad on left ...");
    PolyMesh::HalfEdge* he4 = he1->opposite;
    PolyMesh::HalfEdge* he7 = he4->prev;
    PolyMesh::Face* f1 = he4->f;
    PolyMesh::Vertex* a = new PolyMesh::Vertex(face_center(f0),-1);
    PolyMesh::Vertex* b = new PolyMesh::Vertex(face_center(f1),-1);
    pm->vertices.push_back(a);
    pm->vertices.push_back(b);
    PolyMesh::HalfEdge* ab = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* ba = new PolyMesh::HalfEdge(b);
    pm->hedges.push_back(ab);
    pm->hedges.push_back(ba);
    setOpposite(ab,ba);
    a->he = ab;
    b->he = ba;
    PolyMesh::HalfEdge* av0 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v0a = new PolyMesh::HalfEdge(he0->v);
    pm->hedges.push_back(av0);
    pm->hedges.push_back(v0a);
    setOpposite(av0,v0a);
    PolyMesh::HalfEdge* av2 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v2a = new PolyMesh::HalfEdge(he2->v);
    pm->hedges.push_back(av2);
    pm->hedges.push_back(v2a);
    setOpposite(av2,v2a);
    PolyMesh::HalfEdge* bv7 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v7b = new PolyMesh::HalfEdge(he7->v);
    pm->hedges.push_back(bv7);
    pm->hedges.push_back(v7b);
    setOpposite(bv7,v7b);
    he4->v = b;
    PolyMesh::Face* fb = new PolyMesh::Face(he0);
    PolyMesh::Face* ft = new PolyMesh::Face(he7);
    pm->faces.push_back(fb);
    pm->faces.push_back(ft);
    fb->data = f0->data;
    ft->data = f0->data;
    v2->he = he2;
    he0->v->he = he0;
    he7->v->he = he7;
    setQuadRelations(f0,he2,he3,v0a,av2);
    setQuadRelations(f1,he4,he4->next,he4->next->next,v7b);
    setQuadRelations(ft,he7,v2a,ab,bv7);
    setQuadRelations(fb,he0,he1,ba,av0);

    laplacianSmoothing(a);
    laplacianSmoothing(b);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    return true;
  } else if (he2->opposite != nullptr) {
    Msg::Debug("fixFlatBoundaryQuadWithNeighbor: quad on right ...");
    PolyMesh::HalfEdge* he4 = he2->opposite;
    PolyMesh::HalfEdge* he5 = he4->next;
    PolyMesh::HalfEdge* he6 = he4->next->next;
    PolyMesh::Face* f1 = he4->f;
    PolyMesh::Vertex* a = new PolyMesh::Vertex(face_center(f0),-1);
    PolyMesh::Vertex* b = new PolyMesh::Vertex(face_center(f1),-1);
    pm->vertices.push_back(a);
    pm->vertices.push_back(b);
    PolyMesh::HalfEdge* ab = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* ba = new PolyMesh::HalfEdge(b);
    pm->hedges.push_back(ab);
    pm->hedges.push_back(ba);
    setOpposite(ab,ba);
    a->he = ab;
    b->he = ba;
    PolyMesh::HalfEdge* av0 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v0a = new PolyMesh::HalfEdge(he0->v);
    pm->hedges.push_back(av0);
    pm->hedges.push_back(v0a);
    setOpposite(av0,v0a);

    he4->v = a;

    PolyMesh::HalfEdge* bv3 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v3b = new PolyMesh::HalfEdge(he3->v);
    pm->hedges.push_back(bv3);
    pm->hedges.push_back(v3b);
    setOpposite(bv3,v3b);

    PolyMesh::HalfEdge* bv6 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v6b = new PolyMesh::HalfEdge(he6->v);
    pm->hedges.push_back(bv6);
    pm->hedges.push_back(v6b);
    setOpposite(bv6,v6b);

    PolyMesh::Face* fb = new PolyMesh::Face(he3);
    PolyMesh::Face* ft = new PolyMesh::Face(he4);
    pm->faces.push_back(fb);
    pm->faces.push_back(ft);
    fb->data = f0->data;
    ft->data = f0->data;
    he3->v->he = he3;
    he0->v->he = he0;
    he6->v->he = he6;
    setQuadRelations(f0,he0,he1,he2,av0);
    setQuadRelations(f1,he6,he6->next,v3b,bv6);
    setQuadRelations(ft,ba,he4,he5,v6b);
    setQuadRelations(fb,he3,v0a,ab,bv3);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    return true;
  }
  Msg::Warning("flat boundary quad but tip on bdr, no rule to fix it");
  return false;
}

size_t removeQuadDuets(PolyMesh* pm) {
  size_t nduet = 0;
  for (PolyMesh::Vertex* v: pm->vertices) if (v != nullptr && v->he != nullptr) {
    if (pm->degree(v) == 2) {
      // Duet configuration around v:
      //    ┌───────── ◄──────┐
      //    │ 2             1 │
      //    ▼     3       0   │
      //     ┌───────► ┌──────►
      //     ◄───────┘ ◄──────┘
      //    │    3b       0b   ▲
      //    │4                5│
      //    └────────► ────────┘
      PolyMesh::HalfEdge* h0 = v->he;
      PolyMesh::HalfEdge* h1 = h0->next;
      PolyMesh::HalfEdge* h2 = h1->next;
      PolyMesh::HalfEdge* h3 = h2->next;
      PolyMesh::HalfEdge* h3b = h3->opposite;
      PolyMesh::HalfEdge* h0b = h0->opposite;
      PolyMesh::HalfEdge* h4 = h3b->next;
      PolyMesh::Face* f0 = h0->f;
      PolyMesh::Face* f1 = h0b->f;

      /* Update */
      setQuadRelations(f0,h1,h2,h4,h4->next);
      h1->v->he = h1;
      h4->v->he = h4;

      /* Flag for delete */
      v->he = nullptr;
      clearHalfEdge(h3);
      clearHalfEdge(h3b);
      clearHalfEdge(h0);
      clearHalfEdge(h0b);
      f1->he = nullptr;

      nduet += 1;
    }
  }
  return nduet;
}

size_t removeQuadDiamonds(PolyMesh* pm, 
    const std::unordered_map<PolyMesh::Vertex*,MVertex*>& onCurve) {
  size_t ndiamond = 0;
  for (PolyMesh::Vertex* v: pm->vertices) if (v != nullptr && v->he != nullptr) {
    if (pm->degree(v) == 3) {
      bool isDiamond = true;
      PolyMesh::HalfEdge* h0 = v->he;
      for (size_t lq = 0; lq < 3; ++lq) {
        if (h0->opposite == nullptr) {
          Msg::Warning("removeQuadDiamonds: no opposite, weird");
          continue;
        }
        if (lq != 0) h0 = h0->opposite->next;
        PolyMesh::HalfEdge* h1 = h0->next;
        PolyMesh::HalfEdge* h2 = h1->next;
        PolyMesh::HalfEdge* h3 = h2->next;
        // diamond, valences are (3,4+,3,4+), with 4+ can be 3+ on curve
        //     (3)─────►(4+)
        //       ▲  0  1│ 
        //       │3  2  ▼
        //    (4+)◄─────(3)
        if (pm->degree(h2->v) != 3) continue;

        int val1 = pm->degree(h1->v);
        if (val1 == -1 && onCurve.find(h1->v) != onCurve.end()) { /* special case on boundary curve */
          if (h0->opposite != nullptr && h1->opposite != nullptr && h0->opposite->f != h1->opposite->f) {
            val1 = 5; /* equivalent to 5 if h1->v was inside */
          }
        }
        if (val1 < 4) continue;

        int val3 = pm->degree(h3->v);
        if (val3 == -1 && onCurve.find(h3->v) != onCurve.end()) { /* special case on boundary curve */
          if (h2->opposite != nullptr && h3->opposite != nullptr && h2->opposite->f != h3->opposite->f) {
            val3 = 5; /* equivalent to 5 if h3->v was inside */
          }
        }
        if (val3 < 4) continue;

        PolyMesh::Vertex* vopp = h2->v;
        /* From here, diamond is eliminated */
        /* - update */
        setOpposite(h0->opposite,h1->opposite);
        setOpposite(h3->opposite,h2->opposite);
        /* - v to he */
        v->he = h3->opposite;
        h1->v->he = h0->opposite;
        h3->v->he = h2->opposite;
        /* - he to v */
        h1->opposite->v = v;
        h2->opposite->next->v = v;
        /* - flag for delete */
        h0->f->he = nullptr;
        vopp->he = nullptr;
        clearHalfEdge(h0);
        clearHalfEdge(h1);
        clearHalfEdge(h2);
        clearHalfEdge(h3);
        ndiamond += 1;
        break;
      }
    }
  }
  return ndiamond;
}

inline void show_polymesh(PolyMesh* pm, const std::string& name) {
  for (PolyMesh::Face* f: pm->faces) if (f && f->he) {
    std::vector<GeoLog::vec3> pts;
    PolyMesh::HalfEdge* he = f->he;
    do {
      pts.push_back(he->v->position);
      he = he->next;
    } while (he != f->he);
    GeoLog::add(pts,double(f->data),name);
  }
}

size_t removeQuadFlatOnBoundary(PolyMesh* pm, 
    const std::unordered_map<PolyMesh::Vertex*,MVertex*>& onBdr) {

  size_t nflatfix = 0;
  while (true) {
    /* Look for two consecutive halfedges on the boundary in the same quad */
    size_t n = 0;
    const size_t nhe = pm->hedges.size();
    for (size_t i = 0; i < nhe; ++i) {
      PolyMesh::HalfEdge* he0 = pm->hedges[i];
      if (he0 == nullptr || he0->f == nullptr) continue;
      PolyMesh::HalfEdge* he1 = he0->next;
      if (he1 == nullptr || he1->f == nullptr) continue;
      if (he0->f != he1->f) continue;
      if (he0->opposite != nullptr || he1->opposite != nullptr) continue;

      auto it = onBdr.find(he1->v);
      if (it == onBdr.end()) {
        Msg::Warning("remove flat bdr quads: vertex not found on curve");
        continue;
      }
      bool isFlatQuad = false;
      MVertex* origin = it->second;
      if (origin->onWhat()->dim() == 1) { 
        /* vertex on curve, we don't check the angle */
        isFlatQuad = true;
      } else if (origin->onWhat()->dim() == 0) {
        /* vertex on corner, check the geometry
         * would be best to have the ideal valence from the
         * CAD or background triangulation */
        double sicn = quadQuality(pm, he1->f);
        double aglDeg = angleAcosDot(he0->d(),he1->d()) * 180./M_PI;
        if (sicn < 0.01 && aglDeg < 50) {
          isFlatQuad = true;
        }
      }
      if (!isFlatQuad) continue;

      PolyMesh::HalfEdge* he2 = he1->next;
      PolyMesh::HalfEdge* he3 = he2->next;
      if (he2->opposite != nullptr && he3->opposite != nullptr) {
        /* The tip of the flat quad is inside the surface mesh */
        PolyMesh::Vertex* intVertex = he3->v;
        bool tipOnBdr = onBdr.find(intVertex) != onBdr.end();
        bool okf = false;
        if (!tipOnBdr && pm->degree(intVertex) < 6)  {
          okf = fixFlatBoundaryQuadWithInterior(pm, he1);
          // show_polymesh(pm,"fixed_flat_i");
          // GeoLog::flush();
          // if (n > 100) break;
        } else {
          /* no template for valence 6+, use the neighbor fallback */
          okf = fixFlatBoundaryQuadWithNeighbor(pm, he1);
          // show_polymesh(pm,"fixed_flat_wn");
          // GeoLog::flush();
          // if (n > 100) break;
        }
        if (okf) {
          n += 1;
        } else {
          Msg::Warning("failed to fix flat quad on boundary");
        }
      } else if (he2->opposite != nullptr || he3->opposite != nullptr) {
        /* The tip of the flat quad is on the boundary, so the configuration
         * is very constrained, but there is one side adjacent to another quad */
        bool okf = fixFlatBoundaryQuadWithNeighbor(pm, he1);
        // show_polymesh(pm,"fixed_flat_wn");
        // GeoLog::flush();
        // if (n > 100) break;
        if (okf) {
          n += 1;
        } else {
          Msg::Warning("failed to fix flat quad on boundary (tip also on boundary)");
        }
      }
    }
    if (n != 0) nflatfix += n;
    if (n == 0) break;

    // if (nflatfix > 100)  {
    //   // TODOMX
    //   gmsh::fltk::run();
    //   abort();
    // }
  }

  return nflatfix;
}

int improveQuadMeshTopologyWithLocalCleanup(GFace* gf, SurfaceProjector* sp) {
  Msg::Info("- Face %i: improve quad mesh topology with local clean up ...", gf->tag());
  if (gf->quadrangles.size() == 0 || gf->triangles.size() > 0) {
    Msg::Error("improve quad topology: face %i contains %li quads, %li triangles", 
        gf->tag(), gf->quadrangles.size(), gf->triangles.size());
    return -1;
  }

  /* Import quad mesh */
  PolyMesh *pm = nullptr;
  int result = GFace2PolyMesh (gf->tag(), &pm);
  if (result == -1) return result;

  /* Mark vertices on curves (including corners) */
  std::unordered_map<PolyMesh::Vertex*,MVertex*> onCurve;
  for (PolyMesh::HalfEdge* he: pm->hedges) if (he != nullptr && he->v != nullptr) {
    if (he->opposite == nullptr) {
      PolyMesh::Vertex* v = he->v;
      if (v->data >= 0) {
        MVertex* pv = GModel::current()->getMeshVertexByTag(v->data);
        if (pv != nullptr && pv->onWhat()->dim() <= 1) {
          onCurve[v] = pv;
        }
      }
    }
  }


  /* Clean-up loop */
  const size_t nIter = 3;
  const int PASS_DUET = 0;
  const int PASS_DIAMOND = 1;
  const int PASS_BDR_FLAT = 2;
  for (size_t iter = 0; iter < nIter; ++iter) {
    size_t nduet = 0;
    size_t ndiamond = 0;
    size_t nflat = 0;
    for (int pass: {PASS_DUET,PASS_DIAMOND,PASS_BDR_FLAT}) {
      if (pass == PASS_DUET) {
        nduet = removeQuadDuets(pm);
      } else if (pass == PASS_DIAMOND) {
        ndiamond = removeQuadDiamonds(pm,onCurve);
      } else if (pass == PASS_BDR_FLAT) {
        // nflat = removeQuadFlatOnBoundary(pm,onCurve);
      }
    }
    Msg::Info("- Face %i: quad clean-up, iter %i, eliminated %li duets, %li diamonds, %li flat bdr",
        gf->tag(), iter, nduet, ndiamond, nflat);
    if (nduet + ndiamond + nflat == 0) break;
  }


  /* Export cleaned quad mesh */
  // pm->clean();
  PolyMesh2GFace(pm, gf->tag());
  delete pm;

  if (sp != nullptr) {
    optimizeGeometryQuadMesh(gf, sp);
  }

  return 0;
}

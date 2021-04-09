// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshGFaceQuadLayer.h"
#include "meshPolyMesh.h"
#include "Context.h"
#include "GmshMessage.h"

#include <iostream>

#include "gmsh.h"
#include "cppUtils.h"
#include "geolog.h"
#include "arrayGeometry.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>
#include <cfloat>

using namespace ArrayGeometry;

vec3 _opposite_right_angled_corner(vec3 pPrev, vec3 pCorner, vec3 pNext) {
  double radius = 0.5 * length(pPrev-pNext);
  vec3 center = 0.5 * (pPrev+pNext);
  if (length(center-pCorner) < 1.e-10) {
    return center;
  }
  vec3 dir = center-pCorner;
  normalize(dir);
  return center + radius * dir;
}

void show_polymesh(PolyMesh* pm, const std::string& name) {
  for (PolyMesh::Face* f: pm->faces) if (f) {
    std::vector<vec3> pts;
    PolyMesh::HalfEdge* he = f->he;
    do {
      pts.push_back(he->v->position);
      he = he->next;
    } while (he != f->he);
    GeoLog::add(pts,double(f->data),name);
  }
}

void show_halfedge(PolyMesh::HalfEdge* he, const std::string& name) {
  vec3 p1 = he->first()->position;
  vec3 p2 = he->second()->position;
  GeoLog::add({p1,p2},std::vector<double>{0.,1.},name);
  vec3 dir = p2-p1;
  normalize(dir);
  GeoLog::add(0.5*(p1+p2),dir,name);
}

void launch_gmsh() {
  gmsh::initialize();
  GeoLog::flush();
  gmsh::fltk::run();
  abort();
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

double boundaryAngleAtOrigin(const PolyMesh* pm, PolyMesh::HalfEdge* he) {
  PolyMesh::HalfEdge* he0 = he;
  int faceTag = he0->f->data;
  double agl = 0.;
  size_t count = 0;
  do {
    SVector3 n1 = he->d();
    he = he->prev;
    if (he == nullptr) {
      Msg::Error("boundaryAngleAtOrigin: prev half-edge is null, should not happen");
      return -DBL_MAX;
    }
    SVector3 n2 = -1. * he->d();
    if (n1.normSq() > 0. && n2.normSq() > 0.) {
      agl += angleAcosDot(n1,n2);
    }

    he = he->opposite;
    count += 1;
  } while(he->f->data == faceTag);

  return agl;
}

PolyMesh::HalfEdge* nextOnBoundary(PolyMesh::HalfEdge* he) {
  do {
    he = he->next;
    if (he->opposite->f->data < 0) return he;
    he = he->opposite;
  } while(he != nullptr);
  Msg::Error("nextOnBoundary: turned too much, should not happen");
  return nullptr;
}

bool getBoundaryLoop(const PolyMesh* pm, 
    PolyMesh::HalfEdge* he0, 
    std::vector<PolyMesh::HalfEdge*>& loop) {

  loop.clear();
  PolyMesh::HalfEdge* he = he0;
  do {
    loop.push_back(he);
    he = nextOnBoundary(he);
    if (he == nullptr) {
      Msg::Error("getBoundaryLoop: no next on bdr, should not happen");
      return false;
    }
  } while (he != he0);

  return true;
}

void set_next_prev(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->next = b;
  b->prev = a;
}

void set_opposites(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->opposite = b;
  b->opposite = a;
}

bool quadFlipCut(PolyMesh* pm, PolyMesh::HalfEdge* he, int faceTag) {
  DBG("quadFlipCut <");
  //                           heCutBdr
  // hepp         henn        ──────►
  // ───►        ───►
  //      │     ▲        +    ◄──────
  //  hep │ [f] │              heCut
  //      ▼     │ hen 
  //       ────►               [f]
  //        he
  PolyMesh::HalfEdge* hep = he->prev;
  PolyMesh::HalfEdge* hepp = he->prev->prev;
  PolyMesh::HalfEdge* hen = he->next;
  PolyMesh::HalfEdge* henn = he->next->next;
  if (hep == nullptr || hepp == nullptr || hen == nullptr || henn == nullptr) {
    Msg::Error("quadFlipCut: input connectivity is wrong");
    return false;
  }
  /* Create two new halfedges */
  PolyMesh::HalfEdge* heCut = new PolyMesh::HalfEdge(hen->second());
  PolyMesh::HalfEdge* heCutBdr = new PolyMesh::HalfEdge(hep->first());
  pm->hedges.push_back(heCut);
  pm->hedges.push_back(heCutBdr);
  /* Change the connectivity */
  set_opposites(heCut,heCutBdr);
  set_next_prev(heCut,hep);
  set_next_prev(hen,heCut);
  set_next_prev(hepp,heCutBdr);
  set_next_prev(heCutBdr,henn);
  /* Create the quad */
  PolyMesh::Face* f = new PolyMesh::Face(he);
  f->data = faceTag;
  pm->faces.push_back(f);
  he->f = f;
  hep->f = f;
  hen->f = f;
  heCut->f = f;

  DBG(">");
  return true;
}

bool quadFlipMirrorLeft(PolyMesh* pm, PolyMesh::HalfEdge* he, int faceTag) {
  DBG("quadFlipMirrorLeft <");
  //                                h1b
  //                              ──────►
  // ─────►                         h1    (v)
  //       │                      ◄──────
  //    hep│  [f]           +             ▲ │
  //       ▼                       [f]    │ │ h0b
  //        ─────► ────►               h0 │ │
  //          he    hen                   │ ▼
  // 
  PolyMesh::HalfEdge* hep = he->prev;
  PolyMesh::HalfEdge* hepp = he->prev->prev;
  PolyMesh::HalfEdge* hen = he->next;
  if (hep == nullptr || hepp == nullptr || hen == nullptr) {
    Msg::Error("quadFlipMirrorLeft: input connectivity is wrong");
    return false;
  }
  /* Create new vertex */
  // SVector3 p = (hep->first()->position + he->second()->position)*0.5;
  // if (true) { // TODOMX
  //   SVector3 tg = he->d();
  //   double len = he->len();
  //   SVector3 N(0.,0.,1.);
  //   SVector3 dir = crossprod(tg,N);
  //   dir.normalize();
  //   const double factor = 0.1;
  //   p = he->second()->position + factor * len * dir;
  // }
  // PolyMesh::Vertex* v = new PolyMesh::Vertex(p.x(),p.y(),p.z());
  vec3 p = _opposite_right_angled_corner(hep->first()->position, hep->second()->position,he->second()->position);
  PolyMesh::Vertex* v = new PolyMesh::Vertex(p[0],p[1],p[2]);
  DBG("+v", p);
  pm->vertices.push_back(v);
  /* Create four new halfedges */
  PolyMesh::HalfEdge* h0 = new PolyMesh::HalfEdge(he->second());
  PolyMesh::HalfEdge* h0b = new PolyMesh::HalfEdge(v);
  set_opposites(h0,h0b);
  PolyMesh::HalfEdge* h1 = new PolyMesh::HalfEdge(v);
  PolyMesh::HalfEdge* h1b = new PolyMesh::HalfEdge(hep->first());
  set_opposites(h1,h1b);
  /* Change the connectivity */
  set_next_prev(h0,h1);
  set_next_prev(h1b,h0b);
  set_next_prev(hepp,h1b);
  set_next_prev(h0b,hen);
  set_next_prev(h1,hep);
  set_next_prev(he,h0);
  /* Create the quad */
  PolyMesh::Face* f = new PolyMesh::Face(he);
  f->data = faceTag;
  pm->faces.push_back(f);
  hep->f = f;
  he->f = f;
  h0->f = f;
  h1->f = f;

  DBG(">");
  return true;
}

bool quadFlipPush(PolyMesh* pm, PolyMesh::HalfEdge* he, int faceTag) {
  DBG("quadFlipPush <");
  //                                        h1b
  //                                      ─────►
  //                                 (v2)   h1  (v1)
  //                                      ◄────
  //  hep   he    hen       +        ▲  │       ▲ │
  // ────► ────► ────►           h2b │  │h2  h0 │ │h0b
  //                                 │  ▼       │ ▼
  // 
  PolyMesh::HalfEdge* hep = he->prev;
  PolyMesh::HalfEdge* hen = he->next;
  if (hep == nullptr || hen == nullptr) {
    Msg::Error("quadFlipPush: input connectivity is wrong");
    return false;
  }
  /* Create two new vertices */
  SVector3 avgTg1 = (he->d() + hen->d());
  SVector3 avgTg2 = (hep->d() + he->d());
  double len1 = 0.5*(he->len()+hen->len());
  double len2 = 0.5*(hep->len()+he->len());
  if (false) { // TODOMX test simpler tg
    avgTg1 = he->d();
    avgTg2 = he->d();
    len1 = he->len();
    len2 = he->len();
  }
  SVector3 N(0.,0.,1.);
  SVector3 dir1 = crossprod(avgTg1,N);
  SVector3 dir2 = crossprod(avgTg2,N);
  dir1.normalize();
  dir2.normalize();
  const double factor = 0.1;
  SVector3 p1 = he->second()->position + factor * len1 * dir1;
  SVector3 p2 = hep->second()->position + factor * len2 * dir2;

  PolyMesh::Vertex* v1 = new PolyMesh::Vertex(p1.x(),p1.y(),p1.z());
  PolyMesh::Vertex* v2 = new PolyMesh::Vertex(p2.x(),p2.y(),p2.z());
  pm->vertices.push_back(v1);
  pm->vertices.push_back(v2);
  /* Create fix new halfedges */
  PolyMesh::HalfEdge* h0 = new PolyMesh::HalfEdge(he->second());
  PolyMesh::HalfEdge* h0b = new PolyMesh::HalfEdge(v1);
  set_opposites(h0,h0b);
  PolyMesh::HalfEdge* h1 = new PolyMesh::HalfEdge(v1);
  PolyMesh::HalfEdge* h1b = new PolyMesh::HalfEdge(v2);
  set_opposites(h1,h1b);
  PolyMesh::HalfEdge* h2 = new PolyMesh::HalfEdge(v2);
  PolyMesh::HalfEdge* h2b = new PolyMesh::HalfEdge(he->first());
  set_opposites(h2,h2b);
  /* Change the connectivity */
  set_next_prev(he,h0);
  set_next_prev(h0,h1);
  set_next_prev(h1,h2);
  set_next_prev(h2,he);
  set_next_prev(hep,h2b);
  set_next_prev(h2b,h1b);
  set_next_prev(h1b,h0b);
  set_next_prev(h0b,hen);
  /* Create the quad */
  PolyMesh::Face* f = new PolyMesh::Face(he);
  f->data = faceTag;
  pm->faces.push_back(f);
  he->f = f;
  h0->f = f;
  h1->f = f;
  h2->f = f;

  DBG(">");
  return true;
}

struct QuadLayer {
  /* New components to add in the empty mesh */
  std::vector<PolyMesh::Vertex*> vertices;
  std::vector<std::array<PolyMesh::Vertex*,2> > edges;
  std::vector<std::array<PolyMesh::Vertex*,4> > quads;
};

int generateQuadLayer(
    const PolyMesh* pm,
    const std::vector<PolyMesh::HalfEdge*>& loop,
    QuadLayer& layer) {

  /* Create a copy of the loop, so the halfedges
   * can be modified without changing the initial
   * PolyMesh */
  std::vector<PolyMesh::HalfEdge*> cloop(loop.size(),nullptr);
  // std::unordered_map<PolyMesh::HalfEdge*,PolyMesh::HalfEdge*> old2new;
  for (size_t i = 0; i < loop.size(); ++i) {
    cloop[i] = new PolyMesh::HalfEdge(loop[i]->v);
    cloop[i]->data = loop[i]->data;
    // old2new[loop[i]] = cloop[i];
  }
  for (size_t i = 0; i < cloop.size(); ++i) {
    cloop[i]->next = cloop[(i+1)%cloop.size()];
    cloop[(i+1)%cloop.size()]->prev = cloop[i];
  }

  // TODOMX FROM HERE
  //
  //
  // .....
  //
  //
  //

  for (size_t i = 0; i < cloop.size(); ++i) {
    delete cloop[i];
  }
  return 0;
}

int generateBoundaryQuadLayers(
    const PolyMesh* pm,
    std::vector<QuadLayer>& layers) {
  Msg::Info("generate quad layer on boundary ...");

  /* Compute angle at each boundary vertex */
  std::unordered_map<PolyMesh::Vertex*,double> bdrAngle;
  for (PolyMesh::HalfEdge* he0: pm->hedges) if (he0 != nullptr) {
    PolyMesh::HalfEdge* he0op = he0->opposite;
    if (he0op == nullptr) continue; /* on border of bounding box, not face bdr */
    if (he0->f->data > 0 && he0op->f->data < 0) {
      bdrAngle[he0->v] = boundaryAngleAtOrigin(pm,he0);
    }
  }

  /* Extract the boundary loops */
  std::unordered_set<PolyMesh::HalfEdge*> visited;
  std::vector<std::vector<PolyMesh::HalfEdge*> > loops;
  for (PolyMesh::HalfEdge* he0: pm->hedges) {
    PolyMesh::HalfEdge* he0op = he0->opposite;
    if (he0op == nullptr) continue; /* on border of bounding box, not face bdr */
    if (he0->f->data > 0 && he0op->f->data < 0) {
      if (visited.find(he0) != visited.end()) continue;
      std::vector<PolyMesh::HalfEdge*> loop;
      bool ok = getBoundaryLoop(pm,he0,loop);
      if (!ok) {
        Msg::Error("insertBoundaryQuadLayer: failed to get boundary loop");
        return -1;
      }
      for (PolyMesh::HalfEdge* he: loop) visited.insert(he);
      if (loop.size() > 0) loops.push_back(loop);
    }
  }

  return 0;
}

int insertBoundaryQuadLayer(PolyMesh* pm) {
  Msg::Info("insert quad layer on boundary ...");
  DBG(pm->vertices.size(),pm->hedges.size(),pm->faces.size());

  show_polymesh(pm, "pm_in");

  /* Compute angle at each boundary vertex */
  std::unordered_map<PolyMesh::Vertex*,double> bdrAngle;
  for (PolyMesh::HalfEdge* he0: pm->hedges) if (he0 != nullptr) {
    PolyMesh::HalfEdge* he0op = he0->opposite;
    if (he0op == nullptr) continue; /* on border of bounding box, not face bdr */
    if (he0->f->data > 0 && he0op->f->data < 0) {
      bdrAngle[he0->v] = boundaryAngleAtOrigin(pm,he0);
    }
  }
  for (auto& kv: bdrAngle) {
    GeoLog::add(kv.first->position,double(kv.second),"bdr_angle");
  }


  /* Extract the boundary loops */
  std::unordered_set<PolyMesh::HalfEdge*> visited;
  std::vector<std::vector<PolyMesh::HalfEdge*> > loops;
  for (PolyMesh::HalfEdge* he0: pm->hedges) {
    PolyMesh::HalfEdge* he0op = he0->opposite;
    if (he0op == nullptr) continue; /* on border of bounding box, not face bdr */
    if (he0->f->data > 0 && he0op->f->data < 0) {
      if (visited.find(he0) != visited.end()) continue;
      std::vector<PolyMesh::HalfEdge*> loop;
      bool ok = getBoundaryLoop(pm,he0,loop);
      if (!ok) {
        Msg::Error("insertBoundaryQuadLayer: failed to get boundary loop");
        return -1;
      }
      for (PolyMesh::HalfEdge* he: loop) visited.insert(he);
      if (loop.size() > 0) loops.push_back(loop);
    }
  }

  /* Remove interior components in the mesh */
  /* - remove the interior halfedges */
  for (size_t i = 0; i < pm->hedges.size(); ++i) {
    PolyMesh::HalfEdge* he = pm->hedges[i];
    bool onBdr = visited.find(he) != visited.end();
    if (!onBdr) {
      if (he->f->data > 0) {
        delete he;
        pm->hedges[i] = nullptr;
      }
    }
  }

  /* - remove the face-interior triangles */
  int faceTag = 0;
  for (size_t i = 0; i < pm->faces.size(); ++i) {
    if (pm->faces[i]->data > 0) {
      if (faceTag == 0) faceTag = pm->faces[i]->data;
      delete pm->faces[i];
      pm->faces[i] = nullptr;
    }
  }
  /* - flag vertices on boundary */
  std::unordered_map<PolyMesh::Vertex*,PolyMesh::HalfEdge*> vToBdrEdge;
  for (PolyMesh::HalfEdge* he: pm->hedges) if (he) {
    vToBdrEdge[he->v] = he;
  }
  /* - remove the interior vertices */
  for (size_t i = 0; i < pm->vertices.size(); ++i) {
    PolyMesh::Vertex* v = pm->vertices[i];
    auto it = vToBdrEdge.find(v);
    if (it == vToBdrEdge.end()) {
      delete v;
      pm->vertices[i] = nullptr;
    } else {
      v->he = it->second;
    }
  }
  pm->clean(); /* remove the nullptr values from the PolyMesh */

  /* - update the halfedges on face bdr loops */
  for (size_t i = 0; i < loops.size(); ++i) {
    for (size_t j = 0; j < loops[i].size(); ++j) {
      size_t jNext = (j+1)%loops[i].size();
      loops[i][j]->next = loops[i][jNext];
      loops[i][jNext]->prev = loops[i][j];
      loops[i][j]->f = nullptr; /* interior face have been deleted */
    }
  }

  show_polymesh(pm, "pm_inter");

  std::unordered_map<PolyMesh::Vertex*,int> ideal;
  for (auto& kv: bdrAngle) {
    int v = 0;
    if (kv.second < 0.75*M_PI) {
      v = 1;
    } else if (kv.second < 1.25*M_PI) {
      v = 2;
    } else if (kv.second < 1.75*M_PI) {
      v = 3;
    } else {
      v = 4;
    }
    ideal[kv.first] = v;
  }

  /* Flip all boundary edges to make a layer of quads */
  for (size_t i = 0; i < loops.size(); ++i) {
    for (PolyMesh::HalfEdge* he: loops[i]) {
      show_halfedge(he, "loop"+std::to_string(i));
    }
    // launch_gmsh();

    PolyMesh::HalfEdge* he0 = loops[i][0];
    DBG(i, loops[i].size(),he0);

    size_t nflip = 0;
    PolyMesh::HalfEdge* he = he0;
    bool remaining = true;
    while (remaining) {
      remaining = false;
      /* Try flips in strict order */
      const int PASS_CUT = 0;
      const int PASS_MIRROR = 1;
      const int PASS_PUSH = 2;
      for (int pass = PASS_CUT; pass <= PASS_PUSH; pass++) {
        do { /* Loop on the boundary loop */
          // bool onBdr = visited.find(he) != visited.end();
          // if (!onBdr) {
          //   he = he->next;
          //   continue;
          // }
          PolyMesh::Vertex* v0 = he->first();
          PolyMesh::Vertex* v1 = he->second();
          bool touchBdr = vToBdrEdge.find(v0) != vToBdrEdge.end()
              || vToBdrEdge.find(v1) != vToBdrEdge.end();
          if (!touchBdr) {
            he = he->next;
            continue;
          }

          auto it0 = ideal.find(v0);
          auto it1 = ideal.find(v1);
          if (it0 == ideal.end() || it1 == ideal.end()) {
            Msg::Error("he %p, vertex not found in ideal, v0 %p, v1 %p", he, v0, v1);
            GeoLog::add(v0->position,0.,"not_found");
            GeoLog::add(v1->position,0.,"not_found");
            launch_gmsh();
            abort();
          }
          DBG(i, pass,he,it0->second,it1->second);
          if (pass == PASS_CUT && it0->second == 1 && it1->second == 1) { /* Do a cut flip */
            bool okf = quadFlipCut(pm,he,faceTag);
            if (!okf) {
              Msg::Error("failed to apply quadFlipCut");
              return -1;
            }
            /* Update the ideal valences */
            it0->second -= 1;
            it1->second -= 1;
            auto it2 = ideal.find(he->next->second());
            if (it2 != ideal.end()) it2->second -= 1;
            auto it3 = ideal.find(he->prev->first());
            if (it3 != ideal.end()) it3->second -= 1;
            /* Update the loop start by a HalfEdge that
             * is on the boundary loop for sure */
            he0 = he->next->next->opposite;
            he = he0;
            nflip += 1;
            show_polymesh(pm, "pm_a_flipcut");
            for (PolyMesh::Vertex* v: pm->vertices) if (v) {
              auto itt = ideal.find(v);
              if (itt != ideal.end()) {
                GeoLog::add(v->position, itt->second, "ideal");
              }
            }
            GeoLog::flush();
            remaining = true;
          } else if (pass == PASS_MIRROR && it0->second == 1 && it1->second >= 2) {
            show_halfedge(he,"he_flip");
            GeoLog::flush();
            bool okf = quadFlipMirrorLeft(pm,he,faceTag);
            if (!okf) {
              Msg::Error("failed to apply quadFlipMirrorLeft");
              return -1;
            }
            /* Update the ideal valences */
            it0->second -= 1;
            it1->second -= 1;
            auto it2 = ideal.find(he->prev->first());
            if (it2 != ideal.end()) it2->second -= 1;
            /* One vertex added */
            ideal[pm->vertices[pm->vertices.size()-1]] = 3;

            /* Update the loop start by a HalfEdge that
             * is on the boundary loop for sure */
            he0 = he->next->opposite;
            he = he0;
            nflip += 1;
            show_polymesh(pm, "pm_a_flipmirror");
            for (PolyMesh::Vertex* v: pm->vertices) if (v) {
              auto itt = ideal.find(v);
              if (itt != ideal.end()) {
                GeoLog::add(v->position, itt->second, "ideal");
              }
            }
            GeoLog::flush();
            show_halfedge(he0,"new_he0");
            GeoLog::flush();
            remaining = true;
          } else if (pass == PASS_PUSH && it0->second >= 2 && it1->second >= 2) {
            bool okf = quadFlipPush(pm,he,faceTag);
            if (!okf) {
              Msg::Error("failed to apply quadFlipPush");
              return -1;
            }
            /* Two vertices added */
            ideal[pm->vertices[pm->vertices.size()-2]] = 3;
            ideal[pm->vertices[pm->vertices.size()-1]] = 3;
            /* Update the ideal valences */
            it0->second -= 1;
            it1->second -= 1;
            /* Update the loop start by a HalfEdge that
             * is on the boundary loop for sure */
            he0 = he->next->opposite;
            he = he0;
            nflip += 1;
            show_polymesh(pm, "pm_a_flippush");
            for (PolyMesh::Vertex* v: pm->vertices) if (v) {
              auto itt = ideal.find(v);
              if (itt != ideal.end()) {
                GeoLog::add(v->position, itt->second, "ideal");
              }
            }
            GeoLog::flush();
            remaining = true;
          }

          // if (nflip > 3) {
          //   launch_gmsh();
          // }
          he = he->next;

          if (remaining) {
            DBG("restart");
            break;
          }

          // show_halfedge(he,"he");
          // GeoLog::flush();
        } while (he != he0);

        if (remaining) break; /* break flip type loop */
      }
    } /* end of flip loop */
    // Msg::Error("early stop");
    // break;
  }

  show_polymesh(pm, "pm_out");
  launch_gmsh();

  return 0;
}


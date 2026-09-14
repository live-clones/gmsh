// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "highOrderBoundaryLayerUntangler.h"

#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "GRegion.h"
#include "GVertex.h"
#include "MElement.h"
#include "AnalyseMeshQuality.h"
#include "MHexahedron.h"
#include "MLine.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "bezierBasis.h"
#include "fullMatrix.h"
#include "qualityMeasuresJacobian.h"
#include "winslowUntanglerGMSH.h"

#include <array>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace {
  typedef std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> EdgeVertices;
  typedef std::map<MFace, std::vector<MVertex *>, MFaceLessThan> FaceVertices;

  enum class HighOrderEdgeKind { Curve, Face, Volume };

  struct EdgeTask {
    MEdge edge;
    MElement *element = nullptr;
    GEntity *entity = nullptr;
    HighOrderEdgeKind kind = HighOrderEdgeKind::Volume;
  };

  struct VertexSpec {
    HighOrderEdgeKind kind = HighOrderEdgeKind::Volume;
    GEntity *entity = nullptr;
    double x = 0., y = 0., z = 0.;
    double u = 0., v = 0.;
    std::size_t num = 0;
  };

  struct FaceTask {
    MFace face;
    MElement *element = nullptr;
    GEntity *entity = nullptr;
    HighOrderEdgeKind kind = HighOrderEdgeKind::Volume;
  };

  struct BezierPatchElement {
    MElement *element = nullptr;
    bool isTriangle = false;
    std::array<uint32_t, 9> bezierPoints = {};
  };

  // MPrism18 ordering: 0..5 are the prism vertices, 6..14 are the edge
  // vertices, and 15..17 are the quadrangular face vertices. The latter are
  // needed as midpoints of the face diagonals in the P2 tetrahedra.
  static const int prismP2ToTetP2[6][10] = {
    {1, 0, 2, 3, 6, 7, 9, 15, 16, 8},
    {1, 0, 2, 4, 6, 7, 9, 10, 17, 15},
    {1, 0, 2, 5, 6, 7, 9, 17, 11, 16},
    {3, 4, 5, 0, 12, 14, 13, 8, 16, 15},
    {3, 4, 5, 1, 12, 14, 13, 15, 17, 10},
    {3, 4, 5, 2, 12, 14, 13, 16, 11, 17}};

  // MTetrahedron10 ordering: 0..3 are the vertices, then edge vertices
  // (0,1), (1,2), (2,0), (3,0), (3,2), (3,1). We keep the four corner
  // tetrahedra and split the central prism with the same double covering.
  static const int tetP2ToTetP1[10][4] = {
    {0, 4, 6, 7}, {1, 5, 4, 9}, {2, 6, 5, 8}, {3, 7, 8, 9},
    {4, 5, 6, 7}, {4, 5, 6, 9}, {4, 5, 6, 8}, {9, 7, 8, 4},
    {9, 7, 8, 5}, {9, 7, 8, 6}};

  // Tensor-product subdivision of the P2 prism: split the triangular P2
  // section into 4 P1 triangles and split the quadratic layer direction into
  // 2 P1 layers. Each of the 8 resulting linear prisms is represented by the
  // same 6-tet double covering as the linear prism.
  static const int prismP2TensorPrisms[8][6] = {
    {0, 6, 7, 8, 15, 16},    {6, 1, 9, 15, 10, 17},
    {7, 9, 2, 16, 17, 11},   {6, 9, 7, 15, 17, 16},
    {8, 15, 16, 3, 12, 13},  {15, 10, 17, 12, 4, 14},
    {16, 17, 11, 13, 14, 5}, {15, 17, 16, 12, 14, 13}};

  static const int prismP1DoubleCoveringTets[6][4] = {
    {1, 0, 2, 3}, {1, 0, 2, 4}, {1, 0, 2, 5},
    {3, 4, 5, 0}, {3, 4, 5, 1}, {3, 4, 5, 2}};

  // Tensor-product subdivision of the P2 hexahedron: split each reference
  // direction at its middle node, then split each of the 8 linear hexes into
  // the same 6 tetrahedra used by the linear boundary-layer untangler.
  static const int hexP2TensorHexes[8][8] = {
    {0, 8, 20, 9, 10, 21, 26, 22},
    {8, 1, 11, 20, 21, 12, 23, 26},
    {20, 11, 2, 13, 26, 23, 14, 24},
    {9, 20, 13, 3, 22, 26, 24, 15},
    {10, 21, 26, 22, 4, 16, 25, 17},
    {21, 12, 23, 26, 16, 5, 18, 25},
    {26, 23, 14, 24, 25, 18, 6, 19},
    {22, 26, 24, 15, 17, 25, 19, 7}};

  static const int hexP1Tets[6][4] = {
    {0, 1, 2, 6}, {0, 2, 3, 6}, {0, 3, 7, 6},
    {0, 7, 4, 6}, {0, 4, 5, 6}, {0, 5, 1, 6}};

  static void appendPrismP2DoubleCoveringTets(
    const std::array<uint32_t, 18> &prism,
    std::vector<std::array<uint32_t, 4> > &tets)
  {
    tets.reserve(tets.size() + 48);
    for(const auto &subPrism : prismP2TensorPrisms) {
      for(const auto &tet : prismP1DoubleCoveringTets) {
        tets.push_back({prism[subPrism[tet[0]]], prism[subPrism[tet[1]]],
                        prism[subPrism[tet[2]]], prism[subPrism[tet[3]]]});
      }
    }
  }

  static void validateP2PrismSubdivisionTables()
  {
    static bool done = false;
    if(done) return;
    done = true;

    std::array<uint32_t, 18> prism;
    for(uint32_t i = 0; i < prism.size(); ++i) prism[i] = i;

    std::vector<std::array<uint32_t, 4> > tets;
    appendPrismP2DoubleCoveringTets(prism, tets);
    if(tets.size() != 48)
      Msg::Warning("High-order boundary layer: invalid P2 prism subdivision "
                   "table (%zu tetrahedra instead of 48)",
                   tets.size());
  }

  static std::vector<GFace *> incidentFaces(GEntity *ge)
  {
    if(!ge) return {};
    if(ge->dim() == 2) return {static_cast<GFace *>(ge)};
    if(ge->dim() == 1) return static_cast<GEdge *>(ge)->faces();
    if(ge->dim() == 0) return static_cast<GVertex *>(ge)->faces();
    return {};
  }

  static GFace *commonFace(MVertex *v0, MVertex *v1)
  {
    std::vector<GFace *> f0 = incidentFaces(v0->onWhat());
    std::vector<GFace *> f1 = incidentFaces(v1->onWhat());
    for(auto gf0 : f0)
      for(auto gf1 : f1)
        if(gf0 == gf1) return gf0;
    return nullptr;
  }

  static GFace *commonFace(const MFace &mf)
  {
    if(mf.getNumVertices() < 2) return nullptr;
    GFace *gf = commonFace(mf.getVertex(0), mf.getVertex(1));
    if(!gf) return nullptr;
    for(std::size_t i = 2; i < mf.getNumVertices(); ++i) {
      std::vector<GFace *> faces = incidentFaces(mf.getVertex(i)->onWhat());
      bool found = false;
      for(auto f : faces) {
        if(f == gf) {
          found = true;
          break;
        }
      }
      if(!found) return nullptr;
    }
    return gf;
  }

  static double curveParamAtRelativeArcLength(GEdge *ge, double u0, double u1,
                                              double t)
  {
    if(!(t > 0. && t < 1.)) return (1. - t) * u0 + t * u1;

    const double total = std::abs(ge->length(u0, u1));
    if(!(total > 0.)) return (1. - t) * u0 + t * u1;

    double lo = 0., hi = 1.;
    for(int i = 0; i < 32; ++i) {
      const double mid = 0.5 * (lo + hi);
      const double u = (1. - mid) * u0 + mid * u1;
      const double l = std::abs(ge->length(u0, u));
      if(l < t * total)
        lo = mid;
      else
        hi = mid;
    }
    const double s = 0.5 * (lo + hi);
    return (1. - s) * u0 + s * u1;
  }

  static VertexSpec curveVertexSpec(const MEdge &me, GEdge *ge, double t)
  {
    VertexSpec spec;
    spec.kind = HighOrderEdgeKind::Curve;
    spec.entity = ge;

    MVertex *v0 = me.getVertex(0);
    MVertex *v1 = me.getVertex(1);
    double u0 = 0., u1 = 0.;
    if(!reparamMeshVertexOnEdge(v0, ge, u0) ||
       !reparamMeshVertexOnEdge(v1, ge, u1)) {
      SPoint3 p = me.interpolate(t);
      spec.x = p.x();
      spec.y = p.y();
      spec.z = p.z();
      spec.u = 0.;
      return spec;
    }

    const double u = curveParamAtRelativeArcLength(ge, u0, u1, t);
    GPoint gp = ge->point(u);
    spec.x = gp.x();
    spec.y = gp.y();
    spec.z = gp.z();
    spec.u = u;
    return spec;
  }

  static VertexSpec faceVertexSpec(const MEdge &me, GFace *gf, double t)
  {
    VertexSpec spec;
    spec.kind = HighOrderEdgeKind::Face;
    spec.entity = gf;

    MVertex *v0 = me.getVertex(0);
    MVertex *v1 = me.getVertex(1);
    SPoint3 p((1. - t) * v0->x() + t * v1->x(),
              (1. - t) * v0->y() + t * v1->y(),
              (1. - t) * v0->z() + t * v1->z());
    double guess[2] = {0., 0.};
    GPoint gp = gf->closestPoint(p, guess);
    spec.x = gp.x();
    spec.y = gp.y();
    spec.z = gp.z();
    spec.u = gp.u();
    spec.v = gp.v();
    return spec;
  }

  static VertexSpec volumeVertexSpec(const MEdge &me, GRegion *gr, double t)
  {
    VertexSpec spec;
    spec.kind = HighOrderEdgeKind::Volume;
    spec.entity = gr;

    SPoint3 p = me.interpolate(t);
    spec.x = p.x();
    spec.y = p.y();
    spec.z = p.z();
    return spec;
  }

  static void addEdgeTask(const MEdge &me, MElement *e, GEntity *entity,
                          HighOrderEdgeKind kind,
                          std::map<MEdge, std::size_t, MEdgeLessThan> &edgeMap,
                          std::vector<EdgeTask> &tasks)
  {
    if(edgeMap.find(me) != edgeMap.end()) return;
    EdgeTask task;
    task.edge = me;
    task.element = e;
    task.entity = entity;
    task.kind = kind;
    edgeMap[me] = tasks.size();
    tasks.push_back(task);
  }

  static void addFaceTask(const MFace &mf, MElement *e, GEntity *entity,
                          HighOrderEdgeKind kind,
                          std::map<MFace, std::size_t, MFaceLessThan> &faceMap,
                          std::vector<FaceTask> &tasks)
  {
    if(mf.getNumVertices() != 4) return;
    if(faceMap.find(mf) != faceMap.end()) return;
    if(!entity) kind = HighOrderEdgeKind::Volume;
    FaceTask task;
    task.face = mf;
    task.element = e;
    task.entity = entity;
    task.kind = kind;
    faceMap[mf] = tasks.size();
    tasks.push_back(task);
  }

  static std::vector<VertexSpec> computeEdgeVertexSpecs(const EdgeTask &task,
                                                        int order)
  {
    std::vector<VertexSpec> vertices;
    vertices.reserve(order - 1);

    for(int i = 1; i < order; ++i) {
      const double t = (double)i / (double)order;
      if(task.kind == HighOrderEdgeKind::Curve) {
        vertices.push_back(
          curveVertexSpec(task.edge, static_cast<GEdge *>(task.entity), t));
      }
      else if(task.kind == HighOrderEdgeKind::Face) {
        vertices.push_back(
          faceVertexSpec(task.edge, static_cast<GFace *>(task.entity), t));
      }
      else {
        vertices.push_back(
          volumeVertexSpec(task.edge, static_cast<GRegion *>(task.entity), t));
      }
    }

    return vertices;
  }

  static MVertex *createVertex(const VertexSpec &spec)
  {
    MVertex *v = nullptr;
    if(spec.kind == HighOrderEdgeKind::Curve) {
      v = new MEdgeVertex(spec.x, spec.y, spec.z, spec.entity, spec.u,
                          spec.num);
    }
    else if(spec.kind == HighOrderEdgeKind::Face) {
      v = new MFaceVertex(spec.x, spec.y, spec.z, spec.entity, spec.u, spec.v,
                          spec.num);
    }
    else {
      v = new MVertex(spec.x, spec.y, spec.z, spec.entity, spec.num);
    }
    v->setPolynomialOrder(2);
    return v;
  }

  static VertexSpec computeFaceVertexSpec(const FaceTask &task)
  {
    VertexSpec spec;
    spec.kind = task.kind;
    spec.entity = task.entity;

    SPoint3 p = task.face.barycenter();
    if(task.kind == HighOrderEdgeKind::Face && task.entity) {
      GFace *gf = static_cast<GFace *>(task.entity);
      SPoint2 uv = gf->parFromPoint(p);
      double guess[2] = {uv.x(), uv.y()};
      GPoint gp = gf->closestPoint(p, guess);
      spec.x = gp.x();
      spec.y = gp.y();
      spec.z = gp.z();
      spec.u = gp.u();
      spec.v = gp.v();
    }
    else {
      spec.x = p.x();
      spec.y = p.y();
      spec.z = p.z();
    }

    return spec;
  }

  static void storeVertex(MVertex *v)
  {
    if(v && v->onWhat()) v->onWhat()->mesh_vertices.push_back(v);
  }

  static bool getEdgeVertices(const EdgeVertices &edgeVertices, const MEdge &e,
                              std::vector<MVertex *> &v)
  {
    auto it = edgeVertices.find(e);
    if(it == edgeVertices.end()) return false;

    v = it->second;
    if(e.getVertex(0) != it->first.getVertex(0)) std::reverse(v.begin(), v.end());
    return true;
  }

  static MVertex *getP2EdgeVertex(const EdgeVertices &edgeVertices,
                                  const MEdge &e)
  {
    std::vector<MVertex *> v;
    if(!getEdgeVertices(edgeVertices, e, v) || v.empty()) return nullptr;
    return v[0];
  }

  static MVertex *getP2FaceVertex(const FaceVertices &faceVertices,
                                  const MFace &f)
  {
    auto it = faceVertices.find(f);
    if(it == faceVertices.end() || it->second.empty()) return nullptr;
    return it->second[0];
  }

  static void setHighOrderLinesP2(GModel *m, const EdgeVertices &edgeVertices)
  {
    std::size_t numLines = 0, numMissing = 0;

    for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) {
      GEdge *ge = *it;
      std::vector<MLine *> lines2;
      lines2.reserve(ge->lines.size());
      for(auto l : ge->lines) {
        if(l->getTypeForMSH() != MSH_LIN_2) {
          lines2.push_back(l);
          continue;
        }

        MVertex *v2 = getP2EdgeVertex(edgeVertices, l->getEdge(0));
        if(v2) {
          MLine *lNew =
            new MLine3(l->getVertex(0), l->getVertex(1), v2, 0,
                       l->getPartition());
          lines2.push_back(lNew);
          delete l;
          numLines++;
        }
        else {
          lines2.push_back(l);
          numMissing++;
        }
      }
      ge->lines = lines2;
      ge->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: converted %zu lines to P2 MLine3 "
              "(%zu lines missing high-order nodes)",
              numLines, numMissing);
  }

  static void setHighOrderFacesP2(
    GModel *m, const EdgeVertices &edgeVertices,
    const FaceVertices &faceVertices,
    const std::set<MElement *, MElementPtrLessThan> &toProcess,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2,
    std::map<MElement *, double> *layers)
  {
    std::size_t numTriangles = 0, numQuadrangles = 0, numMissing = 0;
    const std::set<MElement *> toProcessByAddress(toProcess.begin(),
                                                  toProcess.end());

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;

      std::vector<MTriangle *> triangles2;
      triangles2.reserve(gf->triangles.size());
      for(auto t : gf->triangles) {
        MVertex *v3 = getP2EdgeVertex(edgeVertices, t->getEdge(0));
        MVertex *v4 = getP2EdgeVertex(edgeVertices, t->getEdge(1));
        MVertex *v5 = getP2EdgeVertex(edgeVertices, t->getEdge(2));
        if(v3 && v4 && v5) {
          MTriangle *tNew =
            new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                           v3, v4, v5, 0, t->getPartition());
          triangles2.push_back(tNew);
          if(toProcessByAddress.find(t) != toProcessByAddress.end())
            toProcessP2.insert(tNew);
          if(layers) {
            auto itLayer = layers->find(t);
            if(itLayer != layers->end()) {
              double w = itLayer->second;
              layers->erase(itLayer);
              (*layers)[tNew] = w;
            }
          }
          delete t;
          numTriangles++;
        }
        else {
          triangles2.push_back(t);
          numMissing++;
        }
      }
      gf->triangles = triangles2;

      std::vector<MQuadrangle *> quadrangles2;
      quadrangles2.reserve(gf->quadrangles.size());
      for(auto q : gf->quadrangles) {
        MVertex *v4 = getP2EdgeVertex(edgeVertices, q->getEdge(0));
        MVertex *v5 = getP2EdgeVertex(edgeVertices, q->getEdge(1));
        MVertex *v6 = getP2EdgeVertex(edgeVertices, q->getEdge(2));
        MVertex *v7 = getP2EdgeVertex(edgeVertices, q->getEdge(3));
        MVertex *v8 = getP2FaceVertex(faceVertices, q->getFace(0));
        if(v4 && v5 && v6 && v7 && v8) {
          MQuadrangle *qNew =
            new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                             q->getVertex(3), v4, v5, v6, v7, v8, 0,
                             q->getPartition());
          quadrangles2.push_back(qNew);
          if(toProcessByAddress.find(q) != toProcessByAddress.end())
            toProcessP2.insert(qNew);
          if(layers) {
            auto itLayer = layers->find(q);
            if(itLayer != layers->end()) {
              double w = itLayer->second;
              layers->erase(itLayer);
              (*layers)[qNew] = w;
            }
          }
          delete q;
          numQuadrangles++;
        }
        else {
          quadrangles2.push_back(q);
          numMissing++;
        }
      }
      gf->quadrangles = quadrangles2;
      gf->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: converted %zu triangles and %zu "
              "quadrangles to P2 (%zu elements missing high-order nodes)",
              numTriangles, numQuadrangles, numMissing);
  }

  static void setHighOrderTetrahedraP2(
    GModel *m, const EdgeVertices &edgeVertices,
    const std::set<MElement *, MElementPtrLessThan> &toProcess,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2,
    std::map<MElement *, double> *layers)
  {
    std::size_t numTetrahedra = 0, numMissing = 0;
    const std::set<MElement *> toProcessByAddress(toProcess.begin(),
                                                  toProcess.end());

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;

      std::vector<MTetrahedron *> tetrahedra2;
      tetrahedra2.reserve(gr->tetrahedra.size());
      for(auto t : gr->tetrahedra) {
        if(t->getTypeForMSH() != MSH_TET_4) {
          tetrahedra2.push_back(t);
          continue;
        }

        MVertex *edgeVerticesP2[6];
        bool ok = true;
        for(int i = 0; i < 6; ++i) {
          edgeVerticesP2[i] = getP2EdgeVertex(edgeVertices, t->getEdge(i));
          if(!edgeVerticesP2[i]) ok = false;
        }

        if(ok) {
          MTetrahedron *tNew = new MTetrahedron10(
            t->getVertex(0), t->getVertex(1), t->getVertex(2),
            t->getVertex(3), edgeVerticesP2[0], edgeVerticesP2[1],
            edgeVerticesP2[2], edgeVerticesP2[3], edgeVerticesP2[4],
            edgeVerticesP2[5], 0, t->getPartition());
          tetrahedra2.push_back(tNew);
          if(toProcessByAddress.find(t) != toProcessByAddress.end())
            toProcessP2.insert(tNew);
          if(layers) {
            auto itLayer = layers->find(t);
            if(itLayer != layers->end()) {
              double w = itLayer->second;
              layers->erase(itLayer);
              (*layers)[tNew] = w;
            }
          }
          delete t;
          numTetrahedra++;
        }
        else {
          tetrahedra2.push_back(t);
          numMissing++;
        }
      }
      gr->tetrahedra = tetrahedra2;
      gr->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: converted %zu tetrahedra to P2 "
              "MTetrahedron10 (%zu tetrahedra missing high-order nodes)",
              numTetrahedra, numMissing);
  }

  static void setHighOrderPrismsP2(
    GModel *m, const EdgeVertices &edgeVertices,
    const FaceVertices &faceVertices,
    const std::set<MElement *, MElementPtrLessThan> &toProcess,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2,
    std::map<MElement *, double> *layers)
  {
    std::size_t numPrisms = 0, numMissing = 0;
    const std::set<MElement *> toProcessByAddress(toProcess.begin(),
                                                  toProcess.end());

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;

      std::vector<MPrism *> prisms2;
      prisms2.reserve(gr->prisms.size());
      for(auto p : gr->prisms) {
        if(p->getTypeForMSH() != MSH_PRI_6) {
          prisms2.push_back(p);
          continue;
        }

        MVertex *edgeVerticesP2[9];
        bool ok = true;
        for(int i = 0; i < 9; ++i) {
          edgeVerticesP2[i] = getP2EdgeVertex(edgeVertices, p->getEdge(i));
          if(!edgeVerticesP2[i]) ok = false;
        }

        MVertex *faceVerticesP2[3];
        for(int i = 0; i < 3; ++i) {
          faceVerticesP2[i] = getP2FaceVertex(faceVertices, p->getFace(i + 2));
          if(!faceVerticesP2[i]) ok = false;
        }

        if(ok) {
          MPrism *pNew = new MPrism18(
            p->getVertex(0), p->getVertex(1), p->getVertex(2),
            p->getVertex(3), p->getVertex(4), p->getVertex(5),
            edgeVerticesP2[0], edgeVerticesP2[1], edgeVerticesP2[2],
            edgeVerticesP2[3], edgeVerticesP2[4], edgeVerticesP2[5],
            edgeVerticesP2[6], edgeVerticesP2[7], edgeVerticesP2[8],
            faceVerticesP2[0], faceVerticesP2[1], faceVerticesP2[2], 0,
            p->getPartition());
          prisms2.push_back(pNew);
          if(toProcessByAddress.find(p) != toProcessByAddress.end())
            toProcessP2.insert(pNew);
          if(layers) {
            auto itLayer = layers->find(p);
            if(itLayer != layers->end()) {
              double w = itLayer->second;
              layers->erase(itLayer);
              (*layers)[pNew] = w;
            }
          }
          delete p;
          numPrisms++;
        }
        else {
          prisms2.push_back(p);
          numMissing++;
        }
      }
      gr->prisms = prisms2;
      gr->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: converted %zu prisms to P2 "
              "MPrism18 (%zu prisms missing high-order nodes)",
              numPrisms, numMissing);
  }

  static void checkHighOrderBoundaryFaceSharingP2(GModel *m,
                                                  const char *stage)
  {
    std::map<MFace, std::vector<MVertex *>, MFaceLessThan> surfaceFaces;

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement *e = gf->getMeshElement(i);
        if(e->getPolynomialOrder() != 2) continue;
        std::vector<MVertex *> fv;
        e->getFaceVertices(0, fv);
        surfaceFaces[e->getFace(0)] = fv;
      }
    }

    std::size_t numMatched = 0, numBad = 0;
    std::size_t numTriMatched = 0, numQuadMatched = 0;
    std::size_t numTriBad = 0, numQuadBad = 0;
    std::size_t numFirstBadRegion = 0, numFirstBadFace = 0;
    MElement *firstBadElement = nullptr;
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(std::size_t iel = 0; iel < gr->getNumMeshElements(); ++iel) {
        MElement *e = gr->getMeshElement(iel);
        if(e->getPolynomialOrder() != 2) continue;
        for(int iFace = 0; iFace < e->getNumFaces(); ++iFace) {
          MFace mf = e->getFace(iFace);
          auto itFace = surfaceFaces.find(mf);
          if(itFace == surfaceFaces.end()) continue;

          std::vector<MVertex *> vf;
          e->getFaceVertices(iFace, vf);
          const std::vector<MVertex *> &sf = itFace->second;
          const std::size_t nCorner = mf.getNumVertices();
          bool ok = vf.size() == sf.size();
          if(ok) {
            std::set<MVertex *, MVertexPtrLessThan> surfaceHighOrder;
            for(std::size_t i = nCorner; i < sf.size(); ++i)
              surfaceHighOrder.insert(sf[i]);
            for(std::size_t i = nCorner; i < vf.size(); ++i) {
              if(surfaceHighOrder.find(vf[i]) == surfaceHighOrder.end()) {
                ok = false;
                break;
              }
            }
          }

          numMatched++;
          if(nCorner == 3)
            numTriMatched++;
          else if(nCorner == 4)
            numQuadMatched++;
          if(!ok) {
            if(!firstBadElement) {
              firstBadElement = e;
              numFirstBadRegion = gr->tag();
              numFirstBadFace = iFace;
            }
            numBad++;
            if(nCorner == 3)
              numTriBad++;
            else if(nCorner == 4)
              numQuadBad++;
          }
        }
      }
    }

    if(numBad) {
      Msg::Warning("High-order boundary layer (%s): %zu/%zu volume faces that "
                   "match model faces do not share the same P2 node pointers "
                   "(tri %zu/%zu, quad %zu/%zu; first: region %zu, element "
                   "%d, face %zu)",
                   stage, numBad, numMatched, numTriBad, numTriMatched,
                   numQuadBad, numQuadMatched, numFirstBadRegion,
                   firstBadElement ? firstBadElement->getNum() : 0,
                   numFirstBadFace);
    }
    else if(numMatched) {
      Msg::Info("High-order boundary layer (%s): checked %zu P2 volume/model "
                "face matches (%zu triangles, %zu quadrangles); all share "
                "high-order node pointers",
                stage, numMatched, numTriMatched, numQuadMatched);
    }
  }

  static void stitchHighOrderPrismNodes(GModel *m)
  {
    std::map<MEdge, MVertex *, MEdgeLessThan> edgeNodes;
    std::map<MFace, MVertex *, MFaceLessThan> faceNodes;
    std::size_t numEdgeFixes = 0, numFaceFixes = 0;

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto p : gr->prisms) {
        if(p->getTypeForMSH() != MSH_PRI_18) continue;

        for(int i = 0; i < 9; ++i) {
          MEdge edge = p->getEdge(i);
          auto itEdge = edgeNodes.find(edge);
          if(itEdge == edgeNodes.end())
            edgeNodes[edge] = p->getVertex(6 + i);
          else if(p->getVertex(6 + i) != itEdge->second) {
            p->setVertex(6 + i, itEdge->second);
            numEdgeFixes++;
          }
        }

        for(int i = 2; i < 5; ++i) {
          MFace face = p->getFace(i);
          auto itFace = faceNodes.find(face);
          const int centerIndex = 13 + i;
          if(itFace == faceNodes.end())
            faceNodes[face] = p->getVertex(centerIndex);
          else if(p->getVertex(centerIndex) != itFace->second) {
            p->setVertex(centerIndex, itFace->second);
            numFaceFixes++;
          }
        }
      }
      gr->deleteVertexArrays();
    }

    if(numEdgeFixes || numFaceFixes)
      Msg::Info("High-order boundary layer: stitched %zu prism edge nodes and "
                "%zu prism face nodes",
                numEdgeFixes, numFaceFixes);
  }

  static bool replaceVertexPointer(MElement *e, MVertex *oldv, MVertex *newv)
  {
    bool changed = false;
    for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
      if(e->getVertex(i) == oldv) {
        e->setVertex(i, newv);
        changed = true;
      }
    }
    return changed;
  }

  static void stitchHighOrderMeshNodes(GModel *m)
  {
    std::map<MEdge, MVertex *, MEdgeLessThan> edgeNodes;
    std::map<MFace, MVertex *, MFaceLessThan> faceNodes;
    std::size_t numEdgeFixes = 0, numFaceFixes = 0;

    auto stitchElement = [&](MElement *e) {
      if(e->getPolynomialOrder() < 2) return;

      for(int i = 0; i < e->getNumEdges(); ++i) {
        std::vector<MVertex *> ev;
        e->getEdgeVertices(i, ev);
        if(ev.size() != 3) continue;
        MEdge edge = e->getEdge(i);
        auto itEdge = edgeNodes.find(edge);
        if(itEdge == edgeNodes.end())
          edgeNodes[edge] = ev[2];
        else if(ev[2] != itEdge->second &&
                replaceVertexPointer(e, ev[2], itEdge->second)) {
          numEdgeFixes++;
        }
      }

      for(int i = 0; i < e->getNumFaces(); ++i) {
        std::vector<MVertex *> fv;
        e->getFaceVertices(i, fv);
        if(fv.size() != 9) continue;
        MFace face = e->getFace(i);
        auto itFace = faceNodes.find(face);
        if(itFace == faceNodes.end())
          faceNodes[face] = fv[8];
        else if(fv[8] != itFace->second &&
                replaceVertexPointer(e, fv[8], itFace->second)) {
          numFaceFixes++;
        }
      }
    };

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) stitchElement(e);
      for(auto e : gf->quadrangles) stitchElement(e);
      gf->deleteVertexArrays();
    }

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra) stitchElement(e);
      for(auto e : gr->hexahedra) stitchElement(e);
      for(auto e : gr->prisms) stitchElement(e);
      for(auto e : gr->pyramids) stitchElement(e);
      gr->deleteVertexArrays();
    }

    if(numEdgeFixes || numFaceFixes)
      Msg::Info("High-order boundary layer: stitched %zu global edge nodes "
                "and %zu global face nodes",
                numEdgeFixes, numFaceFixes);
  }

  static double highOrderMatchingTolerance(GModel *m)
  {
    double xmin = std::numeric_limits<double>::max();
    double ymin = std::numeric_limits<double>::max();
    double zmin = std::numeric_limits<double>::max();
    double xmax = -std::numeric_limits<double>::max();
    double ymax = -std::numeric_limits<double>::max();
    double zmax = -std::numeric_limits<double>::max();

    auto updateBounds = [&](MElement *e) {
      for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
        MVertex *v = e->getVertex(i);
        xmin = std::min(xmin, v->x());
        ymin = std::min(ymin, v->y());
        zmin = std::min(zmin, v->z());
        xmax = std::max(xmax, v->x());
        ymax = std::max(ymax, v->y());
        zmax = std::max(zmax, v->z());
      }
    };

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) updateBounds(e);
      for(auto e : gf->quadrangles) updateBounds(e);
    }
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra) updateBounds(e);
      for(auto e : gr->hexahedra) updateBounds(e);
      for(auto e : gr->prisms) updateBounds(e);
      for(auto e : gr->pyramids) updateBounds(e);
    }

    if(xmin == std::numeric_limits<double>::max()) return 1.e-12;

    const double dx = xmax - xmin, dy = ymax - ymin, dz = zmax - zmin;
    const double diag = std::sqrt(dx * dx + dy * dy + dz * dz);
    return std::max(1.e-12 * std::max(1., diag), 1.e-14);
  }

  struct PointKey {
    long long x = 0, y = 0, z = 0;
    bool operator<(const PointKey &other) const
    {
      if(x != other.x) return x < other.x;
      if(y != other.y) return y < other.y;
      return z < other.z;
    }
  };

  struct FacePointKey {
    std::vector<PointKey> points;
    bool operator<(const FacePointKey &other) const
    {
      return points < other.points;
    }
  };

  static PointKey pointKey(MVertex *v, double invTol)
  {
    return {llround(v->x() * invTol), llround(v->y() * invTol),
            llround(v->z() * invTol)};
  }

  static FacePointKey facePointKey(const std::vector<MVertex *> &v,
                                   std::size_t nCorner, double invTol)
  {
    FacePointKey key;
    key.points.reserve(nCorner);
    for(std::size_t i = 0; i < nCorner; ++i)
      key.points.push_back(pointKey(v[i], invTol));
    std::sort(key.points.begin(), key.points.end());
    return key;
  }

  static double squaredDistance(MVertex *a, MVertex *b)
  {
    const double dx = a->x() - b->x();
    const double dy = a->y() - b->y();
    const double dz = a->z() - b->z();
    return dx * dx + dy * dy + dz * dz;
  }

  static int findMatchingCorner(MVertex *v, const std::vector<MVertex *> &w,
                                std::size_t nCorner, double tol2,
                                const std::vector<bool> &used)
  {
    int best = -1;
    double bestDist = tol2;
    for(std::size_t i = 0; i < nCorner; ++i) {
      if(used[i]) continue;
      const double dist = squaredDistance(v, w[i]);
      if(dist <= bestDist) {
        best = (int)i;
        bestDist = dist;
      }
    }
    return best;
  }

  static int edgeMidpointIndex(std::size_t nCorner, int v0, int v1)
  {
    for(std::size_t i = 0; i < nCorner; ++i) {
      const int a = (int)i;
      const int b = (int)((i + 1) % nCorner);
      if((a == v0 && b == v1) || (a == v1 && b == v0))
        return (int)(nCorner + i);
    }
    return -1;
  }

  static void addReplacement(MVertex *oldv, MVertex *newv,
                             std::map<MVertex *, MVertex *,
                                      MVertexPtrLessThan> &replacements)
  {
    if(!oldv || !newv || oldv == newv) return;
    replacements[oldv] = newv;
    oldv->x() = newv->x();
    oldv->y() = newv->y();
    oldv->z() = newv->z();
  }

  static void applyVertexReplacements(
    GModel *m,
    const std::map<MVertex *, MVertex *, MVertexPtrLessThan> &replacements)
  {
    if(replacements.empty()) return;

    auto apply = [&](MElement *e) {
      for(std::size_t i = 0; i < e->getNumVertices(); ++i) {
        auto it = replacements.find(e->getVertex(i));
        if(it != replacements.end()) e->setVertex(i, it->second);
      }
    };

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) apply(e);
      for(auto e : gf->quadrangles) apply(e);
      gf->deleteVertexArrays();
    }
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra) apply(e);
      for(auto e : gr->hexahedra) apply(e);
      for(auto e : gr->prisms) apply(e);
      for(auto e : gr->pyramids) apply(e);
      gr->deleteVertexArrays();
    }
  }

  static void syncHighOrderRegionFacesWithBoundary(GModel *m)
  {
    if(!m) return;
    if(m->firstRegion() == m->lastRegion()) return;

    const double tol = highOrderMatchingTolerance(m);
    const double tol2 = tol * tol;
    const double invTol = 1. / tol;

    std::map<FacePointKey, std::vector<MVertex *> > boundaryFaces;

    auto addBoundaryElement = [&](GFace *gf, MElement *e) {
      if(e->getPolynomialOrder() < 2) return;
      const std::size_t nCorner = e->getNumPrimaryVertices();
      if(nCorner != 3 && nCorner != 4) return;
      std::vector<MVertex *> fv;
      e->getFaceVertices(0, fv);
      if(fv.size() < nCorner) return;
      boundaryFaces[facePointKey(fv, nCorner, invTol)] = fv;
    };

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) addBoundaryElement(gf, e);
      for(auto e : gf->quadrangles) addBoundaryElement(gf, e);
    }

    std::map<MVertex *, MVertex *, MVertexPtrLessThan> replacements;
    std::size_t numFacesMatched = 0, numVerticesReplaced = 0;
    std::size_t numGeometricMatches = 0, numMissed = 0;

    auto syncRegionFace = [&](MElement *e, int iFace) {
      MFace mf = e->getFace(iFace);
      GFace *gf = commonFace(mf);
      const bool classifiedOnBoundaryFace = gf != nullptr;

      const std::size_t nCorner = mf.getNumVertices();
      if(nCorner != 3 && nCorner != 4) return;

      std::vector<MVertex *> rf;
      e->getFaceVertices(iFace, rf);
      if(rf.size() != (nCorner == 3 ? 6 : 9)) return;

      auto itBoundary = boundaryFaces.find(facePointKey(rf, nCorner, invTol));
      if(itBoundary == boundaryFaces.end()) {
        if(classifiedOnBoundaryFace) numMissed++;
        return;
      }

      const std::vector<MVertex *> &bf = itBoundary->second;
      std::vector<int> cornerMap(nCorner, -1);
      std::vector<bool> used(nCorner, false);
      for(std::size_t i = 0; i < nCorner; ++i) {
        int j = findMatchingCorner(rf[i], bf, nCorner, tol2, used);
        if(j < 0) {
          numMissed++;
          return;
        }
        cornerMap[i] = j;
        used[j] = true;
      }

      numFacesMatched++;
      for(std::size_t i = 0; i < nCorner; ++i) {
        MVertex *oldv = rf[i], *newv = bf[cornerMap[i]];
        if(oldv != newv) {
          addReplacement(oldv, newv, replacements);
          numVerticesReplaced++;
        }
      }
      for(std::size_t i = 0; i < nCorner; ++i) {
        const int j = edgeMidpointIndex(
          nCorner, cornerMap[i], cornerMap[(i + 1) % nCorner]);
        if(j < 0) continue;
        MVertex *oldv = rf[nCorner + i], *newv = bf[j];
        if(oldv != newv) {
          addReplacement(oldv, newv, replacements);
          numVerticesReplaced++;
          numGeometricMatches++;
        }
      }
      if(nCorner == 4 && rf.size() == 9 && bf.size() == 9 && rf[8] != bf[8]) {
        addReplacement(rf[8], bf[8], replacements);
        numVerticesReplaced++;
        numGeometricMatches++;
      }
    };

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra)
        for(int i = 0; i < e->getNumFaces(); ++i) syncRegionFace(e, i);
      for(auto e : gr->hexahedra)
        for(int i = 0; i < e->getNumFaces(); ++i) syncRegionFace(e, i);
      for(auto e : gr->prisms)
        for(int i = 0; i < e->getNumFaces(); ++i) syncRegionFace(e, i);
      for(auto e : gr->pyramids)
        for(int i = 0; i < e->getNumFaces(); ++i) syncRegionFace(e, i);
    }

    applyVertexReplacements(m, replacements);

    if(numFacesMatched || numVerticesReplaced || numMissed)
      Msg::Info("High-order boundary layer: synchronized %zu region faces with "
                "boundary elements (%zu vertex pointer replacements, %zu P2 "
                "face/edge matches, %zu misses)",
                numFacesMatched, numVerticesReplaced, numGeometricMatches,
                numMissed);
  }

  static std::size_t collectHighOrderFaceNodes(
    GModel *m, std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    std::size_t count = 0;
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement *e = gf->getMeshElement(i);
        for(std::size_t j = e->getNumPrimaryVertices(); j < e->getNumVertices();
            ++j) {
          if(fixed.insert(e->getVertex(j)).second) count++;
        }
      }
    }
    return count;
  }

  static void addPatchVertex(
    GFace *gf, MVertex *v, bool lock,
    std::map<MVertex *, uint32_t, MVertexPtrLessThan> &indices,
    std::vector<std::array<double, 2> > &points, std::vector<bool> &locked)
  {
    auto it = indices.find(v);
    if(it != indices.end()) {
      if(lock) locked[it->second] = true;
      return;
    }

    SPoint2 p;
    if(!reparamMeshVertexOnFace(v, gf, p)) p = gf->parFromPoint(v->point());
    const uint32_t index = (uint32_t)points.size();
    indices[v] = index;
    points.push_back({p.x(), p.y()});
    locked.push_back(lock);
  }

  static uint32_t getPatchVertex(
    GFace *gf, MVertex *v, bool lock,
    std::map<MVertex *, uint32_t, MVertexPtrLessThan> &indices,
    std::vector<std::array<double, 2> > &points, std::vector<bool> &locked)
  {
    addPatchVertex(gf, v, lock, indices, points, locked);
    return indices[v];
  }

  static uint32_t addPatchPoint(const SPoint2 &p,
                                std::vector<std::array<double, 2> > &points,
                                std::vector<bool> &locked)
  {
    const uint32_t index = (uint32_t)points.size();
    points.push_back({p.x(), p.y()});
    locked.push_back(false);
    return index;
  }

  static uint32_t addBezierPatchPoint(
    GFace *gf, const bezierCoeff &bez, int i, MVertex *owner, bool lock,
    std::map<MVertex *, uint32_t, MVertexPtrLessThan> &indices,
    std::vector<std::array<double, 2> > &points, std::vector<bool> &locked)
  {
    if(owner) {
      auto it = indices.find(owner);
      if(it != indices.end()) {
        if(lock) locked[it->second] = true;
        return it->second;
      }
    }

    SPoint3 xyz(bez(i, 0), bez(i, 1), bez(i, 2));
    SPoint2 p = gf->parFromPoint(xyz);
    const uint32_t index = (uint32_t)points.size();
    points.push_back({p.x(), p.y()});
    locked.push_back(lock);
    if(owner) indices[owner] = index;
    return index;
  }

  static bool lockedBezierOwner(
    MVertex *v, const std::set<MVertex *, MVertexPtrLessThan> &boundary,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    return v && (boundary.find(v) != boundary.end() ||
                 fixed.find(v) != fixed.end());
  }

  static SPoint2 blend(const SPoint2 &a, double wa, const SPoint2 &b,
                       double wb)
  {
    return SPoint2(wa * a.x() + wb * b.x(), wa * a.y() + wb * b.y());
  }

  static SPoint2 blend(const SPoint2 &a, double wa, const SPoint2 &b,
                       double wb, const SPoint2 &c, double wc)
  {
    return SPoint2(wa * a.x() + wb * b.x() + wc * c.x(),
                   wa * a.y() + wb * b.y() + wc * c.y());
  }

  static SPoint2 point2(const std::vector<std::array<double, 2>> &points,
                        uint32_t i)
  {
    return SPoint2(points[i][0], points[i][1]);
  }

  static void setVertexOnFace(GFace *gf, MVertex *v, const SPoint2 &p)
  {
    GPoint gp = gf->point(p);
    v->x() = gp.x();
    v->y() = gp.y();
    v->z() = gp.z();
    v->setParameter(0, gp.u());
    v->setParameter(1, gp.v());
  }

  static void putLagrangeNodesAtBezierControlPoints(
    GFace *gf, const std::vector<BezierPatchElement> &patchElements,
    const std::vector<std::array<double, 2>> &points)
  {
    std::set<MVertex *, MVertexPtrLessThan> updated;

    for(const auto &pe : patchElements) {
      MElement *e = pe.element;
      if(!e) continue;
      const int n = pe.isTriangle ? 6 : 9;
      for(int i = 0; i < n; ++i) {
        MVertex *v = e->getVertex(i);
        if(updated.insert(v).second)
          setVertexOnFace(gf, v, point2(points, pe.bezierPoints[i]));
      }
    }
  }

  static void updateLagrangeNodesFromBezierP2(
    GFace *gf, const std::vector<BezierPatchElement> &patchElements,
    const std::vector<std::array<double, 2>> &points)
  {
    std::set<MVertex *, MVertexPtrLessThan> updated;

    for(const auto &pe : patchElements) {
      MElement *e = pe.element;
      if(!e) continue;
      if(pe.isTriangle) {
        const SPoint2 b0 = point2(points, pe.bezierPoints[0]);
        const SPoint2 b1 = point2(points, pe.bezierPoints[1]);
        const SPoint2 b2 = point2(points, pe.bezierPoints[2]);
        const SPoint2 b3 = point2(points, pe.bezierPoints[3]);
        const SPoint2 b4 = point2(points, pe.bezierPoints[4]);
        const SPoint2 b5 = point2(points, pe.bezierPoints[5]);
        const SPoint2 lag[6] = {
          b0,
          b1,
          b2,
          blend(b0, 0.25, b3, 0.5, b1, 0.25),
          blend(b1, 0.25, b4, 0.5, b2, 0.25),
          blend(b2, 0.25, b5, 0.5, b0, 0.25)};
        for(int i = 0; i < 6; ++i) {
          MVertex *v = e->getVertex(i);
          if(updated.insert(v).second) setVertexOnFace(gf, v, lag[i]);
        }
      }
      else {
        const SPoint2 b0 = point2(points, pe.bezierPoints[0]);
        const SPoint2 b1 = point2(points, pe.bezierPoints[1]);
        const SPoint2 b2 = point2(points, pe.bezierPoints[2]);
        const SPoint2 b3 = point2(points, pe.bezierPoints[3]);
        const SPoint2 b4 = point2(points, pe.bezierPoints[4]);
        const SPoint2 b5 = point2(points, pe.bezierPoints[5]);
        const SPoint2 b6 = point2(points, pe.bezierPoints[6]);
        const SPoint2 b7 = point2(points, pe.bezierPoints[7]);
        const SPoint2 b8 = point2(points, pe.bezierPoints[8]);
        const SPoint2 lag[9] = {
          b0,
          b1,
          b2,
          b3,
          blend(b0, 0.25, b4, 0.5, b1, 0.25),
          blend(b1, 0.25, b5, 0.5, b2, 0.25),
          blend(b2, 0.25, b6, 0.5, b3, 0.25),
          blend(b3, 0.25, b7, 0.5, b0, 0.25),
          SPoint2(0.0625 * (b0.x() + b1.x() + b2.x() + b3.x()) +
                    0.125 * (b4.x() + b5.x() + b6.x() + b7.x()) +
                    0.25 * b8.x(),
                  0.0625 * (b0.y() + b1.y() + b2.y() + b3.y()) +
                    0.125 * (b4.y() + b5.y() + b6.y() + b7.y()) +
                    0.25 * b8.y())};
        for(int i = 0; i < 9; ++i) {
          MVertex *v = e->getVertex(i);
          if(updated.insert(v).second) setVertexOnFace(gf, v, lag[i]);
        }
      }
    }
  }

  static MVertex *createProjectedFaceVertex(GFace *gf, const SPoint3 &p)
  {
    double guess[2] = {0., 0.};
    GPoint gp = gf->closestPoint(p, guess);
    MVertex *v = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
    v->setPolynomialOrder(2);
    gf->mesh_vertices.push_back(v);
    return v;
  }

  static MVertex *interpolateProjectedFaceVertex(GFace *gf, MVertex *v0,
                                                 MVertex *v1, double t)
  {
    SPoint3 p((1. - t) * v0->x() + t * v1->x(),
              (1. - t) * v0->y() + t * v1->y(),
              (1. - t) * v0->z() + t * v1->z());
    return createProjectedFaceVertex(gf, p);
  }

  static MVertex *mappedFaceVertex(GFace *gf, MElement *e, double u, double v)
  {
    SPoint3 p;
    e->pnt(u, v, 0., p);
    return createProjectedFaceVertex(gf, p);
  }

  static MVertex *createRegionVertex(GRegion *gr, const SPoint3 &p)
  {
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gr);
    v->setPolynomialOrder(2);
    gr->mesh_vertices.push_back(v);
    return v;
  }

  static MVertex *createMappedRegionVertex(GRegion *gr, MElement *e, double u,
                                           double v, double w)
  {
    SPoint3 p;
    e->pnt(u, v, w, p);
    return createRegionVertex(gr, p);
  }

  static void classifyHighOrderVertexOnFace(GFace *gf, MVertex *v)
  {
    if(!gf || !v) return;
    SPoint3 p = v->point();
    double guess[2] = {0., 0.};
    GPoint gp = gf->closestPoint(p, guess);
    v->x() = gp.x();
    v->y() = gp.y();
    v->z() = gp.z();
    v->setParameter(0, gp.u());
    v->setParameter(1, gp.v());
    if(v->onWhat() != gf) {
      v->setEntity(gf);
      gf->mesh_vertices.push_back(v);
    }
  }

  static void seedHighOrderNodeMaps(
    GModel *m, std::map<MEdge, MVertex *, MEdgeLessThan> &edgeNodes,
    std::map<MFace, MVertex *, MFaceLessThan> &faceNodes)
  {
    auto seedElement = [&](MElement *e) {
      for(int i = 0; i < e->getNumEdges(); ++i) {
        std::vector<MVertex *> ev;
        e->getEdgeVertices(i, ev);
        if(ev.size() == 3) edgeNodes.emplace(MEdge(ev[0], ev[1]), ev[2]);
      }
      for(int i = 0; i < e->getNumFaces(); ++i) {
        std::vector<MVertex *> fv;
        e->getFaceVertices(i, fv);
        if(fv.size() == 9)
          faceNodes.emplace(MFace(fv[0], fv[1], fv[2], fv[3]), fv[8]);
      }
    };

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) seedElement(e);
      for(auto e : gf->quadrangles) seedElement(e);
    }
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra) seedElement(e);
      for(auto e : gr->hexahedra) seedElement(e);
      for(auto e : gr->prisms) seedElement(e);
      for(auto e : gr->pyramids) seedElement(e);
    }
  }

  static MVertex *getOrCreateRegionEdgeNode(
    GRegion *gr, MElement *e, MVertex *v0, MVertex *v1, double u, double v,
    double w, std::map<MEdge, MVertex *, MEdgeLessThan> &edgeNodes)
  {
    MEdge edge(v0, v1);
    auto it = edgeNodes.find(edge);
    if(it != edgeNodes.end()) return it->second;
    MVertex *node = createMappedRegionVertex(gr, e, u, v, w);
    edgeNodes[edge] = node;
    return node;
  }

  static MVertex *getOrCreateRegionFaceNode(
    GRegion *gr, MElement *e, MVertex *v0, MVertex *v1, MVertex *v2,
    MVertex *v3, double u, double v, double w,
    std::map<MFace, MVertex *, MFaceLessThan> &faceNodes)
  {
    MFace face(v0, v1, v2, v3);
    auto it = faceNodes.find(face);
    if(it != faceNodes.end()) return it->second;
    SPoint3 p;
    e->pnt(u, v, w, p);
    GFace *gf = commonFace(face);
    MVertex *node = gf ? createProjectedFaceVertex(gf, p) :
                         createRegionVertex(gr, p);
    faceNodes[face] = node;
    return node;
  }

  static MVertex *getOrCreateFaceEdgeNode(
    GFace *gf, MVertex *v0, MVertex *v1,
    std::map<MEdge, MVertex *, MEdgeLessThan> &edgeNodes)
  {
    MEdge edge(v0, v1);
    auto it = edgeNodes.find(edge);
    if(it != edgeNodes.end()) {
      classifyHighOrderVertexOnFace(gf, it->second);
      return it->second;
    }
    SPoint3 p(0.5 * (v0->x() + v1->x()), 0.5 * (v0->y() + v1->y()),
              0.5 * (v0->z() + v1->z()));
    MVertex *node = createProjectedFaceVertex(gf, p);
    edgeNodes[edge] = node;
    return node;
  }

  static MVertex *getOrCreateFaceCenterNode(
    GFace *gf, MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
    std::map<MFace, MVertex *, MFaceLessThan> &faceNodes)
  {
    MFace face(v0, v1, v2, v3);
    auto it = faceNodes.find(face);
    if(it != faceNodes.end()) {
      classifyHighOrderVertexOnFace(gf, it->second);
      return it->second;
    }
    SPoint3 p(0.25 * (v0->x() + v1->x() + v2->x() + v3->x()),
              0.25 * (v0->y() + v1->y() + v2->y() + v3->y()),
              0.25 * (v0->z() + v1->z() + v2->z() + v3->z()));
    MVertex *node = createProjectedFaceVertex(gf, p);
    faceNodes[face] = node;
    return node;
  }

  static std::vector<MVertex *> getOrCreateSplitColumn(
    GRegion *gr, MElement *e, MVertex *v0, MVertex *v1, double u, double v,
    const std::vector<double> &levels,
    std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &splitColumns)
  {
    MEdge edge(v0, v1);
    auto it = splitColumns.find(edge);
    if(it != splitColumns.end()) {
      std::vector<MVertex *> column = it->second;
      if(!column.empty() && column.front() != v0 && column.back() == v0)
        std::reverse(column.begin(), column.end());
      return column;
    }

    std::vector<MVertex *> column(levels.size());
    column.front() = v0;
    column.back() = v1;
    for(std::size_t i = 1; i + 1 < levels.size(); ++i) {
      const double w = -1. + 2. * levels[i];
      column[i] = createMappedRegionVertex(gr, e, u, v, w);
    }
    splitColumns[edge] = column;
    return column;
  }

  static std::vector<MVertex *> getOrientedSplitColumn(
    const std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &splitColumns,
    const MEdge &edge)
  {
    auto it = splitColumns.find(edge);
    if(it == splitColumns.end()) return {};
    std::vector<MVertex *> column = it->second;
    if(!column.empty() && column.front() != edge.getVertex(0) &&
       column.back() == edge.getVertex(0))
      std::reverse(column.begin(), column.end());
    return column;
  }

  static void splitHighOrderBoundaryQuadsFromVolumeSplitsP2(
    GModel *m, std::map<MElement *, double> &layers,
    const std::vector<double> &widths,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2,
    const std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &splitColumns,
    std::map<MEdge, MVertex *, MEdgeLessThan> &edgeNodes,
    std::map<MFace, MVertex *, MFaceLessThan> &faceNodes)
  {
    std::size_t numSplit = 0, numCreated = 0;
    std::size_t numFromVolumeFaces = 0, numMissingVolumeFaces = 0;
    std::set<MVertex *, MVertexPtrLessThan> classified;
    std::map<MFace, std::vector<MVertex *>, MFaceLessThan> volumeQuadFaces;

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(std::size_t iel = 0; iel < gr->getNumMeshElements(); ++iel) {
        MElement *e = gr->getMeshElement(iel);
        if(e->getPolynomialOrder() < 2) continue;
        for(int iFace = 0; iFace < e->getNumFaces(); ++iFace) {
          std::vector<MVertex *> fv;
          e->getFaceVertices(iFace, fv);
          if(fv.size() == 9) volumeQuadFaces[e->getFace(iFace)] = fv;
        }
      }
    }

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      std::vector<MQuadrangle *> oldQuads = gf->quadrangles;
      std::vector<MQuadrangle *> newQuads;
      newQuads.reserve(oldQuads.size() + oldQuads.size() * widths.size());

      for(auto q : oldQuads) {
        if(q->getTypeForMSH() != MSH_QUA_9) {
          newQuads.push_back(q);
          continue;
        }

        std::vector<MVertex *> side0, side1;
        for(int i = 0; i < 4; ++i) {
          side0 = getOrientedSplitColumn(splitColumns, q->getEdge(i));
          side1 =
            getOrientedSplitColumn(splitColumns, q->getEdge((i + 2) % 4));
          if(side0.size() == widths.size() + 1 &&
             side1.size() == widths.size() + 1) {
            // Opposite edges of a quadrangle are oriented in opposite
            // directions in the element closure. Use the same layer direction
            // on both sides so each split surface quad matches the
            // corresponding split volume face.
            std::reverse(side1.begin(), side1.end());
            break;
          }
          side0.clear();
          side1.clear();
        }
        if(side0.empty()) {
          newQuads.push_back(q);
          continue;
        }

        auto itLayer = layers.find(q);
        const bool wasProcessed = toProcessP2.find(q) != toProcessP2.end();
        if(wasProcessed) toProcessP2.erase(q);
        if(itLayer != layers.end()) layers.erase(itLayer);

        for(std::size_t j = 0; j < widths.size(); ++j) {
          MVertex *v0 = side0[j];
          MVertex *v1 = side0[j + 1];
          MVertex *v2 = side1[j + 1];
          MVertex *v3 = side1[j];
          MVertex *v4 = getOrCreateFaceEdgeNode(gf, v0, v1, edgeNodes);
          MVertex *v5 = getOrCreateFaceEdgeNode(gf, v1, v2, edgeNodes);
          MVertex *v6 = getOrCreateFaceEdgeNode(gf, v2, v3, edgeNodes);
          MVertex *v7 = getOrCreateFaceEdgeNode(gf, v3, v0, edgeNodes);
          MVertex *v8 = getOrCreateFaceCenterNode(gf, v0, v1, v2, v3,
                                                  faceNodes);

          MQuadrangle *qn = nullptr;
          auto itVolumeFace = volumeQuadFaces.find(MFace(v0, v1, v2, v3));
          if(itVolumeFace != volumeQuadFaces.end()) {
            const std::vector<MVertex *> &fv = itVolumeFace->second;
            qn = new MQuadrangle9(fv[0], fv[1], fv[2], fv[3], fv[4], fv[5],
                                  fv[6], fv[7], fv[8], 0,
                                  q->getPartition());
            numFromVolumeFaces++;
          }
          else {
            qn = new MQuadrangle9(v0, v1, v2, v3, v4, v5, v6, v7, v8, 0,
                                  q->getPartition());
            numMissingVolumeFaces++;
          }
          for(std::size_t k = 0; k < qn->getNumVertices(); ++k) {
            MVertex *v = qn->getVertex(k);
            if(classified.insert(v).second) classifyHighOrderVertexOnFace(gf, v);
          }
          newQuads.push_back(qn);
          layers[qn] = widths[j];
          if(wasProcessed) toProcessP2.insert(qn);
          numCreated++;
        }

        delete q;
        numSplit++;
      }

      gf->quadrangles = newQuads;
      gf->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: split %zu boundary P2 quadrangles "
              "into %zu layer quadrangles using volume split nodes (%zu from "
              "volume faces, %zu fallback)",
              numSplit, numCreated, numFromVolumeFaces, numMissingVolumeFaces);
  }

  static void splitHighOrderVolumesParametricP2(
    GModel *m, std::map<MElement *, double> &layers,
    const std::vector<double> &widths,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2)
  {
    if(widths.size() <= 1) return;

    double total = 0.;
    for(double w : widths) total += w;
    if(!(total > 0.)) return;

    std::vector<double> levels;
    levels.reserve(widths.size() + 1);
    levels.push_back(0.);
    double sum = 0.;
    for(double w : widths) {
      sum += w;
      levels.push_back(sum / total);
    }
    levels.back() = 1.;

    std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> splitColumns;
    std::map<MEdge, MVertex *, MEdgeLessThan> edgeNodes;
    std::map<MFace, MVertex *, MFaceLessThan> faceNodes;
    seedHighOrderNodeMaps(m, edgeNodes, faceNodes);

    std::size_t numPrismsSplit = 0, numHexesSplit = 0;
    std::size_t numPrismsCreated = 0, numHexesCreated = 0;
    std::size_t numPrismsReversed = 0, numHexesReversed = 0;
    std::size_t numPrismsNonPositive = 0, numHexesNonPositive = 0;

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;

      std::vector<MPrism *> oldPrisms = gr->prisms;
      std::vector<MPrism *> newPrisms;
      newPrisms.reserve(oldPrisms.size() + oldPrisms.size() * widths.size());
      for(auto p : oldPrisms) {
        auto itLayer = layers.find(p);
        if(itLayer == layers.end() || p->getTypeForMSH() != MSH_PRI_18) {
          newPrisms.push_back(p);
          continue;
        }

        const bool wasProcessed = toProcessP2.find(p) != toProcessP2.end();
        if(wasProcessed) toProcessP2.erase(p);
        layers.erase(itLayer);

        std::vector<MVertex *> c0 = getOrCreateSplitColumn(
          gr, p, p->getVertex(0), p->getVertex(3), 0., 0., levels,
          splitColumns);
        std::vector<MVertex *> c1 = getOrCreateSplitColumn(
          gr, p, p->getVertex(1), p->getVertex(4), 1., 0., levels,
          splitColumns);
        std::vector<MVertex *> c2 = getOrCreateSplitColumn(
          gr, p, p->getVertex(2), p->getVertex(5), 0., 1., levels,
          splitColumns);

        for(std::size_t j = 0; j < widths.size(); ++j) {
          const double w0 = -1. + 2. * levels[j];
          const double w1 = -1. + 2. * levels[j + 1];
          const double wm = 0.5 * (w0 + w1);
          std::vector<MVertex *> v(18);
          v[0] = c0[j];
          v[1] = c1[j];
          v[2] = c2[j];
          v[3] = c0[j + 1];
          v[4] = c1[j + 1];
          v[5] = c2[j + 1];
          v[6] = getOrCreateRegionEdgeNode(gr, p, v[0], v[1], 0.5, 0., w0,
                                           edgeNodes);
          v[7] = getOrCreateRegionEdgeNode(gr, p, v[0], v[2], 0., 0.5, w0,
                                           edgeNodes);
          v[8] = getOrCreateRegionEdgeNode(gr, p, v[0], v[3], 0., 0., wm,
                                           edgeNodes);
          v[9] = getOrCreateRegionEdgeNode(gr, p, v[1], v[2], 0.5, 0.5, w0,
                                           edgeNodes);
          v[10] = getOrCreateRegionEdgeNode(gr, p, v[1], v[4], 1., 0., wm,
                                            edgeNodes);
          v[11] = getOrCreateRegionEdgeNode(gr, p, v[2], v[5], 0., 1., wm,
                                            edgeNodes);
          v[12] = getOrCreateRegionEdgeNode(gr, p, v[3], v[4], 0.5, 0., w1,
                                            edgeNodes);
          v[13] = getOrCreateRegionEdgeNode(gr, p, v[3], v[5], 0., 0.5, w1,
                                            edgeNodes);
          v[14] = getOrCreateRegionEdgeNode(gr, p, v[4], v[5], 0.5, 0.5, w1,
                                            edgeNodes);
          v[15] = getOrCreateRegionFaceNode(gr, p, v[0], v[1], v[4], v[3],
                                            0.5, 0., wm, faceNodes);
          v[16] = getOrCreateRegionFaceNode(gr, p, v[0], v[3], v[5], v[2],
                                            0., 0.5, wm, faceNodes);
          v[17] = getOrCreateRegionFaceNode(gr, p, v[1], v[2], v[5], v[4],
                                            0.5, 0.5, wm, faceNodes);

          MPrism *pn = new MPrism18(v, 0, p->getPartition());
          int sign = pn->getVolumeSign();
          if(sign < 0) {
            pn->reverse();
            numPrismsReversed++;
            sign = pn->getVolumeSign();
          }
          if(sign <= 0) numPrismsNonPositive++;
          newPrisms.push_back(pn);
          layers[pn] = widths[j];
          if(wasProcessed) toProcessP2.insert(pn);
          numPrismsCreated++;
        }

        delete p;
        numPrismsSplit++;
      }
      gr->prisms = newPrisms;

      std::vector<MHexahedron *> oldHexes = gr->hexahedra;
      std::vector<MHexahedron *> newHexes;
      newHexes.reserve(oldHexes.size() + oldHexes.size() * widths.size());
      for(auto h : oldHexes) {
        auto itLayer = layers.find(h);
        if(itLayer == layers.end() || h->getTypeForMSH() != MSH_HEX_27) {
          newHexes.push_back(h);
          continue;
        }

        const bool wasProcessed = toProcessP2.find(h) != toProcessP2.end();
        if(wasProcessed) toProcessP2.erase(h);
        layers.erase(itLayer);

        std::vector<MVertex *> c0 = getOrCreateSplitColumn(
          gr, h, h->getVertex(0), h->getVertex(4), -1., -1., levels,
          splitColumns);
        std::vector<MVertex *> c1 = getOrCreateSplitColumn(
          gr, h, h->getVertex(1), h->getVertex(5), 1., -1., levels,
          splitColumns);
        std::vector<MVertex *> c2 = getOrCreateSplitColumn(
          gr, h, h->getVertex(2), h->getVertex(6), 1., 1., levels,
          splitColumns);
        std::vector<MVertex *> c3 = getOrCreateSplitColumn(
          gr, h, h->getVertex(3), h->getVertex(7), -1., 1., levels,
          splitColumns);

        for(std::size_t j = 0; j < widths.size(); ++j) {
          const double w0 = -1. + 2. * levels[j];
          const double w1 = -1. + 2. * levels[j + 1];
          const double wm = 0.5 * (w0 + w1);
          std::vector<MVertex *> v(27);
          v[0] = c0[j];
          v[1] = c1[j];
          v[2] = c2[j];
          v[3] = c3[j];
          v[4] = c0[j + 1];
          v[5] = c1[j + 1];
          v[6] = c2[j + 1];
          v[7] = c3[j + 1];
          v[8] = getOrCreateRegionEdgeNode(gr, h, v[0], v[1], 0., -1., w0,
                                           edgeNodes);
          v[9] = getOrCreateRegionEdgeNode(gr, h, v[0], v[3], -1., 0., w0,
                                           edgeNodes);
          v[10] = getOrCreateRegionEdgeNode(gr, h, v[0], v[4], -1., -1., wm,
                                            edgeNodes);
          v[11] = getOrCreateRegionEdgeNode(gr, h, v[1], v[2], 1., 0., w0,
                                            edgeNodes);
          v[12] = getOrCreateRegionEdgeNode(gr, h, v[1], v[5], 1., -1., wm,
                                            edgeNodes);
          v[13] = getOrCreateRegionEdgeNode(gr, h, v[2], v[3], 0., 1., w0,
                                            edgeNodes);
          v[14] = getOrCreateRegionEdgeNode(gr, h, v[2], v[6], 1., 1., wm,
                                            edgeNodes);
          v[15] = getOrCreateRegionEdgeNode(gr, h, v[3], v[7], -1., 1., wm,
                                            edgeNodes);
          v[16] = getOrCreateRegionEdgeNode(gr, h, v[4], v[5], 0., -1., w1,
                                            edgeNodes);
          v[17] = getOrCreateRegionEdgeNode(gr, h, v[4], v[7], -1., 0., w1,
                                            edgeNodes);
          v[18] = getOrCreateRegionEdgeNode(gr, h, v[5], v[6], 1., 0., w1,
                                            edgeNodes);
          v[19] = getOrCreateRegionEdgeNode(gr, h, v[6], v[7], 0., 1., w1,
                                            edgeNodes);
          v[20] = getOrCreateRegionFaceNode(gr, h, v[0], v[3], v[2], v[1],
                                            0., 0., w0, faceNodes);
          v[21] = getOrCreateRegionFaceNode(gr, h, v[0], v[1], v[5], v[4],
                                            0., -1., wm, faceNodes);
          v[22] = getOrCreateRegionFaceNode(gr, h, v[0], v[4], v[7], v[3],
                                            -1., 0., wm, faceNodes);
          v[23] = getOrCreateRegionFaceNode(gr, h, v[1], v[2], v[6], v[5],
                                            1., 0., wm, faceNodes);
          v[24] = getOrCreateRegionFaceNode(gr, h, v[2], v[3], v[7], v[6],
                                            0., 1., wm, faceNodes);
          v[25] = getOrCreateRegionFaceNode(gr, h, v[4], v[5], v[6], v[7],
                                            0., 0., w1, faceNodes);
          v[26] = createMappedRegionVertex(gr, h, 0., 0., wm);

          MHexahedron *hn = new MHexahedron27(v, 0, h->getPartition());
          int sign = hn->getVolumeSign();
          if(sign < 0) {
            hn->reverse();
            numHexesReversed++;
            sign = hn->getVolumeSign();
          }
          if(sign <= 0) numHexesNonPositive++;
          newHexes.push_back(hn);
          layers[hn] = widths[j];
          if(wasProcessed) toProcessP2.insert(hn);
          numHexesCreated++;
        }

        delete h;
        numHexesSplit++;
      }
      gr->hexahedra = newHexes;
      gr->deleteVertexArrays();
    }

    splitHighOrderBoundaryQuadsFromVolumeSplitsP2(
      m, layers, widths, toProcessP2, splitColumns, edgeNodes, faceNodes);
    stitchHighOrderMeshNodes(m);

    Msg::Info("High-order boundary layer: split %zu P2 prisms into %zu and "
              "%zu P2 hexes into %zu parametric layer elements (%zu/%zu "
              "reversed, %zu/%zu non-positive after correction)",
              numPrismsSplit, numPrismsCreated, numHexesSplit, numHexesCreated,
              numPrismsReversed, numHexesReversed, numPrismsNonPositive,
              numHexesNonPositive);
  }

  static void splitHighOrderQuadsParametricP2(
    GModel *m, std::map<MElement *, double> &layers,
    const std::vector<double> &widths,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2)
  {
    if(widths.size() <= 1) return;

    double total = 0.;
    for(double w : widths) total += w;
    if(!(total > 0.)) return;

    std::vector<double> levels;
    levels.reserve(widths.size() + 1);
    levels.push_back(0.);
    double sum = 0.;
    for(double w : widths) {
      sum += w;
      levels.push_back(sum / total);
    }
    levels.back() = 1.;

    std::size_t numSplit = 0, numCreated = 0;

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      std::vector<MQuadrangle *> oldQuads = gf->quadrangles;
      std::vector<MQuadrangle *> newQuads;
      newQuads.reserve(oldQuads.size() + oldQuads.size() * widths.size());

      for(auto q : oldQuads) {
        auto itLayer = layers.find(q);
        if(itLayer == layers.end() || q->getTypeForMSH() != MSH_QUA_9) {
          newQuads.push_back(q);
          continue;
        }

        const bool wasProcessed = toProcessP2.find(q) != toProcessP2.end();
        if(wasProcessed) toProcessP2.erase(q);
        layers.erase(itLayer);

        std::vector<MVertex *> left(levels.size()), right(levels.size());
        left.front() = q->getVertex(0);
        right.front() = q->getVertex(1);
        left.back() = q->getVertex(3);
        right.back() = q->getVertex(2);
        for(std::size_t i = 1; i + 1 < levels.size(); ++i) {
          const double v = -1. + 2. * levels[i];
          left[i] = mappedFaceVertex(gf, q, -1., v);
          right[i] = mappedFaceVertex(gf, q, 1., v);
        }

        for(std::size_t j = 0; j < widths.size(); ++j) {
          const double s0 = levels[j];
          const double s1 = levels[j + 1];
          const double sm = 0.5 * (s0 + s1);
          const double v0 = -1. + 2. * s0;
          const double v1 = -1. + 2. * s1;
          const double vm = -1. + 2. * sm;

          MVertex *v0p = left[j];
          MVertex *v1p = right[j];
          MVertex *v2p = right[j + 1];
          MVertex *v3p = left[j + 1];

          MVertex *v4p =
            (j == 0) ? q->getVertex(4) : mappedFaceVertex(gf, q, 0., v0);
          MVertex *v5p = mappedFaceVertex(gf, q, 1., vm);
          MVertex *v6p = (j + 1 == widths.size()) ?
                           q->getVertex(6) :
                           mappedFaceVertex(gf, q, 0., v1);
          MVertex *v7p = mappedFaceVertex(gf, q, -1., vm);
          MVertex *v8p = mappedFaceVertex(gf, q, 0., vm);

          MQuadrangle *qn =
            new MQuadrangle9(v0p, v1p, v2p, v3p, v4p, v5p, v6p, v7p, v8p, 0,
                             q->getPartition());
          newQuads.push_back(qn);
          layers[qn] = widths[j];
          if(wasProcessed) toProcessP2.insert(qn);
          numCreated++;
        }

        delete q;
        numSplit++;
      }

      gf->quadrangles = newQuads;
      gf->deleteVertexArrays();
    }

    Msg::Info("High-order boundary layer: split %zu P2 quadrangles into %zu "
              "parametric layer quadrangles",
              numSplit, numCreated);
  }

  static void writeBezierFaceUntanglerPos(
    GFace *gf, const char *stage,
    const std::vector<std::array<double, 2>> &points,
    const std::vector<bool> &locked,
    const std::vector<std::array<uint32_t, 3>> &triangles,
    const std::vector<std::array<std::array<double, 2>, 3>> &sh)
  {
    char name[256];
    std::snprintf(name, sizeof(name), "highOrderBL_bezier_face_%d_%s.pos",
                  gf->tag(), stage);
    FILE *fp = std::fopen(name, "w");
    if(!fp) {
      Msg::Warning("Could not open '%s' for writing", name);
      return;
    }

    auto point = [&](const std::array<double, 2> &p) {
      return gf->point(SPoint2(p[0], p[1]));
    };

    std::fprintf(fp, "View \"Bezier triangles face %d %s\" {\n", gf->tag(),
                 stage);
    for(std::size_t i = 0; i < triangles.size(); ++i) {
      const auto &t = triangles[i];
      GPoint p0 = point(points[t[0]]);
      GPoint p1 = point(points[t[1]]);
      GPoint p2 = point(points[t[2]]);
      std::fprintf(fp,
                   "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%zu,%zu,%zu};\n",
                   p0.x(), p0.y(), p0.z(), p1.x(), p1.y(), p1.z(), p2.x(),
                   p2.y(), p2.z(), i, i, i);
    }
    std::fprintf(fp, "};\n");

    std::fprintf(fp, "View \"Bezier points face %d %s\" {\n", gf->tag(),
                 stage);
    for(std::size_t i = 0; i < points.size(); ++i) {
      GPoint p = point(points[i]);
      std::fprintf(fp, "SP(%g,%g,%g){%d};\n", p.x(), p.y(), p.z(),
                   locked[i] ? 1 : 0);
    }
    std::fprintf(fp, "};\n");

    if(sh.size() == triangles.size()) {
      std::fprintf(fp, "View \"Ideal triangles face %d %s\" {\n", gf->tag(),
                   stage);
      for(std::size_t i = 0; i < sh.size(); ++i) {
        GPoint p0 = point(sh[i][0]);
        GPoint p1 = point(sh[i][1]);
        GPoint p2 = point(sh[i][2]);
        std::fprintf(fp,
                     "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%zu,%zu,%zu};\n",
                     p0.x(), p0.y(), p0.z(), p1.x(), p1.y(), p1.z(), p2.x(),
                     p2.y(), p2.z(), i, i, i);
      }
      std::fprintf(fp, "};\n");
    }

    std::fclose(fp);
    Msg::Info("High-order boundary layer: wrote '%s'", name);
  }

  static double tetVolume(const std::array<double, 3> &a,
                          const std::array<double, 3> &b,
                          const std::array<double, 3> &c,
                          const std::array<double, 3> &d)
  {
    const double adx = a[0] - d[0], ady = a[1] - d[1], adz = a[2] - d[2];
    const double bdx = b[0] - d[0], bdy = b[1] - d[1], bdz = b[2] - d[2];
    const double cdx = c[0] - d[0], cdy = c[1] - d[1], cdz = c[2] - d[2];
    const double cx = bdy * cdz - bdz * cdy;
    const double cy = bdz * cdx - bdx * cdz;
    const double cz = bdx * cdy - bdy * cdx;
    return (adx * cx + ady * cy + adz * cz) / 6.;
  }

  static std::array<double, 3> point3(MVertex *v)
  {
    return {v->x(), v->y(), v->z()};
  }

  static std::array<double, 3> mid(const std::array<double, 3> &a,
                                   const std::array<double, 3> &b)
  {
    return {0.5 * (a[0] + b[0]), 0.5 * (a[1] + b[1]),
            0.5 * (a[2] + b[2])};
  }

  static std::array<double, 3> avg4(const std::array<double, 3> &a,
                                    const std::array<double, 3> &b,
                                    const std::array<double, 3> &c,
                                    const std::array<double, 3> &d)
  {
    return {0.25 * (a[0] + b[0] + c[0] + d[0]),
            0.25 * (a[1] + b[1] + c[1] + d[1]),
            0.25 * (a[2] + b[2] + c[2] + d[2])};
  }

  static std::array<double, 3> avg8(const std::array<double, 3> &a,
                                    const std::array<double, 3> &b,
                                    const std::array<double, 3> &c,
                                    const std::array<double, 3> &d,
                                    const std::array<double, 3> &e,
                                    const std::array<double, 3> &f,
                                    const std::array<double, 3> &g,
                                    const std::array<double, 3> &h)
  {
    return {0.125 * (a[0] + b[0] + c[0] + d[0] + e[0] + f[0] + g[0] + h[0]),
            0.125 * (a[1] + b[1] + c[1] + d[1] + e[1] + f[1] + g[1] + h[1]),
            0.125 * (a[2] + b[2] + c[2] + d[2] + e[2] + f[2] + g[2] + h[2])};
  }

  static void addTetWithPositiveIdeal(
    const std::array<uint32_t, 4> &tet,
    const std::array<std::array<double, 3>, 4> &ideal,
    std::vector<std::array<uint32_t, 4>> &tets,
    std::vector<std::array<std::array<double, 3>, 4>> &sh,
    std::vector<int> &tetSources, int source, std::size_t &numDegenerate,
    std::size_t &numReorientedIdeal)
  {
    const double volume =
      tetVolume(ideal[0], ideal[1], ideal[2], ideal[3]);
    if(std::abs(volume) < 1.e-18) {
      numDegenerate++;
      return;
    }
    auto orientedTet = tet;
    auto orientedIdeal = ideal;
    if(volume < 0.) {
      std::swap(orientedTet[0], orientedTet[1]);
      std::swap(orientedIdeal[0], orientedIdeal[1]);
      numReorientedIdeal++;
    }
    tets.push_back(orientedTet);
    sh.push_back(orientedIdeal);
    tetSources.push_back(source);
  }

  static void prepareRegionUntanglerP2(
    GRegion *gr, const std::set<MElement *, MElementPtrLessThan> &toProcess,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    std::vector<MElement *> elements;
    for(auto e : gr->tetrahedra)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_TET_10)
        elements.push_back(e);
    for(auto e : gr->prisms)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_PRI_18)
        elements.push_back(e);
    for(auto e : gr->hexahedra)
      if(toProcess.find(e) != toProcess.end() &&
         e->getTypeForMSH() == MSH_HEX_27)
        elements.push_back(e);
    if(elements.empty()) return;

    std::set<MVertex *, MVertexPtrLessThan> lockedByTopology;
    std::size_t numLockedFromBoundaryFaces = 0;
    for(auto gf : gr->faces()) {
      for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement *e = gf->getMeshElement(i);
        for(std::size_t j = 0; j < e->getNumVertices(); ++j) {
          if(lockedByTopology.insert(e->getVertex(j)).second)
            numLockedFromBoundaryFaces++;
        }
      }
    }

    std::size_t numLockedFromOutsideElements = 0;
    auto lockOutsideElement = [&](MElement *e) {
      if(toProcess.find(e) != toProcess.end()) return;
      for(std::size_t j = 0; j < e->getNumVertices(); ++j) {
        if(lockedByTopology.insert(e->getVertex(j)).second)
          numLockedFromOutsideElements++;
      }
    };
    for(auto e : gr->tetrahedra) lockOutsideElement(e);
    for(auto e : gr->hexahedra) lockOutsideElement(e);
    for(auto e : gr->prisms) lockOutsideElement(e);
    for(auto e : gr->pyramids) lockOutsideElement(e);

    std::map<MFace, int, MFaceLessThan> faceCount;
    for(auto e : elements)
      for(int i = 0; i < e->getNumFaces(); ++i) faceCount[e->getFace(i)]++;

    std::set<MVertex *, MVertexPtrLessThan> boundary;
    std::set<MVertex *, MVertexPtrLessThan> geometricalFaceNodes;
    for(auto e : elements) {
      for(int i = 0; i < e->getNumFaces(); ++i) {
        MFace face = e->getFace(i);
        GFace *gf = commonFace(face);
        if(faceCount[face] != 1) continue;
        std::vector<MVertex *> fv;
        e->getFaceVertices(i, fv);
        for(auto v : fv) boundary.insert(v);
        if(gf) {
          for(auto v : fv) geometricalFaceNodes.insert(v);
        }
      }
    }

    std::map<MVertex *, uint32_t, MVertexPtrLessThan> indices;
    std::vector<std::array<double, 3>> points;
    std::vector<bool> locked;
    auto addVertex = [&](MVertex *v) {
      auto it = indices.find(v);
      if(it != indices.end()) return it->second;
      const uint32_t index = (uint32_t)points.size();
      indices[v] = index;
      points.push_back({v->x(), v->y(), v->z()});
      locked.push_back(fixed.find(v) != fixed.end() ||
                       boundary.find(v) != boundary.end() ||
                       lockedByTopology.find(v) != lockedByTopology.end() ||
                       geometricalFaceNodes.find(v) !=
                         geometricalFaceNodes.end() ||
                       !v->onWhat() || v->onWhat()->dim() != 3);
      return index;
    };

    std::vector<std::array<uint32_t, 4>> rawTets;
    std::vector<std::array<std::array<double, 3>, 4>> rawTetIdeals;
    std::vector<MElement *> rawTetParents;
    std::vector<int> rawTetLocals;
    std::vector<int> rawTetSources;
    std::size_t numTet10 = 0, numPrism18 = 0, numHex27 = 0;
    std::size_t numRawTetsFromTet10 = 0, numRawTetsFromPrism18 = 0;
    std::size_t numRawTetsFromHex27 = 0;
    for(auto e : elements) {
      if(e->getTypeForMSH() == MSH_TET_10) {
        numTet10++;
        std::array<uint32_t, 10> tet;
        for(std::size_t i = 0; i < tet.size(); ++i)
          tet[i] = addVertex(e->getVertex(i));
        std::array<std::array<double, 3>, 10> ideal;
        for(std::size_t i = 0; i < 4; ++i) ideal[i] = point3(e->getVertex(i));
        ideal[4] = mid(ideal[0], ideal[1]);
        ideal[5] = mid(ideal[1], ideal[2]);
        ideal[6] = mid(ideal[2], ideal[0]);
        ideal[7] = mid(ideal[3], ideal[0]);
        ideal[8] = mid(ideal[3], ideal[2]);
        ideal[9] = mid(ideal[3], ideal[1]);
        int localTet = 0;
        for(const auto &subTet : tetP2ToTetP1) {
          rawTets.push_back({tet[subTet[0]], tet[subTet[1]], tet[subTet[2]],
                             tet[subTet[3]]});
          rawTetIdeals.push_back({ideal[subTet[0]], ideal[subTet[1]],
                                  ideal[subTet[2]], ideal[subTet[3]]});
          rawTetParents.push_back(e);
          rawTetLocals.push_back(localTet++);
          rawTetSources.push_back(0);
        }
        numRawTetsFromTet10 +=
          sizeof(tetP2ToTetP1) / sizeof(tetP2ToTetP1[0]);
      }
      else if(e->getTypeForMSH() == MSH_PRI_18) {
        numPrism18++;
        std::array<uint32_t, 18> prism;
        for(std::size_t i = 0; i < prism.size(); ++i)
          prism[i] = addVertex(e->getVertex(i));
        std::array<std::array<double, 3>, 18> ideal;
        for(std::size_t i = 0; i < 6; ++i) ideal[i] = point3(e->getVertex(i));
        ideal[6] = mid(ideal[0], ideal[1]);
        ideal[7] = mid(ideal[0], ideal[2]);
        ideal[8] = mid(ideal[0], ideal[3]);
        ideal[9] = mid(ideal[1], ideal[2]);
        ideal[10] = mid(ideal[1], ideal[4]);
        ideal[11] = mid(ideal[2], ideal[5]);
        ideal[12] = mid(ideal[3], ideal[4]);
        ideal[13] = mid(ideal[3], ideal[5]);
        ideal[14] = mid(ideal[4], ideal[5]);
        ideal[15] = avg4(ideal[0], ideal[1], ideal[4], ideal[3]);
        ideal[16] = avg4(ideal[0], ideal[3], ideal[5], ideal[2]);
        ideal[17] = avg4(ideal[1], ideal[2], ideal[5], ideal[4]);
        const std::size_t before = rawTets.size();
        int localTet = 0;
        for(const auto &subPrism : prismP2TensorPrisms) {
          for(const auto &tet : prismP1DoubleCoveringTets) {
            rawTets.push_back({prism[subPrism[tet[0]]],
                               prism[subPrism[tet[1]]],
                               prism[subPrism[tet[2]]],
                               prism[subPrism[tet[3]]]});
            rawTetIdeals.push_back({ideal[subPrism[tet[0]]],
                                    ideal[subPrism[tet[1]]],
                                    ideal[subPrism[tet[2]]],
                                    ideal[subPrism[tet[3]]]});
            rawTetParents.push_back(e);
            rawTetLocals.push_back(localTet++);
            rawTetSources.push_back(1);
          }
        }
        numRawTetsFromPrism18 += rawTets.size() - before;
      }
      else if(e->getTypeForMSH() == MSH_HEX_27) {
        numHex27++;
        std::array<uint32_t, 27> hex;
        for(std::size_t i = 0; i < hex.size(); ++i)
          hex[i] = addVertex(e->getVertex(i));
        std::array<std::array<double, 3>, 27> ideal;
        for(std::size_t i = 0; i < 8; ++i) ideal[i] = point3(e->getVertex(i));
        ideal[8] = mid(ideal[0], ideal[1]);
        ideal[9] = mid(ideal[0], ideal[3]);
        ideal[10] = mid(ideal[0], ideal[4]);
        ideal[11] = mid(ideal[1], ideal[2]);
        ideal[12] = mid(ideal[1], ideal[5]);
        ideal[13] = mid(ideal[2], ideal[3]);
        ideal[14] = mid(ideal[2], ideal[6]);
        ideal[15] = mid(ideal[3], ideal[7]);
        ideal[16] = mid(ideal[4], ideal[5]);
        ideal[17] = mid(ideal[4], ideal[7]);
        ideal[18] = mid(ideal[5], ideal[6]);
        ideal[19] = mid(ideal[6], ideal[7]);
        ideal[20] = avg4(ideal[0], ideal[3], ideal[2], ideal[1]);
        ideal[21] = avg4(ideal[0], ideal[1], ideal[5], ideal[4]);
        ideal[22] = avg4(ideal[0], ideal[4], ideal[7], ideal[3]);
        ideal[23] = avg4(ideal[1], ideal[2], ideal[6], ideal[5]);
        ideal[24] = avg4(ideal[2], ideal[3], ideal[7], ideal[6]);
        ideal[25] = avg4(ideal[4], ideal[5], ideal[6], ideal[7]);
        ideal[26] = avg8(ideal[0], ideal[1], ideal[2], ideal[3],
                         ideal[4], ideal[5], ideal[6], ideal[7]);
        const std::size_t before = rawTets.size();
        int localTet = 0;
        for(const auto &subHex : hexP2TensorHexes) {
          for(const auto &tet : hexP1Tets) {
            rawTets.push_back({hex[subHex[tet[0]]], hex[subHex[tet[1]]],
                               hex[subHex[tet[2]]], hex[subHex[tet[3]]]});
            rawTetIdeals.push_back({ideal[subHex[tet[0]]],
                                    ideal[subHex[tet[1]]],
                                    ideal[subHex[tet[2]]],
                                    ideal[subHex[tet[3]]]});
            rawTetParents.push_back(e);
            rawTetLocals.push_back(localTet++);
            rawTetSources.push_back(2);
          }
        }
        numRawTetsFromHex27 += rawTets.size() - before;
      }
    }

    std::vector<std::array<uint32_t, 4>> tets;
    std::vector<std::array<std::array<double, 3>, 4>> sh;
    std::vector<int> tetSources;
    std::vector<MElement *> tetParents;
    std::vector<int> tetLocals;
    std::size_t numDegenerate = 0;
    tets.reserve(rawTets.size());
    sh.reserve(rawTets.size());
    tetSources.reserve(rawTets.size());
    tetParents.reserve(rawTets.size());
    tetLocals.reserve(rawTets.size());
    std::size_t numReorientedIdeal = 0;
    for(std::size_t i = 0; i < rawTets.size(); ++i) {
      const std::size_t before = tets.size();
      addTetWithPositiveIdeal(rawTets[i], rawTetIdeals[i], tets, sh,
                              tetSources, rawTetSources[i],
                              numDegenerate, numReorientedIdeal);
      if(tets.size() != before) {
        tetParents.push_back(rawTetParents[i]);
        tetLocals.push_back(rawTetLocals[i]);
      }
    }

    if(tets.empty()) return;

    std::size_t nLocked = 0;
    for(bool l : locked)
      if(l) nLocked++;
    Msg::Info("High-order boundary layer region %d: prepared %zu P2 elements "
              "(%zu tet10 -> %zu tets, %zu prism18 -> %zu tets, %zu hex27 -> "
              "%zu tets) as %zu low-order tetrahedra, %zu points, %zu locked "
              "(%zu on geometrical faces, %zu from boundary faces, %zu from "
              "outside elements, %zu reoriented reference tetrahedra)%s",
              gr->tag(), elements.size(), numTet10, numRawTetsFromTet10,
              numPrism18, numRawTetsFromPrism18, numHex27,
              numRawTetsFromHex27, tets.size(), points.size(), nLocked,
              geometricalFaceNodes.size(), numLockedFromBoundaryFaces,
              numLockedFromOutsideElements, numReorientedIdeal,
              numDegenerate ? " (some degenerate tetrahedra skipped)" : "");

    untangle_tetrahedra_GMSH(points, locked, tets, sh, 1.e+0);

    std::size_t numInvalidTet10 = 0, numInvalidPrism18 = 0;
    std::size_t numInvalidHex27 = 0;
    std::array<std::size_t, 5> invalidByLocked = {{0, 0, 0, 0, 0}};
    std::array<std::size_t, 60> invalidPrismLocal = {};
    std::array<std::size_t, 48> invalidHexLocal = {};
    double detMin = DBL_MAX;
    std::size_t firstInvalid = tets.size();
    int firstInvalidLocked = 0;
    for(std::size_t i = 0; i < tets.size(); ++i) {
      const auto &tet = tets[i];
      const double det = tetVolume(points[tet[0]], points[tet[1]],
                                   points[tet[2]], points[tet[3]]) /
                         tetVolume(sh[i][0], sh[i][1], sh[i][2], sh[i][3]);
      if(det < detMin) detMin = det;
      if(det <= 0.) {
        if(tetSources[i] == 0)
          numInvalidTet10++;
        else if(tetSources[i] == 1) {
          numInvalidPrism18++;
          if(tetLocals[i] >= 0 &&
             tetLocals[i] < (int)invalidPrismLocal.size())
            invalidPrismLocal[tetLocals[i]]++;
        }
        else {
          numInvalidHex27++;
          if(tetLocals[i] >= 0 && tetLocals[i] < (int)invalidHexLocal.size())
            invalidHexLocal[tetLocals[i]]++;
        }
        int nLockedTet = 0;
        for(std::size_t j = 0; j < 4; ++j)
          if(locked[tet[j]]) nLockedTet++;
        invalidByLocked[nLockedTet]++;
        if(firstInvalid == tets.size()) {
          firstInvalid = i;
          firstInvalidLocked = nLockedTet;
        }
      }
    }
    if(numInvalidTet10 || numInvalidPrism18 || numInvalidHex27) {
      std::string prismLocalText;
      for(std::size_t i = 0; i < invalidPrismLocal.size(); ++i) {
        if(!invalidPrismLocal[i]) continue;
        if(!prismLocalText.empty()) prismLocalText += ", ";
        prismLocalText += std::to_string(i) + ":" +
                          std::to_string(invalidPrismLocal[i]);
      }
      std::string hexLocalText;
      for(std::size_t i = 0; i < invalidHexLocal.size(); ++i) {
        if(!invalidHexLocal[i]) continue;
        if(!hexLocalText.empty()) hexLocalText += ", ";
        hexLocalText +=
          std::to_string(i) + ":" + std::to_string(invalidHexLocal[i]);
      }
      const char *source =
        tetSources[firstInvalid] == 0 ?
          "tet10" :
          (tetSources[firstInvalid] == 1 ? "prism18" : "hex27");
      Msg::Info("High-order boundary layer region %d: P2 volume proxy still "
                "has %zu invalid tet10-subtets, %zu invalid prism18-subtets "
                "and %zu invalid hex27-subtets after untangling (detmin %.6g, "
                "first source %s element %d local %d with %d locked vertices, "
                "locked histogram %zu/%zu/%zu/%zu/%zu%s%s%s%s)",
                gr->tag(), numInvalidTet10, numInvalidPrism18,
                numInvalidHex27, detMin, source,
                tetParents[firstInvalid] ? tetParents[firstInvalid]->getNum() :
                                           0,
                tetLocals[firstInvalid], firstInvalidLocked,
                invalidByLocked[0], invalidByLocked[1], invalidByLocked[2],
                invalidByLocked[3], invalidByLocked[4],
                prismLocalText.empty() ? "" : ", prism locals ",
                prismLocalText.c_str(), hexLocalText.empty() ? "" :
                                                               ", hex locals ",
                hexLocalText.c_str());
    }

    std::size_t numUpdated = 0;
    double maxUpdate = 0.;
    for(const auto &entry : indices) {
      MVertex *v = entry.first;
      uint32_t i = entry.second;
      if(locked[i]) continue;
      const double dx = points[i][0] - v->x();
      const double dy = points[i][1] - v->y();
      const double dz = points[i][2] - v->z();
      const double d = std::sqrt(dx * dx + dy * dy + dz * dz);
      if(d > maxUpdate) maxUpdate = d;
      v->x() = points[i][0];
      v->y() = points[i][1];
      v->z() = points[i][2];
      numUpdated++;
    }
    Msg::Info("High-order boundary layer region %d: updated %zu free P2 "
              "volume vertices after untangling (max displacement %.6g)",
              gr->tag(), numUpdated, maxUpdate);
  }

  static void prepareFaceUntanglerP2(
    GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
    const std::set<MVertex *, MVertexPtrLessThan> &fixed,
    bool useCurrentBezierAsIdeal)
  {
    std::vector<MElement *> elements;
    for(auto e : gf->triangles)
      if(toProcess.find(e) != toProcess.end()) elements.push_back(e);
    for(auto e : gf->quadrangles)
      if(toProcess.find(e) != toProcess.end()) elements.push_back(e);
    if(elements.empty()) return;

    std::map<MEdge, int, MEdgeLessThan> edgeCount;
    for(auto e : elements)
      for(int i = 0; i < e->getNumEdges(); ++i) edgeCount[e->getEdge(i)]++;

    std::set<MVertex *, MVertexPtrLessThan> boundary;
    for(auto e : elements) {
      for(int i = 0; i < e->getNumEdges(); ++i) {
        MEdge edge = e->getEdge(i);
        if(edgeCount[edge] != 1) continue;
        boundary.insert(edge.getVertex(0));
        boundary.insert(edge.getVertex(1));
        std::vector<MVertex *> ev;
        e->getEdgeVertices(i, ev);
        for(auto v : ev) boundary.insert(v);
      }
    }

    std::map<MVertex *, uint32_t, MVertexPtrLessThan> indices;
    std::vector<std::array<double, 2> > points;
    std::vector<bool> locked;
    std::vector<std::array<uint32_t, 3> > triangles;
    std::vector<std::array<std::array<double, 2>, 3>> sh;
    std::vector<BezierPatchElement> patchElements;

    static const int triBezierTriangles[4][3] = {
      {0, 3, 5}, {3, 1, 4}, {5, 4, 2}, {3, 4, 5}};
    static const int quadBezierTriangles[8][3] = {
      {0, 4, 8}, {0, 8, 7}, {4, 1, 5}, {4, 5, 8},
      {8, 5, 2}, {8, 2, 6}, {7, 8, 6}, {7, 6, 3}};
    static const int triBezierCoeffFromVertex[6] = {0, 2, 5, 1, 4, 3};
    static const int quadBezierCoeffFromVertex[9] = {0, 2, 8, 6, 1,
                                                     5, 7, 3, 4};

    auto vertexParam = [&](MVertex *v) {
      SPoint2 p;
      if(!reparamMeshVertexOnFace(v, gf, p)) p = gf->parFromPoint(v->point());
      return std::array<double, 2>{p.x(), p.y()};
    };
    auto mid = [](const std::array<double, 2> &a,
                  const std::array<double, 2> &b) {
      return std::array<double, 2>{0.5 * (a[0] + b[0]), 0.5 * (a[1] + b[1])};
    };
    auto avg4 = [](const std::array<double, 2> &a,
                   const std::array<double, 2> &b,
                   const std::array<double, 2> &c,
                   const std::array<double, 2> &d) {
      return std::array<double, 2>{
        0.25 * (a[0] + b[0] + c[0] + d[0]),
        0.25 * (a[1] + b[1] + c[1] + d[1])};
    };

    std::size_t numDegenerateBezierTriangles = 0;
    auto addPositiveTriangle =
      [&](uint32_t a, uint32_t b, uint32_t c,
          const std::array<std::array<double, 2>, 3> &ideal) {
      const double idealArea =
        (ideal[1][0] - ideal[0][0]) * (ideal[2][1] - ideal[0][1]) -
        (ideal[1][1] - ideal[0][1]) * (ideal[2][0] - ideal[0][0]);
      if(std::abs(idealArea) < 1.e-14) {
        numDegenerateBezierTriangles++;
        return;
      }
      if(idealArea < 0.) {
        triangles.push_back({a, c, b});
        sh.push_back({ideal[0], ideal[2], ideal[1]});
      }
      else {
        triangles.push_back({a, b, c});
        sh.push_back(ideal);
      }
    };

    for(auto e : elements) {
      const bool isTri = e->getTypeForMSH() == MSH_TRI_6;
      const bool isQuad = e->getTypeForMSH() == MSH_QUA_9;
      if(!isTri && !isQuad) continue;

      bezierCoeff *bez = e->getBezierVerticesCoord();

      if(isTri) {
        if(bez->getNumCoeff() < 6) {
          delete bez;
          continue;
        }
        BezierPatchElement pe;
        pe.element = e;
        pe.isTriangle = true;
        uint32_t v[6];
        for(int i = 0; i < 6; ++i) {
          MVertex *owner = e->getVertex(i);
          const int iBez = triBezierCoeffFromVertex[i];
          v[i] = addBezierPatchPoint(
            gf, *bez, iBez, owner, lockedBezierOwner(owner, boundary, fixed),
            indices, points, locked);
          pe.bezierPoints[i] = v[i];
        }
        std::array<std::array<double, 2>, 6> ideal = {
          vertexParam(e->getVertex(0)),
          vertexParam(e->getVertex(1)),
          vertexParam(e->getVertex(2)),
          std::array<double, 2>{},
          std::array<double, 2>{},
          std::array<double, 2>{}};
        ideal[3] = mid(ideal[0], ideal[1]);
        ideal[4] = mid(ideal[1], ideal[2]);
        ideal[5] = mid(ideal[2], ideal[0]);
        for(const auto &tri : triBezierTriangles) {
          if(useCurrentBezierAsIdeal)
            addPositiveTriangle(v[tri[0]], v[tri[1]], v[tri[2]],
                                {points[v[tri[0]]], points[v[tri[1]]],
                                 points[v[tri[2]]]});
          else
            addPositiveTriangle(v[tri[0]], v[tri[1]], v[tri[2]],
                                {ideal[tri[0]], ideal[tri[1]],
                                 ideal[tri[2]]});
        }
        patchElements.push_back(pe);
      }
      else if(isQuad) {
        if(bez->getNumCoeff() < 9) {
          delete bez;
          continue;
        }
        BezierPatchElement pe;
        pe.element = e;
        pe.isTriangle = false;
        uint32_t v[9];
        for(int i = 0; i < 9; ++i) {
          MVertex *owner = e->getVertex(i);
          const int iBez = quadBezierCoeffFromVertex[i];
          v[i] = addBezierPatchPoint(
            gf, *bez, iBez, owner, lockedBezierOwner(owner, boundary, fixed),
            indices, points, locked);
          pe.bezierPoints[i] = v[i];
        }
        std::array<std::array<double, 2>, 9> ideal = {
          vertexParam(e->getVertex(0)),
          vertexParam(e->getVertex(1)),
          vertexParam(e->getVertex(2)),
          vertexParam(e->getVertex(3)),
          std::array<double, 2>{},
          std::array<double, 2>{},
          std::array<double, 2>{},
          std::array<double, 2>{},
          std::array<double, 2>{}};
        ideal[4] = mid(ideal[0], ideal[1]);
        ideal[5] = mid(ideal[1], ideal[2]);
        ideal[6] = mid(ideal[2], ideal[3]);
        ideal[7] = mid(ideal[3], ideal[0]);
        ideal[8] = avg4(ideal[0], ideal[1], ideal[2], ideal[3]);
        for(const auto &tri : quadBezierTriangles) {
          if(useCurrentBezierAsIdeal)
            addPositiveTriangle(v[tri[0]], v[tri[1]], v[tri[2]],
                                {points[v[tri[0]]], points[v[tri[1]]],
                                 points[v[tri[2]]]});
          else
            addPositiveTriangle(v[tri[0]], v[tri[1]], v[tri[2]],
                                {ideal[tri[0]], ideal[tri[1]],
                                 ideal[tri[2]]});
        }
        patchElements.push_back(pe);
      }
      delete bez;
    }

    if(!patchElements.empty())
      putLagrangeNodesAtBezierControlPoints(gf, patchElements, points);

    if(!triangles.empty()) {
      writeBezierFaceUntanglerPos(gf, "before", points, locked, triangles, sh);
      untangle_triangles_2D_GMSH(points, locked, triangles, sh, 1.e+0);
      writeBezierFaceUntanglerPos(gf, "after", points, locked, triangles, sh);
    }

    if(!patchElements.empty())
      updateLagrangeNodesFromBezierP2(gf, patchElements, points);

    std::size_t nLocked = 0;
    for(bool l : locked)
      if(l) nLocked++;
    if(numDegenerateBezierTriangles)
      Msg::Info("High-order boundary layer face %d: prepared %zu P2 elements "
                "as %zu low-order triangles, %zu points, %zu locked, skipped "
                "%zu degenerate triangles",
                gf->tag(), elements.size(), triangles.size(), points.size(),
                nLocked, numDegenerateBezierTriangles);
    else
    Msg::Info("High-order boundary layer face %d: prepared %zu P2 elements "
              "as %zu low-order triangles, %zu points, %zu locked%s",
              gf->tag(), elements.size(), triangles.size(), points.size(),
              nLocked,
              useCurrentBezierAsIdeal ? " (current Bezier ideal shapes)" :
                                        "");
  }

  static void collectElements(GModel *m, std::vector<MElement *> &elements)
  {
    if(!m) return;

    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(auto e : gf->triangles) elements.push_back(e);
      for(auto e : gf->quadrangles) elements.push_back(e);
    }

    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(auto e : gr->tetrahedra) elements.push_back(e);
      for(auto e : gr->hexahedra) elements.push_back(e);
      for(auto e : gr->prisms) elements.push_back(e);
      for(auto e : gr->pyramids) elements.push_back(e);
    }
  }

  struct ElementKey {
    int dim = 0;
    std::size_t numPrimaryVertices = 0;
    std::vector<MVertex *> vertices;

    bool operator<(const ElementKey &other) const
    {
      if(dim != other.dim) return dim < other.dim;
      if(numPrimaryVertices != other.numPrimaryVertices)
        return numPrimaryVertices < other.numPrimaryVertices;
      const std::less<MVertex *> less;
      for(std::size_t i = 0; i < vertices.size() && i < other.vertices.size();
          ++i) {
        if(less(vertices[i], other.vertices[i])) return true;
        if(less(other.vertices[i], vertices[i])) return false;
      }
      return vertices.size() < other.vertices.size();
    }
  };

  static ElementKey elementKey(MElement *e)
  {
    ElementKey key;
    if(!e) return key;
    key.dim = e->getDim();
    key.numPrimaryVertices = e->getNumPrimaryVertices();
    key.vertices.reserve(key.numPrimaryVertices);
    for(std::size_t i = 0; i < key.numPrimaryVertices; ++i)
      key.vertices.push_back(e->getVertex(i));
    std::sort(key.vertices.begin(), key.vertices.end(),
              std::less<MVertex *>());
    return key;
  }

  static void snapshotHighOrderProcessState(
    const std::set<MElement *, MElementPtrLessThan> &toProcess,
    const std::map<MElement *, double> *layers,
    std::set<ElementKey> &toProcessKeys, std::map<ElementKey, double> &layerKeys)
  {
    toProcessKeys.clear();
    layerKeys.clear();
    for(auto e : toProcess) toProcessKeys.insert(elementKey(e));
    if(layers) {
      for(const auto &entry : *layers) layerKeys[elementKey(entry.first)] =
        entry.second;
    }
  }

  static void remapHighOrderProcessState(
    GModel *m, const std::set<ElementKey> &toProcessKeys,
    const std::map<ElementKey, double> &layerKeys,
    std::set<MElement *, MElementPtrLessThan> &toProcessP2,
    std::map<MElement *, double> *layers)
  {
    toProcessP2.clear();
    std::map<MElement *, double> remappedLayers;

    std::vector<MElement *> elements;
    collectElements(m, elements);
    for(auto e : elements) {
      ElementKey key = elementKey(e);
      if(toProcessKeys.find(key) != toProcessKeys.end()) toProcessP2.insert(e);
      if(layers) {
        auto it = layerKeys.find(key);
        if(it != layerKeys.end()) remappedLayers[e] = it->second;
      }
    }

    if(layers) {
      layers->clear();
      layers->insert(remappedLayers.begin(), remappedLayers.end());
    }

    Msg::Info("High-order boundary layer: remapped %zu/%zu process elements "
              "and %zu/%zu layer entries after GModel::setOrderN",
              toProcessP2.size(), toProcessKeys.size(), remappedLayers.size(),
              layerKeys.size());
  }

  static void checkLowOrderBoundaryFaceSharing(
    GModel *m, const std::map<MElement *, double> *layers, const char *stage)
  {
    if(!m || m->firstRegion() == m->lastRegion()) return;

    std::set<MFace, MFaceLessThan> volumeFaces;
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i) {
        MElement *e = gr->getMeshElement(i);
        for(int j = 0; j < e->getNumFaces(); ++j)
          volumeFaces.insert(e->getFace(j));
      }
    }

    std::size_t numChecked = 0, numMissing = 0;
    std::size_t numLayerChecked = 0, numLayerMissing = 0;
    MElement *firstMissing = nullptr;
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i) {
        MElement *e = gf->getMeshElement(i);
        MFace mf = e->getFace(0);
        bool isLayer = layers && layers->find(e) != layers->end();
        numChecked++;
        if(isLayer) numLayerChecked++;
        if(volumeFaces.find(mf) == volumeFaces.end()) {
          numMissing++;
          if(isLayer) numLayerMissing++;
          if(!firstMissing) firstMissing = e;
        }
      }
    }

    if(numLayerMissing) {
      MFace mf = firstMissing->getFace(0);
      Msg::Warning("High-order boundary layer (%s): %zu P1 layer model faces "
                   "do not match any volume face; first missing face has "
                   "nodes %zu %zu %zu%s",
                   stage, numLayerMissing, mf.getVertex(0)->getNum(),
                   mf.getVertex(1)->getNum(), mf.getVertex(2)->getNum(),
                   mf.getNumVertices() == 4 ? " ..." : "");
    }
    Msg::Info("High-order boundary layer (%s): checked %zu P1 model faces "
              "(%zu in layers), missing volume matches %zu (%zu in layers)",
              stage, numChecked, numLayerChecked, numMissing, numLayerMissing);
  }

  static void writeDebugMesh(GModel *m, const char *name, const char *stage)
  {
    if(!m || !name) return;
    Msg::Info("High-order boundary layer: writing %s mesh to %s", stage, name);
    m->writeMSH(name, 4.1, false, true, false);
  }

  static bool checkHighOrderValidity(GModel *m, int dim, const char *stage)
  {
    if(!m || dim < 2 || dim > 3) return true;

    std::size_t numInverted = 0;
    std::size_t numSignChanging = 0;
    double globalMin = std::numeric_limits<double>::max();
    double globalMax = -std::numeric_limits<double>::max();
    MElement *worstElement = nullptr;
    int worstEntityTag = 0;
    std::vector<data_elementMinMax> data;
    std::vector<int> entityTags;

    auto checkElement = [&](GEntity *entity, MElement *el,
                            const fullMatrix<double> *normals) {
      if(el->getPolynomialOrder() <= 1) return;
      double minJ = 0., maxJ = 0.;
      jacobianBasedQuality::minMaxJacobianDeterminant(el, minJ, maxJ,
                                                      normals);
      data.push_back(data_elementMinMax(el, minJ, maxJ));
      entityTags.push_back(entity ? entity->tag() : 0);
    };

    if(dim == 2) {
      for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
        GFace *gf = *it;
        fullMatrix<double> *normals = nullptr;
        SVector3 n;
        if(gf->normalToPlanarMesh(n)) {
          normals = new fullMatrix<double>(1, 3);
          normals->set(0, 0, n(0));
          normals->set(0, 1, n(1));
          normals->set(0, 2, n(2));
        }
        for(std::size_t i = 0; i < gf->getNumMeshElements(); ++i)
          checkElement(gf, gf->getMeshElement(i), normals);
        if(normals) delete normals;
      }
    }
    else {
      for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
        GRegion *gr = *it;
        for(std::size_t i = 0; i < gr->getNumMeshElements(); ++i)
          checkElement(gr, gr->getMeshElement(i), nullptr);
      }
    }

    bezierCoeff::releasePools();

    if(data.empty()) return true;
    for(std::size_t i = 0; i < data.size(); ++i) {
      double minJ = data[i].minJ();
      double maxJ = data[i].maxJ();
      if(minJ < globalMin) {
        globalMin = minJ;
        globalMax = maxJ;
        worstElement = data[i].element();
        worstEntityTag = entityTags[i];
      }
      if(minJ < 0. && maxJ < 0.)
        numInverted++;
      else if(minJ <= 0. && maxJ >= 0.)
        numSignChanging++;
    }

    if(numSignChanging) {
      Msg::Warning("High-order boundary layer validity %s: NO-GO for %zu/%zu "
                   "%dD elements (inverted %zu); worst "
                   "element %d on entity %d has minJ %.16g maxJ %.16g",
                   stage, numSignChanging, data.size(), dim, numInverted,
                   worstElement ? worstElement->getNum() : 0, worstEntityTag,
                   globalMin, globalMax);
      return false;
    }

    Msg::Info("High-order boundary layer validity %s: GO for %zu %dD "
              "elements (%zu completely inverted by orientation convention, "
              "minJ %.16g, maxJ %.16g, worst element %d on entity %d)",
              stage, data.size(), dim, numInverted, globalMin, globalMax,
              worstElement ? worstElement->getNum() : 0, worstEntityTag);
    return true;
  }
} // namespace

bool untangleHighOrderBoundaryLayerPN(
  GModel *m, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed, int order,
  std::map<MElement *, double> *layers, const std::vector<double> *widths,
  int strategy, bool postSplitUntangle)
{
  if(order <= 1) return true;

  std::vector<MElement *> elements;
  collectElements(m, elements);
  checkLowOrderBoundaryFaceSharing(m, layers, "before P2 construction");

  Msg::Debug("High-order boundary layer untangler skeleton: order %d, "
             "%zu mesh elements, %zu moving-candidate elements, %zu fixed "
             "vertices",
             order, elements.size(), toProcess.size(), fixed.size());

  std::set<MElement *, MElementPtrLessThan> toProcessP2;
  if(order == 2) {
    validateP2PrismSubdivisionTables();

    std::set<ElementKey> toProcessKeys;
    std::map<ElementKey, double> layerKeys;
    snapshotHighOrderProcessState(toProcess, layers, toProcessKeys, layerKeys);

    Msg::Info("High-order boundary layer: calling GModel::setOrderN(%d, 0, "
              "0, 0)",
              order);
    if(!m->setOrderN(order, 0, 0, 0)) {
      Msg::Warning("High-order boundary layer: GModel::setOrderN failed");
      return false;
    }

    remapHighOrderProcessState(m, toProcessKeys, layerKeys, toProcessP2,
                               layers);
    checkHighOrderBoundaryFaceSharingP2(m, "after GModel::setOrderN");
    std::set<MVertex *, MVertexPtrLessThan> fixedRegionP2(fixed.begin(),
                                                          fixed.end());
    if(m->firstRegion() != m->lastRegion()) {
      std::size_t numFixedHighOrderFaceNodes =
        collectHighOrderFaceNodes(m, fixedRegionP2);
      if(numFixedHighOrderFaceNodes)
        Msg::Info("High-order boundary layer: fixed %zu high-order nodes on "
                  "model faces for 3D untangling",
                  numFixedHighOrderFaceNodes);
    }
    if(strategy == 2 && layers && widths) {
      Msg::Info("High-order boundary layer: untangling large P2 elements "
                "before parametric layer splitting");
      for(auto it = m->firstFace(); it != m->lastFace(); ++it)
        prepareFaceUntanglerP2(*it, toProcessP2, fixed, false);
      checkHighOrderBoundaryFaceSharingP2(m, "after face untangling");
      const bool hasRegions = m->firstRegion() != m->lastRegion();
      if(hasRegions) {
        writeDebugMesh(m, "highOrderBL_before_volume_untangle.msh",
                       "before P2 volume untangling");
        for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
          prepareRegionUntanglerP2(*it, toProcessP2, fixedRegionP2);
        splitHighOrderVolumesParametricP2(m, *layers, *widths, toProcessP2);
        checkHighOrderBoundaryFaceSharingP2(m, "after reference-space "
                                               "volume splitting");
        if(postSplitUntangle) {
          Msg::Info("High-order boundary layer: post-split 3D untangling "
                    "enabled");
          fixedRegionP2.insert(fixed.begin(), fixed.end());
          collectHighOrderFaceNodes(m, fixedRegionP2);
          writeDebugMesh(m, "highOrderBL_before_post_split_volume_untangle.msh",
                         "before post-split P2 volume untangling");
          for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
            prepareRegionUntanglerP2(*it, toProcessP2, fixedRegionP2);
          checkHighOrderBoundaryFaceSharingP2(m, "after split volume "
                                                 "untangling");
        }
        else {
          Msg::Info("High-order boundary layer: using reference-space split "
                    "of large P2 volume elements without post-split 3D "
                    "untangling");
        }
      }
      else {
        splitHighOrderQuadsParametricP2(m, *layers, *widths, toProcessP2);
        for(auto it = m->firstFace(); it != m->lastFace(); ++it)
          prepareFaceUntanglerP2(*it, toProcessP2, fixed, true);
        checkHighOrderBoundaryFaceSharingP2(m, "after parametric splitting");
      }
    }
    else {
      for(auto it = m->firstFace(); it != m->lastFace(); ++it)
        prepareFaceUntanglerP2(*it, toProcessP2, fixed, false);
      checkHighOrderBoundaryFaceSharingP2(m, "after face untangling");
      writeDebugMesh(m, "highOrderBL_before_volume_untangle.msh",
                     "before P2 volume untangling");
      for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
        prepareRegionUntanglerP2(*it, toProcessP2, fixedRegionP2);
      checkHighOrderBoundaryFaceSharingP2(m, "after volume untangling");
    }
  }

  const int modelDim = m->getDim();
  if(modelDim >= 2)
    return checkHighOrderValidity(m, modelDim,
                                  "after high-order boundary layer");

  return true;
}

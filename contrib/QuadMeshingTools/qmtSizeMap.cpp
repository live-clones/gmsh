// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmtSizeMap.h"

/* System includes */
#include <vector>
#include <array>
#include <unordered_map>
#include <cstdint>
#include <cmath>
#include <queue>
#include <algorithm>

/* Gmsh includes */
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "Context.h"
#include "MLine.h"
#include "MTriangle.h"
#include "BackgroundMesh.h"
#include "gmsh.h" // debug

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"

using namespace CppUtils;

namespace QMT {

  void setMinimum(MVertex *v, std::unordered_map<MVertex *, double> &minSize,
                  double value)
  {
    auto it = minSize.find(v);
    if(it == minSize.end()) { minSize[v] = value; }
    else if(value < it->second) {
      it->second = value;
    }
  }

  inline double distance2(const SPoint3 &a, const SPoint3 &b)
  {
    const double dx = a.x() - b.x();
    const double dy = a.y() - b.y();
    const double dz = a.z() - b.z();
    return dx * dx + dy * dy + dz * dz;
  }

  inline double distance_point_segment_squared(const SPoint3 &query,
                                               const SPoint3 &a,
                                               const SPoint3 &b)
  {
    const double l2 = distance2(a, b);
    const double t = dot(query - a, b - a);
    if(t <= 0. || l2 == 0.) { return distance2(query, a); }
    else if(t > l2) {
      return distance2(query, b);
    }
    const double lambda = 1. - t / l2;
    SPoint3 proj(lambda * a + (1. - lambda) * b);
    return distance2(query, proj);
  }

  double distanceToLines(const SPoint3 &query, const std::vector<MLine> &lines)
  {
    // warning: not very efficient ...
    double mdist2 = DBL_MAX;
    for(const MLine &l : lines) {
      const MVertex *v1 = l.getVertex(0);
      const MVertex *v2 = l.getVertex(1);
      mdist2 = std::min(mdist2, distance_point_segment_squared(
                                  query, v1->point(), v2->point()));
    }
    return std::sqrt(mdist2);
  }

  double distanceToGEdgeBackgroundMesh(const SPoint3 &query,
                                       GlobalBackgroundMesh &gbm, GEdge *ge)
  {
    auto it = gbm.edgeBackgroundMeshes.find(ge);
    if(it == gbm.edgeBackgroundMeshes.end()) {
      Msg::Error(
        "curve %i not found in background mesh, cannot compute distance to it",
        ge->tag());
      return DBL_MAX;
    }
    return distanceToLines(query, it->second.lines);
  }
} // namespace QMT

using namespace QMT;

int computeMinimalSizeOnCurves(GlobalBackgroundMesh &gbm,
                               bool clampMinWithTriEdges,
                               std::unordered_map<MVertex *, double> &minSize)
{
  Msg::Debug("compute minimal size on curves (using background mesh) ...");
  /* Important information: all mesh elements are queried in the
   * GlobalBackgroundMesh, not in the current GModel ! */

  GModel *gm = gbm.gm;
  if(gm == NULL) return -1;

  /* Initialize minimal size on vertex associated to GVertex
   * prescribed size */
  for(MVertex *v : gbm.mesh_vertices) {
    GVertex *gv = dynamic_cast<GVertex *>(v->onWhat());
    if(gv == NULL) continue;
    /* Mesh size */
    double size = gv->prescribedMeshSizeAtVertex();
    if(size > 0 && size < 1.e22) setMinimum(v, minSize, size);
  }

  std::unordered_map<GVertex *, std::vector<GEdge *> > gv2ge;
  for(GEdge *ge : model_edges(gm))
    for(GVertex *gv : ge->vertices()) { gv2ge[gv].push_back(ge); }
  for(auto &kv : gv2ge) sort_unique(kv.second);

  /* On curve vertices, minimum size is minimum of:
   * - existing size
   * - curve length
   * - distance of projection to non adjacent curves */
  for(GFace *gf : model_faces(gm)) {
    for(GEdge *ge : face_edges(gf)) {
      auto it = gbm.edgeBackgroundMeshes.find(ge);
      if(it == gbm.edgeBackgroundMeshes.end()) {
        Msg::Error("curve %i not found in background mesh", ge->tag());
        continue;
      }

      /* Collect curve vertices, including extremities */
      std::vector<MVertex *> curve_vertices;
      for(MLine &e : it->second.lines)
        for(size_t lv : {0, 1}) {
          MVertex *v = e.getVertex(lv);
          curve_vertices.push_back(v);
        }
      sort_unique(curve_vertices);

      /* Collect non-adjacent curves */
      std::vector<GEdge *> curvesAjacent;
      for(GVertex *gv : ge->vertices()) {
        for(GEdge *ge2 : gv2ge[gv])
          if(ge2 != ge) {
            curvesAjacent.push_back(ge2);

            if(ge2->length() <=
               CTX::instance()->geom.tolerance) { /* yes CAD is annoying ... */
              for(GVertex *gv2 : ge2->vertices()) {
                for(GEdge *ge3 : gv2ge[gv2])
                  if(ge3 != ge) { curvesAjacent.push_back(ge3); }
              }
            }
          }
      }
      sort_unique(curvesAjacent);

      std::vector<GEdge *> curvesNotAdjacent;
      for(GFace *gf : ge->faces())
        for(GEdge *ge2 : gf->edges())
          if(ge2 != ge) { curvesNotAdjacent.push_back(ge2); }
      curvesNotAdjacent = difference(curvesNotAdjacent, curvesAjacent);
      sort_unique(curvesNotAdjacent);

      double len = ge->length();
      for(MVertex *v : curve_vertices) {
        double vMin = len; /* curve length */

        /* Size: minimum of projection to non-adj curves */
        for(GEdge *ge2 : curvesNotAdjacent) {
          /* Warning: testing all MLine, slow, should have kdtree acceleration
           */
          double dist = distanceToGEdgeBackgroundMesh(v->point(), gbm, ge2);
          if(vMin > 0) vMin = std::min(vMin, dist);
        }

        if(vMin > 0 && vMin < 1.e22) setMinimum(v, minSize, vMin);
      }
    }
  }

  if(clampMinWithTriEdges) {
    for(GFace *gf : model_faces(gm)) {
      auto it = gbm.faceBackgroundMeshes.find(gf);
      if(it == gbm.faceBackgroundMeshes.end()) {
        Msg::Error("face %i not found in background mesh", gf->tag());
        continue;
      }
      for(MTriangle &t : it->second.triangles)
        for(size_t le = 0; le < 3; ++le) {
          MVertex *v1 = t.getVertex(le);
          MVertex *v2 = t.getVertex((le + 1) % 3);
          double len = v1->distance(v2);
          if(v1->onWhat()->cast2Face() == nullptr) {
            auto itv = minSize.find(v1);
            if(itv != minSize.end()) {
              itv->second = std::max(itv->second, len);
            }
          }
        }
    }
  }

  return 0;
}

int sizeMapOneWaySmoothing(const std::vector<MTriangle *> &triangles,
                           std::unordered_map<MVertex *, double> &values,
                           double gradientMax)
{
  Msg::Debug(
    "one way smoothing of scalar field (%li triangles, %li values) ...",
    triangles.size(), values.size());
  if(triangles.size() == 0) return -1;
  if(gradientMax <= 0.) return -1;

  std::unordered_map<MVertex *, std::vector<MVertex *> > v2v;
  buildVertexToVertexMap(triangles, v2v);

  std::priority_queue<std::pair<double, MVertex *>,
                      std::vector<std::pair<double, MVertex *> >,
                      std::greater<std::pair<double, MVertex *> > >
    Q;
  for(const auto &kv : values) { Q.push({kv.second, kv.first}); }

  /* Dijkstra propagation */
  while(Q.size() > 0) {
    MVertex *v = Q.top().second;
    double cdist = Q.top().first;
    Q.pop();
    for(MVertex *v2 : v2v[v]) {
      double w_ij = v->distance(v2) * (gradientMax - 1.);
      auto it = values.find(v2);
      if(it == values.end() || cdist + w_ij < it->second) {
        double new_value = cdist + w_ij;
        auto it2 = values.find(v2);
        if(it2 != values.end() && new_value > it2->second) {
          /* No need to propagate in regions where sizemap is
           * already sufficiently fine */
          continue;
        }
        values[v2] = new_value;
        Q.push({new_value, v2});
      }
    }
  }

  return 0;
}

void quantileFiltering(std::unordered_map<MVertex *, double> &scaling,
                       double critera)
{
  std::vector<double> values(scaling.size());
  size_t count = 0;
  for(auto &kv : scaling) {
    values[count] = kv.second;
    count += 1;
  }
  std::sort(values.begin(), values.end());
  size_t n = values.size();
  double clamp_min = values[size_t(critera * double(n))];
  double clamp_max = values[size_t((1. - critera) * double(n))];
  for(auto &kv : scaling) {
    if(kv.second < clamp_min) { kv.second = clamp_min; }
    else if(kv.second > clamp_max) {
      kv.second = clamp_max;
    }
  }
}

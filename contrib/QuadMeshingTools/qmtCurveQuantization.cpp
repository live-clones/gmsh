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
#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "meshGEdge.h"
#include "BackgroundMesh.h"
#include "gmsh.h" // debug

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

using namespace CppUtils;
using namespace ArrayGeometry;

using std::pair;
using std::unordered_map;
using std::vector;

namespace QMT {
  constexpr int UNASSIGNED = -1;
  constexpr int START = -2;

  vec3 gedgeCenter(GEdge *ge)
  {
    double t = 0.5 * (ge->parBounds(0).low() + ge->parBounds(0).high());
    GPoint p = ge->point(t);
    return {p.x(), p.y(), p.z()};
  }

  /* See Campen et al. 2015 */
  inline double quantization_weigth(const int node,
                                    const vector<double> &x_ideal,
                                    const vector<int> &n)
  {
    const size_t Ne = n.size();
    double current = (n[node] == UNASSIGNED) ? 0. : double(n[node]);
    const double dp = x_ideal[node] - current;
    if(1. <= dp) { return 1. / (dp + 1.); }
    else if(0. <= dp && dp < 1.) {
      return Ne / (dp + 1.);
    }
    else if(dp < 0.) {
      return Ne * Ne / (1. - dp);
    }
    return DBL_MAX;
  }

  bool DBGPRINT = false;

  bool tchordPropagation(const vector<vector<vector<int> > > &node2side2nodes,
                         int nodeInit, const vector<int> &n,
                         const vector<double> &x_ideal, vector<int> &tchord)
  {
    std::vector<int> parent(node2side2nodes.size(), UNASSIGNED);
    std::vector<int> initialSide(node2side2nodes.size(), UNASSIGNED);

    std::priority_queue<std::pair<double, int>,
                        std::vector<std::pair<double, int> > >
      Q;
    parent[nodeInit] = START;
    Q.push({DBL_MAX, nodeInit});

    std::vector<int> initialSideEnding(node2side2nodes[nodeInit].size(),
                                       UNASSIGNED);
    if(initialSideEnding.size() == 0 || initialSideEnding.size() > 2) {
      Msg::Error("wrong number of initial sides: %li",
                 initialSideEnding.size());
      return false;
    }

    while(Q.size() > 0) {
      int node = Q.top().second;
      Q.pop();
      int parentNode = parent[node];
      if(parentNode == UNASSIGNED) {
        Msg::Error("parent not defined for node, should not happen");
        return false;
      }

      int currentInitialSide = initialSide[node];
      if(currentInitialSide != UNASSIGNED &&
         initialSideEnding[currentInitialSide] != UNASSIGNED) {
        if(DBGPRINT) {
          DBG(nodeInit, node, parentNode, currentInitialSide,
              "side finished, continue");
        }
        continue;
      }
      if(DBGPRINT) { DBG(nodeInit, node, parentNode, currentInitialSide); }

      /* Propagate on side which is not the origin (i.e. contains the parent) */
      bool prop = false;
      for(size_t s = 0; s < node2side2nodes[node].size(); ++s) {
        if(node == nodeInit) currentInitialSide = s; /* first time */

        auto &sideNodes = node2side2nodes[node][s];

        if(DBGPRINT) {
          DBG(nodeInit, node, parentNode, currentInitialSide, s, sideNodes);
        }

        if(inVector(parentNode, sideNodes)) continue;

        for(auto &node2 : sideNodes) {
          if(DBGPRINT) { DBG("   ", node2, parent[node2]); }
          if(parent[node2] != UNASSIGNED) continue; /* already visited */
          double w = quantization_weigth(node2, x_ideal, n);
          parent[node2] = node;
          initialSide[node2] = currentInitialSide;
          Q.push({w, node2});
          prop = true;
          if(DBGPRINT) { DBG("   +", node2, w); }
        }
      }
      if(!prop && currentInitialSide != UNASSIGNED &&
         initialSideEnding[currentInitialSide] == UNASSIGNED) {
        initialSideEnding[currentInitialSide] = node;
        if(DBGPRINT) { DBG(currentInitialSide, "end on", node); }
      }
    }

    /* Check endings of propagation */
    if(DBGPRINT) { DBG(initialSideEnding); }
    for(int &ending : initialSideEnding)
      if(ending == UNASSIGNED) {
        if(DBGPRINT) { DBG("return false"); }
        return false;
      }

    /* Unroll sides */
    tchord.clear();
    for(int &ending : initialSideEnding) {
      int node = ending;
      while(node != START) {
        tchord.push_back(node);
        node = parent[node];
      }
    }
    sort_unique(tchord);

    return true;
  }

  bool solveQuantizationWithGreedyApproach(
    const vector<pair<vector<GEdge *>, vector<GEdge *> > > &oppositeSides,
    const unordered_map<GEdge *, double> &x_ideal,
    unordered_map<GEdge *, int> &x)
  {
    vector<pair<vector<int>, vector<int> > > oppositeSideTags(
      oppositeSides.size());
    ;
    for(size_t i = 0; i < oppositeSides.size(); ++i) {
      for(size_t j = 0; j < oppositeSides[i].first.size(); ++j) {
        oppositeSideTags[i].first.push_back(oppositeSides[i].first[j]->tag());
      }
      for(size_t j = 0; j < oppositeSides[i].second.size(); ++j) {
        oppositeSideTags[i].second.push_back(oppositeSides[i].second[j]->tag());
      }
    }

    int count = 0;
    unordered_map<GEdge *, int> old2new;
    vector<GEdge *> new2old;
    for(auto &kv : oppositeSides) {
      for(GEdge *ge : merge(kv.first, kv.second)) {
        auto it = old2new.find(ge);
        if(it == old2new.end()) {
          old2new[ge] = count;
          new2old.push_back(ge);
          count += 1;
        }
      }
    }

    /* Build continuous data */
    vector<double> c_x_ideal(count, 0.);
    for(auto &kv : x_ideal) { c_x_ideal[old2new[kv.first]] = kv.second; }

    /* In the dual graph,
     * - a GEdge is a node
     * - the opposite GEdge in a GFace are edges */
    vector<vector<vector<int> > > node2side2nodes(count);
    for(auto &kv : oppositeSides) {
      /* Create a new side for each node */
      for(GEdge *ge : merge(kv.first, kv.second)) {
        int node = old2new[ge];
        node2side2nodes[node].resize(node2side2nodes[node].size() + 1);
      }

      /* Fill the side with the opposite nodes */
      for(GEdge *ge1 : kv.first) {
        int node1 = old2new[ge1];
        for(GEdge *ge2 : kv.second) {
          int node2 = old2new[ge2];

          node2side2nodes[node1].back().push_back(node2);
          node2side2nodes[node2].back().push_back(node1);
        }
      }
    }

    /* Greedy assignement in the graph */
    vector<int> n(count, UNASSIGNED);
    vector<int> tchord;
    int EXISTING_TRANSFINITE = 0;
    int OTHERS = 1;
    for(int pass : {EXISTING_TRANSFINITE, OTHERS}) {
      /* Order the unassigned edges, shorter ideal length first */
      std::priority_queue<std::pair<double, int>,
                          std::vector<std::pair<double, int> >,
                          std::greater<std::pair<double, int> > >
        Q;
      if(pass == EXISTING_TRANSFINITE) {
        for(int e0 = 0; e0 < count; ++e0)
          if(n[e0] == UNASSIGNED) {
            if(new2old[e0]->meshAttributes.method == MESH_TRANSFINITE) {
              Q.push({c_x_ideal[e0], e0});
            }
          }
      }
      else {
        for(int e0 = 0; e0 < count; ++e0)
          if(n[e0] == UNASSIGNED) { Q.push({c_x_ideal[e0], e0}); }
      }

      while(Q.size() > 0) {
        int e0 = Q.top().second;
        Q.pop();
        if(n[e0] != UNASSIGNED) continue;
        tchord.clear();
        bool ok = tchordPropagation(node2side2nodes, e0, n, c_x_ideal, tchord);
        if(!ok || tchord.size() == 0) continue;

        vector<int> nLinesImposedFromTransfinite;
        double avgDiff = 0.;
        double minDiff = DBL_MAX;
        double maxDiff = 0.;
        for(int e : tchord) {
          double current = (n[e] == UNASSIGNED) ? 0. : double(n[e]);
          avgDiff += (c_x_ideal[e] - current);
          minDiff = std::min(minDiff, c_x_ideal[e] - current);
          maxDiff = std::max(maxDiff, c_x_ideal[e] - current);
          if(new2old[e]->meshAttributes.method == MESH_TRANSFINITE) {
            nLinesImposedFromTransfinite.push_back(
              new2old[e]->meshAttributes.nbPointsTransfinite - 1);
          }
        }
        avgDiff /= double(tchord.size());
        int increment = 0;
        sort_unique(nLinesImposedFromTransfinite);
        if(nLinesImposedFromTransfinite.size() == 1) {
          increment = nLinesImposedFromTransfinite[0];
        }
        else if(nLinesImposedFromTransfinite.size() > 1) {
          Msg::Error(
            "curve quantization: incoherent imposed transfinite constraints");
          continue;
        }
        else {
          increment = int(std::round(minDiff));
          if(increment <= 0.) increment = 1;
        }
        DBG(tchord, increment);
        for(int e : tchord) {
          if(n[e] == UNASSIGNED) { n[e] = increment; }
          else {
            n[e] += increment;
          }
        }

        // int e0tag = new2old[e0]->tag();
        // vector<int> tchordTags;
        // for (int a: tchord) tchordTags.push_back(new2old[a]->tag());
        // DBG(e0tag, ok, tchordTags, avgDiff, increment);
        // {
        //   for (int a: tchord) {
        //     vec3 pt = gedgeCenter(new2old[a]);
        //     GeoLog::add({pt},0.,"chord_"+std::to_string(e0tag));
        //   }
        // }
      }
    }

    GeoLog::flush();

    DBG(c_x_ideal);
    DBG(n);

    for(size_t i = 0; i < n.size(); ++i)
      if(n[i] > 0) { x[new2old[i]] = n[i]; }

    return true;
  }
} // namespace QMT

const std::string BMESH_NAME = "bmesh_quadqs";

int initialCurveQuantization(
  GModel *gm, double maxDiffNbLines,
  std::unordered_map<GFace *, vector<GVertex *> > &faceCorners)
{
  std::vector<GFace *> faces = model_faces(gm);
  std::vector<GEdge *> edges = model_edges(gm);

  Msg::Debug("initial curve quantization (%li curves) ...", edges.size());

  /* Collect opposite sides in the CAD */
  vector<pair<vector<GEdge *>, vector<GEdge *> > > oppositeSides;
  std::unordered_map<GEdge *, double> x_ideal;

  for(GFace *gf : faces) {
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if(CTX::instance()->debugSurface > 0 &&
       gf->tag() != CTX::instance()->debugSurface)
      continue;

    GFaceInfo info;
    bool okf = fillGFaceInfo(gf, info);
    if(!okf) {
      Msg::Debug("initial curve quantization: no triangles available");
      return -1;
    }

    std::vector<std::vector<std::vector<std::pair<GEdge *, bool> > > >
      loopSideEdgesAndInv;
    bool oksl = faceOrderedSideLoops(gf, info, loopSideEdgesAndInv);
    if(!oksl) {
      Msg::Debug("initial curve quantization: failed to get face ordered side "
                 "loops for face %i",
                 gf->tag());
      continue;
    }

    DBG(isTopologicalDisk(info), haveConcaveCorners(info),
        info.bdrValVertices[1].size());

    /* Rectangular face with 4 convex corners */
    if(isTopologicalDisk(info) && !haveConcaveCorners(info) &&
       info.bdrValVertices[1].size() == 4) {
      vector<pair<vector<GEdge *>, vector<GEdge *> > > GFoppositeSides;
      size_t NS = 0;
      for(size_t k = 0; k < 2; ++k) { /* direction */
        double len_a = 0.;
        double len_b = 0.;
        int nl_a = 0;
        int nl_b = 0;
        size_t Na = 0;
        size_t Nb = 0;
        vector<GEdge *> side_a;
        vector<GEdge *> side_b;
        for(auto &kv : loopSideEdgesAndInv[0][k]) {
          GEdge *ge = kv.first;
          len_a += ge->length();
          int npts = meshGEdgeTargetNumberOfPoints(ge);
          if(npts >= 2) {
            nl_a += (npts - 1);
            auto it = x_ideal.find(ge);
            if(it == x_ideal.end()) x_ideal[ge] = double(nl_a);
          }
          Na += 1;
          side_a.push_back(ge);
        }
        for(auto &kv : loopSideEdgesAndInv[0][k + 2]) {
          GEdge *ge = kv.first;
          len_b += ge->length();
          int npts = meshGEdgeTargetNumberOfPoints(ge);
          if(npts >= 2) {
            nl_b += (npts - 1);
            auto it = x_ideal.find(ge);
            if(it == x_ideal.end()) x_ideal[ge] = double(nl_b);
          }
          Nb += 1;
          side_b.push_back(ge);
        }

        if(len_a == 0 || len_b == 0) continue;

        /* Check the difference in terms of number of lines */
        double nl_diff_rel =
          std::abs(double(nl_a - nl_b)) / (double(std::max(nl_a, nl_b)));
        double len_diff_rel =
          std::abs(double(len_a - len_b)) / (double(std::max(len_a, len_b)));
        if(nl_diff_rel <= maxDiffNbLines) {
          /* Want equality on opposite sides */
          GFoppositeSides.push_back({side_a, side_b});
          NS += 1;
        }
      }

      if(NS == 2) { /* transfinite face, both direction equal */
        std::vector<GVertex *> corners;
        for(size_t k = 0; k < 4; ++k) {
          for(auto &kv : loopSideEdgesAndInv[0][k]) {
            GEdge *ge = kv.first;
            bool inv = kv.second;
            GVertex *gv1 = inv ? ge->vertices()[1] : ge->vertices()[0];
            bool isCorner1 = std::find(info.bdrValVertices[1].begin(),
                                       info.bdrValVertices[1].end(),
                                       gv1) != info.bdrValVertices[1].end();
            if(isCorner1) { corners.push_back(gv1); }
          }
        }
        if(corners.size() != 4) {
          Msg::Debug("curve quantization: face %i, wrong number of corners",
                     gf->tag());
          continue;
        }
        append(oppositeSides, GFoppositeSides);
        faceCorners[gf] = corners;
      }
    }
  }

  if(oppositeSides.size() == 0) return 0;

  unordered_map<GEdge *, int> n;
  bool okq =
    QMT::solveQuantizationWithGreedyApproach(oppositeSides, x_ideal, n);
  if(!okq) {
    Msg::Error("failed to solve quantization with greedy approach");
    return -1;
  }

  /* Transfinite constraints on curve */
  for(auto &kv : n) {
    if(kv.second > 0) {
      GEdge *ge = kv.first;
      int nLines = kv.second;
      if(ge->meshAttributes.method != MESH_TRANSFINITE) {
        ge->meshAttributes.method = MESH_TRANSFINITE;
        ge->meshAttributes.typeTransfinite = 4; /* use size map for positions */
        ge->meshAttributes.nbPointsTransfinite = nLines + 1;
        Msg::Debug("- set transfinite on curve %i (%i points)", ge->tag(),
                   nLines + 1);
      }
    }
  }

  return 0;
}

int setQuadqsTransfiniteConstraints(GModel *gm, double maxDiffNbLines)
{
  Msg::Debug("set quadqs transfinite constraints ...");

  std::unordered_map<GFace *, vector<GVertex *> > faceCorners;

  int si = initialCurveQuantization(gm, maxDiffNbLines, faceCorners);
  if(si != 0) return si;

  for(GFace *gf : gm->getFaces()) {
    bool allTransfi = true;
    for(GEdge *ge : gf->edges()) {
      if(ge->meshAttributes.method != MESH_TRANSFINITE) allTransfi = false;
    }
    if(allTransfi) {
      gf->meshAttributes.method = MESH_TRANSFINITE;
      gf->meshAttributes.transfiniteArrangement = 1; /* Right */
      gf->meshAttributes.recombine = 1;
      gf->meshAttributes.recombineAngle = 45.;
      auto it = faceCorners.find(gf);
      if(it != faceCorners.end()) {
        std::vector<GVertex *> corners = it->second;
        gf->meshAttributes.corners = corners; /* warning: must be ordered ! */
      }
      Msg::Debug("- set transfinite on surface %i", gf->tag());
    }
  }

  return 0;
}

// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "quad_meshing_tools.h"

#include <cfloat>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <string>
#include <sstream>
#include <iostream>

#include "gmsh.h"
#include "qmt_utils.hpp"

/* - Shortcuts for loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)

using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;
using gmsh::vectorpair;

using Chord = std::vector<QMT::id>;

namespace QMT_SMO_Utils {
  using namespace QMT;
  using namespace QMT_Utils;


  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Smoothing | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Smoothing | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Smoothing | " + stream.str(), "info");
    }
  /************************************/

  bool getOrderedVerticesFromEdges(id vStart, const vector<id2>& edges, vector<id>& orderedVertices) {
    orderedVertices.clear();
    id eStart = NO_ID;
    id lvStart = NO_ID;
    F(e,edges.size()) FC(lv,2,edges[e][lv] == vStart) {
      eStart = e;
      lvStart = lv;
      break;
    }
    if (eStart == NO_ID) return false;

    size_t iter = 0;
    id e = eStart;
    id v = vStart;
    while (true) {
      iter += 1;
      if (iter > 100000) {
        error("infinite loop ? iter = {}", iter);
        return false;
      }
      orderedVertices.push_back(v);
      id next_v = (edges[e][0]  != v) ? edges[e][0] : edges[e][1];
      if (next_v == vStart) { /* closed chain */
        break;
      }
      id next_e = NO_ID;
      FC(ee,edges.size(),ee!=e) FC(lv,2,edges[ee][lv] == next_v) {
        next_e = ee;
        break;
      }
      if (next_e == NO_ID) { /* open chain */
        orderedVertices.push_back(next_v);
        break;
      }
      v = next_v;
      e = next_e;
    }
    return true;
  }

}


namespace QMT {
  using namespace QMT_Utils;
  using namespace QMT_SMO_Utils;

  inline vec3 winslow2DNewPosition(const vec3 ptsStencil[8]) {
    /* Stencil:
     *   6---1---4
     *   |   |   |
     *   2--- ---0
     *   |   |   |
     *   7---3---5
     */
    /* warning: 2D stencil but 3D coordinates */
    double hx = 1.;
    double hy = 1.;

    /* 1. Compute the winslow coefficients (alpha_i, beta_i in the Karman paper) */
    /*    a. Compute first order derivatives of the position */
    vec3 r_i[2];
    r_i[0] = 1./hx * (ptsStencil[0] - ptsStencil[2]);
    r_i[1] = 1./hy * (ptsStencil[1] - ptsStencil[3]);
    /*    b. Compute the alpha_i coefficients */
    double alpha_0 = dot(r_i[1],r_i[1]);
    double alpha_1 = dot(r_i[0],r_i[0]);
    /*    c. Compute the beta coefficient */
    double beta =  dot(r_i[0],r_i[1]);

    /* cross derivative */
    vec3 u_xy = 1./(4.*hx*hy) * (ptsStencil[4]+ptsStencil[7]-ptsStencil[6]-ptsStencil[5]);

    /* 2. Compute the "winslow new position" */
    double denom = 2. * alpha_0 / (hx*hx) + 2. * alpha_1 / (hy*hy);
    vec3 newPos = 1. / denom * (
          alpha_0/(hx*hx) * (ptsStencil[0] + ptsStencil[2])
        + alpha_1/(hy*hy) * (ptsStencil[1] + ptsStencil[3])
        - 2. * beta * u_xy
        );

    return newPos;
  }

  vec3 project_point_on_curve(vec3 p, const vector<vec3>& curve) {
    vec3 proj = {DBL_MAX,DBL_MAX,DBL_MAX};
    if (curve.size() < 2) {
      error("cannot project on curve, size = {}", curve.size());
      return proj;
    }
    double dmin2 = DBL_MAX;
    F(i,curve.size()-1) {
      vec3 a = curve[i];
      vec3 b = curve[i+1];
      double l2 = length2(a - b);
      double t = dot(p - a, b - a) / l2;
      t = std::max(0., std::min(1., t));
      vec3 cproj = a + t * (b - a);
      double len2 = length2(cproj-p);
      if (len2 < dmin2) {
        proj = cproj;
        dmin2 = len2;
      }
    }
    return proj;
  }



  bool smooth_quad_mesh(QMesh& M, size_t iter_max,
      const BoundaryProjector* projector) {
    info("winslow smoothing (explicit, {} iterations) ...", iter_max);
    if (projector != NULL) info("- projector available, using iterative projection on surfaces and curves");


    vector<vector<id>> v2v(M.points.size());
    vector<vector<id>> v2quads(M.points.size());
    FC(q,M.quads.size(),M.quads[q][0] != NO_ID) {
      F(lv,4) v2quads[M.quads[q][lv]].push_back(q);
      F(le,4) {
        v2v[M.quads[q][le]].push_back(M.quads[q][(le+1)%4]);
        v2v[M.quads[q][(le+1)%4]].push_back(M.quads[q][le]);
      }
    }
    F(v,M.points.size()) sort_unique(v2quads[v]);
    F(v,M.points.size()) sort_unique(v2v[v]);



    /* Build the vertex stencils */
    vector<id> stencils(8*M.points.size(),NO_ID);
    F(v,M.points.size()) {
      if (v2quads[v].size() == 4) {
        vector<id2> edges;
        F(lq,4) F(lv,4) {
          id v2 = M.quads[v2quads[v][lq]][lv];
          id v3 = M.quads[v2quads[v][lq]][(lv+1)%4];
          if (v2 != v && v3 != v) edges.push_back({v2,v3});
        }
        if (edges.size() != 8) {
          error("wrong nb of edges: {}", edges);
          return false;
        }
        vector<id> orderedVertices;
        bool oko = getOrderedVerticesFromEdges(v2v[v][0], edges, orderedVertices);
        if (!oko || orderedVertices.size() != 8) {
          error("failed to get a stencil, v = {}, v2quads[v].size()={}, orderedVertices = {}", v, v2quads[v].size(), orderedVertices);
          return false;
        }
        F(k,8) stencils[8*v+k] = orderedVertices[k];
      } else if (v2quads[v].size() == 2) { // TODO: do the same for feature curves !
        if (M.entity[v].first != 1) { /* Valence 2 but not on curve ? */
          int dim = 1;
          int tag = -1;
          double dist;
          bool okc = projector->closestEntity({M.points[v]}, dist, dim, tag);
          if (!okc || dim == -1 || tag == -1) {
            warn("failed to find closest entity for v = {}, okc = {}, dim = {}, tag = {}", v, okc, dim, tag);
          } else {
            M.entity[v] = {dim,tag};
            warn(" v = {}, pt = {}, v2quads[v].size()={}, M.entity[v]={} corrected to {}",v,M.points[v],v2quads[v].size(),M.entity[v], std::make_pair(dim,tag));
          }
        }
        vector<id2> edges;
        F(lq,2) F(le,4) {
          id v2 = M.quads[v2quads[v][lq]][le];
          id v3 = M.quads[v2quads[v][lq]][(le+1)%4];
          if (v2 != v && v3 != v) {
            edges.push_back({v2,v3});
          } else if (M.quad_neighbors[v2quads[v][lq]][le] == NO_SID) {
            edges.push_back({v2,v3});
          }
        }
        if (edges.size() != 6) {
          error("wrong nb of edges: {}", edges);
          return false;
        }
        vector<id> orderedVertices;
        bool oko = getOrderedVerticesFromEdges(v, edges, orderedVertices);
        if (!oko || orderedVertices.size() != 6) {
          error("failed to get a stencil, v = {}, v2quads[v].size()={}, orderedVertices = {}", v, v2quads[v].size(), orderedVertices);
          return false;
        }
        F(k,6) stencils[8*v+k] = orderedVertices[k];
      }
    }

    /* Explicit smoothing loop */
    F(k, iter_max) {
      if (k >= 50 && k % (iter_max / 10) == 0) info("  {} / {} iter", k, iter_max);

      /* A. Winslow smoothing of interior vertices */
      FC(v,M.points.size(),M.entity[v].first == 2) {
        if (v2v[v].size() < 3) {
          continue;
        } else if (v2v[v].size() == 4) {
          vec3 ptsStencil[8];
          F(k,8) ptsStencil[k] = M.points[stencils[8*v+k]];

          /* Stencil for Winslow smoothin (different from ordering in stencils[]):
           *   6---1---4
           *   |   |   |
           *   2--- ---0
           *   |   |   |
           *   7---3---5
           */
          vec3 ptsStencilR[8] = {
            ptsStencil[0],
            ptsStencil[2],
            ptsStencil[4],
            ptsStencil[6],
            ptsStencil[1],
            ptsStencil[7],
            ptsStencil[3],
            ptsStencil[5]
          };

          M.points[v] = winslow2DNewPosition(ptsStencilR);
        } else {
          vec3 avg = {0,0,0};
          F(lv,v2v[v].size()) {
            avg = avg + M.points[v2v[v][lv]];
          }
          avg  = avg * double(1. / v2v[v].size());
          M.points[v] = avg;
        }
        /* Projection on surface */
        if (projector != NULL && M.entity[v].second != -1) {
          vec3 proj;
          bool okp = projector->project(M.entity[v].first,M.entity[v].second,M.points[v],proj);
          if (okp) {
            if (proj[0] == DBL_MAX) {
              error("wrong projected point: {}", proj);
              continue;
            }
            M.points[v] = proj;
          } else {
            error("failed to project point {} on {}", M.points[v], M.entity[v]);
            return false;
          }
        }
      }

      /* B. Boundary orthogonality correction */
      FC(v,M.points.size(),v2quads[v].size() == 2) { // TODO do the same for feature curves
        vec3 ptsStencil[6];
        F(k,6) {
          ptsStencil[k] = M.points[stencils[8*v+k]];
        }

        /* Boundary stencil in stencils[]:
         * --5---0---1--
         *   |   |   |
         * --4---3---2--
         *   |   |   |
         * Orth. correction: project 3 on {5,0,1}
         */
        if (projector != NULL && M.entity[v].first != -1) {
          /* Projection on underlying curve */
          vec3 query = ptsStencil[3];
          vec3 proj;
          bool okp = projector->project(M.entity[v].first,M.entity[v].second,query,proj);
          if (okp) {
            if (proj[0] == DBL_MAX) {
              error("wrong projected point: {}", proj);
              continue;
            }
            M.points[v] = proj;
          } else {
            error("failed to project point {} on {}", M.points[v], M.entity[v]);
            return false;
          }
        } else {
          /* Projection on boundary stencil */
          M.points[v] = project_point_on_curve(ptsStencil[3],{ptsStencil[1],ptsStencil[0],ptsStencil[5]});
        }
      }
    }

    return true;
  }

}

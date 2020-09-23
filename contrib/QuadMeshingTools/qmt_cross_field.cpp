// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "qmt_cross_field.h"
#include "quad_meshing_tools.h"

#include "qmt_types.hpp"
#include "qmt_utils.hpp"
#include "qmt_linalg_solver.h"

#include <cfloat>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <string>
#include <sstream>
#include <iostream>

#include "gmsh.h"

/* - Shortcuts for loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)

using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;
using gmsh::vectorpair;

constexpr double EPS = 1.e-14; /* to detect 0 */

namespace QMT_CF_Utils {
  bool global_gmsh_initialized = false;

  using namespace QMT;
  using namespace QMT_Utils;
  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Cross Field | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Cross Field | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Cross Field | " + stream.str(), "info");
    }
  /************************************/

}


namespace QMT {
  using namespace QMT_Utils;
  using namespace QMT_CF_Utils;

  constexpr bool DBG_VERBOSE = false;


  inline double triangle_area(const SMesh& M, id t) {
    vec3 N = cross(M.points[M.triangles[t][2]]-M.points[M.triangles[t][0]],
        M.points[M.triangles[t][1]]-M.points[M.triangles[t][0]]);
    return length(N) / 2.;
  }

  inline vec3 triangle_center(const SMesh& M, id t) {
    return 1./3.*(M.points[M.triangles[t][0]]+M.points[M.triangles[t][1]]+M.points[M.triangles[t][2]]);
  }

  inline vec3 triangle_normal(const SMesh& M, id t) {
    vec3 N = cross(M.points[M.triangles[t][2]]-M.points[M.triangles[t][0]],
        M.points[M.triangles[t][1]]-M.points[M.triangles[t][0]]);
    if (length(N) < EPS) {
      error("triangle {} ({}): normal too small, length = {}", t, M.triangles[t], length(N));
      return {DBL_MAX,DBL_MAX,DBL_MAX};
    }
    N = normalize(N);
    return N;
  }

  inline vec3 triangle_normal(const TMesh& M, id t) {
    vec3 N = cross(M.points[M.triangles[t][2]]-M.points[M.triangles[t][0]],
        M.points[M.triangles[t][1]]-M.points[M.triangles[t][0]]);
    if (length(N) < EPS) {
      error("triangle {} ({}): normal too small, length = {}", t, M.triangles[t], length(N));
      return {DBL_MAX,DBL_MAX,DBL_MAX};
    }
    N = normalize(N);
    return N;
  }

  struct IJV {
    id2 ij;
    double val;
    bool operator<(const IJV& b) const { return ij[0] < b.ij[0] || (ij[0] == b.ij[0] && ij[1] < b.ij[1]); }
  };

  struct IV {
    id i;
    double val;
    bool operator<(const IV& b) const { return i < b.i; }
  };

  /* two unknowns (x_2i, x_2i+1) for each edge */
  bool stiffness_coefficient(const SMesh& M, 
      id e, 
      const vector<id2>& uIEdges,
      const vector<id>& old2IEdge,
      const vector<vector<id>>& uIEdgeToOld,
      vector<IV>& iv,
      vector<IJV>& ijv) {
    if (uIEdgeToOld[e].size() != 2) {
      error("assembly, edge {}: uIEdgeToOld[e] = {}", e, uIEdgeToOld[e]);
      return false;
    }
    /* edge vertices */
    id v1 = uIEdges[e][0];
    id v2 = uIEdges[e][1];
    vec3 e_x = M.points[v2] - M.points[v1];
    if (DBG_VERBOSE) {info("-"); info("stiffness, e={} ({}->{}), p1={}, p2={}",e, v1,v2, M.points[v1], M.points[v2]);}
    double lenr = length(e_x);
    if (lenr < EPS) {
      error("edge too small: v1={}, v2={}, length = {}", v1, v2, lenr);
      return false;
    }
    e_x = (1./lenr) * e_x;
    /* four neighbor edges */
    id bvars[4] = {NO_ID,NO_ID,NO_ID,NO_ID};
    double alpha[4] = {0.,0.,0.,0.};
    double CR_weight[4] = {-1./4,-1./4,-1./4,-1./4};
    vec3 prevN;
    F(s,2) { /* two triangles */
      id oe = uIEdgeToOld[e][s];
      id t = oe / 3;
      id le = oe % 3;
      vec3 N = triangle_normal(M,t);
      if (s == 1 && dot(prevN,N) < 0.)  N = -1. * N;
      prevN = N;
      // N = {0,0,1};
      vec3 e_y = cross(N,e_x);
      if (length(e_y) < EPS) {
        error("length(e_y) = {}", length(e_y));
        return false;
      }
      e_y = normalize(e_y);

      F(k,2) { /* two other edges in triangle t */
        id aoe = 3*t+(le+1+k)%3;
        id ae = old2IEdge[aoe];
        id2 aedge = uIEdges[ae];

        bvars[2*s+k] = ae;
        vec3 edg = M.points[aedge[1]]-M.points[aedge[0]];
        double len = length(edg);
        if (len < EPS) {
          error("edge too small: t={}, k = {}, edge={}, length = {}", t, k, aedge, len);
          return false;
        }
        edg = (1./len) * edg;

        /* 360deg angle (used for the angle rotation) */
        double cx = dot(edg,e_x);
        double cy = dot(edg,e_y);
        alpha[2*s+k] = atan2(cy,cx);
        if (alpha[2*s+k] < 0.) alpha[2*s+k] += 2.*M_PI;
        if (DBG_VERBOSE) info("  e={} | t={}, k={} <-> ae={} ({}->{}) | angle(e{},e{})={}", e, t, k, ae, aedge[0],aedge[1], e, ae, 180./M_PI*alpha[2*s+k]);

        /* 180deg edge-edge angle (used for the Crouzeix Raviart) */
        double agl = 0.;
        if (aedge[0] == v1) {
          agl = angle_nvectors(edg,e_x);
        } else if (aedge[1] == v1) {
          agl = angle_nvectors(edg, -1. * e_x);
        } else if (aedge[0] == v2) {
          agl = angle_nvectors(-1. * edg, e_x);
        } else if (aedge[1] == v2) {
          agl = angle_nvectors(-1. * edg, -1. * e_x);
        } else {
          error("should not happen");
          return false;
        }
        CR_weight[2*s+k] = -2. / tan(agl);
        if (DBG_VERBOSE) info("   agl = {} -> CR_weight = {}", agl*180./M_PI, CR_weight[2*s+k]);
      }
    }
    /* compute coefficients */
    double isum = -1. * (CR_weight[0] + CR_weight[1] + CR_weight[2] + CR_weight[3]);
    F(k,4) CR_weight[k] = CR_weight[k] / isum;

    iv.clear();
    ijv.clear();
    id x_i = 2*e;
    id y_i = 2*e+1;
    iv.push_back({x_i,1.});
    iv.push_back({y_i,1.});
    F(j,4) {
      id x_j = 2*bvars[j];
      id y_j = 2*bvars[j]+1;
      ijv.push_back({{x_i,x_j},CR_weight[j]    *cos(4.*alpha[j])});
      ijv.push_back({{x_i,y_j},CR_weight[j]*-1.*sin(4.*alpha[j])});
      ijv.push_back({{y_i,x_j},CR_weight[j]    *sin(4.*alpha[j])});
      ijv.push_back({{y_i,y_j},CR_weight[j]    *cos(4.*alpha[j])});
    }

    return true;
  }

  bool prepare_system(
      const vector<IV>& K_diag,
      const vector<IJV>& K_coefs,
      vector<vector<size_t>>& columns,
      vector<vector<double>>& values) {
    vector<IJV> coefs = K_coefs;
    coefs.resize(coefs.size()+K_diag.size());
    F(i,K_diag.size()) coefs[K_coefs.size()+i] = {{id(K_diag[i].i),id(K_diag[i].i)},K_diag[i].val};
    std::sort(coefs.begin(),coefs.end());

    size_t cur_i = coefs[0].ij[0];
    size_t cur_j = coefs[0].ij[1];
    double acc_val = coefs[0].val;
    for (size_t k = 1; k < coefs.size(); ++k) {
      id i = coefs[k].ij[0];
      id j = coefs[k].ij[1];
      double v = coefs[k].val;
      if (i != cur_i) {
        if (std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      } else if (j != cur_j) {
        if (std::abs(acc_val) > EPS) {
          columns[cur_i].push_back(cur_j);
          values[cur_i].push_back(acc_val);
        }
        cur_i = i;
        acc_val = v;
        cur_j = j;
      } else {
        acc_val += v;
      }
    }
    if (std::abs(acc_val) > EPS) {
      columns[cur_i].push_back(cur_j);
      values[cur_i].push_back(acc_val);
    }

    return true;
  }

  bool create_view_with_crosses(
      const std::string& name,
      const SMesh& M,
      const vector<id2>& uIEdges,
      const vector<vector<id>>& uIEdgeToOld,
      const vector<double>& x) {
    vector<vec3> vertAvg(M.points.size(),{0.,0.,0.});
    vector<double> vsum(M.points.size(),0.);

    std::vector<double> data_VP;
    std::vector<double> data_VP_rep;
    vec3 rep_ex = {1.,0.,0.};
    vec3 rep_ey = {0.,1.,0.};
    F(e,uIEdges.size()) {
      /* Average normal */
      vec3 N = triangle_normal(M,uIEdgeToOld[e][0]/3);
      if (uIEdgeToOld[e].size() == 2) {
        N = 0.5 * (N + triangle_normal(M,uIEdgeToOld[e][1]/3));
      }

      vec3 edg = normalize(M.points[uIEdges[e][1]]-M.points[uIEdges[e][0]]);
      vec3 edgo = normalize(cross(N,edg));
      vec3 p = 0.5*(M.points[uIEdges[e][0]]+M.points[uIEdges[e][1]]);
      double len = std::sqrt(x[2*e]*x[2*e]+x[2*e+1]*x[2*e+1]);
      if (len > EPS) {
        double theta = 1./4*atan2(x[2*e+1]/len,x[2*e]/len);
        vec3 cross1 = cos(theta) * edg + sin(theta) * edgo;
        cross1 = len * cross1;
        vec3 cross2 = cross(N,cross1);
        F(d,3) data_VP.push_back(p[d]);
        F(d,3) data_VP.push_back(cross1[d]);
        F(d,3) data_VP.push_back(p[d]);
        F(d,3) data_VP.push_back(cross2[d]);

        { /* representation vector averaging (code only in planar case) */
          vec3 cr1 = cos(theta) * edg + sin(theta) * edgo;
          double rep_theta = atan2(dot(cr1,rep_ey),dot(cr1,rep_ex));
          vec3 vrep = cos(4.*rep_theta) * rep_ex + sin(4.*rep_theta) * rep_ey;
          // F(d,3) data_VP_rep.push_back(p[d]);
          // F(d,3) data_VP_rep.push_back(vrep[d]);
          F(lv,2) {
            id v = uIEdges[e][lv];
            vsum[v] += 1.;
            vertAvg[v] = vertAvg[v] + vrep;
          }
        }

      }
    }
    int view = gmsh::view::add(name);
    gmsh::view::addListData(view, "VP", data_VP.size()/6, data_VP);

    bool show_representation_vector = false; /* only relevant for planar cases */
    if (show_representation_vector) {
      double Nmin = DBL_MAX;
      vec3 ptNmin;
      FC(v,M.points.size(),vsum[v] > 0.) {
        vec3 p = M.points[v];
        vec3 rep = (1./vsum[v]) * vertAvg[v];
        if (length(rep) < Nmin) {
          Nmin = length(rep);
          ptNmin = p;
        }
        F(d,3) data_VP_rep.push_back(p[d]);
        F(d,3) data_VP_rep.push_back(rep[d]);
      }
      int viewv = gmsh::view::add(name+"_rep_planar");
      gmsh::view::addListData(viewv, "VP", data_VP_rep.size()/6, data_VP_rep);
      info("minimum norm = {} at pt = {} (length = {})", Nmin, ptNmin, length(ptNmin));
    }

    return true;
  }

  // TODO: verify this function, not sure if it works (see qmt cross field on smile2 model)
  // -> fixed by checking edge v1 < v2 or v2 > v1 and changing angle sign ?
  bool create_scaled_cross_field_view(const std::string& meshName, 
      int tagCrossField, int tagH, bool viewIsModelData, 
      const std::string& viewName, int& viewTag) {
    if (!QMT_CF_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_CF_Utils::global_gmsh_initialized = true;
    }

    /* Get the mesh and internal edges */
    TMesh M;
    bool oki = import_TMesh_from_gmsh(meshName, M);
    if (!oki) {
      error("failed to get mesh grom gmsh API");
      return false;
    }
    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id>> uIEdgeToOld;
    bool oka = compute_triangle_adjacencies(M.triangles, M.triangle_neighbors, M.nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
    if (!oka) {
      error("failed to compute mesh adjacencies");
      return false;
    }

    /* Get H for each vertex */
    vector<double> H(M.points.size(),0.);
    double Hmin =  DBL_MAX;
    double Hmax = -DBL_MAX;
    if (viewIsModelData) {
      std::string dataType;
      std::vector<std::size_t> tags;
      std::vector<std::vector<double> > data;
      double time;
      int numComponents;
      gmsh::view::getModelData(tagH, 0, dataType, tags, data, time, numComponents);
      if (dataType == "NodeData" && tags.size() <= M.points.size()) {
        F(i,tags.size()) {
          id v = tags[i];
          if (v >= M.points.size()) {
            error("tag[{}]={} but {} points in mesh", i, v, M.points.size());
            return false;
          }
          H[v] = data[i][0];
          Hmin = std::min(Hmin,H[v]);
          Hmax = std::max(Hmax,H[v]);
        }
      } else {
        error("problem");
        DBG("H view");
        DBG(dataType);
        DBG(M.points.size(), tags.size());
      }
    } else { /* use probing */
      std::vector<std::string> dataType;
      std::vector<int> numElements;
      std::vector<std::vector<double> > data;
      gmsh::view::getListData(tagH, dataType, numElements, data);
      Hmin = DBL_MAX;
      Hmax = -DBL_MAX;
      F(i,data[0].size()) {
        Hmin = std::min(Hmin, data[0][i]);
        Hmax = std::max(Hmax, data[0][i]);
      }
      vector<bool> used(M.points.size(),false);
      F(ue,uIEdges.size()) F(lv,2) used[uIEdges[ue][lv]] = true;
      FC(v,M.points.size(),used[v]) {
        vec3 pt = M.points[v];
        vector<double> values;
        gmsh::view::probe(tagH, pt[0], pt[1], pt[2], values);
        if (values.size() == 0) {
          error("probe failed at pt = {}", pt);
          return false;
        }
        H[v] = values[0];
      }
    }

    /* Get theta for each edge */
    vector<double> ue2theta(uIEdges.size(),DBL_MAX);
    {
      std::string dataType;
      std::vector<std::size_t> tags;
      std::vector<std::vector<double> > data;
      double time;
      int numComponents;
      gmsh::view::getModelData(tagCrossField, 0, dataType, tags, data, time, numComponents);
      std::unordered_map<id,id> TagToF(M.triangles.size());
      F(f,M.triangles.size()) TagToF[M.tri_elt_tags[f]] = f;

      if (dataType == "ElementData" && tags.size() == M.triangles.size()) {
        F(i,tags.size()) {
          auto it = TagToF.find(tags[i]);
          if (it == TagToF.end()) {
            error("triangle with tag {} not found", tags[i]);
            return false;
          }
          id f = it->second;
          if (data[i].size() != 3) {
            error("data size should be 3");
            return false;
          }
          F(le,3) {
            id ue = old2IEdge[3*f+le];
            if (ue2theta[ue] == DBL_MAX) {
              id2 tri_edge = {M.triangles[f][le],M.triangles[f][(le+1)%3]};
              id2 glo_edge = uIEdges[ue];
              double val = data[i][le];
              if (tri_edge == glo_edge) {
                ue2theta[ue] = val;
              } else if (tri_edge[0] == glo_edge[1] && tri_edge[1] == glo_edge[0]) {
                ue2theta[ue] = -val;
              } else {
                error("global edge and triangle edge are not matching: {} - {}", tri_edge, glo_edge);
                return -1;
              }
            }
          }
        }
      } else {
        error("problem with 'theta' view, mesh contains {} triangles but {} tags in view", M.triangles.size(), tags.size());
        return false;
      }
    }

    std::vector<double> data_VP;
    F(ue,ue2theta.size()) {
      double v1 = uIEdges[ue][0];
      double v2 = uIEdges[ue][1];
      vec3 p1 = M.points[v1];
      vec3 p2 = M.points[v2];
      double theta = ue2theta[ue];
      double val = 0.5*(H[v1] + H[v2]);
      double h = (exp(-val)/exp(-Hmin));

      vec3 p = 0.5*(p1+p2);
      vec3 edg = normalize(p2-p1);
      vec3 N = normalize(triangle_normal(M,uIEdgeToOld[ue][0]/3));
      if (uIEdgeToOld[ue].size() > 1) {
        if (dot(N,triangle_normal(M,uIEdgeToOld[ue][1]/3)) > 0.) {
          N = (N + normalize(triangle_normal(M,uIEdgeToOld[ue][1]/3)));
          N = normalize(N);
        }
      }
      {
        id t = uIEdgeToOld[ue][0] / 3;
        id le = uIEdgeToOld[ue][0] % 3;
        id tv1 = M.triangles[t][le];
        id tv2 = M.triangles[t][(le+1)%3];
        if (tv1 == v2 && tv2 == v1) {
          N = -1. * N;
        }
      }
      vec3 edgo = normalize(cross(N,edg));
      vec3 cross1 = cos(theta) * edg + sin(theta) * edgo;
      vec3 cross2 = cross(N,cross1);
      cross1 = h * cross1;
      cross2 = h * cross2;
      F(d,3) data_VP.push_back(p[d]);
      F(d,3) data_VP.push_back(cross1[d]);
      F(d,3) data_VP.push_back(p[d]);
      F(d,3) data_VP.push_back(-cross1[d]);
      F(d,3) data_VP.push_back(p[d]);
      F(d,3) data_VP.push_back(cross2[d]);
      F(d,3) data_VP.push_back(p[d]);
      F(d,3) data_VP.push_back(-cross2[d]);
    }

    if (viewTag < 0) {
      info("create view '{}'",viewName);
      viewTag = gmsh::view::add(viewName);
    } else {
      info("overwrite view with tag {}",viewTag);
    }
    gmsh::view::addListData(viewTag, "VP", data_VP.size()/6, data_VP);

    return true;
  }

  vec3 crouzeix_raviart_interpolation(vec3 lambda, vec3 edge_values[3]) {
    double x = lambda[1];
    double y = lambda[2];
    vec3 shape = {1.0 - 2.0 * y, -1.0 + 2.0 * (x + y), 1.0 - 2.0 * x};
    return shape[0] * edge_values[0] + shape[1] * edge_values[1] + shape[2] * edge_values[2];
  }

  bool create_per_triangle_scaled_cross_field_view(const std::string& meshName, int tagCrossField, int tagSizeMap, const std::string& viewName, int& viewTag) {
    initialize_gmsh_api_if_necessary();

    constexpr bool crouzeix_raviart_linear_interp = true;

    /* Get the mesh and internal edges */
    TMesh M;
    bool oki = import_TMesh_from_gmsh(meshName, M);
    if (!oki) {
      error("failed to get mesh grom gmsh API");
      return false;
    }
    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id>> uIEdgeToOld;
    bool oka = compute_triangle_adjacencies(M.triangles, M.triangle_neighbors, M.nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
    if (!oka) {
      error("failed to compute mesh adjacencies");
      return false;
    }

    /* Get size map for each vertex */
    vector<bool> used(M.points.size(),false);
    F(ue,uIEdges.size()) F(lv,2) used[uIEdges[ue][lv]] = true;
    vector<double> sizemap(M.points.size(),DBL_MAX);
    FC(v,M.points.size(),used[v]) {
      vec3 pt = M.points[v];
      vector<double> values;
      gmsh::view::probe(tagSizeMap, pt[0], pt[1], pt[2], values);
      if (values.size() == 0) {
        error("probe failed at pt = {}", pt);
        return false;
      }
      sizemap[v] = values[0];
    }

    /* Compute averaged cross on each triangle */
    bool create_data_list_view = true;
    std::vector<std::size_t> keys;
    std::vector<std::vector<double> > values;
    std::vector<double> datalist;
    {
      std::string dataType;
      std::vector<std::size_t> tags;
      std::vector<std::vector<double> > data;
      double time;
      int numComponents;
      gmsh::view::getModelData(tagCrossField, 0, dataType, tags, data, time, numComponents);
      std::unordered_map<id,id> TagToF(M.triangles.size());
      F(f,M.triangles.size()) TagToF[M.tri_elt_tags[f]] = f;

      if (dataType == "ElementData" && tags.size() == M.triangles.size()) {
        F(i,tags.size()) {
          if (!create_data_list_view) keys.push_back(tags[i]);
          auto it = TagToF.find(tags[i]);
          if (it == TagToF.end()) {
            error("triangle with tag {} not found", tags[i]);
            return false;
          }
          id f = it->second;
          if (data[i].size() != 3) {
            error("data size should be 3");
            return false;
          }
          vec3 N = normalize(triangle_normal(M,f));
          vec3 refCross = {0.,0.,0.};
          vec3 avgCross = {0.,0.,0.};
          vec3 lifted_dirs[3];
          F(le,3) {
            double agl = data[i][le];
            id ue = old2IEdge[3*f+le];
            id2 tri_edge = {M.triangles[f][le],M.triangles[f][(le+1)%3]};
            vec3 p1 = M.points[tri_edge[0]];
            vec3 p2 = M.points[tri_edge[1]];
            vec3 edg = normalize(p2-p1);
            vec3 edgo = normalize(cross(N,edg));
            vec3 cross1 = cos(agl) * edg + sin(agl) * edgo;
            vec3 cross2 = normalize(cross(N,cross1));
            if (le == 0) {
              refCross = cross1;
              avgCross = avgCross + cross1;
              lifted_dirs[le] = refCross;
            } else {
              vec3 candidates[4] = {cross1,-1.*cross1,cross2,-1.*cross2};
              vec3 closest = {0.,0.,0.};
              double dotmax = -DBL_MAX;
              F(k,4) {
                if (dot(candidates[k],refCross) > dotmax) {
                  closest = candidates[k];
                  dotmax = dot(candidates[k],refCross);
                }
              }
              lifted_dirs[le] = closest;
              avgCross = avgCross + closest;
            }
          }
          double asize = 1./3. * (sizemap[M.triangles[f][0]] + sizemap[M.triangles[f][1]] + sizemap[M.triangles[f][2]]);
          vec3 avgScaledDir = asize * 1./3. * avgCross;
          vec3 vertex_dirs[3];
          if (crouzeix_raviart_linear_interp) {
            vec3 edge_dirs[3];
            F(le,3) {
              double se = 0.5 * (sizemap[M.triangles[f][le]] + sizemap[M.triangles[f][(le+1)%3]]);
              edge_dirs[le] = se * lifted_dirs[le];
            }
            F(lv,3) {
              vec3 lambda = {0.,0.,0.};
              lambda[lv] = 1.;
              vertex_dirs[lv] = crouzeix_raviart_interpolation(lambda,edge_dirs);
            }
            // DBG("----");
            // DBG(avgScaledDir);
            // DBG(edge_dirs[0],edge_dirs[1],edge_dirs[2]);
            // DBG(vertex_dirs[0],vertex_dirs[1],vertex_dirs[2]);
          }

          if (create_data_list_view) {
            for (size_t d = 0; d < 3; ++d) {
              for (size_t lv = 0; lv < 3; ++lv) {
                datalist.push_back(M.points[M.triangles[f][lv]][d]);
              }
            }
            for (size_t lv = 0; lv < 3; ++lv) {
              for (size_t d = 0; d < 3; ++d) {
                if (crouzeix_raviart_linear_interp) {
                  datalist.push_back(vertex_dirs[lv][d]);
                } else {
                  datalist.push_back(avgScaledDir[d]);
                }
              }
            }
          } else {
            values.push_back({avgScaledDir[0],avgScaledDir[1],avgScaledDir[2]});
          }
        }
      } else {
        error("problem with 'theta' view, mesh contains {} triangles but {} tags in view", M.triangles.size(), tags.size());
        return false;
      }
    }

    if (viewTag < 0) {
      info("create view '{}'",viewName);
      viewTag = gmsh::view::add(viewName);
    } else {
      info("overwrite view with tag {}",viewTag);
    }
    if (create_data_list_view) {
      gmsh::view::addListData(viewTag, "VT", datalist.size()/(9+9), datalist);
    } else {
      std::string cname;
      gmsh::model::getCurrent(cname);
      gmsh::view::addModelData(viewTag, 0, cname, "ElementData", keys, values);
    }

    return true;
  }

  double bbox_diag(const std::vector<vec3>& points) {
    vec3 mi = {DBL_MAX,DBL_MAX,DBL_MAX};
    vec3 ma = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    F(i,points.size()) {
      F(d,3) {
        mi[d] = std::min(points[i][d],mi[d]);
        ma[d] = std::max(points[i][d],ma[d]);
      }
    }
    return length(ma-mi);
  }

  bool expand_dirichlet_boundary_conditions(
      const SMesh& M,
      const vector<id2>& uIEdges,
      const vector<id>& old2IEdge,
      const vector<vector<id>>& uIEdgeToOld,
      size_t nb_layers,
      vector<bool>& dirichletEdge,
      vector<vec2>& dirichletValue,
      int verbosity) {
    /* Look for expanded BC edges */
    vector<bool> extDirichletEdge = dirichletEdge;
    vector<id> new_edges;
    F(layer,nb_layers) {
      FC(e,uIEdges.size(),extDirichletEdge[e]) {
        F(i,uIEdgeToOld[e].size()) {
          id t = uIEdgeToOld[e][i] / 3;
          F(le,3) {
            id oe2 = 3*t+le;
            id e2 = old2IEdge[oe2];
            if (!extDirichletEdge[e2]) {
              new_edges.push_back(e2);
            }
          }
        }
      }
      sort_unique(new_edges);
      F(i,new_edges.size()) extDirichletEdge[new_edges[i]] = true;
    }
    if (new_edges.size() == 0) {
      if (verbosity >= 2)
        warn("no new edges to expand dirichlet boundary conditions");
      return false;
    }

    if (verbosity >= 2)
      info("Dirichlet B.C. expansion: added {} edges (for {} layers)", new_edges.size(), nb_layers);

    /* Small system for BC expansion */
    vector<IJV> K_coefs;
    F(k,new_edges.size()) {
      id e = new_edges[k];
      vector<IV> iv;
      vector<IJV> ijv;
      bool oks = stiffness_coefficient(M, e, uIEdges, old2IEdge, uIEdgeToOld, iv, ijv);
      if (!oks || iv.size() != 2 || iv[0].i != 2*e || iv[1].i != 2*e+1) {
        error("failed to get stiffness coefficients for edge e = {}", e);
        return false;
      }
      /* Add coefficients for interaction i-j of edges in extDirichletEdge */
      FC(l,ijv.size(),extDirichletEdge[ijv[l].ij[1]/2]) K_coefs.push_back(ijv[l]);
    }
    vector<IV> K_diag;
    vector<vector<size_t>> A_col(2*uIEdges.size());
    vector<vector<double>> A_coef(2*uIEdges.size());
    bool okp = prepare_system(K_diag, K_coefs, A_col, A_coef);
    if (!okp) {
      error("failed to prepare system");
      return false;
    }

    /* Explicit solver (local smoothing) */
    FC(e,uIEdges.size(),extDirichletEdge[e] && !dirichletEdge[e]) {
      dirichletValue[e] = {0.,0.};
    }
    constexpr double EPS = 1.e-14;
    F(iter,nb_layers*10) {
      FC(e,uIEdges.size(),extDirichletEdge[e] && !dirichletEdge[e]) {
        F(d,2) {
          id i = 2*e+d;
          dirichletValue[e][d] = 0.;
          F(l,A_col[i].size()) {
            id j = A_col[i][l];
            if (!extDirichletEdge[j/2]) continue;
            double w = A_coef[i][l];
            dirichletValue[e][d] += -1. * w * dirichletValue[j/2][j%2];
          }
        }
        double n2 = length(dirichletValue[e]);
        if (n2 < EPS) {
          continue;
        }
        dirichletValue[e][0] /= n2;
        dirichletValue[e][1] /= n2;
      }
    }

    /* Set expanded edges as Dirichlet edges */
    FC(e,uIEdges.size(),extDirichletEdge[e] && !dirichletEdge[e] && length(dirichletValue[e]) > EPS) {
      dirichletEdge[e] = true;
    }

    return true;
  }

  bool compute_cross_field_with_heat(
      const std::string& meshName,
      int& crossFieldTag,
      int nbIter,
      std::map<std::pair<size_t,size_t>,double>* edge_to_angle,
      int bc_expansion_layers) {
    if (!QMT_CF_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_CF_Utils::global_gmsh_initialized = true;
    }
    error("function compute_cross_field_with_heat() deprecated, please use compute_cross_field_with_multilevel_diffusion()");
    return false;
  }

  bool create_cross_field_theta_view(
      const std::string& meshName,
      const std::map<std::array<size_t,2>,double>& edgeTheta,
      int& crossFieldTag) {
    if (!QMT_CF_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_CF_Utils::global_gmsh_initialized = true;
    }
    warn("create_cross_field_theta_view | kept for backward compatibility, should no longer be used");

    TMesh M;
    bool oki = import_TMesh_from_gmsh(meshName, M);
    if (!oki) {
      error("failed to get mesh grom gmsh API");
      return false;
    }

    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id>> uIEdgeToOld;
    std::vector<sid3> triangle_neighbors;
    std::vector<std::vector<id>> nm_triangle_neighbors;
    bool oka = compute_triangle_adjacencies(M.triangles, triangle_neighbors, nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
    if (!oka) {
      error("failed to compute mesh adjacencies");
      return false;
    }

    { /* create the theta view */
      std::string cname;
      gmsh::model::getCurrent(cname);
      std::vector<std::size_t> keys;
      std::vector<std::vector<double> > values;
      F(f,M.triangles.size()) {
        keys.push_back(M.tri_elt_tags[f]);
        std::vector<double> vals;
        F(le,3) {
          id v1 = M.triangles[f][le];
          id v2 = M.triangles[f][(le+1)%3];
          id2 edge = sorted(v1,v2);
          std::array<size_t,2> vPair = {size_t(edge[0]),size_t(edge[1])};
          auto it = edgeTheta.find(vPair);
          if (it == edgeTheta.end()) {
            error("edge ({},{}) not found in edgeTheta", v1,v2);
            return false;
          }
          double theta = it->second;
          vals.push_back(theta);
        }
        values.push_back(vals);
      }
      if (crossFieldTag < 0) {
        info("create the 'theta' view");
        crossFieldTag = gmsh::view::add("theta");
      } else {
        info("fill theta in the given view (tag = {})", crossFieldTag);
      }
      gmsh::view::addModelData(crossFieldTag, 0, cname, "ElementData", keys, values);
    }

    return true;

  }

  bool compute_cross_field_with_multilevel_diffusion(
      const std::vector<std::array<double,3> >& points,
      const std::vector<std::array<size_t,2> >& lines,
      const std::vector<std::array<size_t,3> >& triangles,
      std::map<std::array<size_t,2>,double>& edgeTheta,
      int nbDiffusionLevels,
      double thresholdNormConvergence,
      int nbBoundaryExtensionLayer,
      int verbosity) {
    if (!QMT_CF_Utils::global_gmsh_initialized) {
      gmsh::initialize(0, 0, false);
      QMT_CF_Utils::global_gmsh_initialized = true;
    }

    /* Fill a SMesh data structure with the triangles */
    SMesh M;
    {
      if(points.size() >= std::numeric_limits<id>::max()) {
        error("too many points in the input: {}, not supported", points.size());
        return false;
      }
      M.points = points;
      M.lines.resize(lines.size());
      M.triangles.resize(triangles.size());
      F(i,M.lines.size()) F(j,2) M.lines[i][j] = lines[i][j];
      F(i,M.triangles.size()) F(j,3) M.triangles[i][j] = triangles[i][j];
    }

    vector<id2> uIEdges;
    vector<id> old2IEdge;
    vector<vector<id>> uIEdgeToOld;
    std::vector<sid3> triangle_neighbors;
    std::vector<std::vector<id>> nm_triangle_neighbors;
    bool oka = compute_triangle_adjacencies(M.triangles, triangle_neighbors, nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
    if (!oka) {
      error("failed to compute mesh adjacencies");
      return false;
    }

    double diag = bbox_diag(M.points);
    if (verbosity > 0)
      info("input: {} points, {} lines, {} triangles, {} internal edges, bbox diag = {}", M.points.size(),M.lines.size(),M.triangles.size(),uIEdges.size(), diag);

    if (uIEdges.size() == 0) {
      error("no internal edges");
      return false;
    }

    /* System unknowns: cos(4t),sin(4t) for each edge */
    vector<double> x(2*uIEdges.size(),0.);

    /* Initial Dirichlet boundary conditions 
     * alignement of crosses with edges (relative angle = 0) 
     * theta_e = 0 => (cos4t/sin4t) = (1,0) */
    size_t nbc = 0;
    vector<bool> dirichletEdge(uIEdges.size(),false);
    vector<vec2> dirichletValue(uIEdges.size(),{1.,0.});
    FC(e,uIEdges.size(),uIEdgeToOld[e].size() != 2) {
      dirichletEdge[e] = true;
      dirichletValue[e] = {1.,0.};
      nbc += 1;
    }
    F(l,M.lines.size()) { /* mark the lines as boundary conditions */
      id2 edge = sorted(M.lines[l][0],M.lines[l][1]);
      auto it = std::find(uIEdges.begin(),uIEdges.end(),edge);
      if (it != uIEdges.end()) {
        id e = id(it - uIEdges.begin());
        dirichletEdge[e] = true;
        dirichletValue[e] = {1.,0.};
        nbc += 1;
      }
    }
    if (verbosity >= 2)
      info("boundary conditions: {} crosses fixed on edges", nbc);

    if (nbBoundaryExtensionLayer > 0) {
      bool oke = expand_dirichlet_boundary_conditions(M, uIEdges, old2IEdge, uIEdgeToOld, nbBoundaryExtensionLayer, dirichletEdge, dirichletValue, verbosity);
      if (!oke) {
        warn("failed to expand dirichlet boundary conditions");
      }
      F(e,uIEdges.size()) { 
        x[2*e+0] = dirichletValue[e][0];
        x[2*e+1] = dirichletValue[e][1];
      }
    }

    if (verbosity >= 2)
      info("compute stiffness matrix coefficients (Crouzeix-Raviart) ...");

    vector<IV> K_diag;
    vector<IJV> K_coefs;
    vector<double> rhs(2*uIEdges.size(),0.);
    vector<double> Mass(2*uIEdges.size(),1.); /* diagonal for Crouzeix-Raviart */
    F(e,uIEdges.size()) {
      if (!dirichletEdge[e]) {
        vector<IV> iv;
        vector<IJV> ijv;
        bool oks = stiffness_coefficient(M, e, uIEdges, old2IEdge, uIEdgeToOld, iv, ijv);
        if (!oks) {
          error("failed to compute stiffness matrix coefficients for e = {}", e);
          return false;
        }
        F(i,iv.size()) K_diag.push_back(iv[i]);
        F(i,ijv.size()) K_coefs.push_back(ijv[i]);
        double area1 = triangle_area(M, uIEdgeToOld[e][0]/3);
        double area2 = triangle_area(M, uIEdgeToOld[e][1]/3);
        Mass[2*e+0] = 1./3 * (area1 + area2);
        Mass[2*e+1] = 1./3 * (area1 + area2);
      } else { /* Dirichlet BC */
        K_diag.push_back({id(2*e+0),1.});
        rhs[2*e+0] = dirichletValue[e][0];
        K_diag.push_back({id(2*e+1),1.});
        rhs[2*e+1] = dirichletValue[e][1];
        if (DBG_VERBOSE) {
          info(" dirichlet: x[{}]={} (edge {}, p1={}, p2 = {}])",2*e,1.,e,M.points[uIEdges[e][0]],M.points[uIEdges[e][1]]);
          info(" dirichlet: x[{}]={} (edge {})",2*e+1,0.,e);
        }
      }
    }

    double eavg = 0.;
    double emin = DBL_MAX;
    double emax = -DBL_MAX;
    F(e,uIEdges.size()) {
      double len = length(M.points[uIEdges[e][1]]-M.points[uIEdges[e][0]]);
      eavg += len;
      emin = std::min(len,emin);
      emax = std::max(len,emax);
    }
    eavg /= uIEdges.size();

    if (verbosity >= 2)
      info("edge size: min={}, avg={}, max={} | bbox diag: {}",emin,eavg,emax,diag);


    /* prepare system */
    vector<vector<size_t>> K_columns(2*uIEdges.size());
    vector<vector<double>> K_values(2*uIEdges.size());
    {
      bool okp = prepare_system(K_diag, K_coefs, K_columns, K_values);
      if (!okp) {
        error("failed to prepare system");
        return false;
      }
    }
    
    double dtInitial = (0.1*diag)*(0.1*diag);
    double dtFinal = (3.*emin)*(3.*emin);

    if (verbosity >= 1)
      info("heat diffusion and projection loop ({} levels, {} unknowns, dt = {} .. {}) ...", nbDiffusionLevels, 2*uIEdges.size(),dtInitial, dtFinal);

    double wti = gmsh::logger::getWallTime();
    F(e,uIEdges.size()) { 
      x[2*e+0] = dirichletValue[e][0];
      x[2*e+1] = dirichletValue[e][1];
    }

    vector<double> steps;
    F(i,nbDiffusionLevels) { /* resolution transition */
      double dt = dtInitial + (dtFinal-dtInitial) * double(i)/double(nbDiffusionLevels-1);
      steps.push_back(dt);
    }

    {
      /* Initialize system (I/dt + M^-1 * L) x_(i+1) = 1/dt * x_i     (Ax = B) */
      vector<vector<size_t>> Acol = K_columns;
      vector<vector<double>> Aval_add = K_values; /* to get sparsity pattern */
      F(i,Aval_add.size()) std::fill(Aval_add[i].begin(),Aval_add[i].end(),0.);
      vector<double> B = x;
      vector<double> norms(uIEdges.size(),0.);
      vector<double> prevNorms = norms;

      void* data;
      create_linear_system(2*uIEdges.size(),&data);

      vector<double> diag_sum(2*uIEdges.size(), 0.);
      F(i,Acol.size()) {
        if (!dirichletEdge[i/2]) {
          F(j,Acol[i].size()) {
            Aval_add[i][j] = 1. / Mass[i] * K_values[i][j];
          }
        } else {
          Aval_add[i] = {1.};
        }
      }
      add_sparse_coefficients(Acol, Aval_add, data);
      F(i,Aval_add.size()) Aval_add[i].clear();
      F(i,Acol.size()) Acol[i].clear();
      preprocess_sparsity_pattern(data);


      /* Loop over the changing timesteps */
      double prev_dt = DBL_MAX;
      for (int iter = 0; iter < steps.size(); ++iter) {
        if (iter > 0 && steps[iter] > prev_dt) continue;
        double dt = steps[iter];
        prev_dt = dt;

        if (verbosity >= 1)
          info("  step {}/{} | dt = {}, linear system loop ...", iter+1, steps.size(), dt);

        /* Update LHS matrix with the new timestep */
        F(i,Acol.size()) {
          if (!dirichletEdge[i/2]) {
            Acol[i] = {i};
            Aval_add[i] = {-diag_sum[i] + 1./dt};
            diag_sum[i] = 1./dt;
          }
        }
        bool oku = add_sparse_coefficients(Acol, Aval_add, data);
        if (!oku) {
          error("failed to update linear system");
          return false;
        }
        factorize(data);

        /* Loop at fixed time step */
        constexpr size_t subiter_max = 25;
        F(subiter, subiter_max) {
          prevNorms = norms;

          /* Update RHS */
          B = x;
          FC(i,B.size(),!dirichletEdge[i/2]) B[i] /= dt;
          set_rhs_values(B, data);

          bool oks = solve(x, data);
          if (!oks) {
            error("failed to solve linear system");
            return false;
          }

          
          /* Normalize cross field and gather norm stats */
          double nmi = DBL_MAX;
          double nma = -DBL_MAX;
          F(e,uIEdges.size()) {
            norms[e] = std::sqrt(x[2*e]*x[2*e]+x[2*e+1]*x[2*e+1]);
            nmi = std::min(nmi,norms[e]);
            nma = std::max(nma,norms[e]);
            if (!dirichletEdge[e] && norms[e] > EPS) {
              x[2*e+0] /= norms[e];
              x[2*e+1] /= norms[e];
            }
          }
          // info("            |   norm, min = {}, max = {}", nmi, nma);
          const double EPS_NORM = 1.e-1;
          if (nma > 1. + EPS_NORM) {
            steps[iter] /= 10;
            dt = steps[iter];
            iter -= 1;
            if (verbosity >= 2)
              warn("           |   max(norm)={} (should be 1.), solve failed, new time step: dt = {}", nma, dt);
            break;
          }
          if (subiter > 0 || iter > 0) {
            double linf = 0.;
            FC(i,norms.size(),!dirichletEdge[i]) {
              linf = std::max(linf,norms[i]-prevNorms[i]);
            }
            if (verbosity >= 3)
              info("           |   system solved, norm diff max: {}, norm range: {} - {}", linf, nmi, nma);
            if (linf < 1.e-3) break;
          } else {
            if (verbosity >= 3)
              info("           |   system solved");
          }
        }
      }

      destroy_linear_system(&data);
    }
    double et = gmsh::logger::getWallTime() - wti;
    if (verbosity >= 2)
      info("cross field elapsed time: {}", et);

    { /* Export solution */
      F(e,uIEdges.size()) {
        double len = std::sqrt(x[2*e]*x[2*e]+x[2*e+1]*x[2*e+1]);
        double theta = (len > EPS) ? 1./4*atan2(x[2*e+1]/len,x[2*e]/len) : 0.;
        std::array<size_t,2> vPair = {uIEdges[e][0],uIEdges[e][1]};
        edgeTheta[vPair] = theta;
      }
    }

    return true;
  }

}

// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblUtils.h"
#include "hblTypes.hpp"
#include "hblLogging.hpp"
#include "hblBrepMesh.h"

#include "cppUtils.h"
#include "geolog.h"

#include <vector>
#include <unordered_map>
#include <queue>

/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)

namespace hbl {
  using std::vector;
  using namespace CppUtils;

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

  bool getOrderedVerticesFromEdges(const vector<id2>& edges, vector<id>& orderedVertices) {
    std::unordered_map<id,id> vVal;
    F(e,edges.size()) F(lv,2) vVal[edges[e][lv]] += 1;
    id mval = 10;
    id vStart = NO_ID;
    for (auto kv: vVal)  {
      if (kv.second < mval) {
        mval = kv.second;
        vStart = kv.first;
      }
    }
    if (vStart == NO_ID) return false;
    return getOrderedVerticesFromEdges(vStart, edges, orderedVertices);
  }

  bool system_reduction_using_graph(
      id n,
      const std::vector<id2>& equality_constraints,
      const std::vector<bool>& toDel,
      std::vector<id>& old2new,
      id& nbIndep) {

    std::vector<std::vector<id>> v2v(n);
    F(i,equality_constraints.size()) {
      v2v[equality_constraints[i][0]].push_back(equality_constraints[i][1]);
      v2v[equality_constraints[i][1]].push_back(equality_constraints[i][0]);
    }

    /* Greedy aggregation */
    std::deque<id> Q;
    old2new.clear();
    old2new.resize(n,NO_ID);
    id count = 0;
    std::vector<bool> visited(n, false);
    F(i, n) {
      if (toDel.size() > 0 && toDel[i]) continue;
      if (visited[i]) continue;
      Q.push_back(i);
      visited[i] = true;
      while(!Q.empty()) {
        id v = Q.front();
        Q.pop_front();
        old2new[v] = count;
        F(lv,v2v[v].size()) {
          id v2 = v2v[v][lv];
          if (visited[v2]) continue;
          if (toDel.size() > 0 && toDel[v2]) continue;
          visited[v2] = true;
          Q.push_back(v2);
        }
      }
      count += 1;
    }
    nbIndep = count;
    return true;
  }

  bool system_reduction_using_graph(
      id n,
      const std::vector<id2>& equality_constraints,
      std::vector<id>& old2new,
      id& nbIndep) {
    vector<bool> toDel;
    return system_reduction_using_graph(n, equality_constraints, toDel, old2new, nbIndep);
  }

  bool extract_dual_polygon(const BrepMesh& Q, id v, vector<id>& adjacentEdgesOrdered) {
    RFC(v >= Q.vertToEdges.size(), "invalid bottom-up mappings");

    vector<id2> dualEdges; /* connect two face-connected edges adjacent to v */
    std::unordered_set<id> faceDone;
    for (id _e: Q.vertToEdges[v]) for (id f: Q.edgeToFaces[_e]) {
      if (faceDone.find(f) != faceDone.end()) continue;
      id e1 = NO_ID;
      id e2 = NO_ID;
      for (id e: Q.faces[f].edges) if (inVector(e,Q.vertToEdges[v])) {
        if (e1 == NO_ID) {
          e1 = e;
        } else if (e2 == NO_ID) {
          e2 = e;
        } else {
          RF("extract_dual_polygon | more than two edges connected to v, should not happen");
        }
      }
      if (e1 != NO_ID && e2 != NO_ID) {
        dualEdges.push_back(sorted(e1,e2));
        faceDone.insert(f);
      }
    }
    sort_unique(dualEdges);

    std::vector<id> overt;
    bool ok = getOrderedVerticesFromEdges(dualEdges[0][0], dualEdges, overt);
    RFC(!ok,"failed to get ordered vertices from edges: {}", dualEdges);
    adjacentEdgesOrdered = overt;
    return true;
  }

  void visualization_show_cells(const BrepMesh& M, const std::vector<id>& cells, const std::string& viewName) {
    bool colorIsIndex = false;
    for (id c: cells) {
      bool done = false;
      if (M.cells[c].faces.size() == 6) {
        vector<id> vert = hex_vertices(M,c);
        if (vert.size() == 8) {
          done = true;
          vector<vec3> pts = points_from_vertices(M,vert);
          vector<double> values(pts.size(),double(0.));
          if (colorIsIndex) {
            F(j,values.size()) values[j] = double(c);
          }
          GeoLog::add(pts,values,viewName,true);
        }
      } else if (M.cells[c].faces.size() == 4) {
        vector<id> vert = cell_vertices(M,c);
        if (vert.size() == 4) {
          done = true;
          vector<vec3> pts = points_from_vertices(M,vert);
          vector<double> values(pts.size(),double(0.));
          if (colorIsIndex) {
            F(j,values.size()) values[j] = double(c);
          }
          GeoLog::add(pts,values,viewName,true);
        }
      }
      if (!done) { /* Show faces */
        F(lf,M.cells[c].faces.size()) {
          id f = M.cells[c].faces[lf];
          vector<id> vert = face_vertices(M,f);
          vector<vec3> pts = points_from_vertices(M,vert);
          vector<double> values(pts.size(),double(0.));
          if (colorIsIndex) {
            F(j,values.size()) values[j] = double(vert[j]);
          }
          GeoLog::add(pts,values,viewName);
        }
      }
    }
  }

  void visualization_show_faces(const BrepMesh& M, const std::vector<id>& faces, const std::string& viewName) {
    for (id f: faces) {
      vector<id> vert = face_vertices(M,f);
      vector<vec3> pts = points_from_vertices(M,vert);
      vector<double> values(pts.size(),double(0.));
      GeoLog::add(pts,values,viewName);
    }
  }

  void vector_statistics(const std::vector<double>& values, double& vMin, double& vMax, double& vAvg) {
    vMin = DBL_MAX;
    vMax = -DBL_MAX;
    vAvg = 0.;
    if (values.size() == 0.) {
      error("vector_statistics | no values in input");
      return;
    }
    for (size_t i = 0; i < values.size(); ++i) {
      const double val = values[i];
      vAvg += val;
      if (val > vMax) vMax = val;
      if (val < vMin) vMin = val;
    }
    vAvg /= double(values.size());
    if (std::isnan(vMin) || std::isnan(vMax) || std::isnan(vAvg)) {
      warn("vector_statistics: NaN values ! vMin = {}, vMax = {}, vAvg = {}. Recompute with ignoring NaN (slow)", vMin, vMax, vAvg);
      vector<double> values_clean;
      values_clean.reserve(values.size());
      FC(i,values.size(),!std::isnan(values[i])) values_clean.push_back(values[i]);
      return vector_statistics(values_clean, vMin, vMax, vAvg);
    }
  }


  id3 get_smallest_rotation(const id3& vec) {
    id3 smallest = vec;
    id3 rot_l = vec;
    F(i,vec.size()) {
      std::rotate(rot_l.begin(),rot_l.begin()+1,rot_l.end());
      if (rot_l < smallest) smallest = rot_l;
    }
    return smallest;
  }

  id4 get_smallest_rotation(const id4& vec) {
    id4 smallest = vec;
    id4 rot_l = vec;
    F(i,vec.size()) {
      std::rotate(rot_l.begin(),rot_l.begin()+1,rot_l.end());
      if (rot_l < smallest) smallest = rot_l;
    }
    return smallest;
  }

}

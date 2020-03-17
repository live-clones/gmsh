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
#include <fstream>

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

namespace QMT_SMP_Utils {
  using namespace QMT;
  using namespace QMT_Utils;


  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Simplification | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Simplification | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Simplification | " + stream.str(), "info");
    }
  /************************************/

  bool is_file(const char *fileName) {
    std::ifstream in(fileName);
    return in.good();
  }

  inline id2 sorted(id v1, id v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }

  struct id2Hash {
    size_t operator()(id2 p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };

  void show_qmesh_in_view(const QMesh& M, const std::string& viewName, bool use_width_as_color = false) {
    std::vector<double> data;
    size_t nbq = 0;
    F(c,M.quads.size()) {
      if (M.quads[c][0] == NO_ID) continue;
      nbq += 1;
      F(d,3) {
        F(lv,4) {
          id v = M.quads[c][lv];
          data.push_back(M.points[v][d]);
        }
      }
      double color = M.color[c];
      if (use_width_as_color) {
        color = 0.25 * (
            length(M.points[M.quads[c][1]] - M.points[M.quads[c][0]])
            + length(M.points[M.quads[c][2]] - M.points[M.quads[c][1]])
            + length(M.points[M.quads[c][3]] - M.points[M.quads[c][2]])
            + length(M.points[M.quads[c][0]] - M.points[M.quads[c][3]]));
      }
      F(lv,4) {
        data.push_back(color);
      }
    }
    int view = gmsh::view::add(viewName);
    gmsh::view::addListData(view, "SQ", nbq, data);
  }

  void show_chord_in_view(const QMesh& M, const vector<Chord>& chords, const std::string& view) {
    std::vector<double> data_SL;
    F(ch,chords.size()) {
      const Chord& chord = chords[ch];
      F(i,chord.size()) {
        id q = chord[i] / 2;
        if (M.quads[q][0] == NO_ID) continue;
        id le1 = chord[i] % 2;
        id le2 = le1 + 2;
        vec3 p1 = 0.5 * (M.points[M.quads[q][le1]]
            + M.points[M.quads[q][(le1+1)%4]]);
        vec3 p2 = 0.5 * (M.points[M.quads[q][le2]]
            + M.points[M.quads[q][(le2+1)%4]]);
        for (size_t d = 0; d < 3; ++d) {
          data_SL.push_back(p1[d]);
          data_SL.push_back(p2[d]);
        }
        data_SL.push_back(double(ch));
        data_SL.push_back(double(ch));
      }
    }
    int vi = gmsh::view::add(view);
    gmsh::view::addListData(vi, "SL", data_SL.size()/(6+2), data_SL);
  }


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


  /* warning: call gmsh API */
  bool getCurveOrderedVertices(int curve, vector<id>& vertices, vector<vec3>& points, id vStart) {
    /* Points in the curve */
    std::vector<size_t> vert;
    std::vector<double> coords;
    std::vector<double> paramCoords;
    gmsh::model::mesh::getNodes(vert, coords, paramCoords, 1, std::abs(curve), true, false);

    /* Edges in the curve */
    std::vector<int> elementTypes;
    std::vector<std::vector<size_t>> elementTags;
    std::vector<std::vector<size_t>> nodeTags;
    gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,1,curve);
    if (elementTypes.size() != 1) {
      error("elementTypes.size() = {}", elementTypes.size());
      return false;
    }
    vector<id2> edges;
    F(i,nodeTags[0].size()/2) {
      edges.push_back({id(nodeTags[0][2*i]),id(nodeTags[0][2*i+1])});
    }

    bool okov =  getOrderedVerticesFromEdges(vStart, edges, vertices);
    if (!okov) {
      error("failed to get ordered vertices");
      return false;
    }
    points.resize(vertices.size(),{DBL_MAX,DBL_MAX,DBL_MAX});
    F(i,vertices.size()) {
      bool found = false;
      FC(j,vert.size(),vert[j] == vertices[i]) {
        points[i] = {coords[3*j], coords[3*j+1], coords[3*j+2]};
        found = true;
        break;
      }
      if (!found) {
        error("getCurveOrderedVertices | curve {}, vertex {} not found in vert = {}", curve, vertices[i], vert);
        return false;
      }
    }

    return true;
  }

  bool compute_quad_adjacencies(
      const vector<id4>& quads,
      vector<sid4>& quad_neighbors,
      vector<vector<id>>& nm_quad_neighbors) {
    quad_neighbors.clear();
    quad_neighbors.resize(quads.size(),{NO_ID,NO_ID,NO_ID,NO_ID});
    nm_quad_neighbors.clear();

    constexpr size_t NBF = 4;

    /* Store element 'faces', with duplicates for further 'equality test' */
    std::vector<id2> faces;
    for (size_t i = 0; i < quads.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id2 face = {quads[i][lf],quads[i][(lf+1)%4]};
        std::sort(face.begin(),face.end());
        faces.push_back(face);
      }
    }

    /* Reduce 'duplicated faces' to 'unique faces', keeping the 'old2new' mapping */
    std::vector<size_t> old2new;
    std::vector<id2> uFaces;
    size_t nbUniques = sort_unique_with_perm(faces, uFaces, old2new);

    /* Build the 'unique face to elements' mapping */
    std::vector<std::vector<id>> new2old(nbUniques);
    for (size_t i = 0; i < quads.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id facePos = NBF*i+lf;
        new2old[old2new[facePos]].push_back(facePos);
      }
    }

    /* Loop over 'unique face to elements' and set the element adjacencies */
    constexpr id2 NO_FACE = {NO_ID,NO_ID};
    for (size_t i = 0; i < nbUniques; ++i) {
      if (uFaces[i] == NO_FACE) continue;
      if(uFaces[i][0] == NO_ID) return false;
      if(uFaces[i][1] == NO_ID) return false;
      if (new2old[i].size() == 1) { /* boundary */
        id eltId = new2old[i][0] / NBF;
        id lf = new2old[i][0] % NBF;
        quad_neighbors[eltId][lf] = NO_ID;
      } else if (new2old[i].size() == 2) { /* regular face */
        id e1 = new2old[i][0] / NBF;
        id lf1 = new2old[i][0] % NBF;
        id e2 = new2old[i][1] / NBF;
        id lf2 = new2old[i][1] % NBF;
        quad_neighbors[e1][lf1] = NBF*e2+lf2;
        quad_neighbors[e2][lf2] = NBF*e1+lf1;
      } else if (new2old[i].size() > 2) { /* non manifold face */
        for (size_t j = 0; j < new2old[i].size(); ++j) {
          id e = new2old[i][j] / NBF;
          id lf = new2old[i][j] % NBF;
          std::vector<id> neighs;
          for (size_t k = 0; k < new2old[i].size(); ++k) {
            if (new2old[i][k] != new2old[i][j]) {
              neighs.push_back(new2old[i][k]);
            }
          }
          neighs.shrink_to_fit();
          id pos = nm_quad_neighbors.size();
          nm_quad_neighbors.push_back(neighs);
          quad_neighbors[e][lf] = -((sid) pos + 1);
        }
      }
    }

    /* Reduce memory consumption */
    quad_neighbors.shrink_to_fit();
    nm_quad_neighbors.shrink_to_fit();

    return true;
  }

  id add_vertex(QMesh& M, vec3 pt, double size = DBL_MAX, std::pair<int,int> entity = {-1,-1}) {
    id v = M.points.size();
    M.points.push_back(pt);
    M.size.push_back(size);
    M.entity.push_back(entity);
    return v;
  }

  // id add_vertex(QMesh& M, vec3 pt, bool onBdr = false, bool onCorner = false, double size = DBL_MAX, std::pair<int,int> entity = {-1,-1}) {
  //   id v = M.points.size();
  //   M.points.push_back(pt);
  //   // M.onBoundary.push_back(onBdr);
  //   // M.onCorner.push_back(onCorner);
  //   M.size.push_back(size);
  //   // M.geoEntity.push_back(entity);
  //   M.entity.push_back(entity);
  //   // info("add_vertex | pt = {}, onBdr = {}, onCorner = {}, size = {}, entity = {}", pt, onBdr, onCorner, size, entity);
  //   return v;
  // }

  size_t add_quad(QMesh& M, id4 vert, id color, int ent) {
    id q = M.quads.size();
    M.quads.push_back(vert);
    M.color.push_back(color);
    M.quad_neighbors.push_back({NO_SID,NO_SID,NO_SID,NO_SID});
    M.quadEntity.push_back(ent);
    // info("add_quad | vert = {}, color = {}, ent = {}", vert, color, ent);
    return q;
  }

  void extract_chord_internal_edges(const vector<id4>& quads, const vector<id>& chord, vector<id2>& edges) {
    F(j, chord.size()) {
      id qs = chord[j];
      id q = qs / 2;
      id s = qs % 2;
      F(k, 2) {
        id v1 = quads[q][(2*k+s)%4];
        id v2 = quads[q][(2*k+s+1)%4];
        edges.push_back(sorted(v1,v2));
      }
    }
    sort_unique(edges);
  }

  bool transfinite_interpolation(
      const vector<vec3>& c1,
      const vector<vec3>& c2,
      const vector<vec3>& c3,
      const vector<vec3>& c4,
      vector<vec3>& pts) {
    if (c1.size() <= 2 || c2.size() <= 2 || c3.size() <= 2 || c4.size() <= 2) {
      error("cannot TFI, c1.size={}, c2.size={}, c3.size={}, c4.size={}", c1.size(),c2.size(),c3.size(),c4.size());
      return false;
    }
    if (c1.size() != c3.size() || c2.size() != c4.size()) {
      error("cannot TFI, c1.size={}, c2.size={}, c3.size={}, c4.size={}", c1.size(),c2.size(),c3.size(),c4.size());
      return false;
    }

    size_t Ni = c1.size()-2;
    size_t Nj = c2.size()-2;

    vector<vec3> c1_u, c3_u, c2_v, c4_v;
    c1_u = std::vector<vec3>(c1.begin()+1, c1.end()-1);
    c3_u = std::vector<vec3>(c3.begin()+1, c3.end()-1);
    c2_v = std::vector<vec3>(c2.begin()+1, c2.end()-1);
    c4_v = std::vector<vec3>(c4.begin()+1, c4.end()-1);
    std::reverse(c3_u.begin(),c3_u.end());
    std::reverse(c4_v.begin(),c4_v.end());

    pts.resize(Ni*Nj);
    F(i,Ni) F(j,Nj) {
      double u = (1.+i) / (1.+Ni);
      double v = (1.+j) / (1.+Nj);
      pts[Ni*j+i] = (1.-v) * c1_u[i] + v * c3_u[i] + (1.-u) * c4_v[j] + u * c2_v[j] 
        - ((1.-u)*(1.-v)*c1[0] + u*v*c3[0] + u * (1.-v) * c2[0] + (1.-u)*v*c4[0]);
    }

    return true;
  }
}


namespace QMT {
  using namespace QMT_Utils;
  using namespace QMT_SMP_Utils;

  struct SizeMap {
    double hmin = 0.;
    double hmax = 1.e22;
    double Hmin = DBL_MAX;
    double Hmax = -DBL_MAX;
    int H_tag = -1;

    SizeMap(double hmin_, double hmax_, int H_tag_) : hmin(hmin_), hmax(hmax_), H_tag(H_tag_) {
      vector<int> tags;
      gmsh::view::getTags(tags);
      if (H_tag == -1 || tags.size() == 0) {
        warn("SizeMap constructor, tags: {}. Field H (tag {}) not found", tags, H_tag_);
        H_tag = -1;
      }
      if (H_tag != -1) {
          compute_Hmin_Hmax();
          double vmin, vmax;
          if (hmin != 0.) {
            vmax = hmin * (exp(-Hmin)/exp(-Hmax));
            vmin = hmin * (exp(-Hmax)/exp(-Hmax));
            info("SizeMap, hmin = {} (user), H range = [{}, {}] (cross field) => sizemap range = [{}, {}]", hmin, Hmin, Hmax, vmin, vmax);
          } else if (hmax != 1.e22) {
            vmax = hmax * (exp(-Hmin)/exp(-Hmin));
            vmin = hmax * (exp(-Hmax)/exp(-Hmin));
            info("SizeMap, hmax = {} (user), H range = [{}, {}] (cross field) => sizemap range = [{}, {}]", hmax, Hmin, Hmax, vmin, vmax);
          } else {
            error("SizeMap, to use H, size_min or size_max must be defined");
          }
      } else {
        if (hmin == 0. && hmax == 1.e22) {
          error("SizeMap, no input size (hmin or hmax)");
        } else if (hmin != 0.) {
          info("SizeMap, using uniform hmin = {} (user)", hmin);
        } else if (hmax != 1.e22) {
          info("SizeMap, using uniform hmax = {} (user)", hmax);
        }
      }
    };

    bool compute_Hmin_Hmax() {
      std::vector<std::string> dataType;
      std::vector<int> numElements;
      std::vector<std::vector<double> > data;
      gmsh::view::getListData(H_tag, dataType, numElements, data);
      Hmin = DBL_MAX;
      Hmax = -DBL_MAX;
      F(i,data[0].size()) {
        Hmin = std::min(Hmin, data[0][i]);
        Hmax = std::max(Hmax, data[0][i]);
      }
      if (Hmin == DBL_MAX || Hmax == -DBL_MAX) {
        error("Hmin = {}, Hmax = {}", Hmin, Hmax);
        return false;
      }
      return true;
    }

    double eval(vec3 pt) const {
      if (H_tag == -1) return hmin != 0. ? hmin : hmax;
      vector<double> values;
      gmsh::view::probe(H_tag, pt[0], pt[1], pt[2], values);
      if (values.size() == 0) {
        error("probe failed at pt = {}", pt);
        return DBL_MAX;
      }
      double val = 0.;
      if (hmin != 0.) {
        val = hmin * (exp(-values[0])/exp(-Hmax));
      } else if (hmax != 1.e22) {
        val = hmax * (exp(-values[0])/exp(-Hmin));
      }
      if (val <= 0.) warn("size(pt={}) = {}", pt, val);
      return val;
    }
  };


  /* warning: call the gmsh API (via sizemap.eval()) */
  bool sample_curve(const std::vector<vec3>& pts, size_t N, const SizeMap& sizemap, vector<vec3>& newPts) {
    newPts.clear();
    if (N == 0) return true;

    /* Size map size(t) */
    vector<double> size(pts.size(),0.);
    F(i, size.size()) size[i] = sizemap.eval(pts[i]);

    vector<double> Pri(pts.size(),0.);
    /* Integral of inverse, Pri = int(1/size(t),t) */
    F(i,pts.size()-1.) {
      Pri[i+1] = Pri[i] + 1./(0.5*(size[i]+size[i+1])) * length(pts[i+1]-pts[i]);
    }

    vector<double> targetLens(N, 0.);
    F(i,N) {
      double n = double(1.+i)/double(1.+N) * Pri.back();
      double len_j = 0.;
      double len_jp1 = 0.;
      F(j,pts.size()-1) {
        len_jp1 = len_j + length(pts[j+1] - pts[j]);
        if (Pri[j] <= n && n < Pri[j+1]) {
          double lambda = (n - Pri[j]) / (Pri[j+1] - Pri[j]);
          targetLens[i] = (1.-lambda) * len_j + lambda * len_jp1;
        } else if (n == Pri[j+1]) {
          targetLens[i] = len_jp1;
        }
        len_j = len_jp1;
      }
    }

    size_t prev_j = 0;
    double prev_acc = 0.;
    F(i,N) {
      double targetLen = targetLens[i];

      bool found = false;
      double acc = prev_acc;
      for(size_t j = prev_j; j < pts.size()-1; ++j) {
        double len_j = acc;
        acc += length(pts[j+1]-pts[j]);
        double len_jp1 = acc;

        if (len_j < targetLen && targetLen <= len_jp1) {
          double lambda = (targetLen - len_j) / (len_jp1 - len_j);
          vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
          newPts.push_back(pt);
          found = true;
          prev_j = j;
          prev_acc = len_j;
          break;
        }
      }
      if (!found) {
        error("sample point not found !");
        return false;
      }
    }

    return true;
  }


  bool build_chord(
      const vector<id4>& quads, 
      const vector<sid4>& quad_neighbors, 
      id qsInit,
      vector<id>& chord) {

    /* BFS */
    vector<bool> visited(2*quads.size(),false);
    std::queue<id> Q;
    Q.push(qsInit);
    visited[qsInit] = true;
    while (Q.size() > 0) {
      id qs = Q.front();
      id q = qs / 2;
      id side = qs % 2;
      Q.pop();
      chord.push_back(qs);

      sid4 neighs = quad_neighbors[q];

      FC(le, 4, le%2 == side) { /* chord propagation dir */
        sid qe = neighs[le];
        if (qe == NO_ID) continue;
        if (qe < 0) {
          error("build_chord | non manifold adjacencies not supported yet");
          return false;
        }
        id aq = qe / 4;
        id ale = qe % 4;
        id next = 2*aq+(ale%2);
        if (visited[next]) continue;

        Q.push(next);
        visited[next] = true;
      }
    }

    return chord.size() > 0;
  }

  bool build_chords(
      const vector<id4>& quads, 
      const vector<sid4>& quad_neighbors, 
      vector<vector<id>>& chords) {
    chords.clear();
    chords.reserve(10000);

    vector<bool> done(2*quads.size(),false);
    F(c,quads.size()) F(s,2) {
      id qsInit = 2*c+s;
      if (done[qsInit]) continue;
      vector<id> chord;
      bool ok = build_chord(quads, quad_neighbors, qsInit, chord);
      if (!ok) {
        error("failed to compute chord");
        return false;
      }
      chords.push_back(chord);
      F(j,chord.size()) done[chord[j]] = true;
    }

    return true;
  }

  bool chord_is_collapsible(const QMesh& M, const Chord& chord, const vector<int>* valence = NULL) {
    if (valence && valence->size() != M.points.size()) {
      error("M.points.size() = {} and valence.size() = {}", M.points.size(), valence->size());
      return false;
    }
    bool collapse_val3_on_bdr = false;
    bool collapse_val5_on_bdr = false;

    F(i, chord.size()) {
      id q = chord[i] / 2;
      id side = chord[i] % 2;
      if (M.quads[q][0] == NO_ID) continue;

      sid4 neighs = M.quad_neighbors[q];
      if (neighs[(side+1)%4] == NO_SID && neighs[(side+3)%4] == NO_SID) {
        /* collapse would remove a part of the model */
        return false;
      }

      if (neighs[(side+1)%4] != NO_SID && neighs[(side+3)%4] != NO_SID) {
        /* exclude case where both neighbors are adjacent (making a loop)
         * not supported because two distinct edges would have the same pair of vertices
         * and datastructures assume there is only one edge for a pair of vertices v1-v2 */
        id n1 = neighs[side+1];
        id n2 = neighs[(side+3)%4];
        id nn1 = M.quad_neighbors[n1/4][(n1%4+2)%4];
        if (nn1 != NO_ID && nn1/4 == n2/4) {
          return false;
        }
      }

      FC(le, 4, le%2 == side) { /* chord propagation dir */
        id v1 = M.quads[q][le];
        id v2 = M.quads[q][(le+1)%4];
        if (M.entity[v1].first == 0 && M.entity[v2].first == 0) { /* both on corner */
          return false;
        }
        if (valence && !collapse_val3_on_bdr && (*valence)[v1] == 3 && M.entity[v1].first == 2 && M.entity[v2].first <= 1)
          return false;
        if (valence && !collapse_val3_on_bdr && (*valence)[v2] == 3 && M.entity[v2].first == 2 && M.entity[v1].first <= 1)
          return false;
        if (valence && !collapse_val5_on_bdr && (*valence)[v1] == 5 && M.entity[v1].first == 2 && M.entity[v2].first <= 1)
          return false;
        if (valence && !collapse_val5_on_bdr && (*valence)[v2] == 5 && M.entity[v2].first == 2 && M.entity[v1].first <= 1)
          return false;

        sid qe = neighs[le];
        if (qe == NO_ID) continue;
        if (qe < 0) {
          error("  non manifold not supported yet");
          return false;
        }
        id aq = qe / 4;
        id ale = qe % 4;
        id av1 = M.quads[aq][ale];
        id av2 = M.quads[aq][(ale+1)%4];

        /* Reject collapse of edges if both nodes are on
         * the boundary and not an bdr edge */
        if (M.entity[av1].first <= 1 && M.entity[av2].first <= 1 && neighs[le] != NO_ID) {
          return false;
        }
      }
    }

    return true;
  }

  bool chord_width_statistics(const QMesh& M, const Chord& chord, double& wmin, double& wavg, double& wmax) {
    vector<bool> quadSideDone(M.quads.size()*2,false);
    wmax = -DBL_MAX;
    wmin = DBL_MAX;
    wavg = 0.;
    double avg_sum = 0.;
    size_t nb_probe_fail = 0;
    size_t nb_probe_ok = 0;
    F(j,chord.size()) {
      id q = chord[j] / 2;
      id side = chord[j] % 2;
      if (quadSideDone[2*q+side]) continue;
      F(k,2) {
        id le = (k == 0) ? side : side+2;
        id v1 = M.quads[q][le];
        id v2 = M.quads[q][(le+1)%4];
        if (v1 == NO_ID || v2 == NO_ID) continue;
        vec3 p1 = M.points[v1];
        vec3 p2 = M.points[v2];
        double clen = length(p2-p1);
        double s1 = M.size[v1];
        double s2 = M.size[v2];
        if (s1 == DBL_MAX || s2 == DBL_MAX) {
          warn("size not defined at edge v1={},v2={}", v1, v2);
          continue;
        }
        clen *= 1. / (0.5 * (s1 + s2));
        wavg += clen;
        avg_sum += 1.;
        wmax = std::max(wmax, clen);
        wmin = std::min(wmin, clen);
      }
      quadSideDone[2*q+side] = true;
    }
    if (avg_sum == 0.) {
      error("no edge in chord ?");
      return false;
    }
    wavg /= avg_sum;

    return true;
  }

  bool collapse_double_quad_to_line(QMesh& M, 
      id q1, 
      id q2, 
      vector<vector<id>>& v2q) {
    /* Collapse configuration: 
     *
     *    |   |   |              |
     * ---3---2---5---        ---2---
     *    |   |   |              |
     * n1 |q1 | q2| n2  --->   n1|n2
     *    |   |   |              |
     * ---0---1---4---        ---1---
     *    |   |   |              |
     */
    if (M.quads[q1][0] == NO_ID || M.quads[q2][0] == NO_ID) return false;
    id vert[6] = {NO_ID,NO_ID,NO_ID,NO_ID,NO_ID,NO_ID};
    sid4 neigh1 = M.quad_neighbors[q1];
    sid4 neigh2 = M.quad_neighbors[q2];
    id n1 = NO_ID;
    id n2 = NO_ID;
    FC(le1,4,neigh1[le1] != NO_ID && neigh1[le1]/4==q2) {
      FC(le2,4,neigh2[le2] != NO_ID && neigh2[le2]/4==q1) {
        /* TODO / warning: this numbering is dependant 
         * on the coherant cw/ccw ordering of the quad vertices
         * better to have a version without this assumption */
        vert[0] = M.quads[q1][(le1+3)%4];
        vert[1] = M.quads[q1][le1];
        vert[2] = M.quads[q1][(le1+1)%4];
        vert[3] = M.quads[q1][(le1+2)%4];
        if (M.quads[q2][le2] == vert[2]) {
          vert[4] = M.quads[q2][(le2+2)%4];
          vert[5] = M.quads[q2][(le2+3)%4];
        } else if (M.quads[q2][le2] == vert[1]) {
          vert[4] = M.quads[q2][(le2+3)%4];
          vert[5] = M.quads[q2][(le2+2)%4];
        } else {
          error("failed to found double quad config ..., quad[{}] = {}, quad[{}] = {}", q1, M.quads[q1], q2, M.quads[q2]);
          return false;
        }
        n1 = neigh1[(le1+2)%4];
        n2 = neigh2[(le2+2)%4];
      }
    }


    if (vert[0] == NO_ID) {
      error("collapse_double_quad_to_line | matching config not found");
      return false;
    }
    if (M.entity[vert[0]].first == 0 || M.entity[vert[3]].first == 0 
        || M.entity[vert[4]].first == 0 || M.entity[vert[5]].first == 0) {
      error("collapse_double_quad_to_line | 'to collapse' vertex is locked");
      return false;
    }
    if (M.entity[vert[0]].first <= 1 && M.entity[vert[3]].first <= 1) {
      error("collapse_double_quad_to_line | 0-3 on boundary not supported");
      return false;
    }
    if (M.entity[vert[4]].first <= 1 && M.entity[vert[5]].first <= 1) {
      error("collapse_double_quad_to_line | 4-5 on boundary not supported");
      return false;
    }
    if (n1 == NO_ID || n2 == NO_ID) {
      error("collapse_double_quad_to_line | missing adj. quads, not supported");
      return false;
    }

    /* Update vertices of neighbor quads */
    id mapping[6] = {vert[1],NO_ID,NO_ID,vert[2],vert[1],vert[2]};
    FC(lv, 6, lv != 1 && lv != 2) {
      id v = vert[lv];
      F(lq,v2q[v].size()) {
        id aq = v2q[v][lq];
        FC(lv2,4,M.quads[aq][lv2] == v) {
          M.quads[aq][lv2] = mapping[lv];
        }
      }
    }

    /* Update quad and neighbors */
    M.quad_neighbors[n1/4][n1%4] = n2;
    M.quad_neighbors[n2/4][n2%4] = n1;
    F(lq,2) {
      id q = (lq == 0) ? q1 : q2;
      M.quads[q] = {NO_ID,NO_ID,NO_ID,NO_ID};
      M.quad_neighbors[q] = {NO_ID, NO_ID, NO_ID, NO_ID};
    }

    /* Update vertex to quads */
    vector<id> common = intersection(v2q[vert[1]],v2q[vert[2]]);
    {
      vector<id> adj_quads = merge(v2q[vert[1]], merge(v2q[vert[0]],v2q[vert[4]]));
      adj_quads = difference(adj_quads,common);
      v2q[vert[1]] = adj_quads;
    }
    {
      vector<id> adj_quads = merge(v2q[vert[2]], merge(v2q[vert[3]],v2q[vert[5]]));
      adj_quads = difference(adj_quads,common);
      v2q[vert[2]] = adj_quads;
    }
    FC(lv,6,lv!=1&&lv!=2) v2q[vert[lv]].clear();

    return true;
  }

  bool collapse_quad_to_vertex(QMesh& M, id q, 
      vector<vector<id>>& v2q) {
    id target = NO_ID;

    /* Verify it can be collapsed */
    id4 vert = M.quads[q];
    vector<id> locked_vert;
    FC(lv,4,M.entity[vert[lv]].first == 0) {
      target = vert[lv];
      locked_vert.push_back(vert[lv]);
    }
    sort_unique(locked_vert);
    if (locked_vert.size() >= 2) {
      error("locked vertices: {}, cannot collapse", locked_vert);
      return false;
    }

    /* Check diagonals */
    if (M.entity[vert[0]].first <= 1 && M.entity[vert[2]].first <= 1) {
      return false;
    } else if (M.entity[vert[1]].first <= 1 && M.entity[vert[3]].first <= 1) {
      return false;
    }

    vec3 pt = {0,0,0};
    if (target == NO_ID) {
      bool newPtOnBdr = true;
      double targetSize = DBL_MAX;
      bool onBdr[4] = {M.entity[vert[0]].first <= 1, M.entity[vert[1]].first <= 1, M.entity[vert[2]].first <= 1, M.entity[vert[3]].first <= 1};
      size_t nbOnBdr = (size_t) onBdr[0] + (size_t) onBdr[1] + (size_t) onBdr[2] + (size_t) onBdr[3];
      pair<int,int> ent = {-1,-1};
      int entityDim = -1;
      int entityTag = -1;
      if (nbOnBdr == 0) {
        pt = 0.25 * (M.points[M.quads[q][0]] + M.points[M.quads[q][1]]
            + M.points[M.quads[q][2]] + M.points[M.quads[q][3]]);
        newPtOnBdr = false;
        targetSize = 0.25 * (M.size[M.quads[q][0]] + M.size[M.quads[q][1]]
            + M.size[M.quads[q][2]] + M.size[M.quads[q][3]]);
        entityDim = 2;
        entityTag = M.quadEntity[q];
      } else if (nbOnBdr == 1) {
        FC(lv,4,onBdr[lv]) {
          target = vert[lv];
        }
      } else if (nbOnBdr == 2) {
        FC(lv,4,onBdr[lv] && onBdr[(lv+1)%4]) {
          pt = 0.5 * (M.points[vert[lv]] + M.points[vert[(lv+1)%4]]);
          targetSize = 0.5 * (M.size[vert[lv]] + M.size[vert[(lv+1)%4]]);
          entityDim = 1;
          if (M.entity[vert[lv]].first == 1) {
            entityTag = M.entity[vert[lv]].second;
          } else if (M.entity[vert[(lv+1)%4]].first == 1) {
            entityTag = M.entity[vert[(lv+1)%4]].second;
          } else {
            entityTag = -1;
            //warn("case not supported, collapse extremities on bdr but not on curve entity");
          }
        }
      } else if (nbOnBdr == 3) {
        FC(lv,4,onBdr[lv] && onBdr[(lv+1)%4] && onBdr[(lv+2)%4]) {
          target = vert[(lv+1)%4];
        }
      } else if (nbOnBdr == 4) {
        error("the four quad vertices are on the boundary");
        return false;
      }
      if (target == NO_ID) {
        // target = add_vertex(M, pt, newPtOnBdr, false, targetSize, {entityDim,entityTag});
        target = add_vertex(M, pt, targetSize, {entityDim,entityTag});
        // if (entityTag == -1) warn("collapse_quad_to_vertex | target = {}, entityDim = {}, entityTag = {}", target, entityDim, entityTag);
        v2q.resize(M.points.size());
      }
    }

    /* Update quad neighbor vertices and internal points */
    F(lv,4) {
      id v = vert[lv];
      F(lq,v2q[v].size()) {
        id aq = v2q[v][lq];
        FC(lv2,4,M.quads[aq][lv2] == v) {
          M.quads[aq][lv2] = target;
        }
      }
    }

    /* Update vertex to quads */
    vector<id> adj_quads = merge(
        merge(v2q[vert[0]],v2q[vert[1]]),
        merge(v2q[vert[2]],v2q[vert[3]]));
    adj_quads = difference(adj_quads,{q});
    v2q[target] = adj_quads;
    FC(lv,4,vert[lv] != target) v2q[vert[lv]].clear();

    /* Update quad and neighbors */
    M.quads[q] = {NO_ID,NO_ID,NO_ID,NO_ID};
    sid4 neigh = M.quad_neighbors[q];
    FC(le,4,neigh[le] > 0 && neigh[le] != NO_ID) {
      id ne = neigh[le];
      M.quad_neighbors[ne/4][ne%4] = NO_ID;
    }
    M.quad_neighbors[q] = {NO_ID, NO_ID, NO_ID, NO_ID};

    return true;
  }

  bool collapse_quad_to_line(QMesh& M, id q, id side,
      vector<vector<id>>& v2q) {
    /* Collapse configuration: 
     *
     *     |   |                 |
     *  ---3---2---        ---targets[1]---
     *     |   |                 |
     * aq1 | q | qq2  --->    aq1|aq2
     *     |   |                 |
     *  ---0---1---        ---targets[0]---
     *     |   |                 |
     */
    id4 vert, les;
    F(lv,4) {
      vert[lv] = M.quads[q][(side+lv)%4];
      les[lv] = (side+lv)%4;
    }

    if (vert[0] == NO_ID) {
      error("invalid collapse candidate, quad {}, vertices: {}", q, vert);
      return false;
    }

    /* Check if collapse to existing vertex */
    id2 targets = {NO_ID,NO_ID};
    F(i,2) {
      id a = (i == 0) ? vert[0] : vert[2];
      id b = (i == 0) ? vert[1] : vert[3];
      if (a != b && M.entity[a].first == 0 && M.entity[b].first == 0) {
        error("both edge extrimities locked, cannot collapse");
        return false;
      }

      int entityDim = -1;
      int entityTag = -1;
      if (a == b) {
        targets[i] = a;
      } else if (M.entity[a].first <= 1 && M.entity[b].first <= 1) {
        if (M.entity[a].first == 0) {
          targets[i] = a;
        } else if (M.entity[b].first == 0) {
          targets[i] = b;
        } else {
          if (M.entity[a].first == 1) {
            entityDim = 1;
            entityTag = M.entity[a].second;
          } else if (M.entity[b].first == 1) {
            entityDim = 1;
            entityTag = M.entity[b].second;
          } else {
            entityDim = 1;
            entityTag = -1; /* both vertices are corners, curve tag unknown ... */
          }
        }
      } else if (M.entity[a].first <= 1 && M.entity[b].first == 2) {
        targets[i] = a;
      } else if (M.entity[a].first == 2 && M.entity[b].first <= 1) {
        targets[i] = b;
      } else {
        entityDim = 2;
        entityTag = M.quadEntity[q];
      }
      if (targets[i] == NO_ID) {
        vec3 pt = 0.5*(M.points[a] + M.points[b]);
        double targetSize = 0.5*(M.size[a] + M.size[b]);
        // id nv = add_vertex(M, pt, pOnBdr, false, targetSize, {entityDim,entityTag});
        id nv = add_vertex(M, pt, targetSize, {entityDim,entityTag});
        targets[i] = nv;
        v2q.resize(M.points.size());
      }
    }

    /* Update neighbor relations */
    sid4 neighs;
    F(le,4) neighs[le] = M.quad_neighbors[q][les[le]];
    FC(le,4,neighs[le] < 0) {
      error("non manifold case not supported yet ...");
      return false;
    }
    if (neighs[1] != NO_ID && M.quad_neighbors[neighs[1]/4][neighs[1]%4]/4 != q) {
      error("invalid neighbor, M.quad_neighbors[neighs[1]/4][neighs[1]%4]/4 = {} instead of {}", M.quad_neighbors[neighs[1]/4][neighs[1]%4]/4,q);
      return false;
    } else if (neighs[3] != NO_ID && M.quad_neighbors[neighs[3]/4][neighs[3]%4]/4 != q) {
      error("invalid neighbor, M.quad_neighbors[neighs[3]/4][neighs[3]%4]/4 = {} instead of {}", M.quad_neighbors[neighs[3]/4][neighs[3]%4]/4,q);
      return false;
    }
    M.quad_neighbors[q] = {NO_SID, NO_SID, NO_SID, NO_SID};
    if (neighs[1] != NO_ID) M.quad_neighbors[neighs[1]/4][neighs[1]%4] = neighs[3];
    if (neighs[3] != NO_ID) M.quad_neighbors[neighs[3]/4][neighs[3]%4] = neighs[1];

    /* Update vertices of neighbor quads */
    id mapping[4] = {targets[0], targets[0], targets[1], targets[1]};
    F(lv, 4) {
      id v = vert[lv];
      if(v == NO_ID) continue;
      F(lq,v2q[v].size()) {
        id aq = v2q[v][lq];
        FC(lv2,4,M.quads[aq][lv2] == v) {
          M.quads[aq][lv2] = mapping[lv];
        }
      }
    }
    M.quads[q] = {NO_ID,NO_ID,NO_ID,NO_ID};

    /* Update vertex to quads */
    F(i,2) {
      if (vert[2*i+0] == NO_ID || vert[2*i+1] == NO_ID) continue;
      vector<id> common = intersection(v2q[vert[2*i+0]],v2q[vert[2*i+1]]);
      vector<id> adj_quads = merge(v2q[vert[2*i+0]],v2q[vert[2*i+1]]);
      adj_quads = difference(adj_quads,common);
      v2q[targets[i]] = adj_quads;
    }
    FC(lv,4,vert[lv] != NO_ID && mapping[lv]!=vert[lv]) v2q[vert[lv]].clear();

    return true;
  }

  bool apply_chord_collapse(QMesh& M, const Chord& chord) {
    /* Mark quads */
    vector<vector<id>> q2qs(M.quads.size());
    F(i,chord.size()) {
      id q = chord[i] / 2;
      q2qs[q].push_back(chord[i]);
    }

    /* Check dual band in the loop ... */
    vector<id2> double_quads;
    FC(q,M.quads.size(),q2qs[q].size() == 1) {
      sid4 neigh = M.quad_neighbors[q];
      id side = q2qs[q][0] % 2;
      size_t nb = 0;
      FC(le,4,le % 2 != side && neigh[le] != NO_ID) {
        id aq = neigh[le] / 4;
        if (q2qs[aq].size() == 1) {
          double_quads.push_back(sorted(q,aq));
          nb += 1;
        }
      }
      if (nb == 2) {
        error("triple quad band not supported");
        return false;
      }
    }
    sort_unique(double_quads);

    vector<vector<id>> v2quads(M.points.size());
    FC(q,M.quads.size(),M.quads[q][0] != NO_ID) F(lv,4) v2quads[M.quads[q][lv]].push_back(q);
    F(v,M.points.size()) sort_unique(v2quads[v]);

    /* Loop over double quads */
    F(i,double_quads.size()) {
      bool okc = collapse_double_quad_to_line(M, double_quads[i][0], double_quads[i][1], v2quads);
      if (!okc) {
        error("failed to collapse double quad to one line ...");
        show_qmesh_in_view(M, "failed_double_quad_to_line");
        return false;
      }
    }

    /* Loop over full quad collapse (chord self intersection) */
    FC(q,q2qs.size(),q2qs[q].size() >= 2) {
      bool okc = collapse_quad_to_vertex(M, q, v2quads);
      if (!okc) {
        error("failed to collapse quad to one vertex ...");
        return false;
      }
    }

    /* Loop over collapse where one direction of a quad is collapsed */
    FC(q,q2qs.size(),q2qs[q].size() == 1) {
      if (M.quads[q][0] == NO_ID) continue;
      id side = q2qs[q][0] % 2;
      bool okc = collapse_quad_to_line(M, q, side, v2quads);
      if (!okc) {
        error("failed to collapse quad to one vertex ...");
        return false;
      }
    }

    return true;
  }

  bool project_points_via_discrete_projector(QMesh& M,
      const BoundaryProjector& projector,
      bool onCurves = true,
      bool onSurfaces = true) {
    info("project points on discrete curves and triangulated surfaces ...");
    F(v,M.points.size()) {
      vec3 pt = M.points[v];
      if (M.entity[v].first == 1 || M.entity[v].first == 2) {
        pair<int,int> oldEntity = M.entity[v];
        if (oldEntity.second == -1) {
          int dim = M.entity[v].first;
          int tag = -1;
          double dist;
          bool okc = projector.closestEntity({pt}, dist, dim, tag);
          if (okc) {
            oldEntity = {dim,tag};
            warn("v = {}, mapping from entity ({},{}) to initial one not found, using closest entity ({},{}), dist = {}", v, M.entity[v].first, M.entity[v].second, dim, tag, dist);
          } else {
            warn("v = {}, mapping from entity ({},{}) to initial one not found", v, M.entity[v].first, M.entity[v].second);
            continue;
          }
        }
        if ((onCurves && oldEntity.first == 1) || (onSurfaces && oldEntity.first == 2)) {
          vec3 proj;
          bool okp = projector.project(oldEntity.first,oldEntity.second,pt,proj);
          if (okp) {
            if (proj[0] == DBL_MAX) {
              error("wrong projected point: {}", proj);
              continue;
            }
            M.points[v] = proj;
          } else {
            warn("failed to project point {} on {}", M.points[v], oldEntity);
          }
        }
      }
    }
    return true;
  }

  bool fill_missing_entries_in_entity_mapping(QMesh& M,
      const BoundaryProjector& projector,
      std::map<std::pair<int,int>,std::pair<int,int>>& entityToInitialEntity) {
    info("fill missing entries in entity mapping to initial geometry ...");

    std::map<std::pair<int,int>,vector<vec3> > entityToPoints;
    F(v,M.points.size()) {
      vec3 pt = M.points[v];
      if (M.entity[v].first == 1 || M.entity[v].first == 2) {
        auto it = entityToInitialEntity.find(M.entity[v]);
        if (it == entityToInitialEntity.end()) {
          entityToPoints[M.entity[v]].push_back(pt);
        }
      }
    }
    F(f,M.quads.size()) {
      pair<int,int> ent = {2,M.quadEntity[f]};
      auto it = entityToInitialEntity.find(ent);
      if (it == entityToInitialEntity.end()) {
        auto& it2 = entityToPoints[ent];
        it2.push_back(M.points[M.quads[f][0]]);
        it2.push_back(M.points[M.quads[f][1]]);
        it2.push_back(M.points[M.quads[f][2]]);
        it2.push_back(M.points[M.quads[f][3]]);
      }
    }
    for (const auto& kv: entityToPoints) {
      pair<int,int> entity = kv.first;
      int dim = -1;
      int tag = -1;
      double dist = DBL_MAX;
      bool okc = projector.closestEntity(kv.second, dist, dim, tag);
      if (okc) {
        entityToInitialEntity[entity] = {dim,tag};
        warn("  entity {} ({} points) had no mapping to initial entity, set to closest one {} (dist={})", entity, kv.second.size(), std::make_pair(dim,tag), dist);
      } else {
        error("  entity {} ({} points) had no mapping to initial entity, did NOT found a closest entity", entity, kv.second.size());
      }
    }

    return true;
  }

  bool project_points_on_geo_entities(QMesh& M,
      const std::string& initialGeometryName,
      std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity) {
    std::string current;
    gmsh::model::getCurrent(current);

    bool from_disk = false;
    if (is_file(initialGeometryName.c_str())) {
      warn("horrible temporary solution, loading geometry from disk: {}",initialGeometryName);
      gmsh::model::add("tmp_geometry");
      gmsh::merge(initialGeometryName);
      from_disk = true;
    } else {
      gmsh::model::setCurrent(initialGeometryName);
    }

    map<pair<int,int>, pair<vector<id>,vector<double> > > entity_to_vertices;
    F(v,M.points.size()) {
      vec3 pt = M.points[v];
      if (M.entity[v].first == 1 || M.entity[v].first == 2) {
        pair<int,int> oldEntity = M.entity[v];;
        auto& ref = entity_to_vertices[oldEntity];
        ref.first.push_back(v);
        ref.second.push_back(pt[0]);
        ref.second.push_back(pt[1]);
        ref.second.push_back(pt[2]);
      }
    }
    for (auto& kv: entity_to_vertices) {
      int dim = kv.first.first;
      int tag = kv.first.second;
      info("---- {},{}", dim, tag);
      vector<double> pCoords;
      info("getParametrization ...");
      gmsh::model::getParametrization(dim, tag, kv.second.second, pCoords);
      vector<double> points;
      info("getValue ...");
      gmsh::model::getValue(dim, tag, pCoords, points);
      F(lv,kv.second.first.size()) {
        id v = kv.second.first[lv];
        M.points[v] = {points[3*lv],points[3*lv+1],points[3*lv+2]};
      }
    }
    gmsh::model::setCurrent(current);

    return true;
  }


  bool generate_quad_mesh_from_gmsh_colored_triangulation(
      const std::string& modelName,
      int H_tag,
      double size_min,
      double size_max,
      QMesh& M,
      const BoundaryProjector* projector,
      const std::map<std::pair<int,int>,std::pair<int,int>>* entityToInitialEntity) {
    /* gmsh initialization */
    gmsh::initialize(0, 0, false);

    if (size_min == 0 && size_max == 1.e22) {
      double xmin, ymin, zmin, xmax, ymax, zmax;
      gmsh::model::getBoundingBox(-1,-1,xmin,ymin,zmin,xmax,ymax,zmax);
      double h = 0.08 * length({xmax-xmin,ymax-ymin,zmax-zmin});
      warn("size_min = {} and size_max = {}, using size_min = {} (0.08 of bounding box diagonal)", size_min, size_max, h);
      size_min = h;
    }

    gmsh::model::setCurrent(modelName);

    info("generate quad mesh from gmsh colored triangulation ...");

    SizeMap sizemap(size_min, size_max, H_tag);

    /* 1. Import the patchs from gmsh and store the relevant information */
    vector<id4> patches;
    vector<int> patchEntity;
    unordered_map<id2,vector<vec3>,id2Hash> pairToPoints;
    unordered_map<id2,int,id2Hash> pairToEntity;

    std::map<int,id> nodeToMeshVertex; /* mapping from geometric node to gmsh mesh vertex */
    std::map<int,id> meshVertexToV; /* mapping from gmsh mesh vertex to QMesh vertex */
    { /* Loop over Geometry Nodes */
      vectorpair nodes;
      gmsh::model::getEntities(nodes,0);
      info("- {} nodes", nodes.size());
      F(i,nodes.size()) {
        id node = nodes[i].second;
        std::vector<size_t> vertices;
        std::vector<double> coords;
        std::vector<double> paramCoords;
        gmsh::model::mesh::getNodes(vertices, coords, paramCoords, 0, node, false, false);
        if (vertices.size() != 1) {
          error("node {}: vertices.size() = {} (should be one)", node, vertices.size());
          return false;
        }
        vec3 pt = {coords[0],coords[1],coords[2]};
        double size = sizemap.eval(pt); /* call the gmsh API */
        pair<int,int> entity = {-1,-1};
        auto it = entityToInitialEntity->find({0,node});
        if (it != entityToInitialEntity->end()) entity = it->second;
        id nv = add_vertex(M, pt, size, entity);
        nodeToMeshVertex[node] = vertices[0];
        meshVertexToV[vertices[0]] = nv;
      }
    }

    { /* Loop over Geometry Curves */
      vectorpair curves;
      gmsh::model::getEntities(curves,1);
      info("- {} curves", curves.size());
      F(i, curves.size()) {
        int curve = curves[i].second;
        vectorpair cnodes;
        gmsh::model::getBoundary({curves[i]},cnodes,false,false,false);
        if (cnodes.size() != 2) continue;
        id node1 = cnodes[0].second;
        id node2 = cnodes[1].second;
        id v1 = nodeToMeshVertex[node1];
        vector<id> vertices;
        vector<vec3> points;
        bool okc = getCurveOrderedVertices(std::abs(curve), vertices, points, v1);
        if (!okc) {
          error("curve = {}, failed to get curve vertices ...", curve);
          return false;
        }
        id2 scurve = sorted(node1,node2);
        if (scurve[0] != node1) std::reverse(points.begin(),points.end());
        pairToPoints[scurve] = points;
        pairToEntity[scurve] = curve;
      }
    }

    { /* Loop over Geometry Surfaces (should be quad patches) */
      vectorpair surfaces;
      gmsh::model::getEntities(surfaces,2);
      info("- {} surfaces", surfaces.size());
      bool ok = true;
      F(s,surfaces.size()) {
        id4 quad;
        vectorpair sBdr;
        gmsh::model::getBoundary({surfaces[s]}, sBdr, false, true, false);
        if (sBdr.size() != 4) {
          error("surface {}: wrong number of boundaries: {}", surfaces[s], sBdr);
          ok = false;
          continue;
        }
        /* Loop over boundaries of patch surfaces[s] */ 
        F(j,4) {
          vectorpair cnodes;
          gmsh::model::getBoundary({sBdr[j]},cnodes,false,false,false);
          quad[j] = cnodes[0].second;
          id node1 = cnodes[0].second;
          id node2 = cnodes[1].second;
          id2 scurve = sorted(node1,node2);
          if (pairToPoints.find(scurve) == pairToPoints.end()) {
            error("surface {}: curve pair {} not found", quad, scurve);
            return false;
          }
        }
        { /* check quad has 4 distinct vertices */
          vector<id> vert;
          F(k,4) vert.push_back(quad[k]);
          sort_unique(vert);
          if (vert.size() != 4) {
            error("surface {}: wrong quad: {}", surfaces[s].second, quad);
            return false;
          }
        }
        patches.push_back(quad);
        patchEntity.push_back(surfaces[s].second);
      }
      if (!ok) return false;
    }

    /* 2. Fill the quad mesh by subdividing the patches 
     *    - use the sizemap and chord expansion to determine the number of vertices
     *      to add on each curve
     *    - use the sizemap to position the points on curves
     *    - use transfinite interpolation to position the points inside patches */
    vector<sid4> quad_neighbors;
    vector<vector<id>> nm_quad_neighbors;
    bool okn = compute_quad_adjacencies(patches, quad_neighbors, nm_quad_neighbors);
    if (!okn) {
      error("failed to compute quad patch adjacencies");
      return false;
    }

    vector<vector<id>> chords;
    bool okc = build_chords(patches, quad_neighbors, chords);
    if (!okc) {
      error("failed to compute patches chord basis");
      return false;
    }

    info("creating points on curves (via chord expansion) ...");
    unordered_map<id2,vector<id>,id2Hash> pairToNewVertices;
    F(i, chords.size()) {
      /* Compute chord average width (taking sizemap into account) */
      const vector<id>& chord = chords[i];
      vector<id2> edges;
      extract_chord_internal_edges(patches, chord, edges);
      double wavg = 0.;
      double avg_sum = 0.;
      F(j, edges.size()) {
        id node1 = edges[j][0];
        id node2 = edges[j][1];
        if (nodeToMeshVertex.find(node1) == nodeToMeshVertex.end()) {
          error("node1={} not found in nodeToMeshVertex", node1);
          return false;
        }
        if (nodeToMeshVertex.find(node2) == nodeToMeshVertex.end()) {
          error("node2={} not found in nodeToMeshVertex", node2);
          return false;
        }
        id v1 = meshVertexToV[nodeToMeshVertex[node1]];
        id v2 = meshVertexToV[nodeToMeshVertex[node2]];
        vec3 p1 = M.points[v1];
        vec3 p2 = M.points[v2];
        double clen = length(p2-p1);
        /* warning: sizemap call the gmsh api (probe function) */
        double s1 = M.size[v1];
        double s2 = M.size[v2];
        if (s1 == DBL_MAX || s2 == DBL_MAX) {
          warn("sizemap probe failed at node1={} or node2={}", node1, node2);
          continue;
        }
        clen *= 1. / (0.5 * (s1 + s2));
        wavg += clen;
        avg_sum += 1.;
      }
      if (avg_sum == 0.) {
        error("avg_sum = 0., no edge in chord ?");
        return false;
      }
      wavg /= avg_sum;

      /* Assign number of points */
      double denom = 1.;
      if (size_min != 0.) {
        denom = size_min;
      } else if (size_max != 1.e22) {
        denom = size_max;
      }
      size_t nb_ipts = 0;
      nb_ipts = wavg / denom;
      info("  chord {}, avg. scaled width: {}, {} interior points", i, wavg, nb_ipts);

      /* Sample the curves */
      F(j, edges.size()) {
        auto it = pairToPoints.find(edges[j]);
        if (it == pairToPoints.end()) {
          error("curve not found in pairToPoints");
          return false;
        }
        const vector<vec3>& pts = it->second;
        vector<vec3> ipts;
        /* warning: call the gmsh API (via sizemap.eval()) */
        bool oks = sample_curve(pts, nb_ipts, sizemap, ipts);
        if (!oks) {
          error("  ! failed to sample curve, N={}", nb_ipts);
          return false;
        }
        int curve = pairToEntity[edges[j]];
        pair<int,int> entity = {-1,-1};
        auto itt = entityToInitialEntity->find({1,curve});
        if (itt != entityToInitialEntity->end()) entity = itt->second;
        vector<id> nvert;
        F(k,ipts.size()) {
          double size = sizemap.eval(ipts[k]); /* call the gmsh API */
          id nv = add_vertex(M, ipts[k], size, entity);
          nvert.push_back(nv);
        }
        pairToNewVertices[edges[j]] = nvert;
      }
    }

    info("creating points inside the {} patches (transfinite interpolation) and building the subdivided quads ...", patches.size());
    F(c,patches.size()) {
      vector<vector<id>>   curveVertices(4);
      vector<vector<vec3>> curvePoints(4);
      id4 patchNV;
      F(le,4) {
        id node1 = patches[c][le];
        id node2 = patches[c][(le+1)%4];
        id2 sedge = sorted(node1,node2);
        vector<id> ivert = pairToNewVertices[sedge];
        if (node1 != sedge[0]) std::reverse(ivert.begin(),ivert.end());
        curvePoints[le].resize(2+ivert.size());
        id v1 = meshVertexToV[nodeToMeshVertex[node1]];
        id v2 = meshVertexToV[nodeToMeshVertex[node2]];
        patchNV[le] = v1;
        curvePoints[le][0] = M.points[v1];
        curvePoints[le].back() = M.points[v2];
        F(k,ivert.size()) curvePoints[le][1+k] = M.points[ivert[k]];
        curveVertices[le] = ivert;
      }

      /* Create the interior points */
      vector<vec3> ipts;
      if (curvePoints[0].size() > 2 && curvePoints[1].size() > 2)  {
        bool oktfi = transfinite_interpolation(curvePoints[0],curvePoints[1],curvePoints[2],curvePoints[3], ipts);
        if (!oktfi) {
          error("generate quads, failed to TFI");
          return false;
        }
      }
      pair<int,int> entity = {-1,-1};
      auto itt = entityToInitialEntity->find({2,patchEntity[c]});
      if (itt != entityToInitialEntity->end()) entity = itt->second;

      vector<id> qVertices(ipts.size(),NO_ID);
      F(i,ipts.size()) {
        double size = sizemap.eval(ipts[i]); /* call the gmsh API */
        id nv = add_vertex(M, ipts[i], size, entity);
        qVertices[i] = nv;
      }

      /* Generate refined quads in patch */
      std::reverse(curveVertices[2].begin(),curveVertices[2].end());
      std::reverse(curveVertices[3].begin(),curveVertices[3].end());
      vector<vector<id>> allVertices(2+curveVertices[0].size());
      F(i,allVertices.size()) allVertices[i].resize(2+curveVertices[1].size(),NO_ID);
      /* corners */
      allVertices[0][0]         = patchNV[0];
      allVertices.back()[0]     = patchNV[1];
      allVertices.back().back() = patchNV[2];
      allVertices[0].back()     = patchNV[3];
      /* boundaries */
      F(i,curveVertices[0].size()) allVertices[i+1][0] = curveVertices[0][i];
      F(i,curveVertices[2].size()) allVertices[i+1].back() = curveVertices[2][i];
      F(j,curveVertices[1].size()) allVertices.back()[1+j] = curveVertices[1][j];
      F(j,curveVertices[3].size()) allVertices[0][1+j] = curveVertices[3][j];
      /* interior */
      F(i,curveVertices[0].size()) F(j,curveVertices[1].size()) {
        allVertices[1+i][1+j] = qVertices[curveVertices[0].size()*j+i];
      }

      F(i,curveVertices[0].size()+1) F(j,curveVertices[1].size()+1) {
        id4 vert;
        vert[0] = allVertices[i][j];
        vert[1] = allVertices[1+i][j];
        vert[2] = allVertices[1+i][1+j];
        vert[3] = allVertices[i][1+j];
        add_quad(M, vert, c, entity.second);
      }
    }

    compute_quad_adjacencies(M.quads, M.quad_neighbors, M.nm_quad_neighbors);

    info("quad mesh: {} vertices, {} quads", M.points.size(), M.quads.size());

    // std::string initialGeometryName = "no_geometry";
    // if (initialGeometryName != "no_geometry") {
    //   info("project points on initial geometry ...");
    //   bool okp = project_points_on_geo_entities(M, initialGeometryName, entityToInitialEntity);
    //   if (!okp) {
    //     error("failed to project point on initial geometry");
    //   }
    // } else {
    //   warn("cannot project on initial geometry, initialGeometryName = {}", initialGeometryName);
    // }
    
    if (projector != NULL) {
      size_t nac = 0;
      size_t nas = 0;
      FC(v,M.points.size(),M.entity[v].first == -1 || M.entity[v].second == -1) {
        int dim = M.entity[v].first;
        int tag = -1;
        double dist;
        bool okc = projector->closestEntity({M.points[v]}, dist, dim, tag);
        if (!okc || dim == -1 || tag == -1) {
          warn("failed to find closest entity for v = {}", v);
        } else {
          M.entity[v] = {dim,tag};
          if (dim == 1) {nac += 1;} else if (dim == 2){nas += 1;}
        }
      }
      if (nac + nas > 0) warn("{} vertices assigned to closest entities ({} to curves and {} to surfaces)", nac+nas, nac, nas);
      bool okp = project_points_via_discrete_projector(M, *projector);
      if (!okp) {
        error("failed to project point on initial geometry");
      }
    }

    return true;
  }

  bool export_qmesh_to_gmsh_mesh(const QMesh& M, const std::string& meshName) {
    info("export mesh {} to gmsh ({} vertices, {} quads)", meshName, M.points.size(), M.quads.size());

    /* New mesh */
    gmsh::model::add(meshName);
    gmsh::model::setCurrent(meshName);

    /* Create vertices */
    vector<bool> used(M.points.size(),false);
    FC(c,M.quads.size(),M.quads[c][0] != NO_ID)  F(lv,4) used[M.quads[c][lv]] = true;
    { /* warning: node tags shifted by 1 */
      std::vector<double> coords;
      std::vector<size_t> nodeTags;
      FC(v,M.points.size(),used[v]) {
        nodeTags.push_back(v+1);
        F(d,3) coords.push_back(M.points[v][d]);
      }
      int gtag = gmsh::model::addDiscreteEntity(2);
      gmsh::model::mesh::addNodes(2, gtag, nodeTags, coords);
    }

    /* Create quads */
    map<id,vector<id4>> color_quads;
    FC(c,M.quads.size(),M.quads[c][0] != NO_ID) {
      color_quads[M.color[c]].push_back(M.quads[c]);
    }
    size_t nq = 1;
    for (const auto& kv: color_quads) {
      std::vector<size_t> elementTags;
      std::vector<size_t> eltNodeTags;
      const vector<id4>& quads = kv.second;
      F(c,quads.size()) {
        F(lv,4) {
          eltNodeTags.push_back(1+quads[c][lv]);
        }
        elementTags.push_back(nq);
        nq += 1;
      }
      id stag = gmsh::model::addDiscreteEntity(2);
      const int QUAD_ID = 3;
      gmsh::model::mesh::addElements(2, stag, {QUAD_ID}, {elementTags}, {eltNodeTags});
    }

    return true;
  }

  bool simplify_quad_mesh(QMesh& M, double size_collapse, int nb_collapse_max,
      const BoundaryProjector* projector) {
    info("quad mesh simplification (size_collapse = {}) ...", size_collapse);

    constexpr bool SHOW_DETAILS = false; /* Show low of intermediate stuff in views, only for debugging */

    vector<int> valence(M.points.size(),0);
    { /* Init valence */
      valence.resize(M.points.size());
      std::fill(valence.begin(),valence.end(),0.);
      F(q,M.quads.size()) FC(lv,4,M.quads[q][lv] != NO_ID) valence[M.quads[q][lv]] = valence[M.quads[q][lv]] + 1;
    }

    { /* Input statistics */
      size_t nbv = 0;
      size_t nbirr = 0;
      size_t nbq = 0;
      vector<bool> inside(M.points.size(),false);
      FC(c,M.quads.size(),M.quads[c][0] != NO_ID) {
        nbq += 1;
        F(lv,4) inside[M.quads[c][lv]] = true;
      }
      FC(v,M.points.size(), inside[v]) nbv += 1;
      FC(v,M.points.size(), inside[v] && M.entity[v].first == 2 && valence[v] != 4)  nbirr += 1;
      info("input: {} vertices ({} irregular), {} quads", nbv, nbirr, nbq);
    }

    /* Precompute a list of chord collapse candidates */
    vector<pair<double,Chord>> chord_to_collapse;
    {
      vector<Chord> chords;
      bool okc = build_chords(M.quads, M.quad_neighbors, chords);
      if (!okc) {
        error("failed to build chord basis");
        return false;
      }
      vector<pair<double,Chord>> candidates;
      F(i, chords.size()) {
        if (!chord_is_collapsible(M, chords[i])) continue;
        double wmin, wavg, wmax;
        bool oks = chord_width_statistics(M, chords[i], wmin, wavg, wmax);
        if (!oks) {
          warn("failed to evaluate chord width (problem with sizemap ?)");
          continue;
        }
        if (wmin > size_collapse) continue; /* filter on minimum width */
        chord_to_collapse.push_back({wavg,chords[i]}); /* sort by average width */
      }
      std::sort(chord_to_collapse.begin(), chord_to_collapse.end(),
          [](const pair<double,Chord>& a, const pair<double,Chord>& b) {
          return a.first < b.first; });
      info("precomputation: {} chord collapse candidates", chord_to_collapse.size());
    }

    /* Simplification loop */
    info("simplification loop in progress ...");
    id iter = 0;
    int nbc = 0;
    size_t nbmax = chord_to_collapse.size();
    vector<Chord> collapsed_chords;
    while (chord_to_collapse.size() > 0) {
      iter += 1;
      if (nb_collapse_max >= 0 && nbc >= nb_collapse_max) {
        info("reached maximum number of collapse: {}", nb_collapse_max);
        break;
      }
      if (nbmax / 10 > 0 && iter % (nbmax / 10) == 0) info("  {} / {} (collapse max)", iter, nbmax);

      { /* Update valence and onBoundary */
        valence.resize(M.points.size());
        std::fill(valence.begin(),valence.end(),0.);
        F(q,M.quads.size()) {
          if (M.quads[q][0] == NO_ID) continue;
          FC(lv,4,M.quads[q][lv] != NO_ID) valence[M.quads[q][lv]] = valence[M.quads[q][lv]] + 1;
          FC(le,4,M.quad_neighbors[q][le] == NO_SID) {
            // !!!! TODO: how to replace these ones ? !!!!!!
            // M.onBoundary[M.quads[q][le]] = true;
            // M.onBoundary[M.quads[q][(le+1)%4]] = true;
          }
        }
      }

      Chord chord = chord_to_collapse[0].second;
      chord_to_collapse.erase(chord_to_collapse.begin());

      if (!chord_is_collapsible(M, chord, &valence)) {
        warn("  chord not collapsible, continue");
        if (SHOW_DETAILS) show_chord_in_view(M, {chord}, "_i" + std::to_string(iter)+"_ch_rej_nc");
        continue;;
      }

      /* Check chord width criteria */
      double wmin, wavg, wmax;
      bool oks = chord_width_statistics(M, chord, wmin, wavg, wmax);
      if (!oks) {
        warn("  failed to evaluate chord width (sizemap issue ?)");
        if (SHOW_DETAILS) show_chord_in_view(M, {chord}, "_i" + std::to_string(iter)+"_ch_rej_eval");
        continue;
      }
      if (wavg > size_collapse) continue; /* filter on average width */

      if (SHOW_DETAILS) show_chord_in_view(M, {chord}, "_i" + std::to_string(iter)+"_chord");

      bool okc = apply_chord_collapse(M, chord);
      if (!okc) {
        error("iter {}, failed to collapse (should not happen) !", iter);
        return false;
      }
      if (SHOW_DETAILS) show_qmesh_in_view(M, "_i" + std::to_string(iter)+"_M");

      nbc += 1;
    }
    info("simplification done, collapsed {} chords", nbc);

    { /* Output statistics */
      size_t nbv = 0;
      size_t nbirr = 0;
      size_t nbq = 0;
      vector<bool> inside(M.points.size(),false);
      FC(c,M.quads.size(),M.quads[c][0] != NO_ID) {
        nbq += 1;
        F(lv,4) inside[M.quads[c][lv]] = true;
      }
      FC(v,M.points.size(), inside[v]) nbv += 1;
      FC(v,M.points.size(), inside[v] && M.entity[v].first == 2 && valence[v] != 4) nbirr += 1;
      info("output: {} vertices ({} irregular), {} quads", nbv, nbirr, nbq);
    }

    if (projector != NULL) {
      size_t nc = 0;
      double dmax = 0.;
      FC(v,M.points.size(),M.entity[v].first == -1 || M.entity[v].second == -1) {
        if (M.entity[v].first == -1) {
          error("cannot deal with vertex v={}, M.entity[v] = {}", M.entity[v]);
          return false;
        }
        int dim = M.entity[v].first;
        int tag = -1;
        double dist;
        bool okc = projector->closestEntity({M.points[v]}, dist, dim, tag);
        if (okc) {
          // warn("  v = {}, pt = {}, M.entity[v] = {} -> {}", v, M.points[v], M.entity[v], std::make_pair(dim,tag));
          M.entity[v] = {dim,tag};
          nc += 1;
          dmax = std::max(dmax,dist);
        } else {
          warn("v = {}, mapping from entity ({},{}) to initial one not found", v, M.entity[v].first, M.entity[v].second);
          continue;
        }
      }
      if (nc > 0) {
        warn("{} vertices got closest entity assigned (dist max = {})", nc, dmax);
      }


      bool okp = project_points_via_discrete_projector(M, *projector);
      if (!okp) {
        error("failed to project point on initial geometry");
      }
    }

    return true;
  }

}

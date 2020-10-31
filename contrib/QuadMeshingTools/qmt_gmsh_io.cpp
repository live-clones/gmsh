// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "quad_meshing_tools.h"
#include "qmt_types.hpp"
#include "qmt_utils.hpp"

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

namespace QMT_IO_Utils {
  using namespace QMT;
  using namespace QMT_Utils;
  /************************************/
  /* Formatting and Logging functions */
  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Gmsh IO | " + stream.str(), "error");
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Gmsh IO | " + stream.str(), "warning");
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      gmsh::logger::write("QMT | Gmsh IO | " + stream.str(), "info");
    }
  /************************************/
}

namespace QMT {
  using namespace QMT_IO_Utils;

  /* Global variable */
  bool gmsh_api_initialized = false;

  void initialize_gmsh_api_if_necessary() {
    if (!gmsh_api_initialized) {
      gmsh::initialize(0, 0, false);
      gmsh_api_initialized = true;
    }
  }

  bool compute_triangle_adjacencies(
      const vector<id3>& triangles,
      vector<sid3>& triangle_neighbors,
      vector<vector<id>>& nm_triangle_neighbors,
      vector<id2>& uIEdges,
      vector<id>& old2IEdge,
      vector<vector<id>>& uIEdgeToOld
      ) {
    triangle_neighbors.clear();
    triangle_neighbors.resize(triangles.size(),{NO_ID,NO_ID,NO_ID});
    nm_triangle_neighbors.clear();

    constexpr size_t NBF = 3;

    /* Store element 'faces', with duplicates for further 'equality test' */
    std::vector<id2> faces;
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id2 face = {triangles[i][lf],triangles[i][(lf+1)%NBF]};
        std::sort(face.begin(),face.end());
        faces.push_back(face);
      }
    }

    /* Reduce 'duplicated faces' to 'unique faces', keeping the 'old2new' mapping */
    size_t nbUniques = sort_unique_with_perm(faces, uIEdges, old2IEdge);

    /* Build the 'unique face to elements' mapping */
    uIEdgeToOld.resize(nbUniques);
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (size_t lf = 0; lf < NBF; ++lf) {
        id facePos = NBF*i+lf;
        uIEdgeToOld[old2IEdge[facePos]].push_back(facePos);
      }
    }

    /* Loop over 'unique face to elements' and set the element adjacencies */
    constexpr id2 NO_FACE = {NO_ID,NO_ID};
    for (size_t i = 0; i < nbUniques; ++i) {
      if (uIEdges[i] == NO_FACE) continue;
      if(uIEdges[i][0] == NO_ID) return false;
      if(uIEdges[i][1] == NO_ID) return false;
      if (uIEdgeToOld[i].size() == 1) { /* boundary */
        id eltId = uIEdgeToOld[i][0] / NBF;
        id lf = uIEdgeToOld[i][0] % NBF;
        triangle_neighbors[eltId][lf] = NO_ID;
      } else if (uIEdgeToOld[i].size() == 2) { /* regular face */
        id e1 = uIEdgeToOld[i][0] / NBF;
        id lf1 = uIEdgeToOld[i][0] % NBF;
        id e2 = uIEdgeToOld[i][1] / NBF;
        id lf2 = uIEdgeToOld[i][1] % NBF;
        triangle_neighbors[e1][lf1] = NBF*e2+lf2;
        triangle_neighbors[e2][lf2] = NBF*e1+lf1;
      } else if (uIEdgeToOld[i].size() > 2) { /* non manifold face */
        for (size_t j = 0; j < uIEdgeToOld[i].size(); ++j) {
          id e = uIEdgeToOld[i][j] / NBF;
          id lf = uIEdgeToOld[i][j] % NBF;
          std::vector<id> neighs;
          for (size_t k = 0; k < uIEdgeToOld[i].size(); ++k) {
            if (uIEdgeToOld[i][k] != uIEdgeToOld[i][j]) {
              neighs.push_back(uIEdgeToOld[i][k]);
            }
          }
          neighs.shrink_to_fit();
          id pos = nm_triangle_neighbors.size();
          nm_triangle_neighbors.push_back(neighs);
          triangle_neighbors[e][lf] = -((sid) pos + 1);
        }
      }
    }

    /* Reduce memory consumption */
    triangle_neighbors.shrink_to_fit();
    nm_triangle_neighbors.shrink_to_fit();

    return true;
  }


  bool import_TMesh_from_gmsh(const std::string& meshName, TMesh& M, bool compute_adjacencies, bool add_missing_non_manifold_lines) {
    initialize_gmsh_api_if_necessary();

    if (!meshName.empty() && meshName != "current") {
      gmsh::model::setCurrent(meshName);
    }
    
    { /* vertices */
      std::vector<std::size_t> nodeTags;
      std::vector<double> coord;
      std::vector<double> parametricCoords;
      gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoords);
      M.points.resize(nodeTags.size());
      M.pt_color.resize(nodeTags.size(),0);
      F(i,nodeTags.size()) {
        id v = nodeTags[i];
        if (v >= M.points.size()) {
          M.points.resize(v+1);
          M.pt_color.resize(v+1,0);
        }
        M.points[v] = {coord[3*i+0],coord[3*i+1],coord[3*i+2]};
      }
    }

    { /* nodes */
      vectorpair nodes;
      gmsh::model::getEntities(nodes, 0);
      F(k,nodes.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,nodes[k].first,nodes[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 15) { /* nodes */
            F(j,elementTags[i].size()) {
              id v = nodeTags[i][j];
              M.pt_color[v] = nodes[k].second;
            }
          }
        }
      }
    }

    { /* lines */
      vectorpair curves;
      gmsh::model::getEntities(curves, 1);
      F(k,curves.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,curves[k].first,curves[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 1) { /* lines */
            F(j,elementTags[i].size()) {
              M.lines.push_back({id(nodeTags[i][2*j+0]),id(nodeTags[i][2*j+1])});
              M.line_colors.push_back(id(curves[k].second));
              M.line_elt_tags.push_back(id(elementTags[i][j]));
            }
          }
        }
      }
    }

    { /* triangles */
      vectorpair surfs;
      gmsh::model::getEntities(surfs, 2);
      F(k,surfs.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,surfs[k].first,surfs[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 2) { /* triangles */
            F(j,elementTags[i].size()) {
              M.triangles.push_back({id(nodeTags[i][3*j+0]),id(nodeTags[i][3*j+1]),id(nodeTags[i][3*j+2])});
              M.tri_colors.push_back(id(surfs[k].second));
              M.tri_elt_tags.push_back(id(elementTags[i][j]));
            }
          }
        }
      }
    }

    if (compute_adjacencies) {
      vector<id2> uIEdges;
      vector<id> old2IEdge;
      vector<vector<id>> uIEdgeToOld;
      bool oka = compute_triangle_adjacencies(M.triangles, M.triangle_neighbors, M.nm_triangle_neighbors, uIEdges, old2IEdge, uIEdgeToOld);
      if (!oka) {
        error("failed to compute mesh adjacencies");
        return false;
      }
      if (add_missing_non_manifold_lines) {
        size_t na = 0;
        std::unordered_map<id2,id,id2Hash> sedgeToLine;
        F(l,M.lines.size()) {
          id2 sedge = sorted(M.lines[l][0],M.lines[l][1]);
          sedgeToLine[sedge] = l;
        }
        FC(e,uIEdgeToOld.size(),uIEdgeToOld[e].size() != 2) {
          id2 edge = uIEdges[e];
          id2 sedge = sorted(edge[0],edge[1]);
          auto it = sedgeToLine.find(sedge);
          if (it == sedgeToLine.end()) {
            sedgeToLine[sedge] = M.lines.size();
            M.lines.push_back(sedge);
            M.line_elt_tags.push_back(NO_ID);
            M.line_colors.push_back(NO_ID);
            na += 1;
          }
        }
        if (na != 0) {
          warn("added {} lines from non-manifold edges not found in curves (repair)", na);
        }
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


  bool import_QMesh_from_gmsh(const std::string& meshName, QMesh& M, bool compute_adjacencies) {
    initialize_gmsh_api_if_necessary();
    if (!meshName.empty() && meshName != "current") {
      gmsh::model::setCurrent(meshName);
    }
    
    { /* vertices */
      std::vector<std::size_t> nodeTags;
      std::vector<double> coord;
      std::vector<double> parametricCoords;
      gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoords);
      M.points.resize(nodeTags.size());
      M.size.resize(nodeTags.size(),DBL_MAX);
      M.entity.resize(nodeTags.size(),{-1,-1});
      F(i,nodeTags.size()) {
        id v = nodeTags[i];
        if (v >= M.points.size()) {
          M.points.resize(v+1);
          M.size.resize(v+1,DBL_MAX);
          M.entity.resize(v+1,{-1,-1});
        }
        M.points[v] = {coord[3*i+0],coord[3*i+1],coord[3*i+2]};
      }
    }

    { /* nodes */
      vectorpair nodes;
      gmsh::model::getEntities(nodes, 0);
      F(k,nodes.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,nodes[k].first,nodes[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 0) { /* nodes */
            F(j,elementTags[i].size()) {
              id v = nodeTags[i][j];
              M.entity[v] = nodes[k];
            }
          }
        }
      }
    }

    { /* lines */
      vectorpair curves;
      gmsh::model::getEntities(curves, 1);
      F(k,curves.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,curves[k].first,curves[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 1) { /* lines */
            F(j,elementTags[i].size()) {
              M.lines.push_back({id(nodeTags[i][2*j+0]),id(nodeTags[i][2*j+1])});
              M.line_colors.push_back(id(curves[k].second));
              M.line_elt_tags.push_back(id(elementTags[i][j]));
            }
          }
        }
      }
    }

    { /* quads */
      vectorpair surfs;
      gmsh::model::getEntities(surfs, 2);
      F(k,surfs.size()) {
        std::vector<int> elementTypes;
        std::vector<std::vector<size_t>> elementTags;
        std::vector<std::vector<size_t>> nodeTags;
        gmsh::model::mesh::getElements(elementTypes,elementTags,nodeTags,surfs[k].first,surfs[k].second);
        F(i,elementTypes.size()) {
          if (elementTypes[i] == 3) { /* quads */
            F(j,elementTags[i].size()) {
              M.quads.push_back(
                  {id(nodeTags[i][4*j+0]),id(nodeTags[i][4*j+1]),
                  id(nodeTags[i][4*j+2]), id(nodeTags[i][4*j+3])});
              M.quadEntity.push_back(surfs[k].second);
              M.color.push_back(surfs[k].second);
            }
          }
        }
      }
    }

    if (compute_adjacencies) {
      bool okn = compute_quad_adjacencies(M.quads, M.quad_neighbors, M.nm_quad_neighbors);
      if (!okn) {
        error("failed to compute quad patch adjacencies");
        return false;
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

  bool convert_quad_mesh_to_tri_mesh(const QMesh& Q, TMesh& T) {
    T.points = Q.points;
    T.size = Q.size;
    T.pt_color.resize(Q.points.size(),0);
    FC(i,Q.entity.size(),Q.entity[i].first == 0) T.pt_color[i] = Q.entity[i].second;

    T.lines = Q.lines;
    T.line_colors = Q.line_colors;
    T.line_elt_tags = Q.line_elt_tags;

    T.triangles.resize(2*Q.quads.size());
    T.tri_colors.resize(2*Q.quads.size(),0);
    T.tri_elt_tags.resize(2*Q.quads.size(),NO_ID);
    T.triangle_neighbors.clear();
    T.nm_triangle_neighbors.clear();
    F(i,Q.quads.size()) {
      T.triangles[2*i+0] = {Q.quads[i][0],Q.quads[i][1],Q.quads[i][2]};
      T.triangles[2*i+1] = {Q.quads[i][0],Q.quads[i][2],Q.quads[i][3]};
      T.tri_colors[2*i+0] = Q.quadEntity[i];
      T.tri_colors[2*i+1] = Q.quadEntity[i];
      T.tri_elt_tags[2*i+0] = NO_ID;
      T.tri_elt_tags[2*i+1] = NO_ID;
    }

    return true;
  }

}

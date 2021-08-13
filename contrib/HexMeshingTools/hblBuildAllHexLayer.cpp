// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblBuildAllHexLayer.h"

#include <unordered_map>
#include <queue>

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "arrayGeometry.h"
#include "geolog.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"
#include "hblTypes.hpp"
#include "hblUtils.h"
#include "hblBrepMesh.h"
#include "hblDiskTriangulation.h"
#include "hblOptimizeGeometry.h"

#include "gmsh.h"
#include "GEntity.h"
#include "OS.h"

/* - Useful macros */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


using std::vector;
using std::map;
using std::unordered_map;
using std::array;
using std::pair;


namespace hbl {
  constexpr id EDGE_FIXED = 0;
  const double EPS0 = 1.e-15;

  using namespace CppUtils;

  void debug_check_bottom_up_relations(const BrepMesh& H) {
    if (H.edges.size() > 0) {
      FC(v,H.vertices.size(),H.vertToEdges[v].size() == 0) {
        DBG(v,H.vertices.size(),H.vertToEdges[v].size());
        abort();
      }
    }
    if (H.faces.size() > 0) {
      FC(e,H.edges.size(),H.edgeToFaces[e].size() == 0) {
        DBG(e,H.edges.size(),H.edgeToFaces[e].size());
        abort();
      }
    }
    if (H.cells.size() > 0) {
      FC(f,H.faces.size(),H.faceToCells[f].size() == 0) {
        DBG(f,H.faces.size(),H.faceToCells[f].size());
        abort();
      }
    }
  }

  bool get_valences_and_open_edges(
      const BrepMesh& H,
      const vector<id>& vertices,
      const vector<id>& edges,
      const vector<id>& faces,
      unordered_map<id,id>& edge_val,
      unordered_map<id,id>& vert_val,
      vector<id>& open_edges,
      vector<id>& oVert
      ) {
    edge_val.clear();
    vert_val.clear();
    open_edges.clear();
    oVert.clear();
    vector<id> _vert(4);
    F(j,faces.size()) {
      id q = faces[j];
      F(le,H.faces[q].edges.size()) {
        id e = H.faces[q].edges[le];
        edge_val[e] += 1;
      }
      face_vertices(H, q, _vert);
      F(lv,_vert.size()) vert_val[_vert[lv]] += 1;
    }
    for (const auto& kv: edge_val) {
      if (kv.second == 1) open_edges.push_back(kv.first);
    }
    vector<id2> edge_pairs;
    F(i,open_edges.size()) edge_pairs.push_back(H.edges[open_edges[i]].vertices);
    bool oko = getOrderedVerticesFromEdges(edge_pairs, oVert);
    RFC(!oko, "get_valences_and_open_edges | failed to ordered vertices from edge pairs = {}", edge_pairs);

    return true;
  }

  bool get_7v9e3f_config(
      const BrepMesh& H,
      unordered_map<id,id>& edge_val,
      unordered_map<id,id>& vert_val,
      const vector<id>& open_edges,
      const vector<id>& oVert,
      vector<id>& oVertS,
      vector<id>& oEdgesS
      ) {
    id lvStart = NO_ID;
    FC(lv,oVert.size(),vert_val[oVert[lv]] == 2 && vert_val[oVert[(lv+1)%oVert.size()]] == 1) {
      lvStart = lv; break;
    }
    RFC(lvStart == NO_ID, "get_7v9e3f_config | no valence [2 1] on loop ? should not happen");
    oVertS.resize(oVert.size());
    vector<id> oValS(oVert.size());
    F(lv,oVert.size()) {
      oVertS[lv] = oVert[(lvStart+lv)%oVert.size()];
      oValS[lv] = vert_val[oVertS[lv]];
    }
    vector<id> val_expected = {2,1,2,1,2,1};
    if (oValS != val_expected) {
      error("get_7v9e3f_config | wrong valence sequence, got {} instead of {}", oValS, val_expected);
      return false;
    }

    vector<id2> edge_pairs;
    F(i,open_edges.size()) edge_pairs.push_back(
        sorted(H.edges[open_edges[i]].vertices[0], H.edges[open_edges[i]].vertices[1]));

    oEdgesS.resize(open_edges.size(),NO_ID);
    F(le,oEdgesS.size()) {
      id2 query = sorted(oVertS[le],oVertS[(le+1)%oVertS.size()]);
      FC(k,edge_pairs.size(),query==edge_pairs[k]) {
        oEdgesS[le] = open_edges[k];
        break;
      }
      RFC(oEdgesS[le] == NO_ID, "get_7v9e3f_config | edge not found ? {} in {}", query, edge_pairs);
    }

    return true;
  }

  bool build_hex_from_7v9e3f(
      BrepMesh& H,
      const vector<id>& vertices,
      const vector<id>& edges,
      const vector<id>& faces,
      HexToBoundaryMeshMatching& h2q) {
    if (vertices.size() != 7 || edges.size() != 9 || faces.size() != 3) {
      error("build_hex_from_7v9e3f | wrong input");
      return false;
    }

    const bool updateMappings = true;

    vector<id> oVertS;
    vector<id> oEdgesS;
    {
      vector<id> oVert;
      unordered_map<id,id> edge_val;
      unordered_map<id,id> vert_val;
      vector<id> open_edges;
      bool okgv = get_valences_and_open_edges(H, vertices, edges, faces, edge_val, vert_val, open_edges, oVert);
      RFC(!okgv, "build_hex_from_7v9e3f | failed to get valences and open edges");
      bool okc = get_7v9e3f_config(H, edge_val, vert_val, open_edges, oVert, oVertS, oEdgesS);
      RFC(!okc, "build_hex_from_7v9e3f | failed to get config");
    }

    /* Opposite vertex */
    id nv = NO_ID;
    {
      vec3 p = 1./3. * (
          opposite_right_angled_corner(H.vertices[oVertS[1]].pt, H.vertices[oVertS[0]].pt, H.vertices[oVertS[5]].pt)
          + opposite_right_angled_corner(H.vertices[oVertS[1]].pt, H.vertices[oVertS[2]].pt, H.vertices[oVertS[3]].pt)
          + opposite_right_angled_corner(H.vertices[oVertS[3]].pt, H.vertices[oVertS[4]].pt, H.vertices[oVertS[5]].pt));
      nv = add_vertex(H, p, nullptr, nullptr, updateMappings);
      h2q.vertexParent.push_back(NO_PARENT);
    }

    /* Three edges */
    id ne0 = add_edge(H, {oVertS[1],nv}, nullptr, nullptr, updateMappings);
    h2q.edgeParent.push_back(NO_PARENT);
    id ne1 = add_edge(H, {oVertS[3],nv}, nullptr, nullptr, updateMappings);
    h2q.edgeParent.push_back(NO_PARENT);
    id ne2 = add_edge(H, {oVertS[5],nv}, nullptr, nullptr, updateMappings);
    h2q.edgeParent.push_back(NO_PARENT);

    /* Three faces */
    id nf1 = add_face(H, {oEdgesS[0],ne0,ne2,oEdgesS[5]}, nullptr, nullptr, updateMappings);
    h2q.faceParent.push_back(NO_PARENT);
    id nf2 = add_face(H, {oEdgesS[1],ne0,ne1,oEdgesS[2]}, nullptr, nullptr, updateMappings);
    h2q.faceParent.push_back(NO_PARENT);
    id nf3 = add_face(H, {oEdgesS[3],ne1,ne2,oEdgesS[4]}, nullptr, nullptr, updateMappings);
    h2q.faceParent.push_back(NO_PARENT);

    vector<id> hfaces = faces;
    append(hfaces,{nf1,nf2,nf3});
    add_cell(H, hfaces, nullptr, nullptr, updateMappings);

    return true;
  }


  struct DualToPrimalMatching {
    vector<id> dv2e;
    vector<id> de2f;
    vector<id> dt2c;
  };

  bool initializeDualPrimalMatchingOnBoundary(
      const BrepMesh& Q,
      const std::vector<int>& hexValence,
      id v,
      const DTriangulation& diskTrgl,
      DualToPrimalMatching& m) {
    m.dv2e.clear();
    m.dv2e.resize(diskTrgl.nv,NO_ID);
    m.de2f.clear();
    m.de2f.resize(diskTrgl.edges.size(),NO_ID);
    m.dt2c.clear();
    m.dt2c.resize(diskTrgl.triangles.size(),NO_ID);

    /* Extract the boundary polygon (edges of the primal boundary mesh,
     * dual vertices of the disk triangulation) */
    vector<id> dualPolygon;
    bool okbl = extract_dual_polygon(Q, v, dualPolygon);
    RFC(!okbl, "failed to extract dual polygon at boundary vertex {}", v);

    /* Find the rotation between the polygon and the disk triangulation */
    vector<id> bdrVal(dualPolygon.size());
    F(j,dualPolygon.size()) bdrVal[j] = (id) hexValence[dualPolygon[j]];

    vector<id> canonicalBdrLoop(bdrVal.size());
    vector<id> canonicalBdrVal(bdrVal.size());
    get_smallest_rotation(bdrVal, dualPolygon, canonicalBdrVal, canonicalBdrLoop);

    /* Disk triangulation boundary vertices -> primal edges */
    F(j,diskTrgl.nb) {
      m.dv2e[j] = canonicalBdrLoop[j];
    }
    /* Disk triangulation boundary edges -> primal faces */
    FC(j,diskTrgl.edges.size(),diskTrgl.eOnBdr[j]) {
      id dv1 = diskTrgl.edges[j][0];
      id dv2 = diskTrgl.edges[j][1];
      id pe1 = m.dv2e[dv1];
      id pe2 = m.dv2e[dv2];
      RFC(pe1 == NO_ID || pe2 == NO_ID, "no primal edge associated to dual vertex");
      id pf = NO_ID;
      for (id pfc: Q.edgeToFaces[pe1]) if (inVector(pe2,Q.faces[pfc].edges)) {
        pf = pfc;
        break;
      }
      RFC(pf == NO_ID, "no primal face found for dual edge");
      m.de2f[j] = pf;
    }

    return true;
  }

  bool buildBoundaryHexahedralConfiguration(
      const BrepMesh& Q,
      const std::vector<int>& hexValence,
      id v,
      const DTriangulation& diskTrgl,
      const HblOptions& opt,
      const vector<vec3>& qNormals,
      /* Hex config is added to H */
      BrepMesh& H,
      HexToBoundaryMeshMatching& h2q) {
    DualToPrimalMatching m;
    bool okm = initializeDualPrimalMatchingOnBoundary(Q, hexValence, v, diskTrgl, m);
    RFC(!okm, "failed to initialize dual-primal matching at vertex {}", v);

    /* Local edge length */
    double elen = localEdgeLengthAroundVertex(Q, v);

    const bool updateMappings = true;

    id nvo = NO_ID;
    { /* Add boundary vertex */
      const Vertex& ov = Q.vertices[v];
      nvo = add_vertex(H, ov.pt, ov.entity, ov.origin, updateMappings);
      h2q.vertexParent.push_back(std::make_pair(0,v));
    }
    vec3 po = H.vertices[nvo].pt;

    vector<id> dv2e;
    vector<id> de2f;
    vector<id> dt2c;
    /* From dual vertices, create primal edges and their
       associated opposite vertices */
    F(dv,diskTrgl.nv) {
      if (diskTrgl.vOnBdr[dv]) {
        id e = m.dv2e[dv]; /* Edge the primal boundary mesh */
        RFC(e == NO_ID, "wrong matching");
        vec3 p = edge_center(Q,e);

        if (Msg::GetVerbosity() == 101) { // TODOMX
          double fig = 0.75;
          p = fig * p + (1.-fig) * po;
        }

        id nv = add_vertex(H, p, Q.edges[e].entity, nullptr, updateMappings);
        h2q.vertexParent.push_back(std::make_pair(1,e));

        id ne = add_edge(H, {nvo,nv}, Q.edges[e].entity, nullptr, updateMappings);
        h2q.edgeParent.push_back(std::make_pair(1,e));

        dv2e.push_back(ne);
      } else {
        vec3 dir = qNormals[v];
        if (length(dir) > EPS0) {
          normalize(dir);
        }
        vec3 p = Q.vertices[v].pt + 0.5 * opt.extrusion_factor * elen * dir;
        if (Msg::GetVerbosity() == 101) { // TODOMX
          p = Q.vertices[v].pt + 0.25 * opt.extrusion_factor * elen * dir;
        }

        id nv = add_vertex(H, p, nullptr, nullptr, updateMappings);
        h2q.vertexParent.push_back(NO_PARENT);

        id ne = add_edge(H, {nvo,nv}, nullptr, nullptr, updateMappings);
        h2q.edgeParent.push_back(NO_PARENT);

        dv2e.push_back(ne);
      }
    }


    /* For dual edges, create primal quads (touching the boundary vertex v) */
    F(de,diskTrgl.edges.size()) {
      id dv1 = diskTrgl.edges[de][0];
      id dv2 = diskTrgl.edges[de][1];
      id e1 = dv2e[dv1];
      id e2 = dv2e[dv2];
      id v1 = H.edges[e1].vertices[1];
      id v2 = H.edges[e2].vertices[1];
      vec3 p1 = H.vertices[v1].pt;
      vec3 p2 = H.vertices[v2].pt;
      vec3 p3 = opposite_right_angled_corner(p1,po,p2);
      bool should_invert_quad = false;
      pair<int,int> parent = NO_PARENT;
      GEntity* entity = nullptr;
      if (diskTrgl.eOnBdr[de]) { /* New quad is a subdivision of bdr face */
        id f = m.de2f[de];
        RFC(f == NO_ID, "wrong matching de->f");
        parent = {2,f};
        entity = Q.faces[f].entity;
        p3 = face_center(Q,f);
        if (Msg::GetVerbosity() == 101) { // TODOMX
          double fig = 0.75;
          p3 = fig*p3+(1.-fig)*po;
        }

        /* should_invert_quad is used to keep orientation consistent with Q
         * that is, boundary quads are oriented to normals point to the interior */
        /* Edge e1 was edge oe in polygon f */
        id oe = h2q.edgeParent[e1].second;
        bool found = false;
        bool invert = (Q.edges[oe].vertices[1] == v);
        FC(j,Q.faces[f].edges.size(),Q.faces[f].edges[j] == oe) {
          found = true;
          if (Q.faces[f].edge_orient_invert[j]) {
            invert = !invert;
          }
        }
        if (found && invert) {
          should_invert_quad = true;
        } else if (!found) {
          error("original edge {} not found in original quad {}", oe, f);
        }
      }

      id nv = add_vertex(H,p3,entity,nullptr,updateMappings);
      h2q.vertexParent.push_back(parent);

      id e3 = add_edge(H,{v1,nv},entity,nullptr,updateMappings);
      h2q.edgeParent.push_back(parent);

      id e4 = add_edge(H,{v2,nv},entity,nullptr,updateMappings);
      h2q.edgeParent.push_back(parent);

      id nf = add_face(H,{e1,e2,e3,e4},entity,nullptr,updateMappings);
      h2q.faceParent.push_back(parent);

      de2f.push_back(nf);
      if (should_invert_quad) {
        invert_face(H,nf);
      }
    }

    vector<id> hexes;
    F(dt,diskTrgl.triangles.size()) { /* Create hexes and associated interior components */
      vector<id> tri = { diskTrgl.triangles[dt][0], diskTrgl.triangles[dt][1], diskTrgl.triangles[dt][2] };
      vector<id> des;
      FC(de,diskTrgl.edges.size(), inVector(diskTrgl.edges[de][0],tri)
          && inVector(diskTrgl.edges[de][1],tri)) {
        des.push_back(de);
      }
      RFC(des.size() != 3, "wrong size triangle edges");

      /* Primal hex components */
      vector<id> vs;
      vector<id> es;
      vector<id> quads(des.size());
      F(j,quads.size()) quads[j] = de2f[des[j]];
      F(j,quads.size()) {
        append(vs,face_vertices(H,quads[j]));
        append(es,H.faces[quads[j]].edges);
      }
      sort_unique(vs);
      sort_unique(es);

      id nc = H.cells.size();
      bool okh = build_hex_from_7v9e3f(H,vs,es,quads,h2q);
      RFC(!okh, "failed to build hex");
      dt2c.push_back(nc);
    }



    return true;
  }

  bool compute_vertex_matchings(
      const BrepMesh& Q, 
      const BrepMesh& H,
      const HexToBoundaryMeshMatching& h2q,
      vector<id2>& vertex_equalities) {
    vertex_equalities.clear();

    /* Boundary vertex to hex vertex */
    std::vector<id> qv2hv(Q.vertices.size(),NO_ID);
    FC(v,H.vertices.size(),h2q.vertexParent[v].first == 0) {
      qv2hv[h2q.vertexParent[v].second] = v;
    }

    /* On each boundary edge of Q, 
     * - get the hexes in H adjacent to the edge at both extremities,
     * - get the associated interior quad face fans
     * - get the associated vertex chains
     * - set equality constraints on corresponding vertices */
    vector<id> _fvert(4);
    F(e,Q.edges.size()) {
      id2 hvs = {qv2hv[Q.edges[e].vertices[0]],qv2hv[Q.edges[e].vertices[1]]};
      id2 hvAtEdgeMid = {NO_ID,NO_ID};
      vector<vector<id> > hexes(2);
      F(lv,2) {
        RFC(hvs[lv] == NO_ID, "wrong h2q qv2hv");
        id hv = hvs[lv];
        for (id he: H.vertToEdges[hv])  {
          if (h2q.edgeParent[he].first == 1 && h2q.edgeParent[he].second == e) {
            hvAtEdgeMid[lv] = edge_opposite_vertex(H.edges[he].vertices,hv);
            for (id hf: H.edgeToFaces[he]) for (id hc: H.faceToCells[hf]) {
              hexes[lv].push_back(hc);
            }
          }
        }
        sort_unique(hexes[lv]);
      }
      RFC(hexes[0].size() != hexes[1].size(), "not the same # of hexes on both sides");

      vector<vector<id> > fans(2);
      F(k,2) for (id hc: hexes[k]) for (id hf: H.cells[hc].faces) {
        face_vertices(H, hf, _fvert);
        if (inVector(hvs[k],_fvert)) continue;
        if (inVector(hvAtEdgeMid[k],_fvert)) {
          fans[k].push_back(hf);
        }
      }
      RFC(fans[0].size() != fans[1].size(), "not the same # of quads on both sides");

      vector<vector<id> > vertexChains(2);
      F(k,2) {
        vector<id2> vPairs;
        for (id hf: fans[k]) for (id he: H.faces[hf].edges) {
          if (H.edges[he].vertices[0] == hvAtEdgeMid[k] 
              || H.edges[he].vertices[1] == hvAtEdgeMid[k]) continue;
          vPairs.push_back(H.edges[he].vertices);
        }
        vector<id> chain;
        bool ok = getOrderedVerticesFromEdges(vPairs, chain);
        RFC(!ok, "failed to get ordered vertices from vertex pairs");
        vertexChains[k] = chain;
      }
      RFC(vertexChains[0].size() == 0 || vertexChains[0].size() != vertexChains[1].size(), "not the same # of vertices on both sides");

      RFC(h2q.vertexParent[vertexChains[0][0]].first != 2, "vertexParent should be a bdr face");
      if (h2q.vertexParent[vertexChains[0][0]] == h2q.vertexParent[vertexChains[1][0]]) {
        // good
      } else if (h2q.vertexParent[vertexChains[0][0]] == h2q.vertexParent[vertexChains[1].back()]) {
        std::reverse(vertexChains[1].begin(),vertexChains[1].end());
      } else {
        RF("vertex chain do not have a common parent boundary face, bad");
      }

      /* Set the equalities */
      vertex_equalities.push_back(hvAtEdgeMid);
      F(lv,vertexChains[0].size()) {
        vertex_equalities.push_back(sorted(vertexChains[0][lv],vertexChains[1][lv]));
      }

    }

    sort_unique(vertex_equalities);

    return true;
  }

  bool glueBoundaryHexahedralConfigurations(
      const HblOptions& opt,
      const BrepMesh& Q,
      BrepMesh& H,
      HexToBoundaryMeshMatching& h2q) {

    /* Two dual triangles (primal hexes) which are "opposite" on a dual vertex (primal edge) are
     * 'glued' (comes from equality of quad fans on both side of a quad mesh edge) */
    vector<id2> vertex_equalities;
    bool okma = compute_vertex_matchings(Q, H, h2q, vertex_equalities);
    RFC(!okma, "failed to compute vertex matchings");
    info("glue boundary hexahedral configurations: {} vertex equality constraints", 
        vertex_equalities.size());

    if (Msg::GetVerbosity() == 101) {
      F(i,vertex_equalities.size()) {
        vec3 p1 = H.vertices[vertex_equalities[i][0]].pt;
        vec3 p2 = H.vertices[vertex_equalities[i][1]].pt;
        vec3 center = 0.5 * (p1+p2);
        p1 = 0.8*p1+0.2*center;
        p2 = 0.8*p2+0.2*center;
        GeoLog::add({p1,p2},0.,"equalities");
      }
      GeoLog::flush();
    }


    vector<id> v_old2new;
    vector<id> e_old2new;
    vector<id> f_old2new;
    vector<id> c_old2new;
    bool okm = merge_vertices(H, vertex_equalities,v_old2new,e_old2new,f_old2new,c_old2new);
    RFC(!okm, "failed to merge hex vertices");

    bool oku = update_brep_mesh_mappings(H);
    RFC(!oku, "failed to update mesh mappings");

    info("verify hex mesh validity ...");
    bool valid_cells = check_hex_mesh_cells(H, true, true);
    if (!valid_cells) {
      error("invalid cells, bad ...");
      return false;
    }

    { /* After merge, update matching between H and boundary mesh Q */
      HexToBoundaryMeshMatching h2q_updated;
      h2q_updated.vertexParent.resize(H.vertices.size(),NO_PARENT);
      h2q_updated.edgeParent.resize(H.edges.size(),NO_PARENT);
      h2q_updated.faceParent.resize(H.faces.size(),NO_PARENT);
      for (size_t i = 0; i < h2q.vertexParent.size(); ++i) {
        h2q_updated.vertexParent[v_old2new[i]] = h2q.vertexParent[i];
      }
      for (size_t i = 0; i < h2q.edgeParent.size(); ++i) {
        h2q_updated.edgeParent[e_old2new[i]] = h2q.edgeParent[i];
      }
      for (size_t i = 0; i < h2q.faceParent.size(); ++i) {
        h2q_updated.faceParent[f_old2new[i]] = h2q.faceParent[i];
      }
      h2q = h2q_updated;
    }

    return true;
  }

  bool buildAllHexBoundaryLayer(
      const HblInput& input,
      const HblOptions& opt,
      HblOutput& output)
  {
    double t0 = Cpu();
    BrepMesh& H = output.H;

    clear_mesh(output.H);

    /* Build the boundary hexahedral configuration at
     * each boundary vertex */
    info("Build {} boundary hexahedral configurations ...", input.Q.vertices.size());
    for (size_t v = 0; v < input.Q.vertices.size(); ++v) {
      bool okb = buildBoundaryHexahedralConfiguration(
          input.Q, output.hexValence, v, *(output.trgls[v]), opt, input.vertexNormals, output.H, output.h2q);
      RFC(!okb, "failed to build boundary hexahedral config at v={}", v);
    }
    update_brep_mesh_mappings(output.H);


    bool SHOW_STEPS = true;
    if (SHOW_STEPS) {
      // // TODO: need a special optimize without tet meshing etc
      // if (Msg::GetVerbosity() == 101) {
      //   Msg::Warning("OPTIMIZE FOR FIGURE");
      //   bool skipInitialPositionning = true;
      //   bool okgeom = optimizeGeometry(input, opt, output, skipInitialPositionning);
      //   RFC(!okgeom, "failed to optimize geometry");
      // }

      // std::vector<id> cells(H.cells.size());
      // F(i,H.cells.size()) cells[i] = i;
      // visualization_show_cells(H, cells, "hexes_configs");
    }


    /* Glueing hex configs will change the mesh elements in H
     * h2q is also updated */
    info("Glue the {} boundary hexahedral configurations ...", input.Q.vertices.size());
    bool okg = glueBoundaryHexahedralConfigurations(opt, input.Q, output.H, output.h2q);
    RFC(!okg, "failed to glue boundary hex configs");
    update_brep_mesh_mappings(output.H);

    if (SHOW_STEPS) {
      std::vector<id> cells(H.cells.size());
      F(i,H.cells.size()) cells[i] = i;
      visualization_show_cells(H, cells, "hex_layer_raw");
    }

    /* Find geometry of the all-hex layer */

    bool okgeomi = initializeHexLayerGeometry(input, opt, output);
    RFC(!okgeomi, "failed to initialize geometry");

    if (SHOW_STEPS) {
      std::vector<id> cells(H.cells.size());
      F(i,H.cells.size()) cells[i] = i;
      visualization_show_cells(H, cells, "hex_layer_initial");
    }


    bool okgeom = optimizeHexLayerGeometry(input, opt, output);
    if (!okgeom) {
      Msg::Warning("geometry still contains tangled elements after optimization");
    }

    if (opt.viz && opt.debug) {
      std::vector<id> cells(H.cells.size());
      F(i,H.cells.size()) cells[i] = i;
      visualization_show_cells(H, cells, "hex_layer");
    }

    /* Stats */
    output.stats.timeMeshConstruction = Cpu() - t0;
    output.stats.qualityFinalMinMedAvgMaxInv = computeQualityStatsMinMedAvgMaxInv(H);

    return okgeom;
  }

  bool extrudeBoundaryWithFlaggedBoundary(BrepMesh& M, 
      std::vector<id>& newCells,
      const std::vector<vec3>* vNormals,
      const std::vector<bool>& vOnBdr,
      const std::vector<bool>& eOnBdr,
      const std::vector<bool>& fOnBdr)  {

    /* Local length and extrusion directions */
    vector<vec3> normals(M.vertices.size(),{0.,0.,0.});
    vector<double> elens(M.vertices.size(),0.);
    for (id v = 0; v < M.vertices.size(); ++v) if (vOnBdr[v]) {
      if (vNormals != nullptr) {
        normals[v] = (*vNormals)[v];
      } else {
        for (id e: M.vertToEdges[v]) if (!eOnBdr[e]) {
          if (M.edges[e].vertices[0] == v) {
            normals[v] = normals[v] - 1. * (edge_direction(M,e));
          } else {
            normals[v] = normals[v] + 1. * (edge_direction(M,e));
          }
        }
      }
      elens[v] = localEdgeLengthAroundVertex(M,v);
    }

    newCells.reserve(M.faces.size());
    std::vector<id> vbdr2vext(M.vertices.size(),NO_ID);
    std::vector<id> vbdr2eext(M.vertices.size(),NO_ID);
    std::vector<id> ebdr2eext(M.edges.size(),NO_ID);
    std::vector<id> ebdr2fext(M.edges.size(),NO_ID);
    vector<id> fvert;

    /* Loop on each boundary face */
    const bool updateMappings = true;
    const size_t nbFaces = M.faces.size();
    for (size_t f = 0; f < nbFaces; ++f) if (fOnBdr[f]) {
      face_vertices(M,f,fvert);
      /* Create extruded vertices and edges */
      for (size_t lv = 0; lv < fvert.size(); ++lv) {
        id v = fvert[lv];
        if (vbdr2vext[v] == NO_ID) {
          /* Create extruded vertex and edge */
          vec3 p = M.vertices[v].pt;
          vec3 n = normals[v];
          if (length2(n) > 0.) {
            normalize(n);
            p = p + elens[v] * n;
          }
          id nv = add_vertex(M, p, nullptr, nullptr, updateMappings);
          vbdr2vext[v] = nv;
          id ne = add_edge(M, {v,nv}, nullptr, nullptr, updateMappings);
          vbdr2eext[v] = ne;
        }
      }

      std::vector<id> cfaces = {id(f)};
      std::vector<id> eedges;
      for (size_t le = 0; le < M.faces[f].edges.size(); ++le) {
        id e12 = M.faces[f].edges[le];
        id v1 = M.edges[e12].vertices[0];
        id v2 = M.edges[e12].vertices[1];
        id v3 = vbdr2vext[v2];
        id v4 = vbdr2vext[v1];
        id e23 = vbdr2eext[v2];
        id e14 = vbdr2eext[v1];
        id e34 = ebdr2eext[e12];
        if (e34 == NO_ID) {
          e34 = add_edge(M, {v3,v4}, nullptr, nullptr, updateMappings);
          ebdr2eext[e12] = e34;
        }
        eedges.push_back(e34);
        id nf = ebdr2fext[e12];
        if (nf == NO_ID) {
          nf = add_face(M, {e12,e23,e34,e14}, nullptr, nullptr, updateMappings);
          ebdr2fext[e12] = nf;
        }
        cfaces.push_back(nf);
      }

      id of = add_face(M, eedges, nullptr, nullptr, updateMappings);
      cfaces.push_back(of);

      id nc = add_cell(M, cfaces, nullptr, nullptr, updateMappings);
      newCells.push_back(nc);
    }
    return true;
  }

  bool extrudeBoundary(BrepMesh& M, std::vector<id>& newCells,
      const std::vector<vec3>* vNormals,
      const HexToBoundaryMeshMatching* h2q) 
  {
    if (vNormals == nullptr && h2q == nullptr) {
      error("extrude boundary: expect normals or h2q mappings");
      return false;
    }
    newCells.clear();
    if (!brepMeshMappingsAreUpToDate(M)) {
      update_brep_mesh_mappings(M);
    }

    if (M.cells.size() == 0) {
      debug("Extrude boundary mesh ...");
      std::vector<bool> vOnBdr(M.vertices.size(),true);
      std::vector<bool> eOnBdr(M.edges.size(),true);
      std::vector<bool> fOnBdr(M.faces.size(),true);
      return extrudeBoundaryWithFlaggedBoundary(M, newCells, vNormals, vOnBdr, eOnBdr, fOnBdr);
    } else if (h2q != nullptr) {
      debug("Extrude interior boundary mesh ...");
      std::vector<std::vector<id> > quadMeshFaces;
      bool ok = extract_interior_quad_meshes(M, *h2q, quadMeshFaces);
      if (!ok) {
        error("failed to extract interior quad meshes");
        return false;
      }
      std::vector<bool> vOnBdr(M.vertices.size(),false);
      std::vector<bool> eOnBdr(M.edges.size(),false);
      std::vector<bool> fOnBdr(M.faces.size(),false);
      for (size_t i = 0; i < quadMeshFaces.size(); ++i) {
        for (id f: quadMeshFaces[i]) {
          fOnBdr[f] = true;
          for (id e: M.faces[f].edges) {
            eOnBdr[e] = true;
            for (id v: M.edges[e].vertices) {
              vOnBdr[v] = true;
            }
          }
        }
      }
      return extrudeBoundaryWithFlaggedBoundary(M, newCells, vNormals, vOnBdr, eOnBdr, fOnBdr);
    }

    return true;
  }

  bool build_dual_sheet_oriented(const BrepMesh& H, id eStart, bool eStartInverted, 
      std::vector<id>& sheetEdges, std::vector<bool>& sheetEdgeInverted) {
    RFC(H.edgeToFaces.size() == 0, "edgeToFaces mapping required");
    RFC(H.edges[eStart].vertices[0] == NO_ID, "eStart invalid");
    sheetEdges.clear();
    sheetEdgeInverted.clear();

    vector<bool> visited(H.edges.size(),false);

    /* e = value / 2 
     * inverted = value % 2 */
    vector<id> sheetEdgesOriented;

    /* Init */
    visited[eStart] = true;
    std::queue<id> Q;
    Q.push(2*eStart+id(eStartInverted));

    /* Propagation */
    vector<id> fvert(4);
    while (Q.size() > 0) {
      id es = Q.front();
      Q.pop();
      id e = es / 2;
      bool inv = (bool) es % 2;
      sheetEdgesOriented.push_back(es);
      id2 e_vert = edge_overtices(H,e,inv);

      F(lf,H.edgeToFaces[e].size()) {
        id f = H.edgeToFaces[e][lf];
        id oe = quad_opposite_edge(H,f,e);
        RFC(oe == NO_ID, "failed to build dual sheet");
        if (visited[oe]) continue;
        id2 e2_vert = edge_overtices(H,oe,false);
        face_vertices(H,f,fvert);
        id inv2 = NO_ID;
        F(lv,4) {
          id lv_prev = (4+lv-1)%4;
          id lv_next = (lv+1)%4;
          if (fvert[lv_prev] == e_vert[0] && fvert[lv] == e_vert[1]) {
            if (fvert[lv_next] == e2_vert[0]) {
              inv2 = 0;
              break;
            } else if (fvert[lv_next] == e2_vert[1]) {
              inv2 = 1;
              break;
            }
          } else if (fvert[lv_prev] == e_vert[1] && fvert[lv] == e_vert[0]) {
            if (fvert[lv_next] == e2_vert[0]) {
              inv2 = 1;
              break;
            } else if (fvert[lv_next] == e2_vert[1]) {
              inv2 = 0;
              break;
            }
          }
        }
        RFC(inv2 == NO_ID, "failed to get oriented opposite edge");
        id es2 = 2 * oe + inv2;
        visited[oe] = true;
        Q.push(es2);
      }
    }
    sort_unique(sheetEdgesOriented);

    sheetEdges.resize(sheetEdgesOriented.size());
    sheetEdgeInverted.resize(sheetEdgesOriented.size());
    F(i,sheetEdgesOriented.size()) {
      sheetEdges[i] = sheetEdgesOriented[i] / 2;
      sheetEdgeInverted[i] = sheetEdgesOriented[i] % 2;
    }

    RFC(sheetEdges.size() < 4, "build_dual_sheet | {} edges in sheet, weird", sheetEdges.size());

    return true;
  }

  vector<double> lambda_spacing_power_law(int N, int p = 2) {
    if (N < 1) {
      error("wrong N: {}", N);
      return {};
    }
    vector<double> values(N,0.);
    F(i,N) {
      double v = (double(i) + 1.)/(double(N) + 1.);
      values[i] = std::pow(v,p);
    }
    return values;
  }

	void shape_function(vec3 uvw, double result[8]){
		const double& x = uvw[0];
		const double& y = uvw[1];
		const double& z = uvw[2];
		result[0] = -(x - 1)*(y - 1)*(z - 1); /* 0 0 0*/
		result[1] = x*(y - 1)*(z - 1);        /* 1 0 0*/
		result[2] = -x*y*(z - 1);             /* 1 1 0*/
		result[3] = (x - 1)*y*(z - 1);        /* 0 1 0*/
		result[4] = (x - 1)*(y - 1)*z;        /* 0 0 1*/
		result[5] = -x*(y - 1)*z;             /* 1 0 1*/
		result[6] = x*y*z;                    /* 1 1 1*/
		result[7] = -(x - 1)*y*z;             /* 0 1 1*/
	}

	inline id ijk_to_n(id i, id j, id k, id Nx, id Ny, id Nz) {
	  id n = k * Ny * Nx + j * Nx + i;
	  return n;
	}

	inline void n_to_ijk(id n, id Nx, id Ny, id Nz, id& i, id& j, id& k) {
	  k = n / (Ny*Nx);
	  j = (n - k * (Ny*Nx)) / Nx;
	  i = n - k * (Ny*Nx) - j * Nx;
	}

	inline id hex_ijk_to_global_unique_encoding(const id8& hex, id i, id j, id k, id Nx, id Ny, id Nz) {
    vec3 uvw = {
      double(i) / double(Nx-1.),
      double(j) / double(Ny-1.),
      double(k) / double(Nz-1.)};
    double shape[8];
    shape_function(uvw,shape);
    id encoding = 0;
    F(l,8) encoding += hex[l] * id(1000*shape[l]);
    return encoding;
	}

  struct id2Hash {
    size_t operator()(id2 p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };

  bool subdivide_hexahedron_aniso(
      const id8& hex,
      const vector<vec3>& points,
      const std::unordered_map<id2,vector<double>,id2Hash>& sedgeToSubLambdas,
      vector<id8>& sub_hexes,
      vector<vec3>& vertices_coords,
      vector<id>& vertices_unique_encoding) {
  const id HEX_EDGES[12][2] = {
    {0, 1}, {0, 3}, {0, 4}, {1, 2},
    {1, 5}, {3, 2}, {2, 6}, {3, 7},
    {4, 5}, {4, 7}, {5, 6}, {7, 6}};

    vector<vector<double>> axis_lambdas(3);
    id Nx = 2;
    id Ny = 2;
    id Nz = 2;
    F(d,3) {
      axis_lambdas[d] = {0.,1.};
      id2 vert = {hex[HEX_EDGES[d][0]], hex[HEX_EDGES[d][1]]};
      id2 svert = sorted(vert[0],vert[1]);
      auto it = sedgeToSubLambdas.find(svert);
      if (it != sedgeToSubLambdas.end()) {
        vector<double> las = it->second;
        if (vert[0] != svert[0]) {
          std::reverse(las.begin(),las.end());
        }
        axis_lambdas[d].clear();
        axis_lambdas[d].push_back(0.);
        append(axis_lambdas[d],las);
        axis_lambdas[d].push_back(1.);
        if (d == 0) {
          Nx = 2 + las.size();
        } else if (d == 1) {
          Ny = 2 + las.size();
        } else if (d == 2) {
          Nz = 2 + las.size();
        }
      }
    }

    /* Create the points */
    vec3 uvw;
    double shape[8];
    vector<vec3> grid_pts(Nx*Ny*Nz);
    vector<id> grid_encoding(Nx*Ny*Nz);
    for (id i = 0; i < Nx; ++i) {
      // TODO: get aniso u
      uvw[0] = double(i) / double(Nx-1.);
      uvw[0] = axis_lambdas[0][i];
      for (id j = 0; j < Ny; ++j) {
        // TODO: get aniso v
        uvw[1] = double(j) / double(Ny-1.);
        uvw[1] = axis_lambdas[1][j];
        for (id k = 0; k < Nz; ++k) {
          // TODO: get aniso w
          uvw[2] = double(k) / double(Nz-1.);
          uvw[2] = axis_lambdas[2][k];
          shape_function(uvw,shape);
          vec3 p = {0.,0.,0.};
          F(l,8) p = p + shape[l] * points[hex[l]];
          id n = ijk_to_n(i,j,k,Nx,Ny,Nz);
          RFC(n >= grid_pts.size(), "wrong size, n = {} but grid_pts.size()={}", n, grid_pts.size());
          grid_pts[n] = p;
          id encoding = hex_ijk_to_global_unique_encoding(hex, i, j, k, Nx, Ny, Nz);
          grid_encoding[n] = encoding;
          // grid[i][j][k] = p;
        }
      }
    }

    /* Append new points to in/out points */
    id nbv = vertices_coords.size();
    F(i,grid_pts.size()) {
      vertices_coords.push_back(grid_pts[i]);
      vertices_unique_encoding.push_back(grid_encoding[i]);
    }

    /* Create hexahedra */
    id8 new_hex;
    for (id i = 0; i < Nx-1; ++i) {
      for (id j = 0; j < Ny-1; ++j) {
        for (id k = 0; k < Nz-1; ++k) {
          new_hex[0] = nbv + ijk_to_n(  i,   j,   k, Nx,Ny,Nz);
          new_hex[1] = nbv + ijk_to_n(i+1,   j,   k, Nx,Ny,Nz);
          new_hex[2] = nbv + ijk_to_n(i+1, j+1,   k, Nx,Ny,Nz);
          new_hex[3] = nbv + ijk_to_n(  i, j+1,   k, Nx,Ny,Nz);
          new_hex[4] = nbv + ijk_to_n(  i,   j, k+1, Nx,Ny,Nz);
          new_hex[5] = nbv + ijk_to_n(i+1,   j, k+1, Nx,Ny,Nz);
          new_hex[6] = nbv + ijk_to_n(i+1, j+1, k+1, Nx,Ny,Nz);
          new_hex[7] = nbv + ijk_to_n(  i, j+1, k+1, Nx,Ny,Nz);
          sub_hexes.push_back(new_hex);
        }
      }
    }

    return true;
  }

  bool apply_anistropic_subdivision(BrepMesh& H, 
      int N, const std::vector<id>& sheetEdges, const std::vector<bool>& sheetEdgeInverted,
      ElementMesh& A) {
    RFC(H.faceToCells.size() != H.faces.size(), "requires updated faceToCells");

    id nbe = H.edges.size();
    id nbf = H.faces.size();
    id nbc = H.cells.size();

    /* Compute the sub edge new points */
    std::unordered_map<id2,vector<double>,id2Hash> sedgeToSubLambdas;
    {
      vector<double> lambdas = lambda_spacing_power_law(N,2);
      F(le,sheetEdges.size()) {
        vector<double> las = lambdas;
        id e = sheetEdges[le];
        id2 vert = H.edges[e].vertices;
        id2 svert = sorted(vert[0],vert[1]);
        if (svert[0] != vert[0]) {
          std::reverse(las.begin(),las.end());
        }
        bool inv = sheetEdgeInverted[le];
        if (inv) {
          std::reverse(las.begin(),las.end());
        }
        sedgeToSubLambdas[svert] = las;
      }
    }

    /* Subdivide the hexahedra independantly */
    vector<id8> hexes(nbc);
    vector<vec3> points(H.vertices.size());
    {
      vector<id> vert(8);
      F(c,H.cells.size()) {
        if (H.cells[c].faces.size() != 6) RF("not a hex !");
        hex_vertices(H,c,vert); /* collect vertices (not oriented) */
        F(lv,8) hexes[c][lv] = vert[lv];
      }
      F(v,H.vertices.size()) points[v] = H.vertices[v].pt;
    }
    vector<vector<id8> > sub_hexes(H.cells.size());
    vector<vec3> vertices_coords;
    vector<id> vertices_unique_encoding;
    F(c,H.cells.size()) {
      bool oks = subdivide_hexahedron_aniso(hexes[c], points, sedgeToSubLambdas, sub_hexes[c], vertices_coords, vertices_unique_encoding);
      RFC(!oks,"failed to subdivide hex {}", c);
    }

    // /* Merge the adjacent vertices */
    // vector<id2> vertex_equalities;
    // FC(f,H.faces.size(),H.faceToCells[f].size() == 2) {
    //   unordered_map<id,id2> encoding_to_vertex;
    //   F(i,H.faceToCells[f].size()) {
    //     id c = H.faceToCells[f][i];
    //     F(lsc,sub_hexes[c].size()) {
    //       const id8& hex = sub_hexes[c][lsc];
    //       F(lv,8) {
    //         id v = hex[lv];
    //         id enc = vertices_unique_encoding[v];
    //         auto it = encoding_to_vertex.find(enc);
    //         if (it == encoding_to_vertex.end()) {
    //           encoding_to_vertex[enc] = {NO_ID,NO_ID};
    //         }
    //         encoding_to_vertex[enc][i] = v;
    //       }
    //     }
    //   }
    //   for (const auto& kv: encoding_to_vertex) {
    //     if (kv.second[0] != NO_ID && kv.second[1] != NO_ID) {
    //       vertex_equalities.push_back(kv.second);
    //     }
    //   }
    // }
    // sort_unique(vertex_equalities);

    // vector<id> old2new;
    // id nbi = 0;
    // bool okr = system_reduction_using_graph(vertices_coords.size(),vertex_equalities, old2new, nbi);
    // RFC(!okr, "failed to resolve equalities");

    // A.points.resize(nbi);
    // F(v,vertices_coords.size()) {
    //   A.points[old2new[v]] = vertices_coords[v];
    // }
    // A.cells.reserve(N*H.cells.size());
    // F(c,H.cells.size()) {
    //   F(lsc,sub_hexes[c].size()) {
    //     vector<id> cvert(8);
    //     F(lv,8) cvert[lv] = old2new[sub_hexes[c][lsc][lv]];
    //     A.cells.push_back(cvert);
    //   }
    // }

    // TODO: the version with merge !!! (but bug)
    //       current version is just for visu
    A.points = vertices_coords;
    A.cells.reserve(N*H.cells.size());
    F(c,H.cells.size()) {
      F(lsc,sub_hexes[c].size()) {
        vector<id> cvert(8);
        F(lv,8) cvert[lv] = sub_hexes[c][lsc][lv];
        A.cells.push_back(cvert);
        A.cellData.push_back(H.cells[c].data);
      }
    }

    return true;
  }

  bool quad_from_sheet_in_hex(const BrepMesh& H, id c, const vector<bool>& edgeInSheet, vector<vec3>& quadPts) {
    quadPts.clear();
    vector<id> hex_edges = cell_edges(H,c);
    RFC(hex_edges.size() != 12, "wrong number of edges (size={}) for cell {}", hex_edges.size(), c);
    id n = 0;
    FC(i,hex_edges.size(),edgeInSheet[hex_edges[i]]) {
      n += 1;
    }
    if (n == 0) { /* hex not in sheet */
      return false;
    } else if (n == 4 || n == 8 || n == 12) {
      id nq = n / 4;
      vector<id> sedges(4);
      std::unordered_map<id,bool> done;
      F(k,nq) {
        sedges.clear();
        sedges.resize(4,NO_ID);
        FC(i,hex_edges.size(),edgeInSheet[hex_edges[i]]) {
          auto it = done.find(hex_edges[i]);
          if (it != done.end()) continue;
          sedges[0] = hex_edges[i];
          break;
        }
        RFC(sedges[0] == NO_ID, "quad_opposite_edge | not normal, k={}/nq={}, sedges={}", k, nq, sedges);

        /* The 2 edges face-connected to the first one */
        F(lf,H.cells[c].faces.size()) {
          id f = H.cells[c].faces[lf];
          if (!inVector(sedges[0],H.faces[f].edges)) continue;
          if (sedges[1] == NO_ID) {
            sedges[1] = quad_opposite_edge(H,f,sedges[0]);
          } else if (sedges[3] == NO_ID) {
            sedges[3] = quad_opposite_edge(H,f,sedges[0]);
          } else {
            RF("quad_from_sheet_in_hex | should not happen");
          }
        }

        /* Missing opposite edge */
        F(lf,H.cells[c].faces.size()) {
          id f = H.cells[c].faces[lf];
          if (inVector(sedges[0],H.faces[f].edges) || !inVector(sedges[1],H.faces[f].edges)) continue;
          if (sedges[2] == NO_ID) {
            sedges[2] = quad_opposite_edge(H,f,sedges[1]);
          }
        }
        F(le,sedges.size()) {
          id e = sedges[le];
          RFC(e == NO_ID, "quad_from_sheet_in_hex | NO_ID, should not happen");
          quadPts.push_back(edge_center(H,e));
          done[e] = true;
        }
      }
      return true;
    } else {
      error("hex {}: sheet passes through {} edges, case not supported", c, n);
      return false;
    }

    return true;
  }

  void visualize_sheets(const BrepMesh& H, const std::vector<std::vector<id>>& sheetsEdges, const std::string& viewName) {
    vector<bool> edgeInSheet(H.edges.size(),false);
    F(i,sheetsEdges.size()) {
      const vector<id>& sheetEdges = sheetsEdges[i];
      std::fill(edgeInSheet.begin(),edgeInSheet.end(),false);
      for (id e: sheetEdges) edgeInSheet[e] = true;

      vector<vec3> quadPts;
      F(c,H.cells.size()) {
        bool found = quad_from_sheet_in_hex(H,c,edgeInSheet, quadPts);
        if (found) {
          id nq = quadPts.size() / 4;
          F(j,nq) {
            vector<vec3> pts(quadPts.begin()+4*j,quadPts.begin()+4*j+4);
            vector<double> values(4,double(quadPts.size()));
            GeoLog::add(pts,values,viewName+"_"+std::to_string(i));
          }
        }
      }
    }
    GeoLog::flush();
  }

  bool subdivide_hex_boundary_layer_anistropic(
      BrepMesh& H, 
      HexToBoundaryMeshMatching& h2q,
      int N,
      ElementMesh& A
      ){

    /* Collect edges to subdivide */
    vector<id> sheetEdges;
    vector<bool> sheetEdgeInv;

    vector<bool> done(H.edges.size(),false);
    FC(v,H.vertices.size(),h2q.vertexParent[v].first <= 2) {
      /* Look for a edge connecting the boundary and the interior */
      id neInterior = 0;
      id e = NO_ID;
      F(le,H.vertToEdges[v].size()) {
        id ec = H.vertToEdges[v][le];
        if (h2q.edgeParent[ec].first > 2) {
          neInterior += 1;
          e = ec;
        }
      }
      if (neInterior != 1) continue;
      if (done[e]) continue;
      id v2 = edge_opposite_vertex(H.edges[e].vertices,v);
      if (h2q.vertexParent[v2].first <= 2) continue;

      /* Get the sheet */
      vector<id> sheetEdgesLoc;
      vector<bool> sheetEdgeInvLoc;
      bool inv = (H.edges[e].vertices[1] == v);
      bool oks = build_dual_sheet_oriented(H, e, inv, sheetEdgesLoc, sheetEdgeInvLoc);
      RFC(!oks, "failed to build dual sheet (oriented)");

      visualize_sheets(H, {sheetEdges}, "sheet_"+std::to_string(e));

      append(sheetEdges,sheetEdgesLoc);
      append(sheetEdgeInv,sheetEdgeInvLoc);

      for (id se: sheetEdgesLoc) done[se] = true;
    }

    /* Apply */
    bool oka = apply_anistropic_subdivision(H, N, sheetEdges, sheetEdgeInv, A);
    RFC(!oka, "failed to apply anisotropic subdivision to sheet");

    return true;

  }
}

// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblGmshIO.h"

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
#include <array>


/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "qmtMeshUtils.h"
#include "geolog.h"

/* HexMeshingTools includes */
#include "hblTypes.hpp"
#include "hblLogging.hpp"
#include "hblUtils.h"
#include "hblBrepMesh.h"
#include "hblSolveAllHexLayer.h"
#include "OS.h"

/* gmsh includes */
#include "Context.h"
#include "robin_hood.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "meshGRegion.h"
#include "meshGRegionHxt.h"
#include "discreteFace.h"
#include "discreteRegion.h"

#include "gmsh.h"

/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {hbl::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {hbl::error(__VA_ARGS__); return false;} } while(0)


namespace hbl {
  using std::vector;
  using namespace CppUtils;

  template <typename Key, typename T, typename Hash = robin_hood::hash<Key>,
         typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
         using unordered_map = robin_hood::detail::Table<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

  template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key>,
         size_t MaxLoadFactor100 = 80>
         using unordered_set = robin_hood::detail::Table<true, MaxLoadFactor100, Key, void, Hash, KeyEqual>;

  struct id2Hash {
    size_t operator()(const id2 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      return seed;
    }
  };

  struct id3Hash {
    size_t operator()(const id3 &pr) const noexcept {
      size_t seed = 0;
      hash_combine(seed, robin_hood::hash_bytes(&(pr[0]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[1]), sizeof(id)));
      hash_combine(seed, robin_hood::hash_bytes(&(pr[2]), sizeof(id)));
      return seed;
    }
  };


  bool buildBoundaryMeshFromGRegion(GRegion* gr, BrepMesh& Q) {
    clear_mesh(Q);

    robin_hood::unordered_map<MVertex*,id> old2new;
    robin_hood::unordered_map<id2,id,id2Hash> vPairToEdge;

    vector<id> fedges(4);
    for (GFace* gf: gr->faces()) {
      std::vector<MElement*> elements;
      append(elements,dynamic_cast_vector<MTriangle*,MElement*>(gf->triangles));
      append(elements,dynamic_cast_vector<MQuadrangle*,MElement*>(gf->quadrangles));
      Q.faces.reserve(Q.faces.size()+elements.size());
      for (MElement* f: elements) {
        size_t n = f->getNumVertices();
        fedges.resize(n);
        for (size_t le = 0; le < n; ++le) {
          id v1 = NO_ID;
          id v2 = NO_ID;
          MVertex* pv1 = f->getVertex(le);
          MVertex* pv2 = f->getVertex((le+1)%n);
          bool edgeMayExist = true;
          auto it1 = old2new.find(pv1);
          if (it1 == old2new.end()) { /* Create vertex */
            v1 = add_vertex(Q, pv1->point(), pv1->onWhat(), pv1, false);
            old2new[pv1] = v1;
            edgeMayExist = false;
          } else {
            v1 = it1->second;
          }
          auto it2 = old2new.find(pv2);
          if (it2 == old2new.end()) { /* Create vertex */
            v2 = add_vertex(Q, pv2->point(), pv2->onWhat(), pv2, false);
            old2new[pv2] = v2;
            edgeMayExist = false;
          } else {
            v2 = it2->second;
          }
          id e = NO_ID;
          id2 vPair = sorted(v1,v2);
          if (edgeMayExist) {
            auto ite = vPairToEdge.find(vPair);
            if (ite != vPairToEdge.end()) {
              e = ite->second;
            }
          }
          if (e == NO_ID) { /* Create edge */
            MLine* origin = nullptr;
            GEntity* entity = gf;
            GEntity* ent1 = pv1->onWhat();
            GEntity* ent2 = pv2->onWhat();
            if (ent1->cast2Edge() != nullptr && ent2 == ent1) {
              entity = pv1->onWhat()->cast2Edge();
            } else if (ent1->cast2Edge() != nullptr && ent2->cast2Face() == nullptr) {
              entity = pv1->onWhat()->cast2Edge();
            } else if (ent2->cast2Edge() != nullptr && ent1->cast2Face() == nullptr) {
              entity = pv2->onWhat()->cast2Edge();
            }
            /* this check does not work if GEdge have only
             * one MLine, but should not happen due to midpoint
             * subdivision in quad mesher */
            e = add_edge(Q, vPair, entity, origin, false);
            vPairToEdge[vPair] = e;
          }
          fedges[le] = e;
        }
        id nf = add_face(Q, fedges, gf, f, false);
        if (nf == NO_ID) {
          Msg::Error("buildBoundaryMeshFromGRegion: region %i, face %i, failed to add face",
              gr->tag(), gf->tag());
          error("- element {}, face edges: {}", f->getNum(), fedges);
          return false;
        }
      }
    }

    update_brep_mesh_mappings(Q);

    return true;
  }

  bool computeBoundaryNormals(GRegion* gr, 
      size_t nVertices,
      const robin_hood::unordered_map<MVertex*,id>& pv2nv,
      std::vector<vec3>& normals)
  {
    normals.clear();
    normals.resize(nVertices,vec3{{0.,0.,0.}});

    vector<vector<MTetrahedron*> > v2tets(nVertices);
    vector<vec3> points(nVertices);
    vector<double> avgLen(nVertices,0.);
    vector<double> sums(nVertices,0.);
    for (MTetrahedron* tet: gr->tetrahedra) {
      F(lv,4) {
        MVertex* pv = tet->getVertex(lv);
        auto it = pv2nv.find(pv);
        if (it != pv2nv.end()) { /* vertex on boundary */
          v2tets[it->second].push_back(tet);
          points[it->second] = pv->point();

          MVertex* pv2 = tet->getVertex((lv+1)%4);
          avgLen[it->second] += pv->point().distance(pv2->point());
          sums[it->second] += 1.;
        }
      }
    }
    for (size_t i = 0; i < normals.size(); ++i) if (sums[i] > 0.) {
      avgLen[i] /= sums[i];
    }

    for (GFace* gf: gr->faces()) {
      for (MTriangle* t: gf->triangles) {
        vec3 n = t->getFace(0).normal();
        if (length2(n) == 0.) continue;
        normalize(n);
        for (size_t lv = 0; lv < 3; ++lv) {
          MVertex* v = t->getVertex(lv);
          auto it = pv2nv.find(v);
          if (it != pv2nv.end()) {
            normals[it->second] = normals[it->second] + n;
          }
        }
      }
    }
    for (size_t i = 0; i < normals.size(); ++i) {
      vec3 n = normals[i];
      if (length2(n) > 0.) {
        normalize(n);
      } else {
        n = {0.,0.,1.};
      }

      double normal_eps = 1.e-3 * avgLen[i];
      vec3 query    = points[i] + normal_eps * n;
      vec3 query_op = points[i] - normal_eps * n;
      bool inside = false;
      bool found = false;
      int nb_inside = 0;
      int nb_inside_op = 0;
      F(lc,v2tets[i].size()) {
        MTetrahedron* tet = v2tets[i][lc];
        const std::array<vec3,4> tetPts = {
          tet->getVertex(0)->point(),
          tet->getVertex(1)->point(),
          tet->getVertex(2)->point(),
          tet->getVertex(3)->point()
        };


        double lambda[4];
        bool intet = in_tetrahedron(query,tetPts,lambda);
        if (intet) {
          found = true;
          inside = true;
          nb_inside += 1;
        }
        bool intet_op = in_tetrahedron(query_op,tetPts,lambda);
        if (intet_op) {
          found = true;
          inside = false;
          nb_inside_op += 1;
        }
      }
      if (nb_inside_op > nb_inside) {
        normals[i] = -1. * normals[i];
      }
    }

    return true;
  }

  bool computeDihedralAndSolidBoundaryAngles(
      GRegion* gr, 
      const BrepMesh& Q,
      std::vector<double>& edgeDihedralAngle,
      std::vector<double>& vertexSolidAngle,
      std::vector<vec3>& vertexNormals
      ) {
    debug("computeDihedralAndSolidBoundaryAngles ...");
    edgeDihedralAngle.clear();
    vertexSolidAngle.clear();
    /* TODOMX FIXME ISSUE: HXT 3D is deletin the ge->lines and created new ones
     *                     so old pointers in BrepMesh are invalidated */

    /* Volume meshing options
     * - no optimize => there will be slivers (dihedral angle is 0), but
     *   we don't care for sum of angles computation */
    int mesh_renumber = CTX::instance()->mesh.renumber;
    int mesh_optimize = CTX::instance()->mesh.optimize;
    CTX::instance()->mesh.renumber = 0;
    CTX::instance()->mesh.optimize = 0;

    /* For each region, we build a tetrahedral mesh to
     * compute the angles */

    /* First we need a triangulation on the boundary,
     * then call tet mesher */
    std::vector<MTriangle*> global_triangles_to_del;
    std::unordered_map<GFace*, std::vector<MTriangle*> > trianglesBefore;
    std::unordered_map<GFace*, std::vector<MQuadrangle*> > quadsBefore;

    // // TODOMX: copy lines (new allocations), call hxt, delete lines
    //            and restore initial lines
    // std::unordered_map<GEdge*, std::vector<MLine*> > linesBefore;
    // for (GEdge* ge: gr->edges()) {
    //   linesBefore[ge] = ge->lines;
    // }

    std::vector<GFace*> gr_faces = gr->faces();
    std::vector<int> gr_orient = gr->faceOrientations();
    std::map<GFace*,int> fo;
    if (gr_orient.size() == gr_faces.size()) {
      for (size_t i =  0; i < gr_faces.size(); ++i) {
        fo[gr_faces[i]] = gr_orient[i];
      }
    }
    sort_unique(gr_faces);
    if (gr->faces().size() != gr_faces.size()) {
      Msg::Warning("- Region %i: %li faces but %li unique ones, recreating the region faces", 
          gr->tag(), gr->faces().size(), gr_faces.size());
      std::vector<GFace*> toDel = gr->faces();
      for (GFace* gf: toDel) {
        gr->delFace(gf);
      }
      for (GFace* gf: gr_faces) {
        auto it = fo.find(gf);
        if (it != fo.end()) {
          gr->setFace(gf,it->second);
        } else {
          gr->setFace(gf,1);
        }
      }
    }

    for (GFace* gf: gr_faces) {
      /* backup current mesh */
      trianglesBefore[gf] = gf->triangles;
      quadsBefore[gf] = gf->quadrangles;

      /* get full triangle boundary, and update the GFace mesh
       * with it */
      std::vector<MTriangle*> triangles;
      std::vector<MTriangle*> trianglesToDel; /* will be deleted by HXT 3D */
      bool copyExisting = true;
      bool okt = getGFaceTriangles(gf, triangles, trianglesToDel, copyExisting);
      if (!okt || triangles.size() == 0) {
        Msg::Error("region %i: failed to get triangles for face %i", gr->tag(), gf->tag());
        return false;
      }

      append(global_triangles_to_del, trianglesToDel);
      gf->triangles = triangles;
      gf->quadrangles.clear();

      // DBG(gf->tag(),gf->triangles.size(),gf->quadrangles.size());
    }

    /* Generate tet mesh
     * - BIG WARNING: HXT 3D is deleting all edge lines and face triangles,
     *   and recreating new ones */
    Msg::Info("- Region %i: generate tetrahedral mesh ...", gr->tag());

    std::vector<GRegion*> regions;
    regions.push_back(gr);
    int st = meshGRegionHxt(regions);
    if (st != 0) { 
      Msg::Error("- Region %i: HXT 3D mesh failed, status = %i", gr->tag(), st); 

      /* Restore mesh as before */
      CTX::instance()->mesh.optimize = mesh_optimize;
      CTX::instance()->mesh.renumber = mesh_renumber;
      gr->deleteMesh();
      for (GFace* gf: gr->faces()) {
        gf->triangles = trianglesBefore[gf];
        gf->quadrangles = quadsBefore[gf];
      }
      for (MTriangle* t: global_triangles_to_del) delete t;

      return false;
    }
    Msg::Info("- Region %i: %i vertices, %i tetrahedra", gr->tag(),
        gr->mesh_vertices.size(), gr->tetrahedra.size());
    CTX::instance()->mesh.optimize = mesh_optimize;
    CTX::instance()->mesh.renumber = mesh_renumber;

    /* Compute angles */
    edgeDihedralAngle.resize(Q.edges.size(),0.);
    vertexSolidAngle.resize(Q.vertices.size(),0.);
    robin_hood::unordered_map<MVertex*,id> pv2nv;
    robin_hood::unordered_map<id2,id,id2Hash> pe2ne;
    for (size_t v = 0; v < Q.vertices.size(); ++v) {
      MVertex* pv = Q.vertices[v].origin;
      RFC(pv == nullptr, "Vertex not associated with gmsh MVertex");
      pv2nv[pv] = v;
    }
    for (size_t e = 0; e < Q.edges.size(); ++e) {
      MVertex* v1 = Q.vertices[Q.edges[e].vertices[0]].origin;
      MVertex* v2 = Q.vertices[Q.edges[e].vertices[1]].origin;
      RFC(v1 == nullptr || v2 == nullptr, "Edge vertices not associated with gmsh MVertex");
      id2 vPair = sorted(id(v1->getNum()),id(v2->getNum()));
      pe2ne[vPair] = e;
    }
    
    const id cell_edge_tet[6][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {3, 1}};
    for (MTetrahedron* tet: gr->tetrahedra) {
      const std::array<vec3,4> tetPts = {
        tet->getVertex(0)->point(),
        tet->getVertex(1)->point(),
        tet->getVertex(2)->point(),
        tet->getVertex(3)->point()
      };
      F(le,6) { /* Tet edges */
        MVertex* v1 = tet->getVertex(cell_edge_tet[le][0]);
        MVertex* v2 = tet->getVertex(cell_edge_tet[le][1]);
        id2 vPair = sorted(id(v1->getNum()),id(v2->getNum()));
        auto it = pe2ne.find(vPair);
        if (it != pe2ne.end()) { /* edge on boundary */
          double da = tetrahedronDihedralAngle(tetPts, le);
          if (std::isnan(da)) {
            error("- tet {}, le = {} -> global edge {}: dihedral angle is {}", tet->getNum(), le, it->second, da);
            error("  coordinates: {}", tetPts);
            return false;
          }
          edgeDihedralAngle[it->second] += da;
        }
      }
      F(lv,4) {
        MVertex* pv = tet->getVertex(lv);
        auto it = pv2nv.find(pv);
        if (it != pv2nv.end()) { /* vertex on boundary */
          double sa = tetrahedronSolidAngle(tetPts, lv);
          if (std::isnan(sa)) {
            error("- tet {}, lv = {}: solid angle is {}", tet->getNum(), lv, sa);
            error("  coordinates: {}", tetPts);
            return false;
          }
          vertexSolidAngle[it->second] += sa;
        }
      }
    }

    bool okn = computeBoundaryNormals(gr, Q.vertices.size(), pv2nv, vertexNormals);
    RFC(!okn, "failed to compute boundary normals");


    /* Restore mesh as before */
    debug("- remove tet mesh, restore initial boundary mesh");
    gr->deleteMesh();
    for (GFace* gf: gr_faces) {
      /* delete new triangles created by HXT 3D */
      for (MTriangle* t: gf->triangles) {
        delete t;
      }
      gf->triangles.clear();

      /* put back old elements */
      gf->triangles = trianglesBefore[gf];
      gf->quadrangles = quadsBefore[gf];
    }


    // TODOMX verify no memory leaks 

    debug("... computeDihedralAndSolidBoundaryAngles done");

    return true;
  }


  bool prepareHexblInput(GRegion* gr, HblInput& input, HblOutput& output) {
    double t1 = Cpu();

    bool ok = computeDihedralAndSolidBoundaryAngles(gr, input.Q, input.edgeDihedralAngle, input.vertexSolidAngle, input.vertexNormals);
    if (!ok) {
      error("failed to compute boundary angles");
      return false;
    }

    input.edgeHexValIdeal.resize(input.edgeDihedralAngle.size(),0.);
    for (size_t i = 0; i < input.edgeHexValIdeal.size(); ++i) {
      input.edgeHexValIdeal[i] = input.edgeDihedralAngle[i] * 4. / (2. * M_PI);
    }

    input.vertexHexValIdeal.resize(input.vertexSolidAngle.size(),0.);
    for (size_t i = 0; i < input.vertexHexValIdeal.size(); ++i) {
      input.vertexHexValIdeal[i] = input.vertexSolidAngle[i] * 8. / (4. * M_PI);
    }

    output.stats.timePreprocessing = Cpu()-t1;

    return true;
  }

  bool appendTetMeshBuiltFromQuadBoundary(
      BrepMesh& H,
      const std::vector<std::vector<id> >& quadMeshFaces) {

    robin_hood::unordered_map<MVertex*,id> v2hv; /* Gmsh vertex to H vertex */

    /* Create discreteRegion and its faces */
    discreteRegion* dr = new discreteRegion(GModel::current());
    for (size_t i = 0; i < quadMeshFaces.size(); ++i) {
      discreteFace* df = new discreteFace(GModel::current());

      std::vector<id3> tris;
      bool okt = explicit_triangles_from_quad_faces(H, quadMeshFaces[i], tris);
      RFC(!okt, "bad, wrong tris, should clean");
      std::vector<MVertex*> old2new(H.vertices.size(),nullptr);

      df->mesh_vertices.reserve(quadMeshFaces[i].size() * 3);
      df->triangles.resize(tris.size(), nullptr);
      for (size_t t = 0; t < tris.size(); ++t) {
        MVertex* vs[3];
        for (size_t lv = 0; lv < 3; ++lv) {
          size_t v = tris[t][lv];
          if (old2new[v] == nullptr) {
            vec3 p = H.vertices[v].pt;
            vs[lv] = new MVertex(p[0],p[1],p[2],df);
            old2new[v] = vs[lv];
            v2hv[vs[lv]] = v;
          } else {
            vs[lv] = old2new[v];
          }
        }
        df->triangles[t] = new MTriangle(vs[0],vs[1],vs[2]);
      }

      dr->setFace(df,1);
    }

    /* Mesh with HXT */
    int mesh_renumber = CTX::instance()->mesh.renumber;
    int mesh_optimize = CTX::instance()->mesh.optimize;
    CTX::instance()->mesh.renumber = 0;
    CTX::instance()->mesh.optimize = 1;

    std::vector<GRegion*> regions;
    regions.push_back(dr);
    int st = meshGRegionHxt(regions);
    if (st != 0) { 
      Msg::Error("- Region %i: HXT 3D mesh failed", dr->tag()); 
    }
    Msg::Info("- Region %i: %i vertices, %i tetrahedra", dr->tag(),
        dr->mesh_vertices.size(), dr->tetrahedra.size());
    CTX::instance()->mesh.optimize = mesh_optimize;
    CTX::instance()->mesh.renumber = mesh_renumber;

    /* Add the tetrahedra to the BrepMesh mesh */
    robin_hood::unordered_map<id2,id,id2Hash> pair2he;
    robin_hood::unordered_map<id3,id,id3Hash> tri2hf;

    /* - mark existing quad edges */
    for (size_t i = 0; i < quadMeshFaces.size(); ++i) {
      for (size_t j = 0; j < quadMeshFaces[i].size(); ++j) {
        size_t q = quadMeshFaces[i][j];
        for (size_t le = 0; le < 4; ++le) {
          size_t e = H.faces[q].edges[le];
          id2 vPair = H.edges[e].vertices;
          vPair = sorted(vPair[0],vPair[1]);
          pair2he[vPair] = e;
        }
      }
    }

    vector<id> tfaces(4);
    for (MTetrahedron* tet: dr->tetrahedra) {
      for (size_t lf = 0; lf < tet->getNumFaces(); ++lf) {
        MFace face = tet->getFace(lf);
        id3 faceEdges;
        for (size_t le = 0; le < face.getNumVertices(); ++le) {
          MEdge edge = face.getEdge(le);
          id2 hedge;
          for (size_t lv = 0; lv < 2; ++lv) {
            id v = NO_ID;
            MVertex* pv = edge.getVertex(lv);
            auto itv = v2hv.find(pv);
            if (itv == v2hv.end()) { /* add vertex to H */
              v = add_vertex(H, pv->point(), nullptr, nullptr, false);
              v2hv[pv] = v;
            } else {
              v = itv->second;
            }
            hedge[lv] = v;
          }
          hedge = sorted(hedge[0],hedge[1]);
          id e = NO_ID;
          auto ite = pair2he.find(hedge);
          if (ite == pair2he.end()) { /* add edge to H */
            e = add_edge(H, hedge, nullptr, nullptr, false);
            pair2he[hedge] = e;
          } else {
            e = ite->second;
          }
          faceEdges[le] = e;
        }
        id f = NO_ID;
        faceEdges = sorted(faceEdges[0],faceEdges[1],faceEdges[2]);
        auto itf = tri2hf.find(faceEdges);
        if (itf == tri2hf.end()) { /* add face to H */
          const std::vector<id> fedges = {faceEdges[0],faceEdges[1],faceEdges[2]};
          f = add_face(H, fedges, nullptr, nullptr, false);
          tri2hf[faceEdges] = f;
        } else {
          f = itf->second;
        }
        tfaces[lf] = f;
      }
      add_cell(H, tfaces, nullptr, nullptr, false); /* add tet to H */
    }

    /* Clean */
    for (GFace* df: dr->faces()) {
      delete df;
    }
    delete dr;

    update_brep_mesh_mappings(H);

    return true;
  }

}

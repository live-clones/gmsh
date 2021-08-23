// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblBuildInteriorMesh.h"

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
#include "hblOptimizeGeometry.h"

#if defined(HAVE_WINSLOWUNTANGLER)
#include "winslowUntangler.h"
#endif

/* gmsh includes */
#include "robin_hood.h"
#include "gmsh.h"
#include "GEntity.h"
#include "OS.h"
#include "meshGRegion.h"
#include "meshGRegionHxt.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "Context.h"
#include "TetGenPredicates.h"
#include "meshOctreeLibOL.h"

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
  using namespace CppUtils;

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


  bool decreaseBoundaryLayerThickness(
      BrepMesh& H,
      HexToBoundaryMeshMatching& h2q,
      double thicknessFactor = 0.05) {

    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first > 2) {
        size_t nob = 0;
        vec3 pOnBdr;
        for (id e: H.vertToEdges[v]) {
          id v2 = edge_opposite_vertex(H.edges[e].vertices,v);
          if (h2q.vertexParent[v2].first <= 2) {
            nob += 1;
            pOnBdr = H.vertices[v2].pt;
          }
        }
        if (nob == 1) {
          vec3 p = H.vertices[v].pt;
          vec3 newPos = pOnBdr + thicknessFactor * (p - pOnBdr);
          H.vertices[v].pt = newPos;
        }
      }
    }

    return true;
  }

  bool decreaseBoundaryLayerThickness(
      SimpleMesh& M,
      const BrepMesh& H,
      const HexToBoundaryMeshMatching& h2q,
      double thicknessFactor = 0.05) {

    vector<id> h2m(H.vertices.size(),NO_ID);
    FC(v,M.origin.size(),M.origin[v] != NO_ID) {
      h2m[M.origin[v]] = v;
    }

    F(v,H.vertices.size()) {
      if (h2q.vertexParent[v].first > 2) {
        size_t nob = 0;
        vec3 pOnBdr;
        for (id e: H.vertToEdges[v]) {
          id v2 = edge_opposite_vertex(H.edges[e].vertices,v);
          if (h2q.vertexParent[v2].first <= 2) {
            nob += 1;
            pOnBdr = H.vertices[v2].pt;
          }
        }
        if (nob == 1) {
          vec3 p = H.vertices[v].pt;
          vec3 newPos = pOnBdr + thicknessFactor * (p - pOnBdr);
          id mv = h2m[v];
          if (mv != NO_ID) {
            M.points[mv] = newPos;
          }
        }
      }
    }

    return true;
  }


  bool initMeshTriangulation(
      const BrepMesh& H,
      const std::vector<id3>& tris,
      SimpleMesh& M) {
    M.points.clear();
    M.origin.clear();
    M.triangles.clear();
    M.tets.clear();
    M.hexahedra.clear();

    M.triangles.reserve(tris.size());
    M.points.reserve(tris.size());
    M.origin.reserve(tris.size());

    vector<id> old2new(H.vertices.size(),NO_ID);
    for (size_t t = 0; t < tris.size(); ++t) {
      id3 vs;
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t v = tris[t][lv];
        if (old2new[v] == NO_ID) {
          size_t nv = M.points.size();
          vec3 p = H.vertices[v].pt;
          M.points.push_back(p);
          M.origin.push_back(v);
          old2new[v] = nv;
          vs[lv] = nv;
        } else {
          vs[lv] = old2new[v];
        }
      }
      M.triangles.push_back(vs);
    }

    return true;
  }

  bool initMeshTetrahedrization(
      const std::vector<vec3>& points,
      const std::vector<id3>& tris,
      const std::vector<id4>& tets,
      SimpleMesh& M) {
    M.points.clear();
    M.origin.clear();
    M.triangles.clear();
    M.tets.clear();
    M.hexahedra.clear();

    M.points.reserve(points.size());
    M.origin.reserve(points.size());

    vector<id> old2new(points.size(),NO_ID);
    for (size_t t = 0; t < tris.size(); ++t) {
      id3 vs;
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t v = tris[t][lv];
        if (old2new[v] == NO_ID) {
          size_t nv = M.points.size();
          vec3 p = points[v];
          M.points.push_back(p);
          M.origin.push_back(v);
          old2new[v] = nv;
          vs[lv] = nv;
        } else {
          vs[lv] = old2new[v];
        }
      }
      M.triangles.push_back(vs);
    }
    for (size_t t = 0; t < tets.size(); ++t) {
      id4 vs;
      for (size_t lv = 0; lv < 4; ++lv) {
        size_t v = tets[t][lv];
        if (old2new[v] == NO_ID) {
          size_t nv = M.points.size();
          vec3 p = points[v];
          M.points.push_back(p);
          M.origin.push_back(v);
          old2new[v] = nv;
          vs[lv] = nv;
        } else {
          vs[lv] = old2new[v];
        }
      }
      M.tets.push_back(vs);
    }

    return true;
  }

  bool generateConstrainedTetMesh(SimpleMesh& M, bool tetRefine = true, bool tetOptimize = true) {
    if (M.points.size() == 0 || M.triangles.size() == 0) {
      Msg::Error("generateConstrainedTetMesh: no points or no boundary triangles");
      return false;
    }

    bool success = true;

    if (M.tets.size() > 0) M.tets.clear();

    /* Mesh with HXT */
    int mesh_renumber = CTX::instance()->mesh.renumber;
    int mesh_optimize = CTX::instance()->mesh.optimize;
    CTX::instance()->mesh.renumber = 0;
    CTX::instance()->mesh.optimize = (int) tetOptimize;


    /* Create 'gmsh mesh' before calling tet mesher */
    discreteRegion* dr = new discreteRegion(GModel::current());
    discreteFace* df = new discreteFace(GModel::current());
    dr->setFace(df,1);
    vector<MVertex*> vertices(M.points.size(),nullptr);
    std::unordered_map<MVertex*,id> new2old;
    for (size_t v = 0; v < M.points.size(); ++v) {
      vertices[v] = new MVertex(M.points[v][0],M.points[v][1],M.points[v][2],df);
      df->addMeshVertex(vertices[v]);
      new2old[vertices[v]] = v;
    }
    df->triangles.resize(M.triangles.size(),nullptr);
    for (size_t t = 0; t < M.triangles.size(); ++t) {
      df->triangles[t] = new MTriangle(
          vertices[M.triangles[t][0]],
          vertices[M.triangles[t][1]],
          vertices[M.triangles[t][2]]);
    }
    std::vector<GRegion*> regions;
    regions.push_back(dr);
    int st = meshGRegionHxt(regions, (int) tetRefine);
    if (st != 0) { 
      Msg::Warning("- Region %i: HXT 3D mesh failed", dr->tag()); 
      success = false;
    }

    if (success) {
      M.tets.reserve(dr->tetrahedra.size());
      for (MTetrahedron* tet: dr->tetrahedra) {
        id4 vs;
        for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v = tet->getVertex(lv);
          auto it = new2old.find(v);
          if (it == new2old.end()) { // new vertex
            new2old[v] = M.points.size();
            vs[lv] = M.points.size();
            vec3 p = v->point();
            M.points.push_back(p);
            M.origin.push_back(NO_ID);
            vertices.push_back(v);
          } else {
            vs[lv] = it->second;
          }
        }
        M.tets.push_back(vs);
      }
    }

    /* Clean */
    CTX::instance()->mesh.optimize = mesh_optimize;
    CTX::instance()->mesh.renumber = mesh_renumber;
    // for (MVertex* v: vertices) delete v;
    // for (MTriangle* t: df->triangles) delete t;
    // for (MTetrahedron* t: dr->tetrahedra) delete t;
    delete df;
    delete dr;


    return success;
  }

  bool optimizeTetMeshInterior(SimpleMesh& M) {
    if (M.points.size() == 0 || M.triangles.size() == 0 || M.tets.size() == 0) {
      Msg::Error("optimizeTetMeshInterior: no points or no boundary triangles or no tets");
      return false;
    }

    bool success = true;

    /* Mesh with HXT */
    int mesh_renumber = CTX::instance()->mesh.renumber;
    CTX::instance()->mesh.renumber = 0;

    /* Create 'gmsh mesh' before calling tet mesher */
    GModel* gm2 = new GModel();
    discreteRegion* dr = new discreteRegion(gm2);
    discreteFace* df = new discreteFace(gm2);
    dr->setFace(df,1);
    gm2->add(df);
    gm2->add(dr);
    vector<MVertex*> vertices(M.points.size(),nullptr);
    std::unordered_map<MVertex*,id> new2old;
    vector<int> vertexDim(M.points.size(),4);
    for (size_t t = 0; t < M.tets.size(); ++t) {
      for (size_t lv = 0; lv < 4; ++lv) vertexDim[M.tets[t][lv]] = 3;
    }
    for (size_t t = 0; t < M.triangles.size(); ++t) {
      for (size_t lv = 0; lv < 3; ++lv) vertexDim[M.triangles[t][lv]] = 2;
    }
    for (size_t v = 0; v < M.points.size(); ++v) {
      if (vertexDim[v] == 2) {
        vertices[v] = new MVertex(M.points[v][0],M.points[v][1],M.points[v][2],df);
        df->addMeshVertex(vertices[v]);
      } else if (vertexDim[v] == 3) {
        vertices[v] = new MVertex(M.points[v][0],M.points[v][1],M.points[v][2],dr);
        dr->addMeshVertex(vertices[v]);
      }
      new2old[vertices[v]] = v;
    }
    df->triangles.resize(M.triangles.size(),nullptr);
    for (size_t t = 0; t < M.triangles.size(); ++t) {
      df->triangles[t] = new MTriangle(
          vertices[M.triangles[t][0]],
          vertices[M.triangles[t][1]],
          vertices[M.triangles[t][2]]);
    }
    dr->tetrahedra.resize(M.tets.size(),nullptr);
    for (size_t t = 0; t < M.tets.size(); ++t) {
      dr->tetrahedra[t] = new MTetrahedron(
          vertices[M.tets[t][0]],
          vertices[M.tets[t][1]],
          vertices[M.tets[t][2]],
          vertices[M.tets[t][3]]);
    }
    gm2->rebuildMeshVertexCache();
    gm2->rebuildMeshElementCache();
    // gm2->writeMSH("interior_tets.msh");
    // gm2->writeMESH("interior_tets.mesh");

    std::vector<GRegion*> regions;
    regions.push_back(dr);
    int st = meshGRegionHxtOptimize(regions);
    if (st != 0) { 
      Msg::Warning("- Region %i: HXT 3D mesh optimize failed", dr->tag()); 
      success = false;
    }

    if (success) {
      M.tets.clear();
      M.tets.reserve(dr->tetrahedra.size());
      for (MTetrahedron* tet: dr->tetrahedra) {
        id4 vs;
        for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v = tet->getVertex(lv);
          auto it = new2old.find(v);
          if (it == new2old.end()) { // new vertex
            new2old[v] = M.points.size();
            vs[lv] = M.points.size();
            vec3 p = v->point();
            M.points.push_back(p);
            M.origin.push_back(NO_ID);
            vertices.push_back(v);
          } else {
            vs[lv] = it->second;
            M.points[vs[lv]] = v->point();
          }
        }
        M.tets.push_back(vs);
      }
    }

    /* Clean */
    CTX::instance()->mesh.renumber = mesh_renumber;
    // for (MVertex* v: vertices) delete v;
    // for (MTriangle* t: df->triangles) delete t;
    // for (MTetrahedron* t: dr->tetrahedra) delete t;
    // delete df;
    // delete dr;
    delete gm2;

    return success;
  }

  bool checkTriangleIntersectionsAllPairs( 
      std::vector<vec3>& points,
      const std::vector<std::array<int32_t,3> >& triangles,
      std::vector<id2>& intersections,
      bool earlyStop = false) {
    intersections.clear();
    double t0 = Cpu();

    for (size_t i = 0; i < triangles.size(); ++i) {
      for (size_t j = 0; j < triangles.size(); ++j) {
        if (j >= i) continue;
        double* pts1[3] = {
          points[triangles[i][0]].data(),
          points[triangles[i][1]].data(),
          points[triangles[i][2]].data(),
        };
        double* pts2[3] = {
          points[triangles[j][0]].data(),
          points[triangles[j][1]].data(),
          points[triangles[j][2]].data(),
        };

        int r = TetGenPredicates::tri_tri_inter(pts1[0],pts1[1],pts1[2],pts2[0],pts2[1],pts2[2]);
        if (r != TetGenPredicates::DISJOINT && r != TetGenPredicates::SHAREVERT && r != TetGenPredicates::SHAREEDGE) {
          intersections.push_back(sorted(id(i),id(j)));
          if (earlyStop) {
            Msg::Debug("- checked self-intersections of %li triangles in %.3f sec (all pairs), found one, early stop", triangles.size(), Cpu()-t0);
            return false;
          }
        }
      }
    }
    Msg::Debug("- checked self-intersections of %li triangles in %.3f sec (all pairs), found %li", triangles.size(), Cpu()-t0, intersections.size());
    return intersections.size() == 0;
  }

  void triangle_bbox(
      const std::vector<vec3>& points,
      const std::vector<std::array<int32_t,3> >& triangles,
      size_t t,
      vec3& bbMin,
      vec3& bbMax) {
    bbMin = {DBL_MAX,DBL_MAX,DBL_MAX};
    bbMax = {-DBL_MAX,-DBL_MAX,-DBL_MAX};
    for (size_t lv = 0; lv < 3; ++lv) {
      for (size_t d = 0; d < 3; ++d) {
        const double value = points[triangles[t][lv]][d];
        bbMin[d] = std::min(bbMin[d],value);
        bbMax[d] = std::max(bbMax[d],value);
      }
    }
  }

  bool checkTriangleIntersectionsWithOctree(
      std::vector<vec3>& points,
      const std::vector<std::array<int32_t,3> >& triangles,
      std::vector<id2>& intersections,
      bool earlyStop = false) {
    intersections.clear();
    double t0 = Cpu();

    // Build the octree with the triangles
    libOLwrapper octree(points,{},triangles,{},{},{},{},{});

    robin_hood::unordered_set<id2, id2Hash> pairChecked;
    std::vector<int32_t> trisInBbox;
    for (size_t i = 0; i < triangles.size(); ++i) {
      double* pts1[3] = {
        points[triangles[i][0]].data(),
        points[triangles[i][1]].data(),
        points[triangles[i][2]].data(),
      };

      // Get list of triangles in the bbox of the current triangle
      vec3 bbMin, bbMax;
      triangle_bbox(points, triangles, i, bbMin, bbMax);
      octree.elementsInsideBoundingBox(libOLTypTag::LolTypTri, bbMin.data(), bbMax.data(), trisInBbox);

      // Check the triangle-triangle intersections
      for (size_t j: trisInBbox) {
        if (j == i) continue;
        id2 pairTris = sorted(id(i),id(j));
        if (pairChecked.find(pairTris) != pairChecked.end()) continue;

        double* pts2[3] = {
          points[triangles[j][0]].data(),
          points[triangles[j][1]].data(),
          points[triangles[j][2]].data(),
        };

        int r = TetGenPredicates::tri_tri_inter(pts1[0],pts1[1],pts1[2],pts2[0],pts2[1],pts2[2]);
        if (r != TetGenPredicates::DISJOINT && r != TetGenPredicates::SHAREVERT && r != TetGenPredicates::SHAREEDGE) {
          intersections.push_back(pairTris);
          if (earlyStop) {
            Msg::Debug("- checked self-intersections of %li triangles in %.3f sec (with octree), early stop", triangles.size(), Cpu()-t0);
            return false;
          }
        }

        pairChecked.insert(pairTris);
      }
    }

    Msg::Debug("- checked self-intersections of %li triangles in %.3f sec (with octree), found %li", triangles.size(), Cpu()-t0, intersections.size());

    return intersections.size() == 0;
  }

  bool checkTriangleIntersections(
      std::vector<vec3>& points,
      const std::vector<std::array<int32_t,3> >& triangles,
      std::vector<id2>& intersections,
      bool earlyStop) {
    if (triangles.size() < 100) {
      return checkTriangleIntersectionsAllPairs(points, triangles, intersections, earlyStop);
    } else {
      return checkTriangleIntersectionsWithOctree(points, triangles, intersections, earlyStop);
    }
    return false;
  }

  bool checkBoundarySelfIntersections(SimpleMesh& M, std::vector<id2>& intersections)
  {
    intersections.clear();
    Msg::Debug("Checking boundary self-intersections ...");
    vector<std::array<int32_t,3> > tris(M.triangles.size());
    for (size_t t = 0; t < M.triangles.size(); ++t) {
      tris[t][0] = M.triangles[t][0];
      tris[t][1] = M.triangles[t][1];
      tris[t][2] = M.triangles[t][2];
    }
    checkTriangleIntersections(M.points, tris, intersections);
    if (intersections.size() > 0) {
      Msg::Debug("- %li self-intersections", intersections.size());
      return false;
    }
    Msg::Debug("- no self-intersection");
    return true;
  }

  bool buildCavityWithDistanceToIntersections(
      const SimpleMesh& M, 
      const std::vector<std::vector<id> >& v2t, 
      const std::vector<id2>& intersections,
      std::vector<std::vector<id> >& cavities,
      id dist_threshold = 3) {

    vector<id> triDomain(M.triangles.size(),NO_ID);
    vector<id> dist(M.triangles.size(),NO_ID);

    for (size_t i = 0; i < intersections.size(); ++i) {
      dist[intersections[i][0]] = 0;
      dist[intersections[i][1]] = 0;
    }

    /* Grow Dijsktra-like arround triangle intersections */
    id domain = 0;
    FC(tInit,M.triangles.size(), triDomain[tInit] == NO_ID && dist[tInit] == 0) {
      domain += 1;
      /* Init */
      std::priority_queue<std::pair<id,id>,  std::vector<std::pair<id,id> >,  std::greater<std::pair<id,id> > > qq; 
      qq.push({0,tInit});
      /* Dijkstra-like */
      while (qq.size() > 0) {
        id t = qq.top().second;
        qq.pop();
        triDomain[t] = domain;
        /* Propagation to vertex-adjacent triangles */
        for (size_t lv = 0; lv < 3; ++lv) {
          size_t v = M.triangles[t][lv];
          for (size_t t2: v2t[v]) {
            if (t2 == t) continue;
            if (dist[t2] == 0 && triDomain[t2] == NO_ID) { /* reached another seed */
              triDomain[t2] = domain;
              qq.push({dist[t2],t2});
            } else if (dist[t] + 1 < dist[t2]) {
              dist[t2] = dist[t] + 1;
              if (dist[t2] <= dist_threshold) {
                triDomain[t2] = domain;
                qq.push({dist[t2],t2});
              }
            }
          }
        }
      }
    }
    FC(t,M.triangles.size(),triDomain[t] == NO_ID) triDomain[t] = 0;

    if (domain >= 1) {
      cavities.clear();
      cavities.resize(domain);
      for (size_t t = 0; t < M.triangles.size(); ++t) if (triDomain[t] > 0) {
        cavities[triDomain[t]-1].push_back(t);
      }
    }

    return true;
  }

  bool smoothCavityUntilNoIntersection(
      SimpleMesh& M, 
      std::vector<id>& cavity) {

    std::vector<bool> locked(M.points.size(),false);
    std::unordered_map<id2,int,id2Hash> edgeValence;
    for (id t: cavity) {
      for (size_t le = 0; le < 3; ++le) {
        id v1 = M.triangles[t][le];
        id v2 = M.triangles[t][(le+1)%3];
        edgeValence[sorted(v1,v2)] += 1;
      }
    }
    size_t nbdr = 0;
    for (auto& kv: edgeValence) if (kv.second == 1) {
      locked[kv.first[0]] = true;
      locked[kv.first[1]] = true;
      nbdr += 1;
    }
    if (nbdr == 0) {
      Msg::Warning("no cavity boundary edge");
    }

    vector<vector<id> > v2v(M.points.size());
    for (auto& kv: edgeValence) if (kv.second == 2) {
      id v1 = kv.first[0];
      id v2 = kv.first[1];
      if (!locked[v1]) v2v[v1].push_back(v2);
      if (!locked[v2]) v2v[v2].push_back(v1);
    }

    std::vector<std::array<int32_t,3> > triangles(cavity.size());
    for (size_t i = 0; i < cavity.size(); ++i) {
      triangles[i][0] = M.triangles[cavity[i]][0];
      triangles[i][1] = M.triangles[cavity[i]][1];
      triangles[i][2] = M.triangles[cavity[i]][2];
    }

    std::vector<std::pair<id,vec3> > geometry_backup;
    geometry_backup.reserve(cavity.size());
    for (size_t v = 0; v < v2v.size(); ++v) if (v2v[v].size() > 0 && !locked[v]) {
      geometry_backup.push_back({v,M.points[v]});
    }

    bool ok = false;

    /* Taubin coefficients */
    bool taubin = false;
    double lambda = 0.33;
    double mu = -0.34;
    if (!taubin) {
      lambda = 0.1;
    }

    size_t iterMax = std::max((size_t)50,cavity.size());
    double dx0max = 0.;
    for (size_t iter = 0; iter < iterMax; ++iter) {
      // Taubin / Laplacian smoothing step
      double dxmax = 0.;
      for (size_t v = 0; v < v2v.size(); ++v) if (v2v[v].size() > 0) {
        vec3 avg = {0.,0.,0.};
        for (size_t v2: v2v[v]) {
          avg = avg + M.points[v2];
        }
        avg = avg * (1./double(v2v[v].size()));
        vec3 delta = avg - M.points[v];
        vec3 newPos;
        if (taubin) {
          newPos = (iter % 2 == 0) ? M.points[v] + lambda * delta : M.points[v] + mu * delta;
        } else {
          newPos = M.points[v] + lambda * delta;
        }
        double dx = length(newPos - M.points[v]);
        if (dx > dxmax) dxmax = dx;
        M.points[v] = newPos;
      }
      // Msg::Debug("- smoothing: iter %i, dxmax = %.3e (dx0max = %.3e)", iter, dxmax, dx0max);

      // Check surface auto-intersections
      bool earlyStop = true;
      std::vector<id2> intersections;
      checkTriangleIntersections(M.points, triangles, intersections, true);
      if (intersections.size() == 0) {
        Msg::Debug("- smoothing: reached geometry without intersection at iter %i", iter);
        ok = true;
        break;
      }
      if (iter == 0) {
        dx0max = dxmax;
      } else if (dxmax < 1.e-3 * dx0max) { // vertices no longer moving much, stop
        // Msg::Debug("- smoothing: break at iter %i (vertices no longer moving much)", iter);
        break;
      }
    }

    // Restore geometry if failed to remove self-intersections
    if (!ok) {
      Msg::Debug("- smoothing: failed to untangle, restore geometry");
      for (size_t i = 0; i < geometry_backup.size(); ++i) {
        M.points[geometry_backup[i].first] = geometry_backup[i].second;
      }
    }

    return ok;
  }

  bool fixSelfIntersections(SimpleMesh& M, std::vector<id2>& intersections) {
    std::vector<std::vector<id> > v2t(M.points.size());
    for (size_t t = 0; t < M.triangles.size(); ++t) for (size_t lv = 0; lv < 3; ++lv) {
      v2t[M.triangles[t][lv]].push_back(t);
    }

    /* Create domains around self-intersections and fix them by local smoothing */
    /* Loop over cavity size (dist_threshold applied to distance to self-intersection) */
    id dist_threshold_min = 1;
    id dist_threshold_max = 4;
    for (id dist_threshold = dist_threshold_min; dist_threshold < dist_threshold_max; ++dist_threshold) {
      if (dist_threshold > dist_threshold_min) { // Update intersections
        intersections.clear();
        checkBoundarySelfIntersections(M, intersections);
        if (intersections.size() == 0) break;
      }

      std::vector<std::vector<id> > cavities;
      bool okb = buildCavityWithDistanceToIntersections(M, v2t, intersections, cavities, dist_threshold);
      RFC(!okb, "failed to build cavities");

      Msg::Debug("Fix self-intersections: threshold %i, built %li domains around self-intersections", dist_threshold, cavities.size());

      if (Msg::GetVerbosity() >= 99) {
        for (size_t i = 0; i < cavities.size(); ++i) {
          for (size_t j = 0; j < cavities[i].size(); ++j) {
            vec3 p1 = M.points[M.triangles[cavities[i][j]][0]];
            vec3 p2 = M.points[M.triangles[cavities[i][j]][1]];
            vec3 p3 = M.points[M.triangles[cavities[i][j]][2]];
            GeoLog::add({p1,p2,p3},double(i),"SI_cavity_"+std::to_string(i));
          }
        }
        GeoLog::flush();
      }

      bool remaining = false;
      for (size_t i = 0; i < cavities.size(); ++i) {
        Msg::Debug("- fixing domain %i ... (%li triangles)", i, cavities[i].size());
        bool fixed = smoothCavityUntilNoIntersection(M, cavities[i]);
        if (fixed) {
          Msg::Debug(" -> fixed !");

          if (Msg::GetVerbosity() >= 99) {
            for (size_t j = 0; j < cavities[i].size(); ++j) {
              vec3 p1 = M.points[M.triangles[cavities[i][j]][0]];
              vec3 p2 = M.points[M.triangles[cavities[i][j]][1]];
              vec3 p3 = M.points[M.triangles[cavities[i][j]][2]];
              GeoLog::add({p1,p2,p3},double(i),"SI_fixed_cavity_"+std::to_string(i));
            }
          }
        } else {
          remaining = true;
          Msg::Debug(" -> still some intersections ...");

          if (Msg::GetVerbosity() >= 99) {
            for (size_t j = 0; j < cavities[i].size(); ++j) {
              vec3 p1 = M.points[M.triangles[cavities[i][j]][0]];
              vec3 p2 = M.points[M.triangles[cavities[i][j]][1]];
              vec3 p3 = M.points[M.triangles[cavities[i][j]][2]];
              GeoLog::add({p1,p2,p3},double(i),"SI_FAILED_cavity_"+std::to_string(i));
            }
          }
        }
      }
      if (Msg::GetVerbosity() >= 99) {
        GeoLog::flush();
      }

      if (!remaining) break;
    }

    return intersections.size() == 0;
  }

  constexpr size_t TET_EDGES[6][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {3, 1}};
  constexpr size_t TET_FACETS[4][3] = {{0,2,1},{0,1,3}, {0,3,2}, {3,1,2}};
  constexpr size_t TET_FACE_EDGES[4][3] = {{2,1,0}, {0,5,3}, {3,4,2}, {5,1,4}};

  bool transferSimpleMeshToOutput(
      SimpleMesh& M,
      HblOutput& output) {

    if (M.tets.size() == 0 && M.hexahedra.size() == 0) {
      Msg::Error("no tets and no hexes");
      return false;
    }

    // TODO FIXME non conforming interface

    /* Transfer vertices */
    for (size_t i = 0; i < M.origin.size(); ++i) {
      id v = add_vertex(output.H, M.points[i], nullptr, nullptr, false);
      M.origin[i] = v;
    }

    /* Transfer tets and hexahedra */
    for (size_t c = 0; c < M.tets.size(); ++c) {
      output.tetrahedra.push_back({M.origin[M.tets[c][0]], M.origin[M.tets[c][1]], M.origin[M.tets[c][2]], M.origin[M.tets[c][3]]});
    }
    for (size_t c = 0; c < M.hexahedra.size(); ++c) {
      output.hexahedra.push_back(
          {M.origin[M.hexahedra[c][0]], M.origin[M.hexahedra[c][1]], M.origin[M.hexahedra[c][2]], M.origin[M.hexahedra[c][3]],
           M.origin[M.hexahedra[c][4]], M.origin[M.hexahedra[c][5]], M.origin[M.hexahedra[c][6]], M.origin[M.hexahedra[c][7]]});
    }

    return true;
  }


  constexpr int hex_facet_vertex[6][4] = {
    {0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3}, 
    {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};

  /* tetrahedra (id4) added to output.tetrahedra
   * cell center vertices added to H */
  bool appendHexSubTetrahedraMidpoint(HblOutput& output, BrepMesh& H, const id8& hex,
      const array<bool,6>& localHexFaceOnBdr,
      vector<id3>& boundaryTris,
      const array<bool,6>& localHexFaceOnInt,
      vector<id3>& interiorTris) {

    vec3 center = {0.,0.,0.};
    F(lv,8) center = center + H.vertices[hex[lv]].pt;
    center = center * (1./8.);
    id nc = add_vertex(H, center);

    vector<id4> tets;
    F(lf,6) {
      id4 fvert = {
        hex[hex_facet_vertex[lf][0]],
        hex[hex_facet_vertex[lf][1]],
        hex[hex_facet_vertex[lf][2]],
        hex[hex_facet_vertex[lf][3]]};
      if (std::min(fvert[0],fvert[2]) < std::min(fvert[1],fvert[3])) {
        tets.push_back({fvert[0],fvert[1],fvert[2],nc});
        tets.push_back({fvert[0],fvert[2],fvert[3],nc});
        if (localHexFaceOnBdr[lf]) {
          boundaryTris.push_back({fvert[0],fvert[1],fvert[2]});
          boundaryTris.push_back({fvert[0],fvert[2],fvert[3]});
        }
        if (localHexFaceOnInt[lf]) {
          interiorTris.push_back({fvert[0],fvert[1],fvert[2]});
          interiorTris.push_back({fvert[0],fvert[2],fvert[3]});
        }
      } else {
        tets.push_back({fvert[0],fvert[1],fvert[3],nc});
        tets.push_back({fvert[3],fvert[1],fvert[2],nc});
        if (localHexFaceOnBdr[lf]) {
          boundaryTris.push_back({fvert[0],fvert[1],fvert[3]});
          boundaryTris.push_back({fvert[3],fvert[1],fvert[2]});
        }
        if (localHexFaceOnInt[lf]) {
          interiorTris.push_back({fvert[0],fvert[1],fvert[3]});
          interiorTris.push_back({fvert[3],fvert[1],fvert[2]});
        }
      }
    }

    F(lc,tets.size()) {
      output.tetrahedra.push_back(tets[lc]);
    }

    return true;
  }

  /* See the paper 'How to subdivide pyramids, prisms and hexahedra into tetrahedra' */
  /* if (VI1,VI5) < (VI2,VI4) */
  constexpr int prism_to_tets_1[3][4] = { {0,1,2,5}, {0,1,5,4}, {0,4,5,3} };
  /* if (VI2,VI4) < (VI1,VI5) */
  constexpr int prism_to_tets_2[3][4] = { {0,1,2,4}, {0,4,2,5}, {0,4,5,3} };

  /* Each row i corresponds to i being the lowest vertex in the prism */
  constexpr int prism_reindexing[6][6] = {
    {0, 1, 2, 3, 4, 5},
    {1, 2, 0, 4, 5, 3},
    {2, 0, 1, 5, 3, 4},
    {3, 5, 4, 0, 2, 1},
    {4, 3, 5, 1, 0, 2},
    {5, 4, 3, 2, 1, 0}
  };

  std::array<id4,3> tetsFromPrism(id6 prism) {
    id lvMin = NO_ID;
    id vMin = INT32_MAX;
    FC(lv,6,prism[lv] < vMin) {
      lvMin = lv;
      vMin = prism[lv];
    }
    id6 pr2 = {
      prism[prism_reindexing[lvMin][0]],
      prism[prism_reindexing[lvMin][1]],
      prism[prism_reindexing[lvMin][2]],
      prism[prism_reindexing[lvMin][3]],
      prism[prism_reindexing[lvMin][4]],
      prism[prism_reindexing[lvMin][5]]
    };
    std::array<id4,3> tets;
    if (std::min(pr2[1],pr2[5]) < std::min(pr2[2],pr2[4])) {
      F(lt,3) {
        tets[lt][0] = pr2[prism_to_tets_1[lt][0]];
        tets[lt][1] = pr2[prism_to_tets_1[lt][1]];
        tets[lt][2] = pr2[prism_to_tets_1[lt][2]];
        tets[lt][3] = pr2[prism_to_tets_1[lt][3]];
      }
    } else {
      F(lt,3) {
        tets[lt][0] = pr2[prism_to_tets_2[lt][0]];
        tets[lt][1] = pr2[prism_to_tets_2[lt][1]];
        tets[lt][2] = pr2[prism_to_tets_2[lt][2]];
        tets[lt][3] = pr2[prism_to_tets_2[lt][3]];
      }
    }
    return tets;
  }

  constexpr int hex_reindexing[8][8] = {
    {0,1,2,3,4,5,6,7}, 
    {1,0,4,5,2,3,7,6},
    {2,1,5,6,3,0,4,7},
    {3,0,1,2,7,4,5,6},
    {4,0,3,7,5,1,2,6},
    {5,1,0,4,6,2,3,7},
    {6,2,1,5,7,3,0,4},
    {7,3,2,6,4,0,1,5}};

  const std::vector<id4> hex_to_tets_0 = { id4{0,1,2,5}, id4{0,2,7,5}, id4{0,2,3,7}, id4{0,5,7,4}, id4{2,7,5,6} };
  const std::vector<id4> hex_to_tets_1 = { id4{0,5,7,4}, id4{0,1,7,5}, id4{1,6,7,5}, id4{0,7,2,3}, id4{0,7,1,2}, id4{1,7,6,2} };
  const std::vector<id4> hex_to_tets_2 = { id4{0,4,5,6}, id4{0,3,7,6}, id4{0,7,4,6}, id4{0,1,2,5}, id4{0,3,6,2}, id4{0,6,5,2} };
  const std::vector<id4> hex_to_tets_3 = { id4{0,2,3,6}, id4{0,3,7,6}, id4{0,7,4,6}, id4{0,5,6,4}, id4{1,5,6,0}, id4{1,6,2,0} };

  id8 apply_120deg_rot(id8 hex) {
    id tmp = hex[1];
    hex[1] = hex[4];
    hex[4] = hex[3];
    hex[3] = tmp;
    tmp = hex[5];
    hex[5] = hex[7];
    hex[7] = hex[2];
    hex[2] = tmp;
    return hex;
  }

  id8 apply_240deg_rot(id8 hex) {
    id tmp = hex[1];
    hex[1] = hex[3];
    hex[3] = hex[4];
    hex[4] = tmp;
    tmp = hex[5];
    hex[5] = hex[2];
    hex[2] = hex[7];
    hex[7] = tmp;
    return hex;
  }

  std::vector<id4> tetsFromHex(id8 hex) {
    id lvMin = NO_ID;
    id vMin = INT32_MAX;
    FC(lv,8,hex[lv] < vMin) {
      lvMin = lv;
      vMin = hex[lv];
    }
    id8 hexr = {
      hex[hex_reindexing[lvMin][0]],
      hex[hex_reindexing[lvMin][1]],
      hex[hex_reindexing[lvMin][2]],
      hex[hex_reindexing[lvMin][3]],
      hex[hex_reindexing[lvMin][4]],
      hex[hex_reindexing[lvMin][5]],
      hex[hex_reindexing[lvMin][6]],
      hex[hex_reindexing[lvMin][7]] };
    /* face 1,2,6,5 */
    bool b1 = (std::min(hexr[1],hexr[6]) < std::min(hexr[2],hexr[5]));
    /* face 2,3,7,6 */
    bool b2 = (std::min(hexr[3],hexr[6]) < std::min(hexr[2],hexr[7]));
    /* face 4,5,6,7 */
    bool b3 = (std::min(hexr[4],hexr[6]) < std::min(hexr[5],hexr[7]));
    int n = int(b1) + int(b2) + int(b3); /* number of diagonals through vertex 6 */

    if (!b1 && !b2 &&  b3) {
      hexr = apply_120deg_rot(hexr);
    } else if (!b1 &&  b2 && !b3) {
      hexr = apply_240deg_rot(hexr);
    } else if ( b1 && !b2 &&  b3) {
      hexr = apply_240deg_rot(hexr);
    } else if ( b1 &&  b2 && !b3) {
      hexr = apply_120deg_rot(hexr);
    }

    std::vector<id4> tets;
    if (n == 0) {
      F(lt,hex_to_tets_0.size()) {
        tets.push_back({
            hexr[hex_to_tets_0[lt][0]],
            hexr[hex_to_tets_0[lt][1]],
            hexr[hex_to_tets_0[lt][2]],
            hexr[hex_to_tets_0[lt][3]]});
      }
    } else if (n == 1) {
      F(lt,hex_to_tets_1.size()) {
        tets.push_back({
            hexr[hex_to_tets_1[lt][0]],
            hexr[hex_to_tets_1[lt][1]],
            hexr[hex_to_tets_1[lt][2]],
            hexr[hex_to_tets_1[lt][3]]});
      }
    } else if (n == 2) {
      F(lt,hex_to_tets_2.size()) {
        tets.push_back({
            hexr[hex_to_tets_2[lt][0]],
            hexr[hex_to_tets_2[lt][1]],
            hexr[hex_to_tets_2[lt][2]],
            hexr[hex_to_tets_2[lt][3]]});
      }
    } else if (n == 3) {
      F(lt,hex_to_tets_3.size()) {
        tets.push_back({
            hexr[hex_to_tets_3[lt][0]],
            hexr[hex_to_tets_3[lt][1]],
            hexr[hex_to_tets_3[lt][2]],
            hexr[hex_to_tets_3[lt][3]]});
      }
    }

    return tets;
  }

  bool appendHexSubTetrahedra(HblOutput& output, BrepMesh& H, const id8& hex,
      const array<bool,6>& localHexFaceOnBdr,
      vector<id3>& boundaryTris,
      const array<bool,6>& localHexFaceOnInt,
      vector<id3>& interiorTris) {
    std::vector<id4> tets = tetsFromHex(hex);

    {
      std::unordered_set<id2,id2Hash> edges;
      F(i,tets.size()) F(j,6) {
        id v1 = tets[i][TET_EDGES[j][0]];
        id v2 = tets[i][TET_EDGES[j][1]];
        edges.insert(sorted(v1,v2));
      }
      bool good = true;
      F(lf,6) {
        id4 fvert = {
          hex[hex_facet_vertex[lf][0]],
          hex[hex_facet_vertex[lf][1]],
          hex[hex_facet_vertex[lf][2]],
          hex[hex_facet_vertex[lf][3]]};
        id3 tri1, tri2;
        id2 good_diag, bad_diag;
        if (std::min(fvert[0],fvert[2]) < std::min(fvert[1],fvert[3])) {
          tri1 = {fvert[0],fvert[1],fvert[2]};
          tri2 = {fvert[0],fvert[2],fvert[3]};
          good_diag = sorted(fvert[0],fvert[2]);
          bad_diag = sorted(fvert[1],fvert[3]);
        } else {
          tri1 = {fvert[0],fvert[1],fvert[3]};
          tri2 = {fvert[3],fvert[1],fvert[2]};
          good_diag = sorted(fvert[1],fvert[3]);
          bad_diag = sorted(fvert[0],fvert[2]);
        }
        // // TODO FIXME remove this check when sure
        // auto it1 = edges.find(good_diag);
        // auto it2 = edges.find(bad_diag);
        // if (it1 == edges.end()) {
        //   Msg::Error("good diag should be in tet edges but is not !");
        //   DBG(hex,lf,fvert,good_diag);
        //   good = false;
        // }
        // if (it2 != edges.end()) {
        //   Msg::Error("diag should NOT be in tet edges but is !");
        //   DBG(hex,lf,fvert,bad_diag);
        //   good = false;
        // }
      }
      if (!good) abort();
    }

    F(lc,tets.size()) {
      output.tetrahedra.push_back(invert_tet(tets[lc]));
    }
    F(lf,6) {
      id4 fvert = {
        hex[hex_facet_vertex[lf][0]],
        hex[hex_facet_vertex[lf][1]],
        hex[hex_facet_vertex[lf][2]],
        hex[hex_facet_vertex[lf][3]]};
      id3 tri1, tri2;
      if (std::min(fvert[0],fvert[2]) < std::min(fvert[1],fvert[3])) {
        tri1 = {fvert[0],fvert[1],fvert[2]};
        tri2 = {fvert[0],fvert[2],fvert[3]};
      } else {
        tri1 = {fvert[0],fvert[1],fvert[3]};
        tri2 = {fvert[3],fvert[1],fvert[2]};
      }
      if (localHexFaceOnBdr[lf]) {
        boundaryTris.push_back(tri1);
        boundaryTris.push_back(tri2);
      }
      if (localHexFaceOnInt[lf]) {
        interiorTris.push_back(tri1);
        interiorTris.push_back(tri2);
      }
    }
    return true;
  }

  bool buildTopologicalTetMesh(
      const HblInput& input,
      HblOptions& opt,
      HblOutput& output) {
    Msg::Info("Build interior tet mesh with topological tet padding ...");

    if (output.tetrahedra.size() > 0) {
      Msg::Warning("- already %li tets in output ??", output.tetrahedra.size());
    }

    BrepMesh& H = output.H;
    HexToBoundaryMeshMatching& h2q = output.h2q;

    bool resetMidpoint = true;
    vector<vec3> initialPos(H.vertices.size(),NO_VEC3);
    if (resetMidpoint) {
      /* Reset midpoint positions to be sure tet meshing will works */
      const BrepMesh& Q = input.Q;
      F(v,H.vertices.size()) {
        if (h2q.vertexParent[v].first == 0) {
          initialPos[v] = H.vertices[v].pt;
          H.vertices[v].pt = Q.vertices[h2q.vertexParent[v].second].pt;
        } else if (h2q.vertexParent[v].first == 1) {
          initialPos[v] = H.vertices[v].pt;
          H.vertices[v].pt = edge_center(Q, h2q.vertexParent[v].second);
        } else if (h2q.vertexParent[v].first == 2) {
          initialPos[v] = H.vertices[v].pt;
          H.vertices[v].pt = face_center(Q, h2q.vertexParent[v].second);
        }
      }
    }
    

    /* Duplicate hex and split it into tetrahedra, in coherent ways */
    vector<id3> bdrTris;
    vector<id3> intTris;
    vector<id> v_old2new(H.vertices.size(),NO_ID);
    size_t nVert = H.vertices.size();
    size_t nHexes = output.hexahedra.size();
    F(c,nHexes) {
      id8 hex = output.hexahedra[c];
      /* Check if local hex face on boundary */
      array<bool,6> localHexFaceOnBdr;
      array<bool,6> localHexFaceOnInt;
      F(lf,6) {
        id4 fvert = {
          hex[hex_facet_vertex[lf][0]],
          hex[hex_facet_vertex[lf][1]],
          hex[hex_facet_vertex[lf][2]],
          hex[hex_facet_vertex[lf][3]]};
        bool onBdr = true;
        FC(lv,4,h2q.vertexParent[fvert[lv]].first > 2) onBdr = false;
        localHexFaceOnBdr[lf] = onBdr;
        bool onInt = true;
        FC(lv,4,h2q.vertexParent[fvert[lv]].first <= 2) onInt = false;
        localHexFaceOnInt[lf] = onInt;
      }

      id8 nhex = hex;
      size_t nVertOnBdr = 0;
      F(lv,8) {
        id v = hex[lv];
        if (h2q.vertexParent[v].first <= 2) { 
          nVertOnBdr += 1;
          /* vertex on initial surface becomes duplicated (mirrored) inside */
          if (v_old2new[v] == NO_ID) {
            id nv = H.vertices.size();
            v_old2new[v] = nv;
            H.vertices.push_back(H.vertices[v]);
            H.vertices[nv].entity = nullptr;
            H.vertices[nv].origin = nullptr;
          }
          nhex[lv] = v_old2new[v];
        }
      }

      vector<id3> bdrTrisL;
      vector<id3> intTrisL;
      if (nVertOnBdr >= 4) {
        appendHexSubTetrahedra(output, H, nhex, localHexFaceOnBdr, bdrTrisL, localHexFaceOnInt, intTrisL);
      } else {
        appendHexSubTetrahedraMidpoint(output, H, nhex, localHexFaceOnBdr, bdrTrisL, localHexFaceOnInt, intTrisL);
      }
      append(bdrTris, bdrTrisL);
      append(intTris, intTrisL);
    }
    Msg::Info("- added padding layer of %li tets from decomposing %li hexes", output.tetrahedra.size(), output.hexahedra.size());
    bool oko1 = orient_tetrahedra_coherent(output.tetrahedra);
    RFC(!oko1, "failed to orient tetrahedra coherently");

    /* Add extruded tetrahedra on top of tetrahedra obtained by hex subdivision.
     * Required to avoid duplicated tets after constrained tet mesh (because of
     * "inverted" geometry) */
    vector<id3> extrudedTris(bdrTris.size());
    vector<id> bdr2ext(H.vertices.size(),NO_ID);
    size_t nTetExt = 0;
    F(i,bdrTris.size()) {
      F(lv,bdrTris[i].size()) {
        id v = bdrTris[i][lv];
        if (bdr2ext[v] == NO_ID) {
          id nv = add_vertex(H, H.vertices[v].pt);
          bdr2ext[v] = nv;
        }
        extrudedTris[i][lv] = bdr2ext[v];
      }
      id6 prism = {bdrTris[i][0], bdrTris[i][1], bdrTris[i][2],
        extrudedTris[i][0], extrudedTris[i][1], extrudedTris[i][2]};

      std::array<id4,3> tets = tetsFromPrism(prism);
      F(lt,3) {
        output.tetrahedra.push_back(invert_tet(tets[lt]));
        nTetExt += 1;
      }
    }
    Msg::Info("- added padding layer of %li extruded tets", nTetExt);

    h2q.vertexParent.resize(H.vertices.size(),NO_PARENT);
    h2q.edgeParent.resize(H.edges.size(),NO_PARENT);
    h2q.faceParent.resize(H.faces.size(),NO_PARENT);

    bool oko = orient_tetrahedra_coherent(output.tetrahedra);
    RFC(!oko, "failed to orient tetrahedra coherently");

    SimpleMesh M;
    initMeshTriangulation(H, extrudedTris, M);
    bool tetRefine = false;
    bool tetOptimize = false;
    Msg::Info(" - constrained tet meshing ...");
    bool okg = generateConstrainedTetMesh(M, tetRefine, tetOptimize);
    if (!okg) {
      Msg::Error("failed to generate tet mesh of midpoint-subdivided input !");
      return false;
    }
    if (resetMidpoint) { /* Set anisotropic quads again */
      FC(v,initialPos.size(),initialPos[v] != NO_VEC3) {
        H.vertices[v].pt = initialPos[v];
      }
    }

    F(i,M.tets.size()) {
      id4 tet = M.tets[i];
      id4 htet;
      F(lv,tet.size()) {
        id v = tet[lv];
        if (M.origin[v] == NO_ID) {
          id nv = add_vertex(H, M.points[v]);
          M.origin[v] = nv;
        }
        htet[lv] = M.origin[v];
      }
      output.tetrahedra.push_back(htet);
    }

    h2q.vertexParent.resize(H.vertices.size(),NO_PARENT);
    h2q.edgeParent.resize(H.edges.size(),NO_PARENT);
    h2q.faceParent.resize(H.faces.size(),NO_PARENT);

    { // Laplacian smoothing
      Msg::Info("- laplacian smoothing of interior tets (explicit loop) ...");
      vector<vector<id> > v2v(H.vertices.size());
      F(c,output.tetrahedra.size()) {
        F(le,6) {
          id v1 = output.tetrahedra[c][TET_EDGES[le][0]];
          id v2 = output.tetrahedra[c][TET_EDGES[le][1]];
          v2v[v1].push_back(v2);
          v2v[v2].push_back(v1);
        }
      }
      F(v,v2v.size()) {
        if (v < nVert || h2q.vertexParent[v].first <= 2) {
          v2v[v].clear();
        }
      }
      size_t nIter = 10;
      double lambda = 1.;
      F(iter,nIter) {
        FC(v,v2v.size(),v2v[v].size() > 0)  {
          vec3 avg = {0.,0.,0.};
          for (id v2: v2v[v]) {
            avg = avg + H.vertices[v2].pt;
          }
          avg = avg * double(1./v2v[v].size());
          H.vertices[v].pt = (1.-lambda) * H.vertices[v].pt + lambda * avg;
        }
      }
    }
    size_t nNeg = 0;
    F(c,output.tetrahedra.size()) {
      std::array<std::array<double,3>,4> shape = {
        H.vertices[output.tetrahedra[c][0]].pt,
        H.vertices[output.tetrahedra[c][1]].pt,
        H.vertices[output.tetrahedra[c][2]].pt,
        H.vertices[output.tetrahedra[c][3]].pt
      };
      double tvol = 1./6. * basicOrient3d(shape[0],shape[1],shape[2],shape[3]);
      if (tvol <= 0) nNeg += 1;
    }
    if (nNeg > 0) {
      Msg::Warning("- interior tet mesh contains %li/%li inverted tetrahedra (normal because of topological padding)",
          nNeg, output.tetrahedra.size());
    }

    bool winslow = false;
    if (winslow) {
      // Winslow untangler on tets
      vector<vec3> points(H.vertices.size());
      F(v,H.vertices.size()) points[v] = H.vertices[v].pt;
      vector<bool> locked(points.size(),false);
      F(v,points.size()) {
        if (v < nVert || h2q.vertexParent[v].first <= 2) {
          locked[v] = true;
        }
      }

      std::array<vec3,4> equi = {vec3{.5, 0, -1. / (2. * std::sqrt(2.))},
        vec3{-.5, 0, -1. / (2. * std::sqrt(2.))},
        vec3{0, .5, 1. / (2. * std::sqrt(2.))},
        vec3{0, -.5, 1. / (2. * std::sqrt(2.))}};
      double reg_vol = -1./6. * basicOrient3d(equi[0], equi[1], equi[2], equi[3]);
      for(size_t lv = 0; lv < 4; ++lv) {
        equi[lv] = equi[lv] * (1. / std::pow(reg_vol, 1. / 3.));
      }

      std::vector<std::array<std::array<double,3>,4> > tetIdealShapes(output.tetrahedra.size());
      vector<std::array<uint32_t,4> > tets(output.tetrahedra.size());
      double avgVol = 0.;
      F(c,output.tetrahedra.size()) {
        id4 tet = output.tetrahedra[c];
        tet = invert_tet(tet); // invert tet for winslow untangler
        tets[c] = { uint32_t(tet[0]), uint32_t(tet[1]), uint32_t(tet[2]), uint32_t(tet[3])};
        std::array<std::array<double,3>,4> shape;
        shape = equi;

        tetIdealShapes[c] = shape;
        double vol = -1./6. * basicOrient3d(shape[0], shape[1], shape[2], shape[3]);
        avgVol += vol;
      }
      avgVol /= double(tetIdealShapes.size());
      // Scale the target shapes
      F(i,tetIdealShapes.size()) {
        F(lv,tetIdealShapes[i].size()) {
          tetIdealShapes[i][lv] = (1./std::pow(avgVol,1./3.))*tetIdealShapes[i][lv];
        }
      }

      int iterMaxOuter = 10;
      int iterMaxInner = 500;
      int nFailMax = 3;
      double timeMax = 30;
      double lambda = 1./127.;

      Msg::Info("Winslow untangler on tets ...");
#if defined(HAVE_WINSLOWUNTANGLER)
      bool oku = untangle_tetrahedra(points, locked, tets, tetIdealShapes,
          lambda, iterMaxInner, iterMaxOuter, nFailMax, timeMax);
#else
      Msg::Error("WinslowUntangler module missing");
#endif
      FC(v,points.size(),!locked[v]) {
        H.vertices[v].pt = points[v];
      }


    }

    if (false) {
      Msg::Info("HXT optimize tets ...");
      Msg::Warning("do not work, I don't know why");
      vector<vec3> points(H.vertices.size());
      F(v,H.vertices.size()) points[v] = H.vertices[v].pt;
      SimpleMesh T;
      vector<id4> tetsInv = output.tetrahedra;
      // F(i,tetsInv.size()) tetsInv[i] = invert_tet(tetsInv[i]);
      initMeshTetrahedrization(points, intTris, tetsInv, T);
      optimizeTetMeshInterior(T);
    }

    output.stats.interiorTetMeshTopoFallback = 1;

    return true;
  }


  double random_double(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
  }

  bool buildTetMeshFromQuadMesh(
      HblOutput& output,
      const std::vector<id>& quadFaces,
      size_t& nbSelfIntersections) {
    if (output.tetrahedra.size() > 0) {
      Msg::Warning("buildTetMeshFromQuadMesh: already tets in output, weird");
    }

    /* Triangulation of the interior surface */
    std::vector<id3> tris;
    bool okt = explicit_triangles_from_quad_faces(output.H, quadFaces, tris);
    RFC(!okt, "failed to get triangles from quads");
    SimpleMesh M;
    initMeshTriangulation(output.H, tris, M);

    /* Constrained tet meshing */
    bool tetRefine = false;
    bool tetOptimize = false;
    bool okg = generateConstrainedTetMesh(M, tetRefine, tetOptimize);
    if (okg) {
      nbSelfIntersections = 0;
      bool oktr = transferSimpleMeshToOutput(M, output);
      RFC(!oktr, "failed to transfer tets/hexes to output");
      return true;
    }

    /* Failed to tet mesh, check self-intersections */
    std::vector<id2> triIntersections;
    checkBoundarySelfIntersections(M, triIntersections);
    nbSelfIntersections = triIntersections.size();
    Msg::Debug("failed to generate constrained tet mesh: %li self-intersections (%li tris)",
        nbSelfIntersections, tris.size());
    double prop = double(nbSelfIntersections) / double(tris.size());
    if (prop > 0.01) {
      return false;
    }

    /* Few self-intersections, try to smooth them out */
    Msg::Debug("Try to fix self-intersections by smoothing ...");
    fixSelfIntersections(M, triIntersections);
    if (triIntersections.size() > 0) {
      Msg::Debug("still %li self-intersections -> no tet mesh", triIntersections.size());
      return false;
    }

    okg = generateConstrainedTetMesh(M, tetRefine, tetOptimize);
    if (okg) {
      nbSelfIntersections = 0;
      bool oktr = transferSimpleMeshToOutput(M, output);
      RFC(!oktr, "failed to transfer tets/hexes to output");
      return true;
    }

    return okg;
  }

  bool buildInteriorHexdomMesh(
      const HblInput& input,
      HblOptions& opt,
      HblOutput& output) {
    /* Extract interior quad mesh */
    std::vector<std::vector<id> > quadMeshFaces;
    bool okq = extract_interior_quad_meshes(output.H, output.h2q, quadMeshFaces);
    RFC(!okq, "failed to extract interior quad meshes");
    if (quadMeshFaces.size() != 1) {
      Msg::Error("buildInteriorHexdomMesh: expects one interior quad mesh, not %li", quadMeshFaces.size());
      return false;
    }
    vector<id> quadFaces = quadMeshFaces[0];
    if (opt.debug && opt.viz) {
      for (auto& a: quadMeshFaces) visualization_show_faces(output.H, quadFaces, "int_quads_init");
    }

    /* Try tet meshing of the quad mesh */
    Msg::Info("Try tet meshing of the interior quad mesh (%li quads) ...", quadFaces.size());
    size_t nbSelfIntersections = 0;
    bool okt = buildTetMeshFromQuadMesh(output, quadFaces, nbSelfIntersections);
    if (okt) {
      Msg::Info("interior successfully meshed with %li tetrahedra", output.tetrahedra.size());
      output.stats.interiorTetMesh = 1;
      return true;
    }

    /* Try to reduce thickness, untangle hex layer, then tet mesh */
    if (false) {
      double propSI = double(nbSelfIntersections) / double(2*quadFaces.size());
      if (propSI > 0.001) {
        vector<double> factors = {opt.extrusion_factor, 0.3 * opt.extrusion_factor, 0.1 * opt.extrusion_factor, 0.03 * opt.extrusion_factor};
        vector<size_t> nSI(factors.size(),quadFaces.size());
        nSI[0] = nbSelfIntersections;
        for (size_t t = 1; t < factors.size(); ++t) {
          opt.extrusion_factor = factors[t];
          Msg::Info("Reduce all-hex layer thickness to factor %f and try to tet mesh",opt.extrusion_factor);
          initializeHexLayerGeometry(input, opt, output);
          optimizeHexLayerGeometry(input, opt, output);
          bool okt = buildTetMeshFromQuadMesh(output, quadFaces, nSI[t]);
          if (okt) {
            Msg::Info("interior successfully meshed with %li tetrahedra", output.tetrahedra.size());
            output.stats.interiorTetMesh = 1;
            return true;
          }
          if (nSI[t] > 1.1*nSI[t-1]) break; /* # self-intersections increased, stop */
        }
        /* Keep hex-layer with less number of self-intersections */
        size_t nMin = INT32_MAX;
        size_t kBest = 0;
        FC(k,nSI.size(),nSI[k] < nMin) {
          nMin = nSI[k];
          kBest = k;
        }
        opt.extrusion_factor = factors[kBest];
        Msg::Info("Set all-hex layer thickness to factor %f",opt.extrusion_factor);
        initializeHexLayerGeometry(input, opt, output);
        optimizeHexLayerGeometry(input, opt, output);
      }
    }

    Msg::Info("Fallback to topological tet mesh construction");
    return buildTopologicalTetMesh(input, opt, output);
  }
}


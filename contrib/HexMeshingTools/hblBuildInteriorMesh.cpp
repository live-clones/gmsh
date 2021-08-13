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


  bool initMeshTriangulation(
      const BrepMesh& H,
      const std::vector<id3>& tris,
      SimpleMesh& M) {
    M.points.clear();
    M.origin.clear();
    M.triangles.clear();
    M.tets.clear();

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

  bool generateConstrainedTetMesh(SimpleMesh& M, bool tetRefine = true, bool tetOptimize = true) {
    if (M.points.size() == 0 || M.triangles.size() == 0) {
      Msg::Error("generateConstrainedTetMesh: no points or no boundary triangles");
      return false;
    }
    if (!tetRefine) {
      Msg::Warning("tetRefine forced to true by current meshGRegionHxt API");
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
    int st = meshGRegionHxt(regions);
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

    // if (false) {
    //   Msg::Warning("==== checking intersections for %li triangles ===", triangles.size());

    //   intersections.clear();
    //   double t0 = Cpu();
    //   checkTriangleIntersectionsAllPairs(points, triangles, intersections, false);
    //   double t1 = Cpu();
    //   Msg::Warning("--- allPairs: %li intersections %.5f seconds", intersections.size(), t1 - t0);

    //   intersections.clear();
    //   double t2 = Cpu();
    //   checkTriangleIntersectionsWithOctree(points, triangles, intersections, false);
    //   double t3 = Cpu();
    //   Msg::Warning("--- octree:   %li intersections %.5f seconds", intersections.size(), t3 - t2);

    //   Msg::Warning("=====");
    // }

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
    Msg::Info("Checking boundary self-intersections ...");
    vector<std::array<int32_t,3> > tris(M.triangles.size());
    for (size_t t = 0; t < M.triangles.size(); ++t) {
      tris[t][0] = M.triangles[t][0];
      tris[t][1] = M.triangles[t][1];
      tris[t][2] = M.triangles[t][2];
    }
    checkTriangleIntersections(M.points, tris, intersections);
    if (intersections.size() > 0) {
      Msg::Warning("- %li self-intersections", intersections.size());
      return false;
    }
    Msg::Info("- no self-intersection");
    return true;
  }

  // grow cavity by adding all vertex-adjacent triangles
  bool grow(const SimpleMesh& M, 
      const std::vector<std::vector<id> >& v2t, 
      std::vector<id>& cavity) {
    const size_t nt = cavity.size();
    for (size_t lt = 0; lt < nt; ++lt) {
      size_t t = cavity[lt];
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t v = M.triangles[t][lv];
        for (size_t t2: v2t[v]) {
          auto it = std::find(cavity.begin(),cavity.end(),t2);
          if (it == cavity.end()) {
            cavity.push_back(t2);
          }
        }
      }
    }
    return true;
  }

  int computeEulerCharacteristic(const std::vector<id3>& triangles) {
    vector<id> vertices;
    vector<id2> edges;
    vertices.reserve(triangles.size());
    edges.reserve(triangles.size());
    for (size_t t = 0; t < triangles.size(); ++t) {
      for (size_t lv = 0; lv < 3; ++lv) {
        vertices.push_back(triangles[t][lv]);
        edges.push_back(sorted(triangles[t][lv],triangles[t][(lv+1)%3]));
      }
    }
    sort_unique(vertices);
    sort_unique(edges);
    int X = int(vertices.size()) - int(edges.size()) + int(triangles.size());
    return X;
  }

  bool buildCavity(
      const SimpleMesh& M, 
      const std::vector<std::vector<id> >& v2t, 
      id2 trianglePair,
      std::vector<id>& cavity) {
    // Init cavity with the two intersecting triangles
    cavity.clear();
    cavity.push_back(trianglePair[0]);
    cavity.push_back(trianglePair[1]);

    // Grow until cavity is single component
    bool ok = false;
    size_t GMAX = 5;
    for (size_t iter = 0; iter < GMAX; ++iter) {
      grow(M, v2t, cavity);
      vector<id3> cavity_tris(cavity.size());
      for (size_t t = 0; t < cavity.size(); ++t) {
        cavity_tris[t] = M.triangles[cavity[t]];
      }
      int X = computeEulerCharacteristic(cavity_tris);
      DBG(iter,cavity_tris.size(),X);
      if (X == 1) {
        ok = true;
        break;
      }
    }

    return ok;
  }

  bool fixCavity(
      SimpleMesh& M, 
      const std::vector<std::vector<id> >& v2t, 
      std::vector<id>& cavity) {
    for (size_t t = 0; t < cavity.size(); ++t) {
      vec3 p1 = M.points[M.triangles[cavity[t]][0]];
      vec3 p2 = M.points[M.triangles[cavity[t]][1]];
      vec3 p3 = M.points[M.triangles[cavity[t]][2]];
      double col = 0.;
      if (t <= 1) {
        col = 1.;
      }
      GeoLog::add({p1,p2,p3},col,"cavity");
    }
    GeoLog::flush();
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
    double lambda = 0.1;
    size_t iterMax = std::max((size_t)100,cavity.size());
    double dx0max = 0.;
    for (size_t iter = 0; iter < iterMax; ++iter) {
      // Laplacian smoothing step
      double dxmax = 0.;
      for (size_t v = 0; v < v2v.size(); ++v) if (v2v[v].size() > 0) {
        vec3 avg = {0.,0.,0.};
        for (size_t v2: v2v[v]) {
          avg = avg + M.points[v2];
        }
        avg = avg * (1./double(v2v[v].size()));
        vec3 newPos = (1.-lambda) * M.points[v] + lambda * avg;
        double dx = length(newPos - M.points[v]);
        if (dx > dxmax) dxmax = dx;
        M.points[v] = newPos;
      }
      Msg::Debug("- smoothing: iter %i, dxmax = %.3e (dx0max = %.3e)", iter, dxmax, dx0max);

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
        Msg::Debug("- smoothing: break at iter %i (vertices no longer moving much)", iter);
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
    id dist_threshold_max = 5;
    for (id dist_threshold = dist_threshold_min; dist_threshold < dist_threshold_max; ++dist_threshold) {
      if (dist_threshold > dist_threshold_min) { // Update intersections
        intersections.clear();
        checkBoundarySelfIntersections(M, intersections);
        if (intersections.size() == 0) break;
      }

      std::vector<std::vector<id> > cavities;
      bool okb = buildCavityWithDistanceToIntersections(M, v2t, intersections, cavities, dist_threshold);
      RFC(!okb, "failed to build cavities");

      Msg::Info("Threshold %i, built %li domains around self-intersections", dist_threshold, cavities.size());

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
        Msg::Info("- fixing domain %i ... (%li triangles)", i, cavities[i].size());
        bool fixed = smoothCavityUntilNoIntersection(M, cavities[i]);
        if (fixed) {
          Msg::Info(" -> Yeah !");

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
          Msg::Warning(" -> still some intersections ...");

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

    // for (size_t i = 0; i < intersections.size(); ++i) {
    //   std::vector<id> cavity;
    //   buildCavity(M, v2t, intersections[i], cavity);
    //   DBG(i, intersections[i],cavity);
    //   fixCavity(M, v2t, cavity);
    // }
    // gmsh::fltk::run();
    // abort();

    return true;
  }

  bool transferSimpleMeshToBrepMesh(
      SimpleMesh& M,
      const std::vector<std::vector<id> >& quadMeshFaces,
      HblOutput& output) {

    if (M.tets.size() == 0 && M.hexahedra.size() == 0) {
      Msg::Error("no tets and no hexes");
      return false;
    }

    BrepMesh& H = output.H;

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

    /* Transfer vertices */
    for (size_t i = 0; i < M.origin.size(); ++i) if (M.origin[i] == NO_ID) {
      id v = add_vertex(H, M.points[i], nullptr, nullptr, false);
      M.origin[i] = v;
    }

    const size_t TET_EDGES[6][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {3, 1}};
    const size_t TET_FACETS[4][3] = {{0,2,1},{0,1,3}, {0,3,2}, {3,1,2}};
    const size_t TET_FACE_EDGES[4][3] = {{2,1,0}, {0,5,3}, {3,4,2}, {5,1,4}};

    vector<id> tfaces(4);
    for (size_t c = 0; c < M.tets.size(); ++c) {
      for (size_t lf = 0; lf < 4; ++lf) {
        id3 faceEdges;
        for (size_t lfe = 0; lfe < 3; ++lfe) {
          size_t le = TET_FACE_EDGES[lf][lfe];
          size_t lvs[2] = {TET_EDGES[le][0], TET_EDGES[le][1]};
          id2 edge = {M.origin[M.tets[c][lvs[0]]], M.origin[M.tets[c][lvs[1]]]};
          edge = sorted(edge[0],edge[1]);
          id e = NO_ID;
          auto ite = pair2he.find(edge);
          if (ite == pair2he.end()) { /* add edge to H */
            e = add_edge(H, edge, nullptr, nullptr, false);
            pair2he[edge] = e;
          } else {
            e = ite->second;
          }
          faceEdges[lfe] = e;
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

    return true;
  }

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

  bool exportQuadAndTetMeshToFile(
      /* topology of the quad mesh */
      const BrepMesh& M,  
      const std::vector<id>& quadFaces,
      /* new geometry after self-intersection repair */
      const SimpleMesh& G, 
      const std::string& filename,
      bool withTets = true) {

    GModel* gm = new GModel();
    discreteFace* df = new discreteFace(gm);
    discreteRegion* dr = new discreteRegion(gm);
    gm->add(df);
    gm->add(dr);
    dr->setFace(df,1);

    vector<id> vert_M2G(M.vertices.size(),NO_ID);
    for (size_t i = 0; i < G.origin.size(); ++i) if (G.origin[i] != NO_ID) {
      vert_M2G[G.origin[i]] = i;
    }

    vector<id> fvert;
    vector<MVertex*> new_vertices(M.vertices.size(),nullptr);
    df->quadrangles.reserve(quadFaces.size());
    for (id f: quadFaces) {
      face_vertices(M, f, fvert);;

      MVertex* nvs[4];
      for (size_t lv = 0; lv < fvert.size(); ++lv) {
        id _v = fvert[lv]; /* vertex id in M */
        id gv = vert_M2G[_v]; /* vertex id in G */
        vec3 pt = G.points[gv]; /* position in G */

        if (new_vertices[gv] == nullptr) {
          new_vertices[gv] = new MVertex(pt[0],pt[1],pt[2],df);
          df->addMeshVertex(new_vertices[gv]);
        }
        nvs[lv] = new_vertices[gv];
      }
      df->quadrangles.push_back(new MQuadrangle(nvs[0], nvs[1], nvs[2], nvs[3]));
    }

    if (withTets) {
      for (size_t i = 0; i < G.tets.size(); ++i) {
        MVertex* nvs[4];
        for (size_t lv = 0; lv < 4; ++lv) {
          id gv = G.tets[i][lv];
          vec3 pt = G.points[gv]; /* position in G */
          if (new_vertices[gv] == nullptr) {
            new_vertices[gv] = new MVertex(pt[0],pt[1],pt[2],df);
            dr->addMeshVertex(new_vertices[gv]);
          }
          nvs[lv] = new_vertices[gv];
        }
        dr->tetrahedra.push_back(new MTetrahedron(nvs[0], nvs[1], nvs[2], nvs[3]));
      }
    }

    gm->writeMSH(filename);

    delete gm;

    return true;
  }

  bool exportTetMeshToFile(
      const BrepMesh& M,  
      /* new geometry after self-intersection repair */
      const SimpleMesh& G, 
      const std::string& filename) {

    GModel* gm = new GModel();
    discreteFace* df = new discreteFace(gm);
    discreteRegion* dr = new discreteRegion(gm);
    gm->add(df);
    gm->add(dr);
    dr->setFace(df,1);

    vector<id> vert_M2G(M.vertices.size(),NO_ID);
    for (size_t i = 0; i < G.origin.size(); ++i) if (G.origin[i] != NO_ID) {
      vert_M2G[G.origin[i]] = i;
    }

    vector<MVertex*> new_vertices(M.vertices.size(),nullptr);
    df->triangles.reserve(G.triangles.size());
    for (size_t i = 0; i < G.triangles.size(); ++i) {
      MVertex* nvs[3];
      for (size_t lv = 0; lv < 3; ++lv) {
        id gv = G.triangles[i][lv]; /* vertex id in G */
        vec3 pt = G.points[gv]; /* position in G */

        if (new_vertices[gv] == nullptr) {
          new_vertices[gv] = new MVertex(pt[0],pt[1],pt[2],df);
          df->addMeshVertex(new_vertices[gv]);
        }
        nvs[lv] = new_vertices[gv];
      }
      df->triangles.push_back(new MTriangle(nvs[0], nvs[1], nvs[2]));
    }

    for (size_t i = 0; i < G.tets.size(); ++i) {
      MVertex* nvs[4];
      for (size_t lv = 0; lv < 4; ++lv) {
        id gv = G.tets[i][lv];
        vec3 pt = G.points[gv]; /* position in G */
        if (new_vertices[gv] == nullptr) {
          new_vertices[gv] = new MVertex(pt[0],pt[1],pt[2],df);
          dr->addMeshVertex(new_vertices[gv]);
        }
        nvs[lv] = new_vertices[gv];
      }
      dr->tetrahedra.push_back(new MTetrahedron(nvs[0], nvs[1], nvs[2], nvs[3]));
    }

    gm->writeMSH(filename);

    delete gm;

    return true;
  }


  double quadMeshAverageEdgeSize(const BrepMesh& M, const std::vector<id>& quadFaces) {
    double avg = 0.;
    double sum = 0.;
    vector<id> fvert;
    for (id f: quadFaces) {
      face_vertices(M, f, fvert);
      F(le,4) {
        avg += length(M.vertices[fvert[(le+1)%4]].pt - M.vertices[fvert[le]].pt);
        sum += 1.;
      }
    }
    if (sum == 0.) return DBL_MAX;
    return avg/sum;
  }

  bool fillInteriorWithExternalHxt(
      /* All-hex boundary layer */
      const BrepMesh& M,  
      const std::vector<id>& quadFaces,
      /* Tet mesh after self-intersection repair */
      SimpleMesh& G) {

    const std::string& path = "/tmp/iquads.msh";
    Msg::Warning("Export interior quad mesh (%li elements) to '%s'",quadFaces.size(), path.c_str());
    exportQuadAndTetMeshToFile(M, quadFaces, G, path, false);

    const std::string& path_simplex = "/tmp/itristets.msh";
    Msg::Warning("Export interior tri/tet mesh (%li/%li elements) to '%s'",G.triangles.size(), G.tets.size(), path_simplex.c_str());
    exportTetMeshToFile(M, G, path_simplex);

    const std::string trianglesAndPts = "finalmesh.msh";
    const std::string ffa_tets = "/tmp/tets.msh";
    const std::string hextet = "/tmp/hextet.msh";

    double target_size = quadMeshAverageEdgeSize(M, quadFaces);

    { // Tet mesh -> frame field -> volume point generation
      if(!StatFile(trianglesAndPts.c_str())) {
        std::string rmfile = "rm " + trianglesAndPts;
        Msg::Warning("system call: %s", rmfile.c_str());
        system(rmfile.c_str());
      }
      std::string cmd = "/home/maxence/dev/hxt/build/bin/hxtPointGenerationClean";
      cmd += " --lines 0 --surfaces 0 -3 -d 1";
      cmd += " -s " + std::to_string(target_size);
      cmd += " -q 0";
      cmd += " -Q " + path;
      cmd += " -v 2";
      cmd += " " + path_simplex;
      Msg::Warning("system call: %s", cmd.c_str());
      system(cmd.c_str());

      if(StatFile(trianglesAndPts.c_str())) {
        Msg::Error("file not found: %s", trianglesAndPts.c_str());
        return false;
      }
    }

    { // Frame-field aligned tet meshing
      std::string cmd = "/home/maxence/dev/hxt/build/bin/hxtMesh3d";
      // cmd += " -n -N"; // no-refinement and no-improvement
      cmd += " --no-refinement --aspect-ratio-min=0.1"; 
      cmd += " " + trianglesAndPts;
      cmd += " " + ffa_tets;
      Msg::Warning("system call: %s", cmd.c_str());
      system(cmd.c_str());
      if(StatFile(ffa_tets.c_str())) {
        Msg::Error("file not found: %s", ffa_tets.c_str());
        return false;
      }
    }

    bool useBin = false;
    if (useBin) { // Bipartite labelling of vertices (from quad mesh)
      std::string cmd = "/home/maxence/dev/hxt/build/bin/hxtSurfaceQuadInfo";
      cmd += " " + path;
      cmd += " -B";
      cmd += " -X " + ffa_tets;
      Msg::Warning("system call: %s", cmd.c_str());
      system(cmd.c_str());

      std::string binInput = "binInput.txt";
      if(StatFile(binInput.c_str())) {
        Msg::Warning("file not found: %s", binInput.c_str());
        useBin = false;
      }
    }

    { // Combine
      std::string cmd = "/home/maxence/dev/hxt/build/bin/combine_tetrahedra";
      cmd += " --no-prism --no-pyramid";
      cmd += " " + ffa_tets;
      cmd += " " + hextet;
      if (useBin) {
        cmd += " -b binInput.txt";
      }
      Msg::Warning("system call: %s", cmd.c_str());
      system(cmd.c_str());
      if(StatFile(hextet.c_str())) {
        Msg::Error("file not found: %s", ffa_tets.c_str());
        return false;
      }
    }

    // TODO FIXME losing conformity at boundary layer interface !!
    SimpleMesh& Hd = G;
    Hd.points.clear();
    Hd.origin.clear();
    Hd.triangles.clear();
    Hd.tets.clear();
    Hd.hexahedra.clear();

    { // Load hextet mesh
      GModel* gm = new GModel();
      gm->readMSH(hextet.c_str());
      unordered_map<MVertex*,id> v2id;
      for (GRegion* gr: gm->getRegions()) {
        for (MTetrahedron* elt: gr->tetrahedra) {
          id4 tet;
          for (size_t lv = 0; lv < elt->getNumVertices(); ++lv) {
            MVertex* v = elt->getVertex(lv);
            auto it = v2id.find(v);
            if (it == v2id.end()) {
              vec3 p = v->point();
              v2id[v] = Hd.points.size();
              tet[lv] = Hd.points.size();
              Hd.points.push_back(p);
              Hd.origin.push_back(NO_ID);
            } else {
              tet[lv] = it->second;
            }
          }
          Hd.tets.push_back(tet);
        }
        for (MHexahedron* elt: gr->hexahedra) {
          id8 hex;
          for (size_t lv = 0; lv < elt->getNumVertices(); ++lv) {
            MVertex* v = elt->getVertex(lv);
            auto it = v2id.find(v);
            if (it == v2id.end()) {
              vec3 p = v->point();
              v2id[v] = Hd.points.size();
              hex[lv] = Hd.points.size();
              Hd.points.push_back(p);
              Hd.origin.push_back(NO_ID);
            } else {
              hex[lv] = it->second;
            }
          }
          Hd.hexahedra.push_back(hex);
        }
      }

      delete gm;
    }

    return true;
  }

  double random_double(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
  }

  bool buildInteriorHexdomMesh(
      const HblOptions& opt,
      HblOutput& output) {

    std::vector<std::vector<id> > quadMeshFaces;
    bool okq = extract_interior_quad_meshes(output.H, output.h2q, quadMeshFaces);
    RFC(!okq, "failed to extract interior quad meshes");

    if (opt.debug && opt.viz) {
      for (auto& a: quadMeshFaces) visualization_show_faces(output.H, a, "int_quads_init");
    }

    bool tetRefine = true;
    bool tetOptimize = true;

    for (size_t i = 0; i < quadMeshFaces.size(); ++i) {
      std::vector<id3> tris;
      bool okt = explicit_triangles_from_quad_faces(output.H, quadMeshFaces[i], tris);
      RFC(!okt, "failed to get triangles from quads");

      SimpleMesh M;
      bool oki = initMeshTriangulation(output.H, tris, M);
      RFC(!oki, "failed to initialize simplex mesh");

      // Warning / note:
      // sometime perturbation is required or tet meshing boundary recovery is going in infinite loop ...
      const bool perturbation = false;
      if (perturbation) {
        Msg::Warning("TetGen boundary recovery stuck, special perturbation ...");
        double eps = 1.e-4 * bboxDiag(M.points);
        F(v,M.points.size()) {
          M.points[v][0] += random_double(-eps,eps);
          M.points[v][1] += random_double(-eps,eps);
          M.points[v][2] += random_double(-eps,eps);
        }
      }

      bool okg = generateConstrainedTetMesh(M, tetRefine, tetOptimize);
      if (!okg) {
        Msg::Warning("failed to generate constrained tet mesh ... self-intersections ?");
      }
      if (okg) {
        output.stats.nbSelfIntersectionInitial = 0;
        output.stats.nbSelfIntersectionFixed = 0;
        output.stats.interiorTetMeshingInitial = 1;
        output.stats.interiorTetMeshingFixed = 1;
      }

      if (!okg) { // Probably self-intersections on the boundary, check and fix it
        std::vector<id2> triIntersections;
        bool noInter = checkBoundarySelfIntersections(M, triIntersections);

        size_t nbInterInit = triIntersections.size();
        output.stats.nbSelfIntersectionInitial = triIntersections.size();

        if (!noInter) {
          // Try to decrease boundary layer thickness, check if less intersections
          BrepMesh H_backup = output.H;

          double factor = 0.25; // TODOMX testing

          Msg::Info("Decrease boundary thickness by a factor %.3f", factor);
          decreaseBoundaryLayerThickness(output.H, output.h2q, factor);

          oki = initMeshTriangulation(output.H, tris, M);
          RFC(!oki, "failed to initialize simplex mesh");

          std::vector<id2> triIntersections2;
          noInter = checkBoundarySelfIntersections(M, triIntersections2);
          size_t nbInterAfter = triIntersections2.size();

          if (nbInterAfter > nbInterInit) {
            Msg::Info("Decreasing boundary layer thickness increased number of self-intersections, recover initial geometry");
            output.H = H_backup;
            oki = initMeshTriangulation(output.H, tris, M);
            RFC(!oki, "failed to initialize simplex mesh");
          } else {
            triIntersections = triIntersections2;
          }


          // Fix self-intersections by local surface smoothing
          if (triIntersections.size() > 0) {
            fixSelfIntersections(M, triIntersections);
            triIntersections.clear();
            noInter = checkBoundarySelfIntersections(M, triIntersections);
            if (triIntersections.size() > 0) {
              Msg::Warning("still %li self-intersections after fix, cannot tet mesh ...", triIntersections.size());
            }
          }

          output.stats.nbSelfIntersectionFixed = triIntersections.size();

          if (true || noInter) {
            okg = generateConstrainedTetMesh(M, tetRefine, tetOptimize);
            if (!okg) {
              Msg::Warning("failed to generate constrained tet mesh after self-intersections, bad bad ...");
            }
            if (okg) {
              output.stats.interiorTetMeshingFixed = 1;
            }
          }
        }
      }

      const bool USE_EXTERNAL_HXT = false;
      if (okg && USE_EXTERNAL_HXT) {
        const std::string& path = "interior_quad_bdr.msh";
        Msg::Warning("Export interior quad mesh (%li elements) to '%s'",quadMeshFaces[i].size(), path.c_str());
        exportQuadAndTetMeshToFile(output.H, quadMeshFaces[i], M, path);

        const std::string& path_simplex = "interior_tris_tets.msh";
        Msg::Warning("Export interior tri/tet mesh (%li/%li elements) to '%s'",M.triangles.size(), M.tets.size(), path_simplex.c_str());
        exportTetMeshToFile(output.H, M, path_simplex);

        fillInteriorWithExternalHxt(output.H, quadMeshFaces[i], M);
      }

      if (okg) {
        Msg::Info("Transfer %i tets and %li hexes to output", M.tets.size(), M.hexahedra.size());
        bool oktr = transferSimpleMeshToOutput(M, output);
        RFC(!oktr, "failed to transfer tets/hexes to output");
      }
    }

    return true;
  }
}


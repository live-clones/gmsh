// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <iostream>
#include "meshQuadQuasiStructured.h"
#include "meshGFace.h"
#include "GmshMessage.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "GmshConfig.h"
#include "Context.h"
#include "Options.h"
#include "fastScaledCrossField.h"

#include "meshRefine.h"
#include "Generator.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Field.h"
#include "geolog.h"
#include "gmsh.h"
#include <queue>

#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;


namespace QSQ {
  using vec3 = std::array<double,3>;

  template<class T> 
    void sort_unique(std::vector<T>& vec) {
      std::sort( vec.begin(), vec.end() );
      vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
    }

  template<class T1, class T2> 
  T2 sort_unique_with_perm(
        const std::vector<T1>& in, 
        std::vector<T1>& uniques,
        std::vector<T2>& old2new) {

      std::vector<T2> ids(in.size());
      for(T2 k = 0; k != in.size(); ++k) ids[k]=k;

      std::sort(ids.begin(), ids.end(), 
          [&in](const T2& a, const T2&b){ return (in[a] < in[b]); }
          );

      uniques.resize(in.size());
      old2new.resize(in.size());
      for(T2 k = 0; k != in.size(); ++k) uniques[k]=in[k];

      std::sort(uniques.begin(), uniques.end());
      uniques.erase( std::unique(uniques.begin(), uniques.end()), 
          uniques.end());
      T2 ic = 0; // indice current
      T2 ir = 0; // indice representant
      T2 cur_rep = 0; // indice of current representant
      while(ic < in.size()){
        ic = ir;
        while(ic < in.size() && in[ids[ic]]==in[ids[ir]]){
          old2new[ids[ic]] = cur_rep;
          ++ic;
        }
        ir = ic;
        ++cur_rep;
      }
      return (T2) uniques.size();
  }


  std::vector<GFace*> model_faces(GModel* gm) {
    std::vector<GFace*> faces;
    for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
      faces.push_back(*it);
    }
    return faces;
  }

  std::vector<GEdge*> model_edges(GModel* gm) {
    std::vector<GEdge*> edges;
    std::vector<GFace*> faces = model_faces(gm);
    for (GFace* gf: faces) {
      for (GEdge* ge: gf->edges()) {
        edges.push_back(ge);
      }
      for (GEdge* ge: gf->embeddedEdges()) {
        edges.push_back(ge);

      }
    }
    sort_unique(edges);
    return edges;
  }


  inline void normalize_accurate(SVector3& a) {
    double amp = std::abs(a.data()[0]);
    amp = std::max(amp,std::abs(a.data()[1]));
    amp = std::max(amp,std::abs(a.data()[2]));
    if (amp == 0.) {
      Msg::Error("cannot normalize vector whose length is strictly 0 !");
      return ;
    }
    a = amp * a;
    a.normalize();
  }


  inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }

  inline double angleVectors(SVector3 a, SVector3 b) {
    if (a.normSq() == 0. || b.normSq() == 0.) return DBL_MAX;
    normalize_accurate(a);
    normalize_accurate(b);
    return acos(clamp(dot(a,b),-1.,1.)); 
  }

  int computeFaceCornerAngles(const std::vector<GFace*>& faces, std::map<std::array<int,2>,double>& surfCornerAngle) {
    surfCornerAngle.clear();

    for (GFace* gf: faces) {
      if (gf->triangles.size() == 0) {
        int algo = gf->getMeshingAlgo();
        gf->setMeshingAlgo(ALGO_2D_FRONTAL);
        meshGFace mesher;
        mesher(gf);
        if (gf->triangles.size() == 0) {
          Msg::Error("failed to compute triangulated mesh for surface with tag %i", gf->tag());
          return -1;
        }
        gf->setMeshingAlgo(algo);
      }
      for (MTriangle* t: gf->triangles) {
        for (size_t lv = 0; lv < 3; ++lv) {
          MVertex* v = t->getVertex(lv);
          GVertex* gv = v->onWhat()->cast2Vertex();
          if (gv != nullptr) {
            MVertex* vPrev = t->getVertex((3+lv-1)%3);
            MVertex* vNext = t->getVertex((lv+1)%3);
            SVector3 pNext = vNext->point();
            SVector3 pPrev = vPrev->point();
            SVector3 pCurr = v->point();
            double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
            array<int,2> surfCorner = {gf->tag(),gv->tag()};
            surfCornerAngle[surfCorner] += agl;
          }
        }

      }
    }

    return 0;
  }

  bool surfaceContourIsManifold(GFace* gf) {
    std::map<GVertex*,std::set<GEdge*> > v2e;
    for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
      v2e[gv].insert(ge);
    }
    for (const auto& kv : v2e) {
      if (kv.second.size() > 2) {
        return false;
      }
    }
    return true;
  }

  int surfaceEulerCharacteristicDiscrete(GFace* gf) {
    if (gf->triangles.size() == 0) {
      Msg::Error("no triangulation for face %i, cannot compute discrete Euler characteristic", gf->tag());
      return std::numeric_limits<int>::max();
    }
    vector<size_t> vertices;
    vector<array<size_t,2> > edges;
    vertices.reserve(3*gf->triangles.size());
    edges.reserve(3*gf->triangles.size());
    for (MTriangle* t: gf->triangles) {
      for (size_t lv = 0; lv < 3; ++lv) {
        size_t v1 = t->getVertex(lv)->getNum();
        size_t v2 = t->getVertex((lv+1)%3)->getNum();
        array<size_t,2> vPair = {v1,v2};
        if (v1 > v2) vPair = {v2,v1};
        edges.push_back(vPair);
        vertices.push_back(v1);
      }
    }
    sort_unique(vertices);
    sort_unique(edges);
    int S = gf->triangles.size();
    int E = edges.size();
    int V = vertices.size();
    return V - E + S;
  }

  std::vector<GVertex*> face_corners(GFace* gf) {
    vector<GVertex*> corners;
    for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
      corners.push_back(gv);
    }
    sort_unique(corners);
    return corners;
  }

  /* discrete topological relations between irregular vertices:
   *   n_val5 + n_val3 = 4 \chi + m_val1 - m_val3  - 2 m_val4 */
  int sumNbInteriorIrregularVerticesValence3And5(GFace* gf,
      const std::map<std::array<int,2>,double>& surfCornerAngle) {

    int chi = surfaceEulerCharacteristicDiscrete(gf);
    vector<GVertex*> corners = face_corners(gf);

    int m_val1 = 0;
    int m_val2 = 0;
    int m_val3 = 0;
    int m_val4 = 0;
    for (GVertex* gv: corners) {
      array<int,2> query = {gf->tag(),gv->tag()};
      auto it = surfCornerAngle.find(query);
      if (it == surfCornerAngle.end()) {
        Msg::Error("failed to find (surf=%i,node=%i) in surfCornerAngle", query[0], query[1]);
        return std::numeric_limits<int>::max();
      }
      double angle_deg = 180. / M_PI * it->second;
      if (angle_deg < 90. + 45.) {
        m_val1 += 1;
      } else if (angle_deg < 180. + 45.) {
        m_val2 += 1;
      } else if (angle_deg < 270. + 45.) {
        m_val3 += 1;
      } else if (angle_deg < 360.) {
        m_val4 += 1;
      } else {
        Msg::Error("weird angle, corner (surf=%i,node=%i), angle = %f deg", query[0], query[1], angle_deg);
        return std::numeric_limits<int>::max();
      }
    }

    return 4*chi + m_val1 - m_val3 - 2 * m_val4;
  }

  constexpr size_t NO_ID = std::numeric_limits<size_t>::max();

  /************************************/
  /***** Half edge data structure *****/
  /************************************/
  struct HalfEdge {
    /* Indices of other half-edges */
    size_t prev;
    size_t next;
    size_t opposite;
    /* Indices of other mesh entities */
    size_t vertex;
    size_t face;
  };

  struct Vertex {
    size_t he; /* reference to one half edge */
    SVector3 p; /* coordinates */
    bool isSingularity; /* singularities are irregular vertices to be preserved */
    size_t num; /* unique global identifier in gmsh */
  };

  struct Face {
    size_t he; /* reference to one half edge of the face */
  };

  struct MeshHalfEdges {
    std::vector<Vertex> vertices;
    std::vector<HalfEdge> hedges;
    std::vector<Face> faces;

    inline size_t next(size_t he) const {return hedges[he].next; }
    inline size_t opposite(size_t he) const {return hedges[he].opposite; }
    inline size_t prev(size_t he) const {return hedges[he].prev; }

    int vertexFaceValence(size_t v, bool& onBoundary) const {
      onBoundary = false;
      int valence = 0;
      size_t he_bdr = NO_ID;
      size_t he = vertices[v].he;
      do { /* turn around vertex v */
        size_t cand = opposite(next(he));
        if (cand == NO_ID) {
          he_bdr = next(he);
          break;
        }
        he = cand;
        valence += 1;
      } while (he != vertices[v].he);

      if (he_bdr == NO_ID) return valence;

      /* Boundary case, unroll from he_bdr */
      onBoundary = true;
      valence = 0;
      he = he_bdr;
      do { /* turn around vertex v */
        he = opposite(next(he));
        valence += 1;
      } while (he != vertices[v].he && he != NO_ID);
      return valence;
    }

  };
  /************************************/
  /************************************/

  struct size_t2hash {
    size_t operator()(std::array<size_t,2> p) const noexcept {
      return size_t(p[0]) << 32 | p[1];
    }
  };

  inline std::array<double,3> convert(const SVector3& vec) {
    return {vec.data()[0],vec.data()[1],vec.data()[2]};
  }

  inline std::vector<std::array<double,3> > convert(const std::vector<SVector3>& vecs) {
    std::vector<std::array<double,3> > vecs2(vecs.size());
    for (size_t i = 0; i < vecs2.size(); ++i) vecs2[i] = convert(vecs[i]);
    return vecs2;
  }

  void geolog_halfedge(MeshHalfEdges& M, size_t he, double value, const std::string& viewName) {
    size_t v1 = M.hedges[M.hedges[he].prev].vertex;
    size_t v2 = M.hedges[he].vertex;
    SVector3 p1 = M.vertices[v1].p;
    SVector3 p2 = M.vertices[v2].p;
    /* line */
    vector<vec3> pts = {p1,p2};
    GeoLog::add(pts, value , viewName);
  }

  int createMeshHalfEdges(GFace* gf, MeshHalfEdges& M, const std::vector<size_t>& singularNodes) {
    vector<size_t> numToHVertex(gf->triangles.size(), NO_ID);
    M.vertices.reserve(numToHVertex.size());
    M.hedges.reserve(4*gf->triangles.size());
    M.faces.reserve(gf->triangles.size());

    for (MQuadrangle* q: gf->quadrangles) {
      /* Create vertices if necessary */
      size_t quad[4];
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v1 = q->getVertex(le);
        size_t num = v1->getNum();
        if (num >= numToHVertex.size()) numToHVertex.resize(num+1, NO_ID);
        size_t nv = numToHVertex[num];
        if (nv == NO_ID) {
          nv = M.vertices.size();
          M.vertices.resize(nv+1);
          numToHVertex[num] = nv;
          M.vertices[nv].p = v1->point();
          M.vertices[nv].he = NO_ID;
          M.vertices[nv].num = num;
          M.vertices[nv].isSingularity = false;
        }
        quad[le] = nv;
      }
      /* Create half-edges */
      size_t faceNo = M.faces.size();
      size_t he0 = M.hedges.size();
      M.hedges.resize(he0+4);
      for (size_t k = 0; k < 4; ++k) {
        M.hedges[he0+k].face = faceNo;
        M.hedges[he0+k].opposite = NO_ID; /* later */
        M.hedges[he0+k].vertex = quad[(1+k)%4];
        if (M.vertices[quad[(1+k)%4]].he == NO_ID) {
          M.vertices[quad[(1+k)%4]].he = he0+k;
        }
        /* next */
        if (k != 3) {
          M.hedges[he0+k].next = he0+k+1;
        } else {
          M.hedges[he0+k].next = he0;
        }
        /* prev */
        if (k != 0) {
          M.hedges[he0+k].prev = he0+k-1;
        } else {
          M.hedges[he0+k].prev = he0+3;
        }
      }
      /* Create face */
      M.faces.resize(faceNo+1);
      M.faces[faceNo].he = he0;
    }

    /* Connectivity */
    vector<array<size_t,2> > vPairs(M.hedges.size());
    for (size_t i = 0; i < M.hedges.size(); ++i) {
      size_t v1 = M.hedges[M.hedges[i].prev].vertex;
      size_t v2 = M.hedges[i].vertex;
      array<size_t,2> vPair = {v1,v2};
      if (v1 > v2) vPair = {v2,v1};
      vPairs[i] = vPair;
    }
    vector<size_t> old2new;
    vector<array<size_t,2> > uniques;
    sort_unique_with_perm(vPairs, uniques, old2new);
    vector<array<size_t,2>> new2old(uniques.size(),{NO_ID,NO_ID});
    for (size_t i = 0; i < M.hedges.size(); ++i) {
      size_t ni = old2new[i];
      if (new2old[ni][0] == NO_ID) {
        new2old[ni][0] = i;
      } else if (new2old[ni][1] == NO_ID) {
        new2old[ni][1] = i;
      } else {
        Msg::Error("non manifold quad mesh (face with tag %i), cannot build half edge datastructure", gf->tag());
        return -1;
      }
    }
    for (size_t i = 0; i < uniques.size(); ++i) {
      size_t h1 = new2old[i][0];
      size_t h2 = new2old[i][1];
      if (h1 != NO_ID && h2 != NO_ID) {
        M.hedges[h1].opposite = h2;
        M.hedges[h2].opposite = h1;
      }
    }

    if (singularNodes.size()) {
      for (size_t v: singularNodes) {
        M.vertices[numToHVertex[v]].isSingularity = true;
      }
    }

    // for (size_t i = 0; i < M.hedges.size(); ++i) {
    //   geolog_halfedge(M, i, double(i), "hedges_f"+std::to_string(gf->tag()));
    // }
    // GeoLog::flush();

    return 0;
  }

  int generatePathFromIrregularVerticesToSingularities(
      const MeshHalfEdges& M,
      std::vector<std::vector<size_t> >& hePathes) {
    Msg::Info("generatePathFromIrregularVerticesToSingularities ...");

    using std::priority_queue;
    using std::pair;

    hePathes.clear();

    /* Flag non-singularity irregular vertices */
    vector<int> vIsTarget(M.vertices.size(),false);
    size_t Ntarget = 0;
    for (size_t v = 0; v < M.vertices.size(); ++v) {
      if (M.vertices[v].isSingularity) continue;
      bool onBdr = false;
      int valence = M.vertexFaceValence(v,onBdr);
      if (!onBdr && valence != 4) {
        vIsTarget[v] = true;
        Ntarget += 1;
        GeoLog::add(M.vertices[v].p,0.,"targets");
      }
    }
    Msg::Info("- %li targets", Ntarget);
    if (Ntarget == 0) return 0;


    /* Dijkstra algorithm, starting from singularities */
    vector<double> dist(M.vertices.size(),DBL_MAX);
    vector<size_t> prev(M.vertices.size(),NO_ID);
    priority_queue<pair<double,size_t>,  vector<pair<double,size_t> >,  std::greater<pair<double,size_t> > > Q; 

    /* Init */
    for (size_t i = 0; i < M.vertices.size(); ++i) if (M.vertices[i].isSingularity) {
      dist[i] = 0.;
      Q.push({dist[i],i});
      GeoLog::add(M.vertices[i].p,0.,"sources");
    }

    Msg::Info("- %li sources", Q.size());
    if (Q.size() == 0) {
      Msg::Info("no flagged singularities in patch");
      return 0;
    }

    /* Dijkstra propagation */
    while (Q.size() > 0) {
      size_t v = Q.top().second;
      Q.pop();

      bool reachedBoundary = false;
      size_t he = M.vertices[v].he;
      do { /* turn around vertex v */
        size_t v2 = M.hedges[M.prev(he)].vertex;

        double w_ij = (M.vertices[v].p - M.vertices[v2].p).norm();
        if (dist[v] + w_ij < dist[v2]) {
          dist[v2] = dist[v] + w_ij;
          Q.push({dist[v2],v2});
          prev[v2] = v;
        }

        he = M.opposite(M.next(he));
        if (he == NO_ID) reachedBoundary = true;
      } while (he != M.vertices[v].he && he != NO_ID);

      if (reachedBoundary) { /* turn in the other direction */
        he = M.vertices[v].he;
        do {
          size_t v2 = M.hedges[M.prev(he)].vertex;

          double w_ij = (M.vertices[v].p - M.vertices[v2].p).norm();
          if (dist[v] + w_ij < dist[v2]) {
            dist[v2] = dist[v] + w_ij;
            Q.push({dist[v2],v2});
            prev[v2] = v;
          }

          size_t he_op = M.opposite(he);
          if (he_op == NO_ID) break;
          he = M.prev(he_op);
        } while (he != M.vertices[v].he && he != NO_ID);
      }
    }

    /* Unroll path of irregular vertices */
    std::string name = "pathes";
    vector<vector<size_t> > pathes;
    for (size_t i = 0; i < M.vertices.size(); ++i) {
      if (!vIsTarget[i]) continue;
      vector<size_t> path;
      size_t v = i;
      while (v != NO_ID) {
        path.push_back(v);
        v = prev[v];
      }
      if (!M.vertices[path.back()].isSingularity) {
        Msg::Info("weird, final vertex is not singularity");
        continue;
      }
      Msg::Info("start %li -> path with %li vertices", i, path.size());

      if (path.size() >= 2) {
        pathes.push_back(path);
        GeoLog::add(M.vertices[path[0]].p,0.,name);
        GeoLog::add(M.vertices[path.back()].p,1.,name);
        for (size_t j = 0; j < path.size()-1; ++j) {
          size_t v1 = path[j];
          size_t v2 = path[j+1];
          vec3 p1 = M.vertices[v1].p;
          vec3 p2 = M.vertices[v2].p;
          GeoLog::add({p1,p2},double(j),name);
        }
      }
    }
    Msg::Info("=> %li pathes", pathes.size());

    GeoLog::flush();

    return 0;
  }



}

using namespace QSQ;

int setQuadCoherentCurveTransfiniteConstraints(const std::vector<GFace*>& faces) 
{
  Msg::Debug("mesh %li faces with quad integer constraint solver ...", faces.size());
  std::map<std::array<int,2>,double> surfCornerAngle;
  int s1 = computeFaceCornerAngles(faces, surfCornerAngle);
  if (s1 != 0) {
    Msg::Error("failed to compute face corner angles");
    return s1;
  }

  for (GFace* gf: faces) {
    if (!surfaceContourIsManifold(gf)) {
      Msg::Info("surface %i contour is not manifold, ignore it", gf->tag());
      continue;
    }
  }

  return 0;
}

int generateInitialTriangulation(GModel* gm) {
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_FRONTAL);

  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  CTX::instance()->lock = 0;
  GenerateMesh(gm, 2);
  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;

  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);
  return 0;
}

size_t numberOfTriangles(GModel* gm) {
  size_t N = 0;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    N += (*it)->triangles.size();
  }
  return N;
}

int computeScaledCrossField(GModel* gm, std::vector<std::array<double,4> >& singularities) {
  int viewTag = -1;
  int targetNumberOfQuads = 0.5*numberOfTriangles(gm);
  // FIXME: scaling the number of quads break something ! the number of points
  //        on curves are not scaled with the background field
  // targetNumberOfQuads *= 0.25; /* because of future midpoint subdivision */
  Msg::Warning("target number of quads not divided by 4 because of incoherencies between curves/surfaces mesh");
  int nbDiffusionLevels = 7;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;
  std::string name = "scaled_cross_field";
  {
    PView* view_s = PView::getViewByName(name);
    if (view_s) {
      viewTag = view_s->getTag();
    }
  }
  singularities.clear();
  int verbosity = 1;
  int st = computeScaledCrossFieldView(gm, viewTag, targetNumberOfQuads, 
      nbDiffusionLevels, thresholdNormConvergence, nbBoundaryExtensionLayer, 
      name, verbosity, &singularities);
  if (st == 0) {
    gm->getFields()->setBackgroundMesh(viewTag);
    // gm->getFields()->initialize(); // required ?
    // PView* view_s = PView::getViewByName(name);
    // if (view_s) view_s->getOptions()->visible = 0;
    for (size_t i = 0; i < singularities.size(); ++i) {
      array<double,3> p = {
        singularities[i][0],
        singularities[i][1],
        singularities[i][2]};
      double index = singularities[i][3];
      GeoLog::add(p,index,"dbg_singularities");
    }
    GeoLog::flush();
  }
  return st;
}

int computeQuadCurveMeshConstraints(GModel* gm) {
  Msg::Warning("-- curve constraints not yet implemented ...");
  return 1;
}

int generateCurve1DMeshes(GModel* gm) {
  computeQuadCurveMeshConstraints(gm);

  /* Remove triangulations */
  std::for_each(gm->firstFace(), gm->lastFace(), deMeshGFace());

  std::vector<GEdge*> edges = model_edges(gm);
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (GEdge* ge: edges) {
    ge->mesh(false);
  }

  return 0;
}

int generateUnstructuredQuadMeshes(GModel* gm) {
  /* Generate quad dominant mesh */

  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS);

  CTX::instance()->mesh.algo2d = ALGO_2D_PACK_PRLGRMS;
  CTX::instance()->lock = 0;

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (GFace* gf: faces) {
    gf->mesh(true);
  }

  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;

  for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);

  /* Subdivide to get full quad */
  RefineMesh(gm, true, true);

  return 0;
}

int improveQuadMeshOfFace(GFace* gf, const std::vector<size_t>& singularNodes) {
  MeshHalfEdges M;
  int st = createMeshHalfEdges(gf, M, singularNodes);
  if (st != 0) {
    Msg::Error("failed to generate half edge datastructure for face with tag %i", gf->tag());
    return st;
  }

  if (singularNodes.size() > 0) {
    gmsh::view::add("--- patch " + std::to_string(gf->tag()));
    std::vector<std::vector<size_t> > hePathes;
    generatePathFromIrregularVerticesToSingularities(M, hePathes);
  }

  return 0;
}

int flagQuadMeshSingularNodes(const std::vector<GFace*> faces,
    const std::vector<std::array<double,4> >& singularities,
    std::vector<std::vector<size_t> >& faceSingularNodes) {
  Msg::Warning("(perf) inefficient flagging of singular mesh vertices, should use kdtree");
  faceSingularNodes.clear();
  faceSingularNodes.resize(faces.size());

  vector<vector<size_t> > faceNodeVal3(faces.size());
  vector<vector<size_t> > faceNodeVal5(faces.size());
  vector<size_t> numValence;
  vector<MVertex*> numVertex;
  for (size_t i = 0; i < faces.size(); ++i) {
    GFace* gf = faces[i];
    numValence.reserve(numValence.size()+gf->quadrangles.size());
    numVertex.reserve(numValence.size()+gf->quadrangles.size());
    vector<size_t> fvert;
    for (MQuadrangle* q: gf->quadrangles) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v = q->getVertex(le);
        if (v->onWhat()->cast2Face() != NULL) {
          size_t num = v->getNum();
          if (num >= numValence.size()) numValence.resize(num+1,0);
          if (num >= numVertex.size()) numVertex.resize(num+1,(MVertex*)NULL);
          numValence[num] += 1;
          numVertex[num] = v;
          fvert.push_back(num);
        }
      }
    }
    sort_unique(fvert);
    for (size_t num: fvert) {
      if (numValence[num] == 3){
        faceNodeVal3[i].push_back(num);
      } else if (numValence[num] == 5){
        faceNodeVal5[i].push_back(num);
      }
    }
  }

  for (size_t k = 0; k < singularities.size(); ++k) {
    SVector3 p(singularities[k][0],singularities[k][1],singularities[k][2]);
    double index = singularities[k][3];
    double dmin = DBL_MAX;
    size_t best = NO_ID;
    size_t face = NO_ID;
    if (index == -1.) { /* valence 5 */
      for (size_t i = 0; i < faces.size(); ++i) {
        for (size_t j = 0; j < faceNodeVal5[i].size(); ++j) {
          size_t num = faceNodeVal5[i][j];
          MVertex* v = numVertex[num];
          double dist = v->point().distance(p.point());
          if (dist < dmin) {
            dmin = dist;
            best = num;
            face = i;
          }
        }
      }
    } else if (index == 1.) { /* valence 3 */
      for (size_t i = 0; i < faces.size(); ++i) {
        for (size_t j = 0; j < faceNodeVal3[i].size(); ++j) {
          size_t num = faceNodeVal3[i][j];
          MVertex* v = numVertex[num];
          double dist = v->point().distance(p.point());
          if (dist < dmin) {
            dmin = dist;
            best = num;
            face = i;
          }
        }
      }
    }
    if (face != NO_ID) {
      faceSingularNodes[face].push_back(best);
      Msg::Info("Singularity %i assigned to face %i, node %i", k, face, best);
    } else {
      Msg::Warning("No node found for singularity %i", k);
    }
  }

  return 0;
}

int improveQuadMeshTopology(GModel* gm, const std::vector<std::array<double,4> >& singularities) {
  vector<GFace*> faces = model_faces(gm);

  std::vector<std::vector<size_t> > faceSingularNodes;
  int stf = flagQuadMeshSingularNodes(faces, singularities, faceSingularNodes);
  if (stf != 0) {
    Msg::Error("failed to flag singular node from floating singularities");
    return stf;
  }

  for (size_t i = 0; i < faces.size(); ++i) {
    GFace* gf = faces[i];
    int st = improveQuadMeshOfFace(gf,faceSingularNodes[i]);
    if (st != 0) {
      Msg::Error("failed to improve quad mesh of face with tag %i", gf->tag());
      continue;
    }
  }
  return 0;
}

int Mesh2DWithQuadQuasiStructured(GModel* gm)
{
  if (CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) {
    return 1;
  }
  std::vector<GFace*> faces;

  Msg::Info("Generate quasi-structured all-quadrilateral mesh ...");

  Msg::Info("[Step 1] Generate initial triangulation ...");
  int s1 = generateInitialTriangulation(gm);
  if (s1 != 0) {
    Msg::Error("failed to generate initial triangulation, abort");
    return s1;
  }

  Msg::Info("[Step 2] Generate scaled cross field ...");
  std::vector<std::array<double,4> > singularities;
  int s2 = computeScaledCrossField(gm, singularities);
  if (s2 != 0) {
    Msg::Error("failed to compute scaled cross field, abort");
    return s2;
  }

  Msg::Info("[Step 3] Generate curve 1D meshes ...");
  int s3 = generateCurve1DMeshes(gm);
  if (s3 != 0) {
    Msg::Warning("failed to generate curve 1D meshes, abort");
    return s3;
  }

  Msg::Info("[Step 4] Generate unstructured quad meshes ...");
  int s4 = generateUnstructuredQuadMeshes(gm);
  if (s4 != 0) {
    Msg::Warning("failed to generate 2D unstructured quad meshes, abort");
    return s4;
  }

  // TODO FIXME: singularities should know the GFace also, 
  // global closest irregular vertex with same index does not work
  Msg::Info("[Step 5] Improve topology of quad mesh ...");
  int s5 = improveQuadMeshTopology(gm, singularities);
  if (s5 != 0) {
    Msg::Warning("failed to improve quad mesh topology, continue");
  }


  return 0;
}

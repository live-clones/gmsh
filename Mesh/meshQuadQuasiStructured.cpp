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
#include "meshWinslow2d.h"
#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing

#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;


namespace QSQ {
  using vec3 = std::array<double,3>;

  template<class T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& values) { 
      os << "[";
      for (size_t i = 0; i < values.size(); ++i) {
        os << values[i];
        if (i != values.size() - 1) {
          os << ", ";
        }
      }
      os << "]";
      return os;
    }

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

  template<class T> 
    void append(std::vector<T>& v1, const std::vector<T>& v2) {
      v1.insert(v1.end(),v2.begin(),v2.end());
    }

  template<class T> 
    std::vector<T> intersection(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(s3));
      return s3;
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
   *  sum3m5 = n_val3 - n_val5 = 4 \chi + m_val3 - m_val1  + 2 m_val4 */
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
    int sum3m5 = 4*chi + m_val3 - m_val1 + 2 * m_val4;
    Msg::Debug("- face %i | 4*chi=%i + m_val1=%i - m_val3=%i - 2 * m_val4=%i = %i", gf->tag(),
        chi, m_val1, m_val3, m_val4, sum3m5);

    return sum3m5;
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
    size_t vertex; /* the one at the tip of the arrow */
    size_t face;
  };

  struct Vertex {
    size_t he; /* reference to one half edge */
    SVector3 p; /* coordinates */
    bool isSingularity; /* singularities are irregular vertices to be preserved */
    MVertex* ptr;
    // size_t num; /* unique global identifier in gmsh */
  };

  struct Face {
    size_t he; /* reference to one half edge of the face */
    MElement* ptr;
    // size_t num; /* unique global identifier in gmsh */
  };

  struct MeshHalfEdges {
    std::vector<Vertex> vertices;
    std::vector<HalfEdge> hedges;
    std::vector<Face> faces;

    inline size_t next(size_t he) const {return hedges[he].next; }
    inline size_t opposite(size_t he) const {return hedges[he].opposite; }
    inline size_t prev(size_t he) const {return hedges[he].prev; }
    inline size_t vertex(size_t he, size_t lv) const {
      return (lv == 0) ? hedges[prev(he)].vertex : hedges[he].vertex;
    }

    std::vector<size_t> face_vertices(size_t f) const {
      size_t he = faces[f].he;
      vector<size_t> vert;
      do {
        vert.push_back(hedges[he].vertex);
        he = hedges[he].next;
      } while (he != faces[f].he);
      return vert;
    }

    int vertexFaceValence(size_t v, bool& onBoundary) const {
      onBoundary = false;
      int valence = 0;
      size_t he_bdr = NO_ID;
      size_t he = vertices[v].he;
      if (he == NO_ID) return 0;
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

    int vertexFaces(size_t v, std::vector<size_t>& faces) const {
      faces.clear();
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
        faces.push_back(hedges[he].face);
        valence += 1;
      } while (he != vertices[v].he);

      if (he_bdr == NO_ID) return valence;

      /* Boundary case, unroll from he_bdr */
      faces.clear();
      valence = 0;
      he = he_bdr;
      do { /* turn around vertex v */
        faces.push_back(hedges[he].face);
        he = opposite(prev(he));
        valence += 1;
      } while (he != vertices[v].he && he != NO_ID);
      return valence;
    }

    /* Warning: for faster performance, but enough memory must be avalaible ! */
    int vertexFaces(size_t v, size_t faces[]) const {
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
        faces[valence] = hedges[he].face;
        valence += 1;
      } while (he != vertices[v].he);

      if (he_bdr == NO_ID) return valence;

      /* Boundary case, unroll from he_bdr */
      valence = 0;
      he = he_bdr;
      do { /* turn around vertex v */
        faces[valence] = hedges[he].face;
        he = opposite(prev(he));
        valence += 1;
      } while (he != vertices[v].he && he != NO_ID);
      return valence;
    }


    int faceAdjacentFaces(size_t f, std::vector<size_t>& afaces) const { 
      afaces.clear();
      size_t he = faces[f].he;
      do {
        if (opposite(he) != NO_ID) {
          afaces.push_back(hedges[opposite(he)].face);
        }
        he = hedges[he].next;
      } while (he != faces[f].he);
      return (int) afaces.size();
    }

    bool vertexIsRegular(size_t v) {
      bool onBdr;
      int val = vertexFaceValence(v,onBdr);
      return (onBdr && val == 2) || (!onBdr && val == 4);
    };

  };
  /************************************/
  /************************************/

  using si2 = std::array<size_t,2>;

  struct si2hash {
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

  void geolog_halfedge(const MeshHalfEdges& M, size_t he, double value, const std::string& viewName) {
    size_t v1 = M.hedges[M.hedges[he].prev].vertex;
    size_t v2 = M.hedges[he].vertex;
    SVector3 p1 = M.vertices[v1].p;
    SVector3 p2 = M.vertices[v2].p;
    /* line */
    vector<vec3> pts = {p1,p2};
    GeoLog::add(pts, value , viewName);
  }

  void geolog_face(const MeshHalfEdges& M, size_t f, double value, const std::string& viewName) {
    vector<size_t> vert = M.face_vertices(f);
    vector<vec3> pts(vert.size());
    for (size_t lv = 0; lv < pts.size(); ++lv) {
      pts[lv] = M.vertices[vert[lv]].p;
    }
    vector<double> values(vert.size(),1.);
    GeoLog::add(pts,values,viewName);
  }

  int createMeshHalfEdges(GFace* gf, MeshHalfEdges& M, const std::vector<size_t>& singularNodes) {
    M.vertices.clear();
    M.hedges.clear();
    M.faces.clear();

    vector<size_t> numToHVertex(gf->quadrangles.size(), NO_ID);
    M.vertices.reserve(numToHVertex.size());
    M.hedges.reserve(4*gf->quadrangles.size());
    M.faces.reserve(gf->quadrangles.size());

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
          M.vertices[nv].ptr = v1;
          // M.vertices[nv].num = num;
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
      // M.faces[faceNo].num = q->getNum();
      M.faces[faceNo].ptr = q;
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
      if (ni >= new2old.size()) {
        Msg::Error("redirection: ni=%li is superior to new2old size %li", ni, new2old.size());
        return -1;
      }
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
        if (v >= numToHVertex.size()) {
          Msg::Error("singular node %i has no associated vertex in half edges mesh (%li vertices)", v, M.vertices.size());
          return -1;
        }
        size_t nv = numToHVertex[v];
        if (nv >= M.vertices.size()) {
          Msg::Error("vertex %i (from singular node with num=%i) not found in half edges vertices (size %i), vertex not in GFace quads ?", nv, v, M.vertices.size());
          return -1;
        }
        M.vertices[numToHVertex[v]].isSingularity = true;
      }
    }

    // for (size_t i = 0; i < M.hedges.size(); ++i) {
    //   geolog_halfedge(M, i, double(i), "hedges_f"+std::to_string(gf->tag()));
    // }
    // GeoLog::flush();

    return 0;
  }

  struct Cavity {
    size_t valence;
    size_t singularity;
    std::unordered_set<size_t> hes;
    std::unordered_set<size_t> faces;

    void removeInteriorHalfEdges(const MeshHalfEdges& M) {
      std::unordered_set<size_t>::iterator it_he = hes.begin();
      while (it_he != hes.end()) {
        size_t he = *it_he;
        size_t he_op = M.opposite(he);
        auto it_op = hes.find(he_op);
        if (it_op != hes.end()) {
          hes.erase(it_op);
          it_he = hes.erase(it_he);
        } else {
          it_he++;
        }
      }
    }

    void addQuads(const MeshHalfEdges& M, const std::vector<size_t>& quads) {
      for (size_t f: quads) {
        faces.insert(f);
        size_t he = M.faces[f].he;
        do {
          hes.insert(he);
          he = M.next(he);
        } while (he != M.faces[f].he);
      }
      removeInteriorHalfEdges(M);
    }
  };

  int convexifyCavity(const MeshHalfEdges& M, Cavity& cav) {
    /* Initialization */
    if (cav.faces.size() == 0) {
      std::vector<size_t> quadToAdd;
      std::unordered_set<size_t> hes0 = cav.hes;
      for (size_t he0 : hes0) {
        size_t he = he0;
        size_t f = M.hedges[he].face;
        quadToAdd.push_back(f);
      }
      sort_unique(quadToAdd);
      cav.addQuads(M, quadToAdd);
    }

    /* Convexify */
    bool remaining = true;
    while (remaining) {
      remaining = false;
      vector<size_t> faces;
      vector<size_t> quadToAdd;
      vector<size_t> cands;
      for (size_t he: cav.hes) {
        size_t v = M.hedges[he].vertex;
        M.vertexFaces(v, faces);
        int count = 0;
        cands.clear();
        for (size_t f: faces) {
          if (cav.faces.find(f) != cav.faces.end()) {
            count += 1;
          } else {
            cands.push_back(f);
          }
        }

        /* Do not grow cavity if other sing inside */
        if (v != cav.singularity && M.vertices[v].isSingularity) {
          return 1;
        }

        /* Concave vertex */
        if (cands.size() == 1) {
          quadToAdd.push_back(cands[0]);
        } else {
          bool onBdr = false;
          if (M.vertexFaceValence(v,onBdr) != 4 && !onBdr) {
            /* Irregular vertex on cavity boundary, put him inside */
            for (size_t f: cands) quadToAdd.push_back(f);
          }
        }

      }
      if (quadToAdd.size() == 0) break;
      remaining = true;
      sort_unique(quadToAdd);

      cav.addQuads(M, quadToAdd);
    }

    return 0;
  }


  int generateCavitiesAroundSingularities(
      const MeshHalfEdges& M,
      std::vector<Cavity>& cavities) 
  {
    Msg::Info("generateCavitiesAroundSingularities ...");

    // TODO: ensure 3-5 pairs are in the same cavity

    using std::priority_queue;
    using std::pair;

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
    std::map<size_t,vector<vector<size_t> > > singularityToPathes;
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
      size_t sing = path.back();
      if (path.size() < 2) {
        Msg::Info("weird, path size: %li", path.size());
        continue;
      }

      if (true) {
        Msg::Info("Vizu | start %li -> path with %li vertices", i, path.size());
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
      singularityToPathes[sing].push_back(path);
    }

    std::unordered_map<si2, size_t, si2hash> vPair2he;
    for (size_t i = 0; i < M.hedges.size(); ++i) {
      size_t v1 = M.hedges[i].vertex;
      size_t v2 = M.hedges[M.prev(i)].vertex;
      si2 vPair = {v1,v2};
      vPair2he[vPair] = i;
    }

    for (const auto& kv: singularityToPathes) {
      size_t sing = kv.first;
      Cavity cav;
      cav.singularity = sing;
      bool onBdr = false;
      cav.valence = M.vertexFaceValence(sing,onBdr);
      for (size_t i = 0; i < kv.second.size(); ++i) {
        const std::vector<size_t>& path = kv.second[i];
        for (size_t j = 0; j < path.size()-1; ++j) {
          size_t v1 = path[j];
          size_t v2 = path[j+1];
          si2 vPair1 = {v1,v2};
          si2 vPair2 = {v2,v1};
          auto it1 = vPair2he.find(vPair1);
          auto it2 = vPair2he.find(vPair2);
          if (it1 != vPair2he.end()) cav.hes.insert(it1->second);
          if (it2 != vPair2he.end()) cav.hes.insert(it2->second);
        }
      }
      cavities.push_back(cav);
      Msg::Info("cavity sing %i, val %i -> %i hedges", sing, cav.valence, cav.hes.size());
    }

    /* Convexify cavities and verify they do not contain
     * other singularities or irregular vertices, and that
     * they do not overlap */
    auto it = cavities.begin();
    while (it != cavities.end()) {
      int status = convexifyCavity(M, *it);
      if (status != 0) {
        it = cavities.erase(it);
      } else {
        it++;
      }
    }

    /* Check overlaps */
    std::vector<size_t> toDel;
    for (size_t i = 0; i < cavities.size(); ++i) {
      for (size_t j = i+1; j < cavities.size(); ++j) {
        for (size_t f: cavities[i].faces) {
          auto it = cavities[j].faces.find(f);
          if (it != cavities[j].faces.end()) {
            toDel.push_back(j);
            break;
          }
        }
      }
    }
    sort_unique(toDel);
    std::reverse(toDel.begin(),toDel.end());
    for (size_t i: toDel) {
      cavities.erase(cavities.begin()+i);
    }

    /* Vizu */
    for (Cavity& cav: cavities) {
      for (size_t f: cav.faces) {
        vector<size_t> vert = M.face_vertices(f);
        vector<vec3> pts(vert.size());
        for (size_t lv = 0; lv < pts.size(); ++lv) {
          pts[lv] = M.vertices[vert[lv]].p;
        }
        vector<double> values(vert.size(),double(f));
        GeoLog::add(pts,values,"cavity_"+std::to_string(cav.singularity));
      }
      for (size_t he: cav.hes) {
        geolog_halfedge(M, he, 0., "cavity_"+std::to_string(cav.singularity));
      }
    }

    GeoLog::flush();

    return 0;
  }

  bool boundaryHalfEdgesFromQuads(const MeshHalfEdges& M, const std::unordered_set<size_t>& quads, 
      std::vector<size_t>& boundary) {
    std::unordered_set<size_t> hes;
    for (size_t f: quads) {
      size_t he = M.faces[f].he;
      do {
        hes.insert(he);
        he = M.next(he);
      } while (he != M.faces[f].he);
    }

    std::unordered_set<size_t>::iterator it_he = hes.begin();
    while (it_he != hes.end()) {
      size_t he = *it_he;
      size_t he_op = M.opposite(he);
      auto it_op = hes.find(he_op);
      if (it_op != hes.end()) {
        hes.erase(it_op);
        it_he = hes.erase(it_he);
      } else {
        it_he++;
      }
    }

    boundary.reserve(hes.size());
    for (size_t he: hes) boundary.push_back(he);

    return true;
  }

  void removeInteriorHalfEdges(const MeshHalfEdges& M, std::vector<size_t>& hes) {
    std::vector<size_t>::iterator it_he = hes.begin();
    while (it_he != hes.end()) {
      size_t he = *it_he;
      size_t he_op = M.opposite(he);
      auto it_op = std::find(hes.begin(),hes.end(), he_op);
      if (it_op != hes.end()) {
        hes.erase(it_op);
        it_he = hes.erase(it_he);
      } else {
        it_he++;
      }
    }
  }

  bool orderedHalfEdgesFromStack(const MeshHalfEdges& M, 
      const std::vector<size_t>& hes_stack, 
      std::vector<size_t>& orderedHes) {
    orderedHes.clear();
    if (hes_stack.size() < 3) {
      Msg::Error("orderedHalfEdgesFromStack: not enough half edges: %li", hes_stack.size());
      return false;
    }
    orderedHes.reserve(hes_stack.size());

    /* Order boundary half edges in sides */
    for (size_t he0: hes_stack) {
      size_t he = he0;
      do {
        size_t v2 = M.vertex(he,1);
        /* Add current half edge to current side */
        orderedHes.push_back(he);

        /* Find next half edge */
        bool found = false;
        for (size_t he2: hes_stack) if (he2 != he && M.vertex(he2,0) == v2) {
          he = he2;
          found = true;
          break;
        }
        if (!found) {
          return false;
        }
      } while (he != he0);
      break;
    }
    return true;
  }

  inline int valenceInsideQuads(const MeshHalfEdges& M, const std::unordered_set<size_t>& quads, size_t v) {
    constexpr size_t BSIZE = 24;
    size_t faces[BSIZE];
    int val = M.vertexFaces(v, faces);
    if ((size_t) val >= BSIZE) {
      Msg::Error("valence is too high (%i) compared to buffer size %li, memory corrupted, abort", val, BSIZE);
      abort();
    }
    int count = 0;
    for (size_t i = 0; i < (size_t) val; ++i) {
      if (quads.find(faces[i]) != quads.end()) count += 1;
    }
    return count;
  }

  inline int valenceOutsideQuads(const MeshHalfEdges& M, const std::unordered_set<size_t>& quads, size_t v) {
    constexpr size_t BSIZE = 24;
    size_t faces[BSIZE];
    int val = M.vertexFaces(v, faces);
    if ((size_t) val >= BSIZE) {
      Msg::Error("valence is too high (%i) compared to buffer size %li, memory corrupted, abort", val, BSIZE);
      abort();
    }
    int count = 0;
    for (size_t i = 0; i < (size_t) val; ++i) {
      if (quads.find(faces[i]) == quads.end()) count += 1;
    }
    return count;
  }

  struct FlipInfo {
    size_t he = NO_ID;
    size_t nq = NO_ID;
    std::array<size_t,4> nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
  };

  struct FCavity {
    /* Data */
    MeshHalfEdges& M;
    std::vector<size_t> hes; /* ordered half edges */
    std::vector<uint8_t> side; /* side associated to each half-edge */
    std::unordered_set<size_t> quads; /* quads inside, unordered_set for queries */


    /* Methods */
    FCavity(MeshHalfEdges& M_) : M(M_) { }

    bool init(const std::vector<size_t>& quadsInit) {
      if (quadsInit.size() < 3) {
        Msg::Error("SCavity init: expecting at least 3 quads, not %li", quadsInit.size());
        return false;
      }
      /* Add quads and collect bdr half edges */
      vector<size_t> hes_stack;
      for (size_t f: quadsInit) {
        quads.insert(f);
        size_t he = M.faces[f].he;
        do {
          hes_stack.push_back(he);
          he = M.next(he);
        } while (he != M.faces[f].he);
      }
      removeInteriorHalfEdges(M, hes_stack);

      bool oks = orderedHalfEdgesFromStack(this->M, hes_stack, this->hes);
      if (!oks) {
        Msg::Error("failed to determine sides from %li boundary half edges (%li quads)", hes_stack.size(), quads.size());
        return false;
      }
      int nsides = updateSides();
      if (nsides <= 0) {
        Msg::Error("should have at least one side, not %i", nsides);
        return false;
      }

      return true;
    }

    bool growByFlip(size_t i, FlipInfo& info, bool rejectNewSings = true) { /* i is index of half edge in hes */
      DBG("growByFlip ...", i, hes.size());
      if (i >= hes.size()) {
        DBG("can't flip because", i, hes.size());
        info.nq = NO_ID;
        return false;
      }
      const size_t he0_op = hes[i];
      const size_t he0 = M.opposite(he0_op);
      if (he0 == NO_ID) {
        DBG("can't flip because", i, hes.size(), he0_op, he0);
        info.nq = NO_ID;
        return false; /* half-edge on bdr */
      }
      info.he = he0_op;
      info.nq = M.hedges[he0].face;
      const size_t he1 = M.hedges[he0].next;
      const size_t he2 = M.hedges[he1].next;
      const size_t he3 = M.hedges[he2].next;
      const size_t he1_op = M.hedges[he1].opposite;
      const size_t he2_op = M.hedges[he2].opposite;
      const size_t he3_op = M.hedges[he3].opposite;
      // const size_t q0 = M.hedges[he0_op].face; /* initial quad inside cavity */
      const size_t q1 = (he1_op != NO_ID) ? M.hedges[he1_op].face: NO_ID;
      const size_t q2 = (he1_op != NO_ID) ? M.hedges[he2_op].face: NO_ID;
      const size_t q3 = (he1_op != NO_ID) ? M.hedges[he3_op].face: NO_ID;
      const bool q1in = (q1 != NO_ID && quads.find(q1) != quads.end());
      const bool q2in = (q2 != NO_ID && quads.find(q2) != quads.end());
      const bool q3in = (q3 != NO_ID && quads.find(q3) != quads.end());
      if        ( q1in &&  q2in && !q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he1,0);
        size_t nv2 = M.vertex(he1,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          DBG("flip -2v rejected because would include singularity", i, info.nq);
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev_prev = (i + hes.size() - 2)%hes.size();
        hes[i_prev_prev] = he3;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        hes.erase(it0);
        auto it1 = std::find(hes.begin(),hes.end(),he1_op);
        hes.erase(it1);
        DBG("flip -2v", i, info.nq);
      } else if ( q1in && !q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he0_op,0);
        size_t nv2 = M.vertex(he0_op,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          DBG("flip -2v rejected because would include singularity", i, info.nq);
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev = (i + hes.size() - 1)%hes.size();
        hes[i_prev] = he2;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        hes.erase(it0);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        DBG("flip -2v", i, info.nq);
      } else if (!q1in &&  q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he3,0);
        size_t nv2 = M.vertex(he3,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          DBG("flip -2v rejected because would include singularity", i, info.nq);
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        hes[i] = he1;
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        DBG("flip -2v", i, info.nq);
      } else if (q1in && q2in && q3in){
        size_t nv0 = M.hedges[he0].vertex;
        size_t nv1 = M.hedges[he0].vertex;
        size_t nv2 = M.hedges[he0].vertex;
        size_t nv3 = M.hedges[he0].vertex;
        if (rejectNewSings && (M.vertices[nv0].isSingularity || M.vertices[nv1].isSingularity
             || M.vertices[nv2].isSingularity || M.vertices[nv3].isSingularity)) {
          DBG("flip closing hole rejected because would include singularity", i, info.nq);
          return false;
        }
        info.nvs = {nv0,nv1,nv2,nv3};
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        hes.erase(it0);
        auto it1 = std::find(hes.begin(),hes.end(),he1_op);
        hes.erase(it1);
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        std::vector<size_t> hes_stack = hes;
        bool oks = orderedHalfEdgesFromStack(this->M, hes_stack, this->hes);
        if (!oks) {
          Msg::Error("failed to determine sides from %li boundary half edges (%li quads)", hes_stack.size(), quads.size());
          info.nq = NO_ID;
          return false;
        }
        DBG("flip closing hole (may be too slow ?)", i, info.nq);
      } else if ( q1in && !q2in && !q3in) { /* same number of vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv = M.hedges[he2].vertex;
        const int val = valenceInsideQuads(M, quads, nv);
        if (val > 0) {
          DBG("no flip <>1v because", i, info.nq, nv, val);
          info.nq = NO_ID;
          return false;
        }
        const size_t nvIn = M.hedges[he0].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);
          info.nq = NO_ID;
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev = (i + hes.size() - 1)%hes.size();
        hes[i_prev] = he2;
        hes[i] = he3;
        DBG("flip <>1v (1)", i, info.nq, nv);
      } else if (!q1in && !q2in &&  q3in) { /* same number of vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv = M.hedges[he1].vertex;
        const int val = valenceInsideQuads(M, quads, nv);
        if (val > 0) {
          DBG("no flip <>1v because", i, info.nq, nv, val);
          info.nq = NO_ID;
          return false;
        }
        const size_t nvIn = M.hedges[he0_op].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);
          info.nq = NO_ID;
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_next = (i + 1)%hes.size();
        hes[i] = he1;
        hes[i_next] = he2;
        DBG("flip <>1v (2)", i, info.nq, nv);
      } else if (!q1in && !q2in && !q3in) { /* two additional vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv1 = M.hedges[he1].vertex;
        const int val1 = valenceInsideQuads(M, quads, nv1);
        if (val1 > 0) {
          DBG("no flip +2v because", i, info.nq, nv1, val1);
          info.nq = NO_ID;
          return false;
        }
        const size_t nv2 = M.hedges[he2].vertex;
        const int val2 = valenceInsideQuads(M, quads, nv2);
        if (val2 > 0) {
          DBG("no flip +2v because", i, info.nq, nv2, val2);
          info.nq = NO_ID;
          return false;
        }
        if (rejectNewSings) {
          const size_t v0 = M.vertex(he0,0);
          if (M.vertices[v0].isSingularity && valenceOutsideQuads(M, quads, v0) == 2) {
            /* Would be concave corner around singularity, reject */
            DBG("no flip +2v because would be concave corner at sing.", i, info.nq);
            return false;
          }
          const size_t v1 = M.vertex(he0,1);
          if (M.vertices[v1].isSingularity && valenceOutsideQuads(M, quads, v1) == 2) {
            /* Would be concave corner around singularity, reject */
            DBG("no flip +2v because would be concave corner at sing.", i, info.nq);
            return false;
          }
        }
        /* Do the flip */
        hes[i] = he1;
        hes.insert(hes.begin()+i+1,{he2,he3});
        DBG("flip +2v", i, info.nq);
      } else {
        DBG("flip config not supported", i, info.nq, he0, he1, he2, he3, q1in, q2in, q3in);
        info.nq = NO_ID;
        return false;
      }
      quads.insert(info.nq);
      return true;
    }

    int updateSides() {
      // DBG("updateSides ...");
      side.resize(hes.size());
      std::unordered_map<size_t,int> val;
      for (size_t f: quads) {
        size_t he = M.faces[f].he;
        for (size_t lv = 0; lv < 4; ++lv) {
          size_t v = M.hedges[he].vertex;
          val[v] += 1;
          he = M.hedges[he].next;
        }
      }

      std::unordered_set<size_t> corners;
      for (const auto& kv: val) {
        if (kv.second == 1) corners.insert(kv.first);
      }

      // DBG(corners);
      int sideNo = -1;
      for (size_t i = 0; i < hes.size(); ++i) {
        const size_t he0 = hes[i];
        const size_t v0 = M.vertex(he0,0);
        if (corners.find(v0) == corners.end()) {
          continue;
        }
        for (size_t j = 0; j < hes.size(); ++j) {
          const size_t he_pos = (i+j)%hes.size();
          const size_t he = hes[he_pos];
          size_t v1 = M.vertex(he,0);
          if (corners.find(v1) != corners.end()) {
            sideNo += 1;
          }
          side[he_pos] = sideNo;
        }
        break;
      }
      // DBG("->",sideNo+1);
      // {
      //   for (size_t i = 0; i < hes.size(); ++i) {
      //     size_t he = hes[i];
      //     size_t v1 = M.vertex(he,0);
      //     size_t v2 = M.vertex(he,1);
      //     SVector3 p1 = M.vertices[v1].p;
      //     SVector3 p2 = M.vertices[v2].p;
      //     std::vector<vec3> pts = {p1,p2};
      //     std::vector<double> vals = {2.*double(i)+0,2*double(i)+1.};
      //     GeoLog::add(pts,vals,"hes");
      //   }
      //   for (size_t c: corners) {
      //     SVector3 p1 = M.vertices[c].p;
      //     GeoLog::add(p1,0.,"corners");
      //   }
      //   GeoLog::flush();
      // }
      return sideNo+1;
    }


  };

  struct Gardener {
    /* Gardener is used to manage the growth of cavities
     * Can be re-used as long as the GFace is not changed */

    /* Data */
    MeshHalfEdges& M;
    vector<int> valence;
    vector<bool> vOnBoundary;
    FCavity* current;
    vector<int> valenceInCavity;
    /* singularities (flagged irregular) strictly inside */
    std::unordered_set<size_t> sings;
    /* singularities (flagged irregular) strictly on the cavity on the cavity boundary */
    std::unordered_set<size_t> singsBdr;
    /* irregular vertices (not sing.) inside, including bdr */
    std::unordered_set<size_t> irregular;

    /* Methods */
    Gardener(MeshHalfEdges& M_) : M(M_), current(NULL) {
      /* Initialize data from MeshHalfEdges */
      valence.resize(M.vertices.size(),0);
      valenceInCavity.resize(M.vertices.size());
      vOnBoundary.resize(M.vertices.size(),false);
      for (size_t i = 0; i < M.faces.size(); ++i) {
        size_t he = M.faces[i].he;
        do {
          size_t v2 = M.hedges[he].vertex;
          valence[v2] += 1;
          if (M.hedges[he].opposite == NO_ID) {
            size_t v1 = M.vertex(he,0);
            if (!vOnBoundary[v1]) vOnBoundary[v1] = true;
            if (!vOnBoundary[v2]) vOnBoundary[v2] = true;
          }
          he = M.next(he);
        } while (he != M.faces[i].he);
      }
    }

    bool setCavity(FCavity& cav) {
      if (cav.quads.size() == 0 || cav.hes.size() == 0) return false;
      current = &cav;
      std::fill(valenceInCavity.begin(),valenceInCavity.end(),0);
      sings.clear();
      irregular.clear();
      std::vector<size_t> asings;
      for (size_t i: cav.quads) {
        size_t he = M.faces[i].he;
        do {
          size_t v2 = M.hedges[he].vertex;
          valenceInCavity[v2] += 1;
          if (M.vertices[v2].isSingularity) {
            asings.push_back(v2);
          } else if (vOnBoundary[v2] && valence[v2] != 2) {
            irregular.insert(v2);
          } else if (!vOnBoundary[v2] && valence[v2] != 4) {
            irregular.insert(v2);
          }
          he = M.next(he);
        } while (he != M.faces[i].he);
      }
      /* Only add singularities if strictly inside */
      sort_unique(asings);
      for (size_t v: asings) if (valenceInCavity[v] == valence[v]) {
        sings.insert(v);
      } else {
        singsBdr.insert(v);
      }
      return true;
    }

    bool isConvex() const {
      if (current == NULL) return false;
      FCavity& cav = *current;
      for (size_t i = 0; i < cav.hes.size(); ++i) {
        size_t he = cav.hes[i];
        size_t v = M.hedges[he].vertex;
        int valOutside = valence[v] - valenceInCavity[v];
        if (valOutside == 1) return false;
      }
      return true;
    }

    void markNewQuad(size_t nq) {
      /* Call this to update the Gardener data when
       * a new quad is added to the current cavity */
      size_t heq = M.faces[nq].he;
      do {
        size_t v2q = M.hedges[heq].vertex;
        valenceInCavity[v2q] += 1;
        if (M.vertices[v2q].isSingularity) {
          if (valenceInCavity[v2q] == valence[v2q]) {
            DBG("new sing inside, bad ! abort", nq, v2q);
            abort();
            sings.insert(v2q);
          } else {
            singsBdr.insert(v2q);
          }
        } else if (vOnBoundary[v2q] && valence[v2q] != 2) {
          irregular.insert(v2q);
        } else if (!vOnBoundary[v2q] && valence[v2q] != 4) {
          irregular.insert(v2q);
        }
        heq = M.next(heq);
      } while (heq != M.faces[nq].he);
    }

    bool convexify() {
      if (current == NULL) return false;
      FCavity& cav = *current;
      bool running = true;
      FlipInfo info;
      while (running) {
        running = false;
        for (size_t i = 0; i < cav.hes.size(); ++i) {
          size_t he = cav.hes[i];
          size_t v1 = M.vertex(he,0);
          size_t v2 = M.vertex(he,1);
          int valOutside1 = valence[v1] - valenceInCavity[v1];
          int valOutside2 = valence[v2] - valenceInCavity[v2];
          if ((!vOnBoundary[v1] &&valOutside1 == 1) || (!vOnBoundary[v2] && valOutside2 == 1)) {
            bool ok = cav.growByFlip(i, info);
            if (ok) {
              running = true;
              markNewQuad(info.nq);
            }
          }
        }
      }
      return true;
    }

    bool growIsotropic(size_t N) {
      if (current == NULL) return false;
      FCavity& cav = *current;
      srand(0);
      bool running = true;
      size_t nb = 0;
      FlipInfo info;
      while (running && nb < N) {
        running = false;
        /* Try random flip (up to hes.size() tries) */
        for (size_t k = 0; k < cav.hes.size(); ++k) {
          size_t i = (rand() % static_cast<size_t>(cav.hes.size()));
          size_t he = cav.hes[i];
          size_t v = M.hedges[he].vertex;
          DBG(nb,N,"---",i,he,v);
          bool ok = cav.growByFlip(i, info);
          if (ok) {
            nb += 1;
            running = true;
            markNewQuad(info.nq);
            break;
          }
        }
      }
      return true;
    }

    bool growMaximal() {
      if (current == NULL) return false;
      FCavity& cav = *current;
      srand(0);
      bool running = true;
      size_t nb = 0;
      FlipInfo info;
      while (running) {
        running = false;
        /* Try random flip (up to hes.size() tries) */
        for (size_t k = 0; k < cav.hes.size(); ++k) {
          size_t i = (rand() % static_cast<size_t>(cav.hes.size()));
          bool ok = cav.growByFlip(i, info, true);
          if (ok) {
            nb += 1;
            running = true;
            markNewQuad(info.nq);
            break;
          }
        }
      }
      return true;
    }

  };

  void geolog_fcavity(const FCavity& cav, const std::string& name) {
    for (size_t i = 0; i < cav.hes.size(); ++i) {
      geolog_halfedge(cav.M, cav.hes[i], double(cav.side[i]), name);
    }
    for (size_t f: cav.quads) {
      geolog_face(cav.M, f, 1., name);
    }
    for (size_t v = 0; v < cav.M.vertices.size(); ++v) if (cav.M.vertices[v].isSingularity) {
      bool b;
      GeoLog::add(cav.M.vertices[v].p, double(cav.M.vertexFaceValence(v, b)), name);
    }
    GeoLog::flush();
  }


  struct SCavity {
    /* Data */
    std::vector<std::vector<size_t> > sides; /* half-edges in M */
    std::unordered_set<size_t> quads; /* quads inside, unordered_set for queries */
    MeshHalfEdges& M;

    /* Methods */
    SCavity(MeshHalfEdges& M_) : M(M_) { }

    int valenceInsideCavity(size_t v) {
      vector<size_t> faces(6);
      M.vertexFaces(v, faces);
      int count = 0;
      for (size_t f: faces) if (quads.find(f) != quads.end()) count += 1;
      return count;
    }

    int valenceOutsideCavity(size_t v) {
      vector<size_t> faces(6);
      M.vertexFaces(v, faces);
      int count = 0;
      for (size_t f: faces) if (quads.find(f) == quads.end()) count += 1;
      return count;
    }

    bool sidesFromBoundaryHalfEdges(const std::vector<size_t>& hes) {
      sides.clear();
      /* Order boundary half edges in sides */
      for (size_t he0: hes) if (valenceInsideCavity(M.vertex(he0,0)) == 1) {
        size_t he = he0;
        vector<size_t>* cur_side = NULL;
        do {
          /* Change side if first vertex of half edge is corner */
          size_t v1 = M.vertex(he,0);
          size_t v2 = M.vertex(he,1);
          if (valenceInsideCavity(v1) == 1) {
            sides.resize(sides.size()+1);
            cur_side = &(sides.back());
          }
          /* Add current half edge to current side */
          cur_side->push_back(he);
          /* Find next half edge */
          bool found = false;
          for (size_t he2: hes) if (he2 != he && M.vertex(he2,0) == v2) {
            he = he2;
            found = true;
            break;
          }
          if (!found) {
            return false;
          }
        } while (he != he0);
        break;
      }
      return sides.size() > 0;
    }

    bool init(const std::vector<size_t>& quadsInit) {
      if (quadsInit.size() < 3) {
        Msg::Error("SCavity init: expecting at least 3 quads, not %li", quadsInit.size());
        return false;
      }
      /* Add quads and collect bdr half edges */
      vector<size_t> hes;
      for (size_t f: quadsInit) {
        quads.insert(f);
        size_t he = M.faces[f].he;
        do {
          hes.push_back(he);
          he = M.next(he);
        } while (he != M.faces[f].he);
      }
      removeInteriorHalfEdges(M, hes);

      bool oks = sidesFromBoundaryHalfEdges(hes);
      if (!oks) {
        Msg::Error("failed to determine sides from %li boundary half edges (%li quads)", hes.size(), quads.size());
        return false;
      }

      return true;
    }
  };


  void geolog_scavity(const SCavity& cav, const std::string& name) {
    for (size_t i = 0; i < cav.sides.size(); ++i) {
      for (size_t he: cav.sides[i]) {
        geolog_halfedge(cav.M, he, double(i), name);
      }
    }
    for (size_t f: cav.quads) {
      geolog_face(cav.M, f, 1., name);
    }
    for (size_t v = 0; v < cav.M.vertices.size(); ++v) if (cav.M.vertices[v].isSingularity) {
      bool b;
      GeoLog::add(cav.M.vertices[v].p, double(cav.M.vertexFaceValence(v, b)), name);
    }
    GeoLog::flush();
  }

  bool convexifyQuads(const MeshHalfEdges& M, std::vector<size_t>& quadsVector) {
    std::unordered_set<size_t> quads;
    std::vector<size_t> hes;
    for (size_t f: quadsVector) quads.insert(f);
    bool okb = boundaryHalfEdgesFromQuads(M, quads, hes);
    if (!okb) {
      Msg::Error("convexify: failed to get boundary half edges from %li quads", quads.size());
      return false;
    }

    bool remaining = true;
    while (remaining) {
      remaining = false;
      vector<size_t> faces;
      vector<size_t> quadToAdd;
      vector<size_t> cands;
      for (size_t he: hes) {
        size_t v = M.hedges[he].vertex;
        M.vertexFaces(v, faces);
        int count = 0;
        cands.clear();
        for (size_t f: faces) {
          if (quads.find(f) != quads.end()) {
            count += 1;
          } else {
            cands.push_back(f);
          }
        }

        /* Do not grow cavity if other sing inside */
        if (M.vertices[v].isSingularity) {
          if (cands.size() == 1 && count == 2) { /* v is singularity but regular from the inside, do not grow */
            continue;
          } else {
            Msg::Info("convexify: vertex %i (num=%i) is singularity, don't grow", v, M.vertices[v].ptr->getNum());
            return false;
          }
        }

        /* Concave vertex */
        if (cands.size() == 1) {
          quadToAdd.push_back(cands[0]);
        } else {
          // bool onBdr = false;
          // if (M.vertexFaceValence(v,onBdr) != 4 && !onBdr) {
          //   /* Irregular vertex on cavity boundary, put him inside */
          //   for (size_t f: cands) {
          //     quadToAdd.push_back(f);
          //   }
          // }
        }
      }
      if (quadToAdd.size() == 0) break;
      remaining = true;
      sort_unique(quadToAdd);

      for (size_t f: quadToAdd) {
        quads.insert(f);
        size_t he = M.faces[f].he;
        do {
          hes.push_back(he);
          he = M.next(he);
        } while (he != M.faces[f].he);
      }
      removeInteriorHalfEdges(M, hes);
    }

    quadsVector.clear();
    quadsVector.reserve(quads.size());
    for (size_t f: quads) quadsVector.push_back(f);

    return true;
  }

  inline bool vertexIsRegular(const std::vector<int>& valence, const std::vector<bool>& onBdr, size_t v) {
    return (onBdr[v] && valence[v] == 2) || (!onBdr[v] && valence[v] == 4);
  };

  bool sideTangentToBoundary(const SCavity& cav, size_t side) {
    for (size_t j = 0; j < cav.sides[side].size(); ++j) {
      size_t he = cav.sides[side][j];
      if (cav.M.opposite(he) == NO_ID) {
        return true;
      }
    }
    return false;
  }

  bool growRegularSide(SCavity& cav, size_t side, std::vector<bool>& quadAvailable) {
    if (side >= cav.sides.size()) {
      Msg::Error("side %li does not exist in current cavity", side);
      return false;
    }
    std::vector<size_t> vert;
    std::vector<size_t> new_quads;
    std::vector<size_t> new_side;
    size_t he_for_prev_side = NO_ID;
    size_t he_for_next_side = NO_ID;
    vert.reserve(cav.sides[side].size()+1);
    new_quads.reserve(cav.sides[side].size()+1);
    vert.push_back(cav.M.vertex(cav.sides[side][0],0));
    // if (!cav.M.vertexIsRegular(vert[0])) return false;
    for (size_t j = 0; j < cav.sides[side].size(); ++j) {
      size_t he = cav.sides[side][j];
      if (cav.M.opposite(he) == NO_ID) {
        return false;
      }
      size_t cv = cav.M.vertex(he,1);
      if (j != cav.sides[side].size() - 1 && !cav.M.vertexIsRegular(cv)) return false;
      vert.push_back(cv);
      size_t q = cav.M.hedges[cav.M.opposite(he)].face;
      if (quadAvailable.size() && !quadAvailable[q]) return false;
      size_t new_he = cav.M.next(cav.M.next(cav.M.opposite(he)));
      new_side.push_back(new_he);
      new_quads.push_back(q);
      if (j == 0) {
        he_for_prev_side = cav.M.next(cav.M.opposite(he));
      } else if (j == cav.sides[side].size()-1) {
        he_for_next_side = cav.M.prev(cav.M.opposite(he));
      }
    }

    std::vector<size_t>& next_side = cav.sides[(side+1)%cav.sides.size()];
    std::vector<size_t>& prev_side = cav.sides[(cav.sides.size()+side-1)%cav.sides.size()];
    prev_side.push_back(he_for_prev_side);
    next_side.insert(next_side.begin(), he_for_next_side);
    cav.sides[side] = new_side;
    for (size_t q: new_quads) {
      cav.quads.insert(q);
      if (quadAvailable.size()) quadAvailable[q] = false;
    }
    if (quadAvailable.size()) {
      for (size_t q: new_quads)  quadAvailable[q] = false;
    }
    return true;
  }

  bool growIrregularSide(SCavity& cav, size_t side, std::vector<bool>& quadAvailable) {
    /* Collect all the quads in the cavity and the ones adjacent to the side */
    std::vector<size_t> _adj;

    std::vector<size_t> vert;
    vert.reserve(cav.sides[side].size()+1);

    std::vector<size_t> all_quads;
    all_quads.reserve(2*cav.quads.size());
    for (size_t f: cav.quads) all_quads.push_back(f);

    /* First corner */
    size_t v0 = cav.M.vertex(cav.sides[side][0],0);
    if (cav.M.vertices[v0].isSingularity) return false;
    vert.push_back(v0);
    if (!cav.M.vertexIsRegular(v0)) {
      cav.M.vertexFaces(v0,_adj);
      for (size_t f: _adj) {
        /* check if quad not in this cavity and not in another cavity */
        if (quadAvailable.size() == 0 || quadAvailable[f]) {
          all_quads.push_back(f);
        } else {
          if (cav.quads.find(f) == cav.quads.end()) return false; /* in other cav */
        }
      }
    }

    /* Next vertices, including second side corner */
    for (size_t j = 0; j < cav.sides[side].size(); ++j) {
      size_t he = cav.sides[side][j];
      if (cav.M.opposite(he) == NO_ID) {
        Msg::Info("- grow irregular, hedge on bdr, cancel");
        return false;
      }
      size_t cv = cav.M.vertex(he,1);
      if (cav.M.vertices[cv].isSingularity) return false;
      vert.push_back(cv);
      if (cav.M.vertexIsRegular(cv)) {
        size_t q = cav.M.hedges[cav.M.opposite(he)].face;
        if (quadAvailable.size() && !quadAvailable[q]) return false;
        all_quads.push_back(q);
      } else {
        cav.M.vertexFaces(cv,_adj);
        for (size_t f: _adj) {
          /* check if quad not in this cavity and not in another cavity */
          if (quadAvailable.size() == 0 ||  quadAvailable[f]) {
            all_quads.push_back(f);
          } else {
            if (cav.quads.find(f) == cav.quads.end()) return false; /* in other cav */
          }
        }
      }
    }
    sort_unique(all_quads);

    bool okc = convexifyQuads(cav.M, all_quads);
    if (!okc) {
      Msg::Info("- grow irregular side %i, failed to convexify, cancel", side);

      // for (size_t q: all_quads) {
      //   geolog_face(cav.M, q, 0., "!convexify_side"+std::to_string(side));
      // }
      // geolog_scavity(cav, "!convexify_side"+std::to_string(side));
      // GeoLog::flush();

      return false;
    }

    if (false) {
      static int scount = 0;
      for (size_t f: all_quads) {
        vector<size_t> vert = cav.M.face_vertices(f);
        vector<vec3> pts(vert.size());
        for (size_t lv = 0; lv < pts.size(); ++lv) {
          pts[lv] = cav.M.vertices[vert[lv]].p;
        }
        vector<double> values(vert.size(),1.);
        GeoLog::add(pts,values,"irr_CONVEX_"+std::to_string(scount));
      }
      GeoLog::flush();
    }
    
    /* Check if same number of sides */
    SCavity cav2(cav.M);
    bool oki = cav2.init(all_quads);
    if (!oki) {
      Msg::Info("- grow irregular, failed to init, cancel");
      return false;
    }

    if (cav2.sides.size() == cav.sides.size()) {
      /* Replace current cavity with new convex one */
      cav.quads = cav2.quads;
      cav.sides = cav2.sides;
      if (quadAvailable.size()) {
        for (size_t f: cav.quads) quadAvailable[f] = false;
      }
      return true;
    } else {
      Msg::Info("- grow irregular, #sides changed from %li to %li, cancel", cav.sides.size(),cav2.sides.size());
    }

    return false;
  }


  bool growSide(SCavity& cav, size_t side, 
      std::vector<bool>& quadAvailable,
      bool& containIrregular) {
    /* side is a preference, not strictly respected, and sides ordering can change when
     * eating singularities */

    bool bdr = sideTangentToBoundary(cav,side);
    if (bdr) {
      return false;
    }

    bool okr = growRegularSide(cav, side, quadAvailable);
    if (okr) return true;

    bool oki = growIrregularSide(cav, side, quadAvailable);
    if (oki) {
      containIrregular = true;
      return true;
    }
    return false;
  }

  bool growCavity(SCavity& cav, 
      std::vector<bool>& quadAvailable,
      bool& containIrregular) {
    size_t remaining = 0;
    for (size_t s = 0; s < cav.sides.size(); ++s) {
      /* side is a preference, not strictly respected, and sides ordering can change when
       * eating singularities */
      bool ok = growSide(cav, s, quadAvailable, containIrregular);
      if (ok) remaining += 1;
    }
    return remaining > 0;
  }

  bool cavityIsRemeshable(const SCavity& cav) {
    if (cav.sides.size() < 3) return false;
    int n0 = (int) cav.sides[0].size();
    int n1 = (int) cav.sides[1].size();
    int n2 = (int) cav.sides[2].size();
    if (cav.sides.size() == 3) {
      int a0 = (n0+n1-n2)/2;
      int a1 = (n1+n2-n0)/2;
      int a2 = (n0+n2-n1)/2;
      if (a0 <= 0 || a1 <= 0 || a2 <= 0) return false;
      return true;
    } else if (cav.sides.size() == 5) {
      int n3 = (int) cav.sides[3].size();
      int n4 = (int) cav.sides[4].size();
      int a0 = (n0-n1-n2+n3+n4)/2;
      int a1 = (n0+n1+n2-n3-n4)/2;
      int a2 = (n0+n1-n2-n3+n4)/2;
      int a3 = (-n0+n1+n2+n3-n4)/2;
      int a4 = (-n0-n1+n2+n3+n4)/2;
      if (a0 <=0 || a1 <=0 || a2 <=0 || a3 <=0 || a4 <=0) return false;
      return true;
    } else if (cav.sides.size() == 4) {
      int n3 = (int) cav.sides[3].size();
      if (n0 == n2 && n1 == n3) return true;
      // TODO: other cases with dipoles
    }
    return false;
  }

  bool remeshCavityWithGmsh(GFace* gf, SCavity& cav, std::vector<MVertex*>& newSingularities) {
    MeshHalfEdges& M = cav.M;

    /* Inputs for gmsh cavity remesher */
    std::set<MElement*> quads;
    std::vector<MVertex*> bnd;
    bnd.reserve(quads.size());
    std::map<MVertex *, std::vector<MElement *>, MVertexPtrLessThan> adj;

    for (size_t f: cav.quads) {
      MElement* elt = M.faces[f].ptr;
      if (elt == NULL) continue;
      quads.insert(elt);
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = elt->getVertex(lv);
        adj[v].push_back(elt);
      }
    }

    /* Boundary contour from sides */
    for (size_t s = 0; s < cav.sides.size(); ++s) {
      for (size_t i = 0; i < cav.sides[s].size(); ++i) {
        size_t he = cav.sides[s][i];
        MVertex* v = M.vertices[M.hedges[he].vertex].ptr;
        if (v == NULL) continue;
        bnd.push_back(v);
      }
    }
    std::reverse(bnd.begin(),bnd.end());

    /* Remesh with gmsh */
    std::map<MVertex*,int, MVertexPtrLessThan> newSings;
    Msg::Info("remeshing cavity with %li quads, %li bdr vertices ...", quads.size(), bnd.size());
    int status = remeshCavity(gf, cav.sides.size(), quads, bnd, adj, newSings);
    Msg::Info("-> status=%i", status);
    if (status != 1) return false;
    for (const auto& kv: newSings) {
      newSingularities.push_back(kv.first);
    }

    /* Smooth new quads */

    /* Update half edges datastructure */

    // completely rebuild the haft edges datastructure !
    
    // vector<bool> vertexToDel(M.vertices.size(),false);

    // vector<size_t> hesToDel;
    // hesToDel.reserve(cav.quads.size()*4);
    // for (size_t f: cav.quads) {
    //   size_t he = M.faces[f].he;
    //   do {
    //     size_t v = M.hedges[he].vertex;
    //     vertexToDel[v] = true;
    //     hesToDel.push_back(he);
    //     he = M.next(he);
    //   } while (he != M.faces[f].he);
    //   M.faces[f].ptr = NULL;
    // }


    // vector<size_t> hesToConnect;
    // hesToConnect.reserve(bnd.size());
    // for (size_t s = 0; s < cav.sides.size(); ++s) {
    //   for (size_t i = 0; i < cav.sides[s].size(); ++i) {
    //     size_t he = cav.sides[s][i];
    //     size_t v = M.hedges[he].vertex;
    //     vertexToDel[v] = false;
    //     size_t he_op = M.opposite(he);
    //     if (he_op != NO_ID) {
    //       M.hedges[he_op].opposite = NO_ID;
    //       hesToConnect.push_back(he_op);
    //     }
    //   }
    // }


    return true;
  }

  int growCavities(MeshHalfEdges& M,
      std::vector<SCavity>& cavities) {
    if (cavities.size() == 0) return 0;

    std::vector<bool> quadAvailable(M.faces.size(),true);
    for (size_t i = 0; i < cavities.size(); ++i) {
      SCavity& cav = cavities[i];
      for (size_t q: cav.quads) quadAvailable[q] = false;
    }

    bool remaining = true;
    std::vector<bool> running(cavities.size(),true);
    while (remaining) {
      remaining = false;
      for (size_t i = 0; i < cavities.size(); ++i) if (running[i]) {
        SCavity& cav = cavities[i];
        bool containIrregular;
        bool ok = growCavity(cav, quadAvailable, containIrregular);
        if (!ok) running[i] = false;
        if (ok) remaining = true;
      }
    }

    return 0;
  }


  int generateIsotropicCavitiesAroundSingularities(
      MeshHalfEdges& M,
      std::vector<SCavity>& cavities) 
  {
    Msg::Info("generateIsotropicCavitiesAroundSingularities ...");

    using std::priority_queue;
    using std::pair;

    cavities.clear();
    vector<size_t> quads;
    for (size_t i = 0; i < M.vertices.size(); ++i) {
      if (!M.vertices[i].isSingularity) continue;
      int val = M.vertexFaces(i, quads);
      if (val != 3 && val != 5) continue;
      SCavity cav(M);
      bool ok = cav.init(quads);
      if (!ok) {
        Msg::Error("failed to init cavity");
      }
      cavities.push_back(cav);
    }

    growCavities(M, cavities);

    for (size_t i = 0; i < cavities.size(); ++i) {
      geolog_scavity(cavities[i],"cav_"+std::to_string(i));
    }

    return 0;
  }

  int remeshCavitiesAroundSingularities(GFace* gf, std::vector<size_t>& singularNodes) 
  {
    Msg::Info("remeshCavitiesAroundSingularities ...");
    constexpr bool USE_FCAVITY = true;

    // TODO DEBUG deal with cavity that loops / periodic (happens around circles)

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;

    bool inProgress = true;
    while (inProgress) {
      inProgress = false;

      /* singularNodes is the list of singularities (irregular vertices to keep) in the 
       * GFace structure, the values are the vertex 'num' */
      int st = createMeshHalfEdges(gf, M, singularNodes);
      if (st != 0) {
        Msg::Error("failed to generate half edge datastructure for face with tag %i", gf->tag());
        return st;
      }

      Gardener G(M);

      /* Look for the best singularity around which to grow cavity ... */
      singularities.clear();
      irregularNodes.clear();
      for (size_t v = 0; v < M.vertices.size(); ++v) {
        if (M.vertices[v].isSingularity) {
          singularities.push_back(v);
        } else {
          bool onBdr;
          int val = M.vertexFaceValence(v, onBdr);
          if (!onBdr && val != 4) irregularNodes.push_back(v);
        }
      }
      vector<double> priority(singularities.size(),0.);
      for (size_t i = 0; i < irregularNodes.size(); ++i) {
        size_t iv = irregularNodes[i];
        SVector3 ip = M.vertices[iv].p;
        for (size_t j = 0; j < singularities.size(); ++j) {
          SVector3 sp = M.vertices[singularities[j]].p;
          priority[j] += 1./(ip-sp).norm();
        }
      }
      std::vector<std::pair<double,size_t> > prio_sing(singularities.size());
      for (size_t i = 0; i < singularities.size(); ++i) prio_sing[i] = {priority[i],singularities[i]};
      std::sort(prio_sing.begin(),prio_sing.end());
      std::reverse(prio_sing.begin(),prio_sing.end());

      /* Try the cavities */
      for (size_t i = 0; i < prio_sing.size(); ++i) {
        size_t v = prio_sing[i].second;
        /* Init */
        SCavity cav(M);
        FCavity fcav(M);
        vector<size_t> quads;
        M.vertexFaces(v, quads);
        if (USE_FCAVITY) {
          bool ok = fcav.init(quads);
          if (!ok) {
            for (size_t f: quads) {
              geolog_face(cav.M, f, 1., "failed_init_v="+std::to_string(v));
            }
            GeoLog::flush();
            Msg::Error("failed to init cavity");
            continue;
          }
          geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_init");
        } else {
          bool ok = cav.init(quads);
          if (!ok) {
            for (size_t f: quads) {
              geolog_face(cav.M, f, 1., "failed_init_v="+std::to_string(v));
            }
            GeoLog::flush();
            Msg::Error("failed to init cavity");
            continue;
          }
        }

        /* Build a cavity around singularity i */
        if (USE_FCAVITY) {
          G.setCavity(fcav);

          G.growMaximal();
          geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_max");

          G.convexify();
          DBG(G.isConvex());
          fcav.updateSides();
          geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_cvx");

          // G.growIsotropic(10);
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_gi10");

          // G.convexify();
          // DBG(G.isConvex());
          // fcav.updateSides();
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_cvx");

          // G.growIsotropic(100);
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_gi100");

          // G.convexify();
          // DBG(G.isConvex());
          // fcav.updateSides();
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_cvx");

          // G.growIsotropic(1000);
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_gi1000");

          // G.convexify();
          // DBG(G.isConvex());
          // fcav.updateSides();
          // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_cvx");

          GeoLog::flush();
          gmsh::fltk::run();
          break;

          // growFCavity(fcav);
          // geolog_fcavity(fcav, "fcav"+std::to_string(v));
          // GeoLog::flush();
          // gmsh::fltk::run();
          // break;
        } else {
          std::vector<bool> quadAvailable; /* not used in this context */
          bool containIrregular = false;
          bool remaining = true;
          while (remaining) {
            remaining = false;
            bool ok = growCavity(cav, quadAvailable, containIrregular);
            if (ok) remaining = true;
            /* Limit anisotropy */
            // bool too_anisotropic = false;
            // for (size_t s = 0; s < cav.sides.size(); ++s) {
            //   size_t n1 = cav.sides[s].size();
            //   size_t n2 = cav.sides[(s+1)%cav.sides.size()].size();
            //   if (n1 > 2 && n2 > 2 && (n1 > 3*n2 || n2 > 3*n1)) {
            //     too_anisotropic = true;
            //     break;
            //   }
            // }
            // if (too_anisotropic) break;
          }
          bool rem = cavityIsRemeshable(cav);
          if (!containIrregular) {
            Msg::Info("cavity around %i (%li quads) does not contain irregular vertices", v, cav.quads.size());
            geolog_scavity(cav, "ni_cav"+std::to_string(v));
            continue;
          } else if (rem) {
            Msg::Info("cavity around %i (%li quads) IS remeshable !", v, cav.quads.size());
          } else {
            Msg::Info("cavity around %i (%li quads) is NOT remeshable", v, cav.quads.size());
            geolog_scavity(cav, "nr_cav"+std::to_string(v));
            continue;
          }

          geolog_scavity(cav, "cav"+std::to_string(v));
          /* Remesh the cavity */
          std::vector<MVertex*> newSingularities;
          size_t nq = gf->quadrangles.size();
          bool okr = remeshCavityWithGmsh(gf,cav,newSingularities);
          if (okr) { /* then cavity and M are no longer valid, restart */
            size_t nq2 = gf->quadrangles.size();
            if (nq2 == nq)  {
              Msg::Warning("same number of quads in GFace after remeshing... weird");
            }
            Msg::Info("-> successfully remesh cavity");

            /* update list of singular nodes */
            size_t singularityNum = M.vertices[v].ptr->getNum();
            auto itv = std::find(singularNodes.begin(),singularNodes.end(),singularityNum);
            if (itv != singularNodes.end()) {
              singularNodes.erase(itv);
            }
            for (MVertex* v: newSingularities) {
              singularNodes.push_back(v->getNum());
            }


            inProgress = true; // DEBUG, should be true
            break;
          } else {
            Msg::Info("-> failed to remesh cavity");
            geolog_scavity(cav, "failed_cav"+std::to_string(v));
          }
        }
      }
    }

    return 0;
  }


  inline si2 hedge_sorted(const MeshHalfEdges& M, size_t he) {
    size_t v1 = M.hedges[he].vertex;
    size_t v2 = M.hedges[M.prev(he)].vertex;
    si2 vPair = {v1,v2};
    if (v2 < v1) vPair = {v2,v1};
    return vPair;
  }

  bool getOrderedVerticesFromEdges(size_t vStart, const vector<si2>& edges, vector<size_t>& orderedVertices) {
    orderedVertices.clear();
    size_t eStart = NO_ID;
    for (size_t e = 0; e < edges.size();++e) {
      for (size_t lv = 0; lv < 2; ++lv) if (edges[e][lv] == vStart) {
        eStart = e;
        break;
      }
    }
    if (eStart == NO_ID) return false;

    size_t iter = 0;
    size_t e = eStart;
    size_t v = vStart;
    while (true) {
      iter += 1;
      if (iter > 100000) {
        Msg::Error("infinite loop ? iter = %i", iter);
        return false;
      }
      orderedVertices.push_back(v);
      size_t next_v = (edges[e][0]  != v) ? edges[e][0] : edges[e][1];
      if (next_v == vStart) { /* closed chain */
        break;
      }
      size_t next_e = NO_ID;
      for (size_t ee = 0; ee < edges.size();++ee) if (ee != e) {
        for (size_t lv = 0; lv < 2; ++lv) if (edges[ee][lv] == next_v) {
          next_e = ee;
          break;
        }
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

  int computeSum35FromTriangulation(const std::vector<GFace*>& faces, std::map<int,int>& faceSum35) {
    std::map<std::array<int,2>,double> surfCornerAngle;
    int s1 = computeFaceCornerAngles(faces, surfCornerAngle);
    if (s1 != 0) {
      Msg::Error("failed to compute face corner angles");
      return s1;
    }

    for (GFace* gf: faces) {
      if (!surfaceContourIsManifold(gf)) {
        Msg::Info("surface %i contour is not manifold, ignore it", gf->tag());
        faceSum35[gf->tag()] = 9999;
        continue;
      }
      int sum3m5 = sumNbInteriorIrregularVerticesValence3And5(gf, surfCornerAngle);
      faceSum35[gf->tag()] = sum3m5;
    }
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

  /* Frontal Delaunay triangulator with sufficient points on
   * curves to capture curvatures in cross field */
  CTX::instance()->mesh.minCurvPoints = 10;
  CTX::instance()->mesh.minCircPoints = 40;
  CTX::instance()->mesh.lcFromCurvature = 1;
  CTX::instance()->mesh.minElementsPerTwoPi = 40;
  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  CTX::instance()->lock = 0;
  GenerateMesh(gm, 1);
  GenerateMesh(gm, 2);
  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;
  CTX::instance()->mesh.lcFromCurvature = 0;
  CTX::instance()->mesh.minCurvPoints = 0;
  CTX::instance()->mesh.minCircPoints = 0;

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

int computeScaledCrossField(GModel* gm, std::vector<std::array<double,5> >& singularities) {
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
  addSingularitiesAtAcuteCorners(model_faces(gm), 45., singularities);
  if (st == 0) {
    gm->getFields()->setBackgroundMesh(viewTag);
    // gm->getFields()->initialize(); // required ?
    // PView* view_s = PView::getViewByName(name);
    // if (view_s) view_s->getOptions()->visible = 0;
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

  for (GFace* gf: faces) if (gf->quadrangles.size() == 0 && gf->triangles.size() == 0) {
    Msg::Error("face %i: no quads and no triangles, abort", gf->tag());
    return -1;
  }

  bool secondOrderLinear = false; /* which value to use ? */
  RefineMesh(gm, secondOrderLinear, true, false);

  return 0;
}

using si4 = std::array<size_t,4>;
using i4 = std::array<int,4>;

bool quad_config(const MeshHalfEdges& M, const std::vector<int>& valence,
    size_t f, si4& vert, si4& hedges, i4& qVals)
{
  size_t he = M.faces[f].he;
  if (he == NO_ID) {
    Msg::Error("quad_config | face=%li, he=%li", f, he);
    return false;
  }
  size_t count = 0;
  do {
    size_t v = M.hedges[he].vertex;
    vert[count] = v;
    hedges[count] = he;
    he = M.next(he);
    count += 1;
    if (he == NO_ID || count > 4) {
      Msg::Error("quad_config | face=%li, count=%li, he=%li", f, count, he);
      return false;
    }
  } while (he != M.faces[f].he);
  int minVal = 9999;
  size_t minValLv = 0;
  for (size_t lv = 0; lv < 4; ++lv) {
    qVals[lv] = valence[vert[lv]];
    if (qVals[lv] < minVal) {
      minVal = qVals[lv];
      minValLv = lv;
    }
  }
  if (minVal == 0) {
    Msg::Error("quad_config | face=%li, minVal is 0", f);
    return false;
  }
  if (minValLv != 0) {
    /* Shift vertices to get minimum valence in first */
    std::rotate(vert.begin(), vert.begin() + minValLv, vert.end());
    std::rotate(hedges.begin(), hedges.begin() + minValLv, hedges.end());
    std::rotate(qVals.begin(), qVals.begin() + minValLv, qVals.end());
  }

  return true;
}

int move35pairsToSingularities(MeshHalfEdges& M) {
  vector<int> valence(M.vertices.size(),0);
  vector<bool> vOnBdr(M.vertices.size(),false);
  for (size_t i = 0; i < M.vertices.size(); ++i) {
    bool onBdr = false;
    valence[i] = M.vertexFaceValence(i,onBdr);
    if (onBdr) vOnBdr[i] = true;
  }

  for (size_t f = 0; f < M.faces.size();++f) {
    si4 vert;
    si4 hedges;
    i4 qVals;
    bool ok = quad_config(M, valence, f, vert, hedges, qVals);
    if (!ok) {
      Msg::Error("invalid vertices in quad");
      continue;
    }
    i4 pair35 = {3,4,5,4};
    if (qVals == pair35) {
      vector<vec3> pts = {
        M.vertices[vert[0]].p,
        M.vertices[vert[1]].p,
        M.vertices[vert[2]].p,
        M.vertices[vert[3]].p};
      vector<double> values(pts.size(),0.);
      GeoLog::add(pts,values,"pair35");
    }
  }
  GeoLog::flush();

  return 0;
}

int improveQuadMeshOfFace(GFace* gf, std::vector<size_t>& singularNodes) {
  remeshCavitiesAroundSingularities(gf, singularNodes);
  return 0;
}

int flagQuadMeshSingularNodesOnFace(
    GFace* gf,
    const std::vector<std::array<double,5> >& singularities,
    int sum3m5,
    std::vector<size_t>& singularNodes) {

  /* Singularities of the cross assigned to this CAD face */
  vector<array<double,3>> cfSingVal3;
  vector<array<double,3>> cfSingVal5;
  for (size_t k = 0; k < singularities.size(); ++k) {
    int faceTag = int(singularities[k][4]);
    if (faceTag != gf->tag()) continue;
    double index = singularities[k][3];
    SVector3 p(singularities[k][0],singularities[k][1],singularities[k][2]);
    if (index == 1.) {
      cfSingVal3.push_back(p);
    } else if (index == -1.) {
      cfSingVal5.push_back(p);
    } else {
      Msg::Warning("singularity with index %f not supported", index);
    }
  }

  /* Check compatibility between Euler-based topological relation
   * and cross field singularities */
  int cfSum3m5 = int(cfSingVal3.size()) - int(cfSingVal5.size());
  if (cfSum3m5 == sum3m5) {
    Msg::Info("face %i | good ! face topology and cross field are compatible, n_val3 - n_val5 = %i - %i = %i", 
        gf->tag(), cfSingVal3.size(), cfSingVal5.size(), cfSum3m5);
  } else {
    Msg::Warning("face %i | BAD ! face topology and cross field are NOT compatible, crossfield n_val5 - n_val3 = %i - %i = %i but geometry: %i", 
        gf->tag(), cfSingVal3.size(), cfSingVal5.size(), cfSum3m5, sum3m5);
    Msg::Warning("ignore CAD face for the moment");
    return -1;
    // TODO: alternative method to flag singular nodes to keep
  }

  vector<MVertex*> nodeVal3;
  vector<MVertex*> nodeVal5;
  {
    vector<size_t> numValence;
    vector<MVertex*> numVertex;
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
        nodeVal3.push_back(numVertex[num]);
      } else if (numValence[num] == 5){
        nodeVal5.push_back(numVertex[num]);
      }
    }
  }

  /* Assign valence 3 */
  for (size_t i = 0; i < cfSingVal3.size(); ++i) {
    SVector3 p = {cfSingVal3[i][0],cfSingVal3[i][1],cfSingVal3[i][2]};
    double dmin = DBL_MAX;
    size_t best = NO_ID;
    for (size_t j = 0; j < nodeVal3.size(); ++j) {
      SVector3 p2 = nodeVal3[j]->point();
      double dist = nodeVal3[j]->point().distance(p.point());
      if (dist < dmin) {
        dmin = dist;
        best = nodeVal3[j]->getNum();
      }
    }
    if (best != NO_ID) {
      singularNodes.push_back(best);
    } else {
      Msg::Warning("Face %i, singular node %i, failed to assign to val 3 irregular vertex", gf->tag(), i);
      GeoLog::add(p,3.,"dbg_p"+std::to_string(gf->tag())+"_remaining_sing");
    }
  }
  /* Assign valence 5 */
  for (size_t i = 0; i < cfSingVal5.size(); ++i) {
    SVector3 p = {cfSingVal5[i][0],cfSingVal5[i][1],cfSingVal5[i][2]};
    double dmin = DBL_MAX;
    size_t best = NO_ID;
    for (size_t j = 0; j < nodeVal5.size(); ++j) {
      SVector3 p2 = nodeVal5[j]->point();
      double dist = nodeVal5[j]->point().distance(p.point());
      if (dist < dmin) {
        dmin = dist;
        best = nodeVal5[j]->getNum();
      }
    }
    if (best != NO_ID) {
      singularNodes.push_back(best);
    } else {
      Msg::Warning("Face %i, singular node %i, failed to assign to val 5 irregular vertex", gf->tag(), i);
      GeoLog::add(p,5.,"dbg_p"+std::to_string(gf->tag())+"_remaining_sing");
    }
  }

  return 0;
}

int flagQuadMeshSingularNodes(const std::vector<GFace*> faces,
    const std::vector<std::array<double,5> >& singularities,
    const std::map<int,int>& faceSum35,
    std::vector<std::vector<size_t> >& faceSingularNodes)
{
  faceSingularNodes.clear();
  faceSingularNodes.resize(faces.size());

  vector<vector<size_t> > faceNodeVal3(faces.size());
  vector<vector<size_t> > faceNodeVal5(faces.size());
  vector<size_t> numValence;
  vector<MVertex*> numVertex;

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
  for (size_t i = 0; i < faces.size(); ++i) {
    GFace* gf = faces[i];
    flagQuadMeshSingularNodesOnFace(gf, singularities, faceSum35.at(gf->tag()), faceSingularNodes[i]);
  }

  return 0;
}

int improveQuadMeshTopology(GModel* gm, const std::vector<std::array<double,5> >& singularities,
    const std::map<int,int>& faceSum35) {
  vector<GFace*> faces = model_faces(gm);

  std::vector<std::vector<size_t> > faceSingularNodes;
  int stf = flagQuadMeshSingularNodes(faces, singularities, faceSum35, faceSingularNodes);
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
  std::vector<GFace*> faces = model_faces(gm);

  Msg::Info("Generate quasi-structured all-quadrilateral mesh ...");

  Msg::Info("[Step 1] Generate initial triangulation ...");
  int s1 = generateInitialTriangulation(gm);
  if (s1 != 0) {
    Msg::Error("failed to generate initial triangulation, abort");
    return s1;
  }

  std::map<int,int> faceSum35;
  int st35 = computeSum35FromTriangulation(faces, faceSum35);
  if (st35 != 0) {
    Msg::Warning("failed to compute sum 3/5 irregular nodes from triangulation, continue");
  }

  Msg::Info("[Step 2] Generate scaled cross field ...");
  std::vector<std::array<double,5> > singularities;
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

  Msg::Info("[Step 5] Improve topology of quad mesh ...");
  int s5 = improveQuadMeshTopology(gm, singularities, faceSum35);
  if (s5 != 0) {
    Msg::Warning("failed to improve quad mesh topology, continue");
  }

  return 0;
}

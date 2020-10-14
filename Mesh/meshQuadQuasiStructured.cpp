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
#include "meshQuadPatterns.h"

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
  constexpr bool DBG_VERBOSE = false;

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

  template<class T> 
    std::vector<T> difference(const std::vector<T>& v1, const std::vector<T>& v2) {
      std::vector<T> s1 = v1;
      std::vector<T> s2 = v2;
      sort_unique(s1);
      sort_unique(s2);
      std::vector<T> s3;
      set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(s3,s3.begin()));
      return s3;
    }


  std::array<int,4> rotateCanonical(std::array<int,4> indices) {
    int minVal = std::numeric_limits<int>::max();
    size_t minValLv = 0;
    for (size_t lv = 0; lv < 4; ++lv) {
      if (indices[lv] < minVal) {
        minVal = indices[lv];
        minValLv = lv;
      }
    }
    std::rotate(indices.begin(), indices.begin() + minValLv, indices.end());
    return indices;
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

    size_t face_vertices(size_t f, std::vector<size_t>& vert) const {
      vert.clear();
      size_t he = faces[f].he;
      do {
        vert.push_back(hedges[he].vertex);
        he = hedges[he].next;
      } while (he != faces[f].he);
      return vert.size();
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

    int vertexHalfEdges(size_t v, std::vector<size_t>& hes) const {
      hes.clear();
      size_t he_bdr = NO_ID;
      size_t he = vertices[v].he;
      do { /* turn around vertex v */
        hes.push_back(he);
        size_t cand = opposite(next(he));
        if (cand == NO_ID) {
          he_bdr = next(he);
          break;
        }
        he = cand;
      } while (he != vertices[v].he);
      if (he_bdr == NO_ID) return hes.size();

      /* Boundary case, unroll from he_bdr */
      hes.clear();
      he = he_bdr;
      do { /* turn around vertex v */
        hes.push_back(he);
        he = opposite(prev(he));
      } while (he != vertices[v].he && he != NO_ID);
      return hes.size();
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
      for (size_t num: singularNodes) {
        if (num >= numToHVertex.size()) {
          Msg::Error("singular node %i has no associated vertex in half edges mesh (%li vertices)", num, M.vertices.size());
          continue;
        }
        size_t nv = numToHVertex[num];
        if (nv >= M.vertices.size()) {
          Msg::Error("vertex %i (from singular node with num=%i) not found in half edges vertices (size %i), vertex not in GFace quads ?", nv, num, M.vertices.size());
          continue;
        }
        M.vertices[nv].isSingularity = true;
      }
    }

    // for (size_t i = 0; i < M.hedges.size(); ++i) {
    //   geolog_halfedge(M, i, double(i), "hedges_f"+std::to_string(gf->tag()));
    // }
    // GeoLog::flush();

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
      GeoLog::add(M.vertices[v].p, double(val), "val"+std::to_string(val));
      GeoLog::flush();
      gmsh::fltk::run();
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

    FCavity & operator= ( const FCavity & other) {
      hes = other.hes;
      side = other.side;
      quads = other.quads;
      return *this;
    }

    bool init(const std::vector<size_t>& quadsInit) {
      if (quadsInit.size() < 1) {
        Msg::Error("FCavity init: expecting at least 1 quad, not %li", quadsInit.size());
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
      if (DBG_VERBOSE) {DBG("growByFlip ...", i, hes.size());}
      if (i >= hes.size()) {
        if (DBG_VERBOSE) {DBG("can't flip because", i, hes.size());}
        info.nq = NO_ID;
        return false;
      }
      const size_t he0_op = hes[i];
      const size_t he0 = M.opposite(he0_op);
      if (he0 == NO_ID) {
        if (DBG_VERBOSE) {DBG("can't flip because", i, hes.size(), he0_op, he0);}
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
      const size_t q2 = (he2_op != NO_ID) ? M.hedges[he2_op].face: NO_ID;
      const size_t q3 = (he3_op != NO_ID) ? M.hedges[he3_op].face: NO_ID;
      const bool q1in = (q1 != NO_ID && quads.find(q1) != quads.end());
      const bool q2in = (q2 != NO_ID && quads.find(q2) != quads.end());
      const bool q3in = (q3 != NO_ID && quads.find(q3) != quads.end());
      if        ( q1in &&  q2in && !q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he1,0);
        size_t nv2 = M.vertex(he1,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include singularity", i, info.nq);}
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev_prev = (i + hes.size() - 2)%hes.size();
        hes[i_prev_prev] = he3;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        hes.erase(it0);
        auto it1 = std::find(hes.begin(),hes.end(),he1_op);
        hes.erase(it1);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); } 
      } else if ( q1in && !q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he0_op,0);
        size_t nv2 = M.vertex(he0_op,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include singularity", i, info.nq);}
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev = (i + hes.size() - 1)%hes.size();
        hes[i_prev] = he2;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        hes.erase(it0);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); } 
      } else if (!q1in &&  q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he3,0);
        size_t nv2 = M.vertex(he3,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include singularity", i, info.nq);}
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        hes[i] = he1;
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); } 
      } else if (q1in && q2in && q3in){
        size_t nv0 = M.hedges[he0].vertex;
        size_t nv1 = M.hedges[he0].vertex;
        size_t nv2 = M.hedges[he0].vertex;
        size_t nv3 = M.hedges[he0].vertex;
        if (rejectNewSings && (M.vertices[nv0].isSingularity || M.vertices[nv1].isSingularity
             || M.vertices[nv2].isSingularity || M.vertices[nv3].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include singularity", i, info.nq);}
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
        if (DBG_VERBOSE) {DBG("flip closing hole (may be too slow ?)", i, info.nq); } 
      } else if ( q1in && !q2in && !q3in) { /* same number of vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv = M.hedges[he2].vertex;
        const int val = valenceInsideQuads(M, quads, nv);
        if (val > 0) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because", i, info.nq, nv, val);}
          info.nq = NO_ID;
          return false;
        }
        const size_t nvIn = M.hedges[he0].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);}
          info.nq = NO_ID;
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev = (i + hes.size() - 1)%hes.size();
        hes[i_prev] = he2;
        hes[i] = he3;
        if (DBG_VERBOSE) {DBG("flip <>1v (1)", i, info.nq, nv); } 
      } else if (!q1in && !q2in &&  q3in) { /* same number of vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv = M.hedges[he1].vertex;
        const int val = valenceInsideQuads(M, quads, nv);
        if (val > 0) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because", i, info.nq, nv, val);}
          info.nq = NO_ID;
          return false;
        }
        const size_t nvIn = M.hedges[he0_op].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);}
          info.nq = NO_ID;
          return false;
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_next = (i + 1)%hes.size();
        hes[i] = he1;
        hes[i_next] = he2;
        if (DBG_VERBOSE) {DBG("flip <>1v (2)", i, info.nq, nv);}
      } else if (!q1in && !q2in && !q3in) { /* two additional vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv1 = M.hedges[he1].vertex;
        const int val1 = valenceInsideQuads(M, quads, nv1);
        if (val1 > 0) {
          if (DBG_VERBOSE) {DBG("no flip +2v because", i, info.nq, nv1, val1);}
          info.nq = NO_ID;
          return false;
        }
        const size_t nv2 = M.hedges[he2].vertex;
        const int val2 = valenceInsideQuads(M, quads, nv2);
        if (val2 > 0) {
          if (DBG_VERBOSE) {DBG("no flip +2v because", i, info.nq, nv2, val2);}
          info.nq = NO_ID;
          return false;
        }
        if (rejectNewSings) {
          const size_t v0 = M.vertex(he0,0);
          if (M.vertices[v0].isSingularity && valenceOutsideQuads(M, quads, v0) == 2) {
            /* Would be concave corner around singularity, reject */
            if (DBG_VERBOSE) {DBG("no flip +2v because would be concave corner at sing.", i, info.nq);}
            return false;
          }
          const size_t v1 = M.vertex(he0,1);
          if (M.vertices[v1].isSingularity && valenceOutsideQuads(M, quads, v1) == 2) {
            /* Would be concave corner around singularity, reject */
            if (DBG_VERBOSE) {DBG("no flip +2v because would be concave corner at sing.", i, info.nq);}
            return false;
          }
        }
        /* Do the flip */
        hes[i] = he1;
        hes.insert(hes.begin()+i+1,{he2,he3});
        if (DBG_VERBOSE) {DBG("flip +2v", i, info.nq);}
      
        } else {
        if (DBG_VERBOSE) {DBG("flip config not supported", i, info.nq, he0, he1, he2, he3, q1in, q2in, q3in);}
        info.nq = NO_ID;
        return false;
      }
      quads.insert(info.nq);
      return true;
    }

    int updateSides() {
      // if (DBG_VERBOSE) {DBG("updateSides ...");}
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

      // if (DBG_VERBOSE) {DBG(corners);}
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

      return sideNo+1;
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

  bool cavityIsRemeshable(const FCavity& cav) {
    if (cav.hes.size() != cav.side.size()) {
      Msg::Error("wrong side vector size");
      return false;
    }
    size_t nsides = 0;
    std::vector<int> n(6,0);
    for (size_t i = 0; i < cav.hes.size(); ++i) {
      size_t s = (size_t) cav.side[i];
      if (s >= n.size()) {
        return false;
      }
      if (n[s] == 0) nsides += 1;
      n[s] += 1;
    }

    if (nsides < 3) return false;
    if (nsides== 3) {
      int a0 = (n[0]+n[1]-n[2])/2;
      int a1 = (n[1]+n[2]-n[0])/2;
      int a2 = (n[0]+n[2]-n[1])/2;
      if (a0 <= 0 || a1 <= 0 || a2 <= 0) return false;
      return true;
    } else if (nsides== 5) {
      int a0 = (n[0]-n[1]-n[2]+n[3]+n[4])/2;
      int a1 = (n[0]+n[1]+n[2]-n[3]-n[4])/2;
      int a2 = (n[0]+n[1]-n[2]-n[3]+n[4])/2;
      int a3 = (-n[0]+n[1]+n[2]+n[3]-n[4])/2;
      int a4 = (-n[0]-n[1]+n[2]+n[3]+n[4])/2;
      if (a0 <=0 || a1 <=0 || a2 <=0 || a3 <=0 || a4 <=0) return false;
      return true;
    } else if (nsides== 4) {
      if (n[0] == n[2] && n[1] == n[3]) return true;
      // TODO: other cases with dipoles
    }
    return false;
  }

  struct Gardener {
    /* Gardener is used to manage the growth of cavities
     * Can be re-used as long as the GFace is not changed */

    /* Data */
    MeshHalfEdges& M;
    vector<int> valence;
    vector<bool> vOnBoundary;
    FCavity* current;
    vector<int> valenceInCavity;
    int cavityTargetNbOfSides;
    /* singularities (flagged irregular) strictly inside */
    std::unordered_set<size_t> sings;
    /* singularities (flagged irregular) strictly on the cavity on the cavity boundary */
    std::unordered_set<size_t> singsBdr;
    /* irregular vertices (not sing.) inside, including bdr */
    std::unordered_set<size_t> irregular;
    /* when growing, keep last valid remeshable cavity */
    FCavity lastCav;
    size_t lastNbIrregular;

    /* Methods */
    Gardener(MeshHalfEdges& M_) : M(M_), current(NULL), lastCav(M) {
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

      /* Clean stuff of the previous current cavity */
      std::fill(valenceInCavity.begin(),valenceInCavity.end(),0);
      sings.clear();
      irregular.clear();
      singsBdr.clear();
      cavityTargetNbOfSides = 0;
      lastNbIrregular = 0;
      lastCav.hes.clear();
      lastCav.side.clear();
      lastCav.quads.clear();

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
      if (cav.quads.size() == 3) {
        cavityTargetNbOfSides = 3;
      } else if (cav.quads.size() == 4 || cav.quads.size() == 1) {
        cavityTargetNbOfSides = 4;
      } else if (cav.quads.size() == 5) {
        cavityTargetNbOfSides = 5;
      } else {
        cavityTargetNbOfSides = 0;
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
        if (!vOnBoundary[v] && valOutside == 1) return false;
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
            if (DBG_VERBOSE) {DBG("new sing inside, bad ! abort", nq, v2q);}
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


    bool getFlipHalfEdgeCandidates(std::vector<size_t>& candidates) {
      if (current == NULL) return false;
      FCavity& cav = *current;

      candidates.clear();
      candidates.reserve(cav.hes.size());

      /* Forbid half-edges on the same side of a singularity,
       * or of a concave corner */
      std::unordered_set<size_t> limits = singsBdr;
      if (irregular.size() > 0) {
        for (size_t v: irregular) if (vOnBoundary[v] && valence[v] > 2) {
          /* Check if CAD corner */
          MVertex* ptr = cav.M.vertices[v].ptr;
          GVertex* gv = dynamic_cast<GVertex*>(ptr->onWhat());
          if (gv != NULL) {
            limits.insert(v);
          }
        }
      }

      if (limits.size() == 0) {
        for (size_t k = 0; k < cav.hes.size(); ++k) {
          if (M.opposite(cav.hes[k]) != NO_ID) {
            candidates.push_back(cav.hes[k]);
          }
        }
      } else{
        /* Get half edges on boundary of the cavity which are not on the
         * side of singularity */
        std::unordered_set<size_t> forbidden;
        std::vector<size_t> hesOnLimit(100);

        // bool show = false;
        // for (size_t bs: limits) {
        //   if (vOnBoundary[bs] && valence[bs] != 2) {
        //     show = true; break;
        //   }
        // }
        // if (show) {
        //   geolog_fcavity(cav, "cavity");
        //   for (size_t bs: limits) {
        //     hesOnLimit.clear();
        //     M.vertexHalfEdges(bs, hesOnLimit);
        //     for (size_t he: hesOnLimit) {
        //       geolog_halfedge(M, he, 0., "hesOnLimit");
        //     }
        //   }
        // }

        for (size_t bs: limits) {
          hesOnLimit.clear();
          M.vertexHalfEdges(bs, hesOnLimit);
          size_t heInit = NO_ID;
          size_t iInit = NO_ID;
          for (size_t he: hesOnLimit) {
            size_t he_op = M.opposite(he);
            if (he_op == NO_ID) continue;
            auto it = std::find(cav.hes.begin(),cav.hes.end(),he);
            if (it != cav.hes.end()) {
              heInit = he;
              iInit = (size_t) (it - cav.hes.begin());
              break;
            } else { /* Try opposite one */
              it = std::find(cav.hes.begin(),cav.hes.end(),he_op);
              if (it != cav.hes.end()) {
                heInit = he_op;
                iInit = (size_t) (it - cav.hes.begin());
                break;
              }
            }
          }
          if (heInit == NO_ID || iInit == NO_ID) {
            Msg::Error("weird, getFlipHalfEdgeCandidates, limit vertex (sing or concave) = %li, hesOnLimit.size() = %li, but he not found on cavity bdr",
                bs, hesOnLimit.size());
            continue;
          }
          size_t i = iInit;
          while (true) {
            size_t he = cav.hes[i];
            forbidden.insert(he);
            size_t v2 = M.vertex(he,1);
            int valOutside2 = valence[v2] - valenceInCavity[v2];
            if (valOutside2 == 1 || valenceInCavity[v2] == 1) {
              break;
            }
            i = (i + 1)%cav.hes.size();
            if (i == iInit) break;
          }
          i = iInit;
          while (true) {
            size_t he = cav.hes[i];
            forbidden.insert(he);
            size_t v1 = M.vertex(he,0);
            int valOutside1 = valence[v1] - valenceInCavity[v1];
            if (valOutside1 == 1 || valenceInCavity[v1] == 1) {
              break;
            }
            i = (i - 1 + cav.hes.size())%cav.hes.size();
            if (i == iInit) break;
          }
        }
        for (size_t k = 0; k < cav.hes.size(); ++k) {
          size_t he = cav.hes[k];
          if (M.opposite(cav.hes[k]) != NO_ID) {
            auto it = forbidden.find(he);
            if (it == forbidden.end()) {
              candidates.push_back(he);
              // if (show) geolog_halfedge(M, he, 0, "allowed");
            }
          }
        }
        // if (show) {
        //   for (size_t he: forbidden) {
        //     geolog_halfedge(M, he, 1, "forbidden");
        //   }
        //   GeoLog::flush();
        // }
      }

      return true;
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
          if (DBG_VERBOSE) {DBG(nb,N,"---",i,he,v);}
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
      std::vector<size_t> candidates;
      while (running) {
        running = false;
        bool okc = getFlipHalfEdgeCandidates(candidates);
        if (!okc) break;
        for (size_t k = 0; k < candidates.size(); ++k) {
          size_t he = candidates[k];
          auto it = std::find(cav.hes.begin(),cav.hes.end(),he);
          if (it == cav.hes.end()) continue;
          size_t pos = (size_t) (it - cav.hes.begin());
          bool ok = cav.growByFlip(pos, info, true);
          if (ok) {
            nb += 1;
            running = true;
            markNewQuad(info.nq);
          }
        }
        if (running) {
          bool okf = convexify();
          if (!okf) {
            Msg::Error("failed to do convexify flips, weird, abort");
            return false;
          }
          bool convex = isConvex();
          if (!convex) {
            running = false;
            break;
          } else {
            size_t nbi = irregular.size();
            if (nbi > lastNbIrregular) {
              int nsides = cav.updateSides();
              if (nsides == (int) cavityTargetNbOfSides) {
                /* Check number of irregular outside cavity corners */
                size_t nbi_oc = 0;
                for (size_t v: irregular)  {
                  int valIn = valenceInsideQuads(cav.M,cav.quads,v);
                  if (valIn <= 2) continue;
                  nbi_oc += 1;
                }
                if (nbi_oc == 0) continue; /* all irregular are cavity corners, no need to remesh */

                if (cavityIsRemeshable(cav)) {
                  lastCav = cav;
                  lastNbIrregular = nbi;
                }
              }
            }
          }
        }
      }
      if (lastNbIrregular > 0) {
        if (M.faces.size() == cav.quads.size() && lastNbIrregular == (size_t) cavityTargetNbOfSides) {
          /* cavity is full face, which is triangle or quad or pentagon with the right number
           * of irregular vertices at the corners */
          return false;
        }
        // geolog_fcavity(cav, "maxBeforeLast");
        cav = lastCav;
      } else {
        return false;
      }

      return true;
    }

  };


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

  template <class ITERATOR> 
    bool buildBoundary (ITERATOR beg, ITERATOR end, vector<MVertex*>& bnd){
      std::vector<MEdge> eds,veds;

      for (ITERATOR ite = beg; ite != end;++ite){
        for (size_t j=0;j<(size_t)(*ite)->getNumEdges();j++){
          eds.push_back((*ite)->getEdge(j));
        }
      }
      MEdgeLessThan melt;
      std::sort(eds.begin(),eds.end(), melt);
      for(size_t i=0;i<eds.size();i++){
        if (i != eds.size()-1 && eds[i] == eds[i+1])i++;
        else veds.push_back(eds[i]);
      }

      std::vector<std::vector<MVertex *> > vsorted;
      SortEdgeConsecutive(veds, vsorted);
      if (vsorted.empty()){
        return false;
      }
      else if (vsorted.size() > 1){
        printf("ARGHTTT %lu\n",vsorted.size());
        return false;
      }

      /* Reverse vertices if necessary, to keep coherent with elements orientation */
      {
        MEdge e = veds[0];
        MVertex* v1 = e.getVertex(0);
        MVertex* v2 = e.getVertex(1);
        auto it = std::find(vsorted[0].begin(),vsorted[0].end(),v1);
        if (it == vsorted[0].end()) {
          Msg::Error("buildBoundary(): vertex not found in sorted vertices, weird");
          return false;
        }
        size_t i = it - vsorted[0].begin();
        size_t i_next = (i+1)%vsorted[0].size();
        size_t i_prev = (i-1+vsorted[0].size())%vsorted[0].size();
        if (vsorted[0][i_next] == v2) { 
          // good ordering
        } else if (vsorted[0][i_prev] == v2) { // apply reverse
          std::reverse(vsorted[0].begin(),vsorted[0].end());
        } else {
          Msg::Error("buildBoundary(): second vertex not found in adjacent sorted vertices, weird");
          return false;
        }
      }
      bnd = vsorted[0];
      return true;
    }

  inline void removeFromAdjacencyList (MElement*e,  std::unordered_map<MVertex *, std::vector<MElement *> >& adj)
  {
    for (size_t i=0;i<e->getNumVertices();i++){
      auto iti = adj.find(e->getVertex(i));
      if (iti != adj.end()){
        iti->second.erase(std::remove(iti->second.begin(),iti->second.end(),e),iti->second.end());
      }
    }
  }

  int vertexIdealValence(MVertex* v, const std::unordered_map<MVertex *, double>& vAngle) {
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
    if (ge == NULL && gv == NULL) return 4;
    if (gv != NULL) {
      auto it = vAngle.find(v);
      if (it == vAngle.end()) return 2; /* assume flat corner if no angle */
      return int(std::round(4. * it->second / (2. * M_PI)));
    } else if (ge != NULL) {
      auto it = vAngle.find(v);
      if (it == vAngle.end()) return 2; /* assume flat corner if no angle */
      return int(std::round(4. * it->second / (2. * M_PI)));
    }
    return 0;
  }

  bool isCandidateForSmallRemeshing(
      MVertex* v,
      const std::vector<MElement *>& adjQuads,
      const std::unordered_map<MVertex *, double>& vAngle) {
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
    if (ge == NULL && gv == NULL) { /* inside GFace */
      if (adjQuads.size() == 6) return true;

    } else { /* on boundary */
      int ival = vertexIdealValence(v, vAngle);
      if (ge != NULL || ival == 2) { /* on curve, or flat corner */
        if (adjQuads.size() == 3) return true;
        if (adjQuads.size() == 4) return true;
        // if (adjQuads.size() == 5) return true; // do not work well ?
      }
    }
    return false;
  }

  bool remeshSmallDefects(GFace* gf) {
    std::unordered_map<MVertex *, double> vAngle; /* for flat corner on curves */
    std::unordered_map<MVertex *, std::vector<MElement *> > adj;
    for (MQuadrangle* f: gf->quadrangles) {
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = f->getVertex(lv);
        adj[v].push_back(f);

        MVertex* vPrev = f->getVertex((4+lv-1)%4);
        MVertex* vNext = f->getVertex((lv+1)%4);
        SVector3 pNext = vNext->point();
        SVector3 pPrev = vPrev->point();
        SVector3 pCurr = v->point();
        double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
        vAngle[v] += agl;
      }
    }

    bool remaining = true;
    while (remaining) {
      remaining = false;

      for (auto& kv: adj) {
        MVertex* v = kv.first;
        bool candidate = isCandidateForSmallRemeshing(v, kv.second, vAngle);
        if (!candidate) continue;

        vector<MElement*> quads = kv.second; /* copy ! */
        std::vector<MVertex*> bnd;
        bool okb = buildBoundary(quads.begin(),quads.end(), bnd);
        if (!okb || bnd.size() < 4) {
          Msg::Error("failed to build boundary around vertex quads");
          continue;
        }
        if (bnd.back() == bnd.front()) bnd.resize(bnd.size()-1);
        vector<int> bndIdealValence(bnd.size(),0);
        vector<std::pair<int,int> > bndAllowedValenceRange(bnd.size());
        for (size_t i = 0; i < bnd.size(); ++i) {
          MVertex* bv = bnd[i];
          int ival = vertexIdealValence(bv, vAngle);
          std::vector<MElement*> exterior = difference(adj[bv], quads);
          bndIdealValence[i] = ival - int(exterior.size());
          if (ival == 2 && exterior.size() == 0) { /* on flat boundary */
            bndAllowedValenceRange[i] = {2,2};
          } else if (ival == 2 && exterior.size() == 1) { /* on flat boundary but cavity corner */
            bndAllowedValenceRange[i] = {1,1};
          } else if (exterior.size() == 1) { /* avoid 2 */
            bndAllowedValenceRange[i] = {2,4}; 
            // OR allow valence 2 and remove just after ?
            // may be more efficient
           
          // } else if (exterior.size() >= 5) { /* bad, minimize ... */
          //   bndAllowedValenceRange[i] = {1,1}; 
          // } else if (exterior.size() == 4) { /* avoid 6 */
          //   bndAllowedValenceRange[i] = {1,1}; 
          // } else if (exterior.size() == 3) { /* avoid 6 */
          //   bndAllowedValenceRange[i] = {1,2}; 
          // } else if (exterior.size() == 2) { /* avoid 6 */
          //   bndAllowedValenceRange[i] = {1,3}; 
          // } else if (exterior.size() == 1) { /* avoid 2 and 6 */
          //   bndAllowedValenceRange[i] = {2,4}; 
          // } else if (exterior.size() == 0) {
          //   bndAllowedValenceRange[i] = {1,4}; 
          } else {
            bndAllowedValenceRange[i] = {1,4}; 
          }
        }

        std::vector<MVertex*> newVertices;
        std::vector<bool> vertexIsIrregular;
        std::vector<MElement*> newElements;
        int status = remeshFewQuads(gf, bnd, bndIdealValence, bndAllowedValenceRange, 
            newVertices, vertexIsIrregular, newElements);
        if (status == 0) {
          if (true) {
            for (size_t i = 0; i < bnd.size()-1; ++i) {
              vector<array<double,3>> pts = {SVector3(bnd[i]->point()),SVector3(bnd[i+1]->point())};
              vector<double> values = {double(i),double(i+1)};
              GeoLog::add(pts,values,"scav_b"+std::to_string(bnd.size())+"_"+std::to_string(v->getNum()));
            }
            for (MElement* f: quads) {
              vector<array<double,3>> pts = {
                SVector3(f->getVertex(0)->point()),
                SVector3(f->getVertex(1)->point()),
                SVector3(f->getVertex(2)->point()),
                SVector3(f->getVertex(3)->point())
              };
              vector<double> values(pts.size(),double(f->getNum()));
              GeoLog::add(pts,values,"scav_b"+std::to_string(bnd.size())+"_"+std::to_string(v->getNum()));
            }
            GeoLog::flush();
          }

          /* Remove old quads, update adjacency */
          for (MElement* f: quads) {
            MQuadrangle *q = dynamic_cast<MQuadrangle*>(f);	      
            if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
            auto it = std::find(gf->quadrangles.begin(),gf->quadrangles.end(), q);
            if (it != gf->quadrangles.end()) {
              gf->quadrangles.erase(it);
            }
            removeFromAdjacencyList(f,  adj);
            delete f;
          }
          { /* Check if inside vertex must be removed */
            GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
            GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
            if (ge == NULL && gv == NULL) { /* inside GFace */
              auto it1 = std::find(gf->mesh_vertices.begin(),gf->mesh_vertices.end(), v);
              if (it1 != gf->mesh_vertices.end()) {
                gf->mesh_vertices.erase(it1);
              }
              auto it2 = adj.find(v);
              if (it2 != adj.end()) {
                adj.erase(it2);
              }
              delete v;
            }
          }

          for (MElement* f: newElements) {
            for (size_t lv = 0; lv < 4; ++lv) {
              MVertex* v2 = f->getVertex(lv);
              adj[v2].push_back(f);
            }
          }

          /* Restart */
          meshWinslow2d(gf, 10);
          remaining = true;
          break;
        } else {
          if (true) {
            for (size_t i = 0; i < bnd.size()-1; ++i) {
              vector<array<double,3>> pts = {SVector3(bnd[i]->point()),SVector3(bnd[i+1]->point())};
              vector<double> values = {double(i),double(i+1)};
              GeoLog::add(pts,values,"!scav_b"+std::to_string(bnd.size())+"_"+std::to_string(v->getNum()));
            }
            for (MElement* f: quads) {
              vector<array<double,3>> pts = {
                SVector3(f->getVertex(0)->point()),
                SVector3(f->getVertex(1)->point()),
                SVector3(f->getVertex(2)->point()),
                SVector3(f->getVertex(3)->point())
              };
              vector<double> values(pts.size(),double(f->getNum()));
              GeoLog::add(pts,values,"!scav_b"+std::to_string(bnd.size())+"_"+std::to_string(v->getNum()));
            }
            GeoLog::flush();
          }
          DBG("failed around", v->getNum(), bnd.size());
          // return false;
          // remaining = true;
          // break;
        }
      }
    }
    meshWinslow2d(gf, 100);
    return true;
  }

  bool remeshCavityWithGmsh(GFace* gf, FCavity& cav, std::vector<MVertex*>& newSingularities) {
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
    size_t nsides = 0;
    for (size_t i = 0; i < cav.hes.size(); ++i) {
      size_t he = cav.hes[i];
      if (cav.side[i] > nsides) nsides = cav.side[i];
      MVertex* v = M.vertices[M.hedges[he].vertex].ptr;
      if (v == NULL) continue;
      bnd.push_back(v);
    }
    std::reverse(bnd.begin(),bnd.end());
    nsides += 1;

    /* Remesh with gmsh */
    std::map<MVertex*,int, MVertexPtrLessThan> newSings;
    Msg::Info("remeshing cavity with %li quads, %li bdr vertices ...", quads.size(), bnd.size());
    int status = remeshCavity(gf, nsides, quads, bnd, adj, newSings);
    if (status != 1) return false;
    for (const auto& kv: newSings) {
      newSingularities.push_back(kv.first);
    }

    /* Smooth new quads */
    return true;
  }

  bool remeshCavityWithQuadPatterns(GFace* gf, FCavity& cav, std::vector<MVertex*>& newSingularities) {
    MeshHalfEdges& M = cav.M;

    uint8_t smax = 0;
    std::vector<std::vector<MVertex*> > sides;
    for (size_t i0 = 0; i0 < cav.hes.size(); ++i0) {
      size_t i0prev = (i0-1+cav.hes.size())%cav.hes.size();
      smax = std::max(smax,cav.side[i0]);
      if (cav.side[i0] == cav.side[i0prev]) continue;
      for (size_t i = 0; i < cav.hes.size(); ++i) {
        size_t pos = (i0 + i)%cav.hes.size();
        size_t he = cav.hes[pos];
        uint8_t side = cav.side[pos];
        if (side >= sides.size()) sides.resize(side+1);
        MVertex* v1 = M.vertices[M.vertex(he,0)].ptr;
        MVertex* v2 = M.vertices[M.vertex(he,1)].ptr;
        if (sides[side].size() == 0) sides[side].push_back(v1);
        sides[side].push_back(v2);
      }
      break;
    }

    if (sides.size() == 0 && smax < 1) { /* only one side */
      for (size_t i = 0; i < cav.hes.size(); ++i) {
        size_t he = cav.hes[i];
        uint8_t side = cav.side[i];
        if (side >= sides.size()) sides.resize(side+1);
        MVertex* v1 = M.vertices[M.vertex(he,0)].ptr;
        MVertex* v2 = M.vertices[M.vertex(he,1)].ptr;
        if (sides[side].size() == 0) sides[side].push_back(v1);
        sides[side].push_back(v2);
      }
    }

    Msg::Info("remeshing cavity with %li quads, %li sides ...", cav.quads.size(), sides.size());

    std::vector<MVertex*> newVertices;
    std::vector<bool> vertexIsIrregular;
    std::vector<MElement*> newElements;
    int status = remeshPatchWithQuadPattern(gf, sides, newVertices, vertexIsIrregular, newElements);
    if (status != 0) return false;

    /* Remove old quads */
    for (size_t f: cav.quads) {
      MElement* elt = M.faces[f].ptr;
      MQuadrangle *q = dynamic_cast<MQuadrangle*>(elt);	      
      if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
      gf->quadrangles.erase (std::remove(gf->quadrangles.begin(),gf->quadrangles.end(),q),gf->quadrangles.end());
    }

    return true;
  }


  int remeshCavitiesAroundSingularities(GFace* gf, std::vector<size_t>& singularNodes) 
  {
    Msg::Info("remeshCavitiesAroundSingularities ...");

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;

    size_t count = 0;
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
        FCavity fcav(M);
        vector<size_t> quads;
        M.vertexFaces(v, quads);
        bool ok = fcav.init(quads);
        if (!ok) {
          Msg::Error("failed to init cavity");
          continue;
        }
        // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_init");

        /* Build a cavity around singularity i */
        G.setCavity(fcav);

        bool okg = G.growMaximal();
        if (!okg) continue;

        {
          int ns = fcav.updateSides();
          geolog_fcavity(fcav, "cavr"+std::to_string(ns)+"_"+std::to_string(v)+"_before");
        }

        /* Remesh the cavity */
        std::vector<MVertex*> newSingularities;
        size_t nq = gf->quadrangles.size();
        // bool okr = remeshCavityWithGmsh(gf,fcav,newSingularities);
        bool okr = remeshCavityWithQuadPatterns(gf,fcav,newSingularities);
        if (okr) { /* then cavity and M are no longer valid, restart */
          size_t nq2 = gf->quadrangles.size();
          if (nq2 == nq)  {
            Msg::Warning("same number of quads in GFace after remeshing... weird");
          }

          /* update list of singular nodes */
          size_t singularityNum = M.vertices[v].ptr->getNum();
          auto itv = std::find(singularNodes.begin(),singularNodes.end(),singularityNum);
          if (itv != singularNodes.end()) {
            singularNodes.erase(itv);
          }
          for (MVertex* v: newSingularities) {
            singularNodes.push_back(v->getNum());
          }
          inProgress = true;
          count += 1;
          break;
        } else {
          Msg::Info("-> failed to remesh cavity");
          geolog_fcavity(fcav, "failed_cav"+std::to_string(v));
        }
      }
    }

    if (count > 0) {
      Msg::Info("winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
      meshWinslow2d(gf, 100);
    }

    return 0;
  }

  int remeshQuadrilateralPatches(GFace* gf, std::vector<size_t>& singularNodes) 
  {
    Msg::Info("remeshQuadrilateralPatches ...");

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> pairs35;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;

    size_t count = 0;
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

      { /* Collect singularities and irregular vertices */
        singularities.clear();
        irregularNodes.clear();
        for (size_t v = 0; v < M.vertices.size(); ++v) {
          if (M.vertices[v].isSingularity) {
            singularities.push_back(v);
          } else if (G.vOnBoundary[v] && G.valence[v] != 2) {
            MVertex* vp = M.vertices[v].ptr;
            GVertex* gv = vp->onWhat()->cast2Vertex();
            if (gv != nullptr)  continue; /* ignore corners */
            irregularNodes.push_back(v);
          } else if (!G.vOnBoundary[v] && G.valence[v] != 4) {
            irregularNodes.push_back(v);
          }
        }
      }

      { /* Collect quads with pairs of 3-5 (or equivalent on boundary) */
        pairs35.clear();
        vector<size_t> fvert;
        const array<int,4> indices35 = {-1,0,1,0};
        array<int,4> quadIndices = {0,0,0,0};
        for (size_t f = 0; f < M.faces.size(); ++f) {
          size_t n = M.face_vertices(f,fvert);
          if (n != 4) {
            Msg::Error("face %li is not a quad ? %li vertices", f, n);
            return false;
          }
          for (size_t lv = 0; lv < n; ++lv) {
            quadIndices[lv] = (G.vOnBoundary[fvert[lv]]) ?  2 - G.valence[fvert[lv]] : 4 - G.valence[fvert[lv]];
          }
          quadIndices = rotateCanonical(quadIndices);
          if (quadIndices == indices35) {
            pairs35.push_back(f);
          }
        }
      }

      /* Look for the best 3-5 pair around which to grow cavity ... */
      // priority = distance contrib from other 3-5 and TODO repulson from singularities
      vector<double> priority(pairs35.size(),0.);
      for (size_t i = 0; i < pairs35.size(); ++i) {
        size_t f = pairs35[i];
        SVector3 pos = M.vertices[M.hedges[M.faces[f].he].vertex].p;
        for (size_t j = 0; j < pairs35.size(); ++j) if (i != j) {
          SVector3 pos2 = M.vertices[M.hedges[M.faces[pairs35[j]].he].vertex].p;
          double dist = (pos-pos2).norm();
          if (dist != 0.) priority[i] += 1./dist;
        }
      }
      std::vector<std::pair<double,size_t> > prio_sing(priority.size());
      for (size_t i = 0; i < pairs35.size(); ++i) prio_sing[i] = {priority[i],pairs35[i]};
      std::sort(prio_sing.begin(),prio_sing.end());
      std::reverse(prio_sing.begin(),prio_sing.end());

      /* Try the cavities */
      for (size_t i = 0; i < prio_sing.size(); ++i) {
        size_t f = prio_sing[i].second;
        /* Init */
        FCavity fcav(M);
        vector<size_t> quads = {f};
        bool ok = fcav.init(quads);
        if (!ok) {
          Msg::Error("failed to init cavity");
          continue;
        }
        geolog_fcavity(fcav, "cavr4_"+std::to_string(f)+"_init");

        /* Build a cavity around singularity i */
        G.setCavity(fcav);

        bool okg = G.growMaximal();
        if (!okg) continue;

        geolog_fcavity(fcav, "cavr4_"+std::to_string(f)+"_before");

        /* Remesh the cavity */
        std::vector<MVertex*> newSingularities;
        size_t nq = gf->quadrangles.size();
        bool okr = remeshCavityWithGmsh(gf,fcav,newSingularities);
        if (okr) { /* then cavity and M are no longer valid, restart */
          size_t nq2 = gf->quadrangles.size();
          if (nq2 == nq)  {
            Msg::Warning("same number of quads in GFace after remeshing... weird");
          }

          for (MVertex* v: newSingularities) {
            singularNodes.push_back(v->getNum());
          }
          inProgress = true;
          count += 1;
          break;
        } else {
          Msg::Info("-> failed to remesh cavity");
          geolog_fcavity(fcav, "failed_cav_q"+std::to_string(f));
        }
      }
    }

    if (count > 0) {
      Msg::Info("winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
      meshWinslow2d(gf, 100);
    }

    return 0;
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
  // for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_FRONTAL);

  /* Frontal Delaunay triangulator with sufficient points on
   * curves to capture curvatures in cross field */
  // CTX::instance()->mesh.minCurvPoints = 10;
  // CTX::instance()->mesh.minCircPoints = 40;
  // CTX::instance()->mesh.lcFromCurvature = 1;
  // CTX::instance()->mesh.minElementsPerTwoPi = 40;
  CTX::instance()->mesh.algo2d = ALGO_2D_FRONTAL;
  CTX::instance()->lock = 0;
  GenerateMesh(gm, 1);
  GenerateMesh(gm, 2);
  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;
  CTX::instance()->mesh.lcFromCurvature = 0;
  CTX::instance()->mesh.minCurvPoints = 0;
  CTX::instance()->mesh.minCircPoints = 0;

  // for (GFace* gf: faces) gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);
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
  // Msg::Warning("target number of quads not divided by 4 because of incoherencies between curves/surfaces mesh");
  targetNumberOfQuads *= 0.25; /* because of future midpoint subdivision */
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
  double acute = 30.;
  addSingularitiesAtAcuteCorners(model_faces(gm), acute, singularities);
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
  /* Disable clscale because we have a sizemap 
   * that contains the scaling */
  double clscale = CTX::instance()->mesh.lcFactor;
  CTX::instance()->mesh.lcFactor = 1.;

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

  CTX::instance()->mesh.lcFactor = clscale;
  return 0;
}

int generateUnstructuredQuadMeshes(GModel* gm) {
  /* Disable clscale because we have a sizemap 
   * that contains the scaling */
  double clscale = CTX::instance()->mesh.lcFactor;
  CTX::instance()->mesh.lcFactor = 1.;


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
    CTX::instance()->mesh.lcFactor = clscale;
    return -1;
  }

  bool secondOrderLinear = false; /* which value to use ? */
  RefineMesh(gm, secondOrderLinear, true, false);

  CTX::instance()->mesh.lcFactor = clscale;
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
  remeshQuadrilateralPatches(gf, singularNodes);
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
    // Msg::Warning("ignore CAD face for the moment");
    // return -1;
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

  /* Improve local defects (valence 6+, valence 3+ on curves, etc) */
  for (size_t i = 0; i < faces.size(); ++i) {
    GFace* gf = faces[i];
    remeshSmallDefects(gf);
  }

  return 0;


  /* Improve quad meshes with larger operators (cavity remeshing) */
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

  // Msg::Info("[Step 5] Improve topology of quad mesh ...");
  // int s5 = improveQuadMeshTopology(gm, singularities, faceSum35);
  // if (s5 != 0) {
  //   Msg::Warning("failed to improve quad mesh topology, continue");
  // }

  return 0;
}

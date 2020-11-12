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
#include "meshQuadGeometry.h"


#include "meshRefine.h"
#include "discreteFace.h"
#include "Generator.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Field.h"
#include "geolog.h"
#include "meshWinslow2d.h"
#include "meshGEdge.h"
#include "GModelIO_OCC.h"
#include "gmsh.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "qmt_utils.hpp" // For debug printing
#if defined(HAVE_HXT)
#include "meshGFaceHxt.h"
#endif

#if defined(_OPENMP)
#include <omp.h>
#endif

using std::vector;
using std::array;
using std::unordered_map;
using std::unordered_set;

using namespace QuadPatternMatching;

namespace QSQ {
  constexpr bool DBG_VERBOSE = false;
  constexpr bool DBG_VIZU = false;
  bool SHOW_CAVITIES = false;
  constexpr bool EXPORT_MESHES = true;

  constexpr bool PARANO = false;

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

  template<class T> 
    void remove_element_if_inside(const T& value, std::vector<T>& vec) {
      auto it = std::find(vec.begin(),vec.end(),value);
      if (it != vec.end()) {
        vec.erase(it);
      }
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
      bool oks = SortEdgeConsecutive(veds, vsorted);
      if (!oks) {
        // DBG("issue with", veds.size());
        // for (auto edge: veds) {
        //   DBG(edge.getMinVertex()->getNum(),edge.getMaxVertex()->getNum());
        // }
        // DBG("-----");
        return false;
      }
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

  void geolog_elements(const std::vector<MElement*>& elts, const std::string& name,
      double value = 0.) {
    for (MElement* f: elts) {
      vector<array<double,3> > pts(f->getNumVertices());
      for (size_t i = 0; i < pts.size(); ++i) {
        pts[i] = SVector3(f->getVertex(i)->point());
      }
      vector<double> values(pts.size(),value);
      GeoLog::add(pts,values,name);
    }
  }


  GEdge *quad_face_opposite_edge(GFace *face, GEdge *edge)
  {
    if(face->edges().size() != 4) return nullptr;
    GEdge *op = nullptr;
    int v1 = edge->getBeginVertex()->tag();
    int v2 = edge->getEndVertex()->tag();
    bool edgeInside = false;
    for(GEdge *ge : face->edges()) {
      if(ge == edge) {
        edgeInside = true;
        continue;
      }
      int cv1 = ge->getBeginVertex()->tag();
      int cv2 = ge->getEndVertex()->tag();
      if(cv1 != v1 && cv1 != v2 && cv2 != v1 && cv2 != v2) {
        if(op == nullptr) { op = ge; }
        else { /* already found ? should not happen */
          return nullptr;
        }
      }
    }
    if(!edgeInside) return nullptr;
    return op;
  }

  void build_chords(const std::set<GFace *> &faces,
      std::vector<std::set<GEdge *> > &chords) {
    /* Connectivity */
    std::map<GEdge *, std::vector<GFace *> > edge2faces;
    for(GFace *gf : faces)
      for(GEdge *ge : gf->edges()) { edge2faces[ge].push_back(gf); }

    Msg::Debug("build chords: %li faces, %li edges", faces.size(),
        edge2faces.size());

    std::map<GEdge *, bool> done;
    for(auto &kv : edge2faces) {
      GEdge *geInit = kv.first;
      if(done.find(geInit) != done.end()) continue;

      /* Breath first search starting from a GEdge */
      std::queue<GEdge *> Q;
      Q.push(geInit);
      done[geInit] = true;

      std::set<GEdge *> chord;
      while(Q.size() > 0) {
        GEdge *ge = Q.front();
        Q.pop();
        chord.insert(ge);
        for(GFace *gf : edge2faces[ge]) {
          GEdge *ge2 = quad_face_opposite_edge(gf, ge);
          if(ge2 && done.find(ge2) == done.end()) {
            Q.push(ge2);
            done[ge2] = true;
          }
        }
      }

      if(chord.size() >= 2) { chords.push_back(chord); }
    }
  }

  bool verticesStrictlyInsideCavity(const std::vector<MElement*>& quads,
      const std::vector<MVertex*>& bnd, std::vector<MVertex*>& inside) {
    std::vector<MVertex*> vert;
    vert.reserve(4*quads.size());
    for (MElement* f: quads) for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = f->getVertex(lv);
      vert.push_back(v);
    }
    sort_unique(vert);
    inside = difference(vert,bnd);
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


  struct GFaceInfo {
    int chi = 0;
    std::map<GVertex*,int> cornerAngle;
    std::set<GVertex*> cornerIsNonManifold;
    std::array<std::set<GVertex*>,5> bdrValVertices;
    int intSumVal3mVal5 = 0;
  };

  bool fillGFaceInfo(GFace* gf, GFaceInfo& info) {
    info.chi = 0;
    info.cornerAngle.clear();
    info.cornerIsNonManifold.clear();
    for (auto& a: info.bdrValVertices) a.clear();
    info.intSumVal3mVal5 = 0;
    
    if (gf->triangles.size() == 0) {
      if (gf->quadrangles.size() != 0) {
        Msg::Error("fillGFaceInfo: there are %li quads in face %li, cannot compute angles from triangles", 
            gf->quadrangles.size(),gf->tag());
        return false;
      }
      Msg::Debug("compute trianguled mesh to fill GFaceInfo ...");
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
    std::unordered_map<GVertex*,vector<MElement*> > corner2tris;
    std::unordered_map<GVertex*,double> corner2angle;
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
          corner2tris[gv].push_back(t);
          corner2angle[gv] += agl;
        }
      }
    }
    /* Check if corner is manifold */
    for (const auto& kv: corner2tris) {
      GVertex* gv = kv.first;
      std::vector<MElement*> elts = kv.second;
      vector<MVertex*> bnd;
      bool okb = buildBoundary(elts.begin(),elts.end(), bnd);
      if (!okb) {
        info.cornerIsNonManifold.insert(gv);
        continue;
      }
      double angle = corner2angle[gv];
      double angle_deg = 180. / M_PI * angle;
      if (angle_deg < 90. + 45.) {
        info.bdrValVertices[1].insert(gv);
      } else if (angle_deg < 180. + 45.) {
        info.bdrValVertices[2].insert(gv);
      } else if (angle_deg < 270. + 45.) {
        info.bdrValVertices[3].insert(gv);
      } else if (angle_deg < 360.) {
        info.bdrValVertices[4].insert(gv);
      } else {
        Msg::Error("weird angle, corner (surf=%i,node=%i), angle = %f deg", gf->tag(), gv->tag(), angle_deg);
        continue;
      }
    }
    info.chi = surfaceEulerCharacteristicDiscrete(gf);

    /* discrete topological relations between irregular vertices:
     *  sum3m5 = n_val3 - n_val5 = 4 \chi + m_val3 - m_val1  + 2 m_val4 */
    info.intSumVal3mVal5 = 4*info.chi + int(info.bdrValVertices[3].size()) 
      - int(info.bdrValVertices[1].size()) + 2 * int(info.bdrValVertices[4].size());

    return true;
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

    inline size_t next(size_t he) const {
      if (he == NO_ID) return NO_ID;
      return hedges[he].next; 
    }
    inline size_t opposite(size_t he) const {
      if (he == NO_ID) return NO_ID;
      return hedges[he].opposite; 
    }
    inline size_t prev(size_t he) const {
      if (he == NO_ID) return NO_ID;
      return hedges[he].prev;
    }
    inline size_t vertex(size_t he, size_t lv) const {
      if (he == NO_ID) return NO_ID;
      return (lv == 0) ? hedges[prev(he)].vertex : hedges[he].vertex;
    }
    inline MVertex* vertexPtr(size_t he, size_t lv) const {
      size_t v = vertex(he,lv);
      if (v == NO_ID) return NULL;
      return vertices[v].ptr;
    }
    inline MElement* facePtr(size_t he) const {
      if (he == NO_ID) return NULL;
      size_t f = hedges[he].face;
      if (f == NO_ID) return NULL;
      return faces[f].ptr;
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
    vector<double> values(vert.size(),value);
    GeoLog::add(pts,values,viewName);
  }

  inline si2 sorted(size_t v1, size_t v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }

  bool buildAdjacencies(const vector<MQuadrangle*>& quadrangles, 
      vector<array<size_t,4> >& adjacent) {

    adjacent.resize(quadrangles.size());
    unordered_map<si2,si2,si2hash> vPairToQuads;
    for (size_t i = 0; i < quadrangles.size(); ++i) {
      MElement* f = quadrangles[i];
      adjacent[i] = {NO_ID,NO_ID,NO_ID,NO_ID};
      for (size_t le = 0; le < 4; ++le) {
        size_t v1 = f->getVertex(le)->getNum();
        size_t v2 = f->getVertex((le+1)%4)->getNum();
        si2 vPair = sorted(v1,v2);
        auto it = vPairToQuads.find(vPair);
        if (it == vPairToQuads.end()) {
          vPairToQuads[vPair] = {4*i+le,NO_ID};
        } else {
          if (it->second[1] == NO_ID) {
            size_t a2 = it->second[0];
            if (a2 == NO_ID) {
              Msg::Error("should not happen");
              return false;
            }
            it->second[1] = 4*i+le;
            size_t f2 = a2 / 4;
            size_t le2 = a2 % 4;
            adjacent[i][le] = 4*f2+le2;
            adjacent[f2][le2] = 4*i+le;
          } else {
            Msg::Error("non manifold quad mesh");
            return false;
          }
        }
      }
    }

    return true;
  }

  bool reorientQuadranglesIfNecessary(vector<MQuadrangle*>& quads) {
    vector<array<size_t,4> > adjacent;
    bool oka = buildAdjacencies(quads, adjacent);
    if (!oka) return false;

    std::vector<bool> visited(quads.size(),false);
    std::vector<bool> needInvert(quads.size(),false);
    for (size_t fInit = 0; fInit < quads.size(); ++fInit) if (!visited[fInit]) {
      std::queue<size_t> Q;
      Q.push(fInit);
      visited[fInit] = true;

      while (Q.size()) {
        size_t f = Q.front();
        Q.pop();

        for (size_t le = 0; le < 4; ++le) {
          size_t v1 = quads[f]->getVertex(le)->getNum();
          size_t v2 = quads[f]->getVertex((le+1)%4)->getNum();
          size_t aa = adjacent[f][le];
          if (aa == NO_ID) continue;
          size_t f2 = aa/4;
          if (visited[f2]) continue;
          size_t le2 = aa%4;
          size_t av1 = quads[f2]->getVertex(le2)->getNum();
          size_t av2 = quads[f2]->getVertex((le2+1)%4)->getNum();
          if (av1 == v1 && av2 == v2) { /* re-order ! */
            if (!needInvert[f]) needInvert[f2] = true;
          } else if (av1 == v2 && av2 == v1) { /* normal */
            if (needInvert[f]) needInvert[f2] = true;
          } else {
            return false;
          }
          visited[f2] = true;
          Q.push(f2);
        }
      }
    }
    size_t nbi = 0;
    for (size_t f = 0; f < quads.size(); ++f) if (!needInvert[f]) {
      MVertex* v1 = quads[f]->getVertex(1);
      MVertex* v3 = quads[f]->getVertex(3);
      quads[f]->setVertex(1,v3);
      quads[f]->setVertex(3,v1);
      nbi += 1;
    }
    Msg::Info("re-oriented %li quadrangles", nbi);
    return true;
  }

  int createMeshHalfEdges(const std::vector<MQuadrangle*>& quadrangles, MeshHalfEdges& M, const std::vector<MVertex*>& singularVertices) {
    /* warning: does not scale on big big model because of numToHVertex */
    M.vertices.clear();
    M.hedges.clear();
    M.faces.clear();

    unordered_map<MVertex*,size_t> mv2new;
    M.vertices.reserve(4*quadrangles.size());
    M.hedges.reserve(4*quadrangles.size());
    M.faces.reserve(quadrangles.size());

    for (MQuadrangle* q: quadrangles) {
      /* Create vertices if necessary */
      size_t quad[4];
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v1 = q->getVertex(le);
        size_t nv = NO_ID;
        auto it = mv2new.find(v1);
        if (it != mv2new.end()) nv = it->second;
        if (nv == NO_ID) {
          nv = M.vertices.size();
          M.vertices.resize(nv+1);
          mv2new[v1] = nv;
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
        Msg::Error("non manifold quad mesh, cannot build half edge datastructure");
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

    /* Flag singular vertices */
    for (MVertex* mv: singularVertices) {
      auto it = mv2new.find(mv);
      if (it == mv2new.end()) {
        Msg::Error("singular vertex with num=%i not found in half edges vertices, vertex not in GFace quads ?", mv->getNum());
        continue;
      }
      M.vertices[it->second].isSingularity = true;
    }

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
    std::unordered_map<si2,size_t,si2hash> vPairCount;
    for (size_t he: hes) {
      if (M.hedges[he].opposite == NO_ID) continue;
      size_t v1 = M.vertex(he,0);
      size_t v2 = M.vertex(he,1);
      vPairCount[sorted(v1,v2)] += 1;
    }
    std::vector<size_t> hes2;
    hes2.reserve(hes.size()/4);
    for (size_t he: hes) {
      if (M.hedges[he].opposite == NO_ID) {
        hes2.push_back(he);
      } else {
        size_t v1 = M.vertex(he,0);
        size_t v2 = M.vertex(he,1);
        si2 vp = sorted(v1,v2);
        auto it = vPairCount.find(vp);
        if (it != vPairCount.end() && it->second == 1) {
          hes2.push_back(he);
        }
      }
    }
    hes = hes2;

    // std::vector<size_t>::iterator it_he = hes.begin();
    // while (it_he != hes.end()) {
    //   size_t he = *it_he;
    //   size_t he_op = M.opposite(he);
    //   auto it_op = std::find(hes.begin(),hes.end(), he_op);
    //   if (it_op != hes.end()) {
    //     hes.erase(it_op);
    //     it_he = hes.erase(it_he);
    //   } else {
    //     it_he++;
    //   }
    // }
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
      size_t iter = 0;
      do {
        iter += 1;
        if (iter > 100 * hes_stack.size()) {
          Msg::Error("infinite loop in orderedHalfEdgesFromStack ? iter = %li", iter);
          return false;
        }

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

    std::vector<int> _tmp_val; /* for re-use in updateSides() */


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
        Msg::Error("failed to order %li boundary half edges (%li quads)", hes_stack.size(), quads.size());
        for (size_t he: hes_stack) {
          geolog_halfedge(M,he,double(he),"???");
        }
        GeoLog::flush();
      }
      int nsides = updateSides();
      if (nsides <= 0) {
        Msg::Error("should have at least one side, not %i", nsides);
        return false;
      }

      return true;
    }

    bool slowVerifyHalfEdgesInside(const std::vector<size_t>& halfedges) {
      bool ok = true;
      for (size_t he: halfedges) {
        auto it = std::find(hes.begin(),hes.end(),he);
        if (it == hes.end()) {
          Msg::Warning("slowVerifyHalfEdgesInside: he=%li not found in the %li cavity half-edges", he, hes.size());
          ok = false;
        }
      }
      if (!ok) {
        vector<MElement*> quadPtr;
        for(size_t kk: quads) {
          quadPtr.push_back(M.faces[kk].ptr);
        }
        geolog_elements(quadPtr, "--- quads");
        for (size_t k = 0; k < hes.size(); ++k) {
          geolog_halfedge(M, hes[k], double(k), "hes");
        }
        for (size_t he: halfedges) {
          auto it = std::find(hes.begin(),hes.end(),he);
          if (it == hes.end()) {
            geolog_halfedge(M, he, 0., "!missing half edges");
          }
        }
        GeoLog::flush();
      }
      return ok;
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
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he2_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return false;
          }
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
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return false;
          }
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
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he2_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return false;
          }
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        hes[i] = he1;
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        if (it2 == hes.end()) {
          gmsh::fltk::run();
        }
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        hes.erase(it3);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); } 
      } else if (q1in && q2in && q3in){
        size_t nv0 = M.hedges[he0].vertex;
        size_t nv1 = M.hedges[he1].vertex;
        size_t nv2 = M.hedges[he2].vertex;
        size_t nv3 = M.hedges[he3].vertex;
        if (rejectNewSings && (M.vertices[nv0].isSingularity || M.vertices[nv1].isSingularity
             || M.vertices[nv2].isSingularity || M.vertices[nv3].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include singularity", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv0].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv3].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he2_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel closing hole, missing half-edges");
            return false;
          }
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
        if (dynamic_cast<GVertex*>(M.vertices[nvIn].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip <>1v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op});
          if (!okv) {
            Msg::Warning("cancel flip <>1v, missing half-edges");
            return false;
          }
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
        if (dynamic_cast<GVertex*>(M.vertices[nvIn].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip <>1v rejected because would include GVertex", i, info.nq);}
          return false;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip <>1v, missing half-edges");
            return false;
          }
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
      _tmp_val.resize(M.vertices.size());
      std::fill(_tmp_val.begin(),_tmp_val.end(),0);
      // std::vector<int> val(M.vertices.size());
      // std::unordered_map<size_t,int> val;
      for (size_t f: quads) {
        size_t he = M.faces[f].he;
        for (size_t lv = 0; lv < 4; ++lv) {
          size_t v = M.hedges[he].vertex;
          _tmp_val[v] += 1;
          he = M.hedges[he].next;
        }
      }

      std::unordered_set<size_t> corners;
      for (size_t i = 0; i < M.vertices.size(); ++i) if (_tmp_val[i] == 1) {
        corners.insert(i);
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

  bool cavityIsRemeshable(const FCavity& cav, double& irregularityMeasure,
      const std::vector<size_t>& patternsToCheck) {
    if (cav.hes.size() != cav.side.size()) {
      Msg::Error("wrong side vector size");
      return false;
    }
    std::vector<size_t> npts;
    for (size_t i = 0; i < cav.hes.size(); ++i) {
      size_t s = (size_t) cav.side[i];
      if (s >= npts.size()) {
        npts.resize(s+1,0);
        if (s >= 5) return false; /* keep cavity with less than 5 sides */
      }
      npts[s] += 1;
    }
    /* Nb edges -> nb points (including bdr) */
    for (size_t i = 0; i < npts.size(); ++i) npts[i] += 1;

    std::pair<size_t,int> patternNoAndRot;
    size_t Ncorners = npts.size();
    bool meshable = patchIsRemeshableWithQuadPattern(patternsToCheck,Ncorners, npts, patternNoAndRot, irregularityMeasure);
    return meshable;
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
    double lastIrregularity;

    /* Methods */
    Gardener(MeshHalfEdges& M_) : M(M_), current(NULL), lastCav(M), lastIrregularity(DBL_MAX) {
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
        if (vOnBoundary[v] && valOutside == 0 && valence[v] >= 3) {
          /* Check if corner */
          MVertex* mv = M.vertices[v].ptr;
          GVertex* gv = dynamic_cast<GVertex*>(mv->onWhat());
          if (gv != NULL) {
            /* Concave corner absorbed, bad */
            return false;
          }
        }
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

        bool show = false;
        // for (size_t bs: limits) {
        //   if (vOnBoundary[bs] && valence[bs] != 2) {
        //     show = true; break;
        //   }
        // }

        for (size_t bs: limits) {
          size_t heInit = NO_ID;
          size_t iInit = NO_ID;
          size_t heq1 = NO_ID;
          /* Special case for valence 3 concave corners */
          if (!M.vertices[bs].isSingularity) {
            vector<size_t> vfaces;
            if (M.vertexFaces(bs,vfaces) == 3) {
              bool faceInside[3];
              for (size_t lq = 0; lq < vfaces.size(); ++lq) {
                size_t q = vfaces[lq];
                faceInside[lq] = (cav.quads.find(q) != cav.quads.end());
              }
              /* Find the hedge in vfaces[1] pointing to bs */
              heq1 = M.faces[vfaces[1]].he;
              do {
                if (M.vertex(heq1,1) == bs) break;
                heq1 = M.next(heq1);
              } while (heq1 != M.faces[vfaces[1]].he);
              if (M.vertex(heq1,1) != bs) return false;
              size_t faceOp = M.hedges[M.opposite(heq1)].face;
              if (faceOp != vfaces[0] && faceOp != vfaces[2]) return false;

              if (faceInside[0] && faceInside[1] && faceInside[2]) {
                return false; /* should not happen, concave corner in cavity ? */
              } else if (faceInside[0] && faceInside[1]) {
                if (faceOp == vfaces[0]) {
                  heInit = M.next(heq1);
                } else {
                  heInit = heq1;
                }
              } else if (faceInside[1] && faceInside[2]) {
                if (faceOp == vfaces[0]) {
                  heInit = heq1;
                } else {
                  heInit = M.next(heq1);
                }
              } else if (faceInside[0]) {
                if (faceOp == vfaces[0]) {
                  heInit = M.prev(M.opposite(heq1));
                } else {
                  heInit = M.next(M.opposite(M.next(heq1)));
                }
              } else if (faceInside[1]) {
                /* Random between the two sides */
                heInit = heq1;
              } else if (faceInside[2]) {
                if (faceOp == vfaces[0]) {
                  heInit = M.next(M.opposite(M.next(heq1)));
                } else {
                  heInit = M.prev(M.opposite(heq1));
                }
              }
            }
            if (heInit != NO_ID) {
              auto it = std::find(cav.hes.begin(),cav.hes.end(),heInit);
              if (it != cav.hes.end()) {
                iInit = (size_t) (it - cav.hes.begin());
              } else {
                Msg::Error("getFlipHalfEdgeCandidates: hes not found in cavity (at concave corner), should not happen");
                return false;
              }
            }
          }
          if (heInit == NO_ID) {
            hesOnLimit.clear();
            M.vertexHalfEdges(bs, hesOnLimit);
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
          }
          if (heInit == NO_ID || iInit == NO_ID) {
            Msg::Debug("getFlipHalfEdgeCandidates, limit vertex (sing or concave) = %li, hesOnLimit.size() = %li, but he not found on cavity bdr",
                bs, hesOnLimit.size());
            if (SHOW_CAVITIES) {
              GeoLog::flush();
              GeoLog::add(M.vertices[bs].p, double(hesOnLimit.size()),"!gfhec_not_on_bdr");
            }
            return false;
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
              if (show) geolog_halfedge(M, he, 0, "allowed");
            }
          }
        }
        if (show) {
          for (size_t he: forbidden) {
            geolog_halfedge(M, he, 1, "forbidden");
          }
          geolog_fcavity(cav, "cavity");
          for (size_t bs: limits) {
            GeoLog::add(M.vertices[bs].p, double(hesOnLimit.size()),"limits");
            hesOnLimit.clear();
            M.vertexHalfEdges(bs, hesOnLimit);
            for (size_t he: hesOnLimit) {
              geolog_halfedge(M, he, 0., "hesOnLimit");
            }
          }
          GeoLog::flush();
        }
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

    bool growMaximal(const std::vector<size_t>& patternsToCheck, 
        const std::vector<std::pair<size_t,size_t> >& patternSizeLimits = {}) 
    {
      if (current == NULL) return false;
      FCavity& cav = *current;
      Msg::Debug("growMaximal: start with %li quads, %li half-edges on bdr ...", cav.quads.size(), cav.hes.size());
      bool running = true;
      size_t nb = 0;
      FlipInfo info;
      std::vector<size_t> candidates;
      size_t iter = 0;
      while (running) {
        iter += 1;
        if (iter > 1e6) {
          Msg::Error("growMaximal: iter=%li, infinite loop ?", iter);
          break;
        }
        running = false;
        bool okc = getFlipHalfEdgeCandidates(candidates);
        if (!okc) {
          Msg::Debug("growMaximal: failed to get flip half edge candidates");
          break;
        }
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
            bool okf = convexify();
            if (!okf) {
              Msg::Debug("growMaximal: failed to convexity, stop growth");
              running = false;
              break;
            }
          }
        }
        if (running) {
          bool convex = isConvex();
          if (!convex) {
            Msg::Debug("growMaximal: cavity not convex, stop growth");
            running = false;
            // geolog_fcavity(cav, "!convex");
            break;
          } else {
            size_t nbi = irregular.size();
            if (nbi > lastNbIrregular) {
              int nsides = cav.updateSides();
              if (nsides == (int) cavityTargetNbOfSides) {
                double currentCavityIrregularity = 0.;
                /* Check number of irregular outside cavity corners */
                size_t nbi_oc = 0;
                for (size_t v: irregular)  {
                  int valIn = valenceInsideQuads(cav.M,cav.quads,v);
                  if (valIn <= 2) continue;
                  nbi_oc += 1;
                  currentCavityIrregularity += std::pow(valIn-4,2);
                }
                if (nbi_oc == 0) continue; /* all irregular are cavity corners, no need to remesh */
                for (size_t v: sings) {
                  int valIn = valenceInsideQuads(cav.M,cav.quads,v);
                  currentCavityIrregularity += std::pow(valIn-4,2);
                }

                vector<size_t> patternsToCheckRefined = patternsToCheck;
                if (patternSizeLimits.size() > 0) {
                  for (const auto& p: patternSizeLimits) {
                    if (cav.quads.size() > p.second) {
                      remove_element_if_inside(p.first,patternsToCheckRefined);
                    }
                  }
                }

                double irreg = DBL_MAX;
                Msg::Debug("growMaximal: check if cavity is remeshable");
                bool remeshable = cavityIsRemeshable(cav, irreg, patternsToCheckRefined);
                if (remeshable && irreg <= lastIrregularity && irreg < currentCavityIrregularity) {
                  /* Do not choose a pattern if strictly worse irregularity */
                  Msg::Debug("growMaximal: set remeshable cavity (%li quads, irregularity=%f, #irreg=%li)", cav.quads.size(), irreg, nbi_oc);
                  lastCav = cav;
                  lastNbIrregular = nbi;
                  lastIrregularity = irreg;
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
          Msg::Debug("growMaximal: cavity is full face, exit");
          return false;
        }
        // geolog_fcavity(cav, "maxBeforeLast");
        cav = lastCav;
        Msg::Debug("growMaximal: restore previous valid cavity");
      } else {
        return false;
      }

      Msg::Debug("growMaximal: done, %li quads, %li half-edges on cavity bdr", cav.quads.size(), cav.hes.size());
      return true;
    }

  };

  // /* warning: indices (in start, adjacent[i], chord) are in the form 4*f+le */
  // bool buildChord(size_t start, const vector<array<size_t,4> >& adjacent, vector<size_t>& chord) {
  //   /* Init */
  //   std::unordered_set<size_t> visited;
  //   std::queue<size_t> Q;
  //   Q.push(start);
  //   visited.insert(start / 4);

  //   /* Propagation */
  //   while (Q.size() > 0) {
  //     size_t a = Q.front();
  //     Q.pop();
  //     chord.push_back(a);
  //     size_t f = a/4;
  //     size_t le = a%4;

  //     for (size_t k = 0; k < 2; ++k) {
  //       size_t le_cur = (k == 0) ? le : (le+2)%4;
  //       size_t a2 = adjacent[f][le_cur];
  //       if (a2 == NO_ID) continue;
  //       size_t f2 = a2 / 4;
  //       bool already_visited = (visited.find(f2) != visited.end());
  //       if (already_visited) continue;
  //       Q.push(a2);
  //       visited.insert(a2/4);
  //     }
  //   }

  //   sort_unique(chord);
  //   return chord.size() > 2;
  // }

  // inline si2 sorted(size_t v1, size_t v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }

  // struct DualGardener {
  //   vector<MElement*> quads;
  //   vector<array<size_t,4> > adjacent;
  //   vector<vector<size_t> > barrier; /* barrier = list of quads */
  //   vector<bool> isTrigger;
  //   unordered_map<size_t, vector<size_t> > trigger; /* quad -> barrier ids */


  //   bool init(const GFace* gf) {
  //     unordered_map<si2,si2,si2hash> vPairToQuads;
  //     quads.resize(gf->quadrangles.size());
  //     adjacent.resize(gf->quadrangles.size());
  //     for (size_t i = 0; i < gf->quadrangles.size(); ++i) {
  //       MElement* f = gf->quadrangles[i];
  //       quads[i] = f;
  //       adjacent[i] = {NO_ID,NO_ID,NO_ID,NO_ID};
  //       for (size_t le = 0; le < 4; ++le) {
  //         size_t v1 = f->getVertex(le)->getNum();
  //         size_t v2 = f->getVertex((le+1)%4)->getNum();
  //         si2 vPair = sorted(v1,v2);
  //         auto it = vPairToQuads.find(vPair);
  //         if (it == vPairToQuads.end()) {
  //           vPairToQuads[vPair] = {4*i+le,NO_ID};
  //         } else {
  //           if (it->second[1] == NO_ID) {
  //             size_t a2 = it->second[0];
  //             if (a2 == NO_ID) {
  //               Msg::Error("DualGardener init: should not happen");
  //               return false;
  //             }
  //             it->second[1] = 4*i+le;
  //             size_t f2 = a2 / 4;
  //             size_t le2 = a2 % 4;
  //             adjacent[i][le] = 4*f2+le2;
  //             adjacent[f2][le2] = 4*i+le;
  //           } else {
  //             Msg::Error("DualGardener init: non manifold quad mesh for face %i", gf->tag());
  //             return false;
  //           }
  //         }
  //       }
  //     }

  //     return true;
  //   }

  //   bool buildCavityBarriers(
  //       const std::unordered_set<MVertex*>& singularities,
  //       const std::unordered_set<MVertex*>& concaveCorners) {

  //     unordered_map<MVertex*,vector<MElement*> > v2e;
  //     for (size_t i = 0; i < quads.size(); ++i) {
  //       MElement* f = quads[i];
  //       for (size_t lv = 0; lv < 4; ++lv) {
  //         MVertex* v = f->getVertex(lv);
  //         auto it1 = singularities.find(v);
  //         if (it1 != singularities.end()) {
  //           v2e[v].push_back(f);
  //           continue;
  //         }
  //         auto it2 = concaveCorners.find(v);
  //         if (it2 != concaveCorners.end()) {
  //           v2e[v].push_back(f);
  //         }
  //       }
  //     }

  //     /* Build barriers */
  //     for (MVertex* v: concaveCorners) {
  //       auto it = v2e.find(v);

  //       if (it == v2e.end()) {
  //         Msg::Warning("no quads around concave corner ? weird");
  //         continue;
  //       } else if (it->second.size() == 3) {

  //       } else if (it->second.size() == 4) {
  //       } else {
  //         Msg::Warning("concave corner %li has %li adjacent quads", v->getNum(), it->second.size());
  //       }
  //     }

  //     return true;
  //   }
  // };


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

  void geolog_closed_curve(const std::vector<MVertex*>& bnd, const std::string& name) {
    for (size_t i = 0; i < bnd.size(); ++i) {
      SVector3 p1 = bnd[i]->point();
      SVector3 p2 = bnd[(i+1)%bnd.size()]->point();
      vector<array<double,3>> pts = {p1,p2};
      vector<double> values = {double(i),double(i+1)};
      GeoLog::add(pts,values,name);
    }
  }


  inline bool vertexOnSeamCurve(GFace* gf, MVertex* v) {
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge == NULL) return false;
    if (ge->isSeam(gf) && ge->faces().size() == 1) return true;
    return false;
  }

  const int CORNER = 1;
  const int CURVE = 2;
  const int SURFACE = 3;

  inline int vertexSupport(GFace* gf, MVertex* v) {
    GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
    if (gv != NULL) return CORNER;
    GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
    if (ge != NULL) return CURVE;
    GFace* gf2 = dynamic_cast<GFace*>(v->onWhat());
    if (gf2 != NULL) return SURFACE;
    return 0;
  }

  inline bool vertexOnBoundary(GFace* gf, MVertex* v) {
    int vs = vertexSupport(gf,v);
    return (vs == CORNER || vs == CURVE);
  }

  void removeElement(GFace* gf, MElement* e, std::unordered_map<MVertex *, std::vector<MElement *> >& adj) {
    if (e == NULL) return;
    for (size_t i=0;i<e->getNumVertices();i++){
      MVertex* v = e->getVertex(i);
      if (v == NULL) continue;
      auto it = adj.find(v);
      if (it != adj.end()){
        auto it2 = std::find(it->second.begin(),it->second.end(),e);
        if (it2 != it->second.end()) it->second.erase(it2);
      }
    }
    MQuadrangle *q = dynamic_cast<MQuadrangle*>(e);	      
    if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
    auto it = std::find(gf->quadrangles.begin(),gf->quadrangles.end(), q);
    if (it != gf->quadrangles.end()) {
      gf->quadrangles.erase(it);
    }
    delete e;
    e = NULL;
  }

  void removeVertex(MVertex* v, std::unordered_map<MVertex *, std::vector<MElement *> >& adj) {
    if (v == NULL) return;
    auto it = adj.find(v);
    if (it != adj.end()){
      adj.erase(it);
    }
    GFace* gf = dynamic_cast<GFace*>(v->onWhat());
    if (gf != NULL) {
      auto it = std::find(gf->mesh_vertices.begin(),gf->mesh_vertices.end(), v);
      if (it != gf->mesh_vertices.end()) {
        gf->mesh_vertices.erase(it);
      }
    } else {
      GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
      if (ge != NULL) {
        auto it = std::find(ge->mesh_vertices.begin(),ge->mesh_vertices.end(), v);
        if (it != ge->mesh_vertices.end()) {
          ge->mesh_vertices.erase(it);
        }
      } else {
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        if (gv != NULL) {
          auto it = std::find(gv->mesh_vertices.begin(),gv->mesh_vertices.end(), v);
          if (it != gv->mesh_vertices.end()) {
            gv->mesh_vertices.erase(it);
          }
        }
      }
    }
    delete v;
    v = NULL;
  }

  inline void addToAdjacencyList(GFace* gf, MElement*e, std::unordered_map<MVertex *, std::vector<MElement *> >& adj)
  {
    for (size_t i=0;i<e->getNumVertices();i++){
      MVertex* v = e->getVertex(i);
      adj[v].push_back(e);
    }
  }

  int vertexIdealValence(MVertex* v, const std::unordered_map<MVertex *, double>& vAngle) {
    auto it = vAngle.find(v);
    if (it == vAngle.end()) return 4;
    int ival = int(clamp(std::round(4. * it->second / (2. * M_PI)),1.,4.));
    return ival;
  }

  bool slowVerifyMeshIsValid(GFace* gf) {
    Msg::Debug("slow, verify mesh of face %i ...", gf->tag());
    std::unordered_map<MVertex *, std::vector<MElement *> > adj;
    std::map<array<size_t,2>, size_t> edgeVal;
    for (MQuadrangle* f: gf->quadrangles) {
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = f->getVertex(lv);
        adj[v].push_back(f);
        MVertex* v2 = f->getVertex((lv+1)%4);
        if (v->getNum() < v2->getNum()) {
          array<size_t,2> vpair = {v->getNum(),v2->getNum()};
          edgeVal[vpair] += 1;
        } else {
          array<size_t,2> vpair =  {v2->getNum(),v->getNum()};
          edgeVal[vpair] += 1;
        }
      }
    }

    bool ok = true;
    for (auto& kv: edgeVal) {
      if (kv.second > 2) {
        Msg::Error("slowVerifyMeshIsValid | edge (%i,%i) non manifold, valence =  %i", kv.first[0],kv.first[1], kv.second);
        ok = false;
        if (DBG_VIZU) {
          size_t num1 = kv.first[0];
          size_t num2 = kv.first[1];
          MVertex* v1 = gf->getMeshVertex(num1);
          MVertex* v2 = gf->getMeshVertex(num2);
          if (v1 == NULL || v2 == NULL) {
            Msg::Error("  edge vertices not found in GFace");
            continue;
          } 
          SVector3 p1 = v1->point();
          SVector3 p2 = v2->point();
          vector<vec3> pts = {p1,p2};
          vector<double> values(2,double(kv.second));
          GeoLog::add(pts,values,"!non_manifold_edge");
        }
        continue;
      }
    }

    for (auto& kv: adj) {
      MVertex* v = kv.first;
      GFace* vgf = dynamic_cast<GFace*>(v->onWhat());
      if (vgf != NULL) {
        auto it = std::find(gf->mesh_vertices.begin(),gf->mesh_vertices.end(),v);
        if (it == gf->mesh_vertices.end()) {
          Msg::Error("slowVerifyMeshIsValid | vertex %i not found in GFace", v->getNum());
          continue;
        }
      }
      vector<MElement*> quads = kv.second;
      std::vector<MVertex*> bnd;
      bool okb = buildBoundary(quads.begin(),quads.end(), bnd);
      if (!okb) {
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        if (gv != NULL) {
          Msg::Warning("slowVerifyMeshIsValid | failed to build boundary at vertex %i (on CAD corner, may be normal if not manifold)", v->getNum());
          continue;
        } else {
          Msg::Error("slowVerifyMeshIsValid | failed to build boundary at vertex %i (not on CAD corner, so should not happen)", v->getNum());
          ok = false;
          if (DBG_VIZU) {
            geolog_elements(quads, "!invalid_"+std::to_string(quads.size())+"quads");
            GeoLog::add(SVector3(v->point()),0.,"!failed_one_ring");
            GeoLog::flush();
          }
          continue;
        }
      }
      if (bnd.size() > 0 && bnd.back() == bnd.front()) bnd.resize(bnd.size()-1);
    }

    for (MVertex* v: gf->mesh_vertices) {
      size_t num = v->getNum();
      if (num == 0) Msg::Error("num should be >0 ?");
      auto it = adj.find(v);
      if (it == adj.end()) {
        Msg::Error("slowVerifyMeshIsValid | vertex %i has no adjacent quads", v->getNum());
        ok = false;
      } else if (it->second.size() == 0) {
        Msg::Error("slowVerifyMeshIsValid | vertex %i has no adjacent quads", v->getNum());
        ok = false;
      }
    }
    if (DBG_VIZU && !ok) GeoLog::flush();
    return ok;
  }

  double irregularityEnergyOfCavity(GFace* gf,
      const std::vector<MVertex*>& bnd,
      const std::vector<int>& bndIdealValence,
      const vector<std::pair<int,int> >& bndAllowedValenceRange,
      const std::vector<MVertex*>& inside,
      const std::vector<MElement*>& quads)  {
    std::unordered_map<MVertex*,int> qval;
    for (MElement* f: quads) for (size_t lv = 0; lv < f->getNumVertices(); ++lv) {
      MVertex* v = f->getVertex(lv);
      qval[v] += 1;
    }
    double energy = 0.;
    for (size_t i = 0; i < bnd.size(); ++i) {
      auto it = qval.find(bnd[i]);
      if (it == qval.end()) {
        Msg::Error("irregularityEnergyOfCavity | bnd vertex %li not found in qval", bnd[i]->getNum());
        continue;
      }
      double val = double(it->second);
      energy += std::pow(val-bndIdealValence[i],2);
      if (bndAllowedValenceRange[i].first == bndAllowedValenceRange[i].second) {
        if (val != bndAllowedValenceRange[i].first) {
          energy += 1000. * std::abs(val-bndAllowedValenceRange[i].first); /* defect penalty */
        }
      }
    }
    for (MVertex* v: inside) {
      auto it = qval.find(v);
      if (it == qval.end()) {
        Msg::Error("irregularityEnergyOfCavity | interior vertex %li not found in qval", v);
        continue;
      }
      double val = double(it->second);
      energy += std::pow(val-4.,2);
      if (val > 5) energy += 1000. * (val-5); /* defect penalty */
    }
    return energy;
  }

  double irregularityEnergyOnRing(GFace* gf, MVertex* v, 
      const std::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const std::unordered_map<MVertex *, double>& vAngle
      ) {
    int vs = vertexSupport(gf,v);
    const std::vector<MElement*> quads = adj.at(v);
    std::set<MVertex*> bnd; /* not ordered */
    for (MElement* f: quads) for (size_t lv = 0; lv < f->getNumVertices(); ++lv) {
      MVertex* v2 = f->getVertex(lv);
      if (v2 != v) bnd.insert(v2);
    }
    double irregularity = 0.;
    for (MVertex* v2: bnd) {
      int vs2 = vertexSupport(gf,v2);
      int val = adj.at(v2).size();
      if (vs2 == CORNER || vs2 == CURVE) {
        int ival = vertexIdealValence(v2, vAngle);
        irregularity += std::pow(double(val-ival),2);
      } else if (vs == SURFACE) {
        irregularity += std::pow(double(val-4),2);
      }
    }
    return irregularity;
  }

  bool growAroundQuads(
      const std::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      vector<MElement*>& quads) {
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v2 = quads[0]->getVertex(lv);
      auto it = adj.find(v2);
      if (it != adj.end()) {
        for (MElement* f2: it->second) {
          quads.push_back(f2);
        }
      }
    }
    sort_unique(quads);
    return true;
  }

  bool remeshableVertexProperties(
      GFace* gf, MVertex* v,
      const std::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const std::unordered_map<MVertex *, double>& vAngle,
      int& ideal,
      vector<MElement*>& quads
      ) {
    int vs = vertexSupport(gf,v);
    quads = adj.at(v); /* copy */
    /* Ideal quad valence on the vertex */
    ideal = 4;
    if (vs == CORNER) {
      ideal = vertexIdealValence(v, vAngle);
    } else if (vs == CURVE) {
      ideal = 2;
    }

    /* Existing adjacent quads, check if current config is defect or not */
    if (vs == CORNER && quads.size() == (size_t) ideal) return false;
    if (vs == CURVE && quads.size() == 2) return false;
    if (vs == SURFACE && (quads.size() == 4 || quads.size() == 5)) return false;

    bool growCavityAroundQuad = false;

    if (vs == SURFACE && quads.size() == 3) { /* Check if there is a diamond */
      for (MElement* f: quads) {
        for (size_t lv = 0; lv < 4; ++lv) {
          MVertex* v2 = f->getVertex(lv);
          if (v2 == v) { /* Check others */
            MVertex* v2_prev = f->getVertex((lv+4-1)%4);
            MVertex* v2_op = f->getVertex((lv+2)%4);
            MVertex* v2_next = f->getVertex((lv+1)%4);
            if (adj.at(v2_prev).size() > 3 
                && adj.at(v2_op).size() == 3 
                && adj.at(v2_next).size() > 3) {
              if (vertexOnBoundary(gf,v2_prev) || vertexOnBoundary(gf, v2_op) || vertexOnBoundary(gf, v2_next)) continue;
              /* Found a diamond ! */
              quads = {f};
              growCavityAroundQuad = true;
              break;
            }
          }
        }
        if (growCavityAroundQuad) break;
      }
      if (!growCavityAroundQuad) return false; /* No diamond, keep current valence 3 vertex */
    }

    /* For valence 1 vertex on curves, need to grow the cavity a bit */
    if (quads.size() == 1 && ((vs == CORNER && ideal >= 2) || (vs == CURVE && ideal >= 2))) {
      growCavityAroundQuad = true;
    }
    
    if (growCavityAroundQuad) {
      growAroundQuads(adj, quads);
    }

    return true;
  }


  size_t initPriorityQueueWithDefects(
      int pass,
      GFace* gf,
      const std::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const std::unordered_map<MVertex *, double>& vAngle,
      std::priority_queue<std::pair<double,MVertex*>, std::vector<std::pair<double,MVertex*> > >& Q) {
    for (auto& kv: adj) {
      MVertex* v = kv.first;
      int vs = vertexSupport(gf,v);
      if (vs != pass) continue;
      double prio = irregularityEnergyOnRing(gf, v, adj, vAngle);
      if (vs == CURVE && kv.second.size() > 2) prio += 1000. * std::abs(double(kv.second.size())-2.);
      if (vs == SURFACE && kv.second.size() > 5) prio += 1000. * std::abs(double(kv.second.size())-4.);
      Q.push({prio,v});
    }
    return Q.size();
  }

  int addAffectedVerticesToQueue(
      int pass,
      GFace* gf,
      const std::vector<MElement*>& quads,
      const std::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const std::unordered_map<MVertex *, double>& vAngle,
      std::priority_queue<std::pair<double,MVertex*>, std::vector<std::pair<double,MVertex*> > >& Q) {
    int count = 0;
    for (MElement* q: quads) {
      /* check if quad still there, necessary because of recursive functions */
      auto itq = std::find(gf->quadrangles.begin(),gf->quadrangles.end(),q);
      if (itq != gf->quadrangles.end()) {
        for (size_t lv = 0; lv < q->getNumVertices(); ++lv) {
          MVertex* v2 = q->getVertex(lv);
          int vs2 = vertexSupport(gf,v2);
          if (vs2 != pass) continue;
          double irreg2 = irregularityEnergyOnRing(gf, v2, adj, vAngle);
          auto it2 = adj.find(v2);
          if (it2 != adj.end()) {
            if (vs2 == CURVE && it2->second.size() > 2) irreg2 += 1000. * std::abs(double(it2->second.size())-2.);
            if (vs2 == SURFACE && it2->second.size() > 5) irreg2 += 1000. * std::abs(double(it2->second.size())-4.);
          }
          if (irreg2 > 0) {
            Q.push({irreg2,v2}); /* add to queue */
            count += 1;
          }
        }
      }
    }
    return count;
  }

  bool transferSeamGEdgesVerticesToGFace(GFace* gf) {
    /* Transfer the vertices from seam GEdge to associated GFace */
    std::unordered_map<MVertex*,MVertex*> old2new;
    for (GEdge* ge: gf->edges()) {
      if (ge->isSeam(gf) && ge->faces().size() == 1 && ge->faces()[0] == gf) {
        for (MVertex* ov: ge->mesh_vertices) {
          SPoint3 p = ov->point();
          double t;
          ov->getParameter(0,t);
          SPoint2 uv = ge->reparamOnFace(gf, t, -1);
          MVertex *nv = new MFaceVertex(p.x(),p.y(),p.z(),gf,uv[0],uv[1]);
          nv->setParameter(0,uv[0]);
          nv->setParameter(1,uv[1]);
          gf->mesh_vertices.push_back(nv);
          old2new[ov] = nv;
          delete ov;
        }
        ge->mesh_vertices.clear();
        for (size_t i = 0; i < ge->lines.size(); ++i) {
          delete ge->lines[i];
        }
        ge->lines.clear();
      }
    }
    if (old2new.size() > 0) {
      for (MElement* f: gf->quadrangles) for (size_t lv = 0; lv < 4; ++lv){ 
        MVertex* v = f->getVertex(lv);
        auto it = old2new.find(v);
        if (it != old2new.end()) {
          f->setVertex(lv, it->second);
        }
      }
    }
    return true;
  }

  bool remeshSmallDefects(GFace* gf) {
    Msg::Debug("- Face %i: remove small quad mesh defects (%li input quads) ...", gf->tag(), gf->quadrangles.size());
    size_t nq_in = gf->quadrangles.size();

    // TODO FROM HERE: detect and remove diamonds

    std::unordered_set<MVertex*> tried_bigger_cavity;
    std::unordered_set<MVertex*> doNotDegrade;

    std::unordered_map<MVertex *, double> vAngle; /* for flat corner on curves */
    std::unordered_map<MVertex *, std::vector<MElement *>> adj;
    for (MQuadrangle* f: gf->quadrangles) {
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = f->getVertex(lv);
        adj[v].push_back(f);
        int vs = vertexSupport(gf,v);
        if (vs == CORNER || vs == CURVE) {
          MVertex* vPrev = f->getVertex((4+lv-1)%4);
          MVertex* vNext = f->getVertex((lv+1)%4);
          SVector3 pNext = vNext->point();
          SVector3 pPrev = vPrev->point();
          SVector3 pCurr = v->point();
          double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
          vAngle[v] += agl;
        } 
      }
    }


    constexpr bool allowTemporaryDuet = true;

    /* Set vertices around corner to doNotDegrade */
    for (GVertex* gv: gf->vertices()) if (gv->mesh_vertices.size() > 0) {
      MVertex* v = gv->mesh_vertices[0];
      if (v == NULL) continue;
      int ideal = vertexIdealValence(v, vAngle);
      std::vector<MElement*>& quads = adj.at(v);
      if ((int) quads.size() == ideal) {
        std::vector<MVertex*> bnd;
        bool okb = buildBoundary(quads.begin(),quads.end(), bnd);
        if (okb) {
          for (MVertex* bv: bnd) {
            doNotDegrade.insert(bv);
          }
        }
      }
    }

    // TODO:
    // - check quality after smoothing / untangling ?
    // - repair curves if not interections with corner bnd ?
    size_t count[4] = {0,0,0,0};
    for (int pass: {CORNER, CURVE, SURFACE}) {
      if (pass == CORNER) {
        bool skipCorners = false;
        QMT_Utils::read_from_env("quadqsSkipCornerDefects", skipCorners);
        if (skipCorners) continue;
        Msg::Debug("- remove defects on corners ...");
      } else if (pass == CURVE) {
        bool skipCurves = false;
        QMT_Utils::read_from_env("quadqsSkipCurveDefects", skipCurves);
        if (skipCurves) continue;
        Msg::Debug("- remove defects on curves ...");
      } else if (pass == SURFACE) {
        bool skipInterior = false;
        QMT_Utils::read_from_env("quadqsSkipInteriorDefects", skipInterior);
        if (skipInterior) continue;
        Msg::Debug("- remove defects on interior ...");
      }

      std::priority_queue<std::pair<double,MVertex*>, std::vector<std::pair<double,MVertex*> > > Q; 

      /* Initialize the priority queue */
      initPriorityQueueWithDefects(pass, gf, adj, vAngle, Q);

      bool remaining = true;
      while (Q.size() > 0) {
        remaining = false;
        MVertex* v = Q.top().second;
        double prio = Q.top().first;
        Q.pop();
        size_t num = v->getNum();

        { /* Check if vertex still exists, may have been removed */
          auto it = adj.find(v);
          if (it == adj.end()) continue; 
        }

        int ideal = -1;
        std::vector<MElement*> quads;
        bool toRemesh = remeshableVertexProperties(gf, v, adj, vAngle, ideal, quads);
        if (!toRemesh) continue;
        int vs = vertexSupport(gf, v);

        /* Check if concave corner
         * Grow the cavity if was just two quads */
        if (pass == CORNER && vs == CORNER && ideal == 3) {
          if (quads.size() < 3) {
            bool tried = (tried_bigger_cavity.find(v) != tried_bigger_cavity.end());
            if (!tried) {
              growAroundQuads(adj, quads);

              /* Will retry without growing cavity */
              tried_bigger_cavity.insert(v);
              Q.push({prio,v});
            }
          }
        }

        /* Boundary around quads (includes v if on boundary) */
        std::vector<MVertex*> bnd;
        bool okb = buildBoundary(quads.begin(),quads.end(), bnd);
        if (bnd.size() > 0 && bnd.back() == bnd.front()) bnd.resize(bnd.size()-1);
        if (!okb || bnd.size() < 4) {
          GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
          if (gv != NULL) {
            Msg::Warning("failed to build boundary loop around vertex %li (on CAD corner %li)", num, gv->tag());
            continue;
          } else {
            Msg::Error("failed to build boundary around vertex %li, bnd.size()=%li", num, bnd.size());
            if (DBG_VIZU) {
              GeoLog::add(SVector3(v->point()),0.,"!failed_one_ring");
              GeoLog::flush();
            }
            continue;
          }
        }

        /* Build the cavity signature (ideal and allowed valences) which is required
         * to find replacements in disk quadrangulations */
        bool cancel = false;
        vector<int> bndIdealValence(bnd.size(),0);
        vector<std::pair<int,int> > bndAllowedValenceRange(bnd.size());
        for (size_t i = 0; i < bnd.size(); ++i) {
          MVertex* bv = bnd[i];
          int bvs = vertexSupport(gf,bv);
          bool onBdr = (bvs == CORNER || bvs == CURVE);
          int bival = 4;
          if (bvs == CORNER) {
            bival = vertexIdealValence(bv,vAngle);
          } else if (bvs == CURVE) {
            bival = 2;
          }
          std::vector<MElement*> bvAdjQuads = adj.at(bv);
          std::vector<MElement*> exterior = difference(bvAdjQuads, quads);
          bndIdealValence[i] = bival - int(exterior.size());
          if (exterior.size() == 0) { /* boundary vertex "inside" the cavity, probably the one to remesh */
            bndAllowedValenceRange[i] = {bival,bival};
          } else if (bvs == CORNER) {
            bndAllowedValenceRange[i] = {1,1}; 
          } else if (bvs == CURVE) {
            if (vs == CORNER) { /* When fixing corners, can degrade curves */
              bndAllowedValenceRange[i] = {1,2};
            } else {
              bndAllowedValenceRange[i] = {1,1};
            }
          } else if (bvs == SURFACE) {
            if (vs == CORNER || vs == CURVE) { /* When fixing corner/curve, can degrade surface */
              if (exterior.size() == 1) { /* warning: may generate quad duets, should check after */
                if (allowTemporaryDuet) {
                  bndAllowedValenceRange[i] = {1,6};  /* allow val 2, 6 and 7 */
                } else {
                  bndAllowedValenceRange[i] = {2,6};
                }
              } else if (exterior.size() == 2) { /* allow 6, 7 */
                bndAllowedValenceRange[i] = {1,5}; 
              } else if (exterior.size() == 3) { /* allow 6, 7 */
                bndAllowedValenceRange[i] = {1,4};
              } else if (exterior.size() == 4) {  /* allow 6, 7 */
                bndAllowedValenceRange[i] = {1,3}; 
              } else if (exterior.size() == 5) { /* allow 6, 7 */
                bndAllowedValenceRange[i] = {1,2}; 
              } else if (exterior.size() >= 6) { /* allow 7+, should minimize */
                bndAllowedValenceRange[i] = {1,1}; 
              }
              bool improveOnly = (doNotDegrade.find(bv) != doNotDegrade.end());
              if (improveOnly) {
                if (bvAdjQuads.size() == 4) { /* keep 4 */
                  int valIn = 4 - int(exterior.size());
                  bndAllowedValenceRange[i] = {valIn,valIn};
                } else if (bvAdjQuads.size() == 3) { /* -> 3, 4  */
                  if (exterior.size() == 1) {
                    bndAllowedValenceRange[i] = {2,3};
                  } else if (exterior.size() == 2) {
                    bndAllowedValenceRange[i] = {1,2};
                  } else {
                    cancel = true;
                    break;
                  }
                } else if (bvAdjQuads.size() == 5) { /* -> 4, 5  */
                  if (exterior.size() == 1) {
                    bndAllowedValenceRange[i] = {3,4};
                  } else if (exterior.size() == 2) {
                    bndAllowedValenceRange[i] = {2,3};
                  } else if (exterior.size() == 3) {
                    bndAllowedValenceRange[i] = {1,2};
                  } else if (exterior.size() == 4) {
                    bndAllowedValenceRange[i] = {1,1};
                  } else {
                    cancel = true;
                    break;
                  }
                }
              }
            } else {
              if (exterior.size() == 1) { /* warning: may generate quad duets, should check after */
                if (allowTemporaryDuet) {
                  bndAllowedValenceRange[i] = {1,4}; 
                } else {
                  bndAllowedValenceRange[i] = {2,4}; 
                }
              } else if (exterior.size() == 2) { /* avoid 6+ */
                bndAllowedValenceRange[i] = {1,3}; 
              } else if (exterior.size() == 3) { /* avoid 6+ */
                bndAllowedValenceRange[i] = {1,2}; 
              } else if (exterior.size() == 4) { /* avoid 6+ */
                bndAllowedValenceRange[i] = {1,1}; 
              } else if (exterior.size() >= 5) { /* bad, will generate 6+ ... */
                bndAllowedValenceRange[i] = {1,1}; 
              }
            }
          } else {
            Msg::Error("case not supported ... onBdr=%i, bvAdjQuads.size()=%li, exterior.size()=%li, ideal val=%i", onBdr, bvAdjQuads.size(), exterior.size(), ideal);
            if (DBG_VIZU) {
              GeoLog::add(SVector3(v->point()),0.,"!cns");
              geolog_closed_curve(bnd, "!cns");
              geolog_elements(quads,"!cns");
              geolog_elements(exterior,"!cns_ext");
              GeoLog::flush();
            }
            cancel = true;
          }
        }
        if (cancel) continue;

        /* Extract vertices inside cavity */
        std::vector<MVertex*> inside;
        verticesStrictlyInsideCavity(quads, bnd, inside);

        /* Get the remeshing with matching disk quadrangulation
         * (GFace is NOT modified by call to remeshFewQuads(), edition should confirmed after) */
        std::vector<MVertex*> newVertices;
        std::vector<bool> vertexIsIrregular;
        std::vector<MElement*> newElements;
        int status = remeshFewQuads(gf, bnd, bndIdealValence, bndAllowedValenceRange, 
            newVertices, vertexIsIrregular, newElements);
        if (status == 0) {
          /* Check if pattern is better (except if duet)*/
          bool duet = (vs == SURFACE && bnd.size() == 4 && quads.size() == 2 && newElements.size() != 2);
          if (!duet) {
            double energy_before = irregularityEnergyOfCavity(gf, bnd, bndIdealValence, bndAllowedValenceRange, inside, quads);
            double energy_after = irregularityEnergyOfCavity(gf, bnd, bndIdealValence, bndAllowedValenceRange, newVertices, newElements);
            if (energy_after >= energy_before) { /* cancel remeshing */
              Msg::Debug("disk quadrangulation rejected because irregularity energy would increase %f -> %f",
                  energy_before, energy_after);
              for (MVertex* nv: newVertices) delete nv;
              for (MElement* nf: newElements) delete nf;
              continue;
            }
          }

          /* Add the new elements to the current GFace */
          for (MVertex* nv: newVertices) gf->mesh_vertices.push_back(nv);
          for (MElement* nf: newElements) {
            gf->quadrangles.push_back(dynamic_cast<MQuadrangle*>(nf));
            addToAdjacencyList(gf, nf, adj);
          }
          /* Flag the boundary for improvement only */
          if (pass == CORNER) {
            for (MVertex* v: bnd) {
              doNotDegrade.insert(v);
            }
          }

          if (true && DBG_VIZU) {
            geolog_closed_curve(bnd, "scav_"+std::to_string(bnd.size())+"_"+std::to_string(num));
            geolog_elements(quads,"scav_"+std::to_string(bnd.size())+"_"+std::to_string(num));
            geolog_elements(newElements,"scav_"+std::to_string(bnd.size())+"_"+std::to_string(num)+"_rmsh");
            GeoLog::flush();
          }

          /* Remove old quads and old vertices (strictly inside) */
          for (MElement* f: quads) removeElement(gf, f, adj);
          for (MVertex* v2: inside) removeVertex(v2, adj);

          /* Check if there are duets in bnd */
          bool added_duet = false;
          for (size_t j = 0; j < bnd.size(); ++j) {
            MVertex* v2 = bnd[j];
            if (vertexSupport(gf,v2) == SURFACE && adj.at(v2).size() == 2) {
              /* Duet are high priority stuff ! */
              Q.push({DBL_MAX,v2});
              added_duet = true;
            }
          }

          /* Fill the priority queue */
          addAffectedVerticesToQueue(pass, gf, newElements, adj, vAngle, Q);
          remaining = true;

          if (PARANO && !added_duet) {
            bool valid = slowVerifyMeshIsValid(gf);
            if (!valid) {
              Msg::Error("invalid quad mesh");
              // return false;
            }
            // meshWinslow2d(gf, 10);
          }

          count[pass] += 1;

        } else {
          if (DBG_VIZU) {
            geolog_closed_curve(bnd, "!scav_P"+std::to_string(pass)+"_b"+std::to_string(bnd.size())+"_"+std::to_string(num));
            geolog_elements(quads, "!scav_P"+std::to_string(pass)+"_b"+std::to_string(bnd.size())+"_"+std::to_string(num));
            GeoLog::flush();
          }
          Msg::Warning("failed to remesh around vertex %li (cavity with %li bdr vertices, %li quads)", num,
              bnd.size(), quads.size());
        }
        if (Q.size() == 0 && remaining) { /* try again if there are still defects */
          initPriorityQueueWithDefects(pass, gf, adj, vAngle, Q);
        }
      }
    }

    if (count[CORNER] + count[CURVE] + count[SURFACE] > 0) {
      Msg::Info("- Face %i: remeshed %li corner defects, %li curve defects, %li interior defects (%li -> %li quads)", 
          gf->tag(), count[CORNER], count[CURVE], count[SURFACE], nq_in, gf->quadrangles.size());
    } else {
      return true;
    }

    bool meshok = slowVerifyMeshIsValid(gf);
    if (!meshok) {
      Msg::Error("face %i, mesh no longer valid after removing defects ... (should never happen)", gf->tag());
      // return false;
    }

    if (gf->quadrangles.size() < 1000) {
      Msg::Debug("-- Face %i: winslow smoothing (%li quads) ...", gf->tag(), gf->quadrangles.size());
      meshWinslow2d(gf, 10);
    }

    { /* final check */
      Msg::Debug("-- Face %i: counting remaining defects ...", gf->tag());
      for (auto& kv: adj) {
        MVertex* v = kv.first;
        int vs = vertexSupport(gf,v);
        if (vs == CORNER && kv.second.size() != (size_t) vertexIdealValence(v, vAngle))  {
          Msg::Warning("  - still defect at vertex %li: on corner but %li adj quads",
              v->getNum(), adj[v].size());
          if (DBG_VIZU) GeoLog::add(SVector3(v->point()),double(kv.second.size()),"defect_gf" + std::to_string(gf->tag()) + "_bdr_" + std::to_string(kv.second.size()));
        } else if (vs == CURVE && kv.second.size() != 2) {
          Msg::Warning("  - still defect at vertex %li: on boundary but %li adj quads",
              v->getNum(), adj[v].size());
          if (DBG_VIZU) GeoLog::add(SVector3(v->point()),double(kv.second.size()),"defect_gf" + std::to_string(gf->tag()) + "_bdr_" + std::to_string(kv.second.size()));
        } else if (vs == SURFACE) {
          if (kv.second.size() <= 2 || kv.second.size() > 5) {
            Msg::Warning("  - still defect at vertex %li: inside surface but %li adj quads",
                v->getNum(), adj[v].size());
            if (DBG_VIZU) GeoLog::add(SVector3(v->point()),double(kv.second.size()),"defect_gf" + std::to_string(gf->tag()) + "_int_" + std::to_string(kv.second.size()));
          }
        }
      }
      if (DBG_VIZU) GeoLog::flush();
    }

    return true;
  }

  bool remeshCavityWithQuadPatterns(GFace* gf, FCavity& cav, std::vector<MVertex*>& newSingularities,
      const std::vector<size_t>& patternsToCheck
      ) {
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

    Msg::Debug("remeshing cavity with %li quads, %li sides ...", cav.quads.size(), sides.size());

    std::vector<MElement*> newElements;
    std::vector<MVertex*> newVertices;
    std::vector<size_t> sideSizes(sides.size());
    for (size_t i = 0; i < sideSizes.size(); ++i) sideSizes[i] = sides[i].size();
    std::pair<size_t,int> patternNoAndRot;
    size_t Ncorners = sideSizes.size();
    double irreg;
    bool meshable = patchIsRemeshableWithQuadPattern(patternsToCheck,Ncorners, sideSizes, patternNoAndRot, irreg);
    if (meshable) {
      vector<MElement*> quads;
      quads.reserve(cav.quads.size());
      for (size_t f: cav.quads) {
        quads.push_back(M.faces[f].ptr);
      }

      std::vector<bool> vertexIsIrregular;
      int status = remeshPatchWithQuadPattern(gf, sides, patternNoAndRot, quads, newVertices, vertexIsIrregular, newElements);
      if (status != 0) {
        Msg::Error("Face %li, failed to remesh with selected quad pattern, weird", gf->tag());
        return 1;
      }

      /* Check orientation of the remeshed cavity compared to input,
       * and invert if required */
      /* - oriented boundary */
      unordered_set<si2,si2hash> oedges;
      oedges.insert({sides[0][0]->getNum(),sides[0][1]->getNum()});
      // for (size_t i = 0; i < bnd.size()-1; ++i) {
      //   oedges.insert({bnd[i]->getNum(),bnd[i+1]->getNum()});
      // }
      bool found = false;
      bool orientation_ok = true;
      for (MElement* f: newElements) {
        for (size_t le = 0; le < 4; ++le) {
          size_t v1 = f->getVertex(le)->getNum();
          size_t v2 = f->getVertex((le+1)%4)->getNum();
          si2 vPair = {v1,v2};
          auto it = oedges.find(vPair);
          if (it != oedges.end()) {
            found = true;
            orientation_ok = true;
            break;
          }
          si2 vPairInv = {v2,v1};
          auto it2 = oedges.find(vPairInv);
          if (it2 != oedges.end()) {
            found = true;
            orientation_ok = false;
            break;
          }
        }
        if (found) break;
      }
      if (!found) {
        Msg::Error("common edge not found ! cannot check orientation");
      }
      if (!orientation_ok) { /* Invert quads ! */
        for (MElement* f: newElements) {
          MVertex* v1 = f->getVertex(1);
          MVertex* v3 = f->getVertex(3);
          f->setVertex(1,v3);
          f->setVertex(3,v1);
        }
      }

      /* Update singularities */
      vector<MVertex*> ivert;
      for (size_t i = 0; i < newVertices.size(); ++i) if (vertexIsIrregular[i]) {
        ivert.push_back(newVertices[i]);
      }
      if (ivert.size() == 1) {
        if (Ncorners == 3) {
          newSingularities.push_back(ivert[0]);
        } else if (Ncorners == 5) {
          newSingularities.push_back(ivert[0]);
        }
      }
    } 

    if (newElements.size() > 0) {
      if (newElements.size() < 1000) { // TODO: a fast smoothing... somehow
        Msg::Debug("-- Winslow smoothing of cavity (%li quads) ...", newElements.size());
        vector<MQuadrangle*> quadForWinslow(newElements.size());
        for (size_t i = 0; i < newElements.size(); ++i) {
          quadForWinslow[i] = dynamic_cast<MQuadrangle*>(newElements[i]);
        }
        meshWinslow2d(gf, quadForWinslow, newVertices, 10);
      }
    }

    if (SHOW_CAVITIES) {
      std::string cavity_name = "cav_s"+std::to_string(sideSizes.size())+"_after";
      geolog_elements(newElements, cavity_name);
      GeoLog::flush();
    }

    return true;
  }


  int remeshCavitiesAroundSingularities(GFace* gf, std::vector<MVertex*>& singularVertices, 
      const std::vector<size_t>& patternsToCheck) 
  {
    Msg::Debug("- Face %i: remeshCavitiesAroundSingularities ...", gf->tag());

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
      int st = createMeshHalfEdges(gf->quadrangles, M, singularVertices);
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
          Msg::Error("remeshCavitiesAroundSingularities: failed to init cavity");
          continue;
        }
        // geolog_fcavity(fcav, "fcav"+std::to_string(v)+"_init");

        /* Build a cavity around singularity i */
        G.setCavity(fcav);

        bool okg = G.growMaximal(patternsToCheck);
        if (!okg) continue;

        if (SHOW_CAVITIES) {
          fcav.updateSides();
          std::string cavity_name = "cav_s"+std::to_string(quads.size())+"_"+std::to_string(v);
          geolog_fcavity(fcav, cavity_name + "_before");
        }

        /* Remesh the cavity */
        std::vector<MVertex*> newSingularities;
        size_t nq = gf->quadrangles.size();
        bool okr = remeshCavityWithQuadPatterns(gf,fcav,newSingularities,patternsToCheck);
        if (okr) { /* then cavity and M are no longer valid, restart */
          size_t nq2 = gf->quadrangles.size();
          if (nq2 == nq)  {
            Msg::Warning("same number of quads in GFace after remeshing... weird");
          }

          /* update list of singular nodes */
          auto itv = std::find(singularVertices.begin(),singularVertices.end(),M.vertices[v].ptr);
          if (itv != singularVertices.end()) {
            singularVertices.erase(itv);
          }
          for (MVertex* v2: newSingularities) {
            singularVertices.push_back(v2);
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
      if (gf->quadrangles.size() < 1000) {
        Msg::Debug("-- Winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
        meshWinslow2d(gf, 10);
      }
      Msg::Info("- Face %i: remeshed %li cavities around singularities ...", gf->tag(), count);
    }

    return 0;
  }

  /*
     +-------------------+
     |3   <   2|        6|
     |        ^|         |  <- getLeftRightAlong35Path()
     |4   >   1|        5|
     +-------------------+
     |2      1/ \       7|
     |       /   \       |
     |      /     \      |  <- getStartOf35Path()
     |3   4/       \5   6|
     +----+         +----+
     |    |\       /|    |
     |    | \     / |    |
     |    |  \   /  |    |
     |    |   \8/   |    |
     |    |    |    |    |
     |    |    |    |    |
     +----+----+----+----+
  */
  bool getStartOf35Path(MeshHalfEdges& M, size_t he, 
      GFace*& gf, MQuadrangle*& qLeft, MQuadrangle*& qRight, MQuadrangle*& q35,
      std::vector<MVertex*>& vert) {
    vert.clear();
    vert.resize(9,NULL);
    size_t hel = M.opposite(M.prev(he));
    vert[1] = M.vertexPtr(hel,0);
    vert[2] = M.vertexPtr(hel,1);
    vert[3] = M.vertexPtr(M.next(hel),1);
    vert[4] = M.vertexPtr(M.prev(hel),0);
    size_t her = M.opposite(M.next(M.opposite(he)));
    vert[5] = M.vertexPtr(M.next(her),1);
    vert[6] = M.vertexPtr(M.prev(her),0);
    vert[7] = M.vertexPtr(M.prev(her),1);
    vert[8] = M.vertexPtr(M.next(M.opposite(M.prev(hel))),1);
    bool ok = (vert[1] != NULL && vert[2] != NULL && vert[3] != NULL 
        && vert[4] != NULL && vert[5] != NULL && vert[6] != NULL && vert[7] != NULL);
    if (!ok) return false;
    gf = dynamic_cast<GFace*>(vert[1]->onWhat());
    if (gf == NULL) return false;
    qLeft = dynamic_cast<MQuadrangle*>(M.facePtr(hel));
    qRight = dynamic_cast<MQuadrangle*>(M.facePtr(her));
    q35 = dynamic_cast<MQuadrangle*>(M.facePtr(M.opposite(M.prev(hel))));
    if (qLeft == NULL || qRight == NULL || q35 == NULL) return false;
    return true;
  }

  bool getLeftRightAlong35Path(MeshHalfEdges& M, size_t he, 
      GFace*& gf, MQuadrangle*& qLeft, MQuadrangle*& qRight,
      std::vector<MVertex*>& vert) {
    vert.clear();
    vert.resize(7,NULL);
    vert[1] = M.vertexPtr(he,0);
    vert[2] = M.vertexPtr(he,1);
    vert[3] = M.vertexPtr(M.next(he),1);
    vert[4] = M.vertexPtr(M.prev(he),0);
    size_t he_op = M.opposite(he);
    vert[5] = M.vertexPtr(M.next(he_op),1);
    vert[6] = M.vertexPtr(M.prev(he_op),0);
    bool ok = (vert[1] != NULL && vert[2] != NULL && vert[3] != NULL 
        && vert[4] != NULL && vert[5] != NULL && vert[6] != NULL);
    if (!ok) return false;
    qLeft = dynamic_cast<MQuadrangle*>(M.facePtr(he));
    qRight = dynamic_cast<MQuadrangle*>(M.facePtr(he_op));
    if (qLeft == NULL || qRight == NULL) return false;
    /* Get the face */
    for (size_t i = 1; i < vert.size(); ++i) {
      gf = dynamic_cast<GFace*>(vert[i]->onWhat());
      if (gf != NULL) break;
    }
    if (gf == NULL) return false;
    return true;
  }

  bool cancelAddQuadsAlong35Path(
    std::vector<std::array<MVertex*,2> >& newVertices,
    unordered_map<GFace*,vector<MQuadrangle*> >& newQuads) {
    for (auto& a: newVertices) for(auto& b: a) {
      if (b != NULL) delete b;
    }
    for (auto& a: newQuads) for(auto& b: a.second) {
      if (b != NULL) delete b;
    }
    newVertices.clear();
    newQuads.clear();
    return false;
  }

  bool createNewVerticesAlong35Path(
      MeshHalfEdges& M,
      std::vector<size_t>& path,
      std::vector<std::array<MVertex*,2> >& newVertices,
      std::vector<GFace*>& pathFaces) {
    if (path.size() < 1) return false;
    pathFaces.clear();
    pathFaces.resize(path.size(),NULL);
    newVertices.clear();
    newVertices.resize(path.size(),{NULL,NULL});
    /* Path start/end check */
    {
      MVertex* vStart = M.vertexPtr(path[0],0);
      pathFaces[0] = dynamic_cast<GFace*>(vStart->onWhat());
      if (pathFaces[0] == NULL) return false;
      MVertex* vLast0 = M.vertexPtr(path.back(),0);
      MVertex* vLast1 = M.vertexPtr(path.back(),1);
      GFace* gfLast0 = dynamic_cast<GFace*>(vLast0->onWhat());
      GFace* gfLast1 = dynamic_cast<GFace*>(vLast1->onWhat());
      if (gfLast0 == NULL || gfLast1 == NULL || gfLast0 != gfLast1) return false;
    }
    /* Fill the datastructures along path */
    vector<MVertex*> vert;
    for (size_t i = 0; i < path.size(); ++i) {
      size_t he = path[i];
      GFace* gf = NULL;
      MQuadrangle* qLeft = NULL;
      MQuadrangle* qRight = NULL;
      bool oks = getLeftRightAlong35Path(M, he, gf, qLeft, qRight, vert);
      if (!oks) {
        unordered_map<GFace*,vector<MQuadrangle*> > dummy;
        return cancelAddQuadsAlong35Path(newVertices, dummy);
      }
      pathFaces[i] = gf;
      SVector3 pa = 0.5 * (vert[1]->point() + vert[4]->point());
      SVector3 pb = 0.5 * (vert[1]->point() + vert[5]->point());
      GFace* gf1 = dynamic_cast<GFace*>(vert[1]->onWhat());
      if (gf1) {
        double uu,vv;
        vert[1]->getParameter(0,uu);
        vert[1]->getParameter(1,vv);
        MVertex *va = new MFaceVertex(pa.x(),pa.y(),pa.z(),gf,uu,vv);
        MVertex *vb = new MFaceVertex(pb.x(),pb.y(),pb.z(),gf,uu,vv);
        newVertices[i][0] = va;
        newVertices[i][1] = vb;
      } else {
        GEdge* ge = dynamic_cast<GEdge*>(vert[1]->onWhat());
        if (ge) {
          double t;
          vert[1]->getParameter(0,t);
          MVertex *va = new MEdgeVertex(pa.x(),pa.y(),pa.z(),ge,t);
          MVertex *vb = new MEdgeVertex(pb.x(),pb.y(),pb.z(),ge,t);
          newVertices[i][0] = va;
          newVertices[i][1] = vb;
          // TODO: need to create two MLine
        } else {
          Msg::Error("addQuadsAlong35Path: cannot split a corner");
          unordered_map<GFace*,vector<MQuadrangle*> > dummy;
          return cancelAddQuadsAlong35Path(newVertices, dummy);
        }
      }
    }

    return true;
  }

  bool addQuadsAlong35Path(
      GModel* gm,
      MeshHalfEdges& M,
      std::vector<size_t>& path) {
    if (path.size() == 0) return false;


    /* New mesh components, add them at the end if no issue along the path */
    unordered_map<GFace*,vector<MQuadrangle*> > newQuads;
    std::vector<std::array<MVertex*,2> > newVertices(path.size());
    vector<GFace*> pathFaces;
    bool okInit = createNewVerticesAlong35Path(M, path, newVertices, pathFaces);
    if (!okInit) {
      return cancelAddQuadsAlong35Path(newVertices,newQuads);
    }

    unordered_map<GFace*,vector<MQuadrangle*> > quadsToRemove;
    /* Modify the start of the path */
    {
      size_t he0 = path[0];
      GFace* gf = NULL;
      vector<MVertex*> vert;
      MQuadrangle* qLeft = NULL;
      MQuadrangle* qRight = NULL;
      MQuadrangle* q35 = NULL;
      bool oks = getStartOf35Path(M, he0, gf, qLeft, qRight, q35, vert);
      if (!oks) {
        Msg::Error("addQuadsAlong35Path | issue with mesh at start of path");
        return cancelAddQuadsAlong35Path(newVertices,newQuads);
      }
      vector<MQuadrangle*>& gfRemove = quadsToRemove[gf];
      gfRemove.push_back(qLeft);
      gfRemove.push_back(qRight);
      gfRemove.push_back(q35);

      MQuadrangle* rqLeft = new MQuadrangle(vert[3],vert[4],newVertices[0][0],vert[2]);
      MQuadrangle* rqRight = new MQuadrangle(vert[5],vert[6],vert[7],newVertices[0][1]);
      MQuadrangle* nqLeft = new MQuadrangle(vert[8],M.vertexPtr(he0,0),newVertices[0][0],vert[4]);
      MQuadrangle* nqRight = new MQuadrangle(vert[8],vert[5],newVertices[0][1],M.vertexPtr(he0,0));
      vector<MQuadrangle*>& gfNewQuads = newQuads[gf];
      gfNewQuads.push_back(rqLeft);
      gfNewQuads.push_back(rqRight);
      gfNewQuads.push_back(nqLeft);
      gfNewQuads.push_back(nqRight);
    }

    /* Modify the end of the path */
    {
      size_t heL = path.back();
      GFace* gf = NULL;
      vector<MVertex*> vert;
      MQuadrangle* qLeft = NULL;
      MQuadrangle* qRight = NULL;
      bool oks = getLeftRightAlong35Path(M, heL, gf, qLeft, qRight, vert);
      if (!oks) {
        Msg::Error("addQuadsAlong35Path | issue with mesh at end of path");
        return cancelAddQuadsAlong35Path(newVertices,newQuads);
      }
      MVertex* va = newVertices.back()[0];
      MVertex* vb = newVertices.back()[1];
      MQuadrangle* nq = new MQuadrangle(vert[1],vb,vert[2],va);
      MQuadrangle* nql = new MQuadrangle(va,vert[2],vert[3],vert[4]);
      MQuadrangle* nqr = new MQuadrangle(vb,vert[5],vert[6],vert[2]);
      vector<MQuadrangle*>& gfNewQuads = newQuads[gf];
      gfNewQuads.push_back(nq);
      gfNewQuads.push_back(nql);
      gfNewQuads.push_back(nqr);
      vector<MQuadrangle*>& gfRemove = quadsToRemove[gf];
      gfRemove.push_back(qLeft);
      gfRemove.push_back(qRight);
    }

    /* Modify the quads inside the path */
    if (path.size() >= 2) {
      for (size_t i = 0; i < path.size()-1; ++i) {
        size_t he = path[i];
        GFace* gf = NULL;
        vector<MVertex*> vert;
        MQuadrangle* qLeft = NULL;
        MQuadrangle* qRight = NULL;
        bool oks = getLeftRightAlong35Path(M, he, gf, qLeft, qRight, vert);
        if (!oks) {
          Msg::Error("addQuadsAlong35Path | issue with mesh inside the path");
          return cancelAddQuadsAlong35Path(newVertices,newQuads);
        }
        MVertex* va1 = newVertices[i][0];
        MVertex* vb1 = newVertices[i][1];
        MVertex* va2 = newVertices[i+1][0];
        MVertex* vb2 = newVertices[i+1][1];
        MQuadrangle* nq1 = new MQuadrangle(vert[3],vert[4],va1,va2);
        MQuadrangle* nq2 = new MQuadrangle(vert[1],vert[2],va2,va1);
        MQuadrangle* nq3 = new MQuadrangle(vert[2],vert[1],vb1,vb2);
        MQuadrangle* nq4 = new MQuadrangle(vert[5],vert[6],vb2,vb1);
        vector<MQuadrangle*>& gfNewQuads = newQuads[gf];
        gfNewQuads.push_back(nq1);
        gfNewQuads.push_back(nq2);
        gfNewQuads.push_back(nq3);
        gfNewQuads.push_back(nq4);
        vector<MQuadrangle*>& gfRemove = quadsToRemove[gf];
        gfRemove.push_back(qLeft);
        gfRemove.push_back(qRight);
      }
    }

    /* Apply the modifications */
    for (auto& kv: quadsToRemove) {
      GFace* gf = kv.first;
      sort_unique(kv.second);
      for (MQuadrangle*& q: kv.second) {
        auto it = std::find(gf->quadrangles.begin(),gf->quadrangles.end(), q);
        if (it != gf->quadrangles.end()) {
          gf->quadrangles.erase(it);
        }
        if (q != NULL) {
          delete q;
          q = NULL;
        }
      }
    }
    for (auto& kv: newQuads) {
      GFace* gf = kv.first;
      for (MQuadrangle* q: kv.second) {
        gf->addQuadrangle(q);
      }
    }
    for (size_t i = 0; i < newVertices.size(); ++i) {
      for (size_t lv = 0; lv < 2; ++lv) {
        MVertex* v = newVertices[i][lv];
        GEntity* ent = v->onWhat();
        ent->addMeshVertex(v);
      }
    }

    /* Update the half edge datastructure */
    {
      // TODO
    }

    return true;
  }

  int propagate35(GModel* gm, std::vector<MVertex*>& singularVertices) {
    vector<MQuadrangle*> quadrangles;
    for (GFace* gf: model_faces(gm)) {
      append(quadrangles, gf->quadrangles);
    }
    Msg::Info("propagate 35 pairs on %li faces (total: %li quads)", gm->getFaces().size(), quadrangles.size());
    bool oko = reorientQuadranglesIfNecessary(quadrangles);
    if (!oko) {
      Msg::Error("failed to re-orient quads");
    }

    MeshHalfEdges M;
    vector<size_t> pairs35;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;
    std::unordered_set<MVertex*> vIs3Of35Pair;
    std::unordered_set<MVertex*> vIs5Of35Pair;

    /* singularNodes is the list of singularities (irregular vertices to keep) in the 
     * GFace structure, the values are the vertex 'num' */
    int st = createMeshHalfEdges(quadrangles, M, singularVertices);
    if (st != 0) {
      Msg::Error("failed to generate half edge datastructure");
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
      vector<size_t> vertIn35;
      vector<size_t> fvert;
      const array<int,4> indices35 = {3,4,5,4};
      array<int,4> quadIndices = {0,0,0,0};
      for (size_t f = 0; f < M.faces.size(); ++f) {
        size_t n = M.face_vertices(f,fvert);
        if (n != 4) {
          Msg::Error("face %li is not a quad ? %li vertices", f, n);
          return false;
        }
        bool cancel = false;
        for (size_t lv = 0; lv < n; ++lv) {
          quadIndices[lv] = G.valence[fvert[lv]];
          if (quadIndices[lv] != 4) {
            MVertex* v = M.vertices[fvert[lv]].ptr;
            bool interior = (dynamic_cast<GFace*>(v->onWhat()) != NULL);
            if (!interior) cancel = true;
          }
        }
        if (cancel) continue;
        quadIndices = rotateCanonical(quadIndices);
        if (quadIndices == indices35) {
          pairs35.push_back(f);
          append(vertIn35,fvert);
          for (size_t lv = 0; lv < n; ++lv) {
            if (G.valence[fvert[lv]] == 3) {
              vIs3Of35Pair.insert(M.vertices[fvert[lv]].ptr);
            } else if (G.valence[fvert[lv]] == 5) {
              vIs5Of35Pair.insert(M.vertices[fvert[lv]].ptr);
            }
          }
        }
      }
      /* remove irregular nodes of 3-5 from list */
      irregularNodes = difference(irregularNodes, vertIn35); 
    }

    vector<size_t> fvert;
    for (size_t f: pairs35) {
      size_t heStart = NO_ID;
      // size_t v0 = NO_ID;
      M.face_vertices(f,fvert);
      size_t he = M.faces[f].he;
      for (size_t le = 0; le < 4; ++le) {
        size_t v = M.vertex(he,1);
        if (G.valence[v] == 5) {
          // v0 = v;
          heStart = M.next(M.opposite(M.next(M.opposite(M.next(he)))));
          break;
        }
        he = M.next(he);
      }
      if (heStart == NO_ID) continue;

      vector<size_t> path;
      he = heStart;
      while (true) {
        path.push_back(he);

        size_t v2 = M.vertex(he,2);
        // if (G.valence[v2] == 3 && vIs3Of35Pair.find(M.vertices[v2].ptr) != vIs3Of35Pair.end()) {
        //   break;
        // }
        // if (G.valence[v2] == 5 && vIs5Of35Pair.find(M.vertices[v2].ptr) != vIs5Of35Pair.end()) {
        //   break;
        // }

        int index = (G.vOnBoundary[v2]) ?  2 - G.valence[v2] : 4 - G.valence[v2];
        bool regular = (index == 0);
        if (!regular) break;

        size_t he2 = M.next(M.opposite(M.next(he)));
        if (he2 == NO_ID) { /* try the other way */
          he2 = M.opposite(M.prev(M.opposite(M.prev(M.opposite(he)))));
          if (he2 == NO_ID) break;
        }
        he = he2;
      }

      for (size_t i = 0; i < path.size(); ++i) {
        geolog_halfedge(M, path[i], double(i), "path_"+std::to_string(heStart));
      }
      GeoLog::flush();

      addQuadsAlong35Path(gm, M, path);

      return 0;
    }

    return 0;
  }

  bool buildQuadMeshBaseComplex(GModel* gm) {
    vector<MQuadrangle*> quadrangles;
    for (GFace* gf: model_faces(gm)) {
      append(quadrangles, gf->quadrangles);
    }
    Msg::Info("build quad mesh base complex on %li faces (total: %li quads)", gm->getFaces().size(), quadrangles.size());
    bool oko = reorientQuadranglesIfNecessary(quadrangles);
    if (!oko) {
      Msg::Error("failed to re-orient quads");
    }

    MeshHalfEdges M;

    /* singularNodes is the list of singularities (irregular vertices to keep) in the 
     * GFace structure, the values are the vertex 'num' */

    vector<MVertex*> singularVertices;
    int st = createMeshHalfEdges(quadrangles, M, singularVertices);
    if (st != 0) {
      Msg::Error("failed to generate half edge datastructure");
      return st;
    }

    /* Loop over interior irregular vertices, trace seperatrices */
    double count = 0.;
    Gardener G(M);
    std::vector<size_t> hesStart;
    vector<bool> isBCEdge(M.hedges.size(),false);
    for (size_t v = 0; v < M.vertices.size(); ++v) {
      if (G.vOnBoundary[v]) continue;
      if (G.valence[v] == 4) continue;

      M.vertexHalfEdges(v, hesStart);
      for (size_t a: hesStart) {
        size_t he0 = M.opposite(a);
        if (he0 == NO_ID) continue;
        if (isBCEdge[he0]) continue;

        count += 1.;
        vector<size_t> path;
        size_t he = he0;
        while (true) {
          path.push_back(he);
          size_t v2 = M.vertex(he,2);
          int index = (G.vOnBoundary[v2]) ?  2 - G.valence[v2] : 4 - G.valence[v2];
          bool regular = (index == 0);
          if (!regular) break;

          size_t he2 = M.next(M.opposite(M.next(he)));
          if (he2 == NO_ID) { /* try the other way */
            he2 = M.opposite(M.prev(M.opposite(M.prev(M.opposite(he)))));
            if (he2 == NO_ID) break;
          }
          he = he2;
        }

        for (size_t hep: path) {
          isBCEdge[hep] = true;
          size_t hop = M.opposite(hep);
          if (hop != NO_ID) isBCEdge[hop] = true;
          geolog_halfedge(M, hep, double(0.), "base_complex");
          // geolog_halfedge(M, hep, double(count), "base_complex");
        }
      }
    }

    /* Quad colors via BFS */
    {
      std::vector<int> color(M.faces.size(),0);
      int colorCount = 0;
      std::vector<size_t> qhes;
      for (size_t f0 = 0; f0 < M.faces.size(); ++f0) if (color[f0] == 0) {
        colorCount += 1;
        std::queue<size_t> Q;
        Q.push(f0);
        color[f0] = colorCount;

        while (Q.size()) {
          size_t f = Q.front();
          color[f] = colorCount;
          Q.pop();
          size_t he = M.faces[f].he;
          do {
            he = M.hedges[he].next;
            if (!isBCEdge[he]) {
              size_t he_op = M.opposite(he);
              if (he_op == NO_ID) continue;
              size_t f_op = M.hedges[he_op].face;
              if (color[f_op] == 0) {
                color[f_op] = colorCount;
                Q.push(f_op);
              }
            }
          } while (he != M.faces[f].he);
        }
      }
      Msg::Info("%i partitions in base complex (%li CAD faces, %li quads)",
          colorCount, model_faces(gm).size(), M.faces.size());
      for (size_t f = 0; f < M.faces.size(); ++f) {
        MElement* elt = M.faces[f].ptr;
        geolog_elements({elt}, "base_complex", double(color[f]));
      }
    }

    gmsh::initialize();
    GeoLog::flush();

    return true;
  }

  bool getQuadsAjacentToGEdges(
      MeshHalfEdges& M,
      const vector<GEdge*>& gedges,
      std::unordered_map<GEdge*,vector<size_t> >& geQuads) {
    for (size_t f = 0; f < M.faces.size(); ++f) {
      MElement* elt = M.faces[f].ptr;
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v = elt->getVertex(lv);
        GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
        if (ge != NULL && !ge->periodic(0)) {
          geQuads[ge].push_back(f);
        }
      }
    }
    return true;

    // std::unordered_map<si2,size_t,si2hash> vPairToHalfEdges;
    // for (size_t he = 0; he < M.hedges.size(); ++he) if (M.opposite(he) == NO_ID) {
    //   size_t v1 = M.vertexPtr(he,0)->getNum();
    //   size_t v2 = M.vertexPtr(he,1)->getNum();
    //   si2 vPair = sorted(v1,v2);
    //   vPairToHalfEdges[vPair] = he;
    // }
    // vector<size_t> _tmp;
    // for (GEdge* ge: gedges) {
    //   if (ge->periodic(0)) continue;
    //   vector<size_t>& quads = geQuads[ge];
    //   quads.reserve(ge->lines.size());
    //   for (size_t i = 0; i < ge->lines.size(); ++i) {
    //     size_t v1 = ge->lines[i]->getVertex(0)->getNum();
    //     size_t v2 = ge->lines[i]->getVertex(1)->getNum();
    //     si2 vPair = sorted(v1,v2);
    //     auto it = vPairToHalfEdges.find(vPair);
    //     if (it != vPairToHalfEdges.end()) {
    //       size_t he = it->second;
    //       size_t q = M.hedges[he].face;
    //       quads.push_back(q);
    //       bool onBdr = true;

    //       /* Special care if valence >2 on line */
    //       MVertex* mv = ge->lines[i]->getVertex(1);
    //       GEdge* gec = dynamic_cast<GEdge*>(mv->onWhat());
    //       if (gec != NULL) {
    //         size_t M_v = M.vertex(he,1);
    //         if (M.vertexFaceValence(M_v,onBdr) > 2) {
    //           M.vertexFaces(M_v,_tmp);
    //           for (size_t q2: _tmp) {
    //             quads.push_back(q2);
    //           }
    //         }
    //       }
    //     }
    //   }
    //   sort_unique(quads);
    // }

    return true;
  }

  int remeshQuadrilateralPatches(GFace* gf, std::vector<MVertex*>& singularVertices,
      const std::vector<size_t>& patternsToCheck) {
    Msg::Debug("- Face %i: remeshing quadrilateral cavities  ...", gf->tag());

    /* Remeshing parameters */
    const std::vector<std::pair<size_t,size_t> > patternSizeLimits = {
      {PATTERN_QUAD_DIAG35,100},
      {PATTERN_QUAD_ALIGNED35,100},
      {PATTERN_QUAD_CHORD_UTURN,100},
    };

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> pairs35;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;

    size_t count = 0;
    const size_t PASS_ALONG_GEDGES = 1;
    const size_t PASS_FROM_IRREGULAR = 2;
    for (size_t pass : {PASS_ALONG_GEDGES, PASS_FROM_IRREGULAR}) {
      Msg::Debug("-- pass %li (0 = along GEdge, 1 = from irregular vertices)", pass);
      std::unordered_set<void*> tried;
      bool inProgress = true;
      while (inProgress) {
        inProgress = false;

        /* singularNodes is the list of singularities (irregular vertices to keep) in the 
         * GFace structure */
        int st = createMeshHalfEdges(gf->quadrangles, M, singularVertices);
        if (st != 0) {
          Msg::Error("failed to generate half edge datastructure for face with tag %i", gf->tag());
          return st;
        }
        Gardener G(M);

        std::vector<std::pair<double, std::pair<void*,std::vector<size_t> > > > prio_quads;

        if (pass == PASS_ALONG_GEDGES) {
          std::unordered_map<GEdge*,vector<size_t> > geQuads;
          bool ok = getQuadsAjacentToGEdges(M, gf->edges(), geQuads);
          if (!ok) {
            break;
          }

          for (auto& kv: geQuads) {
            GEdge* ge = kv.first;
            vector<size_t> quads = kv.second;
            if (quads.size() == 0) continue;
            double prio = 1. - double(ge->lines.size());
            sort_unique(quads);
            prio_quads.push_back({prio,{(void*)(ge),quads}});
          }
        } else if (pass == PASS_FROM_IRREGULAR) {
          constexpr bool rejectOnBdr = true;
          constexpr bool rejectOnSing = true;
          vector<size_t> fvert;
          for (size_t f = 0; f < M.faces.size(); ++f) {
            M.face_vertices(f,fvert);
            double irreg = 0;
            for (size_t v: fvert) {
              int reg = G.vOnBoundary[v] ? 2 : 4;
              irreg += std::pow(G.valence[v] - reg,2);
              if (rejectOnBdr && reg == 2) {
                irreg = 0.;
                break;
              }
              if (rejectOnSing && M.vertices[v].isSingularity) {
                irreg = 0.;
                break;
              }
            }
            if (irreg != 0.) {
              prio_quads.push_back({irreg,{(void*)M.faces[f].ptr,{f}}});
            }
          }
        }
        if (prio_quads.size() == 0) break;
        std::sort(prio_quads.begin(),prio_quads.end());
        std::reverse(prio_quads.begin(),prio_quads.end());

        /* Try the cavities */
        for (size_t i = 0; i < prio_quads.size(); ++i) {
          void* ptr = prio_quads[i].second.first;
          if (ptr == NULL) continue;
          bool alreadyTried = (tried.find(ptr) != tried.end());
          if (alreadyTried) continue;;
          /* Init */
          tried.insert(ptr);
          FCavity fcav(M);
          const vector<size_t>& quads = prio_quads[i].second.second;
          bool ok = fcav.init(quads);
          if (!ok) {
            Msg::Warning("remeshQuadrilateralPatches: failed to init cavity (%li quads)", quads.size());
            if (SHOW_CAVITIES) {
              geolog_fcavity(fcav, "!cav_init");
            }
            continue;
          }

          /* Build a cavity around singularity i */
          G.setCavity(fcav);
          G.cavityTargetNbOfSides = 4;

          bool okg = G.growMaximal(patternsToCheck, patternSizeLimits);
          if (!okg) continue;

          std::string cavity_name = "cav_s"+std::to_string(quads.size());
          if (SHOW_CAVITIES) {
            fcav.updateSides();
            geolog_fcavity(fcav, cavity_name + "_before");
          }

          /* Remesh the cavity */
          std::vector<MVertex*> newSingularities;
          size_t nq = gf->quadrangles.size();

          bool okr = remeshCavityWithQuadPatterns(gf,fcav,newSingularities,patternsToCheck);
          if (okr) { /* then cavity and M are no longer valid, restart */
            size_t nq2 = gf->quadrangles.size();
            if (nq2 == nq)  {
              Msg::Warning("same number of quads in GFace after remeshing... weird");
            } else {
              inProgress = true;
            }
            count += 1;
            break;
          } else {
            Msg::Info("-> failed to remesh cavity");
            geolog_fcavity(fcav, "!" + cavity_name);
          }
        }
      }
    }

    if (count > 0) {
      if (gf->quadrangles.size() < 1000) {
        Msg::Debug("-- Winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
        meshWinslow2d(gf, 10);
      }
      Msg::Info("- Face %i: remeshed %li quadrilateral cavities  ...", gf->tag(), count);
    }

    return 0;
  }

  int meshSimpleFaceWithPattern(GFace* gf, const GFaceInfo& info,
      bool onlyCheckIfMeshable = false,
      bool checkTheSubdivision = false) {
    vector<GEdge *> const &edges = gf->edges();

    unordered_map<GVertex*,vector<GEdge*> > v2e;
    for (GEdge* ge: edges) {
      if (ge->periodic(0)) continue;
      for (GVertex* gv: ge->vertices()) v2e[gv].push_back(ge);
    }
    for (auto& kv: v2e) { sort_unique(kv.second); }

    std::set<GVertex*> corners = info.bdrValVertices[1];
    bool disk = (corners.size() == 0 && info.bdrValVertices[2].size() > 0);
    // TODO check geometric convexity of the disk ... should not apply on
    //      faces with lot of convex and concave curves
    
    // if (!disk) return 1; // DEBUGING TODO REMOVE

    /* Sort CAD edges in sides */
    vector<vector<GEdge*> > sides;
    vector<vector<bool> > sidesInv;
    for (GEdge* e0: edges) if (!e0->periodic(0)) {
      GVertex* v1 = e0->vertices()[0];
      GVertex* v2 = e0->vertices()[1];
      bool v1IsCorner = (corners.find(v1) != corners.end());
      if (!disk && !v1IsCorner) continue;
      if (disk) {
        sides.resize(1);
        sidesInv.resize(1);
      }

      size_t infLoop = 0;
      GVertex* v = v1;
      GEdge* e = e0;
      bool inv = false;
      do {
        infLoop += 1;
        if (infLoop > 1e6) {
          Msg::Warning("infinite loop in edges of face %i, cancel simple quad mesh", gf->tag());
          return -1;
        }
        bool vIsCorner = (corners.find(v) != corners.end());
        if (vIsCorner) {
          sides.resize(sides.size()+1);
          sidesInv.resize(sidesInv.size()+1);
        }
        v1 = e->vertices()[0];
        v2 = e->vertices()[1];

        inv = (v == v2);

        sides.back().push_back(e);
        sidesInv.back().push_back(inv);

        GVertex* v_next = NULL;
        if (v2 != v) {
          v_next = v2;
        } else {
          v_next = v1;
        }
        GEdge* e_next = NULL;
        if (v2e[v_next].size() == 2) {
          e_next = (v2e[v_next][0] != e) ? v2e[v_next][0] : v2e[v_next][1];
        } else {
          Msg::Warning("non manifold edge loop around face %li, cancel simple quad mesh", gf->tag());
          return -1;
        }

        e = e_next;
        v = v_next;
      } while (e != e0);
      break;
    }

    if (disk && gf->edges().size() == 1 && gf->edges()[0]->periodic(0)) {
      sides = {gf->edges()};
      sidesInv = {{false}};
    }

    if (sides.size() == 0) {
      Msg::Debug("face %i (%li edges), failed to build sides",gf->tag(),edges.size());
      DBG(disk);
      return -1;
    }

    /* Collect mesh vertices */
    vector<vector<MVertex*> > sideVertices(sides.size());
    for (size_t i = 0; i < sides.size(); ++i) {
      for (size_t j = 0; j < sides[i].size(); ++j) {
        GEdge* ge = sides[i][j];
        bool inv = sidesInv[i][j];
        GVertex* v1 = ge->vertices()[0];
        GVertex* v2 = ge->vertices()[1];

        /* Vertices from v1 to v2 */
        // TODO FIXME WARNING: assume the mesh_vertices are oredered, this is not always the case !
        vector<MVertex*> ge_vert = {v1->mesh_vertices.at(0)};
        append(ge_vert, ge->mesh_vertices);
        ge_vert.push_back(v2->mesh_vertices.at(0));
        if (inv) {
          std::reverse(ge_vert.begin(),ge_vert.end());
        }
        if (sideVertices[i].size() == 0) {
          append(sideVertices[i], ge_vert);
        } else {
          if (sideVertices[i].back() == ge_vert[0]) {
            sideVertices[i].pop_back();
          }
          append(sideVertices[i], ge_vert);
        }
      }
    }

    /* When there is just one side, two possible cases:
     * - disk (all bdr vertices are quad-valence 2)
     * - face with only one convex corner
     */
    if (sides.size() == 1) {
      if (sides[0].size() < 1) {
        Msg::Warning("not enough vertices on face loop for quad meshing (%li vert)", sides[0].size());
        return -1;
      }
      if (disk) {
        if (sides[0].front() == sides[0].back()) {
          sides[0].pop_back();
        }
      } else {
        if (sides[0].front() == sides[0].back()) {
          sides[0].pop_back();
        }
      }
    }


    // if (sideVertices.size() > 2) return false; // DEBUG TODO

    // DBG("---------",gf->tag());
    // DBG(sideVertices.size());
    std::vector<size_t> sideSizes(sideVertices.size());
    if (onlyCheckIfMeshable && checkTheSubdivision) {
      for (size_t i = 0; i < sideSizes.size(); ++i) sideSizes[i] = 2*sideVertices[i].size()-1;
    } else {
      for (size_t i = 0; i < sideSizes.size(); ++i) sideSizes[i] = sideVertices[i].size();
    }
    /* Mesh with quad pattern */
    std::pair<size_t,int> patternNoAndRot;
    size_t Ncorners = disk ? 0 : sideSizes.size();
    double irreg;
    std::vector<size_t> patternsToCheck = getAllLoadedPatterns();
    remove_element_if_inside(PATTERN_DISK, patternsToCheck);
    // TODO: keep disk (and others curved patterns?) if good curvature
    bool meshable = patchIsRemeshableWithQuadPattern(patternsToCheck,Ncorners, sideSizes, patternNoAndRot, irreg);
    if (meshable) {
      if (onlyCheckIfMeshable) {
        Msg::Debug("Face %li is mehable with simple quad pattern", gf->tag());
        return 0;
      }
      std::vector<MElement*> oldElements;
      oldElements.reserve(gf->quadrangles.size()+gf->triangles.size());
      for (MElement* f: gf->triangles) oldElements.push_back(f);
      for (MElement* f: gf->quadrangles) oldElements.push_back(f);

      std::vector<MVertex*> newVertices;
      std::vector<bool> vertexIsIrregular;
      std::vector<MElement*> newElements;
      int status = remeshPatchWithQuadPattern(gf, sideVertices, patternNoAndRot, oldElements, newVertices, vertexIsIrregular, newElements);
      if (status == 0) {
        // Msg::Debug("- Face %li: winslow smoothing ...", gf->tag());
        // meshWinslow2d(gf, 10);
        gf->meshStatistics.status = GFace::DONE;
        return 0;
      } else {
        Msg::Error("Face %i, failed to remesh with selected quad pattern, weird", gf->tag());
        return -1;
      }
    } 
    Msg::Debug("- Face %i: no matching quad pattern", gf->tag());
    return -1;
  }

  inline int closestPositiveOdd(double x) {
    int r = 2*int(std::floor(x/2.))+1;
    return r >= 3 ? r : 3;
  }

  bool curveQuantizationSimpleChords(GModel* gm, const std::map<GFace*, GFaceInfo>& faceInfo, bool forceEvenNbEdges = false) {
    /* Chord constraints on quad faces with 4 GEdges (T-junctions not supported here) */
    std::set<GFace *> qfaces;
    for (GFace* gf: model_faces(gm)) {
      auto it = faceInfo.find(gf);
      if (it == faceInfo.end()) continue;
      const GFaceInfo& info = it->second;
      if (info.chi == 1 && gf->edges().size() == 4 && info.bdrValVertices[1].size() == 4) {
        qfaces.insert(gf);
      }
    }
    if (qfaces.size() > 0) {
      std::vector<std::set<GEdge *> > chords;
      build_chords(qfaces, chords);

      /* Determine the number of points, set the transfinite curves */
      Msg::Debug("computeQuadCurveMeshConstraints: assigning number of points ...");
      std::size_t ne = 0;
      for(std::set<GEdge *> &chord : chords) {
        bool chordOk = true;
        int forcedN = -1;

        double avgNbPoints = 0;
        for(GEdge *ge : chord) {
          if (ge->meshAttributes.method == MESH_TRANSFINITE) {
            /* GEdge has already a transfinite constraint */
            size_t N = ge->meshAttributes.nbPointsTransfinite;
            if (forcedN == -1) {
              forcedN = N;
            } else if (forcedN != int(N)) { /* Incoherent transfinite constraints on chord ... */
              Msg::Warning("curve quantization: conflict in existing transfinite constraints on quad loop");
              chordOk = false;
            }
          } else {
            int n = meshGEdgeTargetNumberOfPoints(ge);
            avgNbPoints += double(n);
          }
        }
        avgNbPoints /= chord.size();
        if (!chordOk) {
          Msg::Warning("curve quantization: ignore chord because of existing constraints");
          continue;
        }

        int N = forcedN;
        if (N == -1) {
          N = int(std::round(avgNbPoints));
          if(N == 0) N = 2;
          if (forceEvenNbEdges && N % 2 == 0) {
            N = closestPositiveOdd(avgNbPoints);
          }
        }

        Msg::Debug("- chord with %li edges -> %i points\n", chord.size(), N);

        for(GEdge *ge : chord) {
          if (ge->meshAttributes.method != MESH_TRANSFINITE) {
            ge->meshAttributes.method = MESH_TRANSFINITE;
            ge->meshAttributes.nbPointsTransfinite = N;
            ge->meshAttributes.typeTransfinite = 1; /* Progression */
            ge->meshAttributes.coeffTransfinite = 1.;
            ne += 1;
          }
        }
      }

      Msg::Info("Number of points set on %li curves (transfinite curves) from %li chords (quad loops)", ne, chords.size());
    }

    return true;
  }

  int closestValueInVector(int n, const std::vector<int>& values) {
    int dmin = std::numeric_limits<int>::max();
    int vmin = -1;
    for (int v: values) {
      int d = std::pow(n-v,2);
      if (d < dmin) {
        dmin = d;
        vmin = v;
      }
    }
    return vmin;
  }

  bool curveQuantizationSimpleSnapping(GModel* gm, const std::map<GFace*, GFaceInfo>& faceInfo, double threshold = 0.2, bool forceEvenNbEdges = false) {
    /* Would be better to do mean shift clustering */
    size_t ns = 0;
    for (GFace* gf: model_faces(gm)) {
      auto it = faceInfo.find(gf);
      if (it == faceInfo.end()) continue;

      vector<int> qvalues;
      for (GEdge* ge: gf->edges()) {
        if (ge->meshAttributes.method == MESH_TRANSFINITE) {
          qvalues.push_back(ge->meshAttributes.nbPointsTransfinite);
        }
      }
      sort_unique(qvalues);

      for (GEdge* ge: gf->edges()) {
        if (ge->meshAttributes.method != MESH_TRANSFINITE) {
          int n = meshGEdgeTargetNumberOfPoints(ge); /* nb of points including extremities */
          int e = closestValueInVector(n, qvalues);
          if (n == 0) n = 1;
          double rel = std::abs(double(n-e))/std::max(double(n),double(e));
          if (e <= 0 || rel > threshold) {
            int N = n;
            if(N == 0) N = 2;
            if (forceEvenNbEdges && N % 2 == 0) {
              N = closestPositiveOdd(double(N));
            }
            ge->meshAttributes.method = MESH_TRANSFINITE;
            ge->meshAttributes.nbPointsTransfinite = N;
            ge->meshAttributes.typeTransfinite = 1; /* Progression */
            ge->meshAttributes.coeffTransfinite = 1.;
            qvalues.push_back(N);
            ns += 1;
          } else {
            ge->meshAttributes.method = MESH_TRANSFINITE;
            ge->meshAttributes.nbPointsTransfinite = e;
            ge->meshAttributes.typeTransfinite = 1; /* Progression */
            ge->meshAttributes.coeffTransfinite = 1.;
            ns += 1;
          }
        }
      }
    }
    if (ns > 0) {
      Msg::Info("curve quantization: simple snapping applied on %li curves", ns);
    }

    return true;
  }

  bool projectGVerticesOnGEdges(const vector<GFace*>& faces, std::map<GEdge*, std::vector<GPoint> >& projections,
      const std::map<GFace*, GFaceInfo>& faceInfo) {
    std::unordered_map<GVertex*,std::set<GEdge*> > gv2ge;
    std::unordered_map<GEdge*,int> geNbPoints;
    for (GFace* gf: faces) {
      discreteFace* df = dynamic_cast<discreteFace*>(gf);
      if (df != NULL) {
        Msg::Warning("project CAD vertices on CAD curves cannot be applied on discrete model");
        return false;
      }
      for (GEdge* ge: gf->edges()) {
        bool isTrueSeam = (ge->isSeam(gf) && ge->faces().size() == 1);
        if (isTrueSeam) continue;
        GVertex* v1 = ge->vertices()[0];
        GVertex* v2 = ge->vertices()[1];
        gv2ge[v1].insert(ge);
        gv2ge[v2].insert(ge);
        auto it = geNbPoints.find(ge);
        if (it == geNbPoints.end()) {
          geNbPoints[ge] = meshGEdgeTargetNumberOfPoints(ge); 
        }
      }
    }


    /* Loop over faces */
    for (GFace* gf: faces) {
      for (GVertex* gv: gf->vertices()) {
        const std::set<GEdge*>& adjEdges = gv2ge[gv];
        if (adjEdges.size() <= 1) continue;
        {
          bool isConcaveInGf = false;
          auto it1 = faceInfo.find(gf);
          if (it1 == faceInfo.end()) continue;
          isConcaveInGf = (it1->second.bdrValVertices[3].find(gv) != it1->second.bdrValVertices[3].end());
          if (!isConcaveInGf) continue;
        }
        /* Get raw approximatation of size map 
         * TODO: better way without using GEdge target nb of points ? */
        double avgSize = 0.;
        {
          double sum = 0.;
          for (GEdge* ge: adjEdges) {
            double len = ge->length();
            if (len == 0. || geNbPoints[ge] < 2) continue;
            avgSize += len/(double(geNbPoints[ge])-1.);
            sum += 1;
          }
          if (sum == 0.) continue;
          avgSize /= sum;
        }

        for (GEdge* ge: gf->edges()) {
          bool isTrueSeam = (ge->isSeam(gf) && ge->faces().size() == 1);
          if (isTrueSeam) continue;
          bool adjToGv = (adjEdges.find(ge) != adjEdges.end());
          if (adjToGv) continue;

          double t = 0;
          SPoint3 query(gv->point().x(),gv->point().y(),gv->point().z());
          GPoint proj = ge->closestPoint(query,t);
          if (proj.succeeded()) {
            GPoint tmp = gv->point();
            double dist = proj.distance(tmp);
            if (dist < avgSize) {
              double t_min = ge->getLowerBound();
              double t_max = ge->getUpperBound();
              double t = proj.u();
              // DBG(ge->tag(), t,t_min,t_max);
              if (t <= t_min || t >= t_max) continue;

              /* Do not create projection too close to GEdge extremities or previous projs */
              double distWithExistingProj = DBL_MAX;
              std::vector<GPoint>& eprojs = projections[ge];
              for (GPoint& ep: eprojs) {
                distWithExistingProj = std::min(distWithExistingProj,proj.distance(ep));
              }
              distWithExistingProj = std::min(distWithExistingProj,ge->vertices()[0]->point().distance(proj));
              distWithExistingProj = std::min(distWithExistingProj,ge->vertices()[1]->point().distance(proj));
              if (distWithExistingProj < 0.2 * avgSize) continue;

              vector<vec3> pts = {SVector3(query),SVector3(proj.x(),proj.y(),proj.z())};
              GeoLog::add(pts,std::vector<double>{0.,1.},"projectCAD");
              projections[ge].push_back(proj);
            }
          }
        }
      }
    }


    GeoLog::flush();

    return true;
  }
}
using namespace QSQ;

bool useDiscreteGeometry(GModel* gm) {
  bool useDiscrete = false;
  if (CTX::instance()->mesh.quadqsUseDiscreteGeometry) {
    useDiscrete = true;
  }
  for (GFace* gf: model_faces(gm)) {
    discreteFace* df = dynamic_cast<discreteFace*>(gf);
    if (df) useDiscrete = true;
    if (useDiscrete && gf->triangles.size() == 0) {
      Msg::Error("- Face %li: discrete geometry but no triangles", gf->tag());
    }
  }
  return useDiscrete;
}


int showQuadMeshBaseComplex(GModel* gm) {
  buildQuadMeshBaseComplex(gm);
  return 0;
}

int setQuadCoherentCurveTransfiniteConstraints(const std::vector<GFace*>& faces, const std::map<GFace*,GFaceInfo>& faceInfo) 
{
  Msg::Debug("mesh %li faces with quad integer constraint solver ...", faces.size());

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
  CTX::instance()->mesh.recombineAll = 1; /* force odd number in GEdge sampling */
  GenerateMesh(gm, 1);
  CTX::instance()->mesh.recombineAll = 0;
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
  bool useDiscrete = useDiscreteGeometry(gm);
  bool applyMidpointSubdiv = !useDiscrete;
  if (applyMidpointSubdiv) {
    targetNumberOfQuads *= 0.25; /* because of future midpoint subdivision */
  }
  bool disableConformalScaling = false; /* On some corners, H tends to infinity and may destroy the size map */
  int nbDiffusionLevels = 3;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;
  bool adaptSmallFeatures = true;
  std::string name = "scaled_cross_field";
  {
    PView* view_s = PView::getViewByName(name);
    if (view_s) {
      viewTag = view_s->getTag();
    }
  }
  singularities.clear();
  int verbosity = 0;
  int st = computeScaledCrossFieldView(gm, viewTag, targetNumberOfQuads, 
      nbDiffusionLevels, thresholdNormConvergence, nbBoundaryExtensionLayer, 
      name, verbosity, &singularities, disableConformalScaling, adaptSmallFeatures);
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


int computeQuadCurveMeshConstraints(GModel* gm,
    const std::map<GFace*, GFaceInfo>& faceInfo,
    bool forceEvenNbEdges = false) {

  curveQuantizationSimpleChords(gm, faceInfo, forceEvenNbEdges);
  curveQuantizationSimpleSnapping(gm, faceInfo, 0.15, forceEvenNbEdges);

  return 0;
}

int generateCurve1DMeshes(GModel* gm, std::map<GFace*, GFaceInfo>& faceInfo, bool forceEvenNbEdges = false, bool alignWithGVertices = true) {
  /* Disable clscale because we have a sizemap 
   * that contains the scaling */
  double clscale = CTX::instance()->mesh.lcFactor;
  CTX::instance()->mesh.lcFactor = 1.;

  computeQuadCurveMeshConstraints(gm, faceInfo, forceEvenNbEdges);

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

  if (alignWithGVertices) {
    std::map<GEdge*, std::vector<GPoint> > projections;
    bool okp = projectGVerticesOnGEdges(model_faces(gm), projections, faceInfo);
    if (!okp) {
      Msg::Warning("failed to project GVertices on GEdges");
      return 0;
    }
    for (auto& kv: projections) {
      GEdge* ge = kv.first;
      std::vector<GPoint>& projs = kv.second;

      vector<bool> done_k(projs.size(),false);
      vector<bool> done_j(ge->mesh_vertices.size(),false);

      bool running = true;
      while (running) {
        running = false;

        double dmin = DBL_MAX;
        size_t best_j = NO_ID;
        size_t best_k = NO_ID;
        for (size_t k = 0; k < projs.size(); ++k) if (!done_k[k]) {
          SPoint3 p(projs[k].x(),projs[k].y(),projs[k].z());
          for (size_t j = 0; j < ge->mesh_vertices.size(); ++j) if (!done_j[j]) {
            MVertex* v = ge->mesh_vertices[j];
            double dist = v->point().distance(p);
            if (dist < dmin) {
              best_j = j;
              best_k = k;
              dmin = dist;
            }
          }
        }
        if (best_j != NO_ID) {
          GPoint& proj = projs[best_k];
          MVertex* v = ge->mesh_vertices[best_j];

          // DBG("---");
          // DBG(ge->tag(),dmin,best_j,best_k,proj.u());
          // DBG(v->getNum(), v->point().x(),v->point().y(),v->point().z());
          // DBG(proj.x(),proj.y(),proj.z());

          v->setXYZ(proj.x(),proj.y(),proj.z());
          v->setParameter(0,proj.u());

          done_j[best_j] = true;
          done_k[best_k] = true;


          running = true;
        }
      }
    }
  }


  return 0;
}

int generatePatternBasedQuadMeshesOnSimpleFaces(GModel* gm, std::map<GFace*, GFaceInfo>& faceInfo) {
  CTX::instance()->lock = 0;
  std::vector<GFace*> faces = model_faces(gm);
  for (GFace* gf: faces) {
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    GFaceInfo& info = faceInfo[gf];
    /* Check if convex topological disk */
    if (info.chi == 1 && info.bdrValVertices[1].size() >= 0 
        && info.bdrValVertices[3].size() == 0 && info.bdrValVertices[4].size() == 0) {
      /* Mesh with pattern */
      int status = meshSimpleFaceWithPattern(gf, info);
      if (status == 0) {
        gf->meshStatistics.status = GFace::DONE;
        Msg::Info("- Face %i: simple topology (topo. is disk with %i convex corners), quad mesh (%li elements) built from simple pattern",
            gf->tag(), info.bdrValVertices[1].size(), gf->quadrangles.size());
      }
    }
  }

  return 0;
}

int generateUnstructuredQuadMeshes(GModel* gm, std::map<GFace*, GFaceInfo>& faceInfo) {
  /* Disable clscale because we have a sizemap 
   * that contains the scaling */
  double clscale = CTX::instance()->mesh.lcFactor;
  CTX::instance()->mesh.lcFactor = 1.;

  bool useDiscrete = useDiscreteGeometry(gm);
  bool applyMidpointSubdiv = !useDiscrete;

  Msg::Error("disable MPS");
  applyMidpointSubdiv = false;
  /* Generate quad dominant mesh */

  std::vector<GFace*> faces = model_faces(gm);

  CTX::instance()->mesh.algo2d = ALGO_2D_PACK_PRLGRMS;
  CTX::instance()->lock = 0;

  size_t nPending = 1;
  size_t nIter = 0;
  while (nPending > 0) {
    nPending = 0;

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (GFace* gf: faces) {
      if (gf->meshStatistics.status == GFace::PENDING) {
        if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
        GFaceInfo& info = faceInfo[gf];
        /* Check if quad mesh pattern for simple CAD face */
        if (info.chi == 1 && info.bdrValVertices[1].size() >= 0 
            && info.bdrValVertices[3].size() == 0 && info.bdrValVertices[4].size() == 0) {
          /* Check if there is a quad pattern */
          int status = meshSimpleFaceWithPattern(gf, info, true, applyMidpointSubdiv);
          if (status == 0) {
            gf->meshStatistics.status = GFace::DONE;  /* for the while loop */
            Msg::Debug("-- Face %i: no unstructured meshing because simple pattern exists", gf->tag());
            continue;
          } else {
            Msg::Debug("-- Face %i: no simple pattern matches", gf->tag());
          }
        }

        /* Apply a unstructured quadrilateral mesher */
        if (useDiscrete) {
          /* Unstructured full quad meshing with hxt */
          meshGFaceHxt(gf);
          Msg::Debug("-- Face %i: %li quads and %li triangles built with meshGFaceHxt", 
              gf->tag(), gf->quadrangles.size(), gf->triangles.size());
        } else {
          /* Unstructured quadtri meshing with algo PACK */
          gf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS);
          gf->mesh(true);
          Msg::Debug("-- Face %i: %li quads and %li triangles built with ALGO_2D_PACK_PRLGRMS", 
              gf->tag(), gf->quadrangles.size(), gf->triangles.size());
          gf->setMeshingAlgo(ALGO_2D_QUAD_QUASI_STRUCT);
        }
        if (gf->meshStatistics.status == GFace::DONE) {
          if (!applyMidpointSubdiv && gf->triangles.size() > 0) {
            Msg::Error("- Face %i: %li triangles (%li quads) in mesh but no subdivision, should not happen", gf->tag(),
                gf->triangles.size(),gf->quadrangles.size());
          }
        }

        #if defined(_OPENMP)
        #pragma omp critical
        #endif
        {
          nPending += 1;
        }
      }
    }

    if(nIter++ > (size_t) CTX::instance()->mesh.maxRetries) break;
  }

  /* set to pending to enable future topological improvement */
  for (GFace* gf: faces) {
    if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
    if (gf->meshStatistics.status == GFace::DONE) {
      gf->meshStatistics.status = GFace::PENDING; 
    }
  }

  CTX::instance()->lock = 1;
  CTX::instance()->mesh.algo2d = ALGO_2D_QUAD_QUASI_STRUCT;

  constexpr bool SHOW_VIEW_QUADTRI = true;
  if (SHOW_VIEW_QUADTRI) {
    std::vector<MElement*> tris;
    std::vector<MElement*> quads;
    for (GFace* gf: faces) {
      if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
      tris.reserve(gf->triangles.size());
      quads.reserve(gf->quadrangles.size());
      for (MElement* f: gf->triangles) tris.push_back(f);
      for (MElement* f: gf->quadrangles) quads.push_back(f);
      geolog_elements(quads, "quadtri",0.);
      geolog_elements(tris, "quadtri",1.);
    }
    GeoLog::flush();
  }
  if (EXPORT_MESHES) gm->writeMSH("qqs_quadtri.msh",2.2,false,true);

  if (applyMidpointSubdiv) {
    bool secondOrderLinear = false; /* which value to use ? */
    RefineMesh(gm, secondOrderLinear, true, false);
    if (EXPORT_MESHES) gm->writeMSH("qqs_subdiv.msh",2.2,false,true);
  }

  CTX::instance()->mesh.lcFactor = clscale;
  Msg::Debug("Done generating unstructured quadrilateral mesh");
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

int improveQuadMeshOfFace(GFace* gf, vector<MVertex*>& singularVertices) {
  bool running = true;
  while (running) {
    running = false;
    size_t n1 = gf->quadrangles.size();

    { /* 1st pass: check regular quad patch remeshing only */
      const vector<size_t> patternsToCheck = {PATTERN_QUAD_REGULAR};
      remeshQuadrilateralPatches(gf, singularVertices, patternsToCheck);
    }
    {
      const vector<size_t> patternsToCheck = {PATTERN_TRIANGLE,PATTERN_PENTAGON};
      remeshCavitiesAroundSingularities(gf, singularVertices, patternsToCheck);
    }
    {
      const vector<size_t> patternsToCheck = {PATTERN_QUAD_REGULAR, PATTERN_QUAD_DIAG35, PATTERN_QUAD_ALIGNED35, PATTERN_QUAD_CHORD_UTURN};
      remeshQuadrilateralPatches(gf, singularVertices, patternsToCheck);
    }
    // TODO: move 35 pairs inside patch ?

    size_t n2 = gf->quadrangles.size();
    if (n1 != n2) running = true;
  }
  return 0;
}

int verifyCompatibilityCrossFieldEuler(const GFace* gf, int sum3m5, size_t nSingVal3, size_t nSingVal5) {
  /* Check compatibility between Euler-based topological relation
   * and cross field singularities */
  int cfSum3m5 = int(nSingVal3) - int(nSingVal5);
  if (cfSum3m5 == sum3m5) {
    Msg::Debug("- Face %i | face topology and cross field are compatible, n_val3 - n_val5 = %i - %i = %i", 
        gf->tag(), nSingVal3, nSingVal5, cfSum3m5);
  } else {
    Msg::Warning("- Face %i | face topology and cross field are NOT compatible, crossfield n_val5 - n_val3 = %i - %i = %i but geometry: %i", 
        gf->tag(), nSingVal3, nSingVal5, cfSum3m5, sum3m5);
    return -1;
  }
  return 0;
}

int singularVerticesFromFloatingSingularities(
    const GFace* gf,
    const std::vector<std::array<double,5> >& singularities,
    std::vector<MVertex*>& singularVertices,
    size_t& nSingVal3, size_t& nSingVal5) {
  singularVertices.clear();

  /* Extract sings in current face, from singularity list */
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
  nSingVal3 = cfSingVal3.size();
  nSingVal5 = cfSingVal5.size();

  /* Extract irregular vertices in face */
  vector<MVertex*> nodeVal3;
  vector<MVertex*> nodeVal5;
  {
    unordered_map<MVertex*, size_t> valence;
    for (MQuadrangle* q: gf->quadrangles) {
      for (size_t le = 0; le < 4; ++le) {
        MVertex* v = q->getVertex(le);
        if (v->onWhat()->cast2Face() != NULL) {
          valence[v] += 1;
        }
      }
    }
    for (const auto& kv: valence) if (kv.second != 4) {
      if (kv.second == 3) {
        nodeVal3.push_back(kv.first);
      } else if (kv.second == 5) {
        nodeVal5.push_back(kv.first);
      }
    }
  }

  /* Assign valence 3 */
  for (size_t i = 0; i < cfSingVal3.size(); ++i) {
    SVector3 p = {cfSingVal3[i][0],cfSingVal3[i][1],cfSingVal3[i][2]};
    double dmin = DBL_MAX;
    MVertex* best = NULL;
    for (size_t j = 0; j < nodeVal3.size(); ++j) {
      SVector3 p2 = nodeVal3[j]->point();
      double dist = nodeVal3[j]->point().distance(p.point());
      if (dist < dmin) {
        dmin = dist;
        best = nodeVal3[j];
      }
    }
    if (best != NULL) {
      singularVertices.push_back(best);
    } else {
      Msg::Warning("- Face %i, singular node %i, failed to assign to val 3 irregular vertex", gf->tag(), i);
      // GeoLog::add(p,3.,"dbg_p"+std::to_string(gf->tag())+"_remaining_sing");
    }
  }
  /* Assign valence 5 */
  for (size_t i = 0; i < cfSingVal5.size(); ++i) {
    SVector3 p = {cfSingVal5[i][0],cfSingVal5[i][1],cfSingVal5[i][2]};
    double dmin = DBL_MAX;
    MVertex* best = NULL;
    for (size_t j = 0; j < nodeVal5.size(); ++j) {
      SVector3 p2 = nodeVal5[j]->point();
      double dist = nodeVal5[j]->point().distance(p.point());
      if (dist < dmin) {
        dmin = dist;
        best = nodeVal5[j];
      }
    }
    if (best != NULL) {
      singularVertices.push_back(best);
    } else {
      Msg::Warning("- Face %i, singular node %i, failed to assign to val 5 irregular vertex", gf->tag(), i);
      // GeoLog::add(p,5.,"dbg_p"+std::to_string(gf->tag())+"_remaining_sing");
    }
  }

  return 0;
}

int improveQuadMeshTopology(GModel* gm, const std::vector<std::array<double,5> >& singularities,
    std::map<GFace*, GFaceInfo>& faceInfo) {

  vector<GFace*> faces = model_faces(gm);

  /* Improve local defects (valence 6+, valence 3+ on curves, etc)
   * by checking all possible local remeshing in big list of
   * disk quadrangulations */
  bool repairDefects = true;
  QMT_Utils::read_from_env("quadqsRepairDefects", repairDefects);
  if (repairDefects) {
    Msg::Info("Repair quad mesh defects (wrong valence on bdr. or valence 6+ inside) ...");
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i = 0; i < faces.size(); ++i) {
      GFace* gf = faces[i];
      transferSeamGEdgesVerticesToGFace(gf);

      if (gf->meshStatistics.status == GFace::PENDING) {
        if (gf->triangles.size() > 0) continue;
        GFaceInfo& info = faceInfo.at(gf);
        Msg::Info("- Face %i: chi = %i, corners: %li convex, %li concave, %li highly concave -> #val3 - #val5 = %i",
            gf->tag(), info.chi, info.bdrValVertices[1].size(), info.bdrValVertices[3].size(), info.bdrValVertices[4].size(), info.intSumVal3mVal5);
        remeshSmallDefects(gf);
      }
    }
    if (EXPORT_MESHES) gm->writeMSH("qqs_wo_defects.msh",2.2,false,true);
    printPatternUsage();
  }

  // Msg::Error("early stop DBG");
  // return 0;

  bool remeshCavities = true;
  QMT_Utils::read_from_env("quadqsRemeshCavities", remeshCavities);
  if (remeshCavities) {
    /* Improve quad meshes with larger operators (cavity remeshing) */
    Msg::Info("Improve quad meshes with large cavity remeshing ...");
#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i = 0; i < faces.size(); ++i) {
      GFace* gf = faces[i];
      if (gf->meshStatistics.status == GFace::PENDING) {
        if (gf->triangles.size() > 0) continue;
        size_t nSingVal3, nSingVal5;
        vector<MVertex*> singularVertices;
        singularVerticesFromFloatingSingularities(gf, singularities, singularVertices, nSingVal3, nSingVal5);
        verifyCompatibilityCrossFieldEuler(gf, faceInfo.at(gf).intSumVal3mVal5, nSingVal3, nSingVal5);
        int st = improveQuadMeshOfFace(gf,singularVertices);
        if (st != 0) {
          Msg::Error("failed to improve quad mesh of face with tag %i", gf->tag());
          continue;
        }
      }
    }
    if (EXPORT_MESHES) gm->writeMSH("qqs_after_cavities.msh",2.2,false,true);
  }

  // vector<MVertex*> singularVertices;
  // propagate35(gm, singularVertices);

  Msg::Debug("... improve quad mesh topology done.");

  return 0;
}

int optimizeQuadMeshGeometry(GModel* gm, const std::vector<std::array<double,5> >& singularities,
    std::map<GFace*, GFaceInfo>& faceInfo) {

  bool optimGeom = false;
  QMT_Utils::read_from_env("quadqsOptimGeom",optimGeom);
  if (optimGeom) {
    std::vector<GFace*> faces = model_faces(gm);
    for (GFace* gf: faces) {
      if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) continue;
      if (gf->triangles.size() > 0) continue;

      optimizeQuadGeometry(gf);
    }
  }

  return 0;
}

bool triangulatedMeshAlreadyExists(GModel* gm) {
  for (GFace* gf: model_faces(gm)) {
    if (gf->triangles.size() == 0) return false;
  }
  return true;
}



int Mesh2DWithQuadQuasiStructured(GModel* gm)
{
  if (CTX::instance()->mesh.algo2d != ALGO_2D_QUAD_QUASI_STRUCT) {
    return 1;
  }

  std::vector<GFace*> faces = model_faces(gm);

  if (QMT_Utils::env_var("SHOW_CAVITIES").size() > 0) {
    SHOW_CAVITIES = true;
  }

  Msg::Info("Generate quasi-structured all-quadrilateral mesh ...");

  if (!triangulatedMeshAlreadyExists(gm)) {
    Msg::Info("[Step 1] Generate initial triangulation ...");
    int s1 = generateInitialTriangulation(gm);
    if (s1 != 0) {
      Msg::Error("failed to generate initial triangulation, abort");
      return s1;
    }
  }

  /* Use the triangulation to compute CAD face information 
   * (nb corners of each valence, euler characteristic, etc) */
  std::map<GFace*, GFaceInfo> faceInfo;
  for (GFace* gf: faces) {
    GFaceInfo info;
    bool ok = fillGFaceInfo(gf, info);
    if (ok) faceInfo[gf] = info;
  }

  Msg::Info("[Step 2] Generate scaled cross field ...");
  std::vector<std::array<double,5> > singularities;
  int s2 = computeScaledCrossField(gm, singularities);
  if (s2 != 0) {
    Msg::Error("failed to compute scaled cross field, abort");
    return s2;
  }

  if (!useDiscreteGeometry(gm)) {
    Msg::Info("[Step 3] Generate curve 1D meshes ...");
    bool forceEvenNbEdges = false;
    bool alignWithGVertices = false;
    int s3 = generateCurve1DMeshes(gm, faceInfo, forceEvenNbEdges, alignWithGVertices);
    if (s3 != 0) {
      Msg::Warning("failed to generate curve 1D meshes, abort");
      return s3;
    }
  } else {
    for (GFace* gf: faces) gf->meshStatistics.status = GFace::PENDING;
  }

  /* Pattern required by steps 4, 5 and 6 */
  {
    Msg::Debug("loading quad patterns and disk quadrangulations ...");
    load_disk_quadrangulations();
    load_patterns();
    Msg::Debug("done.");
  }


  Msg::Info("[Step 4] Generate unstructured quad meshes ...");
  int s4 = generateUnstructuredQuadMeshes(gm, faceInfo);
  if (s4 != 0) {
    Msg::Warning("failed to generate 2D unstructured quad meshes, abort");
    return s4;
  }

  // return 0;

  bool SHOW_ONLY_PATTERN_MESHING = false;

  /* After Step 4 because the midpoint subdivision helps */
  Msg::Info("[Step 5] Generate pattern-based quad meshes in simple faces ...");
  int s5 = generatePatternBasedQuadMeshesOnSimpleFaces(gm, faceInfo);
  if (s5 != 0) {
    Msg::Warning("failed to generate pattern-based quad meshes, abort");
    return s5;
  }
  if (EXPORT_MESHES) gm->writeMSH("qqs_simpleCADfaces.msh",2.2,false,true);

  /* For visu */
  if (SHOW_ONLY_PATTERN_MESHING) {
    for (GFace* gf: faces) {
      if (gf->meshStatistics.status != GFace::DONE) {
        gf->quadrangles.clear();
        gf->mesh_vertices.clear();
      }
    }
    return 0;
  }

  Msg::Info("[Step 6] Improve topology of quad mesh ...");
  int s6 = improveQuadMeshTopology(gm, singularities, faceInfo);
  if (s6 != 0) {
    Msg::Warning("failed to improve quad mesh topology, continue");
  }

  Msg::Info("[Step 7] Optimize geometry of quad mesh ...");
  int s7 = optimizeQuadMeshGeometry(gm, singularities, faceInfo);
  if (s7 != 0) {
    Msg::Warning("failed to optimize quad mesh geometry, continue");
  }

  for (GFace* gf: faces) {
    if (gf->quadrangles.size() < 1000) {
      Msg::Debug("- Face %i: winslow smoothing (%li quads) ...", gf->tag(), gf->quadrangles.size());
      meshWinslow2d(gf,100);
    }
  }


  // TODO:
  // - concave corner cavities

  if (EXPORT_MESHES) gm->writeMSH("qqs_final.msh",2.2,false,true);
  Msg::Debug("... quasi-structured quadrilateral meshing done.");
  return 0;
}

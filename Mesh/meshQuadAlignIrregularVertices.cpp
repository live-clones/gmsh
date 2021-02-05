// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <iostream>
#include "meshQuadQuasiStructured.h"
#include "meshSurfaceProjection.h"
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
#include "meshQuadUtils.h"

#include "OS.h"
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
#include "robin_hood.h" // Fast hash maps
#if defined(HAVE_HXT)
#include "meshGFaceHxt.h"
#endif

// Gecode
#if defined(HAVE_GECODE)
#include <gecode/int.hh>
#include <gecode/search.hh>
#endif

#if defined(HAVE_GECODE)
using namespace Gecode;

class SendMoreMoney : public Space {
protected:
  IntVarArray l;
public:
  SendMoreMoney(void) : l(*this, 8, 0, 9) {
    IntVar s(l[0]), e(l[1]), n(l[2]), d(l[3]),
           m(l[4]), o(l[5]), r(l[6]), y(l[7]);
    // no leading zeros
    rel(*this, s, IRT_NQ, 0);
    rel(*this, m, IRT_NQ, 0);
    // all letters distinct
    distinct(*this, l);
    // linear equation
    IntArgs c(4+4+5); IntVarArgs x(4+4+5);
    c[0]=1000; c[1]=100; c[2]=10; c[3]=1;
    x[0]=s;    x[1]=e;   x[2]=n;  x[3]=d;
    c[4]=1000; c[5]=100; c[6]=10; c[7]=1;
    x[4]=m;    x[5]=o;   x[6]=r;  x[7]=e;
    c[8]=-10000; c[9]=-1000; c[10]=-100; c[11]=-10; c[12]=-1;
    x[8]=m;      x[9]=o;     x[10]=n;    x[11]=e;   x[12]=y;
    linear(*this, c, x, IRT_EQ, 0);
    // post branching
    branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
  }
  // search support
  SendMoreMoney(SendMoreMoney& s) : Space(s) {
    l.update(*this, s.l);
  }
  virtual Space* copy(void) {
    return new SendMoreMoney(*this);
  }
  // print solution
  void print(void) const {
    std::cout << l << std::endl;
  }
};



#if defined(_OPENMP)
#include <omp.h>
#endif

// Shortcuts
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {error(__VA_ARGS__); return false;} } while(0)
#define V vector
#define pb push_back
#define S(s) (int)(s).size()

using std::vector;
using std::array;
using std::ostream;
using std::cout;
using std::endl;
using robin_hood::unordered_map;
using robin_hood::unordered_set;

using namespace QuadPatternMatching;
using namespace QuadUtils;

namespace QSQ_matteo {
  constexpr bool DBG_VERBOSE = false;
  constexpr bool DBG_VIZU = false;
  bool SHOW_CAVITIES = false;
  // constexpr bool EXPORT_MESHES = true;

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
      std::vector<std::set<GEdge *> > &chords,
      bool checkNumberOfPoints = false,
      double checkMaxDiff = 0.25) {
    /* Connectivity */
    std::map<GEdge *, std::vector<GFace *> > edge2faces;
    for(GFace *gf : faces)
      for(GEdge *ge : gf->edges()) { edge2faces[ge].push_back(gf); }

    Msg::Debug("build chords: %li faces, %li edges", faces.size(),
        edge2faces.size());

    static int countch = 0;

    robin_hood::unordered_map<GEdge*,int> geNbOfPts;
    if (checkNumberOfPoints) {
      for(auto &kv : edge2faces) {
        GEdge* ge = kv.first;
        int N = 2;
        if (ge->meshAttributes.method == MESH_TRANSFINITE) {
          N = ge->meshAttributes.nbPointsTransfinite;
        } else {
          N = meshGEdgeTargetNumberOfPoints(ge);
        }
        geNbOfPts[ge] = N;
      }
    }

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
            if (checkNumberOfPoints) {
              int n1 = geNbOfPts[ge];
              int n2 = geNbOfPts[ge2];
              double rel = std::abs(double(n1-n2))/std::max(double(n1),double(n2));
              if (rel > checkMaxDiff) continue;
            }

            Q.push(ge2);
            done[ge2] = true;

            if (false) {
              SVector3 p0 = SVector3( ge->vertices()[0]->point().x(), ge->vertices()[0]->point().y(), ge->vertices()[0]->point().z());
              SVector3 p1 = SVector3( ge->vertices()[1]->point().x(), ge->vertices()[1]->point().y(), ge->vertices()[1]->point().z());
              SVector3 p2 = SVector3( ge2->vertices()[0]->point().x(), ge2->vertices()[0]->point().y(), ge2->vertices()[0]->point().z());
              SVector3 p3 = SVector3( ge2->vertices()[1]->point().x(), ge2->vertices()[1]->point().y(), ge2->vertices()[1]->point().z());
              vector<vec3> pts = {0.5*(p0+p1),0.5*(p2+p3)};
              vector<double> values = {0.,1.};
              GeoLog::add(pts,values,"chord_"+std::to_string(countch));
            }
          }
        }
      }
      countch += 1;

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

  int surfaceEulerCharacteristicDiscrete(const std::vector<MTriangle*>& triangles) {
    if (triangles.size() == 0) {
      Msg::Error("no triangulation for face, cannot compute discrete Euler characteristic");
      return std::numeric_limits<int>::max();
    }
    vector<size_t> vertices;
    vector<array<size_t,2> > edges;
    vertices.reserve(3*triangles.size());
    edges.reserve(3*triangles.size());
    for (MTriangle* t: triangles) {
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
    int S = triangles.size();
    int E = edges.size();
    int V = vertices.size();
    return V - E + S;
  }

  int surfaceEulerCharacteristicDiscrete(GFace* gf) {
    return surfaceEulerCharacteristicDiscrete(gf->triangles);
  }

  double project_point_segment(const SPoint3& query, const SPoint3& a, const SPoint3& b, SPoint3& proj, double& lambda) {
    double l = a.distance(b);
    double t = dot(query-a,b-a);
    if (t <= 0. || l == 0.) {
      proj = a;
      lambda = 1.;
      return query.distance(a);
    } else if (t > l) {
      proj = b;
      lambda = 0.;
      return query.distance(b);
    }
    lambda = 1. - t / (l*l);
    SVector3 p = a * lambda + b * (1. - lambda);
    proj.setPosition(p.x(),p.y(),p.z());
    return query.distance(proj);
  }

  inline double distance2(const SPoint3& a, const SPoint3& b) {
    const double dx = a.x() - b.x();
    const double dy = a.y() - b.y();
    const double dz = a.z() - b.z();
    return dx*dx+dy*dy+dz*dz;
  }

  inline double distance_point_segment_squared(const SPoint3& query, const SPoint3& a, const SPoint3& b) {
    const double l2 = distance2(a,b);
    const double t = dot(query-a,b-a);
    if (t <= 0. || l2 == 0.) {
      return distance2(query,a);
    } else if (t > l2) {
      return distance2(query,b);
    }
    const double lambda = 1. - t / l2;
    SPoint3 proj(lambda * a + (1. - lambda) * b);
    return distance2(query,proj);
  }


  double distanceToGEdgeMesh(const SPoint3& query, GEdge* ge) {
    // warning: not very efficient ...
    double mdist2 = DBL_MAX;
    for (MLine* l: ge->lines) {
      MVertex* v1 = l->getVertex(0);
      MVertex* v2 = l->getVertex(1);
      mdist2 = std::min(mdist2,distance_point_segment_squared(query,v1->point(),v2->point()));
    }
    return std::sqrt(mdist2);
  }

  bool computeMinimumDistanceToNonAdjacentGEdges(GFace* gf,
      robin_hood::unordered_map<MVertex*,double>& minDistToOtherFeature,
      bool includeAdjacent = false) {
    /* TODO: Slow, quadratic complexity, should be replaced by knn ? */

    robin_hood::unordered_map<GVertex*,std::vector<GEdge*> > gv2ge;
    robin_hood::unordered_map<MVertex*,std::vector<MLine*> > v2l;
    for (GEdge* ge: gf->edges()) {
      double len = ge->length();
      for (GVertex* gv: ge->vertices()) {
        gv2ge[gv].push_back(ge);
        if (gv->mesh_vertices.size() == 0) {
          MVertex* v = gv->mesh_vertices[9];
          auto it = minDistToOtherFeature.find(v);
          if (it == minDistToOtherFeature.end()) {
            minDistToOtherFeature[v] = len;
          } else if (len < it->second) {
            it->second = len;
          }
        }
      }
    }

    /* Check distance from GVertex to non-adjacent GEdge */
    for (GVertex* gv: gf->vertices()) {
      if (gv->mesh_vertices.size() == 1) {
        for (GEdge* ge: gf->edges()) {
          auto itc = std::find(gv2ge[gv].begin(),gv2ge[gv].end(),ge);
          if (itc != gv2ge[gv].end()) continue;
          MVertex* v = gv->mesh_vertices[0];
          double dist = distanceToGEdgeMesh(v->point(),ge);
          auto it = minDistToOtherFeature.find(v);
          if (it == minDistToOtherFeature.end()) {
            minDistToOtherFeature[v] = dist;
          } else if (dist < it->second) {
            it->second = dist;
          }
        }
      }
    }

    /* Check distance from MVertex* to non-adjacent GEdge */
    for (GEdge* ge: gf->edges()) {
      std::vector<GEdge*> adj_edges = gv2ge[ge->vertices()[0]];
      append(adj_edges,gv2ge[ge->vertices()[1]]);
      std::vector<GEdge*> others = difference(gf->edges(),adj_edges);
      if (includeAdjacent) {
        others = difference(gf->edges(),{ge});
      }
      for (GEdge* ge2: others) {
        if (ge2 == ge) continue;
        for (MVertex* v: ge->mesh_vertices) {
          double dist = distanceToGEdgeMesh(v->point(),ge2);
          auto it = minDistToOtherFeature.find(v);
          if (it == minDistToOtherFeature.end()) {
            minDistToOtherFeature[v] = dist;
          } else if (dist < it->second) {
            it->second = dist;
          }
        }
      }
    }

    return true;
  }

  bool setVertexGFaceUV(GFace* gf, MVertex* v, double uv[2]) {
    bool onGf = (dynamic_cast<GFace*>(v->onWhat()) == gf);
    if (onGf) {
      v->getParameter(0,uv[0]);
      v->getParameter(1,uv[1]);
      return true;
    } else {
      GEdge* ge = dynamic_cast<GEdge*>(v->onWhat());
      if (ge != NULL) {
        double t;
        v->getParameter(0,t);
        SPoint2 uvp = ge->reparamOnFace(gf, t, -1);
        uv[0] = uvp.x();
        uv[1] = uvp.y();
        return true;
      } else {
        GVertex* gv = dynamic_cast<GVertex*>(v->onWhat());
        if (gv != NULL) {
          SPoint2 uvp = gv->reparamOnFace(gf,0);
          uv[0] = uvp.x();
          uv[1] = uvp.y();
          return true;
        }
      }
    }
    uv[0] = 0.;
    uv[1] = 0.;
    return false;
  }

  bool buildVertexToVertex(const std::vector<GFace*>& faces,
      robin_hood::unordered_map<MVertex*,robin_hood::unordered_set<MVertex*> >& v2v) {
    for (GFace* gf: faces) {
      for (MElement* f: gf->triangles) {
        size_t N = f->getNumEdges();
        for (size_t le = 0; le < N; ++le) {
          MVertex* v1 = f->getVertex(le);
          MVertex* v2 = f->getVertex((le+1)%N);
          v2v[v1].insert(v2);
          v2v[v2].insert(v1);
        }
      }
      for (MElement* f: gf->quadrangles) {
        size_t N = f->getNumEdges();
        for (size_t le = 0; le < N; ++le) {
          MVertex* v1 = f->getVertex(le);
          MVertex* v2 = f->getVertex((le+1)%N);
          v2v[v1].insert(v2);
          v2v[v2].insert(v1);
        }
      }
    }
    return true;
  }

  bool adaptSizeMapToSmallFeatures(
      const std::vector<GFace*>& faces,
      std::unordered_map<MVertex*,double>& sizemap,
      double smallestMultiplier,
      double gradientMax) { /* to avoid very small size map */

    // TODO:
    // - take into account prescribed sizes
    // - take into account size map ?

    bool includeAdjacent = false;
    robin_hood::unordered_map<MVertex*,double> minDistToOtherFeature;
    for (GFace* gf: faces) {
      computeMinimumDistanceToNonAdjacentGEdges(gf, minDistToOtherFeature,includeAdjacent);
    }

    /* Propage minDistToOtherFeature from boundary to interior, with maximal gradient */
    /* Clamp with smallest multiplier to avoid very small sizes */
    robin_hood::unordered_map<MVertex*,double> values;
    for (auto& kv: minDistToOtherFeature) {
      MVertex* v = kv.first;
      auto it = sizemap.find(v);
      if (it == sizemap.end()) continue;
      double size = it->second;
      if (kv.second < smallestMultiplier * size) {
        values[v] = smallestMultiplier * size;
      } else if (kv.second < size){
        values[v] = kv.second;
      }
    }


    /* Dijkstra propagation */
    robin_hood::unordered_map<MVertex*,robin_hood::unordered_set<MVertex*> > v2v;
    buildVertexToVertex(faces, v2v);

    std::priority_queue<std::pair<double,MVertex*>,  std::vector<std::pair<double,MVertex*> >,  std::greater<std::pair<double,MVertex*> > > Q;
    for (const auto& kv: values) {
      Q.push({kv.second,kv.first});
    }

    /* Dijkstra propagation */
    while (Q.size() > 0) {
      MVertex* v = Q.top().second;
      double cdist = Q.top().first;
      Q.pop();
      for (MVertex* v2: v2v[v]) {
        double w_ij = v->distance(v2) * (gradientMax-1.);
        auto it = values.find(v2);
        if (it == values.end() || cdist + w_ij < it->second) {
          double new_value = cdist + w_ij;
          auto it2 = sizemap.find(v2);
          if (it2 != sizemap.end() && new_value > it2->second) {
            /* No need to propagate in regions where sizemap is
             * already sufficiently fine */
            continue;
          }
          values[v2] = new_value;
          Q.push({new_value,v2});
        }
      }
    }

    /* Blending sizemap with propagation from small features */
    for (auto& kv: values) {
      MVertex* v = kv.first;
      auto it = sizemap.find(v);
      if (it != sizemap.end() && kv.second < it->second) {
        it->second = kv.second; /* replace sizemap with propagated value */
      }
    }

    return true;
  }

  struct QuadqsInfo {
    bool importBackgroundField = false;
    bool optimizeTopology = true;
    bool optimizeGeometry = true;
    unordered_map<std::string,double> stats;
    double timeMaxTopoPerGFace = 100.;
  };

  class GFaceInfo {
    public:
      GFace* gf = NULL;
      int chi = 0;
      std::map<GVertex*,int> cornerAngle;
      std::set<GVertex*> cornerIsNonManifold;
      std::array<std::set<GVertex*>,5> bdrValVertices;
      int intSumVal3mVal5 = 0;
      SurfaceProjector* sp = NULL;
      std::vector<std::array<double,5> > singularities;

    public:
      GFaceInfo() {}

      ~GFaceInfo() {
        if (sp != NULL) {
          delete sp;
          sp = NULL;
        }
      }

      bool init(GFace* gf_, bool createSurfaceProjector = false) {
        gf = gf_;
        chi = 0;
        cornerAngle.clear();
        cornerIsNonManifold.clear();
        for (auto& a: bdrValVertices) a.clear();
        intSumVal3mVal5 = 0;
        if (sp != NULL) {
          delete sp;
          sp = NULL;
        }

        /* Get triangles */
        std::vector<MTriangle*> triangles;
        bool delTriangles = false;
        bool clearGFace = false;
        if (gf->triangles.size() > 0) {
          triangles = gf->triangles;
        } else if (gf->quadrangles.size() > 0) {
          triangles.reserve(2*gf->quadrangles.size());
          for (MQuadrangle* f: gf->quadrangles) {
            MVertex* v0 = f->getVertex(0);
            MVertex* v1 = f->getVertex(1);
            MVertex* v2 = f->getVertex(2);
            MVertex* v3 = f->getVertex(3);
            MTriangle* t1 = new MTriangle(v0,v1,v2);
            MTriangle* t2 = new MTriangle(v0,v2,v3);
            triangles.push_back(t1);
            triangles.push_back(t2);
          }
          delTriangles = true;
        } else {
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
          delTriangles = true;
          clearGFace = true;
        }

        /* Compute geometric info */
        robin_hood::unordered_map<GVertex*,vector<MElement*> > corner2tris;
        robin_hood::unordered_map<GVertex*,double> corner2angle;
        for (MTriangle* t: triangles) {
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
        robin_hood::unordered_set<GVertex*> boundaryCADcorners;
        for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
          boundaryCADcorners.insert(gv);
        }

        for (const auto& kv: corner2tris) {
          GVertex* gv = kv.first;
          /* Check if corner is manifold */
          {
            auto it = boundaryCADcorners.find(gv);
            if (it == boundaryCADcorners.end()) continue; /* ignore interior GVertex */
          }
          std::vector<MElement*> elts = kv.second;
          vector<MVertex*> bnd;
          bool okb = buildBoundary(elts.begin(),elts.end(), bnd);
          if (!okb) {
            cornerIsNonManifold.insert(gv);
            continue;
          }
          double angle = corner2angle[gv];
          double angle_deg = 180. / M_PI * angle;
          if (angle_deg < 90. + 45.) {
            bdrValVertices[1].insert(gv);
          } else if (angle_deg < 180. + 45.) {
            bdrValVertices[2].insert(gv);
          } else if (angle_deg < 270. + 45.) {
            bdrValVertices[3].insert(gv);
          } else if (angle_deg < 360.) {
            bdrValVertices[4].insert(gv);
          } else {
            Msg::Warning("CAD vertex (surf=%i,node=%i) has angle = %f deg (interior node ?)", gf->tag(), gv->tag(), angle_deg);
            continue;
          }
        }
        chi = surfaceEulerCharacteristicDiscrete(triangles);

        /* discrete topological relations between irregular vertices:
         *  sum3m5 = n_val3 - n_val5 = 4 \chi + m_val3 - m_val1  + 2 m_val4 */
        intSumVal3mVal5 = 4*chi + int(bdrValVertices[3].size())
          - int(bdrValVertices[1].size()) + 2 * int(bdrValVertices[4].size());

        if (createSurfaceProjector) {
          sp = new SurfaceProjector();
          sp->initialize(gf, triangles);
        }

        if (delTriangles) {
          for (MTriangle* t: triangles) delete t;
        }

        if (clearGFace) {
          gf->triangles.clear();
          for (MVertex* v: gf->mesh_vertices) delete v;
          gf->mesh_vertices.clear();
        }

        return true;
      }
  };

  // bool fillGFaceInfo(GFace* gf, GFaceInfo& info) {
  //   info.gf = gf;
  //   info.chi = 0;
  //   info.cornerAngle.clear();
  //   info.cornerIsNonManifold.clear();
  //   for (auto& a: info.bdrValVertices) a.clear();
  //   info.intSumVal3mVal5 = 0;
  //
  //   if (gf->triangles.size() == 0) {
  //     if (gf->quadrangles.size() != 0) {
  //       Msg::Error("fillGFaceInfo: there are %li quads in face %li, cannot compute angles from triangles",
  //           gf->quadrangles.size(),gf->tag());
  //       return false;
  //     }
  //     Msg::Debug("compute trianguled mesh to fill GFaceInfo ...");
  //     int algo = gf->getMeshingAlgo();
  //     gf->setMeshingAlgo(ALGO_2D_FRONTAL);
  //     meshGFace mesher;
  //     mesher(gf);
  //     if (gf->triangles.size() == 0) {
  //       Msg::Error("failed to compute triangulated mesh for surface with tag %i", gf->tag());
  //       return -1;
  //     }
  //     gf->setMeshingAlgo(algo);
  //   }
  //   robin_hood::unordered_map<GVertex*,vector<MElement*> > corner2tris;
  //   robin_hood::unordered_map<GVertex*,double> corner2angle;
  //   for (MTriangle* t: gf->triangles) {
  //     for (size_t lv = 0; lv < 3; ++lv) {
  //       MVertex* v = t->getVertex(lv);
  //       GVertex* gv = v->onWhat()->cast2Vertex();
  //       if (gv != nullptr) {
  //         MVertex* vPrev = t->getVertex((3+lv-1)%3);
  //         MVertex* vNext = t->getVertex((lv+1)%3);
  //         SVector3 pNext = vNext->point();
  //         SVector3 pPrev = vPrev->point();
  //         SVector3 pCurr = v->point();
  //         double agl = angleVectors(pNext-pCurr,pPrev-pCurr);
  //         corner2tris[gv].push_back(t);
  //         corner2angle[gv] += agl;
  //       }
  //     }
  //   }
  //   robin_hood::unordered_set<GVertex*> boundaryCADcorners;
  //   for (GEdge* ge: gf->edges()) for (GVertex* gv: ge->vertices()) {
  //     boundaryCADcorners.insert(gv);
  //   }

  //   /* Check if corner is manifold */
  //   for (const auto& kv: corner2tris) {
  //     GVertex* gv = kv.first;
  //     {
  //       auto it = boundaryCADcorners.find(gv);
  //       if (it == boundaryCADcorners.end()) continue; /* ignore interior GVertex */
  //     }
  //     std::vector<MElement*> elts = kv.second;
  //     vector<MVertex*> bnd;
  //     bool okb = buildBoundary(elts.begin(),elts.end(), bnd);
  //     if (!okb) {
  //       info.cornerIsNonManifold.insert(gv);
  //       continue;
  //     }
  //     double angle = corner2angle[gv];
  //     double angle_deg = 180. / M_PI * angle;
  //     if (angle_deg < 90. + 45.) {
  //       info.bdrValVertices[1].insert(gv);
  //     } else if (angle_deg < 180. + 45.) {
  //       info.bdrValVertices[2].insert(gv);
  //     } else if (angle_deg < 270. + 45.) {
  //       info.bdrValVertices[3].insert(gv);
  //     } else if (angle_deg < 360.) {
  //       info.bdrValVertices[4].insert(gv);
  //     } else {
  //       Msg::Warning("CAD vertex (surf=%i,node=%i) has angle = %f deg (interior node ?)", gf->tag(), gv->tag(), angle_deg);
  //       continue;
  //     }
  //   }
  //   info.chi = surfaceEulerCharacteristicDiscrete(gf);

  //   /* discrete topological relations between irregular vertices:
  //    *  sum3m5 = n_val3 - n_val5 = 4 \chi + m_val3 - m_val1  + 2 m_val4 */
  //   info.intSumVal3mVal5 = 4*info.chi + int(info.bdrValVertices[3].size())
  //     - int(info.bdrValVertices[1].size()) + 2 * int(info.bdrValVertices[4].size());

  //   return true;
  // }

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
        Msg::Warning("singular vertex with num=%i not found in half edges vertices, vertex not in GFace quads ?", mv->getNum());
        continue;
      }
      M.vertices[it->second].isSingularity = true;
    }

    return 0;
  }

  bool boundaryHalfEdgesFromQuads(const MeshHalfEdges& M, const robin_hood::unordered_set<size_t>& quads,
      std::vector<size_t>& boundary) {
    robin_hood::unordered_set<size_t> hes;
    for (size_t f: quads) {
      size_t he = M.faces[f].he;
      do {
        hes.insert(he);
        he = M.next(he);
      } while (he != M.faces[f].he);
    }

    robin_hood::unordered_set<size_t>::iterator it_he = hes.begin();
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
    robin_hood::unordered_map<si2,size_t,si2hash> vPairCount;
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

  inline int valenceInsideQuads(const MeshHalfEdges& M, const robin_hood::unordered_set<size_t>& quads, size_t v) {
    constexpr size_t BSIZE = 48;
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

  inline int valenceOutsideQuads(const MeshHalfEdges& M, const robin_hood::unordered_set<size_t>& quads, size_t v) {
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


  const int FLIP_REJECTED = 0;
  const int FLIP_OK = 1;
  const int FLIP_INVALID_INPUT = 2;

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
    robin_hood::unordered_set<size_t> quads; /* quads inside, unordered_set for queries */


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
        // for (size_t he: hes_stack) {
        //   geolog_halfedge(M,he,double(he),"???");
        // }
        // GeoLog::flush();
        return false;
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

    int growByFlip(size_t i, /* i is index of half edge in hes */
        FlipInfo& info, bool rejectNewSings = true,
        std::vector<int>* valenceInCavity = NULL)
    {

      if (DBG_VERBOSE) {DBG("growByFlip ...", i, hes.size());}
      if (i >= hes.size()) {
        if (DBG_VERBOSE) {DBG("can't flip because", i, hes.size());}
        info.nq = NO_ID;
        return FLIP_INVALID_INPUT;
      }
      const size_t he0_op = hes[i];
      const size_t he0 = M.opposite(he0_op);
      if (he0 == NO_ID) {
        if (DBG_VERBOSE) {DBG("can't flip because", i, hes.size(), he0_op, he0);}
        info.nq = NO_ID;
        return FLIP_REJECTED; /* half-edge on bdr */
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
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he2_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return FLIP_REJECTED;
          }
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev_prev = (i + hes.size() - 2)%hes.size();
        hes[i_prev_prev] = he3;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        if (it0 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it0);
        auto it1 = std::find(hes.begin(),hes.end(),he1_op);
        if (it1 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it1);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); }
      } else if ( q1in && !q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he0_op,0);
        size_t nv2 = M.vertex(he0_op,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include singularity", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return FLIP_REJECTED;
          }
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        size_t i_prev = (i + hes.size() - 1)%hes.size();
        hes[i_prev] = he2;
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        if (it0 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it0);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        if (it3 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it3);
        if (DBG_VERBOSE) {DBG("flip -2v", i, info.nq); }
      } else if (!q1in &&  q2in &&  q3in) { /* minus two vertices on the bdr */
        size_t nv1 = M.vertex(he3,0);
        size_t nv2 = M.vertex(he3,1);
        if (rejectNewSings && (M.vertices[nv1].isSingularity || M.vertices[nv2].isSingularity)) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include singularity", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip -2v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he2_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip -2v, missing half-edges");
            return FLIP_REJECTED;
          }
        }
        info.nvs = {NO_ID,NO_ID,NO_ID,NO_ID};
        hes[i] = he1;
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        if (it2 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        if (it3 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
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
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv0].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv1].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv2].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nv3].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip closing hole rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op,he2_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel closing hole, missing half-edges");
            return FLIP_REJECTED;
          }
        }
        info.nvs = {nv0,nv1,nv2,nv3};
        auto it0 = std::find(hes.begin(),hes.end(),he0_op);
        if (it0 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it0);
        auto it1 = std::find(hes.begin(),hes.end(),he1_op);
        if (it1 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it1);
        auto it2 = std::find(hes.begin(),hes.end(),he2_op);
        if (it2 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it2);
        auto it3 = std::find(hes.begin(),hes.end(),he3_op);
        if (it3 == hes.end()) {
          Msg::Warning("growByFlip: half-edge not found in bdr, should never happen");
          return FLIP_INVALID_INPUT;
        }
        hes.erase(it3);
        std::vector<size_t> hes_stack = hes;
        bool oks = orderedHalfEdgesFromStack(this->M, hes_stack, this->hes);
        if (!oks) {
          Msg::Error("failed to determine sides from %li boundary half edges (%li quads)", hes_stack.size(), quads.size());
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        if (DBG_VERBOSE) {DBG("flip closing hole (may be too slow ?)", i, info.nq); }
      } else if ( q1in && !q2in && !q3in) { /* same number of vertices on the bdr */
        /* Check we are not creating a non-manifold edge boundary */
        const size_t nv = M.hedges[he2].vertex;
        int val;
        if (valenceInCavity != NULL) {
          val = (*valenceInCavity)[nv];
        } else {
          val = valenceInsideQuads(M, quads, nv);
        }
        if (val > 0) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because", i, info.nq, nv, val);}
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        const size_t nvIn = M.hedges[he0].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);}
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nvIn].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip <>1v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he1_op});
          if (!okv) {
            Msg::Warning("cancel flip <>1v, missing half-edges");
            return FLIP_REJECTED;
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
        int val;
        if (valenceInCavity != NULL) {
          val = (*valenceInCavity)[nv];
        } else {
          val = valenceInsideQuads(M, quads, nv);
        }
        if (val > 0) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because", i, info.nq, nv, val);}
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        const size_t nvIn = M.hedges[he0_op].vertex;
        if (rejectNewSings && M.vertices[nvIn].isSingularity) {
          if (DBG_VERBOSE) {DBG("no flip <>1v because would include sing", i, info.nq, nvIn, val);}
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        if (dynamic_cast<GVertex*>(M.vertices[nvIn].ptr->onWhat())) {
          if (DBG_VERBOSE) {DBG("flip <>1v rejected because would include GVertex", i, info.nq);}
          return FLIP_REJECTED;
        }
        if (PARANO) {
          bool okv = slowVerifyHalfEdgesInside({he0_op,he3_op});
          if (!okv) {
            Msg::Warning("cancel flip <>1v, missing half-edges");
            return FLIP_REJECTED;
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
        const size_t nv2 = M.hedges[he2].vertex;
        int val1,val2;
        if (valenceInCavity != NULL) {
          val1 = (*valenceInCavity)[nv1];
          val2 = (*valenceInCavity)[nv2];
        } else {
          val1 = valenceInsideQuads(M, quads, nv1);
          val2 = valenceInsideQuads(M, quads, nv2);
        }
        if (val1 > 0 || val2 > 0) {
          if (DBG_VERBOSE) {DBG("no flip +2v because", i, info.nq, nv1, val1);}
          info.nq = NO_ID;
          return FLIP_REJECTED;
        }
        if (rejectNewSings) {
          const size_t v0 = M.vertex(he0,0);
          if (M.vertices[v0].isSingularity && valenceOutsideQuads(M, quads, v0) == 2) {
            /* Would be concave corner around singularity, reject */
            if (DBG_VERBOSE) {DBG("no flip +2v because would be concave corner at sing.", i, info.nq);}
            return FLIP_REJECTED;
          }
          const size_t v1 = M.vertex(he0,1);
          if (M.vertices[v1].isSingularity && valenceOutsideQuads(M, quads, v1) == 2) {
            /* Would be concave corner around singularity, reject */
            if (DBG_VERBOSE) {DBG("no flip +2v because would be concave corner at sing.", i, info.nq);}
            return FLIP_REJECTED;
          }
        }
        /* Do the flip */
        hes[i] = he1;
        hes.insert(hes.begin()+i+1,{he2,he3});
        if (DBG_VERBOSE) {DBG("flip +2v", i, info.nq);}

        } else {
        if (DBG_VERBOSE) {DBG("flip config not supported", i, info.nq, he0, he1, he2, he3, q1in, q2in, q3in);}
        info.nq = NO_ID;
        return FLIP_REJECTED;
      }
      quads.insert(info.nq);
      return FLIP_OK;
    }

    int updateSides(std::vector<int>* valenceInCavity = NULL) {
      /* faster if valenceInCavity is already known and passed as argument*/

      // if (DBG_VERBOSE) {DBG("updateSides ...");}
      side.resize(hes.size());

      constexpr size_t BSIZE = 48;
      size_t faces[BSIZE];

      vector<bool> heFirstVertexIsCorner(hes.size(),false);
      for (size_t i = 0; i < hes.size(); ++i) {
        const size_t he = hes[i];
        const size_t v = M.vertex(he,0);
        if (valenceInCavity == NULL) {
          int val = M.vertexFaces(v, faces);
          if ((size_t) val >= BSIZE) {
            Msg::Error("valence is too high (%i) compared to buffer size %li, memory corrupted, abort", val, BSIZE);
            return 0;
          }
          int count = 0;
          for (size_t i = 0; i < (size_t) val; ++i) {
            if (quads.find(faces[i]) != quads.end()) count += 1;
            if (count > 1) break;
          }
          if (count == 1) heFirstVertexIsCorner[i] = true;
        } else {
          if ((*valenceInCavity)[v] == 1) {
            heFirstVertexIsCorner[i] = true;
          }
        }
      }

      // if (DBG_VERBOSE) {DBG(corners);}
      int sideNo = -1;
      for (size_t i = 0; i < hes.size(); ++i) {
        /* Look for a corner to start */
        if (!heFirstVertexIsCorner[i]) continue;

        /* Loop over all halfedges starting from corner */
        for (size_t j = 0; j < hes.size(); ++j) {
          const size_t he_pos = (i+j)%hes.size();
          if (heFirstVertexIsCorner[he_pos]) {
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

  const int GROW_MAXIMAL = 1;
  const int GROW_MINIMAL = 2;

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
    robin_hood::unordered_set<size_t> sings;
    /* singularities (flagged irregular) strictly on the cavity on the cavity boundary */
    robin_hood::unordered_set<size_t> singsBdr;
    /* irregular vertices (not sing.) inside, including bdr */
    robin_hood::unordered_set<size_t> irregular;
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
      robin_hood::unordered_set<size_t> limits = singsBdr;
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
        robin_hood::unordered_set<size_t> forbidden;
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
          int valOutside1 = valence[v1] - valenceInCavity[v1];
          if ((!vOnBoundary[v1] &&valOutside1 == 1)) {
            int ok = cav.growByFlip(i, info, true, &valenceInCavity);
            if (ok == FLIP_OK) {
              running = true;
              markNewQuad(info.nq);
            } else if (ok == FLIP_INVALID_INPUT) {
              return false;
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
          int ok = cav.growByFlip(i, info);
          if (ok == FLIP_OK) {
            nb += 1;
            running = true;
            markNewQuad(info.nq);
            break;
          } else if (ok == FLIP_INVALID_INPUT) {
            return false;
          }
        }
      }
      return true;
    }

    bool grow(
        int growthType,
        const std::vector<size_t>& patternsToCheck,
        const std::vector<std::pair<size_t,size_t> >& patternSizeLimits = {})
    {
      if (current == NULL) return false;
      if (growthType != GROW_MINIMAL && growthType != GROW_MAXIMAL) return false;
      FCavity& cav = *current;
      if (DBG_VERBOSE) Msg::Debug("grow: start with %li quads, %li half-edges on bdr ...", cav.quads.size(), cav.hes.size());
      bool running = true;
      size_t nb = 0;
      FlipInfo info;
      std::vector<size_t> candidates;
      size_t iter = 0;
      while (running) {
        iter += 1;
        if (iter > 1e6) {
          Msg::Error("grow: iter=%li, infinite loop ?", iter);
          break;
        }
        running = false;
        bool okc = getFlipHalfEdgeCandidates(candidates);
        if (!okc) {
          if (DBG_VERBOSE) Msg::Debug("grow: failed to get flip half edge candidates");
          break;
        }
        for (size_t k = 0; k < candidates.size(); ++k) {
          size_t he = candidates[k];
          auto it = std::find(cav.hes.begin(),cav.hes.end(),he);
          if (it == cav.hes.end()) continue;
          size_t pos = (size_t) (it - cav.hes.begin());
          int ok = cav.growByFlip(pos, info, true, &valenceInCavity);
          if (ok == FLIP_OK) {
            nb += 1;
            running = true;
            markNewQuad(info.nq);
            bool okf = convexify();
            if (!okf) {
              if (DBG_VERBOSE) Msg::Debug("grow: failed to convexify, stop growth");
              running = false;
              break;
            }
          } else if (ok == FLIP_INVALID_INPUT) {
            return false;
          }
        }
        if (running) {
          bool convex = isConvex();
          if (!convex) {
            if (DBG_VERBOSE) Msg::Debug("grow: cavity not convex, stop growth");
            running = false;
            // geolog_fcavity(cav, "!convex");
            break;
          } else {
            size_t nbi = irregular.size();
            if (nbi > lastNbIrregular) {
              int nsides = cav.updateSides(&valenceInCavity);
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
                if (DBG_VERBOSE) Msg::Debug("grow: check if cavity is remeshable");
                bool remeshable = cavityIsRemeshable(cav, irreg, patternsToCheckRefined);
                if (remeshable && irreg <= lastIrregularity && irreg < currentCavityIrregularity) {
                  /* Do not choose a pattern if strictly worse irregularity */
                  Msg::Debug("grow: set remeshable cavity (%li quads, irregularity=%f, #irreg=%li)", cav.quads.size(), irreg, nbi_oc);
                  lastCav = cav;
                  lastNbIrregular = nbi;
                  lastIrregularity = irreg;
                  if (growthType == GROW_MINIMAL) {
                    break;
                  }
                }
              }
            }
          }
        }
      } /* end of the while-loop growth */

      if (lastNbIrregular > 0) {
        if (M.faces.size() == cav.quads.size() && lastNbIrregular == (size_t) cavityTargetNbOfSides) {
          /* cavity is full face, which is triangle or quad or pentagon with the right number
           * of irregular vertices at the corners */
          Msg::Debug("grow: cavity is full face, exit");
          return false;
        }
        // geolog_fcavity(cav, "maxBeforeLast");
        cav = lastCav;
        Msg::Debug("grow: restore previous valid cavity");
      } else {
        return false;
      }

      Msg::Debug("grow: done, %li quads, %li half-edges on cavity bdr", cav.quads.size(), cav.hes.size());
      return true;
    }

  };


  bool convexifyQuads(const MeshHalfEdges& M, std::vector<size_t>& quadsVector) {
    robin_hood::unordered_set<size_t> quads;
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

  void removeElement(GFace* gf, MElement* e, robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj) {
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

  void removeVertex(MVertex* v, robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj) {
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

  inline void addToAdjacencyList(GFace* gf, MElement*e, robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj)
  {
    for (size_t i=0;i<e->getNumVertices();i++){
      MVertex* v = e->getVertex(i);
      adj[v].push_back(e);
    }
  }

  int vertexIdealValence(MVertex* v, const robin_hood::unordered_map<MVertex *, double>& vAngle) {
    auto it = vAngle.find(v);
    if (it == vAngle.end()) return 4;
    int ival = int(clamp(std::round(4. * it->second / (2. * M_PI)),1.,4.));
    return ival;
  }

  bool slowVerifyMeshIsValid(GFace* gf) {
    Msg::Debug("slow, verify mesh of face %i ...", gf->tag());
    robin_hood::unordered_map<MVertex *, std::vector<MElement *> > adj;
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
    robin_hood::unordered_map<MVertex*,int> qval;
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
      const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const robin_hood::unordered_map<MVertex *, double>& vAngle
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
      const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      vector<MElement*>& quads) {
    vector<MElement*> newQuads;
    for (MElement* q: quads) {
      for (size_t lv = 0; lv < 4; ++lv) {
        MVertex* v2 = q->getVertex(lv);
        auto it = adj.find(v2);
        if (it != adj.end()) {
          for (MElement* f2: it->second) {
            newQuads.push_back(f2);
          }
        }
      }
    }
    append(quads,newQuads);
    sort_unique(quads);
    return true;
  }

  bool remeshableVertexProperties(
      GFace* gf, MVertex* v,
      const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const robin_hood::unordered_map<MVertex *, double>& vAngle,
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
      const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const robin_hood::unordered_map<MVertex *, double>& vAngle,
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
      const robin_hood::unordered_map<MVertex *, std::vector<MElement *> >& adj,
      const robin_hood::unordered_map<MVertex *, double>& vAngle,
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
    robin_hood::unordered_map<MVertex*,MVertex*> old2new;
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

  bool remeshSmallDefects(GFace* gf, SurfaceProjector* sp = NULL) {
    Msg::Debug("- Face %i: remove small quad mesh defects (%li input quads) ...", gf->tag(), gf->quadrangles.size());
    size_t nq_in = gf->quadrangles.size();
    if (gf->quadrangles.size() == 0) return false;

    // TODO: detect and remove diamonds

    robin_hood::unordered_set<MVertex*> tried_bigger_cavity;
    robin_hood::unordered_set<MVertex*> doNotDegrade;

    robin_hood::unordered_map<MVertex *, double> vAngle; /* for flat corner on curves */
    robin_hood::unordered_map<MVertex *, std::vector<MElement *>> adj;
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
      if (gv->mesh_vertices.empty()) continue;
      MVertex* v = gv->mesh_vertices[0];
      if (v == NULL) continue;
      int ideal = vertexIdealValence(v, vAngle);
      auto it = adj.find(v);
      if (it == adj.end()) continue;
      std::vector<MElement*>& quads = it->second;
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

        /* Neighbors */
        std::vector<MElement*> neighbors;
        for (MVertex* bv: bnd) for (MElement* ne: adj[bv]) neighbors.push_back(ne);
        neighbors = difference(neighbors,quads);

        /* Get the remeshing with matching disk quadrangulation
         * (GFace is NOT modified by call to remeshFewQuads(), edition should confirmed after) */
        std::vector<MVertex*> newVertices;
        std::vector<bool> vertexIsIrregular;
        std::vector<MElement*> newElements;
        double qmin = 0.05;
        double qfactor = 0.1;
        int status = remeshFewQuads(gf, bnd, quads, bndIdealValence, bndAllowedValenceRange,
            newVertices, vertexIsIrregular, newElements, sp, qmin, qfactor, neighbors);
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
          Msg::Debug("failed to remesh around vertex %li (cavity with %li bdr vertices, %li quads)", num,
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

    if (gf->quadrangles.size() < 1000000) {
      Msg::Debug("-- Face %i: winslow smoothing (%li quads) ...", gf->tag(), gf->quadrangles.size());
      //      meshWinslow2d(gf, 10);
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
      const std::vector<size_t>& patternsToCheck,
      SurfaceProjector* sp = NULL
      ) {
    MeshHalfEdges& M = cav.M;

    /* Collect vertices on each side of the cavity */
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
      double qualityMin = 0.1;
      double qualityDegradeFactor = 0.66;
      int status = remeshPatchWithQuadPattern(gf, sides, patternNoAndRot,
          quads, newVertices, vertexIsIrregular, newElements,
          sp, qualityMin, qualityDegradeFactor);
      if (status != 0) {
        Msg::Debug("- Face %li, failed to remesh with selected quad pattern", gf->tag());
        return false;
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
      if (newElements.size() < 10000000) { // TODO: a fast smoothing... somehow
        Msg::Debug("-- Winslow smoothing of cavity (%li quads) ...", newElements.size());
        vector<MQuadrangle*> quadForWinslow(newElements.size());
        for (size_t i = 0; i < newElements.size(); ++i) {
          quadForWinslow[i] = dynamic_cast<MQuadrangle*>(newElements[i]);
        }
    //        meshWinslow2d(gf, quadForWinslow, newVertices, 10);
      }
    }

    if (SHOW_CAVITIES) {
      std::string cavity_name = "cav_s"+std::to_string(sideSizes.size())+"_after";
      geolog_elements(newElements, cavity_name);
      GeoLog::flush();
    }

    return true;
  }


  using CavityInputSig = std::array<long,3>;

  struct CIHash {
    size_t operator()(const CavityInputSig& p) const noexcept {
      uint32_t hash = 0;
      for (size_t i = 0; i < p.size(); ++i) {
        hash += p[i];
        hash += hash << 10;
        hash ^= hash >> 6;
      }
      hash += hash << 3;
      hash ^= hash >> 11;
      hash += hash << 15;
      return hash;
    }
  };

  CavityInputSig cavityInputSignature(const FCavity& cav) {
    CavityInputSig sig;
    sig[0] = cav.quads.size();
    sig[1] = cav.hes.size();
    sig[2] = 0;
    for (size_t f: cav.quads) sig[2] += cav.M.faces[f].ptr->getNum();
    return sig;
  }

  int remeshCavitiesAroundSingularities(GFace* gf, std::vector<MVertex*>& singularVertices,
      const std::vector<size_t>& patternsToCheck, SurfaceProjector* sp = NULL,
      double cpuTimeLimit = 0.)
  {
    Msg::Debug("- Face %i: remeshCavitiesAroundSingularities ...", gf->tag());
    double t1 = Cpu();

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;
    vector<SPoint3> repulsion;
    robin_hood::unordered_set<CavityInputSig,CIHash> cavityTried;

    constexpr bool DISTRIBUTE_DISTO = true;

    size_t count = 0;
    bool inProgress = true;
    while (inProgress) {
      inProgress = false;

      if (cpuTimeLimit > 0. && Cpu() - t1 > cpuTimeLimit) {
        Msg::Warning("  remeshing sing. cavities reached time limit (%fs)", cpuTimeLimit);
        break;
      }

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
      std::vector<std::pair<double,size_t> > prio_sing(singularities.size());
      if (DISTRIBUTE_DISTO) {
        /* we prioritize the ones which are far from the previously
         * remeshed cavities to "distribute" the disortion */
        for (size_t v = 0; v < M.vertices.size(); ++v) {
          if (M.vertices[v].isSingularity) {
            SPoint3 pt = M.vertices[v].ptr->point();
            double prio = 0.;
            for (const SPoint3& r: repulsion) {
              prio += pt.distance(r);
            }
            prio_sing.push_back({prio,v});
          }
        }
      } else {
        vector<double> priority;
        for (size_t v = 0; v < M.vertices.size(); ++v) {
          if (M.vertices[v].isSingularity) {
            singularities.push_back(v);
          } else {
            bool onBdr;
            int val = M.vertexFaceValence(v, onBdr);
            if (!onBdr && val != 4) irregularNodes.push_back(v);
          }
        }
        for (size_t i = 0; i < irregularNodes.size(); ++i) {
          size_t iv = irregularNodes[i];
          SVector3 ip = M.vertices[iv].p;
          for (size_t j = 0; j < singularities.size(); ++j) {
            SVector3 sp = M.vertices[singularities[j]].p;
            priority[j] += 1./(ip-sp).norm();
          }
        }
        for (size_t i = 0; i < singularities.size(); ++i)
          prio_sing[i] = {priority[i],singularities[i]};
      }

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
        //
        /* Build a cavity around singularity i */
        G.setCavity(fcav);

        bool okg = G.grow(GROW_MINIMAL,patternsToCheck);
        if (!okg) continue;

        if (SHOW_CAVITIES) {
          fcav.updateSides();
          std::string cavity_name = "cav_s"+std::to_string(quads.size())+"_"+std::to_string(v);
          geolog_fcavity(fcav, cavity_name + "_before");
        }

        /* Check if already tried */
        CavityInputSig sig = cavityInputSignature(fcav);
        bool alreadyTried = (cavityTried.find(sig) != cavityTried.end());
        if (alreadyTried) continue;
        cavityTried.insert(sig);

        /* Remesh the cavity */
        std::vector<MVertex*> newSingularities;
        size_t nq = gf->quadrangles.size();
        bool okr = remeshCavityWithQuadPatterns(gf,fcav,newSingularities,patternsToCheck,sp);
        if (okr) { /* then cavity and M are no longer valid, restart */
          size_t nq2 = gf->quadrangles.size();
          if (nq2 == nq)  {
            Msg::Debug("same number of quads in GFace after remeshing...");
          }

          /* update list of singular nodes */
          auto itv = std::find(singularVertices.begin(),singularVertices.end(),M.vertices[v].ptr);
          if (itv != singularVertices.end()) {
            singularVertices.erase(itv);
          }
          for (MVertex* v2: newSingularities) {
            singularVertices.push_back(v2);
            repulsion.push_back(v2->point());
          }
          inProgress = true;
          count += 1;
          break;
        } else {
          Msg::Debug("failed to remesh cavity at v=%li",v);
          // geolog_fcavity(fcav, "failed_cav"+std::to_string(v));
        }
      }
    }

    if (count > 0) {
      if (gf->quadrangles.size() < 10000000) {
    //        Msg::Debug("-- Winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
    //        meshWinslow2d(gf, 10);
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
    robin_hood::unordered_set<MVertex*> vIs3Of35Pair;
    robin_hood::unordered_set<MVertex*> vIs5Of35Pair;

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

      bool onGf = (dynamic_cast<GFace*>(M.vertices[v].ptr->onWhat()) != NULL);
      if (onGf) {
        GeoLog::add(SVector3(M.vertices[v].p),double(G.valence[v]),"base_complex_irreg");
      }

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
      robin_hood::unordered_map<GEdge*,vector<size_t> >& geQuads) {
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
  }

  int remeshQuadrilateralPatches(
      int growthType,
      GFace* gf, std::vector<MVertex*>& singularVertices,
      const std::vector<size_t>& patternsToCheck, SurfaceProjector* sp = NULL,
      double cpuTimeLimit = 0.) {
    Msg::Debug("- Face %i: remeshing quadrilateral cavities  ...", gf->tag());
    double t1 = Cpu();

    /* Remeshing parameters */
    // const std::vector<std::pair<size_t,size_t> > patternSizeLimits;
    const std::vector<std::pair<size_t,size_t> > patternSizeLimits = {
      {PATTERN_QUAD_DIAG35,100},
      {PATTERN_QUAD_ALIGNED35,200},
      {PATTERN_QUAD_CHORD_UTURN,100},
    };

    using std::priority_queue;
    using std::pair;

    MeshHalfEdges M;
    vector<size_t> pairs35;
    vector<size_t> singularities;
    vector<size_t> irregularNodes;
    vector<SPoint3> repulsion;

    size_t count = 0;
    const size_t PASS_ALONG_GEDGES = 1;
    const size_t PASS_FROM_IRREGULAR = 2;
    for (size_t pass : {PASS_ALONG_GEDGES, PASS_FROM_IRREGULAR}) {
      Msg::Debug("-- pass %li (0 = along GEdge, 1 = from irregular vertices)", pass);
      robin_hood::unordered_set<void*> tried;
      robin_hood::unordered_set<CavityInputSig,CIHash> cavityTried;
      bool inProgress = true;
      while (inProgress) {
        inProgress = false;

        if (cpuTimeLimit > 0. && Cpu() - t1 > cpuTimeLimit) {
          Msg::Warning("  remeshing quad cavities reached time limit (%fs)", cpuTimeLimit);
          break;
        }

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
          robin_hood::unordered_map<GEdge*,vector<size_t> > geQuads;
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
              SPoint3 approxPos = M.vertices[fvert[0]].ptr->point();
              double prio = 0.;
              for (const SPoint3& r: repulsion) {
                prio += approxPos.distance(r);
              }
              prio_quads.push_back({prio,{(void*)M.faces[f].ptr,{f}}});
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
          if (alreadyTried) continue;
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

          // Msg::Debug("------");
          // Msg::Debug("starting cavity (%li quads) (quadrilateral patch), i=%li, prio=%f",
          //     quads.size(), i, prio_quads[i].first);

          /* Build a cavity around singularity i */
          G.setCavity(fcav);
          G.cavityTargetNbOfSides = 4;

          SPoint3 approxPos(0.,0.,0.);
          { /* to distribute via repulsion */
            vector<size_t> fvert;
            M.face_vertices(quads[0],fvert);
            approxPos = M.vertices[fvert[0]].ptr->point();
          }

          bool okg = G.grow(growthType, patternsToCheck, patternSizeLimits);
          if (!okg) {
            continue;
          }

          /* Check if already tried */
          CavityInputSig sig = cavityInputSignature(fcav);
          bool cavAlreadyTried = (cavityTried.find(sig) != cavityTried.end());
          if (cavAlreadyTried) continue;
          cavityTried.insert(sig);

          std::string cavity_name = "cav_s"+std::to_string(quads.size());
          if (SHOW_CAVITIES) {
            fcav.updateSides();
            geolog_fcavity(fcav, cavity_name + "_before");
          }

          /* Remesh the cavity */
          std::vector<MVertex*> newSingularities;
          size_t nq = gf->quadrangles.size();

          Msg::Debug("------");
          bool okr = remeshCavityWithQuadPatterns(gf,fcav,newSingularities,patternsToCheck,sp);
          if (okr) { /* then cavity and M are no longer valid, restart */
            size_t nq2 = gf->quadrangles.size();
            if (nq2 == nq)  {
              Msg::Debug("same number of quads in GFace after remeshing...");
            } else {
              inProgress = true;
            }
            count += 1;
            /* Update repulsion */
            if (PASS_FROM_IRREGULAR) {
              repulsion.push_back(approxPos);
            }
            break;
          } else {
            Msg::Debug("failed to remesh cavity");
            // geolog_fcavity(fcav, "!" + cavity_name);
          }
        }
      }
    }

    if (count > 0) {
      if (gf->quadrangles.size() < 1000000) {
    //        Msg::Debug("-- Winslow smoothing of the face (%li quads) ...", gf->quadrangles.size());
    //        if (NITERWINSLOW)meshWinslow2d(gf, NITERWINSLOW);
      }
      Msg::Info("- Face %i: remeshed %li quadrilateral cavities  ...", gf->tag(), count);
    }

    return 0;
  }

  int meshSimpleFaceWithPattern(GFace* gf, const GFaceInfo& info,
      bool onlyCheckIfMeshable = false,
      bool checkTheSubdivision = false) {

    bool quadqsPatternsOnSimpleFaces = true;
    QMT_Utils::read_from_env("quadqsPatternsOnSimpleFaces", quadqsPatternsOnSimpleFaces);
    if (!quadqsPatternsOnSimpleFaces) return -1;

    /* Ensure compatible orientation with CAD */
    orientMeshGFace orient;
    orient(gf);

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
    // remove_element_if_inside(PATTERN_DISK, patternsToCheck);
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
      double qualityMin = 0.3;
      double qualityDegradeFactor = 0.75;
      int status = remeshPatchWithQuadPattern(gf, sideVertices, patternNoAndRot, oldElements,
          newVertices, vertexIsIrregular, newElements,
          info.sp, qualityMin, qualityDegradeFactor);
      if (status == 0) {
        // Msg::Debug("- Face %li: winslow smoothing ...", gf->tag());
        // meshWinslow2d(gf, 10);
        gf->meshStatistics.status = GFace::DONE;
        return 0;
      } else {
        Msg::Debug("Face %i, failed to remesh with selected quad pattern, weird", gf->tag());
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

  bool extractFaceQuadChords(GModel* gm,
      const std::map<GFace*, GFaceInfo>& faceInfo,
      std::vector<std::vector<GFace*> >& chordFaces) {
    chordFaces.clear();
    std::vector<GFace*> faces = model_faces(gm);
    std::set<GFace *> qfaces;
    for (GFace* gf: faces) {
      auto it = faceInfo.find(gf);
      if (it == faceInfo.end()) continue;
      const GFaceInfo& info = it->second;
      if (info.chi == 1 && gf->edges().size() == 4 && info.bdrValVertices[1].size() == 4) {
        qfaces.insert(gf);
      }
    }
    if (qfaces.size() == 0) return true;
    std::vector<std::set<GEdge *> > chords;
    build_chords(qfaces, chords);

    for(std::set<GEdge *> &chord : chords) {
      std::vector<GFace*> cfs;
      for (GFace* gf: qfaces) {
        for (GEdge* ge: gf->edges()) {
          bool inside = (chord.find(ge) != chord.end());
          if (inside) {
            cfs.push_back(gf);
            break;
          }
        }
      }
      sort_unique(cfs);
      chordFaces.push_back(cfs);
    }

    return true;
  }

  bool curveQuantizationSimpleChords(GModel* gm, const std::map<GFace*, GFaceInfo>& faceInfo, bool forceEvenNbEdges = false) {
    // TODO: check difference #points along chords, split if necessary

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
      constexpr bool setCurveTransfinite = false; /* uniform repartition of vertices, quite bad */
      constexpr bool setFaceTransfinite = true; /* works without transfinite curves */

      std::vector<std::set<GEdge *> > chords;
      bool checkNumberOfPoints = true;
      double checkMaxDiff = 0.25;
      build_chords(qfaces, chords, checkNumberOfPoints, checkMaxDiff);

      /* Determine the number of points, set the transfinite curves */
      Msg::Debug("computeQuadCurveMeshConstraints: assigning number of points ...");
      std::size_t ne = 0;
      for(std::set<GEdge *> &chord : chords) {
        bool chordOk = true;
        int forcedN = -1;

        double avgNbPoints = 0;
        int nMax = 0;
        for(GEdge *ge : chord) {
          if (ge->meshAttributes.method == MESH_TRANSFINITE) {
            /* GEdge has already a transfinite constraint */
            size_t N = ge->meshAttributes.nbPointsTransfinite;
            nMax = std::max(nMax,(int)N);
            if (forcedN == -1) {
              forcedN = N;
            } else if (forcedN != int(N)) { /* Incoherent transfinite constraints on chord ... */
              Msg::Warning("curve quantization: conflict in existing transfinite constraints on quad loop");
              chordOk = false;
            }
          } else {
            if (ge->meshAttributes.prescribedNumberOfEdges > 0) {
              Msg::Warning("curve quantization: existing prescribedNumberOfEdges");
            }
            int n = meshGEdgeTargetNumberOfPoints(ge);
            avgNbPoints += double(n);
            nMax = std::max(n,nMax);
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
          // N = nMax;
          if(N == 0) N = 2;
          if (forceEvenNbEdges && N % 2 == 0) {
            N = closestPositiveOdd(avgNbPoints);
          }
        }

        Msg::Debug("- chord with %li edges -> %i points\n", chord.size(), N);

        if (setCurveTransfinite) {
          for(GEdge *ge : chord) {
            if (ge->meshAttributes.method != MESH_TRANSFINITE) {
              ge->meshAttributes.method = MESH_TRANSFINITE;
              ge->meshAttributes.nbPointsTransfinite = N;
              ge->meshAttributes.typeTransfinite = 1; /* Progression */
              ge->meshAttributes.coeffTransfinite = 1.;
              ge->meshAttributes.prescribedNumberOfEdges = N-1;
              ne += 1;
            }
          }
        } else {
          for(GEdge *ge : chord) {
            if (ge->meshAttributes.method != MESH_TRANSFINITE) {
              ge->meshAttributes.prescribedNumberOfEdges = N-1;
              ne += 1;
            }
          }
        }
      }

      if (setFaceTransfinite) {
        for (GFace* gf: qfaces) if (gf->edges().size() == 4) {
          std::vector<int> ns;
          for (GEdge* ge: gf->edges()) {
            if (ge->meshAttributes.prescribedNumberOfEdges != 0) {
              ns.push_back(ge->meshAttributes.prescribedNumberOfEdges);
            }
          }
          if (ns.size() != 4) continue;
          DBG(gf->tag(),ns);
          sort_unique(ns);
          if (ns.size() != 1 && ns.size() != 2) {
            Msg::Error("- Face %i: imcompatible constraints", gf->tag());
            continue;
          }
          gf->meshAttributes.method = MESH_TRANSFINITE;
          gf->meshAttributes.recombine = 1;
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

  bool curveQuantizationSimpleRings(GModel* gm, const std::map<GFace*, GFaceInfo>& faceInfo, bool forceEvenNbEdges = false) {
    std::set<GFace *> qfaces;
    for (GFace* gf: model_faces(gm)) {
      auto it = faceInfo.find(gf);
      if (it == faceInfo.end()) continue;
      const GFaceInfo& info = it->second;
      if (info.chi == 0 && gf->edges().size() == 2) { /* Ring ! */
        GEdge* ge1 = gf->edges()[0];
        GEdge* ge2 = gf->edges()[1];
        int n1 = ge1->meshAttributes.prescribedNumberOfEdges+1;
        int n2 = ge2->meshAttributes.prescribedNumberOfEdges+1;
        if (n1 > 1 && n2 > 1) continue;
        int n = 0;
        if (n1 > 1 && n2 == 1) n = n1;
        if (n1 == 1 && n2 > 1) n = n2;
        if (n1 == 1) n1 = meshGEdgeTargetNumberOfPoints(ge1);
        if (n2 == 1) n2 = meshGEdgeTargetNumberOfPoints(ge2);
        double rel = std::abs(double(n1-n2))/std::max(double(n1),double(n2));
        if (rel < 0.25) { /* less than 25% diff */
          if (n == 0) n = std::max(n1,n2);
          if (n < 2) n = 2;
          ge1->meshAttributes.prescribedNumberOfEdges = n - 1;
          ge2->meshAttributes.prescribedNumberOfEdges = n - 1;
        }
      }
    }
    return true;
  }

  bool curveQuantizationSimpleSnapping(GModel* gm, const std::map<GFace*, GFaceInfo>& faceInfo, double threshold = 0.2, bool forceEvenNbEdges = false) {
    /* Would be better to do mean shift clustering */
    size_t ns = 0;
    for (GFace* gf: model_faces(gm)) {
      auto it = faceInfo.find(gf);
      if (it == faceInfo.end()) continue;

      vector<int> qvalues;
      for (GEdge* ge: gf->edges()) {
        if (ge->meshAttributes.prescribedNumberOfEdges > 0) {
          qvalues.push_back(ge->meshAttributes.prescribedNumberOfEdges+1);
        }
      }
      sort_unique(qvalues);

      for (GEdge* ge: gf->edges()) {
        if (ge->meshAttributes.prescribedNumberOfEdges == 0) {
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
            ge->meshAttributes.prescribedNumberOfEdges = N-1;
            // ge->meshAttributes.method = MESH_TRANSFINITE;
            // ge->meshAttributes.nbPointsTransfinite = N;
            // ge->meshAttributes.typeTransfinite = 1; /* Progression */
            // ge->meshAttributes.coeffTransfinite = 1.;
            qvalues.push_back(N);
            ns += 1;
          } else {
            ge->meshAttributes.prescribedNumberOfEdges = e-1;
            // ge->meshAttributes.method = MESH_TRANSFINITE;
            // ge->meshAttributes.nbPointsTransfinite = e;
            // ge->meshAttributes.typeTransfinite = 1; /* Progression */
            // ge->meshAttributes.coeffTransfinite = 1.;
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
    robin_hood::unordered_map<GVertex*,std::set<GEdge*> > gv2ge;
    robin_hood::unordered_map<GEdge*,int> geNbPoints;
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


  bool CadStatistics(GModel* gm, unordered_map<std::string,double>& stats) {
    stats["CAD_n_corners"] = double(gm->getVertices().size());
    stats["CAD_n_curves"] = double(model_edges(gm).size());
    stats["CAD_n_faces"] = double(model_faces(gm).size());
    stats["CAD_n_volumes"] = double(gm->getRegions().size());
    return true;
  }

  bool quadMeshStatistics(GModel* gm, unordered_map<std::string,double>& stats) {
    /* Stats on regularity of vertices */
    vector<MQuadrangle*> all_quads;
    {
      std::vector<int> nValFace(10,0);
      std::vector<int> nValCurve(10,0);
      std::vector<int> nValCorner(10,0);
      double nVert = 0.; /* repetition on shared GVertex / GEdge */
      double nQuad = 0.;
      for (GFace* gf: model_faces(gm)) {
        append(all_quads,gf->quadrangles);
        unordered_map<MVertex *, std::vector<MElement *> > adj;
        for (MQuadrangle* f: gf->quadrangles) {
          nQuad += 1.;
          for (size_t lv = 0; lv < 4; ++lv) {
            MVertex* v = f->getVertex(lv);
            adj[v].push_back(f);
          }
        }
        for (auto& kv: adj) {
          nVert += 1.;
          MVertex* v = kv.first;
          GEntity* ent = v->onWhat();
          bool onCorner = (dynamic_cast<GVertex*>(ent) != NULL);
          bool onCurve = (dynamic_cast<GEdge*>(ent) != NULL);
          bool onFace = (dynamic_cast<GFace*>(ent) != NULL);
          int val = (int) kv.second.size();
          if (onCorner) {
            if ((size_t)val >= nValCorner.size()) nValCorner.resize(val+1);
            nValCorner[val] += 1;
          } else if (onCurve) {
            if ((size_t)val >= nValCurve.size()) nValCurve.resize(val+1);
            nValCurve[val] += 1;
          } else if (onFace) {
            if ((size_t)val >= nValFace.size()) nValFace.resize(val+1);
            nValFace[val] += 1;
          }
        }
      }
      double regular = 0.;
      double irregular = 0.;
      double very_irregular = 0.;
      double val3 = 0.;
      double val5 = 0.;
      for (size_t val = 0; val < nValCurve.size(); ++val) {
        if (val == 2) {
          regular += double(nValCurve[val]);
        } else if (val == 1 || val == 3){
          irregular += double(nValCurve[val]);
        } else {
          very_irregular += double(nValCurve[val]);
        }
      }
      for (size_t val = 0; val < nValFace.size(); ++val) {
        if (val == 4) {
          regular += double(nValFace[val]);
        } else if (val == 3) {
          irregular += double(nValFace[val]);
          val3 += double(nValFace[val]);
        } else if (val == 5) {
          irregular += double(nValFace[val]);
          val5 += double(nValFace[val]);
        } else {
          very_irregular += double(nValFace[val]);
        }
      }
      stats["Mesh_n_quads"] = nQuad;
      stats["Mesh_n_vertices"] = nVert;
      stats["Mesh_n_regular"] = regular;
      stats["Mesh_n_irregular"] = irregular;
      stats["Mesh_n_very_irregular"] = very_irregular;
      stats["Mesh_n_val3"] = val3;
      stats["Mesh_n_val5"] = val5;
    }

    /* Quality stats */
    if (all_quads.size() > 0){
      vector<double> quality(all_quads.size());
      double edge_len_min = DBL_MAX;
      double edge_len_avg = 0.;
      double edge_len_max = 0.;
      double edge_n = 0.;
      double avg = 0.;
      for (size_t f = 0; f < all_quads.size(); ++f) {
        quality[f] = all_quads[f]->minSICNShapeMeasure();
        avg += quality[f];
        for (size_t le = 0; le < 4; ++le) {
          SPoint3 p1 = all_quads[f]->getVertex(le)->point();
          SPoint3 p2 = all_quads[f]->getVertex((le+1)%4)->point();
          double len = p1.distance(p2);
          edge_len_min = std::min(edge_len_min, len);
          edge_len_max = std::max(edge_len_max, len);
          edge_len_avg += len;
          edge_n += 1.;
        }
      }
      avg /= quality.size();
      edge_len_avg /= edge_n;
      std::sort(quality.begin(),quality.end());
      stats["SICN_min"] = quality[0];
      stats["SICN_avg"] = avg;
      stats["SICN_max"] = quality.back();
      stats["SICN_01% <"] = quality[size_t(0.01*double(quality.size()))];
      stats["SICN_10% <"] = quality[size_t(0.10*double(quality.size()))];
      stats["SICN_25% <"] = quality[size_t(0.25*double(quality.size()))];
      stats["SICN_50% <"] = quality[size_t(0.50*double(quality.size()))];
      stats["SICN_75% <"] = quality[size_t(0.75*double(quality.size()))];
      stats["SICN_90% <"] = quality[size_t(0.90*double(quality.size()))];
      stats["SICN_99% <"] = quality[size_t(0.99*double(quality.size()))];

      stats["Mesh_edge_min"] = edge_len_min;
      stats["Mesh_edge_avg"] = edge_len_avg;
      stats["Mesh_edge_max"] = edge_len_max;
    }


    return true;
  }

  void printStatistics(const unordered_map<std::string,double>& stats, const std::string& title = "Statistics:") {
    std::vector<std::string> keys;
    for (auto& kv: stats) keys.push_back(kv.first);
    std::sort(keys.begin(),keys.end());
    Msg::Info("%s", title.c_str());;
    for (std::string key: keys) {
      double val = stats.at(key);
      if (std::trunc(val) == val) {
        Msg::Info("- %s: %i", key.c_str(),int(val));
      } else {
        Msg::Info("- %s: %f", key.c_str(),val);
      }
    }
  }

  void writeStatistics(const unordered_map<std::string,double>& stats, const std::string& path) {
    std::vector<std::string> keys;
    for (auto& kv: stats) keys.push_back(kv.first);
    std::sort(keys.begin(),keys.end());

    std::ofstream out(path);
    out << "{\n";
    for (size_t i = 0; i < keys.size(); ++i) {
      std::string key = keys[i];
      double val = stats.at(key);
      if (std::trunc(val) == val) {
        out << key << ": " << int(val);
      } else {
        out << key << ": " << val ;
      }
      if ((int)i < (int)keys.size()-1) {
        out << ",\n";
      } else {
        out << "\n";
      }
    }
    out << "}\n";
    out.close();
  }
}
using namespace QSQ_matteo;

/* vec3 math */
inline double dot      (const vec3& a, const vec3& b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
inline double length2  (const vec3& a) { return dot(a,a); }
inline double length   (const vec3& a) { return sqrt(length2(a)); }
inline vec3 operator-(const vec3& a, const vec3& b) { return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
inline vec3 operator+(const vec3& a, const vec3& b) { return {a[0]+b[0], a[1]+b[1], a[2]+b[2]}; }
inline vec3 operator*(const double& a, const vec3& b) { return {a*b[0], a*b[1], a*b[2]}; }
inline vec3 operator*(const vec3& a, const double& b) { return {a[0]*b, a[1]*b, a[2]*b}; }
inline vec3 cross(const vec3& a, const vec3& b) { return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};}
inline vec3 normalize(vec3 v) { return v * double(1./length(v)); }
// inline double clamp(double x, double lower, double upper) { return std::min(upper, std::max(x, lower)); }
inline double angle_nvectors(vec3 a, vec3 b) { return acos(clamp(dot(a,b),-1.,1.)); }
inline double angle_vectors(vec3 a, vec3 b) { a = normalize(a); b = normalize(b); return angle_nvectors(a,b); }

// Pair of indices
using si2 = array<size_t,2>;
// overload << for si2
ostream &operator<<(ostream &os, si2 v) {
    os << "(" << v[0] << ", " << v[1] << ")"; return os; }

// Quadruple of indices
using si4 = array<size_t,4>;
// overload << for si4
ostream &operator<<(ostream &os, si4 v) {
    for(size_t i = 0; i < 4; ++i) os << (i?", ":"(") << v[i];
    os << ")"; return os; }

// // Overload << for vector
// template<class T> ostream &operator<<(ostream &os, vector<T> v) {
//     for(size_t i = 0; i < v.size(); ++i) os << (i?", ":"[") << v[i];
//     os << "]"; return os; }

struct si2hash {
  size_t operator()(std::array<size_t,2> p) const noexcept {
    return size_t(p[0]) << 32 | p[1];
  }
};
inline si2 sorted(size_t v1, size_t v2) { if (v1 < v2) { return {v1,v2}; } else { return {v2,v1}; } }


// Dual Half-Edge Data Structure
struct DualHalfEdge {
    size_t i; // index if DHE (note that i//4 == face index)
    DualHalfEdge* forward;
    DualHalfEdge* left;
    DualHalfEdge* right; // == left.opposite.forward
    DualHalfEdge* opposite;
    // size_t iFace; // origin of arrow (destination == forward.face)
};

// Build dual half-edges
vector<DualHalfEdge*> buildDualHalfEdges(const vector<MQuadrangle*>& quads,
        const vector<si4>& adj) {
    // Implicit numbering: quad i has dual half edges 4i..4i+3
    vector<DualHalfEdge*> dualHalfEdges(4*quads.size());
    for(size_t i = 0; i < dualHalfEdges.size(); ++i) dualHalfEdges[i] = new DualHalfEdge;
    for(size_t i = 0; i < quads.size(); ++i) {
        for(size_t le = 0; le < 4; ++le) {
            dualHalfEdges[4*i+le]->i = 4*i+le;
            size_t j = adj[i][le] / 4;
            for(size_t je = 0; je < 4; ++je) {
                if(adj[j][je] == 4*i+le) {
                    dualHalfEdges[4*i+le]->opposite = dualHalfEdges[4*j+je];
                    dualHalfEdges[4*i+le]->right = dualHalfEdges[4*j+(je+1)%4];
                    dualHalfEdges[4*i+le]->forward = dualHalfEdges[4*j+(je+2)%4];
                    dualHalfEdges[4*i+le]->left = dualHalfEdges[4*j+(je+3)%4];
                    break;
                }
            }
        }
    }
    return dualHalfEdges;
}



// // Build adjacency list of quads
// bool buildAdjacencies(const vector<MQuadrangle*>& quads, vector<si4>& adj) {
//     adj.resize(quads.size(), {NO_ID,NO_ID,NO_ID,NO_ID});
//     map<si2,si2> vPairToQuads; // (v1,v2) -> (4f1+e1, 4f2+e2)
//     for (size_t i = 0; i < quads.size(); ++i) {
//         MQuadrangle* f = quads[i];
//         for(size_t le = 0; le < 4; ++le) {
//             size_t v1 = f->getVertex(le)->getNum();
//             size_t v2 = f->getVertex((le+1)%4)->getNum();
//             si2 vPair = {v1,v2}; sort(vPair.begin(), vPair.end());
//             if(vPairToQuads.find(vPair) == vPairToQuads.end()) {
//                 vPairToQuads[vPair] = {4*i+le, NO_ID};
//             } else {
//                 si2& qPair = vPairToQuads[vPair];
//                 if(qPair[1] == NO_ID) {
//                     if(qPair[0] == NO_ID) {
//                         Msg::Error("Should not happen!");
//                         return false;
//                     }
//                     qPair[1] = 4*i+le;
//                     adj[i][le] = qPair[0];
//                     adj[qPair[0]/4][qPair[0]%4] = qPair[1];
//                 } else {
//                     Msg::Error("Non-manifold quad mesh (>2 quads share an edge)");
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }

// vector<MElement*> extractQuadLoop(DualHalfEdge* start) {
//     DualHalfEdge* u = start;
//     vector<MElement*> elementsToShow;
//     do {
//         elementsToShow.push_back(quads[u->iFace]);
//         u = u->forward;
//     } while(u != start);
//
// }

// void geolog_elements(const std::vector<MElement*>& elts, const std::string& name,
//     double value = 0.) {
//     for(int iface = 0; iface < elts.size(); iface++) {
//         MElement* f = elts[iface];
//           vector<array<double,3> > pts(f->getNumVertices());
//           for (size_t i = 0; i < pts.size(); ++i) {
//             pts[i] = SVector3(f->getVertex(i)->point());
//           }
//           vector<double> values(pts.size(),(double)iface/elts.size());
//           // vector<double> values(pts.size(), value);
//           GeoLog::add(pts,values,name);
//     }
// }

using id = uint32_t;
using id2 = std::array<id,2>;
using id4 = std::array<id,4>;

/* Quad mesh data structure */
struct QMesh {
    vector<vec3> vertices;
    vector<id2> edges; // edge = pair of vertices
    vector<id4> faces; // face = 4 edges
};

// Edge of T-mesh
struct TEdge {
    size_t p; // patch
    size_t s; // side of patch (0..3)
    size_t i; // index along patch side
    size_t len; // integer length
    size_t he; // first half-edge
    size_t opposite; // index of opposite TEdge
    // TEdge() : p1(NO_ID), p2(NO_ID), s1(NO_ID), s2(NO_ID), i1(NO_ID), i2(NO_ID) {};
    // size_t p1, p2; // adjacent patches
    // size_t s1, s2; // side of patches (0..3)
    // size_t i1, i2; // index of TEdge along patch sides
    // int len; // integer length
};



const bool ERROR_VISU = true;

/* sformat inspired from variadic printf at
 * https://web.archive.org/web/20131018185034/http://www.generic-programming.org/~dgregor/cpp/variadic-templates.html */
static inline void sformat(std::ostream& out, const char* s) {
  while (*s) {
    if (*s == '{' && *++s != '}')
      throw std::runtime_error("invalid format string: missing arguments");
    out << *s++;
  }
}

template<typename T, typename... Args>
  static void sformat(std::ostream& out, const char* s, const T& value, const Args&... args) {
    while (*s) {
      if (*s == '{' && *++s == '}') {
        out << value;
        return sformat(out, ++s, args...);
      }
      out << *s++;
    }
    printf("! sformat problem, input: %s\n",s);
    throw std::runtime_error("extra arguments provided to printf");
  }


/************************************/
/* Formatting and Logging functions */
template <typename... Args>
  void error(const char* format, const Args & ... args) {
    std::ostringstream stream;
    sformat(stream, format, args...);

    gmsh::logger::write("QMT | Cross Field | " + stream.str(), "error");
  }

template <typename... Args>
  void warn(const char* format, const Args & ... args) {
    std::ostringstream stream;
    sformat(stream, format, args...);
    gmsh::logger::write("QMT | Cross Field | " + stream.str(), "warning");
  }

template <typename... Args>
  void info(const char* format, const Args & ... args) {
    std::ostringstream stream;
    sformat(stream, format, args...);
    gmsh::logger::write("QMT | Cross Field | " + stream.str(), "info");
  }
/************************************/

// Transfinite Interpolation, for computing interior points
bool transfinite_interpolation(
    const vector<vec3>& c1,
    const vector<vec3>& c2,
    const vector<vec3>& c3,
    const vector<vec3>& c4,
    vector<vec3>& pts) {
  if (c1.size() <= 2 || c2.size() <= 2 || c3.size() <= 2 || c4.size() <= 2) {
    Msg::Error("cannot TFI, c1.size=%d, c2.size=%d, c3.size=%d, c4.size=%d", c1.size(),c2.size(),c3.size(),c4.size());
    return false;
  }
  if (c1.size() != c3.size() || c2.size() != c4.size()) {
    Msg::Error("cannot TFI, c1.size=%d, c2.size=%d, c3.size=%d, c4.size=%d", c1.size(),c2.size(),c3.size(),c4.size());
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


// Resample polyline
bool compute_subdivided_edge_internal_points(const std::vector<vec3>& pts, size_t N, vector<vec3>& newPts) {
  newPts.clear();
  if (N == 0) return true;

  /* Size map size(t) */
  vector<vec3> failed_probes;
  vector<double> size(pts.size(),0.);
  F(i, size.size()) {
    // size[i] = sizemap.eval(pts[i]);
    size[i] = 1;
    if (size[i] == DBL_MAX) {
      failed_probes.push_back(pts[i]);
    }
  }

  vector<double> Pri(pts.size(),0.);
  /* Integral of inverse, Pri = int(1/size(t),t) */
  double totalLen = 0.;
  F(i,pts.size()-1.) {
    double len = length(pts[i+1]-pts[i]);
    totalLen += len;
    Pri[i+1] = Pri[i] + 0.5 * (1./double(size[i]) + 1./double(size[i+1])) * len;
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

  constexpr bool NAIVE = false;
  size_t prev_j = 0;
  double prev_acc = 0.;
  F(i,N) {
    double targetLen = targetLens[i];

    bool found = false;
    if (NAIVE) {
      double len_j = 0.;
      for(size_t j = 0; j < pts.size()-1; ++j) {
        double acc = length(pts[j+1]-pts[j]);
        double len_jp1 = len_j + acc;

        if (len_j < targetLen && targetLen <= len_jp1) {
          double lambda = (targetLen - len_j) / (len_jp1 - len_j);
          vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
          // double h = (1.-lambda) * size[j] + lambda * size[j+1];
          newPts.push_back(pt);
          // newSizes.push_back(h);
          found = true;
          break;
        }

        len_j = len_jp1;
      }
    } else {
      double acc = prev_acc;
      for(size_t j = prev_j; j < pts.size()-1; ++j) {
        double len_j = acc;
        acc += length(pts[j+1]-pts[j]);
        double len_jp1 = acc;

        if (len_j < targetLen && targetLen <= len_jp1) {
          double lambda = (targetLen - len_j) / (len_jp1 - len_j);
          vec3 pt = (1.-lambda) * pts[j] + lambda * pts[j+1];
          // double h = (1.-lambda) * size[j] + lambda * size[j+1];
          newPts.push_back(pt);
          // newSizes.push_back(h);
          found = true;
          prev_j = j;
          prev_acc = len_j;
          break;
        }
      }
    }
    if (!found) {
      cout << "sample point not found !" << endl;
      return false;
    }
  }

  if (ERROR_VISU && failed_probes.size() > 0) {
    F(i,failed_probes.size()) {
      GeoLog::add({failed_probes[i]},double(i), "compute_subdivided_edge_internal_points");
    }
    GeoLog::flush();
  }
  RFC(failed_probes.size() > 0, "compute_subdivided_edge_internal_points | {} probe failures", failed_probes.size());

  return true;
}



bool generate_quad_mesh_from_quantization(
       MeshHalfEdges& M, // original mesh (described by its half-edges)
       vector<array<vector<size_t>,4>> patches, // patch description
       vector<TEdge>& tedges, // T-edges
       vector<int>& edge_n, // new T-edge lenghts
       QMesh& Q // new mesh after remeshing
       ) {     
    cout << "generating quad mesh from quantization ..." << endl;
  srand(42);

  /*
  // Copy vertices and initialize vertex mapping
  V<id> old2new(S(M.vertices), NO_ID); // map old vertices to new vertices
  Q.vertices.clear();
  F(v, S(M.vertices)) {
    Q.vertices.append(M.vertices[v]);
    old2new[v] = M.vertices[v];
  }
  */

  //// Collapse zero-area patches
  //for(id p = 0; p < S(patches); p++) { // for every patch
    //for(id s = 0; s < 4; s++) { // for every side of patch
      //j
    //}
  //}

  //for(id ite = 0; ite < S(tedges); ite++) {
    //TEdge tedge = tedges[ite];
    //if(edge_n[ite] == 0) {
      //id he = tedge.he;
      //vec3 v1 = M.vertices[M.vertex(he,0)].p;
      //F(j, tedge.len) {
        //he = M.next(M.opposite(M.next(he)));
        //F(k, 3) // TODO: overload '=' operator for vec3
          //M.vertices[M.vertex(he,0)].p[k] = v1[k];
      //}
    //}
  //}

  F(p, S(patches)) { // for every patch
    F(s,4) { // for every side of the patch
      //int len = 0; // total side length
      F(i, S(patches[p][s])) { // for every T-edge on side
        id ite = patches[p][s][i];
        TEdge tedge = tedges[ite];
        if(edge_n[ite] == 0) {
          V<id> vertices_on_tedge;
          id he = tedge.he;
          vertices_on_tedge.pb(M.vertex(he,0));
          F(j, tedge.len) {
            he = M.next(M.opposite(M.next(he)));
            vertices_on_tedge.pb(M.vertex(he,0));
          }
          // Compute median vertex
          vec3 vm;
          if(tedge.len % 2 == 1) {
            vm = (M.vertices[vertices_on_tedge[tedge.len/2]].p + M.vertices[vertices_on_tedge[tedge.len/2+1]].p);
            F(k,3) vm[k] /= 2;
          } else vm = M.vertices[vertices_on_tedge[tedge.len/2]].p;
          // Repalce vertices with vm
          F(j, S(vertices_on_tedge)) {
            F(k,3) M.vertices[vertices_on_tedge[j]].p[k] = vm[k];
          }
          //vec3 v1 = M.vertices[M.vertex(he,0)].p;
          //F(j, tedge.len) {
            //he = M.next(M.opposite(M.next(he)));
            //F(k, 3) // TODO: overload '=' operator for vec3
              //M.vertices[M.vertex(he,0)].p[k] = v1[k];
          //}
          if(S(patches[p][s]) == 1) { // if the collapsed T-edge is the only one on side
            int len = 0;
            id s1 = (s+1)%4;
            F(j,S(patches[p][s1])) len += tedges[patches[p][s1][j]].len;
            id he1 = tedges[patches[p][s1][0]].he;
            id he2 = M.opposite(M.prev(tedge.he));
            F(j,len) {
              id v1 = M.vertex(he1,0);
              id v2 = M.vertex(he2,0);
              vec3 vm = M.vertices[v1].p + M.vertices[v2].p;
              F(k,3) {
                vm[k] /= 2;
                M.vertices[v1].p[k] = vm[k];
                M.vertices[v2].p[k] = vm[k];
              }
              he1 = M.next(M.opposite(M.next(he1)));
              he2 = M.next(M.opposite(M.next(he2)));
            }
          }
        }
      }
    }
  }


  vector<bool> done(tedges.size(), false);

  // Create interior points by transfinite interpolation
  for(size_t p = 0; p < patches.size(); p++) { // for every patch
    array<vector<vec3>,4> side_vertices; // new (internal) vertices on sides of patch
    for(size_t s = 0; s < 4; s++) { // for every side of patch
       for(size_t i = 0; i < patches[p][s].size(); i++) { // for every T-edge of side
           //if(done[patches[p][s][i]]) continue;
           id ite = patches[p][s][i]; // T-edge ID
           TEdge tedge = tedges[ite];
           // Mark this T-edge as done
           done[patches[p][s][i]] = true;
           done[tedge.opposite] = true;

           if(tedge.len != tedges[tedge.opposite].len)
               error("len != opposite.len!!!");

           vector<vec3> pts(tedge.len+1); // list of points lying on T-edge (including endpoints)
           size_t he = tedge.he;
           for(size_t i = 0; i <= tedge.len; i++) {
               pts[i] = M.vertices[M.vertex(he,0)].p;
               he = M.next(M.opposite(M.next(he)));
               //GeoLog::add({pts[i]}, 1, "pts");
           }

           // TODO: what if tedge.len == 0 ?
           vector<vec3> ipts; // new internal points for T-edge
           if(edge_n[ite] > 0) {
             size_t nb_ipts = edge_n[ite]-1; // number of internal points
             bool oks = compute_subdivided_edge_internal_points(pts, nb_ipts, ipts);
             if (!oks) {
                 error("failed to sample edge {}, nb_ipts={}", ite, nb_ipts);
                 return false;
             }
           }
           // geolog new points
           //GeoLog::add({pts[0]}, 1, "internal points");
           //F(i, ipts.size()) GeoLog::add({ipts[i]}, 1, "internal points");

           // Put all new points in a single data structure side_vertices
           if(edge_n[ite] > 0) side_vertices[s].push_back(pts[0]);
           for(size_t j = 0; j < ipts.size(); j++)
               side_vertices[s].push_back(ipts[j]);
           if(i == patches[p][s].size()-1) // if last T-edge of side,
               side_vertices[s].push_back(pts[pts.size()-1]); // put endpoint

           for(id i = 1; i < S(side_vertices[s]); i++) {
               //GeoLog::add({side_vertices[s][i-1], side_vertices[s][i]}, 0, "new T-mesh");
           }
       }
    }
    // TODO: interior points via TFI
    //if(S(side_vertices[0]) > 1 && S(side_vertices[1]) > 1) {
    V<vec3> ipts;
    id n = S(side_vertices[0]), m = S(side_vertices[1]);
    if(n > 2 && m > 2) 
      transfinite_interpolation(side_vertices[0], side_vertices[1], side_vertices[2], side_vertices[3], ipts);

    //F(i, S(ipts)) GeoLog::add({ipts[i]}, (double)i/S(ipts), "interior points");

    V<V<vec3>> apts(n, V<vec3>(m)); // side_vertices + ipts
    F(i, n) {
      F(j, m) {
        if(i == 0) apts[i][j] = side_vertices[3][m-1-j];
        else if(j == 0) apts[i][j] = side_vertices[0][i];
        else if(i == n-1) apts[i][j] = side_vertices[1][j];
        else if(j == m-1) apts[i][j] = side_vertices[2][n-1-i];
        else apts[i][j] = ipts[(i-1)+(j-1)*(n-2)];
      }
    }

    double patch_color = ((double)rand()) / RAND_MAX;
    cout << patch_color << endl;
    F(i,n) F(j,m) {
      if(i < n-1) GeoLog::add({apts[i][j], apts[i+1][j]}, 0, "new edges");
      if(j < m-1) GeoLog::add({apts[i][j], apts[i][j+1]}, 0, "new edges");
      if(i < n-1 && j < m-1) GeoLog::add({apts[i][j], apts[i+1][j], apts[i+1][j+1], apts[i][j+1]}, patch_color, "new faces");
    }

    //FR(i, -1, n+1) FR(j, -1, m+1) {
      //vec3 u;
      //if(i == -1) u = side_vertices[0][j+1];
      //else if(j == -1) u = side_vertices[1][i+1];
      //else if(
      //GeoLog::add({
          //ipts[i+j*n],
          //ipts[i+1+j*n]
      //}, 0, "new edges"); // right edge
      //GeoLog::add({
          //ipts[i+j*n], 
          //ipts[i+(j+1)*n]
      //}, 0, "new edges"); // top edge
    //}

    //F(i, n) GeoLog::add({S(side_vertices[1]) == 2 ? side_vertices[2][1+i] : ipts[i+0*n], side_vertices[0][1+i]}, 0, "new edges");
    ////F(j, m) GeoLog::add({ipts[0+j*n], side_vertices[3][m-j]}, 0, "new edges");
    //F(i, n) {
      //F(j, m) {
        ////if(i == 0) GeoLog::add({ipts[i+j*n], side_vertices[3][m-j]}, 0, "new edges");
        //if(i < n-1) GeoLog::add({ipts[i+j*n], ipts[i+1+j*n]}, 0, "new edges");
        //else GeoLog::add({ipts[i+j*n], side_vertices[1][1+j]}, 0, "new edges");
        ////if(j == 0) GeoLog::add({ipts[i+j*n], side_vertices[0][1+i]}, 0, "new edges");
        //if(j < m-1) GeoLog::add({ipts[i+j*n], ipts[i+(j+1)*n]}, 0, "new edges");
        //else GeoLog::add({ipts[i+j*n], side_vertices[2][n-i]}, 0, "new edges");
      //}
    //}
    //F(k,4) {
      //for(id i = 1; i < S(side_vertices[k]); i++)
        //GeoLog::add({side_vertices[k][i-1], side_vertices[k][i]}, 0, "new edges");
    //}
  }
  return true;
}

struct edge { id i,d; }; // i = neighbor, d = distance
bool operator<(edge a, edge b) { return a.d > b.d; }

void alignQuadMesh(GModel* gm) {

    // create model and search engine
    SendMoreMoney* m = new SendMoreMoney;
    DFS<SendMoreMoney> e(m);
    delete m;
    // search and print all solutions
    while (SendMoreMoney* s = e.next()) {
      s->print(); delete s;
    }
    return;


    // Extract quads from model
    vector<MQuadrangle*> quads;
    for(GFace* gf : gm->getFaces()) {
        QSQ_matteo::append(quads, gf->quadrangles);
    }

    // Compute valence of each vertex
    unordered_map<MVertex*, size_t> valence;
    for(MQuadrangle* q : quads) {
        for(size_t le = 0; le < 4; ++le) {
            MVertex* v = q->getVertex(le);
            if(v->onWhat()->cast2Face() != NULL) // why?
                ++valence[v];
        }
    }

    // Store irregular vertices
    vector<MVertex*> singularVertices;
    for(auto& it : valence)
        if(it.second != 4)
            singularVertices.push_back(it.first);

    // Compute mesh half-edges
    MeshHalfEdges M;
    createMeshHalfEdges(quads, M, singularVertices);

    // For every singular vertex that is NOT a geometric vertex,
    // trace streamlines until meeting another sing vertex or GEdge
    vector<bool> isOnPatchBoundary(M.hedges.size(), false);
    for(Vertex vertex : M.vertices) {
        if(vertex.isSingularity && dynamic_cast<GVertex*>(vertex.ptr->onWhat()) == NULL) {
            // GeoLog::add(vertex.p, 0, "singular vertex");
            size_t he_start = M.opposite(vertex.he);
            for(int i = 0; i < valence[vertex.ptr]; i++) {
                he_start = M.next(M.opposite(he_start));
                size_t he = he_start;
                while(true) {
                    //geolog_halfedge(M, he, 1, "T mesh");
                    isOnPatchBoundary[he] = isOnPatchBoundary[M.opposite(he)] = true;
                    // If we land on a singular vertex or a geometric edge: stop
                    if(M.vertices[M.vertex(he,1)].isSingularity || dynamic_cast<GEdge*>(M.vertexPtr(he,1)->onWhat()) != NULL) break;
                    he = M.next(M.opposite(M.next(he)));
                }
            }
        }
    }

    // Draw and flag geometric edges
    for(size_t he = 0; he < M.hedges.size(); ++he) {
        if((dynamic_cast<GEdge*>(M.vertexPtr(he,1)->onWhat()) != NULL && dynamic_cast<GEdge*>(M.vertexPtr(he,0)->onWhat()) != NULL) ||
        (dynamic_cast<GVertex*>(M.vertexPtr(he,1)->onWhat()) != NULL && dynamic_cast<GEdge*>(M.vertexPtr(he,0)->onWhat()) != NULL)) {
            //geolog_halfedge(M, he, 1, "T mesh");
            isOnPatchBoundary[he] = isOnPatchBoundary[M.opposite(he)] = true;
        }
    }

    // Assign patches to quads
    vector<size_t> quad2patch(M.faces.size(), NO_ID);
    vector<vector<size_t>> patch2quads;
    size_t patch_index = 0;
    for(size_t fs = 0; fs < M.faces.size(); fs++) {
        if(quad2patch[fs] == NO_ID) {
            patch2quads.push_back(vector<size_t>());
            std::queue<size_t> q; // queue of quads
            q.push(fs); quad2patch[fs] = patch_index;
            while(!q.empty()) {
                size_t f = q.front(); q.pop();
                patch2quads[patch_index].push_back(f);
                size_t he = M.faces[f].he;
                for(int k = 0; k < 4; k++) {
                    if(!isOnPatchBoundary[he]) {
                        size_t af = M.hedges[M.opposite(he)].face; // adjacent face
                        if(quad2patch[af] == NO_ID) {
                            quad2patch[af] = patch_index;
                            q.push(af);
                        }
                    }
                    he = M.next(he);
                }
            }
            patch_index++;
        }
    }

    cout << "There are " << patch_index << " patches." << endl;
    // Geolog patches
    //for(size_t p = 0; p < patch2quads.size(); p++) {
        //// if(p != 0) continue;
        //double color = rand();
        //for(size_t f : patch2quads[p])
            //geolog_face(M, f, color, "patches");
    //}


    // Build T-mesh
    int cnt = 0; // counter for half-edges on patch boundaries
    vector<TEdge> tedges;
    vector<size_t> halfEdge2TEdge(M.hedges.size(), NO_ID); // map half-edges to T-edge they lie on
    vector<bool> isPatchProcessed(patch2quads.size(), false);
    vector<array<vector<size_t>,4>> patches(patch2quads.size()); // patches[p][s][i] == t-edge
    for(size_t hes = 0; hes < M.hedges.size(); hes++) {
        size_t he = hes;
        if(!isOnPatchBoundary[he]) continue;
        ++cnt;
        size_t p = quad2patch[M.hedges[he].face]; // current patch
        if(isPatchProcessed[p]) continue;
        cout << "Processing patch #" << p << endl;
        size_t count_tedges = 0;
        isPatchProcessed[p] = true;
        while(quad2patch[M.hedges[he].face] == p) { // while we're still on the patch
            he = M.next(M.opposite(M.next(he)));
        }
        he = M.opposite(M.prev(he)); // now he has origin at some corner of p
        for(size_t s = 0; s < 4; s++) { // for each side of the patch
            if(quad2patch[M.hedges[he].face] != p) cout << "ERROR" << endl;
            size_t i = 0; // index along side
            while(quad2patch[M.hedges[he].face] == p) {
                TEdge tedge;
                tedge.p = p, tedge.s = s, tedge.i = i++, tedge.he = he;
                size_t oppositeTEdge = halfEdge2TEdge[M.opposite(he)];
                if(oppositeTEdge != NO_ID) {
                    tedge.opposite = oppositeTEdge; // assign opposite of current
                    tedges[oppositeTEdge].opposite = tedges.size(); // assign opposite of opposite
                }
                tedge.len = 0;
                size_t adjPatch = quad2patch[M.hedges[M.opposite(he)].face];
                while(quad2patch[M.hedges[he].face] == p && quad2patch[M.hedges[M.opposite(he)].face] == adjPatch) {
                    tedge.len++;
                    halfEdge2TEdge[he] = tedges.size(); // index of current TEdge
                    he = M.next(M.opposite(M.next(he)));
                }
                patches[p][s].push_back(tedges.size());
                tedges.push_back(tedge);
                ++count_tedges;
            }
            he = M.opposite(M.prev(he));
        }
        cout << "Added " << count_tedges << " T-edges" << endl;
    }
    cout << "There are " << cnt << " half-edges on patch boundaries" << endl;
    cout << "There are " << tedges.size() << " T-edges" << endl;
    for(TEdge tedge : tedges) {
        cout << "p = " << tedge.p << ", s = " << tedge.s << ", i = " << tedge.i << ", opp = " << tedge.opposite << endl;
    }

    // Build graph D (vertices = T-edges)
    int n_edges = 0;
    vector<vector<size_t>> D(tedges.size());
    for(size_t p = 0; p < patches.size(); p++) {
        for(size_t s = 0; s < 4; s++) {
            for(size_t t1 : patches[p][s]) {
                for(size_t t2 : patches[p][(s+2)%4]) {
                    // if(t1 == 0) cout << t2 << endl;
                    D[t1].push_back(tedges[t2].opposite);
                    ++n_edges;
                }
            }
        }
    }
    cout << "Graph D has " << tedges.size() << " vertices and " << n_edges << " edges." << endl;

    //// Build T-edge graph
    //std::set<id> unique_vertices;
    //V<id> v2t(S(M.vertices), NO_ID);
    //V<id> t2v;
    //F(ite, S(tedges)) unique_vertices.insert(M.vertex(tedges[ite].he, 0));
    //cout << "There are " << S(unique_vertices) << " vertices in the T-graph" << endl;
    //for(id v : unique_vertices) {
      //v2t[v] = S(t2v);
      //t2v.pb(v);
    //}
    //V<V<edge>> tgraph(S(t2v));
    //F(ite, S(tedges)) {
      //TEdge tedge = tedges[ite];
      //id he = tedge.he;
      //id u = M.vertex(he, 0);
      //F(k,tedge.len) he = M.next(M.opposite(M.next(he)));
      //id v = M.vertex(he, 0);
      //tgraph[v2t[u]].pb({v2t[v], (id)tedge.len});
    //}
    //// Dijkstra
    //id s = 0; 
    //GeoLog::add({M.vertices[t2v[s]].p}, 0, "s");
    ////id s; while(!M.vertices[s].isSingularity) s++; // start vertex (any singularity)
    //V<id> dist(S(tgraph), NO_ID); dist[s] = 0;
    //V<id> par(S(tgraph), NO_ID); // parent
    //std::priority_queue<edge> pq; pq.push({s, 0});
    //while(S(pq)) {
      //edge u = pq.top(); pq.pop();
      //if(dist[u.i] < u.d) continue;
      //for(edge v : tgraph[u.i]) {
        //if(M.vertices[v.i].isSingularity) cout << "singular vertex!" << endl;
        //v.d += u.d;
        //if(dist[v.i] > v.d) {
          //dist[v.i] = v.d; par[v.i] = u.i; pq.push(v);
        //}
      //}
    //}
    //id t = NO_ID, min_dist = NO_ID;
    //F(u, S(tgraph)) if(u != s && dist[u] < min_dist) t = u, min_dist = dist[u];
    //V<id> path; path.pb(t);
    //id u = t;
    //while(u != s) {
      //u = par[u];
      //path.pb(u);
    //}
    //cout << path << endl;

    //gmsh::initialize();
    //GeoLog::flush();
    //gmsh::fltk::run();

    //exit(0);

    // Determine new T-edge lengths
    int max_len_to_remove = 2;
    V<int> edge_n(S(tedges));
    F(ite, S(tedges)) edge_n[ite] = tedges[ite].len;
    //cout << max_len_to_remove << endl;
    for(int len_to_remove = 1; len_to_remove <= max_len_to_remove; ++len_to_remove) {
      //cout << "coucou" << endl;
      while(true) {
        //cout << "coucou" << endl;
        // Find starting T-edge
        size_t start = -1;
        FC(ite, S(tedges), edge_n[ite] == len_to_remove) {
          start = ite;
          break;
        }
        if(start == -1) break;
        // Find shortest cycle going through a given node, using BFS
        std::queue<size_t> q; q.push(start);
        vector<size_t> d(D.size(), -1); d[start] = 0; // distance to start
        vector<size_t> p(D.size(), -1); // parent
        bool done = false;
        while(!done && !q.empty()) {
            size_t u = q.front(); q.pop();
            for(size_t v : D[u]) {
                if(p[v] == -1 && edge_n[v] >= len_to_remove) {
                    d[v] = d[u]+1, p[v] = u;
                    if(v == start) {
                        done = true;
                        break;
                    }
                    q.push(v);
                }
            }
        }
        // Update edge lengths
        size_t u = start;
        do {
            u = p[u];
            edge_n[u] -= len_to_remove;
            edge_n[tedges[u].opposite] -= len_to_remove;
        } while(u != start);
        // Possible pitfall: cycle traversing a T-edge twice in opposite directions, causing negative length!
      }
    }

    cout << edge_n << endl;

    //// Find start T-edge
    //size_t start = -1;
    //for(size_t tedge = 0; tedge < tedges.size(); tedge++) {
        //if(tedges[tedge].len == 1) {
            //start = tedge;
            //break;
        //}
    //}

    //// Find shortest cycle going through a given node, using BFS
    //// size_t start = 1;
    //std::queue<size_t> q; q.push(start);
    //vector<size_t> d(D.size(), -1); d[start] = 0; // distance to start
    //vector<size_t> p(D.size(), -1); // parent
    //bool done = false;
    //while(!done && !q.empty()) {
        //size_t u = q.front(); q.pop();
        //for(size_t v : D[u]) {
            //if(p[v] == -1) {
                //d[v] = d[u]+1, p[v] = u;
                //if(v == start) {
                    //done = true;
                    //break;
                //}
                //q.push(v);
            //}
        //}
    //}
    //// Construct cycle
    //size_t u = start;
    //vector<size_t> cycle;
    //do {
        //u = p[u];
        //cycle.push_back(u);
    //} while(u != start);
    //// cycle.push_back(start);
    //reverse(cycle.begin(), cycle.end());
    //cout << cycle << endl;

    //// Initialize new edge lengths
    //vector<int> edge_n(S(tedges));
    //F(ite, S(tedges)) edge_n[ite] = tedges[ite].len;

    //// Draw cycle
    //size_t color = 0;
    //for(size_t tedge : cycle) {
        //size_t he = tedges[tedge].he;
        //for(size_t i = 0; i < tedges[tedge].len; i++) {
            ////geolog_halfedge(M, he, 1, "cycle");
            //he = M.next(M.opposite(M.next(he)));
        //}
        //// TODO: this is very ugly, pls chng
        //size_t oppos = tedges[tedge].opposite;
        //edge_n[tedge] = tedges[tedge].len-1;
        //edge_n[oppos] = tedges[oppos].len-1;
        //++color;
    //}

    //cout << edge_n << endl;

    // for(size_t he = 0; he < halfEdge2TEdge.size(); he++) {
    //     if(isOnPatchBoundary[he] && vis[halfEdge2TEdge[he]])
    //         geolog_halfedge(M, he, 1, "T-edge cycle");
    //     // if(isOnPatchBoundary[he]) cout << halfEdge2TEdge[he] << endl;
    // }

    // // MOTORCYCLE GRAPH (not needed for now)
    // vector<size_t> particles; // half-edges at the front of the streamlines
    // vector<bool>
    // for(Vertex vertex : M.vertices) {
    //     if(vertex.isSingularity) {
    //         size_t he = M.opposite(vertex.he);
    //         for(int i = 0; i < valence[vertex.ptr]; i++) {
    //             particles.push_back(he);
    //             he = M.next(M.opposite(he));
    //         }
    //     }
    // }
    // while()
    
    QMesh new_mesh;

    generate_quad_mesh_from_quantization(M, patches, tedges, edge_n, new_mesh);

    gmsh::initialize();
    GeoLog::flush();
    gmsh::fltk::run();

    exit(0);






    vector<si4> adj; // adjacency list of quads
    buildAdjacencies(quads, adj);

        vector<DualHalfEdge*> dualHalfEdges = buildDualHalfEdges(quads, adj);
        vector<size_t> dheToParametricLine(4*quads.size(), NO_ID);
    vector<vector<size_t>> parametricLines; // quads forming the parametric line

    int counter = 0;

    size_t nParametricLines = 0;
    for(size_t iDualHalfEdge = 0; iDualHalfEdge < 4*quads.size(); iDualHalfEdge++) {
        // If the DHE has no parametric line yet
        if(dheToParametricLine[iDualHalfEdge] == NO_ID) {
            parametricLines.push_back(vector<size_t>());
            DualHalfEdge* start = dualHalfEdges[iDualHalfEdge];
            DualHalfEdge* u = start;
            do {
                dheToParametricLine[u->i] = dheToParametricLine[u->opposite->i] = nParametricLines;
                parametricLines[nParametricLines].push_back(u->i/4);
                u = u->forward;
            } while(u != start);
            counter += parametricLines[nParametricLines].size();
            cout << parametricLines[nParametricLines].size() << endl;
            nParametricLines++;
        }
    }

    cout << counter << endl;

    // gmsh::initialize();
    // gmsh::fltk::run();


    // for(size_t iFace = 0; iFace < quads.size(); ++iFace) {
    //     cout << "iFace = " << iFace << ", ";
    //     size_t iPL0 = dheToParametricLine[4*iFace], iPL1 = dheToParametricLine[4*iFace+1];
    //     int counter = 0;
    //     if(iPL0 != iPL1) {
    //         cout << "orthogonal parametric lines are distinct" << endl;
    //         cout << "parametric lines: " << iPL0 << ' ' << iPL1 << endl;
    //         // if orthogonal parametric lines are distinct (no self-intersection)
    //         vector<size_t>& PL0 = parametricLines[iPL0], PL1 = parametricLines[iPL1];
    //         DualHalfEdge * dhe0 = dualHalfEdges[4*iFace];
    //         for(size_t h = 1; h < PL0.size(); ++h) {
    //             dhe0 = dhe0->forward;
    //             DualHalfEdge * dhe1 = dualHalfEdges[4*iFace+1];
    //             for(size_t tau = 1; tau < PL1.size(); ++tau) {
    //                 dhe1 = dhe1->forward;
    //                 if(dhe0->i / 4 == dhe1->i / 4) {
    //                     ++counter;
    //                     cout << "h = " << h << ", tau = " << tau << endl;
    //                     cout << "face = " << dhe0->i / 4 << endl;
    //
    //                     // vector<MElement*> paramSegment0, paramSegment1;
    //                     // dhe0 = dualHalfEdges[4*iFace], dhe1 = dualHalfEdges[4*iFace+1];
    //                     // for(size_t h_ = 0; h_ <= h; ++h_) {
    //                     //     paramSegment0.push_back(quads[dhe0->i/4]);
    //                     //     dhe0 = dhe0->forward;
    //                     // }
    //                     // for(size_t tau_ = 0; tau_ <= tau; ++tau_) {
    //                     //     paramSegment1.push_back(quads[dhe1->i/4]);
    //                     //     dhe1 = dhe1->forward;
    //                     // }
    //                     // geolog_elements(paramSegment0, "quad loop", 0);
    //                     // geolog_elements(paramSegment1, "othogonal quad loop", 1);
    //                     //
    //                     // gmsh::initialize();
    //                     // GeoLog::flush();
    //                     // gmsh::fltk::run();
    //                     // exit(0);
    //                 }
    //             }
    //         }
    //     } else {
    //         cout << "self-intersection" << endl;
    //     }
    //     // if(iFace == 100) exit(0);
    //     cout << endl;
    //     // if(counter > 1) exit(0);
    // }

    // cout << nParametricLines << endl;
    // for(size_t i = 0; i < nParametricLines; ++i) {
    //     for(size_t j = i+1; j < nParametricLines; ++j) {
    //         vector<size_t> sortedParametricLine1 = parametricLines[i]; sort(sortedParametricLine1.begin(), sortedParametricLine1.end());
    //         vector<size_t> sortedParametricLine2 = parametricLines[j]; sort(sortedParametricLine2.begin(), sortedParametricLine2.end());
    //         cout << sortedParametricLine1 << endl;
    //         cout << sortedParametricLine2 << endl;
    //         return;
    //     }
    // }
    //
    // cout << parametricLines[0] << endl;
    // cout << parametricLines[1] << endl;




    // for(size_t if = 0; if < quads.size(); if++) {
    //     DualHalfEdge* u = dualHalfEdges[4*if];
    //
    // }
    //
    // DualHalfEdge* start = dualHalfEdges[0];
    //
    // DualHalfEdge* u = start;
    // vector<MElement*> quadLoop;
    //
    // do {
    //     quadLoop.push_back(quads[u->i/4]);
    //     u = u->forward;
    // } while(u != start);
    //
    // u = start = start->opposite->left;
    // vector<MElement*> quadLoopOrtho;
    // do {
    //     quadLoopOrtho.push_back(quads[u->i/4]);
    //     u = u->forward;
    // } while(u != start);
    //
    // geolog_elements(quadLoop, "quad loop", 0);
    // geolog_elements(quadLoopOrtho, "othogonal quad loop", 1);
    //
    gmsh::initialize();
    GeoLog::flush();
    gmsh::fltk::run();
}
#else

void alignQuadMesh(GModel* gm) {
  Msg::Error("Module GECODE required for alignQuadMesh");
  return;
}

#endif

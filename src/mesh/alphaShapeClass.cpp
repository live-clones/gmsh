#include "GmshConfig.h"
#include <cwchar>
#ifdef HAVE_HXT
#include <math.h>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
#include "alphaShapeClass.h"

#include "gmsh.h"
#include "Context.h"
#include "GmshMessage.h"
#include "SPoint3.h"
#include "meshOctreeLibOL.h"
#include "discreteRegion.h"
#include "discreteFace.h"
#include "meshGRegion.h"
#include "MElementOctree.h"
#include "GModel.h"

#ifdef _OPENMP
#include "omp.h"
#endif

#include <time.h>
#include <ctime>
#include <chrono>
#include <iostream>
#include <unordered_set>
#include "robin_hood.h"
#include "BackgroundMeshTools.h"
#include "Field.h"
#include "SPoint3KDTree.h"

extern "C" {
#include "libol1.h"
}
extern "C" {
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetOpti.h"
#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_tetRefine.h"
#include "hxt_tetRepair.h"
#include "hxt_curvature.h"
#include "hxt_boundary_recovery.h"

}

std::map<int, AlphaShapeClass*> asMap;

int SUPER_ELEMENT = -INT_MAX; // elements connected to super element data is -int_max

AlphaShapeClass::AlphaShapeClass(const std::string &name):
    _name(name)
{
    _pm = nullptr;
    _bb = nullptr;

    _GModelOctree = nullptr;
    _bndEdges = std::vector<_alphaShapeBndEdge>();
    _bndNodes = std::unordered_set<size_t>();

    _alphaShapeOctree = nullptr;
    _meshTriangles = std::vector<_meshTriangle>();

    _asNodes = std::vector<size_t>();
    _asTriangles = std::vector<std::vector<size_t>>();
    _asEdges = std::vector<std::vector<size_t>>();
}

void AlphaShapeClass::clear() {
    if (_pm) {
      _pm->reset();
      _pm = nullptr;
    }
    if (_bb) delete _bb;
    _pm = nullptr;
    _bb = nullptr;
    _asNodes.clear();
    _asTriangles.clear();
    _asEdges.clear();
}

void AlphaShapeClass::triangulate(const std::vector<double> &vertices, const bool removeExistingVertices){
  if (removeExistingVertices)
    clear();
  if (_pm == nullptr) {
    _pm = new PolyMesh;
  }
  std::vector<SPoint3> points(vertices.size() / 3);
  for (size_t i = 0; i < vertices.size() / 3; i++) {
    points[i] = SPoint3(vertices[3 * i + 0], vertices[3 * i + 1], vertices[3 * i + 2]);
    }
    if (_bb == nullptr){
      _bb = new SBoundingBox3d;
      for(size_t i=0; i<vertices.size()/3; i++) {
        *_bb += points[i];
      }
      *_bb *= 10;
      initialize_rectangle(_pm, _bb->min().x(), _bb->max().x(), _bb->min().y(),
                              _bb->max().y());
      for (auto v: _pm->vertices) {
        v->data = -1; // reset vertex data
      }
    }
    else {
      bool recreate = false;
      for(size_t i=0; i<vertices.size()/3; i++) {
        if (points[i].x() < _bb->min().x() || points[i].x() > _bb->max().x() ||
          points[i].y() < _bb->min().y() || points[i].y() > _bb->max().y()) {
          Msg::Warning("Point (%f, %f) is outside the bounding box; recreating bounding box", points[i].x(), points[i].y());
          recreate = true;
          break;
        }
      }
      if (recreate){
        std::vector<double> newVertices;
        for(auto v : _pm->vertices) {
          if (v->data < 0) continue; // only keep vertices that are not used
          newVertices.push_back(v->position.x());
          newVertices.push_back(v->position.y());
          newVertices.push_back(v->position.z());
        }
        for(auto v : points) {
          newVertices.push_back(v.x());
          newVertices.push_back(v.y());
          newVertices.push_back(v.z());
        }
        _pm->reset();
        _bb->reset();
        _pm = nullptr;
        _bb = nullptr;
        triangulate(newVertices, false);
        return;
      }
    }
    PolyMesh::Face* f = _pm->faces[0];
    for(auto &v : points) {
        f = WalkGeneral(f, v.x(), v.y());
        _pm->split_triangle(0, v.x(), v.y(), 0, f, delaunayCriterion, nullptr);
        _pm->vertices.back()->data = _pm->vertices.size() - 1; // set vertex data to the index of the vertex
    }
    size_t i=0;
    for (auto f : _pm->faces){
        int i0 = f->he->v->data;
        int i1 = f->he->next->v->data;
        int i2 = f->he->next->next->v->data;
        if(i0 < 0 || i1 < 0 || i2 < 0) 
            f->data = SUPER_ELEMENT;
        else
            f->data = i; // reset face data
        i++;
    }
}

void AlphaShapeClass::getNodes(std::vector<double> &vertices) {
    vertices.clear();
    for (size_t i=4; i<_pm->vertices.size(); i++) {
        auto v = _pm->vertices[i];
        if (v->data < 0){
          Msg::Error("Vertex %lu has no data, it is not part of the alpha shape", i);
          return; // skip super vertices
        }
        vertices.push_back(v->position.x());
        vertices.push_back(v->position.y());
        vertices.push_back(v->position.z());
    }
}

void AlphaShapeClass::getElements(std::vector<size_t> &elementNodes) {
    elementNodes.clear();
    for (size_t i=0; i<_pm->faces.size(); i++) {
        auto f = _pm->faces[i];
        if (f->data == SUPER_ELEMENT || f->he == nullptr) continue; // skip faces connected to super vertices
        PolyMesh::HalfEdge *he = f->he;
        do {
            elementNodes.push_back(he->v->data);
            he = he->next;
        } while (he != f->he);
    }
}

void faceCircumCenter(PolyMesh::HalfEdge *he, double *res, double* R)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  double q0[3] = {v0->position.x(), v0->position.y(), v0->position.z()};
  double q1[3] = {v1->position.x(), v1->position.y(), v1->position.z()};
  double q2[3] = {v2->position.x(), v2->position.y(), v2->position.z()};
  circumCenterXYZ(q0, q1, q2, res, NULL);
  double v[3] = {q0[0] - res[0], q0[1] - res[1], q0[2] - res[2]};
  *R = norm3(v);
}


void AlphaShapeClass::alphaShape2D(const double alpha, const std::vector<double> &sizeAtElements){  
    size_t nElsPm = 0; 
    for (auto f : _pm->faces){
      if (f->data > SUPER_ELEMENT && f->he != nullptr) nElsPm++;
    }
    if (sizeAtElements.size() != nElsPm)
    Msg::Error("The shape of sizeAtElements (%lu) does not match the number of elements in the mesh (%lu).", sizeAtElements.size(), nElsPm);
    for (auto he : _pm->hedges){
      if(he->opposite == nullptr) continue;
      if(he->v->data < 0 || he->opposite->v->data < 0) {
        he->data = -2; // not yet processed
        he->opposite->data = -2; // not yet processed
      }
      else {
        he->data = -1; // not yet processed
        he->opposite->data = -1; // not yet processed
      }
    }
    
    // compute size field at all the elements
    std::unordered_map<PolyMesh::Face*, double> sizeAtElementsMap;
    size_t i=0;
    for (auto f : _pm->faces){
      if (f->data == SUPER_ELEMENT || f->he == nullptr) continue;
      sizeAtElementsMap[f] = sizeAtElements[i];
      i++;
    }
    
    std::unordered_map<PolyMesh::Face*, bool> _touched;
    double hTriangle, R, q;
    SPoint3 cc;
    std::unordered_set<PolyMesh::Face*> _asFaces;
    for (size_t i = 0; i < _pm->faces.size(); i++){
      auto f = _pm->faces[i];
      if (f->data < 0 || f->he == nullptr) continue; //  
      hTriangle = sizeAtElementsMap.find(f)->second;
      faceInfo(f->he, cc, &R, &q);
      if (R/hTriangle < alpha && !_touched[f]){
        std::stack<PolyMesh::Face *> _s;
        _s.push(f);
        _touched[f] = true;
        _asFaces.insert(f);
        while(!_s.empty()){
          PolyMesh::Face* _f = _s.top();
          _s.pop();
          PolyMesh::HalfEdge *_he = _f->he;
          do {
            if (_he->opposite == nullptr || _he->opposite->f->data < -1){
              _he->data = 1;      
              _he->opposite->data = 1;      
            }     
            else if (!_touched[_he->opposite->f]){
              PolyMesh::Face *f_neigh = _he->opposite->f;
              hTriangle = sizeAtElementsMap.find(f_neigh)->second;
              faceInfo(f_neigh->he, cc, &R, &q);
              if (R/hTriangle < alpha){
                _s.push(f_neigh);
                _touched[f_neigh] = true;
                _asFaces.insert(f_neigh);
              } 
              else {
                _he->data = 1;
                _he->opposite->data = 1;
              }
            }
            _he = _he->next;
          }while (_he != _f->he);
        }
      }
    }
    for (std::size_t i=0; i<_pm->faces.size(); i++){
      auto f = _pm->faces[i];
      if (f->he == nullptr) continue; // skip faces without half edges
      int i0 = f->he->v->data;
      int i1 = f->he->next->v->data;
      int i2 = f->he->next->next->v->data;
      if(i0 < 0 || i1 < 0 || i2 < 0){
        f->data = SUPER_ELEMENT;
        continue;
      }
      auto _inAs = _asFaces.find(f);
      if (_inAs == _asFaces.end()) {
        f->data = -1;
      }
      else{
        f->data = static_cast<int>(i);
      }
    }
    updateAlphaShapeMesh();
  }
  
void AlphaShapeClass::updateAlphaShapeMesh() {
  std::unordered_set<PolyMesh::Vertex*> verticesInAlphaShape;
  for (auto f : _pm->faces) {
    if (f->data < 0 || f->he == nullptr) continue;
    verticesInAlphaShape.insert(f->he->v);
    verticesInAlphaShape.insert(f->he->next->v);
    verticesInAlphaShape.insert(f->he->next->next->v);
  }
  _asNodes.clear();
  _asTriangles.clear();
  _asEdges.clear();
  std::unordered_map<PolyMesh::Vertex*, size_t> del2asNodes;
  for (auto v : _pm->vertices){
    if (v->data < 0 || v->he == nullptr) continue; // skip super vertices
    if (verticesInAlphaShape.find(v) != verticesInAlphaShape.end()){
      _asNodes.push_back(v->data);
      del2asNodes[v] = _asNodes.size()-1;
    }
  }
  for (auto f : _pm->faces){
    if (f->data < 0 || f->data == SUPER_ELEMENT || f->he == nullptr) continue; // skip super elements
    PolyMesh::HalfEdge *he = f->he;
    std::vector<size_t> tri;
    do {
      size_t idx = del2asNodes.find(he->v)->second;
      tri.push_back(idx);
      he = he->next;
    } while (he != f->he);
    _asTriangles.push_back(tri);
  }
  for (auto he : _pm->hedges){
    if(he->data == 1 && he->f->data >= 0) {
      size_t idx0 = del2asNodes.find(he->v)->second;
      size_t idx1 = del2asNodes.find(he->opposite->v)->second;
      std::vector<size_t> edge(2);
      edge[0] = idx0;
      edge[1] = idx1;
      _asEdges.push_back(edge);
    }
  }
}

void AlphaShapeClass::filterNodes(const std::vector<double> &sizeAtNodes, const double tolerance){
  size_t nNodesPm = 0; 

  for (auto v : _pm->vertices){
    if (v->data >= 0 && v->he != nullptr) nNodesPm++;
  }
  if (sizeAtNodes.size() != nNodesPm) {
    Msg::Error("The shape of sizeAtNodes (%lu) does not match the number of nodes in the mesh (%lu).", sizeAtNodes.size(), nNodesPm);
    return;
  }
  
  // create size field on nodes
  std::unordered_map<MVertex*, double> sizeAtNodesMap;
  std::unordered_map<MVertex*, PolyMesh::Vertex*> mv2idx;
  BBox<2> bbox;
  std::vector<MVertex* > _MVertices; 
  for(size_t i=0; i<sizeAtNodes.size(); i++) {
    auto v = _verticesInDelaunay[i]; // WRONG ! DELAUNAY MESH...
    auto p = v->position;
    MVertex* mv = new MVertex(p.x(), p.y(), p.z());
    _MVertices.push_back(mv);
    sizeAtNodesMap[mv] = sizeAtNodes[i];
    bbox.extends({p.x(), p.y()});
    mv2idx[mv] = v;
  }

  OctreeNode<2, 32, MVertex*> octree;
  bbox*=1.1;
  octree.set_bbox(bbox);
  for (auto mv : _MVertices){
    BBox<2> v_bbox;
    auto p = SVector3(mv->point());
    v_bbox.extends({p.x(), p.y()});
    octree.add(mv, v_bbox);
  }
  
  std::unordered_set<MVertex*> _deleted;
  for (auto v : _MVertices){
    
    BBox<2> search_bbox;
    double h = tolerance*sizeAtNodesMap[v];

    search_bbox.extends({v->x()+h, v->y()+h});
    search_bbox.extends({v->x()-h, v->y()-h});
    std::vector<MVertex*> closeVertices;
    octree.search(search_bbox, closeVertices);
    size_t mustDelete = closeVertices.size()-1;
    for (auto v_neigh : closeVertices){
      if (v_neigh == v) continue;
      if (_deleted.find(v_neigh) != _deleted.end()){
        mustDelete--;
      }
      if (v_neigh->distance(v) < tolerance * sizeAtNodesMap[v]){
        mustDelete--;
      }
    }
    if (mustDelete > 0){
      _deleted.insert(v);
    }
  }
  Msg::Warning("Deleted %lu vertices\n", _deleted.size());
  std::vector<double> vertKeep; 
  
  for (auto v : _MVertices){
    if (_deleted.find(v) == _deleted.end()){
      auto ikeep = mv2idx.find(v)->second;
      vertKeep.push_back(ikeep->position.x());
      vertKeep.push_back(ikeep->position.y());
      vertKeep.push_back(ikeep->position.z());
    }
  }    
  _pm->reset();
  _bb->reset();
  _pm = nullptr;
  _bb = nullptr;
  triangulate(vertKeep, true);
  for (auto v : _MVertices)
      delete v;
}

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const std::pair<T1, T2>& p) const
  {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    if (hash1 != hash2) {
        return hash1 ^ hash2;              
    }
    return hash1;
  }
};

double edgeLength(std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*> a){
  auto v0 = a.first->position;
  auto v1 = a.second->position;
  return sqrt((v0.x()-v1.x())*(v0.x()-v1.x()) + (v0.y()-v1.y())*(v0.y()-v1.y()) + (v0.z()-v1.z())*(v0.z()-v1.z()));
}

bool edgeLengthCompare(std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*> a, std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*> b){
  double l0 = edgeLength(a);
  double l1 = edgeLength(b);
  return l0 > l1;
}

void AlphaShapeClass::edgeRefine(const std::vector<size_t> &nodeTags, const std::vector<double>& sizeAtNodes, const double tolerance)
{
    // create size field on nodes
    std::unordered_map<size_t, double> sizeAtNodesMap;
    for(size_t i=0; i<nodeTags.size(); i++) {
        size_t idx = nodeTags[i]+4; // +4 to skip the super vertices
        sizeAtNodesMap[idx] = sizeAtNodes[i];
    }

    // Create sorted set of all the edges
    std::unordered_set<std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*>, hash_pair> edgeNodes;
    for (auto he : _pm->hedges){
        if (he->data == 1 && he->f->data >= 0)
            edgeNodes.insert(std::make_pair(he->v, he->opposite->v));
    }
    std::multiset<std::pair<PolyMesh::Vertex*, PolyMesh::Vertex*>, decltype(&edgeLengthCompare)> edgeNodesSorted(edgeLengthCompare);
    for (auto en : edgeNodes){
        edgeNodesSorted.insert(en);
    }
    
    while (!edgeNodesSorted.empty()){
        auto it = edgeNodesSorted.begin();
        PolyMesh::Vertex* v0 = it->first;
        PolyMesh::Vertex* v1 = it->second;
        PolyMesh::HalfEdge *heToSplit = _pm->getEdge(v0, v1);
        if (heToSplit == nullptr || heToSplit->f == nullptr || heToSplit->opposite == nullptr || heToSplit->opposite->f == nullptr){
            edgeNodesSorted.erase(it);
            continue;
        }
        double l = norm(v0->position - v1->position);
        edgeNodesSorted.erase(it);
        std::vector<PolyMesh::Face*> newFaces;
        std::vector<PolyMesh::Vertex*> linkedVertices;
        double h0 = sizeAtNodesMap.find(it->first->data)->second;
        double h1 = sizeAtNodesMap.find(it->second->data)->second;
        if (l > (h0+h1)*tolerance){
            SVector3 midPoint = 0.5*(heToSplit->v->position + heToSplit->next->v->position);
            auto v0 = heToSplit->v;
            auto v1 = heToSplit->next->v;
            _pm->split_edge(heToSplit, midPoint, 0);
            _pm->vertices.back()->data = _pm->vertices.size() - 1;
            sizeAtNodesMap[_pm->vertices.back()->data] = 0.5*(h0+h1);
            edgeNodesSorted.insert(std::make_pair(v0, _pm->vertices.back()));
            edgeNodesSorted.insert(std::make_pair(_pm->vertices.back(), v1));
            auto heNew0 = _pm->getEdge(v0, _pm->vertices.back());
            auto heNew1 = _pm->getEdge(_pm->vertices.back(), v1);
            heNew0->data = 1;
            heNew1->data = 1;
            heNew0->opposite->data = 1;
            heNew1->opposite->data = 1;
            heNew0->f->data = 1;
            heNew0->opposite->f->data = -1;
            heNew1->f->data = 1;
            heNew1->opposite->f->data = -1;
        }
    }
    int i=0;
    for (auto f : _pm->faces){
        int i0 = f->he->v->data;
        int i1 = f->he->next->v->data;
        int i2 = f->he->next->next->v->data;
        if(i0 < 0 || i1 < 0 || i2 < 0) 
            f->data = SUPER_ELEMENT; // faces connected to super vertices
        else if (f->data < 0)
            f->data = -1; // reset face data
        else
            f->data = i; // reset face data
        i++;
    }
    updateAlphaShapeMesh();
}

double _faceSizeFromMap(PolyMesh::HalfEdge *he, std::unordered_map<size_t, double> & sizeAtNodes){
  return 1./3.* (sizeAtNodes[he->v->data] + sizeAtNodes[he->next->v->data] + sizeAtNodes[he->next->next->v->data]);
}

bool faceCompareFctClass(const void *a , const void *b){
  PolyMesh::Face *f0 = (PolyMesh::Face*) a;
  PolyMesh::Face *f1 = (PolyMesh::Face*) b;
  double R0, R1, cc[3];
  faceCircumCenter(f0->he, cc, &R0);
  faceCircumCenter(f1->he, cc, &R1);
  return R0 < R1;
}

template< typename T > typename std::vector<T>::iterator insert_sorted( std::vector<T> & vec, T const& item, bool (*compareFct)(const void *a , const void *b)){
    return vec.insert ( std::upper_bound( vec.begin(), vec.end(), item, compareFct), item );
}

void _WalkColorsClass(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found, int* onEdgeFlag)
{
  // heCandidate = nullptr;
  double POS[2] = {cc[0], cc[1]};
  PolyMesh::HalfEdge *he = f->he;
  bool cont = true;
  if (onEdgeFlag) *onEdgeFlag = -1;
  while(cont) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);
    if (onEdgeFlag){
      if (s0 == 0) *onEdgeFlag = 0;
      if (s1 == 0) *onEdgeFlag = 1;
      if (s2 == 0) *onEdgeFlag = 2;
    }
    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      *heCandidate = he;
      *found = true;
      cont = false;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0){
      if (he->data > 0){
        *heCandidate = he;
        *found = false;
        cont = false;
      }
      else 
        he = he->opposite;
    }
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0){
      if (he->next->data > 0){
        *heCandidate = he->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->opposite;
    }
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0){
      if (he->next->next->data > 0){
        *heCandidate = he->next->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->next->opposite;
    }
    else if(s0 <= 0 && s1 <= 0){
      // he = s0 > s1 ? he->opposite : he->next->opposite;
      if (s0 < s1){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else{
        if (he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
    }
    else if(s0 <= 0 && s2 <= 0){
      if (s0 < s2){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else {
        if (he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else if(s1 <= 0 && s2 <= 0){
      if (s1 < s2){
        if(he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
      else {
        if(he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)", cc[0], cc[1],
                 v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(),
                 s0, s1, s2);
    }
    if(he == nullptr) break;
  }
  if(he== nullptr) *found = false;
}

double interpolateSizeFieldAtPoint(PolyMesh::Face* f, SVector3 p, std::unordered_map<size_t, double> &sizeAtNodesMap)
{
    auto pa = f->he->v;
    auto pb = f->he->next->v;
    auto pc = f->he->next->next->v;
    auto a = pa->position;
    auto b = pb->position;
    auto c = pc->position;
    auto fA = sizeAtNodesMap.find(pa->data)->second;
    auto fB = sizeAtNodesMap.find(pb->data)->second;
    auto fC = sizeAtNodesMap.find(pc->data)->second;
    if (fA == 0 || fB == 0 || fC == 0) {
        Msg::Error("One of the vertices has no data, cannot interpolate size field at point (%f, %f, %f); Vertices : %d, %d, %d \n", fA, fB, fC, pa->data, pb->data, pc->data);
        return -1; // Error case
    }
    // Vectors from A
    auto v0 = SVector3(a - b);
    auto v1 = SVector3(a - c);
    auto v2 = SVector3(a - p);

    // Dot products
    double d00 = dot(v0, v0);
    double d01 = dot(v0, v1);
    double d11 = dot(v1, v1);
    double d20 = dot(v2, v0);
    double d21 = dot(v2, v1);

    // Barycentric coordinates
    double denom = d00 * d11 - d01 * d01;
    if (denom == 0) {
        return fA;
    }

    double lambda2 = (d11 * d20 - d01 * d21) / denom;
    double lambda3 = (d00 * d21 - d01 * d20) / denom;
    double lambda1 = 1.0 - lambda2 - lambda3;

    // Linear interpolation
    return lambda1 * fA + lambda2 * fB + lambda3 * fC;
}

void AlphaShapeClass::volumeRefine(const std::vector<size_t> &nodeTags, const std::vector<double>& sizeAtNodes, const double minQualityLimit, const double minSizeLimit){
    // create size field on nodes
    std::unordered_map<size_t, double> sizeAtNodesMap;
    for(size_t i=0; i<nodeTags.size(); i++) {
        size_t idx = nodeTags[i]+4; // +4 to skip the super vertices
        sizeAtNodesMap[idx] = sizeAtNodes[i];
    }

    // Refine
    std::vector<PolyMesh::Face *> _badFaces;
    double _limit = minQualityLimit;
    double _sizeMinFactor = minSizeLimit;
    for(auto f : _pm->faces) {
        if (f->he && f->data >= 0){
            double q, R, s;
            SPoint3 cc;
            faceInfo(f->he, cc, &R, &q);
            s = _faceSizeFromMap(f->he, sizeAtNodesMap);
            if((q < _limit && R/s > _sizeMinFactor) || R > s) 
                insert_sorted(_badFaces, f, faceCompareFctClass);
        }
    }

    size_t n_faces_init = _badFaces.size();
    while (!_badFaces.empty()){
        if (_badFaces.size() > 1000*n_faces_init){
            printf("too many faces in refine, most likely a bug in geometry \n");
            _pm->print4debug(0); 
            exit(-1);
        }
        PolyMesh::Face *f = _badFaces.back();
        _badFaces.erase(_badFaces.end()-1);
        if (f->he == nullptr || f->data < 0) {
            continue;
        }
        double q, R, s;
        SPoint3 cc;
        faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
        s = _faceSizeFromMap(f->he, sizeAtNodesMap);
        if((q < _limit && R/s > _sizeMinFactor) || R > s) {
            PolyMesh::HalfEdge* heCandidate = nullptr;
            auto f_found = WalkGeneral(f, cc.x(), cc.y(), &heCandidate);
            std::vector<PolyMesh::HalfEdge *> _touched;
            double newSize = 0;
            if (f_found && f_found->data > 0){ // this means we can add a point
                newSize = interpolateSizeFieldAtPoint(f_found, SVector3(cc), sizeAtNodesMap);
                _pm->split_triangle(-1, cc[0], cc[1], cc[2], f_found, delaunayCriterionColors, nullptr, &_touched);
            }
            else { // this means we're outside of the alpha shape
                continue;
            }
            PolyMesh::Vertex* v = _pm->vertices.back();
            v->data = _pm->vertices.size() - 1;
            sizeAtNodesMap[v->data] = newSize;
            std::vector<PolyMesh::Face *> _newFaces;
            for(auto _h : _touched){
                if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
                    _newFaces.push_back(_h->f);
            }
            for(auto pf : _newFaces) {
                double q, R, s;
                SPoint3 cc;
                faceInfo(pf->he, cc, &R, &q);
                s = _faceSizeFromMap(pf->he, sizeAtNodesMap);
                auto it = std::find(_badFaces.begin(), _badFaces.end(), pf); 
                if(it != _badFaces.end()) { 
                    _badFaces.erase(it);
                }
                if((q < _limit && R/s > _sizeMinFactor) || R > s) {
                    insert_sorted(_badFaces, pf, faceCompareFctClass);
                }
            }
        }
    }
    // Reset vertex data
    for (size_t i=4; i<_pm->vertices.size(); i++){
        _pm->vertices[i]->data = i;
    }
    updateAlphaShapeMesh();
}

void AlphaShapeClass::getVerticesWithinRadius(PolyMesh::Vertex* v, double R, std::vector<PolyMesh::Vertex*> * closeVertices){
  // Neighbor to neighbor walk to check if nodes are within a distance R of v.
  std::vector<PolyMesh::Vertex*> _temp;
  std::vector<PolyMesh::Vertex*> _currNeighbors;
  std::vector<PolyMesh::Vertex*> close;
  SVector3 vPos = v->position;
  _pm->vertexNeighbors(v, &_currNeighbors);
  for (auto vv : _currNeighbors) _temp.push_back(vv);
  while (!_temp.empty()){
    PolyMesh::Vertex* vtest = *_temp.begin();
    _temp.erase(_temp.begin());
    SVector3 vect = vtest->position - vPos;
    double dist = vect.norm();
    if (dist < R){
      close.push_back(vtest);
      _pm->vertexNeighbors(vtest, &_currNeighbors);
      for (auto vv : _currNeighbors){
        if(vv != v &&
            std::find(close.begin(), close.end(), vv) == close.end() &&
            std::find(_temp.begin(), _temp.end(), vv) == _temp.end() )
            _temp.push_back(vv);
      }
    }
  }
  *closeVertices = close;
}

bool AlphaShapeClass::boundaryCheck(PolyMesh::Vertex* v){
  PolyMesh::HalfEdge *he = v->he;
  size_t debug = 0;
  if(he->data > 0) return true;
  do {
    he = he->opposite;
    if(he == nullptr) return true;
    he = he->next;
    if(he->data > 0) return true;
    if (debug++ > 1e4){
      printf("stuck in boundary check \n");
      _pm->print4debug(0);
      exit(-1);
    }
  } while(he != v->he);
  return false;
}

inline int _deleteVertex(PolyMesh* pm, PolyMesh::Vertex *v, std::vector<PolyMesh::HalfEdge *> *_t = NULL)
  {
    std::vector<PolyMesh::HalfEdge *> _touched;
    if(pm->degree(v) == 3) {
      PolyMesh::HalfEdge *he = v->he;
      PolyMesh::HalfEdge *he0 = he->next;
      PolyMesh::HalfEdge *he1 = he0->next->opposite->next;
      PolyMesh::HalfEdge *he2 = he1->next->opposite->next;
      PolyMesh::Vertex *v0 = he0->v;
      PolyMesh::Vertex *v1 = he1->v;
      PolyMesh::Vertex *v2 = he2->v;
      do {
        he->f = nullptr;
        he->opposite->f = nullptr;
        he = he->next->next->opposite;
      } while(he != v->he);
      he0->next = he1;
      he1->next = he2;
      he2->next = he0;
      he1->f->he = nullptr; // to turn these faces off
      he2->f->he = nullptr; // to turn these faces off
      v->he = nullptr;
      he1->f = he0->f;
      he2->f = he0->f;
      pm->createFace(he0->f, v0, v1, v2, he0, he1, he2);
      if(_t) {
        // for(auto he : *_t) (*_t).push_back(he);
        (*_t).push_back(he0);
        (*_t).push_back(he1);
        (*_t).push_back(he2);
      }

    }
    else {
      PolyMesh::HalfEdge *he = v->he;
      bool deletion_accepted = false;
      bool corner = false;
      while(!deletion_accepted && !corner) {
        if(he->data != -1) return -1;
        PolyMesh::HalfEdge *_he = he->next->next->opposite;
        PolyMesh::Vertex *v0 = he->next->v;
        bool flipped = false;
        if(!_he) corner = true;
        while(!flipped && _he != he && !corner) {
          PolyMesh::Vertex *v1 = _he->next->v;
          PolyMesh::Vertex *v2 = _he->next->next->v;
          double s = robustPredicates::orient2d(v0->position, v1->position,
                                                v2->position);
          if(s < 0) flipped = true;
          _he = _he->next->next->opposite;
          if(_he == nullptr) corner = true;
        }
        if(flipped) { he = he->next->next->opposite; }
        else if(!flipped && !corner) {
          // we found a good edge! we can adapt the big mesh
          _he = he->next->next->opposite;
          while(pm->degree(v) > 3) {
            if (_t) (*_t).push_back(_he);
            PolyMesh::HalfEdge *_heNext = _he->next->next->opposite;
            pm->swap_edge(_he);
            _he = _heNext;
          }
          // if(_t) *_t = _touched;
          // if(_t) (*_t).insert((*_t).end(), _touched.begin(), _touched.end());
          deletion_accepted = true;
        }
      }
      _deleteVertex(pm, v, _t);
    }
    return 0;
  }

void AlphaShapeClass::delaunayCheckColors(std::vector<PolyMesh::HalfEdge* > hes, std::vector<PolyMesh::HalfEdge* > *_t){
  std::stack<PolyMesh::HalfEdge *> _stack;
  for (auto he : hes) _stack.push(he);
  std::vector<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    // if (debug++ > 1e4){
    //   printf("stuck in delaunay check colors \n");
    //   print4debug(pm, 0);
    //   exit(-1);
    // }
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.push_back(he);
    _stack.pop();
    if (!he->opposite || !he->f) continue;
    if(delaunayCriterionColors(he, nullptr) == 1) {
      _pm->swap_edge(he);
      PolyMesh::HalfEdge *H[2] = {he, he->opposite};
      for(int k = 0; k < 2; k++) {
        if(H[k] == NULL) continue;
        PolyMesh::HalfEdge *heb = H[k]->next;
        PolyMesh::HalfEdge *hebo = heb->opposite;
        if(std::find(_touched.begin(), _touched.end(), heb) ==
              _touched.end() &&
            std::find(_touched.begin(), _touched.end(), hebo) ==
              _touched.end()) {
          _stack.push(heb);
        }

        PolyMesh::HalfEdge *hec = heb->next;
        PolyMesh::HalfEdge *heco = hec->opposite;
        if(std::find(_touched.begin(), _touched.end(), hec) ==
              _touched.end() &&
            std::find(_touched.begin(), _touched.end(), heco) ==
              _touched.end()) {
          _stack.push(hec);
        }
      }
    }
  }
  *_t = _touched;
}

void AlphaShapeClass::applyChew(const std::vector<double>& sizeAtNodes, const double minQualityLimit, const double minSizeLimit){
  // create size field on nodes
  std::unordered_map<size_t, double> sizeAtNodesMap;
  for(size_t i=0; i<sizeAtNodes.size(); i++) {
    size_t n = _asNodes[i];
    sizeAtNodesMap[n] = sizeAtNodes[i];
  }
  // Refine
  std::vector<PolyMesh::Face *> _badFaces;
  double _limit = minQualityLimit;
  double _sizeMinFactor = minSizeLimit;
  for(auto f : _pm->faces) {
    if (f->he && f->data >= 0){
      double q, R, s;
      SPoint3 cc;
      faceInfo(f->he, cc, &R, &q);
      s = _faceSizeFromMap(f->he, sizeAtNodesMap);
      if((q < _limit && R/s > _sizeMinFactor) || R > s) 
        insert_sorted(_badFaces, f, faceCompareFctClass);
    }
  }

  size_t n_faces_init = _badFaces.size();
  // size_t idebug = 0;
  while (!_badFaces.empty()){
    if (_badFaces.size() > 1000*n_faces_init){
      printf("too many faces in refine, most likely a bug in geometry \n");
      _pm->print4debug(0); 
      exit(-1);
    }
    PolyMesh::Face *f = _badFaces.back();
    _badFaces.erase(_badFaces.end()-1);
    if (f->he == nullptr || f->data < 0) {
      continue;
    }
    double q, R, s;
    SPoint3 cc;
    faceInfo(f->he, cc, &R, &q); // NB : q = 2*rho / R
    s = _faceSizeFromMap(f->he, sizeAtNodesMap);
    if((q < _limit && R/s > _sizeMinFactor) || R > s){
      PolyMesh::HalfEdge* heCandidate = nullptr;
      bool found;
      int onEdgeFlag=0;
      double newSize = 0;
      WalkAlphaShape(f, cc, &heCandidate, &found, &onEdgeFlag);
      if (onEdgeFlag != -1){ // A sanity check... if we are splitting a triangle with a 90° angle, and the opposite edge happens to be a boundary edge, we must split the edge, not the triangle
        PolyMesh::HalfEdge *flaggedHe = nullptr; 
        if (onEdgeFlag == 0) flaggedHe = heCandidate;
        else if (onEdgeFlag == 1) flaggedHe = heCandidate->next;
        else if (onEdgeFlag == 2) flaggedHe = heCandidate->next->next;
        if (flaggedHe->data > 0) {
          found = false;
          heCandidate = flaggedHe;
        }
      }
      std::vector<PolyMesh::HalfEdge *> _touched;
      if (heCandidate && found){ // this means it is NOT a constrained edge
        newSize = interpolateSizeFieldAtPoint(heCandidate->f, SVector3(cc), sizeAtNodesMap);
        _pm->split_triangle(-1, cc[0], cc[1], cc[2], heCandidate->f, delaunayCriterionColors, nullptr, &_touched);
      }
      else { // this means it is a constrained edge
        SVector3 p = 0.5*(heCandidate->v->position + heCandidate->next->v->position);
        cc.setPosition(p.x(), p.y(), p.z());
        if ( heCandidate->opposite){
          auto v0 = heCandidate->v;
          auto v1 = heCandidate->next->v;
          newSize = 0.5 * sizeAtNodesMap[heCandidate->v->data] + 0.5 * sizeAtNodesMap[heCandidate->next->v->data];
          _pm->split_edge(heCandidate, cc, 0);
          _pm->vertices.back()->data = _pm->vertices.size() - 1;
          auto heNew0 = _pm->getEdge(v0, _pm->vertices.back());
          auto heNew1 = _pm->getEdge(_pm->vertices.back(), v1);
          heNew0->data = 1;
          heNew1->data = 1;
          heNew0->opposite->data = 1;
          heNew1->opposite->data = 1;
          heNew0->f->data = 1;
          heNew0->opposite->f->data = -1;
          heNew1->f->data = 1;
          heNew1->opposite->f->data = -1;
          // heCandidate->next->opposite->f->data = heCandidate->f->data;
          // heCandidate->opposite->f->data = heCandidate->next->opposite->next->opposite->f->data;
          // heCandidate->data = heData; // constrain them again
          // heCandidate->opposite->data = heData; // constrain them again
          // heCandidate->next->opposite->next->data = heData; // constrain them again
          // heCandidate->next->opposite->next->opposite->data = heData; // constrain them again
          std::vector<PolyMesh::HalfEdge *> new_hes;
          new_hes.push_back(heCandidate);
          new_hes.push_back(heCandidate->next);
          new_hes.push_back(heCandidate->next->next);
          new_hes.push_back(heCandidate->next->opposite);
          new_hes.push_back(heCandidate->next->opposite->next);
          new_hes.push_back(heCandidate->next->opposite->next->next);
          delaunayCheckColors(new_hes, &_touched);

          // pm->split_edge(heCandidate, cc, -1);
          // int heData = heCandidate->data;
          // int heData = bndTag;
          // heCandidate->next->opposite->f->data = heCandidate->f->data;
          // heCandidate->opposite->f->data = heCandidate->next->opposite->next->opposite->f->data;
          // heCandidate->data = heData; // constrain them again
          // heCandidate->opposite->data = heData; // constrain them again
          // heCandidate->next->opposite->next->data = heData; // constrain them again
          // heCandidate->next->opposite->next->opposite->data = heData; // constrain them again
          // std::vector<PolyMesh::HalfEdge *> new_hes;
          // new_hes.push_back(heCandidate);
          // new_hes.push_back(heCandidate->next);
          // new_hes.push_back(heCandidate->next->next);
          // new_hes.push_back(heCandidate->next->opposite);
          // new_hes.push_back(heCandidate->next->opposite->next);
          // new_hes.push_back(heCandidate->next->opposite->next->next);
          // _delaunayCheckColors(pm, new_hes, &_touched);

        }
        SVector3 dist = cc-heCandidate->v->position;
        std::vector<PolyMesh::Vertex *> closeVertices;
        getVerticesWithinRadius(_pm->vertices.back(), dist.norm(), &closeVertices);
        if (closeVertices.size() > 0){
          _touched.clear();
          for (auto vv : closeVertices){
            std::vector<PolyMesh::HalfEdge *> _tlocal;
            std::vector<PolyMesh::HalfEdge *> _nhes;
            if (vv->he->f->data > 0 && _pm->degree(vv) > 0 && !boundaryCheck(vv)) {
              _deleteVertex(_pm, vv, &_nhes);
            }
            delaunayCheckColors(_nhes, &_tlocal);
            _touched.insert(_touched.end(), _tlocal.begin(), _tlocal.end());
          }
          for(auto face_it = _badFaces.begin() ; face_it != _badFaces.end(); face_it++)
          if (!(*face_it)->he) _badFaces.erase(face_it--);
        }
      }
      PolyMesh::Vertex* v = _pm->vertices.back();
      v->data = _pm->vertices.size() - 1;
      sizeAtNodesMap[v->data] = newSize;
      std::vector<PolyMesh::Face *> _newFaces;
      for(auto _h : _touched){
        if(_h->f && _h->f->he != nullptr && std::find(_newFaces.begin(), _newFaces.end(), _h->f) == _newFaces.end())
        _newFaces.push_back(_h->f);
      }
      for(auto pf : _newFaces) {
        if (pf->he == nullptr || pf->data < 0) {
          continue;
        }
        double q, R, s;
        SPoint3 cc;
        faceInfo(pf->he, cc, &R, &q);
        s = _faceSizeFromMap(pf->he, sizeAtNodesMap);
        auto it = std::find(_badFaces.begin(), _badFaces.end(), pf); 
        if(it != _badFaces.end()) { 
          _badFaces.erase(it);
        }
        if((q < _limit && R/s > _sizeMinFactor) || R > s){
          insert_sorted(_badFaces, pf, faceCompareFctClass);
        }
      }
    }
  }
  for (size_t i=0; i<_pm->faces.size(); i++){
    auto f = _pm->faces[i];
    if (f->he == nullptr) continue; // skip faces without half-edges
    int i0 = f->he->v->data;
    int i1 = f->he->next->v->data;
    int i2 = f->he->next->next->v->data;
    if(i0 < 0 || i1 < 0 || i2 < 0) 
      f->data = SUPER_ELEMENT; // faces connected to super vertices
    else if (f->data < 0)
      f->data = -1; // reset face data
    else
      f->data = i; // reset face data
  }
  // Reset vertex data
  for (size_t i=4; i<_pm->vertices.size(); i++){
    _pm->vertices[i]->data = i;
  }
  updateAlphaShapeMesh();
}

void AlphaShapeClass::moveNodes(const std::vector<double> & displacement, const bool recoverDelaunay){
  if (displacement.size()/3 != _asNodes.size()){
    Msg::Error("Displacement vector size (%lu) does not match the number of vertices (%lu)", displacement.size()/3, _asNodes.size());
  }
  for (size_t i=0; i<_asNodes.size(); i++){
    auto n = _asNodes[i];
    PolyMesh::Vertex *v = _pm->vertices[n];
    if (v->data < 0) {
      Msg::Error("Node numbering issue in node displacement (tag < 0)", i);
      return;
    }
    const double *disp = &displacement[3*i];
    auto p = v->position;
    p += SVector3(disp[0], disp[1], disp[2]);
    v->position = p;
  }
  if (recoverDelaunay){
    checkDelaunay();
    for (size_t i=0; i<_pm->faces.size(); i++){
      if (_pm->faces[i]->he == nullptr) continue; // skip faces without half-edges
      auto f = _pm->faces[i];
      int i0 = f->he->v->data;
      int i1 = f->he->next->v->data;
      int i2 = f->he->next->next->v->data;
      if(i0 < 0 || i1 < 0 || i2 < 0) {
        f->data = SUPER_ELEMENT; // faces connected to super vertices
        continue;
      }
      f->data = i; // reset face data
    }
  }
}

void AlphaShapeClass::correctDisplacement(const std::vector<double> & dx, const double tolerance, std::vector<double>& correctedDx){
  if (_GModelOctree == nullptr) {
    Msg::Error("Boundary model not set, cannot correct displacement");
    return;
  }
  if (dx.size()/3 != _asNodes.size()){
    Msg::Error("Displacement vector size (%lu) does not match the number of vertices (%lu)", dx.size()/3, _asNodes.size());
  }
  correctedDx.clear();
  correctedDx.resize(dx.size());
  
  for (size_t i=0; i<_asNodes.size(); i++){
    auto n = _asNodes[i];
    // MVertex* v = gf->getMeshVertex(i);
    auto v = _pm->vertices[n]; 
    bool intersect = false;
    auto x0 = v->position;
    SVector3 disp(dx[3*i], dx[3*i+1], dx[3*i+2]);
    SVector3 x1 = x0 + disp;
    correctedDx[3*i] = disp[0];
    correctedDx[3*i+1] = disp[1];
    correctedDx[3*i+2] = disp[2];
    // We check if it is a boundary node -> if yes, it is forced to stay on the boundary
    SVector3 x1_projected;
    if (_bndNodes.find(v->data) != _bndNodes.end()) {
      BBox<2> bbox;
      bbox.extends({x0[0], x0[1]});
      bbox.extends({x1[0], x1[1]});
      bbox.extends({bbox.min[0]-tolerance, bbox.min[1]-tolerance});
      bbox.extends({bbox.max[0]+tolerance, bbox.max[1]+tolerance});
      std::vector<_alphaShapeBndEdge *> edges;
      double t=0.;
      if (!intersect){
        _GModelOctree->search(bbox, edges);
        double minDist = 1e10;
        double norm;
        for (auto edge : edges) {
          double x2[2] = {edge->x0, edge->y0};
          double x3[2] = {edge->x1, edge->y1};
          double x2x1[2] = {x1[0]-x2[0], x1[1]-x2[1]};
          double x2x3[2] = {x3[0]-x2[0], x3[1]-x2[1]};
          double dot = x2x1[0]*x2x3[0] + x2x1[1]*x2x3[1];
          norm = x2x3[0]*x2x3[0] + x2x3[1]*x2x3[1];
          t = dot/norm;
          double nx[2];
          double dist;
          if(t > 0 && t < 1){
            nx[0] = x2[0]+t*x2x3[0];
            nx[1] = x2[1]+t*x2x3[1];
          }
          else if (t <= 0){
            nx[0] = x2[0];
            nx[1] = x2[1];
          }
          else {
            nx[0] = x3[0];
            nx[1] = x3[1];
          }
          dist = (nx[0]-x1[0])*(nx[0]-x1[0]) + (nx[1]-x1[1])*(nx[1]-x1[1]);
          if (dist < minDist){
            x1_projected[0] = nx[0];
            x1_projected[1] = nx[1];
            x1_projected[2] = 0.;
            intersect = true;
            minDist = dist;
          }
        }
      }
      if (!intersect){
        Msg::Warning("No intersection found for boundary node %zu (%.15f, %.15f) -> (%.15f, %.15f) (norm = %.15e) (size of edges : %lu) (t = %.15f) \n", v->data, x0[0], x0[1], x1[0], x1[1], sqrt((x1[0]-x0[0])*(x1[0]-x0[0]) + (x1[1]-x0[1])*(x1[1]-x0[1])), edges.size(), t);
      }
    }
    else {
      std::vector<_alphaShapeBndEdge *> edges;
      BBox<2> bbox;
      bbox.extends({x0[0], x0[1]});
      bbox.extends({x1[0], x1[1]});
      _GModelOctree->search(bbox, edges);
      for (auto edge : edges) {
        double a1[2] = {edge->x0, edge->y0};
        double a2[2] = {edge->x1, edge->y1};
        double a143 = robustPredicates::orient2d(a1,x1,x0);
        double a243 = robustPredicates::orient2d(a2,x1,x0);    
        double a123 = robustPredicates::orient2d(a1,a2,x0);
        double a124 = robustPredicates::orient2d(a1,a2,x1);
        if (a143*a243 < 0 && a123*a124 < 0){
          double t = fabs(a143)/(fabs(a143)+fabs(a243));
          double vec[2] = {a2[0]-a1[0], a2[1]-a1[1]};
          double new_intersection[2] = {a1[0]+t*vec[0], a1[1]+t*vec[1]};
          x1_projected[0] = new_intersection[0];
          x1_projected[1] = new_intersection[1];
          x1_projected[2] = 0.;
          intersect = true;
          break;
        }
      }
    }
    if (intersect) {
      correctedDx[3*i+0] = x1_projected[0] - x0[0];
      correctedDx[3*i+1] = x1_projected[1] - x0[1];
      correctedDx[3*i+2] = x1_projected[2] - x0[2];
    }
  }
}

void AlphaShapeClass::initialize_rectangle(PolyMesh* _pm, double xmin, double xmax, double ymin, double ymax)
{
    _pm->reset();
    PolyMesh::Vertex *v_mm = new PolyMesh::Vertex(xmin, ymin, 0);
    _pm->vertices.push_back(v_mm);
    PolyMesh::Vertex *v_mM = new PolyMesh::Vertex(xmin, ymax, 0);
    _pm->vertices.push_back(v_mM);
    PolyMesh::Vertex *v_MM = new PolyMesh::Vertex(xmax, ymax, 0);
    _pm->vertices.push_back(v_MM);
    PolyMesh::Vertex *v_Mm = new PolyMesh::Vertex(xmax, ymin, 0);
    _pm->vertices.push_back(v_Mm);
    PolyMesh::HalfEdge *mm_MM = new PolyMesh::HalfEdge(v_mm);
    PolyMesh::HalfEdge *MM_mM = new PolyMesh::HalfEdge(v_MM);
    PolyMesh::HalfEdge *mM_mm = new PolyMesh::HalfEdge(v_mM);
    _pm->hedges.push_back(mm_MM);
    _pm->hedges.push_back(MM_mM);
    _pm->hedges.push_back(mM_mm);
    PolyMesh::Face *f0 = new PolyMesh::Face(mm_MM);
    _pm->faces.push_back(f0);
    _pm->createFace(f0, v_mm, v_MM, v_mM, mm_MM, MM_mM, mM_mm);

    PolyMesh::HalfEdge *MM_mm = new PolyMesh::HalfEdge(v_MM);
    PolyMesh::HalfEdge *mm_Mm = new PolyMesh::HalfEdge(v_mm);
    PolyMesh::HalfEdge *Mm_MM = new PolyMesh::HalfEdge(v_Mm);
    _pm->hedges.push_back(MM_mm);
    _pm->hedges.push_back(mm_Mm);
    _pm->hedges.push_back(Mm_MM);
    PolyMesh::Face *f1 = new PolyMesh::Face(MM_mm);
    _pm->faces.push_back(f1);
    _pm->createFace(f1, v_mm, v_Mm, v_MM, mm_Mm, Mm_MM, MM_mm);

    MM_mm->opposite = mm_MM;
    mm_MM->opposite = MM_mm;
}

void AlphaShapeClass::setBoundaryModel(const std::string & boundaryModelName){
  GModel *bModel = GModel::findByName(boundaryModelName);
  if (bModel == nullptr) {
    Msg::Error("Boundary model '%s' not found", boundaryModelName.c_str());
    return;
  }
  if (_GModelOctree) {
    _GModelOctree->reset();
    _GModelOctree = nullptr;
  }
  _bndEdges.clear();
  _GModelOctree = new OctreeNode<2, 32, _alphaShapeBndEdge*>;
  BBox<2> bbox;
  std::vector<GEntity*> bndEntities;
  bModel->getEntities(bndEntities, 1);
  for (auto e : bndEntities){
    size_t n_elem = e->getNumMeshElements();
    for (size_t i_el = 0; i_el<n_elem; i_el++){
      MElement *elem = e->getMeshElement(i_el);
      if(elem->getDim() != 1) continue;
      _alphaShapeBndEdge bd = {elem->getVertex(0)->x(), elem->getVertex(0)->y(), elem->getVertex(1)->x(), elem->getVertex(1)->y(), e->tag()};
      _bndEdges.push_back(bd);
      bbox.extends({bd.x0, bd.y0});
      bbox.extends({bd.x1, bd.y1});
    }
  }
  bbox*=1.1;
  _GModelOctree->set_bbox(bbox);
  for (auto &ed : _bndEdges){
    BBox<2> ed_bbox;
    ed_bbox.extends({ed.x0, ed.y0});
    ed_bbox.extends({ed.x1, ed.y1});
    _GModelOctree->add(&ed, ed_bbox);
  }
}

void AlphaShapeClass::createAlphaShapeOctree(){
  if (_alphaShapeOctree) {
    _alphaShapeOctree->reset();
    _alphaShapeOctree = nullptr;
  }
  _meshTriangles.clear();
  _alphaShapeOctree = new OctreeNode<2, 32, _meshTriangle*>;
  BBox<2> bbox;
  for (size_t i=0; i<_asTriangles.size(); i++){
    auto tri = _asTriangles[i];
    double tri_x[6];
    for (size_t j=0; j<tri.size(); j++){
      PolyMesh::Vertex *v = _pm->vertices[_asNodes[tri[j]]];
      tri_x[2*j] = v->position.x();
      tri_x[2*j+1] = v->position.y();
      bbox.extends({v->position.x(), v->position.y()});
    }
    _meshTriangle as_tri = {tri_x[0], tri_x[1], tri_x[2], tri_x[3], tri_x[4], tri_x[5], i};
    _meshTriangles.push_back(as_tri);
  }
  _alphaShapeOctree->set_bbox(bbox);
  for (auto &tri : _meshTriangles){
    BBox<2> tri_bbox;
    tri_bbox.extends({tri.x0, tri.y0});
    tri_bbox.extends({tri.x1, tri.y1});
    tri_bbox.extends({tri.x2, tri.y2});
    _alphaShapeOctree->add(&tri, tri_bbox);
  }
}

void AlphaShapeClass::xyz2uvw(_meshTriangle *tri, double xyz[3], double uvw[3])
{
  const double O[3] = {tri->x0, tri->y0, 0.0};

  const double d[3] = {xyz[0] - O[0], xyz[1] - O[1], xyz[2] - O[2]};
  const double d1[3] = {tri->x1 - O[0], tri->y1 - O[1], 0.0 - O[2]};
  const double d2[3] = {tri->x2 - O[0], tri->y2 - O[1], 0.0 - O[2]};

  const double Jxy = d1[0] * d2[1] - d1[1] * d2[0];
  const double Jxz = d1[0] * d2[2] - d1[2] * d2[0];
  const double Jyz = d1[1] * d2[2] - d1[2] * d2[1];

  if((std::abs(Jxy) > std::abs(Jxz)) && (std::abs(Jxy) > std::abs(Jyz))) {
    uvw[0] = (d[0] * d2[1] - d[1] * d2[0]) / Jxy;
    uvw[1] = (d[1] * d1[0] - d[0] * d1[1]) / Jxy;
  }
  else if(std::abs(Jxz) > std::abs(Jyz)) {
    uvw[0] = (d[0] * d2[2] - d[2] * d2[0]) / Jxz;
    uvw[1] = (d[2] * d1[0] - d[0] * d1[2]) / Jxz;
  }
  else {
    uvw[0] = (d[1] * d2[2] - d[2] * d2[1]) / Jyz;
    uvw[1] = (d[2] * d1[1] - d[1] * d1[2]) / Jyz;
  }
  uvw[2] = 0.0;
}

bool AlphaShapeClass::isInside(_meshTriangle *tri, double uvw[3])
{
  // Check if the point is inside the triangle using barycentric coordinates
  double u = uvw[0];
  double v = uvw[1];
  double w = 1.0 - u - v;
  // Check if the barycentric coordinates are valid
  return (u >= 0.0 && v >= 0.0 && w >= 0.0);
}

static std::pair<double, double> projectPointOnSegment(SPoint2 p, SPoint2 a, SPoint2 b){
  SPoint2 ab = b-a;
  SPoint2 ap = p-a;
  SVector3 ab_vec(ab.x(), ab.y(), 0);
  SVector3 ap_vec(ap.x(), ap.y(), 0);
  double t = dot(ap_vec, ab_vec)/dot(ab_vec, ab_vec);
  if (t < 0) t = 0;
  if (t > 1) t = 1;
  SPoint2 proj(a.x() + t*ab.x(), a.y() + t*ab.y());
  double dist = hypot(p.x()-proj.x(), p.y()-proj.y());
  return std::make_pair(dist, t);
}

void AlphaShapeClass::getTrianglesAndParametricCoords(const std::vector<double> & points, std::vector<size_t> & triangles, std::vector<double> & parametricCoords){
  triangles.clear();
  parametricCoords.clear();
  if (_alphaShapeOctree == nullptr) {
    Msg::Error("Mesh octree not created, cannot get triangles and parametric coords");
    return;
  }
  std::vector<_meshTriangle*> candidates;
  double hmean = 0;
  size_t nh = 0;
  for (auto he : _pm->hedges){
    if (he->f == nullptr) continue;
    if (he->f->data < 0) continue;
    double d = norm(he->v->position - he->next->v->position);
    hmean += d;
    nh ++;
  }
  hmean /= nh;
  for (size_t i=0; i<points.size()/3; i++){
    BBox<2> search_bbox;
    search_bbox.extends({points[3*i], points[3*i+1]});
    candidates.clear();
    _alphaShapeOctree->search(search_bbox, candidates);
    bool found = false;
    for (auto elem : candidates){
      double uvw[3];
      double xyz[3] = {points[3*i], points[3*i+1], points[3*i+2]};
      xyz2uvw(elem, xyz, uvw);
      if (isInside(elem, uvw)){
        found = true;
        triangles.push_back(elem->idx);
        parametricCoords.push_back(uvw[0]);
        parametricCoords.push_back(uvw[1]);
        parametricCoords.push_back(uvw[2]);
        break;
      }
    }
    double tol = hmean;
    while (!found) {
      candidates.clear();
      search_bbox.extends({points[3*i]+tol, points[3*i+1]+tol});
      search_bbox.extends({points[3*i]-tol, points[3*i+1]-tol});
      _alphaShapeOctree->search(search_bbox, candidates);
      double dmin = std::numeric_limits<double>::max();
      size_t eidx = 0;
      double xi, eta;
      for (auto elem : candidates) {
        for (int i = 0; i < 3; ++i) {
          SPoint2 a(elem->x0, elem->y0);
          SPoint2 b(elem->x1, elem->y1);
          SPoint2 p(points[3*i], points[3*i+1]);
          double d, t;
          std::tie(d, t) = projectPointOnSegment(p, a, b);
          if (d < dmin) {
            dmin = d;
            found = true;
            eidx = elem->idx;
            if (i == 0) {
              xi = t;
              eta = 0;
            }
            else if (i == 1) {
              xi = 1-t;
              eta = t;
            }
            else {
              xi = 0;
              eta = 1-t;
            }
          }
        }
      }
      if (found) {
        triangles.push_back(eidx);
        parametricCoords.push_back(xi);
        parametricCoords.push_back(eta);
        parametricCoords.push_back(0);
      }
      tol *= 2;
    }
  }
}

double _distPointSegment(SVector3 p, SVector3 a, SVector3 b) {
  SVector3 ab = b-a;
  double t = dot(p-a, ab)/dot(ab, ab);
  if (t < 0) return norm(p-a);
  if (t > 1) return norm(p-b);
  return norm(p-(a+t*ab));
}

void AlphaShapeClass::matchAlphaShapeWithModel(const std::string & boundaryModelName, const double tolerance, std::vector<int> & coloredEdges)
{
  auto bModel = GModel::findByName(boundaryModelName);
  if (bModel == nullptr) {
    Msg::Error("Boundary model '%s' not found", boundaryModelName.c_str());
    return;
  }
  // color the boundary edges with the solid geometry
  _bndNodes.clear();
  std::vector<_alphaShapeBndEdge*> result;
  std::set<int> resultTags0;
  std::set<int> resultTags1;
  std::set<int> intersection;
  std::unordered_map<PolyMesh::HalfEdge*, int> bndMap;
  for (auto he : _pm->hedges){
    if (he->data < 0 || he->f == nullptr || he->f->data < 0) continue;
    if (he->f->data > 0 && he->opposite->f->data > 0){
      continue;
    }
    if (he->v->data == -1 || he->next->v->data == -1){
      printf("oh oh... data of v = -1 \n");
      _pm->print4debug(10);
      exit(-1);
    }
    resultTags0.clear();
    resultTags1.clear();
    intersection.clear();
    BBox<2> search_bbox;
    search_bbox.extends({he->v->position.x()+tolerance, he->v->position.y()+tolerance});
    search_bbox.extends({he->v->position.x()-tolerance, he->v->position.y()-tolerance});
    result.clear();
    _GModelOctree->search(search_bbox, result);
    if (result.size() == 0){  // free surface!!!
      bndMap[he] = -1;
      continue;
    }
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (_distPointSegment(he->v->position, a, b) < tolerance){
        resultTags0.insert(ed->tag);
      }
    }
    BBox<2> search_bbox1;
    search_bbox1.extends({he->next->v->position.x()+tolerance, he->next->v->position.y()+tolerance});
    search_bbox1.extends({he->next->v->position.x()-tolerance, he->next->v->position.y()-tolerance});
    result.clear();
    _GModelOctree->search(search_bbox1, result);
    if (result.size() == 0){ // free surface!!!
      bndMap[he] = -1;
      continue; 
    }
    for (auto &ed : result){
      SVector3 a(ed->x0, ed->y0, 0);
      SVector3 b(ed->x1, ed->y1, 0);
      if (_distPointSegment(he->next->v->position, a, b) < tolerance){
        resultTags1.insert(ed->tag);
      }
    }
    std::set<int> physTags0;
    std::set<int> physTags1;
    std::set<int> physTagsIntersection;
    std::unordered_map<int, int> physTag2EntityTag;
    for (auto t : resultTags0){
      for (auto pt : bModel->getEntityByTag(1, t)->getPhysicalEntities()){
        physTags0.insert(pt);
        physTag2EntityTag[pt] = t; 
      }
    }
    for (auto t : resultTags1){
      for (auto pt : bModel->getEntityByTag(1, t)->getPhysicalEntities()){
        physTags1.insert(pt);
        physTag2EntityTag[pt] = t;
      }
    }
    std::set_intersection(physTags0.begin(), physTags0.end(), physTags1.begin(), physTags1.end(), std::inserter(physTagsIntersection, physTagsIntersection.begin()));
    if (physTagsIntersection.size() == 1){
      bndMap[he] = physTag2EntityTag[*physTagsIntersection.begin()];
      _bndNodes.insert(he->v->data);
      _bndNodes.insert(he->next->v->data);
    }
    else {
      bndMap[he] = -1;
    }
  }
  coloredEdges.clear();
  for (auto he : _pm->hedges){
    if (he->data < 0 || he->f == nullptr || he->f->data < 0) continue;
    if (he->data == 1){
      auto it = bndMap.find(he);
      if (it == bndMap.end()){
        Msg::Error("Half-edge not found in boundary map");
        return;
      }
      coloredEdges.push_back(it->second);
      // if (it->second > 0){
      //   _bndNodes.insert(he->v->data);
      //   _bndNodes.insert(he->next->v->data);
      // }
    }
  }
}

void AlphaShapeClass::getAlphaShapeMesh(std::vector<double> & coords, std::vector<size_t> & triangles, std::vector<size_t> & edges){
  coords.clear();
  triangles.clear();
  edges.clear();
  for (auto v : _asNodes){
    PolyMesh::Vertex *vertex = _pm->vertices[v];
    coords.push_back(vertex->position.x());
    coords.push_back(vertex->position.y());
    coords.push_back(vertex->position.z());
  }
  for (auto &tri : _asTriangles){
    triangles.push_back(tri[0]);
    triangles.push_back(tri[1]);
    triangles.push_back(tri[2]);
  }
  for (auto &edge : _asEdges){
    edges.push_back(edge[0]);
    edges.push_back(edge[1]);
  }
}

void AlphaShapeClass::getDelaunayMesh(std::vector<double> & coords, std::vector<size_t> & triangles){
  coords.clear();
  triangles.clear();
  _verticesInDelaunay.clear();
  if (_pm == nullptr) {
    Msg::Error("PolyMesh not initialized, cannot get Delaunay mesh");
    return;
  }
  std::unordered_map<PolyMesh::Vertex*, size_t> vertexMap;
  size_t idx = 0;
  for (auto v : _pm->vertices){
    if (v->data < 0 || v->he == nullptr) continue; // skip vertices without half-edges or with negative data
    coords.push_back(v->position.x());
    coords.push_back(v->position.y());
    coords.push_back(v->position.z());
    vertexMap[v] = idx++;
    _verticesInDelaunay.push_back(v);
  }
  for (auto f : _pm->faces){
    if (f->he == nullptr || f->data == SUPER_ELEMENT) continue;
    triangles.push_back(vertexMap[f->he->v]);
    triangles.push_back(vertexMap[f->he->next->v]);
    triangles.push_back(vertexMap[f->he->next->next->v]);
  }
}

PolyMesh::Face *AlphaShapeClass::WalkGeneral(PolyMesh::Face *f, double x, double y, PolyMesh::HalfEdge** heBnd)
{
  double POS[2] = {x, y};
  PolyMesh::HalfEdge *he = f->he;

  while(1) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);

    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      if (heBnd != nullptr && s0 < 1e-11) *heBnd = he;
      if (heBnd != nullptr && s1 < 1e-11) *heBnd = he->next;
      if (heBnd != nullptr && s2 < 1e-11) *heBnd = he->next->next;
      return he->f;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0)
      he = he->opposite;
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0)
      he = he->next->opposite;
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0)
      he = he->next->next->opposite;
    else if(s0 <= 0 && s1 <= 0)
      he = s0 > s1 ? he->opposite : he->next->opposite;
    else if(s0 <= 0 && s2 <= 0)
      he = s0 > s2 ? he->opposite : he->next->next->opposite;
    else if(s1 <= 0 && s2 <= 0)
      he = s1 > s2 ? he->next->opposite : he->next->next->opposite;
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)",
                 x, y, v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(), s0, s1,
                 s2);
    }
    if(he == nullptr) break;
  }
  return nullptr;
}

void AlphaShapeClass::WalkAlphaShape(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found, int* onEdgeFlag)
{
  // heCandidate = nullptr;
  double POS[2] = {cc[0], cc[1]};
  PolyMesh::HalfEdge *he = f->he;
  bool cont = true;
  if (onEdgeFlag) *onEdgeFlag = -1;
  while(cont) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = robustPredicates::orient2d(v2->position, v0->position, POS);
    if (onEdgeFlag){
      if (s0 == 0) *onEdgeFlag = 0;
      if (s1 == 0) *onEdgeFlag = 1;
      if (s2 == 0) *onEdgeFlag = 2;
    }
    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      *heCandidate = he;
      *found = true;
      cont = false;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0){
      if (he->data > 0){
        *heCandidate = he;
        *found = false;
        cont = false;
      }
      else 
        he = he->opposite;
    }
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0){
      if (he->next->data > 0){
        *heCandidate = he->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->opposite;
    }
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0){
      if (he->next->next->data > 0){
        *heCandidate = he->next->next;
        *found = false;
        cont = false;
      }
      else 
        he = he->next->next->opposite;
    }
    else if(s0 <= 0 && s1 <= 0){
      // he = s0 > s1 ? he->opposite : he->next->opposite;
      if (s0 < s1){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else{
        if (he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
    }
    else if(s0 <= 0 && s2 <= 0){
      if (s0 < s2){
        if (he->data > 0){
          *heCandidate = he;
          *found = false;
          cont = false;
        }
        else {
          he = he->opposite;
        }
      }
      else {
        if (he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else if(s1 <= 0 && s2 <= 0){
      if (s1 < s2){
        if(he->next->data > 0){
          *heCandidate = he->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->opposite;
        }
      }
      else {
        if(he->next->next->data > 0){
          *heCandidate = he->next->next;
          *found = false;
          cont = false;
        }
        else {
          he = he->next->next->opposite;
        }
      }
    }
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)", cc[0], cc[1],
                 v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(),
                 s0, s1, s2);
    }
    if(he == nullptr) break;
  }
  if(he== nullptr) *found = false;
}

int AlphaShapeClass::delaunayCriterion(PolyMesh::HalfEdge *he, void* val)
{
  if(he->opposite == nullptr) return -1;
  if (val != nullptr){
    int bndTag = *(int*)val;
    if(he->data == bndTag) return 0;
    if(he->opposite->data == bndTag) return 0;
  }
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;
  // FIXME : should be oriented anyway !
  double result = robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);
  return (result > 0) ? 1 : 0;
}

int AlphaShapeClass::delaunayCriterionColors(PolyMesh::HalfEdge *he, void* val)
{
  if(he->opposite == nullptr) return -1;
  if(he->data > 0) return 0;
  if(he->opposite->data > 0) return 0;
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;
  double result = robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);
  return (result >= 0) ? 1 : 0;
}

AlphaShapeClass* AlphaShapeClass::get(int tag)
{
  auto it = asMap.find(tag);
  if(it != asMap.end()) {
    return it->second;
  }
  else {
    Msg::Error("AlphaShapeClass with tag %d not found", tag);
    return nullptr;
  }
}

void AlphaShapeClass::set(int tag, AlphaShapeClass* as)
{
  if(asMap.find(tag) != asMap.end()) {
    Msg::Error("AlphaShapeClass with tag %d already exists", tag);
    return;
  }
  asMap[tag] = as;
}

void AlphaShapeClass::faceInfo(PolyMesh::HalfEdge *he, double *x_center, double *R, double *quality){
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  double q0[3] = {v0->position.x(), v0->position.y(), v0->position.z()};
  double q1[3] = {v1->position.x(), v1->position.y(), v1->position.z()};
  double q2[3] = {v2->position.x(), v2->position.y(), v2->position.z()};
  circumCenterXYZ(q0, q1, q2, x_center);
  double v[3] = {q0[0] - x_center[0], q0[1] - x_center[1], q0[2] - x_center[2]};
  *R = norm3(v);
  *quality = qmTriangle::gamma(q0[0], q0[1], q0[2], q1[0], q1[1], q1[2],
                               q2[0], q2[1], q2[2]);
}

void AlphaShapeClass::checkDelaunay(std::vector<PolyMesh::HalfEdge* > *_t){
  std::stack<PolyMesh::HalfEdge *> _stack;
  for (auto he : _pm->hedges) _stack.push(he);
  std::unordered_set<PolyMesh::HalfEdge *> _touched;
  while(!_stack.empty()) {
    PolyMesh::HalfEdge *he = _stack.top();
    _touched.insert(he);
    _stack.pop();
    if (!he->opposite || !he->f) continue;
    if(delaunayCriterion(he, nullptr) == 1) {
      _pm->swap_edge(he);
      PolyMesh::HalfEdge *H[2] = {he, he->opposite};
      for(int k = 0; k < 2; k++) {
        if(H[k] == NULL) continue;
        PolyMesh::HalfEdge *heb = H[k]->next;
        PolyMesh::HalfEdge *hebo = heb->opposite;
        if(_touched.find(heb) == _touched.end() &&
           _touched.find(hebo) == _touched.end()) {
          _stack.push(heb);
        }
        PolyMesh::HalfEdge *hec = heb->next;
        PolyMesh::HalfEdge *heco = hec->opposite;
        if(_touched.find(hec) == _touched.end() &&
           _touched.find(heco) == _touched.end()) {
          _stack.push(hec);
        }
      }
    }
  }
  if (_t != nullptr) {
    _t->clear();
    *_t = std::vector<PolyMesh::HalfEdge*>(_touched.begin(), _touched.end());
  }
}



#endif
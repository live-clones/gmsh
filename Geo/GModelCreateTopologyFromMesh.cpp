// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stack>
#include <set>
#include <map>
#include <sstream>
#include "OS.h"
#include "GModel.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "MPoint.h"
#include "MVertex.h"
#include "MLine.h"
#include "MEdge.h"
#include "MFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "Context.h"

// Assumption: The input mesh is potentially (partially) coloured

bool topoExists(GModel *gm)
{
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    GEdge *ge = *it;
    if(!ge->getBeginVertex() || !ge->getEndVertex()) return false;
  }
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    GFace *gf = *it;
    if(gf->edges().empty()) return false;
  }
  for(auto it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    GRegion *gr = *it;
    if(gr->faces().empty()) return false;
  }
  return true;
}

// FIXME: Two times the same MLine in each connected part if periodic
std::vector<GEdge *> ensureSimplyConnectedEdge(GEdge *ge)
{
  std::vector<GEdge *> _all;
  std::set<MLine *> _lines;
  std::map<MVertex *, std::pair<MLine *, MLine *> > _conn;

  _all.push_back(ge);

  // create vertex to edge connectivity: only two neighbors are considered...
  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    _lines.insert(ge->lines[i]);
    for(int j = 0; j < 2; j++) {
      auto it = _conn.find(ge->lines[i]->getVertex(j));
      if(it == _conn.end())
        _conn[ge->lines[i]->getVertex(j)] =
          std::make_pair(ge->lines[i], (MLine *)nullptr);
      else
        it->second.second = ge->lines[i];
    }
  }

  std::vector<std::vector<MLine *> > _parts;
  while(!_lines.empty()) {
    std::stack<MLine *> _stack;
    _stack.push(*_lines.begin());
    std::vector<MLine *> _part;
    while(!_stack.empty()) {
      MLine *l = _stack.top();
      _stack.pop();
      _lines.erase(l);
      // avoid adding twice the last one
      if(!_part.size() || _part[_part.size() - 1] != l) { _part.push_back(l); }
      for(int j = 0; j < 2; j++) {
        auto it = _conn.find(l->getVertex(j));
        if(it->second.first == l && it->second.second != nullptr &&
           _lines.find(it->second.second) != _lines.end()) {
          _stack.push(it->second.second);
        }
        else if(it->second.second == l &&
                _lines.find(it->second.first) != _lines.end()) {
          _stack.push(it->second.first);
        }
      }
    }
    _parts.push_back(_part);
  }

  if(_parts.empty()) {
    Msg::Warning("No connected part found in Curve %d", ge->tag());
  }
  else if(_parts.size() > 1) {
    Msg::Info("Curve %d is not simply connected: splitting it in %d parts",
              ge->tag(), _parts.size());
  }

  for(size_t i = 0; i < _parts.size(); i++) {
    if(i == 0)
      ge->lines = _parts[i];
    else {
      discreteEdge *newE = new discreteEdge(
        ge->model(), ge->model()->getMaxElementaryNumber(1) + 1, nullptr,
        nullptr);
      ge->model()->add(newE);
      newE->lines = _parts[i];
      _all.push_back(newE);
    }
  }
  return _all;
}

void assignFace(GFace *gf, std::set<MElement *> &_f)
{
  gf->triangles.clear();
  gf->quadrangles.clear();
  for(auto it = _f.begin(); it != _f.end(); ++it) {
    if((*it)->getNumVertices() == 3)
      gf->triangles.push_back((MTriangle *)*it);
    else if((*it)->getNumVertices() == 4)
      gf->quadrangles.push_back((MQuadrangle *)*it);
  }
}

void ensureManifoldFace(GFace *gf)
{
  std::map<MEdge, std::pair<MElement *, MElement *>, MEdgeLessThan> _pairs;
  std::set<MEdge, MEdgeLessThan> _nonManifold;

  std::set<MElement *> _allFaces;

  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    _allFaces.insert(e);
    for(int j = 0; j < e->getNumEdges(); j++) {
      MEdge ed = e->getEdge(j);
      if(_nonManifold.find(ed) == _nonManifold.end()) {
        auto it = _pairs.find(ed);
        if(it == _pairs.end()) {
          _pairs[ed] = std::make_pair(e, (MElement *)nullptr);
        }
        else {
          if(it->second.second == nullptr) { it->second.second = e; }
          else {
            _nonManifold.insert(ed);
            _pairs.erase(it);
          }
        }
      }
    }
  }
  if(_nonManifold.empty()) return;

  std::vector<std::set<MElement *> > _sub;
  while(!_allFaces.empty()) {
    std::stack<MElement *> _stack;
    _stack.push(*_allFaces.begin());
    std::set<MElement *> _f;
    while(!_stack.empty()) {
      MElement *e = _stack.top();
      _allFaces.erase(e);
      _stack.pop();
      _f.insert(e);
      for(int j = 0; j < e->getNumEdges(); j++) {
        MEdge ed = e->getEdge(j);
        if(_nonManifold.find(ed) == _nonManifold.end()) {
          auto it = _pairs.find(ed);
          if(it->second.second != nullptr) {
            MElement *other =
              it->second.second == e ? it->second.first : it->second.second;
            if(_f.find(other) == _f.end()) _stack.push(other);
          }
        }
      }
    }
    _sub.push_back(_f);
  }

  Msg::Info("Surface %d is non-manifold: splitting it in %d parts", gf->tag(),
            _sub.size());

  for(std::size_t i = 0; i < _sub.size(); i++) {
    if(i == 0)
      assignFace(gf, _sub[i]);
    else {
      discreteFace *newF = new discreteFace(
        gf->model(), gf->model()->getMaxElementaryNumber(2) + 1);
      gf->model()->add(newF);
      assignFace(newF, _sub[i]);
    }
  }
}

void ensureManifoldFaces(GModel *gm)
{
  std::vector<GFace *> f;
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) f.push_back(*it);
  for(std::size_t i = 0; i < f.size(); i++) ensureManifoldFace(f[i]);
}

typedef std::map<MVertex *, std::set<GEdge *> > MVertexToGEdgesMap;
typedef std::map<MVertex *, GVertex *> MVertexToGVertexMap;
typedef std::map<GEdge *, std::set<GVertex *> > GEdgeToGVerticesMap;
typedef std::map<std::set<GEdge *>, GVertex *> GEdgesToGVertexMap;

void createTopologyFromMesh1D(GModel *gm, int &num)
{
  // list all existing GVertex

  MVertexToGVertexMap mVertexToGVertex;

  for(auto it = gm->firstVertex(); it != gm->lastVertex(); it++) {
    GVertex *gv = *it;
    if(gv->mesh_vertices.size()) {
      MVertex *mv = gv->mesh_vertices[0];
      mVertexToGVertex[mv] = gv;
      Msg::Debug("The model already has point %i, containing node %i",
                 gv->tag(), mv->getNum());
    }
  }

  // create bundles of edges for each MVertex on the GEdge; if GVertex already
  // present, link it to the GEdge

  MVertexToGEdgesMap mVertexToGEdges;
  GEdgeToGVerticesMap gEdgeToGVertices;

  for(auto it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    GEdge *ge = *it;
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      MLine *e = (*it)->lines[i];
      for(int j = 0; j < 2; j++) {
        MVertex *mv = e->getVertex(j);
        auto gIter = mVertexToGVertex.find(mv);
        if(gIter != mVertexToGVertex.end())
          gEdgeToGVertices[ge].insert(gIter->second);
        else {
          auto it = mVertexToGEdges.find(mv);
          if(it != mVertexToGEdges.end() &&
             it->second.find(ge) != it->second.end()) {
            // in bulk
            mVertexToGEdges.erase(it);
          }
          else {
            mVertexToGEdges[mv].insert(ge);
          }
        }
      }
    }
  }

  // now create any missing GVertex

  for(auto mvIter = mVertexToGEdges.begin(); mvIter != mVertexToGEdges.end();
      ++mvIter) {
    MVertex *mv = mvIter->first;
    std::set<GEdge *> &gEdges = mvIter->second;
    num++;
    discreteVertex *dv = new discreteVertex(
      gm, gm->getMaxElementaryNumber(0) + 1, mv->x(), mv->y(), mv->z());
    gm->add(dv);
    mVertexToGVertex[mv] = dv;
    MPoint *mp = new MPoint(mv);
    dv->points.push_back(mp);
    for(auto gEIter = gEdges.begin(); gEIter != gEdges.end(); ++gEIter) {
      GEdge *ge = *gEIter;
      gEdgeToGVertices[ge].insert(dv);
    }
  }

  // link all GEdge to GVertex and vice versa (we expect to see two GVertex per
  // GEdge unless it is periodic!)

  for(auto gEIter = gEdgeToGVertices.begin(); gEIter != gEdgeToGVertices.end();
      ++gEIter) {
    GEdge *ge = gEIter->first;
    std::set<GVertex *> gVerts = gEIter->second;

    if(gVerts.size() == 2) {
      GVertex *gv1 = *(gVerts.begin());
      GVertex *gv2 = *(gVerts.rbegin());

      ge->setBeginVertex(gv1);
      ge->setEndVertex(gv2);

      gv1->addEdge(ge);
      gv2->addEdge(ge);
    }
    else {
      std::vector<GEdge *> splits = ensureSimplyConnectedEdge(ge);
      if(splits.size() == 1) { // periodic case
        GVertex *gv1 = *(gVerts.begin());
        ge->setBeginVertex(gv1);
        ge->setEndVertex(gv1);
        gv1->addEdge(ge);
      }
      else {
        std::ostringstream gVertexList;
        for(auto gvIter = gVerts.begin(); gvIter != gVerts.end(); ++gvIter) {
          gVertexList << " " << (*gvIter)->tag();
        }
        Msg::Error(
          "Found single/multiply ended GEdge %i in model (GVertices:%s)",
          ge->tag(), gVertexList.str().c_str());
      }
    }
  }

  // add GVertex for self-intersecting GEdge; we still need to check this is
  // actually the case...

  for(auto it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    if(!(*it)->getBeginVertex() || !(*it)->getEndVertex()) {
      num++;
      MVertex *v = (*it)->lines[0]->getVertex(0);
      discreteVertex *dv = new discreteVertex(
        gm, gm->getMaxElementaryNumber(0) + 1, v->x(), v->y(), v->z());
      gm->add(dv);
      MPoint *mp = new MPoint(v);
      dv->points.push_back(mp);
      dv->addEdge(*it);
      (*it)->setBeginVertex(dv);
      (*it)->setEndVertex(dv);
      gEdgeToGVertices[*it].insert(dv);
    }
  }
}

class topoEdge {
protected:
  MElement *parent;
  int edgeIndex;
  std::pair<int, int> ids;

public:
  const MElement *getParent() const { return parent; }
  const int getIndex() const { return edgeIndex; }
  const int getType() const { return TYPE_LIN; }

  inline bool operator==(const topoEdge &f) const { return ids == f.ids; }
  inline bool operator<(const topoEdge &f) const { return ids < f.ids; }

  topoEdge(MElement *elt, int num)
  {
    parent = elt;
    edgeIndex = num;
    MEdge edge = elt->getEdge(num);

    int id0 = edge.getVertex(0)->getNum();
    int id1 = edge.getVertex(1)->getNum();

    if(id0 > id1) std::swap(id0, id1);

    ids.first = id0;
    ids.second = id1;
  }
};

typedef std::map<topoEdge, std::set<GFace *> > TEdgeToGFacesMap;
typedef std::map<topoEdge, GEdge *> TEdgeToGEdgeMap;
typedef std::map<GFace *, std::set<GEdge *> > GFaceToGEdgesMap;
typedef std::map<std::set<GFace *>, GEdge *> GFacesToGEdgeMap;

void createTopologyFromMesh2D(GModel *gm, int &num)
{
  // create an inverse dictionnary for existing edges

  TEdgeToGEdgeMap tEdgeToGEdge;

  for(auto it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    GEdge *ge = *it;
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      topoEdge te(ge->lines[i], 0);
      tEdgeToGEdge[te] = ge;
    }
  }

  // create a list of face intersections and elements on that intersection

  TEdgeToGFacesMap tEdgeToGFaces;
  GFaceToGEdgesMap gFaceToGEdges;

  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    GFace *gf = *it;
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      MElement *e = (*it)->getMeshElement(i);
      if(e->getDim() == 2) {
        for(int j = 0; j < e->getNumEdges(); j++) {
          topoEdge te(e, j);
          auto eIter = tEdgeToGEdge.find(te);
          if(eIter != tEdgeToGEdge.end())
            gFaceToGEdges[gf].insert(eIter->second);
          else {
            auto it = tEdgeToGFaces.find(te);
            if(it != tEdgeToGFaces.end() &&
               it->second.find(gf) != it->second.end()) {
              // in bulk
              tEdgeToGFaces.erase(it);
            }
            else {
              tEdgeToGFaces[te].insert(gf);
            }
          }
        }
      }
    }
  }

  // create a GEdge for each face boundary, ie. for which edges have been
  // visited once

  GFacesToGEdgeMap gFacesToGEdge;

  for(auto it = tEdgeToGFaces.begin(); it != tEdgeToGFaces.end(); ++it) {
    std::set<GFace *> &gfaces = it->second;
    auto gfIter = gFacesToGEdge.find(gfaces);
    if(gfIter == gFacesToGEdge.end()) {
      discreteEdge *de = new discreteEdge(gm, gm->getMaxElementaryNumber(1) + 1,
                                          nullptr, nullptr);
      num++;
      gm->add(de);
      auto gfIter = gfaces.begin();
      for(; gfIter != gfaces.end(); ++gfIter) gFaceToGEdges[*gfIter].insert(de);
      gFacesToGEdge[gfaces] = de;
    }
  }

  // create elements on new geometric edges

  MElementFactory eltFactory;

  for(auto it = tEdgeToGFaces.begin(); it != tEdgeToGFaces.end(); ++it) {
    const topoEdge &te = it->first;
    std::set<GFace *> &gfaces = it->second;

    auto gfIter = gFacesToGEdge.find(gfaces);

    if(gfIter != gFacesToGEdge.end()) {
      GEdge *ge = gfIter->second;

      const MElement *parent = te.getParent();
      int edgeIndex = te.getIndex();

      std::vector<MVertex *> vtcs;
      parent->getEdgeVertices(edgeIndex, vtcs);

      int type = te.getType();
      int order = parent->getPolynomialOrder();
      bool serendipity = parent->getIsOnlySerendipity();

      int tag = ElementType::getType(type, order, serendipity);

      MLine *edge = dynamic_cast<MLine *>(eltFactory.create(tag, vtcs));

      ge->lines.push_back(edge);
    }
  }

  std::map<GEdge *, std::vector<GEdge *> > splitEdge;
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); it++) {
    std::vector<GEdge *> split = ensureSimplyConnectedEdge(*it);
    if(split.size() != 1) splitEdge[*it] = split;
  }

  // add split edges to face map

  for(auto gfToge = gFaceToGEdges.begin(); gfToge != gFaceToGEdges.end();
      ++gfToge) {
    std::set<GEdge *> &edgeSet = gfToge->second;
    std::set<GEdge *> newEdgeSet;
    auto eIter = edgeSet.begin();
    for(; eIter != edgeSet.end(); ++eIter) {
      auto pIter = splitEdge.find(*eIter);
      if(pIter != splitEdge.end()) {
        std::vector<GEdge *> &edges = pIter->second;
        newEdgeSet.insert(edges.begin(), edges.end());
      }
    }
    edgeSet.insert(newEdgeSet.begin(), newEdgeSet.end());
  }

  // connect GEdges and GFaces

  for(auto gfToge = gFaceToGEdges.begin(); gfToge != gFaceToGEdges.end();
      ++gfToge) {
    GFace *gf = gfToge->first;
    std::set<GEdge *> &gEdgeSet = gfToge->second;

    std::vector<GEdge *> gEdges;
    gEdges.insert(gEdges.begin(), gEdgeSet.begin(), gEdgeSet.end());

    gf->set(gEdges);
    auto eIter = gEdgeSet.begin();
    for(; eIter != gEdgeSet.end(); eIter++) (*eIter)->addFace(gf);
  }
}

class topoFace {
protected:
  MElement *parent;
  int faceIndex;
  std::set<int> vtcs;

public:
  const std::set<int> &getVertices() const { return vtcs; }

  const MElement *getParent() const { return parent; }
  const int getIndex() const { return faceIndex; }
  const int getType() const
  {
    switch(vtcs.size()) {
    case 3: return TYPE_TRI; break;
    case 4: return TYPE_QUA; break;
    default: return vtcs.size() > 4 ? TYPE_POLYG : -1; break;
    }
  }

  inline bool operator==(const topoFace &f) const { return vtcs == f.vtcs; }
  inline bool operator<(const topoFace &f) const { return vtcs < f.vtcs; }

  topoFace(MElement *elt, int num)
  {
    parent = elt;
    faceIndex = num;

    std::vector<MVertex *> tmp;
    MFace face = elt->getFace(num);

    for(std::size_t i = 0; i < face.getNumVertices(); i++) {
      vtcs.insert(face.getVertex(i)->getNum());
    }
  }
};

typedef std::map<topoFace, GFace *> TFaceToGFaceMap;
typedef std::map<topoFace, std::pair<GRegion *, GRegion *> >
  TFaceToGRegionPairMap;
typedef std::map<GRegion *, std::set<GFace *> > GRegionToGFacesMap;
typedef std::set<std::pair<GRegion *, GRegion *> > GRegionPairSet;
typedef std::map<std::pair<GRegion *, GRegion *>, GFace *>
  GRegionPairToGFaceMap;

void createTopologyFromMesh3D(GModel *gm, int &num)
{
  // create an inverse dictionary for existing faces

  TFaceToGFaceMap tFaceToGFace;
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    for(unsigned i = 0; i < (*it)->triangles.size(); i++) {
      topoFace tf((*it)->triangles[i], 0);
      tFaceToGFace.insert(std::make_pair(tf, *it));
    }
    for(unsigned i = 0; i < (*it)->quadrangles.size(); i++) {
      topoFace tf((*it)->quadrangles[i], 0);
      tFaceToGFace.insert(std::make_pair(tf, *it));
    }
  }

  // create inverse dictionary for all other faces; this is the most time
  // consuming part!

  TFaceToGRegionPairMap tFaceToGRegionPair;
  GRegionToGFacesMap gRegionToGFaces;

  for(auto it = gm->firstRegion(); it != gm->lastRegion(); it++) {
    GRegion *gr = *it;
    for(unsigned i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      for(int j = 0; j < e->getNumFaces(); j++) {
        topoFace f(e, j);
        auto ffIter = tFaceToGFace.find(f);
        if(ffIter != tFaceToGFace.end())
          gRegionToGFaces[gr].insert(ffIter->second);
        else {
          auto frIter = tFaceToGRegionPair.find(f);
          if(frIter == tFaceToGRegionPair.end()) {
            tFaceToGRegionPair[f] = std::make_pair((GRegion *)nullptr, *it);
          }
          else
            frIter->second.first = gr;
        }
      }
    }
  }

  // create new GFace for each pair of connected GRegion

  GRegionPairToGFaceMap gRegionPairToGFace;

  auto it = tFaceToGRegionPair.begin();
  for(; it != tFaceToGRegionPair.end(); ++it) {
    GRegion *r1 = it->second.first;
    GRegion *r2 = it->second.second;
    if(r1 != r2) {
      std::pair<GRegion *, GRegion *> gRegionPair;
      if(r1 && r2)
        gRegionPair =
          std::pair<GRegion *, GRegion *>(std::min(r1, r2), std::max(r1, r2));
      else // r1 null
        gRegionPair = std::pair<GRegion *, GRegion *>(r1, r2);
      auto iter = gRegionPairToGFace.find(gRegionPair);
      if(iter == gRegionPairToGFace.end()) {
        discreteFace *df =
          new discreteFace(gm, gm->getMaxElementaryNumber(2) + 1);
        num++;
        gm->add(df);
        if(r1) gRegionToGFaces[r1].insert(df);
        if(r2) gRegionToGFaces[r2].insert(df);
        gRegionPairToGFace[gRegionPair] = df;
      }
    }
  }

  // create elements on new geometric faces

  MElementFactory eltFactory;
  for(it = tFaceToGRegionPair.begin(); it != tFaceToGRegionPair.end(); ++it) {
    const topoFace &tf = it->first;
    std::pair<GRegion *, GRegion *> grPair = it->second;

    auto grTogfIter = gRegionPairToGFace.find(grPair);

    if(grTogfIter != gRegionPairToGFace.end()) {
      GFace *gf = grTogfIter->second;

      const MElement *parent = tf.getParent();
      int faceIndex = tf.getIndex();

      std::vector<MVertex *> vtcs;
      parent->getFaceVertices(faceIndex, vtcs);

      int type = tf.getType();
      int order = parent->getPolynomialOrder();
      bool serendipity = parent->getIsOnlySerendipity();
      int tag = ElementType::getType(type, order, serendipity);

      MElement *face = eltFactory.create(tag, vtcs);

      if(parent->getType() != TYPE_PYR) {
        if(type == TYPE_TRI) gf->triangles.push_back((MTriangle *)face);
        if(type == TYPE_QUA) gf->quadrangles.push_back((MQuadrangle *)face);
      }
    }
  }

  // now connect GFaces to GRegions and vice versa

  auto itTo = gRegionToGFaces.begin();
  for(; itTo != gRegionToGFaces.end(); ++itTo) {
    GRegion *gr = itTo->first;
    std::vector<GFace *> faces;
    faces.insert(faces.begin(), itTo->second.begin(), itTo->second.end());
    gr->set(faces);
    for(auto it3 = faces.begin(); it3 != faces.end(); ++it3)
      (*it3)->addRegion(itTo->first);
  }
}

void GModel::createTopologyFromMesh()
{
  if(topoExists(this)) {
    Msg::Info("Topology exists: no need to create one from mesh");
    return;
  }

  const int dim = getDim();
  double t1 = Cpu(), w1 = TimeOfDay();

  Msg::Info("Creating topology from mesh...");
  int numF = 0, numE = 0, numV = 0;
  if(dim >= 3)
    createTopologyFromMesh3D(this, numF);
  else
    ensureManifoldFaces(this);
  if(dim >= 2) createTopologyFromMesh2D(this, numE);
  if(dim >= 1) createTopologyFromMesh1D(this, numV);

  pruneMeshVertexAssociations();

  CTX::instance()->mesh.changed = ENT_ALL;

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done creating topology from mesh (Wall %gs, CPU %gs)", w2 - w1,
            t2 - t1);
}

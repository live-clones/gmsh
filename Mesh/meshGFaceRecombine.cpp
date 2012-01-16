// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#include "meshGFaceRecombine.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGFaceOptimize.h"

#include "drawContext.h"
#include "FlGui.h"
#include "Context.h"
#include "OS.h"

#define REC2D_EDGE_BASE 1
#define REC2D_EDGE_QUAD 1
#define REC2D_WAIT_TIME 1

// #define REC2D_SMOOTH
 #define REC2D_DRAW

Recombine2D *Recombine2D::_current = NULL;
bool Recombine2D::bo = 0;
double **Rec2DVertex::_qualVSnum = NULL;
double **Rec2DVertex::_gains = NULL;

void Recombine2D::associateParity(int pOld, int pNew)
{
  std::set<Rec2DVertex*>::iterator it = _current->_parities[pOld].begin();
  for (; it != _current->_parities[pOld].end(); ++it)
    (*it)->setParity(pNew);
  _current->_parities.erase(pOld);
  if (pOld % 2)
    pOld -= 1;
  else
    pOld +=1;
  if (pNew % 2)
    pNew -= 1;
  else
    pNew +=1;
  it = _current->_parities[pOld].begin();
  for (; it != _current->_parities[pOld].end(); ++it)
    (*it)->setParity(pNew);
  _current->_parities.erase(pOld);
}

/**  Recombine2D  **/
/*******************/
Recombine2D::Recombine2D(GFace *gf) : _gf(gf)
{
  if (Recombine2D::_current != NULL) {
    Msg::Info("An instance of recombination is already in execution");
    return;
  }
  Recombine2D::_current = this;
  _numChange = 0;
  backgroundMesh::set(gf);
  _bgm = backgroundMesh::current();
  Rec2DVertex::initStaticTable();
  _numEdge = _numVert = 0;
  _valEdge = _valVert = .0;
  
    _tri = _gf->triangles;
  
  // Be able to compute geometrical angle at corners
  std::map<MVertex*, std::set<GEdge*> > mapCornerVert;
  {
    std::list<GEdge*> listge = gf->edges();
    std::list<GEdge*>::iterator itge = listge.begin();
    for (; itge != listge.end(); ++itge) {
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)]
        .insert(*itge);
      mapCornerVert[(*itge)->getEndVertex()->getMeshElement(0)->getVertex(0)]
        .insert(*itge);
    }
  }
  
  // Find all Vertices and edges
  std::map<MVertex*, std::list<MTriangle*> > mapVert;
  std::map<MEdge, std::list<MTriangle*>, Less_Edge> mapEdge;
  for (unsigned int i = 0; i < gf->triangles.size(); ++i) {
    MTriangle *t = gf->triangles[i];
    for (int j = 0; j < 3; ++j) {
      mapVert[t->getVertex(j)].push_back(t);
      mapEdge[t->getEdge(j)].push_back(t);
    }
  }
  
  // Create the 'Rec2DVertex' and store iterator to vertices which have degree 4
  std::list<std::map<MVertex*, std::list<MTriangle*> >::iterator> fourTri;
  {
    mapofVertices::iterator itV2N = _vertices.begin();
    std::map<MVertex*, std::list<MTriangle*> >::iterator itvert = mapVert.begin();
    for (; itvert != mapVert.end(); ++itvert) {
      MVertex *v = itvert->first;
      int onWhat = 1;
      if (mapCornerVert.find(v) != mapCornerVert.end())
        onWhat = -1;
      Rec2DVertex *rv = new Rec2DVertex(v, itvert->second, onWhat, mapCornerVert);
      itV2N = _vertices.insert(itV2N, std::make_pair(v,rv));
      ++_numVert;
      if (itvert->second.size() == 4)
        fourTri.push_back(itvert);
    }
  }
  
  // Create the 'Rec2DEdge' and store boundary edges
  std::map<MVertex*, std::list<MEdge> > boundV2E;
  {
    mapofEdges::iterator itE2E = _edges.begin();
    std::map<MEdge, std::list<MTriangle*> >::iterator itedge = mapEdge.begin();
    for (; itedge != mapEdge.end(); ++itedge) {
      MEdge e = itedge->first;
      Rec2DEdge *re = new Rec2DEdge(e, _vertices, itedge->second);
      itE2E = _edges.insert(itE2E, std::make_pair(e,re));
      _vertices[e.getVertex(0)]->add(re);
      _vertices[e.getVertex(1)]->add(re);
      _numEdge += REC2D_EDGE_BASE;
      _valEdge += REC2D_EDGE_BASE * re->getQual();
      if (itedge->second.size() == 1) {
        _numEdge += REC2D_EDGE_QUAD;
        _valEdge += REC2D_EDGE_QUAD * re->getQual();
        _vertices[e.getVertex(0)]->setOnBoundary();
        _vertices[e.getVertex(1)]->setOnBoundary();
        boundV2E[e.getVertex(0)].push_back(e);
        boundV2E[e.getVertex(1)].push_back(e);
      }
    }
  }
  
  // We know now on what are vertices, compute reward
  {
    mapofVertices::iterator itV2N = _vertices.begin();
    for (; itV2N != _vertices.end(); ++itV2N)
      _valVert += itV2N->second->getQual();
  }
  
  // Be dealing with "parity" on boundaries
  {
    std::map<MVertex*, std::list<MEdge> >::iterator itBound = boundV2E.begin();
    int actualParity = 0;
    bool p = 0;
    while (itBound != boundV2E.end()) {
      MVertex *firstV = itBound->first, *actualV = firstV;
      MEdge actualEdge = *itBound->second.begin();
      Rec2DVertex *rv = _vertices[firstV];
      rv->setParity(actualParity+p);
      _parities[actualParity+p].insert(rv);
      p = !p;
      if (actualEdge.getVertex(0) == actualV)
        actualV = actualEdge.getVertex(1);
      else
        actualV = actualEdge.getVertex(0);
      while (actualV != firstV) {
        rv = _vertices[actualV];
        rv->setParity(actualParity+p);
        _parities[actualParity+p].insert(rv);
        p = !p;
        itBound = boundV2E.find(actualV);
        std::list<MEdge>::iterator it = itBound->second.begin();
        if (*it == actualEdge)
          actualEdge = *(++it);
        else
          actualEdge = *it;
        if (actualEdge.getVertex(0) == actualV)
          actualV = actualEdge.getVertex(1);
        else
          actualV = actualEdge.getVertex(0);
        boundV2E.erase(itBound);
      }
      if (_vertices[actualV]->getParity() != actualParity+p)
        Msg::Error("[Recombine2D] Not even number of mesh edges on boundary !");
      
      boundV2E.erase(boundV2E.begin());
      itBound = boundV2E.begin();
      actualParity += 2;
    }
  }
  
  // Create the 'Rec2DTwoTri2Quad' and 'Rec2DCollapseTri'
  {
    mapofEdges::iterator itE2E = _edges.begin();
    std::map<MEdge, std::list<MTriangle*> >::iterator ite = mapEdge.begin();
    for (; ite != mapEdge.end(); ++ite)
    if (ite->second.size() == 2) {
      Rec2DTwoTri2Quad *q = new Rec2DTwoTri2Quad(_edges[ite->first], ite->second);
      //Rec2DCollapseTri *c = new Rec2DCollapseTri(_edges[ite->first], ite->second);
      _actions.push_back(q);
      //_actions.insert(c);
      std::list<MTriangle*>::iterator it = ite->second.begin();
      _mea[*it].insert(q);
      //_mea[*it].insert(c);
      ++it;
      _mea[*it].insert(q);
      //_mea[*it].insert(c);
    }
  }
  
  // Rec2DTwoTri2Quad
  /*{
    std::list<std::map<MVertex*, std::list<MTriangle*> >::iterator>::iterator it4;
    for (it4 = fourTri.begin(); it4 != fourTri.end(); it4++) {
      Rec2DVertex *rv = _vertices[(*it4)->first];
      std::set<MEdge, Less_Edge> setEdge;
      {
        std::list<MTriangle*>::iterator it = (*it4)->second.begin();
        for (; it != (*it4)->second.end(); ++it) {
          setEdge.insert((*it)->getEdge(0));
          setEdge.insert((*it)->getEdge(1));
          setEdge.insert((*it)->getEdge(2));
        }
      }
      
      std::set<MEdge>::iterator it = setEdge.begin();
      for (; it != setEdge.end(); ++it) {
        std::map<MEdge, std::list<MTriangle*> >::iterator it2;
        it2 = mapEdge.find(*it);
        if (it2 != mapEdge.end())
        if (it2->second.size() == 2) {
          Rec2DTwoTri2Quad *q = new Rec2DTwoTri2Quad(_edges[it2->first], it2->second);
          _actions.insert(q);
          std::list<MTriangle*>::iterator it = it2->second.begin();
          _mea[*it].insert(q);
          ++it;
          _mea[*it].insert(q);
        }
        else
          Msg::Error("fjdaks;lfjkdsa;");
      }
    }
  }*/
  
  // Create the 'Rec2DFourTri2Quad' and 'Rec2DCollapseTri'
  {
    std::list<std::map<MVertex*, std::list<MTriangle*> >::iterator>::iterator it4;
    for (it4 = fourTri.begin(); it4 != fourTri.end(); it4++) {
      Rec2DVertex *rv = _vertices[(*it4)->first];
      if (!rv->getIsOnBoundary()) {
        Rec2DFourTri2Quad *q = new Rec2DFourTri2Quad(rv, (*it4)->second);
        //Rec2DCollapseTri *c = new Rec2DCollapseTri(rv, (*it4)->second);
        _actions.push_back(q);
        //_actions.insert(c);
        std::list<MTriangle*>::iterator it = (*it4)->second.begin();
        for (; it != (*it4)->second.end(); ++it) {
          _mea[*it].insert(q);
          //_mea[*it].insert(c);
        }
      }
    }
  }
  
  Msg::Info("State");
  Msg::Info("-----");
  Msg::Info("numEdge %d (%d), valEdge %g", _numEdge, _edges.size(), _valEdge);
  Msg::Info("numVert %d (%d), valVert %g", _numVert, _vertices.size(), _valVert);
  Msg::Info("global Value %g", Recombine2D::getGlobalValue(0,0,0,0));
  Msg::Info("num action %d", _actions.size());
  std::map<int, std::set<Rec2DVertex*> >::iterator it = _parities.begin();
  for (; it != _parities.end(); ++it) {
    Msg::Info("par %d, #%d", it->first, it->second.size());
  }
  mapofElementActions::iterator it2 = _mea.begin();
  int a = 0;
  for (; it2 != _mea.end(); ++it2) {
    a += it2->second.size();
  }
  if (a > 0)
    Msg::Info("%d elements in mapof elem to action, with average action %g", _mea.size(), (double)a/_mea.size());
  Msg::Info(" ");
}

Recombine2D::~Recombine2D()
{
  Recombine2D::_current = NULL;
  //delete vertices, edges, actions;
}

bool Recombine2D::recombine()
{
  Rec2DAction *nextAction;
  while (_actions.size() > 0) {
    double t = Cpu();
    nextAction = *std::max_element(_actions.begin(), _actions.end(),
                                   lessRec2DAction()                );
    if (nextAction->getReward() > 0) {
      if (_isAllQuad(nextAction))
        _choose(nextAction);
      else {
        nextAction->color(190, 0, 0);
        _removeReference(nextAction);
      }
    }
    else {
      nextAction->color(0, 100, 0);
      _removeReference(nextAction);
    }
    
    _gf->triangles = _tri;
    _gf->quadrangles = _quad;
#ifdef REC2D_DRAW
    CTX::instance()->mesh.changed = (ENT_ALL);
    FlGui::instance()->check();
    drawContext::global()->draw();
    while (Cpu()-t < REC2D_WAIT_TIME)
      FlGui::instance()->check();
#endif
#ifdef REC2D_SMOOTH
    laplaceSmoothing(_gf,1);
#endif

  std::map<int, std::set<Rec2DVertex*> >::iterator it = _parities.begin();
  for (; it != _parities.end(); ++it) {
    Msg::Info("par %d, #%d", it->first, it->second.size());
  }
  }
  
  Msg::Info("State");
  Msg::Info("-----");
  Msg::Info("numEdge %d (%d), valEdge %g", _numEdge, _edges.size(), _valEdge);
  Msg::Info("numVert %d (%d), valVert %g", _numVert, _vertices.size(), _valVert);
  Msg::Info("global Value %g", Recombine2D::getGlobalValue(0,0,0,0));
  Msg::Info("num action %d", _actions.size());
  std::map<int, std::set<Rec2DVertex*> >::iterator it = _parities.begin();
  for (; it != _parities.end(); ++it) {
    Msg::Info("par %d, #%d", it->first, it->second.size());
  }
  mapofElementActions::iterator it2 = _mea.begin();
  int a = 0;
  for (; it2 != _mea.end(); ++it2) {
    a += it2->second.size();
  }
  if (a > 0)
    Msg::Info("%d elements in mapof elem to action, with average action %g", _mea.size(), (double)a/_mea.size());
  Msg::Info(" ");
  
  return 1;
}

bool Recombine2D::_isAllQuad(Rec2DAction *action)
{
  int p[4];
  action->getParities(p);
  
  if (p[0] < 0 && p[1] < 0 && p[2] < 0 && p[3] < 0)
    return true;
  
  if (action->isObsolete()) {
    Msg::Error("[Recombine2D] obsolete action");
    return false;
  }
  
  int min = 100, index;
  for (int i = 0; i < 4; ++i) {
    if (p[i] > -1 && min > p[i]) {
      min = p[i];
      index = i;
    }
  }
  
  //Quid si p[0..4] = -1 ?
  
  std::map<Rec2DVertex*, int> newParVert;
  std::map<int, int> parAssoc; // first parity value become second parity value
  
  for (int i = 0; i < 4; i += 2) {
    int par;
    if ((index/2) * 2 == i)
      par = min;
    else if (min % 2)
      par = min - 1;
    else
      par = min + 1;
    for (int j = 0; j < 2; ++j) {
      if (p[i+j] == -1)
        newParVert.insert(std::make_pair(action->getRVertex(i+j), par));
      else if (p[i+j] != par)
        parAssoc.insert(std::make_pair(p[i+j], par));
    }
  }
  
  std::set<Rec2DAction*> neighbours;
  _getNeighbours(action, neighbours);
  
  while (neighbours.size() > 0) {
    std::set<Rec2DAction*>::iterator it = neighbours.begin();
    if ((*it)->getNum() != 1) {
      neighbours.erase(it);
      continue;
    }
    Rec2DVertex *v0 = (*it)->getRVertex(0);
    Rec2DVertex *v1 = (*it)->getRVertex(1);
    std::map<Rec2DVertex*, int>::iterator it2;
    int p0 = v0->getParity(), p1 = v1->getParity();
    if (p0 < 0 && (it2 = newParVert.find(v0)) == newParVert.end()) {
      neighbours.erase(it);
      continue;
    }
    if (p0 < 0)
      p0 = it2->second;
    
    if (p1 < 0 && (it2 = newParVert.find(v1)) == newParVert.end()) {
      neighbours.erase(it);
      continue;
    }
    if (p1 < 0)
      p1 = it2->second;
    
    std::map<int, int>::iterator it3;
    if ((it3 = parAssoc.find(p0)) != parAssoc.end())
      p0 = it3->second;
    if ((it3 = parAssoc.find(p1)) != parAssoc.end())
      p1 = it3->second;
    
    if (p0 != p1) {
      neighbours.erase(it);
      continue;
    }
    
    int par;
    bool hasChange = false;
    if (p0 % 2)
      par = p0 - 1;
    else
      par = p0 + 1;
    (*it)->getParities(p);
    for (int j = 2; j < 4; ++j) {
      if (p[j] == -1) {
        if ((it2 = newParVert.find((*it)->getRVertex(j))) == newParVert.end()) {
          newParVert.insert(std::make_pair(action->getRVertex(j), par));
          hasChange = true;
        }
        else if (it2->second != par)
          return false;
      }
      else if (p[j] != par) {
        if ((it3 = parAssoc.find(p[j])) == parAssoc.end()) {
          parAssoc.insert(std::make_pair(p[j], par));
          hasChange = true;
        }
        else {
          int a = it3->second;
          while (a != par && (it3 = parAssoc.find(a)) != parAssoc.end()) {
            a = it3->second;
          }
          if (a != par)
            return false;
        }
      }
    }
    Rec2DAction *ra = *it;
    neighbours.erase(it);
    if (hasChange)
      _getNeighbours(ra, neighbours);
  }
  return true;
}

void Recombine2D::_choose(Rec2DAction *action)
{
  action->apply();
  _removeIncompatible(action);
  ++_numChange;
}

void Recombine2D::_removeIncompatible(Rec2DAction *action)
{
  std::set<MTriangle*> touchedTri;
  action->getTriangles(touchedTri);
  std::set<MTriangle*>::iterator itTouched;
  
  std::set<Rec2DAction*> incomp;
  {
    itTouched = touchedTri.begin();
    for (; itTouched != touchedTri.end(); ++itTouched) {
      mapofElementActions::iterator ite2a = _mea.find(*itTouched);
      if (ite2a != _mea.end()) {
        std::set<Rec2DAction*>::iterator ita = ite2a->second.begin();
        for (; ita != ite2a->second.end(); ++ita)
          incomp.insert(*ita);
      }
      else
        Msg::Error("[Recombine2D] didn't found triangle %d (rmIncomp1)", (*itTouched)->getNum());
    }
  }
  
  std::set<Rec2DAction*>::iterator itIncomp = incomp.begin();
  for (; itIncomp != incomp.end(); ++itIncomp) {
    std::set<MTriangle*> touched;
    (*itIncomp)->getTriangles(touched);
    for (itTouched = touched.begin(); itTouched != touched.end(); ++itTouched) {
      mapofElementActions::iterator ite2a = _mea.find(*itTouched);
      if (ite2a != _mea.end()) {
        bool b = ite2a->second.erase(*itIncomp);
        if (!b)
          Msg::Error("[Recombine2D] Tri->Action not found (rmIncomp)");
      }
      else
        Msg::Error("[Recombine2D] didn't found triangle %d (rmIncomp)", (*itTouched)->getNum());
    }
    //bool b = _actions.erase(*itIncomp);
    setofRec2DAction::iterator it2 = _actions.begin();
    bool b = false;
    while (it2 != _actions.end()) {
      if (*it2 == *itIncomp) {
        _actions.erase(it2);
        b = true;
        break;
      }
      ++it2;
    }
    if (!b)
      Msg::Error("[Recombine2D] action not found (rmIncomp2)");
    delete *itIncomp;
  }
  
  itTouched = touchedTri.begin();
  for (; itTouched != touchedTri.end(); ++itTouched) {
    bool b = _mea.erase(*itTouched);
    if (!b)
      Msg::Error("[Recombine2D] triangle not found %d", (*itTouched)->getNum());
  }
}

void Recombine2D::_removeReference(Rec2DAction *action)
{
  std::set<MTriangle*> touchedTri;
  action->getTriangles(touchedTri);
  std::set<MTriangle*>::iterator it = touchedTri.begin();
  for (; it != touchedTri.end(); ++it) {
    mapofElementActions::iterator ite2a = _mea.find(*it);
    if (ite2a != _mea.end()) {
      bool b = ite2a->second.erase(action);
      if (!b)
        Msg::Error("[Recombine2D] Tri->Action not found (rmRef)");
    }
    else
      Msg::Error("[Recombine2D] didn't found triangle %d (rmRef)", (*it)->getNum());
  }
  //bool b = _actions.erase(action);
  setofRec2DAction::iterator it2 = _actions.begin();
  bool b = false;
  while (it2 != _actions.end()) {
    if (*it2 == action) {
      _actions.erase(it2);
      b = true;
      break;
    }
    ++it2;
  }
  if (!b)
    Msg::Error("[Recombine2D] action not found (rmRef)");
  delete action;
}

void Recombine2D::_getNeighbours(Rec2DAction *ra, std::set<Rec2DAction*> &actions)
{
  std::set<MTriangle*> touchedTri;
  ra->getTriangles(touchedTri);
  std::set<MTriangle*>::iterator itTouched;
  
  std::set<Rec2DAction*> incomp;
  {
    itTouched = touchedTri.begin();
    for (; itTouched != touchedTri.end(); ++itTouched) {
      mapofElementActions::iterator ite2a = _mea.find(*itTouched);
      if (ite2a != _mea.end()) {
        std::set<Rec2DAction*>::iterator ita = ite2a->second.begin();
        for (; ita != ite2a->second.end(); ++ita)
          incomp.insert(*ita);
      }
      else
        Msg::Error("[Recombine2D.] didn't found triangle %d (rmIncomp1)", (*itTouched)->getNum());
    }
  }
  
  std::set<Rec2DAction*>::iterator it = incomp.begin();
  for (; it != incomp.end(); ++it) {
    (*it)->getTriangles(touchedTri);
  }
  
  std::set<Rec2DAction*> neighbours;
  {
    itTouched = touchedTri.begin();
    for (; itTouched != touchedTri.end(); ++itTouched) {
      mapofElementActions::iterator ite2a = _mea.find(*itTouched);
      if (ite2a != _mea.end()) {
        std::set<Rec2DAction*>::iterator ita = ite2a->second.begin();
        for (; ita != ite2a->second.end(); ++ita)
          neighbours.insert(*ita);
      }
      else
        Msg::Error("[Recombine2D.] didn't found triangle %d (rmIncomp1)", (*itTouched)->getNum());
    }
    std::set<Rec2DAction*>::iterator itIncomp = incomp.begin();
    for (; itIncomp != incomp.end(); ++itIncomp) {
      bool b = neighbours.erase(*itIncomp);
      if (!b)
        Msg::Error("[Recombine2D] didn't found incomp action");
    }
  }
  
  for (it = neighbours.begin(); it != neighbours.end(); ++it) {
    actions.insert(*it);
  }
}

double Recombine2D::getGlobalValue(int numEdge, double valEdge,
                                   int numVert, double valVert )
{
  double a = (_current->_valVert + valVert) / (_current->_numVert + numVert);
  return (_current->_valEdge + valEdge) / (_current->_numEdge + numEdge) * a * a;
}

Rec2DEdge* Recombine2D::getREdge(MEdge e)
{
  mapofEdges::iterator it = _current->_edges.find(e);
  if (it != _current->_edges.end())
    return it->second;
  Msg::Error("[Recombine2D::getREdge] edge not found");
  return NULL;
}

Rec2DVertex* Recombine2D::getRVertex(MVertex *v)
{
  mapofVertices::iterator it = _current->_vertices.find(v);
  if (it != _current->_vertices.end())
    return it->second;
  Msg::Error("[Recombine2D::getRVertex] vertex not found");
  return NULL;
}

void Recombine2D::remove(MEdge e)
{
  mapofEdges::iterator it = _current->_edges.find(e);
  if (it != _current->_edges.end())
    _current->_edges.erase(it);
  else
    Msg::Error("[Recombine2D::getREdge] edge not found");
}

void Recombine2D::remove(MVertex *v)
{
  mapofVertices::iterator it = _current->_vertices.find(v);
  if (it != _current->_vertices.end())
    _current->_vertices.erase(it);
  else
    Msg::Error("[Recombine2D::getRVertex] vertex not found");
}

void Recombine2D::remove(MTriangle *tri)
{
  std::vector<MTriangle*>::iterator it = _current->_tri.begin();
  for (; it != _current->_tri.end(); ++it) {
    if (*it == tri) {
      _current->_tri.erase(it);
      return;
    }
  }
  Msg::Error("[Recombine2D] triangle %d was not there", tri->getNum());
}

void Recombine2D::add(MQuadrangle *quad)
{
  _current->_quad.push_back(quad);
}


/**  Rec2DAction  **/
/*******************/
bool Rec2DAction::operator<(Rec2DAction &other)
{
  return getReward() < other.getReward(); 
}

MQuadrangle* Rec2DAction::_createQuad(std::vector<Rec2DEdge*> &boundEdge) const
{
  if (boundEdge.size() != 4) {
    Msg::Error("[Rec2DAction] Not 4 edges for quad creation");
    return new MQuadrangle(NULL, NULL, NULL, NULL);
  }
  MVertex *v1, *v2, *v3, *v4;
  v1 = boundEdge[0]->getRVertex(0)->getMVertex();
  v2 = boundEdge[0]->getRVertex(1)->getMVertex();
  int I;
  for (unsigned int i = 1; i < 4; ++i) {
    if (v2 == boundEdge[i]->getRVertex(0)->getMVertex()) {
      v3 = boundEdge[i]->getRVertex(1)->getMVertex();
      I = i;
      break;
    }
    if (v2 == boundEdge[i]->getRVertex(1)->getMVertex()) {
      v3 = boundEdge[i]->getRVertex(0)->getMVertex();
      I = i;
      break;
    }
  }
  for (unsigned int i = 1; i < 4; ++i) {
    if (i == I) continue;
    if (v3 == boundEdge[i]->getRVertex(0)->getMVertex()) {
      v4 = boundEdge[i]->getRVertex(1)->getMVertex();
      break;
    }
    if (v3 == boundEdge[i]->getRVertex(1)->getMVertex()) {
      v4 = boundEdge[i]->getRVertex(0)->getMVertex();
      break;
    }
  }
  return new MQuadrangle(v1, v2, v3, v4);
}


/**  Rec2DTwoTri2Quad  **/
/************************/
Rec2DTwoTri2Quad::Rec2DTwoTri2Quad(Rec2DEdge *re, std::list<MTriangle*> &tri)
{
  int i;
  std::set<MEdge, Less_Edge> extEdges;
  {
    std::list<MTriangle*>::iterator it = tri.begin();
    for (i = 0; it != tri.end() && i < 2; ++it, ++i) {
      for (int j = 0; j < 3; ++j)
        extEdges.insert((*it)->getEdge(j));
      _triangles[i] = *it;
    }
    if (it != tri.end() || i < 2)
      Msg::Error("[Rec2DTwoTri2Quad] Wrong number of triangles");
    extEdges.erase(re->getMEdge());
  }
  
  _edges[0] = re;
  std::set<MEdge>::iterator ite = extEdges.begin();
  for (i = 1; ite != extEdges.end() && i < 5; ++ite, ++i)
    _edges[i] = Recombine2D::getREdge(*ite);
  if (ite != extEdges.end() || i < 5)
    Msg::Error("[Rec2DTwoTri2Quad] Wrong number of edges");
  
  _vertices[0] = re->getRVertex(0);
  _vertices[1] = re->getRVertex(1);
  MVertex *v2, *v3;
  v2 = _triangles[0]->getOtherVertex(_vertices[0]->getMVertex(),
                                    _vertices[1]->getMVertex());
  v3 = _triangles[1]->getOtherVertex(_vertices[0]->getMVertex(),
                                    _vertices[1]->getMVertex());
  _vertices[2] = Recombine2D::getRVertex(v2);
  _vertices[3] = Recombine2D::getRVertex(v3);
  
  _computeGlobVal();
}

bool Rec2DTwoTri2Quad::isObsolete()
{
  int p0 = _vertices[0]->getParity();
  int p1 = _vertices[1]->getParity();
  int p2 = _vertices[2]->getParity();
  int p3 = _vertices[3]->getParity();
  if (p0>-1 && p1>-1 && p0/2 == p1/2 && p0 % 2 != p1 % 2 ||
      p2>-1 && p3>-1 && p2/2 == p3/2 && p2 % 2 != p3 % 2 ||
      p0>-1 && p0 == p2                                  ||
      p0>-1 && p0 == p3                                  ||
      p1>-1 && p1 == p2                                  ||
      p1>-1 && p1 == p3                                    )
    return true;
  return false;
}

void Rec2DTwoTri2Quad::apply()
{
  if (isObsolete()) {
    Msg::Error("[Rec2DTwoTri2Quad] Applying obsolet action");
    return;
  }
  
  int min = 100, index = -1;
  for (int i = 0; i < 4; ++i) {
    if (_vertices[0]->getParity() > -1 && min > _vertices[0]->getParity()) {
      min = _vertices[0]->getParity();
      index = i;
    }
  }
  if (index == -1) {
    int par = Recombine2D::highPar();
    _vertices[0]->setParity(par);
    _vertices[1]->setParity(par);
    _vertices[2]->setParity(par+1);
    _vertices[3]->setParity(par+1);
  }
  else { 
    for (int i = 0; i < 4; i += 2) {
      int par;
      if ((index/2) * 2 == i)
        par = min;
      else if (min % 2)
        par = min - 1;
      else
        par = min + 1;
      Msg::Info("%d", par);
      for (int j = 0; j < 2; ++j) {
        Msg::Info(" %d %d", _vertices[i+j]->getParity(), par);
        if (_vertices[i+j]->getParity() == -1)
          _vertices[i+j]->setParity(par);
        else if (_vertices[i+j]->getParity() != par)
          Recombine2D::associateParity(_vertices[0]->getParity(), par);
      }
    }
  }
  
  double valEdge = - REC2D_EDGE_BASE * _edges[0]->getQual();
  for (int i = 1; i < 5; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
  
  Recombine2D::addNumEdge(4*REC2D_EDGE_QUAD - REC2D_EDGE_BASE);
  Recombine2D::addValEdge(valEdge);
  //Recombine2D::addValVert(_vertices[0]->getGain(-1) + _vertices[1]->getGain(-1));
  
  Recombine2D::remove(_triangles[0]); // FIXME not performant at all !!!
  Recombine2D::remove(_triangles[1]);
  std::vector<Rec2DEdge*> edges;
  for (int i = 1; i < 5; ++i)
    edges.push_back(_edges[i]);
  Recombine2D::add(_createQuad(edges));
  
  _vertices[0]->remove(_edges[0]);
  _vertices[1]->remove(_edges[0]);
  Recombine2D::remove(_edges[0]->getMEdge()); // could also delete REdge
  delete _edges[0];
}

void Rec2DTwoTri2Quad::getParities(int *par)
{
  par[0] = _vertices[0]->getParity();
  par[1] = _vertices[1]->getParity();
  par[2] = _vertices[2]->getParity();
  par[3] = _vertices[3]->getParity();
}

void Rec2DTwoTri2Quad::_computeGlobVal()
{
  double valEdge = - REC2D_EDGE_BASE * _edges[0]->getQual();
  for (int i = 1; i < 5; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
  
  double valVert = _vertices[0]->getGain(-1) + _vertices[1]->getGain(-1);
  
  _globValIfExecuted = Recombine2D::getGlobalValue(4*REC2D_EDGE_QUAD - REC2D_EDGE_BASE,
                                                   valEdge, 0, valVert     );
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DTwoTri2Quad::color(int a, int b, int c)
{
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  _triangles[0]->setCol(col);
  _triangles[1]->setCol(col);
}


/**  Rec2DFourTri2Quad  **/
/*************************/
Rec2DFourTri2Quad::Rec2DFourTri2Quad(Rec2DVertex *rv, std::list<MTriangle*> &tri)
{
  int i, j;
  std::set<MEdge, Less_Edge> edges;
  {
    std::list<MTriangle*>::iterator it = tri.begin();
    for (i = 0; it != tri.end() && i < 4; ++it, ++i) {
      for (j = 0; j < 3; ++j)
        edges.insert((*it)->getEdge(j));
      _triangles[i] = *it;
    }
    if (it != tri.end() || i < 4)
      Msg::Error("[Rec2DFourTri2Quad] Wrong number of triangles");
  }
  
  std::set<MEdge>::iterator ite = edges.begin();
  for (i = 0, j = 4; ite != edges.end() && (i < 4 || j < 8); ++ite) {
    if ((*ite).getVertex(0) == rv->getMVertex() ||
        (*ite).getVertex(1) == rv->getMVertex()   )
      _edges[i++] = Recombine2D::getREdge(*ite);
    else if (j < 8)
      _edges[j++] = Recombine2D::getREdge(*ite);
    else
      Msg::Error("[Rec2DFourTri2Quad] Too much exterior edges");
  }
  if (edges.size() > 8 || ite != edges.end() || i < 4 || i > 4 || j < 8)
    Msg::Error("[Rec2DFourTri2Quad] Wrong number of edges");
  
  _vertices[4] = rv;
  // the 4 other must be in order : 2 non adjacent + last 2
  _vertices[1] = _edges[4]->getRVertex(0);
  _vertices[3] = _edges[4]->getRVertex(1);
  for (int i = 5; i < 8; ++i) {
    if (_edges[i]->getRVertex(0) == _vertices[1])
      _vertices[0] = _edges[i]->getRVertex(1);
    if (_edges[i]->getRVertex(1) == _vertices[1])
      _vertices[0] = _edges[i]->getRVertex(0);
    if (_edges[i]->getRVertex(0) == _vertices[3])
      _vertices[2] = _edges[i]->getRVertex(1);
    if (_edges[i]->getRVertex(1) == _vertices[3])
      _vertices[2] = _edges[i]->getRVertex(0);
  }
  
  _computeGlobVal();
}

bool Rec2DFourTri2Quad::isObsolete()
{
  int p0 = _vertices[0]->getParity();
  int p1 = _vertices[1]->getParity();
  int p2 = _vertices[2]->getParity();
  int p3 = _vertices[3]->getParity();
  if (p0>-1 && p1>-1 && p0/2 == p1/2 && p0 % 2 != p1 % 2 ||
      p2>-1 && p3>-1 && p2/2 == p3/2 && p2 % 2 != p3 % 2 ||
      p0>-1 && p0 == p2                                  ||
      p0>-1 && p0 == p3                                  ||
      p1>-1 && p1 == p2                                  ||
      p1>-1 && p1 == p3                                    )
    return true;
  return false;
}

void Rec2DFourTri2Quad::apply()
{
  double valEdge = 0;
  for (int i = 0; i < 4; ++i)
    valEdge -= REC2D_EDGE_BASE * _edges[i]->getQual();
  for (int i = 4; i < 8; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
    
  double valVert = - _vertices[4]->getQual();
  for (int i = 0; i < 4; ++i)
    valEdge += _vertices[i]->getGain(-1);
  
  Recombine2D::addNumEdge(4*REC2D_EDGE_QUAD - 4*REC2D_EDGE_BASE);
  Recombine2D::addNumVert(-1);
  Recombine2D::addValEdge(valEdge);
  Recombine2D::addValVert(valVert);
  
  Recombine2D::remove(_triangles[0]); // FIXME not performant at all !!!
  Recombine2D::remove(_triangles[1]);
  Recombine2D::remove(_triangles[2]);
  Recombine2D::remove(_triangles[3]);
  std::vector<Rec2DEdge*> edges;
  for (int i = 4; i < 8; ++i)
    edges.push_back(_edges[i]);
  Recombine2D::add(_createQuad(edges));
  
  for (int i = 0; i < 4; ++i) {
    _edges[i]->getRVertex(0)->remove(_edges[i]);
    _edges[i]->getRVertex(1)->remove(_edges[i]);
    Recombine2D::remove(_edges[i]->getMEdge());
    delete _edges[i];
  }
  Recombine2D::remove(_vertices[4]->getMVertex());
  delete _vertices[4];
}

void Rec2DFourTri2Quad::getParities(int *par)
{
  par[0] = _vertices[0]->getParity();
  par[1] = _vertices[1]->getParity();
  par[2] = _vertices[2]->getParity();
  par[3] = _vertices[3]->getParity();
}

void Rec2DFourTri2Quad::_computeGlobVal()
{
  double valEdge = 0;
  for (int i = 0; i < 4; ++i)
    valEdge -= REC2D_EDGE_BASE * _edges[i]->getQual();
  for (int i = 4; i < 8; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
    
  double valVert = - _vertices[4]->getQual();
  for (int i = 0; i < 4; ++i)
    valEdge += _vertices[i]->getGain(-1);
  
  _globValIfExecuted = Recombine2D::getGlobalValue(4*REC2D_EDGE_QUAD - 4*REC2D_EDGE_BASE,
                                                   valEdge, -1, valVert      );
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DFourTri2Quad::color(int a, int b, int c)
{
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  _triangles[0]->setCol(col);
  _triangles[1]->setCol(col);
  _triangles[2]->setCol(col);
  _triangles[3]->setCol(col); 
}


/**  Rec2DCollapseTri  **/
/*********************/
Rec2DCollapseTri::Rec2DCollapseTri(Rec2DVertex *rv, std::list<MTriangle*> &tri)
{
  int i;
  std::set<MEdge, Less_Edge> extEdges;
  {
    std::list<MTriangle*>::iterator it = tri.begin();
    for (i = 0; it != tri.end() && i < 4; ++it, ++i) {
      for (int j = 0; j < 3; ++j)
      if ((*it)->getEdge(j).getVertex(0) != rv->getMVertex() &&
          (*it)->getEdge(j).getVertex(1) != rv->getMVertex()   )
        extEdges.insert((*it)->getEdge(j));
    }
    if (it != tri.end() || i < 4)
      Msg::Error("[Rec2DFourTri2Quad] Wrong number of triangles");
  }
  
  _vertices[4] = rv;
  // the 4 other must be in order : 2 non adjacent + last 2
  std::set<MEdge>::iterator ite = extEdges.begin();
  Rec2DEdge *re = Recombine2D::getREdge(*ite);
  _vertices[1] = re->getRVertex(0);
  _vertices[3] = re->getRVertex(1);
  ++ite;
  for (; ite != extEdges.end(); ++ite) {
    re = Recombine2D::getREdge(*ite);
    if (re->getRVertex(0) == _vertices[1])
      _vertices[0] = re->getRVertex(1);
    if (re->getRVertex(1) == _vertices[1])
      _vertices[0] = re->getRVertex(0);
    if (re->getRVertex(0) == _vertices[3])
      _vertices[2] = re->getRVertex(1);
    if (re->getRVertex(1) == _vertices[3])
      _vertices[2] = re->getRVertex(0);
  }
  
  _computeGlobVal();
}

Rec2DCollapseTri::Rec2DCollapseTri(Rec2DEdge *re, std::list<MTriangle*> &tri)
: _edge(re)
{
  int i;
  std::set<MEdge, Less_Edge> extEdges;
  {
    std::list<MTriangle*>::iterator it = tri.begin();
    for (i = 0; it != tri.end() && i < 2; ++it, ++i) {
      for (int j = 0; j < 3; ++j)
        extEdges.insert((*it)->getEdge(j));
      _triangles[i] = *it;
    }
    if (it != tri.end() || i < 2)
      Msg::Error("[Rec2DTwoTri2Quad] Wrong number of triangles");
    extEdges.erase(re->getMEdge());
  }
  _triangles[2] = _triangles[3] = NULL;
  
  _vertices[0] = re->getRVertex(0);
  _vertices[1] = re->getRVertex(1);
  MVertex *v2, *v3;
  v2 = _triangles[0]->getOtherVertex(_vertices[0]->getMVertex(),
                                    _vertices[1]->getMVertex());
  v3 = _triangles[1]->getOtherVertex(_vertices[0]->getMVertex(),
                                    _vertices[1]->getMVertex());
  _vertices[2] = Recombine2D::getRVertex(v2);
  _vertices[3] = Recombine2D::getRVertex(v3);
  _vertices[4] = NULL;
  
  _computeGlobVal();
}

bool Rec2DCollapseTri::isObsolete()
{
  int p0 = _vertices[0]->getParity();
  int p1 = _vertices[1]->getParity();
  int p2 = _vertices[2]->getParity();
  int p3 = _vertices[3]->getParity();
  int b0 = _vertices[0]->getIsOnBoundary();
  int b1 = _vertices[1]->getIsOnBoundary();
  int b2 = _vertices[2]->getIsOnBoundary();
  int b3 = _vertices[3]->getIsOnBoundary();
  if ((b0 && b1) || (p0>-1 && p1>-1 && p0/2 == p1/2 && p0 % 2 != p1 % 2) &&
      (b2 && b3) || (p2>-1 && p3>-1 && p2/2 == p3/2 && p2 % 2 != p3 % 2)   )
    return true;
  return false;
}

void Rec2DCollapseTri::apply()
{
  return;
}

void Rec2DCollapseTri::getParities(int *par)
{
  par[0] = _vertices[0]->getParity();
  par[1] = _vertices[1]->getParity();
  par[2] = _vertices[2]->getParity();
  par[3] = _vertices[3]->getParity();
}

void Rec2DCollapseTri::_computeGlobVal()
{
  int b0 = _vertices[0]->getIsOnBoundary();
  int b1 = _vertices[1]->getIsOnBoundary();
  int b2 = _vertices[2]->getIsOnBoundary();
  int b3 = _vertices[3]->getIsOnBoundary();
  
  std::map<Rec2DVertex*, int> neighbourVert;
  std::set<Rec2DEdge*> neighbourEdge; 
  if (!b0 || !b1) {
    _vertices[0]->getNeighbours(neighbourVert, neighbourEdge);
    _vertices[1]->getNeighbours(neighbourVert, neighbourEdge);
    if (_vertices[4]) {
      neighbourVert.erase(_vertices[4]);
      _vertices[4]->getNeighbourEdges(neighbourEdge);
    }
    //else
    //  neighbourEdge.insert(_edge);
    
    int numEdge = 0, numVert = 0;
    double valEdge = .0, valVert = .0;
    {
      std::set<Rec2DEdge*>::iterator it = neighbourEdge.begin();
      for (; it != neighbourEdge.end(); ++it) {
        valEdge -= (*it)->getWeightedQual();
        numEdge -= (*it)->getWeight();
      }
      valVert -= _vertices[0]->getQual();
      valVert -= _vertices[1]->getQual();
      if (_vertices[4]) {
        valVert -= _vertices[4]->getQual();
        numVert -= 1;
        valVert += _vertices[2]->getGain(-2);
        valVert += _vertices[3]->getGain(-2);
      }
      else {
        valVert += _vertices[2]->getGain(-1);
        valVert += _vertices[3]->getGain(-1);
      }
    }
    if (b0)
      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[0]);
    else if (b1)
      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[1]);
    else
      _qualCavity(valVert, valEdge, numEdge, neighbourVert);
    numVert -= 1;
    
    _globValIfExecuted =
        Recombine2D::getGlobalValue(numEdge, valEdge, numVert, valVert);
  }
  else
    _globValIfExecuted = -1.;
  
  
  neighbourVert.clear();
  neighbourEdge.clear();
  if (!b2 || !b3) {
    _vertices[2]->getNeighbours(neighbourVert, neighbourEdge);
    _vertices[3]->getNeighbours(neighbourVert, neighbourEdge);
    if (_vertices[4]) {
      neighbourVert.erase(_vertices[4]);
      _vertices[4]->getNeighbourEdges(neighbourEdge);
    }
    else
      neighbourEdge.insert(_edge);
    
    int numEdge = 0, numVert = 0;
    double valEdge = .0, valVert = .0;
    {
      std::set<Rec2DEdge*>::iterator it = neighbourEdge.begin();
      for (; it != neighbourEdge.end(); ++it) {
        valEdge -= (*it)->getWeightedQual();
        numEdge -= (*it)->getWeight();
      }
      valVert -= _vertices[2]->getQual();
      valVert -= _vertices[3]->getQual();
      if (_vertices[4]) {
        valVert -= _vertices[4]->getQual();
        numVert -= 1;
        valVert += _vertices[0]->getGain(-2);
        valVert += _vertices[1]->getGain(-2);
      }
      else {
        valVert += _vertices[0]->getGain(-2);
        valVert += _vertices[1]->getGain(-2);
      }
    }
    if (b2)
      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[2]);
    else if (b3)
      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[3]);
    else
      _qualCavity(valVert, valEdge, numEdge, neighbourVert);
    numVert -= 1;
    
    _globValIfExecuted2 =
        Recombine2D::getGlobalValue(numEdge, valEdge, numVert, valVert);
  }
  else
    _globValIfExecuted2 = -1.;
    
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DCollapseTri::_qualCavity(double &valVert, double &valEdge,
                                   int &numEdge,
                                   std::map<Rec2DVertex*, int> &vert,
                                   Rec2DVertex *imposedVert          )
{
  Recombine2D::bo = true;
  std::map<Rec2DVertex*, int>::iterator it;
  Rec2DVertex *rv = imposedVert;
  if (rv == NULL) {
    double u, v = u = .0;
    it = vert.begin();
    for (; it != vert.end(); ++it) {
      u += it->first->u();
      v += it->first->v();
    }
    u /= vert.size();
    v /= vert.size();
    
    rv = new Rec2DVertex(u, v);
  }
  valVert = rv->getQual(vert.size());
  it = vert.begin();
  for (; it != vert.end(); ++it) {
    Rec2DEdge re(rv, it->first);
    valEdge += it->second * re.getQual();
    numEdge += it->second;
  }
  if (imposedVert == NULL) {
    rv->deleteMVertex();
    delete rv;
  }
}

void Rec2DCollapseTri::color(int a, int b, int c)
{
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  _triangles[0]->setCol(col);
  _triangles[1]->setCol(col);
  if (_triangles[2]) {
    _triangles[2]->setCol(col);
    _triangles[3]->setCol(col);
  }
}


/**  Rec2DVertex  **/
/*******************/
Rec2DVertex::Rec2DVertex(MVertex *v, std::list<MTriangle*> tri, int onWhat,
                         std::map<MVertex*, std::set<GEdge*> > gEdges)
: _v(v), _onWhat(onWhat), _parity(-1), _lastChange(-1), _numEl(tri.size())
{
  if (_onWhat == -1) {
    std::map<MVertex*, std::set<GEdge*> >::iterator it = gEdges.find(_v);
    if (it != gEdges.end()) {
      _angle = _computeAngle(_v, tri, it->second);
    }
    else {
      Msg::Warning("[meshRecombine2D] Can't compute corner angle, setting angle to pi/2");
      _angle = M_PI / 2.;
    }
  }
  reparamMeshVertexOnFace(_v, Recombine2D::getGFace(), _param); 
  _computeQual();
}

Rec2DVertex::Rec2DVertex(double u, double v)
: _onWhat(1), _parity(-1), _lastChange(-1)
{
  _param[0] = u;
  _param[1] = v;
  
  GPoint p = Recombine2D::getGFace()->point(_param);
  _v = new MVertex(p.x(), p.y(), p.z(), Recombine2D::getGFace());
  static int i = 0;
  if (++i < 20)
    Msg::Info("resulting point = [%g, %g, %g]", p.x(), p.y(), p.z());
}

double Rec2DVertex::_computeAngle(MVertex *v,
                                  std::list<MTriangle*> &listTri,
                                  std::set<GEdge*> &setEdge)
{
  if (setEdge.size() != 2) {
    Msg::Warning("[meshGFaceRecombine] Wrong number of edge : %d, returning pi/2", setEdge.size());
    return M_PI / 2.;
  }
  static const double prec = 100.;
  
  SVector3 vectv = SVector3(v->x(), v->y(), v->z());
  SVector3 firstDer0, firstDer1;
  
  std::set<GEdge*>::iterator it = setEdge.begin();
  for (int k = 0; k < 2; ++it, ++k) {
    GEdge *ge = *it;
    SVector3 vectlb = ge->position(ge->getLowerBound());
    SVector3 vectub = ge->position(ge->getUpperBound());
    vectlb -= vectv;
    vectub -= vectv;
    double normlb, normub;
    if ((normlb = norm(vectlb)) > prec * (normub = norm(vectub)))
      firstDer1 = ge->firstDer(ge->getUpperBound());
    else if (normub > prec * normlb)
      firstDer1 = ge->firstDer(ge->getLowerBound());
    else {
      Msg::Warning("[meshGFaceRecombine] Bad precision, returning pi/2");
      return M_PI / 2.;
    }
    if (k == 0)
      firstDer0 = firstDer1;
  }
  
  firstDer0 = firstDer0 * (1 / norm(firstDer0));
  firstDer1 = firstDer1 * (1 / norm(firstDer1));
  
  double angle1 = acos(dot(firstDer0, firstDer1));
  double angle2 = 2. * M_PI - angle1;
  
  double angleMesh = .0;
  std::list<MTriangle*>::iterator it2 = listTri.begin();
  for (; it2 != listTri.end(); ++it2) {
    MTriangle *t = *it2;
    int k = 0;
    while (t->getVertex(k) != v && k < 3)
      ++k;
    if (k == 3) {
      Msg::Warning("[meshGFaceRecombine] Wrong triangle, returning pi/2");
      return M_PI / 2.;
    }
    angleMesh += angle3Vertices(t->getVertex((k+1)%3), v, t->getVertex((k+2)%3));
  }
  
  if (angleMesh < M_PI)
    return angle1;
  return angle2;
}

double Rec2DVertex::getQual(int numEdge)
{
  if (numEdge > 1) {
    switch (_onWhat) {
      case 1 :
        return _qualVSnum[_onWhat][numEdge-1];
      case 0 :
        return _qualVSnum[_onWhat][numEdge-2];
      case -1 :
        return 1. - fabs(2./M_PI * _angle/(numEdge-1) - 1.);
      default :
        Msg::Error("[Rec2DVertex] Don't know on what is the vertex");
        return -1.;
    }
  }
  if (_lastChange < Recombine2D::getNumChange())
    _computeQual();
  return _qual;
}

void Rec2DVertex::_computeQual()
{
  if (_onWhat > -1)
    _qual = _qualVSnum[_onWhat][_numEl-1];
  else
    _qual = 1. - fabs(2./M_PI * _angle/_numEl - 1.);
  _lastChange = Recombine2D::getNumChange();
}

double Rec2DVertex::getGain(int n)
{
  if (_onWhat > -1) {
    switch (n) {
      case 1 :
        return _gains[_onWhat][_numEl-1];
      case -1 :
        return - _gains[_onWhat][_numEl-2];
      default :
        return _qualVSnum[_onWhat][_numEl-1+n] - _qualVSnum[_onWhat][_numEl-1];
    }
  }
  else
    return fabs(2./M_PI * _angle/_numEl - 1.)
         - fabs(2./M_PI * _angle/(_numEl + n) - 1.);
}

void Rec2DVertex::getNeighbours(std::map<Rec2DVertex*, int> &vert,
                                std::set<Rec2DEdge*> &edge        )
{
  Rec2DVertex *rv;
  std::map<Rec2DVertex*, int>::iterator it;
  for (unsigned int i = 0; i < _edges.size(); ++i){
    edge.insert(_edges[i]);
    if (_edges[i]->getRVertex(0) != this)
      rv = _edges[i]->getRVertex(0);
    else
      rv = _edges[i]->getRVertex(1);
    if ((it = vert.find(rv)) != vert.end())
      it->second += _edges[i]->getWeight() - REC2D_EDGE_BASE;
    else
      vert[rv] = _edges[i]->getWeight();
  }
}

void Rec2DVertex::getNeighbourEdges(std::set<Rec2DEdge*> &edge)
{
  for (unsigned int i = 0; i < _edges.size(); ++i)
    edge.insert(_edges[i]);
}

void Rec2DVertex::initStaticTable()
{
  if (_qualVSnum == NULL) {
    // _qualVSnum[onWhat][nEl]; onWhat={0:edge,1:face} / nEl=_numEl-1
    // _gains[onWhat][nEl]; onWhat={0:edge,1:face} / nEl=_numEl-1 (earning of adding an element)
    int nE = 10, nF = 20;
    
    _qualVSnum = new double*[2];
    _qualVSnum[0] = new double[nE];
    for (int i = 0; i < nE; ++i)
      _qualVSnum[0][i] = 1. - fabs(2./(i+1) - 1.);
    _qualVSnum[1] = new double[nF];
    for (int i = 0; i < nF; ++i)
      _qualVSnum[1][i] = 1. - fabs(4./(i+1) - 1.);
      
    _gains = new double*[2];
    _gains[0] = new double[nE-1];
    for (int i = 0; i < nE-1; ++i)
      _gains[0][i] = _qualVSnum[0][i+1] - _qualVSnum[0][i];
    _gains[1] = new double[nF-1];
    for (int i = 0; i < nF-1; ++i)
      _gains[1][i] = _qualVSnum[1][i+1] - _qualVSnum[1][i];
  }
}

void Rec2DVertex::remove(Rec2DEdge *re)
{
  std::vector<Rec2DEdge*>::iterator it = _edges.begin();
  bool b = false;
  for (; it != _edges.end() ; ++it)
    if (*it == re) {
      _edges.erase(it--);
      b = true;
      break;
    }
  if (b) {
    Recombine2D::addValVert(getGain(-1));
    --_numEl;
  }
  else
    Msg::Error("[Rec2DVertex] Edge not found");
}


/**  Rec2DEdge  **/
/*****************/
Rec2DEdge::Rec2DEdge(MEdge e, mapofVertices &vert, std::list<MTriangle*> &tri)
: _lastChange(-1), _qual(.0), _weight(REC2D_EDGE_BASE),
  _rv1(vert[e.getVertex(0)]), _rv2(vert[e.getVertex(1)])
{
  _rv1->add(this);
  _rv2->add(this);
}

Rec2DEdge::Rec2DEdge(Rec2DVertex *rv1, Rec2DVertex *rv2)
: _lastChange(-1), _qual(.0), _weight(REC2D_EDGE_BASE), _rv1(rv1), _rv2(rv2)
{
}

double Rec2DEdge::getQual()
{
  if (_lastChange < Recombine2D::getNumChange())
    _computeQual();
  return _qual;
}

void Rec2DEdge::_computeQual() //*
{
  static int i = 0; if (++i < 2) Msg::Warning("FIXME compute qual edge and update of vertex");
  //_rv1->update();
  //_rv2->update();
  double adimLength = _straightAdimLength();
  double alignment = _straightAlignment();
  if (adimLength > 1)
    adimLength = 1/adimLength;
  _qual = Recombine2D::edgeReward(adimLength, alignment);
  _lastChange = Recombine2D::getNumChange();
}

double Rec2DEdge::_straightAdimLength()
{
  double dx, dy, dz, **xyz;
  xyz = new double*[2];
  xyz[0] = new double[3];
  xyz[1] = new double[3];
  _rv1->getxyz(xyz[0]);
  _rv2->getxyz(xyz[1]);
  dx = xyz[0][0] - xyz[1][0];
  dy = xyz[0][1] - xyz[1][1];
  dz = xyz[0][2] - xyz[1][2];
  double length = sqrt(dx * dx + dy * dy + dz * dz);
  delete[] xyz[0];
  delete[] xyz[1];
  delete[] xyz;
  
  double lc1 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  double lc2 = (*Recombine2D::bgm())(_rv2->u(), _rv2->v(), .0);
  
  return length * (1/lc1 + 1/lc2) / 2;
}

double Rec2DEdge::_straightAlignment()
{
  double angle1 = Recombine2D::bgm()->getAngle(_rv1->u(), _rv1->v(), .0);
  double angle2 = Recombine2D::bgm()->getAngle(_rv1->u(), _rv1->v(), .0);
  double angleEdge = atan2(_rv1->u()-_rv2->u(), _rv1->v()-_rv2->v());
  
  double alpha1 = angleEdge - angle1;
  double alpha2 = angleEdge - angle2;
  crossField2d::normalizeAngle(alpha1);
  crossField2d::normalizeAngle(alpha2);
  alpha1 = 1 - 4 * std::min(alpha1, .5 * M_PI - alpha1) / M_PI;
  alpha2 = 1 - 4 * std::min(alpha2, .5 * M_PI - alpha2) / M_PI;
  
  double lc1 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  double lc2 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  
  return (alpha1/lc1 + alpha2/lc2) / (1/lc1 + 1/lc2);
}

bool lessRec2DAction::operator()(Rec2DAction *ra1, Rec2DAction *ra2) const
{
  return *ra1 < *ra2;
}

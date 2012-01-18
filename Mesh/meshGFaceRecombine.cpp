// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#define REC2D_EDGE_BASE 1
#define REC2D_EDGE_QUAD 1
#define REC2D_ALIGNMENT .5
#define REC2D_WAIT_TIME .01
#define REC2D_NUM_ACTIO 550

#include "meshGFaceRecombine.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGFaceOptimize.h"

#include "drawContext.h"
#include "FlGui.h"
#include "Context.h"
#include "OS.h"

// #define REC2D_SMOOTH
 #define REC2D_DRAW

Recombine2D *Recombine2D::_current = NULL;
bool Recombine2D::bo = 0;
double **Rec2DVertex::_qualVSnum = NULL;
double **Rec2DVertex::_gains = NULL;

int otherParity(int a) {
  if (a % 2)
    return a - 1;
  return a + 1;
}

/*
  TODO :
    - map -> myset<pair> (mapCornerVert, mapVert, mapEdge)
    - set -> myset
    (_vertices, _edges, _elements) -> set
    (_vertices, _edges, _elements) -> set
*/

void Recombine2D::associateParity(int pOld, int pNew)
{
  std::set<Rec2DVertex*>::iterator it = _current->_parities[pOld].begin();
  for (; it != _current->_parities[pOld].end(); ++it)
    (*it)->setParity(pNew);
  _current->_parities.erase(pOld);
  pOld = otherParity(pOld);
  pNew = otherParity(pNew);
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
    Msg::Warning("An instance of recombination is already in execution");
    return;
  }
  Recombine2D::_current = this;
  
  backgroundMesh::set(gf);
  _bgm = backgroundMesh::current();
  _numChange = 0;
  _numEdge = _numVert = 0;
  _valEdge = _valVert = .0;
  Rec2DVertex::initStaticTable();
  
    _tri = _gf->triangles;
  
  // Be able to compute geometrical angle at corners
  std::map<MVertex*, std::set<GEdge*> > mapCornerVert; // TOBE myset
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
  
  // Find all Vertices and edges and create the 'Rec2DElement'
  std::map<MVertex*, std::vector<MTriangle*> > mapVert; // TOBE myset
  std::map<MEdge, std::vector<MTriangle*>, Less_Edge> mapEdge; // TOBE myset
  for (unsigned int i = 0; i < gf->triangles.size(); ++i) {
    MTriangle *t = gf->triangles[i];
    Rec2DElement *el = new Rec2DElement(t);
    _elements[t] = el; // ISITTOKEEP keep only list of relem, map local
    for (int j = 0; j < 3; ++j) {
      mapVert[t->getVertex(j)].push_back(t);
      mapEdge[t->getEdge(j)].push_back(t);
    }
  }
  
  // Create the 'Rec2DVertex' and store iterator to vertices which have degree 4
  std::list<std::map<MVertex*, std::vector<MTriangle*> >::iterator> fourTri; // TOBE vector
  {
    mapofVertices::iterator itV2N = _vertices.begin();
    std::map<MVertex*, std::vector<MTriangle*> >::iterator itvert = mapVert.begin();
    for (; itvert != mapVert.end(); ++itvert) {
      MVertex *v = itvert->first;
      int onWhat = 1;
      if (mapCornerVert.find(v) != mapCornerVert.end())
        onWhat = -1;
      Rec2DVertex *rv = new Rec2DVertex(v, itvert->second, onWhat, mapCornerVert);
      itV2N = _vertices.insert(itV2N, std::make_pair(v,rv)); // ISITTOKEEP keep only list of rvert, map local
      if (itvert->second.size() == 4)
        fourTri.push_back(itvert);
    }
  }
  
  // Create the 'Rec2DEdge' and store boundary edges
  std::map<MVertex*, std::list<MEdge> > boundV2E; // TOBE myset
  {
    mapofEdges::iterator itE2E = _edges.begin();
    std::map<MEdge, std::vector<MTriangle*> >::iterator itedge = mapEdge.begin();
    for (; itedge != mapEdge.end(); ++itedge) {
      MEdge e = itedge->first;
      Rec2DEdge *re = new Rec2DEdge(e, _vertices, itedge->second);
      itE2E = _edges.insert(itE2E, std::make_pair(e,re));
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
    for (; itV2N != _vertices.end(); ++itV2N) {
      ++_numVert;
      _valVert += itV2N->second->getQual();
    }
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
    std::map<MEdge, std::vector<MTriangle*> >::iterator ite = mapEdge.begin();
    for (; ite != mapEdge.end(); ++ite)
    if (ite->second.size() == 2) {
      Rec2DTwoTri2Quad *q = new Rec2DTwoTri2Quad(_edges[ite->first], ite->second);
      //Rec2DCollapseTri *c = new Rec2DCollapseTri(_edges[ite->first], ite->second);
      _actions.push_back(q);
      //_actions.insert(c);
      std::vector<MTriangle*>::iterator it = ite->second.begin();
      _mea[*it].insert(q);
      //_mea[*it].insert(c);
      ++it;
      _mea[*it].insert(q);
      //_mea[*it].insert(c);
    }
  }
  
  // Create the 'Rec2DFourTri2Quad' and 'Rec2DCollapseTri'
  //{
  //  std::list<std::map<MVertex*, std::vector<MTriangle*> >::iterator>::iterator it4;
  //  for (it4 = fourTri.begin(); it4 != fourTri.end(); it4++) {
  //    Rec2DVertex *rv = _vertices[(*it4)->first];
  //    if (!rv->getIsOnBoundary()) {
  //      Rec2DFourTri2Quad *q = new Rec2DFourTri2Quad(rv, (*it4)->second);
  //      //Rec2DCollapseTri *c = new Rec2DCollapseTri(rv, (*it4)->second);
  //      _actions.push_back(q);
  //      //_actions.insert(c);
  //      std::vector<MTriangle*>::iterator it = (*it4)->second.begin();
  //      for (; it != (*it4)->second.end(); ++it) {
  //        _mea[*it].insert(q);
  //        //_mea[*it].insert(c);
  //      }
  //    }
  //  }
  //}
  
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
  //delete vertices, edges, elements, actions;
}

bool Recombine2D::recombine()
{
  Rec2DAction *nextAction;
  int i = -1;
  while (_actions.size() > 0 && ++i < REC2D_NUM_ACTIO) {
    double t = Cpu();
    nextAction = *std::max_element(_actions.begin(), _actions.end(),
                                   lessRec2DAction()                );
    nextAction->color(0, 0, 200);
    
    CTX::instance()->mesh.changed = (ENT_ALL);
    FlGui::instance()->check();
    drawContext::global()->draw();
    //if (nextAction->getReward() > 0) {
      if (_isAllQuad(nextAction))
        _choose(nextAction);
      else {
        nextAction->color(190, 0, 0);
        _removeReference(nextAction);
      }
    /*}
    else {
      nextAction->color(0, 100, 0);
      _removeReference(nextAction);
    }*/
    
    _gf->triangles = _tri;
    _gf->quadrangles = _quad;
#ifdef REC2D_DRAW
    //Msg::Info("%d", REC2D_NUM_ACTIO-i);
    //Msg::GetAnswer("Continue ?", 1, "no", "yes");
    CTX::instance()->mesh.changed = (ENT_ALL);
    FlGui::instance()->check();
    if (i%5 == 0)
    drawContext::global()->draw();
    while (Cpu()-t < REC2D_WAIT_TIME)
      FlGui::instance()->check();
#endif
#ifdef REC2D_SMOOTH
    laplaceSmoothing(_gf,1);
#endif

    std::map<int, std::set<Rec2DVertex*> >::iterator it = _parities.begin();
    for (; it != _parities.end(); ++it) {
      //Msg::Info("par %d, #%d", it->first, it->second.size());
    }
  }
//  
//  Msg::Info("State");
//  Msg::Info("-----");
//  Msg::Info("numEdge %d (%d), valEdge %g", _numEdge, _edges.size(), _valEdge);
//  Msg::Info("numVert %d (%d), valVert %g", _numVert, _vertices.size(), _valVert);
//  Msg::Info("global Value %g", Recombine2D::getGlobalValue(0,0,0,0));
//  Msg::Info("num action %d", _actions.size());
//  std::map<int, std::set<Rec2DVertex*> >::iterator it = _parities.begin();
//  for (; it != _parities.end(); ++it) {
//    Msg::Info("par %d, #%d", it->first, it->second.size());
//  }
//  mapofElementActions::iterator it2 = _mea.begin();
//  int a = 0;
//  for (; it2 != _mea.end(); ++it2) {
//    a += it2->second.size();
//  }
//  if (a > 0)
//    Msg::Info("%d elements in mapof elem to action, with average action %g", _mea.size(), (double)a/_mea.size());
//  Msg::Info(" ");
//  
  return 1;
}

bool Recombine2D::_isAllQuad(Rec2DAction *action)
{
  //Msg::Info("    ---new isAllQuad---");
  
  int p[4];
  action->getParities(p);
  
  if (p[0] < 0 && p[1] < 0 && p[2] < 0 && p[3] < 0) {
    Msg::Info("is isolated");
    return true;
  }
  
  if (action->isObsolete()) {
    Msg::Error("[Recombine2D] obsolete action (allQuad)");
    return false;
  }
  
  std::set<Rec2DVertex*> setRv;
  std::set<Rec2DElement*> neighbours, checked;
  for (int i = 0; i < Recombine2D::getNumVertAllQuad(); ++i) {
    if (Recombine2D::getVertAllQuad(i)->hasTriangle())
      Recombine2D::getVertAllQuad(i)->getElements(neighbours);
    else
      setRv.insert(Recombine2D::getVertAllQuad(i));
  }
  std::set<Rec2DVertex*>::iterator itit = setRv.begin();
  for (; itit != setRv.end(); ++itit)
    Recombine2D::removeVertAllQuad(*itit);
  setRv.clear();
  
  int min = 100, index;
  for (int i = 0; i < 4; ++i) {
    if (p[i] > -1 && min > p[i]) {
      min = p[i];
      index = i;
    }
  }
  //Msg::Info("Passsed through there, [%d %d %d %d] -> min %d", p[0], p[1], p[2], p[3], min);
  
  std::map<Rec2DVertex*, int> newParVert;
  std::map<Rec2DVertex*, int>::iterator it2;
  std::map<int, int> parAssoc; // first parity value become second parity value
  std::map<int, int>::iterator itassoc;
  
  for (int i = 0; i < 4; i += 2) {
    int par;
    if ((index/2) * 2 == i)
      par = min;
    else
      par = otherParity(min);
    for (int j = 0; j < 2; ++j) {
      if (p[i+j] == -1) {
        newParVert.insert(std::make_pair(action->getRVertex(i+j), par));
        action->getRVertex(i+j)->getElements(neighbours);
      }
      else if (p[i+j] != par) {
        if (parAssoc.find(p[i+j]) == parAssoc.end()) {
          parAssoc[p[i+j]] = par;
          parAssoc[otherParity(p[i+j])] = otherParity(par);
          _getElemToLook(p[i+j], neighbours);
          _getElemToLook(otherParity(p[i+j]), neighbours);
        }
      }
    }
  }
  
  while (neighbours.size() > 0) {
    //Msg::Info("num vert %d, num neigh %d", newParVert.size(), neighbours.size());
    
    std::set<Rec2DElement*>::iterator itel = neighbours.begin();
    Rec2DElement *element = *itel;
    if (element->isQuad()) {
      neighbours.erase(itel);
      continue;
    }
    
    Rec2DVertex *v[3];
    element->getVertices(v);
    int p[3];
    for (int i = 0; i < 3; ++i) {
      if ((it2 = newParVert.find(v[i])) != newParVert.end()) {
        p[i] = it2->second;
        while ((itassoc = parAssoc.find(p[i])) != parAssoc.end()) {
          p[i] = itassoc->second;
        }
        it2->second = p[i];
      }
      else {
        p[i] = v[i]->getParity();
        if ((itassoc = parAssoc.find(p[i])) != parAssoc.end()) {
          do
            p[i] = itassoc->second;
          while ((itassoc = parAssoc.find(p[i])) != parAssoc.end());
          newParVert[v[i]] = p[i];
        }
      }
    }
  //Msg::Info("tri %d [%d %d %d]", (*itel)->getNum(), p[0], p[1], p[2]);
    
    bool hasIdentical = false;
    for (int i = 0; i < 3; ++i) {
      if (p[i] > -1 && p[i] == p[(i+1)%3]) hasIdentical = true;
    }
    if (!hasIdentical) {
      neighbours.erase(itel);
      continue;
    }
    if (p[0] == p[1] && p[0] == p[2]) {
      Msg::Info("3 identical par");
      return false;
    }
  //Msg::Info("has identical");
    
    bool hasAction = false;
    std::map<Rec2DVertex*, std::vector<int> > suggestions;
    for (int i = 0; i < element->getNumActions(); ++i) {
      if (element->getAction(i)->whatImply(v, p, suggestions))
        hasAction = true;
    }
  //Msg::Info("suggest %d", suggestions.size());
    
    if (!hasAction) {
      Msg::Info("No action %d", (*itel)->getNum());
      return false;
    }
    
    std::map<Rec2DVertex*, std::vector<int> >::iterator itsug;
    itsug = suggestions.begin();
    for (; itsug != suggestions.end(); ++itsug) {
      int par = itsug->second.front();
      bool onlyOnePar = true;
      for (unsigned int i = 1; i < itsug->second.size(); ++i) {
        if (itsug->second[i] != par) {
          onlyOnePar = false;
          break;
        }
      }
      if (onlyOnePar) {
        if ((itassoc = parAssoc.find(par)) != parAssoc.end()) {
          do
            par = itassoc->second;
          while ((itassoc = parAssoc.find(par)) != parAssoc.end());
        }
        
        int oldPar;
        Rec2DVertex *v = itsug->first;
        
        if ((it2 = newParVert.find(v)) != newParVert.end()) {
          oldPar = it2->second;
          while ((itassoc = parAssoc.find(oldPar)) != parAssoc.end()) {
            oldPar = itassoc->second;
          }
          it2->second = oldPar;
        }
        else {
          oldPar = v->getParity();
          if ((itassoc = parAssoc.find(oldPar)) != parAssoc.end()) {
            do
              oldPar = itassoc->second;
            while ((itassoc = parAssoc.find(oldPar)) != parAssoc.end());
            newParVert[v] = oldPar;
          }
        }
        
        //Msg::Info("a %d, %d", par, oldPar);
        if (oldPar == -1) {
        //Msg::Info("b");
          newParVert[v] = par;
          v->getElements(neighbours);
        }
        else if ((par/2)*2 != (oldPar/2)*2) {
        //Msg::Info("c");
          if (oldPar < par) {
            int a = oldPar;
            oldPar = par;
            par = a;
          }
          parAssoc[oldPar] = par;
          parAssoc[otherParity(oldPar)] = otherParity(par);
          _getElemToLook(oldPar, neighbours);
          _getElemToLook(otherParity(oldPar), neighbours);
        }
        else if (par%2 != oldPar%2) {
        //Msg::Info("d");
          Msg::Info("not all quad");
          return false;
        }
      }
    }
    neighbours.erase(itel);
  }
  Msg::Info("all quad");
  return true;
}

void Recombine2D::_choose(Rec2DAction *action)
{
  action->apply(); //to check
  _removeIncompatible(action); //to check
  ++_numChange; //to check
}

void Recombine2D::_removeIncompatible(Rec2DAction *action) //to check
{
  std::set<Rec2DElement*> touchedTri;
  action->getRTriangles(touchedTri);
  std::set<Rec2DElement*>::iterator itTri;
  
  std::set<Rec2DAction*> incomp;
  {
    itTri = touchedTri.begin();
    for (; itTri != touchedTri.end(); ++itTri)
      (*itTri)->getActions(incomp);
  }
  
  //Msg::Warning("size %d", incomp.size());
  
  std::set<Rec2DAction*>::iterator itAction = incomp.begin();
  for (; itAction != incomp.end(); ++itAction) {
    delete *itAction;
  }
}

void Recombine2D::_removeReference(Rec2DAction *action)
{
  delete action;
}

//void Recombine2D::_getNeighbours(Rec2DAction *ra, std::set<Rec2DAction*> &actions)
//{
//  std::set<Rec2DElement*> touchedTri, neighbourTri;
//  ra->getRTriangles(touchedTri);
//  std::set<Rec2DElement*>::iterator itTri;
//  
//  {
//    itTri = touchedTri.begin();
//    for (; itTri != touchedTri.end(); ++itTri)
//      (*itTri)->getNeighbours(neighbourTri);
//    //itTri = touchedTri.begin();
//    //for (; itTri != touchedTri.end(); ++itTri)
//    //  neighbourTri.erase(*itTri);
//  }
//  
//  std::set<Rec2DAction*> incomp, neighbours;
//  {
//    itTri = touchedTri.begin();
//    for (; itTri != touchedTri.end(); ++itTri)
//      (*itTri)->getActions(neighbours);
//    itTri = neighbourTri.begin();
//    for (; itTri != neighbourTri.end(); ++itTri)
//      (*itTri)->getActions(neighbours);
//  }
//  
//  std::set<Rec2DAction*>::iterator itAction = incomp.begin();
//  for (; itAction != incomp.end(); ++itAction) {
//    bool b = neighbours.erase(*itAction);
//    if (!b)
//      Msg::Error("[Recombine2D] didn't found incomp action");
//  }
//  
//  for (itAction = neighbours.begin(); itAction != neighbours.end(); ++itAction) {
//    actions.insert(*itAction);
//  }
//}

void Recombine2D::_getElemToLook(int par, std::set<Rec2DElement*> &elem)
{
  std::set<Rec2DVertex*>::iterator it = _parities[par].begin();
  std::set<Rec2DVertex*>::iterator itend = _parities[par].end();
  for (; it != itend; ++it) {
    (*it)->getElements(elem);
  }
}


double Recombine2D::getGlobalValue(int numEdge, double valEdge,
                                   int numVert, double valVert )
{
  double a = (_current->_valVert + valVert) / (_current->_numVert + numVert);
  return (_current->_valEdge + valEdge) / (_current->_numEdge + numEdge) * a * a;
}

//Rec2DVertex* Recombine2D::getRVertex(MVertex *v)
//{
//  mapofVertices::iterator it = _current->_vertices.find(v);
//  if (it != _current->_vertices.end())
//    return it->second;
//  Msg::Error("[Recombine2D::getRVertex] vertex not found");
//  return NULL;
//}

Rec2DEdge* Recombine2D::getREdge(MEdge e)
{
  mapofEdges::iterator it = _current->_edges.find(e);
  if (it != _current->_edges.end())
    return it->second;
  Msg::Error("[Recombine2D::getREdge] edge not found");
  return NULL;
}

Rec2DElement* Recombine2D::getRElement(MElement *el)
{
  mapofElements::iterator it = _current->_elements.find(el);
  if (it != _current->_elements.end())
    return it->second;
  Msg::Error("[Recombine2D::getRElement] element not found");
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

void Recombine2D::remove(Rec2DElement *tri)
{
  Rec2DVertex *v[3];
  tri->getVertices(v);
  for (int i = 0; i < 3; ++i) {
    v[i]->remove(tri);
  }
  MTriangle *t = tri->getMTriangle();
  std::vector<MTriangle*>::iterator it = _current->_tri.begin();
  for (; it != _current->_tri.end(); ++it) {
    if (*it == t) {
      _current->_tri.erase(it);
      return;
    }
  }
  Msg::Error("[Recombine2D] triangle was not there");
}

void Recombine2D::remove(Rec2DAction *ra)
{
  setofRec2DAction::iterator itAction = _current->_actions.begin();
  bool b = false;
  while (itAction != _current->_actions.end()) {
    if (*itAction == ra) {
      _current->_actions.erase(itAction);
      b = true;
      break;
    }
    ++itAction;
  }
  if (!b)
    Msg::Error("[Recombine2D] action to delete not found");
}

void Recombine2D::add(MQuadrangle *quad)
{
  _current->_quad.push_back(quad);
}


/**  Rec2DAction  **/
/*******************/
bool lessRec2DAction::operator()(Rec2DAction *ra1, Rec2DAction *ra2) const
{
  return *ra1 < *ra2;
}


bool Rec2DAction::operator<(Rec2DAction &other)
{
  return getReward() < other.getReward(); 
}

MQuadrangle* Rec2DAction::_createQuad(std::vector<Rec2DEdge*> &boundEdge) const
{
  //Msg::Info("Imhere");
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
Rec2DTwoTri2Quad::Rec2DTwoTri2Quad(Rec2DEdge *re, std::vector<MTriangle*> &tri)
{
  int i;
  std::set<MEdge, Less_Edge> extEdges;
  {
    std::vector<MTriangle*>::iterator it = tri.begin();
    for (i = 0; it != tri.end() && i < 2; ++it, ++i) {
      _rtriangles[i] = Recombine2D::getRElement(*it);
      _rtriangles[i]->add(this);
      for (int j = 0; j < 3; ++j)
        extEdges.insert((*it)->getEdge(j));
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
  _vertices[2] = _rtriangles[0]->getOtherVertex(_vertices[0], _vertices[1]);
  _vertices[3] = _rtriangles[1]->getOtherVertex(_vertices[0], _vertices[1]);
  
  _computeGlobVal();
}

Rec2DTwoTri2Quad::~Rec2DTwoTri2Quad()
{
  _rtriangles[0]->remove(this);
  _rtriangles[1]->remove(this);
}

bool Rec2DTwoTri2Quad::isObsolete()
{
  int p[4];
  p[0] = _vertices[0]->getParity();
  p[1] = _vertices[1]->getParity();
  p[2] = _vertices[2]->getParity();
  p[3] = _vertices[3]->getParity();
  return Rec2DTwoTri2Quad::isObsolete(p);
}

bool Rec2DTwoTri2Quad::isObsolete(int *p)
{
  if (p[0]>-1 && p[1]>-1 && p[0]/2 == p[1]/2 && p[0]%2 != p[1]%2 ||
      p[2]>-1 && p[3]>-1 && p[2]/2 == p[3]/2 && p[2]%2 != p[3]%2 ||
      p[0]>-1 && (p[0] == p[2] || p[0] == p[3])                  ||
      p[1]>-1 && (p[1] == p[2] || p[1] == p[3])                    )
    return true;
  return false;
}

void Rec2DTwoTri2Quad::apply() //to check
{
  if (isObsolete()) {
    Msg::Error("[Rec2DTwoTri2Quad] Applying obsolet action");
    return;
  }
  
  int min = 100, index = -1;
  for (int i = 0; i < 4; ++i) {
    if (_vertices[i]->getParity() > -1 && min > _vertices[i]->getParity()) {
      min = _vertices[i]->getParity();
      index = i;
    }
  }
  if (index == -1) {
    int par = Recombine2D::highPar();
    _vertices[0]->setParity(par);
    _vertices[1]->setParity(par);
    _vertices[2]->setParity(par+1);
    _vertices[3]->setParity(par+1);
    Recombine2D::addVertAllQuad(_vertices[0]);
    Recombine2D::addVertAllQuad(_vertices[1]);
    Recombine2D::addVertAllQuad(_vertices[2]);
    Recombine2D::addVertAllQuad(_vertices[3]);
  }
  else {
    for (int i = 0; i < 4; i += 2) {
      int par;
      if ((index/2) * 2 == i)
        par = min;
      else
        par = otherParity(min);
      for (int j = 0; j < 2; ++j) {
        if (_vertices[i+j]->getParity() == -1) {
          _vertices[i+j]->setParity(par);
          Recombine2D::addVertAllQuad(_vertices[i+j]);
        }
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
  
  Recombine2D::remove(_rtriangles[0]); // FIXME not performant at all !!!
  Recombine2D::remove(_rtriangles[1]);
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
  _rtriangles[0]->getMElement()->setCol(col);
  _rtriangles[1]->getMElement()->setCol(col);
}


bool Rec2DTwoTri2Quad::whatImply(
                        Rec2DVertex **rv, int *par,
                        std::map<Rec2DVertex*, std::vector<int> > &suggestions)
{
  int num = 0, p[4];
  for (int i = 0; i < 4; ++i) {
    bool b = false;
    for (int j = 0; j < 3; ++j) {
      if (_vertices[i] == rv[j]) {
        ++num;
        p[i] = par[j];
        b = true;
      }
    }
    if (!b)
      p[i] = _vertices[i]->getParity();
  }
  if (num != 3)
    Msg::Error("[Rec2DTwoTri2Quad] %d corresponding vertices instead of 3", num);
  
  if (Rec2DTwoTri2Quad::isObsolete(p)) {
    //Msg::Info("  obsolete action");
    return false;
  }
  
  //Msg::Info("  [%d %d %d %d]", p[0], p[1], p[2], p[3]);
  
  int min = 100, index = -1;
  for (int i = 0; i < 4; ++i) {
    if (p[i] > -1 && min > p[i]) {
      min = p[i];
      index = i;
    }
  }
  if (index == -1) {
    Msg::Error("[Rec2DTwoTri2Quad] no parities");
    return false;
  }
  
  for (int i = 0; i < 4; i += 2) {
    int par;
    if ((index/2)*2 == i)
      par = min;
    else
      par = otherParity(min);
    for (int j = 0; j < 2; ++j) {
      if (p[i+j] != par)
        suggestions[_vertices[i+j]].push_back(par);
    }
  }
  //Msg::Info("  ok");
  return true;
}


///**  Rec2DFourTri2Quad  **/
///*************************/
//Rec2DFourTri2Quad::Rec2DFourTri2Quad(Rec2DVertex *rv, std::vector<MTriangle*> &tri)
//{
//  int i, j;
//  std::set<MEdge, Less_Edge> edges;
//  {
//    std::vector<MTriangle*>::iterator it = tri.begin();
//    for (i = 0; it != tri.end() && i < 4; ++it, ++i) {
//      for (j = 0; j < 3; ++j)
//        edges.insert((*it)->getEdge(j));
//      _rtriangles[i] = Recombine2D::getRElement(*it);
//      _rtriangles[i]->add(this);
//    }
//    if (it != tri.end() || i < 4)
//      Msg::Error("[Rec2DFourTri2Quad] Wrong number of triangles");
//  }
//  
//  std::set<MEdge>::iterator ite = edges.begin();
//  for (i = 0, j = 4; ite != edges.end() && (i < 4 || j < 8); ++ite) {
//    if ((*ite).getVertex(0) == rv->getMVertex() ||
//        (*ite).getVertex(1) == rv->getMVertex()   )
//      _edges[i++] = Recombine2D::getREdge(*ite);
//    else if (j < 8)
//      _edges[j++] = Recombine2D::getREdge(*ite);
//    else
//      Msg::Error("[Rec2DFourTri2Quad] Too much exterior edges");
//  }
//  if (edges.size() > 8 || ite != edges.end() || i < 4 || i > 4 || j < 8)
//    Msg::Error("[Rec2DFourTri2Quad] Wrong number of edges");
//  
//  _vertices[4] = rv;
//  // the 4 other must be in order : 2 non adjacent + last 2
//  _vertices[1] = _edges[4]->getRVertex(0);
//  _vertices[3] = _edges[4]->getRVertex(1);
//  for (int i = 5; i < 8; ++i) {
//    if (_edges[i]->getRVertex(0) == _vertices[1])
//      _vertices[0] = _edges[i]->getRVertex(1);
//    if (_edges[i]->getRVertex(1) == _vertices[1])
//      _vertices[0] = _edges[i]->getRVertex(0);
//    if (_edges[i]->getRVertex(0) == _vertices[3])
//      _vertices[2] = _edges[i]->getRVertex(1);
//    if (_edges[i]->getRVertex(1) == _vertices[3])
//      _vertices[2] = _edges[i]->getRVertex(0);
//  }
//  
//  _computeGlobVal();
//}
//
//Rec2DFourTri2Quad::~Rec2DFourTri2Quad()
//{
//  _rtriangles[0]->remove(this);
//  _rtriangles[1]->remove(this);
//  _rtriangles[2]->remove(this);
//  _rtriangles[3]->remove(this);
//}
//
//bool Rec2DFourTri2Quad::isObsolete()
//{
//  int p[4];
//  p[0] = _vertices[0]->getParity();
//  p[1] = _vertices[1]->getParity();
//  p[2] = _vertices[2]->getParity();
//  p[3] = _vertices[3]->getParity();
//  return Rec2DTwoTri2Quad::isObsolete(p);
//}
//
//void Rec2DFourTri2Quad::apply()
//{
//  double valEdge = 0;
//  for (int i = 0; i < 4; ++i)
//    valEdge -= REC2D_EDGE_BASE * _edges[i]->getQual();
//  for (int i = 4; i < 8; ++i)
//    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
//    
//  double valVert = - _vertices[4]->getQual();
//  for (int i = 0; i < 4; ++i)
//    valEdge += _vertices[i]->getGain(-1);
//  
//  Recombine2D::addNumEdge(4*REC2D_EDGE_QUAD - 4*REC2D_EDGE_BASE);
//  Recombine2D::addNumVert(-1);
//  Recombine2D::addValEdge(valEdge);
//  Recombine2D::addValVert(valVert);
//  
//  Recombine2D::remove(_rtriangles[0]); // FIXME not performant at all !!!
//  Recombine2D::remove(_rtriangles[1]);
//  Recombine2D::remove(_rtriangles[2]);
//  Recombine2D::remove(_rtriangles[3]);
//  std::vector<Rec2DEdge*> edges;
//  for (int i = 4; i < 8; ++i)
//    edges.push_back(_edges[i]);
//  Recombine2D::add(_createQuad(edges));
//  
//  for (int i = 0; i < 4; ++i) {
//    _edges[i]->getRVertex(0)->remove(_edges[i]);
//    _edges[i]->getRVertex(1)->remove(_edges[i]);
//    Recombine2D::remove(_edges[i]->getMEdge());
//    delete _edges[i];
//  }
//  Recombine2D::remove(_vertices[4]->getMVertex());
//  delete _vertices[4];
//}
//
//void Rec2DFourTri2Quad::getParities(int *par)
//{
//  par[0] = _vertices[0]->getParity();
//  par[1] = _vertices[1]->getParity();
//  par[2] = _vertices[2]->getParity();
//  par[3] = _vertices[3]->getParity();
//}
//
//void Rec2DFourTri2Quad::_computeGlobVal()
//{
//  double valEdge = 0;
//  for (int i = 0; i < 4; ++i)
//    valEdge -= REC2D_EDGE_BASE * _edges[i]->getQual();
//  for (int i = 4; i < 8; ++i)
//    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
//    
//  double valVert = - _vertices[4]->getQual();
//  for (int i = 0; i < 4; ++i)
//    valEdge += _vertices[i]->getGain(-1);
//  
//  _globValIfExecuted = Recombine2D::getGlobalValue(4*REC2D_EDGE_QUAD - 4*REC2D_EDGE_BASE,
//                                                   valEdge, -1, valVert      );
//  _lastUpdate = Recombine2D::getNumChange();
//}
//
//void Rec2DFourTri2Quad::color(int a, int b, int c)
//{
//  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
//  _rtriangles[0]->getMElement()->setCol(col);
//  _rtriangles[1]->getMElement()->setCol(col);
//  _rtriangles[2]->getMElement()->setCol(col);
//  _rtriangles[3]->getMElement()->setCol(col); 
//}
//
//
///**  Rec2DCollapseTri  **/
///*********************/
//Rec2DCollapseTri::Rec2DCollapseTri(Rec2DVertex *rv, std::vector<MTriangle*> &tri)
//{
//  int i;
//  std::set<MEdge, Less_Edge> extEdges;
//  {
//    std::vector<MTriangle*>::iterator it = tri.begin();
//    for (i = 0; it != tri.end() && i < 4; ++it, ++i) {
//      for (int j = 0; j < 3; ++j) {
//        if ((*it)->getEdge(j).getVertex(0) != rv->getMVertex() &&
//            (*it)->getEdge(j).getVertex(1) != rv->getMVertex()   )
//          extEdges.insert((*it)->getEdge(j));
//      }
//      _rtriangles[i] = Recombine2D::getRElement(*it);
//      _rtriangles[i]->add(this);
//    }
//    if (it != tri.end() || i < 4)
//      Msg::Error("[Rec2DFourTri2Quad] Wrong number of triangles");
//  }
//  
//  _vertices[4] = rv;
//  // the 4 other must be in order : 2 non adjacent + last 2
//  std::set<MEdge>::iterator ite = extEdges.begin();
//  Rec2DEdge *re = Recombine2D::getREdge(*ite);
//  _vertices[1] = re->getRVertex(0);
//  _vertices[3] = re->getRVertex(1);
//  ++ite;
//  for (; ite != extEdges.end(); ++ite) {
//    re = Recombine2D::getREdge(*ite);
//    if (re->getRVertex(0) == _vertices[1])
//      _vertices[0] = re->getRVertex(1);
//    if (re->getRVertex(1) == _vertices[1])
//      _vertices[0] = re->getRVertex(0);
//    if (re->getRVertex(0) == _vertices[3])
//      _vertices[2] = re->getRVertex(1);
//    if (re->getRVertex(1) == _vertices[3])
//      _vertices[2] = re->getRVertex(0);
//  }
//  
//  _computeGlobVal();
//}
//
//Rec2DCollapseTri::Rec2DCollapseTri(Rec2DEdge *re, std::vector<MTriangle*> &tri)
//: _edge(re)
//{
//  int i;
//  std::set<MEdge, Less_Edge> extEdges;
//  {
//    std::vector<MTriangle*>::iterator it = tri.begin();
//    for (i = 0; it != tri.end() && i < 2; ++it, ++i) {
//      for (int j = 0; j < 3; ++j)
//        extEdges.insert((*it)->getEdge(j));
//      _rtriangles[i] = Recombine2D::getRElement(*it);
//      _rtriangles[i]->add(this);
//    }
//    if (it != tri.end() || i < 2)
//      Msg::Error("[Rec2DTwoTri2Quad] Wrong number of triangles");
//    extEdges.erase(re->getMEdge());
//  }
//  _rtriangles[2] = _rtriangles[3] = NULL;
//  
//  _vertices[0] = re->getRVertex(0);
//  _vertices[1] = re->getRVertex(1);
//  _vertices[2] = _rtriangles[0]->getOtherVertex(_vertices[0], _vertices[1]);
//  _vertices[3] = _rtriangles[1]->getOtherVertex(_vertices[0], _vertices[1]);
//  _vertices[4] = NULL;
//  
//  _computeGlobVal();
//}
//
//Rec2DCollapseTri::~Rec2DCollapseTri()
//{
//  //_rtriangles[0]->remove(this);
//  //_rtriangles[1]->remove(this);
//}
//
//bool Rec2DCollapseTri::isObsolete()
//{
//  int p0 = _vertices[0]->getParity();
//  int p1 = _vertices[1]->getParity();
//  int p2 = _vertices[2]->getParity();
//  int p3 = _vertices[3]->getParity();
//  int b0 = _vertices[0]->getIsOnBoundary();
//  int b1 = _vertices[1]->getIsOnBoundary();
//  int b2 = _vertices[2]->getIsOnBoundary();
//  int b3 = _vertices[3]->getIsOnBoundary();
//  if ((b0 && b1) || (p0>-1 && p1>-1 && p0/2 == p1/2 && p0 % 2 != p1 % 2) &&
//      (b2 && b3) || (p2>-1 && p3>-1 && p2/2 == p3/2 && p2 % 2 != p3 % 2)   )
//    return true;
//  return false;
//}
//
//void Rec2DCollapseTri::apply()
//{
//  return;
//}
//
//void Rec2DCollapseTri::getParities(int *par)
//{
//  par[0] = _vertices[0]->getParity();
//  par[1] = _vertices[1]->getParity();
//  par[2] = _vertices[2]->getParity();
//  par[3] = _vertices[3]->getParity();
//}
//
//void Rec2DCollapseTri::_computeGlobVal()
//{
//  int b0 = _vertices[0]->getIsOnBoundary();
//  int b1 = _vertices[1]->getIsOnBoundary();
//  int b2 = _vertices[2]->getIsOnBoundary();
//  int b3 = _vertices[3]->getIsOnBoundary();
//  
//  std::map<Rec2DVertex*, int> neighbourVert;
//  std::set<Rec2DEdge*> neighbourEdge; 
//  if (!b0 || !b1) {
//    _vertices[0]->getNeighbours(neighbourVert, neighbourEdge);
//    _vertices[1]->getNeighbours(neighbourVert, neighbourEdge);
//    if (_vertices[4]) {
//      neighbourVert.erase(_vertices[4]);
//      _vertices[4]->getNeighbourEdges(neighbourEdge);
//    }
//    //else
//    //  neighbourEdge.insert(_edge);
//    
//    int numEdge = 0, numVert = 0;
//    double valEdge = .0, valVert = .0;
//    {
//      std::set<Rec2DEdge*>::iterator it = neighbourEdge.begin();
//      for (; it != neighbourEdge.end(); ++it) {
//        valEdge -= (*it)->getWeightedQual();
//        numEdge -= (*it)->getWeight();
//      }
//      valVert -= _vertices[0]->getQual();
//      valVert -= _vertices[1]->getQual();
//      if (_vertices[4]) {
//        valVert -= _vertices[4]->getQual();
//        numVert -= 1;
//        valVert += _vertices[2]->getGain(-2);
//        valVert += _vertices[3]->getGain(-2);
//      }
//      else {
//        valVert += _vertices[2]->getGain(-1);
//        valVert += _vertices[3]->getGain(-1);
//      }
//    }
//    if (b0)
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[0]);
//    else if (b1)
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[1]);
//    else
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert);
//    numVert -= 1;
//    
//    _globValIfExecuted =
//        Recombine2D::getGlobalValue(numEdge, valEdge, numVert, valVert);
//  }
//  else
//    _globValIfExecuted = -1.;
//  
//  
//  neighbourVert.clear();
//  neighbourEdge.clear();
//  if (!b2 || !b3) {
//    _vertices[2]->getNeighbours(neighbourVert, neighbourEdge);
//    _vertices[3]->getNeighbours(neighbourVert, neighbourEdge);
//    if (_vertices[4]) {
//      neighbourVert.erase(_vertices[4]);
//      _vertices[4]->getNeighbourEdges(neighbourEdge);
//    }
//    else
//      neighbourEdge.insert(_edge);
//    
//    int numEdge = 0, numVert = 0;
//    double valEdge = .0, valVert = .0;
//    {
//      std::set<Rec2DEdge*>::iterator it = neighbourEdge.begin();
//      for (; it != neighbourEdge.end(); ++it) {
//        valEdge -= (*it)->getWeightedQual();
//        numEdge -= (*it)->getWeight();
//      }
//      valVert -= _vertices[2]->getQual();
//      valVert -= _vertices[3]->getQual();
//      if (_vertices[4]) {
//        valVert -= _vertices[4]->getQual();
//        numVert -= 1;
//        valVert += _vertices[0]->getGain(-2);
//        valVert += _vertices[1]->getGain(-2);
//      }
//      else {
//        valVert += _vertices[0]->getGain(-2);
//        valVert += _vertices[1]->getGain(-2);
//      }
//    }
//    if (b2)
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[2]);
//    else if (b3)
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert, _vertices[3]);
//    else
//      _qualCavity(valVert, valEdge, numEdge, neighbourVert);
//    numVert -= 1;
//    
//    _globValIfExecuted2 =
//        Recombine2D::getGlobalValue(numEdge, valEdge, numVert, valVert);
//  }
//  else
//    _globValIfExecuted2 = -1.;
//    
//  _lastUpdate = Recombine2D::getNumChange();
//}
//
//void Rec2DCollapseTri::_qualCavity(double &valVert, double &valEdge,
//                                   int &numEdge,
//                                   std::map<Rec2DVertex*, int> &vert,
//                                   Rec2DVertex *imposedVert          )
//{
//  Recombine2D::bo = true;
//  std::map<Rec2DVertex*, int>::iterator it;
//  Rec2DVertex *rv = imposedVert;
//  if (rv == NULL) {
//    double u, v = u = .0;
//    it = vert.begin();
//    for (; it != vert.end(); ++it) {
//      u += it->first->u();
//      v += it->first->v();
//    }
//    u /= vert.size();
//    v /= vert.size();
//    
//    rv = new Rec2DVertex(u, v);
//  }
//  valVert = rv->getQual(vert.size());
//  it = vert.begin();
//  for (; it != vert.end(); ++it) {
//    Rec2DEdge re(rv, it->first);
//    valEdge += it->second * re.getQual();
//    numEdge += it->second;
//  }
//  if (imposedVert == NULL) {
//    rv->deleteMVertex();
//    delete rv;
//  }
//}
//
//void Rec2DCollapseTri::color(int a, int b, int c)
//{
//  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
//  _rtriangles[0]->getMElement()->setCol(col);
//  _rtriangles[1]->getMElement()->setCol(col);
//  if (_rtriangles[2]) {
//    _rtriangles[2]->getMElement()->setCol(col);
//    _rtriangles[3]->getMElement()->setCol(col);
//  }
//}
//
//
/**  Rec2DVertex  **/
/*******************/
Rec2DVertex::Rec2DVertex(MVertex *v, std::vector<MTriangle*> tri, int onWhat,
                         std::map<MVertex*, std::set<GEdge*> > gEdges)
: _v(v), _onWhat(onWhat), _parity(-1), _lastChange(-1), _numEl(tri.size())
{
  for (unsigned int i = 0; i < tri.size(); ++i)
    _elements.push_back(Recombine2D::getRElement(tri[i]));
  
  if (_onWhat == -1) {
    std::map<MVertex*, std::set<GEdge*> >::iterator it = gEdges.find(_v);
    if (it != gEdges.end())
      _angle = _computeAngle(_v, tri, it->second);
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
                                  std::vector<MTriangle*> &tri,
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
  std::vector<MTriangle*>::iterator it2 = tri.begin();
  for (; it2 != tri.end(); ++it2) {
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

bool Rec2DVertex::hasTriangle()
{
  bool b = false;
  for (int i = 0; i < _elements.size(); ++i)
    if (!_elements[i]->isQuad()) b = true;
  return b;
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

void Rec2DVertex::getElements(std::set<Rec2DElement*> &elem)
{
  for (unsigned int i = 0; i < _elements.size(); ++i)
    elem.insert(_elements[i]);
}


/**  Rec2DEdge  **/
/*****************/
Rec2DEdge::Rec2DEdge(MEdge e, mapofVertices &vert, std::vector<MTriangle*> &tri)
: _lastChange(-1), _qual(.0), _weight(REC2D_EDGE_BASE),
  _rv1(vert[e.getVertex(0)]), _rv2(vert[e.getVertex(1)])
{
  _rv1->add(this);
  _rv2->add(this);
  if (tri.size() == 2) {
    Rec2DElement *t0 = Recombine2D::getRElement(tri[0]);
    Rec2DElement *t1 = Recombine2D::getRElement(tri[1]);
    t0->add(this, t1);
    t1->add(this, t0);
  }
  else if (tri.size() == 1)
    Recombine2D::getRElement(tri[0])->add(this);
  else
    Msg::Error("[Rec2DEdge] Wrong number of triangles");
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
  //if (!_rv1->update() && !_rv2->update())
  //  return;
  static int i = 0; if (++i < 2) Msg::Warning("FIXME compute qual edge and update of vertex");
  //_rv1->update();
  //_rv2->update();
  double adimLength = _straightAdimLength();
  double alignment = _straightAlignment();
  if (adimLength > 1)
    adimLength = 1/adimLength;
  _qual = adimLength * ((1-REC2D_ALIGNMENT) + REC2D_ALIGNMENT * alignment);
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


/**  Rec2DElement  **/
/********************/
void Rec2DElement::add(Rec2DEdge *re)
{
  int i = -1;
  while (_redges[++i] && i < 4);
  if (_redges[i])
    Msg::Error("[Rec2DElement] too much edges");
  _redges[i] = re;
}

void Rec2DElement::add(Rec2DEdge *re, Rec2DElement *el)
{
  int i = -1;
  while (_redges[++i] && i < 4);
  if (_redges[i])
    Msg::Error("[Rec2DElement] too much edges");
  _redges[i] = re;
  _relements[i] = el;
}



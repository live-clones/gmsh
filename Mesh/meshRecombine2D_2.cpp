// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (amjohnen@gmail.com) adapted from meshGFaceOptimize
//

#include "meshRecombine2D.h"
#include "BackgroundMesh.h"
#include "GFace.h"
#include <cmath>
#include <FL/Fl.H>
#include "drawContext.h"
#include "FlGui.h"
#include "Context.h"
#include "OpenFile.h"//pas propre
#include "Field.h"
#include "OS.h"
#define HORIZ2 7

double **Rec2d_vertex::_Vvalues = NULL;
double **Rec2d_vertex::_Vbenefs = NULL;
int TrianglesUnion::_RECOMPUTE = 0;
int TrianglesUnion::_NumEdge = 0;
int TrianglesUnion::_NumVert = 0;
double TrianglesUnion::_ValEdge = .0;
double TrianglesUnion::_ValVert = .0;
int Recombine2D::ra = 0;

/*
  a faire :
  - modifier gain des edges
  - fonction retournant qualite
  - verifier la qualite
  - action supplementaire (faire classe de base)
  - Faire un super conteneur pour les actions
*/

Recombine2D::Recombine2D(GFace *gf)
: _horizon(0), _gf(gf), _benef(.0), _applied(true)
{
  Msg::Warning("[meshRecombine2D] Alignement computation ok uniquely for xy or yz plane mesh !");
  {
    FieldManager *fields = gf->model()->getFields();
    fields->newField(fields->newId(), "Param");
  }
  
  // be able to compute geometrical angle at corners
  std::map<MVertex*, std::set<GEdge*> > mapCornerVert;
  {
    std::list<GEdge*> listge = gf->edges();
    std::list<GEdge*>::iterator itge = listge.begin();
    
    for (; itge != listge.end(); itge++) {
      if ((*itge)->getBeginVertex()->getNumMeshElements() > 1 ||
          (*itge)->getEndVertex()->getNumMeshElements() > 1     )
        Msg::Warning("[meshRecombine2D] Why more than one MPoint, what should I do ?");
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)].insert(*itge);
      mapCornerVert[(*itge)->getEndVertex()->getMeshElement(0)->getVertex(0)].insert(*itge);
    }
  }
  
  // Find all Vertices and edges
  std::map<MVertex*, std::list<MTriangle*> > mapVert;
  std::map<MEdge, std::list<MTriangle*>, Less_Edge> mapEdge;
  for (unsigned int i = 0; i < gf->triangles.size(); i++) {
    MTriangle *t = gf->triangles[i];
    for (int j = 0; j < 3; j++) {
      mapVert[t->getVertex(j)].push_back(t);
      mapEdge[t->getEdge(j)].push_back(t);
    }
  }
  
  // Create the 'Rec2d_vertex' and store iterator to vertices which have degree 4
  std::map<MVertex*, std::list<MTriangle*> >::iterator itvert = mapVert.begin();
  std::map<MVertex*, Rec2d_vertex*> mapV2N;
  std::map<MVertex*, Rec2d_vertex*>::iterator itV2N = mapV2N.begin();
  std::list<std::map<MVertex*, std::list<MTriangle*> >::iterator> fourTri;
  for (; itvert != mapVert.end(); itvert++) {
    if (itvert->second.size() == 4 && itvert->first->onWhat()->dim() == 2)
      fourTri.push_back(itvert);
    Rec2d_vertex *n = new Rec2d_vertex(itvert->first, itvert->second, mapCornerVert);
    itV2N = mapV2N.insert(itV2N, std::make_pair(itvert->first,n));
    TrianglesUnion::_NumVert++;
    TrianglesUnion::_ValVert += n->getReward();
  }
  
  // store mesh size for better performance
  std::map<MVertex*,double> mapV2LcUV;
  
  // Create 'TrianglesUnion' for pattern of 4 triangles
/*
  +-----+
  |\   /|
  | \ / |
  |  +  |
  | / \ |
  |/   \|
  +-----+
*/
  std::list<std::map<MVertex*, std::list<MTriangle*> >::iterator>::iterator it4;
  int j = 0;
  for (it4 = fourTri.begin(); it4 != fourTri.end(); it4++) {
    std::list<MEdge> listEmbEdge;
    std::list<Rec2d_vertex*> listVert;
    {
      std::set<MVertex*> setVert;
      std::multiset<MEdge, Less_Edge> msetEdge;
      std::list<MTriangle*>::iterator itTri = (*it4)->second.begin();
      for (; itTri != (*it4)->second.end(); itTri++) {
        MVertex *vt;
        for (int i = 0; i < 3; i++) {
          msetEdge.insert((*itTri)->getEdge(i));
          vt = (*itTri)->getVertex(i);
          if (vt != (*it4)->first)
            setVert.insert(vt);
        }
      }
      std::multiset<MEdge>::iterator itEdge = msetEdge.begin();
      MEdge me = *(itEdge++);
      for (; itEdge != msetEdge.end(); itEdge++) {
        if (*itEdge == me)
          listEmbEdge.push_back(*itEdge);
        me = *itEdge;
      }
      std::set<MVertex*>::iterator itsVert = setVert.begin();
      for (; itsVert != setVert.end(); itsVert++)
        listVert.push_back(mapV2N[*itsVert]);
      listVert.push_back(mapV2N[(*it4)->first]);
    }
    Msg::Info("%d",++j);
    TrianglesUnion *tu = new TrianglesUnion(gf, (*it4)->second, listEmbEdge, listVert, mapV2LcUV);
    std::list<MTriangle*>::iterator itTri = (*it4)->second.begin();
    for (; itTri != (*it4)->second.end(); itTri++)
      _possibleActions[*itTri].insert(tu);
    _setQuads.push_back(tu);
  }
  
  // Create 'TrianglesUnion' for pattern of 2 triangles
/*
  +---+
  |\  |
  | \ |
  |  \|
  +---+
*/
  std::map<MEdge, std::list<MTriangle*> >::iterator itedge = mapEdge.begin();
  for (; itedge != mapEdge.end(); itedge++) {
    if (itedge->second.size() == 2) {
      std::list<MEdge> listEmbEdge;
      listEmbEdge.push_back(itedge->first);
      std::list<Rec2d_vertex*> listVert;
      listVert.push_back(mapV2N[itedge->first.getVertex(0)]);
      listVert.push_back(mapV2N[itedge->first.getVertex(1)]);
      TrianglesUnion *tu = new TrianglesUnion(gf, itedge->second, listEmbEdge, listVert, mapV2LcUV);
      _setQuads.push_back(tu);
      TrianglesUnion::_NumEdge++;
      TrianglesUnion::_ValEdge += tu->getEdgeValue();
      std::list<MTriangle*>::iterator itTri = itedge->second.begin();
      for (; itTri != itedge->second.end(); itTri++)
        _possibleActions[*itTri].insert(tu);
    }
    else
      ;//Msg::Info("[bord] %d", itedge->second.size());
  }
  TrianglesUnion::addRec();
  //_setQuads.sort(lessTriUnion());
  
  _recombine(true);
  _applied = false;
}


void Recombine2D::_recombine(bool a)
{
  SetBoundingBox();
  
  int i = 0;
  std::list<TrianglesUnion*> vectTu;
  
  while (!_setQuads.empty() && i < 2000) {
    TrianglesUnion *tu;
    if (_lastQuad.empty()) {
      if (vectTu.size() < 2)
        tu = *std::max_element(_setQuads.begin(), _setQuads.end(), lessTriUnion());
      else {
        vectTu.pop_front();
        //tu = *std::max_element(vectTu.begin(),vectTu.end(), lessTriUnion());
        tu = *vectTu.begin();
      }
      vectTu.clear();
      vectTu.insert(vectTu.begin(), tu);
      
            Msg::Info("------------------ %d", _setQuads.size());
      _lookAhead(vectTu, HORIZ2);
    }
    else {
      tu = *_lastQuad.begin();
      vectTu.clear();
      vectTu.insert(vectTu.begin(), tu);
      std::set<MTriangle*> touched;
      for (int i = 0; i < tu->getNumTriangles(); i++) {
        touched.insert(tu->getTriangle(i));
      }
      std::list<TrianglesUnion*>::iterator it = _lastQuad.begin();
      while (it != _lastQuad.end()) {
        bool toBeErased = false;
        for (int i = 0; i < (*it)->getNumTriangles(); i++) {
          if (touched.find((*it)->getTriangle(i)) != touched.end())
            toBeErased = true;
        }
        if (toBeErased)
          _lastQuad.erase(it++);
        else
          ++it;
      }
      //_lastQuad.erase(_lastQuad.begin());
    }
    tu = *vectTu.begin();
    tu->select();
    _quads.push_back(tu->createQuad());
    _removeImpossible(tu);
    { // draw Mesh
      Msg::Info("Expected return %lf", tu->getReturn());
      _applied = false;
      apply(true);
      _applied = false;
      CTX::instance()->mesh.changed = (ENT_ALL);
      //drawContext::global()->draw();
      FlGui::instance()->check();
      drawContext::global()->draw();
      double t = Cpu();
      while (Cpu() - t < .0001);
      if (i % 1000 == 0)
      if (!Msg::GetAnswer("Continue ?", 1, "no", "yes"))
        Msg::Info("I continue anyway :p");
    }
    
    ++i;
  }
  Msg::Info("Done %d (%d)", i, _pairs.size());
}

void printIt(std::vector<list_actions::iterator> &vIt, int size)
{
  switch (size) {
    case 3 :
      Msg::Info("--Iterators : %d , %d , %d", vIt[0].getPos(), vIt[1].getPos(), vIt[2].getPos());
      break;
    case 2 :
      Msg::Info("--Iterators : %d , %d", vIt[0].getPos(), vIt[1].getPos());
      break;
    case 1 :
      Msg::Info("--Iterators : %d", vIt[0].getPos());
      break;
    default :
      break;
  }
}

void Recombine2D::_lookAhead(std::list<TrianglesUnion*> &candidate, int horiz)
{
  if (horiz < 1)
    horiz = 1;
  _lessActions.clear();
  
  double maxReturn = .0;
  //TrianglesUnion *bestAction;
  int numbers[2] = {0, 0}; // number of embedded verts & edges
  double values[2] = {.0, .0}; // embedded vert & edge values
  std::set<MTriangle*> setTri;
  std::map<Rec2d_vertex*, int> modifiedVert;
  std::vector<list_actions::iterator> vecIt(horiz);
  std::vector<std::pair<TrianglesUnion*, int> > bestSequence;
  
  list_actions la(horiz);
  {
    setTriUnion candidates;
    _getIncompatibles(*candidate.begin(), candidates);
    la.add(candidates);
  }
  
  vecIt[0] = la.begin();
  (*vecIt[0])->addTri(setTri);
  (*vecIt[0])->addInfluence(numbers, values, modifiedVert);
  _addNeighbors(horiz, vecIt, 0, &la);
  
  int current = 1;
  int num=0;
  
  while (current > 0) {
    bool best = false;
    // set first acceptable action for each step
    while (current < horiz && vecIt[current-1] != la.end()) {
      vecIt[current] = vecIt[current-1];
      while (++vecIt[current] != la.end() && (*vecIt[current])->isIn(setTri));
      if (vecIt[current] != la.end()) {
        (*vecIt[current])->addTri(setTri);
        (*vecIt[current])->addInfluence(numbers, values, modifiedVert);
        _addNeighbors(horiz, vecIt, current, &la);
      }
      ++current;
    }

    { // color
      for (int i = 1; i < current &&  vecIt[i] != la.end(); ++i) {
        TrianglesUnion *tu = *vecIt[i];
        int pos = vecIt[i].getPos();
        double frac = (double)pos / (double)(horiz-1);
        unsigned int col;
        //la.sizes();
        //Msg::Info("%d / %d -> %d", pos, horiz, (int)(200.*frac));
        col = CTX::instance()->packColor(50 - (int)(25.*frac), 200 - (int)(25.*frac), (int)(200.*frac), 255);
        for (int j = 0; j < tu->getNumTriangles(); ++j) {
          tu->getTriangle(j)->setCol(col);
        }
      }
    }
    
    double expectedReturn = TrianglesUnion::computeReturn(numbers, values, modifiedVert);
    if (maxReturn < expectedReturn) {
      int sizeSequence = current;
      if (vecIt[sizeSequence - 1] == la.end())
        --sizeSequence;
      expectedReturn -= .1 * _checkIsolatedTri(vecIt, sizeSequence, setTri);
      if (maxReturn < expectedReturn) {
        maxReturn = expectedReturn;
        //bestAction = *vecIt[0];
        bestSequence.resize(sizeSequence);
        for (int i = 0; i < sizeSequence; ++i)
          bestSequence[i] = std::make_pair(*vecIt[i], vecIt[i].getPos());
        { //color
          best = true;
          TrianglesUnion *tu = *vecIt[0];
          unsigned int col;
          col = CTX::instance()->packColor(190, 0, 190, 255);
          for (int j = 0; j < tu->getNumTriangles(); ++j) {
            tu->getTriangle(j)->setCol(col);
          }
        }
      }
    }
    else { //color
      TrianglesUnion *tu = *vecIt[0];
      unsigned int col;
      col = CTX::instance()->packColor(190, 0, 0, 255);
      for (int j = 0; j < tu->getNumTriangles(); ++j) {
        tu->getTriangle(j)->setCol(col);
      }
    }
    
    if (true || best) { // draw mesh
      apply(false);
      CTX::instance()->mesh.changed = (ENT_ALL);
      FlGui::instance()->check();
      drawContext::global()->draw();
      double t = Cpu();
      while (Cpu() - t < .0001);
      //if (i % 1 == 0)
      if (/*false && best &&*/ !Msg::GetAnswer("Continue ?", 1, "no", "yes"))
        Msg::Info("I continue anyway :p");
      best = false;
    }
    
    { // decolor
      for (int i = 0; i < current &&  vecIt[i] != la.end(); ++i) {
        TrianglesUnion *tu = *vecIt[i];
        int pos = vecIt[i].getPos();
        double frac = (double)pos / (double)horiz;
        unsigned int col;
        col = CTX::instance()->packColor(255, 255, 0, 255);
        for (int j = 0; j < tu->getNumTriangles(); ++j) {
          tu->getTriangle(j)->setCol(col);
        }
      }
    }
    
    if (vecIt[current-1] != la.end() || --current > 0) {
      do {
        (*vecIt[current-1])->removeTri(setTri);
        (*vecIt[current-1])->removeInfluence(numbers, values, modifiedVert);
        _removeNeighbors(horiz, current - 1, &la);
        while (++vecIt[current-1] != la.end() && (*vecIt[current-1])->isIn(setTri));
      } while (vecIt[current-1] == la.end() && --current > 0);
      if (current > 0) {
        (*vecIt[current-1])->addTri(setTri);
        (*vecIt[current-1])->addInfluence(numbers, values, modifiedVert);
        _addNeighbors(horiz, vecIt, current - 1, &la);
      }
    }
  }
  
  { // color
    for (int i = 1; i < bestSequence.size(); ++i) {
      TrianglesUnion *tu = bestSequence[i].first;
      unsigned int col = CTX::instance()->packColor(50, 200, 0, 255);
      for (int j = 0; j < tu->getNumTriangles(); ++j) {
        tu->getTriangle(j)->setCol(col);
      }
    }
  }

  candidate.clear();
  for (int i = 0; i < bestSequence.size(); ++i) {
    candidate.insert(candidate.end(), bestSequence[i].first);
  }
}

void Recombine2D::_getIncompatibles(const TrianglesUnion *tu, setTriUnion &set)
{
  for (int i = 0; i < tu->getNumTriangles(); i++) {
    mapTriUnion::iterator it = _lessActions.find(tu->getTriangle(i));
    if (it == _lessActions.end()) {
      it = _possibleActions.find(tu->getTriangle(i));
      if (it == _possibleActions.end()) {
        Msg::Error("[Rec2D] error no triangle !, stopping with partially filled set");
      }
      _lessActions.insert(*it);
    }
    setTriUnion::iterator it2 = it->second.begin();
    for (; it2 != it->second.end(); ++it2) {
      set.insert(*it2);
    }
  }
}

void Recombine2D::_getNeighbors(const TrianglesUnion *tu, setTriUnion &set)
{
  setTriUnion incomp;
  setTriUnion neighbors;
  _getIncompatibles(tu, incomp);
  setTriUnion::iterator it = incomp.begin();
  for (; it != incomp.end(); ++it)
    _getIncompatibles(*it, neighbors);
  it = incomp.begin();
  for (; it != incomp.end(); ++it)
    neighbors.erase(*it);
  it = neighbors.begin();
  for (; it != neighbors.end(); ++it)
    set.insert(*it);
}

void Recombine2D::_addNeighbors(int horiz, std::vector<list_actions::iterator> &vecIt, int current, list_actions *la)
{
  if (current < horiz - 1 && current > -1) {
    //Msg::Info("+ra %d", ++ra);
    setTriUnion neighbors;
    _getNeighbors(*vecIt[current], neighbors);
    la->add(neighbors);
  }
}

void Recombine2D::_removeNeighbors(int horiz, int current, list_actions *la)
{
  if (current < horiz - 1 && current > -1) {
    //Msg::Info("-ra %d", --ra);
    la->pop_back();
  }
}


int Recombine2D::_checkIsolatedTri(std::vector<list_actions::iterator> &vecIt, int size, std::set<MTriangle*> &seqTri)
{
  setTriUnion setTu;
  for (int i = 0; i < size; ++i) {
    _getIncompatibles(*vecIt[i], setTu);
  }
  
  std::set<MTriangle*> setBoundaryTri;
  setTriUnion::iterator it = setTu.begin();
  for (; it != setTu.end(); ++it) {
    for (int i = 0; i < (*it)->getNumTriangles(); i++)
    if (seqTri.find((*it)->getTriangle(i)) == seqTri.end())
      setBoundaryTri.insert((*it)->getTriangle(i));
  }
  
  int num = 0;
  std::set<MTriangle*>::iterator itTri = setBoundaryTri.begin();
  for (; itTri != setBoundaryTri.end(); ++itTri) {
    mapTriUnion::iterator it1 = _lessActions.find(*itTri);
    if (it1 == _lessActions.end()) {
      it1 = _possibleActions.find(*itTri);
      if (it1 == _possibleActions.end()) {
        Msg::Error("[Rec2D] error no triangle !, stopping with partially filled set");
      }
      _lessActions.insert(*it1);
    }
    int numPossibleRecombinations = 0;
    setTriUnion::iterator it2 = it1->second.begin();
    for (; it2 != it1->second.end(); ++it2)
    if (setTu.find(*it2) == setTu.end())
      ++numPossibleRecombinations;
    if (!numPossibleRecombinations)
      ++num;
  }
  return num;
}

MQuadrangle *TrianglesUnion::createQuad() const
{
  std::list<MEdge> listBoundEdge;
  {
    std::multiset<MEdge, Less_Edge> msetEdge;
    for (int i = 0; i < _numTri; i++) {
      MTriangle *t = _triangles[i];
      for (int i = 0; i < 3; i++) {
        msetEdge.insert(t->getEdge(i));
      }
    }
    std::multiset<MEdge>::iterator itEdge = msetEdge.begin();
    MEdge me = *(itEdge++);
    bool precWasSame = false;
    for (; itEdge != msetEdge.end(); itEdge++) {
      if (*itEdge == me)
        precWasSame = true;
      else if (precWasSame)
        precWasSame = false;
      else
        listBoundEdge.push_back(me);
      me = *itEdge;
    }
    if (!precWasSame)
      listBoundEdge.push_back(me);
  }
  if (listBoundEdge.size() != 4)
    Msg::Warning("[meshRecombine2D] Not 4 edges !");
  
  MVertex *v1, *v2, *v3, *v4;
  v1 = listBoundEdge.begin()->getMinVertex();
  v2 = listBoundEdge.begin()->getMaxVertex();
  std::list<MEdge>::iterator it = listBoundEdge.begin();
  for (it++; it != listBoundEdge.end(); it++) {
    if (v2 == it->getMinVertex()) {
      v3 = it->getMaxVertex();
      listBoundEdge.erase(it);
      break;
    }
    if (v2 == it->getMaxVertex()) {
      v3 = it->getMinVertex();
      listBoundEdge.erase(it);
      break;
    }
  }
  for (it = listBoundEdge.begin(); it != listBoundEdge.end(); it++) {
    if (v3 == it->getMinVertex()) {
      v4 = it->getMaxVertex();
      break;
    }
    if (v3 == it->getMaxVertex()) {
      v4 = it->getMinVertex();
      break;
    }
  }
  
  return new MQuadrangle(v1, v2, v3, v4);
}


int Recombine2D::apply(bool a)
{
  //Msg::Info("(%d, %d, %d)", _quads.size(), _gf->triangles.size(), _isolated.size());
  if (a) {
    std::vector<MTriangle*> triangles2;
    for (int i = 0; i < _gf->triangles.size(); i++) {
      if (_isolated.find(_gf->triangles[i]) != _isolated.end())
        delete _gf->triangles[i];
      else
        triangles2.push_back(_gf->triangles[i]);
    }
    _gf->triangles = triangles2;
    _gf->quadrangles = _quads;
    _isolated.clear();
  }
  
  _applied = true;
  return 1;
}

void Recombine2D::_removeImpossible(TrianglesUnion *tu)
{
  for (int i = 0; i < tu->getNumTriangles(); i++) {
    _isolated.insert(tu->getTriangle(i));
  }// for test
  
  std::set<MTriangle*> touched;
  for (int i = 0; i < tu->getNumTriangles(); i++) {
    touched.insert(tu->getTriangle(i));
  }
  
  setTriUnion incomp;
  std::set<MTriangle*>::iterator itTri = touched.begin();
  for (; itTri != touched.end(); ++itTri) {
    mapTriUnion::iterator it = _possibleActions.find(*itTri);
    if (it != _possibleActions.end()) {
      setTriUnion::iterator it2 = it->second.begin();
      for (; it2 != it->second.end(); ++it2)
        incomp.insert(*it2);
    }
  }
  
  setTriUnion::iterator itTu = incomp.begin();
  for (; itTu != incomp.end(); ++itTu) {
    for (int i = 0; i < (*itTu)->getNumTriangles(); i++) {
      mapTriUnion::iterator it4 = _possibleActions.find((*itTu)->getTriangle(i));
      it4->second.erase(*itTu);
      TrianglesUnion *tu;
      if (touched.find(it4->first) == touched.end())
      switch (it4->second.size()) {
        case 1 :
          _lastQuad.insert(_lastQuad.begin(), *it4->second.begin());
          tu = *it4->second.begin();
          unsigned int col;
          col = CTX::instance()->packColor(0, 0, 0, 0);
          for (int j = 0; j < tu->getNumTriangles(); ++j)
            tu->getTriangle(j)->setCol(col);
          break;
        case 0 :
        default :
          break;
      }
    }
    //_setQuads.erase(*itTu); //marche pas avec list
  } 
  
  std::list<TrianglesUnion*>::iterator it = _setQuads.begin();
  while (it != _setQuads.end()) {
    if (incomp.find(*it) != incomp.end())
      it = _setQuads.erase(it); // replacement de _setQuads.erase(*itTu);
    else
      ++it;
  }
  
  for (int i = 0; i < tu->getNumTriangles(); i++) {
    _possibleActions.erase(tu->getTriangle(i));
  }
  
  /*std::list<TrianglesUnion*>::iterator it = _setQuads.begin();
  while (it != _setQuads.end()) {
    bool b = false;
    for (int i = 0; i < (*it)->getNumTriangles(); i++) {
      if (touched.find((*it)->getTriangle(i)) != touched.end())
        b = true;
    }
    if (b)
      it = _setQuads.erase(it);
    else
      ++it;
  }*/
}

Rec2d_vertex::Rec2d_vertex(MVertex *v,
                           std::list<MTriangle*> &setTri,
                           std::map<MVertex*, std::set<GEdge*> > &mapVert)
: _numEl(setTri.size()), _angle(.0)
{
  _onWhat = v->onWhat()->dim() - 1;
  
  if (_onWhat < 0) {
    std::map<MVertex*, std::set<GEdge*> >::iterator it = mapVert.find(v);
    if (it != mapVert.end()) {
      _angle = _computeAngle(v, setTri, it->second);
    }
    else {
      Msg::Warning("[meshRecombine2D] Can't compute corner angle, setting angle to pi/2");
      _angle = M_PI / 2.;
    }
  }
  
  if (_Vvalues == NULL)
    _initStaticTable();
}

void Rec2d_vertex::_initStaticTable()
{
  if (_Vvalues == NULL) {
    // _Vvalues[onWhat][nEl]; onWhat={0:edge,1:face} / nEl=_numEl-1
    // _Vbenefs[onWhat][nEl]; onWhat={0:edge,1:face} / nEl=_numEl-1 (benef of adding an element)
    int nE = 5, nF = 10;
    
    _Vvalues = new double*[2];
    _Vvalues[0] = new double[nE];
    for (int i = 0; i < nE; i++)
      _Vvalues[0][i] = 1. - fabs(2. / (i+1) - 1.);
    _Vvalues[1] = new double[nF];
    for (int i = 0; i < nF; i++)
      _Vvalues[1][i] = 1. - fabs(4. / (i+1) - 1.);
      
    _Vbenefs = new double*[2];
    _Vbenefs[0] = new double[nE-1];
    for (int i = 0; i < nE-1; i++)
      _Vbenefs[0][i] = _Vvalues[0][i+1] - _Vvalues[0][i];
    _Vbenefs[1] = new double[nF-1];
    for (int i = 0; i < nF-1; i++)
      _Vbenefs[1][i] = _Vvalues[1][i+1] - _Vvalues[1][i];
  }
}


double Rec2d_vertex::_computeAngle(MVertex *v,
                                   std::list<MTriangle*> &setTri,
                                   std::set<GEdge*> &setEdge)
  {
  if (setEdge.size() != 2) {
    Msg::Warning("[meshRecombine2D] Wrong number of edge : %d, returning pi/2", setEdge.size());
    return M_PI / 2.;
  }
  const double prec = 100.;
  
  SVector3 vectv = SVector3(v->x(), v->y(), v->z());
  SVector3 firstDer0, firstDer1;
  
  std::set<GEdge*>::iterator it = setEdge.begin();
  for (int k = 0; k < 2; it++, k++) {
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
      Msg::Warning("[meshRecombine2D] Bad precision, returning pi/2");
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
  std::list<MTriangle*>::iterator it2 = setTri.begin();
  for (; it2 != setTri.end(); it2++) {
    MTriangle *t = *it2;
    int k = 0;
    while (t->getVertex(k) != v && k < 3)
      k++;
    if (k == 3) {
      Msg::Warning("[meshRecombine2D] Wrong triangle, returning pi/2");
      return M_PI / 2.;
    }
    angleMesh += angle3Vertices(t->getVertex((k+1)%3), v, t->getVertex((k+2)%3));
  }
  
  if (angleMesh < M_PI)
    return angle1;
  return angle2;
}

double Rec2d_vertex::getReward()
{
  if (_onWhat > -1)
    return _Vvalues[_onWhat][_numEl-1];
  else
    return 1. - fabs(2. / M_PI * _angle / _numEl - 1.);
}

double Rec2d_vertex::getReward(int n)
{
  if (n == 0) return .0;
  if (_onWhat > -1) {
    switch (n) {
      case 1 :
        return _Vbenefs[_onWhat][_numEl-1];
      case -1 :
        return - _Vbenefs[_onWhat][_numEl-2];
      default :
        return _Vvalues[_onWhat][_numEl-1+n] - _Vvalues[_onWhat][_numEl-1];
    }
  }
  else
    return fabs(2./M_PI*_angle/_numEl - 1.) - fabs(2./M_PI*_angle/(_numEl + n) - 1.);
}


TrianglesUnion::TrianglesUnion(GFace *gf,
                               std::list<MTriangle*> &t,
                               std::list<MEdge> &e,
                               std::list<Rec2d_vertex*> &v,
                               std::map<MVertex*,double> &v2lcUV)
{
  _numTri = t.size();
  _numEmbEdge = e.size();
  _numBoundVert = v.size() == 2 ? 2 : 4;
  _numEmbVert = v.size() - _numBoundVert;
  _globValIfExecuted = _embEdgeValue = _embVertValue = .0;
  
  _triangles = new MTriangle*[_numTri];
  std::list<MTriangle*>::iterator itt = t.begin();
  for (int k = 0; itt != t.end(); itt++, k++)
    _triangles[k] = *itt;
  
  std::list<MEdge>::iterator ite = e.begin();
  for (; ite != e.end(); ite++) {
    double sumlc = .0, u[2], v[2];
    MVertex *vert[2];
    for (int i = 0; i < 2; i++) {
      vert[i] = ite->getVertex(i);
      vert[i]->getParameter(0, u[i]);
      vert[i]->getParameter(1, v[i]); // Warning : should check if vertex on face or on edge
      std::map<MVertex*,double>::iterator itlc;
      if ((itlc = v2lcUV.find(vert[i])) == v2lcUV.end()) {
        sumlc += v2lcUV[vert[i]] = BGM_MeshSize(gf, u[i], v[i], vert[i]->x(), vert[i]->y(), vert[i]->z());
      }
      else
        sumlc += itlc->second;
    }
    
    sumlc = .2; // FIXME BGM_MeshSize returns wrong meshsize

    double length = _computeEdgeLength(gf, vert, u, v, 0);
    double a = .0;
    _embEdgeValue += length / sumlc * (a + (2-a) *_computeAlignment(*ite, t));
    //Msg::Info("Edge a : {%lf/.1 = %lf <-> %lf} => %lf", length, 2 * length / sumlc, 1 - _computeAlignment(*ite, t),length / sumlc * (1 + _computeAlignment(*ite, t)));
  }
  
  _vertices = new Rec2d_vertex*[_numBoundVert];
  std::list<Rec2d_vertex*>::iterator itv = v.begin();
  for (int k = 0; itv != v.end() && k < _numBoundVert; itv++, k++)
    _vertices[k] = *itv;
  for (_numEmbVert = 0; itv != v.end(); itv++, _numEmbVert++)
    _embVertValue += (*itv)->getReward();
  
  _computation = _RECOMPUTE;
}


double TrianglesUnion::_computeEdgeLength(GFace *gf, MVertex **vert,
                                          double *u, double *v, int n)
{
  double dx, dy, dz, l = .0;
  if (n == 0) {
    dx = vert[1]->x() - vert[0]->x();
    dy = vert[1]->y() - vert[0]->y();
    dz = vert[1]->z() - vert[0]->z();
    l = sqrt(dx * dx + dy * dy + dz * dz);
  }
  else if (n == 1) {
    double edgeCenter[2] ={(u[0] + u[1]) * .5, (v[0] + v[1]) * .5};
    GPoint GP = gf->point (edgeCenter[0], edgeCenter[1]);
    dx = vert[1]->x() - GP.x();
    dy = vert[1]->y() - GP.y();
    dz = vert[1]->z() - GP.z();
    l += sqrt(dx * dx + dy * dy + dz * dz);
    dx = vert[0]->x() - GP.x();
    dy = vert[0]->y() - GP.y();
    dz = vert[0]->z() - GP.z();
    l += sqrt(dx * dx + dy * dy + dz * dz);
  }
  else {
    Msg::Warning("[meshRecombine2D] edge length computation not implemented for n=%d, returning 0", n);
    return .0;
  }
  return l;
}
double TrianglesUnion::_computeAlignment(MEdge &e, std::list<MTriangle*> &lt)
{
  std::list<MTriangle*>::iterator itlt = lt.begin();
  if (lt.size() == 2)
    return Temporary::compute_alignment(e, *itlt, *(++itlt));
  
  MVertex *v0 = e.getVertex(0);
  MVertex *v1 = e.getVertex(1);
  MTriangle *tris[2];
  int k = 0;
  for (; itlt != lt.end(); itlt++) {
    MTriangle *t = *itlt;
    if ((t->getVertex(0) == v0 || t->getVertex(1) == v0 || t->getVertex(2) == v0) &&
        (t->getVertex(0) == v1 || t->getVertex(1) == v1 || t->getVertex(2) == v1)   )
      tris[k++] = t;
  }
  if (k < 2 || k > 2) {
    Msg::Warning("[meshRecombine2D] error in alignment computation, returning 0");
    return .0;
  }
  return Temporary::compute_alignment(e, tris[0], tris[1]);
}
void TrianglesUnion::_update()
{
  if (_computation >= _RECOMPUTE)
    return;
  double alpha = _ValVert - _embVertValue;
  for (int i = 0; i < _numBoundVert; i++) {
    alpha += _vertices[i]->getReward(-1);
  }
  alpha /= _NumVert - _numEmbVert;
  double beta = (_ValEdge - _embEdgeValue) / (_NumEdge - _numEmbEdge);
  _globValIfExecuted = alpha * alpha * beta;
  
  _computation = _RECOMPUTE;
}

void TrianglesUnion::addTri(std::set<MTriangle*> &setTri) const
{
  for (int i = 0; i < _numTri; ++i)
    setTri.insert(_triangles[i]);
}

void TrianglesUnion::removeTri(std::set<MTriangle*> &setTri) const
{
  for (int i = 0; i < _numTri; ++i)
    setTri.erase(_triangles[i]);
}

bool TrianglesUnion::isIn(std::set<MTriangle*> &setTri) const
{
  for (int i = 0; i < _numTri; ++i)
  if (setTri.find(_triangles[i]) != setTri.end())
    return true;
  return false;
}

void TrianglesUnion::addInfluence(int *num, double *val, std::map<Rec2d_vertex*, int> &mapVert) const
{
  num[0] += _numEmbVert;
  num[1] += _numEmbEdge;
  val[0] += _embVertValue;
  val[1] += _embEdgeValue;
  for (int i = 0; i < _numBoundVert; ++i) {
    if (mapVert.find(_vertices[i]) == mapVert.end())
      mapVert[_vertices[i]] = -1;
    else
      mapVert[_vertices[i]] -= 1;  
  }
}

void TrianglesUnion::removeInfluence(int *num, double *val, std::map<Rec2d_vertex*, int> &mapVert) const
{
  num[0] -= _numEmbVert;
  num[1] -= _numEmbEdge;
  val[0] -= _embVertValue;
  val[1] -= _embEdgeValue;
  for (int i = 0; i < _numBoundVert; ++i) {
    mapVert[_vertices[i]] += 1;  
  }
}

double TrianglesUnion::computeReturn(const int *num,
                                     const double *val,
                                     const std::map<Rec2d_vertex*,
                                     int> &mapVert)
{
  double alpha = _ValVert - val[0];
  std::map<Rec2d_vertex*, int>::const_iterator it = mapVert.begin();
  for (; it != mapVert.end(); ++it) {
    alpha += it->first->getReward(it->second);
  }
  alpha /= _NumVert - num[0];
  double beta = (_ValEdge - val[1]) / (_NumEdge - num[1]);
  return alpha * beta;
}

bool TrianglesUnion::operator<(TrianglesUnion &other)
{
  _update();
  other._update();
  return _globValIfExecuted < other._globValIfExecuted; 
}

bool lessTriUnion::operator()(TrianglesUnion *tu1, TrianglesUnion *tu2) const
{
  return *tu1 < *tu2;
}

bool lessTriUnionInv::operator()(TrianglesUnion *tu1, TrianglesUnion *tu2) const
{
  return *tu2 < *tu1;
}

/*map tri to recomb
//map edge to double value (constructor)
set Recomb sorted
function best(copy vertex*[], copy set Recomb sorted);

construction :
 - list of vertex
 - set of recomb
 - map tri to recomb
 
destruction :
 - vertices, recomb
 
execution :
 - take best recomb
 - determine recomb to execute
 - maj E N e n
 - reduce maptrirecomb, setrecomb
 - sort setrecomb*/

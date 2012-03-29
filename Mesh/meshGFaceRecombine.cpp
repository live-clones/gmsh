// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#define REC2D_WAIT_TIME .01
#define REC2D_NUM_ACTIO 1000

// #define REC2D_SMOOTH
 #define REC2D_DRAW

#include <cmath>
#include "meshGFaceRecombine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "PView.h"
#include "meshGFace.h"
#ifdef REC2D_SMOOTH
  #include "meshGFaceOptimize.h"
#endif
#ifdef REC2D_DRAW
  #include "drawContext.h"
  #include "FlGui.h"
  #include "Context.h"
  #include "OS.h"
#endif

Recombine2D *Recombine2D::_current = NULL;
Rec2DData *Rec2DData::_current = NULL;
double **Rec2DVertex::_qualVSnum = NULL;
double **Rec2DVertex::_gains = NULL;

int otherParity(int a)
{
  if (a % 2)
    return a - 1;
  return a + 1;
}

/**  Recombine2D  **/
/*******************/
Recombine2D::Recombine2D(GFace *gf) : _gf(gf), _strategy(0), _numChange(0)
{
  if (Recombine2D::_current != NULL) {
    Msg::Warning("[Recombine2D] An instance already in execution");
    _data = NULL;
    return;
  }
  Recombine2D::_current = this;
  
  orientMeshGFace orienter;
  orienter(_gf);
  Rec2DVertex::initStaticTable();
  backgroundMesh::set(_gf);
  _bgm = backgroundMesh::current();
  _data = new Rec2DData();
  
  static int po = -1;
  if (++po < 1)
    Msg::Warning("FIXME Why {mesh 2} then {mesh 0} then {mesh 2} imply not corner vertices");
  
  static int pi = -1;
  if (++pi < 1)
    Msg::Warning("FIXME Why more vertices after first mesh generation");
  
  static int pu = -1;
  if (++pu < 1)
    Msg::Warning("FIXME Update of Action pointing to edge and vertex (when change)");
  
  static int py = -1;
  if (++py < 1)
    Msg::Warning("FIXME Deletion of action twoTri2Quad when Collapse pointing to it");
  
  // Be able to compute geometrical angle at corners
  std::map<MVertex*, AngleData> mapCornerVert;
  {
    std::list<GEdge*> listge = gf->edges();
    std::list<GEdge*>::iterator itge = listge.begin();
    for (; itge != listge.end(); ++itge) {
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)]
        ._gEdges.push_back(*itge);
      mapCornerVert[(*itge)->getEndVertex()->getMeshElement(0)->getVertex(0)]
        ._gEdges.push_back(*itge);
    }
  }
  // Create the 'Rec2DEdge', the 'Rec2DVertex' and the 'Rec2DElement'
  {
    std::map<MVertex*, Rec2DVertex*> mapVert;
    std::map<MVertex*, Rec2DVertex*>::iterator itV;
    std::map<MVertex*, AngleData>::iterator itCorner;
    // triangles
    for (unsigned int i = 0; i < gf->triangles.size(); ++i) {
      MTriangle *t = gf->triangles[i];
      
      Rec2DVertex *rv[3];
      for (int j = 0; j < 3; ++j) {
        MVertex *v = t->getVertex(j);
        if ( (itCorner = mapCornerVert.find(v)) != mapCornerVert.end() ) {
          if (!itCorner->second._rv)
            itCorner->second._rv = new Rec2DVertex(v);
          rv[j] = itCorner->second._rv;
          itCorner->second._mElements.push_back((MElement*)t);
        }
        else if ( (itV = mapVert.find(v)) != mapVert.end() ) {
          rv[j] = itV->second;
        }
        else {
          rv[j] = new Rec2DVertex(v);
          mapVert[v] = rv[j];
        }
      }
      const Rec2DEdge *re[3];
      for (int j = 0; j < 3; ++j) {
        if ( !(re[j] = Rec2DVertex::getCommonEdge(rv[j], rv[(j+1)%3])) )
          re[j] = new Rec2DEdge(rv[j], rv[(j+1)%3]);
      }
      
      new Rec2DElement(t, re, rv);
    }
    // quadrangles
    for (unsigned int i = 0; i < gf->quadrangles.size(); ++i) {
      MQuadrangle *q = gf->quadrangles[i];
      
      Rec2DVertex *rv[4];
      for (int j = 0; j < 4; ++j) {
        MVertex *v = q->getVertex(j);
        if ( (itCorner = mapCornerVert.find(v)) != mapCornerVert.end() ) {
          if (!itCorner->second._rv)
            itCorner->second._rv = new Rec2DVertex(v);
          rv[j] = itCorner->second._rv;
          itCorner->second._mElements.push_back((MElement*)q);
        }
        else if ( (itV = mapVert.find(v)) == mapVert.end() ) {
          rv[j] = itV->second;
        }
        else {
          rv[j] = new Rec2DVertex(v);
          mapVert[v] = rv[j];
        }
      }
      const Rec2DEdge *re[4];
      for (int j = 0; j < 4; ++j) {
        if ( !(re[j] = Rec2DVertex::getCommonEdge(rv[i], rv[(i+1)%3])) )
          re[j] = new Rec2DEdge(rv[i], rv[(i+1)%3]);
      }
      
      new Rec2DElement(q, re, rv);
    }
  }
  // update corner
  {
    std::map<MVertex*, AngleData>::iterator it = mapCornerVert.begin();
    for (; it != mapCornerVert.end(); ++it) {
      double angle = _geomAngle(it->first,
                                it->second._gEdges,
                                it->second._mElements);
      new Rec2DVertex(it->second._rv, angle);
    }
  }
  mapCornerVert.clear();
  // update boundary, create the 'Rec2DTwoTri2Quad'
  {
    Rec2DData::iter_re it = Rec2DData::firstEdge();
    for (; it != Rec2DData::lastEdge(); ++it) {
      Rec2DVertex *rv0 = (*it)->getVertex(0), *rv1 = (*it)->getVertex(1);
      if ((*it)->isOnBoundary()) {
        rv0->setOnBoundary();
        rv1->setOnBoundary();
      }
      else {
        std::vector<Rec2DElement*> elem;
        Rec2DVertex::getCommonElements(rv0, rv1, elem);
        if (elem.size() != 2)
          Msg::Error("[Recombine2D] %d elements instead of 2 for neighbour link",
                     elem.size()                                                 );
        else {
          elem[0]->addNeighbour(*it, elem[1]);
          elem[1]->addNeighbour(*it, elem[0]);
          new Rec2DCollapse(new Rec2DTwoTri2Quad(elem[0], elem[1]));
        }
      }
    }
  }
  // set parity on boundary, create the 'Rec2DFourTri2Quad', add quality of angle at vertices
  {
    Rec2DData::iter_rv it = Rec2DData::firstVertex();
    for (; it != Rec2DData::lastVertex(); ++it) {
      Rec2DVertex *rv = *it;
      if (rv->getOnBoundary()) {
        if (!rv->getParity()) {
          int base = Rec2DData::getNewParity();
          rv->setBoundaryParity(base, base+1);
        }
      }
      else if (rv->getNumElements() == 4) {
        ;
      }
    }
  }
  
  Rec2DData::checkObsolete();
  _data->printState();
}

Recombine2D::~Recombine2D()
{
  delete _data;
  if (Recombine2D::_current == this)
    Recombine2D::_current = NULL;
}

bool Recombine2D::recombine()
{
  Rec2DAction *nextAction;
  while ((nextAction = Rec2DData::getBestAction())) {
#ifdef REC2D_DRAW
    FlGui::instance()->check();
    double time = Cpu();
    nextAction->color(0, 0, 200);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
#endif
    
    if (!_remainAllQuad(nextAction)) {
      delete nextAction;
#ifdef REC2D_DRAW
      nextAction->color(190, 0, 0);
      while (Cpu()-time < REC2D_WAIT_TIME)
        FlGui::instance()->check();
#endif
      continue;
    }
    ++_numChange;
    std::vector<Rec2DVertex*> newPar;
    nextAction->apply(newPar);
    
    // forall v in newPar : check obsoletes action;
    
#ifdef REC2D_DRAW
    _gf->triangles = _data->_tri;
    _gf->quadrangles = _data->_quad;
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    while (Cpu()-time < REC2D_WAIT_TIME)
      FlGui::instance()->check();
#endif
    
    delete nextAction;
  }
  
  _data->printState();
#ifdef REC2D_SMOOTH
    laplaceSmoothing(_gf,100);
#endif
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
  return 1;
}

double Recombine2D::recombine(int depth)
{
  double time = Cpu();
  Rec2DData::clearChanges();
  double bestGlobalQuality;
#ifdef REC2D_DRAW // draw state at origin
    _gf->triangles = _data->_tri;
    _gf->quadrangles = _data->_quad;
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    while (Cpu()-time < REC2D_WAIT_TIME)
      FlGui::instance()->check();
    time = Cpu();
#endif
  Rec2DNode *root = new Rec2DNode(NULL, NULL, bestGlobalQuality, depth);
  Rec2DNode *currentNode = root->selectBestNode();
  
  static int num = 20, i = 0;
  static double dx = .0, dy = .0;
  
  while (currentNode) {
    //_data->checkQuality();
    FlGui::instance()->check();
#ifdef REC2D_DRAW // draw state at origin
    _gf->triangles = _data->_tri;
    _gf->quadrangles = _data->_quad;
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    //while (Cpu()-time < REC2D_WAIT_TIME)
      FlGui::instance()->check();
    time = Cpu();
#endif
#ifdef REC2D_DRAW // draw all states
    if ( !((i+1) % ((int)std::sqrt(num)+1)) ) {
      dx = .0;
      dy -= 1.1;
    }
    else
      dx += 1.1;
    drawState(dx, dy);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    //while (Cpu()-time < REC2D_WAIT_TIME)
      FlGui::instance()->check();
    ++i;
    time = Cpu();
#endif
    currentNode->develop(depth, bestGlobalQuality);
    currentNode = currentNode->selectBestNode();
  }
  
  return Rec2DData::getGlobalQuality();
  //_data->printState();
}

int Recombine2D::getNumTri() const
{
  return _data->getNumTri();
}

void Recombine2D::clearChanges()
{
  Rec2DData::clearChanges();
#ifdef REC2D_DRAW
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
#endif
}

bool Recombine2D::developTree()
{
  double bestGlobalQuality;
  Rec2DNode root(NULL, NULL, bestGlobalQuality);
  _data->printState();
  
  Msg::Info("best global value : %g", bestGlobalQuality);
  Msg::Info("num end node : %d", Rec2DData::getNumEndNode());
  
  Rec2DData::sortEndNode();
  Rec2DData::drawEndNode(100);
  //_gf->triangles.clear();
  return 1;
}

void Recombine2D::nextTreeActions(std::vector<Rec2DAction*> &actions,
                                  const std::vector<Rec2DElement*> &neighbourEl)
{
  actions.clear();
  if (_current->_strategy == 4) {
    Msg::Warning("FIXME remove this part");
    Rec2DAction *action;
    if ((action = Rec2DData::getBestAction()))
      actions.push_back(action);
    return;
  }
  std::vector<Rec2DElement*> elements;
  Rec2DAction *ra = NULL;
  Rec2DElement *rel = NULL;
  switch (_current->_strategy) {
    case 0 : // random triangle of random action
      ra = Rec2DData::getRandomAction();
      if (!ra) return;
      rel = ra->getRandomElement();
      break;
      
    default :
    case 3 : // triangle of best neighbour action
      for (unsigned int i = 0; i < neighbourEl.size(); ++i) {
        neighbourEl[i]->getUniqueActions(actions);
      }
      std::sort(actions.begin(), actions.end(), gterRec2DAction());
      if (actions.size()) {
        actions[0]->getElements(elements);
        for (unsigned int i = 0; i < elements.size(); ++i) {
          for (unsigned int j = 0; j < neighbourEl.size(); ++j) {
            if (elements[i] == neighbourEl[j]) {
              rel = elements[i];
              goto end;
            }
          }
        }
      }
      end :
      if (rel) break;
      
    case 2 : // random neighbour triangle
      if (neighbourEl.size()) {
        rel = neighbourEl[rand() % (int)neighbourEl.size()];
        break;
      }
      
    case 1 : // random triangle of best action
      ra = Rec2DData::getBestAction();
      if (!ra) return;
      rel = ra->getRandomElement();
      break;
  }
  rel->getActions(actions);
  unsigned int i = 0;
  while (i < actions.size()) {
    if (actions[i]->isObsolete()) {
#ifdef REC2D_DRAW
      //actions[i]->color(190, 0, 0);
#endif
      actions[i] = actions.back();
      actions.pop_back();
    }
    else
      ++i;
  }
}

void Recombine2D::drawState(double shiftx, double shifty) const
{
  //_data->drawTriangles(shiftx, shifty);
  _data->drawElements(shiftx, shifty);
  _data->drawChanges(shiftx, shifty);
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

void Recombine2D::printState() const
{
  _data->printState();
}

double Recombine2D::_geomAngle(const MVertex *v,
                               const std::vector<GEdge*> &gEdge,
                               const std::vector<MElement*> &elem) const //*
{
  if (gEdge.size() != 2) {
    Msg::Error("[Recombine2D] Wrong number of edge : %d, returning pi/2",
                 gEdge.size()                                            );
    return M_PI / 2.;
  }
  static const double prec = 100.;
  
  SVector3 vectv = SVector3(v->x(), v->y(), v->z());
  SVector3 firstDer0, firstDer1;
  
  for (unsigned int k = 0; k < 2; ++k) {
    GEdge *ge = gEdge[k];
    SVector3 vectlb = ge->position(ge->getLowerBound());
    SVector3 vectub = ge->position(ge->getUpperBound());
    vectlb -= vectv;
    vectub -= vectv;
    double normlb, normub;
    if ((normlb = norm(vectlb)) > prec * (normub = norm(vectub)))
      firstDer1 = -1. * ge->firstDer(ge->getUpperBound());
    else if (normub > prec * normlb)
      firstDer1 = ge->firstDer(ge->getLowerBound());
    else {
      Msg::Error("[Recombine2D] Bad precision, returning pi/2");
      return M_PI / 2.;
    }
    if (k == 0)
      firstDer0 = firstDer1;
  }
  
  firstDer0 = firstDer0 * (1. / norm(firstDer0));
  firstDer1 = firstDer1 * (1. / norm(firstDer1));
  
  double angle1 = acos(dot(firstDer0, firstDer1));
  double angle2 = 2. * M_PI - angle1;
  
  double angleMesh = .0;
  for (unsigned int i = 0; i < elem.size(); ++i) {
    MElement *el = elem[i];
    int k = 0, numV = el->getNumVertices();
    while (el->getVertex(k) != v && k < numV) ++k;
    if (k == numV) {
      Msg::Error("[Recombine2D] Wrong element, returning pi/2");
      return M_PI / 2.;
    }
    if (el->getNumVertices() > 3)
      Msg::Warning("[Recombine2D] angle3Vertices() ok for triangle... but not for other");
    angleMesh += angle3Vertices(el->getVertex((k+numV-1) % numV), v,
                                el->getVertex((k+1) % numV)    );
  }
  
  if (angleMesh < M_PI)
    return angle1;
  return angle2;
}

bool Recombine2D::_remainAllQuad(const Rec2DAction *action) const
{
  if (action->isAssumedObsolete()) {
    static int a = -1;
    if (++a < 1)
      Msg::Error("[Recombine2D] obsolete action (allQuad)");
    return false;
  }
  Rec2DData::clearAssumedParities();
  
  int p[4];
  action->getAssumedParities(p);
  
  if (!p[0] && !p[1] && !p[2] && !p[3]) {
    static int a = -1;
    if (++a < 1) Msg::Warning("FIXME isoleted should be check ? Think not");
    return true;
  }
  
  int min = Rec2DData::getNewParity(), index = -1;
  for (int i = 0; i < 4; ++i) {
    if (p[i] && min > p[i]) {
      min = p[i];
      index = i;
    }
  }
  if (index == -1) {
    Msg::Error("[Recombine2D] Please, fixme !");
    return false;
  }
  
  std::set<Rec2DElement*> neighbours;
  std::vector<Rec2DVertex*> touched;
  
  for (int i = 0; i < 4; i += 2) {
    static int a = -1;
    if (++a < 1) Msg::Warning("FIXME depend de l'action");
    int par;
    if ((index/2) * 2 == i)
      par = min;
    else
      par = otherParity(min);
    for (int j = 0; j < 2; ++j) {
      if (!p[i+j]) {
        Rec2DVertex *v = action->getVertex(i+j);
        v->setAssumedParity(par);
        v->getTriangles(neighbours);
      }
      else if (p[i+j] != par)
        Rec2DData::associateAssumedParity(p[i+j], par, touched);
    }
  }
  
  for (unsigned int i = 0; i < touched.size(); ++i)
    touched[i]->getTriangles(neighbours);
  touched.clear();
  
  return _remainAllQuad(neighbours);
}

bool Recombine2D::_remainAllQuad(std::set<Rec2DElement*> &elem) const
{
  std::vector<Rec2DVertex*> touched;
  
  while (elem.size() > 0) {
    std::set<Rec2DElement*>::iterator itTri = elem.begin();
    
    int p[3];
    (*itTri)->getAssumedParities(p);
    
    bool hasIdentical = false;
    for (int i = 0; i < 3; ++i) {
      if (p[i] && p[i] == p[(i+1)%3]) hasIdentical = true;
    }
    if (!hasIdentical) {
      elem.erase(itTri);
      continue;
    }
    if (p[0] == p[1] && p[0] == p[2]) {
      Rec2DData::revertAssumedParities();
      return false;
    }
    
    bool hasAction = false;
    std::map<Rec2DVertex*, std::vector<int> > suggestions;
    for (int i = 0; i < (*itTri)->getNumActions(); ++i) {
      if ((*itTri)->getAction(i)->whatWouldYouDo(suggestions))
        hasAction = true;
    }
    if (!hasAction) {
      Rec2DData::revertAssumedParities();
      return false;
    }
    
    std::map<Rec2DVertex*, std::vector<int> >::iterator itSug;
    itSug = suggestions.begin();
    for (; itSug != suggestions.end(); ++itSug) {
      int par = itSug->second.front();
      bool onlyOnePar = true;
      for (unsigned int i = 1; i < itSug->second.size(); ++i) {
        if (itSug->second[i] != par) {
          onlyOnePar = false;
          break;
        }
      }
      
      if (onlyOnePar) {
        Rec2DVertex *v = itSug->first;
        int oldPar = v->getAssumedParity();
        
        if (!oldPar) {
          v->setAssumedParity(par);
          v->getTriangles(elem);
        }
        else if ((par/2)*2 != (oldPar/2)*2) {
          if (oldPar < par) {
            int a = oldPar;
            oldPar = par;
            par = a;
          }
          Rec2DData::associateAssumedParity(oldPar, par, touched);
          for (unsigned int i = 0; i < touched.size(); ++i) {
            touched[i]->getTriangles(elem);  
          }
          touched.clear();
        }
        else if (par%2 != oldPar%2) {
          Msg::Error("SHOULD NOT HAPPEN");
          Rec2DData::revertAssumedParities();
          return false;
        }
      }
    }
    elem.erase(itTri);
  }
  return true;
}

void Recombine2D::add(MQuadrangle *q)
{
  _current->_gf->quadrangles.push_back(q);
  _current->_data->_quad.push_back(q);
}

void Recombine2D::add(MTriangle *t)
{
  _current->_gf->triangles.push_back(t);
  _current->_data->_tri.push_back(t);
}


/**  Rec2DData  **/
/*****************/
Rec2DData::Rec2DData()
{
  if (Rec2DData::_current != NULL) {
    Msg::Error("[Rec2DData] An instance in execution");
    return;
  }
  Rec2DData::_current = this;
  _numEdge = _numVert = 0;
  _valEdge = _valVert = .0;
}

Rec2DData::~Rec2DData()
{
  if (Rec2DData::_current == this)
    Rec2DData::_current = NULL;
}

#ifdef REC2D_DRAW
void Rec2DData::add(Rec2DElement *rel)
{
  _current->_elements.insert(rel);
  
  MTriangle *t = rel->getMTriangle();
  if (t)
    _current->_tri.push_back(t);
  MQuadrangle *q = rel->getMQuadrangle();
  if (q)
    _current->_quad.push_back(q);
  
}
#endif
void Rec2DData::remove(const Rec2DEdge *re)
{
  /*bool b = false;
  unsigned int i = 0;
  while (i < _current->_edges.size()) {
    if (_current->_edges[i] == re) {
      _current->_edges[i] = _current->_edges.back();
      _current->_edges.pop_back();
      if (b)
        Msg::Error("[Rec2DData] Two or more times same edge");
      b = true;
    }
    else
      ++i;
  }
  if (!b)
    Msg::Error("[Rec2DData] No edge");
  */
  _current->_edges.erase((Rec2DEdge*)re);
}

void Rec2DData::remove(const Rec2DVertex *rv)
{
  _current->_vertices.erase((Rec2DVertex*)rv);
  static int a = -1;
  if (++a < 1)
    Msg::Warning("FIXME Verifier element supprimŽ");
}

void Rec2DData::remove(/*const*/ Rec2DElement *rel)
{
  /*bool b = false;
  unsigned int i = 0;
  while (i < _current->_elements.size()) {
    if (_current->_elements[i] == rel) {
      _current->_elements[i] = _current->_elements.back();
      _current->_elements.pop_back();
      if (b)
        Msg::Error("[Rec2DData] Two or more times same element");
      b = true;
    }
    else
      ++i;
  }
  if (!b)
    Msg::Error("[Rec2DData] No element");
  */
  _current->_elements.erase(rel);
#ifdef REC2D_DRAW
  MTriangle *t = rel->getMTriangle();
  if (t) {
    for (unsigned int i = 0; i < _current->_tri.size(); ++i) {
      if (_current->_tri[i] == t) {
        _current->_tri[i] = _current->_tri.back();
        _current->_tri.pop_back();
        return;
      }
    }
    Msg::Warning("[Rec2DData] Didn't erased mtriangle :(");
  }
  MQuadrangle *q = rel->getMQuadrangle();
  if (q) {
    for (unsigned int i = 0; i < _current->_quad.size(); ++i) {
      if (_current->_quad[i] == q) {
        _current->_quad[i] = _current->_quad.back();
        _current->_quad.pop_back();
        return;
      }
    }
    Msg::Warning("[Rec2DData] Didn't erased mquadrangle :(");
  }
#endif
}

void Rec2DData::remove(const Rec2DAction *ra)
{
  std::list<Rec2DAction*>::iterator it = _current->_actions.begin();
  while (it != _current->_actions.end()) {
    if (*it == ra) {
      it = _current->_actions.erase(it);
      return;
    }
    else
      ++it;
  }
  static int a = -1;
  if (++a < 1)
  Msg::Error("[Rec2DData] removing too much action");
}

void Rec2DData::printState() const
{
  Msg::Info(" ");
  Msg::Info("State");
  Msg::Info("-----");
  Msg::Info("numEdge %d (%d), valEdge %g => %g", _numEdge, _edges.size(), (double)_valEdge, (double)_valEdge/(double)_numEdge);
  Msg::Info("numVert %d (%d), valVert %g => %g", _numVert, _vertices.size(), (double)_valVert, (double)_valVert/(double)_numVert);
  Msg::Info("Element (%d)", _elements.size());
  Msg::Info("global Value %g", Rec2DData::getGlobalQuality());
  Msg::Info("num action %d", _actions.size());
  std::map<int, std::vector<Rec2DVertex*> >::const_iterator it = _parities.begin();
  for (; it != _parities.end(); ++it) {
    Msg::Info("par %d, #%d", it->first, it->second.size());
  }
  Msg::Info(" ");
  iter_re ite;
  long double valEdge = .0;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    valEdge += (long double)(*ite)->getWeightedQual();
  }
  Msg::Info("valEdge : %g >< %g", (double)valEdge, (double)_valEdge);
  iter_rv itv;
  long double valVert = .0;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    valVert += (long double)(*itv)->getQual();
    if ((*itv)->getParity() == -1 || (*itv)->getParity() == 1)
      Msg::Error("parity %d, I'm very angry", (*itv)->getParity());
  }
  Msg::Info("valVert : %g >< %g", (double)valVert, (double)_valVert);
}

void Rec2DData::checkQuality() const
{
  iter_re ite;
  long double valEdge = .0;
  int numEdge = 0;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    valEdge += (long double)(*ite)->getWeightedQual();
    numEdge += (*ite)->getWeight();
  }
  iter_rv itv;
  long double valVert = .0;
  int numVert = 0;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    valVert += (long double)(*itv)->getQual();
    numVert += 2;
  }
  if (fabs(valVert - _valVert) > 1e-14 || fabs(valEdge - _valEdge) > 1e-14) {
    Msg::Error("Vert : %g >< %g (%g), %d >< %d", (double)valVert, (double)_valVert, (double)(valVert-_valVert), numVert, _numVert);
    Msg::Error("Edge : %g >< %g (%g), %d >< %d", (double)valEdge, (double)_valEdge, (double)(valEdge-_valEdge), numEdge, _numEdge);
  }
}

void Rec2DData::printActions() const
{
  std::map<int, std::vector<double> > data;
  std::list<Rec2DAction*>::const_iterator it = _actions.begin();
  for (; it != _actions.end(); ++it) {
    std::vector<Rec2DElement*> tri;
    (*it)->getElements(tri);
    Msg::Info("action %d (%d, %d) -> reward %g", *it, tri[0]->getNum(), tri[1]->getNum(), .0/*(*it)->getReward()*/);
      //Msg::Info("action %d -> reward %g", *it, (*it)->getReward());
    data[tri[0]->getNum()].resize(1);
    data[tri[1]->getNum()].resize(1);
    data[tri[0]->getNum()][0] = (*it)->getReward();
    data[tri[1]->getNum()][0] = (*it)->getReward();
    //(*it)->print();
  }
  new PView("Jmin_bad", "ElementData", Recombine2D::getGFace()->model(), data);
  Msg::Info(" ");
}

int Rec2DData::getNewParity()
{
  if (_current->_parities.empty())
    return 2;
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  it = _current->_parities.end();
  --it;
  return (it->first/2)*2 + 2;
}

Rec2DDataChange* Rec2DData::getNewDataChange()
{
  _current->_changes.push_back(new Rec2DDataChange());
  return _current->_changes.back();
}

bool Rec2DData::revertDataChange(Rec2DDataChange *rdc)
{
  if (_current->_changes.back() != rdc)
    return false;
  _current->_changes.pop_back();
  rdc->revert();
  delete rdc;
  return true;
}

void Rec2DData::clearChanges()
{
  for (int i = (int) _current->_changes.size() - 1; i > -1; --i) {
    _current->_changes[i]->revert();
    delete _current->_changes[i];
  }
  _current->_changes.clear();
}

void Rec2DData::removeParity(const Rec2DVertex *rv, int p)
{
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  if ( (it = _current->_parities.find(p)) == _current->_parities.end() ) {
    Msg::Error("[Rec2DData] Don't have parity %d", p);
    return;
  }
  bool b = false;
  std::vector<Rec2DVertex*> *vect = &it->second;
  unsigned int i = 0;
  while (i < vect->size()) {
    if (vect->at(i) == rv) {
      vect->at(i) = vect->back();
      vect->pop_back();
      if (b)
        Msg::Error("[Rec2DData] Two or more times same vertex");
      b = true;
    }
    else
      ++i;
  }
  if (!b)
    Msg::Error("[Rec2DData] No vertex 1");
  else if (vect->empty())
    _current->_parities.erase(it);
}

void Rec2DData::associateParity(int pOld, int pNew, Rec2DDataChange *rdc)
{
  if (pOld/2 == pNew/2) {
    Msg::Error("[Rec2DData] Do you want to make a mess of parities ?");
    return;
  }
  if (_current->_parities.find(pNew) == _current->_parities.end()) {
    Msg::Warning("[Rec2DData] That's strange, isn't it ?");
    static int a = -1;
    if (++a == 10)
      Msg::Warning("[Rec2DData] AND LOOK AT ME WHEN I TALK TO YOU !");
  }
  
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  std::vector<Rec2DVertex*> *vect, *vectNew;
  {
    it = _current->_parities.find(pOld);
    if (it == _current->_parities.end()) {
      static int a = -1;
      if (++a < 1)
        Msg::Error("[Rec2DData] You are mistaken, I'll never talk to you again !");
      return;
    }
    vect = &it->second;
    if (rdc)
      rdc->saveParity(*vect);
    for (unsigned int i = 0; i < vect->size(); ++i)
      (*vect)[i]->setParityWD(pOld, pNew);
    vectNew = &_current->_parities[pNew];
    vectNew->insert(vectNew->end(), vect->begin(), vect->end());
    _current->_parities.erase(it);
  }
  
  pOld = otherParity(pOld);
  pNew = otherParity(pNew);
  {
    it = _current->_parities.find(pOld);
    if (it == _current->_parities.end()) {
      Msg::Error("[Rec2DData] What ?");
      return;
    }
    vect = &it->second;
    if (rdc)
      rdc->saveParity(*vect);
    for (unsigned int i = 0; i < vect->size(); ++i)
      (*vect)[i]->setParityWD(pOld, pNew);
    vectNew = &_current->_parities[pNew];
    vectNew->insert(vectNew->end(), vect->begin(), vect->end());
    _current->_parities.erase(it);
  }
}

void Rec2DData::removeAssumedParity(const Rec2DVertex *rv, int p)
{
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  it = _current->_assumedParities.find(p);
  if (it == _current->_assumedParities.end()) {
    Msg::Error("[Rec2DData] Don't have assumed parity %d", p);
    return;
  }
  bool b = false;
  std::vector<Rec2DVertex*> *vect = &it->second;
  unsigned int i = 0;
  while (i < vect->size()) {
    if (vect->at(i) == rv) {
      vect->at(i) = vect->back();
      vect->pop_back();
      if (b)
        Msg::Error("[Rec2DData] Two or more times same vertex");
      b = true;
    }
    else
      ++i;
  }
  if (!b)
    Msg::Error("[Rec2DData] No vertex 2");
}

void Rec2DData::saveAssumedParity(const Rec2DVertex *rv, int p)
{
  static int a = -1;
  if (++a < 1)
    Msg::Warning("FIXME Do you have cleared _oldParity ?");
  std::map<Rec2DVertex*, int>::iterator it =
      _current->_oldParity.find((Rec2DVertex*)rv);
  if (it == _current->_oldParity.end())
    _current->_oldParity[(Rec2DVertex*)rv] = p;
}

void Rec2DData::associateAssumedParity(int pOld, int pNew,
                                       std::vector<Rec2DVertex*> &touched)
{
  if (pOld/2 == pNew/2) {
    Msg::Error("[Rec2DData] Do you want to make a mess of assumed parities ?");
    return;
  }
  if (_current->_assumedParities.find(pNew) == _current->_assumedParities.end()) {
    Msg::Warning("[Rec2DData] That's strange, isn't it ?");
  }
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  std::vector<Rec2DVertex*> *vect, *vectNew;
  
  {
    it = _current->_parities.find(pOld);
    if (it == _current->_parities.end()) {
      Msg::Error("[Rec2DData] But, this parity doesn't exist !");
      return;
    }
    vect = &it->second;
    for (unsigned int i = 0; i < vect->size(); ++i) {
      if (vect->at(i)->setAssumedParity(pNew))
        touched.push_back(vect->at(i));
    }
    
    it = _current->_assumedParities.find(pOld);
    if (it != _current->_assumedParities.end()) {
      vect = &it->second;
      for (unsigned int i = 0; i < vect->size(); ++i) {
        vect->at(i)->setAssumedParityWD(pOld, pNew);
        touched.push_back(vect->at(i));
      }
      vectNew = &_current->_assumedParities[pNew];
      vectNew->insert(vectNew->end(), vect->begin(), vect->end());
      _current->_assumedParities.erase(it);
    }
  }
  
  pOld = otherParity(pOld);
  pNew = otherParity(pNew);
  {
    it = _current->_parities.find(pOld);
    if (it == _current->_parities.end()) {
      Msg::Error("[Rec2DData] What ?");
      return;
    }
    vect = &it->second;
    for (unsigned int i = 0; i < vect->size(); ++i) {
      if (vect->at(i)->setAssumedParity(pNew))
        touched.push_back(vect->at(i));
    }
    
    it = _current->_assumedParities.find(pOld);
    if (it != _current->_assumedParities.end()) {
      vect = &it->second;
      for (unsigned int i = 0; i < vect->size(); ++i) {
        vect->at(i)->setAssumedParityWD(pOld, pNew);
        touched.push_back(vect->at(i));
      }
      vectNew = &_current->_assumedParities[pNew];
      vectNew->insert(vectNew->end(), vect->begin(), vect->end());
      _current->_assumedParities.erase(it);
    }
  }
}

void Rec2DData::revertAssumedParities()
{
  std::map<Rec2DVertex*, int>::iterator it;
  it = _current->_oldParity.begin();
  for (; it != _current->_oldParity.end(); ++it) {
    it->first->revertAssumedParity(it->second);
  }
}

double Rec2DData::getGlobalQuality()
{
  double a = (double)_current->_valVert / (double)_current->_numVert;
  return a * (double)_current->_valEdge / (double)_current->_numEdge;
}

double Rec2DData::getGlobalQuality(int numEdge, double valEdge,
                                   int numVert, double valVert )
{
  double a = ((double)_current->_valVert + valVert) / (double)(_current->_numVert + numVert);
  return a * ((double)_current->_valEdge + valEdge) / (double)(_current->_numEdge + numEdge);
}

Rec2DAction* Rec2DData::getBestAction()
{
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME implement better compute qual for collapse");
  std::list<Rec2DAction*> actions = _current->_actions;
  if (actions.size() == 0)
    return NULL;
  return *std::max_element(actions.begin(),
                           actions.end(), lessRec2DAction());
}

Rec2DAction* Rec2DData::getRandomAction()
{
  if (_current->_actions.size() == 0)
    return NULL;
  int index = rand() % (int)_current->_actions.size();
  std::list<Rec2DAction*>::iterator it = _current->_actions.begin();
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME what type is size of list ?");
  for (int i = 0; i < index; ++i) ++it;
  return *it;
}

void Rec2DData::checkObsolete()
{
  std::vector<Rec2DAction*> obsoletes;
  std::list<Rec2DAction*>::iterator it = _current->_actions.begin();
  for (; it != _current->_actions.end(); ++it) {
    if ((*it)->isObsolete())
      obsoletes.push_back(*it);
  }
  
  for (unsigned int i = 0; i < obsoletes.size(); ++i) {
    if (obsoletes[i]->getInfant()) {
      obsoletes[i]->hide();
      _current->_hiddenActions.push_back(obsoletes[i]);
    }
    else
      delete obsoletes[i];
  }
}

void Rec2DData::drawTriangles(double shiftx, double shifty) const
{
  iter_rel it = firstElement();
  for (; it != lastElement(); ++it) {
    if ((*it)->isTri())
      (*it)->createElement(shiftx, shifty);
  }
}

void Rec2DData::drawElements(double shiftx, double shifty) const
{
  iter_rel it = firstElement();
  for (; it != lastElement(); ++it)
      (*it)->createElement(shiftx, shifty);
}

void Rec2DData::drawChanges(double shiftx, double shifty) const
{
  std::map<int, std::vector<double> > data;
  int k = 0;
  for (unsigned int i = 0; i < _changes.size(); ++i) {
    if (_changes[i]->getAction()->haveElem())
      data[_changes[i]->getAction()->getNum(shiftx, shifty)].push_back(++k);
  }
  new PView("Changes", "ElementData", Recombine2D::getGFace()->model(), data);
}

void Rec2DData::drawEndNode(int num)
{
  double dx = .0, dy = .0;
  for (int i = 0; i < num && i < (int)_current->_endNodes.size(); ++i) {
    std::map<int, std::vector<double> > data;
    Rec2DNode *currentNode = _current->_endNodes[i];
    Msg::Info("%d -> %g", i+1, currentNode->getGlobQual());
    int k = 0;
    if ( !((i+1) % ((int)std::sqrt(num)+1)) ) {
      dx = .0;
      dy -= 1.2;
    }
    else
      dx += 1.2;
    while (currentNode && currentNode->getAction()) {
      //Msg::Info("%g", currentNode->getGlobQual());
      //data[currentNode->getNum()].push_back(currentNode->getGlobQual());
      data[currentNode->getAction()->getNum(dx, dy)].push_back(++k);
      currentNode = currentNode->getFather();
    }
    new PView("Jmin_bad", "ElementData", Recombine2D::getGFace()->model(), data);
  }
}

void Rec2DData::sortEndNode()
{
  std::sort(_current->_endNodes.begin(),
            _current->_endNodes.end(),
            moreRec2DNode()             );
}

/**  Rec2DChange  **/
/*******************/
Rec2DChange::Rec2DChange(Rec2DEdge *re, bool toHide) : _entity(re), _info(NULL)
{
  if (toHide) {
    re->hide();
    _type = HideEdge;
  }
  else
    _type = CreatedEdge;
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv, bool toHide) : _entity(rv), _info(NULL)
{
  if (toHide) {
    rv->hide();
    _type = HideVertex;
  }
  else
    _type = CreatedVertex;
}

Rec2DChange::Rec2DChange(Rec2DElement *rel, bool toHide) : _entity(rel), _info(NULL)
{
  if (toHide) {
    rel->hide();
    _type = HideElement;
  }
  else
    _type = CreatedElement;
}

Rec2DChange::Rec2DChange(Rec2DAction *ra, bool toHide) : _entity(ra), _info(NULL)
{
  if (toHide) {
    ra->hide();
    _type = HideAction;
  }
  else
    _type = CreatedAction;
}

Rec2DChange::Rec2DChange(const std::vector<Rec2DAction*> &actions, bool toHide) : _info(NULL)
{
  std::vector<Rec2DAction*> *vect = new std::vector<Rec2DAction*>();
  *vect = actions;
  _entity = vect;
  if (toHide) {
    for (unsigned int i = 0; i < actions.size(); ++i)
      actions[i]->hide();
    _type = HideActions;
  }
  else
    _type = CreatedActions;
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv, int newPar, Rec2DChangeType type)
{
  if (type == ChangePar) {
    _type = ChangePar;
    _entity = rv;
    int *oldPar = new int;
    *oldPar = rv->getParity();
    _info = oldPar;
    rv->setParity(newPar);
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

Rec2DChange::Rec2DChange(const std::vector<Rec2DVertex*> &verts,
                         Rec2DChangeType type                   )
{
  if (type == SavePar) {
    _type = SavePar;
    std::vector<Rec2DVertex*> *vect = new std::vector<Rec2DVertex*>();
    *vect = verts;
    _entity = vect;
    std::vector<int> *parities = new std::vector<int>(verts.size());
    _info = parities;
    for (unsigned int i = 0; i < verts.size(); ++i)
      (*parities)[i] = verts[i]->getParity();
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv, SPoint2 newCoord)
: _type(Relocate), _entity(rv)
{
  SPoint2 *oldCoord = new SPoint2();
  rv->getParam(oldCoord);
  _info = oldCoord;
  rv->relocate(newCoord);
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv,
                         const std::vector<Rec2DElement*> &elem,
                         Rec2DChangeType type                   )
{
  std::vector<Rec2DElement*> *vect = new std::vector<Rec2DElement*>();
  _type = type;
  _entity = rv;
  _info = vect;
  switch (type) {
    case AddElem :
      *vect = elem;
      for (unsigned int i = 0; i < elem.size(); ++i)
        rv->add(elem[i]);
      break;
      
    case RemoveElem :
      *vect = elem;
      for (int i = (int)elem.size()-1; i > -1; --i)
        rv->rmv(elem[i]);
      break;
      
    default :
      delete vect;
      _type = Error;
      _entity = _info = NULL;
  }
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv0, Rec2DVertex *rv1,
                         const std::vector<Rec2DEdge*> &edges,
                         Rec2DChangeType type                 )
{
  if (type == SwapVertInEdge) {
    _type = type;
    std::vector<Rec2DEdge*> *vect = new std::vector<Rec2DEdge*>();
    *vect = edges;
    _entity = vect;
    std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
    pairVert = new std::pair<Rec2DVertex*, Rec2DVertex*>(rv1, rv0);
    _info = pairVert;
    for (unsigned int i = 0; i < edges.size(); ++i)
      edges[i]->swap(rv0, rv1);
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

Rec2DChange::Rec2DChange(Rec2DVertex *rv0, Rec2DVertex *rv1,
                         const std::vector<Rec2DAction*> &actions,
                         Rec2DChangeType type                     )
{
  if (type == SwapVertInAction) {
    _type = type;
    std::vector<Rec2DAction*> *vect = new std::vector<Rec2DAction*>();
    *vect = actions;
    _entity = vect;
    std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
    pairVert = new std::pair<Rec2DVertex*, Rec2DVertex*>(rv1, rv0);
    _info = pairVert;
    for (unsigned int i = 0; i < actions.size(); ++i)
      actions[i]->swap(rv0, rv1);
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

Rec2DChange::Rec2DChange(Rec2DEdge *re0, Rec2DEdge *re1,
                         const std::vector<Rec2DAction*> &actions,
                         Rec2DChangeType type                     )
{
  if (type == SwapEdgeInAction) {
    _type = type;
    std::vector<Rec2DAction*> *vect = new std::vector<Rec2DAction*>();
    *vect = actions;
    _entity = vect;
    std::pair<Rec2DEdge*, Rec2DEdge*> *pairVert;
    pairVert = new std::pair<Rec2DEdge*, Rec2DEdge*>(re1, re0);
    _info = pairVert;
    for (unsigned int i = 0; i < actions.size(); ++i)
      actions[i]->swap(re0, re1);
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

Rec2DChange::Rec2DChange(Rec2DEdge *re0, Rec2DEdge *re1,
                         Rec2DChangeType type           )
{
  if (type == SwapEdgeInElem) {
    _type = type;
    Rec2DElement *rel = Rec2DEdge::getUniqueElement(re0);
    if (!rel) {
      {
        Rec2DElement *elem[2];
        Rec2DEdge::getElements(re0, elem);
        int a, b = a = NULL;
        if (elem[0])
          a = elem[0]->getNum();
        if (elem[1])
          b = elem[1]->getNum();
        Rec2DEdge::getElements(re1, elem);
        int c, d = c = NULL;
        if (elem[0])
          c = elem[0]->getNum();
        if (elem[1])
          d = elem[1]->getNum();
        Msg::Error("[Rec2DElement] (edge %d %d -> edge %d %d)", a, b, c, d);
      }
      Msg::Error("[Rec2DDataChange] invalid swapping edges");
      _type = Error;
      _entity = _info = NULL;
      return;
    }
    _entity = rel;
    std::pair<Rec2DEdge*, Rec2DEdge*> *pairEdge;
    pairEdge = new std::pair<Rec2DEdge*, Rec2DEdge*>(re1, re0);
    _info = pairEdge;
    rel->swap(re0, re1);
    return;
  }
  _type = Error;
  _entity = _info = NULL;
}

void Rec2DChange::revert()
{
  //Msg::Info("revert %g (%d)", Rec2DData::getValVert(), _type);
  switch (_type) {
    case HideEdge :
      ((Rec2DEdge*)_entity)->reveal();
      break;
      
    case HideVertex :
      ((Rec2DVertex*)_entity)->reveal();
      break;
      
    case HideElement :
      ((Rec2DElement*)_entity)->reveal();
      break;
      
    case CreatedEdge :
      delete (Rec2DEdge*)_entity;
      break;
      
    case CreatedVertex :
      delete (Rec2DVertex*)_entity;
      break;
      
    case CreatedElement :
      delete (Rec2DElement*)_entity;
      break;
      
    case HideAction :
      ((Rec2DAction*)_entity)->reveal();
      break;
      
    case CreatedAction :
      {
        Rec2DAction *action = (Rec2DAction*)_entity;
        if (action->getInfant()) {
          action->hide();
          Rec2DData::addHidden(action);
        }
        else
          delete action;
      }
      break;
      
    case HideActions :
      {
        std::vector<Rec2DAction*> *vect = (std::vector<Rec2DAction*>*)_entity;
        for (unsigned int i = 0; i < vect->size(); ++i)
          (*vect)[i]->reveal();
        delete vect;
      }
      break;
      
    case CreatedActions :
      {
        std::vector<Rec2DAction*> *vect = (std::vector<Rec2DAction*>*)_entity;
        for (unsigned int i = 0; i < vect->size(); ++i)
          delete (*vect)[i];
        delete vect;
      }
      break;
      
    case SwapEdgeInAction :
      {
        std::vector<Rec2DAction*> *vect = (std::vector<Rec2DAction*>*)_entity;
        std::pair<Rec2DEdge*, Rec2DEdge*> *pairEdge;
        pairEdge = (std::pair<Rec2DEdge*, Rec2DEdge*>*)_info;
        for (unsigned int i = 0; i < vect->size(); ++i)
          (*vect)[i]->swap(pairEdge->first, pairEdge->second);
        delete vect;
        delete pairEdge;
      }
      break;
      
    case SwapEdgeInElem :
      {
        std::pair<Rec2DEdge*, Rec2DEdge*> *pairEdge;
        pairEdge = (std::pair<Rec2DEdge*, Rec2DEdge*>*)_info;
        ((Rec2DElement*)_entity)->swap(pairEdge->first, pairEdge->second);
        delete pairEdge;
      }
      break;
      
    case SwapVertInAction :
      {
        std::vector<Rec2DAction*> *vect = (std::vector<Rec2DAction*>*)_entity;
        std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
        pairVert = (std::pair<Rec2DVertex*, Rec2DVertex*>*)_info;
        for (unsigned int i = 0; i < vect->size(); ++i)
          (*vect)[i]->swap(pairVert->first, pairVert->second);
        delete vect;
        delete pairVert;
      }
      break;
      
    case SwapVertInEdge :
      {
        std::vector<Rec2DEdge*> *edges = (std::vector<Rec2DEdge*>*)_entity;
        std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
        pairVert = (std::pair<Rec2DVertex*, Rec2DVertex*>*)_info;
        for (unsigned int i = 0; i < edges->size(); ++i)
          (*edges)[i]->swap(pairVert->first, pairVert->second);
        delete edges;
        delete pairVert;
      }
      break;
      
    case RemoveElem :
      {
        std::vector<Rec2DElement*> *elem = (std::vector<Rec2DElement*>*)_info;
        for (unsigned int i = 0; i < elem->size(); ++i)
          ((Rec2DVertex*)_entity)->add((*elem)[i]);
        delete elem;
      }
      break;
      
    case AddElem :
      {
        std::vector<Rec2DElement*> *elem = (std::vector<Rec2DElement*>*)_info;
        for (unsigned int i = 0; i < elem->size(); ++i)
          ((Rec2DVertex*)_entity)->rmv((*elem)[i]);
        delete elem;
      }
      break;
      
    case Relocate :
      ((Rec2DVertex*)_entity)->relocate(*(SPoint2*)_info);
      delete (SPoint2*)_info;
      break;
      
    case ChangePar :
      ((Rec2DVertex*)_entity)->setParity(*(int*)_info);
      delete (int*)_info;
      break;
      
    case SavePar :
      {
        std::vector<Rec2DVertex*> *verts = (std::vector<Rec2DVertex*>*)_entity;
        std::vector<int> *parities = (std::vector<int>*)_info;
        for (unsigned int i = 0; i < verts->size(); ++i)
          (*verts)[i]->setParity((*parities)[i]);
        delete verts;
        delete parities;
      }
      break;
      
    case Error :
      Msg::Error("[Rec2DChange] There was an error");
      return;
      
    case Reverted :
      Msg::Error("[Rec2DChange] Multiple revert");
      return;
      
    default :
      Msg::Error("[Rec2DChange] Unknown type (%d)", _type);
      return;
  }
  _type = Reverted;
}


/**  Rec2DDataChange  **/
/***********************/
//void Rec2DDataChange::hide(Rec2DEdge *re)
//{
//  _hiddenEdge.push_back(re);
//  re->hide();
//}
//
//void Rec2DDataChange::hide(Rec2DVertex *rv)
//{
//  _hiddenVertex.push_back(rv);
//  rv->hide();
//}
//
//void Rec2DDataChange::hide(Rec2DElement *rel)
//{
//  _hiddenElement.push_back(rel);
//  rel->hide();
//}
//
//void Rec2DDataChange::hide(std::vector<Rec2DAction*> actions)
//{
//  _hiddenAction.insert(_hiddenAction.end(), actions.begin(), actions.end());
//  for (unsigned int i = 0; i < actions.size(); ++i) {
//    actions[i]->hide();
//  }
//}
//
//void Rec2DDataChange::hide(Rec2DAction *action)
//{
//  _hiddenAction.push_back(action);
//  action->hide();
//}
//
//void Rec2DDataChange::append(const Rec2DElement *rel)
//{
//  _newElement.push_back((Rec2DElement*)rel);
//}
//
//void Rec2DDataChange::append(const Rec2DAction *ra)
//{
//  _newAction.push_back((Rec2DAction*)ra);
//}
//
//void Rec2DDataChange::swapFor(Rec2DEdge *re1, Rec2DEdge *re2)
//{
//  Rec2DElement *rel = Rec2DEdge::getUniqueElement(re1);
//  if (!rel) {
//    Msg::Error("[Rec2DDataChange] invalid swapping edges");
//    return;
//  }
//  _edgeSwap.push_back(std::make_pair(rel, std::make_pair(re2, re1) ));
//  rel->swap(re1, re2);
//}
//
//void Rec2DDataChange::swapFor(Rec2DVertex *rv1, Rec2DVertex *rv2)
//{
//  std::vector<Rec2DElement*> elem;
//  rv1->getElements(elem);
//  for (unsigned int i = 0; i < elem.size(); ++i) {
//    _vertSwapEL.push_back(std::make_pair(elem[i], std::make_pair(rv2, rv1) ));
//    rv1->rmv(elem[i]);
//  }
//  std::vector<Rec2DEdge*> edges;
//  rv1->getEdges(edges);
//  for (unsigned int i = 0; i < edges.size(); ++i) {
//    _vertSwapE.push_back(std::make_pair(edges[i], std::make_pair(rv2, rv1) ));
//    edges[i]->swap(rv1, rv2);
//  }
//  for (unsigned int i = 0; i < elem.size(); ++i) {
//    rv2->add(elem[i]);
//  }
//}
//
//void Rec2DDataChange::relocate(Rec2DVertex *rv, double u, double v)
//{
//  _oldCoordinate.push_back(std::make_pair(rv, SPoint2(rv->u(), rv->v())));
//  rv->relocate(SPoint2(u, v));
//}
//
//void Rec2DDataChange::changeParity(Rec2DVertex *rv, int par)
//{
//  for (unsigned int i = 0; i < _oldParity.size(); ++i) {
//    if (_oldParity[i].first == rv)
//      return;
//  }
//  _oldParity.push_back(std::make_pair(rv, rv->getParity()));
//  rv->setParity(par);
//}
//
//void Rec2DDataChange::saveParity(std::vector<Rec2DVertex*> &vect)
//{
//  int sizeOldParity = _oldParity.size();
//  for (unsigned int i = 0; i < vect.size(); ++i) {
//    bool notThere = true;
//    for (int j = 0; j < sizeOldParity; ++j) {
//      if (_oldParity[j].first == vect[i])
//        notThere = false;
//    }
//    if (notThere) {
//      _oldParity.push_back(std::make_pair(vect[i], vect[i]->getParity()));
//    }
//  }
//}
//
void Rec2DDataChange::checkObsoleteActions(Rec2DVertex *const*verts, int size)
{
  std::vector<Rec2DAction*> actions;
  for (int i = 0; i < size; ++i) {
    verts[i]->getUniqueActions(actions);
  }
  for (unsigned int i = 0; i < actions.size(); ++i) {
    if (actions[i]->isObsolete())
      hide(actions[i]);
  }
}

//void Rec2DDataChange::revert()
//{
//  for (unsigned int i = 0; i < _oldParity.size(); ++i)
//    _oldParity[i].first->setParity(_oldParity[i].second);
//  for (unsigned int i = 0; i < _oldCoordinate.size(); ++i)
//    _oldCoordinate[i].first->relocate(_oldCoordinate[i].second);
//  
//  for (unsigned int i = 0; i < _newAction.size(); ++i)
//    delete _newAction[i];
//  for (unsigned int i = 0; i < _newElement.size(); ++i)
//    delete _newElement[i];
//  //for (unsigned int i = 0; i < _newEdge.size(); ++i)
//  //  delete _newEdge[i];
//  //for (unsigned int i = 0; i < _newVertex.size(); ++i)
//  //  delete _newVertex[i];
//  
//  for (unsigned int i = 0; i < _hiddenVertex.size(); ++i)
//    _hiddenVertex[i]->reveal();
//  for (unsigned int i = 0; i < _hiddenEdge.size(); ++i)
//    _hiddenEdge[i]->reveal();
//  
//  for (unsigned int i = 0; i < _edgeSwap.size(); ++i) {
//    _edgeSwap[i].first->swap(_edgeSwap[i].second.first,
//                             _edgeSwap[i].second.second);
//  }
//  for (unsigned int i = 0; i < _vertSwapE.size(); ++i) {
//    _vertSwapE[i].first->swap(_vertSwapE[i].second.first,
//                             _vertSwapE[i].second.second);
//  }
//  for (unsigned int i = 0; i < _vertSwapEL.size(); ++i) {
//    _vertSwapEL[i].first->swap(_vertSwapEL[i].second.first,
//                             _vertSwapEL[i].second.second);
//  }
//  
//  for (unsigned int i = 0; i < _hiddenElement.size(); ++i)
//    _hiddenElement[i]->reveal();
//  for (unsigned int i = 0; i < _hiddenAction.size(); ++i)
//    _hiddenAction[i]->reveal();
//  _oldParity.clear();
//  _oldCoordinate.clear();
//  //_newEdge.clear();
//  //_newVertex.clear();
//  _newAction.clear();
//  _newElement.clear();
//  _hiddenEdge.clear();
//  _hiddenVertex.clear();
//  _hiddenAction.clear();
//  _hiddenElement.clear();
//}

Rec2DDataChange::~Rec2DDataChange()
{
  for (unsigned int i = 0; i < _changes.size(); ++i)
    delete _changes[i];
}

void Rec2DDataChange::swapFor(Rec2DEdge *re0, Rec2DEdge *re1)
{
  std::vector<Rec2DAction*> actions;
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(re0, elem);
  if (elem[0]) {
    elem[0]->getUniqueActions(actions);
    if (elem[1])
      elem[1]->getUniqueActions(actions);
  }
  Rec2DAction::removeDuplicate(actions);
  _changes.push_back(new Rec2DChange(re0, re1, actions, SwapEdgeInAction));
  _changes.push_back(new Rec2DChange(re0, re1, SwapEdgeInElem));
}

void Rec2DDataChange::swapFor(Rec2DVertex *rv0, Rec2DVertex *rv1)
{
  std::vector<Rec2DElement*> elem;
  std::vector<Rec2DEdge*> edges;
  std::vector<Rec2DAction*> actions;
  rv0->getElements(elem);
  rv0->getEdges(edges);
  for (unsigned int i = 0; i < elem.size(); ++i) {
    elem[i]->getUniqueActions(actions);
  }
  Rec2DAction::removeDuplicate(actions);
  _changes.push_back(new Rec2DChange(rv0, rv1, actions, SwapVertInAction));
  _changes.push_back(new Rec2DChange(rv0, elem, RemoveElem));
  _changes.push_back(new Rec2DChange(rv0, rv1, edges, SwapVertInEdge));
  _changes.push_back(new Rec2DChange(rv1, elem, AddElem));
}

void Rec2DDataChange::revert()
{
  //Msg::Info("reverting");
  for (int i = (int)_changes.size() - 1; i > -1; --i)
    _changes[i]->revert();
  //Msg::Info(".");
}


/**  Rec2DAction  **/
/*******************/
bool lessRec2DAction::operator()(Rec2DAction *ra1, Rec2DAction *ra2) const
{
  return *ra1 < *ra2;
}

bool gterRec2DAction::operator()(Rec2DAction *ra1, Rec2DAction *ra2) const
{
  return *ra2 < *ra1;
}

Rec2DAction::Rec2DAction()
: _globQualIfExecuted(.0), _lastUpdate(-2)
{
  
}

bool Rec2DAction::operator<(Rec2DAction &other)
{
  return getReward() < other.getReward();
}

void Rec2DAction::removeDuplicate(std::vector<Rec2DAction*> &actions)
{
  unsigned int i = -1;
  while (++i < actions.size()) {
    Rec2DAction *ra = actions[i]->getBase();
    if (ra) for (unsigned int j = 0; j < actions.size(); ++j) {
      if (ra == actions[j]) {
        actions[i] = actions.back();
        actions.pop_back();
        --i;
        break;
      }
    }
  }
}

double Rec2DAction::getReward()
{
  if (_lastUpdate < Recombine2D::getNumChange())
    _computeGlobQual();
  
  return _globQualIfExecuted/* - Rec2DData::getGlobalQuality()*/;
}


/**  Rec2DTwoTri2Quad  **/
/************************/
Rec2DTwoTri2Quad::Rec2DTwoTri2Quad(Rec2DElement *el0, Rec2DElement *el1)
{
  _triangles[0] = el0;
  _triangles[1] = el1;
  _edges[4] = Rec2DElement::getCommonEdge(el0, el1);
  
  std::vector<Rec2DEdge*> edges;
  el0->getMoreEdges(edges);
  el1->getMoreEdges(edges);
  int k = -1;
  for (unsigned int i = 0; i < edges.size(); ++i) {
    if (edges[i] != _edges[4])
      _edges[++k] = edges[i];
  }
  if (k > 3)
    Msg::Error("[Rec2DTwoTri2Quad] too much edges");
  // reoder edges if needed
  if (edges[1] == _edges[4]) {
    Rec2DEdge *re = _edges[0];
    _edges[0] = _edges[1];
    _edges[1] = re;
  }
  if (edges[4] == _edges[4]) {
    Rec2DEdge *re = _edges[2];
    _edges[2] = _edges[3];
    _edges[3] = re;
  }
  
  _vertices[0] = _edges[4]->getVertex(0);
  _vertices[1] = _edges[4]->getVertex(1);
  _vertices[2] = _triangles[0]->getOtherVertex(_vertices[0], _vertices[1]);
  _vertices[3] = _triangles[1]->getOtherVertex(_vertices[0], _vertices[1]);
  
  _triangles[0]->add(this);
  _triangles[1]->add(this);
  Rec2DData::add(this);
}

void Rec2DTwoTri2Quad::hide()
{
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME changer le systme d'execution action");
  if (_triangles[0])
    _triangles[0]->remove(this);
  if (_triangles[1])
    _triangles[1]->remove(this);
  Rec2DData::remove(this);
}

void Rec2DTwoTri2Quad::reveal()
{
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME regarder si action sans son triangle");
  
  if (_triangles[0])
    _triangles[0]->add(this);
  if (_triangles[1])
    _triangles[1]->add(this);
  Rec2DData::add(this);
}

//void Rec2DTwoTri2Quad::print()
//{
//  Msg::Info("Printing Action %d |%d|%d|...", this, _triangles[0]->getNum(), _triangles[1]->getNum());
//  Msg::Info("edge0 %g (%g, %g)", _edges[0]->getQual(), _edges[0]->getQualL(), _edges[0]->getQualO());
//  Msg::Info("edge1 %g (%g, %g)", _edges[1]->getQual(), _edges[1]->getQualL(), _edges[1]->getQualO());
//  Msg::Info("edge2 %g (%g, %g)", _edges[2]->getQual(), _edges[2]->getQualL(), _edges[2]->getQualO());
//  Msg::Info("edge3 %g (%g, %g)", _edges[3]->getQual(), _edges[3]->getQualL(), _edges[3]->getQualO());
//  Msg::Info("edge4 %g (%g, %g)", _edges[4]->getQual(), _edges[4]->getQualL(), _edges[4]->getQualO());
//  Msg::Info("angles %g - %g", _vertices[0]->getAngle(), _vertices[1]->getAngle());
//  Msg::Info("merge0 %g", _vertices[0]->getGainMerge(_triangles[0], _triangles[1]));
//  Msg::Info("merge1 %g", _vertices[1]->getGainMerge(_triangles[0], _triangles[1]));
//  //_vertices[0]->printGainMerge(_triangles[0], _triangles[1]);
//  //_vertices[1]->printGainMerge(_triangles[0], _triangles[1]);
//}

void Rec2DTwoTri2Quad::printReward() const
{
  double valEdge1 = _edges[4]->getQual();
  double valEdge2 = 0;
  for (int i = 0; i < 4; ++i)
    valEdge2 += _edges[i]->getQual();
  
  double valVert;
  valVert = _vertices[0]->getGainMerge(_triangles[0], _triangles[1]);
  valVert += _vertices[1]->getGainMerge(_triangles[0], _triangles[1]);
  Msg::Info("-%de%g +%de%g +0v%g -> %g", REC2D_EDGE_BASE, valEdge1, 4 * REC2D_EDGE_QUAD,
            valEdge2/4, valVert/2,
            Rec2DData::getGlobalQuality(4*REC2D_EDGE_QUAD - REC2D_EDGE_BASE,
                                -REC2D_EDGE_BASE*valEdge1
                                +REC2D_EDGE_QUAD*valEdge2 , 0, valVert));
}

void Rec2DTwoTri2Quad::_computeGlobQual()
{
  double valEdge = -REC2D_EDGE_BASE * _edges[4]->getQual();
  for (int i = 0; i < 4; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
  
  if (_vertices[0]->getLastUpdate() > _lastUpdate ||
      _vertices[1]->getLastUpdate() > _lastUpdate   ) {
    _valVert = _vertices[0]->getGainMerge(_triangles[0], _triangles[1]);
    _valVert += _vertices[1]->getGainMerge(_triangles[0], _triangles[1]);
  }
  
  _globQualIfExecuted =
    Rec2DData::getGlobalQuality(4*REC2D_EDGE_QUAD - REC2D_EDGE_BASE,
                                valEdge, 0, valVert                 );
  
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DTwoTri2Quad::color(int a, int b, int c) const
{
#ifdef REC2D_DRAW
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  _triangles[0]->getMElement()->setCol(col);
  _triangles[1]->getMElement()->setCol(col);
#endif
}

void Rec2DTwoTri2Quad::apply(std::vector<Rec2DVertex*> &newPar)
{
  if (isObsolete()) {
    Msg::Error("[Rec2DTwoTri2Quad] No way ! I won't apply ! Find someone else...");
    return;
  }
  
  int min = Rec2DData::getNewParity(), index = -1;
  for (int i = 0; i < 4; ++i) {
    if (_vertices[i]->getParity() && min > _vertices[i]->getParity()) {
      min = _vertices[i]->getParity();
      index = i;
    }
  }
  if (index == -1) {
    _vertices[0]->setParity(min);
    _vertices[1]->setParity(min);
    _vertices[2]->setParity(min+1);
    _vertices[3]->setParity(min+1);
  }
  else {
    for (int i = 0; i < 4; i += 2) {
      int par;
      if ((index/2) * 2 == i)
        par = min;
      else
        par = otherParity(min);
      for (int j = 0; j < 2; ++j) {
        if (!_vertices[i+j]->getParity())
          _vertices[i+j]->setParity(par);
        else if (_vertices[i+j]->getParity() != par &&
                 _vertices[i+j]->getParity() != otherParity(par))
          Rec2DData::associateParity(_vertices[i+j]->getParity(), par);
      }
    }
  }
  
  _triangles[0]->remove(this);
  _triangles[1]->remove(this);
  
  std::vector<Rec2DAction*> actions;
  _triangles[0]->getUniqueActions(actions);
  _triangles[1]->getUniqueActions(actions);
  for (unsigned int i = 0; i < actions.size(); ++i)
    delete actions[i];
  
  delete _triangles[0];
  delete _triangles[1];
  _triangles[0] = NULL;
  _triangles[1] = NULL;
  delete _edges[4];
  
  new Rec2DElement((MQuadrangle*)NULL, (const Rec2DEdge**)_edges);
  
  Recombine2D::incNumChange();
}

void Rec2DTwoTri2Quad::apply(Rec2DDataChange *rdc) const
{
  //Msg::Info("Applying Rec2DTwoTri2Quad |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
  if (isObsolete()) {
    Msg::Error("[Rec2DTwoTri2Quad] I was obsolete !");
  }
  else {
    _doWhatYouHaveToDoWithParity(rdc);
  }
#ifdef REC2D_DRAW
  rdc->setAction(this);
#endif
  std::vector<Rec2DAction*> actions;
  _triangles[0]->getUniqueActions(actions);
  _triangles[1]->getUniqueActions(actions);
  rdc->hide(actions);
  rdc->hide(_triangles[0]);
  rdc->hide(_triangles[1]);
  rdc->hide(_edges[4]);
  rdc->append(new Rec2DElement((MQuadrangle*)NULL, (const Rec2DEdge**)_edges));
  Recombine2D::incNumChange();
  
  //Msg::Info(".");
}

void Rec2DTwoTri2Quad::_doWhatYouHaveToDoWithParity(Rec2DDataChange *rdc) const
{
  int parMin = Rec2DData::getNewParity(), index = -1;
  for (int i = 0; i < 4; ++i) {
    if (_vertices[i]->getParity() && parMin > _vertices[i]->getParity()) {
      parMin = _vertices[i]->getParity();
      index = i;
    }
  }
  if (index == -1) {
    rdc->changeParity(_vertices[0], parMin);
    rdc->changeParity(_vertices[1], parMin);
    rdc->changeParity(_vertices[2], parMin+1);
    rdc->changeParity(_vertices[3], parMin+1);
  }
  else {
    for (int i = 0; i < 4; i += 2) {
      int par;
      if ((index/2) * 2 == i)
        par = parMin;
      else
        par = otherParity(parMin);
      for (int j = 0; j < 2; ++j) {
        if (!_vertices[i+j]->getParity())
          rdc->changeParity(_vertices[i+j], par);
        else if (_vertices[i+j]->getParity() != par)
          Rec2DData::associateParity(_vertices[i+j]->getParity(), par, rdc);
      }
    }
    rdc->checkObsoleteActions(_vertices, 4);
    static int a = -1;
    if (++a < 1) Msg::Warning("FIXME should check obsolete ?");
  }
}

bool Rec2DTwoTri2Quad::isObsolete() const
{
  /*int n[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
  for (int i = 0; i < 4; ++i) {
    if (_vertices[i]) n[i] = _vertices[i]->getNum();
  }
  if (_triangles[0]) n[4] = _triangles[0]->getNum();
  if (_triangles[1]) n[5] = _triangles[1]->getNum();
  Msg::Info("%d %d %d %d | %d %d", n[0], n[1], n[2], n[3], n[4], n[5]);
  Msg::Info(" ");*/
  int p[4];
  p[0] = _vertices[0]->getParity();
  p[1] = _vertices[1]->getParity();
  p[2] = _vertices[2]->getParity();
  p[3] = _vertices[3]->getParity();
  return Rec2DTwoTri2Quad::isObsolete(p);
}

bool Rec2DTwoTri2Quad::isAssumedObsolete() const
{
  int p[4];
  p[0] = _vertices[0]->getAssumedParity();
  p[1] = _vertices[1]->getAssumedParity();
  p[2] = _vertices[2]->getAssumedParity();
  p[3] = _vertices[3]->getAssumedParity();
  return Rec2DTwoTri2Quad::isObsolete(p);
}

bool Rec2DTwoTri2Quad::isObsolete(const int *p)
{
  if (p[0] && p[0]/2 == p[1]/2 && p[0]%2 != p[1]%2 ||
      p[2] && p[2]/2 == p[3]/2 && p[2]%2 != p[3]%2 ||
      p[0] && (p[0] == p[2] || p[0] == p[3])       ||
      p[1] && (p[1] == p[2] || p[1] == p[3])         )
    return true;
  return false;
}

void Rec2DTwoTri2Quad::getAssumedParities(int *par) const
{
  par[0] = _vertices[0]->getAssumedParity();
  par[1] = _vertices[1]->getAssumedParity();
  par[2] = _vertices[2]->getAssumedParity();
  par[3] = _vertices[3]->getAssumedParity();
}

bool Rec2DTwoTri2Quad::whatWouldYouDo
  (std::map<Rec2DVertex*, std::vector<int> > &suggestions)
{
  int p[4];
  p[0] = _vertices[0]->getAssumedParity();
  p[1] = _vertices[1]->getAssumedParity();
  p[2] = _vertices[2]->getAssumedParity();
  p[3] = _vertices[3]->getAssumedParity();
  
  if (Rec2DTwoTri2Quad::isObsolete(p)) {
    return false;
  }
  
  int min = 100, index = -1;
  for (int i = 0; i < 4; ++i) {
    if (p[i] && min > p[i]) {
      min = p[i];
      index = i;
    }
  }
  if (index == -1) {
    Msg::Error("[Rec2DTwoTri2Quad] No parities ! That's not acceptable !");
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
  return true;
}

void Rec2DTwoTri2Quad::getElements(std::vector<Rec2DElement*> &elem) const
{
  elem.clear();
  elem.push_back(_triangles[0]);
  elem.push_back(_triangles[1]);
}

void Rec2DTwoTri2Quad::getNeighbourElements(std::vector<Rec2DElement*> &elem) const
{
  elem.clear();
  _triangles[0]->getMoreNeighbours(elem);
  _triangles[1]->getMoreNeighbours(elem);
  for (unsigned int i = 0; i < elem.size(); ++i) {
    if (elem[i] == _triangles[0] || elem[i] == _triangles[0]) {
      elem[i] = elem.back();
      elem.pop_back();
    }
  }
}

int Rec2DTwoTri2Quad::getNum(double shiftx, double shifty)
{
  MQuadrangle *quad;
  if (shiftx == .0 && shifty == .0)
    quad = new MQuadrangle(_vertices[0]->getMVertex(),
                           _vertices[2]->getMVertex(),
                           _vertices[1]->getMVertex(),
                           _vertices[3]->getMVertex());
  else {
    MVertex *v0 = new MVertex(_vertices[0]->getMVertex()->x() + shiftx,
                              _vertices[0]->getMVertex()->y() + shifty,
                              _vertices[0]->getMVertex()->z()          );
    MVertex *v1 = new MVertex(_vertices[1]->getMVertex()->x() + shiftx,
                              _vertices[1]->getMVertex()->y() + shifty,
                              _vertices[1]->getMVertex()->z()          );
    MVertex *v2 = new MVertex(_vertices[2]->getMVertex()->x() + shiftx,
                              _vertices[2]->getMVertex()->y() + shifty,
                              _vertices[2]->getMVertex()->z()          );
    MVertex *v3 = new MVertex(_vertices[3]->getMVertex()->x() + shiftx,
                              _vertices[3]->getMVertex()->y() + shifty,
                              _vertices[3]->getMVertex()->z()          );
    quad = new MQuadrangle(v0, v2, v1, v3);
  }
  Recombine2D::add(quad);
  return quad->getNum();
}

void Rec2DTwoTri2Quad::swap(Rec2DVertex *rv0, Rec2DVertex *rv1)
{
  for (int i = 0; i < 4; ++i) {
    if (_vertices[i] == rv0) {
      _vertices[i] = rv1;
      return;
    }
  }
  Msg::Error("[Rec2DTwoTri2Quad] Can't swap your vertex (%d -> %d)", rv0->getNum(), rv1->getNum());
  Msg::Warning("[Rec2DTwoTri2Quad] I have %d %d %d %d", _vertices[0]->getNum(), _vertices[1]->getNum(), _vertices[2]->getNum(), _vertices[3]->getNum());
}

void Rec2DTwoTri2Quad::swap(Rec2DEdge *re0, Rec2DEdge *re1)
{
  for (int i = 0; i < 4; ++i) {
    if (_edges[i] == re0) {
      _edges[i] = re1;
      return;
    }
  }
  Msg::Error("[Rec2DTwoTri2Quad] Can't swap your edge (is middle : %d)", re0 == _edges[4]);
}

Rec2DElement* Rec2DTwoTri2Quad::getRandomElement() const
{
  return _triangles[rand() % 2];
}


/**  Rec2DCollapse  **/
/*********************/
Rec2DCollapse::Rec2DCollapse(Rec2DTwoTri2Quad *rec) : _rec(rec)//,
//  _triangles(rec->_triangles), _edges(_rec->_edges), _vertices(_rec->_vertices)
{
  _rec->_col = this;
  _rec->_triangles[0]->add(this);
  _rec->_triangles[1]->add(this);
  Rec2DData::add(this);
}

void Rec2DCollapse::hide()
{
  if (_rec->_triangles[0])
    _rec->_triangles[0]->remove(this);
  if (_rec->_triangles[1])
    _rec->_triangles[1]->remove(this);
  Rec2DData::remove(this);
}

void Rec2DCollapse::reveal()
{
  if (_rec->_triangles[0])
    _rec->_triangles[0]->add(this);
  if (_rec->_triangles[1])
    _rec->_triangles[1]->add(this);
  Rec2DData::add(this);
}

void Rec2DCollapse::printReward() const
{
  std::vector<Rec2DVertex*> verts;
  std::vector<Rec2DEdge*> edges;
  _rec->_vertices[0]->getEdges(edges);
  for (unsigned int i = 0; i < edges.size(); ++i) {
    Rec2DVertex *v = edges[i]->getOtherVertex(_rec->_vertices[0]);
    bool toAdd = true;
    for (int j = 0; j < 4; ++j) {
      if (v == _rec->_vertices[j]) {
        toAdd = false;
        break;
      }
    }
    if (toAdd) verts.push_back(v);
  }
  _rec->_vertices[1]->getEdges(edges);
  for (unsigned int i = 0; i < edges.size(); ++i) {
    Rec2DVertex *v = edges[i]->getOtherVertex(_rec->_vertices[1]);
    bool toAdd = true;
    for (int j = 0; j < 4; ++j) {
      if (v == _rec->_vertices[j]) {
        toAdd = false;
        break;
      }
    }
    if (toAdd) verts.push_back(v);
  }
  
  _rec->_vertices[0]->getUniqueEdges(edges);
  _rec->_vertices[1]->getUniqueEdges(edges);
  int numEdgeBef = edges.size(), weightEdgeBef = 0;
  double valEdgeBef = 0;
  for (unsigned int i = 0; i < edges.size(); ++i) {
    valEdgeBef += edges[i]->getWeightedQual();
    weightEdgeBef += edges[i]->getWeight();
  }
  
  int numVertOther = verts.size();
  double vert01Bef = 0, vert23Bef = 0, vertOtherBef = 0;
  vert01Bef += _rec->_vertices[0]->getQual();
  vert01Bef += _rec->_vertices[1]->getQual();
  vert23Bef += _rec->_vertices[2]->getQual();
  vert23Bef += _rec->_vertices[3]->getQual();
  for (unsigned int i = 0; i < verts.size(); ++i) {
    vertOtherBef += verts[i]->getQual();
  }
  
  double d;
  Rec2DNode *n = new Rec2DNode(NULL, (Rec2DAction*)this, d, 0);
  n->makeChanges();
  
  edges.clear();
  _rec->_vertices[0]->getUniqueEdges(edges);
  _rec->_vertices[1]->getUniqueEdges(edges);
  int numEdgeAft = edges.size(), weightEdgeAft = 0;
  double valEdgeAft = 0;
  for (unsigned int i = 0; i < edges.size(); ++i) {
    valEdgeAft += edges[i]->getWeightedQual();
    weightEdgeAft += edges[i]->getWeight();
  }
  
  double vert01Aft = 0, vert23Aft = 0, vertOtherAft = 0;
  if (_rec->_vertices[0]->getNumElements())
    vert01Aft += _rec->_vertices[0]->getQual();
  if (_rec->_vertices[1]->getNumElements())
    vert01Aft += _rec->_vertices[1]->getQual();
  vert23Aft += _rec->_vertices[2]->getQual();
  vert23Aft += _rec->_vertices[3]->getQual();
  for (unsigned int i = 0; i < verts.size(); ++i) {
    vertOtherAft += verts[i]->getQual();
  }
  
  n->revertChanges();
  delete n;
  
  Msg::Info("-(%d)%de%g +(%d)%de%g "
            "-4v%g +2v%g +0v%g +(%d)0v%g", numEdgeBef, weightEdgeBef, valEdgeBef/weightEdgeBef,
                                           numEdgeAft, weightEdgeAft, valEdgeAft/weightEdgeAft,
                                           vert01Bef/4, vert01Aft/2, (vert23Aft-vert23Bef)/2,
                                           numVertOther, vertOtherAft-vertOtherBef);
}

void Rec2DCollapse::_computeGlobQual()
{
  delete (new Rec2DNode(NULL, this, _globQualIfExecuted, 0));
}

void Rec2DCollapse::apply(std::vector<Rec2DVertex*> &newPar)
{
  static int a = -1;
  if (++a < 1) Msg::Error("FIXME Need definition Rec2DTwoTri2Quad::apply(newPar)");
}

void Rec2DCollapse::apply(Rec2DDataChange *rdc) const
{
  //Msg::Info("Applying Rec2DCollapse |%d|%d|", _rec->_triangles[0]->getNum(), _rec->_triangles[1]->getNum());
  if (isObsolete()) {
    Msg::Error("[Rec2DTwoTri2Quad] I was obsolete !");
  }
#ifdef REC2D_DRAW
  rdc->setAction(this);
#endif
  std::vector<Rec2DAction*> actions;
  _rec->_triangles[0]->getUniqueActions(actions);
  _rec->_triangles[1]->getUniqueActions(actions);
  rdc->hide(actions);
  rdc->hide(_rec->_triangles[0]);
  rdc->hide(_rec->_triangles[1]);
  rdc->hide(_rec->_edges[4]);
  //Msg::Info("v-%g", Rec2DData::getValVert());
  Rec2DVertex *vOK, *vKO;
  if (_rec->_vertices[0]->getOnBoundary()) {
    SPoint2 p(_rec->_vertices[0]->u(), _rec->_vertices[0]->v());
    rdc->relocate(_rec->_vertices[1], p);
    vOK = _rec->_vertices[0];
    vKO = _rec->_vertices[1];
  }
  else if (_rec->_vertices[1]->getOnBoundary()) {
    SPoint2 p(_rec->_vertices[1]->u(), _rec->_vertices[1]->v());
    rdc->relocate(_rec->_vertices[0], p);
    vOK = _rec->_vertices[1];
    vKO = _rec->_vertices[0];
  }
  else {
    double u = (_rec->_vertices[0]->u() + _rec->_vertices[1]->u()) / 2;
    double v = (_rec->_vertices[0]->v() + _rec->_vertices[1]->v()) / 2;
    rdc->relocate(_rec->_vertices[1], SPoint2(u, v));
    //Msg::Info("v.%g", Rec2DData::getValVert());
    rdc->relocate(_rec->_vertices[0], SPoint2(u, v));
    vOK = _rec->_vertices[0];
    vKO = _rec->_vertices[1];
  }
  //Msg::Info("v--%g", Rec2DData::getValVert());
  bool edge12KO = _rec->_edges[1]->getVertex(0) == vKO ||
                  _rec->_edges[1]->getVertex(1) == vKO   ;
  rdc->swapFor(vKO, vOK);
  //Msg::Info("v---%g", Rec2DData::getValVert());
  rdc->hide(vKO);
  //Msg::Info("v----%g", Rec2DData::getValVert());
  
  int i0, i1, i2, i3;
  if (edge12KO) {
    i0 = 1; i1 = 2;
    i2 = 0; i3 = 3;
  }
  else {
    i0 = 0; i1 = 3;
    i2 = 1; i3 = 2;
  }
  {
    rdc->swapFor(_rec->_edges[i0], _rec->_edges[i2]);
    rdc->swapFor(_rec->_edges[i1], _rec->_edges[i3]);
    rdc->hide(_rec->_edges[i0]);
    rdc->hide(_rec->_edges[i1]);
    Rec2DElement *elem[2];
    Rec2DTwoTri2Quad *newAction;
    Rec2DEdge::getElements(_rec->_edges[i2], elem);
    if (elem[1] && elem[0]->isTri() && elem[1]->isTri()) {
      newAction = new Rec2DTwoTri2Quad(elem[0], elem[1]);
      rdc->append(new Rec2DCollapse(newAction));
      rdc->append(newAction);
    }
    Rec2DEdge::getElements(_rec->_edges[i3], elem);
    if (elem[1] && elem[0]->isTri() && elem[1]->isTri()) {
      newAction = new Rec2DTwoTri2Quad(elem[0], elem[1]);
      rdc->append(new Rec2DCollapse(newAction));
      rdc->append(newAction);
    }
  }
  
  int parKO, parOK;
  if ((parKO = vKO->getParity())) {
    if (!(parOK = vOK->getParity())) {
      rdc->changeParity(vOK, parKO);
      Rec2DVertex *v[1] = {vOK};
      rdc->checkObsoleteActions(v, 1);
    }
    else if (parOK/2 != parKO/2) {
      Rec2DData::associateParity(std::max(parOK, parKO), std::min(parOK, parKO), rdc);
    }
  }
  
  Recombine2D::incNumChange();
  //Msg::Info(".");
  //Msg::Info("v-----%g", Rec2DData::getValVert());
}

bool Rec2DCollapse::isObsolete() const
{
  int p[2];
  p[0] = _rec->_vertices[0]->getParity();
  p[1] = _rec->_vertices[1]->getParity();
  return Rec2DCollapse::isObsolete(p) ||
         (_rec->_vertices[0]->getOnBoundary() &&
          _rec->_vertices[1]->getOnBoundary()   );
}

bool Rec2DCollapse::isAssumedObsolete() const
{
  int p[2];
  p[0] = _rec->_vertices[0]->getAssumedParity();
  p[1] = _rec->_vertices[1]->getAssumedParity();
  return Rec2DCollapse::isObsolete(p) ||
         (_rec->_vertices[0]->getOnBoundary() &&
          _rec->_vertices[1]->getOnBoundary()   );
}

bool Rec2DCollapse::isObsolete(const int *p)
{
  if (p[0] && p[0]/2 == p[1]/2 && p[0]%2 != p[1]%2)
    return true;
  return false;
}

void Rec2DCollapse::getAssumedParities(int *par) const
{
  static int a = -1;
  if (++a < 1) Msg::Error("FIXME Rec2DTwoTri2Quad::getAssumedParities not ok");
}

bool Rec2DCollapse::whatWouldYouDo
  (std::map<Rec2DVertex*, std::vector<int> > &suggestions)
{
  static int a = -1;
  if (++a < 1) Msg::Error("FIXME Need definition Rec2DTwoTri2Quad::whatWouldYouDo");
  return false;
}


/**  Rec2DEdge  **/
/*****************/
Rec2DEdge::Rec2DEdge(Rec2DVertex *rv0, Rec2DVertex *rv1)
: _rv0(rv0), _rv1(rv1), _lastUpdate(-2),
  _weight(REC2D_EDGE_BASE+2*REC2D_EDGE_QUAD), _boundary(-1)
{
  reveal();
}

void Rec2DEdge::hide()
{
  _rv0->rmv(this);
  _rv1->rmv(this);
  Rec2DData::remove(this);
  Rec2DData::addEdge(-_weight, -getWeightedQual());
}

void Rec2DEdge::reveal()
{
  _rv0->add(this);
  _rv1->add(this);
  Rec2DData::add(this);
  Rec2DData::addEdge(_weight, getWeightedQual());
}

void Rec2DEdge::_computeQual()
{
  double alignment = _straightAlignment();
  double adimLength = _straightAdimLength();
  if (adimLength > 1)
    adimLength = 1./adimLength;
  _qual = adimLength * ((double)(1-REC2D_ALIGNMENT) + (double)REC2D_ALIGNMENT * alignment);
  _lastUpdate = Recombine2D::getNumChange();
}

//double Rec2DEdge::getQualL() const
//{
//  double adimLength = _straightAdimLength();
//  if (adimLength > 1)
//    ;//adimLength = 1./adimLength;
//  return adimLength;
//}
//
//double Rec2DEdge::getQualO() const
//{
//  Msg::Info("o (%g %g) %g", Recombine2D::bgm()->getAngle(_rv0->u(), _rv0->v(), .0)
//                          , Recombine2D::bgm()->getAngle(_rv1->u(), _rv1->v(), .0)
//                          , atan2(_rv0->u()-_rv1->u(), _rv0->v()-_rv1->v()));
//  return _straightAlignment();
//}
//
void Rec2DEdge::print() const
{
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  int a, b = a = NULL;
  if (elem[0])
    a = elem[0]->getNum();
  if (elem[1])
    b = elem[1]->getNum();
  
  Msg::Info(" edge , %d--%d , %d/%d", _rv0->getNum(), _rv1->getNum(), a, b);
}

void Rec2DEdge::_addWeight(int w)
{
  _weight += w;
  if (_weight > REC2D_EDGE_BASE + 2*REC2D_EDGE_QUAD) {
    Rec2DElement *elem[2];
    Rec2DEdge::getElements(this, elem);
    int a, b = a = NULL;
    if (elem[0])
      a = elem[0]->getNum();
    if (elem[1])
      b = elem[1]->getNum();
    Msg::Error("[Rec2DEdge] Weight too high : %d (%d max) (im %d %d)",
               _weight, REC2D_EDGE_BASE + 2*REC2D_EDGE_QUAD, a, b     );
  }
  if (_weight < REC2D_EDGE_BASE)
    Msg::Error("[Rec2DEdge] Weight too low : %d (%d min)",
               _weight, REC2D_EDGE_BASE                   );
  Rec2DData::addEdge(w, (double)w*getQual());
}

void Rec2DEdge::updateQual()
{
  double oldQual = _qual;
  _computeQual();
  Rec2DData::addValEdge(_weight*(_qual-oldQual));
  _lastUpdate = Recombine2D::getNumChange();
}

Rec2DElement* Rec2DEdge::getUniqueElement(const Rec2DEdge *re)
{
  std::vector<Rec2DElement*> elem;
  Rec2DVertex::getCommonElements(re->getVertex(0), re->getVertex(1), elem);
  unsigned int i = 0;
  while (i < elem.size()) {
    if (!elem[i]->has(re)) {
      elem[i] = elem.back();
      elem.pop_back();
    }
    else
      ++i;
  }
  if (elem.size() == 1)
    return elem[0];
  if (elem.size() != 0) {
    Msg::Info("size(%d) %d %d", elem.size(), elem[0]->getNum(), elem[1]->getNum());
    Msg::Error("[Rec2DEdge] Edge bound %d elements, returning NULL", elem.size());
  }
  return NULL;
}

void Rec2DEdge::getElements(const Rec2DEdge *re, Rec2DElement **elem)
{
  elem[0] = NULL;
  elem[1] = NULL;
  std::vector<Rec2DElement*> vectElem;
  Rec2DVertex::getCommonElements(re->getVertex(0), re->getVertex(1), vectElem);
  unsigned int i = 0;
  while (i < vectElem.size()) {
    if (!vectElem[i]->has(re)) {
      vectElem[i] = vectElem.back();
      vectElem.pop_back();
    }
    else
      ++i;
  }
  switch (vectElem.size()) {
    case 2 :
      elem[1] = vectElem[1];
    case 1 :
      elem[0] = vectElem[0];
      return;
    case 0 :
      return;
    default :
      Msg::Error("[Rec2DEdge] my integrity is not respected :'(");
  }
}

void Rec2DEdge::swap(Rec2DVertex *oldRV, Rec2DVertex *newRV, bool upVert)
{
  if (upVert) {
    oldRV->rmv(this);
    newRV->add(this);
  }
  if (_rv0 == oldRV) {
    _rv0 = newRV;
    return;
  }
  if (_rv1 == oldRV) {
    _rv1 = newRV;
    return;
  }
  Msg::Error("[Rec2DEdge] oldRV not found");
}

double Rec2DEdge::_straightAdimLength() const
{
  double dx, dy, dz, *xyz0 = new double[3], *xyz1 = new double[3];
  _rv0->getxyz(xyz0);
  _rv1->getxyz(xyz1);
  dx = xyz0[0] - xyz1[0];
  dy = xyz0[1] - xyz1[1];
  dz = xyz0[2] - xyz1[2];
  double length = sqrt(dx * dx + dy * dy + dz * dz);
  delete[] xyz0;
  delete[] xyz1;
  
  double lc0 = (*Recombine2D::bgm())(_rv0->u(), _rv0->v(), .0);
  double lc1 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  
  return length * (1./lc0 + 1./lc1) / 2.;
}

double Rec2DEdge::_straightAlignment() const
{
  double angle0 = Recombine2D::bgm()->getAngle(_rv0->u(), _rv0->v(), .0);
  double angle1 = Recombine2D::bgm()->getAngle(_rv1->u(), _rv1->v(), .0);
  double angleEdge = atan2(_rv0->v()-_rv1->v(), _rv0->u()-_rv1->u());
  
  double alpha0 = angleEdge - angle0;
  double alpha1 = angleEdge - angle1;
  crossField2d::normalizeAngle(alpha0);
  crossField2d::normalizeAngle(alpha1);
  alpha0 = 1. - 4. * std::min(alpha0, .5 * M_PI - alpha0) / M_PI;
  alpha1 = 1. - 4. * std::min(alpha1, .5 * M_PI - alpha1) / M_PI;
  
  double lc0 = (*Recombine2D::bgm())(_rv0->u(), _rv0->v(), .0);
  double lc1 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  
  return (alpha0/lc0 + alpha1/lc1) / (1./lc0 + 1./lc1);
}

Rec2DVertex* Rec2DEdge::getOtherVertex(const Rec2DVertex *rv) const
{
  if (rv == _rv0)
    return _rv1;
  if (rv == _rv1)
    return _rv0;
  Msg::Error("[Rec2DEdge] You are wrong, I don't have this vertex !");
  return NULL;
}

void Rec2DEdge::getActions(std::vector<Rec2DAction*> &actions) const
{
  actions.clear();
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  if (elem[0]) {
    elem[0]->getUniqueActions(actions);
    if (elem[1])
      elem[1]->getUniqueActions(actions);
  }
  
}


/**  Rec2DVertex  **/
/*******************/
Rec2DVertex::Rec2DVertex(MVertex *v)
: _v(v), _angle(4.*M_PI), _onWhat(1), _parity(0), _assumedParity(0),
  _lastUpdate(Recombine2D::getNumChange()), _sumQualAngle(.0)
{
  reparamMeshVertexOnFace(_v, Recombine2D::getGFace(), _param);
  Rec2DData::add(this);
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
}

Rec2DVertex::Rec2DVertex(Rec2DVertex *rv, double ang)
: _v(rv->_v), _angle(ang), _onWhat(-1), _parity(rv->_parity),
  _assumedParity(rv->_assumedParity), _lastUpdate(rv->_lastUpdate),
  _sumQualAngle(rv->_sumQualAngle), _edges(rv->_edges),
  _elements(rv->_elements), _param(rv->_param)
{
  static int a = -1;
  if (++a < -1) Msg::Warning("FIXME Edges really necessary ?");
  
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    _edges[i]->swap(rv, this, false);
  }
  Rec2DData::add(this);
  if (_elements.size())
    Rec2DData::addVert(2, getQual());
  delete rv;
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DVertex::hide()
{
  if (_elements.size() || _edges.size())
    Msg::Error("[Rec2DVertex] I have %d elements and %d edges", _elements.size(), _edges.size());
  if (_parity)
    Rec2DData::removeParity(this, _parity);
  if (_assumedParity)
    Rec2DData::removeAssumedParity(this, _assumedParity);
  
  Rec2DData::remove(this);
  if  (_elements.size()) {
    Msg::Error("[Rec2DVertex] normal ?");
    Rec2DData::addVert(-2, -getQual());
  }
}

void Rec2DVertex::reveal()
{
  if (_parity)
    Rec2DData::addParity(this, _parity);
  if (_assumedParity)
    Rec2DData::addAssumedParity(this, _assumedParity);
  
  Rec2DData::add(this);
  if  (_elements.size())
    Rec2DData::addVert(2, getQual());
}

void Rec2DVertex::initStaticTable()
{
  // _qualVSnum[onWhat][numEl]; onWhat={0:edge,1:face}
  // _gains[onWhat][numEl];     onWhat={0:edge,1:face} (earning of adding an element)
  if (_qualVSnum == NULL) {
    int nE = 10, nF = 20; //edge, face
    
    _qualVSnum = new double*[2];
    _qualVSnum[0] = new double[nE];
    _qualVSnum[1] = new double[nF];
    _qualVSnum[0][0] = -10.;
    _qualVSnum[1][0] = -10.;
    for (int i = 1; i < nE; ++i)
      _qualVSnum[0][i] = 1. - fabs(2./(double)i - 1.);
    for (int i = 1; i < nF; ++i)
      _qualVSnum[1][i] = 1. - fabs(4./(double)i - 1.);
      
    _gains = new double*[2];
    _gains[0] = new double[nE-1];
    for (int i = 0; i < nE-1; ++i)
      _gains[0][i] = _qualVSnum[0][i+1] - _qualVSnum[0][i];
    _gains[1] = new double[nF-1];
    for (int i = 0; i < nF-1; ++i)
      _gains[1][i] = _qualVSnum[1][i+1] - _qualVSnum[1][i];
  }
}

Rec2DEdge* Rec2DVertex::getCommonEdge(const Rec2DVertex *rv0,
                                      const Rec2DVertex *rv1 )
{
  for (unsigned int i = 0; i < rv0->_edges.size(); ++i) {
    if (rv1->has(rv0->_edges[i]))
      return rv0->_edges[i];
  }
  //Msg::Warning("[Rec2DVertex] didn't find edge, returning NULL");
  return NULL;
}

void Rec2DVertex::getCommonElements(const Rec2DVertex *rv0,
                                    const Rec2DVertex *rv1,
                                    std::vector<Rec2DElement*> &elem)
{
  for (unsigned int i = 0; i < rv0->_elements.size(); ++i) {
    if (rv1->has(rv0->_elements[i]))
      elem.push_back(rv0->_elements[i]);
  }
}

bool Rec2DVertex::setBoundaryParity(int p0, int p1)
{
  if (_parity) {
    Msg::Error("[Rec2DVertex] Are you kidding me ? Already have a parity !");
    return false;
  }
  setParity(p0);
  int num = 0;
  Rec2DVertex *nextRV = NULL;
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i]->isOnBoundary()) {
      nextRV = _edges[i]->getOtherVertex(this);
      ++num;
    }
  }
  if (num != 2)
    Msg::Error("[Rec2DVertex] What's happening ? Am I on boundary or not ? TELL ME !");
  if (nextRV)
    return nextRV->_recursiveBoundParity(this, p1, p0); // alternate parity
  Msg::Error("[Rec2DVertex] Have I really to say that I didn't find neighbouring vertex ?");
  return false;
}

bool Rec2DVertex::_recursiveBoundParity(const Rec2DVertex *prevRV, int p0, int p1)
{
  if (_parity == p0)
    return true;
  if (_parity) {
    Msg::Error("[Rec2DVertex] Sorry, have parity %d, can't set it to %d... "
               "You failed ! Try again !", _parity, p0);
    return false;
  }
  setParity(p0);
  int num = 0;
  Rec2DVertex *nextRV = NULL;
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i]->isOnBoundary() && _edges[i]->getOtherVertex(this) != prevRV) {
      nextRV = _edges[i]->getOtherVertex(this);
      ++num;
    }
  }
  if (num != 1)
    Msg::Error("[Rec2DVertex] Holy shit !");
  if (nextRV)
    return nextRV->_recursiveBoundParity(this, p1, p0); // alternate parity
  Msg::Error("[Rec2DVertex] Have I really to say that I didn't find next vertex ?");
  return false;
}

void Rec2DVertex::setOnBoundary()
{
  if (_onWhat > 0) {
    Rec2DData::addValVert(-getQual());
    _onWhat = 0;
    Rec2DData::addValVert(getQual());
    _lastUpdate = Recombine2D::getNumChange();
  }
}

void Rec2DVertex::setParity(int p, bool tree)
{
  if (_parity && !tree) {
    //Msg::Warning("[Rec2DVertex] I don't like to do it. Think about that !");
    Rec2DData::removeParity(this, _parity);
  }
  _parity = p;
  if (_assumedParity) {
    Rec2DData::removeAssumedParity(this, _assumedParity);
    _assumedParity = 0;
  }
  if (_parity)
    Rec2DData::addParity(this, _parity);
#ifdef REC2D_DRAW
  if (_v)
    //_v->setIndex(_parity);
    _v->setIndex(_onWhat);
#endif
}

void Rec2DVertex::setParityWD(int pOld, int pNew)
{
  static int a = -1;
  if (++a < 1)
    Msg::Warning("FIXME puis-je rendre fonction utilisable uniquement par recdata ?");
  if (pOld != _parity)
    Msg::Error("[Rec2DVertex] Old parity was not correct");
  _parity = pNew;
  if (_assumedParity) {
    Rec2DData::removeAssumedParity(this, _assumedParity);
    _assumedParity = 0;
  }
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
}

int Rec2DVertex::getAssumedParity() const
{
  if (_assumedParity)
    return _assumedParity;
  return _parity;
}

bool Rec2DVertex::setAssumedParity(int p)
{
  if (p == _assumedParity) {
    //Msg::Warning("[Rec2DVertex] Already have this assumed parity");
    return false;
  }
  if (p == _parity) {
    Msg::Warning("[Rec2DVertex] Parity already this value (%d, %d) -> %d",
                 _parity, _assumedParity, p);
    return false;
  }
  Rec2DData::saveAssumedParity(this, _assumedParity);
  if (_assumedParity) {
    Rec2DData::removeAssumedParity(this, _assumedParity);
  }
  _assumedParity = p;
  Rec2DData::addAssumedParity(this, _assumedParity);
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_assumedParity);
    //_v->setIndex(_onWhat);
#endif
  return true;
}

void Rec2DVertex::setAssumedParityWD(int pOld, int pNew)
{
  static int a = -1;
  if (++a < 1)
    Msg::Warning("FIXME puis-je rendre fonction utilisable uniquement par recdata ?");
  if (pOld != _assumedParity)
    Msg::Error("[Rec2DVertex] Old assumed parity was not correct");
  Rec2DData::saveAssumedParity(this, _assumedParity);
  _assumedParity = pNew;
}

void Rec2DVertex::revertAssumedParity(int p)
{
  if (p == _parity) {
    if (_assumedParity) {
      Rec2DData::removeAssumedParity(this, _assumedParity);
      _assumedParity = 0;
    }
  }
  else {
    if (_assumedParity) {
      Rec2DData::removeAssumedParity(this, _assumedParity);
    }
    _assumedParity = p;
    Rec2DData::addAssumedParity(this, _assumedParity);
  }
}

void Rec2DVertex::relocate(SPoint2 p)
{
  /*static int a = -1;
  if(++a < 1)
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    double d = _elements[i]->getAngle(this);
    Msg::Info("%d - %g", i, d);
  }*/
  _param = p;
  GPoint gpt = Recombine2D::getGFace()->point(p);
  _v->x() = gpt.x();
  _v->y() = gpt.y();
  _v->z() = gpt.z();
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    _edges[i]->updateQual();
    _edges[i]->getOtherVertex(this)->_updateQualAngle();
  }
  _updateQualAngle();
  /*for (unsigned int i = 0; i < _elements.size(); ++i) {
    double d = _elements[i]->getAngle(this);
    Msg::Info("%d - %g", i, d);
  }*/
}

void Rec2DVertex::_updateQualAngle()
{
  //Msg::Info("old : %g", _getQualAngle());
  double oldQualAngle = _getQualAngle();
  _sumQualAngle = .0;
  for (unsigned int i = 0; i < _elements.size(); ++i)
    _sumQualAngle += _angle2Qual(_elements[i]->getAngle(this));
  Rec2DData::addValVert(_getQualAngle()-oldQualAngle);
  //Msg::Info("new : %g", _getQualAngle());
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DVertex::getTriangles(std::set<Rec2DElement*> &tri) const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i]->isTri())
      tri.insert(_elements[i]);
  }
}

void Rec2DVertex::getElements(std::vector<Rec2DElement*> &elem) const
{
  elem.clear();
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    elem.push_back(_elements[i]);
  }
}

void Rec2DVertex::getUniqueEdges(std::vector<Rec2DEdge*> &edges) const
{
  unsigned int size = edges.size();
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    unsigned int j = -1;
    while (++j < size && edges[j] != _edges[i]);
    if (j == size)
      edges.push_back(_edges[i]);
  }
}

double Rec2DVertex::getQualDegree(int numEl) const
{
  int nEl = numEl > -1 ? numEl : _elements.size();
  if (_onWhat > -1)
    return _qualVSnum[_onWhat][nEl];
  if (nEl == 0) {
    Msg::Error("[Rec2DVertex] I don't want this anymore !");
    return -10.;
  }
  return 1. - fabs(2./M_PI * _angle/(double)nEl - 1.);
}

double Rec2DVertex::getGainDegree(int n) const
{
  if (!n)
    return .0;
  if (_elements.size() + n < 0) {
    Msg::Error("[Rec2DVertex] gain for %d elements unavailable",
               _elements.size() + n                             );
    return .0;
  }
  
  if (_onWhat > -1) {
    switch (n) {
      case 1 :
        return _gains[_onWhat][_elements.size()];
      case -1 :
        return - _gains[_onWhat][_elements.size()-1];
      default :
        return _qualVSnum[_onWhat][_elements.size()+n]
               - _qualVSnum[_onWhat][_elements.size()-1];
    }
  }
  
  if (_elements.size() == 0) {
    Msg::Error("[Rec2DVertex] I don't want this anymore !");
    return 11. - fabs(2./M_PI * _angle/(double)(_elements.size() + n) - 1.);
  }
  
  if (_elements.size() + n == 0) {
    Msg::Error("[Rec2DVertex] I don't want this anymore !");
    return fabs(2./M_PI * _angle/(double)_elements.size() - 1.) - 11.;
  }
  
  return fabs(2./M_PI * _angle/(double)_elements.size() - 1.)
         - fabs(2./M_PI * _angle/(double)(_elements.size() + n) - 1.);
}

double Rec2DVertex::getGainMerge(const Rec2DElement *rel1,
                                 const Rec2DElement *rel2 ) const
{
  double qualAngle = _sumQualAngle;
  qualAngle -= _angle2Qual(rel1->getAngle(this));
  qualAngle -= _angle2Qual(rel2->getAngle(this));
  qualAngle += _angle2Qual(rel1->getAngle(this) + rel2->getAngle(this));
  
  return qualAngle / (double)(_elements.size()-1) - getQualAngle()
         + getGainDegree(-1);
}

void Rec2DVertex::add(Rec2DEdge *re)
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re) {
      Msg::Error("[Rec2DVertex] Edge was already there");
      return;
    }
  }
  _edges.push_back(re);
}

bool Rec2DVertex::has(Rec2DEdge *re) const
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re)
      return true;
  }
  return false;
}

void Rec2DVertex::rmv(Rec2DEdge *re)
{
  unsigned int i = 0;
  while (i < _edges.size()) {
    if (_edges[i] == re) {
      _edges[i] = _edges.back();
      _edges.pop_back();
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DVertex] Didn't removed edge, didn't have it");
}

void Rec2DVertex::add(Rec2DElement *rel)
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel) {
      Msg::Error("[Rec2DVertex] Element was already there");
      return;
    }
  }
  if (_elements.size())
    Rec2DData::addVert(-2, -getQual());
  
  _elements.push_back(rel);
  _sumQualAngle += _angle2Qual(rel->getAngle(this));
  Rec2DData::addVert(2, getQual());
  _lastUpdate = Recombine2D::getNumChange();
}

bool Rec2DVertex::has(Rec2DElement *rel) const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel)
      return true;
  }
  return false;
}

void Rec2DVertex::rmv(Rec2DElement *rel)
{
  unsigned int i = 0;
  while (i < _elements.size()) {
    if (_elements[i] == rel) {
      Rec2DData::addVert(-2, -getQual());
      _sumQualAngle -= _angle2Qual(_elements[i]->getAngle(this));
      _elements[i] = _elements.back();
      _elements.pop_back();
      
      if (_elements.size())
        Rec2DData::addVert(2, getQual());
      _lastUpdate = Recombine2D::getNumChange();
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DVertex] Didn't removed element, didn't have it");
}

void Rec2DVertex::getUniqueActions(std::vector<Rec2DAction*> &actions) const
{
  std::vector<Rec2DAction*> actions2;
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    _elements[i]->getUniqueActions(actions2);
  }
  unsigned int size = actions.size();
  for (unsigned int i = 0; i < actions2.size(); ++i) {
    bool notThere = true;
    for (unsigned int j = 0; j < size; ++j) {
      if (actions2[i] == actions[j])
        notThere = false;
    }
    if (notThere)
      actions.push_back(actions2[i]);
  }
}


/**  Rec2DElement  **/
/********************/
Rec2DElement::Rec2DElement(MTriangle *t, const Rec2DEdge **re, Rec2DVertex **rv)
: _mEl((MElement *)t), _numEdge(3)
{
  for (int i = 0; i < 3; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 3; ++i)
    _elements[i] = Rec2DEdge::getUniqueElement(_edges[i]);
  _edges[3] = NULL;
  _elements[3] = NULL;
  
  reveal(rv);
}

Rec2DElement::Rec2DElement(MQuadrangle *q, const Rec2DEdge **re, Rec2DVertex **rv)
: _mEl((MElement *)q), _numEdge(4)
{
  for (int i = 0; i < 4; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 4; ++i)
    _elements[i] = Rec2DEdge::getUniqueElement(_edges[i]);
  
  reveal(rv);
}

void Rec2DElement::hide()
{
  if (_actions.size())
    Msg::Error("[Rec2DElement] I didn't want to be hidden :'(");
  for (int i = 0; i < _numEdge; ++i) {
    if (_numEdge == 3)
      _edges[i]->remHasTri();
    else
      _edges[i]->remHasQuad();
    if (_elements[i])
      _elements[i]->rmvNeighbour(_edges[i], this);
  }
  std::vector<Rec2DVertex*> vertices(_numEdge);
  getVertices(vertices);
  for (int i = 0; i < _numEdge; ++i) {
    vertices[i]->rmv(this);
  }
  Rec2DData::remove(this);
}

void Rec2DElement::reveal(Rec2DVertex **rv)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_numEdge == 3)
      _edges[i]->addHasTri();
    else
      _edges[i]->addHasQuad();
    if (_elements[i])
      _elements[i]->addNeighbour(_edges[i], this);
  }
  
  if (rv) {
    for (int i = 0; i < _numEdge; ++i)
      rv[i]->add(this);
  }
  else {
    std::vector<Rec2DVertex*> vert;
    getVertices(vert);
    for (int i = 0; i < _numEdge; ++i)
      vert[i]->add(this);
  }
  Rec2DData::add(this);
}

void Rec2DElement::add(Rec2DEdge *re)
{
  int i;
  for (i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      Msg::Error("[Rec2DElement] Edge was already there");
      return;
    }
    if (_edges[i] == NULL) {
      _edges[i] = re;
      break;
    }
  }
  if (i == _numEdge)
    Msg::Error("[Rec2DElement] Already %d edges, can't add anymore", _numEdge);
  
  if (_numEdge == 3)
    re->addHasTri();
  else
    re->addHasQuad();
}

bool Rec2DElement::has(const Rec2DEdge *re) const
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re)
      return true;
  }
  return false;
}

void Rec2DElement::add(const Rec2DAction *ra)
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    if (_actions[i] == ra) {
      Msg::Error("[Rec2DElement] Action was already there");
      return;
    }
  }
  _actions.push_back((Rec2DAction*)ra);
}

void Rec2DElement::remove(const Rec2DAction *ra)
{
  unsigned int i = 0;
  while (i < _actions.size()) {
    if (_actions[i] == ra) {
      _actions[i] = _actions.back();
      _actions.pop_back();
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DElement] Didn't removed action, didn't have it");
}

void Rec2DElement::addNeighbour(const Rec2DEdge *re, const Rec2DElement *rel)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      if (_elements[i] != NULL && _elements[i] != rel)
        Msg::Error("[Rec2DElement] Have already a neighbour element");
      _elements[i] = (Rec2DElement*)rel;
      return;
    }
  }
  
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(re, elem);
  int a, b = a = NULL;
  if (elem[0])
    a = elem[0]->getNum();
  if (elem[1])
    b = elem[1]->getNum();
  Msg::Error("[Rec2DElement] Edge not found (add) (im %d, edge %d %d)", getNum(), a, b);
  for (int i = 0; i < _numEdge; ++i) {
    Rec2DElement *elem[2];
    Rec2DEdge::getElements(_edges[i], elem);
    int a, b = a = NULL;
    if (elem[0])
      a = elem[0]->getNum();
    if (elem[1])
      b = elem[1]->getNum();
    Msg::Error("edge%d : %d %d", i+1, a, b);
  }
}

void Rec2DElement::rmvNeighbour(const Rec2DEdge *re, const Rec2DElement *rel)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      if (_elements[i] == rel)
        _elements[i] = NULL;
      else
        Msg::Error("[Rec2DElement] I didn't know this element was my neighbour...");
      return;
    }
  }
  
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(re, elem);
  int a, b = a = NULL;
  if (elem[0])
    a = elem[0]->getNum();
  if (elem[1])
    b = elem[1]->getNum();
  Msg::Error("[Rec2DElement] Edge not found (rmv) (im %d, edge %d %d)", getNum(), a, b);
}

void Rec2DElement::swap(Rec2DEdge *re1, Rec2DEdge *re2)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re1) {
      if (_numEdge == 3)
        re1->remHasTri();
      else
        re1->remHasQuad();
      if (_elements[i])
        _elements[i]->rmvNeighbour(_edges[i], this);
      Rec2DElement *elem[2];
      Rec2DEdge::getElements(re2, elem);
      _edges[i] = (Rec2DEdge*)re2;
      if (_numEdge == 3)
        re2->addHasTri();
      else
        re2->addHasQuad();
      if (elem[1])
        Msg::Error("[Rec2DElement] Invalid swapping (there are %d and %d)", elem[0]->getNum(), elem[1]->getNum());
      else if (elem[0]) {
        _elements[i] = elem[0];
        elem[0]->addNeighbour(re2, this);
      }
      else
        _elements[i] = NULL;
      return;
    }
  }
  
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(re1, elem);
  int a, b = a = NULL;
  if (elem[0])
    a = elem[0]->getNum();
  if (elem[1])
    b = elem[1]->getNum();
  Rec2DEdge::getElements(re2, elem);
  int c, d = c = NULL;
  if (elem[0])
    c = elem[0]->getNum();
  if (elem[1])
    d = elem[1]->getNum();
  Msg::Error("[Rec2DElement] Try to give me the good edge (im %d, edge %d %d -> edge %d %d)", getNum(), a, b, c, d);
  for (int i = 0; i < _numEdge; ++i) {
    Rec2DElement *elem[2];
    Rec2DEdge::getElements(_edges[i], elem);
    int a, b = a = NULL;
    if (elem[0])
      a = elem[0]->getNum();
    if (elem[1])
      b = elem[1]->getNum();
    Msg::Error("edge%d : %d %d", i+1, a, b);
  }
}

double Rec2DElement::getAngle(const Rec2DVertex *rv) const
{
  std::vector<Rec2DVertex*> vert;
  getVertices(vert);
  
  int index = -1;
  for (int i = 0; i < _numEdge; ++i) {
    if (vert[i] == rv) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    Msg::Error("[Rec2DElement] I don't have your vertex...");
    return -1.;
  }
  
  int i1 = (index+_numEdge-1)%_numEdge;
  int i0 = (index+1)%_numEdge;
  double ang =  atan2(vert[i0]->v() - rv->v(), vert[i0]->u() - rv->u())
                - atan2(vert[i1]->v() - rv->v(), vert[i1]->u() - rv->u());
  
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME use real angle instead of parametric angle");
  
  if (ang < .0)
    return ang + 2.*M_PI;
  return ang;
}

void Rec2DElement::getAssumedParities(int *p) const
{
  if (_numEdge == 4) {
    Msg::Error("[Rec2DElement] Not implemented for quad");
  }
  Rec2DVertex *v[3];
  v[0] = _edges[0]->getVertex(0);
  v[1] = _edges[0]->getVertex(1);
  if (_edges[1]->getVertex(0) == v[0] ||
      _edges[1]->getVertex(0) == v[1]   )
    v[2] = _edges[1]->getVertex(1);
  else
    v[2] = _edges[1]->getVertex(0);
  p[0] = v[0]->getAssumedParity();
  p[1] = v[1]->getAssumedParity();
  p[2] = v[2]->getAssumedParity();
}

void Rec2DElement::getMoreEdges(std::vector<Rec2DEdge*> &edges) const
{
  for (int i = 0; i < _numEdge; ++i)
    edges.push_back(_edges[i]);
}

void Rec2DElement::getVertices(std::vector<Rec2DVertex*> &verts) const
{
  verts.resize(_numEdge);
  int i = 0, k = 0;
  while (k < _numEdge) {
    verts[k] = _edges[i/2]->getVertex(i%2);
    bool b = true;
    for (int j = 0; j < k; ++j) {
      if (verts[k] == verts[j])
        b = false;
    }
    if (b) {
      // make sure they are well ordered (edges are ordered)
      if (k == 2 && _edges[i/2]->getVertex((i+1)%2) == verts[0]) {
        Rec2DVertex *rv = verts[0];
        verts[0] = verts[1];
        verts[1] = rv;
      }
      ++k;
    }
    ++i;
  }
}

void Rec2DElement::getMoreNeighbours(std::vector<Rec2DElement*> &elem) const
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_elements[i])
      elem.push_back(_elements[i]);
  }
}

void Rec2DElement::getUniqueActions(std::vector<Rec2DAction*> &vectRA) const
{
  unsigned int size = vectRA.size();
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    unsigned int j = -1;
    while (++j < size && vectRA[j] != _actions[i]);
    if (j == size)
      vectRA.push_back(_actions[i]);
  }
}

Rec2DEdge* Rec2DElement::getCommonEdge(const Rec2DElement *rel0,
                                       const Rec2DElement *rel1 )
{
  for (int i = 0; i < rel0->_numEdge; ++i) {
    if (rel1->has(rel0->_edges[i]))
      return rel0->_edges[i];
  }
  Msg::Error("[Rec2DElement] didn't find edge, returning NULL");
  return NULL;
}

Rec2DVertex* Rec2DElement::getOtherVertex(const Rec2DVertex *rv1,
                                          const Rec2DVertex *rv2 ) const
{
  if (_numEdge == 4) {
    Msg::Error("[Rec2DElement] I'm not a triangle");
    return NULL;
  }
  for (int i = 0; i < 2; ++i) {
    Rec2DVertex *rv = _edges[i]->getVertex(0);
    if (rv != rv1 && rv != rv2)
      return rv;
    rv = _edges[i]->getVertex(1);
    if (rv != rv1 && rv != rv2)
      return rv;
  }
  Msg::Error("[Rec2DElement] I should not be here... Why this happen to me ?");
  return NULL;
}

void Rec2DElement::createElement(double shiftx, double shifty) const
{
  MVertex *mv[4];
  
  std::vector<Rec2DVertex*> v;
  getVertices(v);
  
  for (unsigned int i = 0; i < v.size(); ++i) {
    mv[i] = new MVertex(v[i]->getMVertex()->x() + shiftx,
                        v[i]->getMVertex()->y() + shifty,
                        v[i]->getMVertex()->z()          );
  }
  if (v.size() == 3) {
    MTriangle *tri = new MTriangle(mv[0], mv[1], mv[2]);
    Recombine2D::add(tri);
  }
  else {
    MQuadrangle *quad = new MQuadrangle(mv[0], mv[1], mv[2], mv[3]);
    Recombine2D::add(quad);
  }
}

MQuadrangle* Rec2DElement::_createQuad() const
{
  if (_numEdge != 4) {
    Msg::Error("[Rec2DElement] Why do you ask me to do this ? You know I can't do it ! COULD YOU LEAVE ME KNOW ?");
    return new MQuadrangle(NULL, NULL, NULL, NULL);
  }
  MVertex *v1, *v2, *v3 = NULL, *v4 = NULL;
  v1 = _edges[0]->getVertex(0)->getMVertex();
  v2 = _edges[0]->getVertex(1)->getMVertex();
  int I = -1;
  for (int i = 1; i < 4; ++i) {
    if (v2 == _edges[i]->getVertex(0)->getMVertex()) {
      v3 = _edges[i]->getVertex(1)->getMVertex();
      I = i;
      break;
    }
    if (v2 == _edges[i]->getVertex(1)->getMVertex()) {
      v3 = _edges[i]->getVertex(0)->getMVertex();
      I = i;
      break;
    }
  }
  if (I == -1) {
    Msg::Error("[Rec2DElement] Edges not connected");
    return NULL;
  }
  for (int i = 1; i < 4; ++i) {
    if (i == I) continue;
    if (v3 == _edges[i]->getVertex(0)->getMVertex()) {
      v4 = _edges[i]->getVertex(1)->getMVertex();
      break;
    }
    if (v3 == _edges[i]->getVertex(1)->getMVertex()) {
      v4 = _edges[i]->getVertex(0)->getMVertex();
      break;
    }
  }
  return new MQuadrangle(v1, v2, v3, v4);
}


/**  Rec2DNode  **/
/*****************/
bool lessRec2DNode::operator()(Rec2DNode *rn1, Rec2DNode *rn2) const
{
  return *rn1 < *rn2;
}

bool gterRec2DNode::operator()(Rec2DNode *rn1, Rec2DNode *rn2) const
{
  return *rn2 < *rn1;
}

bool moreRec2DNode::operator()(Rec2DNode *rn1, Rec2DNode *rn2) const
{
  if (rn1->getNumTri() == rn2->getNumTri())
    return *rn2 < *rn1;
  return rn1->getNumTri() < rn2->getNumTri();
}

Rec2DNode::Rec2DNode(Rec2DNode *father, Rec2DAction *ra,
                     double &bestEndGlobQual, int depth )
: _father(father), _ra(ra), _globalQuality(.0), _bestEndGlobQual(.0),
  _dataChange(NULL)
{
  for (int i = 0; i < REC2D_NUM_SON; ++i)
    _son[i] = NULL;
  
  std::vector<Rec2DElement*> neighbours;
  if (_ra) {
    if (depth)
      _ra->getNeighbourElements(neighbours);
    _dataChange = Rec2DData::getNewDataChange();
    _ra->apply(_dataChange);
  }
  
  if (father)
    _remainingTri = father->getNumTri() - _ra->getNumElement();
  else
    _remainingTri = Rec2DData::getNumElement();
  _globalQuality = Rec2DData::getGlobalQuality();
  
  if (depth) {
    std::vector<Rec2DAction*> actions;
    Recombine2D::nextTreeActions(actions, neighbours);
    
    if (actions.empty()) {
      _bestEndGlobQual = _globalQuality;
      if (depth < 0)
        Rec2DData::addEndNode(this);
    }
    else {
      for (unsigned int i = 0; i < actions.size(); ++i) {
        std::vector<Rec2DElement*> elem;
        actions[i]->getElements(elem);
        if (actions[i]->getBase())
          Msg::Info("collapse[%d](%d, %d) -> %g", i, elem[0]->getNum(), elem[1]->getNum(), actions[i]->getReward());
        else
          Msg::Info("recombine[%d](%d, %d) -> %g", i, elem[0]->getNum(), elem[1]->getNum(), actions[i]->getReward());
        actions[i]->printReward();
        double bestSonEGQ;
        _son[i] = new Rec2DNode(this, actions[i], bestSonEGQ, depth-1);
        if (bestSonEGQ > _bestEndGlobQual) {
          _bestEndGlobQual = bestSonEGQ;
          Rec2DNode *tmp = _son[0];
          _son[0] = _son[i];
          _son[i] = tmp;
        }
      }
    }
  }
  else
    _bestEndGlobQual = _globalQuality;
  
  bestEndGlobQual = _bestEndGlobQual;
  
  if (_dataChange) {
    if (!Rec2DData::revertDataChange(_dataChange)) {
      Msg::Error(" 1 - don't reverted changes");Msg::Error(" ");
    }
    _dataChange = NULL;
  }
}

Rec2DNode::~Rec2DNode()
{
  for (int i = 0; i < REC2D_NUM_SON; ++i)
    delete _son[i];
}

Rec2DNode* Rec2DNode::selectBestNode()
{
  for (int i = 1; i < REC2D_NUM_SON; ++i) {
    delete _son[i];
    _son[i] = NULL;
  }
  
  if (_son[0] && !_son[0]->makeChanges())
    Msg::Error("[Rec2DNode] No changes");
  
  return _son[0];
}

void Rec2DNode::develop(int depth, double &bestEndGlobQual)
{
  if (!_ra) {
    Msg::Error("[Rec2DNode] no action in node");
    return;
  }
  if (depth < 1) {
    Msg::Error("[Rec2DNode] That should not happen :'(");
    Msg::Error(" ");
    return;
  }
  
  _bestEndGlobQual = .0;
  bool delChanges = !_dataChange;
  std::vector<Rec2DElement*> neighbours;
  
  if (_ra) {
    _ra->getNeighbourElements(neighbours);
    unsigned int i = 0;
    while (i < neighbours.size()) {
      if (!neighbours[i]->getNumActions()) {
        neighbours[i] = neighbours.back();
        neighbours.pop_back();
      }
      else
        ++i;
    }
  }
  if (delChanges) {
    _dataChange = Rec2DData::getNewDataChange();
    _ra->apply(_dataChange);
  }
  
  if (_son[0]) {
    int i = 0;
    double bestSonEGQ;
    while (_son[i] && i < REC2D_NUM_SON) {
      _son[i]->develop(depth-1, bestSonEGQ);
      if (bestSonEGQ > _bestEndGlobQual) {
        _bestEndGlobQual = bestSonEGQ;
        Rec2DNode *tmp = _son[0];
        _son[0] = _son[i];
        _son[i] = tmp;
      }
      ++i;
    }
  }
  else {
    std::vector<Rec2DAction*> actions;
    Recombine2D::nextTreeActions(actions, neighbours);
    
    if (actions.size()) {
      for (unsigned int i = 0; i < actions.size(); ++i) {
        if (!actions[i]) {
          Msg::Error("null %d/%d", i, actions.size());
        }
        double bestSonEGQ;
        _son[i] = new Rec2DNode(this, actions[i], bestSonEGQ, depth-1);
        if (bestSonEGQ > _bestEndGlobQual) {
          _bestEndGlobQual = bestSonEGQ;
          Rec2DNode *tmp = _son[0];
          _son[0] = _son[i];
          _son[i] = tmp;
        }
      }
    }
    else
      _bestEndGlobQual = _globalQuality;
  }
  
  bestEndGlobQual = _bestEndGlobQual;
  
  if (delChanges) {
    if (!Rec2DData::revertDataChange(_dataChange)) {
      Msg::Error(" 1 - don't reverted changes");Msg::Error(" ");
    }
    _dataChange = NULL;
  }
}

bool Rec2DNode::makeChanges()
{
  if (_dataChange || !_ra)
    return false;
  _dataChange = Rec2DData::getNewDataChange();
#ifdef REC2D_DRAW // draw state at origin
  double time = Cpu();
  _ra->color(0, 0, 200);
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
  while (Cpu()-time < REC2D_WAIT_TIME)
    FlGui::instance()->check();
#endif
  _ra->apply(_dataChange);
  Rec2DData::setNumTri(_remainingTri);
  return true;
}

bool Rec2DNode::revertChanges()
{
  if (!_dataChange)
    return false;
  if (!Rec2DData::revertDataChange(_dataChange)) {
    Msg::Error(" 1 - don't reverted changes");Msg::Error(" ");
  }
  _dataChange = NULL;
  return true;
}

bool Rec2DNode::operator<(Rec2DNode &other)
{
  return _globalQuality < other._globalQuality;
}



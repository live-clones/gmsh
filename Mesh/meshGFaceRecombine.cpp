// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#define REC2D_WAIT_TIME .1
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

bool edgesInOrder(Rec2DEdge **edges, int numEdges)
{
  Rec2DVertex **v, *v0, *v1;
  v = new Rec2DVertex*[numEdges];
  v0 = edges[0]->getVertex(0);
  v1 = edges[0]->getVertex(1);
  if (edges[1]->getVertex(0) == v0 || edges[1]->getVertex(1) == v0) {
    v[0] = v0;
    if (edges[1]->getVertex(0) == v0)
      v[1] = edges[1]->getVertex(1);
    else
      v[1] = edges[1]->getVertex(0);
  }
  else if (edges[1]->getVertex(0) == v1 || edges[1]->getVertex(1) == v1) {
    v[0] = v1;
    if (edges[1]->getVertex(0) == v1)
      v[1] = edges[1]->getVertex(1);
    else
      v[1] = edges[1]->getVertex(0);
  }
  else {
    Msg::Error("edges not in order (1)");
    for (int i = 0; i < numEdges; ++i) {
      edges[i]->print();
    }
    return false;
  }
  for (int i = 2; i < numEdges; ++i) {
    if (edges[i]->getVertex(0) == v[i-1])
      v[i] = edges[i]->getVertex(1);
    else if (edges[i]->getVertex(1) == v[i-1])
      v[i] = edges[i]->getVertex(0);
    else {
      Msg::Error("edges not in order (2)");
      for (int i = 0; i < numEdges; ++i) {
        edges[i]->print();
      }
      return false;
    }
  }
  if (v[0] == v1 && v[numEdges-1] != v0 || v[0] == v0 && v[numEdges-1] != v1) {
    Msg::Error("edges not in order (3)");
    for (int i = 0; i < numEdges; ++i) {
      edges[i]->print();
    }
    return false;
  }
   delete v;
  return true;
}

void crash()
{
  Recombine2D::drawStateOrigin();
  int a[2];
  int e = 0;
  for (int i = 0; i < 10000000; ++i) e+=a[i];
  Msg::Info("%d",e);
}

int otherParity(int a)
{
  if (a % 2)
    return a - 1;
  return a + 1;
}

namespace std
{
  template <>
  void swap(Rec2DData::Action& a0, Rec2DData::Action& a1)
  {
    int pos0 = a0.position;
    a0.position = a1.position;
    a1.position = pos0;
    const Rec2DAction *ra0 = a0.action;
    a0.action = a1.action;
    a1.action = ra0;
  }
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
  if (++po < 1) {
    Msg::Warning("FIXME Why {mesh 2} then {mesh 0} then {mesh 2} imply not corner vertices");
    Msg::Warning("FIXME Why more vertices after first mesh generation");
    Msg::Warning("FIXME Update of Action pointing to edge and vertex (when change)");
    Msg::Warning("FIXME Deletion of action twoTri2Quad when Collapse pointing to it");
  }
  
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
    
    if (false) { // if !(remain all quad)
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
    Recombine2D::incNumChange();
    
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
  drawStateOrigin();
  Rec2DNode *root = new Rec2DNode(NULL, NULL, bestGlobalQuality, depth);
  Rec2DNode *currentNode = root->selectBestNode();
  
  static int num = 20, i = 0;
  static double dx = .0, dy = .0;
  
  while (currentNode) {
    //_data->checkQuality();
    FlGui::instance()->check();
#ifdef REC2D_DRAW // draw state at origin
    drawStateOrigin();
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
    while (Cpu()-time < REC2D_WAIT_TIME)
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
  //_data->drawChanges(shiftx, shifty);
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

void Recombine2D::drawStateOrigin()
{
  _current->_gf->triangles = _current->_data->_tri;
  _current->_gf->quadrangles = _current->_data->_quad;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
  FlGui::instance()->check();
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
bool Rec2DData::gterAction::operator()(Action *ra1, Action *ra2) const
{
  return *((Rec2DAction*)ra2->action) < *((Rec2DAction*)ra1->action);
}

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

void Rec2DData::add(const Rec2DEdge *re)
{
  if (re->_pos > -1) {
    Msg::Error("[Rec2DData] edge already there");
    return;
  }
  ((Rec2DEdge*)re)->_pos = _current->_edges.size();
  _current->_edges.push_back((Rec2DEdge*)re);
}

void Rec2DData::add(const Rec2DVertex *rv)
{
  if (rv->_pos > -1) {
    Msg::Error("[Rec2DData] vert %d already there (size %d)", rv, _current->_vertices.size());
    return;
  }
  ((Rec2DVertex*)rv)->_pos = _current->_vertices.size();
  _current->_vertices.push_back((Rec2DVertex*)rv);
}

void Rec2DData::add(const Rec2DElement *rel)
{
  if (rel->_pos > -1) {
    Msg::Error("[Rec2DData] elem already there");
    return;
  }
  ((Rec2DElement*)rel)->_pos = _current->_elements.size();
  _current->_elements.push_back((Rec2DElement*)rel);
  
#ifdef REC2D_DRAW
  MTriangle *t = rel->getMTriangle();
  if (t)
    _current->_tri.push_back(t);
  MQuadrangle *q = rel->getMQuadrangle();
  if (q)
    _current->_quad.push_back(q);
#endif
}

void Rec2DData::add(const Rec2DAction *ra)
{
  if (ra->_dataAction) {
    Msg::Error("[Rec2DData] action already there");
    return;
  }
  _current->_actions.push_back(new Action(ra, _current->_actions.size()));
  ((Rec2DAction*)ra)->_dataAction = _current->_actions.back();
}

void Rec2DData::rmv(const Rec2DEdge *re)
{
  if (re->_pos < 0) {
    Msg::Error("[Rec2DData] edge not there");
    return;
  }
  _current->_edges.back()->_pos = re->_pos;
  _current->_edges[re->_pos] = _current->_edges.back();
  _current->_edges.pop_back();
  ((Rec2DEdge*)re)->_pos = -1;
}

void Rec2DData::rmv(const Rec2DVertex *rv)
{
  if (rv->_pos < 0) {
    Msg::Error("[Rec2DData] vert not there");
    return;
  }
  _current->_vertices.back()->_pos = rv->_pos;
  _current->_vertices[rv->_pos] = _current->_vertices.back();
  _current->_vertices.pop_back();
  ((Rec2DVertex*)rv)->_pos = -1;
}

void Rec2DData::rmv(const Rec2DElement *rel)
{
  if (rel->_pos < 0) {
    Msg::Error("[Rec2DData] vert not there");
    return;
  }
  _current->_elements.back()->_pos = rel->_pos;
  _current->_elements[rel->_pos] = _current->_elements.back();
  _current->_elements.pop_back();
  ((Rec2DElement*)rel)->_pos = -1;
  
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

void Rec2DData::rmv(const Rec2DAction *ra)
{
  if (!ra->_dataAction) {
    Msg::Error("[Rec2DData] action not there");
  }
  else {
    int pos = ((Action*)ra->_dataAction)->position;
    ((Rec2DAction*)ra)->_dataAction = NULL;
    delete _current->_actions[pos];
    _current->_actions[pos] = _current->_actions.back();
    _current->_actions[pos]->position = pos;
    _current->_actions.pop_back();
  }
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

void Rec2DData::checkEntities()
{
  iter_rv itv;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    if (!(*itv)->checkCoherence()) {
      Msg::Error("Incoherence vertex");
      crash();
      return;
    }
  }
  iter_re ite;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    if (!(*ite)->checkCoherence()) {
      Msg::Error("Incoherence edge");
      crash();
      return;
    }
  }
  iter_rel itel;
  for (itel = firstElement(); itel != lastElement(); ++itel) {
    if (!(*itel)->checkCoherence()) {
      Msg::Error("Incoherence element");
      crash();
      return;
    }
  }
  for (unsigned int i = 0; i < _current->_actions.size(); ++i) {
    if (_current->_actions[i]->action->getDataAction() != _current->_actions[i] ||
        _current->_actions[i]->position != (int)i                          ||
        !_current->_actions[i]->action->checkCoherence()                     ) {
      Msg::Error("Incoherence action");
      crash();
      return;
    }
  }
}

void Rec2DData::printActions() const
{
  
  std::map<int, std::vector<double> > data;
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    std::vector<Rec2DElement*> tri;
    _actions[i]->action->getElements(tri);
    Msg::Info("action %d (%d, %d) -> reward %g",
              _actions[i]->action,
              tri[0]->getNum(),
              tri[1]->getNum(),
              ((Rec2DAction*)_actions[i]->action)->getReward());
      //Msg::Info("action %d -> reward %g", *it, _actions[i]->getReward());
    data[tri[0]->getNum()].resize(1);
    data[tri[1]->getNum()].resize(1);
    //data[tri[0]->getNum()][0] = (*it)->getReward();
    //data[tri[1]->getNum()][0] = (*it)->getReward();
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
  if (_current->_actions.size() == 0)
    return NULL;
  Action *ac = *std::max_element(_current->_actions.begin(),
                                 _current->_actions.end(), gterAction());
  return (Rec2DAction*)ac->action;
}

Rec2DAction* Rec2DData::getRandomAction()
{
  if (_current->_actions.size() == 0)
    return NULL;
  int index = rand() % (int)_current->_actions.size();
  return (Rec2DAction*)_current->_actions[index]->action;
}

void Rec2DData::checkObsolete()
{
  std::vector<Rec2DAction*> obsoletes;
  for (unsigned int i = 0; i < _current->_actions.size(); ++i) {
    if (_current->_actions[i]->action->isObsolete())
      obsoletes.push_back((Rec2DAction*)_current->_actions[i]->action);
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
  else {
    ra->addPointing();
    _type = CreatedAction;
  }
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

Rec2DChange::Rec2DChange(Rec2DVertex *rv0, Rec2DVertex *rv1,
                         const std::vector<Rec2DElement*> &elem,
                         Rec2DChangeType type                   )
{
  if (type == SwapMVertInElement) {
    _type = type;
    std::vector<Rec2DElement*> *vect = new std::vector<Rec2DElement*>();
    *vect = elem;
    _entity = vect;
    std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
    pairVert = new std::pair<Rec2DVertex*, Rec2DVertex*>(rv1, rv0);
    _info = pairVert;
    for (unsigned int i = 0; i < elem.size(); ++i)
      elem[i]->swapMVertex(rv0, rv1);
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
        Rec2DAction *ra = (Rec2DAction*)_entity;
        if (ra->getPointing()) {
          ra->hide();
        }
        else {
          if (ra->getInfant()) {
            ra->hide();
            Rec2DData::addHidden(ra);
          }
          else
            delete ra;
        }
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
        for (unsigned int i = 0; i < vect->size(); ++i) {
          if ((*vect)[i]->getPointing()) {
            (*vect)[i]->hide();
          }
          else {
            if ((*vect)[i]->getInfant()) {
              (*vect)[i]->hide();
              Rec2DData::addHidden((*vect)[i]);
            }
            else
              delete (*vect)[i];
          }
        }
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
      
    case SwapMVertInElement :
      {
        std::vector<Rec2DElement*> *elem = (std::vector<Rec2DElement*>*)_entity;
        std::pair<Rec2DVertex*, Rec2DVertex*> *pairVert;
        pairVert = (std::pair<Rec2DVertex*, Rec2DVertex*>*)_info;
        for (unsigned int i = 0; i < elem->size(); ++i)
          (*elem)[i]->swapMVertex(pairVert->first, pairVert->second);
        delete elem;
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
  _changes.push_back(new Rec2DChange(rv0, elem, RemoveElem));
  _changes.push_back(new Rec2DChange(rv0, rv1, edges, SwapVertInEdge));
  _changes.push_back(new Rec2DChange(rv0, rv1, actions, SwapVertInAction));
  _changes.push_back(new Rec2DChange(rv1, elem, AddElem));
  _changes.push_back(new Rec2DChange(rv0, rv1, elem, SwapMVertInElement));
}

void Rec2DDataChange::revert()
{
  for (int i = (int)_changes.size() - 1; i > -1; --i)
    _changes[i]->revert();
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
: _globQualIfExecuted(.0), _lastUpdate(-2), _numPointing(0), _dataAction(NULL)
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
  
  if (!edgesInOrder(_edges, 4)) Msg::Error("recomb |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
}

void Rec2DTwoTri2Quad::hide()
{
  static int a = -1;
  if (++a < 1) Msg::Warning("FIXME changer le systme d'execution action");
  if (_triangles[0])
    _triangles[0]->remove(this);
  if (_triangles[1])
    _triangles[1]->remove(this);
  Rec2DData::rmv(this);
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

bool Rec2DTwoTri2Quad::checkCoherence() const
{
  Rec2DEdge *edge4 = Rec2DElement::getCommonEdge(_triangles[0], _triangles[1]);
  if (!edge4) {
    if (!_triangles[0]->has(_edges[4]) || !_triangles[1]->has(_edges[4])) {
      Msg::Error("inco action -1, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    }
  }
  else if (_edges[4] != edge4) {
    Msg::Error("inco action 0, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    if (_edges[4])
      _edges[4]->print();
    else Msg::Info("no edge");
    if (Rec2DElement::getCommonEdge(_triangles[0], _triangles[1]))
      Rec2DElement::getCommonEdge(_triangles[0], _triangles[1])->print();
    else Msg::Info("no edge");
    return false;
  }
  
  std::vector<Rec2DEdge*> edges;
  Rec2DEdge *re[4];
  _triangles[0]->getMoreEdges(edges);
  _triangles[1]->getMoreEdges(edges);
  int k = -1;
  for (unsigned int i = 0; i < edges.size(); ++i) {
    if (edges[i] != _edges[4])
      re[++k] = edges[i];
  }
  if (k > 3)
    Msg::Error("[Rec2DTwoTri2Quad] too much edges");
  // reoder edges if needed
  if (edges[1] == _edges[4]) {
    Rec2DEdge *e = re[0];
    re[0] = re[1];
    re[1] = e;
  }
  if (edges[4] == _edges[4]) {
    Rec2DEdge *e = re[2];
    re[2] = re[3];
    re[3] = e;
  }
  
  for (int i = 0; i < 4; ++i) {
    if (re[i] != _edges[i]) {
      Msg::Error("inco action 1, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      for (int i = 0; i < 4; ++i) {
        _edges[i]->print();
        re[i]->print();
        Msg::Info(" ");
      }
      return false;
    }
  }
  
  if (_vertices[0] != _edges[4]->getVertex(0)) {
      Msg::Error("inco action 2, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
  }
  if (_vertices[1] != _edges[4]->getVertex(1)) {
      Msg::Error("inco action 3, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
  }
  if (_vertices[2] != _triangles[0]->getOtherVertex(_vertices[0], _vertices[1])) {
      Msg::Error("inco action 4, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
  }
  if (_vertices[3] != _triangles[1]->getOtherVertex(_vertices[0], _vertices[1])) {
      Msg::Error("inco action 5, |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
  }
  return true;
}

void Rec2DTwoTri2Quad::printIdentity() const
{
  Msg::Info("Recombine |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
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
                                valEdge, 0, _valVert                );
  
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

void Rec2DTwoTri2Quad::apply(Rec2DDataChange *rdc,
                             std::vector<Rec2DAction*> *&createdActions) const
{
  if (isObsolete()) {
    printIdentity();
    int p[4];
    p[0] = _vertices[0]->getParity();
    p[1] = _vertices[1]->getParity();
    p[2] = _vertices[2]->getParity();
    p[3] = _vertices[3]->getParity();
    Msg::Info("%d %d %d %d", p[0], p[1], p[2], p[3]);
    Msg::Error("[Rec2DTwoTri2Quad] I was obsolete !");
    crash();
  }
  _doWhatYouHaveToDoWithParity(rdc);
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
  rdc->checkObsoleteActions(_vertices, 4);
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
  }
}

bool Rec2DTwoTri2Quad::isObsolete() const
{
  int p[4];
  p[0] = _vertices[0]->getParity();
  p[1] = _vertices[1]->getParity();
  p[2] = _vertices[2]->getParity();
  p[3] = _vertices[3]->getParity();
  return (p[0] && p[0]/2 == p[1]/2 && p[0]%2 != p[1]%2 ||
          p[2] && p[2]/2 == p[3]/2 && p[2]%2 != p[3]%2 ||
          p[0] && (p[0] == p[2] || p[0] == p[3])       ||
          p[1] && (p[1] == p[2] || p[1] == p[3])         );
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
  unsigned int i = 0;
  while (i < elem.size()) {
    if (elem[i] == _triangles[0] || elem[i] == _triangles[0]) {
      elem[i] = elem.back();
      elem.pop_back();
    }
    else ++i;
  }
}

void Rec2DTwoTri2Quad::getNeighbElemWithActions(std::vector<Rec2DElement*> &elem) const
{
  getNeighbourElements(elem);
  unsigned int i = 0;
  while (i < elem.size()) {
    if (!elem[i]->getNumActions()) {
      elem[i] = elem.back();
      elem.pop_back();
    }
    else ++i;
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
  Rec2DData::rmv(this);
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
  std::vector<Rec2DVertex*> verts;
  _rec->_vertices[0]->getMoreNeighbourVertices(verts);
  _rec->_vertices[1]->getMoreNeighbourVertices(verts);
  unsigned int i = 0;
  while (i < verts.size() && verts[i]->getLastUpdate() <= _lastUpdate) ++i;
  if (i >= verts.size())
    return;
  
  SPoint2 p[2];
  _rec->_vertices[0]->getParam(&p[0]);
  _rec->_vertices[1]->getParam(&p[1]);
  int b0 = _rec->_vertices[0]->getOnBoundary();
  int b1 = _rec->_vertices[1]->getOnBoundary();
  
  int numEdge = 0;
  double valEdge = .0, valVert = .0;
  if (b0 || b1) {
    int iOK, iKO;
    if (b0) {
      iOK = 0;
      iKO = 1;
    }
    else {
      iOK = 1;
      iKO = 0;
    }
    _rec->_vertices[iKO]->relocate(p[iOK]);
    
    valVert += _rec->_vertices[2]->getGainOneElemLess();
    valVert += _rec->_vertices[3]->getGainOneElemLess();
    valVert += _rec->_vertices[iOK]->getGainMerge(_rec->_vertices[iKO]);
    valEdge -= REC2D_EDGE_BASE * _rec->_edges[1]->getQual();
    valEdge -= REC2D_EDGE_BASE * _rec->_edges[2]->getQual();
    numEdge -= 2 * REC2D_EDGE_BASE;
    valEdge -= _rec->_edges[4]->getWeightedQual();
    numEdge -= _rec->_edges[4]->getWeight();
    
    _globQualIfExecuted = Rec2DData::getGlobalQuality(numEdge, valEdge,
                                                      -REC2D_NUMB_VERT, valVert);
    
    _rec->_vertices[iKO]->relocate(p[iKO]);
  }
  else {
    double u = (_rec->_vertices[0]->u() + _rec->_vertices[1]->u()) / 2;
    double v = (_rec->_vertices[0]->v() + _rec->_vertices[1]->v()) / 2;
    SPoint2 pNew(u, v);
    _rec->_vertices[0]->relocate(pNew);
    _rec->_vertices[1]->relocate(pNew);
    
    valVert += _rec->_vertices[2]->getGainOneElemLess();
    valVert += _rec->_vertices[3]->getGainOneElemLess();
    valVert += _rec->_vertices[0]->getGainMerge(_rec->_vertices[1]);
    valEdge -= REC2D_EDGE_BASE * _rec->_edges[1]->getQual();
    valEdge -= REC2D_EDGE_BASE * _rec->_edges[2]->getQual();
    numEdge -= 2 * REC2D_EDGE_BASE;
    valEdge -= _rec->_edges[4]->getWeightedQual();
    numEdge -= _rec->_edges[4]->getWeight();
    
    _globQualIfExecuted = Rec2DData::getGlobalQuality(numEdge, valEdge,
                                                      -REC2D_NUMB_VERT, valVert);
    
    _rec->_vertices[0]->relocate(p[0]);
    _rec->_vertices[1]->relocate(p[1]);
  }
  
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DCollapse::printIdentity() const
{
  Msg::Info("Collapse |%d|%d|", _rec->_triangles[0]->getNum(), _rec->_triangles[1]->getNum());
}

void Rec2DCollapse::apply(std::vector<Rec2DVertex*> &newPar)
{
  static int a = -1;
  if (++a < 1) Msg::Error("FIXME Need definition Rec2DTwoTri2Quad::apply(newPar)");
}

void Rec2DCollapse::apply(Rec2DDataChange *rdc,
                          std::vector<Rec2DAction*> *&createdActions) const
{
  if (isObsolete()) {
    printIdentity();
    int p[2];
    p[0] = _rec->_vertices[0]->getParity();
    p[1] = _rec->_vertices[1]->getParity();
    Msg::Info("%d %d %d %d", _rec->_vertices[0]->getNum(), _rec->_vertices[1]->getNum(), _rec->_vertices[2]->getNum(), _rec->_vertices[3]->getNum());
    Msg::Info("%d %d - %d %d %d", p[0], p[1],
              _rec->_vertices[0]->getOnBoundary() && _rec->_vertices[1]->getOnBoundary(),
              !_rec->_vertices[2]->getOnBoundary() && _rec->_vertices[2]->getNumElements() < 4,
              !_rec->_vertices[3]->getOnBoundary() && _rec->_vertices[3]->getNumElements() < 4);
    _rec->_vertices[2]->printElem();
    _rec->_vertices[3]->printElem();
    Msg::Error("[Rec2DTwoTri2Quad] I was obsolete !");
    crash();
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
    rdc->relocate(_rec->_vertices[0], SPoint2(u, v));
    vOK = _rec->_vertices[0];
    vKO = _rec->_vertices[1];
  }
  bool edge12KO = _rec->_edges[1]->getVertex(0) == vKO ||
                  _rec->_edges[1]->getVertex(1) == vKO   ;
  rdc->swapFor(vKO, vOK);
  rdc->hide(vKO);
  
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
    if (createdActions) {
      for (unsigned int i = 0; i < createdActions->size(); ++i) {
        (*createdActions)[i]->reveal();
        rdc->append((*createdActions)[i]);
      }
    }
    else {
      createdActions = new std::vector<Rec2DAction*>;
      Rec2DElement *elem[2];
      Rec2DAction *newAction;
      Rec2DEdge::getElements(_rec->_edges[i2], elem);
      if (elem[1] && elem[0]->isTri() && elem[1]->isTri()) {
        newAction = new Rec2DTwoTri2Quad(elem[0], elem[1]);
        rdc->append(newAction);
        createdActions->push_back(newAction);
        newAction = new Rec2DCollapse((Rec2DTwoTri2Quad*)newAction);
        rdc->append(newAction);
        createdActions->push_back(newAction);
      }
      Rec2DEdge::getElements(_rec->_edges[i3], elem);
      if (elem[1] && elem[0]->isTri() && elem[1]->isTri()) {
        newAction = new Rec2DTwoTri2Quad(elem[0], elem[1]);
        rdc->append(newAction);
        createdActions->push_back(newAction);
        newAction = new Rec2DCollapse((Rec2DTwoTri2Quad*)newAction);
        rdc->append(newAction);
        createdActions->push_back(newAction);
      }
    }
  }
  
  int parKO, parOK;
  if ((parKO = vKO->getParity())) {
    if (!(parOK = vOK->getParity()))
      rdc->changeParity(vOK, parKO);
    else if (parOK/2 != parKO/2)
      Rec2DData::associateParity(std::max(parOK, parKO), std::min(parOK, parKO), rdc);
  }
  
  rdc->checkObsoleteActions(_rec->_vertices, 4);
}

bool Rec2DCollapse::isObsolete() const
{
  int p[2];
  p[0] = _rec->_vertices[0]->getParity();
  p[1] = _rec->_vertices[1]->getParity();
  return p[0] && p[0]/2 == p[1]/2 && p[0]%2 != p[1]%2 ||
         _rec->_vertices[0]->getOnBoundary() &&
         _rec->_vertices[1]->getOnBoundary()          ||
         !_rec->_vertices[2]->getOnBoundary() &&
         _rec->_vertices[2]->getNumElements() < 4     ||
         !_rec->_vertices[3]->getOnBoundary() &&
         _rec->_vertices[3]->getNumElements() < 4       ;
}

bool Rec2DCollapse::_hasIdenticalElement() const
{
  return _rec->_triangles[0]->hasIdenticalNeighbour() ||
         _rec->_triangles[1]->hasIdenticalNeighbour()   ;
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
: _rv0(rv0), _rv1(rv1), _lastUpdate(-1),
  _weight(REC2D_EDGE_BASE+2*REC2D_EDGE_QUAD), _pos(-1)
{
  _computeQual();
  reveal();
}

void Rec2DEdge::hide()
{
  _rv0->rmv(this);
  _rv1->rmv(this);
  Rec2DData::rmv(this);
  Rec2DData::addEdge(-_weight, -getWeightedQual());
}

void Rec2DEdge::reveal()
{
  _rv0->add(this);
  _rv1->add(this);
  Rec2DData::add(this);
  Rec2DData::addEdge(_weight, getWeightedQual());
}

bool Rec2DEdge::checkCoherence() const
{
  if (_rv0 == _rv1) return false;
  if (!_rv0->has(this) || !_rv1->has(this)) return false;
  return true;
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  if (elem[1]) {
    if (!elem[0]->has(this) || !elem[1]->has(this)) return false;
    if (!elem[0]->isNeighbour(this, elem[1]) ||
        !elem[1]->isNeighbour(this, elem[0])   ) return false;
  }
  else {
    if (!elem[0]->has(this)) return false;
    if (!elem[0]->isNeighbour(this, NULL)) return false;
  }
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

bool Rec2DEdge::isOnBoundary() const
{
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  return !elem[1];
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
: _v(v), _angle(4.*M_PI), _onWhat(1), _parity(0),
  _lastUpdate(-1), _sumQualAngle(.0), _pos(-1)
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
  _lastUpdate(rv->_lastUpdate),
  _sumQualAngle(rv->_sumQualAngle), _edges(rv->_edges),
  _elements(rv->_elements), _param(rv->_param), _pos(-1)
{
  static int a = -1;
  if (++a < -1) Msg::Warning("FIXME Edges really necessary ?");
  
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    _edges[i]->swap(rv, this, false);
  }
  Rec2DData::add(this);
  if (_elements.size())
    Rec2DData::addVert(REC2D_NUMB_VERT, getQual());
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
  
  Rec2DData::rmv(this);
  if  (_elements.size()) {
    Msg::Error("[Rec2DVertex] normal ?");
    Rec2DData::addVert(-REC2D_NUMB_VERT, -getQual());
  }
}

void Rec2DVertex::reveal()
{
  if (_parity)
    Rec2DData::addParity(this, _parity);
  
  Rec2DData::add(this);
  if  (_elements.size())
    Rec2DData::addVert(REC2D_NUMB_VERT, getQual());
}

bool Rec2DVertex::checkCoherence() const
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (!_edges[i]->has(this)) return false;
    for (unsigned int j = 0; j < i; ++j) {
      if (_edges[i] == _edges[j]) return false;
    }
  }
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (!_elements[i]->has(this)) return false;
    for (unsigned int j = 0; j < i; ++j) {
      if (_elements[i] == _elements[j]) return false;
    }
  }
  return true;
}

void Rec2DVertex::initStaticTable()
{
  // _qualVSnum[onWhat][numEl]; onWhat={0:edge,1:face}
  // _gains[onWhat][numEl];     onWhat={0:edge,1:face} (earning of adding an element)
  if (_qualVSnum == NULL) {
    int nE = 20, nF = 40; //edge, face
    
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
  
  if ((_parity = p))
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
  
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
}

void Rec2DVertex::relocate(SPoint2 p)
{
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
}

void Rec2DVertex::_updateQualAngle()
{
  double oldQualAngle = _getQualAngle();
  _sumQualAngle = .0;
  for (unsigned int i = 0; i < _elements.size(); ++i)
    _sumQualAngle += _angle2Qual(_elements[i]->getAngle(this));
  Rec2DData::addValVert(_getQualAngle()-oldQualAngle);
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

void Rec2DVertex::getMoreNeighbourVertices(std::vector<Rec2DVertex*> &verts) const
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    verts.push_back(_edges[i]->getOtherVertex(this));
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

double Rec2DVertex::getGainMerge(const Rec2DVertex *rv) const
{
  double ans = .0, sumQualAngle = .0;
  ans -= getQual();
  ans -= rv->getQual();
  double *qualAngle = new double[_elements.size()];
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    qualAngle[i] = _angle2Qual(_elements[i]->getAngle(this));
  }
  for (unsigned int i = 0; i < rv->_elements.size(); ++i) {
    unsigned int j = 0;
    while (j < _elements.size() && _elements[j] != rv->_elements[i]) ++j;
    if (j >= _elements.size())
      sumQualAngle += _angle2Qual(rv->_elements[i]->getAngle(rv));
    else
      qualAngle[j] = .0;
  }
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    sumQualAngle += qualAngle[i];
  }
  int numElem = _elements.size() + rv->_elements.size() - 4;
  ans += getQualDegree(numElem) + sumQualAngle / numElem;
  return ans;
}

double Rec2DVertex::getGainOneElemLess() const
{
  return getGainDegree(-1) + _sumQualAngle/(_elements.size()-1) - getQualAngle();
}

void Rec2DVertex::add(const Rec2DEdge *re)
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re) {
      Msg::Error("[Rec2DVertex] Edge was already there");
      return;
    }
  }
  _edges.push_back((Rec2DEdge*)re);
}

bool Rec2DVertex::has(const Rec2DEdge *re) const
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re)
      return true;
  }
  return false;
}

void Rec2DVertex::rmv(const Rec2DEdge *re)
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

void Rec2DVertex::add(const Rec2DElement *rel)
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel) {
      Msg::Error("[Rec2DVertex] Element was already there");
      return;
    }
  }
  if (_elements.size())
    Rec2DData::addVert(-REC2D_NUMB_VERT, -getQual());
  
  _elements.push_back((Rec2DElement*)rel);
  _sumQualAngle += _angle2Qual(rel->getAngle(this));
  Rec2DData::addVert(REC2D_NUMB_VERT, getQual());
  _lastUpdate = Recombine2D::getNumChange();
}

bool Rec2DVertex::has(const Rec2DElement *rel) const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel)
      return true;
  }
  return false;
}

void Rec2DVertex::rmv(const Rec2DElement *rel)
{
  unsigned int i = 0;
  while (i < _elements.size()) {
    if (_elements[i] == rel) {
      Rec2DData::addVert(-REC2D_NUMB_VERT, -getQual());
      _sumQualAngle -= _angle2Qual(_elements[i]->getAngle(this));
      _elements[i] = _elements.back();
      _elements.pop_back();
      
      if (_elements.size())
        Rec2DData::addVert(REC2D_NUMB_VERT, getQual());
      _lastUpdate = Recombine2D::getNumChange();
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DVertex] Didn't removed element, didn't have it");
}

void Rec2DVertex::printElem() const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    Msg::Info("%d - %d", i, _elements[i]->getNum());
  }
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
: _mEl((MElement *)t), _numEdge(3), _pos(-1)
{
  for (int i = 0; i < 3; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 3; ++i)
    _elements[i] = Rec2DEdge::getUniqueElement(_edges[i]);
  _edges[3] = NULL;
  _elements[3] = NULL;
  
  reveal(rv);
  if (!edgesInOrder(_edges, 3)) Msg::Error("tri |%d|", getNum());
}

Rec2DElement::Rec2DElement(MQuadrangle *q, const Rec2DEdge **re, Rec2DVertex **rv)
: _mEl((MElement *)q), _numEdge(4), _pos(-1)
{
  for (int i = 0; i < 4; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 4; ++i)
    _elements[i] = Rec2DEdge::getUniqueElement(_edges[i]);
  
  reveal(rv);
  if (!edgesInOrder(_edges, 4)) Msg::Error("quad |%d|", getNum());
}

void Rec2DElement::hide()
{
  if (_actions.size())
    Msg::Error("[Rec2DElement] I didn't want to be hidden :'(");
  for (int i = 0; i < _numEdge; ++i) {
    if (_numEdge == 3)
      _edges[i]->remHasTri();
    if (_elements[i])
      _elements[i]->rmvNeighbour(_edges[i], this);
  }
  std::vector<Rec2DVertex*> vertices(_numEdge);
  getVertices(vertices);
  for (int i = 0; i < _numEdge; ++i) {
    vertices[i]->rmv(this);
  }
  Rec2DData::rmv(this);
}

void Rec2DElement::reveal(Rec2DVertex **rv)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_numEdge == 3)
      _edges[i]->addHasTri();
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

bool Rec2DElement::checkCoherence() const
{
  Rec2DVertex *v[4], *v0, *v1;
  v0 = _edges[0]->getVertex(0);
  v1 = _edges[0]->getVertex(1);
  if (_edges[1]->getVertex(0) == v0 || _edges[1]->getVertex(1) == v0) {
    v[0] = v0;
    if (_edges[1]->getVertex(0) == v0)
      v[1] = _edges[1]->getVertex(1);
    else
      v[1] = _edges[1]->getVertex(0);
  }
  else if (_edges[1]->getVertex(0) == v1 || _edges[1]->getVertex(1) == v1) {
    v[0] = v1;
    if (_edges[1]->getVertex(0) == v1)
      v[1] = _edges[1]->getVertex(1);
    else
      v[1] = _edges[1]->getVertex(0);
  }
  else {
    Msg::Error("not only %d vertex or edge not in order 1 (im %d)", _numEdge, getNum());
    for (int i = 0; i < _numEdge; ++i) {
      _edges[i]->print();
    }
    return false;
  }
  for (int i = 2; i < _numEdge; ++i) {
    if (_edges[i]->getVertex(0) == v[i-1])
      v[i] = _edges[i]->getVertex(1);
    else if (_edges[i]->getVertex(1) == v[i-1])
      v[i] = _edges[i]->getVertex(0);
    else {
      Msg::Error("not only %d vertex or edge not in order 2 (im %d)", _numEdge, getNum());
      for (int i = 0; i < _numEdge; ++i) {
        _edges[i]->print();
      }
      return false;
    }
  }
  if (v[0] == v1 && v[_numEdge-1] != v0 || v[0] == v0 && v[_numEdge-1] != v1) {
    Msg::Error("not only %d vertex or edge not in order 3 (im %d)", _numEdge, getNum());
    for (int i = 0; i < _numEdge; ++i) {
      _edges[i]->print();
    }
    return false;
  }
  
  for (int i = 1; i < _numEdge; ++i) {
    for (int j = 0; j < i; ++j) {
      if (_edges[i] == _edges[j]) return false;
      if (v[i] == v[j]) return false;
    }
  }
  
  for (int i = 0; i < _numEdge; ++i) {
    if (!v[i]->has(this)) {
      Msg::Error("vertex don't have me (im %d)", getNum());
      return false;
    }
    if (_elements[i] && (!_elements[i]->has(this) || !_elements[i]->has(_edges[i]))) {
      Msg::Error("does %d know me ? %d / does it know edge ? %d (im %d)",
                 _elements[i]->getNum(),
                 _elements[i]->has(this),
                 _elements[i]->has(_edges[i]),
                 getNum()                     );
      return false;
    }
  }
  return true;
}

bool Rec2DElement::has(const Rec2DVertex *rv) const
{
  std::vector<Rec2DVertex*> verts;
  getVertices(verts);
  for (unsigned int i = 0; i < verts.size(); ++i)
    if (verts[i] == rv) return true;
  return false;
}

bool Rec2DElement::has(const Rec2DElement *rel) const
{
  for (int i = 0; i < _numEdge; ++i)
    if (_elements[i] == rel) return true;
  return false;
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
  Msg::Error("[Rec2DElement] Edge not found (rmv) (im %d)", getNum());
}

bool Rec2DElement::isNeighbour(const Rec2DEdge *re, const Rec2DElement *rel) const
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      if (_elements[i] == rel)
        return true;
      return false;
    }
  }
  return false;
}

bool Rec2DElement::hasIdenticalNeighbour() const
{
  for (int i = 1; i < _numEdge; ++i) {
    if (_elements[i]) {
      for (int j = 0; j < i; ++j) {
        if (_elements[i] == _elements[j])
          return true;
      }
    }
  }
  return false;
}

void Rec2DElement::swap(Rec2DEdge *re1, Rec2DEdge *re2)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re1) {
      if (_numEdge == 3)
        re1->remHasTri();
      if (_elements[i])
        _elements[i]->rmvNeighbour(_edges[i], this);
      Rec2DElement *elem[2];
      Rec2DEdge::getElements(re2, elem);
      _edges[i] = (Rec2DEdge*)re2;
      if (_numEdge == 3)
        re2->addHasTri();
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
  Msg::Error("[Rec2DElement] Try to give me the good edge (im %d)", getNum());
}

void Rec2DElement::swapMVertex(Rec2DVertex *rv0, Rec2DVertex *rv1)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_mEl->getVertex(i) == rv0->getMVertex()) {
      _mEl->setVertex(i, rv1->getMVertex());
      return;
    }
  }
  Msg::Error("[Rec2DElement] Didn't find your MVertex");
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
    Msg::Info("im %d, this is %d", getNum(), rv->getNum());
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
    bool itsOK = true;
    for (int j = 0; j < k; ++j) {
      if (verts[k] == verts[j])
        itsOK = false;
    }
    if (itsOK) {
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
  bool foundOne = false;
  for (int i = 0; i < rel0->_numEdge; ++i) {
    if (rel1->has(rel0->_edges[i])) {
      if (!foundOne) {
        return rel0->_edges[i];
        foundOne = true;
      }
      else {
        Msg::Warning("[Rec2DElement] More than one common edge");
        return NULL;
      }
    }
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
  _createdActions(NULL), _dataChange(NULL)
{
  for (int i = 0; i < REC2D_NUMB_SONS; ++i)
    _son[i] = NULL;
  
  if (!depth && !ra) {
    Msg::Error("[Rec2DNode] Nothing to do");
    return;
  }
  
  if (!depth) {
    _globalQuality = _ra->getReward();
    _remainingTri = father->getNumTri() - _ra->getNumElement();
    _bestEndGlobQual = bestEndGlobQual = _globalQuality;
  }
  else {
    std::vector<Rec2DElement*> neighbours;
    if (_ra) {
      _ra->getNeighbElemWithActions(neighbours);
      _dataChange = Rec2DData::getNewDataChange();
      _ra->apply(_dataChange, _createdActions);
      _ra->addPointing();
    }
    _remainingTri = Rec2DData::getNumElement();
    _globalQuality = Rec2DData::getGlobalQuality();
    
    Recombine2D::incNumChange();
    std::vector<Rec2DAction*> actions;
    Recombine2D::nextTreeActions(actions, neighbours);
    
    if (actions.empty()) {
      _bestEndGlobQual = _globalQuality;
      if (depth < 0) // when developping all the tree
        Rec2DData::addEndNode(this);
    }
    else {
      for (unsigned int i = 0; i < actions.size(); ++i) {
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
    bestEndGlobQual = _bestEndGlobQual;
    if (_dataChange) {
      if (!Rec2DData::revertDataChange(_dataChange))
        Msg::Error(" 1 - don't reverted changes");
      else
        Recombine2D::incNumChange();
      _dataChange = NULL;
    }
  }
}

Rec2DNode::~Rec2DNode()
{
  for (int i = 0; i < REC2D_NUMB_SONS; ++i)
    delete _son[i];
  if (_ra)
    _ra->rmvPointing();
}

Rec2DNode* Rec2DNode::selectBestNode()
{
  for (int i = 1; i < REC2D_NUMB_SONS; ++i) {
    delete _son[i];
    _son[i] = NULL;
  }
  
  if (_son[0] && !_son[0]->makeChanges())
    Msg::Error("[Rec2DNode] No changes");
  
  return _son[0];
}

void Rec2DNode::develop(int depth, double &bestEndGlobQual)
{
  if (!_ra || depth < 1) {
    Msg::Error("[Rec2DNode] should not be there");
    return;
  }
  
  bool delChange = !_dataChange;
  _bestEndGlobQual = .0;
  std::vector<Rec2DElement*> neighbours;
  if (!_son[0])
    _ra->getNeighbElemWithActions(neighbours);
    
  if (!_dataChange) {
    _dataChange = Rec2DData::getNewDataChange();
    _ra->apply(_dataChange, _createdActions);
    _ra->addPointing();
  }
  
  if (_son[0]) {
    int i = 0;
    double bestSonEGQ;
    while (_son[i] && i < REC2D_NUMB_SONS) {
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
    Recombine2D::incNumChange();
    std::vector<Rec2DAction*> actions;
    Recombine2D::nextTreeActions(actions, neighbours);
    
    if (actions.empty())
      _bestEndGlobQual = _globalQuality;
    else {
      for (unsigned int i = 0; i < actions.size(); ++i) {
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
  bestEndGlobQual = _bestEndGlobQual;
  if (delChange) {
    if (!Rec2DData::revertDataChange(_dataChange))
      Msg::Error(" 1 - don't reverted changes");
    else
      Recombine2D::incNumChange();
    _dataChange = NULL;
  }
}

bool Rec2DNode::makeChanges()
{
  if (_dataChange || !_ra)
    return false;
  _dataChange = Rec2DData::getNewDataChange();
#ifdef REC2D_DRAW // draw state at origin
  //double time = Cpu();
  _ra->color(0, 0, 200);
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
  //while (Cpu()-time < REC2D_WAIT_TIME)
    FlGui::instance()->check();
#endif
  _ra->apply(_dataChange, _createdActions);
  Rec2DData::setNumTri(_remainingTri);
  Recombine2D::incNumChange();
  return true;
}

bool Rec2DNode::revertChanges()
{
  if (!_dataChange)
    return false;
  if (!Rec2DData::revertDataChange(_dataChange))
    Msg::Error(" 1 - don't reverted changes");
  else
    Recombine2D::incNumChange();
  _dataChange = NULL;
  return true;
}

bool Rec2DNode::operator<(Rec2DNode &other)
{
  return _globalQuality < other._globalQuality;
}


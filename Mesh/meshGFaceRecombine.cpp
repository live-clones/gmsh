// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#include "meshGFaceRecombine.h"
//#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
//#include "meshGFaceOptimize.h"

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

int otherParity(int a) {
  if (a % 2)
    return a - 1;
  return a + 1;
}

/**  Recombine2D  **/
/*******************/
Recombine2D::Recombine2D(GFace *gf) : _gf(gf)
{
  if (Recombine2D::_current != NULL) {
    Msg::Warning("[Recombine2D] An instance already in execution");
    return;
  }
  Recombine2D::_current = this;
  
  backgroundMesh::set(_gf);
  _bgm = backgroundMesh::current();
  _data = new Rec2DData(gf->triangles.size(), gf->quadrangles.size());
  Rec2DVertex::initStaticTable();
  _numChange = 0;
  
#ifdef REC2D_DRAW
  //_data->_tri = _gf->triangles;
  //_data->_quad = _gf->quadrangles;
#endif
  
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
      Rec2DElement *rel = new Rec2DElement(t);
      Rec2DVertex *rv[3];
      for (int j = 0; j < 3; ++j) {
        MVertex *v = t->getVertex(j);
        if ( (itCorner = mapCornerVert.find(v)) != mapCornerVert.end() ) {
          if (!itCorner->second._rv)
            itCorner->second._rv = new Rec2DVertex(v, false);
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
        rv[j]->add(rel); //up data
      }
      for (int j = 0; j < 3; ++j) {
        Rec2DEdge *re;
        if ( (re = Rec2DVertex::getCommonEdge(rv[j], rv[(j+1)%3])) == NULL)
          re = new Rec2DEdge(rv[j], rv[(j+1)%3]);
        rel->add(re); //up data
      }
    }
    
    // quadrangles
    for (unsigned int i = 0; i < gf->quadrangles.size(); ++i) {
      MQuadrangle *q = gf->quadrangles[i];
      Rec2DElement *rel = new Rec2DElement(q);
      Rec2DVertex *rv[4];
      for (int j = 0; j < 4; ++j) {
        MVertex *v = q->getVertex(j);
        if ( (itCorner = mapCornerVert.find(v)) != mapCornerVert.end() ) {
          if (!itCorner->second._rv)
            itCorner->second._rv = new Rec2DVertex(v, false);
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
        rv[j]->add(rel);
      }
      for (int j = 0; j < 4; ++j) {
        Rec2DEdge *re;
        if ( (re = Rec2DVertex::getCommonEdge(rv[i], rv[(i+1)%3])) == NULL) {
          re = new Rec2DEdge(rv[i], rv[(i+1)%3]);
          rv[i]->add(re);
          rv[(i+1)%3]->add(re);
        }
        rel->add(re);
      }
    }
  }
  // update corner
  {
    std::map<MVertex*, AngleData>::iterator it = mapCornerVert.begin();
    for (; it != mapCornerVert.end(); ++it) {
      double angle = _geomAngle(it->first,
                                it->second._gEdges,
                                it->second._mElements);
      //new Rec2DVertex(it->second._rv, angle);
    }
  }
  mapCornerVert.clear();
  // update neighbouring, create the 'Rec2DTwoTri2Quad'
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
          new Rec2DTwoTri2Quad(elem[0], elem[1]);
        }
      }
    }
  }
  
  // set parity on boundary, create 'Rec2DFourTri2Quad'
  {
    Rec2DData::iter_rv it = Rec2DData::firstVertex();
    for (; it != Rec2DData::lastVertex(); ++it) {
      Rec2DVertex *rv = *it;
      if (rv->getOnBoundary()) {
        if (rv->getParity() == -1) {
          int base = Rec2DData::getNewParity();
          rv->setBoundaryParity(base, base+1);
        }
      }
      else if (rv->getNumElements() == 4) {
        ;
      }
    }
  }
  
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
  while (nextAction = Rec2DData::getBestAction()) {
    FlGui::instance()->check();
    double time = Cpu();
#ifdef REC2D_DRAW
    nextAction->color(0, 0, 200);
    CTX::instance()->mesh.changed = (ENT_ALL);
    drawContext::global()->draw();
#endif
    
    ++_numChange;
    nextAction->apply();
    
#ifdef REC2D_DRAW
    _gf->triangles = _data->_tri;
    _gf->quadrangles = _data->_quad;
    CTX::instance()->mesh.changed = (ENT_ALL);
    drawContext::global()->draw();
    while (Cpu()-time < REC2D_WAIT_TIME)
      FlGui::instance()->check();
#endif
    
    delete nextAction;
  }
  return 1;
}

double Recombine2D::_geomAngle(MVertex *v,
                               std::vector<GEdge*> &gEdge,
                               std::vector<MElement*> &elem) //*
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
      firstDer1 = -1 * ge->firstDer(ge->getUpperBound());
    else if (normub > prec * normlb)
      firstDer1 = ge->firstDer(ge->getLowerBound());
    else {
      Msg::Error("[Recombine2D] Bad precision, returning pi/2");
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
  std::vector<MElement*>::iterator it2 = elem.begin();
  for (; it2 != elem.end(); ++it2) {
    MElement *el = *it2;
    int k = 0, numV = el->getNumVertices();
    while (el->getVertex(k) != v && k < numV) ++k;
    if (k == numV) {
      Msg::Error("[Recombine2D] Wrong element, returning pi/2");
      return M_PI / 2.;
    }
    angleMesh += angle3Vertices(el->getVertex((k+1) % numV), v,
                                el->getVertex((k+2) % numV)    );
  }
  
  if (angleMesh < M_PI)
    return angle1;
  return angle2;
}


/**  Rec2DData  **/
/*****************/
Rec2DData::Rec2DData(int numTri, int numQuad)
{
  if (Rec2DData::_current != NULL) {
    Msg::Error("[Rec2DData] An instance in execution");
    return;
  }
  Rec2DData::_current = this;
  _numEdge = _numVert = 0;
  _valEdge = _valVert = .0;
  
  //_elements.reserve((int) (numTri + numQuad) * 1.1);
  //_edges.reserve((int) (numTri * 1.8 + numQuad * 2.4));
  //_vertices.reserve((int) (numTri * .6 + numQuad * 1.2));
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

void Rec2DData::remove(Rec2DEdge *re)
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
  }*/
  _current->_edges.erase(re);
}

void Rec2DData::remove(Rec2DVertex *rv)
{
  _current->_vertices.erase(rv);
}

void Rec2DData::remove(Rec2DElement *rel)
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
  }*/
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
    Msg::Info("[Rec2DData] Didn't erased mtriangle :(");
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
    Msg::Info("[Rec2DData] Didn't erased mquadrangle :(");
  }
#endif
}

void Rec2DData::remove(Rec2DAction *ra)
{
  std::list<Rec2DAction*>::iterator it = _current->_actions.begin();
  while (it != _current->_actions.end()) {
    if (*it == ra)
      it = _current->_actions.erase(it);
    else
      ++it;
  }
}

void Rec2DData::printState()
{
  Msg::Info("State");
  Msg::Info("-----");
  Msg::Info("numEdge %d (%d), valEdge %g => %g", _numEdge, _edges.size(), _valEdge, _valEdge/_numEdge);
  Msg::Info("numVert %d (%d), valVert %g => %g", _numVert, _vertices.size(), _valVert, _valVert/_numVert);
  Msg::Info("Element (%d)", _elements.size());
  Msg::Info("global Value %g", Rec2DData::getGlobalValue());
  Msg::Info("num action %d", _actions.size());
  std::map<int, std::vector<Rec2DVertex*> >::iterator it = _parities.begin();
  for (; it != _parities.end(); ++it) {
    Msg::Info("par %d, #%d", it->first, it->second.size());
  }
  Msg::Info(" ");
  iter_re ite;
  long double valEdge = .0;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    valEdge += (*ite)->getQual();
  }
  Msg::Info("valEdge : %g >< %g", valEdge, _valEdge);
  iter_rv itv;
  long double valVert = .0;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    valVert += (*itv)->getQual();
  }
  Msg::Info("valVert : %g >< %g", valVert, _valVert);
  Msg::Info("        : %g", valVert);
  Msg::Info("        : %g", _valVert);
}

int Rec2DData::getNewParity()
{
  if (!_current->_parities.size())
    return 0;
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  it = _current->_parities.end();
  --it;
  return (it->first/2)*2 + 2;
}

void Rec2DData::removeParity(Rec2DVertex *rv, int p)
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
}

double Rec2DData::getGlobalValue()
{
  double a = (_current->_valVert) / (_current->_numVert);
  return a * (_current->_valEdge) / (_current->_numEdge);
}

double Rec2DData::getGlobalValue(int numEdge, double valEdge,
                                   int numVert, double valVert)
{
  double a = (_current->_valVert + valVert) / (_current->_numVert + numVert);
  return a * (_current->_valEdge + valEdge) / (_current->_numEdge + numEdge);
}

Rec2DAction* Rec2DData::getBestAction()
{
  if (_current->_actions.size() == 0)
    return NULL;
  return *std::max_element(_current->_actions.begin(),
                           _current->_actions.end(), lessRec2DAction());
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

double Rec2DAction::getReward()
{
  if (_lastUpdate < Recombine2D::getNumChange())
    _computeGlobVal();
  return _globValIfExecuted - Rec2DData::getGlobalValue();
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
  
  _vertices[0] = _edges[4]->getVertex(0);
  _vertices[1] = _edges[4]->getVertex(1);
  _vertices[2] = _triangles[0]->getOtherVertex(_vertices[0], _vertices[1]);
  _vertices[3] = _triangles[1]->getOtherVertex(_vertices[0], _vertices[1]);
  
  _triangles[0]->add(this);
  _triangles[1]->add(this);
  Rec2DData::add(this);
}

Rec2DTwoTri2Quad::~Rec2DTwoTri2Quad()
{
  if (_triangles[0])
    _triangles[0]->removeT(this);
  if (_triangles[1])
    _triangles[1]->removeT(this);
  Rec2DData::remove(this);
}

void Rec2DTwoTri2Quad::_computeGlobVal()
{
  double valEdge = - REC2D_EDGE_BASE * _edges[4]->getQual();
  for (int i = 0; i < 4; ++i)
    valEdge += REC2D_EDGE_QUAD * _edges[i]->getQual();
  
  double valVert = _vertices[0]->getGain(-1) + _vertices[1]->getGain(-1);
  
  _globValIfExecuted =
    Rec2DData::getGlobalValue(4*REC2D_EDGE_QUAD - REC2D_EDGE_BASE,
                              valEdge, 0, valVert                 );
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DTwoTri2Quad::color(int a, int b, int c)
{
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  _triangles[0]->getMElement()->setCol(col);
  _triangles[1]->getMElement()->setCol(col);
}

void Rec2DTwoTri2Quad::apply()
{
  /*int min = 100, index = -1;
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
  }*/
  
  _triangles[0]->removeT(this);
  _triangles[1]->removeT(this);
  
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
  
  /*new Rec2DCollapse(*/new Rec2DElement(_edges)/*)*/;
  
}


/**  Rec2DEdge  **/
/*****************/
Rec2DEdge::Rec2DEdge(Rec2DVertex *rv0, Rec2DVertex *rv1)
: _rv0(rv0), _rv1(rv1), _weight(REC2D_EDGE_BASE), _boundary(-1), _lastUpdate(-2)
{
  _rv0->add(this);
  _rv1->add(this);
  Rec2DData::add(this);
  _computeQual();
  Rec2DData::addEdge(_weight, _weight*getQual());
}

Rec2DEdge::~Rec2DEdge()
{
  _rv0->remove(this);
  _rv1->remove(this);
  Rec2DData::remove(this);
  Rec2DData::addEdge(-_weight, -_weight*getQual());
}

void Rec2DEdge::_computeQual() //*
{
  double adimLength = _straightAdimLength();
  double alignment = _straightAlignment();
  if (adimLength > 1)
    adimLength = 1/adimLength;
  _qual = adimLength * ((1-REC2D_ALIGNMENT) + REC2D_ALIGNMENT * alignment);
  _lastUpdate = Recombine2D::getNumChange();
}

double Rec2DEdge::getQual()
{
  if (_lastUpdate < Recombine2D::getNumChange() &&
      _rv0->getLastMove() > _lastUpdate ||
      _rv1->getLastMove() > _lastUpdate           ) {
    _computeQual(); 
  }
  return _qual;
}

double Rec2DEdge::addNeighbour()
{
  if (++_boundary > 1)
    Msg::Error("[Rec2DEdge] Too much boundary element");
}

double Rec2DEdge::addQuadNeighbour()
{
  _weight += REC2D_EDGE_QUAD;
  if (_weight > REC2D_EDGE_BASE + 2*REC2D_EDGE_QUAD)
    Msg::Error("[Rec2DEdge] Weight too higher : %d (%d max)",
               _weight, REC2D_EDGE_BASE + 2*REC2D_EDGE_QUAD  );
  Rec2DData::addEdge(REC2D_EDGE_QUAD, REC2D_EDGE_QUAD*getQual());
}


Rec2DElement* Rec2DEdge::getSingleElement(Rec2DEdge *re)
{
  std::vector<Rec2DElement*> elem;
  Rec2DVertex::getCommonElements(re->getVertex(0), re->getVertex(1), elem);
  if (elem.size() == 1)
    return elem[0];
  if (elem.size() != 0)
    Msg::Error("[Rec2DEdge] Edge bound %d elements, returning NULL", elem.size());
  return NULL;
}

void Rec2DEdge::swap(Rec2DVertex *oldRV, Rec2DVertex *newRV)
{
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
  
  return length * (1/lc0 + 1/lc1) / 2;
}

double Rec2DEdge::_straightAlignment() const
{
  double angle0 = Recombine2D::bgm()->getAngle(_rv0->u(), _rv0->v(), .0);
  double angle1 = Recombine2D::bgm()->getAngle(_rv1->u(), _rv1->v(), .0);
  double angleEdge = atan2(_rv0->u()-_rv1->u(), _rv0->v()-_rv1->v());
  
  double alpha0 = angleEdge - angle0;
  double alpha1 = angleEdge - angle1;
  crossField2d::normalizeAngle(alpha0);
  crossField2d::normalizeAngle(alpha1);
  alpha0 = 1 - 4 * std::min(alpha0, .5 * M_PI - alpha0) / M_PI;
  alpha1 = 1 - 4 * std::min(alpha1, .5 * M_PI - alpha1) / M_PI;
  
  double lc0 = (*Recombine2D::bgm())(_rv0->u(), _rv0->v(), .0);
  double lc1 = (*Recombine2D::bgm())(_rv1->u(), _rv1->v(), .0);
  
  return (alpha0/lc0 + alpha1/lc1) / (1/lc0 + 1/lc1);
}

Rec2DVertex* Rec2DEdge::getOtherVertex(Rec2DVertex *rv) const
{
  if (rv == _rv0)
    return _rv1;
  if (rv == _rv1)
    return _rv0;
  Msg::Error("[Rec2DEdge] You are wrong, I don't have this vertex !");
  return NULL;
}


/**  Rec2DVertex  **/
/*******************/
Rec2DVertex::Rec2DVertex(MVertex *v, bool toSave)
: _v(v), _onWhat(1), _parity(-1), _lastMove(-1), _angle(4*M_PI), _isMesh(toSave)
{
  reparamMeshVertexOnFace(_v, Recombine2D::getGFace(), _param);
  if (_isMesh) {
    Rec2DData::add(this);
    Rec2DData::addVert(1, getQual());
  }
}

Rec2DVertex::Rec2DVertex(Rec2DVertex *rv, double ang)
: _v(rv->_v), _onWhat(-1), _parity(-1), _lastMove(-1), _angle(ang), _isMesh(true)
{
  _edges = rv->_edges;
  _elements = rv->_elements;
  _param = rv->_param;
  for (int i = 0; i < _edges.size(); ++i) {
    _edges[i]->swap(rv, this);
  }
  Rec2DData::add(this);
  Rec2DData::addVert(1, getQual());
  delete rv;
}

Rec2DVertex::~Rec2DVertex()
{
  Rec2DData::remove(this);
  Rec2DData::addVert(-1, -getQual());
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
      _qualVSnum[0][i] = 1. - fabs(2./i - 1.);
    for (int i = 1; i < nF; ++i)
      _qualVSnum[1][i] = 1. - fabs(4./i - 1.);
      
    _gains = new double*[2];
    _gains[0] = new double[nE-1];
    for (int i = 0; i < nE-1; ++i)
      _gains[0][i] = _qualVSnum[0][i+1] - _qualVSnum[0][i];
    _gains[1] = new double[nF-1];
    for (int i = 0; i < nF-1; ++i)
      _gains[1][i] = _qualVSnum[1][i+1] - _qualVSnum[1][i];
  }
}

Rec2DEdge* Rec2DVertex::getCommonEdge(Rec2DVertex *rv0, Rec2DVertex *rv1)
{
  for (unsigned int i = 0; i < rv0->_edges.size(); ++i) {
    if (rv1->has(rv0->_edges[i]))
      return rv0->_edges[i];
  }
  //Msg::Warning("[Rec2DVertex] didn't find edge, returning NULL");
  return NULL;
}

void Rec2DVertex::getCommonElements(Rec2DVertex *rv0, Rec2DVertex *rv1,
                                    std::vector<Rec2DElement*> &elem   )
{
  for (unsigned int i = 0; i < rv0->_elements.size(); ++i) {
    if (rv1->has(rv0->_elements[i]))
      elem.push_back(rv0->_elements[i]);
  }
}

bool Rec2DVertex::setBoundaryParity(int p0, int p1)
{
  if (_parity > -1) {
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

bool Rec2DVertex::_recursiveBoundParity(Rec2DVertex *prevRV, int p0, int p1)
{
  if (_parity == p0)
    return true;
  if (_parity > -1) {
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

void Rec2DVertex::setParity(int p)
{
  if (_parity > -1) {
    Rec2DData::removeParity(this, _parity);
  }
  _parity = p;
  Rec2DData::addParity(this, _parity);
}

double Rec2DVertex::getQual(int numEl) const
{
  int nEl = numEl > -1 ? numEl : _elements.size();
  if (_onWhat > -1)
    return _qualVSnum[_onWhat][nEl];
  if (nEl == 0)
    return -10.;
  return 1. - fabs(2./M_PI * _angle/nEl - 1.);
}

double Rec2DVertex::getGain(int n) const
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
  
  if (_elements.size() == 0)
    return 11 - fabs(2./M_PI * _angle/(_elements.size() + n) - 1.);
    
  if (_elements.size() + n == 0)
    return fabs(2./M_PI * _angle/_elements.size() - 1.) - 11;
    
  return fabs(2./M_PI * _angle/_elements.size() - 1.)
         - fabs(2./M_PI * _angle/(_elements.size() + n) - 1.);
}

void Rec2DVertex::add(Rec2DEdge *re)
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re) {
      Msg::Warning("[Rec2DVertex] Edge was already there");
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

void Rec2DVertex::remove(Rec2DEdge *re)
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
  Msg::Warning("[Rec2DVertex] Didn't removed edge, didn't have it");
}

void Rec2DVertex::add(Rec2DElement *rel)
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel) {
      Msg::Warning("[Rec2DVertex] Element was already there");
      return;
    }
  }
  if (_isMesh)
    Rec2DData::addValVert(getGain(1));
  _elements.push_back(rel);
}

bool Rec2DVertex::has(Rec2DElement *rel) const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel)
      return true;
  }
  return false;
}

void Rec2DVertex::remove(Rec2DElement *rel)
{
  unsigned int i = 0;
  while (i < _elements.size()) {
    if (_elements[i] == rel) {
      _elements[i] = _elements.back();
      _elements.pop_back();
      return;
    }
    ++i;
  }
  Msg::Warning("[Rec2DVertex] Didn't removed element, didn't have it");
}


/**  Rec2DElement  **/
/********************/
Rec2DElement::Rec2DElement(MTriangle *t) : _mEl((MElement *)t), _numEdge(3)
{
  for (int i = 0; i < 4; ++i) {
    _edges[i] = NULL;
    _elements[i] = NULL;
  }
  Rec2DData::add(this);
}

Rec2DElement::Rec2DElement(MQuadrangle *q) : _mEl((MElement *)q), _numEdge(4)
{
  for (int i = 0; i < 4; ++i) {
    _edges[i] = NULL;
    _elements[i] = NULL;
  }
  Rec2DData::add(this);
}

Rec2DElement::Rec2DElement(Rec2DEdge **edges) : _mEl(NULL), _numEdge(4)
{
  for (int i = 0; i < 4; ++i) {
    _edges[i] = edges[i];
    _elements[i] = Rec2DEdge::getSingleElement(edges[i]);
    if (_elements[i])
      _elements[i]->addNeighbour(_edges[i], this);
  }
  std::vector<Rec2DVertex*> vertices(4);
  getVertices(vertices);
  for (unsigned int i = 0; i < 4; ++i) {
    vertices[i]->add(this);
  }
  Rec2DData::add(this);
}

Rec2DElement::~Rec2DElement()
{
  if (_actions.size())
    Msg::Error("[Rec2DElement] I didn't want to be deleted :'(");
  for (int i = 0; i < _numEdge; ++i) {
    if (_elements[i])
      _elements[i]->removeNeighbour(_edges[i], this);
  }
  std::vector<Rec2DVertex*> vertices(_numEdge);
  getVertices(vertices);
  for (unsigned int i = 0; i < _numEdge; ++i) {
    vertices[i]->remove(this);
  }
  Rec2DData::remove(this);
}

void Rec2DElement::add(Rec2DEdge *re)
{
  int i;
  for (i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      Msg::Warning("[Rec2DElement] Edge was already there");
      return;
    }
    if (_edges[i] == NULL) {
      _edges[i] = re;
      break;
    }
  }
  if (i == _numEdge)
    Msg::Error("[Rec2DElement] Already %d edges, can't add anymore", _numEdge);
  
  if (_numEdge == 4)
    re->addQuadNeighbour();
  re->addNeighbour();
}

bool Rec2DElement::has(Rec2DEdge *re) const
{
  for (unsigned int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re)
      return true;
  }
  return false;
}

void Rec2DElement::add(Rec2DAction *ra)
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    if (_actions[i] == ra) {
      Msg::Warning("[Rec2DElement] Action was already there");
      return;
    }
  }
  _actions.push_back(ra);
}

void Rec2DElement::removeT(Rec2DAction *ra)
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
  Msg::Warning("[Rec2DElement] Didn't removed action, didn't have it");
}

void Rec2DElement::addNeighbour(Rec2DEdge *re, Rec2DElement *rel)
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re) {
      if (_elements[i] != NULL && _elements[i] != rel)
        Msg::Error("[Rec2DElement] Have already a neighbour element");
      _elements[i] = rel;
      return;
    }
  }
  Msg::Error("[Rec2DElement] Edge not found");
}


void Rec2DElement::removeNeighbour(Rec2DEdge *re, Rec2DElement *rel)
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
  Msg::Error("[Rec2DElement] Edge not found");
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
    for (unsigned int j = 0; j < k; ++j) {
      if (verts[k] == verts[j])
        b = false;
    }
    if (b) ++k;
    ++i;
  }
}

void Rec2DElement::getUniqueActions(std::vector<Rec2DAction*> &vectRA) const
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    unsigned int j = -1;
    while (++j < vectRA.size() && vectRA[j] != _actions[i]);
    if (j == vectRA.size())
      vectRA.push_back(_actions[i]);
  }
}

Rec2DEdge* Rec2DElement::getCommonEdge(Rec2DElement *rel0, Rec2DElement *rel1)
{
  for (unsigned int i = 0; i < rel0->_numEdge; ++i) {
    if (rel1->has(rel0->_edges[i]))
      return rel0->_edges[i];
  }
  Msg::Error("[Rec2DElement] didn't find edge, returning NULL");
  return NULL;
}

Rec2DVertex* Rec2DElement::getOtherVertex(Rec2DVertex *rv1, Rec2DVertex *rv2) const
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

MQuadrangle* Rec2DElement::_createQuad() const
{
  if (_numEdge != 4) {
    Msg::Error("[Rec2DElement] Why do you ask me to do this ? You know I can't do it ! COULD YOU LEAVE ME KNOW ?");
    return new MQuadrangle(NULL, NULL, NULL, NULL);
  }
  MVertex *v1, *v2, *v3, *v4;
  v1 = _edges[0]->getVertex(0)->getMVertex();
  v2 = _edges[0]->getVertex(1)->getMVertex();
  int I;
  for (unsigned int i = 1; i < 4; ++i) {
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
  for (unsigned int i = 1; i < 4; ++i) {
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



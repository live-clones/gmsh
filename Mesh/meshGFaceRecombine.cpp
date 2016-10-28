// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#include <cmath>
#include "meshGFaceRecombine.h"
#include "MTriangle.h"
#include "MVertex.h" //for angle3Vertices
#include "MQuadrangle.h"
#include "PView.h"
#include "meshGFace.h"
#include <algorithm>
#include <sstream>

#define REC2D_WAIT_SELECTED .0
#define REC2D_WAIT_BEST_SEQ .0
#define REC2D_WAIT_TM_1 1.00
#define REC2D_WAIT_TM_2 .001
#define REC2D_WAIT_TM_3 .001

#ifdef HAVE_FLTK
  #define REC2D_DRAW
  #ifdef REC2D_DRAW
    #define DRAW_ALL_TIME_STEP
    //#define DRAW_WHEN_SELECTED
    //#define DRAW_EVERY_CHANGE
    #define DRAW_BEST_SEQ
    #define DRAW_IF_ERROR
  #endif
#endif

#ifdef REC2D_DRAW
  #include "drawContext.h"
  #include "FlGui.h"
#endif
  #include "Context.h"
  #include "OS.h"
  #include "CreateFile.h"


#define E(x) Msg::Error x
#define F(x) Msg::Fatal x
#define I(x) Msg::Info x
#define W(x) Msg::Warning x
#define DEBUG(x) // {x}
// TODO : regarder pour pointing
//        It''s RElement that should give Blossom Qual !
//        test


Recombine2D *Recombine2D::_cur = NULL;
Rec2DData *Rec2DData::_cur = NULL;
double **Rec2DVertex::_qualVSnum = NULL;
double **Rec2DVertex::_gains = NULL;

double Recombine2D::t0 = 0;
double Recombine2D::t1 = 0;
double Recombine2D::t2 = 0;
double Recombine2D::t3 = 0;
double Recombine2D::t4 = 0;
double Recombine2D::t5 = 0;
double Recombine2D::t6 = 0;
double Recombine2D::t7 = 0;
double Recombine2D::t8 = 0;
double Recombine2D::t9 = 0;

namespace {

#ifdef REC2D_DRAW
  void __draw(double dt = .0)
  {
    double time = Cpu();
    Recombine2D::drawStateOrigin();
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    while (Cpu()-time < dt)
      FlGui::instance()->check();
  }

  void __drawWait(double time, double dt)
  {
    Recombine2D::drawStateOrigin();
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    while (Cpu()-time < dt)
      FlGui::instance()->check();
  }
#endif

  bool edgesAreInOrder(Rec2DEdge const*const*const edges, const int numEdges)
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
      delete[] v;
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
        delete[] v;
        return false;
      }
    }
    if ((v[0] == v1 && v[numEdges-1] != v0) ||
        (v[0] == v0 && v[numEdges-1] != v1)   ) {
      Msg::Error("edges not in order (3)");
      for (int i = 0; i < numEdges; ++i) {
        edges[i]->print();
      }
      delete[] v;
      return false;
    }
     delete[] v;
    return true;
  }

  void __crash()
  {
    Msg::Info(" ");
    Recombine2D::drawStateOrigin();
    int a[2];
    int e = 0;
    for (int i = 0; i < 10000000; ++i) e+=a[i];
    Msg::Info("%d",e);
  }

  void __wait(double dt = REC2D_WAIT_TM_3)
  {
  #ifdef REC2D_DRAW
    Msg::Info(" ");
    double time = Cpu();
    while (Cpu()-time < dt)
      FlGui::instance()->check();
  #endif
  }

  int otherParity(const int a)
  {
    if (a % 2)
      return a - 1;
    return a + 1;
  }
}

namespace std // specialization of std::swap(..) for Rec2DData::Action class
{
  template <>
  void swap(Rec2DData::Action& a0, Rec2DData::Action& a1)
  {
    const Rec2DAction *tmp = a0.action;
    a0.action = a1.action;
    a1.action = tmp;
    a0.update();
    a1.update();
  }
}


/**  Rec2DContainer  **/
/**********************/
template <typename T>
int Rec2DContainer<T>::add(T t)
{
  typename std::set<T>::iterator it = _set.find(t);
  if (it == _set.end()) {
    _set.insert(t);
    _vec.push_back(t);
    return 1;
  }
  return 0;
}

template <typename T>
int Rec2DContainer<T>::rmv(T t)
{
  typename std::set<T>::iterator it = _set.find(t);
  if (it != _set.end()) {
    _set.erase(it);
    return 1;
  }
  return 0;
}

template <typename T>
T Rec2DContainer<T>::getRandom()
{
  while (_set.size()) {
    int index = rand() % _vec.size();
    T t = _vec[index];
    if (_set.find(t) == _set.end()) {
      _vec[index] = _vec.back();
      _vec.pop_back();
    }
    else return t;
  }
  _vec.clear();
  return NULL;
}

/**  Recombine2D  **/
/*******************/
Recombine2D::Recombine2D(GFace *gf, bool col)
  : _gf(gf), _bgm(NULL), _numChange(0), _collapses(col),
    _strategy(0), _horizon(0), _qualCriterion(BlossomQuality), //_qualCriterion(NoCrit),
    _checkIfNotAllQuad(1), _avoidIfNotAllQuad(1),
    _revertIfNotAllQuad(0), _oneActionHavePriority(1),
    _noProblemIfObsolete(0),
    _weightEdgeBase(2),
    _weightEdgeQuad(1),
    _weightAngleTri(1),
    _weightAngleQuad(2),
    _coefAngleQual(.5),
    _coefDegreeQual(.5),
    _coefLengthQual(.5),
    _coefOrientQual(.5),
    _recombineWithBlossom(1), elist(NULL)
{
  if (Recombine2D::_cur) {
    Msg::Warning("[Recombine2D] An instance already exists. Can't create another.");
    return;
  }
  if (Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance exists, should not !");
    return;
  }

  Recombine2D::_cur = this;
  construct();

  srand(time(NULL));
}

Recombine2D::~Recombine2D()
{
  if (_iamCurrent()) {
    Recombine2D::_cur = NULL;
    if (_data)
      delete _data;
  }
}

bool Recombine2D::construct()
{
  if (!_iamCurrent()) {
    Msg::Warning("[Recombine2D] I can't construct...");
    return false;
  }
  if (Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance exists, should not !");
    return false;
  }

  orientMeshGFace orienter;
  orienter(_gf);
  Rec2DVertex::initStaticTable();
  Msg::Info("Before backgroundMesh");
  Msg::Info(" ");
  backgroundMesh::set(_gf); // this doesn't work after call 'recombineWithBlossom()'
  Msg::Info("After backgroundMesh");
  Msg::Info(" ");
  _bgm = backgroundMesh::current();
  _data = new Rec2DData();

  static int po = -1;
  if (++po < 1) {
    Msg::Warning("FIXME Why {mesh 2} then {mesh 0} then {mesh 2} imply not corner vertices");
    Msg::Warning("FIXME Why more vertices after first mesh generation");
    Msg::Warning("FIXME Update of Action pointing to edge and vertex (when change)");
  }

  // Be able to compute geometrical angle at corners
  std::map<MVertex*, AngleData> mapCornerVert;
  {
    std::list<GEdge*> listge = _gf->edges();
    std::list<GEdge*>::iterator itge = listge.begin();
    int iii = 0;
    for (; itge != listge.end(); ++itge) {
      Msg::Info("%d", ++iii);
      *itge;
      (*itge)->getBeginVertex();
      (*itge)->getBeginVertex()->getMeshElement(0);
      (*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0);
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)];
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)]
        ._gEdges;
      mapCornerVert[(*itge)->getBeginVertex()->getMeshElement(0)->getVertex(0)]
        ._gEdges.push_back(*itge);
      mapCornerVert[(*itge)->getEndVertex()->getMeshElement(0)->getVertex(0)]
        ._gEdges.push_back(*itge);
    }
  }
  // Create the 'Rec2DVertex', the 'Rec2DEdge' and the 'Rec2DElement'
  {
    std::map<MVertex*, Rec2DVertex*> mapVert;
    std::map<MVertex*, Rec2DVertex*>::iterator itV;
    std::map<MVertex*, AngleData>::iterator itCorner;
    // triangles
    for (unsigned int i = 0; i < _gf->triangles.size(); ++i) {
      MTriangle *t = _gf->triangles[i];

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
    for (unsigned int i = 0; i < _gf->quadrangles.size(); ++i) {
      MQuadrangle *q = _gf->quadrangles[i];

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
  // update boundary, create the 'Rec2DTwoTri2Quad' and the 'Rec2DCollapse'
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
          if (Recombine2D::onlyRecombinations())
            new Rec2DTwoTri2Quad(elem[0], elem[1]);
          else
            new Rec2DCollapse(new Rec2DTwoTri2Quad(elem[0], elem[1]));
        }
      }
    }
  }
  // set parity on boundary, (create the 'Rec2DFourTri2Quad')
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

  Msg::Info("Before recombining with Blossom");
  Msg::Info(" ");
  
  if (_recombineWithBlossom) {
    _blossomTime = Cpu();
    //recombineWithBlossom(_gf, .0, .16, elist, t2n);// no more in the code (see Amaury)
    _blossomTime = Cpu()-_blossomTime;
  }
  _gf->quadrangles.clear();
  //
  return true;
}

bool Recombine2D::recombine()
{
  if (!_iamCurrent()) {
    Msg::Warning("[Recombine2D] If I can't construct myself, I can't recombine :)");
    return false;
  }
  if (!Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance dosen't exist. Have you called construct() ?");
    return false;
  }

  I(("Recombining... #actions = %d, horizon = %d",
            Rec2DData::getNumAction(), _horizon ));
#ifdef REC2D_DRAW
  __draw(.0);
#endif
  double globtime = Cpu();
  _checkIfNotAllQuad = _checkIfNotAllQuad && !_collapses;
  _avoidIfNotAllQuad = _avoidIfNotAllQuad && _checkIfNotAllQuad;
  _revertIfNotAllQuad = _revertIfNotAllQuad && _avoidIfNotAllQuad;

  Rec2DNode *root = new Rec2DNode(NULL, NULL, _horizon);
  Rec2DNode *currentNode = Rec2DNode::selectBestNode(root);

  while (currentNode) {
    currentNode->lookahead(_horizon);
    currentNode = Rec2DNode::selectBestNode(currentNode);
  }

#ifdef REC2D_DRAW
  __draw(.0);
#endif
  _lastRunTime = Cpu() - globtime;
  I(( "... done recombining, in %f seconds", _lastRunTime ));
  return true;
}

bool Recombine2D::recombineNewAlgo(int horiz, int code)
{
  if (!_iamCurrent()) {
    Msg::Warning("[Recombine2D] If I can't construct myself, I can't recombine :)");
    return false;
  }
  if (!Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance dosen't exist. Have you called construct() ?");
    return false;
  }



  if (horiz < 0 || code < 0) {
    if (!Rec2DAlgo::paramOK()) return false;
    Rec2DAlgo::getParam(horiz, code);
  }
  else {
    if (!Rec2DAlgo::setParam(horiz, code)) return false;
  }

  I(("Recombining... code = %d, horizon = %d", code, horiz));

  double globtime = Cpu();
  Rec2DAlgo::execute();
  _lastRunTime = Cpu() - globtime;

  I(( "... done recombining, in %f seconds", _lastRunTime ));
  return true;
}

bool Recombine2D::recombineSimpleAlgo(int horiz)
{
  if (!_iamCurrent()) {
    Msg::Warning("[Recombine2D] If I can't construct myself, I can't recombine :)");
    return false;
  }
  if (!Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance dosen't exist. Have you called construct() ?");
    return false;
  }

  if (horiz < 0) {
    if (!Rec2DAlgo::paramOKSimpleAlgo()) return false;
  }
  else {
    if (!Rec2DAlgo::setParam(horiz, 0)) return false;
  }

  I(("Recombining... Simple, horizon = %d", horiz));

  double globtime = Cpu();
  Rec2DAlgo::execute();
  _lastRunTime = Cpu() - globtime;

  I(( "... done recombining, in %f seconds", _lastRunTime ));
  return true;
}

bool Recombine2D::recombineComplete(int horiz)
{
  if (!_iamCurrent()) {
    Msg::Warning("[Recombine2D] If I can't construct myself, I can't recombine :)");
    return false;
  }
  if (!Rec2DData::hasInstance()) {
    Msg::Error("[Recombine2D] Data instance dosen't exist. Have you called construct() ?");
    return false;
  }

  if (horiz < 0) {
    if (!Rec2DAlgo::paramOKSimpleAlgo()) return false;
  }
  else {
    if (!Rec2DAlgo::setParam(horiz, 0)) return false;
  }

  I(("Recombining... Complete, horizon = %d", horiz));

  double globtime = Cpu();
  Rec2DAlgo::execute(true);
  _lastRunTime = Cpu() - globtime;

  I(( "... done recombining, in %f seconds", _lastRunTime ));
  return true;
}

double Recombine2D::recombine(int depth)
{
  Msg::Info("Recombining with depth %d", depth);
  Rec2DData::clearChanges();
#ifdef DRAW_ALL_TIME_STEP
  double time = Cpu();
  static int num = 20, i = 0;
  static double dx = .0, dy = .0;
#endif
#ifdef DRAW_WHEN_SELECTED
    __draw(REC2D_WAIT_SELECTED);
#endif
  Rec2DNode *root = new Rec2DNode(NULL, NULL, depth);
  Rec2DNode *currentNode = Rec2DNode::selectBestNode(root);

  while (currentNode) {
    I(("boucle recombine"));
#ifdef DRAW_ALL_TIME_STEP
    FlGui::instance()->check();
    if ( !((i+1) % ((int)std::sqrt(num)+1)) ) {
      dx = .0; dy -= 1.1;
    }
    else
      dx += 1.1;
    drawState(dx, dy);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    while (Cpu()-time < REC2D_WAIT_SELECTED)
      FlGui::instance()->check();
    ++i;
    time = Cpu();
#endif
    currentNode->lookahead(depth);
    currentNode = Rec2DNode::selectBestNode(currentNode);
  }

  Msg::Info("-------- %g", Rec2DData::getGlobalQuality());
  return Rec2DData::getGlobalQuality();
  //_data->printState();
}

void Recombine2D::recombineSameAsBlossom() // check if quality ok
{
  if (!Recombine2D::blossomRec()) {
    Msg::Warning("Cannot do anything !");
  }
  setQualCriterion(BlossomQuality);
  Msg::Error("..............begin..............");
  //recombineWithBlossom(_gf, .0, 1.1, elist, t2n);
  _data->_quad = _gf->quadrangles;
  Recombine2D::drawStateOrigin();

  std::map<int, Rec2DElement*> n2rel;
  std::map<MElement*,int>::iterator it = t2n.begin();
  for (; it != t2n.end(); ++it) {
    n2rel[it->second] = Rec2DData::getRElement(it->first);
  }

  int blosQual = 0;
  for (int i = 0; i < _cur->elist[0]; ++i) {
    Rec2DElement *tri1 = n2rel[_cur->elist[3*i+1]];
    Rec2DElement *tri2 = n2rel[_cur->elist[3*i+2]];
    blosQual += _cur->elist[3*i+3];
    Rec2DAction *ra = new Rec2DTwoTri2Quad(tri1, tri2);
    int realRew = (int) ra->getRealReward();
    if (realRew > ra->getRealReward()+.3) --realRew;
    if (realRew < ra->getRealReward()-.3) ++realRew;
    if ((int) ra->getRealReward()+_cur->elist[3*i+3] != 100)
      Msg::Info("%d(%d-%g) - %d (%d, %d) => blosQual %d",
                    (int) ra->getRealReward(),
                    realRew,
                    ra->getRealReward(),
                    _cur->elist[3*i+3],
                    _cur->elist[3*i+2],
                    _cur->elist[3*i+1],
                    blosQual);
    Rec2DDataChange *dc = Rec2DData::getNewDataChange();
    std::vector<Rec2DAction*> *v = NULL;
    ra->apply(dc, v);
    drawStateOrigin();
  }

  Msg::Info("Recombine2D Blossom Quality %d => %d", Rec2DData::getBlosQual(), 100*_cur->elist[0]-Rec2DData::getBlosQual());
  Msg::Info("vs Blossom Blossom Quality %d", blosQual);
  if (blosQual == 100*_cur->elist[0]-Rec2DData::getBlosQual())
    Msg::Info("It is ok :-)");
  else
    Msg::Info("Not ok :-(...");
}

void Recombine2D::recombineSameAsHeuristic()
{
  double globtime = Cpu();
  _noProblemIfObsolete = true;
  //recombineHeuristic(_gf, .0, 1.1, elist, t2n);// no more in the code (see Amaury)
  _lastRunTime = Cpu() - globtime;
  _data->_quad = _gf->quadrangles;
  drawStateOrigin();

  std::map<int, Rec2DElement*> n2rel;
  std::map<MElement*,int>::iterator it = t2n.begin();
  for (; it != t2n.end(); ++it) {
    n2rel[it->second] = Rec2DData::getRElement(it->first);
  }

  int heurQual = 0;
  for (int i = 0; i < _cur->elist[0]; ++i) {
    Rec2DElement *tri1 = n2rel[_cur->elist[3*i+1]];
    Rec2DElement *tri2 = n2rel[_cur->elist[3*i+2]];
    heurQual += _cur->elist[3*i+3];
    Rec2DAction *ra = new Rec2DTwoTri2Quad(tri1, tri2);
    int realRew = (int) ra->getRealReward();
    if (realRew > ra->getRealReward()+.3) --realRew;
    if (realRew < ra->getRealReward()-.3) ++realRew;
    if ((int) ra->getRealReward()+_cur->elist[3*i+3] != 100)
      Msg::Info("%d(%d-%g) - %d (%d, %d) => blosQual %d",
                    (int) ra->getRealReward(),
                    realRew,
                    ra->getRealReward(),
                    _cur->elist[3*i+3],
                    _cur->elist[3*i+2],
                    _cur->elist[3*i+1],
                    heurQual);
    Rec2DDataChange *dc = Rec2DData::getNewDataChange();
    std::vector<Rec2DAction*> *v = NULL;
    ra->apply(dc, v);
    drawStateOrigin();
  }

  _noProblemIfObsolete = false;
  Msg::Info("Recombine2D Blossom Quality %d => %d", Rec2DData::getBlosQual(), 100*_cur->elist[0]-Rec2DData::getBlosQual());
  Msg::Info("vs Heuristic Blossom Quality %d", heurQual);
  if (heurQual == 100*_cur->elist[0]-Rec2DData::getBlosQual())
    Msg::Info("It is ok :-)");
  else
    Msg::Info("Not ok :-(...");
}

void Recombine2D::recombineGreedy(bool constrained)
{
  double globtime = Cpu();
  if (!constrained) _noProblemIfObsolete = true;
  while (Rec2DAction *ra = Rec2DData::getBestAction()) {
    Rec2DDataChange *dc = Rec2DData::getNewDataChange();
    std::vector<Rec2DAction*> *v = NULL;
    ra->apply(dc, v);
    drawStateOrigin();
  }
  _noProblemIfObsolete = false;
  _lastRunTime = Cpu() - globtime;
  drawStateOrigin();
}

//bool Recombine2D::developTree()
//{
//  Rec2DNode root(NULL, NULL);
//  _data->printState();
//
//  Msg::Info("best global value : %g", root._getBestSequenceReward());
//  Msg::Info("num end node : %d", Rec2DData::getNumEndNode());
//
//  Rec2DData::sortEndNode();
//  Rec2DData::drawEndNode(100);
//  //_gf->triangles.clear();
//  return 1;
//}

void Recombine2D::clearChanges() // revert to initial state
{
  Rec2DData::clearChanges();
  updateMesh();
#ifdef REC2D_DRAW_WHEN_CLEARED
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
#endif
}

void Recombine2D::updateMesh()
{
  _cur->_gf->triangles = _cur->_data->_tri;
  _cur->_gf->quadrangles = _cur->_data->_quad;
}

void Recombine2D::saveMesh(std::string s)
{
  updateMesh();
  CreateOutputFile(s, 1);
}

void Recombine2D::saveStats(std::fstream *fout)
{
  *fout << Rec2DData::getBlosQual() << " @ " << Rec2DData::getNumElements();
  *fout << " & " << _lastRunTime << " s";
}

void Recombine2D::nextTreeActions(std::vector<Rec2DAction*> &actions,
                                  const std::vector<Rec2DElement*> &neighbourEl,
                                  const Rec2DNode *const node                   )
{
  static int a = 0;
  if (++a == 1) Msg::Warning("FIXME check entities");
  //DEBUG(Rec2DData::checkEntities();)
  actions.clear();

  const Rec2DNode *treeNode = node;
  if (Recombine2D::onlyRecombinations() && Recombine2D::priorityOfOneAction()) {
    if (neighbourEl.size()) { // check if there is one in neighbour
      for (unsigned int i = 0; i < neighbourEl.size(); ++i) {
        if (neighbourEl[i]->getNumActions() == 1)
          actions.push_back(neighbourEl[i]->getAction(0));
      }
      if (actions.size()) {
        Rec2DAction *ra = (*std::max_element(actions.begin(), actions.end(), lessRec2DAction()));
        //Rec2DAction *ra = actions[rand() % actions.size()];
        actions.clear();
        actions.push_back(ra);
        //I(("uio 1"));
        return;
      }
    }
    else if (treeNode) { // try to find one in the sequence
      treeNode = treeNode->getFather();
      while (treeNode && treeNode->isInSequence()) {
        std::vector<Rec2DElement*> elem;
        treeNode->getAction()->getNeighbElemWithActions(elem);
        for (unsigned int i = 0; i < elem.size(); ++i) {
          if (elem[i]->getNumActions() == 1) {
            actions.push_back(elem[i]->getAction(0));
          }
        }
        if (actions.size()) {
          Rec2DAction *ra = actions[rand() % actions.size()];
          actions.clear();
          actions.push_back(ra);
        //I(("uio 2"));
          return;
        }
        treeNode = treeNode->getFather();
      }
    }

    Rec2DData::getUniqueOneActions(actions); // get all One Action
    if (actions.size()) {
      Rec2DAction *ra = actions[rand() % actions.size()];
      actions.clear();
      actions.push_back(ra);
        //I(("uio 3"));
      return;
    }
  }


  std::vector<Rec2DElement*> elements;
  Rec2DAction *ra = NULL;
  Rec2DElement *rel = NULL;
  const Rec2DNode *tmpNode = NULL;
  treeNode = NULL;
  switch (_cur->_strategy) {
  // 0 = every step, choose random triangle
  // 1 = every step, choose best triangle
  //
  // 2 = every step, choose random neighbour triangle
  // 3 = every step, choose best neighbour triangle
  //
  // 4 = FIFS : first in, first surrounded.
  // 5 = treeFIFS, first in, first surrounded in the subtree.
  // 6 = treeFIFS with subtree being deleted every time step.
    case 4 :
      if (!_cur->_curNode->isInSequence()) {
        std::vector<Rec2DElement*> elem;

        if (_cur->_curNode->getFather()) {
          _cur->_curNode->getAction()->getNeighbElemWithActions(elem);
          if (elem.size()) {
            rel = elem[rand() % (int)elem.size()];
            break;
          }
        }

        while (_cur->_curNode->notInSubTree()) {
          _cur->_curNode = _cur->_curNode->getSon();
          _cur->_curNode->getAction()->getNeighbElemWithActions(elem);
          if (elem.size()) {
            rel = elem[rand() % (int)elem.size()];
            break;
          }
        }
        if (rel) break;
        // if not, goto case 5 (i.e. try to find in the sequence)
      }

    case 6 :
    case 5 :
    {
      while (_cur->_curNode->notInSubTree()) _cur->_curNode = _cur->_curNode->getSon();
      std::vector<Rec2DElement*> elem;

      treeNode = _cur->_curNode;
      while (treeNode != node) {
        tmpNode = node;
        while (tmpNode->getFather() != treeNode) tmpNode = tmpNode->getFather();
        treeNode = tmpNode;

        treeNode->getAction()->getNeighbElemWithActions(elem);
        if (elem.size()) {
          rel = elem[rand() % (int)elem.size()];
          break;
        }
      }
      if (rel) break;
    }

    default :
    case 3 : // triangle of best neighbour action
      //I(("3"));
      for (unsigned int i = 0; i < neighbourEl.size(); ++i)
        neighbourEl[i]->getMoreUniqueActions(actions);
      if (actions.size()) {
        (*std::max_element(actions.begin(), actions.end(), lessRec2DAction()))
          ->getElements(elements);
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
    //I(("2"));
      if (neighbourEl.size()) {
        rel = neighbourEl[rand() % (int)neighbourEl.size()];
        break;
      }

    case 1 : // random triangle of best action
    //I(("1"));
      if (Recombine2D::onlyRecombinations() && _cur->_strategy != 1 && node) {
        static int aa = 0;
        if (++aa == 1) Msg::Warning("Why should I keep this ? Why only if only rec");
        treeNode = node->getFather();
        while (treeNode && treeNode->isInSequence()) {
          std::vector<Rec2DElement*> elem;
          treeNode->getAction()->getNeighbElemWithActions(elem);
          for (unsigned int i = 0; i < elem.size(); ++i)
            elem[i]->getMoreUniqueActions(actions);
          if (actions.size()) {
            (*std::max_element(actions.begin(), actions.end(), lessRec2DAction()))
              ->getElements(elements);
            for (unsigned int i = 0; i < elements.size(); ++i) {
              for (unsigned int j = 0; j < elem.size(); ++j) {
                if (elements[i] == elem[j]) {
                  rel = elements[i];
                  goto end2;
                }
              }
            }
          }
          actions.clear();
          treeNode = treeNode->getFather();
        }
end2 :
        if (rel) break;
      }
      ra = Rec2DData::getBestAction();
      if (!ra) return;
      rel = ra->getRandomElement();
      break;
    case 0 : // random triangle of random action
      ra = Rec2DData::getRandomAction();
      if (!ra) return;
      rel = ra->getRandomElement();
      break;
  }
//#ifdef REC2D_DRAW
//  unsigned int col = CTX::instance()->packColor(90, 128, 85, 255);
//  rel->getMElement()->setCol(col);
//#endif
  rel->getActions(actions);
  unsigned int i = 0;
  while (i < actions.size()) {
    if (actions[i]->isObsolete()) {
      E(("SHOULD I BE HERE ??"));
#ifdef DRAW_IF_ERROR
      static int a = 0;
      if (++a == 1) Msg::Warning("FIXME Normal to be here ?");
      actions[i]->color(190, 0, 0);
      double time = Cpu();
      CTX::instance()->mesh.changed = ENT_ALL;
      drawContext::global()->draw();
      while (Cpu()-time < 5)
        FlGui::instance()->check();
#endif
      actions[i] = actions.back();
      actions.pop_back();
    }
    else
      ++i;
  }
  //I(( "get %d actions", actions.size() ));
}

void Recombine2D::compareWithBlossom()
{
  Msg::Error("..............begin..............");
  //recombineWithBlossom(_gf, .0, 1.1, elist, t2n);// no more in the code (see Amaury)
  _data->_quad = _gf->quadrangles;
  Recombine2D::drawStateOrigin();
  __wait(3);
  drawState(.0,-1.1);
  setStrategy(3);
  int num = 2;
  double dx = .0, dy = .0, time = Cpu();
  for (int d = 1; d < 7; ++d) {
    recombine(d);
    if ( d % ((int)std::sqrt(num)+1) ) {
      dx += 3.3;
    }
    else {
      dx = .0;
      dy -= 1.1;
    }
    drawState(dx, dy, true);
    CTX::instance()->mesh.changed = ENT_ALL;
#ifdef REC2D_DRAW
    drawContext::global()->draw();
    //while (Cpu()-time < REC2D_WAIT_TIME)
    //  FlGui::instance()->check();
#endif
    time = Cpu();
  }
  int totalBlossom = 0;
  for (int k = 0; k < _cur->elist[0]; ++k) totalBlossom += 100-_cur->elist[1+3*k+2];
  Msg::Info("Blossom %d", totalBlossom);
  delete elist;
  t2n.clear();

  Rec2DData::clearChanges();
#ifdef DRAW_WHEN_SELECTED // draw state at origin
    __drawWait(time, REC2D_WAIT_SELECTED);
#endif
}

int Recombine2D::computeQualBlossom() const
{
  int qualBlos = 0;
  for (int i = 0; i < elist[0]; ++i) {
    qualBlos += elist[3*i+3];
  }
  return 100*elist[0]-qualBlos;
}

void Recombine2D::printState() const
{
  _data->printState();
}

void Recombine2D::drawState(double shiftx, double shifty, bool color) const
{
#ifdef REC2D_DRAW
  //_data->drawElements(shiftx, shifty);
  _data->drawTriangles(shiftx, shifty);
  _data->drawChanges(shiftx, shifty, color);
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
#endif
}

void Recombine2D::drawStateOrigin()
{
#ifdef REC2D_DRAW
  //_cur->_data->_tri.clear();
  _cur->updateMesh();
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
#endif
}

void Recombine2D::add(MQuadrangle *q)
{
  _cur->_gf->quadrangles.push_back(q);
  _cur->_data->_quad.push_back(q);
}

void Recombine2D::add(MTriangle *t)
{
  _cur->_gf->triangles.push_back(t);
  _cur->_data->_tri.push_back(t);
}


void Recombine2D::colorFromBlossom(const Rec2DElement *tri1,
                                   const Rec2DElement *tri2,
                                   const Rec2DElement *quad )
{
#ifdef REC2D_DRAW
  if (!_cur->elist) {
    Msg::Error("no list");
    return;
  }
  int i1 = _cur->t2n[tri1->getMElement()];
  int i2 = _cur->t2n[tri2->getMElement()];
  int k = -1;
  while (++k < _cur->elist[0] &&
         _cur->elist[1+3*k] != i1 &&
         _cur->elist[1+3*k] != i2   );
  if (k < _cur->elist[0] && (_cur->elist[1+3*k+1] == i1 ||
                             _cur->elist[1+3*k+1] == i2   )) {
    unsigned int col = CTX::instance()->packColor(200, 120, 225, 255);
    //quad->getMElement()->setCol(col);// no more in the code (see Amaury)
  }
#endif
}

void Recombine2D::colorFromBlossom(const Rec2DElement *tri1,
                                   const Rec2DElement *tri2,
                                   const MElement *quad     )
{
  if (!_cur->elist) {
    Msg::Error("no list");
    return;
  }
  int i1 = _cur->t2n[tri1->getMElement()];
  int i2 = _cur->t2n[tri2->getMElement()];
  int k = -1;
  while (++k < _cur->elist[0] && _cur->elist[1+3*k] != i1 && _cur->elist[1+3*k] != i2);
  if (k < _cur->elist[0] &&
      (_cur->elist[1+3*k+1] == i1 || _cur->elist[1+3*k+1] == i2)) {
    unsigned int col = CTX::instance()->packColor(200, 120, 225, 255);
    //((MElement*)quad)->setCol(col);// no more in the code (see Amaury)
  }
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


/**  Rec2DData  **/
/*****************/
bool Rec2DData::gterAction::operator()(const Action *ra1, const Action *ra2) const
{
  return *ra2->action < *ra1->action;
}

bool Rec2DData::lessAction::operator()(const Action *ra1, const Action *ra2) const
{
  return *ra1->action < *ra2->action;
}

void Rec2DData::Action::update()
{
  ((Rec2DAction*)action)->_dataAction = this;
}
Rec2DData::Rec2DData()
{
  if (Rec2DData::_cur != NULL) {
    Msg::Error("[Rec2DData] An instance in execution");
    return;
  }
  Rec2DData::_cur = this;
  _numEdge = _numVert = 0;
  _1valVert = _2valVert = _2valEdge = .0;
  _0blossomQuality = 0;
}

Rec2DData::~Rec2DData()
{
  if (Rec2DData::_cur == this)
    Rec2DData::_cur = NULL;
}

double Rec2DData::getValVert(Rec2DQualCrit crit)
{
  if (crit == ChoosedCrit) crit = Recombine2D::getQualCrit();

  switch (crit) {
    case BlossomQuality :
      return -1.;

    case VertQuality :
      return static_cast<double>(_cur->_1valVert);

    case VertEdgeQuality :
      return static_cast<double>(_cur->_2valVert);

    default :
      Msg::Error("[Rec2DData:getValVert] Unknown quality criterion");
  }
  return -1.;
}

void Rec2DData::elementChgAction(Rec2DElement *re, int from, int to)
{
  if (from == to) return;

  if (to < 0 || to > 3) Msg::Error("[Rec2DData::elementChgAction] Wrong argument");

  switch (from) {
  case 0: break;
  case 1:
    _cur->_el_1Actions.rmv(re);
    break;
  case 2:
    _cur->_el_2Actions.rmv(re);
    break;
  case 3:
    _cur->_el_3Actions.rmv(re);
    break;
  default:
    Msg::Error("[Rec2DData::elementChgAction] Wrong argument");
    return;
  }

  switch (to) {
  case 1:
    _cur->_el_1Actions.add(re);
    break;
  case 2:
    _cur->_el_2Actions.add(re);
    break;
  case 3:
    _cur->_el_3Actions.add(re);
    break;
  }
}

void Rec2DData::add(const Rec2DEdge *re)
{
  if (re->_pos > -1) {
    Msg::Error("[Rec2DData] edge already there");
    return;
  }
  ((Rec2DEdge*)re)->_pos = _cur->_edges.size();
  _cur->_edges.push_back((Rec2DEdge*)re);

  _cur->_numEdge += re->getWeight();
  _cur->_2valEdge +=re->getWeightedQual();
}

void Rec2DData::add(const Rec2DVertex *rv)
{
  if (rv->_pos > -1) {
    Msg::Error("[Rec2DData] vert %d already there (size %d)", rv, _cur->_vertices.size());
    return;
  }
  ((Rec2DVertex*)rv)->_pos = _cur->_vertices.size();
  _cur->_vertices.push_back((Rec2DVertex*)rv);

  ++_cur->_numVert;
  _cur->_1valVert += rv->getQual(VertQuality);
  _cur->_2valVert += rv->getQual(VertEdgeQuality);
}

void Rec2DData::add(const Rec2DElement *rel)
{
  if (rel->_pos > -1) {
    Msg::Error("[Rec2DData] elem already there");
    return;
  }
  ((Rec2DElement*)rel)->_pos = _cur->_elements.size();
  _cur->_elements.push_back((Rec2DElement*)rel);
  _cur->_mel2rel[rel->getMElement()] = (Rec2DElement*)rel;

#if 1//def REC2D_DRAW
  MTriangle *t = rel->getMTriangle();
  MQuadrangle *q = rel->getMQuadrangle();
  if (t) _cur->_tri.push_back(t);
  if (q) _cur->_quad.push_back(q);
#endif
}

void Rec2DData::rmv(const Rec2DEdge *re)
{
  if (re->_pos < 0) {
    Msg::Error("[Rec2DData] edge not there");
    return;
  }
  _cur->_edges.back()->_pos = re->_pos;
  _cur->_edges[re->_pos] = _cur->_edges.back();
  _cur->_edges.pop_back();
  ((Rec2DEdge*)re)->_pos = -1;

  _cur->_numEdge -= re->getWeight();
  _cur->_2valEdge -=re->getWeightedQual();
}

void Rec2DData::rmv(const Rec2DVertex *rv)
{
  if (rv->_pos < 0) {
    Msg::Error("[Rec2DData] vert not there");
    return;
  }
  _cur->_vertices.back()->_pos = rv->_pos;
  _cur->_vertices[rv->_pos] = _cur->_vertices.back();
  _cur->_vertices.pop_back();
  ((Rec2DVertex*)rv)->_pos = -1;

  --_cur->_numVert;
  _cur->_1valVert -= rv->getQual(VertQuality);
  _cur->_2valVert -= rv->getQual(VertEdgeQuality);
}

void Rec2DData::rmv(const Rec2DElement *rel)
{
  if (rel->_pos < 0) {
    Msg::Error("[Rec2DData] vert not there");
    return;
  }
  _cur->_elements.back()->_pos = rel->_pos;
  _cur->_elements[rel->_pos] = _cur->_elements.back();
  _cur->_elements.pop_back();
  ((Rec2DElement*)rel)->_pos = -1;
  _cur->_mel2rel.erase(rel->getMElement());

#if 1//def REC2D_DRAW
  MTriangle *t = rel->getMTriangle();
  if (t) {
    for (unsigned int i = 0; i < _cur->_tri.size(); ++i) {
      if (_cur->_tri[i] == t) {
        _cur->_tri[i] = _cur->_tri.back();
        _cur->_tri.pop_back();
        return;
      }
    }
    Msg::Warning("[Rec2DData] Didn't erased mtriangle :(");
  }
  MQuadrangle *q = rel->getMQuadrangle();
  if (q) {
    for (unsigned int i = 0; i < _cur->_quad.size(); ++i) {
      if (_cur->_quad[i] == q) {
        _cur->_quad[i] = _cur->_quad.back();
        delete _cur->_quad.back();
        _cur->_quad.pop_back();
        return;
      }
    }
    Msg::Warning("[Rec2DData] Didn't erased mquadrangle :(");
  }
#endif
}

void Rec2DData::add(const Rec2DAction *ra)
{
  if (ra->_dataAction) {
    Msg::Error("[Rec2DData] action already there");
    ra->printIdentity();
    return;
  }
  _cur->_actions.push_back(new Action(ra, _cur->_actions.size()));
  ((Rec2DAction*)ra)->_dataAction = _cur->_actions.back();

  _cur->_sortedActions.insert((Rec2DAction*)ra);
}

void Rec2DData::rmv(const Rec2DAction *ra)
{
  if (!ra->_dataAction) {
    Msg::Error("[Rec2DData] action not there");
    return;
  }
  std::swap(*((Action*)ra->_dataAction), *_cur->_actions.back());
  ((Rec2DAction*)ra)->_dataAction = NULL;
  delete _cur->_actions.back();
  _cur->_actions.pop_back();

  _cur->_sortedActions.erase((Rec2DAction*)ra);
}

bool Rec2DData::has(const Rec2DAction *ra)
{
  return ra->_dataAction;
}

Rec2DAction* Rec2DData::getBestAction()
{
  if (_cur->_actions.size() == 0)
    return NULL;
  /*Action *ac = *std::max_element(_cur->_actions.begin(),
                                 _cur->_actions.end(), lessAction());

  return const_cast<Rec2DAction*>(ac->action);*/
  return *(_cur->_sortedActions.begin());
}

Rec2DAction* Rec2DData::getRandomAction()
{
  if (_cur->_actions.size() == 0)
    return NULL;
  int index = rand() % (int)_cur->_actions.size();
  return (Rec2DAction*)_cur->_actions[index]->action;
}

void Rec2DData::checkObsolete()
{
  std::vector<Rec2DAction*> obsoletes;
  for (unsigned int i = 0; i < _cur->_actions.size(); ++i) {
    if (_cur->_actions[i]->action->isObsolete())
      obsoletes.push_back((Rec2DAction*)_cur->_actions[i]->action);
  }

  for (unsigned int i = 0; i < obsoletes.size(); ++i)
    delete obsoletes[i];
}

Rec2DElement* Rec2DData::getBestLessAction()
{
  Msg::Fatal("[Rec2DData::getBestAction] Need definition");
  return NULL;
}

Rec2DElement* Rec2DData::getRandomLessAction()
{
  Rec2DElement *re;
  re = _cur->_el_1Actions.getRandom();
  if (re) return re;
  re = _cur->_el_2Actions.getRandom();
  if (re) return re;
  re = _cur->_el_3Actions.getRandom();
  return re;
}

void Rec2DData::addHasZeroAction(const Rec2DElement *rel)
{
  std::pair<std::set<Rec2DElement*>::iterator, bool> rep;
  rep = _cur->_elementWithZeroAction.insert((Rec2DElement*)rel);
  if (!rep.second)
    Msg::Error("[Rec2DData] elementWithZeroAction already there");
}

void Rec2DData::rmvHasZeroAction(const Rec2DElement *rel)
{
  if (!_cur->_elementWithZeroAction.erase((Rec2DElement*)rel))
    Msg::Error("[Rec2DData] elementWithZeroAction not there");
}

bool Rec2DData::hasHasZeroAction(const Rec2DElement *rel)
{
  return _cur->_elementWithZeroAction.find((Rec2DElement*)rel)
         != _cur->_elementWithZeroAction.end();
}

int Rec2DData::getNumZeroAction()
{
  return _cur->_elementWithZeroAction.size();
}

void Rec2DData::addHasOneAction(const Rec2DElement *rel, Rec2DAction *ra)
{
  std::pair<std::set<Rec2DElement*>::iterator, bool> rep;
  rep = _cur->_elementWithOneAction.insert((Rec2DElement*)rel);
  if (!rep.second)
    Msg::Error("[Rec2DData] elementWithOneAction already there");

  std::pair<std::set<Rec2DAction*, gterRec2DAction>::iterator, bool> p;
  p = _cur->_sortedOActions.insert(ra);
  if (p.second) _cur->_OActions.push_back(ra);
}

void Rec2DData::rmvHasOneAction(const Rec2DElement *rel, Rec2DAction *ra)
{
  if (!_cur->_elementWithOneAction.erase((Rec2DElement*)rel))
    Msg::Error("[Rec2DData] elementWithOneAction not there");

  Rec2DElement *el;
  if (ra->getElement(0) == rel) el = ra->getElement(1);
  else if (ra->getElement(1) == rel) el = ra->getElement(0);
  else {
    Msg::Fatal("Does not work as expected");
    return;
  }

  if ((el->getNumActions() != 1 || el->getAction(0) != ra) &&
      !_cur->_sortedOActions.erase(ra))
    Msg::Fatal("Does not work as expected 2");
}

bool Rec2DData::hasHasOneAction(const Rec2DElement *rel)
{
  return _cur->_elementWithOneAction.find((Rec2DElement*)rel)
         != _cur->_elementWithOneAction.end();
}

int Rec2DData::getNumOneAction()
{
  return _cur->_elementWithOneAction.size();
}

Rec2DAction* Rec2DData::getOneAction()
{
  if (_cur->_elementWithOneAction.size())
    return (*_cur->_elementWithOneAction.begin())->getAction(0);
  return NULL;
}

void Rec2DData::getElementsOneAction(std::vector<Rec2DElement*> &v)
{
  v.clear();
  std::set<Rec2DElement*>::iterator it = _cur->_elementWithOneAction.begin();
  while (it != _cur->_elementWithOneAction.end()) {
    v.push_back(*it);
    ++it;
  }
}

void Rec2DData::getUniqueOneActions(std::vector<Rec2DAction*> &vec)
{
  std::set<Rec2DElement*> elemWOA = _cur->_elementWithOneAction;
  std::set<Rec2DElement*>::iterator it = elemWOA.begin();
  std::vector<Rec2DAction*> *v;
  int minNum = 0;
  if (it != elemWOA.end()) {
    Rec2DAction *ra = (*it)->getAction(0);
    Rec2DDataChange *dataChange = Rec2DData::getNewDataChange();
    ra->apply(dataChange, v);
    minNum = Rec2DData::getNumOneAction();
    Rec2DData::revertDataChange(dataChange);
    vec.push_back(ra);
    ++it;
  }
  while (it != elemWOA.end()) {
    Rec2DAction *ra = (*it)->getAction(0);
    Rec2DDataChange *dataChange = Rec2DData::getNewDataChange();
    ra->apply(dataChange, v);
    if (minNum > Rec2DData::getNumOneAction()) {
      minNum = Rec2DData::getNumOneAction();
      vec.clear();
      vec.push_back(ra);
    }
    else if (minNum == Rec2DData::getNumOneAction()) {
      unsigned int i = 0;
      while (i < vec.size() && vec[i] != ra) ++i;
      if (i == vec.size()) vec.push_back(ra);
    }
    Rec2DData::revertDataChange(dataChange);
    ++it;
  }
}

int Rec2DData::getNewParity()
{
  if (_cur->_parities.empty())
    return 2;
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  it = _cur->_parities.end();
  return ((--it)->first/2)*2 + 2;
}

void Rec2DData::removeParity(const Rec2DVertex *rv, int p)
{
  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  if ( (it = _cur->_parities.find(p)) == _cur->_parities.end() ) {
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
    _cur->_parities.erase(it);
}

void Rec2DData::associateParity(int pOld, int pNew, Rec2DDataChange *rdc)
{
  if (pOld/2 == pNew/2) {
    Msg::Error("[Rec2DData] Do you want to make a mess of parities ?");
    return;
  }
  if (_cur->_parities.find(pNew) == _cur->_parities.end()) {
    Msg::Warning("[Rec2DData] That's strange, isn't it ?");
    static int a = 0;
    if (++a == 10)
      Msg::Warning("[Rec2DData] AND LOOK AT ME WHEN I TALK TO YOU !");
  }

  std::map<int, std::vector<Rec2DVertex*> >::iterator it;
  std::vector<Rec2DVertex*> *vect, *vectNew;
  {
    it = _cur->_parities.find(pOld);
    if (it == _cur->_parities.end()) {
      static int a = 0;
      if (++a == 1)
        Msg::Error("[Rec2DData] You are mistaken, I'll never talk to you again !");
      return;
    }
    vect = &it->second;
    if (rdc) {
      rdc->saveParity(*vect);
      //rdc->checkObsoleteActions(_vertices, 4);
    }
    for (unsigned int i = 0; i < vect->size(); ++i)
      (*vect)[i]->setParityWD(pOld, pNew);
    rdc->checkObsoleteActions(&(*vect)[0], vect->size());
    vectNew = &_cur->_parities[pNew];
    vectNew->insert(vectNew->end(), vect->begin(), vect->end());
    _cur->_parities.erase(it);
  }

  pOld = otherParity(pOld);
  pNew = otherParity(pNew);
  {
    it = _cur->_parities.find(pOld);
    if (it == _cur->_parities.end()) {
      Msg::Error("[Rec2DData] What ?");
      return;
    }
    vect = &it->second;
    if (rdc)
      rdc->saveParity(*vect);
    for (unsigned int i = 0; i < vect->size(); ++i)
      (*vect)[i]->setParityWD(pOld, pNew);
    rdc->checkObsoleteActions(&(*vect)[0], vect->size());
    vectNew = &_cur->_parities[pNew];
    vectNew->insert(vectNew->end(), vect->begin(), vect->end());
    _cur->_parities.erase(it);
  }
}

Rec2DDataChange* Rec2DData::getNewDataChange()
{
  _cur->_changes.push_back(new Rec2DDataChange());
  return _cur->_changes.back();
}

bool Rec2DData::revertDataChange(Rec2DDataChange *rdc)
{
  if (_cur->_changes.back() != rdc)
    return false;
  _cur->_changes.pop_back();
  rdc->revert();
  delete rdc;
  return true;
}

void Rec2DData::clearChanges()
{
  for (int i = (int) _cur->_changes.size() - 1; i > -1; --i) {
    _cur->_changes[i]->revert();
    delete _cur->_changes[i];
  }
  _cur->_changes.clear();
  Rec2DAlgo::clear();
}

double Rec2DData::getGlobalQuality(Rec2DQualCrit crit)
{
  if (crit == ChoosedCrit) crit = Recombine2D::getQualCrit();

  switch(crit) {
    case BlossomQuality :
      return _cur->_0blossomQuality;

    case VertQuality :
      return static_cast<double>(_cur->_1valVert) / _cur->_numVert;

    case VertEdgeQuality :
      return static_cast<double>(_cur->_2valVert) / _cur->_numVert
             *static_cast<double>(_cur->_2valEdge) / _cur->_numEdge;

    default :
      Msg::Error("[Rec2DData:getGlobalQuality] Unknown quality criterion");
  }
  return -1.;
}

double Rec2DData::getGlobalQuality(int numVert, double valVert,
                                   int numEdge, double valEdge,
                                   Rec2DQualCrit crit          )
{
  if (crit == ChoosedCrit) crit = Recombine2D::getQualCrit();

  switch (crit) {
    case BlossomQuality :
      return _cur->_0blossomQuality;

    case VertQuality :
      return (static_cast<double>(_cur->_1valVert) + valVert) / (_cur->_numVert + numVert);

    case VertEdgeQuality :
      return (static_cast<double>(_cur->_2valVert) + valVert) / (_cur->_numVert + numVert)
             *(static_cast<double>(_cur->_2valEdge) + valEdge) / (_cur->_numEdge + numEdge);

    default :
      Msg::Error("[Rec2DData:getGlobalQuality] Unknown quality criterion");
  }
  return -1.;
}

void Rec2DData::updateVertQual(double val, Rec2DQualCrit crit)
{
  switch (crit) {
    case VertQuality :
      _cur->_1valVert += val;
      return;

    case VertEdgeQuality :
      _cur->_2valVert += val;
      return;

    default :
      Msg::Error("[Rec2DData:updateVertQual] Unknown quality criterion");
  }
}

bool Rec2DData::checkEntities()
{
  /*if (Recombine2D::onlyRecombinations()) {
    std::set<Rec2DElement*>::iterator it = _cur->_elementWithOneAction.begin();
    while (it != _cur->_elementWithOneAction.end()) {
      if ((*it)->getNumActions() != 1) {
        Msg::Error("Incoherence element with one action");
        //__crash();
        return false;
      }
      ++it;
    }
    it = _cur->_elementWithZeroAction.begin();
    while (it != _cur->_elementWithZeroAction.end()) {
      if ((*it)->getNumActions() != 0) {
        Msg::Error("Incoherence element with zero action");
        //__crash();
        return false;
      }
      ++it;
    }
  }
  iter_rel itel1;
  for (itel1 = firstElement(); itel1 != lastElement(); ++itel1) {
    if (!(*itel1)->checkCoherence()) {
      Msg::Error("Incoherence element");
      //__crash();
      return false;
    }
  }
  return true;*/

  Msg::Error("Need redefinition");
  __crash();
  iter_rv itv;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    if (!(*itv)->checkCoherence()) {
      Msg::Error("Incoherence vertex");
      //__crash();
      return false;
    }
    if (!(*itv)->checkQuality()) {
      Msg::Error("Wrong qualities vertex");
      //__crash();
      return false;
    }
  }
  iter_re ite;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    if (!(*ite)->checkCoherence()) {
      Msg::Error("Incoherence edge");
      //__crash();
      return false;
    }
  }
  iter_rel itel;
  for (itel = firstElement(); itel != lastElement(); ++itel) {
    if (!(*itel)->checkCoherence()) {
      Msg::Error("Incoherence element");
      //__crash();
      return false;
    }
  }

  if (Recombine2D::onlyRecombinations()) {
    std::set<Rec2DElement*>::iterator it = _cur->_elementWithOneAction.begin();
    while (it != _cur->_elementWithOneAction.end()) {
      if ((*it)->getNumActions() != 1) {
        Msg::Error("Incoherence element with one action");
        //__crash();
        return false;
      }
      ++it;
    }
    it = _cur->_elementWithZeroAction.begin();
    while (it != _cur->_elementWithZeroAction.end()) {
      if ((*it)->getNumActions() != 0) {
        Msg::Error("Incoherence element with zero action");
        //__crash();
        return false;
      }
      ++it;
    }
  }
  for (unsigned int i = 0; i < _cur->_actions.size(); ++i) {
    if (_cur->_actions[i]->position != i ||
        _cur->_actions[i]->action->getDataAction() != _cur->_actions[i]) {
      Msg::Error("Wrong link Action <-> Rec2DAction");
      //__crash();
      //return false;
    }
    if (!_cur->_actions[i]->action->checkCoherence()) {
      _cur->printState();
#ifdef REC2D_DRAW
      double time = Cpu();
      while (Cpu()-time < REC2D_WAIT_TM_2)
        FlGui::instance()->check();
#endif
      Msg::Error("Incoherence action");
      //__crash();
      //return false;
    }
  }
  return true;
}

void Rec2DData::checkQuality() const
{
  Msg::Error("need redefinition");
  __crash();
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
  if (fabs(valVert - _2valVert) > 1e-14 || fabs(valEdge - _2valEdge) > 1e-14) {
    Msg::Error("Vert : %g >< %g (%g), %d >< %d", (double)valVert, (double)_2valVert, (double)(valVert-_2valVert), numVert, _numVert);
    Msg::Error("Edge : %g >< %g (%g), %d >< %d", (double)valEdge, (double)_2valEdge, (double)(valEdge-_2valEdge), numEdge, _numEdge);
  }
}

void Rec2DData::printState() const
{
  Msg::Info(" ");
  Msg::Info("State");
  Msg::Info("-----");
  Msg::Info("numEdge %d (%d), valEdge %g => %g", _numEdge, _edges.size(), (double)_2valEdge, (double)_2valEdge/(double)_numEdge);
  Msg::Info("numVert %d (%d), valVert %g => %g", _numVert, _vertices.size(), (double)_2valVert, (double)_2valVert/(double)_numVert);
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
  int numEdge = 0;
  for (ite = firstEdge(); ite != lastEdge(); ++ite) {
    valEdge += (long double)(*ite)->getWeightedQual();
    numEdge += (*ite)->getWeight();
  }
  Msg::Info("valEdge : %g >< %g, numEdge %d >< %d (real><data)",
            (double)valEdge, (double)_2valEdge,
            numEdge, _numEdge);
  iter_rv itv;
  long double valVert = .0;
  int numVert = 0;
  for (itv = firstVertex(); itv != lastVertex(); ++itv) {
    valVert += (long double)(*itv)->getQual(VertEdgeQuality);
    if ((*itv)->getParity() == -1 || (*itv)->getParity() == 1)
      Msg::Error("parity %d, I'm very angry", (*itv)->getParity());
    ++numVert;
  }
  Msg::Info("valVert : %g >< %g, numVert %d >< %d (real><data)",
            (double)valVert, (double)_2valVert,
            numVert, _numVert);
  Msg::Info("----- (end)");
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
#ifdef HAVE_FLTK
  new PView("Jmin_bad", "ElementData", Recombine2D::getGFace()->model(), data);
#endif
  Msg::Info(" ");
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

void Rec2DData::drawChanges(double shiftx, double shifty, bool color) const
{
  std::map<int, std::vector<double> > data;
  int k = 0;
  for (unsigned int i = 0; i < _changes.size(); ++i) {
    if (_changes[i]->getAction()->haveElem()) {
      MElement *el = _changes[i]->getAction()->createMElement(shiftx, shifty);
      if (color)
        Recombine2D::colorFromBlossom(_changes[i]->getAction()->getElement(0),
                                      _changes[i]->getAction()->getElement(1),
                                      el                                     );
      data[el->getNum()].push_back(++k);
    }
  }
#ifdef HAVE_FLTK
  new PView("Changes", "ElementData", Recombine2D::getGFace()->model(), data);
#endif
}

void Rec2DData::addEndNode(const Rec2DNode *rn)
{
  static int k = 0;
  if (_cur->_endNodes.size() > 9999) {
    Msg::Info("%d", ++k);
    sortEndNode();
    int newLast = 4999;
    for (unsigned int i = newLast + 1; i < 10000; ++i) {
      if (_cur->_endNodes[i]->canBeDeleted())
        delete _cur->_endNodes[i];
      else
        _cur->_endNodes[++newLast] = _cur->_endNodes[i];
    }
    _cur->_endNodes.resize(newLast + 1);
  }
  _cur->_endNodes.push_back((Rec2DNode*)rn);
}

void Rec2DData::sortEndNode()
{
  std::sort(_cur->_endNodes.begin(),
            _cur->_endNodes.end(),
            gterRec2DNode());
}

void Rec2DData::drawEndNode(int num)
{
  double dx = .0, dy = .0;
  for (int i = 0; i < num && i < (int)_cur->_endNodes.size(); ++i) {
    std::map<int, std::vector<double> > data;
    Rec2DNode *currentNode = _cur->_endNodes[i];
    //Msg::Info("%d -> %g", i+1, currentNode->getGlobQual());
    //int k = 0;
    if ( !((i+1) % ((int)std::sqrt(num)+1)) ) {
      dx = .0;
      dy -= 1.2;
    }
    else
      dx += 1.2;
    currentNode->draw(dx, dy);
    Rec2DData::clearChanges();
    /*while (currentNode && currentNode->getAction()) {
      //Msg::Info("%g", currentNode->getGlobQual());
      //data[currentNode->getNum()].push_back(currentNode->getGlobQual());
      if (currentNode->getAction()->haveElem())
        data[currentNode->getAction()->getNum(dx, dy)].push_back(++k);
      currentNode = currentNode->getFather();
    }*/
#ifdef HAVE_FLTK
    //new PView("Jmin_bad", "ElementData", Recombine2D::getGFace()->model(), data);
#endif
  }
}

Rec2DElement* Rec2DData::getRElement(MElement *mel)
{
  std::map<MElement*, Rec2DElement*>::iterator it;
  it = _cur->_mel2rel.find(mel);
  if (it == _cur->_mel2rel.end()) return NULL;
  return it->second;
}

/**  Rec2DChange  **/
/*******************/
Rec2DChange::Rec2DChange(int a) : _info(NULL)
{
  _entity = new int(a);
  _type = ValQuad;
  Rec2DData::addBlosQual(a);
}

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
    static int a = 0;
    if (++a == 1) Msg::Warning("FIXME peut pas faire sans pointing ?");
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
    Rec2DElement *rel = Rec2DEdge::getTheOnlyElement(re0);
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

void Rec2DChange::getHiddenActions(std::set<Rec2DAction*> &set)
{
  switch (_type) {
    case HideAction :
      set.insert((Rec2DAction*)_entity);
      return;

    case HideActions :
      set.insert(((std::vector<Rec2DAction*>*)_entity)->begin(),
          ((std::vector<Rec2DAction*>*)_entity)->end());
      return;

    default :
      return;
  }
}

void Rec2DChange::revert()
{
  switch (_type) {
    case ValQuad :
      Rec2DData::addBlosQual(-*(int*)_entity);
      delete (int*)_entity;
      break;

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
      delete (Rec2DAction*)_entity;
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
  if (elem[0]) elem[0]->getMoreUniqueActions(actions);
  if (elem[1]) elem[1]->getMoreUniqueActions(actions);
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
  for (unsigned int i = 0; i < elem.size(); ++i)
    elem[i]->getMoreUniqueActions(actions);
  Rec2DAction::removeDuplicate(actions);
  _changes.push_back(new Rec2DChange(rv0, elem, RemoveElem));
  _changes.push_back(new Rec2DChange(rv0, rv1, edges, SwapVertInEdge));
  _changes.push_back(new Rec2DChange(rv0, rv1, actions, SwapVertInAction));
  _changes.push_back(new Rec2DChange(rv1, elem, AddElem));
  _changes.push_back(new Rec2DChange(rv0, rv1, elem, SwapMVertInElement));
}

void Rec2DDataChange::checkObsoleteActions(Rec2DVertex *const*verts, int size)
{
  std::vector<Rec2DAction*> actions;
  for (int i = 0; i < size; ++i) {
    verts[i]->getMoreUniqueActions(actions);
  }
  for (unsigned int i = 0; i < actions.size(); ++i) {
    if (actions[i]->isObsolete())
      hide(actions[i]);
  }
}

void Rec2DDataChange::getHiddenActions(std::set<Rec2DAction*> &set)
{
  for (unsigned int i = 0; i < _changes.size(); ++i) {
     _changes[i]->getHiddenActions(set);
  }
}

void Rec2DDataChange::revert()
{
  for (int i = (int)_changes.size() - 1; i > -1; --i)
    _changes[i]->revert();
}


/**  Rec2DAction  **/
/*******************/
bool lessRec2DAction::operator()(const Rec2DAction *ra1, const Rec2DAction *ra2) const
{
  return *ra1 < *ra2;
}

bool gterRec2DAction::operator()(const Rec2DAction *ra1, const Rec2DAction *ra2) const
{
  return *ra2 < *ra1;
}

Rec2DAction::Rec2DAction()
: _globQualIfExecuted(.0), _lastUpdate(-2), _numPointing(0), _dataAction(NULL)
{
}

double Rec2DAction::getReward() const
{
  if (_lastUpdate < Recombine2D::getNumChange())
    ((Rec2DAction*)this)->_computeGlobQual();

  return _globQualIfExecuted/* - Rec2DData::getGlobalQuality()*/;
}

double Rec2DAction::getRealReward() const
{
  if (_lastUpdate < Recombine2D::getNumChange())
    ((Rec2DAction*)this)->_computeReward();

  return _reward;
}


bool Rec2DAction::operator<(const Rec2DAction &other) const
{
  //return getReward() < other.getReward();
  if (getRealReward() == other.getRealReward())
    return this < &other;
  else
    return getRealReward() < other.getRealReward();
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

/**  Rec2DTwoTri2Quad  **/
/************************/
/* (2)---0---(0)
 *  | {0}   / |
 *  1    4    3
 *  | /   {1} |
 * (1)---2---(3)
 */
Rec2DTwoTri2Quad::Rec2DTwoTri2Quad(Rec2DElement *el0, Rec2DElement *el1)
{
  _triangles[0] = el0;
  _triangles[1] = el1;
  _edges[4] = Rec2DElement::getCommonEdge(el0, el1);

  // get edges
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

  // get vertices
  _vertices[0] = _edges[4]->getVertex(0);
  _vertices[1] = _edges[4]->getVertex(1);
  _vertices[2] = _triangles[0]->getOtherVertex(_vertices[0], _vertices[1]);
  _vertices[3] = _triangles[1]->getOtherVertex(_vertices[0], _vertices[1]);
  // reorder if needed
  if (_vertices[0] == _edges[1]->getOtherVertex(_vertices[2])) {
    Rec2DVertex *rv = _vertices[0];
    _vertices[0] = _vertices[1];
    _vertices[1] = rv;
  }

  //
  _rt = new RecombineTriangle(MEdge(_vertices[0]->getMVertex(),
                                    _vertices[1]->getMVertex() ),
                              _triangles[0]->getMElement(),
                              _triangles[1]->getMElement()       );
  reveal();

  if (!edgesAreInOrder(_edges, 4)) Msg::Error("recomb |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
}

void Rec2DTwoTri2Quad::operator delete(void *p)
{
  if (!p) return;
  Rec2DTwoTri2Quad *ra = (Rec2DTwoTri2Quad*)p;
  if (ra->_dataAction) { // ra->hide()
    ra->_triangles[0]->rmv(ra);
    ra->_triangles[1]->rmv(ra);
    Rec2DData::rmv(ra);
  }
  if (!ra->_numPointing) {
    //Msg::Info("del ac %d", p);
    if (ra->_col) {
      static int a = 0;
      if (++a == 1) Msg::Warning("FIXME Il faut supprimer les hidden a la fin...");
      Rec2DData::addHidden((Rec2DAction*)p);
    }
    else
      free(p);
  }
}

void Rec2DTwoTri2Quad::hide()
{
  if (_triangles[0])
    _triangles[0]->rmv(this);
  if (_triangles[1])
    _triangles[1]->rmv(this);
  Rec2DData::rmv(this);
}

void Rec2DTwoTri2Quad::reveal()
{
  if (_triangles[0])
    _triangles[0]->add(this);
  if (_triangles[1])
    _triangles[1]->add(this);
  Rec2DData::add(this);
}

bool Rec2DTwoTri2Quad::isObsolete() const
{
  int p[4];
  p[0] = _vertices[0]->getParity();
  p[1] = _vertices[1]->getParity();
  p[2] = _vertices[2]->getParity();
  p[3] = _vertices[3]->getParity();
  return (p[0]/2 == p[1]/2 && p[0] != p[1]) ||
         (p[2]/2 == p[3]/2 && p[2] != p[3]) ||
         (p[0] && (p[0] == p[2] || p[0] == p[3])) ||
         (p[1] && (p[1] == p[2] || p[1] == p[3]))   ;
}

void Rec2DTwoTri2Quad::apply(std::vector<Rec2DVertex*> &newPar)
{
  static int a = 0;
  if (++a == 1) Msg::Error("FIXME Need new definition Rec2DTwoTri2Quad::apply(newPar)");
  /*if (isObsolete()) {
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

  _triangles[0]->rmv(this);
  _triangles[1]->rmv(this);
  // hide() instead

  std::vector<Rec2DAction*> actions;
  _triangles[0]->getMoreUniqueActions(actions);
  _triangles[1]->getMoreUniqueActions(actions);
  for (unsigned int i = 0; i < actions.size(); ++i)
    delete actions[i];

  delete _triangles[0];
  delete _triangles[1];
  _triangles[0] = NULL;
  _triangles[1] = NULL;
  delete _edges[4];

  new Rec2DElement((MQuadrangle*)NULL, (const Rec2DEdge**)_edges);

  Recombine2D::incNumChange();*/
}

void Rec2DTwoTri2Quad::apply(Rec2DDataChange *rdc,
                             std::vector<Rec2DAction*> *&createdActions,
                             bool color) const
{
  //I(( "applying Recombine |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum() ));
  if (isObsolete() && !Recombine2D::canIsolateTriangle()) {
    printIdentity();
    int p[4];
    p[0] = _vertices[0]->getParity();
    p[1] = _vertices[1]->getParity();
    p[2] = _vertices[2]->getParity();
    p[3] = _vertices[3]->getParity();
    Msg::Info("%d %d %d %d", p[0], p[1], p[2], p[3]);
    Msg::Error("[Rec2DTwoTri2Quad] I was obsolete !");
    if (Rec2DData::checkEntities()) {
      Msg::Error("check entities is ok. Should not have been aware of me");
    }
    __crash();
  }
#ifdef REC2D_DRAW
  rdc->setAction(this);
#endif
  std::vector<Rec2DAction*> actions;
  _triangles[0]->getMoreUniqueActions(actions);
  _triangles[1]->getMoreUniqueActions(actions);
  rdc->hide(actions);
  if (!Recombine2D::canIsolateTriangle())
    _doWhatYouHaveToDoWithParity(rdc);
  rdc->hide(_triangles[0]);
  rdc->hide(_triangles[1]);
  rdc->hide(_edges[4]);
  Rec2DElement *rel = new Rec2DElement((MQuadrangle*)NULL, (const Rec2DEdge**)_edges);
  rdc->append(rel);
  //rdc->add((int)_rt->total_gain); // _reward if blossom// no more in the code (see Amaury)
  if (color) Recombine2D::colorFromBlossom(_triangles[0], _triangles[1], rel);
  static int a = 0;
  if (++a == 1) Msg::Warning("FIXME reward is int for blossom");
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

bool Rec2DTwoTri2Quad::has(const Rec2DElement *rel) const
{
  return rel == _triangles[0] || rel == _triangles[1];
}

Rec2DElement* Rec2DTwoTri2Quad::getRandomElement() const
{
  return _triangles[rand() % 2];
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
    if (elem[i] == _triangles[0] || elem[i] == _triangles[1]) {
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

void Rec2DTwoTri2Quad::getTouchedActions(std::vector<Rec2DAction*> &actions) const
{
  std::vector<Rec2DElement*> elem;
  getNeighbourElements(elem);
  for (unsigned int i = 0; i < elem.size(); ++i) {
    elem[i]->getMoreUniqueActions(actions);
  }
}

bool Rec2DTwoTri2Quad::checkCoherence(const Rec2DAction *action) const
{
  Rec2DEdge *edge4 = Rec2DElement::getCommonEdge(_triangles[0], _triangles[1]);
  if (!edge4) {
    if (!_triangles[0]->has(_edges[4]) || !_triangles[1]->has(_edges[4])) {
      Msg::Error("inco action [-1], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
    }
  }
  else if (_edges[4] != edge4) {
    Msg::Error("inco action [0], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
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
      Msg::Error("inco action [1], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      for (int i = 0; i < 4; ++i) {
        _edges[i]->print();
        re[i]->print();
        Msg::Info(" ");
      }
      return false;
    }
  }

  if (_edges[0]->getOtherVertex(_vertices[2]) == _edges[4]->getVertex(0)) {
    if (_vertices[0] != _edges[4]->getVertex(0) || _vertices[1] != _edges[4]->getVertex(1)) {
      Msg::Error("inco action [2], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
    }
  }
  else {
    if (_vertices[0] != _edges[4]->getVertex(1) || _vertices[1] != _edges[4]->getVertex(0)) {
      Msg::Error("inco action [3], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
      return false;
    }
  }
  if (_vertices[2] != _triangles[0]->getOtherVertex(_vertices[0], _vertices[1])) {
    Msg::Error("inco action [4], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    return false;
  }
  if (_vertices[3] != _triangles[1]->getOtherVertex(_vertices[0], _vertices[1])) {
    Msg::Error("inco action [5], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    return false;
  }

  const Rec2DAction *ra;
  if (action) ra = action;
  else ra = this;
  if (!_triangles[0]->has(ra) || !_triangles[1]->has(ra) || _triangles[0] == _triangles[1]) {
    Msg::Error("inco action [6], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    return false;
  }

  if (isObsolete()) {
    int p[4];
    p[0] = _vertices[0]->getParity();
    p[1] = _vertices[1]->getParity();
    p[2] = _vertices[2]->getParity();
    p[3] = _vertices[3]->getParity();
    Msg::Info("%d %d %d %d", p[0], p[1], p[2], p[3]);
    Msg::Error("inco action [7], |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
    return false;
  }

  return true;
}

void Rec2DTwoTri2Quad::printReward() const
{
  if (Recombine2D::blossomQual()) {
    Msg::Error("[Rec2DTwoTri2Quad] Don't know");
    //?return (double)_cur->_blossomQuality;
    return;
  }
  if (Recombine2D::verticesQual()) {
    Msg::Info("reward rec : %g  %g  %g  %g",
              _vertices[0]->getGainRecomb(_triangles[0], _triangles[1], _edges[4], _edges[0], _edges[3]),
              _vertices[1]->getGainRecomb(_triangles[0], _triangles[1], _edges[4], _edges[1], _edges[2]),
              _vertices[2]->getGainQuad(_triangles[0], _edges[0], _edges[1]),
              _vertices[3]->getGainQuad(_triangles[1], _edges[2], _edges[3]));
    return;
  }
  if (Recombine2D::vertAndEdgesQual()) {
    double valEdge1 = _edges[4]->getQual();
    double valEdge2 = 0;
    for (int i = 0; i < 4; ++i)
      valEdge2 += _edges[i]->getQual();

    double valVert;
    valVert = _vertices[0]->getGainRecomb(_triangles[0], _triangles[1]);
    valVert += _vertices[1]->getGainRecomb(_triangles[0], _triangles[1]);
    Msg::Info("-%de%g +%de%g +0v%g -> %g", Recombine2D::getWeightEdgeBase(), valEdge1, 4 * Recombine2D::getWeightEdgeQuad(),
              valEdge2/4, valVert/2,
              Rec2DData::getGlobalQuality(0, valVert,
                            4*Recombine2D::getWeightEdgeQuad() - Recombine2D::getWeightEdgeBase(),
                            -Recombine2D::getWeightEdgeBase()*valEdge1+Recombine2D::getWeightEdgeQuad()*valEdge2));
    return;
  }
  Msg::Error("[Rec2DTwoTri2Quad] Unknown quality criterion");
}

void Rec2DTwoTri2Quad::printVertices() const
{
  for (int i = 0; i < 4; ++i) {
    Msg::Info("vert %d : %g", _vertices[i]->getNum(), _vertices[i]->getQual());
    //_vertices[i]->printQual();
  }
}

void Rec2DTwoTri2Quad::printIdentity() const
{
  Msg::Info("Recombine |%d|%d|", _triangles[0]->getNum(), _triangles[1]->getNum());
}

MElement* Rec2DTwoTri2Quad::createMElement(double shiftx, double shifty)
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
  return quad;
}

void Rec2DTwoTri2Quad::color(int a, int b, int c) const
{
#ifdef REC2D_DRAW
  unsigned int col = CTX::instance()->packColor(a, b, c, 255);
  //_triangles[0]->getMElement()->setCol(col);// no more in the code (see Amaury)
  //_triangles[1]->getMElement()->setCol(col);// no more in the code (see Amaury)
#endif
}

void Rec2DTwoTri2Quad::getIncompatible(std::vector<Rec2DAction*> &vect)
{
  vect.clear();
  Rec2DDataChange *rdc = new Rec2DDataChange();
  std::vector<Rec2DAction*> *v = NULL;
  apply(rdc, v);
  vect = rdc->hiddenActions;
  for (unsigned int i = 0; i < vect.size(); ++i) {
    if (vect[i] == this) {
      vect[i] = vect.back();
      vect.pop_back();
      rdc->revert();
      delete rdc;
      return;
    }
  }
}


void Rec2DTwoTri2Quad::_computeGlobQual()
{
  if (Recombine2D::blossomQual()) {
    _globQualIfExecuted = -99;
    //_globQualIfExecuted = Rec2DData::getGlobalQuality() + (int)_rt->total_gain;// no more in the code (see Amaury)
    return;
  }
  if (Recombine2D::verticesQual()) {
    _valVert = .0;
    _valVert += _vertices[0]->getGainRecomb(_triangles[0], _triangles[1],
                                            _edges[4], _edges[0], _edges[3]);
    _valVert += _vertices[1]->getGainRecomb(_triangles[0], _triangles[1],
                                            _edges[4], _edges[1], _edges[2]);
    _valVert += _vertices[2]->getGainQuad(_triangles[0], _edges[0], _edges[1]);
    _valVert += _vertices[3]->getGainQuad(_triangles[1], _edges[2], _edges[3]);

    _globQualIfExecuted = Rec2DData::getGlobalQuality(0, _valVert);
    _lastUpdate = Recombine2D::getNumChange();
    return;
  }
  if (Recombine2D::vertAndEdgesQual()) {
    double valEdge = -Recombine2D::getWeightEdgeBase() * _edges[4]->getQual();
    for (int i = 0; i < 4; ++i)
      valEdge += Recombine2D::getWeightEdgeQuad() * _edges[i]->getQual();

    if (_vertices[0]->getLastUpdate() > _lastUpdate ||
        _vertices[1]->getLastUpdate() > _lastUpdate   ) {
      _valVert = _vertices[0]->getGainRecomb(_triangles[0], _triangles[1]);
      _valVert += _vertices[1]->getGainRecomb(_triangles[0], _triangles[1]);
    }

    double w = 4*Recombine2D::getWeightEdgeQuad()
               - Recombine2D::getWeightEdgeBase();
    _globQualIfExecuted = Rec2DData::getGlobalQuality(0, _valVert, w, valEdge);
    _lastUpdate = Recombine2D::getNumChange();
    return;
  }
  Msg::Error("[Rec2DTwoTri2Quad] Unknown quality criterion");
}

void Rec2DTwoTri2Quad::_computeReward()
{
  Rec2DQualCrit  crit = Recombine2D::getQualCrit();

  switch (crit) {
    case BlossomQuality :
      _reward = -99;
      //_reward = (int)_rt->total_gain;// no more in the code (see Amaury)
      return;

    case VertQuality :
      _valVert = .0;
      _valVert += _vertices[0]->getGainRecomb(_triangles[0], _triangles[1],
                                              _edges[4], _edges[0], _edges[3]);
      _valVert += _vertices[1]->getGainRecomb(_triangles[0], _triangles[1],
                                              _edges[4], _edges[1], _edges[2]);
      _valVert += _vertices[2]->getGainQuad(_triangles[0], _edges[0], _edges[1]);
      _valVert += _vertices[3]->getGainQuad(_triangles[1], _edges[2], _edges[3]);

      _reward = Rec2DData::getGlobalQuality(0, _valVert)
                - Rec2DData::getGlobalQuality();
      _lastUpdate = Recombine2D::getNumChange();
      return;

    case VertEdgeQuality :
    {
      double valEdge = -Recombine2D::getWeightEdgeBase() * _edges[4]->getQual();
      for (int i = 0; i < 4; ++i)
        valEdge += Recombine2D::getWeightEdgeQuad() * _edges[i]->getQual();

      if (_vertices[0]->getLastUpdate() > _lastUpdate ||
          _vertices[1]->getLastUpdate() > _lastUpdate   ) {
        _valVert = _vertices[0]->getGainRecomb(_triangles[0], _triangles[1]);
        _valVert += _vertices[1]->getGainRecomb(_triangles[0], _triangles[1]);
      }

      double w = 4*Recombine2D::getWeightEdgeQuad()
                 - Recombine2D::getWeightEdgeBase();
      _reward = Rec2DData::getGlobalQuality(0, _valVert, w, valEdge)
                - Rec2DData::getGlobalQuality();

      _lastUpdate = Recombine2D::getNumChange();
      return;
    }

    default :
      Msg::Error("[Rec2DTwoTri2Quad:_computeReward] Unknown quality criterion %d", crit);
  }
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
  else for (int i = 0; i < 4; i += 2) {
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
}


/**  Rec2DCollapse  **/
/*********************/
Rec2DCollapse::Rec2DCollapse(Rec2DTwoTri2Quad *rec) : _rec(rec)
{
  _rec->_col = this;
  _rec->_triangles[0]->add(this);
  _rec->_triangles[1]->add(this);
  Rec2DData::add(this);
}

void Rec2DCollapse::operator delete(void *p)
{
  if (!p) return;
  Rec2DCollapse *ra = (Rec2DCollapse*)p;
  if (ra->_dataAction) { // ra->hide()
    ra->_rec->_triangles[0]->rmv(ra);
    ra->_rec->_triangles[1]->rmv(ra);
    Rec2DData::rmv(ra);
  }
  if (!ra->_numPointing) {
    //Msg::Info("del ac %d", p);
    ra->_rec->_col = NULL;
    free(p);
  }
}

void Rec2DCollapse::hide()
{
  if (_rec->_triangles[0])
    _rec->_triangles[0]->rmv(this);
  if (_rec->_triangles[1])
    _rec->_triangles[1]->rmv(this);
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

bool Rec2DCollapse::isObsolete() const
{
  int p[2];
  p[0] = _rec->_vertices[0]->getParity();
  p[1] = _rec->_vertices[1]->getParity();
  return (p[0]/2 == p[1]/2 && p[0] != p[1]) ||
         (_rec->_vertices[0]->getOnBoundary() &&
          _rec->_vertices[1]->getOnBoundary())  ||
         (!_rec->_vertices[2]->getOnBoundary() &&
          _rec->_vertices[2]->getNumElements() < 4) ||
         (!_rec->_vertices[3]->getOnBoundary() &&
          _rec->_vertices[3]->getNumElements() < 4)    ;
}

void Rec2DCollapse::apply(std::vector<Rec2DVertex*> &newPar)
{
  static int a = 0;
  if (++a == 1) Msg::Error("FIXME Need definition Rec2DCollapse::apply(newPar)");
}

void Rec2DCollapse::apply(Rec2DDataChange *rdc,
                          std::vector<Rec2DAction*> *&createdActions,
                          bool color) const
{
  //Msg::Info("applying Collapse |%d|%d|", _rec->_triangles[0]->getNum(), _rec->_triangles[1]->getNum());
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
    __crash();
  }
#ifdef REC2D_DRAW
  rdc->setAction(this);
#endif
  std::vector<Rec2DAction*> actions;
  _rec->_triangles[0]->getMoreUniqueActions(actions);
  _rec->_triangles[1]->getMoreUniqueActions(actions);
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

void Rec2DCollapse::getNeighbourElements(std::vector<Rec2DElement*> &elem) const
{
  _rec->getNeighbourElements(elem);
}

void Rec2DCollapse::getNeighbElemWithActions(std::vector<Rec2DElement*> &elem) const
{
  _rec->getNeighbElemWithActions(elem);
}

void Rec2DCollapse::printReward() const
{
  if (Recombine2D::blossomQual()) {
    Msg::Error("[Rec2DCollapse] Don't know");
    //?return (double)_cur->_blossomQuality;
    return;
  }
  if (Recombine2D::verticesQual()) {
    SPoint2 p[2];
    _rec->_vertices[0]->getParam(&p[0]);
    _rec->_vertices[1]->getParam(&p[1]);
    int b0 = _rec->_vertices[0]->getOnBoundary();
    int b1 = _rec->_vertices[1]->getOnBoundary();

    double valVert = .0;
    if (b0 || b1) {
      int iOK = 1, iKO = 0;
      if (b0) {
        iOK = 0;
        iKO = 1;
      }
      double oldValVert = Rec2DData::getSumVert();
      _rec->_vertices[iKO]->relocate(p[iOK]);
      double qualRelocation = Rec2DData::getSumVert() - oldValVert;

      valVert += _rec->_vertices[iOK]->getGainMerge(_rec->_vertices[iKO],
                                                    &_rec->_edges[1], 2  );
      valVert += _rec->_vertices[2]->getGainTriLess(_rec->_edges[1]);
      valVert += _rec->_vertices[3]->getGainTriLess(_rec->_edges[2]);

      for (int i = 0; i < 4; ++i) {
        Msg::Info("vert %d : %g", _rec->_vertices[i]->getNum(), _rec->_vertices[i]->getQual());
      }

      Msg::Info("qual col %g %g %g %g", qualRelocation,
                _rec->_vertices[iOK]->getGainMerge(_rec->_vertices[iKO], &_rec->_edges[1], 2),
                _rec->_vertices[2]->getGainTriLess(_rec->_edges[1]),
                _rec->_vertices[3]->getGainTriLess(_rec->_edges[2])
               );

      _rec->_vertices[iKO]->relocate(p[iKO]);
    }
    else {
      double u = (_rec->_vertices[0]->u() + _rec->_vertices[1]->u()) / 2;
      double v = (_rec->_vertices[0]->v() + _rec->_vertices[1]->v()) / 2;
      SPoint2 pNew(u, v);
      double oldValVert = Rec2DData::getSumVert();
      _rec->_vertices[0]->relocate(pNew);
      _rec->_vertices[1]->relocate(pNew);
      double qualRelocation = Rec2DData::getSumVert() - oldValVert;

      valVert += _rec->_vertices[0]->getGainMerge(_rec->_vertices[1],
                                                  &_rec->_edges[1], 2);
      valVert += _rec->_vertices[2]->getGainTriLess(_rec->_edges[0]); //FIX normal ?
      valVert += _rec->_vertices[3]->getGainTriLess(_rec->_edges[2]);

      for (int i = 0; i < 4; ++i) {
        Msg::Info("vert %d : %g", _rec->_vertices[i]->getNum(), _rec->_vertices[i]->getQual());
      }

      Msg::Info("qual col %g %g %g %g", qualRelocation,
                _rec->_vertices[0]->getGainMerge(_rec->_vertices[1], &_rec->_edges[1], 2),
                _rec->_vertices[2]->getGainTriLess(_rec->_edges[1]),
                _rec->_vertices[3]->getGainTriLess(_rec->_edges[2])
               );

      _rec->_vertices[0]->relocate(p[0]);
      _rec->_vertices[1]->relocate(p[1]);
    }
    return;
  }
  if (Recombine2D::vertAndEdgesQual()) {
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

    _rec->_vertices[0]->getMoreUniqueEdges(edges);
    _rec->_vertices[1]->getMoreUniqueEdges(edges);
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

    Rec2DNode *n = new Rec2DNode(NULL, (Rec2DAction*)this, 0);
    n->makeChanges();

    edges.clear();
    _rec->_vertices[0]->getMoreUniqueEdges(edges);
    _rec->_vertices[1]->getMoreUniqueEdges(edges);
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
              "-4v%g +2v%g +0v%g +(%d)0v%g",
              numEdgeBef, weightEdgeBef, valEdgeBef/weightEdgeBef,
              numEdgeAft, weightEdgeAft, valEdgeAft/weightEdgeAft,
              vert01Bef/4, vert01Aft/2, (vert23Aft-vert23Bef)/2,
              numVertOther, vertOtherAft-vertOtherBef);
    return;
  }
  Msg::Error("[Rec2DCollapse] Unknown quality criterion");
}

void Rec2DCollapse::printIdentity() const
{
  Msg::Info("Collapse |%d|%d|", _rec->_triangles[0]->getNum(), _rec->_triangles[1]->getNum());
}

void Rec2DCollapse::_computeGlobQual()
{
  std::vector<Rec2DVertex*> verts;
  _rec->_vertices[0]->getMoreNeighbourVertices(verts);
  _rec->_vertices[1]->getMoreNeighbourVertices(verts);
  unsigned int i = 0;
  while (i < verts.size() && verts[i]->getLastUpdate() <= _lastUpdate) ++i;
  if (i >= verts.size()) {
    _lastUpdate = Recombine2D::getNumChange();
    return;
  }

  SPoint2 p[2];
  _rec->_vertices[0]->getParam(&p[0]);
  _rec->_vertices[1]->getParam(&p[1]);
  int b0 = _rec->_vertices[0]->getOnBoundary();
  int b1 = _rec->_vertices[1]->getOnBoundary();

  if (Recombine2D::blossomQual()) {
    Msg::Error("[Rec2DCollapse] Don't know");
    //?return (double)_cur->_blossomQuality;
    return;
  }
  if (Recombine2D::verticesQual()) {
    double valVert = .0;
    if (b0 || b1) {
      int iOK = 1, iKO = 0;
      if (b0) {
        iOK = 0;
        iKO = 1;
      }
      _rec->_vertices[iKO]->relocate(p[iOK]);

      valVert += _rec->_vertices[iOK]->getGainMerge(_rec->_vertices[iKO],
                                                    &_rec->_edges[1], 2  );
      valVert += _rec->_vertices[2]->getGainTriLess(_rec->_edges[1]);
      valVert += _rec->_vertices[3]->getGainTriLess(_rec->_edges[2]);
      _globQualIfExecuted = Rec2DData::getGlobalQuality(-1, valVert);

      _rec->_vertices[iKO]->relocate(p[iKO]);
    }
    else {
      double u = (_rec->_vertices[0]->u() + _rec->_vertices[1]->u()) / 2;
      double v = (_rec->_vertices[0]->v() + _rec->_vertices[1]->v()) / 2;
      SPoint2 pNew(u, v);
      _rec->_vertices[0]->relocate(pNew);
      _rec->_vertices[1]->relocate(pNew);

      valVert += _rec->_vertices[0]->getGainMerge(_rec->_vertices[1],
                                                  &_rec->_edges[1], 2);
      valVert += _rec->_vertices[2]->getGainTriLess(_rec->_edges[0]);
      valVert += _rec->_vertices[3]->getGainTriLess(_rec->_edges[2]);
      _globQualIfExecuted = Rec2DData::getGlobalQuality(-1, valVert);

      _rec->_vertices[0]->relocate(p[0]);
      _rec->_vertices[1]->relocate(p[1]);
    }
    _lastUpdate = Recombine2D::getNumChange();
    return;
  }
  if (Recombine2D::vertAndEdgesQual()) {
    int numEdge = 0;
    double valEdge = .0, valVert = .0;
    if (b0 || b1) {
      int iOK = 1, iKO = 0;
      if (b0) {
        iOK = 0;
        iKO = 1;
      }
      _rec->_vertices[iKO]->relocate(p[iOK]);

      valVert += _rec->_vertices[2]->getGainOneElemLess();
      valVert += _rec->_vertices[3]->getGainOneElemLess();
      valVert += _rec->_vertices[iOK]->getGainMerge(_rec->_vertices[iKO]);
      valEdge -= Recombine2D::getWeightEdgeBase() * _rec->_edges[1]->getQual();
      valEdge -= Recombine2D::getWeightEdgeBase() * _rec->_edges[2]->getQual();
      numEdge -= 2 * Recombine2D::getWeightEdgeBase();
      valEdge -= _rec->_edges[4]->getWeightedQual();
      numEdge -= _rec->_edges[4]->getWeight();

      _globQualIfExecuted = Rec2DData::getGlobalQuality(-1, valVert,
                                                        numEdge, valEdge);

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
      valEdge -= Recombine2D::getWeightEdgeBase() * _rec->_edges[1]->getQual();
      valEdge -= Recombine2D::getWeightEdgeBase() * _rec->_edges[2]->getQual();
      numEdge -= 2 * Recombine2D::getWeightEdgeBase();
      valEdge -= _rec->_edges[4]->getWeightedQual();
      numEdge -= _rec->_edges[4]->getWeight();

      _globQualIfExecuted = Rec2DData::getGlobalQuality(-1, valVert,
                                                        numEdge, valEdge);

      _rec->_vertices[0]->relocate(p[0]);
      _rec->_vertices[1]->relocate(p[1]);
    }
    _lastUpdate = Recombine2D::getNumChange();
    return;
  }
  Msg::Error("[Rec2DCollapse] Unknown quality criterion");
}

void Rec2DCollapse::_computeReward()
{
  Msg::Fatal("Need definition for compute reward");
}

bool Rec2DCollapse::_hasIdenticalElement() const
{
  return _rec->_triangles[0]->hasIdenticalNeighbour() ||
         _rec->_triangles[1]->hasIdenticalNeighbour()   ;
}


/**  Rec2DEdge  **/
/*****************/
Rec2DEdge::Rec2DEdge(Rec2DVertex *rv0, Rec2DVertex *rv1)
: _rv0(rv0), _rv1(rv1), _weight(Recombine2D::getWeightEdgeBase()
                                + 2*Recombine2D::getWeightEdgeQuad()),
  _lastUpdate(-1), _pos(-1)
{
  _qual = -999999999; // FIXME // _computeQual();
  reveal();
}

void Rec2DEdge::hide()
{
  _rv0->rmv(this);
  _rv1->rmv(this);
  Rec2DData::rmv(this);
}

void Rec2DEdge::reveal()
{
  _rv0->add(this);
  _rv1->add(this);
  Rec2DData::add(this);
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

Rec2DElement* Rec2DEdge::getTheOnlyElement(const Rec2DEdge *re)
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
    case 0 :
      return;
    default :
      Msg::Error("[Rec2DEdge] my integrity is not respected :'(");
  }
}

//void Rec2DEdge::getUniqueActions(std::vector<Rec2DAction*> &actions) const
//{
//  actions.clear();
//  Rec2DElement *elem[2];
//  Rec2DEdge::getElements(this, elem);
//  if (elem[0]) elem[0]->getMoreUniqueActions(actions);
//  if (elem[1]) elem[1]->getMoreUniqueActions(actions);
//}

void Rec2DEdge::updateQual()
{
  double diffQual = _qual;
  _computeQual();
  diffQual = _weight*(_qual-diffQual);

  _rv0->updateWAQualEdges(diffQual);
  _rv1->updateWAQualEdges(diffQual);
  Rec2DData::updateEdgeQual(diffQual);
}

bool Rec2DEdge::isOnBoundary() const
{
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  return !elem[1];
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

bool Rec2DEdge::checkCoherence() const
{
  if (_rv0 == _rv1) return false;
  if (!_rv0->has(this) || !_rv1->has(this)) return false;

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
  return true;
}

void Rec2DEdge::print() const
{
  Rec2DElement *elem[2];
  Rec2DEdge::getElements(this, elem);
  int a, b = a = 0;
  if (elem[0])
    a = elem[0]->getNum();
  if (elem[1])
    b = elem[1]->getNum();

  Msg::Info(" edge , %d--%d , %d/%d", _rv0->getNum(), _rv1->getNum(), a, b);
}

void Rec2DEdge::_computeQual()
{
  double alignment = _straightAlignment();
  double adimLength = _straightAdimLength();
  if (adimLength > 1)
    adimLength = 1./adimLength;

  _qual = (Recombine2D::getCoefLengOrientQual() * alignment
           + Recombine2D::getCoefLengthQual()              ) * adimLength
          + Recombine2D::getCoefOrientQual() * alignment;
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DEdge::_addWeight(int w)
{
  _weight += w;
  if (_weight > Recombine2D::getWeightEdgeBase()
                + 2*Recombine2D::getWeightEdgeQuad()) {
    Msg::Error("[Rec2DEdge] Weight too high");
  }
  if (_weight < Recombine2D::getWeightEdgeBase()) {
    Msg::Error("[Rec2DEdge] Weight too low");
  }

  double diffQual = w*getQual();
  _rv0->updateWAQualEdges(diffQual, w);
  _rv1->updateWAQualEdges(diffQual, w);
  Rec2DData::updateEdgeQual(diffQual, w);
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


/**  Rec2DVertex  **/
/*******************/
Rec2DVertex::Rec2DVertex(MVertex *v)
: _v(v), _angle(4.*M_PI), _onWhat(1), _parity(0),
  _lastUpdate(-1), _sumWQualAngle(.0), _sumWQualEdge(.0),
  _sumWeightAngle(0), _sumWeightEdge(0), _pos(-1)
{
  reparamMeshVertexOnFace(_v, Recombine2D::getGFace(), _param);
  reveal();
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
}

Rec2DVertex::Rec2DVertex(Rec2DVertex *rv, double ang)
: _v(rv->_v), _angle(ang), _onWhat(-1), _parity(rv->_parity),
  _lastUpdate(rv->_lastUpdate),
  _sumWQualAngle(rv->_sumWQualAngle), _sumWQualEdge(rv->_sumWQualEdge),
  _sumWeightAngle(rv->_sumWeightAngle), _sumWeightEdge(rv->_sumWeightEdge), _edges(rv->_edges),
  _elements(rv->_elements), _param(rv->_param), _pos(-1)
{
  rv->hide(false);

  // swap the two vertices in edges
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    _edges[i]->swap(rv, this, false);
  }
  rv->_edges.clear();

  // swap the two vertices in actions
  std::vector<Rec2DAction*> actions;
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    _elements[i]->getMoreUniqueActions(actions);
  }
  for (unsigned int i = 0; i < actions.size(); ++i) {
    if (actions[i]->isRecomb()) actions[i]->swap(rv, this);
  }
  rv->_elements.clear();

  // end
  reveal();
  delete rv;
#ifdef REC2D_DRAW
  if (_v)
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
  _lastUpdate = Recombine2D::getNumChange();
}

void Rec2DVertex::hide(bool check)
{
  if (check && _elements.size() && _edges.size())
    Msg::Error("[Rec2DVertex] I have %d elements and %d edges", _elements.size(), _edges.size());
  if (_parity)
    Rec2DData::removeParity(this, _parity);

  Rec2DData::rmv(this);
}

void Rec2DVertex::reveal()
{
  if (_parity)
    Rec2DData::addParity(this, _parity);

  Rec2DData::add(this);
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
    _qualVSnum[0][0] = -REC2D_BIG_NUMB;
    _qualVSnum[1][0] = -REC2D_BIG_NUMB;
    for (int i = 1; i < nE; ++i)
      _qualVSnum[0][i] = 1. - fabs(2./i - 1.);
    for (int i = 1; i < nF; ++i)
      _qualVSnum[1][i] = std::max(1. - fabs(4./i - 1.), .0);

    _gains = new double*[2];
    _gains[0] = new double[nE-1];
    _gains[1] = new double[nF-1];
    for (int i = 0; i < nE-1; ++i)
      _gains[0][i] = _qualVSnum[0][i+1] - _qualVSnum[0][i];
    for (int i = 0; i < nF-1; ++i)
      _gains[1][i] = _qualVSnum[1][i+1] - _qualVSnum[1][i];
  }
}

void Rec2DVertex::add(const Rec2DEdge *re)
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re) {
      Msg::Error("[Rec2DVertex] Edge was already there");
      return;
    }
  }

  double oldQual = getQual(VertQuality);

  _edges.push_back(const_cast<Rec2DEdge*>(re));
  _sumWQualEdge += re->getWeightedQual();
  _sumWeightEdge += re->getWeight();
  _lastUpdate = Recombine2D::getNumChange();

  Rec2DData::updateVertQual(getQual(VertQuality)-oldQual, VertQuality);
}

bool Rec2DVertex::has(const Rec2DEdge *re) const
{
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    if (_edges[i] == re) return true;
  }
  return false;
}

void Rec2DVertex::rmv(const Rec2DEdge *re)
{
  unsigned int i = 0;
  while (i < _edges.size()) {
    if (_edges[i] == re) {

      double oldQual = getQual(VertQuality);

      _edges[i] = _edges.back();
      _edges.pop_back();
      _sumWQualEdge -= re->getWeightedQual();
      _sumWeightEdge -= re->getWeight();
      if (_sumWeightEdge < 0 || _sumWQualEdge < -1e12)
        Msg::Error("[Rec2DVertex] Negative sum edge %d %g", _sumWeightEdge, _sumWQualEdge);
      _lastUpdate = Recombine2D::getNumChange();

      Rec2DData::updateVertQual(getQual(VertQuality)-oldQual, VertQuality);
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DVertex] Didn't removed edge, don't have it");
}

void Rec2DVertex::add(const Rec2DElement *rel)
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    if (_elements[i] == rel) {
      Msg::Error("[Rec2DVertex] Element was already there");
      return;
    }
  }

  double oldQual1 = getQual(VertQuality);
  double oldQual2 = getQual(VertEdgeQuality);

  _elements.push_back(const_cast<Rec2DElement*>(rel));
  _sumWeightAngle += rel->getAngleWeight();
  _sumWQualAngle += rel->getWeightedAngleQual(this);
  _lastUpdate = Recombine2D::getNumChange();

  Rec2DData::updateVertQual(getQual(VertQuality)-oldQual1, VertQuality);
  Rec2DData::updateVertQual(getQual(VertEdgeQuality)-oldQual2, VertEdgeQuality);
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

      double oldQual1 = getQual(VertQuality);
      double oldQual2 = getQual(VertEdgeQuality);

      _sumWeightAngle -= _elements[i]->getAngleWeight();
      _sumWQualAngle -= _elements[i]->getWeightedAngleQual(this);
      _elements[i] = _elements.back();
      _elements.pop_back();
      _lastUpdate = Recombine2D::getNumChange();

      Rec2DData::updateVertQual(getQual(VertQuality)-oldQual1, VertQuality);
      Rec2DData::updateVertQual(getQual(VertEdgeQuality)-oldQual2, VertEdgeQuality);
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DVertex] Didn't removed element, didn't have it");
}

void Rec2DVertex::getMoreUniqueEdges(std::vector<Rec2DEdge*> &edges) const
{
  unsigned int size = edges.size();
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    unsigned int j = -1;
    while (++j < size && edges[j] != _edges[i]);
    if (j == size)
      edges.push_back(_edges[i]);
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

void Rec2DVertex::getMoreNeighbourVertices(std::vector<Rec2DVertex*> &verts) const
{
  for (unsigned int i = 0; i < _edges.size(); ++i)
    verts.push_back(_edges[i]->getOtherVertex(this));
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

void Rec2DVertex::getMoreUniqueActions(std::vector<Rec2DAction*> &actions) const
{
  std::vector<Rec2DAction*> actions2;
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    _elements[i]->getMoreUniqueActions(actions2);
  }
  int size = (int)actions.size();
  for (unsigned int i = 0; i < actions2.size(); ++i) {
    int j = -1;
    while (++j < size && actions2[i] != actions[j]);
    if (j == size) actions.push_back(actions2[i]);
  }
}

void Rec2DVertex::setOnBoundary()
{
  if (_onWhat > 0) {
    double oldQual1 = getQual(VertQuality);
    double oldQual2 = getQual(VertEdgeQuality);
    _onWhat = 0;
    Rec2DData::updateVertQual(getQual(VertQuality)-oldQual1, VertQuality);
    Rec2DData::updateVertQual(getQual(VertEdgeQuality)-oldQual2, VertEdgeQuality);
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
    _v->setIndex(_parity);
    //_v->setIndex(_onWhat);
#endif
}

void Rec2DVertex::setParityWD(int pOld, int pNew)
{
  static int a = 0;
  if (++a == 1)
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
    Msg::Error("[Rec2DVertex] What's happening ? Am I on boundary or not ? TELL ME ! (%d)", num);
  if (nextRV)
    return nextRV->_recursiveBoundParity(this, p1, p0); // alternate parity
  Msg::Error("[Rec2DVertex] Have I really to say that I didn't find neighbouring vertex ?");
  return false;
}

double Rec2DVertex::getQualDegree(int numEl) const
{
  int nEl = numEl > -1 ? numEl : _elements.size();
  if (nEl == 0) return -REC2D_BIG_NUMB;
  if (_onWhat > -1) return _qualVSnum[_onWhat][nEl];
  return std::max(1. - fabs(2./M_PI * _angle/nEl - 1.), .0);
}

double Rec2DVertex::getGainDegree(int n) const
{
  if (!n)
    return .0;
  int numElem = (int)_elements.size();
  if (numElem + n < 0) {
    Msg::Error("[Rec2DVertex] gain for %d elements not available",
               numElem + n                             );
    return .0;
  }

  if (_onWhat > -1) {
    switch (n) {
      case 1 :
        return _gains[_onWhat][numElem];
      case -1 :
        return - _gains[_onWhat][numElem-1];
      default :
        return _qualVSnum[_onWhat][numElem+n]
               - _qualVSnum[_onWhat][numElem-1];
    }
  }

  if (numElem == 0) {
    Msg::Error("[Rec2DVertex] I don't want this anymore !");
    return 11. - fabs(2./M_PI * _angle/(double)(numElem + n) - 1.);
  }

  if (numElem + n == 0) {
    Msg::Error("[Rec2DVertex] I don't want this anymore !");
    return fabs(2./M_PI * _angle/(double)numElem - 1.) - 11.;
  }

  return fabs(2./M_PI * _angle/(double)numElem - 1.)
         - fabs(2./M_PI * _angle/(double)(numElem + n) - 1.);
}

double Rec2DVertex::getQual(Rec2DQualCrit crit) const
{
  if (crit == ChoosedCrit) crit = Recombine2D::getQualCrit();

  switch (crit) {
    case VertQuality :
      return _vertQual() * _WAQualEdges();

    case VertEdgeQuality :
      return _vertQual();

    default :
      Msg::Error("[Rec2DVertex:getQual-1] Unknown quality criterion %d", crit);
      Msg::Error("");
      __crash();
  }
  return -1.;
}

#ifdef REC2D_VERT_ONLY
double Rec2DVertex::getQual(double waQualAngles, double waQualEdges,
                            int numElem, Rec2DQualCrit crit) const
{
  if (crit == ChoosedCrit) crit = Recombine2D::getQualCrit();

  static int a = 0;
  if (++a == 1) Msg::Warning("FIXME NoCrit==-2, ChoosedCrit==-1");

  switch (crit) {
    case VertQuality :
      return _vertQual(_qualDegree(numElem), waQualAngles) * waQualEdges;

    case VertEdgeQuality :
      return _vertQual(_qualDegree(numElem), waQualAngles);

    default :
      Msg::Error("[Rec2DVertex:getQual-2] Unknown quality criterion %d", crit);
  }
  return -1.;
}

double Rec2DVertex::/*vertQual_*/getGainQuad(const Rec2DElement *rel,
                                         const Rec2DEdge *re0,
                                         const Rec2DEdge *re1    ) const
{
  double wa = Recombine2D::getWeightAngleQuad()
             - Recombine2D::getWeightAngleTri();
  double wq = Recombine2D::getWeightEdgeQuad();

  double qualAngle = _sumWQualAngle + wa * rel->getAngleQual(this) ;
  int sumAngle = _sumWeightAngle + wa;

  double qualEdge = _sumWQualEdge + wq * re0->getQual() + wq * re1->getQual();
  int sumEdge = _sumWeightEdge + 2*wq;

  return getQual(qualAngle/sumAngle, qualEdge/sumEdge,
                 (int)_elements.size()                ) - getQual();
}

double Rec2DVertex::/*vertQual_*/getGainTriLess(const Rec2DEdge *re) const
{
  return getQual(_sumWQualAngle /*!!!!*/ / (_sumWeightAngle - Recombine2D::getWeightAngleTri()),
                 (_sumWQualEdge - re->getQual())
                 / (_sumWeightEdge - Recombine2D::getWeightEdgeBase()),
                 (int)_elements.size() - 1)
         - getQual();
}

double Rec2DVertex::getGainRecomb(/*Rec2DQualCrit crit,*/
                                  const Rec2DElement *rel1,
                                  const Rec2DElement *rel2,
                                  const Rec2DEdge *re0,
                                  const Rec2DEdge *re1,
                                  const Rec2DEdge *re2     ) const
{
  if (rel1->isQuad() || rel2->isQuad()) {
    Msg::Error("[Rec2DVertex] Cannot compute gain of recombination if elements aren't triangles");
    return -1.;
  }

  //if (crit == BlossomQuality) return .0;
  //if (crit < 0) {
    Msg::Warning("[Rec2DVertex] Give me another criterion please.");
  // }

  double swQualAngle = _sumWQualAngle, swQualEdge = _sumWQualEdge;
  int swAngle = _sumWeightAngle, swEdge = _sumWeightEdge;

  double wat = Recombine2D::getWeightAngleTri(),
         waq = Recombine2D::getWeightAngleQuad(),
         weq = Recombine2D::getWeightEdgeQuad(),
         web = Recombine2D::getWeightEdgeBase();

  swQualAngle -= wat * rel1->getAngleQual(this);
  swQualAngle -= wat * rel2->getAngleQual(this);
  swQualAngle += waq * Recombine2D::angle2qual(rel1->getAngle(this)
                                             + rel2->getAngle(this));
  swAngle += waq - 2 * wat;

  if (re2) {
    swQualEdge -= web * re0->getQual();
    swQualEdge += weq * re1->getQual();
    swQualEdge += weq * re2->getQual();
    swEdge += 2 * weq - web;
  }

  return getQual(swQualAngle / swAngle, swQualEdge / swEdge,
                 static_cast<int>(_elements.size())-1/*, crit*/)
         - getQual(/*crit*/);

  //FIX verifier que c'est bien ce qui est demande ! (renvoie bien ce que veux apply, compute reward, ...)
}

void Rec2DVertex::/*vertQual_*/addEdgeQual(double val, int num)
{
  Msg::Error("old function, need redefinition");
  __crash();
  /*double oldQual = .0;
  if (_elements.size())
    oldQual = getQual();*/
  _sumWQualEdge += val;
  _sumWeightEdge += num;
  if (_sumWeightEdge < 0 || _sumWQualEdge < -1e12)
    Msg::Error("[Rec2DVertex] Negative sum edge");
  if (_elements.size()) {
    Msg::Fatal("[Rec2DVertex:addEdgeQual] Need redefinition");
    //Rec2DData::addSumVert(getQual()-oldQual);
  }
  _lastUpdate = Recombine2D::getNumChange();
}

double Rec2DVertex::/*vertQual_*/getGainMerge(const Rec2DVertex *rv,
                                          const Rec2DEdge *const*edges, int nEdges) const
{
  int sumAngle = 0;
  double sumQualAngle = .0;
  int *numAngle = new int[_elements.size()];
  double *qualAngle = new double[_elements.size()];
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    numAngle[i] = _elements[i]->getAngleWeight();
    qualAngle[i] = _elements[i]->getWeightedAngleQual(this);
  }
  for (unsigned int i = 0; i < rv->_elements.size(); ++i) {
    unsigned int j = 0;
    while (j < _elements.size() && _elements[j] != rv->_elements[i]) ++j;
    if (j >= _elements.size()) {
      sumAngle += rv->_elements[i]->getAngleWeight();
      sumQualAngle += rv->_elements[i]->getWeightedAngleQual(rv);
    }
    else {
      numAngle[j] = 0;
      qualAngle[j] = .0;
    }
  }
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    sumAngle += numAngle[i];
    sumQualAngle += qualAngle[i];
  }
  int numElem = _elements.size() + rv->_elements.size() - 4;

  int sumEdge = 0;
  double sumQualEdge = .0;
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    sumEdge += _edges[i]->getWeight();
    sumQualEdge += _edges[i]->getWeightedQual();
  }
  for (unsigned int i = 0; i < rv->_edges.size(); ++i) {
    sumEdge += rv->_edges[i]->getWeight();
    sumQualEdge += rv->_edges[i]->getWeightedQual();
  }
  for (int i = 0; i < nEdges; ++i) {
    sumEdge -= Recombine2D::getWeightEdgeBase();
    sumQualEdge -= Recombine2D::getWeightEdgeBase() * edges[i]->getQual();
  }

  delete[] numAngle;
  delete[] qualAngle;
  return Rec2DVertex::getQual(sumQualAngle/sumAngle,
                              sumQualEdge/sumEdge, numElem)
         - getQual() - rv->getQual()                        ;
}
//#else
double Rec2DVertex::/*vertEdgeQual_*/getGainOneElemLess() const
{//FIX here element size instead of weight
  return getGainDegree(-1) + _sumWQualAngle / (_elements.size()-1) - _WAQualAngles();
}

double Rec2DVertex::/*vertEdgeQual_*/getGainMerge(const Rec2DVertex *rv) const
{
  double ans = .0, sumQualAngle = .0;
  int sumAngle = 0;
  ans -= getQual();
  ans -= rv->getQual();
  double *qualAngle = new double[_elements.size()];
  int *angleWeight = new int[_elements.size()];
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    qualAngle[i] = _elements[i]->getWeightedAngleQual(this);
    angleWeight[i] = _elements[i]->getAngleWeight();
  }
  for (unsigned int i = 0; i < rv->_elements.size(); ++i) {
    unsigned int j = 0;
    while (j < _elements.size() && _elements[j] != rv->_elements[i]) ++j;
    if (j >= _elements.size()) {
      sumQualAngle += rv->_elements[i]->getWeightedAngleQual(rv);
      sumAngle += rv->_elements[i]->getAngleWeight();
    }
    else {
      qualAngle[j] = .0;
      angleWeight[j] = 0;
    }
  }
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    sumQualAngle += qualAngle[i];
    sumAngle += angleWeight[i];
  }

  int numElem = _elements.size() + rv->_elements.size() - 4;
  ans += getQualDegree(numElem) + sumQualAngle / sumAngle;
  delete[] qualAngle;
  delete[] angleWeight;
  return ans;
}

#endif
void Rec2DVertex::updateWAQualEdges(double d, int a)
{
  double oldQual = getQual(VertQuality);

  _sumWQualEdge += d;
  _sumWeightEdge += a;
  _lastUpdate = Recombine2D::getNumChange();

  Rec2DData::updateVertQual(getQual(VertQuality)-oldQual, VertQuality);
}

void Rec2DVertex::relocate(SPoint2 p)
{
  //Msg::Fatal("relocate is disabled because of param on discrete face, see constructor to enable param");
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

bool Rec2DVertex::checkQuality() const
{
  double wQualAngle = .0, wQualEdge = .0;
  int weightAngle = 0, weightEdge = 0;

  for (unsigned int i = 0; i < _elements.size(); ++i) {
    wQualAngle += _elements[i]->getWeightedAngleQual(this);
    weightAngle += _elements[i]->getAngleWeight();
  }
  for (unsigned int i = 0; i < _edges.size(); ++i) {
    wQualEdge += _edges[i]->getWeightedQual();
    weightEdge += _edges[i]->getWeight();
  }

  if (wQualAngle < _sumWQualAngle - 1e12 ||
      wQualAngle > _sumWQualAngle + 1e12 ||
      weightAngle != _sumWeightAngle) {
    Msg::Error("wrong angle qual, stored %g/%d, computed %g/%d",
               _sumWQualAngle, _sumWeightAngle, wQualAngle, weightAngle);
    return false;
  }
  if (wQualEdge < _sumWQualEdge - 1e12 ||
      wQualEdge > _sumWQualEdge + 1e12 ||
      weightEdge != _sumWeightEdge) {
    Msg::Error("wrong edge qual, stored %g/%d, computed %g/%d",
               _sumWQualEdge, _sumWeightEdge, wQualEdge, weightEdge);
    return false;
  }

  return true;
}

void Rec2DVertex::printElem() const
{
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    Msg::Info("%d - %d", i, _elements[i]->getNum());
  }
}

void Rec2DVertex::printQual() const
{
  Msg::Info("d:%g, a:%g, e:%g (sa:%d, se:%d)",
            getQualDegree(), _sumWQualAngle/_sumWeightAngle, _sumWQualEdge / _sumWeightEdge,
            _sumWeightAngle, _sumWeightEdge);
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

void Rec2DVertex::_updateQualAngle()
{
  double oldQual1 = getQual(VertQuality);
  double oldQual2 = getQual(VertEdgeQuality);

  _sumWQualAngle = .0;
  _sumWeightAngle = 0;
  for (unsigned int i = 0; i < _elements.size(); ++i) {
    _sumWeightAngle += _elements[i]->getAngleWeight();
    _sumWQualAngle += _elements[i]->getWeightedAngleQual(this);
  }
  _lastUpdate = Recombine2D::getNumChange();

  Rec2DData::updateVertQual(getQual(VertQuality)-oldQual1, VertQuality);
  Rec2DData::updateVertQual(getQual(VertEdgeQuality)-oldQual2, VertEdgeQuality);
}


double Rec2DVertex::_qualDegree(int numEl) const
{
  int nEl = numEl > -1 ? numEl : _elements.size();
  if (nEl == 0) return -REC2D_BIG_NUMB;
  if (_onWhat > -1) return _qualVSnum[_onWhat][nEl];
  return std::max(1. - fabs(2./M_PI * _angle/nEl - 1.), .0);
}

/**  Rec2DElement  **/
/********************/
Rec2DElement::Rec2DElement(MTriangle *t, const Rec2DEdge **re, Rec2DVertex **rv)
: _mEl((MElement *)t), _numEdge(3), _pos(-1)
{
  for (int i = 0; i < 3; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 3; ++i)
    _elements[i] = Rec2DEdge::getTheOnlyElement(_edges[i]);
  _edges[3] = NULL;
  _elements[3] = NULL;

  reveal(rv);
  if (!edgesAreInOrder(_edges, 3)) Msg::Error("tri |%d|", getNum());
}

Rec2DElement::Rec2DElement(MQuadrangle *q, const Rec2DEdge **re, Rec2DVertex **rv)
: _mEl((MElement *)q), _numEdge(4), _pos(-1)
{
  for (int i = 0; i < 4; ++i)
    _edges[i] = (Rec2DEdge*)re[i];
  for (int i = 0; i < 4; ++i)
    _elements[i] = Rec2DEdge::getTheOnlyElement(_edges[i]);

  reveal(rv);
  if (!edgesAreInOrder(_edges, 4)) Msg::Error("quad |%d|", getNum());
}

void Rec2DElement::hide()
{
  if (_actions.size())
    Msg::Error("[Rec2DElement] I don't want to be hidden :'(");
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
  if (_numEdge == 3)
    Rec2DData::rmvHasZeroAction(this);
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
  if (_numEdge == 3)
    Rec2DData::addHasZeroAction(this);
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
}

bool Rec2DElement::has(const Rec2DEdge *re) const
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_edges[i] == re)
      return true;
  }
  return false;
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
  int a, b = a = 0;
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

void Rec2DElement::add(const Rec2DAction *ra)
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    if (_actions[i] == ra) {
      Msg::Error("[Rec2DElement] Action was already there");
      return;
    }
  }
  if (Recombine2D::onlyRecombinations()) {
    switch (_actions.size()) {
      case 0 :
        Rec2DData::addHasOneAction(this, (Rec2DAction*)ra);
        Rec2DData::rmvHasZeroAction(this);
        Rec2DData::elementChgAction(this, 0, 1);
        break;
      case 1 :
        Rec2DData::rmvHasOneAction(this, _actions[0]);
        Rec2DData::elementChgAction(this, 1, 2);
        break;
      case 2 :
        break;
      default :
        Msg::Error("Should not have more than 3 actions");
    }
  }
  _actions.push_back((Rec2DAction*)ra);
}

void Rec2DElement::rmv(const Rec2DAction *ra)
{
  unsigned int i = 0;
  while (i < _actions.size()) {
    if (_actions[i] == ra) {
      if (Recombine2D::onlyRecombinations()) {
        switch (_actions.size()) {
          case 1 :
            Rec2DData::rmvHasOneAction(this, (Rec2DAction*)ra);
            Rec2DData::addHasZeroAction(this);
            Rec2DData::elementChgAction(this, 1, 0);
            break;
          case 2 :
            Rec2DData::addHasOneAction(this, _actions[i == 0 ? 1 : 0]);
            Rec2DData::elementChgAction(this, 2, 1);
            break;
          case 3 :
            Rec2DData::elementChgAction(this, 3, 2);
          default :;
        }
      }
      _actions[i] = _actions.back();
      _actions.pop_back();
      return;
    }
    ++i;
  }
  Msg::Error("[Rec2DElement] Didn't removed action, didn't have it");
}

bool Rec2DElement::has(const Rec2DAction *ra) const
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    if (_actions[i] == ra)
      return true;
  }
  return false;
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

void Rec2DElement::getMoreNeighbours(std::vector<Rec2DElement*> &elem) const
{
  for (int i = 0; i < _numEdge; ++i) {
    if (_elements[i]) elem.push_back(_elements[i]);
  }
}

void Rec2DElement::getMoreUniqueActions(std::vector<Rec2DAction*> &vectRA) const
{
  unsigned int size = vectRA.size();
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    unsigned int j = -1;
    while (++j < size && vectRA[j] != _actions[i]);
    if (j == size)
      vectRA.push_back(_actions[i]);
  }
}

void Rec2DElement::getMoreUniqueActions(
    std::set<Rec2DAction*, gterRec2DAction> &setRA) const
{
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    setRA.insert(_actions[i]);
  }
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
    Msg::Info("im %d, the vertex is %d", getNum(), rv->getNum());
    return -1.;
  }

  int i1 = (index+_numEdge-1)%_numEdge;
  int i0 = (index+1)%_numEdge;
  double ang =  atan2(vert[i0]->v() - rv->v(), vert[i0]->u() - rv->u())
                - atan2(vert[i1]->v() - rv->v(), vert[i1]->u() - rv->u());

  static unsigned int a = 0;
  if (++a < 2) Msg::Warning("FIXME use real angle instead of parametric angle");

  if (ang < .0)
    return ang + 2.*M_PI;
  return ang;
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
    Msg::Error("not only %d vertices or edge not in order [1] (im %d)", _numEdge, getNum());
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
      Msg::Error("not only %d vertices or edge not in order [2] (im %d)", _numEdge, getNum());
      for (int i = 0; i < _numEdge; ++i) {
        _edges[i]->print();
      }
      return false;
    }
  }
  if ((v[0] == v1 && v[_numEdge-1] != v0) ||
      (v[0] == v0 && v[_numEdge-1] != v1)   ) {
    Msg::Error("not only %d vertices or edge not in order [3] (im %d)", _numEdge, getNum());
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

  if (Recombine2D::onlyRecombinations()) {
    if (_numEdge == 3) {
      if (_actions.size() == 1 && !Rec2DData::hasHasOneAction(this)) {
        Msg::Error("Data doesn't know I've only 1 action(im %d)", getNum());
        return false;
      }
      if (_actions.size() == 0 && !Rec2DData::hasHasZeroAction(this)) {
        Msg::Error("Data doesn't know I've only 0 action(im %d)", getNum());
        return false;
      }
    }
  }
  for (unsigned int i = 0; i < _actions.size(); ++i) {
    if (!_actions[i]->has(this)) {
      Msg::Error("action doesn't have me (im %d)", getNum());
      return false;
    }
  }
  return true;
}

void Rec2DElement::print() const
{
  int num[4];
  for (int i = 0; i < _numEdge; ++i) {
    if (_elements[i])
      num[i] = _elements[i]->getNum();
    else
      num[i] = 0;
  }
  if (_numEdge == 3)
    Msg::Info("tri %d - %d %d %d - nRA %d", getNum(), num[0], num[1], num[2], _actions.size());
  if (_numEdge == 4)
    Msg::Info("quad %d - %d %d %d %d - nRA %d", getNum(), num[0], num[1], num[2], num[3], _actions.size());
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

/**  Rec2DAlgo  **/
/*****************/
namespace Rec2DAlgo {
void execute(bool complete)
{
  using namespace data;

  if (initial || current) {
    Msg::Error("[Rec2DAlgo] Already have a sequence, cannot execute");
    return;
  }
  initial = new Node();
  current = initial;
  quadOk = initial;
  //Msg::Warning("root is %d", initial);

#ifdef REC2D_DRAW
  __draw(.0);
#endif

  while (func::lookAhead(complete)) {
    func::chooseBestSequence();

#ifdef DRAW_WHEN_SELECTED
    __draw(REC2D_WAIT_SELECTED);
#endif
  }
}

void clear()
{
  Rec2DData::_cur->_NActions.clear();
  Rec2DData::_cur->_sortedNActions.clear();


  Rec2DData::_cur->_OActions.clear();
  Rec2DData::_cur->_sortedOActions.clear();

  using namespace data;

  delete initial;
  initial = current = quadOk = NULL;
  if (sequence.size()) {
    Msg::Error("Don't think sequence can be of size %d", sequence.size());
  }
  sequence.clear();
}

bool paramOK()
{
  using namespace data;
  bool ans = true;
  if (root_std_srch > 4 || root_std_srch < 1) {
    Msg::Error("Wrong root std search: %d (not in {1,..,4})", root_std_srch);
    ans = false;
  }
  if (plus_std_srch > 6 || plus_std_srch < 1) {
    Msg::Error("Wrong plus std search: %d (not in {1,..,6})", root_std_srch);
    ans = false;
  }
  if (plus_tree_srch && !root_tree_srch) {
    Msg::Error("Cannot plus tree-search if no root tree-searching");
    ans = false;
  }
  return ans;
}

bool paramOKSimpleAlgo()
{
  using namespace data;
  bool ans = true;
  if (root_std_srch != 0) {
    Msg::Error("Wrong root std search: %d (not 0)", root_std_srch);
    ans = false;
  }
  if (plus_std_srch != 0) {
    Msg::Error("Wrong plus std search: %d (not 0)", plus_std_srch);
    ans = false;
  }
  return ans;
}

bool setParam(int horiz, int code)
{
  using namespace data;

  horizon = horiz;
  codeParam = code;

  unsigned char code_root = static_cast<unsigned char>(code);
  unsigned char code_tree = static_cast<unsigned char>(code >> 8);

  root_tree_srch = code_root        % 2;
  root_one_srch =  (code_root >> 1) % 2;
  root_take_best = (code_root >> 2) % 2;
  root_std_srch =  code_root >> 3;
  plus_tree_srch = code_tree        % 2;
  plus_one_srch =  (code_tree >> 1) % 2;
  plus_take_best = (code_tree >> 2) % 2;
  // plus_std_srch =  code_tree>>3;
  // for try_Clique
  plus_std_srch =  (code_tree>>3) % 7;
  try_clique = code_tree>>3 > 6;

  return (root_std_srch == 0 && plus_std_srch == 0) || paramOK();
}

void getParam(int &horiz, int &code)
{
  using namespace data;
  horiz = horizon;
  code = codeParam;
}

void computeAllParam(std::vector<int> &v, bool restricted)
{
  std::set<int> set;
  for (int code_root = 8*1; code_root < 8*5; ++code_root) {
    for (int code_tree = 8*1; code_tree < 8*7; ++code_tree) {
      if (restricted &&
          (code_root >> 3 > 2 || code_tree >> 3 == 3 || code_root % 2)) {
        continue;
      }
      bool b = (code_tree >> 1) % 4 == (code_root >> 1) % 4;
      switch (code_tree >> 3) {
      case 1: b = b && code_root >> 3 == 1; break;
      case 2: b = b && code_root >> 3 == 2; break;
      case 3: b = b && code_root >> 3 == 3; break;
      case 4: b = b && code_root >> 3 == 2; break;
      case 5: b = b && code_root >> 3 == 4; break;
      case 6: b = b && code_root >> 3 == 4; break;
      }
      if ((code_root % 2 && b)
          || (!(code_root % 2) && !(code_tree % 2))) {
        set.insert((code_tree << 8) + code_root);
        //if ((code_root >> 1) % 2) {
          // for try_Clique
          set.insert((code_tree << 8) + code_root + (8*6 << 8));
        //}
        //Msg::Info("%d %d", code_tree, code_root);
      }
    }
  }
  v.assign(set.begin(), set.end());
}

namespace data {
  bool root_tree_srch = false;
  bool root_one_srch = false;
  bool root_take_best = false;
  int root_std_srch = 0;
  bool plus_tree_srch = false;
  bool plus_one_srch = false;
  bool plus_take_best = false;
  int plus_std_srch = 0;
  int horizon = 0;
  int codeParam = 0;
  Node *current = NULL;
  Node *initial = NULL;
  Node *quadOk = NULL;
  std::vector<Node*> sequence;

  bool try_clique = false;
}

namespace func {
  using namespace data;

  bool lookAhead(bool complete)
  {
    current->goAhead(0, complete);
    return current->numChildren();
  }

  void chooseBestSequence()
  {
    Node *next = current->getNodeBestSequence();
#ifdef DRAW_BEST_SEQ
    if (next) next->colourBestSequence(1);
#endif
    if (current->choose(next))
      current = next;
    else
      Msg::Fatal("Wrong child node in lookahead tree");
  }

  Rec2DElement* best(std::vector<Rec2DElement*> &available)
  {
    std::set<Rec2DAction*, gterRec2DAction> actions;
    for (unsigned int i = 0; i < available.size(); ++i)
      available[i]->getMoreUniqueActions(actions);

    std::vector<Rec2DElement*> candidate;
    (*actions.begin())->getElements(candidate);

    std::vector<Rec2DElement*> unionBest;
    for (unsigned int i = 0; i < candidate.size(); ++i) {
      for (unsigned int j = 0; j < available.size(); ++j) {
        if (candidate[i] == available[j]) {
          unionBest.push_back(candidate[i]);
        }
      }
    }
    return unionBest[rand() % unionBest.size()];
  }

  Rec2DElement* random(std::vector<Rec2DElement*> &v)
  {
    return v[rand() % v.size()];
  }

  void searchForOne(std::vector<Rec2DElement*> &triangles, bool takeBest)
  {
    Rec2DAction *ra;
    if (takeBest)
      ra = getBestOAction();
    else
      ra = getRandomOAction();

    if (ra) {
      if (ra->getElement(0)->getNumActions() == 1) {
        triangles.push_back(ra->getElement(0));
      }
      else if (ra->getElement(1)->getNumActions() == 1) {
        triangles.push_back(ra->getElement(1));
      }
      else {
        Msg::Error(" it was not a one action :( %d %d",
                   ra->getElement(0)->getNumActions(),
                   ra->getElement(1)->getNumActions());
      }
    }
  }

  void searchForRootStd(std::vector<Rec2DElement*> &triangles)
  {
    switch (root_std_srch) {
    case 0: // Simple algo
      searchForLessAction(triangles);
      return;
    case 1:
      searchForAll(triangles, root_take_best);
      return;
    case 2:
      searchForQAll(triangles, root_take_best);
      return;
    case 3:
      searchForQFirst(triangles);
      return;
    case 4:
      searchForQLast(triangles);
      return;
    default:
      Msg::Error("Wrong root standard search");
    }
  }

  void searchForPlusStd(std::vector<Rec2DElement*> &triangles, int depth)
  {
    switch (plus_std_srch) {
    case 0: // Simple algo
      searchForTreeLessAction(triangles);
      return;
    case 1:
    {
      searchForAll(triangles, plus_take_best);
      return;
    }
    case 2:
    {
      if (depth > Rec2DData::getNumNActions()/3)
        searchForTAll(triangles);
      else
        searchForQAll(triangles, plus_take_best);
      return;
    }
    case 3:
      searchForQFirst(triangles);
      return;
    case 4:
      searchForTAll(triangles);
      return;
    case 5:
      searchForTFirst(triangles);
      return;
    case 6:
      searchForTLast(triangles);
      return;
    default:
      Msg::Error("Wrong plus standard search");
    }
  }

  void searchForLessAction(std::vector<Rec2DElement*> &triangles)
  {
    Rec2DElement *re;
    re = Rec2DData::getRandomLessAction();
    if (re) triangles.push_back(re);
  }

  void searchForTreeLessAction(std::vector<Rec2DElement*> &triangles)
  {
    searchForTAll(triangles);
    if (triangles.empty()) return;

    int minAction = 3;
    std::vector<Rec2DElement*> candidates;
    for (unsigned int i = 0; i < triangles.size(); ++i) {
      if (triangles[i]->getNumActions() < minAction) {
        minAction = triangles[i]->getNumActions();
        candidates.clear();
        candidates.push_back(triangles[i]);
      }
      else if (triangles[i]->getNumActions() == minAction) {
        candidates.push_back(triangles[i]);
      }
    }
    if (minAction < 1) {
      Msg::Fatal("[searchForTreeLessAction] min action is %d", minAction);
    }

    triangles.clear();
    triangles.push_back(candidates[rand() % candidates.size()]);
  }

  void searchForAll(std::vector<Rec2DElement*> &triangles, bool takeBest)
  {
    Rec2DAction *ra;
    if (takeBest)
      ra = (Rec2DAction*)Rec2DData::getBestAction();
    else
      ra = (Rec2DAction*)Rec2DData::getRandomAction();

    if (ra) triangles.push_back(ra->getElement(rand() % 2));
  }

  void searchForQAll(std::vector<Rec2DElement*> &triangles, bool takeBest)
  {
    Rec2DAction *ra;
    if (takeBest)
      ra = getBestNAction();
    else
      ra = getRandomNAction();

    if (!ra) return;

    for (int i = 0; i < 2; ++i) {
      std::vector<Rec2DElement*> elem;
      ra->getElement(i)->getMoreNeighbours(elem);
      for (unsigned int j = 0; j < elem.size(); ++j) {
        if (elem[j]->isQuad()) {
          triangles.push_back(ra->getElement(i));
          return;
        }
      }
    }
    Msg::Fatal("Didn't get a action neighbour to a quad");
  }

  void searchForQFirst(std::vector<Rec2DElement*> &triangles)
  {
    triangles.clear();
    Node *n = data::quadOk;
    while (n != data::current) {
      n = n->getChild();
      n->getAction()->getNeighbElemWithActions(triangles);
      if (triangles.size()) return;
    }

    searchForTFirst(triangles);
  }

  void searchForQLast(std::vector<Rec2DElement*> &triangles)
  {
    if (current != initial)
      current->getAction()->getNeighbElemWithActions(triangles);
  }

  void searchForTAll(std::vector<Rec2DElement*> &triangles)
  {
    triangles.clear();
    std::set<Rec2DElement*> set;
    for (unsigned int i = 0; i < data::sequence.size(); ++i) {
      std::vector<Rec2DElement*> elem;
      data::sequence[i]->getAction()->getNeighbElemWithActions(elem);
      set.insert(elem.begin(), elem.end());
    }
    triangles.assign(set.begin(),set.end());
  }

  void searchForTFirst(std::vector<Rec2DElement*> &triangles)
  {
    triangles.clear();
    unsigned int i = 0;
    while (triangles.empty() && i < data::sequence.size()) {
      data::sequence[i]->getAction()->getNeighbElemWithActions(triangles);
      ++i;
    }
  }

  void searchForTLast(std::vector<Rec2DElement*> &triangles)
  {
    data::sequence.back()->getAction()->getNeighbElemWithActions(triangles);
  }

  Rec2DAction* getBestNAction()
  {
    std::set<Rec2DAction*, gterRec2DAction>::iterator it;
    it = Rec2DData::_cur->_sortedNActions.begin();

    while (it != Rec2DData::_cur->_sortedNActions.end()
           && !Rec2DData::has(*it)) ++it;

    return it != Rec2DData::_cur->_sortedNActions.end() ? *it : NULL;
  }

  Rec2DAction* getRandomNAction()
  {
    if (Rec2DData::_cur->_sortedNActions.empty()) {
      Rec2DData::_cur->_NActions.clear();
      return NULL;
    }

    unsigned int count = 0; // limit number of search
    while (count < Rec2DData::_cur->_sortedNActions.size()) {
      int index = rand() % Rec2DData::_cur->_NActions.size();
      Rec2DAction *ra = Rec2DData::_cur->_NActions[index];
      if (Rec2DData::_cur->_sortedNActions.find(ra) ==
          Rec2DData::_cur->_sortedNActions.end()) {
        Rec2DData::_cur->_NActions[index] = Rec2DData::_cur->_NActions.back();
        Rec2DData::_cur->_NActions.pop_back();
      }
      else if(Rec2DData::has(ra)) {
        return ra;
      }
      ++count;
    }
    return NULL;
  }

  Rec2DAction* getBestOAction()
  {
    if (Rec2DData::_cur->_sortedOActions.empty()) return NULL;
    return *Rec2DData::_cur->_sortedOActions.begin();
  }

  Rec2DAction* getRandomOAction()
  {
    if (Rec2DData::_cur->_sortedOActions.empty()) {
      Rec2DData::_cur->_OActions.clear();
      return NULL;
    }

    while (Rec2DData::_cur->_OActions.size()) {
      int index = rand() % Rec2DData::_cur->_OActions.size();
      Rec2DAction *ra = Rec2DData::_cur->_OActions[index];
      if (Rec2DData::_cur->_sortedOActions.find(ra) ==
          Rec2DData::_cur->_sortedOActions.end()) {
        Rec2DData::_cur->_OActions[index] = Rec2DData::_cur->_OActions.back();
        Rec2DData::_cur->_OActions.pop_back();
      }
      else {
        return ra;
      }
    }
    return NULL;
  }

  void findMaximalClique(std::vector<Rec2DAction*> &actions)
  { // vector 'actions' should be a clique of incompatible actions

    // find other actions incompatible with input actions
    std::vector<Rec2DAction*> otherIncompatible;
    for (unsigned int i = 0; i < actions.size(); ++i) {
      std::vector<Rec2DAction*> incompI;
      actions[i]->getIncompatible(incompI);
      relativeComplement(actions, incompI);
      if (i == 0)
        otherIncompatible = incompI;
      else
        intersection(incompI, otherIncompatible);
    }

    if (otherIncompatible.empty()) return;

    // Compute incompatibilities & Search a maximum
    // clique among those other actions:
    std::vector<Ra2Incomp*> incompatibilities;
    for (unsigned int i = 0; i < otherIncompatible.size(); ++i) {
      std::vector<Rec2DAction*> incompI;
      otherIncompatible[i]->getIncompatible(incompI);
      intersection(otherIncompatible, incompI);
      Ra2Incomp *ra2i = new Ra2Incomp(otherIncompatible[i], incompI);
      incompatibilities.push_back(ra2i);
    }

    findMaximumClique(incompatibilities);

    for (unsigned int i = 0; i < incompatibilities.size(); ++i) {
      actions.push_back(incompatibilities[i]->first);
      delete incompatibilities[i];
    }
  }

  void findMaximumClique(std::vector<Ra2Incomp*> &truc)
  {
    if (truc.empty()) {
      Msg::Error("error2 here");
      return;
    }

    std::vector<Ra2Incomp*> candidate, ans;
    Ra2Incomp *remember;

    std::make_heap(truc.begin(), truc.end(), CompareIncomp());

    while (truc.size()) {

      // remove all actions that can not lead to better clique than ans
      while (truc.size() && truc.front()->second.size() < ans.size()) {
        while (truc.front()->second.size()) {
          removeLinkIncompatibilities(truc, truc.front()->first,
                                            truc.front()->second.front());
        }
        std::pop_heap(truc.begin(), truc.end(), CompareIncomp());
        delete truc.back();
        truc.pop_back();
        std::make_heap(truc.begin(), truc.end(), CompareIncomp());
      }
      if (truc.empty()) break;

      if (truc[0]->second.empty()) {
        std::vector<Rec2DAction*> actions(1, truc.front()->first);
        subsetIncompatibilities(truc, actions, ans);
      }
      else {
        // take action A which has the least incompatible
        // and action B which is the first incompatible with A.
        // Then find common incompatibles
        std::vector<Rec2DAction*> actions = truc.front()->second; // A
        unsigned i = 0;
        while (i < truc.size()) {
          if (truc[i]->first == truc.front()->second.front()) {
            remember = truc[i];
            intersection(truc[i]->second, actions); // B
            break;
          }
          ++i;
        }
        if (i == truc.size()) Msg::Error("error3 here");

        // create incompatibilities vector & findMaximumClique
        subsetIncompatibilities(truc, actions, candidate);
        if (candidate.size()) findMaximumClique(candidate);

        // copy candidate if better
        if (candidate.size() + 2 > ans.size()) {
          actions.clear();
          actions.push_back(truc.front()->first); // A
          actions.push_back(truc.front()->second.front()); // B
          for (unsigned int i = 0; i < candidate.size(); ++i) {
            actions.push_back(candidate[i]->first);
          }
          subsetIncompatibilities(truc, actions, ans);
        }

        // remove incomp link between A & B and start again
        removeLinkIncompatibilities(truc, truc.front()->first,
                                          truc.front()->second.front());
        std::make_heap(truc.begin(), truc.end(), CompareIncomp());
      }
    }

    for (unsigned int i = 0; i < candidate.size(); ++i) delete candidate[i];
    for (unsigned int i = 0; i < truc.size(); ++i) delete truc[i];
    truc = ans;
  }

  void subsetIncompatibilities(const std::vector<Ra2Incomp*> &complete,
                               const std::vector<Rec2DAction*> &subAction,
                                     std::vector<Ra2Incomp*> &subset)
  {
    for (unsigned int i = 0; i < subset.size(); ++i) {
      delete subset[i];
    }
    subset.clear();
    for (unsigned int i = 0; i < subAction.size(); ++i) {
      unsigned int j = 0;
      while (j < complete.size()) {
        if (complete[j]->first == subAction[i]) {
          std::vector<Rec2DAction*> tmp1 = complete[j]->second;
          intersection(subAction, tmp1);
          Ra2Incomp *tmp2 = new Ra2Incomp(complete[j]->first, tmp1);
          subset.push_back(tmp2);
          break;
        }
        ++j;
      }
      if (j == complete.size()) Msg::Error("error4 here");
    }
  }

  void removeLinkIncompatibilities(std::vector<Ra2Incomp*> &set,
                                   const Rec2DAction *a, const Rec2DAction *b)
  {
    if (a == NULL || b == NULL) Msg::Error("gneeeeeeeeeeeee");
    bool aOK = false, bOK = false;
    unsigned int i = 0;
    while (i < set.size()) {
      const Rec2DAction *other = NULL;
      if (set[i]->first == a) {
        aOK = true;
        other = b;
      }
      else if (set[i]->first == b) {
        bOK = true;
        other = a;
      }
      if (other) {
        unsigned int j = 0;
        while (j < set[i]->second.size()) {
          if (set[i]->second[j] == other) {
            set[i]->second[j] = set[i]->second.back();
            set[i]->second.pop_back();
            --j;
            break;
          }
          ++j;
        }
        if (j == set[i]->second.size()) Msg::Error("error7 here");
      }
      if (aOK && bOK) return;
      ++i;
    }
    Msg::Error("error6 here");
  }

  void relativeComplement(const std::vector<Rec2DAction*> &vA,
                                std::vector<Rec2DAction*> &vB)
  {
    unsigned int i = 0;
    while (i < vB.size()) {
      for (unsigned int j = 0; j < vA.size(); ++j) {
        if (vB[i] == vA[j]) {
          vB[i] = vB.back();
          vB.pop_back();
          --i;
          break;
        }
      }
      ++i;
    }
  }

  void intersection(const std::vector<Rec2DAction*> &vA,
                          std::vector<Rec2DAction*> &vB)
  {
    unsigned int i = 0;
    while (i < vB.size()) {
      unsigned int j = 0;
      while (j < vA.size()) {
        if (vB[i] == vA[j]) break;
        ++j;
      }
      if (j == vA.size()) {
        vB[i] = vB.back();
        vB.pop_back();
      }
      else ++i;
    }
  }
}

Node::Node() : _ra(NULL), _dataChange(NULL), _createdActions(NULL)
{
  _quality = Rec2DData::getGlobalQuality();
}

Node::Node(Rec2DAction *action) : _ra(action), _dataChange(NULL),
                                  _createdActions(NULL)
{
  _quality = Rec2DData::getGlobalQuality() + _ra->getRealReward();
}

Node::~Node()
{
  for (unsigned int j = 0; j < _children.size(); ++j) {
    delete _children[j];
  }
  if (_createdActions) {
    Msg::Warning("What should I do ?");
    for (unsigned int i = 0; i < _createdActions->size(); ++i) {
      (*_createdActions)[i]->rmvPointing();
      delete (*_createdActions)[i];
    }
    delete _createdActions;
  }
  if (_ra) {
    _ra->rmvPointing();
  }
}

Node* Node::getNodeBestSequence()
{
  // return NULL if no children;
  Node *bestNode = NULL;
  int maxLeafQual = 0; // /!\ ok if quality criterion is >= 0

  for (unsigned int i = 0; i < _children.size(); ++i) {
    int qual = _children[i]->getMaxLeafQual();
    if (qual > maxLeafQual) {
      bestNode = _children[i];
      maxLeafQual = qual;
    }
    //Msg::Info("for child %d, I get %d -> max=%d", _children[i], qual, maxLeafQual);
  }
  return bestNode;
}

int Node::getMaxLeafQual() const
{
  if (_children.empty()) return _quality;

  int maxLeafQual = 0; // /!\ ok if quality criterion is >= 0
  for (unsigned int i = 0; i < _children.size(); ++i) {
    maxLeafQual = std::max(maxLeafQual, _children[i]->getMaxLeafQual());
  }
  return maxLeafQual;
}

bool Node::choose(Node *node)
{
  if (!node) return false;

  for (unsigned int i = 0; i < _children.size(); ++i) {
    if (_children[i] == node) {
      if (!node->makeChanges()) {
        Msg::Error("No changes");
        return false;
      }
      updateNActions(node);
      _children[i] = NULL;
      for (unsigned int j = 0; j < _children.size(); ++j) {
        delete _children[j]; // sufficient ?
      }
      _children.clear();
      _children.push_back(node);
      return true;
    }
  }
  return false;
}

void Node::updateNActions(Node *node)
{
  // - remove obsolete actions from the set
  //   (for performance, actions in the vector will be removed later)
  // - add new actions which are neighbour of quadrangle in set and vector

  if (!node->_dataChange) {
    Msg::Fatal("no changes");
    return;
  }

  std::set<Rec2DAction*> hiddenRA;
  node->_dataChange->getHiddenActions(hiddenRA);
  std::set<Rec2DAction*>::iterator it = hiddenRA.begin();
  while (it != hiddenRA.end()) {
    Rec2DData::_cur->_sortedNActions.erase(*it);
    ++it;
  }

  std::vector<Rec2DAction*> neighbourActions;
  node->_ra->getTouchedActions(neighbourActions);
  // since changes are made, we do not get obsolete actions

  for (unsigned int i = 0; i < neighbourActions.size(); ++i) {
    std::pair<std::set<Rec2DAction*, gterRec2DAction>::iterator, bool> p;
    p = Rec2DData::_cur->_sortedNActions.insert(neighbourActions[i]);
    if (p.second) Rec2DData::_cur->_NActions.push_back(neighbourActions[i]);
  }
}

void Node::goAhead(int depth, bool complete)
{
  if (depth > data::horizon - 1 || depth < 0) {
    Msg::Fatal("the fuck..");
  }

  if (depth == 0) {
    if (complete) branchComplete(depth);
    else branch_root();
    return;
  }

  // 1) Make changes
  _dataChange = Rec2DData::getNewDataChange();
  _ra->apply(_dataChange, _createdActions);
  if (_createdActions) {
    for (unsigned int i = 0; i < _createdActions->size(); ++i)
      (*_createdActions)[i]->addPointing();
  }

  // 2) branch on children
  if (complete) branchComplete(depth);
  else branch(depth);

  // 3) revert changes
  if (!Rec2DData::revertDataChange(_dataChange))
    Msg::Error("Unreverted changes");
  else
    Recombine2D::incNumChange();
  _dataChange = NULL;
}

void Node::branch_root()
{
  using namespace data;
  using namespace func;

  // 1) search a set of triangles
  int searchType = 0;
  std::vector<Rec2DElement*> candidateTriangle;

  while (candidateTriangle.empty()) {
    switch (searchType) {
    case 0:
      if (horizon > 1 && root_tree_srch && current != initial) {
        for (unsigned int i = 0; i < _children.size(); ++i)
          _children[i]->goAhead(1);
        return;
      }
      else {
        for (unsigned int i = 0; i < _children.size(); ++i)
          delete _children[i]; //is it sufficient ?
        _children.clear();
      }
      break;

    case 1:
      if (root_one_srch) searchForOne(candidateTriangle, root_take_best);
      break;

    case 2:
      searchForRootStd(candidateTriangle);
      break;

    case 3:
      searchForAll(candidateTriangle, root_take_best);
      break;

    case 4:
      // end of algorithm
      return;

    default:
      Msg::Fatal("No reason to be here");
    }
    ++searchType;
  }

  // 2) take actions of the best or a random
  Rec2DElement *rt;
  if (root_take_best)
    rt = best(candidateTriangle);
  else
    rt = random(candidateTriangle);
  std::vector<Rec2DAction*> actions;
  rt->getActions(actions);

  // 2b) Find maximum clique if asked
  if (try_clique) {
    unsigned int num = actions.size();
    findMaximalClique(actions);
    static int more = 0, same = 0;
    if (actions.size() > num) ++more;
    else if (actions.size() == num) ++same;
    else Msg::Fatal("You've got to be kidding me. -_-");
    Msg::Info("same - more : %d - %d", same, more);
  }

  // 3) branch on the actions
  if (_children.size()) {
    Msg::Fatal("ARGREAGAEGERGA");
  }
  for (unsigned int i = 0; i < actions.size(); ++i)
    _children.push_back(new Node(actions[i]));

  // Optimization 2 : do not branch if just one child and
  // if no influence of subchildren...
  if (horizon > 1 && (_children.size() != 1 || root_tree_srch)) {
    for (unsigned int i = 0; i < _children.size(); ++i) {
      //Msg::Info("child %d -> q%d(%d)", _children[i], _children[i]->getQual(), _children[i]->getReward());
      _children[i]->goAhead(1);
    }
  }
  /*else {
    for (unsigned int i = 0; i < _children.size(); ++i) {
      Msg::Info("child %d -> q%d(%d)", _children[i], _children[i]->getQual(), _children[i]->getReward());
    }
  }*/

}

void Node::branch(int depth)
{
  if (depth > data::horizon || depth < 1) {
    if (depth == 0) {
      Msg::Error("branch() cannot be called for root, use branch_root()");
      return;
    }
    Msg::Fatal("the fuck !");
  }
  using namespace data;
  using namespace func;
  sequence.push_back(this);

  // 1) search a set of triangles
  int searchType = 0;
  std::vector<Rec2DElement*> candidateTriangle;

  while (candidateTriangle.empty()) {
    switch (searchType) {
    case 0:
      if (depth < horizon - 1 && plus_tree_srch && current != initial) {
        if (_children.size()) {
          for (unsigned int i = 0; i < _children.size(); ++i)
            _children[i]->goAhead(depth + 1);
        }
        if (sequence.back() != this) Msg::Fatal("Aaargh 1");
          sequence.pop_back();

        return;
      }
      else {
        for (unsigned int i = 0; i < _children.size(); ++i)
          delete _children[i]; //is it sufficient ?
        _children.clear();
      }
      break;

    case 1:
      if (plus_one_srch) searchForOne(candidateTriangle, plus_take_best);
      break;

    case 2:
      searchForPlusStd(candidateTriangle, depth);
      break;

    case 3:
      searchForAll(candidateTriangle, plus_take_best);
      break;

    case 4:
      if (sequence.back() != this) Msg::Fatal("Aaargh 2");
      sequence.pop_back();
      return;

    default:
      Msg::Fatal("No reason to be here");
    }
    ++searchType;
  }

  // 2) take actions of the best or a random
  Rec2DElement *rt;
  if (plus_take_best)
    rt = best(candidateTriangle);
  else
    rt = random(candidateTriangle);
  std::vector<Rec2DAction*> actions;
  rt->getActions(actions);

  // 2b) Find maximum clique if asked
  if (try_clique) {
    unsigned int num = actions.size();
    findMaximalClique(actions);
    static int more = 0, same = 0;
    if (actions.size() > num) ++more;
    else if (actions.size() == num) ++same;
    else Msg::Fatal("You've got to be kidding me. -_-");
    //Msg::Info("same - more : %d - %d", same, more);
  }

  // 3) branch on the actions
  if (_children.size()) {
    Msg::Fatal("ARGREAGAEGERGA");
  }
  for (unsigned int i = 0; i < actions.size(); ++i)
    _children.push_back(new Node(actions[i]));

  if (depth + 1 < horizon) {
    for (unsigned int i = 0; i < _children.size(); ++i) {
      /*std::ostringstream oss;
      for (int j = 0; j < depth; ++j)
        oss << "  ";
      oss << "child %d -> q(%d)%d";
      Msg::Info("_____%d_%d", _children[i]->getQual(), _children[i]->getReward());
      Msg::Info(oss.str().c_str(), _children[i], _children[i]->getReward(), _children[i]->getQual());*/
      _children[i]->goAhead(depth + 1);
    }
  }
  /*else {
    for (unsigned int i = 0; i < _children.size(); ++i) {
      std::ostringstream oss;
      for (int j = 0; j < depth; ++j)
        oss << "  ";
      oss << "child %d -> q(%d)%d";
      Msg::Info(oss.str().c_str(), _children[i], _children[i]->getReward(), _children[i]->getQual());
    }
  }*/

  if (sequence.back() != this) Msg::Fatal("Aaargh 3");
  sequence.pop_back();
}

void Node::branchComplete(int depth)
{
  if (depth > data::horizon || depth < 0) {
    Msg::Fatal("the fuck !");
  }
  using namespace data;
  using namespace func;
  sequence.push_back(this);

  for (unsigned int i = 0; i < _children.size(); ++i)
    delete _children[i]; //is it sufficient ?
  _children.clear();

  // Branch on all actions
  for (int i = 0; i < Rec2DData::getNumAction(); ++i)
    _children.push_back(new Node(Rec2DData::getAction(i)));

  if (depth + 1 < horizon &&
      (depth > 0 || (depth == 0 && _children.size() > 1))) {
    for (unsigned int i = 0; i < _children.size(); ++i) {
      _children[i]->goAhead(depth + 1, true);
    }
  }

  if (sequence.back() != this) Msg::Fatal("Aaargh 3");
  sequence.pop_back();
}

bool Node::makeChanges()
{
  if (_dataChange || !_ra)
    return false;

  _dataChange = Rec2DData::getNewDataChange();
  _ra->apply(_dataChange, _createdActions, Recombine2D::blossomRec());
  Recombine2D::incNumChange();

  std::vector<Rec2DElement*> tri;
  Node *n = data::quadOk;
  while (n != data::current) {
    n = n->getChild();
    n->getAction()->getNeighbElemWithActions(tri);
    if (tri.empty()) data::quadOk = n;
    else break;
  }

  return true;
}

void Node::colourBestSequence(int depth) {
  _ra->color(255,
             255*(double) (depth-1)/(data::horizon-1),
             128*(double) (depth-1)/(data::horizon-1) );

  Node *next = getNodeBestSequence();
  if (next) {
    next->colourBestSequence(depth + 1);
  }
  else {
#ifdef REC2D_DRAW
    __draw(REC2D_WAIT_BEST_SEQ);
#endif
  }
  _ra->color(183, 255, 169);
}
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

Rec2DNode::Rec2DNode(Rec2DNode *father, Rec2DAction *ra, int depth)
: _father(father), _ra(ra), _dataChange(NULL), _depth(depth),
  _reward(.0),
  _globalQuality(Rec2DData::getGlobalQuality()), _bestSeqReward(.0),
  _expectedSeqReward(.0), _createdActions(NULL), _notAllQuad(false)
{
  //printIdentity();
  if (!depth && !ra) {
    Msg::Error("[Rec2DNode:constructor] Nothing to do");
    return;
  }

  if (!father) Recombine2D::setNewTreeNode(this);

  for (int i = 0; i < REC2D_NUMB_SONS; ++i)
    _son[i] = NULL;
  if (_ra) _ra->addPointing();

  if (!depth) {
    _reward = _ra->getRealReward();
    if (Recombine2D::checkIfNotAllQuad()) {
      int initialNum = Rec2DData::getNumZeroAction();
      Rec2DDataChange *dataChg = Rec2DData::getNewDataChange();
      std::vector<Rec2DAction*> *vActions;
      _ra->apply(dataChg, vActions);
      while (Rec2DData::getNumZeroAction() == initialNum &&
             Rec2DData::getNumOneAction()                  ) {
        Rec2DAction *ra = Rec2DData::getOneAction();
        ra->apply(dataChg, vActions);
      }
      if (Rec2DData::getNumZeroAction() > initialNum) _notAllQuad = true;
      Rec2DData::revertDataChange(dataChg);
    }
    return;
  }

  // Apply changes
  std::vector<Rec2DElement*> savedNeighbours; // for Collapses
  if (_ra) {
    _ra->getNeighbElemWithActions(savedNeighbours);
    _dataChange = Rec2DData::getNewDataChange();
    _ra->apply(_dataChange, _createdActions);
    if (_createdActions) {
      for (unsigned int i = 0; i < _createdActions->size(); ++i)
        (*_createdActions)[i]->addPointing();
    }
    _reward = Rec2DData::getGlobalQuality() - _globalQuality;
  }

  // Create branches
  std::vector<Rec2DAction*> actions;
  Recombine2D::incNumChange();
  Recombine2D::nextTreeActions(actions, savedNeighbours, this);
  if (actions.empty() && depth < 0) Rec2DData::addEndNode(this);
  if (actions.size()) _createSons(actions, depth);

  // Revert changes
  if (_dataChange) {
    if (!Rec2DData::revertDataChange(_dataChange))
      Msg::Error(" 1 - don't reverted changes");
    else
      Recombine2D::incNumChange();
    _dataChange = NULL;
  }
}

Rec2DNode::~Rec2DNode()
{
  int i = -1;
  while (++i < REC2D_NUMB_SONS && _son[i]) {
    _son[i]->_rmvFather(this);
    delete _son[i];
  }
  if (_createdActions) {
    for (unsigned int i = 0; i < _createdActions->size(); ++i) {
      (*_createdActions)[i]->rmvPointing();
      delete (*_createdActions)[i];
    }
    delete _createdActions;
  }
  if (_ra) {
    _ra->rmvPointing();
    _ra = NULL;
  }
  if (_father) {
    _father->_rmvSon(this);
    if (!_father->_hasSons() && _father->canBeDeleted())
      delete _father;
  }
}

void Rec2DNode::lookahead(int depth)
{
  if (!_ra || depth < 1 || !_dataChange) {
    Msg::Error("[Rec2DNode] should not be here (lookahead)");
    return;
  }
  if (Recombine2D::revertIfNotAllQuad() && _notAllQuad) {
    Msg::Error("[Rec2DNode] not sure if it is normal... Take a look !");
    // should check if normal that 'new Node()' or 'selectbest()'
    // return a notAllQuad node
    return;
  }

  _bestSeqReward = .0;
  _expectedSeqReward = .0;

  if (_son[0]) {
    _depth = depth;
    _makeDevelopments(depth);
  }
  else {//if (depth == 1) {
    _depth = depth;
    std::vector<Rec2DElement*> savedNeighbours;
    _ra->getNeighbElemWithActions(savedNeighbours);
    std::vector<Rec2DAction*> actions;
    Recombine2D::incNumChange();
    Recombine2D::nextTreeActions(actions, savedNeighbours, this);
    if (actions.size()) _createSons(actions, depth);
  }
  //else {Msg::Warning("Why am I here ?");
  //I(( "father%d ra%d son[0]%d", _father, _ra, _son[0] ));}
}

Rec2DNode* Rec2DNode::selectBestNode(Rec2DNode *rn)
{
  if (Recombine2D::revertIfNotAllQuad() && rn->_notAllQuad) {
#ifdef DRAW_WHEN_SELECTED
    __draw(.1);
#endif
    Rec2DNode *father = rn->_father;
    while (father) {
      if (!Rec2DData::revertDataChange(rn->_dataChange))
        Msg::Error(" 4 - don't reverted changes");

      rn->_rmvFather(father);
      father->_rmvSon(rn);
      delete rn;
      rn = father;
      father = rn->_father;

      if (!rn->_getNumSon()) rn->_notAllQuad = true;
      else {
#ifdef DRAW_WHEN_SELECTED
        __draw(.1);
#endif
        return rn;
      }
    }
    return NULL;
  }

  if (!rn->_son[0])
    return NULL;

#ifdef DRAW_BEST_SEQ
  rn->_son[0]->printSequence();
#endif

  for (int i = 1; i < REC2D_NUMB_SONS; ++i) {
    rn->_delSons(false);
  }
  if (Recombine2D::dynamicTree()) {
    rn->_son[0]->_delSons(true);
  }

  if (!rn->_son[0]->makeChanges()) Msg::Error("[Rec2DNode] No changes");

#ifndef DRAW_BEST_SEQ
#ifdef DRAW_WHEN_SELECTED // draw state at origin
    __draw(REC2D_WAIT_SELECTED);
#endif
#endif

  static int a = 0;
  if (++a == 1) Msg::Warning("FIXME : if only recombines : can do all alone recombinations at beginning");

  return rn->_son[0];
}

bool Rec2DNode::makeChanges()
{
  if (_dataChange || !_ra)
    return false;
  _dataChange = Rec2DData::getNewDataChange();
#if 0//def REC2D_DRAW // draw state at origin
  double time = Cpu();
  _ra->color(0, 0, 200);
  //_ra->printTypeRew();
  //Msg::Info(" ");
  Recombine2D::drawStateOrigin();
  while (Cpu()-time < REC2D_WAIT_TIME)
    FlGui::instance()->check();
#endif
  if (Recombine2D::blossomRec())
    _ra->apply(_dataChange, _createdActions, true);
  else
    _ra->apply(_dataChange, _createdActions);
  Recombine2D::incNumChange();
  return true;
}

bool Rec2DNode::revertChanges()
{
  if (!_dataChange)
    return false;
  if (!Rec2DData::revertDataChange(_dataChange))
    Msg::Error(" 3 - don't reverted changes");
  else
    Recombine2D::incNumChange();
  _dataChange = NULL;
  return true;
}

bool Rec2DNode::operator<(Rec2DNode &other)
{
  return _globalQuality + _reward < other._globalQuality + other._reward;
}

bool Rec2DNode::canBeDeleted() const
{
  return _father && _father->_father;
}

void Rec2DNode::printIdentity() const
{
  Msg::Info("---- I am a node (n%d)", this);

  if (_father)
    Msg::Info("     I have a father (n%d)", _father);

  if (_ra) {
    Msg::Info("     My action is (ac%d)", _ra);
    _ra->printIdentity();
  }
  else
    Msg::Info("     I am the root", _father);
}

void Rec2DNode::printSequence() const
{
  static int denom = 5;
  //_ra->color(183+72*(double)(_depth+2)/denom, 255*(1-(double)(_depth+2)/denom), 169*(1-(double)(_depth+2)/denom));
  _ra->color(255, 255*(1-(double)_depth/denom), 128*(1-(double)_depth/denom));
  if (_son[0]) _son[0]->printSequence();
  else {
#ifdef REC2D_DRAW
    __draw(REC2D_WAIT_BEST_SEQ);
#endif
  }
  _ra->color(183, 255, 169);
}

void Rec2DNode::_makeDevelopments(int depth)
{
  if (Recombine2D::revertIfNotAllQuad() && _notAllQuad)
    Msg::Error("[Rec2DNode] Mais !");

  int numSon = 0;
  while (numSon < REC2D_NUMB_SONS && _son[numSon]) ++numSon;

  int i = 0, k2 = REC2D_NUMB_SONS;
  while (i < numSon) {
    _son[i]->_develop(depth-1);

    if (Recombine2D::avoidIfNotAllQuad() && _son[i]->_isNotAllQuad()) {
      if (_son[--k2]) {
        Rec2DNode *tmp = _son[k2];
        _son[k2] = _son[i];
        _son[i] = tmp;
        --numSon;
      }
      else {
        _son[k2] = _son[i];
        _son[i] = _son[--numSon];
        _son[numSon] = NULL;
      }
    }
    else {
      if (i == 0) _bestSeqReward = _son[i]->_getBestSequenceReward();
      else if (_bestSeqReward < _son[i]->_getBestSequenceReward()) {
        _bestSeqReward = _son[i]->_getBestSequenceReward();
        Rec2DNode *tmp = _son[0];
        _son[0] = _son[i];
        _son[i] = tmp;
      }
      ++i;
    }
  }

  if (numSon == 0) {
    _notAllQuad = true;
    if (!Recombine2D::revertIfNotAllQuad()) {
      // If not all quad, I can't tell which son is the best...
      Msg::Warning("I'm crazy and I don't know what I am doing Oo");
      Rec2DNode *tmpNode = _son[0];
      _son[0] = _son[k2];
      _son[k2] = tmpNode;
      _bestSeqReward = _son[0]->_getBestSequenceReward();
      ++k2;
    }
  }

  for (int j = k2; j < REC2D_NUMB_SONS; ++j) {
    _son[j]->_rmvFather(this);
    delete _son[j];
    _son[j] = NULL;
  }
}

void Rec2DNode::_createSons(const std::vector<Rec2DAction*> &actions, int depth)
{
  if (actions.empty() || _son[0]) {
    Msg::Error("[Rec2DNode:_createSons] Nothing to do");
    return;
  }

  Rec2DNode *tmpNode;
  int k1 = -1, k2 = REC2D_NUMB_SONS;
  for (unsigned int i = 0; i < actions.size(); ++i) {
    Rec2DNode *rn = new Rec2DNode(this, actions[i], depth-1);
    if (Recombine2D::avoidIfNotAllQuad() && rn->_isNotAllQuad()) {
      _son[--k2] = rn;
    }
    else {
      _son[++k1] = rn;
      if (k1 == 0) _bestSeqReward = _son[k1]->_getBestSequenceReward();
      else if (_bestSeqReward < _son[k1]->_getBestSequenceReward()) {
        _bestSeqReward = _son[k1]->_getBestSequenceReward();
        tmpNode = _son[0];
        _son[0] = _son[k1];
        _son[k1] = tmpNode;
      }
    }
  }

  if (k1 < 0) {
    _notAllQuad = true;
    if (!Recombine2D::revertIfNotAllQuad()) {
      // If not all quad, I can't tell which son is the best...
      ++k1;
      tmpNode = _son[k1];
      _son[k1] = _son[k2];
      _son[k2] = tmpNode;
      _bestSeqReward = _son[k1]->_getBestSequenceReward();
      ++k2;
    }
  }

  for (int i = k2; i < REC2D_NUMB_SONS; ++i) {
    _son[i]->_rmvFather(this);
    delete _son[i];
    _son[i] = NULL;
  }
}

void Rec2DNode::_develop(int depth)
{
  if (!depth || !_ra) {
    if (!_ra) Msg::Error("[Rec2DNode] should not be here (develop)");
    return;
  }
  if (Recombine2D::revertIfNotAllQuad() && _notAllQuad) {
    Msg::Error("[Rec2DNode] No, no, no, it is not normal !");
    // see lookahead
    return;
  }
  _depth = depth;

  _bestSeqReward = .0;
  _expectedSeqReward = .0;

  std::vector<Rec2DElement*> neighbours;
  if (!_son[0])
    _ra->getNeighbElemWithActions(neighbours);

  bool hadAction = _createdActions;
  _dataChange = Rec2DData::getNewDataChange();
  _ra->apply(_dataChange, _createdActions);
  if (_createdActions && !hadAction) {
    for (unsigned int i = 0; i < _createdActions->size(); ++i)
      (*_createdActions)[i]->addPointing();
  }
  _reward = Rec2DData::getGlobalQuality() - _globalQuality;

  if (_son[0]) _makeDevelopments(depth);
  else {
    std::vector<Rec2DAction*> actions;
    Recombine2D::incNumChange();
    Recombine2D::nextTreeActions(actions, neighbours, this);
    if (actions.size()) _createSons(actions, depth);
  }

  if (!Rec2DData::revertDataChange(_dataChange))
    Msg::Error(" 2 - don't reverted changes");
  else
    Recombine2D::incNumChange();
  _dataChange = NULL;
}

int Rec2DNode::_getNumSon() const
{
  int num = 0;
  for (int i = 0; i < REC2D_NUMB_SONS; ++i) {
    if (_son[i]) ++num;
  }
  return num;
}

void Rec2DNode::_delSons(bool alsoFirst)
{
  int beg = 1;
  if (alsoFirst) beg = 0;
  for (int i = beg; i < REC2D_NUMB_SONS; ++i) {
    if (_son[i]) _son[i]->_rmvFather(this);
    delete _son[i];
    _son[i] = NULL;
  }
  if (_createdActions) {
    for (unsigned int i = 0; i < _createdActions->size(); ++i) {
      (*_createdActions)[i]->rmvPointing();
      delete (*_createdActions)[i];
    }
    delete _createdActions;
  }
}

void Rec2DNode::_orderSons()
{
  bool one = false;
  double bestReward = .0;
  int k = -1;
  for (int i = 0; i < REC2D_NUMB_SONS; ++i) {
    if (_son[i]) {
      _son[++k] = _son[i];
      _son[i] = NULL;
      if (!one) {
        bestReward = _son[k]->_getBestSequenceReward();
        one = true;
      }
      if (bestReward < _son[k]->_getBestSequenceReward()) {
        bestReward = _son[k]->_getBestSequenceReward();
        Rec2DNode *tmp = _son[0];
        _son[0] = _son[k];
        _son[k] = tmp;
      }
    }
  }
}

bool Rec2DNode::_rmvSon(Rec2DNode *n)
{
  int i = -1;
  while (++i < REC2D_NUMB_SONS && _son[i] != n);

  if (i == REC2D_NUMB_SONS) {
    Msg::Info("im %d", this);
    for (int i = 0; i < REC2D_NUMB_SONS; ++i) {
      Msg::Info("son%d %d", i, _son[i]);
    }
    Msg::Error("son %d not found", n);
    __crash();
    return false;
  }
  else {
    _son[i] = NULL;
    _orderSons();
  }
  return true;
}

void Rec2DNode::_rmvFather(Rec2DNode *n)
{
  if (_father != n) {
    Msg::Error("is not my father");
    return;
  }
  _father = NULL;
}

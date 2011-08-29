// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (amjohnen@gmail.com) adapted from meshGFaceOptimize
//

#include "meshRecombine2D.h"
#include "GFace.h"

static int HORIZ = 25;

static int NUM_NEW = 0;
static int NEW_REC = 0;
static int NEW_NODE = 0;
static int NEW_QUAD = 0;

static int NUM_DEL = 0;
static int DEL_REC = 0;
static int DEL_NODE = 0;
static int DEL_QUAD = 0;

Recombine2D::Recombine2D(GFace *gf, int horizon)
    : _horizon(horizon), _gf(gf), _benef(.0), _applied(false)
{
  if (_horizon < 1) _horizon = 1;
  
  Msg::Info("Branching with horizon %d", _horizon = HORIZ);
  
  _haveParam = gf->geomType() != GEntity::DiscreteSurface || gf->getCompound();
  if(!_haveParam) {
    Msg::Warning("Surfaces must have prametrization in order to recombine triangles");
    //return;
    _haveParam=true;
  }
  
  e2t_cont adj;
  _buildEdgeToElement(gf->triangles, adj);
  
  std::map<MElement*, int> boundaryTriangle;
  std::pair<Set_Recomb::iterator, bool> ret;
  
  for (e2t_cont::iterator it = adj.begin(); it != adj.end(); ++it) {
    if (it->second.second) {
      RecombTriangle *rt = new RecombTriangle(it->first, it->second.first, it->second.second);
NUM_NEW++;
NEW_REC++;
      do {
        rt->touch();
        ret = _pairs.insert(rt);
      } while (ret.second == false);
      _possibleRecomb[it->second.first].insert(rt);
      _possibleRecomb[it->second.second].insert(rt);
    }
    else {
      if (boundaryTriangle.find(it->second.first) == boundaryTriangle.end())
        boundaryTriangle[it->second.first] = 1;
      else
        boundaryTriangle[it->second.first] = 2;
    }
  }
  
  std::map<MElement*, int>::iterator itt;
  
  for (itt = boundaryTriangle.begin(); itt != boundaryTriangle.end(); ++itt) {
    RecombTriangle *rt;
    if (itt->second == 1)
      rt = new RecombTriangle(itt->first, -100);
    else
      rt = new RecombTriangle(itt->first, -200);
NUM_NEW++;
NEW_REC++;
    
    ret = _pairs.insert(rt);
    while (!ret.second) {
      rt->touch();
      ret = _pairs.insert(rt);
    }
    _possibleRecomb[itt->first].insert(rt);
  }
  
  Msg::Info("poss %d", _possibleRecomb.size());
  Msg::Info("pairs %d", _pairs.size());
  Msg::Info("tri %d", gf->triangles.size());
  
  _recombine();
  
  Msg::Info("new %d = %d + %d + %d", NUM_NEW, NEW_REC, NEW_NODE, NEW_QUAD);
  Msg::Info("del %d = %d + %d + %d", NUM_DEL, DEL_REC, DEL_NODE, DEL_QUAD);
}

Recombine2D::~Recombine2D()
{
  if (!_applied)
  for (int i = 0; i < _quads.size(); i++) {
    delete _quads[i];
NUM_DEL++;
DEL_QUAD++;
  }
}

template <class E>
void Recombine2D::_buildEdgeToElement(std::vector<E*> &elements, e2t_cont &adj)
{
  for (unsigned int i = 0; i < elements.size(); i++) {
    E *el = elements[i];
    for (int j = 0; j < el->getNumEdges(); j++) {
      MEdge e = el->getEdge(j);
      e2t_cont::iterator it = adj.find(e);
      if (it == adj.end()) {
        std::pair<MElement*, MElement*> one = std::make_pair(el, (MElement*)0);
        adj[e] = one;
      }
      else
        it->second.second = el;
    }
  }
}

void Recombine2D::_recombine()
{
  int i = 0;
  while ((!_pairs.empty() || !_lastRecomb.empty()) && i < 1000) {
    Msg::Info("%d",i);
    Set_Recomb::iterator it = _bestNextRecombination();
    _benef += (*it)->getBenef();
    if ((*it)->isQuad())
      _quads.push_back((*it)->createQuad());
    else
      for (int i = 0; i < (*it)->numTriangles(); i++)
        _isolated.insert((*it)->triangle(i));
    _removeImpossible(it);
    i++;
  }
  Msg::Info("Done %d (%d)", i, _pairs.size());
}

Set_Recomb::iterator Recombine2D::_bestNextRecombination()
{
  if (!_lastRecomb.empty())
    return _lastRecomb.begin();
  
  int h = 0, nSkip = 0;
  double maxBenef = _horizon * -200.;
  
  
  Map_Tri_Node touched;
  std::vector<Node*> nodes(_horizon);
  Set_Recomb::iterator it = _pairs.begin(), itmax = _pairs.begin();
  
  bool end = false;
  
  int numb = 0;
  while (!end) {
    numb++;
    while (h < _horizon && it != _pairs.end()) {
      bool possible = true;
      
      Map_Tri_Node::iterator itm;
      for (int i = 0; i < (*it)->numTriangles(); i++) {
        itm = touched.find((*it)->triangle(i));
        if (itm != touched.end()) {
          itm->second->blocking(itm);
          possible = false;
        }
      }
        
      if (possible) {
        if (h == 0) nodes[h] = new Node(it, touched, nSkip);
        else        nodes[h] = new Node(it, touched, nSkip, nodes[h-1]->getTotBenef());
NUM_NEW++;
NEW_NODE++;
        h++;
        nSkip = 0;
      }
      else
        nSkip++;
      
      it++;
    }
    
    if (nodes[--h]->getTotBenef() > maxBenef) {
      maxBenef = nodes[h]->getTotBenef();
      itmax = nodes[0]->getItRecomb();
    }
    
    /*nSkip = 0;
    while (h >= 0 && nSkip < 2) {
      nodes[h]->erase();
      nSkip += nodes[h--]->getnSkip();
    
    if (h == _horizon - 2 && nodes[h]->getnSkip() >= 3) nodes[h--]->erase(); //probleme si h=-1
    while (h >= 0 &&
           nodes[h]->beSkipped() &&
           nodes[h]->getnSkip() >= 2 * (_horizon - h))
      nodes[h--]->erase();*/
    delete nodes[h];
NUM_DEL++;
DEL_NODE++;
    while (--h >= 0 &&
           (nodes[h]->isBetter() ||
            nodes[h]->getnSkip() >= 2 * (_horizon - h))){
NUM_DEL++;
DEL_NODE++;
      delete nodes[h];
    }
    
    if (h < 0) end = true;
    else {
      it = ++nodes[h]->getItRecomb();
      nSkip = nodes[h]->getnSkip() + 1;
      delete nodes[h];
NUM_DEL++;
DEL_NODE++;
    }
  }
  
  Msg::Info("num test %d", numb);
    
  return itmax;
}

void Recombine2D::_removeImpossible(Set_Recomb::iterator it)
{
  std::vector<MElement *> t;
  (*it)->triangles(t);
  
  Map_Tri_Recomb::iterator itm;
  std::set<RecombTriangle*>::iterator itrt;
  
  for (int i = 0; i < t.size(); i++) {
    
    itm = _possibleRecomb.find(t[i]);
    if (itm == _possibleRecomb.end())
      Msg::Info("not _possibleRecomb");
    else {
      itrt = itm->second.begin();
      while (itrt != itm->second.end()) { // loop over unusable RecombTriangle
        if (*itrt != *it)
          _rmRT(*itrt, t[i]);
        itrt++;
      }
    }
    _possibleRecomb.erase(itm);
  }
  
  RecombTriangle *rt = *it;
  if (!_lastRecomb.erase(*it))
    _pairs.erase(it);
  delete rt;
NUM_DEL++;
DEL_REC++;
}

void Recombine2D::_rmRT(RecombTriangle *rt, MElement *el)
{
  MElement *tri;
  Map_Tri_Recomb::iterator itmtri;
  
  for (int i = 0; i < rt->numTriangles(); i++)
  if ((tri = rt->triangle(i)) != el) {
    itmtri = _possibleRecomb.find(tri);
    if (itmtri == _possibleRecomb.end())
      Msg::Info("-not _possibleRecomb");
    else {
    itmtri->second.erase(rt);
    switch (itmtri->second.size()) {
      case 1 :
        _pairs.erase(*itmtri->second.begin());
        _lastRecomb.insert(*itmtri->second.begin());
        break;
      case 0 :
        _isolated.insert(tri);
        _possibleRecomb.erase(itmtri);
      default :;
    }
    }
  }
  _pairs.erase(rt);
  _lastRecomb.erase(rt);
  delete rt;
NUM_DEL++;
DEL_REC++;
}

int Recombine2D::apply()
{
  if (!_haveParam && !_applied) return 0;
  
  std::vector<MTriangle*> triangles2;
  for (int i = 0; i < _gf->triangles.size(); i++) {
    if (_isolated.find(_gf->triangles[i]) == _isolated.end())
      delete _gf->triangles[i];
    else
      triangles2.push_back(_gf->triangles[i]);
  }
  _gf->triangles = triangles2;
  _gf->quadrangles = _quads;
  
  _applied = true;
  return 1;
}

RecombTriangle::RecombTriangle(const MEdge &me, MElement *t1, MElement *t2)
    : _formingQuad(true)
{
  _t.push_back(t1);
  _t.push_back(t2);
  _n1 = me.getVertex(0);
  _n2 = me.getVertex(1);

  if(t1->getVertex(0) != _n1 && t1->getVertex(0) != _n2) _n3 = t1->getVertex(0);
  else if(t1->getVertex(1) != _n1 && t1->getVertex(1) != _n2) _n3 = t1->getVertex(1);
  else if(t1->getVertex(2) != _n1 && t1->getVertex(2) != _n2) _n3 = t1->getVertex(2);
  if(t2->getVertex(0) != _n1 && t2->getVertex(0) != _n2) _n4 = t2->getVertex(0);
  else if(t2->getVertex(1) != _n1 && t2->getVertex(1) != _n2) _n4 = t2->getVertex(1);
  else if(t2->getVertex(2) != _n1 && t2->getVertex(2) != _n2) _n4 = t2->getVertex(2);

  double a1 = 180 * angle3Vertices(_n1, _n4, _n2) / M_PI;
  double a2 = 180 * angle3Vertices(_n4, _n2, _n3) / M_PI;
  double a3 = 180 * angle3Vertices(_n2, _n3, _n1) / M_PI;
  double a4 = 180 * angle3Vertices(_n3, _n1, _n4) / M_PI;
  _angle = fabs(90. - a1);
  _angle = std::max(fabs(90. - a2), _angle);
  _angle = std::max(fabs(90. - a3), _angle);
  _angle = std::max(fabs(90. - a4), _angle);
  
  _benefit = std::max(1. - _angle/90., .0);
  //_benefit = compute_alignment(me,t1,t2);
      
      //cost_alignment = Temporary::compute_alignment(me,_t1,_t2); //addition for class Temporary
      //total_cost = Temporary::compute_total_cost(cost_quality,cost_alignment); //addition for class Temporary
      //total_cost = 100.0*cost_quality; //addition for class Temporary
}

RecombTriangle::RecombTriangle(MElement *t, double a)
    : _benefit(a), _formingQuad(false) {
  _t.push_back(t);
}

double RecombTriangle::touch()
{
  double prec = 1e-10;
  
  double a = (double)(rand() - RAND_MAX / 2) / RAND_MAX * prec;
  _benefit += a;
  return a;
}

MQuadrangle *RecombTriangle::createQuad() const
{
NUM_NEW++;
NEW_QUAD++;
  switch (_t.size()) {
    case 1 :
    {
      Msg::Error("Can't make a quad from only one triangle");
      return new MQuadrangle(_t[0]->getVertex(0),
                             _t[0]->getVertex(1),
                             _t[0]->getVertex(2),
                             _t[0]->getVertex(0));
    }
    case 2 :
    {
      int orientation = 0;
      for (int i = 0; i < 3; i++) {
        if (_t[0]->getVertex(i) == _n1) {
          if (_t[0]->getVertex((i + 1) % 3) == _n2)
            orientation = 1;
          else
            orientation = -1;
          break;
        }
      }
      if (orientation < 0)
        return new MQuadrangle(_n1, _n3, _n2, _n4);
      else
        return new MQuadrangle(_n1, _n4, _n2, _n3);
    }
    default :
    {
      Msg::Warning("Quad creation not yet implemented for more than two triangles");
      return new MQuadrangle(_n1, _n2, _n3, _n4);
    }
  }
}

double RecombTriangle::compute_alignment(const MEdge &edge, MElement *e1, MElement* e2)
{
  return 1 - Temporary::compute_alignment(edge, e1, e2);
}

bool RecombTriangle::operator<(const RecombTriangle &other) const
{
  return _benefit < other._benefit;
}

bool lessRecombTri::operator()(RecombTriangle *rt1, RecombTriangle *rt2) const
{
  return *rt2 < *rt1;
}

Node::Node(Set_Recomb::iterator it,
           Map_Tri_Node &touched,
           int nskp, double ben) : _nskip(nskp), _recomb(it)
{
  _benef = (*it)->getBenef();
  _totBenef = ben + _benef;
  for (int i = 0; i < (*it)->numTriangles(); i++)
    _vit.push_back(touched.insert( touched.begin(), std::make_pair((*it)->triangle(i), this) ));
  _touch = &touched;
}

Node::~Node()
{
  for (int i = 0; i < _vit.size(); i++)
    _touch->erase(_vit[i]);
}

void Node::erase()
{
  for (int i = 0; i < _vit.size(); i++)
    _touch->erase(_vit[i]);
}

void Node::blocking(const Map_Tri_Node::iterator &it)
{
  for (int i = 0; i < _vit.size(); i++) {
    if (it == _vit[i]) {
      _blocking.insert(i);
    }
  }
}

//

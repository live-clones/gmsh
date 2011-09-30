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

static int HORIZ = 20;

double **Rec2d_vertex::_Vvalues = NULL;
double **Rec2d_vertex::_Vbenefs = NULL;
int TrianglesUnion::_RECOMPUTE = 0;
int TrianglesUnion::_NumEdge = 0;
int TrianglesUnion::_NumVert = 0;
double TrianglesUnion::_ValEdge = .0;
double TrianglesUnion::_ValVert = .0;

Recombine2D::Recombine2D(GFace *gf)
: _horizon(0), _gf(gf), _benef(.0), _applied(true)
{
  Msg::Warning("[meshRecombine2D] Alignement computation ok uniquely for xy or yz plane mesh !");
  
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
    if ((*itvert).second.size() == 4)
      fourTri.push_back(itvert);
    Rec2d_vertex *n = new Rec2d_vertex((*itvert).first, (*itvert).second, mapCornerVert);
    itV2N = mapV2N.insert(itV2N, std::make_pair((*itvert).first,n));
    TrianglesUnion::_NumVert++;
    TrianglesUnion::_ValVert += n->getReward();
  }
  
  // store mesh size and parametric coordinates for better performance
  std::map<MVertex*,double*> mapV2LcUV;
  
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
      std::list<MTriangle*>::iterator itTri = (*(*it4)).second.begin();
      for (; itTri != (*(*it4)).second.end(); itTri++) {
        MVertex *vt;
        for (int i = 0; i < 3; i++) {
          msetEdge.insert((*itTri)->getEdge(i));
          vt = (*itTri)->getVertex(i);
          if (vt != (*(*it4)).first)
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
      listVert.push_back(mapV2N[(*(*it4)).first]);
    }
    Msg::Info("%d",++j);
    _setQuads.push_back(new TrianglesUnion(gf, (*(*it4)).second, listEmbEdge, listVert, mapV2LcUV));
  }
  
  // Create 'TrianglesUnion' for pattern of 2 triangles
/*
  +---+
  |\  |
  | \ |
  |  \|
  +---+
*/
  /*std::map<MEdge, std::list<MTriangle*> >::iterator itedge = mapEdge.begin();
  for (; itedge != mapEdge.end(); itedge++) {
    if ((*itedge).second.size() == 2) {
      std::list<MEdge> listEmbEdge;
      listEmbEdge.push_back((*itedge).first);
      std::list<Rec2d_vertex*> listVert;
      listVert.push_back(mapV2N[(*itedge).first.getVertex(0)]);
      listVert.push_back(mapV2N[(*itedge).first.getVertex(1)]);
      TrianglesUnion *tu = new TrianglesUnion(gf, (*itedge).second, listEmbEdge, listVert, mapV2LcUV);
      _setQuads.push_back(tu);
      TrianglesUnion::_NumEdge++;
      TrianglesUnion::_ValEdge += tu->getEdgeValue();
    }
    else
      Msg::Info("[bord] %d", (*itedge).second.size());
  }
  _setQuads.sort(lessTriUnion());
  
  _recombine(true);
  _applied = true;*/
}


void Recombine2D::_recombine(bool a)
{ 
  int i = 0;
  while (!_setQuads.empty()) {
    Msg::Info("%d",i);
    std::list<TrianglesUnion*>::iterator it = _setQuads.begin();
    
    (*it)->select();
    
    _quads.push_back((*it)->createQuad());
    
    _removeImpossible(it);
    
    _setQuads.sort(lessTriUnion());
    i++;
  }
  Msg::Info("Done %d (%d)", i, _pairs.size());
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
  v2 = listBoundEdge.begin()->getMinVertex();
  std::list<MEdge>::iterator it = listBoundEdge.begin();
  for (it++; it != listBoundEdge.end(); it++) {
    if (v2 == (*it).getMinVertex()) {
      v3 = (*it).getMaxVertex();
      listBoundEdge.erase(it);
      break;
    }
    if (v2 == (*it).getMaxVertex()) {
      v3 = (*it).getMinVertex();
      listBoundEdge.erase(it);
      break;
    }
  }
  for (it = listBoundEdge.begin(); it != listBoundEdge.end(); it++) {
    if (v3 == (*it).getMinVertex()) {
      v4 = (*it).getMaxVertex();
      break;
    }
    if (v3 == (*it).getMaxVertex()) {
      v4 = (*it).getMinVertex();
      break;
    }
  }
  
  return new MQuadrangle(v1, v2, v3, v4);
}


int Recombine2D::apply(bool a)
{
  if (!_haveParam || _applied) return 0;
  
  std::vector<MTriangle*> triangles2;
  for (int i = 0; i < _gf->triangles.size(); i++) {
    delete _gf->triangles[i];
  }
  _gf->triangles = triangles2;
  _gf->quadrangles = _quads;
  
  _applied = true;
  return 1;
}

void Recombine2D::_removeImpossible(std::list<TrianglesUnion*>::iterator it)
{
  std::set<MTriangle *> touched;
  
  for (int i = 0; i < (*it)->getNumTriangles(); i++) {
    touched.insert((*it)->getTriangle(i));
  }
  
  for (it = _setQuads.begin(); it != _setQuads.end();) {
    bool b = false;
    for (int i = 0; i < (*it)->getNumTriangles(); i++) {
      if (touched.find((*it)->getTriangle(i)) != touched.end())
        b = true;
    }
    if (b)
      _setQuads.erase(it++);
    else
      it++;
  }
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
      _angle = _computeAngle(v, setTri, (*it).second);
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
    _Vvalues[0] = new double[nE]; //AVERIFIER SI CA MARCHE
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
      firstDer1 = vectub;
    else if (normub > prec * normlb)
      firstDer1 = vectlb;
    else {
      Msg::Warning("[meshRecombine2D] Bad precision, returning pi/2");
      return M_PI / 2.;
    }
    if (k == 0)
      firstDer0 = firstDer1;
  }
  
  Msg::Info("-- %lf, %lf, %lf", norm(firstDer0), norm(firstDer1), dot(firstDer0, firstDer1));
  double n = 1 / norm(firstDer0);
  firstDer0 = firstDer0 * n;
  n = 1 / norm(firstDer1);
  firstDer1 = firstDer1 * n;
  Msg::Info("--Angles : %lf, %lf, %lf", norm(firstDer0), norm(firstDer1), dot(firstDer0, firstDer1));
  
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
  
  Msg::Info("Angles : %lf, %lf, %lf", angle1, angleMesh, angle2);
  
  return M_PI / 2.;
  
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
    if (n > 0)
      return _Vbenefs[_onWhat][_numEl-1];
    else
      return - _Vbenefs[_onWhat][_numEl-2];
  }
  else
    return fabs(2./M_PI*_angle/_numEl - 1.) - fabs(2./M_PI*_angle/(_numEl + n) - 1.);
}


TrianglesUnion::TrianglesUnion(GFace *gf,
                               std::list<MTriangle*> &t,
                               std::list<MEdge> &e,
                               std::list<Rec2d_vertex*> &v,
                               std::map<MVertex*,double*> &v2lcUV)
{
  _numTri = t.size();
  _numEmbEdge = e.size();
  _numBoundVert = v.size() == 2 ? 2 : 4;
  _numEmbVert = v.size() - _numBoundVert;
  _globValIfExecuted = _embEdgeValue = _embVertValue = .0;
  
  _triangles = new MTriangle*[_numTri];
  std::list<MTriangle*>::iterator itt = t.begin();
  for (int k = 0; itt != t.end(); itt++, k++) {
    _triangles[k] = *itt;
  }
  
  std::list<MEdge>::iterator ite = e.begin();
  for (; ite != e.end(); ite++) {
    double sumlc = .0, u[2], v[2];
    MVertex *vert[2];
    for (int i = 0; i < 2; i++) {
      vert[i] = (*ite).getVertex(i);
      std::map<MVertex*,double*>::iterator itlc;
      if ((itlc = v2lcUV.find(vert[i])) == v2lcUV.end()) {
        double *a = new double[3];
        gf->XYZtoUV(vert[i]->x(), vert[i]->y(), vert[i]->z(), a[1], a[2], 1.);
        sumlc += a[0] = BGM_MeshSize(gf, a[1], a[2], vert[i]->x(), vert[i]->y(), vert[i]->z());
        u[i] = a[1];
        v[i] = a[2];
        v2lcUV[vert[i]] = a;
      }
      else {
        sumlc += (*itlc).second[0];
        u[i] = (*itlc).second[1];
        v[i] = (*itlc).second[2];
      }
    }

    double length = _computeEdgeLength(gf, vert, u, v, 0);
    _embEdgeValue += length / sumlc * (1 + _computeAlignment(*ite, t));
    Msg::Info("Edge a : %lf/%lf = %lf <-> %lf", length, sumlc / 2, 2 * length / sumlc, _computeAlignment(*ite, t));
  }
  
  _vertices = new Rec2d_vertex*[_numBoundVert];
  std::list<Rec2d_vertex*>::iterator itv = v.begin();
  for (int k = 0; itv != v.end() && k < _numBoundVert; itv++, k++) {
    _globValIfExecuted += (*itv)->getReward(-1);
    _vertices[k] = *itv;
  }
  for (_numEmbVert = 0; itv != v.end(); itv++, _numEmbVert++)
    _embVertValue += (*itv)->getReward();
  
  _computation = _RECOMPUTE - 1;
  _update();
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
  _globValIfExecuted = alpha * beta;
  
  _computation = _RECOMPUTE;
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

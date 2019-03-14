// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <queue>
#include "GmshMessage.h"
#include "discreteFace.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "Context.h"
#include "MPoint.h"
#include "MElementOctree.h"
#include "Octree.h"

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = CreateSurface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

void discreteFace::setBoundEdges(const std::vector<int> &tagEdges)
{
  for(std::size_t i = 0; i != tagEdges.size(); i++) {
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge) {
      l_edges.push_back(ge);
      l_dirs.push_back(1);
      ge->addFace(this);
    }
    else {
      Msg::Error("Unknown curve %d in discrete surface %d", tagEdges[i], tag());
    }
  }
}

void discreteFace::setBoundEdges(const std::vector<int> &tagEdges,
                                 const std::vector<int> &signEdges)
{
  if(signEdges.size() != tagEdges.size()) {
    Msg::Error("Wrong number of edge signs in discrete surface %d", tag());
    setBoundEdges(tagEdges);
  }
  for(std::vector<int>::size_type i = 0; i != tagEdges.size(); i++) {
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge) {
      l_edges.push_back(ge);
      l_dirs.push_back(signEdges[i]);
      ge->addFace(this);
    }
    else {
      Msg::Error("Unknown curve %d in discrete surface %d", tagEdges[i], tag());
    }
  }
}

#if defined(HAVE_HXT)

static void splitDiscreteEdge(discreteEdge *de, MVertex *v, GVertex *gv,
                              int &TAG)
{
  GVertex *gv0 = de->getBeginVertex();
  GVertex *gv1 = de->getEndVertex();

  if(v != gv->mesh_vertices[0]) {
    Msg::Error("Wrong vertex for splitting discrete curve");
    return;
  }
  discreteEdge *de_new[2];

  de_new[0] = new discreteEdge(de->model(), ++TAG, gv0, gv);
  de_new[1] = new discreteEdge(de->model(), ++TAG, gv, gv1);

  de->setSplit(de_new[0], de_new[1]);

  int current = 0;
  de_new[current]->lines.push_back(de->lines[0]);
  for(size_t i = 0; i < de->mesh_vertices.size(); i++) {
    if(de->mesh_vertices[i] == v)
      current++;
    else {
      de_new[current]->mesh_vertices.push_back(de->mesh_vertices[i]);
      de->mesh_vertices[i]->setEntity(de_new[current]);
    }
    de_new[current]->lines.push_back(de->lines[i + 1]);
  }
  de->lines.clear();
  de->mesh_vertices.clear();

  std::vector<GFace *> f = de->faces();
  for(size_t i = 0; i < f.size(); i++) {
    std::vector<GEdge *> new_eds, old_eds;
    old_eds = f[i]->edges();
    discreteFace *df = dynamic_cast<discreteFace *>(f[i]);
    if(!df) {
      Msg::Error(
        "A discrete edge is adjacent to a face that is not a discrete face - "
        "cannot remesh");
      return;
    }
    for(size_t j = 0; j < old_eds.size(); j++) {
      if(old_eds[j] == de) {
        new_eds.push_back(de_new[0]);
        new_eds.push_back(de_new[1]);
        new_eds[0]->addFace(f[i]);
        new_eds[1]->addFace(f[i]);
      }
      else
        new_eds.push_back(old_eds[j]);
    }
    f[i]->set(new_eds);
  }
  de->model()->add(de_new[0]);
  de->model()->add(de_new[1]);
  de->model()->remove(de);
}

#endif

int discreteFace::trianglePosition(double par1, double par2, double &u,
                                   double &v) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0;

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e =
    _parametrizations[_currentParametrization].oct->find(par1, par2, 0.0);
  if(!e) return -1;
  e->xyz2uvw(xy, uv);
  int position =
    (int)((MTriangle *)e - &_parametrizations[_currentParametrization].t2d[0]);
  u = uv[0];
  v = uv[1];
  return position;
#else
  return 0;
#endif
}

GPoint discreteFace::point(double par1, double par2) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0;

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e =
    _parametrizations[_currentParametrization].oct->find(par1, par2, 0.0);
  if(!e) {
    GPoint gp = GPoint(1.e21, 1.e21, 1.e21, this, xy);
    gp.setNoSuccess();
    return gp;
  }
  e->xyz2uvw(xy, uv);
  int position =
    (int)((MTriangle *)e - &_parametrizations[_currentParametrization].t2d[0]);
  const MTriangle &t3d =
    _parametrizations[_currentParametrization].t3d[position];

  double X = 0, Y = 0, Z = 0;
  double eval[3] = {1. - uv[0] - uv[1], uv[0], uv[1]};

  for(int io = 0; io < 3; io++) {
    X += t3d.getVertex(io)->x() * eval[io];
    Y += t3d.getVertex(io)->y() * eval[io];
    Z += t3d.getVertex(io)->z() * eval[io];
  }
  return GPoint(X, Y, Z, this, xy);
#else
  Msg::Error("Cannot evaluate point on discrete surface without HXT");
  return GPoint();
#endif
}

class dfWrapper {
public:
  SPoint3 _p;
  double _distance;
  SPoint3 _closestPoint;
  MTriangle *_t3d, *_t2d;
  dfWrapper(const SPoint3 &p) : _p(p), _distance(1.e22), _t3d(NULL), _t2d(NULL)
  {
  }
};

#if defined(HAVE_HXT)

static SVector3 NORMAL_(const MTriangle &t3d)
{
  SVector3 v31(t3d.getVertex(2)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(2)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(2)->z() - t3d.getVertex(0)->z());
  SVector3 v21(t3d.getVertex(1)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(1)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(1)->z() - t3d.getVertex(0)->z());
  SVector3 n = crossprod(v31, v21);

  n.normalize();
  return n;
}

#endif

bool discreteFace_rtree_callback(std::pair<MTriangle *, MTriangle *> *t,
                                 void *w)
{
  dfWrapper *wrapper = static_cast<dfWrapper *>(w);

  SPoint3 closePt;
  double d;
  //  printf("distance %p %p\n", t->first, t->second);
  signedDistancePointTriangle(
    SPoint3(t->first->getVertex(0)->x(), t->first->getVertex(0)->y(),
            t->first->getVertex(0)->z()),
    SPoint3(t->first->getVertex(1)->x(), t->first->getVertex(1)->y(),
            t->first->getVertex(1)->z()),
    SPoint3(t->first->getVertex(2)->x(), t->first->getVertex(2)->y(),
            t->first->getVertex(2)->z()),
    wrapper->_p, d, closePt);
  //  printf("%g\n",d);
  if(fabs(d) < wrapper->_distance) {
    wrapper->_distance = fabs(d);
    wrapper->_closestPoint = closePt;
    wrapper->_t3d = t->first;
    wrapper->_t2d = t->second;
  }

  return true;
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint, double maxDistance,
                                  SVector3 *normal) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return GPoint();

  dfWrapper wrapper(queryPoint);
  do {
    wrapper._distance = 1.e22;
    double MIN[3] = {queryPoint.x() - maxDistance, queryPoint.y() - maxDistance,
                     queryPoint.z() - maxDistance};
    double MAX[3] = {queryPoint.x() + maxDistance, queryPoint.y() + maxDistance,
                     queryPoint.z() + maxDistance};
    _parametrizations[_currentParametrization].rtree3d.Search(
      MIN, MAX, discreteFace_rtree_callback, &wrapper);
    maxDistance *= 2.0;
  } while(!wrapper._t3d);

  if(normal) {
    SVector3 t1(
      wrapper._t3d->getVertex(1)->x() - wrapper._t3d->getVertex(0)->x(),
      wrapper._t3d->getVertex(1)->y() - wrapper._t3d->getVertex(0)->y(),
      wrapper._t3d->getVertex(1)->z() - wrapper._t3d->getVertex(0)->z());
    SVector3 t2(
      wrapper._t3d->getVertex(2)->x() - wrapper._t3d->getVertex(0)->x(),
      wrapper._t3d->getVertex(2)->y() - wrapper._t3d->getVertex(0)->y(),
      wrapper._t3d->getVertex(2)->z() - wrapper._t3d->getVertex(0)->z());
    *normal = crossprod(t1, t2);
    normal->normalize();
  }

  double xyz[3] = {wrapper._closestPoint.x(), wrapper._closestPoint.y(),
                   wrapper._closestPoint.z()};
  double uvw[3];
  wrapper._t3d->xyz2uvw(xyz, uvw);
  const MVertex *v0 = wrapper._t2d->getVertex(0);
  const MVertex *v1 = wrapper._t2d->getVertex(1);
  const MVertex *v2 = wrapper._t2d->getVertex(2);
  double U = 1 - uvw[0] - uvw[1];
  double V = uvw[0];
  double W = uvw[1];
  SPoint2 pp(U * v0->x() + V * v1->x() + W * v2->x(),
             U * v0->y() + V * v1->y() + W * v2->y());
  return GPoint(xyz[0], xyz[1], xyz[2], this, pp);
#else
  return GPoint();
#endif
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint,
                                  const double initialGuess[2]) const
{
#if defined(HAVE_HXT)
  return closestPoint(queryPoint, 0.0001);
#else
  Msg::Error("Cannot evaluate closest point on discrete surface without HXT");
  return GPoint();
#endif
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
#if defined(HAVE_HXT)
  GPoint gp = closestPoint(p, 0.0001);
  return SPoint2(gp.u(), gp.v());
#else
  Msg::Error("Cannot evaluate par from point on discrete surface without HXT");
  return SPoint2();
#endif
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return SVector3();

  MElement *e = _parametrizations[_currentParametrization].oct->find(
    param.x(), param.y(), 0.0);
  if(!e) {
    Msg::Warning("Triangle not found at uv=(%g,%g) on discrete surface %d",
                 param.x(), param.y(), tag());
    return SVector3(0, 0, 1);
  }
  int position =
    (int)((MTriangle *)e - &_parametrizations[_currentParametrization].t2d[0]);
  const MTriangle &t3d =
    _parametrizations[_currentParametrization].t3d[position];
  return NORMAL_(t3d);
#else
  Msg::Error("Cannot evaluate normal on discrete surface without HXT");
  return SVector3();
#endif
}

double discreteFace::curvatureMax(const SPoint2 &param) const { return false; }

double discreteFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                                SVector3 &dirMin, double &curvMax,
                                double &curvMin) const
{
  return false;
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty())
    return Pair<SVector3, SVector3>(SVector3(), SVector3());

  MElement *e = _parametrizations[_currentParametrization].oct->find(
    param.x(), param.y(), 0.0);
  if(!e) {
    Msg::Warning("Triangle not found for first derivative at uv=(%g,%g) on "
                 "discrete surface %d",
                 param.x(), param.y(), tag());
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));
  }

  int position =
    (int)((MTriangle *)e - &_parametrizations[_currentParametrization].t2d[0]);

  const MTriangle &t3d =
    _parametrizations[_currentParametrization].t3d[position];
  const MVertex *v1 = t3d.getVertex(0);
  const MVertex *v2 = t3d.getVertex(1);
  const MVertex *v3 = t3d.getVertex(2);

  double M3D[3][2] = {{v2->x() - v1->x(), v3->x() - v1->x()},
                      {v2->y() - v1->y(), v3->y() - v1->y()},
                      {v2->z() - v1->z(), v3->z() - v1->z()}};
  v1 = e->getVertex(0);
  v2 = e->getVertex(1);
  v3 = e->getVertex(2);

  double M2D[2][2] = {{(v3->y() - v1->y()), -(v3->x() - v1->x())},
                      {-(v2->y() - v1->y()), (v2->x() - v1->x())}};

  double det = 1. / (M2D[0][0] * M2D[1][1] - M2D[1][0] * M2D[0][1]);

  //  printf("det = %12.5E\n",det);

  double dxdu[3][2];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 2; j++) {
      dxdu[i][j] = 0.;
      for(int k = 0; k < 2; k++) { dxdu[i][j] += det * M3D[i][k] * M2D[k][j]; }
    }
  }

  return Pair<SVector3, SVector3>(SVector3(dxdu[0][0], dxdu[1][0], dxdu[2][0]),
                                  SVector3(dxdu[0][1], dxdu[1][1], dxdu[2][1]));
#endif
  Msg::Error(
    "Cannot evaluate first derivative on discrete surface without HXT");
  return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 0, 0));
}

void discreteFace::secondDer(const SPoint2 &param, SVector3 &dudu,
                             SVector3 &dvdv, SVector3 &dudv) const
{
  return;
}

void discreteFace::createGeometry()
{
#if defined(HAVE_HXT)
  if(_parametrizations.size()) return;
  if(!_checkAndFixOrientation()) return;
  HXTStatus s = _reparametrizeThroughHxt();
  if(s != HXT_STATUS_OK)
    Msg::Error("Could not create geometry of discrete surface %d", tag());
#endif
}

bool discreteFace::_checkAndFixOrientation()
{
  if(triangles.empty()) return false;

  // first of all, all the triangles have to be oriented in the same way

  // edge to 1 or 2 triangle(s)
  std::map<MEdge, std::vector<MElement *>, Less_Edge> ed2tri;

  for(std::size_t i = 0; i < triangles.size(); ++i) {
    MElement *e = triangles[i];
    for(int j = 0; j < e->getNumEdges(); j++) {
      MEdge ed = e->getEdge(j);
      ed2tri[ed].push_back(e);
    }
  }

  // element to its neighbors
  std::map<MElement *, std::vector<MElement *> > neighbors;
  for(std::size_t i = 0; i < triangles.size(); ++i) {
    MElement *e = triangles[i];
    for(int j = 0; j < e->getNumEdges(); j++) {
      // #improveme: efficiency could be improved by setting neighbors mutually
      std::vector<MElement *> my_mt = ed2tri[e->getEdge(j)];
      if(my_mt.size() > 1) { // my_mt.size() = {1;2}
        MElement *neighTri = my_mt[0] == e ? my_mt[1] : my_mt[0];
        neighbors[e].push_back(neighTri);
      }
    }
  }

  // element for reference orientation
  std::queue<MElement *> checkList;
  // corresponding neighbor element to be checked for its orientation
  std::queue<std::vector<MElement *> > checkLists;
  // todo list
  std::queue<MElement *> my_todo;
  // help to complete todo list
  std::map<MElement *, bool> check_todo;

  my_todo.push(triangles[0]);

  check_todo[triangles[0]] = true;
  while(!my_todo.empty()) {
    MElement *myMT = my_todo.front();
    my_todo.pop();

    std::vector<MElement *> myV = neighbors[myMT];
    std::vector<MElement *> myInsertion;

    checkList.push(myMT);

    for(std::size_t i = 0; i < myV.size(); ++i) {
      if(check_todo.find(myV[i]) == check_todo.end()) {
        myInsertion.push_back(myV[i]);
        check_todo[myV[i]] = true;
        my_todo.push(myV[i]);
      }
    }
    checkLists.push(myInsertion);
  }

  while(!checkList.empty() && !checkLists.empty()) {
    MElement *current = checkList.front();
    checkList.pop();
    std::vector<MElement *> neigs = checkLists.front();
    checkLists.pop();
    for(std::size_t i = 0; i < neigs.size(); i++) {
      bool myCond = false;
      for(std::size_t k = 0; k < 3; k++) {
        for(std::size_t j = 0; j < 3; j++) {
          if(current->getVertex(k) == neigs[i]->getVertex(j)) {
            myCond = true;
            if(!(current->getVertex(k != 2 ? k + 1 : 0) ==
                   neigs[i]->getVertex(j != 0 ? j - 1 : 2) ||
                 current->getVertex(k != 0 ? k - 1 : 2) ==
                   neigs[i]->getVertex(j != 2 ? j + 1 : 0))) {
              neigs[i]->reverse();
            }
            break;
          }
        }
        if(myCond) break;
      }
    }
  }
  return true;
}

void discreteFace::mesh(bool verbose)
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return;

  std::vector<MTriangle *> _t;
  std::vector<MVertex *> _v;
  std::vector<GEdge *> const tmp = l_edges;
  int _tagtemp = tag();

  Msg::Info("Meshing discrete surface %d: the atlas contains %d map%s", tag(),
            _parametrizations.size(),
            (_parametrizations.size() > 1) ? "s" : "");

  for(size_t i = 0; i < _parametrizations.size(); i++) {
    // setTag(i);
    l_edges.clear();
    for(size_t j = 0; j < _parametrizations[i].bnd.size(); j++) {
      if(_parametrizations[i].bnd[j]->geomType() == DiscreteCurve)
        ((discreteEdge *)_parametrizations[i].bnd[j])->getSplit(l_edges);
      else
        l_edges.push_back(_parametrizations[i].bnd[j]);
    }

    embedded_edges.clear();
    embedded_edges.insert(embedded_edges.begin(),
                          _parametrizations[i].emb.begin(),
                          _parametrizations[i].emb.end());
    _currentParametrization = i;
    triangles.clear();
    mesh_vertices.clear();
    GFace::mesh(verbose);
    _t.insert(_t.begin(), triangles.begin(), triangles.end());
    _v.insert(_v.begin(), mesh_vertices.begin(), mesh_vertices.end());
  }
  setTag(_tagtemp);
  triangles = _t;
  mesh_vertices = _v;
  l_edges = tmp;
  embedded_edges.clear();
  meshStatistics.status = GFace::DONE;
#else
  Msg::Error("Cannot mesh discrete surface without HXT");
#endif
}

#if defined(HAVE_HXT)

static HXTStatus gmsh2hxt(GFace *gf, HXTMesh **pm,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *m;
  HXT_CHECK(hxtMeshCreate(context, &m));
  std::set<MVertex *> all;
  for(size_t i = 0; i < gf->triangles.size(); i++) {
    all.insert(gf->triangles[i]->getVertex(0));
    all.insert(gf->triangles[i]->getVertex(1));
    all.insert(gf->triangles[i]->getVertex(2));
  }
  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->triangles.num = m->triangles.size = gf->triangles.size();
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < gf->triangles.size(); i++) {
    m->triangles.node[3 * i + 0] = v2c[gf->triangles[i]->getVertex(0)];
    m->triangles.node[3 * i + 1] = v2c[gf->triangles[i]->getVertex(1)];
    m->triangles.node[3 * i + 2] = v2c[gf->triangles[i]->getVertex(2)];
    m->triangles.colors[i] = gf->tag();
  }

  m->lines.num = m->lines.size = 0;

  *pm = m;
  return HXT_STATUS_OK;
}

#endif

GPoint discreteFace::intersectionWithCircle(const SVector3 &n1,
                                            const SVector3 &n2,
                                            const SVector3 &p, const double &R,
                                            double uv[2])
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return GPoint();

  MTriangle *t2d =
    (MTriangle *)_parametrizations[_currentParametrization].oct->find(
      uv[0], uv[1], 0.0);
  MTriangle *t3d = NULL;
  if(t2d) {
    int position =
      (int)(t2d - &_parametrizations[_currentParametrization].t2d[0]);
    t3d = &_parametrizations[_currentParametrization].t3d[position];
  }

  SVector3 n = crossprod(n1, n2);
  n.normalize();

  int N = _parametrizations[_currentParametrization].t3d.size();
  int start = 0;
  if(t2d) start = -1;
  for(int i = start; i < N; i++) {
    if(i >= 0) {
      t2d = &_parametrizations[_currentParametrization].t2d[i];
      t3d = &_parametrizations[_currentParametrization].t3d[i];
    }
    SVector3 v0(t3d->getVertex(0)->x(), t3d->getVertex(0)->y(),
                t3d->getVertex(0)->z());
    SVector3 v1(t3d->getVertex(1)->x(), t3d->getVertex(1)->y(),
                t3d->getVertex(1)->z());
    SVector3 v2(t3d->getVertex(2)->x(), t3d->getVertex(2)->y(),
                t3d->getVertex(2)->z());
    SVector3 v0_2d(t2d->getVertex(0)->x(), t2d->getVertex(0)->y(),
                   t2d->getVertex(0)->z());
    SVector3 v1_2d(t2d->getVertex(1)->x(), t2d->getVertex(1)->y(),
                   t2d->getVertex(1)->z());
    SVector3 v2_2d(t2d->getVertex(2)->x(), t2d->getVertex(2)->y(),
                   t2d->getVertex(2)->z());
    SVector3 t1 = v1 - v0;
    SVector3 t2 = v2 - v0;
    SVector3 t = crossprod(t1, t2);
    t.normalize();
    SVector3 d = crossprod(n, t);
    if(d.norm() < 1.e-12) continue;
    d.normalize();
    double rhs[2] = {dot(n, p), dot(v0, t)};
    double r[2];
    double m[2][2];
    SVector3 x0(0, 0, 0);
    m[0][0] = n.y();
    m[0][1] = n.z();
    m[1][0] = t.y();
    m[1][1] = t.z();
    if(fabs(det2x2(m)) > 1.e-12) {
      sys2x2(m, rhs, r);
      x0 = SVector3(0, r[0], r[1]);
    }
    else {
      m[0][0] = n.x();
      m[0][1] = n.z();
      m[1][0] = t.x();
      m[1][1] = t.z();
      if(fabs(det2x2(m)) > 1.e-12) {
        sys2x2(m, rhs, r);
        x0 = SVector3(r[0], 0, r[1]);
      }
      else {
        m[0][0] = n.x();
        m[0][1] = n.y();
        m[1][0] = t.x();
        m[1][1] = t.y();
        if(sys2x2(m, rhs, r)) { x0 = SVector3(r[0], r[1], 0); }
        else {
          // printf("mauvaise pioche\n");
          continue;
        }
      }
    }

    const double a = 1.0;
    const double b = -2 * dot(d, p - x0);
    const double c = dot(p - x0, p - x0) - R * R;
    const double delta = b * b - 4 * a * c;
    if(delta >= 0) {
      double sign = (dot(n2, d) > 0) ? 1.0 : -1.0;
      const double ta = (-b + sign * sqrt(delta)) / (2. * a);
      const double tb = (-b - sign * sqrt(delta)) / (2. * a);
      SVector3 s[2] = {x0 + d * ta, x0 + d * tb};
      for(int IT = 0; IT < 2; IT++) {
        double mat[2][2], b[2], uv[2];
        mat[0][0] = dot(t1, t1);
        mat[1][1] = dot(t2, t2);
        mat[0][1] = mat[1][0] = dot(t1, t2);
        b[0] = dot(s[IT] - v0, t1);
        b[1] = dot(s[IT] - v0, t2);
        sys2x2(mat, b, uv);
        // check now if the point is inside the triangle
        if(uv[0] >= -1.e-6 && uv[1] >= -1.e-6 && 1. - uv[0] - uv[1] >= -1.e-6) {
          SVector3 pp =
            v0_2d * (1. - uv[0] - uv[1]) + v1_2d * uv[0] + v2_2d * uv[1];
          uv[0] = pp.x();
          uv[1] = pp.y();
          return GPoint(s[IT].x(), s[IT].y(), s[IT].z(), this, uv);
        }
      }
    }
  }
#endif
  GPoint pp(0);
  pp.setNoSuccess();
  //  Msg::Warning("Could not intersect with circle");
  return pp;
}

#if defined(HAVE_HXT)

bool discreteFace::_computeTopologyOfPartition(
  int nbColors, int *colors, int *nNodes, int *nodes, double *uv,
  std::vector<MVertex *> &c2v, std::vector<std::vector<MEdge> > &boundaries)
{
  GModel *gm = model();

  int TAG = gm->getMaxElementNumber() + 1;

  // Assign parameters for each vertex of each partition
  std::vector<int> cpt(_parametrizations.size());
  std::vector<MTriangle *> &ts = triangles;
  // make a copy of the geometry and of the parametrization (could be smaller)
  std::map<std::pair<MVertex *, int>, SPoint2> params;
  for(size_t i = 0; i < _parametrizations.size(); i++) {
    cpt[colors[i]] = 0;
    for(int j = nNodes[i]; j < nNodes[i + 1]; j++) {
      MVertex *vert = c2v[nodes[j]];
      double U = uv[2 * j + 0];
      double V = uv[2 * j + 1];
      std::pair<MVertex *, int> pp = std::make_pair(vert, i);
      params[pp] = SPoint2(U, V);
    }
  }

  // count how much triangles per partition
  for(size_t i = 0; i < ts.size(); i++) { cpt[colors[i]]++; }
  for(size_t i = 0; i < _parametrizations.size(); i++) {
    _parametrizations[colors[i]].t3d.reserve(cpt[colors[i]]);
    _parametrizations[colors[i]].t2d.reserve(cpt[colors[i]]);
  }

  //#define debug
#ifdef debug
  // save the atlas in pos files for checking - debugging
  char zz[256];
  sprintf(zz, "parametrization_P%d.pos", tag());
  FILE *f = fopen(zz, "w");
  fprintf(f, "View \"\"{\n");
  sprintf(zz, "parametrization_R%d.pos", tag());
  FILE *f2 = fopen(zz, "w");
  fprintf(f2, "View \"\"{\n");
#endif
  // created copies of triangles, both in 2D and in 3D
  for(size_t i = 0; i < ts.size(); i++) {
    MTriangle *t = ts[i];
    int c = colors[i];
    MVertex *v0 = new MVertex(t->getVertex(0)->x(), t->getVertex(0)->y(),
                              t->getVertex(0)->z());
    MVertex *v1 = new MVertex(t->getVertex(1)->x(), t->getVertex(1)->y(),
                              t->getVertex(1)->z());
    MVertex *v2 = new MVertex(t->getVertex(2)->x(), t->getVertex(2)->y(),
                              t->getVertex(2)->z());
    SPoint2 p0 = params[std::make_pair(t->getVertex(0), c)];
    SPoint2 p1 = params[std::make_pair(t->getVertex(1), c)];
    SPoint2 p2 = params[std::make_pair(t->getVertex(2), c)];
    MVertex *vv0 = new MVertex(p0.x(), p0.y(), 0.0);
    MVertex *vv1 = new MVertex(p1.x(), p1.y(), 0.0);
    MVertex *vv2 = new MVertex(p2.x(), p2.y(), 0.0);
    MTriangle t3d(v0, v1, v2);
    MTriangle t2d(vv0, vv1, vv2);
    _parametrizations[c].t3d.push_back(t3d);
    _parametrizations[c].t2d.push_back(t2d);
#ifdef debug
    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
            vv0->x() + 2.2 * c, vv0->y(), vv0->z(), vv1->x() + 2.2 * c,
            vv1->y(), vv1->z(), vv2->x() + 2.2 * c, vv2->y(), vv2->z(), c, c,
            c);
    fprintf(f2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n", v0->x(), v0->y(),
            v0->z(), v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(), c, c,
            c);
#endif
  }
#ifdef debug
  fprintf(f, "};\n");
  fclose(f);
  fprintf(f2, "};\n");
  fclose(f2);
#endif

  // compute 1D topology

  // edges between two colors
  std::map<MEdge, std::pair<int, int>, Less_Edge> l;
  for(size_t i = 0; i < ts.size(); i++) {
    MTriangle *t = ts[i];
    int c = colors[i];
    for(int j = 0; j < 3; j++) {
      MEdge e = t->getEdge(j);
      std::map<MEdge, std::pair<int, int>, Less_Edge>::iterator it = l.find(e);
      if(it == l.end()) {
        std::pair<int, int> p = std::make_pair(c, (int)-1);
        l[e] = p;
      }
      else {
        if(it->second.first == c) { l.erase(it); }
        else
          it->second.second = c;
      }
    }
  }

  // compute model edges that are internal to a partition or on its boundary
  // the form of an internal edge is a vector of MEdge

  std::map<std::pair<int, int>, std::vector<MEdge> > edges;
  {
    std::map<MEdge, std::pair<int, int>, Less_Edge>::iterator it = l.begin();
    for(; it != l.end(); ++it) {
      std::pair<int, int> x = it->second;
      std::pair<int, int> y = std::make_pair(std::min(x.first, x.second),
                                             std::max(x.first, x.second));
      std::map<std::pair<int, int>, std::vector<MEdge> >::iterator itf =
        edges.find(y);
      if(itf == edges.end()) {
        std::vector<MEdge> v;
        v.push_back(it->first);
        edges[y] = v;
      }
      else {
        itf->second.push_back(it->first);
      }
    }
  }

  // each color has MEdges as boundaries
  {
    std::map<std::pair<int, int>, std::vector<MEdge> >::iterator it =
      edges.begin();
    for(; it != edges.end(); ++it) {
      if(it->first.first != -1)
        boundaries[it->first.first].insert(boundaries[it->first.first].begin(),
                                           it->second.begin(),
                                           it->second.end());
      if(it->first.second != -1)
        boundaries[it->first.second].insert(
          boundaries[it->first.second].begin(), it->second.begin(),
          it->second.end());
    }
  }

  // split external edges i.e. edges that were already there but that are split
  // by partitions
  {
    std::map<std::pair<int, int>, std::vector<MEdge> >::iterator it =
      edges.begin();
    for(; it != edges.end(); ++it) {
      std::vector<std::vector<MVertex *> > vs;
      // this is the tricky beast !!!
      SortEdgeConsecutive(it->second, vs);
      for(size_t k = 0; k < vs.size(); k++) {
        std::vector<MVertex *> &v = vs[k];
        MVertex *vs[2] = {v[0], v[v.size() - 1]};
        for(int i = 0; i < 2; i++) {
          if(vs[i]->onWhat()->dim() == 1 && it->first.second != -1 &&
             it->first.first != -1) {
            // vs[i]->onWhat()->mesh_vertices.erase
            //     (std::remove(vs[i]->onWhat()->mesh_vertices.begin(),
            //	   vs[i]->onWhat()->mesh_vertices.end(), vs[i]),
            //	   vs[i]->onWhat()->mesh_vertices.end());
            discreteEdge *de = dynamic_cast<discreteEdge *>(vs[i]->onWhat());
            if(!de) { Msg::Error("Can currently only split discrete curves"); }
            else {
              discreteVertex *gstart = new discreteVertex(
                gm, ++TAG + 1, vs[i]->x(), vs[i]->y(), vs[i]->z());
              gm->add(gstart);
              vs[i]->setEntity(gstart);
              gstart->mesh_vertices.push_back(vs[i]);
              splitDiscreteEdge(de, vs[i], gstart, TAG);
              Msg::Info(" - Splitting discrete curve %d", de->tag());
            }
          }
        }
      }
    }
  }

  // at that point, end vertices of partition lines are either classified on
  // GVertex or on GFace
  {
    std::map<std::pair<int, int>, std::vector<MEdge> >::iterator it =
      edges.begin();
    for(; it != edges.end(); ++it) {
      std::vector<std::vector<MVertex *> > vs;

      SortEdgeConsecutive(it->second, vs);

      for(size_t k = 0; k < vs.size(); k++) {
        std::vector<MVertex *> &v = vs[k];
        MVertex *ends[2] = {v[0], v[v.size() - 1]};
        if(ends[0]->onWhat() == this || ends[1]->onWhat() == this) {
          for(int i = 0; i < 2; i++) {
            if(ends[i]->onWhat() == this) {
              discreteVertex *gstart = new discreteVertex(
                gm, ++TAG, ends[i]->x(), ends[i]->y(), ends[i]->z());
              gm->add(gstart);
              ends[i]->setEntity(gstart);
              gstart->mesh_vertices.push_back(ends[i]);
            }
          }
        }
        if(it->first.first != -1) {
          discreteEdge *de =
            new discreteEdge(gm, ++TAG, (GVertex *)ends[0]->onWhat(),
                             (GVertex *)ends[1]->onWhat());
          Msg::Info(" - Creating internal discrete curve %d (%d %d) in surface %d",
                    de->tag(), ends[0]->onWhat()->tag(),
                    ends[1]->onWhat()->tag(), tag());
          gm->add(de);
          for(size_t i = 1; i < v.size() - 1; i++) {
            v[i]->setEntity(de);
            de->mesh_vertices.push_back(v[i]);
          }
          for(size_t i = 1; i < v.size(); i++)
            de->lines.push_back(new MLine(v[i - 1], v[i]));
        }
      }
    }
  }
  mesh_vertices.clear();
  triangles.clear();
  gm->setMaxElementNumber(TAG);

  return true;
}

HXTStatus discreteFace::_reparametrizeThroughHxt()
{
  int n = 1;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));

  HXTMesh *m;
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  gmsh2hxt(this, &m, v2c, c2v);

  HXTParametrization *parametrization;
  int *colors, *nNodes, *nodes, nc;
  double *uv;
  HXT_CHECK(hxtParametrizationCreate(m, 0, &parametrization));
  HXT_CHECK(hxtParametrizationCompute(parametrization, &colors, &nNodes, &nodes,
                                      &uv, &nc, &m));

  // HXT_CHECK(hxtParametrizationWrite(parametrization, zz));

  // compute curvatures
  HXTEdges *edges;
  double *crossField, *nodalCurvatures;
  HXT_CHECK(hxtEdgesCreate(m, &edges));
  HXT_CHECK(
    hxtCurvatureRusinkiewicz(m, &nodalCurvatures, &crossField, edges, false));
  HXT_CHECK(hxtEdgesDelete(&edges));
  _parametrizations.resize(nc);
  std::vector<std::vector<MEdge> > boundaries(nc);
  std::vector<std::vector<MEdge> > internals(nc);
  if(!_computeTopologyOfPartition(nc, colors, nNodes, nodes, uv, c2v,
                                  boundaries))
    Msg::Warning("Impossible to compute the topology of the %d partitions", nc);

  Msg::Info(" - Surface %d split in %d part%s", tag(), _parametrizations.size(),
            (_parametrizations.size() > 1) ? "s" : "");

  for(size_t i = 0; i < _parametrizations.size(); i++) {
    Less_Edge le;
    std::sort(boundaries[i].begin(), boundaries[i].end(), le);
    std::set<GEdge *> des;
    for(GModel::eiter it = model()->firstEdge(); it != model()->lastEdge();
        it++) {
      for(size_t k = 0; k < (*it)->lines.size(); k++) {
        MEdge e((*it)->lines[k]->getVertex(0), (*it)->lines[k]->getVertex(1));
        if(std::binary_search(boundaries[i].begin(), boundaries[i].end(), e,
                              le)) {
          GEdge *de = *it;
          if(des.find(de) == des.end()) {
            if(de->_compound.size()) {
              if(de->compound_edge)
                des.insert((discreteEdge *)de->compound_edge);
            }
            else {
              des.insert(de);
            }
          }
        }
      }
    }
    _parametrizations[i].bnd.insert(_parametrizations[i].bnd.begin(),
                                    des.begin(), des.end());
  }

  for(size_t i = 0; i < _parametrizations.size(); i++) {
    std::vector<MElement *> temp;
    for(size_t j = 0; j < _parametrizations[i].t2d.size(); j++) {
      temp.push_back(&_parametrizations[i].t2d[j]);
      double MIN[3] = {_parametrizations[i].t3d[j].getVertex(0)->x(),
                       _parametrizations[i].t3d[j].getVertex(0)->y(),
                       _parametrizations[i].t3d[j].getVertex(0)->z()};
      double MAX[3] = {_parametrizations[i].t3d[j].getVertex(0)->x(),
                       _parametrizations[i].t3d[j].getVertex(0)->y(),
                       _parametrizations[i].t3d[j].getVertex(0)->z()};
      for(int k = 1; k < 3; k++) {
        MAX[0] =
          std::max(MAX[0], _parametrizations[i].t3d[j].getVertex(k)->x());
        MIN[0] =
          std::min(MIN[0], _parametrizations[i].t3d[j].getVertex(k)->x());
        MAX[1] =
          std::max(MAX[1], _parametrizations[i].t3d[j].getVertex(k)->y());
        MIN[1] =
          std::min(MIN[1], _parametrizations[i].t3d[j].getVertex(k)->y());
        MAX[2] =
          std::max(MAX[2], _parametrizations[i].t3d[j].getVertex(k)->z());
        MIN[2] =
          std::min(MIN[2], _parametrizations[i].t3d[j].getVertex(k)->z());
      }
      std::pair<MTriangle *, MTriangle *> *tt =
        new std::pair<MTriangle *, MTriangle *>(&_parametrizations[i].t3d[j],
                                                &_parametrizations[i].t2d[j]);
      _parametrizations[i].rtree3d.Insert(MIN, MAX, tt);
    }
    _parametrizations[i].oct = new MElementOctree(temp);
  }

  for(size_t i = 0; i < _parametrizations.size(); i++) {
    for(size_t j = 0; j < _parametrizations[i].emb.size(); j++) {
      model()->add(_parametrizations[i].emb[j]);
    }
  }

  HXT_CHECK(hxtParametrizationDelete(&parametrization));
  HXT_CHECK(hxtMeshDelete(&m));
  return HXT_STATUS_OK;
}

hxt_reparam_surf::~hxt_reparam_surf()
{
  if(oct) delete oct;
}

#endif

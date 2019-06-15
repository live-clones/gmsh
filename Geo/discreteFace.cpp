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

#if defined(HAVE_HXT)
extern "C" {
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_mean_values.h"
#include "hxt_linear_system.h"
}
#endif

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = CreateSurface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
#if defined(HAVE_HXT)
  _currentParametrization = -1;
#endif
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

int discreteFace::trianglePosition(double par1, double par2, double &u,
                                   double &v) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0;
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return 0;

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e =
    _parametrizations[ipar].oct->find(par1, par2, 0.0, -1, true);
  if(!e) return -1;
  e->xyz2uvw(xy, uv);
  int position = (int)((MTriangle *)e - &_parametrizations[ipar].t2d[0]);
  u = uv[0];
  v = uv[1];
  return position;
#else
  return 0;
#endif
}

static void MYxyz2uvw(const MElement *t, double xyz[3], double uvw[3])
{
  double M[2][2], R[2];
  const SPoint2 p0(t->getVertex(0)->x(), t->getVertex(0)->y());
  const SPoint2 p1(t->getVertex(1)->x(), t->getVertex(1)->y());
  const SPoint2 p2(t->getVertex(2)->x(), t->getVertex(2)->y());
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (xyz[0] - p0.x());
  R[1] = (xyz[1] - p0.y());
  double const det = M[0][0] * M[1][1] - M[1][0] * M[0][1];
  //  printf("DET = %22.15E\n",det);
  uvw[0] = R[0] * M[1][1] - M[0][1] * R[1];
  uvw[1] = M[0][0] * R[1] - M[1][0] * R[0];
  uvw[0] /= det;
  uvw[1] /= det;
  return;
}

GPoint discreteFace::point(double par1, double par2) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return GPoint();
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return GPoint();

  double xy[3] = {par1, par2, 0};
  double uv[3];
  //  MElement::setTolerance(1.e-17);
  const MElement *e =
    _parametrizations[ipar].oct->find(par1, par2, 0.0, -1, true);
  //  std::vector<MElement *> es = _parametrizations[ipar].oct->findAll(par1,
  //  par2, 0.0,-1,false); printf("--> %g %g\n",par1,par2);
  if(!e) {
    GPoint gp = GPoint(1.e21, 1.e21, 1.e21, this, xy);
    gp.setNoSuccess();
    return gp;
  }
  MYxyz2uvw(e, xy, uv);
  //  e->xyz2uvw(xy, uv);
  //  printf("1 point found in %12.5E %12.5E -- %12.5E %12.5E -- %12.5E %12.5E
  //  UVW %12.5E %12.5E %12.5E uv %12.5E %12.5E\n",
  //	 e->getVertex(0)->x(),e->getVertex(0)->y(),
  //	 e->getVertex(1)->x(),e->getVertex(1)->y(),
  //	 e->getVertex(2)->x(),e->getVertex(2)->y(),uv[0],uv[1],1.-uv[0]-uv[1],par1,par2);
  //  printf("DIFFERENCE %12.5E %12.5E -- %12.5E
  //  %12.5E\n",par1,par2,uv[0]*e->getVertex(1)->x()+
  //	 uv[1]*e->getVertex(2)->x()+(1.-uv[0]-uv[1])*e->getVertex(0)->x(),uv[0]*e->getVertex(1)->y()+
  //	 uv[1]*e->getVertex(2)->y()+(1.-uv[0]-uv[1])*e->getVertex(0)->y()
  //	 );

  int position = (int)((MTriangle *)e - &_parametrizations[ipar].t2d[0]);
  const MTriangle &t3d = _parametrizations[ipar].t3d[position];
  double X = 0, Y = 0, Z = 0;
  double eval[3] = {1. - uv[0] - uv[1], uv[0], uv[1]};
  //  printf("%12.5E  %12.5E  %12.5E %d
  //  %d\n",eval[0],eval[1],eval[2],e->isInside(eval[1],eval[2],0.0),es.size());
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
  signedDistancePointTriangle(
    SPoint3(t->first->getVertex(0)->x(), t->first->getVertex(0)->y(),
            t->first->getVertex(0)->z()),
    SPoint3(t->first->getVertex(1)->x(), t->first->getVertex(1)->y(),
            t->first->getVertex(1)->z()),
    SPoint3(t->first->getVertex(2)->x(), t->first->getVertex(2)->y(),
            t->first->getVertex(2)->z()),
    wrapper->_p, d, closePt);
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
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return GPoint();

  dfWrapper wrapper(queryPoint);
  do {
    wrapper._distance = 1.e22;
    double MIN[3] = {queryPoint.x() - maxDistance, queryPoint.y() - maxDistance,
                     queryPoint.z() - maxDistance};
    double MAX[3] = {queryPoint.x() + maxDistance, queryPoint.y() + maxDistance,
                     queryPoint.z() + maxDistance};
    _parametrizations[ipar].rtree3d.Search(
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
  const MVertex *v03 = wrapper._t3d->getVertex(0);
  const MVertex *v13 = wrapper._t3d->getVertex(1);
  const MVertex *v23 = wrapper._t3d->getVertex(2);
  double U = 1 - uvw[0] - uvw[1];
  double V = uvw[0];
  double W = uvw[1];
  SPoint2 pp(U * v0->x() + V * v1->x() + W * v2->x(),
             U * v0->y() + V * v1->y() + W * v2->y());
  SPoint3 pp3(U * v03->x() + V * v13->x() + W * v23->x(),
              U * v03->y() + V * v13->y() + W * v23->y(),
              U * v03->z() + V * v13->z() + W * v23->z());

  //  printf("2 point found in %12.5E %12.5E -- %12.5E %12.5E -- %12.5E %12.5E
  //  UV %12.5E %12.5E %12.5E uv %12.5E %12.5E\n",
  //	 v0->x(),v0->y(),v1->x(),v1->y(),v2->x(),v2->y(),V,W,U,pp.x(),pp.y());

  /*
  GPoint pp01 = point( SPoint2(v0->x(),v0->y()));
  GPoint pp02 = point( SPoint2(v1->x(),v1->y()));
  GPoint pp03 = point( SPoint2(v2->x(),v2->y()));
  SPoint3 PP01(pp01.x(),pp01.y(),pp01.z());
  SPoint3 PP02(pp02.x(),pp02.y(),pp02.z());
  SPoint3 PP03(pp03.x(),pp03.y(),pp03.z());
  printf ("CORNER DISTANCES %12.5E %12.5E %12.5E\n",
      PP01.distance(SPoint3(v03->x(),v03->y(),v03->z())),
      PP02.distance(SPoint3(v13->x(),v13->y(),v13->z())),
      PP03.distance(SPoint3(v23->x(),v23->y(),v23->z())));

  printf("DISTANCE = %12.5E\n",pp3.distance(queryPoint));
  */

  //  if (queryPoint.distance(wrapper._closestPoint) > 1.e-8)
  //    printf("%12.5E %12.5E %12.5E -- %12.5E %12.5E %12.5E d %12.5E\n",
  //	 queryPoint.x(),queryPoint.y(),queryPoint.z(),
  //	   wrapper._closestPoint.x(), wrapper._closestPoint.y(),
  //	   wrapper._closestPoint.z(),
  //queryPoint.distance(wrapper._closestPoint));

  return GPoint(pp3.x(), pp3.y(), pp3.z(), this, pp);
#else
  return GPoint();
#endif
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint,
                                  const double initialGuess[2]) const
{
#if defined(HAVE_HXT)
  return closestPoint(queryPoint, 0.1);
#else
  Msg::Error("Cannot evaluate closest point on discrete surface without HXT");
  return GPoint();
#endif
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
#if defined(HAVE_HXT)
  //  printf(" START -- %12.5E %12.5E %12.5E\n",p.x(),p.y(),p.z());
  GPoint gp = closestPoint(p, 0.000001);
  //  GPoint gp2 = point(SPoint2(gp.u(),gp.v()));
  //  printf(" END -- %12.5E %12.5E %12.5E -- dist
  //  %12.5E\n\n",gp2.x(),gp2.y(),gp2.z(),
  //	 sqrt((gp2.x()-p.x())*(gp2.x()-p.x()) +
  //	      (gp2.y()-p.y())*(gp2.y()-p.y()) +
  //	      (gp2.z()-p.z())*(gp2.z()-p.z()) ));
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
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return SVector3();

  MElement *e =
    _parametrizations[ipar].oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Warning("Triangle not found at uv=(%g,%g) on discrete surface %d",
                 param.x(), param.y(), tag());
    return SVector3(0, 0, 1);
  }
  int position = (int)((MTriangle *)e - &_parametrizations[ipar].t2d[0]);
  const MTriangle &t3d = _parametrizations[ipar].t3d[position];
  return NORMAL_(t3d);
#else
  Msg::Error("Cannot evaluate normal on discrete surface without HXT");
  return SVector3();
#endif
}

double discreteFace::curvatureMax(const SPoint2 &param) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0.;
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return 0.;

  SVector3 dirMax, dirMin;
  double c, C;
  if(_parametrizations[ipar].CURV.empty()) return 0.0;
  curvatures(param, dirMax, dirMin, C, c);
  return std::max(c, C);
#else
  Msg::Error("Cannot evaluate curvature on discrete surface without HXT");
  return 0.;
#endif
}

double discreteFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                                SVector3 &dirMin, double &curvMax,
                                double &curvMin) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0.;
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return 0.;

  if(_parametrizations[ipar].CURV.empty()) return 0.0;

  MElement *e =
    _parametrizations[ipar].oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    //    Msg::Warning("Triangle not found for curvatures at uv=(%g,%g) on "
    //                 "discrete surface %d",
    //                 param.x(), param.y(), tag());
    return 0.0;
  }

  int position = (int)((MTriangle *)e - &_parametrizations[ipar].t2d[0]);

  SVector3 c0max = _parametrizations[ipar].CURV[6 * position + 0];
  SVector3 c1max = _parametrizations[ipar].CURV[6 * position + 1];
  SVector3 c2max = _parametrizations[ipar].CURV[6 * position + 2];
  SVector3 c0min = _parametrizations[ipar].CURV[6 * position + 3];
  SVector3 c1min = _parametrizations[ipar].CURV[6 * position + 4];
  SVector3 c2min = _parametrizations[ipar].CURV[6 * position + 5];

  curvMax = c0max.norm();
  curvMin = c0min.norm();

  dirMax = c0max.normalize();
  dirMin = c0min.normalize();

  return false;
#else
  Msg::Error("Cannot evaluate curvature on discrete surface without HXT");
  return 0.;
#endif
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty())
    return Pair<SVector3, SVector3>(SVector3(), SVector3());
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return Pair<SVector3, SVector3>(SVector3(), SVector3());

  MElement *e =
    _parametrizations[ipar].oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Warning("Triangle not found for first derivative at uv=(%g,%g) on "
                 "discrete surface %d",
                 param.x(), param.y(), tag());
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));
  }

  int position = (int)((MTriangle *)e - &_parametrizations[ipar].t2d[0]);

  const MTriangle &t3d = _parametrizations[ipar].t3d[position];
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

#if defined(HAVE_HXT)

static HXTStatus gmsh2hxt(int tag, const std::vector<MTriangle *> &t,
                          HXTMesh **pm, std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *m;
  HXT_CHECK(hxtMeshCreate(context, &m));
  std::set<MVertex *> all;
  for(size_t i = 0; i < t.size(); i++) {
    all.insert(t[i]->getVertex(0));
    all.insert(t[i]->getVertex(1));
    all.insert(t[i]->getVertex(2));
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

  m->triangles.num = m->triangles.size = t.size();
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < t.size(); i++) {
    m->triangles.node[3 * i + 0] = v2c[t[i]->getVertex(0)];
    m->triangles.node[3 * i + 1] = v2c[t[i]->getVertex(1)];
    m->triangles.node[3 * i + 2] = v2c[t[i]->getVertex(2)];
    m->triangles.colors[i] = tag;
  }

  m->lines.num = m->lines.size = 0;

  *pm = m;
  return HXT_STATUS_OK;
}

static HXTStatus gmsh2hxt(GFace *gf, HXTMesh **pm,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  return gmsh2hxt(gf->tag(), gf->triangles, pm, v2c, c2v);
}

#endif

int discreteFace::createGeometry(
  std::map<MVertex *, std::pair<SVector3, SVector3> > *curvatures)
{
#if defined(HAVE_HXT)
  int n = 1;
  if(triangles.empty()) return 0;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));
  HXTMesh *m;
  HXTMeanValues *param;
  HXTEdges *edges;
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  gmsh2hxt(this, &m, v2c, c2v);
  HXT_CHECK(hxtEdgesCreate(m, &edges));
  HXT_CHECK(hxtMeanValuesCreate(edges, &param));
  HXT_CHECK(hxtMeanValuesCompute(param));
  double *uvc = NULL;
  int nv, ne;
  HXT_CHECK(hxtMeanValuesGetData(param, NULL, NULL, &uvc, &nv, &ne, 1));
  stl_vertices_uv.clear();
  stl_vertices_uv.resize(nv);
  stl_vertices_xyz.clear();
  stl_vertices_xyz.resize(nv);
  stl_curvatures.clear();
  if(curvatures) stl_curvatures.resize(2 * nv);
  stl_normals.clear();
  stl_normals.resize(nv);

  for(int iv = 0; iv < nv; iv++) {
    if(curvatures) {
      MVertex *v = c2v[iv];
      std::map<MVertex *, std::pair<SVector3, SVector3> >::iterator it =
        curvatures->find(v);
      if(it == curvatures->end()) {
        Msg::Error("Curvature not found for node %d", v->getNum());
      }
      else {
        stl_curvatures[2 * iv] = it->second.first;
        stl_curvatures[2 * iv + 1] = it->second.second;
      }
    }
    stl_vertices_uv[iv] = SPoint2(uvc[2 * iv], uvc[2 * iv + 1]);

    stl_vertices_xyz[iv] =
      SPoint3(m->vertices.coord[4 * iv + 0], m->vertices.coord[4 * iv + 1],
              m->vertices.coord[4 * iv + 2]);
    stl_normals[iv] = SVector3(1, 0, 0);
  }
  stl_triangles.clear();
  stl_triangles.resize(3 * ne);
  for(int ie = 0; ie < ne; ie++) {
    stl_triangles[3 * ie + 0] = m->triangles.node[3 * ie + 0];
    stl_triangles[3 * ie + 1] = m->triangles.node[3 * ie + 1];
    stl_triangles[3 * ie + 2] = m->triangles.node[3 * ie + 2];
  }

  fillVertexArray(false);
  createGeometryFromSTL();

  HXT_CHECK(hxtMeshDelete(&m));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtFree(&uvc));

#endif
  return 0;
}

void discreteFace::createGeometryFromSTL()
{
  if(stl_triangles.empty() || stl_vertices_uv.empty() ||
     stl_vertices_xyz.empty())
    return;
#if defined(HAVE_HXT)
  _parametrizations.clear();
  _parametrizations.resize(1);

  for(size_t i = 0; i < stl_vertices_uv.size(); i++) {
    _parametrizations[0].v2d.push_back(
      MVertex(stl_vertices_uv[i].x(), stl_vertices_uv[i].y(), 0.0));
    _parametrizations[0].v3d.push_back(MVertex(stl_vertices_xyz[i].x(),
                                               stl_vertices_xyz[i].y(),
                                               stl_vertices_xyz[i].z()));
  }

  for(size_t i = 0; i < stl_triangles.size() / 3; i++) {
    int a = stl_triangles[3 * i];
    int b = stl_triangles[3 * i + 1];
    int c = stl_triangles[3 * i + 2];
    _parametrizations[0].t2d.push_back(MTriangle(&_parametrizations[0].v2d[a],
                                                 &_parametrizations[0].v2d[b],
                                                 &_parametrizations[0].v2d[c]));
    _parametrizations[0].t3d.push_back(MTriangle(&_parametrizations[0].v3d[a],
                                                 &_parametrizations[0].v3d[b],
                                                 &_parametrizations[0].v3d[c]));
    if(!stl_curvatures.empty()) {
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * a]);
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * a + 1]);
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * b]);
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * b + 1]);
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * c]);
      _parametrizations[0].CURV.push_back(stl_curvatures[2 * c + 1]);
    }
  }
  _parametrizations[0].bnd = edges();
  _parametrizations[0].emb = embedded_edges;
  if(_parametrizations[0].checkPlanar())
    Msg::Info("Discrete surface %d is planar, simplifying parametrization",
              tag());

  std::vector<MElement *> temp;
  for(size_t j = 0; j < _parametrizations[0].t2d.size(); j++) {
    temp.push_back(&_parametrizations[0].t2d[j]);
    double MIN[3] = {_parametrizations[0].t3d[j].getVertex(0)->x(),
                     _parametrizations[0].t3d[j].getVertex(0)->y(),
                     _parametrizations[0].t3d[j].getVertex(0)->z()};
    double MAX[3] = {_parametrizations[0].t3d[j].getVertex(0)->x(),
                     _parametrizations[0].t3d[j].getVertex(0)->y(),
                     _parametrizations[0].t3d[j].getVertex(0)->z()};
    for(int k = 1; k < 3; k++) {
      MAX[0] = std::max(MAX[0], _parametrizations[0].t3d[j].getVertex(k)->x());
      MIN[0] = std::min(MIN[0], _parametrizations[0].t3d[j].getVertex(k)->x());
      MAX[1] = std::max(MAX[1], _parametrizations[0].t3d[j].getVertex(k)->y());
      MIN[1] = std::min(MIN[1], _parametrizations[0].t3d[j].getVertex(k)->y());
      MAX[2] = std::max(MAX[2], _parametrizations[0].t3d[j].getVertex(k)->z());
      MIN[2] = std::min(MIN[2], _parametrizations[0].t3d[j].getVertex(k)->z());
    }
    std::pair<MTriangle *, MTriangle *> *tt =
      new std::pair<MTriangle *, MTriangle *>(&_parametrizations[0].t3d[j],
                                              &_parametrizations[0].t2d[j]);
    _parametrizations[0].rtree3d.Insert(MIN, MAX, tt);
  }
  _parametrizations[0].oct = new MElementOctree(temp);

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
  for(size_t i = 0; i < _parametrizations.size(); i++) {
    int c = i;
    for(size_t j = 0; j < _parametrizations[i].t2d.size(); j++) {
      MTriangle *t2 = &_parametrizations[i].t2d[j];
      MTriangle *t3 = &_parametrizations[i].t3d[j];
      MVertex *vv0 = t2->getVertex(0);
      MVertex *vv1 = t2->getVertex(1);
      MVertex *vv2 = t2->getVertex(2);
      MVertex *v0 = t3->getVertex(0);
      MVertex *v1 = t3->getVertex(1);
      MVertex *v2 = t3->getVertex(2);
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
              vv0->x() + 2.2 * c, vv0->y(), vv0->z(), vv1->x() + 2.2 * c,
              vv1->y(), vv1->z(), vv2->x() + 2.2 * c, vv2->y(), vv2->z(), c, c,
              c);
      fprintf(f2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g};\n",
              v0->x(), v0->y(), v0->z(), v1->x(), v1->y(), v1->z(), v2->x(),
              v2->y(), v2->z(), vv0->x(), vv1->x(), vv2->x(), vv0->y(),
              vv1->y(), vv2->y());
    }
  }
  fprintf(f, "};\n");
  fclose(f);
  fprintf(f2, "};\n");
  fclose(f2);
#endif

#endif
}

void discreteFace::mesh(bool verbose)
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return;

  std::vector<MTriangle *> _t;
  std::vector<MVertex *> _v;
  std::vector<GEdge *> const tmp = l_edges;
  std::vector<GVertex *> _gv;

  Msg::Info("Meshing discrete surface %d: the atlas contains %d map%s", tag(),
            _parametrizations.size(),
            (_parametrizations.size() > 1) ? "s" : "");

  for(size_t i = 0; i < _parametrizations.size(); i++) {
    l_edges.clear();
    for(size_t j = 0; j < _parametrizations[i].bnd.size(); j++) {
      if(_parametrizations[i].bnd[j]->geomType() == DiscreteCurve)
        ((discreteEdge *)_parametrizations[i].bnd[j])->getSplit(l_edges, _gv);
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
  triangles = _t;
  mesh_vertices = _v;
  l_edges = tmp;
  embedded_edges.clear();
  meshStatistics.status = GFace::DONE;
#else
  Msg::Error("Cannot mesh discrete surface without HXT");
#endif
}

GPoint discreteFace::intersectionWithCircle(const SVector3 &n1,
                                            const SVector3 &n2,
                                            const SVector3 &p, const double &R,
                                            double uv[2])
{
#if defined(HAVE_HXT)
  if(_parametrizations.empty()) return 0.;
  int ipar = _parametrizations.size() == 1 ? 0 : _currentParametrization;
  if(ipar < 0) return 0.;

  MTriangle *t2d =
    (MTriangle *)_parametrizations[ipar].oct->find(uv[0], uv[1], 0.0, -1, true);
  MTriangle *t3d = NULL;
  if(t2d) {
    int position = (int)(t2d - &_parametrizations[ipar].t2d[0]);
    t3d = &_parametrizations[ipar].t3d[position];
  }

  SVector3 n = crossprod(n1, n2);
  n.normalize();

  int N = _parametrizations[ipar].t3d.size();
  int start = 0;
  if(t2d) start = -1;
  for(int i = start; i < N; i++) {
    if(i >= 0) {
      t2d = &_parametrizations[ipar].t2d[i];
      t3d = &_parametrizations[ipar].t3d[i];
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

bool discreteFace::param::checkPlanar()
{
#ifndef HAVE_LAPACK
  return false;
#endif

  SBoundingBox3d bb;
  mean_plane mp;
  std::vector<SPoint3> v, vp;
  for(size_t i = 0; i < t3d.size(); i++) {
    for(int j = 0; j < 3; j++) {
      SPoint3 p(t3d[i].getVertex(j)->x(), t3d[i].getVertex(j)->y(),
                t3d[i].getVertex(j)->z());
      bb += p;
      v.push_back(p);
    }
  }

  computeMeanPlaneSimple(v, mp);
  projectPointsToPlane(v, vp, mp);
  for(size_t i = 0; i < v.size(); i++) {
    double F = mp.a * v[i].x() + mp.b * v[i].y() + mp.c * v[i].z() - mp.d;
    // double d = v[i].distance (vp[i]);
    if(fabs(F) > 1.e-3 * bb.diag()) {
      // printf("distance is too large %G vs %g\n",d,bb.diag());
      return false;
    }
  }

  SVector3 VX(mp.plan[0][0], mp.plan[0][1], mp.plan[0][2]);
  SVector3 VY(mp.plan[1][0], mp.plan[1][1], mp.plan[1][2]);
  SPoint3 XP(mp.x, mp.y, mp.z);

  //  printf("%g %g %g\n",mp.plan[0][0],mp.plan[0][1],mp.plan[0][2]);
  //  printf("%g %g %g\n",mp.plan[1][0],mp.plan[1][1],mp.plan[1][2]);
  //  printf("%g %g %g\n",mp.x,mp.y,mp.z);

  int count = 0;
  for(size_t i = 0; i < t2d.size(); i++) {
    for(int j = 0; j < 3; j++) {
      SVector3 DX = vp[count++] - XP;
      // printf("x y = %g %g\n",dot(DX,VX),dot(DX,VY));
      t2d[i].getVertex(j)->x() = dot(DX, VX);
      t2d[i].getVertex(j)->y() = dot(DX, VY);
    }
  }
  return true;
}

discreteFace::param::~param()
{
  if(oct) delete oct;
}

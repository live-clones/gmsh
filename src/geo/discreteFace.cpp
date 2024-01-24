// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <queue>
#include "GmshMessage.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "Context.h"
#include "MPoint.h"
#include "MElementOctree.h"
#include "Octree.h"
#include "Context.h"
#include "GEdgeLoop.h"
#include "MEdge.h"
#include "GModelParametrize.h"

#if defined(HAVE_EIGEN) && defined(HAVE_GEOMETRYCENTRAL)
#include <Eigen/Core>
#include <Eigen/Dense>
#include "geometrycentral/surface/signpost_intrinsic_triangulation.h"
#include "geometrycentral/surface/vertex_position_geometry.h"
#endif

discreteFace::param::~param()
{
  clear();
}

void discreteFace::param::clear()
{
  if(oct) delete oct;
  rtree3d.RemoveAll();
  for(auto p : rtree3dData) delete p;
  rtree3dData.clear();
  v2d.clear();
  v3d.clear();
  bbox = SBoundingBox3d();
  t2d.clear();
  t3d.clear();
  CURV.clear();
}

bool discreteFace::param::checkPlanar()
{
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
    // this is maybe a bit strict, but it's better this way: wrongly identifying
    // a very thin (but curved) surface as plane will lead to complete meshing
    // failure (see e.g. mmbendo.stl in #641)
    if(fabs(F) > CTX::instance()->geom.matchMeshTolerance * bb.diag()) {
      return false;
    }
  }

  SVector3 VX(mp.plan[0][0], mp.plan[0][1], mp.plan[0][2]);
  SVector3 VY(mp.plan[1][0], mp.plan[1][1], mp.plan[1][2]);
  SPoint3 XP(mp.x, mp.y, mp.z);

  umin = 1e200;
  vmin = 1e200;
  umax = -1e200;
  vmax = -1e200;

  int count = 0;
  for(size_t i = 0; i < t2d.size(); i++) {
    for(int j = 0; j < 3; j++) {
      SVector3 DX = vp[count++] - XP;
      MVertex *v = t2d[i].getVertex(j);
      v->x() = dot(DX, VX);
      v->y() = dot(DX, VY);
      umin = std::min(umin, v->x());
      vmin = std::min(vmin, v->y());
      umax = std::max(umax, v->x());
      vmax = std::max(vmax, v->y());
    }
  }
  return true;
}

discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = CreateSurface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

discreteFace::discreteFace(GModel *model) : GFace(model, 0)
{
  // used for temporary discrete faces, that should not lead to the creation of
  // the corresponding entity in GEO internals
}

int discreteFace::trianglePosition(double par1, double par2, double &u,
                                   double &v) const
{
  if(_param.empty()) return 0;

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e = _param.oct->find(par1, par2, 0.0, -1, true);
  if(!e) return -1;
  e->xyz2uvw(xy, uv);
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  u = uv[0];
  v = uv[1];
  return position;
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
  uvw[0] = R[0] * M[1][1] - M[0][1] * R[1];
  uvw[1] = M[0][0] * R[1] - M[1][0] * R[0];
  uvw[0] /= det;
  uvw[1] /= det;
  return;
}

GPoint discreteFace::point(double par1, double par2) const
{
  if(_param.empty()) return GPoint();

  double xy[3] = {par1, par2, 0};
  double uv[3];
  const MElement *e = _param.oct->find(par1, par2, 0.0, -1, true);
  if(!e) {
    GPoint gp = GPoint(1.e21, 1.e21, 1.e21, this, xy);
    gp.setNoSuccess();
    return gp;
  }
  MYxyz2uvw(e, xy, uv);
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  const MTriangle &t3d = _param.t3d[position];
  double X = 0, Y = 0, Z = 0;
  double eval[3] = {1. - uv[0] - uv[1], uv[0], uv[1]};
  for(int io = 0; io < 3; io++) {
    X += t3d.getVertex(io)->x() * eval[io];
    Y += t3d.getVertex(io)->y() * eval[io];
    Z += t3d.getVertex(io)->z() * eval[io];
  }
  return GPoint(X, Y, Z, this, xy);
}

class dfWrapper {
public:
  SPoint3 _p;
  double _distance;
  SPoint3 _closestPoint;
  MTriangle *_t3d, *_t2d;
  dfWrapper(const SPoint3 &p)
    : _p(p), _distance(1.e22), _t3d(nullptr), _t2d(nullptr)
  {
  }
};

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
  if(_param.empty()) {
    auto pp = GPoint();
    pp.setNoSuccess();
    return pp;
  }

  dfWrapper wrapper(queryPoint);
  do {
    wrapper._distance = 1.e22;
    double MIN[3] = {queryPoint.x() - maxDistance, queryPoint.y() - maxDistance,
                     queryPoint.z() - maxDistance};
    double MAX[3] = {queryPoint.x() + maxDistance, queryPoint.y() + maxDistance,
                     queryPoint.z() + maxDistance};
    _param.rtree3d.Search(MIN, MAX, discreteFace_rtree_callback, &wrapper);
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

  return GPoint(pp3.x(), pp3.y(), pp3.z(), this, pp);
}

GPoint discreteFace::closestPoint(const SPoint3 &queryPoint,
                                  const double initialGuess[2]) const
{
  return closestPoint(queryPoint, 1e-1);
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface,
                                   bool convTestXYZ) const
{
  GPoint gp = closestPoint(p, 1e-6);
  return SPoint2(gp.u(), gp.v());
}

Range<double> discreteFace::parBounds(int i) const
{
  if(i == 0)
    return Range<double>(_param.umin, _param.umax);
  else
    return Range<double>(_param.vmin, _param.vmax);
}

bool discreteFace::containsParam(const SPoint2 &pt)
{
  if(_param.empty()) return false;
  if(_param.oct->find(pt.x(), pt.y(), 0.0, -1, true)) return true;
  return false;
}

SBoundingBox3d discreteFace::bounds(bool fast)
{
  if(_param.empty()) return GFace::bounds(fast);
  return _param.bbox;
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  if(_param.empty()) return SVector3();

  MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Info("Triangle not found at uv=(%g,%g) on discrete surface %d",
              param.x(), param.y(), tag());
    return SVector3(0, 0, 1);
  }
  int position = (int)((MTriangle *)e - &_param.t2d[0]);
  const MTriangle &t3d = _param.t3d[position];
  SVector3 v31(t3d.getVertex(2)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(2)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(2)->z() - t3d.getVertex(0)->z());
  SVector3 v21(t3d.getVertex(1)->x() - t3d.getVertex(0)->x(),
               t3d.getVertex(1)->y() - t3d.getVertex(0)->y(),
               t3d.getVertex(1)->z() - t3d.getVertex(0)->z());
  SVector3 n = crossprod(v21, v31);
  n.normalize();
  return n;
}

double discreteFace::curvatureMax(const SPoint2 &param) const
{
  if(_param.empty()) return 0.;

  SVector3 dirMax, dirMin;
  double c, C;
  if(_param.CURV.empty()) return 0.0;
  curvatures(param, dirMax, dirMin, C, c);
  return std::max(c, C);
}

double discreteFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                                SVector3 &dirMin, double &curvMax,
                                double &curvMin) const
{
  if(_param.empty()) return 0.;
  if(_param.CURV.empty()) return 0.0;

  MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Info("Triangle not found for curvatures at uv=(%g,%g) on "
              "discrete surface %d",
              param.x(), param.y(), tag());
    return 0.0;
  }

  int position = (int)((MTriangle *)e - &_param.t2d[0]);

  SVector3 c0max = _param.CURV[6 * position + 0];
  SVector3 c1max = _param.CURV[6 * position + 1];
  SVector3 c2max = _param.CURV[6 * position + 2];
  SVector3 c0min = _param.CURV[6 * position + 3];
  SVector3 c1min = _param.CURV[6 * position + 4];
  SVector3 c2min = _param.CURV[6 * position + 5];

  curvMax = c0max.norm();
  curvMin = c0min.norm();

  dirMax = c0max.normalize();
  dirMin = c0min.normalize();

  return false;
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  if(_param.empty()) return Pair<SVector3, SVector3>(SVector3(), SVector3());

  MElement *e = _param.oct->find(param.x(), param.y(), 0.0, -1, true);
  if(!e) {
    Msg::Info("Triangle not found for first derivative at uv=(%g,%g) on "
              "discrete surface %d",
              param.x(), param.y(), tag());
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));
  }

  int position = (int)((MTriangle *)e - &_param.t2d[0]);

  const MTriangle &t3d = _param.t3d[position];
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
}

void discreteFace::secondDer(const SPoint2 &param, SVector3 &dudu,
                             SVector3 &dvdv, SVector3 &dudv) const
{
  return;
}

void discreteFace::_debugParametrization(bool uv)
{
  char tmp[256];
  sprintf(tmp, "discrete_param_%d.pos", tag());
  FILE *fp = fopen(tmp, "w");
  if(fp) {
    fprintf(fp, "View \"uv\" {\n");
    for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
      int i0 = stl_triangles[i + 0];
      int i1 = stl_triangles[i + 1];
      int i2 = stl_triangles[i + 2];
      SPoint3 xyz0 = stl_vertices_xyz[i0];
      SPoint3 xyz1 = stl_vertices_xyz[i1];
      SPoint3 xyz2 = stl_vertices_xyz[i2];
      SPoint2 uv0 = stl_vertices_uv[i0];
      SPoint2 uv1 = stl_vertices_uv[i1];
      SPoint2 uv2 = stl_vertices_uv[i2];
      if(uv) {
        for(int j = 0; j < 2; j++) {
          xyz0[j] = uv0[j];
          xyz1[j] = uv1[j];
          xyz2[j] = uv2[j];
        }
        xyz0[2] = xyz1[2] = xyz2[2] = 0;
      }
      fprintf(fp, "ST(%g,%g,%g, %g,%g,%g, %g,%g,%g){%g,%g,%g, %g,%g,%g};\n",
              xyz0.x(), xyz0.y(), xyz0.z(), xyz1.x(), xyz1.y(), xyz1.z(),
              xyz2.x(), xyz2.y(), xyz2.z(), uv0.x(), uv1.x(), uv2.x(), uv0.y(),
              uv1.y(), uv2.y());
    }
    fprintf(fp, "};\n");
    fclose(fp);
  }
}

void intrinsicDelaunayize(discreteFace *df)
{
#if defined(HAVE_EIGEN) && defined(HAVE_GEOMETRYCENTRAL)

  char name[245];
  sprintf(name, "intrinsic%d.pos", df->tag());
  FILE *ff = fopen(name, "w");
  fprintf(ff, "View \"\"{\n");

  Eigen::MatrixXi triangles(df->triangles.size(), 3);
  std::vector<geometrycentral::Vector3> vertexCoordinates;
  for(auto t : df->triangles) {
    t->getVertex(0)->setIndex(-1);
    t->getVertex(1)->setIndex(-1);
    t->getVertex(2)->setIndex(-1);
  }
  int index = 0;
  for(auto t : df->triangles) {
    for(int i = 0; i < 3; i++) {
      if(t->getVertex(i)->getIndex() == -1) {
        geometrycentral::Vector3 p = {
          t->getVertex(i)->x(), t->getVertex(i)->y(), t->getVertex(i)->z()};
        vertexCoordinates.push_back(p);
        t->getVertex(i)->setIndex(index++);
      }
    }
  }
  Eigen::MatrixXd positions(vertexCoordinates.size(), 3);
  for(size_t i = 0; i < vertexCoordinates.size(); i++) {
    positions(i, 0) = vertexCoordinates[i].x;
    positions(i, 1) = vertexCoordinates[i].y;
    positions(i, 2) = vertexCoordinates[i].z;
  }

  int T = 0;
  for(auto t : df->triangles) {
    for(int i = 0; i < 3; i++) triangles(T, i) = t->getVertex(i)->getIndex();
    T++;
  }
  geometrycentral::surface::ManifoldSurfaceMesh msm(triangles);

  printf("isManifold %d\n", msm.isManifold());
  printf("isOriented %d\n", msm.isOriented());
  printf("nVertices %lu\n", msm.nVertices());
  printf("nCorners %lu\n", msm.nCorners());
  printf("nInteriorVertices %lu\n", msm.nInteriorVertices());

  geometrycentral::surface::VertexPositionGeometry vpg(msm, positions);

  geometrycentral::surface::SignpostIntrinsicTriangulation signpostTri(msm,
                                                                       vpg);

  signpostTri.flipToDelaunay();

  signpostTri.delaunayRefine();
  printf("-->nVertices %lu %lu\n", signpostTri.intrinsicMesh->nVertices(),
         signpostTri.mesh.nVertices());

  signpostTri.requireVertexIndices();

  size_t nV = signpostTri.mesh.nVertices();
  size_t nF = signpostTri.mesh.nFaces();

  Eigen::MatrixXd vertexPositions(nV, 3);
  Eigen::MatrixXi faceInds(nF, 3);

  size_t iF = 0;
  for(geometrycentral::surface::Face f : signpostTri.mesh.faces()) {
    geometrycentral::surface::Halfedge he = f.halfedge();
    for(int v = 0; v < 3; v++) {
      geometrycentral::surface::Vertex vA = he.vertex();
      size_t indA = signpostTri.vertexIndices[vA];
      faceInds(iF, v) = indA;
      he = he.next();
    }
    iF++;
  }

  size_t iV = 0;
  for(geometrycentral::surface::Vertex v : signpostTri.mesh.vertices()) {
    geometrycentral::Vector3 pos =
      signpostTri.vertexLocations[v].interpolate(vpg.inputVertexPositions);
    vertexPositions(iV, 0) = pos.x;
    vertexPositions(iV, 1) = pos.y;
    vertexPositions(iV, 2) = pos.z;
    iV++;
  }

  for(int i = 0; i < nF; i++) {
    int id0 = faceInds(i, 0);
    int id1 = faceInds(i, 1);
    int id2 = faceInds(i, 2);
    fprintf(ff, "ST(%lg,%lg,%lg,%lg,%lg,%lg,%lg,%lg,%lg){%d,%d,%d};\n",
            vertexPositions(id0, 0), vertexPositions(id0, 1),
            vertexPositions(id0, 2), vertexPositions(id1, 0),
            vertexPositions(id1, 1), vertexPositions(id1, 2),
            vertexPositions(id2, 0), vertexPositions(id2, 1),
            vertexPositions(id2, 2), df->tag(), df->tag(), df->tag());
  }

  fprintf(ff, "};\n");
  fclose(ff);

#endif
}

int discreteFace::createGeometry()
{
  stl_vertices_uv.clear();
  stl_vertices_xyz.clear();
  stl_curvatures.clear();
  stl_triangles.clear();
  if(triangles.empty()) return 0;

  //  intrinsicDelaunayize(this);

  double minq = 1.;
  for(auto t : triangles) minq = std::min(minq, t->gammaShapeMeasure());
  if(minq < 1e-3)
    Msg::Warning("Poor input mesh quality (min gamma = %g) for computing "
                 "parametrization",
                 minq);

  std::vector<MVertex *> nodes;
  computeParametrization(triangles, nodes, stl_vertices_uv, stl_vertices_xyz,
                         stl_triangles);

  if(model()->getCurvatures().size()) {
    stl_curvatures.resize(2 * nodes.size());
    for(std::size_t i = 0; i < nodes.size(); i++) {
      auto it = model()->getCurvatures().find(nodes[i]);
      if(it == model()->getCurvatures().end()) {
        Msg::Error("Curvature not found for node %d", nodes[i]->getNum());
      }
      else {
        stl_curvatures[2 * i] = it->second.first;
        stl_curvatures[2 * i + 1] = it->second.second;
      }
    }
  }

  _computeSTLNormals();
  _createGeometryFromSTL();

  //_debugParametrization(false);

  return 0;
}

void discreteFace::_computeSTLNormals()
{
  stl_normals.clear();
  std::size_t T = stl_triangles.size() / 3;
  std::size_t N = stl_vertices_xyz.size();
  if(!N || !T) return;
  stl_normals.resize(N);
  for(std::size_t i = 0; i < T; i++) {
    int a = stl_triangles[3 * i + 0];
    int b = stl_triangles[3 * i + 1];
    int c = stl_triangles[3 * i + 2];
    SPoint3 pa(stl_vertices_xyz[a]);
    SPoint3 pb(stl_vertices_xyz[b]);
    SPoint3 pc(stl_vertices_xyz[c]);
    SVector3 vba = pb - pa;
    SVector3 vca = pc - pa;
    SVector3 n = crossprod(vba, vca);
    stl_normals[a] += n;
    stl_normals[b] += n;
    stl_normals[c] += n;
  }
  for(std::size_t i = 0; i < N; i++) stl_normals[i].normalize();
}

void discreteFace::_createGeometryFromSTL()
{
  if(stl_triangles.empty() || stl_vertices_uv.empty() ||
     stl_vertices_xyz.empty())
    return;

  _param.clear();

  for(size_t i = 0; i < stl_vertices_uv.size(); i++) {
    _param.v2d.push_back(
      MVertex(stl_vertices_uv[i].x(), stl_vertices_uv[i].y(), 0.0));
    _param.v3d.push_back(MVertex(stl_vertices_xyz[i].x(),
                                 stl_vertices_xyz[i].y(),
                                 stl_vertices_xyz[i].z()));
    _param.bbox += _param.v3d.back().point();
  }

  for(size_t i = 0; i < stl_triangles.size() / 3; i++) {
    int a = stl_triangles[3 * i];
    int b = stl_triangles[3 * i + 1];
    int c = stl_triangles[3 * i + 2];
    _param.t2d.push_back(
      MTriangle(&_param.v2d[a], &_param.v2d[b], &_param.v2d[c]));
    _param.t3d.push_back(
      MTriangle(&_param.v3d[a], &_param.v3d[b], &_param.v3d[c]));
    if(!stl_curvatures.empty()) {
      _param.CURV.push_back(stl_curvatures[2 * a]);
      _param.CURV.push_back(stl_curvatures[2 * a + 1]);
      _param.CURV.push_back(stl_curvatures[2 * b]);
      _param.CURV.push_back(stl_curvatures[2 * b + 1]);
      _param.CURV.push_back(stl_curvatures[2 * c]);
      _param.CURV.push_back(stl_curvatures[2 * c + 1]);
    }
  }
  if(_param.checkPlanar())
    Msg::Info("Discrete surface %d is planar, simplifying parametrization",
              tag());

  std::vector<MElement *> temp;
  for(size_t j = 0; j < _param.t2d.size(); j++) {
    temp.push_back(&_param.t2d[j]);
    double MIN[3] = {_param.t3d[j].getVertex(0)->x(),
                     _param.t3d[j].getVertex(0)->y(),
                     _param.t3d[j].getVertex(0)->z()};
    double MAX[3] = {_param.t3d[j].getVertex(0)->x(),
                     _param.t3d[j].getVertex(0)->y(),
                     _param.t3d[j].getVertex(0)->z()};
    for(int k = 1; k < 3; k++) {
      MAX[0] = std::max(MAX[0], _param.t3d[j].getVertex(k)->x());
      MIN[0] = std::min(MIN[0], _param.t3d[j].getVertex(k)->x());
      MAX[1] = std::max(MAX[1], _param.t3d[j].getVertex(k)->y());
      MIN[1] = std::min(MIN[1], _param.t3d[j].getVertex(k)->y());
      MAX[2] = std::max(MAX[2], _param.t3d[j].getVertex(k)->z());
      MIN[2] = std::min(MIN[2], _param.t3d[j].getVertex(k)->z());
    }
    _param.rtree3dData.push_back
      (new std::pair<MTriangle *, MTriangle *>(&_param.t3d[j], &_param.t2d[j]));
    _param.rtree3d.Insert(MIN, MAX, _param.rtree3dData.back());
  }
  _param.oct = new MElementOctree(temp);
}

void discreteFace::mesh(bool verbose)
{
  if(_param.empty()) return;
  GFace::mesh(verbose);
}

GPoint discreteFace::intersectionWithCircle(const SVector3 &n1,
                                            const SVector3 &n2,
                                            const SVector3 &p, const double &R,
                                            double uv[2])
{
  if(_param.empty()) return 0.;

  MTriangle *t2d = (MTriangle *)_param.oct->find(uv[0], uv[1], 0.0, -1, true);
  MTriangle *t3d = nullptr;
  if(t2d) {
    int position = (int)(t2d - &_param.t2d[0]);
    t3d = &_param.t3d[position];
  }

  SVector3 n = crossprod(n1, n2);
  n.normalize();

  int N = _param.t3d.size();
  int start = 0;
  if(t2d) start = -1;
  for(int i = start; i < N; i++) {
    if(i >= 0) {
      t2d = &_param.t2d[i];
      t3d = &_param.t3d[i];
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

  GPoint pp(0);
  pp.setNoSuccess();
  // Msg::Warning("Could not intersect with circle");
  return pp;
}

bool discreteFace::writeParametrization(FILE *fp, bool binary)
{
  std::size_t N = stl_vertices_uv.size();
  std::size_t T = stl_triangles.size() / 3;
  std::vector<double> d(11 * N, 0.);
  for(std::size_t i = 0; i < N; i++) {
    d[11 * i + 0] = stl_vertices_xyz[i].x();
    d[11 * i + 1] = stl_vertices_xyz[i].y();
    d[11 * i + 2] = stl_vertices_xyz[i].z();
    d[11 * i + 3] = stl_vertices_uv[i].x();
    d[11 * i + 4] = stl_vertices_uv[i].y();
    if(stl_curvatures.size() == 2 * stl_vertices_uv.size()) {
      d[11 * i + 5] = stl_curvatures[2 * i].x();
      d[11 * i + 6] = stl_curvatures[2 * i].y();
      d[11 * i + 7] = stl_curvatures[2 * i].z();
      d[11 * i + 8] = stl_curvatures[2 * i + 1].x();
      d[11 * i + 9] = stl_curvatures[2 * i + 1].y();
      d[11 * i + 10] = stl_curvatures[2 * i + 1].z();
    }
  }
  if(binary) {
    fwrite(&N, sizeof(std::size_t), 1, fp);
    fwrite(&T, sizeof(std::size_t), 1, fp);
    fwrite(&d[0], sizeof(double), d.size(), fp);
    fwrite(&stl_triangles[0], sizeof(int), stl_triangles.size(), fp);
  }
  else {
    fprintf(fp, "%lu %lu\n", N, T);
    for(std::size_t i = 0; i < N; i++)
      fprintf(fp,
              "%.16g %.16g %.16g %.16g %.16g %.16g %.16g "
              "%.16g %.16g %.16g %.16g\n",
              d[11 * i + 0], d[11 * i + 1], d[11 * i + 2], d[11 * i + 3],
              d[11 * i + 4], d[11 * i + 5], d[11 * i + 6], d[11 * i + 7],
              d[11 * i + 8], d[11 * i + 9], d[11 * i + 10]);
    for(std::size_t i = 0; i < T; i++) {
      fprintf(fp, "%d %d %d\n", stl_triangles[3 * i + 0],
              stl_triangles[3 * i + 1], stl_triangles[3 * i + 2]);
    }
  }
  return true;
}

bool discreteFace::readParametrization(FILE *fp, bool binary)
{
  stl_vertices_xyz.clear();
  stl_vertices_uv.clear();
  stl_curvatures.clear();
  stl_triangles.clear();

  std::size_t N, T;
  if(binary) {
    if(fread(&N, sizeof(std::size_t), 1, fp) != 1) { return false; }
    if(fread(&T, sizeof(std::size_t), 1, fp) != 1) { return false; }
  }
  else {
    if(fscanf(fp, "%lu %lu", &N, &T) != 2) { return false; }
  }
  std::vector<double> d(11 * N);
  stl_vertices_xyz.resize(N);
  stl_vertices_uv.resize(N);
  stl_curvatures.resize(2 * N);
  stl_triangles.resize(3 * T);

  if(binary) {
    if(fread(&d[0], sizeof(double), 11 * N, fp) != 11 * N) { return false; }
    if(fread(&stl_triangles[0], sizeof(int), 3 * T, fp) != 3 * T) {
      return false;
    }
  }
  else {
    for(std::size_t i = 0; i < N; i++) {
      if(fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                &d[11 * i + 0], &d[11 * i + 1], &d[11 * i + 2], &d[11 * i + 3],
                &d[11 * i + 4], &d[11 * i + 5], &d[11 * i + 6], &d[11 * i + 7],
                &d[11 * i + 8], &d[11 * i + 9], &d[11 * i + 10]) != 11) {
        return false;
      }
    }
    for(std::size_t i = 0; i < T; i++) {
      if(fscanf(fp, "%d %d %d", &stl_triangles[3 * i + 0],
                &stl_triangles[3 * i + 1], &stl_triangles[3 * i + 2]) != 3) {
        return false;
      }
    }
  }

  for(std::size_t i = 0; i < N; i++) {
    stl_vertices_xyz[i] = SPoint3(d[11 * i + 0], d[11 * i + 1], d[11 * i + 2]);
    stl_vertices_uv[i] = SPoint2(d[11 * i + 3], d[11 * i + 4]);
    stl_curvatures[2 * i + 0] =
      SVector3(d[11 * i + 5], d[11 * i + 6], d[11 * i + 7]);
    stl_curvatures[2 * i + 1] =
      SVector3(d[11 * i + 8], d[11 * i + 9], d[11 * i + 10]);
  }

  _computeSTLNormals();
  _createGeometryFromSTL();
  return true;
}

void discreteFace::resetMeshAttributes()
{
  Surface *_s = FindSurface(tag());
  if(!_s) {
    GFace ::resetMeshAttributes();
    return;
  }
  meshAttributes.recombine = _s->Recombine;
  meshAttributes.recombineAngle = _s->RecombineAngle;
  meshAttributes.method = _s->Method;
  meshAttributes.extrude = _s->Extrude;
  if(meshAttributes.method == MESH_TRANSFINITE) {
    meshAttributes.transfiniteArrangement = _s->Recombine_Dir;
    meshAttributes.transfiniteSmoothing = _s->TransfiniteSmoothing;
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(_s->TrsfPoints); i++) {
      Vertex *corn;
      List_Read(_s->TrsfPoints, i, &corn);
      GVertex *gv = model()->getVertexByTag(corn->Num);
      if(gv)
        meshAttributes.corners.push_back(gv);
      else
        Msg::Error("Unknown point %d in transfinite attributes", corn->Num);
    }
  }
  meshAttributes.reverseMesh = _s->ReverseMesh;
  meshAttributes.algorithm = _s->MeshAlgorithm;
  meshAttributes.meshSizeFromBoundary = _s->MeshSizeFromBoundary;
  meshAttributes.transfinite3 = false;
}

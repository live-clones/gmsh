// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Tristan Carrier and Paul-Emile Bernard

#include "pointInsertionRTreeTools.h"
#include "BackgroundMesh.h"
#include "BackgroundMeshManager.h"
#include "pointInsertion.h"
#include "GEntity.h"
#include "fullMatrix.h"

surfacePointWithExclusionRegion::surfacePointWithExclusionRegion(MVertex *v, SPoint2 p[8], SPoint2 &_mp, SMetric3 &meshMetric,
								 surfacePointWithExclusionRegion *father)
{
  _v = v;
  _meshMetric = meshMetric;
  _center = _mp;
  for(int i = 0; i < 4; i++){
    _q[i] = _center + (p[i] + p[(i + 1) % 4] - _center * 2) * FACTOR;
    //    printf("%g %g vs %g %g\n",_q[i].x(),_q[i].y(),p[i+4].x(),p[i+4].y());
    //    _q[i] = p[i+4];
  }
  for(int i = 0; i < 4; i++)_p[i] = p[i];

  if(!father) {
    _father = NULL;
  }
  else {
    _father = father->_v;
  }
}

bool surfacePointWithExclusionRegion::inExclusionZone(const SPoint2 &p, MVertex *parent)
{
  if (_father == parent) {
    //    printf("parent = me\n");
    return false;
  }

  double mat[2][2];
  double b[2], uv[2];
  mat[0][0] = _q[1].x() - _q[0].x();
  mat[0][1] = _q[2].x() - _q[0].x();
  mat[1][0] = _q[1].y() - _q[0].y();
  mat[1][1] = _q[2].y() - _q[0].y();
  b[0] = p.x() - _q[0].x();
  b[1] = p.y() - _q[0].y();
  sys2x2(mat, b, uv);
  //    printf("inversion 1 : %g %g \n",uv[0],uv[1]);
  if(uv[0] >= 0 && uv[1] >= 0 && 1. - uv[0] - uv[1] >= 0) return true;
  mat[0][0] = _q[3].x() - _q[2].x();
  mat[0][1] = _q[0].x() - _q[2].x();
  mat[1][0] = _q[3].y() - _q[2].y();
  mat[1][1] = _q[0].y() - _q[2].y();
  b[0] = p.x() - _q[2].x();
  b[1] = p.y() - _q[2].y();
  sys2x2(mat, b, uv);
  //    printf("inversion 2 : %g %g \n",uv[0],uv[1]);
  if(uv[0] >= 0 && uv[1] >= 0 && 1. - uv[0] - uv[1] >= 0) return true;
  return false;
}

void surfacePointWithExclusionRegion::minmax(double _min[2],
                                             double _max[2]) const
{
  _min[0] =
    std::min(std::min(std::min(_q[0].x(), _q[1].x()), _q[2].x()), _q[3].x());
  _min[1] =
    std::min(std::min(std::min(_q[0].y(), _q[1].y()), _q[2].y()), _q[3].y());
  _max[0] =
    std::max(std::max(std::max(_q[0].x(), _q[1].x()), _q[2].x()), _q[3].x());
  _max[1] =
    std::max(std::max(std::max(_q[0].y(), _q[1].y()), _q[2].y()), _q[3].y());
}

void surfacePointWithExclusionRegion::print(FILE *f, int i)
{
  //  fprintf(f, "SP(%g,%g,%g){%d};\n", _v->x(), _v->y(), _v->z(), i);
  //  return;
  fprintf(f, "SP(%g,%g,%g){%d};\n", _v->x(), _v->y(), _v->z(), i);
  //  fprintf(f, "SP(%g,%g,%g){%d};\n", _center.x(), _center.y(), 0.0, i);
  fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
	  _q[0].x(), _q[0].y(), 0.0, _q[1].x(), _q[1].y(), 0.0, _q[2].x(),
          _q[2].y(), 0.0, _q[3].x(), _q[3].y(), 0.0, i, i, i, i);

}

bool rtree_callback(surfacePointWithExclusionRegion *neighbour, void *point)
{
  my_wrapper *w = static_cast<my_wrapper *>(point);

  if(neighbour->inExclusionZone(w->_p, w->_parent)) {
    w->_tooclose = true;
    return false;
  }
  return true;
}

bool inExclusionZone(
  MVertex *parent,
  SPoint2 &p,
  RTree<surfacePointWithExclusionRegion *, double, 2, double> &rtree)
{
  my_wrapper w(p, parent);
  double _min[2] = {p.x() - 1.e-1, p.y() - 1.e-1},
         _max[2] = {p.x() + 1.e-1, p.y() + 1.e-1};
  rtree.Search(_min, _max, rtree_callback, &w);

  return w._tooclose;
}

frameFieldBackgroundMesh3D *Wrapper3D::bgmesh = NULL;

double infinity_distance_3D(const MVertex *v1, const MVertex *v2, STensor3 &cf)
{
  SPoint3 p1 = v1->point();
  SPoint3 p2 = v2->point();
  double x1 = 0.;
  double y1 = 0.;
  double z1 = 0.;
  double x2 = 0.;
  double y2 = 0.;
  double z2 = 0.;
  for(int i = 0; i < 3; i++) {
    x1 += cf(i, 0) * p1[i];
    y1 += cf(i, 1) * p1[i];
    z1 += cf(i, 2) * p1[i];
  }
  for(int i = 0; i < 3; i++) {
    x2 += cf(i, 0) * p2[i];
    y2 += cf(i, 1) * p2[i];
    z2 += cf(i, 2) * p2[i];
  }
  return std::max(std::max(fabs(x2 - x1), fabs(y2 - y1)),
                  fabs(z2 - z1)); // distance
};

void fill_min_max(double x, double y, double z, double h, double *min,
                  double *max)
{
  min[0] = x - sqrt3 * h;
  max[0] = x + sqrt3 * h;
  min[1] = y - sqrt3 * h;
  max[1] = y + sqrt3 * h;
  min[2] = z - sqrt3 * h;
  max[2] = z + sqrt3 * h;
};

bool rtree_callback_3D(MVertex *neighbour, void *w)
{
  Wrapper3D *wrapper;
  wrapper = static_cast<Wrapper3D *>(w);
  const MVertex *individual = wrapper->get_individual();
  const MVertex *parent = wrapper->get_parent();
  if(parent == neighbour) return true;
  // frameFieldBackgroundMesh3D* bgm = wrapper->bgm();
  // const MVertex *closest = bgm->get_nearest_neighbor(individual);
  // const double h = bgm->size(closest);// get approximate size, closest
  // vertex, faster ?! STensor3 crossfield;
  // bgm->eval_approximate_crossfield(closest, crossfield);
  double *h = wrapper->get_size();
  STensor3 *crossfield = wrapper->get_crossfield();

  const double distance =
    infinity_distance_3D(individual, neighbour, (*crossfield));
  if(distance < k1 * (*h)) {
    wrapper->set_ok(false);
    return false;
  }
  return true;
};

bool far_from_boundary_3D(frameFieldBackgroundMesh3D *bgm, MVertex *v, double h)
{
  // check if the box (v->point +- k2*h) is in domain

  const double x = v->x();
  const double y = v->y();
  const double z = v->z();
  const double boxsize = k2 * h;
  if(!(bgm->inDomain(x + boxsize, y, z))) return false;
  if(!(bgm->inDomain(x - boxsize, y, z))) return false;
  if(!(bgm->inDomain(x, y + boxsize, z))) return false;
  if(!(bgm->inDomain(x, y - boxsize, z))) return false;
  if(!(bgm->inDomain(x, y, z + boxsize))) return false;
  if(!(bgm->inDomain(x, y, z - boxsize))) return false;

  return true;
};

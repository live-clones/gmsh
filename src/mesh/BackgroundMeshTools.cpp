// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "BackgroundMeshTools.h"
#include "GFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GEntity.h"
#include "Context.h"
#include "Field.h"
#include "GModel.h"

static double max_surf_curvature(const GEdge *ge, double u)
{
  double val = 0;
  std::vector<GFace *> faces = ge->faces();
  auto it = faces.begin();
  while(it != faces.end()) {
    SPoint2 par = ge->reparamOnFace((*it), u, 1);
    double cc = (*it)->curvatureMax(par);
    val = std::max(cc, val);
    ++it;
  }
  return val;
}

static double max_edge_curvature(const GVertex *gv)
{
  double val = 0;
  std::vector<GEdge *> const &l_edges = gv->edges();
  for(auto ite = l_edges.begin(); ite != l_edges.end(); ++ite) {
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);
    double t = (gv == _myGEdge->getBeginVertex()) ? range.low() : range.high();
    double EC = _myGEdge->curvature(t);
    double FC = max_surf_curvature(_myGEdge, t);
    val = std::max(std::max(val, EC), FC);
  }
  return val;
}

// the mesh vertex is classified on a model vertex.  we compute the maximum of
// the curvature of model faces surrounding this point if it is classified on a
// model edge, we do the same for all model faces surrounding it if it is on a
// model face, we compute the curvature at this location
static double LC_MVertex_CURV(GEntity *ge, double U, double V)
{
  double Crv = 0;
  switch(ge->dim()) {
  case 0:
    Crv = max_edge_curvature((const GVertex *)ge);
    // Crv = std::max(max_surf_curvature_vertex((const GVertex *)ge), Crv);
    // Crv = max_surf_curvature((const GVertex *)ge);
    break;
  case 1: {
    GEdge *ged = (GEdge *)ge;
    Crv = ged->curvature(U);
    Crv = std::max(Crv, max_surf_curvature(ged, U));
  } break;
  case 2: {
    GFace *gf = (GFace *)ge;
    Crv = gf->curvatureMax(SPoint2(U, V));
  } break;
  }
  double ne = CTX::instance()->mesh.lcFromCurvature;
  if(ne < 1) {
    Msg::Warning("Invalid number of elements per 2*pi curvature %g", ne);
    ne = 1;
  }
  double lc = Crv > 0 ? 2 * M_PI / Crv / ne : MAX_LC;
  return lc;
}

SMetric3 max_edge_curvature_metric(const GEdge *ge, double u)
{
  SVector3 t = ge->firstDer(u);
  t.normalize();
  double ne = CTX::instance()->mesh.lcFromCurvature;
  if(ne < 1) {
    Msg::Warning("Invalid number of elements per 2*pi curvature %g", ne);
    ne = 1;
  }
  double l_t = (2 * M_PI) / (fabs(ge->curvature(u)) * ne);
  double l_n = 1.e12;
  return buildMetricTangentToCurve(t, l_t, l_n);
}

static SMetric3 metric_based_on_surface_curvature(const GEdge *ge, double u,
                                                  bool iso_surf)
{
  SMetric3 mesh_size(1.e-12);
  std::vector<GFace *> faces = ge->faces();
  auto it = faces.begin();
  // we choose the metric eigenvectors to be the ones
  // related to the edge ...
  SMetric3 curvMetric = max_edge_curvature_metric(ge, u);
  while(it != faces.end()) {
    SPoint2 par = ge->reparamOnFace((*it), u, 1);
    SMetric3 m =
      metric_based_on_surface_curvature(*it, par.x(), par.y(), iso_surf);
    curvMetric = intersection_conserveM1(curvMetric, m);
    ++it;
  }
  return curvMetric;
}

static SMetric3 metric_based_on_surface_curvature(const GVertex *gv,
                                                  bool iso_surf)
{
  SMetric3 mesh_size(1.e-15);
  return mesh_size;
}

SMetric3 LC_MVertex_CURV_ANISO(GEntity *ge, double U, double V)
{
  bool iso_surf = CTX::instance()->mesh.lcFromCurvatureIso;

  switch(ge->dim()) {
  case 0:
    return metric_based_on_surface_curvature((const GVertex *)ge, iso_surf);
  case 1:
    return metric_based_on_surface_curvature((const GEdge *)ge, U, iso_surf);
  case 2:
    return metric_based_on_surface_curvature((const GFace *)ge, U, V, iso_surf);
  }
  Msg::Error("Curvature control impossible to compute for a volume");
  return SMetric3();
}

// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
static double LC_MVertex_PNTS(GEntity *ge, double U, double V)
{
  switch(ge->dim()) {
  case 0: {
    GVertex *gv = (GVertex *)ge;
    double lc = gv->prescribedMeshSizeAtVertex();
    // FIXME we might want to remove this to make all lc treatment consistent
    if(lc >= MAX_LC) return CTX::instance()->lc / 10.;
    return lc;
  }
  case 1: {
    GEdge *ged = (GEdge *)ge;
    GVertex *v1 = ged->getBeginVertex();
    GVertex *v2 = ged->getEndVertex();
    if(v1 && v2) {
      double lc1 = v1->prescribedMeshSizeAtVertex();
      double lc2 = v2->prescribedMeshSizeAtVertex();
      if(lc1 >= MAX_LC && lc2 >= MAX_LC) {
        // FIXME we might want to remove this to make all lc treatment
        // consistent
        return CTX::instance()->lc / 10.;
      }
      else {
        Range<double> range = ged->parBounds(0);
        double a = (U - range.low()) / (range.high() - range.low());
        return (1 - a) * lc1 + (a)*lc2;
      }
    }
    else
      return MAX_LC;
  }
  default: return MAX_LC;
  }
}

SMetric3 buildMetricTangentToCurve(SVector3 &t, double l_t, double l_n)
{
  if(l_t == 0.0) return SMetric3(1.e-22);
  SVector3 a;
  if(fabs(t(0)) <= fabs(t(1)) && fabs(t(0)) <= fabs(t(2))) {
    a = SVector3(1, 0, 0);
  }
  else if(fabs(t(1)) <= fabs(t(0)) && fabs(t(1)) <= fabs(t(2))) {
    a = SVector3(0, 1, 0);
  }
  else {
    a = SVector3(0, 0, 1);
  }
  SVector3 b = crossprod(t, a);
  SVector3 c = crossprod(b, t);
  b.normalize();
  c.normalize();
  t.normalize();
  SMetric3 Metric(1. / (l_t * l_t), 1. / (l_n * l_n), 1. / (l_n * l_n), t, b,
                  c);
  //  printf("bmttc %g %g %g %g
  //  %g\n",l_t,l_n,Metric(0,0),Metric(0,1),Metric(1,1));
  return Metric;
}

SMetric3 buildMetricTangentToSurface(SVector3 &t1, SVector3 &t2, double l_t1,
                                     double l_t2, double l_n)
{
  t1.normalize();
  t2.normalize();
  SVector3 n = crossprod(t1, t2);
  n.normalize();

  l_t1 = std::max(l_t1, CTX::instance()->mesh.lcMin);
  l_t2 = std::max(l_t2, CTX::instance()->mesh.lcMin);
  l_t1 = std::min(l_t1, CTX::instance()->mesh.lcMax);
  l_t2 = std::min(l_t2, CTX::instance()->mesh.lcMax);
  SMetric3 Metric(1. / (l_t1 * l_t1), 1. / (l_t2 * l_t2), 1. / (l_n * l_n), t1,
                  t2, n);
  return Metric;
}

double BGM_MeshSizeWithoutScaling(GEntity *ge, double U, double V, double X,
                                  double Y, double Z)
{
  // lc from points
  double l1 = MAX_LC;
  if(ge && CTX::instance()->mesh.lcFromPoints && ge->dim() < 2)
    l1 = LC_MVertex_PNTS(ge, U, V);

  // lc from curvature
  double l2 = MAX_LC;
  if(ge && CTX::instance()->mesh.lcFromCurvature > 0 && ge->dim() < 3)
    l2 = LC_MVertex_CURV(ge, U, V);

  // lc from fields
  double l3 = MAX_LC;
  if(ge) {
    FieldManager *fields = ge->model()->getFields();
    if(fields->getBackgroundField() > 0) {
      Field *f = fields->get(fields->getBackgroundField());
      if(f) l3 = (*f)(X, Y, Z, ge);
    }
  }

  // global lc from entity
  double l4 = ge ? ge->getMeshSize() : MAX_LC;

  double l5 = (ge && ge->dim() == 1) ?
                ((GEdge *)ge)->prescribedMeshSizeAtParam(U) :
                MAX_LC;

  // take the minimum
  double lc = std::min(std::min(std::min(std::min(l1, l2), l3), l4), l5);

  // lc from callback
  if(GModel::current()->lcCallback) {
    int dim = (ge ? ge->dim() : -1);
    int tag = (ge ? ge->tag() : -1);
    lc = GModel::current()->lcCallback(dim, tag, X, Y, Z, lc);
  }

  return lc;
}

// This is the only function that is used by the meshers
double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y,
                    double Z)
{
  if(!ge) Msg::Warning("No entity in background mesh size evaluation");

  // default size to size of model
  double lc = CTX::instance()->lc;

  // min of all sizes
  lc = std::min(lc, BGM_MeshSizeWithoutScaling(ge, U, V, X, Y, Z));

  // constrain by lcMin and lcMax
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);

  if(lc <= 0.) {
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)", lc,
               CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = CTX::instance()->lc;
  }

  // size factor from entity
  if(ge && ge->getMeshSizeFactor() != 1.0) lc *= ge->getMeshSizeFactor();

  // global size factor
  return lc * CTX::instance()->mesh.lcFactor;
}

// anisotropic version of the background field
SMetric3 BGM_MeshMetric(GEntity *ge, double U, double V, double X, double Y,
                        double Z)
{
  // default size to size of model
  double lc = CTX::instance()->lc;

  // lc from points
  if(CTX::instance()->mesh.lcFromPoints && ge->dim() < 2)
    lc = std::min(lc, LC_MVertex_PNTS(ge, U, V));

  // global lc from entity
  lc = std::min(lc, ge->getMeshSize());

  // constrain by global min/max
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);

  if(lc <= 0.) {
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)", lc,
               CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = CTX::instance()->lc;
  }

  // isotropic base metric
  SMetric3 m0(1. / (lc * lc));

  // intersect with metrics from fields if applicable
  FieldManager *fields = ge->model()->getFields();
  SMetric3 m1 = m0;
  if(fields->getBackgroundField() > 0) {
    Field *f = fields->get(fields->getBackgroundField());
    if(f) {
      SMetric3 l4;
      if(!f->isotropic()) { (*f)(X, Y, Z, l4, ge); }
      else {
        const double L = (*f)(X, Y, Z, ge);
        l4 = SMetric3(1 / (L * L));
      }
      m1 = intersection(l4, m0);
    }
  }

  // intersect with metrics from curvature if applicable
  SMetric3 m = (CTX::instance()->mesh.lcFromCurvature > 0 && ge->dim() < 3) ?
                 intersection(m1, LC_MVertex_CURV_ANISO(ge, U, V)) :
                 m1;

  // apply global size factor
  if(CTX::instance()->mesh.lcFactor != 0 &&
     CTX::instance()->mesh.lcFactor != 1.)
    m *= 1. / (CTX::instance()->mesh.lcFactor * CTX::instance()->mesh.lcFactor);

  return m;
}

bool Extend1dMeshIn2dSurfaces(GFace *gf)
{
  int val = gf->getMeshSizeFromBoundary();
  return (val > 0 || val == -2);
}

bool Extend2dMeshIn3dVolumes()
{
  int val = CTX::instance()->mesh.lcExtendFromBoundary;
  return (val > 0 || val == -3);
}

SMetric3 max_edge_curvature_metric(const GVertex *gv)
{
  SMetric3 val(1.e-12);
  std::vector<GEdge *> const &l_edges = gv->edges();
  for(auto ite = l_edges.begin(); ite != l_edges.end(); ++ite) {
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);
    SMetric3 cc;
    double ne = CTX::instance()->mesh.lcFromCurvature;
    if(ne < 1) {
      Msg::Warning("Invalid number of elements per 2*pi curvature %g", ne);
      ne = 1;
    }
    if(gv == _myGEdge->getBeginVertex()) {
      SVector3 t = _myGEdge->firstDer(range.low());
      t.normalize();
      double l_t = 2 * M_PI / (fabs(_myGEdge->curvature(range.low())) * ne);
      double l_n = 1.e12;
      cc = buildMetricTangentToCurve(t, l_t, l_n);
    }
    else {
      SVector3 t = _myGEdge->firstDer(range.high());
      t.normalize();
      double l_t = 2 * M_PI / (fabs(_myGEdge->curvature(range.high())) * ne);
      double l_n = 1.e12;
      cc = buildMetricTangentToCurve(t, l_t, l_n);
    }
    val = intersection(val, cc);
  }
  return val;
}

SMetric3 metric_based_on_surface_curvature(const GFace *gf, double u, double v,
                                           bool surface_isotropic,
                                           double d_normal,
                                           double d_tangent_max)
{
  if(gf->geomType() == GEntity::Plane) return SMetric3(1.e-12);
  double cmax, cmin;
  SVector3 dirMax, dirMin;
  cmax = gf->curvatures(SPoint2(u, v), dirMax, dirMin, cmax, cmin);
  if(cmin == 0) cmin = 1.e-12;
  if(cmax == 0) cmax = 1.e-12;
  double ne = CTX::instance()->mesh.lcFromCurvature;
  if(ne < 1) {
    Msg::Warning("Invalid number of elements per 2*pi curvature %g", ne);
    ne = 1;
  }
  double lambda1 = 2 * M_PI / (fabs(cmin) * ne);
  double lambda2 = 2 * M_PI / (fabs(cmax) * ne);
  SVector3 Z = crossprod(dirMax, dirMin);
  if(surface_isotropic) lambda2 = lambda1 = std::min(lambda2, lambda1);
  dirMin.normalize();
  dirMax.normalize();
  Z.normalize();
  lambda1 = std::max(lambda1, CTX::instance()->mesh.lcMin);
  lambda2 = std::max(lambda2, CTX::instance()->mesh.lcMin);
  lambda1 = std::min(lambda1, CTX::instance()->mesh.lcMax);
  lambda2 = std::min(lambda2, CTX::instance()->mesh.lcMax);
  double lambda3 = std::min(d_normal, CTX::instance()->mesh.lcMax);
  lambda3 = std::max(lambda3, CTX::instance()->mesh.lcMin);
  lambda1 = std::min(lambda1, d_tangent_max);
  lambda2 = std::min(lambda2, d_tangent_max);

  SMetric3 curvMetric(1. / (lambda1 * lambda1), 1. / (lambda2 * lambda2),
                      1. / (lambda3 * lambda3), dirMin, dirMax, Z);
  return curvMetric;
}

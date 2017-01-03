// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "BackgroundMeshTools.h"
#include "GFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GEdgeCompound.h"
#include "GEntity.h"
#include "Context.h"
#include "Field.h"
#include "GModel.h"

static double max_surf_curvature(const GEdge *ge, double u)
{
  double val = 0;
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  while(it != faces.end()){
    if ((*it)->geomType() != GEntity::CompoundSurface &&
        (*it)->geomType() != GEntity::DiscreteSurface){
      SPoint2 par = ge->reparamOnFace((*it), u, 1);
      double cc = (*it)->curvature(par);
      val = std::max(cc, val);
    }
    ++it;
  }
  return val;
}

static double max_edge_curvature(const GVertex *gv)
{
  double val = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin();
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);
    double cc;
    if (gv == _myGEdge->getBeginVertex()) cc = _myGEdge->curvature(range.low());
    else cc = _myGEdge->curvature(range.high());
    val = std::max(val, cc);
  }
  return val;
}

// the mesh vertex is classified on a model vertex.  we compute the
// maximum of the curvature of model faces surrounding this point if
// it is classified on a model edge, we do the same for all model
// faces surrounding it if it is on a model face, we compute the
// curvature at this location

static double LC_MVertex_CURV(GEntity *ge, double U, double V)
{
  double Crv = 0;
  switch(ge->dim()){
  case 0:
    Crv = max_edge_curvature((const GVertex *)ge);
    //Crv = std::max(max_surf_curvature_vertex((const GVertex *)ge), Crv);
    // Crv = max_surf_curvature((const GVertex *)ge);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      Crv = ged->curvature(U);
      Crv = std::max(Crv, max_surf_curvature(ged, U));
      //      printf("%g %d\n",Crv, CTX::instance()->mesh.minCircPoints);
      // Crv = max_surf_curvature(ged, U);
    }
    break;
  case 2:
    {
      GFace *gf = (GFace *)ge;
      Crv = gf->curvature(SPoint2(U, V));
    }
    break;
  }
  double lc = Crv > 0 ? 2 * M_PI / Crv / CTX::instance()->mesh.minCircPoints : MAX_LC;
  return lc;
}

SMetric3 max_edge_curvature_metric(const GEdge *ge, double u)
{
  SVector3 t =  ge->firstDer(u);
  t.normalize();
  double l_t = ((2 * M_PI) /( fabs(ge->curvature(u))
			      *  CTX::instance()->mesh.minCircPoints ));
  double l_n = 1.e12;
  return buildMetricTangentToCurve(t,l_t,l_n);
}

static SMetric3 metric_based_on_surface_curvature(const GEdge *ge, double u, bool iso_surf)
{
  const GEdgeCompound* ptrCompoundEdge = dynamic_cast<const GEdgeCompound*>(ge);
  if (ptrCompoundEdge){
    double cmax, cmin;
    SVector3 dirMax,dirMin;
    cmax = ptrCompoundEdge->curvatures(u,&dirMax, &dirMin, &cmax,&cmin);
    if (cmin == 0)cmin =1.e-12;
    if (cmax == 0)cmax =1.e-12;
    double lambda2 =  ((2 * M_PI) /( fabs(cmax) *  CTX::instance()->mesh.minCircPoints ) );
    double lambda1 =  ((2 * M_PI) /( fabs(cmin) *  CTX::instance()->mesh.minCircPoints ) );
    SVector3 Z = crossprod(dirMax,dirMin);

    lambda1 = std::max(lambda1, CTX::instance()->mesh.lcMin);
    lambda2 = std::max(lambda2, CTX::instance()->mesh.lcMin);
    lambda1 = std::min(lambda1, CTX::instance()->mesh.lcMax);
    lambda2 = std::min(lambda2, CTX::instance()->mesh.lcMax);

    SMetric3 curvMetric (1. / (lambda1 * lambda1), 1. / (lambda2 * lambda2),
                         1.e-12, dirMin, dirMax, Z);
    return curvMetric;
  }
  else{
    SMetric3 mesh_size(1.e-12);
    std::list<GFace *> faces = ge->faces();
    std::list<GFace *>::iterator it = faces.begin();
    // we choose the metric eigenvectors to be the ones
    // related to the edge ...
    SMetric3 curvMetric = max_edge_curvature_metric(ge, u);
    while(it != faces.end()){
      if (((*it)->geomType() != GEntity::CompoundSurface) &&
          ((*it)->geomType() != GEntity::DiscreteSurface)){
        SPoint2 par = ge->reparamOnFace((*it), u, 1);
        SMetric3 m = metric_based_on_surface_curvature (*it, par.x(), par.y(), iso_surf);
        curvMetric = intersection_conserveM1(curvMetric,m);
      }
      ++it;
    }

    return curvMetric;
  }
}

static SMetric3 metric_based_on_surface_curvature(const GVertex *gv, bool iso_surf)
{
  SMetric3 mesh_size(1.e-15);
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin();
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> bounds = _myGEdge->parBounds(0);

    // ES: Added extra if condition to use the code below only with compund curves
    // This is because we want to call the function
    // metric_based_on_surface_curvature(const GEdge *ge, double u) for the case when
    // ge is a compound edge
    if (_myGEdge->geomType() == GEntity::CompoundCurve){
      if (gv == _myGEdge->getBeginVertex())
        mesh_size = intersection
          (mesh_size,
           metric_based_on_surface_curvature(_myGEdge, bounds.low(), iso_surf));
      else
        mesh_size = intersection
          (mesh_size,
           metric_based_on_surface_curvature(_myGEdge, bounds.high(), iso_surf));
    }
  }
  return mesh_size;
}

SMetric3 LC_MVertex_CURV_ANISO(GEntity *ge, double U, double V)
{
  bool iso_surf = CTX::instance()->mesh.lcFromCurvature == 2;

  switch(ge->dim()){
  case 0: return metric_based_on_surface_curvature((const GVertex *)ge, iso_surf);
  case 1: return metric_based_on_surface_curvature((const GEdge *)ge, U, iso_surf);
  case 2: return metric_based_on_surface_curvature((const GFace *)ge, U, V, iso_surf);
  }
  Msg::Error("Curvature control impossible to compute for a volume!");
  return SMetric3();
}

// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
static double LC_MVertex_PNTS(GEntity *ge, double U, double V)
{
  switch(ge->dim()){
  case 0:
    {
      GVertex *gv = (GVertex *)ge;
      double lc = gv->prescribedMeshSizeAtVertex();
      // FIXME we might want to remove this to make all lc treatment consistent
      if(lc >= MAX_LC) return CTX::instance()->lc / 10.;
      return lc;
    }
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      GVertex *v1 = ged->getBeginVertex();
      GVertex *v2 = ged->getEndVertex();
      if (v1 && v2){
        double lc1 = v1->prescribedMeshSizeAtVertex();
        double lc2 = v2->prescribedMeshSizeAtVertex();
        if (lc1 >= MAX_LC && lc2 >= MAX_LC){
          // FIXME we might want to remove this to make all lc treatment consistent
          return CTX::instance()->lc / 10.;
        }
        else{
        Range<double> range = ged->parBounds(0);
        double a = (U - range.low()) / (range.high() - range.low());
          return (1 - a) * lc1 + (a)* lc2;
      }
      }
      else
        return MAX_LC;
    }
  default:
    return MAX_LC;
  }
}

SMetric3 buildMetricTangentToCurve(SVector3 &t, double l_t, double l_n)
{
  if (l_t == 0.0) return SMetric3(1.e-22);
  SVector3 a;
  if (fabs(t(0)) <= fabs(t(1)) && fabs(t(0)) <= fabs(t(2))){
    a = SVector3(1,0,0);
  }
  else if (fabs(t(1)) <= fabs(t(0)) && fabs(t(1)) <= fabs(t(2))){
    a = SVector3(0,1,0);
  }
  else{
    a = SVector3(0,0,1);
  }
  SVector3 b = crossprod (t,a);
  SVector3 c = crossprod (b,t);
  b.normalize();
  c.normalize();
  t.normalize();
  SMetric3 Metric (1./(l_t*l_t),1./(l_n*l_n),1./(l_n*l_n),t,b,c);
  //  printf("bmttc %g %g %g %g %g\n",l_t,l_n,Metric(0,0),Metric(0,1),Metric(1,1));
  return Metric;
}

SMetric3 buildMetricTangentToSurface(SVector3 &t1, SVector3 &t2,
                                     double l_t1, double l_t2, double l_n)
{
  t1.normalize();
  t2.normalize();
  SVector3 n = crossprod (t1,t2);
  n.normalize();

  l_t1 = std::max(l_t1, CTX::instance()->mesh.lcMin);
  l_t2 = std::max(l_t2, CTX::instance()->mesh.lcMin);
  l_t1 = std::min(l_t1, CTX::instance()->mesh.lcMax);
  l_t2 = std::min(l_t2, CTX::instance()->mesh.lcMax);
  SMetric3 Metric (1./(l_t1*l_t1),1./(l_t2*l_t2),1./(l_n*l_n),t1,t2,n);
  return Metric;
}

// This is the only function that is used by the meshers
double BGM_MeshSize(GEntity *ge, double U, double V,
                    double X, double Y, double Z)
{
  // default lc (mesh size == size of the model)
  double l1 = CTX::instance()->lc;

  // lc from points
  double l2 = MAX_LC;
  if(CTX::instance()->mesh.lcFromPoints && ge->dim() < 2)
    l2 = LC_MVertex_PNTS(ge, U, V);

  // lc from curvature
  double l3 = MAX_LC;
  if(CTX::instance()->mesh.lcFromCurvature && ge->dim() < 3)
    l3 = LC_MVertex_CURV(ge, U, V);

  // lc from fields
  double l4 = MAX_LC;
  FieldManager *fields = ge->model()->getFields();
  if(fields->getBackgroundField() > 0){
    Field *f = fields->get(fields->getBackgroundField());
    if(f) l4 = (*f)(X, Y, Z, ge);
  }

  // global lc from entity
  double l5 = ge->getMeshSize();

  // take the minimum, then constrain by lcMin and lcMax
  double lc = std::min(std::min(std::min(std::min(l1, l2), l3), l4), l5);
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);

  if(lc <= 0.){
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)",
               lc, CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = l1;
  }

  return lc * CTX::instance()->mesh.lcFactor;
}

// anisotropic version of the background field
SMetric3 BGM_MeshMetric(GEntity *ge,
                        double U, double V,
                        double X, double Y, double Z)
{

  // Metrics based on element size

  // Element size = min. between default lc and lc from point (if applicable),
  // constrained by lcMin and lcMax
  double lc = CTX::instance()->lc;
  if(CTX::instance()->mesh.lcFromPoints && ge->dim() < 2)
    lc = std::min(lc, LC_MVertex_PNTS(ge, U, V));
  lc = std::min(lc, ge->getMeshSize());
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);
  if(lc <= 0.){
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)",
               lc, CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = CTX::instance()->lc;
  }
  SMetric3 m0(1./(lc*lc));

  // Intersect with metrics from fields if applicable
  FieldManager *fields = ge->model()->getFields();
  SMetric3 m1 = m0;
  if(fields->getBackgroundField() > 0){
    Field *f = fields->get(fields->getBackgroundField());
    if(f) {
      SMetric3 l4;
      if (!f->isotropic()) (*f)(X, Y, Z, l4, ge);
      else {
        const double L = (*f)(X, Y, Z, ge);
        l4 = SMetric3(1/(L*L));
      }
      m1 = intersection(l4, m0);
    }
  }

  // Intersect with metrics from curvature if applicable
  SMetric3 m = (CTX::instance()->mesh.lcFromCurvature && ge->dim() < 3) ?
      intersection(m1, LC_MVertex_CURV_ANISO(ge, U, V)) : m1;

  return m;
}

bool Extend1dMeshIn2dSurfaces()
{
  return CTX::instance()->mesh.lcExtendFromBoundary ? true : false;
}

bool Extend2dMeshIn3dVolumes()
{
  return CTX::instance()->mesh.lcExtendFromBoundary ? true : false;
}

SMetric3 max_edge_curvature_metric(const GVertex *gv)
{
  SMetric3 val (1.e-12);
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin();
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);
    SMetric3 cc;
    if (gv == _myGEdge->getBeginVertex()) {
      SVector3 t = _myGEdge->firstDer(range.low());
      t.normalize();
      double l_t = ((2 * M_PI) /( fabs(_myGEdge->curvature(range.low()))
				*  CTX::instance()->mesh.minCircPoints ));
      double l_n = 1.e12;
      cc = buildMetricTangentToCurve(t,l_t,l_n);
    }
    else {
      SVector3 t = _myGEdge->firstDer(range.high());
      t.normalize();
      double l_t = ((2 * M_PI) /( fabs(_myGEdge->curvature(range.high()))
				  *  CTX::instance()->mesh.minCircPoints ));
      double l_n = 1.e12;
      cc = buildMetricTangentToCurve(t,l_t,l_n);
    }
    val = intersection(val,cc);
  }
  return val;
}

SMetric3 metric_based_on_surface_curvature(const GFace *gf, double u, double v,
					   bool surface_isotropic,
					   double d_normal ,
					   double d_tangent_max)
{
  if (gf->geomType() == GEntity::Plane)return SMetric3(1.e-12);
  double cmax, cmin;
  SVector3 dirMax,dirMin;
  cmax = gf->curvatures(SPoint2(u, v),&dirMax, &dirMin, &cmax,&cmin);
  if (cmin == 0)cmin =1.e-12;
  if (cmax == 0)cmax =1.e-12;
  double lambda1 =  ((2 * M_PI) /( fabs(cmin) *  CTX::instance()->mesh.minCircPoints ) );
  double lambda2 =  ((2 * M_PI) /( fabs(cmax) *  CTX::instance()->mesh.minCircPoints ) );
  SVector3 Z = crossprod(dirMax,dirMin);
  if (surface_isotropic)  lambda2 = lambda1 = std::min(lambda2,lambda1);
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

  SMetric3 curvMetric (1./(lambda1*lambda1),1./(lambda2*lambda2),
		       1./(lambda3*lambda3),
                       dirMin, dirMax, Z );
  return curvMetric;
}

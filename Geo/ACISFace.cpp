// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GEdgeLoop.h"
#include "ACISVertex.h"
#include "ACISEdge.h"
#include "ACISFace.h"
#include "Numeric.h"
#include "Context.h"

#if defined(HAVE_ACIS)

#include <loop.hxx>
#include <surdef.hxx>
#include <coedge.hxx>
#include <intrapi.hxx>
#include <poly_vtx.hxx>
#include <api.hxx>
#include <kernapi.hxx>
#include <af_api.hxx>

ACISFace::ACISFace(GModel *m, FACE *f, int num)
  : GFace(m, num), _f(f)
{
  edgeLoops.clear();
  l_edges.clear();
  l_dirs.clear();
  
  LOOP *myLoop = _f->loop();
  do{
    std::list<GEdge*> l_wire;
    COEDGE *start = myLoop->start();
    COEDGE *_current  = start;
    do {
      EDGE *e = _current->edge();
      GEdge *ge = getACISEdgeByNativePtr(m,e);
      l_wire.push_back(ge);      
      _current = _current->next();
    }while (_current && _current != start);
    GEdgeLoop el(l_wire);
    for(GEdgeLoop::citer it = el.begin(); it != el.end(); ++it){
      l_edges.push_back(it->ge);
      l_dirs.push_back(it->_sign);
      if (el.count() == 2){
        it->ge->meshAttributes.minimumMeshSegments = 
          std::max(it->ge->meshAttributes.minimumMeshSegments,2);
      }
      if (el.count() == 1){
        it->ge->meshAttributes.minimumMeshSegments = 
          std::max(it->ge->meshAttributes.minimumMeshSegments,3);
      }
    }
    edgeLoops.push_back(el);   
  }while (myLoop = myLoop->next());

  SURFACE *Surf = _f->geometry();
  const surface &surf = Surf->equation();

  SPAinterval _u,_v;
  _u = surf.param_range_u();
  _v = surf.param_range_v();

  umin = _u.start_pt();
  umax = _u.end_pt();

  vmin = _v.start_pt();
  vmax = _v.end_pt();

  if ( surf.closed_u() || surf.closed_v() ) {
    printf("%d %g %g -- %g %g\n",tag(),umin,umax,vmin,vmax);
  }

  _periodic[0] = surf.periodic_u();
  _periodic[1] = surf.periodic_v();

  const double du = umax - umin;
  const double dv = vmax - vmin;
  umin -= fabs(du) / 100.0;
  vmin -= fabs(dv) / 100.0;
  umax += fabs(du) / 100.0;
  vmax += fabs(dv) / 100.0;
}

Range<double> ACISFace::parBounds(int i) const
{  
  if(i == 0)
    return Range<double>(umin, umax);
  return Range<double>(vmin, vmax);
}

SVector3 ACISFace::normal(const SPoint2 &param) const
{
  SURFACE *Surf = _f->geometry();
  const surface &surf = Surf->equation();

  const SPAunit_vector n = surf.eval_normal (SPApar_pos (param.x(),param.y()));  
  return SVector3(n.component(0),n.component(1),n.component(2));  
}

Pair<SVector3,SVector3> ACISFace::firstDer(const SPoint2 &param) const
{
  SURFACE *Surf = _f->geometry();
  const surface &surf = Surf->equation();
  SPAposition pos;
  SPAvector first_derivs[2];
  surf.eval (SPApar_pos(param.x(),param.y()), pos,first_derivs);
  return Pair<SVector3,SVector3> 
    (SVector3(first_derivs[0].component(0), first_derivs[0].component(1), 
              first_derivs[0].component(2)),
     SVector3(first_derivs[1].component(0), first_derivs[1].component(1),
              first_derivs[1].component(2)));
}

void ACISFace::secondDer(const SPoint2 &param,
                        SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  SURFACE *Surf = _f->geometry();
  const surface &surf = Surf->equation();
}

GPoint ACISFace::point(double par1, double par2) const
{
  SURFACE *Surf = _f->geometry();
  const surface &surf = Surf->equation();
  SPAposition pos;
  surf.eval (SPApar_pos(par1,par2), pos);
  double pp[2] = {par1,par2};
  return GPoint(pos.coordinate(0),pos.coordinate(1),pos.coordinate(2),this,pp);    
}

GPoint ACISFace::closestPoint(const SPoint3 &qp, const double initialGuess[2]) const
{
  SPAposition pt(qp.x(),qp.y(),qp.z());
  SPAposition fpt;
  SPApar_pos ppt;
  SURFACE *Surf = _f->geometry();

  Surf->equation().point_perp(pt,fpt,*(SPApar_pos *)NULL_REF,ppt);
  SPoint2 pt2(ppt.u,ppt.v);	

  return GPoint(fpt.x(),fpt.y(),fpt.z(),this,pt2);
}

SPoint2 ACISFace::parFromPoint(const SPoint3 &qp, bool onSurface) const
{
  SURFACE *Surf = _f->geometry();
  SPAposition pt(qp.x(),qp.y(),qp.z());
  SPApar_pos ppt = Surf->equation().param(pt);
  SPoint2 pt2(ppt.u,ppt.v);
  GPoint sp = point(ppt.u,ppt.v);
  return pt2;
}

GEntity::GeomType ACISFace::geomType() const
{
  SURFACE *Surf = _f->geometry();
  if (!strcmp(Surf->type_name(),"plane"))return Plane;
  if (!strcmp(Surf->type_name(),"sphere"))return Sphere;
  if (!strcmp(Surf->type_name(),"cone"))return Cone;
  if (!strcmp(Surf->type_name(),"torus"))return Torus;
  if (!strcmp(Surf->type_name(),"cylinder"))return Cylinder;
  return Unknown;
}

double ACISFace::curvatureMax(const SPoint2 &param) const
{
  return 1.e22;
}

double ACISFace::curvatures(const SPoint2 &param,
                           SVector3 *dirMax,
                           SVector3 *dirMin,
                           double *curvMax,
                           double *curvMin) const
{
  return 1.e22;
}

bool ACISFace::containsPoint(const SPoint3 &pt) const
{ 
  SPAposition ps(pt.x(),pt.y(),pt.z());
  if (_f->geometry()->equation().test_point(ps))
    return 1;
  else 
    return 0;
}

double ACISFace::period(int dir) const { 
  if (dir == 0)
    return _f->geometry()->equation().param_period_u();
  else if (dir == 1)
    return _f->geometry()->equation().param_period_v();
}

bool ACISFace::buildSTLTriangulation(bool force)
{
  if(stl_triangles.size()){
    if(force){
      stl_vertices.clear();
      stl_triangles.clear();
    }
    else
      return true;
  }
  outcome out = api_facet_entity(_f);
  if (!out.ok())return false;
  return true;
}

GFace *getACISFaceByNativePtr(GModel *model, FACE *f)
{
  GModel::fiter it =model->firstFace();
  for (; it !=model->lastFace(); ++it){
    ACISFace *gf = dynamic_cast<ACISFace*>(*it);
    if (gf){
      if (f == (FACE*)gf->getNativePtr())return gf;
    }
  }
  return 0;
}

#endif

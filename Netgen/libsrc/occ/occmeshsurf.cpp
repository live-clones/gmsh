#ifdef OCCGEOMETRY

#include <mystdlib.h>

#include <occgeom.hpp>
#include <meshing.hpp>


namespace netgen
{
#include "occmeshsurf.hpp"

void OCCSurface :: GetNormalVector (const Point<3> & p, 
				    const PointGeomInfo & geominfo,
				    Vec<3> & n) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;
  occface->D1(geominfo.u,geominfo.v,pnt,du,dv);

  n = Cross (Vec<3>(du.X(), du.Y(), du.Z()),
	     Vec<3>(dv.X(), dv.Y(), dv.Z()));
  n.Normalize();

  if (orient == TopAbs_REVERSED) n = -1*n;
}


void OCCSurface :: DefineTangentialPlane (const Point<3> & ap1,
					  const PointGeomInfo & geominfo1,
					  const Point<3> & ap2,
					  const PointGeomInfo & geominfo2)
{
  p1 = ap1; p2 = ap2;
  
  GetNormalVector (p1, geominfo1, ez);

  ex = p2 - p1;
  ex -= (ex * ez) * ez;
  ex.Normalize();
  ey = Cross (ez, ex); 

  /*
  double u, v;
  gp_Vec du, dv;
  gp_Pnt pnt(ap2(0), ap2(1), ap2(2));
  GeomAPI_ProjectPointOnSurf proj(pnt, occface);
  proj.LowerDistanceParameters (u, v);
  occface->D1(u, v, pnt, du, dv);
  n2 = Cross (Vec<3>(du.X(), du.Y(), du.Z()),
	      Vec<3>(dv.X(), dv.Y(), dv.Z()));
  n2.Normalize();
  if (orient == TopAbs_REVERSED) n2 = -1*n2;
  */

  GetNormalVector (p2, geominfo2, n2);
 
  nmid = 0.5*(n2+ez);

  ez = nmid;
  ez.Normalize(); 

  ex = (p2 - p1).Normalize();
  ez -= (ez * ex) * ex;
  ez.Normalize();
  ey = Cross (ez, ex);
  nmid = ez;
 
}


void OCCSurface :: ToPlane (const Point<3> & p3d,
			    const PointGeomInfo & geominfo,
			    Point<2> & pplane, 
			    double h, int & zone) const
{
  Vec<3> p1p, n;
  GetNormalVector (p3d, geominfo, n);

  p1p = p3d - p1;
  pplane(0) = (p1p * ex) / h;
  pplane(1) = (p1p * ey) / h;

  if (n * nmid < 0)
    zone = -1;
  else
    zone = 0;
  
  /*
  Vec<3> v = p3d - p1;
  Vec<3> n;
  GetNormalVector (p3d, geominfo, n);

  if (n * nmid < 0)
    zone = -1;
  else
    {
      double nom = h*(n(0)*(ex(1)*ey(2)-ex(2)*ey(1)) + 
		      n(1)*(ex(2)*ey(0)-ex(0)*ey(2)) +
		      n(2)*(ex(0)*ey(1)-ex(1)*ey(0)));

      pplane(0) = (n(0)*(ey(2)*v(1)-ey(1)*v(2)) +
		   n(1)*(ey(0)*v(2)-ey(2)*v(0)) +
		   n(2)*(ey(1)*v(0)-ey(0)*v(1)))/nom;

      pplane(1) = (n(0)*(ex(1)*v(2)-ex(2)*v(1)) +
		   n(1)*(ex(2)*v(0)-ex(0)*v(2)) +
		   n(2)*(ex(0)*v(1)-ex(1)*v(0)))/nom;
      
      zone = 0;
    }
  */
}	


void OCCSurface :: FromPlane (const Point<2> & pplane, 
			      Point<3> & p3d,
			      PointGeomInfo & gi,
			      double h) 
{ 
  p3d = p1 + (h * pplane(0)) * ex + (h * pplane(1)) * ey;
  Project (p3d, gi);  
}



void OCCSurface :: Project (Point<3> & p, PointGeomInfo & gi)
{
  //   static int cnt = 0;
  //  if (cnt++ % 1000 == 0) cout << "********************************************** OCCSurfce :: Project, cnt = " << cnt << endl;
  
  gp_Pnt pnt(p(0), p(1), p(2));
  GeomAPI_ProjectPointOnSurf proj(pnt, occface);

  pnt = proj.NearestPoint();
  proj.LowerDistanceParameters (gi.u, gi.v);
  gi.trignum = 1;

  p = Point<3> (pnt.X(), pnt.Y(), pnt.Z());
}


Meshing2OCCSurfaces :: Meshing2OCCSurfaces (const TopoDS_Shape & asurf,
					    const Box<3> & abb)
  : Meshing2(Box3d(abb.PMin(), abb.PMax())), surface(TopoDS::Face(asurf))
{
  ;
}


void Meshing2OCCSurfaces :: DefineTransformation (Point3d & p1, Point3d & p2,
						  const PointGeomInfo * geominfo1,
						  const PointGeomInfo * geominfo2)
{
  ((OCCSurface&)surface).DefineTangentialPlane (p1, *geominfo1, p2, *geominfo2);
}

void Meshing2OCCSurfaces :: TransformToPlain (const Point3d & locpoint, 
					   const MultiPointGeomInfo & geominfo,
					   Point2d & planepoint, 
					   double h, int & zone)
{
  Point<2> hp;
  surface.ToPlane (locpoint, geominfo.GetPGI(1), hp, h, zone);
  planepoint.X() = hp(0);
  planepoint.Y() = hp(1);
}

int Meshing2OCCSurfaces :: TransformFromPlain (Point2d & planepoint,
					       Point3d & locpoint,
					       PointGeomInfo & gi,
					       double h)
{
  Point<3> hp;
  Point<2> hp2 (planepoint.X(), planepoint.Y());
  surface.FromPlane (hp2, hp, gi, h);
  locpoint = hp;
  return 0;
}



double Meshing2OCCSurfaces :: CalcLocalH (const Point3d & p, double gh) const
{
  return gh;
}






MeshOptimize2dOCCSurfaces :: MeshOptimize2dOCCSurfaces (const OCCGeometry & ageometry)
  : MeshOptimize2d(), geometry(ageometry)
{
  ;
}


void MeshOptimize2dOCCSurfaces :: ProjectPoint (INDEX surfind, Point3d & p) const
{
  Point<3> hp = p;
  geometry.Project (surfind, hp);
  p = hp;
}

void MeshOptimize2dOCCSurfaces :: ProjectPoint2 (INDEX surfind, INDEX surfind2, 
					      Point3d & p) const
{
  TopExp_Explorer exp0, exp1;
  int done = 0;
  Handle(Geom_Curve) c;

  for (exp0.Init(geometry.fmap(surfind), TopAbs_EDGE); !done && exp0.More(); exp0.Next())
    for (exp1.Init(geometry.fmap(surfind2), TopAbs_EDGE); !done && exp1.More(); exp1.Next())
      {
	if (TopoDS::Edge(exp0.Current()).IsSame(TopoDS::Edge(exp1.Current())))
	  {
	    done = 1;
	    double s0, s1;
	    c = BRep_Tool::Curve(TopoDS::Edge(exp0.Current()), s0, s1);
	  }
      }
  
  gp_Pnt pnt(p.X(), p.Y(), p.Z());
  GeomAPI_ProjectPointOnCurve proj(pnt, c);
  pnt = proj.NearestPoint();  
  p.X() = pnt.X();
  p.Y() = pnt.Y();
  p.Z() = pnt.Z();
	
}

void MeshOptimize2dOCCSurfaces :: 
GetNormalVector(INDEX surfind, const Point3d & p, PointGeomInfo & geominfo, Vec3d & n) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;

  Handle(Geom_Surface) occface;
  occface = BRep_Tool::Surface(TopoDS::Face(geometry.fmap(surfind)));

  occface->D1(geominfo.u,geominfo.v,pnt,du,dv);

  n = Cross (Vec<3>(du.X(), du.Y(), du.Z()),
	     Vec<3>(dv.X(), dv.Y(), dv.Z()));
  n.Normalize();

  if (geometry.fmap(surfind).Orientation() == TopAbs_REVERSED) n = -1*n;  
  
  //  GetNormalVector (surfind, p, n);
}


void MeshOptimize2dOCCSurfaces :: 
GetNormalVector(INDEX surfind, const Point3d & p, Vec3d & n) const
{
  //  static int cnt = 0;
  //  if (cnt++ % 1000 == 0) cout << "GetNV cnt = " << cnt << endl;
  Standard_Real u,v;

  gp_Pnt pnt(p.X(), p.Y(), p.Z());

  Handle(Geom_Surface) occface;
  occface = BRep_Tool::Surface(TopoDS::Face(geometry.fmap(surfind)));

  GeomAPI_ProjectPointOnSurf proj(pnt, occface);

  if (proj.NbPoints() < 1)
    {
      cout << "ERROR: OCCSurface :: GetNormalVector: GeomAPI_ProjectPointOnSurf failed!"
	   << endl;
      cout << p << endl;
      return;
    }
 
  proj.LowerDistanceParameters (u, v);

  gp_Vec du, dv;
  occface->D1(u,v,pnt,du,dv);

  /*
  if (!occface->IsCNu (1) || !occface->IsCNv (1))
    (*testout) << "SurfOpt: Differentiation FAIL" << endl;
  */

  n = Cross (Vec3d(du.X(), du.Y(), du.Z()),
	     Vec3d(dv.X(), dv.Y(), dv.Z()));
  n.Normalize();

  if (geometry.fmap(surfind).Orientation() == TopAbs_REVERSED) n = -1*n;  
}


int MeshOptimize2dOCCSurfaces :: 
CalcPointGeomInfo(int surfind, PointGeomInfo& gi, const Point3d& p) const
{
  Standard_Real u,v;

  gp_Pnt pnt(p.X(), p.Y(), p.Z());

  Handle(Geom_Surface) occface;
  occface = BRep_Tool::Surface(TopoDS::Face(geometry.fmap(surfind)));

  GeomAPI_ProjectPointOnSurf proj(pnt, occface);

  if (proj.NbPoints() < 1)
    {
      cout << "ERROR: OCCSurface :: GetNormalVector: GeomAPI_ProjectPointOnSurf failed!"
	   << endl;
      cout << p << endl;
      return 0;
    }
 
  proj.LowerDistanceParameters (u, v);  

  gi.u = u;
  gi.v = v;
  return 1;
}






OCCRefinementSurfaces :: OCCRefinementSurfaces (const OCCGeometry & ageometry)
  : Refinement(), geometry(ageometry)
{
  ;
}

OCCRefinementSurfaces :: ~OCCRefinementSurfaces ()
{
  ;
}
  
void OCCRefinementSurfaces :: 
PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
	      int surfi, 
	      const PointGeomInfo & gi1, 
	      const PointGeomInfo & gi2,
	      Point3d & newp, PointGeomInfo & newgi)
{
  Point<3> hnewp;
  hnewp = p1+secpoint*(p2-p1);

  if (surfi > 0)
    {
      geometry.Project (surfi, hnewp);
      newgi.trignum = 1;
    }
  
  newp = hnewp;
}


void OCCRefinementSurfaces :: 
PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
 	      int surfi1, int surfi2, 
	      const EdgePointGeomInfo & ap1, 
	      const EdgePointGeomInfo & ap2,
	      Point3d & newp, EdgePointGeomInfo & newgi)
{
  double s0, s1;

  Point<3> hnewp = p1+secpoint*(p2-p1);
  gp_Pnt pnt(hnewp(0), hnewp(1), hnewp(2));
  GeomAPI_ProjectPointOnCurve proj(pnt, BRep_Tool::Curve(TopoDS::Edge(geometry.emap(ap1.edgenr)), s0, s1));
  pnt = proj.NearestPoint();
  hnewp = Point<3> (pnt.X(), pnt.Y(), pnt.Z());
  newp = hnewp;
};


void OCCRefinementSurfaces :: ProjectToSurface (Point<3> & p, int surfi)
{
  if (surfi > 0)
    geometry.Project (surfi, p);
};



}


#endif

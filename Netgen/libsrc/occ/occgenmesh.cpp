#ifdef OCCGEOMETRY

#include <mystdlib.h>
#include <occgeom.hpp>
#include <meshing.hpp>

#include <stlgeom.hpp>


namespace netgen
{

#include "occmeshsurf.hpp"

#define TCL_OK 0
#define TCL_ERROR 1

extern STLParameters stlparam;

#define DIVIDEEDGESECTIONS 1000
#define IGNORECURVELENGTH 1e-4

 
void DivideEdge (TopoDS_Edge & edge,
		 ARRAY<MeshPoint> & ps,
		 ARRAY<double> & params,
		 Mesh & mesh)
{
  double s0, s1;
  int j;
  double maxh = mparam.maxh;
  int nsubedges = 1;  
  gp_Pnt pnt, oldpnt;
  double svalue[DIVIDEEDGESECTIONS];

  GProp_GProps system;
  BRepGProp::LinearProperties(edge, system);
  double L = system.Mass();

  Handle(Geom_Curve) c = BRep_Tool::Curve(edge, s0, s1);

  double hvalue[DIVIDEEDGESECTIONS+1];
  hvalue[0] = 0;
  pnt = c->Value(s0);

  double olddist = 0;
  double dist = 0;

  for (int i = 1; i <= DIVIDEEDGESECTIONS; i++)
    {
      oldpnt = pnt;
      pnt = c->Value(s0+(i/double(DIVIDEEDGESECTIONS))*(s1-s0));
      hvalue[i] = hvalue[i-1] +
	1.0/mesh.GetH(Point3d(pnt.X(), pnt.Y(), pnt.Z()))*
	pnt.Distance(oldpnt);

      olddist = dist;
      dist = pnt.Distance(oldpnt);
    }

  //  nsubedges = int(ceil(hvalue[DIVIDEEDGESECTIONS]));
  nsubedges = max (1, int(floor(hvalue[DIVIDEEDGESECTIONS]+0.5)));

  ps.SetSize(nsubedges-1);
  params.SetSize(nsubedges+1);

  int i = 1;
  int i1 = 0;
  do
    {
      if (hvalue[i1]/hvalue[DIVIDEEDGESECTIONS]*nsubedges >= i)
	{
	  params[i] = s0+(i1/double(DIVIDEEDGESECTIONS))*(s1-s0);
	  pnt = c->Value(params[i]);
	  ps[i-1] = MeshPoint (Point3d(pnt.X(), pnt.Y(), pnt.Z()));
	  i++;
	}
      i1++;
      if (i1 > DIVIDEEDGESECTIONS)
	{
	  nsubedges = i;
	  ps.SetSize(nsubedges-1);
	  params.SetSize(nsubedges+1);
	  cout << "divide edge: local h too small" << endl;
	}
    } while (i < nsubedges);

  params[0] = s0;
  params[nsubedges] = s1;

  if (params[nsubedges] <= params[nsubedges-1])
    {
      cout << "CORRECTED" << endl;
      ps.SetSize (nsubedges-2);
      params.SetSize (nsubedges);
      params[nsubedges] = s1;
    }
}
 



static void FindEdges (OCCGeometry & geom, Mesh & mesh)
{
  int i, j;
  
  char * savetask = multithread.task;
  multithread.task = "Edge meshing";

  (*testout) << "edge meshing" << endl;

  TopExp_Explorer exp0, exp01, exp1, exp2, exp3;
  
  int nvertices = geom.vmap.Extent();
  int nedges = geom.emap.Extent();
  for (i = 1; i <= nvertices; i++)
    {
      gp_Pnt pnt = BRep_Tool::Pnt (TopoDS::Vertex(geom.vmap(i)));
      MeshPoint mp( Point3d(pnt.X(), pnt.Y(), pnt.Z()) );

      /*
      int exists = 0;
			
      for (j = 1; !exists && (j <= mesh.GetNP()); j++)
	if ((mesh.Point(j)-Point<3>(mp)).Length() < 1e-6)
	  exists = 1;
      
      if (!exists)
      */

      mesh.AddPoint (mp);
    }
  
  int facenr = 0;
  int edgenr = 0;
  
  int total = 0;
  int solidnr = 0;

  ARRAY<int> face2solid;
  face2solid.SetSize (geom.fmap.Extent());
  face2solid = 0;

  /*
  for (exp0.Init(geom.shape, TopAbs_SOLID); exp0.More(); exp0.Next())
    {
      solidnr++;
      for (exp01.Init(exp0.Current(), TopAbs_SHELL); exp01.More(); exp01.Next())
	{
	  TopoDS_Shape shell = exp01.Current();
	  for (exp1.Init(shell, TopAbs_FACE); exp1.More(); exp1.Next())
	    {
	      TopoDS_Face face = TopoDS::Face(exp1.Current());
	      facenr = geom.fmap.FindIndex(face);
	      face2solid[facenr-1] = solidnr;
	    
	      for (exp2.Init (face, TopAbs_WIRE); exp2.More(); exp2.Next())
		{
		  TopoDS_Shape wire = exp2.Current();
		  
		  for (exp3.Init (wire, TopAbs_EDGE); exp3.More(); exp3.Next())
		    {
		      total++;
		    }
		}
	    }
	  }
      }
  */

  for (exp0.Init(geom.shape, TopAbs_SOLID); exp0.More(); exp0.Next())
    {
      solidnr++;
      for (exp1.Init(exp0.Current(), TopAbs_FACE); exp1.More(); exp1.Next())
	{
	  TopoDS_Face face = TopoDS::Face(exp1.Current());
	  facenr = geom.fmap.FindIndex(face);
	  face2solid[facenr-1] = solidnr;
	}
      }


  for (int i3 = 1; i3 <= geom.fmap.Extent(); i3++)
    for (exp2.Init (geom.fmap(i3), TopAbs_WIRE); exp2.More(); exp2.Next())
      for (exp3.Init (exp2.Current(), TopAbs_EDGE); exp3.More(); exp3.Next())
	total++;
	   

  int curr = 0;

  
  solidnr = 0;
  /*
  for (exp0.Init(geom.shape, TopAbs_SOLID); exp0.More(); exp0.Next())
    {
      solidnr++;
      for (exp01.Init(exp0.Current(), TopAbs_SHELL); exp01.More(); exp01.Next())
	{
	  TopoDS_Shape shell = exp01.Current();
	  
	  for (exp1.Init(shell, TopAbs_FACE); exp1.More(); exp1.Next())
	    {
	      
	      TopoDS_Face face = TopoDS::Face(exp1.Current());
  */
	      
  for (int i3 = 1; i3 <= geom.fmap.Extent(); i3++)
    
      
	{
	  {
	    {
	      TopoDS_Face face = TopoDS::Face(geom.fmap(i3));
	      solidnr = face2solid[i3-1];
	      
	      
	      facenr = geom.fmap.FindIndex (face);
	      
	      mesh.AddFaceDescriptor (FaceDescriptor(facenr, solidnr, 0, 0));
	      Handle(Geom_Surface) occface = BRep_Tool::Surface(face);
	      
	      for (exp2.Init (face, TopAbs_WIRE); exp2.More(); exp2.Next())
		{
		  TopoDS_Shape wire = exp2.Current();
		  
		  for (exp3.Init (wire, TopAbs_EDGE); exp3.More(); exp3.Next())
		    {
		      curr++;
 
		      multithread.percent = 100 * curr / (double) total;
		      if (multithread.terminate) return;

		      TopoDS_Edge edge = TopoDS::Edge (exp3.Current());
		      if (BRep_Tool::Degenerated(edge)) continue;

		      if (geom.vmap.FindIndex(TopExp::FirstVertex (edge)) == 
			  geom.vmap.FindIndex(TopExp::LastVertex (edge)))
			{
			  GProp_GProps system;
			  BRepGProp::LinearProperties(edge, system);

			  if (system.Mass() < 1e-5)
			    {
			      cout << "ignoring edge " << geom.emap.FindIndex (edge)
				   << ". closed edge with length < 1e-5" << endl;
			      continue;
			    }
			}


		      Handle(Geom2d_Curve) cof;
		      double s0, s1;
		      cof = BRep_Tool::CurveOnSurface (edge, face, s0, s1);

		      int geomedgenr = geom.emap.FindIndex(edge);

		      ARRAY <MeshPoint> mp;
		      ARRAY <double> params;

		      DivideEdge (edge, mp, params, mesh);

		    
		      ARRAY <int> pnums;
		      pnums.SetSize (mp.Size()+2);
		    
		      pnums[0] = geom.vmap.FindIndex (TopExp::FirstVertex (edge));
		      pnums[pnums.Size()-1] = geom.vmap.FindIndex (TopExp::LastVertex (edge));

		      for (i = 1; i <= mp.Size(); i++)
			{
			  int exists = 0;
			
			  for (j = 1; !exists && (j <= mesh.GetNP()-nvertices); j++)
			    if ((mesh.Point(nvertices+j)-Point<3>(mp[i-1])).Length() < 1e-6) exists = 1;

			  if (exists)
			    {
			      pnums[i] = nvertices+j-1;
			    }
			  else
			    {
			      mesh.AddPoint (mp[i-1]);
			      pnums[i] = mesh.GetNP();
			    }
			}
		    
		      for (i = 1; i <= mp.Size()+1; i++)
			{
			  edgenr++;
			  Segment seg;
			
			  seg.p1 = pnums[i-1];
			  seg.p2 = pnums[i];
			  seg.edgenr = edgenr;
			  seg.si = facenr;
			  seg.epgeominfo[0].dist = params[i-1];
			  seg.epgeominfo[1].dist = params[i];
			  seg.epgeominfo[0].edgenr = geomedgenr;
			  seg.epgeominfo[1].edgenr = geomedgenr;
			
			  gp_Pnt2d p2d;
			  p2d = cof->Value(params[i-1]);
			  //			if (i == 1) p2d = cof->Value(s0);
			  seg.epgeominfo[0].u = p2d.X();
			  seg.epgeominfo[0].v = p2d.Y();
			  p2d = cof->Value(params[i]);
			  //			if (i == mp.Size()+1) p2d = cof -> Value(s1);
			  seg.epgeominfo[1].u = p2d.X();
			  seg.epgeominfo[1].v = p2d.Y();

			  /*
			    if (occface->IsUPeriodic())
			    {
			    cout << "U Periodic" << endl;
			    if (fabs(seg.epgeominfo[1].u-seg.epgeominfo[0].u) >
			    fabs(seg.epgeominfo[1].u-
			    (seg.epgeominfo[0].u-occface->UPeriod())))
			    seg.epgeominfo[0].u = p2d.X()+occface->UPeriod();

			    if (fabs(seg.epgeominfo[1].u-seg.epgeominfo[0].u) >
			    fabs(seg.epgeominfo[1].u-
			    (seg.epgeominfo[0].u+occface->UPeriod())))
			    seg.epgeominfo[0].u = p2d.X()-occface->UPeriod();
			    }

			    if (occface->IsVPeriodic())
			    {
			    cout << "V Periodic" << endl;
			    if (fabs(seg.epgeominfo[1].v-seg.epgeominfo[0].v) >
			    fabs(seg.epgeominfo[1].v-
			    (seg.epgeominfo[0].v-occface->VPeriod())))
			    seg.epgeominfo[0].v = p2d.Y()+occface->VPeriod();

			    if (fabs(seg.epgeominfo[1].v-seg.epgeominfo[0].v) >
			    fabs(seg.epgeominfo[1].v-
			    (seg.epgeominfo[0].v+occface->VPeriod())))
			    seg.epgeominfo[0].v = p2d.Y()-occface->VPeriod();
			    }
			  */
			
			  if (edge.Orientation() == TopAbs_REVERSED)
			    {
			      swap (seg.p1, seg.p2);
			      swap (seg.epgeominfo[0].dist, seg.epgeominfo[1].dist);
			      swap (seg.epgeominfo[0].u, seg.epgeominfo[1].u);
			      swap (seg.epgeominfo[0].v, seg.epgeominfo[1].v);
			    }

			  mesh.AddSegment (seg);

			}
		    }
		}
	    }
	}
    }
  mesh.CalcSurfacesOfNode();
  multithread.task = savetask;
}  




static void OCCMeshSurface (OCCGeometry & geom, Mesh & mesh, int perfstepsend)
{
  int i, j, k;
  int changed;

  char * savetask = multithread.task;
  multithread.task = "Surface meshing";
  
  geom.facemeshstatus = 0;

  int noldp = mesh.GetNP();

  double starttime = GetTime();

  ARRAY<int> glob2loc(noldp);

  int projecttype = PARAMETERSPACE;
  
  //int projecttype = PLANESPACE;

  int notrys = 1;

  int surfmesherror = 0;

  for (k = 1; k <= mesh.GetNFD(); k++)
    {
      (*testout) << "mesh face " << k << endl;
      multithread.percent = 100 * k / (mesh.GetNFD()+1e-10);
      geom.facemeshstatus[k-1] = -1;

      
      /*
      if (k != 138)
	{
	  cout << "skipped" << endl;
	  continue;
	}
      */
    
      FaceDescriptor & fd = mesh.GetFaceDescriptor(k);

      int oldnf = mesh.GetNSE();

      Box<3> bb = geom.GetBoundingBox();
 
      Meshing2OCCSurfaces meshing(TopoDS::Face(geom.fmap(k)), bb, projecttype); 

      if (meshing.GetProjectionType() == PLANESPACE)
	PrintMessage (2, "Face ", k, " / ", mesh.GetNFD(), " (plane space projection)");
      else
	PrintMessage (2, "Face ", k, " / ", mesh.GetNFD(), " (parameter space projection)");

      if (surfmesherror)
	cout << "Surface meshing error occured before (in " << surfmesherror << " faces)" << endl;

      //      Meshing2OCCSurfaces meshing(f2, bb); 
      meshing.SetStartTime (starttime);

      (*testout) << "Face " << k << endl << endl;


      if (meshing.GetProjectionType() == PLANESPACE)
	{
	  int cntp = 0;
	  glob2loc = 0;
	  for (i = 1; i <= mesh.GetNSeg(); i++)
	    {
	      Segment & seg = mesh.LineSegment(i);
	      if (seg.si == k)
		{
		  for (j = 1; j <= 2; j++)
		    {
		      int pi = (j == 1) ? seg.p1 : seg.p2;
		      if (!glob2loc.Get(pi))
			{
			  meshing.AddPoint (mesh.Point(pi), pi);
			  cntp++;
			  glob2loc.Elem(pi) = cntp;
			}
		    }
		}
	    }
	  
	  for (i = 1; i <= mesh.GetNSeg(); i++)
	    {
	      Segment & seg = mesh.LineSegment(i);
	      if (seg.si == k)
		{
		  PointGeomInfo gi0, gi1;
		  gi0.trignum = gi1.trignum = k;
		  gi0.u = seg.epgeominfo[0].u;
		  gi0.v = seg.epgeominfo[0].v;
		  gi1.u = seg.epgeominfo[1].u;
		  gi1.v = seg.epgeominfo[1].v;
		  
		  meshing.AddBoundaryElement (glob2loc.Get(seg.p1), glob2loc.Get(seg.p2), gi0, gi1);
		  (*testout) << gi0.u << " " << gi0.v << endl;
		  (*testout) << gi1.u << " " << gi1.v << endl;
		}
	    }
	}
      else
	{
	  int cntp = 0;
	  
	  for (i = 1; i <= mesh.GetNSeg(); i++)
	    if (mesh.LineSegment(i).si == k)
	      cntp+=2;
	  
	  
	  ARRAY< PointGeomInfo > gis;
	  
	  gis.SetAllocSize (cntp);
	  gis.SetSize (0);
	  
	  for (i = 1; i <= mesh.GetNSeg(); i++)
	    {
	      Segment & seg = mesh.LineSegment(i);
	      if (seg.si == k)
		{
		  PointGeomInfo gi0, gi1;
		  gi0.trignum = gi1.trignum = k;
		  gi0.u = seg.epgeominfo[0].u;
		  gi0.v = seg.epgeominfo[0].v;
		  gi1.u = seg.epgeominfo[1].u;
		  gi1.v = seg.epgeominfo[1].v;
		  
		  int locpnum[2] = {0, 0};
		  
		  for (j = 0; j < 2; j++)
		    {
		      PointGeomInfo gi = (j == 0) ? gi0 : gi1;
		      
		      int l;
		      for (l = 0; l < gis.Size() && locpnum[j] == 0; l++)
			{
			  double dist = sqr (gis[l].u-gi.u)+sqr(gis[l].v-gi.v);

			  if (dist < 1e-10)
			    locpnum[j] = l+1;
			}
		      
		      if (locpnum[j] == 0)
			{
			  int pi = (j == 0) ? seg.p1 : seg.p2;
			  meshing.AddPoint (mesh.Point(pi), pi);

			  gis.SetSize (gis.Size()+1);
			  gis[l] = gi;
			  locpnum[j] = l+1;
			}
		    }
		  
		  meshing.AddBoundaryElement (locpnum[0], locpnum[1], gi0, gi1);
		  (*testout) << gi0.u << " " << gi0.v << endl;
		  (*testout) << gi1.u << " " << gi1.v << endl;
	      
		}
	    }
	}






      double maxh = mparam.maxh;
      mparam.checkoverlap = 0;
      //      int noldpoints = mesh->GetNP();
      int noldsurfel = mesh.GetNSE();

      MESHING2_RESULT res;

      try {
        res = meshing.GenerateMesh (mesh, maxh, k);
      }

      catch (SingularMatrixException)
	{
	  (*myerr) << "Singular Matrix" << endl;
	  res = MESHING2_GIVEUP;
	}

      catch (UVBoundsException)
	{
	  (*myerr) << "UV bounds exceeded" << endl;
	  res = MESHING2_GIVEUP;
	}

      projecttype = PARAMETERSPACE;

      if (res != MESHING2_OK)
	{
	  if (notrys == 1)
	    {
	      for (int i = noldsurfel+1; i <= mesh.GetNSE(); i++)
		mesh.DeleteSurfaceElement (i);
	      
	      mesh.Compress();

	      cout << "retry Surface " << k << endl;

	      k--;
	      projecttype*=-1;
	      notrys++;
	      continue;
	    }
	  else
	    {
	      geom.facemeshstatus[k-1] = -1;
	      PrintError ("Problem in Surface mesh generation");
	      surfmesherror++;
	      //	      throw NgException ("Problem in Surface mesh generation");
	    }
	}
      else
	{
	  geom.facemeshstatus[k-1] = 1;
 	}

      notrys = 1;
      
      for (i = oldnf+1; i <= mesh.GetNSE(); i++)
	mesh.SurfaceElement(i).SetIndex (k);

    }

  if (surfmesherror)
    {
      cout << "WARNING! NOT ALL FACES HAVED BEEN MESHED" << endl;
      cout << "SURFACE MESHING ERROR OCCURED IN " << surfmesherror << " FACES:" << endl;
      for (int i = 1; i <= geom.fmap.Extent(); i++)
	  if (geom.facemeshstatus[i-1] == -1)
	    cout << "Face " << i << endl;
      cout << endl;
      cout << "for more information open IGES/STEP Topology Explorer" << endl;
      throw NgException ("Problem in Surface mesh generation");
    }


  if (multithread.terminate || perfstepsend < MESHCONST_OPTSURFACE)
    return;

  multithread.task = "Optimizing surface";
  
  for (k = 1; k <= mesh.GetNFD(); k++)
    {
      (*testout) << "optimize face " << k << endl;
      multithread.percent = 100 * k / (mesh.GetNFD()+1e-10);
      
      FaceDescriptor & fd = mesh.GetFaceDescriptor(k);
      
      PrintMessage (1, "Optimize Surface ", k);
      for (i = 1; i <= mparam.optsteps2d; i++)
	{
	  if (multithread.terminate) return;
	  
	  {
	    MeshOptimize2dOCCSurfaces meshopt(geom);
	    meshopt.SetFaceIndex (k);
	    meshopt.SetImproveEdges (0);
	    meshopt.SetMetricWeight (0.2);
	    meshopt.SetWriteStatus (0);
	    
	    meshopt.EdgeSwapping (mesh, (i > mparam.optsteps2d/2));
	  }
	  
	  if (multithread.terminate) return;
	  {
	    MeshOptimize2dOCCSurfaces meshopt(geom);
	    meshopt.SetFaceIndex (k);
	    meshopt.SetImproveEdges (0);
	    meshopt.SetMetricWeight (0.2);
	    meshopt.SetWriteStatus (0);
	    
	    meshopt.ImproveMesh (mesh);
	  }
	  
	  {
	    MeshOptimize2dOCCSurfaces meshopt(geom);
	    meshopt.SetFaceIndex (k);
	    meshopt.SetImproveEdges (0);
	    meshopt.SetMetricWeight (0.2);
	    meshopt.SetWriteStatus (0);
	    
	    meshopt.CombineImprove (mesh);
	  }
	  
	  if (multithread.terminate) return;
	  {
	    MeshOptimize2dOCCSurfaces meshopt(geom);
	    meshopt.SetFaceIndex (k);
	    meshopt.SetImproveEdges (0);
	    meshopt.SetMetricWeight (0.2);
	    meshopt.SetWriteStatus (0);
	    
	    meshopt.ImproveMesh (mesh);
	  }
	}
      
    }
  
  
  mesh.CalcSurfacesOfNode();
  mesh.Compress();

  multithread.task = savetask;
}

double ComputeH (double kappa)
{
  double hret;
  kappa *= mparam.curvaturesafety;
  
  if (mparam.maxh * kappa < 1)
    hret = mparam.maxh;
  else
    hret = 1 / kappa;
  
  if (mparam.maxh < hret)
    hret = mparam.maxh;
  
  return (hret);
}


class Line
{
public:
  Point<3> p0, p1;
  double Dist (Line l)
  {
    Vec<3> n = p1-p0;
    Vec<3> q = l.p1-l.p0;
    double nq = n*q;
    
    Point<3> p = p0 + 0.5*n;
    double lambda = (p-l.p0)*n / nq;

    if (lambda >= 0 && lambda <= 1)
      {
	double d = (p-l.p0-lambda*q).Length();
	//        if (d < 1e-3) d = 1e99;
	return d;
      }
    else
      return 1e99;
  }
  
  double Length ()
  {
    return (p1-p0).Length();
  };
};



void RestrictHTriangle (gp_Pnt2d & par0, gp_Pnt2d & par1, gp_Pnt2d & par2,
			BRepLProp_SLProps * prop, Mesh & mesh, double maxside, int depth, double h = 0)
{
  gp_Pnt2d parmid;

  parmid.SetX(0.3*(par0.X()+par1.X()+par2.X()));
  parmid.SetY(0.3*(par0.Y()+par1.Y()+par2.Y()));
  
  if (depth == 0)
    {
      prop->SetParameters (parmid.X(), parmid.Y());
      if (!prop->IsCurvatureDefined())
	{
	  (*testout) << "curvature not defined!" << endl;
	  return;
	}
      double curvature = max(fabs(prop->MinCurvature()), fabs(prop->MaxCurvature()));
      if (curvature < 1e-3)
	{
	  (*testout) << "curvature too small (" << curvature << ")!" << endl;
	  //	  return;
	}
      h = ComputeH (curvature+1e-10);
    }
  
  if (h < maxside)
    {
      gp_Pnt2d pm0;
      gp_Pnt2d pm1;
      gp_Pnt2d pm2;
      
      pm0.SetX(0.5*(par1.X()+par2.X())); pm0.SetY(0.5*(par1.Y()+par2.Y()));
      pm1.SetX(0.5*(par0.X()+par2.X())); pm1.SetY(0.5*(par0.Y()+par2.Y()));
      pm2.SetX(0.5*(par1.X()+par0.X())); pm2.SetY(0.5*(par1.Y()+par0.Y()));

      RestrictHTriangle (pm0, pm1, pm2, prop, mesh, maxside/2, depth+1, h);
      RestrictHTriangle (par0, pm1, pm2, prop, mesh, maxside/2, depth+1, h);
      RestrictHTriangle (par1, pm0, pm2, prop, mesh, maxside/2, depth+1, h);
      RestrictHTriangle (par2, pm1, pm0, prop, mesh, maxside/2, depth+1, h);
    }
  else
    {
      prop->SetParameters (parmid.X(), parmid.Y());
      gp_Pnt pnt = prop->Value();
      Point3d p3d(pnt.X(), pnt.Y(), pnt.Z());
      mesh.RestrictLocalH (p3d, h);

      prop->SetParameters (par0.X(), par0.Y());
      pnt = prop->Value();
      p3d = Point3d(pnt.X(), pnt.Y(), pnt.Z());
      mesh.RestrictLocalH (p3d, h);

      prop->SetParameters (par1.X(), par1.Y());
      pnt = prop->Value();
      p3d = Point3d(pnt.X(), pnt.Y(), pnt.Z());
      mesh.RestrictLocalH (p3d, h);

      prop->SetParameters (par2.X(), par2.Y());
      pnt = prop->Value();
      p3d = Point3d(pnt.X(), pnt.Y(), pnt.Z());
      mesh.RestrictLocalH (p3d, h);

      //      (*testout) << "p = " << p3d << ", h = " << h << ", maxside = " << maxside << endl;
      /*
      (*testout) << pnt.X() << " " << pnt.Y() << " " << pnt.Z() << endl;

      prop->SetParameters (par0.X(), par0.Y());
      pnt = prop->Value();
      (*testout) << pnt.X() << " " << pnt.Y() << " " << pnt.Z() << endl;

      prop->SetParameters (par1.X(), par1.Y());
      pnt = prop->Value();
      (*testout) << pnt.X() << " " << pnt.Y() << " " << pnt.Z() << endl;

      prop->SetParameters (par2.X(), par2.Y());
      pnt = prop->Value();
      (*testout) << pnt.X() << " " << pnt.Y() << " " << pnt.Z() << endl;
      */
    }
}




int OCCGenerateMesh (OCCGeometry & geom,
		  Mesh *& mesh,
		  int perfstepsstart, int perfstepsend,
		  char * optstr)
{
  int i, j;

  multithread.percent = 0;

  if (perfstepsstart <= MESHCONST_ANALYSE)
    {
      delete mesh;
      mesh = new Mesh();

      mesh->SetGlobalH (mparam.maxh);

      ARRAY<double> maxhdom;
      maxhdom.SetSize (geom.NrSolids());
      maxhdom = mparam.maxh;
      
      mesh->SetMaxHDomain (maxhdom);
      
      Box<3> bb = geom.GetBoundingBox();
      bb.Increase (bb.Diam()/10);
      
      mesh->SetLocalH (bb.PMin(), bb.PMax(), 0.5);
    

      if (mparam.uselocalh)
	{

	  char * savetask = multithread.task;
	  multithread.percent = 0;

	  mesh->SetLocalH (bb.PMin(), bb.PMax(), mparam.grading);

	  int nedges = geom.emap.Extent();
	  int i;

	  double maxedgelen = 0;
	  double minedgelen = 1e99;

	  
	  multithread.task = "Setting local mesh size (elements per edge)";

	  // setting elements per edge

	  for (i = 1; i <= nedges && !multithread.terminate; i++)
	    {
	      TopoDS_Edge e = TopoDS::Edge (geom.emap(i));
	      multithread.percent = 100 * (i-1)/double(nedges);
	      if (BRep_Tool::Degenerated(e)) continue;

	      GProp_GProps system;	       
	      BRepGProp::LinearProperties(e, system);
	      double len = system.Mass();

	      if (len < IGNORECURVELENGTH)
		{
		  (*testout) << "ignored" << endl;
		  continue;
		}


	      double localh = len/mparam.segmentsperedge;
	      double s0, s1;
	      Handle(Geom_Curve) c = BRep_Tool::Curve(e, s0, s1);

	      maxedgelen = max (maxedgelen, len);
	      minedgelen = min (minedgelen, len);

	      int j;
	      int maxj = (int) ceil (localh);
	      for (j = 0; j <= localh; j++)
		{
		  gp_Pnt pnt = c->Value (s0+double(j)/maxj*(s1-s0));
		  mesh->RestrictLocalH (Point3d(pnt.X(), pnt.Y(), pnt.Z()), localh);
		}
	    }




	  multithread.task = "Setting local mesh size (edge curvature)";

	  
	  // setting edge curvature

	  //	  int nsections = 10;
	  int nsections = 20;

	  for (i = 1; i <= nedges && !multithread.terminate; i++)
	    {
	      multithread.percent = 100 * (i-1)/double(nedges);
	      TopoDS_Edge edge = TopoDS::Edge (geom.emap(i));
	      if (BRep_Tool::Degenerated(edge)) continue;
	      double s0, s1;
	      Handle(Geom_Curve) c = BRep_Tool::Curve(edge, s0, s1);
	      BRepAdaptor_Curve brepc(edge);
 	      BRepLProp_CLProps prop(brepc, 2, 1e-5);
	      
	      int j;
	      for (j = 1; j <= nsections; j++)
		//	      for (j = 0; j < nsections; j++)
		{
		  double s = s0 + j/(double) nsections * (s1-s0);
		  prop.SetParameter (s);
		  double curvature = prop.Curvature();

		  if (curvature >= 1e99) continue;

		  gp_Pnt pnt = c->Value (s);

		  mesh->RestrictLocalH (Point3d(pnt.X(), pnt.Y(), pnt.Z()),
					ComputeH (fabs(curvature)));		  
		}
	    }

	  

	  multithread.task = "Setting local mesh size (face curvature)";

	  // setting face curvature
	  
	  int nfaces = geom.fmap.Extent();
	  
	  for (i = 1; i <= nfaces && !multithread.terminate; i++)
	    {
	      multithread.percent = 100 * (i-1)/double(nfaces);
	      TopoDS_Face face = TopoDS::Face(geom.fmap(i));
	      TopLoc_Location loc;
	      Handle(Geom_Surface) surf = BRep_Tool::Surface (face);
	      Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation (face, loc);
	      if (triangulation.IsNull()) continue;
	      
	      BRepAdaptor_Surface sf(face, Standard_True);
	      BRepLProp_SLProps prop(sf, 2, 1e-5);

	      int ntriangles = triangulation -> NbTriangles();
	      for (j = 1; j <= ntriangles; j++)
		{
		  int k;
		  gp_Pnt p[3];
		  gp_Pnt2d par[3];

		  for (k = 1; k <=3; k++)
		    {
		      int n = triangulation->Triangles()(j)(k);
		      p[k-1] = triangulation->Nodes()(n).Transformed(loc);
		      par[k-1] = triangulation->UVNodes()(n);
		    }

		  double maxside = 0;
		  maxside = max (maxside, p[0].Distance(p[1]));
		  maxside = max (maxside, p[0].Distance(p[2]));
		  maxside = max (maxside, p[1].Distance(p[2]));

		  RestrictHTriangle (par[0], par[1], par[2], &prop, *mesh, maxside, 0);
		}
	    }



	  // setting close edges

	  if (stlparam.resthcloseedgeenable)
	    {
	      multithread.task = "Setting local mesh size (close edges)";
	      
	      int sections = 100;
	      
	      ARRAY<Line> lines(sections*nedges);
	      
	      Box3dTree* searchtree =
		new Box3dTree (bb.PMin(), bb.PMax());
	      
	      int nlines = 0;
	      for (int i = 1; i <= nedges && !multithread.terminate; i++)
		{
		  TopoDS_Edge edge = TopoDS::Edge (geom.emap(i));
		  if (BRep_Tool::Degenerated(edge)) continue;

		  double s0, s1;
		  Handle(Geom_Curve) c = BRep_Tool::Curve(edge, s0, s1);
		  BRepAdaptor_Curve brepc(edge);
		  BRepLProp_CLProps prop(brepc, 1, 1e-5);
		  prop.SetParameter (s0);

		  gp_Vec d0 = prop.D1().Normalized();
		  double s_start = s0;
		  int count = 0;
		  for (int j = 1; j <= sections; j++)
		    {
		      double s = s0 + (s1-s0)*(double)j/(double)sections;
		      prop.SetParameter (s);
		      gp_Vec d1 = prop.D1().Normalized();
		      double cosalpha = fabs(d0*d1);
		      if ((j == sections) || (cosalpha < cos(10.0/180.0*M_PI)))
			{
			  count++;
			  gp_Pnt p0 = c->Value (s_start);
			  gp_Pnt p1 = c->Value (s);
			  lines[nlines].p0 = Point<3> (p0.X(), p0.Y(), p0.Z());
			  lines[nlines].p1 = Point<3> (p1.X(), p1.Y(), p1.Z());
		      
			  Box3d box;
			  box.SetPoint (Point3d(lines[nlines].p0));
			  box.AddPoint (Point3d(lines[nlines].p1));

			  searchtree->Insert (box.PMin(), box.PMax(), nlines+1);
			  nlines++;

			  s_start = s;
			  d0 = d1;
			}
		    }
		}
		
	      ARRAY<int> linenums;
	      
	      for (int i = 0; i < nlines; i++)
		{
		  multithread.percent = (100*i)/double(nlines);
		  Line & line = lines[i];
		  
		  Box3d box;
		  box.SetPoint (Point3d(line.p0));
		  box.AddPoint (Point3d(line.p1));
		  double maxhline = max (mesh->GetH(box.PMin()),
					 mesh->GetH(box.PMax()));
		  box.Increase(maxhline);

		  double mindist = 1e99;
		  linenums.SetSize(0);
		  searchtree->GetIntersecting(box.PMin(),box.PMax(),linenums);

		  for (int j = 0; j < linenums.Size(); j++)
		    {
		      int num = linenums[j]-1;
		      if (i == num) continue;
		      if ((line.p0-lines[num].p0).Length2() < 1e-15) continue;
		      if ((line.p0-lines[num].p1).Length2() < 1e-15) continue;
		      if ((line.p1-lines[num].p0).Length2() < 1e-15) continue;
		      if ((line.p1-lines[num].p1).Length2() < 1e-15) continue;
		      mindist = min (mindist, line.Dist(lines[num]));
		    }
		  
		  mindist *= stlparam.resthcloseedgefac;

		  if (mindist < 1e-3) 
		    {
		      (*testout) << "extremely small local h: " << mindist
				 << " --> setting to 1e-3" << endl;
		      mindist = 1e-3;
		    }

		  mesh->RestrictLocalHLine(line.p0, line.p1, mindist);
		}
	    }
				   


	  multithread.task = savetask;

	}
    }


  if (multithread.terminate || perfstepsend <= MESHCONST_ANALYSE) 
    return TCL_OK;

  if (perfstepsstart <= MESHCONST_MESHEDGES)
    {
      FindEdges (geom, *mesh);

      /*
      cout << "Removing redundant points" << endl;
      
      int i, j;
      int np = mesh->GetNP();
      ARRAY<int> equalto;

      equalto.SetSize (np);
      equalto = 0;

      for (i = 1; i <= np; i++)
	{
	  for (j = i+1; j <= np; j++)
	    {
	      if (!equalto[j-1] && (Dist2 (mesh->Point(i), mesh->Point(j)) < 1e-12))
		equalto[j-1] = i;
	    }
	}

      for (i = 1; i <= np; i++)
	if (equalto[i-1])
	  {
	    cout << "Point " << i << " is equal to Point " << equalto[i-1] << endl;
	    for (j = 1; j <= mesh->GetNSeg(); j++)
	      {
		Segment & seg = mesh->LineSegment(j);
		if (seg.p1 == i) seg.p1 = equalto[i-1];
		if (seg.p2 == i) seg.p2 = equalto[i-1];
	      }
	  }

      cout << "Removing degenerated segments" << endl;
      for (j = 1; j <= mesh->GetNSeg(); j++)
	{
	  Segment & seg = mesh->LineSegment(j);
	  if (seg.p1 == seg.p2)
	    {
	      mesh->DeleteSegment(j);
	      cout << "Deleting Segment " << j << endl;
	    }
	}

      mesh->Compress();
      */

      /*
      for (int i = 1; i <= geom.fmap.Extent(); i++)
	{
	  Handle(Geom_Surface) hf1 =
	    BRep_Tool::Surface(TopoDS::Face(geom.fmap(i)));
	  for (int j = i+1; j <= geom.fmap.Extent(); j++)
	    {
	      Handle(Geom_Surface) hf2 = 
		BRep_Tool::Surface(TopoDS::Face(geom.fmap(j)));
	      if (hf1 == hf2) cout << "face " << i << " and face " << j << " lie on same surface" << endl;
	    }
	}
      */



#ifdef LOG_STREAM      
      (*logout) << "Edges meshed" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl;
#endif
    }

   if (multithread.terminate || perfstepsend <= MESHCONST_MESHEDGES)
    return TCL_OK;

  if (perfstepsstart <= MESHCONST_MESHSURFACE)
    {
      OCCMeshSurface (geom, *mesh, perfstepsend);  
      if (multithread.terminate) return TCL_OK;
      
#ifdef LOG_STREAM
      (*logout) << "Surfaces meshed" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl;
#endif      
      
#ifdef STAT_STREAM
      (*statout) << mesh->GetNSeg() << " & "
		 << mesh->GetNSE() << " & - &" 
		 << GetTime() << " & " << endl;
#endif  
      
      //      MeshQuality2d (*mesh);
      mesh->CalcSurfacesOfNode();
    }

  if (multithread.terminate || perfstepsend <= MESHCONST_OPTSURFACE)
    return TCL_OK;
  

  if (perfstepsstart <= MESHCONST_MESHVOLUME)
    {
      multithread.task = "Volume meshing";
      
      MESHING3_RESULT res =
	MeshVolume (mparam, *mesh);

      if (res != MESHING3_OK) return TCL_ERROR;
      
      if (multithread.terminate) return TCL_OK;
      
      RemoveIllegalElements (*mesh);
      if (multithread.terminate) return TCL_OK;

      MeshQuality3d (*mesh);
      
#ifdef STAT_STREAM
      (*statout) << GetTime() << " & ";
#endif      
      
#ifdef LOG_STREAM
      (*logout) << "Volume meshed" << endl
		<< "time = " << GetTime() << " sec" << endl
	    << "points: " << mesh->GetNP() << endl;
#endif
    }

  if (multithread.terminate || perfstepsend <= MESHCONST_MESHVOLUME)
    return TCL_OK;


  if (perfstepsstart <= MESHCONST_OPTVOLUME)
    {
      multithread.task = "Volume optimization";
      
      OptimizeVolume (mparam, *mesh);
      if (multithread.terminate) return TCL_OK;
      
#ifdef STAT_STREAM
      (*statout) << GetTime() << " & "
		 << mesh->GetNE() << " & "
		 << mesh->GetNP() << " " << '\\' << '\\' << " \\" << "hline" << endl;
#endif      

#ifdef LOG_STREAM      
      (*logout) << "Volume optimized" << endl
		<< "time = " << GetTime() << " sec" << endl
	    << "points: " << mesh->GetNP() << endl;
#endif

     
      cout << "Optimization complete" << endl;
      
    }

  (*testout) << "NP: " << mesh->GetNP() << endl;
  for (i = 1; i <= mesh->GetNP(); i++)
      (*testout) << mesh->Point(i) << endl;
 
  (*testout) << endl << "NSegments: " << mesh->GetNSeg() << endl;
  for (i = 1; i <= mesh->GetNSeg(); i++)
    (*testout) << mesh->LineSegment(i) << endl;
   


  return TCL_OK;
}
}

#endif

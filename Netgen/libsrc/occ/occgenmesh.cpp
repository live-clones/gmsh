#ifdef OCCGEOMETRY

#include <mystdlib.h>
#include <occgeom.hpp>
#include <meshing.hpp>

namespace netgen
{

#include "occmeshsurf.hpp"

#define TCL_OK 0
#define TCL_ERROR 1


void DivideEdge (TopoDS_Edge & edge, ARRAY <MeshPoint> & ps, ARRAY<double> & params, Mesh & mesh)
{
  double s0, s1;
  int j;
  double maxh = mparam.maxh;
  int nsubedges = 1;  
  gp_Pnt pnt;
  double svalue[1000];

  GProp_GProps system;
  BRepGProp::LinearProperties(edge, system);
  double L = system.Mass();

  Handle(Geom_Curve) c = BRep_Tool::Curve(edge, s0, s1);

  double s = s0;
  j = 0;
  while (s < s1)
    {
      pnt = c->Value(s);
      svalue[j] = s;
      s += mesh.GetH(Point3d(pnt.X(), pnt.Y(), pnt.Z()))*(s1-s0)/L;
      j++;
      if (s < s1) nsubedges++;
    }
  svalue[j] = s;
  double stretchfac = (s1-s0)/(s-s0);

  if (nsubedges < mparam.segmentsperedge)
    {
      nsubedges = 1;
      s = s0;
      j = 0;
      while (s < s1)
	{
	  pnt = c->Value(s);
	  svalue[j] = s;
	  s += min ((s1-s0)/mparam.segmentsperedge, mesh.GetH(Point3d(pnt.X(), pnt.Y(), pnt.Z()))*(s1-s0)/L);
	  j++;
	  if (s < s1) nsubedges++; 
	}
      svalue[j] = s;
      stretchfac = (s1-s0)/(s-s0);
    }

  ps.SetSize (nsubedges-1);
  params.SetSize (nsubedges+1);

  for (j = 1; j < nsubedges; j++)
    {
      params[j] = s0+stretchfac*(svalue[j]-s0);
      pnt = c->Value(params[j]);
      ps[j-1] = MeshPoint (Point3d(pnt.X(), pnt.Y(), pnt.Z()));
    } 

  params[0] = s0;
  params[nsubedges] = s1;
}



static void FindEdges (OCCGeometry & geom, Mesh & mesh)
{
  int i, j;
  
  TopExp_Explorer exp0, exp01, exp1, exp2, exp3;
  
  int nvertices = geom.vmap.Extent();
  int nedges = geom.emap.Extent();
  for (i = 1; i <= nvertices; i++)
    {
      gp_Pnt pnt = BRep_Tool::Pnt (TopoDS::Vertex(geom.vmap(i)));
      MeshPoint mp( Point3d(pnt.X(), pnt.Y(), pnt.Z()) );
      mesh.AddPoint (mp);
    }
  
  int facenr = 0;
  int edgenr = 0;
  
  for (exp0.Init(geom.shape, TopAbs_SOLID); exp0.More(); exp0.Next())
    for (exp01.Init(exp0.Current(), TopAbs_SHELL); exp01.More(); exp01.Next())
      {
	TopoDS_Shape shell = exp01.Current();
	
	for (exp1.Init(shell, TopAbs_FACE); exp1.More(); exp1.Next())
	  {
	    TopoDS_Face face = TopoDS::Face(exp1.Current());

	    facenr = geom.fmap.FindIndex (face);
	    
	    mesh.AddFaceDescriptor (FaceDescriptor(facenr, 1, 0, 0));
	    Handle(Geom_Surface) occface = BRep_Tool::Surface(face);
	    
	    for (exp2.Init (face, TopAbs_WIRE); exp2.More(); exp2.Next())
	      {
		TopoDS_Shape wire = exp2.Current();

		for (exp3.Init (wire, TopAbs_EDGE); exp3.More(); exp3.Next())
		  {
		    TopoDS_Edge edge = TopoDS::Edge (exp3.Current());
		    if (BRep_Tool::Degenerated(edge)) continue;

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
			seg.epgeominfo[0].u = p2d.X();
			seg.epgeominfo[0].v = p2d.Y();
			p2d = cof->Value(params[i]);
			seg.epgeominfo[1].u = p2d.X();
			seg.epgeominfo[1].v = p2d.Y();
			
			if (edge.Orientation() == TopAbs_REVERSED)
			  {
			    swap (seg.p1, seg.p2);
			    swap (seg.epgeominfo[0].dist, seg.epgeominfo[1].dist);
			    swap (seg.epgeominfo[0].u, seg.epgeominfo[1].u);
			    swap (seg.epgeominfo[0].v, seg.epgeominfo[1].v);
			  }
			
			
			mesh.AddSegment (seg);
			
			// (*testout) << "seg" << seg.edgenr << ": " << seg.p1 << " - " << seg.p2 << endl;
		      }
		  }
	      }
	  }
      }
  mesh.CalcSurfacesOfNode();
}  




static void OCCMeshSurface (OCCGeometry & geom, Mesh & mesh, int perfstepsend)
{
  int i, j, k;
  int changed;

  char * savetask = multithread.task;
  multithread.task = "Surface meshing";
  
  int noldp = mesh.GetNP();

  double starttime = GetTime();

  ARRAY<int> glob2loc(noldp);

  for (k = 1; k <= mesh.GetNFD(); k++)
    {

      (*testout) << "mesh face " << k << endl;
      multithread.percent = 100 * k / (mesh.GetNFD()+1e-10);

      FaceDescriptor & fd = mesh.GetFaceDescriptor(k);

      PrintMessage (2, "Surface ", k, " / ", mesh.GetNFD());

      int oldnf = mesh.GetNSE();

      
      Box<3> bb (Point<3> (-geom.MaxSize(), -geom.MaxSize(), -geom.MaxSize()), 
		 Point<3> (geom.MaxSize(), geom.MaxSize(), geom.MaxSize()));

      Meshing2OCCSurfaces meshing(TopoDS::Face(geom.fmap(k)), bb); 
      //      Meshing2OCCSurfaces meshing(f2, bb); 
      meshing.SetStartTime (starttime);

      /*
      for (i = 1; i <= noldp; i++)
	{
	  // (*testout) << "Add point " << mesh.Point(i) << endl;
	  meshing.AddPoint (mesh.Point(i), i);
	}
      */

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
	      
	      (*testout) << "Add BE " << seg.p1 << "-" << seg.p2 << " (" << ")" << endl;
	    }
	}

      double maxh = mparam.maxh;

      MESHING2_RESULT res =
	meshing.GenerateMesh (mesh, maxh, k);

      if (res != MESHING2_OK)
	{
	  PrintError ("Problem in Surface mesh generation");
	  throw NgException ("Problem in Surface mesh generation");
	}
      
      for (i = oldnf+1; i <= mesh.GetNSE(); i++)
	mesh.SurfaceElement(i).SetIndex (k);

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


int OCCGenerateMesh (OCCGeometry & geom,
		  Mesh *& mesh,
		  int perfstepsstart, int perfstepsend,
		  char * optstr)
{
  int i, j;

  if (perfstepsstart <= MESHCONST_ANALYSE)
    {
      delete mesh;
      mesh = new Mesh();

      mesh->SetGlobalH (mparam.maxh);

      ARRAY<double> maxhdom(1);
      maxhdom[0] = mparam.maxh;
      double maxsize = geom.MaxSize(); 
      
      mesh->SetMaxHDomain (maxhdom);
      mesh->SetLocalH (Point<3>(-maxsize, -maxsize, -maxsize),
		       Point<3>(maxsize, maxsize, maxsize),
		       0.5);

      if (mparam.uselocalh)
	{

	  char * savetask = multithread.task;
	  multithread.task = "Setting local mesh size";
  
	  double maxsize = geom.MaxSize(); 
	  mesh->SetLocalH (Point<3>(-maxsize, -maxsize, -maxsize),
			   Point<3>(maxsize, maxsize, maxsize),
			   mparam.grading);

	  cout << "maxsize = " << maxsize << endl;
	  
	  int nfaces = geom.fmap.Extent();
	  
	  int i;
	  for (i = 1; i <= nfaces; i++)
	    {
	      (*testout) << "face " << i << endl;
	      multithread.percent = 100 * (i-1)/double(nfaces);
	      TopoDS_Face face = TopoDS::Face(geom.fmap(i));
	      TopLoc_Location loc;
	      Handle(Geom_Surface) surf = BRep_Tool::Surface (face);
	      Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation (face, loc);
	      BRepAdaptor_Surface sf(face, Standard_False);
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
		      p[k-1] = triangulation->Nodes()(n);
		      par[k-1] = triangulation->UVNodes()(n);
		    }

		  double lp2p0 = p[2].Distance(p[0]);
		  double lp2p1 = p[2].Distance(p[1]);

		  prop.SetParameters (p[2].X(), p[2].Y());
		  double h;

		  if (!prop.IsCurvatureDefined()) continue;

		  h = ComputeH (max(fabs(prop.MinCurvature()),
				    fabs(prop.MaxCurvature()))+1e-10);
		  
		  double h0 = h/lp2p0;
		  double h1 = h/lp2p1;

		  h0 = min (h0, 1.0);
		  h1 = min (h1, 1.0);

		  double l0, l1, l2;
		  for (l0 = 0; l0 <= 1; l0+=h0)
		    for (l1 = 0; l1 <= 1-l0; l1+=h1)
		      {
			l2 = 1-l0-l1;
			double u = l0*par[0].X() + l1*par[1].X() + l2*par[2].X();
			double v = l0*par[0].Y() + l1*par[1].Y() + l2*par[2].Y();

			prop.SetParameters (u, v);

			if (!prop.IsCurvatureDefined()) continue;

			gp_Pnt pnt = prop.Value();

			mesh->RestrictLocalH (Point3d(pnt.X(), pnt.Y(), pnt.Z()),
					      ComputeH (max(fabs(prop.MinCurvature()),
							    fabs(prop.MaxCurvature()))+1e-10));
		      }
		  
		}

	      /*
	      // schmale lange drei+viereckerl
	      TopExp_Explorer exp;
	      for (exp.Init (face, TopAbs_WIRE); exp.More(); exp.Next())
		{
		  bool done = 0;
		  BRepTools_WireExplorer wexp;
		  double L[4];
		  GProp_GProps system;
		  int i = 0;
		  double minL = 1e10;

		  for (wexp.Init (TopoDS::Wire(exp.Current())); wexp.More() && i < 4; wexp.Next())
		    {
		      BRepGProp::LinearProperties(wexp.Current(), system);
		      L[i++] = system.Mass();
		      minL = min (minL, L[i-1]);
		    }

		  if (i == 4 && wexp.More()) continue; // more that 4 edges

		    
		  double h = minL;

		  for (j = 1; j <= ntriangles; j++)
		    {
		      int k;
		      gp_Pnt p[3];
		      gp_Pnt2d par[3];

		      for (k = 1; k <=3; k++)
			{
			  int n = triangulation->Triangles()(j)(k);
			  p[k-1] = triangulation->Nodes()(n);
			  par[k-1] = triangulation->UVNodes()(n);
			}

		      double lp2p0 = p[2].Distance(p[0]);
		      double lp2p1 = p[2].Distance(p[1]);

		      prop.SetParameters (p[2].X(), p[2].Y());
		  
		      double h0 = h/lp2p0;
		      double h1 = h/lp2p1;

		      h0 = min (h0, 1.0);
		      h1 = min (h1, 1.0);

		      double l0, l1, l2;
		      for (l0 = 0; l0 <= 1; l0+=h0)
		      for (l1 = 0; l1 <= 1-l0; l1+=h1)
		      {
			l2 = 1-l0-l1;
			double u = l0*par[0].X() + l1*par[1].X() + l2*par[2].X();
			double v = l0*par[0].Y() + l1*par[1].Y() + l2*par[2].Y();

			prop.SetParameters (u, v);
			gp_Pnt pnt = prop.Value();

			mesh->RestrictLocalH (Point3d(pnt.X(), pnt.Y(), pnt.Z()), h);
		      }
		      
		    }
		}
	      */


	    }
	  
	  multithread.task = savetask;
	}
    }


  if (multithread.terminate || perfstepsend <= MESHCONST_ANALYSE) 
    return TCL_OK;

  if (perfstepsstart <= MESHCONST_MESHEDGES)
    {
      FindEdges (geom, *mesh);

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
      
      OptimizeVolume (mparam, *mesh, NULL);
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

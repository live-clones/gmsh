#include <mystdlib.h>


// #include <FlexLexer.h>

#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>
#include <stlgeom.hpp>
#include <meshing.hpp>

namespace netgen
{
ARRAY<SpecialPoint> specpoints;
static ARRAY<MeshPoint> spoints;

#define TCL_OK 0
#define TCL_ERROR 1


static void FindPoints (CSGeometry & geom, Mesh & mesh,
			const char * filename)
{
  int i;
  PrintMessage (1, "Start Findpoints");

  char * savetask = multithread.task;
  multithread.task = "Find points";

  for (i = 0; i < geom.GetNUserPoints(); i++)
    {
      mesh.AddPoint (geom.GetUserPoint (i));
      mesh.AddLockedPoint (PointIndex (i+1));
    }

  SpecialPointCalculation spc;

  if (spoints.Size() == 0)
    spc.CalcSpecialPoints (geom, spoints);

  PrintMessage (2, "Analyze spec points");
  spc.AnalyzeSpecialPoints (geom, spoints, specpoints);
  
  PrintMessage (5, "done");

  (*testout) << specpoints.Size() << " special points:" << endl;
  for (i = 0; i < specpoints.Size(); i++)
    specpoints[i].Print (*testout);

  /*
  for (i = 1; i <= geom.identifications.Size(); i++)
    geom.identifications.Elem(i)->IdentifySpecialPoints (specpoints);
  */
  multithread.task = savetask;
}



static void FindEdges (CSGeometry & geom, Mesh & mesh,
		       const char * filename)
{
  int i, k;
  
  EdgeCalculation ec (geom, specpoints);
  ec.Calc (mparam.maxh, mesh);

  for (i = 1; i <= geom.singedges.Size(); i++)
    geom.singedges.Elem(i)->FindPointsOnEdge (mesh);
  for (i = 1; i <= geom.singpoints.Size(); i++)
    geom.singpoints.Elem(i)->FindPoints (mesh);

  //  SaveEdges (mesh, filename, h, "edges.out");

  for (i = 1; i <= mesh.GetNSeg(); i++)
    {
      int ok = 0;
      for (k = 1; k <= mesh.GetNFD(); k++)
	if (mesh.GetFaceDescriptor(k).SegmentFits (mesh.LineSegment(i)))
	  ok = k;

      if (!ok)
	ok = mesh.AddFaceDescriptor (FaceDescriptor (mesh.LineSegment(i)));

      mesh.LineSegment(i).si = ok;
    }

  (*testout) << "identify points after line meshing" << endl;
  for (i = 0; i < geom.identifications.Size(); i++)
    geom.identifications[i]->IdentifyPoints (mesh);
  for (i = 0; i < geom.identifications.Size(); i++)
    geom.identifications[i]->IdentifyFaces (mesh);

  //  mesh.Save ("lines.vol");
}  


static void MeshSurface (CSGeometry & geom, Mesh & mesh)
{
  int i, j, k;
  int changed;

  char * savetask = multithread.task;
  multithread.task = "Surface meshing";

  
  ARRAY<Segment> segments;
  int noldp = mesh.GetNP();

  double starttime = GetTime();


  // find master faces from identified
  ARRAY<int> masterface(mesh.GetNFD());
  for (i = 1; i <= mesh.GetNFD(); i++)
    masterface.Elem(i) = i;
  
  ARRAY<INDEX_2> fpairs;
  do
    {
      changed = 0;
      for (i = 0; i < geom.identifications.Size(); i++)
	{
	  geom.identifications[i]->GetIdentifiedFaces (fpairs);

	  for (j = 0; j < fpairs.Size(); j++)
	    {
	      if (masterface.Get(fpairs[j].I1()) <
		  masterface.Get(fpairs[j].I2()))
		{
		  changed = 1;
		  masterface.Elem(fpairs[j].I2()) =
		    masterface.Elem(fpairs[j].I1());
		}
	      if (masterface.Get(fpairs[j].I2()) <
		  masterface.Get(fpairs[j].I1()))
		{
		  changed = 1;
		  masterface.Elem(fpairs[j].I1()) =
		    masterface.Elem(fpairs[j].I2());
		}
	    }
	}
    }
  while (changed);


  int bccnt=0;
  for (k = 0; k < geom.GetNSurf(); k++)
    bccnt = max2 (bccnt, geom.GetSurface(k)->GetBCProperty());

  for (k = 1; k <= mesh.GetNFD(); k++)
    {
      FaceDescriptor & fd = mesh.GetFaceDescriptor(k);
      const Surface * surf = geom.GetSurface(fd.SurfNr());

      if (fd.TLOSurface() && 
	  geom.GetTopLevelObject(fd.TLOSurface()-1) -> GetBCProp() > 0)
	fd.SetBCProperty (geom.GetTopLevelObject(fd.TLOSurface()-1) -> GetBCProp());
      else if (surf -> GetBCProperty() != -1)
	fd.SetBCProperty (surf->GetBCProperty());
      else
	{
	  bccnt++;
	  fd.SetBCProperty (bccnt);
	}      

      for (int l = 0; l < geom.bcmodifications.Size(); l++)
	{
	  if (geom.GetSurfaceClassRepresentant (fd.SurfNr()) == 
	      geom.GetSurfaceClassRepresentant (geom.bcmodifications[l].si) &&
	      (fd.DomainIn() == geom.bcmodifications[l].tlonr+1 ||
	       fd.DomainOut() == geom.bcmodifications[l].tlonr+1))
	    {
	      cout << "modify, surfnr = " << fd.SurfNr() << ", dom = " 
		   << geom.bcmodifications[l].tlonr+1 << endl;
	      fd.SetBCProperty (geom.bcmodifications[l].bcnr);
	    }
	}
    }

  /*
  (*testout) << "Face descriptors:" << endl;
  for (k = 1; k <= mesh.GetNFD(); k++)
    (*testout) << "fd(" << k << ") = " << mesh.GetFaceDescriptor(k) << endl;
  */

  // assemble edge hash-table
  (*testout) << "calc surf before surface" << endl;
  mesh.CalcSurfacesOfNode();

  for (k = 1; k <= mesh.GetNFD(); k++)
    {
      (*testout) << "mesh face " << k << endl;
      multithread.percent = 100 * k / (mesh.GetNFD()+1e-10);

      if (masterface.Get(k) != k)
	continue;

      FaceDescriptor & fd = mesh.GetFaceDescriptor(k);

      (*testout) << "Surface " << k << endl;
      (*testout) << "Face Descriptor: " << fd << endl;
      PrintMessage (1, "Surface ", k, " / ", mesh.GetNFD());

      int oldnf = mesh.GetNSE();
      
      const Surface * surf =
	geom.GetSurface((mesh.GetFaceDescriptor(k).SurfNr()));

      /*
      if (surf -> GetBCProperty() != -1)
	fd.SetBCProperty (surf->GetBCProperty());
      else
	{
	  bccnt++;
	  fd.SetBCProperty (bccnt);
	}
      */


      Meshing2Surfaces meshing(*surf, geom.BoundingBox());
      meshing.SetStartTime (starttime);

      for (PointIndex pi = PointIndex::BASE; 
	   pi < noldp+PointIndex::BASE; pi++)
	{
	  meshing.AddPoint (mesh[pi], pi);
	}
  
      segments.SetSize (0);

      for (i = 1; i <= mesh.GetNSeg(); i++)
	{
	  Segment * seg = &mesh.LineSegment(i);
	  if (seg->si == k)
	    {
	      segments.Append (*seg);
	      (*testout) << "add segment " << seg->p1 << "-" << seg->p2 << endl;
	    }
	}

      for (i = 1; i <= geom.identifications.Size(); i++)
	geom.identifications.Get(i)->
	  BuildSurfaceElements(segments, mesh, surf);

      // (*testout) << "Mesh surface, elements:" << endl;
      for (SegmentIndex si = 0; si < segments.Size(); si++)
	{
	  PointGeomInfo gi;
	  gi.trignum = k;
	  /*
	  (*testout) << segments[si].p1 << " - " << segments[si].p2 << endl;
	  (*testout) << mesh[segments[si].p1] << " - " 
		     << mesh[segments[si].p2] << endl;
	  */
	  meshing.AddBoundaryElement (segments[si].p1 + 1 - PointIndex::BASE, 
				      segments[si].p2 + 1 - PointIndex::BASE, 
				      gi, gi);
	}

      double maxh = mparam.maxh;
      if (fd.DomainIn() != 0)
	{
	  const Solid * s1 = 
	    geom.GetTopLevelObject(fd.DomainIn()-1) -> GetSolid();
	  if (s1->GetMaxH() < maxh)
	    maxh = s1->GetMaxH();
	  maxh = min2(maxh, geom.GetTopLevelObject(fd.DomainIn()-1)->GetMaxH());
	}
      if (fd.DomainOut() != 0)
	{
	  const Solid * s1 = 
	    geom.GetTopLevelObject(fd.DomainOut()-1) -> GetSolid();
	  if (s1->GetMaxH() < maxh)
	    maxh = s1->GetMaxH();
	  maxh = min2(maxh, geom.GetTopLevelObject(fd.DomainOut()-1)->GetMaxH());
	}
      if (fd.TLOSurface() != 0)
	{
	  double hi = geom.GetTopLevelObject(fd.TLOSurface()-1) -> GetMaxH();
	  if (hi < maxh) maxh = hi;
	}

      (*testout) << "domin = " << fd.DomainIn() << ", domout = " << fd.DomainOut()
		 << ", tlo-surf = " << fd.TLOSurface()
		 << " mpram.maxh = " << mparam.maxh << ", maxh = " << maxh << endl;


      MESHING2_RESULT res =
	meshing.GenerateMesh (mesh, maxh, k);

      if (res != MESHING2_OK)
	{
	  PrintError ("Problem in Surface mesh generation");
	  throw NgException ("Problem in Surface mesh generation");
	}
      if (multithread.terminate) return;

      
      for (i = oldnf+1; i <= mesh.GetNSE(); i++)
	mesh.SurfaceElement(i).SetIndex (k);


      //      mesh.CalcSurfacesOfNode();
      if (segments.Size())   
	{ 
	  // surface was meshed, not copied
	  PrintMessage (2, "Optimize Surface");
	  for (i = 1; i <= mparam.optsteps2d; i++)
	    {
	      if (multithread.terminate) return;

	      {
		MeshOptimize2dSurfaces meshopt(geom);
		meshopt.SetFaceIndex (k);
		meshopt.SetImproveEdges (0);
		meshopt.SetMetricWeight (0.2);
		meshopt.SetWriteStatus (0);

		meshopt.EdgeSwapping (mesh, (i > mparam.optsteps2d/2));
	      }

	      if (multithread.terminate) return;
	      {
		//		mesh.CalcSurfacesOfNode();
		
		MeshOptimize2dSurfaces meshopt(geom);
		meshopt.SetFaceIndex (k);
		meshopt.SetImproveEdges (0);
		meshopt.SetMetricWeight (0.2);
		meshopt.SetWriteStatus (0);

		meshopt.ImproveMesh (mesh);
	      }

	      {
		MeshOptimize2dSurfaces meshopt(geom);
		meshopt.SetFaceIndex (k);
		meshopt.SetImproveEdges (0);
		meshopt.SetMetricWeight (0.2);
		meshopt.SetWriteStatus (0);

		meshopt.CombineImprove (mesh);
		//		mesh.CalcSurfacesOfNode();
	      }

	      if (multithread.terminate) return;
	      {
		MeshOptimize2dSurfaces meshopt(geom);
		meshopt.SetFaceIndex (k);
		meshopt.SetImproveEdges (0);
		meshopt.SetMetricWeight (0.2);
		meshopt.SetWriteStatus (0);

		meshopt.ImproveMesh (mesh);
	      }
	    }
	}



      PrintMessage (3, (mesh.GetNSE() - oldnf), " elements, ", mesh.GetNP(), " points");

#ifdef OPENGL
      extern void Render();
      Render();
#endif
    }

  mesh.Compress();







  do
    {
      changed = 0;
      for (k = 1; k <= mesh.GetNFD(); k++)
	{
	  multithread.percent = 100 * k / (mesh.GetNFD()+1e-10);
	  
	  if (masterface.Get(k) == k)
	    continue;

	  FaceDescriptor & fd = mesh.GetFaceDescriptor(k);

	  (*testout) << "Surface " << k << endl;
	  (*testout) << "Face Descriptor: " << fd << endl;
	  PrintMessage (2, "Surface ", k);

	  int oldnf = mesh.GetNSE();
      
	  const Surface * surf =
	    geom.GetSurface((mesh.GetFaceDescriptor(k).SurfNr()));

	  /*
	  if (surf -> GetBCProperty() != -1)
	    fd.SetBCProperty (surf->GetBCProperty());
	  else
	    {
	      bccnt++;
	      fd.SetBCProperty (bccnt);
	    }
	  */
  
	  segments.SetSize (0);
	  for (i = 1; i <= mesh.GetNSeg(); i++)
	    {
	      Segment * seg = &mesh.LineSegment(i);
	      if (seg->si == k)
		segments.Append (*seg);
	    }

	  for (i = 1; i <= geom.identifications.Size(); i++)
	    {
	      geom.identifications.Elem(i)->GetIdentifiedFaces (fpairs);
	      int found = 0;
	      for (j = 1; j <= fpairs.Size(); j++)
		if (fpairs.Get(j).I1() == k || fpairs.Get(j).I2() == k)
		  found = 1;

	      if (!found)
		continue;

	      geom.identifications.Get(i)->
		BuildSurfaceElements(segments, mesh, surf);
	      if (!segments.Size())
		break;
	    }

	  
	  if (multithread.terminate) return;

	  for (i = oldnf+1; i <= mesh.GetNSE(); i++)
	    mesh.SurfaceElement(i).SetIndex (k);


	  if (!segments.Size())
	    {
	      masterface.Elem(k) = k;
	      changed = 1; 
	    }

	  PrintMessage (3, (mesh.GetNSE() - oldnf), " elements, ", mesh.GetNP(), " points");
	}
      
#ifdef OPENGL
      extern void Render();
      Render();
#endif
    }
  while (changed);

  mesh.SplitSeparatedFaces();

  mesh.CalcSurfacesOfNode();

  multithread.task = savetask;
}


int GenerateMesh (CSGeometry & geom,
		  Mesh *& mesh,
		  int perfstepsstart, int perfstepsend,
		  const char * optstr)
{
  extern char geomfilename[];
  const char * filename = geomfilename;

  int i;
  char filenametrunc[255];
  char filenameext[255];

  if (mesh && mesh->GetNSE() &&
      !geom.GetNSolids())
    {
      if (perfstepsstart < MESHCONST_MESHVOLUME)
	perfstepsstart = MESHCONST_MESHVOLUME;
    }


  
  strcpy (filenametrunc, filename);
  char * pos = strstr (filenametrunc, ".geo");
  if (pos) strcpy (pos, "");

  if (perfstepsstart <= MESHCONST_ANALYSE)
    {
      delete mesh;
      mesh = new Mesh();

      mesh->SetGlobalH (mparam.maxh);

      ARRAY<double> maxhdom(geom.GetNTopLevelObjects());
      for (i = 0; i < maxhdom.Size(); i++)
	maxhdom[i] = geom.GetTopLevelObject(i)->GetMaxH();

      mesh->SetMaxHDomain (maxhdom);

      if (mparam.uselocalh)
	{
	  //	  double maxsize = globflags.GetNumFlag ("maxsize", 500);
	  double maxsize = geom.MaxSize(); 
	  mesh->SetLocalH (Point<3>(-maxsize, -maxsize, -maxsize),
			   Point<3>(maxsize, maxsize, maxsize),
			   mparam.grading);

	  if (mparam.meshsizefilename)
	    {
	      ifstream msf(mparam.meshsizefilename);
	      if (msf)
		mesh->LoadLocalMeshSize (msf);
	    }
	}

      spoints.SetSize(0);
      FindPoints (geom, *mesh, filename);
      
      PrintMessage (5, "find points done");

#ifdef LOG_STREAM
      (*logout) << "Special points found" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl << endl;
#endif
    }


  if (multithread.terminate || perfstepsend <= MESHCONST_ANALYSE) 
    return TCL_OK;

  if (perfstepsstart <= MESHCONST_MESHEDGES)
    {
      FindEdges (geom, *mesh, filename);
      if (multithread.terminate) return TCL_OK;
#ifdef LOG_STREAM      
      (*logout) << "Edges meshed" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl;
#endif
      
      
      if (multithread.terminate)
	return TCL_OK;
  

      if (mparam.uselocalh)
	{
	  mesh->CalcLocalH();
	  mesh->DeleteMesh();
	  
	  FindPoints (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;
	  FindEdges (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;

	  mesh->DeleteMesh();
	  
	  FindPoints (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;
	  FindEdges (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;
	}
    }
  
  if (multithread.terminate || perfstepsend <= MESHCONST_MESHEDGES)
    return TCL_OK;


  if (perfstepsstart <= MESHCONST_MESHSURFACE)
    {
      MeshSurface (geom, *mesh);  
      if (multithread.terminate) return TCL_OK;
      
#ifdef LOG_STREAM
      (*logout) << "Surfaces meshed" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl;
#endif      
      
      if (mparam.uselocalh && 0)
	{
	  mesh->CalcLocalH();      
	  mesh->DeleteMesh();

	  FindPoints (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;
	  FindEdges (geom, *mesh, filename);
	  if (multithread.terminate) return TCL_OK;

	  MeshSurface (geom, *mesh);  
	  if (multithread.terminate) return TCL_OK;
	}

#ifdef LOG_STREAM      
      (*logout) << "Surfaces remeshed" << endl
		<< "time = " << GetTime() << " sec" << endl
		<< "points: " << mesh->GetNP() << endl;
#endif      
      
#ifdef STAT_STREAM
      (*statout) << mesh->GetNSeg() << " & "
		 << mesh->GetNSE() << " & - &" 
		 << GetTime() << " & " << endl;
#endif  

      MeshQuality2d (*mesh);
      mesh->CalcSurfacesOfNode();

      /*
	strcpy (filenameext, filenametrunc);
	strcat (filenameext, ".surf.mesh");
	WriteFile (WRITE_SURFACE, mesh, geom, filenameext, filename, h);
      */
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
      
      for (int i = 0; i < geom.GetNTopLevelObjects(); i++)
	mesh->SetMaterial (i+1, geom.GetTopLevelObject(i)->GetMaterial().c_str());
      

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
      
      OptimizeVolume (mparam, *mesh, &geom);
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

      
#ifndef TRAFO
      /*
      if (&geom)
	{
	  ZRefinementOptions opt;
	  opt.minref = 0;
	  ZRefinement (*mesh, &geom, opt);
	}
      */
#endif
    }

  /*
  cout << (char)7 << (char)7 << endl;
  cout << "Meshing finished" << endl << endl;
  cout << setw (4) << mesh->GetNP() << " Points" << endl;
  cout << setw (4) << mesh->GetNSE() << " Surface Elements" << endl;
  cout << setw (4) << mesh->GetNE() << " Volume Elements" << endl;
  cout << setw (4) << int (GetTime()) << " Seconds" << endl;
  */

  /*
    strcpy (filenameext, filenametrunc);
    strcat (filenameext, ".vol");
    mesh->Save (filenameext);	
  */

  return TCL_OK;
}
}

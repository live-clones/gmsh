#include <mystdlib.h>


#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>
#include <meshing.hpp>


namespace netgen
{
  ARRAY<SpecialPoint> specpoints;
  static ARRAY<MeshPoint> spoints;

#define TCL_OK 0
#define TCL_ERROR 1



  static void FindPoints (CSGeometry & geom, Mesh & mesh)
  {
    PrintMessage (1, "Start Findpoints");

    char * savetask = multithread.task;
    multithread.task = "Find points";

    for (int i = 0; i < geom.GetNUserPoints(); i++)
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
    for (int i = 0; i < specpoints.Size(); i++)
      specpoints[i].Print (*testout);

    /*
      for (int i = 1; i <= geom.identifications.Size(); i++)
      geom.identifications.Elem(i)->IdentifySpecialPoints (specpoints);
    */
    multithread.task = savetask;
  }






  static void FindEdges (CSGeometry & geom, Mesh & mesh)
  {
    EdgeCalculation ec (geom, specpoints);
    ec.Calc (mparam.maxh, mesh);

    for (int i = 0; i < geom.singedges.Size(); i++)
      geom.singedges[i]->FindPointsOnEdge (mesh);
    for (int i = 0; i < geom.singpoints.Size(); i++)
      geom.singpoints[i]->FindPoints (mesh);

    for (int i = 1; i <= mesh.GetNSeg(); i++)
      {
	int ok = 0;
	for (int k = 1; k <= mesh.GetNFD(); k++)
	  if (mesh.GetFaceDescriptor(k).SegmentFits (mesh.LineSegment(i)))
	    ok = k;

	if (!ok)
	  ok = mesh.AddFaceDescriptor (FaceDescriptor (mesh.LineSegment(i)));

	mesh.LineSegment(i).si = ok;
      }

    for (int i = 0; i < geom.identifications.Size(); i++)
      geom.identifications[i]->IdentifyPoints (mesh);
    for (int i = 0; i < geom.identifications.Size(); i++)
      geom.identifications[i]->IdentifyFaces (mesh);



    // find intersecting segments
    PrintMessage (3, "Check intersecting edges");

    if (!ec.point_on_edge_problem)
      for (SegmentIndex si = 0; si < mesh.GetNSeg(); si++)
	for (SegmentIndex sj = 0; sj < si; sj++)
	  {
	    if (!mesh[si].seginfo || !mesh[sj].seginfo) continue;
	    if (mesh[mesh[si].p1].GetLayer() != mesh[mesh[sj].p2].GetLayer()) continue;
	    
	    Point<3> pi1 = mesh[mesh[si].p1];
	    Point<3> pi2 = mesh[mesh[si].p2];
	    Point<3> pj1 = mesh[mesh[sj].p1];
	    Point<3> pj2 = mesh[mesh[sj].p2];
	    Vec<3> vi = pi2 - pi1;
	    Vec<3> vj = pj2 - pj1;
	    
	    if (sqr (vi * vj) > (1-1e-6) * Abs2 (vi) * Abs2 (vj)) continue;

	    // pi1 + vi t = pj1 + vj s
	    Mat<3,2> mat;
	    Vec<3> rhs;
	    Vec<2> sol;
	    
	    for (int j = 0; j < 3; j++)
	      { 
		mat(j,0) = vi(j); 
		mat(j,1) = -vj(j); 
		rhs(j) = pj1(j)-pi1(j); 
	    }
	    
	    mat.Solve (rhs, sol);

	    if (sol(0) > 1e-6 && sol(0) < 1-1e-6 &&
		sol(1) > 1e-6 && sol(1) < 1-1e-6 &&
		Abs (rhs - mat*sol) < 1e-6)
	      {
		Point<3> ip = pi1 + sol(0) * vi;
		cout << "Intersection at " << ip << endl;
		
		geom.AddUserPoint (ip);
		spoints.Append (MeshPoint (ip, mesh[mesh[si].p1].GetLayer()));
		mesh.AddPoint (ip);
	      }
	  }
  }  






  static void MeshSurface (CSGeometry & geom, Mesh & mesh)
  {
    char * savetask = multithread.task;
    multithread.task = "Surface meshing";
  
    ARRAY<Segment> segments;
    int noldp = mesh.GetNP();

    double starttime = GetTime();

    // find master faces from identified
    ARRAY<int> masterface(mesh.GetNFD());
    for (int i = 1; i <= mesh.GetNFD(); i++)
      masterface.Elem(i) = i;
  
    ARRAY<INDEX_2> fpairs;
    bool changed;
    do
      {
	changed = 0;
	for (int i = 0; i < geom.identifications.Size(); i++)
	  {
	    geom.identifications[i]->GetIdentifiedFaces (fpairs);

	    for (int j = 0; j < fpairs.Size(); j++)
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
    for (int k = 0; k < geom.GetNSurf(); k++)
      bccnt = max2 (bccnt, geom.GetSurface(k)->GetBCProperty());

    for (int k = 1; k <= mesh.GetNFD(); k++)
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
		fd.SetBCProperty (geom.bcmodifications[l].bcnr);
	      }
	  }
      }


    for (int j = 0; j < geom.singfaces.Size(); j++)
      {
	ARRAY<int> surfs;
	geom.GetIndependentSurfaceIndices (geom.singfaces[j]->GetSolid(),
					   geom.BoundingBox(), surfs);
	for (int k = 1; k <= mesh.GetNFD(); k++)
	  {
	    FaceDescriptor & fd = mesh.GetFaceDescriptor(k);
	    for (int l = 0; l < surfs.Size(); l++)
	      if (surfs[l] == fd.SurfNr())
		{
		  if (geom.singfaces[j]->GetDomainNr() == fd.DomainIn())
		    fd.domin_singular = 1;
		  if (geom.singfaces[j]->GetDomainNr() == fd.DomainOut())
		    fd.domout_singular = 1;
		}
	  }
      }
    

    // assemble edge hash-table
    mesh.CalcSurfacesOfNode();

    for (int k = 1; k <= mesh.GetNFD(); k++)
      {
	multithread.percent = 100.0 * k / (mesh.GetNFD()+1e-10);

	if (masterface.Get(k) != k)
	  continue;

	FaceDescriptor & fd = mesh.GetFaceDescriptor(k);

	(*testout) << "Surface " << k << endl;
	(*testout) << "Face Descriptor: " << fd << endl;
	PrintMessage (1, "Surface ", k, " / ", mesh.GetNFD());

	int oldnf = mesh.GetNSE();
      
	const Surface * surf =
	  geom.GetSurface((mesh.GetFaceDescriptor(k).SurfNr()));


	Meshing2Surfaces meshing(*surf, geom.BoundingBox());
	meshing.SetStartTime (starttime);

	for (PointIndex pi = PointIndex::BASE; pi < noldp+PointIndex::BASE; pi++)
	  meshing.AddPoint (mesh[pi], pi);
  
	segments.SetSize (0);

	for (SegmentIndex si = 0; si < mesh.GetNSeg(); si++)
	  if (mesh[si].si == k)
	    segments.Append (mesh[si]);

	for (int i = 1; i <= geom.identifications.Size(); i++)
	  geom.identifications.Get(i)->
	    BuildSurfaceElements(segments, mesh, surf);

	for (int si = 0; si < segments.Size(); si++)
	  {
	    PointGeomInfo gi;
	    gi.trignum = k;
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

	mparam.checkoverlap = 0;

	MESHING2_RESULT res =
	  meshing.GenerateMesh (mesh, maxh, k);

	if (res != MESHING2_OK)
	  {
	    PrintError ("Problem in Surface mesh generation");
	    throw NgException ("Problem in Surface mesh generation");
	  }

	if (multithread.terminate) return;
      
	for (int i = oldnf+1; i <= mesh.GetNSE(); i++)
	  mesh.SurfaceElement(i).SetIndex (k);


	//      mesh.CalcSurfacesOfNode();
	if (segments.Size())   
	  { 
	    // surface was meshed, not copied
	    PrintMessage (2, "Optimize Surface");
	    for (int i = 1; i <= mparam.optsteps2d; i++)
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
	for (int k = 1; k <= mesh.GetNFD(); k++)
	  {
	    multithread.percent = 100.0 * k / (mesh.GetNFD()+1e-10);
	  
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
	    for (int i = 1; i <= mesh.GetNSeg(); i++)
	      {
		Segment * seg = &mesh.LineSegment(i);
		if (seg->si == k)
		  segments.Append (*seg);
	      }

	    for (int i = 1; i <= geom.identifications.Size(); i++)
	      {
		geom.identifications.Elem(i)->GetIdentifiedFaces (fpairs);
		int found = 0;
		for (int j = 1; j <= fpairs.Size(); j++)
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

	    for (int i = oldnf+1; i <= mesh.GetNSE(); i++)
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

    if (mesh && mesh->GetNSE() &&
	!geom.GetNSolids())
      {
	if (perfstepsstart < MESHCONST_MESHVOLUME)
	  perfstepsstart = MESHCONST_MESHVOLUME;
      }



    if (perfstepsstart <= MESHCONST_ANALYSE)
      {
	delete mesh;
	mesh = new Mesh();

	mesh->SetGlobalH (mparam.maxh);

	ARRAY<double> maxhdom(geom.GetNTopLevelObjects());
	for (int i = 0; i < maxhdom.Size(); i++)
	  maxhdom[i] = geom.GetTopLevelObject(i)->GetMaxH();

	mesh->SetMaxHDomain (maxhdom);

	if (mparam.uselocalh)
	  {
	    double maxsize = geom.MaxSize(); 
	    mesh->SetLocalH (Point<3>(-maxsize, -maxsize, -maxsize),
			     Point<3>(maxsize, maxsize, maxsize),
			     mparam.grading);

	    mesh -> LoadLocalMeshSize (mparam.meshsizefilename);
	  }

	spoints.SetSize(0);
	FindPoints (geom, *mesh);
      
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
	FindEdges (geom, *mesh);
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
	  
	    FindPoints (geom, *mesh);
	    if (multithread.terminate) return TCL_OK;
	    FindEdges (geom, *mesh);
	    if (multithread.terminate) return TCL_OK;

	    mesh->DeleteMesh();
	  
	    FindPoints (geom, *mesh);
	    if (multithread.terminate) return TCL_OK;
	    FindEdges (geom, *mesh);
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

	    FindPoints (geom, *mesh);
	    if (multithread.terminate) return TCL_OK;
	    FindEdges (geom, *mesh);
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
      }

    return TCL_OK;
  }
}

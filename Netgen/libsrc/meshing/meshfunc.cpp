#include <mystdlib.h>
#include "meshing.hpp"

namespace netgen
{
  extern const char * tetrules2[];
  extern const char * prismrules2[];
  extern const char * pyramidrules[];
  extern const char * pyramidrules2[];


  extern double teterrpow; 
  MESHING3_RESULT MeshVolume (MeshingParameters & mp, Mesh& mesh3d)
  {
    int i, k, oldne;
    PointIndex pi;

    int meshed;
    int cntsteps; 


    //  PlotStatistics3d * pstat;
    //  pstat = new TerminalPlotStatistics3d;


    ARRAY<INDEX_2> connectednodes;

    mesh3d.Compress();

    //  mesh3d.PrintMemInfo (cout);

    int nonconsist = 0;
    for (k = 1; k <= mesh3d.GetNDomains(); k++)
      {
	PrintMessage (3, "Check subdomain ", k, " / ", mesh3d.GetNDomains());

	mesh3d.FindOpenElements(k);

	int res = 0; // mesh3d.CheckOverlappingBoundary();
	if (res)
	  {
	    PrintError ("Surface is overlapping !!");
	    nonconsist = 1;
	  }

	res = mesh3d.CheckConsistentBoundary();
	if (res)
	  {
	    PrintError ("Surface mesh not consistent");
	    nonconsist = 1;
	  }
      }

    if (nonconsist)
      {
	PrintError ("Stop meshing since surface mesh not consistent");
	throw NgException ("Stop meshing since surface mesh not consistent");
      }

    double globmaxh = mp.maxh;

    for (k = 1; k <= mesh3d.GetNDomains(); k++)
      {
	if (multithread.terminate)
	  break;

	PrintMessage (2, "");
	PrintMessage (1, "Meshing subdomain ", k, " of ", mesh3d.GetNDomains());
 
	mp.maxh = min2 (globmaxh, mesh3d.MaxHDomain(k));

	mesh3d.CalcSurfacesOfNode();
	mesh3d.FindOpenElements(k);

	/*
	  if (mesh3d.CheckOverlappingBoundary())
	  {
	  (*mycout) << "overlapping" << endl;
	  (*testout) << "overlapping !!!" << endl;
	  continue;
	  }
	  if (mesh3d.CheckConsistentBoundary())
	  {
	  (*mycout) << "boundary not consistent" << endl;
	  (*testout) << "boundary not consistent !!!" << endl;
	  continue;
	  }
	*/

	if (!mesh3d.GetNOpenElements())
	  continue;

	int qstep;
	for (qstep = 1; qstep <= 3; qstep++)
	  {
	    if (mesh3d.HasOpenQuads())
	      {
		string rulefile = ngdir;
		/*
		  char rulefile[255];
		  strcpy (rulefile, ngdir);
		*/
		const char ** rulep = NULL;
		switch (qstep)
		  {
		  case 1:
		    //		  strcat (rulefile, "/rules/prisms2.rls");
		    rulefile += "/rules/prisms2.rls";
		    rulep = prismrules2;
		    break;
		  case 2: // connect pyramid to triangle
		    //		  strcat (rulefile, "/rules/pyramids2.rls");
		    rulefile += "/rules/pyramids2.rls";
		    rulep = pyramidrules2;
		    break;
		  case 3: // connect to vis-a-vis point
		    //		  strcat (rulefile, "/rules/pyramids.rls");
		    rulefile += "/rules/pyramids.rls";
		    rulep = pyramidrules;
		    break;
		  }
	      
		//	      Meshing3 meshing(rulefile.c_str(), pstat);
		Meshing3 meshing(NULL, rulep); 
	      
		MeshingParameters mpquad = mp;
	      
		mpquad.giveuptol = 15;
		mpquad.baseelnp = 4;
		mpquad.starshapeclass = 100;
	      
		for (pi = PointIndex::BASE; 
		     pi < mesh3d.GetNP()+PointIndex::BASE; pi++)
		  meshing.AddPoint (mesh3d[pi], pi);

		mesh3d.GetIdentifications().GetPairs (0, connectednodes);
		for (i = 1; i <= connectednodes.Size(); i++)
		  meshing.AddConnectedPair (connectednodes.Get(i));
	      
		for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
		  {
		    Element2d hel = mesh3d.OpenElement(i);
		    meshing.AddBoundaryElement (hel);
		  }
	      
		oldne = mesh3d.GetNE();
	      
		meshing.GenerateMesh (mesh3d, mpquad);
	      
		for (i = oldne + 1; i <= mesh3d.GetNE(); i++)
		  mesh3d.VolumeElement(i).SetIndex (k);
	      
		(*testout) 
		  << "mesh has " << mesh3d.GetNE() << " prism ? elements" << endl;
	      
		mesh3d.FindOpenElements(k);
	      }
	  }


	if (mesh3d.HasOpenQuads())
	  {
	    PrintSysError ("mesh has still open quads");
	    throw NgException ("Stop meshing since too many attempts");
	    // return MESHING3_GIVEUP;
	  }


	if (mp.delaunay && mesh3d.GetNOpenElements())
	  {
	    Meshing3 meshing(NULL);
	 
	    mesh3d.FindOpenElements(k);
	  

	    for (pi = PointIndex::BASE; 
		 pi < mesh3d.GetNP()+PointIndex::BASE; pi++)
	      meshing.AddPoint (mesh3d[pi], pi);
	  

	    for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
	      meshing.AddBoundaryElement (mesh3d.OpenElement(i));
	  
	    oldne = mesh3d.GetNE();
	    /*
	      if (globflags.GetDefineFlag ("blockfill"))
	      {
	      if (!globflags.GetDefineFlag ("localh"))
	      meshing.BlockFill 
	      (mesh3d, mp.h * globflags.GetNumFlag ("relblockfillh", 1));
	      else
	      meshing.BlockFillLocalH (mesh3d);
	      }
	    */

	  
	    //	  mp.blockfill = globflags.GetDefineFlag ("blockfill");
	    meshing.Delaunay (mesh3d, mp);
	    //	  return MESHING3_OK;

	    for (i = oldne + 1; i <= mesh3d.GetNE(); i++)
	      mesh3d.VolumeElement(i).SetIndex (k);

	    PrintMessage (3, mesh3d.GetNP(), " points, ",
			  mesh3d.GetNE(), " elements");
	  }


	cntsteps = 0;
	do
	  {
	    if (multithread.terminate)
	      break;

	    //	  mesh3d.CalcSurfacesOfNode();
	    mesh3d.FindOpenElements(k);
	    PrintMessage (5, mesh3d.GetNOpenElements(), " open faces");
	    cntsteps++;
	    if (cntsteps > mp.maxoutersteps) 
	      throw NgException ("Stop meshing since too many attempts");
	    // return MESHING3_OUTERSTEPSEXCEEDED;

	    /*
	      if (mesh3d.CheckOverlappingBoundary())
	      {
	      (*mycout) << "overlapping" << endl;
	      (*testout) << "overlapping !!!!" << endl;
	      break;
	      }
	      if (mesh3d.CheckConsistentBoundary())
	      {
	      (*mycout) << "boundary not consistent" << endl;
	      (*testout) << "boundary not consistent !!!" << endl;
	      //	      break;
	      }
	    */


	    /*
	      char rulefile[255];
	      strcpy (rulefile, ngdir);
	      strcat (rulefile, "/tetra.rls");
	    */
	    string rulefile = ngdir + "/tetra.rls";
	    PrintMessage (1, "start tetmeshing");

	    //	  Meshing3 meshing(rulefile, pstat);
	    Meshing3 meshing(NULL);
      
#ifdef MYGRAPH	  
	    Point3d pmin, pmax;
	    mesh3d.GetBox (pmin, pmax, k);
	    rot.SetCenter (Center (pmin, pmax));
#endif

	    for (i = 1; i <= mesh3d.GetNP(); i++)
	      meshing.AddPoint (mesh3d.Point(i), i);

	    for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
	      meshing.AddBoundaryElement (mesh3d.OpenElement(i));


	    oldne = mesh3d.GetNE();

	    mp.giveuptol = 15; // int(globflags.GetNumFlag ("giveuptol", 15));
	    mp.sloppy = 5;
	    meshing.GenerateMesh (mesh3d, mp);

	    for (i = oldne + 1; i <= mesh3d.GetNE(); i++)
	      mesh3d.VolumeElement(i).SetIndex (k);
	  
	  
	    mesh3d.CalcSurfacesOfNode();
	    mesh3d.FindOpenElements(k);
	  
	    teterrpow = 2;
	    if (mesh3d.GetNOpenElements() != 0)
	      {
		meshed = 0;
		PrintMessage (5, mesh3d.GetNOpenElements(), " open faces found");

		//	      mesh3d.Save ("tmp.vol");


		MeshOptimize3d optmesh;

		const char * optstr = "mcmstmcmstmcmstmcm";
		int j;
		for (j = 1; j <= strlen(optstr); j++)
		  {
		    mesh3d.CalcSurfacesOfNode();
		    mesh3d.FreeOpenElementsEnvironment(2);

		    switch (optstr[j-1])
		      {
		      case 'c': optmesh.CombineImprove(mesh3d, OPT_REST); break;
		      case 'd': optmesh.SplitImprove(mesh3d, OPT_REST); break;
		      case 's': optmesh.SwapImprove(mesh3d, OPT_REST); break;
		      case 't': optmesh.SwapImprove2(mesh3d, OPT_REST); break;
		      case 'm': mesh3d.ImproveMesh(OPT_REST); break;
		      }	  

		  }

		mesh3d.FindOpenElements(k);	      
		PrintMessage (3, "Call remove problem");
		RemoveProblem (mesh3d);
		mesh3d.FindOpenElements(k);
	      }
	    else
	      {
		meshed = 1;
		PrintMessage (1, "Success !");
	      }
	  }
	while (!meshed);

	PrintMessage (1, mesh3d.GetNP(), " points, ",
		      mesh3d.GetNE(), " elements");
      }

    mp.maxh = globmaxh;

    MeshQuality3d (mesh3d);

    //  delete pstat;

    return MESHING3_OK;
  }  




  /*


  MESHING3_RESULT MeshVolumeOld (MeshingParameters & mp, Mesh& mesh3d)
  {
  int i, k, oldne;


  int meshed;
  int cntsteps; 


  PlotStatistics3d * pstat;
  if (globflags.GetNumFlag("silentflag", 1) <= 2)
  pstat = new XPlotStatistics3d;
  else
  pstat = new TerminalPlotStatistics3d;

  cntsteps = 0;
  do
  {
  cntsteps++;
  if (cntsteps > mp.maxoutersteps) 
  {
  return MESHING3_OUTERSTEPSEXCEEDED;
  }


  int noldp = mesh3d.GetNP();
      
      
  if ( (cntsteps == 1) && globflags.GetDefineFlag ("delaunay"))
  {
  cntsteps ++;

  mesh3d.CalcSurfacesOfNode();


  for (k = 1; k <= mesh3d.GetNDomains(); k++)
  {
  Meshing3 meshing(NULL, pstat);

  mesh3d.FindOpenElements(k);
	      
  for (i = 1; i <= noldp; i++)
  meshing.AddPoint (mesh3d.Point(i), i);
	      
  for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
  {
  if (mesh3d.OpenElement(i).GetIndex() == k)
  meshing.AddBoundaryElement (mesh3d.OpenElement(i));
  }
	      
  oldne = mesh3d.GetNE();
  if (globflags.GetDefineFlag ("blockfill"))
  {
  if (!globflags.GetDefineFlag ("localh"))
  meshing.BlockFill 
  (mesh3d, mp.h * globflags.GetNumFlag ("relblockfillh", 1));
  else
  meshing.BlockFillLocalH (mesh3d);
  }
	      
  MeshingParameters mpd;
  meshing.Delaunay (mesh3d, mpd);

  for (i = oldne + 1; i <= mesh3d.GetNE(); i++)
  mesh3d.VolumeElement(i).SetIndex (k);
  }
  }

  noldp = mesh3d.GetNP();

  mesh3d.CalcSurfacesOfNode();
  mesh3d.FindOpenElements();
  for (k = 1; k <= mesh3d.GetNDomains(); k++)
  {
  Meshing3 meshing(globflags.GetStringFlag ("rules3d", NULL), pstat);
      
  Point3d pmin, pmax;
  mesh3d.GetBox (pmin, pmax, k);
	  
  rot.SetCenter (Center (pmin, pmax));

  for (i = 1; i <= noldp; i++)
  meshing.AddPoint (mesh3d.Point(i), i);

  for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
  {
  if (mesh3d.OpenElement(i).GetIndex() == k)
  meshing.AddBoundaryElement (mesh3d.OpenElement(i));
  }

  oldne = mesh3d.GetNE();


  if ( (cntsteps == 1) && globflags.GetDefineFlag ("blockfill"))
  {
  if (!globflags.GetDefineFlag ("localh"))
  {
  meshing.BlockFill 
  (mesh3d, 
  mp.h * globflags.GetNumFlag ("relblockfillh", 1));
  }
  else
  {
  meshing.BlockFillLocalH (mesh3d);
  }
  }


  mp.giveuptol = int(globflags.GetNumFlag ("giveuptol", 15));

  meshing.GenerateMesh (mesh3d, mp);

  for (i = oldne + 1; i <= mesh3d.GetNE(); i++)
  mesh3d.VolumeElement(i).SetIndex (k);
  }



  mesh3d.CalcSurfacesOfNode();
  mesh3d.FindOpenElements();
      
  teterrpow = 2;
  if (mesh3d.GetNOpenElements() != 0)
  {
  meshed = 0;
  (*mycout) << "Open elements found, old" << endl;
  const char * optstr = "mcmcmcmcm";
  int j;
  for (j = 1; j <= strlen(optstr); j++)
  switch (optstr[j-1])
  {
  case 'c': mesh3d.CombineImprove(); break;
  case 'd': mesh3d.SplitImprove(); break;
  case 's': mesh3d.SwapImprove(); break;
  case 'm': mesh3d.ImproveMesh(2); break;
  }	  
	  
  (*mycout) << "Call remove" << endl;
  RemoveProblem (mesh3d);
  (*mycout) << "Problem removed" << endl;
  }
  else
  meshed = 1;
  }
  while (!meshed);

  MeshQuality3d (mesh3d);

  return MESHING3_OK;
  }  

  */


  MESHING3_RESULT MeshMixedVolume(MeshingParameters & mp, Mesh& mesh3d)
  {
    int i, j;
    MESHING3_RESULT res;
    Point3d pmin, pmax;

    mp.giveuptol = 10;
    mp.baseelnp = 4;
    mp.starshapeclass = 100;

    //  TerminalPlotStatistics3d pstat;
  
    Meshing3 meshing1("pyramids.rls");
    for (i = 1; i <= mesh3d.GetNP(); i++)
      meshing1.AddPoint (mesh3d.Point(i), i);

    mesh3d.FindOpenElements();
    for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
      if (mesh3d.OpenElement(i).GetIndex() == 1)
	meshing1.AddBoundaryElement (mesh3d.OpenElement(i));

    res = meshing1.GenerateMesh (mesh3d, mp);

    mesh3d.GetBox (pmin, pmax);
    PrintMessage (1, "Mesh pyramids, res = ", res);
    if (res)
      exit (1);


    for (i = 1; i <= mesh3d.GetNE(); i++)
      mesh3d.VolumeElement(i).SetIndex (1);

    // do delaunay
  
    mp.baseelnp = 0;
    mp.starshapeclass = 5;

    Meshing3 meshing2(NULL);
    for (i = 1; i <= mesh3d.GetNP(); i++)
      meshing2.AddPoint (mesh3d.Point(i), i);
    
    mesh3d.FindOpenElements();
    for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
      if (mesh3d.OpenElement(i).GetIndex() == 1)
	meshing2.AddBoundaryElement (mesh3d.OpenElement(i));

    MeshingParameters mpd;
    meshing2.Delaunay (mesh3d, mpd);

    for (i = 1; i <= mesh3d.GetNE(); i++)
      mesh3d.VolumeElement(i).SetIndex (1);


    mp.baseelnp = 0;
    mp.giveuptol = 10;

    for (int trials = 1; trials <= 50; trials++)
      {
	if (multithread.terminate)
	  return MESHING3_TERMINATE;

	Meshing3 meshing3("tetra.rls");
	for (i = 1; i <= mesh3d.GetNP(); i++)
	  meshing3.AddPoint (mesh3d.Point(i), i);
      
	mesh3d.FindOpenElements();
	for (i = 1; i <= mesh3d.GetNOpenElements(); i++)
	  if (mesh3d.OpenElement(i).GetIndex() == 1)
	    meshing3.AddBoundaryElement (mesh3d.OpenElement(i));
      
	if (trials > 1)
	  CheckSurfaceMesh2 (mesh3d);
	res = meshing3.GenerateMesh (mesh3d, mp);
      
	for (i = 1; i <= mesh3d.GetNE(); i++)
	  mesh3d.VolumeElement(i).SetIndex (1);

	if (res == 0) break;



	for (i = 1; i <= mesh3d.GetNE(); i++)
	  {
	    const Element & el = mesh3d.VolumeElement(i);
	    if (el.GetNP() != 4)
	      {
		for (j = 1; j <= el.GetNP(); j++)
		  mesh3d.AddLockedPoint (el.PNum(j));
	      }
	  }

	mesh3d.CalcSurfacesOfNode();
	mesh3d.FindOpenElements();

	MeshOptimize3d optmesh;

	teterrpow = 2;
	const char * optstr = "mcmcmcmcm";
	for (j = 1; j <= strlen(optstr); j++)
	  switch (optstr[j-1])
	    {
	    case 'c': optmesh.CombineImprove(mesh3d, OPT_REST); break;
	    case 'd': optmesh.SplitImprove(mesh3d); break;
	    case 's': optmesh.SwapImprove(mesh3d); break;
	    case 'm': mesh3d.ImproveMesh(); break;
	    }	  
	        
	RemoveProblem (mesh3d);
      }


    PrintMessage (1, "Meshing tets, res = ", res);
    if (res)
      {
	mesh3d.FindOpenElements();
	PrintSysError (1, "Open elemetns: ", mesh3d.GetNOpenElements());
	exit (1);
      }


  
    for (i = 1; i <= mesh3d.GetNE(); i++)
      {
	const Element & el = mesh3d.VolumeElement(i);
	if (el.GetNP() != 4)
	  {
	    for (j = 1; j <= el.GetNP(); j++)
	      mesh3d.AddLockedPoint (el.PNum(j));
	  }
      }
  
    mesh3d.CalcSurfacesOfNode();
    mesh3d.FindOpenElements();
  
    MeshOptimize3d optmesh;

    teterrpow = 2;
    const char * optstr = "mcmcmcmcm";
    for (j = 1; j <= strlen(optstr); j++)
      switch (optstr[j-1])
	{
	case 'c': optmesh.CombineImprove(mesh3d, OPT_REST); break;
	case 'd': optmesh.SplitImprove(mesh3d); break;
	case 's': optmesh.SwapImprove(mesh3d); break;
	case 'm': mesh3d.ImproveMesh(); break;
	}	  


    return MESHING3_OK;
  }







  MESHING3_RESULT OptimizeVolume (MeshingParameters & mp, 
				  Mesh & mesh3d,
				  const CSGeometry * geometry)
  {
    int i, j;

    PrintMessage (1, "Volume Optimization");

    /*
      if (!mesh3d.PureTetMesh())
      return MESHING3_OK;
    */

    // (*mycout) << "optstring = " << mp.optimize3d << endl;
    /*
      const char * optstr = globflags.GetStringFlag ("optimize3d", "cmh");
      int optsteps = int (globflags.GetNumFlag ("optsteps3d", 2));
    */

    mesh3d.CalcSurfacesOfNode();
    for (i = 1; i <= mp.optsteps3d; i++)
      {
	if (multithread.terminate)
	  break;

	MeshOptimize3d optmesh;

	teterrpow = mp.opterrpow;
	for (j = 1; j <= strlen(mp.optimize3d); j++)
	  {
	    if (multithread.terminate)
	      break;

	    switch (mp.optimize3d[j-1])
	      {
	      case 'c': optmesh.CombineImprove(mesh3d, OPT_REST); break;
	      case 'd': optmesh.SplitImprove(mesh3d); break;
	      case 's': optmesh.SwapImprove(mesh3d); break;
	      case 't': optmesh.SwapImprove2(mesh3d); break;
#ifdef SOLIDGEOM
	      case 'm': mesh3d.ImproveMesh(*geometry); break;
	      case 'M': mesh3d.ImproveMesh(*geometry); break;
#else
	      case 'm': mesh3d.ImproveMesh(); break;
	      case 'M': mesh3d.ImproveMesh(); break;
#endif
	      
	      case 'j': mesh3d.ImproveMeshJacobian(); break;
	      }
	  }
	MeshQuality3d (mesh3d);
      }
  
    return MESHING3_OK;
  }




  void RemoveIllegalElements (Mesh & mesh3d)
  {
    int it = 10;
    int nillegal, oldn;
    int i;

    PrintMessage (1, "Remove Illegal Elements");
    // return, if non-pure tet-mesh
    /*
      if (!mesh3d.PureTetMesh())
      return;
    */
    mesh3d.CalcSurfacesOfNode();

    nillegal = mesh3d.MarkIllegalElements();

    MeshOptimize3d optmesh;
    while (nillegal && (it--) > 0)
      {
	if (multithread.terminate)
	  break;

	PrintMessage (5, nillegal, " illegal tets");
	optmesh.SplitImprove (mesh3d, OPT_LEGAL);

	mesh3d.MarkIllegalElements();  // test
	optmesh.SwapImprove (mesh3d, OPT_LEGAL);
	mesh3d.MarkIllegalElements();  // test
	optmesh.SwapImprove2 (mesh3d, OPT_LEGAL);

	oldn = nillegal;
	nillegal = mesh3d.MarkIllegalElements();

	if (oldn != nillegal)
	  it = 10;
      }
    PrintMessage (5, nillegal, " illegal tets");
  }
}

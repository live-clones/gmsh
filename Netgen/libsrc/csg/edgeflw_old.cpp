#include <mystdlib.h>
#include <meshing.hpp>
#include <csg.hpp>

#undef DEVELOP

namespace netgen
{

  EdgeCalculation :: 
  EdgeCalculation (const CSGeometry & ageometry,
		   ARRAY<SpecialPoint> & aspecpoints)
    : geometry(ageometry), specpoints(aspecpoints)
  {
    ;
  }

  EdgeCalculation :: ~EdgeCalculation ()
  { ; }

  void EdgeCalculation :: Calc(double h, Mesh & mesh)
  {
    PrintMessage (1, "Find edges");
    PushStatus ("Find edges");

    CalcEdges1 (h, mesh);
    SplitEqualOneSegEdges (mesh);
    FindClosedSurfaces (h, mesh);
    PrintMessage (3, cntedge, " edges found");

    PopStatus ();
  }




  void EdgeCalculation :: CalcEdges1 (double h, Mesh & mesh)
  {
    ARRAY<SpecialPoint> hsp(specpoints.Size());
    ARRAY<SpecialPoint> startpoints, endpoints;

    int i, j, k, l, hi, pos, ep, ne;
    int layer;

    Vec<3> a1, a2, t, n, m;
    Point<3> p, np, pnp, hp;

    Segment seg;
    int pi1, s1, s2;
    int lastpi, thispi;

    ARRAY<Point<3> > edgepoints;
    ARRAY<double> curvelength;
    int copyedge, copyfromedge, copyedgeidentification;

    ARRAY<int> locsurfind;

    double len, corr, lam;
    double steplen, cursteplen, loch, hd;

    int checkedcopy = 0;

    double size = geometry.MaxSize(); // globflags.GetNumFlag ("maxsize", 500);
    double epspointdist2 = size * 1e-6; // globflags.GetNumFlag ("epspointdist", size * 1e-6);
    epspointdist2 = sqr (epspointdist2);


    Solid * locsol;


    // copy special points to work with
    for (i = 0; i < specpoints.Size(); i++)
      hsp[i] = specpoints[i];


    cntedge = 0;

    while (hsp.Size())
      {
	SetThreadPercent(100 - 100 * double (hsp.Size()) / specpoints.Size());

	edgepoints.SetSize (0);
	curvelength.SetSize (0);
      

	pi1 = 0;
	copyedge = 0;
	// identifyable point available ?

	//      (*testout) << endl;

	for (i = 1; i <= geometry.identifications.Size() && !pi1; i++)
	  {
	    for (j = checkedcopy+1; j <= startpoints.Size() && !pi1; j++)
	      {

		if (geometry.identifications.Get(i)->IdentifyableCandidate (startpoints.Get(j)))
		
		  {
		    int pi1cand = 0;
		    double mindist = 1e10;
		  
		    for (k = 1; k <= hsp.Size() && !pi1; k++)
		      {
#ifdef DEVELOP
			(*testout) << "check kand = " << hsp.Get(k).p 
				   << ", v = " << hsp.Get(k).v 
				   << endl;		      
#endif
			if (geometry.identifications.Get(i)
			    ->Identifyable(startpoints.Get(j), hsp.Get(k)) ||
			    geometry.identifications.Get(i)
			    ->Identifyable(hsp.Get(k), startpoints.Get(j)))
			  {

#ifdef DEVELOP
			    (*testout) << "identifiable, dist = "
				       << Dist (startpoints.Get(j).p, hsp.Get(k).p) << endl;
#endif

			    if (Dist (startpoints.Get(j).p, hsp.Get(k).p) < mindist)
			      {
				mindist = Dist (startpoints.Get(j).p, hsp.Get(k).p);
				pi1cand = k;
			      }
			    /*
			      pi1 = k;
			      copyedge = 1;
			      copyfromedge = j;
			      copyedgeidentification = i;
			  
			      (*testout) << "copy edge startpoint from "
			      << startpoints.Get(j).p << " - " 
			      << startpoints.Get(j).v 
			      << " to " 
			      << hsp.Get(k).p << " - " << hsp.Get(k).v << endl;
			    */
			  }
		      }

		    if (pi1cand)
		      {
			pi1 = pi1cand;
			copyedge = 1;
			copyfromedge = j;
			copyedgeidentification = i;
#ifdef DEVELOP
			(*testout) << "copy edge startpoint from "
				   << startpoints.Get(j).p << " - " 
				   << startpoints.Get(j).v 
				   << " to " 
				   << hsp.Get(pi1).p << " - " << hsp.Get(pi1).v << endl;
#endif
		      }
		  }
	      }
	  }
      
      
	// cannot copy from other ege ?
	if (!pi1)
	  checkedcopy = startpoints.Size();
      
	// unconditional special point available ?
	if (!pi1)
	  for (i = 1; i <= hsp.Size() && pi1 == 0; i++)
	    if (hsp.Get(i).unconditional == 1)
	      pi1 = i;
 
     
	if (!pi1)
	  {
	    // only unconditional points available, choose first
	    pi1 = 1;
	  }

	layer = hsp.Get(pi1).GetLayer();
      

	if (!hsp.Get(pi1).unconditional)
	  {
	    hsp.Elem(pi1).unconditional = 1;
	    for (i = 1; i <= hsp.Size(); i++)
	      if (i != pi1 && Dist (hsp.Get(pi1).p, hsp.Get(i).p) < 1e-8 &&
		  (hsp.Get(pi1).v + hsp.Get(i).v).Length() < 1e-4)
		{
		  // opposite direction
		  hsp.Elem(i).unconditional = 1;
		}
	  }

	cntedge++;
	startpoints.Append (hsp.Get(pi1));

#ifdef DEVELOP
	(*testout) << "edge nr " << cntedge << endl;
	(*testout) << "start followedge: p1 = " << hsp.Get(pi1).p << ", v = " << hsp.Get(pi1).v << endl;
#endif

	FollowEdge (pi1, ep, pos, hsp, h, mesh,
		    edgepoints, curvelength);


	if (multithread.terminate)
	  return;
      
	if (!ep)
	  {
	    // ignore starting point
	    hsp.DeleteElement (pi1);
	    continue;
	  }



	endpoints.Append (hsp.Get(ep));


	double elen = 0;
	for (i = 1; i <= edgepoints.Size()-1; i++)
	  elen += Dist (edgepoints.Get(i), edgepoints.Get(i+1));


	int shortedge = 0;
	for (i = 1; i <= geometry.identifications.Size(); i++)
	  if (geometry.identifications.Get(i)->ShortEdge(hsp.Get(pi1), hsp.Get(ep)))
	    shortedge = 1;
	(*testout) << "shortedge = " << shortedge << endl;


	if (!shortedge)
	  {
	    mesh.RestrictLocalHLine (Point3d (hsp.Get(pi1).p), 
				     Point3d (hsp.Get(ep).p), 
				     elen / mparam.segmentsperedge);
	  }
      
	s1 = hsp.Get(pi1).s1;
	s2 = hsp.Get(pi1).s2;


	// delete initial, terminal and conditional points

#ifdef DEVELOP
	(*testout) << "terminal point: p = " << hsp.Get(ep).p << ", v = " << hsp.Get(ep).v << endl;      
#endif
	if (ep > pi1)
	  {
	    hsp.DeleteElement (ep);
	    hsp.DeleteElement (pi1);
	  }
	else
	  {
	    hsp.DeleteElement (pi1);
	    hsp.DeleteElement (ep);
	  }


	for (j = 1; j <= edgepoints.Size()-1; j++)
	  {
	    p = edgepoints.Get(j);
	    np = Center (p, edgepoints.Get(j+1));
	    hd = Dist2 (p, np);
 
	    for (i = 1; i <= hsp.Size(); i++)
	      if ( hsp.Get(i).HasSurfaces (s1, s2) &&
		   hsp.Get(i).unconditional == 0 &&
		   Dist2 (np, hsp.Get(i).p) < 1.2 * hd)
		{
		  hsp.DeleteElement (i);
		  i--;
		}
	  }

      
	ARRAY<Segment> refedges;
	ARRAY<int> refedgesinv;
      

	AnalyzeEdge (s1, s2, pos, layer,
		     edgepoints,
		     refedges, refedgesinv);

	for (i = 1; i <= refedges.Size(); i++)
	  refedges.Elem(i).edgenr = cntedge;


#ifdef DEVELOP
	(*testout) << "edge " << cntedge << endl
		   << "startp: " << startpoints.Last().p 
		   << ", v = " << startpoints.Last().v << endl
		   << "copy = " << copyedge << endl
		   << refedges.Size() << " refedges: ";
	for (i = 1; i <= refedges.Size(); i++)
	  (*testout) << " " << refedges.Get(i).si;
	(*testout) << endl;
	(*testout) << "inv[1] = " << refedgesinv.Get(1) << endl;
#endif
      
	if (!copyedge)
	  {
	    int oldnseg = mesh.GetNSeg();

	    if (!shortedge)
	      StoreEdge (refedges, refedgesinv, 
			 edgepoints, curvelength, layer, mesh);
	    else
	      StoreShortEdge (refedges, refedgesinv, 
			      edgepoints, curvelength, layer, mesh);


	    /*
	      for (i = oldnseg+1; i <= mesh.GetNSeg(); i++)
	      for (j = 1; j <= oldnseg; j++)
	      {
	      const Point<3> & l1p1 = mesh.Point (mesh.LineSegment(i).p1);
	      const Point<3> & l1p2 = mesh.Point (mesh.LineSegment(i).p2);
	      const Point<3> & l2p1 = mesh.Point (mesh.LineSegment(j).p1);
	      const Point<3> & l2p2 = mesh.Point (mesh.LineSegment(j).p2);
	      Vec<3> vl1(l1p1, l1p2);
	      for (double lamk = 0; lamk <= 1; lamk += 0.1)
	      {
	      Point<3> l2p = l1p1 + lamk * vl1;
	      double dist = sqrt (MinDistLP2 (l2p1, l2p2, l2p));
	      if (dist > 1e-12)
	      mesh.RestrictLocalH (l2p, 3*dist);
	      }
	      }
	    */
	  }
	else
	  {
	    CopyEdge (refedges, refedgesinv,
		      copyfromedge, 
		      startpoints.Get(copyfromedge).p,
		      endpoints.Get(copyfromedge).p,
		      edgepoints.Get(1), edgepoints.Last(),
		      copyedgeidentification, 
		      layer,
		      mesh);
	  }

      }
  }



  /*
    If two or more edges share the same initial and end-points,
    then they need at least two segments 
  */
  void EdgeCalculation ::
  SplitEqualOneSegEdges (Mesh & mesh)
  {
    int i, j;
    SegmentIndex si;
    PointIndex pi;

    ARRAY<int> osedges(cntedge);
    INDEX_2_HASHTABLE<int> osedgesht (cntedge+1);

    osedges = 2;

    // count segments on edges
    for (si = 0; si < mesh.GetNSeg(); si++)
      {
	const Segment & seg = mesh[si];
	if (seg.seginfo && seg.edgenr >= 1 && seg.edgenr <= cntedge)
	  osedges.Elem(seg.edgenr)--;
      }

    (*testout) << "osedges  = " << osedges << endl;

    // flag one segment edges
    for (i = 0; i < cntedge; i++)
      osedges[i] = (osedges[i] > 0) ? 1 : 0;

    (*testout) << "osedges, now  = " << osedges << endl;

    for (si = 0; si < mesh.GetNSeg(); si++)
      {
	const Segment & seg = mesh[si];
	if (seg.seginfo && seg.edgenr >= 1 && seg.edgenr <= cntedge)
	  {
	    if (osedges.Get(seg.edgenr))
	      {
		INDEX_2 i2(seg.p1, seg.p2);
		i2.Sort ();
		if (osedgesht.Used (i2))
		  osedgesht.Set (i2, 2);
		else
		  osedgesht.Set (i2, 1);
	      }
	  }
      }


    // one edge 1 segment, other 2 segments 
    // yes, it happens !
  
    for (i = 1; i <= osedgesht.GetNBags(); i++)
      for (j = 1; j <= osedgesht.GetBagSize(i); j++)
	{
	  INDEX_2 i2; 
	  int val;
	  osedgesht.GetData (i, j, i2, val);

	  const Point<3> & p1 = mesh[PointIndex(i2.I1())];
	  const Point<3> & p2 = mesh[PointIndex(i2.I2())];
	  Vec<3> v = p2 - p1;
	  double vlen = v.Length();
	  v /= vlen;
	  for (pi = PointIndex::BASE; 
	       pi < mesh.GetNP()+PointIndex::BASE; pi++)

	    if (pi != i2.I1() && pi != i2.I2())
	      {
		const Point<3> & p = mesh[pi];
		Vec<3> v2 = p - p1;
		double lam = (v2 * v);
		if (lam > 0 && lam < vlen)
		  {
		    Point<3> hp = p1 + lam * v;
		    if (Dist (p, hp) < 1e-4 * vlen)
		      {
			PrintSysError ("Point on edge !!!");
			cout << "seg: " << i2 << ", p = " << pi << endl;
			osedgesht.Set (i2, 2);		      
		      }
		  }
	      }
	}


    // insert new points
    osedges = -1;

    int nseg = mesh.GetNSeg();
    for (si = 0; si < nseg; si++)
      {
	const Segment & seg = mesh[si];
	if (seg.seginfo && seg.edgenr >= 1 && seg.edgenr <= cntedge)
	  {
	    INDEX_2 i2(seg.p1, seg.p2);
	    i2.Sort ();
	    if (osedgesht.Used (i2) &&
		osedgesht.Get (i2) == 2 &&
		osedges.Elem(seg.edgenr) == -1)
	      {
		Point<3> newp = Center (mesh[PointIndex(seg.p1)],
					mesh[PointIndex(seg.p2)]);

		ProjectToEdge (geometry.GetSurface(seg.surfnr1), 
			       geometry.GetSurface(seg.surfnr2), 
			       newp);

		osedges.Elem(seg.edgenr) = 
		  mesh.AddPoint (newp, mesh[PointIndex(seg.p1)].GetLayer());
	      }
	  }
      }


    for (i = 1; i <= nseg; i++)
      {
	Segment & seg = mesh.LineSegment (i);
	if (seg.edgenr >= 1 && seg.edgenr <= cntedge)
	  {
	    if (osedges.Get(seg.edgenr) != -1)
	      {
		Segment newseg = seg;
		newseg.p1 = osedges.Get(seg.edgenr);
		seg.p2 = osedges.Get(seg.edgenr);
		mesh.AddSegment (newseg);
	      }
	  }
      }

  }



  void EdgeCalculation :: 
  FollowEdge (int pi1, int & ep, int & pos,
	      const ARRAY<SpecialPoint> & hsp,
	      double h, const Mesh & mesh,
	      ARRAY<Point<3> > & edgepoints,
	      ARRAY<double> & curvelength)
  {
    int i, j, s1, s2;
    double len, steplen, cursteplen, loch;
    Point<3> p, np, pnp;
    Vec<3> a1, a2, t;


    double size = geometry.MaxSize();  
    double epspointdist2 = size * 1e-6;
    epspointdist2 = sqr (epspointdist2);
    int uselocalh = mparam.uselocalh;


    s1 = hsp.Get(pi1).s1;
    s2 = hsp.Get(pi1).s2;
  
    p = hsp.Get(pi1).p;
    geometry.GetSurface(s1) -> CalcGradient (p, a1);
    geometry.GetSurface(s2) -> CalcGradient (p, a2);

    t = Cross (a1, a2);
    t.Normalize();

    pos = (hsp.Get(pi1).v * t) > 0;
    if (!pos) t *= -1;

  
    edgepoints.Append (p);
    curvelength.Append (0);
    len = 0;

    loch = min2 (geometry.GetSurface(s1) -> LocH (p, 3, 1, h), 
		 geometry.GetSurface(s2) -> LocH (p, 3, 1, h));
  
  
  
    if (uselocalh)
      {
	double lh = mesh.GetH(p);
	if (lh < loch)
	  loch = lh;
      }

    steplen = 0.1 * loch;
  
    do
      {
	if (multithread.terminate)
	  return;
      
	if (fabs (p(0)) + fabs (p(1)) + fabs (p(2)) > 10000)
	  {
	    ep = 0;
	    PrintWarning ("Give up line");
	    break;
	  }

	if (steplen > 0.1 * loch) steplen = 0.1 * loch;
      
	steplen *= 2;
	do
	  {
	    steplen *= 0.5;
	    np = p + steplen * t;
	    pnp = np;
	    ProjectToEdge (geometry.GetSurface(s1), 
			   geometry.GetSurface(s2), pnp);
	  }
	while (Dist (np, pnp) > 0.1 * steplen);
      
	cursteplen = steplen;
	if (Dist (np, pnp) < 0.01 * steplen) steplen *= 2;
      
 
	np = pnp;
      
#ifdef MYGRAPH
	if (silentflag <= 2)
	  {
	    MyLine3D (p, np, rot);
	    MyDraw ();
	  }
#endif      

	ep = 0;
      
	double hvtmin = 1.5 * cursteplen;
      
	Box<3> boxp (p - (2 * cursteplen) * Vec<3> (1, 1, 1),
		     p + (2 * cursteplen) * Vec<3> (1, 1, 1));

	for (i = 1; i <= hsp.Size(); i++)
	  // if ( i != pi1 && hsp.Get(i).HasSurfaces (s1, s2) )
	  {
	    if (!boxp.IsIn (hsp.Get(i).p))
	      continue;
	  
	    Vec<3> hv = hsp.Get(i).p - p;
	    if (hv.Length2() > 9 * cursteplen * cursteplen)
	      continue;

	    /*
	    if (!hsp.Get(i).HasSurfaces (s1, s2))
	      continue;                  // test for dalibor-problem
	    */

	    double hvt = hv * t;
	    hv -= hvt * t;
	  
	    if (hv.Length() < 0.2 * cursteplen &&
		hvt > 0 && 
		//		  hvt < 1.5 * cursteplen &&
		hvt < hvtmin && 
		hsp.Get(i).unconditional == 1 &&
		(hsp.Get(i).v + t).Length() < 0.4  ) 
	      {
		Point<3> hep = hsp.Get(i).p;
		ProjectToEdge (geometry.GetSurface(s1), 
			       geometry.GetSurface(s2), hep);            
	      
	      
		if (Dist2 (hep, hsp.Get(i).p) < epspointdist2 )
		  {
		    geometry.GetSurface(s1) -> CalcGradient (hep, a1);
		    geometry.GetSurface(s2) -> CalcGradient (hep, a2);
		    Vec<3> ept = Cross (a1, a2);
		    ept /= ept.Length();
		    if (!pos) ept *= -1;
		  
		    if ( (hsp.Get(i).v + ept).Length() < 1e-4 )
		      {
			np = hsp.Get(i).p;
			ep = i;
			hvtmin = hvt;
			//			  break;
		      }
		  }
	      }
	  }

	loch = min2 (geometry.GetSurface(s1) -> LocH (np, 3, 1, h), 
		     geometry.GetSurface(s2) -> LocH (np, 3, 1, h));

	if (uselocalh)
	  {
	    double lh = mesh.GetH(np);
	    if (lh < loch)
	      loch = lh;
	  }
      
      
	len += Dist (p, np) / loch;
	edgepoints.Append (np);
	curvelength.Append (len);
      
	p = np;
      
	geometry.GetSurface(s1) -> CalcGradient (p, a1);
	geometry.GetSurface(s2) -> CalcGradient (p, a2);
	t = Cross (a1, a2);
	t.Normalize();
	if (!pos) t *= -1;
      }
    while (! ep);
  }







  void EdgeCalculation :: 
  AnalyzeEdge (int s1, int s2, int pos, int layer,
	       const ARRAY<Point<3> > & edgepoints,
	       ARRAY<Segment> & refedges,
	       ARRAY<int> & refedgesinv)
  {
    int i, j, k, l;
    int hi;
    Point<3> hp;
    Vec<3> t, a1, a2, m, n;
    Segment seg;
    Solid * locsol;
    ARRAY<int> locsurfind;

    /*
      int pi1 = 0, pi2 = 0;
      extern Mesh * mesh;
      for (i = 1; i <= mesh->GetNP(); i++)
      {
      if (Dist2 (edgepoints.Get(1), mesh->Point(i)) < 1e-12)
      pi1 = i;
      if (Dist2 (edgepoints.Last(), mesh->Point(i)) < 1e-12)
      pi2 = i;
      }
      (*testout) << "Analyze edge: " << pi1 << " - " << pi2 << ", pts = " << edgepoints.Size() << endl;
      (*testout) << "p1 = " << edgepoints.Get(1) << " pl = " << edgepoints.Last() << endl;
    */
    int debug = 0;
    /*
      Dist2 (Point<3> (2.69642, 1.1866, 2.03), edgepoints.Get(1)) < 1e-6 ||
      Dist2 (Point<3> (2.69642, 1.1866, 2.03), edgepoints.Last()) < 1e-6;
    */

    if (debug)
      {
	//      (*testout) << "tubious edge !!!" << endl;
	(*testout) << "s1, s2 = " << s1 << " - " << s2 << endl;
      }

    refedges.SetSize(0);
    refedgesinv.SetSize(0);
    hp = Center (edgepoints.Get(1), edgepoints.Get(2));
    ProjectToEdge (geometry.GetSurface(s1), geometry.GetSurface(s2), hp);

    geometry.GetSurface(s1) -> CalcGradient (hp, a1);
    geometry.GetSurface(s2) -> CalcGradient (hp, a2);
    t = Cross (a1, a2);
    t.Normalize();
    if (!pos) t *= -1;    
  
    (*testout) << "t = " << t << endl;

    for (i = 0; i < geometry.GetNTopLevelObjects(); i++)
      {
	(*testout) << "layer = " << layer 
		   << ", tlo-layer = " << geometry.GetTopLevelObject(i)->GetLayer() << endl;
	if (geometry.GetTopLevelObject(i)->GetLayer() != layer) 
	  continue;
      
	const Solid * sol = geometry.GetTopLevelObject(i)->GetSolid();
	const Surface * surf = geometry.GetTopLevelObject(i)->GetSurface();

	sol -> TangentialSolid (hp, locsol);
	if (!locsol) continue;

	BoxSphere<3> boxp (hp, hp);
	boxp.Increase (1e-5);
	boxp.CalcDiamCenter();
      
	ReducePrimitiveIterator rpi(boxp);
	UnReducePrimitiveIterator urpi;
      
	((Solid*)locsol) -> IterateSolid (rpi);

	locsol -> CalcSurfaceInverse ();
      

	if (!surf)
	  {
	    locsol -> GetSurfaceIndices (locsurfind);
	  }
	else
	  {
	    /*
	      if (fabs (surf->CalcFunctionValue (hp)) < 1e-6)
	      continue;
	    */
	    locsurfind.SetSize(1);
	    locsurfind[0] = -1;
	    for (j = 0; j < geometry.GetNSurf(); j++)
	      if (geometry.GetSurface(j) == surf)
		{
		  locsurfind[0] = j;
		  //		      geometry.GetSurfaceClassRepresentant(j);
		  break;
		}
	  }

	((Solid*)locsol) -> IterateSolid (urpi);

      
	if (debug)
	  (*testout) << "edge of tlo " << i << ", has " << locsurfind.Size() << " faces." << endl;
      

	for (j = locsurfind.Size()-1; j >= 0; j--)
	  if (fabs (geometry.GetSurface(locsurfind[j])
		    ->CalcFunctionValue (hp) ) > 1e-6)
	    locsurfind.DeleteElement(j+1);
      
	if (debug)
	  (*testout) << locsurfind.Size() << " faces on hp" << endl;

	for (j = 0; j < locsurfind.Size(); j++)
	  {      
	    int lsi = locsurfind[j];
	    int rlsi = geometry.GetSurfaceClassRepresentant(lsi);
	  
	    Vec<3> rn;

	    // n is outer normal to solid
	    geometry.GetSurface(lsi) -> GetNormalVector (hp, n);
	    if (geometry.GetSurface (lsi)->Inverse())
	      n *= -1;
	  
	    if (fabs (t * n) > 1e-4) continue;
	    if (debug)
	      {
		(*testout) << "face " << locsurfind.Get(j) << ", rep = " << rlsi 
			   << " has (t*n) = " << (t*n) << endl;
		(*testout) << "n = " << n << endl;
	      }
	  
	    // rn is normal to class representant
	    geometry.GetSurface(rlsi) -> GetNormalVector (hp, rn);
	  
	    int sameasref = ((n * rn) > 0);
	  
	    m = Cross (t, rn);
	    m.Normalize();
	  

	    for (k = 1; k <= 2; k ++)
	      {
		bool edgeinv = (k == 2);
	      
		if (debug)
		  {
		    (*testout) << "onface(" << hp << ", " << m << ")= " 
			       << locsol->OnFace (hp, m);
		    (*testout) << " vec2in = "
			       << locsol -> VectorIn2 (hp, m, n) << " and " 
			       << locsol -> VectorIn2 (hp, m, -1 * n) << endl;
		  }

		//	      if (locsol -> OnFace (hp, m))
		if (locsol -> VectorIn2 (hp, m, n) == 0 &&
		    locsol -> VectorIn2 (hp, m, -1 * n) == 1)
		  {
		    hi = 0;
		    for (l = 1; l <= refedges.Size(); l++)
		      {
			if (refedges.Get(l).si == rlsi &&
			    refedgesinv.Get(l) == edgeinv)
			  hi = l;
		      }
		  
		    if (!hi)
		      {
			seg.si = rlsi;
			seg.domin = -1;
			seg.domout = -1;
			seg.tlosurf = -1;
			seg.surfnr1 = s1;
			seg.surfnr2 = s2;
			hi = refedges.Append (seg);
			refedgesinv.Append (edgeinv);
		      }
		  
		    if (!surf)
		      {
			if (sameasref)
			  refedges.Elem(hi).domin = i;
			else 
			  refedges.Elem(hi).domout = i;
		      }
		    else
		      refedges.Elem(hi).tlosurf = i;

		    if (debug)
		      (*testout) << "add ref seg:" 
				 << "si = " << refedges.Get(hi).si
				 << ", domin = " << refedges.Get(hi).domin
				 << ", domout = " << refedges.Get(hi).domout
				 << ", surfnr1/2 = " << refedges.Get(hi).surfnr1
				 << ", " << refedges.Get(hi).surfnr2
				 << ", inv = " << refedgesinv.Get(hi) 
				 << ", refedgenr = " << hi
				 << endl;
		  }
		m *= -1;
	      } 
	  }
	delete locsol;          
      }
  }



  void EdgeCalculation :: 
  StoreEdge (const ARRAY<Segment> & refedges,
	     const ARRAY<int> & refedgesinv,
	     const ARRAY<Point<3> > & edgepoints,
	     const ARRAY<double> & curvelength,
	     int layer,
	     Mesh & mesh)
  {
  
    // Calculate optimal element-length
    int i, j, k;
    PointIndex pi;
    int ne;

    double len, corr, lam;
    PointIndex thispi, lastpi;
    Point<3> p, np;
    Segment seg;


    const Surface * surf1 = geometry.GetSurface (refedges.Get(1).surfnr1);
    const Surface * surf2 = geometry.GetSurface (refedges.Get(1).surfnr2);

    len = curvelength.Last();
    ne = int (len + 0.5);
    if (ne == 0) ne = 1;
    if (Dist2 (edgepoints.Get(1), edgepoints.Last()) < 1e-8 && 
	ne <= 6) 
      ne = 6;
    corr = len / ne;

    // generate initial point
    p = edgepoints.Get(1);
    lastpi = -1;
    for (pi = PointIndex::BASE; 
	 pi < mesh.GetNP()+PointIndex::BASE; pi++)
      if (Dist (mesh[pi], p) < 1e-6)
	{
	  lastpi = pi;
	  break;
	}

    if (lastpi == -1)
      lastpi = mesh.AddPoint (p, layer);

  
    j = 1;
    for (i = 1; i <= ne; i++)
      {
	while (curvelength.Get(j) < i * corr && j < curvelength.Size()) j++;
      
	lam = (i * corr - curvelength.Get(j-1)) / 
	  (curvelength.Get(j) - curvelength.Get(j-1));
      
	np(0) = (1-lam) * edgepoints.Get(j-1)(0) + lam * edgepoints.Get(j)(0);
	np(1) = (1-lam) * edgepoints.Get(j-1)(1) + lam * edgepoints.Get(j)(1);
	np(2) = (1-lam) * edgepoints.Get(j-1)(2) + lam * edgepoints.Get(j)(2);
      
      
	thispi = -1;
	if (i == ne)
	  for (pi = PointIndex::BASE; 
	       pi < mesh.GetNP()+PointIndex::BASE; pi++)
	    if (Dist(mesh[pi], np) < 1e-6)
	      thispi = pi;
      
	if (thispi == -1)
	  {
	    ProjectToEdge (surf1, surf2, np);
	    thispi = mesh.AddPoint (np, layer);
	  }

	for (k = 1; k <= refedges.Size(); k++)
	  {
	    if (refedgesinv.Get(k))
	      {
		seg.p1 = lastpi;
		seg.p2 = thispi;
	      }
	    else
	      {
		seg.p1 = thispi;
		seg.p2 = lastpi;
	      }
	    seg.si = refedges.Get(k).si;
	    seg.domin = refedges.Get(k).domin;
	    seg.domout = refedges.Get(k).domout;
	    seg.tlosurf = refedges.Get(k).tlosurf;
	    seg.edgenr = refedges.Get(k).edgenr;
	    seg.surfnr1 = refedges.Get(k).surfnr1;
	    seg.surfnr2 = refedges.Get(k).surfnr2;
	    seg.seginfo = 0;
	    if (k == 1) seg.seginfo = (refedgesinv.Get(k)) ? 2 : 1;
	    mesh.AddSegment (seg);
	    //	  (*testout) << "add seg " << seg.p1 << "-" << seg.p2 << endl;
	  
	    double maxh = min2 (geometry.GetSurface(seg.surfnr1)->GetMaxH(),
				geometry.GetSurface(seg.surfnr2)->GetMaxH());
			      
	    if (seg.domin != -1)
	      {
		const Solid * s1 = 
		  geometry.GetTopLevelObject(seg.domin) -> GetSolid();
		maxh = min2 (maxh, s1->GetMaxH());
		maxh = min2 (maxh, geometry.GetTopLevelObject(seg.domin)->GetMaxH());
		mesh.RestrictLocalH (p, maxh);
		mesh.RestrictLocalH (np, maxh);
	      }
	    if (seg.domout != -1)
	      {
		const Solid * s1 = 
		  geometry.GetTopLevelObject(seg.domout) -> GetSolid();
		maxh = min2 (maxh, s1->GetMaxH());
		maxh = min2 (maxh, geometry.GetTopLevelObject(seg.domout)->GetMaxH());
		mesh.RestrictLocalH (p, maxh);
		mesh.RestrictLocalH (np, maxh);
	      }
	    if (seg.tlosurf != -1)
	      {
		double hi = geometry.GetTopLevelObject(seg.tlosurf) -> GetMaxH();
		maxh = min2 (maxh, hi);
		mesh.RestrictLocalH (p, maxh);
		mesh.RestrictLocalH (np, maxh);
	      }	  
	  }
      
	p = np;
	lastpi = thispi;
      }

#ifdef DEVELOP
    (*testout) << " eplast = " << lastpi << " = " << p << endl;
#endif
  }
  





  void EdgeCalculation :: 
  StoreShortEdge (const ARRAY<Segment> & refedges,
		  const ARRAY<int> & refedgesinv,
		  const ARRAY<Point<3> > & edgepoints,
		  const ARRAY<double> & curvelength,
		  int layer,
		  Mesh & mesh)
  {
  
    // Calculate optimal element-length
    int i, j, k;
    PointIndex pi;
    int ne;
    Segment seg;

    /*
      double len, corr, lam;
      int thispi, lastpi;
      Point<3> p, np;


      const Surface * surf1 = geometry.GetSurface (refedges.Get(1).surfnr1);
      const Surface * surf2 = geometry.GetSurface (refedges.Get(1).surfnr2);

      len = curvelength.Last();
      ne = int (len + 0.5);
      if (ne == 0) ne = 1;
      if (Dist2 (edgepoints[1], edgepoints.Last()) < 1e-8 && 
      ne <= 6) 
      ne = 6;
      corr = len / ne;
    */

    // generate initial point
    Point<3> p = edgepoints[0];
    PointIndex pi1 = -1;
    for (pi = PointIndex::BASE; 
	 pi < mesh.GetNP()+PointIndex::BASE; pi++)

      if (Dist (mesh[pi], p) < 1e-6)
	{
	  pi1 = pi;
	  break;
	}

    if (pi1 == -1) pi1 = mesh.AddPoint (p, layer);

    p = edgepoints.Last();
    PointIndex pi2 = -1;
    for (pi = PointIndex::BASE; 
	 pi < mesh.GetNP()+PointIndex::BASE; pi++)

      if (Dist (mesh[pi], p) < 1e-6)
	{
	  pi2 = pi;
	  break;
	}
    if (pi2==-1) pi2 = mesh.AddPoint (p, layer);

    /*
  
    j = 1;
    for (i = 1; i <= ne; i++)
    {
    while (curvelength[j] < i * corr && j < curvelength.Size()) j++;
      
    lam = (i * corr - curvelength[j-1]) / 
    (curvelength[j] - curvelength[j-1]);
      
    np(0) = (1-lam) * edgepoints[j-1](0) + lam * edgepoints[j](0);
    np(1) = (1-lam) * edgepoints[j-1](1) + lam * edgepoints[j](1);
    np(2) = (1-lam) * edgepoints[j-1](2) + lam * edgepoints[j](2);
      
      
    thispi = 0;
    if (i == ne)
    for (j = 1; j <= mesh.GetNP(); j++)
    if (Dist(mesh.Point(j), np) < 1e-6)
    thispi = j;
      
    if (!thispi)
    {
    ProjectToEdge (surf1, surf2, np);
    thispi = mesh.AddPoint (np);
    }
    */
  
    for (k = 1; k <= refedges.Size(); k++)
      {
	if (refedgesinv.Get(k))
	  {
	    seg.p1 = pi1;
	    seg.p2 = pi2;
	  }
	else
	  {
	    seg.p1 = pi2;
	    seg.p2 = pi1;
	  }

	seg.si = refedges.Get(k).si;
	seg.domin = refedges.Get(k).domin;
	seg.domout = refedges.Get(k).domout;
	seg.tlosurf = refedges.Get(k).tlosurf;
	seg.edgenr = refedges.Get(k).edgenr;
	seg.surfnr1 = refedges.Get(k).surfnr1;
	seg.surfnr2 = refedges.Get(k).surfnr2;
	seg.seginfo = 0;
	if (k == 1) seg.seginfo = (refedgesinv.Get(k)) ? 2 : 1;
	mesh.AddSegment (seg);
	//	  (*testout) << "add seg " << seg.p1 << "-" << seg.p2 << endl;
      }
  }
  






  void EdgeCalculation :: 
  CopyEdge (const ARRAY<Segment> & refedges,
	    const ARRAY<int> & refedgesinv,
	    int copyfromedge, 
	    const Point<3> & fromstart, const Point<3> & fromend,
	    const Point<3> & tostart, const Point<3> & toend,
	    int copyedgeidentification, 
	    int layer,
	    Mesh & mesh)
  {
    int i, j, k;
    PointIndex pi;

    // copy start and end points
    for (i = 1; i <= 2; i++)
      {
	Point<3> fromp =
	  (i == 1) ? fromstart : fromend;
	Point<3> top =
	  (i == 1) ? tostart : toend;
      
	PointIndex frompi = -1;
	PointIndex topi = -1;
	for (pi = PointIndex::BASE; 
	     pi < mesh.GetNP()+PointIndex::BASE; pi++)
	  {
	    if (Dist2 (mesh[pi], fromp) <= 1e-16)
	      frompi = pi;
	    if (Dist2 (mesh[pi], top) <= 1e-16)
	      topi = pi;
	  }

	if (topi == -1)
	  topi = mesh.AddPoint (top, layer);

	const Identification & csi = 
	  (*geometry.identifications.Get(copyedgeidentification));

	if (csi.Identifyable (mesh[frompi], mesh[topi]))
	  mesh.GetIdentifications().Add(frompi, topi, copyedgeidentification);
	else if (csi.Identifyable (mesh[topi], mesh[frompi]))
	  mesh.GetIdentifications().Add(topi, frompi, copyedgeidentification);
	else
	  {
	    cerr << "edgeflw.cpp: should identify, but cannot";
	    exit(1);
	  }
	/*
	  (*testout) << "Add Identification from CopyEdge, p1 = " 
	  << mesh[PointIndex(frompi)] << ", p2 = " 
	  << mesh[PointIndex(topi)] << endl;

	  mesh.GetIdentifications().Add(frompi, topi, copyedgeidentification);
	*/
      }

    int oldns = mesh.GetNSeg();
    for (i = 1; i <= oldns; i++)
      {
	// real copy, since array might be reallocated !!
	const Segment oldseg = mesh.LineSegment(i);
	if (oldseg.edgenr != copyfromedge)
	  continue;
	if (oldseg.seginfo == 0)
	  continue;

	int pi1 = oldseg.p1;
	int pi2 = oldseg.p2;

	int npi1 = geometry.identifications.Get(copyedgeidentification)
	  -> GetIdentifiedPoint (mesh, pi1);
	int npi2 = geometry.identifications.Get(copyedgeidentification)
	  -> GetIdentifiedPoint (mesh, pi2);

	Segment seg;

	for (k = 1; k <= refedges.Size(); k++)
	  {
	    int inv = refedgesinv.Get(k);

	    // other edge is inverse
	    if (oldseg.seginfo == 1)
	      inv = !inv;

	    //	  (*testout) << "inv, now = " << inv << endl;

	    if (inv)
	      {
		seg.p1 = npi1;
		seg.p2 = npi2;
	      }
	    else
	      {
		seg.p1 = npi2;
		seg.p2 = npi1;
	      }
	    seg.si = refedges.Get(k).si;
	    seg.domin = refedges.Get(k).domin;
	    seg.domout = refedges.Get(k).domout;
	    seg.tlosurf = refedges.Get(k).tlosurf;
	    seg.edgenr = refedges.Get(k).edgenr;
	    seg.surfnr1 = refedges.Get(k).surfnr1;
	    seg.surfnr2 = refedges.Get(k).surfnr2;
	    seg.seginfo = 0;
	    if (k == 1) seg.seginfo = refedgesinv.Get(k) ? 2 : 1;
	    mesh.AddSegment (seg);
	    //	  (*testout) << "copy seg " << seg.p1 << "-" << seg.p2 << endl;
#ifdef DEVELOP

	    (*testout) << "copy seg, face = " << seg.si << ": " 
		       << " inv = " << inv << ", refinv = " << refedgesinv.Get(k)
		       << mesh.Point(seg.p1) << ", " << mesh.Point(seg.p2) << endl;
#endif

	  }
      
      }   
  }
  






  void EdgeCalculation :: 
  FindClosedSurfaces (double h, Mesh & mesh)
  {
    // if there is no special point at a sphere, one has to add a segment pair
  
    int i, j; 
    int nsol; 
    int nsurf = geometry.GetNSurf();
    int layer;

    BitArray pointatsurface (nsurf);
    Point<3> p1, p2;
    Vec<3> nv, tv;
    Solid * tansol;
    ARRAY<int> tansurfind;
    //  const Solid * sol;

    nsol = geometry.GetNTopLevelObjects();


    pointatsurface.Clear();
  
    /*
      for (i = 1; i <= specpoints.Size(); i++)
      {
      int classrep;

      classrep = geometry.GetSurfaceClassRepresentant (specpoints[i].s1);
      pointatsurface.Set (classrep);
      classrep = geometry.GetSurfaceClassRepresentant (specpoints[i].s2);
      pointatsurface.Set (classrep);
      //      pointatsurface.Set (specpoints[i].s1);
      //      pointatsurface.Set (specpoints[i].s2);
      }
    */
    for (i = 1; i <= mesh.GetNSeg(); i++)
      {
	const Segment & seg = mesh.LineSegment(i);
	int classrep;

#ifdef DEVELOP      
	(*testout) << seg.surfnr1 << ", " << seg.surfnr2 << ", si = " << seg.si << endl;
#endif
	classrep = geometry.GetSurfaceClassRepresentant (seg.si);

	pointatsurface.Set (classrep);
      }

  
    for (i = 0; i < nsurf; i++)
      {
	int classrep = geometry.GetSurfaceClassRepresentant (i);

	if (!pointatsurface.Test(classrep))
	  {
	    const Surface * s = geometry.GetSurface(i);
	    p1 = s -> GetSurfacePoint();
	    s -> GetNormalVector (p1, nv);
		    
	    double hloc = 
	      min2 (s->LocH (p1, 3, 1, h), mesh.GetH(p1));

	    tv = nv.GetNormal ();
	    tv *=  (hloc / tv.Length());
	    p2 = p1 + tv;
	    s->Project (p2);
	  
		    
	    Segment seg1;
	    seg1.si = i;
	    seg1.domin = -1;
	    seg1.domout = -1;

	    Segment seg2;
	    seg2.si = i;
	    seg2.domin = -1;
	    seg2.domout = -1;

	    seg1.surfnr1 = i;
	    seg2.surfnr1 = i;
	    seg1.surfnr2 = i;
	    seg2.surfnr2 = i;

	    for (j = 0; j < nsol; j++)
	      {
		if (geometry.GetTopLevelObject(j)->GetSurface())
		  continue;

		const Solid * sol = geometry.GetTopLevelObject(j)->GetSolid();
		sol -> TangentialSolid (p1, tansol);
		layer = geometry.GetTopLevelObject(j)->GetLayer();

		if (tansol)
		  {
		    tansol -> GetSurfaceIndices (tansurfind);
		
		    if (tansurfind.Size() == 1 && tansurfind.Get(1) == i)
		      {
			if (!tansol->VectorIn(p1, nv))
			  {
			    seg1.domin = j;
			    seg2.domin = j;
			    seg1.tlosurf = j;
			    seg2.tlosurf = j;
			  }
			else
			  {
			    seg1.domout = j;
			    seg2.domout = j;
			    seg1.tlosurf = j;
			    seg2.tlosurf = j;
			  }
			//        seg.s2 = i;
			//        seg.invs1 = surfaces[i] -> Inverse();
			//        seg.invs2 = ! (surfaces[i] -> Inverse());
		      }
		    delete tansol;
		  }
	      }


	    if (seg1.domin != -1 || seg1.domout != -1)
	      {
		mesh.AddPoint (p1, layer);
		mesh.AddPoint (p2, layer);
		seg1.p1 = mesh.GetNP()-1;
		seg1.p2 = mesh.GetNP();
		seg2.p2 = mesh.GetNP()-1;
		seg2.p1 = mesh.GetNP();
		seg1.geominfo[0].trignum = 1;
		seg1.geominfo[1].trignum = 1;
		seg2.geominfo[0].trignum = 1;
		seg2.geominfo[1].trignum = 1;
		mesh.AddSegment (seg1);
		mesh.AddSegment (seg2);

		PrintMessage (5, "Add line segment to smooth surface");

#ifdef DEVELOP
		(*testout) << "Add segment at smooth surface " << i;
		if (i != classrep) (*testout) << ", classrep = " << classrep;
		(*testout) << ": "
			   << mesh.Point (mesh.GetNP()-1) << " - "
			   << mesh.Point (mesh.GetNP()) << endl;
#endif
	      }
	  }
      }
  }

}

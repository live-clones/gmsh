#include <mystdlib.h>
#include "meshing.hpp"


namespace netgen
{
  void Refinement :: Refine (Mesh & mesh, int /* levels */)
  {
    int i, j, k;


    // reduce 2nd order
    mesh.ComputeNVertices();
    mesh.SetNP(mesh.GetNV());



    //  for (l = 1; l <= levels; l++)
    //    {
    INDEX_2_HASHTABLE<int> between(mesh.GetNP() + 5);
      
    int oldne, oldns, oldnf;

    // refine edges


    ARRAY<EdgePointGeomInfo> epgi;

    oldns = mesh.GetNSeg();

    for (i = 1; i <= oldns; i++)
      {
	const Segment & el = mesh.LineSegment(i);

	INDEX_2 i2(el.p1, el.p2);
	i2.Sort();

	int pnew;
	EdgePointGeomInfo ngi;

	if (between.Used(i2))
	  {
	    pnew = between.Get(i2);
	    ngi = epgi.Get(pnew);
	  }
	else
	  {
	    Point3d pb;
	    pb = Center (mesh.Point (el.p1),
			 mesh.Point (el.p2));

	    PointBetween (mesh.Point (el.p1),
			  mesh.Point (el.p2), 0.5,
			  el.surfnr1, el.surfnr2,
			  el.epgeominfo[0], el.epgeominfo[1],
			  pb, ngi);

	    pnew = mesh.AddPoint (pb);

	    between.Set (i2, pnew);

	    if (pnew > epgi.Size())
	      epgi.SetSize (pnew);
	    epgi.Elem(pnew) = ngi;

	    (*testout) << "ref edge, oldgi = " 
		       << el.epgeominfo[0] << " - " << el.epgeominfo[1] 
		       << ", new gi = " << ngi << endl;
	    
	  }

	Segment ns1 = el;
	Segment ns2 = el;
	ns1.p2 = pnew;
	ns1.epgeominfo[1] = ngi;
	ns2.p1 = pnew;
	ns2.epgeominfo[0] = ngi;

	mesh.LineSegment(i) = ns1;
	mesh.AddSegment (ns2);
      }



    (*testout) << "refine surfaces" << endl;
    // refine surface elements

    ARRAY<PointGeomInfo> surfgi (8*mesh.GetNP());
    for (i = 1; i <= surfgi.Size(); i++)
      surfgi.Elem(i).trignum = -1;

    oldnf = mesh.GetNSE();
    for (i = 1; i <= oldnf; i++)
      {
	int j, k;
	const Element2d & el = mesh.SurfaceElement(i);

	switch (el.GetType())
	  {
	  case TRIG:
	  case TRIG6:
	    {
	      ArrayMem<int,6> pnums(6);
	      ArrayMem<PointGeomInfo,6> pgis(6);
	      
	      static int betw[3][3] =
		{ { 2, 3, 4 },
		  { 1, 3, 5 },
		  { 1, 2, 6 } };
	      
	      for (j = 1; j <= 3; j++)
		{
		  pnums.Elem(j) = el.PNum(j);
		  pgis.Elem(j) = el.GeomInfoPi(j);
		}
	      
	      for (j = 0; j < 3; j++)
		{
		  int pi1 = pnums.Elem(betw[j][0]);
		  int pi2 = pnums.Elem(betw[j][1]);
		  
		  INDEX_2 i2 (pi1, pi2);
		  i2.Sort();
		  


		  Point3d pb;
		  PointGeomInfo pgi;
		  PointBetween (mesh.Point (pi1),
				mesh.Point (pi2), 0.5,
				mesh.GetFaceDescriptor(el.GetIndex ()).SurfNr(),
				el.GeomInfoPi (betw[j][0]),
				el.GeomInfoPi (betw[j][1]),
				pb, pgi);


		  pgis.Elem(4+j) = pgi;
		  if (between.Used(i2))
		    pnums.Elem(4+j) = between.Get(i2);
		  else
		    {
		      pnums.Elem(4+j) = mesh.AddPoint (pb);
		      between.Set (i2, pnums.Get(4+j));
		    }

		  if (surfgi.Size() < pnums.Elem(4+j))
		    surfgi.SetSize (pnums.Elem(4+j));
		  surfgi.Elem(pnums.Elem(4+j)) = pgis.Elem(4+j);
		      

		  /*
		  if (between.Used(i2))
		    {
		      pnums.Elem(4+j) = between.Get(i2);
		      pgis.Elem(4+j) = surfgi.Get(pnums.Elem(4+j));
		    }
		  else
		    {
		      Point3d pb;
		      PointBetween (mesh.Point (pi1),
				    mesh.Point (pi2), 0.5,
				    mesh.GetFaceDescriptor(el.GetIndex ()).SurfNr(),
				    el.GeomInfoPi (betw[j][0]),
				    el.GeomInfoPi (betw[j][1]),
				    pb, pgis.Elem(4+j));
		    
		      pnums.Elem(4+j) = mesh.AddPoint (pb);
		    
		      between.Set (i2, pnums.Get(4+j));
		    
		      if (surfgi.Size() < pnums.Elem(4+j))
			surfgi.SetSize (pnums.Elem(4+j));
		      surfgi.Elem(pnums.Elem(4+j)) = pgis.Elem(4+j);

		      (*testout) << "ref face, oldgi = " 
				 << el.GeomInfoPi (betw[j][0]) << " - " 
				 << el.GeomInfoPi (betw[j][1])
				 << ", new gi = " << pgis.Elem(4+j) << endl;

		    }
		  */
		}

	      static int reftab[4][3] = 
		{ { 1, 6, 5 },
		  { 2, 4, 6 },
		  { 3, 5, 4 },
		  { 6, 4, 5 } };
	    
	      int ind = el.GetIndex();
	      for (j = 0; j < 4; j++)
		{
		  Element2d nel(TRIG);
		  for (k = 1; k <= 3; k++)
		    {
		      nel.PNum(k) = pnums.Get(reftab[j][k-1]);
		      nel.GeomInfoPi(k) = pgis.Get(reftab[j][k-1]);
		    }
		  nel.SetIndex(ind);
		
		  if (j == 0)
		    mesh.SurfaceElement(i) = nel;
		  else
		    mesh.AddSurfaceElement(nel);
		}
	      break;
	    }
	  case QUAD:
	  case QUAD6:
	    {
	      ArrayMem<int,9> pnums(9);
	      ArrayMem<PointGeomInfo,9> pgis(9);
	    
	      static int betw[5][3] =
		{ { 1, 2, 5 },
		  { 2, 3, 6 },
		  { 3, 4, 7 },
		  { 1, 4, 8 },
		  { 1, 3, 9 } };
	    
	      for (j = 1; j <= 4; j++)
		{
		  pnums.Elem(j) = el.PNum(j);
		  pgis.Elem(j) = el.GeomInfoPi(j);
		}
	    
	      for (j = 0; j < 5; j++)
		{
		  int pi1 = pnums.Elem(betw[j][0]);
		  int pi2 = pnums.Elem(betw[j][1]);
		
		  INDEX_2 i2 (pi1, pi2);
		  i2.Sort();
		
		  if (between.Used(i2))
		    {
		      pnums.Elem(5+j) = between.Get(i2);
		      pgis.Elem(5+j) = surfgi.Get(pnums.Elem(4+j));
		    }
		  else
		    {
		      Point3d pb;
		      PointBetween (mesh.Point (pi1),
				    mesh.Point (pi2), 0.5,
				    mesh.GetFaceDescriptor(el.GetIndex ()).SurfNr(),
				    el.GeomInfoPi (betw[j][0]),
				    el.GeomInfoPi (betw[j][1]),
				    pb, pgis.Elem(5+j));
		    
		      pnums.Elem(5+j) = mesh.AddPoint (pb);
		    
		      between.Set (i2, pnums.Get(5+j));
		    
		      if (surfgi.Size() < pnums.Elem(5+j))
			surfgi.SetSize (pnums.Elem(5+j));
		      surfgi.Elem(pnums.Elem(5+j)) = pgis.Elem(5+j);
		    }
		}

	      static int reftab[4][4] = 
		{ 
		  { 1, 5, 9, 8 },
		  { 5, 2, 6, 9 },
		  { 8, 9, 7, 4 },
		  { 9, 6, 3, 7 } };

	      int ind = el.GetIndex();
	      for (j = 0; j < 4; j++)
		{
		  Element2d nel(QUAD);
		  for (k = 1; k <= 4; k++)
		    {
		      nel.PNum(k) = pnums.Get(reftab[j][k-1]);
		      nel.GeomInfoPi(k) = pgis.Get(reftab[j][k-1]);
		    }
		  nel.SetIndex(ind);
		
		  if (j == 0)
		    mesh.SurfaceElement(i) = nel;
		  else
		    mesh.AddSurfaceElement(nel);
		}
	      break;
	    }
	  default:
	    PrintSysError ("Refine: undefined surface element type ", int(el.GetType()));
	  }
      }
    
    (*testout) << "refine volume" << endl;

    // refine volume elements
    oldne = mesh.GetNE();
    for (i = 1; i <= oldne; i++)
      {
	int j, k;
	const Element & el = mesh.VolumeElement(i);
	ArrayMem<int,10> pnums(10);
	static int betw[6][3] =
	  { { 1, 2, 5 },
	    { 1, 3, 6 },
	    { 1, 4, 7 },
	    { 2, 3, 8 },
	    { 2, 4, 9 },
	    { 3, 4, 10 } };
	  
	int elrev = el.flags.reverse;

	for (j = 1; j <= 4; j++)
	  pnums.Elem(j) = el.PNum(j);
	if (elrev)
	  Swap (pnums.Elem(3), pnums.Elem(4));

	for (j = 0; j < 6; j++)
	  {
	    INDEX_2 i2;
	    i2.I1() = pnums.Get(betw[j][0]);
	    i2.I2() = pnums.Get(betw[j][1]);
	    i2.Sort();

	    if (between.Used(i2))
	      pnums.Elem(5+j) = between.Get(i2);
	    else
	      {
		pnums.Elem(5+j) = mesh.AddPoint
		  (Center (mesh.Point(i2.I1()),
			   mesh.Point(i2.I2())));
		between.Set (i2, pnums.Elem(5+j));
	      }
	  }

	static int reftab[8][4] = 
	  { { 1, 5, 6, 7 },
	    { 5, 2, 8, 9 },
	    { 6, 8, 3, 10 },
	    { 7, 9, 10, 4 },
	    { 5, 6, 7, 9 },
	    { 5, 6, 9, 8 },
	    { 6, 7, 9, 10 },
	    { 6, 8, 10, 9 } };
	/*
	  { { 1, 5, 6, 7 },
	  { 5, 2, 8, 9 },
	  { 6, 8, 3, 10 },
	  { 7, 9, 10, 4 },
	  { 5, 6, 7, 9 },
	  { 5, 6, 8, 9 },
	  { 6, 7, 9, 10 },
	  { 6, 8, 9, 10 } };
	*/
	static int reverse[8] =
	  {
	    0, 0, 0, 0, 0, 1, 0, 1
	  };

	int ind = el.GetIndex();
	for (j = 0; j < 8; j++)
	  {
	    Element nel;
	    for (k = 1; k <= 4; k++)
	      nel.PNum(k) = pnums.Get(reftab[j][k-1]);
	    nel.SetIndex(ind);
	    nel.flags.reverse = reverse[j];
	    if (elrev)
	      {
		nel.flags.reverse = 1 - nel.flags.reverse;
		Swap (nel.PNum(3), nel.PNum(4));
	      }

	    if (j == 0)
	      mesh.VolumeElement(i) = nel;
	    else
	      mesh.AddVolumeElement (nel);
	  }
      }
      
    // update identification tables
    for (i = 1; i <= mesh.GetIdentifications().GetMaxNr(); i++)
      {
	ARRAY<int,PointIndex::BASE> identmap;
	mesh.GetIdentifications().GetMap (i, identmap);

	for (j = 1; j <= between.GetNBags(); j++)
	  for (k = 1; k <= between.GetBagSize(j); k++)
	    {
	      INDEX_2 i2;
	      int newpi;
	      between.GetData (j, k, i2, newpi);
	      INDEX_2 oi2(identmap.Get(i2.I1()),
			  identmap.Get(i2.I2()));
	      oi2.Sort();
	      if (between.Used (oi2))
		{
		  int onewpi = between.Get(oi2);
		  mesh.GetIdentifications().Add (newpi, onewpi, i);
		}
	    }

      }


    
      

    int cnttrials = 10;
    int wrongels = 0;
    for (i = 1; i <= mesh.GetNE(); i++)
      if (mesh.VolumeElement(i).Volume(mesh.Points()) < 0)
	{
	  wrongels++;
	  mesh.VolumeElement(i).flags.badel = 1;
	}
      else
	mesh.VolumeElement(i).flags.badel = 0;

      
    if (wrongels)
      {
	cout << "WARNING: " << wrongels << " with wrong orientation found" << endl;

	int np = mesh.GetNP();
	ARRAY<Point3d> should(np);
	ARRAY<Point3d> can(np);
	for (i = 1; i <= np; i++)
	  {
	    should.Elem(i) = can.Elem(i) = mesh.Point(i);
	  }
	for (i = 1; i <= between.GetNBags(); i++)
	  for (j = 1; j <= between.GetBagSize(i); j++)
	    {
	      INDEX_2 parent;
	      int child;
	      between.GetData (i, j, parent, child);
	      can.Elem(child) = Center (can.Elem(parent.I1()),
					can.Elem(parent.I2()));
	    }

	BitArray boundp(np);
	boundp.Clear();
	for (i = 1; i <= mesh.GetNSE(); i++)
	  {
	    const Element2d & sel = mesh.SurfaceElement(i);
	    for (j = 1; j <= sel.GetNP(); j++)
	      boundp.Set(sel.PNum(j));
	  }


	double lam = 0.5;

	while (lam < 0.9 && cnttrials > 0)
	  {
	    lam = 2;
	    do
	      {
		lam *= 0.5;
		cnttrials--;

		cout << "lam = " << lam << endl;

		for (i = 1; i <= np; i++)
		  if (boundp.Test(i))
		    {
		      for (j = 1; j <= 3; j++)
			mesh.Point(i).X(j) = 
			  lam * should.Get(i).X(j) +
			  (1-lam) * can.Get(i).X(j);
		    }
		  else
		    mesh.Point(i) = can.Get(i);
	      

		BitArray free (mesh.GetNP()), fhelp(mesh.GetNP());
		free.Clear();
		for (i = 1; i <= mesh.GetNE(); i++)
		  {
		    const Element & el = mesh.VolumeElement(i);
		    if (el.Volume(mesh.Points()) < 0)
		      for (j = 1; j <= el.GetNP(); j++)
			free.Set (el.PNum(j));
		  }
		for (k = 1; k <= 3; k++)
		  {
		    fhelp.Clear();
		    for (i = 1; i <= mesh.GetNE(); i++)
		      {
			const Element & el = mesh.VolumeElement(i);
			int freeel = 0;
			for (j = 1; j <= el.GetNP(); j++)
			  if (free.Test(el.PNum(j)))
			    freeel = 1;
			if (freeel)
			  for (j = 1; j <= el.GetNP(); j++)
			    fhelp.Set (el.PNum(j));
		      }
		    free.Or (fhelp);
		  }

		(*testout) << "smooth points: " << endl;
		for (i = 1; i <= free.Size(); i++)
		  if (free.Test(i))
		    (*testout) << "p " << i << endl;

		(*testout) << "surf points: " << endl;
		for (i = 1; i <= mesh.GetNSE(); i++)
		  for (j = 1; j <= 3; j++)
		    (*testout) << mesh.SurfaceElement(i).PNum(j) << endl;
		  


		mesh.CalcSurfacesOfNode();
		free.Invert();
		mesh.FixPoints (free);
		mesh.ImproveMesh (OPT_REST);


		wrongels = 0;
		for (i = 1; i <= mesh.GetNE(); i++)
		  {
		    if (mesh.VolumeElement(i).Volume(mesh.Points()) < 0)
		      {
			wrongels++;
			mesh.VolumeElement(i).flags.badel = 1;
			(*testout) << "wrong el: ";
			for (j = 1; j <= 4; j++)
			  (*testout) << mesh.VolumeElement(i).PNum(j) << " ";
			(*testout) << endl;
		      }
		    else
		      mesh.VolumeElement(i).flags.badel = 0;
		  }
		cout << "wrongels = " << wrongels << endl;
	      }
	    while (wrongels && cnttrials > 0);
	  
	    for (i = 1; i <= np; i++)
	      can.Elem(i) = mesh.Point(i);
	  }
      }

    if (cnttrials <= 0)
      {
	cerr << "ERROR: Sorry, reverted elements" << endl;
      }
 
    mesh.ComputeNVertices();
    (*testout) << "refine done" << endl;

  }
}

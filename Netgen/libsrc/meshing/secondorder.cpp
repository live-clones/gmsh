#include <mystdlib.h>
#include "meshing.hpp"


namespace netgen
{



  Refinement :: Refinement ()
  {
    ;
  }

  Refinement :: ~Refinement ()
  {
    ;
  }
  
  void Refinement :: MakeSecondOrder (Mesh & mesh)
  {
    int i, j;
  
    INDEX_2_HASHTABLE<int> between(mesh.GetNP() + 5);

    int nseg, nse, ne;


    nseg = mesh.GetNSeg();
    for (i = 1; i <= nseg; i++)
      {
	Segment & el = mesh.LineSegment(i);
      
	INDEX_2 i2 (el.p1, el.p2);
	i2.Sort();
      
	int pnew;
	if (between.Used(i2))
	  pnew = between.Get(i2);
	else
	  {
	    Point3d pb;
	    EdgePointGeomInfo ngi;
	    PointBetween (mesh.Point (el.p1),
			  mesh.Point (el.p2), 0.5,
			  el.surfnr1, el.surfnr2,
			  el.epgeominfo[0], el.epgeominfo[1],
			  pb, ngi);
	  
	    pnew = mesh.AddPoint (pb);
	    between.Set (i2, pnew);
	  }
	el.pmid = pnew;
      }

    // refine surface elements
    nse = mesh.GetNSE();
    for (i = 1; i <= nse; i++)
      {
	int j;
	const Element2d & el = mesh.SurfaceElement(i);

	int onp = el.GetNP();
      
	Element2d newel;
	newel.SetIndex (el.GetIndex());

	static int betw_trig[3][3] =
	  { { 2, 3, 4 },
	    { 1, 3, 5 },
	    { 1, 2, 6 } };
	static int betw_quad6[2][3] =
	  { { 1, 2, 5 },
	    { 4, 3, 6 } };
	int (*betw)[3];
      
	switch (el.GetType())
	  {
	  case TRIG:
	  case TRIG6:
	    {
	      betw = betw_trig;
	      newel.SetType (TRIG6);
	      break;
	    }
	  case QUAD:
	  case QUAD6:
	  case QUAD8:
	    {
	      betw = betw_quad6;
	      newel.SetType (QUAD6);
	      break;
	    }
	  default:
	    PrintSysError ("Unhandled element in secondorder:", int(el.GetType()));
	  }

	for (j = 1; j <= onp; j++)
	  newel.PNum(j) = el.PNum(j);
      
	int nnp = newel.GetNP();
	for (j = 0; j < nnp-onp; j++)
	  {
	    int pi1 = newel.PNum(betw[j][0]);
	    int pi2 = newel.PNum(betw[j][1]);
	  
	    INDEX_2 i2 (pi1, pi2);
	    i2.Sort();
	  
	    if (between.Used(i2))
	      newel.PNum(onp+1+j) = between.Get(i2);
	    else
	      {
		Point3d pb;
		PointGeomInfo newgi;
		PointBetween (mesh.Point (pi1),
			      mesh.Point (pi2), 0.5, 
			      mesh.GetFaceDescriptor(el.GetIndex ()).SurfNr(),
			      el.GeomInfoPi (betw[j][0]),
			      el.GeomInfoPi (betw[j][1]),
			      pb, newgi);

		newel.PNum(onp+1+j) = mesh.AddPoint (pb);
		between.Set (i2, newel.PNum(onp+1+j));
	      }
	  }
      
	mesh.SurfaceElement(i) = newel;
      }

 


    // refine volume elements
    ne = mesh.GetNE();
    for (i = 1; i <= ne; i++)
      {
	int j;
	const Element & el = mesh.VolumeElement(i);

	if (el.GetType() != TET && el.GetType() != PRISM)
	  continue;

	int onp = el.GetNP();

	Element newel;
	newel.SetIndex (el.GetIndex());

	static int betw_tet[6][3] =
	  { { 1, 2, 5 },
	    { 1, 3, 6 },
	    { 1, 4, 7 },
	    { 2, 3, 8 },
	    { 2, 4, 9 },
	    { 3, 4, 10 } };
	static int betw_prism[6][3] =
	  {
	    { 1, 3, 7 },
	    { 1, 2, 8 },
	    { 2, 3, 9 },
	    { 4, 6, 10 },
	    { 4, 5, 11 },
	    { 5, 6, 12 },
	  };
	int (*betw)[3];

	switch (el.GetType())
	  {
	  case TET:
	  case TET10:
	    {
	      betw = betw_tet;
	      newel.SetType (TET10);
	      break;
	    }
	  case PRISM:
	  case PRISM12:
	    {
	      betw = betw_prism;
	      newel.SetType (PRISM12);
	      break;
	    }
	  default:
	    PrintSysError ("MakeSecondOrder, illegal vol type ", el.GetType());
	  }


	for (j = 1; j <= onp; j++)
	  newel.PNum(j) = el.PNum(j);
	int nnp = newel.GetNP();

	for (j = 0; j < nnp-onp; j++)
	  {
	    INDEX_2 i2(newel.PNum(betw[j][0]),
		       newel.PNum(betw[j][1]));
	    i2.Sort();
	  
	    if (between.Used(i2))
	      newel.PNum(onp+1+j) = between.Get(i2);
	    else
	      {
		newel.PNum(onp+1+j) = mesh.AddPoint
		  (Center (mesh.Point(i2.I1()),
			   mesh.Point(i2.I2())));
		between.Set (i2, newel.PNum(onp+1+j));
	      }
	  }

	mesh.VolumeElement (i) = newel;
      }

    /*
    // makes problems after linear mesh refinement, since
    // 2nd order identifications are not removed
    // update identification tables
    for (i = 1; i <= mesh.GetIdentifications().GetMaxNr(); i++)
    {
    ARRAY<int> identmap;
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
    */

    //  mesh.mglevels++;
    int oldsize = mesh.mlbetweennodes.Size();
    mesh.mlbetweennodes.SetSize(mesh.GetNP());
    for (i = oldsize+1; i <= mesh.GetNP(); i++)
      {
	mesh.mlbetweennodes.Elem(i).I1() = 0;
	mesh.mlbetweennodes.Elem(i).I2() = 0;
      }
    for (i = 1; i <= between.GetNBags(); i++)
      for (j = 1; j <= between.GetBagSize(i); j++)
	{
	  INDEX_2 oldp;
	  int newp;
	  between.GetData (i, j, oldp, newp);
	  mesh.mlbetweennodes.Elem(newp) = oldp;
	}

    mesh.ComputeNVertices();
  
    //  ValidateSecondOrder (mesh);
  }


  void Refinement :: ValidateSecondOrder (Mesh & mesh)
  {
    PrintMessage (3, "Validate mesh");
    int np = mesh.GetNP();
    int ne = mesh.GetNE();
    int i, j;
    ARRAY<INDEX_2> parents(np);
  
    for (i = 1; i <= np; i++)
      parents.Elem(i) = INDEX_2(0,0);

    for (i = 1; i <= ne; i++)
      {
	const Element & el = mesh.VolumeElement(i);
	if (el.GetType() == TET10)
	  {
	    static int betweentab[6][3] =
	      { { 1, 2, 5 },
		{ 1, 3, 6 },
		{ 1, 4, 7 },
		{ 2, 3, 8 },
		{ 2, 4, 9 },
		{ 3, 4, 10 } };
	    for (j = 0; j < 6; j++)
	      {
		int f1 = el.PNum (betweentab[j][0]);
		int f2 = el.PNum (betweentab[j][1]);
		int son = el.PNum (betweentab[j][2]);
		parents.Elem(son).I1() = f1;
		parents.Elem(son).I2() = f2;
	      }
	  }
      }

    ValidateRefinedMesh (mesh, parents);
  }


  void Refinement ::
  ValidateRefinedMesh (Mesh & mesh, 
		       ARRAY<INDEX_2> & parents)
  {
    int i, j, k;
  
    // homotopy method

    int ne = mesh.GetNE();

    int cnttrials = 100;
    int wrongels = 0;
    for (i = 1; i <= ne; i++)
      if (mesh.VolumeElement(i).CalcJacobianBadness (mesh.Points()) > 1e10)
	{
	  wrongels++;
	  mesh.VolumeElement(i).flags.badel = 1;
	}
      else
	mesh.VolumeElement(i).flags.badel = 0;

    double facok = 0;
    double factry;

    BitArray illegalels(ne);
    illegalels.Clear();

      
    if (wrongels)
      {
	cout << "WARNING: " << wrongels << " illegal element(s) found" << endl;

	int np = mesh.GetNP();
	ARRAY<Point3d> should(np);
	ARRAY<Point3d> can(np);

	for (i = 1; i <= np; i++)
	  {
	    should.Elem(i) = can.Elem(i) = mesh.Point(i);
	  }

	for (i = 1; i <= parents.Size(); i++)
	  {
	    if (parents.Get(i).I1())
	      can.Elem(i) = Center (can.Elem(parents.Get(i).I1()),
				    can.Elem(parents.Get(i).I2()));
	  }

	BitArray boundp(np);
	boundp.Clear();
	for (i = 1; i <= mesh.GetNSE(); i++)
	  {
	    const Element2d & sel = mesh.SurfaceElement(i);
	    for (j = 1; j <= sel.GetNP(); j++)
	      boundp.Set(sel.PNum(j));
	  }


	(*testout) << "bpoints:" << endl;
	for (i = 1; i <= np; i++)
	  if (boundp.Test(i))
	    (*testout) << i << endl;

	double lam = 0.5;

	while (facok < 1-1e-8 && cnttrials > 0)
	  {
	    lam *= 4;
	    if (lam > 2) lam = 2;

	    do
	      {
		//	      cout << "trials: " << cnttrials << endl;
		lam *= 0.5;
		cnttrials--;

		cout << "lam = " << lam << endl;

		factry = lam + (1-lam) * facok;
		cout << "trying: " << factry << endl;

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
	      
		//	      (*testout) << "bad els: " << endl;
		wrongels = 0;
		for (i = 1; i <= ne; i++)
		  {
		    if (!illegalels.Test(i) && 
			mesh.VolumeElement(i).
			CalcJacobianBadness(mesh.Points()) > 1e10)
		      {
			wrongels++;
			Element & el = mesh.VolumeElement(i);
			el.flags.badel = 1;
		     
		      
			if (lam < 1e-4)
			  illegalels.Set(i);
 

			/*
			  (*testout) << i << ": ";
			  for (j = 1; j <= el.GetNP(); j++)
			  (*testout) << el.PNum(j) << " ";
			  (*testout) << endl;
			*/
		      }
		    else
		      mesh.VolumeElement(i).flags.badel = 0;
		  }
		cout << "wrongels = " << wrongels << endl;
	      }
	    while (wrongels && cnttrials > 0);

	    mesh.CalcSurfacesOfNode();
	    mesh.ImproveMeshJacobian (OPT_WORSTCASE);	      
	  
	    facok = factry;
	    for (i = 1; i <= np; i++)
	      can.Elem(i) = mesh.Point(i);
	  }
      }


      
    for (i = 1; i <= ne; i++)
      {
	if (illegalels.Test(i))
	  {
	    cout << "illegal element: " << i << endl;
	    mesh.VolumeElement(i).flags.badel = 1;	
	  }
	else
	  mesh.VolumeElement(i).flags.badel = 0;	
      }
  
    /*
      if (cnttrials <= 0)
      {
      cerr << "ERROR: Sorry, illegal elements:" << endl;
      }
    */
  }

}

#include <mystdlib.h>
#include <meshing.hpp>
#include <csg.hpp>


/*
  Special Point calculation uses the global Flags:

  relydegtest       when to rely on degeneration ?
  calccp            calculate points of intersection ?
  cpeps1            eps for degenerated poi
  calcep            calculate points of extreme coordinates ?
  epeps1            eps for degenerated edge
  epeps2            eps for axis parallel pec
  epspointdist      eps for distance of special points 
*/


namespace netgen
{
  void ProjectToEdge (const Surface * f1, const Surface * f2, Point<3> & hp);



  SpecialPoint :: SpecialPoint (const SpecialPoint & sp)
  {
    p = sp.p;
    v = sp.v;
    s1 = sp.s1;
    s2 = sp.s2;
    layer = sp.layer;
    unconditional = sp.unconditional;
  }
  
  SpecialPoint & SpecialPoint :: operator= (const SpecialPoint & sp)
  {
    p = sp.p;
    v = sp.v;
    s1 = sp.s1;
    s2 = sp.s2;
    layer = sp.layer;
    unconditional = sp.unconditional;
    return *this;
  }


  void SpecialPoint :: Print (ostream & str)
  {
    str << "p = " << p << "   v = " << v 
	<< " s1/s2 = " << s1 << "/" << s2
	<< " layer = " << layer
	<< endl;
  }


  static ARRAY<int> numprim_hist;

  SpecialPointCalculation :: SpecialPointCalculation ()
  {
    ;  
  }

  void SpecialPointCalculation :: 
  CalcSpecialPoints (const CSGeometry & ageometry, 
		     ARRAY<MeshPoint> & apoints)
  {
    geometry = &ageometry;
    points = &apoints;

    size = geometry->MaxSize(); 
    (*testout) << "Find Special Points" << endl;
    (*testout) << "maxsize = " << size << endl;

    cpeps1 = 1e-6; 
    epeps1 = 1e-3; 
    epeps2 = 1e-6; 

    epspointdist2 = sqr (size * 1e-8); 
    relydegtest = size * 1e-4; 


    BoxSphere<3> box (Point<3> (-size, -size, -size),
		      Point<3> ( size,  size,  size));

    box.CalcDiamCenter();
    PrintMessage (3, "main-solids: ", geometry->GetNTopLevelObjects());

    numprim_hist.SetSize (geometry->GetNSurf()+1);
    numprim_hist = 0;

    for (int i = 0; i < geometry->GetNTopLevelObjects(); i++)
      {
	const TopLevelObject * tlo = geometry->GetTopLevelObject(i);

	(*testout) << "tlo " << i << ":" << endl
		   << *tlo->GetSolid() << endl;

	CalcSpecialPointsRec (tlo->GetSolid(), tlo->GetLayer(),
			      box, 1, 1, 1);
      }
  
    // add user point:
    for (int i = 0; i < geometry->GetNUserPoints(); i++)
      AddPoint (geometry->GetUserPoint(i), 1);

    PrintMessage (3, "Found points ", apoints.Size());

    for (int i = 0; i < boxesinlevel.Size(); i++)
      (*testout) << "level " << i << " has " 
		 << boxesinlevel[i] << " boxes" << endl;
    (*testout) << "numprim_histogramm = " << endl << numprim_hist << endl;
  }
  


  void SpecialPointCalculation :: 
  CalcSpecialPointsRec (const Solid * sol, int layer,
			const BoxSphere<3> & box, 
			int level, bool calccp, bool calcep)
  {
    if (multithread.terminate)
      throw NgException ("Meshing stopped");


    if (!sol) return;

    if (level >= 100)
      {
	MyStr err =
	  MyStr("Problems in CalcSpecialPoints\nPoint: ") + MyStr (box.Center());
	throw NgException (err.c_str());
      }


    bool decision;
    bool possiblecrossp, possibleexp;  // possible cross or extremalpoint
    bool surecrossp, sureexp;          // sure ...
  
    static ARRAY<int> locsurf;  // attention: array is static

    static int cntbox = 0;
    cntbox++;

    if (level <= boxesinlevel.Size())
      boxesinlevel.Elem(level)++;
    else
      boxesinlevel.Append (1);

    /*
      numprim = sol -> NumPrimitives();
      sol -> GetSurfaceIndices (locsurf);
    */

    geometry -> GetIndependentSurfaceIndices (sol, box, locsurf);
    int numprim = locsurf.Size();

    numprim_hist[numprim]++;

    Point<3> p = box.Center();


    possiblecrossp = (numprim >= 3) && calccp;
    surecrossp = 0;

    if (possiblecrossp && (locsurf.Size() <= 5 || level > 50))
      {
	decision = 1;
	surecrossp = 0;

	for (int k1 = 1; k1 <= locsurf.Size() - 2; k1++)
	  for (int k2 = k1 + 1; k2 <= locsurf.Size() - 1; k2++)
	    for (int k3 = k2 + 1; k3 <= locsurf.Size(); k3++)
	      {
		int nc, deg;
		nc = CrossPointNewtonConvergence 
		  (geometry->GetSurface(locsurf.Get(k1)), 
		   geometry->GetSurface(locsurf.Get(k2)), 
		   geometry->GetSurface(locsurf.Get(k3)), p );
	      
		deg = CrossPointDegenerated 
		  (geometry->GetSurface(locsurf.Get(k1)), 
		   geometry->GetSurface(locsurf.Get(k2)), 
		   geometry->GetSurface(locsurf.Get(k3)), box );
	      
		if (!nc && !deg) decision = 0;
		if (nc) surecrossp = 1;
	      }

	if (decision && surecrossp)
	  {
	    for (int k1 = 1; k1 <= locsurf.Size() - 2; k1++)
	      for (int k2 = k1 + 1; k2 <= locsurf.Size() - 1; k2++)
		for (int k3 = k2 + 1; k3 <= locsurf.Size(); k3++)
		  {
		    if (CrossPointNewtonConvergence 
			(geometry->GetSurface(locsurf.Get(k1)), 
			 geometry->GetSurface(locsurf.Get(k2)), 
			 geometry->GetSurface(locsurf.Get(k3)), p ) )
		      {
			Point<3> pp = p;
			CrossPointNewton 
			  (geometry->GetSurface(locsurf.Get(k1)), 
			   geometry->GetSurface(locsurf.Get(k2)), 
			   geometry->GetSurface(locsurf.Get(k3)), pp);
              
			BoxSphere<3> hbox (pp, pp);
			hbox.Increase (1e-8);

			if (pp(0) > box.PMin()(0) - 1e-5 && 
			    pp(0) < box.PMax()(0) + 1e-5 &&
			    pp(1) > box.PMin()(1) - 1e-5 && 
			    pp(1) < box.PMax()(1) + 1e-5 &&
			    pp(2) > box.PMin()(2) - 1e-5 && 
			    pp(2) < box.PMax()(2) + 1e-5 &&
			    sol -> IsIn (pp) && !sol->IsStrictIn (pp) &&
			    !CrossPointDegenerated
			    (geometry->GetSurface(locsurf.Get(k1)), 
			     geometry->GetSurface(locsurf.Get(k2)), 
			     geometry->GetSurface(locsurf.Get(k3)), hbox ))

			  { 
			    //                AddCrossPoint (locsurf, sol, p);
			    BoxSphere<3> boxp (pp, pp);
			    boxp.Increase (1e-3);
			    boxp.CalcDiamCenter();
			    ARRAY<int> locsurf2;

			    geometry -> GetIndependentSurfaceIndices (sol, boxp, locsurf2);
			  
			    bool found1 = 0, found2 = 0, found3 = 0;
			    for (int i = 0; i < locsurf2.Size(); i++)
			      {
				if (locsurf2[i] == locsurf.Get(k1)) found1 = 1;
				if (locsurf2[i] == locsurf.Get(k2)) found2 = 1;
				if (locsurf2[i] == locsurf.Get(k3)) found3 = 1;
			      }

			    if (found1 && found2 && found3)
			      if (AddPoint (pp, layer))
				{
				  (*testout) << "Crosspoint found: " << pp 
					     << " diam = " << box.Diam()
					     << ",  surfs: " 
					     << locsurf.Get(k1) << "," 
					     << locsurf.Get(k2) << "," 
					     << locsurf.Get(k3) << endl;
				}
			  }
		      }
		  }
	  }
      
	if (decision)
	  possiblecrossp = 0;
      }




    possibleexp = (numprim >= 2) && calcep;


    if (numprim == 2)
      {
	const Surface * surf1 = geometry->GetSurface(locsurf[0]);
	const Surface * surf2 = geometry->GetSurface(locsurf[1]);
	
	const Plane * plane1 = dynamic_cast<const Plane*> (surf1);
	const Plane * plane2 = dynamic_cast<const Plane*> (surf2);
	const QuadraticSurface * quadric1 = dynamic_cast<const QuadraticSurface*> (surf1);
	const QuadraticSurface * quadric2 = dynamic_cast<const QuadraticSurface*> (surf2);

	if (plane1 && plane2)
	  possibleexp = 0;
	else
	  {
	    ARRAY<Point<3> > pts;
	    if (plane1 && quadric2)
	      {
		ComputeExtremalPoints (plane1, quadric2, pts);
		possibleexp = 0;
	      }		
	    else if (plane2 && quadric1)
	      {
		ComputeExtremalPoints (plane2, quadric1, pts);
		possibleexp = 0;
	      }		

	    for (int j = 0; j < pts.Size(); j++)
	      if (Dist (pts[j], box.Center()) < box.Diam()/2 &&
		  sol -> IsIn (pts[j]) && !sol->IsStrictIn (pts[j]) )
		{
		  if (AddPoint (pts[j], layer))
		    (*testout) << "Extremal point found: " << pts[j] << endl;
		}  
	  }
      }

    
    if (possibleexp && (locsurf.Size() <= 5 || level >= 50))
      {
	decision = 1;
	sureexp = 0;

	/*
	(*testout) << "extremal surfs = ";
	for (int k5 = 0; k5 < locsurf.Size(); k5++)
	  (*testout) << typeid(*geometry->GetSurface(locsurf[k5])).name() << " ";
	(*testout) << "\n";
	*/

	for (int k1 = 0; k1 < locsurf.Size() - 1; k1++)
	  for (int k2 = k1+1; k2 < locsurf.Size(); k2++)
	    {
	      const Surface * surf1 = geometry->GetSurface(locsurf[k1]);
	      const Surface * surf2 = geometry->GetSurface(locsurf[k2]);
	      /*
	      (*testout) << "edgecheck, types = " << typeid(*surf1).name() << ", " << typeid(*surf2).name()
			 << "edge-newton-conv = " << EdgeNewtonConvergence (surf1, surf2, p)
			 << "edge-deg = " << EdgeDegenerated (surf1, surf2, box)
			 << "\n";
	      */
	      if (EdgeNewtonConvergence (surf1, surf2, p) ) 
		sureexp = 1;
	      else
		{
		  if (!EdgeDegenerated (surf1, surf2, box)) 
		    decision = 0;
		}
	    }

	if (decision && sureexp)
	  {
	    for (int k1 = 0; k1 < locsurf.Size() - 1; k1++)
	      for (int k2 = k1+1; k2 < locsurf.Size(); k2++)
		{
		  const Surface * surf1 = geometry->GetSurface(locsurf[k1]);
		  const Surface * surf2 = geometry->GetSurface(locsurf[k2]);

		  if (EdgeNewtonConvergence (surf1, surf2, p))
		    {
		      EdgeNewton (surf1, surf2, p);
		    
		      Point<3> pp;
		      if (IsEdgeExtremalPoint (surf1, surf2, p, pp, box.Diam()/2))
			{
			  (*testout) << "extremalpoint (nearly) found:" << pp << endl;

			  if (Dist (pp, box.Center()) < box.Diam()/2 &&
			      sol -> IsIn (pp) && !sol->IsStrictIn (pp) )
			    {
			      if (AddPoint (pp, layer))
				(*testout) << "Extremal point found: " << pp << endl;
			    }  
			}            
		    }
		}
	  }
	if (decision)
	  possibleexp = 0;
      }
 


    if (possiblecrossp || possibleexp)
      {
	BoxSphere<3> sbox;
	for (int i = 0; i < 8; i++)
	  {
	    box.GetSubBox (i, sbox);
	    sbox.Increase (1e-4 * sbox.Diam());

	    Solid * redsol = sol -> GetReducedSolid (sbox);

	    if (redsol)
	      {
		CalcSpecialPointsRec (redsol, layer, sbox, level+1, calccp, calcep);
		delete redsol;
	      }
	  }
      }
  }





  /******* Tests for Point of intersection **********************/



  bool SpecialPointCalculation :: 
  CrossPointNewtonConvergence (const Surface * f1, 
			       const Surface * f2, 
			       const Surface * f3,
			       const Point<3> & p)
  {
    Vec<3> grad, rs, x;
    Mat<3> jacobi, inv;

    f1->CalcGradient (p, grad);
    jacobi(0,0) = grad(0);
    jacobi(0,1) = grad(1);
    jacobi(0,2) = grad(2);

    f2->CalcGradient (p, grad);
    jacobi(1,0) = grad(0);
    jacobi(1,1) = grad(1);
    jacobi(1,2) = grad(2);

    f3->CalcGradient (p, grad);
    jacobi(2,0) = grad(0);
    jacobi(2,1) = grad(1);
    jacobi(2,2) = grad(2);

    if (fabs (Det (jacobi)) > 1e-8)
      {
	double gamma = f1 -> HesseNorm() + f2 -> HesseNorm() + f3 -> HesseNorm();
	if (gamma == 0.0) return 1;

	CalcInverse (jacobi, inv);

	rs(0) = f1->CalcFunctionValue (p);
	rs(1) = f2->CalcFunctionValue (p);
	rs(2) = f3->CalcFunctionValue (p);

	x = inv * rs;

	double beta = 0;
	for (int i = 0; i < 3; i++)
	  {
	    double sum = 0;
	    for (int j = 0; j < 3; j++)
	      sum += fabs (inv(i,j));
	    if (sum > beta)  beta = sum;
	  }
	double eta = Abs (x);

	return (beta * gamma * eta < 0.1);
      }
    return 0;

  }




  bool SpecialPointCalculation :: 
  CrossPointDegenerated (const Surface * f1,
			 const Surface * f2, 
			 const Surface * f3, 
			 const BoxSphere<3> & box) const
  {
    Mat<3> mat;
    Vec<3> g1, g2, g3;
    double normprod;

    if (box.Diam() > relydegtest) return 0;

    f1->CalcGradient (box.Center(), g1);
    normprod = Abs2 (g1);

    f2->CalcGradient (box.Center(), g2);
    normprod *= Abs2 (g2);
 
    f3->CalcGradient (box.Center(), g3);
    normprod *= Abs2 (g3);

    for (int i = 0; i < 3; i++)
      {
	mat(i,0) = g1(i);
	mat(i,1) = g2(i);
	mat(i,2) = g3(i);
      }

    return sqr (Det (mat)) < sqr(cpeps1) * normprod;
  }
 




  void SpecialPointCalculation :: CrossPointNewton (const Surface * f1, 
						    const Surface * f2, 
						    const Surface * f3, Point<3> & p)
  {
    Vec<3> g1, g2, g3;
    Vec<3> rs, sol;
    Mat<3> mat;

    int i = 10;
    while (i > 0)
      {
	i--;
	rs(0) = f1->CalcFunctionValue (p);
	rs(1) = f2->CalcFunctionValue (p);
	rs(2) = f3->CalcFunctionValue (p);

	f1->CalcGradient (p, g1);
	f2->CalcGradient (p, g2);
	f3->CalcGradient (p, g3);

	for (int j = 0; j < 3; j++)
	  {
	    mat(0, j) = g1(j);
	    mat(1, j) = g2(j);
	    mat(2, j) = g3(j);
	  }
	mat.Solve (rs, sol);
	if (sol.Length2() < 1e-24 && i > 1) i = 1;

	p -= sol;
      }
  }




  /******* Tests for Point on edges **********************/




  bool SpecialPointCalculation :: 
  EdgeNewtonConvergence (const Surface * f1, const Surface * f2, 
			 const Point<3> & p)
  {
    Vec<3> g1, g2, sol;
    Vec<2> vrs;
    Mat<2,3> mat;
    Mat<3,2> inv;

    f1->CalcGradient (p, g1);
    f2->CalcGradient (p, g2);

    if ( sqr(g1 * g2) < (1 - 1e-8) * Abs2 (g1) * Abs2 (g2))
      {
	double gamma = f1 -> HesseNorm() + f2 -> HesseNorm();
	if (gamma < 1e-32) return 1;
	gamma = sqr (gamma);
      
	for (int i = 0; i < 3; i++)
	  {
	    mat(0,i) = g1(i);
	    mat(1,i) = g2(i);
	  }

	CalcInverse (mat, inv);

	vrs(0) = f1->CalcFunctionValue (p);
	vrs(1) = f2->CalcFunctionValue (p);
	sol = inv * vrs;

	double beta = 0;
	for (int i = 0; i < 3; i++)
	  for (int j = 0; j < 2; j++)
	    beta += inv(i,j) * inv(i,j);
	// beta = sqrt (beta);

	double eta = Abs2 (sol);

	// alpha = beta * gamma * eta;
	return (beta * gamma * eta < 0.01);
      }
    return 0;
  }




  bool SpecialPointCalculation :: 
  EdgeDegenerated (const Surface * f1,
		   const Surface * f2, 
		   const BoxSphere<3> & box) const
  {
    // perform newton steps. normals parallel ?
    // if not decideable: return 0 
  
    Point<3> p = box.Center();
    Vec<3> g1, g2, sol;
    Vec<2> vrs;
    Mat<2,3> mat;

    int i = 20;
    while (i > 0)
      {
	if (Dist2 (p, box.Center()) > sqr(box.Diam()))
	  return 0;

	i--;
	vrs(0) = f1->CalcFunctionValue (p);
	vrs(1) = f2->CalcFunctionValue (p);

	f1->CalcGradient (p, g1);
	f2->CalcGradient (p, g2);

	if ( sqr (g1 * g2) > (1 - 1e-10) * Abs2 (g1) * Abs2 (g2))
	  return 1;

	for (int j = 0; j < 3; j++)
	  {
	    mat(0,j) = g1(j);
	    mat(1,j) = g2(j);
	  }
	mat.Solve (vrs, sol);

	if (Abs2 (sol) < 1e-24 && i > 1) i = 1;
	p -= sol;
      }

    return 0;
  }






  void SpecialPointCalculation :: EdgeNewton (const Surface * f1, 
					      const Surface * f2, Point<3> & p)
  {
    Vec<3> g1, g2, sol;
    Vec<2> vrs;
    Mat<2,3> mat;

    int i = 10;
    while (i > 0)
      {
	i--;
	vrs(0) = f1->CalcFunctionValue (p);
	vrs(1) = f2->CalcFunctionValue (p);

	f1->CalcGradient (p, g1);
	f2->CalcGradient (p, g2);

	for (int j = 0; j < 3; j++)
	  {
	    mat(0,j) = g1(j);
	    mat(1,j) = g2(j);
	  }
	mat.Solve (vrs, sol);

	if (Abs2 (sol) < 1e-24 && i > 1) i = 1;
	p -= sol;
      }
  }



  bool SpecialPointCalculation :: 
  IsEdgeExtremalPoint (const Surface * f1, const Surface * f2, 
		       const Point<3> & p, Point<3> & pp, double rad)
  {
    Vec<3> g1, g2, t, t1, t2;

    f1->CalcGradient (p, g1);
    f2->CalcGradient (p, g2);
  
    t = Cross (g1, g2);
    t.Normalize();

    Point<3> p1 = p + rad * t;
    Point<3> p2 = p - rad * t;

    EdgeNewton (f1, f2, p1);
    EdgeNewton (f1, f2, p2);
  
    f1->CalcGradient (p1, g1);
    f2->CalcGradient (p1, g2);
    t1 = Cross (g1, g2);
    t1.Normalize();

    f1->CalcGradient (p2, g1);
    f2->CalcGradient (p2, g2);
    t2 = Cross (g1, g2);
    t2.Normalize();

    double val = 1e-8 * rad * rad;
    for (int j = 0; j < 3; j++)
      if ( (t1(j) * t2(j) < -val) )
	{
	  pp = p;
	  ExtremalPointNewton (f1, f2, j+1, pp);
	  return 1;
	}

    return 0;
  }









  /********** Tests of Points of extremal coordinates  ****************/


  void SpecialPointCalculation :: ExtremalPointNewton (const Surface * f1, 
						       const Surface * f2, 
						       int dir, Point<3> & p)
  {
    Vec<3> g1, g2, v, curv;
    Vec<3> rs, x, y1, y2, y;
    Mat<3> h1, h2;
    Mat<3> jacobi;

    int i = 50;
    while (i > 0)
      {
	i--;
	rs(0) = f1->CalcFunctionValue (p);
	rs(1) = f2->CalcFunctionValue (p);

	f1 -> CalcGradient (p, g1);
	f2 -> CalcGradient (p, g2);

	f1 -> CalcHesse (p, h1);
	f2 -> CalcHesse (p, h2);

	v = Cross (g1, g2);

	rs(2) = v(dir-1);

	jacobi(0,0) = g1(0);
	jacobi(0,1) = g1(1);
	jacobi(0,2) = g1(2);

	jacobi(1,0) = g2(0);
	jacobi(1,1) = g2(1);
	jacobi(1,2) = g2(2);


	switch (dir)
	  {
	  case 1:
	    {
	      y1(0) = 0;
	      y1(1) = g2(2);
	      y1(2) = -g2(1);
	      y2(0) = 0;
	      y2(1) = -g1(2);
	      y2(2) = g1(1);
	      break;
	    }
	  case 2:
	    {
	      y1(0) = -g2(2);
	      y1(1) = 0;
	      y1(2) = g2(0);
	      y2(0) = g1(2);
	      y2(1) = 0;
	      y2(2) = -g1(0);
	      break;
	    }
	  case 3:
	    {
	      y1(0) = g2(1);
	      y1(1) = -g2(0);
	      y1(2) = 0;
	      y2(0) = -g1(1);
	      y2(1) = g1(0);
	      y2(2) = 0;
	      break;
	    }
	  }

	y = h1 * y1 + h2 * y2;

	jacobi(2,0) = y(0);
	jacobi(2,1) = y(1);
	jacobi(2,2) = y(2);

	jacobi.Solve (rs, x);

	if (Abs2 (x) < 1e-24 && i > 1)
	  {
	    i = 1;
	  }
      
	p -= x;
      }


    if (Abs2 (x) > 1e-20)
      {
	(*testout) << "Error: extremum Newton not convergent" << endl;
	(*testout) << "dir = " << dir << endl;
	(*testout) << "p = " << p << endl;
	(*testout) << "x = " << x << endl;
      }
  }



  void SpecialPointCalculation :: 
  ComputeExtremalPoints (const Plane * plane, 
			 const QuadraticSurface * quadric, 
			 ARRAY<Point<3> > & pts)
  {
    // 3 equations:
    // surf1 = 0  <===> plane_a + plane_b x = 0;
    // surf2 = 0  <===> quad_a + quad_b x + x^T quad_c x = 0
    // (grad 1 x grad 2)(i) = 0  <====> (grad 1 x e_i) . grad_2 = 0

    pts.SetSize (0);

    Point<3> p0(0,0,0);
    double plane_a, quad_a;
    Vec<3> plane_b, quad_b, ei;
    Mat<3> quad_c;

    plane_a = plane -> CalcFunctionValue(p0);
    plane -> CalcGradient (p0, plane_b);

    quad_a = quadric -> CalcFunctionValue(p0);
    quadric -> CalcGradient (p0, quad_b);
    quadric -> CalcHesse (p0, quad_c);
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
	quad_c(i,j) *= 0.5;

    for (int dir = 0; dir <= 2; dir++)
      {
	ei = 0.0; ei(dir) = 1;
	Vec<3> v1 = Cross (plane_b, ei);
	
	// grad_2 . v1 ... linear:
	double g2v1_c = v1 * quad_b;
	Vec<3> g2v1_l = 2.0 * (quad_c * v1);

	// find line of two linear equations:
	
	Vec<2> rhs;
	Vec<3> sol;
	Mat<2,3> mat;

	for (int j = 0; j < 3; j++)
	  {
	    mat(0,j) = plane_b(j);
	    mat(1,j) = g2v1_l(j);
	  }
	rhs(0) = -plane_a;
	rhs(1) = -g2v1_c;

	Vec<3> t = Cross (plane_b, g2v1_l);
	if (Abs2(t) > 0)
	  {
	    mat.Solve (rhs, sol);
	    
	    // solve quadratic equation along line  sol + alpha t ....
	    double a = quad_a + quad_b * sol + sol * (quad_c * sol);
	    double b = quad_b * t + 2 * (sol * (quad_c * t));
	    double c = t * (quad_c * t);

	    // solve a + b alpha + c alpha^2:

	    if (fabs (c) > 1e-32)
	      {
		double disc = sqr (0.5*b/c) - a/c;
		if (disc > 0)
		  {
		    disc = sqrt (disc);
		    double alpha1 = -0.5*b/c + disc;
		    double alpha2 = -0.5*b/c - disc;

		    pts.Append (Point<3> (sol+alpha1*t));
		    pts.Append (Point<3> (sol+alpha2*t));
		    /*
		    cout << "sol1 = " << sol + alpha1 * t
			 << ", sol2 = " << sol + alpha2 * t << endl;
		    */
		  }
	      }
	  }
      }
  }






  /*
    bool SpecialPointCalculation :: ExtremalPointPossible (const Surface * f1, 
    const Surface * f2, 
    int dir, 
    const BoxSphere<3> & box)
    {
    double hn1, hn2, gn1, gn2;
    Point<3> p;
    Vec<3> g1, g2, v;
    double f3;
    double r = box.Diam()/2;

    p = box.Center();

    f1 -> CalcGradient (p, g1);
    f2 -> CalcGradient (p, g2);

    gn1 = g1.Length();
    gn2 = g2.Length();

    hn1 = f1 -> HesseNorm ();
    hn2 = f2 -> HesseNorm ();

    v = Cross (g1, g2);
    f3 = fabs (v(dir-1));

    //  (*testout) << "f3 = " << f3 << "  r = " << r 
    //             << "normbound = " 
    //             << (hn1 * (gn2 + r * hn2) + hn2 * (gn1 + r * hn1)) << endl;
 
    return (f3 <= 3 * r * (hn1 * (gn2 + r * hn2) + hn2 * (gn1 + r * hn1)));
    }



    bool SpecialPointCalculation :: 
    ExtremalPointNewtonConvergence (const Surface * f1, const Surface * f2, 
    int dir, 
    const BoxSphere<3> & box)
    {
    return box.Diam() < 1e-8;
    }


    bool SpecialPointCalculation :: 
    ExtremalPointDegenerated (const Surface * f1, const Surface * f2, 
    int dir, const BoxSphere<3> & box)
    {
    double gn1, gn2;
    Point<3> p;
    Vec<3> g1, g2, v;
    double maxderiv;
    double minv;
    Vec<3> curv, t;
    Vec<2> rs, x;
    Mat<3> h1, h2;
    Mat<2> a, inv;
    double leftside;

    if (box.Diam() > relydegtest) return 0;

    p = box.Center();

    f1 -> CalcGradient (p, g1);
    f2 -> CalcGradient (p, g2);
    gn1 = g1.Length();
    gn2 = g2.Length();

    v = Cross (g1, g2);
    if (Abs (v) < epeps1 * gn1 * gn2) return 1;       // irregular edge

    f1 -> CalcHesse (p, h1);
    f2 -> CalcHesse (p, h2);

    //  hn1 = f1 -> HesseNorm ();
    //  hn2 = f2 -> HesseNorm ();

    t = v;
    a(0, 0) = g1 * g1;
    a(0, 1) = 
    a(1, 0) = g1 * g2;
    a(1, 1) = g2 * g2;
  
    rs(0) = g1(dir-1);
    rs(1) = g2(dir-1);

    a.Solve (rs, x);

    //  (*testout) << "g1 = " << g1 << " g2 = " << g2 << endl;
    //  (*testout) << "lam = " << x << endl;
    //  (*testout) << "h2 = " << h2 << endl;

    leftside = fabs (x(0) * ( t * (h1 * t)) + 
    x(1) * ( t * (h2 * t)));

    //  (*testout) << "leftside = " << leftside << endl;

    if (leftside < epeps2 * Abs2 (v)) return 1;  

    return 0;
    }
  */
 

  bool SpecialPointCalculation :: AddPoint (const Point<3> & p, int layer)
  {
    for (int i = 0; i < points->Size(); i++)
      if (Dist2 ( (*points)[i], p) < epspointdist2 &&
	  (*points)[i].GetLayer() == layer)
	return 0;

    points->Append (MeshPoint(p, layer));
    PrintMessageCR (3, "Found points ", points->Size());
    return 1;
  }







  void SpecialPointCalculation :: 
  AnalyzeSpecialPoints (const CSGeometry & ageometry,
			ARRAY<MeshPoint> & apoints, 
			ARRAY<SpecialPoint> & specpoints)
  {
    ARRAY<int> surfind;
    ARRAY<int> surfind2;

    ARRAY<Vec<3> > normalvecs;
    Vec<3> t, nsurf;
    Point<3> p;

    ARRAY<int> specpoint2point;
    specpoints.SetSize (0);

    geometry = &ageometry;
 
    (*testout) << "AnalyzeSpecialPoints\n";


    Box<3> bbox;
    if (apoints.Size())
      bbox.Set (apoints[0]);
    else
      { bbox.Set (Point<3> (0,0,0)); bbox.Add (Point<3> (1,1,1)); }
    for (int i = 1; i < apoints.Size(); i++)
      bbox.Add (apoints[i]);
    bbox.Increase (0.1 * Dist (bbox.PMin(), bbox.PMax()));

    Point3dTree searchtree (bbox.PMin(), bbox.PMax());
    ARRAY<int> locsearch;

    for (int si = 0; si < ageometry.GetNTopLevelObjects(); si++)
      {
	//      (*testout) << "main solid " << si << "\n";
	
	const Solid * sol = ageometry.GetTopLevelObject(si)->GetSolid();
	const Surface * surf = ageometry.GetTopLevelObject(si)->GetSurface();

	for (int i = 0; i < apoints.Size(); i++)
	  {
	    p = apoints[i];
	    if (ageometry.GetTopLevelObject(si)->GetLayer() !=
		apoints[i].GetLayer())
	      continue;

	    //	  (*testout) << "Point " << apoints[i] << "\n";

	    Solid * locsol;
	    sol -> TangentialSolid (p, locsol);
	    if (!locsol) continue;
	  
	    // get all surface indices, 
	    if (surf)
	      {
		locsol -> GetSurfaceIndices (surfind);
		bool hassurf = 0;
		for (int m = 0; m < surfind.Size(); m++)
		  if (ageometry.GetSurface(surfind[m]) == surf)
		    hassurf = 1;

		if (!hassurf)
		  continue;

		nsurf = surf->GetNormalVector (p);
	      }

	    // get independent surfaces of tangential solid

	    BoxSphere<3> box(p,p);
	    box.Increase (1e-6);
	    box.CalcDiamCenter();
	    ageometry.GetIndependentSurfaceIndices (locsol, box, surfind);

	    normalvecs.SetSize(surfind.Size());
	    for (int j = 0; j < surfind.Size(); j++)
	      normalvecs[j] = 
		ageometry.GetSurface(surfind[j]) -> GetNormalVector(apoints[i]);

	    for (int j = 0; j < normalvecs.Size(); j++)
	      for (int k = j+1; k < normalvecs.Size(); k++)
		for (int l = 1; l <= 2; l++)
		  {
		    t = Cross (normalvecs[j], normalvecs[k]);
		    if (Abs2 (t) < 1e-8)
		      {
			cerr << "AnalyzePoint: Surfaces degenerated" << "\n";
			break;
		      }
		    t.Normalize();
		    if (l == 2) t *= -1;

		    // try tangential direction t

		    // (*testout) << "check tangential " << t << "\n";

		    if (surf && fabs (nsurf * t) > 1e-6)
		      continue;

		    if (!surf)
		      {
			ageometry.GetIndependentSurfaceIndices 
			  (locsol, p, t, surfind2);
		  
			bool found1 = 0, found2 = 0;
			for (int ii = 0; ii < surfind2.Size(); ii++)
			  {
			    if (surfind2[ii] == surfind[j])
			      found1 = 1;
			    if (surfind2[ii] == surfind[k])
			      found2 = 1;
			  }
			if (!found1 || !found2)
			  continue;
		      }


		    bool isedge;

		    // isedge = locsol -> Edge (apoints.Get(i), t);
		  
		    // edge must be on tangential surface
		    isedge = 
		      locsol->VectorIn (p, t) &&
		      !locsol->VectorStrictIn (p, t);
		  
		    // (*testout) << "isedge,1 = " << isedge << "\n";

		    // there must exist at least two different faces on edge
		    if (isedge)
		      {
			int cnts = 0;
			for (int m = 0; m < surfind.Size(); m++)
			  {
			    if (fabs (normalvecs[m] * t) > 1e-6)
			      continue;

			    Vec<3> s = Cross (normalvecs[m], t);
			    Vec<3> t2a = t + 0.01 *s;
			    Vec<3> t2b = t - 0.01 *s;

			    /*
			      (*testout) << "nv = " << normalvecs[m] << ", s = " << s << "\n";
			      (*testout) << "t2a = " << t2a << ", t2b = " << t2b << "\n";
			      (*testout) << "via = "
			      << locsol->VectorIn (p, t2a) << "/"
			      << locsol->VectorStrictIn (p, t2a);
			      (*testout) << "vib = "
			      << locsol->VectorIn (p, t2b) << "/"
			      << locsol->VectorStrictIn (p, t2b) << "\n";
			    */

			    bool isface =
			      (locsol->VectorIn (p, t2a) &&
			       !locsol->VectorStrictIn (p, t2a))
			      ||
			      (locsol->VectorIn (p, t2b) &&
			       !locsol->VectorStrictIn (p, t2b));
			  
			    if (isface)
			      {
				cnts++;
			      }
			  }
			if (cnts < 2) isedge = 0;
		      }

		    if (isedge)
		      {
			int spi = -1;

			searchtree.GetIntersecting (apoints[i]-Vec3d(1e-4,1e-4,1e-4), 
						    apoints[i]+Vec3d(1e-4,1e-4,1e-4), 
						    locsearch);

			for (int m = 0; m < locsearch.Size(); m++)
			  if (Dist2 (specpoints[locsearch[m]].p, apoints[i]) < 1e-8
			      && Abs2(specpoints[locsearch[m]].v - t) < 1e-8)
			    {
			      spi = locsearch[m];
			      break;
			    }


			if (spi == -1)
			  {
			    spi = specpoints.Append (SpecialPoint()) - 1;
			    specpoint2point.Append (i);
			    specpoints.Last().unconditional = 0;
			    searchtree.Insert (apoints[i], spi);
			  }

			specpoints[spi].p = apoints[i];
			specpoints[spi].v = t;
			if (surfind.Size() >= 3)
			  specpoints[spi].unconditional = 1;
			specpoints[spi].s1 = surfind[j];
			specpoints[spi].s2 = surfind[k];
			specpoints[spi].layer = apoints[i].GetLayer();
			for (int up = 0; up < geometry->GetNUserPoints(); up++)
			  if (Dist (geometry->GetUserPoint(up), apoints[i]) < 1e-10)
			    specpoints[spi].unconditional = 1;
		      }
          
		  }
	    delete locsol;
	  }
      }

    // if special point is unconditional on some solid,
    // it must be unconditional everywhere:

    BitArray uncond (apoints.Size());
    uncond.Clear();

    for (int i = 0; i < specpoints.Size(); i++)
      if (specpoints[i].unconditional)
	uncond.Set (specpoint2point[i]);
  
    for (int i = 0; i < specpoints.Size(); i++)
      specpoints[i].unconditional = 
	uncond.Test (specpoint2point[i]) ? 1 : 0;
  }
}

#include <mystdlib.h>
#include <meshing.hpp>
#include <csg.hpp>


/*

   Special Point calculation uses the global Flags:


   size .. 500       cube = [-size, size]^3
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



  /*
SpecialPoint :: SpecialPoint ()
  : p(), v(), layer(0)
{
  ;
}
  */


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

bool SpecialPoint :: HasSurfaces (int as1, int as2) const
{
  return (s1 == as1 && s2 == as2 || s1 == as2 && s2 == as1);
}

void SpecialPoint :: Print (ostream & str)
{
  str << "p = " << p << "   v = " << v 
      << " s1/s2 = " << s1 << "/" << s2
      << " layer = " << layer
      << endl;
}




SpecialPointCalculation :: SpecialPointCalculation ()
{
  ;  
}

void SpecialPointCalculation :: 
CalcSpecialPoints (const CSGeometry & ageometry, 
		   ARRAY<MeshPoint> & apoints)
{
  int i;

  geometry = &ageometry;
  points = &apoints;

  size = geometry->MaxSize();  // globflags.GetNumFlag ("maxsize", 500);
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

  for (i = 0; i < geometry->GetNTopLevelObjects(); i++)
    {
      (*testout) << "tlo " << i << ":" << endl;
      const TopLevelObject * tlo = geometry->GetTopLevelObject(i);
      tlo->GetSolid()->Print (*testout); 
      (*testout) << endl;
      CalcSpecialPointsRec (tlo->GetSolid(), tlo->GetLayer(),
			    box, 1, 1, 1);
    }
  
  PrintDot ('\n');


  // add user point:
  int found = 0;
  for (i = 0; i < geometry->GetNUserPoints(); i++)
    AddPoint (geometry->GetUserPoint(i), 1);
  
  PrintMessage (3, apoints.Size(), " special points");

  for (i = 0; i < boxesinlevel.Size(); i++)
    (*testout) << "level " << i << " has " 
	       << boxesinlevel[i] << " boxes" << endl;
}



int debug;
void SpecialPointCalculation :: 
CalcSpecialPointsRec (const Solid * sol, int layer,
		      const BoxSphere<3> & box, 
		      int level, bool calccp, bool calcep)
{
  if (multithread.terminate)
    return;

  int i;
  BoxSphere<3> sbox;
  Solid * redsol;

  int numprim;

  bool decision;
  bool possiblecrossp, possibleexp;  // possible cross or extremalpoint
  bool surecrossp, sureexp;          // sure ...
  
  static ARRAY<int> locsurf;  // attention: array is static


  Point<3> p;
  int k1, k2, k3;
  int extremdir;
  double hd;

  if (!sol) return;


  if (level >= 100)
    {
      cerr << "Problems in CalcSpecialPoints" << endl;
      cerr << "Point: " << box.Center() << endl;
      exit (1);
    }

  static int cntbox = 0;
  cntbox++;
  if (cntbox % 10000 == 0) 
    PrintDot ();

  if (level <= boxesinlevel.Size())
    boxesinlevel.Elem(level)++;
  else
    boxesinlevel.Append (1);

  /*
  numprim = sol -> NumPrimitives();
  sol -> GetSurfaceIndices (locsurf);
  */

  debug = 0;
  // box.IsIn (Point<3> (4.9, 1.279, 2.8));


  geometry -> GetIndependentSurfaceIndices (sol, box, locsurf);
  numprim = locsurf.Size();
  
  if (debug)
    {
      (*testout) << "box = " << box.PMin() << "-" << box.PMax()
		 << " np = " << numprim << " : ";
      for (i = 1; i <= locsurf.Size(); i++)
	(*testout) << " " << locsurf.Get(i);
      (*testout) << " diam = " << box.Diam();
      (*testout) << " numprim = " << numprim;
      (*testout) << endl;
    }

  p = box.Center();
  
  /*
  (*testout) << "box = " << box.PMin() << " - " << box.PMax()
	     << ", lev = " << level 
	     << ", nprim = " << sol->NumPrimitives() 
	     << ", lsurf = " << locsurf.Size() << endl;

  for (i = 1; i <= locsurf.Size(); i++)
    geometry->GetSurface (locsurf.Get(i)) -> Print (*testout);
  sol -> Print (*testout);
  */

  /*
    for (i = 1; i <= locsurf.Size(); i++)
    (*testout) << locsurf.Get(i) << " ";
    (*testout) << "C = " << box.Center() << " diam = " << box.Diam() << endl;
    */

  possiblecrossp = (numprim >= 3) && calccp;
  surecrossp = 0;

  if (possiblecrossp && (locsurf.Size() <= 10))
    {
      decision = 1;
      surecrossp = 0;

      for (k1 = 1; k1 <= locsurf.Size() - 2; k1++)
	for (k2 = k1 + 1; k2 <= locsurf.Size() - 1; k2++)
	  for (k3 = k2 + 1; k3 <= locsurf.Size(); k3++)
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
	  for (k1 = 1; k1 <= locsurf.Size() - 2; k1++)
	    for (k2 = k1 + 1; k2 <= locsurf.Size() - 1; k2++)
	      for (k3 = k2 + 1; k3 <= locsurf.Size(); k3++)
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
			  
			  /*
			  ReducePrimitiveIterator rpi(boxp);
			  UnReducePrimitiveIterator urpi;
			  
			  ((Solid*)sol) -> IterateSolid (rpi);
			  sol -> GetIndependentSurfaceIndices (locsurf2);
			  ((Solid*)sol) -> IterateSolid (urpi);
			  */
			  bool found1 = 0, found2 = 0, found3 = 0;
			  for (i = 1; i <= locsurf2.Size(); i++)
			    {
			      if (locsurf2.Get(i) == locsurf.Get(k1))
				found1 = 1;
			      if (locsurf2.Get(i) == locsurf.Get(k2))
				found2 = 1;
			      if (locsurf2.Get(i) == locsurf.Get(k3))
				found3 = 1;
			    }
			  
			  if (found1 && found2 && found3)
			    if (AddPoint (pp, layer))
			      {
				(*testout) << "Crosspoint found: " << pp 
					   << " diam = " << box.Diam() << endl;
				(*testout) << "surfs: " 
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
    
  if (possibleexp && (locsurf.Size() <= 10))
    {
      decision = 1;
      sureexp = 0;

      for (k1 = 1; k1 <= locsurf.Size() - 1; k1++)
	for (k2 = k1+1; k2 <= locsurf.Size(); k2++)
	  {
	    bool nc, deg;
	    
	    nc = EdgeNewtonConvergence 
	      (geometry->GetSurface(locsurf.Get(k1)),
	       geometry->GetSurface(locsurf.Get(k2)),
	       p);
	    
	    deg = EdgeDegenerated 
	      (geometry->GetSurface(locsurf.Get(k1)),
	       geometry->GetSurface(locsurf.Get(k2)),
	       box);
	    
	    if (!nc && !deg) decision = 0;
	    if (nc) sureexp = 1;

	    if (debug)
	      {
		(*testout) << "p = " << p << " s1,2 = " << locsurf.Get(k1) << ", " << locsurf.Get(k2) 
			   << " nc = " << nc << " deg = " << deg << endl;
	      }
	  }

      if (decision && sureexp)
	{
	  for (k1 = 1; k1 <= locsurf.Size() - 1; k1++)
	    for (k2 = k1+1; k2 <= locsurf.Size(); k2++)
	      {
		if (
		    EdgeNewtonConvergence 
		    (geometry->GetSurface(locsurf.Get(k1)),
		     geometry->GetSurface(locsurf.Get(k2)),
		     p) )
		  {
		    EdgeNewton 
		      (geometry->GetSurface(locsurf.Get(k1)),
		       geometry->GetSurface(locsurf.Get(k2)),
		       p);
		    
		    Point<3> pp;
		    if (IsEdgeExtremalPoint 
		      (geometry->GetSurface(locsurf.Get(k1)),
		       geometry->GetSurface(locsurf.Get(k2)),
		       p, pp, box.Diam()/2))
			{
			  (*testout) << "extremalpoint (nearly) found:" 
				     << pp
				     << endl;
			  if (Dist (pp, box.Center()) < box.Diam()/2 &&
			      sol -> IsIn (pp) && !sol->IsStrictIn (pp) )
			    {
			      //                AddExtremalPoint (locsurf.Get(k1), locsurf.Get(k2), p);
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
      for (i = 0; i < 8; i++)
	{
	  box.GetSubBox (i, sbox);
	  sbox.Increase (1e-4 * sbox.Diam());

	  redsol = sol -> GetReducedSolid (sbox);

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
  int i;
  Vec<3> grad;
  Vec<3> rs, x;
  Mat<3> jacobi, inv;
  double alpha, beta, gamma, eta;
  double sum;
  int j;


  rs(0) = f1->CalcFunctionValue (p);
  rs(1) = f2->CalcFunctionValue (p);
  rs(2) = f3->CalcFunctionValue (p);

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

  alpha = 1;
  if (fabs (Det (jacobi)) > 1e-8)
    {
      CalcInverse (jacobi, inv);
      x = inv * rs;

      gamma = f1 -> HesseNorm() + f2 -> HesseNorm() + f3 -> HesseNorm();
      beta = 0;
      for (i = 0; i < 3; i++)
	{
	  sum = 0;
	  for (j = 0; j < 3; j++)
	    sum += fabs (inv(i,j));
	  beta = max2 (beta, sum);
	}
      eta = Abs (x);

      alpha = beta * gamma * eta;
    }

  return (alpha < 0.1);
}




bool SpecialPointCalculation :: 
CrossPointDegenerated (const Surface * f1,
		       const Surface * f2, 
		       const Surface * f3, 
		       const BoxSphere<3> & box) const
{
  Mat<3> mat;
  Vec<3> grad, g1, g2, g3;
  double normprod;

  if (box.Diam() > relydegtest) return 0;

  f1->CalcGradient (box.Center(), g1);
  normprod = Abs (g1);

  f2->CalcGradient (box.Center(), g2);
  normprod *= Abs (g2);
 
  f3->CalcGradient (box.Center(), g3);
  normprod *= Abs (g3);

  for (int i = 0; i < 3; i++)
    {
      mat(i,0) = g1(i);
      mat(i,1) = g2(i);
      mat(i,2) = g3(i);
    }

  if (fabs (Det (mat)) < cpeps1 * normprod)
    return 1;
  else 
    return 0;
}
 




void SpecialPointCalculation :: CrossPointNewton (const Surface * f1, 
						  const Surface * f2, 
						  const Surface * f3, Point<3> & p)
{
  int i;
  Vec<3> g1, g2, g3;
  Vec<3> rs, sol;
  Mat<3> mat;

  i = 10;
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
	  /*
      Transpose (g1, g2, g3);
      SolveLinearSystem (g1, g2, g3, rs, sol);
	  */
      if (sol.Length() < 1e-12 && i > 1) i = 1;

      p -= sol;
    }
}




/******* Tests for Point on edges **********************/




bool SpecialPointCalculation :: 
EdgeNewtonConvergence (const Surface * f1, const Surface * f2, 
		       const Point<3> & p)
{
  int i;
  Vec<3> g1, g2, sol;
  Vec<2> vrs;
  double alpha, beta, gamma, eta;
  double sum;
  Mat<2,3> mat;
  Mat<3,2> inv;
  int j;

  vrs(0) = f1->CalcFunctionValue (p);
  vrs(1) = f2->CalcFunctionValue (p);

  f1->CalcGradient (p, g1);
  f2->CalcGradient (p, g2);

  for (i = 0; i < 3; i++)
    {
      mat(0,i) = g1(i);
      mat(1,i) = g2(i);
    }

  alpha = 1;

  if ( fabs(g1 * g2) < (1 - 1e-8) * Abs (g1) * Abs (g2))
    {
      CalcInverse (mat, inv);
      sol = inv * vrs;

      // SolveLinearSystemLS (g1, g2, vrs, sol);

      gamma = f1 -> HesseNorm() + f2 -> HesseNorm();

      /*
      Vec<3> inv1, inv2;
      PseudoInverse (g1, g2, inv1, inv2);
      */
      
      beta = 0;
      for (i = 0; i < 3; i++)
	for (j = 0; j < 2; j++)
	  beta += inv(i,j) * inv(i,j);
      beta = sqrt (beta);

      //      beta = inv1.Length() + inv2.Length();
      eta = Abs (sol);
      alpha = beta * gamma * eta;
    }
  return (alpha < 0.1);
}




bool SpecialPointCalculation :: 
EdgeDegenerated (const Surface * f1,
		 const Surface * f2, 
		 const BoxSphere<3> & box) const
{
  // perform newton steps. normals parallel ?
  // if not decideable: return 0 
  
  
  Point<3> p = box.Center();
  int i;
  Vec<3> grad, g1, g2, sol;
  Vec<2> vrs;
  Mat<2,3> mat;

  i = 20;
  while (i > 0)
    {
      if (Dist (p, box.Center()) > box.Diam())
	return 0;

      i--;
      vrs(0) = f1->CalcFunctionValue (p);
      vrs(1) = f2->CalcFunctionValue (p);

      f1->CalcGradient (p, g1);
      f2->CalcGradient (p, g2);

      if ( fabs (g1 * g2) > (1 - 1e-10) * Abs (g1) * Abs (g2))
	return 1;

      for (int j = 0; j < 3; j++)
	{
	  mat(0,j) = g1(j);
	  mat(1,j) = g2(j);
	}
      mat.Solve (vrs, sol);
      //      SolveLinearSystemLS (g1, g2, vrs, sol);

      if (Abs (sol) < 1e-12 && i > 1) i = 1;
      p -= sol;
    }

  return 0;
  /*
  return 0;

  static DenseMatrix jacobi(3);
  Vec<3> grad, g1, g2, g3;
  double normprod;
  
  if (box.Diam() > relydegtest) return 0;
  
  f1->CalcGradient (box.Center(), g1);
  normprod = g1.Length();
  
  f2->CalcGradient (box.Center(), g2);
  normprod *= g2.Length();
  
  if (fabs (g1 * g2) < 1e-8 * normprod)
    return 1;
  else 
    return 0;
  */
}






void SpecialPointCalculation :: EdgeNewton (const Surface * f1, 
					    const Surface * f2, Point<3> & p)
{
  int i;
  Vec<3> grad, g1, g2, sol;
  Vec<2> vrs;
  Mat<2,3> mat;

  i = 10;
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
      //      SolveLinearSystemLS (g1, g2, vrs, sol);

      if (Abs (sol) < 1e-12 && i > 1) i = 1;
      p -= sol;
    }
}



bool SpecialPointCalculation :: 
IsEdgeExtremalPoint (const Surface * f1, const Surface * f2, 
		     const Point<3> & p, Point<3> & pp, double rad)
{
  Vec<3> g1, g2, t, t1, t2;
  int j;

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
  for (j = 0; j < 3; j++)
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
  int i;

  Vec<3> g1, g2, v, curv;
  Vec<3> rs, x, y1, y2, y;
  Mat<3> h1, h2;
  Mat<3> jacobi;


  if (dir < 1 || dir > 3)
    {
      cerr << "Error: Illegal extremdir" << endl;
      return;
    }

  i = 50;
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
      /*
      CalcInverse (jacobi, inv);
      inv.Mult (rs, x);
      */
      //    (*testout) << "err = " << x.L2Norm() << endl;

      if (Abs (x) < 1e-12 && i > 1)
	{
	  //      (*testout) << "convergent in " << (10 - i) << " steps " << endl;

	  i = 1;
	}
      
      p -= x;
    }

  if (Abs (x) > 1e-10)
    {
      (*testout) << "Error: extremum Newton not convergent" << endl;
      (*testout) << "dir = " << dir << endl;
      (*testout) << "p = " << p << endl;
      (*testout) << "x = " << x << endl;
    }
}




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

  /*
  CalcInverse (a, inv);
  inv.Mult (rs, x);          // x .. Lagrangeparameter
  */
  //  (*testout) << "g1 = " << g1 << " g2 = " << g2 << endl;
  //  (*testout) << "lam = " << x << endl;
  //  (*testout) << "h2 = " << h2 << endl;

  leftside = fabs (x(0) * ( t * (h1 * t)) + 
                   x(1) * ( t * (h2 * t)));

  //  (*testout) << "leftside = " << leftside << endl;

  if (leftside < epeps2 * Abs2 (v)) return 1;  

  return 0;
}

 

bool SpecialPointCalculation :: AddPoint (const Point<3> & p, int layer)
{
  for (int i = 0; i < points->Size(); i++)
    if (Dist2 ( (*points)[i], p) < epspointdist2 &&
	(*points)[i].GetLayer() == layer)
      return 0;

  points->Append (MeshPoint(p, layer));
  return 1;
}







/*
void SpecialPointCalculation :: 
AnalyzeSpecialPoints (const CSGeometry & ageometry,
		      ARRAY<Point<3> > & apoints, 
		      ARRAY<SpecialPoint> & specpoints)
{
  int si, i, j, k, l, m, spi;
  Solid * locsol;
  ARRAY<int> surfind;
  ARRAY<Vec<3>> normalvecs;
  const Solid * sol;
  Vec<3> t;
  Point<3> p;

  ARRAY<int> specpoint2point;
  specpoints.SetSize (0);
 
  (*testout) << "AnalyzeSpecialPoints" << endl;

  for (si = 1; si <= ageometry.GetNTopLevelObjects(); si++)
    {
      (*testout) << "main solid " << si << endl;

      sol = ageometry.GetTopLevelObject(si)->GetSolid();
      for (i = 1; i <= apoints.Size(); i++)
	{
	  p = apoints.Get(i);

	  sol -> TangentialSolid (p, locsol);
	  if (!locsol) continue;
	  
	  (*testout) << "Point " << apoints.Get(i) << endl;

	  locsol -> GetSurfaceIndices (surfind);
	  for (j = surfind.Size(); j >= 1; j--)
	    if (fabs (ageometry.GetSurface(surfind.Get(j))->
		      CalcFunctionValue (p)) > 1e-6)
	      surfind.DeleteElement (j);



	  (*testout) << "Surfaces: ";
	  for (j = 1; j <= surfind.Size(); j++)
	    (*testout) << surfind.Get(j) << " ";
	  (*testout) << endl;

	  normalvecs.SetSize(surfind.Size());
	  for (j = 1; j <= surfind.Size(); j++)
	    ageometry.GetSurface(surfind.Get(j)) -> 
	      GetNormalVector(apoints.Get(i), normalvecs.Elem(j));

	  for (j = 1; j <= normalvecs.Size() - 1; j ++)
	    for (k = j+1; k <= normalvecs.Size(); k++)
	      for (l = 1; l <= 2; l++)
		{
		  t = Cross (normalvecs.Get(j), normalvecs.Get(k));
		  if (t.Length2() < 1e-8)
		    {
		      cerr << "AnalyzePoint: Surfaces degenerated" << endl;
		      break;
		    }
		  t /= t.Length();
		  if (l == 2) t *= -1;

		  if (locsol -> Edge (apoints.Get(i), t))
		    {
		      spi = 0;
		      for (m = 1; m <= specpoints.Size(); m++)
			if (Dist2 (specpoints.Get(m).p, apoints.Get(i)) < 1e-8
			    && (specpoints.Get(m).v - t).Length2() < 1e-8)
			  {
			    spi = m;
			    break;
			  }
		      if (!spi)
			{
			  spi = specpoints.Append (SpecialPoint());
			  specpoint2point.Append (i);
			  specpoints.Last().unconditional = 0;
			}
		      specpoints.Elem(spi).p = apoints.Get(i);
		      specpoints.Elem(spi).v = t;
		      if (surfind.Size() >= 3)
			specpoints.Elem(spi).unconditional = 1;
		      specpoints.Elem(spi).s1 = surfind.Get(j);
		      specpoints.Elem(spi).s2 = surfind.Get(k);
		      (*testout) << "spi = " << spi 
				 << " uncond = " << specpoints.Get(spi).unconditional
				 << " t = " << t << endl;
		    }
          
		}
	  delete locsol;
	}
    }

  // if special point is unconditional on some solid,
  // it must be unconditional everywhere:

  BitArray uncond (apoints.Size());
  uncond.Clear();

  for (i = 1; i <= specpoints.Size(); i++)
    if (specpoints.Get(i).unconditional)
      uncond.Set (specpoint2point.Get(i));

  for (i = 1; i <= specpoints.Size(); i++)
    specpoints.Elem(i).unconditional = 
      uncond.Test (specpoint2point.Get(i)) ? 1 : 0;
}
*/



void SpecialPointCalculation :: 
AnalyzeSpecialPoints (const CSGeometry & ageometry,
		      ARRAY<MeshPoint> & apoints, 
		      ARRAY<SpecialPoint> & specpoints)
{
  int si, i, j, k, l, m, spi;

  Solid * locsol;
  ARRAY<int> surfind;
  ARRAY<int> surfind2;

  ARRAY<Vec<3> > normalvecs;
  const Solid * sol;
  const Surface * surf;

  Vec<3> t, nsurf;
  Point<3> p;

  ARRAY<int> specpoint2point;
  specpoints.SetSize (0);

  geometry = &ageometry;
 
  (*testout) << "AnalyzeSpecialPoints\n";

  for (si = 0; si < ageometry.GetNTopLevelObjects(); si++)
    {
      (*testout) << "main solid " << si << "\n";

      sol = ageometry.GetTopLevelObject(si)->GetSolid();
      surf = ageometry.GetTopLevelObject(si)->GetSurface();

      for (i = 0; i < apoints.Size(); i++)
	{
	  p = apoints[i];
	  if (ageometry.GetTopLevelObject(si)->GetLayer() !=
	      apoints[i].GetLayer())
	    continue;

	  // (*testout) << "Point " << apoints[i] << "\n";

	  sol -> TangentialSolid (p, locsol);
	  if (!locsol) continue;
	  
	  // get all surface indices, 
	  if (surf)
	    {
	      locsol -> GetSurfaceIndices (surfind);
	      bool hassurf = 0;
	      for (m = 0; m < surfind.Size(); m++)
		if (ageometry.GetSurface(surfind[m]) == surf)
		  hassurf = 1;

	      if (!hassurf)
		continue;

	      surf->GetNormalVector (p, nsurf);
	    }

	  // get independent surfaces of tangential solid

	  BoxSphere<3> box(p,p);
	  box.Increase (1e-6);
	  box.CalcDiamCenter();
	  ageometry.GetIndependentSurfaceIndices (locsol, box, surfind);


	  /*
	  locsol -> GetSurfaceIndices (surfind);
	  for (j = surfind.Size(); j >= 1; j--)
	    if (fabs (ageometry.GetSurface(surfind.Get(j))->
		      CalcFunctionValue (p)) > 1e-6)
	      surfind.DeleteElement (j);
	  */

	  /*
	  (*testout) << "Surfaces: ";
	  for (j = 0; j < surfind.Size(); j++)
	    (*testout) << surfind[j] << " ";
	  (*testout) << "\n";
	  */


	  normalvecs.SetSize(surfind.Size());
	  for (j = 0; j < surfind.Size(); j++)
	    ageometry.GetSurface(surfind[j]) ->
	      GetNormalVector(apoints[i], normalvecs[j]);

	  for (j = 0; j < normalvecs.Size(); j++)
	    for (k = j+1; k < normalvecs.Size(); k++)
	      for (l = 1; l <= 2; l++)
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
		      for (m = 0; m < surfind.Size(); m++)
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
		      spi = -1;
		      for (m = 0; m < specpoints.Size(); m++)
			if (Dist2 (specpoints[m].p, apoints[i]) < 1e-8
			    && Abs2(specpoints[m].v - t) < 1e-8)
			  {
			    spi = m;
			    break;
			  }
		      if (spi == -1)
			{
			  spi = specpoints.Append (SpecialPoint()) - 1;
			  specpoint2point.Append (i);
			  specpoints.Last().unconditional = 0;
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
			
		      /*
		      (*testout) << "spi = " << spi 
				 << " uncond = " << specpoints[spi].unconditional
				 << " t = " << t << "\n";
		      */
		    }
          
		}
	  delete locsol;
	}
    }

  // if special point is unconditional on some solid,
  // it must be unconditional everywhere:

  BitArray uncond (apoints.Size());
  uncond.Clear();

  for (i = 0; i < specpoints.Size(); i++)
    if (specpoints[i].unconditional)
      uncond.Set (specpoint2point[i]);
  
  for (i = 0; i < specpoints.Size(); i++)
    specpoints[i].unconditional = 
      uncond.Test (specpoint2point[i]) ? 1 : 0;
}
}

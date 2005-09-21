#include <mystdlib.h>
#include "meshing.hpp"

namespace netgen
{
static double CalcElementBadness (const ARRAY<Point2d> & points,
				  const Element2d & elem)
{
  // badness = sqrt(3) /36 * circumference^2 / area - 1 +
  //           h / li + li / h - 2

  Vec2d v12, v13, v23;
  double l12, l13, l23, cir, area;
  static const double c = sqrt(3.0) / 36;

  v12 = points.Get(elem.PNum(2)) - points.Get(elem.PNum(1));
  v13 = points.Get(elem.PNum(3)) - points.Get(elem.PNum(1));
  v23 = points.Get(elem.PNum(3)) - points.Get(elem.PNum(2));

  l12 = v12.Length();
  l13 = v13.Length();
  l23 = v23.Length();

  cir = l12 + l13 + l23;
  area = 0.5 * (v12.X() * v13.Y() - v12.Y() * v13.X());
  if (area < 1e-6)
    {
      return 1e8;
    }

  if (testmode)
    {
      (*testout) << "l = " << l12 << " + " << l13 << " + " << l23 << " = " 
		 << cir << ", area = " << area << endl;
      (*testout) << "shapeerr = " << 10 * (c * cir * cir / area - 1) << endl
		 << "sizeerr = " << 1/l12 + l12 + 1/l13 + l13 + 1/l23 + l23 - 6
		 << endl;
    }

  return 10 * (c * cir * cir / area - 1)
    + 1/l12 + l12 + 1/l13 + l13 + 1/l23 + l23 - 6;
}



int Meshing2 ::ApplyRules (ARRAY<Point2d> & lpoints, 
			   ARRAY<int> & legalpoints,
			   int maxlegalpoint,
			   ARRAY<INDEX_2> & llines,
			   int maxlegalline,
			   ARRAY<Element2d> & elements,
			   ARRAY<INDEX> & dellines, int tolerance)
{
  int i, j, ri, nlok, npok, incnpok, refpi, locli = 0;

  double maxerr = 0.5 + 0.3 * tolerance;
  double minelerr = 2 + 0.5 * tolerance * tolerance;


  bool ok;
  int found;   // rule number
  Vector oldu, newu;
  Point2d np;
  Vec2d linevec;
  int oldnp;
  INDEX_2 loclin;
  double hf, elerr;
  int noldlp, noldll;
  int loctestmode;

  static ARRAY<int> pused, lused;
  static ARRAY<int> pmap, lmap, pfixed;
  static ARRAY<int> pnearness, lnearness;
  
  static ARRAY<Point2d> tempnewpoints;
  static ARRAY<INDEX_2> tempnewlines;
  static ARRAY<int> tempdellines;
  static ARRAY<Element2d> tempelements;



  elements.SetSize (0);
  dellines.SetSize (0);

  noldlp = lpoints.Size();
  noldll = llines.Size();

  pused.SetSize (maxlegalpoint);
  lused.SetSize (maxlegalline);
  pnearness.SetSize (noldlp);
  lnearness.SetSize (llines.Size());


  testmode = debugparam.debugoutput;
  loctestmode = testmode;

  if (loctestmode)
    {
      (*testout) << endl << endl << "Check new environment" << endl;
      (*testout) << "tolerance = " << tolerance << endl;
      for (i = 1; i <= lpoints.Size(); i++)
	(*testout) << "P" << i << " = " << lpoints.Get(i) << endl;
      (*testout) << endl;
      for (i = 1; i <= llines.Size(); i++)
	(*testout) << "(" << llines.Get(i).I1() << "-" << llines.Get(i).I2() << ")" << endl;
    }

  // check every rule

  found = 0;

  
  for (i = 1; i <= noldlp; i++)
    pnearness.Set(i, 1000);
  
  for (j = 1; j <= 2; j++)
    pnearness.Set(llines.Get(1).I(j), 0);
    

  do
    {
      ok = 1;
      for (i = 1; i <= maxlegalline; i++)
	{
	  const INDEX_2 & hline = llines.Get(i);

	  /*
	  int minn = INT_MAX-1;
	  for (j = 1; j <= 2; j++)
	    {
	      int hi = pnearness.Get(hline.I(j));
	      if (hi < minn) minn = hi;
	    }
	  */
	  int minn = pnearness.Get(hline.I1());
	  int minn2 = pnearness.Get(hline.I2());
	  if (minn2 < minn)
	    minn = minn2;

	  /*
	  for (j = 1; j <= 2; j++)
	    {
	      int hpi = hline.I(j);
	      if (pnearness.Get(hpi) > minn+1)
		{
		  ok = 0;
		  pnearness.Set(hpi, minn+1);
		}
	    }
	  */
	  int hpi = hline.I1();
	  if (pnearness.Get(hpi) > minn+1)
	    {
	      ok = 0;
	      pnearness.Set(hpi, minn+1);
	    }
	  hpi = hline.I2();
	  if (pnearness.Get(hpi) > minn+1)
	    {
	      ok = 0;
	      pnearness.Set(hpi, minn+1);
	    }
	}
    }
  while (!ok);
  
  for (i = 1; i <= maxlegalline /* lnearness.Size() */; i++)
    {
      lnearness.Set(i, 0);
      for (j = 1; j <= 2; j++)
	lnearness.Elem(i) += pnearness.Get(llines.Get(i).I(j));
    }


  for (ri = 1; ri <= rules.Size(); ri++)
    {
      netrule * rule = rules.Get(ri);

      if (loctestmode)
	(*testout) << "Rule " << rule->Name() << endl;

      if (rule->GetQuality() > tolerance) continue;

      pmap.SetSize (rule->GetNP());
      lmap.SetSize (rule->GetNL());
      
      lused = 0;
      pused = 0;
      pmap = 0;
      lmap = 0;
      /*
      for (i = 1; i <= lused.Size(); i++)
	lused.Set (i, 0);
      for (i = 1; i <= pused.Size(); i++)
	pused.Set (i, 0);
      for (i = 1; i <= pmap.Size(); i++)
	pmap.Set(i, 0);
      for (i = 1; i <= lmap.Size(); i++)
	lmap.Set(i, 0);
      */

      lused[0] = 1;   // .Set (1, 1);
      lmap[0] = 1;    // .Set (1, 1);

      for (j = 1; j <= 2; j++)
	{
	  pmap.Elem(rule->GetPointNr (1, j)) = llines.Get(1).I(j);
	  pused.Elem(llines.Get(1).I(j))++;
	}


      nlok = 2;

      while (nlok >= 2)
	{

	  if (nlok <= rule->GetNOldL())

	    {
	      ok = 0;
	      while (!ok && lmap.Get(nlok) < maxlegalline  /* llines.Size() */)
		{
		  lmap.Elem(nlok)++;
		  locli = lmap.Get(nlok);

		  if (!lused.Get(locli) && 
		      lnearness.Get(locli) <= rule->GetLNearness (nlok) )
		    {
		      ok = 1;

		      loclin = llines.Get(locli);

		      linevec.X() = lpoints.Get (loclin.I2()).X() -
			lpoints.Get (loclin.I1()).X();
		      linevec.Y() = lpoints.Get (loclin.I2()).Y() -
			lpoints.Get (loclin.I1()).Y();

		      if (rule->CalcLineError (nlok, linevec) > maxerr)
			  ok = 0;

		      for (j = 1; j <= 2 && ok; j++)
			{
			  refpi = rule->GetPointNr (nlok, j);

			  if (pmap.Get(refpi) != 0)
			    {
			      if (pmap.Get(refpi) != loclin.I(j))
				ok = 0;
			    }
			  else
			    {
			      if (rule->CalcPointDist (refpi, lpoints.Get(loclin.I(j))) > maxerr
				  || !legalpoints.Get(loclin.I(j))
				  || pused.Get(loclin.I(j))) ok = 0;
			    }
			}
		    }
		}

	      if (ok)
		{
		  lused.Set (locli, 1);
		  for (j = 1; j <= 2; j++)
		    {
		      pmap.Set(rule->GetPointNr (nlok, j), loclin.I(j));
		      pused.Elem(loclin.I(j))++;
		    }

		  nlok++;
		}
	      else
		{
		  lmap.Elem(nlok) = 0;
		  nlok--;

		  lused.Set (lmap.Get(nlok), 0);
		  for (j = 1; j <= 2; j++)
		    {
		      pused.Elem(llines.Get(lmap.Get(nlok)).I(j)) --;
		      if (! pused.Get (llines.Get (lmap.Get (nlok)).I(j)))
			pmap.Set (rule->GetPointNr (nlok, j), 0);
		    }
		}
	    }

	  else

	    {

	      // all lines are mapped !!

	      // map also all points:

	      npok = 1;
	      incnpok = 1;

	      pfixed.SetSize (pmap.Size());
	      for (i = 1; i <= pmap.Size(); i++)
		pfixed.Elem(i) = (pmap.Get(i) >= 1);

	      while (npok >= 1)
		{

		  if (npok <= rule->GetNOldP())

		    {
		      if (pfixed.Get(npok))

			{
			  if (incnpok)
			    npok++;
			  else
			    npok--;
			}

		      else

			{
			  ok = 0;

			  if (pmap.Get(npok))
			    pused.Elem(pmap.Get(npok))--;

			  while (!ok && pmap.Get(npok) < maxlegalpoint)
			    {
			      ok = 1;

			      pmap.Elem(npok)++;

			      if (pused.Get(pmap.Get(npok)))
				{
				  ok = 0;
				}
			      else
				{
				  if (rule->CalcPointDist (npok, lpoints.Get(pmap.Get(npok))) > maxerr 
				      || !legalpoints.Get(pmap.Get(npok)) 
				      ) ok = 0;
				}
			    }

			  if (ok)
			    {
			      pused.Elem(pmap.Get(npok))++;
			      npok++;
			      incnpok = 1;
			    }

			  else

			    {
			      pmap.Elem(npok) = 0;
			      npok--;
			      incnpok = 0;
			    }
			}
		    }

		  else

		    {
		      if (ok)
			foundmap.Elem(ri)++; 

		      if (loctestmode)
			(*testout) << "lines and points mapped" << endl;


		      ok = 1;

		      // check orientations

		      for (i = 1; i <= rule->GetNOrientations() && ok; i++)
			{
			  if (CW (lpoints.Get(pmap.Get(rule->GetOrientation(i).i1)),
				  lpoints.Get(pmap.Get(rule->GetOrientation(i).i2)),
				  lpoints.Get(pmap.Get(rule->GetOrientation(i).i3))) )
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "Orientation " << i << " not ok" << endl;
			    }
			}

		      if (ok)
			{
			  oldu.SetSize (2 * rule->GetNOldP());
			  
			  for (i = 1; i <= rule->GetNOldP(); i++)
			    {
			      Vec2d ui(rule->GetPoint(i), lpoints.Get(pmap.Get(i)));
			      oldu.Set (2*i-1, ui.X());
			      oldu.Set (2*i  , ui.Y());
			    }
			  
			  rule -> SetFreeZoneTransformation (oldu, tolerance);
			}
		      

		      if (ok && !rule->ConvexFreeZone())
			{
			  ok = 0;
			  if (loctestmode) (*testout) << "freezone not convex" << endl;

			  /*
			  static int cnt = 0;
			  cnt++;
			  if (cnt % 100 == 0)
			    {
			      cout << "freezone not convex, cnt = " << cnt << "; rule = " << rule->Name() << endl;
			      (*testout) << "freezone not convex, cnt = " << cnt << "; rule = " << rule->Name() << endl;
			      (*testout) << "tol = " << tolerance << endl;
			      (*testout) << "maxerr = " << maxerr << "; minerr = " << minelerr << endl;
			      (*testout) << "freezone = " << rule->GetTransFreeZone() << endl;
			    }
			  */
			}

		      // check freezone:

		      for (i = 1; i <= maxlegalpoint && ok; i++)
			{
			  if ( !pused.Get(i) &&
			       rule->IsInFreeZone (lpoints.Get(i)) )
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "Point " << i << " in freezone" << endl;
			    }
			}


		      for (i = maxlegalpoint+1; i <= lpoints.Size() && ok; i++)
			{
			  if ( rule->IsInFreeZone (lpoints.Get(i)) )
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "Point " << i << " in freezone" << endl;
			    }
			}

		      for (i = 1; i <= maxlegalline && ok; i++)
			{
			  if (!lused.Get(i) && 
			      rule->IsLineInFreeZone (lpoints.Get(llines.Get(i).I1()),
						      lpoints.Get(llines.Get(i).I2())))
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "line " << llines.Get(i).I1() << "-"
					   << llines.Get(i).I2() << " in freezone" << endl;
			    }
			}
		      for (i = maxlegalline+1; i <= llines.Size() && ok; i++)
			{
			  if (rule->IsLineInFreeZone (lpoints.Get(llines.Get(i).I1()),
						      lpoints.Get(llines.Get(i).I2())))
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "line " << llines.Get(i).I1() << "-"
					   << llines.Get(i).I2() << " in freezone" << endl;
			    }
			}


		      /*
		      // check orientations

		      for (i = 1; i <= rule->GetNOrientations() && ok; i++)
			{
			  if (CW (lpoints.Get(pmap.Get(rule->GetOrientation(i).i1)),
				  lpoints.Get(pmap.Get(rule->GetOrientation(i).i2)),
				  lpoints.Get(pmap.Get(rule->GetOrientation(i).i3))) )
			    {
			      ok = 0;
			      if (loctestmode)
				(*testout) << "Orientation " << i << " not ok" << endl;
			    }
			}
		      */


		      if (ok)
			{
			  if (loctestmode)
			    (*testout) << "rule ok" << endl;

			  //			  newu = rule->GetOldUToNewU() * oldu;
			  if (rule->GetNOldP() < rule->GetNP())
			    {
			      newu.SetSize (rule->GetOldUToNewU().Height());
			      rule->GetOldUToNewU().Mult (oldu, newu);
			    }

			  // Setze neue Punkte:

			  oldnp = rule->GetNOldP();

			  for (i = oldnp + 1; i <= rule->GetNP(); i++)
			    {
			      np = rule->GetPoint(i);
			      np.X() += newu.Elem (2 * (i-oldnp) - 1);
			      np.Y() += newu.Elem (2 * (i-oldnp));

			      pmap.Elem(i) = lpoints.Append (np);
			    }

			  // Setze neue Linien:

			  for (i = rule->GetNOldL() + 1; i <= rule->GetNL(); i++)
			    {
			      llines.Append (INDEX_2 (pmap.Get(rule->GetPointNr (i, 1)),
						      pmap.Get(rule->GetPointNr (i, 2))));
			    }


			  // delete old lines:

			  for (i = 1; i <= rule->GetNDelL(); i++)
			    dellines.Append (lmap.Get(rule->GetDelLine(i)));

			  // insert new elements:

			  for (i = 1; i <= rule->GetNE(); i++)
			    {
			      elements.Append (rule->GetElement(i));
			      for (j = 1; j <= elements.Get(i).GetNP(); j++)
				elements.Elem(i).PNum(j) = pmap.Get(elements.Get(i).PNum(j));
			    }


			  elerr = 0;
			  for (i = 1; i <= elements.Size(); i++)
			    {
			      if (!mparam.quad)
				hf = CalcElementBadness (lpoints, elements.Get(i));
			      else
				hf = elements.Get(i).CalcJacobianBadness (lpoints) * 5;
			      if (loctestmode)
				(*testout) << "r " << rule->Name() << "bad = " << hf << endl;
			      if (hf > elerr) elerr = hf;
			    }

			  if (loctestmode)
			    (*testout) << "error = " << elerr;


			  canuse.Elem(ri) ++;

			  if (elerr < minelerr)
			    {

			      if (loctestmode)
				{
				  (*testout) << "rule = " << rule->Name() << endl;
				  (*testout) << "class = " << tolerance << endl;
				  (*testout) << "lpoints: " << endl;
				  for (i = 1; i <= lpoints.Size(); i++)
				    (*testout) << lpoints.Get(i) << endl;
				  (*testout) << "llines: " << endl;
				  for (i = 1; i <= llines.Size(); i++)
				    (*testout) << llines.Get(i).I1() << " " << llines.Get(i).I2() << endl;

				  (*testout) << "Freezone: ";
				  for (i = 1; i <= rule -> GetTransFreeZone().Size(); i++)
				    (*testout) << rule->GetTransFreeZone().Get(i) << endl;
				}



			      minelerr = elerr;
			      found = ri;

			      tempnewpoints.SetSize (0);
			      for (i = noldlp+1; i <= lpoints.Size(); i++)
				tempnewpoints.Append (lpoints.Get(i));

			      tempnewlines.SetSize (0);
			      for (i = noldll+1; i <= llines.Size(); i++)
				tempnewlines.Append (llines.Get(i));

			      tempdellines.SetSize (0);
			      for (i = 1; i <= dellines.Size(); i++)
				tempdellines.Append (dellines.Get(i));

			      tempelements.SetSize (0);
			      for (i = 1; i <= elements.Size(); i++)
				tempelements.Append (elements.Get(i));
			    }

			  lpoints.SetSize (noldlp);
			  llines.SetSize (noldll);
			  dellines.SetSize (0);
			  elements.SetSize (0);
			  ok = 0;

			}


		      npok = rule->GetNOldP();
		      incnpok = 0;
		    }
		}

	      nlok = rule->GetNOldL();

	      lused.Set (lmap.Get(nlok), 0);

	      for (j = 1; j <= 2; j++)
		{
		  refpi = rule->GetPointNr (nlok, j);
		  pused.Elem(pmap.Get(refpi))--;

		  if (pused.Get(pmap.Get(refpi)) == 0)
		    {
		      pmap.Set(refpi, 0);
		    }
		}
	    }
	}
    }


  if (found)
    {
      for (i = 0; i < tempnewpoints.Size(); i++)
	lpoints.Append (tempnewpoints[i]);
      for (i = 0; i < tempnewlines.Size(); i++)
	llines.Append (tempnewlines[i]);
      for (i = 0; i < tempdellines.Size(); i++)
	dellines.Append (tempdellines[i]);
      for (i = 0; i < tempelements.Size(); i++)
	elements.Append (tempelements[i]);
    }


  return found;
}





}

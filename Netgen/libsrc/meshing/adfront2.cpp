/*
  Advancing front class for surfaces
*/

#include <mystdlib.h>
#include "meshing.hpp"


namespace netgen
{

  /*
AdFront2::FrontPoint2 :: FrontPoint2 ()
{
  globalindex = 0;
  nlinetopoint = 0;
  frontnr = INT_MAX-10;    // attention: overflow on calculating  INT_MAX + 1
  mgi = NULL;
}
  */

AdFront2::FrontPoint2 :: FrontPoint2 (const Point3d & ap, PointIndex agi,
				      MultiPointGeomInfo * amgi)
{
  p = ap;
  globalindex = agi;
  nlinetopoint = 0;
  frontnr = INT_MAX-10;

  if (amgi)
    {
      mgi = new MultiPointGeomInfo (*amgi);
      for (int i = 1; i <= mgi->GetNPGI(); i++)
	if (mgi->GetPGI(i).trignum <= 0)
	  cout << "Add FrontPoint2, illegal geominfo = " << mgi->GetPGI(i).trignum << endl;
    }
  else
    mgi = NULL;
}

/*
AdFront2::FrontPoint2 :: ~FrontPoint2 ()
{
//  if (mgi) delete mgi;
}
*/


AdFront2::FrontLine :: FrontLine ()
{
  lineclass = 1;
}

AdFront2::FrontLine :: FrontLine (const INDEX_2 & al)
{
  l = al;
  lineclass = 1;
}






AdFront2 :: AdFront2 (const Box3d & aboundingbox)
  : boundingbox(aboundingbox), 
    linesearchtree(boundingbox.PMin(), boundingbox.PMax()),
    cpointsearchtree(boundingbox.PMin(), boundingbox.PMax())
{
  nfl = 0;
  //  allflines = new INDEX_2_HASHTABLE<int> (100000);
  allflines = 0;

  minval = 0;
  starti = 1;
}

AdFront2 :: ~AdFront2 ()
{
  delete allflines;
}


void AdFront2 :: PrintOpenSegments (ostream & ost) const
{
 if (nfl > 0)
    {
      int i;
      ost << nfl << " open front segments left:" << endl;
      for (i = 1; i <= lines.Size(); i++)
	if (lines.Get(i).Valid())
	  ost << GetGlobalIndex (lines.Get(i).L().I1()) << "-"
	      << GetGlobalIndex (lines.Get(i).L().I2()) << endl;
	    
    }
}


void AdFront2 :: GetPoints (ARRAY<Point3d> & apoints) const
{
  for (int i = 0; i < points.Size(); i++)
    apoints.Append (points[i].P());
}





INDEX AdFront2 :: AddPoint (const Point3d & p, PointIndex globind, 
			    MultiPointGeomInfo * mgi)
{
  // inserts at empty position or resizes array
  int pi;

  if (delpointl.Size() != 0)
    {
      pi = delpointl.Last();
      delpointl.DeleteLast ();

      points.Elem(pi) = FrontPoint2 (p, globind, mgi);
    }
  else
    {
      pi = points.Append (FrontPoint2 (p, globind, mgi));
    }

  if (mgi)
    {
      cpointsearchtree.Insert (p, pi);
    }

  return pi;
}


INDEX AdFront2 :: AddLine (INDEX pi1, INDEX pi2,
			   const PointGeomInfo & gi1, const PointGeomInfo & gi2)
{
  int minfn;
  INDEX li;

  FrontPoint2 & p1 = points.Elem(pi1);
  FrontPoint2 & p2 = points.Elem(pi2);

  nfl++;

  p1.AddLine();
  p2.AddLine();

  minfn = min2 (p1.FrontNr(), p2.FrontNr());
  p1.DecFrontNr (minfn+1);
  p2.DecFrontNr (minfn+1);

  if (dellinel.Size() != 0)
    {
      li = dellinel.Last();
      dellinel.DeleteLast ();

      lines.Elem(li) = FrontLine (INDEX_2(pi1, pi2));
    }
  else
    {
      li = lines.Append(FrontLine (INDEX_2(pi1, pi2)));
    }

  
  if (!gi1.trignum || !gi2.trignum)
    {
      cout << "ERROR: in AdFront::AddLine, illegal geominfo" << endl;
    }
  
  lines.Elem(li).SetGeomInfo (gi1, gi2);

  Box3d lbox;
  lbox.SetPoint(p1.P());
  lbox.AddPoint(p2.P());

  linesearchtree.Insert (lbox.PMin(), lbox.PMax(), li);

  /*
  (*testout) << "add front line: " << p1.P() << " - " << p2.P()
  	     << " Dist = " << Dist (p1.P(), p2.P()) << endl;
  */

  if (allflines)
    {
      if (allflines->Used (INDEX_2 (GetGlobalIndex (pi1), 
				    GetGlobalIndex (pi2))))
	{
	  cerr << "ERROR Adfront2::AddLine: line exists" << endl;
	  (*testout) << "ERROR Adfront2::AddLine: line exists" << endl;
	}

      allflines->Set (INDEX_2 (GetGlobalIndex (pi1), 
			       GetGlobalIndex (pi2)), 1);
    }

  return li;
}


void AdFront2 :: DeleteLine (INDEX li)
{
  int i;
  INDEX pi;

  nfl--;

  for (i = 1; i <= 2; i++)
    {
      pi = lines.Get(li).L().I(i);
      points.Elem(pi).RemoveLine();

      if (!points.Get(pi).Valid())
	{
	  delpointl.Append (pi);
	  if (points.Elem(pi).mgi)
	    {
	      cpointsearchtree.DeleteElement (pi);
	      delete points.Elem(pi).mgi;
	      points.Elem(pi).mgi = NULL;
	    }
	}
    }

  if (allflines)
    {
      allflines->Set (INDEX_2 (GetGlobalIndex (lines.Get(li).L().I1()),
			       GetGlobalIndex (lines.Get(li).L().I2())), 2);
    }

  lines.Elem(li).Invalidate();
  linesearchtree.DeleteElement (li);



  dellinel.Append (li);
}


int AdFront2 :: ExistsLine (int pi1, int pi2)
{
  if (!allflines)
    return 0;
  if (allflines->Used (INDEX_2(pi1, pi2)))
    return allflines->Get (INDEX_2 (pi1, pi2));
  else
    return 0;
}



void AdFront2 :: IncrementClass (INDEX li)
{
  lines.Elem(li).IncrementClass();
}


void AdFront2 :: ResetClass (INDEX li)
{
  lines.Elem(li).ResetClass();
}



int AdFront2 :: SelectBaseLine (Point3d & p1, Point3d & p2, 
				const PointGeomInfo *& geominfo1,
				const PointGeomInfo *& geominfo2)
{
  int i, hi;

  /*  
      int minval;
      int baselineindex;
      minval = INT_MAX;
  for (i = 1; i <= lines.Size(); i++)
    if (lines.Get(i).Valid())
      {
	hi = lines.Get(i).LineClass() +
	  points.Get(lines.Get(i).L().I1()).FrontNr() +
	  points.Get(lines.Get(i).L().I2()).FrontNr();
	
	if (hi < minval)
	  {
	    minval = hi;
	    baselineindex = i;
	  }
      }
  */

  /*
  static int minval = 0;
  static int starti = 1;
  */
  int baselineindex = 0; 

  for (i = starti; i <= lines.Size(); i++)
    {
      if (lines.Get(i).Valid())
	//      const ILINE * lp = &lines.Get(i).l;
	//      if (lp->I1() >= 0)
	{
	  hi = lines.Get(i).LineClass() +
	    points.Get(lines.Get(i).L().I1()).FrontNr() +
	    points.Get(lines.Get(i).L().I2()).FrontNr();
	  
	  if (hi <= minval)
	    {
	      minval = hi;
	      baselineindex = i;
	      break;
	    }
	}
    }
  
  if (!baselineindex)
    {
      (*testout) << "nfl = " << nfl << " tot l = " << lines.Size() << endl;
      minval = INT_MAX;
      for (i = 1; i <= lines.Size(); i++)
	if (lines.Get(i).Valid())
	  {
	    hi = lines.Get(i).LineClass() +
	      points.Get(lines.Get(i).L().I1()).FrontNr() +
	      points.Get(lines.Get(i).L().I2()).FrontNr();
	    
	    if (hi < minval)
	      {
		minval = hi;
		baselineindex = i;
	      }
	  }
    }
  starti = baselineindex+1;



  p1 = points.Get(lines.Get(baselineindex).L().I1()).P();
  p2 = points.Get(lines.Get(baselineindex).L().I2()).P();
  geominfo1 = &lines.Get(baselineindex).GetGeomInfo(1);
  geominfo2 = &lines.Get(baselineindex).GetGeomInfo(2);
  return baselineindex;
}




int AdFront2 :: GetLocals (int baselineindex,
			   ARRAY<Point3d> & locpoints,
			   ARRAY<MultiPointGeomInfo> & pgeominfo,
			   ARRAY<INDEX_2> & loclines,   // local index
			   ARRAY<INDEX> & pindex,
			   ARRAY<INDEX> & lindex,
			   double xh)
{
  int i, j, ii;
  int pstind;
  int pi;
  Point3d midp, p0;

  pstind = lines.Get(baselineindex).L().I1();
  p0 = points.Get(pstind).P();

  loclines.Append(lines.Get(baselineindex).L());
  lindex.Append(baselineindex);

  static ARRAY<int> nearlines;

  nearlines.SetSize(0);
  double dist = xh;
  linesearchtree.GetIntersecting (p0 - Vec3d(dist, dist, dist),
				  p0 + Vec3d(dist, dist, dist),
				  nearlines);

  //  for (i = 1; i <= lines.Size(); i++)
  for (ii = 1; ii <= nearlines.Size(); ii++)
    {
      i = nearlines.Get(ii);

      if (lines.Get(i).Valid() && i != baselineindex)
	{
	  const Point3d & p1 = points.Get(lines.Get(i).L().I1()).P();
	  const Point3d & p2 = points.Get(lines.Get(i).L().I2()).P();

	  midp = Center (p1, p2);
	  
	  if (Dist (midp, p0) <= xh + 0.5 * Dist (p1, p2))
	    {
	      loclines.Append(lines.Get(i).L());
	      lindex.Append(i);
	    }
	}
    }

  static ARRAY<int> invpindex;

  invpindex.SetSize (points.Size());
  for (i = 1; i <= loclines.Size(); i++)
    for (j = 1; j <= 2; j++)
      invpindex.Elem(loclines.Get(i).I(j)) = 0;

  for (i = 1; i <= loclines.Size(); i++)
    {
      for (j = 1; j <= 2; j++)
	{
	  pi = loclines.Get(i).I(j);
	  if (invpindex.Get(pi) == 0)
	    {
	      pindex.Append (pi);
	      invpindex.Elem(pi) = pindex.Size();
	      loclines.Elem(i).I(j) = locpoints.Append (points.Get(pi).P());
	    }
	  else
	    loclines.Elem(i).I(j) = invpindex.Get(pi);
	}
    }

  pgeominfo.SetSize (locpoints.Size());
  for (i = 1; i <= pgeominfo.Size(); i++)
    pgeominfo.Elem(i).Init();


  for (i = 1; i <= loclines.Size(); i++)
    for (j = 1; j <= 2; j++)
      {
	int lpi = loclines.Get(i).I(j);
	
	const PointGeomInfo & gi = 
	  lines.Get(lindex.Get(i)).GetGeomInfo (j);
	pgeominfo.Elem(lpi).AddPointGeomInfo (gi);
	
	/*
	if (pgeominfo.Elem(lpi).cnt == MULTIPOINTGEOMINFO_MAX)
	  break;

	const PointGeomInfo & gi = 
	  lines.Get(lindex.Get(i)).GetGeomInfo (j);
	
	PointGeomInfo * pgi = pgeominfo.Elem(lpi).mgi;

	int found = 0;
	for (k = 0; k < pgeominfo.Elem(lpi).cnt; k++)
	  if (pgi[k].trignum == gi.trignum)
	    found = 1;

	if (!found)
	  {
	    pgi[pgeominfo.Elem(lpi).cnt] = gi;
	    pgeominfo.Elem(lpi).cnt++;
	  }
	*/
      }

  for (i = 1; i <= locpoints.Size(); i++)
    {
      int pi = pindex.Get(i);


      
      if (points.Get(pi).mgi)
	for (j = 1; j <= points.Get(pi).mgi->GetNPGI(); j++)
	  pgeominfo.Elem(i).AddPointGeomInfo (points.Get(pi).mgi->GetPGI(j));
/*
	{
	  for (j = 0; j < points.Get(pi).mgi->cnt; j++)
	    {
	      pgeominfo.Elem(i).mgi[pgeominfo.Elem(i).cnt] = 
		points.Get(pi).mgi->mgi[j];
	      pgeominfo.Elem(i).cnt++;
	    }
	}
*/
    }
	
  

  /*
  for (i = 1; i <= points.Size(); i++)
    if (points.Get(i).Valid() && 
	Dist (points.Get(i).P(), p0) <= xh &&
	invpindex.Get(i) == 0)
      {
	invpindex.Elem(i) =
	  locpoints.Append (points.Get(pi).P());
      }
  */


  if (loclines.Size() == 1)
    {
      cout << "loclines.Size = 1" << endl;
      (*testout) << "loclines.size = 1" << endl
		 << " h = " << xh << endl
		 << " nearline.size = " << nearlines.Size() << endl
		 << " p0 = " << p0 << endl;
    }



  return lines.Get(baselineindex).LineClass();
}



void AdFront2 :: SetStartFront ()
{
  INDEX i;
  int j;

  for (i = 1; i <= lines.Size(); i++)
    if (lines.Get(i).Valid())
      for (j = 1; j <= 2; j++)
        points.Elem(lines.Get(i).L().I(j)).DecFrontNr(0);
}




void AdFront2 :: Print (ostream & ost) const
{
  INDEX i;

  ost << points.Size() << " Points: " << endl;
  for (i = 1; i <= points.Size(); i++)
    if (points.Get(i).Valid())
      ost << i << "  " << points.Get(i).P() << endl;

  ost << nfl << " Lines: " << endl;
  for (i = 1; i <= lines.Size(); i++)
    if (lines.Get(i).Valid())
      ost << lines.Get(i).L().I1() << " - " << lines.Get(i).L().I2() << endl;

  ost << flush;
}
}

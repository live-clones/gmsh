#include <mystdlib.h>
#include <myadt.hpp>

#include <linalg.hpp>
#include <csg.hpp>
#include <meshing.hpp>


namespace netgen
{
Identification :: Identification (int anr, const CSGeometry & ageom)
  : geom(ageom), identfaces(10)
{
  nr = anr;
}

Identification :: ~Identification ()
{
  ;
}


ostream & operator<< (ostream & ost, Identification & ident)
{
  ident.Print (ost);
  return ost;
}


/*
void Identification :: IdentifySpecialPoints (ARRAY<class SpecialPoint> & points)
{
  ;
}
*/


int Identification :: 
Identifyable (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{
  cout << "Identification::Identifyable called for base-class" << endl;
  return 0;
}

int Identification :: 
Identifyable (const Point<3> & p1, const Point<3> & sp2) const
{
  cout << "Identification::Identifyable called for base-class" << endl;
  return 0;
}


int Identification :: 
IdentifyableCandidate (const SpecialPoint & sp1) const
{
  return 1;
}


int Identification :: 
ShortEdge (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{
  return 0;
}

int Identification :: GetIdentifiedPoint (class Mesh & mesh, int pi)
{
  cout << "Identification::GetIdentifiedPoint called for base-class" << endl;
  return -1;
}

void Identification :: IdentifyPoints (Mesh & mesh)
{
  cout << "Identification::IdentifyPoints called for base-class" << endl;
  ;
}

void Identification :: IdentifyFaces (class Mesh & mesh)
{
  cout << "Identification::IdentifyFaces called for base-class" << endl;
  ;
}

void Identification :: 
BuildSurfaceElements (ARRAY<Segment> & segs,
		      Mesh & mesh, const Surface * surf)
{
  cout << "Identification::BuildSurfaceElements called for base-class" << endl;
  ;
}


void Identification :: 
BuildVolumeElements (ARRAY<class Element2d> & surfels,
			  class Mesh & mesh)
{
  ;
}

void Identification :: 
GetIdentifiedFaces (ARRAY<INDEX_2> & idfaces) const
{
  idfaces.SetSize(0);
  for (int i = 1; i <= identfaces.GetNBags(); i++)
    for (int j = 1; j <= identfaces.GetBagSize(i); j++)
      {
	INDEX_2 i2;
	int val;
	identfaces.GetData (i, j, i2, val);
	idfaces.Append (i2);
      }
}




PeriodicIdentification ::
PeriodicIdentification (int anr,
			const CSGeometry & ageom,
			const Surface * as1,
			const Surface * as2)
  : Identification(anr, ageom)
{
  s1 = as1;
  s2 = as2;
}

PeriodicIdentification :: ~PeriodicIdentification ()
{
  ;
}

/*
void PeriodicIdentification :: IdentifySpecialPoints 
(ARRAY<class SpecialPoint> & points)
{
  int i, j;
  int bestj;
  double bestval, val;

  for (i = 1; i <= points.Size(); i++)
    {
      Point<3> p1 = points.Get(i).p;
      Point<3> hp1 = p1;
      s1->Project (hp1);
      if (Dist (p1, hp1) > 1e-6) continue;

      Vec<3> n1;
      s1->GetNormalVector (p1, n1);
      n1 /= n1.Length();
      if ( fabs(n1 * points.Get(i).v) > 1e-3)
	continue;

      bestval = 1e8;
      bestj = 1;
      for (j = 1; j <= points.Size(); j++)
	{
	  Point<3> p2= points.Get(j).p;
	  Point<3> hp2 = p2;
	  s2->Project (hp2);
	  if (Dist (p2, hp2) > 1e-6) continue;
	  
	  Vec<3> n2;
	  s2->GetNormalVector (p2, n2);
	  n2 /= n2.Length();
	  if ( fabs(n2 * points.Get(j).v) > 1e-3)
	    continue;


	  Vec<3> v(p1, p2);
	  double vl = v.Length();
	  double cl = fabs (v*n1);

	  val = 1 - cl*cl/(vl*vl);

	  val += (points.Get(i).v - points.Get(j).v).Length();

	  if (val < bestval)
	    {
	      bestj = j;
	      bestval = val;
	    }
	}

      (*testout) << "Identify Periodic special points: pi = " 
		 << points.Get(i).p << ", vi = " << points.Get(i).v 
		 << " pj = " << points.Get(bestj).p 
		 << ", vj = " << points.Get(bestj).v 
		 << " bestval = " << bestval << endl;
    }
}
*/

int PeriodicIdentification :: 
Identifyable (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{
  int i;
  double val;
  
  SpecialPoint hsp1 = sp1;
  SpecialPoint hsp2 = sp2;

  for (i = 1; i <= 1; i++)
    {
      //      Swap (hsp1, hsp2);

      if (!s1->PointOnSurface (hsp1.p))
	continue;

      Vec<3> n1;
      n1 = s1->GetNormalVector (hsp1.p);
      n1 /= n1.Length();
      if ( fabs(n1 * hsp1.v) > 1e-3)
	continue;


      if (!s2->PointOnSurface(hsp2.p))
	continue;

      Vec<3> n2;
      n2 = s2->GetNormalVector (hsp2.p);
      n2 /= n2.Length();
      if ( fabs(n2 * hsp2.v) > 1e-3)
	continue;


      Vec<3> v = hsp2.p - hsp1.p;
      double vl = v.Length();
      double cl = fabs (v*n1);
      

      val = 1 - cl*cl/(vl*vl);
      val += (hsp1.v - hsp2.v).Length();
    
      if (val < 1e-3)
	{
	  return 1;
	}
    }

  return 0;
}

int PeriodicIdentification :: 
Identifyable (const Point<3> & p1, const Point<3> & p2) const
{
  return (s1->PointOnSurface (p1) &&
	  s2->PointOnSurface (p2));
}
  



int PeriodicIdentification :: 
GetIdentifiedPoint (class Mesh & mesh,  int pi)
{
  const Surface * sold, *snew;
  const Point<3> & p = mesh.Point (pi);

  if (s1->PointOnSurface (p))
    {
      snew = s2;
    }
  else
    {
      if (s2->PointOnSurface (p))
	{
	  snew = s1;
	}
      else
	{
	  cerr << "GetIdenfifiedPoint: Not possible" << endl;
	  exit (1);
	}    
    }
  
  // project to other surface
  Point<3> hp = p;
  snew->Project (hp);

  int i;
  int newpi = 0;
  for (i = 1; i <= mesh.GetNP(); i++)
    if (Dist2 (mesh.Point(i), hp) < 1e-12)
      {
	newpi = i;
	break;
      }
  if (!newpi)
    newpi = mesh.AddPoint (hp);

  if (snew == s2)
    mesh.GetIdentifications().Add (pi, newpi, nr);
  else
    mesh.GetIdentifications().Add (newpi, pi, nr);
	   
  /* 
  (*testout) << "Identify points(periodic), nr = " << nr << ": " << mesh.Point(pi)
	     << " and " << mesh.Point(newpi) 
	     << ((snew == s2) ? "" : " inverse")
	     << endl;
  */
  return newpi;
}


void PeriodicIdentification :: IdentifyPoints (class Mesh & mesh)
{
  int i, j;
  for (i = 1; i <= mesh.GetNP(); i++)
    {
      Point<3> p = mesh.Point(i);
      if (s1->PointOnSurface (p))
	{
	  Point<3> pp = p;
	  s2->Project (pp);
	  for (j = 1; j <= mesh.GetNP(); j++)
	    if (Dist2(mesh.Point(j), pp) < 1e-6)
	      {
		mesh.GetIdentifications().Add (i, j, nr);
		/*
		(*testout) << "Identify points(periodic:), nr = " << nr << ": "
			   << mesh.Point(i) << " - " << mesh.Point(j) << endl;
		*/
	      }
	}
    }
}


void PeriodicIdentification :: IdentifyFaces (class Mesh & mesh)
{
  int i, j, k, l;
  int fi1, fi2, side;
  for (i = 1; i <= mesh.GetNFD(); i++)
    for (j = 1; j <= mesh.GetNFD(); j++)
      {
	int surfi = mesh.GetFaceDescriptor(i).SurfNr();
	int surfj = mesh.GetFaceDescriptor(j).SurfNr();
	if (surfi == surfj)
	  continue;
	
	if (geom.GetSurface (surfi) != s1 ||
	    geom.GetSurface (surfj) != s2)
	  continue;
	    
	int idok = 1;


	//	(*testout) << "check faces " << i << " and " << j << endl;
	for (side = 1; side <= 2 && idok; side++)
	  {
	    if (side == 1)
	      {
		fi1 = i; 
		fi2 = j;
	      }
	    else
	      {
		fi1 = j;
		fi2 = i;
	      }

	    for (k = 1; k <= mesh.GetNSeg(); k++)
	      {
		const Segment & seg1 = mesh.LineSegment(k);
		if (seg1.si != fi1)
		  continue;

		int foundother = 0;
		for (l = 1; l <= mesh.GetNSeg(); l++)
		  {
		    const Segment & seg2 = mesh.LineSegment(l);
		    if (seg2.si != fi2)
		      continue;
		    
		    //		    (*testout) << "seg1 = " << seg1.p1 << "-" << seg1.p2 << ", seg2 = " << seg2.p1 << "-" << seg2.p2;

		    if (side == 1)
		      {
			if (mesh.GetIdentifications().Get (seg1.p1, seg2.p1) &&
			    mesh.GetIdentifications().Get (seg1.p2, seg2.p2))
			  {
			    foundother = 1;
			    break;
			  }
			
			if (mesh.GetIdentifications().Get (seg1.p1, seg2.p2) &&
			    mesh.GetIdentifications().Get (seg1.p2, seg2.p1))
			  {
			    foundother = 1;
			    break;
			  }
		      }
		    else
		      {
			if (mesh.GetIdentifications().Get (seg2.p1, seg1.p1) &&
			    mesh.GetIdentifications().Get (seg2.p2, seg1.p2))
			  {
			    foundother = 1;
			    break;
			  }
			
			if (mesh.GetIdentifications().Get (seg2.p1, seg1.p2) &&
			    mesh.GetIdentifications().Get (seg2.p2, seg1.p1))
			  {
			    foundother = 1;
			    break;
			  }
		      }
		  }

		if (!foundother)
		  {
		    idok = 0;
		    break;
		  }
	      }
	  }


	if (idok)
	  {
	    // (*testout) << "Identify faces " << i << " and " << j << endl;
	    INDEX_2 fpair(i,j);
	    fpair.Sort();
	    identfaces.Set (fpair, 1);
	  }
      }
}



void PeriodicIdentification :: 
BuildSurfaceElements (ARRAY<Segment> & segs,
		      Mesh & mesh, const Surface * surf)
{
  int i1, i2;
  int found = 0;
  int i, j, k;
  int fother;


  int facei = segs.Get(1).si;
  int surfnr = mesh.GetFaceDescriptor(facei).SurfNr();


  if (geom.GetSurface(surfnr) == s1 ||
      geom.GetSurface(surfnr) == s2)
    {
      //      (*testout) << "surfs found !" << endl;

      for (i = 1; i <= mesh.GetNSE(); i++)
	{
	  const Element2d & sel = mesh.SurfaceElement(i);
	  INDEX_2 fpair (facei, sel.GetIndex());
	  fpair.Sort();
	  if (identfaces.Used (fpair))
	    {
	      found = 1;
	      fother = sel.GetIndex();

	      // copy element
	      Element2d newel(3);
	      newel.SetIndex (facei);
	      for (k = 1; k <= 3; k++)
		{
		  newel.PNum(k) = 
		    GetIdentifiedPoint (mesh, sel.PNum(k));
		}	  

	      Vec<3> nt = Cross (Point<3> (mesh.Point (newel.PNum(2)))-
				 Point<3> (mesh.Point (newel.PNum(1))),
				 Point<3> (mesh.Point (newel.PNum(3)))-
				 Point<3> (mesh.Point (newel.PNum(1))));
	      
	      Vec<3> nsurf;
	      nsurf = geom.GetSurface (surfnr)->GetNormalVector (mesh.Point(newel.PNum(1)));
	      if (nsurf * nt < 0)
		Swap (newel.PNum(2), newel.PNum(3));
				
	      mesh.AddSurfaceElement (newel);
	    }
	}
    }
  
  if (found)
    {
      (*mycout) << " copy face " << facei << " from face " << fother;
      segs.SetSize(0);
    }
}








void PeriodicIdentification :: Print (ostream & ost) const
{
  ost << "Periodic Identifiaction, surfaces: " 
      << s1->Name() << " - " << s2->Name() << endl;
  s1->Print (ost);
  ost << " - ";
  s2->Print (ost);
  ost << endl;
}


void PeriodicIdentification :: GetData (ostream & ost) const
{
  ost << "periodic " << s1->Name() << " " << s2->Name();
}







CloseSurfaceIdentification ::
CloseSurfaceIdentification (int anr,
			    const CSGeometry & ageom,
			    const Surface * as1,
			    const Surface * as2,
			    const TopLevelObject * adomain,
			    const Flags & flags)
  : Identification(anr, ageom)
{
  s1 = as1;
  s2 = as2;
  domain = adomain;
  ref_levels = int (flags.GetNumFlag ("reflevels", 2));
  ref_levels_s1 = int (flags.GetNumFlag ("reflevels1", 0));
  ref_levels_s2 = int (flags.GetNumFlag ("reflevels2", 0));
  slices = flags.GetNumListFlag ("slices");
  // eps_n = 1e-3;
  eps_n = 1e-6;

  dom_surf_valid = 0;
}

CloseSurfaceIdentification :: ~CloseSurfaceIdentification ()
{
  ;
}

void CloseSurfaceIdentification :: Print (ostream & ost) const
{
  ost << "CloseSurface Identifiaction, surfaces: " 
      << s1->Name() << " - " << s2->Name() << endl;
  s1->Print (ost);
  s2->Print (ost);
  ost << endl;
}


void CloseSurfaceIdentification :: GetData (ostream & ost) const
{
  ost << "close surface " << s1->Name() << " " << s2->Name();
}


/*
void CloseSurfaceIdentification :: IdentifySpecialPoints 
(ARRAY<class SpecialPoint> & points)
{
  int i, j;
  int bestj;
  double bestval, val;

  for (i = 1; i <= points.Size(); i++)
    {
      Point<3> p1 = points.Get(i).p;
      Vec<3> n1;

      if (!s1->PointOnSurface (p1))
	continue;

	s1->GetNormalVector (p1, n1);
      n1 /= n1.Length();
      if ( fabs(n1 * points.Get(i).v) > 1e-3)
	continue;

      bestval = 1e8;
      bestj = 1;
      for (j = 1; j <= points.Size(); j++)
	{
	  Point<3> p2= points.Get(j).p;
	  if (!s2->PointOnSurface (p2))
	    continue;
	  
	  Vec<3> n2;
	  s2->GetNormalVector (p2, n2);
	  n2 /= n2.Length();
	  if ( fabs(n2 * points.Get(j).v) > 1e-3)
	    continue;


	  Vec<3> v(p1, p2);
	  double vl = v.Length();
	  double cl = fabs (v*n1);

	  val = 1 - cl*cl/(vl*vl);

	  val += (points.Get(i).v - points.Get(j).v).Length();

	  if (val < bestval)
	    {
	      bestj = j;
	      bestval = val;
	    }
	}

      (*testout) << "Identify close surfaces special points: pi = " 
		 << points.Get(i).p << ", vi = " << points.Get(i).v 
		 << " pj = " << points.Get(bestj).p 
		 << ", vj = " << points.Get(bestj).v 
		 << " bestval = " << bestval << endl;
    }
}
*/

int CloseSurfaceIdentification :: 
Identifyable (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{

  if (!dom_surf_valid)
    {
      const_cast<bool&> (dom_surf_valid) = 1;
      ARRAY<int> & hsurf = const_cast<ARRAY<int>&> (domain_surfaces);

      if (domain)
	{
	  BoxSphere<3> hbox (geom.BoundingBox());
	  geom.GetIndependentSurfaceIndices (domain->GetSolid(), hbox,
					     hsurf);
	}
      else
	{
	  hsurf.SetSize (geom.GetNSurf());
	  for (int j = 0; j < hsurf.Size(); j++)
	    hsurf[j] = j;
	}
    }



  if (!s1->PointOnSurface (sp1.p))
    return 0;
  
  Vec<3> n1 = s1->GetNormalVector (sp1.p);
  n1.Normalize();
  if ( fabs(n1 * sp1.v) > eps_n)
    return 0;
  
  if (!s2->PointOnSurface(sp2.p))
    return 0;
  
  Vec<3> n2 = s2->GetNormalVector (sp2.p);
  n2.Normalize();
  if ( fabs(n2 * sp2.v) > eps_n)
    return 0;
  
  // must have joint surface 
  bool joint = 0;
  //  for (int j = 0; j < geom.GetNSurf(); j++)
  for (int jj = 0; jj < domain_surfaces.Size(); jj++)
    {
      int j = domain_surfaces[jj];
      if (geom.GetSurface(j) -> PointOnSurface(sp1.p) &&
	  geom.GetSurface(j) -> PointOnSurface(sp2.p) )
	{
	  Vec<3> hn1 = geom.GetSurface(j)->GetNormalVector (sp1.p);
	  Vec<3> hn2 = geom.GetSurface(j)->GetNormalVector (sp2.p);
	  
	  if (hn1 * hn2 > 0)
	    {
	      joint = 1;
	      break;
	    }
	}
    }
  if (!joint) return 0;
  
  Vec<3> v = sp2.p - sp1.p;
  double vl = v.Length();
  double cl = fabs (v*n1);
      
  if (cl > (1-eps_n*eps_n) * vl && (sp1.v - sp2.v).Length() < 0.1)
    return 1;

  return 0;
}

int CloseSurfaceIdentification :: 
Identifyable (const Point<3> & p1, const Point<3> & p2) const
{
  return (s1->PointOnSurface (p1) && s2->PointOnSurface (p2));
}
  



int CloseSurfaceIdentification :: 
IdentifyableCandidate (const SpecialPoint & sp1) const
{
  if (s1->PointOnSurface (sp1.p))
    {
      Vec<3> n1;
      n1 = s1->GetNormalVector (sp1.p);
      n1.Normalize();
      if ( fabs(n1 * sp1.v) > eps_n)
	return 0;
      return 1;
    }

  if (s2->PointOnSurface (sp1.p))
    {
      Vec<3> n1;
      n1 = s2->GetNormalVector (sp1.p);
      n1.Normalize();
      if ( fabs(n1 * sp1.v) > eps_n)
	return 0;
      return 1;
    }
  return 0;
}



int CloseSurfaceIdentification :: 
ShortEdge (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{
  if ( (s1->PointOnSurface (sp1.p) && s2->PointOnSurface (sp2.p)) ||
       (s1->PointOnSurface (sp2.p) && s2->PointOnSurface (sp1.p)) )
    {
      return 1;
    }
  return 0;
}



int CloseSurfaceIdentification :: 
GetIdentifiedPoint (class Mesh & mesh,  int pi)
{
  const Surface * sold, *snew;
  const Point<3> & p = mesh.Point (pi);

  ARRAY<int,PointIndex::BASE> identmap(mesh.GetNP());
  mesh.GetIdentifications().GetMap (nr, identmap);
  if (identmap.Get(pi))
    return identmap.Get(pi);

  if (s1->PointOnSurface (p))
    {
      snew = s2;
    }
  else
    {
      if (s2->PointOnSurface (p))
	{
	  snew = s1;
	}
      else
	{
	  (*testout)  << "GetIdenfifiedPoint: Not possible" << endl;
	  (*testout) << "p = " << p << endl;
	  (*testout) << "surf1: ";
	  s1->Print (*testout); 
	  (*testout) << endl;
	  (*testout) << "surf2: ";
	  s2->Print (*testout);
	  (*testout) << endl;

	  cerr << "GetIdenfifiedPoint: Not possible" << endl;
	  exit (1);
	}    
    }
  
  // project to other surface
  Point<3> hp = p;
  snew->Project (hp);

  int i;
  int newpi = 0;
  for (i = 1; i <= mesh.GetNP(); i++)
    if (Dist2 (mesh.Point(i), hp) < 1e-12)
      //    if (Dist2 (mesh.Point(i), hp) < 1 * Dist2 (hp, p))
      {
	newpi = i;
	break;
      }
  if (!newpi)
    newpi = mesh.AddPoint (hp);

  if (snew == s2)
    mesh.GetIdentifications().Add (pi, newpi, nr);
  else
    mesh.GetIdentifications().Add (newpi, pi, nr);
	   
  /* 
  (*testout) << "Identify points(closesurface), nr = " << nr << ": " << mesh.Point(pi)
	     << " and " << mesh.Point(newpi) 
	     << ((snew == s2) ? "" : " inverse")
	     << endl;
  */
  return newpi;
}





void CloseSurfaceIdentification :: IdentifyPoints (Mesh & mesh)
{
  int i, j;
  int i1, i2;

  int np = mesh.GetNP();
  BitArray ons2(np);
  ons2.Clear();
  for (i2 = 1; i2 <= np; i2++)
    if (s2->PointOnSurface (mesh.Point(i2)))
      ons2.Set (i2);
    
  for (i1 = 1; i1 <= np; i1++)
    {
      const Point<3> p1 = mesh.Point(i1);
      if (s1->PointOnSurface (p1))
	{
	  int candi2 = 0;
	  double mindist = 1e10;

	  Vec<3> n1;
	  n1 = s1->GetNormalVector (p1);
	  n1.Normalize();

	  for (i2 = 1; i2 <= np; i2++)
	    {
	      if (i2 == i1)
		continue;
	
	      const Point<3> p2 = mesh.Point(i2);
	      
	      if (!ons2.Test(i2))
		continue;
		  /*
	      if (!s2->PointOnSurface (p2))
		continue;
		  */
	      Vec<3> n = p2 - p1;
	      n.Normalize();
	      
	      
	      bool joint = 0;
	      for (int jj = 0; jj < domain_surfaces.Size(); jj++)
		{
		  int j = domain_surfaces[jj];
		  if (geom.GetSurface(j) -> PointOnSurface(p1) &&
		      geom.GetSurface(j) -> PointOnSurface(p2) )
		    {
		      Vec<3> hn1 = geom.GetSurface(j)->GetNormalVector (p1);
		      Vec<3> hn2 = geom.GetSurface(j)->GetNormalVector (p2);
		      
		      if (hn1 * hn2 > 0)
			{
			  joint = 1;
			  break;
			}
		    }
		}
	      if (!joint) continue;
	      



	      if (fabs (n * n1) > 0.9 &&
		  Dist (p1, p2) < mindist)
		{
		  candi2 = i2;
		  mindist = Dist (p1, p2);
		}
	    }

	  if (candi2)
	    {
	      // (*testout) << "identify points " << p1 << " - " << mesh.Point(candi2) << endl;
	      (*testout) << "Add Identification from CSI2, p1 = " 
			 << mesh[PointIndex(i1)] << ", p2 = " 
			 << mesh[PointIndex(candi2)] << endl;

	      mesh.GetIdentifications().Add (i1, candi2, nr);
	    }
	}
    }
}



void CloseSurfaceIdentification :: IdentifyFaces (class Mesh & mesh)
{
  int i, j, k, l;
  int fi1, fi2, side;

  int s1rep, s2rep;
  for (i = 0; i < geom.GetNSurf(); i++)
    {
      if (geom.GetSurface (i) == s1) 
	s1rep = geom.GetSurfaceClassRepresentant(i);
      if (geom.GetSurface (i) == s2) 
	s2rep = geom.GetSurfaceClassRepresentant(i);
    }

  for (i = 1; i <= mesh.GetNFD(); i++)
    for (j = 1; j <= mesh.GetNFD(); j++)
      {
	int surfi = mesh.GetFaceDescriptor(i).SurfNr();
	int surfj = mesh.GetFaceDescriptor(j).SurfNr();
	if (surfi == surfj)
	  continue;

	if (s1rep != surfi || s2rep != surfj) 
	  continue;

	/*
	if (geom.GetSurface (surfi) != s1 ||
	    geom.GetSurface (surfj) != s2)
	  continue;
	*/
  
	int idok = 1;


	// (*testout) << "check faces " << i << " and " << j << endl;
	for (side = 1; side <= 2 && idok; side++)
	  {
	    if (side == 1)
	      {
		fi1 = i; 
		fi2 = j;
	      }
	    else
	      {
		fi1 = j;
		fi2 = i;
	      }

	    for (k = 1; k <= mesh.GetNSeg(); k++)
	      {
		const Segment & seg1 = mesh.LineSegment(k);
		if (seg1.si != fi1)
		  continue;

		int foundother = 0;
		for (l = 1; l <= mesh.GetNSeg(); l++)
		  {
		    const Segment & seg2 = mesh.LineSegment(l);
		    if (seg2.si != fi2)
		      continue;
		    
		    //		    (*testout) << "seg1 = " << seg1.p1 << "-" << seg1.p2 << ", seg2 = " << seg2.p1 << "-" << seg2.p2;

		    if (side == 1)
		      {
			if (mesh.GetIdentifications().Get (seg1.p1, seg2.p1) &&
			    mesh.GetIdentifications().Get (seg1.p2, seg2.p2))
			  {
			    foundother = 1;
			    break;
			  }
			
			if (mesh.GetIdentifications().Get (seg1.p1, seg2.p2) &&
			    mesh.GetIdentifications().Get (seg1.p2, seg2.p1))
			  {
			    foundother = 1;
			    break;
			  }
		      }
		    else
		      {
			if (mesh.GetIdentifications().Get (seg2.p1, seg1.p1) &&
			    mesh.GetIdentifications().Get (seg2.p2, seg1.p2))
			  {
			    foundother = 1;
			    break;
			  }
			
			if (mesh.GetIdentifications().Get (seg2.p1, seg1.p2) &&
			    mesh.GetIdentifications().Get (seg2.p2, seg1.p1))
			  {
			    foundother = 1;
			    break;
			  }
		      }
		  }

		if (!foundother)
		  {
		    idok = 0;
		    break;
		  }
	      }
	  }


	if (idok)
	  {
	    // (*testout) << "Identify faces " << i << " and " << j << endl;
	    INDEX_2 fpair(i,j);
	    fpair.Sort();
	    identfaces.Set (fpair, 1);
	  }
      }
}



void CloseSurfaceIdentification :: 
BuildSurfaceElements (ARRAY<Segment> & segs,
		      Mesh & mesh, const Surface * surf)
{
  int i1, i2;
  int found = 0, cntquads = 0;
  int i, j, k;

  // insert quad layer:
  for (i1 = 1; i1 <= segs.Size(); i1++)
    for (i2 = 1; i2 < i1; i2++)
      {
	const Segment & s1 = segs.Get(i1);
	const Segment & s2 = segs.Get(i2);
	if ( (mesh.GetIdentifications().Get (s1.p1, s2.p2) == nr &&
	      mesh.GetIdentifications().Get (s1.p2, s2.p1) == nr)    || 
	     (mesh.GetIdentifications().Get (s2.p1, s1.p2) == nr &&
	      mesh.GetIdentifications().Get (s2.p2, s1.p1) == nr)
	     )
	  {
	    Element2d el(4);
	    el.PNum(1) = s1.p1;
	    el.PNum(2) = s1.p2;
	    el.PNum(3) = s2.p1;
	    el.PNum(4) = s2.p2;

	    Vec<3> n = Cross (Point<3> (mesh.Point(el.PNum(2)))-
			      Point<3> (mesh.Point(el.PNum(1))),
			      Point<3> (mesh.Point(el.PNum(4)))-
			      Point<3> (mesh.Point(el.PNum(1))));

	    Vec<3> ns;
	    ns = surf->GetNormalVector (mesh.Point(el.PNum(1)));
	    // (*testout) << "n = " << n << " ns = " << ns << endl;
	    if (n * ns < 0)
	      {
		// (*testout) << "Swap the quad" << endl;
		Swap (el.PNum(1), el.PNum(2));
		Swap (el.PNum(3), el.PNum(4));
	      }
			     
	    mesh.AddSurfaceElement (el);
	    (*testout) << "add rect element: "
		       << mesh.Point (el.PNum(1)) << " - "
		       << mesh.Point (el.PNum(2)) << " - "
		       << mesh.Point (el.PNum(3)) << " - "
		       << mesh.Point (el.PNum(4)) << endl;
	    found = 1;
	    cntquads++;
	  }
      }

  if (found)
    {
      (*mycout) << " insert quad layer of " << cntquads
		<< " elements at face " << segs.Get(1).si << endl;
      segs.SetSize(0);
    }
  else
    {
      BuildSurfaceElements2 (segs, mesh, surf);
    }
     
  /* 
      int fother;
      int facei = segs.Get(1).si;
      int surfnr = mesh.GetFaceDescriptor(facei).SurfNr();

      int foundid = 0;
      for (i = 1; i <= identfaces.GetNBags(); i++)
	for (j = 1; j <= identfaces.GetBagSize(i); j++)
	  {
	    INDEX_2 i2;
	    int data;
	    identfaces.GetData (i, j, i2, data);
	    if (i2.I1() == facei || i2.I2() == facei)
	      foundid = 1;
	  }

      //      (*testout) << "facei = " << facei << ", surfnr = " << surfnr << endl;

      if (foundid)
	{
	  //	  (*testout) << "surfaces found" << endl;
	  // copy surface
	  for (i = 1; i <= mesh.GetNSE(); i++)
	    {
	      const Element2d & sel = mesh.SurfaceElement(i);
	      INDEX_2 fpair (facei, sel.GetIndex());
	      fpair.Sort();
	      if (identfaces.Used (fpair))
		{
		  found = 1;
		  fother = sel.GetIndex();
		  
		  // copy element
		  Element2d newel(3);
		  newel.SetIndex (facei);
		  for (k = 1; k <= 3; k++)
		    {
		      newel.PNum(k) = 
			GetIdentifiedPoint (mesh, sel.PNum(k));
		      //		      cout << "id-point = " << sel.PNum(k) << ", np = " << newel.PNum(k) << endl;
		    }	  
		  
		  Vec<3> nt = Cross (Vec<3> (mesh.Point (newel.PNum(1)), mesh.Point (newel.PNum(2))),
				    Vec<3> (mesh.Point (newel.PNum(1)), mesh.Point (newel.PNum(3))));
		  Vec<3> nsurf;
		  nsurf = geom.GetSurface (surfnr)->GetNormalVector (mesh.Point(newel.PNum(1)));
		  if (nsurf * nt < 0)
		    Swap (newel.PNum(2), newel.PNum(3));
		  
		  mesh.AddSurfaceElement (newel);
		}
	    }
	}
      
      if (found)
	(*mycout) << " copy face " << facei << " from face " << fother;
    }
      
  if (found)
    segs.SetSize(0);
  */
}






void CloseSurfaceIdentification :: 
BuildSurfaceElements2 (ARRAY<Segment> & segs,
		       Mesh & mesh, const Surface * surf)
{
  int i1, i2;
  int found = 0, cntquads = 0;
  int i, j, k;

  int fother;
  int facei = segs.Get(1).si;
  int surfnr = mesh.GetFaceDescriptor(facei).SurfNr();
  
  int foundid = 0;
  for (i = 1; i <= identfaces.GetNBags(); i++)
    for (j = 1; j <= identfaces.GetBagSize(i); j++)
      {
	INDEX_2 i2;
	int data;
	identfaces.GetData (i, j, i2, data);
	if (i2.I1() == facei || i2.I2() == facei)
	  foundid = 1;
      }
  
      //      (*testout) << "facei = " << facei << ", surfnr = " << surfnr << endl;
  
  /*
    if (geom.GetSurface(surfnr) == s1 ||
    geom.GetSurface(surfnr) == s2)
  */
  if (foundid)
    {
      //	  (*testout) << "surfaces found" << endl;
      // copy surface
      for (i = 1; i <= mesh.GetNSE(); i++)
	{
	  const Element2d & sel = mesh.SurfaceElement(i);
	  INDEX_2 fpair (facei, sel.GetIndex());
	  fpair.Sort();
	  if (identfaces.Used (fpair))
	    {
	      found = 1;
	      fother = sel.GetIndex();
	      
	      // copy element
	      Element2d newel(3);
	      newel.SetIndex (facei);
	      for (k = 1; k <= 3; k++)
		{
		  newel.PNum(k) = 
		    GetIdentifiedPoint (mesh, sel.PNum(k));
		  //		      cout << "id-point = " << sel.PNum(k) << ", np = " << newel.PNum(k) << endl;
		}	  
	      
	      Vec<3> nt = Cross (Point<3> (mesh.Point (newel.PNum(2)))- 
				 Point<3> (mesh.Point (newel.PNum(1))),
				 Point<3> (mesh.Point (newel.PNum(3)))- 
				 Point<3> (mesh.Point (newel.PNum(1))));
	      Vec<3> nsurf;
	      nsurf = geom.GetSurface (surfnr)->GetNormalVector (mesh.Point(newel.PNum(1)));
	      if (nsurf * nt < 0)
		Swap (newel.PNum(2), newel.PNum(3));
	      
	      mesh.AddSurfaceElement (newel);
	    }
	}
    }
  
  if (found)
    {
      (*mycout) << " copy face " << facei << " from face " << fother;
      segs.SetSize(0);
    }
}














void CloseSurfaceIdentification :: 
BuildVolumeElements (ARRAY<class Element2d> & surfels,
		     class Mesh & mesh)
{
  ;
}













/*   ***************** Close Edges Identification ********** */



CloseEdgesIdentification ::
CloseEdgesIdentification (int anr,
			  const CSGeometry & ageom,
			  const Surface * afacet,
			  const Surface * as1,
			  const Surface * as2)
  : Identification(anr, ageom)
{
  facet = afacet;
  s1 = as1;
  s2 = as2;
}

CloseEdgesIdentification :: ~CloseEdgesIdentification ()
{
  ;
}

void CloseEdgesIdentification :: Print (ostream & ost) const
{
  ost << "CloseEdges Identifiaction, facet = " 
      << facet->Name() << ", surfaces: " 
      << s1->Name() << " - " << s2->Name() << endl;
  facet->Print (ost);
  s1->Print (ost);
  s2->Print (ost);
  ost << endl;
}


void CloseEdgesIdentification :: GetData (ostream & ost) const
{
  ost << "closeedges " << facet->Name() << " " 
      << s1->Name() << " " << s2->Name();
}


/*
void CloseEdgesIdentification :: IdentifySpecialPoints 
(ARRAY<class SpecialPoint> & points)
{
  int i, j;
  int bestj;
  double bestval, val;

  for (i = 1; i <= points.Size(); i++)
    {
      Point<3> p1 = points.Get(i).p;
      Vec<3> n1;

      if (!s1->PointOnSurface (p1))
	continue;

	s1->GetNormalVector (p1, n1);
      n1 /= n1.Length();
      if ( fabs(n1 * points.Get(i).v) > 1e-3)
	continue;

      bestval = 1e8;
      bestj = 1;
      for (j = 1; j <= points.Size(); j++)
	{
	  Point<3> p2= points.Get(j).p;
	  if (!s2->PointOnSurface (p2))
	    continue;
	  
	  Vec<3> n2;
	  s2->GetNormalVector (p2, n2);
	  n2 /= n2.Length();
	  if ( fabs(n2 * points.Get(j).v) > 1e-3)
	    continue;


	  Vec<3> v(p1, p2);
	  double vl = v.Length();
	  double cl = fabs (v*n1);

	  val = 1 - cl*cl/(vl*vl);

	  val += (points.Get(i).v - points.Get(j).v).Length();

	  if (val < bestval)
	    {
	      bestj = j;
	      bestval = val;
	    }
	}

      (*testout) << "Identify close surfaces special points: pi = " 
		 << points.Get(i).p << ", vi = " << points.Get(i).v 
		 << " pj = " << points.Get(bestj).p 
		 << ", vj = " << points.Get(bestj).v 
		 << " bestval = " << bestval << endl;
    }
}
*/

int CloseEdgesIdentification :: 
Identifyable (const SpecialPoint & sp1, const SpecialPoint & sp2) const
{
  int i;
  double val;
  
  SpecialPoint hsp1 = sp1;
  SpecialPoint hsp2 = sp2;

  for (i = 1; i <= 1; i++)
    {
      if (!s1->PointOnSurface (hsp1.p))
	continue;

      Vec<3> n1;
      n1 = s1->GetNormalVector (hsp1.p);
      n1 /= n1.Length();
      if ( fabs(n1 * hsp1.v) > 1e-3)
	continue;


      if (!s2->PointOnSurface(hsp2.p))
	continue;

      Vec<3> n2;
      n2 = s2->GetNormalVector (hsp2.p);
      n2 /= n2.Length();
      if ( fabs(n2 * hsp2.v) > 1e-3)
	continue;


      Vec<3> v = hsp2.p - hsp1.p;
      double vl = v.Length();
      double cl = fabs (v*n1);
      

      val = 1 - cl*cl/(vl*vl);
      val += (hsp1.v - hsp2.v).Length();
    
      if (val < 1e-3)
	{
	  return 1;
	}
    }

  return 0;
}




void CloseEdgesIdentification :: IdentifyPoints (Mesh & mesh)
{
  int i, j;
  int i1, i2;

  int np = mesh.GetNP();
  for (i1 = 1; i1 <= np; i1++)
    for (i2 = 1; i2 <= np; i2++)
      {
	if (i2 == i1)
	  continue;
	
	const Point<3> p1 = mesh.Point(i1);
	const Point<3> p2 = mesh.Point(i2);
	Point<3> pp1 = p1;
	Point<3> pp2 = p2;
	
	s1->Project (pp1);
	facet->Project (pp1);
	s2->Project (pp2);
	facet->Project (pp2);

	if (Dist (p1, pp1) > 1e-6 || Dist (p2, pp2) > 1e-6)
	  continue;

	Vec<3> n1, nf, t;
	Vec<3> n = p2 - p1;
	n.Normalize();

	n1 = s1->GetNormalVector (p1);
	nf = facet->GetNormalVector (p1);
	t = Cross (n1, nf);
	t /= t.Length();

	if (fabs (n * t) < 0.5)
	  {
	    (*testout) << "close edges identify points " << p1 << " - " << p2 << endl;
	    mesh.GetIdentifications().Add (i1, i2, nr);
	  }
      }
}

void CloseEdgesIdentification :: 
BuildSurfaceElements (ARRAY<Segment> & segs,
		      Mesh & mesh, const Surface * surf)
{
  int i1, i2;
  int found = 0;
  int i, j, k;

  if (surf != facet)
    return;

  for (i1 = 1; i1 <= segs.Size(); i1++)
    for (i2 = 1; i2 < i1; i2++)
      {
	const Segment & s1 = segs.Get(i1);
	const Segment & s2 = segs.Get(i2);
	if (mesh.GetIdentifications().Get (s1.p1, s2.p2) &&
	    mesh.GetIdentifications().Get (s1.p2, s2.p1))
	  {
	    Element2d el(4);
	    el.PNum(1) = s1.p1;
	    el.PNum(2) = s1.p2;
	    el.PNum(3) = s2.p2;
	    el.PNum(4) = s2.p1;

	    Vec<3> n = Cross (Point<3> (mesh.Point(el.PNum(2)))-
			      Point<3> (mesh.Point(el.PNum(1))),
			      Point<3> (mesh.Point(el.PNum(3)))-
			      Point<3> (mesh.Point(el.PNum(1))));
	    Vec<3> ns;
	    ns = surf->GetNormalVector (mesh.Point(el.PNum(1)));
	    (*testout) << "n = " << n << " ns = " << ns << endl;
	    if (n * ns < 0)
	      {
		(*testout) << "Swap the quad" << endl;
		Swap (el.PNum(1), el.PNum(2));
		Swap (el.PNum(3), el.PNum(4));
	      }
			     
	    
	    Swap (el.PNum(3), el.PNum(4));
	    mesh.AddSurfaceElement (el);
	    (*testout) << "add rect element: "
		       << mesh.Point (el.PNum(1)) << " - "
		       << mesh.Point (el.PNum(2)) << " - "
		       << mesh.Point (el.PNum(3)) << " - "
		       << mesh.Point (el.PNum(4)) << endl;
	    found = 1;
	  }
      }

  if (found)
    segs.SetSize(0);
}

}

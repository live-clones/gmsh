#include <mystdlib.h>
#include "meshing.hpp"


namespace netgen
{
//#include "../interface/writeuser.hpp"

  class MarkedTet;
  class MarkedPrism;
  class MarkedTri;
  class MarkedQuad;
  
  typedef MoveableArray<MarkedTet> T_MTETS;
  typedef MoveableArray<MarkedPrism> T_MPRISMS;
  typedef MoveableArray<MarkedTri> T_MTRIS;
  typedef MoveableArray<MarkedQuad> T_MQUADS;

class MarkedTet
{
public:
  /// pnums of tet
  PointIndex pnums[4];
  /// material number
  int matindex;
  /// element marked for refinement
  /// marked = 1: marked by element marker, marked = 2 due to closure
  unsigned int marked:2;
  /// flag of Arnold-Mukherjee algorithm
  unsigned int flagged:1;
  /// tetedge (local coordinates 0..3)
  unsigned int tetedge1:3;
  unsigned int tetedge2:3;
  /// marked edge of faces
  /// face_j : face without node j,
  /// mark_k : edge without node k
  unsigned char faceedges[4];

  bool incorder;
  unsigned int order:6;

  friend ostream & operator<< (ostream & ost, const MarkedTet & mt);
};

class MarkedPrism
{
public:
  /// 6 point numbers
  PointIndex pnums[6];
  /// material number
  int matindex;
  /// marked for refinement
  int marked;
  /// edge without node k (0,1,2)
  int markededge;

  bool incorder;
  unsigned int order:6;
};

class MarkedTri
{
public:
  /// three point numbers
  PointIndex pnums[3];
  /// three geominfos
  PointGeomInfo pgeominfo[3];
  /// marked for refinement
  int marked;
  /// edge without node k
  int markededge;
  /// surface id
  int surfid;

  bool incorder;
  unsigned int order:6;
};

class MarkedQuad
{
public:
  /// point numbers
  PointIndex pnums[4];
  ///
  PointGeomInfo pgeominfo[4];
  /// marked for refinement
  int marked;
  /// surface id
  int surfid;

  bool incorder;
  unsigned int order:6;
};





ostream & operator<< (ostream & ost, const MarkedTet & mt)
{
  int k;
  ost << "MT: " << mt.pnums[0] << " - " << mt.pnums[1] << " - " 
      << mt.pnums[2] << " - " << mt.pnums[3] << endl
      << "marked edge: " << mt.tetedge1 << " - " << mt.tetedge2
      << ", order = " << mt.order << endl;
  for (k = 0; k < 4; k++)
    ost << mt.faceedges[k] << "  ";
  ost << endl;
  return ost;
}




void BTSortEdges (const Mesh & mesh,
		  INDEX_2_CLOSED_HASHTABLE<int> & edgenumber)
{
  cout << "sorting ... " << flush;

  //  if (mesh.PureTetMesh())
  if (1)
    {
      // new, fast version
      
      ARRAY<INDEX_2> edges;
      ARRAY<int> eclasses;
      
      int i, j, k;
      int cntedges = 0;
      int goon;
      int ned;
      
      // enumerate edges:
      for (i = 1; i <= mesh.GetNE(); i++)
	{
	  const Element & el = mesh.VolumeElement (i);
	  static int tetedges[6][2] =
	  { { 1, 2 },
	    { 1, 3 },
	    { 1, 4 },
	    { 2, 3 },
	    { 2, 4 },
            { 3, 4 } } ;
	  static int prismedges[9][2] =
	  { { 1, 2 },
	    { 1, 3 },
	    { 2, 3 },
	    { 4, 5 },
	    { 4, 6 },
	    { 5, 6 },
	    { 1, 4 },
	    { 2, 5 },
            { 3, 6 } };
	  int pyramidedges[6][2] =
	  { { 1, 2 },
	    { 3, 4 },
	    { 1, 5 },
	    { 2, 5 },
	    { 3, 5 },
	    { 4, 5 } };
	  
	  int (*tip)[2];
	  
	  switch (el.GetType())
	    {
	    case TET:
	    case TET10:
	      {
		tip = tetedges;
		ned = 6;
		break;
	      }
	    case PRISM:
	    case PRISM12:
	      {
		tip = prismedges;
		ned = 6;
		break;
	      }
	    case PYRAMID:
	      {
		tip = pyramidedges;
		ned = 6;
		break;
	      }
	    }
	      
	  for (j = 0; j < ned; j++)
	    {
	      INDEX_2 i2(el.PNum(tip[j][0]), el.PNum(tip[j][1]));
	      i2.Sort();
	      if (!edgenumber.Used(i2))
		{
		  cntedges++;
		  edges.Append (i2);
		  edgenumber.Set(i2, cntedges);
		}
	    }
	}
      
      // additional surface edges:
      for (i = 1; i <= mesh.GetNSE(); i++)
	{
	  const Element2d & el = mesh.SurfaceElement (i);
	  static int trigedges[3][2] =
	  { { 1, 2 },
	    { 2, 3 },
	    { 3, 1 } };

	  static int quadedges[4][2] =
	  { { 1, 2 },
	    { 2, 3 },
	    { 3, 4 },
	    { 4, 1 } };


	  int (*tip)[2];
	  
	  switch (el.GetType())
	    {
	    case TRIG:
	    case TRIG6:
	      {
		tip = trigedges;
		ned = 3;
		break;
	      }
	    case QUAD:
	    case QUAD6:
	      {
		tip = quadedges;
		ned = 4;
		break;
	      }
	    default:
	      {
		cerr << "Error: Sort for Bisect, SE has " << el.GetNP() << " points" << endl;
		ned = 0;
	      }
	    }
	      
	  for (j = 0; j < ned; j++)
	    {
	      INDEX_2 i2(el.PNum(tip[j][0]), el.PNum(tip[j][1]));
	      i2.Sort();
	      if (!edgenumber.Used(i2))
		{
		  cntedges++;
		  edges.Append (i2);
		  edgenumber.Set(i2, cntedges);
		}
	    }
	}





      eclasses.SetSize (cntedges);
      for (i = 1; i <= cntedges; i++)
	eclasses.Elem(i) = i;


      // identify edges in element stack
      do
	{
	  goon = 0;
	  for (i = 1; i <= mesh.GetNE(); i++)
	    {
	      const Element & el = mesh.VolumeElement (i);	     
	      
	      if (el.GetType() != PRISM &&
		  el.GetType() != PRISM12 &&
		  el.GetType() != PYRAMID)
		continue;

	      int prismpairs[3][4] =
	      { { 1, 2, 4, 5 },
		{ 2, 3, 5, 6 },
		{ 1, 3, 4, 6 } };
	      
	      int pyramidpairs[3][4] =
	      { { 1, 2, 4, 3 },
		{ 1, 5, 4, 5 },
		{ 2, 5, 3, 5 } };
		      
	      int (*pairs)[4];
	      switch (el.GetType())
		{
		case PRISM:
		case PRISM12:
		  {
		    pairs = prismpairs;
		    break;
		  }
		case PYRAMID:
		  {
		    pairs = pyramidpairs;
		    break;
		  }
		}

	      for (j = 0; j < 3; j++)
		{
		  INDEX_2 e1 (el.PNum(pairs[j][0]), 
			      el.PNum(pairs[j][1]));
		  INDEX_2 e2 (el.PNum(pairs[j][2]), 
			      el.PNum(pairs[j][3]));
		  e1.Sort();
		  e2.Sort();
		      
		  int eclass1 = edgenumber.Get (e1);
		  int eclass2 = edgenumber.Get (e2);

		  //		  (*testout) << "identify edges " << eclass1 << "-" << eclass2 << endl;

		  if (eclasses.Get(eclass1) >
		      eclasses.Get(eclass2))
		    {
		      eclasses.Elem(eclass1) = 
			eclasses.Get(eclass2);
		      goon = 1;
		    }
		  if (eclasses.Get(eclass2) >
		      eclasses.Get(eclass1))
		    {
		      eclasses.Elem(eclass2) = 
			eclasses.Get(eclass1);
		      goon = 1;
		    }
		}
	    }
	}
      while (goon);

      /*      
      for (i = 1; i <= cntedges; i++)
	{
	  (*testout) << "edge " << i << ": " 
		     << edges.Get(i).I1() << "-" << edges.Get(i).I2()
		     << ", class = " << eclasses.Get(i) << endl;
	}
      */      
      // compute classlength:
      ARRAY<double> edgelength(cntedges);
      for (i = 1; i <= cntedges; i++)
	edgelength.Elem(i) = 1e20;

      for (i = 1; i <= cntedges; i++)
	{
	  INDEX_2 edge = edges.Get(i);
	  double elen = Dist (mesh.Point(edge.I1()),
			      mesh.Point(edge.I2()));
	  edgelength.Elem (i) = elen;
	}

      /*
      for (i = 1; i <= mesh.GetNE(); i++)
	{
	  const Element & el = mesh.VolumeElement (i);
	  
	  if (el.GetType() == TET)
	    {
	      for (j = 1; j <= 3; j++)
		for (k = j+1; k <= 4; k++)
		  {
		    INDEX_2 i2(el.PNum(j), el.PNum(k));
		    i2.Sort();
		    
		    int enr = edgenumber.Get(i2);
		    double elen = Dist (mesh.Point (i2.I1()), mesh.Point (i2.I2()));
		    if (elen < edgelength.Get(enr))
		      edgelength.Set (enr, elen);
		  }
	    }
	  else if (el.GetType() == PRISM)
	    {
	      for (j = 1; j <= 3; j++)
		{
		  k = (j % 3) + 1;
		  
		  INDEX_2 i2(el.PNum(j), el.PNum(k));
		  i2.Sort();
		  
		  int enr = edgenumber.Get(i2);
		  double elen = Dist (mesh.Point (i2.I1()), mesh.Point (i2.I2()));
		  if (elen < edgelength.Get(enr))
		    edgelength.Set (enr, elen);
		  
		  i2 = INDEX_2(el.PNum(j+3), el.PNum(k+3));
		  i2.Sort();
		  
		  enr = edgenumber.Get(i2);
		  elen = Dist (mesh.Point (i2.I1()), mesh.Point (i2.I2()));
		  if (elen < edgelength.Get(enr))
		    edgelength.Set (enr, elen);
		  
		  if (!edgenumber.Used(i2))
		    {
		      cntedges++;
		      edgenumber.Set(i2, cntedges);
		    }
		  i2 = INDEX_2(el.PNum(j), el.PNum(j+3));
		  i2.Sort();
		  
		  enr = edgenumber.Get(i2);
		  elen = Dist (mesh.Point (i2.I1()), mesh.Point (i2.I2()));
		  if (elen < edgelength.Get(enr))
		    edgelength.Set (enr, elen);
		}
	    }
	}
      */

      
      for (i = 1; i <= cntedges; i++)
	{
	  if (eclasses.Get(i) != i)
	    {
	      if (edgelength.Get(i) < edgelength.Get(eclasses.Get(i)))
		edgelength.Elem(eclasses.Get(i)) = edgelength.Get(i);
	      edgelength.Elem(i) = 1e20;
	    }
	}


      TABLE<int> eclasstab(cntedges);
      for (i = 1; i <= cntedges; i++)
	eclasstab.Add1 (eclasses.Get(i), i);


      // sort edges:
      ARRAY<int> sorted(cntedges);
      
      QickSort (edgelength, sorted);
      
      int cnt = 0;
      for (i = 1; i <= cntedges; i++)
	{
	  int ii = sorted.Get(i);
	  for (j = 1; j <= eclasstab.EntrySize(ii); j++)
	    {
	      cnt++;
	      edgenumber.Set (edges.Get(eclasstab.Get(ii, j)), cnt); 
	    }
	}
    }

  else
    
    {
      // old version
      
      int i, j, k;
      int cnt = 0;
      int found;
      double len2, maxlen2;
      INDEX_2 ep;
      
      // sort edges by length, parallel edges (on prisms)
      // are added in blocks
      
      do
	{
	  found = 0;
	  maxlen2 = 1e30;
	  
	  for (i = 1; i <= mesh.GetNE(); i++)
	    {
	      const Element & el = mesh.VolumeElement (i);
	      int ned;
	      int tetedges[6][2] =
	      { { 1, 2 },
		{ 1, 3 },
		{ 1, 4 },
		{ 2, 3 },
		{ 2, 4 },
		{ 3, 4 } };
	      int prismedges[6][2] =
	      { { 1, 2 },
		{ 1, 3 },
		{ 2, 4 },
		{ 4, 5 },
		{ 4, 6 },
		{ 5, 6 } };
	      int pyramidedges[6][2] =
	      { { 1, 2 },
		{ 3, 4 },
		{ 1, 5 },
		{ 2, 5 },
		{ 3, 5 },
		{ 4, 5 } };

	      int (*tip)[2];

	      switch (el.GetType())
		{
		case TET:
		  {
		    tip = tetedges;
		    ned = 6;
		    break;
		  }
		case PRISM:
		  {
		    tip = prismedges;
		    ned = 6;
		    break;
		  }
		case PYRAMID:
		  {
		    tip = pyramidedges;
		    ned = 6;
		    break;
		  }
		}
	      
	      for (j = 0; j < ned; j++)
		{
		  INDEX_2 i2(el.PNum(tip[j][0]), el.PNum(tip[j][1]));
		  i2.Sort();
		  if (!edgenumber.Used(i2))
		    {
		      len2 = Dist (mesh.Point (i2.I1()),
				   mesh.Point (i2.I2()));
		      if (len2 < maxlen2)
			{
			  maxlen2 = len2;
			  ep = i2;
			  found = 1;
			}
		    }
		}
	    }
	  if (found)
	    {
	      cnt++;
	      edgenumber.Set (ep, cnt);
	      
	      
	      // find connected edges:
	      int goon = 0;
	      do
		{
		  goon = 0;
		  for (i = 1; i <= mesh.GetNE(); i++)
		    {
		      const Element & el = mesh.VolumeElement (i);	      
		      if (el.GetNP() != 6) continue;

		      int prismpairs[3][4] =
		      { { 1, 2, 4, 5 },
			{ 2, 3, 5, 6 },
			{ 1, 3, 4, 6 } };

		      int pyramidpairs[3][4] =
		      { { 1, 2, 4, 3 },
			{ 1, 5, 4, 5 },
			{ 2, 5, 3, 5 } };
		      
		      int (*pairs)[4];
		      switch (el.GetType())
			{
			case PRISM:
			  {
			    pairs = prismpairs;
			    break;
			  }
			case PYRAMID:
			  {
			    pairs = pyramidpairs;
			    break;
			  }
			}

		      for (j = 0; j < 3; j++)
			{
			  INDEX_2 e1 (el.PNum(pairs[j][0]), 
				      el.PNum(pairs[j][1]));
			  INDEX_2 e2 (el.PNum(pairs[j][2]), 
				      el.PNum(pairs[j][3]));
			  e1.Sort();
			  e2.Sort();
			  
			  int used1 = edgenumber.Used (e1);
			  int used2 = edgenumber.Used (e2);
			  
			  if (used1 && !used2)
			    {
			      cnt++;
			      edgenumber.Set (e2, cnt);
			      goon = 1;
			    }
			  if (used2 && !used1)
			    {
			      cnt++;
			      edgenumber.Set (e1, cnt);
			      goon = 1;
			    }
			}
		    }
		}
	      while (goon);
	    }
	}
      while (found);
    }
}




void BTDefineMarkedTet (const Element & el,
			INDEX_2_CLOSED_HASHTABLE<int> & edgenumber,
			MarkedTet & mt)
{
  int i, j, k;
  for (i = 0; i < 4; i++)
    mt.pnums[i] = el[i];

  mt.marked = 0;
  mt.flagged = 0;

  mt.incorder = 0;
  mt.order = 1;
  
  int val = 0;
  // find marked edge of tet:
  for (i = 0; i < 3; i++)
    for (j = i+1; j < 4; j++)
      {
	INDEX_2 i2(mt.pnums[i], mt.pnums[j]);
	i2.Sort();
	int hval = edgenumber.Get(i2);
	if (hval > val)
	  {
	    val = hval;
	    mt.tetedge1 = i;
	    mt.tetedge2 = j;
	  }
      }


  // find marked edges of faces:
  for (k = 0; k < 4; k++)
    {
      val = 0;
      for (i = 0; i < 3; i++)
	for (j = i+1; j < 4; j++)
	  if (i != k && j != k)
	    {
	      INDEX_2 i2(mt.pnums[i], mt.pnums[j]);
	      i2.Sort();
	      int hval = edgenumber.Get(i2);
	      if (hval > val)
		{
		  val = hval;
		  mt.faceedges[k] = 6 - k - i - j;
		}
	    }
    }
}




void BTDefineMarkedPrism (const Element & el,
			  INDEX_2_CLOSED_HASHTABLE<int> & edgenumber,
			  MarkedPrism & mp)
{
  int i, j, k;

  if (el.GetType() == PRISM ||
      el.GetType() == PRISM12)
    {
      for (i = 0; i < 6; i++)
	mp.pnums[i] = el[i];
    }
  else if (el.GetType() == PYRAMID)
    {
      static int map[6] = 
	{ 1, 2, 5, 4, 3, 5 };
      for (i = 0; i < 6; i++)
	mp.pnums[i] = el.PNum(map[i]);
    }
  else if (el.GetType() == TET ||
	   el.GetType() == TET10)
    {
      static int map[6] = 
      { 1, 4, 3, 2, 4, 3 };
      for (i = 0; i < 6; i++)
	mp.pnums[i] = el.PNum(map[i]);
      
    }
  else
    {
      PrintSysError ("Define marked prism called for non-prism and non-pyramid");
    }
  


  mp.marked = 0;

  mp.incorder = 0;
  mp.order = 1;

  int val = 0;
  for (i = 0; i < 2; i++)
    for (j = i+1; j < 3; j++)
      {
	INDEX_2 i2(mp.pnums[i], mp.pnums[j]);
	i2.Sort();
	int hval = edgenumber.Get(i2);
	if (hval > val)
	  {
	    val = hval;
	    mp.markededge = 3 - i - j;
	  }
      }
}






void BTDefineMarkedTri (const Element2d & el,
			INDEX_2_CLOSED_HASHTABLE<int> & edgenumber,
			MarkedTri & mt)
{
  int i, j, k;
  for (i = 0; i < 3; i++)
    {
      mt.pnums[i] = el[i];
      mt.pgeominfo[i] = el.GeomInfoPi (i+1);
    }

  mt.marked = 0;
  mt.surfid = el.GetIndex();

  mt.incorder = 0;
  mt.order = 1;

  int val = 0;
  for (i = 0; i < 2; i++)
    for (j = i+1; j < 3; j++)
      {
	INDEX_2 i2(mt.pnums[i], mt.pnums[j]);
	i2.Sort();
	int hval = edgenumber.Get(i2);
	if (hval > val)
	  {
	    val = hval;
	    mt.markededge = 3 - i - j;
	  }
      }
}





void BTDefineMarkedQuad (const Element2d & el,
			 INDEX_2_CLOSED_HASHTABLE<int> & edgenumber,
			 MarkedQuad & mq)
{
  int i, j, k;
  for (i = 0; i < 4; i++)
    mq.pnums[i] = el[i];
  Swap (mq.pnums[2], mq.pnums[3]);

  mq.marked = 0;
  mq.surfid = el.GetIndex();
}




// mark elements due to local h
int BTMarkTets (T_MTETS & mtets,
		T_MPRISMS & mprisms,
		const Mesh & mesh)
{
  int i, j, k;
  int step;

  int marked = 0;

  int np = mesh.GetNP();
  Vector hv(np);
  for (i = 1; i <= np; i++)
    hv.Elem(i) = mesh.GetH (mesh.Point(i));

  double hfac = 1;
  
  for (step = 1; step <= 2; step++)
    {
      for (i = 1; i <= mtets.Size(); i++)
	{
	  double h = 0;
	  
	  for (j = 0; j < 3; j++)
	    for (k = j+1; k < 4; k++)
	      {
		const Point3d & p1 = mesh.Point (mtets.Get(i).pnums[j]);
		const Point3d & p2 = mesh.Point (mtets.Get(i).pnums[k]);
		double hh = Dist2 (p1, p2);
		if (hh > h) h = hh;
	      }
	  h = sqrt (h);
	  
	  double hshould = 1e10;
	  for (j = 0; j < 4; j++)
	    {
	      double hi = hv.Get (mtets.Get(i).pnums[j]);
	      if (hi < hshould)
		hshould = hi;
	    }
	  
	
	  if (step == 1)
	    {
	      if (h / hshould > hfac)
		hfac = h / hshould;
	    }
	  else
	    {
	      if (h > hshould * hfac)
		{
		  mtets.Elem(i).marked = 1;
		  marked = 1;
		}
	      else
		mtets.Elem(i).marked = 0;
	    }
	  
	}
      for (i = 1; i <= mprisms.Size(); i++)
	{
	  double h = 0;
	  
	  for (j = 0; j < 2; j++)
	    for (k = j+1; k < 3; k++)
	      {
		const Point3d & p1 = mesh.Point (mprisms.Get(i).pnums[j]);
		const Point3d & p2 = mesh.Point (mprisms.Get(i).pnums[k]);
		double hh = Dist2 (p1, p2);
		if (hh > h) h = hh;
	      }
	  h = sqrt (h);
	  
	  double hshould = 1e10;
	  for (j = 0; j < 6; j++)
	    {
	      double hi = hv.Get (mprisms.Get(i).pnums[j]);
	      if (hi < hshould)
		hshould = hi;
	    }
	  
	
	  if (step == 1)
	    {
	      if (h / hshould > hfac)
		hfac = h / hshould;
	    }
	  else
	    {
	      if (h > hshould * hfac)
		{
		  mprisms.Elem(i).marked = 1;
		  marked = 1;
		}
	      else
		mprisms.Elem(i).marked = 0;
	    }
	  
	}



      if (step == 1)
	{
	  if (hfac > 2)
	    hfac /= 2;
	  else
	    hfac = 1;
	}

    }
  return marked;
}














void BTBisectTet (const MarkedTet & oldtet, int newp, 
		  MarkedTet & newtet1, MarkedTet & newtet2)
{
  int i, j, k;
  
  
  // points vis a vis from tet-edge
  int vis1, vis2;
  vis1 = 0;
  while (vis1 == oldtet.tetedge1 || vis1 == oldtet.tetedge2)
    vis1++;
  vis2 = 6 - vis1 - oldtet.tetedge1 - oldtet.tetedge2;


  // is tet of type P ?
  int istypep = 0;
  for (i = 0; i < 4; i++)
    {
      int cnt = 0;
      for (j = 0; j < 4; j++)
	if (oldtet.faceedges[j] == i)
	  cnt++;
      if (cnt == 3)
	istypep = 1;
    }


  
  for (i = 0; i < 4; i++)
    {
      newtet1.pnums[i] = oldtet.pnums[i];
      newtet2.pnums[i] = oldtet.pnums[i];
    }
  newtet1.flagged = istypep && !oldtet.flagged;
  newtet2.flagged = istypep && !oldtet.flagged;

  int nm = oldtet.marked - 1;
  if (nm < 0) nm = 0;
  newtet1.marked = nm;
  newtet2.marked = nm;


  for (i = 0; i < 4; i++)
    {
      if (i == oldtet.tetedge1)
	{
	  newtet2.pnums[i] = newp;
	  newtet2.faceedges[i] = oldtet.faceedges[i];  // inherited face
	  newtet2.faceedges[vis1] = i;        // cut faces
	  newtet2.faceedges[vis2] = i;

	  j = 0;
	  while (j == i || j == oldtet.faceedges[i])
	    j++;
	  k = 6 - i - oldtet.faceedges[i] - j;
	  newtet2.tetedge1 = j;                        // tet-edge
	  newtet2.tetedge2 = k;         

	  // new face:
	  if (istypep && oldtet.flagged)
	    newtet2.faceedges[oldtet.tetedge2] = 
	      6 - oldtet.tetedge1 - j - k;
	  else
	    newtet2.faceedges[oldtet.tetedge2] = oldtet.tetedge1;
	}

      if (i == oldtet.tetedge2)
	{
	  newtet1.pnums[i] = newp;
	  newtet1.faceedges[i] = oldtet.faceedges[i];  // inherited face
	  newtet1.faceedges[vis1] = i;
	  newtet1.faceedges[vis2] = i;
	  j = 0;
	  while (j == i || j == oldtet.faceedges[i])
	    j++;
	  k = 6 - i - oldtet.faceedges[i] - j;
	  newtet1.tetedge1 = j;        
	  newtet1.tetedge2 = k;

	  // new face:
	  if (istypep && oldtet.flagged)
	    newtet1.faceedges[oldtet.tetedge1] = 
	      6 - oldtet.tetedge2 - j - k;
	  else
	    newtet1.faceedges[oldtet.tetedge1] = oldtet.tetedge2;
	}
    }

  newtet1.matindex = oldtet.matindex;
  newtet2.matindex = oldtet.matindex;
  newtet1.incorder = 0;
  newtet1.order = oldtet.order;
  newtet2.incorder = 0;
  newtet2.order = oldtet.order;
}




void BTBisectPrism (const MarkedPrism & oldprism, int newp1, int newp2,
		    MarkedPrism & newprism1, MarkedPrism & newprism2)
{
  int i, j, k;

  for (i = 0; i < 6; i++)
    {
      newprism1.pnums[i] = oldprism.pnums[i];
      newprism2.pnums[i] = oldprism.pnums[i];
    }  

  int pe1, pe2;
  pe1 = 0;
  if (pe1 == oldprism.markededge)
    pe1++;
  pe2 = 3 - oldprism.markededge - pe1;

  newprism1.pnums[pe2] = newp1;
  newprism1.pnums[pe2+3] = newp2;
  newprism1.markededge = pe2;
  newprism2.pnums[pe1] = newp1;
  newprism2.pnums[pe1+3] = newp2;
  newprism2.markededge = pe1;

  newprism1.matindex = oldprism.matindex;
  newprism2.matindex = oldprism.matindex;

  int nm = oldprism.marked - 1;
  if (nm < 0) nm = 0;
  newprism1.marked = nm;
  newprism2.marked = nm;

  newprism1.incorder = 0;
  newprism1.order = oldprism.order;
  newprism2.incorder = 0;
  newprism2.order = oldprism.order;
}



void BTBisectTri (const MarkedTri & oldtri, int newp, const PointGeomInfo & newpgi,
		  MarkedTri & newtri1, MarkedTri & newtri2)
{
  int i, j, k;

  for (i = 0; i < 3; i++)
    {
      newtri1.pnums[i] = oldtri.pnums[i];
      newtri1.pgeominfo[i] = oldtri.pgeominfo[i];
      newtri2.pnums[i] = oldtri.pnums[i];
      newtri2.pgeominfo[i] = oldtri.pgeominfo[i];
    }  

  int pe1, pe2;
  pe1 = 0;
  if (pe1 == oldtri.markededge)
    pe1++;
  pe2 = 3 - oldtri.markededge - pe1;

  newtri1.pnums[pe2] = newp;
  newtri1.pgeominfo[pe2] = newpgi;
  newtri1.markededge = pe2;

  newtri2.pnums[pe1] = newp;
  newtri2.pgeominfo[pe1] = newpgi;
  newtri2.markededge = pe1;

  newtri1.surfid = oldtri.surfid;
  newtri2.surfid = oldtri.surfid;

  int nm = oldtri.marked - 1;
  if (nm < 0) nm = 0;
  newtri1.marked = nm;
  newtri2.marked = nm;

  newtri1.incorder = 0;
  newtri1.order = oldtri.order;
  newtri2.incorder = 0;
  newtri2.order = oldtri.order;
}


void BTBisectQuad (const MarkedQuad & oldquad, 
		   int newp1, const PointGeomInfo & npgi1, 
		   int newp2, const PointGeomInfo & npgi2, 
		   MarkedQuad & newquad1, MarkedQuad & newquad2)
{
  int i, j, k;

  for (i = 0; i < 4; i++)
    {
      newquad1.pnums[i] = oldquad.pnums[i];
      newquad1.pgeominfo[i] = oldquad.pgeominfo[i];
      newquad2.pnums[i] = oldquad.pnums[i];
      newquad2.pgeominfo[i] = oldquad.pgeominfo[i];
    }  

  newquad1.pnums[1] = newp1;
  newquad1.pgeominfo[1] = npgi1;
  newquad1.pnums[3] = newp2;
  newquad1.pgeominfo[3] = npgi2;

  newquad2.pnums[0] = newp1;
  newquad2.pgeominfo[0] = npgi1;
  newquad2.pnums[2] = newp2;
  newquad2.pgeominfo[2] = npgi2;

  newquad1.surfid = oldquad.surfid;
  newquad2.surfid = oldquad.surfid;


  int nm = oldquad.marked - 1;
  if (nm < 0) nm = 0;

  newquad1.marked = nm;
  newquad2.marked = nm;
}




int MarkHangingTets (T_MTETS & mtets, 
		     const INDEX_2_CLOSED_HASHTABLE<int> & cutedges)
{
  int i, j, k;

  int hanging = 0;
  for (i = 1; i <= mtets.Size(); i++)
    {
      MarkedTet & teti = mtets.Elem(i);

      if (teti.marked)
	{
	  hanging = 1;
	  continue;
	}

      for (j = 0; j < 3; j++)
	for (k = j+1; k < 4; k++)
	  {
	    INDEX_2 edge(teti.pnums[j],
			 teti.pnums[k]);
	    edge.Sort();
	    if (cutedges.Used (edge))
	      {
		teti.marked = 1;
		hanging = 1;
	      }
	  }
    }
  return hanging;
}



int MarkHangingPrisms (T_MPRISMS & mprisms, 
		       const INDEX_2_CLOSED_HASHTABLE<int> & cutedges)
{
  int i, j, k;

  int hanging = 0;
  for (i = 1; i <= mprisms.Size(); i++)
    {
      if (mprisms.Elem(i).marked)
	{
	  hanging = 1;
	  continue;
	}

      for (j = 0; j < 2; j++)
	for (k = j+1; k < 3; k++)
	  {
	    INDEX_2 edge1(mprisms.Get(i).pnums[j],
			  mprisms.Get(i).pnums[k]);
	    INDEX_2 edge2(mprisms.Get(i).pnums[j+3],
			  mprisms.Get(i).pnums[k+3]);
	    edge1.Sort();
	    edge2.Sort();
	    if (cutedges.Used (edge1) ||
		cutedges.Used (edge2))
	      {
		mprisms.Elem(i).marked = 1;
		hanging = 1;
	      }
	  }
    }
  return hanging;
}



int MarkHangingTris (T_MTRIS & mtris, 
		     const INDEX_2_CLOSED_HASHTABLE<int> & cutedges)
{
  int i, j, k;

  int hanging = 0;
  for (i = 1; i <= mtris.Size(); i++)
    {
      if (mtris.Get(i).marked)
	{
	  hanging = 1;
	  continue;
	}
      for (j = 0; j < 2; j++)
	for (k = j+1; k < 3; k++)
	  {
	    INDEX_2 edge(mtris.Get(i).pnums[j],
			 mtris.Get(i).pnums[k]);
	    edge.Sort();
	    if (cutedges.Used (edge))
	      {
		mtris.Elem(i).marked = 1;
		hanging = 1;
	      }
	  }
    }
  return hanging;
}



int MarkHangingQuads (T_MQUADS & mquads, 
		      const INDEX_2_CLOSED_HASHTABLE<int> & cutedges)
{
  int i;

  int hanging = 0;
  for (i = 1; i <= mquads.Size(); i++)
    {
      if (mquads.Elem(i).marked)
	{
	  hanging = 1;
	  continue;
	}

      INDEX_2 edge1(mquads.Get(i).pnums[0],
		    mquads.Get(i).pnums[1]);
      INDEX_2 edge2(mquads.Get(i).pnums[2],
		    mquads.Get(i).pnums[3]);
      edge1.Sort();
      edge2.Sort();
      if (cutedges.Used (edge1) ||
	  cutedges.Used (edge2))
	{
	  mquads.Elem(i).marked = 1;
	  hanging = 1;
	}
    
    }
  return hanging;
}



void ConnectToNodeRec (int node, int tonode, 
		       const TABLE<int> & conto, ARRAY<int> & connecttonode)
{
  int i, n2;
  //  (*testout) << "connect " << node << " to " << tonode << endl;
  for (i = 1; i <= conto.EntrySize(node); i++)
    {
      n2 = conto.Get(node, i);
      if (!connecttonode.Get(n2))
	{
	  connecttonode.Elem(n2) = tonode;
	  ConnectToNodeRec (n2, tonode, conto, connecttonode);
	}
    }
}




T_MTETS mtets;
T_MPRISMS mprisms;
T_MTRIS mtris;
T_MQUADS mquads;



void BisectTetsCopyMesh (Mesh & mesh, const class CSGeometry *,
			 BisectionOptions & opt)
{
  mtets.SetName ("bisection, tets");
  mprisms.SetName ("bisection, prisms");
  mtris.SetName ("bisection, trigs");
  mquads.SetName ("bisection, quads");

  int np = mesh.GetNP();
  int ne = mesh.GetNE();
  int nse = mesh.GetNSE();
  int i, j, k, l, m;

  /*
  if (mtets.Size() + mprisms.Size() == mesh.GetNE())
    return;
  */

  mtets.SetSize(0);
  mprisms.SetSize(0);
  mtris.SetSize(0);
  mquads.SetSize(0);


  INDEX_2_HASHTABLE<int> shortedges(100);
  for (i = 1; i <= ne; i++)
    {
      const Element & el = mesh.VolumeElement(i);
      if (el.GetType() == PRISM ||
	  el.GetType() == PRISM12)
	{
	  for (j = 1; j <= 3; j++)
	    {
	      INDEX_2 se(el.PNum(j), el.PNum(j+3));
	      se.Sort();
	      shortedges.Set (se, 1);
	    }
	}
    }



  // INDEX_2_HASHTABLE<int> edgenumber(np);
  INDEX_2_CLOSED_HASHTABLE<int> edgenumber(9*ne+4*nse);  

  BTSortEdges (mesh, edgenumber);
  for (i = 1; i <= ne; i++)
    {
      const Element & el = mesh.VolumeElement(i);
	  
      switch (el.GetType())
	{
	case TET:
	case TET10:
	  {
	    // if tet has short edge, it is handled as degenerated prism

	    int foundse = 0;
	    for (j = 1; j <= 3; j++)
	      for (k = j+1; k <= 4; k++)
		{
		  INDEX_2 se(el.PNum(j), el.PNum(k));
		  se.Sort();
		  if (shortedges.Used (se))
		    {
		      //		      cout << "tet converted to prism" << endl;

		      foundse = 1;
		      int p3 = 1;
		      while (p3 == j || p3 == k)
			p3++;
		      int p4 = 10 - j - k - p3;

		      // even permutation ?
		      int pi[4];
		      pi[0] = j;
		      pi[1] = k;
		      pi[2] = p3;
		      pi[3] = p4;
		      int cnt = 0;
		      for (l = 1; l <= 4; l++)
			for (m = 0; m < 3; m++)
			  if (pi[m] > pi[m+1])
			    {
			      Swap (pi[m], pi[m+1]);
			      cnt++;
			    }
		      if (cnt % 2)
			Swap (p3, p4);

		      Element hel = el;
		      hel.PNum(1) = el.PNum(j);
		      hel.PNum(2) = el.PNum(k);
		      hel.PNum(3) = el.PNum(p3);
		      hel.PNum(4) = el.PNum(p4);

		      MarkedPrism mp;
		      BTDefineMarkedPrism (hel, edgenumber, mp);
		      mp.matindex = el.GetIndex();
		      mprisms.Append (mp);
		    }
		}
	    if (!foundse)
	      {
		MarkedTet mt;
		BTDefineMarkedTet (el, edgenumber, mt);
		mt.matindex = el.GetIndex();
		mtets.Append (mt);
	      }
	    break;
	  }
	case PYRAMID:
	  {
	    // eventually rotate
	    MarkedPrism mp;
	    
	    INDEX_2 se(el.PNum(1), el.PNum(2));
	    se.Sort();
	    if (shortedges.Used (se))
	      {
		Element hel = el;
		hel.PNum(1) = el.PNum(2);
		hel.PNum(2) = el.PNum(3);
		hel.PNum(3) = el.PNum(4);
		hel.PNum(4) = el.PNum(1);
		BTDefineMarkedPrism (hel, edgenumber, mp);
	      }
	    else
	      {
		BTDefineMarkedPrism (el, edgenumber, mp);
	      }

	    mp.matindex = el.GetIndex();
	    mprisms.Append (mp);
	    break;
	  }
	case PRISM:
	case PRISM12:
	  {
	    MarkedPrism mp;
	    BTDefineMarkedPrism (el, edgenumber, mp);
	    mp.matindex = el.GetIndex();
	    mprisms.Append (mp);
	    break;
	  }
	}
    }

  for (i = 1; i <= nse; i++)
    {
      const Element2d & el = mesh.SurfaceElement(i);
      if (el.GetType() == TRIG ||
	  el.GetType() == TRIG6)
	{
	  MarkedTri mt;
	  BTDefineMarkedTri (el, edgenumber, mt);
	  mtris.Append (mt);
	}
      else
	{
	  MarkedQuad mq;
	  BTDefineMarkedQuad (el, edgenumber, mq);
	  mquads.Append (mq);
	}
    }



  mesh.mlparentelement.SetSize(ne);
  for (i = 1; i <= ne; i++)
    mesh.mlparentelement.Elem(i) = 0;
  mesh.mlparentsurfaceelement.SetSize(nse);
  for (i = 1; i <= nse; i++)
    mesh.mlparentsurfaceelement.Elem(i) = 0;


  cout << "copied " << mtets.Size() << " tets, " << mtris.Size() << " trigs" << endl;
}


void Refinement :: Bisect (Mesh & mesh, 
			   BisectionOptions & opt)
{
  cout << "Mesh bisection" << endl;

  if (mesh.mglevels == 1)
    BisectTetsCopyMesh(mesh, NULL, opt);

  mesh.ComputeNVertices();
  
  int np = mesh.GetNV();
  mesh.SetNP(np);

  // int ne = mesh.GetNE();
  // int nse = mesh.GetNSE();
  int i, j, l;

  // int initnp = np;
  //  int maxsteps = 3;

  mesh.mglevels++;

  /*
  if (opt.refinementfilename || opt.usemarkedelements)
    maxsteps = 3;
  */



  if (opt.refine_p)
    {
      int ne = mesh.GetNE();
      int nse = mesh.GetNSE();
      int ii = 0;
      for (ElementIndex ei = 0; ei < ne; ei++)
        if (mesh[ei].TestRefinementFlag())
	  mesh[ei].SetOrder (mesh[ei].GetOrder()+1);

      for (SurfaceElementIndex sei = 0; sei < nse; sei++)
        if (mesh[sei].TestRefinementFlag())
	  mesh[sei].SetOrder (mesh[sei].GetOrder()+1);


      ARRAY<int,PointIndex::BASE> v_order (mesh.GetNP());
      v_order = 0;

      for (ElementIndex ei = 0; ei < ne; ei++)
	for (j = 0; j < mesh[ei].GetNP(); j++)
	  if (mesh[ei].GetOrder() > v_order[mesh[ei][j]])
	    v_order[mesh[ei][j]] = mesh[ei].GetOrder();

      for (SurfaceElementIndex sei = 0; sei < nse; sei++)
	for (j = 0; j < mesh[sei].GetNP(); j++)
	  if (mesh[sei].GetOrder() > v_order[mesh[sei][j]])
	    v_order[mesh[sei][j]] = mesh[sei].GetOrder();

      for (ElementIndex ei = 0; ei < ne; ei++)
	for (j = 0; j < mesh[ei].GetNP(); j++)
	  if (mesh[ei].GetOrder() < v_order[mesh[ei][j]]-1)
	    mesh[ei].SetOrder(v_order[mesh[ei][j]]-1);

      for (SurfaceElementIndex sei = 0; sei < nse; sei++)
	for (j = 0; j < mesh[sei].GetNP(); j++)
	  if (mesh[sei].GetOrder() < v_order[mesh[sei][j]]-1)
	    mesh[sei].SetOrder(v_order[mesh[sei][j]]-1);

      return;
    }



  // INDEX_2_HASHTABLE<int> cutedges(10 + 5 * (mtets.Size()+mprisms.Size()+mtris.Size()+mquads.Size()));
  INDEX_2_CLOSED_HASHTABLE<int> cutedges(10 + 9 * (mtets.Size()+mprisms.Size()+mtris.Size()+mquads.Size()));

  
  for (l = 1; l <= 1; l++)
    {
      int marked = 0;
      if (opt.refinementfilename)
	{
	  ifstream inf(opt.refinementfilename);
	  cout << "load refinementinfo from file " << opt.refinementfilename << endl;
	  char ch;
	  for (i = 1; i <= mtets.Size(); i++)
	    {
	      inf >> ch;
	      mtets.Elem(i).marked = (ch == '1');
	    }
	  marked = 1;
	}

      else if (opt.usemarkedelements)
	{
	  int cntm = 0;

	  // all in one !
	  if (mprisms.Size())
	    {
	      int cnttet = 0;
	      int cntprism = 0;
	      for (i = 1; i <= mesh.GetNE(); i++)
		{
		  if (mesh.VolumeElement(i).GetType() == TET ||
		      mesh.VolumeElement(i).GetType() == TET10)
		    {
		      cnttet++;
		      mtets.Elem(cnttet).marked =
			3 * mesh.VolumeElement(i).TestRefinementFlag();
		      if (mtets.Elem(cnttet).marked)
			cntm++;
		    }
		  else
		    {
		      cntprism++;
		      mprisms.Elem(cntprism).marked =
			2 * mesh.VolumeElement(i).TestRefinementFlag();
		      if (mprisms.Elem(cntprism).marked)
			cntm++;
		    }

		}
	    }
	  else
	    for (i = 1; i <= mtets.Size(); i++)
	      {
		mtets.Elem(i).marked =
		  3 * mesh.VolumeElement(i).TestRefinementFlag();
		if (mtets.Elem(i).marked)
		  cntm++;
	      }

	  // (*testout) << "mtets = " << mtets << endl;

	  /*
	  for (i = 1; i <= mtris.Size(); i++)
	    mtris.Elem(i).marked = 0;
	  for (i = 1; i <= mquads.Size(); i++)
	    mquads.Elem(i).marked = 0;
	    */

	  cout << "marked elements: " << cntm << endl;

	  int cnttrig = 0;
	  int cntquad = 0;
	  for (i = 1; i <= mesh.GetNSE(); i++)
	    {
	      if (mesh.SurfaceElement(i).GetType() == TRIG ||
		  mesh.SurfaceElement(i).GetType() == TRIG6)
		{
		  cnttrig++;
		  mtris.Elem(cnttrig).marked =
		    mesh.SurfaceElement(i).TestRefinementFlag() ? 2 : 0;
		  // mtris.Elem(cnttrig).marked = 0;
		  if (mtris.Elem(cnttrig).marked)
		    cntm++;
		}
	      else
		{
		  cntquad++;
		  mquads.Elem(cntquad).marked =
		    mesh.SurfaceElement(i).TestRefinementFlag();
		  // mquads.Elem(cntquad).marked = 0;
		  if (mquads.Elem(cntquad).marked)
		    cntm++;
		}
	    }

	  cout << "with surface-elements: " << cntm << endl;

	  if (mesh.GetDimension() == 2)
	    {
	      cntm = 0;
	      for (i = 1; i <= mtris.Size(); i++)
		{
		  mtris.Elem(i).marked =
		    2 * mesh.SurfaceElement(i).TestRefinementFlag();
		  //		  mtris.Elem(i).marked = 2;
		  if (mtris.Elem(i).marked)
		    cntm++;
		}

	      if (!cntm)
		{
		  for (i = 1; i <= mtris.Size(); i++)
		    {
		      mtris.Elem(i).marked = 2;
		      cntm++;
		    }
		}
	      cout << "trigs: " << mtris.Size() << " ";
	      cout << "marked: " << cntm << endl;
	    }

	  marked = (cntm > 0);
	}
      else
	{
	  marked = BTMarkTets (mtets, mprisms, mesh);
	}

      if (!marked) break;


	  if (opt.refine_p)
	    {
	      cout << "refine p" << endl;

	      for (i = 1; i <= mtets.Size(); i++)
		mtets.Elem(i).incorder = mtets.Elem(i).marked ? 1 : 0;

	      for (i = 1; i <= mtets.Size(); i++)
		if (mtets.Elem(i).incorder)
		  mtets.Elem(i).marked = 0;


	      for (i = 1; i <= mprisms.Size(); i++)
		mprisms.Elem(i).incorder = mprisms.Elem(i).marked ? 1 : 0;

	      for (i = 1; i <= mprisms.Size(); i++)
		if (mprisms.Elem(i).incorder)
		  mprisms.Elem(i).marked = 0;


	      for (i = 1; i <= mtris.Size(); i++)
		mtris.Elem(i).incorder = mtris.Elem(i).marked ? 1 : 0;

	      for (i = 1; i <= mtris.Size(); i++)
		{
		  if (mtris.Elem(i).incorder)
		    mtris.Elem(i).marked = 0;
		}
	    }

	  if (opt.refine_hp)
	    {
	      cout << "refine hp" << endl;
	      BitArray singv(np);
	      singv.Clear();

	      if (mesh.GetDimension() == 3)
		for (i = 1; i <= mesh.GetNSeg(); i++)
		  {
		    const Segment & seg = mesh.LineSegment(i);
		    singv.Set (seg.p1);
		    singv.Set (seg.p2);
		  }
	      else
		{
		  // vertices with 2 different bnds
		  ARRAY<int> bndind(np);
		  bndind = 0;
		  for (i = 1; i <= mesh.GetNSeg(); i++)
		    {
		      const Segment & seg = mesh.LineSegment(i);
		      for (int j = 0; j < 2; j++)
			{
			  int pi = (j == 0) ? seg.p1 : seg.p2;
			  if (bndind.Elem(pi) == 0)
			    bndind.Elem(pi) = seg.edgenr;
			  else if (bndind.Elem(pi) != seg.edgenr)
			    singv.Set (pi);
			}
		    }
		}



	      for (i = 1; i <= mtets.Size(); i++)
		mtets.Elem(i).incorder = 1;
	      for (i = 1; i <= mtets.Size(); i++)
		{
		  if (!mtets.Elem(i).marked)
		    mtets.Elem(i).incorder = 0;
		  for (j = 0; j < 4; j++)
		    if (singv.Test (mtets.Elem(i).pnums[j]))
		      mtets.Elem(i).incorder = 0;
		}
	      for (i = 1; i <= mtets.Size(); i++)
		if (mtets.Elem(i).incorder)
		  mtets.Elem(i).marked = 0;


	      for (i = 1; i <= mprisms.Size(); i++)
		mprisms.Elem(i).incorder = 1;
	      for (i = 1; i <= mprisms.Size(); i++)
		{
		  if (!mprisms.Elem(i).marked)
		    mprisms.Elem(i).incorder = 0;
		  for (j = 0; j < 6; j++)
		    if (singv.Test (mprisms.Elem(i).pnums[j]))
		      mprisms.Elem(i).incorder = 0;
		}
	      for (i = 1; i <= mprisms.Size(); i++)
		if (mprisms.Elem(i).incorder)
		  mprisms.Elem(i).marked = 0;


	      for (i = 1; i <= mtris.Size(); i++)
		mtris.Elem(i).incorder = 1;
	      for (i = 1; i <= mtris.Size(); i++)
		{
		  if (!mtris.Elem(i).marked)
		    mtris.Elem(i).incorder = 0;
		  for (j = 0; j < 3; j++)
		    if (singv.Test (mtris.Elem(i).pnums[j]))
		      mtris.Elem(i).incorder = 0;
		}
	      for (i = 1; i <= mtris.Size(); i++)
		{
		  if (mtris.Elem(i).incorder)
		    mtris.Elem(i).marked = 0;
		}
	    }





      int hangingvol, hangingsurf, hangingedge;

      do
	{
	  // refine volume elements

	  int nel = mtets.Size();
	  for (i = 1; i <= nel; i++)
	    if (mtets.Elem(i).marked)
	      {
		MarkedTet oldtet;
		MarkedTet newtet1, newtet2;
		int newp;


		oldtet = mtets.Get(i);
		INDEX_2 edge(oldtet.pnums[oldtet.tetedge1],
			     oldtet.pnums[oldtet.tetedge2]);
		edge.Sort();
		if (cutedges.Used (edge))
		  {
		    newp = cutedges.Get(edge);
		  }
		else
		  {
		    Point3d np = Center (mesh.Point (edge.I1()),
					 mesh.Point (edge.I2()));
		    newp = mesh.AddPoint (np);
		    cutedges.Set (edge, newp);
		  }

		BTBisectTet (oldtet, newp, newtet1, newtet2);
		mtets.Elem(i) = newtet1;
		mtets.Append (newtet2);
	      }

	  int npr = mprisms.Size();
	  for (i = 1; i <= npr; i++)
	    if (mprisms.Elem(i).marked)
	      {
		MarkedPrism oldprism;
		MarkedPrism newprism1, newprism2;
		int newp1, newp2;

		oldprism = mprisms.Get(i);
		int pi1 = 0;
		if (pi1 == oldprism.markededge)
		  pi1++;
		int pi2 = 3-pi1-oldprism.markededge;

		INDEX_2 edge1(oldprism.pnums[pi1],
			      oldprism.pnums[pi2]);
		INDEX_2 edge2(oldprism.pnums[pi1+3],
			      oldprism.pnums[pi2+3]);
		edge1.Sort();
		edge2.Sort();

		if (cutedges.Used (edge1))
		  newp1 = cutedges.Get(edge1);
		else
		  {
		    Point3d np = Center (mesh.Point (edge1.I1()),
					 mesh.Point (edge1.I2()));
		    newp1 = mesh.AddPoint (np);
		    cutedges.Set (edge1, newp1);
		  }
		if (cutedges.Used (edge2))
		  newp2 = cutedges.Get(edge2);
		else
		  {
		    Point3d np = Center (mesh.Point (edge2.I1()),
					 mesh.Point (edge2.I2()));
		    newp2 = mesh.AddPoint (np);
		    cutedges.Set (edge2, newp2);
		  }
		

		BTBisectPrism (oldprism, newp1, newp2, newprism1, newprism2);
		mprisms.Elem(i) = newprism1;
		mprisms.Append (newprism2);
	      }


	  hangingvol = 
	    MarkHangingTets (mtets, cutedges) +
	    MarkHangingPrisms (mprisms, cutedges);


	  int nsel = mtris.Size();

	  for (i = 1; i <= nsel; i++)
	    if (mtris.Elem(i).marked)
	      {
		MarkedTri oldtri;
		MarkedTri newtri1, newtri2;
		int newp;
		
		oldtri = mtris.Get(i);
		int oldpi1 = oldtri.pnums[(oldtri.markededge+1)%3];
		int oldpi2 = oldtri.pnums[(oldtri.markededge+2)%3];
		INDEX_2 edge(oldpi1, oldpi2);
		edge.Sort();

		//		cerr << "edge = " << edge.I1() << "-" << edge.I2() << endl;

		if (cutedges.Used (edge))
		  {
		    newp = cutedges.Get(edge);
		  }
		else
		  {
		    Point3d np = Center (mesh.Point (edge.I1()),
					 mesh.Point (edge.I2()));
		    newp = mesh.AddPoint (np);
		    cutedges.Set (edge, newp);
		  }
		//		newp = cutedges.Get(edge);
		
		int si = mesh.GetFaceDescriptor (oldtri.surfid).SurfNr();
		//  geom->GetSurface(si)->Project (mesh.Point(newp));
		PointGeomInfo npgi;
		
		if (mesh.PointType(newp) != EDGEPOINT)
		  PointBetween (mesh.Point (oldpi1), mesh.Point (oldpi2),
				0.5, si,
				oldtri.pgeominfo[(oldtri.markededge+1)%3],
				oldtri.pgeominfo[(oldtri.markededge+2)%3],
				mesh.Point (newp), npgi);
		
		BTBisectTri (oldtri, newp, npgi, newtri1, newtri2);
		
		
		mtris.Elem(i) = newtri1;
		mtris.Append (newtri2);
		mesh.mlparentsurfaceelement.Append (i);
	      }
	  
	  int nquad = mquads.Size();
	  for (i = 1; i <= nquad; i++)
	    if (mquads.Elem(i).marked)
	      {
		MarkedQuad oldquad;
		MarkedQuad newquad1, newquad2;
		int newp1, newp2;
		
		oldquad = mquads.Get(i);
		INDEX_2 edge1(oldquad.pnums[0],
			      oldquad.pnums[1]);
		INDEX_2 edge2(oldquad.pnums[2],
			      oldquad.pnums[3]);
		edge1.Sort();
		edge2.Sort();

		if (cutedges.Used (edge1))
		  {
		    newp1 = cutedges.Get(edge1);
		  }
		else
		  {
		    Point3d np = Center (mesh.Point (edge1.I1()),
					 mesh.Point (edge1.I2()));
		    newp1 = mesh.AddPoint (np);
		    cutedges.Set (edge1, newp1);
		  }

		if (cutedges.Used (edge2))
		  {
		    newp2 = cutedges.Get(edge2);
		  }
		else
		  {
		    Point3d np = Center (mesh.Point (edge2.I1()),
					 mesh.Point (edge2.I2()));
		    newp2 = mesh.AddPoint (np);
		    cutedges.Set (edge2, newp2);
		  }

		PointGeomInfo npgi1, npgi2;
		
		int si = mesh.GetFaceDescriptor (oldquad.surfid).SurfNr();
		//		geom->GetSurface(si)->Project (mesh.Point(newp1));
		//		geom->GetSurface(si)->Project (mesh.Point(newp2));

		(*testout) << "project point " << newp1 << " old: " << mesh.Point(newp1);
		PointBetween (mesh.Point (edge1.I1()), mesh.Point (edge1.I2()),
			      0.5, si,
			      oldquad.pgeominfo[0],
			      oldquad.pgeominfo[1],
			      mesh.Point (newp1), npgi1);
		(*testout) << " new: " << mesh.Point(newp1) << endl;

		
		PointBetween (mesh.Point (edge2.I1()), mesh.Point (edge2.I2()),
			      0.5, si,
			      oldquad.pgeominfo[2],
			      oldquad.pgeominfo[3],
			      mesh.Point (newp2), npgi2);
		

		BTBisectQuad (oldquad, newp1, npgi1, newp2, npgi2,
			      newquad1, newquad2);
		mquads.Elem(i) = newquad1;
		mquads.Append (newquad2);
	      }
	  

	  hangingsurf = 
	    MarkHangingTris (mtris, cutedges) +
	    MarkHangingQuads (mquads, cutedges);

	  hangingedge = 0;
	  
	  int nseg = mesh.GetNSeg ();
	  for (i = 1; i <= nseg; i++)
	    {
	      Segment & seg = mesh.LineSegment (i);
	      INDEX_2 edge(seg.p1, seg.p2);
	      edge.Sort();
	      if (cutedges.Used (edge))
		{
		  hangingedge = 1;
		  Segment nseg1 = seg;
		  Segment nseg2 = seg;
		  
		  int newpi = cutedges.Get(edge);
		  
		  nseg1.p2 = newpi;
		  nseg2.p1 = newpi;
		  
		  EdgePointGeomInfo newepgi;
		  
		  //		  (*testout) << "move edgepoint " << newpi << " from " << mesh.Point(newpi);
		  PointBetween (mesh.Point (seg.p1), mesh.Point (seg.p2),
				0.5, seg.surfnr1, seg.surfnr2, 
				seg.epgeominfo[0], seg.epgeominfo[1],
				mesh.Point (newpi), newepgi);
		  //		  (*testout) << " to " << mesh.Point (newpi) << endl;
		  nseg1.epgeominfo[1] = newepgi;
		  nseg2.epgeominfo[0] = newepgi;
		  
		  mesh.LineSegment (i) = nseg1;
		  mesh.AddSegment (nseg2);
		}
	    }

	}
      while (hangingvol || hangingsurf || hangingedge);
      
      
      cout << mtets.Size() << " tets" << endl;
      cout << mtris.Size() << " trigs" << endl;
      if (mprisms.Size())
	{
	  cout << mprisms.Size() << " prisms" << endl;
	  cout << mquads.Size() << " quads" << endl;
	}
      cout << mesh.GetNP() << " points" << endl;
    }

  /*
  cout << "mem in mtets: " << endl;
  mtets.PrintMemInfo(cout);
  cout << "cutedges" << endl;
  cutedges.PrintMemInfo(cout);
  */

  // (*testout) << "mtets = " << mtets << endl;

  if (opt.refine_hp)
    {
      //
      ARRAY<int> v_order (mesh.GetNP());
      v_order = 0;
      if (mesh.GetDimension() == 3)
	{
	  for (i = 1; i <= mtets.Size(); i++)
	    if (mtets.Elem(i).incorder)
	      mtets.Elem(i).order++;
      
	  for (i = 0; i < mtets.Size(); i++)
	    for (j = 0; j < 4; j++)
	    if (mtets[i].order > v_order.Elem(mtets[i].pnums[j]))
	      v_order.Elem(mtets[i].pnums[j]) = mtets[i].order;
	  for (i = 0; i < mtets.Size(); i++)
	    for (j = 0; j < 4; j++)
	      if (mtets[i].order < v_order.Elem(mtets[i].pnums[j])-1)
		mtets[i].order = v_order.Elem(mtets[i].pnums[j])-1;
	}
      else
	{
	  for (i = 1; i <= mtris.Size(); i++)
	    if (mtris.Elem(i).incorder)
	      {
		mtris.Elem(i).order++;
	      }

	  for (i = 0; i < mtris.Size(); i++)
	    for (j = 0; j < 3; j++)
	      if (mtris[i].order > v_order.Elem(mtris[i].pnums[j]))
		v_order.Elem(mtris[i].pnums[j]) = mtris[i].order;
	  for (i = 0; i < mtris.Size(); i++)
	    {
	      for (j = 0; j < 3; j++)
		if (mtris[i].order < v_order.Elem(mtris[i].pnums[j])-1)
		  mtris[i].order = v_order.Elem(mtris[i].pnums[j])-1;
	    }
	}
    }
  
  mtets.SetAllocSize (mtets.Size());
  mprisms.SetAllocSize (mprisms.Size());
  mtris.SetAllocSize (mtris.Size());
  mquads.SetAllocSize (mquads.Size());
  
  
  mesh.ClearVolumeElements();
  mesh.VolumeElements().SetAllocSize (mtets.Size()+mprisms.Size());
  for (i = 1; i <= mtets.Size(); i++)
    {
      Element el(TET);
      el.SetIndex (mtets.Get(i).matindex);
      for (j = 1; j <= 4; j++)
	el.PNum(j) = mtets.Get(i).pnums[j-1];
      el.SetOrder (mtets.Get(i).order);
      mesh.AddVolumeElement (el);
    }
  for (i = 1; i <= mprisms.Size(); i++)
    {
      Element el(PRISM);
      el.SetIndex (mprisms.Get(i).matindex);
      for (j = 1; j <= 6; j++)
	el.PNum(j) = mprisms.Get(i).pnums[j-1];
      el.SetOrder (mprisms.Get(i).order);

      // degenerated prism ?
      static const int map1[] = { 3, 2, 5, 6, 1 };
      static const int map2[] = { 1, 3, 6, 4, 2 };
      static const int map3[] = { 2, 1, 4, 5, 3 };
      

      const int * map = NULL;
      int deg1 = 0, deg2 = 0, deg3 = 0;
      // int deg = 0;
      if (el.PNum(1) == el.PNum(4)) { map = map1; deg1 = 1; }
      if (el.PNum(2) == el.PNum(5)) { map = map2; deg2 = 1; }
      if (el.PNum(3) == el.PNum(6)) { map = map3; deg3 = 1; }
	  
      switch (deg1+deg2+deg3)
	{
	case 1:
	  {
	    for (j = 1; j <= 5; j++)
	      el.PNum(j) = mprisms.Get(i).pnums[map[j-1]-1];
	    
	    el.SetType (PYRAMID);
	    break;
	  }
	case 2:
	  {
	    static const int tetmap1[] = { 1, 2, 3, 4 };
	    static const int tetmap2[] = { 2, 3, 1, 5 };
	    static const int tetmap3[] = { 3, 1, 2, 6 };
	    if (!deg1) map = tetmap1;
	    if (!deg2) map = tetmap2;
	    if (!deg3) map = tetmap3; 
	    for (j = 1; j <= 4; j++)
	      el.PNum(j) = mprisms.Get(i).pnums[map[j-1]-1];
	    /*
	    if (!deg1) el.PNum(4) = el.PNum(4);
	    if (!deg2) el.PNum(4) = el.PNum(5);
	    if (!deg3) el.PNum(4) = el.PNum(6);
	    */
	    el.SetType(TET);
	    break;
	  }
	default:
	  ;
	}
      mesh.AddVolumeElement (el);
    }
  
  mesh.ClearSurfaceElements();
  for (i = 1; i <= mtris.Size(); i++)
    {
      Element2d el(TRIG);
      el.SetIndex (mtris.Get(i).surfid);
      el.SetOrder (mtris.Get(i).order);
      for (j = 1; j <= 3; j++)
	{
	  el.PNum(j) = mtris.Get(i).pnums[j-1];
	  el.GeomInfoPi(j) = mtris.Get(i).pgeominfo[j-1];
	}
      mesh.AddSurfaceElement (el);
    }
  for (i = 1; i <= mquads.Size(); i++)
    {
      Element2d el(QUAD);
      el.SetIndex (mquads.Get(i).surfid);
      for (j = 1; j <= 4; j++)
	el.PNum(j) = mquads.Get(i).pnums[j-1];
      Swap (el.PNum(3), el.PNum(4));
      mesh.AddSurfaceElement (el);
    }


      
  // write multilevel hierarchy to mesh:
  np = mesh.GetNP();
  mesh.mlbetweennodes.SetSize(np);
  if (mesh.mglevels <= 2)
    for (i = 1; i <= np; i++)
      {
	mesh.mlbetweennodes.Elem(i).I1() = 0;
	mesh.mlbetweennodes.Elem(i).I2() = 0;
      }

  /*
  for (i = 1; i <= cutedges.GetNBags(); i++)
    for (j = 1; j <= cutedges.GetBagSize(i); j++)
      {
	INDEX_2 edge;
	int newpi;
	cutedges.GetData (i, j, edge, newpi);
	mesh.mlbetweennodes.Elem(newpi) = edge;
      }
  */
  for (i = 1; i <= cutedges.Size(); i++)
    if (cutedges.UsedPos(i))
      {
	INDEX_2 edge;
	int newpi;
	cutedges.GetData (i, edge, newpi);
	mesh.mlbetweennodes.Elem(newpi) = edge;
      }


  /*
  mesh.PrintMemInfo (cout);
  cout << "tets ";
  mtets.PrintMemInfo (cout);
  cout << "prims ";
  mprisms.PrintMemInfo (cout);
  cout << "tris ";
  mtris.PrintMemInfo (cout);
  cout << "quads ";
  mquads.PrintMemInfo (cout);
  cout << "cutedges ";
  cutedges.PrintMemInfo (cout);
  */


  /*

  // find connected nodes (close nodes)
  TABLE<int> conto(np);
  for (i = 1; i <= mprisms.Size(); i++)
    for (j = 1; j <= 6; j++)
      {
	int n1 = mprisms.Get(i).pnums[j-1];
	int n2 = mprisms.Get(i).pnums[(j+2)%6];
	//	    if (n1 != n2)
	{
	  int found = 0;
	  for (k = 1; k <= conto.EntrySize(n1); k++)
	    if (conto.Get(n1, k) == n2)
	      {
		found = 1;
		break;
	      }
	  if (!found)
	    conto.Add (n1, n2);
	}
      }
  mesh.connectedtonode.SetSize(np);
  for (i = 1; i <= np; i++)
    mesh.connectedtonode.Elem(i) = 0;
  

//       (*testout) << "connection table: " << endl;
//       for (i = 1; i <= np; i++)
//       {
//       (*testout) << "node " << i << ": ";
// 	  for (j = 1; j <= conto.EntrySize(i); j++)
// 	  (*testout) << conto.Get(i, j) << " ";
// 	  (*testout) << endl;
// 	}

  
  for (i = 1; i <= np; i++)
    if (mesh.connectedtonode.Elem(i) == 0)
      {
	mesh.connectedtonode.Elem(i) = i;
	ConnectToNodeRec (i, i, conto, mesh.connectedtonode);
      }
*/  

  //  mesh.BuildConnectedNodes();

  mesh.ComputeNVertices();
  mesh.UpdateTopology();

  // update identification tables
  for (i = 1; i <= mesh.GetIdentifications().GetMaxNr(); i++)
    {
      ARRAY<int,PointIndex::BASE> identmap;
      mesh.GetIdentifications().GetMap (i, identmap);


      /*
      for (j = 1; j <= cutedges.GetNBags(); j++)
	for (k = 1; k <= cutedges.GetBagSize(j); k++)
	  {
	    INDEX_2 i2;
	    int newpi;
	    cutedges.GetData (j, k, i2, newpi);
	    INDEX_2 oi2(identmap.Get(i2.I1()),
			identmap.Get(i2.I2()));
	    oi2.Sort();
	    if (cutedges.Used (oi2))
	      {
		int onewpi = cutedges.Get(oi2);
		mesh.GetIdentifications().Add (newpi, onewpi, i);
	      }
	  }
      */

      for (j = 1; j <= cutedges.Size(); j++)
	if (cutedges.UsedPos(j))
	  {
	    INDEX_2 i2;
	    int newpi;
	    cutedges.GetData (j, i2, newpi);
	    INDEX_2 oi2(identmap.Get(i2.I1()),
			identmap.Get(i2.I2()));
	    oi2.Sort();
	    if (cutedges.Used (oi2))
	      {
		int onewpi = cutedges.Get(oi2);
		mesh.GetIdentifications().Add (newpi, onewpi, i);
	      }
	  }

    }
  PrintMessage (5, "Bisection done");
}




BisectionOptions :: BisectionOptions ()
{
  outfilename = NULL;
  mlfilename = NULL;
  refinementfilename = NULL;
  femcode = NULL;
  maxlevel = 50;
  usemarkedelements = 0;
  refine_hp = 0;
  refine_p = 0;
}



void Refinement :: PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
				 int surfi, 
				 const PointGeomInfo & gi1, 
				 const PointGeomInfo & gi2,
				 Point3d & newp, PointGeomInfo & newgi)
{
  newp = p1+secpoint*(p2-p1);
}

void Refinement :: PointBetween (const Point3d & p1, const Point3d & p2, double secpoint,
				 int surfi1, int surfi2, 
				 const EdgePointGeomInfo & ap1, 
				 const EdgePointGeomInfo & ap2,
				 Point3d & newp, EdgePointGeomInfo & newgi)
{
  newp = p1+secpoint*(p2-p1);
}

void Refinement :: ProjectToSurface (Point<3> & p, int surfi)
{
  cout << "Refinement :: ProjectToSurface    ERROR: no geometry set" << endl;
};


}

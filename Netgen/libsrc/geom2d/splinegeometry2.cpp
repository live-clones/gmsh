/*

2d Spline curve for Mesh generator

*/

#include <mystdlib.h>
#include <csg.hpp>
#include <linalg.hpp>
#include <meshing.hpp>


namespace netgen

{

#include "spline2d.hpp"
#include "splinegeometry2.hpp"





void SplineGeometry2d :: Load (const char * filename)
{
  ifstream infile;
  int nump, numseg, nelp, i, leftdom, rightdom;
  double x, y;
  int hi1, hi2, hi3;
  double hd;
  char reco[50], ch;

  infile.open (filename);

  infile >> reco;
  infile >> elto0;

  infile >> nump;
  for (i = 0; i < nump; i++)
    {
      infile >> x >> y >> hd;
      geompoints.Append (GeomPoint2d(x, y, hd));
    }

  infile >> numseg;

  SplineSegment * spline = 0;
  for (i = 0; i < numseg; i++)
    {
      infile >> leftdom >> rightdom;

      infile >> nelp;  
      switch (nelp)
	{ // type of spline segement
	case 2:
	  { // a line
	    infile >> hi1 >> hi2;
	    spline = new LineSegment(geompoints[hi1-1],
				     geompoints[hi2-1]);
	    break;
	  }
	case 3:
	  { // a rational spline
	    infile >> hi1 >> hi2 >> hi3;
	    spline = new SplineSegment3 (geompoints[hi1-1],
					 geompoints[hi2-1],
					 geompoints[hi3-1]);
	    break;
	  }
	case 4:
	  { // an arc
	    infile >> hi1 >> hi2 >> hi3;
	    splines.Append (new CircleSegment (geompoints[hi1-1],
					       geompoints[hi2-1],
					       geompoints[hi3-1]));
	    break;
	  }
	}
    
      infile >> spline->reffak;
      spline -> leftdom = leftdom;
      spline -> rightdom = rightdom;
      splines.Append (spline);

    

      Flags flags;
      ch = 'a';
      infile >> ch;
      while (ch == '-')
	{
	  char flag[100];
	  flag[0]='-';
	  infile >> (flag+1);
	  flags.SetCommandLineFlag (flag);
	  ch = 'a';
	  infile >> ch;
	}
    
      if (infile.good())
	infile.putback (ch);
    
      splines.Last()->bc = int (flags.GetNumFlag ("bc", i+1));
      splines.Last()->copyfrom = int (flags.GetNumFlag ("copy", -1));
    }


  Box<2> bbox;
  GetBoundingBox (bbox);
  // cout << "bbox = " << bbox << endl;
}



void SplineGeometry2d :: 
PartitionBoundary (double h, Mesh & mesh2d)
{
  for (int i = 0; i < splines.Size(); i++)
    if (splines[i]->copyfrom == -1)
      splines[i]->Partition(h, elto0, mesh2d, i+1);
    else
      CopyEdgeMesh (splines[i]->copyfrom, i+1, mesh2d);
}


void SplineGeometry2d :: CopyEdgeMesh (int from, int to, Mesh & mesh)
{
  int i, j, k;

  ARRAY<int> mappoints (mesh.GetNP());
  ARRAY<double> param (mesh.GetNP());
  mappoints = -1;
  param = 0;

  Point3d pmin, pmax;
  mesh.GetBox (pmin, pmax);
  double diam2 = Dist2(pmin, pmax);

  cout << "copy edge, from = " << from << " to " << to << endl;
  
  for (i = 1; i <= mesh.GetNSeg(); i++)
    {
      const Segment & seg = mesh.LineSegment(i);
      if (seg.edgenr == from)
	{
	  mappoints.Elem(seg.p1) = 1;
	  param.Elem(seg.p1) = seg.epgeominfo[0].dist;

	  mappoints.Elem(seg.p2) = 1;
	  param.Elem(seg.p2) = seg.epgeominfo[1].dist;
	}
    }

  for (i = 1; i <= mappoints.Size(); i++)
    {
      if (mappoints.Get(i) != -1)
	{
	  Point<2> newp = splines.Get(to)->GetPoint (param.Get(i));
	  Point<3> newp3 (newp(0), newp(1), 0);
	  
	  int npi = -1;
	  
	  for (PointIndex pi = PointIndex::BASE; 
	       pi < mesh.GetNP()+PointIndex::BASE; pi++)
	    if (Dist2 (mesh.Point(pi), newp3) < 1e-12 * diam2)
	      npi = pi;
	  
	  if (npi == -1)
	    {
	      npi = mesh.AddPoint (newp3);
	    }
	  
	  mappoints.Elem(i) = npi;

	  mesh.GetIdentifications().Add (i, npi, to);
	}
    }

  // copy segments
  int oldnseg = mesh.GetNSeg();
  for (i = 1; i <= oldnseg; i++)
    {
      const Segment & seg = mesh.LineSegment(i);
      if (seg.edgenr == from)
	{
	  Segment nseg;
	  nseg.edgenr = to;
	  nseg.si = splines.Get(to)->bc;
	  nseg.p1 = mappoints.Get(seg.p1);
	  nseg.p2 = mappoints.Get(seg.p2);
	  nseg.domin = splines.Get(to)->leftdom;
	  nseg.domout = splines.Get(to)->rightdom;
	  
	  nseg.epgeominfo[0].edgenr = to;
	  nseg.epgeominfo[0].dist = param.Get(seg.p1);
	  nseg.epgeominfo[1].edgenr = to;
	  nseg.epgeominfo[1].dist = param.Get(seg.p2);
	  mesh.AddSegment (nseg);
	}
    }
}
  

void SplineGeometry2d :: 
GetBoundingBox (Box<2> & box) const
{
  if (!splines.Size())
    {
      box.Set (Point<2> (0,0));
      return;
    }

  ARRAY<Point<2> > points;
  for (int i = 0; i < splines.Size(); i++)
    {
      splines[i]->GetPoints (20, points);

      if (i == 0) box.Set(points[0]);
      for (int j = 0; j < points.Size(); j++)
	box.Add (points[j]);
    }
}

}

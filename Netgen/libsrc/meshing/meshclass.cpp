#include <mystdlib.h>

#include "meshing.hpp"

namespace netgen
{

Mesh :: Mesh ()
  : ident (*this)

{
  boundaryedges = NULL;
  surfelementht = NULL; 
  segmentht = NULL;

  lochfunc = NULL;
  mglevels = 1;
  elementsearchtree = NULL;
  elementsearchtreets = NextTimeStamp();
  majortimestamp = timestamp = NextTimeStamp();
  hglob = 1e10;
  numvertices = -1;
  dimension = 3;
  topology = new MeshTopology (*this);
  curvedelems = new CurvedElements (*this);
  clusters = new AnisotropicClusters (*this);

  //  volelements.SetName ("Volume Elements");
  //  surfelements.SetName ("Surface Elements");
  //  points.SetName ("Mesh Points");
}

Mesh :: ~Mesh()
{
  // DeleteMesh();
  delete lochfunc;
  delete boundaryedges;
  delete surfelementht;
  delete segmentht;
  delete curvedelems;
  delete clusters;
  delete topology;
}

void Mesh :: DeleteMesh()
{
  points.SetSize(0);
  ptyps.SetSize(0);
  segments.SetSize(0);
  surfelements.SetSize(0);
  volelements.SetSize(0);
  lockedpoints.SetSize(0);
  surfacesonnode.SetSize(0);

  delete boundaryedges;
  boundaryedges = NULL;

  openelements.SetSize(0);
  facedecoding.SetSize(0);

  ident.Delete();

  delete topology;
  topology = new MeshTopology (*this);
  delete curvedelems;
  curvedelems = new CurvedElements (*this);
  delete clusters;
  clusters = new AnisotropicClusters (*this);

  timestamp = NextTimeStamp();
}



PointIndex Mesh :: AddPoint (const Point3d & p, int layer)
{ 
  NgLock lock(mutex);
  lock.Lock();

  timestamp = NextTimeStamp();

  if (ptyps.Size() == points.Size())
    ptyps.Append (INNERPOINT);

  PointIndex pi = points.Size() + PointIndex::BASE;
  points.Append ( MeshPoint (p, layer) ); 

  lock.UnLock();

  return pi;
}


SegmentIndex Mesh :: AddSegment (const Segment & s)
{ 
  NgLock lock(mutex);	
  lock.Lock();
  timestamp = NextTimeStamp();

  int maxn = max2 (s.p1, s.p2);
  maxn += 1-PointIndex::BASE;

  if (maxn > ptyps.Size())
    {
      int maxo = ptyps.Size();
      ptyps.SetSize (maxn);
      for (int i = maxo; i < maxn; i++)
	ptyps[i] = INNERPOINT;
    }

  if (ptyps[s.p1] > EDGEPOINT) ptyps[s.p1] = EDGEPOINT;
  if (ptyps[s.p2] > EDGEPOINT) ptyps[s.p2] = EDGEPOINT;
  
  SegmentIndex si = segments.Size();
  segments.Append (s); 
  
  lock.UnLock();
  return si;
}

SurfaceElementIndex Mesh :: AddSurfaceElement (const Element2d & el)
{     
  NgLock lock(mutex);
  lock.Lock();
  timestamp = NextTimeStamp();

  int i;
  int maxn = el[0];
  for (i = 1; i < el.GetNP(); i++)
    if (el[i] > maxn) maxn = el[i];

  maxn += 1-PointIndex::BASE;

  if (maxn > ptyps.Size())
    {
      int maxo = ptyps.Size();
      ptyps.SetSize (maxn);
      for (i = maxo+PointIndex::BASE; 
	   i < maxn+PointIndex::BASE; i++)
	ptyps[i] = INNERPOINT;
    }

  for (i = 0; i < el.GetNP(); i++)
    if (ptyps[el[i]] > SURFACEPOINT)
      ptyps[el[i]] = SURFACEPOINT;

  SurfaceElementIndex si = surfelements.Size();
  surfelements.Append (el); 

  lock.UnLock();
  return si;
}


ElementIndex Mesh :: AddVolumeElement (const Element & el)
{ 
  NgLock lock(mutex);
  lock.Lock();

  int i;

  int maxn = el[0];
  for (i = 1; i < el.GetNP(); i++)
    if (el[i] > maxn) maxn = el[i];

  maxn += 1-PointIndex::BASE;

  if (maxn > ptyps.Size())
    {
      int maxo = ptyps.Size();
      ptyps.SetSize (maxn);
      for (i = maxo+PointIndex::BASE; 
	   i < maxn+PointIndex::BASE; i++)
	ptyps[i] = INNERPOINT;
    }


  int ve = volelements.Size();

  volelements.Append (el); 
  volelements.Last().flags.illegal_valid = 0;

  while (volelements.Size() > eltyps.Size())
    eltyps.Append (FREEELEMENT);
  
  timestamp = NextTimeStamp();

  lock.UnLock();
  return ve;
}






void Mesh :: Save (const char * filename) const
{
  int i, j;

  double scale = 1;  // globflags.GetNumFlag ("scale", 1);
  int inverttets = 0;  // globflags.GetDefineFlag ("inverttets");
  int invertsurf = 0;  // globflags.GetDefineFlag ("invertsurfacemesh");

  ofstream outfile(filename);


  outfile << "mesh3d" << "\n";

  outfile << "dimension\n" << GetDimension() << "\n";

  outfile << "\n";
  outfile << "# surfnr    bcnr   domin  domout      np      p1      p2      p3"
	  << "\n";

  outfile << "surfaceelementsgi" << "\n";
  //  outfile << "surfaceelements" << "\n";
  outfile << GetNSE() << "\n";

  SurfaceElementIndex sei;
  for (sei = 0; sei < GetNSE(); sei++)
    {
      if ((*this)[sei].GetIndex())
	{
	  outfile.width(8);
	  outfile << GetFaceDescriptor((*this)[sei].GetIndex ()).SurfNr()+1;
	  outfile.width(8);
	  outfile << GetFaceDescriptor((*this)[sei].GetIndex ()).BCProperty();
	  outfile.width(8);	  
	  outfile << GetFaceDescriptor((*this)[sei].GetIndex ()).DomainIn();
	  outfile.width(8);	  
	  outfile << GetFaceDescriptor((*this)[sei].GetIndex ()).DomainOut();
	}
      else
	outfile << "       0       0       0";


      Element2d sel = (*this)[sei];
      if (invertsurf)
	sel.Invert();

      outfile.width(8);
      outfile << sel.GetNP();

      for (j = 0; j < sel.GetNP(); j++)
	{
	  outfile.width(8);	  
	  outfile << sel[j];
	}

      for (j = 1; j <= sel.GetNP(); j++)
	{
	  outfile.width(7);	  
	  outfile << " " << sel.GeomInfoPi(j).trignum;
	}
      outfile << endl;
    }

  outfile << "\n" << "\n";
  outfile << "#  matnr      np      p1      p2      p3      p4" << "\n";
  outfile << "volumeelements" << "\n";
  outfile << GetNE() << "\n";

  for (ElementIndex ei = 0; ei < GetNE(); ei++)
    {
      outfile.width(8);
      outfile << (*this)[ei].GetIndex();
      outfile.width(8);
      outfile << (*this)[ei].GetNP();

      Element el = (*this)[ei];
      if (inverttets)
	el.Invert();

      for (j = 0; j < el.GetNP(); j++)
	{
	  outfile.width(8);
	  outfile << el[j];
	}
      outfile << "\n";
    }


  outfile << "\n" << "\n";
  outfile << "   surf1   surf2      p1      p2" << "\n";
  outfile << "edgesegmentsgi2" << "\n";
  outfile << GetNSeg() << "\n";

  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment (i);
      outfile.width(8);
      outfile << seg.si;
      outfile.width(8);
      outfile << 0;
      outfile.width(8);
      outfile << seg.p1;
      outfile.width(8);
      outfile << seg.p2;
      outfile << " ";
      outfile.width(8);
      outfile << seg.geominfo[0].trignum;
      outfile << " ";
      outfile.width(8);
      outfile << seg.geominfo[1].trignum << endl;

      outfile << " ";
      outfile.width(8);
      outfile << seg.surfnr1+1;
      outfile << " ";
      outfile.width(8);
      outfile << seg.surfnr2+1;
      outfile << " ";
      outfile.width(8);
      outfile << seg.edgenr;
      //      outfile << seg.epgeominfo[0].edgenr;
      /*
      outfile.width(8);
      outfile << seg.epgeominfo[0].lefttrig;
      outfile.width(8);
      outfile << seg.epgeominfo[0].righttrig;
      */
      outfile << " ";
      outfile.width(12);
      outfile << seg.epgeominfo[0].dist;
      outfile << " ";
      outfile.width(8);
      outfile << seg.epgeominfo[1].edgenr;
      /*
      outfile.width(8);
      outfile << seg.epgeominfo[1].lefttrig;
      outfile.width(8);
      outfile << seg.epgeominfo[1].righttrig;
      */
      outfile << " ";
      outfile.width(12);
      outfile << seg.epgeominfo[1].dist;

      outfile << "\n";
    }




  outfile << "\n" << "\n";
  outfile << "#          X             Y             Z" << "\n";
  outfile << "points" << "\n";
  outfile << GetNP() << "\n";
  outfile.precision(16);
  outfile.setf (ios::fixed, ios::floatfield);
  outfile.setf (ios::showpoint);

  PointIndex pi;
  for (pi = 1; pi <= GetNP(); pi++)
    {
      outfile.width(22);
      outfile << (*this)[pi].X()/scale << "  ";
      outfile.width(22);
      outfile << (*this)[pi].Y()/scale << "  ";
      outfile.width(22);
      outfile << (*this)[pi].Z()/scale << "\n";
    }      

  if (ident.GetMaxNr() > 0)
    {
      outfile << "identifications\n";
      ARRAY<INDEX_2> identpairs;
      int cnt = 0;
      for (i = 1; i <= ident.GetMaxNr(); i++)
	{
	  ident.GetPairs (i, identpairs);
	  cnt += identpairs.Size();
	}
      outfile << cnt << "\n";
      for (i = 1; i <= ident.GetMaxNr(); i++)
	{
	  ident.GetPairs (i, identpairs);
	  for (j = 1; j <= identpairs.Size(); j++)
	    {
	      outfile.width (8);
	      outfile << identpairs.Get(j).I1();
	      outfile.width (8);
	      outfile << identpairs.Get(j).I2();
	      outfile.width (8);
	      outfile << i << "\n";
	    }
	}
    }

  int cntmat = 0;
  for (i = 1; i <= materials.Size(); i++)
    if (materials.Get(i) && strlen (materials.Get(i)))
      cntmat++;

  if (cntmat)
    {
      outfile << "materials" << endl;
      outfile << cntmat << endl;
      for (i = 1; i <= materials.Size(); i++)
	if (materials.Get(i) && strlen (materials.Get(i)))
	  outfile << i << " " << materials.Get(i) << endl;
    }

  //  delete houtfile;
}


void Mesh :: Load (const char * filename)
{
  char str[100];
  int i, n;

  double scale = 1;  // globflags.GetNumFlag ("scale", 1);
  int inverttets = 0;  // globflags.GetDefineFlag ("inverttets");
  int invertsurf = 0;  // globflags.GetDefineFlag ("invertsurfacemesh");


  ifstream infile(filename);
  if (!infile.good())
    {
      throw NgException ("mesh file not found");
      //      cerr << "mesh file not found !!" << endl;
      //      return;
    }

  facedecoding.SetSize(0);

  while (infile.good())
    {
      infile >> str;

      if (strcmp (str, "dimension") == 0)
	{
	  infile >> dimension;
	}

      if (strcmp (str, "surfaceelements") == 0)
	{
	  infile >> n;
	  PrintMessage (3, n, " surface elements");
	  for (i = 1; i <= n; i++)
	    {
	      int j;
	      int surfnr, bcp, domin, domout, nep, faceind = 0;

	      infile >> surfnr >> bcp >> domin >> domout;
	      surfnr--;

	      for (j = 1; j <= facedecoding.Size(); j++)
		if (GetFaceDescriptor(j).SurfNr() == surfnr &&
		    GetFaceDescriptor(j).BCProperty() == bcp &&
		    GetFaceDescriptor(j).DomainIn() == domin &&
		    GetFaceDescriptor(j).DomainOut() == domout)
		  faceind = j;

	      if (!faceind)
		{
		  faceind = AddFaceDescriptor (FaceDescriptor(surfnr, domin, domout, 0));
		  GetFaceDescriptor(faceind).SetBCProperty (bcp);
		}

	      infile >> nep;
	      if (!nep) nep = 3;

	      Element2d tri(nep);
	      tri.SetIndex(faceind);

	      for (j = 1; j <= nep; j++)
		infile >> tri.PNum(j);

	      if (invertsurf)
		tri.Invert();

	      AddSurfaceElement (tri);
	    }
	}

      if (strcmp (str, "surfaceelementsgi") == 0)
	{
	  infile >> n;
	  PrintMessage (3, n, " surface elements");
	  for (i = 1; i <= n; i++)
	    {
	      int j;
	      int surfnr, bcp, domin, domout, nep, faceind = 0;
	      infile >> surfnr >> bcp >> domin >> domout;
	      surfnr--;

	      for (j = 1; j <= facedecoding.Size(); j++)
		if (GetFaceDescriptor(j).SurfNr() == surfnr &&
		    GetFaceDescriptor(j).BCProperty() == bcp &&
		    GetFaceDescriptor(j).DomainIn() == domin &&
		    GetFaceDescriptor(j).DomainOut() == domout)
		  faceind = j;

	      if (!faceind)
		{
		  faceind = AddFaceDescriptor (FaceDescriptor(surfnr, domin, domout, 0));
		  GetFaceDescriptor(faceind).SetBCProperty (bcp);
		}

	      infile >> nep;
	      if (!nep) nep = 3;

	      Element2d tri(nep);
	      tri.SetIndex(faceind);

	      for (j = 1; j <= nep; j++)
		infile >> tri.PNum(j);

	      for (j = 1; j <= nep; j++)
		infile >> tri.GeomInfoPi(j).trignum;

	      if (invertsurf)
		tri.Invert();

	      AddSurfaceElement (tri);
	    }
	}



      if (strcmp (str, "volumeelements") == 0)
	{
	  infile >> n;
	  PrintMessage (3, n, " volume elements");
	  for (i = 1; i <= n; i++)
	    {
	      Element el;
	      int hi, nep;
	      infile >> hi;
	      if (hi == 0) hi = 1;
	      el.SetIndex(hi);
	      infile >> nep;
	      el.SetNP(nep);
	      
	      for (int j = 0; j < nep; j++)
		infile >> (int&)(el[j]);
	      
	      if (inverttets)
		el.Invert();

	      AddVolumeElement (el);
	      
	    }
	}

      if (strcmp (str, "edgesegments") == 0)
	{
	  infile >> n;
	  for (i = 1; i <= n; i++)
	    {
	      Segment seg;
	      int hi;
	      infile >> seg.si >> hi >> seg.p1 >> seg.p2;
	      AddSegment (seg);
	    }
	}
      
      if (strcmp (str, "edgesegmentsgi") == 0)
	{
	  infile >> n;
	  for (i = 1; i <= n; i++)
	    {
	      Segment seg;
	      int hi;
	      infile >> seg.si >> hi >> seg.p1 >> seg.p2
		     >> seg.geominfo[0].trignum
		     >> seg.geominfo[1].trignum;
	      AddSegment (seg);
	    }
	}
      if (strcmp (str, "edgesegmentsgi2") == 0)
	{
	  infile >> n;
	  PrintMessage (3, n, " curve elements");

	  for (i = 1; i <= n; i++)
	    {
	      Segment seg;
	      int hi;
	      infile >> seg.si >> hi >> seg.p1 >> seg.p2
		     >> seg.geominfo[0].trignum
		     >> seg.geominfo[1].trignum
		     >> seg.surfnr1 >> seg.surfnr2
		     >> seg.epgeominfo[0].edgenr
		//		     >> seg.epgeominfo[0].lefttrig
		//		     >> seg.epgeominfo[0].righttrig
		     >> seg.epgeominfo[0].dist
		     >> seg.epgeominfo[1].edgenr
		//		     >> seg.epgeominfo[1].lefttrig
		//		     >> seg.epgeominfo[1].righttrig
		     >> seg.epgeominfo[1].dist;
	      seg.edgenr = seg.epgeominfo[0].edgenr;

	      seg.surfnr1--;
	      seg.surfnr2--;
	      
	      AddSegment (seg);
	    }
	}
      
      if (strcmp (str, "points") == 0)
	{
	  infile >> n;
	  PrintMessage (3, n, " points");
	  for (i = 1; i <= n; i++)
	    {
	      Point3d p;
	      infile >> p.X() >> p.Y() >> p.Z();
	      p.X() *= scale;
	      p.Y() *= scale;
	      p.Z() *= scale;
	      AddPoint (p);
	    }
	}

      if (strcmp (str, "identifications") == 0)
	{
	  infile >> n;
	  for (i = 1; i <= n; i++)
	    {
	      PointIndex pi1, pi2;
	      int ind;
	      infile >> pi1 >> pi2 >> ind;
	      ident.Add (pi1, pi2, ind);
	    }
	}
      if (strcmp (str, "materials") == 0)
	{
	  infile >> n;
	  for (i = 1; i <= n; i++)
	    {
	      int nr;
	      string mat;
	      infile >> nr >> mat;
	      SetMaterial (nr, mat.c_str());
	    }
	}

      strcpy (str, "");
    }
  
  CalcSurfacesOfNode ();
  //  BuildConnectedNodes ();
  topology -> Update();
  clusters -> Update();
  
  SetNextMajorTimeStamp();
  //  PrintMemInfo (cout);
}
  
   

bool Mesh :: TestOk () const
{
  for (ElementIndex ei = 0; ei < volelements.Size(); ei++)
    {
      for (int j = 0; j < 4; j++)
	if ( (*this)[ei][j] <= PointIndex::BASE-1)
	  {
	    (*testout) << "El " << ei << " has 0 nodes: ";
	    for (int k = 0; k < 4; k++)
	      (*testout) << (*this)[ei][k];
	    break;
	  }
    }
  CheckMesh3D (*this);
  return 1;
}

void Mesh :: CalcSurfacesOfNode ()
{
  int i, j, k;
  SurfaceElementIndex sei;

  surfacesonnode.SetSize (GetNP());
  if (boundaryedges)
    delete boundaryedges;
  if (surfelementht)
    delete surfelementht;
  if (segmentht)
    delete segmentht;

  boundaryedges = new INDEX_2_CLOSED_HASHTABLE<int>
    (3 * (GetNSE() + GetNOpenElements()) + GetNSeg() + 1);
  surfelementht = new INDEX_3_HASHTABLE<int> (GetNSE()/4 + 1);
  segmentht = new INDEX_2_HASHTABLE<int> (GetNSeg() + 1);

  for (sei = 0; sei < GetNSE(); sei++)
    {
      const Element2d & sel = surfelements[sei];
      if (sel.IsDeleted()) continue;

      int si = sel.GetIndex();
      
      for (j = 0; j < sel.GetNP(); j++)
	{
	  PointIndex pi = sel[j];
	  bool found = 0;
	  for (k = 0; k < surfacesonnode[pi].Size(); k++)
	    if (surfacesonnode[pi][k] == si)
	      {
		found = 1;
		break;
	      }
	  
	  if (!found)
	    surfacesonnode.Add (pi, si);

	  INDEX_2 i2;
	  i2.I1() = sel.PNumMod(j+1);
	  i2.I2() = sel.PNumMod(j+2);
	  i2.Sort();
	  if (sel.GetNP() <= 4)
	    boundaryedges->Set (i2, 1);
	}
    }

  for (sei = 0; sei < GetNSE(); sei++)
    {
      const Element2d & sel = surfelements[sei];
      if (sel.IsDeleted()) continue;

      INDEX_3 i3;
      i3.I1() = sel.PNum(1);
      i3.I2() = sel.PNum(2);
      i3.I3() = sel.PNum(3);
      i3.Sort();
      surfelementht -> PrepareSet (i3);
    }

  surfelementht -> AllocateElements();
  for (sei = 0; sei < GetNSE(); sei++)
    {
      const Element2d & sel = surfelements[sei];
      if (sel.IsDeleted()) continue;

      INDEX_3 i3;
      i3.I1() = sel.PNum(1);
      i3.I2() = sel.PNum(2);
      i3.I3() = sel.PNum(3);
      i3.Sort();
      surfelementht -> Set (i3, sel.GetIndex());
    }

  int np = GetNP();
  ptyps.SetSize(np);
  ptyps = INNERPOINT;

  if (GetNFD() == 0) //  || GetFaceDescriptor(1).SurfNr() == 0)
    {
      for (sei = 0; sei < GetNSE(); sei++)
	{
	  const Element2d & sel = surfelements[sei];
	  if (sel.IsDeleted()) continue;
	  for (j = 0;  j < sel.GetNP(); j++)
	    {
	      PointIndex pi = SurfaceElement(sei)[j];
	      ptyps[pi] = FIXEDPOINT;
	    }
	}
    }
  else
    {
      for (sei = 0; sei < GetNSE(); sei++)
	{
	  const Element2d & sel = surfelements[sei];
	  if (sel.IsDeleted()) continue;
	  for (j = 0; j < sel.GetNP(); j++)
	    {
	      int pi = sel[j];
	      int ns = surfacesonnode[pi].Size();
	      if (ns == 1)
		ptyps[pi] = SURFACEPOINT;
	      if (ns == 2)
		ptyps[pi] = EDGEPOINT;
	      if (ns >= 3)
		ptyps[pi] = FIXEDPOINT;
	    }      
	}
    }

  for (i = 0; i < segments.Size(); i++)
    {
      const Segment & seg = segments[i];
      for (j = 1; j <= 2; j++)
	{
	  PointIndex hi = (j == 1) ? seg.p1 : seg.p2;
	  
	  if (ptyps[hi] == INNERPOINT ||
	      ptyps[hi] == SURFACEPOINT)
	    ptyps[hi] = EDGEPOINT;
	}
    }


  for (i = 0; i < lockedpoints.Size(); i++)
    ptyps[lockedpoints[i]] = FIXEDPOINT;
  
  for (i = 0; i < openelements.Size(); i++)
    {
      const Element2d & sel = openelements[i];
      for (j = 0; j < sel.GetNP(); j++)
	{
	  INDEX_2 i2;
	  i2.I1() = sel.PNumMod(j+1);
	  i2.I2() = sel.PNumMod(j+2);
	  i2.Sort();
	  boundaryedges->Set (i2, 1);

	  ptyps[sel[j]] = FIXEDPOINT;
	}
    }

  eltyps.SetSize (GetNE());
  eltyps = FREEELEMENT;

  for (i = 0; i < GetNSeg(); i++)
    {
      const Segment & seg = segments[i];
      INDEX_2 i2(seg.p1, seg.p2);
      i2.Sort();

      boundaryedges -> Set (i2, 2);
      segmentht -> Set (i2, 1);
    }
}


void Mesh :: FixPoints (const BitArray & fixpoints)
{
  if (fixpoints.Size() != GetNP())
    {
      cerr << "Mesh::FixPoints: sizes don´t fit" << endl;
      return;
    }
  int np = GetNP();
  for (int i = 1; i <= np; i++)
    if (fixpoints.Test(i))
      {
	ptyps.Elem(i) = FIXEDPOINT;
      }
}


void Mesh :: FindOpenElements (int dom)
{
  int i, ii, j, k, l;
  PointIndex pi;
  SurfaceElementIndex sei;
  Element2d hel;



  if (1)   
    { // nodebased 

      int np = GetNP();
      int ne = GetNE();
      int nse = GetNSE();

      ARRAY<int,PointIndex::BASE> numonpoint(np);

      Element2d hel;

      numonpoint = 0;
      /*
      for (i = 1; i <= np; i++)
	numonpoint.Elem(i) = 0;
      */
      ElementIndex ei;
      for (ei = 0; ei < ne; ei++)
	{
	  const Element & el = (*this)[ei];
	  if (el.GetNP() == 4)
	    {
	      INDEX_4 i4(el[0], el[1], el[2], el[3]);
	      i4.Sort();
	      numonpoint[i4.I1()]++;
	      numonpoint[i4.I2()]++;
	    }
	  else
	    for (j = 0; j < el.GetNP(); j++)
	      numonpoint[el[j]]++;
	}
      TABLE<ElementIndex,PointIndex::BASE> elsonpoint(numonpoint);
      for (ei = 0; ei < ne; ei++)
	{
	  const Element & el = (*this)[ei];
	  if (el.GetNP() == 4)
	    {
	      INDEX_4 i4(el[0], el[1], el[2], el[3]);
	      i4.Sort();
	      elsonpoint.Add (i4.I1(), ei);
	      elsonpoint.Add (i4.I2(), ei);
	    }
	  else
	    for (j = 0; j < el.GetNP(); j++)
	      elsonpoint.Add (el[j], ei);
	}

      numonpoint = 0;
      for (i = 0; i < nse; i++)
	{
	  hel = surfelements[i];
	  hel.NormalizeNumbering();	  
	  numonpoint[hel[0]]++;
	}

      TABLE<SurfaceElementIndex,PointIndex::BASE> selsonpoint(numonpoint);
      for (i = 0; i < nse; i++)
	{
	  hel = surfelements[i];
	  hel.NormalizeNumbering();	  
	  selsonpoint.Add (hel[0], i);
	}


      INDEX_3_CLOSED_HASHTABLE<INDEX_2> faceht(100);   
      openelements.SetSize(0);
      
      for (pi = PointIndex::BASE; 
	   pi < np+PointIndex::BASE; pi++)
	{
	  faceht.SetSize (2 * selsonpoint[pi].Size() + 4 * elsonpoint[pi].Size());


	  FlatArray<SurfaceElementIndex> row = selsonpoint[pi];
	  for (ii = 0; ii < row.Size(); ii++)
	    {
	      hel = SurfaceElement(row[ii]);
	      int ind = hel.GetIndex();	  
  
	      if (GetFaceDescriptor(ind).DomainIn() && 
		  (dom == 0 || dom == GetFaceDescriptor(ind).DomainIn()) )
		{
		  hel.NormalizeNumbering();
		  if (hel.PNum(1) == pi)
		    {
		      INDEX_3 i3(hel[0], hel[1], hel[2]);
		      INDEX_2 i2 (GetFaceDescriptor(ind).DomainIn(), 
				  (hel.GetNP() == 3) 
				  ? PointIndex (PointIndex::BASE-1)
				  : hel.PNum(4));
		      faceht.Set (i3, i2);
		    }
		}
	      if (GetFaceDescriptor(ind).DomainOut() &&
		  (dom == 0 || dom == GetFaceDescriptor(ind).DomainOut()) )
		{
		  hel.Invert();
		  hel.NormalizeNumbering();
		  if (hel.PNum(1) == pi)
		    {
		      INDEX_3 i3(hel[0], hel[1], hel[2]);
		      INDEX_2 i2 (GetFaceDescriptor(ind).DomainOut(), 
				  (hel.GetNP() == 3) 
				  ? PointIndex (PointIndex::BASE-1)
				  : hel.PNum(4));
		      faceht.Set (i3, i2);
		    }
		}
	    }

	  
	  FlatArray<ElementIndex> rowel = elsonpoint[pi];
	  for (ii = 0; ii < rowel.Size(); ii++)
	    {
	      const Element & el = VolumeElement(rowel[ii]);

	      if (dom == 0 || el.GetIndex() == dom)
		{
		  for (j = 1; j <= el.GetNFaces(); j++)
		    {
		      el.GetFace (j, hel);
		      hel.Invert();
		      hel.NormalizeNumbering();

		      if (hel[0] == pi)
			{
			  INDEX_3 i3(hel[0], hel[1], hel[2]);
			  
			  if (faceht.Used (i3))
			    {
			      INDEX_2 i2 = faceht.Get(i3);
			      if (i2.I1() == el.GetIndex())
				{
				  i2.I1() = PointIndex::BASE-1;
				  faceht.Set (i3, i2);
				}
			      else
				{
				  if (i2.I1() == 0)
				    {
				      PrintSysError ("more elements on face");
				      (*testout)  << "more elements on face!!!" << endl;
				      (*testout) << "el = " << el << endl;
				      (*testout) << "hel = " << hel << endl;
				      (*testout) << "face = " << i3 << endl;
				      (*testout) << "points = " << endl;
				      for (int jj = 1; jj <= 3; jj++)
					(*testout) << "p = " << Point(i3.I(jj)) << endl;
				    }
				}
			    }
			  else
			    {
			      hel.Invert();
			      hel.NormalizeNumbering();
			      INDEX_3 i3(hel[0], hel[1], hel[2]);
			      INDEX_2 i2(el.GetIndex(), 
					 (hel.GetNP() == 3) 
					 ? PointIndex (PointIndex::BASE-1)
					 : hel[3]);
			      faceht.Set (i3, i2);
			    }
			}
		    }
		}
	    }

	  for (i = 1; i <= faceht.Size(); i++)
	    if (faceht.UsedPos (i))
	      {
		INDEX_3 i3;
		INDEX_2 i2;
		faceht.GetData (i, i3, i2);
		if (i2.I1() != PointIndex::BASE-1)
		  {
		    Element2d tri;
		    tri.SetType ( (i2.I2() == PointIndex::BASE-1) ? TRIG : QUAD);
		    for (l = 0; l < 3; l++)
		      tri[l] = i3.I(l+1);
		    tri.PNum(4) = i2.I2();
		    tri.SetIndex (i2.I1());

		    //	tri.Invert();
		    
		    openelements.Append (tri);
		  }
	      }
	}
    }

  else if (GetNE() || 1)
    {
      // new version, general elemetns
      // hash index: pnum1-3
      // hash data : domain nr, pnum4

      openelements.SetSize(0);
      

      const int steps = 4;

      for (k = 0; k < steps; k++)
	{
	  
	  INDEX_3_CLOSED_HASHTABLE<INDEX_2> faceht( (5 * GetNE() + 2 * GetNSE() ) / steps +1);   
	  
	  for (i = 1; i <= GetNSE(); i++)
	    {
	      hel = SurfaceElement(i);
	      int ind = hel.GetIndex();	  
	      
	      
	      if (GetFaceDescriptor(ind).DomainIn() && 
		  (dom == 0 || dom == GetFaceDescriptor(ind).DomainIn()) )
		{
		  hel.Invert();
		  hel.NormalizeNumbering();
		  if (hel.PNum(1) % steps == k)
		    {
		      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
		      INDEX_2 i2 (GetFaceDescriptor(ind).DomainIn(), 
				  (hel.GetNP() == 3) 
				  ? PointIndex (PointIndex::BASE-1)
				  : hel.PNum(4));
		      faceht.Set (i3, i2);
		    }
		}
	      if (GetFaceDescriptor(ind).DomainOut() &&
		  (dom == 0 || dom == GetFaceDescriptor(ind).DomainOut()) )
		{
		  hel.NormalizeNumbering();
		  if (hel.PNum(1) % steps == k)
		    {
		      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
		      INDEX_2 i2 (GetFaceDescriptor(ind).DomainOut(), 
				  (hel.GetNP() == 3) 
				  ? PointIndex(0)
				  : hel.PNum(4));
		      faceht.Set (i3, i2);
		    }
		}
	    }

	  for (i = 1; i <= GetNE(); i++)
	    {
	      const Element & el = VolumeElement(i);
	      
	      if (dom == 0 || el.GetIndex() == dom)
		{
		  for (j = 1; j <= el.GetNFaces(); j++)
		    {
		      el.GetFace (j, hel);
		      
		      hel.NormalizeNumbering();
		      if (hel.PNum(1) % steps != k)
			continue;
		      
		      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));

		      int pos = faceht.Position (i3);
		      if (pos)
			{
			  INDEX_2 i2;
			  faceht.GetData (pos, i2);
			  if (i2.I1() == el.GetIndex())
			    {
			      i2.I1() = 0;
			      faceht.SetData (pos, i2);
			    }
			  else
			    {
			      if (i2.I1() == 0)
				PrintSysError ("more elements on face");
			    }
			}
		      else
			{
			  hel.Invert();
			  hel.NormalizeNumbering();
			  INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
			  INDEX_2 i2(el.GetIndex(), 
				     (hel.GetNP() == 3) 
				     ? PointIndex(0)
				     : hel.PNum(4));
			  faceht.Set (i3, i2);
			}
		    }
		}
	    }  
	  
	  for (i = 1; i <= faceht.Size(); i++)
	    if (faceht.UsedPos (i))
	      {
		INDEX_3 i3;
		INDEX_2 i2;
		faceht.GetData (i, i3, i2);
		if (i2.I1() != 0)
		  {
		    Element2d tri;
		    tri.SetType ( (i2.I2() == 0) ? TRIG : QUAD);
		    for (l = 1; l <= 3; l++)
		      tri.PNum(l) = i3.I(l);
		    tri.PNum(4) = i2.I2();
		    tri.SetIndex (i2.I1());

		    tri.Invert();
		    
		    openelements.Append (tri);
		  }
	      }
	  /*
	  cout << "FindOpenElements, mem = ";
	  faceht.PrintMemInfo (cout);
	  */
	}




      /*
	// open hashing version:

	INDEX_3_HASHTABLE<INDEX_2> faceht(4 * GetNE()+GetNSE()+1);   
 
      for (i = 1; i <= GetNSE(); i++)
	{
	  Element2d hel = SurfaceElement(i);
	  int ind = hel.GetIndex();	  
	  

	  if (GetFaceDescriptor(ind).DomainIn() && 
	      (dom == 0 || dom == GetFaceDescriptor(ind).DomainIn()) )
	    {
	      hel.NormalizeNumbering();
	      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
	      INDEX_2 i2 (GetFaceDescriptor(ind).DomainIn(), 
			  (hel.GetNP() == 3) ? 0 : hel.PNum(4));
	      faceht.Set (i3, i2);
	    }
	  if (GetFaceDescriptor(ind).DomainOut() &&
	      (dom == 0 || dom == GetFaceDescriptor(ind).DomainOut()) )
	    {
	      hel.Invert();
	      hel.NormalizeNumbering();
	      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
	      INDEX_2 i2 (GetFaceDescriptor(ind).DomainOut(), 
			  (hel.GetNP() == 3) ? 0 : hel.PNum(4));
	      faceht.Set (i3, i2);
	    }
	}

      for (i = 1; i <= GetNE(); i++)
	{
	  const Element & el = VolumeElement(i);
	  //	  INDEX_3 i3;

	  if (dom == 0 || el.GetIndex() == dom)
	    {
	      for (j = 1; j <= el.GetNFaces(); j++)
		{
		  Element2d hel;
		  el.GetFace (j, hel);
		  hel.Invert();
		  
		  hel.NormalizeNumbering();
		  INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
		  
		  if (faceht.Used (i3))
		    {
		      INDEX_2 i2 = faceht.Get(i3);
		      if (i2.I1() == el.GetIndex())
			{
			  i2.I1() = 0;
			  faceht.Set (i3, i2);
			}
		      else
			{
			  if (i2.I1() == 0)
			    PrintSysError ("more elements on face");
			}
		    }
		  else
		    {
		      hel.Invert();
		      hel.NormalizeNumbering();
		      INDEX_3 i3(hel.PNum(1), hel.PNum(2), hel.PNum(3));
		      INDEX_2 i2(el.GetIndex(), 
				 (hel.GetNP() == 3) ? 0 : hel.PNum(4));
		      faceht.Set (i3, i2);
		    }
		}
	    }
	}  

      
      openelements.SetSize(0);
      for (i = 1; i <= faceht.GetNBags(); i++)
	for (j = 1; j <= faceht.GetBagSize(i); j++)
	  {
	    INDEX_3 i3;
	    INDEX_2 i2;
	    faceht.GetData (i, j, i3, i2);
	    if (i2.I1() != 0)
	      {
		Element2d tri;
		tri.SetNP ( (i2.I2() == 0) ? 3 : 4);
		for (k = 1; k <= 3; k++)
		  tri.PNum(k) = i3.I(k);
		tri.PNum(4) = i2.I2();
		tri.SetIndex (i2.I1());

		openelements.Append (tri);
	      }
	  }
      */

    }
  else 
    {
      for (i = 1; i <= GetNSE(); i++)
	{
	  Element2d hel = SurfaceElement(i);
	  int ind = SurfaceElement(i).GetIndex();

	  if (GetFaceDescriptor(ind).DomainIn())
	    openelements.Append (hel);
	  if (GetFaceDescriptor(ind).DomainOut())
	    {
	      hel.Invert();
	      openelements.Append (hel);
	    }
	}
    }


  int cnt3 = 0, cnt4 = 0;
  for (i = 1; i <= openelements.Size(); i++)
    if (openelements.Elem(i).GetNP() == 3)
      cnt3++;
    else
      cnt4++;


  MyStr treequad;
  if (cnt4)
    treequad = MyStr(" (") + MyStr(cnt3) + MyStr (" + ") + 
      MyStr(cnt4) + MyStr(")");

  PrintMessage (5, openelements.Size(), treequad, " open elements");


  for (i = 1; i <= openelements.Size(); i++)
    {
      const Element2d & sel = openelements.Get(i);

      if (boundaryedges)
	for (j = 1; j <= sel.GetNP(); j++)
	  {
	    INDEX_2 i2;
	    i2.I1() = sel.PNumMod(j);
	    i2.I2() = sel.PNumMod(j+1);
	    i2.Sort();
	    boundaryedges->Set (i2, 1);
	  }
      
      for (j = 1; j <= 3; j++)
	{
	  int pi = sel.PNum(j);
	  if (pi < ptyps.Size()+PointIndex::BASE)
	    ptyps[pi] = FIXEDPOINT;
	}
    }


  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment(i);
      INDEX_2 i2(seg.p1, seg.p2);
      i2.Sort();

      if (!boundaryedges->Used (i2))
	cerr << "WARNING: no boundedge, but seg edge: " << i2 << endl;

      boundaryedges -> Set (i2, 2);
      segmentht -> Set (i2, 1);
    }
}

int Mesh :: HasOpenQuads () const
{
  int i;
  int no = GetNOpenElements();
  for (i = 1; i <= no; i++)
    if (OpenElement(i).GetNP() == 4)
      return 1;
  return 0;
}





void Mesh :: FindOpenSegments (int surfnr)
{
  int i, j, k;

  // new version, general elemetns
  // hash index: pnum1-2
  // hash data : surfnr,  surfel-nr (pos) or segment nr(neg)
  INDEX_2_HASHTABLE<INDEX_2> faceht(4 * GetNSE()+GetNSeg()+1);   
  
  PrintMessage (5, "Test Opensegments");
  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment (i);

      if (surfnr == 0 || seg.si == surfnr)
	{
	  INDEX_2 key(seg.p1, seg.p2);
	  INDEX_2 data(seg.si, -i);

	  if (faceht.Used (key))
	    {
	      cerr << "ERROR: Segment " << seg << " already used" << endl;
	      (*testout) << "ERROR: Segment " << seg << " already used" << endl;
	    }

	  faceht.Set (key, data);
	}
    }


  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment (i);

      if (surfnr == 0 || seg.si == surfnr)
	{
	  INDEX_2 key(seg.p2, seg.p1);
	  if (!faceht.Used(key))
	    {
	      cerr << "ERROR: Segment " << seg << " brother not used" << endl;
	      (*testout) << "ERROR: Segment " << seg << " brother not used" << endl;
	    }
	}
    }



  
  for (i = 1; i <= GetNSE(); i++)
    {
      const Element2d & el = SurfaceElement(i);
      
      if (surfnr == 0 || el.GetIndex() == surfnr)
	{
	  for (j = 1; j <= el.GetNP(); j++)
	    {
	      INDEX_2 seg (el.PNumMod(j), el.PNumMod(j+1));
	      INDEX_2 data;

	      if (faceht.Used(seg))
		{
		  data = faceht.Get(seg);
		  if (data.I1() == el.GetIndex())
		    {
		      data.I1() = 0;
		      faceht.Set (seg, data);
		    }
		  else
		    {
		      PrintSysError ("hash table si not fitting for segment: ",
				     seg.I1(), "-", seg.I2(), " other = ",
				     data.I2());
		    }
		}
	      else
		{
		  Swap (seg.I1(), seg.I2());
		  data.I1() = el.GetIndex();
		  data.I2() = i;

		  faceht.Set (seg, data);
		}
	    }
	}
    }  
  
  (*testout) << "open segments: " << endl;
  opensegments.SetSize(0);
  for (i = 1; i <= faceht.GetNBags(); i++)
    for (j = 1; j <= faceht.GetBagSize(i); j++)
      {
	INDEX_2 i2;
	INDEX_2 data;
	faceht.GetData (i, j, i2, data);
	if (data.I1())  // surfnr
	  {
	    Segment seg;
	    seg.p1 = i2.I1();
	    seg.p2 = i2.I2();
	    seg.si = data.I1();

	    // find geomdata:
	    if (data.I2() > 0)
	      {
		// segment due to triangle
		const Element2d & el = SurfaceElement (data.I2());
		for (k = 1; k <= el.GetNP(); k++)
		  {
		    if (seg.p1 == el.PNum(k))
		      seg.geominfo[0] = el.GeomInfoPi(k);
		    if (seg.p2 == el.PNum(k))
		      seg.geominfo[1] = el.GeomInfoPi(k);
		  }

		(*testout) << "trig seg: ";
	      }
	    else
	      {
		// segment due to line
		const Segment & lseg = LineSegment (-data.I2());
		seg.geominfo[0] = lseg.geominfo[0];
		seg.geominfo[1] = lseg.geominfo[1];

		(*testout) << "line seg: ";
	      }
	    
	    (*testout) << seg.p1 << " - " << seg.p2 
		       << " len = " << Dist (Point(seg.p1), Point(seg.p2))
		       << endl;

	    opensegments.Append (seg);
	    if (seg.geominfo[0].trignum <= 0 || seg.geominfo[1].trignum <= 0)
	      {
		(*testout) << "Problem with open segment: " << seg << endl;
	      }

	  }
      }

  PrintMessage (3, opensegments.Size(), " open segments found");
  (*testout) << opensegments.Size() << " open segments found" << endl;
  
  ptyps.SetSize (GetNP());
  for (i = 1; i <= ptyps.Size(); i++)
    ptyps.Elem(i) = SURFACEPOINT;

  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment (i);
      ptyps.Elem(seg.p1) = EDGEPOINT;
      ptyps.Elem(seg.p2) = EDGEPOINT;
    }
  for (i = 1; i <= GetNOpenSegments(); i++)
    {
      const Segment & seg = GetOpenSegment (i);
      ptyps.Elem(seg.p1) = EDGEPOINT;
      ptyps.Elem(seg.p2) = EDGEPOINT;
    }
  
  
  /*

  for (i = 1; i <= openelements.Size(); i++)
    {
      const Element2d & sel = openelements.Get(i);

      if (boundaryedges)
	for (j = 1; j <= sel.GetNP(); j++)
	  {
	    INDEX_2 i2;
	    i2.I1() = sel.PNumMod(j);
	    i2.I2() = sel.PNumMod(j+1);
	    i2.Sort();
	    boundaryedges->Set (i2, 1);
	  }
      
      for (j = 1; j <= 3; j++)
	{
	  int pi = sel.PNum(j);
	  if (pi <= ptyps.Size())
	    ptyps.Elem(pi) = FIXEDPOINT;
	}
    }
  */
}


void Mesh :: RemoveOneLayerSurfaceElements ()
{
  int i, j;
  int np = GetNP();

  FindOpenSegments();
  BitArray frontpoints(np);

  frontpoints.Clear();
  for (i = 1; i <= GetNOpenSegments(); i++)
    {
      const Segment & seg = GetOpenSegment(i);
      frontpoints.Set (seg.p1);
      frontpoints.Set (seg.p2);
    }

  for (i = 1; i <= GetNSE(); i++)
    {
      Element2d & sel = surfelements.Elem(i);
      int remove = 0;
      for (j = 1; j <= sel.GetNP(); j++)
	if (frontpoints.Test(sel.PNum(j)))
	  remove = 1;
      if (remove)
	sel.PNum(1) = 0;
    }

  for (i = surfelements.Size(); i >= 1; i--)
    {
      if (surfelements.Elem(i).PNum(1) == 0)
	{
	  surfelements.Elem(i) = surfelements.Last();
	  surfelements.DeleteLast();
	}
    }
  timestamp = NextTimeStamp();
  //  Compress();
}





void Mesh :: FreeOpenElementsEnvironment (int layers)
{
  int i, j, k;
  PointIndex pi;
  const int large = 9999;
  ARRAY<int,PointIndex::BASE> dist(GetNP());

  dist = large;

  for (i = 1; i <= GetNOpenElements(); i++)
    {
      const Element2d & face = OpenElement(i);
      for (j = 1; j <= face.GetNP(); j++)
	dist[face.PNum(j)] = 1;
    }

  for (k = 1; k <= layers; k++)
    for (i = 1; i <= GetNE(); i++)
      {
	const Element & el = VolumeElement(i);
	if (el[0] == -1 || el.IsDeleted()) continue;

	int elmin = large;
	for (j = 0; j < el.GetNP(); j++)
	  if (dist[el[j]] < elmin)
	    elmin = dist[el[j]];

	if (elmin < large)
	  {
	    for (j = 0; j < el.GetNP(); j++)
	      if (dist[el[j]] > elmin+1)
		dist[el[j]] = elmin+1;
	  }
      }

  int cntfree = 0;
  for (i = 1; i <= GetNE(); i++)
    {
      const Element & el = VolumeElement(i);
      if (el[0] == -1 || el.IsDeleted()) continue;
	
      int elmin = large;
      for (j = 0; j < el.GetNP(); j++)
	if (dist[el[j]] < elmin)
	  elmin = dist[el[j]];
      
      eltyps.Elem(i) = (elmin <= layers) ? 
	FREEELEMENT : FIXEDELEMENT;
      if (elmin <= layers)
	cntfree++;
    }

  PrintMessage (5, "free: ", cntfree, ", fixed: ", GetNE()-cntfree);
  (*testout) << "free: " << cntfree << ", fixed: " << GetNE()-cntfree << endl;

  for (pi = PointIndex::BASE; 
       pi < GetNP()+PointIndex::BASE; pi++)
    {
      if (dist[pi] > layers+1)
	ptyps[pi] = FIXEDPOINT;
    }
}



void Mesh :: SetLocalH (const Point3d & pmin, const Point3d & pmax, double grading)
{
  Point3d c = Center (pmin, pmax);
  double d = max3 (pmax.X()-pmin.X(),
		   pmax.Y()-pmin.Y(),
		   pmax.Z()-pmin.Z());
  d /= 2;
  Point3d pmin2 = c - Vec3d (d, d, d);
  Point3d pmax2 = c + Vec3d (d, d, d);
  

  delete lochfunc;
  lochfunc = new LocalH (pmin2, pmax2, grading);
}

void Mesh :: RestrictLocalH (const Point3d & p, double hloc)
{
  // cout << "restrict h in " << p << " to " << hloc << endl;
  if (!lochfunc)
    {
      PrintWarning("RestrictLocalH called, creating mesh-size tree");

      Point3d boxmin, boxmax;
      GetBox (boxmin, boxmax);
      SetLocalH (boxmin, boxmax, 0.8);
    }

  lochfunc -> SetH (p, hloc);
}

void Mesh :: RestrictLocalHLine (const Point3d & p1, 
				 const Point3d & p2,
				 double hloc)
{
  // cout << "restrict h along " << p1 << " - " << p2 << " to " << hloc << endl;
  int i;
  int steps = int (Dist (p1, p2) / hloc) + 2;
  Vec3d v(p1, p2);
  
  for (i = 0; i <= steps; i++)
    {
      Point3d p = p1 + (double(i)/double(steps) * v);
      RestrictLocalH (p, hloc);
    }
}


void Mesh :: SetGlobalH (double h)
{
  hglob = h;
}

double Mesh :: MaxHDomain (int dom) const
{
  if (maxhdomain.Size())
    return maxhdomain.Get(dom);
  else
    return 1e10;
}

void Mesh :: SetMaxHDomain (const ARRAY<double> & mhd)
{
  maxhdomain.SetSize(mhd.Size());
  for (int i = 1; i <= mhd.Size(); i++)
    maxhdomain.Elem(i) = mhd.Get(i);
}


double Mesh :: GetH (const Point3d & p) const
{
  double hmin = hglob;
  if (lochfunc)
    {
      double hl = lochfunc->GetH (p);
      if (hl < hglob)
	hmin = hl;
    }
  return hmin;
}

double Mesh :: GetMinH (const Point3d & pmin, const Point3d & pmax)
{
  double hmin = hglob;
  if (lochfunc)
    {
      double hl = lochfunc->GetMinH (pmin, pmax);
      if (hl < hmin)
	hmin = hl;
    }
  return hmin;
}





double Mesh :: AverageH (int surfnr) const
{
  int i, j, n;
  double hi, hsum;
  double maxh = 0, minh = 1e10;

  hsum = 0;
  n = 0;
  for (i = 1; i <= GetNSE(); i++)
    {
      const Element2d & el = SurfaceElement(i);
      if (surfnr == 0 || el.GetIndex() == surfnr)
	{
	  for (j = 1; j <= 3; j++)
	    {
	      hi = Dist (Point (el.PNumMod(j)), 
			 Point (el.PNumMod(j+1)));

	      hsum += hi;

	      if (hi > maxh) maxh = hi;
	      if (hi < minh) minh = hi;
	      n++;
	    }
	}
    }

  PrintMessage (5, "minh = ", minh, " avh = ", (hsum/n), " maxh = ", maxh);
  return (hsum / n);
}



void Mesh :: CalcLocalH () 
{
  if (!lochfunc)
    {
      Point3d pmin, pmax;
      GetBox (pmin, pmax);
      SetLocalH (pmin, pmax, mparam.grading);
    }

  PrintMessage (3,
		"CalcLocalH: ", 
		GetNP(), " Points ", 
		GetNE(), " Elements ", 
		GetNSE(), " Surface Elements");


  int i;
  for (i = 0; i < GetNSE(); i++)
    {
      const Element2d & el = surfelements[i];
      int j;

      if (el.GetNP() == 3)
	{
	  double hel = -1;
	  for (j = 1; j <= 3; j++)
	    {
	      const Point3d & p1 = points[el.PNumMod(j)];
	      const Point3d & p2 = points[el.PNumMod(j+1)];
	      
	      /*
	      INDEX_2 i21(el.PNumMod(j), el.PNumMod(j+1));
	      INDEX_2 i22(el.PNumMod(j+1), el.PNumMod(j));
	      if (! identifiedpoints->Used (i21) &&
		  ! identifiedpoints->Used (i22) )
	      */
	      if (!ident.UsedSymmetric (el.PNumMod(j),
					el.PNumMod(j+1)))
		{
		  double hedge = Dist (p1, p2);
		  if (hedge > hel)
		    hel = hedge;
		  //		  lochfunc->SetH (Center (p1, p2), 2 * Dist (p1, p2));
		  //		  (*testout) << "trigseth, p1,2 = " << el.PNumMod(j) << ", " << el.PNumMod(j+1) 
		  //			     << " h = " << (2 * Dist(p1, p2)) << endl;
		}
	    }
	  
	  if (hel > 0)
	    {
	      const Point3d & p1 = points[el.PNum(1)];
	      const Point3d & p2 = points[el.PNum(2)];
	      const Point3d & p3 = points[el.PNum(3)];
	      lochfunc->SetH (Center (p1, p2, p3), hel);
	    }
	}
      else
	  {
	    {
	      const Point3d & p1 = points[el.PNum(1)];
	      const Point3d & p2 = points[el.PNum(2)];
	      lochfunc->SetH (Center (p1, p2), 2 * Dist (p1, p2));
	    }
	    {
	      const Point3d & p1 = points[el.PNum(3)];
	      const Point3d & p2 = points[el.PNum(4)];
	      lochfunc->SetH (Center (p1, p2), 2 * Dist (p1, p2));
	    }
	  }
    }

  for (i = 0; i < GetNSeg(); i++)
    {
      const Segment & seg = segments[i];
      const Point3d & p1 = points[seg.p1];
      const Point3d & p2 = points[seg.p2];
      /*
      INDEX_2 i21(seg.p1, seg.p2);
      INDEX_2 i22(seg.p2, seg.p1);
      if (identifiedpoints)
	if (!identifiedpoints->Used (i21) && !identifiedpoints->Used (i22))
      */
      if (!ident.UsedSymmetric (seg.p1, seg.p2))
	{
	  lochfunc->SetH (Center (p1, p2), Dist (p1, p2));
	}
    }
  /*
  cerr << "do vol" << endl;
  for (i = 1; i <= GetNE(); i++)
    {
      const Element & el = VolumeElement(i);
      if (el.GetType() == TET)
	{
	  int j, k;
	  for (j = 2; j <= 4; j++)
	    for (k = 1; k < j; k++)  
	      {
		const Point3d & p1 = Point (el.PNum(j));
		const Point3d & p2 = Point (el.PNum(k));
		lochfunc->SetH (Center (p1, p2), 2 * Dist (p1, p2));
		(*testout) << "set vol h to " << (2 * Dist (p1, p2)) << endl;

	      }
	}
    }
  */

  /*
  const char * meshsizefilename = 
    globflags.GetStringFlag ("meshsize", NULL);
  if (meshsizefilename)
    {
      ifstream msf(meshsizefilename);
      if (msf)
	{
	  int nmsp;
	  msf >> nmsp;
	  for (i = 1; i <= nmsp; i++)
	    {
	      Point3d pi;
	      double hi;
	      msf >> pi.X() >> pi.Y() >> pi.Z();
	      msf >> hi;
	      lochfunc->SetH (pi, hi);
	    }
	}
    }
  */
  //  lochfunc -> Convexify();
  //  lochfunc -> PrintMemInfo (cout);
}



void Mesh :: CalcLocalHFromSurfaceCurvature (double elperr) 
{
  PrintMessage (3, "Calculating local h from Surface curvature");

  if (!lochfunc)
    {
      Point3d pmin, pmax;
      GetBox (pmin, pmax);
      
      SetLocalH (pmin, pmax, mparam.grading);
    }

  
  INDEX_2_HASHTABLE<int> edges(3 * GetNP() + 2);
  INDEX_2_HASHTABLE<int> bedges(GetNSeg() + 2);
  int i, j;

  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment(i);
      INDEX_2 i2(seg.p1, seg.p2);
      i2.Sort();
      bedges.Set (i2, 1);
    }
  for (i = 1; i <= GetNSE(); i++)
    {
      const Element2d & sel = SurfaceElement(i);
      if (!sel.PNum(1))
	continue;
      for (j = 1; j <= 3; j++)
	{
	  INDEX_2 i2(sel.PNumMod(j), sel.PNumMod(j+1));
	  i2.Sort();
	  if (bedges.Used(i2)) continue;

	  if (edges.Used(i2))
	    {
	      int other = edges.Get(i2);

	      const Element2d & elother = SurfaceElement(other);

	      int pi3 = 1;
	      while ( (sel.PNum(pi3) == i2.I1()) || 
		      (sel.PNum(pi3) == i2.I2()))
		pi3++;
	      pi3 = sel.PNum(pi3);

	      int pi4 = 1;
	      while ( (elother.PNum(pi4) == i2.I1()) || 
		      (elother.PNum(pi4) == i2.I2()))
		pi4++;
	      pi4 = elother.PNum(pi4);

	      double rad = ComputeCylinderRadius (Point (i2.I1()),
						  Point (i2.I2()),
						  Point (pi3), 
						  Point (pi4));
	      
	      RestrictLocalHLine (Point(i2.I1()), Point(i2.I2()), rad/elperr);


	      /*	      
	      (*testout) << "pi1,2, 3, 4 = " << i2.I1() << ", " << i2.I2() << ", " << pi3 << ", " << pi4
			 << " p1 = " << Point(i2.I1()) 
			 << ", p2 = " << Point(i2.I2()) 
		//			 << ", p3 = " << Point(pi3) 
		//			 << ", p4 = " << Point(pi4) 
			 << ", rad = " << rad << endl;
	      */
	    }
	  else
	    edges.Set (i2, i);
	}
    }


  // Restrict h due to line segments

  for (i = 1; i <= GetNSeg(); i++)
    {
      const Segment & seg = LineSegment(i);
      const Point3d & p1 = Point(seg.p1);
      const Point3d & p2 = Point(seg.p2);
      RestrictLocalH (Center (p1, p2),  Dist (p1, p2));
    }



      /*


  int i, j;
  int np = GetNP();
  int nseg = GetNSeg();
  int nse = GetNSE();
  
  ARRAY<Vec3d> normals(np);
  BitArray linepoint(np);

  linepoint.Clear();
  for (i = 1; i <= nseg; i++)
    {
      linepoint.Set (LineSegment(i).p1);
      linepoint.Set (LineSegment(i).p2);
    }

  for (i = 1; i <= np; i++)
    normals.Elem(i) = Vec3d(0,0,0);

  for (i = 1; i <= nse; i++)
    {
      Element2d & el = SurfaceElement(i);
      Vec3d nf = Cross (Vec3d (Point (el.PNum(1)), Point(el.PNum(2))),
			Vec3d (Point (el.PNum(1)), Point(el.PNum(3))));
      for (j = 1; j <= 3; j++)
	normals.Elem(el.PNum(j)) += nf;
    }

  for (i = 1; i <= np; i++)
    normals.Elem(i) /= (1e-12 + normals.Elem(i).Length());

  for (i = 1; i <= nse; i++)
    {
      Element2d & el = SurfaceElement(i);
      Vec3d nf = Cross (Vec3d (Point (el.PNum(1)), Point(el.PNum(2))),
			Vec3d (Point (el.PNum(1)), Point(el.PNum(3))));
      nf /= nf.Length();
      Point3d c = Center (Point(el.PNum(1)),
			  Point(el.PNum(2)),
			  Point(el.PNum(3)));
			  
      for (j = 1; j <= 3; j++)
	{
	  if (!linepoint.Test (el.PNum(j)))
	    {
	      double dist = Dist (c, Point(el.PNum(j)));
	      double dn = (nf - normals.Get(el.PNum(j))).Length();
	  
	      RestrictLocalH (Point(el.PNum(j)), dist / (dn+1e-12) /elperr);
	    }
	}
    }
      */
}


void Mesh :: RestrictLocalH (resthtype rht, int nr, double loch)
{
  int i;
  switch (rht)
    {
    case RESTRICTH_FACE:
      {
	for (i = 1; i <= GetNSE(); i++)
	  {
	    const Element2d & sel = SurfaceElement(i);
	    if (sel.GetIndex() == nr)
	      RestrictLocalH (RESTRICTH_SURFACEELEMENT, i, loch);
	  }
	break;
      }
    case RESTRICTH_EDGE:
      {
	for (i = 1; i <= GetNSeg(); i++)
	  {
	    const Segment & seg = LineSegment(i);
	    if (seg.edgenr == nr)
	      RestrictLocalH (RESTRICTH_SEGMENT, i, loch);
	  }
	break;
      }
    case RESTRICTH_POINT:
      {
	RestrictLocalH (Point (nr), loch);
	break;
      }

    case RESTRICTH_SURFACEELEMENT:
      {
	const Element2d & sel = SurfaceElement(nr);
	Point3d p = Center (Point(sel.PNum(1)),
			    Point(sel.PNum(2)),
			    Point(sel.PNum(3)));
	RestrictLocalH (p, loch);
	break;
      }
    case RESTRICTH_SEGMENT:
      {
	const Segment & seg = LineSegment(nr);
	RestrictLocalHLine (Point (seg.p1), Point(seg.p2), loch);
	break;
      }
    }
}


void Mesh :: LoadLocalMeshSize (istream & msf)
{
  PrintMessage (3, "Load local mesh-size");
  int i, nmsp, nmsl;
  msf >> nmsp;
  for (i = 1; i <= nmsp; i++)
    {
      Point3d pi;
      double hi;
      msf >> pi.X() >> pi.Y() >> pi.Z();
      msf >> hi;
      RestrictLocalH (pi, hi);
    }
  msf >> nmsl;
  for (i = 1; i <= nmsl; i++)
    {
      Point3d p1, p2;
      double hi;
      msf >> p1.X() >> p1.Y() >> p1.Z();
      msf >> p2.X() >> p2.Y() >> p2.Z();
      msf >> hi;
      RestrictLocalHLine (p1, p2, hi);
    }  
}



void Mesh :: GetBox (Point3d & pmin, Point3d & pmax, int dom) const
{
  if (points.Size() == 0)
    {
      pmin = pmax = Point3d(0,0,0);
      return;
    }

  if (dom <= 0)
    {
      pmin = Point3d (1e10, 1e10, 1e10);
      pmax = Point3d (-1e10, -1e10, -1e10); 

      for (PointIndex pi = PointIndex::BASE; 
	   pi < GetNP()+PointIndex::BASE; pi++)
	{
	  pmin.SetToMin ( (*this) [pi] );
	  pmax.SetToMax ( (*this) [pi] );
	}
    }
  else
    {
      int j, nse = GetNSE();
      SurfaceElementIndex sei;

      pmin = Point3d (1e10, 1e10, 1e10);
      pmax = Point3d (-1e10, -1e10, -1e10); 
      for (sei = 0; sei < nse; sei++)
	{
	  const Element2d & el = (*this)[sei];
	  if (el.IsDeleted() ) continue;

	  if (dom == -1 || el.GetIndex() == dom)
	    {
	      for (j = 0; j < 3; j++)
		{
		  pmin.SetToMin ( (*this) [el[j]] );
		  pmax.SetToMax ( (*this) [el[j]] );
		}
	    }
	}
    }

  if (pmin.X() > 0.5e10)
    {
      pmin = pmax = Point3d(0,0,0);
    }
}




void Mesh :: GetBox (Point3d & pmin, Point3d & pmax, POINTTYPE ptyp) const
{
  if (points.Size() == 0)
    {
      pmin = pmax = Point3d(0,0,0);
      return;
    }

  pmin = Point3d (1e10, 1e10, 1e10);
  pmax = Point3d (-1e10, -1e10, -1e10); 
  
  for (PointIndex pi = PointIndex::BASE; 
       pi < GetNP()+PointIndex::BASE; pi++)
    if (ptyps[pi] <= ptyp)
      {
	pmin.SetToMin ( (*this) [pi] );
	pmax.SetToMax ( (*this) [pi] );
      }
}




double Mesh :: ElementError (int eli) const
{
  const Element & el = volelements.Get(eli);
  return CalcTetBadness (points.Get(el[0]), points.Get(el[1]),
			 points.Get(el[2]), points.Get(el[3]), -1);
}

void Mesh :: AddLockedPoint (PointIndex pi)
{ 
  lockedpoints.Append (pi); 
}

void Mesh :: ClearLockedPoints ()
{ 
  lockedpoints.SetSize (0); 
}



void Mesh :: Compress ()
{
  int i, j;
  ARRAY<int,PointIndex::BASE> op2np(GetNP());
  ARRAY<Point3d> hpoints;
  BitArrayChar<PointIndex::BASE> pused(GetNP());

  /*
  (*testout) << "volels: " << endl;
  for (i = 1; i <= volelements.Size(); i++)
    {
      for (j = 1; j <= volelements.Get(i).GetNP(); j++)
	(*testout) << volelements.Get(i).PNum(j) << " ";
      (*testout) << endl;
    }
  (*testout) << "np: " << GetNP() << endl;
  */


  for (i = 0; i < volelements.Size(); i++)
    if (volelements[i][0] <= PointIndex::BASE-1 ||
	volelements[i].IsDeleted())
      {
	volelements.Delete(i);
	i--;
      }
  for (i = 0; i < surfelements.Size(); i++)
    if (surfelements[i].IsDeleted())
      {
	surfelements.Delete(i);
	i--;
      }
  for (i = 0; i < segments.Size(); i++)
    if (segments[i].p1 == -1)
      {
	segments.Delete(i);
	i--;
      }

  
  pused.Clear();
  for (i = 0; i < volelements.Size(); i++)
    {
      const Element & el = volelements[i];
      for (j = 0; j < el.GetNP(); j++)
	pused.Set (el[j]);
    }

  for (i = 0; i < surfelements.Size(); i++)
    {
      const Element2d & el = surfelements[i];
      for (j = 0; j < el.GetNP(); j++)
	pused.Set (el[j]);
    }

  for (i = 0; i < segments.Size(); i++)
    {
      const Segment & seg = segments[i];
      pused.Set (seg.p1);
      pused.Set (seg.p2);
    }

  for (i = 0; i < openelements.Size(); i++)
    {
      const Element2d & el = openelements[i];
      for (j = 0; j < el.GetNP(); j++)
	pused.Set(el[j]);
    }

  for (i = 0; i < lockedpoints.Size(); i++)
    pused.Set (lockedpoints[i]);

  /*
  // compress points doesn´t work for identified points !
  if (identifiedpoints)
    {
      for (i = 1; i <= identifiedpoints->GetNBags(); i++)
	if (identifiedpoints->GetBagSize(i))
	  {
	    pused.Set ();
	    break;
	  }
    }
  */
  //  pused.Set();


  int npi = PointIndex::BASE-1;

  for (i = PointIndex::BASE; 
       i < points.Size()+PointIndex::BASE; i++)
    if (pused.Test(i))
      {
	npi++;
	op2np[i] = npi;
	hpoints.Append (points[i]);
      }
    else
      op2np[i] = -1;


  points.SetSize(0);
  for (i = 0; i < hpoints.Size(); i++)
    points.Append (hpoints[i]);


  for (i = 1; i <= volelements.Size(); i++)
    {
      Element & el = VolumeElement(i);
      for (j = 0; j < el.GetNP(); j++)
	el[j] = op2np[el[j]];
    }

  for (i = 1; i <= surfelements.Size(); i++)
    {
      Element2d & el = SurfaceElement(i);
      for (j = 0; j < el.GetNP(); j++)
	el[j] = op2np[el[j]];
    }
  
  for (i = 0; i < segments.Size(); i++)
    {
      Segment & seg = segments[i];
      seg.p1 = op2np[seg.p1];
      seg.p2 = op2np[seg.p2];
    }

  for (i = 1; i <= openelements.Size(); i++)
    {
      Element2d & el = openelements.Elem(i);
      for (j = 0; j < el.GetNP(); j++)
	el[j] = op2np[el[j]];
    }  


  for (i = 0; i < lockedpoints.Size(); i++)
    lockedpoints[i] = op2np[lockedpoints[i]];



  CalcSurfacesOfNode();
  //  FindOpenElements();
  timestamp = NextTimeStamp();

  (*testout) << "compress, done" << endl
	     << "np = " << points.Size()
	     << "ne = " << volelements.Size() << ", type.size = " << eltyps.Size()
	     <<  "volelements = " << volelements << endl;
}


int Mesh :: CheckConsistentBoundary () const
{
  int nf = GetNOpenElements();
  INDEX_2_HASHTABLE<int> edges(nf+2);
  int i, j;
  INDEX_2 i2;
  int err = 0;


  for (i = 1; i <= nf; i++)
    {
      const Element2d & sel = OpenElement(i);
      
      for (j = 1; j <= sel.GetNP(); j++)
	{
	  i2.I1() = sel.PNumMod(j);
	  i2.I2() = sel.PNumMod(j+1);

	  int sign = (i2.I2() > i2.I1()) ? 1 : -1;
	  i2.Sort();
	  if (!edges.Used (i2))
	    edges.Set (i2, 0);

	  edges.Set (i2, edges.Get(i2) + sign);
	  /*

	    if (edges.Used(i2))
	    {
	    int hi;
	    hi = edges.Get(i2);
	    if (hi != 1) 
	    err = 1;
	    edges.Set(i2, 2);
	    cnt2++;
	    }
	    else
	    {
	    Swap (i2.I1(), i2.I2());
	    edges.Set(i2, 1);
	    cnt1++;
	    }
	    */
	}
    }


  /*
    if (cnt1 != cnt2)
    err = 2;
    */

  for (i = 1; i <= edges.GetNBags(); i++)
    for (j = 1; j <= edges.GetBagSize(i); j++)
      {
	int cnt = 0;
	edges.GetData (i, j, i2, cnt);
	if (cnt)
	  {
	    PrintError ("Edge ", i2.I1() , " - ", i2.I2(), " multiple times in surface mesh");
	    err = 2;
	  }
      }

  return err;
}



int Mesh :: CheckOverlappingBoundary () 
{
  int i, j, k;

  Point3d pmin, pmax;
  GetBox (pmin, pmax);
  Box3dTree setree(pmin, pmax);
  ARRAY<int> inters;
  int overlap = 0;

  for (i = 1; i <= GetNSE(); i++)
    SurfaceElement(i).badel = 0;


  for (i = 1; i <= GetNSE(); i++)
    {
      const Element2d & tri = SurfaceElement(i);
      
      Point3d tpmin (Point(tri[0]));
      Point3d tpmax (tpmin);

      for (k = 1; k < tri.GetNP(); k++)
	{
	  tpmin.SetToMin (Point (tri[k]));
	  tpmax.SetToMax (Point (tri[k]));
	}
      Vec3d diag(tpmin, tpmax);

      tpmax = tpmax + 0.1 * diag;
      tpmin = tpmin - 0.1 * diag;

      setree.Insert (tpmin, tpmax, i);
    }

  for (i = 1; i <= GetNSE(); i++)
    {
      const Element2d & tri = SurfaceElement(i);
      
      Point3d tpmin (Point(tri[0]));
      Point3d tpmax (tpmin);

      for (k = 1; k < tri.GetNP(); k++)
	{
	  tpmin.SetToMin (Point (tri[k]));
	  tpmax.SetToMax (Point (tri[k]));
	}

      setree.GetIntersecting (tpmin, tpmax, inters);

      for (j = 1; j <= inters.Size(); j++)
	{
	  const Element2d & tri2 = SurfaceElement(inters.Get(j));	  

	  const Point3d *trip1[3], *trip2[3];	  
	  for (k = 1; k <= 3; k++)
	    {
	      trip1[k-1] = &Point (tri.PNum(k));
	      trip2[k-1] = &Point (tri2.PNum(k));
	    }

	  if (IntersectTriangleTriangle (&trip1[0], &trip2[0]))
	    {
	      overlap = 1;
	      PrintWarning ("Intersecting elements" 
			    ,i, " and ", inters.Get(j));

	      (*testout) << "Intersecting: " << endl;
	      (*testout) << "openelement " << i << " with open element " << inters.Get(j) << endl;

	      for (k = 1; k <= 3; k++)
		(*testout) << tri.PNum(k) << "  ";
	      (*testout) << endl;
	      for (k = 1; k <= 3; k++)
		(*testout) << tri2.PNum(k) << "  ";
	      (*testout) << endl;

	      for (k = 0; k <= 2; k++)
		(*testout) << *trip1[k] << "   ";
	      (*testout) << endl;
	      for (k = 0; k <= 2; k++)
		(*testout) << *trip2[k] << "   ";
	      (*testout) << endl;


	      /*
	      INDEX_3 i3(tri.PNum(1), tri.PNum(2), tri.PNum(3));
	      i3.Sort();
	      for (k = 1; k <= GetNSE(); k++)
		{
		  const Element2d & el2 = SurfaceElement(k);
		  INDEX_3 i3b(el2.PNum(1), el2.PNum(2), el2.PNum(3));
		  i3b.Sort();
		  if (i3 == i3b)
		    {
		      SurfaceElement(k).badel = 1;
		    }
		}
	      */
	      SurfaceElement(i).badel = 1;
	      SurfaceElement(inters.Get(j)).badel = 1;
	    }
	}
    }

  return overlap;
}


int Mesh :: CheckVolumeMesh () const
{
  PrintMessage (3, "Checking volume mesh");
  
  int ne = GetNE();
  DenseMatrix dtrans(3,3);
  int i, j;

  PrintMessage (5, "elements: ", ne);
  for (i = 1; i <= ne; i++)
    {
      Element & el = (Element&) VolumeElement(i);
      el.flags.badel = 0;
      int nip = el.GetNIP();
      for (j = 1; j <= nip; j++)
	{
	  el.GetTransformation (j, Points(), dtrans);
	  double det = dtrans.Det();
	  if (det > 0)
	    {
	      PrintError ("Element ", i , " has wrong orientation");
	      el.flags.badel = 1;
	    }
	}
    }

  return 0;
}


bool Mesh :: LegalTrig (const Element2d & el) const
{
  return 1;
  if ( /* hp */ 1)  // needed for old, simple hp-refinement
    { 
      // trigs with 2 or more segments are illegal
      int i;
      int nseg = 0;

      if (!segmentht)
	{
	  cerr << "no segmentht allocated" << endl;
	  return 0;
	}

      //      Point3d cp(0.5, 0.5, 0.5);
      for (i = 1; i <= 3; i++)
	{
	  INDEX_2 i2(el.PNumMod (i), el.PNumMod (i+1));
	  i2.Sort();
	  if (segmentht -> Used (i2))
	    nseg++;
	}
      if (nseg >= 2) 
	return 0;
    }
  return 1;
}

///
bool Mesh :: LegalTet2 (Element & el) const
{
  //  return 1;
  // Test, whether 4 points have a common surface plus
  // at least 4 edges at the boundary

  int i, j, k;
  
  // non-tets are always legal
  if (el.GetType() != TET)
    {
      el.SetLegal (1);
      return 1;
    }

  // element has at least 2 inner points ---> legal
  int cnti = 0;
  for (j = 1; j <= 4; j++)
    if (PointType(el.PNum(j)) == INNERPOINT)
      cnti++;
  if (cnti >= 2)
    {
      el.SetLegal (1);
      return 1;
    }

  // which faces are boundary faces ?
  Element2d face;
  int bface[4];

  for (i = 1; i <= 4; i++)
    {
      el.GetFace (i, face);
      INDEX_3 i3 (face.PNum(1), face.PNum(2), face.PNum(3));
      i3.Sort();
      bface[i-1] = surfelementht->Used (i3);
    }

  int bedge[4][4];
  int segedge[4][4];
  for (i = 1; i <= 4; i++)
    for (j = 1; j < i; j++)
      {
	INDEX_2 i2(el.PNum(i), el.PNum(j));
	i2.Sort();

	int sege = 0, be = 0;

	if (boundaryedges -> Used(i2))
	  {
	    int val = boundaryedges -> Get(i2);
	    be = 1;
	    if (val == 2)
	      sege = 1;
	  }

	segedge[j-1][i-1] =
	  segedge[i-1][j-1] = sege;

	bedge[j-1][i-1] =
	  bedge[i-1][j-1] = be;
      }


  // two boundary faces and no edge is illegal
  for (i = 0; i < 3; i++)
    for (j = i+1; j < 4; j++)
      {
	if (bface[i] && bface[j])
	  {
	    // common nodes:
	    int pi1 = 0, pi2;
	    while (pi1 == i || pi1 == j)
	      pi1++;
	    pi2 = 6 - i - j - pi1;
	    /*
	    INDEX_2 i2(el.PNum(pi1+1), el.PNum(pi2+1));
	    i2.Sort();
	    if (!segmentht->Used (i2))
	    */
	    if (!segedge[pi1][pi2])
	      {
		// 2 boundary faces withoud edge in between
		//		cout << "p1, p2 = " << pi1 << "," << pi2 << endl;
		//		cout << "tet illegal due to first case" << endl;
		el.SetLegal (0);
		return 0;
	      }
	  }
      }


  // three boundary edges meeting in a Surface point
  for (i = 1; i <= 4; i++)
    {
      int alledges = 1;
      if (PointType(el.PNum(i)) == SURFACEPOINT)
	{
	  for (j = 1; j <= 4; j++)
	    if (j != i)
	      {
		/*
		INDEX_2 i2(el.PNum(i), el.PNum(j));
		i2.Sort();
		if (!boundaryedges->Used(i2))
		*/
		if (!bedge[i-1][j-1])
		  {
		    alledges = 0;
		    break;
		  }
	      }
	  if (alledges)
	    {
	      //	      cout << "tet illegal due to unmarked node" << endl;
	      el.SetLegal (0);
	      return 0;
	    }
	}
    }


  /*  
  {
    // having 3 boundary edges and 4 surface nodes ???
    int nodehasedge[4];
    int canbe = 1;   // can be that illegal tet

    for (i = 0; i < 4; i++)
      nodehasedge[i] = 0;
    for (i = 1; i <= 4; i++)
      {
	if (PointType(el.PNum(i)) != SURFACEPOINT)
	  canbe = 0;
	for (j = i+1; j <= 4; j++)
	  {
	    INDEX_2 i2(el.PNum(i), el.PNum(j));
	    i2.Sort();
	    if (boundaryedges->Used(i2))
	      {
		nodehasedge[i-1] = 1;
		nodehasedge[j-1] = 1;
	      }

	  }
      }
    for (i = 0; i < 4; i++)
      if (!nodehasedge[i])
	canbe = 0;

    if (canbe) return 0;
    
  }
  */

  {
    // two connected edges on surface, but no face

    int ltestmode = 0; // (el.PNum(1) == 10516);

    if (ltestmode)
      {
	(*testout) << "pnums: " << endl;
	for (i = 1; i <= 4; i++)
	  (*testout) << el.PNum(i) << " ";
	(*testout) << endl;
      }

    for (i = 1; i <= 4; i++)
      if (PointType(el.PNum(i)) == SURFACEPOINT)
	for (j = 1; j <= 4; j++)
	  if (j != i)
	    for (k = j+1; k <= 4; k++)
	      if (k != i)
		{
		  int fnr = 10 - i - j - k;

		  if (!bface[fnr-1] &&
		      bedge[i-1][j-1] &&
		      bedge[i-1][k-1])
		    {
		      el.SetLegal (0);
		      return 0;
		    }
		  /*
		  INDEX_2 e1(el.PNum(i), el.PNum(j));
		  e1.Sort();
		  INDEX_2 e2(el.PNum(i), el.PNum(k));
		  e2.Sort();
		  INDEX_3 face(el.PNum(i), el.PNum(j), el.PNum(k));
		  face.Sort();
		  
		  if (ltestmode)
		    {
		      (*testout) << "i, j, k = " << i << ", " << j << ", " << k << endl;
		      (*testout) << "eij = " << boundaryedges->Used(e1) 
				 << " eik = " << boundaryedges->Used(e2) 
				 << " face = " << surfelementht->Used (face) << endl;
		      
		    }
		  
		  if (boundaryedges->Used(e1) && 
		      boundaryedges->Used(e2) &&
		      !surfelementht->Used (face))
		    {
		      //		      cout << "tet illegal due to last case" << endl;
		      el.SetLegal (0);
		      return 0;
		    }
		  */
		}
    
  }


  {
    // connected surface edge and edge edge, but no face

    for (i = 1; i <= 4; i++)
      if (PointType(el.PNum(i)) == EDGEPOINT)
	for (j = 1; j <= 4; j++)
	  if (j != i)
	    for (k = j+1; k <= 4; k++)
	      if (k != i)
		{
		  int fnr = 10 - i - j - k;

		  if (!bface[fnr-1] &&
		      (bedge[i-1][j-1] && segedge[i-1][k-1] ||
		       segedge[i-1][j-1] && bedge[i-1][k-1]))
		    {
		      el.SetLegal (0);
		      return 0;
		    }
		}
    
  }





    
  el.SetLegal (1);
  return 1;
  
      /*
  int i1, i2, i3, i4, j;
  if (PointType(el.PNum(1)) != INNERPOINT && 
      PointType(el.PNum(2)) != INNERPOINT && 
      PointType(el.PNum(3)) != INNERPOINT &&
      PointType(el.PNum(4)) != INNERPOINT)
    {      
      for (i1 = 1; i1 <= surfacesonnode.EntrySize(el.PNum(1)); i1++)
	for (i2 = 1; i2 <= surfacesonnode.EntrySize(el.PNum(2)); i2++)
	  if (surfacesonnode.Get(el.PNum(1), i1) == 
	      surfacesonnode.Get(el.PNum(2), i2))
	    for (i3 = 1; i3 <= surfacesonnode.EntrySize(el.PNum(3)); i3++)
	      if (surfacesonnode.Get(el.PNum(1), i1) == 
		  surfacesonnode.Get(el.PNum(3), i3))
		for (i4 = 1; i4 <= surfacesonnode.EntrySize(el.PNum(4)); i4++)
		  if (surfacesonnode.Get(el.PNum(1), i1) == 
		      surfacesonnode.Get(el.PNum(4), i4))
		    {
		      int j, numbe = 0;
		      INDEX_2 i2;

		      for (j = 1; j <= 6; j++)
			{
			  switch (j)
			    {
			    case 1:
			      i2.I1() = el.PNum(1);
			      i2.I2() = el.PNum(2); break;
			    case 2: 
			      i2.I1() = el.PNum(1); 
			      i2.I2() = el.PNum(3); break;
			    case 3: 
			      i2.I1() = el.PNum(1); 
			      i2.I2() = el.PNum(4); break;
			    case 4:
			      i2.I1() = el.PNum(2); 
			      i2.I2() = el.PNum(3); break;
			    case 5:
			      i2.I1() = el.PNum(2);
			      i2.I2() = el.PNum(4); break;
			    case 6: 
			      i2.I1() = el.PNum(3); 
			      i2.I2() = el.PNum(4); break;
			    }

			  i2.Sort();
			  if (boundaryedges->Used (i2)) numbe++;
			}

		      if (numbe >= 4)
			{
// 			  (*testout) 
// 			    << "Tet illegal: " 
// 			    << "mat = " << el.GetIndex() << " "
// 			    << "surf = " << surfacesonnode.Get(el.PNum(1), i1) 
// 			    << " " 
// 			    << el.PNum(1) << " "
// 			    << el.PNum(2) << " "
// 			    << el.PNum(3) << " "
// 			    << el.PNum(4) << endl;

			  return 0;
			}
		    }
    }
  return 1;
*/
}


int Mesh :: GetNDomains() const
{
  int ndom = 0;

  for (int k = 0; k < facedecoding.Size(); k++)
    {
      if (facedecoding[k].DomainIn() > ndom)
	ndom = facedecoding[k].DomainIn();
      if (facedecoding[k].DomainOut() > ndom)
	ndom = facedecoding[k].DomainOut();
    }

  return ndom;
}



void Mesh :: SurfaceMeshOrientation ()
{
  int i, j;
  int nse = GetNSE();
  
  BitArray used(nse);
  used.Clear();
  INDEX_2_HASHTABLE<int> edges(nse+1);

  bool haschanged = 0;


  const Element2d & tri = SurfaceElement(1);
  for (j = 1; j <= 3; j++)
    {
      INDEX_2 i2(tri.PNumMod(j), tri.PNumMod(j+1));
      edges.Set (i2, 1);
    }
  used.Set(1);

  bool unused;
  do
    {
      bool changed;
      do
	{
	  changed = 0;
	  for (i = 1; i <= nse; i++)
	    if (!used.Test(i))
	      {
		Element2d & el = surfelements.Elem(i);
		int found = 0, foundrev = 0;
		for (j = 1; j <= 3; j++)
		  {
		    INDEX_2 i2(el.PNumMod(j), el.PNumMod(j+1));
		    if (edges.Used(i2))
		      foundrev = 1;
		    Swap (i2.I1(), i2.I2());
		    if (edges.Used(i2))
		      found = 1;
		  }
		
		if (found || foundrev)
		  {
		    if (foundrev)
		      Swap (el.PNum(2), el.PNum(3));
		    
		    changed = 1;
		    for (j = 1; j <= 3; j++)
		      {
			INDEX_2 i2(el.PNumMod(j), el.PNumMod(j+1));
			edges.Set (i2, 1);
		      }
		    used.Set (i);
		  }
	      }
	  if (changed)
	    haschanged = 1;
	}
      while (changed);
      

      unused = 0;
      for (i = 1; i <= nse; i++)
	if (!used.Test(i))
	  {
	    unused = 1;
	    const Element2d & tri = SurfaceElement(i);
	    for (j = 1; j <= 3; j++)
	      {
		INDEX_2 i2(tri.PNumMod(j), tri.PNumMod(j+1));
		edges.Set (i2, 1);
	      }
	    used.Set(i);
	    break;
	  }
    }
  while (unused);

  if (haschanged)
    timestamp = NextTimeStamp();
}
  

void Mesh :: Split2Tets()
{
  int oldne, oldnse;
  int i, j, k, l;
  
  oldne = GetNE(); 
  for (i = 1; i <= oldne; i++)
    {
      Element el = VolumeElement(i);
      if (el.GetType() == PRISM)
	{
	  //	  (*testout) << "split el: " << el << " to ";

	  // prism, to 3 tets
	  
	  // make minimal node to node 1
	  int minpi=0;
	  PointIndex minpnum;
	  minpnum = GetNP() + 1;

	  for (j = 1; j <= 6; j++)
	    {
	      if (el.PNum(j) < minpnum)
		{
		  minpnum = el.PNum(j);
		  minpi = j;
		}
	    }

	  if (minpi >= 4)
	    {
	      for (j = 1; j <= 3; j++)
		Swap (el.PNum(j), el.PNum(j+3));
	      minpi -= 3;
	    }

	  while (minpi > 1)
	    {
	      int hi = 0;
	      for (j = 0; j <= 3; j+= 3)
		{
		  hi = el.PNum(1+j);
		  el.PNum(1+j) = el.PNum(2+j);
		  el.PNum(2+j) = el.PNum(3+j);
		  el.PNum(3+j) = hi;
		}
	      minpi--;
	    }

	  /*
	    version 1: edge from pi2 to pi6,
	    version 2: edge from pi3 to pi5,
	   */

	  (*testout) << " rot el = " << el << " ";

	  static const int ntets[2][12] =
	  { { 1, 4, 5, 6, 1, 2, 3, 6, 1, 2, 5, 6 },
	    { 1, 4, 5, 6, 1, 2, 3, 5, 3, 1, 5, 6 } };

	  const int * min2pi;

	  if (min2 (el.PNum(2), el.PNum(6)) <
	      min2 (el.PNum(3), el.PNum(5)))
	    {
	      min2pi = &ntets[0][0];
	      (*testout) << "version 1 ";
	    }
	  else
	    {
	      min2pi = &ntets[1][0];
	      (*testout) << "version 2 ";
	    }

	  
	  int firsttet = 1;
	  for (j = 1; j <= 3; j++)
	    {
	      Element nel(4);
	      for (k = 1; k <= 4; k++)
		nel.PNum(k) = el.PNum(min2pi[4 * j + k - 5]);
	      nel.SetIndex (el.GetIndex());

	      int legal = 1;
	      for (k = 1; k <= 3; k++)
		for (l = k+1; l <= 4; l++)
		  if (nel.PNum(k) == nel.PNum(l))
		    legal = 0;

	      (*testout) << nel << " ";

	      if (legal)
		{
		  if (firsttet)
		    {
		      VolumeElement(i) = nel;
		      firsttet = 0;
		    }
		  else
		    {
		      AddVolumeElement(nel);
		    }
		}
	    }
	  if (firsttet) (*testout) << "no legal";
	  (*testout) << endl;
	}
      
      
      if (el.GetType() == PYRAMID)
	{
	  // pyramid, to 2 tets
	  


	  static const int ntets[2][8] =
	  { { 1, 2, 3, 5, 1, 3, 4, 5 },
	    { 1, 2, 4, 5, 4, 2, 3, 5 }};

	  const int * min2pi;

	  if (min2 (el.PNum(1), el.PNum(3)) <
	      min2 (el.PNum(2), el.PNum(4)))
	    min2pi = &ntets[0][0];
	  else
	    min2pi = &ntets[1][0];


	  int firsttet = 1;
	  for (j = 1; j <= 2; j++)
	    {
	      Element nel(4);
	      for (k = 1; k <= 4; k++)
		nel.PNum(k) = el.PNum(min2pi[4 * j + k - 5]);
	      nel.SetIndex (el.GetIndex());


	      int legal = 1;
	      for (k = 1; k <= 3; k++)
		for (l = k+1; l <= 4; l++)
		  if (nel.PNum(k) == nel.PNum(l))
		    legal = 0;

	      if (legal)
		{
		  (*testout) << nel << " ";
		  if (firsttet)
		    {
		      VolumeElement(i) = nel;
		      firsttet = 0;
		    }
		  else
		    {
		      AddVolumeElement(nel);
		    }
		}
	    }
	  (*testout) << endl;


	  
	  
	}
    }

  
  oldnse = GetNSE(); 
  for (i = 1; i <= oldnse; i++)
    {
      Element2d el = SurfaceElement(i);
      if (el.GetNP() == 4)
	{
	  (*testout) << "split el: " << el << " to ";
	  
	  static const int ntris[2][6] =
	  { { 1, 2, 3, 1, 3, 4 },
	    { 1, 2, 4, 4, 2, 3 }};

	  const int * min2pi;

	  if (min2 (el.PNum(1), el.PNum(3)) <
	      min2 (el.PNum(2), el.PNum(4)))
	    min2pi = &ntris[0][0];
	  else
	    min2pi = &ntris[1][0];

	  for (j = 0; j <6; j++)
	    (*testout) << min2pi[j] << " ";


	  int firsttri = 1;
	  for (j = 1; j <= 2; j++)
	    {
	      Element2d nel(3);
	      for (k = 1; k <= 3; k++)
		nel.PNum(k) = el.PNum(min2pi[3 * j + k - 4]);
	      nel.SetIndex (el.GetIndex());

	      int legal = 1;
	      for (k = 1; k <= 2; k++)
		for (l = k+1; l <= 3; l++)
		  if (nel.PNum(k) == nel.PNum(l))
		    legal = 0;

	      if (legal)
		{
		  (*testout) << nel << " ";
		  if (firsttri)
		    {
		      SurfaceElement(i) = nel;
		      firsttri = 0;
		    }
		  else
		    {
		      AddSurfaceElement(nel);
		    }
		}
	    }
	  (*testout) << endl;

	}
    }


  for (i = 1; i <= GetNE(); i++)
    {
      Element & el = VolumeElement(i);
      const Point3d & p1 = Point (el.PNum(1));
      const Point3d & p2 = Point (el.PNum(2));
      const Point3d & p3 = Point (el.PNum(3));
      const Point3d & p4 = Point (el.PNum(4));

      double vol = (Vec3d (p1, p2) * 
		    Cross (Vec3d (p1, p3), Vec3d(p1, p4)));
      if (vol > 0)
	Swap (el.PNum(3), el.PNum(4));
    }
  timestamp = NextTimeStamp();
}

void Mesh :: BuildElementSearchTree ()
{
  if (elementsearchtreets == GetTimeStamp())
    return;

  NgLock lock(mutex);
  lock.Lock();

  PrintMessage (4, "Rebuild element searchtree");

  if (elementsearchtree)
    delete elementsearchtree;
  elementsearchtree = NULL;

  Box3d box;
  int i, j;
  int ne = GetNE();
  if (!ne) 
    {
      lock.UnLock();
      return;
    }

  box.SetPoint (Point (VolumeElement(1).PNum(1)));
  for (i = 1; i <= ne; i++)
    {
      const Element & el = VolumeElement(i);
      for (j = 1; j <= el.GetNP(); j++)
	box.AddPoint (Point (el.PNum(j)));
    }
  
  box.Increase (1.01 * box.CalcDiam());
  elementsearchtree = new Box3dTree (box.PMin(), box.PMax());
  


  for (i = 1; i <= ne; i++)
    {
      const Element & el = VolumeElement(i);
      box.SetPoint (Point (el.PNum(1)));
      for (j = 1; j <= el.GetNP(); j++)
	box.AddPoint (Point (el.PNum(j)));

      elementsearchtree -> Insert (box.PMin(), box.PMax(), i);
    }

  elementsearchtreets = GetTimeStamp();

  lock.UnLock();
}


int Mesh :: GetElementOfPoint (const Point3d & p,
			       double lami[3]) const
{
  if (dimension == 2)
    {
      int i, j;
      Vec3d col1, col2, col3;
      Vec3d rhs, sol;
      double eps = 1e-6;
      int ne;
      
      ARRAY<int> locels;
      if (0)
	{
	  elementsearchtree->GetIntersecting (p, p, locels);
	  ne = locels.Size();
	}
      else
	ne = GetNSE();
      
      ARRAY<Element2d> loctrigs;
      Vec3d nv(0, 0, 1);

      for (i = 1; i <= ne; i++)
	{
	  int ii;
	  if (0)
	    ii = locels.Get(i);
	  else
	    ii = i;
	  
	  //	  SurfaceElement(ii).GetTets (loctets);
	  loctrigs.SetSize(1);
	  loctrigs.Elem(1) = SurfaceElement(ii);

	  for (j = 1; j <= loctrigs.Size(); j++)
	    {
	      const Element2d & el = loctrigs.Get(j);
	      
	      const Point3d & p1 = Point(el.PNum(1));
	      const Point3d & p2 = Point(el.PNum(2));
	      const Point3d & p3 = Point(el.PNum(3));
	      
	      /*
	      Box3d box;
	      box.SetPoint (p1);
	      box.AddPoint (p2);
	      box.AddPoint (p3);
	      box.AddPoint (p4);
	      if (!box.IsIn (p))
		continue;
	      */
	      col1 = p2-p1;
	      col2 = p3-p1;
	      col3 = nv;
	      rhs = p - p1;
	      
	      SolveLinearSystem (col1, col2, col3, rhs, sol);
	      
	      if (sol.X() >= -eps && sol.Y() >= -eps && 
		  sol.X() + sol.Y() <= 1+eps)
		{
		  lami[0] = sol.X();
		  lami[1] = sol.Y();
		  lami[2] = sol.Z();
		  return ii;
		}
	    }
	}
      
      return 0;
    }

  else
      
    {
      int i, j;
      Vec3d col1, col2, col3;
      Vec3d rhs, sol;
      double eps = 1e-4;
      int ne;
      
      ARRAY<int> locels;
      if (elementsearchtree)
	{
	  // update if necessary:
	  const_cast<Mesh&>(*this).BuildElementSearchTree (); 
	  elementsearchtree->GetIntersecting (p, p, locels);
	  ne = locels.Size();
	}
      else
	ne = GetNE();
      
      ARRAY<Element> loctets;
      for (i = 1; i <= ne; i++)
	{
	  int ii;
	  if (elementsearchtree)
	    ii = locels.Get(i);
	  else
	    ii = i;
	  
	  VolumeElement(ii).GetTets (loctets);
	  
	  for (j = 1; j <= loctets.Size(); j++)
	    {
	      const Element & el = loctets.Get(j);
	      
	      const Point3d & p1 = Point(el.PNum(1));
	      const Point3d & p2 = Point(el.PNum(2));
	      const Point3d & p3 = Point(el.PNum(3));
	      const Point3d & p4 = Point(el.PNum(4));
	      
	      Box3d box;
	      box.SetPoint (p1);
	      box.AddPoint (p2);
	      box.AddPoint (p3);
	      box.AddPoint (p4);
	      if (!box.IsIn (p))
		continue;
	      
	      col1 = p2-p1;
	      col2 = p3-p1;
	      col3 = p4-p1;
	      rhs = p - p1;
	      
	      SolveLinearSystem (col1, col2, col3, rhs, sol);
	      
	      if (sol.X() >= -eps && sol.Y() >= -eps && sol.Z() >= -eps &&
		  sol.X() + sol.Y() + sol.Z() <= 1+eps)
		{
		  ARRAY<Element> loctetsloc;
		  ARRAY<Point3d> pointsloc;

		  VolumeElement(ii).GetTetsLocal (loctetsloc);
		  VolumeElement(ii).GetNodesLocalNew (pointsloc);

		  const Element & le = loctetsloc.Get(j);
		  
		  Point3d p = 
		    pointsloc.Get(le.PNum(1)) 
		    + sol.X() * Vec3d (pointsloc.Get(le.PNum(1)), pointsloc.Get(le.PNum(2))) 
		    + sol.Y() * Vec3d (pointsloc.Get(le.PNum(1)), pointsloc.Get(le.PNum(3))) 
		    + sol.Z() * Vec3d (pointsloc.Get(le.PNum(1)), pointsloc.Get(le.PNum(4))) ;


		  lami[0] = p.X();
		  lami[1] = p.Y();
		  lami[2] = p.Z();
		  return ii;
		}
	    }
	}
      
      return 0;
    }
}


void Mesh::GetIntersectingVolEls(const Point3d& p1, const Point3d& p2, 
				 ARRAY<int> & locels) const
{
  elementsearchtree->GetIntersecting (p1, p2, locels);
}

void Mesh :: SplitIntoParts()
{
  int i, j, dom;
  int ne = GetNE();
  int np = GetNP();
  int nse = GetNSE();

  BitArray surfused(nse);
  BitArray pused (np);

  surfused.Clear();

  dom = 0;
  
  while (1)
    {
      int cntd = 1;

      dom++;
      
      pused.Clear();

      int found = 0;
      for (i = 1; i <= nse; i++)
	if (!surfused.Test(i))
	  {
	    SurfaceElement(i).SetIndex (dom);
	    for (j = 1; j <= 3; j++)
	      pused.Set (SurfaceElement(i).PNum(j));
	    found = 1;
	    cntd = 1;
	    surfused.Set(i);
	    break;
	  }

      if (!found)
	break;

      int change;
      do
	{
	  change = 0;
	  for (i = 1; i <= nse; i++)
	    {
	      int is = 0, isnot = 0;
	      for (j = 1; j <= 3; j++)
		if (pused.Test(SurfaceElement(i).PNum(j)))
		  is = 1;
		else
		  isnot = 1;
	      
	      if (is && isnot)
		{
		  change = 1;
		  for (j = 1; j <= 3; j++)
		    pused.Set (SurfaceElement(i).PNum(j));
		}

	      if (is) 
		{
		  if (!surfused.Test(i))
		    {
		      surfused.Set(i);
		      SurfaceElement(i).SetIndex (dom);
		      cntd++;
		    }
		}
	    }


	  for (i = 1; i <= ne; i++)
	    {
	      int is = 0, isnot = 0;
	      for (j = 1; j <= 4; j++)
		if (pused.Test(VolumeElement(i).PNum(j)))
		  is = 1;
		else
		  isnot = 1;
	      
	      if (is && isnot)
		{
		  change = 1;
		  for (j = 1; j <= 4; j++)
		    pused.Set (VolumeElement(i).PNum(j));
		}

	      if (is)
		{
		  VolumeElement(i).SetIndex (dom);
		}
	    }
	}
      while (change);

      PrintMessage (3, "domain ", dom, " has ", cntd, " surfaceelements");
    }

  /*
  facedecoding.SetSize (dom);
  for (i = 1; i <= dom; i++)
    {
      facedecoding.Elem(i).surfnr = 0;
      facedecoding.Elem(i).domin = i;
      facedecoding.Elem(i).domout = 0;
    }
    */
  ClearFaceDescriptors();
  for (i = 1; i <= dom; i++)
    AddFaceDescriptor (FaceDescriptor (0, i, 0, 0));
  CalcSurfacesOfNode();
  timestamp = NextTimeStamp();
}

void Mesh :: SplitSeparatedFaces ()
{
  int fdi;
  int i, j;
  int np = GetNP();

  BitArray usedp(np);

  fdi = 1;
  while (fdi <= GetNFD())
    {
      int firstel = 0;
      for (i = 1; i <= GetNSE(); i++)
	if (SurfaceElement(i).GetIndex() == fdi)
	  {
	    firstel = i;
	    break;
	  }
      if (!firstel) continue;

      usedp.Clear();
      for (j = 1; j <= SurfaceElement(firstel).GetNP(); j++)
	usedp.Set (SurfaceElement(firstel).PNum(j));

      int changed;
      do
	{
	  changed = 0;
	  for (i = 1; i <= GetNSE(); i++)
	    {
	      const Element2d & el = SurfaceElement(i);
	      if (el.GetIndex() != fdi)
		continue;

	      int has = 0;
	      int hasno = 0;
	      for (j = 1; j <= el.GetNP(); j++)
		{
		  if (usedp.Test(el.PNum(j)))
		    has = 1;
		  else
		    hasno = 1;
		}
	      if (has && hasno)
		changed = 1;

	      if (has)
		for (j = 1; j <= el.GetNP(); j++)
		  usedp.Set (el.PNum(j));
	    }
	}
      while (changed);

      int nface = 0;
      for (i = 1; i <= GetNSE(); i++)
	{
	  Element2d & el = SurfaceElement(i);
	  if (el.GetIndex() != fdi)
	    continue;	  

	  int hasno = 0;
	  for (j = 1; j <= el.GetNP(); j++)
	    {
	      if (!usedp.Test(el.PNum(j)))
		hasno = 1;
	    }
	  
	  if (hasno)
	    {
	      if (!nface)
		{
		  FaceDescriptor nfd = GetFaceDescriptor(fdi);
		  nface = AddFaceDescriptor (nfd);
		}

	      el.SetIndex (nface);
	    }
	}
      fdi++;
    }
}


void Mesh :: GetSurfaceElementsOfFace (int facenr, ARRAY<SurfaceElementIndex> & sei) const
{
  sei.SetSize (0);
  for (SurfaceElementIndex i = 0; i < GetNSE(); i++)
    if ( (*this)[i].GetIndex () == facenr && (*this)[i][0] >= PointIndex::BASE )
      sei.Append (i);
}




void Mesh :: CalcMinMaxAngle (double badellimit, double * retvalues) 
{
  int i, j;
  int lpi1, lpi2, lpi3, lpi4;
  double phimax = 0, phimin = 10;
  double facephimax = 0, facephimin = 10;
  int illegaltets = 0, negativetets = 0, badtets = 0;

  for (i = 1; i <= GetNE(); i++)
    {
      int badel = 0;

      Element & el = VolumeElement(i);

      if (el.GetType() != TET)
	{
	  VolumeElement(i).flags.badel = 0;
	  continue;
	}

      if (el.Volume(Points()) < 0)
	{
	  badel = 1;
	  negativetets++;
	}
      

      if (!LegalTet (el)) 
	{
	  badel = 1;
	  illegaltets++;
	  (*testout) << "illegal tet: " << i << " ";
	  for (j = 1; j <= el.GetNP(); j++)
	    (*testout) << el.PNum(j) << " ";
	  (*testout) << endl;
	}
      
	
      // angles between faces
      for (lpi1 = 1; lpi1 <= 3; lpi1++)
	for (lpi2 = lpi1+1; lpi2 <= 4; lpi2++)
	  {
	    lpi3 = 1;
	    while (lpi3 == lpi1 || lpi3 == lpi2)
	      lpi3++;
	    lpi4 = 10 - lpi1 - lpi2 - lpi3;

	    const Point3d & p1 = Point (el.PNum(lpi1));
	    const Point3d & p2 = Point (el.PNum(lpi2));
	    const Point3d & p3 = Point (el.PNum(lpi3));
	    const Point3d & p4 = Point (el.PNum(lpi4));

	    Vec3d n(p1, p2);
	    n /= n.Length();
	    Vec3d v1(p1, p3);
	    Vec3d v2(p1, p4);

	    v1 -= (n * v1) * n;
	    v2 -= (n * v2) * n;

	    double cosphi = (v1 * v2) / (v1.Length() * v2.Length());
	    double phi = acos (cosphi);
	    if (phi > phimax) phimax = phi;
	    if (phi < phimin) phimin = phi;

	    if ((180/M_PI) * phi > badellimit)
	      badel = 1;
	  }


      // angles in faces
      for (j = 1; j <= 4; j++)
	{
	  Element2d face;
	  el.GetFace (j, face);
	  for (lpi1 = 1; lpi1 <= 3; lpi1++)
	    {
	      lpi2 = lpi1 % 3 + 1;
	      lpi3 = lpi2 % 3 + 1;

	      const Point3d & p1 = Point (el.PNum(lpi1));
	      const Point3d & p2 = Point (el.PNum(lpi2));
	      const Point3d & p3 = Point (el.PNum(lpi3));

	      Vec3d v1(p1, p2);
	      Vec3d v2(p1, p3);
	      double cosphi = (v1 * v2) / (v1.Length() * v2.Length());
	      double phi = acos (cosphi);
	      if (phi > facephimax) facephimax = phi;
	      if (phi < facephimin) facephimin = phi;

	      if ((180/M_PI) * phi > badellimit)
		badel = 1;

	    }
	}

       
      VolumeElement(i).flags.badel = badel;
      if (badel) badtets++;
    }

  if (!GetNE())
    {
      phimin = phimax = facephimin = facephimax = 0;
    }

  if (!retvalues)
    {
      PrintMessage (1, "");
      PrintMessage (1, "between planes:  phimin = ", (180/M_PI) * phimin,
		    " phimax = ", (180/M_PI) *phimax);
      PrintMessage (1, "inside planes:   phimin = ", (180/M_PI) * facephimin,
		    " phimax = ", (180/M_PI) * facephimax);
      PrintMessage (1, "");      
    }
  else
    {
      retvalues[0] = (180/M_PI) * facephimin;
      retvalues[1] = (180/M_PI) * facephimax;
      retvalues[2] = (180/M_PI) * phimin;
      retvalues[3] = (180/M_PI) * phimax;
    }
  PrintMessage (3, "negative tets: ", negativetets);
  PrintMessage (3, "illegal tets:  ", illegaltets);
  PrintMessage (3, "bad tets:      ", badtets);
}


int Mesh :: MarkIllegalElements ()
{
  int cnt = 0;
  int i;

  for (i = 1; i <= GetNE(); i++)
    {
      LegalTet (VolumeElement(i));

      /*
      Element & el = VolumeElement(i);
      int leg1 = LegalTet (el);
      el.flags.illegal_valid = 0;
      int leg2 = LegalTet (el);

      if (leg1 != leg2) 
	{
	  cerr << "legal differs!!" << endl;
	  (*testout) << "legal differs" << endl;
	  (*testout) << "elnr = " << i << ", el = " << el
		     << " leg1 = " << leg1 << ", leg2 = " << leg2 << endl;
	}
      
      //      el.flags.illegal = !LegalTet (el);
      */
      cnt += VolumeElement(i).Illegal();
    }
  return cnt;
}

#ifdef NONE
void Mesh :: AddIdentification (int pi1, int pi2, int identnr)
{
  INDEX_2 pair(pi1, pi2);
  //  pair.Sort();
  identifiedpoints->Set (pair, identnr);
  if (identnr > maxidentnr)
    maxidentnr = identnr;
  timestamp = NextTimeStamp();
}

int Mesh :: GetIdentification (int pi1, int pi2) const
{
  INDEX_2 pair(pi1, pi2);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);
  else
    return 0;
}

int Mesh :: GetIdentificationSym (int pi1, int pi2) const
{
  INDEX_2 pair(pi1, pi2);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);

  pair = INDEX_2 (pi2, pi1);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);

  return 0;
}


void Mesh :: GetIdentificationMap (int identnr, ARRAY<int> & identmap) const
{
  int i, j;

  identmap.SetSize (GetNP());
  for (i = 1; i <= identmap.Size(); i++)
    identmap.Elem(i) = 0;

  for (i = 1; i <= identifiedpoints->GetNBags(); i++)
    for (j = 1; j <= identifiedpoints->GetBagSize(i); j++)
      {
	INDEX_2 i2;
	int nr;
	identifiedpoints->GetData (i, j, i2, nr);
	
	if (nr == identnr)
	  {
	    identmap.Elem(i2.I1()) = i2.I2();
	  }
      }
}


void Mesh :: GetIdentificationPairs (int identnr, ARRAY<INDEX_2> & identpairs) const
{
  int i, j;

  identpairs.SetSize(0);

  for (i = 1; i <= identifiedpoints->GetNBags(); i++)
    for (j = 1; j <= identifiedpoints->GetBagSize(i); j++)
      {
	INDEX_2 i2;
	int nr;
	identifiedpoints->GetData (i, j, i2, nr);
	
	if (identnr == 0 || nr == identnr)
	  identpairs.Append (i2);
      }
}
#endif

void Mesh :: ComputeNVertices ()
{
  int i, j, nv;
  int ne = GetNE();
  int nse = GetNSE();

  numvertices = 0;
  for (i = 1; i <= ne; i++)
    {
      const Element & el = VolumeElement(i);
      nv = el.GetNV();
      for (j = 0; j < nv; j++)
	if (el[j] > numvertices)
	  numvertices = el[j];
    }
  for (i = 1; i <= nse; i++)
    {
      const Element2d & el = SurfaceElement(i);
      nv = el.GetNV();
      for (j = 1; j <= nv; j++)
	if (el.PNum(j) > numvertices)
	  numvertices = el.PNum(j);
   } 

  numvertices += 1- PointIndex::BASE;
}

int Mesh :: GetNV () const
{
  if (numvertices < 0)
    return GetNP();
  else
    return numvertices;
}

void Mesh :: SetNP (int np)
{
  points.SetSize(np);
  ptyps.SetSize(np);

  int mlold = mlbetweennodes.Size();
  mlbetweennodes.SetSize(np);
  if (np > mlold)
    for (int i = mlold+PointIndex::BASE; 
	 i < np+PointIndex::BASE; i++)
      {
	mlbetweennodes[i].I1() = PointIndex::BASE-1;
	mlbetweennodes[i].I2() = PointIndex::BASE-1;
      }
}


/*
void Mesh :: BuildConnectedNodes ()
{
  if (PureTetMesh())
    {
      connectedtonode.SetSize(0);
      return;
    }


  int i, j, k;
  int np = GetNP();
  int ne = GetNE();
  TABLE<int> conto(np);
  for (i = 1; i <= ne; i++)
    {
      const Element & el = VolumeElement(i);

      if (el.GetType() == PRISM)
	{
	  for (j = 1; j <= 6; j++)
	    {
	      int n1 = el.PNum (j);
	      int n2 = el.PNum ((j+2)%6+1);
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
	}
      else if (el.GetType() == PYRAMID)
	{
	  for (j = 1; j <= 4; j++)
	    {
	      int n1, n2;
	      switch (j)
		{
		case 1: n1 = 1; n2 = 4; break;
		case 2: n1 = 4; n2 = 1; break;
		case 3: n1 = 2; n2 = 3; break;
		case 4: n1 = 3; n2 = 2; break;
		}

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
    }
  
  connectedtonode.SetSize(np);
  for (i = 1; i <= np; i++)
    connectedtonode.Elem(i) = 0;
  
  for (i = 1; i <= np; i++)
    if (connectedtonode.Elem(i) == 0)
      {
	connectedtonode.Elem(i) = i;
	ConnectToNodeRec (i, i, conto);
      }
  


}

void Mesh :: ConnectToNodeRec (int node, int tonode, 
		       const TABLE<int> & conto)
{
  int i, n2;
  //  (*testout) << "connect " << node << " to " << tonode << endl;
  for (i = 1; i <= conto.EntrySize(node); i++)
    {
      n2 = conto.Get(node, i);
      if (!connectedtonode.Get(n2))
	{
	  connectedtonode.Elem(n2) = tonode;
	  ConnectToNodeRec (n2, tonode, conto);
	}
    }
}
*/


bool Mesh :: PureTrigMesh (int faceindex) const
{
  if (!faceindex)
    return !mparam.quad;

  int i;
  for (i = 1; i <= GetNSE(); i++)
    if (SurfaceElement(i).GetIndex() == faceindex &&
	SurfaceElement(i).GetNP() != 3)
      return 0;
  return 1;
}

bool Mesh :: PureTetMesh () const
{
  for (ElementIndex ei = 0; ei < GetNE(); ei++)
    if (VolumeElement(ei).GetNP() != 4)
      return 0;
  return 1;
}

void Mesh :: UpdateTopology()
{
  topology->Update();
  clusters->Update();
}


void Mesh :: SetMaterial (int domnr, const char * mat)
{
  if (domnr > materials.Size())
    {
      int olds = materials.Size();
      materials.SetSize (domnr);
      for (int i = olds; i < domnr; i++)
	materials[i] = 0;
    }
  materials.Elem(domnr) = new char[strlen(mat+1)];
  strcpy (materials.Elem(domnr), mat);
}

const char * Mesh :: GetMaterial (int domnr) const
{
  if (domnr <= materials.Size())
    return materials.Get(domnr);
  return 0;
}





void Mesh :: PrintMemInfo (ostream & ost) const
{
  ost << "Mesh Mem:" << endl;

  ost << GetNP() << " Points, of size " 
      << sizeof (Point3d) << " + " << sizeof(POINTTYPE) << " = "
      << GetNP() * (sizeof (Point3d) + sizeof(POINTTYPE)) << endl;

  ost << GetNSE() << " Surface elements, of size " 
      << sizeof (Element2d) << " = " 
      << GetNSE() * sizeof(Element2d) << endl;

  ost << GetNE() << " Volume elements, of size " 
      << sizeof (Element) << " = " 
      << GetNE() * sizeof(Element) << endl;

  ost << "surfs on node:";
  surfacesonnode.PrintMemInfo (cout);
  
  ost << "boundaryedges: ";
  if (boundaryedges)
    boundaryedges->PrintMemInfo (cout);

  ost << "surfelementht: ";
  if (surfelementht)
    surfelementht->PrintMemInfo (cout);
}
}

#include <mystdlib.h>

#include "meshing.hpp"


namespace netgen
{

  MultiPointGeomInfo :: MultiPointGeomInfo()
  {
    cnt = 0;
  }

  int MultiPointGeomInfo :: 
  AddPointGeomInfo (const PointGeomInfo & gi)
  {
    int k;

    for (k = 0; k < cnt; k++)
      if (mgi[k].trignum == gi.trignum)
	return 0;
  
    if (cnt < MULTIPOINTGEOMINFO_MAX)
      {
	mgi[cnt] = gi;
	cnt++;
	return 0;
      }
    // #ifdef DEVELOP
    cout << "Please Increase MPGI - Size" << endl;
    // #endif
    return 1;
  }


  void MultiPointGeomInfo :: 
  Init ()
  {
    cnt = 0;
  }

  void MultiPointGeomInfo :: 
  DeleteAll ()
  {
    cnt = 0;
  }




  Segment :: Segment() 
  {
    p1 = p2 = 0; 
    geominfo[0].trignum=0; 
    geominfo[1].trignum=0; 
    surfnr1 = surfnr2 = 0;
    edgenr = 0;

    singedge = 0;

    epgeominfo[0].edgenr = 1;
    epgeominfo[0].dist = 0;
    epgeominfo[1].edgenr = 1;
    epgeominfo[1].dist = 0;

    pmid = 0;
  }

  ostream & operator<<(ostream  & s, const Segment & seg)
  {
    s << seg.p1 << "(gi=" << seg.geominfo[0].trignum << ") - "
      << seg.p2 << "(gi=" << seg.geominfo[1].trignum << ")";
    return s;
  }

  Element2d :: Element2d (int anp)
  { 
    int i;
    for (i = 0; i < 6; i++)
      {
	pnum[i] = 0;
	geominfo[i].trignum = 0;
      }
    np = anp;
    index = 0;
    badel = 0;
    deleted = 0;
    switch (np)
      {
      case 3: typ = TRIG; break;
      case 4: typ = QUAD; break;
      case 6: typ = TRIG6; break;
      }
    order = 1;
  } 


  Element2d :: Element2d (ELEMENT_TYPE atyp)
  { 
    int i;
    for (i = 0; i < 6; i++)
      {
	pnum[i] = 0;
	geominfo[i].trignum = 0;
      }

    SetType (atyp);

    index = 0;
    badel = 0;
    deleted = 0;
    order = 1;
  } 




  Element2d :: Element2d (int pi1, int pi2, int pi3)
{
  pnum[0] = pi1;
  pnum[1] = pi2;
  pnum[2] = pi3;
  np = 3;
  typ = TRIG;
  pnum[3] = 0;
  pnum[4] = 0;
  pnum[5] = 0;
  
  for (int i = 0; i < 6; i++)
    geominfo[i].trignum = 0;
  index = 0;
  badel = 0;
  refflag = 1;
  deleted = 0;
  order = 1;
}

Element2d :: Element2d (int pi1, int pi2, int pi3, int pi4)
{
  pnum[0] = pi1;
  pnum[1] = pi2;
  pnum[2] = pi3;
  pnum[3] = pi4;
  np = 4;
  typ = QUAD;

  pnum[4] = 0;
  pnum[5] = 0;
  
  for (int i = 0; i < 6; i++)
    geominfo[i].trignum = 0;
  index = 0;
  badel = 0;
  refflag = 1;
  deleted = 0;
  order = 1;
}


void Element2d :: SetType (ELEMENT_TYPE atyp)
{
  typ = atyp;
  switch (typ)
    {
    case TRIG: np = 3; break;
    case QUAD: np = 4; break;
    case TRIG6: np = 6; break;
    case QUAD6: np = 6; break;
    default:
      PrintSysError ("Element2d::SetType, illegal type ", typ);
    }
}



void Element2d :: GetBox (const T_POINTS & points, Box3d & box) const
{
  box.SetPoint (points.Get(pnum[0]));
  for (unsigned i = 1; i < np; i++)
    box.AddPoint (points.Get(pnum[i]));
}

void Element2d :: Invert2()
{
  switch (typ)
    {
    case TRIG:
      {
	Swap (pnum[1], pnum[2]);
	break;
      }
    case QUAD:
      {
	Swap (pnum[0], pnum[3]);
	Swap (pnum[1], pnum[2]);
	break;
      }
    default:
      {
	cerr << "Element2d::Invert2, illegal element type " << int(typ) << endl;
      }
    }
}

int Element2d::HasFace(const Element2d& el) const
{
  //nur für tets!!! hannes
  for (int i = 1; i <= 3; i++)
    {
      if (PNumMod(i)   == el[0] && 
	  PNumMod(i+1) == el[1] && 
	  PNumMod(i+2) == el[2])
	{
	  return 1;
	}
    }
  return 0;
}

void Element2d :: NormalizeNumbering2 ()
{
  if (GetNP() == 3)
    {
      PointIndex pi1;
      if (PNum(1) < PNum(2) && PNum(1) < PNum(3))
	return;
      else
	{
	  if (PNum(2) < PNum(3))
	    {
	      pi1 = PNum(2);
	      PNum(2) = PNum(3);
	      PNum(3) = PNum(1);
	      PNum(1) = pi1;
	    }
	  else
	    {
	      pi1 = PNum(3);
	      PNum(3) = PNum(2);
	      PNum(2) = PNum(1);
	      PNum(1) = pi1;
	    }
	}
    }
  else
    {
      int i;
      int mini = 1;
      for (i = 2; i <= GetNP(); i++)
	if (PNum(i) < PNum(mini)) mini = i;
      
      Element2d hel = (*this);
      for (i = 1; i <= GetNP(); i++)
	PNum(i) = hel.PNumMod (i+mini-1);
    }
}




ARRAY<IntegrationPointData*> ipdtrig;
ARRAY<IntegrationPointData*> ipdquad;


int Element2d :: GetNIP () const
{
  int nip;
  switch (np)
    {
    case 3: nip = 1; break;
    case 4: nip = 4; break;
    default: nip = 0; break;
    }
  return nip;
}

void Element2d :: 
GetIntegrationPoint (int ip, Point2d & p, double & weight) const
{
  static double eltriqp[1][3] =
  {
    { 1.0/3.0, 1.0/3.0, 0.5 }
  };

  static double elquadqp[4][3] =
  { 
    { 0, 0, 0.25 },
    { 0, 1, 0.25 },
    { 1, 0, 0.25 },
    { 1, 1, 0.25 }
  };
  
  double * pp = 0;
  switch (typ)
    {
    case TRIG: pp = &eltriqp[0][0]; break;
    case QUAD: pp = &elquadqp[ip-1][0]; break;
    default:
      PrintSysError ("Element2d::GetIntegrationPoint, illegal type ", typ);
    }

  p.X() = pp[0];
  p.Y() = pp[1];
  weight = pp[2];
}

void Element2d :: 
GetTransformation (int ip, const ARRAY<Point2d> & points,
		   DenseMatrix & trans) const
{
  int np = GetNP();
  static DenseMatrix pmat(2, np), dshape(2, np);
  pmat.SetSize (2, np);
  dshape.SetSize (2, np);

  Point2d p;
  double w;

  GetPointMatrix (points, pmat);
  GetIntegrationPoint (ip, p, w);
  GetDShape (p, dshape);
  
  CalcABt (pmat, dshape, trans);

  /*
  (*testout) << "p = " << p  << endl
	     << "pmat = " << pmat << endl
	     << "dshape = " << dshape << endl
	     << "tans = " << trans << endl;
  */
}

void Element2d :: 
GetTransformation (int ip, class DenseMatrix & pmat,
		   class DenseMatrix & trans) const
{
  int np = GetNP();

  if (pmat.Width() != np || pmat.Height() != 2)
    {
      (*testout) << "GetTransofrmation: pmat doesn't fit" << endl;
      return;
    }

  ComputeIntegrationPointData ();
  DenseMatrix * dshapep = 0;
  switch (typ)
    {
    case TRIG: dshapep = &ipdtrig.Get(ip)->dshape; break;
    case QUAD: dshapep = &ipdquad.Get(ip)->dshape; break;
    default:
      PrintSysError ("Element2d::GetTransformation, illegal type ", typ);
    }
  
  CalcABt (pmat, *dshapep, trans);
}



void Element2d :: GetShape (const Point2d & p, Vector & shape) const
{
  if (shape.Size() != GetNP())
    {
      cerr << "Element::GetShape: Length not fitting" << endl;
      return;
    }

  switch (typ)
    {
    case TRIG:
      shape.Elem(1) = 1 - p.X() - p.Y();
      shape.Elem(2) = p.X();
      shape.Elem(3) = p.Y();
      break;
    case QUAD:
      shape.Elem(1) = (1-p.X()) * (1-p.Y());
      shape.Elem(2) = p.X() * (1-p.Y());
      shape.Elem(3) = p.X() * p.Y();
      shape.Elem(4) = (1-p.X()) * p.Y();
      break;
    default:
      PrintSysError ("Element2d::GetShape, illegal type ", typ);
    }
}

void Element2d :: 
GetDShape (const Point2d & p, DenseMatrix & dshape) const
{
#ifdef DEBUG
  if (dshape.Height() != 2 || dshape.Width() != np)
    {
      PrintSysError ("Element::DShape: Sizes don't fit");
      return;
    }
#endif

  switch (typ)
    {
    case TRIG:
      dshape.Elem(1, 1) = -1;
      dshape.Elem(1, 2) = 1;
      dshape.Elem(1, 3) = 0;
      dshape.Elem(2, 1) = -1;
      dshape.Elem(2, 2) = 0;
      dshape.Elem(2, 3) = 1;
      break;
    case QUAD:
      dshape.Elem(1, 1) = -(1-p.Y());
      dshape.Elem(1, 2) = (1-p.Y());
      dshape.Elem(1, 3) = p.Y();
      dshape.Elem(1, 4) = -p.Y();
      dshape.Elem(2, 1) = -(1-p.X());
      dshape.Elem(2, 2) = -p.X();
      dshape.Elem(2, 3) = p.X();
      dshape.Elem(2, 4) = (1-p.X());
      break;

    default:
      PrintSysError ("Element2d::GetDShape, illegal type ", typ);
    }
}


void Element2d :: 
GetPointMatrix (const ARRAY<Point2d> & points,
		DenseMatrix & pmat) const
{
  int i;
  int np = GetNP();
  if (pmat.Width() != np || pmat.Height() != 2)
    {
      cerr << "Element::GetPointMatrix: sizes don't fit" << endl;
      return;
    }
  
  for (i = 1; i <= np; i++)
    {
      const Point2d & p = points.Get(PNum(i));
      pmat.Elem(1, i) = p.X();
      pmat.Elem(2, i) = p.Y();
    }
}





double Element2d :: CalcJacobianBadness (const ARRAY<Point2d> & points) const
{
  int i, j;
  int nip = GetNIP();
  static DenseMatrix trans(2,2);
  static DenseMatrix pmat;
  
  pmat.SetSize (2, GetNP());
  GetPointMatrix (points, pmat);

  double err = 0;
  for (i = 1; i <= nip; i++)
    {
      GetTransformation (i, pmat, trans);

      // Frobenius norm
      double frob = 0;
      for (j = 1; j <= 4; j++)
	frob += sqr (trans.Get(j));
      frob = sqrt (frob);
      frob /= 2;

      double det = trans.Det();

      if (det <= 0)
	err += 1e12;
      else
	err += frob * frob / det;
    }

  err /= nip;
  return err;
}


double Element2d :: 
CalcJacobianBadnessDirDeriv (const ARRAY<Point2d> & points,
			     int pi, Vec2d & dir, double & dd) const
{
  int i, j, k, l;
  int nip = GetNIP();
  static DenseMatrix trans(2,2), dtrans(2,2), hmat(2,2);
  static DenseMatrix pmat, vmat;
  
  pmat.SetSize (2, GetNP());
  vmat.SetSize (2, GetNP());

  GetPointMatrix (points, pmat);
  
  for (i = 1; i <= np; i++)
    for (j = 1; j <= 2; j++)
      vmat.Elem(j, i) = 0;
  //  for (j = 1; j <= 2; j++)
  vmat.Elem(1, pi) = dir.X();
  vmat.Elem(2, pi) = dir.Y();



  double err = 0;
  dd = 0;

  for (i = 1; i <= nip; i++)
    {
      GetTransformation (i, pmat, trans);
      GetTransformation (i, vmat, dtrans);


      // Frobenius norm
      double frob = 0;
      for (j = 1; j <= 4; j++)
	frob += sqr (trans.Get(j));
      frob = sqrt (frob);
      
      double dfrob = 0;
      for (j = 1; j <= 4; j++)
	dfrob += trans.Get(j) * dtrans.Get(j);
      dfrob = dfrob / frob;
      
      frob /= 2;      
      dfrob /= 2;

      
      double det = trans.Det();
      double ddet = 0;
      
      for (j = 1; j <= 2; j++)
	{
	  hmat = trans;
	  for (k = 1; k <= 2; k++)
	    hmat.Elem(k, j) = dtrans.Get(k, j);
	  ddet += hmat.Det();
	}


      if (det <= 0)
	err += 1e12;
      else
	{
	  err += frob * frob / det;
	  dd += (2 * frob * dfrob * det - frob * frob * ddet) / (det * det);
	}
    }

  err /= nip;
  dd /= nip;
  return err;
}



double Element2d :: 
CalcJacobianBadness (const T_POINTS & points, const Vec3d & n) const
{
  int i, j;
  int nip = GetNIP();
  static DenseMatrix trans(2,2);
  static DenseMatrix pmat;
  
  pmat.SetSize (2, GetNP());

  Vec3d t1, t2;
  n.GetNormal(t1);
  Cross (n, t1, t2);

  for (i = 1; i <= nip; i++)
    {
      const Point3d & p = points.Get(PNum(i));
      pmat.Elem(1, i) = p.X() * t1.X() + p.Y() * t1.Y() + p.Z() * t1.Z();
      pmat.Elem(2, i) = p.X() * t2.X() + p.Y() * t2.Y() + p.Z() * t2.Z();
    }

  double err = 0;
  for (i = 1; i <= nip; i++)
    {
      GetTransformation (i, pmat, trans);

      // Frobenius norm
      double frob = 0;
      for (j = 1; j <= 4; j++)
	frob += sqr (trans.Get(j));
      frob = sqrt (frob);
      frob /= 2;

      double det = trans.Det();
      if (det <= 0)
	err += 1e12;
      else
	err += frob * frob / det;
    }

  err /= nip;
  return err;
}



void Element2d :: ComputeIntegrationPointData () const
{
  switch (np)
    {
    case 3: if (ipdtrig.Size()) return; break;
    case 4: if (ipdquad.Size()) return; break;
    }

  int i;
  for (i = 1; i <= GetNIP(); i++)
    {
      IntegrationPointData * ipd = new IntegrationPointData;
      Point2d hp;
      GetIntegrationPoint (i, hp, ipd->weight);
      ipd->p.X() = hp.X();
      ipd->p.Y() = hp.Y();
      ipd->p.Z() = 0;

      ipd->shape.SetSize(GetNP());
      ipd->dshape.SetSize(2, GetNP());

      GetShape (hp, ipd->shape);
      GetDShape (hp, ipd->dshape);

      switch (np)
	{
	case 3: ipdtrig.Append (ipd); break;
	case 4: ipdquad.Append (ipd); break;
	}
    }
}










ostream & operator<<(ostream  & s, const Element2d & el)
{
  s << "np = " << el.GetNP();
  for (int j = 1; j <= el.GetNP(); j++)
    s << " " << el.PNum(j);
  return s;
}


ostream & operator<<(ostream  & s, const Element & el)
{
  s << "np = " << el.GetNP();
  for (int j = 0; j < el.GetNP(); j++)
    s << " " << int(el[j]);
  return s;
}


Element :: Element ()
{
  typ = TET;
  np = 4;
  for (int i = 0; i < ELEMENT_MAXPOINTS; i++)
    pnum[i] = 0;
  index = 0;
  flags.marked = 1;
  flags.badel = 0;
  flags.reverse = 0;
  flags.illegal = 0;
  flags.illegal_valid = 0;
  flags.refflag = 1;
  flags.deleted = 0;
  order = 1;
}


Element :: Element (int anp)
{
  np = anp;
  int i;
  for (i = 0; i < ELEMENT_MAXPOINTS; i++)
    pnum[i] = 0;
  index = 0;
  flags.marked = 1;
  flags.badel = 0;
  flags.reverse = 0;
  flags.illegal = 0;
  flags.illegal_valid = 0;
  flags.refflag = 1;
  flags.deleted = 0;
  switch (np)
    {
    case 4: typ = TET; break;
    case 5: typ = PYRAMID; break;
    case 6: typ = PRISM; break;
    case 8: typ = HEX; break;
    case 10: typ = TET10; break;
    default: cerr << "Element::Element: unknown element with " << np << " points" << endl;
    }
  order = 1;
}


Element :: Element (ELEMENT_TYPE type)
{
  SetType (type);

  int i;
  for (i = 0; i < ELEMENT_MAXPOINTS; i++)
    pnum[i] = 0;
  index = 0;
  flags.marked = 1;
  flags.badel = 0;
  flags.reverse = 0;
  flags.illegal = 0;
  flags.illegal_valid = 0;
  flags.refflag = 1;
  flags.deleted = 0;
  order = 1;
}





Element & Element :: operator= (const Element & el2)
{
  int i;
  typ = el2.typ;
  np = el2.np;
  for (i = 0; i < ELEMENT_MAXPOINTS; i++)
    pnum[i] = el2.pnum[i];
  index = el2.index;
  flags = el2.flags;
  order = el2.order;
  return *this;
}



void Element :: SetNP (int anp)
{
  np = anp; 
  switch (np)
    {
    case 4: typ = TET; break;
    case 5: typ = PYRAMID; break;
    case 6: typ = PRISM; break;
    case 8: typ = HEX; break;
    case 10: typ = TET10; break;
      // 
    default: break;
      cerr << "Element::SetNP unknown element with " << np << " points" << endl;
    }
}



void Element :: SetType (ELEMENT_TYPE atyp)
{
  typ = atyp;
  switch (atyp)
    {
    case TET: np = 4; break;
    case PYRAMID: np = 5; break;
    case PRISM: np = 6; break;
    case HEX: np = 8; break;
    case TET10: np = 10; break;
    case PRISM12: np = 12; break;
    }
}



void Element :: Invert()
{
  switch (GetNP())
    {
    case 4:
      {
	Swap (PNum(3), PNum(4));
	break;
      }
    case 5:
      {
	Swap (PNum(1), PNum(4));
	Swap (PNum(2), PNum(3));
	break;
      }
    case 6:
      {
	Swap (PNum(1), PNum(4));
	Swap (PNum(2), PNum(5));
	Swap (PNum(3), PNum(6));
	break;
      }
    }
}


void Element :: Print (ostream & ost) const
{
  ost << np << " Points: ";
  for (int i = 1; i <= np; i++)
    ost << pnum[i-1] << " " << endl;
}

void Element :: GetBox (const T_POINTS & points, Box3d & box) const
{
  box.SetPoint (points.Get(PNum(1)));
  box.AddPoint (points.Get(PNum(2)));
  box.AddPoint (points.Get(PNum(3)));
  box.AddPoint (points.Get(PNum(4)));
}

double Element :: Volume (const T_POINTS & points) const
{
  Vec3d v1 = points.Get(PNum(2)) - 
    points.Get(PNum(1));
  Vec3d v2 = points.Get(PNum(3)) - 
    points.Get(PNum(1));
  Vec3d v3 = points.Get(PNum(4)) - 
    points.Get(PNum(1)); 
         
  return -(Cross (v1, v2) * v3) / 6;	 
}  


void Element :: GetFace2 (int i, Element2d & face) const
{
  static const int tetfaces[][5] = 
  { { 3, 2, 3, 4, 0 },
    { 3, 3, 1, 4, 0 },
    { 3, 1, 2, 4, 0 },
    { 3, 2, 1, 3, 0 } };

  static const int pyramidfaces[][5] =
  { { 4, 1, 4, 3, 2 },
    { 3, 1, 2, 5, 0 },
    { 3, 2, 3, 5, 0 },
    { 3, 3, 4, 5, 0 },
    { 3, 4, 1, 5, 0 } };

  static const int prismfaces[][5] =
  {
    { 3, 1, 3, 2, 0 },
    { 3, 4, 5, 6, 0 },
    { 4, 1, 2, 5, 4 },
    { 4, 2, 3, 6, 5 },
    { 4, 3, 1, 4, 6 }
  };

  switch (np)
    {
    case 4: // tet
    case 10: // tet
      {
	face.SetType(TRIG);
	for (int j = 1; j <= 3; j++)
	  face.PNum(j) = PNum(tetfaces[i-1][j]);
	break;
      }
    case 5: // pyramid
      {
	// face.SetNP(pyramidfaces[i-1][0]);
	face.SetType ( (i == 1) ? QUAD : TRIG);
	for (int j = 1; j <= face.GetNP(); j++)
	  face.PNum(j) = PNum(pyramidfaces[i-1][j]);
	break;
      }
    case 6: // prism
      {
	//	face.SetNP(prismfaces[i-1][0]);
	face.SetType ( (i >= 3) ? QUAD : TRIG);
	for (int j = 1; j <= face.GetNP(); j++)
	  face.PNum(j) = PNum(prismfaces[i-1][j]);
	break;
      }
    }
}



void Element :: GetTets (ARRAY<Element> & locels) const
{
  GetTetsLocal (locels);
  int i, j;
  for (i = 1; i <= locels.Size(); i++)
    for (j = 1; j <= 4; j++)
      locels.Elem(i).PNum(j) = PNum ( locels.Elem(i).PNum(j) );
}

void Element :: GetTetsLocal (ARRAY<Element> & locels) const
{
  int i, j;
  locels.SetSize(0);
  switch (GetType())
    {
    case TET:
      {
	int linels[1][4] = 
	{ { 1, 2, 3, 4 },
	};
	for (i = 0; i < 1; i++)
	  {
	    Element tet(4);
	    for (j = 1; j <= 4; j++)
	      tet.PNum(j) = linels[i][j-1];
	    locels.Append (tet);
	  }
	break;
      }
    case TET10:
      {
	int linels[8][4] = 
	{ { 1, 5, 6, 7 },
	  { 5, 2, 8, 9 },
	  { 6, 8, 3, 10 },
	  { 7, 9, 10, 4 },
	  { 5, 6, 7, 9 },
	  { 5, 6, 9, 8 },
	  { 6, 7, 9, 10 },
	  { 6, 8, 10, 9 } };
	for (i = 0; i < 8; i++)
	  {
	    Element tet(4);
	    for (j = 1; j <= 4; j++)
	      tet.PNum(j) = linels[i][j-1];
	    locels.Append (tet);
	  }
	break;
      }
    case PYRAMID:
      {
	int linels[2][4] = 
	{ { 1, 2, 3, 5 },
	  { 1, 3, 4, 5 } };
	for (i = 0; i < 2; i++)
	  {
	    Element tet(4);
	    for (j = 1; j <= 4; j++)
	      tet.PNum(j) = linels[i][j-1];
	    locels.Append (tet);
	  }
	break;
      }
    case PRISM:
    case PRISM12:
      {
	int linels[3][4] = 
	{ { 1, 2, 3, 4 },
	  { 4, 2, 3, 5 },
	  { 6, 5, 4, 3 }
	};
	for (i = 0; i < 3; i++)
	  {
	    Element tet(4);
	    for (j = 0; j < 4; j++)
	      tet[j] = linels[i][j];
	    locels.Append (tet);
	  }
	break;
      }
    case HEX:
      {
	int linels[6][4] = 
	{ { 1, 7, 2, 3 },
	  { 1, 7, 3, 4 },
	  { 1, 7, 4, 8 },
	  { 1, 7, 8, 5 },
	  { 1, 7, 5, 6 },
	  { 1, 7, 6, 2 }
	};
	for (i = 0; i < 6; i++)
	  {
	    Element tet(4);
	    for (j = 0; j < 4; j++)
	      tet[j] = linels[i][j];
	    locels.Append (tet);
	  }
	break;
      }
    default:
      {
	cerr << "GetTetsLocal not implemented for el with " << GetNP() << " nodes" << endl;
      }
    }
}

void Element :: GetNodesLocal (ARRAY<Point3d> & points) const
{
  const static double tetpoints[4][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 }};
  
  const static double prismpoints[6][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 1, 0, 1 },
      { 0, 1, 1 } };
  
  const static double pyramidpoints[6][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 } };
  
  const static double tet10points[10][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 0.5, 0, 0 },
      { 0, 0.5, 0 },
      { 0, 0, 0.5 },
      { 0.5, 0.5, 0 },
      { 0.5, 0, 0.5 },
      { 0, 0.5, 0.5 } };

  const static double hexpoints[8][3] =
    { 
      { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 1, 0, 0 },
      { 0, 0, 1 },
      { 1, 0, 1 },
      { 1, 1, 1 },
      { 1, 0, 1 }
    };
  
  int np, i;
  const double (*pp)[3];
  switch (GetType())
    {
    case TET:
      {
	np = 4;
	pp = tetpoints;
	break;
      }
    case PRISM:
    case PRISM12:
      {
	np = 6;
	pp = prismpoints;
	break;
      }
    case TET10:
      {
	np = 10;
	pp = tet10points;
	break;
      }
    case PYRAMID:
      {
	np = 5;
	pp = pyramidpoints;
	break;
      }
    case HEX:
      {
	np = 8;
	pp = hexpoints;
	break;
      }
    default:
      {
	cout << "GetNodesLocal not impelemented for element " << GetType() << endl;
	np = 0;
      }
    }
  
  points.SetSize(0);
  for (i = 0; i < np; i++)
    points.Append (Point3d (pp[i][0], pp[i][1], pp[i][2]));
}







void Element :: GetNodesLocalNew (ARRAY<Point3d> & points) const
{
  const static double tetpoints[4][3] =
    {      
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 0, 0, 0 }
    };
  
  const static double prismpoints[6][3] =
    {
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 0 },
      { 1, 0, 1 },
      { 0, 1, 1 },
      { 0, 0, 1 }
    };
  
  const static double pyramidpoints[6][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 } };
  
  const static double tet10points[10][3] =
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 0.5, 0, 0 },
      { 0, 0.5, 0 },
      { 0, 0, 0.5 },
      { 0.5, 0.5, 0 },
      { 0.5, 0, 0.5 },
      { 0, 0.5, 0.5 } };

  const static double hexpoints[8][3] =
    { 
      { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 1, 0, 1 },
      { 1, 1, 1 },
      { 0, 1, 1 }
    };
  

  
  int np, i;
  const double (*pp)[3];
  switch (GetType())
    {
    case TET:
      {
	np = 4;
	pp = tetpoints;
	break;
      }
    case PRISM:
    case PRISM12:
      {
	np = 6;
	pp = prismpoints;
	break;
      }
    case TET10:
      {
	np = 10;
	pp = tet10points;
	break;
      }
    case PYRAMID:
      {
	np = 5;
	pp = pyramidpoints;
	break;
      }
    case HEX:
      {
	np = 8;
	pp = hexpoints;
	break;
      }
    default:
      {
	cout << "GetNodesLocal not impelemented for element " << GetType() << endl;
	np = 0;
      }
    }
  
  points.SetSize(0);
  for (i = 0; i < np; i++)
    points.Append (Point3d (pp[i][0], pp[i][1], pp[i][2]));
}

















void Element :: GetSurfaceTriangles (ARRAY<Element2d> & surftrigs) const
{
  static int tet4trigs[][3] = 
  { { 2, 3, 4 },
    { 3, 1, 4 },
    { 1, 2, 4 },
    { 2, 1, 3 } };

  // just a few:
  static int tet10trigs[][3] = 
  { { 2, 8, 9 },
    { 3, 10, 8},
    { 4, 9, 10 },
    { 9, 8, 10 },
    { 3, 1, 4 },
    { 1, 2, 4 },
    { 2, 1, 3 } };

  static int pyramidtrigs[][3] =
  {
    { 1, 3, 2 },
    { 1, 4, 3 },
    { 1, 2, 5 },
    { 2, 3, 5 },
    { 3, 4, 5 },
    { 4, 1, 5 }
  };

  static int prismtrigs[][3] =
    {
      { 1, 3, 2 },
      { 4, 5, 6 },
      { 1, 2, 4 },
      { 4, 2, 5 },
      { 2, 3, 5 },
      { 5, 3, 6 },
      { 3, 1, 6 },
      { 6, 1, 4 }
    };
  
  static int hextrigs[][3] = 
    {
      { 1, 3, 2 },
      { 1, 4, 3 }, 
      { 5, 6, 7 },
      { 5, 7, 8 },
      { 1, 2, 6 },
      { 1, 6, 5 },
      { 2, 3, 7 },
      { 2, 7, 6 },
      { 3, 4, 8 },
      { 3, 8, 7 },
      { 4, 1, 8 },
      { 1, 5, 8 }
    };

  int j;

  int nf;
  int (*fp)[3];

  switch (GetType())
    {
    case TET:
      {
	nf = 4;
	fp = tet4trigs;
	break;
      }
    case PYRAMID:
      {
	nf = 6;
	fp = pyramidtrigs;
	break;
      }
    case PRISM:
    case PRISM12:
      {
	nf = 8;
	fp = prismtrigs;
	break;
      }
    case TET10:
      {
	nf = 7;
	fp = tet10trigs;
	break;
      }
    case HEX:
      {
	nf = 12;
	fp = hextrigs;
	break;
      }
    default:
      {
	nf = 0;
	fp = NULL;
      }
    }

  
  surftrigs.SetSize (nf);
  for (j = 0; j < nf; j++)
    {
      surftrigs.Elem(j+1) = Element2d(3);
      surftrigs.Elem(j+1).PNum(1) = fp[j][0];
      surftrigs.Elem(j+1).PNum(2) = fp[j][1];
      surftrigs.Elem(j+1).PNum(3) = fp[j][2];
    }
}





ARRAY<IntegrationPointData*> ipdtet;
ARRAY<IntegrationPointData*> ipdtet10;


int Element :: GetNIP () const
{
  int nip;
  switch (typ)
    {
    case TET: nip = 1; break;
    case TET10: nip = 8; break;
    default: nip = 0; break;
    }
  return nip;
}

void Element :: 
GetIntegrationPoint (int ip, Point3d & p, double & weight) const
{
  static double eltetqp[1][4] =
  {
    { 0.25, 0.25, 0.25, 1.0/6.0 }
  };

  static double eltet10qp[8][4] =
  {
    { 0.585410196624969, 0.138196601125011, 0.138196601125011, 1.0/24.0 },
    { 0.138196601125011, 0.585410196624969, 0.138196601125011, 1.0/24.0 },
    { 0.138196601125011, 0.138196601125011, 0.585410196624969, 1.0/24.0 },
    { 0.138196601125011, 0.138196601125011, 0.138196601125011, 1.0/24.0 },
    { 1, 0, 0, 1 },
    { 0, 1, 0, 1 },
    { 0, 0, 1, 1 },
    { 0, 0, 0, 1 },
  };
  
  double * pp;
  switch (typ)
    {
    case TET: pp = &eltetqp[0][0]; break;
    case TET10: pp = &eltet10qp[ip-1][0]; break;
    }

  p.X() = pp[0];
  p.Y() = pp[1];
  p.Z() = pp[2];
  weight = pp[3];
}

void Element :: 
GetTransformation (int ip, const T_POINTS & points,
		   DenseMatrix & trans) const
{
  int np = GetNP();
  static DenseMatrix pmat(3, np), dshape(3, np);
  pmat.SetSize (3, np);
  dshape.SetSize (3, np);

  Point3d p;
  double w;

  GetPointMatrix (points, pmat);
  GetIntegrationPoint (ip, p, w);
  GetDShape (p, dshape);
  
  CalcABt (pmat, dshape, trans);

  /*
  (*testout) << "p = " << p  << endl
	     << "pmat = " << pmat << endl
	     << "dshape = " << dshape << endl
	     << "tans = " << trans << endl;
  */
}

void Element :: 
GetTransformation (int ip, class DenseMatrix & pmat,
		   class DenseMatrix & trans) const
{
  int np = GetNP();

  if (pmat.Width() != np || pmat.Height() != 3)
    {
      (*testout) << "GetTransofrmation: pmat doesn't fit" << endl;
      return;
    }

  ComputeIntegrationPointData ();
  DenseMatrix * dshapep;
  switch (GetType())
    {
    case TET: dshapep = &ipdtet.Get(ip)->dshape; break;
    case TET10: dshapep = &ipdtet10.Get(ip)->dshape; break;
    }
  
  CalcABt (pmat, *dshapep, trans);
}



void Element :: GetShape (const Point3d & p, Vector & shape) const
{
  if (shape.Size() != GetNP())
    {
      cerr << "Element::GetShape: Length not fitting" << endl;
      return;
    }

  switch (typ)
    {
    case TET:
      shape.Elem(1) = 1 - p.X() - p.Y() - p.Z(); 
      shape.Elem(2) = p.X();
      shape.Elem(3) = p.Y();
      shape.Elem(4) = p.Z();
      break;
    case TET10:
      double lam1 = 1 - p.X() - p.Y() - p.Z();
      double lam2 = p.X();
      double lam3 = p.Y();
      double lam4 = p.Z();
      
      shape.Elem(5) = 4 * lam1 * lam2;
      shape.Elem(6) = 4 * lam1 * lam3;
      shape.Elem(7) = 4 * lam1 * lam4;
      shape.Elem(8) = 4 * lam2 * lam3;
      shape.Elem(9) = 4 * lam2 * lam4;
      shape.Elem(10) = 4 * lam3 * lam4;

      shape.Elem(1) = lam1 - 
	0.5 * (shape.Elem(5) + shape.Elem(6) + shape.Elem(7));
      shape.Elem(2) = lam2 - 
	0.5 * (shape.Elem(5) + shape.Elem(8) + shape.Elem(9));
      shape.Elem(3) = lam3 - 
	0.5 * (shape.Elem(6) + shape.Elem(8) + shape.Elem(10));
      shape.Elem(4) = lam4 - 
	0.5 * (shape.Elem(7) + shape.Elem(9) + shape.Elem(10));
      break;
    }
}

void Element :: 
GetDShape (const Point3d & p, DenseMatrix & dshape) const
{
  int np = GetNP();
  if (dshape.Height() != 3 || dshape.Width() != np)
    {
      cerr << "Element::DShape: Sizes don't fit" << endl;
      return;
    }

  int i, j;
  double eps = 1e-6;
  Vector shaper(np), shapel(np);

  for (i = 1; i <= 3; i++)
    {
      Point3d pr(p), pl(p);
      pr.X(i) += eps;
      pl.X(i) -= eps;
      
      GetShape (pr, shaper);
      GetShape (pl, shapel);
      for (j = 1; j <= np; j++)
	dshape.Elem(i, j) = (shaper.Get(j) - shapel.Get(j)) / (2 * eps);
    }
}


void Element :: 
GetPointMatrix (const T_POINTS & points,
		DenseMatrix & pmat) const
{
  int i;
  int np = GetNP();
  if (pmat.Width() != np || pmat.Height() != 3)
    {
      cerr << "Element::GetPointMatrix: sizes don't fit" << endl;
      return;
    }
  
  for (i = 1; i <= np; i++)
    {
      const Point3d & p = points.Get(PNum(i));
      pmat.Elem(1, i) = p.X();
      pmat.Elem(2, i) = p.Y();
      pmat.Elem(3, i) = p.Z();
    }
}






double Element :: CalcJacobianBadness (const T_POINTS & points) const
{
  int i, j;
  int nip = GetNIP();
  static DenseMatrix trans(3,3);
  static DenseMatrix pmat;
  
  pmat.SetSize (3, GetNP());
  GetPointMatrix (points, pmat);

  double err = 0;
  for (i = 1; i <= nip; i++)
    {
      GetTransformation (i, pmat, trans);

      // Frobenius norm
      double frob = 0;
      for (j = 1; j <= 9; j++)
	frob += sqr (trans.Get(j));
      frob = sqrt (frob);
      frob /= 3;

      double det = -trans.Det();
      
      if (det <= 0)
	err += 1e12;
      else
	err += frob * frob * frob / det;
    }

  err /= nip;
  return err;
}

double Element :: 
CalcJacobianBadnessDirDeriv (const T_POINTS & points,
			     int pi, Vec3d & dir, double & dd) const
{
  int i, j, k, l;
  int nip = GetNIP();
  static DenseMatrix trans(3,3), dtrans(3,3), hmat(3,3);
  static DenseMatrix pmat, vmat;
  
  pmat.SetSize (3, GetNP());
  vmat.SetSize (3, GetNP());

  GetPointMatrix (points, pmat);
  
  for (i = 1; i <= np; i++)
    for (j = 1; j <= 3; j++)
      vmat.Elem(j, i) = 0;
  for (j = 1; j <= 3; j++)
    vmat.Elem(j, pi) = dir.X(j);



  double err = 0;
  dd = 0;

  for (i = 1; i <= nip; i++)
    {
      GetTransformation (i, pmat, trans);
      GetTransformation (i, vmat, dtrans);


      // Frobenius norm
      double frob = 0;
      for (j = 1; j <= 9; j++)
	frob += sqr (trans.Get(j));
      frob = sqrt (frob);
      
      double dfrob = 0;
      for (j = 1; j <= 9; j++)
	dfrob += trans.Get(j) * dtrans.Get(j);
      dfrob = dfrob / frob;
      
      frob /= 3;      
      dfrob /= 3;

      
      double det = trans.Det();
      double ddet = 0;
      
      for (j = 1; j <= 3; j++)
	{
	  hmat = trans;
	  for (k = 1; k <= 3; k++)
	    hmat.Elem(k, j) = dtrans.Get(k, j);
	  ddet += hmat.Det();
	}


      det *= -1;
      ddet *= -1;

      
      if (det <= 0)
	err += 1e12;
      else
	{
	  err += frob * frob * frob / det;
	  dd += (3 * frob * frob * dfrob * det - frob * frob * frob * ddet) / (det * det);
	}
    }

  err /= nip;
  dd /= nip;
  return err;
}





void Element :: ComputeIntegrationPointData () const
{
  switch (GetType())
    {
    case TET: if (ipdtet.Size()) return; break;
    case TET10: if (ipdtet10.Size()) return; break;
    default:
      PrintSysError ("Element::ComputeIntegrationPoint, illegal type ", int(typ));
    }

  int i;
  for (i = 1; i <= GetNIP(); i++)
    {
      IntegrationPointData * ipd = new IntegrationPointData;
      GetIntegrationPoint (i, ipd->p, ipd->weight);
      ipd->shape.SetSize(GetNP());
      ipd->dshape.SetSize(3, GetNP());

      GetShape (ipd->p, ipd->shape);
      GetDShape (ipd->p, ipd->dshape);

      switch (GetType())
	{
	case TET: ipdtet.Append (ipd); break;
	case TET10: ipdtet10.Append (ipd); break;
	default:
	  PrintSysError ("Element::ComputeIntegrationPoint(2), illegal type ", int(typ));
	}
    }
}








FaceDescriptor ::  FaceDescriptor()
{ 
  surfnr = domin = 
    domout  = bcprop = 0; 
  tlosurf = -1;
}

FaceDescriptor :: 
FaceDescriptor(int surfnri, int domini, int domouti, int tlosurfi)
{ 
  surfnr = surfnri; 
  domin = domini; 
  domout = domouti;
  tlosurf = tlosurfi; 
  bcprop = surfnri;
}

FaceDescriptor :: FaceDescriptor(const Segment & seg)
{ 
  surfnr = seg.si; 
  domin = seg.domin+1;
  domout = seg.domout+1;
  tlosurf = seg.tlosurf+1;
  bcprop = 0;
}

int FaceDescriptor ::  SegmentFits (const Segment & seg)
{
  return
    surfnr == seg.si &&
    domin == seg.domin+1 &&
    domout == seg.domout+1  &&
    tlosurf == seg.tlosurf+1;
}


ostream & operator<<(ostream  & s, const FaceDescriptor & fd)
{
  s << "surfnr = " << fd.surfnr 
    << ", domin = " << fd.domin
    << ", domout = " << fd.domout
    << ", tlosurf = " << fd.tlosurf
    << ", bcprop = " << fd.bcprop;
  return s;
}






Identifications :: Identifications (Mesh & amesh)
  : mesh(amesh)
{
  identifiedpoints = new INDEX_2_HASHTABLE<int>(100);
  maxidentnr = 0;
}

Identifications :: ~Identifications ()
{
  delete identifiedpoints;
}

void Identifications :: Delete ()
{
  delete identifiedpoints;
  identifiedpoints = new INDEX_2_HASHTABLE<int>(100);
  maxidentnr = 0;
}

void Identifications :: Add (PointIndex pi1, PointIndex pi2, int identnr)
{
  INDEX_2 pair (pi1, pi2);
  identifiedpoints->Set (pair, identnr);
  if (identnr > maxidentnr) maxidentnr = identnr;
  //  timestamp = NextTimeStamp();
}

int Identifications :: Get (PointIndex pi1, PointIndex pi2) const
{
  INDEX_2 pair(pi1, pi2);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);
  else
    return 0;
}

int Identifications :: GetSymmetric (PointIndex pi1, PointIndex pi2) const
{
  INDEX_2 pair(pi1, pi2);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);

  pair = INDEX_2 (pi2, pi1);
  if (identifiedpoints->Used (pair))
    return identifiedpoints->Get(pair);

  return 0;
}


void Identifications :: GetMap (int identnr, 
				ARRAY<int,PointIndex::BASE> & identmap) const
{
  int i, j;
  
  identmap.SetSize (mesh.GetNP());
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
 

void Identifications :: GetPairs (int identnr, 
				  ARRAY<INDEX_2> & identpairs) const
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







MeshingParameters :: MeshingParameters ()
{
  optimize3d = "cmdmstm";
  optsteps3d = 3;
  optimize2d = "smsmsmSmSmSm";
  optsteps2d = 1;
  opterrpow = 2;
  blockfill = 1;
  filldist = 0.1;
  safety = 5;
  relinnersafety = 3;
  uselocalh = 1;
  grading = 0.5;
  delaunay = 1;
  maxh = 1e10;
  meshsizefilename = NULL;
  startinsurface = 0;
  checkoverlap = 1;
  checkchartboundary = 1;
  curvaturesafety = 2;
  parthread = 0;
  
  elsizeweight = 0;
  giveuptol = 10;
  maxoutersteps = 5;
  starshapeclass = 5;
  baseelnp = 0;
  sloppy = 1;

  badellimit = 175;
  secondorder = 0;
}

void MeshingParameters :: Print (ostream & ost) const
{
  ost << "Meshing parameters: " << endl
      << "maxh = " << maxh << endl
      << "grading = " << grading << endl
      << "startinsurface = " << startinsurface << endl
      << "checkoverlap = " << checkoverlap << endl
      << "curvaturesafety = " << curvaturesafety << endl;
}



DebugParameters :: DebugParameters ()
{
  slowchecks = 0;
  haltsuccess = 0;
  haltnosuccess = 0;
  haltsegment = 0;
  haltsegmentp1 = 0;
  haltsegmentp2 = 0;
};



}

#include <mystdlib.h>

#include "meshing.hpp"
#include <opti.hpp>

namespace netgen
{

static const MeshOptimize2d * meshthis;




inline void CalcTriangleBadness (double x2, double x3, double y3, double metricweight,
			  double h, double & badness, double & g1x, double & g1y)
{
  // badness = sqrt(3.0) /36 * circumference^2 / area - 1 
  // p1 = (0, 0), p2 = (x2, 0), p3 = (x3, y3);

  Vec2d v23;
  double l12, l13, l23, cir, area;
  static const double c = sqrt(3.0) / 36;
  double c1, c2, c3, c4;

  v23.X() = x3 - x2;
  v23.Y() = y3;

  l12 = x2;
  l13 = sqrt (x3*x3 + y3*y3);
  l23 = v23.Length();

  cir = l12 + l13 + l23;
  area = 0.5 * x2 * y3;

  if (area <= 1e-24 * cir * cir)
    {
      g1x = 0;
      g1y = 0;
      badness = 1e10;
      return;
    }

  badness = c * cir * cir / area - 1;

  c1 = 2 * c * cir / area;
  c2 = 0.5 * c * cir * cir / (area * area);

  g1x = c1 * ( - 1 - x3 / l13) - c2 * (-v23.Y());
  g1y = c1 * (     - y3 / l13) - c2 * ( v23.X());
  
  //  metricweight = 0.1;
  if (metricweight > 0)
    {
      // area = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
      // add:  metricweight * (area / h^2 + h^2 / area - 2)
      
      const double area = x2 * y3;
      const double dareax1 = -y3; 
      const double dareay1 = x3 - x2; 

      const double areahh = area / (h * h);
      const double fac = metricweight * (areahh - 1 / areahh) / area;

      badness += metricweight * (areahh + 1 / areahh - 2);
      g1x += fac * dareax1;
      g1y += fac * dareay1; 
      
      /*
      // add: metricweight * (l1^2/h^2 + l2^2/h^2 + l3^2/h2 + h^2/l1^2 + h^2/l2^2 + h^2/l3^2 - 6)
      double h2 = h*h;
      double l1 = x2*x2;
      double l2 = x3*x3+y3*y3;
      double l3 = (x2-x3)*(x2-x3)+y3*y3;
      double dl1dx = 2*(-x2);
      double dl1dy = 0;
      double dl2dx = -2*x3;
      double dl2dy = -2*y3;

      badness += (l1/h2 + l2/h2 + l3/h2 +h2/l1 + h2/l2 + h2/l3-6) * metricweight;

      g1x += metricweight * (dl1dx/h2-h2/(l1*l1)*dl1dx + dl2dx/h2-h2/(l2*l2)*dl2dx);
      g1y += metricweight * (dl1dy/h2-h2/(l1*l1)*dl1dy + dl2dy/h2-h2/(l2*l2)*dl2dy);
      */
    }
}


  double CalcTriangleBadness (const Point3d & p1, 
			      const Point3d & p2, 
			      const Point3d & p3,
			      double metricweight,
			      double h)
  {
  double badness;
  double g1x, g1y;
  
  Vec3d e1 (p1, p2);
  Vec3d e2 (p1, p3);
  
  double e1l = e1.Length() + 1e-24;
  e1 /= e1l;
  double e1e2 = (e1 * e2);
  e2.Add (-e1e2, e1);
  double e2l = e2.Length();
  
  CalcTriangleBadness ( e1l, e1e2, e2l,
			metricweight, h, badness, g1x, g1y);
  return badness;
}


double CalcTriangleBadness (const Point3d & p1, 
			    const Point3d & p2, 
			    const Point3d & p3,
			    const Vec3d & n,
			    double metricweight,
			    double h)
{
  double badness;
  double g1x, g1y;
  
  Vec3d v1 (p1, p2);
  Vec3d v2 (p1, p3);

  Vec3d e1 = v1;
  Vec3d e2 = v2;

  e1 -= (e1 * n) * n;
  e1 /= (e1.Length() + 1e-12);
  e2 = Cross (n, e1);

  CalcTriangleBadness ( (e1 * v1), (e1 * v2), (e2 * v2), 
			metricweight, h, badness, g1x, g1y);
  return badness;
}




static Point3d sp1; 
static PointGeomInfo gi1;
static Vec3d n, t1, t2;
static ARRAY<SurfaceElementIndex> locelements(0);
static ARRAY<int> locrots(0);
static ARRAY<double> lochs(0);
// static int locerr2;
static double locmetricweight = 0;
static double loch;
static int surfi, surfi2;
static int uselocalh;


class Opti2SurfaceMinFunction : public MinFunction
{
  const Mesh & mesh;
public:
  Opti2SurfaceMinFunction (const Mesh & amesh)
    : mesh(amesh)
    { } ;
  virtual double FuncGrad (const Vector & x, Vector & g) const;
  virtual double Func (const Vector & x) const;
};
  
double Opti2SurfaceMinFunction :: 
Func (const Vector & x) const
{
  Vector g(x.Size());
  return FuncGrad (x, g);
}


double Opti2SurfaceMinFunction :: 
FuncGrad (const Vector & x, Vector & grad) const
{
  int j, roti;
  Vec3d n, vgrad;
  Point3d pp1;
  Vec2d g1;
  double badness, hbadness;

  vgrad = 0;
  badness = 0;


  meshthis -> GetNormalVector (surfi, sp1, gi1, n);

  pp1 = sp1;
  pp1.Add2 (x.Get(1), t1, x.Get(2), t2);

  //  meshthis -> ProjectPoint (surfi, pp1);
  // meshthis -> GetNormalVector (surfi, pp1, n);


  for (j = 0; j < locelements.Size(); j++)
    {
      roti = locrots[j];
      const Element2d & bel = mesh[locelements[j]];

      Vec3d e1(pp1, mesh[bel.PNumMod(roti + 1)]);
      Vec3d e2(pp1, mesh[bel.PNumMod(roti + 2)]);

      if (uselocalh) loch = lochs[j];

      double e1l = e1.Length();
      if (Determinant(e1, e2, n) > 1e-8 * e1l * e2.Length())
	{
	  e1 /= e1l;
	  double e1e2 = e1 * e2;
	  e2.Add (-e1e2, e1);
	  double e2l = e2.Length();

	  CalcTriangleBadness ( e1l, e1e2, e2l, locmetricweight, loch,
				hbadness, g1.X(), g1.Y());

	  badness += hbadness;
	  vgrad.Add2 (g1.X(), e1, g1.Y() / e2l, e2);
	}
      else
	badness += 1e8;
    }

  vgrad.Add (-(vgrad * n), n);

  grad.Elem(1) = vgrad * t1;
  grad.Elem(2) = vgrad * t2;
  return badness;
}


class Opti2EdgeMinFunction : public MinFunction
{
  const Mesh & mesh;
public:
  Opti2EdgeMinFunction (const Mesh & amesh)
    : mesh(amesh) { } ;

  virtual double FuncGrad (const Vector & x, Vector & g) const;
  virtual double Func (const Vector & x) const;
};

double Opti2EdgeMinFunction :: Func (const Vector & x) const
{
  Vector g(x.Size());
  return FuncGrad (x, g);
}

double Opti2EdgeMinFunction :: FuncGrad (const Vector & x, Vector & grad) const
{
  int j, rot;
  Vec3d n1, n2, v1, v2, e1, e2, vgrad;
  Point3d pp1;
  Vec2d g1;
  double badness, hbadness;

  vgrad.X() = 0;
  vgrad.Y() = 0;
  vgrad.Z() = 0;
  badness = 0;

  pp1 = sp1 + x.Get(1) * t1;
  meshthis -> ProjectPoint2 (surfi, surfi2, pp1);

  for (j = 0; j < locelements.Size(); j++)
    {
      rot = locrots[j];
      const Element2d & bel = mesh[locelements[j]];

      v1 = mesh[bel.PNumMod(rot + 1)] - pp1;
      v2 = mesh[bel.PNumMod(rot + 2)] - pp1;

      e1 = v1;
      e2 = v2;
      e1 /= e1.Length();
      e2 -= (e1 * e2) * e1;
      e2 /= e2.Length();

      if (uselocalh) loch = lochs[j];
      CalcTriangleBadness ( (e1 * v1), (e1 * v2), (e2 * v2), locmetricweight, loch,
			    hbadness, g1.X(), g1.Y());

      badness += hbadness;

      vgrad.X() += g1.X() * e1.X() + g1.Y() * e2.X();
      vgrad.Y() += g1.X() * e1.Y() + g1.Y() * e2.Y();
      vgrad.Z() += g1.X() * e1.Z() + g1.Y() * e2.Z();
    }

  meshthis -> GetNormalVector (surfi, pp1, n1);
  meshthis -> GetNormalVector (surfi2, pp1, n2);

  v1 = Cross (n1, n2);
  v1 /= v1.Length();

  grad.Elem(1) = (vgrad * v1) * (t1 * v1);

  return badness;
}




class Opti2SurfaceMinFunctionJacobian : public MinFunction
{
  const Mesh & mesh;
public:
  Opti2SurfaceMinFunctionJacobian (const Mesh & amesh)
    : mesh(amesh)
    { } ;
  virtual double FuncGrad (const Vector & x, Vector & g) const;
  virtual double Func (const Vector & x) const;
};
  
double Opti2SurfaceMinFunctionJacobian :: 
Func (const Vector & x) const
{
  Vector g(x.Size());
  return FuncGrad (x, g);
}


double Opti2SurfaceMinFunctionJacobian :: 
FuncGrad (const Vector & x, Vector & grad) const
{
  // from 2d:

  int j, k, lpi, gpi;
  Vec3d n, vgrad;
  Point3d pp1;
  Vec2d g1, vdir;
  double badness, hbadness, hbad, hderiv;

  vgrad = 0;
  badness = 0;

  meshthis -> GetNormalVector (surfi, sp1, gi1, n);

  pp1 = sp1;
  pp1.Add2 (x.Get(1), t1, x.Get(2), t2);

  //  meshthis -> ProjectPoint (surfi, pp1);
  //  meshthis -> GetNormalVector (surfi, pp1, n);

  static ARRAY<Point2d> pts2d;
  pts2d.SetSize(mesh.GetNP());

  grad = 0;

  for (j = 1; j <= locelements.Size(); j++)
    {
      lpi = locrots.Get(j);
      const Element2d & bel = 
	mesh[locelements.Get(j)];
      
      gpi = bel.PNum(lpi);

      for (k = 1; k <= bel.GetNP(); k++)
	{
	  PointIndex pi = bel.PNum(k);
	  pts2d.Elem(pi) = Point2d (t1 * (mesh.Point(pi) - sp1), 
				    t2 * (mesh.Point(pi) - sp1)); 
	}				    
      pts2d.Elem(gpi) = Point2d (x.Get(1), x.Get(2));
      

      for (k = 1; k <= 2; k++)
	{
	  if (k == 1)
	    vdir = Vec2d (1, 0);
	  else
	    vdir = Vec2d (0, 1);
	  
	  hbad = bel.
	    CalcJacobianBadnessDirDeriv (pts2d, lpi, vdir, hderiv);

	  grad.Elem(k) += hderiv;
	  if (k == 1)
	    badness += hbad;
	}
	  
	  
      /*
      Vec3d e1(pp1, mesh.Point(bel.PNumMod(lpi + 1)));
      Vec3d e2(pp1, mesh.Point(bel.PNumMod(lpi + 2)));

      if (uselocalh)
	loch = lochs.Get(j);

      double e1l = e1.Length();
      if (Determinant(e1, e2, n) > 1e-8 * e1l * e2.Length())
	{
	  e1 /= e1l;
	  double e1e2 = e1 * e2;
	  e2.Add (-e1e2, e1);
	  double e2l = e2.Length();

	  CalcTriangleBadness ( e1l, e1e2, e2l, locmetricweight, loch,
				hbadness, g1.X(), g1.Y());

	  badness += hbadness;
	  vgrad.Add2 (g1.X(), e1, g1.Y() / e2l, e2);
	}
      else
	badness += 1e8;
      */
    }


  /*
  vgrad.Add (-(vgrad * n), n);

  grad.Elem(1) = vgrad * t1;
  grad.Elem(2) = vgrad * t2;
  */
  return badness;

  /*

  // from 3d:

  int j, k;
  int lpi;
  double badness = 0, hbad;

  Point3d hp = points.Elem(actpind);
  points.Elem(actpind) = hp + Vec3d (x.Get(1), x.Get(2), x.Get(3));

  double hderiv;
  Vec3d vdir;
  g.SetSize(3);
  g = 0;

  for (j = 1; j <= elementsonpoint.EntrySize(actpind); j++)
    {
      int eli = elementsonpoint.Get(actpind, j);
      const Element & el = elements.Get(eli);

      lpi = 0;
      for (k = 1; k <= el.GetNP(); k++)
	if (el.PNum(k) == actpind)
	  lpi = k;
      if (!lpi) cerr << "loc point not found" << endl;

      for (k = 1; k <= 3; k++)
	{
	  vdir = Vec3d(0,0,0);
	  vdir.X(k) = 1;

	  hbad = elements.Get(eli).
	    CalcJacobianBadnessDirDeriv (points, lpi, vdir, hderiv);
	  g.Elem(k) += hderiv;
	  if (k == 1)
	    badness += hbad;
	}
    }
  
  points.Elem(actpind) = hp; 

  return badness;

  */

}







MeshOptimize2d dummy;

MeshOptimize2d :: MeshOptimize2d ()
{
  SetFaceIndex (0);
  SetImproveEdges (0);
  SetMetricWeight (0);
  SetWriteStatus (1);
}


void MeshOptimize2d :: SelectSurfaceOfPoint (const Point3d & p,
					     const PointGeomInfo & gi)
{
  ;
}

void MeshOptimize2d :: ImproveMesh (Mesh & mesh)
{
  if (!faceindex)
    {
      PrintMessage (3, "Smoothing");

      for (faceindex = 1; faceindex <= mesh.GetNFD(); faceindex++)
	{
	  ImproveMesh (mesh);
	  if (multithread.terminate)
	    throw NgException ("Meshing stopped");
	}
      faceindex = 0;
      return;
    }
 
  CheckMeshApproximation (mesh);

  int i, j, k, surfi3;
  SurfaceElementIndex sei;

  ARRAY<SurfaceElementIndex> seia;
  mesh.GetSurfaceElementsOfFace (faceindex, seia);

  bool mixed = 0;
  for (i = 0; i < seia.Size(); i++)
    if (mesh[seia[i]].GetNP() != 3)
      {
	mixed = 1;
	break;
      }


  int loci;
  double fact;
  int moveisok;

  PointGeomInfo ngi;
  Point3d origp;

  Vec3d n1, n2;
  Vector x(2), xedge(1);

  ARRAY<Point3d, PointIndex::BASE> savepoints(mesh.GetNP());
  uselocalh = mparam.uselocalh;

  ARRAY<int, PointIndex::BASE> nelementsonpoint(mesh.GetNP());
  nelementsonpoint = 0;

  for (i = 0; i < seia.Size(); i++)
    {
      const Element2d & el = mesh[seia[i]];
      for (j = 0; j < el.GetNP(); j++)
	nelementsonpoint[el[j]]++;
    }


  TABLE<SurfaceElementIndex,PointIndex::BASE> elementsonpoint(nelementsonpoint);
  for (i = 0; i < seia.Size(); i++)
    {
      const Element2d & el = mesh[seia[i]];
      for (j = 0; j < el.GetNP(); j++)
	elementsonpoint.Add (el[j], seia[i]);
    }

  loch = mparam.maxh;
  locmetricweight = metricweight;
  meshthis = this;

  Opti2SurfaceMinFunction surfminf(mesh);
  Opti2EdgeMinFunction edgeminf(mesh);
  Opti2SurfaceMinFunctionJacobian surfminfj(mesh);

  OptiParameters par;
  par.maxit_linsearch = 8;
  par.maxit_bfgs = 5;

  /*
  if (improveedges)
    for (i = 1; i <= mesh.GetNP(); i++)
      if (mesh.PointType(i) == EDGEPOINT)
	{
	  continue;
	  PrintDot ();
	  sp1 = mesh.Point(i);
	  
	  locelements.SetSize(0);
	  locrots.SetSize (0);
	  lochs.SetSize (0);
	  surfi = surfi2 = surfi3 = 0;
	  
	  for (j = 0; j < elementsonpoint[i].Size(); j++)
	    {
	      sei = elementsonpoint[i][j];
	      const Element2d * bel = &mesh[sei];
	      
	      if (!surfi)
		surfi = mesh.GetFaceDescriptor(bel->GetIndex()).SurfNr();
	      else if (surfi != mesh.GetFaceDescriptor(bel->GetIndex()).SurfNr())
		{
		  if (surfi2 != 0 && surfi2 != 
		      mesh.GetFaceDescriptor(bel->GetIndex()).SurfNr())
		    surfi3 = mesh.GetFaceDescriptor(bel->GetIndex()).SurfNr();
		  else
		    surfi2 = mesh.GetFaceDescriptor(bel->GetIndex()).SurfNr();
		}
	      
	      locelements.Append (sei);
	      
	      if (bel->PNum(1) == i)
		locrots.Append (1);
	      else if (bel->PNum(2) == i)
		locrots.Append (2);
	      else
		locrots.Append (3);

	      if (uselocalh)
		{
		  Point3d pmid = Center (mesh.Point(bel->PNum(1)),
					 mesh.Point(bel->PNum(2)),
					 mesh.Point(bel->PNum(3)));
		  lochs.Append (mesh.GetH(pmid));
		}
	    }
	  
	  if (surfi2 && !surfi3)
	    {
	      GetNormalVector (surfi, sp1, n1);
	      GetNormalVector (surfi2, sp1, n2);
	      t1 = Cross (n1, n2);
	      
	      xedge = 0;
	      BFGS (xedge, edgeminf, par, 1e-6);
	      
	      mesh.Point(i).X() += xedge.Get(1) * t1.X();
	      mesh.Point(i).Y() += xedge.Get(1) * t1.Y();
	      mesh.Point(i).Z() += xedge.Get(1) * t1.Z();
	      ProjectPoint2 (surfi, surfi2, mesh.Point(i));
	    }
	}
  */

  bool printeddot = 0;
  char plotchar = '.';
  int modplot = 1;
  if (mesh.GetNP() > 1000)
    {
      plotchar = '+';
      modplot = 10;
    }
  int cnt = 0;

  for (PointIndex pi = PointIndex::BASE; 
       pi < mesh.GetNP()+PointIndex::BASE; pi++)

    if (mesh.PointType(pi) == SURFACEPOINT)
      {
	if (multithread.terminate)
	  throw NgException ("Meshing stopped");
	
	cnt++;
	if (cnt % modplot == 0 && writestatus)
	  {
	    printeddot = 1;
	    PrintDot (plotchar);
	  }
	
	if (elementsonpoint[pi].Size() == 0)
	  continue;
	
	sp1 = mesh[pi];

	Element2d & hel = mesh[elementsonpoint[pi][0]];

	int hpi = 0;
	for (j = 1; j <= hel.GetNP(); j++)
	  if (hel.PNum(j) == pi)
	    {
	      hpi = j;
	      break;
	    }

	gi1 = hel.GeomInfoPi(hpi);
	SelectSurfaceOfPoint (sp1, gi1);
	  
	locelements.SetSize(0);
	locrots.SetSize (0);
	lochs.SetSize (0);
	
	for (j = 0; j < elementsonpoint[pi].Size(); j++)
	  {
	    sei = elementsonpoint[pi][j];
	    const Element2d & bel = mesh[sei];
	    surfi = mesh.GetFaceDescriptor(bel.GetIndex()).SurfNr();
	    
	    locelements.Append (sei);
	    
	    for (k = 1; k <= bel.GetNP(); k++)
	      if (bel.PNum(k) == pi)
		{
		  locrots.Append (k);
		  break;
		}
	      
	    if (uselocalh)
	      {
		Point3d pmid = Center (mesh[bel[0]], mesh[bel[1]], mesh[bel[2]]);
		lochs.Append (mesh.GetH(pmid));
	      }
	  }

	  
	GetNormalVector (surfi, sp1, gi1, n);
	n.GetNormal (t1);
	t2 = Cross (n, t1);
	  
	// save points, and project to tangential plane
	for (j = 0; j < locelements.Size(); j++)
	  {
	    const Element2d & el = mesh[locelements[j]];
	    for (k = 0; k < el.GetNP(); k++)
	      savepoints[el[k]] = mesh[el[k]];
	  }

	for (j = 0; j < locelements.Size(); j++)
	  {
	    const Element2d & el = mesh[locelements[j]];
	    for (k = 0; k < el.GetNP(); k++)
	      {
		PointIndex hpi = el[k];
		double lam = n * (mesh[hpi] - sp1);
		mesh[hpi] -= lam * n;
	      }
	  }
	  
	x = 0;

	if (mixed)
	  BFGS (x, surfminfj, par, 1e-6);
	else
	  BFGS (x, surfminf, par, 1e-6);

	origp = mesh[pi];
	loci = 1;
	fact = 1;
	moveisok = 0;

	// restore other points
	for (j = 0; j < locelements.Size(); j++)
	  {
	    const Element2d & el = mesh[locelements[j]];
	    for (k = 0; k < el.GetNP(); k++)
	      {
		PointIndex hpi = el[k];
		if (hpi != pi) mesh[hpi] = savepoints[hpi];
	      }
	  }
	  
	  
	//optimizer loop (if not whole distance is not possible, move only a bit!!!!)
	while (loci <= 5 && !moveisok)
	  {
	    loci ++;
	    mesh[pi].X() = origp.X() + (x.Get(1) * t1.X() + x.Get(2) * t2.X())*fact;
	    mesh[pi].Y() = origp.Y() + (x.Get(1) * t1.Y() + x.Get(2) * t2.Y())*fact;
	    mesh[pi].Z() = origp.Z() + (x.Get(1) * t1.Z() + x.Get(2) * t2.Z())*fact;
	    fact = fact/2.;
	    ProjectPoint (surfi, mesh[pi]);
	    
	    moveisok = CalcPointGeomInfo(surfi, ngi, mesh[pi]); 
	    // point lies on same chart in stlsurface
	    
	    if (moveisok)
	      {
		for (j = 0; j < locelements.Size(); j++)
		  mesh[locelements[j]].GeomInfoPi(locrots[j]) = ngi;
	      }
	    else
	      {
		mesh[pi] = origp;
	      }
	    
	  }
	  //	(*testout) << " new: " << mesh.Point(i) << endl;
      }
  
  if (printeddot)
    PrintDot ('\n');
  
  CheckMeshApproximation (mesh);
  mesh.SetNextTimeStamp();
}

void MeshOptimize2d :: GetNormalVector(INDEX /* surfind */, const Point3d & p, Vec3d & nv) const
{
  nv = Vec3d (0, 0, 1);
}

void MeshOptimize2d :: GetNormalVector(INDEX surfind, const Point3d & p, PointGeomInfo & gi, Vec3d & n) const
{
  GetNormalVector (surfind, p, n);
}

}

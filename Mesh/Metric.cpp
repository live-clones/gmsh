// $Id: Metric.cpp,v 1.14 2002-05-20 18:28:28 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include <time.h>
#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Matrix.h"
#include "Interpolation.h"

Matrix3x3 Matrix3x3::operator * (const Matrix3x3 &autre)
{  
  Matrix3x3 m(0.);
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
	{
	  for(int k=0;k<3;k++)
	    m.mat[i][j] += mat[i][k] * autre.mat[k][j];
	  if (fabs(m.mat[i][j]) < 1.e-15)m.mat[i][j] = 0.0;
	}
    }
  return m;
}

void Matrix3x3::setMetric()
{
  Matrix3x3 rot (eVec[0],eVec[1],eVec[2]);
  Matrix3x3 rotT (eVec[0],eVec[1],eVec[2]);
  Matrix3x3 Id (0.0);
  rotT.transpose();
  Id.Identity(1.0);
  for(int i=0;i<3;i++)Id.mat[i][i] = eVal[i];
  Matrix3x3 kk = (Id * rot);
  Matrix3x3 m = rotT * kk;
  /*
  Msg(INFO,"rot: %g %g %g %g %g %g %g %g %g \n  ", 
      rot[0][0], rot[0][1], rot[0][2],
      rot[1][0], rot[1][1], rot[1][2],
      rot[2][0], rot[2][1], rot[2][2]);	      	      
  Msg(INFO,"rotT: %g %g %g %g %g %g %g %g %g \n  ", 
      rotT[0][0], rotT[0][1], rotT[0][2],
      rotT[1][0], rotT[1][1], rotT[1][2],
      rotT[2][0], rotT[2][1], rotT[2][2]);	      	      
  Msg(INFO,"id: %g %g %g %g %g %g %g %g %g \n  ", 
      Id[0][0], Id[0][1], Id[0][2],
      Id[1][0], Id[1][1], Id[1][2],
      Id[2][0], Id[2][1], Id[2][2]);	      	      

  Msg(INFO,"kk: %g %g %g %g %g %g %g %g %g \n  ", 
      kk[0][0], kk[0][1], kk[0][2],
      kk[1][0], kk[1][1], kk[1][2],
      kk[2][0], kk[2][1], kk[2][2]);	      	      

  Msg(INFO,"m: %g %g %g %g %g %g %g %g %g \n  ", 
      m[0][0], m[0][1], m[0][2],
      m[1][0], m[1][1], m[1][2],
      m[2][0], m[2][1], m[2][2]);	      	      
  */
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      mat[i][j] = m.mat[i][j];
}


GMSHMetric::GMSHMetric ()
{
  Identity ();
  Attractors = List_Create (2, 2, sizeof (Attractor *));
  limite_aniso = 3000.;
  min_cos = 0.0095;
  quality_measure = QUALITY_SIMPLEX_BASED;
}


Matrix3x3 GMSHMetric :: Intersect2Metrics (Matrix3x3 *m1[2])
{
  double lmax = 0.;
  int im,ic,io;
  Vector3 cmax(0.,0,0,0);
  Matrix3x3 res(0.0);

  for(int i=0;i<3;i++)
    {
      for(int j=0;j<2;j++)
	{
	  Vector3 v(0.0);
	  double l;
	  m1[j]->getEigen(i,v,l);
	  // cout << i << " " << j << " " << l << endl; 
	  if(l>lmax)
	    {
	      ic = i;
	      lmax = l;
	      cmax = v;
	      im = j;
	      io = (j==0)?1:0;
	    }
	}
    }
  
  // cout << "lmax " << lmax  << endl;
  res.setEigen (ic, cmax[0],cmax[1], cmax[2], lmax);
  
  for(int i=0;i<3;i++)
    {
      if(i != ic)
	{
	  Vector3 v(0.0);
	  double l;
	  m1[im]->getEigen(i,v,l);
	  double l2 =  m1[io]->quadraticFormEval(v);
	  // cout << l << " " << l2 << endl;
	  res.setEigen(i,v[0],v[1],v[2],(l2>l)?l2:l);
	}
    }  
  // cout << "gives " << endl;
  // res.print();
  // cout<<endl;
  res.setMetric();
  return res;
  
}

double GMSHMetric::
Local_Metric_Of_Attractors ( double X, double Y, double Z,
			     double metric[3][3])
{

  int i;
  Attractor *a;
  double u, x1, x2, d;
  Vertex v1 (X, Y, Z), v2,metr;

  Matrix3x3 myOldMetric (0.,m);

  for (i = 0; i < List_Nbr (Attractors); i++)
    {
      Matrix3x3 myMetric (0.);
      List_Read (Attractors, i, &a);
      if (a->v)
	{
	  d = sqrt ((X - a->v->Pos.X) * (X - a->v->Pos.X) +
		    (Y - a->v->Pos.Y) * (Y - a->v->Pos.Y) +
		    (Z - a->v->Pos.Z) * (Z - a->v->Pos.Z));
	  metr = Vertex(1.,0.,0.);
	}
      if (a->c)
	{
	  ProjectPointOnCurve (a->c, &v1, &v2, &metr);
	  d = sqrt ((X - v2.Pos.X) * (X - v2.Pos.X) +
		    (Y - v2.Pos.Y) * (Y - v2.Pos.Y) +
		    (Z - v2.Pos.Z) * (Z - v2.Pos.Z));
	  
	}
      double d1 = d * a->Radius;
      if(fabs(d1) < a->Radius * 1.e-6)d1 = 0.0;
      u = exp (-(d1 * d1));
      x1 = (1. - u) + u * a->lc1;
      x2 = (1. - u) + u * a->lc2;
      // cout << " dist from "<<  X  << " " << Y << " = " << d << endl;
      if (u > 1.e-2)
	{
	  if (a->v)
	    {
	      double q11 = 1. / (x1 * x1);
	      double q22 = 1. / (x2 * x2);
	      //double q12 = 1. / (x1 * x2);
	      
	      myMetric.setEigen (0,1.,0.,0.,q11);
	      myMetric.setEigen (1,0.,1.,0.,q22);
	      myMetric.setEigen (2,0.,0.,1.,q11);
	      myMetric.setMetric();
	    }
	  else if (a->c)
	    {
	      double xx=0.0,yy=0.0,zz=0.0;
	      if (metr.Pos.X != 0.0 || metr.Pos.Y != 0.0)
		zz = 1.0;
	      else if (metr.Pos.Y == 0.0)
		yy = 1.0;
	      else
		xx = 1.0;
	      
	      Vertex z (xx, yy, zz);
	      Vertex d2 = metr % z;
	      metr.norme ();
	      d2.norme ();
	      Vertex d3 = metr % d2;
	      d3.norme ();
	      
	      myMetric.setEigen (0,metr.Pos.X,metr.Pos.Y,metr.Pos.Z,1./(x1*x1));
	      myMetric.setEigen (1,d2.Pos.X,d2.Pos.Y,d2.Pos.Z,1./(x2*x2));
	      myMetric.setEigen (2,d3.Pos.X,d3.Pos.Y,d3.Pos.Z,1./(x1*x1));
	      myMetric.setMetric();
	      /*
	      Msg(INFO,"%d %12.5E heigens : %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E \n  ", a->c->Num,d,
		  metr.Pos.X, metr.Pos.Y, metr.Pos.Z,
		  d2.Pos.X,d2.Pos.Y,d2.Pos.Z,
		  d3.Pos.X,d3.Pos.Y,d3.Pos.Z);

	      Msg(INFO,"heigenv : %12.5E %12.5E \n",x1,x2);

	      Msg(INFO,"curve Metric: %g %g %g %g %g %g %g %g %g \n  ", 
		  myMetric[0][0], myMetric[0][1], myMetric[0][2],
		  myMetric[1][0], myMetric[1][1], myMetric[1][2],
		  myMetric[2][0], myMetric[2][1], myMetric[2][2]);	      	      
	      */
	    }
	  Matrix3x3 *M[2];
	  M[0] = &myMetric;
	  M[1] = &myOldMetric;
	  myOldMetric = Intersect2Metrics(M);
	  // myOldMetric = myMetric;
	}
    }
  myOldMetric.copy(m);  
  return 1.0;
}


void GMSHMetric::
setMetric (double u,
	   double v,
	   Surface * s)
{
  double a, b, c; // ellipse axx+byy+cxy=1
  double l1, l2; // 2 eigenvalues

  Identity ();
  Vertex p = InterpolateSurface (s, u, v, 0, 0);
  if (s->Typ != MSH_SURF_PLAN && s->Typ != MSH_SURF_REGL && s->Typ != MSH_SURF_TRIC)
    {
      Vertex du = InterpolateSurface (s, u, v, 1, 1);
      Vertex dv = InterpolateSurface (s, u, v, 1, 2);

      a = du * du;
      b = dv * dv;
      c = du * dv;

      m[0][0] = a;
      m[1][1] = b;
      m[0][1] = c;
      m[1][0] = c;

      l1 = 0.5 * ((a + b) + sqrt ((a - b) * (a - b) + 4. * c * c));
      l2 = 0.5 * ((a + b) - sqrt ((a - b) * (a - b) + 4. * c * c));

      if (l1 == 0.0 && l2 == 0.0)
	Identity ();

      else if (sqrt (l1 / l2) > limite_aniso)
	{
	  // on limite les rapports de metrique a limite_ansio
	  double r = limite_aniso * limite_aniso * (l2 / l1);
	  m[0][0] = a / r;
	  m[1][1] = b * r;
	  m[0][1] = c;
	  m[1][0] = c;
	}
    }
  Local_Metric_Of_Attractors (p.Pos.X, p.Pos.Y, p.Pos.Z, NULL);
  return;
}

void GMSHMetric::
setMetric (double x,
	   double y,
	   double z)
{
  Identity ();
  Local_Metric_Of_Attractors (x, y, z, NULL);
  return;
}


void GMSHMetric::
setMetricMin (double u,
	      double v,
	      Surface * s)
{
  /*setMetric(u,v,s);
     return;
   */
  Identity ();
  if (s->Typ != MSH_SURF_PLAN && s->Typ != MSH_SURF_REGL && s->Typ != MSH_SURF_TRIC)
    {
      Vertex du = InterpolateSurface (s, u, v, 1, 1);
      Vertex dv = InterpolateSurface (s, u, v, 1, 2);
      double d = (du * du > dv * dv) ? du * du : dv * dv;
      m[0][0] = d;
      m[1][1] = d;
    }
  return;
}

double GMSHMetric::
getWorstEdge (Simplex * s, Surface * surf, Vertex * v[2])
{
  double l1, l2, l3, q1, q2, q3;
  v[0] = s->V[0];
  v[1] = s->V[1];
  l1 = EdgeLengthOnSurface (surf, v, 1);
  v[0] = s->V[0];
  v[1] = s->V[2];
  l2 = EdgeLengthOnSurface (surf, v, 1);
  v[0] = s->V[1];
  v[1] = s->V[2];
  l3 = EdgeLengthOnSurface (surf, v, 1);

  q1 = 2. * l1 / (s->V[0]->lc + s->V[1]->lc);
  q2 = 2. * l2 / (s->V[0]->lc + s->V[2]->lc);
  q3 = 2. * l3 / (s->V[1]->lc + s->V[2]->lc);

  if (q1 >= q2 && q1 >= q3)
    {
      v[0] = s->V[0];
      v[1] = s->V[1];
      return l1;
    }
  else if (q2 >= q3)
    {
      v[0] = s->V[0];
      v[1] = s->V[2];
      return l2;
    }
  return l3;
}

void GMSHMetric::
setSimplexQuality (Simplex * s, Surface * surf)
{
  if (quality_measure == QUALITY_EDGES_BASED)
    {
      Vertex *v[2], vv;
      double l1, l2, l3, q1, q2, q3;
      v[0] = s->V[0];
      v[1] = s->V[1];
      vv = (*v[1]) - (*v[0]);
      l1 = LengthVector (&vv);
      v[0] = s->V[0];
      v[1] = s->V[2];
      vv = (*v[1]) - (*v[0]);
      l2 = LengthVector (&vv);
      v[0] = s->V[1];
      v[1] = s->V[2];
      vv = (*v[1]) - (*v[0]);
      l3 = LengthVector (&vv);

      q1 = 2. * l1 / (s->V[0]->lc + s->V[1]->lc);
      q2 = 2. * l2 / (s->V[0]->lc + s->V[2]->lc);
      q3 = 2. * l3 / (s->V[1]->lc + s->V[2]->lc);

      s->Quality = DMAX (DMAX (q1, q2), q3) / (RacineDeTrois);
    }
  else
    { 
      /*
      Matrix3x3 myOldMetric (0.,m);
      Identity();
      Local_Metric_Of_Attractors (s->V[0]->Pos.X,s->V[0]->Pos.Y,s->V[0]->Pos.Z,0);
      Local_Metric_Of_Attractors (s->V[1]->Pos.X,s->V[1]->Pos.Y,s->V[1]->Pos.Z,0);
      Local_Metric_Of_Attractors (s->V[2]->Pos.X,s->V[2]->Pos.Y,s->V[2]->Pos.Z,0);
      */
      s->Center_Ellipsum_2D (m);
      s->Quality = 3. * s->Radius / (s->V[0]->lc + s->V[1]->lc + s->V[2]->lc);
    }
}

void GMSHMetric::
setSimplexQuality (Simplex * s)
{
  if (quality_measure == QUALITY_EDGES_BASED)
    {
      Vertex *v[2], vv;
      double l1, l2, l3, l4, l5, l6, q1, q2, q3, q4, q5, q6;
      v[0] = s->V[0];
      v[1] = s->V[1];
      vv = (*v[1]) - (*v[0]);
      l1 = LengthVector (&vv);
      v[0] = s->V[0];
      v[1] = s->V[2];
      vv = (*v[1]) - (*v[0]);
      l2 = LengthVector (&vv);
      v[0] = s->V[1];
      v[1] = s->V[2];
      vv = (*v[1]) - (*v[0]);
      l3 = LengthVector (&vv);
      v[0] = s->V[0];
      v[1] = s->V[3];
      vv = (*v[1]) - (*v[0]);
      l4 = LengthVector (&vv);
      v[0] = s->V[1];
      v[1] = s->V[3];
      vv = (*v[1]) - (*v[0]);
      l5 = LengthVector (&vv);
      v[0] = s->V[2];
      v[1] = s->V[3];
      vv = (*v[1]) - (*v[0]);
      l6 = LengthVector (&vv);

      q1 = 2. * l1 / (s->V[0]->lc + s->V[1]->lc);
      q2 = 2. * l2 / (s->V[0]->lc + s->V[2]->lc);
      q3 = 2. * l3 / (s->V[1]->lc + s->V[2]->lc);
      q4 = 2. * l4 / (s->V[0]->lc + s->V[3]->lc);
      q5 = 2. * l5 / (s->V[1]->lc + s->V[3]->lc);
      q6 = 2. * l6 / (s->V[2]->lc + s->V[3]->lc);

      //s->Quality = (0.5/6.)*(q1+q2+q3+q4+q5+q6);

      //double qmax = (DMAX (q1, DMAX (q2, DMAX (q3, DMAX (q4, DMAX (q5, q6))))));

      s->Quality = (q1 + q2 + q3 + q4 + q5 + q6) / (6. * RacineDeDeux);
    }
  else
    {
      //double x = (s->V[0]->Pos.X + s->V[1]->Pos.X + s->V[2]->Pos.X + s->V[3]->Pos.X) / 4.;
      //double y = (s->V[0]->Pos.Y + s->V[1]->Pos.Y + s->V[2]->Pos.Y + s->V[3]->Pos.Y) / 4.;
      //      double z = (s->V[0]->Pos.Z + s->V[1]->Pos.Z + s->V[2]->Pos.Z + s->V[3]->Pos.Z) / 4.;
      //      setMetric(x,y,z);
      s->Center_Ellipsum_3D (m);
      s->Quality = 4. * s->Radius / (s->V[0]->lc + s->V[1]->lc + s->V[2]->lc + s->V[3]->lc);
    }
}

double GMSHMetric::operator () (int i, int j)
{
  return m[i][j];
}


double *GMSHMetric::operator[] (int i)
{
  if (i < 0 || i > 3)
    return m[0];
  return m[i];
}

void GMSHMetric::
Identity ()
{
  m[0][0] = m[1][1] = m[2][2] = 1.0;
  m[1][0] = m[1][2] = m[0][1] = 0.0;
  m[2][0] = m[2][1] = m[0][2] = 0.0;
}

void GMSHMetric::
setMetric (double u,
	   Curve * c)
{

}


double GMSHMetric::
getLc (double u, Curve * c)
{
  double l;
  Identity ();
  Vertex v = InterpolateCurve (c, u, 0);
  Vertex du = InterpolateCurve (c, u, 1);
  Local_Metric_Of_Attractors (v.Pos.X, v.Pos.Y, v.Pos.Z, NULL);
  l = LengthVector (&du);
  /*   
    Msg(INFO,"GetLC : u = %g l=%g  lc=%g  return=%g\n", u, l, v.lc, l/v.lc);
    Msg(INFO,"Metric: %g %g %g %g %g %g %g %g %g \n  ", 
    m[0][0], m[0][1], m[0][2],
    m[1][0], m[1][1], m[1][2],
    m[2][0], m[2][1], m[2][2]);
    Msg(INFO,"du = %g %g %g\n",du.Pos.X,du.Pos.Y,du.Pos.Z);
  */
  return l / v.lc;
}

double GMSHMetric::
LengthVector (Vertex * v)
{
  double qqq = v->Pos.X *  (v->Pos.X * m[0][0] + v->Pos.Y * m[0][1] + v->Pos.Z * m[0][2]) +
    v->Pos.Y * (v->Pos.X * m[1][0] + v->Pos.Y * m[1][1] + v->Pos.Z * m[1][2]) +
    v->Pos.Z * (v->Pos.X * m[2][0] + v->Pos.Y * m[2][1] + v->Pos.Z * m[2][2]);
  //  Msg(INFO,"qqq = %g\n",qqq);
  return sqrt (qqq);
}

double GMSHMetric::
EdgeLengthOnSurface (Surface * s, Vertex * v[2], int cuts)
{
  Vertex dv;

  if (!s)
    {
      dv = (*v[1]) - (*v[0]);
      return LengthVector (&dv);
    }

  dv.Pos.X = (v[1]->Pos.X - v[0]->Pos.X) / (double) cuts;
  dv.Pos.Y = (v[1]->Pos.Y - v[0]->Pos.Y) / (double) cuts;

  double l = 0.0, posu, posv;

  for (int i = 0; i < cuts; i++)
    {
      posu = v[0]->Pos.X + dv.Pos.X * ((double) (i) + 0.5);
      posv = v[0]->Pos.Y + dv.Pos.Y * ((double) (i) + 0.5);
      setMetric (posu, posv, s);
      l += LengthVector (&dv);
    }
  return l;
}

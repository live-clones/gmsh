/* $Id: Metric.cpp,v 1.2 2000-11-23 14:11:35 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "CAD.h"
#include "Mesh.h"
#include "Matrix.h"
#include "Interpolation.h"

GMSHMetric::GMSHMetric (){
  Identity ();
  Attractors = List_Create (2, 2, sizeof (Attractor *));
  apply_costest = true;
  apply_disttest = true;
  min_cos = 0.0095;
  max_dist = 1.e-3;
  limite_aniso = 3000.;
  quality_measure = QUALITY_SIMPLEX_BASED;
}

double GMSHMetric:: Local_Metric_Of_Attractors (double X, double Y, double Z,
						double metric[3][3]){
  int i;
  Attractor *a, *amin;
  double u, x1, x2, d, dmin;
  Vertex v1 (X, Y, Z), v2, der, metr;

  dmin = 1.e25;
  amin = NULL;

  for (i = 0; i < List_Nbr (Attractors); i++){
    List_Read (Attractors, i, &a);
    if (a->v){
      d = sqrt ((X - a->v->Pos.X) * (X - a->v->Pos.X) +
		(Y - a->v->Pos.Y) * (Y - a->v->Pos.Y) +
		(Z - a->v->Pos.Z) * (Z - a->v->Pos.Z));
    }
    if (a->c){
      ProjectPointOnCurve (a->c, &v1, &v2, &der);
      d = sqrt ((X - v2.Pos.X) * (X - v2.Pos.X) +
		(Y - v2.Pos.Y) * (Y - v2.Pos.Y) +
		(Z - v2.Pos.Z) * (Z - v2.Pos.Z));
      
    }
    /*
      if(a->s){
         ProjectPointOnSurface (a->c, &v1, &v2,&der);
         d = sqrt((X-v2.Pos.X)*(X-v2.Pos.X)+
         (Y-v2.Pos.Y)*(Y-v2.Pos.Y)+
         (Z-v2.Pos.Z)*(Z-v2.Pos.Z));

         }
    */
    if (d < dmin){
      dmin = d;
      amin = a;
      metr = der;
    }
  }
  if (amin){
    double d1 = dmin * amin->Radius;
    u = exp (-(d1 * d1));
    x1 = (1. - u) + u * amin->lc1;
    x2 = (1. - u) + u * amin->lc2;
  }
  if (amin && amin->v){
    double q11 = 1. / (x1 * x1);
    double q22 = 1. / (x2 * x2);
    double q12 = 1. / (x1 * x2);
    m[0][0] *= q11;
    m[0][1] *= q12;
    m[1][0] *= q12;
    m[1][1] *= q22;
    m[2][1] *= q11;
    m[1][2] *= q12;
    m[0][2] *= q12;
    m[2][0] *= q12;
    m[2][2] *= q11;
  }
  else if (amin && amin->c){
    Matrix3x3 < double >NewMetric (0.), Rot (0.), RotTranspose (0.), Id (0.);
    double xx = 0.0, yy = 0.0, zz = 0.0;
    
    if (metr.Pos.Z == 0.0)
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
    
    Id.Identity (1.0);
    Rot.Identity (1.0);
    
    Id[0][0] = 1. / (x1 * x1);
    Id[1][1] = 1. / (x2 * x2);
    Id[2][2] = 1. / (x2 * x2);
    
    Rot[0][0] = metr.Pos.X;
    Rot[0][1] = metr.Pos.Y;
    Rot[0][2] = metr.Pos.Z;
    Rot[1][0] = d2.Pos.X;
    Rot[1][1] = d2.Pos.Y;
    Rot[1][2] = d2.Pos.Z;
    Rot[2][0] = d3.Pos.X;
    Rot[2][1] = d3.Pos.Y;
    Rot[2][2] = d3.Pos.Z;
    
    RotTranspose = Rot;
    RotTranspose.transpose ();
    NewMetric = RotTranspose * (Id * Rot);
    NewMetric.copy (m);
  }
  else
    u = 0.0;
  return u;
}


void GMSHMetric:: setMetric (double u,double v, Surface * s){
  double a, b, c;		// ellipsis axx+byy+cxy=1
  double l1, l2;		// 2 eigenvalues

  Identity ();
  Vertex p = InterpolateSurface (s, u, v, 0, 0);
  if (s->Typ != MSH_SURF_PLAN && s->Typ != MSH_SURF_REGL && s->Typ != MSH_SURF_TRIC){
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
    
    else if (sqrt (l1 / l2) > limite_aniso){
      // on limite les rapports de metrique a limite_ansio
      double r = limite_aniso * limite_aniso * (l2 / l1);
      m[0][0] = a / r;
      m[1][1] = b * r;
      m[0][1] = c;
      m[1][0] = c;
    }
  }
  Local_Metric_Of_Attractors (p.Pos.X, p.Pos.Y, p.Pos.Z, NULL);

}

void GMSHMetric:: setMetric (double x, double y, double z){
  Identity ();
  Local_Metric_Of_Attractors (x, y, z, NULL);
  return;
}

void GMSHMetric:: setMetricMin (double u, double v, Surface * s){

  Identity ();
  if (s->Typ != MSH_SURF_PLAN && s->Typ != MSH_SURF_REGL && s->Typ != MSH_SURF_TRIC){
    Vertex du = InterpolateSurface (s, u, v, 1, 1);
    Vertex dv = InterpolateSurface (s, u, v, 1, 2);
    double d = (du * du > dv * dv) ? du * du : dv * dv;
    m[0][0] = d;
    m[1][1] = d;
  }

}

double GMSHMetric:: getWorstEdge (Simplex * s, Surface * surf, Vertex * v[2]){
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

  if (q1 >= q2 && q1 >= q3){
    v[0] = s->V[0];
    v[1] = s->V[1];
    return l1;
  }
  else if (q2 >= q3){
    v[0] = s->V[0];
    v[1] = s->V[2];
    return l2;
  }
  return l3;
}

void GMSHMetric:: setSimplexQuality (Simplex * s, Surface * surf){
  if (quality_measure == QUALITY_EDGES_BASED){
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
  else{
    s->Center_Ellipsum_2D (m);
    s->Quality = 3. * s->Radius / (s->V[0]->lc + s->V[1]->lc + s->V[2]->lc);
  }
}

void GMSHMetric::setSimplexQuality (Simplex * s){
  if (quality_measure == QUALITY_EDGES_BASED){
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
  else{
    s->Center_Ellipsum_3D (m);
    s->Quality = 4. * s->Radius / (s->V[0]->lc + s->V[1]->lc + s->V[2]->lc + s->V[3]->lc);
  }
}

double GMSHMetric::operator () (int i, int j){
  return m[i][j];
}

double *GMSHMetric::operator[] (int i){
  if (i < 0 || i > 3)
    return m[0];
  return m[i];
}

void GMSHMetric::Identity (){
  m[0][0] = m[1][1] = m[2][2] = 1.0;
  m[1][0] = m[1][2] = m[0][1] = 0.0;
  m[2][0] = m[2][1] = m[0][2] = 0.0;
}

void GMSHMetric::setMetric (double u, Curve * c){

}

double GMSHMetric::getLc (double u, Curve * c){
  double l;
  Identity ();
  Vertex v = InterpolateCurve (c, u, 0);
  Vertex du = InterpolateCurve (c, u, 1);
  Local_Metric_Of_Attractors (v.Pos.X, v.Pos.Y, v.Pos.Z, NULL);
  l = LengthVector (&du);
  return l / v.lc;
}

double GMSHMetric::LengthVector (Vertex * v){
  Vertex mult (v->Pos.X * m[0][0] + v->Pos.Y * m[0][1] + v->Pos.Z * m[0][2],
	       v->Pos.X * m[1][0] + v->Pos.Y * m[1][1] + v->Pos.Z * m[1][2],
	       v->Pos.X * m[2][0] + v->Pos.Y * m[2][1] + v->Pos.Z * m[2][2]);
  return sqrt (mult * (*v));
}

double GMSHMetric::EdgeLengthOnSurface (Surface * s, Vertex * v[2], int cuts){
  Vertex dv;

  if (!s){
    dv = (*v[1]) - (*v[0]);
    return LengthVector (&dv);
  }

  dv.Pos.X = (v[1]->Pos.X - v[0]->Pos.X) / (double) cuts;
  dv.Pos.Y = (v[1]->Pos.Y - v[0]->Pos.Y) / (double) cuts;

  double l = 0.0, posu, posv;

  for (int i = 0; i < cuts; i++){
    posu = v[0]->Pos.X + dv.Pos.X * ((double) (i) + 0.5);
    posv = v[0]->Pos.Y + dv.Pos.Y * ((double) (i) + 0.5);
    setMetric (posu, posv, s);
    l += LengthVector (&dv);
  }
  return l;
}

#ifndef _METRIC_H_
#define _METRIC_H_

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

#include "Matrix.h"

class GMSHMetric{
 public:
  double m[3][3];
  double limite_aniso;
  double min_cos;
  int quality_measure;
  List_T  *Attractors;
  GMSHMetric();
  void Identity ();
  Matrix3x3 Intersect2Metrics (Matrix3x3 *M[2]);
  double EdgeLengthOnSurface (Surface *s , Vertex *v[2], int cuts);
  double LengthVector (Vertex *v);
  void setMetric (double u,double v ,Surface *s);
  void setMetric (double x,double y ,double z);
  void setMetricMin (double u,double v ,Surface *s);
  void setSimplexQuality (Simplex *s,  Surface *surf);
  void  setSimplexQuality (Simplex *s);
  void setMetric (double u,Curve *c);
  double getLc ( double u , Curve *c );
  double operator () (int i,int j);
  double * operator [] (int i);
  double Local_Metric_Of_Attractors (double X, double Y, double Z,
				     double metric[3][3]);
  double getWorstEdge (Simplex *s, Surface *surf, Vertex *v[2]);
} ;

#endif

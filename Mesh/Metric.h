#ifndef _METRIC_H_
#define _METRIC_H_

#include "Matrix.h"
class GMSHMetric
{
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

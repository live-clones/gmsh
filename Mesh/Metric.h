/* $Id: Metric.h,v 1.4 2000-11-26 15:43:47 geuzaine Exp $ */
#ifndef _METRIC_H_
#define _METRIC_H_

class GMSHMetric{

public:
  double m[3][3];
  double min_cos;
  double max_dist;
  bool apply_costest;
  bool apply_disttest;
  double limite_aniso;
  int quality_measure;
  List_T  *Attractors;
  GMSHMetric();
  void Identity ();
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


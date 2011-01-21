// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_
#include "fullMatrix.h"
#include "DivideAndConquer.h"
#include "Bindings.h"

class GFace;

class lloydAlgorithm {
  int ITER_MAX;
  bool infiniteNorm;
  double test;
 public :
  lloydAlgorithm (int itermax, bool infnorm = false)
  : ITER_MAX(itermax), infiniteNorm(infnorm) {}
  lloydAlgorithm() {}
  void operator () (GFace *);
  double get_angle(double,double);
  void get_rotation(double,double,double&,double&,double&,double&);
  void get_unrotation(double,double,double&,double&,double&,double&);
  void rotate(SPoint2,SPoint2&);
  void unrotate(SPoint2,SPoint2&);
  SPoint2 fixed_point(const std::vector<SPoint2>&);
  double range(const std::vector<SPoint2>&,double,double,bool);
  double gradient(const std::vector<SPoint2>&,double,bool);
  bool point_side(SPoint2,double,bool);
  double polygon_area(const std::vector<SPoint2>&);
  SPoint2 line_intersection(SPoint2,SPoint2,double,bool,bool&);
  double optimize(int,int);
  static void registerBindings(binding *b);
};

#endif

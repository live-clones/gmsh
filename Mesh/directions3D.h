// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "GFace.h"
#include "MElementOctree.h"
#if defined(HAVE_ANN)
#include <ANN/ANN.h>
#endif

class Matrix{
 private:
  double m11,m21,m31,m12,m22,m32,m13,m23,m33;
 public:
  Matrix();
  ~Matrix();
  void set_m11(double);
  void set_m21(double);
  void set_m31(double);
  void set_m12(double);
  void set_m22(double);
  void set_m32(double);
  void set_m13(double);
  void set_m23(double);
  void set_m33(double);
  double get_m11();
  double get_m21();
  double get_m31();
  double get_m12();
  double get_m22();
  double get_m32();
  double get_m13();
  double get_m23();
  double get_m33();
};

class Frame_field{
 private:
  static std::map<MVertex*,Matrix> field;
  static std::vector<std::pair<MVertex*,Matrix> > random;
  #if defined(HAVE_ANN)
  static ANNpointArray duplicate;
  static ANNkd_tree* kd_tree;
  #endif
  Frame_field();
 public:
  static void init_region(GRegion*);
  static void init_face(GFace*);
  static bool translate(GFace*,MElementOctree*,MVertex*,SPoint2,SVector3&,SVector3&);
  static Matrix search(double,double,double);
  static Matrix combine(double,double,double);
  static bool inside_domain(MElementOctree*,double,double);
  static double get_ratio(GFace*,SPoint2);
  static void print_field1();
  static void print_field2(GRegion*);
  static void print_segment(SPoint3,SPoint3,std::ofstream&);
  static GRegion* test();
  static void clear();
};

class Size_field{
 private:
  static std::map<MVertex*,double> boundary;
  static MElementOctree* octree;
  Size_field();
 public:
  static void init_region(GRegion*);
  static void solve(GRegion*);
  static double search(double,double,double);
  static double get_ratio(GFace*,SPoint2);
  static void print_field();
  static GRegion* test();
  static void clear();
};

class Nearest_point{
 private:
  static std::vector<SPoint3> random;
  #if defined(HAVE_ANN)
  static ANNpointArray duplicate;
  static ANNkd_tree* kd_tree;
  #endif
  Nearest_point();
 public:
  static void init_region(GRegion*);
  static bool search(double,double,double,SVector3&);
  static double T(double,double,double,double,double);
  static void print_field(GRegion*);
  static void print_segment(SPoint3,SPoint3,std::ofstream&);
  static GRegion* test();
  static void clear();
};
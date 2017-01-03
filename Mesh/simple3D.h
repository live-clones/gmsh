// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Tristan Carrier François Henrotte


#ifndef _SIMPLE3D_H_
#define _SIMPLE3D_H_


#include "SVector3.h"
#include <list>
#include "GRegion.h"
#include "MElementOctree.h"

class Node;
class Metric;

class Filler{
 private:
  static std::vector<MVertex*> new_vertices;
  Metric get_metric(double,double,double);
  Metric get_metric(double,double,double,GEntity*);
  double get_size(double,double,double);
  double get_size(double,double,double,GEntity*);
  bool inside_domain(MElementOctree*,double,double,double);
  bool far_from_boundary(MElementOctree*,Node*);
  void compute_parameters(Node*,GEntity*);
  void create_spawns(GEntity*,MElementOctree*,Node*,std::vector<Node*>&);
  double improvement(GEntity*,MElementOctree*,SPoint3,double,SVector3);
  int code(int);
  void print_segment(SPoint3,SPoint3,std::ofstream&);
  void print_node(Node*,std::ofstream&);
 public:
  Filler();
  ~Filler();
  void treat_model();
  void treat_region(GRegion*);
  static int get_nbr_new_vertices();
  static MVertex* get_new_vertex(int);
};

#endif


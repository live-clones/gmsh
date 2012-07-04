// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "GRegion.h"
#include <set>

class Hex{
 private:
  double quality;
  MVertex *a,*b,*c,*d,*e,*f,*g,*h;
 public:
  Hex();
  Hex(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  ~Hex();
  double get_quality() const;
  void set_quality(double);
  MVertex* get_a();
  MVertex* get_b();
  MVertex* get_c();
  MVertex* get_d();
  MVertex* get_e();
  MVertex* get_f();
  MVertex* get_g();
  MVertex* get_h();
  void set_vertices(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  bool operator<(const Hex&) const;
};

class Recombinator{
 private:
  std::vector<Hex> potential;
  std::map<MElement*,bool> markings;
  std::map<MVertex*,std::set<MVertex*> > vertex_to_vertices;
  std::map<MVertex*,std::set<MElement*> > vertex_to_elements;
 public:
  Recombinator();
  ~Recombinator();
  
  void execute();
  void execute(GRegion*);
  
  void init_markings(GRegion*);
  void patern1(GRegion*);
  void patern2(GRegion*);
  void patern3(GRegion*);
  void merge(GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
	
  bool sliver(MElement*,Hex);
  double diagonal(MElement*,int&,int&);
  double distance(MVertex*,MVertex*);
  double distance(MVertex*,MVertex*,MVertex*);
  double scalar(MVertex*,MVertex*,MVertex*,MVertex*);
  void two_others(int,int,int&,int&);
  bool valid(Hex,const std::set<MElement*>&);
  bool valid(Hex);
  double eta(MVertex*,MVertex*,MVertex*,MVertex*);
  bool linked(MVertex*,MVertex*);
	
  void find(MVertex*,MVertex*,const std::vector<MVertex*>&,std::set<MVertex*>&);
  void find(MVertex*,MVertex*,MVertex*,const std::vector<MVertex*>&,std::set<MVertex*>&);
  void find(MVertex*,MVertex*,std::set<MElement*>&);
  void find(MVertex*,Hex,std::set<MElement*>&);
  MVertex* find(MVertex*,MVertex*,MVertex*,MVertex*,const std::set<MElement*>&);
  
  void intersection(const std::set<MVertex*>&,const std::set<MVertex*>&,const std::vector<MVertex*>&,std::set<MVertex*>&);
  void intersection(const std::set<MVertex*>&,const std::set<MVertex*>&,const std::set<MVertex*>&,const std::vector<MVertex*>&,std::set<MVertex*>&);
  void intersection(const std::set<MElement*>&,const std::set<MElement*>&,std::set<MElement*>&);
  
  bool inclusion(MVertex*,Hex);
  bool inclusion(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  bool inclusion(MVertex*,MVertex*,MVertex*,const std::set<MElement*>&);
  
  void build_vertex_to_vertices(GRegion*);
  void build_vertex_to_elements(GRegion*);
  void print_vertex_to_vertices(GRegion*);
  void print_vertex_to_elements(GRegion*);
  void print_segment(SPoint3,SPoint3,std::ofstream&);
	
  double scaled_jacobian(MVertex*,MVertex*,MVertex*,MVertex*);
  double max_scaled_jacobian(MElement*,int&);
  double min_scaled_jacobian(Hex);	
};
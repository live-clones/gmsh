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

class Facet{
 private:
  MVertex *a,*b,*c;
  unsigned long long hash;
 public:
  Facet();
  Facet(MVertex*,MVertex*,MVertex*);
  ~Facet();
  MVertex* get_a();
  MVertex* get_b();
  MVertex* get_c();
  void set_vertices(MVertex*,MVertex*,MVertex*);
  bool same_vertices(Facet);
  void compute_hash();
  unsigned long long get_hash() const;
  bool operator<(const Facet&) const;
};

class Diagonal{
 private:
  MVertex *a,*b;
  unsigned long long hash;
 public:
  Diagonal();
  Diagonal(MVertex*,MVertex*);
  ~Diagonal();
  MVertex* get_a();
  MVertex* get_b();
  void set_vertices(MVertex*,MVertex*);
  bool same_vertices(Diagonal);
  void compute_hash();
  unsigned long long get_hash() const;
  bool operator<(const Diagonal&) const;
};

class Recombinator{
 private:
  std::vector<Hex> potential;
  std::map<MElement*,bool> markings;
  std::map<MVertex*,std::set<MVertex*> > vertex_to_vertices;
  std::map<MVertex*,std::set<MElement*> > vertex_to_elements;
  std::multiset<Facet> hash_tableA;
  std::multiset<Diagonal> hash_tableB;
  std::multiset<Diagonal> hash_tableC;
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
  bool inclusion(Facet);
  bool inclusion(Diagonal);
  bool duplicate(Diagonal);
  
  bool conformityA(Hex);
  bool conformityA(MVertex*,MVertex*,MVertex*,MVertex*);
  bool conformityB(Hex);
  bool conformityC(Hex);
	
  void build_vertex_to_vertices(GRegion*);
  void build_vertex_to_elements(GRegion*);
  void build_hash_tableA(Hex);
  void build_hash_tableA(MVertex*,MVertex*,MVertex*,MVertex*);
  void build_hash_tableA(Facet);
  void build_hash_tableB(Hex);
  void build_hash_tableB(MVertex*,MVertex*,MVertex*,MVertex*);
  void build_hash_tableB(Diagonal);
  void build_hash_tableC(Hex);
  void build_hash_tableC(Diagonal);
  
  void print_vertex_to_vertices(GRegion*);
  void print_vertex_to_elements(GRegion*);
  void print_hash_tableA();
  void print_segment(SPoint3,SPoint3,std::ofstream&);
	
  double scaled_jacobian(MVertex*,MVertex*,MVertex*,MVertex*);
  double max_scaled_jacobian(MElement*,int&);
  double min_scaled_jacobian(Hex);	
};

class Prism{
 private:
  double quality;
  MVertex *a,*b,*c,*d,*e,*f;
 public:
  Prism();
  Prism(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  ~Prism();
  double get_quality() const;
  void set_quality(double);
  MVertex* get_a();
  MVertex* get_b();
  MVertex* get_c();
  MVertex* get_d();
  MVertex* get_e();
  MVertex* get_f();
  void set_vertices(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  bool operator<(const Prism&) const;
};

class Supplementary{
 private:
  std::vector<Prism> potential;
  std::map<MElement*,bool> markings;
  std::map<MVertex*,std::set<MVertex*> > vertex_to_vertices;
  std::map<MVertex*,std::set<MElement*> > vertex_to_tetrahedra;
  std::multiset<Facet> hash_tableA;
  std::multiset<Diagonal> hash_tableB;
  std::multiset<Diagonal> hash_tableC;
 public:
  Supplementary();
  ~Supplementary();
	
  void execute();
  void execute(GRegion*);	
	
  void init_markings(GRegion*);
  void patern(GRegion*);
  void merge(GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
	
  bool four(MElement*);
  bool five(MElement*);
  bool six(MElement*);
  bool eight(MElement*);	
	
  bool sliver(MElement*,Prism);
  bool valid(Prism,const std::set<MElement*>&);
  bool valid(Prism);
  double eta(MVertex*,MVertex*,MVertex*,MVertex*);
  bool linked(MVertex*,MVertex*);	
	
  void find(MVertex*,MVertex*,const std::vector<MVertex*>&,std::set<MVertex*>&);	
  void find(MVertex*,Prism,std::set<MElement*>&);
	
  void intersection(const std::set<MVertex*>&,const std::set<MVertex*>&,const std::vector<MVertex*>&,std::set<MVertex*>&);	
	
  bool inclusion(MVertex*,Prism);
  bool inclusion(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  bool inclusion(MVertex*,MVertex*,MVertex*,const std::set<MElement*>&);
  bool inclusion(Facet);
  bool inclusion(Diagonal);
  bool duplicate(Diagonal);
	
  bool conformityA(Prism);
  bool conformityA(MVertex*,MVertex*,MVertex*,MVertex*);
  bool conformityB(Prism);
  bool conformityC(Prism);
	
  void build_vertex_to_vertices(GRegion*);
  void build_vertex_to_tetrahedra(GRegion*);
  void build_hash_tableA(Prism);
  void build_hash_tableA(MVertex*,MVertex*,MVertex*,MVertex*);
  void build_hash_tableA(Facet);
  void build_hash_tableB(Prism);
  void build_hash_tableB(MVertex*,MVertex*,MVertex*,MVertex*);
  void build_hash_tableB(Diagonal);
  void build_hash_tableC(Prism);
  void build_hash_tableC(Diagonal);
	
  double scaled_jacobian(MVertex*,MVertex*,MVertex*,MVertex*);
  double min_scaled_jacobian(Prism);
};

class PostOp{
 private:
  std::map<MElement*,bool> markings;
  std::map<MVertex*,std::set<MElement*> > vertex_to_tetrahedra;
 public:
  PostOp();
  ~PostOp();
	
  void execute();
  void execute(GRegion*);
	
  void init_markings(GRegion*);
  void pyramids(GRegion*);
  void pyramids(MVertex*,MVertex*,MVertex*,MVertex*,GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
	
  bool four(MElement*);
  bool five(MElement*);
  bool six(MElement*);
  bool eight(MElement*);
	
  MVertex* find(MVertex*,MVertex*,MVertex*,MVertex*,MElement*);
  void find(MVertex*,MVertex*,std::set<MElement*>&);
	
  void intersection(const std::set<MElement*>&,const std::set<MElement*>&,std::set<MElement*>&);
	
  void build_vertex_to_tetrahedra(GRegion*);
};
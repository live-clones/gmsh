// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Tristan Carrier

#ifndef _YAMAKAWA_H_
#define _YAMAKAWA_H_


#include "GRegion.h"
#include "MVertex.h"
#include <set>
#include <map>

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>

using namespace std;


extern void export_gregion_mesh(GRegion *gr, string filename);


class PEEntity{
protected:
  vector<const MVertex *> vertices;
  size_t hash;
  void compute_hash();
public:
  PEEntity(const vector<const MVertex*> &_v);
  //PEEntity(size_t l);
  virtual ~PEEntity();
  virtual size_t get_max_nb_vertices() const=0;
  const MVertex* getVertex(size_t n) const;
  bool hasVertex(const MVertex *v)const;
  size_t get_hash() const;
  bool same_vertices(const PEEntity *t)const;
  bool operator<(const PEEntity&) const;
  //bool operator==(const PEEntity&) const;
  //bool operator==(const size_t&) const;
};

class PELine : public PEEntity{
public:
  PELine(const vector<const MVertex*> &_v);
  virtual ~PELine();
  size_t get_max_nb_vertices() const;
};

class PETriangle : public PEEntity{
public:
  PETriangle(const vector<const MVertex*> &_v);
  //PETriangle(size_t l);
  virtual ~PETriangle();
  size_t get_max_nb_vertices() const;
};

class PEQuadrangle : public PEEntity{
public:
  PEQuadrangle(const vector<const MVertex*> &_v);
  //PEQuadrangle(size_t l);
  virtual ~PEQuadrangle();
  size_t get_max_nb_vertices() const;
};


template<class T>
class clique_stop_criteria{
public:
  //typedef tr1::unordered_set<T> graph_data_no_hash;
  typedef std::set<T> graph_data_no_hash;
  clique_stop_criteria(map<T, std::set<MElement*> > &_m, int _i);
  ~clique_stop_criteria();
  bool stop(const graph_data_no_hash &clique)const;
  void export_corresponding_mesh(const graph_data_no_hash &clique)const;

private:
  const map<T, std::set<MElement*> > &hex_to_tet;
  const unsigned int total_number_tet;
};


template<class T>
class cliques_compatibility_graph{
public:
  typedef unsigned long long hash_key;

  //    typedef  set<T> graph_data;
  //    typedef  map<T, graph_data > graph;
  //    typedef multimap<int,T> ranking_data;
  //typedef tr1::unordered_set<T> graph_data_no_hash;
  typedef std::set<T> graph_data_no_hash;
  //    typedef tr1::unordered_multimap<hash_key, T> graph_data;
  //    typedef tr1::unordered_multimap<hash_key, pair<T, graph_data > > graph;
  //    typedef tr1::unordered_map<int,T> ranking_data;
  typedef std::multimap<hash_key, T> graph_data;
  typedef std::multimap<hash_key, pair<T, graph_data > > graph;
  typedef std::map<int,T> ranking_data;

  typedef void (*ptrfunction_export)(cliques_compatibility_graph<T>&, int, string);

  cliques_compatibility_graph(graph &_g, const map<T, std::vector<double> > &_hex_ranks, unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels, clique_stop_criteria<T> *csc, ptrfunction_export fct);
  ~cliques_compatibility_graph();
  void find_cliques();
  void export_cliques();

  virtual typename graph::const_iterator begin_graph(){return G.begin();};
  virtual typename graph::const_iterator end_graph(){return G.end();};

  bool found_the_ultimate_max_clique;

  multimap<int, set<T> > allQ;// all cliques

protected:
  void erase_entry(graph_data &s, T &u, hash_key &key);
  void find_cliques(graph_data &s,int n);
  void split_set_BW(const T &u, const hash_key &u_key,const graph_data &s, graph_data &white, graph_data &black);
  void fill_black_set(const T &u, const hash_key &u_key, const graph_data &s, graph_data &black);
  void choose_u(const graph_data &s, T &u, hash_key &u_key);
  // the maximum score (int) will be chosen...
  double function_to_maximize_for_u(const T &u, const hash_key &u_key, const graph_data &s);
  void store_clique(int n);
  // returns true if two nodes are connected in the compatibility graph
  virtual bool compatibility(const T &u, const hash_key &u_key, const T &v, const hash_key &v_key);

  ptrfunction_export export_clique_graph;

  const bool debug;
  unsigned int max_nb_cliques;
  unsigned int nb_hex_potentiels;
  unsigned int max_clique_size;
  unsigned int position;
  unsigned int total_nodes_number;
  unsigned int total_nb_of_cliques_searched;
  unsigned int max_nb_of_stored_cliques;// to reduce memory footprint (set to zero if no limit)

  clique_stop_criteria<T>* criteria;

  bool cancel_search;
  const map<T, std::vector<double> > &hex_ranks;
  graph &G;
  graph_data_no_hash Q;// the current clique
};



template<class T>
class cliques_losses_graph : public cliques_compatibility_graph<T> {
  //    typedef  set<T> graph_data;
  //    typedef  map<T, graph_data > graph;
  //    typedef tr1::unordered_set<T> graph_data;
  //    typedef tr1::unordered_map<T, graph_data > graph;
public:
  typedef unsigned long long hash_key;
  typedef multimap<hash_key, T> graph_data;
  typedef multimap<hash_key, pair<T, graph_data > > graph;
  //    typedef tr1::unordered_multimap<hash_key, T> graph_data;
  typedef void (*ptrfunction_export)(cliques_compatibility_graph<T>&, int, string);

  cliques_losses_graph(graph &_g, const map<T, std::vector<double> > &_hex_ranks, unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels, clique_stop_criteria<T> *csc, ptrfunction_export fct);
  ~cliques_losses_graph();

protected:
  // returns false if two nodes are connected in the losses graph (i.e. true if connected in compatibility graph)
  virtual bool compatibility(const T &u, const hash_key &u_key, const T &v, const hash_key &v_key);
  graph &G;
};



class Hex{
private:
  double quality;
  unsigned long long hash;
  MVertex *a,*b,*c,*d,*e,*f,*g,*h;
  void set_hash();
public:
  Hex();
  Hex(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  ~Hex();
  double get_quality();
  void set_quality(double);
  MVertex* get_a();
  MVertex* get_b();
  MVertex* get_c();
  MVertex* get_d();
  MVertex* get_e();
  MVertex* get_f();
  MVertex* get_g();
  MVertex* get_h();
  MVertex* getVertex(int n);
  bool hasVertex(const MVertex *v);
  bool same_vertices(Hex *h);
  void set_vertices(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  unsigned long long get_hash();
  bool operator<( Hex&) ;
};

class Facet{
private:
  MVertex *a,*b,*c;
  int num[3];
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

class Tuple{
private:
  MVertex *v1,*v2,*v3;
  MElement* element;
  GFace* gf;
  unsigned long long hash;
public:
  Tuple();
  Tuple(MVertex*,MVertex*,MVertex*,MElement*,GFace*);
  Tuple(MVertex*,MVertex*,MVertex*);
  ~Tuple();
  MVertex* get_v1();
  MVertex* get_v2();
  MVertex* get_v3();
  MElement* get_element() const;
  GFace* get_gf() const;
  bool same_vertices(Tuple);
  unsigned long long get_hash() const;
  bool operator<(const Tuple&) const;
};

//inline std::ostream& operator<<(std::ostream& s, const PETriangle& t){
//  const MVertex *v;
//  for (int i=0;i<3;i++){
//    v = t.getVertex(i);
//    s << "(" << v->x() << "," << v->y() << "," << v->z() << ")";
//  }
//  return s;
//};

class Recombinator{
protected:
  std::vector<Hex*> potential;
  std::map<MElement*,bool> markings;
  std::multiset<Facet> hash_tableA;
  std::multiset<Diagonal> hash_tableB;
  std::multiset<Diagonal> hash_tableC;
  std::multiset<Tuple> tuples;
  std::set<MElement*> triangles;
  //std::fstream file; //fordebug

public:
  Recombinator();
  ~Recombinator();

  std::map<MVertex*,std::set<MVertex*> > vertex_to_vertices;
  std::map<MVertex*,std::set<MElement*> > vertex_to_elements;

  virtual void execute();
  virtual void execute(GRegion*);

  void init_markings(GRegion*);
  virtual void pattern1(GRegion*);
  virtual void pattern2(GRegion*);
  virtual void pattern3(GRegion*);
  virtual void merge(GRegion*);
  void improved_merge(GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
  // tuples are triangles on geometrical faces (region boundaries...)
  void build_tuples(GRegion*);
  void modify_surfaces(GRegion*);
  void modify_surfaces(MVertex*,MVertex*,MVertex*,MVertex*);

  bool sliver(MElement*,Hex&);
  double diagonal(MElement*,int&,int&);
  double distance(MVertex*,MVertex*);
  double distance(MVertex*,MVertex*,MVertex*);
  double scalar(MVertex*,MVertex*,MVertex*,MVertex*);
  void two_others(int,int,int&,int&);
  // soit une face du cube: abcd
  // en principe, on doit avoir soit les facets (abc) et (acd), soit les facets (abd) et(bcd) qui sont inclues dans un des tets qui forment l'hex.
  // si c'est le cas pour toutes les 6 faces de l'hex, return true.
  // ce test permet probablement de virer les hex "avec des trous" (avec 8 noeuds ok, mais un tet manquant, ce qui peut occasionner un hex à 14 faces, par exemple, si l'on compte les faces à partir des tets inclus)
  bool valid(Hex&,const std::set<MElement*>&);
  // renvoie true si le "MQuadrangle::etaShapeMeasure" des 6 faces est plus grand que 0.000001
  bool valid(Hex&);
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

  // return true if vertex belong to hex
  bool inclusion(MVertex*,Hex);
  // renvoie true si vertex se trouve dans [a,b,c]
  bool inclusion(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  // return true if all three vertices v1,v2 and v3 belong to one tet
  bool inclusion(MVertex*,MVertex*,MVertex*,const std::set<MElement*>&);
  // return true si la facet existe dans la table A
  bool inclusion(Facet);
  // return true si la diagonal existe dans la table B
  bool inclusion(Diagonal);
  // return true si la diagonal existe dans la table C !!!!!!!!!   Sinon, c'est exactement la même fonction !!!!! avec un nom différent !
  bool duplicate(Diagonal);

  // return true si un hex est "conforme A"
  // est "conforme A" un hex dont les 6 faces sont "conforme A"
  bool conformityA(Hex&);
  // est "conforme A" une face si ses 4 facets existent dans tableA, ou bien si aucune des ses facets ne se trouve dans table A
  bool conformityA(MVertex*,MVertex*,MVertex*,MVertex*);
  // return false si:
  //- une des 12 arrêtes de l'hex se trouve dans tableB !!! (pas C !!!), càd si une arrete a été utilisée comme diagonale d'un autre hex
  //- (ou bien) si, pour chaque face de l'hex, on a une diagonale dans tableB et pas l'autre
  bool conformityB(Hex&);
  // return false si une des 12 diagonales du cube se trouve dans tableC, càd a été utilisée comme arrête
  bool conformityC(Hex&);

  // return true si les 6 faces de l'hex sont "faces_statuquo"
  bool faces_statuquo(Hex&);
  // return false si, parmis les deux paires de facets de la face, il existe un couple de facet qui soient toutes les deux des tuples, mais correspondant à des geometric faces différentes. Bref, une arrête géométrique confondue avec une diagonale de la face.
  bool faces_statuquo(MVertex*,MVertex*,MVertex*,MVertex*);

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
  //double scaled_jacobian_face(MVertex*,MVertex*,MVertex*,MVertex*);
  double max_scaled_jacobian(MElement*,int&);
  double min_scaled_jacobian(Hex&);
};

class Recombinator_Graph : public Recombinator{
public:
  typedef size_t my_hash_key;
  typedef multimap<my_hash_key,PETriangle*> trimap;
  typedef map<PETriangle*, PETriangle*> tripair;


  //typedef tr1::unordered_multimap<my_hash_key,PETriangle*> trimap;
  typedef trimap::iterator iter;
  typedef trimap::const_iterator citer;

  typedef multimap<my_hash_key,PELine*> linemap;
  //typedef tr1::unordered_multimap<my_hash_key,PELine*> linemap;


  bool found_the_ultimate_max_clique;

  set<Hex*>& getHexInGraph(){return set_of_all_hex_in_graph;};

protected:
  bool debug,debug_graph;
  std::map<Hex*, std::set<MElement*> > hex_to_tet;
  std::map<Hex*, std::set<PELine*> > hex_to_edges;
  std::map<PELine*, std::set<Hex*> > edges_to_hex;
  std::map<Hex*, std::set<PETriangle*> > hex_to_faces;
  std::map<PETriangle*, std::set<Hex*> > faces_to_hex;
  std::map<PETriangle*, unsigned int > faces_connectivity;// # of adjacent tets (1 or 2)
  std::map<MElement*, std::set<Hex*> >tet_to_hex;
  std::map<Hex*, std::vector<double> > hex_ranks;


  typedef unsigned long long hash_key;
  //    typedef tr1::unordered_multimap<hash_key, Hex*> graph_data;
  //    typedef tr1::unordered_multimap<hash_key, pair<Hex*, graph_data > > graph;
  typedef multimap<hash_key, Hex*> graph_data;
  typedef multimap<hash_key, pair<Hex*, graph_data > > graph;

  graph incompatibility_graph;
  set<Hex*> set_of_all_hex_in_graph;

  std::multimap<unsigned long long, Hex*>created_potential_hex;

  void create_faces_connectivity();
  void add_face_connectivity(MElement *tet, int i, int j, int k);

  void add_edges(Hex *hex);
  void fill_edges_table(const MVertex *a, const MVertex *b, const MVertex *c, const MVertex *d, Hex *hex);
  void add_face(const MVertex *a,const MVertex* b,const MVertex *c,Hex *hex);
  void add_face(const MVertex *a,const MVertex* b,const MVertex *c,std::multimap<unsigned long long, pair<PETriangle*,int> > &f);
  std::multimap<double,Hex*> degree;// degree = the final ranking of hexahedra
  std::multimap<int,Hex*> idegree;// idegree = number of connected hex in indirect neighbors graph
  std::multimap<int,Hex*> ndegree;// ndegree = number of direct neighbors !!! not chosen yet !!!
  std::map<Hex*,int> reverse_idegree;
  std::map<Hex*,int> reverse_ndegree;
  // each tet has at least one neighbor, at most four. For all not chosen hex, check this data to find how many direct neighbors...
  //    std::map<MElement*,set<PETriangle*> > tet_to_triangle;
  std::map<PETriangle*,set<MElement*> > triangle_to_tet;
  std::map<MElement*,int> tet_degree;

  bool find_face_in_blossom_info(MVertex *a, MVertex *b, MVertex *c, MVertex *d);
  void compute_hex_ranks_blossom();
  PETriangle* get_triangle(MVertex*a, MVertex* b, MVertex *c);
  bool is_blossom_pair(PETriangle *t1, PETriangle *t2);

  tripair blossom_info;
  trimap triangular_faces;
  linemap edges_and_diagonals;

  map<PETriangle*, GFace*> tri_to_gface_info;

  vector<Hex*> chosen_hex;
  vector<MElement*> chosen_tet;

  citer find_the_triangle(PETriangle *t, const trimap &list);
  linemap::const_iterator  find_the_line(PELine *t, const linemap &list);
  std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator  find_the_triangle(PETriangle *t, std::multimap<unsigned long long, pair<PETriangle*, int> > &list);
  std::multimap<unsigned long long, Hex* >::const_iterator  find_the_created_potential_hex(Hex *t, const std::multimap<unsigned long long, Hex*>  &list);

  int nbhex_in_losses_graph;
  double average_connectivity;
  bool post_check_validation(Hex* current_hex);

  PETriangle* get_triangle(MElement *element, int i, int j, int k);

  void compute_hex_ranks();

  // check if the hex is good enough to be put into the graph. If not in the graph, it cannot be chosen...
  bool is_not_good_enough(Hex* hex);

  // fills incompatibility_graph if two hex share a common (non-sliver!) tet
  void create_indirect_neighbors_graph();

  graph::iterator find_hex_in_graph(Hex* hex);
  graph_data::iterator find_hex_in_graphrow(Hex* hex, graph_data &row);
  bool find_hex_couple_in_graph(Hex* hex, Hex* other_hex);
  void add_graph_entry(Hex* hex, Hex* other_hex);

  // fills incompatibility_graph if two hex are incompatible direct neighbors,
  // i.e. they have one (or more) common face or common edge and are not compatible
  void create_direct_neighbors_incompatibility_graph();
  void evaluate_hex_couple(Hex* hex, Hex* other_hex);

  // if two hex are not connected in the incompatibility_graph, they are compatible
  void create_losses_graph(GRegion *gr);

  void merge_clique(GRegion* gr, cliques_losses_graph<Hex*> &cl,int clique_number=0);

  void fill_tet_to_hex_table(Hex *hex);

  virtual void pattern1(GRegion*);
  virtual void pattern2(GRegion*);
  virtual void pattern3(GRegion*);

  void merge(GRegion*);

  // ------- exports --------
  void export_tets(set<MElement*> &tetset, Hex* hex, string s);
  void export_single_hex_all(Hex* hex,string s);
  void export_single_hex(Hex* hex,string s);
  void export_single_hex_faces(Hex* hex,string s);
  void export_single_hex_tet(Hex* hex,string s);
  void export_all_hex(int &file,GRegion *gr);
  void export_hexmesh_so_far(int &file);
  void export_direct_neighbor_table(int max);
  void export_hex_init_degree(GRegion *gr, const std::map<Hex*,int> &init_degree, const vector<Hex*> &chosen_hex);

  int max_nb_cliques;
  string graphfilename;

public:
  Recombinator_Graph(unsigned int max_nb_cliques, string filename=string());
  ~Recombinator_Graph();
  virtual void execute();
  virtual void execute(GRegion*);
  virtual void buildGraphOnly(unsigned int max_nb_cliques, string filename=string());
  virtual void buildGraphOnly(GRegion*, unsigned int max_nb_cliques, string filename=string());
  virtual void execute_blossom(unsigned int max_nb_cliques, string filename=string());
  virtual void execute_blossom(GRegion*, unsigned int max_nb_cliques, string filename=string());
  virtual void createBlossomInfo();
  void createBlossomInfo(GRegion *gr);
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
  std::multiset<Tuple> tuples;
  std::set<MElement*> triangles;
  //std::fstream file; //fordebug

public:
  Supplementary();
  ~Supplementary();

  void execute();
  void execute(GRegion*);

  void init_markings(GRegion*);
  void pattern(GRegion*);
  void merge(GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
  void build_tuples(GRegion*);
  void modify_surfaces(GRegion*);
  void modify_surfaces(MVertex*,MVertex*,MVertex*,MVertex*);

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

  bool faces_statuquo(Prism);
  bool faces_statuquo(MVertex*,MVertex*,MVertex*,MVertex*);

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
  int nbr,nbr8,nbr6,nbr5,nbr4,nbr4Trih;
  double vol,vol8,vol6,vol5,vol4;
  int estimate1;
  int estimate2;
  int iterations;
  std::map<MElement*,bool> markings;
  std::map<MVertex*,std::set<MElement*> > vertex_to_tetrahedra;
  std::map<MVertex*,std::set<MElement*> > vertex_to_pyramids;
  std::map<MVertex*,std::set<MElement*> > vertex_to_hexPrism;
  std::multiset<Tuple> tuples;
  std::set<MElement*> triangles;

public:
  PostOp();
  ~PostOp();

  void execute(int, int);
  //level - 0: hex, 1: hex+prisms, 2: hex+prism+pyramids
  //conformity - 0: nonconforming, 1: trihedra, 2: pyramids+trihedra, 3:pyramids+hexPrismSplit+trihedra, 4:hexPrismSplit+trihedra
  void execute(GRegion*,int level, int conformity);
  void executeNew(GRegion*);

  inline int get_nb_hexahedra()const{return nbr8;};
  inline double get_vol_hexahedra()const{return vol8;};
  inline int get_nb_elements()const{return nbr;};
  inline double get_vol_elements()const{return vol;};

  void init_markings(GRegion*);
  void init_markings_hex(GRegion*);
  void init_markings_pri(GRegion*);
  void init_markings_pyr(GRegion*);
  void pyramids1(GRegion*);
  void pyramids2(GRegion*, bool allowNonConforming=false);
  void trihedra(GRegion*);
  void split_hexahedra(GRegion*);
  void split_prisms(GRegion*);
  void split_pyramids(GRegion*);  
  int nonConformDiag(MVertex* a,MVertex* b,MVertex* c,MVertex* d,GRegion* gr);
  void pyramids1(MVertex*,MVertex*,MVertex*,MVertex*,GRegion*);
  void pyramids2(MVertex*,MVertex*,MVertex*,MVertex*,GRegion*, bool allowNonConforming);
  void trihedra(MVertex*,MVertex*,MVertex*,MVertex*,GRegion*);
  void rearrange(GRegion*);
  void statistics(GRegion*);
  void build_tuples(GRegion*);
  void modify_surfaces(GRegion*);
  void modify_surfaces(MVertex*,MVertex*,MVertex*,MVertex*);

  //returns the geometrical validity of the pyramid
  bool valid(MPyramid *pyr);
  
  bool four(MElement*);
  bool fourTrih(MElement*);
  bool five(MElement*);
  bool six(MElement*);
  bool eight(MElement*);

  bool equal(MVertex*,MVertex*,MVertex*,MVertex*);
  bool equal(MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*,MVertex*);
  bool different(MVertex*,MVertex*,MVertex*,MVertex*);
  MVertex* other(MElement*,MVertex*,MVertex*);
  MVertex* other(MElement*,MVertex*,MVertex*,MVertex*);
  void mean(const std::set<MVertex*>&,MVertex*,const std::vector<MElement*>&);
  double workaround(MElement*);

  MVertex* find(MVertex*,MVertex*,MVertex*,MVertex*,MElement*);
  MVertex* findInTriFace(MVertex* in0,MVertex* in1,MVertex* out0,MVertex* out1,MElement* element);
  void find_tetrahedra(MVertex*,MVertex*,std::set<MElement*>&);
  void find_tetrahedra(MVertex*,MVertex*,MVertex*,std::set<MElement*>&);
  void find_pyramids_from_tri(MVertex*,MVertex*,MVertex*,std::set<MElement*>&);
  void find_pyramids_from_quad(MVertex*,MVertex*,MVertex*,MVertex*,std::set<MElement*>&);
  void find_pyramids(MVertex*,MVertex*,std::set<MElement*>&);

  void intersection(const std::set<MElement*>&,const std::set<MElement*>&,std::set<MElement*>&);

  void build_vertex_to_tetrahedra(GRegion*);
  void build_vertex_to_tetrahedra(MElement*);
  void erase_vertex_to_tetrahedra(MElement*);

  void build_vertex_to_pyramids(GRegion*);
  void build_vertex_to_pyramids(MElement*);
  void erase_vertex_to_pyramids(MElement*);

  void build_vertex_to_hexPrism(GRegion*);
  void build_vertex_to_hexPrism(MElement*);
  void erase_vertex_to_hexPrism(MElement*);

  void removeElseAdd(std::set<Facet>&, MVertex*, MVertex*, MVertex*);
  void writeMSH(const char *filename, std::vector<MElement*>&);
  MFace find_quadFace(MVertex*, MVertex*, MVertex*);
  MVertex* otherVertexQuadFace(MFace&, MVertex*, MVertex*, MVertex*);
  void matchQuadFace(MFace&, MVertex*, MVertex*, MVertex*);
};

#endif

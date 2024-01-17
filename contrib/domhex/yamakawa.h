// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Tristan Carrier

#ifndef YAMAKAWA_H
#define YAMAKAWA_H

#include "GRegion.h"
#include "MVertex.h"
#include "MHexahedron.h"
#include "qualityMeasuresJacobian.h"
#include <set>
#include <map>
#include <iterator>

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>

using namespace std;

extern void export_gregion_mesh(GRegion *gr, const std::string &filename);

class Hex {
private:
  double quality;
  unsigned long long hash;
  std::vector<MVertex *> vertices_;

private:
  void set_hash()
  {
    hash = 0.;
    for(int i = 0; i < 8; ++i) { hash += vertices_[i]->getNum(); }
  }
  void compute_quality()
  {
    MHexahedron elt(vertices_);
    quality = jacobianBasedQuality::minIGEMeasure(&elt, false, true);
  }
  void initialize()
  {
    set_hash();
    compute_quality();
  }

public:
  Hex() : quality(0.), hash(0.) {}
  Hex(const std::vector<MVertex *> &vertices)
    : quality(0.), hash(0), vertices_(vertices)
  {
    initialize();
  }
  Hex(MVertex *a2, MVertex *b2, MVertex *c2, MVertex *d2, MVertex *e2,
      MVertex *f2, MVertex *g2, MVertex *h2)
    : quality(0.)
  {
    vertices_.push_back(a2);
    vertices_.push_back(b2);
    vertices_.push_back(c2);
    vertices_.push_back(d2);
    vertices_.push_back(e2);
    vertices_.push_back(f2);
    vertices_.push_back(g2);
    vertices_.push_back(h2);
    initialize();
  }
  ~Hex(){};
  double get_quality() const { return quality; }
  MVertex *getVertex(unsigned int i) const
  {
    if(i < 8) { return vertices_[i]; }
    else {
      cout << "Hex: unknown vertex number " << i << endl;
      throw;
      return NULL;
    }
  }
  const std::vector<MVertex *> &vertices() const { return vertices_; }
  MVertex *vertex_in_facet(unsigned int facet, unsigned int v_in_facet) const;
  bool hasVertex(MVertex *v) const
  {
    for(int i = 0; i < 8; i++) {
      if(getVertex(i) == v) { return true; }
    }
    return false;
  }
  bool same_vertices(Hex *h) const
  {
    for(int i = 0; i < 8; i++) {
      if(!(h->hasVertex(getVertex(i)))) { return false; }
    }
    return true;
  }
  int vertex_index(MVertex *v) const
  {
    for(unsigned int i = 0; i < 8; ++i) {
      if(vertices_[i] == v) { return i; }
    }
    return -1;
  }
  bool contains(MVertex *v) const { return vertex_index(v) != -1; }
  unsigned long long get_hash()
  {
    if(hash == 0. && vertices_[0] != NULL) { set_hash(); }
    return hash;
  }
  bool operator<(const Hex &hex) const
  {
    return quality >
           hex.get_quality(); // Why > ??? Shouldn't it be < ?? Jeanne.
  }
};

class Facet {
private:
  MVertex *a, *b, *c;
  int num[3];
  unsigned long long hash;

public:
  Facet() : a(NULL), b(NULL), c(NULL), hash(0.)
  {
    num[0] = -1;
    num[1] = -1;
    num[2] = -1;
  }
  Facet(MVertex *a2, MVertex *b2, MVertex *c2) : a(a2), b(b2), c(c2), hash(0.)
  {
    num[0] = -1;
    num[1] = -1;
    num[2] = -1;
    compute_hash();
  }
  ~Facet(){};
  MVertex *get_a() const { return a; }
  MVertex *get_b() const { return b; }
  MVertex *get_c() const { return c; }
  void set_vertices(MVertex *a2, MVertex *b2, MVertex *c2)
  {
    a = a2;
    b = b2;
    c = c2;
    compute_hash();
  }
  bool same_vertices(const Facet &facet) const
  {
    bool c1 =
      (a == facet.get_a()) || (a == facet.get_b()) || (a == facet.get_c());
    bool c2 =
      (b == facet.get_a()) || (b == facet.get_b()) || (b == facet.get_c());
    bool c3 =
      (c == facet.get_a()) || (c == facet.get_b()) || (c == facet.get_c());
    return c1 && c2 && c3;
  }
  void compute_hash()
  {
    num[0] = a->getNum();
    num[1] = b->getNum();
    num[2] = c->getNum();
    std::sort(num, num + 3);
    hash = num[2] + 1e4 * num[1] + 1e8 * num[0];
  }
  unsigned long long get_hash() const { return hash; }
  bool operator<(const Facet &rhs) const { return hash < rhs.get_hash(); }
};

class Diagonal {
private:
  MVertex *a, *b;
  unsigned long long hash;

private:
  void compute_hash() { hash = a->getNum() + b->getNum(); }

public:
  Diagonal() : a(NULL), b(NULL), hash(){};
  Diagonal(MVertex *a2, MVertex *b2) : a(a2), b(b2) { compute_hash(); }
  ~Diagonal(){};
  MVertex *get_a() const { return a; }
  MVertex *get_b() const { return b; }
  void set_vertices(MVertex *a2, MVertex *b2)
  {
    a = a2;
    b = b2;
    compute_hash();
  }
  bool same_vertices(const Diagonal &diagonal) const
  {
    bool c1 = (a == diagonal.get_a()) || (a == diagonal.get_b());
    bool c2 = (b == diagonal.get_a()) || (b == diagonal.get_b());
    return c1 && c2;
  }
  unsigned long long get_hash() const { return hash; }
  bool operator<(const Diagonal &rhs) const { return hash < rhs.get_hash(); }
};

class Tuple {
private:
  MVertex *vertex1, *vertex2, *vertex3;
  MElement *element;
  GFace *gf;
  unsigned long long hash;

public:
  Tuple()
    : vertex1(NULL), vertex2(NULL), vertex3(NULL), element(NULL), gf(NULL),
      hash(0)
  {
  }

  Tuple(MVertex *const a, MVertex *const b, MVertex *const c,
        MElement *const element2, GFace *const gf2)
    : vertex1(NULL), vertex2(NULL), vertex3(NULL), element(element2), gf(gf2),
      hash(a->getNum() + b->getNum() + c->getNum())
  {
    MVertex *tmp[3] = {a, b, c};
    std::sort(tmp, tmp + 3);
    vertex1 = tmp[0];
    vertex2 = tmp[1];
    vertex2 = tmp[2];
  }

  Tuple(MVertex *const a, MVertex *const b, MVertex *const c)
    : vertex1(NULL), vertex2(NULL), vertex3(NULL), element(NULL), gf(NULL),
      hash(a->getNum() + b->getNum() + c->getNum())
  {
    MVertex *tmp[3] = {a, b, c};
    std::sort(tmp, tmp + 3);
    vertex1 = tmp[0];
    vertex2 = tmp[1];
    vertex2 = tmp[2];
  }

  ~Tuple() {}

  MVertex *get_v1() const { return vertex1; }
  MVertex *get_v2() const { return vertex2; }
  MVertex *get_v3() const { return vertex3; }

  MElement *get_element() const { return element; }

  GFace *get_gf() const { return gf; }

  bool same_vertices(const Tuple &rhs) const
  {
    return (vertex1 == rhs.get_v1() && vertex2 == rhs.get_v2() &&
            vertex3 == rhs.get_v3());
  }
  unsigned long long get_hash() const { return hash; }

  bool operator<(const Tuple &rhs) const { return hash < rhs.get_hash(); }
};

// Class in charge of answering connectivity requests on the input tetraedral
// mesh
class TetMeshConnectivity {
public:
  typedef std::set<MVertex *> VertexSet;
  typedef std::set<MElement *> TetSet;
  TetMeshConnectivity(){};
  ~TetMeshConnectivity(){};
  void initialize(GRegion *region)
  {
    Msg::Info("Initialize Connectivity Information...");
    clear();
    initialize_vertex_to_vertices(region);
    initialize_vertex_to_elements(region);
  }
  void clear()
  {
    vertex_to_vertices_.clear();
    vertex_to_elements_.clear();
  }
  VertexSet &vertices_around_vertex(MVertex *v)
  {
    return vertex_to_vertices_[v];
  }
  TetSet &tets_around_vertex(MVertex *v) { return vertex_to_elements_[v]; }
  bool are_vertex_neighbors(MVertex *v0, MVertex *v1)
  {
    return vertices_around_vertex(v0).count(v1) > 0;
  }
  void vertices_around_vertices(MVertex *v0, MVertex *v1, VertexSet &result)
  {
    const VertexSet &neighbors0 = vertices_around_vertex(v0);
    const VertexSet &neighbors1 = vertices_around_vertex(v1);
    std::set_intersection(neighbors0.begin(), neighbors0.end(),
                          neighbors1.begin(), neighbors1.end(),
                          std::inserter(result, result.end()));
  }
  void vertices_around_vertices(MVertex *v0, MVertex *v1, MVertex *v2,
                                VertexSet &result)
  {
    VertexSet tmp;
    vertices_around_vertices(v0, v1, tmp);
    const VertexSet &neighbors2 = vertices_around_vertex(v2);
    std::set_intersection(neighbors2.begin(), neighbors2.end(), tmp.begin(),
                          tmp.end(), std::inserter(result, result.end()));
  }
  void tets_around_vertices(MVertex *v0, MVertex *v1, TetSet &result)
  {
    const TetSet &elements0 = tets_around_vertex(v0);
    const TetSet &elements1 = tets_around_vertex(v1);
    std::set_intersection(elements0.begin(), elements0.end(), elements1.begin(),
                          elements1.end(), std::inserter(result, result.end()));
  }
  void tets_around_vertices(MVertex *v0, MVertex *v1, MVertex *v2,
                            TetSet &result)
  {
    TetSet tmp;
    tets_around_vertices(v0, v1, tmp);
    const TetSet &elements2 = tets_around_vertex(v2);
    std::set_intersection(tmp.begin(), tmp.end(), elements2.begin(),
                          elements2.end(), std::inserter(result, result.end()));
  }

private:
  // TODO Change this costly  implementation
  // Replace maps by vectors and store adjacent vertices whose
  // index is bigger
  void initialize_vertex_to_vertices(GRegion *region)
  {
    int nbtets = region->getNumMeshElements();
    for(int i = 0; i < nbtets; i++) {
      MElement *tet = region->getMeshElement(i);
      for(int j = 0; j < 4; j++) {
        MVertex *a = tet->getVertex(j);
        MVertex *b = tet->getVertex((j + 1) % 4);
        MVertex *c = tet->getVertex((j + 2) % 4);
        MVertex *d = tet->getVertex((j + 3) % 4);
        std::map<MVertex *, std::set<MVertex *> >::iterator it =
          vertex_to_vertices_.find(a);
        if(it != vertex_to_vertices_.end()) {
          it->second.insert(b);
          it->second.insert(c);
          it->second.insert(d);
        }
        else {
          std::set<MVertex *> bin;
          bin.insert(b);
          bin.insert(c);
          bin.insert(d);
          vertex_to_vertices_.insert(
            std::pair<MVertex *, std::set<MVertex *> >(a, bin));
        }
      }
    }
  }
  void initialize_vertex_to_elements(GRegion *region)
  {
    int nbtets = region->getNumMeshElements();

    for(int i = 0; i < nbtets; i++) {
      MElement *tet = region->getMeshElement(i);
      for(unsigned int j = 0; j < 4; j++) {
        MVertex *getVertex = tet->getVertex(j);
        std::map<MVertex *, std::set<MElement *> >::iterator it =
          vertex_to_elements_.find(getVertex);
        if(it != vertex_to_elements_.end()) { it->second.insert(tet); }
        else {
          std::set<MElement *> bin;
          bin.insert(tet);
          vertex_to_elements_.insert(
            std::pair<MVertex *, std::set<MElement *> >(getVertex, bin));
        }
      }
    }
  }

private:
  std::map<MVertex *, std::set<MVertex *> > vertex_to_vertices_;
  std::map<MVertex *, std::set<MElement *> > vertex_to_elements_;
};

class Recombinator {
public:
  typedef std::set<MVertex *>::iterator vertex_set_itr;
  typedef std::set<MElement *>::iterator element_set_itr;

  typedef std::map<MVertex *, std::set<MVertex *> > Vertex2Vertices;
  typedef std::map<MVertex *, std::set<MElement *> > Vertex2Elements;

  Recombinator() : current_region(NULL), hex_threshold_quality(0.6){};
  virtual ~Recombinator();

  virtual void execute();
  virtual void execute(GRegion *);

protected:
  // ---- Initialization of the structures
  virtual void initialize_structures(GRegion *region)
  {
    set_current_region(region);
    tet_mesh.initialize(current_region);
    build_tuples();
    init_markings();
    // What happens when the mesh of the region is not only constituted of tets?
    // JP
  }
  void init_markings();
  void build_tuples();
  void set_current_region(GRegion *region) { current_region = region; }

  // ---- Create the final mesh -------
  virtual void merge();
  virtual void merge(GRegion *) {}

  void delete_marked_tets_in_region() const;
  // Check if the hex is valid and compatible with the
  // previously built hexes and add it to the region
  bool add_hex_to_region_if_valid(const Hex &hex);

  // ---- Computation of potential hexes
  virtual void clear_potential_hex_info() { potential.clear(); }
  void compute_potential_hexes()
  {
    clear_potential_hex_info();
    pattern1();
    pattern2();
    pattern3();
    Msg::Info("Number of potential hexes %d", potential.size());
  }
  void pattern1();
  void pattern2();
  void pattern3();
  virtual void add_or_free_potential_hex(Hex *candidate);

  // ----- Helpers to debug -------
  void print_all_potential_hex() const;
  void print_hash_tableA();
  void print_segment(const SPoint3 &, const SPoint3 &, std::ofstream &);

  // -----  Conformity stuff -------
  bool is_potential_hex_conform(const Hex &hex);
  bool conformityA(const Hex &);
  bool conformityB(const Hex &);
  bool conformityC(const Hex &);

  bool faces_statuquo(const Hex &);
  bool faces_statuquo(MVertex *, MVertex *, MVertex *, MVertex *);

  bool are_all_tets_free(const std::set<MElement *> &tets) const;

  void mark_tets(const std::set<MElement *> &tets);
  void clear_hash_tables()
  {
    hash_tableA.clear();
    hash_tableB.clear();
    hash_tableC.clear();
  }
  void build_hash_tableA(const Hex &hex);
  void build_hash_tableB(const Hex &hex);
  void build_hash_tableC(const Hex &hex);

  // -----  Post-processing -------
  void improve_final_mesh()
  {
    set_region_elements_positive();
    create_quads_on_boundary();
  }
  // Reverse of of built elements with a negative volume
  void set_region_elements_positive();
  void create_quads_on_boundary();
  void create_quads_on_boundary(MVertex *, MVertex *, MVertex *, MVertex *);
  void delete_quad_triangles_in_boundary() const;

  // ---- Functions that should not be part of the class
  double scaled_jacobian(MVertex *, MVertex *, MVertex *, MVertex *);
  double max_scaled_jacobian(MElement *, int &);
  double min_scaled_jacobian(Hex &);
  void print_statistics();

protected:
  // Object in charge of answering connectivity request
  // in the initial region tetrahedral mesh
  TetMeshConnectivity tet_mesh;

  GRegion *current_region;
  double hex_threshold_quality;

  std::vector<Hex *> potential;
  std::map<MElement *, bool> markings;
  // Already chosen facet triangles (4 per hex facet)
  std::multiset<Facet> hash_tableA;
  // Already chosen hex facet diagonals
  std::multiset<Diagonal> hash_tableB;
  // Already chosen hex edges
  std::multiset<Diagonal> hash_tableC;

  std::multiset<Tuple> tuples;
  std::set<MElement *> triangles;
};

class PEEntity {
protected:
  vector<MVertex *> vertices;
  size_t hash;
  void compute_hash();

public:
  PEEntity(const vector<MVertex *> &_v);
  virtual ~PEEntity();
  virtual size_t get_max_nb_vertices() const = 0;
  MVertex *getVertex(size_t n) const;
  bool hasVertex(MVertex *v) const;
  size_t get_hash() const;
  bool same_vertices(const PEEntity *t) const;
  bool operator<(const PEEntity &) const;
};

class PELine : public PEEntity {
public:
  PELine(const vector<MVertex *> &_v);
  virtual ~PELine();
  size_t get_max_nb_vertices() const;
};

class PETriangle : public PEEntity {
public:
  PETriangle(const vector<MVertex *> &_v);
  // PETriangle(size_t l);
  virtual ~PETriangle();
  size_t get_max_nb_vertices() const;
};

class PEQuadrangle : public PEEntity {
public:
  PEQuadrangle(const vector<MVertex *> &_v);
  // PEQuadrangle(size_t l);
  virtual ~PEQuadrangle();
  size_t get_max_nb_vertices() const;
};

// Why are the following classes templates???
// Used with only with Hex*, implemented in the cpp file (bad idea) and does not
// seem robust. JP.

// Very very complicated way to answer one question
// Do we have all the tets of the input mesh for a given combination of hex?
// Slivers are tricky since they can be in shared by 2 hex.
template <class T> class clique_stop_criteria {
public:
  typedef std::set<T> graph_data_no_hash;
  clique_stop_criteria(map<T, std::set<MElement *> > &_m, int _i);
  ~clique_stop_criteria();
  bool stop(const graph_data_no_hash &clique) const;
  void export_corresponding_mesh(const graph_data_no_hash &clique) const;

private:
  const map<T, std::set<MElement *> > &hex_to_tet;
  const unsigned int total_number_tet;
};

// Why is this class template?
// This complicates everything and is useless as the class
// cannot be used outside the .cpp file where it is implemented.
// TODO - Rewrite this without multimaps or unnecessary abstractions.
template <class T> class cliques_compatibility_graph {
public:
  typedef unsigned long long hash_key;
  typedef std::set<T> graph_data_no_hash;
  typedef std::multimap<hash_key, T> graph_data;
  typedef std::multimap<hash_key, pair<T, graph_data> > graph;
  typedef std::map<int, T> ranking_data;

  typedef void (*ptrfunction_export)(cliques_compatibility_graph<T> &, int,
                                     const std::string &);

  cliques_compatibility_graph(graph &_g,
                              const map<T, std::vector<double> > &_hex_ranks,
                              unsigned int _max_nb_cliques,
                              unsigned int _nb_hex_potentiels,
                              clique_stop_criteria<T> *csc,
                              ptrfunction_export fct);
  virtual ~cliques_compatibility_graph();
  void find_cliques();
  void export_cliques();

  virtual typename graph::const_iterator begin_graph() { return G.begin(); };
  virtual typename graph::const_iterator end_graph() { return G.end(); };

public:
  bool found_the_ultimate_max_clique;
  // The stored maximal cliques.
  // The maximum number of stored cliques can be limited with the
  // max_nb_of_stored_cliques attribute
  // Cliques are ordered by size (number of nodes in the clique)
  multimap<int, set<T> > allQ;

protected:
  void erase_entry(graph_data &subgraph, T &u, hash_key &key);
  void find_cliques(graph_data &subgraph, int n);
  void split_set_BW(const T &u, const hash_key &u_key,
                    const graph_data &subgraph, graph_data &white,
                    graph_data &black);
  void fill_black_set(const T &u, const hash_key &u_key,
                      const graph_data &subgraph, graph_data &black);
  void choose_u(const graph_data &subgraph, T &u, hash_key &u_key);
  double function_to_maximize_for_u(const T &u, const hash_key &u_key,
                                    const graph_data &subgraph);
  void store_clique(int n);
  // Returns true if two nodes are connected in the graph
  virtual bool compatibility(const T &u, const hash_key &u_key, const T &v,
                             const hash_key &v_key);

  ptrfunction_export export_clique_graph;

protected:
  const bool debug;
  unsigned int max_nb_cliques;
  unsigned int nb_hex_potentiels;
  unsigned int max_clique_size;
  unsigned int position;
  unsigned int total_nodes_number;
  unsigned int total_nb_of_cliques_searched;
  unsigned int max_nb_of_stored_cliques; // to reduce memory footprint (set to
                                         // zero if no limit)
  clique_stop_criteria<T> *criteria;
  bool cancel_search;
  // Not used in anyway
  const map<T, std::vector<double> > &hex_ranks;
  graph &G;
  graph_data_no_hash Q; // the current clique
};

// Non necessary derivation
template <class T>
class cliques_losses_graph : public cliques_compatibility_graph<T> {
public:
  typedef unsigned long long hash_key;
  typedef multimap<hash_key, T> graph_data;
  typedef multimap<hash_key, pair<T, graph_data> > graph;
  typedef void (*ptrfunction_export)(cliques_compatibility_graph<T> &, int,
                                     const std::string &);

  cliques_losses_graph(graph &_g,
                       const map<T, std::vector<double> > &_hex_ranks,
                       unsigned int _max_nb_cliques,
                       unsigned int _nb_hex_potentiels,
                       clique_stop_criteria<T> *csc, ptrfunction_export fct);
  virtual ~cliques_losses_graph();

protected:
  // Returns true if the two nodes are compatible
  // (connected in compatiblity graph - not connected in losses graph)
  virtual bool compatibility(const T &u, const hash_key &u_key, const T &v,
                             const hash_key &v_key);
};

class Recombinator_Graph : public Recombinator {
public:
  typedef size_t my_hash_key;
  typedef multimap<my_hash_key, PETriangle *> trimap;
  typedef map<PETriangle *, PETriangle *> tripair;
  typedef multimap<my_hash_key, PELine *> linemap;

  // typedef tr1::unordered_multimap<my_hash_key,PETriangle*> trimap;
  typedef trimap::iterator iter;
  typedef trimap::const_iterator citer;

  typedef unsigned long long hash_key;

  typedef multimap<hash_key, Hex *> graph_data;
  typedef multimap<hash_key, pair<Hex *, graph_data> > graph;

protected:
  bool debug;
  bool debug_graph;

  int max_nb_cliques;
  string graphfilename;

  // Topological information to navigate in the input tet mesh
  // to navigate between the potential hexes and the input tet mesh
  std::map<Hex *, std::set<MElement *> > hex_to_tet;
  std::map<MElement *, std::set<Hex *> > tet_to_hex;
  std::map<Hex *, std::set<PELine *> > hex_to_edges;
  std::map<PELine *, std::set<Hex *> > edges_to_hex;
  std::map<Hex *, std::set<PETriangle *> > hex_to_faces;
  std::map<PETriangle *, std::set<Hex *> > faces_to_hex;
  // Number of tets containing a tet - Is the facet on the boundary (1 tet) or
  // not (2 tets)?
  std::map<PETriangle *, unsigned int> faces_connectivity;

  std::map<Hex *, std::vector<double> > hex_ranks;

  graph incompatibility_graph;
  std::set<Hex *> set_of_all_hex_in_graph;

  std::multimap<unsigned long long, Hex *> created_potential_hex;

  std::multimap<double, Hex *>
    degree; // degree = the final ranking of hexahedra
  std::multimap<int, Hex *>
    idegree; // idegree = number of connected hex in indirect neighbors graph
  std::multimap<int, Hex *>
    ndegree; // ndegree = number of direct neighbors !!! not chosen yet !!!
  std::map<Hex *, int> reverse_idegree;
  std::map<Hex *, int> reverse_ndegree;
  // each tet has at least one neighbor, at most four. For all not chosen hex,
  // check this data to find how many direct neighbors...
  //    std::map<MElement*,set<PETriangle*> > tet_to_triangle;
  std::map<PETriangle *, set<MElement *> > triangle_to_tet;
  std::map<MElement *, int> tet_degree;

  tripair blossom_info;
  trimap triangular_faces;
  linemap edges_and_diagonals;

  map<PETriangle *, GFace *> tri_to_gface_info;

  vector<Hex *> chosen_hex;
  vector<MElement *> chosen_tet;
  bool post_check_validation(Hex *current_hex);

protected:
  void create_faces_connectivity();
  void add_face_connectivity(MElement *tet, int i, int j, int k);

  void add_edges(Hex *hex);
  void fill_edges_table(const std::vector<MVertex *> &, Hex *hex);
  void add_face(MVertex *a, MVertex *b, MVertex *c, Hex *hex);
  void add_face(MVertex *a, MVertex *b, MVertex *c,
                std::multimap<unsigned long long, pair<PETriangle *, int> > &f);

  // All the blossom related stuff is out of date - or not working
  // Cannot be called. To remove?
  bool find_face_in_blossom_info(MVertex *a, MVertex *b, MVertex *c,
                                 MVertex *d);
  void compute_hex_ranks_blossom();
  PETriangle *get_triangle(MVertex *a, MVertex *b, MVertex *c);
  bool is_blossom_pair(PETriangle *t1, PETriangle *t2);

  citer find_the_triangle(PETriangle *t, const trimap &list);
  linemap::const_iterator find_the_line(PELine *t, const linemap &list);
  std::multimap<unsigned long long, pair<PETriangle *, int> >::iterator
  find_the_triangle(
    PETriangle *t,
    std::multimap<unsigned long long, pair<PETriangle *, int> > &list);
  std::multimap<unsigned long long, Hex *>::const_iterator
  find_the_created_potential_hex(
    Hex *t, const std::multimap<unsigned long long, Hex *> &list);

  PETriangle *get_triangle(MElement *element, int i, int j, int k);

  void compute_hex_ranks();

  // check if the hex is good enough to be put into the graph. If not in the
  // graph, it cannot be chosen...
  bool is_not_good_enough(Hex *hex);

  // fills incompatibility_graph if two hex share a common (non-sliver!) tet
  void create_indirect_neighbors_graph();

  graph::iterator find_hex_in_graph(Hex *hex);
  graph_data::iterator find_hex_in_graphrow(Hex *hex, graph_data &row);
  bool find_hex_couple_in_graph(Hex *hex, Hex *other_hex);
  void add_graph_entry(Hex *hex, Hex *other_hex);

  // fills incompatibility_graph if two hex are incompatible direct neighbors,
  // i.e. they have one (or more) common face or common edge and are not
  // compatible
  void create_direct_neighbors_incompatibility_graph();
  void evaluate_hex_couple(Hex *hex, Hex *other_hex);

  // if two hex are not connected in the incompatibility_graph, they are
  // compatible
  void create_losses_graph(GRegion *gr);

  void merge_clique(GRegion *gr, cliques_losses_graph<Hex *> &cl,
                    int clique_number = 0);

  /*
   * Tries to merge tetrahedra into one hexahedron. Returns false if the hex
   * that would be created does not pass some conformity checks.
   */
  bool merge_hex(GRegion *gr, Hex *hex);

  void fill_tet_to_hex_table(Hex *hex);

  // Reimplementation
  virtual void add_or_free_potential_hex(Hex *candidate)
  {
    fill_tet_to_hex_table(candidate);
  }

  virtual void clear_potential_hex_info()
  {
    hex_to_tet.clear();
    tet_to_hex.clear();
    created_potential_hex.clear();
  }
  virtual void initialize_structures(GRegion *region)
  {
    set_current_region(region);
    tet_mesh.initialize(current_region);
    build_tuples();
  }

  void clear_and_build_hash_tables(const Hex &hex)
  {
    hash_tableA.clear();
    hash_tableB.clear();
    hash_tableC.clear();
    build_hash_tableA(hex);
    build_hash_tableB(hex);
    build_hash_tableC(hex);
  }

  // Throw an assertion
  using Recombinator::merge;
  void merge(GRegion *);

  // ------- exports --------
  // ---- seems that it won't export nothing since the
  // ---- data structures from which info is read seem to never be filled
  void export_tets(set<MElement *> &tetset, Hex *hex, const string &s);
  void export_single_hex_all(Hex *hex, const string &s);
  void export_single_hex(Hex *hex, const string &s);
  void export_single_hex_faces(Hex *hex, const string &s);
  void export_single_hex_tet(Hex *hex, const string &s);
  void export_all_hex(int &file, GRegion *gr);
  void export_hexmesh_so_far(int &file);
  void export_direct_neighbor_table(int max);
  void export_hex_init_degree(GRegion *gr,
                              const std::map<Hex *, int> &init_degree,
                              const vector<Hex *> &chosen_hex);

public:
  Recombinator_Graph(unsigned int max_nb_cliques,
                     const string &filename = string());
  virtual ~Recombinator_Graph();
  using Recombinator::execute;
  virtual void execute(GRegion *);

  virtual void buildGraphOnly(unsigned int max_nb_cliques,
                              string filename = string());
  virtual void buildGraphOnly(GRegion *, unsigned int max_nb_cliques,
                              string filename = string());
  virtual void execute_blossom(unsigned int max_nb_cliques,
                               const std::string &filename = string());
  // What is this function supposed to do?
  // Right now it throws at the first line. JP
  virtual void execute_blossom(GRegion *, unsigned int max_nb_cliques,
                               const std::string &filename = "mygraph.dot");
  virtual void createBlossomInfo();
  void createBlossomInfo(GRegion *gr);

  const std::set<Hex *> &getHexInGraph() const
  {
    return set_of_all_hex_in_graph;
  };
  bool found_the_ultimate_max_clique;
};

class Prism {
private:
  double quality;
  MVertex *a, *b, *c, *d, *e, *f;

public:
  typedef std::set<MVertex *>::iterator vertex_set_itr;
  typedef std::set<MElement *>::iterator element_set_itr;

  Prism();
  Prism(MVertex *, MVertex *, MVertex *, MVertex *, MVertex *, MVertex *);
  ~Prism();
  double get_quality() const;
  void set_quality(double);
  MVertex *get_a();
  MVertex *get_b();
  MVertex *get_c();
  MVertex *get_d();
  MVertex *get_e();
  MVertex *get_f();
  void set_vertices(MVertex *, MVertex *, MVertex *, MVertex *, MVertex *,
                    MVertex *);
  bool operator<(const Prism &) const;
};

// Une ENORME partie de ce code est du copie-colle depuis Recombinator
class Supplementary {
private:
  std::vector<Prism> potential;
  std::map<MElement *, bool> markings;
  std::map<MVertex *, std::set<MVertex *> > vertex_to_vertices;
  std::map<MVertex *, std::set<MElement *> > vertex_to_tetrahedra;
  std::multiset<Facet> hash_tableA;
  std::multiset<Diagonal> hash_tableB;
  std::multiset<Diagonal> hash_tableC;
  std::multiset<Tuple> tuples;
  std::set<MElement *> triangles;
  // std::fstream file; //fordebug

public:
  typedef std::set<MVertex *>::iterator vertex_set_itr;
  typedef std::set<MElement *>::iterator element_set_itr;

  typedef std::map<MVertex *, std::set<MVertex *> > Vertex2Vertices;
  typedef std::map<MVertex *, std::set<MElement *> > Vertex2Elements;

  Supplementary();
  ~Supplementary();

  void execute();
  void execute(GRegion *);

  void init_markings(GRegion *);
  void pattern(GRegion *);
  void merge(GRegion *);
  void rearrange(GRegion *);
  void statistics(GRegion *);
  void build_tuples(GRegion *);
  void create_quads_on_boundary(GRegion *);
  void create_quads_on_boundary(MVertex *, MVertex *, MVertex *, MVertex *);

  bool four(MElement *);
  bool five(MElement *);
  bool six(MElement *);
  bool eight(MElement *);

  bool sliver(MElement *, Prism);
  bool valid(Prism, const std::set<MElement *> &);
  bool valid(Prism);
  double eta(MVertex *, MVertex *, MVertex *, MVertex *);
  bool linked(MVertex *, MVertex *);

  void find(MVertex *, MVertex *, const std::vector<MVertex *> &,
            std::set<MVertex *> &);
  void find(MVertex *, const Prism &, std::set<MElement *> &);

  void intersection(const std::set<MVertex *> &, const std::set<MVertex *> &,
                    const std::vector<MVertex *> &, std::set<MVertex *> &);

  bool inclusion(MVertex *, Prism);
  bool inclusion(MVertex *, MVertex *, MVertex *, MVertex *, MVertex *);
  bool inclusion(MVertex *, MVertex *, MVertex *, const std::set<MElement *> &);
  bool inclusion(const Facet &);
  bool inclusion(const Diagonal &);
  bool duplicate(const Diagonal &);

  bool conformityA(Prism);
  bool conformityA(MVertex *, MVertex *, MVertex *, MVertex *);
  bool conformityB(Prism);
  bool conformityC(Prism);

  bool faces_statuquo(Prism);
  bool faces_statuquo(MVertex *, MVertex *, MVertex *, MVertex *);

  void build_vertex_to_vertices(GRegion *);
  void build_vertex_to_tetrahedra(GRegion *);

  void build_hash_tableA(Prism);
  void build_hash_tableA(MVertex *, MVertex *, MVertex *, MVertex *);
  void build_hash_tableA(const Facet &);
  void build_hash_tableB(Prism);
  void build_hash_tableB(MVertex *, MVertex *, MVertex *, MVertex *);
  void build_hash_tableB(const Diagonal &);
  void build_hash_tableC(Prism);
  void build_hash_tableC(const Diagonal &);

  double scaled_jacobian(MVertex *, MVertex *, MVertex *, MVertex *);
  double min_scaled_jacobian(Prism);
};

class PostOp {
private:
  int nbr, nbr8, nbr6, nbr5, nbr4, nbr4Trih;
  double vol, vol8, vol6, vol5, vol4;
  int estimate1;
  int estimate2;
  int iterations;
  std::map<MElement *, bool> markings;
  std::map<MVertex *, std::set<MElement *> > vertex_to_tetrahedra;
  std::map<MVertex *, std::set<MElement *> > vertex_to_pyramids;
  std::map<MVertex *, std::set<MElement *> > vertex_to_hexPrism;
  std::multiset<Tuple> tuples;
  std::set<MElement *> triangles;

public:
  typedef std::set<MVertex *>::iterator vertex_set_itr;
  typedef std::set<MElement *>::iterator element_set_itr;

  typedef std::map<MVertex *, std::set<MVertex *> > Vertex2Vertices;
  typedef std::map<MVertex *, std::set<MElement *> > Vertex2Elements;

  PostOp();
  ~PostOp();

  void execute(int, int);
  // level - 0: hex, 1: hex+prisms, 2: hex+prism+pyramids
  // conformity - 0: nonconforming, 1: trihedra, 2: pyramids+trihedra,
  // 3:pyramids+hexPrismSplit+trihedra, 4:hexPrismSplit+trihedra
  void execute(GRegion *, int level, int conformity);
  void executeNew(GRegion *);

  inline int get_nb_hexahedra() const { return nbr8; };
  inline double get_vol_hexahedra() const { return vol8; };
  inline int get_nb_elements() const { return nbr; };
  inline double get_vol_elements() const { return vol; };

  void init_markings(GRegion *);
  void init_markings_hex(GRegion *);
  void init_markings_pri(GRegion *);
  void init_markings_pyr(GRegion *);
  void pyramids1(GRegion *);
  void pyramids2(GRegion *, bool allowNonConforming = false);
  void trihedra(GRegion *);
  void split_hexahedra(GRegion *);
  void split_prisms(GRegion *);
  void split_pyramids(GRegion *);
  int nonConformDiag(MVertex *a, MVertex *b, MVertex *c, MVertex *d,
                     GRegion *gr);
  void pyramids1(MVertex *, MVertex *, MVertex *, MVertex *, GRegion *);
  void pyramids2(MVertex *, MVertex *, MVertex *, MVertex *, GRegion *,
                 bool allowNonConforming);
  void trihedra(MVertex *, MVertex *, MVertex *, MVertex *, GRegion *);
  void rearrange(GRegion *);
  void statistics(GRegion *);
  void build_tuples(GRegion *);
  void create_quads_on_boundary(GRegion *);
  void create_quads_on_boundary(MVertex *, MVertex *, MVertex *, MVertex *);

  // returns the geometrical validity of the pyramid
  bool valid(MPyramid *pyr);

  bool four(MElement *);
  bool fourTrih(MElement *);
  bool five(MElement *);
  bool six(MElement *);
  bool eight(MElement *);

  bool equal(MVertex *, MVertex *, MVertex *, MVertex *);
  bool equal(MVertex *, MVertex *, MVertex *, MVertex *, MVertex *, MVertex *,
             MVertex *, MVertex *);
  bool different(MVertex *, MVertex *, MVertex *, MVertex *);
  MVertex *other(MElement *, MVertex *, MVertex *);
  MVertex *other(MElement *, MVertex *, MVertex *, MVertex *);
  void mean(const std::set<MVertex *> &, MVertex *,
            const std::vector<MElement *> &);
  double workaround(MElement *);

  MVertex *find(MVertex *, MVertex *, MVertex *, MVertex *, MElement *);
  MVertex *findInTriFace(MVertex *in0, MVertex *in1, MVertex *out0,
                         MVertex *out1, MElement *element);
  void find_tetrahedra(MVertex *, MVertex *, std::set<MElement *> &);
  void find_tetrahedra(MVertex *, MVertex *, MVertex *, std::set<MElement *> &);
  void find_pyramids_from_tri(MVertex *, MVertex *, MVertex *,
                              std::set<MElement *> &);
  void find_pyramids_from_quad(MVertex *, MVertex *, MVertex *, MVertex *,
                               std::set<MElement *> &);
  void find_pyramids(MVertex *, MVertex *, std::set<MElement *> &);

  void intersection(const std::set<MElement *> &, const std::set<MElement *> &,
                    std::set<MElement *> &);

  void build_vertex_to_tetrahedra(GRegion *);
  void build_vertex_to_tetrahedra(MElement *);
  void erase_vertex_to_tetrahedra(MElement *);

  void build_vertex_to_pyramids(GRegion *);
  void build_vertex_to_pyramids(MElement *);
  void erase_vertex_to_pyramids(MElement *);

  void build_vertex_to_hexPrism(GRegion *);
  void build_vertex_to_hexPrism(MElement *);
  void erase_vertex_to_hexPrism(MElement *);

  void removeElseAdd(std::set<Facet> &, MVertex *, MVertex *, MVertex *);
  void writeMSH(const char *filename, std::vector<MElement *> &);
  MFace find_quadFace(MVertex *, MVertex *, MVertex *);
  MVertex *otherVertexQuadFace(MFace &, MVertex *, MVertex *, MVertex *);
  void matchQuadFace(MFace &, MVertex *, MVertex *, MVertex *);
};

#endif

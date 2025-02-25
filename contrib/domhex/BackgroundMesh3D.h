// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BACKGROUND_MESH3D_H
#define BACKGROUND_MESH3D_H

#include <set>
#include <vector>
#include <map>
#include <numeric>
#include "BGMBase.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
class ANNkd_tree;
#endif

// TODO: do we really need to build the graph vertex2elem-> vertex 2 neighbors ?
// This was useful for the smoothness computation, if we want to take into
// account vertices at a given topological distance... but using distance=1, it
// seems to work... ?!

class montripletbis {
public:
  ~montripletbis(){};
  montripletbis(int a, int b, int c) : vec(3)
  {
    vec[0] = a;
    vec[1] = b;
    vec[2] = c;
  };
  inline int operator()(int i) const { return vec[i]; }

private:
  std::vector<int> vec;
};

// difference with BackgroundMesh2D: no copy of components, working directly on
// the vertices and elements of GVolume

class backgroundMesh3D : public BGMBase {
protected:
  virtual void computeSizeField();
  virtual void propagateValues(DoubleStorageType &dirichlet,
                               simpleFunction<double> &eval_diffusivity,
                               bool in_parametric_plane = false);
  virtual GVertex get_GPoint_from_MVertex(const MNode *) const;

  virtual const MElement *getElement(unsigned int i) const;
  virtual unsigned int getNumMeshElements() const;

  const bool debug;
  const bool verbose;

public:
  backgroundMesh3D(GVolume *_gr);
  virtual ~backgroundMesh3D();

  virtual MElementOctree *getOctree();

  virtual MNode *get_nearest_neighbor(const double *xyz, double &distance);
  virtual MNode *get_nearest_neighbor(const double *xyz);
  virtual MNode *get_nearest_neighbor(const MNode *v);
  virtual MNode *get_nearest_neighbor(double x, double y, double z);
  virtual MNode *get_nearest_neighbor(double x, double y, double z,
                                        double &distance);
};

class frameFieldBackgroundMesh3D : public backgroundMesh3D {
public:
  //    typedef tr1::unordered_map<hash_key_ptr, std::set<MElement*> >
  //    vert2elemtype; typedef tr1::unordered_map<MElement*, std::set<MNode*>
  //    > elem2verttype;
  typedef std::map<hash_key_ptr, std::set<MElement *> > vert2elemtype;
  typedef std::map<MElement *, std::set<MNode *> > elem2verttype;
  typedef std::multimap<MNode const *const, std::pair<int, MNode const *> >
    graphtype;

protected:
  bool smooth_the_crossfield;

  void initiate_crossfield();
  void initiate_ANN_research();
  void computeCrossField();
  void computeSmoothnessOnlyFromBoundaries();

  void build_vertex_to_element_table();

  // fills the multimap "graph": vertex to direct neighbors, or indirect
  // neighbors, depending on the "max_recursion_level".
  void build_neighbors(const int &max_recursion_level);

  // function called only by "build_neighbors", recursively recovering vertices
  // neighbors.
  void get_recursive_neighbors(std::set<MNode const *> &start,
                               std::set<MNode const *> &visited,
                               std::set<MElement const *> &visited_elements,
                               std::multimap<int, MNode const *> &proximity,
                               int max_level, int level = 0);

  double
  compare_to_neighbors(const SPoint3 &current, STensor3 &ref,
                       std::multimap<double, MNode const *>::iterator itbegin,
                       std::multimap<double, MNode const *>::iterator itend,
                       SVector3 &mean_axis, double &mean_angle,
                       std::vector<double> &vectorial_smoothness);

  STensor3 apply_rotation(const SVector3 &axis, const double &angle,
                          const STensor3 &thecross);
  void get_rotation_matrix(const double &angle_to_go, const SVector3 &rotvec,
                           double *rotmat);
  void get_min_rotation_matrix(const STensor3 &reference,
                               const STensor3 &thecross, double &minimum_angle,
                               SVector3 &rotation_axis, double threshold = -1.,
                               bool debugflag = false);
  void get_rotation_angle_and_axis(const STensor3 &reference,
                                   const STensor3 &thecross,
                                   double &minimum_angle,
                                   SVector3 &rotation_axis, int modulo,
                                   montripletbis &trip);

  TensorStorageType crossField;
  DoubleStorageType crossFieldSmoothness;
  VectorStorageType crossFieldVectorialSmoothness;
  vert2elemtype vert2elem;
  elem2verttype elem2vert;

  std::set<MNode *> listOfBndVertices;
  graphtype graph;
  double smoothness_threshold;

  static std::vector<montripletbis> permutation;

#if defined(HAVE_ANN)
  ANNkd_tree *annTree;
  ANNpointArray dataPts;
  ANNkd_tree *annTreeBnd;
  ANNpointArray dataPtsBnd;
#endif

public:
  frameFieldBackgroundMesh3D(GVolume *_gf);
  virtual ~frameFieldBackgroundMesh3D();

  MNode *get_nearest_neighbor_on_boundary(MNode *v);
  MNode *get_nearest_neighbor_on_boundary(MNode *v, double &distance);

  //    bool findvertex(const MNode *v)const{
  //      std::map<MNode*,double>::const_iterator it =
  //      sizeField.find(const_cast<MNode*>(v)); if (it==sizeField.end())
  //      return false; return true;
  //    };

  double get_smoothness(double x, double y, double z);
  double get_smoothness(MNode *v);

  double get_approximate_smoothness(double x, double y, double z);
  double get_approximate_smoothness(MNode *v);

  void eval_approximate_crossfield(double x, double y, double z, STensor3 &cf);
  void eval_approximate_crossfield(const MNode *vert, STensor3 &cf);

  void get_vectorial_smoothness(double x, double y, double z, SVector3 &cf);
  void get_vectorial_smoothness(const MNode *vert, SVector3 &cf);
  double get_vectorial_smoothness(const int idir, double x, double y, double z);
  double get_vectorial_smoothness(const int idir, const MNode *vert);

  inline void exportCrossField(const std::string &filename)
  {
    export_tensor_as_vectors(filename, crossField);
  };
  inline void exportSmoothness(const std::string &filename) const
  {
    export_scalar(filename, crossFieldSmoothness);
  };
  void exportVectorialSmoothness(const std::string &filename);
};

#endif

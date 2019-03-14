// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BACKGROUND_MESH_BASE_H
#define BACKGROUND_MESH_BASE_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "STensor3.h"

#include "MElement.h"
#include "simpleFunction.h"

//#include <tr1/unordered_map>
//#include <tr1/unordered_set>

class MElementOctree;
class GFace;
class GRegion;
class GVertex;
class GEdge;
class GPoint;
class MElement;
class MVertex;
class GEntity;

class BGMBase {
public:
  typedef MVertex const *const hash_key_ptr;
  //    typedef tr1::unordered_map<hash_key_ptr, STensor3 > TensorStorageType;
  //    typedef tr1::unordered_map<hash_key_ptr, double > DoubleStorageType;
  //    typedef tr1::unordered_map<hash_key_ptr, vector<double> >
  //    VectorStorageType;
  typedef std::map<hash_key_ptr, STensor3> TensorStorageType;
  typedef std::map<hash_key_ptr, double> DoubleStorageType;
  typedef std::map<hash_key_ptr, std::vector<double> > VectorStorageType;

protected:
  mutable MElementOctree *octree;
  GEntity *gf;

  DoubleStorageType sizeField; // an attached size field

  int DIM, order;

  virtual void export_scalar(const std::string &filename,
                             const DoubleStorageType &) const;
  virtual void export_vector(const std::string &filename,
                             const VectorStorageType &) const;
  virtual void
  export_tensor_as_vectors(const std::string &filename,
                           const TensorStorageType &_whatToPrint) const;

  virtual void propagateValues(DoubleStorageType &dirichlet,
                               simpleFunction<double> &eval_diffusivity,
                               bool in_parametric_plane = false) = 0;
  virtual void computeSizeField() = 0;
  virtual GPoint get_GPoint_from_MVertex(const MVertex *) const = 0;
  virtual const MElement *getElement(unsigned int i) const = 0;
  virtual unsigned int getNumMeshElements() const = 0;

  virtual std::vector<double>
  get_nodal_values(const MElement *e, const DoubleStorageType &data) const;
  virtual std::vector<std::vector<double> >
  get_nodal_values(const MElement *e, const VectorStorageType &data) const;

  virtual std::vector<double>
  get_nodal_value(const MVertex *v, const VectorStorageType &data) const;
  virtual double get_nodal_value(const MVertex *v,
                                 const DoubleStorageType &data) const;

  virtual std::vector<double> get_element_uvw_from_xyz(const MElement *e,
                                                       double x, double y,
                                                       double z) const;

  virtual double get_field_value(double u, double v, double w,
                                 const DoubleStorageType &data);
  virtual std::vector<double> get_field_value(double u, double v, double w,
                                              const VectorStorageType &data);

public:
  BGMBase(int dim, GEntity *_gf);
  ~BGMBase();

  virtual MElementOctree *getOctree() = 0;

  virtual GEntity *getBackgroundGEntity();

  virtual double
  size(double u, double v,
       double w = 0.); // get the size field, element interpolation
  virtual double size(const MVertex *v); // get the nodal size field

  virtual bool inDomain(double u, double v, double w = 0.);

  virtual inline void exportSizeField(const std::string &filename) const
  {
    export_scalar(filename, sizeField);
  };

  // warning: these are "3D", "real" vertices, not copies in a parametric domain
  virtual std::set<MVertex *> get_vertices_of_maximum_dim(int dim);
  virtual const MElement *findElement(double u, double v, double w = 0.,
                                      bool strict = true);
};

#endif

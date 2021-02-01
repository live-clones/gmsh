// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BACKGROUND_MESH_H
#define BACKGROUND_MESH_H

#include <cmath>
#include <vector>
#include <list>
#include "simpleFunction.h"
#include "BackgroundMeshTools.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
class ANNkd_tree;
#endif

class MElementOctree;
class GFace;
class GEdge;
class MElement;
class MVertex;

struct crossField2d {
  double _angle;
  static void normalizeAngle(double &angle)
  {
    if(angle < 0)
      while(angle < 0) angle += (M_PI * .5);
    else if(angle >= M_PI * .5)
      while(angle >= M_PI * .5) angle -= (M_PI * .5);
  }
  crossField2d(MVertex *, GEdge *);
  crossField2d(double a) : _angle(a) {}
  crossField2d &operator+=(const crossField2d &);
};

class backgroundMesh : public simpleFunction<double> {
  MElementOctree *_octree;
  std::vector<MVertex *> _vertices;
  std::vector<MElement *> _triangles;
  std::map<MVertex *, double> _sizes;
  std::map<MVertex *, MVertex *> _3Dto2D;
  std::map<MVertex *, MVertex *> _2Dto3D;
  std::map<MVertex *, double> _distance;
  std::map<MVertex *, double> _angles;
  static std::vector<backgroundMesh *> _current;
  backgroundMesh(GFace *, bool dist = false);
  ~backgroundMesh();
#if defined(HAVE_ANN)
  mutable ANNkd_tree *uv_kdtree;
  mutable ANNpointArray nodes;
  ANNidxArray index;
  ANNdistArray dist;
  mutable ANNpointArray angle_nodes;
  mutable ANNkd_tree *angle_kdtree;
  std::vector<double> _cos, _sin;
#endif
public:
  static void set(GFace *);
  static void setCrossFieldsByDistance(GFace *);
  static void unset();
  static backgroundMesh *current();
  void propagate1dMesh(GFace *);
  void propagateCrossField(GFace *, simpleFunction<double> *);
  void propagateCrossFieldHJ(GFace *);
  void propagateCrossField(GFace *);
  void propagateCrossFieldByDistance(GFace *);
  void updateSizes(GFace *);
  double operator()(double u, double v, double w) const; // returns mesh size
  bool inDomain(double u, double v,
                double w) const; // returns true if in domain
  double getAngle(double u, double v, double w) const;
  double getSmoothness(double u, double v, double w);
  double getSmoothness(MElement *);
  void print(const std::string &filename, GFace *gf,
             const std::map<MVertex *, double> &, int smooth = 0);
  void print(const std::string &filename, GFace *gf, int choice = 0)
  {
    switch(choice) {
    case 0: print(filename, gf, _sizes); return;
    case 2: print(filename, gf, _sizes, 1); return;
    default: print(filename, gf, _angles); return;
    }
  }
  MElement *getMeshElementByCoord(double u, double v, double w,
                                  bool strict = true);
  int getNumMeshElements() const { return _triangles.size(); }
  std::vector<MVertex *>::iterator begin_vertices()
  {
    return _vertices.begin();
  }
  std::vector<MVertex *>::iterator end_vertices() { return _vertices.end(); }
  std::vector<MVertex *>::const_iterator begin_vertices() const
  {
    return _vertices.begin();
  }
  std::vector<MVertex *>::const_iterator end_vertices() const
  {
    return _vertices.end();
  }
  std::vector<MElement *>::iterator begin_triangles()
  {
    return _triangles.begin();
  }
  std::vector<MElement *>::iterator end_triangles() { return _triangles.end(); }
  std::vector<MElement *>::const_iterator begin_triangles() const
  {
    return _triangles.begin();
  }
  std::vector<MElement *>::const_iterator end_triangles() const
  {
    return _triangles.end();
  }
};

#endif

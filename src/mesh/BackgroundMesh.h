// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BACKGROUND_MESH_H
#define BACKGROUND_MESH_H

#include <cmath>
#include <vector>
#include <unordered_map>
#include <list>
#include <memory>
#include "simpleFunction.h"
#include "BackgroundMeshTools.h"
#include "MLine.h"
#include "MTriangle.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
class ANNkd_tree;
#endif

class GEntity;
class GModel;
class MElementOctree;
class GSurface;
class GCurve;
class MElement;
class MNode;

struct crossField2d {
  double _angle;
  static void normalizeAngle(double &angle)
  {
    if(angle < 0)
      while(angle < 0) angle += (M_PI * .5);
    else if(angle >= M_PI * .5)
      while(angle >= M_PI * .5) angle -= (M_PI * .5);
  }
  crossField2d(MNode *, GCurve *);
  crossField2d(double a) : _angle(a) {}
  crossField2d &operator+=(const crossField2d &);
};

class backgroundMesh : public simpleFunction<double> {
  MElementOctree *_octree;
  std::vector<MNode *> _vertices;
  std::vector<MElement *> _triangles;
  std::map<MNode *, double> _sizes;
  std::map<MNode *, MNode *> _3Dto2D;
  std::map<MNode *, MNode *> _2Dto3D;
  std::map<MNode *, double> _distance;
  std::map<MNode *, double> _angles;
  static std::vector<backgroundMesh *> _current;
  backgroundMesh(GSurface *, bool dist = false);
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
  static void set(GSurface *);
  static void setCrossFieldsByDistance(GSurface *);
  static void unset();
  static backgroundMesh *current();
  void propagate1dMesh(GSurface *);
  void propagateCrossField(GSurface *, simpleFunction<double> *);
  void propagateCrossFieldHJ(GSurface *);
  void propagateCrossField(GSurface *);
  void propagateCrossFieldByDistance(GSurface *);
  void updateSizes(GSurface *);
  double operator()(double u, double v, double w) const; // returns mesh size
  bool inDomain(double u, double v,
                double w) const; // returns true if in domain
  double getAngle(double u, double v, double w) const;
  double getSmoothness(double u, double v, double w);
  double getSmoothness(MElement *);
  void print(const std::string &filename, GSurface *gf,
             const std::map<MNode *, double> &, int smooth = 0);
  void print(const std::string &filename, GSurface *gf, int choice = 0)
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
  std::vector<MNode *>::iterator begin_vertices()
  {
    return _vertices.begin();
  }
  std::vector<MNode *>::iterator end_vertices() { return _vertices.end(); }
  std::vector<MNode *>::const_iterator begin_vertices() const
  {
    return _vertices.begin();
  }
  std::vector<MNode *>::const_iterator end_vertices() const
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

/************************************************************/
/* Alternative datastructures for storing background meshes */
/************************************************************/

struct BackgroundMeshGEdge {
  GCurve *ge = NULL;
  std::vector<MLine> lines;
};

struct BackgroundMeshGFace {
  GSurface *gf = NULL;
  std::vector<MTriangle> triangles;
};

/* @brief Store a collection of GEntity background meshes.
 *        Deal with the mesh import (see importEntityMeshes())
 *        New MNode* instance are created by the import
 *        and are deleted by the destructor.
 */
class GlobalBackgroundMesh {
public:
  const std::string &name;
  GModel *gm;
  std::unordered_map<GCurve *, BackgroundMeshGEdge> edgeBackgroundMeshes;
  std::unordered_map<GSurface *, BackgroundMeshGFace> faceBackgroundMeshes;
  std::vector<MNode *> mesh_vertices;

public:
  GlobalBackgroundMesh(const std::string &_name) : name(_name), gm(NULL) {}
  GlobalBackgroundMesh(GlobalBackgroundMesh const &) = delete;
  GlobalBackgroundMesh &operator=(GlobalBackgroundMesh const &) = delete;
  ~GlobalBackgroundMesh(); /* delete the MNode instances stored in
                              mesh_vertices */

  /**
   * @brief Fill the entityMesh map by copying the meshes in the GModel.
   *        New MNode, MLine and MTriangle instances are created, the
   * background meshes are totally independant from the ones in the GModel after
   *        this function call.
   *        Quadrangles in GSurface are split into two triangles.
   *
   * @param gm the GModel containing the GEntity whose meshes are imported
   * @param overwriteExisting Delete existing background meshes before importing
   * new ones
   *
   * @warning Only import GPoint, GCurve, GSurface for the moment, not GVolume
   *
   * @return 0 if successful import
   */
  int importGModelMeshes(GModel *gm, bool overwriteExisting = true);
};

/* Global storage for access deep in meshing algorithms without passing
 * reference everywhere. Use getBackgroundMesh(name) instead of direcly
 * accessing the global variable. */
extern std::vector<std::unique_ptr<GlobalBackgroundMesh> > global_bmeshes;
bool backgroudMeshExists(const std::string &name);
GlobalBackgroundMesh &getBackgroundMesh(const std::string &name);

#endif

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCTREE_POST_H
#define OCTREE_POST_H

#include "Octree.h"

class PView;
class PViewData;
class PViewDataList;
class PViewDataGModel;

class OctreePost {
public:
  // the element a search found, where the next one looks first: successive
  // searches close to each other (along a streamline) then mostly skip the
  // search structure; only elements of the highest dimension of the view are
  // kept, so that the result is the one of a full search (up to the element
  // chosen on a face shared by two)
  struct Cache {
    void *element = nullptr;
    int kind = -1; // of list data element
  };

private:
  // for list data: the search structures of the lists of each number of
  // components (1, 3, 9) and kind of element (points, lines, triangles,
  // quadrangles, tetrahedra, hexahedra, prisms, pyramids)
  Octree *_trees[3][8];
  // the highest dimension of the elements of each of these lists
  int _topDim[3];
  PViewDataList *_theViewDataList;
  PViewDataGModel *_theViewDataGModel;
  void _create(PViewData *data);
  bool _getValue(void *in, int dim, int nbNod, int nbComp, double P[3],
                 int step, double *values, double *elementSize, bool grad);
  bool _getValue(void *in, int nbComp, double P[3], int step, double *values,
                 double *elementSize, bool grad);
  bool _search(int numComp, double x, double y, double z, double *values,
               int step, double *size, int qn, double *qx, double *qy,
               double *qz, bool grad, int dim, Cache *cache = nullptr);

public:
  OctreePost(PView *v);
  OctreePost(PViewData *data);
  ~OctreePost();
  // build what the searches in model data create when first needed (the
  // search structure of the mesh, the bases of its elements), for them to be
  // run in several threads afterwards; searches in list data only read
  void prepareThreads();
  // search for the value of the View at point x, y, z. Values are interpolated
  // using standard first order shape functions in the post element. If several
  // time steps are present, they are all interpolated unless time step is set
  // to a different value than -1. If qn is given, n node coordinates stored in
  // qx/y/z are used to select which element is used to interpolate (if the
  // query returned more than one). If grad is true, return the component-wise
  // derivative (gradient) in xyz coordinates instead of the value. If dim !=
  // -1, only return a value if it was found on an element of the
  // prescribed dimension.
  bool searchScalar(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchVector(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchVector(double x, double y, double z, double *values, int step,
                    Cache &cache);
  bool searchTensor(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
};

#endif

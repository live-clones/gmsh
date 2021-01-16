// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCTREE_POST_H
#define OCTREE_POST_H

#include "Octree.h"

class PView;
class PViewData;
class PViewDataList;
class PViewDataGModel;

class OctreePost {
private:
  Octree *_sp, *_vp, *_tp;
  Octree *_sl, *_vl, *_tl;
  Octree *_st, *_vt, *_tt;
  Octree *_sq, *_vq, *_tq;
  Octree *_ss, *_vs, *_ts;
  Octree *_sh, *_vh, *_th;
  Octree *_si, *_vi, *_ti;
  Octree *_sy, *_vy, *_ty;
  PViewDataList *_theViewDataList;
  PViewDataGModel *_theViewDataGModel;
  void _create(PViewData *data);
  bool _getValue(void *in, int dim, int nbNod, int nbComp, double P[3],
                 int step, double *values, double *elementSize, bool grad);
  bool _getValue(void *in, int nbComp, double P[3], int step, double *values,
                 double *elementSize, bool grad);

public:
  OctreePost(PView *v);
  OctreePost(PViewData *data);
  ~OctreePost();
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
  bool searchScalarWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);
  bool searchVector(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchVectorWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);
  bool searchTensor(double x, double y, double z, double *values, int step = -1,
                    double *size = nullptr, int qn = 0, double *qx = nullptr,
                    double *qy = nullptr, double *qz = nullptr,
                    bool grad = false, int dim = -1);
  bool searchTensorWithTol(double x, double y, double z, double *values,
                           int step = -1, double *size = nullptr,
                           double tol = 1.e-2, int qn = 0, double *qx = nullptr,
                           double *qy = nullptr, double *qz = nullptr,
                           bool grad = false, int dim = -1);
};

#endif

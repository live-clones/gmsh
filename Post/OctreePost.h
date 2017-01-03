// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _OCTREE_POST_H_
#define _OCTREE_POST_H_

#include "Octree.h"

class PView;
class PViewData;
class PViewDataList;
class PViewDataGModel;

class OctreePost
{
 private:
  Octree *_SPP, *_VPP, *_TPP; // _SP & co reserved by win32
  Octree *_SL, *_VL, *_TL;
  Octree *_ST, *_VT, *_TT;
  Octree *_SQ, *_VQ, *_TQ;
  Octree *_SS, *_VS, *_TS;
  Octree *_SH, *_VH, *_TH;
  Octree *_SI, *_VI, *_TI;
  Octree *_SY, *_VY, *_TY;
  PViewDataList *_theViewDataList;
  PViewDataGModel *_theViewDataGModel;
  void _create(PViewData *data);
  bool _getValue(void *in, int dim, int nbNod, int nbComp,
                 double P[3], int step, double *values,
                 double *elementSize, bool grad);
  bool _getValue(void *in, int nbComp, double P[3], int step,
                 double *values, double *elementSize, bool grad);
 public :
  OctreePost(PView *v);
  OctreePost(PViewData *data);
  ~OctreePost();
  // search for the value of the View at point x, y, z. Values are interpolated
  // using standard first order shape functions in the post element. If several
  // time steps are present, they are all interpolated unless time step is set
  // to a different value than -1. If qn is given, n node coordinates stored in
  // qx/y/z are used to select which element is used to interpolate (if the
  // query returned more than one). If grad is true, return the component-wise
  // derivative (gradient) in xyz coordinates instead of the value.
  bool searchScalar(double x, double y, double z, double *values,
                    int step=-1, double *size=0,
                    int qn=0, double *qx=0, double *qy=0, double *qz=0,
                    bool grad=false);
  bool searchScalarWithTol(double x, double y, double z, double *values,
                           int step=-1, double *size=0, double tol=1.e-2,
                           int qn=0, double *qx=0, double *qy=0, double *qz=0,
                           bool grad=false);
  bool searchVector(double x, double y, double z, double *values,
                    int step=-1, double *size=0,
                    int qn=0, double *qx=0, double *qy=0, double *qz=0,
                    bool grad=false);
  bool searchVectorWithTol(double x, double y, double z, double *values,
                           int step=-1, double *size=0, double tol=1.e-2,
                           int qn=0, double *qx=0, double *qy=0, double *qz=0,
                           bool grad=false);
  bool searchTensor(double x, double y, double z, double *values,
                    int step=-1, double *size=0,
                    int qn=0, double *qx=0, double *qy=0, double *qz=0,
                    bool grad=false);
  bool searchTensorWithTol(double x, double y, double z, double *values,
                           int step=-1, double *size=0, double tol=1.e-2,
                           int qn=0, double *qx=0, double *qy=0, double *qz=0,
                           bool grad=false);
};

#endif

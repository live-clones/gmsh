// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCTREE_POST_H_
#define _OCTREE_POST_H_

#include "Octree.h"

class PView;
class PViewDataList;
class PViewDataGModel;

class OctreePost 
{
 private:
  Octree *_SL, *_VL, *_TL;
  Octree *_ST, *_VT, *_TT;
  Octree *_SQ, *_VQ, *_TQ;
  Octree *_SS, *_VS, *_TS;
  Octree *_SH, *_VH, *_TH;
  Octree *_SI, *_VI, *_TI;
  Octree *_SY, *_VY, *_TY;
  PView *_theView;
  PViewDataList *_theViewDataList;
  PViewDataGModel *_theViewDataGModel;
  bool _getValue(void *in, int dim, int nbNod, int nbComp, 
                 double P[3], int step, double *values,
                 double *elementSize);
  bool _getValue(void *in, int nbComp, double P[3], int step, 
                 double *values, double *elementSize);
  bool searchScalar_(double x, double y, double z, double *values, 
                    int step = -1, double *size = 0);
 public :
  OctreePost(PView *);
  ~OctreePost();
  // search for the value of the View at point x, y, z. Values are
  // interpolated using standard first order shape functions in the
  // post element. If several time steps are present, they are all
  // interpolated unless time step is set to a different value than
  // -1.
  bool searchScalar(double x, double y, double z, double *values, 
                    int step = -1, double *size = 0);
  bool searchVector(double x, double y, double z, double *values, 
                    int step = -1, double *size = 0);
  bool searchTensor(double x, double y, double z, double *values, 
                    int step = -1, double *size = 0);
};

#endif

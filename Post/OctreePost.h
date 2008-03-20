#ifndef _OCTREE_POST_H_
#define _OCTREE_POST_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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
  Octree *_GModel;
  PView *_theView;
  PViewDataList *_theViewDataList;
  PViewDataGModel *_theViewDataGModel;
  bool _getValue(void *in, int dim, int nbNod, int nbComp, 
		 double P[3], int step, double *values,
		 double *elementSize);
  bool _getValue(void *in, int nbComp, double P[3], int step, 
		 double *values, double *elementSize);
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

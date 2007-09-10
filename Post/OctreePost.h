#ifndef _OCTREE_POST_H_
#define _OCTREE_POST_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

class OctreePost 
{
  Octree *SL, *VL, *TL;
  Octree *ST, *VT, *TT;
  Octree *SQ, *VQ, *TQ;
  Octree *SS, *VS, *TS;
  Octree *SH, *VH, *TH;
  Octree *SI, *VI, *TI;
  Octree *SY, *VY, *TY;
  PView *theView;
  bool getValue(void *in, int dim, int nbNod, int nbComp, 
		double P[3], int timestep, double *values, double *size_elem);
 public :
  OctreePost(PView *);
  ~OctreePost();
  // search for the value of the View at point x, y, z. Values are
  // interpolated using standard first order shape functions in the
  // post element. If several time steps are present, they are all
  // interpolated unless time step is set to a different value than
  // -1.
  bool searchScalar(double x, double y, double z, double *values, 
		    int timestep = -1, double *size_elem = 0);
  bool searchVector(double x, double y, double z, double *values, 
		    int timestep = -1, double *size_elem = 0);
  bool searchTensor(double x, double y, double z, double *values, 
		    int timestep = -1, double *size_elem = 0);
};

#endif

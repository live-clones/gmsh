#ifndef _3D_MESH_H_
#define _3D_MESH_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "Tree.h"
#include "Mesh.h"

Brick LaBrique (Grid_T * pGrid, double X, double Y, double Z);
void AddSimplexInGrid (Mesh * m, Simplex * s, int boule_boite);
int Coherence (Volume * v, Mesh * m);
int Pt_In_Volume (double X, double Y, double Z, Mesh * m,
                  double *l, double tol);
void findminmax (void *a, void *b);
void getminmax (double *xmin, double *ymin, double *zmin,
                double *xmax, double *ymax, double *zmax);
void cut_tetraedre (Intersection * pI, Tree_T * AddedTet, Tree_T * TetDel,
                    Tree_T * newpoints);
void Impression_Resultats (void);
void Restore_Volume (Volume * v);
void Remise_A_Zero (void);

#endif

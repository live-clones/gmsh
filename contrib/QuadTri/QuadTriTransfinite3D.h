/********************************************************************************
QuadTriTransfinite3D.h

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com>

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the
conformal interface of quadrangle faces to triangle faces using pyramids and
other mesh elements.

Trevor S. Strickler hereby transfers copyright of QuadTri files to Christophe
Geuzaine and J.-F. Remacle with the understanding that his contribution shall be
cited appropriately. See the LICENSE.txt file for license information.
********************************************************************************/

#ifndef QTTRANS3D_H
#define QTTRANS3D_H

#include "QuadTriUtils.h"

// Function to get all the diagonals from external surfaces of a given
// Transfinite region tr and place them in boundary_diags.
int getTransfiniteBoundaryDiags(
  GRegion *tr, std::set<std::pair<MVertex *, MVertex *> > *boundary_diags);

// Meshes either a prism or a hexahedral set of mesh vertices in a Transfinite
// Region with an internal vertex that is created here in the function.
void meshTransfElemWithInternalVertex(
  GRegion *to, std::vector<MVertex *> v,
  std::set<std::pair<MVertex *, MVertex *> > *boundary_diags);

#endif

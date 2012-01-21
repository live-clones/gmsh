/************************************************************************************************** 
QuadTriTransfinite3D.h

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com> 

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the conformal interface
of quadrangle faces to triangle faces using pyramids and other mesh elements. 

See READMEQUADTRI.txt for more information. The license information is in LICENSE.txt.

Trevor S. Strickler hereby transfers copyright of QuadTri files to 
Christophe Geuzaine and J.-F. Remacle with the understanding that 
his contribution shall be cited appropriately.

All reused or original Gmsh code is Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
Gmsh is available at: www.geuz.org/gmsh

For Gmsh license information, see the LICENSE.txt file for license information. Please report all
Gmsh bugs and problems to <gmsh@geuz.org>.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, Version 2,
as published by the Free Software Foundation, or (at your option) 
any later version, with or without the exception given in the 
LICENSE.txt file supplied with this code and with Gmsh.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

****************************************************************************************************/

#if !defined( _QTTRANS3D_H_ )
#define _QTTRANS3D_H_

#include "QuadTriUtils.h"

// Function to get all the diagonals from external surfaces of a given Transfinite region tr
// and place them in boundary_diags.
int getTransfiniteBoundaryDiags( GRegion *tr, std::set< std::pair<MVertex*,
				         MVertex*> > *boundary_diags );

// Meshes either a prism or a hexahedral set of mesh vertices in a Transfinite Region with an internal vertex 
// that is created here in the function.
void meshTransfElemWithInternalVertex( GRegion *to, std::vector<MVertex *> v, 
                                       std::set< std::pair<MVertex*, MVertex*> > *boundary_diags );

#endif

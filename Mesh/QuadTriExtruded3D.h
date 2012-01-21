/************************************************************************************************** 
QuadTriExtruded3D.h

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

#if !defined( _QTEXTR3D_H_ )
#define _QTEXTR3D_H_

#include "Geo.h"
#include "GEntity.h"
#include "GFace.h"
#include "GRegion.h"
#include "GEdge.h"
#include "GModel.h"
#include "ExtrudeParams.h"
#include "GmshDefines.h"
#include "MVertex.h"
#include "Context.h"
#include "GModel.h"
#include "meshGFace.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "Numeric.h"
#include <map>
#include <math.h>
#include "QuadTriUtils.h"

// Determines whether the region is a valid QuadToTri region.  Performs some 
// basic checks, including whether there is a valid top, valid source,
// and that the surfaces serving as laterals are structured 
// Added 2010-12-30
bool IsValidQuadToTriRegion(GRegion *region, bool *allNonGlobalSharedLaterals);

// Mesh QuadToTri region from extrudeMesh() from meshGRegionExtruded.cpp.
// Added 04/08/2011:
int meshQuadToTriRegion( GRegion *gr, std::set<MVertex*, MVertexLessThanLexicographic> &pos );

// The function that is called from meshGRegionExtruded.cpp to mesh QuadToTri regions
// that are adjacent to subdivided regions, after the global Subdivide command is called.
// Added 04/08/11.
int meshQuadToTriRegionAfterGlobalSubdivide( GRegion *gr, std::set<std::pair<MVertex*, MVertex*> > *edges,
                                            std::set<MVertex*, MVertexLessThanLexicographic> &pos );


#endif

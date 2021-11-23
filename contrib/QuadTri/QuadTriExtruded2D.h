/*******************************************************************************
QuadTriExtruded2D.h

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com>

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the
conformal interface of quadrangle faces to triangle faces using pyramids and
other mesh elements.

Trevor S. Strickler hereby transfers copyright of QuadTri files to Christophe
Geuzaine and J.-F. Remacle with the understanding that his contribution shall be
cited appropriately. See the README.txt file for license information.
********************************************************************************/

#ifndef QTEXTR2D_H
#define QTEXTR2D_H

#include "GEntity.h"
#include "GFace.h"
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
#include "Numeric.h"
#include <map>
#include <cmath>
#include "QuadTriUtils.h"

// The function that tests whether a 2D surface is a lateral of a valid
// QuadToTri region and whether there are conflicts. If surface is not part of
// valid QuadToTri region or if there are QuadToTri conflicts, return 0.  Note
// that RemoveDuplicateSurfaces() makes this DIFFICULT. Also, the tri_quad_flag
// determins whether the surface should be meshed with triangles or quadrangles:
// tri_quad_values: 0 = no override, 1 = mesh as quads, 2 = mesh as triangles.
// Added 2010-12-09.
int IsValidQuadToTriLateral(GFace *face, int *tri_quad_flag,
                            bool *detectQuadToTriLateral);

// The function that tests whether a surface is a QuadToTri top surface and
// whether there are conflicts. If surface is not a top for a valid QuadToTri
// region or if there are QuadToTri conflicts, return 0.  Note that
// RemoveDuplicateSurfaces() makes this DIFFICULT. Also, the type of QuadToTri
// interface is placed into the pointer argument quadToTri. .  Added 2010-12-09.
int IsValidQuadToTriTop(GFace *face, int *quadToTri, bool *detectQuadToTriTop);

// This function meshes the top surface of a QuadToTri extrusion.  It returns 0
// if it is given a non-quadToTri extrusion or if it fails.  Args: 'GFace *to'
// is the top surface to mesh, 'from' is the source surface, 'pos' is a tree
// of vertex positions for the top surface.
int MeshQuadToTriTopSurface(GFace *from, GFace *to, MVertexRTree &pos);

#endif

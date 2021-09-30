/********************************************************************************
QuadTriExtruded3D.h

The code in this file was written by Dr. Trevor S. Strickler.
email: <trevor.strickler@gmail.com>

This file is part of the QuadTri contribution to Gmsh. QuadTri allows the
conformal interface of quadrangle faces to triangle faces using pyramids and
other mesh elements.

Trevor S. Strickler hereby transfers copyright of QuadTri files to Christophe
Geuzaine and J.-F. Remacle with the understanding that his contribution shall be
cited appropriately. See the README.txt file for license information.
********************************************************************************/

#ifndef QTEXTR3D_H
#define QTEXTR3D_H

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
#include <cmath>
#include "QuadTriUtils.h"

// Determines whether the region is a valid QuadToTri region.  Performs some
// basic checks, including whether there is a valid top, valid source, and that
// the surfaces serving as laterals are structured Added 2010-12-30
bool IsValidQuadToTriRegion(GRegion *region, bool *allNonGlobalSharedLaterals);

// Mesh QuadToTri region from extrudeMesh() from meshGRegionExtruded.cpp.  Added
// 04/08/2011:
int meshQuadToTriRegion(GRegion *gr, MVertexRTree &pos);

// The function that is called from meshGRegionExtruded.cpp to mesh QuadToTri
// regions that are adjacent to subdivided regions, after the global Subdivide
// command is called.  Added 04/08/11.
int meshQuadToTriRegionAfterGlobalSubdivide(
  GRegion *gr, std::set<std::pair<MVertex *, MVertex *> > *edges,
  MVertexRTree &pos);

#endif

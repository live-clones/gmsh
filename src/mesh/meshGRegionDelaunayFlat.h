// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GREGION_DELAUNAY_FLAT_H
#define MESH_GREGION_DELAUNAY_FLAT_H

// Flat-array refinement kernel of the 3D Delaunay mesher, selected with
// Mesh.FlatRefineDelaunay3D. Same algorithm and same floating-point
// operations as the MTet4 kernel in meshGRegionDelaunay.cpp, on index-based
// arrays instead of objects; the meshes are bit-for-bit identical, node and
// element numbering included. Internal to the mesher - the entry points the
// rest of Gmsh uses are in meshGRegionDelaunay.h.

#include <set>
#include <vector>
#include "MFace.h"

class GRegion;
class MTet4;
class MTet4Factory;
struct edgeContainerB;

void refineRegionFlat(GRegion *gr, int maxIter, double worstTetRadiusTarget,
                      std::vector<MTet4 *> &tets0, MTet4Factory &myFactory,
                      std::vector<double> &vSizes,
                      std::vector<double> &vSizesBGM, int &NUM,
                      const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                      edgeContainerB &allEmbeddedEdges);

#endif

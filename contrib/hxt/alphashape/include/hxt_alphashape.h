
#ifndef HXT_ALPHASHAPE_H
#define HXT_ALPHASHAPE_H

#include "hxt_tetDelaunay.h"
#include "hxt_alphaUtils.h"
#include "hxt_tetRefine.h"

// Compute the alpha shape of the Delaunay tetrahedrization.
// Assuming a mesh already exists (from gmsh or other).
// A size field can be given as input for a variable value of alpha.
HXTStatus hxtAlphaShape(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions);

// Refine the surface triangulation defined by the alpha shape.
// The facets on the boundary should respect a size field defined by the user.
int hxtRefineSurfaceTriangulation(HXTMesh** mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions);

// Delaunay refinement of the tetrahedra colored as part of the alpha shape.
// A size field should be given as input.
int hxtRefineTetrahedraInAlphaShape(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions);

int hxtAlphaShapeNodeInsertion(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions);

#endif
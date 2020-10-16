// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_PATTERNS
#define MESH_QUAD_PATTERNS

#include <vector>

class MVertex;
class GFace;
class MElement;


bool patchIsRemeshableWithQuadPattern(const std::vector<size_t>& sideSizes);

/* Remesh a cavity (defined by its boundary arranged in sides) with a quad pattern
 * some important notes: 
 * - the GFace gf is modified, vertices and quads are added 
 * - the old quads inside the cavity are not deleted, because they are not know by this method 
 * - return 0 if successful
 * - if failure (status != 0), the GFace gf is not changed */
int remeshPatchWithQuadPattern(GFace* gf, 
    const std::vector<std::vector<MVertex*> > & sides, /* vertices on the boundary, not changed */
    std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
    std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*> & newElements               /* new quads inside the cavity */
    );

/* Remesh small cavity, useful to remove:
 * - interior vertices with valence 6 or 7
 * - boundary vertices (i.e. on GEdge) with valence 3
 * The cavity boundary vertices, in bnd, must be ordered and their
 * ideal / allowed quad valence specified (to avoid adding new high valence
 * vertices and optimize the pattern choice) */
int remeshFewQuads(GFace* gf, 
    const std::vector<MVertex*>& bnd,
    const std::vector<int>& bndIdealValence,
    const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
    std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
    std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*> & newElements               /* new quads inside the cavity */
    );

void printPatternUsage();

#endif

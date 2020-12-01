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
class SPoint3;
class SurfaceProjector;

/*******************************/
/* Hand-made pattern remeshing */
/*******************************/

namespace QuadPatternMatching {

/* List of patterns */
extern const size_t PATTERN_QUAD_REGULAR;
extern const size_t PATTERN_TRIANGLE;
extern const size_t PATTERN_PENTAGON;
extern const size_t PATTERN_QUAD_DIAG35;
extern const size_t PATTERN_QUAD_ALIGNED35;
extern const size_t PATTERN_QUAD_CHORD_UTURN;
extern const size_t PATTERN_2CORNERS;
extern const size_t PATTERN_1CORNER;
extern const size_t PATTERN_DISK;

/* Call this function one-time before using patchIsRemeshableWithQuadPattern() and remeshPatchWithQuadPattern() */
bool load_patterns();

std::vector<size_t> getAllLoadedPatterns();

bool patchIsRemeshableWithQuadPattern(
    const std::vector<size_t>& patternsToCheck, /* Contain the ids of the above pattern */
    size_t Ncorners, 
    const std::vector<size_t>& sideSizes, 
    std::pair<size_t,int>& patternNoAndRot,
    double& irregularityMeasure);

/* Remesh a cavity (defined by its boundary arranged in sides) with a quad pattern
 * some important notes: 
 * - the GFace gf is modified, vertices and quads are added 
 * - the old elements (quads or triangles) inside the cavity and the old vertices are deleted
 * - return 0 if successful
 * - if failure (status != 0), the GFace gf is not changed */
int remeshPatchWithQuadPattern(GFace* gf, 
    const std::vector<std::vector<MVertex*> > & sides, /* vertices on the boundary, not changed */
    const std::pair<size_t,int>& patternNoAndRot,      /* pattern to use, from patchIsRemeshableWithQuadPattern */
    std::vector<MElement*> & oldElements,              /* elements to replace */
    std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
    std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*> & newElements,              /* new quads inside the cavity */
    SurfaceProjector* sp = NULL,                       /* a quick way to project on GFace triangulation */
    double qualityMin = 0.,                            /* only remesh if resulting quality > qualityMin */
    double qualityFactor = 0.                          /* only remesh if quality > qualityDegradeFactor * qualityBefore */
    );





/***********************************/
/* Disk quandrangulation remeshing */
/***********************************/

/* Call this function before using remeshFewQuads() */
bool load_disk_quadrangulations();

/* Remesh small cavity, useful to remove:
 * - interior vertices with valence 6 or 7
 * - boundary vertices (i.e. on GEdge) with valence 3
 * The cavity boundary vertices, in bnd, must be ordered and their
 * ideal / allowed quad valence specified (to avoid adding new high valence
 * vertices and optimize the pattern choice)
 * WARNING: GFace is NOT modified, just the "floating" MVertex
 * and MQuadrangle are created, they must be inserted in the GFace
 * later is the pattern is kept
 * */
int remeshFewQuads(GFace* gf, 
    const std::vector<MVertex*>& bnd,
    const std::vector<MElement*> & oldElements,              /* old quads inside the cavity */
    const std::vector<int>& bndIdealValence,
    const std::vector<std::pair<int,int> >& bndAllowedValenceRange,
    std::vector<MVertex*> & newVertices,               /* new vertices inside the cavity */
    std::vector<bool> & vertexIsIrregular,             /* for each new vertex, true if irregular */
    std::vector<MElement*> & newElements,              /* new quads inside the cavity */
    SurfaceProjector* sp = NULL,                       /* a quick way to project on GFace triangulation */
    double qualityMin = 0.,                            /* only remesh if resulting quality > qualityMin */
    double qualityFactor = 0.,                         /* only remesh if quality > qualityDegradeFactor * qualityBefore */
    const std::vector<MElement*>& neighborsForGeometry = {}
    );

void printPatternUsage();

}

#endif

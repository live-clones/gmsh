

#ifndef _HXT_ALPHASHAPEFORPOLYMESH_H
#define _HXT_ALPHASHAPEFORPOLYMESH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetOpti.h"
#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_tetRefine.h"
#include "hxt_alphashape.h"

void _refineSurfaceTriangulation(HXTMesh** meshPtr, HXTDelaunayOptions* delOptions, HXTAlphaShapeOptions* alphaShapeOptions);


#ifdef __cplusplus
}
#endif

#endif
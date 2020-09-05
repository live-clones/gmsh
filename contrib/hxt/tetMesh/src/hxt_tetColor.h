// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETCOLOR_H
#define HXT_TETCOLOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"


/* Gives a unique color to each enclosed volume
 * If mesh->brep.numVolumes = 0, then this functions fills those BREP fields:
 *  - mesh->brep.numVolumes
 *  - mesh->brep.numSurfacesPerVolume
 *  - mesh->brep.surfacesPerVolume
 * 
 * else, the colors of each volume are filled such as to match the BREP.
 */
HXTStatus hxtMapColorsToBrep(HXTMesh* mesh, uint64_t* tri2TetMap);

/* set the processed flag (see hxt_tetFlag.h) for colors that are not in colorsToMesh */
HXTStatus setFlagsToProcessOnlyVolumesInBrep(HXTMesh* mesh);

#ifdef __cplusplus
}
#endif

#endif

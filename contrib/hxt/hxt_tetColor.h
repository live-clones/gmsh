#ifndef _HXT_TETCOLOR_
#define _HXT_TETCOLOR_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"

/// Gives a unique color to each enclosed volume
HXTStatus hxtColorMesh(HXTMesh* mesh, uint16_t *nbVolumes);

/* call hxtFillVolumeBrep if mesh->brep.numVolumes = 0
 * or change the colors so that they match the volumes described by
 * mesh->brep.numSurfacesPerVolume
 * mesh->brep.surfacesPerVolume
 */
HXTStatus hxtMapColorsToBrep(HXTMesh* mesh, uint16_t nbColors, uint64_t* tri2TetMap);


// fill mesh->brep.numVolumes, mesh->brep.numSurfacesPerVolume and mesh->brep.surfacesPerVolume
HXTStatus hxtFillVolumeBrep(HXTMesh* mesh, uint64_t* tri2TetMap,
                            uint16_t numVolumes, uint16_t** numSurfacesPerVolume, uint16_t** surfacesPerVolume);

/* set the processed flag (see hxt_tetFlag.h) for colors that are not in colorsToMesh */
HXTStatus setFlagsToProcessOnlyVolumesInBrep(HXTMesh* mesh);

#ifdef __cplusplus
}
#endif

#endif

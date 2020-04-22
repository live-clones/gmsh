#ifndef HXT_QUADMULTIBLOCK_H
#define HXT_QUADMULTIBLOCK_H

#ifdef __cplusplus
#include <string> 
extern "C" {
#endif

#include "hxt_api.h" 
#include "hxt_mesh.h"

  /* HXTStatus hxtQuadMultiBlockTest(HXTMesh *mesh, int nbTurns, double critNorm, int flagTypePos, const char *fileName, const char *geoFile); */
  /* HXTStatus hxtQuadMultiBlockGetSingInfo(HXTMesh *mesh,int nbTurns, double critNorm, int flagTypePos, const char *fileName, const char *geoFile); */
  HXTStatus hxtQuadMultiBlockGetSingInfo(HXTMesh *mesh, int tagCrossField, std::string geoFileName);
  HXTStatus hxtQuadMultiBlockDBG(HXTMesh *mesh, int tagCrossField, HXTMesh **splitMesh);
  HXTStatus hxtQuadMultiBlockSplitWithPrescribedSing(HXTMesh *mesh, int tagCrossField, HXTMesh **splitMesh);

#ifdef __cplusplus
}
#endif

#endif

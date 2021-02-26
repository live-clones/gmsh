#ifndef HXT_ORIENTATION3D_SCALING
#define HXT_ORIENTATION3D_SCALING

#include "hxt_mesh.h"

typedef struct HXTOrientation3DScalStruct HXTOrientation3DScal;
HXTStatus hxtScaleCrossesFromFrames(HXTMesh *mesh, double *frames, double *directionsScaled, double *smoothnessIndicator);
HXTStatus hxtScaleCrossesFromFramesQuadBC(HXTMesh *mesh, HXTMesh *quadMesh, double *frames, double *directionsScaled, double *smoothnessIndicator);
HXTStatus solveAndWriteDBG2DRect(HXTMesh *mesh);
#endif

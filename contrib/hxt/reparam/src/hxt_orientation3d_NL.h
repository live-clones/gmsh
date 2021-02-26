#ifndef HXT_ORIENTATION3D_NR_H
#define HXT_ORIENTATION3D_NR_H

#include "hxt_mesh.h"

typedef struct HXTOrientation3DStruct HXTOrientation3D;

HXTStatus computeFramesNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon);
HXTStatus computeFramesEulerNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon);
HXTStatus computeFramesEulerIntNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon);
HXTStatus computeFramesEulerConstScalNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon);
HXTStatus computeFramesEulerMixedNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon);
/* HXTStatus computeFramesNLNewInt(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon); */

#endif

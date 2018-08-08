#ifndef _HXT_MESH_3D_MAIN_
#define _HXT_MESH_3D_MAIN_

#include "hxt_mesh.h"

HXTStatus hxtTetMesh3d(HXTMesh* mesh,
                      int nthreads,
                      int reproducible,
                      int verbosity,
                      int displayStat,
                      int refine,
                      int optimize,
                      double qualityThreshold,
                      HXTStatus (*bnd_recovery)(HXTMesh* mesh));

#endif
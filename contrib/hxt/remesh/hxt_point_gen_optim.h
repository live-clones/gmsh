#ifndef HXT_POINT_GEN_OPTIM_H
#define HXT_POINT_GEN_OPTIM_H

#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"


HXTStatus hxtPointGenOptim(HXTMesh *mesh, const double *directions, const double *sizemap);
HXTStatus hxtPointGenSmoothing(HXTMesh *mesh);

#endif

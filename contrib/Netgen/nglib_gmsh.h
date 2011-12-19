#ifndef _NGLIB_GMSH_H_
#define _NGLIB_GMSH_H_

#include "nglib.h"

Ng_Result Ng_GenerateVolumeMesh(Ng_Mesh *mesh, double maxh);
Ng_Result Ng_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh);

#endif

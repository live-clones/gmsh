#ifndef HEXTREME_PARAMETRIZATION_H
#define HEXTREME_PARAMETRIZATION_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

typedef struct HXTVectorStruct HXTVector;
typedef struct HXTParametrizationStruct HXTParametrization;


HXTStatus hxtParametrizationCreate(HXTMesh *mesh, HXTParametrization **parametrization);
HXTStatus hxtParametrizationDelete(HXTParametrization **parametrization);
HXTStatus hxtParametrizationCompute(HXTParametrization *parametrization, int **colors, int **nNodes, int **nodes, double **uv, int*nc);
HXTStatus hxtParametrizationWrite(HXTParametrization *parametrization, const char *filename);


#endif

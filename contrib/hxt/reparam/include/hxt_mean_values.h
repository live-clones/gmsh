#ifndef HEXTREME_MEAN_VALUES_H
#define HEXTREME_MEAN_VALUES_H

#include "hxt_edge.h"


typedef struct HXTMeanValuesStruct HXTMeanValues;


HXTStatus hxtMeanValuesCreate(HXTEdges *edges, HXTMeanValues **meanValues);
HXTStatus hxtMeanValuesDelete(HXTMeanValues **meanValues);
HXTStatus hxtMeanValuesCompute(HXTMeanValues *meanValues);
HXTStatus hxtMeanValueAspectRatio(HXTMeanValues *meanValues, int *aspectRatio);
HXTStatus hxtMeanValuesGetData(HXTMeanValues *mv, uint64_t **global, uint32_t **gn, double **uv, int *nv, int *ne, int onlyuv);

#ifdef HXT_CORE_FILEIO
HXTStatus hxtMeanValuesWrite(HXTMeanValues *meanValues, const char* filename);
HXTStatus hxtMeanValuesWriteParamMesh(HXTMeanValues *meanValues, const char* filename);
#endif

#endif

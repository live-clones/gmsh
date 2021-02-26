#ifndef HXT_UVW_PARAMETRIZATION_H
#define HXT_UVW_PARAMETRIZATION_H
#include "hxt_mesh.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct {
    int ignore_scaling;
    int debug;
    int verbose;
  } HxtUVWParamOptions;

  HXTStatus computeUVW(
      HXTMesh* mesh,
      const double* directionsScaled,
      const double* smoothnessIndicator,
      const HxtUVWParamOptions* options,
      double* uvw /* size: nb_tets*12, order: all u, then all v, then all w */
		       );

  HXTStatus get_lifting(
			HXTMesh* mesh,
			const double* directionsScaled,
			const double* gradientIndicator,
			const HxtUVWParamOptions* options,
			double* liftU,
			double* liftV,
			double* liftW
			);
    
  HXTStatus savePerTetDirectionsAndSmoothness(
      const HXTMesh* mesh,
      const double* directionsScaled,
      const double* smoothnessIndicator,
      const char* path);

  /* Assume arrays are already allocated with the right size */
  HXTStatus loadPerTetDirectionsAndSmoothness(
      const char* path,
      const HXTMesh* mesh,
      double* directionsScaled,
      double* smoothnessIndicator);

#ifdef __cplusplus
}
#endif

#endif

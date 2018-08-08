#ifndef _HXT_TET_ASPECT_RATIO_
#define _HXT_TET_ASPECT_RATIO_

double hxtTetAspectRatio (double p0[3],  double p1[3], double p2[3], double p3[3]);

//!\ this function does not return the aspect ratio 'r'. It returns 'r^2/24'
double hxtTetAspectFastRatio (double p0[3],  double p1[3], double p2[3], double p3[3]);

#endif

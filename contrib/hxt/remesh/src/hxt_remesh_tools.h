#ifndef HXT_REMESH_TOOLS_H
#define HXT_REMESH_TOOLS_H

#include "hxt_message.h"

/*********************************************************
 * Operations on 3D vectors
 *********************************************************/
HXTStatus hxtNorm2V3(double v[3], double* norm2);
HXTStatus hxtNorm2V(double v[3], int size, double* norm2);
HXTStatus hxtNormalizeV3(double v[3]);
HXTStatus hxtNormalizeV(double *v, int size);
HXTStatus hxtCrossProductV3(double a[3], double b[3], double res[3]);

/*********************************************************
 * Matrix operations
 *********************************************************/
HXTStatus hxtDet2x2(double mat[2][2], double* det);
HXTStatus hxtInv2x2(double mat[2][2], double inv[2][2], double *det);
HXTStatus hxtDet3x3(double mat[3][3], double *det);
HXTStatus hxtInv3x3(double mat[3][3], double inv[3][3], double *det);

HXTStatus hxtInv4x4ColumnMajor(double mat[16], double inv[16], double *det);

#endif

#include "hxt_api.h"
#include "hxt_tools.h"

HXTStatus hxtNorm2V3(double v[3], double* norm2){
  *norm2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  return HXT_STATUS_OK;
}

HXTStatus hxtNormalizeV3(double v[3]){
  double norm=0.0;
  hxtNorm2V3(v,&norm);
  v[0] /= norm;
  v[1] /= norm;
  v[2] /= norm;
  return HXT_STATUS_OK;
}

HXTStatus hxtCrossProductV3(double a[3], double b[3], double res[3]){
  res[0] = a[1]*b[2] - a[2]*b[1];
  res[1] = a[2]*b[0] - a[0]*b[2];
  res[2] = a[0]*b[1] - a[1]*b[0];
  return HXT_STATUS_OK;
}

HXTStatus hxtDet2x2(double mat[2][2], double* det){
  *det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
  return HXT_STATUS_OK;
}

HXTStatus hxtInv2x2(double mat[2][2], double inv[2][2], double *det){
  hxtDet2x2(mat,det);
  if(*det) {
    const double ud = 1. / *det;
    inv[0][0] =  mat[1][1] * ud;
    inv[0][1] = -mat[0][1] * ud;
    inv[1][0] = -mat[1][0] * ud;
    inv[1][1] =  mat[0][0] * ud;
  } else {
    return HXT_STATUS_ERROR;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtDet3x3(double mat[3][3], double *det)
{
  *det = (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
          mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
          mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
  return HXT_STATUS_OK;
}

HXTStatus hxtInv3x3(double mat[3][3], double inv[3][3], double *det)
{
  HXT_CHECK(hxtDet3x3(mat, det));
  if(*det){
    double ud = 1. / *det;
    inv[0][0] =  (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] =  (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] =  (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] =  (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] =  (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
    return HXT_STATUS_OK;
  }
  else{
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        inv[i][j] = 0.;
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Singular matrix 3x3");
  }
}

HXTStatus hxtInv4x4ColumnMajor(double m[16], double invOut[16], double *det)
{
  double inv[16];
  int i;
  
  inv[ 0] =  m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
  inv[ 4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
  inv[ 8] =  m[4] * m[ 9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[ 9];
  inv[12] = -m[4] * m[ 9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[ 9];
  inv[ 1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
  inv[ 5] =  m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
  inv[ 9] = -m[0] * m[ 9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[ 9];
  inv[13] =  m[0] * m[ 9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[ 9];
  inv[ 2] =  m[1] * m[ 6] * m[15] - m[1] * m[ 7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[ 7] - m[13] * m[3] * m[ 6];
  inv[ 6] = -m[0] * m[ 6] * m[15] + m[0] * m[ 7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[ 7] + m[12] * m[3] * m[ 6];
  inv[10] =  m[0] * m[ 5] * m[15] - m[0] * m[ 7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[ 7] - m[12] * m[3] * m[ 5];
  inv[14] = -m[0] * m[ 5] * m[14] + m[0] * m[ 6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[ 6] + m[12] * m[2] * m[ 5];
  inv[ 3] = -m[1] * m[ 6] * m[11] + m[1] * m[ 7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[ 9] * m[2] * m[ 7] + m[ 9] * m[3] * m[ 6];
  inv[ 7] =  m[0] * m[ 6] * m[11] - m[0] * m[ 7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[ 8] * m[2] * m[ 7] - m[ 8] * m[3] * m[ 6];
  inv[11] = -m[0] * m[ 5] * m[11] + m[0] * m[ 7] * m[ 9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[ 9] - m[ 8] * m[1] * m[ 7] + m[ 8] * m[3] * m[ 5];
  inv[15] =  m[0] * m[ 5] * m[10] - m[0] * m[ 6] * m[ 9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[ 9] + m[ 8] * m[1] * m[ 6] - m[ 8] * m[2] * m[ 5];
  
  *det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
  
  if(*det == 0)
    return HXT_STATUS_ERROR;
    
  double invDet = 1.0 / *det;
  
  for(i = 0; i < 16; i++)
    invOut[i] = inv[i] * invDet;
  
  return HXT_STATUS_OK;
}

HXTStatus hxtJacobianLinTet(double *x , double *y, double *z , double mat[3][3]){
  mat[0][0] = x[1] - x[0];
  mat[0][1] = x[2] - x[0];
  mat[0][2] = x[3] - x[0];
  mat[1][0] = y[1] - y[0];
  mat[1][1] = y[2] - y[0];
  mat[1][2] = y[3] - y[0];
  mat[2][0] = z[1] - z[0];
  mat[2][1] = z[2] - z[0];
  mat[2][2] = z[3] - z[0];  
  return HXT_STATUS_OK;
}

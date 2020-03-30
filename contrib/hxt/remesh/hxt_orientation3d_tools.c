#include "hxt_orientation3d_tools.h"
#include "hxt_tools.h"
#include "hxt_eigenvectors.h"
#include <math.h>

void normalize6x6(double mat[6][6]){
  double norm=0.0;
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      norm+=mat[i][j]*mat[i][j];
  norm=sqrt(norm);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      mat[i][j]=mat[i][j]/norm;
}

HXTStatus hxtOrientation3DboundaryConstraintMatrix(const double C[9][2], double B[9][9]){
  /* S = C^T C, iS = S^-1 */
  double S[2][2];
  for(uint8_t i=0;i<2;i++){
    for(uint8_t j=0;j<2;j++){
      S[i][j]=0;
      for(uint8_t k=0;k<9;k++){
        S[i][j] += C[k][i] * C[k][j];
      }
    }
  }
  double iS[2][2], dS;
  hxtInv2x2(S, iS, &dS);
  /* INT = (C^T C)^-1 C^T = iS C^T */
  double INT[2][9];
  for(uint8_t i=0;i<2;i++){
    for(uint8_t j=0;j<9;j++){
      INT[i][j]=0;
      for(uint8_t k=0;k<2;k++){
        INT[i][j] += iS[i][k] * C[j][k];
      }
    }
  }
  /* Bint = I - C (C^T C)^-1 C^T = I - C*INT */
  double Bint[9][9];
  for(uint8_t i=0;i<9;i++){
    for(uint8_t j=0;j<9;j++){
      Bint[i][j] = (i == j) ? 1. : 0.;
      for(uint8_t k=0;k<2;k++){
        Bint[i][j] -= C[i][k] * INT[k][j];
      }
    }
  }
  /* B = Bint^T.Bint */
  for(uint8_t i=0;i<9;i++){
    for(uint8_t j=0;j<9;j++){
      B[i][j] = 0.;
      for(uint8_t k=0;k<9;k++){
        B[i][j] += Bint[k][i] * Bint[k][j];
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOrientation3DcombinationOnBorder(double a, double b, double c[9][2], double d[9]){
  double v0Old[9], v1Old[9], v2Old[9];
  double v0[9], v1[9], v2[9];
  double euler[3]={a,b,0};
  hxtOrientation3DeulerToFrame(v0Old, euler);
  oldBasisToNewBasis(v0Old, v0);
  /* hxtOrientation3DeulerToFrame(v0, euler); */
  euler[2]=M_PI/8;
  hxtOrientation3DeulerToFrame(v1Old, euler);
  oldBasisToNewBasis(v1Old, v1);
  /* hxtOrientation3DeulerToFrame(v1, euler); */
  euler[2]=M_PI/4;
  hxtOrientation3DeulerToFrame(v2Old, euler);
  oldBasisToNewBasis(v2Old, v2);
  /* hxtOrientation3DeulerToFrame(v2, euler); */
  for (int i=0;i<9;i++){
    d[i]    = 0.5*(v0[i]+v2[i]);
    c[i][0] = v0[i]-d[i];
    c[i][1] = v1[i]-d[i];
  }
  return HXT_STATUS_OK;
}

void hxtOrientation3DeulerAnglesOfNormal(const double *n, double* alpha, double* beta){
  /* Euler angles assuming e_z is transformed to the normal n */
  const double eps = 1.e-12;
  if (fabs(n[2] - 1.) < eps) {
    *alpha = 0;
    *beta = 0;
  } else if (fabs(n[2] + 1.) < eps) {
    *alpha = 0;
    *beta =  M_PI;
  }
  else {
    *alpha = atan2(-n[0],n[1]);
    if (fabs(cos(*alpha)) < eps){
      /* *beta = acos(n[2]); */
      *beta = atan2(n[0]/sin(*alpha),n[2]);
    }
    else
      *beta = atan2(-n[1]/cos(*alpha),n[2]);
  }
}

HXTStatus hxtOrientation3DgradBoundary(const double *B, const double D[9], const double frame[9], double grad[9]){
  for(uint8_t i=0;i<9;i++){
    grad[i]=0.0;
    for(uint8_t k=0;k<9;k++){
      grad[i] += B[i*9+k] * (frame[k]-D[k]);
    }
  }
  return HXT_STATUS_OK;
}

void hxtOrientation3DgradPenaltyComp(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9], int k, int l){
  for (int i = 0; i < 9; ++i)
    grad[i]=0.0;
  double L[6][6]={0.0};
  double a[10]={0.0};
  for (int i = 0; i < 9; ++i)
    a[i]=frame[i];
  a[9]=sqrt(9.0/5.0);
  for (int i = 0; i < 10; ++i){
    L[k][l]-=a[i]*base[k][l][i];
    for (int j = 0; j < 10; ++j)
      L[k][l]+=a[i]*a[j]*crossProdBase[i][j][k][l];
  }
  double Gtilde[9][6][6]={0.0};
  for (int m = 0; m < 9; ++m){
    Gtilde[m][k][l]-=base[k][l][m];
    for (int i = 0; i < 10; ++i)
      Gtilde[m][k][l]+=a[i]*(crossProdBaseSym[m][i][k][l]);
  }
  for (int m = 0; m < 9; ++m)
    grad[m]+=L[k][l]*Gtilde[m][k][l];
  return;
}

void hxtOrientation3DgradPenalty(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9]){
  for (int i = 0; i < 9; ++i)
    grad[i]=0.0;
  double L[6][6]={0.0};
  double a[10]={0.0};
  for (int i = 0; i < 9; ++i)
    a[i]=frame[i];
  a[9]=sqrt(9.0/5.0);
  for (int k = 0; k < 6; ++k)
    for (int l = k; l < 6; ++l)
      for (int i = 0; i < 10; ++i){
        L[k][l]-=a[i]*base[k][l][i];
        for (int j = 0; j < 10; ++j)
          L[k][l]+=a[i]*a[j]*crossProdBase[i][j][k][l];
      }
  double Gtilde[9][6][6]={0.0};
  for (int k = 0; k < 6; ++k)
    for (int l = k; l < 6; ++l)
      for (int m = 0; m < 9; ++m){
        Gtilde[m][k][l]-=base[k][l][m];
        for (int i = 0; i < 10; ++i)
          Gtilde[m][k][l]+=a[i]*(crossProdBaseSym[m][i][k][l]);
      }
  for (int m = 0; m < 9; ++m)
    for (int k = 0; k < 6; ++k)
      for (int l = k; l < 6; ++l) 
        grad[m]+=L[k][l]*Gtilde[m][k][l];
  return;
}

HXTStatus hxtOrientation3DcrossProdBase(double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6]){
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      for (int k = 0; k < 6; ++k)
        for (int l = 0; l < 6; ++l){
          crossProdBase[i][j][k][l]=0.0;
          crossProdBaseSym[i][j][k][l]=0.0;
        }
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)      
      for (int k = 0; k < 6; ++k)  
        for (int l = 0; l < 6; ++l)
          for (int m = 0; m < 6; ++m){
            crossProdBase[i][j][k][l]+=base[k][m][i]*base[m][l][j];
            crossProdBaseSym[i][j][k][l]+=base[k][m][i]*base[m][l][j]+base[k][m][j]*base[m][l][i];
          }
  return HXT_STATUS_OK;
}

void hxtOrientation3DgetBase(double basis[6][6][10]){
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      for(int k=0;k<9;k++)
        basis[i][j][k]=0.0;

  double alpha = 1.0;
  double beta = 0.5*(sqrt(70)-8)*alpha;
  double B1[6][6]={{alpha,-0.5*alpha,-0.5*alpha,0.0,0.0,0.0},
    {-0.5*alpha,beta,0.5*alpha-beta,0.0,0.0,0.0},
    {-0.5*alpha,0.5*alpha-beta,beta,0.0,0.0,0.0},
    {0.0,0.0,0.0,alpha-2*beta,0.0,0.0},
    {0.0,0.0,0.0,0.0,-alpha,0.0},
    {0.0,0.0,0.0,0.0,0.0,-alpha}};
  normalize6x6(B1);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][0]=B1[i][j];

  double B2[6][6] = {{beta,-0.5*alpha,0.5*alpha-beta,0.0,0.0,0.0},
    {-0.5*alpha,alpha,-0.5*alpha,0.0,0.0,0.0},
    {0.5*alpha-beta,-0.5*alpha,beta,0.0,0.0,0.0},
    {0.0,0.0,0.0,-alpha,0.0,0.0},
    {0.0,0.0,0.0,0.0,alpha-2*beta,0.0},
    {0.0,0.0,0.0,0.0,0.0,-alpha}};
  normalize6x6(B2);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][1]=B2[i][j];

  double B3[6][6] = {{beta,0.5*alpha-beta,-0.5*alpha,0.0,0.0,0.0},
    {0.5*alpha-beta,beta,-0.5*alpha,0.0,0.0,0.0},
    {-0.5*alpha,-0.5*alpha,alpha,0.0,0.0,0.0},
    {0.0,0.0,0.0,-alpha,0.0,0.0},
    {0.0,0.0,0.0,0.0,-alpha,0.0},
    {0.0,0.0,0.0,0.0,0.0,alpha-2*beta}};
  normalize6x6(B3);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][2]=B3[i][j];

  alpha = 1.0;
  beta = alpha*(sqrt(7)-4.0)/3.0;
  double B4[6][6] = {{0.0,0.0,0.0,-(alpha+beta),0.0,0.0},
    {0.0,0.0,0.0,alpha,0.0,0.0},
    {0.0,0.0,0.0,beta,0.0,0.0},
    {-(alpha+beta),alpha,beta,0.0,0.0,0.0},
    {0.0,0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta)},
    {0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0}};
  normalize6x6(B4);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][3]=B4[i][j];

  double B5[6][6] = {{0.0,0.0,0.0,-(alpha+beta),0.0,0.0},
    {0.0,0.0,0.0,beta,0.0,0.0},
    {0.0,0.0,0.0,alpha,0.0,0.0},
    {-(alpha+beta),beta,alpha,0.0,0.0,0.0},
    {0.0,0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta)},
    {0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0}};
  normalize6x6(B5);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][4]=B5[i][j];

  double B6[6][6] = {{0.0,0.0,0.0,0.0,alpha,0.0},
    {0.0,0.0,0.0,0.0,-(alpha+beta),0.0},
    {0.0,0.0,0.0,0.0,beta,0.0},
    {0.0,0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta)},
    {alpha,-(alpha+beta),beta,0.0,0.0,0.0},
    {0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0,0.0}};
  normalize6x6(B6);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][5]=B6[i][j];

  double B7[6][6] = {{0.0,0.0,0.0,0.0,beta,0.0},
    {0.0,0.0,0.0,0.0,-(alpha+beta),0.0},
    {0.0,0.0,0.0,0.0,alpha,0.0},
    {0.0,0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta)},
    {beta,-(alpha+beta),alpha,0.0,0.0,0.0},
    {0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0,0.0}};
  normalize6x6(B7);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][6]=B7[i][j];

  double B8[6][6] = {{0.0,0.0,0.0,0.0,0.0,alpha},
    {0.0,0.0,0.0,0.0,0.0,beta},
    {0.0,0.0,0.0,0.0,0.0,-(alpha+beta)},
    {0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0},
    {0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0,0.0},
    {alpha,beta,-(alpha+beta),0.0,0.0,0.0}};
  normalize6x6(B8);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][7]=B8[i][j];

  double B9[6][6] = {{0.0,0.0,0.0,0.0,0.0,beta},
    {0.0,0.0,0.0,0.0,0.0,alpha},
    {0.0,0.0,0.0,0.0,0.0,-(alpha+beta)},
    {0.0,0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0},
    {0.0,0.0,0.0,-sqrt(2)*(alpha+beta),0.0,0.0},
    {beta,alpha,-(alpha+beta),0.0,0.0,0.0}};
  normalize6x6(B9);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][8]=B9[i][j];

  double B10[6][6] = {{3.0,1.0,1.0,0.0,0.0,0.0},
    {1.0,3.0,1.0,0.0,0.0,0.0},
    {1.0,1.0,3.0,0.0,0.0,0.0},
    {0.0,0.0,0.0,2.0,0.0,0.0},
    {0.0,0.0,0.0,0.0,2.0,0.0},
    {0.0,0.0,0.0,0.0,0.0,2.0}};
  normalize6x6(B10);
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      basis[i][j][9]=B10[i][j];
}

//Conversion from new basis to old basis
void newBasisToOldBasis(double *sol, double *solRef){
  double alpha=1.0;
  double beta=0.5*(sqrt(70)-8)*alpha;
  double matBtoA[3][3]={0.0};
  double matBtoA2[2][2]={0.0};
  double invMatBtoA[3][3]={0.0};
  double invMatBtoA2[2][2]={0.0};
  double det=0.0;
  double norm=sqrt(3*alpha*alpha+(alpha-2*beta)*(alpha-2*beta)+2*beta*beta+4*(0.5*alpha)*(0.5*alpha)+2*(0.5*alpha-beta)*(0.5*alpha-beta));
  matBtoA[0][0]=alpha/norm;
  matBtoA[0][1]=beta/norm;
  matBtoA[0][2]=beta/norm;
  matBtoA[1][0]=beta/norm;
  matBtoA[1][1]=alpha/norm;
  matBtoA[1][2]=beta/norm;
  matBtoA[2][0]=beta/norm;
  matBtoA[2][1]=beta/norm;
  matBtoA[2][2]=alpha/norm;
  /* hxtInv3x3(matBtoA, invMatBtoA, &det); */
  for(int i=0;i<9;i++)
    solRef[i]=0.0;
  for(int i=0;i<3;i++)
    solRef[i]=3.0/5.0;
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      /* solRef[i]+=invMatBtoA[i][k]*sol[k]; */
      solRef[i]+=matBtoA[i][k]*sol[k];
    }
  }
  alpha = 1.0;
  beta = alpha*(sqrt(7)-4.0)/3.0;
  norm = sqrt(2*(3*(alpha+beta)*(alpha+beta)+alpha*alpha+beta*beta))*sqrt(2.0);
  matBtoA2[0][0]=-(alpha+beta)/norm;
  matBtoA2[0][1]=-(alpha+beta)/norm;
  matBtoA2[1][0]=alpha/norm;
  matBtoA2[1][1]=beta/norm;
  /* hxtInv2x2(matBtoA2, invMatBtoA2, &det); */
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      /* solRef[i+3]+=invMatBtoA2[i][k]*sol[k+3]; */
      solRef[i+3]+=matBtoA2[i][k]*sol[k+3];
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=-(alpha+beta)/norm;
  matBtoA2[1][1]=-(alpha+beta)/norm;
  /* hxtInv2x2(matBtoA2, invMatBtoA2, &det); */
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      /* solRef[i+5]+=invMatBtoA2[i][k]*sol[k+5]; */
      solRef[i+5]+=matBtoA2[i][k]*sol[k+5];
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=beta/norm;
  matBtoA2[1][1]=alpha/norm;
  /* hxtInv2x2(matBtoA2, invMatBtoA2, &det); */
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      /* solRef[i+7]+=invMatBtoA2[i][k]*sol[k+7]; */
      solRef[i+7]+=matBtoA2[i][k]*sol[k+7];
    }
  }
}

//Conversion from old basis to new basis
void oldBasisToNewBasis(double *sol, double *solRef){
  double alpha=1.0;
  double beta=0.5*(sqrt(70)-8)*alpha;
  double matBtoA[3][3]={0.0};
  double matBtoA2[2][2]={0.0};
  double invMatBtoA[3][3]={0.0};
  double invMatBtoA2[2][2]={0.0};
  double det=0.0;
  double solForInv[9]={0.0};
  for(int i=0;i<9;i++)
    solForInv[i]=sol[i];
  for(int i=0;i<3;i++)
    solForInv[i]-=3.0/5.0;
  double norm=sqrt(3*alpha*alpha+(alpha-2*beta)*(alpha-2*beta)+2*beta*beta+4*(0.5*alpha)*(0.5*alpha)+2*(0.5*alpha-beta)*(0.5*alpha-beta));
  matBtoA[0][0]=alpha/norm;
  matBtoA[0][1]=beta/norm;
  matBtoA[0][2]=beta/norm;
  matBtoA[1][0]=beta/norm;
  matBtoA[1][1]=alpha/norm;
  matBtoA[1][2]=beta/norm;
  matBtoA[2][0]=beta/norm;
  matBtoA[2][1]=beta/norm;
  matBtoA[2][2]=alpha/norm;
  hxtInv3x3(matBtoA, invMatBtoA, &det);
  for(int i=0;i<9;i++)
    solRef[i]=0.0;

  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      solRef[i]+=invMatBtoA[i][k]*solForInv[k];
      /* solRef[i]+=matBtoA[i][k]*sol[k]; */
    }
  }
  alpha = 1.0;
  beta = alpha*(sqrt(7)-4.0)/3.0;
  norm = sqrt(2*(3*(alpha+beta)*(alpha+beta)+alpha*alpha+beta*beta))*sqrt(2);
  matBtoA2[0][0]=-(alpha+beta)/norm;
  matBtoA2[0][1]=-(alpha+beta)/norm;
  matBtoA2[1][0]=alpha/norm;
  matBtoA2[1][1]=beta/norm;
  hxtInv2x2(matBtoA2, invMatBtoA2, &det);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      solRef[i+3]+=invMatBtoA2[i][k]*solForInv[k+3];
      /* solRef[i+3]+=matBtoA2[i][k]*sol[k+3]; */
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=-(alpha+beta)/norm;
  matBtoA2[1][1]=-(alpha+beta)/norm;
  hxtInv2x2(matBtoA2, invMatBtoA2, &det);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      solRef[i+5]+=invMatBtoA2[i][k]*solForInv[k+5];
      /* solRef[i+5]+=matBtoA2[i][k]*sol[k+5]; */
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=beta/norm;
  matBtoA2[1][1]=alpha/norm;
  hxtInv2x2(matBtoA2, invMatBtoA2, &det);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      solRef[i+7]+=invMatBtoA2[i][k]*solForInv[k+7];
      /* solRef[i+7]+=matBtoA2[i][k]*sol[k+7]; */
    }
  }
}

// Frobenius norm of 3x3 symmetric matrix
void hxtOrientation3DfrobNormMatSym3x3(double *frobNorm, double *mat)
{
  double rotMat[3*3];
  double vp3[3];
  hxtEigenvectors3(mat, vp3, rotMat);
  *frobNorm=sqrt(vp3[0]*vp3[0]+vp3[1]*vp3[1]+vp3[2]*vp3[2]);
}

// representation Mandel 9x1 -> matrice 3x3 sym
void hxtOrientation3Dmat3x3ToMandel2nd(double *mandel2nd, double *mat)
{
  double s = sqrt(2);
  mandel2nd[0] = mat[0*3+0];
  mandel2nd[1] = mat[1*3+1];
  mandel2nd[2] = mat[2*3+2];
  mandel2nd[3] = s*mat[1*3+2];
  mandel2nd[4] = s*mat[2*3+0];
  mandel2nd[5] = s*mat[1*3+0];  
}

// representation Mandel 9x1 -> matrice 3x3 sym
void hxtOrientation3Dmandel2ndToMat3x3(double *tens2, double *vectDir)
{
  double s = sqrt(2);
  tens2[0*3+0] = vectDir[0];
  tens2[0*3+1] = vectDir[5]/s;
  tens2[0*3+2] = vectDir[4]/s;
  tens2[1*3+0] = vectDir[5]/s;
  tens2[2*3+0] = vectDir[4]/s;
  tens2[1*3+1] = vectDir[1];
  tens2[1*3+2] = vectDir[3]/s;
  tens2[2*3+1] = vectDir[3]/s;
  tens2[2*3+2] = vectDir[2];
}

// frame 9x1 -> representation Mandel 6x6
void hxtOrientation3DframeToMandel4th(double *D, const double *vectA)
{
  double s = sqrt(2.);
  D[0*6+0] = vectA[0];
  D[0*6+1] = 0.5*(1+vectA[2]-vectA[0]-vectA[1]);
  D[0*6+2] = 0.5*(1+vectA[1]-vectA[0]-vectA[2]);
  D[0*6+3] = s*vectA[3];
  D[0*6+4] = s*vectA[5];
  D[0*6+5] = s*vectA[7];

  D[1*6+0] = D[0*6+1];
  D[1*6+1] = vectA[1];
  D[1*6+2] = 0.5*(1+vectA[0]-vectA[2]-vectA[1]);
  D[1*6+3] = s*vectA[4];
  D[1*6+4] = s*vectA[6];
  D[1*6+5] = s*vectA[8];

  D[2*6+0] = D[0*6+2];
  D[2*6+1] = D[1*6+2];
  D[2*6+2] = vectA[2];
  D[2*6+3] = -s*(vectA[3]+vectA[4]);
  D[2*6+4] = -s*(vectA[5]+vectA[6]);
  D[2*6+5] = -s*(vectA[7]+vectA[8]);

  D[3*6+0] = D[0*6+3];
  D[3*6+1] = D[1*6+3];
  D[3*6+2] = D[2*6+3];
  D[3*6+3] = s*s*0.5*(1+vectA[0]-vectA[2]-vectA[1]);
  D[3*6+4] = -s*s*(vectA[7]+vectA[8]);
  D[3*6+5] = s*s*vectA[6];

  D[4*6+0] = D[0*6+4];
  D[4*6+1] = D[1*6+4];
  D[4*6+2] = D[2*6+4];
  D[4*6+3] = D[3*6+4];
  D[4*6+4] = s*s*0.5*(1+vectA[1]-vectA[0]-vectA[2]);
  D[4*6+5] = s*s*vectA[3];

  D[5*6+0] = D[0*6+5];
  D[5*6+1] = D[1*6+5];
  D[5*6+2] = D[2*6+5];
  D[5*6+3] = D[3*6+5];
  D[5*6+4] = D[4*6+5];
  D[5*6+5] = s*s*0.5*(1+vectA[2]-vectA[0]-vectA[1]);
}

// representation Mandel 6x6 -> frame 9x1
void hxtOrientation3Dmandel4thToFrame(double *vectA, double *D)
{
  double s = sqrt(2);
  vectA[0] = D[0*6+0];
  vectA[1] = D[1*6+1];
  vectA[2] = D[2*6+2];
  vectA[3] = D[0*6+3]/s;
  vectA[4] = D[1*6+3]/s;
  vectA[5] = D[0*6+4]/s;
  vectA[6] = D[1*6+4]/s;
  vectA[7] = D[0*6+5]/s;
  vectA[8] = D[1*6+5]/s;
}

// angles euler ZXZ -> matrice rotation 3x3
void hxtOrientation3DeulerToMatRot3x3(double *rotMat, double *euler)
{
  double c1 = cos(euler[0]);
  double s1 = sin(euler[0]);
  double c2 = cos(euler[1]);
  double s2 = sin(euler[1]);
  double c3 = cos(euler[2]);
  double s3 = sin(euler[2]);
  rotMat[0*3+0] = c1*c3-c2*s1*s3;
  rotMat[0*3+1] = -c1*s3-c3*c2*s1;
  rotMat[0*3+2] = s2*s1;
  rotMat[1*3+0] = c2*c1*s3+c3*s1;
  rotMat[1*3+1] = c1*c2*c3-s1*s3;
  rotMat[1*3+2] = -c1*s2;
  rotMat[2*3+0] = s3*s2;
  rotMat[2*3+1] = c3*s2;
  rotMat[2*3+2] = c2;
}

// matrice rotation 3x3 -> representation Mandel 6x6 de l'opérateur de rotation d'ordre 4
void hxtOrientation3DmatRot3x3ToMandelRot4th(double *Rv, double *R)
{
  double s = sqrt(2);
  Rv[0*6+0] = R[0*3+0]*R[0*3+0];
  Rv[0*6+1] = R[0*3+1]*R[0*3+1];
  Rv[0*6+2] = R[0*3+2]*R[0*3+2];
  Rv[0*6+3] = s*R[0*3+1]*R[0*3+2];
  Rv[0*6+4] = s*R[0*3+0]*R[0*3+2];
  Rv[0*6+5] = s*R[0*3+0]*R[0*3+1];

  Rv[1*6+0] = R[1*3+0]*R[1*3+0];
  Rv[1*6+1] = R[1*3+1]*R[1*3+1];
  Rv[1*6+2] = R[1*3+2]*R[1*3+2];
  Rv[1*6+3] = s*R[1*3+1]*R[1*3+2];
  Rv[1*6+4] = s*R[1*3+0]*R[1*3+2];
  Rv[1*6+5] = s*R[1*3+1]*R[1*3+0];

  Rv[2*6+0] = R[2*3+0]*R[2*3+0];
  Rv[2*6+1] = R[2*3+1]*R[2*3+1];
  Rv[2*6+2] = R[2*3+2]*R[2*3+2];
  Rv[2*6+3] = s*R[2*3+2]*R[2*3+1];
  Rv[2*6+4] = s*R[2*3+2]*R[2*3+0];
  Rv[2*6+5] = s*R[2*3+0]*R[2*3+1];

  Rv[3*6+0] = s*R[1*3+0]*R[2*3+0];
  Rv[3*6+1] = s*R[1*3+1]*R[2*3+1];
  Rv[3*6+2] = s*R[1*3+2]*R[2*3+2];
  Rv[3*6+3] = R[1*3+1]*R[2*3+2]+R[1*3+2]*R[2*3+1];
  Rv[3*6+4] = R[1*3+0]*R[2*3+2]+R[1*3+2]*R[2*3+0];
  Rv[3*6+5] = R[1*3+1]*R[2*3+0]+R[1*3+0]*R[2*3+1];

  Rv[4*6+0] = s*R[0*3+0]*R[2*3+0];
  Rv[4*6+1] = s*R[0*3+1]*R[2*3+1];
  Rv[4*6+2] = s*R[0*3+2]*R[2*3+2];
  Rv[4*6+3] = R[0*3+1]*R[2*3+2]+R[0*3+2]*R[2*3+1];
  Rv[4*6+4] = R[0*3+2]*R[2*3+0]+R[0*3+0]*R[2*3+2];
  Rv[4*6+5] = R[0*3+0]*R[2*3+1]+R[0*3+1]*R[2*3+0];

  Rv[5*6+0] = s*R[0*3+0]*R[1*3+0];
  Rv[5*6+1] = s*R[0*3+1]*R[1*3+1];
  Rv[5*6+2] = s*R[0*3+2]*R[1*3+2];
  Rv[5*6+3] = R[0*3+1]*R[1*3+2]+R[0*3+2]*R[1*3+1];
  Rv[5*6+4] = R[0*3+2]*R[1*3+0]+R[0*3+0]*R[1*3+2];
  Rv[5*6+5] = R[0*3+0]*R[1*3+1]+R[0*3+1]*R[1*3+0];  
}

// angle euler ZXZ -> frame 9x1
void hxtOrientation3DeulerToFrame(double *cross, double *euler)
{
  hxtDeclareAligned double Rv[36];

  double matRot[9];
  double vectRef[9]={1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0};
  hxtDeclareAligned double crossTensRef[36];
  hxtDeclareAligned double crossTens[36];
  hxtDeclareAligned double Rvt[36];
  hxtDeclareAligned double crossTensRefRvt[36] = {0.0};

  hxtOrientation3DeulerToMatRot3x3(matRot, euler);
  hxtOrientation3DmatRot3x3ToMandelRot4th(Rv, matRot);
  hxtOrientation3DframeToMandel4th(crossTensRef, vectRef);

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      Rvt[6*i + j] = Rv[6*j + i];

  for (int k = 0; k < 6; k++)
    for (int l = 0; l < 6; l++)
      for (int j = 0; j < 6; j++)
        crossTensRefRvt[k*6+j] += crossTensRef[k*6+l] * Rvt[l*6+j];

  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++) {
      crossTens[i*6+j] = 0.0;
    }
  }

  for (int i=0; i < 6; i++)
    for (int k=0; k < 6; k++)
      for (int j=0; j < 6; j++)
        crossTens[i*6+j] += Rv[i*6+k]*crossTensRefRvt[k*6+j];

  /* for (int i=0; i < 6; i++) */
  /*   for (int j=0; j < 6; j++) */
  /*     for (int k=0; k < 6; k++) */
  /* 	for (int l=0; l < 6; l++) */
  /* 	  crossTens[i*6+j] += Rv[i*6+k]*crossTensRef[k*6+l]*Rvt[l*6+j]; */

  hxtOrientation3Dmandel4thToFrame(cross,crossTens);
}

// 3 directions orthogonale normalisées -> frame 9x1
void hxtOrientation3DdirectionsToFrame(double *cross, double *dirCross)
{
  hxtDeclareAligned double Rv[36];

  double matRot[9];
  double vectRef[9]={1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0};
  hxtDeclareAligned double crossTensRef[36];
  hxtDeclareAligned double crossTens[36];
  hxtDeclareAligned double Rvt[36];
  hxtDeclareAligned double crossTensRefRvt[36] = {0.0};

  for(int k=0;k<3;k++)
    for(int i=0;i<3;i++)
      matRot[i*3+k] = dirCross[k*3+i];

  hxtOrientation3DmatRot3x3ToMandelRot4th(Rv, matRot);
  hxtOrientation3DframeToMandel4th(crossTensRef, vectRef);

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      Rvt[6*i + j] = Rv[6*j + i];

  for (int k = 0; k < 6; k++)
    for (int l = 0; l < 6; l++)
      for (int j = 0; j < 6; j++)
        crossTensRefRvt[k*6+j] += crossTensRef[k*6+l] * Rvt[l*6+j];

  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++) {
      crossTens[i*6+j] = 0.0;
    }
  }

  for (int i=0; i < 6; i++)
    for (int k=0; k < 6; k++)
      for (int j=0; j < 6; j++)
        crossTens[i*6+j] += Rv[i*6+k]*crossTensRefRvt[k*6+j];

  hxtOrientation3Dmandel4thToFrame(cross,crossTens);
}

// normale + un angle de rotation autour de celle-ci -> frame 9x1
void hxtOrientation3DnormalEulerToFrame(double *cross, double *normal, double gamma)
{
  double a = normal[0];
  double b = normal[1];
  double c = normal[2];

  if(sqrt(b*b+c*c)<1e-8){
    double cosGamma4 = pow(cos(gamma),4);
    double sinGamma4 = pow(sin(gamma),4);
    cross[0] = 1.;
    cross[1] = cosGamma4+sinGamma4;
    cross[2] = cosGamma4+sinGamma4;
    cross[3] = 0.;
    cross[4] = sin(4*gamma)/4.;
    cross[5] = 0.;
    cross[6] = 0.;
    cross[7] = 0.;
    cross[8] = 0.;
  }
  else if(sqrt(b*b+a*a)<1e-8){
    double cosGamma4 = pow(cos(gamma),4);
    double sinGamma4 = pow(sin(gamma),4);
    cross[0] = cosGamma4+sinGamma4;
    cross[1] = cosGamma4+sinGamma4;
    cross[2] = 1.0;
    cross[3] = 0.;
    cross[4] = 0.;
    cross[5] = 0.;
    cross[6] = 0.;
    cross[7] = sin(4*gamma)/4.;
    cross[8] = -sin(4*gamma)/4.;
  }
  else{
    double gammaCorr = atan2(-b,(a*c));
    double sgn = b/fabs(b);
    double cos4Gamma = cos(4*(sgn*gamma-gammaCorr));
    double sin4Gamma = sin(4*(sgn*gamma-gammaCorr));

    double a4 = pow(a,4);
    double a3 = pow(a,3);
    double a2 = pow(a,2);
    double b8 = pow(b,8);
    double b6 = pow(b,6);
    double b4 = pow(b,4);
    double b3 = pow(b,3);
    double b2 = pow(b,2);
    double c8 = pow(c,8);
    double c6 = pow(c,6);
    double c5 = pow(c,5);
    double c4 = pow(c,4);
    double c3 = pow(c,3);
    double c2 = pow(c,2);

    cross[0] = a4 + (pow(b2 + c2,2)*(3 + cos4Gamma))/4.;

    cross[1] = (3*a4*b4 + 4*b8 + 6*a2*b2*c2 +
        8*b6*c2 + (3 + 4*b4)*c4 +
        (a4*b4 - 6*a2*b2*c2 + c4)*cos4Gamma +
        4*a*b*c*(-(a2*b2) + c2)*sin4Gamma)/
      (4.*pow(b2 + c2,2));

    cross[2] = (3*a4*c4 + 4*c8 + b4*(3 + 4*c4) +
        b2*(6*a2*c2 + 8*c6) +
        (b4 - 6*a2*b2*c2 + a4*c4)*cos4Gamma -
        4*a*b*c*(b - a*c)*(b + a*c)*sin4Gamma)/(4.*pow(b2 + c2,2));

    cross[3] = (b*c*(-1 + 7*a2 + (1 + a2)*cos4Gamma) + a*(b - c)*(b + c)*sin4Gamma)/4.;

    cross[4] = (b3*(-3*a2 + 3*a4 + 4*b4)*c +
        b*(-3 + 3*a2 + 8*b4)*c3 + 4*b3*c5 +
        b*c*(a2*(3 + a2)*b2 - (1 + 3*a2)*c2)*cos4Gamma +
        a*(a2*b4 - 3*(1 + a2)*b2*c2 + c4)*sin4Gamma)
      /(4.*pow(b2 + c2,2));

    cross[5] = a3*c - (3*a*c*(b2 + c2))/4. -
      ((b2 + c2)*(a*c*cos4Gamma + b*sin4Gamma))/4.;

    cross[6] = (a*b2*(2 - 3*a2 + 4*b2)*c + a*(-1 + 4*b2)*c3 +
        a*c*(-((2 + a2)*b2) + c2)*cos4Gamma +
        b*(c2 - a2*(b2 - 2*c2))*sin4Gamma)/
      (4.*(b2 + c2));

    cross[7] = a3*b - (3*a*b*(b2 + c2))/4. -
      ((b2 + c2)*(a*b*cos4Gamma - c*sin4Gamma))/4.;

    cross[8] = (a*b*(-3*a2*b2 + 4*b4 + (-3 + 4*b2)*c2 +
          (-(a2*b2) + 3*c2)*cos4Gamma) -
        c*(-3*a2*b2 + c2)*sin4Gamma)/(4.*(b2 + c2));
  }
}

/* void hxtOrientation3DnormalEulerToFrame(double *cross, double *normal, double gamma) */
/* { */
/*   double a,b; */
/*   hxtOrientation3DeulerAnglesOfNormal(normal, &a, &b); */
/*   double C[9][2]; */
/*   double D[9]; */
/*   hxtOrientation3DcombinationOnBorder2(a, b, C, D); */
/*   double v[2]={cos(gamma),sin(gamma)}; */
/*   for(int k=0;k<9;k++){ */
/*     cross[k]=0.0; */
/*     for(int i=0;i<2;i++){ */
/*       cross[k]=C[k][i]*v[i]+D[k]; */
/*     } */
/*   } */
/* } */

void hxtOrientation3Dvec3ToMandel2nd(double *mandel2nd, double *vect){
  double mat3x3[9]={0.0};
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      mat3x3[3*i+j]=vect[i]*vect[j];
  hxtOrientation3Dmat3x3ToMandel2nd(mandel2nd, mat3x3); 
}

// projection frame 9x1 -> 3 directions orthogonales
HXTStatus hxtOrientation3DframeToDirections(double *dirFinal, double *stableDir, const double *cross)
{
  double mat[6*6];
  double dirPropres[6*6];
  double vpMat[6];
  double R4[6];
  double R5[6];
  double v4[3*3];
  double v5[3*3];
  double r4[3*3];
  double r5[3*3];
  double vp3[3];

  // move to voigt
  hxtOrientation3DframeToMandel4th(mat,cross);
  //  remove eigenvalue 1
  for (int i=0;i<3;i++){
    mat[0 +i]  -= (1./3.);
    mat[6 +i]  -= (1./3.);
    mat[12+i]  -= (1./3.);
  }
  //  get eigentensors
  hxtEigenvectors6(mat, vpMat, dirPropres);

  //  printf("EIGS %g %g %g %g %g %g \n",
  //	 vpMat[0],vpMat[1],vpMat[2],
  //	 vpMat[3],vpMat[4],vpMat[5]);


  // take the 2 ones
  for(int j=0;j<6;j++){
    R4[j] = dirPropres[j*6+4];
    R5[j] = dirPropres[j*6+5];
  }
  // mv to tensors of order 2
  hxtOrientation3Dmandel2ndToMat3x3(v4, R4);
  hxtOrientation3Dmandel2ndToMat3x3(v5, R5);

  // compute the 2 basis
  hxtEigenvectors3(v4, vp3, r4);
  hxtEigenvectors3(v5, vp3, r5);

  // compute rotations
  double r4tV4r4[3*3]={0.0};
  double r4tV5r4[3*3]={0.0};
  double r5tV4r5[3*3]={0.0};
  double r5tV5r5[3*3]={0.0};
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      for(int l=0;l<3;l++){
        r4tV5r4[3*i+i]+=r4[3*k+i]*v5[3*k+l]*r4[3*l+i];
        r5tV4r5[3*i+i]+=r5[3*k+i]*v4[3*k+l]*r5[3*l+i];
        r4tV4r4[3*i+i]+=r4[3*k+i]*v4[3*k+l]*r4[3*l+i];
        r5tV5r5[3*i+i]+=r5[3*k+i]*v5[3*k+l]*r5[3*l+i];	
      }
    }
  }

  // Choose the best one
  double frobNorm454=0.0;
  double frobNorm545=0.0;
  double frobNorm444=0.0;
  double frobNorm555=0.0;
  hxtOrientation3DfrobNormMatSym3x3(&frobNorm454, r4tV5r4);
  hxtOrientation3DfrobNormMatSym3x3(&frobNorm545, r5tV4r5);
  hxtOrientation3DfrobNormMatSym3x3(&frobNorm444, r4tV4r4);
  hxtOrientation3DfrobNormMatSym3x3(&frobNorm555, r5tV5r5);
  double *rFinal;
  if(frobNorm454+frobNorm444>frobNorm545+frobNorm555)
    rFinal=r4;
  else
    rFinal=r5;

  /* printf("R4\n"); */
  /* printf("%12.5E %12.5E %12.5E\n",r4[0],r4[1],r4[2]); */
  /* printf("%12.5E %12.5E %12.5E\n",r4[3],r4[4],r4[5]); */
  /* printf("%12.5E %12.5E %12.5E\n",r4[6],r4[7],r4[8]); */
  /* printf("R5\n"); */
  /* printf("%12.5E %12.5E %12.5E\n",r5[0],r5[1],r5[2]); */
  /* printf("%12.5E %12.5E %12.5E\n",r5[3],r5[4],r5[5]); */
  /* printf("%12.5E %12.5E %12.5E\n",r5[6],r5[7],r5[8]); */
  /* printf("RFinal\n"); */
  /* printf("%12.5E %12.5E %12.5E\n",rFinal[0],rFinal[1],rFinal[2]); */
  /* printf("%12.5E %12.5E %12.5E\n",rFinal[3],rFinal[4],rFinal[5]); */
  /* printf("%12.5E %12.5E %12.5E\n",rFinal[6],rFinal[7],rFinal[8]); */

  for (int i=0;i<9;i++){
    dirFinal[i] = rFinal[i];
  }
  if(stableDir!=NULL){
    for (int i=0;i<3;i++){
      mat[0 +i]  += (1./3.);
      mat[6 +i]  += (1./3.);
      mat[12+i]  += (1./3.);
    }
    for(int i=0; i<3; i++){
      double mandel2ndDir[6];
      double dir[3];
      for(int k=0; k<3; k++)
        dir[k]=dirFinal[3*k+i];
      /* printf("dir : %g %g %g\n",dir[0],dir[1],dir[2]); */
      hxtOrientation3Dvec3ToMandel2nd(mandel2ndDir, dir);
      /* printf("mandel : %g %g %g %g %g %g\n",mandel2ndDir[0],mandel2ndDir[1],mandel2ndDir[2],mandel2ndDir[3],mandel2ndDir[4],mandel2ndDir[5]); */
      double imMandel2ndDir[6]={0.0};
      for(int k=0; k<6; k++)
        for(int m=0; m<6; m++)
          imMandel2ndDir[k]+=mat[6*k+m]*mandel2ndDir[m];
      /* printf("imMandel : %g %g %g %g %g %g\n",imMandel2ndDir[0],imMandel2ndDir[1],imMandel2ndDir[2],imMandel2ndDir[3],imMandel2ndDir[4],imMandel2ndDir[5]); */
      double scalarP=0.0;
      for(int k=0; k<6; k++)
        scalarP+=imMandel2ndDir[k]*mandel2ndDir[k];
      /* printf("scalarP : %g\n",scalarP); */
      /* exit(0); */
      stableDir[i]=scalarP;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOrientation3DframeToEuler(double *euler, double *flagNotUnique, const double *frame)
{
  double directions[9]={0.0};
  double stableDir[3]={0.0};
  hxtOrientation3DframeToDirections(directions, stableDir, frame);
  // DBG check here if u,v,w is direct
  double *u=directions;
  double *v=directions+3;
  double *w=directions+6;
  double phi=0.0;
  double theta=0.0;
  double psi=0.0;

  int flagNoNutation=1;
  double sign=0.0;
  double phiPlusPsi=0.0;
  if(fabs(w[0])>1e-5 || fabs(w[1])>1e-5)
    flagNoNutation=0;

  if(flagNoNutation){
    if(w[2]<0){
      theta=M_PI;
      sign=-1.0;
    }
    else{
      theta=0;
      sign=1.0;
    }
    phiPlusPsi=atan2(u[1],u[0]);
    phi=phiPlusPsi;
    psi=0.0;
    euler[0]=phi;
    euler[1]=theta;
    euler[2]=psi;
  }
  else{
    phi = atan2(u[2],v[2]);    
    psi = atan2(w[0],-w[1]);
    if(cos(phi)>0.01)
      theta=atan2(v[2],w[2]);
    else
      theta=atan2(u[2],w[2]);
    euler[0]=phi;
    euler[1]=theta;
    euler[2]=psi;
  }
  *flagNotUnique=sign;
  return HXT_STATUS_OK;
}

// frame 9x1 -> double quality (||A^2 - A||)
HXTStatus hxtOrientation3DcomputeQuality(const double *frame, double *quality){
  double D[36]={0.0};
  hxtOrientation3DframeToMandel4th(D, frame);
  double D2[36]={0.0};
  for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
      for(int k=0;k<6;k++)
        D2[i*6+j]+=D[i*6+k]*D[k*6+j];
  *quality=0.0;
  for(int i=0;i<36;i++)
    *quality+=(D2[i]-D[i])*(D2[i]-D[i]);
  *quality=sqrt(*quality);
  return HXT_STATUS_OK;
}

HXTStatus hxtOrientation3DgetCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode){
  double *framesElem;
  HXT_CHECK(hxtMalloc(&framesElem, sizeof(double)*4*9));
  for(int k=0;k<4;k++){
    double *frameK=framesElem+9*k;
    double dirK[9]={0.0};
    for(int j=0;j<3;j++)
      for(int l=0;l<3;l++)
        dirK[3*j+l]=directions[9*k+3*j+l];
    hxtOrientation3DdirectionsToFrame(frameK, dirK);
  }
  double xi=coordParam[0];
  double eta=coordParam[1];
  double zeta=coordParam[2];
  double L[4]={0.0};
  L[0]=1-xi-eta-zeta;
  L[1]=xi;
  L[2]=eta;
  L[3]=zeta;
  double frameP[9]={0.0};
  for(int l=0;l<9;l++)
    for(int k=0;k<4;k++)
      frameP[l]+=framesElem[9*k+l]*L[k];
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOrientation3DframeToDirections(refDir, stableDir, frameP);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      dirAtParamNode[3*i+j]=refDir[3*j+i];
  hxtFree(&framesElem);
  return HXT_STATUS_OK;
}

HXTStatus hxtOrientation3DgetScaledCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode){
  double xi=coordParam[0];
  double eta=coordParam[1];
  double zeta=coordParam[2];
  double directionsNormalized[9*4]={0.0};
  double normDir[4*3]={0.0};
  for(int l=0;l<4;l++){
    for(int k=0;k<3;k++){
      double normDirK=0.0;
      for(int i=0;i<3;i++)
        normDirK+=directions[9*l+3*k+i]*directions[9*l+3*k+i];
      normDirK=sqrt(normDirK);
      normDir[3*l+k]=normDirK;
      for(int i=0;i<3;i++)
        directionsNormalized[9*l+3*k+i]=directions[9*l+3*k+i]/normDirK;
    }
  }
  hxtOrientation3DgetCrossInTetFromDir(directionsNormalized, coordParam, dirAtParamNode);
  //Loop on dir at param node to get scaling
  for(int k=0;k<3;k++){
    double *dir=dirAtParamNode+3*k;
    //finding closest dir for each node and getting associated norm
    double normInterp[4]={0.0};
    for(int l=0;l<4;l++){
      double maxSP=-1.0;
      int indMaxL=-1;
      for(int m=0;m<3;m++){
        double *dirTestM=directionsNormalized+9*l+3*m;
        double scalarProdMK=0;
        for(int j=0;j<3;j++)
          scalarProdMK+=dir[j]*dirTestM[j];
        if(fabs(scalarProdMK)>maxSP){
          maxSP=fabs(scalarProdMK);
          indMaxL=m;
        }
      }
      normInterp[l]=normDir[3*l+indMaxL];
    }
    //Interpolation of corresponding norms in tet
    double L[4]={0.0};
    L[0]=1-xi-eta-zeta;
    L[1]=xi;
    L[2]=eta;
    L[3]=zeta;
    double normAtParamNode=0.0;
    for(int l=0;l<4;l++)
      normAtParamNode+=normInterp[l]*L[l];
    for(int i=0;i<3;i++)
      dir[i]=dir[i]*normAtParamNode;
  }
  return HXT_STATUS_OK;
}

#include "hxt_orientation3d_tools.h"
#include "hxt_tools.h"
#include "hxt_eigenvectors.h"
#include "hxt_tools.h"
#include "hxt_remesh_tools.h"

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

HXTStatus hxtOr3DboundaryConstraintMatrix(const double C[9][2], double B[9][9]){
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

HXTStatus hxtOr3DcombinationOnBorder(double a, double b, double c[9][2], double d[9]){
  double v0[9], v1[9], v2[9];
  double euler[3]={a,b,0};
  hxtOr3DeulerToFrame(euler, v0);
  euler[2]=M_PI/8;
  hxtOr3DeulerToFrame(euler, v1);
  euler[2]=M_PI/4;
  hxtOr3DeulerToFrame(euler, v2);
  for (int i=0;i<9;i++){
    d[i]    = 0.5*(v0[i]+v2[i]);
    c[i][0] = v0[i]-d[i];
    c[i][1] = v1[i]-d[i];
  }
  return HXT_STATUS_OK;
}

void hxtOr3DeulerAnglesOfNormal(const double *normal, double* psi, double* theta){ //mod
  /* Euler angles assuming e_z is transformed to the normal n */
  double w[3] = {normal[0],normal[1],normal[2]};
  hxtNormalizeV3(w);
  int flagNoNutation=1;
  if(fabs(w[2])<cos(0.1*M_PI/180.0))
    flagNoNutation=0;
  if(flagNoNutation){
    if(w[2]<0){
      *theta=M_PI;
    }
    else{
      *theta=0.0;
    }
    *psi=0.0;
  }
  else{
    *psi = atan2(w[0],-w[1]);
    if(fabs(cos(*psi))>0.01)
      *theta=atan2(-w[1]/cos(*psi),w[2]);
    else
      *theta=atan2(w[0]/sin(*psi),w[2]);
  }
  
  return;
}

HXTStatus hxtOr3DgradBoundary(const double *B, const double D[9], const double frame[9], double grad[9]){
  for(uint8_t i=0;i<9;i++){
    grad[i]=0.0;
    for(uint8_t k=0;k<9;k++){
      grad[i] += B[i*9+k] * (frame[k]-D[k]);
    }
  }
  return HXT_STATUS_OK;
}

void hxtOr3DgradPenaltyComp(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9], int k, int l){
  for (int i = 0; i < 9; ++i)
    grad[i]=0.0;
  double L[6][6]={{0.0}};
  double a[10]={0.0};
  for (int i = 0; i < 9; ++i)
    a[i]=frame[i];
  a[9]=sqrt(9.0/5.0);
  for (int i = 0; i < 10; ++i){
    L[k][l]-=a[i]*base[k][l][i];
    for (int j = 0; j < 10; ++j)
      L[k][l]+=a[i]*a[j]*crossProdBase[i][j][k][l];
  }
  double Gtilde[9][6][6]={{{0.0}}};
  for (int m = 0; m < 9; ++m){
    Gtilde[m][k][l]-=base[k][l][m];
    for (int i = 0; i < 10; ++i)
      Gtilde[m][k][l]+=a[i]*(crossProdBaseSym[m][i][k][l]);
  }
  for (int m = 0; m < 9; ++m)
    grad[m]+=L[k][l]*Gtilde[m][k][l];
  return;
}

void hxtOr3DgradPenalty(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9]){
  for (int i = 0; i < 9; ++i)
    grad[i]=0.0;
  double L[6][6]={{0.0}};
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
  double Gtilde[9][6][6]={{{0.0}}};
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

HXTStatus hxtOr3DcrossProdBase(const double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6]){ //mod
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

void hxtOr3DgetBase(double basis[6][6][10]){ //mod
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
void newBasisToOldBasis(const double *solNewBasis, double *solOldBasis){ //mod
  double alpha=1.0;
  double beta=0.5*(sqrt(70)-8)*alpha;
  double matBtoA[3][3]={{0.0}};
  double matBtoA2[2][2]={{0.0}};
  /* double invMatBtoA[3][3]={{0.0}}; */
  /* double invMatBtoA2[2][2]={{0.0}}; */
  /* double det=0.0; */
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
    solOldBasis[i]=0.0;
  for(int i=0;i<3;i++)
    solOldBasis[i]=3.0/5.0;
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      /* solOldBasis[i]+=invMatBtoA[i][k]*sol[k]; */
      solOldBasis[i]+=matBtoA[i][k]*solNewBasis[k];
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
      /* solOldBasis[i+3]+=invMatBtoA2[i][k]*solNewBasis[k+3]; */
      solOldBasis[i+3]+=matBtoA2[i][k]*solNewBasis[k+3];
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=-(alpha+beta)/norm;
  matBtoA2[1][1]=-(alpha+beta)/norm;
  /* hxtInv2x2(matBtoA2, invMatBtoA2, &det); */
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      /* solOldBasis[i+5]+=invMatBtoA2[i][k]*solNewBasis[k+5]; */
      solOldBasis[i+5]+=matBtoA2[i][k]*solNewBasis[k+5];
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=beta/norm;
  matBtoA2[1][1]=alpha/norm;
  /* hxtInv2x2(matBtoA2, invMatBtoA2, &det); */
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      /* solOldBasis[i+7]+=invMatBtoA2[i][k]*solNewBasis[k+7]; */
      solOldBasis[i+7]+=matBtoA2[i][k]*solNewBasis[k+7];
    }
  }
}

//Conversion from old basis to new basis
void oldBasisToNewBasis(const double *solOldBasis, double *solNewBasis){ //mod
  double alpha=1.0;
  double beta=0.5*(sqrt(70)-8)*alpha;
  double matBtoA[3][3]={{0.0}};
  double matBtoA2[2][2]={{0.0}};
  double invMatBtoA[3][3]={{0.0}};
  double invMatBtoA2[2][2]={{0.0}};
  double det=0.0;
  double solForInv[9]={0.0};
  for(int i=0;i<9;i++)
    solForInv[i]=solOldBasis[i];
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
    solNewBasis[i]=0.0;

  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      solNewBasis[i]+=invMatBtoA[i][k]*solForInv[k];
      /* solNewBasis[i]+=matBtoA[i][k]*sol[k]; */
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
      solNewBasis[i+3]+=invMatBtoA2[i][k]*solForInv[k+3];
      /* solNewBasis[i+3]+=matBtoA2[i][k]*sol[k+3]; */
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=-(alpha+beta)/norm;
  matBtoA2[1][1]=-(alpha+beta)/norm;
  hxtInv2x2(matBtoA2, invMatBtoA2, &det);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      solNewBasis[i+5]+=invMatBtoA2[i][k]*solForInv[k+5];
      /* solNewBasis[i+5]+=matBtoA2[i][k]*sol[k+5]; */
    }
  }
  matBtoA2[0][0]=alpha/norm;
  matBtoA2[0][1]=beta/norm;
  matBtoA2[1][0]=beta/norm;
  matBtoA2[1][1]=alpha/norm;
  hxtInv2x2(matBtoA2, invMatBtoA2, &det);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      solNewBasis[i+7]+=invMatBtoA2[i][k]*solForInv[k+7];
      /* solNewBasis[i+7]+=matBtoA2[i][k]*sol[k+7]; */
    }
  }
}

// Frobenius norm of 3x3 symmetric matrix
void hxtOr3DfrobNormMatSym3x3(const double *mat, double *frobNorm) //mod
{
  double norm=0.0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      norm+=mat[3*i+j]*mat[3*i+j];
  *frobNorm=sqrt(norm);
  return;
}

// representation Mandel 9x1 -> matrice 3x3 sym
void hxtOr3Dmat3x3ToMandel2nd(const double *mat33, double *mandel2nd) //mod
{
  double s = sqrt(2);
  mandel2nd[0] = mat33[0*3+0];
  mandel2nd[1] = mat33[1*3+1];
  mandel2nd[2] = mat33[2*3+2];
  mandel2nd[3] = s*mat33[1*3+2];
  mandel2nd[4] = s*mat33[2*3+0];
  mandel2nd[5] = s*mat33[1*3+0];  
}

// representation Mandel 9x1 -> matrice 3x3 sym
void hxtOr3Dmandel2ndToMat3x3(const double *mandel2nd, double *mat33) //mod
{
  double s = sqrt(2);
  mat33[0*3+0] = mandel2nd[0];
  mat33[0*3+1] = mandel2nd[5]/s;
  mat33[0*3+2] = mandel2nd[4]/s;
  mat33[1*3+0] = mandel2nd[5]/s;
  mat33[2*3+0] = mandel2nd[4]/s;
  mat33[1*3+1] = mandel2nd[1];
  mat33[1*3+2] = mandel2nd[3]/s;
  mat33[2*3+1] = mandel2nd[3]/s;
  mat33[2*3+2] = mandel2nd[2];
}

/* // old frame representation 9x1 -> representation Mandel 6x6 */
/* void hxtOr3DframeToMandel4th(const double *frameOld, double *mandel4th) //mod */
/* { */
/*   double s = sqrt(2.); */
/*   D[0*6+0] = frameOld[0]; */
/*   D[0*6+1] = 0.5*(1+frameOld[2]-frameOld[0]-frameOld[1]); */
/*   D[0*6+2] = 0.5*(1+frameOld[1]-frameOld[0]-frameOld[2]); */
/*   D[0*6+3] = s*frameOld[3]; */
/*   D[0*6+4] = s*frameOld[5]; */
/*   D[0*6+5] = s*frameOld[7]; */
  
/*   D[1*6+0] = D[0*6+1]; */
/*   D[1*6+1] = frameOld[1]; */
/*   D[1*6+2] = 0.5*(1+frameOld[0]-frameOld[2]-frameOld[1]); */
/*   D[1*6+3] = s*frameOld[4]; */
/*   D[1*6+4] = s*frameOld[6]; */
/*   D[1*6+5] = s*frameOld[8]; */
  
/*   D[2*6+0] = D[0*6+2]; */
/*   D[2*6+1] = D[1*6+2]; */
/*   D[2*6+2] = frameOld[2]; */
/*   D[2*6+3] = -s*(frameOld[3]+frameOld[4]); */
/*   D[2*6+4] = -s*(frameOld[5]+frameOld[6]); */
/*   D[2*6+5] = -s*(frameOld[7]+frameOld[8]); */
  
/*   D[3*6+0] = D[0*6+3]; */
/*   D[3*6+1] = D[1*6+3]; */
/*   D[3*6+2] = D[2*6+3]; */
/*   D[3*6+3] = s*s*0.5*(1+frameOld[0]-frameOld[2]-frameOld[1]); */
/*   D[3*6+4] = -s*s*(frameOld[7]+frameOld[8]); */
/*   D[3*6+5] = s*s*frameOld[6]; */
  
/*   D[4*6+0] = D[0*6+4]; */
/*   D[4*6+1] = D[1*6+4]; */
/*   D[4*6+2] = D[2*6+4]; */
/*   D[4*6+3] = D[3*6+4]; */
/*   D[4*6+4] = s*s*0.5*(1+frameOld[1]-frameOld[0]-frameOld[2]); */
/*   D[4*6+5] = s*s*frameOld[3]; */
  
/*   D[5*6+0] = D[0*6+5]; */
/*   D[5*6+1] = D[1*6+5]; */
/*   D[5*6+2] = D[2*6+5]; */
/*   D[5*6+3] = D[3*6+5]; */
/*   D[5*6+4] = D[4*6+5]; */
/*   D[5*6+5] = s*s*0.5*(1+frameOld[2]-frameOld[0]-frameOld[1]); */
/* } */

// frame representation 9x1 -> representation Mandel 6x6
void hxtOr3DframeToMandel4th(const double *frame, double *mandel4th) //mod
{
  double basis[6][6][10];
  hxtOr3DgetBase(basis);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      mandel4th[6*i+j]=0.0;
  for (int b = 0; b < 9; b++)
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
	mandel4th[6*i+j]+=frame[b]*basis[i][j][b];
  double sphereCoef=3.0/sqrt(5);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      mandel4th[6*i+j]+=sphereCoef*basis[i][j][9];
  return;
}

// representation Mandel 6x6 -> frame 9x1
void hxtOr3Dmandel4thToFrame(const double *mandel4th, double *frame) //mod
{
  double basis[6][6][10];
  hxtOr3DgetBase(basis);
  for(int b = 0; b < 9; b++){
    double scalarP=0.0;
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
	scalarP+=basis[i][j][b]*mandel4th[6*i+j];
    frame[b]=scalarP;
  }
  return;
}

// angles euler ZXZ -> matrice rotation 3x3
void hxtOr3DeulerToBasis(const double *euler, double *basis) //mod
{
  double c1 = cos(euler[0]);
  double s1 = sin(euler[0]);
  double c2 = cos(euler[1]);
  double s2 = sin(euler[1]);
  double c3 = cos(euler[2]);
  double s3 = sin(euler[2]);
  basis[3*0+0] = c1*c3-c2*s1*s3;
  basis[3*0+1] = c2*c1*s3+c3*s1;
  basis[3*0+2] = s3*s2;

  basis[3*1+0] = -c1*s3-c3*c2*s1;
  basis[3*1+1] = c1*c2*c3-s1*s3;
  basis[3*1+2] = c3*s2;

  basis[3*2+0] = s2*s1;
  basis[3*2+1] = -c1*s2;
  basis[3*2+2] = c2;

  /* basis[3*0+0] = c1*c3-c2*s1*s3; */
  /* basis[3*1+0] = c2*c1*s3+c3*s1; */
  /* basis[3*2+0] = s3*s2; */

  /* basis[3*0+1] = -c1*s3-c3*c2*s1; */
  /* basis[3*1+1] = c1*c2*c3-s1*s3; */
  /* basis[3*2+1] = c3*s2; */

  /* basis[3*0+2] = s2*s1; */
  /* basis[3*1+2] = -c1*s2; */
  /* basis[3*2+2] = c2; */

  return;
}

/* // matrice rotation 3x3 -> representation Mandel 6x6 de l'opérateur de rotation d'ordre 4 */
/* void hxtOr3DmatRot3x3ToMandelRot4th(double *Rv, double *R) */
/* { */
/*   double s = sqrt(2); */
/*   Rv[0*6+0] = R[0*3+0]*R[0*3+0]; */
/*   Rv[0*6+1] = R[0*3+1]*R[0*3+1]; */
/*   Rv[0*6+2] = R[0*3+2]*R[0*3+2]; */
/*   Rv[0*6+3] = s*R[0*3+1]*R[0*3+2]; */
/*   Rv[0*6+4] = s*R[0*3+0]*R[0*3+2]; */
/*   Rv[0*6+5] = s*R[0*3+0]*R[0*3+1]; */
  
/*   Rv[1*6+0] = R[1*3+0]*R[1*3+0]; */
/*   Rv[1*6+1] = R[1*3+1]*R[1*3+1]; */
/*   Rv[1*6+2] = R[1*3+2]*R[1*3+2]; */
/*   Rv[1*6+3] = s*R[1*3+1]*R[1*3+2]; */
/*   Rv[1*6+4] = s*R[1*3+0]*R[1*3+2]; */
/*   Rv[1*6+5] = s*R[1*3+1]*R[1*3+0]; */
  
/*   Rv[2*6+0] = R[2*3+0]*R[2*3+0]; */
/*   Rv[2*6+1] = R[2*3+1]*R[2*3+1]; */
/*   Rv[2*6+2] = R[2*3+2]*R[2*3+2]; */
/*   Rv[2*6+3] = s*R[2*3+2]*R[2*3+1]; */
/*   Rv[2*6+4] = s*R[2*3+2]*R[2*3+0]; */
/*   Rv[2*6+5] = s*R[2*3+0]*R[2*3+1]; */
  
/*   Rv[3*6+0] = s*R[1*3+0]*R[2*3+0]; */
/*   Rv[3*6+1] = s*R[1*3+1]*R[2*3+1]; */
/*   Rv[3*6+2] = s*R[1*3+2]*R[2*3+2]; */
/*   Rv[3*6+3] = R[1*3+1]*R[2*3+2]+R[1*3+2]*R[2*3+1]; */
/*   Rv[3*6+4] = R[1*3+0]*R[2*3+2]+R[1*3+2]*R[2*3+0]; */
/*   Rv[3*6+5] = R[1*3+1]*R[2*3+0]+R[1*3+0]*R[2*3+1]; */
  
/*   Rv[4*6+0] = s*R[0*3+0]*R[2*3+0]; */
/*   Rv[4*6+1] = s*R[0*3+1]*R[2*3+1]; */
/*   Rv[4*6+2] = s*R[0*3+2]*R[2*3+2]; */
/*   Rv[4*6+3] = R[0*3+1]*R[2*3+2]+R[0*3+2]*R[2*3+1]; */
/*   Rv[4*6+4] = R[0*3+2]*R[2*3+0]+R[0*3+0]*R[2*3+2]; */
/*   Rv[4*6+5] = R[0*3+0]*R[2*3+1]+R[0*3+1]*R[2*3+0]; */
  
/*   Rv[5*6+0] = s*R[0*3+0]*R[1*3+0]; */
/*   Rv[5*6+1] = s*R[0*3+1]*R[1*3+1]; */
/*   Rv[5*6+2] = s*R[0*3+2]*R[1*3+2]; */
/*   Rv[5*6+3] = R[0*3+1]*R[1*3+2]+R[0*3+2]*R[1*3+1]; */
/*   Rv[5*6+4] = R[0*3+2]*R[1*3+0]+R[0*3+0]*R[1*3+2]; */
/*   Rv[5*6+5] = R[0*3+0]*R[1*3+1]+R[0*3+1]*R[1*3+0];   */
/* } */

// angle euler ZXZ -> frame 9x1
void hxtOr3DeulerToFrame(const double *euler, double *frame) //mod
{
  double basis[9]={0.0};
  hxtOr3DeulerToBasis(euler, basis);
  hxtOr3DdirectionsToFrame(basis, frame);
  return;
}

// 3 directions orthogonale normalisées (x0,y0,z0,x1,y1,z1,x2,y2,z2) -> frame 9x1
void hxtOr3DdirectionsToFrame(const double *directions, double *frame) //mod
{
  double u[3]={directions[0],directions[1],directions[2]};
  double v[3]={directions[3+0],directions[3+1],directions[3+2]};
  double w[3]={directions[6+0],directions[6+1],directions[6+2]};
  hxtNormalizeV3(u);
  hxtNormalizeV3(v);
  hxtNormalizeV3(w);
  /* double tens2uu[9]={0.0}; */
  /* double tens2vv[9]={0.0}; */
  /* double tens2ww[9]={0.0}; */
  /* for (int i = 0; i < 3; i++) */
  /*   for (int j = 0; j < 3; j++){ */
  /*     tens2uu[3*i+j]=u[i]*u[j]; */
  /*     tens2vv[3*i+j]=v[i]*v[j]; */
  /*     tens2ww[3*i+j]=w[i]*w[j]; */
  /*   } */
  double mandel2ndUU[6]={0.0};
  double mandel2ndVV[6]={0.0};
  double mandel2ndWW[6]={0.0};
  hxtOr3Dvec3ToMandel2ndDyadic(u, mandel2ndUU);
  hxtOr3Dvec3ToMandel2ndDyadic(v, mandel2ndVV);
  hxtOr3Dvec3ToMandel2ndDyadic(w, mandel2ndWW);
  /* hxtOr3Dmat3x3ToMandel2nd(tens2uu, mandel2ndUU); */
  /* hxtOr3Dmat3x3ToMandel2nd(tens2vv, mandel2ndVV); */
  /* hxtOr3Dmat3x3ToMandel2nd(tens2ww, mandel2ndWW); */
  double mandel4th[36]={0.0};
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      mandel4th[6*i+j]+=mandel2ndUU[i]*mandel2ndUU[j]+mandel2ndVV[i]*mandel2ndVV[j]+mandel2ndWW[i]*mandel2ndWW[j];
  hxtOr3Dmandel4thToFrame(mandel4th, frame);
  return;
}

// normale + un angle de rotation autour de celle-ci -> frame 9x1
void hxtOr3DnormalEulerToFrame(const double *normal, const double gamma, double *frame) //mod
{
  double w[3] = {normal[0],normal[1],normal[2]};
  hxtNormalizeV3(w);
  double psi=0.0;
  double theta=0.0;
  double phi=0.0;
  hxtOr3DeulerAnglesOfNormal(normal, &psi, &theta);
  phi=gamma;
  double euler[3]={psi,theta,phi};
  hxtOr3DeulerToFrame(euler, frame);
  return;
}

/* // normale + un angle de rotation autour de celle-ci -> frame 9x1 */
/* void hxtOr3DnormalEulerToFrame(const double *normal, const double gamma, double *frame) */
/* { */
/*   double a = normal[0]; */
/*   double b = normal[1]; */
/*   double c = normal[2]; */

/*   if(sqrt(b*b+c*c)<1e-8){ */
/*     double cosGamma4 = pow(cos(gamma),4); */
/*     double sinGamma4 = pow(sin(gamma),4); */
/*     frame[0] = 1.; */
/*     frame[1] = cosGamma4+sinGamma4; */
/*     frame[2] = cosGamma4+sinGamma4; */
/*     frame[3] = 0.; */
/*     frame[4] = sin(4*gamma)/4.; */
/*     frame[5] = 0.; */
/*     frame[6] = 0.; */
/*     frame[7] = 0.; */
/*     frame[8] = 0.; */
/*   } */
/*   else if(sqrt(b*b+a*a)<1e-8){ */
/*     double cosGamma4 = pow(cos(gamma),4); */
/*     double sinGamma4 = pow(sin(gamma),4); */
/*     frame[0] = cosGamma4+sinGamma4; */
/*     frame[1] = cosGamma4+sinGamma4; */
/*     frame[2] = 1.0; */
/*     frame[3] = 0.; */
/*     frame[4] = 0.; */
/*     frame[5] = 0.; */
/*     frame[6] = 0.; */
/*     frame[7] = sin(4*gamma)/4.; */
/*     frame[8] = -sin(4*gamma)/4.; */
/*   } */
/*   else{ */
/*     double gammaCorr = atan2(-b,(a*c)); */
/*     double sgn = b/fabs(b); */
/*     double cos4Gamma = cos(4*(sgn*gamma-gammaCorr)); */
/*     double sin4Gamma = sin(4*(sgn*gamma-gammaCorr)); */
  
/*     double a4 = pow(a,4); */
/*     double a3 = pow(a,3); */
/*     double a2 = pow(a,2); */
/*     double b8 = pow(b,8); */
/*     double b6 = pow(b,6); */
/*     double b4 = pow(b,4); */
/*     double b3 = pow(b,3); */
/*     double b2 = pow(b,2); */
/*     double c8 = pow(c,8); */
/*     double c6 = pow(c,6); */
/*     double c5 = pow(c,5); */
/*     double c4 = pow(c,4); */
/*     double c3 = pow(c,3); */
/*     double c2 = pow(c,2); */
  
/*     frame[0] = a4 + (pow(b2 + c2,2)*(3 + cos4Gamma))/4.; */

/*     frame[1] = (3*a4*b4 + 4*b8 + 6*a2*b2*c2 + */
/* 		8*b6*c2 + (3 + 4*b4)*c4 + */
/* 		(a4*b4 - 6*a2*b2*c2 + c4)*cos4Gamma + */
/* 		4*a*b*c*(-(a2*b2) + c2)*sin4Gamma)/ */
/*       (4.*pow(b2 + c2,2)); */

/*     frame[2] = (3*a4*c4 + 4*c8 + b4*(3 + 4*c4) + */
/* 		b2*(6*a2*c2 + 8*c6) + */
/* 		(b4 - 6*a2*b2*c2 + a4*c4)*cos4Gamma - */
/* 		4*a*b*c*(b - a*c)*(b + a*c)*sin4Gamma)/(4.*pow(b2 + c2,2)); */

/*     frame[3] = (b*c*(-1 + 7*a2 + (1 + a2)*cos4Gamma) + a*(b - c)*(b + c)*sin4Gamma)/4.; */

/*     frame[4] = (b3*(-3*a2 + 3*a4 + 4*b4)*c + */
/* 		b*(-3 + 3*a2 + 8*b4)*c3 + 4*b3*c5 + */
/* 		b*c*(a2*(3 + a2)*b2 - (1 + 3*a2)*c2)*cos4Gamma + */
/* 		a*(a2*b4 - 3*(1 + a2)*b2*c2 + c4)*sin4Gamma) */
/*       /(4.*pow(b2 + c2,2)); */

/*     frame[5] = a3*c - (3*a*c*(b2 + c2))/4. - */
/*       ((b2 + c2)*(a*c*cos4Gamma + b*sin4Gamma))/4.; */

/*     frame[6] = (a*b2*(2 - 3*a2 + 4*b2)*c + a*(-1 + 4*b2)*c3 + */
/* 		a*c*(-((2 + a2)*b2) + c2)*cos4Gamma + */
/* 		b*(c2 - a2*(b2 - 2*c2))*sin4Gamma)/ */
/*       (4.*(b2 + c2)); */

/*     frame[7] = a3*b - (3*a*b*(b2 + c2))/4. - */
/*       ((b2 + c2)*(a*b*cos4Gamma - c*sin4Gamma))/4.; */

/*     frame[8] = (a*b*(-3*a2*b2 + 4*b4 + (-3 + 4*b2)*c2 + */
/* 		     (-(a2*b2) + 3*c2)*cos4Gamma) - */
/* 		c*(-3*a2*b2 + c2)*sin4Gamma)/(4.*(b2 + c2)); */
/*   } */
/* } */

/* void hxtOr3DnormalEulerToFrame(double *cross, double *normal, double gamma) */
/* { */
/*   double a,b; */
/*   hxtOr3DeulerAnglesOfNormal(normal, &a, &b); */
/*   double C[9][2]; */
/*   double D[9]; */
/*   hxtOr3DcombinationOnBorder2(a, b, C, D); */
/*   double v[2]={cos(gamma),sin(gamma)}; */
/*   for(int k=0;k<9;k++){ */
/*     cross[k]=0.0; */
/*     for(int i=0;i<2;i++){ */
/*       cross[k]=C[k][i]*v[i]+D[k]; */
/*     } */
/*   } */
/* } */

void hxtOr3Dvec3ToMandel2ndDyadic(const double *vect, double *mandel2ndDyadic){
  double mat3x3[9]={0.0};
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      mat3x3[3*i+j]=vect[i]*vect[j];
  hxtOr3Dmat3x3ToMandel2nd(mat3x3, mandel2ndDyadic);
}

HXTStatus hxtOr3DprojectFrameOnCrossManifold(const double *frame, double *frameProj){
  double dir[3*3]={0.0};
  hxtOr3DframeToDirections(frame,NULL,dir);
  hxtOr3DdirectionsToFrame(dir, frameProj);
  return HXT_STATUS_OK;
}

// projection frame 9x1 -> 3 directions orthogonales (x0,y0,z0,x1,y1,z1,x2,y2,z2)
HXTStatus hxtOr3DframeToDirections(const double *frame, double *stableDir, double *dirFinal) //mod
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
  hxtOr3DframeToMandel4th(frame,mat);
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
  hxtOr3Dmandel2ndToMat3x3(R4, v4);
  hxtOr3Dmandel2ndToMat3x3(R5, v5);

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
  hxtOr3DfrobNormMatSym3x3(r4tV5r4, &frobNorm454);
  hxtOr3DfrobNormMatSym3x3(r5tV4r5, &frobNorm545);
  hxtOr3DfrobNormMatSym3x3(r4tV4r4, &frobNorm444);
  hxtOr3DfrobNormMatSym3x3(r5tV5r5, &frobNorm555);
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

  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      dirFinal[3*i+j] = rFinal[3*j+i];
    }
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
	dir[k]=dirFinal[3*i+k];
      /* printf("dir : %g %g %g\n",dir[0],dir[1],dir[2]); */
      hxtOr3Dvec3ToMandel2ndDyadic(dir, mandel2ndDir);
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

HXTStatus hxtOr3DframeToEuler(const double *frame, double *flagNotUnique, double *euler) //mod
{
  double directions[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frame, stableDir, directions);
  hxtOr3DdirectionsToEuler(directions, flagNotUnique, euler);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdirectionsToEuler(const double * dir, double *flagNotUnique, double *euler){
  const double *u=dir;
  const double *v=dir+3;
  const double *w=dir+6;
  double psi=0.0;
  double theta=0.0;
  double phi=0.0;

  int flagNoNutation=1;
  double sign=0.0;
  double phiPlusPsi=0.0;
  if(fabs(w[2])<cos(0.01*M_PI/180.0))
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
    psi=0.0;
    phiPlusPsi=atan2(-v[0],u[0]);
    phi=phiPlusPsi;
    euler[0]=psi;
    euler[1]=theta;
    euler[2]=phi;
  }
  else{
    psi = atan2(w[0],-w[1]);
    phi = atan2(u[2],v[2]);
    if(fabs(cos(phi))>0.01)
      theta=atan2(v[2]/cos(phi),w[2]);
    else
      theta=atan2(u[2]/sin(phi),w[2]);
    euler[0]=psi;
    euler[1]=theta;
    euler[2]=phi;
  }
  *flagNotUnique=sign;
  return HXT_STATUS_OK;
}

// frame 9x1 -> double quality (||A^2 - A||)
HXTStatus hxtOr3DcomputeQuality(const double *frame, double *quality){ //mod
  double D[36]={0.0};
  hxtOr3DframeToMandel4th(frame, D);
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

HXTStatus hxtOr3DgetCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode, double *quality, int flagTrusted[3]){ //mod
  double framesElem[9*4];
  for(int k=0;k<4;k++){
    double *frameK=framesElem+9*k;
    double dirK[9]={0.0};
    for(int j=0;j<3;j++)
      for(int l=0;l<3;l++)
	dirK[3*j+l]=directions[9*k+3*j+l];
    hxtOr3DdirectionsToFrame(dirK, frameK);
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
  hxtOr3DcomputeQuality(frameP, quality);
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frameP, stableDir, refDir);
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      dirAtParamNode[3*i+j]=refDir[3*i+j];
  for(int i=0;i<3;i++){
    double val=stableDir[i]-0.9;
    (val<0)? ((flagTrusted[i])=0):((flagTrusted[i])=1);
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DgetScaledCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode, double *quality, int flagTrusted[3]){ //mod
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
  hxtOr3DgetCrossInTetFromDir(directionsNormalized, coordParam, dirAtParamNode, quality, flagTrusted);
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

static inline double Cos(double angle){ return cos(angle);}
static inline double Sin(double angle){ return sin(angle);}
static inline double Sqrt(double val){ return sqrt(val);}
static inline double Power(double value,double exposant){ return pow(value,exposant);}

HXTStatus hxtOr3DdBdEuler(const double euler[3], double dBdEuler[9][3]){
  double psi = euler[0];
  double theta = euler[1];
  double phi = euler[2];
  dBdEuler[0][0] = (Sqrt(9.5 - Sqrt(70))*(4*(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
					  Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),3) -
					  4*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3)*
					  (Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi)) +
					  4*Power(Cos(psi),3)*Sin(psi)*Power(Sin(theta),4)))/3. +
    (4*Sqrt(30.5 + 2*Sqrt(70))*(Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3)*
				(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi)) -
				(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
				Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),3) +
				Cos(psi)*Power(Sin(psi),3)*Power(Sin(theta),4)))/3.;
  dBdEuler[0][1] = (-4*(-Sqrt(5) + Sqrt(14))*Cos(psi)*Sin(theta)*
		    (-(Sin(phi)*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3)) -
		     Cos(phi)*Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),3) +
		     Power(Cos(psi),3)*Cos(theta)*Power(Sin(theta),2)) +
		    4*(Sqrt(5) + 2*Sqrt(14))*Sin(psi)*Sin(theta)*
		    (-(Cos(phi)*Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3)) +
		     Sin(phi)*Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),3) +
		     Cos(theta)*Power(Sin(psi),3)*Power(Sin(theta),2)) +
		    (-Sqrt(5) + Sqrt(14))*(4*Power(Cos(theta),3)*Sin(theta) -
					   (3 + Cos(4*phi))*Cos(theta)*Power(Sin(theta),3)))/(3.*Sqrt(2));
  dBdEuler[0][2] = (-4*(-Sqrt(5) + Sqrt(14))*(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi))*
		    (Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3) -
		     (Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
		     Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),2)) +
		    4*(Sqrt(5) + 2*Sqrt(14))*(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi))*
		    (Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3) -
		     (Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
		     Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),2)) +
		    (-Sqrt(5) + Sqrt(14))*Sin(4*phi)*Power(Sin(theta),4))/(3.*Sqrt(2));

  dBdEuler[1][0] = ((4*Sqrt(7) + Sqrt(10))*(-4*(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
					    Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),3) +
					    4*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3)*
					    (Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi)) -
					    4*Power(Cos(psi),3)*Sin(psi)*Power(Sin(theta),4)) -
		    4*Sqrt(38 - 4*Sqrt(70))*(Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3)*
					     (Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi)) -
					     (Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
					     Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),3) +
					     Cos(psi)*Power(Sin(psi),3)*Power(Sin(theta),4)))/6.;
  dBdEuler[1][1] = (4*(Sqrt(5) + 2*Sqrt(14))*Cos(psi)*Sin(theta)*
		    (-(Sin(phi)*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3)) -
		     Cos(phi)*Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),3) +
		     Power(Cos(psi),3)*Cos(theta)*Power(Sin(theta),2)) -
		    4*(-Sqrt(5) + Sqrt(14))*Sin(psi)*Sin(theta)*
		    (-(Cos(phi)*Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3)) +
		     Sin(phi)*Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),3) +
		     Cos(theta)*Power(Sin(psi),3)*Power(Sin(theta),2)) +
		    (-Sqrt(5) + Sqrt(14))*(4*Power(Cos(theta),3)*Sin(theta) -
					   (3 + Cos(4*phi))*Cos(theta)*Power(Sin(theta),3)))/(3.*Sqrt(2));
  dBdEuler[1][2] = (4*(Sqrt(5) + 2*Sqrt(14))*(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi))*
		    (Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),3) -
		     (Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
		     Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),2)) -
		    4*(-Sqrt(5) + Sqrt(14))*(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi))*
		    (Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3) -
		     (Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
		     Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),2)) +
		    (-Sqrt(5) + Sqrt(14))*Sin(4*phi)*Power(Sin(theta),4))/(3.*Sqrt(2));

  dBdEuler[2][0] = (Sqrt(9.5 - Sqrt(70))*(8*Cos(4*psi)*(7*Cos(theta) + Cos(3*theta))*Sin(4*phi) +
					  Sin(4*psi)*(Cos(4*phi)*(35 + 28*Cos(2*theta) + Cos(4*theta)) + 56*Power(Sin(theta),4))))/96.;
  dBdEuler[2][1] = (-(Sqrt(297.5 + 35*Sqrt(70))*(4*Power(Sin(2*phi),2)*Sin(2*theta) +
						 (7 + Cos(4*phi))*Sin(4*theta))) +
		    Sqrt(9.5 - Sqrt(70))*(-2*Sin(4*phi)*Sin(4*psi)*(7*Sin(theta) + 3*Sin(3*theta)) +
					  Cos(4*psi)*(-28*Power(Sin(2*phi),2)*Sin(2*theta) + (7 + Cos(4*phi))*Sin(4*theta))))/96.;
  dBdEuler[2][2] = -(Sqrt(30.5 + 2*Sqrt(70))*Sin(4*phi)*Power(Sin(theta),4))/3. +
    (Sqrt(9.5 - Sqrt(70))*(8*Cos(4*phi)*(7*Cos(theta) + Cos(3*theta))*Sin(4*psi) +
			   Sin(4*phi)*(Cos(4*psi)*(35 + 28*Cos(2*theta) + Cos(4*theta)) + 24*Power(Sin(theta),4))))/96.;


  dBdEuler[3][0] = 3*(1 + Sqrt(7))*Sin(theta)*(-(Cos(phi)*(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
						 Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),2)) +
					       Sin(phi)*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),2)*
					       (Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi)) +
					       Power(Cos(psi),2)*Cos(theta)*Sin(psi)*Power(Sin(theta),2)) -
    ((-1 + Sqrt(7))*Sin(theta)*(-4*Power(Cos(theta),3)*Sin(psi) +
				(Cos(psi)*Sin(4*phi) + (3 + Cos(4*phi))*Cos(theta)*Sin(psi))*Power(Sin(theta),2)))/4.;
  dBdEuler[3][1] = (4*Cos(psi)*((7 + Cos(4*phi))*(Sqrt(8 - 3*Sqrt(7)) + Sqrt(4 + Sqrt(7))*Cos(2*psi))*Cos(4*theta) +
				2*(Sqrt(7*(8 + 3*Sqrt(7))) - 7*Sqrt(4 + Sqrt(7))*Cos(2*psi))*Cos(2*theta)*
				Power(Sin(2*phi),2)) + (-2*Sqrt(7*(16 - 5*Sqrt(7)))*Cos(theta) -
							3*Sqrt(2)*(5 + Sqrt(7))*Cos(3*theta) -
							2*Sqrt(4 + Sqrt(7))*Cos(2*psi)*(7*Cos(theta) + 9*Cos(3*theta)))*Sin(4*phi)*Sin(psi))/
    (32.*Sqrt(2));
  dBdEuler[3][2] = ((1 + Sqrt(7))*((3*(Cos(psi) - 5*Cos(3*psi))*Cos(theta) - 4*Power(Cos(psi),3)*Cos(3*theta))*
				   Sin(4*phi) - 4*Cos(4*phi)*(1 + 5*Cos(2*psi) + 6*Power(Cos(psi),2)*Cos(2*theta))*Sin(psi))*
		    Sin(theta))/16. - (-1 + Sqrt(7))*(Cos(psi)*Cos(theta)*Sin(4*phi) + Cos(4*phi)*Sin(psi))*
    Power(Sin(theta),3);

  dBdEuler[4][0] = 3*(-1 + Sqrt(7))*Sin(theta)*(-(Cos(phi)*(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi))*
						  Power(Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi),2)) +
						Sin(phi)*Power(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi),2)*
						(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi)) +
						Power(Cos(psi),2)*Cos(theta)*Sin(psi)*Power(Sin(theta),2)) +
    ((1 + Sqrt(7))*Sin(theta)*(4*Power(Cos(theta),3)*Sin(psi) -
			       (Cos(psi)*Sin(4*phi) + (3 + Cos(4*phi))*Cos(theta)*Sin(psi))*Power(Sin(theta),2)))/4.;
  dBdEuler[4][1] = (2*Cos(psi)*(Sqrt(2)*(7 + Cos(4*phi))*(-3 - Sqrt(7) + (-1 + Sqrt(7))*Cos(2*psi))*Cos(4*theta) +
				2*(2*Sqrt(7*(8 - 3*Sqrt(7))) - 7*Sqrt(2)*(-1 + Sqrt(7))*Cos(2*psi))*Cos(2*theta)*
				Power(Sin(2*phi),2)) + (-2*Sqrt(7*(16 + 5*Sqrt(7)))*Cos(theta) -
							3*Sqrt(2)*(-5 + Sqrt(7))*Cos(3*theta) -
							Sqrt(2)*(-1 + Sqrt(7))*Cos(2*psi)*(7*Cos(theta) + 9*Cos(3*theta)))*Sin(4*phi)*Sin(psi))/
    (32.*Sqrt(2));
  dBdEuler[4][2] = ((-1 + Sqrt(7))*((3*(Cos(psi) - 5*Cos(3*psi))*Cos(theta) - 4*Power(Cos(psi),3)*Cos(3*theta))*
				    Sin(4*phi) - 4*Cos(4*phi)*(1 + 5*Cos(2*psi) + 6*Power(Cos(psi),2)*Cos(2*theta))*Sin(psi))*
		    Sin(theta))/16. - (1 + Sqrt(7))*(Cos(psi)*Cos(theta)*Sin(4*phi) + Cos(4*phi)*Sin(psi))*
    Power(Sin(theta),3);

  dBdEuler[5][0] = (1 + Sqrt(7))*Sin(theta)*(-3*Cos(phi)*Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),2)*
					     (Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi)) -
					     3*Sin(phi)*(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
					     Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),2) +
					     3*Cos(psi)*Cos(theta)*Power(Sin(psi),2)*Power(Sin(theta),2)) +
    ((-1 + Sqrt(7))*(4*Cos(psi)*Power(Cos(theta),3)*Sin(theta) +
		     (-((3 + Cos(4*phi))*Cos(psi)*Cos(theta)) + Sin(4*phi)*Sin(psi))*Power(Sin(theta),3)))/4.;
  dBdEuler[5][1] = (4*Cos(psi)*Cos(theta)*(11 - Sqrt(7) - 3*(5 + Sqrt(7))*Cos(2*theta) +
					   (1 + Sqrt(7))*Cos(2*psi)*(-1 + 9*Cos(2*theta)))*Sin(4*phi) -
		    56*(1 + Sqrt(7))*Cos(4*theta)*Power(Sin(psi),3) +
		    2*(1 + Sqrt(7))*(7*(-1 + Cos(4*phi))*Cos(2*theta) + Cos(4*phi)*Cos(4*theta))*Sin(3*psi) +
		    2*Sin(psi)*(28*(-1 + Sqrt(7))*Cos(4*theta) +
				(-7 + Sqrt(7))*(Cos(2*theta) - 2*Cos(4*phi)*(1 + 2*Cos(2*theta))*Power(Sin(theta),2))))/64.;
  dBdEuler[5][2] = (2*Cos(4*phi)*(-4*(-7 + Sqrt(7))*Cos(psi)*Power(Sin(theta),3) +
				  (1 + Sqrt(7))*Cos(3*psi)*(7*Sin(theta) + 3*Sin(3*theta))) +
		    Sin(4*phi)*(8*(-7 + Sqrt(7))*Cos(theta)*Sin(psi)*Power(Sin(theta),3) -
				(1 + Sqrt(7))*Sin(3*psi)*(14*Sin(2*theta) + Sin(4*theta))))/32.;

  dBdEuler[6][0] = (-1 + Sqrt(7))*Sin(theta)*(-3*Cos(phi)*Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),2)*
					      (Cos(phi)*Cos(psi)*Cos(theta) - Sin(phi)*Sin(psi)) -
					      3*Sin(phi)*(Cos(psi)*Cos(theta)*Sin(phi) + Cos(phi)*Sin(psi))*
					      Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),2) +
					      3*Cos(psi)*Cos(theta)*Power(Sin(psi),2)*Power(Sin(theta),2)) +
    ((1 + Sqrt(7))*(4*Cos(psi)*Power(Cos(theta),3)*Sin(theta) +
		    (-((3 + Cos(4*phi))*Cos(psi)*Cos(theta)) + Sin(4*phi)*Sin(psi))*Power(Sin(theta),3)))/4.;
  dBdEuler[6][1] = (-1 + Sqrt(7))*Sin(psi)*Power(Sin(theta),2)*
    (2*Power(Cos(theta),2)*Power(Sin(psi),2) +
     3*Power(Cos(phi),2)*Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),2) +
     3*Power(Sin(phi),2)*Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),2) -
     Power(Sin(psi),2)*Power(Sin(theta),2)) +
    (-1 + Sqrt(7))*Cos(theta)*(-(Cos(phi)*
				 Power(Cos(psi)*Sin(phi) + Cos(phi)*Cos(theta)*Sin(psi),3)) +
			       Sin(phi)*Power(Cos(phi)*Cos(psi) - Cos(theta)*Sin(phi)*Sin(psi),3) +
			       Cos(theta)*Power(Sin(psi),3)*Power(Sin(theta),2)) +
    ((1 + Sqrt(7))*(4*Power(Cos(theta),4)*Sin(psi) -
		    3*Cos(theta)*(Cos(psi)*Sin(4*phi) + (7 + Cos(4*phi))*Cos(theta)*Sin(psi))*
		    Power(Sin(theta),2) + (3 + Cos(4*phi))*Sin(psi)*Power(Sin(theta),4)))/4.;
  dBdEuler[6][2] = (1 + Sqrt(7))*(-(Cos(4*phi)*Cos(psi)) + Cos(theta)*Sin(4*phi)*Sin(psi))*Power(Sin(theta),3) +
    ((-1 + Sqrt(7))*(Cos(4*phi)*(9*Cos(psi)*Sin(theta) + 7*Cos(3*psi)*Sin(theta) -
				 6*Sin(psi)*Sin(2*psi)*Sin(3*theta)) +
		     2*Sin(4*phi)*Sin(psi)*(-((5 + 7*Cos(2*psi))*Sin(2*theta)) + Power(Sin(psi),2)*Sin(4*theta)))
     )/16.;

  dBdEuler[7][0] = (-8*(7*Cos(theta) + Cos(3*theta))*Sin(4*phi)*Sin(4*psi) +
		    4*Sqrt(7)*Cos(2*psi)*(5 + 7*Cos(2*theta) + Cos(4*phi)*(3 + Cos(2*theta)))*
		    Power(Sin(theta),2) + Cos(4*psi)*(Cos(4*phi)*(35 + 28*Cos(2*theta) + Cos(4*theta)) +
						      56*Power(Sin(theta),4)) - 8*Sqrt(7)*Sin(4*phi)*Sin(2*psi)*Sin(theta)*Sin(2*theta))/32.;
  dBdEuler[7][1] = (-2*Sqrt(7)*Cos(2*psi)*Sin(4*phi)*(Sin(theta) - 3*Sin(3*theta)) -
		    2*Cos(4*psi)*Sin(4*phi)*(7*Sin(theta) + 3*Sin(3*theta)) +
		    2*Sin(2*psi)*(-4*(Sqrt(7) - 7*Cos(2*psi))*Power(Sin(2*phi),2)*Sin(2*theta) +
				  (7 + Cos(4*phi))*(Sqrt(7) - Cos(2*psi))*Sin(4*theta)))/32.;
  dBdEuler[7][2] = (8*Cos(4*phi)*(Cos(4*psi)*(7*Cos(theta) + Cos(3*theta)) +
				  4*Sqrt(7)*Cos(2*psi)*Cos(theta)*Power(Sin(theta),2)) +
		    Sin(4*phi)*(-((35 + 28*Cos(2*theta) + Cos(4*theta))*Sin(4*psi)) -
				8*Sqrt(7)*(3 + Cos(2*theta))*Sin(2*psi)*Power(Sin(theta),2)))/32.;

  dBdEuler[8][0] = (8*(7*Cos(theta) + Cos(3*theta))*Sin(4*phi)*Sin(4*psi) +
		    4*Sqrt(7)*Cos(2*psi)*(5 + 7*Cos(2*theta) + Cos(4*phi)*(3 + Cos(2*theta)))*
		    Power(Sin(theta),2) - Cos(4*psi)*(Cos(4*phi)*(35 + 28*Cos(2*theta) + Cos(4*theta)) +
						      56*Power(Sin(theta),4)) - 8*Sqrt(7)*Sin(4*phi)*Sin(2*psi)*Sin(theta)*Sin(2*theta))/32.;
  dBdEuler[8][1] = (-2*Sqrt(7)*Cos(2*psi)*Sin(4*phi)*(Sin(theta) - 3*Sin(3*theta)) +
		    2*Cos(4*psi)*Sin(4*phi)*(7*Sin(theta) + 3*Sin(3*theta)) +
		    2*Sin(2*psi)*(-4*(Sqrt(7) + 7*Cos(2*psi))*Power(Sin(2*phi),2)*Sin(2*theta) +
				  (7 + Cos(4*phi))*(Sqrt(7) + Cos(2*psi))*Sin(4*theta)))/32.;
  dBdEuler[8][2] = (-8*Cos(4*phi)*(Cos(4*psi)*(7*Cos(theta) + Cos(3*theta)) -
				   4*Sqrt(7)*Cos(2*psi)*Cos(theta)*Power(Sin(theta),2)) +
		    Sin(4*phi)*((35 + 28*Cos(2*theta) + Cos(4*theta))*Sin(4*psi) -
				8*Sqrt(7)*(3 + Cos(2*theta))*Sin(2*psi)*Power(Sin(theta),2)))/32.;

  return HXT_STATUS_OK;
}

//Cross fields tools
HXTStatus hxtOr3DcrossNodesToElem(const HXTMesh *mesh, const double *directionsScaledNodes, double *directionsScaledElem, double *qualityElem){
  double xGref[3]={1.0/4.0, 1.0/4.0, 1.0/4.0};
  int flagTrusted[3]={0};
  for(uint64_t i=0;i<mesh->tetrahedra.num;i++){
    double directionsNodeTet[9*4]={0.0};
    for (int k = 0; k < 4; k++)
      for (int l = 0; l < 9; l++)
	directionsNodeTet[9*k+l]=directionsScaledNodes[9*(mesh->tetrahedra.node[4*i+k])+l];
    hxtOr3DgetScaledCrossInTetFromDir(directionsNodeTet, xGref, directionsScaledElem + 9*i, qualityElem+i, flagTrusted);
  }
  return HXT_STATUS_OK;
}

//FE tools
HXTStatus hxtOr3DFEbasisFctDataTetOrder1(const HXTMesh *mesh, uint64_t iel, double *wGDet, double L[4], double dLdX[4][3]){
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
  double x[4][4];
  /* for (int i = 0; i < 4; i++) */
  /*   memcpy(x[i], mesh->vertices.coord + 4*tet[i], sizeof(x[i])); */
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      x[i][j] = mesh->vertices.coord[4*tet[i]+j];
  double dxdxi[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      dxdxi[i][j] = x[i+1][j] - x[0][j];
  double dxidx[3][3];
  double detj;
  HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dphi[][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  *wGDet = detj/6.0;
  for (int i = 0; i < 4; i++)
    L[i]=1./4.;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      dLdX[i][j]=dphi[i][j];
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DFELaplaceElemMatTetOrder1(const HXTMesh *mesh, uint64_t iel, double *laplaceMat){
  for (int i=0; i < 16; ++i)
    laplaceMat[i] = 0.0;
  double wGDet=0.0;
  double L[4]={0.0};
  double dLdX[4][3]={{0.0}};
  hxtOr3DFEbasisFctDataTetOrder1(mesh, iel, &wGDet, L, dLdX);
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j) {
      laplaceMat[i*4+j] = wGDet*(dLdX[i][0]*dLdX[j][0]+dLdX[i][1]*dLdX[j][1]+dLdX[i][2]*dLdX[j][2]);
    }
  }
      
  return HXT_STATUS_OK;
}

//Basic maths tools
HXTStatus hxtOr3DtransposeBasis(double *basis){
  double dirT[9]={0.0};
  for(int i=0;i<3;i++)
    for(int k=0;k<3;k++)
      dirT[3*i+k]=basis[3*k+i];
  for(int i=0;i<9;i++)
    basis[i]=dirT[i];
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DmakeOrientationDirect(double *basis){
  double u[3]={basis[0],basis[1],basis[2]};
  double v[3]={basis[3],basis[4],basis[5]};
  double w[3]={basis[6],basis[7],basis[8]};
  double n[3]={0.0};
  hxtCrossProductV3(u, v, n);
  hxtNormalizeV3(n);
  double scalarProd=0.0;
  hxtOr3DdotProd(w, n, 3, &scalarProd);
  if(scalarProd<0){
    for(int i=0;i<3;i++){
      basis[i]=-u[i];
    }
  }
  return HXT_STATUS_OK;
}

/* HXTStatus hxtOr3DliftBasis(const double *dirRef, double *dir){ */
/*   double *u=dir; */
/*   const double *uRef=dirRef; */
/*   const double *vRef=dirRef+3; */
/*   const double *wRef=dirRef+6; */
/*   double newDir[9]={0.0}; */
  
/*   // find closest to uRef */
/*   double maxDotProd=0.0; */
/*   hxtOr3DdotProd(uRef,u,3, &maxDotProd); */
/*   maxDotProd=fabs(maxDotProd); */
/*   int indMax=0; */
/*   double sign=0.0; */
/*   for(int i=1;i<3;i++){ */
/*     double scalarProd=0.0; */
/*     hxtOr3DdotProd(uRef,dir+3*i,3, &scalarProd); */
/*     if(fabs(scalarProd)>maxDotProd){ */
/*       indMax=i; */
/*       maxDotProd=fabs(scalarProd); */
/*     } */
/*   } */
/*   double scalarP=0.0; */
/*   hxtOr3DdotProd(uRef,dir+3*indMax,3, &scalarP); */
/*   if(scalarP<0) */
/*     sign=-1.0; */
/*   else */
/*     sign=1.0; */
/*   for(int i=0;i<3;i++) */
/*     newDir[i]=sign*dir[3*indMax+i]; */
  
/*   // find closest to vRef */
/*   maxDotProd=0.0; */
/*   indMax=0; */
/*   hxtOr3DdotProd(vRef,u,3, &maxDotProd); */
/*   maxDotProd=fabs(maxDotProd); */
/*   for(int i=1;i<3;i++){ */
/*     double scalarProd=0.0; */
/*     hxtOr3DdotProd(vRef,dir+3*i,3, &scalarProd); */
/*     if(fabs(scalarProd)>maxDotProd){ */
/*       indMax=i; */
/*       maxDotProd=fabs(scalarProd); */
/*     } */
/*   } */
/*   scalarP=0.0; */
/*   hxtOr3DdotProd(vRef,dir+3*indMax,3, &scalarP); */
/*   if(scalarP<0) */
/*     sign=-1.0; */
/*   else */
/*     sign=1.0; */
/*   for(int i=0;i<3;i++) */
/*     newDir[3+i]=sign*dir[3*indMax+i]; */

/*   // find closest to wRef */
/*   maxDotProd=0.0; */
/*   indMax=0; */
/*   hxtOr3DdotProd(wRef,u,3, &maxDotProd); */
/*   maxDotProd=fabs(maxDotProd); */
/*   for(int i=1;i<3;i++){ */
/*     double scalarProd=0.0; */
/*     hxtOr3DdotProd(wRef,dir+3*i,3, &scalarProd); */
/*     if(fabs(scalarProd)>maxDotProd){ */
/*       indMax=i; */
/*       maxDotProd=fabs(scalarProd); */
/*     } */
/*   } */
/*   scalarP=0.0; */
/*   hxtOr3DdotProd(wRef,dir+3*indMax,3, &scalarP); */
/*   if(scalarP<0) */
/*     sign=-1.0; */
/*   else */
/*     sign=1.0; */
/*   for(int i=0;i<3;i++) */
/*     newDir[6+i]=sign*dir[3*indMax+i]; */

/*   for(int i=0;i<9;i++) */
/*     dir[i]=newDir[i]; */
/*   return HXT_STATUS_OK; */
/* } */

HXTStatus hxtOr3DliftBasis(const double *dirRef, double *dir){
  const double *uRef=dirRef;
  const double *vRef=dirRef+3;
  const double *wRef=dirRef+6;
  double newDir[9]={0.0};
  
  // find closest to uRef
  double maxDotProd=-10.0;
  /* dotProd(uRef,u,3, &maxDotProd); */
  /* maxDotProd=fabs(maxDotProd); */
  int indMax=0;
  double sign=0.0;
  for(int i=0;i<3;i++){
    double scalarProd=0.0;
    hxtOr3DdotProd(uRef,dir+3*i,3, &scalarProd);
    if(fabs(scalarProd)>maxDotProd){
      indMax=i;
      maxDotProd=fabs(scalarProd);
    }
  }
  int prevInd=indMax;
  double scalarP=0.0;
  hxtOr3DdotProd(uRef,dir+3*indMax,3, &scalarP);
  if(scalarP<0)
    sign=-1.0;
  else
    sign=1.0;
  for(int i=0;i<3;i++)
    newDir[i]=sign*dir[3*indMax+i];
  
  // find closest to vRef
  maxDotProd=-10.0;
  indMax=0;
  /* dotProd(vRef,u,3, &maxDotProd); */
  /* maxDotProd=fabs(maxDotProd); */
  for(int i=0;i<3;i++){
    if(i!=prevInd){
      double scalarProd=0.0;
      hxtOr3DdotProd(vRef,dir+3*i,3, &scalarProd);
      if(fabs(scalarProd)>maxDotProd){
	indMax=i;
	maxDotProd=fabs(scalarProd);
      }
    }
  }
  int prevInd2=indMax;
  scalarP=0.0;
  hxtOr3DdotProd(vRef,dir+3*indMax,3, &scalarP);
  if(scalarP<0)
    sign=-1.0;
  else
    sign=1.0;
  for(int i=0;i<3;i++)
    newDir[3+i]=sign*dir[3*indMax+i];

  // find closest to wRef
  maxDotProd=-10.0;
  indMax=0;
  /* dotProd(wRef,u,3, &maxDotProd); */
  /* maxDotProd=fabs(maxDotProd); */
  for(int i=0;i<3;i++){
    if(i!=prevInd&&i!=prevInd2){
      double scalarProd=0.0;
      hxtOr3DdotProd(wRef,dir+3*i,3, &scalarProd);
      if(fabs(scalarProd)>maxDotProd){
	indMax=i;
	maxDotProd=fabs(scalarProd);
      }
    }
  }
  scalarP=0.0;
  hxtOr3DdotProd(wRef,dir+3*indMax,3, &scalarP);
  if(scalarP<0)
    sign=-1.0;
  else
    sign=1.0;
  for(int i=0;i<3;i++)
    newDir[6+i]=sign*dir[3*indMax+i];

  for(int i=0;i<9;i++)
    dir[i]=newDir[i];
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdirectionsToEulerTri(const double dirElem[9*3], const double dLdX[3][3], double eulerElem[3*3], int *flagLoc){
  *flagLoc=0;
  double flagNotUnique[3]={0.0};
  const double *dir=dirElem;
  for(int k=0;k<3;k++){
    double euler[3]={0.0};  
    dir=dirElem+9*k;
    hxtOr3DdirectionsToEuler(dir,flagNotUnique+k,euler);
    for(int j=0;j<3;j++)
      eulerElem[3*k+j]=euler[j];
  }

  int indRef=0;
  int elemNoNutation[3]={1,1,1};
  for(int k=0;k<3;k++)
    if(fabs(flagNotUnique[k])<1e-5){
      elemNoNutation[k]=0;
      indRef=k;
    }
  for(int k=0;k<3;k++)
    if(elemNoNutation[k])
      *flagLoc=1;
  /* //DBG */
  /* indRef=0; */
  double *eulerRef=eulerElem+3*indRef;

  //ICI
  /* printf("-----------------********************--------------------\n"); */
  /* printf("eulemNoNutation :\n"); */
  /* printf("%i %i %i %i\n",elemNoNutation[0],elemNoNutation[1],elemNoNutation[2],elemNoNutation[3]); */
  /* printf("indRef : %i\n",indRef); */
  /* printf("u : %g %g %g\n",dirElem[0],dirElem[1],dirElem[2]); */
  /* printf("v : %g %g %g\n",dirElem[3],dirElem[4],dirElem[5]); */
  /* printf("w : %g %g %g\n",dirElem[6],dirElem[7],dirElem[8]); */
  /* printf("-----------------********************--------------------\n"); */
  double normInit=0.0;
  /* printf("eulerRef :\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  double gradInit[3][3]={{0.0}};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
	gradInit[i][j]+=dLdX[k][j]*eulerElem[3*k+i];
      }
    }
  }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      normInit+=gradInit[i][j]*gradInit[i][j];
  
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*     printf("u:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]); */
  /*     printf("v:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]); */
  /*     printf("w:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]); */
  /*   } */
  /* } */

  //DBG solve periodicity here
  for(int k=0;k<3;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;
      for(int i=0;i<3;i++){
  	if(fabs(euler[i]-2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]-2*M_PI;
  	if(fabs(euler[i]+2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]+2*M_PI;
      }
    }
  }

  //DBG solve lock pb here //ICI  
  if(!elemNoNutation[indRef]){
    for(int k=0;k<3;k++){
      if((!(k==indRef))&&elemNoNutation[k]){
	double *euler=eulerElem+3*k;
	double sum = euler[0]+flagNotUnique[k]*euler[2];
	euler[2]=0.5*(flagNotUnique[k]*sum - flagNotUnique[k]*eulerRef[0] + eulerRef[2]);
	euler[0]=sum-flagNotUnique[k]*euler[2];
      }
    }
  }
  
  //DBG solve periodicity here
  for(int k=0;k<3;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;
      for(int i=0;i<3;i++){
  	if(fabs(euler[i]-2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]-2*M_PI;
  	if(fabs(euler[i]+2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]+2*M_PI;
      }
    }
  }
  
  /* //ICI */
  /* /\* double normInit=0.0; *\/ */
  /* printf("**********************val int\n"); */
  /* printf("eulerRef :\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*     /\* for(int l=0;l<3;l++) *\/ */
  /*     /\* 	normInit+=(euler[l]-eulerRef[l])*(euler[l]-eulerRef[l]); *\/ */
  /*   } */
  /* } */
  //DBG solve non unicity here
  for(int k=0;k<3;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;

      if(fabs(euler[0]-M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      	/* printf("case 1\n"); */
      	euler[0]=euler[0]-M_PI;
      	euler[2]=euler[2]-M_PI;
      	euler[1]=-euler[1];
      	if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=2*M_PI+euler[1];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=-2*M_PI+euler[1];
      	}
      	if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
      	  euler[2]=2*M_PI+euler[2];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[2]=-2*M_PI+euler[2];
      	}
      }
      if(fabs(euler[0]+M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      	/* printf("case 2\n"); */
      	euler[0]=euler[0]+M_PI;
      	euler[2]=euler[2]-M_PI;
      	euler[1]=-euler[1];
      	if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=2*M_PI+euler[1];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=-2*M_PI+euler[1];
      	}
      	if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
      	  euler[2]=2*M_PI+euler[2];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[2]=-2*M_PI+euler[2];
      	}
      }

      /* //ICI */
      /* double test[3]={euler[0],euler[1],euler[2]}; */
      /* if(fabs(test[0]-M_PI-eulerRef[0])<fabs(test[0]-eulerRef[0])){ */
      /* 	printf("case 1\n"); */
      /* 	test[0]=test[0]-M_PI; */
      /* 	test[2]=test[2]-M_PI; */
      /* 	test[1]=-test[1]; */
      /* 	if(fabs(2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=-2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(2*M_PI+test[2]-eulerRef[2])<fabs(test[2]-eulerRef[2])){ */
      /* 	  test[2]=2*M_PI+test[2]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[2]=-2*M_PI+test[2]; */
      /* 	} */
      /* } */
      /* if(fabs(test[0]+M_PI-eulerRef[0])<fabs(test[0]-eulerRef[0])){ */
      /* 	printf("case 2\n"); */
      /* 	test[0]=test[0]+M_PI; */
      /* 	test[2]=test[2]-M_PI; */
      /* 	test[1]=-test[1]; */
      /* 	if(fabs(2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=-2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(2*M_PI+test[2]-eulerRef[2])<fabs(test[2]-eulerRef[2])){ */
      /* 	  test[2]=2*M_PI+test[2]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[2]=-2*M_PI+test[2]; */
      /* 	} */
      /* } */
      /* double normTest=0.0; */
      /* for(int l=0;l<3;l++) */
      /* 	normTest+=(euler[l]-eulerRef[l])*(euler[l]-eulerRef[l]); */
      /* double normTestNew=0.0; */
      /* for(int l=0;l<3;l++) */
      /* 	normTestNew+=(test[l]-eulerRef[l])*(test[l]-eulerRef[l]); */
      /* if(fabs(normTestNew)<fabs(normTest)+1e-8){ */
      /* /\* if(1){ *\/ */
      /* 	euler[0]=test[0]; */
      /* 	euler[1]=test[1]; */
      /* 	euler[2]=test[2]; */
      /* } */
    }
  }


  

  //ICI
  double normFinal=0.0;
  double gradFinal[3][3]={{0.0}};
  /* printf("+++++++++++++++++++++++++++++++++++++\n"); */
  /* printf("eulerRef Final:\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
	gradFinal[i][j]+=dLdX[k][j]*eulerElem[3*k+i];
      }
    }
  }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      normFinal+=gradFinal[i][j]*gradFinal[i][j];
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*   } */
  /* } */
  /* if(fabs(normFinal)>fabs(normInit)+1e-8){ */
  /*   printf("normInit : %g\n",normInit); */
  /*   printf("normFinal : %g\n",normFinal); */
  /*   printf("Houston we have a pb\n"); */
  /*   /\* exit(0); *\/ */
  /* } */
  /* printf("-----------------********************--------------------\n"); */
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdirectionsToEulerTet(const double dirElem[9*4], const double dLdX[4][3], double eulerElem[3*4], int *flagLoc){
  *flagLoc=0;
  double flagNotUnique[4]={0.0};
  const double *dir=dirElem;
      
  for(int k=0;k<4;k++){
    double euler[3]={0.0};  
    dir=dirElem+9*k;
    hxtOr3DdirectionsToEuler(dir,flagNotUnique+k,euler);
    for(int j=0;j<3;j++)
      eulerElem[3*k+j]=euler[j];
  }

  int indRef=0;
  int elemNoNutation[4]={1,1,1,1};
  for(int k=0;k<4;k++)
    if(fabs(flagNotUnique[k])<1e-5){
      elemNoNutation[k]=0;
      indRef=k;
    }
  for(int k=0;k<4;k++)
    if(elemNoNutation[k])
      *flagLoc=1;
  /* //DBG */
  /* indRef=0; */
  double *eulerRef=eulerElem+3*indRef;

  //ICI
  /* printf("-----------------********************--------------------\n"); */
  /* printf("eulemNoNutation :\n"); */
  /* printf("%i %i %i %i\n",elemNoNutation[0],elemNoNutation[1],elemNoNutation[2],elemNoNutation[3]); */
  /* printf("indRef : %i\n",indRef); */
  /* printf("u : %g %g %g\n",dirElem[0],dirElem[1],dirElem[2]); */
  /* printf("v : %g %g %g\n",dirElem[3],dirElem[4],dirElem[5]); */
  /* printf("w : %g %g %g\n",dirElem[6],dirElem[7],dirElem[8]); */
  /* printf("-----------------********************--------------------\n"); */
  double normInit=0.0;
  /* printf("eulerRef :\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  double gradInit[3][3]={{0.0}};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<4;k++){
	gradInit[i][j]+=dLdX[k][j]*eulerElem[3*k+i];
      }
    }
  }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      normInit+=gradInit[i][j]*gradInit[i][j];
  
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*     printf("u:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]); */
  /*     printf("v:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]); */
  /*     printf("w:\n"); */
  /*     printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]); */
  /*   } */
  /* } */

  //DBG solve periodicity here
  for(int k=0;k<4;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;
      for(int i=0;i<3;i++){
  	if(fabs(euler[i]-2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]-2*M_PI;
  	if(fabs(euler[i]+2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]+2*M_PI;
      }
    }
  }

  //DBG solve lock pb here //ICI  
  if(!elemNoNutation[indRef]){
    for(int k=0;k<4;k++){
      if((!(k==indRef))&&elemNoNutation[k]){
	double *euler=eulerElem+3*k;
	double sum = euler[0]+flagNotUnique[k]*euler[2];
	euler[2]=0.5*(flagNotUnique[k]*sum - flagNotUnique[k]*eulerRef[0] + eulerRef[2]);
	euler[0]=sum-flagNotUnique[k]*euler[2];
      }
    }
  }
  
  //DBG solve periodicity here
  for(int k=0;k<4;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;
      for(int i=0;i<3;i++){
  	if(fabs(euler[i]-2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]-2*M_PI;
  	if(fabs(euler[i]+2*M_PI-eulerRef[i])<fabs(euler[i]-eulerRef[i]))
  	  euler[i]=euler[i]+2*M_PI;
      }
    }
  }
  
  /* //ICI */
  /* /\* double normInit=0.0; *\/ */
  /* printf("**********************val int\n"); */
  /* printf("eulerRef :\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*     /\* for(int l=0;l<3;l++) *\/ */
  /*     /\* 	normInit+=(euler[l]-eulerRef[l])*(euler[l]-eulerRef[l]); *\/ */
  /*   } */
  /* } */
  //DBG solve non unicity here
  for(int k=0;k<4;k++){
    if(!(k==indRef)){
      double *euler=eulerElem+3*k;

      if(fabs(euler[0]-M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      	/* printf("case 1\n"); */
      	euler[0]=euler[0]-M_PI;
      	euler[2]=euler[2]-M_PI;
      	euler[1]=-euler[1];
      	if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=2*M_PI+euler[1];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=-2*M_PI+euler[1];
      	}
      	if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
      	  euler[2]=2*M_PI+euler[2];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[2]=-2*M_PI+euler[2];
      	}
      }
      if(fabs(euler[0]+M_PI-eulerRef[0])<fabs(euler[0]-eulerRef[0])){
      	/* printf("case 2\n"); */
      	euler[0]=euler[0]+M_PI;
      	euler[2]=euler[2]-M_PI;
      	euler[1]=-euler[1];
      	if(fabs(2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=2*M_PI+euler[1];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[1]=-2*M_PI+euler[1];
      	}
      	if(fabs(2*M_PI+euler[2]-eulerRef[2])<fabs(euler[2]-eulerRef[2])){
      	  euler[2]=2*M_PI+euler[2];
      	}
      	if(fabs(-2*M_PI+euler[1]-eulerRef[1])<fabs(euler[1]-eulerRef[1])){
      	  euler[2]=-2*M_PI+euler[2];
      	}
      }

      /* //ICI */
      /* double test[3]={euler[0],euler[1],euler[2]}; */
      /* if(fabs(test[0]-M_PI-eulerRef[0])<fabs(test[0]-eulerRef[0])){ */
      /* 	printf("case 1\n"); */
      /* 	test[0]=test[0]-M_PI; */
      /* 	test[2]=test[2]-M_PI; */
      /* 	test[1]=-test[1]; */
      /* 	if(fabs(2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=-2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(2*M_PI+test[2]-eulerRef[2])<fabs(test[2]-eulerRef[2])){ */
      /* 	  test[2]=2*M_PI+test[2]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[2]=-2*M_PI+test[2]; */
      /* 	} */
      /* } */
      /* if(fabs(test[0]+M_PI-eulerRef[0])<fabs(test[0]-eulerRef[0])){ */
      /* 	printf("case 2\n"); */
      /* 	test[0]=test[0]+M_PI; */
      /* 	test[2]=test[2]-M_PI; */
      /* 	test[1]=-test[1]; */
      /* 	if(fabs(2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[1]=-2*M_PI+test[1]; */
      /* 	} */
      /* 	if(fabs(2*M_PI+test[2]-eulerRef[2])<fabs(test[2]-eulerRef[2])){ */
      /* 	  test[2]=2*M_PI+test[2]; */
      /* 	} */
      /* 	if(fabs(-2*M_PI+test[1]-eulerRef[1])<fabs(test[1]-eulerRef[1])){ */
      /* 	  test[2]=-2*M_PI+test[2]; */
      /* 	} */
      /* } */
      /* double normTest=0.0; */
      /* for(int l=0;l<3;l++) */
      /* 	normTest+=(euler[l]-eulerRef[l])*(euler[l]-eulerRef[l]); */
      /* double normTestNew=0.0; */
      /* for(int l=0;l<3;l++) */
      /* 	normTestNew+=(test[l]-eulerRef[l])*(test[l]-eulerRef[l]); */
      /* if(fabs(normTestNew)<fabs(normTest)+1e-8){ */
      /* /\* if(1){ *\/ */
      /* 	euler[0]=test[0]; */
      /* 	euler[1]=test[1]; */
      /* 	euler[2]=test[2]; */
      /* } */
    }
  }


  

  //ICI
  double normFinal=0.0;
  double gradFinal[3][3]={{0.0}};
  /* printf("+++++++++++++++++++++++++++++++++++++\n"); */
  /* printf("eulerRef Final:\n"); */
  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<4;k++){
	gradFinal[i][j]+=dLdX[k][j]*eulerElem[3*k+i];
      }
    }
  }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      normFinal+=gradFinal[i][j]*gradFinal[i][j];
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*   } */
  /* } */
  /* if(fabs(normFinal)>fabs(normInit)+1e-8){ */
  /*   printf("normInit : %g\n",normInit); */
  /*   printf("normFinal : %g\n",normFinal); */
  /*   printf("Houston we have a pb\n"); */
  /*   /\* exit(0); *\/ */
  /* } */
  /* printf("-----------------********************--------------------\n"); */
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DframesToEulerDataTet(const double *framesElem, const double dLdX[4][3],double eulerElem[3*4],double gradPsi[3],double gradTheta[3],double gradPhi[3]){
  //Computing coherent euler angles on element
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(framesElem, stableDir, refDir);
  hxtOr3DmakeOrientationDirect(refDir);
  for(int i=0;i<12;i++)
    eulerElem[i]=0.0;
  double dirElem[9*4]={0.0};
  for(int i=0;i<9;i++){
    dirElem[i]=refDir[i];
  }
  for(int k=1;k<4;k++){
    const double *frameK=framesElem+9*k;
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    hxtOr3DliftBasis(refDir,dirK);
    for(int i=0;i<9;i++){
      dirElem[9*k+i]=dirK[i];
    }
  }
  int flagLoc=0;
  hxtOr3DdirectionsToEulerTet(dirElem,dLdX,eulerElem,&flagLoc);
  /* double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3]; */
  /* //DBG test */
  /* for(int k=0;k<3;k++){ */
  /*   getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1); */
  /*   double diffTest[3*3]={0.0};//ICI */
  /*   for(int j=0;j<3;j++){ */
  /*     diffTest[j]=dirElem[9*k+j]-u[j]; */
  /*     diffTest[3+j]=dirElem[9*k+3+j]-v[j]; */
  /*     diffTest[6+j]=dirElem[9*k+6+j]-w[j]; */
  /*   } */
  /*   double normDiff=0.0; */
  /*   hxtNorm2V(diffTest, 9, &normDiff); */
  /*   /\* if(normDiff>1e-10){ *\/ */
  /*   /\*   printf("ok pb ici: normDiff = %g\n",normDiff); *\/ */
  /*   /\*   printf("euler :\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",eulerElem[0],eulerElem[1],eulerElem[2]); *\/ */
  /*   /\*   printf("u:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]); *\/ */
  /*   /\*   printf("uRebuilt:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",u[0],u[1],u[2]); *\/ */
  /*   /\*   printf("v:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]); *\/ */
  /*   /\*   printf("vRebuilt:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",v[0],v[1],v[2]); *\/ */
  /*   /\*   printf("w:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]); *\/ */
  /*   /\*   printf("wRebuilt:\n"); *\/ */
  /*   /\*   printf("%g %g %g\n",w[0],w[1],w[2]); *\/ */
  /*   /\*   exit(0); *\/ */
  /*   /\* } *\/ */
  /* } */
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};
  
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }

  //Compute euler angles gradient
  for(int k=0;k<3;k++){
    gradPsi[k]=0.0;
    gradTheta[k]=0.0;
    gradPhi[k]=0.0;
  }
  for (int j = 0; j < 3; ++j){
    for (int k = 0; k < 4; ++k){
      gradPsi[j]+=dLdX[k][j]*psiElem[k];
      gradTheta[j]+=dLdX[k][j]*thetaElem[k];
      gradPhi[j]+=dLdX[k][j]*phiElem[k];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdotProd(const double *u, const double *v, const int sizeVect, double *scalarProd){
  *scalarProd=0.0;
  for(int i=0;i<sizeVect;i++){
    (*scalarProd)+=u[i]*v[i];
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdyadicProd3(const double u[3], const double v[3], double dyadicProd[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      dyadicProd[i][j]=u[i]*v[j];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DsumMat3x3(const double A[3][3], const double B[3][3], double sum[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      sum[i][j]=A[i][j]+B[i][j];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DgetRankMat9x3(const double mat[9][3], int baseVect[3], int *rank){
  double u[9]={0.0};
  double v[9]={0.0};
  double w[9]={0.0};  
  for(int k=0;k<9;k++){
    u[k]=mat[k][0];
    v[k]=mat[k][1];
    w[k]=mat[k][2];
  }
  double normU=0.0;
  hxtNorm2V(u, 9, &normU);
  double normV=0.0;
  hxtNorm2V(v, 9, &normV);
  double normW=0.0;
  hxtNorm2V(w, 9, &normW);
  if(normU<=1e-10 && normV<=1e-10 && normW<=1e-10){
    *rank=0;
    return HXT_STATUS_OK;
  }
  if(normU>1e-10)
    hxtNormalizeV(u, 9);
  if(normV>1e-10)
    hxtNormalizeV(v, 9);
  if(normW>1e-10)
    hxtNormalizeV(w, 9);
  double sUV=0.0;
  hxtOr3DdotProd(u, v, 9, &sUV);
  double sUW=0.0;
  hxtOr3DdotProd(u, w, 9, &sUW);
  double sVW=0.0;
  hxtOr3DdotProd(v, w, 9, &sVW);
  double uOrth[9]={0.0};
  double vOrth[9]={0.0};
  double wOrth[9]={0.0};
  for(int k=0;k<9;k++){
    uOrth[k]=u[k]-(sUV*v[k]+sUW*w[k]);
    vOrth[k]=v[k]-(sUV*u[k]+sVW*w[k]);
    wOrth[k]=w[k]-(sUW*u[k]+sVW*v[k]);
  }
  double normUOrth=0.0;
  hxtNorm2V(uOrth, 9, &normUOrth);
  double normVOrth=0.0;
  hxtNorm2V(vOrth, 9, &normVOrth);
  double normWOrth=0.0;
  hxtNorm2V(wOrth, 9, &normWOrth);
  double tolRank=1e-4;
  if(normUOrth>tolRank && normVOrth>tolRank && normWOrth>tolRank){
    *rank=3;
    for(int k=0;k<3;k++)
      baseVect[k]=1;
    return HXT_STATUS_OK;
  }
  else{
    if(normWOrth<=tolRank){
      if(normU<=1e-10){
	*rank=1;
	baseVect[0]=-1;
        baseVect[1]=1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      if(normV<=1e-10){
	*rank=1;
	baseVect[0]=1;
        baseVect[1]=-1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      double uOrthV[9]={0.0};
      for(int k=0;k<9;k++)
	uOrthV[k]=u[k]-(sUV*v[k]);
      double normUOrthV=0.0;
      hxtNorm2V(uOrthV, 9, &normUOrthV);
      if(normUOrthV<=tolRank){
	*rank=1;
	baseVect[0]=1;
        baseVect[1]=-1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      else{
	*rank=2;
	baseVect[0]=1;
        baseVect[1]=1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
    }
    else if(normVOrth<=tolRank){
      if(normU<=1e-10){
	*rank=1;
	baseVect[0]=-1;
        baseVect[1]=-1;
        baseVect[2]=1;
	return HXT_STATUS_OK;
      }
      if(normW<=1e-10){
	*rank=1;
	baseVect[0]=1;
        baseVect[1]=-1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      double uOrthW[9]={0.0};
      for(int k=0;k<9;k++)
	uOrthW[k]=u[k]-(sUW*w[k]);
      double normUOrthW=0.0;
      hxtNorm2V(uOrthW, 9, &normUOrthW);
      if(normUOrthW<=tolRank){
	*rank=1;
	baseVect[0]=1;
        baseVect[1]=-1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      else{
	*rank=2;
	baseVect[0]=1;
        baseVect[1]=-1;
        baseVect[2]=1;
	return HXT_STATUS_OK;
      }
    }
    else if(normUOrth<=tolRank){
      if(normV<=1e-10){
	*rank=1;
	baseVect[0]=-1;
        baseVect[1]=-1;
        baseVect[2]=1;
	return HXT_STATUS_OK;
      }
      if(normW<=1e-10){
	*rank=1;
	baseVect[0]=-1;
        baseVect[1]=1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      double vOrthW[9]={0.0};
      for(int k=0;k<9;k++)
	vOrthW[k]=v[k]-(sVW*w[k]);
      double normVOrthW=0.0;
      hxtNorm2V(vOrthW, 9, &normVOrthW);
      if(normVOrthW<=tolRank){
	*rank=1;
	baseVect[0]=-1;
        baseVect[1]=1;
        baseVect[2]=-1;
	return HXT_STATUS_OK;
      }
      else{
	*rank=2;
	baseVect[0]=-1;
        baseVect[1]=1;
        baseVect[2]=1;
	return HXT_STATUS_OK;
      }
    }
    else{
      printf("pb in rank computation in rank<3\n");
      exit(0);
    }
  }
  printf("pb in rank computation\n");
  return HXT_STATUS_ERROR;
}

HXTStatus hxtOr3DpseudoInv9x3(const double mat[9][3], double pseudoInv[3][9]){
  int baseVect[3]={0,0,0};
  int rank = 0.0;
  hxtOr3DgetRankMat9x3(mat,baseVect,&rank);
  double u[9]={0.0};
  double v[9]={0.0};
  double w[9]={0.0};
  for(int k=0;k<9;k++){
    u[k]=mat[k][0];
    v[k]=mat[k][1];
    w[k]=mat[k][2];
  }
  double normU=0.0;
  hxtNorm2V(u, 9, &normU);
  double normV=0.0;
  hxtNorm2V(v, 9, &normV);
  double normW=0.0;
  hxtNorm2V(w, 9, &normW);
  
  switch(rank){
  case 0:
    {
      double pInv[3][9]={{0.0}};
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  pseudoInv[i][j]=pInv[i][j];
      break;
    }
  case 1:
    {
      printf("rank1 pInv computation\n");
      double *vectRef=NULL;
      double normRef=0.0;
      if(normU>1e-10){
	vectRef=u;
	normRef=normU;
      }
      else if(normV>1e-10){
	vectRef=v;
	normRef=normV;
      }
      else if(normW>1e-10){
	vectRef=w;
	normRef=normW;
      }
      else{
	printf("pb result rank\n");
	exit(0);
      }
      double B[9][1]={{0.0}};
      double C[1][3]={{0.0}};
      for(int j=0;j<9;j++)
	B[j][0]=vectRef[j];
      double sUvRef=0.0;
      double sVvRef=0.0;
      double sWvRef=0.0;
      hxtOr3DdotProd(u, vectRef, 9, &sUvRef);
      hxtOr3DdotProd(v, vectRef, 9, &sVvRef);
      hxtOr3DdotProd(w, vectRef, 9, &sWvRef);
      if(normU<1e-10)
	normU=1;
      C[0][0] = sUvRef/(normU*normRef);
      if(normV<1e-10)
	normV=1;
      C[0][1] = sVvRef/(normV*normRef);
      if(normW<1e-10)
	normW=1;
      C[0][2] = sWvRef/(normW*normRef);
      double BtB=0.0;
      double CCt=0.0;
      for(int j=0;j<9;j++)
	BtB+=B[j][0]*B[j][0];
      for(int k=0;k<3;k++)
	CCt+=C[0][k]*C[0][k];
      double pInv[3][9]={{0.0}};
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  pInv[i][j]+=C[0][i]*B[j][0]/(CCt*BtB);
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  pseudoInv[i][j]=pInv[i][j];
      break;
    }
  case 2:
    {
      /* printf("rank2 pInv computation\n"); */
      double vectRef1[9]={0.0};
      double vectRef2[9]={0.0};
      int nBaseGet=0;
      for(int k=0;k<3;k++){
	if(baseVect[k]==1){
	  if(nBaseGet==0){
	    if(k==0){
	      for(int j=0;j<9;j++)
		vectRef1[j]=u[j];
	      nBaseGet++;
	    }
	    else if(k==1){
	      for(int j=0;j<9;j++)
		vectRef1[j]=v[j];
	      nBaseGet++;
	    }
	    else{
	      printf("pb in baseVect\n");
	      exit(0);
	    }
	  }
	  else if(nBaseGet==1){
	    if(k==1){
	      for(int j=0;j<9;j++)
		vectRef2[j]=v[j];
	      nBaseGet++;
	    }
	    else if(k==2){
	      for(int j=0;j<9;j++)
		vectRef2[j]=w[j];
	      nBaseGet++;
	    }
	    else{
	      printf("pb in baseVect\n");
	      exit(0);
	    }
	  }	    
	}
      }
      double normRef1 = 0.0;
      hxtNorm2V(vectRef1, 9, &normRef1);
      double normRef2 = 0.0;
      hxtNorm2V(vectRef2, 9, &normRef2);
      /* printf("----------------norm vects ref -----------------------\n"); */
      /* printf("%g\n",normRef1); */
      /* printf("%g\n",normRef2); */
      /* printf("------------------------------------------------------\n"); */
      double B[9][2]={{0.0}};
      double C[2][3]={{0.0}};
      for(int j=0;j<9;j++)
	B[j][0]=vectRef1[j];
      for(int j=0;j<9;j++)
	B[j][1]=vectRef2[j];
      double sUvRef1=0.0;
      double sVvRef1=0.0;
      double sWvRef1=0.0;
      hxtOr3DdotProd(u, vectRef1, 9, &sUvRef1);
      hxtOr3DdotProd(v, vectRef1, 9, &sVvRef1);
      hxtOr3DdotProd(w, vectRef1, 9, &sWvRef1);
      double sUvRef2=0.0;
      double sVvRef2=0.0;
      double sWvRef2=0.0;
      hxtOr3DdotProd(u, vectRef2, 9, &sUvRef2);
      hxtOr3DdotProd(v, vectRef2, 9, &sVvRef2);
      hxtOr3DdotProd(w, vectRef2, 9, &sWvRef2);
      if(normU<1e-10)
	normU=1;
      if(normV<1e-10)
	normV=1;
      if(normW<1e-10)
	normW=1;
      C[0][0] = sUvRef1/(normU*normRef1);
      C[1][0] = sUvRef2/(normU*normRef2);
      C[0][1] = sVvRef1/(normV*normRef1);
      C[1][1] = sVvRef2/(normV*normRef2);
      C[0][2] = sWvRef1/(normW*normRef1);
      C[1][2] = sWvRef2/(normW*normRef2);
      double BtB[2][2]={{0.0}};
      double CCt[2][2]={{0.0}};
      for(int l=0;l<2;l++)
	for(int k=0;k<2;k++)
	  for(int j=0;j<9;j++)
	    BtB[l][k]+=B[j][l]*B[j][k];
      for(int l=0;l<2;l++)
	for(int k=0;k<2;k++)
	  for(int j=0;j<3;j++)
	    CCt[l][k]+=C[l][j]*C[k][j];
      double invBtB[2][2]={{0.0}};
      double invCCt[2][2]={{0.0}};
      double det;
      HXT_CHECK(hxtInv2x2(BtB, invBtB, &det));
      HXT_CHECK(hxtInv2x2(CCt, invCCt, &det));
      double pInv[3][9]={{0.0}};
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  for(int k=0;k<2;k++)
	    for(int l=0;l<2;l++)
	      for(int m=0;m<2;m++)
		pInv[i][j]+=C[k][i]*invCCt[k][l]*invBtB[l][m]*B[j][m];
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++){
	  pseudoInv[i][j]=pInv[i][j];
	  /* pritnf("val : %g\n",pseudoInv[i][j]); */
	}
      
      break;
    }
  case 3:
    {
      /* printf("rank 3 pInv computation\n"); */
      double intMat[3][3]={{0.0}};
      for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	  for(int k=0;k<9;k++)
	    intMat[i][j]+=mat[k][i]*mat[k][j];
      double invIntMat[3][3]={{0.0}};
      double det=0.0;
      HXT_CHECK(hxtInv3x3(intMat, invIntMat, &det));
      double pInv[3][9]={{0.0}};
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  for(int k=0;k<3;k++)
	    pInv[i][j]+=invIntMat[i][k]*mat[j][k];
      for(int i=0;i<3;i++)
	for(int j=0;j<9;j++)
	  pseudoInv[i][j]=pInv[i][j];
      break;
    default:
      printf("Pb rank dBdEuler\n");
      exit(0);
      break;
    }
  }
  hxtOr3DcheckIfPinvOk(mat, pseudoInv);
  return HXT_STATUS_OK;
}


//DBG fcts
HXTStatus hxtOr3DcheckIfBasisDirect(const double basis[9]){
  const double *u=basis;
  const double *v=basis+3;
  const double *w=basis+6;
  double n[3]={0.0};
  hxtCrossProductV3(u, v, n);
  double scalarP=0.0;
  hxtOr3DdotProd(n, w, 3, &scalarP);
  if(scalarP<0){
    printf("Basis not direct, exiting.....\n");
    printf("u : %g %g %g\n",u[0],u[1],u[2]);
    printf("v : %g %g %g\n",v[0],v[1],v[2]);
    printf("w : %g %g %g\n",w[0],w[1],w[2]);
    exit(0);
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DprintBase(const double basis[9]){
  const double *u=basis;
  const double *v=basis+3;
  const double *w=basis+6;
  printf("u : %g %g %g\n",u[0],u[1],u[2]);
  printf("v : %g %g %g\n",v[0],v[1],v[2]);
  printf("w : %g %g %g\n",w[0],w[1],w[2]);  
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DcheckIfPinvOk(const double A[9][3], const double pInvA[3][9]){
    //Checking if pseudo inverse is ok
  double p1[9][3]={{0.0}};
  double p2[3][9]={{0.0}};
  double p3[9][9]={{0.0}};
  double p4[3][3]={{0.0}};

  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
	for(int l=0;l<9;l++)
	  p1[i][j]+=A[i][k]*pInvA[k][l]*A[l][j];	  
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      p1[i][j]-=A[i][j];
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      for(int k=0;k<9;k++)
	for(int l=0;l<3;l++)
	  p2[i][j]+=pInvA[i][k]*A[k][l]*pInvA[l][j];
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      p2[i][j]-=pInvA[i][j];
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<9;k++)
	p3[i][k]+=A[i][j]*pInvA[j][k];
  for(int i=0;i<9;i++)
    for(int j=i;j<9;j++){
      double temp=p3[i][j];
      p3[i][j]-=p3[j][i];
      if(i!=j)
	p3[j][i]-=temp;
    }
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      for(int k=0;k<3;k++)
	p4[i][k]+=pInvA[i][j]*A[j][k];
  for(int i=0;i<3;i++)
    for(int k=i;k<3;k++){
      double temp=p4[i][k];
      p4[i][k]-=p4[k][i];
      if(i!=k)
	p4[k][i]-=temp;
    }

  double valP1=0.0;
  double valP2=0.0;
  double valP3=0.0;
  double valP4=0.0;
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++){
      valP1+=p1[i][j]*p1[i][j];
      valP2+=p2[j][i]*p2[j][i];
    }
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++){
      valP3+=p3[i][j]*p3[i][j];
    }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      valP4+=p4[i][j]*p4[i][j];
    }

  double tolPInv=1e-4;
  if(sqrt(valP1)>tolPInv||sqrt(valP2)>tolPInv||sqrt(valP3)>tolPInv||sqrt(valP4)>tolPInv){
    int baseVect[3];
    int rank=0;
    hxtOr3DgetRankMat9x3(A,baseVect,&rank);
    printf("pb with pseudo inverse\n");
    printf("rank : %i\n",rank);
    printf("A\n");
    for(int i=0;i<9;i++)
      printf("%g // %g // %g\n",A[i][0],A[i][1],A[i][2]);
    printf("---------------\n");
    printf("pInvA\n");
    for(int i=0;i<3;i++)
      printf("%g // %g // %g // %g // %g // %g // %g // %g // %g\n",pInvA[i][0],pInvA[i][1],pInvA[i][2],pInvA[i][3],pInvA[i][4],pInvA[i][5],pInvA[i][6],pInvA[i][7],pInvA[i][8]);
    double id[3][3]={{0.0}};
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
	for(int k=0;k<9;k++)
	  id[i][j]+=A[k][i]*pInvA[j][k];
    printf("id\n");
    for(int i=0;i<3;i++)
      printf("%g // %g // %g\n",id[i][0],id[i][1],id[i][2]);
    printf("values check pInv\n");
    printf("first  : %g // %g // %g // %g\n",sqrt(valP1),sqrt(valP2),sqrt(valP3),sqrt(valP4));
    /* exit(0); */
  }
  //
  return HXT_STATUS_OK;
}

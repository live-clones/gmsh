#include "hxt_orientation3d_implicit.h"
/* #include "hxt_orientation3d.h" */
#include "hxt_orientation3d_tools.h"
#include "hxt_tools.h"

#include <math.h>
#include "OpenNL_psm.h"
#define Cos cos
#define Sin sin

static double Power(const double x, const unsigned int i) {
  switch (i) {
    case 2 : return x*x;
    case 3 : return x*x*x;
    case 4 : {const double temp = x*x ; return temp*temp;}
  }
  HXT_ASSERT_MSG(0, "Power %i not defined", i);
  return 0.;
}

// THE 9 linear combinations correponding to the 9 affinely independant components of cross U
// A_{1111} = R_{11}^4 + R_{12}^4  R_{13}^4
// A_{2222} = R_{21}^4 + R_{22}^4  R_{23}^4
// A_{3333} = R_{31}^4 + R_{32}^4  + R_{33}^4
// A_{2322} = R_{21}^3 R_{31} + R_{22}^3 R_{32} +  R_{23}^3 R_{33}
// A_{2333} = R_{31}^3 R_{21} + R_{32}^3 R_{22} +  R_{33}^3 R_{23}
// A_{1113} = R_{11}^3 R_{31} + R_{12}^3 R_{32} +  R_{13}^3 R_{33}
// A_{3331} = R_{31}^3 R_{11} + R_{32}^3 R_{12} +  R_{33}^3 R_{13}
// A_{1112} = R_{11}^3 R_{21} + R_{12}^3 R_{22} +  R_{13}^3 R_{23}
// A_{2221} = R_{21}^3 R_{11} + R_{22}^3 R_{12} +  R_{23}^3 R_{13}
HXTStatus computeCombinationOnBorder(double a, double b, double c[9][2], double d[9]) {
  /* c[0][0] =  (9 + 20*Cos(2*a) + 35*Cos(4*a) - 16*(5 + 7*Cos(2*a))*Cos(2*b)*Power(Sin(a),2) + 8*Cos(4*b)*Power(Sin(a),4))/256.; */
  /* c[0][1] =  -(Cos(b)*(1 + 3*Cos(2*a) - 2*Cos(2*b)*Power(Sin(a),2))*Sin(2*a))/8.; */
  /* c[1][0] =  (9 - 20*Cos(2*a) + 35*Cos(4*a) + 16*Power(Cos(a),2)*(-5 + 7*Cos(2*a))*Cos(2*b) +      8*Power(Cos(a),4)*Cos(4*b))/256.; */
  /* c[1][1] =  -(Cos(b)*(-1 + 3*Cos(2*a) + 2*Power(Cos(a),2)*Cos(2*b))*Sin(2*a))/8.; */
  /* c[2][0] = Power(Sin(b),4)/4.; */
  /* c[2][1] = 0; */
  /* c[3][0] =  (-3*Cos(a)*Sin(2*b) + 7*Cos(3*a)*Sin(2*b) + 2*Power(Cos(a),3)*Sin(4*b))/64. ; */
  /* c[3][1] =  (-7*Sin(3*a)*Sin(b) + 3*Sin(a)*(3*Sin(b) - 4*Power(Cos(a),2)*Sin(3*b)))/64. ; */
  /* c[4][0] = (Cos(a)*Cos(b)*Power(Sin(b),3))/4.; */
  /* c[4][1] = -(Sin(a)*Power(Sin(b),3))/4.; */
  /* c[5][0] =  (7*Sin(3*a)*Sin(2*b) + Cos(2*b)*Sin(3*a)*Sin(2*b) +      6*Sin(a)*Power(Sin(b),2)*Sin(2*b))/64.; */
  /* c[5][1] =  (12*Cos(a)*Power(Sin(b),3) + Cos(3*a)*(7*Sin(b) + 3*Sin(3*b)))/64.; */
  /* c[6][0] = -(Cos(b)*Sin(a)*Power(Sin(b),3))/4.; */
  /* c[6][1] = -(Cos(a)*Power(Sin(b),3))/4.; */
  /* c[7][0] =  (-8*Cos(a)*Cos(4*b)*Power(Sin(a),3) + 10*Sin(2*a) - 8*Cos(2*b)*Sin(2*a) +      35*Sin(4*a) + 28*Cos(2*b)*Sin(4*a))/256.; */
  /* c[7][1] =  (8*(Cos(2*a) + 7*Cos(4*a))*Cos(b) -      16*(1 + 2*Cos(2*a))*Cos(3*b)*Power(Sin(a),2))/256.; */
  /* c[8][0] =  (-8*Power(Cos(a),3)*Cos(4*b)*Sin(a) + 10*Sin(2*a) - 8*Cos(2*b)*Sin(2*a) -      35*Sin(4*a) - 28*Cos(2*b)*Sin(4*a))/256.; */
  /* c[8][1] =  (8*(Cos(2*a) - 7*Cos(4*a))*Cos(b) +      16*Power(Cos(a),2)*(1 - 2*Cos(2*a))*Cos(3*b))/256.; */
  /* d[0] = (3*(53 + 4*Cos(2*a) + 7*Cos(4*a)) + 16*(5 + 7*Cos(2*a))*Cos(2*b)*Power(Sin(a),2) + 56*Cos(4*b)*Power(Sin(a),4))/256.; */
  /* d[1] = (3*(53 - 4*Cos(2*a) + 7*Cos(4*a)) +      16*Power(Cos(a),2)*(5 - 7*Cos(2*a))*Cos(2*b) +      56*Power(Cos(a),4)*Cos(4*b))/256.; */
  /* d[2] = (4*Cos(2*b) + 7*(3 + Cos(4*b)))/32.; */
  /* d[3] = ((3*Cos(a) - 7*Cos(3*a))*Sin(2*b) + 14*Power(Cos(a),3)*Sin(4*b))/64.; */
  /* d[4] = -(Cos(a)*(2*Sin(2*b) + 7*Sin(4*b)))/32.; */
  /* d[5] = -(Cos(b)*Sin(b)*(3*(1 + 7*Cos(2*b))*Sin(a) + 14*Sin(3*a)*Power(Sin(b),2)))/   32.; */
  /* d[6] = (Sin(a)*(2*Sin(2*b) + 7*Sin(4*b)))/32.; */
  /* d[7] = (-56*Cos(a)*Cos(4*b)*Power(Sin(a),3) + (6 + 8*Cos(2*b))*Sin(2*a) +      7*(3 - 4*Cos(2*b))*Sin(4*a))/256.; */
  /* d[8] = (-56*Power(Cos(a),3)*Cos(4*b)*Sin(a) + (6 + 8*Cos(2*b))*Sin(2*a) +      7*(-3 + 4*Cos(2*b))*Sin(4*a))/256.; */

  
  /* printf("d = ["); */
  /* for(int i=0;i<9;i++){ */
  /*   printf("%12.5E ",d[i]); */
  /* } */
  /* printf("]"); */
  /* printf("\n"); */
  double v0Old[9], v1Old[9], v2Old[9];
  double v0[9], v1[9], v2[9];
  double euler[3]={a,b,0};
  hxtOrientation3DeulerToFrame(v0Old, euler);
  oldBasisToNewBasis(v0Old, v0);
  euler[2]=M_PI/8;
  hxtOrientation3DeulerToFrame(v1Old, euler);
  oldBasisToNewBasis(v1Old, v1);
  euler[2]=M_PI/4;
  hxtOrientation3DeulerToFrame(v2Old, euler);
  oldBasisToNewBasis(v2Old, v2);

  for (int i=0;i<9;i++){
    d[i]    = 0.5*(v0[i]+v2[i]);
    c[i][0] = v0[i]-d[i];
    c[i][1] = v1[i]-d[i];
  }
  /* printf("c = ["); */
  /* for(int i=0;i<9;i++){ */
  /*   printf("%12.5E %12.5E\n",c[i][0],c[i][1]); */
  /* } */
  /* printf("]"); */
  /* printf("\n"); */

  /* printf("d2 = ["); */
  /* for(int i=0;i<9;i++){ */
  /*   printf("%12.5E ",d[i]); */
  /* } */
  /* printf("]"); */
  /* printf("\n"); */
  return HXT_STATUS_OK;
}

static double det2x2(const double mat[2][2]) {
  return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
}

static HXTStatus inv2x2(const double mat[2][2], double inv[2][2], double *det) {
  *det = det2x2(mat);
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

static HXTStatus computeBoundaryConstraintMatrix(const double C[9][2], double B[9][9]) {
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
  HXT_CHECK(inv2x2(S, iS, &dS));

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

  /* B = Bint^T.B */
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

static HXTStatus computeBoundaryRhsContribution(const double B[9][9], const double D[9], double rhs[9]) {
  for(uint8_t i=0;i<9;i++){
    rhs[i]=0;
    for(uint8_t k=0;k<9;k++){
      rhs[i] += B[i][k] * D[k];
    }
  }
  return HXT_STATUS_OK;
}


// UTILS --- from GMSH --------------------------------------------------------------------------------------------------

static double det3x3(const double mat[3][3])
{
  return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
      mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
      mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
}


static HXTStatus inv3x3(const double mat[3][3], double inv[3][3], double *det)
{
  *det = det3x3(mat);
  if(det) {
    double ud = 1. / *det;
    inv[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
  } else {
    return HXT_STATUS_ERROR;
  }
  return HXT_STATUS_OK;
}



static void jacobianTet ( const double *x , const double *y, const double *z , double mat[3][3] ){

  // SF   = {1-u-v-w, u, v, w};
  // SF_u = {-1, 1, 0, 0};
  // SF_v = {-1, 0, 1, 0};
  // SF_w = {-1, 0, 0, 1};

  /* mat[0][0] = x[1] - x[0]; */
  /* mat[0][1] = x[2] - x[0]; */
  /* mat[0][2] = x[3] - x[0]; */
  /* mat[1][0] = y[1] - y[0]; */
  /* mat[1][1] = y[2] - y[0]; */
  /* mat[1][2] = y[3] - y[0]; */
  /* mat[2][0] = z[1] - z[0]; */
  /* mat[2][1] = z[2] - z[0]; */
  /* mat[2][2] = z[3] - z[0]; */
  mat[0][0] = x[1] - x[0];
  mat[1][0] = x[2] - x[0];
  mat[2][0] = x[3] - x[0];
  mat[0][1] = y[1] - y[0];
  mat[1][1] = y[2] - y[0];
  mat[2][1] = y[3] - y[0];
  mat[0][2] = z[1] - z[0];
  mat[1][2] = z[2] - z[0];
  mat[2][2] = z[3] - z[0];  

}

// k_{ij} = \int_{tetra}  \nabla \phi_i \cdot \nabla \phi_j  dv -------------------------------------------------------------------------------------

/* static HXTStatus stiffnessMatrixOneTetra (const HXTMesh *mesh, uint32_t tetK, uint32_t i0, uint32_t i1, uint32_t i2, uint32_t i3, double S[16], double* dualVolume) { */
static HXTStatus stiffnessMatrixOneTetra (const HXTMesh *mesh, uint32_t i0, uint32_t i1, uint32_t i2, uint32_t i3, double S[16], double* dualVolume) {
  double mat[3][3];
  double det, imat[3][3];

  const double x[4] = {mesh->vertices.coord[4*i0+0],
    mesh->vertices.coord[4*i1+0],
    mesh->vertices.coord[4*i2+0],
    mesh->vertices.coord[4*i3+0]};
  const double y[4] = {mesh->vertices.coord[4*i0+1],
    mesh->vertices.coord[4*i1+1],
    mesh->vertices.coord[4*i2+1],
    mesh->vertices.coord[4*i3+1]};
  const double z[4] = {mesh->vertices.coord[4*i0+2],
    mesh->vertices.coord[4*i1+2],
    mesh->vertices.coord[4*i2+2],
    mesh->vertices.coord[4*i3+2]};

  jacobianTet (x,y,z,mat);

  HXT_CHECK(inv3x3 (mat, imat, &det));
  det=fabs(det);
  dualVolume[i0] += 1./12 * det;
  dualVolume[i1] += 1./12 * det;
  dualVolume[i2] += 1./12 * det;
  dualVolume[i3] += 1./12 * det;


  static const  double gradSF [4][3] = {
    {-1, -1, -1},
    { 1,  0, 0},
    { 0,  1, 0},
    { 0,  0, 1}};


  double GradSF [4][3];

  for (int i=0;i<4;i++){
    for (int j=0;j<3;j++){
      GradSF [i][j] = 0.0;
      for (int k=0;k<3;k++){
        GradSF [i][j] += gradSF[i][k] * imat[k][j];
      }
    }
  }

  const double ONE_SIXTH = 1./6;

  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      S[i+4*j] = det * ONE_SIXTH * (
          GradSF [i][0]*GradSF [j][0]+
          GradSF [i][1]*GradSF [j][1]+
          GradSF [i][2]*GradSF [j][2] );
    }
  }
  return HXT_STATUS_OK;

  /* uint32_t *tet = &mesh->tetrahedra.node[tetK*4]; */
  /* double x[4][4]; */
  /* for (int i = 0; i < 4; i++) */
  /*   memcpy(x[i], mesh->vertices.coord + 4*tet[i], sizeof(x[i])); */
  /* for (int i = 0; i < 4; i++) */
  /*   for (int j = 0; j < 4; j++) */
  /*     x[i][j] = mesh->vertices.coord[4*tet[i]+j]; */

  /* // */
  /* double dxdxi[3][3]; */
  /* for (int i = 0; i < 3; ++i) */
  /*   for (int j = 0; j < 3; ++j) */
  /*     dxdxi[i][j] = x[i+1][j] - x[0][j]; */
  /* double dxidx[3][3]; */
  /* double detj; */
  /* HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj)); */
  /* detj=fabs(detj); */
  /* dualVolume[i0] += 1./12 * detj; */
  /* dualVolume[i1] += 1./12 * detj; */
  /* dualVolume[i2] += 1./12 * detj; */
  /* dualVolume[i3] += 1./12 * detj; */
  /* const double dphi[][3] = { */
  /*   {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]}, */
  /*   {dxidx[0][0],dxidx[0][1],dxidx[0][2]}, */
  /*   {dxidx[1][0],dxidx[1][1],dxidx[1][2]}, */
  /*   {dxidx[2][0],dxidx[2][1],dxidx[2][2]} */
  /* }; */
  /* double volume = detj/6; */
  /* /\* // Local epsilon v2 *\/ */
  /* /\* double epsilonLoc = pow(volume,2./3.)*2*2; *\/ */
  /* /\* // *\/ */
  /* for (int i = 0; i < 4; ++i){ */
  /*   for (int j = 0; j < 4; ++j) { */
  /*     double m = volume*(dphi[i][0]*dphi[j][0]+dphi[i][1]*dphi[j][1]+dphi[i][2]*dphi[j][2]); */
  /*     S[4*i+j]=m; */
  /*   } */
  /* } */
  /* return HXT_STATUS_OK; */
}

// ------------------------------ stiffness assembly -------------------------------------------------------------------------------------------------

HXTStatus stiffnessMatrixMesh(const HXTMesh *mesh, void *matrix, void (*addToMatrix) (void *, uint64_t, uint64_t, double), double* dualVolume) {
  double S[16];
  for (uint64_t tetra = 0 ; tetra < mesh->tetrahedra.num; tetra++){
    const uint32_t *nodes = &(mesh->tetrahedra.node[4*tetra+0]);
    HXT_CHECK ( stiffnessMatrixOneTetra ( mesh, nodes[0], nodes[1], nodes[2], nodes[3], S, dualVolume) );
    for ( uint64_t i=0;i<4;i++){
      for ( uint64_t j=0;j<4;j++){
        addToMatrix(matrix, nodes[i], nodes[j], S[i+4*j]);
      }
    }    
  }
  return HXT_STATUS_OK;
}

void triangleNormal(const double v1[3], const double v2[3], const double v3[3], double n[3]) {
  double d1[3] = { v2[0] - v1[0], v2[1] - v1[1], v2[2] - v1[2] };
  double d2[3] = { v3[0] - v1[0], v3[1] - v1[1], v3[2] - v1[2] };
  hxtCrossProductV3(d1,d2,n);
}


void computeEulerAnglesOfNormal(const double *n, double* alpha, double* beta) {
  /* Euler angles assuming e_z is transformed to the normal n */
  const double eps = 1.e-12;
  if (fabs(n[2] - 1.) < eps) {
    *alpha = 0;
    *beta = 0;
  } else if (fabs(n[2] + 1.) < eps) {
    *alpha = 0;
    *beta =  M_PI;
  } else {
    *alpha = atan2(-n[0],n[1]);
    if (fabs(cos(*alpha)) < eps)
      /* *beta = acos(n[2]); */
      *beta = atan2(n[0]/sin(*alpha),n[2]);
    else
      *beta = atan2(-n[1]/cos(*alpha),n[2]);
  }
}

HXTStatus contributionsFromNodes(const HXTMesh* mesh, const uint32_t nodes[3], const double* dualVolume, double avgEdge) {
  /* Get the normal */
  double n[3];
  triangleNormal(&(mesh->vertices.coord[4*nodes[0]]), &(mesh->vertices.coord[4*nodes[1]]), 
      &(mesh->vertices.coord[4*nodes[2]]), n);
  HXT_ASSERT(n[0]*n[0]+n[1]*n[1]+n[2]*n[2] > 0.);
  hxtNormalizeV3(n);
  double norm=0.0;
  hxtNorm2V3(n, &norm);
  HXT_ASSERT_MSG(norm <= 1. + 1.e-12, "norm: %.3f", norm);

  /* Euler angles assuming e_z is transformed to the normal n */
  double a,b;
  hxtOrientation3DeulerAnglesOfNormal(n, &a, &b);

  /* Computing the constraints between coefficients on the boundary */
  double C[9][2];
  double D[9];
  computeCombinationOnBorder(a, b, C, D);

  double MAT[9][9];
  computeBoundaryConstraintMatrix(C, MAT);
  double R[9];
  computeBoundaryRhsContribution(MAT, D, R);

  /* Contributions to the linear system */
  for (uint8_t lv = 0; lv < 3; ++lv) {
    const uint32_t v = nodes[lv];
    const double factor = 1*dualVolume[v] / (avgEdge*avgEdge);
    for(uint8_t i=0;i<9;i++){
      nlAddIRightHandSide(9*v+i, factor * R[i]);
    }
    for(uint8_t i=0;i<9;i++){
      for(uint8_t j=0;j<9;j++){
        nlAddIJCoefficient(9*v+i, 9*v+j, factor * MAT[i][j]);
      }
    }
  }

  if (0) {
    printf("\n-------\nBoundary condition for tri (%i %i %i)\n", nodes[0], nodes[1], nodes[2]);
    printf(" euler angles: %.3f %.3f\n", a, b);
    printf(" penalty factor: ");
    for (uint8_t lv = 0; lv < 3; ++lv) {
      const uint32_t v = nodes[lv];
      const double factor = dualVolume[v] / (avgEdge*avgEdge);
      printf("%.3f ", factor);
    }
    printf("\n");

    printf(" rhs <- ");
    for (uint8_t c = 0; c < 9; ++c) {
      printf("%.3e ", R[c]);
    }
    printf("\n");
    printf(" mat <- \n");
    for(uint8_t i=0;i<9;i++){
      printf("   (");
      for(uint8_t j=0;j<9;j++){
        printf("%.3e ", MAT[i][j]);
      }
      printf(")\n");
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus addBoundaryConditionsEnergyFromTriangles(const HXTMesh* mesh, const double* dualVolume) {
  HXT_ASSERT(mesh->triangles.num > 0);

  double avgEdge = 0.;
  uint64_t n = 0;
  for (uint64_t c = 0 ; c < mesh->triangles.num; c++){
    const uint32_t* nodes = &mesh->triangles.node[3*c];
    for (uint8_t i = 0; i < 3; ++i) {
      double edge = 0.;
      for (uint8_t d = 0; d < 3; ++d) {
        edge += pow(mesh->vertices.coord[4*nodes[i]+d] - mesh->vertices.coord[4*nodes[(i+1)%3]+d],2);
      }
      avgEdge += sqrt(edge);
      n += 1;
    }
  }
  avgEdge /= n;


  for (uint64_t c = 0 ; c < mesh->triangles.num; c++){
    const uint32_t* nodes = &mesh->triangles.node[3*c];
    HXT_CHECK(contributionsFromNodes(mesh, nodes, dualVolume, avgEdge));
  }
  return HXT_STATUS_OK;
}

void addToMatrix(void* matrix, uint64_t i, uint64_t j, double value) {
  for ( uint64_t u=0;u<9;u++){
    nlAddIJCoefficient(9*i+u, 9*j+u, value);
  }
}

void magicTransfo (double *dir){

  return;
  double temp[9];
  for (int i=0;i<9;i++){
    temp[i] = dir[i];    
  }
  dir [0] = temp[0];
  dir [1] = temp[1];
  dir [2] = temp[2];

  dir [3] = -(temp[3]+temp[4]);
  dir [4] = temp[3];
  
  dir [5] = temp[5];
  dir [6] = -(temp[5]+temp[6]);

  dir [7] = temp[7];
  dir [8] = temp[8];
  
}

HXTStatus projectTensorOnCrossManifold(double tIn[9], double tOut[9]) {
  double tInOld[9], tOutOld[9];
  newBasisToOldBasis(tIn, tInOld);
  double Rot[9];
  HXT_CHECK(hxtOrientation3DframeToDirections(Rot, NULL, tInOld));
  double Rv[36];
  hxtOrientation3DmatRot3x3ToMandelRot4th(Rv, Rot);
  double vectRef[9]={1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0};
  double crossTensRef[36];
  hxtOrientation3DframeToMandel4th(crossTensRef, vectRef);
  double crossTens[36];
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      crossTens[i*6+j]=0.0;
    }
  }
  for(int i=0; i<6; i++)
    for(int j=0; j<6; j++)
      for(int k=0; k<6; k++)
        for(int l=0; l<6; l++)
          crossTens[i*6+j] += Rv[i*6+k]*crossTensRef[k*6+l]*Rv[j*6+l];
  
  hxtOrientation3Dmandel4thToFrame(tOutOld,crossTens);
  oldBasisToNewBasis(tOutOld, tOut);
  return HXT_STATUS_OK;
}


HXTStatus testImplicitSolver(HXTMesh* mesh, double* field) {
  printf("------------------------------\n");
  printf("running testImplicitSolver... \n");
  printf("input mesh has %i vertices, %li tetrahedra and %li triangles\n",
      mesh->vertices.num, mesh->tetrahedra.num, mesh->triangles.num);


  /* Dual volume associated to vertices required to compute penalty factor */
  double* dualVolume;
  hxtMalloc(&dualVolume, mesh->vertices.num * sizeof(double));
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) dualVolume[i] = 0.;

  /* Solver stuff */
  omp_set_nested(0);
  const uint64_t nbv = mesh->vertices.num * 9;
  nlNewContext();
  nlSolverParameteri(NL_SOLVER, NL_CG);
  nlSolverParameteri(NL_NB_VARIABLES, nbv);
  nlSolverParameteri(NL_MAX_ITERATIONS, 1000);
  // nlSolverParameteri(NL_PRECONDITIONER, NL_PRECOND_JACOBI);
  // nlSolverParameteri(NL_SYMMETRIC, NL_TRUE);
  // nlSolverParameteri(NL_PRECONDITIONER, NL_PRECOND_SSOR);
  nlSolverParameterd(NL_THRESHOLD, 1.e-6);
  nlEnable(NL_VERBOSE);

  nlBegin(NL_SYSTEM);
  nlBegin(NL_MATRIX);
  HXT_CHECK(stiffnessMatrixMesh(mesh, NULL, addToMatrix, dualVolume));
  if (mesh->triangles.num > 0){
    HXT_CHECK(addBoundaryConditionsEnergyFromTriangles(mesh, dualVolume));
  } else {
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "no tet adjacencies and no triangles, cannot apply boundary conditions");
  }
  nlEnd(NL_MATRIX);
  nlEnd(NL_SYSTEM);
  hxtFree(&dualVolume);

  /* Solve and get solution */
  printf("solving linear system with OpenNL (%li unknowns) ...\n", nbv);
  double ti = omp_get_wtime();
  nlSolve();
  for (uint64_t i = 0; i < 9*mesh->vertices.num; ++i) {
    field[i] = nlGetVariable(i);
  }

  printf("projecting on cross-field manifold ...\n");
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    double fieldNew[9];
    for(int k=0;k<9;k++)
      fieldNew[k]=field[9*i+k];
    newBasisToOldBasis(fieldNew, field+9*i);
  }
  double tf = omp_get_wtime();
  printf("... done in %.3fs\n", tf - ti);

  /* Debug printing, remove this after ! */
  if (0) {
    int isOnBorder[mesh->vertices.num]; /* bad bad, only for small pb */
    for (uint64_t i = 0; i < mesh->vertices.num; ++i) isOnBorder[i] = 0;
    for (uint64_t i = 0; i < mesh->triangles.num; ++i) {
      isOnBorder[mesh->triangles.node[3*i+0]] = 1;
      isOnBorder[mesh->triangles.node[3*i+1]] = 1;
      isOnBorder[mesh->triangles.node[3*i+2]] = 1;
    }
    printf("\n-------------\nSolution:\n");
    for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
      double* tensor = &field[9*i];
      double dev;
      hxtOrientation3DcomputeQuality(tensor, &dev);
      printf("u[%li] = ", i);
      for (uint8_t c = 0; c < 9; ++c) {
        printf("%.3e ", field[9*i+c]);
      }
      printf(" <%.3f> ", dev);
      if (isOnBorder[i]) printf(" BDR");
      printf("\n");
    }
  }
  return HXT_STATUS_OK;
}

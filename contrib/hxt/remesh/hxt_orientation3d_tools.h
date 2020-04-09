#ifndef HXT_ORIENTATION3D_TOOLS_H
#define HXT_ORIENTATION3D_TOOLS_H

#include "hxt_api.h"
#include "hxt_mesh.h"

// frame tools
void hxtOr3DgetBase(double basis[6][6][10]); //mod
HXTStatus hxtOr3DcrossProdBase(const double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6]); //mod
HXTStatus hxtOr3DgradBoundary(const double *B, const double D[9], const double frame[9], double grad[9]);
void hxtOr3DgradPenalty(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9]);
void hxtOr3DgradPenaltyComp(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9], int k, int l);
void hxtOr3DeulerAnglesOfNormal(const double *normal, double* psi, double* theta); //mod
HXTStatus hxtOr3DcombinationOnBorder(double a, double b, double c[9][2], double d[9]);
HXTStatus hxtOr3DboundaryConstraintMatrix(const double C[9][2], double B[9][9]);
//Conversion from new basis to old basis
void newBasisToOldBasis(const double *solNewBasis, double *solOldBasis); //mod
//Conversion from old basis to new basis
void oldBasisToNewBasis(const double *solOldBasis, double *solNewBasis); //mod
// Frobenius norm of 3x3 symmetric matrix
void hxtOr3DfrobNormMatSym3x3(const double *mat, double *frobNorm); //mod
// representation Mandel 6x1 -> matrice 3x3 sym
void hxtOr3Dmandel2ndToMat3x3(const double *mandel2nd, double *mat33); //mod
// representation matrice 3x3 sym -> Mandel 6x1
void hxtOr3Dmat3x3ToMandel2nd(const double *mat33, double *mandel2nd); //mod
// vec 3 -> representation Mandel 6x1 of the vector dyadic product
void hxtOr3Dvec3ToMandel2ndDyadic(const double *vect, double *mandel2nd); //mod
// old frame representation 9x1 -> representation Mandel 6x6
void hxtOr3DframeToMandel4th(const double *frame, double *mandel4th); //mod
// representation Mandel 6x6 -> frame 9x1
void hxtOr3Dmandel4thToFrame(const double *mandel4th, double *frame); //mod
// angles euler ZXZ -> basis (u0,u1,u2,v0,v1,v2,w0,w1,w2)
void hxtOr3DeulerToBasis(const double *euler, double *basis); //mod
// angle euler ZXZ -> frame 9x1
void hxtOr3DeulerToFrame(const double *euler, double *frame); //mod
// 3 orthogonal directions (x0,y0,z0,x1,y1,z1,x2,y2,z2) -> frame 9x1
void hxtOr3DdirectionsToFrame(const double *directions, double *frame); //mod
// normale + un angle de rotation autour de celle-ci -> frame 9x1
void hxtOr3DnormalEulerToFrame(const double *normal, const double gamma, double *frame); //mod
// projection frame 9x1 -> 3 stable direction indicator (s0,s1,s2) and 3 orthogonal directions (x0,y0,z0,x1,y1,z1,x2,y2,z2)
HXTStatus hxtOr3DframeToDirections(const double *frame, double *stableDir, double *dirFinal); //mod
HXTStatus hxtOr3DprojectFrameOnCrossManifold(const double *frame, double *frameProj);
// frame 9x1 -> double quality (||A^2 - A||)
HXTStatus hxtOr3DcomputeQuality(const double *frame, double *quality); //mod
// frame 9x1 -> angles euler 3x1
HXTStatus hxtOr3DframeToEuler(const double *frame, double* flagNotUnique, double *euler); //mod
HXTStatus hxtOr3DdirectionsToEuler(const double *dir, double *flagNotUnique, double *euler); //directionsToEuler2
HXTStatus hxtOr3DgetCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode); //mod
HXTStatus hxtOr3DgetScaledCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode); //mod
HXTStatus hxtOr3DdBdEuler(const double euler[3], double dBdEuler[9][3]);

//FE for tet tools
HXTStatus hxtOr3DFEbasisFctDataTetOrder1(const HXTMesh *mesh, uint64_t iel, double *wGDet, double L[4], double dLdX[4][3]);
HXTStatus hxtOr3DFELaplaceElemMatTetOrder1(const HXTMesh *mesh, uint64_t iel, double *laplaceMat);

// euler and local basis tools
HXTStatus hxtOr3DtransposeBasis(double *basis); //tranposeDir2
HXTStatus hxtOr3DmakeOrientationDirect(double *basis); //makeOrientationDirect2
HXTStatus hxtOr3DliftBasis(const double *dirRef, double *dir); //reorderDir2
HXTStatus hxtOr3DdirectionsToEulerTet(const double dirElem[9*4], const double dLdX[4][3], double eulerElem[3*4], int *flagLoc); //computeEulerElem2DBG
HXTStatus hxtOr3DdirectionsToEulerTri(const double dirElem[9*3], const double dLdX[3][3], double eulerElem[3*3], int *flagLoc);
HXTStatus hxtOr3DframesToEulerDataTet(const double *framesElem, const double dLdX[4][3],double eulerElem[3*4],double gradPsi[3],double gradTheta[3],double gradPhi[3]); //getEulerDataElem

// basic math tools
HXTStatus hxtOr3DdotProd(const double *u, const double *v, const int sizeVect, double *scalarProd); //dotProd2
HXTStatus hxtOr3DdyadicProd3(const double u[3], const double v[3], double dyadicProd[3][3]);
HXTStatus hxtOr3DsumMat3x3(const double A[3][3], const double B[3][3], double sum[3][3]);
HXTStatus hxtOr3DgetRankMat9x3(const double mat[9][3], int baseVect[3], int *rank);
HXTStatus hxtOr3DpseudoInv9x3(const double mat[9][3], double pseudoInv[3][9]);

//DBG fcts
HXTStatus hxtOr3DcheckIfBasisDirect(const double basis[9]);
HXTStatus hxtOr3DprintBase(const double basis[9]);
HXTStatus hxtOr3DcheckIfPinvOk(const double A[9][3], const double pInvA[3][9]);
#endif

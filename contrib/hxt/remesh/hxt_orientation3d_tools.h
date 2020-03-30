#ifndef HXT_ORIENTATION3D_TOOLS_H
#define HXT_ORIENTATION3D_TOOLS_H

#include "hxt_api.h"

void hxtOrientation3DgetBase(double basis[6][6][10]);
HXTStatus hxtOrientation3DcrossProdBase(double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6]);
HXTStatus hxtOrientation3DgradBoundary(const double *B, const double D[9], const double frame[9], double grad[9]);
void hxtOrientation3DgradPenalty(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9]);
void hxtOrientation3DgradPenaltyComp(double frame[9], double base[6][6][10], double crossProdBase[10][10][6][6], double crossProdBaseSym[10][10][6][6], double grad[9], int k, int l);
void hxtOrientation3DeulerAnglesOfNormal(const double *n, double* alpha, double* beta);
HXTStatus hxtOrientation3DcombinationOnBorder(double a, double b, double c[9][2], double d[9]);
HXTStatus hxtOrientation3DboundaryConstraintMatrix(const double C[9][2], double B[9][9]);
//Conversion from new basis to old basis
void newBasisToOldBasis(double *solNewBasis, double *solOldBasis);
//Conversion from old basis to new basis
void oldBasisToNewBasis(double *solOldBasis, double *solNewBasis);
// Frobenius norm of 3x3 symmetric matrix
void hxtOrientation3DfrobNormMatSym3x3(double *frobNorm, double *mat);
// representation Mandel 6x1 -> matrice 3x3 sym
void hxtOrientation3Dmandel2ndToMat3x3(double *tens2, double *vectDir);
// representation matrice 3x3 sym -> Mandel 6x1
void hxtOrientation3Dmat3x3ToMandel2nd(double *mandel2nd, double *mat);
// vec 3 -> representation Mandel 6x1 of the vector dyadic product
void hxtOrientation3Dvec3ToMandel2nd(double *mandel2nd, double *vect);
// frame 9x1 -> representation Mandel 6x6
void hxtOrientation3DframeToMandel4th(double *D, const double *vectA);
// representation Mandel 6x6 -> frame 9x1
void hxtOrientation3Dmandel4thToFrame(double *vectA, double *D);
// angles euler ZXZ -> matrice rotation 3x3
void hxtOrientation3DeulerToMatRot3x3(double *rotMat, double *euler);
// matrice rotation 3x3 -> representation Mandel 6x6 de l'opérateur de rotation d'ordre 4
void hxtOrientation3DmatRot3x3ToMandelRot4th(double *Rv, double *R);
// angle euler ZXZ -> frame 9x1
void hxtOrientation3DeulerToFrame(double *cross, double *euler);
// 3 directions orthogonale normalisées -> frame 9x1
void hxtOrientation3DdirectionsToFrame(double *frame, double *dirCross);
// normale + un angle de rotation autour de celle-ci -> frame 9x1
void hxtOrientation3DnormalEulerToFrame(double *frame, double *normal, double gamma);
// projection frame 9x1 -> 3 directions orthogonales
HXTStatus hxtOrientation3DframeToDirections(double *directions, double *stableDir, const double *frame);
// frame 9x1 -> double quality (||A^2 - A||)
HXTStatus hxtOrientation3DcomputeQuality(const double *frame, double *quality);
// frame 9x1 -> angles euler 3x1
HXTStatus hxtOrientation3DframeToEuler(double *euler, double* flagNotUnique, const double *frame);
HXTStatus hxtOrientation3DgetCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode);
HXTStatus hxtOrientation3DgetScaledCrossInTetFromDir(const double *directions, double* coordParam, double *dirAtParamNode);

#endif

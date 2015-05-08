// TODO: Header

#ifndef _CADDISTANCES_H_
#define _CADDISTANCES_H_

#include "fullMatrix.h"
#include <vector>
#include <map>


class GradientBasis;
class MLine;
class MElement;
class GEdge;
class GFace;
class SVector3;
class GModel;


enum { CADDIST_GEN, CADDIST_DECASTELJAU };
enum { CADDIST_TAYLOR, CADDIST_FRECHET, CADDIST_HAUSFAST, CADDIST_HAUSBRUTE };


double discreteFrechetDistanceEdge(MLine *l, GEdge *ed, double tol,
                                   int meshDiscr = CADDIST_GEN, int geomDiscr = CADDIST_GEN);
double discreteHausdorffDistanceBruteEdge(MLine *l, GEdge *ed, double tol,
                                          int meshDiscr = CADDIST_GEN, int geomDiscr = CADDIST_GEN);
double discreteHausdorffDistanceFastEdge(MLine *l, GEdge *ed, double tol,
                                         int meshDiscr = CADDIST_GEN, int geomDiscr = CADDIST_GEN);
double taylorDistanceSq1D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &tanCAD);
double taylorDistanceSq2D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &normCAD);
double taylorDistanceEdge(MLine *l, GEdge *ge);
double taylorDistanceFace(MElement *el, GFace *gf);

void distanceFromElementsToGeometry(GModel *gm, int dim, std::map<MElement*, double> &distances);
double distanceToGeometry(GModel *gm, int distType = CADDIST_TAYLOR, double tol = 1e-3,
                          int meshDiscr = CADDIST_DECASTELJAU,
                          int geomDiscr = CADDIST_DECASTELJAU);
double distanceToGeometry(GModel *gm, int dim, int tag,
                          int distType = CADDIST_TAYLOR, double tol = 1e-3,
                          int meshDiscr = CADDIST_DECASTELJAU,
                          int geomDiscr = CADDIST_DECASTELJAU);


#endif /* _CADDISTANCES_H_ */

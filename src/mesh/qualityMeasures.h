// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef QUALITY_MEASURES_H
#define QUALITY_MEASURES_H

#include <vector>

class SPoint3;
class SVector3;
class BDS_Point;
class BDS_Face;
class MVertex;
class MTriangle;
class MQuadrangle;
class MTetrahedron;
class MPrism;
class MHexahedron;
class MElement;
template <class scalar> class fullVector;
template <class scalar> class fullMatrix;

class qmTriangle {
public:
  static double gamma(MTriangle *f);
  static double gamma(BDS_Face *f);
  static double gamma(const BDS_Point *p1, const BDS_Point *p2,
                      const BDS_Point *p3);
  static double gamma(const MVertex *v1, const MVertex *v2, const MVertex *v3);
  static double gamma(const double *d1, const double *d2, const double *d3);
  static double gamma(const double &x1, const double &y1, const double &z1,
                      const double &x2, const double &y2, const double &z2,
                      const double &x3, const double &y3, const double &z3);
  static double eta(MTriangle *el);
  static double angles(MTriangle *e);
  static double minNCJ(const MTriangle *e);
  static void NCJRange(const MTriangle *e, double &valMin, double &valMax);
  static inline int numNCJVal() { return 3; }
  static void NCJ(const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                  const SVector3 &normal, std::vector<double> &NCJ);
  static void NCJAndGradients(const SPoint3 &p0, const SPoint3 &p1,
                              const SPoint3 &p2, const SVector3 &normal,
                              std::vector<double> &NCJ,
                              std::vector<double> &dNCJ);
};

class qmQuadrangle {
public:
  static double gamma(MQuadrangle *el) { return eta(el); }
  static double eta(MQuadrangle *el);
  static double angles(MQuadrangle *e);
  static double minNCJ(const MQuadrangle *e);
  static void NCJRange(const MQuadrangle *e, double &valMin, double &valMax);
  static inline int numNCJVal() { return 4; }
  static void NCJ(const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                  const SPoint3 &p3, const SVector3 &normal,
                  std::vector<double> &ncj);
  static void NCJAndGradients(const SPoint3 &p0, const SPoint3 &p1,
                              const SPoint3 &p2, const SPoint3 &p3,
                              const SVector3 &normal, std::vector<double> &NCJ,
                              std::vector<double> &dNCJ);
};

class qmTetrahedron {
public:
  enum Measures { QMTET_GAMMA, QMTET_ETA, QMTET_ONE, QMTET_COND };
  static double qm(MTetrahedron *t, const Measures &cr,
                   double *volume = nullptr);
  static double qm(const BDS_Point *p1, const BDS_Point *p2,
                   const BDS_Point *p3);
  static double qm(const MVertex *v1, const MVertex *v2, const MVertex *v3,
                   const MVertex *v4, const Measures &cr,
                   double *volume = nullptr);
  static double qm(const double &x1, const double &y1, const double &z1,
                   const double &x2, const double &y2, const double &z2,
                   const double &x3, const double &y3, const double &z3,
                   const double &x4, const double &y4, const double &z4,
                   const Measures &cr, double *volume = nullptr);
  static double eta(const double &x1, const double &y1, const double &z1,
                    const double &x2, const double &y2, const double &z2,
                    const double &x3, const double &y3, const double &z3,
                    const double &x4, const double &y4, const double &z4,
                    double *volume = nullptr);
  static double gamma(const double &x1, const double &y1, const double &z1,
                      const double &x2, const double &y2, const double &z2,
                      const double &x3, const double &y3, const double &z3,
                      const double &x4, const double &y4, const double &z4,
                      double *volume = nullptr);
  static double cond(const double &x1, const double &y1, const double &z1,
                     const double &x2, const double &y2, const double &z2,
                     const double &x3, const double &y3, const double &z3,
                     const double &x4, const double &y4, const double &z4,
                     double *volume = nullptr);
  static double minNCJ(const MTetrahedron *e);
  //  static void NCJRange(const MTetrahedron *e, double &valMin, double
  //  &valMax);
  static inline int numNCJVal() { return 4; }
  //  static void NCJ(const double &x0, const double &y0, const double &z0,
  //                  const double &x1, const double &y1, const double &z1,
  //                  const double &x2, const double &y2, const double &z2,
  //                  const double &x3, const double &y3, const double &z3,
  //                  fullVector<double> &ncj);
  //  static void NCJAndGradients(const double &x0, const double &y0, const
  //  double &z0,
  //                              const double &x1, const double &y1, const
  //                              double &z1, const double &x2, const double
  //                              &y2, const double &z2, const double &x3, const
  //                              double &y3, const double &z3,
  //                              fullMatrix<double> &ncj);
};

class qmPrism {
public:
  static double minNCJ(const MPrism *el);
  static inline int numNCJVal() { return 6; }
  //  static void NCJ(const double &x0, const double &y0, const double &z0,
  //                  const double &x1, const double &y1, const double &z1,
  //                  const double &x2, const double &y2, const double &z2,
  //                  const double &x3, const double &y3, const double &z3,
  //                  const double &x4, const double &y4, const double &z4,
  //                  fullVector<double> &ncj);
};

class qmHexahedron {
public:
  static double angles(MHexahedron *el);
  static inline int numNCJVal() { return 8; }
  //  static void NCJ(const double &x0, const double &y0, const double &z0,
  //                  const double &x1, const double &y1, const double &z1,
  //                  const double &x2, const double &y2, const double &z2,
  //                  const double &x3, const double &y3, const double &z3,
  //                  const double &x4, const double &y4, const double &z4,
  //                  fullVector<double> &ncj);
};

#endif

// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _QUALITY_MEASURES_H_
#define _QUALITY_MEASURES_H_

#include "fullMatrix.h"

class BDS_Point;
class BDS_Face;
class MVertex;
class MTriangle;
class MQuadrangle;
class MTetrahedron;
class MPrism;
class MHexahedron;
class MElement;


class qmTriangle
{
public:
  static double gamma(MTriangle *f);
  static double gamma(BDS_Face *f);
  static double gamma(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3);
  static double gamma(const MVertex *v1, const MVertex *v2, const MVertex *v3);
  static double gamma(const double *d1, const double *d2, const double *d3);
  static double gamma(const double &x1, const double &y1, const double &z1,
                      const double &x2, const double &y2, const double &z2,
                      const double &x3, const double &y3, const double &z3);
  static double eta(MTriangle *el);
  static double angles(MTriangle *e);
  static double minNCJ(const MTriangle *e);
  static void NCJ(const double &x0, const double &y0, const double &z0,
                  const double &x1, const double &y1, const double &z1,
                  const double &x2, const double &y2, const double &z2,
                  fullVector<double> &ncj);
  static void NCJAndGradients(const double &x0, const double &y0, const double &z0,
                              const double &x1, const double &y1, const double &z1,
                              const double &x2, const double &y2, const double &z2,
                              fullMatrix<double> &ncj);
};


class qmQuadrangle
{
public:
  static double gamma(MQuadrangle *el) { return eta(el); }
  static double eta(MQuadrangle *el);
  static double angles(MQuadrangle *e);
  static double minNCJ(const MQuadrangle *e);
  static void NCJ(const double &x0, const double &y0, const double &z0,
                  const double &x1, const double &y1, const double &z1,
                  const double &x2, const double &y2, const double &z2,
                  const double &x3, const double &y3, const double &z3,
                  fullVector<double> &ncj);
  static void NCJAndGradients(const double &x0, const double &y0, const double &z0,
                              const double &x1, const double &y1, const double &z1,
                              const double &x2, const double &y2, const double &z2,
                              const double &x3, const double &y3, const double &z3,
                              fullMatrix<double> &ncj);
};


class qmTetrahedron
{
public:
  enum Measures {QMTET_GAMMA, QMTET_ETA, QMTET_ONE, QMTET_COND};
  static double qm(MTetrahedron *t, const Measures &cr, double *volume = 0);
  static double qm(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3);
  static double qm(const MVertex *v1, const MVertex *v2, const MVertex *v3,
      const MVertex *v4, const Measures &cr, double *volume = 0);
  static double qm(const double &x1, const double &y1, const double &z1,
                   const double &x2, const double &y2, const double &z2,
                   const double &x3, const double &y3, const double &z3,
                   const double &x4, const double &y4, const double &z4,
                   const Measures &cr, double *volume = 0);
  static double eta(const double &x1, const double &y1, const double &z1,
                    const double &x2, const double &y2, const double &z2,
                    const double &x3, const double &y3, const double &z3,
                    const double &x4, const double &y4, const double &z4,
                    double *volume = 0);
  static double gamma(const double &x1, const double &y1, const double &z1,
                      const double &x2, const double &y2, const double &z2,
                      const double &x3, const double &y3, const double &z3,
                      const double &x4, const double &y4, const double &z4,
                      double *volume = 0);
  static double cond(const double &x1, const double &y1, const double &z1,
                     const double &x2, const double &y2, const double &z2,
                     const double &x3, const double &y3, const double &z3,
                     const double &x4, const double &y4, const double &z4,
                     double *volume = 0);
  static double minNCJ(const MTetrahedron *e);
  static void NCJ(const double &x0, const double &y0, const double &z0,
                  const double &x1, const double &y1, const double &z1,
                  const double &x2, const double &y2, const double &z2,
                  const double &x3, const double &y3, const double &z3,
                  fullVector<double> &ncj);
  static void NCJAndGradients(const double &x0, const double &y0, const double &z0,
                              const double &x1, const double &y1, const double &z1,
                              const double &x2, const double &y2, const double &z2,
                              const double &x3, const double &y3, const double &z3,
                              fullMatrix<double> &ncj);
};


class qmPrism
{
public:
  static double minNCJ(const MPrism *el);
//  static void NCJ(const double &x0, const double &y0, const double &z0,
//                  const double &x1, const double &y1, const double &z1,
//                  const double &x2, const double &y2, const double &z2,
//                  const double &x3, const double &y3, const double &z3,
//                  const double &x4, const double &y4, const double &z4,
//                  fullVector<double> &ncj);
};


class qmHexahedron
{
public:
  static double angles(MHexahedron *el);
//  static void NCJ(const double &x0, const double &y0, const double &z0,
//                  const double &x1, const double &y1, const double &z1,
//                  const double &x2, const double &y2, const double &z2,
//                  const double &x3, const double &y3, const double &z3,
//                  const double &x4, const double &y4, const double &z4,
//                  fullVector<double> &ncj);
};

#endif

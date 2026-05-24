// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

/*
 * Implementation of Mean Value Coordinates based on:
 *
 * Kai Hormann and Michael S. Floater,
 * "Mean Value Coordinates for Arbitrary Planar Polygons",
 * ACM Transactions on Graphics, 2006.
 *
 * Chiara Fuda and Kai Hormann,
 * "A New Stable Method to Compute Mean Value Coordinates",
 * Computer Aided Geometric Design, 2024.
 */

#include <stdlib.h>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "meanValueBasis.h"
#include "GaussIntegration.h"
#include "MPolygon.h"
#include "MVertex.h"
#include "SVector3.h"

static double angle(MVertex *a, MVertex *b, MVertex *c, SVector3 &n)
{
  SVector3 v0(b->x() - a->x(), b->y() - a->y(), b->z() - a->z());
  SVector3 v1(c->x() - a->x(), c->y() - a->y(), c->z() - a->z());
  SVector3 cp = crossprod(v0, v1);
  return atan2(dot(cp, n), dot(v0, v1));
}

void meanValueBasis::evaluateCoordinates(MElement *e, double x, double y,
                                         double z, std::vector<double> c) const
{
  if(e->getType() == TYPE_POLYG) {
    MPolygon *polygon = static_cast<MPolygon *>(e);
    c.resize(polygon->getNumVertices());
    SVector3 n = polygon->getNormal();

    std::vector<double> r(c.size()), b(c.size()), g(c.size()), s(c.size());
    for(int i = 0; i < c.size(); ++i) {
      MVertex v(x, y, z), *vi = polygon->getVertex(i),
                          *vip1 = polygon->getVertex((i + 1) % c.size());
      r[i] = v.distance(vi);

      b[i] = angle(vi, vip1, &v, n);
      g[i] = angle(vip1, vi, &v, n);
      s[i] = b[i] + g[i];
    }

    double W = 0.;
    for(size_t i = 0; i < c.size(); ++i) {
      size_t im1 = (i - 1 + c.size()) % c.size(), ip1 = (i + 1) % c.size();
      MVertex v(x, y, z), *vim1 = polygon->getVertex(im1),
                          *vip1 = polygon->getVertex(ip1);
      double a = angle(&v, vim1, vip1, n);
      double signs = (s[im1] > 0.) + (s[i] > 0.) - (s[im1] < 0.) - (s[i] < 0.);
      double ss = M_PI * signs - s[im1] - s[i];
      if(a * ss < 0.) a *= -1;
      c[i] = r[im1] * sin(a / 2);
      for(size_t j = 0; j < c.size(); ++j) {
        if(j == im1 || j == i) continue;
        c[i] *= r[j] * sin(abs(s[j]) / 2);
      }
      W += c[i];
    }
    double inv_W = 1. / W;
    for(size_t i = 0; i < c.size(); ++i) c[i] *= inv_W;
  }
  else {
    Msg::Error("No implementation of Mean Value Basis for element type %d",
               e->getType());
  }
}

void meanValueBasis::f(double x, double y, double z, double *sf) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::f(const fullMatrix<double> &coord,
                       fullMatrix<double> &sf) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::f(double x, double y, double z, int i, double *sf) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::df(const fullMatrix<double> &coord,
                        fullMatrix<double> &dfm) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::df(double x, double y, double z, double grads[][3]) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::df(double x, double y, double z, int i,
                        double grad[3]) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::ddf(double x, double y, double z,
                         double hess[][3][3]) const
{
  Msg::Error("No implementation");
}

void meanValueBasis::dddf(double x, double y, double z,
                          double third[][3][3][3]) const
{
  Msg::Error("No implementation");
}

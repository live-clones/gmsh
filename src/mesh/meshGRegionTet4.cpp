// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The tetrahedron wrapper the object-based 3D kernels work on: its
// allocator, its in-sphere test, and the routines that build the
// adjacencies of a set of such tetrahedra.

#include <set>
#include <map>
#include <algorithm>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "meshGRegionTet4.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MEdge.h"
#include "Numeric.h"
#include "Context.h"

MTet4Factory::MTet4Factory() : extend(Extend2dMeshIn3dVolumes()) {}

MTetrahedron *MTet4Factory::createTet(MVertex *v0, MVertex *v1, MVertex *v2,
                                      MVertex *v3)
{
  if(!freeTet.empty()) {
    MTetrahedron *t = freeTet.back();
    freeTet.pop_back();
    t->setVertex(0, v0);
    t->setVertex(1, v1);
    t->setVertex(2, v2);
    t->setVertex(3, v3);
    t->forceNum(GModel::current()->incrementAndGetMaxElementNumber());
    return t;
  }
  return new MTetrahedron(v0, v1, v2, v3);
}

void
createAllEmbeddedEdges(GRegion *gr,
                       std::set<MEdge, MEdgeLessThan> &allEmbeddedEdges)
{
  std::vector<GEdge *> const &e = gr->embeddedEdges();
  for(auto it = e.begin(); it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      allEmbeddedEdges.insert(
        MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)));
    }
  }
}

void
createAllEmbeddedFaces(GRegion *gr,
                       std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  std::vector<GFace *> const &f = gr->embeddedFaces();
  for(auto it = f.begin(); it != f.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      allEmbeddedFaces.insert((*it)->triangles[i]->getFace(0));
    }
  }
}

int MTet4::inCircumSphere(const double *p) const
{
  // filtered test on the circumsphere cached by setup(): decide with a
  // simple distance comparison when it lies outside the roundoff bound, and
  // fall back to the exact predicates otherwise
  const double dx = p[0] - cc[0], dy = p[1] - cc[1], dz = p[2] - cc[2];
  const double d2 = dx * dx + dy * dy + dz * dz;
  const double diff = d2 - r2;
  const double s = d2 + r2;
  const double bound = sphTol * std::sqrt(s) + 1.e-12 * s;
  if(std::abs(diff) > bound) return (diff < 0) ? 1 : 0;

  double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(),
                  base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(),
                  base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(),
                  base->getVertex(2)->z()};
  double pd[3] = {base->getVertex(3)->x(), base->getVertex(3)->y(),
                  base->getVertex(3)->z()};
  double orient = orientSgn ? (double)orientSgn :
                              robustPredicates::orient3d(pa, pb, pc, pd);
  double result = robustPredicates::insphere(pa, pb, pc, pd, (double *)p) *
                  orient;
  return (result > 0) ? 1 : 0;
}


void connectTets(std::list<MTet4 *> &l,
                 const std::set<MFace, MFaceLessThan> *embeddedFaces)
{
  connectTets(l.begin(), l.end(), embeddedFaces);
}

void connectTets(std::vector<MTet4 *> &l,
                 const std::set<MFace, MFaceLessThan> *embeddedFaces)
{
  connectTets(l.begin(), l.end(), embeddedFaces);
}

// Ensure the star-shapeness of the delaunay cavity
// We use the visibility criterion : the vertex should be visible
// by all the facets of the cavity

double tetcircumcenterBounded(double a[3], double b[3], double c[3],
                              double d[3], double circumcenter[3], double *err)
{
  // this function must perform exactly the same floating-point operations as
  // tetcircumcenter() so that the computed center is bit-identical; it only
  // accumulates in addition a conservative bound on the roundoff error of
  // the result
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  const double xxx = robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  // bound the roundoff on (xcirca, ycirca, zcirca): the dominant error terms
  // come from the cancellations in the cross products and in the numerator
  // sums, all bounded by the same expressions on absolute values; the
  // constant includes a generous safety margin on the ~10 ulp worst case
  const double axcross = fabs(yca * zda) + fabs(yda * zca) + fabs(yda * zba) +
                         fabs(yba * zda) + fabs(yba * zca) + fabs(yca * zba);
  const double aycross = fabs(zca * xda) + fabs(zda * xca) + fabs(zda * xba) +
                         fabs(zba * xda) + fabs(zba * xca) + fabs(zca * xba);
  const double azcross = fabs(xca * yda) + fabs(xda * yca) + fabs(xda * yba) +
                         fabs(xba * yda) + fabs(xba * yca) + fabs(xca * yba);
  const double maxlength = std::max(balength, std::max(calength, dalength));
  *err = 4096. * 2.220446049250313e-16 * maxlength *
         (axcross + aycross + azcross) * fabs(denominator);

  return xxx;
}


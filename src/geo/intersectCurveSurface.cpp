// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "intersectCurveSurface.h"
#include "Numeric.h"
#include "fullMatrix.h"

static bool _kaboom(fullVector<double> &uvt, fullVector<double> &res,
                    void *_data);

struct intersectCurveSurfaceData {
  const curveFunctor &c;
  const surfaceFunctor &s;
  const double epsilon;
  intersectCurveSurfaceData(const curveFunctor &_c, const surfaceFunctor &_s,
                            const double &eps)
    : c(_c), s(_s), epsilon(eps)
  {
  }
  bool apply(double newPoint[3])
  {
    try {
      fullVector<double> uvt(3);
      uvt(0) = newPoint[0];
      uvt(1) = newPoint[1];
      uvt(2) = newPoint[2];
      fullVector<double> res(3);
      _kaboom(uvt, res, this);
      // printf("start with %12.5E\n",res.norm());
      if(res.norm() < epsilon) return true;

      if(newton_fd(_kaboom, uvt, this)) {
        // printf("--- CONVERGED -----------\n");
        newPoint[0] = uvt(0);
        newPoint[1] = uvt(1);
        newPoint[2] = uvt(2);
        // printf("newton done\n");
        return true;
      }
    } catch(...) {
      // printf("intersect curve surface failed !\n");
    }
    // printf("newton failed\n");
    return false;
  }
};

static bool _kaboom(fullVector<double> &uvt, fullVector<double> &res,
                    void *_data)
{
  intersectCurveSurfaceData *data = (intersectCurveSurfaceData *)_data;
  SPoint3 s = data->s(uvt(0), uvt(1));
  SPoint3 c = data->c(uvt(2));
  res(0) = s.x() - c.x();
  res(1) = s.y() - c.y();
  res(2) = s.z() - c.z();
  return true;
}

int intersectCurveSurface(curveFunctor &c, surfaceFunctor &s, double uvt[3],
                          double epsilon)
{
  intersectCurveSurfaceData data(c, s, epsilon);
  return data.apply(uvt);
}

// a solution (u, v, t) of the restart is acceptable if its point is on the
// same side of the circle as the surface point p0 of the guess uv (not the
// other intersection), and if its parameters are not further from uv than uv
// is from those of the middle (not the same point at another period of a
// periodic parametrization, or anywhere around a pole)
static bool _nearGuess(GFace *gf, const double uv[2], const GPoint &p0,
                       const SVector3 &middle, const double uvMiddle[2],
                       const double uvt[3])
{
  GPoint p = gf->point(uvt[0], uvt[1]);
  if(!p.succeeded()) return false;
  SVector3 w(p0.x() - middle.x(), p0.y() - middle.y(), p0.z() - middle.z());
  SVector3 m(p.x() - middle.x(), p.y() - middle.y(), p.z() - middle.z());
  if(dot(w, m) <= 0.) return false;
  return std::hypot(uvt[0] - uv[0], uvt[1] - uv[1]) <=
         std::hypot(uv[0] - uvMiddle[0], uv[1] - uvMiddle[1]);
}

bool intersectCircleSurface(GFace *gf, const SVector3 &a, const SVector3 &b,
                            const SVector3 &middle, const double uvMiddle[2],
                            double d, double uv[2],
                            const std::function<bool(double, double)> &inside)
{
  curveFunctorCircle cc(a, b, middle, d);
  surfaceFunctorGFace ss(gf);
  double uvt[3] = {uv[0], uv[1], 0.};
  if(!intersectCurveSurface(cc, ss, uvt, d * 1.e-8)) return false;
  if(!inside || inside(uvt[0], uvt[1])) {
    uv[0] = uvt[0];
    uv[1] = uvt[1];
    return true;
  }

  // the point is outside the domain: when the plane of the circle is far from
  // the tangent plane (e.g. that of a large initial triangle under a curved
  // surface), t = 0 can be far from both intersections, and Newton then ends
  // anywhere (#2089); restart at the point of the circle closest to the
  // surface point of the guess
  GPoint p0 = gf->point(uv[0], uv[1]);
  if(!p0.succeeded()) return false;
  SVector3 w(p0.x() - middle.x(), p0.y() - middle.y(), p0.z() - middle.z());
  uvt[0] = uv[0];
  uvt[1] = uv[1];
  uvt[2] = std::atan2(dot(w, b), dot(w, a));
  if(intersectCurveSurface(cc, ss, uvt, d * 1.e-8) &&
     _nearGuess(gf, uv, p0, middle, uvMiddle, uvt) &&
     inside(uvt[0], uvt[1])) {
    uv[0] = uvt[0];
    uv[1] = uvt[1];
    return true;
  }
  return false;
}

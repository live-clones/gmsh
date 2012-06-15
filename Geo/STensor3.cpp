// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

// compute the largest inscribed ellipsoid...
#include "STensor3.h"

void SMetric3::print (const char *s) const
{
  printf(" metric %s : %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E \n", s,
         (*this)(0,0), (*this)(1,1), (*this)(2,2),
         (*this)(0,1), (*this)(0,2), (*this)(1,2));
}

void STensor3::print (const char *s) const
{
  printf(" tensor %s : \n"
         " %12.5E %12.5E %12.5E \n %12.5E %12.5E %12.5E \n %12.5E %12.5E %12.5E \n", s,
         (*this)(0,0), (*this)(0,1), (*this)(0,2),
         (*this)(1,0), (*this)(1,1), (*this)(1,2),
         (*this)(2,0), (*this)(2,1), (*this)(2,2));
}

SMetric3 intersection (const SMetric3 &m1, const SMetric3 &m2)
{
  SMetric3 im1 = m1.invert();
  fullMatrix<double> V(3,3);
  fullVector<double> S(3);
  im1 *= m2;
  im1.eig(V,S,true);
  SVector3 v0(V(0,0),V(1,0),V(2,0));
  SVector3 v1(V(0,1),V(1,1),V(2,1));
  SVector3 v2(V(0,2),V(1,2),V(2,2));
  double l0 = std::max(dot(v0,m1,v0),dot(v0,m2,v0));
  double l1 = std::max(dot(v1,m1,v1),dot(v1,m2,v1));
  double l2 = std::max(dot(v2,m1,v2),dot(v2,m2,v2));
  SMetric3 iv(l0,l1,l2,v0,v1,v2);
  return iv;
}

// preserve orientation of m1 !!!
SMetric3 intersection_conserveM1 (const SMetric3 &m1, const SMetric3 &m2)
{
  fullMatrix<double> V(3,3);
  fullVector<double> S(3);
  m1.eig(V,S,true);
  SVector3 v0(V(0,0),V(1,0),V(2,0));
  SVector3 v1(V(0,1),V(1,1),V(2,1));
  SVector3 v2(V(0,2),V(1,2),V(2,2));
  double l0 = std::max(dot(v0,m1,v0),dot(v0,m2,v0));
  double l1 = std::max(dot(v1,m1,v1),dot(v1,m2,v1));
  double l2 = std::max(dot(v2,m1,v2),dot(v2,m2,v2));
  SMetric3 iv(l0,l1,l2,v0,v1,v2);
  return iv;
}

// preserve orientation of the most anisotropic metric !!!
SMetric3 intersection_conserve_mostaniso (const SMetric3 &m1, const SMetric3 &m2)
{
  fullMatrix<double> V1(3,3);
  fullVector<double> S1(3);
  m1.eig(V1,S1,true);
  double lambda1_min = std::min(std::min(fabs(S1(0)),fabs(S1(1))),fabs(S1(2)));
  //double lambda1_max = std::max(std::max(fabs(S1(0)),fabs(S1(1))),fabs(S1(2)));
  fullMatrix<double> V2(3,3);
  fullVector<double> S2(3);
  m2.eig(V2,S2,true);
  double lambda2_min = std::min(std::min(fabs(S2(0)),fabs(S2(1))),fabs(S2(2)));
  //double lambda2_max = std::max(std::max(fabs(S2(0)),fabs(S2(1))),fabs(S2(2)));

  if (lambda1_min < lambda2_min)
    return intersection_conserveM1(m1, m2);
  else
    return intersection_conserveM1(m2, m1);
}

// (1-t) * m1 + t * m2
SMetric3 interpolation (const SMetric3 &m1,
                               const SMetric3 &m2,
                               const double t)
{
  SMetric3 im1 = m1.invert();
  SMetric3 im2 = m2.invert();
  im1 *= (1.-t);
  im2 *= t;
  im1 += im2;
  return im1.invert();
}

SMetric3 interpolation (const SMetric3 &m1,
                        const SMetric3 &m2,
                        const SMetric3 &m3,
                        const double u,
                        const double v)
{
  SMetric3 im1 = m1.invert();
  SMetric3 im2 = m2.invert();
  SMetric3 im3 = m3.invert();
  im1 *= (1.-u-v);
  im2 *= u;
  im3 *= v;
  im1 += im2;
  im1 += im3;
  return im1.invert();
}

SMetric3 interpolation (const SMetric3 &m1,
                        const SMetric3 &m2,
                        const SMetric3 &m3,
                        const SMetric3 &m4,
                        const double u,
                        const double v,
                        const double w)
{
  SMetric3 im1 = m1.invert();
  SMetric3 im2 = m2.invert();
  SMetric3 im3 = m3.invert();
  SMetric3 im4 = m4.invert();
  im1 *= (1.-u-v-w);
  im2 *= u;
  im3 *= v;
  im4 *= w;
  im1 += im2;
  im1 += im3;
  im1 += im4;
  return im1.invert();
}

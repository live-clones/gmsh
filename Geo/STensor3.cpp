// compute the largest inscribed ellipsoid...
#include "STensor3.h"

void SMetric3::print (const char *s) const
{
  printf(" metric %s : %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E \n",s,
         (*this)(0,0),(*this)(1,1),(*this)(2,2),
         (*this)(0,1),(*this)(0,2),(*this)(1,2));
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


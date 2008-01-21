#include "FProjectionFace.h"

#if defined(HAVE_FOURIER_MODEL)

FProjectionFace::FProjectionFace(GModel *m, int num) 
  : GFace(m,num), ps_(0) {}

FProjectionFace::FProjectionFace(GModel *m, int num, FM::ProjectionSurface* ps)
  : GFace(m,num), ps_(ps) {}

FProjectionFace::~FProjectionFace() {}

GPoint FProjectionFace::point(double par1, double par2) const
{
  SVector3 p;
  ps_->F(par1,par2,p[0],p[1],p[2]);
  return GPoint(p[0],p[1],p[2]);
}

SPoint2 FProjectionFace::parFromPoint(const SPoint3 &p) const
{  
  double u,v;
  ps_->Inverse(p[0],p[1],p[2],u,v);
  return SPoint2(u,v);
}

Pair<SVector3,SVector3> FProjectionFace::firstDer(const SPoint2 &param) const
{
  SVector3 du;
  SVector3 dv;
  ps_->Dfdu(param.x(),param.y(),du[0],du[1],du[2]);
  ps_->Dfdv(param.x(),param.y(),dv[0],dv[1],dv[2]);
  return Pair<SVector3,SVector3>(du,dv);
} 

SVector3 FProjectionFace::normal(const SPoint2 &param) const
{	
  double x, y, z;
  ps_->GetUnitNormal(param.x(),param.y(),x,y,z);
  return SVector3(x,y,z);
}

Range<double> FProjectionFace::parBounds(int i) const
{
  return Range<double>(0, 1);
}

#endif

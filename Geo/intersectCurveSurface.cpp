#include "intersectCurveSurface.h"
#include "Numeric.h"

static void _kaboom(fullVector<double> &uvt, 
			    fullVector<double> &res, void *_data);

struct intersectCurveSurfaceData 
{
  const curveFunctor &c;
  const surfaceFunctor &s;
  const double epsilon;
  intersectCurveSurfaceData (const curveFunctor & _c, 
			     const surfaceFunctor & _s, 
			     const double &eps) : c(_c),s(_s),epsilon(eps)
  { }

  bool apply (double newPoint[3]){
    fullVector<double> uvt(3);
    uvt(0) = newPoint[0];
    uvt(1) = newPoint[1];
    uvt(2) = newPoint[2];
    fullVector<double> res(3);
    _kaboom(uvt,res,this);
    if (res.norm() < epsilon)return true;

    if(newton_fd(_kaboom, uvt, this)){
      //      printf("--- CONVERGED -----------\n");
      newPoint[0] = uvt(0);
      newPoint[1] = uvt(1);
      return true;
    }    
    return false;
  }
};

void _kaboom(fullVector<double> &uvt, 
	     fullVector<double> &res, void *_data){
  intersectCurveSurfaceData *data = (intersectCurveSurfaceData*)_data;
  SPoint3 s = data->s(uvt(0),uvt(1));
  SPoint3 c = data->c(uvt(2));
  res(0) = s.x() - c.x();
  res(1) = s.y() - c.y();
  res(2) = s.z() - c.z();
}

int intersectCurveSurface (curveFunctor &c, surfaceFunctor & s, double uvt[3], double epsilon){
  intersectCurveSurfaceData data(c,s,epsilon);
  return data.apply(uvt);
}

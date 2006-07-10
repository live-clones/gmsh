#ifndef _GPOINT_H_
#define _GPOINT_H_
class GEntity;

struct GPoint 
{
  double X,Y,Z;
  const GEntity *e;  
  double par[2];
  GPoint (double _x, double _y, double _z, const GEntity *onwhat)
    : X(_x), Y(_y), Z(_z), e(onwhat){
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p)
    : X(_x), Y(_y), Z(_z), e(onwhat){
    par[0] = p;
  }
  GPoint (double _x, double _y, double _z, const GEntity *onwhat, double p[2])
    : X(_x), Y(_y), Z(_z), e(onwhat)
  {
    par[0] = p[0];
    par[1] = p[1];
  }
};
#endif

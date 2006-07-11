#ifndef _MVERTEX_H_
#define _MVERTEX_H_
class GEntity;
class MVertex 
{
  double x,y,z;
  GEntity *ge;
public :
  MVertex ( double _x, double _y, double _z , GEntity * _ge ) :
    x(_x),y(_y),z(_z),ge(_ge)
  {
  }
};

class MEdgeVertex : public MVertex
{
  double u;
public :
  MEdgeVertex ( double _x, double _y, double _z , GEntity * _ge , double _u) :
    MVertex (_x,_y,_z,_ge),u(_u)
  {
  }
};
#endif

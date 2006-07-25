#ifndef _MVERTEX_H_
#define _MVERTEX_H_

class GEntity;
class MVertex 
{
  double x_,y_,z_;
  GEntity *ge;
 public :
  MVertex ( double _x, double _y, double _z , GEntity * _ge ) :
    x_(_x),y_(_y),z_(_z),ge(_ge)
  {
  }
  inline double x() const {return x_;}
  inline double y() const {return y_;}
  inline double z() const {return z_;}
  inline double & x()  {return x_;}
  inline double & y()  {return y_;}
  inline double & z()  {return z_;}
  inline GEntity* onWhat() const {return ge;}
};

class MEdgeVertex : public MVertex {
 private:
  double u;
 public :
  MEdgeVertex ( double _x, double _y, double _z , GEntity * _ge , double _u) :
    MVertex (_x,_y,_z,_ge),u(_u)
  {
  }
};

class MFaceVertex : public MVertex
{
  double u,v;
public :
  MFaceVertex ( double _x, double _y, double _z , GEntity * _ge , double _u, double _v) :
    MVertex (_x,_y,_z,_ge),u(_u),v(_v)
  {
  }
};

#endif

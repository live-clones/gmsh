#ifndef _MVERTEX_H_
#define _MVERTEX_H_

#include <stdio.h>
#include <algorithm>

class GEntity;

class MVertex{
 private:
  static int _globalNum;
  int _num;
  double _x, _y, _z;
  GEntity *_ge;
 public :
  MVertex(double x, double y, double z, GEntity *ge=0, int num=0) 
    : _x(x), _y(y), _z(z), _ge(ge)
  {
    if(num){
      _num = num;
      _globalNum = std::max(_globalNum, _num);
    }
    else{
      _num = ++_globalNum;
    }
  }
  virtual ~MVertex(){}
  inline double x() const {return _x;}
  inline double y() const {return _y;}
  inline double z() const {return _z;}
  inline double & x() {return _x;}
  inline double & y() {return _y;}
  inline double & z() {return _z;}
  inline GEntity* onWhat() const {return _ge;}
  inline void setEntity(GEntity *ge) { _ge = ge; }
  inline int getNum() const {return _num;}
  inline void setNum(int num) { _num = num; }
  void writeMSH(FILE *fp, double scalingFactor=1.0)
  {
    fprintf(fp, "%d %.16g %.16g %.16g\n", getNum(), 
	    x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
  }
  void writeMSH(FILE *fp, double version, int num, int elementary, int physical)
  {
    fprintf(fp, "%d 15", num);
    if(version < 2.0)
      fprintf(fp, " %d %d 1", physical, elementary);
    else
      fprintf(fp, " 2 %d %d", physical, elementary);
    fprintf(fp, " %d\n", _num);
  }
};

class MEdgeVertex : public MVertex{
 private:
  double _u;
 public :
  MEdgeVertex(double x, double y, double z, GEntity *ge, double u) 
    : MVertex(x, y, z, ge), _u(u)
  {
  }
  ~MEdgeVertex(){}
};

class MFaceVertex : public MVertex{
 private:
  double _u, _v;
 public :
  MFaceVertex(double x, double y, double z, GEntity *ge, double u, double v) 
    : MVertex(x, y, z, ge), _u(u), _v(v)
  {
  }
  ~MFaceVertex(){}
};

#endif

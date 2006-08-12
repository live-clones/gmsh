#ifndef _MVERTEX_H_
#define _MVERTEX_H_

#include <stdio.h>
#include <algorithm>

class GEntity;

class MVertex{
 private:
  static int _globalNum;
  int _num;
  char _visible;
  double _x, _y, _z;
  GEntity *_ge;

 public :
  MVertex(double x, double y, double z, GEntity *ge=0, int num=0) 
    : _visible(true), _x(x), _y(y), _z(z), _ge(ge)
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

  // get/set the visibility flag
  virtual char getVisibility(){ return _visible; }
  virtual void setVisibility(char val){ _visible = val; }
  
  // get/set the coordinates
  inline double x() const {return _x;}
  inline double y() const {return _y;}
  inline double z() const {return _z;}
  inline double & x() {return _x;}
  inline double & y() {return _y;}
  inline double & z() {return _z;}

  // get/set the parent entity
  inline GEntity* onWhat() const {return _ge;}
  inline void setEntity(GEntity *ge) { _ge = ge; }

  // get/set the number
  inline int getNum() const {return _num;}
  inline void setNum(int num) { _num = num; }

  // IO routines
  void writeMSH(FILE *fp, double scalingFactor=1.0);
  void writeMSH(FILE *fp, double version, int num, int elementary, int physical);
  void writeVRML(FILE *fp, double scalingFactor=1.0);
  void writeUNV(FILE *fp, double scalingFactor=1.0);
  void writeMESH(FILE *fp, double scalingFactor=1.0);
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

class MVertexLessThanLexicographic{
 public:
  static double tolerance;
  bool operator()(const MVertex *v1, const MVertex *v2) const
  {
    if(v1->x() - v2->x() >  tolerance) return true;
    if(v1->x() - v2->x() < -tolerance) return false;
    if(v1->y() - v2->y() >  tolerance) return true;
    if(v1->y() - v2->y() < -tolerance) return false;
    if(v1->z() - v2->z() >  tolerance) return true;
    return false;
  }
};

#endif

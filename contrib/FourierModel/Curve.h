#ifndef _CURVE_H_
#define _CURVE_H_

namespace FM {

// The base class for the patches
class Curve {
 protected:
  int _tag;
 public:
  // Intersection Information
  Curve();
  Curve(int tag);
  virtual ~Curve() {}

  inline int GetTag() { return _tag; }

  virtual double GetPou(double t) = 0;
  virtual void F(double t, double &x, double &y, double &z) = 0;
  virtual bool Inverse(double x,double y,double z,double &t) = 0;
  virtual void Dfdt(double t, double &x, double &y, double &z) = 0;
  virtual void Dfdfdtdt(double t, double &x, double &y, double &z) = 0;
};

}

#endif

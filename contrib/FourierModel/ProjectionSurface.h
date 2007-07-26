#ifndef _PROJECTION_SURFACE_H_
#define _PROJECTION_SURFACE_H_

#include <string>

class ProjectionSurface {
 private:
  int tag_;
  std::string name_;
 protected:
  int numParameters_;
  double uPeriod_, vPeriod_;
  bool uPeriodic_, vPeriodic_;
  double O_[3], E0_[3], E1_[3], E2_[3], scale_[3];
 public:
  ProjectionSurface
    (double uPeriod = -1., double vPeriod = -1.);

  virtual ~ProjectionSurface() {}

  inline int GetTag() { return tag_; }
  inline void SetTag(int tag) { tag_ = tag; }

  inline std::string GetName() { return name_; }
  inline void SetName(std::string name) { name_ = name; }

  inline int GetNumParameters() { return numParameters_; }

  // Public access functions

  inline void GetOrigin
    (double &x, double &y, double &z)
    {
      x = O_[0]; y = O_[1]; z = O_[2];
    }
  inline void GetE0
    (double &x, double &y, double &z)
    {
      x = E0_[0]; y = E0_[1]; z = E0_[2];
    }
  inline void GetE1
    (double &x, double &y, double &z)
    {
      x = E1_[0]; y = E1_[1]; z = E1_[2];
    }
  inline void GetE2
    (double &x, double &y, double &z)
    {
      x = E2_[0]; y = E2_[1]; z = E2_[2];
    }
  inline void GetScale
    (double &x, double &y, double &z)
    {
      x = scale_[0]; y = scale_[1]; z = scale_[2];
    }

  // These are the virtual functions that must be provided 
  // by all derived projection surfaces

  virtual void F
    (double u, double v, double &x, double &y, double &z) = 0;
  virtual bool Inverse
    (double x,double y,double z,double &u,double &v) = 0;
  virtual void Dfdu
    (double u, double v, double &x, double &y, double &z) = 0;
  virtual void Dfdv
    (double u, double v, double &x, double &y, double &z) = 0;
  virtual void Dfdfdudu
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdudv
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdvdv
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdfdududu
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdfdududv
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdfdudvdv
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdfdvdvdv
    (double u,double v,double &x,double &y,double &z) = 0;
  virtual bool OrthoProjectionOnSurface
    (double x, double y, double z, double &u,double &v) = 0;
  virtual void SetParameter
    (int i, double x) = 0;
  virtual double GetParameter
    (int i) = 0;

  // These functions may also be provided by the derived 
  // projection surfaces (usually for better performance), 
  // but they don't have to

  virtual void GetNormal
    (double u, double v, double &x, double &y, double &z);
  virtual void GetUnitNormal
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndu
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndv
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndudu
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndudv
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndvdv
    (double u, double v, double &x, double &y, double &z);

  virtual void Rotate
    (double A0, double A1, double A2);
  virtual void Translate
    (double D0, double D1, double D2);
  virtual void Rescale
    (double S0, double S1, double S2);
};

#endif

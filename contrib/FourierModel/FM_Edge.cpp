#include "FM_Edge.h"
#include "Message.h"

void FM_Edge::F(double t, double &x, double &y, double &z)
{
  if (_curve) {
    double tStart, tEnd;
    _curve->Inverse(_SP->GetX(),_SP->GetY(),_SP->GetZ(),tStart);
    _curve->Inverse(_EP->GetX(),_EP->GetY(),_EP->GetZ(),tEnd);
   
    double tRescaled;
    if (std::abs(tEnd - tStart) < 1.e-12) {
      tRescaled = tStart + t * (1. + tEnd - tStart);
      tRescaled -= floor(tRescaled);
    }
    else
      tRescaled = tStart + t * (tEnd - tStart);
    _curve->F(tRescaled, x, y, z);
    //Msg::Info("%g %g %g",_SP->GetX(),_SP->GetY(),_SP->GetZ());
    //Msg::Info("%g %g %g",_EP->GetX(),_EP->GetY(),_EP->GetZ());
    //Msg::Info("t : %g %g %g %g",t,tRescaled, tStart, tEnd);
  }
  else {
    x = _SP->GetX() + t * (_EP->GetX() - _SP->GetX());
    y = _SP->GetY() + t * (_EP->GetY() - _SP->GetY());
    z = _SP->GetZ() + t * (_EP->GetZ() - _SP->GetZ());
  }
}

bool FM_Edge::Inverse(double x,double y,double z,double &t)
{
  if (_curve) {
    double tStart, tEnd;
    _curve->Inverse(_SP->GetX(),_SP->GetY(),_SP->GetZ(),tStart);
    _curve->Inverse(_EP->GetX(),_EP->GetY(),_EP->GetZ(),tEnd);
    
    double tCurve;
    _curve->Inverse(x, y, z, tCurve);

    if (std::abs(tEnd - tStart) < 1.e-12) {
      t = (tCurve - tStart) / (1. + tEnd - tStart);
      t -= floor(t);
    }
    else
      t = (tCurve - tStart) / (tEnd - tStart);
  }
  else {
    if (_EP->GetX() - _SP->GetX())
      t = (x - _SP->GetX()) / (_EP->GetX() - _SP->GetX());
    else if (_EP->GetY() - _SP->GetY())
      t = (y - _SP->GetY()) / (_EP->GetY() - _SP->GetY());
    else if (_EP->GetZ() - _SP->GetZ())
      t = (z - _SP->GetZ()) / (_EP->GetZ() - _SP->GetZ());
    else {
      Msg::Warning("Cannnot invert the curve");
      t = 0.;
    }
  }
}

void FM_Edge::Dfdt(double t, double &x, double &y, double &z)
{
  if (_curve) {
    double xMinus, yMinus, zMinus;
    double xPlus, yPlus, zPlus;
    
    double tStart, tEnd;
    _curve->Inverse(_SP->GetX(),_SP->GetY(),_SP->GetZ(),tStart);
    _curve->Inverse(_EP->GetX(),_EP->GetY(),_EP->GetZ(),tEnd);
    
    double h = 1.e-10;
    double tRescaled;
    if (std::abs(tEnd - tStart) < 1.e-12) {
      tRescaled = tStart + t * (1. + tEnd - tStart);
      tRescaled -= floor(tRescaled);
    }
    else
      tRescaled = tStart + t * (tEnd - tStart);
    if (tRescaled+0.5*h > tEnd) {
      _curve->F(tRescaled, xPlus, yPlus, zPlus);
      double tMinus = tRescaled - h;
      _curve->F(tMinus, xMinus, yMinus, zMinus);
    }
    else if (tRescaled-0.5*h < tStart) {
      _curve->F(tRescaled, xMinus, yMinus, zMinus);
      double tPlus = tRescaled + h;
      _curve->F(tPlus, xPlus, yPlus, zPlus);
    }
    else {
      double tPlus = tRescaled + 0.5 * h;
      double tMinus = tRescaled - 0.5 * h;
      _curve->F(tPlus, xPlus, yPlus, zPlus);
      _curve->F(tMinus, xMinus, yMinus, zMinus);
    }
    x = (xPlus - xMinus) / h;
    y = (yPlus - yMinus) / h;
    z = (zPlus - zMinus) / h;
  }
  else {
    x = _EP->GetX() - _SP->GetX();
    y = _EP->GetY() - _SP->GetY();
    z = _EP->GetZ() - _SP->GetZ();
  }
}

void FM_Edge::Dfdfdtdt(double t, double &x, double &y, double &z)
{
  if (_curve) {
    double xMinus, yMinus, zMinus;
    double xPlus, yPlus, zPlus;
    
    double tStart, tEnd;
    _curve->Inverse(_SP->GetX(),_SP->GetY(),_SP->GetZ(),tStart);
    _curve->Inverse(_EP->GetX(),_EP->GetY(),_EP->GetZ(),tEnd);
    
    double h = 1.e-10;
    double tRescaled;
    if (std::abs(tEnd - tStart) < 1.e-12) {
      tRescaled = tStart + t * (1. + tEnd - tStart);
      tRescaled -= floor(tRescaled);
    }
    else
      tRescaled = tStart + t * (tEnd - tStart);
    if (tRescaled+0.5*h > tEnd) {
      Dfdt(tRescaled, xPlus, yPlus, zPlus);
      double tMinus = tRescaled - h;
      Dfdt(tMinus, xMinus, yMinus, zMinus);
    }
    else if (tRescaled-0.5*h < tStart) {
      Dfdt(tRescaled, xMinus, yMinus, zMinus);
      double tPlus = tRescaled + h;
      Dfdt(tPlus, xPlus, yPlus, zPlus);
    }
    else {
      double tPlus = tRescaled + 0.5 * h;
      double tMinus = tRescaled - 0.5 * h;
      Dfdt(tPlus, xPlus, yPlus, zPlus);
      Dfdt(tMinus, xMinus, yMinus, zMinus);
    }
    x = (xPlus - xMinus) / h;
    y = (yPlus - yMinus) / h;
    z = (zPlus - zMinus) / h;
  }
  else {
    x = y = z = 0.;
  }
}

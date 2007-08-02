#include "Message.h"
#include "ExactPatch.h"

ExactPatch::ExactPatch(PatchInfo *PI, ProjectionSurface* ps) : Patch()
{
  _PI = PI;
  SetProjectionSurface(ps);

  if (!strcmp(_PI->type,"plane")) {
    _PI->periodic[0] = 0;
    _PI->periodic[1] = 0;
  }
  else if (!strcmp(_PI->type,"disc")) {
    _PI->periodic[0] = 0;
    _PI->periodic[1] = 1;
  }
  else {
    Msg::Info("Unknown exact patch type");
    _PI->periodic[0] = 0;
    _PI->periodic[1] = 0;
  }
}

void ExactPatch::F(double u, double v, double &x, double &y, double &z)
{
  _ps->F(u,v,x,y,z);
}

bool  ExactPatch::Inverse(double x,double y,double z,double &u,double &v)
{
  return _ps->Inverse(x,y,z,u,v);
}

void ExactPatch::Dfdu(double u, double v, double &x, double &y, double &z)
{
  _ps->Dfdu(u,v,x,y,z);
}

void ExactPatch::Dfdv(double u, double v, double &x, double &y, double &z)
{
  _ps->Dfdv(u,v,x,y,z);
}

void ExactPatch::Dfdfdudu(double u,double v,double &x,double &y,double &z)
{
  _ps->Dfdfdudu(u,v,x,y,z);
}

void ExactPatch::Dfdfdudv(double u,double v,double &x,double &y,double &z)
{
  _ps->Dfdfdudv(u,v,x,y,z);
}

void ExactPatch::Dfdfdvdv(double u,double v,double &x,double &y,double &z)
{
  _ps->Dfdfdvdv(u,v,x,y,z);
}

double ExactPatch::GetPou(double u, double v)
{
  return 1.;
}

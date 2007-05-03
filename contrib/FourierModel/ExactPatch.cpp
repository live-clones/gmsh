#include "Message.h"
#include "ExactPatch.h"

ExactPatch::ExactPatch(PatchInfo *PI) : Patch(PI)
{
  _NcrossT[0] = _PI->normal[1] * _PI->tangent[2] - 
    _PI->normal[2] * _PI->tangent[1];
  _NcrossT[1] = _PI->normal[2] * _PI->tangent[0] - 
    _PI->normal[0] * _PI->tangent[2];
  _NcrossT[2] = _PI->normal[0] * _PI->tangent[1] - 
    _PI->normal[1] * _PI->tangent[0];

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
  if (!strcmp(_PI->type,"plane")) {
    x = _PI->origin[0] + _PI->tangent[0] * _PI->scale[0] * u + 
      _NcrossT[0] * _PI->scale[1] * v;
    y = _PI->origin[1] + _PI->tangent[1] * _PI->scale[0] * u + 
      _NcrossT[1] * _PI->scale[1] * v;
    z = _PI->origin[2] + _PI->tangent[2] * _PI->scale[0] * u + 
      _NcrossT[2] * _PI->scale[1] * v;
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = _PI->origin[0] + _PI->scale[1] * u * 
      (_PI->tangent[0] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[0] * sin(_PI->scale[0] * (v-0.5)));
    y = _PI->origin[1] + _PI->scale[1] * u * 
      (_PI->tangent[1] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[1] * sin(_PI->scale[0] * (v-0.5)));
    z = _PI->origin[2] + _PI->scale[1] * u * 
      (_PI->tangent[2] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[2] * sin(_PI->scale[0] * (v-0.5)));
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

bool  ExactPatch::Inverse(double x,double y,double z,double &u,double &v)
{
  if (!strcmp(_PI->type,"plane")) {
    u = ((x - _PI->origin[0]) * _PI->tangent[0] + 
	 (y - _PI->origin[1]) * _PI->tangent[1] +
	 (z - _PI->origin[2]) * _PI->tangent[2]) / _PI->scale[0];
    v = ((x - _PI->origin[0]) * _NcrossT[0] +
	 (y - _PI->origin[1]) * _NcrossT[1] +
	 (z - _PI->origin[2]) * _NcrossT[2]) / _PI->scale[1];
  }
  else if (!strcmp(_PI->type,"disc")) {
    double a = (x - _PI->origin[0]) * _PI->tangent[0] + 
      (y - _PI->origin[1]) * _PI->tangent[1] + 
      (z - _PI->origin[2]) * _PI->tangent[2];
    double b = (x - _PI->origin[0]) * _NcrossT[0] + 
      (y - _PI->origin[1]) * _NcrossT[1] + (z - _PI->origin[2]) * _NcrossT[2];

    u = sqrt(a * a + b * b);
    u /= _PI->scale[1];

    v = atan2(b,a);
    v /= _PI->scale[0];
    v += 0.5;
  }
  else {
    Msg::Info("Unknown exat patch type");
    x = y = z = 0.;
  }
  return true;
}

void ExactPatch::Dfdu(double u, double v, double &x, double &y, double &z)
{
  if (!strcmp(_PI->type,"plane")) {
    x = _PI->tangent[0] * _PI->scale[0];
    y = _PI->tangent[1] * _PI->scale[0];
    z = _PI->tangent[2] * _PI->scale[0];
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = _PI->scale[1] * (_PI->tangent[0] * cos(_PI->scale[0] * (v-0.5)) + 
			 _NcrossT[0] * sin(_PI->scale[0] * (v-0.5)));
    y = _PI->scale[1] * (_PI->tangent[1] * cos(_PI->scale[0] * (v-0.5)) + 
			 _NcrossT[1] * sin(_PI->scale[0] * (v-0.5)));
    z = _PI->scale[1] * (_PI->tangent[2] * cos(_PI->scale[0] * (v-0.5)) + 
			 _NcrossT[2] * sin(_PI->scale[0] * (v-0.5)));
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

void ExactPatch::Dfdv(double u, double v, double &x, double &y, double &z)
{
  if (!strcmp(_PI->type,"plane")) {
    x = _NcrossT[0] * _PI->scale[1];
    y = _NcrossT[1] * _PI->scale[1];
    z = _NcrossT[2] * _PI->scale[1];
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = _PI->scale[1] * u * _PI->scale[0] *
      (- _PI->tangent[0] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[0] * cos(_PI->scale[0] * (v-0.5)));
    y = _PI->scale[1] * u * _PI->scale[0] *
      (- _PI->tangent[1] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[1] * cos(_PI->scale[0] * (v-0.5)));
    z = _PI->scale[1] * u * _PI->scale[0] *
      (- _PI->tangent[2] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[2] * cos(_PI->scale[0] * (v-0.5)));
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

void ExactPatch::Dfdfdudu(double u,double v,double &x,double &y,double &z)
{
  if (!strcmp(_PI->type,"plane")) {
     x = y = z = 0.;
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = y = z = 0.;
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

void ExactPatch::Dfdfdudv(double u,double v,double &x,double &y,double &z)
{
  if (!strcmp(_PI->type,"plane")) {
     x = y = z = 0.;
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = _PI->scale[1] * _PI->scale[0] *
      (- _PI->tangent[0] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[0] * cos(_PI->scale[0] * (v-0.5)));
    y = _PI->scale[1] * _PI->scale[0] *
      (- _PI->tangent[1] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[1] * cos(_PI->scale[0] * (v-0.5)));
    z = _PI->scale[1] * _PI->scale[0] *
      (- _PI->tangent[2] * sin(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[2] * cos(_PI->scale[0] * (v-0.5)));
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

void ExactPatch::Dfdfdvdv(double u,double v,double &x,double &y,double &z)
{
  if (!strcmp(_PI->type,"plane")) {
    x = y = z = 0.;
  }
  else if (!strcmp(_PI->type,"disc")) {
    x = - _PI->scale[1] * u * _PI->scale[0] * _PI->scale[0] *
      (_PI->tangent[0] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[0] * sin(_PI->scale[0] * (v-0.5)));
    y = - _PI->scale[1] * u * _PI->scale[0] * _PI->scale[0] *
      (- _PI->tangent[1] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[1] * sin(_PI->scale[0] * (v-0.5)));
    z = - _PI->scale[1] * u * _PI->scale[0] * _PI->scale[0] *
      (- _PI->tangent[2] * cos(_PI->scale[0] * (v-0.5)) + 
       _NcrossT[2] * sin(_PI->scale[0] * (v-0.5)));
  }
  else {
    Msg::Info("Unknown exact patch type");
    x = y = z = 0.;
  }
}

double ExactPatch::GetPou(double u, double v)
{
  return 1.;
}

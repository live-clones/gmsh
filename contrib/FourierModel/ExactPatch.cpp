#include "Message.h"
#include "ExactPatch.h"

ExactPatch::ExactPatch(ProjectionSurface* ps) : Patch()
{
  SetProjectionSurface(ps);
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

void ExactPatch::Export(FILE *fp)
{
  double x,y,z;

  fprintf(fp, "%s\n", _ps->GetName().c_str());
  fprintf(fp, "%d\n", _ps->GetTag());
  _ps->GetOrigin(x,y,z);
  fprintf(fp, "%g %g %g\n", x, y, z);
  _ps->GetE0(x,y,z);
  fprintf(fp, "%g %g %g\n", x, y, z);
  _ps->GetE1(x,y,z);
  fprintf(fp, "%g %g %g\n", x, y, z);
  _ps->GetScale(x,y,z);
  fprintf(fp, "%g %g %g\n", x, y, z);
  fprintf(fp, "%d\n", _ps->GetNumParameters());
  for (int i = 0; i < _ps->GetNumParameters(); i++)
    fprintf(fp, "%g\n",_ps->GetParameter(i));

  fprintf(fp, "%s\n", "ExactPatch");
  fprintf(fp, "%d\n", _tag);
  fprintf(fp, "%d\n", _derivative);
  fprintf(fp, "%g %g\n", _uMin, _uMax);
  fprintf(fp, "%g %g\n", _vMin, _vMax);
  fprintf(fp, "%d %d %d %d\n", _hardEdge[0], _hardEdge[1], _hardEdge[2],
	  _hardEdge[3]);
}

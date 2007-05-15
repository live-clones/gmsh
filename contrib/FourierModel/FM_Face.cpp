#include "FM_Face.h"
#include "Message.h"

void FM_Face::F(double u, double v, double &x, double &y, double &z) {
  if (_edge.size() == 4) {
    _patch->F(u,v,x,y,z);
  }
  else if (_edge.size() == 1) {
    // sanity check
    double cx, cy, cz;
    _patch->F(0.,0.,cx,cy,cz);
    double px, py, pz;
    _edge[0]->F(v,px,py,pz);
    double R = sqrt((px-cx)*(px-cx)+(py-cy)*(py-cy)+(pz-cz)*(pz-cz));
    _patch->F(u*R,v,x,y,z);
  }
  else if (_edge.size() == 4) {
    bool isPhysical = (_edge[0]->IsPhysical()) && (_edge[1]->IsPhysical()) &&
      (_edge[2]->IsPhysical()) && (_edge[3]->IsPhysical());
    if (isPhysical)
      _patch->F(u,v,x,y,z);
    else {
      double xD, yD, zD, uD, vD;
      double xU, yU, zU, uU, vU;
      _edge[0]->F(v,xD,yD,zD);
      _patch->Inverse(xD,yD,zD,uD,vD);
      _edge[2]->F(1.-v,xU,yU,zU);
      _patch->Inverse(xU,yU,zU,uU,vU);
      
      double U = uD + u * (uU - uD);
      double V = vD;
      
      _patch->F(U,V,x,y,z);
    }
  }
  else {
    Msg::Info("Such a face not implemented yet");
    x = y = z = 0.;
  }
}

bool FM_Face::Inverse(double x,double y,double z,double &u, double &v)
{
  if (_edge.size() == 1) {
    double n[3], t[3], s[3], c[3], r[3];
    _patch->F(0.,0.,c[0],c[1],c[2]);
    for (int i=0;i<3;i++) {
      t[i] = _patch->_PI->tangent[i];
      n[i] = _patch->_PI->normal[i];
    }

    s[0] = n[1] * t[2] - n[2] * t[1];
    s[1] = n[2] * t[0] - n[0] * t[2];
    s[2] = n[0] * t[1] - n[1] * t[0];

    r[0] = x - c[0];
    r[1] = y - c[1];
    r[2] = z - c[2];

    double norm = sqrt(r[0]*r[0]+r[1]*r[1]+r[2]*r[2]);
    for (int i=0;i<3;i++)
      r[i] /= norm;
    double xx, yy;
    for (int i=0;i<3;i++) {
      xx += r[i] * t[i];
      yy += r[i] * s[i];
    }
    v = atan2(yy, xx)/(2. * M_PI) +0.5;
    double px, py, pz;
    _edge[0]->F(v,px,py,pz);
    double R = sqrt((px-c[0])*(px-c[0])+(py-c[1])*(py-c[1])+
		    (pz-c[2])*(pz-c[2]));
    u = norm / R;
  }
  else if (_edge.size() == 4) {
    bool isPhysical = (_edge[0]->IsPhysical()) && (_edge[1]->IsPhysical()) &&
      (_edge[2]->IsPhysical()) && (_edge[3]->IsPhysical());
    if (isPhysical)
      _patch->Inverse(x,y,z,u,v);
    else {
      double U, V;
      _patch->Inverse(x,y,z,U,V);
      double u0,v0,u1,v1;
      double xD, yD, zD, uD, vD;
      double xU, yU, zU, uU, vU;
      _edge[0]->F(0,xD,yD,zD);
      _patch->Inverse(xD,yD,zD,u0,v0);
      _edge[0]->F(1,xD,yD,zD);
      _patch->Inverse(xD,yD,zD,u1,v1);
      v = (V-v0)/(v1-v0);
      _edge[0]->F(v,xD,yD,zD);
      _patch->Inverse(xD,yD,zD,uD,vD);
      _edge[2]->F(1.-v,xU,yU,zU);
      _patch->Inverse(xU,yU,zU,uU,vU);
      
      u = (U - uD) / (uU - uD);
    }
  }
  else {
    Msg::Info("Such a face not implemented yet");
    u = v = 0.;
  }
  
}

void FM_Face::Dfdu(double u, double v, double &x, double &y, double &z)
{
  Msg::Info("Not implemented yet.");
  x = y = z = 0.;
}

void FM_Face::Dfdv(double u, double v, double &x, double &y, double &z)
{
  Msg::Info("Not implemented yet.");
  x = y = z = 0.;
}

void FM_Face::Dfdfdudu(double u, double v, double &x, double &y, double &z)
{
  Msg::Info("Not implemented yet.");
  x = y = z = 0.;
}

void FM_Face::Dfdfdudv(double u, double v, double &x, double &y, double &z)
{
  Msg::Info("Not implemented yet.");
  x = y = z = 0.;
}

void FM_Face::Dfdfdvdv(double u, double v, double &x, double &y, double &z)
{
  Msg::Info("Not implemented yet.");
  x = y = z = 0.;
}

void FM_Face::GetNormal(double u, double v, double &x, double &y, double &z)
{
  double dfdu[3], dfdv[3];
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  x = dfdu[1] * dfdv[2] - dfdu[2] * dfdv[1];
  y = dfdu[2] * dfdv[0] - dfdu[0] * dfdv[2];
  z = dfdu[0] * dfdv[1] - dfdu[1] * dfdv[0];
}

void FM_Face::
GetUnitNormal(double u, double v, double &x, double &y, double &z)
{
  GetNormal(u, v, x, y, z);
  double norm = sqrt(x * x + y * y + z * z);
  if(norm > 0.) {
    x /= norm;
    y /= norm;
    z /= norm;
  }
}

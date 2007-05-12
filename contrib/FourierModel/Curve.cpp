#include <math.h>
#include "Message.h"
#include "Curve.h"

Curve::Curve(IntersectionInfo* II, std::vector<Patch*> patches) 
  : _II(II)
{
  _h = 1.e-6;
  _tol = 1.e-12;

  if (_II->intersectingPatches[0].patchTag < 0)
    _patch0 = 0;
  else {
    for (int i=0;i<patches.size();i++) {
      if (patches[i]->GetTag() == _II->intersectingPatches[0].patchTag) {
	_patch0 = patches[i];
	break;
      }
    }
  }
  if (_II->intersectingPatches[1].patchTag)
    _patch1 = 0;
  else {
    for (int i=0;i<patches.size();i++) {
      if (patches[i]->GetTag() == _II->intersectingPatches[1].patchTag) {
	_patch1 = patches[i];
	break;
      }
    }
  }
  if ((_patch0) && (_patch1)) {
    double u,v,x,y,z;
    x = _II->SP[0]; y = _II->SP[1]; z = _II->SP[2];
    _patch0->Inverse(x,y,z,u,v);
    _SP0[0] = u;
    _SP0[1] = v;
    _patch1->Inverse(x,y,z,u,v);
    _SP1[0] = u;
    _SP1[1] = v;
    //printf("SPx = %g; SPy = %g; SPz = %g;\n",x,y,z);
    
    x = _II->EP[0]; y = _II->EP[1]; z = _II->EP[2];
    _patch0->Inverse(x,y,z,u,v);
    _EP0[0] = u;
    _EP0[1] = v;
    _patch1->Inverse(x,y,z,u,v);
    _EP1[0] = u;
    _EP1[1] = v;
    //printf("EPx = %g; EPy = %g; EPz = %g;\n",x,y,z);
  }
  else if (_patch0) {
    double u,v,x,y,z;
    x = _II->SP[0]; y = _II->SP[1]; z = _II->SP[2];
    _patch0->Inverse(x,y,z,u,v);
    _SP0[0] = u;
    _SP0[1] = v;
    x = _II->EP[0]; y = _II->EP[1]; z = _II->EP[2];
    _patch0->Inverse(x,y,z,u,v);
    _EP0[0] = u;
    _EP0[1] = v;
  }
  else if (_patch1) {
    double u,v,x,y,z;
    x = _II->SP[0]; y = _II->SP[1]; z = _II->SP[2];
    _patch1->Inverse(x,y,z,u,v);
    _SP1[0] = u;
    _SP1[1] = v;
    x = _II->EP[0]; y = _II->EP[1]; z = _II->EP[2];
    _patch1->Inverse(x,y,z,u,v);
    _EP1[0] = u;
    _EP1[1] = v;
  }
  else
    Msg::Error("No patches to find the intersection curve.");
}

void Curve::F(double t, double &x, double &y, double &z)
{
  if ((_patch0) && (_patch1)) {
    double u0, v0, u1, v1;
    //printf("patch0 : %d\n",_patch0->GetTag());
    //printf("patch1 : %d\n",_patch1->GetTag());
    //printf("%g,%g,%g\n",_II->SP[0],_II->SP[1],_II->SP[2]);
    //printf("%g,%g,%g\n",_II->EP[0],_II->EP[1],_II->EP[2]);
    //printf("%g,%g,%g,%g\n",_SP0[0],_SP0[1],_EP0[0],_EP0[1]);
    //printf("%g,%g,%g,%g\n",_SP1[0],_SP1[1],_EP1[0],_EP1[1]);
    
    if (_patch0->_PI->periodic[0] == 1) {
      if (std::abs(_SP0[0]-_EP0[0])<1.e-12)
	u0 = _SP0[0] + t * (1. + _EP0[0] - _SP0[0]);
      else
	u0 = _SP0[0] + t * (_EP0[0] - _SP0[0]);
      u0 -= floor(u0);
    }
    else
      u0 = _SP0[0] + t * (_EP0[0] - _SP0[0]);
    
    if (_patch0->_PI->periodic[1] == 1) {
      if (std::abs(_SP0[1]-_EP0[1])<1.e-12)
	v0 = _SP0[1] + t * (1. + _EP0[1] - _SP0[1]);
      else
	v0 = _SP0[1] + t * (_EP0[1] - _SP0[1]);
      v0 -= floor(v0);
    }
    else
      v0 = _SP0[1] + t * (_EP0[1] - _SP0[1]);
    
    if (_patch1->_PI->periodic[0] == 1) {
      if (std::abs(_SP1[0]-_EP1[0])<1.e-12)
	u1 = _SP1[0] + t * (1. + _EP1[0] - _SP1[0]);
      else
	u1 = _SP1[0] + t * (_EP1[0] - _SP1[0]);
      u1 -= floor(u1);
    }
    else
      u1 = _SP1[0] + t * (_EP1[0] - _SP1[0]);
    
    if (_patch1->_PI->periodic[1] == 1) {
      if (std::abs(_SP1[1]-_EP1[1])<1.e-12)
	v1 = _SP1[1] + t * (1. + _EP1[1] - _SP1[1]);
      else
	v1 = _SP1[1] + t * (_EP1[1] - _SP1[1]);
      v1 -= floor(v1);
    }
    else
      v1 = _SP1[1] + t * (_EP1[1] - _SP1[1]);
    
    //printf("%d,%d,%g,%g: %g,%g,%g,%g\n",_patch1->_PI->periodic[0],
    // _patch1->_PI->periodic[1],std::abs(_SP1[0]-_EP1[0]),
    // std::abs(_SP1[1]-_EP1[1]),u0,v0,u1,v1);
    
    double x0, y0, z0;
    _patch0->F(u0,v0,x0,y0,z0);
    
    //Msg::Info("%g,%g,%g",x0,y0,z0);
    
    double x1, y1, z1;
    _patch1->F(u1,v1,x1,y1,z1);
    
    //Msg::Info("%g,%g,%g",x1,y1,z1);
    
    double r,u,v,rPlus,uPlus,vPlus;
    
    r = u0;
    u = u1;
    v = v1;
    
    double F[3];
    F[0] = x1 - x0;
    F[1] = y1 - y0;
    F[2] = z1 - z0;
    
    while ((std::abs(F[0])>_tol) || (std::abs(F[1])>_tol) ||
	   (std::abs(F[2])>_tol)) {
      rPlus = r + _h;
      uPlus = u + _h;
      vPlus = v + _h;
      if (_patch0->_PI->periodic[0] == 1)
	rPlus -= std::floor(rPlus);
      if (_patch1->_PI->periodic[0] == 1)
	uPlus -= std::floor(uPlus);
      if (_patch1->_PI->periodic[1] == 1)
	vPlus -= floor(vPlus);
      //Msg::Info(" F : %g,%g,%g",F[0],F[1],F[2]);
      //Msg::Info(" R : %g,%g,%g",x0,y0,z0);
      double x0rPlus, y0rPlus, z0rPlus;
      _patch0->F(rPlus,v0,x0rPlus,y0rPlus,z0rPlus);
      double x1uPlus, y1uPlus, z1uPlus;
      _patch1->F(uPlus,v,x1uPlus,y1uPlus,z1uPlus);
      double x1vPlus, y1vPlus, z1vPlus;
      _patch1->F(u,vPlus,x1vPlus,y1vPlus,z1vPlus);
      
      double Df[3][3];
      Df[0][0] = - (x0rPlus - x0) / _h;
      Df[0][1] = (x1uPlus - x1) / _h;
      Df[0][2] = (x1vPlus - x1) / _h;
      Df[1][0] = - (y0rPlus - y0) / _h;
      Df[1][1] = (y1uPlus - y1) / _h;
      Df[1][2] = (y1vPlus - y1) / _h;
      Df[2][0] = - (z0rPlus - z0) / _h;
      Df[2][1] = (z1uPlus - z1) / _h;
      Df[2][2] = (z1vPlus - z1) / _h;
      
      //Msg::Info("D1: %g,%g,%g",Df[0][0],Df[0][1],Df[0][2]);
      //Msg::Info("D2: %g,%g,%g",Df[1][0],Df[1][1],Df[1][2]);
      //Msg::Info("D3: %g,%g,%g",Df[2][0],Df[2][1],Df[2][2]);
      
      double det = 
	Df[0][0] * (Df[1][1] * Df[2][2] - Df[1][2] * Df[2][1]) +
	Df[0][1] * (Df[1][2] * Df[2][0] - Df[1][0] * Df[2][2]) +
	Df[0][2] * (Df[1][0] * Df[2][1] - Df[1][1] * Df[2][0]);
      
      //Msg::Info("det: %g",det);
      
      double update[3];
      update[0] = 
	(Df[1][1] * Df[2][2] - Df[1][2] * Df[2][1]) * F[0] +
	(Df[0][2] * Df[2][1] - Df[0][1] * Df[2][2]) * F[1] +
	(Df[0][1] * Df[1][2] - Df[0][2] * Df[1][1]) * F[2];
      update[1] =
	(Df[1][2] * Df[2][0] - Df[1][0] * Df[2][2]) * F[0] +
	(Df[0][0] * Df[2][2] - Df[0][2] * Df[2][0]) * F[1] +
	(Df[0][2] * Df[1][0] - Df[0][0] * Df[1][2]) * F[2];
      update[2] =
	(Df[1][0] * Df[2][1] - Df[1][1] * Df[2][0]) * F[0] +
	(Df[0][1] * Df[2][0] - Df[0][0] * Df[2][1]) * F[1] +
	(Df[0][0] * Df[1][1] - Df[0][1] * Df[1][0]) * F[2];
      
      //Msg::Info("U: %g,%g,%g",update[0],update[1],update[2]);
      
      r -= update[0] / det;
      u -= update[1] / det;
      v -= update[2] / det;
      
      //Msg::Info("U/det: %g,%g,%g",update[0]/det,update[1]/det,update[2]/det);
      
      //Msg::Info("uv: %g,%g,%g",r,u,v);
      
      if (_patch0->_PI->periodic[0] == 1)
	r -= std::floor(r);
      if (_patch1->_PI->periodic[0] == 1)
	u -= std::floor(u);
      if (_patch1->_PI->periodic[1] == 1)
	v -= floor(v);

      //Msg::Info("UV : %g,%g,%g",r,u,v);
      
      //rPlus = r + _h;
      //uPlus = u + _h;
      //vPlus = v + _h;
      
      _patch0->F(r,v0,x0,y0,z0);
      _patch1->F(u,v,x1,y1,z1);
      
      F[0] = x1 - x0;
      F[1] = y1 - y0;
      F[2] = z1 - z0;
    }
    x = x0; y = y0; z = z0;
  }
  else if (_patch0) {
    if (_II->edgeNumber == 0)
      _patch0->F(t,0.,x,y,z);
    else if (_II->edgeNumber == 1)
      _patch0->F(1.,t,x,y,z);
    else if (_II->edgeNumber == 2)
      _patch0->F(1.-t,1.,x,y,z);
    else if (_II->edgeNumber == 3)
      _patch0->F(0.,1.-t,x,y,z);
    else
      Msg::Error("Unknown edge number.");
  }
  else if (_patch1) {
    if (_II->edgeNumber == 0)
      _patch1->F(t,0.,x,y,z);
    else if (_II->edgeNumber == 1)
      _patch1->F(1.,t,x,y,z);
    else if (_II->edgeNumber == 2)
      _patch1->F(1.-t,1.,x,y,z);
    else if (_II->edgeNumber == 3)
      _patch1->F(0.,1.-t,x,y,z);
  }
  else
    Msg::Error("No patches to find the intersection curve.");
}

bool Curve::Inverse(double x,double y,double z,double &t)
{
  if ((_patch0) && (_patch1)) {  
    double u0, v0;
    _patch0->Inverse(x,y,z,u0,v0);
    
    if ((std::abs(_SP0[1]-_EP0[1])<1.e-12) && 
	(_patch0->_PI->periodic[1] == 1)) {
      t = (v0 - _SP0[1] > 0 ? v0 - _SP0[1] : 1. + v0 - _SP0[1]);
    }
    else
      t = (v0 - _SP0[1]) / (_EP0[1] - _SP0[1]);
  }
  else if (_patch0) {
     double u,v;
    _patch0->Inverse(x,y,z,u,v);
    if (_II->edgeNumber == 0)
      t = u;
    else if (_II->edgeNumber == 1)
      t = v;
    else if (_II->edgeNumber == 2)
      t = 1. - u;
    else if (_II->edgeNumber == 3)
      t = 1. - v;   
  }
  else if (_patch1) {
    double u,v;
    _patch1->Inverse(x,y,z,u,v);
    if (_II->edgeNumber == 0)
      t = u;
    else if (_II->edgeNumber == 1)
      t = v;
    else if (_II->edgeNumber == 2)
      t = 1. - u;
    else if (_II->edgeNumber == 3)
      t = 1. - v;
  }
  else
    Msg::Error("No patches to find the intersection curve.");

  if ((t < 0.) || (t > 1.))
    return false;
  else
    return true;
}

double Curve::GetPou(double t)
{
  return 1.;
}

int Curve::GetTag()
{
  return _II->tag;
}

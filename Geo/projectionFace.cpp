#include "projectionFace.h"

SVector3 scalePoint(SVector3 p, SVector3 s)
{
  double x = p[0]*s[0];
  double y = p[1]*s[1];
  double z = p[2]*s[2];
  SVector3 result(x,y,z);
  return result;
}

SVector3 rotatePoint(SVector3 p, SVector3 r)
{
  double rot[16];
  double x = r[0] * Pi / 180.;
  double y = r[1] * Pi / 180.;
  double z = r[2] * Pi / 180.;
  double A = cos(x);
  double B = sin(x);
  double C = cos(y);
  double D = sin(y);
  double E = cos(z);
  double F = sin(z);
  double AD = A * D;
  double BD = B * D;
  rot[0] = C*E; rot[1] = BD*E+A*F; rot[2] =-AD*E+B*F; rot[3] = 0.;
  rot[4] =-C*F; rot[5] =-BD*F+A*E; rot[6] = AD*F+B*E; rot[7] = 0.;
  rot[8] = D;   rot[9] =-B*C;	     rot[10] = A*C;     rot[11] = 0.;
  rot[12] = 0.; rot[13] = 0.;      rot[14] = 0.;      rot[15] = 1.;
  
  x = p[0]*rot[0] + p[1]*rot[1] + p[2]*rot[2];
  y = p[0]*rot[4] + p[1]*rot[5] + p[2]*rot[6];
  z = p[0]*rot[8] + p[1]*rot[9] + p[2]*rot[10];
  
  SVector3 result(x,y,z);
  return result;
}

void projectionFace::rotate(SVector3 rot)
{
  rotation = rot + rotation;
}

void projectionFace::translate(SVector3 trans)
{
  translation = trans + translation;
}

void projectionFace::scale(SVector3 sc)
{
  scaleFactor[0] *= sc[0];
  scaleFactor[1] *= sc[1];
  scaleFactor[2] *= sc[2];
}

void projectionFace::setScale(SVector3 sc)
{
  scaleFactor[0] = sc[0];
  scaleFactor[1] = sc[1];
  scaleFactor[2] = sc[2];
}

void projectionFace::setRotation(SVector3 r)
{
  rotation[0] = r[0];
  rotation[1] = r[1];
  rotation[2] = r[2];  
}

void projectionFace::setTranslation(SVector3 t)
{
  translation = t;
}

projectionFace::projectionFace(GModel *m,int num) : GFace(m,num)
{
  for(int j = 0; j<3; j++){
    translation[j] = 0;
    rotation[j] = 0;
  }
}

projectionFace::~projectionFace()
{
}

parabolicCylinder::parabolicCylinder(GModel *m, int num) : projectionFace(m,num)
{
  focalPoint = 1;
  scaleFactor[0] = 1;
  scaleFactor[1] = 1;
  scaleFactor[2] = 1;
}

parabolicCylinder::~parabolicCylinder()
{
}

GPoint parabolicCylinder::point(double par1, double par2) const
{
  //first let's find the vertex
  //SPoint3 k = focalPoint - directrixPoint;
  //k.setPosition(k.x/2,k.y/2,k.z/2);
  //double f = sqrt(k.x^2 + k.y^2 + k.z^2);
  //SPoint3 vertex = directrixPoint + k;
  par1 -= .5;  //I need these to make sure the 'vertex' occurs at the parameter point (.5,.5)
  par2 -= .5;
  
  SVector3 p(par1, (1/(4*focalPoint))*pow(par1,2.0), par2);
  
  //now we have to do the necessary transformations
  p = scalePoint(p,scaleFactor);	//LOCAL SCALING
  p = rotatePoint(p,rotation);
  p = translation + p;
  
  GPoint gp(p[0],p[1],p[2]);	
  return gp;
}

SPoint2 parabolicCylinder::parFromPoint(const SPoint3 &p) const
{
  // ok...first we need to untranslate, unrotate and unscale it
  SVector3 trans(-translation[0], -translation[1], -translation[2]);
  SVector3 rot(-rotation[0],-rotation[1],-rotation[2]);
  SVector3 scalar(1/scaleFactor[0],1/scaleFactor[1],1/scaleFactor[2]);	//LOCAL SCALING?
  
  SVector3 pos(p[0],p[1],p[2]);
  pos = trans + pos;
  pos = rotatePoint(pos,rot);
  pos = scalePoint(pos, scalar);
  
  SPoint2 q(pos[0],pos[1]);	
  return q;
}

// du/dx, du/dy, du/dz; dv/dx, dv/dy, dv/dz
// v - (1/4f)*u^2 = 0

Pair<SVector3,SVector3> parabolicCylinder::firstDer(const SPoint2 &param) const
{
  SVector3 du;
  SVector3 dv;
  
  du[0] = 1;
  du[1] = -(1/(2*focalPoint))*(param[0]-.5);
  du[2] = 0;
  
  dv[0] = 0;
  dv[1] = 0;
  dv[2] = 1;

  //ok, now we need to scale and rotate...hmm
  du = scalePoint(du, scaleFactor);
  dv = scalePoint(dv, scaleFactor);
  du = rotatePoint(du, rotation);
  dv = rotatePoint(dv, rotation);
  //yeah...that "might" work
  
  Pair<SVector3,SVector3> result(du,dv);
  return result;
} 

// By convention, we're going to return the normal facing the interior
// of the parabola
SVector3 parabolicCylinder::normal(const SPoint2 &param) const
{	
  SVector3 n; 
  Pair<SVector3,SVector3> result = firstDer(param);
  
  const SVector3 left = result.left();
  const SVector3 right = result.right();
  n = crossprod(left, right);
  n.normalize();
  return n;
}

Range<double> parabolicCylinder::parBounds(int i) const
{
  return Range<double>(0, 1);
}

#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Camera.h"
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Trackball.h"
#include "Context.h"
#include "drawContext.h"

#if defined(HAVE_FLTK)
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#endif

using namespace std;
  

   
Camera::~Camera(){};

void Camera::init(){
  on=true;  
  near=0.1 ; 
  far=10000;
  eye_sep_ratio=.015;
  // apparent angle of the screen height
  aperture = 25;
  focallength = 100.;
  alongZ();
  this->lookAtCg();
  eyesep=distance*eye_sep_ratio;
  ref_distance=distance;
  this->update();
   
}

void Camera::alongX(){ 
  view.set(-1.,0.,0.);
  up.set(0., 0., 1);
  position=target-distance*view;
  this->update();
}
void Camera::alongY(){ 
  view.set(0.,-1.,0.);
  up.set(1., 0., 0);
  position=target-distance*view;
  this->update();
}
void Camera::alongZ(){ 
  view.set(0.,0.,-1.);
  up.set(0., 1., 0);
  position=target-distance*view;
  this->update();
}
void Camera::tiltHeadLeft(){
  up=-1.*right;
  update();
}
void Camera::tiltHeadRight(){
  up=right;
  update();
}



void Camera::lookAtCg(){
  target.x=CTX::instance()->cg[0];
  target.y=CTX::instance()->cg[1];
  target.z=CTX::instance()->cg[2];
  double W=CTX::instance()->max[0]-CTX::instance()->min[0];
  double H=CTX::instance()->max[1]-CTX::instance()->min[1];
  double P=CTX::instance()->max[2]-CTX::instance()->min[2];
  Lc=sqrt(1.*W*W+1.*H*H+1.*P*P);
  distance=.8*fabs(.5*Lc*4./3./tan(aperture*.01745329/2.));
  //distance=Lc*1.45;
   position=target-distance*view;
  this->update();
  focallength=distance;
  ref_distance=distance;
  eyesep=focallength*eye_sep_ratio;
}

void Camera::giveViewportDimension(const int& W,const int& H){
  screenwidth=W;
  screenheight=H;
  screenratio=(double)W/(double)H;
  glFleft  =-screenratio*wd2;
  glFright = screenratio*wd2;
  glFtop   = wd2;
  glFbottom =-wd2;
}

void Camera::update() {
  right.x=view.y*up.z-view.z*up.y;
  right.y=view.z*up.x-view.x*up.z;
  right.z=view.x*up.y-view.y*up.x;
  ref_distance=distance;
  normalize(up);
  normalize(right);
  normalize(view);
  radians =  0.0174532925 * aperture / 2.;
  wd2 = near * tan(radians);
  ndfl    = near / focallength;
}


void Camera::affiche() {
  cout<<"  ------------ CAMERA PARAMETERS ------------"   <<endl ;         
  cout<<"  position "<<  position.x<<","<<position.y<<","<<position.z <<endl ;    
  cout<<"  view "<<  view.x<<","<<view.y<<","<<view.z <<endl;              
  cout<<"  up "<< up.x<<","<<up.y<<","<<up.z <<endl;                 
  cout<<"  right "<< right.x<<","<<right.y<<","<<right.z  <<endl;              
  cout<<"  target "<<  target.x<<","<<target.y<<","<<target.z <<endl;   
  cout<<"  focallength "<<focallength <<endl;  
  cout<<"  aperture "<<aperture <<endl;     
  cout<<"  eyesep "<<eyesep <<endl;       
  cout<<"  screenwidth "<<screenwidth <<endl;
  cout<<"  screenheight "<<screenheight <<endl;
  cout<<"  distance "<<distance <<endl;
  cout<<"  ref_distance "<<ref_distance <<endl;
  cout<<"  button_left_down "<<button_left_down <<endl;
  cout<<"  button_middle_down "<< button_middle_down  <<endl;
  cout<<"  button_right_down "<< button_right_down  <<endl;
  cout<<"  stereoEnable "<< stereoEnable <<endl;
  cout<<"  Lc "<< Lc<<endl;
  cout<<"  eye_sep_ratio "<<eye_sep_ratio <<endl;
  cout<<"  closeness "<< closeness<<endl;
  cout<<"  near "<< near <<endl; 
  cout<<"  far "<<far <<endl;
  cout<<"  radians "<<radians <<endl;
  cout<<"  wd2 "<<wd2 <<endl;
}



void Camera::moveRight(double& theta) {
  this->update();
  position=position-distance*tan(theta)*right;
  target=position+distance*view;
  this->update();
}


void Camera::moveUp(double& theta) {
  this->update();
   position=position+distance*tan(theta)*up;
  target=position+distance*view;
  this->update();
}


void Camera::zoom(double& factor) {
  distance=fabs(1./factor*ref_distance);
  position=target-distance*view;
}


void Camera::rotate(double* q) {
  this->update();
  // rotation projection in global coordinates  
  Quaternion omega;
  omega.x=q[0]*right.x+q[1]*up.x-q[2]*view.x ;
  omega.y=q[0]*right.y+q[1]*up.y-q[2]*view.y ;
  omega.z=q[0]*right.z+q[1]*up.z-q[2]*view.z ;
  omega.w=q[3];
  // normalize the axe of rotation in the Quaternion omega if not null
  double sina=sin(acos(omega.w));
  double length;
  if (sina != 0.){
    length=(omega.x*omega.x+omega.y*+omega.y+omega.z*omega.z)/(sina*sina);
  }
  else{
    length=0.;
  }
  length=sqrt(length);
  if (length!=0.){
    omega.x/=length;
    omega.y/=length;
    omega.z/=length;
    Quaternion conj=conjugate(omega);  
    view=omega*view*conj;
    up=omega*up*conj;
    right=omega*right*conj;
    normalize(view);
    normalize(up);
    normalize(right);
    //actualize camera position 
    position=target-distance*view;
  }
  this->update();
}





// Quaternion and XYZ functions
double length(Quaternion &q) {  return sqrt(q.x*q.x+q.y*q.y+q.z*q.z+q.w*q.w); }

double length(XYZ &p) {  return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);}

void normalize(Quaternion &quat)
{
  double L = length(quat);
  quat.x /= L;   quat.y /= L;   quat.z /= L;   quat.w /= L;
}

void normalize(XYZ &p){
  double L = length(p);
  p.x /= L;   p.y /= L;   p.z /= L;
}

XYZ::XYZ (const Quaternion &R):x(R.x), y(R.y), z(R.z){} 

XYZ::XYZ(double _x,double _y,double _z):x(_x),y(_y),z(_z){}

void XYZ::set(const double&  _x,const double&  _y,const double&  _z){x=_x;y=_y;z=_z;}

void rotate(Quaternion omega,XYZ axe) {
  XYZ new_axe;
  Quaternion qaxe,new_qaxe;
  qaxe.x=axe.x;    qaxe.y=axe.y;   qaxe.z=axe.z;   qaxe.w=0.;
  new_qaxe=mult(mult(omega,qaxe),conjugate(omega));
  axe.x=new_qaxe.x ;   axe.y=new_qaxe.y;   axe.z=new_qaxe.z;
}

XYZ operator* (const double &a,const XYZ &T){ 
  XYZ res(T);
  res.x*=a;
  res.y*=a;
  res.z*=a;
  return res;
}
XYZ operator+ (const XYZ &L,const XYZ &R){ 
  XYZ res(L);
  res.x+=R.x;
  res.y+=R.y;
  res.z+=R.z;
  return res;
}
XYZ operator- (const XYZ &L,const XYZ &R){ 
  XYZ res(L);
  res.x-=R.x;
  res.y-=R.y;
  res.z-=R.z;
  return res;
}

Quaternion::Quaternion(const XYZ &R):x(R.x), y(R.y), z(R.z),w(0.){}

Quaternion mult(const Quaternion& A,const Quaternion& B)
{
  Quaternion C;
  C.x = A.w*B.x + A.x*B.w + A.y*B.z - A.z*B.y;
  C.y = A.w*B.y - A.x*B.z + A.y*B.w + A.z*B.x;
  C.z = A.w*B.z + A.x*B.y - A.y*B.x + A.z*B.w;
  C.w = A.w*B.w - A.x*B.x - A.y*B.y - A.z*B.z;
  return C;
}

Quaternion operator *(const Quaternion& A,const Quaternion& B){
  return mult(A,B);
}

Quaternion conjugate(Quaternion quat) {
  quat.x = -quat.x;   quat.y = -quat.y;   quat.z = -quat.z;
  return quat;
}

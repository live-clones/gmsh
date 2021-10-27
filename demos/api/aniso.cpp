#include <iostream>
#include <map>
#include <set>
#include <gmsh.h>
#include <math.h>
#include "poly34.cppp"
#include "../../Mesh/meshPolyMesh.h"
#include "../../Mesh/meshTriangulation.h"

#define Pi M_PI

#define Power(x, y)	(pow((double)(x), (double)(y)))
#define Sqrt(x)		(sqrt((double)(x)))
#define Sqrtl(x)        (sqrt((double)(x)))

#define Abs(x)		(fabs((double)(x)))

#define Exp(x)		(exp((double)(x)))
#define Log(x)		(log((double)(x)))

#define Sin(x)		(sin((double)(x)))
#define Cos(x)		(cos((double)(x)))
#define Tan(x)		(tan((double)(x)))

#define ArcSin(x)       (asin((double)(x)))
#define ArcCos(x)       (acos((double)(x)))
#define ArcTan(x)       (atan((double)(x)))

#define Sinh(x)          (sinh((double)(x)))
#define Cosh(x)          (cosh((double)(x)))
#define Tanh(x)          (tanh((double)(x)))
#define Sech(x)          (1./cosh((double)(x)))


#define Cot(x)          (1./tan((double)(x)))
#define Csc(x)          (1./sin((double)(x)))
#define Sec(x)          (1./cos((double)(x)))

int CASE_ = 0;

#if 0 
#define U_X  0
#define U_Y  1
#define V_X  2
#define V_Y  3

#define U_XX 4
#define U_XY 5
#define U_YX 6
#define U_YY 7

#define V_XX 8
#define V_XY 9
#define V_YX 10
#define V_YY 11

#define U_XXX 12
#define U_XXY 13
#define U_XYX 14
#define U_XYY 15

#define U_YXX 16
#define U_YXY 17
#define U_YYX 18
#define U_YYY 19

#define V_XXX 20
#define V_XXY 21
#define V_XYX 22
#define V_XYY 23

#define V_YXX 24
#define V_YXY 25
#define V_YYX 26
#define V_YYY 27

#define U_    28
#define V_    29
#define P_    30

#else 

#define U_X  1
#define U_Y  2
#define V_X  1
#define V_Y  2

#define U_XX 3
#define U_XY 4
#define U_YX 5
#define U_YY 6

#define V_XX 3
#define V_XY 4
#define V_YX 5
#define V_YY 6

#define U_XXX 7
#define U_XXY 8
#define U_XYX 9
#define U_XYY 10

#define U_YXX 11
#define U_YXY 12
#define U_YYX 13
#define U_YYY 14

#define V_XXX 7
#define V_XXY 8
#define V_XYX 9
#define V_XYY 10

#define V_YXX 11
#define V_YXY 12
#define V_YYX 13
#define V_YYY 14

#define U_    0
#define V_    0
#define P_    0
#endif


static void PROBE (int TAG, double x, double y, double z, std::vector<double> &val, const int step = -1, const int numComp = -1){
  val.clear();
  gmsh::view::probe(TAG,x,y,z,val);//, -1, -1, 0, 1.e-5);
  //  printf("%g %g %g %d %g\n",x,y,z,TAG,val[0]);
  if(val.empty()){
    val.push_back(0);printf("argh\n");
  }
}

static bool INSIDE (double* x){
  if (CASE_ == -4){
    if (x[0] < 0)return false;
    if (x[1] < 0)return false;
    if (x[0] > 1)return false;
    if (x[1] > 1)return false;
    return true;
  }
  if (fabs(x[0]) <= 1 && fabs(x[1]) <= 1)return true;
  return false;
}

std::string nameModel;

static double f (double x, double y) {
  switch(CASE_) {
  case 6 : return atan(10*(x+y)) ;
  case 1 : return atan(10*(sin(3*M_PI*y/2) - 2*x)) ;
  case 2 : return Power (x,3) + Power (y,3);
  case 4 : return Power (x,4) + Power (y,4);
  case 5 : return Power (x,3) + Power (y,2)*x;
  case 3 : return 0.5 + 0.5*Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4))));
  case 7 : return atan(x) + atan(y) ;
  case -2 : {
    std::vector<double> u;
    PROBE(V_,x,y,0.0,u);
    return u[0];
  }
  default :
    {
      gmsh::model::setCurrent(nameModel);
      std::vector<double> u,v;
      PROBE(U_,x,y,0.0,u);
      PROBE(V_,x,y,0.0,v);
      gmsh::model::setCurrent("rect");
      return u[0]*u[0]+v[0]*v[0];
    }
  }    
}

static double fx (double x, double y) {
  switch(CASE_) {
  case 6 : return 10/(1 + 100*Power(x + y,2));
  case 1 : return -20/(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2));
  case 2 : return 3*x*x;
  case 4 : return 4*x*x*x;
  case 5 : return 3*Power (x,2) + Power (y,2);
  case 3 : return -10.*Power(x,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7 : return 1/(1 + Power(x,2));
  case -2 : {
    std::vector<double> u;
    PROBE(V_X,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> ux, vx;
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    gmsh::model::setCurrent("rect");
    return 2*u[0] * ux[0] + 2*v[0] * vx[0] ;
  }
  }
}

static double fy (double x, double y) {
  switch(CASE_) {
  case 6 : return 10/(1 + 100*Power(x + y,2));
  case 1 : return (15*Pi*Cos((3*Pi*y)/2.))/(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2));
  case 2 : return 3*y*y;
  case 4 : return 4*y*y*y;
  case 5 : return 2*x*y;
  case 3 : return -10.*Power(y,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7 : return 1/(1 + Power(y,2));
  case -2 : {
    std::vector<double> u;
    PROBE(V_Y,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    gmsh::model::setCurrent("rect");
    return 2*u[0] * uy[0] + 2*v[0] * vy[0] ;
  }
  }
}


static double fxx (double x, double y) {
  switch(CASE_) {
  case 6 : return (-2000*(x + y))/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (-8000*(-2*x + Sin((3*Pi*y)/2.)))/Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2);
  case 2 : return 6*x;
  case 4 : return 12*x*x;
  case 5 : return 6*x;
  case 3 : return -30.*Power(x,2)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2) - 
      400.*Power(x,6)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4))));
  case 7 : return (-2*x)/Power(1 + Power(x,2),2);
  case -2 : {
    std::vector<double> u;
    PROBE(V_XX,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> ux, vx;
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    std::vector<double> uxx, vxx;
    PROBE(U_XX,x,y,0.0,uxx,0,1);
    PROBE(V_XX,x,y,0.0,vxx,0,1);
    gmsh::model::setCurrent("rect");
    return 2*uxx[0]*u[0] + 2 * ux[0]*ux[0] + 2*vxx[0]*v[0] + 2 * vx[0]*vx[0] ;
  }
  }
}

static double fyy (double x, double y) {
  switch(CASE_) {
  case 6 : return (-2000*(x + y))/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (-4500*Power(Pi,2)*Power(Cos((3*Pi*y)/2.),2)*(-2*x + Sin((3*Pi*y)/2.)))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2) - 
      (45*Power(Pi,2)*Sin((3*Pi*y)/2.))/(2.*(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2)));
  case 2 : return 6*y;
  case 4 : return 12*y*y;
  case 5 : return 2*x;
  case 3 : return -30.*Power(y,2)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2) - 
      400.*Power(y,6)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4))));
  case 7 : return (-2*y)/Power(1 + Power(y,2),2);
  case -2 : {
    std::vector<double> u;
    PROBE(V_YY,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    std::vector<double> uyy, vyy;
    PROBE(U_YY,x,y,0.0,uyy,0,1);
    PROBE(V_YY,x,y,0.0,vyy,0,1);
    gmsh::model::setCurrent("rect");
    return 2*uyy[0]*u[0] + 2 * uy[0]*uy[0] + 2*vyy[0]*v[0] + 2 * vy[0]*vy[0] ;
  }
  }
}

static double fxy (double x, double y) {
  switch(CASE_) {
  case 6 : return (-2000*(x + y))/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (6000*Pi*Cos((3*Pi*y)/2.)*(-2*x + Sin((3*Pi*y)/2.)))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2);
  case 2 : return 0;
  case 5 : return 2*y;
  case 3 : return -400.*Power(x,3)*Power(y,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4))));
  case 7 : return 0.0;
  case -2 : {
    std::vector<double> u;
    PROBE(V_XY,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy, ux, vx;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    std::vector<double> uyx, vyx;
    std::vector<double> uxy, vxy;
    PROBE(U_XY,x,y,0.0,uxy);
    PROBE(U_YX,x,y,0.0,uyx);
    PROBE(V_XY,x,y,0.0,vxy);
    PROBE(V_YX,x,y,0.0,vyx);
    gmsh::model::setCurrent("rect");
    double UXY = 0.5*(uxy[0]+uyx[0]);
    double VXY = 0.5*(vxy[0]+vyx[0]);
    return 2*u[0]*UXY + 2*v[0]*VXY + 2* ux[0]*uy[0] + 2* vx[0]*vy[0];
  }
  }
}



static double fxxx (double x, double y) {
  switch(CASE_) {
  case 6 : return (800000*Power(x + y,2))/Power(1 + 100*Power(x + y,2),3) - 
      2000/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (-6400000*Power(-2*x + Sin((3*Pi*y)/2.),2))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),3) + 
      16000/Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2);
  case 2 : return 6;
  case 4 : return 24*x;
  case 5 : return 6;
  case 3 : return -60.*x*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2) + 
   8000.*Power(x,9)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),4) - 
   3600.*Power(x,5)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
    Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))) - 
   16000.*Power(x,9)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Power(Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7 : return (8*x*x)/pow(1+x*x,3)-2/pow(1+x*x,2);
  case -2 : {
    std::vector<double> u;
    PROBE(V_XXX,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> ux, vx;
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    std::vector<double> uxx, vxx;
    PROBE(U_XX,x,y,0.0,uxx,0,1);
    PROBE(V_XX,x,y,0.0,vxx,0,1);

    std::vector<double> uxxx, vxxx;
    PROBE(U_XXX,x,y,0.0,uxxx);
    PROBE(V_XXX,x,y,0.0,vxxx);
    gmsh::model::setCurrent("rect");
    return 6*(uxx[0]*ux[0] +vxx[0]*vx[0]) + 2* (u[0]*uxxx[0]+v[0]*vxxx[0]); ;
  }
  }
}

static double fyyy (double x, double y) {
  switch(CASE_) {
  case 6 : return (800000*Power(x + y,2))/Power(1 + 100*Power(x + y,2),3) - 
      2000/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (2700000*Power(Pi,3)*Power(Cos((3*Pi*y)/2.),3)*Power(-2*x + Sin((3*Pi*y)/2.),2))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),3) - 
      (6750*Power(Pi,3)*Power(Cos((3*Pi*y)/2.),3))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2) + 
      (20250*Power(Pi,3)*Cos((3*Pi*y)/2.)*Sin((3*Pi*y)/2.)*(-2*x + Sin((3*Pi*y)/2.)))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2) - 
      (135*Power(Pi,3)*Cos((3*Pi*y)/2.))/(4.*(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2)));
  case 2 : return 6;
  case 4 : return 24*y;
  case 5 : return 0;
  case 3 : return -60.*y*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2) + 
   8000.*Power(y,9)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),4) - 
   3600.*Power(y,5)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
    Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))) - 
   16000.*Power(y,9)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Power(Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7 : return (8*y*y)/pow(1+y*y,3)-2/pow(1+y*y,2);
  case -2 : {
    std::vector<double> u;
    PROBE(V_YYY,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    std::vector<double> uyy, vyy;
    PROBE(U_YY,x,y,0.0,uyy,0,1);
    PROBE(V_YY,x,y,0.0,vyy,0,1);

    std::vector<double> uyyy, vyyy;
    PROBE(U_YYY,x,y,0.0,uyyy);
    PROBE(V_YYY,x,y,0.0,vyyy);
    gmsh::model::setCurrent("rect");
    return 6*(uyy[0]*uy[0] +vyy[0]*vy[0]) + 2* (u[0]*uyyy[0]+v[0]*vyyy[0]); ;
  }
  }
}

static double fxyy (double x, double y) {
  switch(CASE_) {
  case 6 : return  (800000*Power(x + y,2))/Power(1 + 100*Power(x + y,2),3) - 
      2000/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (-3600000*Power(Pi,2)*Power(Cos((3*Pi*y)/2.),2)*Power(-2*x + Sin((3*Pi*y)/2.),2))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),3) + 
      (9000*Power(Pi,2)*Power(Cos((3*Pi*y)/2.),2))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2) - 
      (9000*Power(Pi,2)*Sin((3*Pi*y)/2.)*(-2*x + Sin((3*Pi*y)/2.)))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2);
  case 5 : return 2;
  case 3 : return 8000.*Power(x,3)*Power(y,6)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),4) - 
      1200.*Power(x,3)*Power(y,2)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))) - 
      16000.*Power(x,3)*Power(y,6)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),
				      2)*Power(Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7 : return 0;
  case -2 : {
    std::vector<double> u;
    PROBE(V_XYY,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy, ux, vx;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    std::vector<double> uyx, vyx, uyy;
    std::vector<double> uxy, vxy, vyy;
    PROBE(U_YY,x,y,0.0,uyy);
    PROBE(U_XY,x,y,0.0,uxy);
    PROBE(U_YX,x,y,0.0,uyx);
    PROBE(V_YY,x,y,0.0,vyy);
    PROBE(V_XY,x,y,0.0,vxy);
    PROBE(V_YX,x,y,0.0,vyx);
    double UXY = 0.5*(uxy[0]+uyx[0]);
    double VXY = 0.5*(vxy[0]+vyx[0]);
    std::vector<double> uxyy, uyxy,uyyx ;
    std::vector<double> vxyy, vyxy,vyyx ;
    PROBE(U_YYX,x,y,0.0,uyyx);
    PROBE(U_XYY,x,y,0.0,uxyy);
    PROBE(U_YXY,x,y,0.0,uyxy);
    PROBE(V_YYX,x,y,0.0,vyyx);
    PROBE(V_XYY,x,y,0.0,vxyy);
    PROBE(V_YXY,x,y,0.0,vyxy);
    double UXYY = (uxyy[0]+uyxy[0]+uyyx[0])/3.0;
    double VXYY = (vxyy[0]+vyxy[0]+vyyx[0])/3.0;
    gmsh::model::setCurrent("rect");
    return 4 * (UXY*uy[0] + VXY*vy[0]) + 2 * (uy[0]*uyy[0]+vy[0]*vyy[0]) +
      2 * (u[0]*UXYY+v[0]*VXYY);     
  }
  }
}

static double fxxy (double x, double y) {
  switch(CASE_) {
  case 6 : return (800000*Power(x + y,2))/Power(1 + 100*Power(x + y,2),3) - 
      2000/Power(1 + 100*Power(x + y,2),2);
  case 1 : return (4800000*Pi*Cos((3*Pi*y)/2.)*Power(-2*x + Sin((3*Pi*y)/2.),2))/
      Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),3) - 
      (12000*Pi*Cos((3*Pi*y)/2.))/Power(1 + 100*Power(-2*x + Sin((3*Pi*y)/2.),2),2);
  case 3 : return 8000.*Power(x,6)*Power(y,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),4) - 
      1200.*Power(x,2)*Power(y,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2)*
      Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))) - 
      16000.*Power(x,6)*Power(y,3)*Power(Sech(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),
				      2)*Power(Tanh(20*(0.75 - 0.25*(Power(x,4) + Power(y,4)))),2);
  case 7: return 0;
  case -2 : {
    std::vector<double> u;
    PROBE(V_XXY,x,y,0.0,u);
    return u[0];
  }
  default : {
    gmsh::model::setCurrent(nameModel);
    std::vector<double> u,v;
    PROBE(U_,x,y,0.0,u);
    PROBE(V_,x,y,0.0,v);
    std::vector<double> uy, vy, ux, vx;
    PROBE(U_Y,x,y,0.0,uy);
    PROBE(V_Y,x,y,0.0,vy);
    PROBE(U_X,x,y,0.0,ux);
    PROBE(V_X,x,y,0.0,vx);
    std::vector<double> uyx, vyx, uxx;
    std::vector<double> uxy, vxy, vxx;
    PROBE(U_XX,x,y,0.0,uxx);
    PROBE(U_XY,x,y,0.0,uxy);
    PROBE(U_YX,x,y,0.0,uyx);
    PROBE(V_XX,x,y,0.0,vxx);
    PROBE(V_XY,x,y,0.0,vxy);
    PROBE(V_YX,x,y,0.0,vyx);
    double UXY = 0.5*(uxy[0]+uyx[0]);
    double VXY = 0.5*(vxy[0]+vyx[0]);
    std::vector<double> uxxy, uyxx,uxyx ;
    std::vector<double> vxxy, vyxx,vxyx ;
    PROBE(U_XXY,x,y,0.0,uxxy);
    PROBE(U_YXX,x,y,0.0,uyxx);
    PROBE(U_XYX,x,y,0.0,uxyx);
    PROBE(V_XXY,x,y,0.0,vxxy);
    PROBE(V_YXX,x,y,0.0,vyxx);
    PROBE(V_XYX,x,y,0.0,vxyx);
    gmsh::model::setCurrent("rect");
    double UXXY = (uxxy[0]+uyxx[0]+uxyx[0])/3.0;
    double VXXY = (vxxy[0]+vyxx[0]+vxyx[0])/3.0;
    gmsh::model::setCurrent("rect");
    return 4 * (UXY*ux[0] + VXY*vx[0]) + 2 * (uy[0]*uxx[0]+vy[0]*vxx[0]) +
      2 * (u[0]*UXXY+v[0]*VXXY);     

  }
  }
}


static double dtt (const double x, const double y, double C, double S)
{
  const double c11 = fxx(x,y);
  const double c22 = fyy(x,y);
  const double c12 = fxy(x,y);
  
  return C*C*c11 + S*S*c22+ 2*C*S*c12;
  
}

static double dttt (const double x, const double y, double C, double S)
{
  const double c111 = fxxx(x,y);
  const double c222 = fyyy(x,y);
  const double c112 = fxxy(x,y);
  const double c122 = fxyy(x,y);
  
  return C*C*C*c111 + S*S*S*c222+ 3*C*C*S*c112 + 3*C*S*S*c122;
  
}

static double dtttt (const double x, const double y, double C, double S)
{
  const double eps = 1.e-8;

  return  (dttt (x+C*eps, y+S*eps, C, S) - dttt (x, y, C, S))/eps;  
}


static void computeMetricMaxRectangle (double x, double y, double S, double C, double lMin, double lMax, double eps,
				       double &g00, double &g01, double &g11){
  
  const int N = 40;
  double tMax = 0,uMax = 0;
  for (int i=0;i<N;i++){
    const double theta = (double)i * 2 * M_PI / (N-1);
    const double St = sin(theta);
    const double Ct = cos(theta);
    const double dttt_ = fabs(dttt (x,y, Ct, St));
    const double X = dttt_ * Ct;
    const double Y = dttt_ * St;
    const double t =  C * X + S * Y;
    const double u = -S * X + C * Y;
    if (t > tMax) tMax = t;
    if (u > uMax) uMax = u;
  }

  //  printf("%12.5E %12.5E\n",tMax,uMax);
  
  double l0 = tMax != 0. ? pow (6*eps/tMax,0.3333) : lMax;
  double l1 = uMax != 0. ? pow (6*eps/uMax,0.3333) : lMax;
  
  l0 = std::min (l0,lMax);
  l0 = std::max (l0,lMin);
  l1 = std::min (l1,lMax);
  l1 = std::max (l1,lMin);
  
  double h0 = 1./(l0*l0);
  double h1 = 1./(l1*l1);
  
  g00 = C*C*h0+S*S*h1;
  g11 = S*S*h0+C*C*h1;
  g01 = S*C*(h1-h0);  
  
}

static void computeMetricDMax (double x, double y, double lMin, double lMax,
			       double eps, double &g00, double &g01, double &g11, double CMax, double SMax){


  const int N = 5;
  double AreaMin = 1.e22;
  for (int i=0;i<N;i++){
    const double theta_ = (double)i * 2 * M_PI / (N-1);
    const double S = sin(theta_);
    const double C = cos(theta_);
    double tMax = 0,uMax = 0;
    for (int j=0;j<N;j++){
      const double theta = (double)j * 2 * M_PI / (N-1);
      const double St = sin(theta);
      const double Ct = cos(theta);
      const double dttt_ = fabs(dttt (x,y, Ct, St));
      const double X = dttt_ * Ct;
      const double Y = dttt_ * St;
      const double t =  C * X + S * Y;
      const double u = -S * X + C * Y;
      if (t > tMax) tMax = t;
      if (u > uMax) uMax = u;
    }
    if (tMax*uMax < AreaMin){
      SMax = S;
      CMax = C;
      AreaMin = tMax*uMax;
    }
  }
  return;
  
  const double dttt0_ = fabs(dttt (x,y, CMax, SMax));
  const double dttt1_ = fabs(dttt (x,y, -SMax, CMax));
  
  double l0 = dttt0_ != 0. ? pow (6*eps/dttt0_,0.3333) : lMax;
  double l1 = dttt1_ != 0. ? pow (6*eps/dttt1_,0.3333) : lMax;
  
  l0 = std::min (l0,lMax);
  l0 = std::max (l0,lMin);
  l1 = std::min (l1,lMax);
  l1 = std::max (l1,lMin);
  
  if (x == 0 && y == 0){
    printf("%12.5E %12.5E %12.5E %12.5E\n",CMax,SMax, l0, l1);
  }

  double h0 = 1./(l0*l0);
  double h1 = 1./(l1*l1);
  
  g00 = CMax*CMax*h0+SMax*SMax*h1;
  g11 = SMax*SMax*h0+CMax*CMax*h1;
  g01 = SMax*CMax*(h1-h0);  

}


static void computeMetricP2Grad (double x, double y, double lMin, double lMax, double eps,
				 double &g00, double &g01, double &g11, FILE *F,
				 double &C, double &S){
  
  const double c1 = (fx(x,y));
  const double c2 = (fy(x,y));

  
  double l = sqrt (c1*c1+c2*c2);  

  if (l < 1.e-12){
    C = 1;
    S = 0;
  }
  else {  
    C = c1/l;
    S = c2/l;
  }
  return;
  
  //computeMetricMaxRectangle (x, y, S, C, lMin, lMax, eps, g00, g01, g11);

  
  //  return;
  
  const double dttt0_ = fabs(dttt (x,y, C, S));
  const double dttt1_ = fabs(dttt (x,y, S, -C));
  
  double l0 = dttt0_ != 0. ? pow (6*eps/dttt0_,0.3333) : lMax;
  double l1 = dttt1_ != 0. ? pow (6*eps/dttt1_,0.3333) : lMax;

  
  l0 = std::min (l0,lMax);
  l0 = std::max (l0,lMin);
  l1 = std::min (l1,lMax);
  l1 = std::max (l1,lMin);
  
  double h0 = 1./(l0*l0);
  double h1 = 1./(l1*l1);
  
  g00 = C*C*h0+S*S*h1;
  g11 = S*S*h0+C*C*h1;
  g01 = S*C*(h1-h0);  
}

static void computeMetricP2Hess (double x, double y, double lMin, double lMax, double eps,
				 double &g00, double &g01, double &g11, FILE *F, double &C, double &S){
  
  const double c11 = fxx(x,y);
  const double c22 = fyy(x,y);
  const double c12 = fxy(x,y);

  const double t2 = atan2(2*c12,c11-c22);
  C = cos(t2/2);
  S = sin(t2/2);
  return;
  //  computeMetricMaxRectangle (x, y, S, C, lMin, lMax, eps, g00, g01, g11);

  //  return;
  //  printf("%12.5E %12.5E %12.5E %12.5E %12.5E\n",c11,c12,c22,C,S);
  
    const double dttt1_ = fabs(dttt (x,y, -S, C));
    const double dttt0_ = fabs(dttt (x,y, C, S));
  
    //const double dtt1_ = fabs(dtt (x,y, -S, C));
    //  const double dtt0_ = fabs(dtt (x,y, C, S));

  double l0 = dttt0_ != 0. ? pow (6*eps/dttt0_,0.3333) : lMax;
  double l1 = dttt1_ != 0. ? pow (6*eps/dttt1_,0.3333) : lMax;
  //double l0 = dtt0_ != 0. ? pow (2*eps/dtt0_,0.5) : lMax;
  //  double l1 = dtt1_ != 0. ? pow (2*eps/dtt1_,0.5) : lMax;
  
  l0 = std::min (l0,lMax);
  l0 = std::max (l0,lMin);
  l1 = std::min (l1,lMax);
  l1 = std::max (l1,lMin);
    
  double h0 = 1./(l0*l0);
  double h1 = 1./(l1*l1);
  
  fprintf(F,"VP(%g,%g,%g){%g,%g,%g};\n",x,y,0.,C,S,0.);
  fprintf(F,"VP(%g,%g,%g){%g,%g,%g};\n",x,y,0.,-S,C,0.);

  g00 = C*C*h0+S*S*h1;
  g11 = S*S*h0+C*C*h1;
  g01 = S*C*(h1-h0);  
    
}

static void computeMetricP2 (double x, double y, double lMin, double lMax, double eps, double &g00, double &g01, double &g11,
			     FILE *F, double &C, double &S){
  double c111 = fxxx(x,y);
  const double c222 = fyyy(x,y);
  const double c112 = fxxy(x,y);
  const double c122 = fxyy(x,y);
  
  if (c111 == 0) {
    printf("coucou\n");
    c111 = .0001;
  }
  
  double c[3];
  int nRoots = SolveP3(c, c112/c111, c122/c111, c222/c111);
  
  int myRoot = 0;
  
  if (nRoots == 3) {
    double maxdttt_ = 0;
    for (int i=0;i<3;i++){
      C = c[i];
      S = 1;
      double L =  sqrt(C*C+S*S);
      C /=L;
      S /=L;
      double dttt_ = fabs(dttt (x,y, -S, C));
      if (dttt_ > maxdttt_){
	myRoot = i;
	maxdttt_ = dttt_ ;
      }
    }      
  }
  
  C = c[myRoot];
  S = 1;
  
  const double L =  sqrt(C*C+S*S);
  C /=L;
  S /=L;
  return;
  //  computeMetricMaxRectangle (x, y, S, C, lMin, lMax, eps, g00, g01, g11);
  
  //  return;
  const double dttt_  = fabs(dttt (x,y, -S, C));
  const double dtttt_ = fabs(dtttt (x,y, C, S));
  
  // const double dttt1_ = fabs(dttt (x,y, -S, C));
  // const double dttt0_ = fabs(dttt (x,y, C, S));
  
  //  double l0 = dttt0_ != 0. ? pow (6*eps/dttt0_,0.3333) : lMax;
  //  double l1 = dttt1_ != 0. ? pow (6*eps/dttt1_,0.3333) : lMax;
 
  double l0 = dtttt_ != 0. ? pow (24*eps/dtttt_,0.25) : lMax;
  double l1 = dttt_  != 0. ? pow (6*eps/dttt_,0.3333) : lMax;
    
  l0 = std::min (l0,lMax);
  l0 = std::max (l0,lMin);
  l1 = std::min (l1,lMax);
  l1 = std::max (l1,lMin);
  
  
  double h0 = 1./(l0*l0);
  double h1 = 1./(l1*l1);
  
  g00 = C*C*h0+S*S*h1;
  g11 = S*S*h0+C*C*h1;
  g01 = S*C*(h1-h0);
}


void smoothDirections( std::map<size_t, double> &C,  std::map<size_t, double> &S){
  std::vector<int> elementTypes;
  std::vector<std::vector<std::size_t> > elementTags;
  std::vector<std::vector<std::size_t> > nodeTags;
  gmsh::model::mesh::getElements ( elementTypes,elementTags, nodeTags, 2); 
  std::multimap<size_t, size_t> graph;
  std::set<size_t> nodes_to_treat;
  std::set<size_t> nodes;

  
  for (size_t i=0; i<elementTags[0].size();i++){
    size_t n0 = nodeTags[0][3*i+0];
    size_t n1 = nodeTags[0][3*i+1];
    size_t n2 = nodeTags[0][3*i+2];
    graph.insert(std::make_pair(n0,n1));
    graph.insert(std::make_pair(n1,n2));
    graph.insert(std::make_pair(n2,n0));
    nodes.insert(n0);
    nodes.insert(n1);
    nodes.insert(n2);
  }

  double threshold = 0.1;
  
  for (auto n : nodes){
    double c = C[n];
    double s = S[n];
    for (auto it = graph.lower_bound(n); it != graph.upper_bound(n) ; ++it){
      size_t neigh = it->second;
      double cn = C[neigh];
      double sn = S[neigh];
      double pv = fabs(cn*c + sn*s);
      if (pv > threshold && pv < 1.-threshold)nodes_to_treat.insert(n);
    }
  }
  int iter = 0;
  while (iter++ < 100){
    for (auto n : nodes_to_treat){
      double c4 = 0;
      double s4 = 0;
      for (auto it = graph.lower_bound(n); it != graph.upper_bound(n) ; ++it){
	size_t neigh = it->second;
	double cn = C[neigh];
	double sn = S[neigh];
	double theta = atan2(sn,cn);
	c4 += cos(4*theta);
	s4 += sin(4*theta);
      }
      double theta = 0.25*atan2(s4,c4);
      C[n] = cos(theta);
      S[n] = sin(theta);      
    }
  }

  FILE *f = fopen("dirs.pos","w");
  fprintf(f,"View\"Dirs\"{\n");

  for (auto n : nodes){
    double c = C[n];
    double s = S[n];
    if (nodes_to_treat.find(n) != nodes_to_treat.end()){
      c*=2;
      s*=2;
    }
    std::vector<double>coord;
    std::vector<double> par;
    int dim,tag;
    gmsh::model::mesh::getNode(n,coord,par,dim,tag);
    
    fprintf(f,"VP(%g,%g,0){%g,%g,0};",coord[0],coord[1],c,s);
  }
  
  fprintf(f,"};\n");
  fclose(f);
  
}


/// Let us try to minimize the error ///
double ERROR_SQUARED_P2 (double *xa, double *xb, double *xc,
			 double *xab, double *xbc, double *xca) {
  int triangleP2 = gmsh::model::mesh::getElementType("Triangle", 2);
  std::vector<double> localCoord;
  std::vector<double> weights;
  gmsh::model::mesh::getIntegrationPoints(triangleP2, "Gauss12",localCoord, weights);
  std::vector<double> basisFunctions;
  int numComponents, numOrientations;
  gmsh::model::mesh::getBasisFunctions(triangleP2, localCoord, "Lagrange",
				       numComponents,basisFunctions,numOrientations);

  std::vector<double> gradBasisFunctions;
  gmsh::model::mesh::getBasisFunctions(triangleP2, localCoord, "GradLagrange",
				       numComponents,gradBasisFunctions,numOrientations);
  
  double F[6] = {f(xa[0],xa[1]), f(xb[0],xb[1]), f(xc[0],xc[1]),
		 f(xab[0],xab[1]), f(xbc[0],xbc[1]), f(xca[0],xca[1])};  
  double X[6] = {xa[0], xb[0], xc[0], xab[0], xbc[0], xca[0] };  
  double Y[6] = {xa[1], xb[1], xc[1], xab[1], xbc[1], xca[1] };
  double e2 = 0;
  for (size_t i=0;i<weights.size();i++){
    double interpolated = 0, x=0, y=0, dxdu=0, dxdv=0, dydu=0, dydv=0;
    
    for (size_t j=0;j<6;j++){
      x +=  basisFunctions[6*i+j] * X[j];
      y +=  basisFunctions[6*i+j] * Y[j];
      dxdu +=  gradBasisFunctions[3*(6*i+j)+0] * X[j];
      dxdv +=  gradBasisFunctions[3*(6*i+j)+1] * X[j];
      dydu +=  gradBasisFunctions[3*(6*i+j)+0] * Y[j];
      dydv +=  gradBasisFunctions[3*(6*i+j)+1] * Y[j];
      interpolated += basisFunctions[6*i+j]*F[j];
    }
    double detJ = fabs(dxdu*dydv-dxdv*dydu);
    double exact = f(x,y);
    double diff = exact - interpolated;
    e2 += weights[i] * diff * diff * detJ;
  }
  return e2;
}


int main2(double eps, double &Error, int METR = 0)
{
  
  double modelSize = CASE_ == 0 ? 100 : 2;
  if (CASE_ == 3)modelSize =4;
  if (CASE_ == -1)modelSize =1;
  int tag;
  // create a square and mesh it
  if(CASE_ > 0)  {
    gmsh::clear();
    gmsh::model::add("rect");
    gmsh::model::setCurrent("rect");
  }

  if ( CASE_ == -4) {
    modelSize =1;
    tag = gmsh::model::occ::addRectangle(0, 0, 0, modelSize, modelSize, 1);    
    gmsh::model::occ::synchronize();
    gmsh::option::setNumber("Mesh.MeshSizeMin", modelSize/100);
    gmsh::option::setNumber("Mesh.MeshSizeMax", modelSize/100);
    gmsh::model::mesh::generate();
  }
  else if ( CASE_ == -2) {
    tag = 1;
    gmsh::model::setCurrent("rect");
    gmsh::merge("step1.msh");
    modelSize =50;
  }
  else if ( CASE_ == -3) {
    tag = 1;
    gmsh::model::setCurrent("rect");
    gmsh::merge("cyl1.msh");
    modelSize =3;
  }
  else{
    tag = gmsh::model::occ::addRectangle(-modelSize/2, -modelSize/2, 0, modelSize, modelSize, 1);
    
    gmsh::model::occ::synchronize();
    gmsh::option::setNumber("Mesh.MeshSizeMin", modelSize/100);
    gmsh::option::setNumber("Mesh.MeshSizeMax", modelSize/100);
    gmsh::model::mesh::generate();
  }
  const double lMin = modelSize /1000;
  const double lMax = modelSize /6;
  
  // get the nodes
  std::vector<std::size_t> nodeTags;
  std::vector<double> coord;
  std::vector<double> parametricCoord;
  gmsh::model::mesh::getNodes(nodeTags,coord, parametricCoord, -1, tag, true, false);

  // add a view with metric tensor (for mmg)
  int viewTag  = gmsh::view::add (":metricP2_straight");
  int viewTagF = gmsh::view::add ("F");
  std::vector<std::vector<double> > data;
  std::vector<std::vector<double> > dataF;
  
  // compute metric @ nodes

  double g00,g01,g11;


  FILE *F = fopen("metric.pos", "w");
  fprintf(F,"View \" \"{\n");

  std::map<size_t, double> COS;
  std::map<size_t, double> SIN;

  for (size_t i=0 ; i < nodeTags.size() ; i++){
    const double x = coord [3*i + 0];
    const double y = coord [3*i + 1];

    double C, S;
    if (METR == 0)
      computeMetricP2 (x, y, lMin, lMax, eps, g00, g01, g11, F, C, S);
    else if (METR == 1)
      computeMetricP2Hess (x, y, lMin, lMax, eps, g00, g01, g11, F, C, S);
    else if (METR == 2)
      computeMetricP2Grad (x, y, lMin, lMax, eps, g00, g01, g11, F, C, S);
    else if (METR == 3)
      computeMetricDMax (x, y, lMin, lMax, eps, g00, g01, g11, C, S);

    COS[nodeTags[i]]=C;
    SIN[nodeTags[i]]=S;

    //    printf("%lu %12.5E %12.5E = %12.5E %12.5E\n",i,x,y,C,S);

  }

  smoothDirections( COS, SIN );
    
  for (size_t i=0 ; i < nodeTags.size() ; i++){

    const double x = coord [3*i + 0];
    const double y = coord [3*i + 1];

    double C = COS[nodeTags[i]];
    double S =SIN[nodeTags[i]];

    fprintf(F,"VP(%g,%g,%g){%g,%g,%g};\n",x,y,0.,C,S,0.);
    fprintf(F,"VP(%g,%g,%g){%g,%g,%g};\n",x,y,0.,-S,C,0.);
        
    const double dttt0_  = fabs(dttt (x,y, C, S));
    const double dttt1_  = fabs(dttt (x,y, -S, C));

    double l0 = dttt0_ != 0. ? pow (6*eps/dttt0_,0.3333) : lMax;
    double l1 = dttt1_ != 0. ? pow (6*eps/dttt1_,0.3333) : lMax;
    
    l0 = std::min (l0,lMax);
    l0 = std::max (l0,lMin);
    l1 = std::min (l1,lMax);
    l1 = std::max (l1,lMin);
    
    double h0 = 1./(l0*l0);
    double h1 = 1./(l1*l1);
    
    double g00 = C*C*h0+S*S*h1;
    double g11 = S*S*h0+C*C*h1;
    double g01 = S*C*(h1-h0);  
        
    std::vector<double> v(9);
    std::vector<double> vF(1);

    v[0] = g00;
    v[1] = -g01;
    v[2] = 0;
    
    v[3] = -g01;
    v[4] = g11;
    v[5] = 0;
    
    v[6] = 0;
    v[7] = 0;
    v[8] = f(x,y);// export f as well.
    vF[0] = f(x,y);
    data.push_back(v);    
    dataF.push_back(vF);    
  }
  fprintf(F,"};\n");
  fclose(F);

  gmsh::view::addModelData(viewTag, 0, "rect", "NodeData",
			   nodeTags, data);
  gmsh::view::addModelData(viewTagF, 0, "rect", "NodeData",
			   nodeTags, dataF);

  printf("dataf.size = %lu\n",dataF.size());
  
  gmsh::option::setNumber("Mesh.MshFileVersion",2.2);

  //  gmsh::write("metric.msh");
  gmsh::view::write(viewTagF,"sol.msh");
  gmsh::view::write(viewTag,"metric.msh");
  //  gmsh::view::write(viewTagF,"metric.msh",true);

  
  system ("/Users/CODES/bin/mmg2d_O3 -hgrad 3 metric.msh");

  
  gmsh::option::setNumber("Mesh.MshFileVersion",4);
  gmsh::model::add("rect_adapt");
  gmsh::model::setCurrent("rect_adapt");
  gmsh::merge("metric.o.msh");

  int computePointsUsingScaledCrossFieldPlanarP2 (const char *modelForMetric,
						  const char *modelForMesh,
						  int VIEW_TAG,
						  int faceTag, std::vector<double> &pts,
						  double er (double *, double *, double *,
							     double *, double *, double *),
						  bool inside(double *));

  bool vazy = true;//false;
  
  std::vector<double> pts;
  if (vazy)computePointsUsingScaledCrossFieldPlanarP2 ("rect", "rect_adapt", viewTag, 0,pts, (CASE_ <= -2) ?ERROR_SQUARED_P2:NULL, INSIDE);
  gmsh::model::setCurrent("rect_adapt");

  if (!vazy)gmsh::model::mesh::setOrder(2);
  gmsh::model::mesh::getNodes(nodeTags,coord, parametricCoord,-1,-1,true);
  
  int viewTagF_adapt = gmsh::view::add ("F_adapt");
  std::vector<std::vector<double> > dataF_adapt;

  for (size_t i=0 ; i < nodeTags.size() ; i++){
    const double x = coord [3*i + 0];
    const double y = coord [3*i + 1];
    std::vector<double> vF(1);
    vF[0] = f(x,y);
    dataF_adapt.push_back(vF);    
  }
  gmsh::model::setCurrent("rect_adapt");
  gmsh::view::addModelData(viewTagF_adapt, 0, "rect_adapt", "NodeData",
			   nodeTags, dataF_adapt);
  gmsh::view::write(viewTagF_adapt,"sol_adapt.msh");

  std::vector<int>  elementTypes ; 

  gmsh::model::setCurrent("rect_adapt");
  
  {
    FILE *ERR = fopen ("ERROR.pos","w");
    fprintf(ERR,"View\"ERROR\"{\n");
    int triangleP2 = gmsh::model::mesh::getElementType("Triangle", 2);
    std::vector<double> localCoord;
    std::vector<double> weights;
    gmsh::model::mesh::getIntegrationPoints(triangleP2, "Gauss12",localCoord, weights);
    std::vector<double> basisFunctions;
    int numComponents, numOrientations;
    gmsh::model::mesh::getBasisFunctions(triangleP2, localCoord, "Lagrange",
					 numComponents,basisFunctions,numOrientations);
    std::vector<int> elementTypes;
    std::vector<std::vector<std::size_t> > elementTags;
    std::vector<std::vector<std::size_t> > nodeTags;
    gmsh::model::mesh::getElements ( elementTypes,elementTags, nodeTags, 2); 
    double Error = 0.0;
    int dim, tag;
    for (size_t e=0; e<elementTags[0].size();e++){
      std::vector<double> xa, xb, xc, xab, xbc, xca, pc;
      gmsh::model::mesh::getNode( nodeTags[0][6*e+0], xa, pc,dim,tag);
      gmsh::model::mesh::getNode( nodeTags[0][6*e+1], xb, pc,dim,tag);
      gmsh::model::mesh::getNode( nodeTags[0][6*e+2], xc, pc,dim,tag);
      gmsh::model::mesh::getNode( nodeTags[0][6*e+3], xab, pc,dim,tag);
      gmsh::model::mesh::getNode( nodeTags[0][6*e+4], xbc, pc,dim,tag);
      gmsh::model::mesh::getNode( nodeTags[0][6*e+5], xca, pc,dim,tag);      
      double ErrorElement = ERROR_SQUARED_P2 (&xa[0],&xb[0],&xc[0],&xab[0],&xbc[0],&xca[0]);
      fprintf(ERR,"ST2(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g};\n",
	      xa[0],xa[1],0.0,xb[0],xb[1],0.0,xc[0],xc[1],0.0,
	      xab[0],xab[1],0.0,xbc[0],xbc[1],0.0,xca[0],xca[1],0.0,
	      ErrorElement,ErrorElement,ErrorElement,ErrorElement,ErrorElement,ErrorElement);
      Error+=ErrorElement;
    }
    fprintf(ERR,"};\n");
    fclose(ERR);
    printf("Error = %12.5E\n",sqrt(Error));
  }
  return 1;//determinants.size()/weights.size();
}

void readSimulationData (const char* fn){
  gmsh::open(fn);
  //  std::vector<int> tags;
  //  gmsh::view::getTags(tags);
  //  printf("%lu views\n",tags.size());
  //  for (size_t i=0;i<tags.size();i++)printf("%lu %d\n",i,tags[i]);
}


/* Compute metric using a brute-force method to solve optimization problem
   Original code from R. Kuate */
void metricHechtKuate(int nbpoints,
		      double *x, double *y,
		      double &A, double &B, double &C,
                      double epsilon,
		      double *xNew, double *yNew) {
  C = 0.0;

  int bool_assert = 1;

  double epsilon0 = 1e-5, precision = 1e-18, delta = 1e-10;
  double inf = 1e100;

  double Rmin = 1e20, Rmax = 0;

  int indiceX0 = 0;

  // double* xNew = new double[nbpoints];
  // double* yNew = new double[nbpoints];
  // double *PPoint = new double[nbpoints];

  for(int i = 0; i < nbpoints; i++) {
    Rmax = fmax(Rmax, sqrt(x[i] * x[i] + y[i] * y[i]));

    //---déplacement des points situées sur les axes--------------
    if(abs(x[i]) <= precision) {
      if(y[i] < 0) {
        x[i] = -delta;
        y[i] = -sqrt(pow(y[i], 2) - pow(x[i], 2));
      }
      if(y[i] > 0) {
        x[i] = delta;
        y[i] = sqrt(pow(y[i], 2) - pow(x[i], 2));
      }
    }

    if(abs(y[i]) <= precision) {
      if(x[i] < 0) {
        y[i] = -delta;
        x[i] = -sqrt(pow(x[i], 2) - pow(y[i], 2));
      }
      if(x[i] > 0) {
        y[i] = delta;
        x[i] = sqrt(pow(x[i], 2) - pow(y[i], 2));
      }
    }
    //-----------------------------------------------------------
    if(bool_assert) {
      // std::cout<<"foo : "<<abs(x[i]*y[i])<<std::endl;
      // std::cout<<"foo : "<<pow(precision,2)<<std::endl;
      assert(abs(x[i] * y[i]) >= pow(precision, 2));
    }

    if(Rmin > sqrt(x[i] * x[i] + y[i] * y[i])) {
      indiceX0 = i;
      Rmin = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
  }

  //-------permutation des indices de la liste des points :
  // ranger la liste en commençant par le point X0-------
  for(int k = 0; k < nbpoints - indiceX0; k++) {
    xNew[k] = x[k + indiceX0];
    yNew[k] = y[k + indiceX0];
  }
  for(int k = nbpoints - indiceX0; k < nbpoints; k++) {
    xNew[k] = x[k - nbpoints + indiceX0];
    yNew[k] = y[k - nbpoints + indiceX0];
  }
  for(int i = 0; i < nbpoints; i++) {
    x[i] = xNew[i];
    y[i] = yNew[i];
  }

  //----------------------------------------------------------------

  int test = -1;

  double X0, Y0;
  double bmin = 0., bmax = inf, b1, b2, aik = 0., bik = 0., cik = 0.;
  double Xk = 0., Yk = 0., Ck = 0., Bk = 0., Xi = 0., Yi = 0., ri, detXY = 0., Ri, R0, r0;

  X0 = x[0];
  Y0 = y[0];
  r0 = sqrt(x[0] * x[0] + y[0] * y[0]);
  if(bool_assert) {
    // std::cout<<"Assert ON"<<std::endl;
    assert(r0 == Rmin);
  }

  // std::cout<<" Rmin = "<<Rmin<<" Rmax =  "<<Rmax<<std::endl;

  double EPS = 0.0; // pour recuperer la valeur de epsilon0 optimale

  int condition = -1;

  if(r0 <= epsilon0) epsilon0 = r0 * epsilon0;

  A = 1. / ((r0 - epsilon0) * (r0 - epsilon0));
  B = A;

  double epsilon0min = epsilon0;

  // if(abs(Rmin-Rmax) > 1e-5){
  if(abs(Rmin - Rmax) > precision) {
    // for(int ee=0; ee<neps-1; ee++){ //boucle sur epsilon0---------------
    // epsilon0= Tabepsilon[ee];
    if(r0 <= epsilon0) epsilon0 = r0 * epsilon0;
    if(bool_assert) { assert(r0 > epsilon0); }
    R0 = r0 / (r0 - epsilon0);

    for(int i = 1; i < nbpoints; i++) { // boucle sur chaque noeud
      Xi = x[i];
      Yi = y[i];
      ri = sqrt(x[i] * x[i] + y[i] * y[i]);

      if(ri <= epsilon) epsilon = ri * epsilon;

      if(bool_assert) { assert(ri > epsilon); }

      Ri = ri / (ri - epsilon);

      detXY = Xi * Y0 - Yi * X0;

      //------deplacement des points alignés avec l'origine et X0-----------
      if(abs(detXY) <= precision) {
        printf("Point %d - \t x = %10.15f - \t y =%10.15f - \t x0 = %10.15f - \t y0 =%10.15f - \t "
               "detXY = %10.15f \n",
               i, x[i], y[i], X0, Y0, detXY);
        Xi += delta;

        if(Yi < 0)
          Yi = -sqrt(pow(ri, 2) - pow(Xi, 2));
        else
          Yi = sqrt(pow(ri, 2) - pow(Xi, 2));
        x[i] = Xi;
        y[i] = Yi;

        std::cout << ri << std::endl;
        ri = sqrt(x[i] * x[i] + y[i] * y[i]);

        if(ri <= epsilon) epsilon = ri * epsilon;

        std::cout << "xi =" << x[i] << " yi =" << y[i] << " ri = " << ri << " epsilon = " << epsilon
                  << std::endl;
        if(bool_assert) { assert(ri > epsilon); }
        Ri = ri / (ri - epsilon);
      }

      detXY = Xi * Y0 - Yi * X0;

      if(bool_assert) { assert(abs(detXY) >= precision); }

      //-----racines du polynome en b à minimiser----------------------------
      double bb1 =
        (1. / pow(detXY, 2)) *
        (pow(X0 * Ri, 2) + pow(Xi * R0, 2) -
         2. * abs(Xi * X0) * sqrt(pow(R0 * Ri, 2) - pow(detXY / (Rmax * (r0 - epsilon0)), 2)));
      double bb2 =
        (1. / pow(detXY, 2)) *
        (pow(X0 * Ri, 2) + pow(Xi * R0, 2) +
         2. * abs(Xi * X0) * sqrt(pow(R0 * Ri, 2) - pow(detXY / (Rmax * (r0 - epsilon0)), 2)));
      //--fin----racines du polynome en b à minimiser--------------------

      bmax = fmin(bb2, pow(Rmax / pow((r0), 2), 2));
      bmin = fmax(1. / (Rmax * Rmax), bb1); // minoration de b
      double Cte = fmax(1e-9, (bmax - bmin) * 1e-9);
      bmin = bmin * (1. + Cte);
      bmax = bmax * (1. - Cte);

      // bornes de b-----------------------------------------------------------

      // cas:  majoration de c --------------------------------------------
      double Li = X0 * Xi * (pow(Rmax / pow(r0 - epsilon0min, 2), 2) - 1. / pow(Rmax, 2)) +
                  (pow(Ri * X0, 2) - pow(R0 * Xi, 2)) / detXY;
      double LiXY = Xi * Y0 + Yi * X0;

      if(abs(LiXY) >= precision) {
        condition = 1;

        if(Xi * X0 > 0) {
          if(LiXY > 0)
            bmin = fmax(bmin, -Li / LiXY);
          else
            bmax = fmin(bmax, -Li / LiXY);
        } else {
          if(LiXY < 0)
            bmin = fmax(bmin, -Li / LiXY);
          else
            bmax = fmin(bmax, -Li / LiXY);
        }
      } else {
        if(Li < 0)
          condition = 0;
        else
          condition = 1;
      }

      // cas  minoration de c --------------------------------------------
      Li = X0 * Xi * (-pow(Rmax / pow(r0 - epsilon0min, 2), 2) + 1. / pow(Rmax, 2)) +
           (pow(Ri * X0, 2) - pow(R0 * Xi, 2)) / detXY;
      LiXY = Xi * Y0 + Yi * X0;

      if(abs(LiXY) >= precision) {
        condition = 1;
        if(Xi * X0 > 0) {
          if(LiXY < 0)
            bmin = fmax(bmin, -Li / LiXY);
          else
            bmax = fmin(bmax, -Li / LiXY);
        } else {
          if(LiXY > 0)
            bmin = fmax(bmin, -Li / LiXY);
          else
            bmax = fmin(bmax, -Li / LiXY);
        }
      } else {
        if(Li > 0)
          condition = 0;
        else
          condition = 1;
      }

      if(condition) {
        //--cas : minoration de a-----------------------------------------------

        double Gi =
          ((Xi * Yi * R0 * R0 - X0 * Y0 * Ri * Ri) / detXY + Xi * X0 / (Rmax * Rmax)) / (Yi * Y0);

        if(Xi * X0 > 0) {
          if(Yi * Y0 > 0)
            bmin = fmax(bmin, Gi);
          else
            bmax = fmin(bmax, Gi);
        } else {
          if(Yi * Y0 < 0)
            bmin = fmax(bmin, Gi);
          else
            bmax = fmin(bmax, Gi);
        }

        // cas :majoration de a------------------------------------------------
        double Hi = (Xi * X0 * Rmax * Rmax / pow((r0 - epsilon0min), 4) +
                     (Xi * Yi * R0 * R0 - X0 * Y0 * Ri * Ri) / detXY) /
                    (Yi * Y0);
        if(Xi * X0 > 0) {
          if(Yi * Y0 > 0)
            bmax = fmin(bmax, Hi);
          else
            bmin = fmax(bmin, Hi);
        } else {
          if(Yi * Y0 < 0)
            bmax = fmin(bmax, Hi);
          else
            bmin = fmax(bmin, Hi);
        }
        //------fin bornes de b------------------------------------------------
        b2 = bmax;
        b1 = bmin;

        for(int k = 1; k < nbpoints; k++) { // on balaye les contraintes
          Xk = x[k];
          Yk = y[k];
          Bk = (Yk * Yk * Xi * X0 + Xk * (Xk * Yi * Y0 - Yk * (Yi * X0 + Xi * Y0))) / (Xi * X0);
          Ck = (X0 * Xi * detXY -
                Xk * (Xi * R0 * R0 * (Yk * Xi - Yi * Xk) + X0 * Ri * Ri * (-Yk * X0 + Y0 * Xk))) /
               (Xi * X0 * detXY);

          if(bool_assert) { assert(abs(Xi * X0 * Y0 * Yi * Xk * Yk) >= pow(precision, 5)); }
          if(abs(Bk) > precision) { // non nul

            if(Bk <= 0)
              bmax = fmin(bmax, Ck / Bk);
            else
              bmin = fmax(bmin, Ck / Bk);

            if((bmax < b1) || (bmin > b2) || (bmin > bmax)) {
              test = 0;
              break;
            }

            else
              test = 1;
          } else {
            if(Ck > precision) {
              test = 0;
              break;
            } else // Ck<=0
              test = -1; // 1 peut etre
          }
        }

        if(test) {
          double a0 = -pow((detXY / (Xi * X0)), 2);
          double a1 = 2. * (pow(Ri / Xi, 2) + pow(R0 / X0, 2));
          if(((a0 * bmax + a1) * bmax) < ((a0 * bmin + a1) * bmin))
            bik = bmax;
          else
            bik = bmin;

          aik = (Ri * Ri * Y0 * X0 - R0 * R0 * Yi * Xi + bik * Yi * Y0 * detXY) / (detXY * Xi * X0);
          cik = (-Ri * Ri * X0 * X0 + R0 * R0 * Xi * Xi - bik * (Yi * X0 + Y0 * Xi) * detXY) /
                (detXY * Xi * X0);

          if(bool_assert) {
            assert((4. * aik * bik - cik * cik) >= 0.); // aire positive
            assert(abs((4. * aik * bik - cik * cik) - pow(2. / (Rmax * (r0 - epsilon0)), 2)) >
                   0); // aire positive
          }
          if((4. * aik * bik - cik * cik) <= (4. * A * B - C * C)) {
            A = aik;
            B = bik;
            C = cik;
            EPS = epsilon0;
          }
        } // if(test)
      } // if(condition)
    } // for(int i=1;i<nbpoints;i++)
    // } // for(int ee=0; ee<neps-1; ee++)
  } // if(abs(Rmin-Rmax)>1e-5)
  else {
    A = 1. / (Rmin * Rmin);
    B = A;
    C = 0.;
  }
}


int main(int argc, char **argv)
{
  gmsh::initialize();
  CASE_ = atoi(argv[1]);
  int METR = atoi(argv[2]);

  if (argc == 5){
    //   CASE_ = -1;
    readSimulationData (argv[3]);
    gmsh::model::getCurrent(nameModel);
    //    std::cout << nameModel << std::endl;

    //    std::vector<double> uxx(1);
    //    PROBE(8,0,0,0.0,uxx,0,1);

    double err;
    gmsh::model::add("rect");
    gmsh::model::setCurrent("rect");


    int nelem = main2(atof(argv[4]),err,METR);
    gmsh::model::setCurrent("rect_adapt");
    return 0;
  }
  
  
  FILE *f;
  switch(METR){
  default : f = fopen ("conv0.txt","w"); break;
  case 1 :  f = fopen ("conv1.txt","w"); break;
  case 2 :  f = fopen ("conv2.txt","w"); break;
  case 3 :  f = fopen ("conv3.txt","w"); break;
  }
  double eps = .1;
  for (int i=0;i< 8; i++){
    double err;
    int nelem = main2(eps,err,METR);
    fprintf(f,"%d %12.5E\n",nelem,err);
    eps/= 2.0;
  }
  fclose(f);
  return 0;
}

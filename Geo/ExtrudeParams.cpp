// $Id: ExtrudeParams.cpp,v 1.5 2001-08-14 16:25:11 geuzaine Exp $

#include "Gmsh.h"
#include "Geo.h"
#include "CAD.h"
#include "ExtrudeParams.h"

void Projette (double p[3],double mat[3][3]) {
  double X, Y, Z ;

  X = p[0] * mat[0][0] + p[1] * mat[0][1] + p[2] * mat[0][2];
  Y = p[0] * mat[1][0] + p[1] * mat[1][1] + p[2] * mat[1][2];
  Z = p[0] * mat[2][0] + p[1] * mat[2][1] + p[2] * mat[2][2];
  p[0] = X;
  p[1] = Y;
  p[2] = Z;
}

ExtrudeParams :: ExtrudeParams (int ModeEx){
  mesh.ExtrudeMesh = false;
  geo.Mode = ModeEx;
  mesh.Recombine = false;
}


void ExtrudeParams :: fill (int ep , double A, double B, double C,
                            double X, double Y, double Z, double angle){
  geo.axe[0] = A;
  geo.axe[1] = B;
  geo.axe[2] = C;
  geo.pt[0] = X;
  geo.pt[1] = Y;
  geo.pt[2] = Z;
  geo.angle = angle;
  geo.Type = ep;
}

void ExtrudeParams :: Extrude ( int iLayer, int iElemLayer,
                                double &x, double &y, double &z){

  double dx0,dy0,dz0,dx1,dy1,dz1;
  double dx,dy,dz;
  if(!iLayer){
    dx0=dy0=dz0=0.0;
    dx1 = mesh.hLayer[0];
    dy1 = mesh.hLayer[0];
    dz1 = mesh.hLayer[0];
  }
  else{
    dx0 = mesh.hLayer[iLayer-1];
    dy0 = mesh.hLayer[iLayer-1];
    dz0 = mesh.hLayer[iLayer-1];
    dx1 = mesh.hLayer[iLayer];
    dy1 = mesh.hLayer[iLayer];
    dz1 = mesh.hLayer[iLayer];
  }
  double t = (double) iElemLayer /(double)mesh.NbElmLayer[iLayer];
  if(geo.Type){
    dx = geo.axe[0]*(dx0 + t * (dx1-dx0));
    dy = geo.axe[1]*(dy0 + t * (dy1-dy0));
    dz = geo.axe[2]*(dz0 + t * (dz1-dz0));
    x+=dx;y+=dy;z+=dz;
  }
  else{
    double angle = geo.angle;
    geo.angle = geo.angle*(dx0 + t * (dx1-dx0));
    ProtudeXYZ(x,y,z,this);
    geo.angle = angle;
  }
}

void ExtrudeParams :: Rotate(double matr[3][3]){
  Projette(geo.axe,matr);
  Projette(geo.pt,matr);
  geo.angle = -geo.angle;
}

void ExtrudeParams :: Extrude (double t, double &x, double &y, double &z){

  double dx,dy,dz;
  if(geo.Type){
    dx = geo.axe[0]*t;
    dy = geo.axe[1]*t;
    dz = geo.axe[2]*t;
    x+=dx;y+=dy;z+=dz;
  }
  else{
    double angle = geo.angle;
    geo.angle = geo.angle*t;
    ProtudeXYZ(x,y,z,this);
    geo.angle = angle;
  }
}


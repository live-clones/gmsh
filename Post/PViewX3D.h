// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// PViewX3D is a extension for Post-processing outputs :
// creates a file in X3D format with the same features as
// what is visible in post-processing screen.
// contact : gilles.marckmann@ec-nantes.fr

#ifndef _PVIEWX3D_H_
#define _PVIEWX3D_H_

#include <iostream>

using namespace std;

static inline void UnsignedChar2rgba(unsigned char *glc,double*rgba){
  rgba[0]=glc[0]/255.; 
  rgba[1]=glc[1]/255.; 
  rgba[2]=glc[2]/255.;
  rgba[3]=glc[3]/255.;
}

static inline void unsignedInt2RGBA(unsigned int &color,double &r,double &g, double &b,double &a)
{
  r =  color & 255; 
  g = (color >> 8) & 255; 
  b = (color >> 16) & 255; 
  a = (color >> 24) & 255; 
  r =r /255.;
  g =g /255.;
  b =b /255.;
  a =a /255.;
  // cout<< "couleur="<<color<<" / decomposition: "<<" r="<<r<<", g="<<g<<", b="<<b<<", a="<<a<<endl;
  return;
}

static void writeX3DScale(FILE *fp, PView *p, double xmin, double ymin, double width, double height, double tic, int horizontal,double ratio);
static void writeX3DScaleBar(FILE *fp, PView *p, double xmin, double ymin, double width, double height, double tic, int horizontal);
static void writeX3DScaleValues(FILE *fp, PView *p, double xmin, double ymin, double width, double height, double tic, int horizontal,double ratio);
static void writeX3DScaleLabel (FILE *fp, PView *p, double xmin, double ymin, double width, double height, double tic, int horizontal,double ratio);
static void writeX3DStringCenter( FILE *fp,char *label,double x, double y, double z,double font_size); 
 

#endif


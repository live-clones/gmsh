// $Id: StreamLines.cpp,v 1.5 2004-04-24 05:22:50 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "OctreePost.h"
#include "StreamLines.h"
#include "List.h"
#include "Context.h"
#include "Views.h"
#include "Message.h"

extern Context_T CTX;

StringXNumber StreamLinesOptions_Number[] = {
  {GMSH_FULLRC, "X0", NULL, 2.39},
  {GMSH_FULLRC, "Y0", NULL, .445},
  {GMSH_FULLRC, "Z0", NULL, 0.},
  {GMSH_FULLRC, "X1", NULL, 2.39},
  {GMSH_FULLRC, "Y1", NULL, 0.94},
  {GMSH_FULLRC, "Z1", NULL, 0.},
  {GMSH_FULLRC, "X2", NULL, 2.39},
  {GMSH_FULLRC, "Y2", NULL, .445},
  {GMSH_FULLRC, "Z2", NULL, 1.},
  {GMSH_FULLRC, "nPointsU", NULL, 20},
  {GMSH_FULLRC, "nPointsV", NULL, 1},
  {GMSH_FULLRC, "MaxIter", NULL, 100},
  {GMSH_FULLRC, "DT", NULL, .1},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStreamLinesPlugin()
  {
    return new GMSH_StreamLinesPlugin();
  }
}


GMSH_StreamLinesPlugin::GMSH_StreamLinesPlugin()
{
  ;
}

void GMSH_StreamLinesPlugin::getName(char *name) const
{
  strcpy(name, "Stream lines");
}

void GMSH_StreamLinesPlugin::getInfos(char *author, char *copyright,
				      char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
	 "Plugin(StreamLines) computes stream lines\n"
	 "from a vector view `iView'. It takes as input a\n"
	 "grid defined by the 3 points (`X0',`Y0',`Z0')\n"
	 "(origin), (`X1',`Y1',`Z1') (axis of U) and\n"
	 "(`X2',`Y2',`Z2') (axis of V). The number of points\n"
	 "that are going to be transported along U and V is\n"
	 "set with the options `nPointsU' and `nPointsV'.\n"
	 "Then, we solve the equation DX(t)/dt = V(x,y,z)\n"
	 "with X(t=0) chosen as the grid and V(x,y,z)\n"
	 "interpolated on the vector view. The timestep and\n"
	 "the maximum number of iterations are set with\n"
	 "the options `MaxIter' and `DT'. The time stepping\n"
	 "scheme is a RK44. If `iView' < 0, the plugin is run\n"
	 "on the current view.\n"
	 "\n"
	 "Plugin(StreamLines) creates one new view. It is\n"
	 "nice to choose the displacement mode to see\n"
	 "vectors and to animate the view ;-)\n");
}

int GMSH_StreamLinesPlugin::getNbOptions() const
{
  return sizeof(StreamLinesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_StreamLinesPlugin::getOption(int iopt)
{
  return &StreamLinesOptions_Number[iopt];
}

void GMSH_StreamLinesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "StreamLines failed...");
}

int GMSH_StreamLinesPlugin::getNbU()const 
{
  return   (int)StreamLinesOptions_Number[9].def;
}

int GMSH_StreamLinesPlugin::getNbV()const 
{
  return   (int)StreamLinesOptions_Number[10].def;
}

void GMSH_StreamLinesPlugin::getPoint(int iU, int iV, double *X) const 
{
  double u = (double)iU / (double)(getNbU ());
  double v = (double)iV / (double)(getNbV ());
  X[0] = StreamLinesOptions_Number[0].def + 
    u  * (StreamLinesOptions_Number[3].def-StreamLinesOptions_Number[0].def) +
    v  * (StreamLinesOptions_Number[6].def-StreamLinesOptions_Number[0].def) ;
  X[1] = StreamLinesOptions_Number[1].def + 
    u  * (StreamLinesOptions_Number[4].def-StreamLinesOptions_Number[1].def) +
    v  * (StreamLinesOptions_Number[7].def-StreamLinesOptions_Number[1].def) ;
  X[2] = StreamLinesOptions_Number[2].def + 
    u  * (StreamLinesOptions_Number[5].def-StreamLinesOptions_Number[2].def) +
    v  * (StreamLinesOptions_Number[8].def-StreamLinesOptions_Number[2].def) ;
}

Post_View * GMSH_StreamLinesPlugin::GenerateView(Post_View * v) const 
{
  Post_View * View = BeginView(1);

  View->NbTimeStep = (int) StreamLinesOptions_Number[11].def;

  double XINIT[3];
  double X[3],DX[3];
  double X1[3];
  double X2[3];
  double X3[3];
  double X4[3];
  double VALUES [24];
  const double b1=1./3.,b2=2./3.,b3=1./3.,b4=1./6.,a1=0.5,a2=0.5,a3=1.0,a4=1.0;
  OctreePost o(v);

  const double DT = StreamLinesOptions_Number[12].def;
  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      getPoint(i, j, XINIT);
      getPoint(i, j, X);
	  
      int ITER = 0;
      
      View->NbVP++;
      
      List_Add(View->VP, &X[0]);
      List_Add(View->VP, &X[1]);
      List_Add(View->VP, &X[2]);	      
      
      while (ITER++ < (int) StreamLinesOptions_Number[11].def){
	// dX/dt = V
	// X1 = X + a1 * DT * V(X)
	// X2 = X + a2 * DT * V(X1)
	// X3 = X + a3 * DT * V(X2)
	// X4 = X + a4 * DT * V(X3)
	// X = X + b1 X1 + b2 X2 + b3 X3 + b4 x4
	double sizeElem = 0.033;
	o.searchVector(X[0], X[1], X[2], VALUES, &sizeElem, 0);
	// sizeElem = 0.1;
	//double normV = sqrt(VALUES[0]*VALUES[0]+
	//		      VALUES[1]*VALUES[1]+
	//		      VALUES[2]*VALUES[2]);	     
	// if (normV==0.0) normV = 1.0;
	// double DT = sizeElem / normV ; /// CFL = 1 ==> secure 
	for(int k = 0; k < 3; k++) X1[k] = X[k] + DT * VALUES[k] * a1;
	o.searchVector(X1[0], X1[1], X1[2], VALUES, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X2[k] = X[k] + DT * VALUES[k] * a2;
	o.searchVector(X2[0], X2[1], X2[2], VALUES, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X3[k] = X[k] + DT * VALUES[k] * a3;
	o.searchVector(X3[0], X3[1], X3[2], VALUES, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X4[k] = X[k] + DT * VALUES[k] * a4;
	for(int k = 0; k < 3; k++) X[k] += (b1*(X1[k]-X[k]) + b2*(X2[k]-X[k]) + 
					    b3*(X3[k]-X[k]) + b4*(X4[k]-X[k])) ;
	for(int k = 0; k < 3; k++) DX[k] = X[k] - XINIT[k];
	List_Add(View->VP, &DX[0]);
	List_Add(View->VP, &DX[1]);
	List_Add(View->VP, &DX[2]);	      
      }
    }
  }

  char name[1024], filename[1024];
  sprintf(name, "%s_StreamLines", v->Name);
  sprintf(filename, "%s_StreamLines", v->FileName);
  EndView(View, 1, filename, name);

  return View;
}

Post_View *GMSH_StreamLinesPlugin::execute(Post_View * v)
{
  Post_View *vv;

  int iView = (int)StreamLinesOptions_Number[13].def;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      return 0;
    }
  }
  
  Post_View *newView = GenerateView(vv);
  
  return newView;
}

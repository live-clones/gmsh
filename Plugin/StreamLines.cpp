// $Id: StreamLines.cpp,v 1.14 2004-12-27 09:17:44 geuzaine Exp $
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

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

StringXNumber StreamLinesOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_StreamLinesPlugin::callbackX0, 2.39},
  {GMSH_FULLRC, "Y0", GMSH_StreamLinesPlugin::callbackY0, .445},
  {GMSH_FULLRC, "Z0", GMSH_StreamLinesPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_StreamLinesPlugin::callbackX1, 2.39},
  {GMSH_FULLRC, "Y1", GMSH_StreamLinesPlugin::callbackY1, 0.94},
  {GMSH_FULLRC, "Z1", GMSH_StreamLinesPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_StreamLinesPlugin::callbackX2, 2.39},
  {GMSH_FULLRC, "Y2", GMSH_StreamLinesPlugin::callbackY2, .445},
  {GMSH_FULLRC, "Z2", GMSH_StreamLinesPlugin::callbackZ2, 1.},
  {GMSH_FULLRC, "nPointsU", GMSH_StreamLinesPlugin::callbackU, 20},
  {GMSH_FULLRC, "nPointsV", GMSH_StreamLinesPlugin::callbackV, 1},
  {GMSH_FULLRC, "MaxIter", NULL, 100},
  {GMSH_FULLRC, "DT", NULL, .1},
  {GMSH_FULLRC, "dView", NULL, -1.},
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

void GMSH_StreamLinesPlugin::draw()
{
#if defined(HAVE_FLTK)
  glColor4ubv((GLubyte *) & CTX.color.fg);
  double p[3];
  glBegin(GL_LINES);
  for(int i = 0; i < getNbU(); ++i){
    getPoint(i, 0, p);
    glVertex3d(p[0], p[1], p[2]);
    getPoint(i, getNbV()-1, p);
    glVertex3d(p[0], p[1], p[2]);
  }
  for(int i = 0; i < getNbV(); ++i){
    getPoint(0, i, p);
    glVertex3d(p[0], p[1], p[2]);
    getPoint(getNbU()-1, i, p);
    glVertex3d(p[0], p[1], p[2]);
  }
  glEnd();
#endif
}

void GMSH_StreamLinesPlugin::callback()
{
#if defined(HAVE_FLTK)
  CTX.post.plugin_draw_function = draw;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  if(!CTX.batch) 
    Draw();
  CTX.post.plugin_draw_function = NULL;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
#endif
}

double GMSH_StreamLinesPlugin::callbackXYZ(int num, int action, double value, double *opt)
{
  switch(action){ // configure the input field
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  *opt = value;
  callback();
  return 0.;
}

double GMSH_StreamLinesPlugin::callbackX0(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[0].def);
}

double GMSH_StreamLinesPlugin::callbackY0(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[1].def);
}

double GMSH_StreamLinesPlugin::callbackZ0(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[2].def);
}

double GMSH_StreamLinesPlugin::callbackX1(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[3].def);
}

double GMSH_StreamLinesPlugin::callbackY1(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[4].def);
}

double GMSH_StreamLinesPlugin::callbackZ1(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[5].def);
}

double GMSH_StreamLinesPlugin::callbackX2(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[6].def);
}

double GMSH_StreamLinesPlugin::callbackY2(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[7].def);
}

double GMSH_StreamLinesPlugin::callbackZ2(int num, int action, double value)
{
  return callbackXYZ(num, action, value, &StreamLinesOptions_Number[8].def);
}

double GMSH_StreamLinesPlugin::callbackU(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1;
  case 2: return 1;
  case 3: return 100;
  default: break;
  }
  StreamLinesOptions_Number[9].def = value;
  callback();
  return 0.;
}

double GMSH_StreamLinesPlugin::callbackV(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return 1;
  case 2: return 1;
  case 3: return 100;
  default: break;
  }
  StreamLinesOptions_Number[10].def = value;
  callback();
  return 0.;
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
	 "from a triangle/tetrahedron vector view `iView'\n"
	 "and optionally interpolates the scalar view `dView'\n"
	 "on the resulting stream lines. It takes as input a\n"
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
	 "Plugin(StreamLines) creates one new view. This\n"
	 "view contains multi-step vector points if `dView'\n"
	 "< 0, or single-step scalar lines if `dView' >= 0.\n");
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

int GMSH_StreamLinesPlugin::getNbU()
{
  return (int)StreamLinesOptions_Number[9].def;
}

int GMSH_StreamLinesPlugin::getNbV()
{
  return (int)StreamLinesOptions_Number[10].def;
}

void GMSH_StreamLinesPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
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

Post_View * GMSH_StreamLinesPlugin::GenerateView(int iView, int dView) const 
{
  const double b1=1./3., b2=2./3., b3=1./3., b4=1./6.;
  const double a1=0.5, a2=0.5, a3=1.0, a4=1.0;
  const double DT = StreamLinesOptions_Number[12].def;
  double XINIT[3], X[3], DX[3], X1[3], X2[3], X3[3], X4[3];
  double sizeElem = 0.033, val[3], *val2 = NULL;

  Post_View *View = BeginView(1);

  Post_View *v1;
  if(List_Pointer_Test(CTX.post.list, iView))
    List_Read(CTX.post.list, iView, &v1);
  else
    v1 = NULL;

  Post_View *v2;
  if(List_Pointer_Test(CTX.post.list, dView))
    List_Read(CTX.post.list, dView, &v2);
  else
    v2 = NULL;

  if(!v1) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return NULL;
  }

  OctreePost o(v1);
  OctreePost *o2 = NULL;

  if(v2){
    val2 = new double[v2->NbTimeStep];
    o2 = new OctreePost(v2);
  }

  for(int i = 0; i < getNbU(); ++i){
    for(int j = 0; j < getNbV(); ++j){
      getPoint(i, j, XINIT);
      getPoint(i, j, X);
	  
      if(v2){
	o2->searchScalar(X[0], X[1], X[2], val2, -1);
      }
      else{
	View->NbVP++;
	List_Add(View->VP, &X[0]);
	List_Add(View->VP, &X[1]);
	List_Add(View->VP, &X[2]);	      
      }

      for(int iter = 0; iter < (int)StreamLinesOptions_Number[11].def; iter++){

	double XPREV[3] = { X[0], X[1], X[2] };

	// dX/dt = V
	// X1 = X + a1 * DT * V(X)
	// X2 = X + a2 * DT * V(X1)
	// X3 = X + a3 * DT * V(X2)
	// X4 = X + a4 * DT * V(X3)
	// X = X + b1 X1 + b2 X2 + b3 X3 + b4 x4

	o.searchVector(X[0], X[1], X[2], val, &sizeElem, 0);
	// double normV = sqrt(val[0]*val[0]+
	//	 	       val[1]*val[1]+
	//		       val[2]*val[2]);	     
	// if (normV==0.0) normV = 1.0;
	// double DT = sizeElem / normV ; /// CFL = 1 ==> secure 
	for(int k = 0; k < 3; k++) X1[k] = X[k] + DT * val[k] * a1;
	o.searchVector(X1[0], X1[1], X1[2], val, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X2[k] = X[k] + DT * val[k] * a2;
	o.searchVector(X2[0], X2[1], X2[2], val, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X3[k] = X[k] + DT * val[k] * a3;
	o.searchVector(X3[0], X3[1], X3[2], val, &sizeElem, 0);
	for(int k = 0; k < 3; k++) X4[k] = X[k] + DT * val[k] * a4;
	for(int k = 0; k < 3; k++) X[k] += (b1*(X1[k]-X[k]) + b2*(X2[k]-X[k]) + 
					    b3*(X3[k]-X[k]) + b4*(X4[k]-X[k])) ;
	for(int k = 0; k < 3; k++) DX[k] = X[k] - XINIT[k];

	if(v2){
	  View->NbSL++;
	  List_Add(View->SL, &XPREV[0]);
	  List_Add(View->SL, &X[0]);
	  List_Add(View->SL, &XPREV[1]);
	  List_Add(View->SL, &X[1]);
	  List_Add(View->SL, &XPREV[2]);
	  List_Add(View->SL, &X[2]);
	  for(int k = 0; k < v2->NbTimeStep; k++)
	    List_Add(View->SL, &val2[k]);
	  o2->searchScalar(X[0], X[1], X[2], val2, -1);
	  for(int k = 0; k < v2->NbTimeStep; k++)
	    List_Add(View->SL, &val2[k]);
	}
	else{
	  List_Add(View->VP, &DX[0]);
	  List_Add(View->VP, &DX[1]);
	  List_Add(View->VP, &DX[2]);	      
	}
      }
    }
  }

  if(v2){
    delete [] val2;
    delete o2;
  }
  else{
    View->VectorType = DRAW_POST_DISPLACEMENT;
  }

  char name[1024], filename[1024];
  sprintf(name, "%s_StreamLines", v1->Name);
  sprintf(filename, "%s_StreamLines.pos", v1->Name);
  EndView(View, 1, filename, name);

  return View;
}

Post_View *GMSH_StreamLinesPlugin::execute(Post_View * v)
{
  int iView = (int)StreamLinesOptions_Number[14].def;
  int dView = (int)StreamLinesOptions_Number[13].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  return GenerateView(iView, dView);
}

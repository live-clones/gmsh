// $Id: CutGrid.cpp,v 1.15 2005-01-09 02:18:59 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "OctreePost.h"
#include "CutGrid.h"
#include "List.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

StringXNumber CutGridOptions_Number[] = {
  {GMSH_FULLRC, "X0", GMSH_CutGridPlugin::callbackX0, 0.},
  {GMSH_FULLRC, "Y0", GMSH_CutGridPlugin::callbackY0, 0.},
  {GMSH_FULLRC, "Z0", GMSH_CutGridPlugin::callbackZ0, 0.},
  {GMSH_FULLRC, "X1", GMSH_CutGridPlugin::callbackX1, 1.},
  {GMSH_FULLRC, "Y1", GMSH_CutGridPlugin::callbackY1, 0.},
  {GMSH_FULLRC, "Z1", GMSH_CutGridPlugin::callbackZ1, 0.},
  {GMSH_FULLRC, "X2", GMSH_CutGridPlugin::callbackX2, 0.},
  {GMSH_FULLRC, "Y2", GMSH_CutGridPlugin::callbackY2, 1.},
  {GMSH_FULLRC, "Z2", GMSH_CutGridPlugin::callbackZ2, 0.},
  {GMSH_FULLRC, "nPointsU", GMSH_CutGridPlugin::callbackU, 20},
  {GMSH_FULLRC, "nPointsV", GMSH_CutGridPlugin::callbackV, 20},
  {GMSH_FULLRC, "ConnectPoints", GMSH_CutGridPlugin::callbackConnect, 1},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutGridPlugin()
  {
    return new GMSH_CutGridPlugin();
  }
}

GMSH_CutGridPlugin::GMSH_CutGridPlugin()
{
  ;
}

void GMSH_CutGridPlugin::draw()
{
#if defined(HAVE_FLTK)
  glColor4ubv((GLubyte *) & CTX.color.fg);
  double p[3];

  if(CutGridOptions_Number[11].def){
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
  }
  else{
    for(int i = 0; i < getNbU(); ++i){
      for(int j = 0; j < getNbV(); ++j){
	getPoint(i, j, p);
	Draw_Point(1, CTX.point_size, &p[0], &p[1], &p[2], 1);
      }
    }
  }
#endif
}

double GMSH_CutGridPlugin::callback(int num, int action, double value, double *opt,
				    double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

double GMSH_CutGridPlugin::callbackX0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[0].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackY0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[1].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackZ0(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[2].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackX1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[3].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackY1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[4].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackZ1(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[5].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackX2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[6].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackY2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[7].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackZ2(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[8].def,
		  CTX.lc/100., -2*CTX.lc, 2*CTX.lc);
}

double GMSH_CutGridPlugin::callbackU(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[9].def,
		  1, 1, 100);
}

double GMSH_CutGridPlugin::callbackV(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[10].def,
		  1, 1, 100);
}

double GMSH_CutGridPlugin::callbackConnect(int num, int action, double value)
{
  return callback(num, action, value, &CutGridOptions_Number[11].def,
		  1, 0, 1);
}

void GMSH_CutGridPlugin::getName(char *name) const
{
  strcpy(name, "Cut Grid");
}

void GMSH_CutGridPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutGrid) cuts a triangle/tetrahedron view\n"
	 "with a rectangular grid defined by the 3 points\n"
	 "(`X0',`Y0',`Z0') (origin), (`X1',`Y1',`Z1') (axis of U)\n"
	 "and (`X2',`Y2',`Z2') (axis of V). The number of points\n"
	 "along U and V is set with the options `nPointsU'\n"
	 "and `nPointsV'. If `ConnectPoints' is zero, the\n"
	 "plugin creates scalar or vector points; otherwise,\n"
	 "the plugin generates scalar or vector quadrangles,\n"
	 "lines or points depending on the values of `nPointsU'\n"
	 "and `nPointsV'. If `iView' < 0, the plugin is run on\n"
	 "the current view.\n"
	 "\n"
	 "Plugin(CutGrid) creates one new view.\n");
}

int GMSH_CutGridPlugin::getNbOptions() const
{
  return sizeof(CutGridOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutGridPlugin::getOption(int iopt)
{
  return &CutGridOptions_Number[iopt];
}

void GMSH_CutGridPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutGrid failed...");
}

int GMSH_CutGridPlugin::getNbU()
{
  return   (int)CutGridOptions_Number[9].def;
}

int GMSH_CutGridPlugin::getNbV()
{
  return   (int)CutGridOptions_Number[10].def;
}

void GMSH_CutGridPlugin::getPoint(int iU, int iV, double *X)
{
  double u = getNbU() > 1 ? (double)iU / (double)(getNbU() - 1.) : 0.;
  double v = getNbV() > 1 ? (double)iV / (double)(getNbV() - 1.) : 0.;
  X[0] = CutGridOptions_Number[0].def + 
    u  * (CutGridOptions_Number[3].def-CutGridOptions_Number[0].def) +
    v  * (CutGridOptions_Number[6].def-CutGridOptions_Number[0].def) ;
  X[1] = CutGridOptions_Number[1].def + 
    u  * (CutGridOptions_Number[4].def-CutGridOptions_Number[1].def) +
    v  * (CutGridOptions_Number[7].def-CutGridOptions_Number[1].def) ;
  X[2] = CutGridOptions_Number[2].def + 
    u  * (CutGridOptions_Number[5].def-CutGridOptions_Number[2].def) +
    v  * (CutGridOptions_Number[8].def-CutGridOptions_Number[2].def) ;
}

Post_View * GMSH_CutGridPlugin::GenerateView(Post_View * v, int connect) const 
{
  if(getNbU() <= 0 || getNbV() <= 0)
    return v;

  Post_View * View = BeginView(1);

  OctreePost o(v);

  double ***pnts = new double** [getNbU()];
  double ***vals = new double** [getNbU()];
  for(int i = 0; i < getNbU(); i++){
    pnts[i] = new double* [getNbV()];
    vals[i] = new double* [getNbV()];
    for(int j = 0; j < getNbV(); j++){
      pnts[i][j] = new double[3];
      vals[i][j] = new double[3 * v->NbTimeStep]; // change to 9 for tensors
      getPoint(i, j, pnts[i][j]);
    }
  }
  
  if(v->NbST || v->NbSS){

    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
	o.searchScalar(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], 
		       vals[i][j]);
    
    if(!connect){ // generate points

      for(int i = 0; i < getNbU(); ++i){
	for(int j = 0; j < getNbV(); ++j){
	  List_Add(View->SP, &pnts[i][j][0]);
	  List_Add(View->SP, &pnts[i][j][1]);
	  List_Add(View->SP, &pnts[i][j][2]);
	  View->NbSP ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->SP, &vals[i][j][k]);
	  }
	}
      }

    }
    else{

      if(getNbU() == 1 && getNbV() == 1){
	List_Add(View->SP, &pnts[0][0][0]);
	List_Add(View->SP, &pnts[0][0][1]);
	List_Add(View->SP, &pnts[0][0][2]);
	View->NbSP ++;
	for(int k = 0; k < v->NbTimeStep; ++k){
	  List_Add(View->SP, &vals[0][0][k]);
	}
      }
      else if(getNbU() == 1){
	for(int i = 0; i < getNbV()-1; ++i){
	  List_Add(View->SL, &pnts[0][i][0]); List_Add(View->SL, &pnts[0][i+1][0]);
	  List_Add(View->SL, &pnts[0][i][1]); List_Add(View->SL, &pnts[0][i+1][1]);
	  List_Add(View->SL, &pnts[0][i][2]); List_Add(View->SL, &pnts[0][i+1][2]);
	  View->NbSL ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->SL, &vals[0][i  ][k]);
	    List_Add(View->SL, &vals[0][i+1][k]);
	  }
	}
      }
      else if(getNbV() == 1){
	for(int i = 0; i < getNbU()-1; ++i){
	  List_Add(View->SL, &pnts[i][0][0]); List_Add(View->SL, &pnts[i+1][0][0]);
	  List_Add(View->SL, &pnts[i][0][1]); List_Add(View->SL, &pnts[i+1][0][1]);
	  List_Add(View->SL, &pnts[i][0][2]); List_Add(View->SL, &pnts[i+1][0][2]);
	  View->NbSL ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->SL, &vals[i  ][0][k]);
	    List_Add(View->SL, &vals[i+1][0][k]);
	  }
	}
      }
      else{
	for(int i = 0; i < getNbU()-1; ++i){
	  for(int j = 0; j < getNbV()-1; ++j){
	    List_Add(View->SQ, &pnts[i  ][j  ][0]); List_Add(View->SQ, &pnts[i+1][j  ][0]);
	    List_Add(View->SQ, &pnts[i+1][j+1][0]); List_Add(View->SQ, &pnts[i  ][j+1][0]);
	    List_Add(View->SQ, &pnts[i  ][j  ][1]); List_Add(View->SQ, &pnts[i+1][j  ][1]);
	    List_Add(View->SQ, &pnts[i+1][j+1][1]); List_Add(View->SQ, &pnts[i  ][j+1][1]);
	    List_Add(View->SQ, &pnts[i  ][j  ][2]); List_Add(View->SQ, &pnts[i+1][j  ][2]);
	    List_Add(View->SQ, &pnts[i+1][j+1][2]); List_Add(View->SQ, &pnts[i  ][j+1][2]);
	    View->NbSQ ++;
	    for(int k = 0; k < v->NbTimeStep; ++k){
	      List_Add(View->SQ, &vals[i  ][j  ][k]);
	      List_Add(View->SQ, &vals[i+1][j  ][k]);
	      List_Add(View->SQ, &vals[i+1][j+1][k]);
	      List_Add(View->SQ, &vals[i  ][j+1][k]);
	    }
	  }
	}
      }
    }	

  }

  if(v->NbVT || v->NbVS){

    double sizeElem;
    for(int i = 0; i < getNbU(); i++)
      for(int j = 0; j < getNbV(); j++)
	o.searchVector(pnts[i][j][0], pnts[i][j][1], pnts[i][j][2], 
		       vals[i][j], &sizeElem);
    
    if(!connect){ // generate points

      for(int i = 0; i < getNbU(); ++i){
	for(int j = 0; j < getNbV(); ++j){
	  List_Add(View->VP, &pnts[i][j][0]);
	  List_Add(View->VP, &pnts[i][j][1]);
	  List_Add(View->VP, &pnts[i][j][2]);
	  View->NbVP ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->VP, &vals[i][j][3*k]);
	    List_Add(View->VP, &vals[i][j][3*k+1]);
	    List_Add(View->VP, &vals[i][j][3*k+2]);
	  }
	}
      }

    }
    else{

      if(getNbU() == 1 && getNbV() == 1){
	List_Add(View->VP, &pnts[0][0][0]);
	List_Add(View->VP, &pnts[0][0][1]);
	List_Add(View->VP, &pnts[0][0][2]);
	View->NbVP ++;
	for(int k = 0; k < v->NbTimeStep; ++k){
	  List_Add(View->VP, &vals[0][0][3*k]);
	  List_Add(View->VP, &vals[0][0][3*k+1]);
	  List_Add(View->VP, &vals[0][0][3*k+2]);
	}
      }
      else if(getNbU() == 1){
	for(int i = 0; i < getNbV()-1; ++i){
	  List_Add(View->VL, &pnts[0][i][0]); List_Add(View->VL, &pnts[0][i+1][0]);
	  List_Add(View->VL, &pnts[0][i][1]); List_Add(View->VL, &pnts[0][i+1][1]);
	  List_Add(View->VL, &pnts[0][i][2]); List_Add(View->VL, &pnts[0][i+1][2]);
	  View->NbVL ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->VL, &vals[0][i  ][3*k]);
	    List_Add(View->VL, &vals[0][i  ][3*k+1]);
	    List_Add(View->VL, &vals[0][i  ][3*k+2]);
	    List_Add(View->VL, &vals[0][i+1][3*k]);
	    List_Add(View->VL, &vals[0][i+1][3*k+1]);
	    List_Add(View->VL, &vals[0][i+1][3*k+2]);
	  }
	}
      }
      else if(getNbV() == 1){
	for(int i = 0; i < getNbU()-1; ++i){
	  List_Add(View->VL, &pnts[i][0][0]); List_Add(View->VL, &pnts[i+1][0][0]);
	  List_Add(View->VL, &pnts[i][0][1]); List_Add(View->VL, &pnts[i+1][0][1]);
	  List_Add(View->VL, &pnts[i][0][2]); List_Add(View->VL, &pnts[i+1][0][2]);
	  View->NbVL ++;
	  for(int k = 0; k < v->NbTimeStep; ++k){
	    List_Add(View->VL, &vals[i  ][0][3*k]);
	    List_Add(View->VL, &vals[i  ][0][3*k+1]);
	    List_Add(View->VL, &vals[i  ][0][3*k+2]);
	    List_Add(View->VL, &vals[i+1][0][3*k]);
	    List_Add(View->VL, &vals[i+1][0][3*k+1]);
	    List_Add(View->VL, &vals[i+1][0][3*k+2]);
	  }
	}
      }
      else{
	for(int i = 0; i < getNbU()-1; ++i){
	  for(int j = 0; j < getNbV()-1; ++j){
	    List_Add(View->VQ, &pnts[i  ][j  ][0]); List_Add(View->VQ, &pnts[i+1][j  ][0]);
	    List_Add(View->VQ, &pnts[i+1][j+1][0]); List_Add(View->VQ, &pnts[i  ][j+1][0]);
	    List_Add(View->VQ, &pnts[i  ][j  ][1]); List_Add(View->VQ, &pnts[i+1][j  ][1]);
	    List_Add(View->VQ, &pnts[i+1][j+1][1]); List_Add(View->VQ, &pnts[i  ][j+1][1]);
	    List_Add(View->VQ, &pnts[i  ][j  ][2]); List_Add(View->VQ, &pnts[i+1][j  ][2]);
	    List_Add(View->VQ, &pnts[i+1][j+1][2]); List_Add(View->VQ, &pnts[i  ][j+1][2]);
	    View->NbVQ ++;
	    for(int k = 0; k < v->NbTimeStep; ++k){
	      List_Add(View->VQ, &vals[i  ][j  ][3*k]);
	      List_Add(View->VQ, &vals[i  ][j  ][3*k+1]);
	      List_Add(View->VQ, &vals[i  ][j  ][3*k+2]);
	      List_Add(View->VQ, &vals[i+1][j  ][3*k]);
	      List_Add(View->VQ, &vals[i+1][j  ][3*k+1]);
	      List_Add(View->VQ, &vals[i+1][j  ][3*k+2]);
	      List_Add(View->VQ, &vals[i+1][j+1][3*k]);
	      List_Add(View->VQ, &vals[i+1][j+1][3*k+1]);
	      List_Add(View->VQ, &vals[i+1][j+1][3*k+2]);
	      List_Add(View->VQ, &vals[i  ][j+1][3*k]);
	      List_Add(View->VQ, &vals[i  ][j+1][3*k+1]);
	      List_Add(View->VQ, &vals[i  ][j+1][3*k+2]);
	    }
	  }
	}
      }
    }	

  }

  for(int i = 0; i < getNbU(); i++){
    for(int j = 0; j < getNbV(); j++){
      delete [] pnts[i][j];
      delete [] vals[i][j];
    }
    delete [] pnts[i];
    delete [] vals[i];
  }
  delete [] pnts;
  delete [] vals;

  char name[1024], filename[1024];
  sprintf(name, "%s_CutGrid", v->Name);
  sprintf(filename, "%s_CutGrid.pos", v->Name);
  EndView(View, v->NbTimeStep, filename, name);

  return View;
}

Post_View *GMSH_CutGridPlugin::execute(Post_View * v)
{
  int connectPoints = (int)CutGridOptions_Number[11].def;
  int iView = (int)CutGridOptions_Number[12].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  return GenerateView(v1, connectPoints);
}

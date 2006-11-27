// $Id: Lambda2.cpp,v 1.11 2006-11-27 22:22:32 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "Plugin.h"
#include "Lambda2.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "ShapeFunctions.h"
#include <math.h>
#include <stdio.h>

extern Context_T CTX;

StringXNumber Lambda2Options_Number[] = {
  {GMSH_FULLRC, "Eigenvalue", NULL, 2.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterLambda2Plugin()
  {
    return new GMSH_Lambda2Plugin();
  }
}

GMSH_Lambda2Plugin::GMSH_Lambda2Plugin()
{
  ;
}

void GMSH_Lambda2Plugin::getName(char *name) const
{
  strcpy(name, "Lambda2");
}

void GMSH_Lambda2Plugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "E. Marchandise");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Lambda2) computes the eigenvalues\n"
	 "Lambda(1,2,3) of the tensor (S_ik S_kj +\n"
	 "Om_ik Om_kj), where S_ij = 0.5 (ui,j + uj,i)\n"
	 "and Om_ij = 0.5 (ui,j - uj,i) are respectively\n"
	 "the symmetric and antisymmetric parts of the\n"
	 "velocity gradient tensor. Vortices are well\n"
	 "represented by regions where Lambda(2) is\n"
	 "negative. If `iView' contains tensor elements,\n"
	 "the plugin directly uses the tensors as the\n"
	 "values of the velocity gradient tensor; if\n"
	 "`iView' contains vector elements, the plugin\n"
	 "uses them as the velocities from which to derive\n"
	 "the velocity gradient tensor. If `iView' < 0,\n"
	 "the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Lambda2) creates one new view.\n");
}

int GMSH_Lambda2Plugin::getNbOptions() const
{
  return sizeof(Lambda2Options_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Lambda2Plugin::getOption(int iopt)
{
  return &Lambda2Options_Number[iopt];
}

void GMSH_Lambda2Plugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Lambda2 failed...");
}

static int inv3x3tran(double mat[3][3], double inv[3][3], double *det)
{
  double ud;

  *det = det3x3(mat);

  if(*det == 0.0)
    return (0);

  ud = 1. / (*det);

  inv[0][0] = ud * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
  inv[0][1] = -ud * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
  inv[0][2] = ud * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
  inv[1][0] = -ud * (mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
  inv[1][1] = ud * (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
  inv[1][2] = -ud * (mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);
  inv[2][0] = ud * (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
  inv[2][1] = -ud * (mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
  inv[2][2] = ud * (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
  return 1;
}

static void eigen(List_T *inList, int inNb, 
		  List_T *outList, int *outNb,
		  int nbTime, int nbNod, int nbComp, int lam)
{
  if(!inNb || (nbComp != 3 && nbComp != 9) || lam < 1 || lam > 3)
    return;

  // loop on elements  
  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {

    // FIXME: there was this test in the old Plugin(Gradient)
    // double *yy = (double *)List_Pointer_Fast(inList, i + nbNod);
    // if(yy[0] > 0){

    // copy node coordinates
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, List_Pointer_Fast(inList, i + j));
    
    // loop on time steps
    for(int j = 0; j < nbTime; j++){

      double *x = (double *)List_Pointer_Fast(inList, i);
      double *y = (double *)List_Pointer_Fast(inList, i + nbNod);
      double *z = (double *)List_Pointer_Fast(inList, i + 2 * nbNod);

      double GradVel[3][3];

      if(nbComp == 9){ 
	// val is the velocity gradient tensor: we assume that it is
	// constant per element
	double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						nbNod * nbComp * j + nbComp * 0);
	GradVel[0][0] = v[0]; GradVel[0][1] = v[1]; GradVel[0][2] = v[2];
	GradVel[1][0] = v[3]; GradVel[1][1] = v[4]; GradVel[1][2] = v[5];
	GradVel[2][0] = v[6]; GradVel[2][1] = v[7]; GradVel[2][2] = v[8];
      }
      else if(nbComp == 3){ 
	// FIXME: the following could be greatly simplified and
	// generalized by using the classes in ShapeFunctions.h

	// val contains the velocities: compute the gradient tensor
	// from them
	const int MAX_NOD = 4; 
	double val[3][MAX_NOD];
	for(int k = 0; k < nbNod; k++){
	  double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						  nbNod * nbComp * j + nbComp * k);
	  for(int l = 0; l < 3; l++){
	    val[l][k] = v[l];
	  }
	}
	// compute gradient of shape functions
	double GradPhi_x[MAX_NOD][3];
	double GradPhi_ksi[MAX_NOD][3];
	double dx_dksi[3][3];
	double dksi_dx[3][3];
	double det;
	if(nbNod == 3){ // triangles  
	  double a[3], b[3], cross[3];
	  a[0]= x[1]-x[0]; a[1]= y[1]-y[0]; a[2]= z[1]-z[0];
	  b[0]= x[2]-x[0]; b[1]= y[2]-y[0]; b[2]= z[2]-z[0];
	  prodve(a, b, cross);
	  dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = cross[0];
	  dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = cross[1];
	  dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = cross[2];
	  inv3x3tran(dx_dksi, dksi_dx, &det);
	  GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1;  GradPhi_ksi[0][2]= 0;  
	  GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0;  GradPhi_ksi[1][2]= 0;
	  GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1;  GradPhi_ksi[2][2]= 0;
	}
	else if (nbNod == 4){ // tetrahedra
	  dx_dksi[0][0] = x[1] - x[0]; dx_dksi[0][1] = x[2]-x[0]; dx_dksi[0][2] = x[3]-x[0];
	  dx_dksi[1][0] = y[1] - y[0]; dx_dksi[1][1] = y[2]-y[0]; dx_dksi[1][2] = y[3]-y[0];
	  dx_dksi[2][0] = z[1] - z[0]; dx_dksi[2][1] = z[2]-z[0]; dx_dksi[2][2] = z[3]-z[0];   
	  inv3x3tran(dx_dksi, dksi_dx, &det);
	  GradPhi_ksi[0][0]= -1;  GradPhi_ksi[0][1]= -1; GradPhi_ksi[0][2]= -1; 
	  GradPhi_ksi[1][0]=  1;  GradPhi_ksi[1][1]=  0; GradPhi_ksi[1][2]=  0; 
	  GradPhi_ksi[2][0]=  0;  GradPhi_ksi[2][1]=  1; GradPhi_ksi[2][2]=  0; 
	  GradPhi_ksi[3][0]=  0;  GradPhi_ksi[3][1]=  0; GradPhi_ksi[3][2]=  1; 
	}
	else{
	  Msg(GERROR, "Lambda2 not ready for this type of element");
	  return;
	}
	for(int k = 0; k < nbNod ; k++){
	  for(int l = 0; l < 3; l++){
	    GradPhi_x[k][l] = 0.0;
	    for(int m = 0; m < 3; m++){
	      GradPhi_x[k][l] += GradPhi_ksi[k][m] * dksi_dx[l][m];
	    }
	  }
	}
	// compute gradient of velocities
	for(int k = 0; k < 3; k++){
	  for(int l = 0; l < 3; l++){
	    GradVel[k][l] = 0.0;
	    for(int m = 0; m < nbNod; m++){
	      GradVel[k][l] +=  val[k][m]* GradPhi_x[m][l];
	    }
	  }
	}
      }
	
      // compute the sym and antisymetric parts
      double sym[3][3];
      double asym[3][3];
      for(int m = 0; m < 3; m++){
	for(int n = 0; n < 3; n++){
	  sym[m][n]  = 0.5 * (GradVel[m][n] + GradVel[n][m]);
	  asym[m][n] = 0.5 * (GradVel[m][n] - GradVel[n][m]);
	}
      }
      double a[3][3];
      for(int m = 0; m < 3; m++){
	for(int n = 0; n < 3; n++){
	  a[m][n] = 0.0;
	  for(int l = 0; l < 3; l++)
	    a[m][n] += sym[m][l] * sym[l][n] + asym[m][l] * asym[l][n];
	}
      }
      
      // compute the eigenvalues
      double lambda[3];
      eigenvalue(a, lambda);
      for(int k = 0; k < nbNod; k++)
	List_Add(outList, &lambda[lam-1]);
    }

    (*outNb)++;

    // FIXME: end of the yy[0]>0 test in the old Plugin(Gradient)
    // }
    
  }
}

Post_View *GMSH_Lambda2Plugin::execute(Post_View * v)
{
  int ev = (int)Lambda2Options_Number[0].def;
  int iView = (int)Lambda2Options_Number[1].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);  
  Post_View *v2 = BeginView(1);
  
  // assume that the tensors contain the velocity gradient tensor
  eigen(v1->TP, v1->NbTP, v2->SP, &v2->NbSP, v1->NbTimeStep, 1, 9, ev);
  eigen(v1->TL, v1->NbTL, v2->SL, &v2->NbSL, v1->NbTimeStep, 2, 9, ev);
  eigen(v1->TT, v1->NbTT, v2->ST, &v2->NbST, v1->NbTimeStep, 3, 9, ev);
  eigen(v1->TQ, v1->NbTQ, v2->SQ, &v2->NbSQ, v1->NbTimeStep, 4, 9, ev);
  eigen(v1->TS, v1->NbTS, v2->SS, &v2->NbSS, v1->NbTimeStep, 4, 9, ev);
  eigen(v1->TH, v1->NbTH, v2->SH, &v2->NbSH, v1->NbTimeStep, 8, 9, ev);
  eigen(v1->TI, v1->NbTI, v2->SI, &v2->NbSI, v1->NbTimeStep, 6, 9, ev);
  eigen(v1->TY, v1->NbTY, v2->SY, &v2->NbSY, v1->NbTimeStep, 5, 9, ev);

  // assume that the vectors contain the velocities
  // FIXME: only implemented for tri/tet at the moment
  //eigen(v1->VP, v1->NbVP, v2->SP, &v2->NbSP, v1->NbTimeStep, 1, 3, ev);
  //eigen(v1->VL, v1->NbVL, v2->SL, &v2->NbSL, v1->NbTimeStep, 2, 3, ev);
  eigen(v1->VT, v1->NbVT, v2->ST, &v2->NbST, v1->NbTimeStep, 3, 3, ev);
  //eigen(v1->VQ, v1->NbVQ, v2->SQ, &v2->NbSQ, v1->NbTimeStep, 4, 3, ev);
  eigen(v1->VS, v1->NbVS, v2->SS, &v2->NbSS, v1->NbTimeStep, 4, 3, ev);
  //eigen(v1->VH, v1->NbVH, v2->SH, &v2->NbSH, v1->NbTimeStep, 8, 3, ev);
  //eigen(v1->VI, v1->NbVI, v2->SI, &v2->NbSI, v1->NbTimeStep, 6, 3, ev);
  //eigen(v1->VY, v1->NbVY, v2->SY, &v2->NbSY, v1->NbTimeStep, 5, 3, ev);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Lambda2", v1->Name);
  sprintf(filename, "%s_Lambda2.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}

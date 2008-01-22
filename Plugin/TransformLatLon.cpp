// $Id: TransformLatLon.cpp,v 1.2 2008-01-22 20:44:36 geuzaine Exp $
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

#include "TransformLatLon.h"
#include "Numeric.h"

StringXNumber TransformLatLonOptions_Number[] = {
  {GMSH_FULLRC,(char*) "iView", NULL, -1.},
  {GMSH_FULLRC,(char*) "Longitude0", NULL, 0.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformLatLonPlugin()
  {
    return new GMSH_TransformLatLonPlugin();
  }
}

GMSH_TransformLatLonPlugin::GMSH_TransformLatLonPlugin()
{
  ;
}

void GMSH_TransformLatLonPlugin::getName(char *name) const
{
  strcpy(name, "TransformLatLon");
}

void GMSH_TransformLatLonPlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(TransformLatLon) transforms the homogeneous\n"
	 "node coordinates (x,y,z,1) of the elements in\n"
	 "the view `iView' by the matrix\n"
         "[`A11' `A12' `A13' `Tx']\n"
	 "[`A21' `A22' `A23' `Ty']\n"
	 "[`A31' `A32' `A33' `Tz'].\n"
	 "If `SwapOrientation' is set, the orientation of the\n"
	 "elements is reversed. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(TransformLatLon) is executed in-place.\n");
}

int GMSH_TransformLatLonPlugin::getNbOptions() const
{
  return sizeof(TransformLatLonOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TransformLatLonPlugin::getOption(int iopt)
{
  return &TransformLatLonOptions_Number[iopt];
}

void GMSH_TransformLatLonPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "TransformLatLon failed...");
}

// TransformLatLonation

static void transform(double v[3], double *x, double *y, double *z,double rotate)
{
	double r = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	*y=asin(v[2]/r)*180/M_PI;
	*x=atan2(v[1],v[0])*180/M_PI+rotate;
	while(*x>180)*x-=360;
	*z=0;
}

static void transform_list(List_T *list, int nbList, List_T *list2, int *nbList2, 
			   int nbVert, int nbComp,double rotate)
{
  if(!nbList) return;
  int nb = List_Nbr(list) / nbList;
	double *x2=new double[nbVert];
	double *y2=new double[nbVert];
	double *z2=new double[nbVert];
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      double v[3] = { x[j], y[j], z[j] };
      transform(v, &x2[j], &y2[j], &z2[j],rotate);
    }
		// check the periodicity
		bool cross=false;
		for(int j=1;j<nbVert;j++) cross|=(fabs(x2[j]-x2[0])>180);
		if(cross) for(int j=0;j<nbVert;j++) if(x2[j]<0)x2[j]+=360;
    for(int j = 0; j < nbVert; j++)List_Add(list2,&x2[j]);
    for(int j = 0; j < nbVert; j++)List_Add(list2,&y2[j]);
    for(int j = 0; j < nbVert; j++)List_Add(list2,&z2[j]);
		for(int k = 0; k < nbVert; k++){
			double d;
			for(int l = 0; l < nbComp; l++){
				List_Read(list, i + 3 * nbVert + nbComp * k + l, &d);
				List_Add(list2, &d);
			}
		}
    (*nbList2)++;
		if(cross){
			for(int j=0;j<nbVert;j++) x2[j]-=360;
			for(int j = 0; j < nbVert; j++)List_Add(list2,&x2[j]);
			for(int j = 0; j < nbVert; j++)List_Add(list2,&y2[j]);
			for(int j = 0; j < nbVert; j++)List_Add(list2,&z2[j]);
			for(int k = 0; k < nbVert; k++){
				double d;
				for(int l = 0; l < nbComp; l++){
					List_Read(list, i + 3 * nbVert + nbComp * k + l, &d);
					List_Add(list2, &d);
				}
			}
			(*nbList2)++;
		}
  }
	delete []x2;
	delete []y2;
	delete []z2;
}

PView *GMSH_TransformLatLonPlugin::execute(PView *v)
{
  int iView = (int)TransformLatLonOptions_Number[0].def;
	double rotate = (double)TransformLatLonOptions_Number[1].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
	PView *v2 = new PView(true);
  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;
  // points
  transform_list(data1->SP, data1->NbSP, data2->SP, &data2->NbSP, 1, 1, rotate); 
  transform_list(data1->VP, data1->NbVP, data2->VP, &data2->NbVP, 1, 3, rotate);
  transform_list(data1->TP, data1->NbTP, data2->TP, &data2->NbTP, 1, 9, rotate);
  // lines			                                  	            
  transform_list(data1->SL, data1->NbSL, data2->SL, &data2->NbSL, 2, 1, rotate); 
  transform_list(data1->VL, data1->NbVL, data2->VL, &data2->NbVL, 2, 3, rotate);
  transform_list(data1->TL, data1->NbTL, data2->TL, &data2->NbTL, 2, 9, rotate);
  // triangles			                                  	        	
  transform_list(data1->ST, data1->NbST, data2->ST, &data2->NbST, 3, 1, rotate); 
  transform_list(data1->VT, data1->NbVT, data2->VT, &data2->NbVT, 3, 3, rotate);
  transform_list(data1->TT, data1->NbTT, data2->TT, &data2->NbTT, 3, 9, rotate);
  // quadrangles		                                  	        	
  transform_list(data1->SQ, data1->NbSQ, data2->SQ, &data2->NbSQ, 4, 1, rotate); 
  transform_list(data1->VQ, data1->NbVQ, data2->VQ, &data2->NbVQ, 4, 3, rotate);
  transform_list(data1->TQ, data1->NbTQ, data2->TQ, &data2->NbTQ, 4, 9, rotate);
  // tets			                                  	              
  transform_list(data1->SS, data1->NbSS, data2->SS, &data2->NbSS, 4, 1, rotate); 
  transform_list(data1->VS, data1->NbVS, data2->VS, &data2->NbVS, 4, 3, rotate);
  transform_list(data1->TS, data1->NbTS, data2->TS, &data2->NbTS, 4, 9, rotate);
  // hexas			                                  	            
  transform_list(data1->SH, data1->NbSH, data2->SH, &data2->NbSH, 8, 1, rotate); 
  transform_list(data1->VH, data1->NbVH, data2->VH, &data2->NbVH, 8, 3, rotate);
  transform_list(data1->TH, data1->NbTH, data2->TH, &data2->NbTH, 8, 9, rotate);
  // prisms			                                  	            
  transform_list(data1->SI, data1->NbSI, data2->SI, &data2->NbSI, 6, 1, rotate); 
  transform_list(data1->VI, data1->NbVI, data2->VI, &data2->NbVI, 6, 3, rotate);
  transform_list(data1->TI, data1->NbTI, data2->TI, &data2->NbTI, 6, 9, rotate);
  // pyramids			                                  	          
  transform_list(data1->SY, data1->NbSY, data2->SY, &data2->NbSY, 5, 1, rotate); 
  transform_list(data1->VY, data1->NbVY, data2->VY, &data2->NbVY, 5, 3, rotate);
  transform_list(data1->TY, data1->NbTY, data2->TY, &data2->NbTY, 5, 9, rotate);

  data2->setName(data1->getName() + "_LatLon");
  data2->setFileName(data1->getName() + "_LatLon.pos");
  data2->finalize();

  return v2;
}

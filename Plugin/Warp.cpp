// $Id: Warp.cpp,v 1.9 2007-09-11 14:01:55 geuzaine Exp $
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

#include "Warp.h"
#include "SmoothData.h"

StringXNumber WarpOptions_Number[] = {
  {GMSH_FULLRC, "Factor", NULL, 1.},
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "SmoothingAngle", NULL, 180.},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterWarpPlugin()
  {
    return new GMSH_WarpPlugin();
  }
}


GMSH_WarpPlugin::GMSH_WarpPlugin()
{
  ;
}

void GMSH_WarpPlugin::getName(char *name) const
{
  strcpy(name, "Warp");
}

void GMSH_WarpPlugin::getInfos(char *author, char *copyright,
                                         char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Warp) transforms the elements in the\n"
	 "view `iView' by adding to their node coordinates\n"
	 "the vector field stored in the `TimeStep'-th time\n"
	 "step of the view `dView', scaled by `Factor'. If\n"
	 "`dView' < 0, the vector field is taken as the field\n"
	 "of surface normals multiplied by the `TimeStep'\n"
	 "value in `iView'. (The smoothing of the surface\n"
	 "normals is controlled by the `SmoothingAngle'\n"
	 "parameter.) If `iView' < 0, the plugin is run on\n"
	 "the current view.\n"
	 "\n"
	 "Plugin(Warp) is executed in-place.\n");
}

int GMSH_WarpPlugin::getNbOptions() const
{
  return sizeof(WarpOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_WarpPlugin::getOption(int iopt)
{
  return &WarpOptions_Number[iopt];
}

void GMSH_WarpPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Warp failed...");
}

static void addNormals(List_T *listElm, int nbElm, int nbNod, 
		       smooth_normals *normals)
{
  if(!nbElm || nbNod < 3) return;
  int nb = List_Nbr(listElm) / nbElm;
  for(int i = 0; i < List_Nbr(listElm); i += nb) {
    double *x = (double *)List_Pointer_Fast(listElm, i);
    double *y = (double *)List_Pointer_Fast(listElm, i + nbNod);
    double *z = (double *)List_Pointer_Fast(listElm, i + 2 * nbNod);
    double nn[3];
    normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], nn);
    for(int k = 0; k < nbNod; k++)
      normals->add(x[k], y[k], z[k], nn[0], nn[1], nn[2]);
  }
}

static void warpList(List_T *iList, int iNbElm,
		     List_T *dList, int dNbElm,
		     int nbNod, double factor, int TimeStep,
		     int nbComp, smooth_normals *normals)
{
  if(!iNbElm)
    return;

  if(!normals && (iNbElm != dNbElm)){
    Msg(GERROR, "Views have a different number of elements (%d != %d)", 
	iNbElm, dNbElm);
    return;
  }
  
  // for each element
  //   for each node
  //      (x,y,z) += factor * (valx,valy,valz)

  int iNb = List_Nbr(iList) / iNbElm;
  int dNb = normals ? 0 : List_Nbr(dList) / dNbElm;
  for(int i = 0, j = 0; i < List_Nbr(iList); i += iNb, j += dNb) {
    double *x = (double *)List_Pointer_Fast(iList, i);
    double *y = (double *)List_Pointer_Fast(iList, i + nbNod);
    double *z = (double *)List_Pointer_Fast(iList, i + 2 * nbNod);
    double *val;
    if(normals)
      val = (double *)List_Pointer_Fast(iList, i + 3 * nbNod);
    else
      val = (double *)List_Pointer_Fast(dList, j + 3 * nbNod);

    double nn[3] = {0., 0., 1.};
    if(normals && nbNod > 2)
      normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], nn);

    for(int k = 0; k < nbNod; k++) {
      if(normals){
	double d = 1.;
	if(TimeStep >= 0){
	  double *v = &val[nbComp * nbNod * TimeStep + nbComp * k];
	  if(nbComp == 1)
	    d = v[0];
	  else if(nbComp == 3)
	    d = sqrt(DSQR(v[0]) + DSQR(v[1]) + DSQR(v[2]));
	  else if(nbComp == 9)
	    d = ComputeVonMises(v);
	}
	normals->get(x[k], y[k], z[k], nn[0], nn[1], nn[2]);
	x[k] += factor * d * nn[0];
	y[k] += factor * d * nn[1];
	z[k] += factor * d * nn[2];
      }
      else{
	if(TimeStep < 0) TimeStep = 0;
	x[k] += factor * val[3 * nbNod * TimeStep + 3 * k];
	y[k] += factor * val[3 * nbNod * TimeStep + 3 * k + 1];
	z[k] += factor * val[3 * nbNod * TimeStep + 3 * k + 2];
      }
    }
  }
  
}

static void warp(PViewDataList *data1, PViewDataList *data2, double factor, 
		 int ts, double tol)
{
  smooth_normals *nn = 0;
  if(WarpOptions_Number[3].def <  0){
    nn = new smooth_normals(tol);
    addNormals(data1->ST, data1->NbST, 3, nn);
    addNormals(data1->VT, data1->NbVT, 3, nn);
    addNormals(data1->TT, data1->NbTT, 3, nn);
    addNormals(data1->SQ, data1->NbSQ, 4, nn);
    addNormals(data1->VQ, data1->NbVQ, 4, nn);
    addNormals(data1->TQ, data1->NbTQ, 4, nn);
  }

  warpList(data1->SP, data1->NbSP, data2->VP, data2->NbVP, 1, factor, ts, 1, nn);
  warpList(data1->SL, data1->NbSL, data2->VL, data2->NbVL, 2, factor, ts, 1, nn);
  warpList(data1->ST, data1->NbST, data2->VT, data2->NbVT, 3, factor, ts, 1, nn);
  warpList(data1->SQ, data1->NbSQ, data2->VQ, data2->NbVQ, 4, factor, ts, 1, nn);
  warpList(data1->SS, data1->NbSS, data2->VS, data2->NbVS, 4, factor, ts, 1, nn);
  warpList(data1->SH, data1->NbSH, data2->VH, data2->NbVH, 8, factor, ts, 1, nn);
  warpList(data1->SI, data1->NbSI, data2->VI, data2->NbVI, 6, factor, ts, 1, nn);
  warpList(data1->SY, data1->NbSY, data2->VY, data2->NbVY, 5, factor, ts, 1, nn);
	   		   	       	  	                    
  warpList(data1->VP, data1->NbVP, data2->VP, data2->NbVP, 1, factor, ts, 3, nn);
  warpList(data1->VL, data1->NbVL, data2->VL, data2->NbVL, 2, factor, ts, 3, nn);
  warpList(data1->VT, data1->NbVT, data2->VT, data2->NbVT, 3, factor, ts, 3, nn);
  warpList(data1->VQ, data1->NbVQ, data2->VQ, data2->NbVQ, 4, factor, ts, 3, nn);
  warpList(data1->VS, data1->NbVS, data2->VS, data2->NbVS, 4, factor, ts, 3, nn);
  warpList(data1->VH, data1->NbVH, data2->VH, data2->NbVH, 8, factor, ts, 3, nn);
  warpList(data1->VI, data1->NbVI, data2->VI, data2->NbVI, 6, factor, ts, 3, nn);
  warpList(data1->VY, data1->NbVY, data2->VY, data2->NbVY, 5, factor, ts, 3, nn);
	   		   	       	  	                    
  warpList(data1->TP, data1->NbTP, data2->VP, data2->NbVP, 1, factor, ts, 9, nn);
  warpList(data1->TL, data1->NbTL, data2->VL, data2->NbVL, 2, factor, ts, 9, nn);
  warpList(data1->TT, data1->NbTT, data2->VT, data2->NbVT, 3, factor, ts, 9, nn);
  warpList(data1->TQ, data1->NbTQ, data2->VQ, data2->NbVQ, 4, factor, ts, 9, nn);
  warpList(data1->TS, data1->NbTS, data2->VS, data2->NbVS, 4, factor, ts, 9, nn);
  warpList(data1->TH, data1->NbTH, data2->VH, data2->NbVH, 8, factor, ts, 9, nn);
  warpList(data1->TI, data1->NbTI, data2->VI, data2->NbVI, 6, factor, ts, 9, nn);
  warpList(data1->TY, data1->NbTY, data2->VY, data2->NbVY, 5, factor, ts, 9, nn);

  if(nn) delete nn;
}

PView *GMSH_WarpPlugin::execute(PView *v)
{
  double factor = WarpOptions_Number[0].def;
  int TimeStep = (int)WarpOptions_Number[1].def;
  double AngleTol = WarpOptions_Number[2].def;
  int dView = (int)WarpOptions_Number[3].def;
  int iView = (int)WarpOptions_Number[4].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(dView < 0) dView = iView;

  PView *v2 = getView(dView, v);
  if(!v2) return v;

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  if(TimeStep > data2->getNumTimeSteps() - 1){
    // we allow TimeStep < 0 (to apply fixed warps)
    Msg(GERROR, "Invalid TimeStep (%d) in View[%d]", TimeStep, v2->getIndex());
    return v;
  }

  warp(data1, data2, factor, TimeStep, AngleTol);

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

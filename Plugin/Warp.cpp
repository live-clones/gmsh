// $Id: Warp.cpp,v 1.1.2.3 2006-04-17 15:18:02 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "Warp.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "SmoothNormals.h"

extern Context_T CTX;

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
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
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
	 "parameter.). If `iView' < 0, the plugin is run on\n"
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

static void warpList(Post_View * iView, List_T * iList, int iNbElm, 
		     Post_View * dView, List_T * dList, int dNbElm,
		     int nbNod, double factor, int TimeStep,
		     int nbComp, smooth_normals *normals)
{
  if(!iNbElm)
    return;

  if(!normals && (iNbElm != dNbElm)){
    Msg(GERROR, "View[%d] and View[%d] have a different number of elements (%d != %d)",
	iView->Index, dView->Index, iNbElm, dNbElm);
    return;
  }
  
  iView->Changed = 1;

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
      if(x[k] < iView->BBox[0]) iView->BBox[0] = x[k];
      if(x[k] > iView->BBox[1]) iView->BBox[1] = x[k];
      if(y[k] < iView->BBox[2]) iView->BBox[2] = y[k];
      if(y[k] > iView->BBox[3]) iView->BBox[3] = y[k];
      if(z[k] < iView->BBox[4]) iView->BBox[4] = z[k];
      if(z[k] > iView->BBox[5]) iView->BBox[5] = z[k];
    }
  }
  
}

static void warp(Post_View * v, Post_View * w, double factor, int ts, double tol)
{
  for(int i = 0; i < 3; i++) {
    v->BBox[2 * i] = VAL_INF;
    v->BBox[2 * i + 1] = -VAL_INF;
  }

  smooth_normals *nn = 0;
  if(WarpOptions_Number[3].def <  0){
    nn = new smooth_normals(tol);
    addNormals(v->ST, v->NbST, 3, nn);
    addNormals(v->VT, v->NbVT, 3, nn);
    addNormals(v->TT, v->NbTT, 3, nn);
    addNormals(v->SQ, v->NbSQ, 4, nn);
    addNormals(v->VQ, v->NbVQ, 4, nn);
    addNormals(v->TQ, v->NbTQ, 4, nn);
  }

  warpList(v, v->SP, v->NbSP, w, w->VP, w->NbVP, 1, factor, ts, 1, nn);
  warpList(v, v->SL, v->NbSL, w, w->VL, w->NbVL, 2, factor, ts, 1, nn);
  warpList(v, v->ST, v->NbST, w, w->VT, w->NbVT, 3, factor, ts, 1, nn);
  warpList(v, v->SQ, v->NbSQ, w, w->VQ, w->NbVQ, 4, factor, ts, 1, nn);
  warpList(v, v->SS, v->NbSS, w, w->VS, w->NbVS, 4, factor, ts, 1, nn);
  warpList(v, v->SH, v->NbSH, w, w->VH, w->NbVH, 8, factor, ts, 1, nn);
  warpList(v, v->SI, v->NbSI, w, w->VI, w->NbVI, 6, factor, ts, 1, nn);
  warpList(v, v->SY, v->NbSY, w, w->VY, w->NbVY, 5, factor, ts, 1, nn);
			   	       	  	                    
  warpList(v, v->VP, v->NbVP, w, w->VP, w->NbVP, 1, factor, ts, 3, nn);
  warpList(v, v->VL, v->NbVL, w, w->VL, w->NbVL, 2, factor, ts, 3, nn);
  warpList(v, v->VT, v->NbVT, w, w->VT, w->NbVT, 3, factor, ts, 3, nn);
  warpList(v, v->VQ, v->NbVQ, w, w->VQ, w->NbVQ, 4, factor, ts, 3, nn);
  warpList(v, v->VS, v->NbVS, w, w->VS, w->NbVS, 4, factor, ts, 3, nn);
  warpList(v, v->VH, v->NbVH, w, w->VH, w->NbVH, 8, factor, ts, 3, nn);
  warpList(v, v->VI, v->NbVI, w, w->VI, w->NbVI, 6, factor, ts, 3, nn);
  warpList(v, v->VY, v->NbVY, w, w->VY, w->NbVY, 5, factor, ts, 3, nn);
			   	       	  	                    
  warpList(v, v->TP, v->NbTP, w, w->VP, w->NbVP, 1, factor, ts, 9, nn);
  warpList(v, v->TL, v->NbTL, w, w->VL, w->NbVL, 2, factor, ts, 9, nn);
  warpList(v, v->TT, v->NbTT, w, w->VT, w->NbVT, 3, factor, ts, 9, nn);
  warpList(v, v->TQ, v->NbTQ, w, w->VQ, w->NbVQ, 4, factor, ts, 9, nn);
  warpList(v, v->TS, v->NbTS, w, w->VS, w->NbVS, 4, factor, ts, 9, nn);
  warpList(v, v->TH, v->NbTH, w, w->VH, w->NbVH, 8, factor, ts, 9, nn);
  warpList(v, v->TI, v->NbTI, w, w->VI, w->NbVI, 6, factor, ts, 9, nn);
  warpList(v, v->TY, v->NbTY, w, w->VY, w->NbVY, 5, factor, ts, 9, nn);

  if(nn) delete nn;
}

Post_View *GMSH_WarpPlugin::execute(Post_View * v)
{
  double factor = WarpOptions_Number[0].def;
  int TimeStep = (int)WarpOptions_Number[1].def;
  double AngleTol = WarpOptions_Number[2].def;
  int dView = (int)WarpOptions_Number[3].def;
  int iView = (int)WarpOptions_Number[4].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  if(dView < 0)
    dView = iView;

  if(!List_Pointer_Test(CTX.post.list, dView)) {
    Msg(GERROR, "View[%d] does not exist", dView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = *(Post_View **)List_Pointer(CTX.post.list, dView);

  if(TimeStep > v2->NbTimeStep - 1){
    // we allow TimeStep < 0 (to apply fixed warps)
    Msg(GERROR, "Invalid TimeStep (%d) in View[%d]", TimeStep, v2->Index);
    return v;
  }

  warp(v1, v2, factor, TimeStep, AngleTol);

  return v1;
}

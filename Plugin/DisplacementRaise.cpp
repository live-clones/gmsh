// $Id: DisplacementRaise.cpp,v 1.9 2003-11-22 18:45:40 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Plugin.h"
#include "DisplacementRaise.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber DisplacementRaiseOptions_Number[] = {
  {GMSH_FULLRC, "Factor", NULL, 1.},
  {GMSH_FULLRC, "dTimeStep", NULL, 0.},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDisplacementRaisePlugin()
  {
    return new GMSH_DisplacementRaisePlugin();
  }
}


GMSH_DisplacementRaisePlugin::GMSH_DisplacementRaisePlugin()
{
  ;
}

void GMSH_DisplacementRaisePlugin::getName(char *name) const
{
  strcpy(name, "Displacement raise");
}

void GMSH_DisplacementRaisePlugin::getInfos(char *author, char *copyright,
                                         char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(DisplacementRaise) transforms the\n"
         "coordinates of the elements in the view 'iView'\n"
         "using the vectorial values (the displacements)\n"
         "stored in the 'dTimeStep'-th time step of the\n"
	 "view 'dView'. If 'iView' < 0, the plugin is\n"
	 "run on the current view. If 'dView' < 0, the\n"
	 "plugin looks for the displacements in the\n"
	 "view located just after 'iView' in the view\n"
	 "list.\n");
}

int GMSH_DisplacementRaisePlugin::getNbOptions() const
{
  return sizeof(DisplacementRaiseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DisplacementRaisePlugin::getOption(int iopt)
{
  return &DisplacementRaiseOptions_Number[iopt];
}

void GMSH_DisplacementRaisePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "DisplacementRaise failed...");
}

static void displacementRaiseList(Post_View * iView, List_T * iList, int iNbElm, 
				  Post_View * dView, List_T * dList, int dNbElm,
				  int nbVert, double factor, int dTimeStep)
{
  if(!iNbElm || !dNbElm)
    return;

  if(iNbElm != dNbElm){
    Msg(WARNING, "View[%d] and View[%d] have a different number of elements (%d != %d)",
	iView->Index, dView->Index, iNbElm, dNbElm);
    return;
  }

  // should we treat multiple time steps by generating new views
  // (cf. time dependent CutMaps)?
  if(dTimeStep < 0 || dTimeStep > dView->NbTimeStep - 1){
    Msg(WARNING, "Invalid TimeStep (%d) in View[%d]: choosing TimeStep 0",
	dTimeStep, dView->Index);
    dTimeStep = 0;
  }

  iView->Changed = 1;

  // for each element
  //   for each node
  //      compute (x,y,z)_new = (x,y,z)_old + factor*(valx,valy,valz)

  int iNb = List_Nbr(iList) / iNbElm;
  int dNb = List_Nbr(dList) / dNbElm;
  for(int i = 0, j = 0; i < List_Nbr(iList); i += iNb, j += dNb) {
    double *x = (double *)List_Pointer_Fast(iList, i);
    double *y = (double *)List_Pointer_Fast(iList, i + nbVert);
    double *z = (double *)List_Pointer_Fast(iList, i + 2 * nbVert);
    double *val = (double *)List_Pointer_Fast(dList, j + 3 * nbVert);
    for(int k = 0; k < nbVert; k++) {
      x[k] += factor * val[3 * nbVert * dTimeStep + 3 * k];
      y[k] += factor * val[3 * nbVert * dTimeStep + 3 * k + 1];
      z[k] += factor * val[3 * nbVert * dTimeStep + 3 * k + 2];
    }
  }

}

static void displacementRaise(Post_View * v, Post_View * w, double factor, int ts)
{
  displacementRaiseList(v, v->SP, v->NbSP, w, w->VP, w->NbVP, 1, factor, ts);
  displacementRaiseList(v, v->SL, v->NbSL, w, w->VL, w->NbVL, 2, factor, ts);
  displacementRaiseList(v, v->ST, v->NbST, w, w->VT, w->NbVT, 3, factor, ts);
  displacementRaiseList(v, v->SQ, v->NbSQ, w, w->VQ, w->NbVQ, 4, factor, ts);
  displacementRaiseList(v, v->SS, v->NbSS, w, w->VS, w->NbVS, 4, factor, ts);
  displacementRaiseList(v, v->SH, v->NbSH, w, w->VH, w->NbVH, 8, factor, ts);
  displacementRaiseList(v, v->SI, v->NbSI, w, w->VI, w->NbVI, 6, factor, ts);
  displacementRaiseList(v, v->SY, v->NbSY, w, w->VY, w->NbVY, 5, factor, ts);
			   	       	  	                    
  displacementRaiseList(v, v->VP, v->NbVP, w, w->VP, w->NbVP, 1, factor, ts);
  displacementRaiseList(v, v->VL, v->NbVL, w, w->VL, w->NbVL, 2, factor, ts);
  displacementRaiseList(v, v->VT, v->NbVT, w, w->VT, w->NbVT, 3, factor, ts);
  displacementRaiseList(v, v->VQ, v->NbVQ, w, w->VQ, w->NbVQ, 4, factor, ts);
  displacementRaiseList(v, v->VS, v->NbVS, w, w->VS, w->NbVS, 4, factor, ts);
  displacementRaiseList(v, v->VH, v->NbVH, w, w->VH, w->NbVH, 8, factor, ts);
  displacementRaiseList(v, v->VI, v->NbVI, w, w->VI, w->NbVI, 6, factor, ts);
  displacementRaiseList(v, v->VY, v->NbVY, w, w->VY, w->NbVY, 5, factor, ts);
			   	       	  	                    
  displacementRaiseList(v, v->TP, v->NbTP, w, w->VP, w->NbVP, 1, factor, ts);
  displacementRaiseList(v, v->TL, v->NbTL, w, w->VL, w->NbVL, 2, factor, ts);
  displacementRaiseList(v, v->TT, v->NbTT, w, w->VT, w->NbVT, 3, factor, ts);
  displacementRaiseList(v, v->TQ, v->NbTQ, w, w->VQ, w->NbVQ, 4, factor, ts);
  displacementRaiseList(v, v->TS, v->NbTS, w, w->VS, w->NbVS, 4, factor, ts);
  displacementRaiseList(v, v->TH, v->NbTH, w, w->VH, w->NbVH, 8, factor, ts);
  displacementRaiseList(v, v->TI, v->NbTI, w, w->VI, w->NbVI, 6, factor, ts);
  displacementRaiseList(v, v->TY, v->NbTY, w, w->VY, w->NbVY, 5, factor, ts);
}

Post_View *GMSH_DisplacementRaisePlugin::execute(Post_View * v)
{
  Post_View *vv, *ww;

  double factor = DisplacementRaiseOptions_Number[0].def;
  int dTimeStep = (int)DisplacementRaiseOptions_Number[1].def;
  int dView = (int)DisplacementRaiseOptions_Number[2].def;
  int iView = (int)DisplacementRaiseOptions_Number[3].def;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(GERROR, "View[%d] does not exist", iView);
      return 0;
    }
  }

  if(dView < 0){
    dView = vv->Index + 1; // by default, try to use the next view
  }
  if(!(ww = (Post_View *) List_Pointer_Test(CTX.post.list, dView))) {
    Msg(GERROR, "View[%d] does not exist", dView);
    return 0;
  }

  displacementRaise(vv, ww, factor, dTimeStep);
  return vv;
}


// $Id: HarmonicToTime.cpp,v 1.5 2005-01-01 19:35:39 geuzaine Exp $
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

#include "Plugin.h"
#include "HarmonicToTime.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber HarmonicToTimeOptions_Number[] = {
  {GMSH_FULLRC, "realPart", NULL, 0.},
  {GMSH_FULLRC, "imaginaryPart", NULL, 1.},
  {GMSH_FULLRC, "nSteps", NULL, 20.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHarmonicToTimePlugin()
  {
    return new GMSH_HarmonicToTimePlugin();
  }
}


GMSH_HarmonicToTimePlugin::GMSH_HarmonicToTimePlugin()
{
  ;
}

void GMSH_HarmonicToTimePlugin::getName(char *name) const
{
  strcpy(name, "Harmonic to Time");
}

void GMSH_HarmonicToTimePlugin::getInfos(char *author, char *copyright,
                                        char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(HarmonicToTime) takes the values in the\n"
	 "time steps `realPart' and `imaginaryPart' of\n"
         "the view `iView', and creates a new view\n"
         "containing (`iView'[`realPart'] * cos(p) -\n"
         "`iView'[`imaginaryPart'] * sin(p)), with\n"
         "p = 2*Pi*k/`nSteps', k = 0, ..., `nSteps'-1.\n"
	 "If `iView' < 0, the plugin is run on the\n"
	 "current view.\n"
	 "\n"
	 "Plugin(HarmonicToTime) creates one new view.\n");
}

int GMSH_HarmonicToTimePlugin::getNbOptions() const
{
  return sizeof(HarmonicToTimeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HarmonicToTimePlugin::getOption(int iopt)
{
  return &HarmonicToTimeOptions_Number[iopt];
}

void GMSH_HarmonicToTimePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "HarmonicToTime failed...");
}


static void h2t(int nb1, List_T *list1, int *nb2, List_T *list2,
		int nbNod, int nbComp, int rIndex, int iIndex, int nSteps)
{
  if(!nb1) return;

  int nb = List_Nbr(list1) / nb1;
  for(int i = 0; i < List_Nbr(list1); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(list2, List_Pointer_Fast(list1, i + j));
    double *valr = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
					       nbNod * nbComp * rIndex);
    double *vali = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
					       nbNod * nbComp * iIndex);
    for(int t = 0; t < nSteps; t++) {
      double p = 2. * M_PI * t / nSteps;
      for(int j = 0; j < nbNod; j++) {
	for(int k = 0; k < nbComp; k++) {
	  double val = valr[nbComp * j + k] * cos(p) - vali[nbComp * j + k] * sin(p);
	  List_Add(list2, &val);	  
	}
      }
    }
  }
  *nb2 = nb1;
}

Post_View *GMSH_HarmonicToTimePlugin::execute(Post_View * v)
{
  int rIndex, iIndex, nSteps, iView;

  rIndex = (int)HarmonicToTimeOptions_Number[0].def;
  iIndex = (int)HarmonicToTimeOptions_Number[1].def;
  nSteps = (int)HarmonicToTimeOptions_Number[2].def;
  iView = (int)HarmonicToTimeOptions_Number[3].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  if(nSteps <= 0){
    Msg(GERROR, "nSteps should be > 0");
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  if(rIndex < 0 || rIndex >= v1->NbTimeStep ||
     iIndex < 0 || iIndex >= v1->NbTimeStep){
    Msg(GERROR, "Wrong real or imaginary part index");
    return v;
  }

  Post_View *v2 = BeginView(1);

  h2t(v1->NbSP, v1->SP, &v2->NbSP, v2->SP, 1, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVP, v1->VP, &v2->NbVP, v2->VP, 1, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTP, v1->TP, &v2->NbTP, v2->TP, 1, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSL, v1->SL, &v2->NbSL, v2->SL, 2, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVL, v1->VL, &v2->NbVL, v2->VL, 2, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTL, v1->TL, &v2->NbTL, v2->TL, 2, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbST, v1->ST, &v2->NbST, v2->ST, 3, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVT, v1->VT, &v2->NbVT, v2->VT, 3, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTT, v1->TT, &v2->NbTT, v2->TT, 3, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSQ, v1->SQ, &v2->NbSQ, v2->SQ, 4, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVQ, v1->VQ, &v2->NbVQ, v2->VQ, 4, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTQ, v1->TQ, &v2->NbTQ, v2->TQ, 4, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSS, v1->SS, &v2->NbSS, v2->SS, 4, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVS, v1->VS, &v2->NbVS, v2->VS, 4, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTS, v1->TS, &v2->NbTS, v2->TS, 4, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSH, v1->SH, &v2->NbSH, v2->SH, 8, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVH, v1->VH, &v2->NbVH, v2->VH, 8, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTH, v1->TH, &v2->NbTH, v2->TH, 8, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSI, v1->SI, &v2->NbSI, v2->SI, 6, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVI, v1->VI, &v2->NbVI, v2->VI, 6, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTI, v1->TI, &v2->NbTI, v2->TI, 6, 9, rIndex, iIndex, nSteps);
  h2t(v1->NbSY, v1->SY, &v2->NbSY, v2->SY, 5, 1, rIndex, iIndex, nSteps);
  h2t(v1->NbVY, v1->VY, &v2->NbVY, v2->VY, 5, 3, rIndex, iIndex, nSteps);
  h2t(v1->NbTY, v1->TY, &v2->NbTY, v2->TY, 5, 9, rIndex, iIndex, nSteps);

  // copy time data
  for(int i = 0; i < nSteps; i++){
    double p = 2.*M_PI*i/(double)nSteps;
    List_Add(v2->Time, &p);
  }
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_HarmonicToTime", v1->Name);
  sprintf(filename, "%s_HarmonicToTime.pos", v1->Name);
  EndView(v2, 1, filename, name);

  return v2;
}

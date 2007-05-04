// $Id: ModulusPhase.cpp,v 1.5 2007-05-04 10:45:09 geuzaine Exp $
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
#include "ModulusPhase.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

extern Context_T CTX;

StringXNumber ModulusPhaseOptions_Number[] = {
  {GMSH_FULLRC, "RealPart", NULL, 0.},
  {GMSH_FULLRC, "ImaginaryPart", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterModulusPhasePlugin()
  {
    return new GMSH_ModulusPhasePlugin();
  }
}


GMSH_ModulusPhasePlugin::GMSH_ModulusPhasePlugin()
{
  ;
}

void GMSH_ModulusPhasePlugin::getName(char *name) const
{
  strcpy(name, "Modulus Phase");
}

void GMSH_ModulusPhasePlugin::getInfos(char *author, char *copyright,
                                        char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(ModulusPhase) interprets the time steps\n"
	 "`realPart' and `imaginaryPart' in the view `iView'\n"
	 "as the real and imaginary parts of a complex field\n"
	 "and replaces them with their corresponding\n"
	 "modulus and phase. If `iView' < 0, the plugin is\n"
	 "run on the current view.\n"
	 "\n"
	 "Plugin(ModulusPhase) is executed in-place.\n");
}

int GMSH_ModulusPhasePlugin::getNbOptions() const
{
  return sizeof(ModulusPhaseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ModulusPhasePlugin::getOption(int iopt)
{
  return &ModulusPhaseOptions_Number[iopt];
}

void GMSH_ModulusPhasePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "ModulusPhase failed...");
}


static void mp(int nb1, List_T *list1, int nbNod, int nbComp)
{
  if(!nb1) return;

  int rIndex = (int)ModulusPhaseOptions_Number[0].def;
  int iIndex = (int)ModulusPhaseOptions_Number[1].def;

  int nb = List_Nbr(list1) / nb1;
  for(int i = 0; i < List_Nbr(list1); i += nb) {
    double *valr = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
					       nbNod * nbComp * rIndex);
    double *vali = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
					       nbNod * nbComp * iIndex);
    for(int j = 0; j < nbNod; j++) {
      for(int k = 0; k < nbComp; k++) {
	double vr = valr[nbComp * j + k];
	double vi = vali[nbComp * j + k];
	double modulus = sqrt(vr*vr+vi*vi);
	double phase = atan2(vi, vr);
	valr[nbComp * j + k] = modulus;
	vali[nbComp * j + k] = phase;
      }
    }
  }
}

Post_View *GMSH_ModulusPhasePlugin::execute(Post_View * v)
{
  int rIndex = (int)ModulusPhaseOptions_Number[0].def;
  int iIndex = (int)ModulusPhaseOptions_Number[1].def;
  int iView = (int)ModulusPhaseOptions_Number[2].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  if(rIndex < 0 || rIndex >= v1->NbTimeStep ||
     iIndex < 0 || iIndex >= v1->NbTimeStep){
    Msg(GERROR, "Wrong real or imaginary part index");
    return v1;
  }

  mp(v1->NbSP, v1->SP, 1, 1); mp(v1->NbVP, v1->VP, 1, 3); mp(v1->NbTP, v1->TP, 1, 9);
  mp(v1->NbSL, v1->SL, 2, 1); mp(v1->NbVL, v1->VL, 2, 3); mp(v1->NbTL, v1->TL, 2, 9);
  mp(v1->NbST, v1->ST, 3, 1); mp(v1->NbVT, v1->VT, 3, 3); mp(v1->NbTT, v1->TT, 3, 9);
  mp(v1->NbSQ, v1->SQ, 4, 1); mp(v1->NbVQ, v1->VQ, 4, 3); mp(v1->NbTQ, v1->TQ, 4, 9);
  mp(v1->NbSS, v1->SS, 4, 1); mp(v1->NbVS, v1->VS, 4, 3); mp(v1->NbTS, v1->TS, 4, 9);
  mp(v1->NbSH, v1->SH, 8, 1); mp(v1->NbVH, v1->VH, 8, 3); mp(v1->NbTH, v1->TH, 8, 9);
  mp(v1->NbSI, v1->SI, 6, 1); mp(v1->NbVI, v1->VI, 6, 3); mp(v1->NbTI, v1->TI, 6, 9);
  mp(v1->NbSY, v1->SY, 5, 1); mp(v1->NbVY, v1->VY, 5, 3); mp(v1->NbTY, v1->TY, 5, 9);

  // recompute min/max, etc.:
  v1->Min = VAL_INF;
  v1->Max = -VAL_INF;
  char name[1024], filename[1024];
  sprintf(name, "%s_ModulusPhase", v1->Name);
  sprintf(filename, "%s_ModulusPhase.pos", v1->Name);
  EndView(v1, 0, filename, name);

  return v1;
}

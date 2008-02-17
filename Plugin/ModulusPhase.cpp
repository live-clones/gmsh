// $Id: ModulusPhase.cpp,v 1.8 2008-02-17 08:48:07 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "ModulusPhase.h"

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

PView *GMSH_ModulusPhasePlugin::execute(PView *v)
{
  int rIndex = (int)ModulusPhaseOptions_Number[0].def;
  int iIndex = (int)ModulusPhaseOptions_Number[1].def;
  int iView = (int)ModulusPhaseOptions_Number[2].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() ||
     iIndex < 0 || iIndex >= data1->getNumTimeSteps()){
    Msg(GERROR, "Wrong real or imaginary part index");
    return v1;
  }

  mp(data1->NbSP, data1->SP, 1, 1); 
  mp(data1->NbVP, data1->VP, 1, 3); 
  mp(data1->NbTP, data1->TP, 1, 9);
  mp(data1->NbSL, data1->SL, 2, 1);
  mp(data1->NbVL, data1->VL, 2, 3); 
  mp(data1->NbTL, data1->TL, 2, 9);
  mp(data1->NbST, data1->ST, 3, 1); 
  mp(data1->NbVT, data1->VT, 3, 3); 
  mp(data1->NbTT, data1->TT, 3, 9);
  mp(data1->NbSQ, data1->SQ, 4, 1); 
  mp(data1->NbVQ, data1->VQ, 4, 3);
  mp(data1->NbTQ, data1->TQ, 4, 9);
  mp(data1->NbSS, data1->SS, 4, 1); 
  mp(data1->NbVS, data1->VS, 4, 3); 
  mp(data1->NbTS, data1->TS, 4, 9);
  mp(data1->NbSH, data1->SH, 8, 1); 
  mp(data1->NbVH, data1->VH, 8, 3);
  mp(data1->NbTH, data1->TH, 8, 9);
  mp(data1->NbSI, data1->SI, 6, 1); 
  mp(data1->NbVI, data1->VI, 6, 3);
  mp(data1->NbTI, data1->TI, 6, 9);
  mp(data1->NbSY, data1->SY, 5, 1);
  mp(data1->NbVY, data1->VY, 5, 3); 
  mp(data1->NbTY, data1->TY, 5, 9);

  data1->setName(data1->getName() + "_ModulusPhase");
  data1->setName(data1->getName() + ".pos");
  data1->finalize();

  return v1;
}

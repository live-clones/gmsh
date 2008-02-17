// $Id: Eigenvalues.cpp,v 1.6 2008-02-17 08:48:06 geuzaine Exp $
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

#include "Eigenvalues.h"
#include "Numeric.h"

StringXNumber EigenvaluesOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvaluesPlugin()
  {
    return new GMSH_EigenvaluesPlugin();
  }
}

GMSH_EigenvaluesPlugin::GMSH_EigenvaluesPlugin()
{
  ;
}

void GMSH_EigenvaluesPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvalues");
}

void GMSH_EigenvaluesPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Eigenvalues) computes the three real\n"
	 "eigenvalues of each tensor in the view `iView'.\n"
	 "If `iView' < 0, the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Eigenvalues) creates three new scalar views.\n");
}

int GMSH_EigenvaluesPlugin::getNbOptions() const
{
  return sizeof(EigenvaluesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvaluesPlugin::getOption(int iopt)
{
  return &EigenvaluesOptions_Number[iopt];
}

void GMSH_EigenvaluesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvalues failed...");
}

static void eigenvalues(List_T *inList, int inNb, 
			int nbNod, int nbTime,
			List_T *minList, int *minNb, 
			List_T *midList, int *midNb, 
			List_T *maxList, int *maxNb)
{
  if(!inNb) return;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++){
      List_Add(minList, List_Pointer_Fast(inList, i + j));
      List_Add(midList, List_Pointer_Fast(inList, i + j));
      List_Add(maxList, List_Pointer_Fast(inList, i + j));
    }
    for(int j = 0; j < nbTime; j++){
      for(int k = 0; k < nbNod; k++){
	double *v = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
						nbNod * 9 * j + 9 * k);
	double w[3], A[3][3] = { {v[0], v[1], v[2]},
				 {v[3], v[4], v[5]},
				 {v[6], v[7], v[8]} };
	eigenvalue(A, w);
	for(int l = 0; l < 3; l++){
	  List_Add(minList, &w[2]);
	  List_Add(midList, &w[1]);
	  List_Add(maxList, &w[0]);
	}
      }
    }
    (*minNb)++;
    (*midNb)++;
    (*maxNb)++;
  }
}

PView *GMSH_EigenvaluesPlugin::execute(PView *v)
{
  int iView = (int)EigenvaluesOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *min = new PView(true);
  PView *mid = new PView(true);
  PView *max = new PView(true);

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);

  eigenvalues(data1->TP, data1->NbTP, 1, data1->getNumTimeSteps(),
	      dmin->SP, &dmin->NbSP, dmid->SP, &dmid->NbSP, dmax->SP, &dmax->NbSP);
  eigenvalues(data1->TL, data1->NbTL, 2, data1->getNumTimeSteps(),
	      dmin->SL, &dmin->NbSL, dmid->SL, &dmid->NbSL, dmax->SL, &dmax->NbSL);
  eigenvalues(data1->TT, data1->NbTT, 3, data1->getNumTimeSteps(),
	      dmin->ST, &dmin->NbST, dmid->ST, &dmid->NbST, dmax->ST, &dmax->NbST);
  eigenvalues(data1->TQ, data1->NbTQ, 4, data1->getNumTimeSteps(),
	      dmin->SQ, &dmin->NbSQ, dmid->SQ, &dmid->NbSQ, dmax->SQ, &dmax->NbSQ);
  eigenvalues(data1->TS, data1->NbTS, 4, data1->getNumTimeSteps(),
	      dmin->SS, &dmin->NbSS, dmid->SS, &dmid->NbSS, dmax->SS, &dmax->NbSS);
  eigenvalues(data1->TH, data1->NbTH, 8, data1->getNumTimeSteps(),
	      dmin->SH, &dmin->NbSH, dmid->SH, &dmid->NbSH, dmax->SH, &dmax->NbSH);
  eigenvalues(data1->TI, data1->NbTI, 6, data1->getNumTimeSteps(),
	      dmin->SI, &dmin->NbSI, dmid->SI, &dmid->NbSI, dmax->SI, &dmax->NbSI);
  eigenvalues(data1->TY, data1->NbTY, 5, data1->getNumTimeSteps(),
	      dmin->SY, &dmin->NbSY, dmid->SY, &dmid->NbSY, dmax->SY, &dmax->NbSY);

  for(int i = 0; i < List_Nbr(data1->Time); i++){
    List_Add(dmin->Time, List_Pointer(data1->Time, i));
    List_Add(dmid->Time, List_Pointer(data1->Time, i));
    List_Add(dmax->Time, List_Pointer(data1->Time, i));
  }
  dmin->setName(data1->getName() + "_MinEigenvalues");
  dmin->setFileName(data1->getName() + "_MinEigenvalues.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvalues");
  dmid->setFileName(data1->getName() + "_MidEigenvalues.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvalues");
  dmax->setFileName(data1->getName() + "_MaxEigenvalues.pos");
  dmax->finalize();

  return 0;
}

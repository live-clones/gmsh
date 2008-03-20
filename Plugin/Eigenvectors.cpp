// $Id: Eigenvectors.cpp,v 1.11 2008-03-20 11:44:13 geuzaine Exp $
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

#include "Eigenvectors.h"
#include "Numeric.h"
#include "EigSolve.h"

StringXNumber EigenvectorsOptions_Number[] = {
  {GMSH_FULLRC, "ScaleByEigenvalues", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvectorsPlugin()
  {
    return new GMSH_EigenvectorsPlugin();
  }
}

GMSH_EigenvectorsPlugin::GMSH_EigenvectorsPlugin()
{
  ;
}

void GMSH_EigenvectorsPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvectors");
}

void GMSH_EigenvectorsPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Eigenvectors) computes the three (right)\n"
         "eigenvectors of each tensor in the view `iView'\n"
         "and sorts them according to the value of the\n"
         "associated eigenvalues. If `ScaleByEigenvalues'\n"
         "is set, each eigenvector is scaled by its\n"
         "associated eigenvalue. The plugin gives an error\n"
         "if the eigenvectors are complex. If `iView' < 0,\n"
         "the plugin is run on the current view.\n"
         "\n"
         "Plugin(Eigenvectors) creates three new\n"
         "vector views.\n");
}

int GMSH_EigenvectorsPlugin::getNbOptions() const
{
  return sizeof(EigenvectorsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvectorsPlugin::getOption(int iopt)
{
  return &EigenvectorsOptions_Number[iopt];
}

void GMSH_EigenvectorsPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvectors failed...");
}

static int nonzero(double v[3])
{
  for(int i = 0; i < 3; i++)
    if(fabs(v[i]) > 1.e-16) return 1;
  return 0;
}

static void eigenvectors(List_T *inList, int inNb, 
                         int nbNod, int nbTime, int scale,
                         List_T *minList, int *minNb, 
                         List_T *midList, int *midNb, 
                         List_T *maxList, int *maxNb)
{
  if(!inNb) return;

  int nbcomplex = 0;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++){
      List_Add(minList, List_Pointer_Fast(inList, i + j));
      List_Add(midList, List_Pointer_Fast(inList, i + j));
      List_Add(maxList, List_Pointer_Fast(inList, i + j));
    }
    for(int j = 0; j < nbTime; j++){
      for(int k = 0; k < nbNod; k++){
        double *val = (double *)List_Pointer_Fast(inList, i + 3 * nbNod + 
                                                  nbNod * 9 * j + 9 * k);
        double wr[3], wi[3], B[9];
        if(!EigSolve3x3(val, wr, wi, B))
          Msg(GERROR, "Eigensolver failed to converge");
        nbcomplex += nonzero(wi); 
        if(!scale)
          wr[0] = wr[1] = wr[2] = 1.;
        for(int l = 0; l < 3; l++){
          double res;
          // wrong if there are complex eigenvals (B contains both
          // real and imag parts: cf. explanation in EigSolve.cpp)
          res = wr[0] * B[l]; List_Add(minList, &res);
          res = wr[1] * B[3+l]; List_Add(midList, &res);
          res = wr[2] * B[6+l]; List_Add(maxList, &res);
        }
      }
    }
    (*minNb)++;
    (*midNb)++;
    (*maxNb)++;
  }

  if(nbcomplex)
    Msg(GERROR, "%d tensors have complex eigenvalues/eigenvectors", nbcomplex);
}

PView *GMSH_EigenvectorsPlugin::execute(PView *v)
{
  int scale = (int)EigenvectorsOptions_Number[0].def;
  int iView = (int)EigenvectorsOptions_Number[1].def;

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

  eigenvectors(data1->TP, data1->NbTP, 1, data1->getNumTimeSteps(), scale,
               dmin->VP, &dmin->NbVP, dmid->VP, &dmid->NbVP, dmax->VP, &dmax->NbVP);
  eigenvectors(data1->TL, data1->NbTL, 2, data1->getNumTimeSteps(), scale,
               dmin->VL, &dmin->NbVL, dmid->VL, &dmid->NbVL, dmax->VL, &dmax->NbVL);
  eigenvectors(data1->TT, data1->NbTT, 3, data1->getNumTimeSteps(), scale,
               dmin->VT, &dmin->NbVT, dmid->VT, &dmid->NbVT, dmax->VT, &dmax->NbVT);
  eigenvectors(data1->TQ, data1->NbTQ, 4, data1->getNumTimeSteps(), scale,
               dmin->VQ, &dmin->NbVQ, dmid->VQ, &dmid->NbVQ, dmax->VQ, &dmax->NbVQ);
  eigenvectors(data1->TS, data1->NbTS, 4, data1->getNumTimeSteps(), scale,
               dmin->VS, &dmin->NbVS, dmid->VS, &dmid->NbVS, dmax->VS, &dmax->NbVS);
  eigenvectors(data1->TH, data1->NbTH, 8, data1->getNumTimeSteps(), scale,
               dmin->VH, &dmin->NbVH, dmid->VH, &dmid->NbVH, dmax->VH, &dmax->NbVH);
  eigenvectors(data1->TI, data1->NbTI, 6, data1->getNumTimeSteps(), scale,
               dmin->VI, &dmin->NbVI, dmid->VI, &dmid->NbVI, dmax->VI, &dmax->NbVI);
  eigenvectors(data1->TY, data1->NbTY, 5, data1->getNumTimeSteps(), scale,
               dmin->VY, &dmin->NbVY, dmid->VY, &dmid->NbVY, dmax->VY, &dmax->NbVY);

  for(int i = 0; i < List_Nbr(data1->Time); i++){
    List_Add(dmin->Time, List_Pointer(data1->Time, i));
    List_Add(dmid->Time, List_Pointer(data1->Time, i));
    List_Add(dmax->Time, List_Pointer(data1->Time, i));
  }
  dmin->setName(data1->getName() + "_MinEigenvectors");
  dmin->setFileName(data1->getName() + "_MinEigenvectors.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvectors");
  dmid->setFileName(data1->getName() + "_MidEigenvectors.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvectors");
  dmax->setFileName(data1->getName() + "_MaxEigenvectors.pos");
  dmax->finalize();

  return 0;
}

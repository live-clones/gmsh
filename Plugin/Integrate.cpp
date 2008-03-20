// $Id: Integrate.cpp,v 1.24 2008-03-20 11:44:14 geuzaine Exp $
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

#include "Integrate.h"
#include "ShapeFunctions.h"

StringXNumber IntegrateOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterIntegratePlugin()
  {
    return new GMSH_IntegratePlugin();
  }
}

GMSH_IntegratePlugin::GMSH_IntegratePlugin()
{
  ;
}

void GMSH_IntegratePlugin::getName(char *name) const
{
  strcpy(name, "Integrate");
}

void GMSH_IntegratePlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Integrate) integrates scalar fields over\n"
         "all the elements in the view `iView', as well\n"
         "as the circulation/flux of vector fields over\n"
         "line/surface elements. If `iView' < 0, the\n"
         "plugin is run on the current view.\n"
         "\n"
         "Plugin(Integrate) creates one new view.\n");
}

int GMSH_IntegratePlugin::getNbOptions() const
{
  return sizeof(IntegrateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_IntegratePlugin::getOption(int iopt)
{
  return &IntegrateOptions_Number[iopt];
}

void GMSH_IntegratePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Integrate failed...");
}

static double integrate(int nbList, List_T *list, int dim, 
                        int nbNod, int nbComp, int step)
{
  if(!nbList) return 0.;

  double res = 0.;
  int nb = List_Nbr(list) / nbList;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbNod);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbNod);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbNod +
                                            nbNod * nbComp * step);
    elementFactory factory;
    element *element = factory.create(nbNod, dim, x, y, z);
    if(!element) return 0.;
    if(nbComp == 1){
      res += element->integrate(v);
    }
    else if(nbComp == 3){
      if(dim == 1)
        res += element->integrateCirculation(v);
      else if(dim == 2)
        res += element->integrateFlux(v);
    }
    delete element;
  }
  return res;
}

PView *GMSH_IntegratePlugin::execute(PView * v)
{
  int iView = (int)IntegrateOptions_Number[1].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;
  
  double x = data1->getBoundingBox().center().x();
  double y = data1->getBoundingBox().center().y();
  double z = data1->getBoundingBox().center().z();
  List_Add(data2->SP, &x);
  List_Add(data2->SP, &y);
  List_Add(data2->SP, &z);
  for(int ts = 0; ts < data1->getNumTimeSteps(); ts++){
    double val = 0;
    // scalar fields
    val += integrate(data1->NbSP, data1->SP, 0, 1, 1, ts);
    val += integrate(data1->NbSL, data1->SL, 1, 2, 1, ts);
    val += integrate(data1->NbST, data1->ST, 2, 3, 1, ts);
    val += integrate(data1->NbSQ, data1->SQ, 2, 4, 1, ts);
    val += integrate(data1->NbSS, data1->SS, 3, 4, 1, ts);
    val += integrate(data1->NbSH, data1->SH, 3, 8, 1, ts);
    val += integrate(data1->NbSI, data1->SI, 3, 6, 1, ts);
    val += integrate(data1->NbSY, data1->SY, 3, 5, 1, ts);
    // circulations
    val += integrate(data1->NbVL, data1->VL, 1, 2, 3, ts);
    // fluxes
    val += integrate(data1->NbVT, data1->VT, 2, 3, 3, ts);
    val += integrate(data1->NbVQ, data1->VQ, 2, 4, 3, ts);
    Msg(INFO, "Step %d: integral = %.16g", ts, val);
    List_Add(data2->SP, &val);
  }
  data2->NbSP = 1;
  v2->getOptions()->IntervalsType = PViewOptions::Numeric;
  
  for(int i = 0; i < List_Nbr(data1->Time); i++)
    List_Add(data2->Time, List_Pointer(data1->Time, i));
  data2->setName(data1->getName() + "_Integrate");
  data2->setFileName(data1->getName() + "_Integrate.pos");
  data2->finalize();
  
  return v2;
}

// $Id: Integrate.cpp,v 1.13 2005-01-08 20:15:19 geuzaine Exp $
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
#include "Integrate.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "ShapeFunctions.h"

extern Context_T CTX;

StringXNumber IntegrateOptions_Number[] = {
  {GMSH_FULLRC, "ComputeLevelsetPositive", NULL, 0.},
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
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
	 "Plugin(Integrate) integrates scalar fields over\n"
	 "all the elements in the view `iView', as well\n"
	 "as the circulation/flux of vector fields over\n"
	 "line/surface elements. If `iView' < 0, the\n"
	 "plugin is run on the current view. If\n"
	 "`ComputeLevelsetPositive' is set, the plugin\n"
	 "computes the positive area (volume) of the map.\n"
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
  
  const int levelsetPositive = (int)IntegrateOptions_Number[0].def;
  
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
    if(!element){
      Msg(GERROR, "Unknown type of element (dim=%d, nbNod=%d)", dim, nbNod);
      return 0.;
    }
    if(nbComp == 1){
      if(!levelsetPositive) 
	res += element->integrate(v);
      else 
	res += element->integrateLevelsetPositive(v);
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

Post_View *GMSH_IntegratePlugin::execute(Post_View * v)
{
  int iView = (int)IntegrateOptions_Number[1].def;
  
  if(iView < 0)
    iView = v ? v->Index : 0;
  
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }
  
  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  Post_View *v2 = BeginView(1);
  
  double x = (v1->BBox[0]+v1->BBox[1])/2.;
  double y = (v1->BBox[2]+v1->BBox[3])/2.;
  double z = (v1->BBox[4]+v1->BBox[5])/2.;
  List_Add(v2->SP, &x);
  List_Add(v2->SP, &y);
  List_Add(v2->SP, &z);
  for(int ts = 0; ts < v1->NbTimeStep; ts++){
    double val = 0;
    // scalar fields
    val += integrate(v1->NbSP, v1->SP, 0, 1, 1, ts);
    val += integrate(v1->NbSL, v1->SL, 1, 2, 1, ts);
    val += integrate(v1->NbST, v1->ST, 2, 3, 1, ts);
    val += integrate(v1->NbSQ, v1->SQ, 2, 4, 1, ts);
    val += integrate(v1->NbSS, v1->SS, 3, 4, 1, ts);
    val += integrate(v1->NbSH, v1->SH, 3, 8, 1, ts);
    val += integrate(v1->NbSI, v1->SI, 3, 6, 1, ts);
    val += integrate(v1->NbSY, v1->SY, 3, 5, 1, ts);
    // circulations
    val += integrate(v1->NbVL, v1->VL, 1, 2, 3, ts);
    // fluxes
    val += integrate(v1->NbVT, v1->VT, 2, 3, 3, ts);
    val += integrate(v1->NbVQ, v1->VQ, 2, 4, 3, ts);
    Msg(INFO, "Step %d: integral = %.16g", ts, val);
    List_Add(v2->SP, &val);
  }
  v2->NbSP = 1;
  v2->IntervalsType = DRAW_POST_NUMERIC;
  
  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Integrate", v1->Name);
  sprintf(filename, "%s_Integrate.pos", v1->Name);
  EndView(v2, 1, filename, name);
  
  return v2;
}

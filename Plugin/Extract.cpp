// $Id: Extract.cpp,v 1.2 2004-03-07 23:49:11 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "Extract.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

StringXNumber ExtractOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "iComponent", NULL, 0.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractPlugin()
  {
    return new GMSH_ExtractPlugin();
  }
}

GMSH_ExtractPlugin::GMSH_ExtractPlugin()
{
  ;
}

void GMSH_ExtractPlugin::getName(char *name) const
{
  strcpy(name, "Extract");
}

void GMSH_ExtractPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Extract) extracts the iComponent-th\n"
	 "component of the view 'iView'. If 'iView' < 0, the\n"
	 "plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Extract) creates one new view.\n");
}

int GMSH_ExtractPlugin::getNbOptions() const
{
  return sizeof(ExtractOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractPlugin::getOption(int iopt)
{
  return &ExtractOptions_Number[iopt];
}

void GMSH_ExtractPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Extract failed...");
}

static void extract(int comp, List_T *inList, int inNb, 
		    List_T *outList, int *outNb, 
		    int nbTime, int nbNod, int nbComp)
{
  if(!inNb)
    return;

  if(comp < 0 || comp > nbComp-1){
    Msg(GERROR, "Cannot extract component #(%d+1)=%d from a %d-component field", 
	comp, comp+1, nbComp);
  }

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, List_Pointer_Fast(inList, i + j));
    for(int j = 0; j < nbTime; j++)
      for(int k = 0; k < nbNod; k++)
	List_Add(outList, List_Pointer_Fast(inList, i + 3 * nbNod + 
					    nbNod * nbComp * j + 
					    nbComp * k + 
					    comp));
    (*outNb)++;
  }
}

Post_View *GMSH_ExtractPlugin::execute(Post_View * v)
{
  int iView = (int)ExtractOptions_Number[0].def;
  int iComp = (int)ExtractOptions_Number[1].def;
  Post_View *vv;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  // FIXME: this is not secure: if BeginView forces a post.list
  // reallocation, vv is wrong
  Post_View *view = BeginView(1);

  // FIXME: this is a very quick implementation of the Extract
  // plugin. An interesting generalization would be to allow arbitrary
  // manipulations of the components: we could do that by merging the
  // stack-based expression evaluator from getdp and then allow things
  // like "$1 + $2", or "Sqrt[$1^2+$5^2]"...

  // points
  extract(iComp, vv->SP, vv->NbSP, view->SP, &view->NbSP, vv->NbTimeStep, 1, 1);
  extract(iComp, vv->VP, vv->NbVP, view->SP, &view->NbSP, vv->NbTimeStep, 1, 3);
  extract(iComp, vv->TP, vv->NbTP, view->SP, &view->NbSP, vv->NbTimeStep, 1, 9);
  // lines
  extract(iComp, vv->SL, vv->NbSL, view->SL, &view->NbSL, vv->NbTimeStep, 2, 1);
  extract(iComp, vv->VL, vv->NbVL, view->SL, &view->NbSL, vv->NbTimeStep, 2, 3);
  extract(iComp, vv->TL, vv->NbTL, view->SL, &view->NbSL, vv->NbTimeStep, 2, 9);
  // triangles
  extract(iComp, vv->ST, vv->NbST, view->ST, &view->NbST, vv->NbTimeStep, 3, 1);
  extract(iComp, vv->VT, vv->NbVT, view->ST, &view->NbST, vv->NbTimeStep, 3, 3);
  extract(iComp, vv->TT, vv->NbTT, view->ST, &view->NbST, vv->NbTimeStep, 3, 9);
  // quadrangles
  extract(iComp, vv->SQ, vv->NbSQ, view->SQ, &view->NbSQ, vv->NbTimeStep, 4, 1);
  extract(iComp, vv->VQ, vv->NbVQ, view->SQ, &view->NbSQ, vv->NbTimeStep, 4, 3);
  extract(iComp, vv->TQ, vv->NbTQ, view->SQ, &view->NbSQ, vv->NbTimeStep, 4, 9);
  // tets
  extract(iComp, vv->SS, vv->NbSS, view->SS, &view->NbSS, vv->NbTimeStep, 4, 1);
  extract(iComp, vv->VS, vv->NbVS, view->SS, &view->NbSS, vv->NbTimeStep, 4, 3);
  extract(iComp, vv->TS, vv->NbTS, view->SS, &view->NbSS, vv->NbTimeStep, 4, 9);
  // hexas
  extract(iComp, vv->SH, vv->NbSH, view->SH, &view->NbSH, vv->NbTimeStep, 8, 1);
  extract(iComp, vv->VH, vv->NbVH, view->SH, &view->NbSH, vv->NbTimeStep, 8, 3);
  extract(iComp, vv->TH, vv->NbTH, view->SH, &view->NbSH, vv->NbTimeStep, 8, 9);
  // prisms
  extract(iComp, vv->SI, vv->NbSI, view->SI, &view->NbSI, vv->NbTimeStep, 6, 1);
  extract(iComp, vv->VI, vv->NbVI, view->SI, &view->NbSI, vv->NbTimeStep, 6, 3);
  extract(iComp, vv->TI, vv->NbTI, view->SI, &view->NbSI, vv->NbTimeStep, 6, 9);
  // pyramids
  extract(iComp, vv->SY, vv->NbSY, view->SY, &view->NbSY, vv->NbTimeStep, 5, 1);
  extract(iComp, vv->VY, vv->NbVY, view->SY, &view->NbSY, vv->NbTimeStep, 5, 3);
  extract(iComp, vv->TY, vv->NbTY, view->SY, &view->NbSY, vv->NbTimeStep, 5, 9);

  if(view->empty()) {
    RemoveViewByNumber(view->Num);
    printf("aaa\n");

  }
  else{
    // copy time data
    for(int i = 0; i < List_Nbr(vv->Time); i++)
      List_Add(view->Time, List_Pointer(vv->Time, i));
    // finalize
    char name[1024], filename[1024];
    sprintf(name, "extract-%s", vv->Name);
    sprintf(filename, "extract-%s", vv->FileName);
    EndView(view, 1, filename, name);
  }

  return 0;
}

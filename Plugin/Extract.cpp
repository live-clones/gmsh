// $Id: Extract.cpp,v 1.12 2004-09-16 19:15:27 geuzaine Exp $
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

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

StringXNumber ExtractOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString ExtractOptions_String[] = {
  {GMSH_FULLRC, "Expression0", NULL, "v0"},
  {GMSH_FULLRC, "Expression1", NULL, ""},
  {GMSH_FULLRC, "Expression2", NULL, ""}
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
         "Plugin(Extract) extracts a combination of\n"
	 "components from the view `iView'. If\n"
	 "`Expression1' or `Expression2' is empty, the\n"
	 "plugin creates a scalar view using\n"
	 "`Expression0'; otherwise the plugin creates\n"
	 "a vector view. In addition to the usual\n"
	 "mathematical functions (Exp, Log, Sqrt, Sin,\n"
	 "Cos, Fabs, etc.) and operators (+, -, *, /, ^),\n"
	 "the expressions can contain the symbols v0,\n"
	 "v1, v2, ..., vn, which represent the n\n"
	 "components of the field. If `iView' < 0, the\n"
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

int GMSH_ExtractPlugin::getNbOptionsStr() const
{
  return sizeof(ExtractOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_ExtractPlugin::getOptionStr(int iopt)
{
  return &ExtractOptions_String[iopt];
}

void GMSH_ExtractPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Extract failed...");
}

static void extract(char *expr[3], List_T *inList, int inNb, 
		    List_T *outListScalar, int *outNbScalar, 
		    List_T *outListVector, int *outNbVector, 
		    int nbTime, int nbNod, int nbComp)
{
  if(!inNb)
    return;

  int outNbComp, *outNb;
  List_T *outList;
  
  if(!strlen(expr[1]) || !strlen(expr[2])){
    outNbComp = 1;
    outNb = outNbScalar;
    outList = outListScalar;
  }
  else{
    outNbComp = 3;
    outNb = outNbVector;
    outList = outListVector;
  }

  // if we have MathEval, we can evaluate arbitrary expressions;
  // otherwise, we only allow to extract single components

#if defined(HAVE_MATH_EVAL)
  void *f[3];
  for(int i = 0; i < outNbComp; i++){
    f[i] = evaluator_create(expr[i]);
    if(!f[i]){
      Msg(GERROR, "Invalid expression '%s'", expr[i]);
      return;
    }
  }
#else
  int comp[3];
  for(int i = 0; i < outNbComp; i++){
    if     (!strcmp(expr[i], "v0")) comp[i] = 0;
    else if(!strcmp(expr[i], "v1")) comp[i] = 1;
    else if(!strcmp(expr[i], "v2")) comp[i] = 2;
    else if(!strcmp(expr[i], "v3")) comp[i] = 3;
    else if(!strcmp(expr[i], "v4")) comp[i] = 4;
    else if(!strcmp(expr[i], "v5")) comp[i] = 5;
    else if(!strcmp(expr[i], "v6")) comp[i] = 6;
    else if(!strcmp(expr[i], "v7")) comp[i] = 7;
    else if(!strcmp(expr[i], "v8")) comp[i] = 8;
    else{
      Msg(GERROR, "Invalid expression '%s'", expr[i]);
      return;
    }
  }
#endif

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, List_Pointer_Fast(inList, i + j));
    for(int j = 0; j < nbTime; j++){
      for(int k = 0; k < nbNod; k++){
	double res, d[9];
	for(int l = 0; l < nbComp; l++)
	  List_Read(inList, i + 3 * nbNod + nbNod * nbComp * j + nbComp * k + l, &d[l]);
	for(int l = nbComp; l < 9; l++)
	  d[l] = 0.;
	for(int l = 0; l < outNbComp; l++){
#if defined(HAVE_MATH_EVAL)
	  char *names[] = { "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" };
	  double values[] = { d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8] };
	  res = evaluator_evaluate(f[l], sizeof(names)/sizeof(names[0]), names, values);
#else
	  res = d[comp[l]];
#endif
	  List_Add(outList, &res);
	}
      }
    }
    (*outNb)++;
  }

#if defined(HAVE_MATH_EVAL)
  for(int i = 0; i < outNbComp; i++)
    evaluator_destroy(f[i]);
#endif
}

Post_View *GMSH_ExtractPlugin::execute(Post_View * v)
{
  int iView = (int)ExtractOptions_Number[0].def;
  char *expr[3] = { ExtractOptions_String[0].def, 
		    ExtractOptions_String[1].def,
		    ExtractOptions_String[2].def };

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v2 = BeginView(1);

  // get v1 after BeginView: this is ok even if post.list got reallocated
  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);

  // points
  extract(expr, v1->SP, v1->NbSP, v2->SP, &v2->NbSP, v2->VP, &v2->NbVP, v1->NbTimeStep, 1, 1);
  extract(expr, v1->VP, v1->NbVP, v2->SP, &v2->NbSP, v2->VP, &v2->NbVP, v1->NbTimeStep, 1, 3);
  extract(expr, v1->TP, v1->NbTP, v2->SP, &v2->NbSP, v2->VP, &v2->NbVP, v1->NbTimeStep, 1, 9);
  // lines			                                  
  extract(expr, v1->SL, v1->NbSL, v2->SL, &v2->NbSL, v2->VL, &v2->NbVL, v1->NbTimeStep, 2, 1);
  extract(expr, v1->VL, v1->NbVL, v2->SL, &v2->NbSL, v2->VL, &v2->NbVL, v1->NbTimeStep, 2, 3);
  extract(expr, v1->TL, v1->NbTL, v2->SL, &v2->NbSL, v2->VL, &v2->NbVL, v1->NbTimeStep, 2, 9);
  // triangles			                                  
  extract(expr, v1->ST, v1->NbST, v2->ST, &v2->NbST, v2->VT, &v2->NbVT, v1->NbTimeStep, 3, 1);
  extract(expr, v1->VT, v1->NbVT, v2->ST, &v2->NbST, v2->VT, &v2->NbVT, v1->NbTimeStep, 3, 3);
  extract(expr, v1->TT, v1->NbTT, v2->ST, &v2->NbST, v2->VT, &v2->NbVT, v1->NbTimeStep, 3, 9);
  // quadrangles		                                  
  extract(expr, v1->SQ, v1->NbSQ, v2->SQ, &v2->NbSQ, v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 1);
  extract(expr, v1->VQ, v1->NbVQ, v2->SQ, &v2->NbSQ, v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 3);
  extract(expr, v1->TQ, v1->NbTQ, v2->SQ, &v2->NbSQ, v2->VQ, &v2->NbVQ, v1->NbTimeStep, 4, 9);
  // tets			                                  
  extract(expr, v1->SS, v1->NbSS, v2->SS, &v2->NbSS, v2->VS, &v2->NbVS, v1->NbTimeStep, 4, 1);
  extract(expr, v1->VS, v1->NbVS, v2->SS, &v2->NbSS, v2->VS, &v2->NbVS, v1->NbTimeStep, 4, 3);
  extract(expr, v1->TS, v1->NbTS, v2->SS, &v2->NbSS, v2->VS, &v2->NbVS, v1->NbTimeStep, 4, 9);
  // hexas			                                  
  extract(expr, v1->SH, v1->NbSH, v2->SH, &v2->NbSH, v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 1);
  extract(expr, v1->VH, v1->NbVH, v2->SH, &v2->NbSH, v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 3);
  extract(expr, v1->TH, v1->NbTH, v2->SH, &v2->NbSH, v2->VH, &v2->NbVH, v1->NbTimeStep, 8, 9);
  // prisms			                                  
  extract(expr, v1->SI, v1->NbSI, v2->SI, &v2->NbSI, v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 1);
  extract(expr, v1->VI, v1->NbVI, v2->SI, &v2->NbSI, v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 3);
  extract(expr, v1->TI, v1->NbTI, v2->SI, &v2->NbSI, v2->VI, &v2->NbVI, v1->NbTimeStep, 6, 9);
  // pyramids			                                  
  extract(expr, v1->SY, v1->NbSY, v2->SY, &v2->NbSY, v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 1);
  extract(expr, v1->VY, v1->NbVY, v2->SY, &v2->NbSY, v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 3);
  extract(expr, v1->TY, v1->NbTY, v2->SY, &v2->NbSY, v2->VY, &v2->NbVY, v1->NbTimeStep, 5, 9);

  // copy time data
  for(int i = 0; i < List_Nbr(v1->Time); i++)
    List_Add(v2->Time, List_Pointer(v1->Time, i));
  // finalize
  char name[1024], filename[1024];
  sprintf(name, "%s_Extract", v1->Name);
  sprintf(filename, "%s_Extract.pos", v1->Name);
  EndView(v2, 1, filename, name);
  return v2;
}

// $Id: Extract.cpp,v 1.29 2008-05-04 08:31:23 geuzaine Exp $
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

#include "Extract.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

StringXNumber ExtractOptions_Number[] = {
  {GMSH_FULLRC, "TimeStep", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString ExtractOptions_String[] = {
#if defined(HAVE_MATH_EVAL)
  {GMSH_FULLRC, "Expression0", NULL, "Sqrt(v0^2+v1^2+v2^2)"},
#else
  {GMSH_FULLRC, "Expression0", NULL, "v0"},
#endif
  {GMSH_FULLRC, "Expression1", NULL, ""},
  {GMSH_FULLRC, "Expression2", NULL, ""},
  {GMSH_FULLRC, "Expression3", NULL, ""},
  {GMSH_FULLRC, "Expression4", NULL, ""},
  {GMSH_FULLRC, "Expression5", NULL, ""},
  {GMSH_FULLRC, "Expression6", NULL, ""},
  {GMSH_FULLRC, "Expression7", NULL, ""},
  {GMSH_FULLRC, "Expression8", NULL, ""}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractPlugin()
  {
    return new GMSH_ExtractPlugin();
  }
}

void GMSH_ExtractPlugin::getName(char *name) const
{
  strcpy(name, "Extract");
}

void GMSH_ExtractPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Extract) extracts a combination of\n"
         "components from the `TimeStep'th time step\n"
         "in the view `iView'. If only `Expression0' is\n"
         "given (and `Expression1', ..., `Expression8' are\n"
         "all empty), the plugin creates a scalar view.\n"
         "If `Expression0', `Expression1' and/or\n"
         "`Expression2' are given (and `Expression3',\n"
         "..., `Expression8' are all empty) the plugin\n"
         "creates a vector view. Otherwise the plugin\n"
         "creates a tensor view. In addition to the usual\n"
         "mathematical functions (Exp, Log, Sqrt, Sin, Cos,\n"
         "Fabs, etc.) and operators (+, -, *, /, ^), all\n"
         "expressions can contain the symbols v0, v1, v2,\n"
         " ..., vn, which represent the n components of the\n"
         "field, and the symbols x, y and z, which represent\n"
         "the three spatial coordinates. If `TimeStep' < 0,\n"
         "the plugin extracts data from all the time steps\n"
         "in the view. If `iView' < 0, the plugin is run on\n"
         "the current view.\n"
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

static void extract(const char *expr[9], List_T *inList, int inNb, 
                    List_T *outListScalar, int *outNbScalar, 
                    List_T *outListVector, int *outNbVector, 
                    List_T *outListTensor, int *outNbTensor, 
                    int timeStep, int nbNod, int nbComp)
{
  if(!inNb)
    return;

  int outNbComp, *outNb;
  List_T *outList;

  if(strlen(expr[3]) || strlen(expr[4]) || strlen(expr[5]) || 
     strlen(expr[6]) || strlen(expr[7]) || strlen(expr[8])){
    outNbComp = 9;
    outNb = outNbTensor;
    outList = outListTensor;
    for(int i = 0; i < 9; i++)
      if(!strlen(expr[i])) expr[i] = "0";
  }
  else if(strlen(expr[1]) || strlen(expr[2])){
    outNbComp = 3;
    outNb = outNbVector;
    outList = outListVector;
    for(int i = 0; i < 3; i++)
      if(!strlen(expr[i])) expr[i] = "0";
  }
  else{
    outNbComp = 1;
    outNb = outNbScalar;
    outList = outListScalar;
  }

  // if we have MathEval, we can evaluate arbitrary expressions;
  // otherwise, we only allow to extract single components

#if defined(HAVE_MATH_EVAL)
  void *f[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  for(int i = 0; i < outNbComp; i++){
    f[i] = evaluator_create((char*)expr[i]);
    if(!f[i]){
      Msg::Error("Invalid expression '%s'", expr[i]);
      for(int j = 0; j < i; j++)
        if(f[j]) evaluator_destroy(f[j]);
      return;
    }
  }
#else
  int comp[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
      Msg::Error("Invalid expression '%s'", expr[i]);
      return;
    }
  }
#endif

  int timeBeg = (timeStep < 0) ? 0 : timeStep;
  int timeEnd = (timeStep < 0) ? -timeStep : timeStep + 1;

  int nb = List_Nbr(inList) / inNb;
  for(int i = 0; i < List_Nbr(inList); i += nb) {
    double *x = (double *)List_Pointer_Fast(inList, i);
    double *y = (double *)List_Pointer_Fast(inList, i + nbNod);
    double *z = (double *)List_Pointer_Fast(inList, i + 2 * nbNod);
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(outList, List_Pointer_Fast(inList, i + j));
    for(int j = timeBeg; j < timeEnd; j++){
      for(int k = 0; k < nbNod; k++){
        double xx = x[k];
        double yy = y[k];
        double zz = z[k];
        double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
        for(int l = 0; l < nbComp; l++)
          List_Read(inList, i + 3 * nbNod + nbNod * nbComp * j + nbComp * k + l, &d[l]);
        for(int l = 0; l < outNbComp; l++){
#if defined(HAVE_MATH_EVAL)
          char *names[] = { "x", "y", "z", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" };
          double values[] = { xx, yy, zz, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7], d[8] };
          double res = evaluator_evaluate(f[l], sizeof(names)/sizeof(names[0]), names, values);
#else
          double res = d[comp[l]];
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

PView *GMSH_ExtractPlugin::execute(PView *v)
{
  int step = (int)ExtractOptions_Number[0].def;
  int iView = (int)ExtractOptions_Number[1].def;
  const char *expr[9] = { ExtractOptions_String[0].def, 
                          ExtractOptions_String[1].def,
                          ExtractOptions_String[2].def,
                          ExtractOptions_String[3].def,
                          ExtractOptions_String[4].def,
                          ExtractOptions_String[5].def,
                          ExtractOptions_String[6].def,
                          ExtractOptions_String[7].def,
                          ExtractOptions_String[8].def };

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  if(step < 0){
    step = - data1->getNumTimeSteps();
  }
  else if(step > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using all steps instead",
        step, v1->getIndex());
    step = - data1->getNumTimeSteps();
  }

  // points
  extract(expr, data1->SP, data1->NbSP, data2->SP, &data2->NbSP, 
          data2->VP, &data2->NbVP, data2->TP, &data2->NbTP, step, 1, 1);
  extract(expr, data1->VP, data1->NbVP, data2->SP, &data2->NbSP,
          data2->VP, &data2->NbVP, data2->TP, &data2->NbTP, step, 1, 3);
  extract(expr, data1->TP, data1->NbTP, data2->SP, &data2->NbSP,
          data2->VP, &data2->NbVP, data2->TP, &data2->NbTP, step, 1, 9);
  // lines                                                                              
  extract(expr, data1->SL, data1->NbSL, data2->SL, &data2->NbSL,
          data2->VL, &data2->NbVL, data2->TL, &data2->NbTL, step, 2, 1);
  extract(expr, data1->VL, data1->NbVL, data2->SL, &data2->NbSL,
          data2->VL, &data2->NbVL, data2->TL, &data2->NbTL, step, 2, 3);
  extract(expr, data1->TL, data1->NbTL, data2->SL, &data2->NbSL,
          data2->VL, &data2->NbVL, data2->TL, &data2->NbTL, step, 2, 9);
  // triangles                                                                          
  extract(expr, data1->ST, data1->NbST, data2->ST, &data2->NbST,
          data2->VT, &data2->NbVT, data2->TT, &data2->NbTT, step, 3, 1);
  extract(expr, data1->VT, data1->NbVT, data2->ST, &data2->NbST,
          data2->VT, &data2->NbVT, data2->TT, &data2->NbTT, step, 3, 3);
  extract(expr, data1->TT, data1->NbTT, data2->ST, &data2->NbST,
          data2->VT, &data2->NbVT, data2->TT, &data2->NbTT, step, 3, 9);
  // quadrangles                                                                        
  extract(expr, data1->SQ, data1->NbSQ, data2->SQ, &data2->NbSQ,
          data2->VQ, &data2->NbVQ, data2->TQ, &data2->NbTQ, step, 4, 1);
  extract(expr, data1->VQ, data1->NbVQ, data2->SQ, &data2->NbSQ,
          data2->VQ, &data2->NbVQ, data2->TQ, &data2->NbTQ, step, 4, 3);
  extract(expr, data1->TQ, data1->NbTQ, data2->SQ, &data2->NbSQ,
          data2->VQ, &data2->NbVQ, data2->TQ, &data2->NbTQ, step, 4, 9);
  // tets                                                                               
  extract(expr, data1->SS, data1->NbSS, data2->SS, &data2->NbSS,
          data2->VS, &data2->NbVS, data2->TS, &data2->NbTS, step, 4, 1);
  extract(expr, data1->VS, data1->NbVS, data2->SS, &data2->NbSS,
          data2->VS, &data2->NbVS, data2->TS, &data2->NbTS, step, 4, 3);
  extract(expr, data1->TS, data1->NbTS, data2->SS, &data2->NbSS,
          data2->VS, &data2->NbVS, data2->TS, &data2->NbTS, step, 4, 9);
  // hexas                                                                              
  extract(expr, data1->SH, data1->NbSH, data2->SH, &data2->NbSH,
          data2->VH, &data2->NbVH, data2->TH, &data2->NbTH, step, 8, 1);
  extract(expr, data1->VH, data1->NbVH, data2->SH, &data2->NbSH,
          data2->VH, &data2->NbVH, data2->TH, &data2->NbTH, step, 8, 3);
  extract(expr, data1->TH, data1->NbTH, data2->SH, &data2->NbSH,
          data2->VH, &data2->NbVH, data2->TH, &data2->NbTH, step, 8, 9);
  // prisms                                                                             
  extract(expr, data1->SI, data1->NbSI, data2->SI, &data2->NbSI,
          data2->VI, &data2->NbVI, data2->TI, &data2->NbTI, step, 6, 1);
  extract(expr, data1->VI, data1->NbVI, data2->SI, &data2->NbSI,
          data2->VI, &data2->NbVI, data2->TI, &data2->NbTI, step, 6, 3);
  extract(expr, data1->TI, data1->NbTI, data2->SI, &data2->NbSI,
          data2->VI, &data2->NbVI, data2->TI, &data2->NbTI, step, 6, 9);
  // pyramids                                                                           
  extract(expr, data1->SY, data1->NbSY, data2->SY, &data2->NbSY,
          data2->VY, &data2->NbVY, data2->TY, &data2->NbTY, step, 5, 1);
  extract(expr, data1->VY, data1->NbVY, data2->SY, &data2->NbSY,
          data2->VY, &data2->NbVY, data2->TY, &data2->NbTY, step, 5, 3);
  extract(expr, data1->TY, data1->NbTY, data2->SY, &data2->NbSY,
          data2->VY, &data2->NbVY, data2->TY, &data2->NbTY, step, 5, 9);

  if(step < 0)
    for(int i = 0; i < List_Nbr(data1->Time); i++)
      List_Add(data2->Time, List_Pointer(data1->Time, i));
  else
    List_Add(data2->Time, List_Pointer(data1->Time, step));

  data2->setName(data1->getName() + "_Extract");
  data2->setFileName(data1->getName() + "_Extract.pos");
  data2->finalize();

  return v2;
}

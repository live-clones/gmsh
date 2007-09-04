// $Id: FieldView.cpp,v 1.2 2007-09-04 13:47:05 remacle Exp $
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
#include "Field.h"
#include "FieldView.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"
#include "ShapeFunctions.h"

extern Context_T CTX;

StringXNumber FieldViewOptions_Number[] = {
  {GMSH_FULLRC, "Component", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "Field", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFieldViewPlugin()
  {
    return new GMSH_FieldViewPlugin();
  }
}

GMSH_FieldViewPlugin::GMSH_FieldViewPlugin()
{
  ;
}

void GMSH_FieldViewPlugin::getName(char *name) const
{
  strcpy(name, "FieldView");
}

void GMSH_FieldViewPlugin::getInfos(char *author, char *copyright,
				    char *help_text) const
{
  strcpy(author, "J. Lambrechts (jonathanlambrechts@gmail.org)");
  strcpy(copyright, "GPL");
  strcpy(help_text,
	 "Plugin(FieldView) evaluate a field on the choosen view.\n");
}

int GMSH_FieldViewPlugin::getNbOptions() const
{
  return sizeof(FieldViewOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_FieldViewPlugin::getOption(int iopt)
{
  return &FieldViewOptions_Number[iopt];
}

void GMSH_FieldViewPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "FieldView failed...");
}


static void evaluate(Field *field,Post_View *v1, List_T *list1, int nbElm1, int nbNod, int nbComp, int comp )
{
  if(!nbElm1)
    return;
  v1->Changed = 1;
  int nb = List_Nbr(list1) / nbElm1;
  for(int i = 0, i2 = 0; i < List_Nbr(list1); i += nb) {
    double *x = (double *)List_Pointer_Fast(list1, i);
    double *y = (double *)List_Pointer_Fast(list1, i + nbNod);
    double *z = (double *)List_Pointer_Fast(list1, i + 2 * nbNod);
    for(int j = 0; j < nbNod; j++) {
      // store data from the main view into v
      double *val1 = (double *)List_Pointer_Fast(list1, 
						 i + 3 * nbNod + 
						 nbNod * nbComp * 0 + nbComp * j);
      val1[comp] =(*field)(x[j],y[j],z[j]);
    }
  }
}


Post_View *GMSH_FieldViewPlugin::execute(Post_View * v)
{
  int comp = (int)FieldViewOptions_Number[0].def;
  int iView = (int)FieldViewOptions_Number[1].def;
	int iField=(int)FieldViewOptions_Number[2].def;
	Field *field=fields.get(iField);
  if(!field){
    Msg(GERROR, "Field[%d] does not exist", iField);
    return v;
	}
  if(iView < 0)
    iView = v ? v->Index : 0;
  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }
  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
      evaluate(field, v1, v1->SP, v1->NbSP, 1, 1, 0);
      evaluate(field, v1, v1->SL, v1->NbSL, 2, 1, 0);
      evaluate(field, v1, v1->ST, v1->NbST, 3, 1, 0);
      evaluate(field, v1, v1->SQ, v1->NbSQ, 4, 1, 0);      
      evaluate(field, v1, v1->SS, v1->NbSS, 4, 1, 0);
      evaluate(field, v1, v1->SH, v1->NbSH, 8, 1, 0);      
      evaluate(field, v1, v1->SI, v1->NbSI, 6, 1, 0);
      evaluate(field, v1, v1->SY, v1->NbSY, 5, 1, 0);

      for(int cc = 0; cc < 3; cc++){
	if(comp < 0 || comp == cc){
	  evaluate(field, v1, v1->VP, v1->NbVP, 1, 3, cc);
	  evaluate(field, v1, v1->VL, v1->NbVL, 2, 3, cc);
	  evaluate(field, v1, v1->VT, v1->NbVT, 3, 3, cc);
	  evaluate(field, v1, v1->VQ, v1->NbVQ, 4, 3, cc);
	  evaluate(field, v1, v1->VS, v1->NbVS, 4, 3, cc);
	  evaluate(field, v1, v1->VH, v1->NbVH, 8, 3, cc);
	  evaluate(field, v1, v1->VI, v1->NbVI, 6, 3, cc);
	  evaluate(field, v1, v1->VY, v1->NbVY, 5, 3, cc);
	}
      }

      for(int cc = 0; cc < 9; cc++){
	if(comp < 0 || comp == cc){
	  evaluate(field, v1, v1->TP, v1->NbTP, 1, 9, cc);
	  evaluate(field, v1, v1->TL, v1->NbTL, 2, 9, cc);
	  evaluate(field, v1, v1->TT, v1->NbTT, 3, 9, cc);      
	  evaluate(field, v1, v1->TQ, v1->NbTQ, 4, 9, cc);
	  evaluate(field, v1, v1->TS, v1->NbTS, 4, 9, cc);
	  evaluate(field, v1, v1->TH, v1->NbTH, 8, 9, cc);
	  evaluate(field, v1, v1->TI, v1->NbTI, 6, 9, cc);
	  evaluate(field, v1, v1->TY, v1->NbTY, 5, 9, cc);
	}
      }
  // recompute min/max, etc.:
  v1->Min = VAL_INF;
  v1->Max = -VAL_INF;
  EndView(v1, 0, v1->FileName, v1->Name);

  return v1;
}

// $Id: FieldView.cpp,v 1.3 2007-09-11 14:01:55 geuzaine Exp $
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

#include "FieldView.h"
#include "Field.h"

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

static void evaluate(Field *field, List_T *list1, int nbElm1, int nbNod, 
		     int nbComp, int comp )
{
  if(!nbElm1) return;
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
      val1[comp] = (*field)(x[j],y[j],z[j]);
    }
  }
}

PView *GMSH_FieldViewPlugin::execute(PView *v)
{
  int comp = (int)FieldViewOptions_Number[0].def;
  int iView = (int)FieldViewOptions_Number[1].def;
  int iField = (int)FieldViewOptions_Number[2].def;

  Field *field = fields.get(iField);
  if(!field){
    Msg(GERROR, "Field[%d] does not exist", iField);
    return v;
  }

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  evaluate(field, data1->SP, data1->NbSP, 1, 1, 0);
  evaluate(field, data1->SL, data1->NbSL, 2, 1, 0);
  evaluate(field, data1->ST, data1->NbST, 3, 1, 0);
  evaluate(field, data1->SQ, data1->NbSQ, 4, 1, 0);      
  evaluate(field, data1->SS, data1->NbSS, 4, 1, 0);
  evaluate(field, data1->SH, data1->NbSH, 8, 1, 0);      
  evaluate(field, data1->SI, data1->NbSI, 6, 1, 0);
  evaluate(field, data1->SY, data1->NbSY, 5, 1, 0);

  for(int cc = 0; cc < 3; cc++){
    if(comp < 0 || comp == cc){
      evaluate(field, data1->VP, data1->NbVP, 1, 3, cc);
      evaluate(field, data1->VL, data1->NbVL, 2, 3, cc);
      evaluate(field, data1->VT, data1->NbVT, 3, 3, cc);
      evaluate(field, data1->VQ, data1->NbVQ, 4, 3, cc);
      evaluate(field, data1->VS, data1->NbVS, 4, 3, cc);
      evaluate(field, data1->VH, data1->NbVH, 8, 3, cc);
      evaluate(field, data1->VI, data1->NbVI, 6, 3, cc);
      evaluate(field, data1->VY, data1->NbVY, 5, 3, cc);
    }
  }
  
  for(int cc = 0; cc < 9; cc++){
    if(comp < 0 || comp == cc){
      evaluate(field, data1->TP, data1->NbTP, 1, 9, cc);
      evaluate(field, data1->TL, data1->NbTL, 2, 9, cc);
      evaluate(field, data1->TT, data1->NbTT, 3, 9, cc);      
      evaluate(field, data1->TQ, data1->NbTQ, 4, 9, cc);
      evaluate(field, data1->TS, data1->NbTS, 4, 9, cc);
      evaluate(field, data1->TH, data1->NbTH, 8, 9, cc);
      evaluate(field, data1->TI, data1->NbTI, 6, 9, cc);
      evaluate(field, data1->TY, data1->NbTY, 5, 9, cc);
    }
  }
  
  data1->finalize();
  v1->setChanged(true);

  return v1;
}

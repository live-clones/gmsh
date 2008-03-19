// $Id: FieldView.cpp,v 1.7 2008-03-19 17:26:54 geuzaine Exp $
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

#include "FieldView.h"
#include "Field.h"
#include "GModel.h"

StringXNumber FieldViewOptions_Number[] = {
  {GMSH_FULLRC, "Component", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "iField", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFieldViewPlugin()
  {
    return new GMSH_FieldViewPlugin();
  }
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

PView *GMSH_FieldViewPlugin::execute(PView *v)
{
  int comp = (int)FieldViewOptions_Number[0].def;
  int iView = (int)FieldViewOptions_Number[1].def;
  int iField = (int)FieldViewOptions_Number[2].def;
  Field *field = GModel::current()->getFields()->get(iField);
  if(!field){
    Msg(GERROR, "Field[%d] does not exist", iField);
    return v;
  }
  PView *v1 = getView(iView, v);
  if(!v1) return v;
	field->put_on_view(v1);
  return v1;
}

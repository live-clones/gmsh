// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
  strcpy(author, "J. Lambrechts");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(FieldView) evaluates a field on the choosen view.\n");
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
  //int comp = (int)FieldViewOptions_Number[0].def;
  int iView = (int)FieldViewOptions_Number[1].def;
  int iField = (int)FieldViewOptions_Number[2].def;
  Field *field = GModel::current()->getFields()->get(iField);
  if(!field){
    Msg::Error("Field[%d] does not exist", iField);
    return v;
  }
  PView *v1 = getView(iView, v);
  if(!v1) return v;
        field->put_on_view(v1);
  return v1;
}

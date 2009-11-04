// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "FieldView.h"
#include "GModel.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

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

std::string GMSH_FieldViewPlugin::getHelp() const
{
  return "Plugin(FieldView) evaluates a field on the choosen view.\n";
}

int GMSH_FieldViewPlugin::getNbOptions() const
{
  return sizeof(FieldViewOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_FieldViewPlugin::getOption(int iopt)
{
  return &FieldViewOptions_Number[iopt];
}

PView *GMSH_FieldViewPlugin::execute(PView *v)
{
#if defined(HAVE_MESH)
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
  field->putOnView(v1);
  return v1;
#else
  Msg::Error("FieldView plugin requires the mesh module");
  return v;
#endif
}

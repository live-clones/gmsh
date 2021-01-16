// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "Invisible.h"

StringXNumber InvisibleOptions_Number[] = {
  {GMSH_FULLRC, "DeleteElements", nullptr, 1.},
  {GMSH_FULLRC, "ReverseElements", nullptr, 0.},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterInvisiblePlugin()
{
  return new GMSH_InvisiblePlugin();
}
}

std::string GMSH_InvisiblePlugin::getHelp() const
{
  return "Plugin(Invisible) deletes (if `DeleteElements' is set) or "
         "reverses (if `ReverseElements' is set) all the invisible elements in "
         "the current model.";
}

int GMSH_InvisiblePlugin::getNbOptions() const
{
  return sizeof(InvisibleOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_InvisiblePlugin::getOption(int iopt)
{
  return &InvisibleOptions_Number[iopt];
}

PView *GMSH_InvisiblePlugin::execute(PView *v)
{
  if(InvisibleOptions_Number[0].def)
    GModel::current()->removeInvisibleElements();
  if(InvisibleOptions_Number[1].def)
    GModel::current()->reverseInvisibleElements();

  return nullptr;
}

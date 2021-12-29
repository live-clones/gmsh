// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Smooth.h"

StringXNumber SmoothOptions_Number[] = {{GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterSmoothPlugin() { return new GMSH_SmoothPlugin(); }
}

std::string GMSH_SmoothPlugin::getHelp() const
{
  return "Plugin(Smooth) averages the values at the nodes "
         "of the view `View'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Smooth) is executed in-place.";
}

int GMSH_SmoothPlugin::getNbOptions() const
{
  return sizeof(SmoothOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SmoothPlugin::getOption(int iopt)
{
  return &SmoothOptions_Number[iopt];
}

PView *GMSH_SmoothPlugin::execute(PView *v)
{
  int iView = (int)SmoothOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  v1->getData()->smooth();
  v1->setChanged(true);

  return v1;
}

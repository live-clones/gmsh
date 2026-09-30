// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Smooth.h"

GMSH_SmoothPlugin::GMSH_SmoothPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_SmoothPlugin::getHelp() const
{
  return "Plugin(Smooth) averages the values at the nodes "
         "of the view `View'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Smooth) is executed in-place.";
}

PView *GMSH_SmoothPlugin::execute(PView *v)
{
  int iView = (int)option(0);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  v1->getData()->smooth();
  v1->setChanged(true);

  return v1;
}

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "SphericalRaise.h"
#include "Numeric.h"

GMSH_SphericalRaisePlugin::GMSH_SphericalRaisePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Xc", nullptr, 0., ""},
                     {GMSH_FULLRC, "Yc", nullptr, 0., ""},
                     {GMSH_FULLRC, "Zc", nullptr, 0., ""},
                     {GMSH_FULLRC, "Raise", nullptr, 1., ""},
                     {GMSH_FULLRC, "Offset", nullptr, 0., ""},
                     {GMSH_FULLRC, "TimeStep", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_SphericalRaisePlugin::getHelp() const
{
  return "Plugin(SphericalRaise) transforms the "
         "coordinates of the elements in the view "
         "`View' using the values associated with the "
         "`TimeStep'-th time step.\n\n"
         "Instead of elevating the nodes along the X, Y "
         "and Z axes as with the View[`View'].RaiseX, "
         "View[`View'].RaiseY and View[`View'].RaiseZ "
         "options, the raise is applied along the radius "
         "of a sphere centered at (`Xc', `Yc', `Zc').\n\n"
         "To produce a standard radiation pattern, set "
         "`Offset' to minus the radius of the sphere the "
         "original data lives on.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(SphericalRaise) is executed in-place.";
}

PView *GMSH_SphericalRaisePlugin::execute(PView *v)
{
  double center[3];
  center[0] = option(0);
  center[1] = option(1);
  center[2] = option(2);
  double raise = option(3);
  double offset = option(4);
  int timeStep = (int)option(5);
  int iView = (int)option(6);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  // sanity checks
  if(timeStep < 0 || timeStep > data1->getNumTimeSteps() - 1) {
    Msg::Error("Invalid TimeStep (%d) in view", timeStep);
    return v;
  }

  forEachNode(data1, [&](int step, int ent, int ele, int nod) {
    double x, y, z, val;
    data1->getNode(step, ent, ele, nod, x, y, z);
    double r[3] = {x - center[0], y - center[1], z - center[2]};
    norme(r);
    if(!data1->hasTimeStep(timeStep) ||
       data1->skipElement(timeStep, ent, ele))
      return;
    data1->getScalarValue(timeStep, ent, ele, nod, val);
    double coef = offset + raise * val;
    data1->setNode(step, ent, ele, nod, x + coef * r[0], y + coef * r[1],
                   z + coef * r[2]);
  });

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "SphericalRaise.h"
#include "Numeric.h"

StringXNumber SphericalRaiseOptions_Number[] = {
  {GMSH_FULLRC, "Xc", NULL, 0.},
  {GMSH_FULLRC, "Yc", NULL, 0.},
  {GMSH_FULLRC, "Zc", NULL, 0.},
  {GMSH_FULLRC, "Raise", NULL, 1.},
  {GMSH_FULLRC, "Offset", NULL, 0.},
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "View", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSphericalRaisePlugin()
  {
    return new GMSH_SphericalRaisePlugin();
  }
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

int GMSH_SphericalRaisePlugin::getNbOptions() const
{
  return sizeof(SphericalRaiseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SphericalRaisePlugin::getOption(int iopt)
{
  return &SphericalRaiseOptions_Number[iopt];
}

PView *GMSH_SphericalRaisePlugin::execute(PView *v)
{
  double center[3];
  center[0] = SphericalRaiseOptions_Number[0].def;
  center[1] = SphericalRaiseOptions_Number[1].def;
  center[2] = SphericalRaiseOptions_Number[2].def;
  double raise = SphericalRaiseOptions_Number[3].def;
  double offset = SphericalRaiseOptions_Number[4].def;
  int timeStep = (int)SphericalRaiseOptions_Number[5].def;
  int iView = (int)SphericalRaiseOptions_Number[6].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  // sanity checks
  if(timeStep < 0 || timeStep > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid TimeStep (%d) in view", timeStep);
    return v;
  }

  // tag all the nodes with "0" (the default tag)
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
        if(data1->skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++)
          data1->tagNode(step, ent, ele, nod, 0);
      }
    }
  }

  // transform all "0" nodes
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
        if(data1->skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
          double x, y, z;
          int tag = data1->getNode(step, ent, ele, nod, x, y, z);
          if(!tag){
            double r[3], val;
            r[0] = x - center[0];
            r[1] = y - center[1];
            r[2] = z - center[2];
            norme(r);
            data1->getScalarValue(step, ent, ele, nod, val);
            double coef = offset + raise * val;
            x += coef * r[0];
            y += coef * r[1];
            z += coef * r[2];
            data1->setNode(step, ent, ele, nod, x, y, z);
            data1->tagNode(step, ent, ele, nod, 1);
          }
        }
      }
    }
  }

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

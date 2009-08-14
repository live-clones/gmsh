// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSphericalRaisePlugin()
  {
    return new GMSH_SphericalRaisePlugin();
  }
}

void GMSH_SphericalRaisePlugin::getName(char *name) const
{
  strcpy(name, "Spherical Raise");
}

void GMSH_SphericalRaisePlugin::getInfos(char *author, char *copyright,
                                         char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(SphericalRaise) transforms the\n"
         "coordinates of the elements in the view\n"
         "`iView' using the values associated with the\n"
         "`TimeStep'-th time step. Instead of elevating\n"
         "the nodes along the X, Y and Z axes as in\n"
         "View[`iView'].RaiseX, View[`iView'].RaiseY\n"
         "and View[`iView'].RaiseZ, the raise is applied\n"
         " along the radius of a sphere centered at\n"
         "(`Xc', `Yc', `Zc'). To produce a standard\n"
         "radiation pattern, set `Offset' to minus the\n"
         "radius of the sphere the original data lives on.\n"
         "If `iView' < 0, the plugin is run on the current\n"
         "view.\n"
         "\n"
         "Plugin(SphericalRaise) is executed in-place.\n");
}

int GMSH_SphericalRaisePlugin::getNbOptions() const
{
  return sizeof(SphericalRaiseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SphericalRaisePlugin::getOption(int iopt)
{
  return &SphericalRaiseOptions_Number[iopt];
}

void GMSH_SphericalRaisePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "SphericalRaise failed...");
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

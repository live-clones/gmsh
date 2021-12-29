// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "ModulusPhase.h"

StringXNumber ModulusPhaseOptions_Number[] = {
  {GMSH_FULLRC, "RealPart", nullptr, 0.},
  {GMSH_FULLRC, "ImaginaryPart", nullptr, 1.},
  {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterModulusPhasePlugin()
{
  return new GMSH_ModulusPhasePlugin();
}
}

std::string GMSH_ModulusPhasePlugin::getHelp() const
{
  return "Plugin(ModulusPhase) interprets the time steps "
         "`realPart' and `imaginaryPart' in the view `View' "
         "as the real and imaginary parts of a complex field "
         "and replaces them with their corresponding "
         "modulus and phase.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(ModulusPhase) is executed in-place.";
}

int GMSH_ModulusPhasePlugin::getNbOptions() const
{
  return sizeof(ModulusPhaseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ModulusPhasePlugin::getOption(int iopt)
{
  return &ModulusPhaseOptions_Number[iopt];
}

PView *GMSH_ModulusPhasePlugin::execute(PView *v)
{
  int rIndex = (int)ModulusPhaseOptions_Number[0].def;
  int iIndex = (int)ModulusPhaseOptions_Number[1].def;
  int iView = (int)ModulusPhaseOptions_Number[2].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()) {
    Msg::Error("ModulusPhase plugin cannot be run on multi-mesh views");
    return v;
  }

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() || iIndex < 0 ||
     iIndex >= data1->getNumTimeSteps()) {
    Msg::Error("Wrong real or imaginary part index");
    return v1;
  }

  if(data1->isNodeData()) {
    // tag all the nodes with "0" (the default tag)
    for(int step = 0; step < data1->getNumTimeSteps(); step++) {
      for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
        for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
          if(data1->skipElement(step, ent, ele)) continue;
          for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++)
            data1->tagNode(step, ent, ele, nod, 0);
        }
      }
    }
  }

  // transform all "0" nodes
  for(int ent = 0; ent < data1->getNumEntities(rIndex); ent++) {
    for(int ele = 0; ele < data1->getNumElements(rIndex, ent); ele++) {
      if(data1->skipElement(rIndex, ent, ele)) continue;
      for(int nod = 0; nod < data1->getNumNodes(rIndex, ent, ele); nod++) {
        double x, y, z;
        int tag = data1->getNode(rIndex, ent, ele, nod, x, y, z);
        if(data1->isNodeData() && tag) continue;
        for(int comp = 0; comp < data1->getNumComponents(rIndex, ent, ele);
            comp++) {
          double vr, vi;
          data1->getValue(rIndex, ent, ele, nod, comp, vr);
          data1->getValue(iIndex, ent, ele, nod, comp, vi);
          double modulus = sqrt(vr * vr + vi * vi);
          double phase = atan2(vi, vr);
          data1->setValue(rIndex, ent, ele, nod, comp, modulus);
          data1->setValue(iIndex, ent, ele, nod, comp, phase);
          if(data1->isNodeData()) {
            data1->tagNode(rIndex, ent, ele, nod, 1);
            data1->tagNode(iIndex, ent, ele, nod, 1);
          }
        }
      }
    }
  }

  data1->setName(data1->getName() + "_ModulusPhase");
  data1->setName(data1->getName() + ".pos");
  data1->finalize();

  v1->setChanged(true);
  return v1;
}

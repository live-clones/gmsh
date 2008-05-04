// $Id: ModulusPhase.cpp,v 1.11 2008-05-04 08:31:23 geuzaine Exp $
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

#include "ModulusPhase.h"

StringXNumber ModulusPhaseOptions_Number[] = {
  {GMSH_FULLRC, "RealPart", NULL, 0.},
  {GMSH_FULLRC, "ImaginaryPart", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterModulusPhasePlugin()
  {
    return new GMSH_ModulusPhasePlugin();
  }
}

void GMSH_ModulusPhasePlugin::getName(char *name) const
{
  strcpy(name, "Modulus Phase");
}

void GMSH_ModulusPhasePlugin::getInfos(char *author, char *copyright,
                                        char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(ModulusPhase) interprets the time steps\n"
         "`realPart' and `imaginaryPart' in the view `iView'\n"
         "as the real and imaginary parts of a complex field\n"
         "and replaces them with their corresponding\n"
         "modulus and phase. If `iView' < 0, the plugin is\n"
         "run on the current view.\n"
         "\n"
         "Plugin(ModulusPhase) is executed in-place.\n");
}

int GMSH_ModulusPhasePlugin::getNbOptions() const
{
  return sizeof(ModulusPhaseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ModulusPhasePlugin::getOption(int iopt)
{
  return &ModulusPhaseOptions_Number[iopt];
}

void GMSH_ModulusPhasePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "ModulusPhase failed...");
}

PView *GMSH_ModulusPhasePlugin::execute(PView *v)
{
  int rIndex = (int)ModulusPhaseOptions_Number[0].def;
  int iIndex = (int)ModulusPhaseOptions_Number[1].def;
  int iView = (int)ModulusPhaseOptions_Number[2].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Gradient plugin cannot be run on multi-mesh views");
    return v;
  }

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() ||
     iIndex < 0 || iIndex >= data1->getNumTimeSteps()){
    Msg::Error("Wrong real or imaginary part index");
    return v1;
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
  for(int ent = 0; ent < data1->getNumEntities(rIndex); ent++){
    for(int ele = 0; ele < data1->getNumElements(rIndex, ent); ele++){
      if(data1->skipElement(rIndex, ent, ele)) continue;
      for(int nod = 0; nod < data1->getNumNodes(rIndex, ent, ele); nod++){
	double x, y, z;
	int tag = data1->getNode(rIndex, ent, ele, nod, x, y, z);
	if(tag) continue;
	for(int comp = 0; comp < data1->getNumComponents(rIndex, ent, ele); comp++){
	  double vr, vi;
	  data1->getValue(rIndex, ent, ele, nod, comp, vr);
	  data1->getValue(iIndex, ent, ele, nod, comp, vi);
	  double modulus = sqrt(vr * vr + vi * vi);
	  double phase = atan2(vi, vr);
	  data1->setValue(rIndex, ent, ele, nod, comp, modulus);
	  data1->setValue(iIndex, ent, ele, nod, comp, phase);
	  data1->tagNode(rIndex, ent, ele, nod, 1);
	  data1->tagNode(iIndex, ent, ele, nod, 1);
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

// $Id: Integrate.cpp,v 1.27 2008-05-12 20:24:05 geuzaine Exp $
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

#include "Integrate.h"
#include "shapeFunctions.h"
#include "PViewOptions.h"

StringXNumber IntegrateOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterIntegratePlugin()
  {
    return new GMSH_IntegratePlugin();
  }
}

GMSH_IntegratePlugin::GMSH_IntegratePlugin()
{
  ;
}

void GMSH_IntegratePlugin::getName(char *name) const
{
  strcpy(name, "Integrate");
}

void GMSH_IntegratePlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Integrate) integrates scalar fields over\n"
         "all the elements in the view `iView', as well\n"
         "as the circulation/flux of vector fields over\n"
         "line/surface elements. If `iView' < 0, the\n"
         "plugin is run on the current view.\n"
         "\n"
         "Plugin(Integrate) creates one new view.\n");
}

int GMSH_IntegratePlugin::getNbOptions() const
{
  return sizeof(IntegrateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_IntegratePlugin::getOption(int iopt)
{
  return &IntegrateOptions_Number[iopt];
}

void GMSH_IntegratePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Integrate failed...");
}

PView *GMSH_IntegratePlugin::execute(PView * v)
{
  int iView = (int)IntegrateOptions_Number[1].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

  PView *v2 = new PView(true);
  PViewDataList *data2 = getDataList(v2);
  
  double x = data1->getBoundingBox().center().x();
  double y = data1->getBoundingBox().center().y();
  double z = data1->getBoundingBox().center().z();
  List_Add(data2->SP, &x);
  List_Add(data2->SP, &y);
  List_Add(data2->SP, &z);
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    double res = 0;
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
	int numComp = data1->getNumComponents(step, ent, ele);
	int numEdges = data1->getNumEdges(step, ent, ele);
	bool scalar = (numComp == 1);
	bool circulation = (numComp == 3 && numEdges == 1);
	bool flux = (numComp == 3 && (numEdges == 3 || numEdges == 4));
	if(!scalar && !circulation && !flux) continue;
	int numNodes = data1->getNumNodes(step, ent, ele);
	int dim = data1->getDimension(step, ent, ele);
	double x[8], y[8], z[8], val[8 * 3];
	for(int nod = 0; nod < numNodes; nod++){
	  data1->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
	  for(int comp = 0; comp < numComp; comp++)
	    data1->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
	}
	elementFactory factory;
	element *element = factory.create(numNodes, dim, x, y, z);
	if(!element) continue;
	if(scalar)
	  res += element->integrate(val);
	else if(circulation)
	  res += element->integrateCirculation(val);
	else if(flux)
	  res += element->integrateFlux(val);
	delete element;
      }
    }
    Msg::Info("Step %d: integral = %.16g", step, res);
    List_Add(data2->SP, &res);
  }
  data2->NbSP = 1;
  v2->getOptions()->IntervalsType = PViewOptions::Numeric;
  
  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    List_Add(data2->Time, &time);
  }
  data2->setName(data1->getName() + "_Integrate");
  data2->setFileName(data1->getName() + "_Integrate.pos");
  data2->finalize();
  
  return v2;
}

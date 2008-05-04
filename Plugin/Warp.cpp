// $Id: Warp.cpp,v 1.16 2008-05-04 08:31:23 geuzaine Exp $
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

#include "Warp.h"
#include "SmoothData.h"
#include "Numeric.h"

StringXNumber WarpOptions_Number[] = {
  {GMSH_FULLRC, "Factor", NULL, 1.},
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "SmoothingAngle", NULL, 180.},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterWarpPlugin()
  {
    return new GMSH_WarpPlugin();
  }
}

void GMSH_WarpPlugin::getName(char *name) const
{
  strcpy(name, "Warp");
}

void GMSH_WarpPlugin::getInfos(char *author, char *copyright,
			       char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Warp) transforms the elements in the\n"
         "view `iView' by adding to their node coordinates\n"
         "the vector field stored in the `TimeStep'-th time\n"
         "step of the view `dView', scaled by `Factor'. If\n"
         "`dView' < 0, the vector field is taken as the field\n"
         "of surface normals multiplied by the `TimeStep'\n"
         "value in `iView'. (The smoothing of the surface\n"
         "normals is controlled by the `SmoothingAngle'\n"
         "parameter.) If `iView' < 0, the plugin is run on\n"
         "the current view.\n"
         "\n"
         "Plugin(Warp) is executed in-place.\n");
}

int GMSH_WarpPlugin::getNbOptions() const
{
  return sizeof(WarpOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_WarpPlugin::getOption(int iopt)
{
  return &WarpOptions_Number[iopt];
}

void GMSH_WarpPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Warp failed...");
}

PView *GMSH_WarpPlugin::execute(PView *v)
{
  double factor = WarpOptions_Number[0].def;
  int TimeStep = (int)WarpOptions_Number[1].def;
  double AngleTol = WarpOptions_Number[2].def;
  int dView = (int)WarpOptions_Number[3].def;
  int iView = (int)WarpOptions_Number[4].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  if(dView < 0) dView = iView;
  PView *v2 = getView(dView, v);
  if(!v2) return v;

  PViewData *data1 = v1->getData();
  PViewData *data2 = v2->getData();

  // sanity checks
  if(data1->getNumEntities() != data2->getNumEntities() ||
     data1->getNumElements() != data2->getNumElements()){
    Msg::Error("Incompatible views");
    return v;
  }
  if(TimeStep < 0 || TimeStep > data2->getNumTimeSteps() - 1){
    Msg::Error("Invalid TimeStep (%d) in View[%d]", TimeStep, v2->getIndex());
    return v;
  }
  
  // create smooth normal field if we don't have an explicit warp field
  smooth_normals *normals = 0;
  if(dView < 0){
    normals = new smooth_normals(AngleTol);
    for(int ent = 0; ent < data1->getNumEntities(0); ent++){
      for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
	if(data1->skipElement(0, ent, ele)) continue;
	int numEdges = data1->getNumEdges(0, ent, ele);
	if(numEdges == 3 || numEdges == 4){
	  double x[4], y[4], z[4], n[4];
	  for(int nod = 0; nod < numEdges; nod++)
	    data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
	  normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
	  for(int nod = 0; nod < numEdges; nod++)
	    normals->add(x[nod], y[nod], z[nod], n[0], n[1], n[2]);
	}
      }
    }
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
  
  // transform each "0" node: (x,y,z) += factor * mult * (valx, valy, valz)
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
	int numNodes = data1->getNumNodes(step, ent, ele);
	double x[8], y[8], z[8], n[3] = {0., 0., 0.};
	int tag[8];
	for(int nod = 0; nod < numNodes; nod++)
	  tag[nod] = data1->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
	int dim = data1->getDimension(step, ent, ele);
	if(normals && dim == 2)
	  normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
	for(int nod = 0; nod < numNodes; nod++){
	  if(tag[nod]) continue; // already transformed
	  double mult = 1., val[3] = {n[0], n[1], n[2]};
	  if(normals){
	    if(dim == 2){
	      normals->get(x[nod], y[nod], z[nod], val[0], val[1], val[2]);
	      data1->getScalarValue(step, ent, ele, nod, mult);
	    }
	  }
	  else if(data2->getNumComponents(TimeStep, ent, ele) == 3 &&
		  data2->getNumNodes(TimeStep, ent, ele) == numNodes){
	    for(int comp = 0; comp < 3; comp++)
	      data2->getValue(TimeStep, ent, ele, nod, comp, val[comp]);
	  }
	  x[nod] += factor * mult * val[0];
	  y[nod] += factor * mult * val[1];
	  z[nod] += factor * mult * val[2];
	  data1->setNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
	  data1->tagNode(step, ent, ele, nod, 1);
	}
      }
    }
  }
  
  if(normals) delete normals;

  data1->finalize();
  v1->setChanged(true);

  return v1;
}

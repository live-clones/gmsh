// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Divergence.h"
#include "shapeFunctions.h"

StringXNumber DivergenceOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDivergencePlugin()
  {
    return new GMSH_DivergencePlugin();
  }
}

void GMSH_DivergencePlugin::getName(char *name) const
{
  strcpy(name, "Divergence");
}

void GMSH_DivergencePlugin::getInfos(char *author, char *copyright,
				     char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Divergence) computes the divergence of the\n"
         "field in the view `iView'. If `iView' < 0, the plugin\n"
         "is run on the current view.\n"
         "\n"
         "Plugin(Divergence) creates one new view.\n");
}

int GMSH_DivergencePlugin::getNbOptions() const
{
  return sizeof(DivergenceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DivergencePlugin::getOption(int iopt)
{
  return &DivergenceOptions_Number[iopt];
}

void GMSH_DivergencePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Divergence failed...");
}

static List_T *incrementList(PViewDataList *data2, int numEdges)
{
  switch(numEdges){
  case 0: data2->NbSP++; return data2->SP;
  case 1: data2->NbSL++; return data2->SL;
  case 3: data2->NbST++; return data2->ST;
  case 4: data2->NbSQ++; return data2->SQ;
  case 6: data2->NbSS++; return data2->SS;
  case 12: data2->NbSH++; return data2->SH;
  case 9: data2->NbSI++; return data2->SI;
  case 8: data2->NbSY++; return data2->SY;
  default: return 0;
  }
}

PView *GMSH_DivergencePlugin::execute(PView *v)
{
  int iView = (int)DivergenceOptions_Number[0].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Divergence plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *v2 = new PView(true);
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 3) continue;
      int numEdges = data1->getNumEdges(0, ent, ele);
      List_T *out = incrementList(data2, numEdges);
      if(!out) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      double x[8], y[8], z[8], val[8 * 3];
      for(int nod = 0; nod < numNodes; nod++)
	data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = data1->getDimension(0, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++) List_Add(out, &x[nod]);
      for(int nod = 0; nod < numNodes; nod++) List_Add(out, &y[nod]);
      for(int nod = 0; nod < numNodes; nod++) List_Add(out, &z[nod]);
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
	for(int nod = 0; nod < numNodes; nod++)
	  for(int comp = 0; comp < numComp; comp++)
	    data1->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
	for(int nod = 0; nod < numNodes; nod++){
	  double u, v, w;
	  element->getNode(nod, u, v, w);
	  double f = element->interpolateDiv(val, u, v, w, 3);
	  List_Add(out, &f);
	}
      }
      delete element;
    }
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    List_Add(data2->Time, &time);
  }
  data2->setName(data1->getName() + "_Divergence");
  data2->setFileName(data1->getName() + "_Divergence.pos");
  data2->finalize();

  return v2;
}

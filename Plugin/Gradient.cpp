// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Gradient.h"
#include "shapeFunctions.h"

StringXNumber GradientOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGradientPlugin()
  {
    return new GMSH_GradientPlugin();
  }
}

void GMSH_GradientPlugin::getName(char *name) const
{
  strcpy(name, "Gradient");
}

void GMSH_GradientPlugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Gradient) computes the gradient of the\n"
         "field in the view `iView'. If `iView' < 0, the\n"
         "plugin is run on the current view.\n"
         "\n"
         "Plugin(Gradient) creates one new view.\n");
}

int GMSH_GradientPlugin::getNbOptions() const
{
  return sizeof(GradientOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_GradientPlugin::getOption(int iopt)
{
  return &GradientOptions_Number[iopt];
}

void GMSH_GradientPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Gradient failed...");
}

static List_T *incrementList(PViewDataList *data2, int numComp, int numEdges)
{
  if(numComp == 1){
    switch(numEdges){
    case 0: data2->NbVP++; return data2->VP;
    case 1: data2->NbVL++; return data2->VL;
    case 3: data2->NbVT++; return data2->VT;
    case 4: data2->NbVQ++; return data2->VQ;
    case 6: data2->NbVS++; return data2->VS;
    case 12: data2->NbVH++; return data2->VH;
    case 9: data2->NbVI++; return data2->VI;
    case 8: data2->NbVY++; return data2->VY;
    default: return 0;
    }
  }
  else if(numComp == 3){
    switch(numEdges){
    case 0: data2->NbTP++; return data2->TP;
    case 1: data2->NbTL++; return data2->TL;
    case 3: data2->NbTT++; return data2->TT;
    case 4: data2->NbTQ++; return data2->TQ;
    case 6: data2->NbTS++; return data2->TS;
    case 12: data2->NbTH++; return data2->TH;
    case 9: data2->NbTI++; return data2->TI;
    case 8: data2->NbTY++; return data2->TY;
    default: return 0;
    }
  }
  return 0;
}

PView *GMSH_GradientPlugin::execute(PView *v)
{
  int iView = (int)GradientOptions_Number[0].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Gradient plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *v2 = new PView(true, data1->getNumElements());
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 1 && numComp != 3) continue;
      int numEdges = data1->getNumEdges(0, ent, ele);
      List_T *out = incrementList(data2, numComp, numEdges);
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
	  double u, v, w, f[3];
	  element->getNode(nod, u, v, w);
	  for(int comp = 0; comp < numComp; comp++){
	    element->interpolateGrad(val + comp, u, v, w, f, numComp);
	    List_Add(out, &f[0]);
	    List_Add(out, &f[1]);
	    List_Add(out, &f[2]);
	  }
	}
      }
      delete element;
    }
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    List_Add(data2->Time, &time);
  }
  data2->setName(data1->getName() + "_Gradient");
  data2->setFileName(data1->getName() + "_Gradient.pos");
  data2->finalize();
  
  return v2;
}

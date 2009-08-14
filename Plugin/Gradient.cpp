// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Gradient.h"
#include "shapeFunctions.h"
#include "GmshDefines.h"

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

static std::vector<double> *incrementList(PViewDataList *data2, int numComp, int type)
{
  if(numComp == 1){
    switch(type){
    case TYPE_PNT: data2->NbVP++; return &data2->VP;
    case TYPE_LIN: data2->NbVL++; return &data2->VL;
    case TYPE_TRI: data2->NbVT++; return &data2->VT;
    case TYPE_QUA: data2->NbVQ++; return &data2->VQ;
    case TYPE_TET: data2->NbVS++; return &data2->VS;
    case TYPE_HEX: data2->NbVH++; return &data2->VH;
    case TYPE_PRI: data2->NbVI++; return &data2->VI;
    case TYPE_PYR: data2->NbVY++; return &data2->VY;
    default: return 0;
    }
  }
  else if(numComp == 3){
    switch(type){
    case TYPE_PNT: data2->NbTP++; return &data2->TP;
    case TYPE_LIN: data2->NbTL++; return &data2->TL;
    case TYPE_TRI: data2->NbTT++; return &data2->TT;
    case TYPE_QUA: data2->NbTQ++; return &data2->TQ;
    case TYPE_TET: data2->NbTS++; return &data2->TS;
    case TYPE_HEX: data2->NbTH++; return &data2->TH;
    case TYPE_PRI: data2->NbTI++; return &data2->TI;
    case TYPE_PYR: data2->NbTY++; return &data2->TY;
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

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 1 && numComp != 3) continue;
      int type = data1->getType(0, ent, ele);
      std::vector<double> *out = incrementList(data2, numComp, type);
      if(!out) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      double x[8], y[8], z[8], val[8 * 3];
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = data1->getDimension(0, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
        for(int nod = 0; nod < numNodes; nod++)
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
        for(int nod = 0; nod < numNodes; nod++){
          double u, v, w, f[3];
          element->getNode(nod, u, v, w);
          for(int comp = 0; comp < numComp; comp++){
            element->interpolateGrad(val + comp, u, v, w, f, numComp);
            out->push_back(f[0]);
            out->push_back(f[1]);
            out->push_back(f[2]);
          }
        }
      }
      delete element;
    }
  }

  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    data2->Time.push_back(time);
  }
  data2->setName(data1->getName() + "_Gradient");
  data2->setFileName(data1->getName() + "_Gradient.pos");
  data2->finalize();
  
  return v2;
}

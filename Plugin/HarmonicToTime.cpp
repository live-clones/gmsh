// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "HarmonicToTime.h"
#include "GmshDefines.h"

StringXNumber HarmonicToTimeOptions_Number[] = {
  {GMSH_FULLRC, "RealPart", NULL, 0.},
  {GMSH_FULLRC, "ImaginaryPart", NULL, 1.},
  {GMSH_FULLRC, "nSteps", NULL, 20.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHarmonicToTimePlugin()
  {
    return new GMSH_HarmonicToTimePlugin();
  }
}

std::string GMSH_HarmonicToTimePlugin::getHelp() const
{
  return "Plugin(HarmonicToTime) takes the values in the\n"
         "time steps `RealPart' and `ImaginaryPart' of\n"
         "the view `iView', and creates a new view\n"
         "containing (`iView'[`RealPart'] * cos(p) -\n"
         "`iView'[`ImaginaryPart'] * sin(p)), with\n"
         "p = 2*Pi*k/`nSteps', k = 0, ..., `nSteps'-1.\n"
         "If `iView' < 0, the plugin is run on the\n"
         "current view.\n"
         "\n"
         "Plugin(HarmonicToTime) creates one new view.\n";
}

int GMSH_HarmonicToTimePlugin::getNbOptions() const
{
  return sizeof(HarmonicToTimeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HarmonicToTimePlugin::getOption(int iopt)
{
  return &HarmonicToTimeOptions_Number[iopt];
}

static std::vector<double> *incrementList(PViewDataList *data, int numComp, 
                                          int type)
{
  switch(type){
  case TYPE_PNT:
    if     (numComp == 1){ data->NbSP++; return &data->SP; }
    else if(numComp == 3){ data->NbVP++; return &data->VP; }
    else if(numComp == 9){ data->NbTP++; return &data->TP; }
    break;
  case TYPE_LIN:
    if     (numComp == 1){ data->NbSL++; return &data->SL; }
    else if(numComp == 3){ data->NbVL++; return &data->VL; }
    else if(numComp == 9){ data->NbTL++; return &data->TL; }
    break;
  case TYPE_TRI:
    if     (numComp == 1){ data->NbST++; return &data->ST; }
    else if(numComp == 3){ data->NbVT++; return &data->VT; }
    else if(numComp == 9){ data->NbTT++; return &data->TT; }
    break;
  case TYPE_QUA:
    if     (numComp == 1){ data->NbSQ++; return &data->SQ; }
    else if(numComp == 3){ data->NbVQ++; return &data->VQ; }
    else if(numComp == 9){ data->NbTQ++; return &data->TQ; }
    break;
  case TYPE_TET:
    if     (numComp == 1){ data->NbSS++; return &data->SS; }
    else if(numComp == 3){ data->NbVS++; return &data->VS; }
    else if(numComp == 9){ data->NbTS++; return &data->TS; }
    break;
  case TYPE_HEX:
    if     (numComp == 1){ data->NbSH++; return &data->SH; }
    else if(numComp == 3){ data->NbVH++; return &data->VH; }
    else if(numComp == 9){ data->NbTH++; return &data->TH; }
    break;
  case TYPE_PRI:
    if     (numComp == 1){ data->NbSI++; return &data->SI; }
    else if(numComp == 3){ data->NbVI++; return &data->VI; }
    else if(numComp == 9){ data->NbTI++; return &data->TI; }
    break;
  case TYPE_PYR:
    if     (numComp == 1){ data->NbSY++; return &data->SY; }
    else if(numComp == 3){ data->NbVY++; return &data->VY; }
    else if(numComp == 9){ data->NbTY++; return &data->TY; }
    break;
  }
  return 0;
}

PView *GMSH_HarmonicToTimePlugin::execute(PView * v)
{
  int rIndex = (int)HarmonicToTimeOptions_Number[0].def;
  int iIndex = (int)HarmonicToTimeOptions_Number[1].def;
  int nSteps = (int)HarmonicToTimeOptions_Number[2].def;
  int iView = (int)HarmonicToTimeOptions_Number[3].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()){
    Msg::Error("HarmonicToTime plugin cannot be applied to multi-mesh views");
    return v1;
  }

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() ||
     iIndex < 0 || iIndex >= data1->getNumTimeSteps()){
    Msg::Error("Wrong real or imaginary part index");
    return v1;
  }

  if(nSteps <= 0){
    Msg::Error("nSteps should be > 0");
    return v1;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  
  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      int type = data1->getType(0, ent, ele);
      int numComp = data1->getNumComponents(0, ent, ele);
      std::vector<double> *out = incrementList(data2, numComp, type);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      std::vector<double> vr(numNodes * numComp), vi(numNodes * numComp);
      for(int nod = 0; nod < numNodes; nod++){
        data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
        for(int comp = 0; comp < numComp; comp++){
          data1->getValue(rIndex, ent, ele, nod, comp, vr[numComp * nod + comp]);
          data1->getValue(iIndex, ent, ele, nod, comp, vi[numComp * nod + comp]);
        }
      }
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]); 
      for(int t = 0; t < nSteps; t++) {
        double p = 2. * M_PI * t / nSteps;
        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < numComp; comp++) {
            double val = vr[numComp * nod + comp] * cos(p) - 
              vi[numComp * nod + comp] * sin(p);
            out->push_back(val);
          }
        }
      }
    }
  }

  for(int i = 0; i < nSteps; i++){
    double p = 2. * M_PI * i / (double)nSteps;
    data2->Time.push_back(p);
  }
  data2->setName(data1->getName() + "_HarmonicToTime");
  data2->setFileName(data1->getName() + "_HarmonicToTime.pos");
  data2->finalize();

  return v2;
}

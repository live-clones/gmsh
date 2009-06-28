// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "ExtractElements.h"
#include "Numeric.h"

#define SQU(a)      ((a)*(a))

StringXNumber ExtractElementsOptions_Number[] = {
  {GMSH_FULLRC, "MinVal", NULL, 0.},
  {GMSH_FULLRC, "MaxVal", NULL, 1.},
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractElementsPlugin()
  {
    return new GMSH_ExtractElementsPlugin();
  }
}

void GMSH_ExtractElementsPlugin::getName(char *name) const
{
  strcpy(name, "Extract Elements");
}

void GMSH_ExtractElementsPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(ExtractElements) extracts the elements\n"
         "from the view `iView' whose `TimeStep'-th values\n"
         "(averaged by element) are comprised between\n"
         "`MinVal' and `MaxVal'. If `iView' < 0, the plugin\n"
         "is run on the current view.\n"
         "\n"
         "Plugin(ExtractElements) creates one new view.\n");
}

int GMSH_ExtractElementsPlugin::getNbOptions() const
{
  return sizeof(ExtractElementsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractElementsPlugin::getOption(int iopt)
{
  return &ExtractElementsOptions_Number[iopt];
}

void GMSH_ExtractElementsPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "ExtractElements failed...");
}

static void extract(std::vector<double> &inList, int inNb, 
                    std::vector<double> &outList, int *outNb, 
                    int timeStep, int nbNod, int nbComp)
{
  if(!inNb)
    return;

  double MinVal = ExtractElementsOptions_Number[0].def;
  double MaxVal = ExtractElementsOptions_Number[1].def;

  int nb = inList.size() / inNb;
  for(unsigned int i = 0; i < inList.size(); i += nb) {
    double *vals = &inList[i + 3 * nbNod + timeStep * nbNod * nbComp];
    double d = 0.;
    for(int k = 0; k < nbNod; k++) {
      double *v = &vals[nbComp * k];
      switch(nbComp) {
      case 1: // scalar
        d += v[0];
        break;
      case 3 : // vector
        d += sqrt(SQU(v[0]) + SQU(v[1]) + SQU(v[2]));
        break;
      case 9 : // tensor
        d += ComputeVonMises(v);
        break;
      }
    }
    d /= (double)nbNod;
    // We use '>=' and '<' so that we can do segmentation without
    // worrying about roundoff errors
    if(d >= MinVal && d < MaxVal){
      for(int j = 0; j < nb; j++)
        outList.push_back(inList[i + j]);
      (*outNb)++;
    }
  }
}

PView *GMSH_ExtractElementsPlugin::execute(PView *v)
{
  int step = (int)ExtractElementsOptions_Number[2].def;
  int iView = (int)ExtractElementsOptions_Number[3].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView();

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  if(step < 0 || step > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using first step instead",
        step, v1->getIndex());
    step = 0;
  }

  // points
  extract(data1->SP, data1->NbSP, data2->SP, &data2->NbSP, step, 1, 1);
  extract(data1->VP, data1->NbVP, data2->VP, &data2->NbVP, step, 1, 3);
  extract(data1->TP, data1->NbTP, data2->TP, &data2->NbTP, step, 1, 9);
  // lines                                              
  extract(data1->SL, data1->NbSL, data2->SL, &data2->NbSL, step, 2, 1);
  extract(data1->VL, data1->NbVL, data2->VL, &data2->NbVL, step, 2, 3);
  extract(data1->TL, data1->NbTL, data2->TL, &data2->NbTL, step, 2, 9);
  // triangles                                          
  extract(data1->ST, data1->NbST, data2->ST, &data2->NbST, step, 3, 1);
  extract(data1->VT, data1->NbVT, data2->VT, &data2->NbVT, step, 3, 3);
  extract(data1->TT, data1->NbTT, data2->TT, &data2->NbTT, step, 3, 9);
  // quadrangles                                        
  extract(data1->SQ, data1->NbSQ, data2->SQ, &data2->NbSQ, step, 4, 1);
  extract(data1->VQ, data1->NbVQ, data2->VQ, &data2->NbVQ, step, 4, 3);
  extract(data1->TQ, data1->NbTQ, data2->TQ, &data2->NbTQ, step, 4, 9);
  // tets                                               
  extract(data1->SS, data1->NbSS, data2->SS, &data2->NbSS, step, 4, 1);
  extract(data1->VS, data1->NbVS, data2->VS, &data2->NbVS, step, 4, 3);
  extract(data1->TS, data1->NbTS, data2->TS, &data2->NbTS, step, 4, 9);
  // hexas                                              
  extract(data1->SH, data1->NbSH, data2->SH, &data2->NbSH, step, 8, 1);
  extract(data1->VH, data1->NbVH, data2->VH, &data2->NbVH, step, 8, 3);
  extract(data1->TH, data1->NbTH, data2->TH, &data2->NbTH, step, 8, 9);
  // prisms                                             
  extract(data1->SI, data1->NbSI, data2->SI, &data2->NbSI, step, 6, 1);
  extract(data1->VI, data1->NbVI, data2->VI, &data2->NbVI, step, 6, 3);
  extract(data1->TI, data1->NbTI, data2->TI, &data2->NbTI, step, 6, 9);
  // pyramids                                           
  extract(data1->SY, data1->NbSY, data2->SY, &data2->NbSY, step, 5, 1);
  extract(data1->VY, data1->NbVY, data2->VY, &data2->NbVY, step, 5, 3);
  extract(data1->TY, data1->NbTY, data2->TY, &data2->NbTY, step, 5, 9);

  data2->Time = data1->Time;
  data2->setName(data1->getName() + "_ExtractElements");
  data2->setFileName(data1->getName() + "_ExtractElements.pos");
  data2->finalize();

  return v2;
}

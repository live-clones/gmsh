// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "HarmonicToTime.h"

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


GMSH_HarmonicToTimePlugin::GMSH_HarmonicToTimePlugin()
{
  ;
}

void GMSH_HarmonicToTimePlugin::getName(char *name) const
{
  strcpy(name, "Harmonic to Time");
}

void GMSH_HarmonicToTimePlugin::getInfos(char *author, char *copyright,
                                        char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(HarmonicToTime) takes the values in the\n"
         "time steps `RealPart' and `ImaginaryPart' of\n"
         "the view `iView', and creates a new view\n"
         "containing (`iView'[`RealPart'] * cos(p) -\n"
         "`iView'[`ImaginaryPart'] * sin(p)), with\n"
         "p = 2*Pi*k/`nSteps', k = 0, ..., `nSteps'-1.\n"
         "If `iView' < 0, the plugin is run on the\n"
         "current view.\n"
         "\n"
         "Plugin(HarmonicToTime) creates one new view.\n");
}

int GMSH_HarmonicToTimePlugin::getNbOptions() const
{
  return sizeof(HarmonicToTimeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HarmonicToTimePlugin::getOption(int iopt)
{
  return &HarmonicToTimeOptions_Number[iopt];
}

void GMSH_HarmonicToTimePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "HarmonicToTime failed...");
}


static void h2t(int nb1, List_T *list1, int *nb2, List_T *list2,
                int nbNod, int nbComp, int rIndex, int iIndex, int nSteps)
{
  if(!nb1) return;

  int nb = List_Nbr(list1) / nb1;
  for(int i = 0; i < List_Nbr(list1); i += nb) {
    for(int j = 0; j < 3 * nbNod; j++)
      List_Add(list2, List_Pointer_Fast(list1, i + j));
    double *valr = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
                                               nbNod * nbComp * rIndex);
    double *vali = (double *)List_Pointer_Fast(list1, i + 3 * nbNod +
                                               nbNod * nbComp * iIndex);
    for(int t = 0; t < nSteps; t++) {
      double p = 2. * M_PI * t / nSteps;
      for(int j = 0; j < nbNod; j++) {
        for(int k = 0; k < nbComp; k++) {
          double val = valr[nbComp * j + k] * cos(p) - vali[nbComp * j + k] * sin(p);
          List_Add(list2, &val);          
        }
      }
    }
  }
  *nb2 = nb1;
}

PView *GMSH_HarmonicToTimePlugin::execute(PView * v)
{
  int rIndex = (int)HarmonicToTimeOptions_Number[0].def;
  int iIndex = (int)HarmonicToTimeOptions_Number[1].def;
  int nSteps = (int)HarmonicToTimeOptions_Number[2].def;
  int iView = (int)HarmonicToTimeOptions_Number[3].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() ||
     iIndex < 0 || iIndex >= data1->getNumTimeSteps()){
    Msg::Error("Wrong real or imaginary part index");
    return v1;
  }

  if(nSteps <= 0){
    Msg::Error("nSteps should be > 0");
    return v1;
  }

  PView *v2 = new PView(true, data1->getNumElements() * nSteps);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  h2t(data1->NbSP, data1->SP, &data2->NbSP, data2->SP, 1, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVP, data1->VP, &data2->NbVP, data2->VP, 1, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTP, data1->TP, &data2->NbTP, data2->TP, 1, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSL, data1->SL, &data2->NbSL, data2->SL, 2, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVL, data1->VL, &data2->NbVL, data2->VL, 2, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTL, data1->TL, &data2->NbTL, data2->TL, 2, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbST, data1->ST, &data2->NbST, data2->ST, 3, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVT, data1->VT, &data2->NbVT, data2->VT, 3, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTT, data1->TT, &data2->NbTT, data2->TT, 3, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSQ, data1->SQ, &data2->NbSQ, data2->SQ, 4, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVQ, data1->VQ, &data2->NbVQ, data2->VQ, 4, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTQ, data1->TQ, &data2->NbTQ, data2->TQ, 4, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSS, data1->SS, &data2->NbSS, data2->SS, 4, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVS, data1->VS, &data2->NbVS, data2->VS, 4, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTS, data1->TS, &data2->NbTS, data2->TS, 4, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSH, data1->SH, &data2->NbSH, data2->SH, 8, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVH, data1->VH, &data2->NbVH, data2->VH, 8, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTH, data1->TH, &data2->NbTH, data2->TH, 8, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSI, data1->SI, &data2->NbSI, data2->SI, 6, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVI, data1->VI, &data2->NbVI, data2->VI, 6, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTI, data1->TI, &data2->NbTI, data2->TI, 6, 9, rIndex, iIndex, nSteps);
  h2t(data1->NbSY, data1->SY, &data2->NbSY, data2->SY, 5, 1, rIndex, iIndex, nSteps);
  h2t(data1->NbVY, data1->VY, &data2->NbVY, data2->VY, 5, 3, rIndex, iIndex, nSteps);
  h2t(data1->NbTY, data1->TY, &data2->NbTY, data2->TY, 5, 9, rIndex, iIndex, nSteps);

  for(int i = 0; i < nSteps; i++){
    double p = 2. * M_PI * i / (double)nSteps;
    List_Add(data2->Time, &p);
  }
  data2->setName(data1->getName() + "_HarmonicToTime");
  data2->setFileName(data1->getName() + "_HarmonicToTime.pos");
  data2->finalize();

  return v2;
}

// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "HarmonicToTime.h"
#include "GmshDefines.h"

StringXNumber HarmonicToTimeOptions_Number[] = {
  {GMSH_FULLRC, "RealPart", nullptr, 0.},
  {GMSH_FULLRC, "ImaginaryPart", nullptr, 1.},
  {GMSH_FULLRC, "NumSteps", nullptr, 20.},
  {GMSH_FULLRC, "TimeSign", nullptr, -1.},
  {GMSH_FULLRC, "Frequency", nullptr, 1},
  {GMSH_FULLRC, "NumPeriods", nullptr, 1},
  {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterHarmonicToTimePlugin()
{
  return new GMSH_HarmonicToTimePlugin();
}
}

std::string GMSH_HarmonicToTimePlugin::getHelp() const
{
  return "Plugin(HarmonicToTime) takes the values in the "
         "time steps `RealPart' and `ImaginaryPart' of "
         "the view `View', and creates a new view "
         "containing\n\n"
         "`View'[`RealPart'] * cos(p) +- `View'[`ImaginaryPart'] * sin(p)\n"
         "with\n p = 2*Pi*k/`NumSteps', k = 0, ..., `NumSteps'-1\n"
         "and 'NumSteps' the total number of time steps\n"
         "over 'NumPeriods' periods at frequency 'Frequency' [Hz].\n"
         "The '+' sign is used if `TimeSign'>0, the '-' sign otherwise.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(HarmonicToTime) creates one new list-based view.";
}

int GMSH_HarmonicToTimePlugin::getNbOptions() const
{
  return sizeof(HarmonicToTimeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HarmonicToTimePlugin::getOption(int iopt)
{
  return &HarmonicToTimeOptions_Number[iopt];
}

PView *GMSH_HarmonicToTimePlugin::execute(PView *v)
{
  int rIndex = (int)HarmonicToTimeOptions_Number[0].def;
  int iIndex = (int)HarmonicToTimeOptions_Number[1].def;
  int nSteps = (int)HarmonicToTimeOptions_Number[2].def;
  double tsign = HarmonicToTimeOptions_Number[3].def > 0 ? 1. : -1.;
  double frequency = HarmonicToTimeOptions_Number[4].def;
  int nPeriods = (int)HarmonicToTimeOptions_Number[5].def;
  int iView = (int)HarmonicToTimeOptions_Number[6].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData(true);

  if(data1->hasMultipleMeshes()) {
    Msg::Error("HarmonicToTime plugin cannot be applied to multi-mesh views");
    return v1;
  }

  if(rIndex < 0 || rIndex >= data1->getNumTimeSteps() || iIndex < 0 ||
     iIndex >= data1->getNumTimeSteps()) {
    Msg::Error("Wrong real or imaginary part index");
    return v1;
  }

  if(nSteps <= 0) {
    Msg::Error("nSteps should be > 0");
    return v1;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(0); ent++) {
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++) {
      if(data1->skipElement(0, ent, ele)) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      int type = data1->getType(0, ent, ele);
      int numComp = data1->getNumComponents(0, ent, ele);
      std::vector<double> *out = data2->incrementList(numComp, type, numNodes);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      std::vector<double> vr(numNodes * numComp), vi(numNodes * numComp);
      for(int nod = 0; nod < numNodes; nod++) {
        data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
        for(int comp = 0; comp < numComp; comp++) {
          data1->getValue(rIndex, ent, ele, nod, comp,
                          vr[numComp * nod + comp]);
          data1->getValue(iIndex, ent, ele, nod, comp,
                          vi[numComp * nod + comp]);
        }
      }
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int k = 0; k < nSteps; k++) {
        // if frequency == 0 is requested, simply use real part
        double p = frequency ? 2. * M_PI * nPeriods * k / nSteps : 0.;
        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < numComp; comp++) {
            double val = vr[numComp * nod + comp] * cos(p) +
                         tsign * vi[numComp * nod + comp] * sin(p);
            out->push_back(val);
          }
        }
      }
    }
  }

  for(int k = 0; k < nSteps; k++) {
    double t =
      frequency ? (2. * M_PI * nPeriods * k / frequency / (double)nSteps) : 0.;
    data2->Time.push_back(t);
  }
  data2->setName(data1->getName() + "_HarmonicToTime");
  data2->setFileName(data1->getName() + "_HarmonicToTime.pos");
  data2->finalize();

  return v2;
}

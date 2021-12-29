// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "ExtractElements.h"
#include "Numeric.h"

StringXNumber ExtractElementsOptions_Number[] = {
  {GMSH_FULLRC, "MinVal", nullptr, 0.},
  {GMSH_FULLRC, "MaxVal", nullptr, 0.},
  {GMSH_FULLRC, "TimeStep", nullptr, 0.},
  {GMSH_FULLRC, "Visible", nullptr, 1.},
  {GMSH_FULLRC, "Dimension", nullptr, -1.},
  {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterExtractElementsPlugin()
{
  return new GMSH_ExtractElementsPlugin();
}
}

std::string GMSH_ExtractElementsPlugin::getHelp() const
{
  return "Plugin(ExtractElements) extracts some elements "
         "from the view `View'. If `MinVal' != `MaxVal', it extracts "
         "the elements whose `TimeStep'-th values (averaged by element) "
         "are comprised between `MinVal' and `MaxVal'. If `Visible' != 0, "
         "it extracts visible elements. "
         "\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(ExtractElements) creates one new list-based view.";
}

int GMSH_ExtractElementsPlugin::getNbOptions() const
{
  return sizeof(ExtractElementsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractElementsPlugin::getOption(int iopt)
{
  return &ExtractElementsOptions_Number[iopt];
}

PView *GMSH_ExtractElementsPlugin::execute(PView *v)
{
  double MinVal = ExtractElementsOptions_Number[0].def;
  double MaxVal = ExtractElementsOptions_Number[1].def;
  int thisStep = (int)ExtractElementsOptions_Number[2].def;
  int visible = (int)ExtractElementsOptions_Number[3].def;
  int dimension = (int)ExtractElementsOptions_Number[4].def;
  int iView = (int)ExtractElementsOptions_Number[5].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = getPossiblyAdaptiveData(v1);
  bool checkMinMax = MinVal != MaxVal;

  int step = (thisStep < 0) ? 0 : thisStep;
  if(thisStep > data1->getNumTimeSteps() - 1) {
    Msg::Error("Invalid time step (%d) in View[%d]: using first step instead",
               thisStep, v1->getIndex());
    step = 0;
  }

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
    if(visible && data1->skipEntity(step, ent)) continue;
    for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
      if(data1->skipElement(step, ent, ele, visible)) continue;

      int dim = data1->getDimension(step, ent, ele);
      if((dimension > 0) && (dim != dimension)) continue;

      int numNodes = data1->getNumNodes(step, ent, ele);
      if(checkMinMax) {
        double d = 0.;
        for(int nod = 0; nod < numNodes; nod++) {
          double val;
          data1->getScalarValue(step, ent, ele, nod, val);
          d += val;
        }
        d /= (double)numNodes;
        // use '>=' and '<' so that we can do segmentation without
        // worrying about roundoff errors
        if(d < MinVal || d >= MaxVal) continue;
      }

      int type = data1->getType(step, ent, ele);
      int numComp = data1->getNumComponents(step, ent, ele);
      std::vector<double> *out = data2->incrementList(numComp, type, numNodes);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      std::vector<double> v(numNodes * numComp);
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);

      for(int step = 0; step < data1->getNumTimeSteps(); step++) {
        if(!data1->hasTimeStep(step)) continue;
        if((thisStep >= 0) && (thisStep != step)) continue;

        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < numComp; comp++) {
            double temp;
            data1->getValue(step, ent, ele, nod, comp, temp);
            out->push_back(temp);
          }
        }
      }
    }
  }

  if(thisStep >= 0)
    data2->Time.push_back(data1->getTime(thisStep));
  else {
    for(int step = 0; step < data1->getNumTimeSteps(); step++) {
      data2->Time.push_back(data1->getTime(step));
    }
  }

  data2->setName(data1->getName() + "_ExtractElements");
  data2->setFileName(data1->getName() + "_ExtractElements.pos");
  data2->finalize();

  return v2;
}

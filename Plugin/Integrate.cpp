// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Integrate.h"
#include "shapeFunctions.h"
#include "PViewOptions.h"

StringXNumber IntegrateOptions_Number[] = {
  {GMSH_FULLRC, "View", nullptr, -1.},
  {GMSH_FULLRC, "OverTime", nullptr, -1.},
  {GMSH_FULLRC, "Dimension", nullptr, -1.},
  {GMSH_FULLRC, "Visible", nullptr, 1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterIntegratePlugin()
{
  return new GMSH_IntegratePlugin();
}
}

std::string GMSH_IntegratePlugin::getHelp() const
{
  return "Plugin(Integrate) integrates a scalar field over all the elements "
         "of the view `View' (if `Dimension' < 0), or over all elements of "
         "the prescribed dimension (if `Dimension' > 0). If the field is a "
         "vector field, the circulation/flux of the field over  line/surface "
         "elements is calculated.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "If `OverTime' = i > -1 , the plugin integrates the scalar view "
         "over time (using the trapezoidal rule) instead of over space, "
         "starting at step i. If `Visible' = 1, the plugin only integrates "
         "over visible entities.\n\n"
         "Plugin(Integrate) creates one new list-based view.";
}

int GMSH_IntegratePlugin::getNbOptions() const
{
  return sizeof(IntegrateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_IntegratePlugin::getOption(int iopt)
{
  return &IntegrateOptions_Number[iopt];
}

PView *GMSH_IntegratePlugin::execute(PView *v)
{
  int iView = (int)IntegrateOptions_Number[0].def;
  int overTime = (int)IntegrateOptions_Number[1].def;
  int dimension = (int)IntegrateOptions_Number[2].def;
  bool visible = (bool)IntegrateOptions_Number[3].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  if(overTime == -1) {
    double x = data1->getBoundingBox().center().x();
    double y = data1->getBoundingBox().center().y();
    double z = data1->getBoundingBox().center().z();
    data2->SP.push_back(x);
    data2->SP.push_back(y);
    data2->SP.push_back(z);
    for(int step = 0; step < data1->getNumTimeSteps(); step++) {
      double res = 0, resv[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
      bool simpleSum = false;
      for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
        if(visible && data1->skipEntity(step, ent)) continue;
        for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
          if(data1->skipElement(step, ent, ele, visible)) continue;
          int numComp = data1->getNumComponents(step, ent, ele);
          int numEdges = data1->getNumEdges(step, ent, ele);
          bool scalar = (numComp == 1);
          bool circulation = (numComp == 3 && numEdges == 1);
          bool flux = (numComp == 3 && (numEdges == 3 || numEdges == 4));
          int numNodes = data1->getNumNodes(step, ent, ele);
          int dim = data1->getDimension(step, ent, ele);
          if((dimension > 0) && (dim != dimension)) continue;
          double x[8], y[8], z[8], val[8 * 3] = {0.};
          for(int nod = 0; nod < numNodes; nod++) {
            data1->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
            for(int comp = 0; comp < numComp; comp++)
              data1->getValue(step, ent, ele, nod, comp,
                              val[numComp * nod + comp]);
          }
          if(numNodes == 1) {
            simpleSum = true;
            res += val[0];
            for(int comp = 0; comp < numComp; comp++) resv[comp] += val[comp];
          }
          else {
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
      }
      if(simpleSum)
        Msg::Info("Step %d: sum = %g %g %g %g %g %g %g %g %g", step, resv[0],
                  resv[1], resv[2], resv[3], resv[4], resv[5], resv[6], resv[7],
                  resv[8]);
      else
        Msg::Info("Step %d: integral = %.16g", step, res);
      data2->SP.push_back(res);
    }
    data2->NbSP = 1;
    v2->getOptions()->intervalsType = PViewOptions::Numeric;

    for(int i = 0; i < data1->getNumTimeSteps(); i++) {
      double time = data1->getTime(i);
      data2->Time.push_back(time);
    }
  }
  else {
    int firstStep = data1->getFirstNonEmptyTimeStep();
    int numSteps = data1->getNumTimeSteps();
    for(int ent = 0; ent < data1->getNumEntities(firstStep); ent++) {
      for(int ele = 0; ele < data1->getNumElements(firstStep, ent); ele++) {
        if(data1->skipElement(firstStep, ent, ele)) continue;
        int dim = data1->getDimension(firstStep, ent, ele);
        if((dimension > 0) && (dim != dimension)) continue;

        int numNodes = data1->getNumNodes(firstStep, ent, ele);
        int type = data1->getType(firstStep, ent, ele);
        int numComp = data1->getNumComponents(firstStep, ent, ele);
        if(numComp != 1)
          Msg::Error("Can only integrate scalar views over time");
        std::vector<double> *out =
          data2->incrementList(numComp, type, numNodes);
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        for(int nod = 0; nod < numNodes; nod++)
          data1->getNode(firstStep, ent, ele, nod, x[nod], y[nod], z[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);

        std::vector<double> val, t;
        for(int step = firstStep + overTime; step < numSteps - 1; step++) {
          if(!data1->hasTimeStep(step)) continue;
          t.push_back(data1->getTime(step));
          for(int nod = 0; nod < numNodes; nod++) {
            double v;
            data1->getValue(step, ent, ele, nod, 0, v);
            val.push_back(v);
          }
        }
        std::vector<double> timeIntegral(numNodes, 0.);
        for(std::size_t step = 0; step < t.size() - 1; step++) {
          double dt = t[step + 1] - t[step];
          for(int nod = 0; nod < numNodes; nod++) {
            timeIntegral[nod] += 0.5 *
              (val[step * numNodes + nod] + val[(step + 1) * numNodes + nod]) * dt;
          }
        }
        for(int nod = 0; nod < numNodes; nod++)
          out->push_back(timeIntegral[nod]);
      }
    }
  }

  data2->setName(data1->getName() + "_Integrate");
  data2->setFileName(data1->getName() + "_Integrate.pos");
  data2->finalize();

  return v2;
}

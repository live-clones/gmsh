// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Integrate.h"
#include "MElement.h"
#include "shapeFunctions.h"
#include "PViewOptions.h"

GMSH_IntegratePlugin::GMSH_IntegratePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""},
                     {GMSH_FULLRC, "OverTime", nullptr, -1., ""},
                     {GMSH_FULLRC, "Dimension", nullptr, -1., ""},
                     {GMSH_FULLRC, "Visible", nullptr, 1., ""}})
{
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

PView *GMSH_IntegratePlugin::execute(PView *v)
{
  int iView = (int)option(0);
  int overTime = (int)option(1);
  int dimension = (int)option(2);
  bool visible = (bool)option(3);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  if(overTime == -1) {
    bool skipped = false;
    SPoint3 c = data1->getBoundingBox().center();
    std::vector<double> *l = data2->incrementList(1, TYPE_PNT);
    l->insert(l->end(), {c.x(), c.y(), c.z()});
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
          int numNodes = getNumCornerNodes(data1, step, ent, ele);
          if(!numNodes) continue;
          int dim = data1->getDimension(step, ent, ele);
          if((dimension > 0) && (dim != dimension)) continue;
          int type = data1->getType(step, ent, ele);
          if(type == TYPE_POLYG || type == TYPE_POLYH) {
            // integrate on the element itself (P1 on its sub-simplices)
            MElement *e = data1->getElement(step, ent, ele);
            if(!e) continue;
            if(!scalar) {
              Msg::Warning("Only scalar views are integrated on polytopes");
              continue;
            }
            std::vector<double> v(numNodes);
            for(int nod = 0; nod < numNodes; nod++)
              data1->getValue(step, ent, ele, nod, 0, v[nod]);
            res += e->integrate(&v[0], 1);
            continue;
          }
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
            else if(!skipped) {
              Msg::Warning("Only scalars, and the circulation along lines "
                           "and the flux through surfaces of vectors, are "
                           "integrated: skipping the other elements");
              skipped = true;
            }
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
      l->push_back(res);
    }
    v2->getOptions()->intervalsType = PViewOptions::Numeric;

    for(int i = 0; i < data1->getNumTimeSteps(); i++) {
      double time = data1->getTime(i);
      data2->addTime(time);
    }
  }
  else {
    int firstStep = data1->getFirstNonEmptyTimeStep();
    int numSteps = data1->getNumTimeSteps();
    bool warned = false;
    for(int ent = 0; ent < data1->getNumEntities(firstStep); ent++) {
      for(int ele = 0; ele < data1->getNumElements(firstStep, ent); ele++) {
        if(data1->skipElement(firstStep, ent, ele)) continue;
        int dim = data1->getDimension(firstStep, ent, ele);
        if((dimension > 0) && (dim != dimension)) continue;

        if(data1->getNumComponents(firstStep, ent, ele) != 1) {
          if(!warned) Msg::Warning("Can only integrate scalar views over time");
          warned = true;
          continue;
        }
        int numNodes = getNumCornerNodes(data1, firstStep, ent, ele);
        if(!numNodes) continue;
        int type = data1->getType(firstStep, ent, ele);
        std::vector<double> *out = data2->incrementList(1, type, numNodes);
        if(!out) continue;
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        for(int nod = 0; nod < numNodes; nod++)
          data1->getNode(firstStep, ent, ele, nod, x[nod], y[nod], z[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
        for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);

        std::vector<double> val, t;
        for(int step = firstStep + overTime; step < numSteps; step++) {
          if(!data1->hasTimeStep(step)) continue;
          t.push_back(data1->getTime(step));
          for(int nod = 0; nod < numNodes; nod++) {
            double v;
            data1->getValue(step, ent, ele, nod, 0, v);
            val.push_back(v);
          }
        }
        std::vector<double> timeIntegral(numNodes, 0.);
        for(std::size_t step = 0; step + 1 < t.size(); step++) {
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

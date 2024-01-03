// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MinMax.h"
#include "PViewOptions.h"

StringXNumber MinMaxOptions_Number[] = {{GMSH_FULLRC, "View", nullptr, -1.},
                                        {GMSH_FULLRC, "OverTime", nullptr, 0},
                                        {GMSH_FULLRC, "Argument", nullptr, 0},
                                        {GMSH_FULLRC, "Visible", nullptr, 1}};

extern "C" {
GMSH_Plugin *GMSH_RegisterMinMaxPlugin() { return new GMSH_MinMaxPlugin(); }
}

std::string GMSH_MinMaxPlugin::getHelp() const
{
  return "Plugin(MinMax) computes the min/max of a view.\n\n"
         "If `View' < 0, the plugin is run on the current view. "
         "If `OverTime' = 1, the plugin calculates the min/max over "
         "space and time. If `Argument' = 1, the plugin calculates the "
         "min/max and the argmin/argmax. If `Visible' = 1, the plugin "
         "is only applied to visible entities.\n\n"
         "Plugin(MinMax) creates two new list-based views.";
}

int GMSH_MinMaxPlugin::getNbOptions() const
{
  return sizeof(MinMaxOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MinMaxPlugin::getOption(int iopt)
{
  return &MinMaxOptions_Number[iopt];
}

PView *GMSH_MinMaxPlugin::execute(PView *v)
{
  int iView = (int)MinMaxOptions_Number[0].def;
  int overTime = (int)MinMaxOptions_Number[1].def;
  int argument = (int)MinMaxOptions_Number[2].def;
  bool visible = (bool)MinMaxOptions_Number[3].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData(true);
  PView *vMin = new PView();
  PView *vMax = new PView();
  PViewDataList *dataMin = getDataList(vMin);
  PViewDataList *dataMax = getDataList(vMax);

  if(!argument) {
    double x = data1->getBoundingBox().center().x();
    double y = data1->getBoundingBox().center().y();
    double z = data1->getBoundingBox().center().z();
    dataMin->SP.push_back(x);
    dataMin->SP.push_back(y);
    dataMin->SP.push_back(z);
    dataMax->SP.push_back(x);
    dataMax->SP.push_back(y);
    dataMax->SP.push_back(z);
    dataMin->NbSP = 1;
    dataMax->NbSP = 1;
  }

  double min = VAL_INF, max = -VAL_INF, timeMin = 0, timeMax = 0;

  for(int step = 0; step < data1->getNumTimeSteps(); step++) {
    if(data1->hasTimeStep(step)) {
      double minView = VAL_INF, maxView = -VAL_INF;
      double xmin = 0., ymin = 0., zmin = 0., xmax = 0., ymax = 0., zmax = 0.;
      for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
        if(visible && data1->skipEntity(step, ent)) continue;
        for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
          if(data1->skipElement(step, ent, ele, visible)) continue;
          for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++) {
            double val;
            data1->getScalarValue(step, ent, ele, nod, val);
            if(val < minView) {
              data1->getNode(step, ent, ele, nod, xmin, ymin, zmin);
              minView = val;
            }
            if(val > maxView) {
              data1->getNode(step, ent, ele, nod, xmax, ymax, zmax);
              maxView = val;
            }
          }
        }
      }

      if(!overTime) {
        if(argument) {
          dataMin->SP.push_back(xmin);
          dataMin->SP.push_back(ymin);
          dataMin->SP.push_back(zmin);
          dataMax->SP.push_back(xmax);
          dataMax->SP.push_back(ymax);
          dataMax->SP.push_back(zmax);
          (dataMin->NbSP)++;
          (dataMax->NbSP)++;
        }
        else {
          double time = data1->getTime(step);
          dataMin->Time.push_back(time);
          dataMax->Time.push_back(time);
        }
        dataMin->SP.push_back(minView);
        dataMax->SP.push_back(maxView);
      }
      else {
        if(minView < min) {
          min = minView;
          timeMin = data1->getTime(step);
        }
        if(maxView > max) {
          max = maxView;
          timeMax = data1->getTime(step);
        }
      }
    }
  }

  if(overTime) {
    dataMin->SP.push_back(min);
    dataMax->SP.push_back(max);
    dataMin->Time.push_back(timeMin);
    dataMax->Time.push_back(timeMax);
  }

  vMin->getOptions()->intervalsType = PViewOptions::Numeric;
  vMax->getOptions()->intervalsType = PViewOptions::Numeric;

  dataMin->setName(data1->getName() + "_Min");
  dataMin->setFileName(data1->getName() + "_Min.pos");
  dataMin->finalize();
  dataMax->setName(data1->getName() + "_Max");
  dataMax->setFileName(data1->getName() + "_Max.pos");
  dataMax->finalize();

  return nullptr;
}

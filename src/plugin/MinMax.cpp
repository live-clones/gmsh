// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MinMax.h"
#include "PViewOptions.h"

GMSH_MinMaxPlugin::GMSH_MinMaxPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""},
                     {GMSH_FULLRC, "OverTime", nullptr, 0, ""},
                     {GMSH_FULLRC, "Argument", nullptr, 0, ""},
                     {GMSH_FULLRC, "Visible", nullptr, 1, ""}})
{
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

PView *GMSH_MinMaxPlugin::execute(PView *v)
{
  int iView = (int)option(0);
  int overTime = (int)option(1);
  int argument = (int)option(2);
  bool visible = (bool)option(3);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = getPossiblyAdaptiveData(v1);
  PView *vMin = new PView();
  PView *vMax = new PView();
  PViewDataList *dataMin = getDataList(vMin);
  PViewDataList *dataMax = getDataList(vMax);

  // the point the values are appended to
  std::vector<double> *sMin = nullptr, *sMax = nullptr;
  if(!argument) {
    SPoint3 c = data1->getBoundingBox().center();
    sMin = dataMin->incrementList(1, TYPE_PNT);
    sMax = dataMax->incrementList(1, TYPE_PNT);
    sMin->insert(sMin->end(), {c.x(), c.y(), c.z()});
    sMax->insert(sMax->end(), {c.x(), c.y(), c.z()});
  }

  double min = VAL_INF, max = -VAL_INF, timeMin = 0, timeMax = 0;
  double pmin[3] = {0., 0., 0.}, pmax[3] = {0., 0., 0.}; // over time

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
          sMin = dataMin->incrementList(1, TYPE_PNT);
          sMax = dataMax->incrementList(1, TYPE_PNT);
          sMin->insert(sMin->end(), {xmin, ymin, zmin});
          sMax->insert(sMax->end(), {xmax, ymax, zmax});
        }
        else {
          double time = data1->getTime(step);
          dataMin->addTime(time);
          dataMax->addTime(time);
        }
        sMin->push_back(minView);
        sMax->push_back(maxView);
      }
      else {
        if(minView < min) {
          min = minView;
          timeMin = data1->getTime(step);
          pmin[0] = xmin;
          pmin[1] = ymin;
          pmin[2] = zmin;
        }
        if(maxView > max) {
          max = maxView;
          timeMax = data1->getTime(step);
          pmax[0] = xmax;
          pmax[1] = ymax;
          pmax[2] = zmax;
        }
      }
    }
  }

  if(overTime) {
    if(argument) {
      sMin = dataMin->incrementList(1, TYPE_PNT);
      sMax = dataMax->incrementList(1, TYPE_PNT);
      sMin->insert(sMin->end(), pmin, pmin + 3);
      sMax->insert(sMax->end(), pmax, pmax + 3);
    }
    sMin->push_back(min);
    sMax->push_back(max);
    dataMin->addTime(timeMin);
    dataMax->addTime(timeMax);
  }

  vMin->getOptions()->intervalsType = PViewOptions::Numeric;
  vMax->getOptions()->intervalsType = PViewOptions::Numeric;

  dataMin->setName(data1->getName() + "_Min");
  dataMin->setFileName(data1->getName() + "_Min.pos");
  dataMin->finalize();
  dataMax->setName(data1->getName() + "_Max");
  dataMax->setFileName(data1->getName() + "_Max.pos");
  dataMax->finalize();

  return vMax;
}

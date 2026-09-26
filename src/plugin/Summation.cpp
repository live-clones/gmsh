// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Summation.h"
#include "GEntity.h"
#include <algorithm>

GMSH_SummationPlugin::GMSH_SummationPlugin()
  : GMSH_PostPlugin(
      {{GMSH_FULLRC, "View0", nullptr, -1., ""},
       {GMSH_FULLRC, "View1", nullptr, -1., ""},
       {GMSH_FULLRC, "View2", nullptr, -1., ""},
       {GMSH_FULLRC, "View3", nullptr, -1., ""},
       {GMSH_FULLRC, "View4", nullptr, -1., ""},
       {GMSH_FULLRC, "View5", nullptr, -1., ""},
       {GMSH_FULLRC, "View6", nullptr, -1., ""},
       {GMSH_FULLRC, "View7", nullptr, -1., ""}},
      {{GMSH_FULLRC, "ResultingViewName", nullptr, "default", ""}})
{
}

std::string GMSH_SummationPlugin::getHelp() const
{
  return "Plugin(Summation) sums every time step of the views `View0', "
         "..., `View7' and stores the result in a new view, named "
         "`ResultingViewName' (unless it is `default').\n\n"
         "If `View0' < 0, the current view is used; views `View1' to `View7' "
         "< 0 are skipped.\n\n"
         "The views can have different numbers of time steps, but they must "
         "share the same mesh, and the mesh must not move between time "
         "steps.\n\n"
         "Plugin(Summation) creates one new list-based view.";
}

PView *GMSH_SummationPlugin::execute(PView *view)
{
  int nviewmax = 8;
  std::vector<int> views_indices;
  std::vector<PView *> pviews;
  std::vector<PViewData *> pviewsdata;

  // Get view indices and PViews
  for(int i = 0; i < nviewmax; i++) {
    int iview = (int)option(i);
    if(i == 0 || iview > -1) {
      views_indices.push_back(iview);
      pviews.push_back(getView(iview, view));
      if(!pviews.back()) {
        Msg::Error("Summation plugin could not find view %i", iview);
        return view;
      }
      pviewsdata.push_back(getPossiblyAdaptiveData(pviews.back()));
      if(pviewsdata.back()->hasMultipleMeshes()) {
        Msg::Error("Summation plugin cannot be applied to multi-mesh views");
        return view;
      }
    }
  }
  // Number of view to sum
  int nviews = pviews.size();
  // Check if the views share the same mesh
  //(at least same number of elements and entities)
  // If a view has an empty timestep: skip it, no problem.
  for(int j = 1; j < nviews; j++) {
    if(pviewsdata[j]->getNumEntities() == 0 &&
       pviewsdata[j]->getNumElements() == 0)
      continue; // empty time step
    if((pviewsdata[0]->getNumEntities() != pviewsdata[j]->getNumEntities()) ||
       (pviewsdata[0]->getNumElements() != pviewsdata[j]->getNumElements())) {
      Msg::Error("Summation plugin: views based on different grid.");
      return view;
    }
  }
  // get min/max indices of time steps
  int timeBeg = pviewsdata[0]->getFirstNonEmptyTimeStep();
  int timeEnd = pviewsdata[0]->getNumTimeSteps();
  int iref = 0; // reference view and time step to get mesh's info
  int stepref = timeBeg;
  for(int i = 1; i < nviews; i++) {
    if(timeBeg > pviewsdata[i]->getFirstNonEmptyTimeStep()) {
      timeBeg = pviewsdata[i]->getFirstNonEmptyTimeStep();
      iref = i;
      stepref = timeBeg;
    }
    timeEnd = std::max(timeEnd, pviewsdata[i]->getNumTimeSteps());
  }
  // Init result
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < pviewsdata[iref]->getNumEntities(stepref); ent++) {
    for(int ele = 0; ele < pviewsdata[iref]->getNumElements(stepref, ent);
        ele++) {
      if(pviewsdata[iref]->skipElement(stepref, ent, ele)) continue;
      int numNodes = getNumCornerNodes(pviewsdata[iref], stepref, ent, ele);
      if(!numNodes) continue;
      int type = pviewsdata[iref]->getType(stepref, ent, ele);
      int numComp = pviewsdata[iref]->getNumComponents(stepref, ent, ele);
      int numComp2 = numComp;
      std::vector<double> *out = data2->incrementList(numComp2, type, numNodes);
      if(!out) continue;
      std::vector<double> v(std::max(9, numComp), 0.);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        pviewsdata[iref]->getNode(stepref, ent, ele, nod, x[nod], y[nod],
                                  z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = timeBeg; step < timeEnd; step++) {
        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < numComp; comp++) {
            v[comp] = 0;
            for(int iview = 0; iview < nviews; iview++) {
              if(!pviewsdata[iview]->hasTimeStep(step) ||
                 pviewsdata[iview]->skipElement(step, ent, ele))
                continue;
              double d;
              pviewsdata[iview]->getValue(step, ent, ele, nod, comp, d);
              v[comp] += d;
            }
          }
          for(int i = 0; i < numComp2; i++) out->push_back(v[i]);
        }
      }
    }
  }

  // Set time
  for(int step = timeBeg; step < timeEnd; step++) {
    int iview = 0;
    while(iview < nviews && !pviewsdata[iview]->hasTimeStep(step)) iview++;
    data2->Time.push_back(iview < nviews ? pviewsdata[iview]->getTime(step) :
                                           step);
  }

  std::string outputname = optionStr(0);
  if(outputname == "default")
    outputname = pviewsdata[0]->getName() + "_Summation";

  data2->setName(outputname);
  data2->setFileName(outputname + ".pos");
  data2->finalize();

  return v2;
}

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <cstdio>
#include <map>
#include <string>
#include <vector>

#include "GuiStatistics.h"
#include "Gui.h"
#include "GuiDeclare.h"
#include "GModel.h"
#include "Context.h"
#include "GEntity.h"
#include "MElement.h"
#include "OS.h"
#include "drawContext.h"
#include "GmshMessage.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#include "adaptiveData.h"
#endif

using namespace Ui;
using namespace Declare;

GuiStatistics::GuiStatistics()
{
  for(int i = 0; i < 50; i++) s[i] = 0.;
  for(int i = 0; i < 10; i++) adapted[i] = 0.;
  for(int i = 0; i < 9; i++) qualityStats[i] = 0.;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 101; j++) quality[i][j] = 0.;
}

#if defined(HAVE_POST)
// the points, lines, triangles, quadrangles, tetrahedra, hexahedra, prisms,
// pyramids and trihedra of a view; for model-based data, those that have data
// at the step shown (the model may have more: e.g. a view of the part of a
// partitioned mesh a process computed, in the model of all the parts)
static void countViewElements(PView *p, double count[9])
{
  PViewData *data = p->getData();
  if(!dynamic_cast<PViewDataGModel *>(data)) {
    count[0] += data->getNumPoints();
    count[1] += data->getNumLines();
    count[2] += data->getNumTriangles();
    count[3] += data->getNumQuadrangles();
    count[4] += data->getNumTetrahedra();
    count[5] += data->getNumHexahedra();
    count[6] += data->getNumPrisms();
    count[7] += data->getNumPyramids();
    count[8] += data->getNumTrihedra();
    return;
  }
  int step = p->getOptions()->timeStep;
  if(!data->hasTimeStep(step)) step = data->getFirstNonEmptyTimeStep();
  if(!data->hasTimeStep(step)) return;
  for(int ent = 0; ent < data->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
      if(data->skipElement(step, ent, ele)) continue;
      switch(data->getType(step, ent, ele)) {
      case TYPE_PNT: count[0]++; break;
      case TYPE_LIN: count[1]++; break;
      case TYPE_TRI: count[2]++; break;
      case TYPE_QUA: count[3]++; break;
      case TYPE_TET: count[4]++; break;
      case TYPE_HEX: count[5]++; break;
      case TYPE_PRI: count[6]++; break;
      case TYPE_PYR: count[7]++; break;
      case TYPE_TRIH: count[8]++; break;
      }
    }
  }
}
#endif

void GuiStatistics::compute(bool elementQuality)
{
#if defined(HAVE_MESH)
  GetStatistics(s, elementQuality ? quality : nullptr, visibleOnly);
  // the qualities computed last are kept (e.g. when the histogram adds a view)
  // as long as neither the mesh nor the entities counted change
  CTX *ctx = CTX::instance();
  std::vector<std::size_t> key = {
    (std::size_t)GModel::current(), (std::size_t)ctx->meshContentStamp,
    visibleOnly, visibleOnly ? (std::size_t)ctx->entityVisibilityStamp : 0};
  for(int i = 4; i < 14; i++) key.push_back((std::size_t)s[i]);
  if(elementQuality) {
    qualityKey = key;
    for(int i = 0; i < 9; i++) qualityStats[i] = s[18 + i];
  }
  else if(!qualityKey.empty() && key == qualityKey) {
    elementQuality = true;
    for(int i = 0; i < 9; i++) s[18 + i] = qualityStats[i];
  }
  else
    qualityKey.clear();
  qualityDone = elementQuality;
#else
  Msg::Error("Statistics require the mesh module");
#endif

  // the views here, not in GetStatistics(), which the options reading the
  // numbers of mesh elements call
  for(int i = 27; i < 38; i++) s[i] = 0.;
  for(int i = 0; i < 10; i++) adapted[i] = 0.;
#if defined(HAVE_POST)
  s[27] = PView::list.size();
  for(auto p : PView::list) {
    countViewElements(p, &s[28]);
    s[37] += p->getData()->getNumStrings2D() + p->getData()->getNumStrings3D();
  }
  // the elements of the adaptive views, as last refined (they are refined
  // when they are used, as drawn, not here), with those refined apart where
  // the clipping planes cut them (see PView::refineClipLayer())
  for(auto p : PView::list) {
    bool refined = false;
    for(adaptiveData *ad :
        {p->getData()->getAdaptiveData(), p->getClipAdaptiveData()}) {
      PViewData *d = ad ? ad->getData() : nullptr;
      if(!d) continue;
      refined = true;
      adapted[1] += d->getNumPoints();
      adapted[2] += d->getNumLines();
      adapted[3] += d->getNumTriangles();
      adapted[4] += d->getNumQuadrangles();
      adapted[5] += d->getNumTetrahedra();
      adapted[6] += d->getNumHexahedra();
      adapted[7] += d->getNumPrisms();
      adapted[8] += d->getNumPyramids();
      adapted[9] += d->getNumTrihedra();
    }
    if(refined) adapted[0] += 1;
  }
#endif
}

void GuiStatistics::refresh()
{
  if(!Gui::instance().available() || !visible()) return;
  compute(false);
  reload();
}

void GuiStatistics::histogram(int which, bool threeD)
{
#if defined(HAVE_POST)
  const char *name = (which == 0) ? "SICN" : (which == 1) ? "Gamma" : "SIGE";
  if(!threeD) {
    // SICN and SIGE run from -1 to 1, Gamma from 0 to 1
    std::vector<double> x, y;
    for(int i = 0; i < 101; i++) {
      x.push_back(which == 1 ? (double)i / 100. : (double)(2 * i - 100) / 100.);
      y.push_back(quality[which][i]);
    }
    new PView(name, "# Elements", x, y);
  }
  else {
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(visibleOnly && !entities[i]->getVisibility()) continue;
      if(entities[i]->dim() < 2) continue;
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        if(which == 0)
          d[e->getNum()].push_back(e->minSICNShapeMeasure());
        else if(which == 1)
          d[e->getNum()].push_back(e->gammaShapeMeasure());
        else
          d[e->getNum()].push_back(e->minSIGEShapeMeasure());
      }
    }
    new PView(name, "ElementData", GModel::current(), d);
  }
  Gui::instance().updateViews(true, true);
  drawContext::global()->draw();
#else
  Msg::Error("Histograms require the post-processing module");
#endif
}

Form GuiStatistics::build()
{
  auto stat = [this](const std::string &name, int index) {
    return output(name, [this, index]() {
      char tmp[64];
      sprintf(tmp, "%g", s[index]);
      return std::string(tmp);
    });
  };
  // the three buttons of a measure stand under one another from one line to the
  // next: what the grid is for
  auto computed = [this]() { return qualityDone; };
  auto measure = [&](const std::string &name, const std::string &tip,
                     int index, int which) {
    return hbox({output(name,
                        [this, index]() {
                          if(!qualityDone) return std::string("Press Update");
                          char tmp[128];
                          sprintf(tmp, "%.4g (%.4g->%.4g)", s[index],
                                  s[index + 1], s[index + 2]);
                          return std::string(tmp);
                        })
                   .tip(tip)
                   .enabledWhen(computed),
                 label("Plot"),
                 button("X-Y", [this, which]() { histogram(which, false); })
                   .sized(3.)
                   .enabledWhen(computed),
                 button("3D", [this, which]() { histogram(which, true); })
                   .sized(3.)});
  };
  const char *counts[] = {"Nodes",      "Points",    "Lines",  "Triangles",
                          "Quadrangles", "Tetrahedra", "Hexahedra", "Prisms",
                          "Pyramids",   "Trihedra"};
  std::vector<Item> mesh;
  for(int i = 0; i < 10; i++) mesh.push_back(stat(counts[i], 4 + i));
  mesh.push_back(stat("Time for 1D mesh", 14));
  mesh.push_back(stat("Time for 2D mesh", 15));
  mesh.push_back(stat("Time for 3D mesh", 16));
  mesh.push_back(measure("SICN", "~ signed inverse condition number", 18, 0));
  mesh.push_back(measure(
    "Gamma", "~ inscribed_radius / circumscribed_radius (simplices)", 21, 1));
  mesh.push_back(
    measure("SIGE", "~ signed inverse error on gradient FE solution", 24, 2));
  mesh.push_back(
    check("Compute statistics for visible entities only", &visibleOnly));

  // the data as given, and the elements the adaptive views are refined into
  // (empty and greyed out if no view is refined; no strings in the refined
  // data)
  const char *views[] = {"Views",      "Points",    "Lines",    "Triangles",
                         "Quadrangles", "Tetrahedra", "Hexahedra", "Prisms",
                         "Pyramids",   "Trihedra",  "Strings"};
  auto refined = [this](const std::string &name, int index) {
    return output(name,
                  [this, index]() {
                    if(!adapted[0] || index >= 10) return std::string("");
                    char tmp[64];
                    sprintf(tmp, "%g", adapted[index]);
                    return std::string(tmp);
                  })
      .tip("The elements of the adaptive views as last refined (they are "
           "refined when drawn), with those refined apart where clipping "
           "planes cut")
      .enabledWhen([this, index]() { return adapted[0] && index < 10; });
  };
  std::vector<Item> post = {hbox({label("Data"), label("Adapted")})};
  for(int i = 0; i < 11; i++)
    post.push_back(hbox({stat("", 27 + i), refined(views[i], i)}));

  return {"statistics", "Statistics",
          vbox({tabs({{"Geometry", vbox({stat("Points", 0), stat("Curves", 1),
                                         stat("Surfaces", 2), stat("Volumes", 3),
                                         stat("Physical groups", 45)})},
                      {"Mesh", grid(mesh)},
                      {"Post-processing", grid(post)}}),
                hbox({label([]() {
                        std::size_t m = GetMemoryUsage();
                        if(!m) return std::string("");
                        char tmp[64];
                        sprintf(tmp, "Memory usage: %gMB", m / 1024. / 1024.);
                        return std::string(tmp);
                      }),
                      gap(),
                      button("Update", [this]() { compute(true); }).byDefault()})})};
}

void GuiStatistics::show(const std::string &pane)
{
  std::string on = pane;
  if(!visible()) {
    compute(false);
    if(on.empty()) {
      on = "Geometry";
      if(GModel::current()->getMeshStatus(true) > 0) on = "Mesh";
#if defined(HAVE_POST)
      else if(PView::list.size()) on = "Post-processing";
#endif
    }
  }
  GuiTabbed::show(on);
}

#endif

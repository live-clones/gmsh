// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// turning a mesh with no geometry under it into a model: the edges sharper than
// the angle are the curves between surfaces; three steps done in order, two by
// picking in the view

#include "GmshConfig.h"

#include <algorithm>
#include <string>
#include <vector>

#include "GuiClassify.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "Context.h"
#include "Options.h"
#include "drawContext.h"
#include "discreteEdge.h"

#if defined(HAVE_MESH)
#include "meshGFaceOptimize.h"
#endif

using namespace Ui;
using namespace Declare;

GEdge *GuiClassify::curve()
{
  if(!selected) {
    selected = new discreteEdge(
      GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
      nullptr, nullptr);
    GModel::current()->add(selected);
  }
  return selected;
}

// sharper first: the list is sorted, so the first angle under the threshold
// ends it
void GuiClassify::updateEdges()
{
  GEdge *curve = selected;
  if(!curve) return;
  for(std::size_t i = 0; i < curve->lines.size(); i++) delete curve->lines[i];
  curve->lines.clear();

#if defined(HAVE_MESH)
  double threshold = angle / 180. * M_PI;
  for(const edge &e : detected) {
    if(e.angle <= threshold) break;
    curve->lines.push_back(new MLine(e.v1, e.v2));
  }
  if(boundary)
    for(const edge &e : lonely) curve->lines.push_back(new MLine(e.v1, e.v2));
  Msg::Info("Edges: %d inside, %d boundary, %d selected", (int)detected.size(),
            (int)lonely.size(), (int)curve->lines.size());
#endif

  CTX::instance()->meshChanged();
  drawContext::global()->draw();
}

// every surface element of the model, or the ones picked in the view
void GuiClassify::selectElements(bool all)
{
  curve();

  if(all) {
    for(auto it = GModel::current()->firstFace();
        it != GModel::current()->lastFace(); ++it) {
      elements.insert(elements.end(), (*it)->triangles.begin(),
                      (*it)->triangles.end());
      elements.insert(elements.end(), (*it)->quadrangles.begin(),
                      (*it)->quadrangles.end());
    }
  }
  else {
    CTX::instance()->pickElements = 1;
    while(1) {
      drawContext::global()->draw();
      Msg::StatusGl("Select elements\n"
                    "[Press 'e' to end selection or 'q' to abort]");
      char ib = Gui::instance().selectEntity(ENT_ALL);
      if(!Gui::instance().available()) break;
      if(ib == 'l') {
        for(auto *me : Gui::instance().selectedElements()) {
          if(me->getDim() == 2 && me->getVisibility() != 2) {
            me->setVisibility(2);
            elements.push_back(me);
          }
        }
      }
      if(ib == 'r') {
        for(auto *me : Gui::instance().selectedElements()) {
          if(me->getVisibility() == 2) {
            auto it = std::find(elements.begin(), elements.end(), me);
            if(it != elements.end()) elements.erase(it);
          }
          me->setVisibility(1);
        }
      }
      if(ib == 'e') {
        GModel::current()->setSelection(0);
        break;
      }
      if(ib == 'q') {
        GModel::current()->setSelection(0);
        elements.clear();
        break;
      }
    }
    CTX::instance()->pickElements = 0;
  }

#if defined(HAVE_MESH)
  e2t_cont adj;
  buildEdgeToElements(elements, adj);
  std::vector<edge_angle> inside, alone;
  buildListOfEdgeAngle(adj, inside, alone);
  detected.clear();
  lonely.clear();
  for(const edge_angle &ea : inside)
    detected.push_back({ea.v1, ea.v2, ea.angle});
  for(const edge_angle &ea : alone) lonely.push_back({ea.v1, ea.v2, ea.angle});
#else
  Msg::Error("Reclassifying surfaces requires the mesh module");
#endif

  updateEdges();
  Msg::StatusGl("");
}

// what the threshold keeps is a guess: edges may be taken out by picking
void GuiClassify::deleteEdges()
{
  GEdge *curve = selected;
  if(!curve) return;

  CTX::instance()->pickElements = 1;
  std::vector<MLine *> picked;
  while(1) {
    drawContext::global()->draw();
    Msg::StatusGl("Select elements\n"
                  "[Press 'e' to end selection or 'q' to abort]");
    char ib = Gui::instance().selectEntity(ENT_ALL);
    if(!Gui::instance().available()) break;
    if(ib == 'l') {
      for(auto *me : Gui::instance().selectedElements()) {
        if(me->getType() == TYPE_LIN && me->getVisibility() != 2) {
          me->setVisibility(2);
          picked.push_back((MLine *)me);
        }
      }
    }
    if(ib == 'r') {
      for(auto *me : Gui::instance().selectedElements()) {
        if(me->getVisibility() == 2) {
          auto it = std::find(picked.begin(), picked.end(), me);
          if(it != picked.end()) picked.erase(it);
        }
        me->setVisibility(1);
      }
    }
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      break;
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      picked.clear();
      break;
    }
  }

  std::sort(picked.begin(), picked.end());

  std::vector<MLine *> keep;
  keep.swap(curve->lines);
  for(std::size_t i = 0; i < keep.size(); i++) {
    if(std::find(picked.begin(), picked.end(), keep[i]) != picked.end())
      delete keep[i];
    else
      curve->lines.push_back(keep[i]);
  }

  CTX::instance()->meshChanged();
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");

  elements.clear();
  detected.clear();
}

void GuiClassify::reset()
{
  GEdge *curve = selected;
  if(!curve) return;
  for(std::size_t i = 0; i < curve->lines.size(); i++) delete curve->lines[i];
  curve->lines.clear();
  curve->deleteVertexArrays();
  elements.clear();
  detected.clear();
  CTX::instance()->meshChanged();
  drawContext::global()->draw();
}

void GuiClassify::classify()
{
  meshClassifySurfaces(angle, parametrizable, &selected);
  elements.clear();
  detected.clear();
  lonely.clear();
}

// the edges alone, and the surfaces back afterwards
void GuiClassify::showOnlyEdges()
{
  if(onlyEdges) {
    wasSurfaceFaces = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
    wasSurfaceEdges = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0.);
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, 0.);
  }
  else {
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, wasSurfaceFaces);
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, wasSurfaceEdges);
  }
  drawContext::global()->draw();
}

void GuiClassify::load()
{
  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
  drawContext::global()->draw();
}

Form GuiClassify::build()
{
  // what one may do next hangs on whether anything has been selected
  auto selecting = [this]() { return elements.size() > 0; };
  auto update = [this]() { updateEdges(); };
  return {
    "classify", "Reclassify 2D",
    vbox(
      {heading("1. Select mesh elements on which to perform edge detection"),
       hbox({button("Select elements", [this]() { selectElements(false); }),
             button("All", [this]() { selectElements(true); }),
             check(
               "Hide unselected elements",
               []() { return CTX::instance()->hideUnselected != 0; },
               [](bool on) { CTX::instance()->hideUnselected = on ? 1 : 0; })
               .onChanged([]() {
                 CTX::instance()->meshChanged();
                 drawContext::global()->draw();
               })}),
       rule(), heading("2. Fine-tune edge selection"),
       hbox({number("Threshold angle", &angle)
               .within(0., 180., 1.)
               .sized(5.)
               .enabledWhen(selecting)
               .onChanged(update),
             check("Show only edges", &onlyEdges).onChanged([this]() {
               showOnlyEdges();
             })}),
       check("Include edges on boundary (closure)", &boundary)
         .enabledWhen(selecting)
         .onChanged(update),
       hbox({button("Delete edges from selection", [this]() { deleteEdges(); })
               .enabledWhen(selecting),
             button("Reset selection", [this]() { reset(); })
               .enabledWhen(selecting)}),
       rule(), heading("3. Reclassify surfaces using selected edges"),
       check("Create parametrized discrete model", &parametrizable)
         .tip("Cut the surfaces further so that each of them can be "
              "parametrized, and build the geometry of the discrete entities"),
       button("Reclassify", [this]() { classify(); })
         .byDefault()
         .enabledWhen(selecting)})};
}

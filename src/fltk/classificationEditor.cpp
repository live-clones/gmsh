// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "classificationEditor.h"
#include "paletteWindow.h"
#include "Numeric.h"
#include "drawContext.h"
#include "Options.h"
#include "Context.h"
#include "GmshMessage.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GModelParametrize.h"

#if defined(HAVE_MESH)
#include "meshGFaceDelaunayInsertion.h"
#endif

static void NoElementsSelectedMode(classificationEditor *e)
{
  e->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->activate();
  e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->activate();

  e->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->deactivate();
  e->buttons[CLASS_BUTTON_RESET_SELECTION]->deactivate();
  e->toggles[CLASS_TOGGLE_BOUNDARY]->deactivate();
  e->inputs[CLASS_VALUE_ANGLE]->deactivate();
  e->buttons[CLASS_BUTTON_CLASSIFY]->deactivate();

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");
}

static void ElementsSelectedMode(classificationEditor *e)
{
  e->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->activate();
  e->buttons[CLASS_BUTTON_RESET_SELECTION]->activate();
  e->toggles[CLASS_TOGGLE_BOUNDARY]->activate();
  e->inputs[CLASS_VALUE_ANGLE]->activate();
  e->buttons[CLASS_BUTTON_CLASSIFY]->activate();
}

static void update_edges_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;

  if(!e->selected) return;

  for(std::size_t i = 0; i < e->selected->lines.size(); i++)
    delete e->selected->lines[i];
  e->selected->lines.clear();

#if defined(HAVE_MESH)
  double threshold = e->inputs[CLASS_VALUE_ANGLE]->value() / 180. * M_PI;
  for(std::size_t i = 0; i < e->edges_detected.size(); i++) {
    edge_angle ea = e->edges_detected[i];
    if(ea.angle <= threshold) break;
    e->selected->lines.push_back(new MLine(ea.v1, ea.v2));
  }

  if(e->toggles[CLASS_TOGGLE_BOUNDARY]->value()) {
    for(std::size_t i = 0; i < e->edges_lonly.size(); i++) {
      edge_angle ea = e->edges_lonly[i];
      e->selected->lines.push_back(new MLine(ea.v1, ea.v2));
    }
  }
#endif

  Msg::Info("Edges: %d inside, %d boundary, %d selected",
            (int)e->edges_detected.size(), (int)e->edges_lonly.size(),
            (int)e->selected->lines.size());

  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

static void select_elements_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  bool all = (w == e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]);

  // allocate discrete edge to hold the selected mesh segments
  if(!e->selected) {
    e->selected = new discreteEdge(
      GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
      nullptr, nullptr);
    GModel::current()->add(e->selected);
  }

  if(all) {
    for(auto it = GModel::current()->firstFace();
        it != GModel::current()->lastFace(); ++it) {
      e->elements.insert(e->elements.end(), (*it)->triangles.begin(),
                         (*it)->triangles.end());
      e->elements.insert(e->elements.end(), (*it)->quadrangles.begin(),
                         (*it)->quadrangles.end());
    }
  }
  else {
    CTX::instance()->pickElements = 1;
    while(1) {
      CTX::instance()->mesh.changed = ENT_ALL;
      drawContext::global()->draw();
      Msg::StatusGl("Select elements\n"
                    "[Press 'e' to end selection or 'q' to abort]");

      char ib = FlGui::instance()->selectEntity(ENT_ALL);
      if(ib == 'l') {
        for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
            i++) {
          MElement *me = FlGui::instance()->selectedElements[i];
          if(me->getDim() == 2 && me->getVisibility() != 2) {
            me->setVisibility(2);
            e->elements.push_back(me);
          }
        }
      }
      if(ib == 'r') {
        for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
            i++) {
          MElement *me = FlGui::instance()->selectedElements[i];
          if(me->getVisibility() == 2)
            e->elements.erase(
              std::find(e->elements.begin(), e->elements.end(), me));
          me->setVisibility(1);
        }
      }
      if(ib == 'e') { // ok, compute the edges
        GModel::current()->setSelection(0);
        break;
      }
      if(ib == 'q') { // do nothing
        GModel::current()->setSelection(0);
        e->elements.clear();
        break;
      }
    }
    CTX::instance()->pickElements = 0;
  }

#if defined(HAVE_MESH)
  e2t_cont adj;
  buildEdgeToElements(e->elements, adj);
  buildListOfEdgeAngle(adj, e->edges_detected, e->edges_lonly);
#else
  Msg::Error("Classification requires mesh module");
#endif

  ElementsSelectedMode(e);
  update_edges_cb(nullptr, data);
  Msg::StatusGl("");
}

static void hide_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->hideUnselected = !CTX::instance()->hideUnselected;
  CTX::instance()->mesh.changed = ENT_ALL;
  drawContext::global()->draw();
}

static void show_only_edges_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  static int old_sf = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
  static int old_se = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
  if(e->toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->value()) {
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
    old_sf = (int)opt_mesh_surface_faces(0, GMSH_GET, 0.);
    old_se = (int)opt_mesh_surface_edges(0, GMSH_GET, 0.);
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0.);
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, 0.);
  }
  else {
    opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, old_sf);
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, old_se);
  }
  drawContext::global()->draw();
}

static void delete_edge_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;

  if(!e->selected) return;

  CTX::instance()->pickElements = 1;
  std::vector<MLine *> ele;

  while(1) {
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();

    Msg::StatusGl("Select elements\n"
                  "[Press 'e' to end selection or 'q' to abort]");

    char ib = FlGui::instance()->selectEntity(ENT_ALL);
    if(ib == 'l') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
          i++) {
        MElement *me = FlGui::instance()->selectedElements[i];
        if(me->getType() == TYPE_LIN && me->getVisibility() != 2) {
          me->setVisibility(2);
          ele.push_back((MLine *)me);
        }
      }
    }
    if(ib == 'r') {
      for(std::size_t i = 0; i < FlGui::instance()->selectedElements.size();
          i++) {
        MElement *me = FlGui::instance()->selectedElements[i];
        if(me->getVisibility() == 2)
          ele.erase(std::find(ele.begin(), ele.end(), me));
        me->setVisibility(1);
      }
    }
    if(ib == 'e') {
      GModel::current()->setSelection(0);
      break;
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      ele.clear();
      break;
    }
  }

  std::sort(ele.begin(), ele.end());

  // look in all selected edges if a deleted one is present and delete it
  std::vector<MLine *> temp = e->selected->lines;
  e->selected->lines.clear();
  for(std::size_t i = 0; i < temp.size(); i++) {
    auto it = std::find(ele.begin(), ele.end(), temp[i]);
    if(it != ele.end())
      delete temp[i];
    else
      e->selected->lines.push_back(temp[i]);
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");

  e->elements.clear();
  e->edges_detected.clear();
}

static void reset_selection_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  if(!e->selected) return;
  for(std::size_t i = 0; i < e->selected->lines.size(); i++)
    delete e->selected->lines[i];
  e->selected->lines.clear();
  e->selected->deleteVertexArrays();
  e->elements.clear();
  e->edges_detected.clear();
  NoElementsSelectedMode(e);
}

static void classify_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;

  if(!e->selected) {
    e->selected = new discreteEdge(
      GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
      nullptr, nullptr);
    GModel::current()->add(e->selected);
  }

  computeDiscreteCurvatures(GModel::current());
  if(e->toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES]->value())
    computeEdgeCut(GModel::current(), e->selected->lines, 100000);
  computeNonManifoldEdges(GModel::current(), e->selected->lines, true);
  double threshold = e->inputs[CLASS_VALUE_ANGLE]->value() / 180. * M_PI;
  classifyFaces(GModel::current(), threshold);

  // remove selected, but do not delete its elements
  if(e->selected) {
    GModel::current()->remove(e->selected);
    e->selected->lines.clear();
    delete e->selected;
    e->selected = nullptr;
  }

  GModel::current()->pruneMeshVertexAssociations();

  e->elements.clear();
  e->edges_detected.clear();

  if(e->toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES]->value())
    GModel::current()->createGeometryOfDiscreteEntities();

  NoElementsSelectedMode(e);
}

classificationEditor::classificationEditor() : selected(nullptr)
{
  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);

  drawContext::global()->draw();

  int BBB = (int)(1.4 * BB);
  const int width = (int)(3.15 * BBB), height = (int)(10.5 * BH);

  window = new paletteWindow(width, height,
                             CTX::instance()->nonModalWindows ? true : false,
                             "Reclassify 2D");
  window->box(GMSH_WINDOW_BOX);

  int x = WB, y = WB;
  {
    Fl_Box *b =
      new Fl_Box(x, y, width, BH,
                 "1. Select mesh elements on which to perform edge detection");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    x += WB;
    y += BH;
    buttons[CLASS_BUTTON_SELECT_ELEMENTS] =
      new Fl_Button(x, y, BBB, BH, "Select elements");
    buttons[CLASS_BUTTON_SELECT_ELEMENTS]->callback(select_elements_cb, this);

    buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS] =
      new Fl_Button(x + BBB + WB, y, (int)(0.5 * BBB) - WB, BH, "All");
    buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->callback(select_elements_cb,
                                                        this);

    toggles[CLASS_TOGGLE_HIDE] = new Fl_Check_Button(
      (int)(x + 1.5 * BBB + WB), y, (int)(width - 1.5 * BBB - x - 2 * WB), BH,
      "Hide unselected elements");
    toggles[CLASS_TOGGLE_HIDE]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_HIDE]->callback(hide_cb, this);

    x -= WB;
  }
  {
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 2 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }
  {
    y += BH;
    Fl_Box *b = new Fl_Box(x, y, width, BH, "2. Fine-tune edge selection");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    x += WB;
    y += BH;
    inputs[CLASS_VALUE_ANGLE] =
      new Fl_Value_Input(x, y, 2 * BBB / 3, BH, "Threshold angle");
    inputs[CLASS_VALUE_ANGLE]->value(40);
    inputs[CLASS_VALUE_ANGLE]->maximum(180);
    inputs[CLASS_VALUE_ANGLE]->minimum(0);
    if(CTX::instance()->inputScrolling) inputs[CLASS_VALUE_ANGLE]->step(1);
    inputs[CLASS_VALUE_ANGLE]->align(FL_ALIGN_RIGHT);
    inputs[CLASS_VALUE_ANGLE]->when(FL_WHEN_RELEASE);
    inputs[CLASS_VALUE_ANGLE]->callback(update_edges_cb, this);

    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES] = new Fl_Check_Button(
      (int)(x + 1.5 * BBB + WB), y, (int)(width - x - 1.5 * BBB - 2 * WB), BH,
      "Show only edges");
    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->callback(show_only_edges_cb, this);

    y += BH;
    toggles[CLASS_TOGGLE_BOUNDARY] = new Fl_Check_Button(
      x, y, width - x - 2 * WB, BH, "Include edges on boundary (closure)");
    toggles[CLASS_TOGGLE_BOUNDARY]->type(FL_TOGGLE_BUTTON);
    toggles[CLASS_TOGGLE_BOUNDARY]->callback(update_edges_cb, this);

    y += BH;
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION] =
      new Fl_Button(x, y, (int)(1.5 * BBB), BH, "Delete edges from selection");
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->callback(delete_edge_cb, this);
    buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->deactivate();

    buttons[CLASS_BUTTON_RESET_SELECTION] =
      new Fl_Button(x + (int)(1.5 * BBB + WB), y, BBB, BH, "Reset selection");
    buttons[CLASS_BUTTON_RESET_SELECTION]->callback(reset_selection_cb, this);
    buttons[CLASS_BUTTON_RESET_SELECTION]->deactivate();

    x -= WB;
  }
  {
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 2 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }
  {
    y += BH;
    Fl_Box *b = new Fl_Box(x, y, width, BH,
                           "3. Reclassify surfaces using selected edges");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    x += WB;

    y += BH;
    toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES] = new Fl_Check_Button(
      x, y, width - x - 2 * WB, BH, "Create parametrized discrete model");
    toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES]->type(
      FL_TOGGLE_BUTTON);

    y += BH;
    buttons[CLASS_BUTTON_CLASSIFY] = new Fl_Return_Button(
      (int)(x /*+ 1.5 * BBB + WB*/), y, BBB, BH, "Reclassify");
    buttons[CLASS_BUTTON_CLASSIFY]->callback(classify_cb, this);
    buttons[CLASS_BUTTON_CLASSIFY]->activate();

    x -= WB;
  }

  window->end();
  window->hotspot(window);

  NoElementsSelectedMode(this);
}

void mesh_classify_cb(Fl_Widget *w, void *data)
{
  // create the (static) editor
  static classificationEditor *editor = nullptr;
  if(!editor) editor = new classificationEditor();
  editor->show();
}

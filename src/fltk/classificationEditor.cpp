// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <memory>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "classificationEditor.h"
#include "sceneTool.h"
#include "openglWindow.h"
#include "paletteWindow.h"
#include "drawContext.h"
#include "Options.h"
#include "Context.h"
#include "GmshMessage.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "discreteEdge.h"
#include "GModelParametrize.h"

#if defined(HAVE_MESH)
#include "meshGFaceDelaunay.h"
#endif

// without update only the buttons change, as when the editor is built at
// start-up
static void NoElementsSelectedMode(classificationEditor *e, bool update = true)
{
  e->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->activate();
  e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]->activate();

  e->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->deactivate();
  e->buttons[CLASS_BUTTON_RESET_SELECTION]->deactivate();
  e->toggles[CLASS_TOGGLE_BOUNDARY]->deactivate();
  e->inputs[CLASS_VALUE_ANGLE]->deactivate();
  e->buttons[CLASS_BUTTON_CLASSIFY]->deactivate();
  if(!update) return;

  CTX::instance()->meshChanged();
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

bool classificationEditor::forgetIfChanged()
{
  if(!stamps.changed()) return false;
  if(!selected && elements.empty() && edges_detected.empty() &&
     edges_lonly.empty()) { // nothing to forget
    stamps.record();
    return false;
  }
  // the curve, still in its model (compared by address, as it may have been
  // deleted with its model or its entities), goes, its lines on nodes that
  // may be gone
  if(selected) {
    for(GModel *m : GModel::list) {
      if(m->getSerial() == selectedSerial &&
         m->getEdgeByTag(selectedTag) == selected) {
        m->remove(selected);
        delete selected;
        break;
      }
    }
  }
  selected = nullptr;
  elements.clear();
  edges_detected.clear();
  edges_lonly.clear();
  Msg::Info("The model changed: the selection of the classification is reset");
  NoElementsSelectedMode(this);
  stamps.record();
  return true;
}

void classificationEditor::createSelected()
{
  if(selected) return;
  selectedModel = GModel::current();
  selectedSerial = selectedModel->getSerial();
  selectedTag = selectedModel->getMaxElementaryNumber(1) + 1;
  selected = new discreteEdge(selectedModel, selectedTag, nullptr, nullptr);
  selectedModel->add(selected);
}

static void update_edges_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  // the selection is in the model: not during another operation on it
  if(modelBusy()) return;

  if(e->forgetIfChanged() || !e->selected) return;

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

  CTX::instance()->meshChanged();
  e->stamps.record();
  drawContext::global()->draw();
}

static void reset_selection_cb(Fl_Widget *w, void *data);

// the edges of all the elements selected so far, made again
static void elementsSelected(classificationEditor *e)
{
#if defined(HAVE_MESH)
  e->edges_detected.clear();
  e->edges_lonly.clear();
  e2t_cont adj;
  buildEdgeToElements(e->elements, adj);
  buildListOfEdgeAngle(adj, e->edges_detected, e->edges_lonly);
#else
  Msg::Error("Classification requires mesh module");
#endif

  ElementsSelectedMode(e);
  e->stamps.record();
  update_edges_cb(nullptr, e);
  Msg::StatusGl("");
}

static void select_elements_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  // the selection is in the model: not during another operation on it
  if(modelBusy()) return;
  bool all = (w == e->buttons[CLASS_BUTTON_SELECT_ALL_ELEMENTS]);
  e->forgetIfChanged();

  // allocate discrete edge to hold the selected mesh segments
  e->createSelected();
  e->stamps.record();

  if(all) {
    // (all of them, instead of those picked before)
    for(MElement *me : e->elements)
      if(me->getVisibility() == 2) me->setVisibility(1);
    e->elements.clear();
    for(auto it = GModel::current()->firstFace();
        it != GModel::current()->lastFace(); ++it) {
      e->elements.insert(e->elements.end(), (*it)->triangles.begin(),
                         (*it)->triangles.end());
      e->elements.insert(e->elements.end(), (*it)->quadrangles.begin(),
                         (*it)->quadrangles.end());
    }
    elementsSelected(e);
    return;
  }

  // the elements picked until 'e', as a tool of the current window (see
  // sceneTool); anything but 'e' undoes them
  auto ended = std::make_shared<bool>(false);
  drawContext::global()->draw();
  sceneTool::start(
    new functionTool(
      "Classify elements", ENT_ALL, true,
      [](sceneView *) {
        return std::string(
          "Select elements\n[Press 'e' to end selection or Escape to abort]");
      },
      [e, ended](char ib, sceneView *, const scenePicks &p) {
        // the model changed meanwhile: what was picked is gone
        if(e->forgetIfChanged()) {
          *ended = true;
          return false;
        }
        if(ib == 'l') {
          for(MElement *me : p.elements) {
            if(me->getDim() == 2 && me->getVisibility() != 2) {
              me->setVisibility(2);
              e->elements.push_back(me);
            }
          }
        }
        if(ib == 'r') {
          for(MElement *me : p.elements) {
            auto it = std::find(e->elements.begin(), e->elements.end(), me);
            if(me->getVisibility() == 2 && it != e->elements.end())
              e->elements.erase(it);
            me->setVisibility(1);
          }
        }
        if(ib == 'e') { // ok, compute the edges
          GModel::current()->setSelection(0);
          *ended = true;
          elementsSelected(e);
          return false;
        }
        return ib != 'q';
      },
      [e, ended]() {
        // the selection undone, back to no elements selected
        if(*ended || !FlGui::available()) return;
        GModel::current()->setSelection(0);
        for(MElement *me : e->elements) me->setVisibility(1);
        reset_selection_cb(nullptr, e);
      }),
    FlGui::instance()->getCurrentOpenglWindow(), (Fl_Window *)e->win);
}

static void hide_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  Fl_Button *b = e->toggles[CLASS_TOGGLE_HIDE];
  // the selection is in the model: not during another operation on it (the
  // box then back as it was)
  if(modelBusy()) {
    b->value(CTX::instance()->hideUnselected ? 1 : 0);
    return;
  }
  e->forgetIfChanged();
  CTX::instance()->hideUnselected = b->value() ? 1 : 0;
  CTX::instance()->meshChanged();
  e->stamps.record();
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

// the segments picked deleted from the selected curve
static void deleteEdges(classificationEditor *e, std::vector<MLine *> &ele)
{
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

  CTX::instance()->meshChanged();
  e->stamps.record();
  drawContext::global()->draw();
  Msg::StatusGl("");

  e->elements.clear();
  e->edges_detected.clear();
  e->edges_lonly.clear();
}

static void delete_edge_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  // the selection is in the model: not during another operation on it
  if(modelBusy()) return;

  if(e->forgetIfChanged() || !e->selected) return;

  // the segments picked until 'e' ('q' keeps them all), as a tool of the
  // current window (see sceneTool)
  auto ele = std::make_shared<std::vector<MLine *>>();
  auto gone = std::make_shared<bool>(false),
       ended = std::make_shared<bool>(false);
  drawContext::global()->draw();
  sceneTool::start(
    new functionTool(
      "Delete edges", ENT_ALL, true,
      [](sceneView *) {
        return std::string(
          "Select elements\n[Press 'e' to end selection or Escape to abort]");
      },
      [e, ele, gone, ended](char ib, sceneView *, const scenePicks &p) {
        // a reclassification may also have taken the curve meanwhile
        if(e->forgetIfChanged() || !e->selected) {
          *gone = true;
          return false;
        }
        if(ib == 'l') {
          for(MElement *me : p.elements) {
            if(me->getType() == TYPE_LIN && me->getVisibility() != 2) {
              me->setVisibility(2);
              ele->push_back((MLine *)me);
            }
          }
        }
        if(ib == 'r') {
          for(MElement *me : p.elements) {
            auto it = std::find(ele->begin(), ele->end(), me);
            if(me->getVisibility() == 2 && it != ele->end()) ele->erase(it);
            me->setVisibility(1);
          }
        }
        if(ib == 'e') *ended = true;
        return ib != 'e' && ib != 'q';
      },
      [e, ele, gone, ended]() {
        if(*gone || !FlGui::available()) return;
        GModel::current()->setSelection(0);
        // (none deleted unless ended with 'e')
        if(!*ended) ele->clear();
        deleteEdges(e, *ele);
      }),
    FlGui::instance()->getCurrentOpenglWindow(), (Fl_Window *)e->win);
}

static void reset_selection_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  // the selection is in the model: not during another operation on it
  if(modelBusy()) return;
  if(e->forgetIfChanged() || !e->selected) return;
  for(std::size_t i = 0; i < e->selected->lines.size(); i++)
    delete e->selected->lines[i];
  e->selected->lines.clear();
  e->selected->deleteVertexArrays();
  e->elements.clear();
  e->edges_detected.clear();
  e->edges_lonly.clear();
  NoElementsSelectedMode(e);
  e->stamps.record();
}

static void classify_cb(Fl_Widget *w, void *data)
{
  classificationEditor *e = (classificationEditor *)data;
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  // the selection made on a model that changed since is gone
  if(e->forgetIfChanged()) return;

  e->createSelected();

  // what the editor holds, read before the operations: they process events,
  // during which the GUI, and the editor with it, may be closed
  bool parametrizable =
    e->toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES]->value();
  double threshold = e->inputs[CLASS_VALUE_ANGLE]->value() / 180. * M_PI;
  GEdge *selected = e->selected;
  GModel *m = e->selectedModel;
  e->selected = nullptr;

  computeDiscreteCurvatures(m);
  if(parametrizable)
    computeEdgeCut(m, selected->lines,
                   CTX::instance()->mesh.reparamMaxTriangles);
  computeNonManifoldEdges(m, selected->lines, true);
  classifyFaces(m, threshold);

  // remove selected, but do not delete its elements
  m->remove(selected);
  selected->lines.clear();
  delete selected;

  m->pruneMeshVertexAssociations();

  if(parametrizable) m->createGeometryOfDiscreteEntities();

  if(!FlGui::available()) return;
  e->elements.clear();
  e->edges_detected.clear();
  e->edges_lonly.clear();
  NoElementsSelectedMode(e);
  e->stamps.record();
  // the entities changed: the visibility list held the old ones
  FlGui::instance()->resetVisibility();
}

classificationEditor::classificationEditor(int deltaFontSize)
  : selected(nullptr), selectedModel(nullptr), selectedSerial(0),
    selectedTag(0)
{
  FL_NORMAL_SIZE -= deltaFontSize;
  int BBB = (int)(1.4 * BB);
  const int width = TW, height = (int)(10.5 * BH);

  win = new paletteWindow(
    width, height, CTX::instance()->nonModalWindows ? true : false,
    "Reclassify surfaces", CTX::instance()->reclassifyOffset);
  win->box(GMSH_WINDOW_BOX);

  int x = WB, y = WB;
  {
    Fl_Box *b =
      new Fl_Box(x, y, width - 2 * WB, BH,
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
    Fl_Box *b =
      new Fl_Box(x, y, width - 2 * WB, BH, "2. Fine-tune edge selection");
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
    inputs[CLASS_VALUE_ANGLE]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    inputs[CLASS_VALUE_ANGLE]->callback(update_edges_cb, this);

    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES] = new Fl_Check_Button(
      (int)(x + 1.5 * BBB + WB), y, (int)(width - x - 1.5 * BBB - 2 * WB), BH,
      "Show only edges");
    toggles[CLASS_TOGGLE_SHOW_ONLY_EDGES]->callback(show_only_edges_cb, this);

    y += BH;
    toggles[CLASS_TOGGLE_BOUNDARY] = new Fl_Check_Button(
      x, y, width - x - 2 * WB, BH, "Include edges on boundary (closure)");
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
    Fl_Box *b = new Fl_Box(x, y, width - 2 * WB, BH,
                           "3. Reclassify surfaces using selected edges");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    x += WB;

    y += BH;
    toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES] = new Fl_Check_Button(
      x, y, width - x - 2 * WB, BH, "Create parametrized discrete model");
    toggles[CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES]->type(
      FL_TOGGLE_BUTTON);

    y += BH;
    // on the right, as the action buttons of the other tools
    buttons[CLASS_BUTTON_CLASSIFY] =
      new Fl_Return_Button(width - 2 * WB - BBB, y, BBB, BH, "Reclassify");
    buttons[CLASS_BUTTON_CLASSIFY]->callback(classify_cb, this);
    buttons[CLASS_BUTTON_CLASSIFY]->activate();

    x -= WB;
  }

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);

  NoElementsSelectedMode(this, false);
  FL_NORMAL_SIZE += deltaFontSize;
}

void classificationEditor::show()
{
  // not during another operation on the model, which the selection is in
  if(!CTX::instance()->lock) forgetIfChanged();
  // the edges are what is selected
  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
  // (the box as the flag is, whatever changed it meanwhile)
  toggles[CLASS_TOGGLE_HIDE]->value(CTX::instance()->hideUnselected ? 1 : 0);
  drawContext::global()->draw();
  win->show();
}

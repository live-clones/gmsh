// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Escape, 'e', 'u' and 'q' and the mouse selection (Shift+Escape) in every
// selection workflow of the FLTK graphical user interface: the query and the
// measurement, the operations on picked entities, a point placed with the
// mouse, the rotation centre, the visibility window, the reclassification
// editor, and the API waiting for a selection; with synthetic clicks and keys
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include "gmsh.h"
#include "FlGui.h"
#include "openglWindow.h"
#include "classificationEditor.h"
#include "graphicWindow.h"
#include "fltkActions.h"
#include "optionWindow.h"
#include "visibilityWindow.h"
#include "contextWindow.h"
#include "sceneTool.h"
#include "Actions.h"
#include "Options.h"
#include "Context.h"
#include "GModel.h"
#include "GFace.h"
#include "MElement.h"


// no display: the test is skipped (ctest reads 77 as skipped)
static bool noDisplay()
{
#if defined(__linux__)
  return !getenv("DISPLAY") && !getenv("WAYLAND_DISPLAY");
#else
  return false;
#endif
}

static openglWindow *gl() { return FlGui::instance()->getCurrentOpenglWindow(); }
static void settle(double t = 0.2) { double s = 0; while(s < t) { Fl::wait(0.02); s += 0.02; } }
static void click(double fx = 0.5, double fy = 0.5)
{
  openglWindow *g = gl();
  g->redraw(); Fl::flush();
  Fl::e_x = (int)(fx * g->w()); Fl::e_y = (int)(fy * g->h());
  Fl::e_x_root = g->x_root() + Fl::e_x; Fl::e_y_root = g->y_root() + Fl::e_y;
  Fl::e_state = 0; ((Fl_Widget *)g)->handle(FL_MOVE);
  Fl::e_keysym = FL_Button + 1; Fl::e_state = FL_BUTTON1; Fl::e_is_click = 1; Fl::e_clicks = 0;
  ((Fl_Widget *)g)->handle(FL_PUSH);
  Fl::e_state = 0; ((Fl_Widget *)g)->handle(FL_RELEASE);
  Fl::awake();
}
static void key(const char *k) { FlGui::instance()->runShortcut(k); Fl::awake(); }
static const char *E = "escape", *SE = "mouse_selection", *U = "selection_undo", *END = "selection_end", *Q = "selection_quit";
static int fails = 0;
static void check(bool ok, const std::string &what) { printf("%s %s\n", ok ? "ok  " : "FAIL", what.c_str()); if(!ok) fails++; }
static std::string script()
{ std::ifstream in("gui_keys.geo"); std::stringstream s; s << in.rdbuf(); return s.str(); }
static int pickedFaces()
{
  int n = 0;
  for(auto it = GModel::current()->firstFace(); it != GModel::current()->lastFace(); ++it)
    // (picked, not under the hover, which marks the face below the pointer)
    if((*it)->getSelection() && (*it)->getSelection() != GEntity::SelectHover) n++;
  return n;
}
static bool running() { return sceneTool::current() != nullptr; }
// Shift+Escape: picking off, the tool goes on, a click picks nothing
// (changed() says whether it did), Shift+Escape again: picking on
static void escapeCheck(const std::string &w, std::function<bool()> changed)
{
  key(SE);
  check(running() && !CTX::instance()->mouseSelection, w + ": Shift+Escape switches picking off, still running");
  click();
  check(!changed(), w + ":   a click then picks nothing");
  key(SE);
  check(running() && CTX::instance()->mouseSelection == 1, w + ":   Shift+Escape again switches it on");
}
static Fl_Button *findButton(Fl_Group *g, const char *label)
{
  for(int i = 0; i < g->children(); i++) {
    Fl_Widget *c = g->child(i);
    if(c->label() && !strcmp(c->label(), label)) return (Fl_Button *)c;
    if(Fl_Group *cg = c->as_group())
      if(Fl_Button *b = findButton(cg, label)) return b;
  }
  return nullptr;
}
// Escape pressed with the focus in a window, as FLTK sends it
static void escapeIn(Fl_Window *w)
{
  Fl_Widget *f = w->children() ? w->child(0) : (Fl_Widget *)w;
  Fl::focus(f);
  Fl::e_keysym = FL_Escape; Fl::e_state = 0; Fl::e_text = (char *)"\x1b"; Fl::e_length = 1;
  w->handle(FL_SHORTCUT);
}
static std::function<void()> later;
static void runLater(void *) { if(later) later(); }

int main(int argc, char **argv)
{
  if(noDisplay()) return 77;
  setvbuf(stdout, nullptr, _IONBF, 0);
  { std::ofstream f("gui_keys.geo"); f << "SetFactory(\"OpenCASCADE\");\nBox(1) = {-.5, -.5, -.5, 1, 1, 1};\n"; }
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Terminal", 0);
  gmsh::option::setNumber("Geometry.Surfaces", 1);
  gmsh::option::setNumber("Mesh.SurfaceFaces", 1);
  gmsh::open("gui_keys.geo");
  gmsh::model::mesh::generate(2);
  gmsh::fltk::initialize();
  settle(1.0);
  int pinned;

  // --- query
  toggleTool("Query");
  click(); pinned = gl()->numPinned();
  check(pinned > 0, "query: a click pins a note");
  escapeCheck("query", [&] { return gl()->numPinned() != pinned; });
  key(U); check(sceneTool::running("Query") && gl()->numPinned() == pinned, "query: 'u' does nothing, still running");
  key(END); check(sceneTool::running("Query"), "query: 'e' does nothing, still running");
  key(E); check(!running() && gl()->numPinned() == 0, "query: Escape ends it, notes cleared");

  // --- measure
  toggleTool("Measure");
  click(0.45, 0.5);
  check(gl()->measuring(), "measure: first point");
  escapeCheck("measure", [&] { return !gl()->measuring(); });
  key(U); key(END); check(sceneTool::running("Measure") && gl()->measuring(), "measure: 'u' and 'e' do nothing");
  click(0.55, 0.5); check(!gl()->measuring(), "measure: second point");
  key(Q); check(!running(), "measure: 'q' ends it");

  // --- an operation on the script: Delete
  std::string before = script();
  runItem(actionItem{"Delete", ItemOperation, "delete", {}, ""});
  check(sceneTool::running("delete"), "Delete: started");
  click(); check(pickedFaces() == 1, "Delete: a click picks a surface");
  key(U); check(pickedFaces() == 0 && running(), "Delete: 'u' takes it back, still running");
  escapeCheck("Delete", [&] { return pickedFaces() != 0; });
  click(); key(Q);
  printf("       (running %d picked %d script same %d)\n", (int)running(), pickedFaces(), (int)(script() == before));
  check(!running() && pickedFaces() == 0 && script() == before, "Delete: 'q' ends it, nothing written");
  runItem(actionItem{"Delete", ItemOperation, "delete", {}, ""});
  click(); key(END);
  check(script() != before && script().find("Delete") != std::string::npos, "Delete: 'e' writes the command");
  check(sceneTool::running("delete"), "Delete: and goes on for the next one");
  key(E); check(!running(), "Delete: Escape ends it");
  gmsh::open("gui_keys.geo"); gmsh::model::mesh::generate(2); settle();

  // --- a physical group
  before = script();
  runItem(actionItem{"Surface", ItemOperation, "physical_add_surface", {}, ""});
  check(running(), "Physical Surface: started");
  escapeCheck("Physical Surface", [&] { return pickedFaces() != 0; });
  click(); key(U); check(pickedFaces() == 0 && running(), "Physical Surface: 'u' takes the pick back");
  click(); key(END);
  check(script().find("Physical Surface") != std::string::npos, "Physical Surface: 'e' writes the group");
  if(running()) key(Q);
  check(!running(), "Physical Surface: 'q' ends it");
  gmsh::model::mesh::generate(2); settle();

  // --- mesh parts
  std::vector<int> et; std::vector<std::vector<std::size_t> > etags, en;
  auto numTriangles = [&] {
    gmsh::model::mesh::getElements(et, etags, en, 2);
    std::size_t n = 0; for(auto &t : etags) n += t.size(); return n;
  };
  std::size_t n0 = numTriangles();
  runItem(actionItem{"Surfaces", ItemOperation, "mesh_delete_surfaces", {}, ""});
  click(); key(U); check(pickedFaces() == 0 && running(), "Delete mesh surfaces: 'u' takes the pick back");
  escapeCheck("Delete mesh surfaces", [&] { return pickedFaces() != 0; });
  click(); key(Q); check(!running() && numTriangles() == n0, "Delete mesh surfaces: 'q' ends it, nothing deleted");
  runItem(actionItem{"Surfaces", ItemOperation, "mesh_delete_surfaces", {}, ""});
  click(); key(END); check(numTriangles() < n0, "Delete mesh surfaces: 'e' deletes the mesh picked");
  key(E); check(!running(), "Delete mesh surfaces: Escape ends it");
  gmsh::model::mesh::generate(2); settle();

  // --- a point placed with the mouse
  before = script();
  runItem(actionItem{"Point", ItemShape, "add_point", {}, ""});
  check(running() && gl()->addPointMode == 1, "add point: started");
  key(SE); check(running() && !CTX::instance()->mouseSelection, "add point: Shift+Escape switches picking off, still running");
  key(SE);
  key(U); check(running() && gl()->addPointMode == 1 && script() == before, "add point: 'u' does nothing");
  key(END); check(running() && script().find("Point(") != std::string::npos, "add point: 'e' adds a point, goes on");
  key(E); check(!running() && gl()->addPointMode == 0, "add point: Escape ends it");
  gmsh::open("gui_keys.geo"); gmsh::model::mesh::generate(2); settle();

  // --- the rotation center
  CTX::instance()->rotationCenterCg = 0;
  double x0 = CTX::instance()->rotationCenter[0];
  general_options_rotation_center_select_cb(nullptr, nullptr);
  escapeCheck("rotation center", [&] { return CTX::instance()->rotationCenter[0] != x0; });
  key(U); check(running(), "rotation center: 'u' does nothing");
  key(END); check(!running() && CTX::instance()->rotationCenter[0] == x0, "rotation center: 'e' ends it, nothing set");
  general_options_rotation_center_select_cb(nullptr, nullptr);
  key(E); check(!running(), "rotation center: Escape ends it");
  general_options_rotation_center_select_cb(nullptr, nullptr);
  click(0.6, 0.5); check(!running() && CTX::instance()->rotationCenter[0] != x0, "rotation center: a click sets it and ends");

  // --- visibility: hide surfaces
  FlGui::instance()->visibility->show(false);
  settle();
  Fl_Button *hide = findButton(FlGui::instance()->visibility->win, "Hide surfaces");
  check(hide != nullptr, "visibility: 'Hide surfaces' button found");
  auto hidden = [] {
    int n = 0;
    for(auto it = GModel::current()->firstFace(); it != GModel::current()->lastFace(); ++it)
      if(!(*it)->getVisibility()) n++;
    return n;
  };
  if(hide) {
    hide->do_callback();
    check(running(), "visibility: started");
    click(); check(hidden() == 1, "visibility: a click hides a surface");
    key(U); check(hidden() == 0 && running(), "visibility: 'u' shows it again");
    escapeCheck("visibility", [&] { return hidden() != 0; });
    key(END); check(running(), "visibility: 'e' does nothing");
    key(E); check(!running(), "visibility: Escape ends it");
  }
  FlGui::instance()->visibility->win->hide();

  // --- classification: select elements, then delete edges
  FlGui::instance()->classify->show();
  settle();
  classificationEditor *ce = FlGui::instance()->classify;
  ce->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->do_callback();
  check(running(), "classify: element selection started");
  click(); check(ce->elements.size() >= 1, "classify: a click picks an element");
  std::size_t ne = ce->elements.size();
  key(U); check(running() && ce->elements.size() == ne, "classify: 'u' does nothing");
  escapeCheck("classify", [&] { return ce->elements.size() != ne; });
  key(Q); check(!running() && ce->elements.empty(), "classify: 'q' ends it, picks undone");
  ce->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->do_callback();
  click(); click(0.45, 0.5);
  key(END); check(!running() && !ce->elements.empty() && ce->selected, "classify: 'e' ends it, edges computed");
  printf("       (%zu elements, %zu selected lines)\n", ce->elements.size(), ce->selected ? ce->selected->lines.size() : 0);
  std::size_t lines = ce->selected ? ce->selected->lines.size() : 0;
  ce->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->do_callback();
  check(running(), "classify delete edges: started");
  escapeCheck("classify delete edges", [] { return false; });
  key(U); check(running(), "classify delete edges: 'u' does nothing");
  key(E); check(!running() && ce->selected && ce->selected->lines.size() == lines, "classify delete edges: Escape ends it, nothing deleted");
  ce->buttons[CLASS_BUTTON_DELETE_FROM_SELECTION]->do_callback();
  key(END); check(!running(), "classify delete edges: 'e' ends it");
  ce->win->hide();

  // --- Escape in the window of the selection, and its closing
  runItem(actionItem{"Delete", ItemOperation, "delete", {}, ""});
  Fl_Window *tw = FlGui::instance()->transformContext->win;
  check(running() && tw->shown(), "Delete: its context window is shown");
  escapeIn(tw);
  check(!running() && !tw->visible(), "Delete: Escape in its window stops it, the window goes");
  runItem(actionItem{"Delete", ItemOperation, "delete", {}, ""});
  tw->hide();
  check(!running(), "Delete: closing its window ends it");
  FlGui::instance()->visibility->show(false); settle();
  Fl_Window *vw = FlGui::instance()->visibility->win;
  Fl_Button *hide2 = findButton(vw, "Hide surfaces");
  if(hide2) {
    hide2->do_callback();
    escapeIn(vw);
    check(!running() && vw->visible(), "visibility: Escape in the window stops the pick, the window stays");
    escapeIn(vw);
    check(!vw->visible(), "visibility:   a second Escape closes the window");
    FlGui::instance()->visibility->show(false); settle();
    hide2->do_callback();
    vw->hide();
    check(!running(), "visibility: closing the window ends the pick");
  }
  FlGui::instance()->classify->show(); settle();
  ce->buttons[CLASS_BUTTON_SELECT_ELEMENTS]->do_callback();
  check(running(), "classify: element selection started again");
  ce->win->hide();
  check(!running(), "classify: closing the editor ends the selection");
  toggleTool("Query");
  FlGui::instance()->visibility->show(false); settle();
  escapeIn(vw);
  check(sceneTool::running("Query") && !vw->visible(), "Escape in another window closes it, the query goes on");
  key(E);
  check(!running(), "  and Escape in the scene stops the query");

  // --- the API
  std::vector<std::pair<int, int> > dt;
  later = [] { key(SE); key(SE); key(U); };
  Fl::add_timeout(0.3, runLater);
  int r = gmsh::fltk::selectEntities(dt, 2);
  check(r == 3 && CTX::instance()->mouseSelection == 1, "API: Shift+Escape twice goes on, 'u' returns 3");
  later = [] { key(E); };
  Fl::add_timeout(0.3, runLater);
  r = gmsh::fltk::selectEntities(dt, 2);
  check(r == 0, "API: Escape returns 0, as 'q'");
  later = [] { key(END); };
  Fl::add_timeout(0.3, runLater);
  r = gmsh::fltk::selectEntities(dt, 2);
  check(r == 4, "API: 'e' returns 4");
  later = [] { key(Q); };
  Fl::add_timeout(0.3, runLater);
  r = gmsh::fltk::selectEntities(dt, 2);
  check(r == 0, "API: 'q' returns 0");
  later = [] { key(SE); click(); key(SE); click(); };
  Fl::add_timeout(0.3, runLater);
  r = gmsh::fltk::selectEntities(dt, 2);
  check(r == 1 && dt.size() == 1, "API: with picking off a click is ignored, then picks once on");

  int ms = CTX::instance()->mouseSelection;
  key(E);
  check(!running() && CTX::instance()->mouseSelection == ms, "Escape with nothing under way changes nothing");
  gmsh::fltk::finalize();
  gmsh::finalize();
  printf("%d failure(s)\n", fails);
  return fails;
}

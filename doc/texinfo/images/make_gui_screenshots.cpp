// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The screenshots of the GUI for the reference manual (gui.png,
// gui_add_rectangle.png, gui_mesh.png, gui_tools.png), taken on a retina
// screen in light mode with the in-window menu bar.
//
// Build Gmsh as a shared library with its private API (cmake
// -DENABLE_BUILD_SHARED=1 -DENABLE_PRIVATE_API=1), then
//
//   clang++ -std=c++17 -I../../../api -I../../../src/fltk -I../../../src/common
//     -I../../../src/geo -I../../../src/post -I../../../src/graphics
//     -I../../../src/numeric -I../../../src/mesh -I../../../src/parser
//     -I../../../src/plugin -I<build dir>/src/common $(fltk-config --cxxflags
//     --use-images --use-gl) make_gui_screenshots.cpp -o make_gui_screenshots
//     -L<build dir> -lgmsh $(fltk-config --ldflags --use-images --use-gl)
//
// and run `SCENE=<scene> ./make_gui_screenshots <dir>' for each of the scenes
// gui, rectangle, mesh and tools: each writes the windows it shows into <dir>
// with their offsets in a text file, which make_gui_screenshots.py composes
// into the final pictures.
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <typeinfo>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tree.H>
#include <FL/fl_draw.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Image_Surface.H>
#include <FL/fl_ask.H>
#include "gmsh.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "onelabGroup.h"
#include "optionWindow.h"
#include "visibilityWindow.h"
#include "Context.h"

static Fl_Window *m = nullptr, *mwFirst = nullptr;
static std::string outdir, scene;
static void pump(int n = 10) { for(int k = 0; k < n; k++) Fl::wait(0.02); }
static void pumpFor(double sec) { auto t0 = std::chrono::steady_clock::now(); while(std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count() < sec) Fl::wait(0.05); }

// every window shown, the main one first, written with its offset from the main one
static void captureAll(const std::string &name)
{
  std::string base = outdir + "/" + name;
  FILE *f = fopen((base + ".txt").c_str(), "w");
  int k = 0;
  std::vector<Fl_Window *> ws = {m};
  for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w)) if(w != m && w->shown() && w->visible()) ws.push_back(w);
  for(Fl_Window *w : ws) {
    Fl_RGB_Image *img = fl_capture_window(w, 0, 0, w->w(), w->h());
    std::string file = base + "-" + std::to_string(k) + ".png";
    if(img) { fl_write_png(file.c_str(), img); delete img; }
    fprintf(f, "%s %d %d %d %d %s\n", file.c_str(), w->x() - m->x(), w->y() - m->y(), w->w(), w->h(), typeid(*w).name());
    k++;
  }
  fclose(f);
}

static Fl_Widget *findLabel(Fl_Group *root, const char *lab)
{
  std::vector<Fl_Group *> st = {root};
  while(!st.empty()) { Fl_Group *grp = st.back(); st.pop_back();
    for(int i = 0; i < grp->children(); i++) { Fl_Widget *c = grp->child(i);
      if(c->label() && std::string(c->label()) == lab && c->visible_r()) return c;
      if(Fl_Group *gg = dynamic_cast<Fl_Group *>(c)) st.push_back(gg); } }
  return nullptr;
}
static Fl_Widget *findTooltip(Fl_Group *root, const char *tip)
{
  std::vector<Fl_Group *> st = {root};
  while(!st.empty()) { Fl_Group *grp = st.back(); st.pop_back();
    for(int i = 0; i < grp->children(); i++) { Fl_Widget *c = grp->child(i);
      if(c->tooltip() && std::string(c->tooltip()).find(tip) != std::string::npos && c->visible_r()) return c;
      if(Fl_Group *gg = dynamic_cast<Fl_Group *>(c)) st.push_back(gg); } }
  return nullptr;
}
// the pointer moved to a point of a widget, through the main window
static void moveTo(Fl_Widget *w, int dx, int dy)
{
  int ox = 0, oy = 0; for(Fl_Widget *p = w; p && p != m; p = p->parent()) if(dynamic_cast<Fl_Window *>(p)) { ox += p->x(); oy += p->y(); }
  Fl::e_x = ox + w->x() + dx; Fl::e_y = oy + w->y() + dy; Fl::e_x_root = m->x() + Fl::e_x; Fl::e_y_root = m->y() + Fl::e_y; Fl::e_state = 0;
  Fl::handle(FL_ENTER, m); Fl::handle(FL_MOVE, m);
}
static void key(int sym, int n = 1) { for(int i = 0; i < n; i++) { Fl::e_keysym = sym; Fl::e_text = (char *)""; Fl::e_length = 0; Fl::handle(FL_KEYBOARD, Fl::first_window()); pump(2); } }

int main(int argc, char **argv)
{
  outdir = argc > 1 ? argv[1] : "."; scene = getenv("SCENE") ? getenv("SCENE") : "gui";
  gmsh::initialize(0, nullptr, false);
  gmsh::option::setNumber("General.FltkColorScheme", 0);
  gmsh::option::setNumber("General.SystemMenuBar", 0);
  gmsh::option::setNumber("General.GraphicsWidth", 940);
  gmsh::option::setNumber("General.GraphicsHeight", 512);
  gmsh::option::setNumber("General.MenuWidth", 215);
  gmsh::option::setNumber("General.MessageHeight", 130);
  std::string geo = outdir + "/mymodel.geo";
  if(scene == "rectangle") { FILE *f = fopen(geo.c_str(), "w"); fclose(f); gmsh::open(geo); }
  if(scene == "mesh" || scene == "tools") {
    FILE *f = fopen(geo.c_str(), "w"); fprintf(f, "//+\nSetFactory(\"OpenCASCADE\");\nRectangle(1) = {0, 0, 0, 1, 0.5, 0};\n"); fclose(f);
    gmsh::open(geo); gmsh::model::mesh::generate(2);
    if(scene == "mesh") gmsh::option::setNumber("Mesh.SurfaceFaces", 1);
  }
  gmsh::fltk::initialize();
  FlGui *g = FlGui::instance();
  m = g->graph[0]->getWindow();
  pump(20);
  if(scene == "gui") { captureAll("gui"); }
  else if(scene == "rectangle") {
    for(const char *n : {"0Modules/Geometry", "0Modules/Geometry/Elementary entities", "0Modules/Geometry/Elementary entities/Add"}) g->onelab->openTreeItem(n);
    pump(10);
    Fl_Widget *r = findLabel(m, "Rectangle"); printf("Rectangle button: %d\n", r != nullptr);
    if(!r) return 1;
    Fl::add_timeout(1.5, [](void *) { // inside the add loop: the pointer on the picture, then the capture
      openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
      // the event goes straight to the subwindow: coordinates relative to it
      Fl::e_x = gl->w() * 0.40; Fl::e_y = gl->h() * 0.62; Fl::e_x_root = m->x() + gl->x() + Fl::e_x; Fl::e_y_root = m->y() + gl->y() + Fl::e_y; Fl::e_state = 0;
      Fl_Widget *glw = gl; glw->handle(FL_ENTER); glw->handle(FL_MOVE); pump(10);
      captureAll("gui_add_rectangle"); gmsh::finalize(); exit(0); });
    r->do_callback(); // runs the add loop until a key
  }
  else if(scene == "mesh") {
    g->onelab->openTreeItem("0Modules/Mesh"); pump(10);
    // a double click in the picture pops the quick access menu there; the steps run from timers,
    // each returning so that the loop of the menu can open the submenu and redraw between them
    Fl::add_timeout(0.8, [](void *) {
      Fl_Window *mw = Fl::first_window(); mwFirst = mw; printf("menu window %s %dx%d\n", typeid(*mw).name(), mw->w(), mw->h());
      double ry = getenv("ROW_Y") ? atof(getenv("ROW_Y")) : 0.733;
      Fl::e_x = mw->w() / 2; Fl::e_y = (int)(mw->h() * ry); Fl::e_x_root = mw->x() + Fl::e_x; Fl::e_y_root = mw->y() + Fl::e_y; Fl::e_state = 0;
      Fl::handle(FL_MOVE, mw);
      Fl::add_timeout(0.4, [](void *) {
        int n = 0; for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w)) if(std::string(typeid(*w).name()).find("Menu_Window") != std::string::npos) n++;
        printf("menu windows open: %d\n", n);
        // into the submenu, on its fourth row (2D element faces)
        Fl_Window *sub = nullptr; for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w)) if(std::string(typeid(*w).name()).find("Menu_Window") != std::string::npos && w != mwFirst) sub = w;
        if(sub) { Fl::e_x = sub->w() / 2; Fl::e_y = (int)(sub->h() * 3.5 / 6.); Fl::e_x_root = sub->x() + Fl::e_x; Fl::e_y_root = sub->y() + Fl::e_y; Fl::e_state = 0; Fl::handle(FL_MOVE, sub); }
        Fl::add_timeout(0.4, [](void *) { captureAll("gui_mesh"); gmsh::finalize(); exit(0); });
      });
    });
    openglWindow *gl = g->getCurrentOpenglWindow(); Fl_Widget *glw = gl;
    Fl::e_x = gl->w() * 0.22; Fl::e_y = gl->h() * (getenv("CLICK_Y") ? atof(getenv("CLICK_Y")) : 0.67); Fl::e_x_root = m->x() + gl->x() + Fl::e_x; Fl::e_y_root = m->y() + gl->y() + Fl::e_y;
    Fl::e_state = FL_BUTTON1; Fl::e_keysym = FL_Button + 1; Fl::e_clicks = 1;
    glw->handle(FL_PUSH); // runs the menu until it is closed
    pump(10);
  }
  else if(scene == "tools") {
    g->options->showGroup(3); pump(10); // the mesh options, docked
    g->visibility->win->show(); pump(10); // a second tab
    g->options->win->show(); pump(10); // the options in front
    captureAll("gui_tools");
  }
  gmsh::finalize();
  return 0;
}

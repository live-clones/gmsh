// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_SVG_Image.H>
#include <FL/fl_draw.H>
#include "icons.h"

// the strokes, in a 24 by 24 box, two units wide with round ends, the colour
// put in when rendered
static const char *strokes(const std::string &name)
{
  if(name == "sidebar")
    return "<rect x='3' y='4' width='18' height='16' rx='2'/>"
           "<path d='M9 4v16'/>";
  if(name == "models")
    return "<path d='M12 3 2 8l10 5 10-5z'/><path d='m2 12 10 5 10-5'/>"
           "<path d='m2 16 10 5 10-5'/>";
  if(name == "quick")
    return "<path d='M21 4h-7M10 4H3M21 12h-9M8 12H3M21 20h-5M12 20H3'/>"
           "<path d='M14 2v4M8 10v4M16 18v4'/>";
  if(name == "cube")
    return "<path d='M12 3l8 4.5v9L12 21l-8-4.5v-9z'/>"
           "<path d='m4 7.5 8 4.5 8-4.5M12 12v9'/>";
  if(name == "rotate")
    return "<path d='M21 12a9 9 0 1 1-3-6.7'/><path d='M21 3v6h-6'/>";
  if(name == "query")
    return "<circle cx='12' cy='12' r='8'/>"
           "<path d='M22 12h-4M6 12H2M12 6V2M12 22v-4'/>";
  if(name == "measure")
    return "<path d='M3 15 15 3l6 6L9 21z'/>"
           "<path d='m7 11 2 2M10 8l2 2M13 5l2 2'/>";
  if(name == "rewind")
    return "<path d='M19 20 9 12l10-8z'/><path d='M5 19V5'/>";
  if(name == "back") return "<path d='m15 18-6-6 6-6'/>";
  if(name == "play") return "<path d='M6 3l14 9-14 9z'/>";
  if(name == "pause")
    return "<rect x='6' y='4' width='4' height='16' rx='1'/>"
           "<rect x='14' y='4' width='4' height='16' rx='1'/>";
  if(name == "forward") return "<path d='m9 18 6-6-6-6'/>";
  if(name == "gear")
    return "<circle cx='12' cy='12' r='3'/><circle cx='12' cy='12' r='7'/>"
           "<path d='M19 12h3M5 12H2M12 5V2M12 22v-3'/>"
           "<path d='m16.95 16.95 2.12 2.12M7.05 7.05 4.93 4.93'/>"
           "<path d='m16.95 7.05 2.12-2.12M7.05 16.95l-2.12 2.12'/>";
  if(name == "search")
    return "<circle cx='11' cy='11' r='7'/><path d='m21 21-4.3-4.3'/>";
  if(name == "eye")
    return "<path d='M2 12s3.5-7 10-7 10 7 10 7-3.5 7-10 7-10-7-10-7z'/>"
           "<circle cx='12' cy='12' r='3'/>";
  return "";
}

// the images made, one per name, size and colour, and the widgets holding one
namespace {
  struct icon {
    std::string name;
    int size;
    Fl_Widget *widget;
  };
  std::map<std::string, Fl_SVG_Image *> images;
  std::vector<icon *> holders;
} // namespace

static Fl_SVG_Image *image(const std::string &name, int size, bool active)
{
  unsigned char r, g, b;
  // the inactive icons in the colour FLTK greys an inactive label with
  Fl::get_color(active ? FL_FOREGROUND_COLOR : fl_inactive(FL_FOREGROUND_COLOR),
                r, g, b);
  char col[16];
  snprintf(col, sizeof(col), "#%02x%02x%02x", r, g, b);
  std::string key = name + "/" + std::to_string(size) + "/" + col;
  auto it = images.find(key);
  if(it != images.end()) return it->second;
  std::string svg = "<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 24 "
                    "24' fill='none' stroke='" +
                    std::string(col) +
                    "' stroke-width='2' stroke-linecap='round' "
                    "stroke-linejoin='round'>" +
                    strokes(name) + "</svg>";
  Fl_SVG_Image *img = new Fl_SVG_Image(nullptr, svg.c_str());
  img->resize(size, size);
  images[key] = img;
  return img;
}

void gmshIcon(Fl_Widget *w, const char *name, int size)
{
  // the holders of deleted widgets go (FLTK cleared their pointers, which it
  // watches until released)
  for(auto it = holders.begin(); it != holders.end();) {
    if((*it)->widget) {
      ++it;
      continue;
    }
    Fl::release_widget_pointer((*it)->widget);
    delete *it;
    it = holders.erase(it);
  }
  icon *h = nullptr;
  for(icon *i : holders)
    if(i->widget == w) h = i;
  if(!h) {
    h = new icon;
    h->widget = w;
    // the pointer cleared by FLTK if the widget is deleted
    Fl::watch_widget_pointer(h->widget);
    holders.push_back(h);
  }
  h->name = name;
  h->size = size;
  // no label at all: an empty one would still take its line under the image
  w->label(nullptr);
  w->image(image(name, size, true));
  w->deimage(image(name, size, false));
  w->redraw();
}

void gmshIconsRecolor()
{
  for(icon *h : holders) {
    if(!h->widget) continue;
    h->widget->image(image(h->name, h->size, true));
    h->widget->deimage(image(h->name, h->size, false));
    h->widget->redraw();
  }
}

// The icons of the status bar and the tools as FLTK symbols ("@gmsh_play"),
// drawn in a 2 by 2 box: those of the themes other than gmsh
#define vv(x, y) fl_vertex(x, y)
#define bl fl_begin_loop()
#define el fl_end_loop()

static void gmsh_play(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.3, 0.8);
  vv(0.5, 0.0);
  vv(-0.3, -0.8);
  el;
}

static void gmsh_pause(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  el;
  bl;
  vv(0.0, -0.8);
  vv(0.5, -0.8);
  vv(0.5, 0.8);
  vv(0.0, 0.8);
  el;
}

static void gmsh_rewind(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  el;
  bl;
  vv(-0.3, 0.0);
  vv(0.5, -0.8);
  vv(0.5, 0.8);
  el;
}

static void gmsh_forward(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(0.0, 0.8);
  vv(0.8, 0.0);
  vv(0.0, -0.8);
  el;
  bl;
  vv(-0.8, 0.8);
  vv(-0.3, 0.8);
  vv(-0.3, -0.8);
  vv(-0.8, -0.8);
  el;
}

static void gmsh_back(Fl_Color c)
{
  fl_rotate(180);
  gmsh_forward(c);
}

static void gmsh_rotate(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  fl_arc(0.0, -0.1, 0.7, 0.0, 270.0);
  fl_end_line();
  fl_begin_polygon();
  vv(0.5, 0.6);
  vv(-0.1, 0.9);
  vv(-0.1, 0.3);
  fl_end_polygon();
}

// a cube seen along its diagonal: the isometric view
static void gmsh_cube(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(0.0, 0.9);
  vv(0.78, 0.45);
  vv(0.78, -0.45);
  vv(0.0, -0.9);
  vv(-0.78, -0.45);
  vv(-0.78, 0.45);
  el;
  // (y down)
  fl_begin_line();
  vv(-0.78, -0.45);
  vv(0.0, 0.0);
  vv(0.78, -0.45);
  fl_end_line();
  fl_begin_line();
  vv(0.0, 0.0);
  vv(0.0, 0.9);
  fl_end_line();
}

// a small disk (FLTK draws its circle 10 pixels wide at the least): the switch
// of the views of a group in the ONELAB tree
static void gmsh_dot(Fl_Color c)
{
  fl_color(c);
  fl_begin_polygon();
  fl_arc(0.0, 0.0, 0.5, 0.0, 360.0);
  fl_end_polygon();
}

// a crosshair over a target: the point of the model a query asks about
static void gmsh_query(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  fl_arc(0.0, 0.0, 0.45, 0.0, 360.0);
  fl_end_line();
  bl;
  vv(-0.9, 0.0);
  vv(-0.2, 0.0);
  el;
  bl;
  vv(0.2, 0.0);
  vv(0.9, 0.0);
  el;
  bl;
  vv(0.0, -0.9);
  vv(0.0, -0.2);
  el;
  bl;
  vv(0.0, 0.2);
  vv(0.0, 0.9);
  el;
}

// a ruler: the line a measurement draws between the two points it is given
static void gmsh_measure(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.75, 0.55);
  vv(0.75, -0.55);
  el; // the line
  bl;
  vv(-0.90, 0.35);
  vv(-0.60, 0.75);
  el; // its ends
  bl;
  vv(0.60, -0.75);
  vv(0.90, -0.35);
  el;
  bl;
  vv(-0.38, 0.28);
  vv(-0.29, 0.40);
  el; // graduations
  bl;
  vv(0.00, 0.00);
  vv(0.09, 0.12);
  el;
  bl;
  vv(0.38, -0.28);
  vv(0.46, -0.15);
  el;
}

// a window with its side pane filled: the tree, shown or hidden
static void gmsh_sidebar(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.8);
  vv(0.8, -0.8);
  vv(0.8, 0.8);
  vv(-0.8, 0.8);
  el;
  fl_begin_polygon();
  vv(-0.8, -0.8);
  vv(-0.3, -0.8);
  vv(-0.3, 0.8);
  vv(-0.8, 0.8);
  fl_end_polygon();
}

static void gmsh_models(Fl_Color c)
{
  fl_color(c);
  bl;
  vv(-0.8, -0.7);
  vv(0.8, -0.7);
  el;
  bl;
  vv(-0.8, -0.2);
  vv(0.8, -0.2);
  el;
  bl;
  vv(-0.8, 0.3);
  vv(0.8, 0.3);
  el;
  bl;
  vv(-0.8, 0.8);
  vv(0.8, 0.8);
  el;
}

static void gmsh_gear(Fl_Color c)
{
  fl_color(c);
  double w = 0.12;
  double h1 = 0.5;
#if defined(WIN32)
  double h2 = 1.0;
#else
  double h2 = 1.05;
#endif
  fl_line_style(FL_SOLID, 3);
  fl_begin_line();
  fl_circle(0, 0, 0.5);
  fl_end_line();
  fl_line_style(FL_SOLID);
  for(int i = 0; i < 8; i++) {
    fl_rotate(45);
    fl_begin_polygon();
    fl_vertex(h1, -w);
    fl_vertex(h2, -w);
    fl_vertex(h2, w);
    fl_vertex(h1, w);
    fl_end_polygon();
  }
}

static void gmsh_graph(Fl_Color c)
{
  fl_color(c);
  fl_begin_line();
  vv(-0.8, -0.8);
  vv(-0.8, 0.8);
  vv(0.8, 0.8);
  fl_end_line();
  fl_begin_line();
  vv(-0.8, 0.3);
  vv(-0.2, -0.2);
  vv(0.3, 0.1);
  vv(0.8, -0.4);
  fl_end_line();
}

static void gmsh_search(Fl_Color col)
{
  double e = 0.5;
  fl_color(col);
  fl_begin_polygon();
  vv(.6 - e, .33);
  vv(1.2 - e, .93);
  vv(.93 - e, 1.2);
  vv(.33 - e, .6);
  fl_end_polygon();
  fl_line_style(FL_SOLID, 2);
  fl_begin_loop();
  fl_circle(0 - e, 0, .6);
  fl_end_loop();
  fl_line_style(FL_SOLID);
}

#undef vv
#undef bl
#undef el

void gmshAddSymbols()
{
  fl_add_symbol("gmsh_rewind", gmsh_rewind, 1);
  fl_add_symbol("gmsh_back", gmsh_back, 1);
  fl_add_symbol("gmsh_play", gmsh_play, 1);
  fl_add_symbol("gmsh_pause", gmsh_pause, 1);
  fl_add_symbol("gmsh_forward", gmsh_forward, 1);
  fl_add_symbol("gmsh_rotate", gmsh_rotate, 1);
  fl_add_symbol("gmsh_cube", gmsh_cube, 1);
  fl_add_symbol("gmsh_sidebar", gmsh_sidebar, 1);
  fl_add_symbol("gmsh_models", gmsh_models, 1);
  fl_add_symbol("gmsh_query", gmsh_query, 1);
  fl_add_symbol("gmsh_dot", gmsh_dot, 1);
  fl_add_symbol("gmsh_measure", gmsh_measure, 1);
  fl_add_symbol("gmsh_gear", gmsh_gear, 1);
  fl_add_symbol("gmsh_graph", gmsh_graph, 1);
  fl_add_symbol("gmsh_search", gmsh_search, 1);
}

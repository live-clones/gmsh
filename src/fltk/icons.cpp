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

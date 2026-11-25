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
#include "IconStrokes.h"

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

static Fl_SVG_Image *image(const std::string &name, int size, Fl_Color c,
                           bool active)
{
  unsigned char r, g, b;
  // the inactive icons in the colour FLTK greys an inactive label with
  Fl::get_color(active ? c : fl_inactive(c), r, g, b);
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
                    IconStrokes(name) + "</svg>";
  Fl_SVG_Image *img = new Fl_SVG_Image(nullptr, svg.c_str());
  img->resize(size, size);
  images[key] = img;
  return img;
}

static void draw(icon *h)
{
  h->widget->image(image(h->name, h->size, h->widget->labelcolor(), true));
  h->widget->deimage(image(h->name, h->size, h->widget->labelcolor(), false));
  h->widget->redraw();
}

void gmshIcon(Fl_Widget *w, const char *name, int size)
{
  // a null name takes the icon off: its holder goes with those of the deleted
  // widgets (FLTK cleared their pointers, which it watches until released)
  if(!name) {
    for(icon *i : holders)
      if(i->widget == w) i->widget = nullptr;
    w->image(nullptr);
    w->deimage(nullptr);
    w->redraw();
  }
  for(auto it = holders.begin(); it != holders.end();) {
    if((*it)->widget) {
      ++it;
      continue;
    }
    Fl::release_widget_pointer((*it)->widget);
    delete *it;
    it = holders.erase(it);
  }
  if(!name) return;
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
  draw(h);
}

void gmshIconRecolor(Fl_Widget *w)
{
  for(icon *h : holders)
    if(h->widget == w) draw(h);
}

void gmshIconsRecolor()
{
  for(icon *h : holders)
    if(h->widget) draw(h);
}

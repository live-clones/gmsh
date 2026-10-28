// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Menu_.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Valuator.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include "gmshScheme.h"
#include "desktop.h"
#include <string>
#include "FlGui.h" // the box types of Gmsh
#include "Context.h"

// the default theme, which an empty name also selects: the session files of
// older versions store an empty theme, and their users get the new look too
bool gmshScheme()
{
  return CTX::instance()->guiTheme == "gmsh" ||
         CTX::instance()->guiTheme.empty();
}

int gmshAir()
{
  // read once: the layouts are built from it, and the theme is set for the
  // session
  static int air = gmshScheme() ? 1 : 0;
  return air;
}

static Fl_Color _accent = FL_SELECTION_COLOR;

Fl_Color gmshAccent() { return _accent; }

void applyGmshColors(bool dark)
{
  if(dark) {
    // the greys and the blue of the Dark Modern theme of VS Code
    Fl::set_color(FL_BACKGROUND_COLOR, 31, 31, 31);
    Fl::set_color(FL_BACKGROUND2_COLOR, 49, 49, 49);
    Fl::set_color(FL_FOREGROUND_COLOR, 204, 204, 204);
    // the greys of the bevels and frames, from black to a dark grey: the
    // ramp FLTK derives from a background runs up to white, far too bright
    for(int i = 0; i < FL_NUM_GRAY; i++) {
      int d = (int)(i * 80. / (FL_NUM_GRAY - 1.));
      Fl::set_color(fl_gray_ramp(i), d, d, d);
    }
    // the selected rows and text muted, the blue of the editor selection,
    // the bright blue kept for the accents the theme draws itself
    Fl::set_color(FL_SELECTION_COLOR, 38, 79, 120);
    _accent = fl_rgb_color(0, 120, 212);
    // the tooltips on the hover widget colour of the theme, not the pale
    // yellow of FLTK
    Fl_Tooltip::color(fl_rgb_color(37, 37, 38));
    Fl_Tooltip::textcolor(FL_FOREGROUND_COLOR);
  }
  else {
    // the greys and the blue of the Light Modern theme of VS Code
    Fl::background(248, 248, 248);
    Fl::background2(255, 255, 255);
    Fl::foreground(59, 59, 59);
    // the ramp FLTK fits to such a light background fades the frames out
    // (FL_DARK3 at 228): a ramp from black to the frame grey of VS Code (206)
    // at FL_DARK3, then up to the background and white
    for(int i = 0; i < FL_NUM_GRAY; i++) {
      int d = (i <= 7) ? 206 * i / 7 : std::min(255, 206 + (i - 7) * 42 / 10);
      Fl::set_color(fl_gray_ramp(i), d, d, d);
    }
    Fl::set_color(FL_SELECTION_COLOR, 173, 214, 255);
    _accent = fl_rgb_color(0, 95, 184);
    Fl_Tooltip::color(fl_rgb_color(243, 243, 243));
    Fl_Tooltip::textcolor(FL_FOREGROUND_COLOR);
  }
}

// The widget under the pointer, when it takes input (a button, a check box,
// a menu button, a field, a slider, a tab): its boxes are drawn a little
// toward the foreground, as the desktop does. A box is known by its place
// alone, as it draws without its widget: it is the widget's, or lies inside
// it (the square of a check box, the arrow of a choice).
static bool hoverable(Fl_Widget *w)
{
  if(!w || !w->active_r()) return false;
  // not the menu bar, which draws no box per title and highlights its own
  // (see hoverMenuBar), nor a scrollbar, which is not a control one presses
  if(dynamic_cast<Fl_Menu_Bar *>(w) || dynamic_cast<Fl_Scrollbar *>(w))
    return false;
  return dynamic_cast<Fl_Button *>(w) || dynamic_cast<Fl_Menu_ *>(w) ||
         dynamic_cast<Fl_Input_ *>(w) || dynamic_cast<Fl_Valuator *>(w) ||
         dynamic_cast<Fl_Tabs *>(w);
}

static Fl_Color highlight(Fl_Color c)
{ return fl_color_average(c, FL_FOREGROUND_COLOR, 0.94f); }

Fl_Color hoverHighlight(Fl_Widget *w, Fl_Color c)
{
  if(!gmshScheme() || Fl::belowmouse() != w || !w->active_r()) return c;
  return highlight(c);
}

Fl_Color hoverHighlight(Fl_Color c) { return gmshScheme() ? highlight(c) : c; }

// the pointer, known relative to the top window, brought into a window
static void pointerIn(Fl_Window *win, int &px, int &py)
{
  px = Fl::event_x();
  py = Fl::event_y();
  for(Fl_Window *p = win; p && p->parent(); p = p->window()) {
    px -= p->x();
    py -= p->y();
  }
}

static bool hovered(int x, int y, int w, int h)
{
  Fl_Widget *b = Fl::belowmouse();
  // in the window being drawn: the places are relative to it
  Fl_Window *win = Fl_Window::current();
  if(!hoverable(b) || b->window() != win) return false;
  if(x < b->x() || x + w > b->x() + b->w() || y < b->y() ||
     y + h > b->y() + b->h())
    return false;
  // tabs highlight the one under the pointer, never their own box, the frame of
  // the whole widget, which holds the pointer too
  if(dynamic_cast<Fl_Tabs *>(b)) {
    if(w >= b->w() && h >= b->h()) return false;
    int px, py;
    pointerIn(win, px, py);
    return px >= x && px < x + w && py >= y && py < y + h;
  }
  return true;
}

// Drawn again for the highlight: the region of the window the widget occupies,
// backgrounds and whatever lies over it included, drawn again in order, as
// FLTK redraws a region. A widget drawn on its own would paint over itself
// when it has no box (the label gets bolder), or over what is placed on top
// of it (the content of the option tabs and of the dock, which the tabs do
// not hold). Tabs redraw their row only.
static void redrawHover(Fl_Widget *w)
{
  Fl_Window *win = w->window();
  if(!win) return;
  int h = w->h();
  if(Fl_Tabs *t = dynamic_cast<Fl_Tabs *>(w))
    if(Fl_Widget *v = t->value()) h = v->y() - t->y();
  win->damage(FL_DAMAGE_ALL, w->x(), w->y(), w->w(), h);
}

// the box types the widgets use, each drawn as before after the highlight:
// a box type is not always a constant (FL_ROUND_UP_BOX is a function call in
// FLTK 1.4), so a drawer is made per slot, and the slot knows its type
static const int maxBoxes = 8;
static Fl_Boxtype wrapped[maxBoxes];
static Fl_Box_Draw_F *stock[maxBoxes], *flat = nullptr;
static int numWrapped = 0;

template <int I> static void hover_box(int x, int y, int w, int h, Fl_Color c)
{
  if(wrapped[I] == FL_BORDER_BOX) {
    if(Fl_Window *win = dynamic_cast<Fl_Menu_Window *>(Fl_Window::current())) {
      // a tooltip, which fills its window: on its colour, with the thin frame
      // of the hover boxes of VS Code instead of the black one of FLTK
      if(x == 0 && y == 0 && w == win->w() && h == win->h()) {
        flat(x, y, w, h, c);
        fl_color(
          fl_color_average(FL_FOREGROUND_COLOR, FL_BACKGROUND_COLOR, 0.22f));
        fl_rect(x, y, w, h);
        return;
      }
      // the item chosen in the menu of a choice, without the frame FLTK puts
      // around it (the bordered down box of the choice): flat, as in the
      // menus of the bar
      flat(x, y, w, h, c);
      return;
    }
  }
  if(hovered(x, y, w, h)) {
    c = highlight(c);
    if(getenv("GMSH_HOVER_DEBUG"))
      fprintf(stderr, "hover: highlighted box at (%d,%d) %dx%d\n", x, y, w, h);
  }
  stock[I](x, y, w, h, c);
}

static Fl_Box_Draw_F *const hoverBoxes[maxBoxes] = {
  hover_box<0>, hover_box<1>, hover_box<2>, hover_box<3>,
  hover_box<4>, hover_box<5>, hover_box<6>, hover_box<7>};

static bool ours(Fl_Box_Draw_F *f)
{
  for(int i = 0; i < maxBoxes; i++)
    if(f == hoverBoxes[i]) return true;
  return false;
}

// FLTK puts its own boxes back whenever it reloads its scheme (opening the
// display does), so they are put in place again whenever they are found
// gone, each type keeping its slot; the up and down boxes are the thin ones
// (see FlGui::applyColorScheme())
static void wrap(Fl_Boxtype t)
{
  Fl_Box_Draw_F *f = Fl::get_boxtype(t);
  if(ours(f)) return;
  int i = -1;
  for(int k = 0; k < numWrapped; k++)
    if(wrapped[k] == t) i = k;
  if(i < 0) i = numWrapped++;
  wrapped[i] = t;
  stock[i] = f;
  if(t == FL_FLAT_BOX) flat = f;
  Fl::set_boxtype(t, hoverBoxes[i], Fl::box_dx(t), Fl::box_dy(t), Fl::box_dw(t),
                  Fl::box_dh(t));
}

static void installBoxes()
{
  if(ours(Fl::get_boxtype(FL_THIN_UP_BOX))) return;
  wrap(FL_FLAT_BOX);
  wrap(FL_BORDER_BOX);
  wrap(FL_THIN_UP_BOX);
  wrap(FL_THIN_DOWN_BOX);
  wrap(FL_ROUND_UP_BOX);
  wrap(FL_ROUND_DOWN_BOX);
  // the boxes of Gmsh (the folded section headers of the options)
  wrap(GMSH_SIMPLE_TOP_BOX);
  wrap(GMSH_SIMPLE_RIGHT_BOX);
  Fl::set_boxtype(FL_UP_BOX, FL_THIN_UP_BOX);
  Fl::set_boxtype(FL_DOWN_BOX, FL_THIN_DOWN_BOX);
  if(getenv("GMSH_HOVER_DEBUG")) fprintf(stderr, "hover: boxes installed\n");
}

// a widget without a box (a check box, an icon button) is given a flat one
// while the pointer is over it, so that its whole area highlights; FLTK clears
// the pointer if the widget is deleted meanwhile
static Fl_Widget *boxed = nullptr;

static void boxWhileHovered(Fl_Widget *w)
{
  static bool watched = false;
  if(!watched) {
    Fl::watch_widget_pointer(boxed);
    watched = true;
  }
  if(boxed == w) return;
  if(boxed) {
    boxed->box(FL_NO_BOX);
    boxed = nullptr;
  }
  if(w && hoverable(w) && w->box() == FL_NO_BOX) {
    w->box(FL_FLAT_BOX);
    boxed = w;
  }
}

// the widget the pointer leaves and the one it enters are drawn again
static int hover_dispatch(int event, Fl_Window *win)
{
  installBoxes();
  Fl_Widget *before = Fl::belowmouse();
  int ret = Fl::handle_(event, win);
  Fl_Widget *after = Fl::belowmouse();
  static Fl_Widget *lastTab = nullptr;
  if(before != after) {
    boxWhileHovered(after);
    if(getenv("GMSH_HOVER_DEBUG"))
      fprintf(stderr, "hover: event %d, under the pointer %s '%s' -> %s '%s'\n",
              event, before ? typeid(*before).name() : "none",
              before && before->label() ? before->label() : "",
              after ? typeid(*after).name() : "none",
              after && after->label() ? after->label() : "");
    if(hoverable(before)) redrawHover(before);
    if(hoverable(after)) redrawHover(after);
    lastTab = nullptr;
  }
  else if(Fl_Tabs *t = dynamic_cast<Fl_Tabs *>(after)) {
    // along the row of tabs, from one tab to the next
    int px, py;
    pointerIn(t->window(), px, py);
    Fl_Widget *tab = t->which(px, py);
    if(tab != lastTab) {
      lastTab = tab;
      redrawHover(t);
    }
  }
  return ret;
}

void applyGmshScheme()
{
  // the font of the desktop, where FLTK can be told its name
#if defined(__APPLE__)
  Fl::set_font(FL_HELVETICA, ".AppleSystemUIFont");
  Fl::set_font(FL_HELVETICA_BOLD, ".AppleSystemUIFontBold");
  Fl::set_font(FL_HELVETICA_ITALIC, ".AppleSystemUIFontItalic");
  Fl::set_font(FL_HELVETICA_BOLD_ITALIC, ".AppleSystemUIFontBoldItalic");
#elif defined(WIN32)
  Fl::set_font(FL_HELVETICA, " Segoe UI");
  Fl::set_font(FL_HELVETICA_BOLD, "BSegoe UI");
  Fl::set_font(FL_HELVETICA_ITALIC, "ISegoe UI");
  Fl::set_font(FL_HELVETICA_BOLD_ITALIC, "PSegoe UI");
#else
  // the font the desktop names (GNOME, KDE), the sans of fontconfig
  // otherwise; FLTK keeps the pointers, so the names stay. Under X11 a style
  // is a first character of the name, under Wayland a last word
  static std::string names[4];
  if(names[0].empty()) {
    std::string family = desktopFont();
    if(family.empty()) family = "sans-serif";
    const char *stock = Fl::get_font(FL_HELVETICA);
    bool x11 = (stock && stock[0] == ' ');
    names[0] = x11 ? " " + family : family;
    names[1] = x11 ? "B" + family : family + " Bold";
    names[2] = x11 ? "I" + family : family + " Italic";
    names[3] = x11 ? "P" + family : family + " Bold Italic";
  }
  Fl::set_font(FL_HELVETICA, names[0].c_str());
  Fl::set_font(FL_HELVETICA_BOLD, names[1].c_str());
  Fl::set_font(FL_HELVETICA_ITALIC, names[2].c_str());
  Fl::set_font(FL_HELVETICA_BOLD_ITALIC, names[3].c_str());
#endif

  installBoxes();
  Fl::event_dispatch(hover_dispatch);

  // no dashed rectangle on the widget with the focus
  Fl::visible_focus(0);

  // the entries of every menu, pulldown, popup or choice, on the row pitch
  // of the menus of the desktop (4 pixels without the theme)
  Fl::menu_linespacing(5 + 2 * gmshAir());
}

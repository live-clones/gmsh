// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The FLTK interface: one window -- the menu bar, the tree down the left, the
// scene and the console under it, the bar along the bottom -- and a window for
// each described form (dialogFltk.cpp). The loop is FLTK's, turned by hand, so
// that check() and wait() can turn it from inside the mesher, and a question
// can run a loop of its own.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <mutex>
#include <regex>
#include <string>
#include <thread>
#include <vector>

#include <FL/Fl.H>
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
// OK
#elif(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 3)
// OK
#else
#error "Gmsh requires FLTK >= 1.3.3"
#endif
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_File_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#if defined(__APPLE__)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif

#include "fltkCommon.h"
#include "Bar.h"
#include "Console.h"
#include "Glyph.h"
#include "XpmIcon.h"

#if defined(HAVE_3M)
#include "3M.h"
#endif

namespace {

  // --- the thread it runs on, and the other threads holding it

  std::atomic<int> _locked(0);
  std::thread::id _thread;

  bool _onThread() { return std::this_thread::get_id() == _thread; }

  // --- what a string is made of

  void _replaceAll(const std::string &what, const std::string &with,
                   std::string &in)
  {
    for(std::size_t at = in.find(what); at != std::string::npos;
        at = in.find(what, at + with.size()))
      in.replace(at, what.size(), with);
  }

  // the directory, the name and the extension
  std::vector<std::string> _splitName(const std::string &name)
  {
    std::size_t slash = name.find_last_of("/\\");
    std::string dir = slash == std::string::npos ? "" : name.substr(0, slash + 1);
    std::string rest = slash == std::string::npos ? name : name.substr(slash + 1);
    std::size_t dot = rest.find_last_of('.');
    if(dot == std::string::npos) return {dir, rest, ""};
    return {dir, rest.substr(0, dot), rest.substr(dot)};
  }

  enum { _single = 0, _multi, _create, _directory };

  // --- the icons of the bar, the tree and the console, and the boxes the
  // windows draw themselves with

  static void simple_right_box_draw(int x, int y, int w, int h, Fl_Color c)
  {
    fl_color(c);
    fl_rectf(x, y, w, h);
    fl_color(FL_DARK2);
    fl_line(x + w - 1, y, x + w - 1, y + h);
  }

  static void simple_top_box_draw(int x, int y, int w, int h, Fl_Color c)
  {
    fl_color(c);
    fl_rectf(x, y, w, h);
    fl_color(FL_DARK2);
    fl_line(x, y, x + w, y);
  }

  // --- the pictures of Glyph.h as FLTK symbols, "gmsh_" and their name: a
  // symbol is drawn by a function that is told only its colour, one per
  // glyph

  void _drawGlyph(const Ui::Glyph &g, Fl_Color ink)
  {
    for(const Ui::Stroke &k : g.strokes) {
      fl_color(k.colour.a ? fl_rgb_color(k.colour.r, k.colour.g, k.colour.b) :
                            ink);
      if(k.width != 1.) fl_line_style(FL_SOLID, (int)k.width);
      switch(k.kind) {
      case Ui::Stroke::Line: fl_begin_line(); break;
      case Ui::Stroke::Loop: fl_begin_loop(); break;
      case Ui::Stroke::Fill: fl_begin_polygon(); break;
      }
      for(std::size_t i = 0; i + 1 < k.points.size(); i += 2)
        fl_vertex(k.points[i], k.points[i + 1]);
      switch(k.kind) {
      case Ui::Stroke::Line: fl_end_line(); break;
      case Ui::Stroke::Loop: fl_end_loop(); break;
      case Ui::Stroke::Fill: fl_end_polygon(); break;
      }
      if(k.width != 1.) fl_line_style(FL_SOLID);
    }
  }

  template <int I> void _glyphSymbol(Fl_Color ink)
  {
    if(I < (int)Ui::glyphs().size()) _drawGlyph(Ui::glyphs()[I], ink);
  }

  void _addGlyphSymbols()
  {
    typedef void (*symbol)(Fl_Color);
    static const symbol drawn[] = {
      _glyphSymbol<0>,  _glyphSymbol<1>,  _glyphSymbol<2>,  _glyphSymbol<3>,
      _glyphSymbol<4>,  _glyphSymbol<5>,  _glyphSymbol<6>,  _glyphSymbol<7>,
      _glyphSymbol<8>,  _glyphSymbol<9>,  _glyphSymbol<10>, _glyphSymbol<11>,
      _glyphSymbol<12>, _glyphSymbol<13>, _glyphSymbol<14>, _glyphSymbol<15>,
      _glyphSymbol<16>, _glyphSymbol<17>, _glyphSymbol<18>, _glyphSymbol<19>};
    // FLTK keeps the name it is given
    static std::deque<std::string> names;
    const std::vector<Ui::Glyph> &all = Ui::glyphs();
    for(std::size_t i = 0; i < all.size() && i < sizeof(drawn) / sizeof(drawn[0]); i++) {
      names.push_back("gmsh_" + all[i].name);
      fl_add_symbol(names.back().c_str(), drawn[i], 1);
    }
  }
#undef bl
#undef el


  void _applyColorScheme(bool redraw)
  {
    static int first = true;
    int N = 4 + FL_NUM_GRAY;
    static std::vector<unsigned char> r(N, 0), g(N, 0), b(N, 0);

    if(first) {
      // store default (OS-dependent) interface colors:
      Fl::get_system_colors();
      Fl::get_color(FL_BACKGROUND_COLOR, r[0], g[0], b[0]);
      Fl::get_color(FL_BACKGROUND2_COLOR, r[1], g[1], b[1]);
      Fl::get_color(FL_FOREGROUND_COLOR, r[2], g[2], b[2]);
      Fl::get_color(FL_SELECTION_COLOR, r[3], g[3], b[3]);
      for(int i = 0; i < FL_NUM_GRAY; i++) {
        Fl::get_color(fl_gray_ramp(i), r[4 + i], g[4 + i], b[4 + i]);
      }
    }

    if(fltkSources().settings().darkScheme) {
      Fl::set_color(FL_BACKGROUND_COLOR, 20, 20, 20);
      Fl::set_color(FL_BACKGROUND2_COLOR, 70, 70, 70);
      Fl::set_color(FL_FOREGROUND_COLOR, 220, 220, 220);
      for(int i = 0; i < FL_NUM_GRAY; i++) {
        double min = 0., max = 70.;
        int d = (int)(min + i * (max - min) / (FL_NUM_GRAY - 1.));
        Fl::set_color(fl_gray_ramp(i), d, d, d);
      }
      Fl::set_color(FL_SELECTION_COLOR, 200, 200, 200);
    }
    else if(!first) {
      // retore default colors (only if not calling the routine from the
      // constructor)
      Fl::set_color(FL_BACKGROUND_COLOR, r[0], g[0], b[0]);
      Fl::set_color(FL_BACKGROUND2_COLOR, r[1], g[1], b[1]);
      Fl::set_color(FL_FOREGROUND_COLOR, r[2], g[2], b[2]);
      for(int i = 0; i < FL_NUM_GRAY; i++) {
        Fl::set_color(fl_gray_ramp(i), r[4 + i], g[4 + i], b[4 + i]);
      }
      Fl::set_color(FL_SELECTION_COLOR, r[3], g[3], b[3]);
    }

    first = false;

    // also change default box type here (to thin versions)
    Fl::set_boxtype(FL_UP_BOX, FL_THIN_UP_BOX);
    Fl::set_boxtype(FL_DOWN_BOX, FL_THIN_DOWN_BOX);
    Fl::set_boxtype(FL_UP_FRAME, FL_THIN_UP_FRAME);
    Fl::set_boxtype(FL_DOWN_FRAME, FL_THIN_DOWN_FRAME);

    // thinner scrollbars
    Fl::scrollbar_size(std::max(10, FL_NORMAL_SIZE));

    if(redraw) {
      for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win)) {
        win->redraw();
      }
    }
  }


  // This dummy box class permits to define a box widget that will not eat the
  // FL_ENTER/FL_LEAVE events (the box widget in fltk > 1.1 does that, so that
  // gl->handle() was not called when the mouse moved)
  class dummyBox : public Fl_Box {
  private:
    int handle(int) { return 0; } // always!
  public:
    dummyBox(int x, int y, int w, int h, const char *l = nullptr)
      : Fl_Box(x, y, w, h, l)
    {
    }
  };


  // Derive the main window from Fl_Window (it shows up faster that way)
  class topWindow : public Fl_Window {
  public:
    // what the main window lays out again once it has its new size
    static void (*resized)(Fl_Window *);
    topWindow(int w, int h, bool nonModal, const char *l = nullptr)
      : Fl_Window(w, h, l)
    {
      if(nonModal) set_non_modal();
    }
    virtual int handle(int event)
    {
      switch(event) {
      case FL_SHORTCUT:
      case FL_KEYBOARD:
#if defined(__APPLE__)
        if(Fl::test_shortcut(FL_META + 'w')) {
#elif defined(WIN32)
        if(Fl::test_shortcut(FL_ALT + FL_F + 4)) {
#else
        if(Fl::test_shortcut(FL_CTRL + 'w')) {
#endif
          if(fl_choice("Do you really want to quit?", "Cancel", "Quit", nullptr))
            do_callback();
          return 1;
        }
        break;
      }
      return Fl_Window::handle(event);
    }
    virtual void resize(int X, int Y, int W, int H)
    {
      Fl_Window::resize(X, Y, W, H);
      if(resized) resized(this);
    }
    virtual void show()
    {
      if(non_modal() && !shown()) Fl_Window::show(); // fix ordering
      Fl_Window::show();
    }
  };


  class console : public Fl_Group {
  private:
    Fl_Browser *_browser;
    Fl_Group *_box;
    Fl_Check_Button *_autoscroll;
    Fl_Button *_clear, *_save;
    Fl_Input *_search;

  public:
    console(int x, int y, int w, int h, const char *l = 0)
      : Fl_Group(x, y, w, h, l)
    {
      int bh = BH - 4; // button height
      int wb = WB / 2; // border
      int bb = BB - 3 * WB;
      int sw = 3 * BB; // search field width

      _box = new Fl_Group(x, y, w, bh + 2 * wb);
      _box->box(GMSH_SIMPLE_TOP_BOX);

      Fl_Group *o = new Fl_Group(x + wb, y + wb, sw, bh);
      o->tooltip(Ui::Console::filterTip());
      o->box(FL_THIN_DOWN_BOX);
      o->color(FL_BACKGROUND2_COLOR);
      _search = new Fl_Input(x + wb + bh, y + wb + 2, sw - bh - 2, bh - 4);
      _search->copy_label(
        (std::string("@-1gmsh_") + Ui::Console::filterGlyph()).c_str());
      _search->box(FL_FLAT_BOX);
      _search->when(FL_WHEN_CHANGED);
      _search->textsize(FL_NORMAL_SIZE - 1);
      o->resizable(_search);
      o->end();

      _save = new Fl_Button(x + wb + sw + WB, y + wb, bb, bh,
                            Ui::Console::saveLabel());
      _save->tooltip(Ui::Console::saveTip());
      _save->labelsize(FL_NORMAL_SIZE - 1);
      _save->box(FL_THIN_UP_BOX);

      _clear = new Fl_Button(x + sw + bb + 2 * WB, y + wb, bb, bh,
                             Ui::Console::clearLabel());
      _clear->tooltip(Ui::Console::clearTip());
      _clear->labelsize(FL_NORMAL_SIZE - 1);
      _clear->box(FL_THIN_UP_BOX);

      _autoscroll = new Fl_Check_Button(x + sw + 2 * bb + 3 * WB, y + wb, 2 * bb,
                                        bh, Ui::Console::autoScrollLabel());
      _autoscroll->labelsize(FL_NORMAL_SIZE - 1);
      _autoscroll->type(FL_TOGGLE_BUTTON);
      _autoscroll->value(1);

      _box->end();
      _box->resizable(0);

      _browser = new Fl_Browser(x, y + bh + 2 * wb, w, h - bh - 2 * wb, l);
      _browser->box(GMSH_SIMPLE_TOP_BOX);
#if defined(WIN32) // FL_SCREEN seems to be too tiny on most Windows setups
      _browser->textfont(FL_COURIER);
#else
      _browser->textfont(FL_SCREEN);
#endif
      _browser->type(FL_MULTI_BROWSER);
      _browser->tooltip("Selected lines are copied to the clipboard");
      _browser->end();
      end();
      resizable(_browser);
    }
    void box(Fl_Boxtype new_box) { _browser->box(new_box); }
    void textfont(Fl_Font font) { _browser->textfont(font); }
    void textsize(Fl_Fontsize newSize) { _browser->textsize(newSize); }
    Fl_Fontsize textsize() const { return _browser->textsize(); }
    void callback(Fl_Callback *cb, void *p) { _browser->callback(cb, p); }
    void search_callback(Fl_Callback *cb, void *p) { _search->callback(cb, p); }
    void autoscroll_callback(Fl_Callback *cb, void *p)
    {
      _autoscroll->callback(cb, p);
    }
    void save_callback(Fl_Callback *cb, void *p) { _save->callback(cb, p); }
    void clear_callback(Fl_Callback *cb, void *p) { _clear->callback(cb, p); }
    void bottomline(int line) { _browser->bottomline(line); }
    int size() { return _browser->size(); }
    void add(const char *line) { _browser->add(line); }
    const char *filter() const { return _search->value(); }
    bool autoScrolling() const { return _autoscroll->value() != 0; }
    void clear() { _browser->clear(); }
    const char *text(int line) const { return _browser->text(line); }
    int selected(int line) const { return _browser->selected(line); }
  };


  class statusButtonFltk : public Fl_Button {
  public:
    Ui::BarButton what;
    statusButtonFltk(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {}
    std::string shown() const
    {
      bool on = what.on && what.on();
      const std::string &glyph = (on && what.glyphOn.size()) ? what.glyphOn :
                                                               what.glyph;
      if(Ui::glyph(glyph)) return "@-1gmsh_" + glyph;
      return (on && what.labelOn.size()) ? what.labelOn : what.label;
    }
    // whether it changed
    bool refresh();
    void draw() override
    {
      refresh();
      Fl_Button::draw();
    }
    int handle(int event) override
    {
      if(event == FL_PUSH && what.menu) {
        fltkPopupMenu(what.menu(), Fl::event_x(), Fl::event_y(), what.label);
        return 1;
      }
      return Fl_Button::handle(event);
    }
  };
#if defined(__APPLE__)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif
#include <FL/Fl_Menu_Bar.H>

  class sceneViewFltk;
  class sceneView;
  class onelabGroup;

  // asked of the description rather than remembered
  bool statusButtonFltk::refresh()
  {
    bool changed = false;
    std::string text = shown();
    if(!label() || text != label()) {
      copy_label(text.c_str());
      changed = true;
    }
    bool enabled = what.enabled ? what.enabled() : true;
    if(enabled != (active() ? true : false)) {
      if(enabled)
        activate();
      else
        deactivate();
      changed = true;
    }
    Fl_Color want = FL_BACKGROUND_COLOR;
    if(what.alert && what.alert())
      want = FL_RED;
    else if(what.onColour && what.on && what.on()) {
      Ui::Colour c = what.onColour();
      want = fl_rgb_color(c.r, c.g, c.b);
    }
    if(color() != want) {
      color(want);
      changed = true;
    }
    return changed;
  }


  class progressFltk : public Fl_Progress {
  public:
    progressFltk(int x, int y, int w, int h, const char *l = nullptr)
      : Fl_Progress(x, y, w, h, l)
    {
    }
    void draw() override
    {
      const Ui::Backend::Sources &sources = fltkSources();
      Ui::BarMessage m = sources.barMessage ? sources.barMessage() : Ui::BarMessage();
      if(!label() || m.text != label()) copy_label(m.text.c_str());
      minimum(0.);
      maximum(m.running ? 1. : 0.);
      value(m.running ? (float)m.fraction : 0.f);
      bool dark = sources.settings().darkScheme;
      int col = (m.weight == Ui::MessageError) ? (dark ? FL_DARK_RED : FL_RED) :
                (m.weight == Ui::MessageWarning) ?
                                                (dark ? FL_DARK_YELLOW : FL_YELLOW) :
                                                -1;
      if(col >= 0) {
        if(dark)
          color(col);
        else
          labelcolor(col);
      }
      else {
        color(FL_BACKGROUND_COLOR);
        labelcolor(FL_FOREGROUND_COLOR);
      }
      Fl_Progress::draw();
    }
    int handle(int event)
    {
      if(event == FL_PUSH) {
        if(fltkSources().barPressed) fltkSources().barPressed();
        return 1;
      }
      return Fl_Progress::handle(event);
    }
  };


  // basic file chooser
  class flFileChooser : public Fl_File_Chooser {
    // we derive our own so we can set its position (The original file
    // chooser doesn't expose its window to the world, so we need to use
    // a cheap hack to get to it. Even worse is the hack used to get the
    // focus on the file input widget.)
  private:
    Fl_Window *_win;
    Fl_File_Input *_in;

  public:
    flFileChooser(const char *d, const char *p, int t, const char *title)
      : Fl_File_Chooser(d, p, t, title)
    {
      _win = dynamic_cast<Fl_Window *>(newButton->parent()->parent());
      _in = dynamic_cast<Fl_File_Input *>(
        previewButton->parent()->parent()->resizable());
    }
    void show()
    {
      if(_win) {
        _win->show();
        rescan(); // necessary since fltk 1.1.7
        if(_in)
          _in->take_focus();
        else
          _win->take_focus();
      }
      else
        Fl_File_Chooser::show();
    }
    void position(int x, int y)
    {
      if(_win) _win->position(x, y);
    }
    int x()
    {
      if(_win)
        return _win->x();
      else
        return 100;
    }
    int y()
    {
      if(_win)
        return _win->y();
      else
        return 100;
    }
  };

  static flFileChooser *fc = nullptr;

  // native file chooser
  static Fl_Native_File_Chooser *nfc = nullptr;

  int _fileChooser(int type, const char *message, const char *filter,
                  const char *fname)
  {
    static char thefilter[2000] = "";
    static char thefilter2[2000] = "";
    static int thefilterindex = 0;

    // reset the filter and the selection if the filter has changed
    if(strncmp(thefilter, filter, sizeof(thefilter) - 1)) {
      strncpy(thefilter, filter, sizeof(thefilter) - 1);
      thefilter[sizeof(thefilter) - 1] = '\0';
      thefilterindex = 0;
      // for the basic file chooser, we should replace
      //  * "\t" with " ("
      //  * "\n" with ")\t"
      std::string tmp(thefilter);
      _replaceAll("\t", " (", tmp);
      _replaceAll("\n", ")\t", tmp);
      strncpy(thefilter2, tmp.c_str(), sizeof(thefilter2) - 1);
      thefilter2[sizeof(thefilter2) - 1] = '\0';
    }

    // determine where to start
    std::string thepath = fname ? fname : "";
    std::vector<std::string> split = _splitName(thepath);
    if(split[0].empty()) thepath = std::string("./") + thepath;

    if(fltkSources().settings().nativeFileChooser) {
      if(!nfc) {
        nfc = new Fl_Native_File_Chooser();
        nfc->preset_file(thepath.c_str());
      }
      else {
        std::string name = split[1] + split[2];
        nfc->preset_file(name.c_str());
      }

      switch(type) {
      case _multi:
        nfc->type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
        break;
      case _create:
        nfc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
        break;
      case _directory:
        nfc->type(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
        break;
      default: nfc->type(Fl_Native_File_Chooser::BROWSE_FILE); break;
      }
      nfc->title(message);
      nfc->filter(thefilter);
      nfc->filter_value(thefilterindex);

      int ret = 0;
      switch(nfc->show()) {
      case -1: break; // error
      case 1: break; // cancel
      default:
        if(nfc->filename()) ret = nfc->count();
        break;
      }
      thefilterindex = nfc->filter_value();
      // hack to clear the KEYDOWN state that remains when calling the
      // file chooser on Mac and Windows using a keyboard shortcut
      Fl::e_state = 0;
      return ret;
    }
    else {
      Fl_File_Chooser::show_label = "Format:";
      Fl_File_Chooser::all_files_label = "All files (*)";
      if(!fc) {
        fc = new flFileChooser(thepath.c_str(), thefilter2,
                               Fl_File_Chooser::SINGLE, message);
        fc->position(fltkSources().settings().chooserX,
                     fltkSources().settings().chooserY);
      }
      switch(type) {
      case _multi: fc->type(Fl_File_Chooser::MULTI); break;
      case _create: fc->type(Fl_File_Chooser::CREATE); break;
      case _directory: fc->type(Fl_File_Chooser::DIRECTORY); break;
      default: fc->type(Fl_File_Chooser::SINGLE); break;
      }
      fc->label(message);
      fc->filter(thefilter2);
      fc->filter_value(thefilterindex);
      fc->show();
      while(fc->shown()) Fl::wait();
      thefilterindex = fc->filter_value();
      if(fc->value())
        return fc->count();
      else
        return 0;
    }
  }

  std::string _chosenName(int num)
  {
    if(fltkSources().settings().nativeFileChooser) {
      if(!nfc) return "";
      return std::string(nfc->filename(num - 1));
    }
    else {
      if(!fc) return "";
      return std::string(fc->value(num));
    }
  }

  int _chosenFilter()
  {
    if(fltkSources().settings().nativeFileChooser) {
      if(!nfc) return 0;
      return nfc->filter_value();
    }
    else {
      if(!fc) return 0;
      return fc->filter_value();
    }
  }

  void _chooserPosition(int *x, int *y)
  {
    if(fltkSources().settings().nativeFileChooser) {
      // not available
    }
    else {
      if(!fc) return;
      *x = fc->x();
      *y = fc->y();
    }
  }

  int _showText(const char *title, const std::string &text)
  {
    struct _display {
      Fl_Window *window;
      Fl_Text_Buffer *buff;
      Fl_Text_Display *disp;
    };
    static _display *display = nullptr;

    if(!display) {
      display = new _display;
      display->window =
        new paletteWindow(4 * BB + 2 * WB, 5 * BH + 2 * WB,
                          fltkSources().settings().nonModalWindows);
      display->buff = new Fl_Text_Buffer();
      display->disp = new Fl_Text_Display(WB, WB, 4 * BB, 5 * BH);
      display->disp->buffer(display->buff);
      display->disp->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);
      display->window->end();
      display->window->resizable(display->disp);
    }
    display->window->label(title);
    display->buff->text(text.c_str());
    display->window->hotspot(display->window);
    display->window->show();

    while(display->window->shown()) {
      Fl::wait();
      for(;;) {
        Fl_Widget *o = Fl::readqueue();
        if(!o) break;
        if(o == display->window) {
          display->window->hide();
          return 0;
        }
      }
    }
    return 0;
  }

  int _editText(const char *title, const std::string &help,
                       std::string &text)
  {
    struct _editor {
      Fl_Window *window;
      Fl_Text_Buffer *buff;
      Fl_Text_Editor *edit;
      Fl_Button *apply, *cancel;
      Fl_Box *help;
      char *help_text;
    };
    static _editor *editor = nullptr;

    if(!editor) {
      editor = new _editor;
      editor->window =
        new paletteWindow(4 * BB + 2 * WB, 7 * BH + 3 * WB,
                          fltkSources().settings().nonModalWindows);
      editor->help_text = strdup(help.c_str());
      editor->help = new Fl_Box(WB, WB / 2, 4 * BB, BH, editor->help_text);
      editor->help->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      editor->buff = new Fl_Text_Buffer();
      editor->edit = new Fl_Text_Editor(WB, WB + BH, 4 * BB, 5 * BH);
      editor->edit->buffer(editor->buff);
      editor->edit->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);
      editor->apply =
        new Fl_Return_Button(4 * BB + WB - BB, 2 * WB + 6 * BH, BB, BH, "Apply");
      editor->cancel =
        new Fl_Button(4 * BB - 2 * BB, 2 * WB + 6 * BH, BB, BH, "Cancel");
      Fl_Box *resize = new Fl_Box(WB, WB + BH, WB, WB);
      editor->window->end();
      editor->window->resizable(resize);
    }
    editor->window->label(title);
    editor->buff->text(text.c_str());
    editor->window->hotspot(editor->window);
    editor->window->show();

    while(editor->window->shown()) {
      Fl::wait();
      for(;;) {
        Fl_Widget *o = Fl::readqueue();
        if(!o) break;
        if(o == editor->apply) {
          char *t = editor->buff->text();
          text = t;
          free(t);
          editor->window->hide();
          return 1;
        }
        if(o == editor->window || o == editor->cancel) {
          editor->window->hide();
          return 0;
        }
      }
    }
    return 0;
  }


  // --- the main window

  struct mainWindow {
    topWindow *win = nullptr;
    Fl_Menu_Bar *bar = nullptr;
#if defined(__APPLE__)
    Fl_Sys_Menu_Bar *sysbar = nullptr;
#endif
    Fl_Tile *tile = nullptr;
    Fl_Group *scene = nullptr, *status = nullptr;
    treeFltk *tree = nullptr;
    // the tree in a window of its own
    topWindow *treeWin = nullptr;
    console *messages = nullptr;
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console said;
    int minWidth = 100, minHeight = 100;
    // what full screen hides, and what "Zoom" puts back
    bool fullscreen = false, zoomed = false;
    int treeWas = 0, consoleWas = 0;
    int oldX = 0, oldY = 0, oldW = 0, oldH = 0;
  };

  mainWindow *_w = nullptr;
  bool _dark = false;

  void (*topWindow::resized)(Fl_Window *) = nullptr;

  // the bars made, of the main window and of the graphic windows of their own
  std::vector<Fl_Group *> _bars;

  int _statusHeight() { return 2 * FL_NORMAL_SIZE - 3; }
  int _menuHeight()
  {
#if defined(__APPLE__)
    if(fltkSources().settings().systemMenuBar) return 0;
#endif
    return BH;
  }

  void _forgetting(const Ui::Backend::Layout &what)
  {
    if(fltkHost().layoutChanged) fltkHost().layoutChanged(what);
  }

  // --- the console under the scene: a height of 0 is hidden

  int _consoleHeight() { return _w && _w->messages ? _w->messages->h() : 0; }

  void _setConsoleHeight(int h)
  {
    if(!_w || !_w->messages) return;
    int dh = h - _w->messages->h();
    if(!dh) return;
    Fl_Group *s = _w->scene;
    s->resize(s->x(), s->y(), s->w(), s->h() - dh);
    _w->messages->resize(_w->messages->x(), _w->messages->y() - dh,
                         _w->messages->w(), _w->messages->h() + dh);
    _w->tile->init_sizes();
    _w->tile->redraw();
  }

  void _showConsole()
  {
    if(!_w || !_w->win->shown()) return;
    if(_consoleHeight() < FL_NORMAL_SIZE) {
      int height = fltkSources().settings().consoleHeight;
      if(height < FL_NORMAL_SIZE) height = 10 * FL_NORMAL_SIZE;
      int most = _w->tile->h();
      if(height > most) height = most / 2;
      _setConsoleHeight(height);
    }
    if(_w->said.autoScroll()) _w->messages->bottomline(_w->messages->size());
  }

  void _hideConsole()
  {
    if(!_w) return;
    Ui::Backend::Layout l;
    l.consoleHeight = _consoleHeight();
    _forgetting(l);
    _setConsoleHeight(0);
  }

  // Fl_Browser colour codes; a dark scheme wants lighter ones
  std::string _linePrefix(int level)
  {
    switch(level) {
    case Ui::Backend::Direct: return _dark ? "@B136@." : "@C4@.";
    case Ui::Backend::Error: return _dark ? "@B72@." : "@C1@.";
    case Ui::Backend::Warning: return _dark ? "@B152@." : "@C5@.";
    // a line that starts with "@" would be read as a code
    default: return "@.";
    }
  }

  void _addLine(const std::string &text, int level)
  {
    if(!_w) return;
    // Msg::Info can be called from the threads of the mesher
#pragma omp critical(addMessage)
    {
      if(_w->said.add(text, level)) {
        _w->messages->add((_linePrefix(level) + text).c_str());
        if(_w->said.autoScroll() && _w->win->shown() &&
           _consoleHeight() >= FL_NORMAL_SIZE)
          _w->messages->bottomline(_w->messages->size());
      }
    }
  }

  // the lines again, filtered as the field says
  void _refillConsole()
  {
    if(!_w) return;
    _w->messages->clear();
    for(const Ui::Console::Line *l : _w->said.shown())
      _w->messages->add((_linePrefix(l->level) + l->text).c_str());
    if(_w->said.autoScroll()) _w->messages->bottomline(_w->messages->size());
  }

  void _filterConsole(Fl_Widget *, void *)
  {
    if(_w && _w->said.setFilter(_w->messages->filter())) _refillConsole();
  }

  void _copySelectedLines(Fl_Widget *, void *)
  {
    if(!_w) return;
    std::string buff;
    for(int i = 1; i <= _w->messages->size(); i++) {
      if(!_w->messages->selected(i)) continue;
      const char *c = _w->messages->text(i);
      // the colour code, up to "@."
      const char *text = c[0] == '@' ? strstr(c, "@.") : nullptr;
      buff += text ? text + 2 : c;
      buff += "\n";
    }
    Fl::copy(buff.c_str(), (int)buff.size(), 0);
    Fl::copy(buff.c_str(), (int)buff.size(), 1);
  }

  void _consoleFont(int size)
  {
    if(!_w) return;
    _w->messages->textsize(size <= 0 ? FL_NORMAL_SIZE - 2 : size);
    _w->messages->redraw();
  }

  // --- the tree beside the scene: a width of 0 is hidden

  int _treeWidth() { return _w && _w->tree ? _w->tree->w() : 0; }

  void _setTreeWidth(int w)
  {
    if(!_w || !_w->tree) return;
    if(_w->treeWin) {
      _w->treeWin->size(std::max(w, _w->tree->minWindowWidth()),
                        _w->treeWin->h());
      _w->treeWin->redraw();
      return;
    }
    int dw = w - _w->tree->w();
    if(!dw) return;
    Fl_Group *s = _w->scene;
    s->resize(s->x() + dw, s->y(), s->w() - dw, s->h());
    _w->messages->resize(_w->messages->x() + dw, _w->messages->y(),
                         _w->messages->w() - dw, _w->messages->h());
    _w->tree->resize(_w->tree->x(), _w->tree->y(), _w->tree->w() + dw,
                     _w->tree->h());
    _w->tile->init_sizes();
    _w->tile->redraw();
  }

  void _showTree()
  {
    if(!_w || _w->treeWin || !_w->win->shown()) return;
    if(_treeWidth() < FL_NORMAL_SIZE) {
      int width = fltkSources().settings().treeWidth;
      if(width < FL_NORMAL_SIZE) width = _w->tree->minWindowWidth();
      if(width > _w->win->w()) width = _w->win->w() / 2;
      _setTreeWidth(width);
      // necessary until resizing of 0-sized groups works
      _w->tree->rebuild(true);
    }
  }

  void _hideTree()
  {
    if(!_w || _w->treeWin) return;
    Ui::Backend::Layout l;
    l.treeWidth = _treeWidth();
    _forgetting(l);
    _setTreeWidth(0);
  }

  void _quit(Fl_Widget *, void *)
  {
    if(fltkHost().quitting) fltkHost().quitting();
  }

  void _attachTree();

  // closed from its frame, the tree goes back in the main window, once the
  // event is over: the window is deleted
  void _treeClosed(Fl_Widget *, void *)
  {
    fltkLater([]() { _attachTree(); });
  }

  // the tree taken out of the main window into one of its own, and put back
  void _detachTree()
  {
    if(!_w || _w->treeWin) return;
    if(_consoleHeight() == 0) _setConsoleHeight(1);
    int w = _w->tree->w();
    _w->tile->remove(_w->tree);
    Fl_Group *s = _w->scene;
    s->resize(0, s->y(), s->w() + w, s->h());
    _w->messages->resize(0, _w->messages->y(), _w->messages->w() + w,
                         _w->messages->h());
    _w->tile->init_sizes();
    _w->tile->redraw();

    const Ui::Backend::Settings set = fltkSources().settings();
    Fl_Group *current = Fl_Group::current();
    Fl_Group::current(nullptr);
    _w->treeWin = new topWindow(w, set.treeHeight > 0 ? set.treeHeight : 600,
                                set.nonModalWindows, "Gmsh");
    Fl_Group::current(current);
    _w->treeWin->callback(_treeClosed);
    _w->treeWin->box(GMSH_WINDOW_BOX);
    _w->tree->box(FL_FLAT_BOX);
    _w->treeWin->add(_w->tree);
    _w->tree->resize(0, 0, _w->treeWin->w(), _w->treeWin->h());
    if(set.treeX > 0 || set.treeY > 0)
      _w->treeWin->position(set.treeX, set.treeY);
    _w->treeWin->resizable(_w->tree);
    _w->treeWin->size_range(_w->tree->minWindowWidth(),
                            _w->tree->minWindowHeight());
    _w->treeWin->end();
    _w->treeWin->show();
    _w->tree->enableTreeWidgetResize(true);
    _w->tree->rebuild(true);
  }

  void _attachTree()
  {
    if(!_w || !_w->treeWin) return;
    {
      Ui::Backend::Layout l;
      l.treeX = _w->treeWin->x();
      l.treeY = _w->treeWin->y();
      l.treeHeight = _w->treeWin->h();
      _forgetting(l);
    }
    _w->treeWin->remove(_w->tree);
    _w->treeWin->hide();
    delete _w->treeWin;
    _w->treeWin = nullptr;
    if(_consoleHeight() == 0) _setConsoleHeight(1);
    int w = _w->tree->w();
    if(_w->messages->w() - w < 0) w = _w->messages->w() / 2;
    Fl_Group *s = _w->scene;
    s->resize(w, s->y(), s->w() - w, s->h());
    _w->messages->resize(w, _w->messages->y(), _w->messages->w() - w,
                         _w->messages->h());
    _w->tree->box(GMSH_SIMPLE_RIGHT_BOX);
    _w->tile->add(_w->tree);
    _w->tree->resize(_w->tile->x(), _w->tile->y(), w, _w->tile->h());
    _w->tile->init_sizes();
    _w->tile->redraw();
    _w->tree->enableTreeWidgetResize(false);
    _w->tree->rebuild(true);
  }

  // the tree is built again once the mouse lets go of a border it dragged
  void _tileMoved(Fl_Widget *, void *)
  {
    if(Fl::event() == FL_RELEASE && _w && _w->tree) _w->tree->rebuild(true);
  }

  // --- the window as a whole

  void _fullscreen(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    int mh = _menuHeight(), sh = _statusHeight();
    if(on) {
      // nothing but the scene
      _w->treeWas = _w->treeWin ? -1 : _treeWidth();
      _w->consoleWas = _consoleHeight();
      if(!_w->treeWin) _setTreeWidth(0);
      _setConsoleHeight(0);
      // a console of no height still shows its bar
      _w->messages->hide();
      if(_w->bar) _w->bar->hide();
      _w->status->hide();
      // the scene over all of the screen, once the window has its size
      _w->win->fullscreen();
      _w->tile->resize(0, 0, _w->win->w(), _w->win->h());
    }
    else {
      _w->win->fullscreen_off();
      if(_w->bar) _w->bar->show();
      _w->status->show();
      _w->messages->show();
      _w->tile->resize(0, mh, _w->win->w(), _w->win->h() - mh - sh);
      _w->status->resize(0, _w->win->h() - sh, _w->win->w(), sh);
      if(_w->treeWas > 0) {
        _setTreeWidth(_w->treeWas);
        // necessary until resizing of 0-sized groups works
        _w->tree->rebuild(true);
      }
      if(_w->consoleWas > 0) _setConsoleHeight(_w->consoleWas);
    }
    _w->tile->init_sizes();
    _w->win->redraw();
  }

  void _fullscreenResized(Fl_Window *win)
  {
    if(!_w || win != _w->win || !_w->fullscreen) return;
    _w->tile->resize(0, 0, win->w(), win->h());
    _w->tile->init_sizes();
  }

  void _zoom()
  {
    if(!_w || _w->fullscreen) return;
    if(!_w->zoomed) {
      _w->oldX = _w->win->x();
      _w->oldY = _w->win->y();
      _w->oldW = _w->win->w();
      _w->oldH = _w->win->h();
      _w->win->resize(Fl::x(), Fl::y(), Fl::w(), Fl::h());
    }
    else
      _w->win->resize(_w->oldX, _w->oldY, _w->oldW, _w->oldH);
    _w->zoomed = !_w->zoomed;
  }

  // the size of the type when the options say none: the height of the main
  // screen says it
  int _fontSize()
  {
    int said = fltkSources().settings().fontSize;
    if(said > 0) return said;
    int h = Fl::h();
    if(h < 800) return 11;
    if(h < 1000) return 12;
    if(h < 1200) return 13;
    if(h < 1400) return 14;
    if(h < 1600) return 15;
    if(h < 1800) return 16;
    float dpih = 96.f, dpiv = 96.f;
    Fl::screen_dpi(dpih, dpiv);
    return std::max(16, (int)(dpih / 10.));
  }

  // FLTK's errors: "Insufficient GL support" leaves nothing to show
  void _error(const char *format, ...)
  {
    char str[5000];
    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof(str), format, args);
    va_end(args);
    if(fltkHost().error) fltkHost().error(std::string(str) + " (FLTK)");
    if(!strcmp(str, "Insufficient GL support")) {
      if(fltkHost().error)
        fltkHost().error("Your system does not seem to support OpenGL");
      exit(1);
    }
  }

  void _fatal(const char *format, ...)
  {
    char str[5000];
    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof(str), format, args);
    va_end(args);
    if(fltkHost().error) fltkHost().error(std::string(str) + " (FLTK)");
    exit(1);
  }

  // the shortcuts, for the keys no widget took
  int _globalShortcut(int event)
  {
    if(event != FL_SHORTCUT) return 0;
    return fltkMainKey() ? 1 : 0;
  }

#if defined(__APPLE__)
  // what the Finder asks to open, and the About entry of the application
  // menu, which is the one of the menu bar
  void _openFromFinder(const char *name)
  {
    std::function<void(const std::vector<std::string> &)> open =
      fltkHost().filesDropped;
    if(open && name) open({std::string(name)});
  }

  bool _about(const std::vector<Ui::MenuItem> &items)
  {
    for(const auto &it : items) {
      if(it.kind == Ui::MenuItem::Submenu && _about(it.children)) return true;
      if(it.label.find("About") == 0 && it.action) {
        it.action();
        return true;
      }
    }
    return false;
  }

  void _aboutPressed(Fl_Widget *, void *)
  {
    if(fltkSources().menuBar) _about(fltkSources().menuBar());
  }
#endif

  void _build(int argc, char **argv)
  {
    const Ui::Backend::Settings set = fltkSources().settings();
    FL_NORMAL_SIZE = _fontSize();
    if(set.theme.size()) Fl::scheme(set.theme.c_str());
    Fl_Tooltip::size(FL_NORMAL_SIZE);
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 4)
    Fl::use_high_res_GL(set.highResolution ? 1 : 0);
#elif(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
    Fl::use_high_res_GL(set.highResolution ? 1 : 0);
#endif
    Fl_Tooltip::enable(set.tooltips);

    _w = new mainWindow;
    bool detached = set.detachedTree;
    int mh = _menuHeight();
    int sh = _statusHeight();
    int sw = FL_NORMAL_SIZE + 2;
    // the console is there from the start, at nothing: see showConsole()
    int mheight = 2 * BH;
    int sceneHeight = set.sceneHeight > 0 ? set.sceneHeight : 600;
    int glheight = sceneHeight - mheight;
    if(glheight <= 0) {
      sceneHeight = 600;
      glheight = sceneHeight - mheight;
    }
    int height = mh + glheight + mheight + sh;
    if(height > Fl::h()) {
      height = Fl::h();
      glheight = height - mh - mheight - sh;
      sceneHeight = glheight + mheight;
    }
    int twidth = detached ? 0 : 14 * sw;
    int sceneWidth = set.sceneWidth > 0 ? set.sceneWidth : 600;
    int glwidth = sceneWidth - twidth;
    if(glwidth <= 0) {
      sceneWidth = 600;
      glwidth = sceneWidth - twidth;
    }
    int width = glwidth + twidth;
    if(width > Fl::w()) {
      width = Fl::w();
      glwidth = width - twidth;
    }

    _w->win = new topWindow(width, height, false);
    _w->win->callback(_quit);
    topWindow::resized = _fullscreenResized;
#if defined(__APPLE__)
    if(set.systemMenuBar) {
      _w->sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
      _w->sysbar->menu(fltkMenuBar(true));
      _w->sysbar->global();
    }
    else
#endif
    {
      _w->bar = new menuBarFltk(0, 0, width, BH);
      _w->bar->menu(fltkMenuBar(false));
      _w->bar->global();
    }

    // as wide as the buttons of the bar at least
    _w->minWidth = (int)(10 + 11 * sw + 1.75 * FL_NORMAL_SIZE);
    _w->minHeight = 100;
    _w->win->size_range(_w->minWidth, _w->minHeight);
    // a box that does not eat the events of what is under it
    dummyBox *resbox = new dummyBox(_w->minWidth, mh, width - _w->minWidth,
                                    glheight);
    _w->win->resizable(resbox);

    // the tree, the scene and the console, which share the borders
    _w->tile = new Fl_Tile(0, mh, width, glheight + mheight);
    _w->scene = fltkSceneBox(twidth, mh, glwidth, glheight);
    _w->messages = new console(twidth, mh + glheight, glwidth, mheight);
    _consoleFont(set.consoleFontSize);
    _w->messages->callback(_copySelectedLines, nullptr);
    _w->messages->search_callback(_filterConsole, nullptr);
    _w->messages->autoscroll_callback(
      [](Fl_Widget *, void *) {
        _w->said.setAutoScroll(_w->messages->autoScrolling());
      },
      nullptr);
    _w->messages->save_callback(
      [](Fl_Widget *, void *) {
        if(fltkSources().saveMessages) fltkSources().saveMessages();
      },
      nullptr);
    _w->messages->clear_callback(
      [](Fl_Widget *, void *) {
        _w->said.clear();
        _w->messages->clear();
      },
      nullptr);
    if(!detached) {
      _w->tree = new treeFltk(0, mh, twidth, height - mh - sh);
      _w->tree->enableTreeWidgetResize(false);
    }
    _w->tile->callback(_tileMoved);
    _w->tile->end();
    // the console at nothing, the tree at the width asked for, at least what
    // it needs to be built right -- and that said, since it is shown again at
    // the width the settings say
    _w->tile->position(0, mh + glheight, 0, mh + sceneHeight);
    int treeWidth = set.treeWidth;
    int minw = 3 * BB / 2 + 4 * WB;
    if(treeWidth < minw) {
      treeWidth = minw;
      Ui::Backend::Layout l;
      l.treeWidth = treeWidth;
      _forgetting(l);
    }
    _w->tile->position(twidth, 0, treeWidth, 0);

    _w->status = fltkMakeBar(0, mh + glheight + mheight, width, sh);
    if(set.sceneX > 0 || set.sceneY > 0) _w->win->position(set.sceneX, set.sceneY);
    _w->win->end();

    if(detached) {
      _w->treeWin = new topWindow(set.treeWidth > minw ? set.treeWidth : minw,
                                  set.treeHeight > 0 ? set.treeHeight : 600,
                                  set.nonModalWindows, "Gmsh");
      _w->treeWin->callback(_treeClosed);
      _w->treeWin->box(GMSH_WINDOW_BOX);
      _w->tree = new treeFltk(0, 0, _w->treeWin->w(), _w->treeWin->h());
      _w->tree->enableTreeWidgetResize(true);
      if(set.treeX > 0 || set.treeY > 0)
        _w->treeWin->position(set.treeX, set.treeY);
      _w->treeWin->resizable(_w->tree);
      _w->treeWin->size_range(_w->tree->minWindowWidth(),
                              _w->tree->minWindowHeight());
      _w->treeWin->end();
    }

    if(argc > 0 && argv && argv[0])
      ((Fl_Window *)_w->win)->show(1, argv);
    else
      _w->win->show();
    if(_w->treeWin) _w->treeWin->show();
    // the colours again, now that the display is open: the selection colour
    // and the boxes come right
    _applyColorScheme(false);
    // the keys go to the scene first: the arrows step the animation
    fltkSceneFocus();
  }

  // --- the backend

  class backendFltk : public Ui::Backend {
  public:
    std::string name() override
    {
      char tmp[256];
      snprintf(tmp, sizeof(tmp), "FLTK %d.%d.%d", FL_MAJOR_VERSION,
               FL_MINOR_VERSION, FL_PATCH_VERSION);
      return std::string(tmp);
    }

    void setSources(const Sources &sources) override { _sources = sources; }
    const Sources &sources() const { return _sources; }
    void setHost(const Host &host) override { _host = host; }
    const Host &host() const { return _host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(_w) return true;
      _thread = std::this_thread::get_id();
      Fl::error = _error;
      Fl::fatal = _fatal;
#if defined(__APPLE__)
      // the defaults use %@, which leads to (lowercase) gmsh
      Fl_Mac_App_Menu::about = "About Gmsh";
      Fl_Mac_App_Menu::hide = "Hide Gmsh";
      Fl_Mac_App_Menu::quit = "Quit Gmsh";
      Fl_Mac_App_Menu::print = ""; // this sometimes crashes
#endif
      // the X11 class, which window rules key on; matches the StartupWMClass
      // of utils/freedesktop/info.gmsh.gmsh.desktop
      Fl_Window::default_xclass("Gmsh");
      // the mesher may be in threads of its own
      Fl::lock();
      const Settings set = _sources.settings();
      if(set.display.size()) Fl::display(set.display.c_str());
      Fl::set_boxtype(GMSH_SIMPLE_RIGHT_BOX, simple_right_box_draw, 0, 0, 1, 0);
      Fl::set_boxtype(GMSH_SIMPLE_TOP_BOX, simple_top_box_draw, 0, 1, 0, 1);
      // before the widgets are made, so that no colour flashes
      _applyColorScheme(false);
      Fl::add_handler(_globalShortcut);
      fltkFontEngine();
      fl_register_images();
      _addGlyphSymbols();
      // the icons of the file chooser
      Fl_File_Icon::load_system_icons();
      static Fl_RGB_Image icon(&gmsh_icon_pixmap);
      Fl_Window::default_icon(&icon);
#if defined(__APPLE__)
      fl_open_callback(_openFromFinder);
      fl_mac_set_about(_aboutPressed, nullptr);
#endif
      // the questions do not follow the mouse
      fl_message_hotspot(0);
      // the scene is told who holds it before the first window is made
      fltkSceneStart();
      _build(argc, argv);
      return true;
    }

    void destroy() override
    {
      if(!_w) return;
      // hiding a form is now the interface going away
      fltkFormsClosingDown();
      std::vector<Fl_Window *> wins;
      for(Fl_Window *win = Fl::first_window(); win; win = Fl::next_window(win))
        wins.push_back(win);
      for(Fl_Window *win : wins) win->hide();
      Fl::check();
      fltkSceneStop();
      mainWindow *w = _w;
      _w = nullptr;
      delete w->treeWin;
      Fl::delete_widget(w->win);
      delete w;
      _bars.clear();
      Fl::check();
    }

    int runLoop() override { return Fl::run(); }

    void check(bool rateLimited) override { fltkCheck(rateLimited); }
    bool ready() override { return Fl::ready() ? true : false; }

    void wait(double seconds, bool force) override
    {
      if((!_onThread() || _locked > 0) && !force) return;
      if(seconds < 0.)
        Fl::wait();
      else
        Fl::wait(seconds);
    }

    void lock() override
    {
      _locked++;
      Fl::lock();
    }
    void unlock() override
    {
      _locked--;
      Fl::unlock();
    }
    int locked() override { return _locked; }

    void postFromThread(const std::function<void()> &what) override
    {
      // Fl::awake() carries a pointer: the work is held here until the loop
      // asks
      {
        std::lock_guard<std::mutex> lock(_mutex);
        _posted.push_back(what);
      }
      Fl::awake(_drain, this);
    }

    void post(const std::function<void()> &what) override { what(); }

    void copyText(const std::string &text) override
    {
      Fl::copy(text.c_str(), (int)text.size(), 0);
      Fl::copy(text.c_str(), (int)text.size(), 1);
    }

    void beep() override { fl_beep(); }

    // --- messages, the bar, and the questions that stop everything

    void addMessage(const std::string &text, int level) override
    {
      _addLine(text, level);
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      lines.clear();
      if(_w) lines = _w->said.texts();
    }

    void refreshBar() override { fltkRefreshBar(); }

    // --- what the options that shape the main window push into it

    void setSceneSize(int width, int height) override
    {
      if(!_w) return;
      int sw = 0, sh = 0;
      fltkSceneSize(sw, sh);
      int ww = _w->win->w(), wh = _w->win->h();
      if(width >= 0) ww = std::max(_w->minWidth, ww + width - sw);
      if(height >= 0) wh = std::max(_w->minHeight, wh + height - sh);
      if(ww != _w->win->w() || wh != _w->win->h()) _w->win->size(ww, wh);
    }

    void setConsoleFontSize(int size) override { _consoleFont(size); }
    void setTreeWidth(int width) override { _setTreeWidth(width); }

    void detachTree(bool detached) override
    {
      if(detached)
        _detachTree();
      else
        _attachTree();
    }

    void enableTooltips(bool on) override
    {
      if(on)
        Fl_Tooltip::enable();
      else
        Fl_Tooltip::disable();
    }

    int numWindows() override { return _w ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(_w && which == 0) _w->win->copy_label(title.c_str());
    }

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      if(readOnly) {
        _showText(question.c_str(), value);
        return false;
      }
      // the little editor that says the shape of the answer
      if(hint.size()) return _editText(question.c_str(), hint.c_str(), value);
      const char *ret = fl_input("%s", value.c_str(), question.c_str());
      if(!ret) return false;
      value = ret;
      return true;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      return fl_choice("%s", zero.c_str(), one.c_str(),
                       two.empty() ? nullptr : two.c_str(), question.c_str());
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      // the filters, one per line, and which was in force when the name was
      // given
      std::string filter;
      for(const auto &f : formats) {
        if(f.name.size()) filter += f.name + "\t";
        filter += f.pattern + "\n";
      }
      int how = mode == OpenSeveral ? _multi : mode == Create ? _create :
                                                                 _single;
      std::string from = names.empty() ? "" : names[0];
      int picked = _fileChooser(how, title.c_str(), filter.c_str(), from.c_str());
      if(!picked) return false;
      names.clear();
      for(int i = 1; i <= picked; i++) names.push_back(_chosenName(i));
      if(chosenFormat) *chosenFormat = _chosenFilter();
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      _dark = dark;
      _applyColorScheme(true);
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    {
      fltkShowForm(form, show);
    }
    bool formVisible(const Ui::Form &form) override
    {
      return fltkFormVisible(form);
    }
    std::string formPane(const Ui::Form &form) override
    {
      return fltkFormPane(form);
    }
    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      fltkSetFormPane(form, pane);
    }
    void reloadForm(const Ui::Form &form) override { fltkReloadForm(form); }
    void rebuildForm(const Ui::Form &form) override { fltkReloadForm(form); }
    void dropForm(const Ui::Form &form) override { fltkDropForm(form); }
    void optionChanged(const std::string &name) override
    {
      fltkFormOptionChanged(name);
    }

    void showConsole(bool show) override
    {
      if(show)
        _showConsole();
      else
        _hideConsole();
      fltkCheck();
    }

    bool consoleVisible() override
    {
      return _consoleHeight() >= FL_NORMAL_SIZE;
    }

    void refreshTree(bool rebuild) override
    {
      if(_w && _w->tree) _w->tree->rebuild(rebuild);
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(_w && _w->tree) _w->tree->open(name, open);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return _w && _w->tree && _w->tree->isOpen(name);
    }

    void showTree() override
    {
      if(!_w || !_w->tree) return;
      if(_w->treeWin)
        _w->treeWin->show();
      else
        _showTree();
    }

    void refreshMenus() override
    {
      if(!_w) return;
#if defined(__APPLE__)
      if(_w->sysbar) {
        _w->sysbar->menu(fltkMenuBar(true));
        return;
      }
#endif
      if(_w->bar) _w->bar->menu(fltkMenuBar(false));
    }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &key) override
    {
      fltkPopupMenu(items, Fl::event_x_root(), Fl::event_y_root(), key);
    }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      l.sceneX = _w->win->x();
      l.sceneY = _w->win->y();
      fltkSceneSize(l.sceneWidth, l.sceneHeight);
      // a hidden console said what it measured when it was hidden
      if(_consoleHeight()) l.consoleHeight = _consoleHeight();
      l.treeWidth = _treeWidth();
      l.treeDetached = _w->treeWin ? 1 : 0;
      if(_w->treeWin) {
        l.treeX = _w->treeWin->x();
        l.treeY = _w->treeWin->y();
        l.treeHeight = _w->treeWin->h();
      }
      fltkFormPosition(l.dialogX, l.dialogY);
#if defined(HAVE_3M)
      storeWindowPosition3M();
#endif
      _chooserPosition(&l.chooserX, &l.chooserY);
      return l;
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      if(_w && _w->tree && !fltkLocked()) _w->tree->rebuildFooter();
    }

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      if(what == "new")
        fltkSceneNewWindow();
      else if(what == "minimize") {
        _w->win->iconize();
        fltkSceneWindows(false);
      }
      else if(what == "zoom")
        _zoom();
      else if(what == "fullscreen")
        _fullscreen(!_w->fullscreen);
      else if(what == "front") {
        // the order is important!
        _w->win->show();
        fltkSceneWindows(true);
        fltkFormsToFront();
      }
      else if(what == "show_hide_tree") {
        if(_treeWidth() < FL_NORMAL_SIZE)
          _showTree();
        else
          _hideTree();
        fltkCheck();
      }
      else if(what == "attach_detach") {
        if(_w->treeWin)
          _attachTree();
        else
          _detachTree();
        fltkCheck();
      }
#if defined(HAVE_3M)
      else if(what == "3m")
        window3M_cb(nullptr, nullptr);
#endif
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    bool supports(const std::string &what) override
    {
#if !defined(WIN32) && FL_API_VERSION < 10400
      if(what == "copy") return false;
#endif
#if !defined(HAVE_3M)
      if(what == "3m") return false;
#endif
      return true;
    }

    bool fullscreen() const { return _w && _w->fullscreen; }
    void leaveFullscreen() { _fullscreen(false); }

  private:
    Sources _sources;
    Host _host;
    std::mutex _mutex;
    std::vector<std::function<void()> > _posted;

    static void _drain(void *data)
    {
      backendFltk *self = (backendFltk *)data;
      std::vector<std::function<void()> > work;
      {
        std::lock_guard<std::mutex> lock(self->_mutex);
        work.swap(self->_posted);
      }
      for(auto &w : work) w();
    }
  };

  backendFltk *_the = nullptr;

} // namespace

// --- what the files of the interface share

const Ui::Backend::Sources &fltkSources()
{
  // before the interface was given anything, the settings are their defaults
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

const Ui::Backend::Host &fltkHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

void fltkLater(const std::function<void()> &what)
{
  std::function<void()> *kept = new std::function<void()>(what);
  Fl::add_timeout(
    0.,
    [](void *data) {
      std::function<void()> *fn = (std::function<void()> *)data;
      (*fn)();
      delete fn;
    },
    kept);
}

bool fltkButtonDown() { return Fl::pushed() != nullptr; }

bool fltkLocked() { return _locked > 0; }

void fltkCheck(bool rateLimited)
{
  if(!_onThread() || _locked > 0) return;
  static double last = -1e10;
  double rate = fltkSources().settings().refreshRate;
  double now = std::chrono::duration<double>(
                 std::chrono::steady_clock::now().time_since_epoch())
                 .count();
  if(rateLimited && rate > 0. && now - last < 1. / rate) return;
  last = now;
  Fl::check();
}

// as Ui::Shortcut says it; 0 for a key no shortcut could name
bool fltkUiKey(int &key, unsigned &mods)
{
  int k = Fl::event_key();
  key = 0;
  if(k >= 'a' && k <= 'z')
    key = toupper(k);
  else if(k >= FL_F + 1 && k <= FL_F + 12)
    key = Ui::KeyF1 + k - FL_F - 1;
  else {
    switch(k) {
    case FL_Left: key = Ui::KeyLeft; break;
    case FL_Right: key = Ui::KeyRight; break;
    case FL_Up: key = Ui::KeyUp; break;
    case FL_Down: key = Ui::KeyDown; break;
    case FL_Escape: key = Ui::KeyEscape; break;
    case FL_Home: key = Ui::KeyHome; break;
    case FL_Page_Up: key = Ui::KeyPageUp; break;
    case FL_Page_Down: key = Ui::KeyPageDown; break;
    case FL_Delete: key = Ui::KeyDelete; break;
    default:
      if(k > ' ' && k < 127) key = k;
      break;
    }
  }
  // FL_COMMAND is what Ui::ModCommand means
  mods = 0;
  if(Fl::event_state(FL_COMMAND)) mods |= Ui::ModCommand;
  if(Fl::event_state(FL_SHIFT)) mods |= Ui::ModShift;
  if(Fl::event_state(FL_ALT)) mods |= Ui::ModAlt;
  const char *text = Fl::event_text();
  if(text && text[0] > ' ' && text[0] < 127 && !text[1] && !isalpha(text[0])) {
    key = text[0];
    mods &= ~Ui::ModShift;
  }
  return key != 0;
}

bool fltkMainKey()
{
  if(Fl::event_key() == FL_Escape && _the && _the->fullscreen()) {
    _the->leaveFullscreen();
    return true;
  }
  int key = 0;
  unsigned mods = 0;
  if(!fltkUiKey(key, mods) || !fltkSources().keys) return false;
  bool taken = false;
  for(const Ui::KeyBinding &k : fltkSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    if(k.action) k.action();
    taken = true;
    if(k.spent) break;
  }
  return taken;
}

int paletteWindow::handle(int event)
{
  switch(event) {
  case FL_SHORTCUT:
  case FL_KEYBOARD:
#if defined(__APPLE__)
    if(Fl::test_shortcut(FL_META + 'w') || Fl::test_shortcut(FL_Escape)) {
#elif defined(WIN32)
    if(Fl::test_shortcut(FL_ALT + FL_F + 4) || Fl::test_shortcut(FL_Escape)) {
#else
    if(Fl::test_shortcut(FL_CTRL + 'w') || Fl::test_shortcut(FL_Escape)) {
#endif
      do_callback();
      return 1;
    }
    break;
  }
  return Fl_Double_Window::handle(event);
}

void paletteWindow::show()
{
  if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
  Fl_Double_Window::show();
}

// --- the bar: the buttons, then the message with the progress of what runs

Fl_Group *fltkMakeBar(int x, int y, int w, int h)
{
  const Ui::Backend::Settings set = fltkSources().settings();
  Fl_Group *bar = new Fl_Group(x, y, w, h);
  bar->box(GMSH_SIMPLE_TOP_BOX);
  int sw = FL_NORMAL_SIZE + 2;
  int at = x + 2;
  int sht = h - 4; // leave a 2 pixel border at the bottom
  std::vector<Ui::BarButton> wanted = fltkSources().barButtons ?
                                        fltkSources().barButtons() :
                                        std::vector<Ui::BarButton>();
  for(const auto &b : wanted) {
    if(b.gapBefore) at += 4;
    int bw = b.widthEm > 0. ? (int)(b.widthEm * FL_NORMAL_SIZE) : sw;
    statusButtonFltk *button = new statusButtonFltk(at, y + 2, bw, sht);
    button->what = b;
    button->copy_label(button->shown().c_str());
    button->copy_tooltip(b.tooltip.c_str());
    if(b.action) {
      // Shift and Control are read when it is pressed
      button->callback(
        [](Fl_Widget *w, void *) {
          statusButtonFltk *b = (statusButtonFltk *)w;
          if(b->what.action)
            b->what.action(Fl::event_state(FL_SHIFT) ? true : false,
                           Fl::event_state(FL_CTRL) || Fl::event_state(FL_META));
          fltkRefreshBar();
        },
        nullptr);
    }
    button->box(FL_FLAT_BOX);
    button->selection_color(FL_WHITE);
    button->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    at += bw;
  }
  at += 4;
  progressFltk *label = new progressFltk(at, y + 2, x + w - at - 2, sht);
  label->box(FL_FLAT_BOX);
  label->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  if(set.darkScheme)
    label->color(FL_BACKGROUND_COLOR, FL_LIGHT3);
  else
    label->color(FL_BACKGROUND_COLOR, FL_DARK2);
  bar->resizable(label);
  bar->end();
  _bars.push_back(bar);
  return bar;
}

void fltkDropBar(Fl_Group *bar)
{
  _bars.erase(std::remove(_bars.begin(), _bars.end(), bar), _bars.end());
}

void fltkRefreshBar()
{
  for(Fl_Group *bar : _bars)
    for(int i = 0; i < bar->children(); i++) {
      Fl_Widget *c = bar->child(i);
      if(statusButtonFltk *b = dynamic_cast<statusButtonFltk *>(c)) {
        if(b->refresh()) b->redraw();
      }
      else
        c->redraw();
    }
}

int fltkBarHeight() { return _statusHeight(); }

Fl_Window *fltkMainWindow() { return _w ? _w->win : nullptr; }

// made once
namespace {
  struct offeringFltk {
    offeringFltk()
    {
      Ui::offer("fltk", []() -> Ui::Backend * {
        if(!_the) _the = new backendFltk();
        return _the;
      });
    }
  };
  offeringFltk _offeringFltk;
} // namespace

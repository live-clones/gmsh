// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PALETTE_WINDOWH
#define PALETTE_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "windowPlacement.h"
#include "widthRules.h"

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Esc & Cmd-w on Mac, Alt+F4 on Windows)
class paletteWindow : public Fl_Double_Window {
private:
  // position relative to the main graphic window, applied when shown
  int *_offset;
  // the widgets that follow the width of the window, laid out at _width
  widthRules _rules;
  int _width;
  void (*_resized)(void *);
  void *_resizedData;
  // the least and greatest sizes, kept here as FLTK 1.3 cannot give them back
  int _minW, _minH, _maxW, _maxH;

public:
  paletteWindow(int w, int h, bool nonModal, const char *l = nullptr,
                int *offset = nullptr)
    : Fl_Double_Window(w, h, l), _offset(offset), _width(w), _resized(nullptr),
      _resizedData(nullptr), _minW(0), _minH(0), _maxW(0), _maxH(0)
  {
    if(nonModal) set_non_modal();
  }
  ~paletteWindow() { forgetWindow(this); }
  // the widgets as placed now follow a wider window (see widthRules.h)
  void followWidth(int mid, int right)
  {
    _rules = widthRules();
    _rules.record(this, mid, right);
    _width = w();
  }
  // size_range() that remembers the sizes (0: no greatest size)
  void sizeRange(int minw, int minh, int maxw = 0, int maxh = 0)
  {
    _minW = minw;
    _minH = minh;
    _maxW = maxw;
    _maxH = maxh;
    size_range(minw, minh, maxw, maxh);
  }
  int leastWidth() const { return _minW; }
  int leastHeight() const { return _minH; }
  bool fixedHeight() const { return _maxH && _maxH == _minH; }
  // sets the least height, and makes the window that tall if it is not: true
  // if it was resized
  bool leastHeight(int h)
  {
    if(h != _minH) sizeRange(_minW, h, _maxW, _maxH);
    if(this->h() >= h) return false;
    size(w(), h);
    return true;
  }
  // called once the window has been resized
  void whenResized(void (*cb)(void *), void *data)
  {
    _resized = cb;
    _resizedData = data;
  }
  virtual void resize(int x, int y, int w, int h)
  {
    bool sized = (w != this->w() || h != this->h());
    Fl_Double_Window::resize(x, y, w, h);
    if(!sized) return; // only moved
    if(!_rules.empty()) {
      _rules.apply(w - _width);
      init_sizes();
    }
    if(_resized) _resized(_resizedData);
  }
  virtual int handle(int event)
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
  virtual void show()
  {
    if(_offset) placeWindow(this, _offset);
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
  }
};

#endif

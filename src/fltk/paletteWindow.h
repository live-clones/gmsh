// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PALETTE_WINDOWH
#define PALETTE_WINDOWH

#include <algorithm>
#include <string>
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
  // a tool window, docked in the main window while it has a dock, unless it
  // was dragged out of the dock: then it stays on the desktop until dragged
  // back (see General.FloatingTools, which names it)
  bool _dockable, _floating;
  std::string _name;
  // the button down on the background of a floating tool, where a drag takes
  // it to the dock
  bool _pushed;
  int _pushX, _pushY;
  // the border (FLTK removes those of subwindows), size and non-modal state
  // (floating above other windows on macOS) the window had on the desktop
  // before it was docked
  bool _desktopBorder, _desktopNonModal;
  int _desktopW, _desktopH;
  // called when the dock shows the window again
  void (*_revealed)(void *);
  void *_revealedData;

public:
  // set by the main window while it has a dock: docks a window and shows it
  inline static void (*dockHook)(paletteWindow *w) = nullptr;
  // called when a docked window is hidden, or resized
  inline static void (*hiddenHook)(paletteWindow *w) = nullptr;
  inline static void (*resizedHook)(paletteWindow *w) = nullptr;
  // called when a floating tool window is moved on the desktop
  inline static void (*movedHook)(paletteWindow *w) = nullptr;
  // called when a floating tool window is dragged to the dock by a tab or
  // its background: an FLTK drag and drop, the one drag the application can
  // follow under Wayland, which hides where the windows are
  inline static void (*dragHook)(paletteWindow *w) = nullptr;
  // the tool window being so dragged, until it is dropped: the main window
  // takes the drop over the dock (see graphicWindow::toolDrop())
  inline static paletteWindow *dragged = nullptr;
  // the events of that drag reaching a subwindow of the main window are handed
  // to it, in its coordinates; -1 when the event is not one of them
  static int dragEventUp(Fl_Window *sub, int event)
  {
    if(!dragged || !sub->parent()) return -1;
    switch(event) {
    case FL_DND_ENTER:
    case FL_DND_DRAG:
    case FL_DND_LEAVE:
    case FL_DND_RELEASE: break;
    default: return -1;
    }
    int x = Fl::e_x, y = Fl::e_y;
    Fl::e_x += sub->x();
    Fl::e_y += sub->y();
    int r = sub->window()->handle(event);
    Fl::e_x = x;
    Fl::e_y = y;
    return r;
  }
  paletteWindow(int w, int h, bool nonModal, const char *l = nullptr,
                int *offset = nullptr)
    : Fl_Double_Window(w, h, l), _offset(offset), _width(w), _resized(nullptr),
      _resizedData(nullptr), _minW(0), _minH(0), _maxW(0), _maxH(0),
      _dockable(false), _floating(false), _pushed(false), _desktopBorder(true),
      _desktopNonModal(false), _desktopW(w), _desktopH(h), _revealed(nullptr),
      _revealedData(nullptr)
  {
    if(nonModal) set_non_modal();
  }
  void dockable(bool d) { _dockable = d; }
  bool dockable() const { return _dockable; }
  void floating(bool f) { _floating = f; }
  bool floating() const { return _floating; }
  void dragToDock()
  {
    if(!parent() && _dockable && dragHook) dragHook(this);
  }
  // on the desktop, or in the dock (where a folded or covered window is not
  // shown)
  bool isOpen()
  { return parent() || shown(); } // shown() is not const in FLTK 1.4
  void name(const std::string &n) { _name = n; }
  const std::string &name() const { return _name; }
  // docked, shown where placed: Cocoa centers a non-modal window otherwise
  void keepPosition() { force_position(1); }
  // the window leaves the desktop for the dock, its offset kept as it was, and
  // comes back
  void leaveDesktop()
  {
    _desktopBorder = border();
    _desktopNonModal = non_modal();
    clear_flag(NON_MODAL);
    _desktopW = w();
    _desktopH = h();
    if(_offset) storeWindowOffset(this, _offset);
    forgetWindow(this);
  }
  // the size on the desktop, also while docked
  int desktopW() const { return parent() ? _desktopW : w(); }
  int desktopH() const { return parent() ? _desktopH : h(); }
  // docked, the window is shown again (its tab chosen, unfolded): a tool
  // refreshes there what it skips while hidden
  void whenRevealed(void (*cb)(void *), void *data)
  {
    _revealed = cb;
    _revealedData = data;
  }
  void revealed()
  {
    if(_revealed) _revealed(_revealedData);
  }
  void backToDesktop()
  {
    border(_desktopBorder);
    if(_desktopNonModal) set_non_modal();
    size(std::max(_desktopW, _minW),
         fixedHeight() ? _minH : std::max(_desktopH, _minH));
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
  // a window of fixed height built w x h, whose widgets follow a wider width
  // up to the right margin, margin pixels before the edge
  void fixedLayout(int w, int h, int margin)
  {
    followWidth(w / 2, w - margin);
    sizeRange(w, h, 0, h);
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
    if(!sized) { // only moved
      if(!parent() && _dockable && _floating && movedHook) movedHook(this);
      return;
    }
    if(!_rules.empty()) {
      _rules.apply(w - _width);
      init_sizes();
    }
    if(_resized) _resized(_resizedData);
    if(parent() && resizedHook) resizedHook(this);
  }
  virtual int handle(int event)
  {
    int up = dragEventUp(this, event);
    if(up >= 0) return up;
    switch(event) {
    case FL_PUSH:
      dragged = nullptr; // a drag that ended elsewhere, which Wayland hides
      if(Fl_Double_Window::handle(event)) return 1;
      if(Fl::event_button() != FL_LEFT_MOUSE || parent() || !_dockable)
        return 0;
      _pushed = true;
      _pushX = Fl::event_x();
      _pushY = Fl::event_y();
      return 1;
    case FL_DRAG:
      if(!_pushed) break;
      if(abs(Fl::event_x() - _pushX) > 4 || abs(Fl::event_y() - _pushY) > 4) {
        _pushed = false;
        dragToDock();
      }
      return 1;
    case FL_RELEASE:
      if(!_pushed) break;
      _pushed = false;
      return 1;
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      // docked, only when the focus is inside: the main window has its own
      if(parent() && !contains(Fl::focus())) break;
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
    if(_dockable && !_floating && dockHook) {
      dockHook(this);
      return;
    }
    if(parent()) { // docked
      Fl_Double_Window::show();
      return;
    }
    if(_offset) placeWindow(this, _offset);
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
    titleBarColor(this);
    watchMoves(this);
  }
  virtual void hide()
  {
    // FLTK also hides the subwindows of a window it hides: not a close
    if(parent() && hiddenHook && top_window()->shown())
      hiddenHook(this);
    else
      Fl_Double_Window::hide();
  }
};

#endif

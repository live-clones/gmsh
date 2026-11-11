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
#include "gmshScheme.h"
#include "sceneTool.h"

class paletteWindow;

// The main window that docks the tool windows (see graphicWindow::
// setDocking()), as the tool windows, the main window and the dock reach it:
// through paletteWindow::host, null while the main window does not dock its
// tools
class dockHost {
public:
  virtual ~dockHost() {}
  // whether a tool window shown is docked (not while the dock lets its tools
  // go)
  virtual bool takesTools() const = 0;
  // docks a window and shows it
  virtual void dockTool(paletteWindow *w) = 0;
  // a docked window hidden, or resized
  virtual void toolHidden(paletteWindow *w) = 0;
  virtual void toolResized(paletteWindow *w) = 0;
  // a floating tool window moved on the desktop, or dragged to the dock by a
  // tab or its background: an FLTK drag and drop, the one drag the
  // application can follow under Wayland, which hides where the windows are
  virtual void toolMoved(paletteWindow *w) = 0;
  virtual void dragToDock(paletteWindow *w) = 0;
  // the events of that drag over the main window, and its drop
  virtual int toolDrop(int event) = 0;
  // a window torn out of the dock, to be shown on the desktop under the
  // pointer (root coordinates)
  virtual void toolTornOut(paletteWindow *w, int x, int y) = 0;
  // closes the tool shown in the dock if w is the main window, or returns
  // false (Cmd-W)
  virtual bool closeTool(Fl_Window *w) = 0;
};

// The windows of the FLTK graphical user interface, main and tool windows:
// placed on the desktop
// at their offset from the main graphic window (see windowPlacement.h), with
// the title bar and the widgets in the style of the theme
class gmshWindow : public Fl_Double_Window {
protected:
  // position relative to the main graphic window, applied when shown
  int *_offset;
  void _showOnDesktop()
  {
    if(_offset) placeWindow(this, _offset);
    if(non_modal() && !shown()) Fl_Double_Window::show(); // fix ordering
    Fl_Double_Window::show();
    titleBarColor(this);
  }
  // the key that closes a window: Cmd-W on macOS, Alt+F4 on Windows, Ctrl-W
  // otherwise
  static bool _closeKey()
  {
#if defined(__APPLE__)
    return Fl::test_shortcut(FL_META + 'w');
#elif defined(WIN32)
    return Fl::test_shortcut(FL_ALT + FL_F + 4);
#else
    return Fl::test_shortcut(FL_CTRL + 'w');
#endif
  }

public:
  gmshWindow(int w, int h, bool nonModal, const char *l, int *offset)
    : Fl_Double_Window(w, h, l), _offset(offset)
  {
    if(nonModal) set_non_modal();
  }
  ~gmshWindow() { forgetWindow(this); }
  virtual void draw()
  {
    gmshStyleWidgets(this);
    Fl_Double_Window::draw();
  }
};

// The tool windows: on the desktop or in the dock of the main window (see
// dockHost), with the sizes their rules allow, and the shortcuts that close
// them (Escape, and the key that closes a window)
class paletteWindow : public gmshWindow {
private:
  // the selection this window is for being ended by its closing (see hide())
  bool _endingTool = false;
  // the widgets that follow the width of the window, laid out at _width
  widthRules _rules;
  int _width;
  void (*_resized)(void *);
  void *_resizedData;
  // the least and greatest sizes, kept here for the const accessors below
  // (Fl_Window::get_size_range() is not const in FLTK 1.4)
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
  // the main window while it has a dock
  inline static dockHost *host = nullptr;
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
    : gmshWindow(w, h, nonModal, l, offset), _width(w), _resized(nullptr),
      _resizedData(nullptr), _minW(0), _minH(0), _maxW(0), _maxH(0),
      _dockable(false), _floating(false), _pushed(false), _desktopBorder(true),
      _desktopNonModal(false), _desktopW(w), _desktopH(h), _revealed(nullptr),
      _revealedData(nullptr)
  {
  }
  void dockable(bool d) { _dockable = d; }
  bool dockable() const { return _dockable; }
  void floating(bool f) { _floating = f; }
  bool floating() const { return _floating; }
  void dragToDock()
  {
    if(!parent() && _dockable && host) host->dragToDock(this);
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
      if(!parent() && _dockable && _floating && host) host->toolMoved(this);
      return;
    }
    if(!_rules.empty()) {
      _rules.apply(w - _width);
      init_sizes();
    }
    if(_resized) _resized(_resizedData);
    if(parent() && host) host->toolResized(this);
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
      // Escape stops the selection this window is for first, as in the
      // graphic window (a second one closes it, unless the end of the
      // selection did); the close key closes it, which ends the selection
      if(Fl::test_shortcut(FL_Escape) && sceneTool::owner() == ownerId()) {
        sceneTool::stop();
        return 1;
      }
      if(_closeKey() || Fl::test_shortcut(FL_Escape)) {
        do_callback();
        return 1;
      }
      break;
    }
    return Fl_Double_Window::handle(event);
  }
  virtual void show()
  {
    if(_dockable && !_floating && host && host->takesTools()) {
      host->dockTool(this);
      return;
    }
    if(parent()) { // docked
      Fl_Double_Window::show();
      return;
    }
    _showOnDesktop();
    watchMoves(this);
  }
  // what a tool started for this window gives as its owner (see sceneTool)
  const void *ownerId() const { return (const Fl_Window *)this; }
  virtual void hide()
  {
    // (hidden below, once: the end of the selection may hide it too)
    if(_endingTool) return;
    // FLTK also hides the subwindows of a window it hides: not a close
    bool docked = parent() && host && top_window()->shown();
    // closed (by any means): the selection it is for ends
    if((docked || !parent()) && sceneTool::owner() == ownerId()) {
      _endingTool = true;
      sceneTool::stop();
      _endingTool = false;
    }
    if(docked)
      host->toolHidden(this);
    else
      Fl_Double_Window::hide();
  }
};

#endif

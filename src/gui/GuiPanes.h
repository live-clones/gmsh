// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_PANES_H
#define GMSH_GUI_PANES_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <functional>
#include <string>
#include <vector>

#include "sceneView.h"

// The views of the 3D scene for an interface that gives each of them an
// OpenGL surface of its own -- a GtkGLArea, a QOpenGLWidget, a WGL child
// window, an NSOpenGLView: which view is current, the tiling kept apart from
// the windows of their own, what is selected and captured, the animation and
// the gamepad, the whole of GuiSceneOps and Scene::Host. The interface makes
// and places the surfaces, and says what they are through a Toolkit; it
// hands the events of a surface to the Pane that sits on it.

class GuiPanes {
public:
  // one view on one surface; an interface keeps its surface in a subclass
  struct Pane {
    // the modifiers held, before the event they go with
    void modifiers(bool shift, bool ctrl, bool alt, bool super = false);
    sceneView *view = nullptr;
    // a graphic window of its own, not tiled in the main one
    bool window = false;
    Pane();
    virtual ~Pane();
    // --- the pointer on the surface, in its logical pixels; each call
    // hands the view one event
    void moved(double x, double y);
    // button 0 left, 1 right, 2 middle; the double click is told apart by
    // the interval the toolkit uses, in seconds
    void pressed(int button, double x, double y, double doubleClick);
    void released(int button, double x, double y);
    void wheel(double dy, double x, double y);
    void left();

  private:
    friend class GuiPanes;
    paneInput _input;
    double _lastX = 0., _lastY = 0., _lastPress = 0.;
    bool _moved = false;
    void _at(double x, double y);
    void _handle();
  };

  // what the interface does with its surfaces
  struct Toolkit {
    // a surface for a view, after `from` (null for the first one)
    std::function<Pane *(Pane *from)> makePane;
    // a draw asked for, when the toolkit next draws
    std::function<void(Pane *)> redraw;
    // the context of the surface current and its framebuffer bound; false
    // while it has none yet
    std::function<bool(Pane *)> prepare;
    // the size of the surface in logical pixels, and the framebuffer pixels
    // of a logical one
    std::function<void(Pane *, int &width, int &height, double &factor)> size;
    // drawn and shown now, not when the toolkit next draws (the progress of
    // a mesher): prepare(), draw(), and what shows the picture
    std::function<void(Pane *)> drawNow;
    // the surface of `fresh` beside that of `was`, across ('h') or down
    // ('v'), `was` getting the ratio of the room
    std::function<void(Pane *was, Pane *fresh, char how, double ratio)> split;
    // all the tiled surfaces but `keep` gone, `keep` filling the room
    std::function<void(Pane *keep, const std::vector<Pane *> &gone)> unsplit;
    // the surface of `fresh` in a window of its own
    std::function<void(Pane *fresh)> newWindow;
    // the hand over the surfaces, or the arrow
    std::function<void(bool picking)> cursor;
    // a picture to the clipboard: rows from the bottom, 4 bytes a pixel
    std::function<void(int width, int height,
                       const std::vector<unsigned char> &rgba)>
      clipboard;
    // as Scene::Host has them
    std::function<void(double seconds, std::function<void()> what)> later;
    std::function<bool()> buttonDown;
    std::function<void *()> context;
    std::function<void(int &height, float &scale)> screen;
  };

  static GuiPanes &instance();
  // the scene operations offered under that name (Gui::offerScene), by an
  // interface at start-up, before Gui picks the one it runs with
  static void offer(const char *name);
  // installs the Scene::Host, offers the scene operations and makes the
  // first view; the one after the toolkit's makePane(nullptr)
  Pane *start(const Toolkit &toolkit);
  // the views gone, the surfaces being the toolkit's to delete
  void stop();

  const std::vector<Pane *> &panes() const { return _panes; }
  Pane *current() const { return _current; }
  void setCurrent(Pane *p) { _current = p; }
  Pane *paneOf(sceneView *view) const;
  // the surface is going: its view goes with it
  void dropped(Pane *p);
  void redrawAll();
  bool drawing() const { return _drawing; }

  // what the toolkit calls when it draws a surface, its context current:
  // the view, or the picture being captured in the bottom-left corner
  void draw(Pane *p);
  // the view where its surface is, for picking outside a draw
  void place(Pane *p);
  // the state the scene leaves set, put back as a toolkit composing the
  // surface in the same context expects it
  static void putBackState();

  void split(char how, double ratio);
  void newWindow();
  // the timers of the animation and of the gamepad, started when wanted
  void startTimers();

private:
  Toolkit _tk;
  std::vector<Pane *> _panes;
  Pane *_current = nullptr;
  int _captureW = 0, _captureH = 0;
  bool _drawing = false, _animating = false;
  bool _animationArmed = false, _gamepadArmed = false;
  std::vector<GVertex *> _vertices;
  std::vector<GEdge *> _edges;
  std::vector<GFace *> _faces;
  std::vector<GRegion *> _regions;
  std::vector<MElement *> _elements;
  std::vector<SPoint2> _points;
  std::vector<PView *> _views;
  Pane *_make(Pane *from);
  void _setHost();
  void _clearSelected();
  void _pixelSize(Pane *p, int &width, int &height);
  friend struct GuiPanesOps;
};

#endif

#endif

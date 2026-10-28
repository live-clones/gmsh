// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H

#include <string>
#include <vector>
#include "drawContext.h"

class GEntity;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// One mouse event, as the host of a view reads it from its toolkit: the
// pointer in pixels of the view from its top left corner, the size of the
// view in the same pixels, the modifier keys, and what happened.
struct paneInput {
  enum Kind { Move, Push, Release, Drag, Wheel };
  Kind kind;
  double x, y;
  int w, h;
  // the button pushed, released or held during the drag: 0 left, 1 right,
  // 2 middle
  int button;
  // the push is the second of a double click, and the view takes one (see
  // sceneView::acceptsDoubleClick())
  bool doubleClick;
  // the notches the wheel turned, positive towards the user
  double wheel;
  bool shift, ctrl, alt, meta;
  paneInput()
    : kind(Move), x(0.), y(0.), w(1), h(1), button(0), doubleClick(false),
      wheel(0.), shift(false), ctrl(false), alt(false), meta(false)
  {
  }
};

// The interaction with the scene of a drawContext, the same whatever shows
// it: rotation, zoom and pan by the mouse, the lasso, the selection of
// entities by clicks, the point being placed when an entity is created, what
// the cursor is over and the stepping through what is stacked under it.
// Whoever shows the view (an Fl_Gl_Window, the canvas of a web page) derives
// from this class, fills a paneInput from the events of its toolkit and
// gives them to handleMouse(); what the interaction needs of it in return
// (a redraw, a cursor, ...) goes through the virtual host* functions, which
// do nothing unless the host overrides them.
class sceneView {
private:
  // what the last event was measured against, and the size of the view then
  mousePosition _prev;
  int _w, _h;
  // the selection waited for (ENT_NONE: a click), and what a click asked to
  // be looked at at the next step: 1 select, -1 unselect, 2 and -2 inside
  // the lasso, in the rectangle (centre, size)
  int _selection, _trySelection, _trySelectionXYWH[4];
  // whether the last click asked to add a query to those on the picture
  // (Ctrl+click in query mode) rather than to replace them
  bool _addQuery;
  // what the cursor is over, in a box by it or in the status bar
  void _hover();
  // and drawn as selected while it is: the entity, what its selection was
  // before, and the change of one for the other (which redraws)
  GEntity *_highlighted;
  char _highlightedWas;
  void _highlight(GEntity *e);
  // step through what is under the cursor, once per press or notch: see
  // _stepPick() for the several ways one of them arrives twice
  double _pickStepTime;
  bool _stepping;
  // where the cursor was when it last stepped: a trackpad nudges the pointer
  // while two fingers are dragged over it, and a pixel of that must not
  // throw away the place in the stack
  double _stepAnchor[2];
  void _stepPick(int direction, bool rateLimited);
  // whether something stands behind what the cursor is over, which costs a
  // picking pass: asked once per entity, the information that names it
  std::string _hoverBehindFor;
  bool _hoverBehind;
  bool _probeBehind();
  // how fast the model is spun (see the drag in handleMouse()): the speed,
  // smoothed, the path drawn since it was last measured and when that was,
  // and how long it has stayed fast
  double _spin, _spinFrom, _spinPath, _spinHot;
  // a picking pass, between hostBeginGL() and hostEndGL()
  bool _select(int type, bool multiple, bool mesh, bool post, int x, int y,
               int w, int h, std::vector<GVertex *> &vertices,
               std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
               std::vector<GRegion *> &regions,
               std::vector<MElement *> &elements, std::vector<SPoint2> &points,
               std::vector<PView *> &views);
  // should a double click be processed?
  bool _processDoubleClick(std::size_t num, const std::string &what);
  void _doubleClick(const paneInput &in);
  void _lassoZoom();

protected:
  // the context whose scene this is: the host's, which draws it
  drawContext *_ctx;
  // where the last click was, and where the pointer is: the lasso rectangle
  // goes from one to the other
  mousePosition _click, _curr;
  // the point being placed in addPointMode
  double _point[3];
  // What the cursor is over, written in a box in the picture rather than in
  // a window of its own, which some window managers showed and hid with a
  // flicker on every move: the text, where the cursor was when it was last
  // placed (window coordinates, from the top left), and where the box was
  // last drawn (left, bottom, width, height, in the pixel coordinates of
  // draw2d, from the bottom left)
  std::string _hoverText;
  double _hoverAnchor[2], _hoverBox[4];
  // what the queries found, each in a box hanging from the point it asked
  // about, kept until a click replaces them all, under what the cursor is
  // over
  struct pinnedNote {
    std::string text;
    double xyz[3];
  };
  std::vector<pinnedNote> _pinned;
  // a model spun hard enough catches fire: how much is alight and when that
  // was last drawn (the host draws the flames)
  double _fire, _fireTime;

  // what the interaction asks of the host
  // the picture changed
  virtual void hostRedraw() {}
  // a button was pushed in this view: it is the current one from now on
  virtual void hostClicked() {}
  // the view moved (rotation, translation, scale): whatever shows the
  // numbers follows
  virtual void hostViewChanged() {}
  // a cross where a click would pick something, the default cursor elsewhere
  virtual void hostCursor(bool cross) {}
  // make the context current for a picking pass; false if a frame is being
  // drawn (the pass would mix with it), in which case nothing is picked
  virtual bool hostBeginGL() { return true; }
  virtual void hostEndGL() {}
  // the tools that take over the clicks: see queryMode() and measureMode()
  virtual bool hostQueryMode() { return false; }
  virtual bool hostMeasureMode() { return false; }
  // the point being placed: which of its coordinates the dialog holds fixed,
  // and where the pointer moved it (mode: see addPointMode)
  virtual bool hostFrozenCoordinate(int coord) { return false; }
  virtual void hostPointMoved(const double p[3], int mode) {}
  // the ONELAB parameters of the entities: whether there are any, and show
  // those of one entity
  virtual bool hostHasOnelabContext() { return false; }
  virtual void hostShowOnelabContext(int dim, int tag) {}
  // a double click on nothing: the quick access menu
  virtual void hostQuickAccess() {}

public:
  // the entity being created follows the pointer: 0 none, 1 a point (see
  // elementaryContextWindow::updatePoint() for the other values)
  int addPointMode;
  // a lasso is being drawn; a selection waits for clicks
  bool lassoMode, selectionMode;
  // what the keys ask of the selection, read at its next step
  int endSelection, undoSelection, invertSelection, quitSelection,
    changeSelection;
  // the two lines of Msg::StatusGl(), drawn at the top of the picture
  std::string screenMessage[2];

  sceneView(drawContext *ctx);
  virtual ~sceneView() {}
  drawContext *getDrawContext() { return _ctx; }
  void setDrawContext(drawContext *ctx) { _ctx = ctx; }

  // a mouse event; the host counts clicks and reports a double click only
  // when acceptsDoubleClick() says the view takes one
  void handleMouse(const paneInput &in);
  bool acceptsDoubleClick() const;
  // the pointer left the view
  void pointerLeft();
  // step through what is stacked under the cursor (Alt+Up/Down)
  void stepPick(int direction) { _stepPick(direction, false); }

  // A selection: begin it, then call selectionStep() each time the host has
  // waited for events. It returns 0 while there is nothing to report, and
  // otherwise 'l' (selected), 'r' (unselected), 'c' (a click, when the type
  // is ENT_NONE), 'e' (ended), 'u' (undo), 'i' (invert) or 'q' (quit), the
  // entities in the vectors; the selection goes on after 'e', 'u' and 'i'.
  void beginSelection(int type);
  char selectionStep(std::vector<GVertex *> &vertices,
                     std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
                     std::vector<GRegion *> &regions,
                     std::vector<MElement *> &elements,
                     std::vector<SPoint2> &points, std::vector<PView *> &views);
  // run one picking pass at the given position (window coordinates) and
  // return what a click there would select, without waiting for a click
  bool pick(int type, bool mesh, bool post, int x, int y, int w, int h,
            std::vector<GVertex *> &vertices, std::vector<GEdge *> &edges,
            std::vector<GFace *> &faces, std::vector<GRegion *> &regions,
            std::vector<MElement *> &elements, std::vector<SPoint2> &points,
            std::vector<PView *> &views)
  {
    // the kept image was drawn around the pointer, not around this position
    _ctx->invalidatePickCache();
    return _select(type, false, mesh, post, x, y, w, h, vertices, edges, faces,
                   regions, elements, points, views);
  }
  // where the last selection looked, in the units of the window
  void lastSelection(int xywh[4])
  {
    for(int i = 0; i < 4; i++) xywh[i] = _trySelectionXYWH[i];
  }
  // show the text in a box by the cursor, or take the box away
  void drawTooltip(const std::string &text);
  // the same box, pinned to the point xyz of the model: it replaces the
  // boxes pinned before, or is added to them; an empty text removes them all
  void pinTooltip(const std::string &text, const double *xyz = nullptr,
                  bool add = false);
  bool addQuery() const { return _addQuery; }
  void setPoint(double x, double y, double z)
  {
    _point[0] = x;
    _point[1] = y;
    _point[2] = z;
  }
};

#endif

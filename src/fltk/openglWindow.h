// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <vector>
#include <string>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>
#include "drawContext.h"

class GEntity;
#include "Navigator.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

// the FLTK visual the graphic windows ask for; changing it recreates the
// OpenGL context
int openglWindowMode();

class openglWindow : public Fl_Gl_Window {
private:
  static openglWindow *_lastHandled;
  static void _setLastHandled(openglWindow *);
  bool _lock;
  bool _drawn;
  mousePosition _click, _curr, _prev;
  drawContext *_ctx;
  double _point[3];
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
  void _drawScreenMessage();
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
  // whether something stands behind what the cursor is over, which costs a
  // picking pass: asked once per entity, the information that names it
  std::string _hoverBehindFor;
  bool _hoverBehind = false;
  bool _probeBehind();
  void _drawBorder();
  // The accumulation of the studio frames: whether the timer asked for the
  // next draw, whether this draw is one of them, the modelview of this
  // frame, and the modelview and window size the last one was drawn with.
  // Whether a draw is the timer's is not read from the damage bits, which
  // FLTK sets all of before calling draw() on Windows (the UNDEFINED swap
  // type of Fl_Gl_Window::flush(); macOS and X11 keep them): the timer sets
  // the flag, and any other request for a redraw clears it.
  bool _studioAsked, _studioTimer;
  double _frameView[16], _studioModel[16];
  int _studioW, _studioH;
  bool _again = false;
  // the studio frames the last draw of a print accumulated, all of them or 0
  int _studioPrinted = 0;
  // the size (pixels) of the picture being drawn instead of the window, or
  // 0, and its pixels per unit of the drawing (the window's, times the
  // supersampling)
  int _printW, _printH;
  double _printScale;
  // the camera's projection (shifted for the studio frame) and modelview
  void _cameraMatrices();
  void _studioFrame();
  static void _studioSampleCb(void *data);
  // a model spun hard enough catches fire: the speed of the drag, smoothed,
  // the path drawn since it was last measured and when that was, and how
  // long it has stayed fast; how much is alight and when that was last drawn
  double _spin, _spinFrom, _spinPath, _spinHot, _fire, _fireTime;
  // sameFrame: the other eye of a stereo pair, drawn at the level the first
  // of them left
  void _burn(bool sameFrame = false);
  static void _fireCb(void *data);
  bool _select(int type, bool multiple, bool mesh, bool post, int x, int y,
               int w, int h, std::vector<GVertex *> &vertices,
               std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
               std::vector<GRegion *> &regions,
               std::vector<MElement *> &elements, std::vector<SPoint2> &points,
               std::vector<PView *> &views);
  // should a double click be processed?
  bool _processDoubleClick(std::size_t num, const std::string &what);
protected:
  void draw();
  int handle(int);

public:
  int pixel_w();
  int pixel_h();
  // a redraw asked for by anyone but the studio timer draws a plain frame
  void redraw()
  {
    _studioAsked = false;
    Fl_Gl_Window::redraw();
  }
  time_t rawtime, prev_rawtime;
  double response_frequency;
  int addPointMode;
  bool lassoMode, selectionMode;
  int endSelection, undoSelection, invertSelection, quitSelection,
    changeSelection;
  std::string screenMessage[2];
  openglWindow(int x, int y, int w, int h);
  ~openglWindow();
  void show();
  drawContext *getDrawContext() { return _ctx; }
  // draw into a picture of the given size (pixels) instead of the window,
  // at supersampling times the scale of the window; false if it cannot be
  // done
  bool printTo(int width, int height, int supersampling, unsigned int format,
               unsigned int type, void *pixels);
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
  char selectEntity(int type, std::vector<GVertex *> &vertices,
                    std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
                    std::vector<GRegion *> &regions,
                    std::vector<MElement *> &elements,
                    std::vector<SPoint2> &points, std::vector<PView *> &views);
  static openglWindow *getLastHandled() { return _lastHandled; }
  // the next draw is the same picture as the last one (see
  // PixelBuffer::fill): the studio frames that one accumulated are put back
  // rather than drawn again
  void setAgain(bool again) { _again = again; }
  static void setLastHandled(openglWindow *w) { _lastHandled = w; }
  // show the text in a box by the cursor, or take the box away
  // where the last selection looked, in the units of the window
  void lastSelection(int xywh[4])
  {
    for(int i = 0; i < 4; i++) xywh[i] = _trySelectionXYWH[i];
  }
  void drawTooltip(const std::string &text);
  // the same box, pinned to the point xyz of the model: it replaces the
  // boxes pinned before, or is added to them; an empty text removes them all
  void pinTooltip(const std::string &text, const double *xyz = nullptr,
                  bool add = false);
  bool addQuery() const { return _addQuery; }
  double frequency;
  void moveWithGamepad();
  Navigator *Nautilus;
  void setPoint(double x, double y, double z)
  {
    _point[0] = x;
    _point[1] = y;
    _point[2] = z;
  }
};

#endif

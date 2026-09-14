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

#define NEW_TOOLTIPS 1

#if defined(NEW_TOOLTIPS)

// no <FL/fl_draw.H> here: it brings in the platform headers of FLTK
// (<FL/win32.H> on Windows), which src/common/gmsh.cpp cannot take after
// all it includes before this header
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Tooltip.H>

class tooltipWindow : public Fl_Menu_Window {
private:
  char _text[1024];
  // the window this floats over, which the keys are for
  Fl_Widget *_owner;

public:
  tooltipWindow(Fl_Widget *owner = nullptr) : Fl_Menu_Window(1, 1), _owner(owner)
  {
    _text[0] = '\0';
    set_override();
    set_tooltip_window();
    end();
  }
  void draw();
  int handle(int e)
  {
    if(e == FL_PUSH) {
      hide();
      return 1;
    }
    // A key makes the tooltip go away, but it is not for this window, which
    // only floats over the graphics: it is handed to the window under it
    // rather than left to the toolkit, which sends keys to whatever has the
    // focus and gives one to a tooltip as it is shown. Claiming it, as this
    // did, swallowed every other press of a key that shows a tooltip - the
    // steps through the entities under the cursor, say.
    if(e == FL_KEYDOWN || e == FL_SHORTCUT) {
      hide();
      return _owner ? _owner->handle(e) : 0;
    }
    return Fl_Menu_Window::handle(e);
  }
  void value(const std::string &s);
};

#endif

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
  // what the cursor is over, in the tooltip or the status bar
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
  void _drawBorder();
  // the accumulation of the studio frames: whether this draw is one of them
  // (asked for by the timer), the modelview of this frame, and the modelview
  // and window size the last one was drawn with
  bool _studioTimer;
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
#if defined(NEW_TOOLTIPS)
  tooltipWindow *_tooltip;
#endif

protected:
  void draw();
  int handle(int);

public:
  int pixel_w();
  int pixel_h();
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
  void drawTooltip(const std::string &text);
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

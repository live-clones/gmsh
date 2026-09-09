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
#include "Navigator.h"

#define NEW_TOOLTIPS 1

#if defined(NEW_TOOLTIPS)

#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_draw.H>

class tooltipWindow : public Fl_Menu_Window {
private:
  char _text[1024];

public:
  tooltipWindow() : Fl_Menu_Window(1, 1)
  {
    strcpy(_text, "");
    set_override();
    set_tooltip_window();
    end();
  }
  void draw()
  {
    draw_box(FL_BORDER_BOX, 0, 0, w(), h(), Fl_Tooltip::color());
    fl_color(Fl_Tooltip::textcolor());
    fl_font(Fl_Tooltip::font(), Fl_Tooltip::size());
    int X = Fl_Tooltip::margin_width();
    int Y = Fl_Tooltip::margin_height();
    int W = w() - (Fl_Tooltip::margin_width() * 2);
    int H = h() - (Fl_Tooltip::margin_height() * 2);
    fl_draw(_text, X, Y, W, H, Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_WRAP), 0, 1);
  }
  int handle(int e)
  {
    if(e == FL_PUSH || e == FL_KEYDOWN) {
      hide();
      return 1;
    }
    return Fl_Menu_Window::handle(e);
  }
  void value(const std::string &s)
  {
    strncpy(_text, s.c_str(), 1023);
    _text[1023] = '\0';
    fl_font(Fl_Tooltip::font(), Fl_Tooltip::size());
    int ww = Fl_Tooltip::wrap_width();
    int hh = 0;
    fl_measure(_text, ww, hh, 1);
    ww += (Fl_Tooltip::margin_width() * 2);
    hh += (Fl_Tooltip::margin_height() * 2);
    size(ww, hh);
    redraw();
  }
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
  void _drawScreenMessage();
  void _drawBorder();
  // the accumulation of the studio frames: whether this draw is one of them
  // (asked for by the timer), the modelview of this frame, and the modelview
  // and window size the last one was drawn with
  bool _studioTimer;
  double _frameView[16], _studioModel[16];
  int _studioW, _studioH;
  // the size (pixels) of the picture being drawn instead of the window, or
  // 0, and its pixels per unit of the drawing (the window's, times the
  // supersampling)
  int _printW, _printH;
  double _printScale;
  // the camera's projection (shifted for the studio frame) and modelview
  void _cameraMatrices();
  void _studioFrame();
  static void _studioSampleCb(void *data);
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
  // with the shader pipeline, at supersampling times the scale of the
  // window; false if it cannot be done
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

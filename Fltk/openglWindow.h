// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <vector>
#include <string>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>
#include "drawContext.h"
#include "Navigator.h"

#if defined(NEW_TOOLTIPS)

#include <FL/Fl_Menu_Window.H>
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
    draw_box(FL_BORDER_BOX, 0, 0, w(), h(), Fl_Color(175));
    fl_color(FL_BLACK);
    fl_font(labelfont(), labelsize());
    fl_draw(_text, 3, 3, w() - 6, h() - 6,
            Fl_Align(FL_ALIGN_LEFT | FL_ALIGN_WRAP));
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
    // recalc size of window
    fl_font(labelfont(), labelsize());
    int W = w(), H = h();
    fl_measure(_text, W, H, 0);
    W += 8;
    size(W, H);
    redraw();
  }
};

#endif

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

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
  double _lassoXY[2];
  void _drawScreenMessage();
  void _drawBorder();
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

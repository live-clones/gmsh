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
#include "sceneView.h"
#include "Navigator.h"

// the FLTK visual the graphic windows ask for; changing it recreates the
// OpenGL context
int openglWindowMode();
// give the graphic windows that visual
void resetOpenglMode();

// An Fl_Gl_Window showing a scene: it draws the frames (the studio
// accumulation, the prints, the fire), and hands the events of FLTK to the
// interaction it inherits from sceneView, whose host it is.
class openglWindow : public Fl_Gl_Window, public sceneView {
private:
  static openglWindow *_lastHandled;
  static void _setLastHandled(openglWindow *);
  // some drawing routines can create data (STL triangulations, etc.), which
  // can fire draw() while we are already drawing, e.g. due to an impromptu
  // Fl::check(); the same lock keeps the picking passes out of the frames
  bool _lock;
  bool _drawn;
  void _drawScreenMessage();
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
  // the fire lit by spinning the model (see sceneView), drawn over the scene;
  // sameFrame: the other eye of a stereo pair, drawn at the level the first
  // of them left
  void _burn(bool sameFrame = false);
  static void _fireCb(void *data);

protected:
  void draw();
  int handle(int);
  // what the interaction asks of its window
  void hostRedraw();
  void hostClicked();
  void hostViewChanged();
  void hostCursor(bool cross);
  bool hostBeginGL();
  void hostEndGL();
  bool hostQueryMode();
  bool hostMeasureMode();
  bool hostFrozenCoordinate(int coord);
  void hostPointMoved(const double p[3], int mode);
  bool hostHasOnelabContext();
  void hostShowOnelabContext(int dim, int tag);
  void hostQuickAccess();

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
  openglWindow(int x, int y, int w, int h);
  ~openglWindow();
  void show();
  // draw into a picture of the given size (pixels) instead of the window,
  // at supersampling times the scale of the window; false if it cannot be
  // done
  bool printTo(int width, int height, int supersampling, unsigned int format,
               unsigned int type, void *pixels);
  // wait for a selection (see sceneView::selectionStep() for what is
  // returned)
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
  double frequency;
  void moveWithGamepad();
  Navigator *Nautilus;
};

#endif

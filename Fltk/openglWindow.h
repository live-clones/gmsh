// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

#include <vector>
#include <string>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>
#include "drawContext.h"
#include "Navigator.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class openglWindow : public Fl_Gl_Window {
 private:
  static openglWindow *_lastHandled;
  static void _setLastHandled(openglWindow*);
  bool _lock;
  bool _drawn;
  mousePosition _click, _curr, _prev;
  drawContext *_ctx;
  double _point[3];
  int _selection, _trySelection, _trySelectionXYWH[4];
  double _lassoXY[2];
  void _drawScreenMessage();
  void _drawBorder();
  bool _select(int type, bool multiple, bool mesh, bool post, int x, int y, int w, int h,
               std::vector<GVertex*> &vertices, std::vector<GEdge*> &edges,
               std::vector<GFace*> &faces, std::vector<GRegion*> &regions,
               std::vector<MElement*> &elements, std::vector<SPoint2> &points,
               std::vector<PView*> &views);
 protected:
  void draw();
  int handle(int);
 public:
  int pixel_w();
  int pixel_h();
  time_t rawtime,  prev_rawtime;
  double response_frequency;
  bool addPointMode, lassoMode, selectionMode;
  int endSelection, undoSelection, invertSelection, quitSelection;
  std::string screenMessage[2];
  openglWindow(int x, int y, int w, int h);
  ~openglWindow();
  drawContext *getDrawContext(){ return _ctx; }
  char selectEntity(int type,
                    std::vector<GVertex*> &vertices, std::vector<GEdge*> &edges,
                    std::vector<GFace*> &faces, std::vector<GRegion*> &regions,
                    std::vector<MElement*> &elements, std::vector<SPoint2> &points,
                    std::vector<PView*> &views);
  static openglWindow *getLastHandled(){ return _lastHandled; }
  static void setLastHandled(openglWindow *w){ _lastHandled = w; }
  void drawTooltip(const std::string &text);
  double frequency;
  void moveWithGamepad();
  Navigator *Nautilus;
};

#endif

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

#include <vector>
#include <string>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>
#include "drawContext.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;

class mousePosition {
 public:
  double win[3]; // window coordinates
  double wnr[3]; // world coordinates BEFORE rotation
  double s[3]; // scaling state when the event was recorded
  double t[3]; // translation state when the event was recorded
  mousePosition()
  {
    for(int i = 0; i < 3; i++)
      win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  mousePosition(const mousePosition &instance)
  {
    for(int i = 0; i < 3; i++){
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set(drawContext *ctx);
  void recenter(drawContext *ctx);
};

class openglWindow : public Fl_Gl_Window {
 private:
  static openglWindow *_lastHandled;
  mousePosition _click, _curr, _prev;
  drawContext *_ctx;
  double _point[3];
  int _selection, _trySelection, _trySelectionXYWH[4];
  double _lassoXY[2];
  void drawScreenMessage();
  void drawBorder();
  bool processSelectionBuffer(int type, 
                              bool multipleSelection, bool meshSelection,
                              int x, int y, int w, int h,
                              std::vector<GVertex*> &vertices,
                              std::vector<GEdge*> &edges,
                              std::vector<GFace*> &faces,
                              std::vector<GRegion*> &regions,
                              std::vector<MElement*> &elements);
  void draw();
  int handle(int);
 public:
  bool addPointMode, lassoMode, selectionMode;
  int endSelection, undoSelection, invertSelection, quitSelection;
  std::string screenMessage[2];
  openglWindow(int x, int y, int w, int h, const char *l=0);
  ~openglWindow();
  drawContext *getDrawContext(){ return _ctx; }
  char selectEntity(int type, 
                    std::vector<GVertex*> &vertices, std::vector<GEdge*> &edges,
                    std::vector<GFace*> &faces, std::vector<GRegion*> &regions,
                    std::vector<MElement*> &elements);
  static openglWindow *getLastHandled(){ return _lastHandled; }
  static void setLastHandled(openglWindow *w){ _lastHandled = w; }
};

#endif

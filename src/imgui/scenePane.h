// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_PANE_H
#define SCENE_PANE_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include <vector>
#include "drawContext.h"

class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// One 3D view of the model: the Dear ImGui counterpart of openglWindow.
//
// A pane owns a rectangle of a platform window, into which the scene is
// rendered with glViewport()/glScissor(). There are two kinds. The panes that
// tile the central node of the dock space are drawn straight into the main
// framebuffer, before the Dear ImGui draw lists are submitted: Dear ImGui
// leaves that node transparent, so the scene shows through. The panes of the
// extra graphic windows that "Window > New Window" creates live inside a Dear
// ImGui window of their own, which may end up in another platform window, so
// they are drawn from a draw callback instead -- that is the only way to have
// custom OpenGL run in the right framebuffer.

// What the pointer and the modifier keys are doing, as one frame of the pane
// sees it. The panes of the main window get it from Dear ImGui; the extra
// graphic windows are plain GLFW windows with no Dear ImGui in them, and fill
// it in from the GLFW callbacks. The buttons are numbered as Dear ImGui numbers
// them: 0 left, 1 right, 2 middle.
struct paneInput {
  // pointer position, in the same space as the pane rectangle plus its origin
  double x, y;
  // how much it moved since the last frame
  double dx, dy;
  double wheel;
  bool shift, ctrl, alt, super;
  bool clicked[3], released[3], dragging[3];
  bool doubleClicked;
  paneInput()
    : x(0.), y(0.), dx(0.), dy(0.), wheel(0.), shift(false), ctrl(false),
      alt(false), super(false), doubleClicked(false)
  {
    for(int i = 0; i < 3; i++) clicked[i] = released[i] = dragging[i] = false;
  }
};

class scenePane {
private:
  drawContext *_ctx;
  // rectangle in logical (not framebuffer) pixels, top-left origin, relative to
  // the main window
  int _x, _y, _w, _h;
  mousePosition _click, _curr, _prev;
  bool _lassoMode;
  double _lassoXY[2];
  // pending selection request, handled at the next draw: 1 = select,
  // -1 = unselect, 2 = select inside the lasso rectangle
  int _trySelection;
  int _trySelectionXYWH[4];
  // entity type the blocking selection is currently waiting for
  int _selection;
  // the point being placed while addPointMode is on
  double _point[3];
  // see setOrigin()
  double _originX, _originY, _pixelFactor;
  int _windowHeight;

  void _drawScreenMessage();
  void _drawBorder();
  void _drawLasso();
  void _lassoZoom();
  void _handleDoubleClick(double lx, double ly);
  // say what is under the pointer, and offer to click it
  void _hover();
  bool _select(int type, bool multiple, bool mesh, bool post, int x, int y,
               int w, int h, std::vector<GVertex *> &vertices,
               std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
               std::vector<GRegion *> &regions,
               std::vector<MElement *> &elements,
               std::vector<SPoint2> &points, std::vector<PView *> &views);

public:
  // While this is on, the pointer places the entity being created instead of
  // highlighting what it hovers: see geometryAddPointBasedEntity().
  bool addPointMode;

  bool selectionMode;
  int endSelection, undoSelection, invertSelection, quitSelection;
  int changeSelection;
  std::string screenMessage[2];

public:
  scenePane();
  ~scenePane();

  drawContext *getDrawContext() { return _ctx; }

  // where the point being placed with the mouse currently is
  void setPoint(double x, double y, double z)
  {
    _point[0] = x;
    _point[1] = y;
    _point[2] = z;
  }

  // geometry of the pane, in logical pixels, relative to the platform window it
  // is drawn in
  void setRect(int x, int y, int w, int h);
  // Where that platform window is, in the screen space Dear ImGui reports the
  // mouse in, and how tall it is. They are the same as the main window for a
  // tiled pane; an extra graphic window dragged onto another monitor has its
  // own.
  void setOrigin(double x, double y, int height, double pixelFactor);
  int x() const { return _x; }
  int y() const { return _y; }
  int w() const { return _w; }
  int h() const { return _h; }
  // px and py are in Dear ImGui screen space, as io.MousePos is
  bool contains(double px, double py) const
  {
    double lx = px - _originX, ly = py - _originY;
    return lx >= _x && lx < _x + _w && ly >= _y && ly < _y + _h;
  }

  // render the scene into the pane; pixelFactor is the ratio between
  // framebuffer pixels and logical pixels, windowHeight the height of the whole
  // window in logical pixels (needed to flip the y axis for OpenGL)
  void draw(double pixelFactor, int windowHeight);

  // process the mouse events that fall inside the pane
  void handleMouse(const paneInput &in);

  // blocking entity selection, as FlGui::selectEntity(); returns 'q', 'l', 'r',
  // 'u' or 'e'
  char selectEntity(int type, std::vector<GVertex *> &vertices,
                    std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
                    std::vector<GRegion *> &regions,
                    std::vector<MElement *> &elements,
                    std::vector<SPoint2> &points, std::vector<PView *> &views);
};

#endif

#endif

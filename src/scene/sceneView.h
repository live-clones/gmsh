// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

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

// One 3D view of the model, owning a rectangle of a platform window into
// which the scene is rendered with glViewport()/glScissor().

// the pointer and the modifier keys as one frame sees them; the buttons are
// numbered 0 left, 1 right, 2 middle
struct paneInput {
  double x, y;
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

class sceneView;

namespace Scene {
  // what is as viewSetOrientation() knows it; sync makes the views after the
  // first follow it; which views are meant is the holder's to say
  void orientViews(const std::vector<sceneView *> &views,
                   const std::string &what, bool reverse, bool sync);
  // the fixed function pipeline, for what an interface draws itself: a pick
  // made since the last frame leaves the shader program bound
  void plainPipeline();
} // namespace Scene

class sceneView {
private:
  static std::vector<sceneView *> _all;
  drawContext *_ctx;
  // in logical pixels, top-left origin, relative to the window
  int _x, _y, _w, _h;
  mousePosition _click, _curr, _prev;
  bool _lassoMode;
  double _lassoXY[2];
  // handled at the next draw: 1 select, -1 unselect, 2 inside the lasso
  int _trySelection;
  int _trySelectionXYWH[4];
  // whether the last click asked to add a query to those on the picture
  // (Ctrl+click in query mode) rather than to replace them
  bool _addQuery;
  int _selection;
  double _point[3];
  double _originX, _originY, _pixelFactor;
  int _windowHeight;
  bool _drawn;
  // drawn over the frame rather than in it, so that the studio frames stay
  // good; named by model, dimension and tag, as it may be gone by the next
  // frame
  GEntity *_highlighted;
  GModel *_highlightModel;
  int _highlightDim, _highlightTag;
  bool _highlightAsked;
  void _highlight(GEntity *e);
  // what is drawn over the frame changed, not the frame
  void _overlayChanged();
  GEntity *_highlightEntity();
  void _drawHighlight();
  // stepping through what is stacked under the pointer
  double _pickStepTime;
  bool _stepping;
  double _stepAnchor[2];
  void _stepPick(int direction, bool rateLimited);
  // whether the timer asked for the frame being drawn, and the view and size
  // the frames so far were drawn for
  bool _studioAsked, _studioTimer, _accumulating;
  int _studioArmed;
  double _frameView[16], _studioModel[16];
  int _studioX, _studioY, _studioW, _studioH;
  int _studioPrinted;
  bool _again;
  int _printW, _printH;
  double _printScale;
  void _cameraMatrices();
  void _drawPointBeingPlaced();
  void _studioFrame(bool highlightOnly);
  void _studioSample();
  void _armStudio(double seconds);
  // the fire lit by spinning the model
  double _spin, _spinFrom, _spinPath, _spinHot, _fire, _fireTime;
  void _burn(bool sameFrame = false);
  bool _buttonHeld;

  // What the cursor is over, written in a box in the picture: the text, where
  // the cursor was when it was last placed (window coordinates, from the top
  // left), and where the box was last drawn (left, bottom, width, height, in
  // the pixel coordinates of draw2d, from the bottom left)
  std::string _hoverText;
  double _hoverAnchor[2], _hoverBox[4];
  // what the queries found, each in a box hanging from the point it asked
  // about, kept until a click replaces them all
  struct pinnedNote {
    std::string text;
    double xyz[3];
  };
  std::vector<pinnedNote> _pinned;
  // whether something stands behind what the cursor is over, which costs a
  // picking pass: asked once per entity, the information that names it
  std::string _hoverBehindFor;
  bool _hoverBehind;
  bool _probeBehind();
  // should a double click run what the entity asks for?
  bool _processDoubleClick(std::size_t num, const std::string &what);
  // the messages of a selection and what the cursor is over, in boxes over
  // the picture, and neither in a print
  void _drawScreenMessage();
  void _drawBorder();
  void _drawLasso();
  void _lassoZoom();
  void _handleDoubleClick(double lx, double ly);
  void _hover();
  bool _select(int type, bool multiple, bool mesh, bool post, int x, int y,
               int w, int h, std::vector<GVertex *> &vertices,
               std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
               std::vector<GRegion *> &regions,
               std::vector<MElement *> &elements,
               std::vector<SPoint2> &points, std::vector<PView *> &views);

public:
  // the key that aborts a picking asks every view
  bool lasso() const { return _lassoMode; }
  void endLasso() { _lassoMode = false; }

  // the pointer places the entity being created instead of highlighting: see
  // geometryAddPointBasedEntity()
  bool addPointMode;

  bool selectionMode;
  int endSelection, undoSelection, invertSelection, quitSelection;
  int changeSelection;
  std::string screenMessage[2];

public:
  sceneView();
  ~sceneView();
  // every view there is, whoever holds it
  static const std::vector<sceneView *> &all() { return _all; }

  drawContext *getDrawContext() { return _ctx; }

  // what flies the camera has nothing to move until a picture has been drawn
  bool everDrawn() const { return _drawn; }
  // the frame drawn last was a studio frame with more to come: a host showing
  // pictures need not send it
  bool accumulating() const { return _accumulating; }

  void setPoint(double x, double y, double z)
  {
    _point[0] = x;
    _point[1] = y;
    _point[2] = z;
  }

  void setRect(int x, int y, int w, int h);
  // where the platform window is in the screen space the mouse is reported in,
  // and how tall it is
  void setOrigin(double x, double y, int height, double pixelFactor);
  int x() const { return _x; }
  int y() const { return _y; }
  int w() const { return _w; }
  int h() const { return _h; }
  bool contains(double px, double py) const
  {
    double lx = px - _originX, ly = py - _originY;
    return lx >= _x && lx < _x + _w && ly >= _y && ly < _y + _h;
  }

  // pixelFactor: framebuffer pixels per logical pixel; windowHeight in logical
  // pixels, to flip the y axis
  void draw(double pixelFactor, int windowHeight);
  // what was kept for the previous context belongs to it
  void contextChanged();
  // a frame anyone asked for starts the studio accumulation over
  void redrawAsked() { _studioAsked = _highlightAsked = false; }
  // the second draw of a print: what was accumulated may be put back
  void setAgain(bool again) { _again = again; }
  // at supersampling times the scale of the view; false if it cannot be done
  bool printTo(int width, int height, int supersampling, unsigned int format,
               unsigned int type, void *pixels);
  void pointerLeft()
  {
    _highlight(nullptr);
    drawTooltip("");
  }
  // show the text in a box by the cursor, or take the box away
  void drawTooltip(const std::string &text);
  // the same box, pinned to the point xyz of the model: it replaces the boxes
  // pinned before, or is added to them; an empty text removes them all
  void pinTooltip(const std::string &text, const double *xyz = nullptr,
                  bool add = false);
  bool addQuery() const { return _addQuery; }
  // where the last selection looked, in the units of the window
  void lastSelection(int xywh[4]) const
  {
    for(int i = 0; i < 4; i++) xywh[i] = _trySelectionXYWH[i];
  }
  void stepPick(int direction) { _stepPick(direction, false); }

  void handleMouse(const paneInput &in);

  // 'e' ends, 'u' undoes, 'i' inverts, 'q' gives up (a lasso too); whether
  // there was one to take it
  bool key(char what);

  // returns 'q', 'l', 'r', 'u' or 'e'
  char selectEntity(int type, std::vector<GVertex *> &vertices,
                    std::vector<GEdge *> &edges, std::vector<GFace *> &faces,
                    std::vector<GRegion *> &regions,
                    std::vector<MElement *> &elements,
                    std::vector<SPoint2> &points, std::vector<PView *> &views);
  // what a click there would select, without waiting for one
  bool pick(int type, bool mesh, bool post, int x, int y, int w, int h,
            std::vector<GVertex *> &vertices, std::vector<GEdge *> &edges,
            std::vector<GFace *> &faces, std::vector<GRegion *> &regions,
            std::vector<MElement *> &elements, std::vector<SPoint2> &points,
            std::vector<PView *> &views)
  {
    return _select(type, false, mesh, post, x, y, w, h, vertices, edges, faces,
                   regions, elements, points, views);
  }
};

#endif

#endif

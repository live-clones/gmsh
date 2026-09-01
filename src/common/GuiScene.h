// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_SCENE_H
#define GMSH_GUI_SCENE_H

#include <string>
#include <vector>

#include "GmshConfig.h"
#include "SPoint2.h"

// The 3D scene: what draws the model, and what one picks in it.
//
// It is not part of the toolkit contract of src/gui/Backend.h, and that is
// deliberate. Every one of these speaks Gmsh -- picking answers with model
// entities, the capture with a pixel buffer, the draw context is the drawing
// itself -- so putting them there would mean a vocabulary born with a hole in
// it. It is a chantier of its own, to be started once the chrome is done and
// to be rewritten rather than adapted; until then these keep the shape they
// have always had, and are implemented once per interface in src/fltk and
// src/imgui.
//
// Gui.h includes this, so nothing outside has to know that the line is here.
// What is on this side of it is what remains to be done.
//
// An interface that has a scene says HAVE_GUI_SCENE and writes these itself;
// one that has not -- a backend being tried out, which only has to say whether
// the chrome works -- says nothing, and GuiScene.cpp answers for it. The scene
// must not be the thing that stops a new interface from linking.

class drawContext;
class PixelBuffer;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

namespace Gui {

  // --- the graphic windows

  // draw context of the last graphic window that received an event
  drawContext *getCurrentDrawContext();
  // size in pixels (i.e. taking the high resolution factor into account) of the
  // last graphic window that received an event
  void getCurrentPixelSize(int &width, int &height);
  // override which graphic window should be considered as current, by giving an
  // absolute index amongst all the existing graphic windows
  void setCurrentOpenglWindow(int which);
  // show every model and every view in every graphic window, undoing what the
  // visibility panel hid in one of them
  void showAllInEveryWindow();
  // split the current graphic window ('h', 'v' or 'u')
  void splitCurrentOpenglWindow(char how, double ratio = 0.5);
  // copy the current graphic window to the clipboard
  void copyCurrentOpenglWindowToClipboard();
  // create a pixel buffer with the contents of the current graphic window, or
  // of all the graphic windows composited together when
  // General.PrintCompositeWindows is set; the caller owns the returned buffer,
  // which is null if it could not be created
  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type);
  // Make the scene occupy the bottom-left corner of the frame buffer at the
  // given size, which is where glReadPixels() reads and where gl2ps expects the
  // viewport to be. width and height are updated with the size that could
  // actually be used.
  void beginGraphicCapture(int &width, int &height, bool composite = false);
  void endGraphicCapture();

  // --- what the views are showing

  // Orient the views the status bar acts upon: "x", "y" or "z" to point that
  // axis out of the screen, "r" for a quarter turn, "1:1" to drop the
  // translation and the zoom. `reverse` is what Shift asks for and `sync` what
  // Control asks for: the other views follow the first instead of being
  // oriented themselves.
  void orientViews(const std::string &what, bool reverse, bool sync);
  // Turn picking with the mouse on or off. It is an option, but the interface
  // has the pointers to change.
  void setMouseSelection(bool on);
  // Play or pause the animation of the post-processing views, and say whether
  // it is running.
  void toggleAnimation();
  bool animating();

  // --- interactive selection

  // select entities of the given type (ENT_POINT, ENT_CURVE, ...) in the most
  // recent graphic window; returns 'q' (abort), 'l' (selected), 'r'
  // (deselected), 'u' (undone) or 'e' (ended)
  char selectEntity(int type);
  // stop the interactive selection that is running, as if the user had pressed
  // 'q'
  void abortSelection();
  // Turn the "add point mode" of the 3D views on or off: while it is on, the
  // pointer drives the coordinates of the entity being placed instead of
  // highlighting what it hovers.
  void setAddPointMode(bool on);
  // results of the last selectEntity() call
  const std::vector<GVertex *> &selectedVertices();
  const std::vector<GEdge *> &selectedEdges();
  const std::vector<GFace *> &selectedFaces();
  const std::vector<GRegion *> &selectedRegions();
  const std::vector<MElement *> &selectedElements();
  const std::vector<SPoint2> &selectedPoints();
  const std::vector<PView *> &selectedViews();

} // namespace Gui

#endif

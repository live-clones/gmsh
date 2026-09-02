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

  // Bring the scene up if it is not already, and give it a chance to draw and
  // to answer the pointer. An interface that holds the scene inside its own
  // windows does this in its own loop and has nothing to do here; a scene in
  // a window of its own is pumped from whatever loop the chrome is running,
  // which is what lets a chrome that knows nothing of OpenGL still show the
  // model.
  void pumpScene(bool rateLimited);

  // --- a picture of the scene, for a chrome that cannot draw one
  //
  // A page in a browser has no way of being handed an OpenGL context: one
  // lives in the browser's process and nothing can draw into it from outside.
  // So the scene is drawn here and the picture is sent, and what the pointer
  // did over that picture comes back. It is what a remote view has always
  // been, and it is honest about its cost: a frame crosses on every move.
  //
  // The interfaces that draw the scene themselves have nothing to send and
  // answer with nothing.

  // Give the chrome a turn. A picking runs a loop of its own -- it waits for
  // the user to click something -- and that loop must not be the end of the
  // interface: whatever is showing the panels has to keep answering, or there
  // is no way left to give up. It pumps the chrome and not the scene, which
  // would be pumping the loop one is already inside.
  void pumpChrome(bool rateLimited);

  // The chrome draws the scene itself, from the pictures below: there is to be
  // no window of its own. Said once, as the interface comes up.
  void sceneShownElsewhere();
  // the scene as a picture, and the size it was drawn at; empty when there is
  // none to send
  // Nothing comes back when the scene has not changed since the last one was
  // asked for, unless `always` says to draw it anyway.
  std::string scenePicture(int &width, int &height, bool always = false);
  // and the same question without the picture
  bool sceneMoved();
  // how big the picture is wanted
  void sceneResize(int width, int height);
  // What the pointer did over it. `what` is 0 moved, 1 pressed, 2 released,
  // 3 turned the wheel; `button` is 0 left, 1 right, 2 middle.
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt);
  // and the keys a picking answers to: 'q' gives up, 'e' ends, 'u' undoes,
  // 'i' inverts
  void sceneKey(char key);

  // Two lines said over the scene rather than in the bar: what to do, and
  // which keys end or abort it, which is what a picking says while it runs.
  // It belongs to whatever draws the scene and not to the chrome around it --
  // a chrome showing pictures of a scene it does not draw could not write on
  // them. Both lines are said every time: a line that is empty is a line that
  // goes away, which is how a picking clears its prompt when it ends.
  void sceneMessage(const std::string &first, const std::string &second);

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

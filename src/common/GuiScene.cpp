// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI) && !defined(HAVE_GUI_SCENE) && \
  !defined(HAVE_GL_SCENE)

#include "GuiScene.h"

// A 3D scene for an interface that has none.
//
// The scene is a chantier of its own, to be rewritten rather than adapted, and
// it must not be the thing that stops a new interface from being tried. One
// that only has to say whether the chrome works -- a backend over a socket, a
// page in a browser, a recorder that draws nothing -- says HAVE_GUI without
// saying HAVE_GUI_SCENE, and these answer for it: nothing is drawn, nothing is
// picked, and nothing crashes.
//
// Every one of them is what the caller gets when there is no scene, and none
// of them is a stub waiting to be filled: the interface that has a scene
// provides its own, in src/fltk/SceneFltk.cpp or src/imgui/SceneImGui.cpp.

namespace Gui {

  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always)
  {
    return "";
  }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  void sceneKey(char key) {}
  void sceneMessage(const std::string &, const std::string &) {}
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }

  drawContext *getCurrentDrawContext() { return nullptr; }

  void getCurrentPixelSize(int &width, int &height) { width = height = 0; }

  void setCurrentOpenglWindow(int which) {}

  void showAllInEveryWindow() {}

  void splitCurrentOpenglWindow(char how, double ratio) {}

  void copyCurrentOpenglWindowToClipboard() {}

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    return nullptr;
  }

  void beginGraphicCapture(int &width, int &height, bool composite) {}

  void endGraphicCapture() {}

  void orientViews(const std::string &what, bool reverse, bool sync) {}

  void setMouseSelection(bool on) {}

  void toggleAnimation() {}

  bool animating() { return false; }

  // 'q' is what a picking says when it was given up, which is what a picking
  // that never began has to say
  char selectEntity(int type) { return 'q'; }

  void abortSelection() {}

  void setAddPointMode(bool on) {}

  const std::vector<GVertex *> &selectedVertices()
  {
    static std::vector<GVertex *> none;
    return none;
  }

  const std::vector<GEdge *> &selectedEdges()
  {
    static std::vector<GEdge *> none;
    return none;
  }

  const std::vector<GFace *> &selectedFaces()
  {
    static std::vector<GFace *> none;
    return none;
  }

  const std::vector<GRegion *> &selectedRegions()
  {
    static std::vector<GRegion *> none;
    return none;
  }

  const std::vector<MElement *> &selectedElements()
  {
    static std::vector<MElement *> none;
    return none;
  }

  const std::vector<SPoint2> &selectedPoints()
  {
    static std::vector<SPoint2> none;
    return none;
  }

  const std::vector<PView *> &selectedViews()
  {
    static std::vector<PView *> none;
    return none;
  }

} // namespace Gui

#endif

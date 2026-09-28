// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_SCENE_OPS_H
#define GMSH_GUI_SCENE_OPS_H

// What a scene answers, written once: to declare the table a scene fills,
// the functions GuiScene.h promises, and what fills the table. Three lists,
// by what is answered when no scene is there: nothing, a value standing for
// nothing, or an empty list one may take a reference to.

#define GUI_SCENE_VOID(F)                                                      \
  F(pumpScene, (bool rateLimited), (rateLimited))                              \
  F(sceneShownElsewhere, (), ())                                               \
  F(sceneResize, (int width, int height), (width, height))                     \
  F(scenePointer,                                                              \
    (double x, double y, int button, int what, double wheel, bool shift,       \
     bool ctrl, bool alt),                                                     \
    (x, y, button, what, wheel, shift, ctrl, alt))                             \
  F(sceneMessage, (const std::string &first, const std::string &second),       \
    (first, second))                                                           \
  F(getCurrentPixelSize, (int &width, int &height), (width, height))           \
  F(setCurrentOpenglWindow, (int which), (which))                              \
  F(showAllInEveryWindow, (), ())                                              \
  F(splitCurrentOpenglWindow, (char how, double ratio), (how, ratio))          \
  F(copyCurrentOpenglWindowToClipboard, (), ())                                \
  F(beginGraphicCapture, (int &width, int &height, bool composite),            \
    (width, height, composite))                                                \
  F(endGraphicCapture, (), ())                                                 \
  F(orientViews, (const std::string &what, bool reverse, bool sync),           \
    (what, reverse, sync))                                                     \
  F(setMouseSelection, (bool on), (on))                                        \
  F(toggleAnimation, (), ())                                                   \
  F(abortSelection, (), ())                                                    \
  F(setAddPointMode, (bool on), (on))                                          \
  F(sceneSettingChanged, (const std::string &what), (what))

#define GUI_SCENE_VALUE(F)                                                     \
  F(std::string, scenePicture, (int &width, int &height, bool always),         \
    (width, height, always), std::string())                                    \
  F(bool, sceneMoved, (), (), false)                                           \
  F(bool, sceneKey, (char key), (key), false)                                  \
  F(drawContext *, getCurrentDrawContext, (), (), nullptr)                     \
  F(PixelBuffer *, createCompositePixelBuffer,                                 \
    (unsigned int format, unsigned int type), (format, type), nullptr)         \
  F(bool, animating, (), (), false)                                            \
  F(char, selectEntity, (int type), (type), 'q')                               \
  F(bool, pickAt, (int type, bool mesh, bool post, int x, int y, int w, int h), \
    (type, mesh, post, x, y, w, h), false)                                     \
  F(bool, printView,                                                           \
    (int width, int height, int supersampling, unsigned int format,            \
     unsigned int type, void *pixels),                                         \
    (width, height, supersampling, format, type, pixels), false)

#define GUI_SCENE_LIST(F)                                                      \
  F(GVertex *, selectedVertices)                                               \
  F(GEdge *, selectedEdges)                                                    \
  F(GFace *, selectedFaces)                                                    \
  F(GRegion *, selectedRegions)                                                \
  F(MElement *, selectedElements)                                              \
  F(SPoint2, selectedPoints)                                                   \
  F(PView *, selectedViews)

#endif

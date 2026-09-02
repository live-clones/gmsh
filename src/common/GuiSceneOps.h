// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_SCENE_OPS_H
#define GMSH_GUI_SCENE_OPS_H

// What a 3D scene answers, written once.
//
// There is more than one of them -- the FLTK windows, the Dear ImGui panes, a
// window of its own for a chrome that draws nothing -- and which one runs is
// decided when the interface comes up. So the list of what a scene has to
// answer is written here, once, and used three ways: to declare the table a
// scene fills, to write the functions GuiScene.h promises, and to fill that
// table from a scene's own functions without naming any of them twice.
//
// Saying it once is the point. Thirty-odd functions repeated in four files is
// four places for one of them to be forgotten, and a scene that forgets one
// answers with whatever was in memory.
//
// Three lists, because what a function gives back decides what happens when
// no scene has it: nothing at all, a value that stands for nothing, or an
// empty list one may take a reference to.

#define GUI_SCENE_VOID(F)                                                      \
  F(pumpScene, (bool rateLimited), (rateLimited))                              \
  F(sceneShownElsewhere, (), ())                                               \
  F(sceneResize, (int width, int height), (width, height))                     \
  F(scenePointer,                                                              \
    (double x, double y, int button, int what, double wheel, bool shift,       \
     bool ctrl, bool alt),                                                     \
    (x, y, button, what, wheel, shift, ctrl, alt))                             \
  F(sceneKey, (char key), (key))                                               \
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
  F(setAddPointMode, (bool on), (on))

// what each answers with when there is no scene to answer
#define GUI_SCENE_VALUE(F)                                                     \
  F(std::string, scenePicture, (int &width, int &height, bool always),         \
    (width, height, always), std::string())                                    \
  F(bool, sceneMoved, (), (), false)                                           \
  F(drawContext *, getCurrentDrawContext, (), (), nullptr)                     \
  F(PixelBuffer *, createCompositePixelBuffer,                                 \
    (unsigned int format, unsigned int type), (format, type), nullptr)         \
  F(bool, animating, (), (), false)                                            \
  F(char, selectEntity, (int type), (type), 'q')

// the lists a picking answers with, which are handed back by reference
#define GUI_SCENE_LIST(F)                                                      \
  F(GVertex *, selectedVertices)                                               \
  F(GEdge *, selectedEdges)                                                    \
  F(GFace *, selectedFaces)                                                    \
  F(GRegion *, selectedRegions)                                                \
  F(MElement *, selectedElements)                                              \
  F(SPoint2, selectedPoints)                                                   \
  F(PView *, selectedViews)

#endif

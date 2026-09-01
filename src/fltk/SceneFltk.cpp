// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The 3D scene of the FLTK interface: what draws the model, and what one
// picks in it.
//
// It is the whole of what is left outside src/common/Gui.cpp, and it is the
// only thing either interface still answers for itself. GuiScene.h says why:
// every one of these speaks Gmsh -- picking answers with model entities, the
// capture with a pixel buffer, the draw context is the drawing itself -- so
// none of it belongs in the toolkit contract of src/gui/Backend.h. It is a
// chantier of its own, to be rewritten rather than adapted, and until then it
// keeps the shape it has always had.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <FL/Fl.H>
#include <FL/fl_ask.H>

#include "Gui.h"
#include "FlGui.h"
#include <FL/fl_draw.H>
#include "extraDialogs.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "dialogFltk.h"
#include "onelabGroup.h"
#include "fileDialogs.h"
#include "Context.h"
#include "drawContext.h"
#include "PixelBuffer.h"
#include "OS.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

// defined in CreateFileFltk.cpp
PixelBuffer *GetCompositePixelBufferFltk(GLenum format, GLenum type);

// The 3D scene of the FLTK interface: what draws the model, and what one
// picks in it.
//
// It is the whole of what is left outside src/common/Gui.cpp, and it is the
// only thing either interface still answers for itself. GuiScene.h says why:
// every one of these speaks Gmsh -- picking answers with model entities, the
// capture with a pixel buffer, the draw context is the drawing itself -- so
// none of it belongs in the toolkit contract of src/gui/Backend.h. It is a
// chantier of its own, to be rewritten rather than adapted, and until then it
// keeps the shape it has always had.

namespace Gui {

  // this interface holds the scene inside its own windows and draws it in its
  // own loop; there is nothing to pump from outside
  void pumpScene(bool rateLimited) {}


  // --- messages, status bar and modal dialogs

  // --- refreshing the GUI when the model changes

  // --- modules, tree and context windows

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    if(available()) fltkOrientViews(what, reverse, sync);
  }

  void setMouseSelection(bool on)
  {
    if(available()) fltkSetMouseSelection(on);
  }

  void toggleAnimation()
  {
    if(available()) fltkToggleAnimation();
  }

  bool animating() { return available() && fltkAnimating(); }

  void abortSelection()
  {
    openglWindow *w = FlGui::instance()->getCurrentOpenglWindow();
    if(w) {
      w->quitSelection = 1;
      w->selectionMode = false;
    }
  }

  void setAddPointMode(bool on)
  {
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->addPointMode = on ? 1 : 0;
  }

  // --- graphic windows

  drawContext *getCurrentDrawContext()
  {
    return FlGui::instance()->getCurrentDrawContext();
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    width = gl->pixel_w();
    height = gl->pixel_h();
  }

  void setCurrentOpenglWindow(int which)
  {
    FlGui::instance()->setCurrentOpenglWindow(which);
  }

  void showAllInEveryWindow()
  {
    if(!available()) return;
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
        FlGui::instance()->graph[i]->gl[j]->getDrawContext()->showAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    FlGui::instance()->splitCurrentOpenglWindow(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    FlGui::instance()->copyCurrentOpenglWindowToClipboard();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format, unsigned int type)
  {
    return GetCompositePixelBufferFltk((GLenum)format, (GLenum)type);
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    // the graphic window is a window of its own: making it current already puts
    // its origin at (0, 0)
  }

  void endGraphicCapture() {}

  // --- interactive selection

  char selectEntity(int type) { return FlGui::instance()->selectEntity(type); }

  const std::vector<GVertex *> &selectedVertices()
  {
    return FlGui::instance()->selectedVertices;
  }
  const std::vector<GEdge *> &selectedEdges()
  {
    return FlGui::instance()->selectedEdges;
  }
  const std::vector<GFace *> &selectedFaces()
  {
    return FlGui::instance()->selectedFaces;
  }
  const std::vector<GRegion *> &selectedRegions()
  {
    return FlGui::instance()->selectedRegions;
  }
  const std::vector<MElement *> &selectedElements()
  {
    return FlGui::instance()->selectedElements;
  }
  const std::vector<SPoint2> &selectedPoints()
  {
    return FlGui::instance()->selectedPoints;
  }
  const std::vector<PView *> &selectedViews()
  {
    return FlGui::instance()->selectedViews;
  }

} // namespace Gui

#endif

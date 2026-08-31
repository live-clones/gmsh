// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// FLTK implementation of the toolkit-independent GUI interface declared in
// src/common/Gui.h. This is the only file of src/fltk that the rest of Gmsh
// links against; everything else in this directory is FLTK-specific and is
// reached exclusively through the functions below.

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

// What is left of the FLTK adapter.
//
// Everything that is not a toolkit's is in src/common/Gui.cpp now, and what
// is goes through Ui::Backend. Two things are still here:
//
//   the 3D scene -- picking, the draw context, the capture, the windows the
//   views are drawn in -- which speaks Gmsh and is a chantier of its own,
//   declared in GuiScene.h;
//
//   and the two calls that wait on a file chooser that can name its formats:
//   exporting a view has to know which of the four flavours of ".pos" was
//   picked, and the entries of the File menu each open a chooser of their
//   own. Until the chooser can answer, both are written twice.
//
// When those two are done this file goes.

namespace Gui {

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

  void exportView(int index)
  {
#if defined(HAVE_POST)
    if(index < 0 || index >= (int)PView::list.size()) return;
    static const char *formats =
      "Gmsh Parsed\t*.pos\nGmsh Mesh-based\t*.pos\n"
      "Gmsh Legacy ASCII\t*.pos\nGmsh Legacy Binary\t*.pos\n"
      "MED\t*.rmed\nSTL Surface\t*.stl\nGeneric TXT\t*.txt\n";
    PView *view = PView::list[index];
  again:
    if(!fileChooser(FILE_CHOOSER_CREATE, "Export", formats,
                    view->getData()->getFileName().c_str()))
      return;
    std::string name = fileChooserGetName(1);
    bool confirmOverwrite = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
    // handled directly by the native macOS file chooser
    if(CTX::instance()->nativeFileChooser) confirmOverwrite = false;
#endif
    if(confirmOverwrite && !StatFile(name)) {
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", nullptr, name.c_str()))
        goto again;
    }
    // the place of the filter in the list above, in the order PView::write()
    // numbers the formats
    static const int format[] = {2, 5, 0, 1, 6, 3, 4};
    int which = fileChooserGetFilter();
    view->write(name, (which >= 0 && which < 7) ? format[which] : 2);
#endif
  }

  void fileAction(const std::string &what) { fltkFileAction(what); }

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

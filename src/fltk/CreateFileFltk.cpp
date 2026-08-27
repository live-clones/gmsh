// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// FLTK-specific part of the graphic output file creation: grabbing the pixels
// of the graphic window(s). Called from CreateFile.cpp through
// Gui::createCompositePixelBuffer().

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <algorithm>
#include <vector>

#include <FL/Fl.H>
#include <FL/gl.h>

#include "FlGui.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "drawContext.h"
#include "PixelBuffer.h"
#include "Context.h"

PixelBuffer *GetCompositePixelBufferFltk(GLenum format, GLenum type)
{
  openglWindow *newg = nullptr;

  if(CTX::instance()->print.width > 0 || CTX::instance()->print.height > 0){
    GLint width = FlGui::instance()->getCurrentOpenglWindow()->pixel_w();
    GLint height = FlGui::instance()->getCurrentOpenglWindow()->pixel_h();
    if(CTX::instance()->print.width <= 0){
      double w = width * CTX::instance()->print.height / (double)height;
      width = (int)w;
      height = CTX::instance()->print.height;
    }
    else if(CTX::instance()->print.height <= 0){
      double h = height * CTX::instance()->print.width / (double)width;
      height = (int)h;
      width = CTX::instance()->print.width;
    }
    else{
      width = CTX::instance()->print.width;
      height = CTX::instance()->print.height;
    }
    newg = new openglWindow(100, 100, width, height);
    int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
    if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
    newg->mode(mode);
    newg->end();
    newg->getDrawContext()->copyViewAttributes
      (FlGui::instance()->getCurrentOpenglWindow()->getDrawContext());
    newg->show();
    openglWindow::setLastHandled(newg);
    // waiting for the OS to really make the window visible and to call the
    // draw() function on (some ?) linux; if we do not wait here, the window is
    // not ready and the picture cannot be generated
    while(!newg->valid()) Fl::wait();
  }

  PixelBuffer *buffer;
  if(newg || !CTX::instance()->print.compositeWindows){
    GLint width = FlGui::instance()->getCurrentOpenglWindow()->pixel_w();
    GLint height = FlGui::instance()->getCurrentOpenglWindow()->pixel_h();
    buffer = new PixelBuffer(width, height, format, type);
    buffer->fill(CTX::instance()->batch);
  }
  else{
    graphicWindow *g = FlGui::instance()->graph[0];
    for(std::size_t i = 1; i < FlGui::instance()->graph.size(); i++){
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++){
        if(FlGui::instance()->graph[i]->gl[j] ==
           FlGui::instance()->getCurrentOpenglWindow()){
          g = FlGui::instance()->graph[i];
          break;
        }
      }
    }
    int xmin = 10000000, ymin = 10000000;
    for(std::size_t i = 0; i < g->gl.size(); i++){
      xmin = std::min(xmin, g->gl[i]->x());
      ymin = std::min(ymin, g->gl[i]->y());
    }
    int ww = 0, hh = 0;
    std::vector<PixelBuffer*> buffers;
    for(std::size_t i = 0; i < g->gl.size(); i++){
      openglWindow::setLastHandled(g->gl[i]);
      buffer = new PixelBuffer(g->gl[i]->pixel_w(), g->gl[i]->pixel_h(),
                               format, type);
      buffer->fill(CTX::instance()->batch);
      buffers.push_back(buffer);
      double fact = g->gl[i]->getDrawContext()->highResolutionPixelFactor();
      ww = std::max(ww, (int)(fact * (g->gl[i]->x() - xmin)) + g->gl[i]->pixel_w());
      hh = std::max(hh, (int)(fact * (g->gl[i]->y() - ymin)) + g->gl[i]->pixel_h());
    }
    buffer = new PixelBuffer(ww, hh, format, type);
    for(std::size_t i = 0; i < g->gl.size(); i++){
      double fact = g->gl[i]->getDrawContext()->highResolutionPixelFactor();
      buffer->copyPixels(fact * (g->gl[i]->x() - xmin),
                         hh - g->gl[i]->pixel_h() - fact * (g->gl[i]->y() - ymin),
                         buffers[i]);
      delete buffers[i];
    }
  }

  if(newg){
    openglWindow::setLastHandled(nullptr);
    newg->hide();
    delete newg;
  }

  return buffer;
}

#endif

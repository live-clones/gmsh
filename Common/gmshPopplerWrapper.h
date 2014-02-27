// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GMSHPOPPLERWRAPPER_PDF_H_
#define _GMSHPOPPLERWRAPPER_PDF_H_

#include "GmshConfig.h"

#if defined(HAVE_POPPLER)
#include <string>
#include <map>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-image.h>
#if defined(HAVE_OPENGL)
#  if defined(__APPLE__) || defined(HAVE_OPENGL_GL_H)
#    include <OpenGL/gl.h>
#  else
#    include <GL/gl.h>
#  endif
#endif

class gmshPopplerWrapper {
private:
  static int _current_page;
  static poppler::document *_current_doc;
  static gmshPopplerWrapper *_instance;
  static int _w,_h;
#if defined(HAVE_OPENGL)
  static std::map<int,GLuint> _pages2textures; // map pages to textures
#endif

public:
  static gmshPopplerWrapper *instance();
  static bool hasFile(){ return _current_doc ? true : false; }
  static int loadFromFile(const std::string &file_name,
                          const std::string &owner_password=std::string(),
                          const std::string &user_password=std::string());
  static int width() { return _w; }
  static int height() { return _h; }
  static void setCurrentPageUp () { _current_page++; }
  static void setCurrentPageDown () { if(_current_page > 0) _current_page--; }
#if defined(HAVE_OPENGL)
  static GLuint getTextureForPage(double xres, double yres);
#endif
};

#endif
#endif

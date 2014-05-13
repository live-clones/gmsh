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
  static int _currentPage;
  static poppler::document *_currentDoc;
  static gmshPopplerWrapper *_instance;
  static int _w, _h;
#if defined(HAVE_OPENGL)
  static std::map<int,GLuint> _pages2textures; // map pages to textures
#endif

public:
  static gmshPopplerWrapper *instance();
  static int loadFromFile(const std::string &file_name,
                          const std::string &owner_password=std::string(),
                          const std::string &user_password=std::string());
  static int width(){ return _w; }
  static int height(){ return _h; }
  static int getNumPages();
  static void setCurrentPage(int num){ _currentPage = num; }
  static int getCurrentPage(){ return _currentPage; }
  static void setCurrentPageUp(){ if(_currentPage < getNumPages()) _currentPage++; }
  static void setCurrentPageDown(){ if(_currentPage > 0) _currentPage--; }
#if defined(HAVE_OPENGL)
  static GLuint getTextureForPage(double xres, double yres);
#endif
};

#endif
#endif

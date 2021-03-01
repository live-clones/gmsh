// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSHPOPPLERWRAPPER_PDF_H
#define GMSHPOPPLERWRAPPER_PDF_H

#include "GmshConfig.h"
#include "Context.h"
#include "OpenFile.h"
#include "GModel.h"

#if defined(HAVE_POPPLER)
#include <string>
#include <map>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <poppler/cpp/poppler-image.h>
#if defined(HAVE_OPENGL)
#if defined(__APPLE__) || defined(HAVE_OPENGL_GL_H)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#endif

class gmshPopplerWrapper {
private:
  static int _currentPage;
  static poppler::document *_currentDoc;
  static gmshPopplerWrapper *_instance;
  static std::map<int, std::pair<GModel *, std::string> > _macros;
  static int _w, _h;
#if defined(HAVE_OPENGL)
  static std::map<int, GLuint> _pages2textures; // map pages to textures
#endif

public:
  static gmshPopplerWrapper *instance();
  static int loadFromFile(const std::string &file_name,
                          const std::string &owner_password = std::string(),
                          const std::string &user_password = std::string());
  static int width() { return _w; }
  static int height() { return _h; }
  static int getNumPages();

  static void setMacroForPages(std::vector<int> &is, const std::string &s,
                               const std::string &o)
  {
    GModel *gm = GModel::current();
    if(_macros.empty()) {
      _macros[-1] = std::make_pair(gm, "NULL");
    }
    GModel *gmNew = new GModel(s);
    GModel::setCurrent(gmNew);
    MergeFile(s, true);
    for(size_t i = 0; i < is.size(); i++)
      _macros[is[i]] = std::make_pair(gmNew, o);
    GModel::setCurrent(gm);
    gmNew->setVisibility(0);
  }

  static void setCurrentPage(int num)
  {
    _currentPage = num;
    if(_currentPage >= getNumPages()) _currentPage = getNumPages() - 1;
    if(_currentPage < 0) _currentPage = 0;
    CTX::instance()->bgImagePage = _currentPage;
    auto it = _macros.find(_currentPage);
    if(it == _macros.end()) it = _macros.find(-1);
    if(it != _macros.end()) {
      if(GModel::current() != it->second.first) {
        GModel::current()->setVisibility(0);
        GModel::setCurrent(it->second.first);
        if(it->second.second != "NULL") MergeFile(it->second.second, true);
        it->second.first->setVisibility(1);
      }
    }
  }
  static int getCurrentPage() { return _currentPage; }
  static void setCurrentPageUp()
  {
    ++_currentPage;
    if(_currentPage >= getNumPages()) _currentPage = getNumPages() - 1;
    CTX::instance()->bgImagePage = _currentPage;
  }
  static void setCurrentPageDown()
  {
    --_currentPage;
    if(_currentPage < 0) _currentPage = 0;
    CTX::instance()->bgImagePage = _currentPage;
  }
#if defined(HAVE_OPENGL)
  static GLuint getTextureForPage(double xres, double yres);
#endif
};

#endif
#endif

// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "gmshPopplerWrapper.h"

#if defined(HAVE_POPPLER)

#include "GmshMessage.h"
#include <poppler/cpp/poppler-image.h>
#include <poppler/cpp/poppler-page-renderer.h>

gmshPopplerWrapper *gmshPopplerWrapper::_instance = 0;
poppler::document  *gmshPopplerWrapper::_currentDoc = 0;
#if defined(HAVE_OPENGL)
std::map<int, GLuint> gmshPopplerWrapper::_pages2textures;
int gmshPopplerWrapper::_w = -1;
int gmshPopplerWrapper::_h = -1;
int gmshPopplerWrapper::_currentPage = 0;
#endif

gmshPopplerWrapper *gmshPopplerWrapper::instance()
{
  if(!_instance) _instance = new gmshPopplerWrapper;
  return _instance;
}

int gmshPopplerWrapper::loadFromFile(const std::string &fileName,
                                     const std::string &ownerPassword,
                                     const std::string &userPassword)
{
  if (_currentDoc) delete _currentDoc;

  Msg::Info("Loading PDF file `%s'...", fileName.c_str());
  _currentDoc = poppler::document::load_from_file(fileName, ownerPassword,
                                                   userPassword);
  if (!_currentDoc) return 0;

  Msg::Info("Loaded PDF file `%s'", fileName.c_str());
  //  createBitmap(1,72.,72.,-1,-1,-1,-1);
  return 1;
}

int gmshPopplerWrapper::getNumPages()
{
  if(!_currentDoc) return 0;
  return _currentDoc->pages();
}

#if defined(HAVE_OPENGL)
GLuint gmshPopplerWrapper::getTextureForPage(double xres,
					     double yres)
{
  int iPage = _currentPage;
  int numPages = getNumPages();
  if(iPage < 0) iPage = 0;
  if(iPage > numPages - 1) iPage = numPages - 1;
  std::map<int,GLuint>::iterator it = _pages2textures.find(iPage);
  if (it != _pages2textures.end()) return it->second;
  if (!_currentDoc) return 0;
  poppler::page *page = _currentDoc->create_page(iPage);
  poppler::page_renderer pr;
  poppler::image im = pr.render_page(page, xres, yres, -1, -1, -1);
  _w = im.width();
  _h = im.height();
  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  _pages2textures[iPage] = texture;
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, im.width(), im.height(), 0,
	       GL_RGBA, GL_UNSIGNED_BYTE, im.const_data());
  return texture;
}
#endif

#endif

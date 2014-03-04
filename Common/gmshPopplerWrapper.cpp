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
poppler::document  *gmshPopplerWrapper::_current_doc = 0;
#if defined(HAVE_OPENGL)
std::map<int, GLuint> gmshPopplerWrapper::_pages2textures;
int gmshPopplerWrapper::_w = -1;
int gmshPopplerWrapper::_h = -1;
int gmshPopplerWrapper::_current_page = 0;
#endif

gmshPopplerWrapper *gmshPopplerWrapper::instance()
{
  if(!_instance) _instance = new gmshPopplerWrapper;
  return _instance;
}

int gmshPopplerWrapper::loadFromFile(const std::string &file_name,
                                     const std::string &owner_password,
                                     const std::string &user_password)
{
  if (_current_doc) delete _current_doc;
  _current_doc = poppler::document::load_from_file(file_name, owner_password,
                                                   user_password);
  if (!_current_doc) return 0;
  Msg::Info("PDF File has been loaded in the Wrapper");
  //  createBitmap(1,72.,72.,-1,-1,-1,-1);
  return 1;
}

#if defined(HAVE_OPENGL)
GLuint gmshPopplerWrapper::getTextureForPage(double xres,
					     double yres)
{
  int iPage = _current_page;
  std::map<int,GLuint>::iterator it = _pages2textures.find(iPage);
  if (it != _pages2textures.end()) return it->second;
  if (!_current_doc) return 0;
  poppler::page *_current_page = _current_doc->create_page(iPage);
  poppler::page_renderer pr;
  poppler::image im = pr.render_page(_current_page, xres, yres, -1, -1, -1);
  _w = im.width();
  _h = im.height();
  // im.save("page.png","png");
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

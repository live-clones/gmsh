// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "gmshPopplerWrapper.h"

#if defined(HAVE_POPPLER)

#include "GmshMessage.h"
#include "FunctionManager.h"
#include <poppler/cpp/poppler-image.h>
#include <poppler/cpp/poppler-page-renderer.h>
#if defined(HAVE_FLTK)
#include <FL/Fl_JPEG_Image.H>
#endif

gmshPopplerWrapper *gmshPopplerWrapper::_instance = 0;
std::map<int, std::pair<GModel *, std::string> > gmshPopplerWrapper::_macros;
poppler::document *gmshPopplerWrapper::_currentDoc = 0;
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
  if(_currentDoc) delete _currentDoc;

  Msg::Info("Loading PDF file `%s'...", fileName.c_str());
  _currentDoc =
    poppler::document::load_from_file(fileName, ownerPassword, userPassword);
  if(!_currentDoc) return 0;

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
GLuint gmshPopplerWrapper::getTextureForPage(double xres, double yres)
{
  int iPage = _currentPage;
  int numPages = getNumPages();
  if(iPage < 0) iPage = 0;
  if(iPage > numPages - 1) iPage = numPages - 1;
  auto it = _pages2textures.find(iPage);
  if(it != _pages2textures.end()) return it->second;
  if(!_currentDoc) return 0;

  poppler::page *page = _currentDoc->create_page(iPage);
  poppler::page_renderer pr;
  pr.set_render_hint(poppler::page_renderer::text_antialiasing, true);
  pr.set_render_hint(poppler::page_renderer::antialiasing, true);
  poppler::image im = pr.render_page(page, xres, yres, -1, -1, -1);
  im.save("hop.jpeg", "jpeg");
  Fl_RGB_Image *img = new Fl_JPEG_Image("hop.jpeg");
  //  Fl_RGB_Image *img2 = (Fl_RGB_Image*)img->copy(2048, 2048);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, img->w());
  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->w(), img->h(), 0,
               (img->d() == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE,
               img->array);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);

  _w = img->w();
  _h = img->h();

  delete img;
  //  delete img2;
  _pages2textures[iPage] = texture;
  return texture;
}
#endif

#endif

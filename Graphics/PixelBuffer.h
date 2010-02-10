// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PIXEL_BUFFER_H_
#define _PIXEL_BUFFER_H_

#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "drawContext.h"

#if defined(WIN32)
#include <windows.h>
#undef min
#undef max
#endif

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#if defined(HAVE_OSMESA)
#include <GL/osmesa.h>
#endif

class PixelBuffer{
 private:
  int _width, _height, _numComp, _dataSize;
  GLenum _format, _type;
  unsigned char *_pixels;
 public:
  PixelBuffer(int width, int height, GLenum format, GLenum type)
    : _width(width), _height(height), _format(format), _type(type)
  {
    if(format == GL_RGB){
      _numComp = 3;
    }
    else if(format == GL_RGBA){
      _numComp = 4;
    }
    else{
      Msg::Error("Unknown pixel format: assuming RGB");
      _format = GL_RGB;
      _numComp = 3;
    }
    
    if(type == GL_UNSIGNED_BYTE){
      _dataSize = sizeof(unsigned char);
    }
    else if(type == GL_FLOAT){
      _dataSize = sizeof(float);
    }
    else{
      Msg::Error("Unknown pixel storage type: assuming unsigned byte");
      _type = GL_UNSIGNED_BYTE;
      _dataSize = sizeof(unsigned char);
    }
    int n = _numComp * _width * _height * _dataSize;
    _pixels = new unsigned char[n];
    for(int i = 0; i < n; i++) _pixels[i] = 0;
  }
  ~PixelBuffer()
  {
    delete [] _pixels;
  }
  int getWidth(){ return _width; }
  int getHeight(){ return _height; }
  int getNumComp(){ return _numComp; }
  int getDataSize(){ return _dataSize; }
  GLenum getFormat(){ return _format; }
  GLenum getType(){ return _type; }
  void *getPixels(){ return (void*)_pixels; }
  void copyPixels(int x, int y, PixelBuffer *buffer)
  {
    if(x + buffer->getWidth() > _width || y + buffer->getHeight() > _height){
      Msg::Error("Destination pixel buffer too small for holding copy");
      return;
    }
    if(buffer->getNumComp() != _numComp || buffer->getDataSize() != _dataSize ||
       buffer->getFormat() != _format || buffer->getType() != _type){
      Msg::Error("Pixel buffer type mismatch: impossible to copy");
      return;
    }
    for(int i = 0; i < buffer->getWidth(); i++)
      for(int j = 0; j < buffer->getHeight(); j++)
        memcpy(_pixels + ((j + y) * _width + (i + x)) * _dataSize * _numComp,
               (unsigned char*)buffer->getPixels() + (j * buffer->getWidth() + i) *
               _dataSize * _numComp, _dataSize * _numComp);
  }
  void fill(int offscreen)
  {
    if(!offscreen){
      drawContext::global()->drawCurrentOpenglWindow(true);
      glFinish();
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glReadPixels(0, 0, _width, _height, _format, _type, (void*)_pixels);
    }
    else{
#if defined(HAVE_OSMESA)
      if(_format != GL_RGB && _type != GL_UNSIGNED_BYTE){
        Msg::Error("Offscreen rendering only implemented for GL_RGB/GL_UNSIGNED_BYTE");
        return;
      }
      OSMesaContext ctx = OSMesaCreateContextExt(OSMESA_RGB, 16, 0, 0, NULL);
      if(!ctx){
        Msg::Error("OSMesaCreateContext failed");
        return;
      }
      if(!OSMesaMakeCurrent(ctx, (void*)_pixels, GL_UNSIGNED_BYTE, _width, _height)){
        Msg::Error("OSMesaMakeCurrent failed");
      }
      drawContext::global()->drawCurrentOpenglWindow(false);
      glFinish();
      OSMesaDestroyContext(ctx);
#else
      Msg::Warning("Gmsh must be compiled with OSMesa to support offscreen rendering");
#endif
    }
  }
};

#endif

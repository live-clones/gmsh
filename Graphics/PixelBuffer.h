// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PIXEL_BUFFER_H_
#define _PIXEL_BUFFER_H_

#include <FL/gl.h>
#include "GmshMessage.h"
#include "Draw.h"
#include "MallocUtils.h"

#if defined(HAVE_OSMESA)
#include <GL/osmesa.h>
#endif

class PixelBuffer{
 private:
  int _width, _height, _numComp, _dataSize;
  GLenum _format, _type;
  void *_pixels;
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
    _pixels = Calloc(_numComp * _width * _height, _dataSize);
  }
  ~PixelBuffer()
  {
    Free(_pixels);
  }
  int GetWidth(){ return _width; }
  int GetHeight(){ return _height; }
  int GetNumComp(){ return _numComp; }
  int GetDataSize(){ return _dataSize; }
  GLenum GetFormat(){ return _format; }
  GLenum GetType(){ return _type; }
  void *GetPixels(){ return _pixels; }
  void Fill(int offscreen)
  {
    if(!offscreen){
      DrawCurrentOpenglWindow(true);
      glFinish();
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glReadPixels(0, 0, _width, _height, _format, _type, _pixels);
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
      if(!OSMesaMakeCurrent(ctx, _pixels, GL_UNSIGNED_BYTE, _width, _height)){
	Msg::Error("OSMesaMakeCurrent failed");
      }
      DrawCurrentOpenglWindow(false);
      glFinish();
      OSMesaDestroyContext(ctx);
#else
      Msg::Warning("Offscreen rendering not available in this version");
#endif
    }
  }
};

#endif

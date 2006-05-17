#ifndef _PIXEL_BUFFER_H_
#define _PIXEL_BUFFER_H_
/*
 * Copyright (C) 1999-2006 Christophe Geuzaine <geuz@geuz.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of either:
 *
 * a) the GNU Library General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your
 * option) any later version; or
 *
 * b) the GL2PS License as published by Christophe Geuzaine, either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either
 * the GNU Library General Public License or the GL2PS License for
 * more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library in the file named "COPYING.LGPL";
 * if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * You should have received a copy of the GL2PS License with this
 * library in the file named "COPYING.GL2PS"; if not, I will be glad
 * to provide one.
 */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Draw.h"
#include "Context.h"

extern Context_T CTX;

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
      Msg(GERROR, "Unknown pixel format: assuming RGB");
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
      Msg(GERROR, "Unknown pixel storage type: assuming unsigned byte");
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
  void Fill()
  {
    if(!CTX.batch){
      SetOpenglContext();
      ClearOpengl();
      Draw3d();
      Draw2d();
      glFinish();
      glPixelStorei(GL_PACK_ALIGNMENT, 1);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glReadPixels(0, 0, _width, _height, _format, _type, _pixels);
    }
    else{
#if defined(HAVE_OSMESA)
      if(_format != GL_RGB && _type != GL_UNSIGNED_BYTE){
	Msg(GERROR, "Offscreen rendering only implemented for GL_RGB/GL_UNSIGNED_BYTE");
	return;
      }
      OSMesaContext ctx = OSMesaCreateContextExt(OSMESA_RGB, 16, 0, 0, NULL);
      if(!ctx){
	Msg(GERROR, "OSMesaCreateContext failed");
	return;
      }
      if(!OSMesaMakeCurrent(ctx, _pixels, GL_UNSIGNED_BYTE, _width, _height)){
	Msg(GERROR, "OSMesaMakeCurrent failed");
      }
      ClearOpengl();
      Draw3d();
      Draw2d();
      glFinish();
      OSMesaDestroyContext(ctx);
#else
      Msg(WARNING, "Offscreen rendering not available in this version");
#endif
    }
  }
};

#endif

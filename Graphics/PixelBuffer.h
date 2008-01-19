#ifndef _PIXEL_BUFFER_H_
#define _PIXEL_BUFFER_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "Message.h"
#include "Malloc.h"
#include "Draw.h"

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
  void Fill(int offscreen)
  {
    if(!offscreen){
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

#if defined(BUILD_ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>
#else
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#endif

#include "drawString.h"

drawString::drawString(std::string text, int size, float color[4])
{
  _map = 0;
  _size = size;
  _height = 0;
  _width = 0;
  _realWidth = 0;
  if(color == NULL)
    setColor(0.0f, 0.0f, 0.0f, 1.0f);
  else
    setColor(color);
  setText(text);
}

void drawString::setText(std::string text)
{
  _text = text;
  getBitmapFromString(_text.c_str(), _size, &_map, &_height, &_width,
                      &_realWidth);
}

void drawString::setColor(float color[4])
{
  _color[0] = color[0];
  _color[1] = color[1];
  _color[2] = color[2];
  _color[3] = color[3];
}

void drawString::setColor(float r, float g, float b, float a)
{
  _color[0] = r;
  _color[1] = g;
  _color[2] = b;
  _color[3] = a;
}

void drawString::draw(float x, float y, float z, float w, float h, bool center)
{
  if(!_map || !_width || !_height) return;
  GLuint textureId;
  glGenTextures(1, &textureId);
  glBindTexture(GL_TEXTURE_2D, textureId);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, _width, _height, 0, GL_ALPHA,
               GL_UNSIGNED_BYTE, _map);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glColor4f(_color[0], _color[1], _color[2], _color[3]);
  if(center) x -= (float)_realWidth / w / 2;
  GLfloat vertex[] = {
    x,
    y - _height / h + _size / h,
    z, // bottom left
    x,
    y + (float)_height / h - _height / h + _size / h,
    z, // top left
    x + (float)_width / w,
    y - _height / h + _size / h,
    z, // bottom right
    x + (float)_width / w,
    y + (float)_height / h - _height / h + _size / h,
    z, // top right
  };
  GLfloat texture[] = {
    0.0f, 1.0f, // top left
    0.0f, 0.0f, // bottom left
    1.0f, 1.0f, // top right
    1.0f, 0.0f, // bottom right
  };
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glTexCoordPointer(2, GL_FLOAT, 0, texture);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertex);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  glDeleteTextures(1, &textureId);
}

#ifndef ONELAB_DRAW_STRING_H
#define ONELAB_DRAW_STRING_H

#include <stdlib.h>
#include <string>

#if defined(BUILD_ANDROID)
#include "androidUtils.h"
#else
#include "iosUtils.h"
#endif

class drawString {
private:
  std::string _text; // Text to draw
  float _color[4]; // Text color
  int _size; // Text size in px
  int _height, _width, _realWidth; // Size of the texture in px
  unsigned char *_map;

public:
  drawString(std::string text, int size = 12, float *color = NULL);
  ~drawString()
  {
    if(_map) free(_map);
  }

  void setText(std::string text);
  void setColor(float *color);
  void setColor(float r, float g, float b, float a);
  void draw(float x, float y, float z, float w, float h, bool center = true);
};

#endif

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#include "drawContextFltkStringTexture.h"

// the size of the string, measured at its size in the window's units as the
// other engines do, and the baseline its descent (at the rasterised size)
// above the bottom: the quad is lowered by as much, so that the anchor is on
// the baseline
drawContextFltkQueued::extent
drawContextFltkStringTexture::measure(const element &e, double f)
{
  gl_font(e.fontId, e.fontSize);
  double width = gl_width(e.text.c_str()) + 1;
  int height = gl_height();
  fl_font(e.fontId, (int)(e.fontSize * f));
  int h = (int)(height * f);
  int descent = fl_descent();
  return {(int)(width * f), h, descent, 0., (double)(h - descent)};
}

void drawContextFltkStringTexture::rasterise(const std::vector<slot> &slots,
                                             double f, int w, int h,
                                             unsigned char *image)
{
  Fl_Offscreen offscreen = fl_create_offscreen(w, h);
  fl_begin_offscreen(offscreen);
  fl_color(0, 0, 0);
  fl_rectf(0, 0, w, h);
  fl_color(255, 255, 255);
  for(const slot &s : slots) {
    fl_push_clip(s.x, s.y, s.w, s.h);
    fl_font(s.e->fontId, (int)(s.e->fontSize * f));
    fl_draw(s.e->text.c_str(), (int)(s.x - s.shift + s.ext.penX),
            (int)(s.y + s.ext.penY));
    fl_pop_clip();
  }
  uchar *data = fl_read_image(nullptr, 0, 0, w, h);
  fl_end_offscreen();
  fl_delete_offscreen(offscreen);
  for(int i = 0; i < w * h; i++) image[i] = data[3 * i];
  delete[] data;
}

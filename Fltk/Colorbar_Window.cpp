// $Id: Colorbar_Window.cpp,v 1.36 2003-12-08 19:18:13 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

// This class was inspired by the colorbar widget provided in Vis5d, a
// program for visualizing five dimensional gridded data sets
// Copyright (C) 1990 - 1995 Bill Hibbard, Brian Paul, Dave Santek,
// and Andre Battaiola.
   
#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "GUI.h"
#include "ColorTable.h"
#include "Colorbar_Window.h"
#include "Context.h"

extern Context_T CTX;

#define UNDEFINED   0
#define EPS         1.e-10

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 0)
#define fl_contrast contrast
#endif

// This file defines the Colorbar_Window class (subclass of Fl_Window)

// The constructor

Colorbar_Window::Colorbar_Window(int x, int y, int w, int h, const char *l)
  : Fl_Window(x, y, w, h, l)
{
  ct = NULL;
  label = NULL;
  help_flag = 1;
  font_height = CTX.fontsize;
  marker_height = font_height;
  wedge_height = marker_height;
  marker_pos = 0;
  minval = maxval = 0.0;
}


// rgb on [0, 1], sv returned on [0, 1] and h on [0, 6]. 
// Exception: h is returned UNDEFINED if S==0.

#define RETURN_HSV(h,s,v) {*H=h; *S=s; *V=v; return;}

static void RGB_to_HSV(double R, double G, double B,
                       double *H, double *S, double *V)
{
  double v, x, f;
  int i;

  x = DMIN(DMIN(R, G), B);
  v = DMAX(DMAX(R, G), B);
  if(v == x)
    RETURN_HSV(UNDEFINED, 0, v);
  f = (R == x) ? G - B : ((G == x) ? B - R : R - G);
  i = (R == x) ? 3 : ((G == x) ? 5 : 1);
  RETURN_HSV(i - f / (v - x), (v - x) / v, v);
}

// h given on [0, 6] or UNDEFINED. s and v given on [0, 1].      
// rgb each returned on [0, 1].

#define RETURN_RGB(r,g,b) {*R=r; *G=g; *B=b; return;}

static void HSV_to_RGB(double H, double S, double V,
                       double *R, double *G, double *B)
{
  double m, n, f;
  int i;

  if(H == UNDEFINED)
    RETURN_RGB(V, V, V);
  i = (int)floor(H);
  f = H - i;
  if(!(i & 1))
    f = 1 - f;  // if i is even
  m = V * (1 - S);
  n = V * (1 - S * f);

  switch (i) {
  case 6:
  case 0:
    RETURN_RGB(V, n, m);
  case 1:
    RETURN_RGB(n, V, m);
  case 2:
    RETURN_RGB(m, V, n);
  case 3:
    RETURN_RGB(m, n, V);
  case 4:
    RETURN_RGB(n, m, V);
  case 5:
    RETURN_RGB(V, m, n);
  }
}


// Convert window X coordinate to color table index

int Colorbar_Window::x_to_index(int x)
{
  int index;
  index = (int)(x * (float)ct->size / (float)w());
  if(index < 0)
    index = 0;
  else if(index >= ct->size)
    index = ct->size - 1;
  return index;
}

// Convert color table index to window X coordinate

int Colorbar_Window::index_to_x(int index)
{
  int x;
  x = (int)(index * (float)w() / (float)(ct->size - 1));
  if(x >= w())
    x = w() - 1;
  return x;
}

// Convert a color intensity to a window Y coordinate

int Colorbar_Window::intensity_to_y(int intensity)
{
  int y;
  y = (int)(wedge_y - intensity * (float)wedge_y / 255.);
  if(y < 0)
    y = 0;
  else if(y >= wedge_y)
    y = wedge_y - 1;
  return y;
}

// Convert a window Y coordinate to a color intensity

int Colorbar_Window::y_to_intensity(int y)
{
  int intensity;
  intensity = (int)((wedge_y - y) * 255. / (float)wedge_y);
  if(intensity < 0)
    intensity = 0;
  else if(intensity > 255)
    intensity = 255;
  return intensity;
}

// Redraw part of the Colorbar_Window (between a and b)

void Colorbar_Window::redraw_range(int a, int b)
{
  int i;
  int x, y, px = 0, py = 0;
  int x1, y1, x2, y2;
  int intensity = 0;
  double H, S, V;

  make_current();

  if(a < 0)
    a = 0;
  if(b >= ct->size)
    b = ct->size - 1;

  // calculate region to update
  x1 = index_to_x(a);
  x2 = index_to_x(b);
  y1 = intensity_to_y(255);
  y2 = intensity_to_y(0);

  // erase region
  fl_color(color_bg);
  fl_rectf(x1, y1, x2 - x1 + 1, y2 - y1 + 1);

  // redraw region of entries in interval [a,b]
  if(a > 0)
    a--;
  if(b < ct->size - 1)
    b++;

  // draw red or hue levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB)
      intensity = UNPACK_RED(ct->table[i]);
    else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_HSV) {
      RGB_to_HSV(UNPACK_RED(ct->table[i]) / 255.,
                 UNPACK_GREEN(ct->table[i]) / 255.,
                 UNPACK_BLUE(ct->table[i]) / 255., &H, &S, &V);
      intensity = (int)(H / 6. * 255. + EPS);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_RED);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw green or saturation levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB)
      intensity = UNPACK_GREEN(ct->table[i]);
    else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_HSV) {
      RGB_to_HSV(UNPACK_RED(ct->table[i]) / 255.,
                 UNPACK_GREEN(ct->table[i]) / 255.,
                 UNPACK_BLUE(ct->table[i]) / 255., &H, &S, &V);
      intensity = (int)(S * 255.);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_GREEN);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw blue or value levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB)
      intensity = UNPACK_BLUE(ct->table[i]);
    else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_HSV) {
      RGB_to_HSV(UNPACK_RED(ct->table[i]) / 255.,
                 UNPACK_GREEN(ct->table[i]) / 255.,
                 UNPACK_BLUE(ct->table[i]) / 255., &H, &S, &V);
      intensity = (int)(V * 255.);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_BLUE);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw alpha levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    y = intensity_to_y(UNPACK_ALPHA(ct->table[i]));
    if(i != a) {
      fl_color(fl_contrast(FL_BLACK, color_bg));
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw the color bar
  for(x = x1; x <= x2; x++) {
    int r, g, b;
    unsigned int color;
    i = x_to_index(x);
    color = ct->table[i];
    r = UNPACK_RED(color);
    g = UNPACK_GREEN(color);
    b = UNPACK_BLUE(color);
    fl_color(r, g, b);
    fl_line(x, wedge_y, x, wedge_y + wedge_height - 1);
  }

  // print colortable mode and help
  fl_font(FL_HELVETICA, font_height);
  fl_color(fl_contrast(FL_BLACK, color_bg));
  int xx0 = 10, xx1 = 12 * font_height, yy0 = 10;
  if(help_flag) {
    i = 0;
    fl_draw("1, 2, ..., 8", xx0, yy0 + (i + 1) * font_height);
    fl_draw("select predefined colormap", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("mouse1", xx0, yy0 + (i + 1) * font_height);
    fl_draw("draw red or hue channel", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("mouse2", xx0, yy0 + (i + 1) * font_height);
    fl_draw("draw green or saturation channel", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("mouse3", xx0, yy0 + (i + 1) * font_height);
    fl_draw("draw blue or value channel", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("Ctrl+mouse1", xx0, yy0 + (i + 1) * font_height);
    fl_draw("draw alpha channel", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("c, p, r", xx0, yy0 + (i + 1) * font_height);
    fl_draw("copy, paste or reset colormap", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("m", xx0, yy0 + (i + 1) * font_height);
    fl_draw("toggle RGB/HSV mode", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("left, right", xx0, yy0 + (i + 1) * font_height);
    fl_draw("move colormap", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("Ctrl+left, Ctrl+right", xx0, yy0 + (i + 1) * font_height);
    fl_draw("rotate colormap", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("up, down", xx0, yy0 + (i + 1) * font_height);
    fl_draw("modify color curvature", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("Ctrl+up, Ctrl+down", xx0, yy0 + (i + 1) * font_height);
    fl_draw("incr. or decr. alpha channel", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("i, Ctrl+i", xx0, yy0 + (i + 1) * font_height);
    fl_draw("invert x or y range", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("b, Ctrl+b", xx0, yy0 + (i + 1) * font_height);
    fl_draw("increase or decrease gamma", xx1, yy0 + (i + 1) * font_height);
    i++;
    fl_draw("h", xx0, yy0 + (i + 1) * font_height);
    fl_draw("show this help message", xx1, yy0 + (i + 1) * font_height);
    i++;
  }
  else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB)
    fl_draw("RGB", xx0, yy0 + font_height);
  else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_HSV)
    fl_draw("HSV", xx0, yy0 + font_height);
}


// Redraw the marker and the text

void Colorbar_Window::redraw_marker()
{
  int x, y0, y1;
  char str[50];
  float val;

  make_current();

  y0 = marker_y;
  y1 = h() - 1;

  fl_color(color_bg);
  fl_rectf(0, y0, w(), y1 - y0 + 1);

  // draw marker below color wedge
  x = index_to_x(marker_pos);
  fl_color(fl_contrast(FL_BLACK, color_bg));
  fl_line(x, marker_y, x, marker_y + marker_height);
  fl_line(x, marker_y, x - 3, marker_y + 6);
  fl_line(x, marker_y, x + 3, marker_y + 6);

  // draw marker value
  fl_font(FL_HELVETICA, font_height);
  val =
    minval + (maxval - minval) * ((float)marker_pos / (float)(ct->size - 1));
  sprintf(str, "%g", val);
  fl_draw(str, 10, label_y);
}

// Draw everything

void Colorbar_Window::draw()
{
  if(ct) {
    label_y = h() - 5;
    marker_y = label_y - marker_height - font_height;
    wedge_y = marker_y - wedge_height;
    color_bg = fl_color_cube(UNPACK_RED(CTX.color.bg) * FL_NUM_RED / 256,
                             UNPACK_GREEN(CTX.color.bg) * FL_NUM_GREEN / 256,
                             UNPACK_BLUE(CTX.color.bg) * FL_NUM_BLUE / 256);
    redraw_range(0, ct->size - 1);
    redraw_marker();
  }
}

// Update

void Colorbar_Window::update(char *name, float min, float max,
                             GmshColorTable * table, int *changed)
{
  label = name;
  ct = table;
  viewchanged = changed;
  minval = min;
  maxval = max;
  redraw();
}

// Handle

int Colorbar_Window::handle(int event)
{
  static int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
  static int pentry, move_marker;
  int i, ibut, xpos, ypos, modify, entry, compute;

  modify = 0;
  compute = 0;

  switch (event) {

  case FL_ENTER:
    take_focus();       //force keyboard focus on the ColorbarWindow    
    return 1;

  case FL_LEAVE:
  case FL_FOCUS:
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    if(Fl::test_shortcut('0')) {
      ColorTable_InitParam(0, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('1')) {
      ColorTable_InitParam(1, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('2')) {
      ColorTable_InitParam(2, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('3')) {
      ColorTable_InitParam(3, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('4')) {
      ColorTable_InitParam(4, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('5')) {
      ColorTable_InitParam(5, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('6')) {
      ColorTable_InitParam(6, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('7')) {
      ColorTable_InitParam(7, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('8')) {
      ColorTable_InitParam(8, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('9')) {
      ColorTable_InitParam(9, ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('c')) {
      ColorTable_Copy(ct);
    }
    else if(Fl::test_shortcut('p')) {
      ColorTable_Paste(ct);
      draw();
    }
    else if(Fl::test_shortcut('h')) {
      help_flag = !help_flag;
      draw();
    }
    else if(Fl::test_shortcut('r')) {
      ColorTable_InitParam(ct->ipar[COLORTABLE_NUMBER], ct);
      compute = 1;
    }
    else if(Fl::test_shortcut('m')) {
      if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB)
        ct->ipar[COLORTABLE_MODE] = COLORTABLE_HSV;
      else
        ct->ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
      draw();
    }
    else if(Fl::test_shortcut('i')) {
      ct->ipar[COLORTABLE_SWAP] = !ct->ipar[COLORTABLE_SWAP];
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + 'i')) {
      ct->ipar[COLORTABLE_INVERT] = !ct->ipar[COLORTABLE_INVERT];
      compute = 1;
    }
    else if(Fl::test_shortcut('b')) {
      ct->fpar[COLORTABLE_BETA] += 0.05;
      if(ct->fpar[COLORTABLE_BETA] > 1.0)
        ct->fpar[COLORTABLE_BETA] = 1.0;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + 'b')) {
      ct->fpar[COLORTABLE_BETA] -= 0.05;
      if(ct->fpar[COLORTABLE_BETA] < -1.0)
        ct->fpar[COLORTABLE_BETA] = -1.0;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_Left)) {
      ct->fpar[COLORTABLE_BIAS] -= 0.05;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + FL_Left)) {
      ct->ipar[COLORTABLE_ROTATE] += 5;
      if(ct->ipar[COLORTABLE_ROTATE] > ct->size - 1)
        ct->ipar[COLORTABLE_ROTATE] -= ct->size - 1;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_Right)) {
      ct->fpar[COLORTABLE_BIAS] += 0.05;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + FL_Right)) {
      ct->ipar[COLORTABLE_ROTATE] -= 5;
      if(ct->ipar[COLORTABLE_ROTATE] < -(ct->size - 1))
        ct->ipar[COLORTABLE_ROTATE] += ct->size - 1;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_Up)) {
      ct->fpar[COLORTABLE_CURVE] -= 0.05;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + FL_Up)) {
      ct->fpar[COLORTABLE_ALPHAPOW] += 0.05;
      if(ct->fpar[COLORTABLE_ALPHAPOW] > 1.0)
        ct->fpar[COLORTABLE_ALPHAPOW] = 1.0;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_Down)) {
      ct->fpar[COLORTABLE_CURVE] += 0.05;
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + FL_Down)) {
      ct->fpar[COLORTABLE_ALPHAPOW] -= 0.05;
      if(ct->fpar[COLORTABLE_ALPHAPOW] < 0.0)
        ct->fpar[COLORTABLE_ALPHAPOW] = 0.0;
      compute = 1;
    }
    else {
      return Fl_Window::handle(event);
    }

    if(compute) {
      ColorTable_Recompute(ct);
      draw();
      *viewchanged = 1;
      set_changed();
    }
    return 1;

  case FL_PUSH:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    if(help_flag) {
      help_flag = 0;
      draw();
    }
    // change color function or marker position
    if(ypos < wedge_y)
      move_marker = 0;
    else
      move_marker = 1;

    // determine which curve to modify
    if(Fl::event_state(FL_CTRL))
      p4 = 1;
    else if(ibut == 1 && !Fl::event_state(FL_SHIFT)
            && !Fl::event_state(FL_ALT))
      p1 = 1;
    else if(ibut == 2 || (ibut == 1 && Fl::event_state(FL_SHIFT)))
      p2 = 1;
    else
      p3 = 1;
    pentry = x_to_index(xpos);
    modify = 1;
    break;

  case FL_RELEASE:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    break;

  case FL_DRAG:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    modify = 1;
    break;

  default:
    // don't know what to do with the event: passing it to parent
    return Fl_Window::handle(event);

  }

  // Modify one or more of the color curves

  if(modify && (p1 || p2 || p3 || p4)) {
    // calculate which entry in color table to change
    entry = x_to_index(xpos);
    // update
    if(move_marker) {
      // changing marker position
      marker_pos = entry;
      redraw_marker();
    }
    else {
      // changing color graph
      int a, b, value;

      *viewchanged = 1;
      set_changed();

      value = y_to_intensity(ypos);

      if(pentry <= entry) {
        a = pentry;
        b = entry;
      }
      else {
        a = entry;
        b = pentry;
      }

      // update entries from 'pentry' to 'entry'
      for(i = a; i <= b; i++) {
        int red, green, blue, alpha;
        double R, G, B, H, S, V;

        red = UNPACK_RED(ct->table[i]);
        green = UNPACK_GREEN(ct->table[i]);
        blue = UNPACK_BLUE(ct->table[i]);
        alpha = UNPACK_ALPHA(ct->table[i]);

        if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_RGB) {
          if(p1) {
            red = value;
          }
          if(p2) {
            green = value;
          }
          if(p3) {
            blue = value;
          }
          if(p4) {
            alpha = value;
          }
        }
        else if(ct->ipar[COLORTABLE_MODE] == COLORTABLE_HSV) {
          RGB_to_HSV((double)red / 255., (double)green / 255.,
                     (double)blue / 255., &H, &S, &V);
          if(p1) {
            H = 6. * (double)value / 255. + EPS;
          }
          if(p2) {
            S = (double)value / 255.;
          }
          if(p3) {
            V = (double)value / 255.;
          }
          if(p4) {
            alpha = value;
          }
          HSV_to_RGB(H, S, V, &R, &G, &B);
          red = (int)(255 * R);
          green = (int)(255 * G);
          blue = (int)(255 * B);
        }

        ct->table[i] = PACK_COLOR(red, green, blue, alpha);
      }

      // redraw the color curves
      if(pentry < entry)
        redraw_range(pentry - 1, entry + 1);
      else
        redraw_range(entry - 1, pentry + 1);

      pentry = entry;

    }
    return 1;
  }

  return 1;
}

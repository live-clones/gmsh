#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

class Opengl_Window : public Fl_Gl_Window {
  void draw();
  void draw_overlay();
  int handle(int);

  // new
  void clear_overlay();

public:
  Opengl_Window(int x,int y,int w,int h,const char *l=0)
    : Fl_Gl_Window(x, y, w, h, l) {}
};

#endif

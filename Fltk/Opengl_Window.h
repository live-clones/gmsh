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

// This dummy box class permits to define a box widget that will not
// eat the FL_ENTER/FL_LEAVE events (the new Box widget in fltk >1.1
// does that, so that our Opengl_Window->handle() was not called each
// time the mouse moved...)
//
// There is probably a better solution...

class Dummy_Box : public Fl_Box {
  int handle(int){ return 0; }; // always!
public:
  Dummy_Box(int x,int y,int w,int h,const char *l=0)
    : Fl_Box(x, y, w, h, l) {}
};

#endif

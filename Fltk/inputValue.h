// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _INPUT_VALUE_H_
#define _INPUT_VALUE_H_

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>

// this is basically the same as Fl_Value_Input, except that we force the
// underlying input to always accept floats (whatever the step value)

class inputValue : public Fl_Value_Input
{
 private:
  static void new_input_cb(Fl_Widget*,void*);
 public:
  inputValue(int x, int y, int w, int h, const char *l=0);
  virtual int format(char *buffer){ return sprintf(buffer, "%g", value()); }
  int handle(int event);
};

#endif

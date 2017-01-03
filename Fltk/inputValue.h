// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _INPUT_VALUE_H_
#define _INPUT_VALUE_H_

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>

// same as FL_Value_Input, but prints values in engineering notation

class inputValue : public Fl_Value_Input
{
 public:
  inputValue(int x, int y, int w, int h, const char *l=0) :
    Fl_Value_Input(x, y, w, h, l) {}
  virtual int format(char *buffer){ return sprintf(buffer, "%g", value()); }
};


// same as inputValue, but forces the underlying FL_Value_Input to always accept
// floats (whatever the step value)

class inputValueFloat : public inputValue
{
 private:
  static void new_input_cb(Fl_Widget*,void*);
 public:
  inputValueFloat(int x, int y, int w, int h, const char *l=0);
  int handle(int event);
};

#endif

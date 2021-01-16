// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef INPUT_VALUE_H
#define INPUT_VALUE_H

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>
#include <string>

// same as FL_Value_Input, but prints values in engineering notation

class inputValue : public Fl_Value_Input {
private:
  std::string _number_format;

public:
  inputValue(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Value_Input(x, y, w, h, l)
  {
  }
  void numberFormat(const std::string &fmt) { _number_format = fmt; }
  virtual int format(char *buffer)
  {
    if(_number_format.empty()) { return sprintf(buffer, "%g", value()); }
    else {
      if(_number_format.find("d") != std::string::npos ||
         _number_format.find("u") != std::string::npos)
        return sprintf(buffer, _number_format.c_str(), (int)value());
      else
        return sprintf(buffer, _number_format.c_str(), value());
    }
  }
};

// same as inputValue, but forces the underlying FL_Value_Input to always accept
// floats (whatever the step value)

class inputValueFloat : public inputValue {
private:
  static void new_input_cb(Fl_Widget *, void *);

public:
  inputValueFloat(int x, int y, int w, int h, const char *l = nullptr);
  int handle(int event);
};

#endif

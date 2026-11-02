// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef INPUT_VALUE_H
#define INPUT_VALUE_H

#include <FL/Fl.H>
#include <FL/Fl_Value_Input.H>
#include <string>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <string.h>

// A value written in a buffer of the given size with the NumberFormat of a
// ONELAB parameter, which comes from the user's files: a format with anything
// else than exactly one conversion of a number (%d, %.3f, %g...) is replaced
// by %g, as printf would read other arguments than the value
inline int formatNumber(char *buffer, int size, const std::string &fmt,
                        double value)
{
  int conversions = 0;
  char type = 0;
  for(std::size_t i = 0; i < fmt.size(); i++) {
    if(fmt[i] != '%') continue;
    if(i + 1 < fmt.size() && fmt[i + 1] == '%') {
      i++;
      continue;
    }
    std::size_t j = i + 1;
    while(j < fmt.size() && fmt[j] && strchr("-+ #0123456789.", fmt[j])) j++;
    // %lf is %f; %ld would read a long
    bool l = (j < fmt.size() && fmt[j] == 'l');
    if(l) j++;
    if(j < fmt.size() && fmt[j] && strchr(l ? "eEfFgG" : "eEfFgGdiu", fmt[j])) {
      type = fmt[j];
      conversions++;
    }
    else
      conversions = 2; // %s, %*d, %ld...
    i = j;
  }
  int n;
  // not a number has no integer to convert to
  if(conversions != 1 || (value != value && strchr("diu", type)))
    n = snprintf(buffer, size, "%g", value);
  else if(strchr("diu", type)) // within the range of an int
    n = snprintf(
      buffer, size, fmt.c_str(),
      (int)std::max(std::min(value, (double)INT_MAX), (double)INT_MIN));
  else
    n = snprintf(buffer, size, fmt.c_str(), value);
  return (n < 0) ? 0 : (n < size ? n : size - 1);
}

// same as FL_Value_Input, but prints values with the NumberFormat of a ONELAB
// parameter (see formatNumber())

class inputValue : public Fl_Value_Input {
private:
  std::string _number_format;

public:
  inputValue(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Value_Input(x, y, w, h, l)
  {
  }
  void numberFormat(const std::string &fmt) { _number_format = fmt; }
  // FLTK's buffer holds 128 characters
  virtual int format(char *buffer)
  { return formatNumber(buffer, 128, _number_format, value()); }
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

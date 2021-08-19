// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <ostream>
#include <sstream>
#include <iostream>

#include "GmshMessage.h"

#include "prettyprint.hpp"

namespace hbl {

  /* sformat inspired from variadic printf at
   * https://web.archive.org/web/20131018185034/http://www.generic-programming.org/~dgregor/cpp/variadic-templates.html */
  static inline void sformat(std::ostream& out, const char* s) {
    while (*s) {
      if (*s == '{' && *++s != '}') 
        throw std::runtime_error("invalid format string: missing arguments");
      out << *s++;
    }
  }

  template<typename T, typename... Args>
    static void sformat(std::ostream& out, const char* s, const T& value, const Args&... args) {
      while (*s) {
        if (*s == '{' && *++s == '}') {
          out << value;
          return sformat(out, ++s, args...);
        }
        out << *s++;
      }
      printf("! sformat problem, input: %s\n, extra arguments provided to sformat",*s);
      //throw std::runtime_error("extra arguments provided to printf");
    }

  template <typename... Args>
    void error(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      Msg::Error("%s", stream.str().c_str());
    }

  template <typename... Args>
    void warn(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      Msg::Warning("%s", stream.str().c_str());
    }

  template <typename... Args>
    void info(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      Msg::Info("%s", stream.str().c_str());
    }

  template <typename... Args>
    void debug(const char* format, const Args & ... args) {
      std::ostringstream stream;
      sformat(stream, format, args...);
      Msg::Debug("%s", stream.str().c_str());
    }
}

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <cstdio>
#include <cstring>
#include "GmshMessage.h"

// Overload the printf statements in Chaco to write using Msg::Direct in gmsh

extern "C" int Gmsh_printf(const char *fmt, ...)
{
  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  // deal with multi-line messages
  const char *const last = str + std::max(0, (int)std::strlen(str) - 1);
  char buf[1024];
  char *p = std::strtok(str, "\n");
  if(p) {
    // If more than 1 leading '\n', print a blank line
    if(p - str > 1) Msg::Direct(" ");
    std::strcpy(buf, p);
    Msg::Direct(buf);
    // New line for each interior '\n'
    while((p = std::strtok(NULL, "\n"))) {
      std::strcpy(buf, p);
      Msg::Direct(buf);
    }
  }
  // If more than 1 trailing '\n', or only "\n" in the string, print a blank
  // line.
  if(*last == '\n') Msg::Direct(" ");
  return 0;
}

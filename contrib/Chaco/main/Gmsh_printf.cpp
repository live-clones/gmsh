// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "../../../Common/Message.h"

// Overload the printf statements in Chaco to write using Msg::Direct in gmsh

extern "C" int Gmsh_printf(const char *fmt, ...)
{
  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  Msg::Direct(3, str);
}

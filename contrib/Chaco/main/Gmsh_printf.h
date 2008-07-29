// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

// Overload the printf statements in Chaco to write using Msg::Direct gmsh

#ifndef _GMSH_PRINTF_H_
#define _GMSH_PRINTF_H_

#define printf Gmsh_printf
int Gmsh_printf(const char *fmt, ...);

#endif

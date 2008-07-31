/* Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
 *
 * See the LICENSE.txt file for license information. Please report all
 * bugs and problems to <gmsh@geuz.org>.
 */
#ifndef _GMSH_PRINTF_H_
#define _GMSH_PRINTF_H_

/* Overload the printf statements in Chaco to write using Msg::Direct gmsh */
#define printf(fmt, ...) Gmsh_printf(fmt, ##__VA_ARGS__)
/* #define fprintf(file, fmt, ...) Gmsh_printf(fmt, ##__VA_ARGS__) */
int Gmsh_printf(const char *fmt, ...);

#endif

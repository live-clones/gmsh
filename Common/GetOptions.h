#ifndef _GET_OPTIONS_H_
#define _GET_OPTIONS_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

extern char gmsh_progname[], gmsh_copyright[], gmsh_version[], gmsh_os[];
extern char gmsh_date[], gmsh_host[], gmsh_packager[], gmsh_url[];
extern char gmsh_email[], gmsh_gui[];

extern char *TheFileNameTab[MAX_OPEN_FILES], *TheBgmFileName, *TheOptString;

void Get_Options(int argc, char *argv[], int *nbfiles);
void Print_Usage(char *name);

#endif

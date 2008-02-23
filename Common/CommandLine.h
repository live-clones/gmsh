#ifndef _COMMAND_LINE_H_
#define _COMMAND_LINE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

extern char gmsh_progname[], gmsh_copyright[], gmsh_version[], gmsh_os[];
extern char gmsh_date[], gmsh_host[], gmsh_packager[], gmsh_url[];
extern char gmsh_email[], gmsh_gui[], gmsh_options[], gmsh_license[];

void Get_Options(int argc, char *argv[]);
void Print_Usage(const char *name);

char *Get_BuildOptions();

int Get_GmshMajorVersion();
int Get_GmshMinorVersion();
int Get_GmshPatchVersion();
const char *Get_GmshExtraVersion();
const char *Get_GmshVersion();
const char *Get_GmshBuildDate();
const char *Get_GmshBuildHost();
const char *Get_GmshPackager();
const char *Get_GmshBuildOS();
const char *Get_GmshShortLicense();

#endif

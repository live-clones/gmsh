// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _COMMAND_LINE_H_
#define _COMMAND_LINE_H_

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
const char *Get_GmshBuildOptions();

void Print_Usage(const char *name);
void Get_Options(int argc, char *argv[]);

#endif

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _COMMAND_LINE_H_
#define _COMMAND_LINE_H_

int GetGmshMajorVersion();
int GetGmshMinorVersion();
int GetGmshPatchVersion();
const char *GetGmshExtraVersion();
const char *GetGmshVersion();
const char *GetGmshBuildDate();
const char *GetGmshBuildHost();
const char *GetGmshPackager();
const char *GetGmshBuildOS();
const char *GetGmshShortLicense();
const char *GetGmshBuildOptions();

void PrintUsage(const char *name);
void GetOptions(int argc, char *argv[]);

#endif

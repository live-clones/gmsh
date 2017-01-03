// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _COMMAND_LINE_H_
#define _COMMAND_LINE_H_

#include <string>

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

std::vector<std::pair<std::string, std::string> > GetUsage();
std::vector<std::pair<std::string, std::string> > GetShortcutsUsage(const std::string &ctrl="");
std::vector<std::pair<std::string, std::string> > GetMouseUsage();
void PrintUsage(const std::string &name);
void GetOptions(int argc, char *argv[]);

#endif

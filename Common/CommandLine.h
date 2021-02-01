// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

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
std::vector<std::pair<std::string, std::string> >
GetShortcutsUsage(const std::string &ctrl = "");
std::vector<std::pair<std::string, std::string> > GetMouseUsage();
void PrintUsage(const std::string &name);
std::vector<std::string> GetBuildInfo();
void PrintBuildInfo();
void GetOptions(bool readConfigFiles, bool exitOnError);

#endif

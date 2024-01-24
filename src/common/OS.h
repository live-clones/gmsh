// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OS_H
#define OS_H

#include <string>
#include <stdio.h>

FILE *Fopen(const char *f, const char *mode);
std::string GetEnvironmentVar(const std::string &var);
void SetEnvironmentVar(const std::string &var, const std::string &val);
void SleepInSeconds(double s);
void CheckResources();
double Cpu();
double TotalRam();
double TimeOfDay();
std::size_t GetMemoryUsage();
int GetProcessId();
std::string GetExecutableFileName();
std::string GetAbsolutePath(const std::string &fileName);
std::string GetHostName();
int UnlinkFile(const std::string &fileName);
int StatFile(const std::string &fileName);
int KillProcess(int pid);
int CreateSingleDir(const std::string &dirName);
void CreatePath(const std::string &fullPath);
int SystemCall(const std::string &command, bool blocking = false);
int SystemCallExe(const std::string &exe, const std::string &argsOrCommand,
                  bool blocking = false);
void RedirectIOToConsole();
void UnzipFile(const std::string &fileName, const std::string &prependDir = "");

#endif

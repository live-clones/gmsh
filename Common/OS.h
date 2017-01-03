// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _OS_H_
#define _OS_H_

#include <string>
#include <stdio.h>

FILE *Fopen(const char* f, const char *mode);
const char *GetEnvironmentVar(const char *var);
void SetEnvironmentVar(const char *var, const char *val);
double GetTimeInSeconds();
void SleepInSeconds(double s);
void CheckResources();
double Cpu();
double TotalRam();
double TimeOfDay();
long GetMemoryUsage();
int GetProcessId();
std::string GetExecutableFileName();
std::string GetAbsolutePath(const std::string &fileName);
std::string GetHostName();
int UnlinkFile(const std::string &fileName);
int StatFile(const std::string &fileName);
int KillProcess(int pid);
int CreateSingleDir(const std::string &dirName);
void CreatePath(const std::string &fullPath);
int SystemCall(const std::string &command, bool blocking=false);
int SystemCallExe(const std::string &exe, const std::string &argsOrCommand,
                  bool blocking=false);
std::string GetCurrentWorkdir();
void RedirectIOToConsole();
void UnzipFile(const std::string &fileName, const std::string &prependDir="");

#endif

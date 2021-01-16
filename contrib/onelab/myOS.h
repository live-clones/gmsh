// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MY_OS_H
#define MY_OS_H

#include <string>

const char *GetEnvironmentVar(const char *var);
double TimeOfDay();
void SleepInSeconds(double s);
void CheckResources();
double Cpu();
long GetMemoryUsage();
int GetProcessId();
std::string GetHostName();
int UnlinkFile(const std::string &fileName);
int StatFile(const std::string &fileName);
int KillProcess(int pid);
int SystemCall(const std::string &command, bool blocking = false);
std::string getCurrentWorkdir();

#endif

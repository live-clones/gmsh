// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OS_H_
#define _OS_H_

#include <string>

const char *GetEnvironmentVariable(const char *var);
double GetTimeInSeconds();
void SleepInSeconds(double s);
void CheckResources();
double Cpu();
int GetProcessId();
std::string GetHostName();
int UnlinkFile(std::string fileName);
int StatFile(std::string fileName);
int KillProcess(int pid);
int SystemCall(std::string command);

#endif

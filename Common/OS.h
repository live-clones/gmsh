// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OS_H_
#define _OS_H_

#include <string>

double GetTimeInSeconds();
void SleepInSeconds(double s);
void GetResources(double *s, long *mem);
void CheckResources();
double Cpu();
int GetProcessId();
std::string GetHostName();
int UnlinkFile(const char *name);
int StatFile(const char *filename);
int KillProcess(int pid);
int SystemCall(const char *command);

#endif

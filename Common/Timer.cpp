// $Id: Timer.cpp,v 1.23 2006-02-26 00:40:29 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#if !defined(WIN32) || defined(__CYGWIN__)

#include <unistd.h>
#include <time.h> // for sgi and maybe others
#include <sys/time.h>
#include <sys/resource.h>

#else // pure windows

#include <windows.h>

#endif

#if defined(__APPLE__)
#define RUSAGE_SELF      0
#define RUSAGE_CHILDREN -1
#endif

double GetTimeInSeconds()
{
#if !defined(WIN32) || defined(__CYGWIN__)
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  double t = (double)tp.tv_sec + 1.e-6 * (double)tp.tv_usec;
  return t;
#else
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);
  double t =  1.e-7 * 4294967296. * (double)ft.dwHighDateTime +
              1.e-7 * (double)ft.dwLowDateTime;
  return t;
#endif
}

void SleepInSeconds(double s)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  usleep((long)(1.e6 * s));
#else
  Sleep((long)(1.e3 * s));
#endif
}

void GetResources(double *s, long *mem)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  static struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  *s = (double)r.ru_utime.tv_sec + 1.e-6 * (double)r.ru_utime.tv_usec;
  *mem = (long)r.ru_maxrss;
#else
  FILETIME creation, exit, kernel, user;
  if(GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user)){
    *s = 1.e-7 * 4294967296. * (double)user.dwHighDateTime +
         1.e-7 * (double)user.dwLowDateTime;
  }
  *mem = 0;
#endif
}

double Cpu()
{
  long mem = 0;
  double s = 0.;
  GetResources(&s, &mem);
  return s;
}

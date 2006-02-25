// $Id: Timer.cpp,v 1.20 2006-02-25 07:07:29 geuzaine Exp $
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

#include <time.h> // FIXME: for sgi and maybe others
#include <sys/time.h>
#include <unistd.h>

double GetTimeInSeconds()
{
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  double t = (double)tp.tv_sec + 1.e-6 * (double)tp.tv_usec;
  return t;
}

void SleepInSeconds(double s)
{
  usleep((long)(1.e6 * s));
}

#else // pure windows

#include "Gmsh.h"
#include <windows.h>

double GetTimeInSeconds()
{
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);
  double t = 1.e2 * (double)ft.dwHighDateTime;
  return t;
}

void SleepInSeconds(double s)
{
  Sleep((long)(1.e3 * s));
}

#endif

// $Id: Timer.cpp,v 1.5 2002-05-18 07:17:59 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#if defined(WIN32) && !defined(__CYGWIN__)

long GetTime(){
  return 0;
}

#else

#include <sys/time.h>
#include <unistd.h>
long GetTime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

#endif

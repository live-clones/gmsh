// $Id: SafeIO.cpp,v 1.9 2006-11-27 22:22:08 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "SafeIO.h"
#include "Message.h"

/*
  Safe fprintf routine

  In a perfect world, one should use this routine. Unfortunately, it
  is very, very slow.

  We should use a macro, i.e.

    #define gprintf(...) { fprintf(__VA_ARGS__); ... }

  but but var args don't work with all C preprocessors.

  Bottom line: don't use safe_fprintf.
*/

int safe_fprintf(FILE * stream, char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  vfprintf(stream, fmt, args);
  va_end(args);

  if(ferror(stream)) {
    Msg(GERROR, strerror(errno));
    clearerr(stream);
    return 1;
  }

  return 0;
}

/* Safe fwrite routine */

int safe_fwrite(const void *ptr, size_t size, size_t nmemb, FILE * stream)
{
  size_t result = fwrite(ptr, size, nmemb, stream);

  if(result < nmemb) {
    if(result >= 0)     /* Partial write */
      Msg(GERROR, "Disk full");
    else
      Msg(GERROR, strerror(errno));
    if(fflush(stream) < 0)
      Msg(GERROR, "EOF reached");
    if(fclose(stream) < 0)
      Msg(GERROR, strerror(errno));
    return 1;
  }
  return 0;
}

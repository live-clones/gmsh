#ifndef _STRING_UTIL_H_
#define _STRING_UTIL_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <string.h>
#include <string>

void SwapBytes(char *array, int size, int n);
std::string ExtractDoubleQuotedString(const char *str, int len);
std::string SanitizeTeXString(const char *in, int equation);
void FixWindowsPath(const char *in, char *out);
void SplitFileName(const char *name, char *no_ext, char *ext, char *base);

#endif

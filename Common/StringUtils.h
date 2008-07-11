// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STRING_UTIL_H_
#define _STRING_UTIL_H_

#include <string.h>
#include <string>

void SwapBytes(char *array, int size, int n);
std::string ExtractDoubleQuotedString(const char *str, int len);
std::string SanitizeTeXString(const char *in, int equation);
void FixWindowsPath(const char *in, char *out);
void SplitFileName(const char *name, char *no_ext, char *ext, char *base);

#endif

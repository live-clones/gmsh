// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <string.h>
#include <string>
#include <vector>

void SwapBytes(char *array, int size, int n);
std::string ExtractDoubleQuotedString(const char *str, int len);
std::string SanitizeTeXString(const char *in, int equation);
std::string FixWindowsPath(const char *in);
std::string FixRelativePath(std::string reference, std::string in);
std::vector<std::string> SplitFileName(std::string fileName);
std::vector<std::string> SplitWhiteSpace(std::string in, unsigned int len);
void ReplaceMultiFormat(const char *in, const char *val, char *out);

#endif

// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
std::string FixWindowsPath(const std::string &in);
std::string FixRelativePath(const std::string &reference, const std::string &in);
std::vector<std::string> SplitFileName(const std::string &fileName);
std::string ConvertFileToString(const std::string &fileName);
void ReplaceSubStringInPlace(const std::string &olds, const std::string &news, 
                             std::string &str);
std::string ReplaceSubString(const std::string &olds, const std::string &news, 
                             const std::string &str);
void ConvertToHTML(std::string &in);

#endif

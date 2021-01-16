// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string.h>
#include <string>
#include <vector>

void SwapBytes(char *array, int size, int n);
std::string ExtractDoubleQuotedString(const char *str, int len);
std::string SanitizeTeXString(const char *in, int equation);
std::string FixWindowsPath(const std::string &in);
std::string FixRelativePath(const std::string &reference,
                            const std::string &in);
std::vector<std::string> SplitFileName(const std::string &fileName);
std::string GetFileNameWithoutPath(const std::string &fileName);
std::string ConvertFileToString(const std::string &fileName);
void ReplaceSubStringInPlace(const std::string &olds, const std::string &news,
                             std::string &str);
std::string ReplaceSubString(const std::string &olds, const std::string &news,
                             const std::string &str);
void ConvertToHTML(std::string &in);
bool SplitOptionName(const std::string &fullName, std::string &category,
                     std::string &name, int &index);
std::vector<std::string> SplitString(const std::string &msg, char separator,
                                     bool removeWhiteSpace = false);
std::string RemoveWhiteSpace(const std::string &s);

#endif

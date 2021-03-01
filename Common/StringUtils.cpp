// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <stdlib.h>
#include <regex>
#if defined(__CYGWIN__)
#include <sys/cygwin.h>
#endif
#include "StringUtils.h"
#include "GmshMessage.h"
#include "OS.h"

void SwapBytes(char *array, int size, int n)
{
  char *x = new char[size];
  for(int i = 0; i < n; i++) {
    char *a = &array[i * size];
    memcpy(x, a, size);
    for(int c = 0; c < size; c++) a[size - 1 - c] = x[c];
  }
  delete[] x;
}

std::string ExtractDoubleQuotedString(const char *str, int len)
{
  char *c = strstr((char *)str, "\"");
  if(!c) return "";
  std::string ret;
  for(int i = 1; i < len; i++) {
    if(c[i] == '"' || c[i] == EOF || c[i] == '\n' || c[i] == '\r') break;
    ret.push_back(c[i]);
  }
  return ret;
}

std::string SanitizeTeXString(const char *in, int equation)
{
  // if there is a '$' or a '\' in the string, assume the author knows
  // what he's doing:
  if(strstr(in, "$") || strstr(in, "\\")) return std::string(in);

  std::string out;

  if(equation) out.push_back('$');

  // otherwise, escape the following special characters:
  char bad[8] = {'%', '^', '#', '%', '&', '_', '{', '}'};
  while(*in) {
    for(std::size_t i = 0; i < sizeof(bad); i++) {
      if(*in == bad[i]) {
        out.push_back('\\');
        break;
      }
    }
    out.push_back(*in++);
  }

  if(equation) out.push_back('$');
  return out;
}

std::string FixWindowsPath(const std::string &in)
{
#if defined(__CYGWIN__)
  char tmp[1024];
  cygwin_conv_to_win32_path(in.c_str(), tmp);
  return std::string(tmp);
#else
  return in;
#endif
}

std::string FixRelativePath(const std::string &reference, const std::string &in)
{
  if(in.empty()) return "";

  if(in[0] == '/' || in[0] == '\\' ||
     (in.size() > 3 && in[1] == ':' && (in[2] == '/' || in[2] == '\\'))) {
    // do nothing: 'in' is an absolute path
    return in;
  }
  else {
    // append 'in' to the path of the reference file
    std::vector<std::string> split = SplitFileName(reference);
    return split[0] + in;
  }
}

std::vector<std::string> SplitFileName(const std::string &fileName)
{
  // JFR DO NOT CHANGE TO std::vector<std::string> s(3), it segfaults while
  // destructor si called
  std::vector<std::string> s;
  s.resize(3);
  if(fileName.size()) {
    // returns [path, baseName, extension]
    int idot = (int)fileName.find_last_of('.');
    int islash = (int)fileName.find_last_of("/\\");
    if(idot == (int)std::string::npos) idot = -1;
    if(islash == (int)std::string::npos) islash = -1;
    if(idot > 0) s[2] = fileName.substr(idot);
    if(islash > 0) s[0] = fileName.substr(0, islash + 1);
    s[1] =
      fileName.substr(s[0].size(), fileName.size() - s[0].size() - s[2].size());
  }
  return s;
}

std::string GetFileNameWithoutPath(const std::string &fileName)
{
  std::vector<std::string> s = SplitFileName(fileName);
  return s[1] + s[2];
}

std::string ConvertFileToString(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "r");
  if(!fp) return "";
  std::string out;
  char str[256];
  while(!feof(fp) && fgets(str, sizeof(str), fp)) out += str;
  fclose(fp);
  return out;
}

void ReplaceSubStringInPlace(const std::string &olds, const std::string &news,
                             std::string &str)
{
  while(1) {
    int pos = (int)str.find(olds.c_str());
    if(pos == (int)std::string::npos) break;
    str.replace(pos, olds.size(), news.c_str());
  }
}

std::string ReplaceSubString(const std::string &olds, const std::string &news,
                             const std::string &str)
{
  std::string copy(str);
  ReplaceSubStringInPlace(olds, news, copy);
  return copy;
}

void ConvertToHTML(std::string &str)
{
  ReplaceSubStringInPlace("<", "&lt;", str);
  ReplaceSubStringInPlace(">", "&gt;", str);
  ReplaceSubStringInPlace("\n\n", "<p>", str);
  ReplaceSubStringInPlace("\n", "<br>", str);
}

bool SplitOptionName(const std::string &fullName, std::string &category,
                     std::string &name, int &index)
{
  std::string::size_type d = fullName.find_first_of('.');
  if(d == std::string::npos) {
    name = fullName;
    return false;
  }
  category = fullName.substr(0, d);
  std::string::size_type b1 = fullName.find_first_of('[');
  std::string::size_type b2 = fullName.find_last_of(']');
  if(b1 != std::string::npos && b2 != std::string::npos) {
    std::string id = fullName.substr(b1 + 1, b2 - b1 - 1);
    index = atoi(id.c_str());
    category = fullName.substr(0, b1);
    name = fullName.substr(d + 1, b1 - d);
  }
  else {
    index = 0;
    name = fullName.substr(d + 1);
  }
  Msg::Debug("Decoded option name '%s' . '%s' (index %d)", category.c_str(),
             name.c_str(), index);
  return true;
}

std::string RemoveWhiteSpace(const std::string &s)
{
  std::regex r("\\s+");
  return std::regex_replace(s, r, "");
}

static std::string getNextTokenInString(const std::string &msg,
                                        std::string::size_type &first,
                                        char separator)
{
  if(first == std::string::npos) return "";
  std::string::size_type last = msg.find_first_of(separator, first);
  std::string next("");
  if(last == std::string::npos) {
    next = msg.substr(first);
    first = last;
  }
  else if(first == last) {
    next = "";
    first = last + 1;
  }
  else {
    next = msg.substr(first, last - first);
    first = last + 1;
  }
  return next;
}

std::vector<std::string> SplitString(const std::string &msg, char separator,
                                     bool removeWhiteSpace)
{
  std::vector<std::string> out;
  std::string::size_type first = 0;
  while(first != std::string::npos) {
    if(removeWhiteSpace)
      out.push_back(RemoveWhiteSpace
                    (getNextTokenInString(msg, first, separator)));
    else
      out.push_back(getNextTokenInString(msg, first, separator));
  }
  return out;
}

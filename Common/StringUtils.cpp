// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#if defined(__CYGWIN__)
#include <sys/cygwin.h>
#endif

#include "StringUtils.h"
#include "GmshMessage.h"

void SwapBytes(char *array, int size, int n)
{
  char *x = new char[size];
  for(int i = 0; i < n; i++) {
    char *a = &array[i * size];
    memcpy(x, a, size);
    for(int c = 0; c < size; c++)
      a[size - 1 - c] = x[c];
  }
  delete [] x;
}

std::string ExtractDoubleQuotedString(const char *str, int len)
{
  char *c = strstr((char*)str, "\"");
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
  if(strstr(in, "$") || strstr(in, "\\"))
    return std::string(in);

  std::string out;

  if(equation) out.push_back('$');

  // otherwise, escape the following special characters:
  char bad[8] = { '%', '^', '#', '%', '&', '_', '{', '}' };
  while(*in){
    for(unsigned int i = 0; i < sizeof(bad); i++){
      if(*in == bad[i]){
        out.push_back('\\');
        break;
      }
    }
    out.push_back(*in++);
  }

  if(equation) out.push_back('$');
  return out;
}

std::string FixWindowsPath(std::string in)
{
#if defined(__CYGWIN__)
  char tmp[1024];
  cygwin_conv_to_win32_path(in.c_str(), tmp);
  return std::string(tmp);
#else
  return in;
#endif
}

std::string FixRelativePath(std::string reference, std::string in)
{
  if(in.empty()) return "";

  if(in[0] == '/' || in[0] == '\\' || (in.size() > 2 && in[1] == ':')){
    // do nothing: 'in' is an absolute path
    return in;
  }
  else{
    // append 'in' to the path of the reference file
    std::vector<std::string> split = SplitFileName(reference);
    return split[0] + in;
  }
}

std::vector<std::string> SplitFileName(std::string fileName)
{
  // returns [path, baseName, extension]
  int idot = fileName.find_last_of('.');
  int islash = fileName.find_last_of("/\\");
  if(idot == (int)std::string::npos) idot = -1;
  if(islash == (int)std::string::npos) islash = -1;
  std::vector<std::string> s(3);
  if(idot > 0)
    s[2] = fileName.substr(idot);
  if(islash > 0)
    s[0] = fileName.substr(0, islash + 1);
  s[1] = fileName.substr(s[0].size(), fileName.size() - s[0].size() - s[2].size());
  return s;
}

std::vector<std::string> SplitWhiteSpace(std::string in, unsigned int len)
{
  std::vector<std::string> out(1);
  for(unsigned int i = 0; i < in.size(); i++){
    out.back() += in[i];
    if(out.back().size() > len && in[i] == ' ')
      out.resize(out.size() + 1);
  }
  return out;
}

std::string ReplacePercentS(std::string in, std::string val)
{
  std::string out;
  for(unsigned int i = 0; i < in.size(); i++){
    if(in[i] == '%' && i + 1 < in.size() && in[i + 1] == 's'){
      out += val;
      i++;
    }
    else{
      out += in[i];
    }
  }
  return out;
}

std::string ConvertFileToString(std::string fileName)
{
  FILE *fp = fopen(fileName.c_str(), "r");
  if(!fp) return "";
  std::string out;
  char str[256];
  while(!feof(fp) && fgets(str, sizeof(str), fp)) out += str;
  fclose(fp);
  return out;
}

void ConvertToHTML(std::string &in)
{
  while(1){
    int pos = in.find("<");
    if(pos == std::string::npos) break;
    in.replace(pos, 1, "&lt;");
  }
  while(1){
    int pos = in.find(">");
    if(pos == std::string::npos) break;
    in.replace(pos, 1, "&gt;");
  }
  while(1){
    const char n2[3] = {'\n', '\n', '\0'};
    int pos = in.find(n2);
    if(pos == std::string::npos) break;
    in.replace(pos, 2, "<p>");
  }
  while(1){
    const char n1[2] = {'\n', '\0'};
    int pos = in.find(n1);
    if(pos == std::string::npos) break;
    in.replace(pos, 1, "<br>");
  }
}

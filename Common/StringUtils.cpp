// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#if defined(__CYGWIN__)
#include <sys/cygwin.h>
#endif

#include "StringUtils.h"

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

std::string FixWindowsPath(const char *in)
{
#if defined(__CYGWIN__)
  char tmp[1024];
  cygwin_conv_to_win32_path(in, tmp);
  return std::string(tmp);
#else
  return std::string(in);
#endif
}

void SplitFileName(const char *name, char *no_ext, char *ext, char *base)
{
  strcpy(no_ext, name);
  strcpy(ext, "");
  for(int i = strlen(name) - 1; i >= 0; i--){
    if(name[i] == '.'){
      strcpy(ext, &name[i]);
      no_ext[i] = '\0';
      break;
    }
  }
  strcpy(base, no_ext);
  for(int i = strlen(no_ext) - 1; i >= 0; i--){
    if(no_ext[i] == '/' || no_ext[i] == '\\'){
      strcpy(base, &no_ext[i + 1]);
      break;
    }
  }
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

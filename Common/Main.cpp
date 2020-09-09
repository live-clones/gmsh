// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"

#if defined(WIN32) && !defined(__CYGWIN__)
// necessary to handle UTF command line arguments on Windows
#define _UNICODE
#define UNICODE
#include <wchar.h>
#include <stdio.h>
// from OS.cpp
extern unsigned int utf8FromUtf16(char *dst, unsigned int dstlen,
                                  const wchar_t *src, unsigned int srclen);
extern "C"
int wmain(int argc, wchar_t *wargv[], wchar_t *envp[])
{
  char **argv = new char*[argc + 1];
  for(int i = 0; i < argc; i++) {
    argv[i] = new char[MAX_PATH];
    utf8FromUtf16(argv[i], MAX_PATH, wargv[i], wcslen(wargv[i]));
  }
  argv[argc] = NULL;
#else
int main(int argc, char *argv[])
{
#endif
#if defined(HAVE_FLTK)
  return GmshMainFLTK(argc, argv);
#else
  return GmshMainBatch(argc, argv);
#endif
}

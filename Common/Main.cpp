// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
#include "OS.h"

#if defined(WIN32) && !defined(__CYGWIN__)
// necessary to handle UTF command line arguments
int wmain(int argc, wchar_t *wargv[], wchar_t *envp[])
{
  char **argv = new char*[argc + 1];
  for(int i = 0; i < wargc; i++) {
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

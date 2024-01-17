// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"

#if defined(WIN32) && !defined(__CYGWIN__)

// in order to handle non-ASCII command line arguments on Windows, use wmain()
// instead of main() (we could also use main() and retrieve the "wide" args with
// GetCommandLineW() later on, but this would have side-effects on the flow for
// e.g. initializing the api); using wmain() with the mingw compilers requires
// adding the "-municode" linker flag

#include <windows.h>
#include <wchar.h>

static char *toUTF8(wchar_t *src)
{
  if(!src) return nullptr;
  size_t srclen = wcslen(src);
  int len = WideCharToMultiByte(CP_UTF8, 0, src, srclen, 0, 0, nullptr, nullptr);
  char *out = new char[len + 1];
  if(out) {
    WideCharToMultiByte(CP_UTF8, 0, src, srclen, out, len, nullptr, nullptr);
    out[len] = '\0';
  }
  return out;
}

int wmain(int argc, wchar_t *wargv[], wchar_t *envp[])
{
  char **argv = new char*[argc + 1];
  for(int i = 0; i < argc; i++)
    argv[i] = toUTF8(wargv[i]);
  argv[argc] = nullptr;

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

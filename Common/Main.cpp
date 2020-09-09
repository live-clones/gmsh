// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"

#if defined(WIN32) && !defined(__CYGWIN__)

// in order to handle UTF command line arguments on Windows, use wmain() instead
// of main() (we could also use main() and retrieve the "wide" args with
// GetCommandLineW() later on, but this would have side-effects on the flow for
// e.g. initializing the api); using wmain() with the mingw compilers requires
// adding the "-municode" linker flag

#include <windows.h>
#include <wchar.h>

// borrowed from FLTK
static unsigned int utf8FromUtf16(char *dst, unsigned int dstlen,
                                  const wchar_t *src, unsigned int srclen)
{
  unsigned int i = 0;
  unsigned int count = 0;
  if(dstlen) {
    for(;;) {
      unsigned int ucs;
      if(i >= srclen) {
        dst[count] = 0;
        return count;
      }
      ucs = src[i++];
      if(ucs < 0x80U) {
        dst[count++] = ucs;
        if(count >= dstlen) {
          dst[count - 1] = 0;
          break;
        }
      }
      else if(ucs < 0x800U) { /* 2 bytes */
        if(count + 2 >= dstlen) {
          dst[count] = 0;
          count += 2;
          break;
        }
        dst[count++] = 0xc0 | (ucs >> 6);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
      else if(ucs >= 0xd800 && ucs <= 0xdbff && i < srclen &&
              src[i] >= 0xdc00 && src[i] <= 0xdfff) {
        /* surrogate pair */
        unsigned int ucs2 = src[i++];
        ucs = 0x10000U + ((ucs & 0x3ff) << 10) + (ucs2 & 0x3ff);
        /* all surrogate pairs turn into 4-byte utf8 */
        if(count + 4 >= dstlen) {
          dst[count] = 0;
          count += 4;
          break;
        }
        dst[count++] = 0xf0 | (ucs >> 18);
        dst[count++] = 0x80 | ((ucs >> 12) & 0x3F);
        dst[count++] = 0x80 | ((ucs >> 6) & 0x3F);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
      else {
        /* all others are 3 bytes: */
        if(count + 3 >= dstlen) {
          dst[count] = 0;
          count += 3;
          break;
        }
        dst[count++] = 0xe0 | (ucs >> 12);
        dst[count++] = 0x80 | ((ucs >> 6) & 0x3F);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
    }
  }
  /* we filled dst, measure the rest: */
  while(i < srclen) {
    unsigned int ucs = src[i++];
    if(ucs < 0x80U) {
      count++;
    }
    else if(ucs < 0x800U) { /* 2 bytes */
      count += 2;
    }
    else if(ucs >= 0xd800 && ucs <= 0xdbff && i < srclen - 1 &&
            src[i + 1] >= 0xdc00 && src[i + 1] <= 0xdfff) {
      /* surrogate pair */
      ++i;
      count += 4;
    }
    else {
      count += 3;
    }
  }
  return count;
}

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

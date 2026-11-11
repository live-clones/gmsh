// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPTION_ENTRIES_H
#define OPTION_ENTRIES_H

// The entries of the option tables (DefaultOptions.h) and of the plugin
// options, apart from Options.h so that the plugins need not include it

#include <string>

#define GMSH_SET (1 << 0)
#define GMSH_GET (1 << 1)
#define GMSH_GUI (1 << 2)
#define GMSH_SET_DEFAULT (1 << 3)
#define GMSH_GET_DEFAULT (1 << 4)

#define GMSH_SESSIONRC (1 << 0)
#define GMSH_OPTIONSRC (1 << 1)
#define GMSH_FULLRC (1 << 2)
#define GMSH_DEPRECATED (1 << 3)

// action is a combination of GMSH_SET, GMSH_GET, GMSH_GUI

#define OPT_ARGS_STR int num, int action, const std::string &val
#define OPT_ARGS_NUM int num, int action, double val
#define OPT_ARGS_COL int num, int action, unsigned int val

typedef struct {
  const char *str;
  int int1, int2, int3, int4;
} StringX4Int;

typedef struct {
  int level;
  const char *str;
  std::string (*function)(int num, int action, const std::string &val);
  std::string def;
  const char *help;
} StringXString;

typedef struct {
  int level;
  const char *str;
  double (*function)(int num, int action, double val);
  double def;
  const char *help;
} StringXNumber;

typedef struct {
  int level;
  const char *str;
  unsigned int (*function)(int num, int action, unsigned int val);
  // the defaults are stored in individual bytes so that we can initialize
  // them statically independently of the machine endianness. They will be
  // packed into unsigned ints at runtime
  unsigned char def1[4], def2[4], def3[4]; // light, classic, dark
  const char *help;
} StringXColor;

#endif

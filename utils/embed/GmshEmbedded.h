#ifndef _GMSH_EMBEDDED_H_
#define _GMSH_EMBEDDED_H_

#include <stdarg.h>
#include "NumericEmbedded.h"

#define FATAL          1  // Fatal error (causes Gmsh to exit)
#define FATAL1         2  // First part of a multiline FATAL message 
#define FATAL2         3  // Middle part of a multiline FATAL message
#define FATAL3         4  // Last part of a multiline FATAL message  

#define GERROR         5  // Error (but Gmsh can live with it)
#define GERROR1        6  // First part of a multiline ERROR message 
#define GERROR2        7  // Middle part of a multiline ERROR message
#define GERROR3        8  // Last part of a multiline ERROR message  

#define WARNING        9  // Warning
#define WARNING1      10  // First part of a multiline WARNING message 
#define WARNING2      11  // Middle part of a multiline WARNING message
#define WARNING3      12  // Last part of a multiline WARNING message  

#define INFO          13  // Long informations
#define INFO1         14  // First part of a multiline INFO message 
#define INFO2         15  // Middle part of a multiline INFO message
#define INFO3         16  // Last part of a multiline INFO message  

#define DEBUG         17  // Long debug information
#define DEBUG1        18  // First part of a multiline DEBUG message 
#define DEBUG2        19  // Middle part of a multiline DEBUG message
#define DEBUG3        20  // Last part of a multiline DEBUG message  

#define STATUS1       21  // left status bar
#define STATUS2       22  // right status bar

#define STATUS1N      24  // Same as STATUS1, but not going into the log file
#define STATUS2N      25  // Same as STATUS2, but not going into the log file

#define ONSCREEN      27  // Persistent on-screen message

#define DIRECT        30  // Direct message (no special formatting)
#define SOLVER        31  // Solver message
#define SOLVERR       32  // Solver errors and warnings

#define PROGRESS      40  // Progress indicator

#define WHITE_STR          "        : "
#define FATAL_STR          "Fatal   : "
#define ERROR_STR          "Error   : "
#define WARNING_STR        "Warning : "
#define INFO_STR           "Info    : "
#define DEBUG_STR          "Debug   : "
#define STATUS_STR         "Info    : "

void   Signal(int signum);
void   Msg(int level, const char *fmt, ...);

class Context_T{
public:
  Context_T()
  {
    lc = 1.;
    verbosity = 4;
    hide_unselected = 0;
    geom.tolerance = 1.e-6;
    mesh.reverse_all_normals = 1;
    pick_elements = 0;
  }
  double lc;
  int verbosity;
  int hide_unselected;
  int pick_elements;
  struct{
    double tolerance;
  } geom;
  struct{
    int reverse_all_normals;
  } mesh;
  unsigned int PACK_COLOR(int,int,int,int){ return 0; }
  int UNPACK_RED(unsigned int){ return 0; }
  int UNPACK_GREEN(unsigned int){ return 0; }
  int UNPACK_BLUE(unsigned int){ return 0; }
  int UNPACK_ALPHA(unsigned int){ return 0; }
};

class smooth_normals{
 public:
  int dummy;
};

class VertexArray{
 public:
  int dummy;
};

#endif

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdarg.h>

#define FATAL          0  // Fatal error (causes Gmsh to exit)
#define FATAL1        10  
#define FATAL2        20  
#define FATAL3        30  

#define GERROR         1  // Error (but Gmsh can live with it)
#define GERROR1       11
#define GERROR2       21
#define GERROR3       31

#define WARNING        2  // Warning
#define WARNING1      12
#define WARNING2      22
#define WARNING3      32

#define INFOS          3  // Long informations
#define INFOS1        13
#define INFOS2        23
#define INFOS3        33

#define INFO           4  // Small information in status bar
#define SELECT         5  // Small interaction message in status bar, e.g. for select
#define STATUS         6  // Gmsh status in status bar
#define PARSER_ERROR   7  // Error during syntax parsing
#define PARSER_INFO    8  // Info during syntax parsing

#define DEBUG          9  // Long debug information
#define DEBUG1        19
#define DEBUG2        29
#define DEBUG3        39

#define FATAL_STR          "Fatal Error : "
#define FATAL_NIL          "            : "
#define ERROR_STR          "Error : "
#define ERROR_NIL          "      : "
#define WARNING_STR        "Warning : "
#define WARNING_NIL        "        : "
#define INFOS_STR          "Info : "
#define INFOS_NIL          "     : "
#define DEBUG_STR          "Debug : "
#define DEBUG_NIL          "      : "

#define INFO_STR           "Info : "
#define SELECT_STR         "Info : "
#define STATUS_STR         "Info : "
#define PARSER_ERROR_STR   "Parse Error : "
#define PARSER_INFO_STR    "Parse Info : "

void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Progress(int);
void   AddALineInTheEditGeometryForm (char* line);

#endif

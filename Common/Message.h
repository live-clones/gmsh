/* $Id: Message.h,v 1.5 2000-11-24 08:04:14 geuzaine Exp $ */
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdarg.h>

#define FATAL          0  // Fatal error (causes Gmsh to exit)
#define ERROR          1  // Error (but Gmsh can live with it)
#define WARNING        2  // Warning
#define INFOS          3  // Long informations
#define INFO           4  // Small information in status bar
#define SELECT         5  // Small interaction message in status bar, e.g. for select
#define STATUS         6  // Gmsh status in status bar
#define PARSER_ERROR   7  // Error during syntax parsing
#define PARSER_INFO    8  // Info during syntax parsing
#define DEBUG          9  // Long debug information

#define FATAL_STR          "Fatal Error : "
#define FATAL_NIL          "            : "
#define ERROR_STR          "Error : "
#define ERROR_NIL          "      : "
#define WARNING_STR        "Warning : "
#define WARNING_NIL        "        : "
#define INFOS_STR          "Info : "
#define INFOS_NIL          "     : "
#define INFO_STR           "Info : "
#define INFO_NIL           "     : "
#define SELECT_STR         "Info : "
#define SELECT_NIL         "     : "
#define STATUS_STR         "Info : "
#define STATUS_NIL         "     : "
#define PARSER_ERROR_STR   "Parse Error : "
#define PARSER_ERROR_NIL   "            : "
#define PARSER_INFO_STR    "Parse Info : "
#define PARSER_INFO_NIL    "           : "
#define DEBUG_STR          "Debug : "
#define DEBUG_NIL          "      : "

void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Progress(int);
void   AddALineInTheEditGeometryForm (char* line);

#endif

/* $Id: Message.h,v 1.4 2000-11-24 00:11:25 geuzaine Exp $ */
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdarg.h>

#define FATAL          0  // Fatal error (causes Gmsh to exit)
#define ERROR          1  // Error
#define WARNING        2  // Warning
#define INFOS          3  // Long informations
#define INFO           4  // Small information in status bar
#define SELECT         5  // Small interaction message in status bar, e.g. for select
#define STATUS         6  // Gmsh status in status bar
#define PARSER_ERROR   7  // Error during syntax parsing
#define PARSER_INFO    8  // Info during syntax parsing
#define DEBUG          9  // Long debug information

#define FATAL_STR          "Fatal Error : "
#define ERROR_STR          "Error       : "
#define WARNING_STR        "Warning     : "
#define INFOS_STR          "Info        : "
#define INFO_STR           "Info        : "
#define SELECT_STR         "Info        : "
#define STATUS_STR         "Status      : "
#define PARSER_ERROR_STR   "Parse Error : "
#define PARSER_INFO_STR    "Parse Info  : "
#define DEBUG_STR          "Debug       : "

#define WHITE_STR          "            : "

void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Progress(int);
void   AddALineInTheEditGeometryForm (char* line);

#endif

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include <stdarg.h>

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

#define STATUS1       21  // Small information in status bar (left)
#define STATUS2       22  // Small interaction in status bar (middle)
#define STATUS3       23  // Small interaction in status bar (right)

#define STATUS1N      24  // Same as STATUS1, but not going into the log file
#define STATUS2N      25  // Same as STATUS2, but not going into the log file
#define STATUS3N      26  // Same as STATUS3, but not going into the log file

#define PARSER_ERROR  27  // Error during syntax parsing
#define PARSER_INFO   28  // Info during syntax parsing
#define LOG_INFO      29  // Info put only in the logfile

#define DIRECT        30  // Direct message (no special formatting)

#define FATAL_STR          "Fatal Error : "
#define FATAL_NIL          "            : "
#define ERROR_STR          "Error : "
#define ERROR_NIL          "      : "
#define WARNING_STR        "Warning : "
#define WARNING_NIL        "        : "
#define INFO_STR           "Info : "
#define INFO_NIL           "     : "
#define DEBUG_STR          "Debug : "
#define DEBUG_NIL          "      : "
#define STATUS_STR         "Info : "
#define PARSER_ERROR_STR   "Parse Error : "
#define PARSER_INFO_STR    "Parse Info : "

void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Exit(int);

#endif

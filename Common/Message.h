#ifndef _MESSAGE_H_
#define _MESSAGE_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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

#define DIRECT        30  // Direct message (no special formatting)

#define SOLVER        31  // Solver message
#define SOLVERR       32  // Solver errors and warnings

#define WHITE_STR          "        : "
#define FATAL_STR          "Fatal   : "
#define ERROR_STR          "Error   : "
#define WARNING_STR        "Warning : "
#define INFO_STR           "Info    : "
#define DEBUG_STR          "Debug   : "
#define STATUS_STR         "Info    : "

void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Exit(int);

#endif

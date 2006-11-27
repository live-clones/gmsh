#ifndef _GMSH_CLIENT_H_
#define _GMSH_CLIENT_H_

/*
 * Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
 * ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 * 
 * Please report all bugs and problems to <gmsh@geuz.org>.
 */

#define GMSH_CLIENT_START        1
#define GMSH_CLIENT_STOP         2
#define GMSH_CLIENT_INFO         10
#define GMSH_CLIENT_WARNING      11
#define GMSH_CLIENT_ERROR        12
#define GMSH_CLIENT_PROGRESS     13
#define GMSH_CLIENT_VIEW         20 /* deprecated: use MERGE_FILE instead */
#define GMSH_CLIENT_MERGE_FILE   20
#define GMSH_CLIENT_PARSE_STRING 21
#define GMSH_CLIENT_OPTION       100
#define GMSH_CLIENT_OPTION_1     (GMSH_CLIENT_OPTION+0)
#define GMSH_CLIENT_OPTION_2     (GMSH_CLIENT_OPTION+1)
#define GMSH_CLIENT_OPTION_3     (GMSH_CLIENT_OPTION+2)
#define GMSH_CLIENT_OPTION_4     (GMSH_CLIENT_OPTION+3)
#define GMSH_CLIENT_OPTION_5     (GMSH_CLIENT_OPTION+4)

int  Gmsh_Connect(char *sockname);
void Gmsh_SendString(int socket, int type, char str[]);
void Gmsh_Disconnect(int sock);

#endif

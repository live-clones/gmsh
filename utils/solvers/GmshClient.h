#ifndef _GMSH_CLIENT_H_
#define _GMSH_CLIENT_H_

/*
  Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.
  
  You should have received a copy of the GNU Library General Public
  License along with this library; if not, write to the Free
  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
  Please report all bugs and problems to "gmsh@geuz.org".
*/

#define GMSH_CLIENT_START       1
#define GMSH_CLIENT_STOP        2
#define GMSH_CLIENT_INFO        10
#define GMSH_CLIENT_WARNING     11
#define GMSH_CLIENT_ERROR       12
#define GMSH_CLIENT_PROGRESS    13
#define GMSH_CLIENT_VIEW        20
#define GMSH_CLIENT_OPTION      100
#define GMSH_CLIENT_OPTION_1    (GMSH_CLIENT_OPTION+0)
#define GMSH_CLIENT_OPTION_2    (GMSH_CLIENT_OPTION+1)
#define GMSH_CLIENT_OPTION_3    (GMSH_CLIENT_OPTION+2)
#define GMSH_CLIENT_OPTION_4    (GMSH_CLIENT_OPTION+3)
#define GMSH_CLIENT_OPTION_5    (GMSH_CLIENT_OPTION+4)

int  Gmsh_Connect(char *sockname);
void Gmsh_SendString(int socket, int type, char str[]);
void Gmsh_Disconnect(int sock);

#endif

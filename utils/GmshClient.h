#ifndef _GMSH_CLIENT_H_
#define _GMSH_CLIENT_H_

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

#ifndef _GMSH_SERVER_H_
#define _GMSH_SERVER_H_

int Gmsh_StartClient(char *command, char *sockname);
int Gmsh_ReceiveString(int socket, int *type, char str[]);
int Gmsh_StopClient(char *sockname, int socket);

#endif

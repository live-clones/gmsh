#ifndef _SOCKET_H_
#define _SOCKET_H_

int  Socket_ReceiveData(int socket, void *buffer, int bytes);
void Socket_SendData(int socket, void *buffer, int bytes);
int  Socket_ReceiveInt(int socket, int *i);
void Socket_SendInt(int socket, int i);
int  Socket_ReceiveDouble(int socket, double *x);
void Socket_SendDouble(int socket, double x);
int  Socket_ReceiveString(int socket, char str[]);
void Socket_SendString(int socket, char str[]);
int  Socket_StartProgram(char *progname, char *sockname);
int  Socket_StopProgram(char *progname, char *sockname, int sock);
int  Socket_Connect(char *sockname);
void Socket_Close(int sock);

#endif

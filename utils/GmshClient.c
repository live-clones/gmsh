/* $Id: GmshClient.c,v 1.1 2002-01-03 10:25:06 geuzaine Exp $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _AIX
#include <strings.h>
#endif
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <unistd.h>

/* private functions */

static void Socket_SendData(int socket, void *buffer, int bytes){
  int sofar, remaining, len;
  char *buf;
  buf = (char*)buffer;
  sofar = 0;
  remaining = bytes;
  do {
    len = write(socket, buf + sofar, remaining);
    sofar += len;
    remaining -= len;
  } while (remaining>0);
}

static long Socket_GetTime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

static void Socket_Idle(double delay){
  long t1 = Socket_GetTime();
  while(1){
    if(Socket_GetTime() - t1 > 1.e6*delay) break;
  }
}

/* public interface */

int Gmsh_Connect(char *sockname){
  struct sockaddr_un addr;
  int len, sock;
  int tries;

  /* slight delay to be sure that the socket is bound by the
     server before we attempt to connect to it... */
  Socket_Idle(0.1);

  /* create socket */
  sock = socket(PF_UNIX, SOCK_STREAM, 0);
  if (sock<0) return -1; /* Error: Couldn't create socket */

  /* try to connect socket to given name */
  strcpy(addr.sun_path, sockname);
  addr.sun_family = AF_UNIX;
  len = strlen(addr.sun_path)+sizeof(addr.sun_family);
  for (tries=0;tries<5;tries++) {
    if (connect(sock, (struct sockaddr *)&addr, len) >= 0) return sock;
  }
   
  return -2; /* Error: Couldn't connect */
}

void Gmsh_SendString(int socket, int type, char str[]){
  int len = strlen(str);
  Socket_SendData(socket, &type, sizeof(int));
  Socket_SendData(socket, &len, sizeof(int));
  Socket_SendData(socket, str, len);
}

void Gmsh_Disconnect(int sock){
  close(sock);
}


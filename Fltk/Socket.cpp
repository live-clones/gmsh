/* $Id: Socket.cpp,v 1.7 2001-05-04 22:42:21 geuzaine Exp $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <unistd.h>

#include "Message.h"

int Socket_ReceiveData(int socket, void *buffer, int bytes){
  int sofar, remaining, len;
  char *buf;
  
  buf = (char*)buffer;
  sofar = 0;
  remaining = bytes;
  do {
    len = read(socket, buf + sofar, remaining);
    if (len<=0) return 0;
    sofar += len;
    remaining -= len;
  } while (remaining>0);
  return bytes;
}

void Socket_SendData(int socket, void *buffer, int bytes){
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

int Socket_ReceiveInt(int socket, int *i){
  return Socket_ReceiveData(socket, i, sizeof(int));
}

void Socket_SendInt(int socket, int i){
  Socket_SendData(socket, &i, sizeof(int));
}

int Socket_ReceiveDouble(int socket, double *x){
  return Socket_ReceiveData(socket, x, sizeof(double));
}

void Socket_SendDouble(int socket, double x){
  Socket_SendData(socket, &x, sizeof(double));
}

int Socket_ReceiveString(int socket, char str[]){
   int len;

   if (Socket_ReceiveInt(socket, &len)) {
     if (Socket_ReceiveData(socket, str, len)==len) {
       str[len] = '\0';
       return 1;
     }
   }
   return 0;
}

void Socket_SendString(int socket, char str[]){
  int len;
  
  len = strlen(str);
  Socket_SendInt(socket, len);
  Socket_SendData(socket, str, len);
}


int Socket_StartProgram(char *progname, char *sockname){
  int s, sock;
#ifdef linux
  socklen_t len ;
#else
  int len;
#endif
  struct sockaddr_un addr, from;
  char command[1000];
  fd_set rfds;
  struct timeval tv;
  int retval;

  /* first delete the socket's name if it exists */
  unlink(sockname);
  
  /* make the socket */
  s = socket(PF_UNIX, SOCK_STREAM, 0);
  if (s<0) {
    Msg(GERROR, "Couldn't create socket");
    return -1;
  }
  
  /* bind the socket to its name */
  strcpy(addr.sun_path, sockname);
  addr.sun_family = AF_UNIX;
  if(bind(s, (struct sockaddr *)&addr, strlen(addr.sun_path)+sizeof(addr.sun_family)) < 0) {
    Msg(GERROR, "Couldn't bind socket to name");
    return -1;
  }
  
  /* change permissions on the socket name in case it has to be rm'd later */
  chmod(sockname, 0666);
  
  /* Start the external function via system() call */
  sprintf(command, "%s -socket %s &", progname, sockname);
  system(command);
  
  /* wait for external function to connect */
  if(listen(s, 20)) Msg(GERROR, "Socket listen failed");
  
  /* Watch s to see when it has input. */
  FD_ZERO(&rfds);
  FD_SET(s, &rfds);
  /* Wait up to 2 seconds */
  tv.tv_sec = 2;
  tv.tv_usec = 0;
  retval = select(s+1, &rfds, NULL, NULL, &tv);
  
  if(!retval){
    Msg(GERROR, "Socket listening timeout");	
    return -1;
  }
  
  len = sizeof(from);
  if ( (sock = accept(s, (struct sockaddr *)&from, &len)) < 0) {
    Msg(GERROR, "Socket accept failed");	
    return -1;
  }
  
  close(s); /* don't need this socket anymore */
  
  return sock;
}

int Socket_StopProgram(char *progname, char *sockname, int sock){
  if(unlink(sockname)==-1) Msg(WARNING, "Impossible to unlink the socket");
  close(sock);
  return 0;
}

long Socket_GetTime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

void Socket_Idle(double delay){
  long t1 = Socket_GetTime();
  while(1){
    if(Socket_GetTime() - t1 > 1.e6*delay) break;
  }
}

int Socket_Connect(char *sockname){
  struct sockaddr_un addr;
  int len, sock;
  int tries;

  /* slight delay to be sure that the socket is bind by the
     server before we attempt to connect to it... */
  Socket_Idle(0.1);

  /* create socket */
  sock = socket(PF_UNIX, SOCK_STREAM, 0);
  if (sock<0){
    Msg(GERROR, "Couldn't create socket");
    return -1;
  }

  /* try to connect socket to given name */
  strcpy(addr.sun_path, sockname);
  addr.sun_family = AF_UNIX;
  len = strlen(addr.sun_path)+sizeof(addr.sun_family);
  for (tries=0;tries<5;tries++) {
    if (connect(sock, (struct sockaddr *)&addr, len) < 0) {
      Msg(WARNING, "Socket connect failed on '%s'", sockname);
    }
    else {
      return sock;
    }
  }
   
  return -1;
}


void Socket_Close(int sock){
  close(sock);
}

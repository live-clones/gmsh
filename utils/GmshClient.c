/* $Id: GmshClient.c,v 1.2 2002-05-18 08:06:10 geuzaine Exp $ */
/*
  Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
*/

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


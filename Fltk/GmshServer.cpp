/* $Id: GmshServer.cpp,v 1.19 2004-12-06 06:54:32 geuzaine Exp $ */
/*
 * Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
 *  Please report all bugs and problems to <gmsh@geuz.org>.
 */

// This is a hacked version using the Gmsh function SystemCall()
// instead system() and using CTX.solver.max_delay in select()
#include "Context.h"
extern Context_T CTX;
void SystemCall(char *str);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_AIX)
#include <strings.h>
#endif
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>

/* private functions */

static int Socket_ReceiveData(int socket, void *buffer, int bytes)
{
  int sofar, remaining, len;
  char *buf;

  buf = (char *)buffer;
  sofar = 0;
  remaining = bytes;
  do {
    len = read(socket, buf + sofar, remaining);
    if(len <= 0)
      return 0;
    sofar += len;
    remaining -= len;
  } while(remaining > 0);
  return bytes;
}

static int Socket_UnlinkName(char *name)
{
#if defined(_AIX) || defined(__APPLE__)
  char name2[1000];
  strcpy(name2, name);
  name2[strlen(name2) - 1] = '\0';
  return unlink(name2);
#else
  return unlink(name);
#endif
}


/* public interface */

int Gmsh_StartClient(char *command, char *sockname)
{
  static int init = 0;
  static int s;
  int sock;
#if defined(linux) || defined(_AIX) || defined(__FreeBSD__)
  socklen_t len;
#else
  int len;
#endif
  struct sockaddr_un addr_un, from_un;
  struct sockaddr_in addr_in, from_in;
  fd_set rfds;
  struct timeval tv;
  int retval, portno;
  char *port;

  /* no socket? launch the command! */
  if(!sockname) {
    //system(command);
    SystemCall(command);
    return 1;
  }

  if((port = strstr(sockname, ":"))){ /* INET socket */
    portno = atoi(port+1);
  }
  else{
    portno = -1;
  }

  if(portno < 0){ /* UNIX socket */
    /* delete the file if it already exists */
    Socket_UnlinkName(sockname);

    /* make the socket */
    s = socket(PF_UNIX, SOCK_STREAM, 0);
    if(s < 0)
      return -1;  /* Error: Couldn't create socket */

    /* bind the socket to its name */
    strcpy(addr_un.sun_path, sockname);
    addr_un.sun_family = AF_UNIX;
    if(bind(s, (struct sockaddr *)&addr_un,
	    strlen(addr_un.sun_path) + sizeof(addr_un.sun_family)) < 0)
      return -2;  /* Error: Couldn't bind socket to name */

    /* change permissions on the socket name in case it has to be rm'd later */
    chmod(sockname, 0666);
  }
  else{ /* INET socket */
    if(init != portno){ /* FIXME: need a better solution to deal with
			   addresses that have already been bound! */
      init = portno;

      /* make the socket */
      s = socket(AF_INET, SOCK_STREAM, 0);
      if(s < 0)
	return -1;  /* Error: Couldn't create socket */
      
      /* bind the socket to its name */
      bzero((char *) &addr_in, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      addr_in.sin_addr.s_addr = INADDR_ANY;
      addr_in.sin_port = htons(portno);
      
      if(bind(s, (struct sockaddr *)&addr_in, sizeof(addr_in)) < 0)
	return -2;  /* Error: Couldn't bind socket to name */
    }
  }

  /* Start the external function via system() call */
  //system(command);
  SystemCall(command);

  /* wait for external function to connect */
  if(listen(s, 20))
    return -3;  /* Error: Socket listen failed */

  /* Watch s to see when it has input; wait up to N seconds */
  //tv.tv_sec = 4;
  tv.tv_sec = CTX.solver.max_delay;
  tv.tv_usec = 0;
  FD_ZERO(&rfds);
  FD_SET(s, &rfds);
  retval = select(s + 1, &rfds, NULL, NULL, &tv);

  if(!retval)
    return -4;  /* Error: Socket listening timeout */

  if(portno < 0){
    len = sizeof(from_un);
    if((sock = accept(s, (struct sockaddr *)&from_un, &len)) < 0)
      return -5;  /* Error: Socket accept failed */
  }
  else{
    len = sizeof(from_in);
    if((sock = accept(s, (struct sockaddr *)&from_in, &len)) < 0)
      return -5;  /* Error: Socket accept failed */
  }

  return sock;
}

int Gmsh_ReceiveString(int socket, int *type, char str[])
{
  int len;

  Socket_ReceiveData(socket, type, sizeof(int));
  if(Socket_ReceiveData(socket, &len, sizeof(int))) {
    if(Socket_ReceiveData(socket, str, len) == len) {
      str[len] = '\0';
      return 1;
    }
  }
  return 0;
}

int Gmsh_StopClient(char *sockname, int sock)
{
  if(!strstr(sockname, ":"))
    if(Socket_UnlinkName(sockname) == -1)
      return -1;  /* Impossible to unlink the socket */

  close(sock);
  return 0;
}

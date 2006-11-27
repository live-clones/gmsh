/* $Id: GmshClient.c,v 1.7 2006-11-27 22:22:34 geuzaine Exp $ */
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
 *
 * Contributor(s):
 *   Christopher Stott
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _AIX
#include <strings.h>
#endif

#if !defined(WIN32) || defined(__CYGWIN__)

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>

#else /* pure windows */

#include <winsock.h>
#include <process.h>

#endif

/* private functions */

static void Socket_SendData(int socket, void *buffer, int bytes)
{
  ssize_t len;
  int sofar, remaining;
  char *buf;
  buf = (char *)buffer;
  sofar = 0;
  remaining = bytes;
  do {
    len = send(socket, buf + sofar, remaining, 0); 
    sofar += len;
    remaining -= len;
  } while(remaining > 0);
}

static void Socket_Idle(int ms)
{
#if !defined(WIN32) || defined(__CYGWIN__)
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
}

/* public interface */

int Gmsh_Connect(char *sockname)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  struct sockaddr_un addr_un;
#else
  WSADATA wsaData;
  int iResult;
#endif

  struct sockaddr_in addr_in;
  int sock;
  int tries;
  struct hostent *server;
  int portno, remotelen;
  char remote[256], *port;

#if defined(WIN32) && !defined(__CYGWIN__)
  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if(iResult != NO_ERROR)
    return -4;  /* Error: Couldn't initialize Windows sockets */
#endif

  /* slight delay to be sure that the socket is bound by the
     server before we attempt to connect to it... */
  Socket_Idle(100);

  if(strstr(sockname, "/") || strstr(sockname, "\\") || !strstr(sockname, ":")){
    /* UNIX socket (testing ":" is not enough with Windows paths) */
    portno = -1;
  }
  else{
    /* INET socket */
    port = strstr(sockname, ":");
    portno = atoi(port+1);
    remotelen = strlen(sockname) - strlen(port);
    if(remotelen > 0)
      strncpy(remote, sockname, remotelen);
    remote[remotelen] = '\0';
  }

  /* create socket */

  if(portno < 0){
#if !defined(WIN32) || defined(__CYGWIN__)
    sock = socket(PF_UNIX, SOCK_STREAM, 0);
    if(sock < 0)
      return -1; /* Error: Couldn't create socket */
    /* try to connect socket to given name */
    memset((char *) &addr_un, 0, sizeof(addr_un));
    addr_un.sun_family = AF_UNIX;
    strcpy(addr_un.sun_path, sockname);
    for(tries = 0; tries < 5; tries++) {
      if(connect(sock, (struct sockaddr *)&addr_un, sizeof(addr_un)) >= 0)
	return sock;
      Socket_Idle(100);
    }
#else
    /* Unix sockets are not available on Windows without Cygwin */
    return -1;
#endif
  }
  else{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
      return -1; /* Error: Couldn't create socket */
    if(!(server = gethostbyname(remote)))
      return -3; /* Error: No such host */
    /* try to connect socket to given name */
    memset((char *) &addr_in, 0, sizeof(addr_in));
    addr_in.sin_family = AF_INET;
    memcpy((char *)&addr_in.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    addr_in.sin_port = htons(portno);
    for(tries = 0; tries < 5; tries++) {
      if(connect(sock, (struct sockaddr *)&addr_in, sizeof(addr_in)) >= 0)
	return sock;
      Socket_Idle(100);
    }
  }

  return -2; /* Error: Couldn't connect */
}

void Gmsh_SendString(int socket, int type, char str[])
{
  int len = strlen(str);
  Socket_SendData(socket, &type, sizeof(int));
  Socket_SendData(socket, &len, sizeof(int));
  Socket_SendData(socket, str, len);
}

void Gmsh_Disconnect(int sock)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  close(sock);
#else
  closesocket(sock);
  WSACleanup();
#endif
}

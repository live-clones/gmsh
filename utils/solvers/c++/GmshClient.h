#ifndef _GMSH_CLIENT_H_
#define _GMSH_CLIENT_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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

#else // pure windows

#include <winsock.h>
#include <process.h>

#endif

class GmshClient {
 private:
  typedef enum{ CLIENT_START        = 1,
		CLIENT_STOP         = 2,
		CLIENT_INFO         = 10,
		CLIENT_WARNING      = 11,
		CLIENT_ERROR        = 12,
		CLIENT_PROGRESS     = 13,
		CLIENT_MERGE_FILE   = 20, // old name was CLIENT_VIEW
		CLIENT_PARSE_STRING = 21,
		CLIENT_OPTION_1     = 100,
		CLIENT_OPTION_2     = 101,
		CLIENT_OPTION_3     = 102,
		CLIENT_OPTION_4     = 103,
		CLIENT_OPTION_5     = 104 } MessageType;
  int _sock;
  void _SendData(void *buffer, int bytes)
  {
    char *buf = (char *)buffer;
    int sofar = 0;
    int remaining = bytes;
    do {
      ssize_t len = send(_sock, buf + sofar, remaining, 0); 
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
  }
  void _SendString(int type, char str[])
  {
    int len = strlen(str);
    _SendData(&type, sizeof(int));
    _SendData(&len, sizeof(int));
    _SendData(str, len);
  }
  void _Idle(int ms)
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
  }
 public:
  GmshClient() : _sock(0) {}
  ~GmshClient(){}
  int Connect(char *sockname)
  {
#if defined(WIN32) && !defined(__CYGWIN__)
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != NO_ERROR)
      return -4;  // Error: Couldn't initialize Windows sockets
#endif

    // slight delay to be sure that the socket is bound by the
    // server before we attempt to connect to it...
    _Idle(100);

    int portno;
    char remote[256];
    if(strstr(sockname, "/") || strstr(sockname, "\\") || !strstr(sockname, ":")){
      // UNIX socket (testing ":" is not enough with Windows paths)
      portno = -1;
    }
    else{
      // INET socket
      char *port = strstr(sockname, ":");
      portno = atoi(port+1);
      int remotelen = strlen(sockname) - strlen(port);
      if(remotelen > 0)
	strncpy(remote, sockname, remotelen);
      remote[remotelen] = '\0';
    }
    
    // create socket
    
    if(portno < 0){
#if !defined(WIN32) || defined(__CYGWIN__)
      _sock = socket(PF_UNIX, SOCK_STREAM, 0);
      if(_sock < 0)
	return -1;  // Error: Couldn't create socket
      // try to connect socket to given name
      struct sockaddr_un addr_un;
      memset((char *) &addr_un, 0, sizeof(addr_un));
      addr_un.sun_family = AF_UNIX;
      strcpy(addr_un.sun_path, sockname);
      for(int tries = 0; tries < 5; tries++) {
	if(connect(_sock, (struct sockaddr *)&addr_un, sizeof(addr_un)) >= 0)
	  return _sock;
	_Idle(100);
      }
#else
      // Unix sockets are not available on Windows without Cygwin
      return -1;
#endif
    }
    else{
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
	return -1; // Error: Couldn't create socket
      struct hostent *server;
      if(!(server = gethostbyname(remote)))
	return -3; // Error: No such host
      // try to connect socket to given name
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      memcpy((char *)&addr_in.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      addr_in.sin_port = htons(portno);
      for(int tries = 0; tries < 5; tries++) {
	if(connect(_sock, (struct sockaddr *)&addr_in, sizeof(addr_in)) >= 0)
	  return _sock;
	_Idle(100);
      }
    }
    return -2; // Error: Couldn't connect
  }
  void Start()
  {
    char tmp[256];
#if !defined(WIN32) || defined(__CYGWIN__)
    sprintf(tmp, "%d", getpid());
#else
    sprintf(tmp, "%d", _getpid());
#endif
    _SendString(CLIENT_START, tmp);
  }
  void Stop()
  {
    _SendString(CLIENT_STOP, "Goodbye!");
  }
  void Info(char *str)
  {
    _SendString(CLIENT_INFO, str);
  }
  void Warning(char *str)
  {
    _SendString(CLIENT_WARNING, str);
  }
  void Error(char *str)
  {
    _SendString(CLIENT_ERROR, str);
  }
  void Progress(char *str)
  {
    _SendString(CLIENT_PROGRESS, str);
  }
  void View(char *str) 
  {
    // deprecated: use MergeFile(str) instead
    _SendString(CLIENT_MERGE_FILE, str);
  }
  void MergeFile(char *str)
  {
    _SendString(CLIENT_MERGE_FILE, str);
  }
  void ParseString(char *str)
  {
    _SendString(CLIENT_PARSE_STRING, str);
  }
  void Option(int num, char *str)
  {
    if(num < 1) num = 1;
    if(num > 5) num = 5;
    _SendString(CLIENT_OPTION_1 + num - 1, str);
  }
  void Disconnect()
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    close(_sock);
#else
    closesocket(_sock);
    WSACleanup();
#endif
  }
};

#endif

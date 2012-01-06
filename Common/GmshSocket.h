// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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

#ifndef _GMSH_SOCKET_H_
#define _GMSH_SOCKET_H_

#include "GmshConfig.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_AIX)
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
#if defined(HAVE_NO_SOCKLEN_T)
typedef int socklen_t;
#endif
#else
#include <winsock.h>
#include <process.h>
typedef int socklen_t;
#endif

class GmshSocket{
 public:
  // types of messages that can be exchanged (never use values greater
  // that 65535: if we receive a type > 65535 we assume that we
  // receive data from a machine with a different byte ordering, and
  // we swap the bytes in the payload)
  enum MessageType{ 
    GMSH_START           = 1,
    GMSH_STOP            = 2,
    GMSH_INFO            = 10,
    GMSH_WARNING         = 11,
    GMSH_ERROR           = 12,
    GMSH_PROGRESS        = 13,
    GMSH_MERGE_FILE      = 20,
    GMSH_PARSE_STRING    = 21,
    GMSH_VERTEX_ARRAY    = 22,
    GMSH_PARAMETER       = 23,
    GMSH_PARAMETER_QUERY = 24,
    GMSH_PARAM_QUERY_ALL = 25,
    GMSH_PARAM_QUERY_END = 26,
    GMSH_SPEED_TEST      = 30,
    GMSH_OPTION_1        = 100,
    GMSH_OPTION_2        = 101,
    GMSH_OPTION_3        = 102,
    GMSH_OPTION_4        = 103,
    GMSH_OPTION_5        = 104};
 protected:
  // the socket descriptor
  int _sock;
  // the socket name
  std::string _sockname;
  // send some data over the socket
  void _SendData(const void *buffer, int bytes)
  {
    const char *buf = (const char *)buffer;
    int sofar = 0;
    int remaining = bytes;
    do {
      int len = send(_sock, buf + sofar, remaining, 0); 
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
  }
  // receive some data over the socket
  int _ReceiveData(void *buffer, int bytes)
  {
    char *buf = (char *)buffer;
    int sofar = 0;
    int remaining = bytes;
    do {
      int len = recv(_sock, buf + sofar, remaining, 0);
      if(len == 0) break; // we're done!
      if(len < 0) return -1; // error
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
    return bytes;
  }
  // utility function to swap bytes in an array
  void _SwapBytes(char *array, int size, int n)
  {
    char *x = new char[size];
    for(int i = 0; i < n; i++) {
      char *a = &array[i * size];
      memcpy(x, a, size);
      for(int c = 0; c < size; c++)
        a[size - 1 - c] = x[c];
    }
    delete [] x;
  }
  // sleep for some milliseconds
  void _Sleep(int ms)
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
  }
 public:
  GmshSocket() : _sock(0)
  {
#if defined(WIN32) && !defined(__CYGWIN__)
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
  }
  ~GmshSocket()
  {
#if defined(WIN32) && !defined(__CYGWIN__)
    WSACleanup();
#endif
  }
  // utility function to wait for some data to read on a socket (if
  // seconds and microseconds == 0 we check for available data and
  // return immediately, i.e., we do polling). Returns 0 when data is
  // available.
  int Select(int seconds, int microseconds, int socket=-1)
  {
    int s = (socket < 0) ? _sock : socket;
    struct timeval tv;
    tv.tv_sec = seconds;
    tv.tv_usec = microseconds;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s, &rfds);
    // select checks all IO descriptors between 0 and its first arg,
    // minus 1... hence the +1 below
    return select(s + 1, &rfds, NULL, NULL, &tv);
  }
  void SendMessage(int type, int length, const void *msg)
  {
    // send header (type + length)
    _SendData(&type, sizeof(int));
    _SendData(&length, sizeof(int));
    // send body
    _SendData(msg, length);
  }
  void SendString(int type, const char *str)
  {
    SendMessage(type, strlen(str), str);
  }
  void Info(const char *str){ SendString(GMSH_INFO, str); }
  void Warning(const char *str){ SendString(GMSH_WARNING, str); }
  void Error(const char *str){ SendString(GMSH_ERROR, str); }
  void Progress(const char *str){ SendString(GMSH_PROGRESS, str); }
  void MergeFile(const char *str){ SendString(GMSH_MERGE_FILE, str); }
  void ParseString(const char *str){ SendString(GMSH_PARSE_STRING, str); }
  void SpeedTest(const char *str){ SendString(GMSH_SPEED_TEST, str); }
  void Option(int num, const char *str)
  {
    if(num < 1) num = 1;
    if(num > 5) num = 5;
    SendString(GMSH_OPTION_1 + num - 1, str);
  }
  int ReceiveHeader(int *type, int *len, int *swap)
  {
    *swap = 0;
    if(_ReceiveData(type, sizeof(int))){
      if(*type < 0) return 0;
      if(*type > 65535){ 
        // the data comes from a machine with different endianness and
        // we must swap the bytes
        *swap = 1;
        _SwapBytes((char*)type, sizeof(int), 1);
      }
      if(_ReceiveData(len, sizeof(int))){
        if(*len < 0) return 0;
        if(*swap) _SwapBytes((char*)len, sizeof(int), 1);
        return 1;
      }
    }
    return 0;
  }
  int ReceiveMessage(int len, void *buffer)
  {
    if(_ReceiveData(buffer, len) == len) return 1;
    return 0;
  }
  // str should be allocated with size (len+1)
  int ReceiveString(int len, char *str)
  {
    if(_ReceiveData(str, len) == len) {
      str[len] = '\0';
      return 1;
    }
    return 0;
  }
  void CloseSocket(int s)
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    close(s);
#else
    closesocket(s);
#endif
  }
  void ShutdownSocket(int s)
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    shutdown(s, SHUT_RDWR);
#endif
  }
};

class GmshClient : public GmshSocket {
 public:
  GmshClient() : GmshSocket() {}
  ~GmshClient(){}
  int Connect(const char *sockname)
  {
    // slight delay to make sure that the socket is bound by the
    // server before we attempt to connect to it
    _Sleep(100);
    if(strstr(sockname, "/") || strstr(sockname, "\\") || !strstr(sockname, ":")){
#if !defined(WIN32) || defined(__CYGWIN__)
      // UNIX socket (testing ":" is not enough with Windows paths)
      _sock = socket(PF_UNIX, SOCK_STREAM, 0);
      if(_sock < 0) return -1;
      // try to connect socket to given name
      struct sockaddr_un addr_un;
      memset((char *) &addr_un, 0, sizeof(addr_un));
      addr_un.sun_family = AF_UNIX;
      strcpy(addr_un.sun_path, sockname);
      for(int tries = 0; tries < 5; tries++) {
        if(connect(_sock, (struct sockaddr *)&addr_un, sizeof(addr_un)) >= 0)
          return _sock;
        _Sleep(100);
      }
#else
      return -1; // Unix sockets are not available on Windows
#endif
    }
    else{
      // TCP/IP socket
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0) return -1;
      // try to connect socket to host:port
      const char *port = strstr(sockname, ":");
      int portno = atoi(port + 1);
      int remotelen = strlen(sockname) - strlen(port);
      char remote[256];
      if(remotelen > 0)
        strncpy(remote, sockname, remotelen);
      remote[remotelen] = '\0';
      struct hostent *server;
      if(!(server = gethostbyname(remote))){
        CloseSocket(_sock);
        return -3; // no such host
      }
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      memcpy((char *)&addr_in.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      addr_in.sin_port = htons(portno);
      for(int tries = 0; tries < 5; tries++) {
        if(connect(_sock, (struct sockaddr *)&addr_in, sizeof(addr_in)) >= 0){
          return _sock;
	}
        _Sleep(100);
      }
    }
    CloseSocket(_sock);
    return -2; // couldn't connect
  }
  void Start()
  {
    char tmp[256];
#if !defined(WIN32) || defined(__CYGWIN__)
    sprintf(tmp, "%d", getpid());
#else
    sprintf(tmp, "%d", _getpid());
#endif
    SendString(GMSH_START, tmp);
  }
  void Stop(){ SendString(GMSH_STOP, "Goodbye!"); }
  void Disconnect(){ CloseSocket(_sock); }
};

class GmshServer : public GmshSocket{
 private:
  int _portno;
 public:
  GmshServer() : GmshSocket(), _portno(-1) {}
  virtual ~GmshServer(){}
  virtual int SystemCall(const char *str) = 0;
  virtual int NonBlockingWait(int socket, double waitint, double timeout) = 0;
  int Start(const char *command, const char *sockname, double timeout)
  {
    if(!sockname) throw "Invalid (null) socket name";
    _sockname = sockname;
    int tmpsock;
    if(strstr(_sockname.c_str(), "/") || strstr(_sockname.c_str(), "\\") ||
       !strstr(_sockname.c_str(), ":")){
      // UNIX socket (testing ":" is not enough with Windows paths)
      _portno = -1;
#if !defined(WIN32) || defined(__CYGWIN__)
      // delete the file if it already exists
      unlink(_sockname.c_str());
      // create a socket
      tmpsock = socket(PF_UNIX, SOCK_STREAM, 0);
      if(tmpsock < 0) throw "Couldn't create socket";
      // bind the socket to its name
      struct sockaddr_un addr_un;
      memset((char *) &addr_un, 0, sizeof(addr_un));
      strcpy(addr_un.sun_path, _sockname.c_str());
      addr_un.sun_family = AF_UNIX;
      if(bind(tmpsock, (struct sockaddr *)&addr_un, sizeof(addr_un)) < 0){
        CloseSocket(tmpsock);
        throw "Couldn't bind socket to name";
      }
      // change permissions on the socket name in case it has to be rm'd later
      chmod(_sockname.c_str(), 0666);
#else
      throw "Unix sockets not available on Windows";
#endif
    }
    else{
      // TCP/IP socket: valid names are either explicit ("hostname:12345")
      // or implicit ("hostname:", "hostname: ", "hostname:0") in which case
      // the system attributes at random an available port
      const char *port = strstr(_sockname.c_str(), ":");
      _portno = atoi(port + 1);
      // create a socket
      tmpsock = socket(AF_INET, SOCK_STREAM, 0);
#if !defined(WIN32) || defined(__CYGWIN__)
      if(tmpsock < 0)
#else
      if(tmpsock == INVALID_SOCKET)
#endif
        throw "Couldn't create socket";
      // bind the socket to its name
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      addr_in.sin_addr.s_addr = INADDR_ANY;
      addr_in.sin_port = htons(_portno); // random assign if _portno == 0
      if(bind(tmpsock, (struct sockaddr *)&addr_in, sizeof(addr_in)) < 0){
        CloseSocket(tmpsock);
        throw "Couldn't bind socket to name";
      }
      if(!_portno){ // retrieve name if randomly assigned port
        socklen_t addrlen = sizeof(addr_in);
        int rc = getsockname(tmpsock, (struct sockaddr *)&addr_in, &addrlen);
        _portno = ntohs(addr_in.sin_port);
	int pos = _sockname.find(':'); // remove trailing ' ' or '0'
        char tmp[256];
	sprintf(tmp, "%s:%d", _sockname.substr(0, pos).c_str(), _portno);
        _sockname.assign(tmp);
      }
    }

    if(command && strlen(command)){
      // we assume that the command line always ends with the socket name
      std::string cmd(command);
      cmd += " " + _sockname;
#if !defined(WIN32)
      cmd += " &";
#endif
      SystemCall(cmd.c_str()); // starts the solver
    }
    else{
      timeout = 0.; // no command launched: don't set a timeout
    }

    // listen on socket (queue up to 20 connections before having
    // them automatically rejected)
    if(listen(tmpsock, 20)){
      CloseSocket(tmpsock);
      throw "Socket listen failed";
    }
    
    // wait until we get data
    int ret = NonBlockingWait(tmpsock, 0.5, timeout);
    if(ret){
      CloseSocket(tmpsock);
      if(ret == 2){
        throw "Socket listening timeout";
      }
      else{
        return -1; // stopped listening
      }
    }

    // accept connection request
    if(_portno < 0){
#if !defined(WIN32) || defined(__CYGWIN__)
      struct sockaddr_un from_un;
      socklen_t len = sizeof(from_un);
      _sock = accept(tmpsock, (struct sockaddr *)&from_un, &len);
#endif
    }
    else{
      struct sockaddr_in from_in;
      socklen_t len = sizeof(from_in);
      _sock = accept(tmpsock, (struct sockaddr *)&from_in, &len);
    }
    CloseSocket(tmpsock);

    if(_sock < 0)
      throw "Socket accept failed";
    return _sock;
  }
  int Shutdown()
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    if(_portno < 0)
      unlink(_sockname.c_str());
#endif
    ShutdownSocket(_sock);
    CloseSocket(_sock);
    return 0;
  }
};  

#endif

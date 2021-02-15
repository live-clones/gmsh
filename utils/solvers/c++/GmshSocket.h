// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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

#ifndef GMSH_SOCKET_H
#define GMSH_SOCKET_H

//#include "GmshConfig.h"

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
#include <netinet/tcp.h>
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
    GMSH_START               = 1,
    GMSH_STOP                = 2,
    GMSH_INFO                = 10,
    GMSH_WARNING             = 11,
    GMSH_ERROR               = 12,
    GMSH_PROGRESS            = 13,
    GMSH_MERGE_FILE          = 20,
    GMSH_PARSE_STRING        = 21,
    GMSH_VERTEX_ARRAY        = 22,
    GMSH_PARAMETER           = 23,
    GMSH_PARAMETER_QUERY     = 24,
    GMSH_PARAMETER_QUERY_ALL = 25,
    GMSH_PARAMETER_QUERY_END = 26,
    GMSH_CONNECT             = 27,
    GMSH_OLPARSE             = 28,
    GMSH_PARAMETER_NOT_FOUND = 29,
    GMSH_SPEED_TEST          = 30,
    GMSH_PARAMETER_CLEAR     = 31,
    GMSH_PARAMETER_UPDATE    = 32,
    GMSH_OPEN_PROJECT        = 33,
    GMSH_CLIENT_CHANGED      = 34,
    GMSH_PARAMETER_WITHOUT_CHOICES = 35,
    GMSH_PARAMETER_QUERY_WITHOUT_CHOICES = 36,
    GMSH_OPTION_1            = 100,
    GMSH_OPTION_2            = 101,
    GMSH_OPTION_3            = 102,
    GMSH_OPTION_4            = 103,
    GMSH_OPTION_5            = 104};
 protected:
  // the socket descriptor
  int _sock;
  // the socket name
  std::string _sockname;
  // statistics
  unsigned long int _sent, _received;
  // send some data over the socket
  int _sendData(const void *buffer, int bytes)
  {
    const char *buf = (const char *)buffer;
    long int sofar = 0;
    long int remaining = bytes;
    do {
      long int len = send(_sock, buf + sofar, remaining, 0);
      if(len < 0) return -1; // error
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
    _sent += bytes;
    return bytes;
  }
  // receive some data over the socket
  int _receiveData(void *buffer, int bytes)
  {
    char *buf = (char *)buffer;
    long int sofar = 0;
    long int remaining = bytes;
    do {
      long int len = recv(_sock, buf + sofar, remaining, 0);
      if(len == 0) break; // we're done!
      if(len < 0) return -1; // error
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
    _received += bytes;
    return bytes;
  }
  // utility function to swap bytes in an array
  void _swapBytes(char *array, int size, int n)
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
  void _sleep(int ms)
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    usleep(1000 * ms);
#else
    Sleep(ms);
#endif
  }
 public:
  GmshSocket() : _sock(0), _sent(0), _received(0)
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
  // Wait for some data to read on the socket (if seconds and microseconds == 0
  // we check for available data and return immediately, i.e., we do
  // polling). Returns 1 when data is available, 0 when nothing happened before
  // the time delay, -1 on error.
  int Select(int seconds, int microseconds, int socket=-1)
  {
    int s = (socket < 0) ? _sock : socket;
    struct timeval tv;
    tv.tv_sec = seconds;
    tv.tv_usec = microseconds;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s, &rfds);
    // select checks all IO descriptors between 0 and its first arg, minus 1;
    // hence the +1 below
    return select(s + 1, &rfds, nullptr, nullptr, &tv);
  }
  void SendMessage(int type, int length, const void *msg)
  {
    // send header (type + length)
    _sendData(&type, sizeof(int));
    _sendData(&length, sizeof(int));
    // send body
    _sendData(msg, length);
  }
  void SendString(int type, const char *str)
  {
    SendMessage(type, (int)strlen(str), str);
  }
  void Info(const char *str){ SendString(GMSH_INFO, str); }
  void Warning(const char *str){ SendString(GMSH_WARNING, str); }
  void Error(const char *str){ SendString(GMSH_ERROR, str); }
  void Progress(const char *str){ SendString(GMSH_PROGRESS, str); }
  void MergeFile(const char *str){ SendString(GMSH_MERGE_FILE, str); }
  void OpenProject(const char *str){ SendString(GMSH_OPEN_PROJECT, str); }
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
    if(_receiveData(type, sizeof(int)) > 0){
      if(*type > 65535){
        // the data comes from a machine with different endianness and
        // we must swap the bytes
        *swap = 1;
        _swapBytes((char*)type, sizeof(int), 1);
      }
      if(_receiveData(len, sizeof(int)) > 0){
        if(*swap) _swapBytes((char*)len, sizeof(int), 1);
        return 1;
      }
    }
    return 0;
  }
  int ReceiveMessage(int len, void *buffer)
  {
    if(_receiveData(buffer, len) == len) return 1;
    return 0;
  }
  // str should be allocated with size (len+1)
  int ReceiveString(int len, char *str)
  {
    if(_receiveData(str, len) == len) {
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
  unsigned long int SentBytes(){ return _sent; }
  unsigned long int ReceivedBytes(){ return _received; }
};

class GmshClient : public GmshSocket {
 public:
  GmshClient() : GmshSocket() {}
  ~GmshClient(){}
  int Connect(const char *sockname)
  {
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
        _sleep(100);
      }
#else
      return -1; // Unix sockets are not available on Windows
#endif
    }
    else{
      // TCP/IP socket
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0) return -1;
      char one = 1;
      // disable Nagle's algorithm (very slow for many small messages)
      setsockopt(_sock, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one));
      // try to connect socket to host:port
      const char *port = strstr(sockname, ":");
      int portno = atoi(port + 1);
      char *remote = strdup(sockname);
      int remotelen = (int)(strlen(remote) - strlen(port));
      if(remotelen > 0)
        strncpy(remote, sockname, remotelen);
      if(remotelen >= 0)
        remote[remotelen] = '\0';
      struct hostent *server;
      if(!(server = gethostbyname(remote))){
        CloseSocket(_sock);
        free(remote);
        return -3; // no such host
      }
      free(remote);
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      memcpy((char *)&addr_in.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      addr_in.sin_port = htons(portno);
      for(int tries = 0; tries < 5; tries++) {
        if(connect(_sock, (struct sockaddr *)&addr_in, sizeof(addr_in)) >= 0){
          return _sock;
	}
        _sleep(100);
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
  virtual int NonBlockingSystemCall(const std::string &exe, const std::string &args) = 0;
  virtual int NonBlockingWait(double waitint, double timeout, int socket=-1) = 0;
  // start the client by launching "exe args" (args is supposed to contain
  // '%s' where the socket name should appear)
  int Start(const std::string &exe, const std::string &args, const std::string &sockname,
            double timeout)
  {
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
      char one = 1;
      setsockopt(tmpsock, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one));

#if !defined(WIN32) || defined(__CYGWIN__)
      if(tmpsock < 0)
#else
      if(tmpsock == (int)INVALID_SOCKET)
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
        getsockname(tmpsock, (struct sockaddr *)&addr_in, &addrlen);
        _portno = ntohs(addr_in.sin_port);
	int pos = (int)_sockname.find(':'); // remove trailing ' ' or '0'
        char tmp[256];
	sprintf(tmp, "%s:%d", _sockname.substr(0, pos).c_str(), _portno);
        _sockname.assign(tmp);
      }
    }

    if(exe.size() || args.size()){
      char s[1024];
      sprintf(s, args.c_str(), _sockname.c_str());
      NonBlockingSystemCall(exe, s); // starts the solver
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
    int ret = NonBlockingWait(0.001, timeout, tmpsock);
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
      char one = 1;
      setsockopt(_sock, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one));
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

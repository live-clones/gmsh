// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_SOCKET_H_
#define _GMSH_SOCKET_H_

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
#else
#include <winsock.h>
#include <process.h>
#endif

class GmshSocket{
 public:
  // types of messages that can be exchanged (never use values greater
  // that 65535: if we receive a type > 65535 we assume that we
  // receive data from a machine with a different byte ordering, and
  // we swap the bytes in the payload)
  enum MessageType{ 
    CLIENT_START        = 1,
    CLIENT_STOP         = 2,
    CLIENT_INFO         = 10,
    CLIENT_WARNING      = 11,
    CLIENT_ERROR        = 12,
    CLIENT_PROGRESS     = 13,
    CLIENT_MERGE_FILE   = 20, // old name: CLIENT_VIEW
    CLIENT_PARSE_STRING = 21,
    CLIENT_SPEED_TEST   = 30,
    CLIENT_OPTION_1     = 100,
    CLIENT_OPTION_2     = 101,
    CLIENT_OPTION_3     = 102,
    CLIENT_OPTION_4     = 103,
    CLIENT_OPTION_5     = 104};
 protected:
  // the socket descriptor
  int _sock;
  // the socket name
  const char *_sockname;
  // send some data over the socket
  void _SendData(const void *buffer, int bytes)
  {
    const char *buf = (const char *)buffer;
    int sofar = 0;
    int remaining = bytes;
    do {
      ssize_t len = send(_sock, buf + sofar, remaining, 0); 
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
      if(len <= 0)
        return 0;
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
  GmshSocket() : _sock(0), _sockname(0)
  {
#if defined(WIN32) && !defined(__CYGWIN__)
    static bool first = true;
    if(first){
      first = false;
      WSADATA wsaData;
      WSAStartup(MAKEWORD(2, 2), &wsaData);
    }
#endif
  }
  ~GmshSocket()
  {
#if defined(WIN32) && !defined(__CYGWIN__)
    WSACleanup();
#endif
  }
  // utility function to wait for some data to read on a socket (if
  // seconds==0 we check for available data and return immediately,
  // i.e., we do polling)
  int Select(int socket, int seconds)
  {
    struct timeval tv;
    tv.tv_sec = seconds;
    tv.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket, &rfds);
    // select checks all IO descriptors between 0 and its first arg,
    // minus 1... hence the +1 below
    return select(socket + 1, &rfds, NULL, NULL, &tv);
  }
  void SendString(int type, const char *str)
  {
    // send header (type + length)
    _SendData(&type, sizeof(int));
    int len = strlen(str);
    _SendData(&len, sizeof(int));
    // send body
    _SendData(str, len);
  }
  int ReceiveHeader(int *type, int *len)
  {
    bool swap = false;
    if(_ReceiveData(type, sizeof(int))){
      if(*type < 0) return 0;
      if(*type > 65535){ 
        // the data comes from a machine with different endianness and
        // we must swap the bytes
        swap = true;
        _SwapBytes((char*)type, sizeof(int), 1);
      }
      if(_ReceiveData(len, sizeof(int))){
        if(*len < 0) return 0;
        if(swap) _SwapBytes((char*)len, sizeof(int), 1);
        return 1;
      }
    }
    return 0;
  }
  int ReceiveString(int len, char *str)
  {
    if(_ReceiveData(str, len) == len) {
      str[len] = '\0';
      return 1;
    }
    return 0;
  }
};

class GmshClient : public GmshSocket {
 public:
  GmshClient() : GmshSocket() {}
  ~GmshClient(){}
  int Connect(const char *sockname)
  {
    // slight delay to be sure that the socket is bound by the
    // server before we attempt to connect to it...
    _Sleep(100);

    if(strstr(sockname, "/") || strstr(sockname, "\\") || !strstr(sockname, ":")){
#if !defined(WIN32) || defined(__CYGWIN__)
      // UNIX socket (testing ":" is not enough with Windows paths)
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
	_Sleep(100);
      }
#else
      return -1; // Unix sockets are not available on Windows
#endif
    }
    else{
      // TCP/IP socket
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
	return -1; // Error: Couldn't create socket
      // try to connect socket to host:port
      char *port = strstr(sockname, ":");
      int portno = atoi(port + 1);
      int remotelen = strlen(sockname) - strlen(port);
      char remote[256];
      if(remotelen > 0)
	strncpy(remote, sockname, remotelen);
      remote[remotelen] = '\0';
      struct hostent *server;
      if(!(server = gethostbyname(remote)))
	return -3; // Error: No such host
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      memcpy((char *)&addr_in.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      addr_in.sin_port = htons(portno);
      for(int tries = 0; tries < 5; tries++) {
	if(connect(_sock, (struct sockaddr *)&addr_in, sizeof(addr_in)) >= 0)
	  return _sock;
	_Sleep(100);
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
    SendString(CLIENT_START, tmp);
  }
  void Stop()
  {
    SendString(CLIENT_STOP, "Goodbye!");
  }
  void Info(const char *str)
  {
    SendString(CLIENT_INFO, str);
  }
  void Warning(const char *str)
  {
    SendString(CLIENT_WARNING, str);
  }
  void Error(const char *str)
  {
    SendString(CLIENT_ERROR, str);
  }
  void Progress(const char *str)
  {
    SendString(CLIENT_PROGRESS, str);
  }
  void View(const char *str) 
  {
    // deprecated: use MergeFile(str) instead
    SendString(CLIENT_MERGE_FILE, str);
  }
  void MergeFile(const char *str)
  {
    SendString(CLIENT_MERGE_FILE, str);
  }
  void ParseString(const char *str)
  {
    SendString(CLIENT_PARSE_STRING, str);
  }
  void Option(int num, const char *str)
  {
    if(num < 1) num = 1;
    if(num > 5) num = 5;
    SendString(CLIENT_OPTION_1 + num - 1, str);
  }
  void Disconnect()
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    close(_sock);
#else
    closesocket(_sock);
#endif
  }

};

class GmshServer : public GmshSocket{
 private:
  int _portno;
 public:
  GmshServer() : GmshSocket(), _portno(-1) {}
  ~GmshServer(){}
  virtual int SystemCall(const char *str) = 0;
  virtual int NonBlockingWait(int socket, int num, double waitint) = 0;
  int StartClient(const char *command, const char *sockname=0, int maxdelay=4)
  {
    int justwait = (!command || !strlen(command));
    _sockname = sockname;

    // no socket? launch the command directly
    if(!_sockname) {
      SystemCall(command);
      return 1;
    }

    int tmpsock;
    if(strstr(_sockname, "/") || strstr(_sockname, "\\") || !strstr(_sockname, ":")){
      // UNIX socket (testing ":" is not enough with Windows paths)
      _portno = -1;
#if !defined(WIN32) || defined(__CYGWIN__)
      // delete the file if it already exists
      unlink(_sockname);
      // create a socket
      tmpsock = socket(PF_UNIX, SOCK_STREAM, 0);
      if(tmpsock < 0)
        return -1;  // Error: Couldn't create socket
      // bind the socket to its name
      struct sockaddr_un addr_un;
      memset((char *) &addr_un, 0, sizeof(addr_un));
      strcpy(addr_un.sun_path, _sockname);
      addr_un.sun_family = AF_UNIX;
      if(bind(tmpsock, (struct sockaddr *)&addr_un, sizeof(addr_un)) < 0)
        return -2;  // Error: Couldn't bind socket to name
      // change permissions on the socket name in case it has to be rm'd later
      chmod(_sockname, 0666);
#else
      return -7; // Unix sockets not available on Windows without Cygwin
#endif
    }
    else{
      // TCP/IP socket
      const char *port = strstr(_sockname, ":");
      _portno = atoi(port + 1);
      // create a socket
      tmpsock = socket(AF_INET, SOCK_STREAM, 0);
#if !defined(WIN32) || defined(__CYGWIN__)
      if(tmpsock < 0)
#else
      if(tmpsock == INVALID_SOCKET)
#endif
        return -1;  // Error: Couldn't create socket
      // bind the socket to its name
      struct sockaddr_in addr_in;
      memset((char *) &addr_in, 0, sizeof(addr_in));
      addr_in.sin_family = AF_INET;
      addr_in.sin_addr.s_addr = INADDR_ANY;
      addr_in.sin_port = htons(_portno);
      if(bind(tmpsock, (struct sockaddr *)&addr_in, sizeof(addr_in)) < 0)
        return -2;  // Error: Couldn't bind socket to name
    }

    if(!justwait)
      SystemCall(command); // Start the solver
    
    // listen on socket (queue up to 20 connections before having
    // them automatically rejected)
    if(listen(tmpsock, 20))
      return -3;  // Error: Socket listen failed
    
    if(justwait){
      // wait indefinitely until we get data
      if(NonBlockingWait(tmpsock, -1, 0.5))
        return -6; // not an actual error: we just stopped listening
    }
    else{
      // Wait at most maxdelay seconds for data, issue error if no
      // connection in that amount of time
      if(!Select(tmpsock, maxdelay))
        return -4;  // Error: Socket listening timeout
    }

    // accept connection request
#if defined(HAVE_NO_SOCKLEN_T)
    int len;
#else
    socklen_t len;
#endif
    if(_portno < 0){
#if !defined(WIN32) || defined(__CYGWIN__)
      struct sockaddr_un from_un;
      len = sizeof(from_un);
      _sock = accept(tmpsock, (struct sockaddr *)&from_un, &len);
#else
      _sock = -7; // Unix sockets not available on Windows
#endif
    }
    else{
      struct sockaddr_in from_in;
      len = sizeof(from_in);
      _sock = accept(tmpsock, (struct sockaddr *)&from_in, &len);
    }
    if(_sock < 0) return -5;  // Error: Socket accept failed

    // close temporary socket
#if !defined(WIN32) || defined(__CYGWIN__)
    close(tmpsock);
#else
    closesocket(tmpsock);
#endif
    return _sock;
  }
  int StopClient()
  {
#if !defined(WIN32) || defined(__CYGWIN__)
    if(_portno < 0)
      unlink(_sockname);
    close(_sock);
#else
    closesocket(_sock);
#endif
    return 0;
  }
};  

#endif

#ifndef _GMSH_SERVER_H_
#define _GMSH_SERVER_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   Christopher Stott

void SystemCall(char *str); // use our own instead of 'system()'

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

class GmshServer {
 public:
  // This should match what's in GmshClient.h
  typedef enum{ CLIENT_START    = 1,
		CLIENT_STOP     = 2,
		CLIENT_INFO     = 10,
		CLIENT_WARNING  = 11,
		CLIENT_ERROR    = 12,
		CLIENT_PROGRESS = 13,
		CLIENT_VIEW     = 20,
		CLIENT_OPTION_1 = 100,
		CLIENT_OPTION_2 = 101,
		CLIENT_OPTION_3 = 102,
		CLIENT_OPTION_4 = 103,
		CLIENT_OPTION_5 = 104 } MessageType;
 private:
  int _maxdelay, _portno, _sock;
  char *_sockname;
  int _ReceiveData(void *buffer, int bytes)
  {
    char *buf = (char *)buffer;
    int sofar = 0;
    int remaining = bytes;
    do {
      int len = read(_sock, buf + sofar, remaining);
      if(len <= 0)
	return 0;
      sofar += len;
      remaining -= len;
    } while(remaining > 0);
    return bytes;
  }
 public:
  GmshServer(int maxdelay = 4)
    : _maxdelay(maxdelay), _portno(-1), _sock(0), _sockname(NULL) {}
  ~GmshServer(){}
  int StartClient(char *command, char *sockname = NULL)
  {
    static int init = 0;
    static int s;

    _sockname = sockname;

    // no socket? launch the command directly
    if(!_sockname) {
      SystemCall(command);
      //system(command);
      return 1;
    }

    if(strstr(_sockname, "/") || strstr(_sockname, "\\") || !strstr(_sockname, ":")){
      // UNIX socket (testing ":" is not enough with Windows paths)
      _portno = -1;
    }
    else{
      // INET socket
      char *port = strstr(_sockname, ":");
      _portno = atoi(port+1);
    }
    
    if(_portno < 0){
      // delete the file if it already exists
      unlink(_sockname);
      
      // make the socket
      s = socket(PF_UNIX, SOCK_STREAM, 0);
      if(s < 0)
	return -1;  // Error: Couldn't create socket
      
      // bind the socket to its name
      struct sockaddr_un addr_un;
      strcpy(addr_un.sun_path, _sockname);
      addr_un.sun_family = AF_UNIX;
      if(bind(s, (struct sockaddr *)&addr_un, sizeof(addr_un)) < 0)
	return -2;  // Error: Couldn't bind socket to name
      
      // change permissions on the socket name in case it has to be rm'd later
      chmod(_sockname, 0666);
    }
    else{
      if(init != _portno){ 
	// FIXME: need a better solution to deal with addresses that
	// have already been bound!
	init = _portno;
	
	// make the socket
	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s < 0)
	  return -1;  // Error: Couldn't create socket
	
	// bind the socket to its name
	struct sockaddr_in addr_in;
	memset((char *) &addr_in, 0, sizeof(addr_in));
	addr_in.sin_family = AF_INET;
	addr_in.sin_addr.s_addr = INADDR_ANY;
	addr_in.sin_port = htons(_portno);
	if(bind(s, (struct sockaddr *)&addr_in, sizeof(addr_in)) < 0)
	  return -2;  // Error: Couldn't bind socket to name
      }
    }

    // Start the solver via system() call
    SystemCall(command);
    //system(command);
    
    // wait for solver to connect
    if(listen(s, 20))
      return -3;  // Error: Socket listen failed
    
    // Watch socket s to see when it has input; wait up to N seconds
    struct timeval tv;
    tv.tv_sec = _maxdelay;
    tv.tv_usec = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(s, &rfds);
    if(!select(s + 1, &rfds, NULL, NULL, &tv))
      return -4;  // Error: Socket listening timeout
    
    // accept connection request
#if defined(HAVE_NO_SOCKLEN_T)
    int len;
#else
    socklen_t len;
#endif
    if(_portno < 0){
      struct sockaddr_un from_un;
      len = sizeof(from_un);
      if((_sock = accept(s, (struct sockaddr *)&from_un, &len)) < 0)
	return -5;  // Error: Socket accept failed
    }
    else{
      struct sockaddr_in from_in;
      len = sizeof(from_in);
      if((_sock = accept(s, (struct sockaddr *)&from_in, &len)) < 0)
	return -5;  // Error: Socket accept failed
    }
   
    return _sock;
  }
  int ReceiveString(int *type, char str[])
  {
    _ReceiveData(type, sizeof(int));
    int len;
    if(_ReceiveData(&len, sizeof(int))) {
      if(_ReceiveData(str, len) == len) {
	str[len] = '\0';
	return 1;
      }
    }
    return 0;
  }
  int StopClient()
  {
    if(_portno < 0){
      // UNIX socket
      if(unlink(_sockname) == -1)
	return -1;  // Impossible to unlink the socket
    }
    close(_sock);
    return 0;
  }
};

#endif

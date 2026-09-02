// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_BROWSER)

#include <cstring>
#include <string>
#include <vector>

#if defined(WIN32)
#include <winsock2.h>
typedef int socklen_t;
#define CLOSE_SOCKET closesocket
#else
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#define CLOSE_SOCKET close
#define INVALID_SOCKET (-1)
typedef int SOCKET;
#endif

#include "httpServer.h"

namespace Browser {

  namespace {

    SOCKET _listening = INVALID_SOCKET;

    void _dontBlock(SOCKET s)
    {
#if defined(WIN32)
      u_long on = 1;
      ioctlsocket(s, FIONBIO, &on);
#else
      int flags = fcntl(s, F_GETFL, 0);
      fcntl(s, F_SETFL, flags | O_NONBLOCK);
#endif
    }

    // Read until the head is complete and the body with it. A browser sends a
    // request in one go on a local connection, so a short wait is enough; this
    // is not meant to stand up to anything but a page it serves itself.
    bool _read(SOCKET s, Ask &ask)
    {
      std::string got;
      char buffer[4096];
      for(int tries = 0; tries < 200; tries++) {
        int n = (int)recv(s, buffer, sizeof(buffer), 0);
        if(n > 0) {
          got.append(buffer, n);
          std::string::size_type head = got.find("\r\n\r\n");
          if(head == std::string::npos) continue;
          // how much body was announced
          std::size_t want = 0;
          std::string::size_type at = got.find("Content-Length:");
          if(at != std::string::npos && at < head)
            want = (std::size_t)atoi(got.c_str() + at + 15);
          if(got.size() >= head + 4 + want) {
            std::string::size_type line = got.find("\r\n");
            std::string first = got.substr(0, line);
            std::string::size_type a = first.find(' ');
            std::string::size_type b = first.find(' ', a + 1);
            if(a == std::string::npos || b == std::string::npos) return false;
            ask.path = first.substr(a + 1, b - a - 1);
            ask.body = got.substr(head + 4, want);
            return true;
          }
          continue;
        }
        if(n == 0) return false;
#if !defined(WIN32)
        if(errno != EAGAIN && errno != EWOULDBLOCK) return false;
#endif
        // nothing yet; the rest is on its way
        struct timeval wait;
        wait.tv_sec = 0;
        wait.tv_usec = 1000;
        fd_set in;
        FD_ZERO(&in);
        FD_SET(s, &in);
        select((int)s + 1, &in, nullptr, nullptr, &wait);
      }
      return false;
    }

    void _write(SOCKET s, const std::string &body, const char *type)
    {
      std::string out = "HTTP/1.1 200 OK\r\nContent-Type: ";
      out += type;
      out += "\r\nContent-Length: " + std::to_string(body.size());
      out += "\r\nCache-Control: no-store\r\nConnection: close\r\n\r\n";
      out += body;
      std::size_t sent = 0;
      while(sent < out.size()) {
        int n = (int)send(s, out.c_str() + sent, (int)(out.size() - sent), 0);
        if(n <= 0) break;
        sent += n;
      }
    }

  } // namespace

  int listen(int wanted)
  {
#if defined(WIN32)
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
#endif
    _listening = socket(AF_INET, SOCK_STREAM, 0);
    if(_listening == INVALID_SOCKET) return 0;
    int on = 1;
    setsockopt(_listening, SOL_SOCKET, SO_REUSEADDR, (const char *)&on,
               sizeof(on));
    struct sockaddr_in where;
    memset(&where, 0, sizeof(where));
    where.sin_family = AF_INET;
    // only from this machine: it is a window onto this process, not a service
    where.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    for(int port = wanted; port < wanted + 64; port++) {
      where.sin_port = htons((unsigned short)port);
      if(bind(_listening, (struct sockaddr *)&where, sizeof(where)) == 0) {
        if(::listen(_listening, 8) != 0) break;
        _dontBlock(_listening);
        return port;
      }
    }
    CLOSE_SOCKET(_listening);
    _listening = INVALID_SOCKET;
    return 0;
  }

  void stop()
  {
    if(_listening != INVALID_SOCKET) CLOSE_SOCKET(_listening);
    _listening = INVALID_SOCKET;
  }

  void serve(const std::function<std::string(const Ask &, std::string &type)>
               &answer)
  {
    if(_listening == INVALID_SOCKET) return;
    while(true) {
      SOCKET talking = accept(_listening, nullptr, nullptr);
      if(talking == INVALID_SOCKET) return; // nothing waiting
      Ask ask;
      if(_read(talking, ask)) {
        std::string type = "application/json";
        std::string body = answer(ask, type);
        _write(talking, body, type.c_str());
      }
      CLOSE_SOCKET(talking);
    }
  }

} // namespace Browser

#endif

#ifndef _ONELABEXCEPTION_H_
#define _ONELABEXCEPTION_H_
#include <exception>

//class OnelabException : public std::exception


class NetworkException : public std::exception
{
 private:
  int _code;

 public:
  NetworkException(int code) : _code(code) {}

  typedef enum {
    Create,
    Bind,
    Connect,
    Listen,
    Send,
    Recv,
    nUnix
  } NetworkExceptionCode;

  virtual const char* what(){
    switch(_code) {
      case Create:
        return "Unable to create the socket";
      case Bind:
        return "Unable to bind the socket";
      case Connect:
        return "Unable to connect the socket";
      case Listen:
        return "Unable to listen on the socket";
      case Send:
        return "Unable to send on the socket";
      case Recv:
        return "Unable to recv on the socket";
      case nUnix:
        return "UNIX sockets are unavailable";
      default:
        return "Unkonown error with the socket";
    }
  }
};

#endif

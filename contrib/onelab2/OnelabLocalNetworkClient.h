#ifndef _ONELABLOCALNETWORKCLIENT_H_
#define _ONELABLOCALNETWORKCLIENT_H_

#include <string>
#include "onelab.h"
#ifdef HAVE_UDT
#include "UdtUtils.h"
#endif
#include "NetworkUtils.h"
#include "OnelabProtocol.h"

class OnelabLocalNetworkClient
{
private:
  Socket _fds;
#ifdef HAVE_UDT
  UDTSOCKET _fdu;
#endif
  IPv4 _ip;
  std::string _name;
  pthread_mutex_t _mutex_wait;
public:
#ifdef HAVE_UDT
  OnelabLocalNetworkClient(std::string name, UDTSOCKET fd, unsigned int ip, unsigned short port, bool UDT);
  UDTSOCKET getUSocket() {return _fdu;}
#endif
  OnelabLocalNetworkClient(std::string name, Socket fd, unsigned int ip, unsigned short port);
  virtual ~OnelabLocalNetworkClient(){}
  void sendto(UInt8 *buff, unsigned int len);
  int recvfrom(UInt8 *buff, unsigned int maxlen);
  int recvmsg(OnelabProtocol &msg);
  Socket getSSocket() {return _fds;}
  std::string getName() {return _name;}
  void updateParameter(onelab::parameter *);
  unsigned int getIp() {return _ip.address;}
  unsigned short getPort() {return _ip.port;}

  void run(std::string action);
};
#endif

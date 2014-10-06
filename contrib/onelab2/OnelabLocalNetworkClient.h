#ifndef _ONELABLOCALNETWORKCLIENT_H_
#define _ONELABLOCALNETWORKCLIENT_H_

#include <string>
#include "onelab.h"
//#ifdef HAVE_UDT
#include "UdtUtils.h"
//#else
//#include "NetworkUtils.h"
//#endif

class OnelabLocalNetworkClient
{
private:
  Socket _fds;
//#ifdef HAVE_UDT
	UDTSOCKET _fdu;
//#endif
	IPv4 _ip;
	std::string _name;
public:
//#ifdef HAVE_UDT
	OnelabLocalNetworkClient(std::string name, UDTSOCKET fd, unsigned int ip, unsigned short port, bool UDT);
//#endif
	OnelabLocalNetworkClient(std::string name, Socket fd, unsigned int ip, unsigned short port);
	void sendto(UInt8 *buff, unsigned int len);
	int recvfrom(UInt8 *buff, unsigned int maxlen);
	UDTSOCKET getSSocket() {return _fds;}
	UDTSOCKET getUSocket() {return _fdu;}
	virtual ~OnelabLocalNetworkClient(){}
	std::string getName() {return _name;}
  void updateParameter(onelab::parameter *);
	unsigned int getIp() {return _ip.address;}
	unsigned short getPort() {return _ip.port;}

  void run() {}
  void stop() {}
};
#endif

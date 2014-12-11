#include "OnelabLocalNetworkClient.h"
#include "OnelabProtocol.h"

//#ifdef HAVE_UDT
OnelabLocalNetworkClient::OnelabLocalNetworkClient(std::string name, UDTSOCKET fd, unsigned int ip, unsigned short port, bool UDT)
{
	_name = name;
  _fds = 0;
	_fdu = fd;
	_ip.address = ip;
	_ip.port = port;
}
//#endif
OnelabLocalNetworkClient::OnelabLocalNetworkClient(std::string name, Socket fd, unsigned int ip, unsigned short port)
{
	_name = name;
  _fdu = 0;
	_fds = fd;
	_ip.address = ip;
	_ip.port = port;
}
void OnelabLocalNetworkClient::sendto(UInt8 *buff, unsigned int len)
{
//#ifdef HAVE_UDT
	if(_fds) ip4_socket_send(_fds, buff, len, _ip);
  else udt_socket_send(_fdu, buff, len);
//#else
//	return ip4_socket_send(_fds, buff, maxlen);
//#endif
}
int OnelabLocalNetworkClient::recvfrom(UInt8 *buff, unsigned int maxlen)
{
  IPv4 unused;
//#ifdef HAVE_UDT
	if(_fds) return ip4_socket_recv(_fds, buff, maxlen, unused);
	return udt_socket_recv(_fdu, buff, maxlen);
//#else
//	return ip4_socket_recv(_fds, buff, maxlen);
//#endif
}
int OnelabLocalNetworkClient::recvmsg(OnelabProtocol &msg)
{
  UInt8 header[8];
  UInt8 *buff = NULL;
  int recvlen = 0;
  // recv the header
  recvlen = recvfrom(header, 4);
  if(recvlen != 4) return recvlen;
  int msglen = msg.parseHeader(header, recvlen);
  // then recv the message
  if(msglen == 0) return 4;
  buff = (UInt8 *) malloc(sizeof(UInt8)*msglen);
  recvlen = recvfrom(buff, msglen); // recvlen should be equals to msglen
  msg.parseMessage(buff, recvlen);
  free(buff);
  return recvlen + 4;
}
void OnelabLocalNetworkClient::updateParameter(onelab::parameter *p)
{
  OnelabProtocol msg(OnelabProtocol::OnelabUpdate);
  msg.attrs.push_back(p);
  UInt8 buff[1024];
  unsigned int recvlen = msg.encodeMsg(buff, 1024);
  sendto(buff, recvlen);
}
void OnelabLocalNetworkClient::run(std::string action)
{
  OnelabProtocol msg(OnelabProtocol::OnelabAction);
  msg.attrs.push_back(new OnelabAttrAction(action, _name));
  UInt8 buff[1024];
  unsigned int size = msg.encodeMsg(buff, 1024);
  sendto(buff, size);
}

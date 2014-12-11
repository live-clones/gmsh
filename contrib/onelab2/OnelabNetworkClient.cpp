#include <iostream>

#include "OnelabNetworkClient.h"

#ifdef HAVE_UDT
OnelabNetworkClient::OnelabNetworkClient(std::string name, bool UDT)
  : VirtualClient(name)
{
  _fds = 0;
  _fdu = 0;
  _ip.address = 0;
  _ip.port = 0;
  _connected = false;

  IPv4 local;
  local.address = 0;// FIXME ip4_default_iface();
  local.port = 0;
  UDT::startup();
  if(UDT) _fdu = udt_socket(local, SOCK_STREAM);
  else _fds = ip4_socket(local, SOCK_STREAM);
}
OnelabNetworkClient::OnelabNetworkClient(std::string name, unsigned int ip, unsigned short port, bool UDT)
  : VirtualClient(name)
{
  _fds = 0;
  _fdu = 0;
  _ip.address = ip;
  _ip.port = port;
  _connected = false;

  IPv4 local;
  local.address = 0;//ip4_default_iface();
  local.port = 0;
  UDT::startup();
  if(UDT) _fdu = udt_socket(local, SOCK_STREAM);
  else _fds = ip4_socket(local, SOCK_STREAM);
}
#else
OnelabNetworkClient::OnelabNetworkClient(std::string name)
  : VirtualClient(name)
{
  _ip.address = 0;
  _ip.port = 0;
  _connected = false;

  IPv4 local;
  local.address = 0;// FIXME ip4_default_iface();
  local.port = 0;
  _fds = ip4_socket(local, SOCK_STREAM);
}
OnelabNetworkClient::OnelabNetworkClient(std::string name, unsigned int ip, unsigned short port)
  : VirtualClient(name)
{
  _ip.address = ip;
  _ip.port = port;
  _connected = false;

  IPv4 local;
  local.address = 0;//ip4_default_iface();
  local.port = 0;
  _fds = ip4_socket(local, SOCK_STREAM);
}
#endif
void OnelabNetworkClient::sendto(UInt8 *buff, UInt16 len)
{
#ifndef HAVE_UDT
  ip4_socket_send(_fds, buff, len, _ip);
#else
  if(_fds) ip4_socket_send(_fds, buff, len);
  else udt_socket_send(_fdu, buff, len);
#endif
}
int OnelabNetworkClient::recvfrom(UInt8 *buff, UInt16 maxlen)
{
  IPv4 unused;
#ifndef HAVE_UDT
  return ip4_socket_recv(_fds, buff, maxlen, unused); // FIXME check unused == _ip ?
#else
  if(_fds) return ip4_socket_recv(_fds, buff, maxlen); // FIXME check unused == _ip ?
  return udt_socket_recv(_fdu, buff, maxlen);
#endif
}
int OnelabNetworkClient::recvfrom(OnelabProtocol &msg)
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
bool OnelabNetworkClient::connect()
{
  UInt16 bufflen = 1024;
  int recvlen = 0;
  UInt8 buff[1024];
  OnelabProtocol msg(OnelabProtocol::OnelabStart);
  if(_connected) return true;
#ifdef HAVE_UDT
  if(_fds) {
    ip4_socket_connect(_fds, _ip);
  }
  else{
    udt_socket_connect(_fdu, _ip);
  }
#else
  ip4_socket_connect(_fds, _ip);
#endif
  msg.attrs.push_back(new OnelabAttrStart(_name));
  recvlen = msg.encodeMsg(buff, bufflen);
  sendto(buff, recvlen);
#ifdef HAVE_UDT
  udt_socket_timeout(_fdu, 3);
#endif
  ip4_socket_timeout(_fds, 3);
  recvlen = recvfrom(buff, bufflen);

#ifdef HAVE_UDT
  udt_socket_timeout(_fdu, -1);
#endif
  ip4_socket_timeout(_fds, 0);
  if(recvlen <= 0) return false;
  msg.parseMsg(buff, recvlen);
  if(recvlen > 0 && msg.msgType() == OnelabProtocol::OnelabStart) _connected = true;
  return _connected;
}

void OnelabNetworkClient::disconnect()
{
  // Send a message to the server to say the client stop (the server have to reply)
  UInt16 bufflen = 1024, recvlen = 0;
  UInt8 buff[1024];
  OnelabProtocol msg(OnelabProtocol::OnelabStop);
  if(!_connected) return;
  recvlen = msg.encodeMsg(buff, bufflen);
  this->sendto(buff, recvlen);
  _connected = false;
}

void OnelabNetworkClient::request(OnelabProtocol &msg)
{
  UInt16 bufflen = 1024, recvlen = 0;
  UInt8 buff[1024];
  recvlen = msg.encodeMsg(buff, bufflen);
  this->sendto(buff, recvlen);
}

void OnelabNetworkClient::requestParameters()
{
  OnelabProtocol msg(OnelabProtocol::OnelabRequest);
  this->request(msg);
}

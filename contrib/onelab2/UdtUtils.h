#ifndef _UDTUTILS_H_
#define _UDTUTILS_H_
#include <iostream>// FIXME debug only
#include <udt.h>
#include "NetworkUtils.h"

inline UDTSOCKET udt_socket(IPv4 ip, int socketType)
{
	UDTSOCKET fd;
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = hton32((ip.address==0)? INADDR_ANY : ip.address);
	addr.sin_port = hton16(ip.port);

	if(UDT::ERROR == (fd = UDT::socket(AF_INET, socketType, 0))) throw ERROR_SOCKET_CREATE;

	if(UDT::ERROR == UDT::bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {std::cout << UDT::getlasterror().getErrorMessage() << std::endl; throw ERROR_SOCKET_BIND;}

	bool otrue = true;
	UDT::setsockopt(fd, 0, UDT_REUSEADDR, &otrue, sizeof(bool));

	return fd;
}

inline void udt_socket_timeout(UDTSOCKET fd, long ms)
{
	setsockopt(fd, 0, UDT_SNDTIMEO, &ms, sizeof(long));
	setsockopt(fd, 0, UDT_RCVTIMEO, &ms, sizeof(long));
}

inline void udt_socket_listen(UDTSOCKET fd, int maxconnection=1024)
{
	if(UDT::ERROR == UDT::listen(fd, maxconnection)) throw ERROR_SOCKET_LISTEN;
}

inline UDTSOCKET udt_socket_accept(UDTSOCKET fd, IPv4 &ip)
{
	UDTSOCKET cli;
	struct sockaddr_in addr;
	int addrl = sizeof(addr);

	cli = UDT::accept(fd, (struct sockaddr*)&addr, &addrl);
	ip.address = ntoh32(addr.sin_addr.s_addr);
	ip.port = ntoh16(addr.sin_port);

	return cli;
}

inline void udt_socket_connect(UDTSOCKET fd, IPv4 ip)
{
	struct sockaddr_in addr;
	socklen_t addrl = sizeof(addr);
	memset(&addr, 0, addrl);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = hton32(ip.address);
	addr.sin_port = hton16(ip.port);
	if(UDT::ERROR == UDT::connect(fd, (struct sockaddr *)&addr, addrl)) { std::cout << UDT::getlasterror().getErrorMessage() << std::endl; throw ERROR_SOCKET_CONNECT;}
}

inline int udt_socket_send(UDTSOCKET fd, UInt8 *src, int length)
{
	return UDT::send(fd, (char *)src, length, 0);
}

inline int udt_socket_recv(UDTSOCKET fd, UInt8 *dst, int maxlength)
{
	int recvlen = 0;
	if(UDT::ERROR == (recvlen = UDT::recv(fd, (char *)dst, maxlength, 0))) { std::cout << UDT::getlasterror().getErrorMessage() << std::endl; throw ERROR_SOCKET_RECV;}
	return recvlen;
}

inline void udt_socket_close(UDTSOCKET fd)
{
	UDT::close(fd);
}

#endif

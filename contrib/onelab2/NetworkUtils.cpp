#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <iostream>
#include <unistd.h>

#include "NetworkUtils.h"

UInt32 ip4_inet_pton(const char *ip)
{
	struct in_addr dst;
	if(inet_pton(AF_INET, ip, &dst) == 0)
		return 0; // the string seems to contain an invalid ip
	return ntohl(dst.s_addr);
}

UInt32 ip4_inet_resolve(const char *hostname)
{
	struct hostent *he;
	struct in_addr **addr_list;

	if((he = gethostbyname(hostname)) == NULL)
		return 0;

	addr_list = (struct in_addr **) he->h_addr_list;

	for(int i = 0; addr_list[i] != NULL; i++) 
		return ntoh32(addr_list[i]->s_addr);

	return 0;
}

void ip4_socket_ip(Socket fd, IPv4 &ip)
{
  struct sockaddr_in sin;
  socklen_t len = sizeof(sin);
  if(getsockname(fd, (struct sockaddr *)&sin, &len) != -1){
	  ip.address = ntoh32(sin.sin_addr.s_addr);
    ip.port = ntoh16(sin.sin_port);
  }
}

UInt32 ip4_default_iface()
{
	struct ifaddrs *ifas = NULL;
	UInt32 ip = 0;

	getifaddrs(&ifas);
	for (struct ifaddrs *ifa = ifas; ifa != NULL; ifa = ifa->ifa_next) {
		if(ifa->ifa_addr->sa_family == AF_INET) {
			UInt32 tmp = ntoh32((UInt32)((struct sockaddr_in *) ifa->ifa_addr)->sin_addr.s_addr);
			if(!ip4_is_loopback(tmp)) {
				ip = tmp;
				break;
			}
		}
	}
	freeifaddrs(ifas);
	return ip;
}

Socket ip4_socket(IPv4 ip, int socketType)
{
	Socket fd;
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = hton32((ip.address==0)? INADDR_ANY : ip.address);
	addr.sin_port = hton16(ip.port);

	if((fd = socket(AF_INET, socketType, 0)) < 0) throw ERROR_SOCKET_CREATE;

	if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) != 0) throw ERROR_SOCKET_BIND;	

	return fd;
}

void ip4_socket_timeout(Socket fd, long tos, long tous)
{
	struct timeval tv;
	tv.tv_sec = tos; // seconds
	tv.tv_usec = tous; // microseconds
	setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(struct timeval));
}

int ip4_socket_send(Socket fd, UInt8 *src, int length)
{
	ssize_t sent = send(fd, src, length, 0);

	// TODO handle error (length != sent) for ??? and (sent < 0) for local error
  std::cout << "ip: send " << sent << "/" << length << "bytes" <<  std::endl;
	return (int)sent;
}
int ip4_socket_send(Socket fd, UInt8 *src, int length, IPv4 dst)
{
	struct sockaddr_in to;
	socklen_t tol = sizeof(to);
	memset(&to, 0, tol);

	to.sin_family = AF_INET;
	to.sin_port = hton16(dst.port);
	to.sin_addr.s_addr = hton32(dst.address);

	ssize_t sent = sendto(fd, src, length, 0, (struct sockaddr *)&to, tol);

	// TODO handle error (length != sent) for ??? and (sent < 0) for local error
  std::cout << "ip: send " << sent << "/" << length << "bytes to " << ip4_inet_ntop(dst.address)<< ':' << dst.port << std::endl;
	return (int)sent;
}

int ip4_socket_recv(Socket fd, UInt8 *dst, int maxlength)
{
  ssize_t recved = recv(fd, dst, maxlength, 0);
  
	// TODO handle error if(recvlength < 0)
  std::cout << "ip: recv " << recved << "bytes" << std::endl;
	return recved;
}
int ip4_socket_recv(Socket fd, UInt8 *dst, int maxlength, IPv4 &src)
{
	struct sockaddr_in from;
	socklen_t froml = sizeof(from);
	memset(&from, 0, froml);

	ssize_t recvlength = recvfrom(fd, dst, maxlength, 0, (struct sockaddr *)&from, &froml);
	src.port = ntoh16(from.sin_port);
	src.address = ntoh32(from.sin_addr.s_addr);

	// TODO handle error if(recvlength < 0)
  std::cout << "ip: recv " << recvlength << "bytes from " << ip4_inet_ntop(src.address)<< ':' << src.port << std::endl;
	return recvlength;
}

bool ip4_socket_get_local_address(Socket fd, IPv4 &ip)
{
	struct sockaddr_in addr_in;
	socklen_t len = sizeof(addr_in);

	if(getsockname(fd, (struct sockaddr *)&addr_in, &len) != -1) {
		ip.port = ntoh16(addr_in.sin_port);
		ip.address = ntoh32(addr_in.sin_addr.s_addr);
		return true;
	}
	return false;
}

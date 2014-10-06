#ifndef _NETWORKUTILS_H_
#define _NETWORKUTILS_H_

#include <cstring>
#include <sstream>
#include <unistd.h>
#include <arpa/inet.h>

#define ERROR_SOCKET_CREATE 10
#define ERROR_SOCKET_BIND 11
#define ERROR_SOCKET_CONNECT 12
#define ERROR_SOCKET_LISTEN 13
#define ERROR_SOCKET_RECV 14

#ifdef WIN32
typedef SOCKET Socket;
typedef int socklen_t;
#else
typedef int Socket;
#endif

typedef unsigned char  UInt8;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
typedef unsigned long long UInt64;
typedef struct {unsigned char bytes[16];} UInt128;
typedef struct {UInt32 address; UInt16 port;} IPv4;

// host to network (and network to host) order, Reference RFC 791
#define hton64 ntoh64
#define hton32 htonl
#define ntoh32 ntohl
#define hton16 htons
#define ntoh16 ntohs
#if BYTE_ORDER == BIG_ENDIAN
inline UInt64 ntoh64(UInt64 n) {return n;}
inline double ntoh64(double n) {return n;}
#else
inline UInt64 ntoh64(UInt64 n) {
        union
        {
		UInt64 d;
                UInt8 b[8];
        }in, out;
        in.d = n;
        out.b[0] = in.b[7];
        out.b[1] = in.b[6];
        out.b[2] = in.b[5];
        out.b[3] = in.b[4];
        out.b[4] = in.b[3];
        out.b[5] = in.b[2];
        out.b[6] = in.b[1];
        out.b[7] = in.b[0];
        return out.d;
}
inline double ntoh64(double n) {
        union
        {
		double d;
                UInt8 b[8];
        }in, out;
        in.d = n;
        out.b[0] = in.b[7];
        out.b[1] = in.b[6];
        out.b[2] = in.b[5];
        out.b[3] = in.b[4];
        out.b[4] = in.b[3];
        out.b[5] = in.b[2];
        out.b[6] = in.b[1];
        out.b[7] = in.b[0];
        return out.d;
}
#endif

inline UInt8 *encode(UInt8 *dst, UInt8 data) {memcpy(dst, reinterpret_cast<void*>(&data), sizeof(UInt8));return dst+ sizeof(UInt8);}
inline UInt8 *encode(UInt8 *dst, UInt16 data) {data = hton16(data);memcpy(dst, reinterpret_cast<void*>(&data), sizeof(UInt16));return dst+ sizeof(UInt16);}
inline UInt8 *encode(UInt8 *dst, UInt32 data) {data = hton32(data);memcpy(dst, reinterpret_cast<void*>(&data), sizeof(UInt32));return dst+ sizeof(UInt32);}
inline UInt8 *encode(UInt8 *dst, UInt64 data) {data = hton64(data);memcpy(dst, reinterpret_cast<void*>(&data), sizeof(UInt64));return dst+ sizeof(UInt64);}
inline UInt8 *encode(UInt8 *dst, UInt8 *data, unsigned int length) {memcpy(dst, reinterpret_cast<void*>(data), length);return dst+ length;}
inline UInt8 *encode(UInt8 *dst, double data) {data = hton64(data);memcpy(dst, reinterpret_cast<void*>(&data), sizeof(double));return dst+ sizeof(double);}

inline UInt8 *parse(UInt8 *src, UInt8 &data) {memcpy(reinterpret_cast<void*>(&data), src, sizeof(UInt8)); return src+ sizeof(UInt8);}
inline UInt8 *parse(UInt8 *src, UInt16 &data) {memcpy(reinterpret_cast<void*>(&data), src, sizeof(UInt16));data = ntoh16(data);return src+ sizeof(UInt16);}
inline UInt8 *parse(UInt8 *src, UInt32 &data) {memcpy(reinterpret_cast<void*>(&data), src, sizeof(UInt32));data = ntoh32(data);return src+ sizeof(UInt32);}
inline UInt8 *parse(UInt8 *src, UInt64 &data) {memcpy(reinterpret_cast<void*>(&data), src, sizeof(UInt64));data = ntoh64(data);return src+ sizeof(UInt64);}
inline UInt8 *parse(UInt8 *src, UInt8 *data, UInt16 length) {memcpy(reinterpret_cast<void*>(data), src, length);return src+length;}
inline UInt8 *parse(UInt8 *src, double &data) {memcpy(reinterpret_cast<void*>(&data), src, sizeof(double));data = ntoh64(data);return src+ sizeof(double);}
inline UInt8 *parse(UInt8 *src, std::string &data, UInt16 length) {data.assign((char *)src, length-1); return src+length;}
inline UInt8 *parse(UInt8 *src, std::string &data, char limiter) {UInt16 len = strchr((char *)src, limiter)-(char*)src+1; return parse(src, data, len);}

inline bool ip4_is_loopback(const unsigned int ip) { // Reference RFC 1122
	return (unsigned int)(ip & 0xFF000000) == (unsigned int)0x7F000000; // 127.0.0.0/8
}
inline bool ip4_is_private(const unsigned int ip) { // Refercence RFC 1918
	return (unsigned int)(ip & 0xFFFF0000) == (unsigned int)0xC0A80000 || // 192.168.0.0/16
		(unsigned int)(ip & 0xFFF00000) == (unsigned int)0xAC100000 || // 172.16.0.0/12
		(unsigned int)(ip & 0xFF000000) == (unsigned int)0x0A000000; // 10.0.0.0/8
}
UInt32 ip4_inet_pton(const char *);
UInt32 ip4_inet_resolve(const char *hostname);
UInt32 ip4_default_iface();
inline std::string ip4_inet_ntop(UInt32 address) {
	std::ostringstream oss;
	oss << ((address >> 24) & 0xFF) << '.'	
		<< ((address >> 16) & 0xFF) << '.'
		<< ((address >> 8) & 0xFF) << '.'
		<< (address & 0xFF);
	return oss.str();
}
void ip4_socket_ip(Socket fd, IPv4 &ip);

Socket ip4_socket(IPv4 ip, int socketType);
int ip4_socket_send(Socket fd, UInt8 *src, int length);
int ip4_socket_send(Socket fd, UInt8 *src, int length, IPv4 dst);
int ip4_socket_recv(Socket fd, UInt8 *dst, int maxlength, IPv4 &src);
int ip4_socket_recv(Socket fd, UInt8 *dst, int maxlength);
inline void ip4_socket_listen(Socket fd, int maxconnection=1024)
{
	if(-1 == listen(fd, maxconnection))  throw ERROR_SOCKET_LISTEN;
}
inline Socket ip4_socket_accept(Socket fd, IPv4 &ip)
{
	Socket cli;
	struct sockaddr_in addr;
  unsigned int addrl = sizeof(addr);

	cli = accept(fd, (struct sockaddr*)&addr, &addrl);
	ip.address = ntoh32(addr.sin_addr.s_addr);
	ip.port = ntoh16(addr.sin_port);

	return cli;
}
inline int ip4_socket_connect(Socket fd, IPv4 &ip)
{
  struct sockaddr_in addr;
  unsigned int addrl = sizeof(addr);
  memset(&addr, 0, sizeof(struct sockaddr_in));

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = hton32(ip.address);
  addr.sin_port = hton16(ip.port);
  return connect(fd, (struct sockaddr*)&addr, addrl);
}
bool ip4_socket_get_local_address(Socket fd, IPv4 &ip);
void ip4_socket_timeout(Socket d, long tos, long tous=0);
inline void ip4_socket_reuse_address(Socket fd, bool reuse=true) {setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);}
inline void ip4_socket_close(Socket fd) {/*if(-1 == */close(fd);}

#endif

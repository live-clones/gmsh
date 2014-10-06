#include <iostream>

#include "OnelabServer.h"
#include "OnelabNetworkClient.h"

#include "NetworkUtils.h"

OnelabServer *OnelabServer::_server = 0;

void usage()
{
	//TODO std::cout << std::endl;
}

int server(unsigned short port=0)
{
	OnelabServer::instance(0, port);
	OnelabServer::instance()->Run();
}

int main(int argc, char **argv)
{
	bool isServer = false;
	unsigned int ip = 0;
	unsigned short port = 0;
	for(int arg=1; arg<argc; arg++) {
		if(strcmp(argv[arg], "-l") == 0 || strcmp(argv[arg], "--listen") == 0)
			isServer = true;
		else if(strcmp(argv[arg], "-p") == 0 || strcmp(argv[arg], "--port") == 0) {
			if(++arg >= argc) {
				usage();
				return 1;
			}
			port = atoi(argv[arg]);
		}
		else if(strcmp(argv[arg], "-i") == 0 || strcmp(argv[arg], "--ip") == 0) {
			if(++arg >= argc) {
				usage();
				return 1;
			}
			ip = ip4_inet_pton(argv[arg]);
			
		}
		else {
			usage();
			return 1;
		}
	}
	try {
		if(isServer && port != 0)
			server(port);
		else {
			usage();
			return -1;
		}
	}
	catch(int &e) {
		if(e == ERROR_SOCKET_CREATE || e == ERROR_SOCKET_BIND || e == ERROR_SOCKET_CONNECT || e == ERROR_SOCKET_LISTEN || e == ERROR_SOCKET_RECV)
			std::cerr << "UDT fail: " << UDT::getlasterror().getErrorMessage() << std::endl;
		std::cerr << "Fail with code " << e << std::endl;
		return e;
	}
	catch(const char*e) {
		std::cout << e << std::endl;
		return 1;
	}
	return 0;
}

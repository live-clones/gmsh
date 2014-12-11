#ifndef _GMSHCLIENT_H_
#define _GMSHCLIENT_H_

#include <vector>

#include "VirtualClient.h"
#include "NetworkUtils.h"
#include "OnelabNetworkClient.h"
#include "OnelabProtocol.h"

#ifdef HAVE_FLTK
class onelabGroup;
#endif

class GmshNetworkClient : public OnelabNetworkClient
{
private:
#ifdef HAVE_FLTK
  onelabGroup *_cb_obj;
#endif
public:
#ifdef HAVE_FLTK
	GmshNetworkClient(std::string name) : OnelabNetworkClient(name) {_cb_obj=NULL;}
	GmshNetworkClient(std::string name, unsigned int ip, unsigned short port) : OnelabNetworkClient(name, ip, port) {_cb_obj =NULL;}
  void setCallback(onelabGroup *cb);
	void onNewParameter(onelab::parameter *p);
  void onUpdateParameter(onelab::parameter *p);
  void onRemoveParameter(onelab::parameter *p);
#else
	GmshNetworkClient(std::string name) : OnelabNetworkClient(name) {}
	GmshNetworkClient(std::string name, unsigned int ip, unsigned short port) : OnelabNetworkClient(name, ip, port) {}
#endif
};

#endif

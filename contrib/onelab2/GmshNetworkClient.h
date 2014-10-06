#ifndef _GMSHCLIENT_H_
#define _GMSHCLIENT_H_

#include <vector>

#include "VirtualClient.h"
#include "NetworkUtils.h"
#include "OnelabNetworkClient.h"
#include "OnelabProtocol.h"

class onelab2Group;

class GmshNetworkClient : public OnelabNetworkClient
{
private:
  onelab2Group *_cb_obj;
public:
	GmshNetworkClient(std::string name) : OnelabNetworkClient(name) {}
	GmshNetworkClient(std::string name, unsigned int ip, unsigned short port) : OnelabNetworkClient(name, ip, port) {}
	~GmshNetworkClient() {}
  void setCallback(onelab2Group *cb) {_cb_obj = cb;}
	void onNewParameter(onelab::parameter *p){_cb_obj->addParameter(*p);}
  void onUpdateParameter(onelab::parameter *p){_cb_obj->updateParameter(*p);}
  void onRemoveParameter(onelab::parameter *p){_cb_obj->removeParameter(*p);}
};

#endif

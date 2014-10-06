#ifndef _GMSHLOCLACLIENT_H_
#define _GMSHLOCALCLIENT_H_

#include "OnelabLocalClient.h"

class GmshLocalClient : public OnelabLocalClient
{
private:
  onelab2Group *_cb_obj;
public:
	GmshLocalClient(std::string name, onelab::parameterSpace *parameterSpace)
		: OnelabLocalClient(name, parameterSpace){
	}
	~GmshLocalClient(){}
  void setCallback(onelab2Group *cb) {_cb_obj = cb;}
	void onNewParameter(onelab::parameter *p){_cb_obj->addParameter(*p);}
  void onUpdateParameter(onelab::parameter *p){_cb_obj->updateParameter(*p);}
  void onRemoveParameter(onelab::parameter *p){_cb_obj->removeParameter(*p);}
};

#endif

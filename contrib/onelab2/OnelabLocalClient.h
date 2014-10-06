#ifndef _ONELABLOCALCLIENT_H_
#define _ONELABLOCALCLIENT_H_

#include "VirtualClient.h"

/**
  @class OnelabLocalClient
  @brief This class is used for client in the same memory space as the server.

*/

class OnelabLocalClient : public VirtualClient
{
public:
	OnelabLocalClient(std::string name, onelab::parameterSpace *parameterSpace)
		: VirtualClient(name, parameterSpace){
	}
	template <class T> bool set(const T &p){
		return _parameterSpace->set(p, this->_name);
	}
	template <class T> bool get(std::vector<T> &ps, const std::string &name=""){
		return _parameterSpace->get(ps, name, this->_name);
	}
	virtual ~OnelabLocalClient(){}
	void onNewParameter(onelab::parameter *p){}
  void onUpdateParameter(onelab::parameter *p){}
  void onRemoveParameter(onelab::parameter *p){}

  void run() {}
  void stop() {}
};

#endif

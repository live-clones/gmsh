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
	virtual ~OnelabLocalClient(){}
  template <class T> bool set(const T &p);
  template <class T> bool get(std::vector<T> &ps, const std::string &name);
	virtual void onNewParameter(onelab::parameter *p){}
  virtual void onUpdateParameter(onelab::parameter *p){}
  virtual void onRemoveParameter(onelab::parameter *p){}

  virtual void run(std::string action) {}
  void stop() {}
};

#endif

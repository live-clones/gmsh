#ifndef _GMSHLOCLACLIENT_H_
#define _GMSHLOCALCLIENT_H_

#include "OnelabLocalClient.h"

#ifdef HAVE_FLTK
class onelabGroup;
#endif

class GmshLocalClient : public OnelabLocalClient
{
private:
#ifdef HAVE_FLTK
  onelabGroup *_cb_obj;
#endif
public:
#ifdef HAVE_FLTK
	GmshLocalClient(std::string name, onelab::parameterSpace *parameterSpace)
		: OnelabLocalClient(name, parameterSpace){
    _cb_obj = NULL;
	}
	~GmshLocalClient(){}
  void setCallback(onelabGroup *cb);
	void onNewParameter(onelab::parameter *p);
  void onUpdateParameter(onelab::parameter *p);
  void onRemoveParameter(onelab::parameter *p);
#else
	GmshLocalClient(std::string name, onelab::parameterSpace *parameterSpace)
		: OnelabLocalClient(name, parameterSpace){}
#endif

  void run(std::string action);
};

#endif

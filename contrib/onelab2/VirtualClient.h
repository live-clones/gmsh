#ifndef _VIRTUALCLIENT_H_
#define _VIRTUALCLIENT_H_

#include <string>

#include "onelab.h"

class VirtualClient
{
protected:
	std::string _name;
	onelab::parameterSpace *_parameterSpace;
private:
	bool _parameterSpaceShouldBeDeleted;
public:
	VirtualClient(std::string name, onelab::parameterSpace *parameterSpace=NULL){
		_name = name;
		_parameterSpaceShouldBeDeleted = (parameterSpace==NULL);
		if(_parameterSpaceShouldBeDeleted)_parameterSpace = new onelab::parameterSpace;
		else _parameterSpace = parameterSpace;
	}
	virtual ~VirtualClient(){
		if(_parameterSpaceShouldBeDeleted && _parameterSpace != NULL) delete _parameterSpace;
	}
	std::string &getName() {return _name;}
	template <class T> bool existInDatabase(const T p) const {
		std::vector<T> ps;
		_parameterSpace->get(ps, p.getName(), this->_name);
		return ps.size() > 0;
	}
	template <class T> bool set(const T &p){
		return _parameterSpace->set(p, this->_name);
	}
	template <class T> bool get(std::vector<T> &ps, const std::string &name=""){
		return _parameterSpace->get(ps, this->_name);
	}
	virtual void onNewParameter(onelab::parameter *) = 0;
  virtual void onUpdateParameter(onelab::parameter *) = 0;
  virtual void onRemoveParameter(onelab::parameter *) = 0;

  virtual void run() = 0;
  virtual void stop() = 0;
};

#endif

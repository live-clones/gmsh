#ifndef _ONELABCLIENT_H_
#define _ONELABCLIENT_H_

#include <vector>
#include <unistd.h>

#include "VirtualClient.h"
#include "OnelabProtocol.h"
#ifdef HAVE_UDT
#include "UdtUtils.h"
#else
#include "NetworkUtils.h"
#endif

class OnelabNetworkClient : VirtualClient
{
private:
#ifdef HAVE_UDT
	UDTSOCKET _fdu;
#endif
	Socket _fds;
	bool _connected;
	IPv4 _ip;

	void request(OnelabProtocol &msg);
	template <class T> bool requestParameter(std::vector<T> &ps, const std::string &name=""){
		OnelabProtocol msg(OnelabProtocol::OnelabRequest);
		msg.attrs.push_back(new OnelabAttrParameterQuery(name.c_str(), T::attributeType()));
		this->request(msg);
    return true;
	}
	void requestParameters(); // request all parameter for this client
public:
#ifdef HAVE_UDT
	OnelabNetworkClient(std::string name, bool UDT=false);
	OnelabNetworkClient(std::string name, unsigned int ip, unsigned short port, bool UDT=false);
	virtual ~OnelabNetworkClient() {UDT::cleanup();}
#else
	OnelabNetworkClient(std::string name);
	OnelabNetworkClient(std::string name, unsigned int ip, unsigned short port);
	virtual ~OnelabNetworkClient() {}
#endif
	template <class T> bool existInDatabase(const T p) {
		std::vector<T> ps;
		_parameterSpace->get(ps, p.getName(), _name);
		return ps.size() > 0;
	}
	template <class T> bool set(const T &p, bool update=true){
		bool isInDatabase = existInDatabase(p);
		if(_parameterSpace->set(p, _name)) {
			T *pp;
			_parameterSpace->getPtr(&pp, p.getName(), _name);
			if(update) {
				OnelabProtocol msg(OnelabProtocol::OnelabUpdate);
				msg.attrs.push_back(pp);
				request(msg);
			}
			if(!isInDatabase) onNewParameter(pp);
      else onUpdateParameter(pp);
			return true;
		}
		return false;
	}
	template <class T> bool get(std::vector<T> &ps, const std::string &name, bool needed=false){
		if(_parameterSpace->get(ps, name, this->_name) && ps.size() == 0) {
			if(requestParameter(ps, name)) {
		    if(needed) {// wait for the answer
          fd_set readfds;
          struct timeval timeout;
          timeout.tv_sec = 1;
          timeout.tv_usec = 0;
          FD_ZERO(&readfds);
          FD_SET(_fds, &readfds);
          int nfds = select(_fds+1, &readfds, NULL, NULL, &timeout); // Wait for the server to answer
          if(nfds > 0) recvfrom();
        }
        return _parameterSpace->get(ps, name, this->_name) && ps.size() == 0;
      }
      else
        return false;
    }
		return true;
  }
  void clear(const std::string &name="", const std::string &client="")
  {
    // TODO
  }
  FILE *openFile(const std::string name, const char *mode="rb")
  {
    FILE *fp = fopen(name.c_str(), mode);
    if(fp == NULL){ // File is not local, download it
      OnelabProtocol msg(OnelabProtocol::OnelabUpdate);
      msg.attrs.push_back(new OnelabAttrFileQuery(name));
      request(msg);
    // TODO
    }
    return fp;
  }
  bool fromChar(const std::vector<std::string> &msg, const std::string &client="")
  {
    onelab::parameter *parameters[4];
    unsigned int pi = 0;
    for(unsigned int i = 0; i < msg.size(); i++){
      std::string version, type, name;
      onelab::parameter::getInfoFromChar(msg[i], version, type, name);
      if(onelab::parameter::version() != version) return false;
      if(type == "number"){
        onelab::number p; p.fromChar(msg[i]); set(p, false);
        _parameterSpace->getPtr((onelab::number **)&parameters[pi++], p.getName());
      }
      else if(type == "string"){
        onelab::string p; p.fromChar(msg[i]); set(p, false);
        _parameterSpace->getPtr((onelab::string **)&parameters[pi++], p.getName());
      }
      else if(type == "region"){
        onelab::region p; p.fromChar(msg[i]); set(p, false);
        _parameterSpace->getPtr((onelab::region **)&parameters[pi++], p.getName());
      }
      else if(type == "function"){
        onelab::function p; p.fromChar(msg[i]); set(p, false);
        _parameterSpace->getPtr((onelab::function **)&parameters[pi++], p.getName());
      }
      else
        return false;
      if(pi == 4 || i==msg.size()-1) {
        OnelabProtocol msg(OnelabProtocol::OnelabUpdate);
        for(unsigned int j = 0; j < pi; j++)
          msg.attrs.push_back(parameters[j]);
        request(msg);
        pi=0;
      }
    }
    return true;
  }
  bool fromFile(FILE *fp, const std::string &client="")
  {
    std::vector<std::string> msg;
    if(onelab::parameter::fromFile(msg, fp)) return fromChar(msg, client);
    return false;
  }
	virtual void onNewParameter(onelab::parameter *){}
  virtual void onUpdateParameter(onelab::parameter *){}
  virtual void onRemoveParameter(onelab::parameter *){} // TODO call on clear
	// network specific method
	bool connect();
	bool isConnected(){return _connected;}
	int recvfrom(); // empty the buffer (useful when the client do not listen on another thread)
	int recvfrom(OnelabProtocol &msg);
	int recvfrom(UInt8 *buff, UInt16 maxlen);
	void sendto(UInt8 *buff, UInt16 len);
	void disconnect();
	void setRemoteIP(unsigned long ip){if(!_connected) _ip.address=ip;}
	void setRemotePort(unsigned short port){if(!_connected) _ip.port=port;}

  void run(std::string action) {}

  void sendMessage(const int level, const std::string &message);
  void sendInfo(const std::string &msg)
  {
    sendMessage(OnelabAttrMessage::Info, msg);
  }
  void sendWarning(const std::string &msg)
  {
    sendMessage(OnelabAttrMessage::Warning, msg);
  }
  void sendError(const std::string &msg)
  {
    sendMessage(OnelabAttrMessage::Error, msg);
  }

};

#endif

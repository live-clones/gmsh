#ifndef _ONELABDATABASE_H_
#define _ONELABDATABASE_H_
#endif
#include <signal.h>
#include <stdio.h>

#include "GmshMessage.h"
#include "Options.h"
#include "Context.h"
#include "onelabUtils.h"
#include "OnelabServer.h"
#include "VirtualClient.h"
#include "GmshNetworkClient.h"
#include "GmshLocalClient.h"

#ifndef WIN32
void *OnelabDatabase_listen(void *arg);
void *OnelabDatabase_server(void *arg);
#else
DWORD WINAPI OnelabDatabase_listen(LPVOID arg);
DWORD WINAPI OnelabDatabase_server(void *arg);
#endif

// OnelabDatabase is a singleton that get/set/... parameters from server/clients
class OnelabDatabase {
private:
  static OnelabDatabase *_instance;
#ifndef WIN32
  pthread_t _listenThread, _serverThread;
#else
  HANDLER _listenThread, _serverThread;
#endif
  bool _haveToStop;
  std::string _action;
  GmshNetworkClient *_client;
  GmshLocalClient *_localGUI, *_localGmsh;
  void _clear() {
#ifndef WIN32
    // TODO send message to thread to exit the thread
    //pthread_kill(_serverThread, 9);
    //if(_client) pthread_kill(_listenThread, 9);
#else
    // TODO
#endif
    if(_client) {
      _client->disconnect();
      delete _client;
    }
    if(_localGUI) delete _localGUI;
    if(_localGmsh) delete _localGmsh;
    _client = NULL; _localGUI = _localGmsh = NULL;
  }

public:
  OnelabDatabase() {
    _localGUI = NULL; _client = NULL; _localGmsh = NULL;
    _action = ""; _haveToStop = false;
  }
  static OnelabDatabase *instance() {
    if(!_instance) _instance = new OnelabDatabase;
    return _instance;
  }
  GmshLocalClient *useAsClient(){
    // the server is in the same memory space
    _clear();

    OnelabServer::instance(0x7F000001, 0);
    //OnelabServer::instance(0, 0);
    _localGUI = new GmshLocalClient("localGUI", OnelabServer::instance()->getParameterSpace());
    _localGmsh = new GmshLocalClient("Gmsh", OnelabServer::instance()->getParameterSpace());
    OnelabServer::instance()->addClient(_localGUI); // TODO remove from server in _clear()
    OnelabServer::instance()->addClient(_localGmsh); // TODO remove from server in _clear()

#ifndef WIN32
    pthread_create(&_serverThread, NULL, OnelabDatabase_server, &(((OnelabLocalClient *)_localGmsh)->getName()));
#else
    _serverThread = CreateThread(NULL, 0, NULL, OnelabDatabase_server, 0, NULL);
#endif
    return _localGUI;
  }
  GmshNetworkClient *useAsNetworkClient(UInt32 address, UInt16 port, std::string cli="GUI"){
    // use this as a network client (take server address/port)
    if(!_client) {
      _clear();

      _client = new GmshNetworkClient(cli, address, port);
      if(_client->connect()) {
#ifndef WIN32
        pthread_create(&_listenThread, NULL, OnelabDatabase_listen, &(((OnelabLocalClient *)_client)->getName()));
#else
        _listenThread = CreateThread(NULL, 0, NULL, OnelabDatabase_listen, 0, NULL);
#endif
        return _client;
      }
      else {
        Msg::Error("Unable to connect to the server!");
        return NULL;
      }
    }
    else {
#ifndef WIN32
      pthread_create(&_listenThread, NULL, OnelabDatabase_listen, &(((OnelabLocalClient *)_client)->getName()));
#else
      _listenThread = CreateThread(NULL, 0, NULL, OnelabDatabase_listen, 0, NULL);
#endif
      return _client;
    }
    return NULL;
  }
  void networkClientHaveToStop(bool haveToStop) {_haveToStop = haveToStop;}
  bool networkClientHaveToStop() {return _haveToStop;}
  void haveToDo(const std::string action) {_action = action;}
  std::string &actionToDo() {return _action;}
  int wait() {
    if(_client) return pthread_join(_listenThread, NULL);
    return pthread_join(_serverThread, NULL);
  }
  int listen(UInt8 *buff, unsigned int maxlen){
    if(_client) return _client->recvfrom(buff, maxlen);
    return 0;
  }
  void sendbytes(UInt8 *buff, unsigned int len){
    if(_client) _client->sendto(buff, len);
  }
  GmshLocalClient *useAsServer(UInt32 address, UInt16 port){
    // use this as a network server (take interface/port to listen to)
    _clear();

    OnelabServer::instance(address, port);
    _localGUI = new GmshLocalClient("localGUI", OnelabServer::instance()->getParameterSpace());
#ifndef WIN32
    pthread_create(&_serverThread, NULL, OnelabDatabase_server, NULL);
#else
    _serverThread = CreateThread(NULL, 0, NULL, OnelabDatabase_server, 0, NULL);
#endif
    return _localGUI;
  }
  template <class T> bool set(const T &p, const std::string &client) {
    std::cout<<"set "<<p.getName()<<" from "<<client<<std::endl;
    if(_client) return _client->set(p, true);
    return OnelabServer::instance()->set(p, client);
  }
  template <class T> bool set(const T &p, bool update=true) {
    std::cout<<"set "<<p.getName()<<std::endl;
    if(_client) return _client->set(p, update);
    //if(_localGUI) return _localGUI->set(p);
    return OnelabServer::instance()->set(p);
  }
  template <class T> bool get(std::vector<T> &ps, const std::string &name="", const std::string &client="") {
    if(_client) return _client->get(ps, name);
    //if(_localGUI) _localGUI->get(ps, name);
    return OnelabServer::instance()->get(ps, name, client);
  }
  bool fromFile(FILE *fp, const std::string &client="")
  {
    if(_client) return _client->fromFile(fp, client);
    return OnelabServer::instance()->fromFile(fp, client);

  }
  bool run(const std::string action, const std::string client="") {
    UInt8 buff[1024];
    OnelabProtocol msg(OnelabProtocol::OnelabAction);
    if(client.size()) {
      std::cout << "try to " << action << ' ' << client <<  std::endl;
      onelab::string o(client + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      set(o);
      if(_client && ((OnelabLocalClient *)_client)->getName() == client) {
        if(client == "Gmsh") onelabUtils::runGmshClient(action, true);
      }
      else if(_client) {
        std::cout << "client is remote" << std::endl;
        msg.attrs.push_back(new OnelabAttrAction(action, client));
        int size = msg.encodeMsg(buff, 1024);
        sendbytes(buff, size);
        return true;
      }
      else {
        std::cout << "client is local" << std::endl;
        OnelabServer::instance()->performAction(action, client);
        return true;
      }
    }
    else {
      // run Gmsh client
      run(action, "Gmsh");

      // iterate over all other clients
      std::string solver = "";
      if(CTX::instance()->solverToRun >= 0) solver = opt_solver_name(CTX::instance()->solverToRun, GMSH_GET, "");
      if(_client) {
        std::cout << "server is remote" << std::endl;
        if(CTX::instance()->solverToRun >= 0) run(action, solver);
        else {
          msg.attrs.push_back(new OnelabAttrAction(action, client));
          int size = msg.encodeMsg(buff, 1024);
          sendbytes(buff, size);
        }
        return true;
      }
      else {
        std::cout << "server is local" << std::endl;
        if(CTX::instance()->solverToRun >= 0) OnelabServer::instance()->performAction(action, solver);
        else OnelabServer::instance()->performAction(action, client);
        return true;
      }
    }
    return false;
  }
  bool getChanged(const std::string &client="") const {
    if(!_client)
      return OnelabServer::instance()->getChanged(client);
    else
      return true; // TODO
  }
  void setChanged(bool changed, const std::string &client="") {
    if(!_client)
      OnelabServer::instance()->setChanged(changed, client);
    else
      return; // TODO
  }
};


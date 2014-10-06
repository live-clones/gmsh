#include <signal.h>
#include <stdio.h>

#include "GmshMessage.h"
#include "OnelabServer.h"
#include "GmshNetworkClient.h"
#include "GmshLocalClient.h"
#include "onelabUtils.h"


#ifndef WIN32
void *OnelabDatabase_listen(void *arg);
void *OnelabDatabase_server(void *arg);
#else
DWORD WINAPI OnelabDatabase_listen(LPVOID arg);
DWORD WINAPI OnelabDatabase_server(void *arg);
#endif

OnelabServer *OnelabServer::_server = NULL;

// OnelabDatabase is a singleton that get/set/... parameters from server/clients
class OnelabDatabase {
private:
  static OnelabDatabase *_instance;
#ifndef WIN32
  pthread_t _listenThread, _serverThread;
#else
  HANDLER _listenThread, _serverThread;
#endif
  GmshNetworkClient *_client;
  GmshLocalClient *_localClient;
  void _clear() {
#ifndef WIN32
    // TODO send message to thread to exit the thread
    //pthread_kill(_serverThread, 9);
    //if(_client) pthread_kill(_listenThread, 9);
#else
    // TODO
#endif
    if(_client) delete _client;
    if(_localClient) delete _localClient;
    _client = NULL; _localClient = NULL;
  }

public:
  OnelabDatabase() {
    _localClient = NULL; _client = NULL;
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
    _localClient = new GmshLocalClient("localGUI", OnelabServer::instance()->getParameterSpace());
    OnelabServer::instance()->addClient(_localClient); // TODO remove from server in _clear()
#ifndef WIN32
    pthread_create(&_serverThread, NULL, OnelabDatabase_server, NULL);
#else
    _serverThread = CreateThread(NULL, 0, NULL, OnelabDatabase_server, 0, NULL);
#endif
    return _localClient;
  }
  GmshNetworkClient *useAsNetworkClient(UInt32 address, UInt16 port){
    // use this as a network client (take server address/port)
    _clear();

    _client = new GmshNetworkClient("GUI", address, port);
    if(_client->connect()) {
#ifndef WIN32
      pthread_create(&_listenThread, NULL, OnelabDatabase_listen, NULL);
#else
      _listenThread = CreateThread(NULL, 0, NULL, OnelabDatabase_listen, 0, NULL);
#endif
      return _client;
    }
    else
      Msg::Error("Unable to connect to the server!");
    return NULL;
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
    _localClient = new GmshLocalClient("localGUI", OnelabServer::instance()->getParameterSpace());
#ifndef WIN32
    pthread_create(&_serverThread, NULL, OnelabDatabase_server, NULL);
#else
    _serverThread = CreateThread(NULL, 0, NULL, OnelabDatabase_server, 0, NULL);
#endif
    return _localClient;
  }
  template <class T> bool set(const T &p, bool update=true) {
    if(_client) return _client->set(p, update);
    //if(_localClient) return _localClient->set(p);
    return OnelabServer::instance()->set(p, "");
  }
  template <class T> bool set(const T &p, const std::string &client) {
    return OnelabServer::instance()->set(p, client);
  }
  template <class T> bool get(std::vector<T> &ps, const std::string &name="", const std::string &client="") {
    if(_client) return _client->get(ps, name);
    //if(_localClient) _localClient->get(ps, name);
    return OnelabServer::instance()->get(ps, name, client);
  }  
  bool fromFile(FILE *fp, const std::string &client="")
  {
    if(_client) return _client->fromFile(fp, client);
    return OnelabServer::instance()->fromFile(fp, client);
    
  }
  void onelab_cb(std::string action) {
    if(_client) return; // TODO send action to the server
    if(action == "stop"){
      //FlGui::instance()->onelab->stop(true);
      if(_client) _client->stop();
    }
    //TODO if(action == "compute") initializeLoops();

    do {
      for (std::vector<OnelabLocalNetworkClient>::iterator it = OnelabServer::instance()->getClients().begin() ; it != OnelabServer::instance()->getClients().end(); ++it)
      {
        onelab::string o((*it).getName() + "/Action", action);
        o.setVisible(false);
        o.setNeverChanged(true);
        this->set(o);
        (*it).run();
      }
      
    } while(action == "compute" &&
        //TODO incrementLoops() &&
        !false/*TODO onelab->stop*/);
    
  }
};

#ifndef WIN32
void *OnelabDatabase_listen(void *arg)
#else
DWORD WINAPI OnelabDatabase_listen(LPVOID arg)
#endif
{
  OnelabProtocol msg(-1);
  UInt8 buff[1024];
  int recvlen = 0;
  while(1) {
    recvlen = OnelabDatabase::instance()->listen(buff, 1024);
    if(recvlen == 1 && buff[0] == 'S')
      break; 
    msg.parseMsg(buff, recvlen);
    msg.showMsg();
    switch(msg.msgType()) {
      case OnelabProtocol::OnelabStop:
        return NULL;
      case OnelabProtocol::OnelabMessage:
        Msg::Info("Message from onelab"); // TODO
        break;
      case OnelabProtocol::OnelabResponse:
      case OnelabProtocol::OnelabUpdate:
        for(std::vector<OnelabAttr *>::iterator it = msg.attrs.begin() ; it != msg.attrs.end(); ++it) {
          if((*it)->getAttributeType() == OnelabAttr::Number) {
            onelab::number *attr = (onelab::number *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::String) {
            onelab::string *attr = (onelab::string *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::Region) {
            onelab::region *attr = (onelab::region *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttr::Function) {
            onelab::function *attr = (onelab::function *)*it;
            OnelabDatabase::instance()->set(*attr, false);
          }
          else if((*it)->getAttributeType() == OnelabAttrFileQuery::attributeType()) {
            OnelabAttrFileQuery *attr = (OnelabAttrFileQuery *)*it;
            const char *filename = attr->getFilename();
            // FIXME path/filename ?
            std::clog << "try to open " << filename << " for reading" << std::endl;
            FILE *fp = fopen(filename, "rb");
            if(fp != NULL){
              OnelabProtocol rep(OnelabProtocol::OnelabUpdate);
              rep.attrs.push_back(new OnelabAttrFile(std::string(filename), fp));
              recvlen = rep.encodeMsg(buff, 1024);
              OnelabDatabase::instance()->sendbytes(buff, recvlen);
              while((recvlen = fread(buff, 1, 1024, fp)) > 0)
                OnelabDatabase::instance()->sendbytes(buff, recvlen);
            }
          }
          else if((*it)->getAttributeType() == OnelabAttrFile::attributeType()) {
            OnelabAttrFile *attr = (OnelabAttrFile *)*it;
            const char *filename = attr->getFilename();
            std::clog << "try to open " << filename << " for writing" << std::endl;
            FILE *fp = fopen(filename, "wb");
            if(fp != NULL){
              unsigned int filesize = ((OnelabAttrFile *)attr)->getFileSize();
              unsigned int downloadsize = 0;
              while(downloadsize < filesize) {
                recvlen = OnelabDatabase::instance()->listen(buff, 1024);
                downloadsize += recvlen;
                fwrite(buff, 1, recvlen, fp);
              }
            }
          }
          else if((*it)->getAttributeType() == OnelabAttrAction::attributeType()) {
            OnelabAttrAction *attr = (OnelabAttrAction *)*it;
            OnelabLocalNetworkClient *target = OnelabServer::instance()->getClient(attr->getClient());
            target->sendto(buff, recvlen);
          }
        }
        break;
    }
  }
}
#ifndef WIN32
void *OnelabDatabase_server(void *arg)
#else
DWORD WINAPI OnelabDatabase_server(LPVOID arg)
#endif
{
  OnelabServer::instance()->Run();
}

#include <cstdio>

#ifndef WIN32
#include <pthread.h>
#include <signal.h>
#else
#include <wspiapi.h>
#endif

#include "NetworkUtils.h"
#include "OnelabServer.h"
#include "OnelabProtocol.h"
#include "OnelabAttributes.h"
#include "onelab.h"
#include "onelabUtils.h"

// FIXME no Gmsh specific header (used in launchClient)
#include "StringUtils.h"
#include "GmshMessage.h"
#include "OS.h"
#include "GModel.h"
#include "Options.h"

static bool haveToStop = false;

void signalHandler(int unused)
{
  haveToStop = true;
}

OnelabServer::OnelabServer(UInt32 iface, UInt16 port)
{
  _ip.address = iface;
  _ip.port = port;

#ifdef HAVE_UDT
  UDT::startup();
  _fdu = udt_socket(_ip, SOCK_STREAM);
#endif
  _fds = ip4_socket(_ip, SOCK_STREAM);
  ip4_socket_ip(_fds, _ip);
}

OnelabServer::OnelabServer(UInt16 port)
{
  _ip.address = 0;
  _ip.port = port;

#ifdef HAVE_UDT
  UDT::startup();
  _fdu = udt_socket(_ip, SOCK_STREAM);
#endif
  _fds = ip4_socket(_ip, SOCK_STREAM);
  ip4_socket_ip(_fds, _ip);
}

#ifdef HAVE_UDT
void OnelabServer::addClient(std::string name, UDTSOCKET fd, UInt32 ip, UInt16 port)
{
  this->_clients.push_back(OnelabLocalNetworkClient(name, fd, ip, port));
}

OnelabLocalNetworkClient *OnelabServer::getClient(UDTSOCKET fd) // UDTSOCKET Socket
{
  for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
    if(it->getUSocket() == fd) return &(*it);
    if(it->getSSocket() == fd) return &(*it);
  }
  return NULL;
}
#endif

int OnelabServer::launchClient(const std::string &client) // FIXME OnelabDatabase instead of OnelabServer ?
{
  // launch a new client with a system call
  std::string command = "";
  if(getClient(client) != NULL || getLocalClient(client) != NULL) return -1; // client already exist

  if(client == "Gmsh") {
    command.assign(Msg::GetExecutableName());
  }
  else {
    int num = 0;
    while(num < 10/*NUM_SOLVERS*/){
      if(opt_solver_name(num, GMSH_GET, "") == client) break;
      num++;
    }
    if(num >= 10/*NUM_SOLVERS*/) {
      std::cout << "Unable to find " << client << std::endl;
      return -1;
    }

    //std::string name = opt_solver_name(num, GMSH_GET, "");
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    command.assign(exe);
  }

  if(command.size()){
    std::vector<std::string> args = onelabUtils::getCommandLine(client);
    for(unsigned int i = 0; i < args.size(); i++)
      command.append(" " + args[i]);
  }
  command.append(" -onelab"
                 " \"" + client + "\" %s");

  char cmd[1024];
  // UNIX socket
  //TODO sprintf(cmd, command, _sockname.c_str());

  // TCP socket
  sprintf(cmd, command.c_str(), " %s:%d");
  command.assign(cmd);
  sprintf(cmd, command.c_str(), (_ip.address==0)?"127.0.0.1":ip4_inet_ntop(_ip.address).c_str(), _ip.port);

  std::cout << "launch " << client << " with command: " << cmd << std::endl;
  SystemCall(cmd);

  return 0;
}

//void OnelabServer::addClient(std::string name, Socket fd, UInt32 ip, UInt16 port)
//{
//  if(ip == 0 || port == 0) throw "Unable to add client (invalid ip or port)";
//  this->_clients.push_back(OnelabLocalNetworkClient(name, fd, ip, port));
//}
//OnelabLocalNetworkClient *OnelabServer::getClient(Socket fd)
//{
//	for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
//		if(it->getSSocket() == fd) return &(*it);
//	}
//  return NULL;
//}
void OnelabServer::sendto(std::string client, UInt8 *buff, UInt32 len)
{
  for(std::vector<OnelabLocalNetworkClient>::iterator it = this->_clients.begin() ; it != this->_clients.end(); ++it) {
    if((*it).getName() != client) continue;
    (*it).sendto(buff, len);
    return;
  }
}

OnelabLocalNetworkClient *OnelabServer::getClient(UInt32 ip, UInt16 port)
{
  for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
    if((*it).getIp() == ip && (*it).getPort() == port)
      return &(*it);
  }
  return NULL;
}

OnelabLocalNetworkClient *OnelabServer::getClient(std::string name)
{
  for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
    if((*it).getName() == name)
      return &(*it);
  }
  return NULL;
}
OnelabLocalClient *OnelabServer::getLocalClient(std::string name)
{
  for(std::vector<OnelabLocalClient *>::iterator it = _localClients.begin(); it != _localClients.end(); ++it) {
    if((*it)->getName() == name)
      return (*it);
  }
  return NULL;

}

void OnelabServer::removeClient(OnelabLocalNetworkClient *client)
{
  for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
    if(&(*it) == client) {
      _clients.erase(it);
      return;
    }
  }
}

void OnelabServer::performAction(const std::string action, const std::string client)
{
  if(client.size()) {
    onelabUtils::guessModelName(client);
    OnelabLocalNetworkClient *cli = getClient(client);
    OnelabLocalClient *localcli = getLocalClient(client);
    onelab::string o(client + "/Action", action);
    o.setVisible(false);
    o.setNeverChanged(true);
    set(o, client);
    if(cli != NULL){ // Gmsh is used as a server and the client is remote
      std::cout << action << " on " << client << "(client is remote)" << std::endl;
      cli->run(action);
    }
    else if(localcli != NULL){ // client is local (in the same memory space than this server)
      std::cout << action << " on " << client << "(client is local)" << std::endl;
      localcli->run(action);
    }
    else { // client does not exist (Gmsh is used as a server), launch the client
      std::cout << action << " on " << client << "(launch a new remote Gmsh)" << std::endl;
      if(launchClient(client) >= 0)
        ;// FIXME then action or action is store in onelab DB ?
      else
        ;// TODO save action and wait for the cli ?
    }
  }
  else {
    // run all non Gmsh clients TODO; exclude GUI ?
    for(std::vector<OnelabLocalNetworkClient>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
      if((*it).getName() == "Gmsh") continue;
      std::cout << action << " on " << (*it).getName() << "(remote)" << std::endl;
      onelab::string o((*it).getName() + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      set(o);
      (*it).run(action);
    }

    for(std::vector<OnelabLocalClient *>::iterator it = _localClients.begin(); it != _localClients.end(); ++it) {
      if((*it)->getName() == "Gmsh") continue;
      onelab::string o((*it)->getName() + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      set(o);
      std::cout << action << " on " << (*it)->getName() << "(local)" << std::endl;
      (*it)->run(action);
    }
  }
}

#ifdef HAVE_UDT
#ifndef WIN32
void *listenOnClients(void *param)
#else
  DWORD WINAPI listenOnClients(LPVOID param)
#endif
{
  IPv4 ip;
  std::set<UDTSOCKET> fdus;
  std::set<Socket> fdss;
  int recvlen = 0;
  UInt8 buff[1024];
  OnelabProtocol msg(-1), rep(-1);
  int eid = OnelabServer::instance()->getEID();
  while(UDT::ERROR != UDT::epoll_wait(eid, &fdus, NULL, -1, &fdss, NULL)) {
    /*for(std::set<UDTSOCKET>::iterator it = fdus.begin(); it != fdus.end(); ++it) {
      OnelabLocalNetworkClient *cli = OnelabServer::instance()->getClient(*it);
      if(cli == NULL) { // Client is not in the list (it muste be a Start message)
        IPv4 ip;
        recvlen = udt_socket_recv(*it, buff, 1024);
    }TODO*/

    for(std::set<Socket>::iterator it = fdss.begin(); it != fdss.end(); ++it) {

      OnelabLocalNetworkClient *cli = OnelabServer::instance()->getClient(*it);
      if(cli == NULL) { // Client is not in the list (we should get a Start message)
        IPv4 ip;
        // recv the header
        recvlen = ip4_socket_recv(*it, buff, 4, ip);
        if(recvlen != 4) {
          // invalid message header
          UDT::epoll_remove_ssock(eid, *it);
          UDT::close(*it);
          continue;
        }
        int msglen = msg.parseHeader(buff, recvlen);
        if(msglen > 1024) {
          // FIXME? buffer is too small
          UDT::epoll_remove_ssock(eid, *it);
          UDT::close(*it);
          continue;
        }
        // then recv the message
        recvlen = ip4_socket_recv(*it, buff, msglen, ip);
        msg.parseMessage(buff, recvlen);
        if(msg.msgType() == OnelabProtocol::OnelabStart && msg.attrs.size() > 0 && msg.attrs[0]->getAttributeType() == OnelabAttr::Start) {
          std::string name = std::string(((OnelabAttrStart *)msg.attrs[0])->name());
          if(OnelabServer::instance()->getClient(name) != NULL) {
            std::cout << "A client exist with this name !" << std::endl;
            rep.msgType(OnelabProtocol::OnelabMessage);
            rep.attrs.push_back(new OnelabAttrMessage("A client exist with this name !", OnelabAttrMessage::Fatal));
            recvlen = rep.encodeMsg(buff, 1024);
            //udt_socket_send(*it, buff, recvlen);
            //TODO ip4_socket_send(*it, buff, recvlen);
            //UDT::epoll_remove_usock(eid, *it);
            UDT::epoll_remove_ssock(eid, *it);
            UDT::close(*it);
            continue;
          }
          // Add a new remote client
          OnelabServer::instance()->addClient(name, *it, ip.address, ip.port);
          std::clog << "\033[0;31m" << "Add a new client: " << name <<  "\033[0m" << std::endl;
          OnelabProtocol rep(OnelabProtocol::OnelabStart);
          recvlen = rep.encodeMsg(buff, 1024);
          cli = OnelabServer::instance()->getClient(*it);
          cli->sendto(buff, recvlen);
          OnelabServer::instance()->sendAllParameter(cli);
          continue;
        }
        else {
          // cli shoud send a name first
          //UDT::epoll_remove_usock(eid, *it);
          UDT::epoll_remove_ssock(eid, *it);
          UDT::close(*it);
          continue;
        }
      }
      else {
        try {
          recvlen = cli->recvmsg(msg);
        }
        catch(int &e) {
          if(e == 50) { // Recv error (TCP)
            std::cout << "\033[0;31m" << "Connection with client \"" << cli->getName() << "\" was broken, removing the client." << "\033[0m" << std::endl; // DEBUG
            UDT::epoll_remove_ssock(eid, *it);
            OnelabServer::instance()->removeClient(cli);
            UDT::close(*it);
          }
          // TODO for UDT
          /*if(UDT::getlasterror().getErrorCode() == 2001 || e == 50) { // ECONNLOST
            std::cout << "\033[0;31m" << "Connection with client \"" << cli->getName() << "\" was broken, removing the client." << "\033[0m" << std::endl; // DEBUG
            UDT::epoll_remove_usock(eid, *it);
            OnelabServer::instance()->removeClient(cli);
            UDT::close(*it);
            }*/
          std::cerr << "Error while recv message." << std::endl;
          continue;
        }
        if(recvlen == 0) { // for TCP
          std::cout << "\033[0;31m" << "Connection with client \"" << cli->getName() << "\" was broken, removing the client." << "\033[0m" << std::endl; // DEBUG
          UDT::epoll_remove_ssock(eid, *it);
          OnelabServer::instance()->removeClient(cli);
          UDT::close(*it);
          continue;
        }
        std::clog << "recv " << recvlen << " bytes on client " << cli->getName() << std::endl;
        switch (msg.msgType()) {
        case OnelabProtocol::OnelabStop:
          std::cout << "\033[0;31m" << "Client \"" << cli->getName() << "\" is going to stop" << "\033[0m" << std::endl; // DEBUG
          rep.msgType(OnelabProtocol::OnelabStop);
          recvlen = rep.encodeMsg(buff, 1024);
          if(ip4_socket_connected(cli->getSSocket())) // FIXME cli can close socket before send
            cli->sendto(buff, recvlen);
          //UDT::epoll_remove_usock(eid, *it);
          UDT::epoll_remove_ssock(eid, *it);
          OnelabServer::instance()->removeClient(cli);
          UDT::close(*it);
          break;
        case OnelabProtocol::OnelabMessage:
          // TODO do not use Gmsh, send message to GUI
          if(msg.attrs.size()==1 && msg.attrs[0]->getAttributeType() == OnelabAttrMessage::attributeType()) {
            switch(((OnelabAttrMessage *)msg.attrs[0])->getLevel()) {
              case OnelabAttrMessage::Info:
                Msg::Direct("Info    : %s - %s", cli->getName().c_str(), ((OnelabAttrMessage *)msg.attrs[0])->getMessage());
                break;
              case OnelabAttrMessage::Warning:
                Msg::Warning("%s - %s", cli->getName().c_str(), ((OnelabAttrMessage *)msg.attrs[0])->getMessage());
                break;
              case OnelabAttrMessage::Error:
                Msg::Error("%s - %s", cli->getName().c_str(), ((OnelabAttrMessage *)msg.attrs[0])->getMessage());
                break;
            }
          }
          break;
        case OnelabProtocol::OnelabRequest:
          rep.msgType(OnelabProtocol::OnelabResponse);
          if(msg.attrs.size() == 0) OnelabServer::instance()->sendAllParameter(cli);
          else for(std::vector<OnelabAttr *>::iterator it = msg.attrs.begin() ; it != msg.attrs.end(); ++it) {
              if((*it)->getAttributeType() == OnelabAttr::Parameter) {
                OnelabAttrParameterQuery *attr = (OnelabAttrParameterQuery *)*it;
                std::cout << "\033[0;31m" << "Client \"" << cli->getName() << " ask for parameter \"" << attr->getName() << "\"\033[0m" << std::endl; // DEBUG
                onelab::parameter *p;
                switch(attr->paramType()) {
                case OnelabAttr::Number:
                  OnelabServer::instance()->getPtr((onelab::number **)&p, attr->getName(), cli->getName());
                  break;
                case OnelabAttr::String:
                  OnelabServer::instance()->getPtr((onelab::string **)&p, attr->getName(), cli->getName());
                  break;
                case OnelabAttr::Region:
                  OnelabServer::instance()->getPtr((onelab::region **)&p, attr->getName(), cli->getName());
                  break;
                case OnelabAttr::Function:
                  OnelabServer::instance()->getPtr((onelab::function **)&p, attr->getName(), cli->getName());
                  break;
                }
                if(p != NULL) rep.attrs.push_back(p);
                else rep.attrs.push_back(new OnelabAttrMessage("Unable to find the request parameter.", OnelabAttrMessage::Error));
              }
              // else ??
            }
          recvlen = rep.encodeMsg(buff, 1024);
          cli->sendto(buff, recvlen);
          break;
        case OnelabProtocol::OnelabUpdate:
          for(std::vector<OnelabAttr *>::iterator it = msg.attrs.begin() ; it != msg.attrs.end(); ++it) {
            if((*it)->getAttributeType() >= OnelabAttr::Number && (*it)->getAttributeType() <= OnelabAttr::Function) {
              onelab::parameter *attr = (onelab::parameter *)*it;
              std::cout << "\033[0;31m" << "Client \"" << cli->getName() << " update parameter \"" << attr->getName() << "\"\033[0m" << std::endl; // DEBUG
              onelab::parameter *parameter = NULL;
              switch(attr->getAttributeType()) {
              case OnelabAttr::Number:
                OnelabServer::instance()->set(*(onelab::number *)attr, cli->getName());
                OnelabServer::instance()->getPtr((onelab::number **)&parameter, attr->getName(), cli->getName());
                break;
              case OnelabAttr::String:
                OnelabServer::instance()->set(*(onelab::string *)attr, cli->getName());
                OnelabServer::instance()->getPtr((onelab::string **)&parameter, attr->getName(), cli->getName());
                break;
              case OnelabAttr::Region:
                OnelabServer::instance()->set(*(onelab::region *)attr, cli->getName());
                OnelabServer::instance()->getPtr((onelab::region **)&parameter, attr->getName(), cli->getName());
                break;
              case OnelabAttr::Function:
                OnelabServer::instance()->set(*(onelab::function *)attr, cli->getName());
                OnelabServer::instance()->getPtr((onelab::function **)&parameter, attr->getName(), cli->getName());
                break;
              }
            }
            else
              switch((*it)->getAttributeType()) {
              case 0x0B:
                {
                  // TODO check if file is on a specific client
                  const char *filename = ((OnelabAttrFileQuery *)*it)->getFilename();
                  // FIXME path/filename ?
                  std::clog << "try to open " << filename << " to read" << std::endl;
                  FILE *fp = fopen(filename, "rb");
                  if(fp != NULL){
                    std::clog << "file open" << std::endl;
                    rep.msgType(OnelabProtocol::OnelabUpdate);
                    rep.attrs.push_back(new OnelabAttrFile(std::string(filename), fp));
                    recvlen = rep.encodeMsg(buff, 1024);
                    cli->sendto(buff, recvlen);
                    while((recvlen = fread(buff, 1, 1024, fp)) > 0){
                      cli->sendto(buff, recvlen);
                    }
                  }
                  std::clog << "file ok" << std::endl;
                  break;
                }
              case 0x0C:
                const char *filename = ((OnelabAttrFile *)*it)->getFilename();
                std::clog << "try to open " << filename << " to write" << std::endl;
                FILE *fp = fopen(filename, "wb");
                if(fp != NULL){
                  std::clog << "file open" << std::endl;
                  int filesize = ((OnelabAttrFile *)*it)->getFileSize();
                  int downloadsize = 0;
                  while(downloadsize < filesize) {
                    recvlen = cli->recvfrom(buff, 1024);
                    fwrite(buff, 1, recvlen, fp);
                  }
                }
                std::clog << "file ok" << std::endl;
                break;
              }
          }
          break;
          case OnelabProtocol::OnelabAction:
          {
            if(msg.attrs.size()==1 && msg.attrs[0]->getAttributeType() == OnelabAttrAction::attributeType()) {
              std::clog << "\033[0;31m" << "Client " << cli->getName() << " ask " << ((OnelabAttrAction *)msg.attrs[0])->getClient() << " to " << ((OnelabAttrAction *)msg.attrs[0])->getAction() <<  "\033[0m" << std::endl;
              OnelabServer::instance()->performAction(((OnelabAttrAction *)msg.attrs[0])->getAction(), ((OnelabAttrAction *)msg.attrs[0])->getClient());
              //OnelabLocalNetworkClient *cli = OnelabServer::instance()->getClient(((OnelabAttrAction *)msg.attrs[0])->getClient());
              //OnelabLocalClient *localcli = OnelabServer::instance()->getLocalClient(((OnelabAttrAction *)msg.attrs[0])->getClient());
              //std::cout << ((OnelabAttrAction *)msg.attrs[0])->getAction() << " on " << ((OnelabAttrAction *)msg.attrs[0])->getClient() << "(" << cli <<  " or local " << localcli << ")" << std::endl;
              //if(cli == NULL && localcli == NULL) {
              //}
              //if(cli != NULL)
              //  cli->run(((OnelabAttrAction *)msg.attrs[0])->getAction());
              //else if(localcli != NULL)
              //  localcli->run(((OnelabAttrAction *)msg.attrs[0])->getAction());
              //else
              //  ;// TODO save action and wait for the cli ?
            }
          }
          break;
        }
      }
    }
  }
}
#endif

void OnelabServer::sendAllParameter(OnelabLocalNetworkClient *cli)
{
  std::set<onelab::parameter*, onelab::parameterLessThan> ps;
  OnelabProtocol msg = OnelabProtocol(OnelabProtocol::OnelabUpdate);
  UInt32 bufflen = 1024, recvlen = 0;
  UInt8 buff[1024];
  _parameterSpace.getAllParameters(ps);
  if(ps.size() == 0) return;
  // FIXME ...
  for(std::set<onelab::parameter*, onelab::parameterLessThan>::iterator it = ps.begin(); it != ps.end(); it++)
    if((*it)->hasClient(cli->getName())) msg.attrs.push_back(*it);
  recvlen = msg.encodeMsg(buff, bufflen);
  cli->sendto(buff, recvlen);
}

void OnelabServer::Run()
{
  UInt32 bufflen = 1024, recvlen = 0;
  UInt8 buff[1024];
  IPv4 ip;
  OnelabProtocol msg(-1), rep(OnelabProtocol::OnelabResponse);
  OnelabLocalNetworkClient *currentClient = NULL;

#ifdef HAVE_UDT
  UDTSOCKET newcli = 0;
#ifndef WIN32
  pthread_t listen_thread;
#else
  HANDLER listen_thread;
#endif

  _eid = UDT::epoll_create();

  udt_socket_listen(_fdu);
  ip4_socket_listen(_fds);
  std::clog << "listen on " << ip4_inet_ntop(_ip.address) << ":" << _ip.port << "(tcp)" << std::endl;
  //  << "listen on " << ip4_inet_ntop(_ip.address) << ":" << _ip.port << "(udp/udt)" << std::endl;
  //while(newcli = udt_socket_accept(_fdu, ip)) { // TODO accept udt and tcp ?

  while(newcli = ip4_socket_accept(_fds, ip)) {
    std::clog << "\033[0;31m" << "accpet peer : " << ip4_inet_ntop(ip.address)<< ':' << ip.port <<  "\033[0m" << std::endl;
    //UDT::epoll_add_usock(_eid, newcli);
    UDT::epoll_add_ssock(_eid, newcli);
    if(_clients.size() == 0)
#ifndef WIN32
      pthread_create(&listen_thread, NULL, listenOnClients, NULL);
#else
      listen_thread = CreateThread(NULL, 0, listenOnClients, NULL, 0, NULL);
#endif
  }
  udt_socket_close(_fdu);
#else
  // TODO
  ip4_socket_close(_fds);
#endif
}

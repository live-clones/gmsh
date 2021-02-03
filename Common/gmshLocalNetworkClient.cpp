// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include "GmshGlobal.h"
#include "Context.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "GModel.h"

#if defined(HAVE_ONELAB)

#include "gmshLocalNetworkClient.h"
#include "onelabUtils.h"

#if defined(HAVE_FLTK)
#include "FlGui.h"
#include "onelabGroup.h"
#include "drawContext.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_ONELAB_METAMODEL)
#include "OnelabClients.h"
#include "metamodel.h"
#endif

class onelabGmshServer : public GmshServer {
private:
  onelab::localNetworkClient *_client;

public:
  onelabGmshServer(onelab::localNetworkClient *client)
    : GmshServer(), _client(client)
  {
  }
  ~onelabGmshServer() {}
  int NonBlockingSystemCall(const std::string &exe, const std::string &args)
  {
    return SystemCallExe(exe, args);
  }
  int NonBlockingWait(double waitint, double timeout, int socket)
  {
    double start = TimeOfDay();
    while(1) {
      if(timeout > 0 && TimeOfDay() - start > timeout)
        return 2; // timeout
      if(_client->getPid() < 0 ||
         (_client->getExecutable().empty() && !CTX::instance()->solver.listen))
        return 1; // process has been killed or we stopped listening
      int ret = 0;
#if defined(HAVE_FLTK)
      if(FlGui::available()) {
        // if GUI available, check if there is data and return immediately (we
        // will wait for GUI events later - see below)
        ret = Select(0, 0, socket);
      }
      else {
        ret = Select(0, waitint * 1e6, socket);
      }
#else
      ret = Select(0, waitint * 1e6, socket);
#endif
      if(ret == 0) { // nothing available
#if defined(HAVE_FLTK)
        if(FlGui::available()) {
          if(timeout < 0) {
            // if asked, refresh the onelab GUI, but no more than every 1/4th of
            // a second
            static double lastRefresh = 0.;
            if(start - lastRefresh > 0.25) {
              std::vector<onelab::string> ps;
              onelab::server::instance()->get(ps, "Gmsh/Action");
              if(ps.size() && ps[0].getValue() == "refresh") {
                ps[0].setVisible(false);
                ps[0].setValue("");
                onelab::server::instance()->set(ps[0]);
                if(FlGui::available()) onelab_cb(nullptr, (void *)"refresh");
              }
              lastRefresh = start;
            }
          }
          // wait at most waitint seconds and respond to FLTK events
          FlGui::wait(waitint);
        }
#endif
        // return to caller (we will be back here soon again)
        if(timeout < 0) return 3;
      }
      else if(ret > 0) {
        return 0; // data is there!
      }
      else {
        // an error happened
        _client->setPid(-1);
        return 1;
      }
    }
  }
  int LaunchClient()
  {
    std::string sockname;
    std::ostringstream tmp;
    static bool first = true;
    const char *port = strstr(CTX::instance()->solver.socketName.c_str(), ":");
    if(!port) {
      // Unix socket
      tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName
          << _client->getId();
      sockname = FixWindowsPath(tmp.str());
    }
    else {
      // TCP/IP socket
      if(CTX::instance()->solver.socketName.size() &&
         CTX::instance()->solver.socketName[0] == ':')
        tmp << GetHostName(); // prepend hostname if only port number is given
      tmp << CTX::instance()->solver.socketName;
      if(atoi(port + 1)) {
        // if a port number is given we use it for the first client, then we
        // append the client id so that we can manage several clients at once;
        // this is ugly but it leads to the expected result if a single client
        // is instanciated (in general it is recommended to *not* specify the
        // port number, and let the OS assign a port number automatically)
        if(!first) {
          tmp << _client->getId();
          first = false;
        }
      }
      sockname = tmp.str();
    }

    std::string exe = FixWindowsPath(_client->getExecutable());
    std::string args;
    if(exe.size()) {
      if(_client->treatExecutableAsFullCommandLine()) {
        args = exe;
        exe = "";
      }
      else {
        std::vector<std::string> cl = onelabUtils::getCommandLine(_client);
        for(std::size_t i = 0; i < cl.size(); i++) args.append(" " + cl[i]);
      }
      args.append(" " + _client->getSocketSwitch() + " \"" +
                  _client->getName() + "\" %s");
    }
    else {
      Msg::Info("Listening on socket '%s'", sockname.c_str());
    }

    int sock;
    try {
      sock = Start(exe, args, sockname, CTX::instance()->solver.timeout);
    } catch(const char *err) {
      Msg::Error("Abnormal server termination (%s on socket %s)", err,
                 sockname.c_str());
      sock = -1;
    }

    return sock;
  }
};

static std::string tryToGetGmshNumberOption(const std::string &name)
{
  std::string reply;
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos) {
    double val;
    if(GmshGetOption(name.substr(0, dot), name.substr(dot + 1), val)) {
      onelab::number par(name, val);
      reply = par.toChar();
    }
  }
  return reply;
}

static std::string tryToGetGmshStringOption(const std::string &name)
{
  std::string reply;
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos) {
    std::string val;
    if(GmshGetOption(name.substr(0, dot), name.substr(dot + 1), val)) {
      onelab::string par(name, val);
      reply = par.toChar();
    }
  }
  return reply;
}

static bool tryToSetGmshNumberOption(onelab::number &p)
{
  const std::string &name = p.getName();
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos) {
    double val = p.getValue();
    return GmshSetOption(name.substr(0, dot), name.substr(dot + 1), val);
  }
  return false;
}

static bool tryToSetGmshStringOption(onelab::string &p)
{
  const std::string &name = p.getName();
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos) {
    const std::string &val = p.getValue();
    return GmshSetOption(name.substr(0, dot), name.substr(dot + 1), val);
  }
  return false;
}

bool gmshLocalNetworkClient::receiveMessage(gmshLocalNetworkClient *master)
{
  // receive a message on the associated GmshServer; 'master' is only used when
  // creating subclients with GMSH_CONNECT.

  double timer = TimeOfDay();

  if(!getGmshServer()) {
    Msg::Error("Abnormal server termination (no valid server)");
    return false;
  }

  int type, length, swap;
  if(!getGmshServer()->ReceiveHeader(&type, &length, &swap)) {
    Msg::Error("Abnormal server termination (did not receive message header)");
    return false;
  }

  std::string message(length, ' '), blank = message;
  if(!getGmshServer()->ReceiveMessage(length, &message[0])) {
    Msg::Error("Abnormal server termination (did not receive message body)");
    return false;
  }

  if(message == blank &&
     !(type == GmshSocket::GMSH_PROGRESS || type == GmshSocket::GMSH_INFO ||
       type == GmshSocket::GMSH_WARNING || type == GmshSocket::GMSH_ERROR)) {
    // we should still allow blank msg strings to be sent
    Msg::Error(
      "Abnormal server termination (blank message: client not stopped?)");
    return false;
  }

  switch(type) {
  case GmshSocket::GMSH_START: setPid(atoi(message.c_str())); break;
  case GmshSocket::GMSH_STOP:
    setPid(-1);
    if(getFather()) {
      std::string reply = getName(); // reply is dummy
      getFather()->getGmshServer()->SendMessage(GmshSocket::GMSH_STOP,
                                                (int)reply.size(), &reply[0]);
    }
    break;
  case GmshSocket::GMSH_PARAMETER:
  case GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES:
  case GmshSocket::GMSH_PARAMETER_UPDATE: {
    std::string version, ptype, name;
    onelab::parameter::getInfoFromChar(message, version, ptype, name);
    if(onelab::parameter::version() != version) {
      Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                 onelab::parameter::version().c_str(), version.c_str());
    }
    else if(ptype == "number") {
      onelab::number p;
      p.fromChar(message);
      if(!tryToSetGmshNumberOption(p)) {
        if(type == GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES) {
          // append value to any choices already on the server
          std::vector<onelab::number> par;
          get(par, name);
          std::vector<double> c;
          if(par.size()) c = par[0].getChoices();
          c.push_back(p.getValue());
          p.setChoices(c);
        }
        if(type == GmshSocket::GMSH_PARAMETER_UPDATE) {
          std::vector<onelab::number> par;
          get(par, name);
          if(par.size()) {
            onelab::number y = p;
            p = par[0];
            onelabUtils::updateNumber(p, y);
          }
        }
        set(p);
        if(p.getName() == getName() + "/Progress") {
#if defined(HAVE_FLTK)
          if(FlGui::available())
            FlGui::instance()->setProgress(p.getLabel().c_str(), p.getValue(),
                                           p.getMin(), p.getMax());
#endif
        }
      }
    }
    else if(ptype == "string") {
      onelab::string p;
      p.fromChar(message);
      if(!tryToSetGmshStringOption(p)) {
        if(type == GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES) {
          // append value to any choices already on the server
          std::vector<onelab::string> par;
          get(par, name);
          std::vector<std::string> c;
          if(par.size()) c = par[0].getChoices();
          c.push_back(p.getValue());
          p.setChoices(c);
        }
        else if(type == GmshSocket::GMSH_PARAMETER_UPDATE) {
          std::vector<onelab::string> par;
          get(par, name);
          if(par.size()) {
            onelab::string y = p;
            p = par[0];
            onelabUtils::updateString(p, y);
          }
        }
        set(p);
      }
    }
    else
      Msg::Error("Unknown ONELAB parameter type: %s", ptype.c_str());
  } break;
  case GmshSocket::GMSH_PARAMETER_QUERY:
  case GmshSocket::GMSH_PARAMETER_QUERY_WITHOUT_CHOICES: {
    std::string version, ptype, name, reply;
    onelab::parameter::getInfoFromChar(message, version, ptype, name);
    if(onelab::parameter::version() != version) {
      Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                 onelab::parameter::version().c_str(), version.c_str());
    }
    else if(ptype == "number") {
      std::vector<onelab::number> par;
      if(type == GmshSocket::GMSH_PARAMETER_QUERY_WITHOUT_CHOICES)
        getWithoutChoices(par, name);
      else
        get(par, name);
      if(par.empty())
        reply = tryToGetGmshNumberOption(name);
      else
        reply = par[0].toChar();
    }
    else if(ptype == "string") {
      std::vector<onelab::string> par;
      if(type == GmshSocket::GMSH_PARAMETER_QUERY_WITHOUT_CHOICES)
        getWithoutChoices(par, name);
      else
        get(par, name);
      if(par.empty())
        reply = tryToGetGmshStringOption(name);
      else
        reply = par[0].toChar();
    }
    else
      Msg::Error("Unknown ONELAB parameter type in query: %s", ptype.c_str());

    if(reply.size()) {
      getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER,
                                   (int)reply.size(), &reply[0]);
    }
    else {
      reply = name;
      getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER_NOT_FOUND,
                                   (int)reply.size(), &reply[0]);
    }
  } break;
  case GmshSocket::GMSH_PARAMETER_QUERY_ALL: {
    std::string version, ptype, name, reply;
    std::vector<std::string> replies;
    onelab::parameter::getInfoFromChar(message, version, ptype, name);
    if(onelab::parameter::version() != version) {
      Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                 onelab::parameter::version().c_str(), version.c_str());
    }
    else if(ptype == "number") {
      std::vector<onelab::number> numbers;
      get(numbers);
      for(auto it = numbers.begin();
          it != numbers.end(); it++)
        replies.push_back((*it).toChar());
    }
    else if(ptype == "string") {
      std::vector<onelab::string> strings;
      get(strings);
      for(auto it = strings.begin();
          it != strings.end(); it++)
        replies.push_back((*it).toChar());
    }
    else
      Msg::Error("Unknown ONELAB parameter type in query: %s", ptype.c_str());

    for(std::size_t i = 0; i < replies.size(); i++)
      getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY_ALL,
                                   (int)replies[i].size(), &replies[i][0]);
    reply = "Sent all ONELAB " + ptype + "s";
    getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY_END,
                                 (int)reply.size(), &reply[0]);
  } break;
  case GmshSocket::GMSH_PARAMETER_CLEAR:
    clear(message == "*" ? "" : message);
    break;
  case GmshSocket::GMSH_PROGRESS:
    Msg::StatusBar(false, "%s %s", _name.c_str(), message.c_str());
    break;
  case GmshSocket::GMSH_INFO:
    Msg::Direct("Info    : %s - %s", _name.c_str(), message.c_str());
    break;
  case GmshSocket::GMSH_WARNING:
    Msg::Warning("%s - %s", _name.c_str(), message.c_str());
    break;
  case GmshSocket::GMSH_ERROR:
    Msg::Error("%s - %s", _name.c_str(), message.c_str());
    break;
  case GmshSocket::GMSH_MERGE_FILE:
    if(CTX::instance()->solver.autoMergeFile) {
#if defined(HAVE_FLTK)
      std::size_t n = PView::list.size();
#endif
      bool changedBeforeMerge = onelab::server::instance()->getChanged("Gmsh");
      MergePostProcessingFile(message, CTX::instance()->solver.autoShowViews,
                              CTX::instance()->solver.autoShowLastStep, true);
      onelab::server::instance()->setChanged(changedBeforeMerge, "Gmsh");
#if defined(HAVE_FLTK)
      drawContext::global()->draw();
      if(FlGui::available() && n != PView::list.size()) {
        FlGui::instance()->rebuildTree(true);
        FlGui::instance()->openModule("Post-processing");
      }
#endif
    }
    break;
  case GmshSocket::GMSH_OPEN_PROJECT: OpenProject(message);
#if defined(HAVE_FLTK)
    drawContext::global()->draw();
#endif
    break;
  case GmshSocket::GMSH_PARSE_STRING: ParseString(message, true);
#if defined(HAVE_FLTK)
    drawContext::global()->draw();
#endif
    break;
  case GmshSocket::GMSH_SPEED_TEST:
    Msg::Info("Got %d Mb message in %g seconds", length / 1024 / 1024,
              TimeOfDay() - timer);
    break;
  case GmshSocket::GMSH_VERTEX_ARRAY: {
#if defined(HAVE_FLTK)
    int n = PView::list.size();
#endif
#if defined(HAVE_POST)
    PView::fillVertexArray(this, length, &message[0], swap);
#endif
#if defined(HAVE_FLTK)
    if(FlGui::available())
      FlGui::instance()->updateViews(n != (int)PView::list.size(), true);
    drawContext::global()->draw();
#endif
  } break;
  case GmshSocket::GMSH_CONNECT: {
    std::string::size_type first = 0;
    std::string clientName = onelab::parameter::getNextToken(message, first);
    std::string command = onelab::parameter::getNextToken(message, first);
    gmshLocalNetworkClient *subClient =
      new gmshLocalNetworkClient(clientName, command, "", true);
    onelabGmshServer *server = new onelabGmshServer(subClient);
    subClient->setPid(0);
    onelab::string o(subClient->getName() + "/Action", "compute");
    o.setVisible(false);
    o.setNeverChanged(true);
    onelab::server::instance()->set(o);
    int sock = server->LaunchClient();
    if(sock < 0) { // could not establish the connection: aborting
      server->Shutdown();
      delete server;
      Msg::Error("Could not connect client '%s'", subClient->getName().c_str());
    }
    else {
      Msg::StatusBar(true, "Running '%s'...", subClient->getName().c_str());
      subClient->setGmshServer(server);
      subClient->setFather(this);
      master->addClient(subClient);
    }
  } break;
  case GmshSocket::GMSH_OLPARSE: {
    std::string reply = "unavailable";
#if defined(HAVE_ONELAB_METAMODEL)
    std::string::size_type first = 0;
    std::string clientName = onelab::parameter::getNextToken(message, first);
    std::string fullName = onelab::parameter::getNextToken(message, first);
    preProcess(clientName, fullName); // contrib/onelab/OnelabParser.cpp
    Msg::Info("Done preprocessing file '%s'", fullName.c_str());
    reply =
      onelab::server::instance()->getChanged(clientName) ? "true" : "false";
#endif
    getGmshServer()->SendMessage(GmshSocket::GMSH_OLPARSE,
                                 (int)reply.size(), &reply[0]);
  } break;
  case GmshSocket::GMSH_CLIENT_CHANGED: {
    std::string::size_type first = 0;
    std::string command = onelab::parameter::getNextToken(message, first);
    std::string name = onelab::parameter::getNextToken(message, first);
    if(command == "get") {
      std::string reply =
        onelab::server::instance()->getChanged(name) ? "true" : "false";
      getGmshServer()->SendMessage(GmshSocket::GMSH_CLIENT_CHANGED,
                                   (int)reply.size(), &reply[0]);
    }
    else if(command == "set") {
      std::string changed = onelab::parameter::getNextToken(message, first);
      onelab::server::instance()->setChanged(changed == "true" ? 31 : 0, name);
    }
  } break;
  default:
    Msg::Warning("Received unknown message type (%d)", type);
    return false;
    break;
  }

  return true;
}

bool gmshLocalNetworkClient::run()
{
new_connection:
  setPid(0); // dummy pid, should be non-negative

  onelabGmshServer *server = new onelabGmshServer(this);

  int sock = server->LaunchClient();

  if(sock < 0) {
    // could not establish the connection: aborting
    server->Shutdown();
    delete server;
    return false;
  }

  Msg::StatusBar(true, "Running '%s'...", _name.c_str());

  setGmshServer(server);

  while(1) {
    if(getExecutable().empty() && !CTX::instance()->solver.listen) {
      // we stopped listening to the special "Listen" client
      break;
    }

    // loop over all the clients (usually only one, but can be more if we
    // spawned subclients) and check if data is available for one of them
    bool stop = false, haveData = false;
    gmshLocalNetworkClient *c = nullptr;
    std::vector<gmshLocalNetworkClient *> toDelete;
    for(int i = 0; i < getNumClients(); i++) {
      c = getClient(i);
      if(c->getPid() < 0) {
        if(c == this) { // the "master" client stopped
          stop = true;
          break;
        }
        else {
          // this subclient is not active anymore: shut down and delete its
          // server and mark the client for deletion
          GmshServer *s = c->getGmshServer();
          c->setGmshServer(nullptr);
          c->setFather(nullptr);
          if(s) {
            s->Shutdown();
            delete s;
          }
          toDelete.push_back(c);
          continue;
        }
      }
      GmshServer *s = c->getGmshServer();
      if(!s) {
        Msg::Error("Abnormal server termination (no valid server)");
        stop = true;
        break;
      }
      else {
        int ret = s->NonBlockingWait(0.0001, -1.);
        if(ret == 0) { // we have data from this particular client
          haveData = true;
          break;
        }
        else if(ret == 3) { // pass to the next client
          continue;
        }
        else { // an error occurred
          stop = true;
          break;
        }
      }
    }
    for(std::size_t i = 0; i < toDelete.size(); i++) {
      removeClient(toDelete[i]);
      delete toDelete[i];
    }

    // break the while(1) if the master client has stopped or if we encountered
    // a problem
    if(stop) break;

    // if data is available try to get the message from the corresponding
    // client; break the while(1) if we could not receive the message
    if(haveData && !c->receiveMessage(this)) break;

    // break the while(1) if the master client has stopped
    if(c == this && c->getPid() < 0) break;
  }

  // we are done running the (master) client: delete the servers and the
  // subclients, if any remain (they should have been deleted already).
  std::vector<gmshLocalNetworkClient *> toDelete;
  for(int i = 0; i < getNumClients(); i++) {
    gmshLocalNetworkClient *c = getClient(i);
    GmshServer *s = c->getGmshServer();
    c->setGmshServer(nullptr);
    c->setFather(nullptr);
    if(s) {
      s->Shutdown();
      delete s;
    }
    if(c != this) {
      if(c->getPid() > 0)
        Msg::Error("Subclient %s was not stopped correctly",
                   c->getName().c_str());
      toDelete.push_back(c);
    }
  }
  for(std::size_t i = 0; i < toDelete.size(); i++) {
    removeClient(toDelete[i]);
    delete toDelete[i];
  }

  Msg::StatusBar(true, "Done running '%s'", _name.c_str());

  if(getExecutable().empty()) {
    Msg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

  return true;
}

bool gmshLocalNetworkClient::kill()
{
  // FIXME: we should kill all the clients in the list
  if(getPid() > 0) {
    if(KillProcess(getPid())) {
      Msg::Info("Killed '%s' (pid %d)", _name.c_str(), getPid());
#if defined(HAVE_FLTK)
      if(FlGui::available()) FlGui::instance()->setProgress("Killed", 0, 0, 0);
#endif
      setPid(-1);
      return true;
    }
  }
  setPid(-1);
  return false;
}

#endif

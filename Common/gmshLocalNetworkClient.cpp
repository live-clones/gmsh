// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include "Gmsh.h"
#include "Context.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "PView.h"
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

#if defined(HAVE_ONELAB_METAMODEL)
#include "OnelabClients.h"
#include "metamodel.h"
#endif

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client)
    : GmshServer(), _client(client) {}
  ~onelabGmshServer(){}
  int NonBlockingSystemCall(const std::string &exe, const std::string &args)
  {
    return SystemCallExe(exe, args);
  }
  int NonBlockingWait(double waitint, double timeout, int socket)
  {
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout)
        return 2; // timeout
      if(_client->getPid() < 0 || (_client->getExecutable().empty() &&
                                   !CTX::instance()->solver.listen))
        return 1; // process has been killed or we stopped listening
      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);
      if(ret == 0){ // nothing available
        if(timeout < 0){
          // if asked, refresh the onelab GUI, but no more than every 1/4th of
          // a second
          static double lastRefresh = 0.;
          if(start - lastRefresh > 0.25){
            std::vector<onelab::string> ps;
            onelab::server::instance()->get(ps, "Gmsh/Action");
            if(ps.size() && ps[0].getValue() == "refresh"){
              ps[0].setVisible(false);
              ps[0].setValue("");
              onelab::server::instance()->set(ps[0]);
#if defined(HAVE_FLTK)
              if(FlGui::available()) onelab_cb(0, (void*)"refresh");
#endif
            }
            lastRefresh = start;
          }
        }
        // wait at most waitint seconds and respond to FLTK events
#if defined(HAVE_FLTK)
        if(FlGui::available()) FlGui::instance()->wait(waitint);
#endif
        // return to caller (we will be back here soon again)
	if(timeout < 0) return 3;
      }
      else if(ret > 0){
        return 0; // data is there!
      }
      else{
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
    const char *port = strstr(CTX::instance()->solver.socketName.c_str(), ":");
    if(!port){
      // Unix socket
      tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName
          << _client->getId();
      sockname = FixWindowsPath(tmp.str());
    }
    else{
      // TCP/IP socket
      if(CTX::instance()->solver.socketName.size() &&
         CTX::instance()->solver.socketName[0] == ':')
        tmp << GetHostName(); // prepend hostname if only the port number is given
      tmp << CTX::instance()->solver.socketName;
      if(atoi(port + 1)) // nonzero port is given - append client id
        tmp << _client->getId();
      sockname = tmp.str();
    }

    std::string exe = FixWindowsPath(_client->getExecutable());
    std::string args;
    if(exe.size()){
      if(_client->treatExecutableAsFullCommandLine()){
        args = exe;
        exe = "";
      }
      else{
        std::vector<std::string> cl = onelabUtils::getCommandLine(_client);
        for(unsigned int i = 0; i < cl.size(); i++)
          args.append(" " + cl[i]);
      }
      args.append(" " + _client->getSocketSwitch() +
                  " \"" + _client->getName() + "\" %s");
    }
    else{
      Msg::Info("Listening on socket '%s'", sockname.c_str());
    }

    int sock;
    try{
      sock = Start(exe, args, sockname, CTX::instance()->solver.timeout);
    }
    catch(const char *err){
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
  if(dot != std::string::npos){
    double val;
    if(GmshGetOption(name.substr(0, dot), name.substr(dot + 1), val)){
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
  if(dot != std::string::npos){
    std::string val;
    if(GmshGetOption(name.substr(0, dot), name.substr(dot + 1), val)){
      onelab::string par(name, val);
      reply = par.toChar();
    }
  }
  return reply;
}

static bool tryToSetGmshNumberOption(onelab::number &p)
{
  std::string name = p.getName();
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos){
    double val = p.getValue();
    return GmshSetOption(name.substr(0, dot), name.substr(dot + 1), val);
  }
  return false;
}

static bool tryToSetGmshStringOption(onelab::string &p)
{
  std::string name = p.getName();
  std::string::size_type dot = name.find('.');
  if(dot != std::string::npos){
    std::string val = p.getValue();
    return GmshSetOption(name.substr(0, dot), name.substr(dot + 1), val);
  }
  return false;
}

bool gmshLocalNetworkClient::receiveMessage(gmshLocalNetworkClient *master)
{
  // receive a message on the associated GmshServer; 'master' is only used when
  // creating subclients with GMSH_CONNECT.

  double timer = GetTimeInSeconds();

  if(!getGmshServer()){
    Msg::Error("Abnormal server termination (no valid server)");
    return false;
  }

  int type, length, swap;
  if(!getGmshServer()->ReceiveHeader(&type, &length, &swap)){
    Msg::Error("Abnormal server termination (did not receive message header)");
    return false;
  }

  std::string message(length, ' '), blank = message;
  if(!getGmshServer()->ReceiveMessage(length, &message[0])){
    Msg::Error("Abnormal server termination (did not receive message body)");
    return false;
  }

  if(message == blank && !(type == GmshSocket::GMSH_PROGRESS ||
                           type == GmshSocket::GMSH_INFO ||
                           type == GmshSocket::GMSH_WARNING ||
                           type == GmshSocket::GMSH_ERROR)){
    // we should still allow blank msg strings to be sent
    Msg::Error("Abnormal server termination (blank message: client not stopped?)");
    return false;
  }

  switch (type) {
  case GmshSocket::GMSH_START:
    setPid(atoi(message.c_str()));
    break;
  case GmshSocket::GMSH_STOP:
    setPid(-1);
    if(getFather()){
      std::string reply = getName(); // reply is dummy
      getFather()->getGmshServer()->SendMessage
        (GmshSocket::GMSH_STOP, reply.size(), &reply[0]);
    }
    break;
  case GmshSocket::GMSH_PARAMETER:
  case GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES:
  case GmshSocket::GMSH_PARAMETER_UPDATE:
    {
      std::string version, ptype, name;
      onelab::parameter::getInfoFromChar(message, version, ptype, name);
      if(onelab::parameter::version() != version){
        Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                   onelab::parameter::version().c_str(), version.c_str());
      }
      else if(ptype == "number"){
        onelab::number p; p.fromChar(message);
        if(!tryToSetGmshNumberOption(p)){
          if(type == GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES){
            // append value to any choices already on the server
            std::vector<onelab::number> par; get(par, name);
            std::vector<double> c;
            if(par.size()) c = par[0].getChoices();
            c.push_back(p.getValue());
            p.setChoices(c);
          }
          if(type == GmshSocket::GMSH_PARAMETER_UPDATE){
            std::vector<onelab::number> par; get(par, name);
            if(par.size()) {
              onelab::number y = p; p = par[0]; onelabUtils::updateNumber(p, y);
            }
          }
          set(p);
          if(p.getName() == getName() + "/Progress"){
#if defined(HAVE_FLTK)
            if(FlGui::available())
              FlGui::instance()->setProgress(p.getLabel().c_str(), p.getValue(),
                                             p.getMin(), p.getMax());
#endif
          }
        }
      }
      else if(ptype == "string"){
        onelab::string p; p.fromChar(message);
        if(!tryToSetGmshStringOption(p)){
          if(type == GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES){
            // append value to any choices already on the server
            std::vector<onelab::string> par; get(par, name);
            std::vector<std::string> c;
            if(par.size()) c = par[0].getChoices();
            c.push_back(p.getValue());
            p.setChoices(c);
          }
          else if(type == GmshSocket::GMSH_PARAMETER_UPDATE){
            std::vector<onelab::string> par; get(par, name);
            if(par.size()){
              onelab::string y = p; p = par[0]; onelabUtils::updateString(p,y);
            }
          }
          set(p);
        }
      }
      else
        Msg::Error("Unknown ONELAB parameter type: %s", ptype.c_str());
    }
    break;
  case GmshSocket::GMSH_PARAMETER_QUERY:
  case GmshSocket::GMSH_PARAMETER_QUERY_WITHOUT_CHOICES:
    {
      std::string version, ptype, name, reply;
      onelab::parameter::getInfoFromChar(message, version, ptype, name);
      if(onelab::parameter::version() != version){
        Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                   onelab::parameter::version().c_str(), version.c_str());
      }
      else if(ptype == "number"){
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
      else if(ptype == "string"){
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

      if(reply.size()){
        getGmshServer()->SendMessage
          (GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
      }
      else{
        reply = name;
        getGmshServer()->SendMessage
          (GmshSocket::GMSH_PARAMETER_NOT_FOUND, reply.size(), &reply[0]);
      }
    }
    break;
  case GmshSocket::GMSH_PARAMETER_QUERY_ALL:
    {
      std::string version, ptype, name, reply;
      std::vector<std::string> replies;
      onelab::parameter::getInfoFromChar(message, version, ptype, name);
      if(onelab::parameter::version() != version){
        Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                   onelab::parameter::version().c_str(), version.c_str());
      }
      else if(ptype == "number"){
        std::vector<onelab::number> numbers; get(numbers);
        for(std::vector<onelab::number>::iterator it = numbers.begin();
            it != numbers.end(); it++) replies.push_back((*it).toChar());
      }
      else if(ptype == "string"){
        std::vector<onelab::string> strings; get(strings);
        for(std::vector<onelab::string>::iterator it = strings.begin();
            it != strings.end(); it++) replies.push_back((*it).toChar());
      }
      else
        Msg::Error("Unknown ONELAB parameter type in query: %s", ptype.c_str());

      for(unsigned int i = 0; i < replies.size(); i++)
        getGmshServer()->SendMessage
          (GmshSocket::GMSH_PARAMETER_QUERY_ALL, replies[i].size(), &replies[i][0]);
      reply = "Sent all ONELAB " + ptype + "s";
      getGmshServer()->SendMessage
        (GmshSocket::GMSH_PARAMETER_QUERY_END, reply.size(), &reply[0]);
    }
    break;
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
    if(CTX::instance()->solver.autoMergeFile){
      unsigned int n = PView::list.size();
      MergePostProcessingFile(message, CTX::instance()->solver.autoShowViews,
                              CTX::instance()->solver.autoShowLastStep, true);
#if defined(HAVE_FLTK)
      drawContext::global()->draw();
      if(FlGui::available() && n != PView::list.size()){
        FlGui::instance()->rebuildTree(true);
        FlGui::instance()->openModule("Post-processing");
      }
#endif
    }
    break;
  case GmshSocket::GMSH_OPEN_PROJECT:
    OpenProject(message);
#if defined(HAVE_FLTK)
    drawContext::global()->draw();
#endif
    break;
  case GmshSocket::GMSH_PARSE_STRING:
    ParseString(message, true);
#if defined(HAVE_FLTK)
    drawContext::global()->draw();
#endif
    break;
  case GmshSocket::GMSH_SPEED_TEST:
    Msg::Info("got %d Mb message in %g seconds",
              length / 1024 / 1024, GetTimeInSeconds() - timer);
    break;
  case GmshSocket::GMSH_VERTEX_ARRAY:
    {
      int n = PView::list.size();
      PView::fillVertexArray(this, length, &message[0], swap);
#if defined(HAVE_FLTK)
      if(FlGui::available())
        FlGui::instance()->updateViews(n != (int)PView::list.size(), true);
      drawContext::global()->draw();
#endif
    }
    break;
  case GmshSocket::GMSH_CONNECT:
    {
      std::string::size_type first = 0;
      std::string clientName = onelab::parameter::getNextToken(message, first);
      std::string command = onelab::parameter::getNextToken(message, first);
      gmshLocalNetworkClient* subClient =
        new gmshLocalNetworkClient(clientName, command, "", true);
      onelabGmshServer *server = new onelabGmshServer(subClient);
      subClient->setPid(0);
      onelab::string o(subClient->getName() + "/Action", "compute");
      o.setVisible(false);
      o.setNeverChanged(true);
      onelab::server::instance()->set(o);
      int sock = server->LaunchClient();
      if(sock < 0){ // could not establish the connection: aborting
        server->Shutdown();
        delete server;
        Msg::Error("Could not connect client '%s'", subClient->getName().c_str());
      }
      else{
        Msg::StatusBar(true, "Running '%s'...", subClient->getName().c_str());
        subClient->setGmshServer(server);
        subClient->setFather(this);
        master->addClient(subClient);
      }
    }
    break;
  case GmshSocket::GMSH_OLPARSE:
    {
      std::string reply = "unavailable";
#if defined(HAVE_ONELAB_METAMODEL)
      std::string::size_type first = 0;
      std::string clientName = onelab::parameter::getNextToken(message, first);
      std::string fullName = onelab::parameter::getNextToken(message, first);
      preProcess(clientName, fullName); // contrib/onelab/OnelabParser.cpp
      Msg::Info("Done preprocessing file '%s'", fullName.c_str());
      reply = onelab::server::instance()->getChanged(clientName) ? "true" : "false";
#endif
      getGmshServer()->SendMessage
	(GmshSocket::GMSH_OLPARSE, reply.size(), &reply[0]);
    }
    break;
  case GmshSocket::GMSH_CLIENT_CHANGED:
    {
      std::string::size_type first = 0;
      std::string command = onelab::parameter::getNextToken(message, first);
      std::string name = onelab::parameter::getNextToken(message, first);
      if(command == "get"){
	std::string reply = onelab::server::instance()->getChanged(name) ? "true" : "false";
	getGmshServer()->SendMessage
	  (GmshSocket::GMSH_CLIENT_CHANGED, reply.size(), &reply[0]);
      }
      else if(command == "set"){
	std::string changed = onelab::parameter::getNextToken(message, first);
	onelab::server::instance()->setChanged(changed == "true" ? 31 : 0, name);
      }
    }
    break;
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

  if(sock < 0){
    // could not establish the connection: aborting
    server->Shutdown();
    delete server;
    return false;
  }

  Msg::StatusBar(true, "Running '%s'...", _name.c_str());

  setGmshServer(server);

  while(1) {
    if(getExecutable().empty() && !CTX::instance()->solver.listen){
      // we stopped listening to the special "Listen" client
      break;
    }

    // loop over all the clients (usually only one, but can be more if we
    // spawned subclients) and check if data is available for one of them
    bool stop = false, haveData = false;
    gmshLocalNetworkClient *c = 0;
    std::vector<gmshLocalNetworkClient*> toDelete;
    for(int i = 0; i < getNumClients(); i++){
      c = getClient(i);
      if(c->getPid() < 0){
        if(c == this){ // the "master" client stopped
          stop = true;
          break;
        }
        else{
          // this subclient is not active anymore: shut down and delete its
          // server and mark the client for deletion
          GmshServer *s = c->getGmshServer();
          c->setGmshServer(0);
          c->setFather(0);
          if(s){
            s->Shutdown();
            delete s;
          }
          toDelete.push_back(c);
          continue;
        }
      }
      GmshServer *s = c->getGmshServer();
      if(!s){
        Msg::Error("Abnormal server termination (no valid server)");
        stop = true;
        break;
      }
      else{
        int ret = s->NonBlockingWait(0.0001, -1.);
        if(ret == 0){ // we have data from this particular client
          haveData = true;
          break;
        }
        else if(ret == 3){ // pass to the next client
          continue;
        }
        else{ // an error occurred
          stop = true;
          break;
        }
      }
    }
    for(unsigned int i = 0; i < toDelete.size(); i++){
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
  std::vector<gmshLocalNetworkClient*> toDelete;
  for(int i = 0; i < getNumClients(); i++){
    gmshLocalNetworkClient *c = getClient(i);
    GmshServer *s = c->getGmshServer();
    c->setGmshServer(0);
    c->setFather(0);
    if(s){
      s->Shutdown();
      delete s;
    }
    if(c != this){
      if(c->getPid() > 0)
        Msg::Error("Subclient %s was not stopped correctly", c->getName().c_str());
      toDelete.push_back(c);
    }
  }
  for(unsigned int i = 0; i < toDelete.size(); i++){
    removeClient(toDelete[i]);
    delete toDelete[i];
  }

  Msg::StatusBar(true, "Done running '%s'", _name.c_str());

  if(getExecutable().empty()){
    Msg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

  return true;
}

bool gmshLocalNetworkClient::kill()
{
  // FIXME: we should kill all the clients in the list
  if(getPid() > 0) {
    if(KillProcess(getPid())){
      Msg::Info("Killed '%s' (pid %d)", _name.c_str(), getPid());
#if defined(HAVE_FLTK)
      if(FlGui::available())
        FlGui::instance()->setProgress("Killed", 0, 0, 0);
#endif
      setPid(-1);
      return true;
    }
  }
  setPid(-1);
  return false;
}

void initializeLoops()
{
  onelabUtils::initializeLoop("1");
  onelabUtils::initializeLoop("2");
  onelabUtils::initializeLoop("3");

#if defined(HAVE_FLTK)
  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);
#endif
}

bool incrementLoops()
{
  bool ret = false;
  if(onelabUtils::incrementLoop("3"))      ret = true;
  else if(onelabUtils::incrementLoop("2")) ret = true;
  else if(onelabUtils::incrementLoop("1")) ret = true;

  //Define ONELAB parameter indicating whether or not in a loop
  onelab::number n("0Metamodel/Loop",ret?1:0);
  n.setVisible(false);
  onelab::server::instance()->set(n);

#if defined(HAVE_FLTK)
  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);
#endif
  return ret;
}

void updateGraphs()
{
  bool redraw = false;
  for(int i = 0; i < 18; i++){
    std::ostringstream tmp;
    tmp << i;
    bool ret = onelabUtils::updateGraph(tmp.str());
    redraw = redraw || ret;
  }
  if(redraw){
    // don't delete the widgets, as this is called in widget callbacks
#if defined(HAVE_FLTK)
    FlGui::instance()->updateViews(true, false);
    drawContext::global()->draw();
#endif
  }
}

std::string timeStamp()
{
  time_t now;
  time(&now);
  tm *t = localtime(&now);
  char stamp[32];
  // stamp.size() is always 20
  sprintf(stamp, "_%04d-%02d-%02d_%02d-%02d-%02d", 1900 + t->tm_year,
          1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
  return std::string(stamp);
}

void saveDb(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "wb");
  if(fp){
    Msg::StatusBar(true, "Saving database '%s'...", fileName.c_str());
    onelab::server::instance()->toFile(fp);
    fclose(fp);
    Msg::StatusBar(true, "Done saving database '%s'", fileName.c_str());
  }
  else
    Msg::Error("Could not save database '%s'", fileName.c_str());

#if 0
  fp = Fopen((fileName + ".json").c_str(), "wb");
  if(fp){
    std::string json;
    onelab::server::instance()->toJSON(json);
    fwrite(json.c_str(), sizeof(char), json.size(), fp);
    fclose(fp);
  }
#endif
}

void archiveOutputFiles(const std::string &fileName)
{
  std::string stamp;
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps,"0Metamodel/9Tag");
  if(ps.size() && ps[0].getValue().size())
    stamp.assign(timeStamp() + "_" + ps[0].getValue());
  else
    stamp.assign(timeStamp());

  // add time stamp in all output files in the db, and rename them on disk
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    if(strings[i].getName().find("9Output files") != std::string::npos){
      std::vector<std::string> names = strings[i].getChoices();
      names.push_back(strings[i].getValue());
      for(unsigned int j = 0; j < names.size(); j++){
        std::vector<std::string> split = SplitFileName(names[j]);
        int n = split[1].size();
        // if name is not already stamped
        if(n < 18 || split[1][n-3] != '-' || split[1][n-6] != '-' ||
           split[1][n-9] != '_'){
          std::string old = names[j];
          CreateSingleDir(split[0] + "archive/");
          names[j] = split[0] + "archive/" + split[1] + stamp + split[2];
          Msg::Info("Renaming '%s' into '%s'", old.c_str(), names[j].c_str());
          rename(old.c_str(), names[j].c_str());
        }
      }
      strings[i].setValue(names.back());
      names.pop_back();
      strings[i].setChoices(names);
      onelab::server::instance()->set(strings[i]);
    }
  }

  // save stamped db
  {
    std::vector<std::string> split = SplitFileName(fileName);
    CreateSingleDir(split[0] + "archive/");
    saveDb(split[0] + "archive/" + split[1] + stamp + split[2]);
  }

#if defined(HAVE_FLTK)
  FlGui::instance()->rebuildTree(true);
#endif
}

void archiveSolutionFiles(const std::string &fileName)
{
  // extract tag from db fileName, use fileName as tag otherwise
  std::vector<std::string> split = SplitFileName(fileName);
  std::string dir = split[0] + "archive/";
  std::string tag = split[1];
  if (!tag.compare(0,6,"onelab"))
    tag.assign(tag.substr(6)); // cut off 'onelab' if present

  // add tag to all solution files in the db, and rename them on disk
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings,"0Metamodel/9Solution files");
  if(strings.size()){
    std::vector<std::string> names = strings[0].getChoices();
    if(names.size()){
      for(unsigned int j = 0; j < names.size(); j++){
	std::vector<std::string> split = SplitFileName(names[j]);
	std::string old = names[j];
	CreateSingleDir(dir);
	names[j] = dir + split[1] + tag + split[2];
	Msg::Info("Renaming '%s' into '%s'", old.c_str(), names[j].c_str());
	rename(old.c_str(), names[j].c_str());
      }
      strings[0].setValue(names[0]);
      strings[0].setChoices(names);
      onelab::server::instance()->set(strings[0]);
#if defined(HAVE_FLTK)
      FlGui::instance()->rebuildTree(true);
#endif
    }
  }
}

void loadDb(const std::string &name)
{
  Msg::StatusBar(true, "Loading database '%s'...", name.c_str());
  FILE *fp = Fopen(name.c_str(), "rb");
  if(fp){
    onelab::server::instance()->fromFile(fp);
    fclose(fp);
    Msg::StatusBar(true, "Done loading database '%s'", name.c_str());
  }
  else
    Msg::Error("Could not load database '%s'", name.c_str());
}

void resetDb(bool runGmshClient)
{
  Msg::Info("Resetting database");

  // clear everything except persistent parameters
  std::vector<onelab::number> allNumbers, persistentNumbers;
  std::vector<onelab::string> allStrings, persistentStrings;
  onelab::server::instance()->get(allNumbers);
  onelab::server::instance()->get(allStrings);
  for(unsigned int i = 0; i < allNumbers.size(); i++){
    if(allNumbers[i].getAttribute("Persistent") == "1")
      persistentNumbers.push_back(allNumbers[i]);
  }
  for(unsigned int i = 0; i < allStrings.size(); i++){
    if(allStrings[i].getAttribute("Persistent") == "1")
      persistentStrings.push_back(allStrings[i]);
  }

  // clear the db
  onelab::server::instance()->clear();

  // run Gmsh client for non-python metamodels
  if(runGmshClient && onelab::server::instance()->findClient("Gmsh") !=
     onelab::server::instance()->lastClient())
    onelabUtils::runGmshClient("reset", CTX::instance()->solver.autoMesh);

  for(unsigned int i = 0; i < persistentNumbers.size(); i++){
    Msg::Debug("Restoring persistent parameter %s",
               persistentNumbers[i].getName().c_str());
    onelab::server::instance()->set(persistentNumbers[i]);
  }
  for(unsigned int i = 0; i < persistentStrings.size(); i++){
    Msg::Debug("Restoring persistent parameter %s",
               persistentStrings[i].getName().c_str());
    onelab::server::instance()->set(persistentStrings[i]);
  }

  // mark all parameters as changed
  onelab::server::instance()->setChanged(3);
}

void solver_batch_cb(void *data)
{
  int num = (intptr_t)data;
  std::string name, exe, host;

  if(num == -1){
    // no solver to run
    return;
  }
  else if(num == -2){
    // just run local Gmsh client
  }
  else if(num >= 0){
    // run local Gmsh client + solver num
    name = opt_solver_name(num, GMSH_GET, "");
    exe = opt_solver_executable(num, GMSH_GET, "");
    host = opt_solver_remote_login(num, GMSH_GET, "");
    if(exe.empty()){
      Msg::Error("Solver executable name not provided");
      return;
    }
  }
  else{
    Msg::Error("Unknown client to run in batch mode (%d)", num);
    return;
  }

  onelab::number n("0Metamodel/Batch", CTX::instance()->batch);
  n.setVisible(false);
  onelab::server::instance()->set(n);

  // create client
  onelab::localNetworkClient *c = 0;
  onelab::string o;
  if(name.size()){
    c = new gmshLocalNetworkClient(name, exe, host);
    c->setIndex(num);
    o = c->getName() + "/Action";
  }

  // initialize
  onelabUtils::runGmshClient("initialize", CTX::instance()->solver.autoMesh);
  if(c){
    o.setValue("initialize");
    onelab::server::instance()->set(o);
    c->run();
  }

  // load db
  if(CTX::instance()->solver.autoLoadDatabase){
    std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());
    std::string db = split[0] + split[1] + ".db";
    if(!StatFile(db)) loadDb(db);
  }

  // check
  onelabUtils::runGmshClient("check", CTX::instance()->solver.autoMesh);
  if(c){
    onelabUtils::guessModelName(c);
    o.setValue("check");
    onelab::server::instance()->set(o);
    c->run();
  }

  // compute
  initializeLoops();
  do{
    onelabUtils::runGmshClient("compute", CTX::instance()->solver.autoMesh);
    if(c){
      onelabUtils::guessModelName(c);
      o.setValue("compute");
      onelab::server::instance()->set(o);
      c->run();
      onelab::server::instance()->setChanged(0, c->getName());
    }
  } while(incrementLoops());

  if(CTX::instance()->solver.autoSaveDatabase ||
     CTX::instance()->solver.autoArchiveOutputFiles){
    std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());
    std::string db = split[0] + split[1] + ".db";
    if(CTX::instance()->solver.autoArchiveOutputFiles) archiveOutputFiles(db);
    if(CTX::instance()->solver.autoSaveDatabase) saveDb(db);
  }
}

#endif

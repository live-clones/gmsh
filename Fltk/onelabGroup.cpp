// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <FL/Fl.H>
#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif

#include <ctype.h>
#include "GmshMessage.h"
#include "onelab.h"
#include "gmshLocalNetworkClient.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include "inputRange.h"
#include "outputRange.h"
#include "inputRegion.h"
#include "solverButton.h"
#include "viewButton.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "fileDialogs.h"
#include "onelabGroup.h"
#include "Gmsh.h"
#include "FlGui.h"
#include "Context.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "onelabUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"

#if defined(HAVE_ONELAB_METAMODEL)
#include "OnelabClients.h"
#include "metamodel.h"
#endif

// This file contains the Gmsh/FLTK specific parts of the ONELAB
// interface. You'll need to reimplement this if you plan to build a different
// ONELAB server.

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client)
    : GmshServer(), _client(client) {}
  ~onelabGmshServer(){}
  int NonBlockingSystemCall(const char *str)
  {
    return SystemCall(str);
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
              if(FlGui::available()) onelab_cb(0, (void*)"refresh");
            }
            lastRefresh = start;
          }
        }
        // wait at most waitint seconds and respond to FLTK events
        if(FlGui::available()) FlGui::instance()->wait(waitint);
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

    std::string command = FixWindowsPath(_client->getExecutable());
    if(command.size()){
      std::vector<std::string> args = onelabUtils::getCommandLine(_client);
      for(unsigned int i = 0; i < args.size(); i++)
        command.append(" " + args[i]);
      command.append(" " + _client->getSocketSwitch() +
                     " \"" + _client->getName() + "\" %s");
    }
    else{
      Msg::Info("Listening on socket '%s'", sockname.c_str());
    }

    int sock;
    try{
      sock = Start(command.c_str(), sockname.c_str(),
                   CTX::instance()->solver.timeout);
    }
    catch(const char *err){
      Msg::Error("Abnormal server termination (%s on socket %s)", err,
                 sockname.c_str());
      sock = -1;
    }

    return sock;
  }
};

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
        if(type == GmshSocket::GMSH_PARAMETER_UPDATE){
          std::vector<onelab::number> par; get(par, name);
          if(par.size()) {
            onelab::number y = p; p = par[0]; onelabUtils::updateNumber(p, y);
          }
        }
        set(p);
        if(p.getName() == getName() + "/Progress")
          if(FlGui::available())
            FlGui::instance()->setProgress(p.getLabel().c_str(), p.getValue(),
                                           p.getMin(), p.getMax());
      }
      else if(ptype == "string"){
        onelab::string p; p.fromChar(message);
        if(type == GmshSocket::GMSH_PARAMETER_UPDATE){
          std::vector<onelab::string> par; get(par, name);
          if(par.size()){
            onelab::string y = p; p = par[0]; onelabUtils::updateString(p,y);
          }
	}
        set(p);
      }
      else if(ptype == "region"){
        onelab::region p; p.fromChar(message); set(p);
      }
      else if(ptype == "function"){
        onelab::function p; p.fromChar(message); set(p);
      }
      else
        Msg::Error("Unknown ONELAB parameter type: %s", ptype.c_str());
    }
    break;
  case GmshSocket::GMSH_PARAMETER_QUERY:
    {
      std::string version, ptype, name, reply;
      onelab::parameter::getInfoFromChar(message, version, ptype, name);
      if(onelab::parameter::version() != version){
        Msg::Error("ONELAB version mismatch (server: %s / client: %s)",
                   onelab::parameter::version().c_str(), version.c_str());
      }
      else if(ptype == "number"){
        std::vector<onelab::number> par; get(par, name);
        if(par.size() == 1) reply = par[0].toChar();
      }
      else if(ptype == "string"){
        std::vector<onelab::string> par; get(par, name);
        if(par.size() == 1) reply = par[0].toChar();
      }
      else if(ptype == "region"){
        std::vector<onelab::region> par; get(par, name);
        if(par.size() == 1) reply = par[0].toChar();
      }
      else if(ptype == "function"){
        std::vector<onelab::function> par; get(par, name);
        if(par.size() == 1) reply = par[0].toChar();
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
      else if(ptype == "region"){
        std::vector<onelab::region> regions; get(regions);
        for(std::vector<onelab::region>::iterator it = regions.begin();
            it != regions.end(); it++) replies.push_back((*it).toChar());
      }
      else if(ptype == "function"){
        std::vector<onelab::function> functions; get(functions);
        for(std::vector<onelab::function>::iterator it = functions.begin();
            it != functions.end(); it++) replies.push_back((*it).toChar());
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
      drawContext::global()->draw();
      if(FlGui::available() && n != PView::list.size()){
        FlGui::instance()->rebuildTree(true);
        FlGui::instance()->openModule("Post-processing");
      }
    }
    break;
  case GmshSocket::GMSH_OPEN_PROJECT:
    OpenProject(message);
    drawContext::global()->draw();
    break;
  case GmshSocket::GMSH_PARSE_STRING:
    ParseString(message);
    drawContext::global()->draw();
    break;
  case GmshSocket::GMSH_SPEED_TEST:
    Msg::Info("got %d Mb message in %g seconds",
              length / 1024 / 1024, GetTimeInSeconds() - timer);
    break;
  case GmshSocket::GMSH_VERTEX_ARRAY:
    {
      int n = PView::list.size();
      PView::fillVertexArray(this, length, &message[0], swap);
      if(FlGui::available())
        FlGui::instance()->updateViews(n != (int)PView::list.size(), true);
      drawContext::global()->draw();
    }
    break;
  case GmshSocket::GMSH_CONNECT:
    {
      std::string::size_type first = 0;
      std::string clientName = onelab::parameter::getNextToken(message, first);
      std::string command = onelab::parameter::getNextToken(message, first);
      gmshLocalNetworkClient* subClient =
	new gmshLocalNetworkClient(clientName, command);
      onelabGmshServer *server = new onelabGmshServer(subClient);
      subClient->setPid(0);
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
#if defined(HAVE_ONELAB_METAMODEL)
      std::vector<std::string> split = SplitOLFileName(message);
      std::string ofileName = split[0] + split[1] ;
      std::ofstream outfile(ofileName.c_str());
      localSolverClient *c = new InterfacedClient(split[1],"","");
      if (outfile.is_open()) {
        Msg::Info("Preprocess file <%s>",ofileName.c_str());
        c->convert_onefile(message, outfile);
      }
      else
        Msg::Error("The file <%s> cannot be opened",ofileName.c_str());
      outfile.close();

      std::string reply = onelab::server::instance()->getChanged(c->getName()) ? "changed" : "unchanged";
      getGmshServer()->SendMessage
        (GmshSocket::GMSH_OLPARSE, reply.size(), &reply[0]);

      delete c;
#endif
    }
    break;
  case GmshSocket::GMSH_CLIENT_CHANGED:
    {
      std::string reply = onelab::server::instance()->getChanged(message) ? "changed" : "unchanged";
      getGmshServer()->SendMessage
        (GmshSocket::GMSH_CLIENT_CHANGED, reply.size(), &reply[0]);
    }
    break;
  default:
    Msg::Warning("Received unknown message type (%d)", type);
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
        int ret = s->NonBlockingWait(0.001, -1.);
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
      if(FlGui::available())
        FlGui::instance()->setProgress("Killed", 0, 0, 0);
      setPid(-1);
      return true;
    }
  }
  setPid(-1);
  return false;
}

static void initializeLoops()
{
  onelabUtils::initializeLoop("1");
  onelabUtils::initializeLoop("2");
  onelabUtils::initializeLoop("3");

  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);
}

static bool incrementLoops()
{
  bool ret = false;
  if(onelabUtils::incrementLoop("3"))      ret = true;
  else if(onelabUtils::incrementLoop("2")) ret = true;
  else if(onelabUtils::incrementLoop("1")) ret = true;

  //Define ONELAB parameter indicating whether or not in a loop
  onelab::number n("0Metamodel/Loop",ret?1:0);
  n.setVisible(false);
  onelab::server::instance()->set(n);

  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);

  return ret;
}

static void updateGraphs()
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
    FlGui::instance()->updateViews(true, false);
    drawContext::global()->draw();
  }
}

static std::string timeStamp()
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

static void saveDb(const std::string &fileName)
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
}

static void archiveOutputFiles(const std::string &fileName)
{
  std::string stamp;
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps,"0Metamodel/9Tag");
  if(ps.size())
    stamp.assign(ps[0].getValue()+timeStamp());
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

  FlGui::instance()->rebuildTree(true);
}

static void archiveSolutionFiles(const std::string &fileName)
{
  // extract tag from dbName
  std::vector<std::string> split = SplitFileName(fileName);
  std::string tag = split[1].substr(6); // cut off 'onelab'

  // add tag to all solution files in the db, and rename them on disk
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings,"0Metamodel/9Solution files");
  if(strings.size()){
    std::vector<std::string> names = strings[0].getChoices();
    if(names.size()){
      for(unsigned int j = 0; j < names.size(); j++){
	std::vector<std::string> split = SplitFileName(names[j]);
	std::string old = names[j];
	CreateSingleDir(split[0] + "archive/");
	names[j] = split[0] + "archive/" + split[1] + tag + split[2];
	Msg::Info("Renaming '%s' into '%s'", old.c_str(), names[j].c_str());
	rename(old.c_str(), names[j].c_str());
      }
      strings[0].setValue(names[0]);
      strings[0].setChoices(names);
      onelab::server::instance()->set(strings[0]);
      FlGui::instance()->rebuildTree(true);
    }
  }
}

static void loadDb(const std::string &name)
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

static void resetDb(bool runGmshClient)
{
  // clear everything except command line and model name setup (maybe we
  // should just re-run initialize?)
  Msg::Info("Resetting database");
  std::vector<onelab::number> useCommandLines, guessModelNames;
  std::vector<onelab::string> fileExtensions;
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    std::vector<onelab::number> ps;
    c->get(ps, c->getName() + "/UseCommandLine");
    if(ps.size()) useCommandLines.push_back(ps[0]);
    c->get(ps, c->getName() + "/GuessModelName");
    if(ps.size()) guessModelNames.push_back(ps[0]);
    std::vector<onelab::string> ps2;
    c->get(ps2, c->getName() + "/FileExtension");
    if(ps2.size()) fileExtensions.push_back(ps2[0]);
  }

  // clear the db
  onelab::server::instance()->clear();

  if(runGmshClient && onelab::server::instance()->findClient("Gmsh") !=
     onelab::server::instance()->lastClient())
    onelabUtils::runGmshClient("reset", CTX::instance()->solver.autoMesh);

  for(unsigned int i = 0; i < useCommandLines.size(); i++)
    onelab::server::instance()->set(useCommandLines[i]);
  for(unsigned int i = 0; i < guessModelNames.size(); i++)
    onelab::server::instance()->set(guessModelNames[i]);
  for(unsigned int i = 0; i < fileExtensions.size(); i++)
    onelab::server::instance()->set(fileExtensions[i]);
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;

  std::string action((const char*)data);

  if(action == "refresh"){
    updateGraphs();
    FlGui::instance()->rebuildTree(false); // FIXME: true would be better
    return;
  }

  if(action == "stop"){
    FlGui::instance()->onelab->stop(true);
    FlGui::instance()->onelab->setButtonMode("", "kill");
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++){
      onelab::string o(it->second->getName() + "/Action", "stop");
      o.setVisible(false);
      o.setNeverChanged(true);
      onelab::server::instance()->set(o);
    }
    return;
  }

  if(action == "kill"){
    FlGui::instance()->onelab->stop(true);
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++)
      it->second->kill();
    return;
  }

  if(action == "save"){
    std::vector<std::string> db = onelab::server::instance()->toChar();
    Msg::Direct("ONELAB database:");
    for(unsigned int i = 0; i < db.size(); i++){
      for(unsigned int j = 0; j < db[i].size(); j++)
        if(db[i][j] == onelab::parameter::charSep()) db[i][j] = '|';
      Msg::Direct("%s", db[i].c_str());
    }

    std::string fileName = "onelab.db";
    // add user defined tag, if any
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps,"0Metamodel/9Tag");
    if(ps.size()){
      fileName.assign("onelab" + ps[0].getValue() + ".db");
      ps[0].setValue("");
      onelab::server::instance()->set(ps[0]);
    }

    std::string s;
    s.assign(SplitFileName(GModel::current()->getFileName())[0] + fileName);
    if(fileChooser(FILE_CHOOSER_CREATE, "Save", "*.db", s.c_str())){
      archiveSolutionFiles(fileChooserGetName(1));
      saveDb(fileChooserGetName(1));
    }

    return;
  }

  if(FlGui::instance()->onelab->isBusy()){
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }

  if(action == "load"){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(fileChooser(FILE_CHOOSER_SINGLE, "Load", "*.db", db.c_str()))
      loadDb(fileChooserGetName(1));

    // switch to "restore" mode" (use archived solution files)
    std::vector<onelab::number> pn;
    onelab::server::instance()->get(pn,"0Metamodel/9Use restored solution");
    if(pn.size()){
      pn[0].setValue(1);
      onelab::server::instance()->set(pn[0]);
    }
    action = "check";
  }

  if(action == "reset"){
    resetDb(true);
    action = "check";
  }

  Msg::ResetErrorCounter();

  FlGui::instance()->onelab->setButtonMode("", "stop");

  if(action == "compute") initializeLoops();

  // check whether we are running a metamodel (.py)
  std::vector<onelab::number> pn;
  onelab::server::instance()->get(pn, "IsPyMetamodel");
  bool isPyMetamodel = (pn.size() && pn[0].getValue());


  do{ // enter loop

    // if the client is a not a metamodel, run Gmsh
    if(!isPyMetamodel){
      if(onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh))
        drawContext::global()->draw();
    }

    if(action == "compute")
      FlGui::instance()->onelab->checkForErrors("Gmsh");
    if(FlGui::instance()->onelab->stop()) break;

    // iterate over all other clients (there should normally only be one)
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
	it != onelab::server::instance()->lastClient(); it++){
      onelab::client *c = it->second;
      if(c->getName() == "Gmsh" || // local Gmsh client
	 c->getName() == "Listen" || // unknown client connecting through "-listen"
	 c->getName() == "GmshRemote") // distant post-processing Gmsh client
	continue;
      if(action != "initialize") onelabUtils::guessModelName(c);
      onelab::string o(c->getName() + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      onelab::server::instance()->set(o);
      c->run();
      if(action == "compute"){
	FlGui::instance()->onelab->checkForErrors(c->getName());
      }
      if(FlGui::instance()->onelab->stop()) break;
    }
    // after computing, all parameters are set unchanged
    if(action == "compute"){
      onelab::server::instance()->setChanged(false);
    }

    if(action != "initialize"){
      updateGraphs();
      FlGui::instance()->rebuildTree(action == "compute");
    }

  } while(action == "compute" && !FlGui::instance()->onelab->stop() &&
          incrementLoops());

  if(action == "compute" && (CTX::instance()->solver.autoSaveDatabase ||
                             CTX::instance()->solver.autoArchiveOutputFiles)){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(CTX::instance()->solver.autoArchiveOutputFiles) archiveOutputFiles(db);
    if(CTX::instance()->solver.autoSaveDatabase) saveDb(db);
  }

  FlGui::instance()->onelab->stop(false);
  FlGui::instance()->onelab->setButtonMode("check", "compute");

  Msg::StatusBar(true, "Done");

  if(action != "initialize") FlGui::instance()->onelab->show();
}

void onelab_option_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char*)data);
  double val = ((Fl_Menu_*)w)->mvalue()->value() ? 1. : 0.;
  if(what == "save")
    CTX::instance()->solver.autoSaveDatabase = val;
  else if(what == "archive")
    CTX::instance()->solver.autoArchiveOutputFiles = val;
  else if(what == "check"){
    CTX::instance()->solver.autoCheck = val;
    FlGui::instance()->onelab->setButtonVisibility();
  }
  else if(what == "mesh")
    CTX::instance()->solver.autoMesh = val;
  else if(what == "merge")
    CTX::instance()->solver.autoMergeFile = val;
  else if(what == "show")
    CTX::instance()->solver.autoShowViews = val ? 2 : 0;
  else if(what == "step")
    CTX::instance()->solver.autoShowLastStep = val;
  else if(what == "invisible"){
    CTX::instance()->solver.showInvisibleParameters = val;
    FlGui::instance()->onelab->rebuildTree(true);
  }
}

static void onelab_choose_executable_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient*)data;
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif

  std::string exe = "";

  if(!w){ // we entered here automatically because no executable is given

    // try to find an executable automatically (this is really useful for
    // beginners)
    if(CTX::instance()->argv0.size()){
      std::vector<std::string> split = SplitFileName(CTX::instance()->argv0);
      std::string name = c->getName();
      for(unsigned int i = 0; i < name.size(); i++)
        name[i] = tolower(name[i]);
      std::string path = split[0] + name;
#if defined(WIN32)
      path += ".exe";
#endif
      if(!StatFile(path)){
        exe = path;
        Msg::Info("Automatically found %s executable: %s", c->getName().c_str(),
                  exe.c_str());
      }
    }

    if(exe.empty()){
      const char *o = fl_close;
      fl_close = "OK";
      fl_message("This appears to be the first time you are trying to run %s.\n\n"
                 "Please select the path to the executable.", c->getName().c_str());
      fl_close = o;
    }
  }

  if(exe.empty()){
    const char *old = 0;
    if(c->getExecutable().size()) old = c->getExecutable().c_str();
    std::string title = "Choose location of " + c->getName() + " executable";
    if(fileChooser(FILE_CHOOSER_SINGLE, title.c_str(), pattern.c_str(), old))
      exe = fileChooserGetName(1);
  }

  if(exe.size()){
    c->setExecutable(exe);
    opt_solver_executable(c->getIndex(), GMSH_SET, exe);
  }
}

static void onelab_add_solver_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < NUM_SOLVERS; i++){
    if(opt_solver_name(i, GMSH_GET, "").empty() || i == (NUM_SOLVERS - 1)){
      const char *name = fl_input("Solver name:", "");
      if(name){
        FlGui::instance()->onelab->addSolver(name, "", "", i);
      }
      return;
    }
  }
}

template<class T>
static void setClosed(const std::string &path, std::vector<T> &ps,
                      const std::string &value)
{
  onelab::server::instance()->get(ps);
  for(unsigned int i = 0; i < ps.size(); i++){
    if(ps[i].getPath() == path){
      ps[i].setAttribute("Closed", value);
      onelab::server::instance()->set(ps[i]);
    }
  }
}

static void setOpenedClosed(Fl_Tree_Item *item, int reason)
{
  std::vector<onelab::number> numbers;
  std::vector<onelab::string> strings;
  std::vector<onelab::region> regions;
  std::vector<onelab::function> functions;
  std::string path = FlGui::instance()->onelab->getPath(item);
  switch(reason){
  case FL_TREE_REASON_OPENED:
    FlGui::instance()->onelab->removeFromManuallyClosed(path);
    setClosed(path, numbers, "0");
    setClosed(path, strings, "0");
    setClosed(path, regions, "0");
    setClosed(path, functions, "0");
    break;
  case FL_TREE_REASON_CLOSED:
    FlGui::instance()->onelab->insertInManuallyClosed(path);
    setClosed(path, numbers, "1");
    setClosed(path, strings, "1");
    setClosed(path, regions, "1");
    setClosed(path, functions, "1");
    break;
  default:
    break;
  }
}

static void onelab_tree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree *tree = (Fl_Tree*)w;
  Fl_Tree_Item *item = (Fl_Tree_Item*)tree->callback_item();
  setOpenedClosed(item, tree->callback_reason());
}

#if 0 // FIXME until the FLTK bug with widgets is solved
static void onelab_subtree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree_Item *n = (Fl_Tree_Item*)data;
  int reason;
  if(n->is_open()){
    reason = FL_TREE_REASON_CLOSED;
    n->close();
  }
  else{
    reason = FL_TREE_REASON_OPENED;
    n->open();
  }
  setOpenedClosed(n, reason);
  FlGui::instance()->onelab->redrawTree();
}
#endif

void onelabGroup::_computeWidths()
{
  _baseWidth = (int)(_tree->w() - _tree->marginleft());
  _indent = (int)(_tree->connectorwidth() / 2. + _tree->openicon()->w() / 2.);
}

#if !defined(__APPLE__)
#define gear_width 16
#define gear_height 16
static unsigned char gear_bits[] = {
   0x80, 0x01, 0x80, 0x01, 0x8c, 0x31, 0xfc, 0x3f, 0xf8, 0x1f, 0xf8, 0x1f,
   0x38, 0x1c, 0x3f, 0xfc, 0x3f, 0xfc, 0x38, 0x1c, 0xf8, 0x1f, 0xf8, 0x1f,
   0xfc, 0x3f, 0x8c, 0x31, 0x80, 0x01, 0x80, 0x01 };
#endif

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x,y,w,h,l), _stop(false), _enableTreeWidgetResize(false)
{
  int col = FL_BACKGROUND2_COLOR;
  color(col);

  box(GMSH_SIMPLE_RIGHT_BOX);
  int dx = Fl::box_dx(box());
  int dy = Fl::box_dy(box());
  int dw = Fl::box_dw(box());
  int dh = Fl::box_dh(box());

  _tree = new Fl_Tree(x + dx, y + dy, w - dw, h - dh - BH - 2 * WB);
  _tree->color(col);
  _tree->callback(onelab_tree_cb);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  // _tree->marginleft(0);
  // _tree->usericonmarginleft(0);
  // _tree->labelmarginleft(0);
  // _tree->connectorwidth(15);
  _tree->showroot(0);
  _tree->box(FL_FLAT_BOX);
  _tree->scrollbar_size(std::max(10, FL_NORMAL_SIZE - 2));
  // _tree->resizable(0);
  _tree->end();

  _computeWidths();
  _widgetLabelRatio = 0.48;

  int BB2 = BB / 2 + 4;

  _butt[0] = new Fl_Button(x + w - 3 * WB - 3 * BB2, y + h - WB - BH, BB2, BH, "Check");
  _butt[0]->callback(onelab_cb, (void*)"check");

  _butt[1] = new Fl_Button(x + w - 2 * WB - 2 * BB2, y + h - WB - BH, BB2, BH, "Run");
  _butt[1]->callback(onelab_cb, (void*)"compute");

  _gear = new Fl_Menu_Button(x + w - WB - BB2, y + h - WB - BH, BB2, BH);
#if defined(__APPLE__)
  _gear->label("@-1gmsh_gear");
#else
  _gear->image(new Fl_Bitmap(gear_bits, gear_width, gear_height));
#endif
  _gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _gear->add("Reset database", 0, onelab_cb, (void*)"reset");
  _gear->add("Save database...", 0, onelab_cb, (void*)"save");
  _gear->add("_Load database...", 0, onelab_cb, (void*)"load");

  _minWindowWidth = 3 * BB2 + 4 * WB;
  _minWindowHeight = 2 * BH + 3 * WB;

  _gearOptionsStart = _gear->menu()->size();

  _gear->add("Save && load database automatically", 0, onelab_option_cb, (void*)"save",
             FL_MENU_TOGGLE);
  _gear->add("Archive output files automatically", 0, onelab_option_cb, (void*)"archive",
             FL_MENU_TOGGLE);
  _gear->add("Check model after each change", 0, onelab_option_cb, (void*)"check",
             FL_MENU_TOGGLE);
  _gear->add("Remesh automatically", 0, onelab_option_cb, (void*)"mesh",
             FL_MENU_TOGGLE);
  _gear->add("Merge results automatically", 0, onelab_option_cb, (void*)"merge",
             FL_MENU_TOGGLE);
  _gear->add("Show new views", 0, onelab_option_cb, (void*)"show",
             FL_MENU_TOGGLE);
  _gear->add("Always show last step", 0, onelab_option_cb, (void*)"step",
             FL_MENU_TOGGLE);
  _gear->add("_Show hidden parameters", 0, onelab_option_cb, (void*)"invisible",
             FL_MENU_TOGGLE);

  _gearOptionsEnd = _gear->menu()->size();

  _gear->add("Add new solver...", 0, onelab_add_solver_cb);

  end();

  Fl_Box *resbox = new Fl_Box(x + WB, y + WB, WB, WB);
  resizable(resbox);

  rebuildSolverList();
}

static bool getFlColor(const std::string &str, Fl_Color &c)
{
  if(str == "1"){
    c = FL_YELLOW;
    return true;
  }
  int r, g, b;
  if(str.size() && GetRGBForString(str.c_str(), r, g, b)){
    c = fl_color_cube(r * (FL_NUM_RED - 1) / 255,
                      g * (FL_NUM_GREEN - 1) / 255,
                      b * (FL_NUM_BLUE - 1) / 255);
    return true;
  }
  c = FL_BLACK;
  return false;
}

template<class T>
static void autoCheck(const T &pold, const T &pnew, bool force=false)
{
  if(onelabUtils::getFirstComputationFlag()){
    if(pold.getValue() != pnew.getValue())
      onelabUtils::setFirstComputationFlag(false);
  }

  if((CTX::instance()->solver.autoCheck && pnew.getAttribute("AutoCheck") != "0") ||
     pnew.getAttribute("AutoCheck") == "1"){
    if(force || pold.getValue() != pnew.getValue())
      onelab_cb(0, (void*)"check");
  }
}

template<class T>
void onelabGroup::_addParameter(T &p)
{
  bool highlight = false;
  Fl_Color c;
  if(getFlColor(p.getAttribute("Highlight"), c)) highlight = true;
  Fl_Tree_Item *n = _tree->add(p.getName().c_str());
  n->labelsize(FL_NORMAL_SIZE + 4);
  _tree->begin();
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  ww *= _widgetLabelRatio; // FIXME CHANGE THIS
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Widget *widget = _addParameterWidget(p, ww, hh, n, highlight, c);
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  widget->copy_label(p.getShortName().c_str());
  std::string help = p.getLabel().size() ? p.getLabel() : p.getShortName();
  if(p.getHelp().size()) help += ":\n" + p.getHelp();
  widget->copy_tooltip(help.c_str());
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addMenu(const std::string &path, Fl_Callback *callback, void *data)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  _tree->begin();
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Button *but = new Fl_Button(1, 1, ww, hh);
  but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  but->callback(callback, data);
  but->box(FL_FLAT_BOX);
  but->color(_tree->color());
  but->selection_color(_tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  std::string label = path;
  std::string::size_type last = path.find_last_of('/');
  if(last != std::string::npos) label = path.substr(last + 1);
  but->copy_label(label.c_str());
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addSolverMenu(int num)
{
  std::ostringstream path;
  path << "0Modules/Solver/Solver" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new solverButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addViewMenu(int num)
{
  std::ostringstream path;
  path << "0Modules/Post-processing/View" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new viewButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

viewButton *onelabGroup::getViewButton(int num)
{
  char tmp[256];
  sprintf(tmp, "0Modules/Post-processing/View%d", num);
  Fl_Tree_Item *n = _tree->find_item(tmp);
  if(n){
    Fl_Group *grp = (Fl_Group*)n->widget();
    return (viewButton*)grp->child(0);
  }
  return 0;
}

template <class T>
static void setGmshOption(T &n)
{
  std::string opt = n.getAttribute("GmshOption");
  if(opt.empty()) return;
  if(opt == "ResetDatabase"){ // special option to reset the onelab db
    resetDb(false);
    FlGui::instance()->rebuildTree(false);
    return;
  }
  if(opt == "Reset"){ // reset db + models except current one
    resetDb(false);
    for(int i = PView::list.size() - 1; i >= 0; i--)
      delete PView::list[i];
    for(int i = GModel::list.size() - 1; i >= 0; i--)
      if(GModel::list[i] != GModel::current()) delete GModel::list[i];
    FlGui::instance()->rebuildTree(false);
    return;
  }
  std::string::size_type dot = opt.find('.');
  if(dot == std::string::npos) return;
  GmshSetOption(opt.substr(0, dot), opt.substr(dot + 1), n.getValue());
  drawContext::global()->draw();
}

static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Check_Button *o = (Fl_Check_Button*)w;
    onelab::number old = numbers[0];
    numbers[0].setValue(o->value());
    setGmshOption(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Choice *o = (Fl_Choice*)w;
    std::vector<double> choices = numbers[0].getChoices();
    onelab::number old = numbers[0];
    if(o->value() < (int)choices.size()) numbers[0].setValue(choices[o->value()]);
    setGmshOption(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    inputRange *o = (inputRange*)w;
    onelab::number old = numbers[0];
    if(o->doCallbackOnValues()){
      numbers[0].setValue(o->value());
      numbers[0].setMin(o->minimum());
      numbers[0].setMax(o->maximum());
      numbers[0].setStep(o->step());
      numbers[0].setChoices(o->choices());
    }
    o->doCallbackOnValues(true);
    numbers[0].setAttribute("Loop", o->loop());
    numbers[0].setAttribute("Graph", o->graph());
    setGmshOption(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    updateGraphs();
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_output_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    outputRange *o = (outputRange*)w;
    numbers[0].setAttribute("Graph", o->graph());
    onelab::server::instance()->set(numbers[0]);
    updateGraphs();
  }
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::number &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()){
    Fl_Choice *but = new Fl_Choice(1, 1, ww, hh);
    std::vector<Fl_Menu_Item> menu;
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::map<double, std::string>::iterator it = labels.begin();
        it != labels.end(); it++){
      char *str = strdup(it->second.c_str());
      _treeStrings.push_back(str);
      Fl_Menu_Item menuItem = {str, 0, 0, 0, 0};
      if(highlight) menuItem.labelcolor(c);
      menu.push_back(menuItem);
    }
    Fl_Menu_Item it = {0};
    menu.push_back(it);
    but->copy(&menu[0]);
    for(unsigned int i = 0; i < p.getChoices().size(); i++){
      if(p.getValue() == p.getChoices()[i]){
        but->value(i);
        break;
      }
    }
    but->callback(onelab_number_choice_cb, (void*)path);
    but->align(FL_ALIGN_RIGHT);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 &&
     p.getChoices()[0] == 0 && p.getChoices()[1] == 1){
    n->labelsize(FL_NORMAL_SIZE + 2);
    Fl_Check_Button *but = new Fl_Check_Button(1, 1, ww / _widgetLabelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(_tree->color());
    but->value(p.getValue());
    but->callback(onelab_number_check_button_cb, (void*)path);
    if(highlight) but->color(c);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // non-editable value
  if(p.getReadOnly()){
    outputRange *but = new outputRange(1, 1, ww, hh);
    but->callback(onelab_number_output_range_cb, (void*)path);
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT);
    but->graph(p.getAttribute("Graph"));
    if(highlight) but->color(c);
    return but;
  }

  // general number input
  inputRange *but = new inputRange(1, 1, ww, hh, onelab::parameter::maxNumber(),
                                   p.getAttribute("ReadOnlyRange") == "1");
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void*)path);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->color(c);
  return but;
}

static void onelab_string_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    std::string tmp = FixRelativePath(GModel::current()->getFileName(),
                                      strings[0].getValue());
    MergeFile(tmp);
    setGmshOption(strings[0]);
    autoCheck(strings[0], strings[0], true);
    drawContext::global()->draw();
  }
}

static void onelab_string_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    Fl_Input *o = (Fl_Input*)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
    setGmshOption(strings[0]);
    onelab::server::instance()->set(strings[0]);
    autoCheck(old, strings[0]);
  }
}

static void onelab_string_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    Fl_Input_Choice *o = (Fl_Input_Choice*)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
    std::string choices;
    for(int i = 0; i < o->menubutton()->menu()->size(); i++){
      if(o->menubutton()->menu()[i].flags & FL_MENU_TOGGLE){
        if(o->menubutton()->menu()[i].flags & FL_MENU_VALUE)
          choices += "1";
        else
          choices += "0";
      }
    }
    if(choices.size())
      strings[0].setAttribute("MultipleSelection", choices);
    setGmshOption(strings[0]);
    onelab::server::instance()->set(strings[0]);
    autoCheck(old, strings[0]);
  }
}

static void onelab_input_choice_file_chooser_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "", but->value())){
    but->value(fileChooserGetName(1).c_str());
    but->do_callback(but, data);
  }
}

static void onelab_input_choice_file_edit_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  std::string file = FixWindowsPath(but->value());
  SystemCall(ReplaceSubString("%s", file, prog));
}

static void onelab_input_choice_file_merge_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  std::string file = FixWindowsPath(but->value());
  MergeFile(file);
  drawContext::global()->draw();
}

static void multiple_selection_menu_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_Button *menu = (Fl_Menu_Button*)w;
  std::string val;
  for (int i = 0; i < menu->size() - 1; i++) {
    const Fl_Menu_Item &item = menu->menu()[i];
    if(item.value() && item.label()){
      if(val.size()) val += ", ";
      val += item.label();
    }
  }
  Fl_Input_Choice *but = (Fl_Input_Choice*)data;
  but->value(val.c_str());
  but->do_callback();
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::string &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // macro button
  if(p.getAttribute("Macro") == "Gmsh"){
    Fl_Button *but = new Fl_Button(1, 1, ww / _widgetLabelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(_tree->color());
    but->selection_color(_tree->color());
    but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    but->callback(onelab_string_button_cb, (void*)path);
    if(highlight) but->color(c);
    return but;
  }

  // non-editable value
  if(p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, ww, hh);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // simple string (no menu)
  if(p.getChoices().empty() && p.getKind() != "file"){
    Fl_Input *but = new Fl_Input(1, 1, ww, hh);
    but->value(p.getValue().c_str());
    but->callback(onelab_string_input_cb, (void*)path);
    but->when(FL_WHEN_ENTER_KEY);
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // general string input
  Fl_Input_Choice *but = new Fl_Input_Choice(1, 1, ww, hh);
  std::string multipleSelection = p.getAttribute("MultipleSelection");
  if(multipleSelection.size())
    but->menubutton()->callback(multiple_selection_menu_cb, but);
  std::vector<Fl_Menu_Item> menu;
  for(unsigned int j = 0; j < p.getChoices().size(); j++){
    char *str = strdup(p.getChoices()[j].c_str());
    _treeStrings.push_back(str);
    bool divider = (p.getKind() == "file" &&
                    j == p.getChoices().size() - 1);
    int choice = multipleSelection.size() ? FL_MENU_TOGGLE : 0;
    if(multipleSelection.size() > j && multipleSelection[j] == '1')
      choice |= FL_MENU_VALUE;
    Fl_Menu_Item it = {str, 0, 0, 0, divider ? FL_MENU_DIVIDER : choice};
    menu.push_back(it);
  }
  if(p.getKind() == "file"){
    Fl_Menu_Item it = {"Choose...", 0, onelab_input_choice_file_chooser_cb, (void*)n};
    menu.push_back(it);
    Fl_Menu_Item it2 = {"Edit...", 0, onelab_input_choice_file_edit_cb, (void*)n};
    menu.push_back(it2);
    if(GuessFileFormatFromFileName(p.getValue()) >= 0){
      Fl_Menu_Item it3 = {"Merge...", 0, onelab_input_choice_file_merge_cb, (void*)n};
      menu.push_back(it3);
    }
  }
  Fl_Menu_Item it = {0};
  menu.push_back(it);
  but->menubutton()->copy(&menu[0]);
  but->value(p.getValue().c_str());
  but->callback(onelab_string_input_choice_cb, (void*)path);
  but->input()->when(FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->input()->color(c);
  return but;
}

static void onelab_region_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::region> regions;
  onelab::server::instance()->get(regions, name);
  if(regions.size()){
    inputRegion *o = (inputRegion*)w;
    onelab::region old = regions[0];
    regions[0].setValue(o->value());
    onelab::server::instance()->set(regions[0]);
    autoCheck(old, regions[0]);
  }
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::region &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // non-editable value
  if(p.getReadOnly()){
    inputRegion *but = new inputRegion(1, 1, ww, hh, true);
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  inputRegion *but = new inputRegion(1, 1, ww, hh, false);
  but->value(p.getValue());
  but->align(FL_ALIGN_RIGHT);
  but->callback(onelab_region_input_cb, (void*)path);
  if(highlight) but->color(c);
  return but;
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::function &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  // non-editable value
  if(1 || p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, ww, hh);
    but->value("TODO function");
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }
}

void onelabGroup::rebuildTree(bool deleteWidgets)
{
  FL_NORMAL_SIZE -= CTX::instance()->deltaFontSize;

  _computeWidths();

  std::set<std::string> closed = _getClosedGmshMenus();

  _tree->clear();
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  // we don't delete widgets everytime the tree is rebuilt to minimize potential
  // race conditions (e.g. during heavy user interaction with autoCheck, with
  // risks to call handle() or focus() on deleted widgets)
  std::vector<Fl_Widget*> delWidgets;
  std::vector<char*> delStrings;
  if(deleteWidgets){
    delWidgets = _treeWidgets;
    delStrings = _treeStrings;
    _treeWidgets.clear();
    _treeStrings.clear();
  }

  _addGmshMenus();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(!numbers[i].getVisible() && !CTX::instance()->solver.showInvisibleParameters)
      continue;
    if(numbers[i].getAttribute("Closed") == "1")
      closed.insert(numbers[i].getPath());
    _addParameter(numbers[i]);
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    if(!strings[i].getVisible() && !CTX::instance()->solver.showInvisibleParameters)
      continue;
    if(strings[i].getAttribute("Closed") == "1")
      closed.insert(strings[i].getPath());
    _addParameter(strings[i]);
  }

  std::vector<onelab::region> regions;
  onelab::server::instance()->get(regions);
  for(unsigned int i = 0; i < regions.size(); i++){
    if(!regions[i].getVisible() && !CTX::instance()->solver.showInvisibleParameters)
      continue;
    if(regions[i].getAttribute("Closed") == "1")
      closed.insert(regions[i].getPath());
    _addParameter(regions[i]);
  }

  std::vector<onelab::function> functions;
  onelab::server::instance()->get(functions);
  for(unsigned int i = 0; i < functions.size(); i++){
    if(!functions[i].getVisible() && !CTX::instance()->solver.showInvisibleParameters)
      continue;
    if(functions[i].getAttribute("Closed") == "1")
      closed.insert(functions[i].getPath());
    _addParameter(functions[i]);
  }

  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()){
    if(n->has_children()){
      int ww = _baseWidth - (n->depth() + 1) * _indent;
      int hh = n->labelsize() + 4;
      _tree->begin();
#if 0 // FIXME this can crash FLTK when submenus are intially closed (somehow
      // the widget is badly positioned and overlaps the open icon, leading to
      // a corrupted Fl_Tree_Item)
      Fl_Button *but = new Fl_Button(1, 1, ww, hh);
      but->box(FL_NO_BOX);
      but->clear_visible_focus();
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      but->callback(onelab_subtree_cb, (void*)n);
#else
      Fl_Box *but = new Fl_Box(1, 1, ww, hh);
      //but->labelfont(FL_HELVETICA_ITALIC);
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
#endif
      _treeWidgets.push_back(but);
      onelab::string o(n->label());
      but->copy_label(o.getShortName().c_str());
      n->widget(but);
      _tree->end();
    }
  }

  for(std::set<std::string>::iterator it = closed.begin(); it != closed.end(); it++){
    if(it->size()) _tree->close(it->c_str(), 0);
  }

  _tree->redraw();

  FL_NORMAL_SIZE += CTX::instance()->deltaFontSize;

  FlGui::check(); // necessary e.g. on windows to avoid "ghosting"

  if(deleteWidgets){
    // this needs to be performed after FlGui::check()
    Msg::Debug("Deleting onelabGroup widgets (%d)", (int)_treeWidgets.size());
    for(unsigned int i = 0; i < delWidgets.size(); i++)
      Fl::delete_widget(delWidgets[i]);
    for(unsigned int i = 0; i < delStrings.size(); i++)
      free(delStrings[i]);
  }
}

void onelabGroup::openTreeItem(const std::string &name)
{
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if(n && n->has_children()){
    n->open();
    _tree->redraw();
  }
}

void onelabGroup::checkForErrors(const std::string &client)
{
  if(Msg::GetErrorCount() > 0 && !CTX::instance()->expertMode){
    std::string msg
      (client + " reported an error: do you really want to continue?\n\n"
       "(To disable this warning in the future, select `Enable expert mode'\n"
       "in the option dialog.)");
    if(Msg::GetAnswer(msg.c_str(), 1, "Stop", "Continue") == 0)
      _stop = true;
  }
}

void onelabGroup::setButtonVisibility()
{
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  bool showRun = onelab::server::instance()->getNumClients() > 1 || numbers.size();
  if(CTX::instance()->solver.autoCheck){
    _butt[0]->hide();
    if(showRun)
      _butt[1]->show();
    else
      _butt[1]->hide();
  }
  else if(showRun){
    _butt[0]->show();
    _butt[1]->show();
  }
  else{
    _butt[0]->hide();
    _butt[1]->hide();
  }
  redraw();
}

void onelabGroup::setButtonMode(const std::string &butt0, const std::string &butt1)
{
  if(butt0 == "check"){
    _butt[0]->activate();
    _butt[0]->label("Check");
    _butt[0]->callback(onelab_cb, (void*)"check");
  }
  else{
    _butt[0]->deactivate();
  }

  if(butt1 == "compute"){
    _butt[1]->activate();
    _butt[1]->label("Run");
    _butt[1]->callback(onelab_cb, (void*)"compute");
    for(int i = 0; i < _gear->menu()->size(); i++)
      ((Fl_Menu_Item*)_gear->menu())[i].activate();
  }
  else if(butt1 == "stop"){
    _butt[1]->activate();
    _butt[1]->label("Stop");
    _butt[1]->callback(onelab_cb, (void*)"stop");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
  else if(butt1 == "kill"){
    _butt[1]->activate();
    _butt[1]->label("Kill");
    _butt[1]->callback(onelab_cb, (void*)"kill");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
  else{
    _butt[1]->deactivate();
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
}

bool onelabGroup::isBusy()
{
  std::string s(_butt[1]->label());
  if(s == "Run") return false;
  return true;
}

std::string onelabGroup::getPath(Fl_Tree_Item *item)
{
  if(!item){
    Msg::Error("No item for path");
    return "";
  }
  char path[1024];
  if(_tree->item_pathname(path, sizeof(path), item)){
    Msg::Error("Could not get path for item");
    return "";
  }
  return std::string(path);
}

void onelabGroup::updateGearMenu()
{
  Fl_Menu_Item* menu = (Fl_Menu_Item*)_gear->menu();
  int values[8] = {CTX::instance()->solver.autoSaveDatabase,
                   CTX::instance()->solver.autoArchiveOutputFiles,
                   CTX::instance()->solver.autoCheck,
                   CTX::instance()->solver.autoMesh,
                   CTX::instance()->solver.autoMergeFile,
                   CTX::instance()->solver.autoShowViews,
                   CTX::instance()->solver.autoShowLastStep,
                   CTX::instance()->solver.showInvisibleParameters};
  for(int i = 0; i < 8; i++){
    int idx = _gearOptionsStart - 1 + i;
    if(values[i])
      menu[idx].set();
    else
      menu[idx].clear();
  }
}

void onelabGroup::rebuildSolverList()
{
  updateGearMenu();

  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < NUM_SOLVERS; i++){
    if(opt_solver_name(i, GMSH_GET, "").size()){
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(unsigned int i = 0; i < NUM_SOLVERS; i++){
    if(i < names.size()){
      onelab::server::citer it = onelab::server::instance()->findClient(names[i]);
      if(it != onelab::server::instance()->lastClient())
        it->second->setIndex(i);
      opt_solver_name(i, GMSH_SET, names[i]);
      opt_solver_executable(i, GMSH_SET, exes[i]);
      opt_solver_remote_login(i, GMSH_SET, hosts[i]);
    }
    else{
      opt_solver_name(i, GMSH_SET, "");
      opt_solver_executable(i, GMSH_SET, "");
      opt_solver_remote_login(i, GMSH_SET, "");
    }
  }

  setButtonVisibility();
  rebuildTree(true);
}

static bool needToChooseExe(const std::string &exe)
{
  // no exe given
  if(exe.empty()) return true;

  // exe is given with absolute path to non-existing file
  if(exe[0] == '/' || exe[0] == '\\' || (exe.size() > 2 && exe[1] == ':')){
    if(StatFile(exe)) return true;
  }

  return false;
}

void onelabGroup::addSolver(const std::string &name, const std::string &executable,
                            const std::string &remoteLogin, int index)
{
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()){
    if(needToChooseExe(executable))
      onelab_choose_executable_cb(0, (void *)it->second);
    return; // solver already exists
  }

  // delete the other non-local clients so we keep only the new one
  std::vector<onelab::client*> networkClients;
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++)
    if(it->second->isNetworkClient())
      networkClients.push_back(it->second);
  for(unsigned int i = 0; i < networkClients.size(); i++){
    delete networkClients[i];
  }

  // create and register the new client
  onelab::localNetworkClient *c = new gmshLocalNetworkClient(name, executable,
                                                             remoteLogin);
  c->setIndex(index);
  opt_solver_name(index, GMSH_SET, name);
  if(needToChooseExe(executable))
    onelab_choose_executable_cb(0, (void *)c);
  opt_solver_remote_login(index, GMSH_SET, remoteLogin);

  FlGui::instance()->onelab->rebuildSolverList();

  // initialize the client
  onelab_cb(0, (void*)"initialize");
}

void solver_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  if(num >= 0){
    std::string name = opt_solver_name(num, GMSH_GET, "");
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    std::string host = opt_solver_remote_login(num, GMSH_GET, "");
    FlGui::instance()->onelab->addSolver(name, exe, host, num);
  }
  else{
    FlGui::instance()->onelab->rebuildSolverList();
  }

  if(CTX::instance()->solver.autoSaveDatabase){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(!StatFile(db)){
      loadDb(db);
      CTX::instance()->launchSolverAtStartup = -1;
    }
  }

  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else{
    if(CTX::instance()->launchSolverAtStartup >= 0){
      onelab_cb(0, (void*)"reset");
      onelabUtils::setFirstComputationFlag(true);
    }
    else if(num >= 0)
      onelab_cb(0, (void*)"check");
    else
      onelab_cb(0, (void*)"refresh");
    FlGui::instance()->onelab->updateGearMenu();
  }

  CTX::instance()->launchSolverAtStartup = -1;
}

void solver_batch_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  if(num < 0) return;
  std::string name = opt_solver_name(num, GMSH_GET, "");
  std::string exe = opt_solver_executable(num, GMSH_GET, "");
  std::string host = opt_solver_remote_login(num, GMSH_GET, "");
  if(exe.empty()){
    Msg::Error("Solver executable name not provided");
    return;
  }

  onelab::number n("0Metamodel/Batch", CTX::instance()->batch);
  n.setVisible(false);
  onelab::server::instance()->set(n);

  // create client
  onelab::localNetworkClient *c = new gmshLocalNetworkClient(name, exe, host);
  c->setIndex(num);
  onelab::string o(c->getName() + "/Action");

  // initialize
  onelabUtils::runGmshClient("initialize", CTX::instance()->solver.autoMesh);
  o.setValue("initialize");
  onelab::server::instance()->set(o);
  c->run();

  // load db
  if(CTX::instance()->solver.autoSaveDatabase){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(!StatFile(db)) loadDb(db);
  }

  // check
  onelabUtils::runGmshClient("check", CTX::instance()->solver.autoMesh);
  onelabUtils::guessModelName(c);
  o.setValue("check");
  onelab::server::instance()->set(o);
  c->run();

  // compute
  initializeLoops();
  do{
    onelabUtils::runGmshClient("compute", CTX::instance()->solver.autoMesh);
    onelabUtils::guessModelName(c);
    o.setValue("compute");
    onelab::server::instance()->set(o);
    c->run();
  } while(incrementLoops());

  if(CTX::instance()->solver.autoSaveDatabase ||
     CTX::instance()->solver.autoArchiveOutputFiles){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(CTX::instance()->solver.autoArchiveOutputFiles) archiveOutputFiles(db);
    if(CTX::instance()->solver.autoSaveDatabase) saveDb(db);
  }
}

void flgui_wait_cb(double time)
{
  FlGui::instance()->wait(time);
}

/*
int metamodel_cb(const std::string &name, const std::string &action)
{
#if defined(HAVE_ONELAB_METAMODEL)
  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else{
    initializeMetamodel(Msg::GetExecutableName(),Msg::GetOnelabClient(),
			&flgui_wait_cb,Msg::GetVerbosity());

    onelab::number n("IsMetamodel", 1.);
    n.setVisible(false);
    onelab::server::instance()->set(n);
    std::vector<std::string> split = SplitFileName(name);
    onelab::string s1("Arguments/WorkingDir",
		      split[0].size() ? split[0] : GetCurrentWorkdir());
    s1.setVisible(false);
    s1.setAttribute("NotInDb","True");
    onelab::server::instance()->set(s1);
    onelab::string s2("Arguments/FileName", split[1]);
    s2.setVisible(false);
    onelab::server::instance()->set(s2);

    FlGui::instance()->onelab->rebuildSolverList();

    if(FlGui::instance()->available()){
      onelab_cb(0, (void*)"check");
    }
    else
      metamodel(action);
  }
  return 1;
#else
  return 0;
#endif
}
*/

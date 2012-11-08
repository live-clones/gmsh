// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl.H>
#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif

#include "GmshMessage.h"
#include "onelab.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include "inputRange.h"
#include "inputRegion.h"
#include "viewButton.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "fileDialogs.h"
#include "onelabGroup.h"
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
#include "metamodel.h"
#endif

// This file contains the Gmsh/FLTK specific parts of the OneLab
// interface. You'll need to reimplement this if you plan to build a different
// OneLab server.

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client)
    : GmshServer(), _client(client) {}
  ~onelabGmshServer(){}
  int NonBlockingSystemCall(const char *str){ return SystemCall(str); }
  int NonBlockingWait(int socket, double waitint, double timeout)
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
        // if asked, refresh the onelab GUI
        std::vector<onelab::string> ps;
        onelab::server::instance()->get(ps, "Gmsh/Action");
        if(ps.size() && ps[0].getValue() == "refresh"){
          ps[0].setVisible(false);
          ps[0].setValue("");
          onelab::server::instance()->set(ps[0]);
          onelab_cb(0, (void*)"refresh");
        }
        // wait at most waitint seconds and respond to FLTK events
        FlGui::instance()->wait(waitint);
      }
      else if(ret > 0){
        return 0; // data is there!
      }
      else{
        // an error happened
        _client->setPid(-1);
        _client->setGmshServer(0);
        return 1;
      }
    }
  }
};

bool onelab::localNetworkClient::run()
{
 new_connection:
  _pid = 0;
  _gmshServer = 0;

  onelabGmshServer *server = new onelabGmshServer(this);

  std::string sockname;
  std::ostringstream tmp;
  if(!strstr(CTX::instance()->solver.socketName.c_str(), ":")){
    // Unix socket
    tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName << getId();
    sockname = FixWindowsPath(tmp.str());
  }
  else{
    // TCP/IP socket
    if(CTX::instance()->solver.socketName.size() &&
       CTX::instance()->solver.socketName[0] == ':')
      tmp << GetHostName(); // prepend hostname if only the port number is given
    tmp << CTX::instance()->solver.socketName << getId();
    sockname = tmp.str();
  }

  std::string command = FixWindowsPath(_executable);
  if(command.size()){
    std::vector<std::string> args = onelabUtils::getCommandLine(this);
    for(unsigned int i = 0; i < args.size(); i++)
      command.append(" " + args[i]);
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else{
    Msg::Info("Listening on socket '%s'", sockname.c_str());
  }

  int sock;
  try{
    sock = server->Start(command.c_str(), sockname.c_str(),
                         CTX::instance()->solver.timeout);
  }
  catch(const char *err){
    Msg::Error("%s (on socket '%s')", err, sockname.c_str());
    sock = -1;
  }

  if(sock < 0){
    server->Shutdown();
    delete server;
    return false;
  }

  Msg::StatusBar(true, "Running '%s'...", _name.c_str());

  while(1) {

    if(_pid < 0 || (command.empty() && !CTX::instance()->solver.listen))
      break;

    int stop = server->NonBlockingWait(sock, 0.001, 0.);

    if(stop || _pid < 0 || (command.empty() && !CTX::instance()->solver.listen))
      break;

    double timer = GetTimeInSeconds();

    int type, length, swap;
    if(!server->ReceiveHeader(&type, &length, &swap)){
      Msg::Error("Did not receive message header: stopping server");
      break;
    }

    std::string message(length, ' ');
    if(!server->ReceiveMessage(length, &message[0])){
      Msg::Error("Did not receive message body: stopping server");
      break;
    }

    switch (type) {
    case GmshSocket::GMSH_START:
      _pid = atoi(message.c_str());
      _gmshServer = server;
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      _gmshServer = 0;
      break;
    case GmshSocket::GMSH_PARAMETER:
      {
        std::string version, type, name;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(onelab::parameter::version() != version){
          Msg::Error("OneLab version mismatch (server: %s / client: %s)",
                     onelab::parameter::version().c_str(), version.c_str());
        }
        else if(type == "number"){
          onelab::number p; p.fromChar(message); set(p);
          if(p.getName() == getName() + "/Progress")
            FlGui::instance()->setProgress(p.getLabel().c_str(), p.getValue(),
                                           p.getMin(), p.getMax());
        }
        else if(type == "string"){
          onelab::string p; p.fromChar(message); set(p);
        }
        else if(type == "region"){
          onelab::region p; p.fromChar(message); set(p);
        }
        else if(type == "function"){
          onelab::function p; p.fromChar(message); set(p);
        }
        else
          Msg::Error("Unknown OneLab parameter type: %s", type.c_str());
      }
      break;
    case GmshSocket::GMSH_PARAMETER_QUERY:
      {
        std::string version, type, name, reply;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(onelab::parameter::version() != version){
          Msg::Error("OneLab version mismatch (server: %s / client: %s)",
                     onelab::parameter::version().c_str(), version.c_str());
        }
        else if(type == "number"){
          std::vector<onelab::number> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else if(type == "string"){
          std::vector<onelab::string> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else if(type == "region"){
          std::vector<onelab::region> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else if(type == "function"){
          std::vector<onelab::function> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else
          Msg::Error("Unknown OneLab parameter type in query: %s", type.c_str());

        if(reply.size()){
          server->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
        }
        else{
          reply = "OneLab parameter '" + name + "' not found";
          server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
        }
      }
      break;
    case GmshSocket::GMSH_PARAM_QUERY_ALL:
      {
        std::string version, type, name, reply;
        std::vector<std::string> replies;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(onelab::parameter::version() != version){
          Msg::Error("OneLab version mismatch (server: %s / client: %s)",
                     onelab::parameter::version().c_str(), version.c_str());
        }
	else if(type == "number"){
	  std::vector<onelab::number> numbers; get(numbers);
	  for(std::vector<onelab::number>::iterator it = numbers.begin();
              it != numbers.end(); it++) replies.push_back((*it).toChar());
        }
        else if(type == "string"){
	  std::vector<onelab::string> strings; get(strings);
	  for(std::vector<onelab::string>::iterator it = strings.begin();
              it != strings.end(); it++) replies.push_back((*it).toChar());
        }
        else if(type == "region"){
	  std::vector<onelab::region> regions; get(regions);
	  for(std::vector<onelab::region>::iterator it = regions.begin();
              it != regions.end(); it++) replies.push_back((*it).toChar());
        }
        else if(type == "function"){
	  std::vector<onelab::function> functions; get(functions);
	  for(std::vector<onelab::function>::iterator it = functions.begin();
              it != functions.end(); it++) replies.push_back((*it).toChar());
        }
        else
          Msg::Error("Unknown OneLab parameter type in query: %s", type.c_str());

        for(unsigned int i = 0; i < replies.size(); i++)
          server->SendMessage
            (GmshSocket::GMSH_PARAM_QUERY_ALL, replies[i].size(), &replies[i][0]);
        reply = "Sent all OneLab " + type + "s";
        server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_END, reply.size(), &reply[0]);
      }
      break;
    case GmshSocket::GMSH_PROGRESS:
      Msg::StatusBar(false, "%s %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_INFO:
      Msg::Direct("%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_WARNING:
      Msg::Direct(2, "%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_ERROR:
      Msg::Direct(1, "%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_MERGE_FILE:
      if(CTX::instance()->solver.autoMergeFile){
        unsigned int n = PView::list.size();
        MergePostProcessingFile(message, CTX::instance()->solver.autoShowLastStep,
                                CTX::instance()->solver.autoHideNewViews, true);
        drawContext::global()->draw();
        if(n != PView::list.size()){
          FlGui::instance()->rebuildTree();
          FlGui::instance()->openModule("Post-processing");
        }
      }
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
        FlGui::instance()->updateViews(n != (int)PView::list.size());
        drawContext::global()->draw();
      }
      break;
    default:
      Msg::Warning("Received unknown message type (%d)", type);
      break;
    }
  }

  _gmshServer = 0;
  server->Shutdown();
  delete server;

  Msg::StatusBar(true, "Done running '%s'", _name.c_str());

  if(command.empty()){
    Msg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

  return true;
}

bool onelab::localNetworkClient::kill()
{
  if(_pid > 0) {
    if(KillProcess(_pid)){
      Msg::Info("Killed '%s' (pid %d)", _name.c_str(), _pid);
      _pid = -1;
      return true;
    }
  }
  _pid = -1;
  return false;
}

static void initializeLoops()
{
  onelabUtils::initializeLoop("1");
  onelabUtils::initializeLoop("2");
  onelabUtils::initializeLoop("3");

  if(onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree();
}

static bool incrementLoops()
{
  bool ret = false;
  if(onelabUtils::incrementLoop("3"))      ret = true;
  else if(onelabUtils::incrementLoop("2")) ret = true;
  else if(onelabUtils::incrementLoop("1")) ret = true;

  if(onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree();

  return ret;
}

static void updateGraphs()
{
  bool redraw0 = onelabUtils::updateGraph("0");
  bool redraw1 = onelabUtils::updateGraph("1");
  bool redraw2 = onelabUtils::updateGraph("2");
  bool redraw3 = onelabUtils::updateGraph("3");
  if(redraw0 || redraw1 || redraw2 || redraw3){
    FlGui::instance()->updateViews();
    drawContext::global()->draw();
  }
}

static std::string timeStamp()
{
  time_t now;
  time(&now);
  tm *t = localtime(&now);
  char stamp[32];
  sprintf(stamp, "_%04d-%02d-%02d_%02d-%02d-%02d", 1900 + t->tm_year,
          1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
  return std::string(stamp);
}

static void saveDb(const std::string &fileName)
{
  Msg::StatusBar(true, "Saving database '%s'...", fileName.c_str());
  if(onelab::server::instance()->toFile(fileName))
    Msg::StatusBar(true, "Done saving database '%s'", fileName.c_str());
  else
    Msg::Error("Could not save database '%s'", fileName.c_str());
}

static void archiveOutputFiles(const std::string &fileName)
{
  std::string stamp = timeStamp();

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
          CreateDirectory(split[0] + "archive/");
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
    CreateDirectory(split[0] + "archive/");
    saveDb(split[0] + "archive/" + split[1] + stamp + split[2]);
  }

  FlGui::instance()->rebuildTree();
}

static void loadDb(const std::string &name)
{
  Msg::StatusBar(true, "Loading database '%s'...", name.c_str());
  if(onelab::server::instance()->fromFile(name))
    Msg::StatusBar(true, "Done loading database '%s'", name.c_str());
  else
    Msg::Error("Could not load database '%s'", name.c_str());
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string action((const char*)data);

  if(action == "refresh"){
    updateGraphs();
    FlGui::instance()->rebuildTree();
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
    Msg::Direct("OneLab database:");
    for(unsigned int i = 0; i < db.size(); i++){
      for(unsigned int j = 0; j < db[i].size(); j++)
        if(db[i][j] == onelab::parameter::charSep()) db[i][j] = '|';
      Msg::Direct("%s", db[i].c_str());
    }
    std::string s = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(fileChooser(FILE_CHOOSER_CREATE, "Save", "*.db", s.c_str()))
      saveDb(fileChooserGetName(1));
    return;
  }

  if(action == "load"){
    std::string db = SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(fileChooser(FILE_CHOOSER_SINGLE, "Load", "*.db", db.c_str()))
      loadDb(fileChooserGetName(1));
    action = "check";
  }

  if(action == "reset"){
    // clear everything except command line and model name setup
    std::vector<onelab::number> useCommandLines, guessModelNames;
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
      onelab::client *c = it->second;
      std::vector<onelab::number> ps;
      c->get(ps, c->getName() + "/UseCommandLine");
      if(ps.size()) useCommandLines.push_back(ps[0]);
      c->get(ps, c->getName() + "/GuessModelName");
      if(ps.size()) guessModelNames.push_back(ps[0]);
    }
    onelab::server::instance()->clear();
    if(onelab::server::instance()->findClient("Gmsh") !=
       onelab::server::instance()->lastClient())
      onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh);
    for(unsigned int i = 0; i < useCommandLines.size(); i++)
      onelab::server::instance()->set(useCommandLines[i]);
    for(unsigned int i = 0; i < guessModelNames.size(); i++)
      onelab::server::instance()->set(guessModelNames[i]);
    action = "check";
  }

  FlGui::instance()->onelab->setButtonMode("", "stop");

  if(action == "compute") initializeLoops();

  // check whether we are running a metamodel
  std::vector<onelab::number> n;
  onelab::server::instance()->get(n, "IsMetamodel");
  bool isMetamodel = (n.size() && n[0].getValue());

  do{ // enter loop

    // if the client is a not a metamodel, run Gmsh
    if(!isMetamodel){
      if(onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh))
        drawContext::global()->draw();
    }

    if(action == "compute")
      FlGui::instance()->onelab->checkForErrors("Gmsh");
    if(FlGui::instance()->onelab->stop()) break;

    if(isMetamodel){
#if defined(HAVE_ONELAB_METAMODEL)
      if(metamodel(action))
	geometry_reload_cb(0, 0);
      Msg::ResetErrorCounter();
#endif
    }
    else{
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
    }

    if(action != "initialize"){
      updateGraphs();
      FlGui::instance()->rebuildTree();
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
  else if(what == "hide")
    CTX::instance()->solver.autoHideNewViews = val;
  else if(what == "step")
    CTX::instance()->solver.autoShowLastStep = val;
}

static void onelab_choose_executable_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient*)data;
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif
  const char *old = 0;
  if(!c->getExecutable().empty()) old = c->getExecutable().c_str();

  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose executable", pattern.c_str(), old)){
    std::string exe = fileChooserGetName(1);
    c->setExecutable(exe);
    if(c->getIndex() >= 0 && c->getIndex() < 5)
      opt_solver_executable(c->getIndex(), GMSH_SET, exe);
  }
}

static void onelab_remove_solver_cb(Fl_Widget *w, void *data)
{
  onelab::client *c = (onelab::client*)data;
  FlGui::instance()->onelab->removeSolver(c->getName());
}

static void onelab_add_solver_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < 5; i++){
    if(opt_solver_name(i, GMSH_GET, "").empty()){
      const char *name = fl_input("Client name:", "");
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

static void onelab_tree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree *tree = (Fl_Tree*)w;
  Fl_Tree_Item *item = (Fl_Tree_Item*)tree->callback_item();
  std::string path = FlGui::instance()->onelab->getPath(item);
  std::vector<onelab::number> numbers;
  std::vector<onelab::string> strings;
  std::vector<onelab::region> regions;
  std::vector<onelab::function> functions;

  switch(tree->callback_reason()){
  case FL_TREE_REASON_SELECTED: break;
  case FL_TREE_REASON_DESELECTED: break;
  case FL_TREE_REASON_OPENED:
    setClosed(path, numbers, "0");
    setClosed(path, strings, "0");
    setClosed(path, regions, "0");
    setClosed(path, functions, "0");
    break;
  case FL_TREE_REASON_CLOSED:
    setClosed(path, numbers, "1");
    setClosed(path, strings, "1");
    setClosed(path, regions, "1");
    setClosed(path, functions, "1");
    break;
  default:
    break;
  }
}

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x,y,w,h,l), _stop(false)
{
  _tree = new Fl_Tree(x, y, w, h - BH - 2 * WB);
  _tree->callback(onelab_tree_cb);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);
  _tree->box(FL_FLAT_BOX);
  _tree->scrollbar_size(std::max(10, FL_NORMAL_SIZE - 2));

  _itemWidth = (int)(0.4 * _tree->w());

  box(FL_FLAT_BOX);
  color(_tree->color());

  int BB2 = BB / 2 + 4;

  _butt[0] = new Fl_Button(x + w - 3 * WB - 3 * BB2, y + h - WB - BH, BB2, BH, "Check");
  _butt[0]->callback(onelab_cb, (void*)"check");

  _butt[1] = new Fl_Button(x + w - 2 * WB - 2 * BB2, y + h - WB - BH, BB2, BH, "Run");
  _butt[1]->callback(onelab_cb, (void*)"compute");

  _gear = new Fl_Menu_Button
    (x + w - WB - BB2, y + h - WB - BH, BB2, BH, "@-1gmsh_gear");
  _gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _gear->add("Reset database", 0, onelab_cb, (void*)"reset");
  _gear->add("Save database...", 0, onelab_cb, (void*)"save");
  _gear->add("_Load database...", 0, onelab_cb, (void*)"load");

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
  _gear->add("Hide new views", 0, onelab_option_cb, (void*)"hide",
             FL_MENU_TOGGLE);
  _gear->add("_Always show last step", 0, onelab_option_cb, (void*)"step",
             FL_MENU_TOGGLE);

  _gearOptionsEnd = _gear->menu()->size();

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
  n->labelsize(FL_NORMAL_SIZE + 5);
  _tree->begin();
  Fl_Widget *widget = _addParameterWidget(p, n, highlight, c);
  _treeWidgets.push_back(widget);
  widget->copy_label(p.getShortName().c_str());
  n->widget(widget);
  _tree->end();
}

void onelabGroup::_addMenu(const std::string &path, Fl_Callback *callback, void *data)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  n->labelsize(FL_NORMAL_SIZE + 5);
  _tree->begin();
  Fl_Button *but = new Fl_Button(1, 1, (3 * _itemWidth) / 2, 1);
  but->align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  but->callback(callback, data);
  _treeWidgets.push_back(but);
  std::string label = path;
  std::string::size_type last = path.find_last_of('/');
  if(last != std::string::npos) label = path.substr(last + 1);
  but->copy_label(label.c_str());
  n->widget(but);
  _tree->end();
}

void onelabGroup::_addViewMenu(int num)
{
  std::ostringstream path;
  path << "0Gmsh modules/Post-processing/View" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  n->labelsize(FL_NORMAL_SIZE + 5);
  _tree->begin();
  viewButton *but = new viewButton(1, 1, (7 * _itemWidth) / 4, 1, num);
  _treeWidgets.push_back(but);
  n->widget(but);
  _tree->end();
}

viewButton *onelabGroup::getViewButton(int num)
{
  char tmp[256];
  sprintf(tmp, "0Gmsh modules/Post-processing/View%d", num);
  Fl_Tree_Item *n = _tree->find_item(tmp);
  if(n) return (viewButton*)n->widget();
  return 0;
}

static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Check_Button *o = (Fl_Check_Button*)w;
    onelab::number old = numbers[0];
    numbers[0].setValue(o->value());
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Choice *o = (Fl_Choice*)w;
    std::vector<double> choices = numbers[0].getChoices();
    onelab::number old = numbers[0];
    if(o->value() < (int)choices.size()) numbers[0].setValue(choices[o->value()]);
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
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
    onelab::server::instance()->set(numbers[0]);
    updateGraphs();
    autoCheck(old, numbers[0]);
  }
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::number &p, Fl_Tree_Item *n,
                                            bool highlight, Fl_Color c)
{
  // non-editable value
  if(p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, _itemWidth, 1);
    char tmp[128];
    sprintf(tmp, "%g", p.getValue());
    but->value(tmp);
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()){
    Fl_Choice *but = new Fl_Choice(1, 1, _itemWidth, 1);
    std::vector<Fl_Menu_Item> menu;
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::map<double, std::string>::iterator it = labels.begin();
        it != labels.end(); it++){
      char *str = strdup(it->second.c_str());
      _treeStrings.push_back(str);
      Fl_Menu_Item menuItem = {str, 0, 0, 0, 0};
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
    but->callback(onelab_number_choice_cb, (void*)n);
    but->align(FL_ALIGN_RIGHT);
    if(highlight) n->labelbgcolor(c);
    return but;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 &&
     p.getChoices()[0] == 0 && p.getChoices()[1] == 1){
    Fl_Check_Button *but = new Fl_Check_Button(1, 1, _itemWidth, 1);
    but->value(p.getValue());
    but->callback(onelab_number_check_button_cb, (void*)n);
    if(highlight) n->labelbgcolor(c);
    return but;
  }

  // general number input
  inputRange *but = new inputRange
    (1, 1, _itemWidth, 1, onelab::parameter::maxNumber());
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void*)n);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->color(c);
  return but;
}

static void onelab_string_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    MergeFile(strings[0].getValue());
    autoCheck(strings[0], strings[0], true);
  }
}

static void onelab_string_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    Fl_Input_Choice *o = (Fl_Input_Choice*)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
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

Fl_Widget *onelabGroup::_addParameterWidget(onelab::string &p, Fl_Tree_Item *n,
                                            bool highlight, Fl_Color c)
{
  // macro button
  if(p.getKind() == "macro"){
    Fl_Button *but = new Fl_Button(1, 1, (3 * _itemWidth) / 2, 1);
    but->align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    but->callback(onelab_string_button_cb, (void*)n);
    if(highlight) but->color(c);
    return but;
  }

  // non-editable value
  if(p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, _itemWidth, 1);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // general string input
  Fl_Input_Choice *but = new Fl_Input_Choice(1, 1, _itemWidth, 1);
  std::vector<Fl_Menu_Item> menu;
  for(unsigned int j = 0; j < p.getChoices().size(); j++){
    char *str = strdup(p.getChoices()[j].c_str());
    _treeStrings.push_back(str);
    bool divider = (p.getKind() == "file" &&
                    j == p.getChoices().size() - 1);
    Fl_Menu_Item it = {str, 0, 0, 0, divider ? FL_MENU_DIVIDER : 0};
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
  but->callback(onelab_string_input_choice_cb, (void*)n);
  but->input()->when(FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->input()->color(c);
  return but;
}

static void onelab_region_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
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

Fl_Widget *onelabGroup::_addParameterWidget(onelab::region &p, Fl_Tree_Item *n,
                                            bool highlight, Fl_Color c)
{
  // non-editable value
  if(p.getReadOnly()){
    inputRegion *but = new inputRegion(1, 1, _itemWidth, 1, true);
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  inputRegion *but = new inputRegion(1, 1, _itemWidth, 1, false);
  but->value(p.getValue());
  but->align(FL_ALIGN_RIGHT);
  but->callback(onelab_region_input_cb, (void*)n);
  if(highlight) but->color(c);
  return but;
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::function &p, Fl_Tree_Item *n,
                                            bool highlight, Fl_Color c)
{
  // non-editable value
  if(1 || p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, _itemWidth, 1);
    but->value("TODO function");
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }
}

static void onelab_subtree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree_Item *n = (Fl_Tree_Item*)data;
  n->open_toggle();
  FlGui::instance()->onelab->redrawTree();
}

void onelabGroup::rebuildTree()
{
  _itemWidth = (int)(0.4 * _tree->w());

  std::set<std::string> closed = _getClosedGmshMenus();

  _tree->clear();
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  for(unsigned int i = 0; i < _treeWidgets.size(); i++)
    Fl::delete_widget(_treeWidgets[i]);
  _treeWidgets.clear();
  for(unsigned int i = 0; i < _treeStrings.size(); i++)
    free(_treeStrings[i]);
  _treeStrings.clear();

  _addGmshMenus();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(!numbers[i].getVisible()) continue;
    if(numbers[i].getAttribute("Closed") == "1")
      closed.insert(numbers[i].getPath());
    _addParameter(numbers[i]);
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    if(!strings[i].getVisible()) continue;
    if(strings[i].getAttribute("Closed") == "1")
      closed.insert(strings[i].getPath());
    _addParameter(strings[i]);
  }

  std::vector<onelab::region> regions;
  onelab::server::instance()->get(regions);
  for(unsigned int i = 0; i < regions.size(); i++){
    if(!regions[i].getVisible()) continue;
    if(regions[i].getAttribute("Closed") == "1")
      closed.insert(regions[i].getPath());
    _addParameter(regions[i]);
  }

  std::vector<onelab::function> functions;
  onelab::server::instance()->get(functions);
  for(unsigned int i = 0; i < functions.size(); i++){
    if(!functions[i].getVisible()) continue;
    if(functions[i].getAttribute("Closed") == "1")
      closed.insert(functions[i].getPath());
    _addParameter(functions[i]);
  }

  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()){
    if(n->has_children()){
      _tree->begin();
      Fl_Button *but = new Fl_Button(1, 1, _itemWidth, 1);
      but->box(FL_NO_BOX);
      but->clear_visible_focus();
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      but->callback(onelab_subtree_cb, (void*)n);
      _treeWidgets.push_back(but);
      onelab::string o(n->label());
      but->copy_label(o.getShortName().c_str());
      n->widget(but);
      _tree->end();
    }
  }

  for(std::set<std::string>::iterator it = closed.begin(); it != closed.end(); it++)
    _tree->close(it->c_str(), 0);

  _tree->redraw();

  FlGui::check(); // necessary e.g. on windows to avoid "ghosting"
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
    Msg::ResetErrorCounter();
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

void onelabGroup::rebuildSolverList()
{
  // update OneLab window title and gear menu
  _title = "OneLab";
  Fl_Menu_Item* menu = (Fl_Menu_Item*)_gear->menu();
  int values[7] = {CTX::instance()->solver.autoSaveDatabase,
                   CTX::instance()->solver.autoArchiveOutputFiles,
                   CTX::instance()->solver.autoCheck,
                   CTX::instance()->solver.autoMesh,
                   CTX::instance()->solver.autoMergeFile,
                   CTX::instance()->solver.autoHideNewViews,
                   CTX::instance()->solver.autoShowLastStep};
  for(int i = 0; i < 7; i++){
    int idx = _gearOptionsStart - 1 + i;
    if(values[i])
      menu[idx].set();
    else
      menu[idx].clear();
  }
  for(int i = menu->size(); i >= _gearOptionsEnd - 1; i--)
    _gear->remove(i);
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    if(it == onelab::server::instance()->firstClient()) _title += " -";
    if(it->second->isNetworkClient()){
      onelab::localNetworkClient *c = (onelab::localNetworkClient*)it->second;
      char tmp[256];
      sprintf(tmp, "%s/Choose executable", c->getName().c_str());
      _gear->add(tmp, 0, onelab_choose_executable_cb, (void*)c);
      sprintf(tmp, "%s/Remove", c->getName().c_str());
      _gear->add(tmp, 0, onelab_remove_solver_cb, (void*)c);
    }
    _title += " " + it->second->getName();
  }
  _gear->add("Add new client...", 0, onelab_add_solver_cb);
  //label(_title.c_str());

  // update Gmsh solver menu
  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < 5; i++){
    if(opt_solver_name(i, GMSH_GET, "").size()){
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(unsigned int i = 0; i < 5; i++){
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
  rebuildTree();
}

void onelabGroup::addSolver(const std::string &name, const std::string &executable,
                            const std::string &remoteLogin, int index)
{
  if(onelab::server::instance()->findClient(name) !=
     onelab::server::instance()->lastClient()) return; // solver already exists

  // unregister the other non-local clients so we keep only the new one
  std::vector<onelab::client*> networkClients;
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++)
    if(it->second->isNetworkClient())
      networkClients.push_back(it->second);
  for(unsigned int i = 0; i < networkClients.size(); i++){
    onelab::server::instance()->unregisterClient(networkClients[i]);
    delete networkClients[i];
  }

  // create and register the new client
  onelab::localNetworkClient *c = new onelab::localNetworkClient(name, executable,
                                                                 remoteLogin);
  c->setIndex(index);
  opt_solver_name(index, GMSH_SET, name);
  if(executable.empty())
    onelab_choose_executable_cb(0, (void *)c);
  opt_solver_remote_login(index, GMSH_SET, remoteLogin);

  FlGui::instance()->onelab->rebuildSolverList();

  // initialize the client
  onelab_cb(0, (void*)"initialize");
}

void onelabGroup::removeSolver(const std::string &name)
{
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()){
    onelab::client *c = it->second;
    if(c->isNetworkClient()){
      onelab::server::instance()->unregisterClient(c);
      if(c->getIndex() >= 0 && c->getIndex() < 5){
        opt_solver_name(c->getIndex(), GMSH_SET, "");
        opt_solver_executable(c->getIndex(), GMSH_SET, "");
        opt_solver_remote_login(c->getIndex(), GMSH_SET, "");
      }
      delete c;
    }
  }
  FlGui::instance()->onelab->rebuildSolverList();
}

void solver_cb(Fl_Widget *w, void *data)
{
  Msg::ResetErrorCounter();

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
    if(!StatFile(db)) loadDb(db);
  }

  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else
    onelab_cb(0, (num >= 0) ? (void*)"check" : (void*)"refresh");

  CTX::instance()->launchSolverAtStartup = -1;
}

void flgui_wait_cb(double time)
{
  FlGui::instance()->wait(time);
}

int metamodel_cb(const std::string &name, const std::string &action)
{
#if defined(HAVE_ONELAB_METAMODEL)
  Msg::ResetErrorCounter();
  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else{
    initializeMetamodel(Msg::GetExecutableName(),Msg::GetOnelabClient(), &flgui_wait_cb);

    onelab::number n("IsMetamodel", 1.);
    n.setVisible(false);
    onelab::server::instance()->set(n);
    std::vector<std::string> split = SplitFileName(name);
    onelab::string s1("Arguments/WorkingDir",
		      split[0].size()?split[0]:getCurrentWorkdir());
    s1.setVisible(false);
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

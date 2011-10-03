// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "onelab.h"

#if defined(HAVE_FL_TREE)
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Box.H>
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "OpenFile.h"
#include "drawContext.h"
#include "PView.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "menuWindow.h"
#include "fileDialogs.h"
#include "onelabWindow.h"

// This file contains the Gmsh/FLTK specific parts of the ONELAB
// interface. You'll need to reimplement this if you plan to build
// a different ONELAB server.

onelab::server *onelab::server::_server = 0;

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client) : GmshServer(), _client(client) {}
  ~onelabGmshServer() {}
  int SystemCall(const char *str)
  { 
    return ::SystemCall(str); 
  }
  int NonBlockingWait(int socket, double waitint, double timeout)
  { 
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout)
        return 2; // timout

      if(_client->getPid() < 0)
        return 1; // process has been killed

      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);

      if(ret == 0){ 
        // nothing available: wait at most waitint seconds, and in the
        // meantime respond to FLTK events
        FlGui::instance()->wait(waitint);
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
};

bool onelab::localNetworkClient::run(const std::string &what)
{
  _pid = 0;
  onelabGmshServer *server = new onelabGmshServer(this);
 
  std::string sockname = "localhost:1631";
  std::string command = _commandLine + " " + what +  " -onelab " + sockname + " &";

  int sock;
  try{
    sock = server->Start(command.c_str(), sockname.c_str(), 30);
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

  Msg::StatusBar(2, true, "Running '%s'...", _name.c_str());

  while(1) {

    if(_pid < 0) break;
    
    int stop = server->NonBlockingWait(sock, 0.1, 0.);
    if(stop || _pid < 0) break;
    
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
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      break;
    case GmshSocket::GMSH_PARAMETER:
      {
        std::string type, name;
        onelab::parameter::getTypeAndNameFromChar(message, type, name);
        if(type == "number"){
          onelab::number p;
          p.fromChar(message);
          set(p, false);
          printf("gmsh got '%s' from %s\n", p.toChar().c_str(), _name.c_str());
        }
        else if(type == "string"){
          onelab::string p;
          p.fromChar(message);
          set(p, false);
          printf("gmsh got '%s' from %s\n", p.toChar().c_str(), _name.c_str());
        }
      }
      break;
    case GmshSocket::GMSH_PARAMETER_QUERY:
      {
        std::string type, name;
        onelab::parameter::getTypeAndNameFromChar(message, type, name);
        if(type == "number"){
          std::vector<onelab::number> par;
          get(par, name);
          if(par.size() == 1){
            std::string reply = par[0].toChar();
            server->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
          }
          else{
            std::string reply = "Parameter " + name + " not found";
            server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
          }
        }
        else if(type == "string"){
          Msg::Error("FIXME do strings");
        }
      }
      break;
    case GmshSocket::GMSH_PROGRESS:
      Msg::StatusBar(2, false, "%s %s", _name.c_str(), message.c_str());
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
      {
        int n = PView::list.size();
        MergeFile(message);
        drawContext::global()->draw();
        if(n != (int)PView::list.size()) 
          FlGui::instance()->menu->setContext(menu_post, 0);
      }
      break;
    case GmshSocket::GMSH_PARSE_STRING:
      ParseString(message);
      drawContext::global()->draw();
      break;
    default:
      Msg::Warning("Received unknown message type (%d)", type);
      break;
    }

    FlGui::instance()->check();
  }

  server->Shutdown();
  delete server;

  Msg::StatusBar(2, true, "Done running '%s'", _name.c_str());
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

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string action((const char*)data);

  if(action == "choose model"){
    if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "*.pro"))
      FlGui::instance()->onelab->setModelName(fileChooserGetName(1));
    action = "check";
  }

  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    std::string what = FlGui::instance()->onelab->getModelName();
    if(action == "check")
      c->run(what);
    else if(action == "compute"){
      if(c->getName() == "getdp"){
        std::vector<onelab::string> str;
        onelab::server::instance()->get(str, "GetDP/Resolution");
        if(str.size()) what += " -solve " + str[0].getValue();
        onelab::server::instance()->get(str, "GetDP/Post-processing");
        if(str.size()) what += " -pos " + str[0].getValue();
        c->run(what);
      }
    }
  }
  printf("**** GMSH ONELAB DB DUMP:\n");
  onelab::server::instance()->print();
  printf("**** \n");
  FlGui::instance()->onelab->rebuildTree();
  FlGui::instance()->onelab->show();
}

static void onelab_number_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    numbers[0].setValue(((Fl_Value_Input*)w)->value());
    onelab::server::instance()->set(numbers[0]);
  }
}

static void onelab_string_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    strings[0].setValue(((Fl_Input*)w)->value());
    onelab::server::instance()->set(strings[0]);
  }
}

onelabWindow::onelabWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 25 * FL_NORMAL_SIZE;
  int height = 10 * BH + 3 * WB;
  
  _win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "ONELAB");
  _win->box(GMSH_WINDOW_BOX);

  _model = new Fl_Input(WB, WB, width - 2*WB - (2*BB)/3, BH);
  _model->align(FL_ALIGN_RIGHT);
  _model->value("/Users/geuzaine/src/getdp/demos/test.pro");
  _model->callback(onelab_cb, (void*)"check");
  _model->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);

  Fl_Button *choose = new Fl_Button(width - WB - (2*BB)/3, WB, (2*BB)/3, BH, "Choose");
  choose->callback(onelab_cb, (void*)"choose model");

  _tree = new Fl_Tree(WB, WB+BH, width - 2 * WB, height - 3 * WB - 2 * BH);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);

  _butt[0] = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Compute");
  _butt[0]->callback(onelab_cb, (void*)"compute");
  _butt[1] = new Fl_Button(width - 2*WB - 2*BB, height - WB - BH, BB, BH, "Check");
  _butt[1]->callback(onelab_cb, (void*)"check");

  Fl_Box *resbox = new Fl_Box(WB, height - BH - 3 * WB, WB, WB);
  _win->resizable(resbox);

  _win->position
    (CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  _win->end();

  FL_NORMAL_SIZE += deltaFontSize;

  onelab::server::instance()->registerClient
    (new onelab::localNetworkClient("getdp", "/Users/geuzaine/src/getdp/bin/getdp"));
}

static std::string getShortName(const std::string &name) 
{
  std::string::size_type last = name.find_last_of('/');
  if(last != std::string::npos)
    return name.substr(last + 1);
  return name;
}

void onelabWindow::rebuildTree()
{
  printf("rebulding tree\n");
  _tree->deactivate();
  _tree->clear();
  for(unsigned int i = 0; i < _treeWidgets.size(); i++)
    Fl::delete_widget(_treeWidgets[i]);
  _treeWidgets.clear();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    Fl_Tree_Item *n = _tree->add(numbers[i].getName().c_str());
    _tree->begin();
    Fl_Value_Input *but = new Fl_Value_Input(1,1,IW,1);
    _treeWidgets.push_back(but);
    but->copy_label(getShortName(numbers[i].getName()).c_str());
    but->value(numbers[i].getValue());
    but->minimum(0.);
    but->maximum(10.);
    but->step(0.1);
    but->align(FL_ALIGN_RIGHT);
    but->callback(onelab_number_cb, (void*)n);
    but->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
    n->widget(but);
    _tree->end();
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    Fl_Tree_Item *n = _tree->add(strings[i].getName().c_str());
    _tree->begin();
    Fl_Input *but = new Fl_Input(1,1,IW,1);
    _treeWidgets.push_back(but);
    but->copy_label(getShortName(strings[i].getName()).c_str());
    but->value(strings[i].getValue().c_str());
    but->align(FL_ALIGN_RIGHT);
    but->callback(onelab_string_cb, (void*)n);
    but->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
    n->widget(but);
    _tree->end();
  }
  
  _tree->activate();
  _tree->redraw();
  //n->user_data((void*)gv);
  //n->close();
}

void onelabWindow::redrawTree()
{
  _tree->redraw();
}

#endif

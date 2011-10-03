// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "onelab.h"

#if defined(HAVE_FL_TREE)
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "OpenFile.h"
#include "drawContext.h"
#include "PView.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "menuWindow.h"
#include "onelabWindow.h"

#include <FL/Fl_Value_Input.H>

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
          onelab::number par;
          par.fromChar(message);
          set(par, false);
          printf("gmsh got '%s' from %s\n", par.toChar().c_str(), _name.c_str());
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
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    c->run("/Users/geuzaine/src/getdp/demos/test.pro");
  }
  printf("**** GMSH ONELAB DB DUMP:\n");
  onelab::server::instance()->print();
  printf("**** \n");
  FlGui::instance()->onelab->rebuildTree();
  FlGui::instance()->onelab->show();
}

void onelab_compute_cb(Fl_Widget *w, void *data)
{
  printf("**** ONELAB DB DUMP:\n");
  onelab::server::instance()->print();
  printf("**** \n");

  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    c->run("/Users/geuzaine/src/getdp/demos/test.pro -solve MagSta_phi -pos phi");
  }
}

onelabWindow::onelabWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 32 * FL_NORMAL_SIZE;
  int height = 10 * BH + 3 * WB;
  
  _win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "ONELAB");
  _win->box(GMSH_WINDOW_BOX);

  _tree = new Fl_Tree(WB, WB, width - 2 * WB, height - 3 * WB - BH);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);

  _run = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Compute");
  _run->callback(onelab_compute_cb);

  _win->position
    (CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  _win->end();

  FL_NORMAL_SIZE += deltaFontSize;

  onelab::server::instance()->registerClient
    (new onelab::localNetworkClient("getdp", "/Users/geuzaine/src/getdp/bin/getdp"));
}

void number_cb(Fl_Widget *w, void *data)
{
  Fl_Value_Input *v = (Fl_Value_Input*)w;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, v->label());
  if(numbers.size()){
    numbers[0].setValue(v->value());
    onelab::server::instance()->set(numbers[0]);
  }
}

void onelabWindow::rebuildTree()
{
  printf("rebulding tree\n");
  _tree->clear();
  for(unsigned int i = 0; i < _treeWidgets.size(); i++)
    delete _treeWidgets[i];
  _treeWidgets.clear();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);

  for(unsigned int i = 0; i < numbers.size(); i++){
    Fl_Tree_Item *n = _tree->add(numbers[i].getName().c_str());
    _tree->begin();
    Fl_Value_Input *but = new Fl_Value_Input(1,1,IW,1);
    _treeWidgets.push_back(but);
    but->copy_label(numbers[i].getName().c_str());
    but->value(numbers[i].getValue());
    but->minimum(0.);
    but->maximum(10.);
    but->step(0.1);
    but->align(FL_ALIGN_RIGHT);
    but->callback(number_cb);
    n->widget(but);
    _tree->end();
  }
  
  _tree->redraw();
  //n->user_data((void*)gv);
  //n->close();
}

void onelabWindow::redrawTree()
{
  _tree->redraw();
}

#endif

// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "onelab.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "FlGui.h"
#include "paletteWindow.h"
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
  std::string command = "getdp -onelab -socket localhost:1631 test.pro &";

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

    double timer = GetTimeInSeconds();
    
    char *message = new char[length + 1];
    if(!server->ReceiveString(length, message)){
      Msg::Error("Did not receive message body: stopping server");
      delete [] message;
      break;
    }

    switch (type) {
    case GmshSocket::GMSH_START:
      _pid = atoi(message);
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      break;
    case GmshSocket::GMSH_ONELAB_PARAM:
      printf("server: got onelab param!\n");
      break;
    case GmshSocket::GMSH_PROGRESS:
      Msg::StatusBar(2, false, "%s %s", _name.c_str(), message);
      break;
    case GmshSocket::GMSH_INFO:
      Msg::Direct("%-8.8s: %s", _name.c_str(), message);
      break;
    case GmshSocket::GMSH_WARNING:
      Msg::Direct(2, "%-8.8s: %s", _name.c_str(), message);
      break;
    case GmshSocket::GMSH_ERROR:
      Msg::Direct(1, "%-8.8s: %s", _name.c_str(), message);
      break;
    default:
      Msg::Warning("Received unknown message type (%d)", type);
      break;
    }

    delete [] message;
    FlGui::instance()->check();
  }

  server->Shutdown();
  delete server;

  Msg::StatusBar(2, true, "Done running '%s'", _name.c_str());

  return false;
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
  printf("onelab has %d clients\n", onelab::server::instance()->getNumClients());
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    printf("client name = %s\n", c->getName().c_str());
  }
  FlGui::instance()->onelab->show();
}

onelabWindow::onelabWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 32 * FL_NORMAL_SIZE;
  int height = 10 * BH + 3 * WB;
  
  _win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "ONELAB");
  _win->box(GMSH_WINDOW_BOX);
  {
    _tree = new Fl_Tree(WB, WB, width - 2 * WB, height - 3 * WB - BH);
  }
  
  _run = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Compute");

  _win->position
    (CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  _win->end();

  FL_NORMAL_SIZE += deltaFontSize;

  onelab::server::instance()->registerClient(new onelab::localNetworkClient
                                             ("getdp", "/Users/geuzaine/src/getdp/bin/getdp"));
}

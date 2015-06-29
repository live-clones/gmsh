#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Scroll.H>
#include <iostream>

#include "OnelabWindow.h"
#include "OnelabDatabase.h"
#include "OnelabServer.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "Context.h"
#include "Options.h"

void onelab_listen_tcp_cb(Fl_Widget *w, void *data);
void onelab_listen_unix_cb(Fl_Widget *w, void *data);
#ifdef HAVE_UDT
void onelab_listen_udt_cb(Fl_Widget *w, void *data);
#endif
void onelab_connect_remote_server_cb(Fl_Widget *w, void *data);

onelabWindow::onelabWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 34 * FL_NORMAL_SIZE + WB;
  int height = 12 * BH + 4 * WB;

  win = new paletteWindow(width, height, CTX::instance()->nonModalWindows ? true : false);
  win->box(GMSH_WINDOW_BOX);
  win->label("ONELAB2");

  Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 2 * WB);
  {
    Fl_Group *o = new Fl_Group(
      WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Network (server)");
    _listenOnUNIX = new Fl_Check_Button(2*WB, 2*WB + 1*BH, width-2*WB, BH, "Listen on UNIX socket");
    _sockUNIX = new Fl_Input(2*WB, 2*WB + 2*BH, width/2-2*WB, BH, "UNIX base socket name");
    _listenOnUNIX->callback(onelab_listen_unix_cb, _sockUNIX);
    _sockUNIX->align(FL_ALIGN_RIGHT);
    _listenOnTCP = new Fl_Check_Button(2*WB, 2*WB + 3*BH, width-2*WB, BH, "Listen on TCP socket");
    _sockTCP = new Fl_Input(2*WB, 2*WB + 4*BH, width/2-2*WB, BH, "TCP port (0 to let the system choose)");
    _listenOnTCP->callback(onelab_listen_tcp_cb, _sockTCP);
    _sockTCP->align(FL_ALIGN_RIGHT);
#ifdef HAVE_UDT
    _listenOnUDT = new Fl_Check_Button(2*WB, 2*WB + 5*BH, width-2*WB, BH, "Listen on UDT (UDP) socket");
    _sockUDT = new Fl_Input(2*WB, 2*WB + 6*BH, width/2-2*WB, BH, "UDP port (0 to let the system choose)");
    _listenOnUDT->callback(onelab_listen_udt_cb, _sockUDT);
    _sockUDT->align(FL_ALIGN_RIGHT);
#else
    _listenOnUDT = new Fl_Check_Button(2*WB, 2*WB + 5*BH, width-2*WB, BH, "Listen on UDT (UDP) socket");
    _sockUDT = new Fl_Input(2*WB, 2*WB + 6*BH, width/2-2*WB, BH, "UDP port (0 to let the system choose)");
    _sockUDT->align(FL_ALIGN_RIGHT);
#endif
    refreshServers();
    o->end();
  }
  {
    Fl_Group *o = new Fl_Group(
      0, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Clients (server)");
    _solvers = new Fl_Choice(2*WB, 2*WB + 1*BH, width/2-2*WB, BH, "Solver");
    _solvers->align(FL_ALIGN_RIGHT);
    rebuildSolverList();
    _clients = new Fl_Browser(2*WB, 2*WB + 3*BH, width/2-2*WB, 5*BH, "Connected clients");
    _clients->align(FL_ALIGN_RIGHT);
    o->end();
  }
  {
    Fl_Group *o = new Fl_Group(
      WB, WB + BH, width - 2 * WB, height - 2 * WB - BH, "Network (client)");
    _remoteServer = new Fl_Input(2*WB, 2*WB + 1*BH, width/2-2*WB, BH, "Server address (IPv4:port)");
    _remoteServer->align(FL_ALIGN_RIGHT);
    _connectRemoteServer = new Fl_Button(2*WB, 3*WB + 2*BH, width/2-2*WB, BH, "Connect");
    _connectRemoteServer->callback(onelab_connect_remote_server_cb, _remoteServer);
  }
}

void onelabWindow::refresh(){
  refreshServers();
  rebuildSolverList();
  refreshRemoteServer();
}

void onelabWindow::refreshServers()
{
  if(OnelabDatabase::instance()->isNetworkClient()) {
    _listenOnUNIX->deactivate();
    _listenOnTCP->deactivate();
    _listenOnUDT->deactivate();
    _sockUNIX->deactivate();
    _sockUDT->deactivate();
    _sockTCP->deactivate();
    return;
  }

  _sockUNIX->value(CTX::instance()->onelab.unixSock.c_str());
  _sockTCP->value(CTX::instance()->onelab.tcpSock.c_str());
#ifdef HAVE_UDT
  _sockUDT->value(CTX::instance()->onelab.udtSock.c_str());
#else
  _sockUDT->value("Not compiled with UDT library");
#endif
  if(CTX::instance()->onelab.unixConnected) {
    _listenOnUNIX->value(1);
    _sockUNIX->deactivate();
  }
  else {
    _listenOnUNIX->value(0);
    _sockUNIX->activate();
  }

  if(CTX::instance()->onelab.tcpConnected) {
    _listenOnTCP->value(1);
    _sockTCP->deactivate();
  }
  else {
    _listenOnTCP->value(0);
    _sockTCP->activate();
  }

  if(CTX::instance()->onelab.udtConnected) {
    _listenOnUDT->value(1);
    _sockUDT->deactivate();
  }
  else {
    _listenOnUDT->value(0);
    _sockUDT->activate();
  }
}

void onelabWindow::rebuildSolverList()
{
  _solvers->clear();
  for(int i = 0; i < NUM_SOLVERS; i++){
    if(opt_solver_name(i, GMSH_GET, "").size())
      _solvers->add(opt_solver_name(i, GMSH_GET, "").c_str());
  }
  if(CTX::instance()->solverToRun >= 0) _solvers->value(CTX::instance()->solverToRun);
}

void onelabWindow::refreshRemoteServer()
{
  if(OnelabDatabase::instance()->isNetworkClient()) {
    _remoteServer->value();
    //TODO size_t colon = sockname.find(':');
    //if(colon != std::string::npos) {
    //  address = ip4_inet_pton(sockname.substr(0,colon).c_str());
    //  port = atoi(sockname.substr(colon+1).c_str());
    //}
    //GmshNetworkClient *c = OnelabDatabase::instance()->useAsNetworkClient(address, port, name);
    //if(c == NULL) {
    //  Error("Unable to connect ONELAB server (%s)", sockname.c_str());
    //  Exit(1);
    //}
  }
}

void onelab_listen_tcp_cb(Fl_Widget *w, void *data)
{
  Fl_Check_Button *checkbutton = (Fl_Check_Button *)w;
  Fl_Input *sockTCP = (Fl_Input *)data;
  if(checkbutton->value() == 1) {
    sockTCP->deactivate();
    CTX::instance()->onelab.tcpSock = sockTCP->value();
    std::size_t colon = CTX::instance()->onelab.tcpSock.find(":");
    OnelabServer::instance()->listenOnTcp(
      ip4_inet_pton(CTX::instance()->onelab.tcpSock.substr(0, colon).c_str()),
      atoi(CTX::instance()->onelab.tcpSock.substr(colon+1, CTX::instance()->onelab.tcpSock.size()-colon-1).c_str()));
  }
  else {
    sockTCP->activate();
    OnelabServer::instance()->stopTcp();
  }
}

void onelab_listen_unix_cb(Fl_Widget *w, void *data)
{
  Fl_Check_Button *checkbutton = (Fl_Check_Button *)w;
  Fl_Input *sockUNIX = (Fl_Input *)data;
  if(checkbutton->value() == 1) {
    sockUNIX->deactivate();
    CTX::instance()->onelab.unixSock = sockUNIX->value();
    std::size_t colon = CTX::instance()->onelab.unixSock.find(":");
    std::ostringstream tmp;
    tmp << CTX::instance()->homeDir << CTX::instance()->onelab.unixSock;
    OnelabServer::instance()->listenOnUnix(tmp.str().c_str());
  }
  else {
    sockUNIX->activate();
    OnelabServer::instance()->stopUnix();
  }
}

#ifdef HAVE_UDT
void onelab_listen_udt_cb(Fl_Widget *w, void *data)
{
  Fl_Check_Button *checkbutton = (Fl_Check_Button *)w;
  Fl_Input *sockUDT = (Fl_Input *)data;
  if(checkbutton->value() == 1) {
    sockUDT->deactivate();
    CTX::instance()->onelab.udtSock = sockUDT->value();
    std::size_t colon = CTX::instance()->onelab.udtSock.find(":");
    OnelabServer::instance()->listenOnTcp(
      ip4_inet_pton(CTX::instance()->onelab.udtSock.substr(0, colon).c_str()),
      atoi(CTX::instance()->onelab.udtSock.substr(colon+1, CTX::instance()->onelab.udtSock.size()-colon-1).c_str()));
  }
  else {
    sockUDT->activate();
    OnelabServer::instance()->stopUdt();
  }
}
#endif

void onelab2_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->onelab2->refresh();
  FlGui::instance()->onelab2->win->show();
}

void onelab_connect_remote_server_cb(Fl_Widget *w, void *data)
{
  Fl_Input *serverAddr = (Fl_Input *)data;
  std::string address = serverAddr->value();
  std::size_t colon = address.find(":");
  GmshNetworkClient *c = OnelabDatabase::instance()->useAsNetworkClient(
    ip4_inet_pton(address.substr(0, colon).c_str()),
    atoi(address.substr(colon+1, address.size()-colon-1).c_str()),
    "GUI");
  if(c == NULL) {
    Msg::Error("Unable to connect ONELAB server (%s)", address.c_str());
    Msg::Exit(1);
  }
  else if(FlGui::available()) // FIXME
    c->setCallback(FlGui::instance()->onelab);
}

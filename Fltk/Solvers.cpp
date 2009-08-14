// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <string>
#include "FlGui.h"
#include "solverWindow.h"
#include "menuWindow.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "Solvers.h"
#include "GmshSocket.h"
#include "OpenFile.h"
#include "PView.h"
#include "Draw.h"
#include "Context.h"
#include "OS.h"

SolverInfo SINFO[MAX_NUM_SOLVERS];

class myGmshServer : public GmshServer{
 public:
  myGmshServer() : GmshServer() {}
  ~myGmshServer() {}
  int SystemCall(const char *str){ return ::SystemCall(str); }
  int NonBlockingWait(int socket, int num, double waitint)
  { 
    // This routine polls the socket at least every 'waitint' seconds and
    // returns 0 if data is available or 1 if there was en error or if the
    // process was killed. Otherwise it just tends to current GUI events
    // (this is easier to manage than non-blocking IO, and simpler than
    // using the "real" solution, i.e., threads. Another possibility would
    // be to use Fl::add_fd())
    while(1){
      if((num >= 0 && SINFO[num].pid < 0) || (num < 0 && !CTX::instance()->solver.listen)){
        // process has been killed or we stopped listening
        return 1;
      }

      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(socket, 0, 0);

      if(ret == 0){ 
        // nothing available: wait at most waitint seconds, and in the
        // meantime respond to FLTK events
        FlGui::instance()->wait(waitint);
      }
      else if(ret > 0){ 
        // data is there
        return 0;
      }
      else{ 
        // an error happened
        if(num >= 0){
          SINFO[num].pid = -1;
          SINFO[num].server = 0;
        }
        return 1;
      }
    }
  }
};

// This routine either launches a solver and waits for some answer (if
// num >= 0), or simply waits for messages (if num < 0)

int Solver(int num, const char *args)
{
  std::string command, sockname, prog;

 new_connection:

  GmshServer *server = new myGmshServer;

  if(num >= 0){
    prog = FixWindowsPath(SINFO[num].executable_name.c_str());
    if(!SINFO[num].client_server) {
      command = prog + " " + args;
#if !defined(WIN32)
      command += " &";
#endif
      server->StartClient(command.c_str());
      return 1;
    }
  }
  else{
    if(!CTX::instance()->solver.listen){
      Msg::Info("Stopped listening for solver connections");
      return 0;
    }
    // we don't know who will (maybe) contact us
    prog = command = "";
  }

  if(!strstr(CTX::instance()->solver.socketName.c_str(), ":")){
    // Unix socket
    char tmp[1024];
    if(num >= 0)
      sprintf(tmp, "%s%s-%d", CTX::instance()->homeDir.c_str(), 
              CTX::instance()->solver.socketName.c_str(),
              num);
    else
      sprintf(tmp, "%s%s", CTX::instance()->homeDir.c_str(), 
              CTX::instance()->solver.socketName.c_str());
    sockname = FixWindowsPath(tmp);
  }
  else{
    // TCP/IP socket
    sockname = CTX::instance()->solver.socketName;
    // if only the port is given, prepend the host name
    if(sockname.size() && sockname[0] == ':')
      sockname = GetHostName() + sockname;
  }

  if(num >= 0){
    std::string tmp2 = "\"" + sockname + "\"";
    char tmp[1024];
    sprintf(tmp, SINFO[num].socket_command.c_str(), tmp2.c_str());
    command = prog + " " + args + " " + tmp;
#if !defined(WIN32)
    command += " &";
#endif
  }

  int sock = server->StartClient(command.c_str(), sockname.c_str());

  if(sock < 0) {
    switch (sock) {
    case -1:
      Msg::Error("Couldn't create socket '%s'", sockname.c_str());
      break;
    case -2:
      Msg::Error("Couldn't bind socket to name '%s'", sockname.c_str());
      break;
    case -3:
      Msg::Error("Socket listen failed on '%s'", sockname.c_str());
      break;
    case -4:
      Msg::Error("Socket listen timeout on '%s'", sockname.c_str());
      Msg::Error("Is '%s' correctly installed?", prog.c_str());
      break;
    case -5:
      Msg::Error("Socket accept failed on '%s'", sockname.c_str());
      break;
    case -6:
      Msg::Info("Stopped listening for solver connections");
      server->StopClient();
      break;
    case -7:
      Msg::Error("Unix sockets not available on Windows without Cygwin");
      Msg::Error("Use TCP/IP sockets instead");
      break;
    case -8:
      Msg::Error("Could not initialize Windows sockets");
      break;
    }
    if(num >= 0){
      for(int i = 0; i < SINFO[num].nboptions; i++)
        FlGui::instance()->solver[num]->choice[i]->clear();
    }
    return 0;
  }

  if(num >= 0){
    SINFO[num].pid = 0;
    SINFO[num].server = 0;
  }
  bool initOption[5] = {true, true, true, true, true};

  Msg::StatusBar(2, false, "Running '%s'", prog.c_str());

  while(1) {

    int stop = (num < 0 && !CTX::instance()->solver.listen);

    if(stop || (num >= 0 && SINFO[num].pid < 0))
      break;

    stop = server->NonBlockingWait(sock, num, 0.1);

    if(stop || (num >= 0 && SINFO[num].pid < 0))
      break;

    int type, length;
    if(server->ReceiveHeader(&type, &length)){
      double timer = GetTimeInSeconds();
      char *message = new char[length + 1];
      if(server->ReceiveString(length, message)){
        switch (type) {
        case GmshServer::CLIENT_START:
          if(num >= 0){
            SINFO[num].pid = atoi(message);
            SINFO[num].server = server;
          }
          break;
        case GmshServer::CLIENT_STOP:
          stop = 1;
          if(num >= 0){
            SINFO[num].pid = -1;
            SINFO[num].server = 0;
          }
          break;
        case GmshServer::CLIENT_PROGRESS:
          if(num >= 0)
            Msg::StatusBar(2, false, "%s %s", SINFO[num].name.c_str(), message);
          else
            Msg::StatusBar(2, false, "%s", message);
          break;
        case GmshServer::CLIENT_OPTION_1:
          if(initOption[0]){
            SINFO[num].option[0].clear();
            initOption[0] = false;
          }
          if(num >= 0)
            SINFO[num].option[0].push_back(message);
          break;
        case GmshServer::CLIENT_OPTION_2:
          if(initOption[1]){
            SINFO[num].option[1].clear();
            initOption[1] = false;
          }
          if(num >= 0)
            SINFO[num].option[1].push_back(message);
          break;
        case GmshServer::CLIENT_OPTION_3:
          if(initOption[2]){
            SINFO[num].option[2].clear();
            initOption[2] = false;
          }
          if(num >= 0)
            SINFO[num].option[2].push_back(message);
          break;
        case GmshServer::CLIENT_OPTION_4:
          if(initOption[3]){
            SINFO[num].option[3].clear();
            initOption[3] = false;
          }
          if(num >= 0)
            SINFO[num].option[3].push_back(message);
          break;
        case GmshServer::CLIENT_OPTION_5:
          if(initOption[4]){
            SINFO[num].option[4].clear();
            initOption[4] = false;
          }
          if(num >= 0)
            SINFO[num].option[4].push_back(message);
          break;
        case GmshServer::CLIENT_MERGE_FILE:
          if(num < 0 || (num >= 0 && SINFO[num].merge_views)) {
            int n = PView::list.size();
            MergeFile(message);
            Draw();
            if(n != (int)PView::list.size()) 
              FlGui::instance()->menu->setContext(menu_post, 0);
          }
          break;
        case GmshServer::CLIENT_PARSE_STRING:
          ParseString(message);
          Draw();
          break;
        case GmshServer::CLIENT_INFO:
          Msg::Direct("%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshServer::CLIENT_WARNING:
          Msg::Direct(2, "%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshServer::CLIENT_ERROR:
          Msg::Direct(1, "%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshServer::CLIENT_SPEED_TEST:
          Msg::Info("got %d Mb message in %g seconds", 
                    strlen(message) / 1024 / 1024, GetTimeInSeconds() - timer);
          break;
        default:
          Msg::Warning("Unknown type of message received from %s",
                       num >= 0 ? SINFO[num].name.c_str() : "client");
          Msg::Direct("%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client", 
                      message);
          break;
        }
        FlGui::instance()->check();
      }
      else{
        Msg::Warning("Failed to receive message body on socket: aborting");
        break;
      }
      delete [] message;
    }
    else{
      // didn't get any header, just abort
      break;
    }
  }
  
  if(num >= 0){
    if(!initOption[0] || !initOption[1] || !initOption[2] || 
       !initOption[3] || !initOption[4]){ // some options have been changed
      for(int i = 0; i < SINFO[num].nboptions; i++) {
        FlGui::instance()->solver[num]->choice[i]->clear();
        for(unsigned int j = 0; j < SINFO[num].option[i].size(); j++)
          FlGui::instance()->solver[num]->choice[i]->add(SINFO[num].option[i][j].c_str());
        FlGui::instance()->solver[num]->choice[i]->value(0);
      }
    }
  }
  
  server->StopClient();

  if(num >= 0){
    Msg::StatusBar(2, false, "");
  }
  else{
    Msg::Info("Client disconnected: starting new connection");
    delete server;
    goto new_connection;
  }

  return 1;
}

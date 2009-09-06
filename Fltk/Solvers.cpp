// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <string>
#include <sstream>
#include "FlGui.h"
#include "solverWindow.h"
#include "menuWindow.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "Solvers.h"
#include "GmshSocket.h"
#include "OpenFile.h"
#include "PView.h"
#include "drawContext.h"
#include "Context.h"
#include "OS.h"

SolverInfo SINFO[MAX_NUM_SOLVERS + 1];

class myGmshServer : public GmshServer{
 public:
  myGmshServer() : GmshServer() {}
  ~myGmshServer() {}
  int SystemCall(const char *str){ return ::SystemCall(str); }
  int NonBlockingWait(int socket, int num, double waitint, double timeout)
  { 
    // This routine polls the socket at least every 'waitint' seconds,
    // and for at most timout seconds (or indefinitely if
    // timeout==0). The routine returns 0 as soon as data is available
    // and 1 if there was en error or if the process was
    // killed. Otherwise it just tends to current GUI events (this is
    // easier to manage than non-blocking IO, and simpler than using
    // the "real" solution, i.e., threads. Another possibility would
    // be to use Fl::add_fd())
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout) {
        return 2; // timout
      }

      if((num >= 0 && SINFO[num].pid < 0) ||
         (num < 0 && !CTX::instance()->solver.listen)){
        return 1; // process has been killed or we stopped listening
      }

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
        if(num >= 0){
          SINFO[num].pid = -1;
          SINFO[num].server = 0;
        }
        return 1;
      }
    }
  }
};

std::string GetSocketName(int num)
{
  std::string sockname;
  if(!strstr(CTX::instance()->solver.socketName.c_str(), ":")){
    // Unix socket
    std::ostringstream tmp;
    tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName;
    if(num >= 0) tmp << "-" << num;
    sockname = FixWindowsPath(tmp.str());
  }
  else{
    // TCP/IP socket
    sockname = CTX::instance()->solver.socketName;
    // if only the port is given, prepend the host name
    if(sockname.size() && sockname[0] == ':')
      sockname = GetHostName() + sockname;
  }
  return sockname;
}

// This routine either launches a solver and waits for some answer (if
// num >= 0), or simply waits for messages (if num < 0)

int Solver(int num, const char *args)
{
  std::string command, sockname, prog;

 new_connection:

  GmshServer *server = new myGmshServer;

  if(num >= 0){
    prog = FixWindowsPath(SINFO[num].executable_name);
    if(!SINFO[num].client_server) {
      command = prog + " " + args;
#if !defined(WIN32)
      command += " &";
#endif
      server->Start(num, command.c_str(), 0, 0.);
      delete server;
      return 1;
    }
  }
  else{
    if(!CTX::instance()->solver.listen){
      Msg::Info("Stopped listening for solver connections");
      delete server;
      return 0;
    }
    // we don't know who will (maybe) contact us
    prog = command = "";
  }

  sockname = GetSocketName(num);

  if(num >= 0){
    std::string tmp2 = "\"" + sockname + "\"";
    char tmp[1024];
    sprintf(tmp, SINFO[num].socket_command.c_str(), tmp2.c_str());
    command = prog + " " + args + " " + tmp;
#if !defined(WIN32)
    command += " &";
#endif
  }

  if(num >= 0){
    SINFO[num].pid = 0;
    SINFO[num].server = 0;
  }
  bool initOption[5] = {true, true, true, true, true};

  int sock;
  try{
    sock = server->Start(num, command.c_str(), sockname.c_str(), 5.);
  }
  catch(const char *err){
    Msg::Error("%s (on socket '%s')", err, sockname.c_str());
    sock = -1;
  }

  if(sock < 0){
    if(num >= 0){
      for(int i = 0; i < SINFO[num].nboptions; i++)
        FlGui::instance()->solver[num]->choice[i]->clear();
    }
    server->Shutdown();
    delete server;
    return 0;
  }

  Msg::StatusBar(2, false, "Running '%s'", prog.c_str());

  while(1) {

    int stop = (num < 0 && !CTX::instance()->solver.listen);

    if(stop || (num >= 0 && SINFO[num].pid < 0))
      break;

    stop = server->NonBlockingWait(sock, num, 0.1, 0.);

    if(stop || (num >= 0 && SINFO[num].pid < 0))
      break;

    int type, length;
    if(server->ReceiveHeader(&type, &length)){
      double timer = GetTimeInSeconds();
      char *message = new char[length + 1];
      if(server->ReceiveString(length, message)){
        switch (type) {
        case GmshSocket::START:
          if(num >= 0){
            SINFO[num].pid = atoi(message);
            SINFO[num].server = server;
          }
          break;
        case GmshSocket::STOP:
          stop = 1;
          if(num >= 0){
            SINFO[num].pid = -1;
            SINFO[num].server = 0;
          }
          break;
        case GmshSocket::PROGRESS:
          if(num >= 0)
            Msg::StatusBar(2, false, "%s %s", SINFO[num].name.c_str(), message);
          else
            Msg::StatusBar(2, false, "%s", message);
          break;
        case GmshSocket::OPTION_1:
          if(initOption[0]){
            SINFO[num].option[0].clear();
            initOption[0] = false;
          }
          if(num >= 0)
            SINFO[num].option[0].push_back(message);
          break;
        case GmshSocket::OPTION_2:
          if(initOption[1]){
            SINFO[num].option[1].clear();
            initOption[1] = false;
          }
          if(num >= 0)
            SINFO[num].option[1].push_back(message);
          break;
        case GmshSocket::OPTION_3:
          if(initOption[2]){
            SINFO[num].option[2].clear();
            initOption[2] = false;
          }
          if(num >= 0)
            SINFO[num].option[2].push_back(message);
          break;
        case GmshSocket::OPTION_4:
          if(initOption[3]){
            SINFO[num].option[3].clear();
            initOption[3] = false;
          }
          if(num >= 0)
            SINFO[num].option[3].push_back(message);
          break;
        case GmshSocket::OPTION_5:
          if(initOption[4]){
            SINFO[num].option[4].clear();
            initOption[4] = false;
          }
          if(num >= 0)
            SINFO[num].option[4].push_back(message);
          break;
        case GmshSocket::MERGE_FILE:
          if(num < 0 || (num >= 0 && SINFO[num].merge_views)) {
            int n = PView::list.size();
            MergeFile(message);
            drawContext::global()->draw();
            if(n != (int)PView::list.size()) 
              FlGui::instance()->menu->setContext(menu_post, 0);
          }
          break;
        case GmshSocket::PARSE_STRING:
          ParseString(message);
          drawContext::global()->draw();
          break;
        case GmshSocket::INFO:
          Msg::Direct("%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshSocket::WARNING:
          Msg::Direct(2, "%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshSocket::ERROR:
          Msg::Direct(1, "%-8.8s: %s", num >= 0 ? SINFO[num].name.c_str() : "Client",
                      message);
          break;
        case GmshSocket::SPEED_TEST:
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

    // only necessary in case of error
    SINFO[num].server = 0;
  }

  server->Shutdown();
  delete server;

  if(num >= 0){
    Msg::StatusBar(2, false, "");
  }
  else{
    Msg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

  return 1;
}

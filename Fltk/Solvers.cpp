// $Id: Solvers.cpp,v 1.36 2005-03-14 06:32:33 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GmshServer.h"

// FIXME: this should be removed
int GmshServer::init = 0;
int GmshServer::s;

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/poll.h>
#include <sys/un.h>
#include <unistd.h>

#include "OpenFile.h"
#include "Solvers.h"
#include "GmshUI.h"
#include "GUI.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

extern Context_T CTX;
extern GUI *WID;

SolverInfo SINFO[MAXSOLVERS];

int Solver(int num, char *args)
{
  char command[1024], sockname[1024], str[1024], prog[1024], buf[1024];

  GmshServer server(CTX.solver.max_delay);

  FixWindowsPath(SINFO[num].executable_name, prog);

  if(!SINFO[num].client_server) {
    sprintf(command, "%s %s", prog, args);
#if !defined(WIN32)
    strcat(command, " &");
#endif
    server.StartClient(command);
    return 1;
  }

  if(!strstr(CTX.solver.socket_name, ":")){
    // file socket
    sprintf(str, "%s%s-%d", CTX.home_dir, CTX.solver.socket_name, num);
    FixWindowsPath(str, sockname);
  }
  else
    strcpy(sockname, CTX.solver.socket_name);

  sprintf(str, "\"%s\"", sockname);
  sprintf(buf, SINFO[num].socket_command, str);
  
  sprintf(command, "%s %s %s", prog, args, buf);
#if !defined(WIN32)
  strcat(command, " &");
#endif

  int sock = server.StartClient(command, sockname);
  if(sock < 0) {
    switch (sock) {
    case -1:
      Msg(GERROR, "Couldn't create socket '%s'", sockname);
      break;
    case -2:
      Msg(GERROR, "Couldn't bind socket to name '%s'", sockname);
      break;
    case -3:
      Msg(GERROR, "Socket listen failed on '%s'", sockname);
      break;
    case -4:
      Msg(GERROR, "Socket listen timeout on '%s'", sockname);
      Msg(GERROR, "Is '%s' correctly installed?", prog);
      break;
    case -5:
      Msg(GERROR, "Socket accept failed on '%s'", sockname);
      break;
    }
    for(int i = 0; i < SINFO[num].nboptions; i++)
      WID->solver[num].choice[i]->clear();
    return 0;
  }

  for(int i = 0; i < SINFO[num].nboptions; i++)
    SINFO[num].nbval[i] = 0;
  SINFO[num].pid = 0;

  struct pollfd pfd;
  pfd.fd = sock;
  pfd.events = POLLIN;

  while(1) {
    // poll the socket file descriptor every 10 milliseconds until
    // data is avalable; when nothing is available, just tend to
    // pending GUI events. (This is much easier to manage than
    // non-blocking IO. The real solution is of course to use threads,
    // but that's still a bit of a nightmare to maintain in a portable
    // way on all the platforms.)
    while(1){
      if(SINFO[num].pid < 0){ // process has been killed
	break;
      }
      int ret = poll(&pfd, 1, 10);
      if(ret == 0){ // nothing available
	WID->check();
      }
      else if(ret > 0){ // data is there
        break;
      }
      else{ // error
        SINFO[num].pid = -1;
        break;
      }
    }

    if(SINFO[num].pid < 0)
      break;

    int type;
    if(server.ReceiveString(&type, str)){
      switch (type) {
      case GmshServer::CLIENT_START:
	SINFO[num].pid = atoi(str);
	break;
      case GmshServer::CLIENT_STOP:
	SINFO[num].pid = -1;
	break;
      case GmshServer::CLIENT_PROGRESS:
	Msg(STATUS3N, "%s %s", SINFO[num].name, str);
	break;
      case GmshServer::CLIENT_OPTION_1:
	strcpy(SINFO[num].option[0][SINFO[num].nbval[0]++], str);
	break;
      case GmshServer::CLIENT_OPTION_2:
	strcpy(SINFO[num].option[1][SINFO[num].nbval[1]++], str);
	break;
      case GmshServer::CLIENT_OPTION_3:
	strcpy(SINFO[num].option[2][SINFO[num].nbval[2]++], str);
	break;
      case GmshServer::CLIENT_OPTION_4:
	strcpy(SINFO[num].option[3][SINFO[num].nbval[3]++], str);
	break;
      case GmshServer::CLIENT_OPTION_5:
	strcpy(SINFO[num].option[4][SINFO[num].nbval[4]++], str);
	break;
      case GmshServer::CLIENT_VIEW:
	if(SINFO[num].merge_views) {
	  int n = List_Nbr(CTX.post.list);
	  MergeProblem(str);
	  Draw();
	  if(n != List_Nbr(CTX.post.list))
	    WID->set_context(menu_post, 0);
	}
	break;
      case GmshServer::CLIENT_INFO:
	Msg(SOLVER, "%-8.8s: %s", SINFO[num].name, str);
	break;
      case GmshServer::CLIENT_WARNING:
      case GmshServer::CLIENT_ERROR:
	Msg(SOLVERR, "%-8.8s: %s", SINFO[num].name, str);
	break;
      default:
	Msg(WARNING, "Unknown type of message received from %s",
	    SINFO[num].name);
	Msg(SOLVER, "%-8.8s: %s", SINFO[num].name, str);
	break;
      }
      WID->check();
    }
  }
  
  for(int i = 0; i < SINFO[num].nboptions; i++) {
    if(SINFO[num].nbval[i]) {
      WID->solver[num].choice[i]->clear();
      for(int j = 0; j < SINFO[num].nbval[i]; j++)
        WID->solver[num].choice[i]->add(SINFO[num].option[i][j]);
      WID->solver[num].choice[i]->value(0);
    }
  }

  Msg(STATUS3N, "Ready");

  if(server.StopClient() < 0)
    Msg(WARNING, "Impossible to unlink the socket '%s'", sockname);

  return 1;
}

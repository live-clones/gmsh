// $Id: Solvers.cpp,v 1.25 2004-05-22 01:24:17 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "GmshClient.h"
#include "GmshServer.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
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
  int sock, type, stop = 0, i, j, n;
  char command[1000], socket_name[1000], str[1000];

  if(!SINFO[num].client_server) {
    sprintf(command, "%s %s &", SINFO[num].executable_name, args);
    Gmsh_StartClient(command, NULL);
    return 1;
  }

  sprintf(socket_name, "%s.gmshsock-%d", CTX.home_dir, num);
  sprintf(command, "%s %s -socket \"%s\"", SINFO[num].executable_name,
          args, socket_name);
#if !defined(WIN32)
  strcat(command, " &");
#endif

  sock = Gmsh_StartClient(command, socket_name);
  if(sock < 0) {
    switch (sock) {
    case -1:
      Msg(GERROR, "Couldn't create socket '%s'", socket_name);
      break;
    case -2:
      Msg(GERROR, "Couldn't bind socket to name '%s'", socket_name);
      break;
    case -3:
      Msg(GERROR, "Socket listen failed on '%s'", socket_name);
      break;
    case -4:
      Msg(GERROR,
          "Solver not responding (is '%s' correctly installed/in your path?)",
          SINFO[num].executable_name);
      break;
    case -5:
      Msg(GERROR, "Socket accept failed on '%s'", socket_name);
      break;
    }
    for(i = 0; i < SINFO[num].nboptions; i++)
      WID->solver[num].choice[i]->clear();
    return 0;
  }

  for(i = 0; i < SINFO[num].nboptions; i++)
    SINFO[num].nbval[i] = 0;
  SINFO[num].pid = 0;

  while(1) {
    if(SINFO[num].pid < 0)
      break;
    Gmsh_ReceiveString(sock, &type, str);
    switch (type) {
    case GMSH_CLIENT_START:
      SINFO[num].pid = atoi(str);
      break;
    case GMSH_CLIENT_STOP:
      SINFO[num].pid = -1;
      stop = 1;
      break;
    case GMSH_CLIENT_PROGRESS:
      Msg(STATUS3N, "%s %s", SINFO[num].name, str);
      break;
    case GMSH_CLIENT_OPTION_1:
    case GMSH_CLIENT_OPTION_2:
    case GMSH_CLIENT_OPTION_3:
    case GMSH_CLIENT_OPTION_4:
    case GMSH_CLIENT_OPTION_5:
      i = type - GMSH_CLIENT_OPTION;
      strcpy(SINFO[num].option[i][SINFO[num].nbval[i]++], str);
      break;
    case GMSH_CLIENT_VIEW:
      if(SINFO[num].merge_views) {
        n = List_Nbr(CTX.post.list);
        MergeProblem(str);
        Draw();
        if(n != List_Nbr(CTX.post.list))
          WID->set_context(menu_post, 0);
      }
      break;
    case GMSH_CLIENT_INFO:
      Msg(SOLVER, "%-8.8s: %s", SINFO[num].name, str);
      break;
    case GMSH_CLIENT_WARNING:
    case GMSH_CLIENT_ERROR:
      Msg(SOLVERR, "%-8.8s: %s", SINFO[num].name, str);
      break;
    default:
      Msg(WARNING, "Unknown type of message received from %s",
          SINFO[num].name);
      Msg(SOLVER, "%-8.8s: %s", SINFO[num].name, str);
      break;
    }
    if(stop)
      break;
  }

  for(i = 0; i < SINFO[num].nboptions; i++) {
    if(SINFO[num].nbval[i]) {
      WID->solver[num].choice[i]->clear();
      for(j = 0; j < SINFO[num].nbval[i]; j++)
        WID->solver[num].choice[i]->add(SINFO[num].option[i][j]);
      WID->solver[num].choice[i]->value(0);
    }
  }

  Msg(STATUS3N, "Ready");

  if(Gmsh_StopClient(socket_name, sock) < 0)
    Msg(WARNING, "Impossible to unlink the socket '%s'", socket_name);

  return 1;
}

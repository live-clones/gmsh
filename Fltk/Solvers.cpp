// $Id: Solvers.cpp,v 1.7 2001-05-21 13:01:13 geuzaine Exp $

#include "Gmsh.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

#include "Socket.h"
#include "OpenFile.h"
#include "Solvers.h"
#include "GmshUI.h"
#include "GUI.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

extern Context_T  CTX;
extern GUI       *WID;


// interface to GetDP

_GetDP_Info GetDP_Info ;

int GetDP(char *args){
  int sock, type, i, n;
  char progname[1000], sockname[1000], str[1000];

  strcpy(sockname, CTX.home_dir);
  strcat(sockname, ".gmshsock");

  sprintf(progname, "%s %s", GetDP_Info.command, args);
  sock = Socket_StartProgram(progname, sockname);
  if(sock<0){
    Msg(GERROR, "Could not execute '%s'", progname);
    WID->getdp_choice[0]->clear();
    WID->getdp_choice[1]->clear();
    return 0;
  }

  Socket_ReceiveInt(sock, &GetDP_Info.pid);

  Msg(INFO, "GetDP start (%s)", progname);

  GetDP_Info.nbres = 0;
  GetDP_Info.nbpostop = 0;

  while(1){
    if(GetDP_Info.pid < 0) break;

    Socket_ReceiveInt(sock, &type);

    if(type == GETDP_END) break;

    Socket_ReceiveString(sock, str);

    switch(type){
    case GETDP_PROGRESS :
      Msg(STATUS3N, "GetDP %s", str);
      break ;
    case GETDP_RESOLUTION_NAME :
      strcpy(GetDP_Info.res[GetDP_Info.nbres++],str);
      break ;
    case GETDP_POSTOPERATION_NAME :
      strcpy(GetDP_Info.postop[GetDP_Info.nbpostop++],str);
      break ;
    case GETDP_LOAD_VIEW :
      if(GetDP_Info.mergeviews){
	n = List_Nbr(Post_ViewList);
	MergeProblem(str);
	Draw(); 
	if(n != List_Nbr(Post_ViewList))
	  WID->set_context(menu_post, 0);
      }
      break ;
    case GETDP_INFO :
      Msg(DIRECT, "GetDP > %s", str);
      break;
    default :
      Msg(WARNING, "Unknown type of message received from GetDP");
      Msg(DIRECT, "GetDP > %s", str);
      break ;
    }

  }

  if(GetDP_Info.nbres){
    WID->getdp_choice[0]->clear();
    for(i=0;i<GetDP_Info.nbres;i++) 
      WID->getdp_choice[0]->add(GetDP_Info.res[i]);
    WID->getdp_choice[0]->value(0);
  }

  if(GetDP_Info.nbpostop){
    WID->getdp_choice[1]->clear();
    for(i=0;i<GetDP_Info.nbpostop;i++) 
      WID->getdp_choice[1]->add(GetDP_Info.postop[i]);
    WID->getdp_choice[1]->value(0);
  }

  Msg(STATUS3N, "Ready");

  Socket_StopProgram(progname, sockname, sock);

  GetDP_Info.pid = -1;

  Msg(INFO, "GetDP stop (%s)", progname);

  return 1;
}




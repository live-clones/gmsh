// $Id: Solvers.cpp,v 1.3 2001-05-04 13:39:34 geuzaine Exp $

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


extern GUI       *WID;


#if defined(WIN32) && !defined(__CYGWIN__)
#define SLASH "\\"
#else
#define SLASH "/"
#endif

#define GET_PATH(path_val)					\
  char *tmp;							\
  if     ((tmp = getenv("HOME"))) strcpy(path_val, tmp);	\
  else if((tmp = getenv("TMP")))  strcpy(path_val, tmp);	\
  else if((tmp = getenv("TEMP"))) strcpy(path_val, tmp);	\
  else                            strcpy(path_val, "");		\
  if(strlen(path_val)) strcat(path_val, SLASH);




// interface to GetDP

_GetDP_Info GetDP_Info ;

int GetDP(char *args){
  int sock, type, i, n ;
  char progname[1000], sockname[1000], str[1000];

  GET_PATH(sockname);
  strcat(sockname, ".gmshsock");

  sprintf(progname, GetDP_Info.command, args);
  sock = Socket_StartProgram(progname, sockname);
  if(sock<0){
    Msg(GERROR, "Could not execute '%s'", progname);
    return 0;
  }

  Msg(INFO, "GetDP start (%s)", progname);

  GetDP_Info.nbres = 0;
  GetDP_Info.nbpostop = 0;

  while(1){
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

  Msg(STATUS3N, "");

  Socket_StopProgram(progname, sockname, sock);

  Msg(INFO, "GetDP stop (%s)", progname);

  return 1;
}




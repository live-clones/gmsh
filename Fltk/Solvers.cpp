// $Id: Solvers.cpp,v 1.1 2001-05-03 00:09:42 geuzaine Exp $

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
  int sock, i, n ;
  char progname[1000], sockname[1000], str[1000];

  GET_PATH(sockname);
  strcat(sockname, ".gmsh-socket-GetDP");

  sprintf(progname, "getdp %s", args);
  sock = Socket_StartProgram(progname, sockname);
  if(sock<0){
    Msg(GERROR, "Could not execute '%s'", progname);
    return 0;
  }

  GetDP_Info.nbres = 0;
  GetDP_Info.nbpostop = 0;

  while(1){
    Socket_ReceiveInt(sock, &i);

    if(i<0){
      Msg(INFO, "Finished '%s'", progname);
      break;
    }

    Socket_ReceiveString(sock, str);

    switch(i){
    case 10 : // status
      Msg(STATUS3N, "GetDP %s", str);
      break ;
    case 101 : // available resolution
      strcpy(GetDP_Info.res[GetDP_Info.nbres++],str);
      break ;
    case 102 : // available postoperations
      strcpy(GetDP_Info.postop[GetDP_Info.nbpostop++],str);
      break ;
    case 200 : // load postprocessing file
      n = List_Nbr(Post_ViewList);
      MergeProblem(str);
      Draw(); 
      if(n != List_Nbr(Post_ViewList))
	WID->set_context(menu_post, 0);
      break ;
    default :
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


  Socket_StopProgram(progname, sockname, sock);

  return 1;
}




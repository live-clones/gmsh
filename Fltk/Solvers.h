#ifndef _SOLVERS_H_
#define _SOLVERS_H_

// Message protocol for GetDP

#define GETDP_END                 -1
#define GETDP_INFO                 1
#define GETDP_PROGRESS             2
#define GETDP_RESOLUTION_NAME      3
#define GETDP_POSTOPERATION_NAME   4
#define GETDP_LOAD_VIEW            5

typedef struct{
  char command[256];
  int popupmessages, mergeviews;
  int pid;
  int nbres, nbpostop;
  char res[100][100];
  char postop[100][100];
} _GetDP_Info ;

extern _GetDP_Info GetDP_Info ;

int GetDP(char *args);


#endif


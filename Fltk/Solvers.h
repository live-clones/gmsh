#ifndef _SOLVERS_H_
#define _SOLVERS_H_


typedef struct{
  int nbres, nbpostop;
  char res[100][100];
  char postop[100][100];
  char file[256], mesh[256];
} _GetDP_Info ;

extern _GetDP_Info GetDP_Info ;

int GetDP(char *args);


#endif


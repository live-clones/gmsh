#ifndef _SOLVERS_H_
#define _SOLVERS_H_

typedef struct{
  char name[256], extension[32], executable_name[256];
  char mesh_name[256], mesh_command[256];
  char button_name[5][32], button_command[5][256];
  char option_name[5][256], option_command[256];
  char option[5][100][256];
  int  nboptions, nbval[5];
  char *help;
  int client_server, popup_messages, merge_views;
  int pid;
} SolverInfo ;

extern SolverInfo SINFO[5] ;

int Solver(int num, char *args);

#endif


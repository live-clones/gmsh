#ifndef _SOLVERS_H_
#define _SOLVERS_H_

#define MAXSOLVERS 5

typedef struct{
  char name[256], extension[32], executable_name[256];
  char mesh_name[256], mesh_command[256];
  char button_name[MAXSOLVERS][32], button_command[MAXSOLVERS][256];
  char option_name[MAXSOLVERS][256], option_command[256];
  char option[MAXSOLVERS][100][256];
  int  nboptions, nbval[MAXSOLVERS];
  char *help;
  int client_server, popup_messages, merge_views;
  int pid;
} SolverInfo ;

extern SolverInfo SINFO[MAXSOLVERS] ;

int Solver(int num, char *args);

#endif


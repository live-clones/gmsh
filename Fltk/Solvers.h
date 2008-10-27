// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SOLVERS_H_
#define _SOLVERS_H_

#define MAXSOLVERS 5

class GmshServer;

typedef struct{
  char name[256], extension[32], executable_name[256];
  char mesh_name[256], mesh_command[256];
  char socket_command[256];
  char name_command[256];
  char button_name[MAXSOLVERS][32], button_command[MAXSOLVERS][256];
  char option_name[MAXSOLVERS][256], option_command[256];
  char option[MAXSOLVERS][100][256];
  int  nboptions, nbval[MAXSOLVERS];
  const char *help;
  int client_server, popup_messages, merge_views;
  int pid;
  GmshServer *server;
} SolverInfo ;

extern SolverInfo SINFO[MAXSOLVERS] ;

int Solver(int num, const char *args);

#endif

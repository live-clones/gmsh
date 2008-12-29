// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SOLVERS_H_
#define _SOLVERS_H_

#define MAX_NUM_SOLVERS 5
#define MAX_NUM_SOLVER_OPTIONS 5

class GmshServer;

typedef struct{
  char name[256], extension[32], executable_name[256];
  char mesh_name[256], mesh_command[256];
  char socket_command[256];
  char name_command[256];
  char button_name[MAX_NUM_SOLVER_OPTIONS][32];
  char button_command[MAX_NUM_SOLVER_OPTIONS][256];
  char option_name[MAX_NUM_SOLVER_OPTIONS][256], option_command[256];
  char option[MAX_NUM_SOLVER_OPTIONS][100][256];
  int  nboptions, nbval[MAX_NUM_SOLVER_OPTIONS];
  const char *help;
  int client_server, popup_messages, merge_views;
  int pid;
  GmshServer *server;
} SolverInfo ;

extern SolverInfo SINFO[MAX_NUM_SOLVERS];

int Solver(int num, const char *args);

#endif

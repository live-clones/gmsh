// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SOLVERS_H_
#define _SOLVERS_H_

#include <string>
#include <vector>

#define MAX_NUM_SOLVERS 5
#define MAX_NUM_SOLVER_OPTIONS 5

class GmshServer;

typedef struct{
  std::string name, input_name, extension, executable_name;
  std::string mesh_name, mesh_command;
  std::string socket_command;
  std::string name_command;
  std::string button_name[MAX_NUM_SOLVER_OPTIONS];
  std::string button_command[MAX_NUM_SOLVER_OPTIONS];
  std::string option_name[MAX_NUM_SOLVER_OPTIONS], option_command;
  std::vector<std::string> option[MAX_NUM_SOLVER_OPTIONS];
  int  nboptions;
  std::string help;
  int client_server, popup_messages, merge_views;
  int pid;
  GmshServer *server;
} SolverInfo ;

extern SolverInfo SINFO[MAX_NUM_SOLVERS + 1];

std::string GetSocketName(int num);
int Solver(int num, const char *args);

#endif

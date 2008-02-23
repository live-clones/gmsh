#ifndef _SOLVERS_H_
#define _SOLVERS_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#define MAXSOLVERS 5

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
} SolverInfo ;

extern SolverInfo SINFO[MAXSOLVERS] ;

int Solver(int num, const char *args);

#endif

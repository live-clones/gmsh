/* $Id: mysolver.c,v 1.5 2003-01-23 20:19:26 geuzaine Exp $ */
/*
  Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
 
  Please report all bugs and problems to "gmsh@geuz.org".
*/

/* This file contains a dummy client solver for Gmsh. It does not
   solve anything, but shows how to program your own solver to interact
   with the Gmsh solver module.
   
   To compile this solver, type something like:

   gcc -o mysolver.exe mysolver.c GmshClient.c
   
   To test this solver, copy the mysolver.opt file into your default
   Gmsh option file, or lauch Gmsh with the command:
   
   gmsh -option mysolver.opt */

/* We start by including some standard headers. Under Windows, you
   will need to install the cygwin tools (http://www.cygwin.com) to
   compile this example (as well as your own solver), since the Gmsh
   solver interface uses Unix sockets. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

/* Now we include the Gmsh client interface definitions. At the time
   of this writing, the client interface contains only three
   functions: Gmsh_Connect, Gmsh_SendString and Gmsh_Disconnect. This
   example shows how to use these functions in order to program some
   simple interactions between a solver and Gmsh. */

#include "GmshClient.h"

/* The following typedef defines the two actions of our dummy solver:
   either output some valid option strings, or run a dummy computation
   and output a post-processing map. */

typedef enum{options,run} action;

/* Let's now define some fake CPU intensive functions: */

long worktime(){
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

void work(){
  long t1 = worktime();
  while(1){
    if(worktime() - t1 > 1.e5) break;
  }
}

/* And here we go with the main routine of the solver: */

int main(int argc, char *argv[]){
  action what;
  int i=0, s;
  char *name=NULL, *option=NULL, *socket=NULL, tmp[256];
  FILE *file;

  /* 1. Loop through the command line arguments, remember the action
     the solver has to perform (what) and store the socket name, the
     option name and the problem name. */

  while(i<argc) {
    if(argv[i][0] == '-') {
      if(!strcmp(argv[i]+1, "socket")){
	i++;
	if(argv[i]) socket = argv[i++];
      }
      else if(!strcmp(argv[i]+1, "options")){
	i++;
	what = options;
      }
      else if(!strcmp(argv[i]+1, "run")){
	i++;
	what = run;
	if(argv[i]) option = argv[i++];
      }
    }
    else
      name = argv[i++];
  }

  /* 2. If the '-socket' option was not given, we cannot connect to Gmsh... */

  if(!socket){
    printf("No socket specified: running non-interactively...\n");
    exit(1);
  }

  /* 3. Try to connect to the socket given by the '-socket' command
     line option: */

  s = Gmsh_Connect(socket) ;
  switch(s){

    /* 3.1. If the socket is <0, issue an error... */

  case -1 :
    printf("Couldn't create socket %s\n", socket);
    break;
  case -2 :
    printf("Couldn't connect to socket %s\n", socket);
    break;
  default :
    
    /* 3.2. ...otherwise, send the GMSH_CLIENT_START command (together
       with the process ID of the solver), check if a problem name was
       specified, and decide what to do according to the 'what'
       variable: */
    
    sprintf(tmp, "%d", getpid());
    Gmsh_SendString(s, GMSH_CLIENT_START, tmp);
    if(!name){
      Gmsh_SendString(s, GMSH_CLIENT_ERROR, "Missing file name");
      Gmsh_Disconnect(s);
      exit(1);
    }
    switch(what){
      
      /* 3.2.1. If what==options, the solver sends the valid options
         (here for the first option): */
      
    case options :
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val1");
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val2");
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val3");
      break;
      
      /* 3.2.2. If what==run, the solver runs the chosen option,
         updates the progress message, issues some information data,
         produces a post-processing map and asks Gmsh to merge it: */

    case run :
      sprintf(tmp, "Running %s with option %s...", name, option);
      Gmsh_SendString(s, GMSH_CLIENT_INFO, tmp);
      for(i=0 ; i<100 ; i++){
	sprintf(tmp, "%d %% complete", i);
	Gmsh_SendString(s, GMSH_CLIENT_PROGRESS, tmp);
	work();
      }
      sprintf(tmp, "Done with %s!", name);
      Gmsh_SendString(s, GMSH_CLIENT_INFO, tmp); 
      file = fopen ("mysolver.pos", "wb");
      if (!file){
	Gmsh_SendString(s, GMSH_CLIENT_ERROR, "Unable to open output file");
      }
      else{
	fprintf(file, "View \"%s\"{\n", option);
	fprintf(file, "ST(0,0,0,1,0,0,0,1,0){0,1,2};\n");
	fprintf(file, "};\n");
	fclose(file);
	Gmsh_SendString(s, GMSH_CLIENT_VIEW, "mysolver.pos");
      }
      break;
    }
    
    /* 3.3. We can now disconnect the solver from Gmsh: */

    Gmsh_SendString(s, GMSH_CLIENT_STOP, "Goodbye!");
    Gmsh_Disconnect(s);
    break;
  }


  /* 4. That's it! */

}

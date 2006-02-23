/* $Id: solver.c,v 1.3 2006-02-23 21:59:08 geuzaine Exp $ */
/*
 * Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
 * ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 * 
 *  Please report all bugs and problems to <gmsh@geuz.org>.
 */

/* This file contains a dummy client solver for Gmsh. It does not
   solve anything, but shows how to program your own solver to interact
   with the Gmsh solver module.
   
   To compile this solver, type something like:

   gcc -o solver.exe solver.c GmshClient.c
   
   To run it, merge the contents of the file solver.opt into your
   default Gmsh option file, or launch Gmsh with the command:
   
   gmsh -option solver.opt 

   You will then see a new button labeled "My C solver" in Gmsh's
   solver menu.
*/

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

typedef enum { options, run } action;

/* Let's now define some fake CPU intensive functions: */

long worktime()
{
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  return (long)tp.tv_sec * 1000000 + (long)tp.tv_usec;
}

void work()
{
  long t1 = worktime();
  while(1) {
    if(worktime() - t1 > 1.e5)
      break;
  }
}

/* And here we go with the main routine of the solver: */

int main(int argc, char *argv[])
{
  action what = run;
  int i = 0, s;
  char *name = NULL, *option = NULL, *socket = NULL, tmp[256];
  FILE *file;

  /* 1. Loop through the command line arguments, remember the action
     the solver has to perform (what) and store the socket name, the
     option name and the problem name. */

  while(i < argc) {
    if(argv[i][0] == '-') {
      if(!strcmp(argv[i] + 1, "socket")) {
        i++;
        if(argv[i])
          socket = argv[i++];
      }
      else if(!strcmp(argv[i] + 1, "options")) {
        i++;
        what = options;
      }
      else if(!strcmp(argv[i] + 1, "run")) {
        i++;
        what = run;
        if(argv[i])
          option = argv[i++];
      }
    }
    else
      name = argv[i++];
  }

  /* 2. If the '-socket' option was not given, we cannot connect to
        Gmsh... */

  if(!socket) {
    printf("No socket specified: running non-interactively...\n");
    exit(1);
  }

  /* 3. Try to connect to the socket given by the '-socket' command
     line option: */

  s = Gmsh_Connect(socket);
  switch (s) {

    /* 3.1. If the socket is <0, issue an error... */

  case -1:
    printf("Couldn't create socket %s\n", socket);
    break;
  case -2:
    printf("Couldn't connect to socket %s\n", socket);
    break;
  default:

    /* 3.2. ...otherwise, send the GMSH_CLIENT_START command (together
       with the process ID of the solver), check if a problem name was
       specified, and decide what to do according to the 'what'
       variable: */

    sprintf(tmp, "%d", getpid());
    Gmsh_SendString(s, GMSH_CLIENT_START, tmp);
    if(!name) {
      Gmsh_SendString(s, GMSH_CLIENT_ERROR, "Missing file name");
      Gmsh_Disconnect(s);
      exit(1);
    }
    switch (what) {

      /* 3.2.1. If what==options, the solver sends the valid options
         (here for the first option): */

    case options:
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val1");
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val2");
      Gmsh_SendString(s, GMSH_CLIENT_OPTION_1, "Val3");
      break;

      /* 3.2.2. If what==run, the solver runs the chosen option,
         updates the progress message, issues some information data,
         produces a post-processing map and asks Gmsh to merge it: */

    case run:
      sprintf(tmp, "Running %s with option %s...", name, option);
      Gmsh_SendString(s, GMSH_CLIENT_INFO, tmp);
      for(i = 0; i < 10; i++) {
        sprintf(tmp, "%d %% complete", 10*i);
        Gmsh_SendString(s, GMSH_CLIENT_PROGRESS, tmp);
        work();
      }
      sprintf(tmp, "Done with %s!", name);
      Gmsh_SendString(s, GMSH_CLIENT_INFO, tmp);
      file = fopen("solver.pos", "wb");
      if(!file) {
        Gmsh_SendString(s, GMSH_CLIENT_ERROR, "Unable to open output file");
      }
      else {
        fprintf(file, "View \"%s\"{\n", option);
	fprintf(file, "ST(0,0,0,1,0,0,0,1,0){0,1,2};\n");
        fprintf(file, "};\n");
        fclose(file);
        Gmsh_SendString(s, GMSH_CLIENT_MERGE_FILE, "solver.pos");
      }
      break;
    }

    /* 3.3. We can now disconnect the solver from Gmsh: */

    Gmsh_SendString(s, GMSH_CLIENT_STOP, "Goodbye!");
    Gmsh_Disconnect(s);
    break;
  }

  /* 4. That's it! */
  return 0;
}

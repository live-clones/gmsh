// $Id: solver.cpp,v 1.8 2006-02-24 22:07:08 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

// This file contains a dummy client solver for Gmsh. It does not
// solve anything, but shows how to program your own solver to interact
// with the Gmsh solver module.
//
// To compile this solver, type something like:
//
// g++ solver.cpp -o solver.exe
//
// To run it, merge the contents of the file solver.opt into your
// default Gmsh option file, or launch Gmsh with the command:
//
// gmsh -option solver.opt 
//
// You will then see a new button labeled "My C++ solver" in Gmsh's
// solver menu.

#include <math.h>
#include "GmshClient.h"

typedef enum { send_options, run_code } action;

int main(int argc, char *argv[])
{
  action what_to_do = run_code;
  char *name = NULL, *option = NULL, *socket = NULL;

  // parse command line

  int i = 0;
  while(i < argc) {
    if(argv[i][0] == '-') {
      if(!strcmp(argv[i] + 1, "socket")) {
        i++; 
	if(argv[i]) socket = argv[i++];
      }
      else if(!strcmp(argv[i] + 1, "options")) {
        i++;
        what_to_do = send_options;
      }
      else if(!strcmp(argv[i] + 1, "run")) {
        i++;
        what_to_do = run_code;
        if(argv[i]) option = argv[i++];
      }
    }
    else
      name = argv[i++];
  }

  if(!socket) {
    printf("No socket specified: running non-interactively...\n");
    exit(1);
  }

  // connect to Gmsh

  GmshClient client;
  if(client.Connect(socket) < 0){
    printf("Unable to connect to Gmsh\n");
    exit(1);
  }

  client.Start();

  if(what_to_do == send_options) {
    // send the available options for this computation
    client.Option(1, "FormulationH");
    client.Option(1, "ConvTest");
    client.Option(1, "Blablabli");
  }
  else if(what_to_do == run_code){
    // do the computation and merge some views
    for(int i = 0; i < 10; i++){
      client.Info("Computing curve...");
      // fake computation...
#if !defined(WIN32) || defined(__CYGWIN__)
      usleep(500);
#else
      Sleep(500);
#endif
      client.Info("Done computing curve");
      FILE *file = fopen("solver.pos", "w");
      if(!file)
	client.Error("Unable to open output file");
      else {
	fprintf(file, "View.Type = 2;\n");
	fprintf(file, "View.Axes = 3;\n");
	fprintf(file, "Delete View[0];\n");
	fprintf(file, "View \"%s\"{\n", option);
	for(int j = 0; j < 100; j++)
	  fprintf(file, "SP(%d,0,0){%g};\n", j,sin(j*i*M_PI/10.));
	fprintf(file, "};\n");
	fclose(file);
	client.MergeFile("solver.pos");
      }
    }
    client.Info("Done!");
  }

  client.Stop();
  client.Disconnect();
}

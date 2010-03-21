// This is a dummy C++ client solver for Gmsh: it does not solve
// anything, but shows how to program your own solver to interact with
// the Gmsh solver module.
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
#include "GmshSocket.h"

typedef enum { send_options, run_code } action;

int main(int argc, char *argv[])
{
  action what_to_do = run_code;
  char *name = 0, *option = 0, *socket = 0;

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
      // fake computation for 500ms:
#if !defined(WIN32) || defined(__CYGWIN__)
      usleep(500 * 1000);
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

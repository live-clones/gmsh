
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
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
    printf("Unable to connect to server\n");
    exit(1);
  }
  else{
    client.Start(getpid());
    if(what_to_do == send_options) {
      // send the available options for this computation
      client.Option(1, "FormulationH");
      client.Option(1, "\"Convergence Test\"");
      client.Option(1, "\"Blabla blblablabli\"");
    }
    else if(what_to_do == run_code){
      // do the computation and merge some views
      for(int i = 0; i < 10; i++){
	client.Info("Computing curve...");
	sleep(1);
	client.Info("Done computing curve");
	FILE *file = fopen("andre.pos", "w");
	if(!file)
	  client.Error("Unable to open output file");
	else {
	  fprintf(file, "General.GraphicsWidth = 500;\n");
	  fprintf(file, "General.GraphicsHeight = 450;\n");
	  fprintf(file, "General.SmallAxes = 0;\n");
	  fprintf(file, "View.Type = 2;\n");
	  fprintf(file, "View.AutoPosition = 0;\n");
	  fprintf(file, "View.PositionX = 100;\n");
	  fprintf(file, "View.PositionY = 50;\n");
	  fprintf(file, "View.Width = 350;\n");
	  fprintf(file, "View.Height = 350;\n");
	  fprintf(file, "Delete View[0];\n");
	  fprintf(file, "View \"test\"{\n");
	  for(int j = 0; j < 100; j++)
	    fprintf(file, "SP(%d,0,0){%g};\n", j,sin(j*i*M_PI/10.));
	  fprintf(file, "};\n");
	  fclose(file);
	  client.View("andre.pos");
	}
      }
      client.Info("Done!");
    }

    client.Stop();
    client.Disconnect();
  }
}

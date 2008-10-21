#include "GmshSocket.h"
#include <readline/readline.h>
#include <readline/history.h>

// compile with: g++ interactive.cpp -lreadline -ltermcap

class GmshInteractiveClient{
 private:
  GmshClient _client;
 public:
  GmshInteractiveClient(char *socket)
  {
    using_history();
    if(_client.Connect(socket) < 0) {
      printf("Unable to connect to Gmsh\n");
      exit(1);
    }
    _client.Start();
  }
  ~GmshInteractiveClient()
  {
    _client.Stop();
    _client.Disconnect();
  }
  void read(char *prompt)
  {
    // pre-load a few commands in the history:
    add_history("lc = 1.;");
    add_history("Point(1) = {0,0,0,lc};");
    add_history("Point(2) = {5,0,0,lc};");
    add_history("Line(1) = {1,2};");
    add_history("argh");
    
    while (1) {
      // read input char until CR, LF, EOF or ^D
      char *ptr = readline(prompt);
      // exit interactive if EOF or ^D
      if(!ptr) break;
      // if the command line is not empty
      if(strlen(ptr)){
	// add the command in the stack
	add_history(ptr);
	if(!strcmp(ptr, "q") || !strcmp(ptr, "quit")){
	  // exit interactive if q or quit
	  free(ptr);
	  break;
	}
	else if(ptr[0] == '!'){
	  // direct system calls
	  system(&ptr[1]);
	}
	else if(!strcmp(ptr, "argh")){
	  // test speed of string sending with a 1Mb view
	  char *dat = new char[1200000];
	  strcpy(dat, "View \"test\" {\n");
	  int n = strlen(dat);
	  for(int i = 0; i < 100; i++){
	    for(int j = 0; j < 200; j++){
	      n += sprintf(&dat[n], "SQ(%d,%d,0,%d,%d,0,%d,%d,0,%d,%d,0){%d,%d,%d,%d};\n",
			   i, j, i+1, j, i+1, j+1, i, j+1, i, i+1, j, j+1);
	    }
	  }
	  strcat(dat, "};");
	  printf("n=%d\n", n);
	  _client.ParseString(dat);
	  delete [] dat;
	}
	else{
	  // pass any other command to gmsh
	  _client.ParseString(ptr);
	}
      }
      free(ptr);
    }
  }
};

int main(int argc, char **argv) 
{
  if(argc < 2){
    printf("usage: %s socket\n", argv[0]);
    exit(1);
  }

  GmshInteractiveClient c(argv[1]);
  c.read("gmsh> ");

  return 0;
}

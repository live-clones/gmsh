#include "GmshClient.h"
#include <readline/readline.h>
#include <readline/history.h>

// compile with: g++ interactive.cpp -lreadline

class GmshInteractiveClient{
 private:
  GmshClient _client;
 public:
  GmshInteractiveClient()
  {
    using_history();
    char socket[256];
    sprintf(socket, "%s/.gmshsock", getenv("HOME"));
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
    // preload a few commands in the history:
    add_history("lc = 1.;");
    add_history("Point(1) = {0,0,0,lc};");
    add_history("Point(2) = {5,0,0,lc};");
    add_history("Line(1) = {1,2};");
    
    while (1) {
      // read input char until CR, LF, EOF, ^D
      char *ptr = readline(prompt);
      // exit interactive if EOF or ^D
      if(!ptr) break;
      // if there is something in the line
      if(strlen(ptr)){
	// add the command in the stack
	add_history(ptr);
	if(!strcmp(ptr,"q") || !strcmp(ptr, "quit")){
	  // exit interactive if q, quit, exit
	  free(ptr);
	  break;
	}
	else if(!strcmp(ptr, "dir") || !strcmp(ptr, "ls")){
	  // direct system calls
	  system("ls -al");
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

int main() 
{
  GmshInteractiveClient c;
  c.read("gmsh> ");

  return 0;
}

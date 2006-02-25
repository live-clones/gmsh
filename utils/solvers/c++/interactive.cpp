#include "GmshClient.h"
#include <readline/readline.h>
#include <readline/history.h>

// compile with: g++ interactive.cpp -lreadline -ltermcap

class GmshInteractiveClient{
 private:
  GmshClient _client;
 public:
  GmshInteractiveClient()
  {
    using_history();
    char socket[256];
#if !defined(WIN32) || defined(__CYGWIN__)
    sprintf(socket, "%s/.gmshsock", getenv("HOME"));
#else
    sprintf(socket, "127.0.0.1:44122");
#endif
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
    add_history("argh");
    
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

int main() 
{
  GmshInteractiveClient c;
  c.read("gmsh> ");

  return 0;
}

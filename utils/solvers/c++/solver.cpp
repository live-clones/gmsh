#include <iostream>
#include <vector>
#include <string>
#include "onelab.h"

// 1) Compile this solver: g++ solver.cpp
//
// 2) Add it to Gmsh:
//   - launch Gmsh and open Tools->OneLab
//   - In the gear menu, select "Add new client"
//   - Enter "My Solver" as client name, then choose the exe in the dialog

int main(int argc, char **argv)
{
  onelab::remoteNetworkClient *client = 0;

  for(int i = 0; i < argc; i++){
    if(std::string(argv[i]) == "-onelab" && i + 2 < argc){
      client = new onelab::remoteNetworkClient(argv[i + 1], argv[i + 2]);
      break;
    }
  }

  if(!client){
    printf("usage: %s -onelab name socket\n", argv[0]);
    exit(1);
  }

  std::vector<onelab::string> strings;

  // try to get the string variable "My solver/My string" from the server
  client->get(strings, "My string");
  if(strings.size()){
    std::cout << "Got string from server: '" << strings[0].getValue() << "'\n";
  }
  else{
    // send a value to the server
    onelab::string s("My string", "Hello!");
    client->set(s);
  }

  delete client;

  return 0;
}

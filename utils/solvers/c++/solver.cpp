#include <iostream>
#include <vector>
#include <string>
#include "onelab.h"

int main(int argc, char **argv) 
{
  onelab::remoteNetworkClient *client = 0;

  for(int i = 0; i < argc; i++){
    if(std::string(argv[i]) == "-onelab" && i < argc - 1)
      client = new onelab::remoteNetworkClient("My solver", argv[i + 1]);
  }

  if(!client){
    printf("usage: %s -onelab socket\n", argv[0]);
    exit(1);
  }

  std::vector<onelab::string> strings;

  // try to get the string variable "My solver/My string" from the server
  client->get(strings, "My solver/My string");
  if(strings.size()){
    std::cout << "Got string from server: '" << strings[0].getValue() << "'\n";
  }
  else{
    // send a value to the server
    onelab::string s("My solver/My string", "Hello!");
    client->set(s);
  }

  delete client;

  return 0;
}

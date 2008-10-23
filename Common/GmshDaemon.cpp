// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "Message.h"
#include "OS.h"
#include "GmshSocket.h"

int GmshDaemon(std::string socket)
{
  GmshClient client;

  if(client.Connect(socket.c_str()) < 0){
    Msg::Error("Unable to connect to server on %s", socket.c_str());
    return 1;
  }
  client.Start();
  
  int i = 0;
  while(1){
    if(!client.Select(0, 1000)){
      // data is available to read: deal with it
      int type, length;
      if(client.ReceiveHeader(&type, &length)){
        printf("received header: %d %d\n", type, length);
        char *msg = new char[length];
        if(client.ReceiveString(length, msg)){
          printf("received string: %s\n", msg);
        }
        delete [] msg;

        printf("stopping connection!\n");
        break;
      }
    }
  }

  client.Stop();
  client.Disconnect();

  return 0;
}

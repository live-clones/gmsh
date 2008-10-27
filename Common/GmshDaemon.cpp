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
  
  while(1){
    // wait (at most 10ms) until data is available to read
    if(!client.Select(0, 10000)){
      int type, length;
      if(client.ReceiveHeader(&type, &length)){
        Msg::Info("Received header: type=%d length=%d", type, length);
        char *msg = new char[length];
        if(client.ReceiveString(length, msg)){
          Msg::Info("received string: %s", msg);
          Msg::Info("replying by sending post data");
          std::ostringstream tmp;
          tmp<<"View \"test\" {\n";
          for(int i= 0; i < 100; i++){
            for(int j= 0; j < 100; j++){
              tmp << "SQ("<<i<<","<<j<<",0, "<<i+1<<","<<j<<",0, "
                  <<i+1<<","<<j+1<<",0, "<<i<<","<<j+1<<",0){"
                  <<i+j<<","<<i+j<<","<<i+j<<","<<i+j<<"};\n";
            }
          }
          tmp<<"};BoundingBox;\n";
          client.ParseString(tmp.str().c_str());
        }
        delete [] msg;
        //printf("stopping connection!\n");
        //break;
      }
    }
  }

  client.Stop();
  client.Disconnect();

  return 0;
}

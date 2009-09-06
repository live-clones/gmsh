// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshMessage.h"
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
  client.Info("Server sucessfully started. Listening...");

  // read large data file,
  // initialize mpi job,
  // then wait for commands to execute:
  while(1){
    // wait at most 1 second for data
    if(!client.Select(1, 0)){
      int type, length;
      if(client.ReceiveHeader(&type, &length)){
        char *msg = new char[length + 1];
        if(client.ReceiveString(length, msg)){
          std::ostringstream tmp;
          tmp << "Hello! I've received msg type=" << type << " len=" << length
              << " str=" << msg;
          client.Info(tmp.str().c_str());
          if(type == GmshSocket::GMSH_STOP){
            client.Info("Stopping connection!");
            delete [] msg;
            break;
          }
          else{
            std::ostringstream v;
            v << "View \"test\" {\n";
            for(int i= 0; i < 100; i++){
              for(int j= 0; j < 100; j++){
                v << "SQ("<<i<<","<<j<<",0, "<<i+1<<","<<j<<",0, "
                  <<i+1<<","<<j+1<<",0, "<<i<<","<<j+1<<",0){"
                  <<i+j<<","<<i+j<<","<<i+j<<","<<i+j<<"};\n";
              }
            }
            v << "};BoundingBox;\n";
            client.ParseString(v.str().c_str());
          }
        }
        delete [] msg;
      }
    }
    else{
      // ping the server so we automatically crash of it goes down :-)
      printf("printf ping!\n");
      client.Info("Ping!");
    }
  }

  client.Stop();
  client.Disconnect();

  return 0;
}

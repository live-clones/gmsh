// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshMessage.h"
#include "OS.h"
#include "GmshSocket.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "VertexArray.h"

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
  bool stop = false;
  while(1){
    if(stop) break;
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
          switch(type){
          case GmshSocket::GMSH_STOP:
            {
              client.Info("Stopping connection!");
              stop = true;
            }
            break;
          case GmshSocket::GMSH_VERTEX_ARRAY:
            {
              // create and send a vertex array
              if(PView::list.size()){
                PView *view = PView::list[0];
                view->getOptions()->intervalsType = PViewOptions::Iso;
                view->fillVertexArrays();
                PViewData *data = view->getData();
                
                int len;
                char *ss = view->va_triangles->toChar
                  (view->getNum(), 3, data->getMin(), data->getMax(), 
                   data->getTime(0), data->getBoundingBox(), len);
                client.SendMessage(GmshSocket::GMSH_VERTEX_ARRAY, len, ss);
                delete [] ss;
              }
            }
            break;
          case GmshSocket::GMSH_SPEED_TEST:
            {
              std::string huge(500000000, 'a');
              client.SpeedTest(huge.c_str());
            }
            break;
          case GmshSocket::GMSH_PARSE_STRING:
            {
              std::ostringstream v;
              v << "View \"test\" {\n";
              for(int i = 0; i < 200; i++){
                for(int j = 0; j < 200; j++){
                  v << "SQ("<<i<<","<<j<<",0, "<<i+1<<","<<j<<",0, "
                    <<i+1<<","<<j+1<<",0, "<<i<<","<<j+1<<",0){"
                    <<i+j<<","<<i+j<<","<<i+j<<","<<i+j<<"};\n";
                }
              }
              v << "};BoundingBox;\n";
              client.ParseString(v.str().c_str());
            }
            break;
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

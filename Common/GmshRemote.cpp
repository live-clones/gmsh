// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshMessage.h"
#include "GmshSocket.h"
#include "OpenFile.h"
#include "OS.h"
#include "VertexArray.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#endif

static void computeAndSendVertexArrays(GmshClient *client)
{
#if defined(HAVE_POST)
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PView *p = PView::list[i];
    p->fillVertexArrays();
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();
    double min = data->getMin(), max = data->getMax();
    if(opt->rangeType == PViewOptions::PerTimeStep){
      min = data->getMin(opt->timeStep);
      max = data->getMax(opt->timeStep);
    }
    VertexArray *va[4] = 
      {p->va_points, p->va_lines, p->va_triangles, p->va_vectors};
    for(int type = 0; type < 4; type++){
      if(va[type]){
        int len;
        char *str = va[type]->toChar
          (p->getNum(), data->getName(), type + 1, min, max, 
           data->getNumTimeSteps(), data->getTime(opt->timeStep),
           data->getBoundingBox(), len);
        client->SendMessage(GmshSocket::GMSH_VERTEX_ARRAY, len, str);
        delete [] str;
      }
    }
  }
#endif
}

int GmshRemote()
{
  GmshClient *client = Msg::GetClient();
  
  if(!client) return 0;

  computeAndSendVertexArrays(client);

  while(1){
    // stop if we have no communications for 5 minutes
    int ret = client->Select(300, 0);
    if(!ret){
      client->Info("Timout: stopping remote Gmsh...");
      break;
    }
    else if(ret < 0){
      client->Error("Error on select: stopping remote Gmsh...");
      break;
    }

    int type, length, swap;
    if(!client->ReceiveHeader(&type, &length, &swap)){
      client->Error("Did not receive message header: stopping remote Gmsh...");
      break;
    }
      
    char *msg = new char[length + 1];
    if(!client->ReceiveString(length, msg)){
      client->Error("Did not receive message body: stopping remote Gmsh...");
      delete [] msg;
      break;
    }

    if(type == GmshSocket::GMSH_STOP){
      client->Info("Stopping remote Gmsh...");
      break;
    }
    else if(type == GmshSocket::GMSH_VERTEX_ARRAY){
      ParseString(msg);
      computeAndSendVertexArrays(client);
    }
    else if(type == GmshSocket::GMSH_MERGE_FILE){
      MergeFile(msg);
      computeAndSendVertexArrays(client);
    }
    else if(type == GmshSocket::GMSH_PARSE_STRING){
      ParseString(msg);
    }
    else if(type == GmshSocket::GMSH_SPEED_TEST){
      client->Info("Sending huge array");
      std::string huge(500000000, 'a');
      client->SpeedTest(huge.c_str());
    }
    else{
      client->Error("Ignoring unknown message");
    }
    
    delete [] msg;
  }

  return 0;
}

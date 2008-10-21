// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Message.h"
#include "GmshSocket.h"

int GmshDaemon(std::string socket)
{
  Msg::Info("Gmsh daemon running on socket %s", socket.c_str());
  while(1){
    ;
  }
  return 0;
}

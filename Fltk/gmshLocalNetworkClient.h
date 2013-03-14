// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GMSH_LOCAL_NETWORK_CLIENT_H_
#define _GMSH_LOCAL_NETWORK_CLIENT_H_

#include <vector>
#include <algorithm>
#include "onelab.h"

class gmshLocalNetworkClient : public onelab::localNetworkClient{
 private:
  std::vector<onelab::localNetworkClient*> _clients;
 public:
  gmshLocalNetworkClient(const std::string &name, const std::string &executable,
                         const std::string &remoteLogin="")
    : onelab::localNetworkClient(name, executable, remoteLogin)
  {
    addClient(this);
  }
  void addClient(onelab::localNetworkClient *client)
  {
    _clients.push_back(client);
  }
  void removeClient(onelab::localNetworkClient *client)
  {
    std::vector<onelab::localNetworkClient*>::iterator it;
    it = std::find(_clients.begin(), _clients.end(), client);
    if(it != _clients.end()) _clients.erase(it);
  }
  int getNumClients(){ return _clients.size(); }
  onelab::localNetworkClient *getClient(int i)
  {
    if(i >= 0 && i < getNumClients()) return _clients[i];
    return 0;
  }
  bool receiveMessage();
  bool run();
  bool kill();
};

#endif

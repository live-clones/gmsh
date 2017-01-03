// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_LOCAL_NETWORK_CLIENT_H_
#define _GMSH_LOCAL_NETWORK_CLIENT_H_

#include <vector>
#include <algorithm>
#include "GmshConfig.h"

#if defined(HAVE_ONELAB)

#include "onelab.h"

class gmshLocalNetworkClient : public onelab::localNetworkClient{
 private:
  // a gmsh local network client can launch subclients (this is typical for a
  // metamodel that calls several underlying models); _clients keeps track of
  // the master (this) and the subclients.
  std::vector<gmshLocalNetworkClient*> _clients;
  // client that launched this one (with GMSH_CONNECT); _father is zero for the
  // master client (the one created by Gmsh).
  gmshLocalNetworkClient *_father;
 public:
  gmshLocalNetworkClient(const std::string &name, const std::string &executable,
                         const std::string &remoteLogin="",
                         bool treatExecutableAsFullCommandLine=false)
    : onelab::localNetworkClient(name, executable, remoteLogin,
                                 treatExecutableAsFullCommandLine), _father(0)
  {
    addClient(this);
  }
  void setFather(gmshLocalNetworkClient *father)
  {
    _father = father;
  }
  gmshLocalNetworkClient *getFather()
  {
    return _father;
  }
  void addClient(gmshLocalNetworkClient *client)
  {
    _clients.push_back(client);
  }
  void removeClient(gmshLocalNetworkClient *client)
  {
    std::vector<gmshLocalNetworkClient*>::iterator it;
    it = std::find(_clients.begin(), _clients.end(), client);
    if(it != _clients.end()) _clients.erase(it);
  }
  int getNumClients(){ return _clients.size(); }
  gmshLocalNetworkClient *getClient(int i)
  {
    if(i >= 0 && i < getNumClients()) return _clients[i];
    return 0;
  }
  int getNumConnectedClients()
  {
    int n = 0;
    for(int i = 0; i < getNumClients(); i++){
      if(_clients[i]->getPid() != -1) n++;
    }
    return n;
  }
  bool receiveMessage(gmshLocalNetworkClient *master);
  bool run();
  bool kill();
};

// FIXME: move this to onelabUtils
void initializeLoops();
bool incrementLoops();
void updateGraphs();
std::string timeStamp();
void saveDb(const std::string &fileName);
void archiveOutputFiles(const std::string &fileName);
void archiveSolutionFiles(const std::string &fileName);
void loadDb(const std::string &name);
void resetDb(bool runGmshClient);
void solver_batch_cb(void *data);

#endif

#endif

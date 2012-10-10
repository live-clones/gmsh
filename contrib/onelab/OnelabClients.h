// ONELAB - Copyright (C) 2010-2012 C. Geuzaine, F. Henrotte
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ONELAB_CLIENTS_H_
#define _ONELAB_CLIENTS_H_

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>

#include "OS.h"
#include "onelab.h"
#include "OnelabMessage.h"

// Onelab file extension
static std::string onelabExtension(".ol");
// Possible actions for clients
enum parseMode {INITIALIZE, REGISTER, ANALYZE, COMPUTE, EXIT, STOP};

static char charSep() { return '\0'; }
#if defined(WIN32)
static std::string dirSep("\\");
static std::string cmdSep(" & ");
#else
static std::string dirSep("/");
static std::string cmdSep(" ; ");
#endif

// TOOLS 
int getOptions(int argc, char *argv[], parseMode &todo, std::string &commandLine, std::string &caseName, std::string &clientName, std::string &sockName);
std::string itoa(const int i);
std::string ftoa(const double x);
bool checkIfPresent(std::string fileName);
int mySystem(std::string commandLine);
std::string getCurrentWorkdir();
std::string getUserHomedir();
std::string sanitize(const std::string &in);
std::string removeBlanks(const std::string &in);
bool isPath(const std::string &in);

// Parser TOOLS 
int enclosed(const std::string &in, std::vector<std::string> &arguments);
int extract(const std::string &in, std::string &paramName, std::string &action, std::vector<std::string> &arguments);
bool extractRange(const std::string &in, std::vector<double> &arguments);
std::string extractExpandPattern(const std::string& str);


typedef std::vector <std::vector <double> > array;
array read_array(std::string fileName, char sep);
double find_in_array(int i, int j, const std::vector <std::vector <double> > &data);
std::vector<double> extract_column(const int j, array data);

static std::string getShortName(const std::string &name) {
  std::string s = name;
  // remove path
  std::string::size_type last = name.find_last_of('/');
  if(last != std::string::npos)
    s = name.substr(last + 1);
  // remove starting numbers
  while(s.size() && s[0] >= '0' && s[0] <= '9')
    s = s.substr(1);
  return s;
}

class ShortNameLessThan{
 public:
  bool operator()(const std::string p1, const std::string p2) const
  {
    return getShortName(p1) < getShortName(p2);
  }
};

/*
VIRTUAL and BASE CLASSES

"localSolverClient" is the base class 
for all onelab clients called from a metamodel.
It inherits from the "LocalClient" class of "onelab.h" 
and has the additional metamodel specific functions: 
analyze(), compute(), checkIfPresent(), checkCommandLine(),
inputFile(), outputFile()

The subclass "localSolverNetworkClient" of "localSolverClient"
is for native clients (Gmsh and getDP so far)
that communicate with the server through sockets. 
It has a GmshServer member,
uses localNetworkSolverClient::run instead of onelab::client::run().

Both "localSolverNetworkClient" and "localSolverClient" are pure virtual.

The combination of two alternatives native/interfaced and local/remote
yields 4 clients: 
InterfacedClient, RemoteInterfacesClient
NativeClient, RemoteINterfacedClient

The base class "remoteClient" is a base class 
for clients running on a remote host.
It provides appropriate versions of checkIfPresent() and checkCommandLine().
*/
class localSolverClient : public onelab::localClient{
 private:
  std::string _commandLine;
  std::string _workingDir;
  int _active;
  bool _onelabBlock;
  std::set<std::string, ShortNameLessThan> _parameters;
  std::string longName(const std::string name);
 public:
 localSolverClient(const std::string &name, const std::string &cmdl, 
		   const std::string &wdir) 
   : onelab::localClient(name), _commandLine(cmdl), _workingDir(wdir),
    _active(1), _onelabBlock(false) {
  }
  virtual ~localSolverClient(){}
  const std::string &getCommandLine(){ return _commandLine; }
  const std::string &getWorkingDir() { return _workingDir; }
  virtual void setCommandLine(const std::string &s){ _commandLine = s; }
  virtual void setWorkingDir(const std::string &s){ _workingDir = s; }

  void setAction(const std::string action);
  const std::string getString(const std::string what);
  const bool getList(const std::string type, 
		     std::vector<std::string> &choices);
  const bool isActive() { return (bool)_active; }
  const void setActive(int val) { _active=val; }
  int getActive() { return _active; }
  virtual std::string toChar();

  // parser
  void modify_tags(const std::string lab, const std::string com);
  const bool isOnelabBlock() { return _onelabBlock; }
  const void openOnelabBlock() { _onelabBlock=true; }
  const void closeOnelabBlock() { _onelabBlock=false; }
  std::string resolveGetVal(std::string line);
  bool resolveLogicExpr(std::vector<std::string> arguments);
  void parse_sentence(std::string line) ;
  void parse_oneline(std::string line, std::ifstream &infile) ;
  bool parse_block(std::ifstream &infile) ;
  bool parse_ifstatement(std::ifstream &infile, bool condition) ;
  void parse_onefile(std::string ifileName, bool mandatory=true);
  void convert_oneline(std::string line, std::ifstream &infile, 
		       std::ofstream &outfile);
  bool convert_ifstatement(std::ifstream &infile, 
			   std::ofstream &outfile, bool condition) ;
  void convert_onefile(std::string ifileName, std::ofstream &outfile);
  virtual void client_sentence(const std::string &name, 
			       const std::string &action, 
			       const std::vector<std::string> &arguments);

  // execution
  bool buildRmCommand(std::string &cmd);
  bool checkIfPresentLocal(const std::string &fileName){
    return checkIfPresent(getWorkingDir()+fileName);
  }
  virtual bool checkCommandLine();
  virtual void analyze() =0;
  virtual void compute() =0;
  void addNumberChoice(std::string name, double val);
  void PostArray(std::vector<std::string> choices);
  void GmshMerge(std::vector<std::string> choices);
};

class localNetworkSolverClient : public localSolverClient{
 private:
  // command line option to specify socket
  std::string _socketSwitch;
  // pid of the remote network client
  int _pid;
  // underlying GmshServer
  GmshServer *_gmshServer;
  // flag indicating if the client is a remote one
  bool _remote;
 public:
 localNetworkSolverClient(const std::string &name, const std::string &cmdl, const std::string &wdir)
   : localSolverClient(name,cmdl,wdir), _socketSwitch("-onelab"),
    _pid(-1), _gmshServer(0), _remote(false) {}
  virtual ~localNetworkSolverClient(){}
  virtual bool isNetworkClient(){ return true; }
  const std::string &getSocketSwitch(){ return _socketSwitch; }
  void setSocketSwitch(const std::string &s){ _socketSwitch = s; }
  int getPid(){ return _pid; }
  void setPid(int pid){ _pid = pid; }
  GmshServer *getGmshServer(){ return _gmshServer; }
  void setGmshServer(GmshServer *server){ _gmshServer = server; }
  int getRemote(){ return _remote; }
  void setRemote(bool rem){ _remote = rem; }

  virtual std::string buildCommandLine();
  std::string appendArguments();
  virtual bool run();
  virtual bool kill();

  virtual void analyze() =0;
  virtual void compute() =0;
};

class remoteClient {
 private:
  std::string _remoteHost;
  std::string _remoteDir;
 public:
 remoteClient(const std::string &host, const std::string &rdir) 
   : _remoteHost(host), _remoteDir(rdir) {}
  ~remoteClient(){}

  const std::string &getRemoteHost() const { return _remoteHost; }
  const std::string &getRemoteDir() const { return _remoteDir; }

  bool checkCommandLine(const std::string &commandLine);
  bool checkIfPresentRemote(const std::string &fileName);
  bool syncInputFile(const std::string &wdir, const std::string &fileName);
  bool syncOutputFile(const std::string &wdir, const std::string &fileName);
};

// ONELAB CLIENTS

class MetaModel : public localSolverClient {
 private:
  std::vector<localSolverClient *> _clients;
  parseMode _todo;
 public:
 MetaModel(const std::string &cmdl, const std::string &wdir, const std::string &cname, const std::string &fname) 
   : localSolverClient(cname,cmdl,wdir){
    clientName = cname;
    genericNameFromArgs = fname.size() ? fname : cmdl;
    setWorkingDir(wdir); // wdir from args
    _todo=REGISTER;
    construct();
  }
  ~MetaModel(){}
  typedef std::vector<localSolverClient*>::iterator citer;
  void setTodo(const parseMode x) { _todo=x; }
  parseMode getTodo() { return _todo; }
  bool isTodo(const parseMode x) { return (_todo==x);}
  citer firstClient(){ return _clients.begin(); }
  citer lastClient(){ return _clients.end(); }
  int getNumClients() { return _clients.size(); };

  void registerClient(const std::string &name, const std::string &type, 
		      const std::string &cmdl, const std::string &host, 
		      const std::string &rdir);
  bool checkCommandLines();
  void saveCommandLines(const std::string fileName);
  localSolverClient *findClientByName(std::string name){
    for(unsigned int i=0; i<_clients.size(); i++)
      if(_clients[i]->getName() == name) return _clients[i];
    return 0;
  }

  std::string genericNameFromArgs, clientName;
  void client_sentence(const std::string &name, const std::string &action, 
		       const std::vector<std::string> &arguments);
  std::string toChar(){}
  void PostArray(std::vector<std::string> choices);
  void construct();
  void analyze();
  void compute();
};

class InterfacedClient : public localSolverClient { 
  // n'utilise pas localNetworkSolverClient::run mais client::run()
 public:
 InterfacedClient(const std::string &name, const std::string &cmdl, const std::string &wdir)
   : localSolverClient(name,cmdl,wdir) {}
  ~InterfacedClient(){}

  void analyze();
  void convert();
  virtual void compute();
};

class NativeClient : public localNetworkSolverClient { 
public:
 NativeClient(const std::string &name, const std::string &cmdl, const std::string &wdir) 
   : localNetworkSolverClient(name,cmdl,wdir) {}
  ~NativeClient(){}

  virtual void analyze();
  virtual void compute();
};


class EncapsulatedClient : public localNetworkSolverClient{
 public:
 EncapsulatedClient(const std::string &name, const std::string &cmdl, const std::string &wdir) : localNetworkSolverClient(name,cmdl,wdir) {}
  ~EncapsulatedClient(){}

  std::string buildCommandLine();
  void analyze();
  void convert();
  void compute();
};


class RemoteInterfacedClient : public InterfacedClient, public remoteClient {
public:
 RemoteInterfacedClient(const std::string &name, const std::string &cmdl, const std::string &wdir, const std::string &host, const std::string &rdir) 
   : InterfacedClient(name,cmdl,wdir), remoteClient(host,rdir) {}
  ~RemoteInterfacedClient(){}

  bool checkCommandLine();
  // uses InterfacedClient::analyze()
  void compute() ;
};

class RemoteNativeClient : public NativeClient, public remoteClient {
public:
 RemoteNativeClient(const std::string &name, const std::string &cmdl, const std::string &wdir, const std::string &host, const std::string &rdir) 
   : NativeClient(name,cmdl,wdir), remoteClient(host,rdir) {
    setRemote(true);
  }
  ~RemoteNativeClient(){}

  std::string buildCommandLine();
  bool checkCommandLine();
  void analyze();
  void compute() ;
};

#endif



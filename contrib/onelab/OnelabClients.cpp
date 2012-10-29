#include "OnelabMessage.h"
#include "OnelabClients.h"
#include "StringUtils.h"
#include <algorithm>
#ifdef WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else
#define POPEN popen
#define PCLOSE pclose
#endif

class onelabMetaModelServer : public GmshServer{
 private:
  localNetworkSolverClient *_client;
 public:
  onelabMetaModelServer(localNetworkSolverClient *client)
    : GmshServer(), _client(client) {}
  ~onelabMetaModelServer(){}

  int NonBlockingSystemCall(const char *command)
  {
#if defined(WIN32)
    STARTUPINFO suInfo;
    PROCESS_INFORMATION prInfo;
    memset(&suInfo, 0, sizeof(suInfo));
    suInfo.cb = sizeof(suInfo);
    std::string cmd(command);
    OLMsg::Info("Calling <%s>", cmd.c_str());
    // DETACHED_PROCESS removes the console (useful if the program to launch is
    // a console-mode exe)
    CreateProcess(NULL,(char *)cmd.c_str(), NULL, NULL, FALSE,
		  NORMAL_PRIORITY_CLASS|DETACHED_PROCESS, NULL, NULL,
		  &suInfo, &prInfo);
    return 0;
#else
    if(!system(NULL)) {
      OLMsg::Error("Could not find /bin/sh: aborting system call");
      return 1;
    }
    std::string cmd(command);
    size_t pos;
    if((pos=cmd.find("incomp_ssh ")) != std::string::npos){
      cmd.assign(cmd.substr(pos+7));  // remove "incomp_"
      cmd.append(" & '");
    }
    else
      cmd.append(" & ");

    OLMsg::Info("Calling <%s>", cmd.c_str());
    return system(cmd.c_str());
#endif
  }// non blocking

  int NonBlockingWait(int socket, double waitint, double timeout)
  {
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout)
        return 2; // timeout
      // if(_client->getPid() < 0 || (_client->getCommandLine().empty() &&
      //                              !CTX::instance()->solver.listen))
      if(_client->getPid() < 0 || (_client->getCommandLine().empty()))
        return 1; // process has been killed or we stopped listening
      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);
      if(ret == 0){ // nothing available
        // if asked, refresh the onelab GUI
        // std::vector<onelab::string> ps;
        // onelab::server::instance()->get(ps, "Gmsh/Action");
        // if(ps.size() && ps[0].getValue() == "refresh"){
        //   ps[0].setVisible(false);
        //   ps[0].setValue("");
        //   onelab::server::instance()->set(ps[0]);
        //   onelab_cb(0, (void*)"refresh");
        //}

        // wait at most waitint seconds and respond to FLTK events
	//FlGui::instance()->wait(waitint);
	void (*waitFct)(double) = OLMsg::GetGuiWaitFunction();
	if(waitFct) waitFct(waitint);
      }
      else if(ret > 0){
        return 0; // data is there!
      }
      else{
        // ret<0 an error happened
        _client->setPid(-1);
        _client->setGmshServer(0);
        return 1;
      }
    }
  }
};

std::string localNetworkSolverClient::buildCommandLine(){
  std::string command;
  command.assign("");
  if(!getWorkingDir().empty())
    command.append("cd " + getWorkingDir() + cmdSep);
  command.append(FixExecPath(getCommandLine()));
  return command;
}

std::string localNetworkSolverClient::appendArguments(){

  std::string action = getString("Action");
  std::string checkCommand = getString("9CheckCommand");
  std::string computeCommand = getString("9ComputeCommand");

  std::string command;
  if(action == "initialize"){
    command.assign(" " + getSocketSwitch() + " " + getName() + " %s");
  }
  else if(action == "check") {
    command.assign(" " + getString("Arguments") + " " + checkCommand) ;
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else if(action == "compute"){
    command.assign(" " + getString("Arguments") + " " + computeCommand);
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else
    OLMsg::Error("appendArguments: Unknown Action <%s>", action.c_str());
  return command;
}

bool localNetworkSolverClient::run()
{
 new_connection:
  _pid = 0;
  _gmshServer = 0;

  onelabMetaModelServer *server = new onelabMetaModelServer(this);

#if defined(WIN32)
  std::string socketName = ":";
#else
  std::string socketName;
  if(getRemote())
    socketName = ":";
  else
    socketName = getUserHomedir() + ".gmshsock";
#endif

  std::string sockname;
  std::ostringstream tmp;
  if(!strstr(socketName.c_str(), ":")){
    // Unix socket
    tmp << socketName << getId();
    sockname = FixWindowsPath(tmp.str());
  }
  else{
    // TCP/IP socket
    if(socketName.size() && socketName[0] == ':')
      // prepend hostname if only the port number is given
      tmp << GetHostName();
    tmp << socketName ;
    sockname = tmp.str();
  }

  std::string command = buildCommandLine();
  if(command.size()) command.append(appendArguments());

  int sock;
  try{
    sock = server->Start(command.c_str(), sockname.c_str(), 10);
  }
  catch(const char *err){
    OLMsg::Error("%s (on socket '%s')", err, sockname.c_str());
    sock = -1;
  }

  if(sock < 0){
    server->Shutdown();
    delete server;
    return false;
  }

  OLMsg::StatusBar(2, true, "Now running client <%s>", _name.c_str());

  while(1) {
    if(_pid < 0) break;

    int stop = server->NonBlockingWait(sock, 0.001, 0.);
    if(stop || _pid < 0) {
      OLMsg::Info("Stop=%d _pid=%d",stop, _pid);
      break;
    }
    int type, length, swap;
    if(!server->ReceiveHeader(&type, &length, &swap)){
      OLMsg::Error("Did not receive message header: stopping server");
      break;
    }
     // else
     //   std::cout << "FHF: Received header=" << type << std::endl;

    std::string message(length, ' ');
    if(!server->ReceiveMessage(length, &message[0])){
      OLMsg::Error("Did not receive message body: stopping server");
      break;
    }
    //else
    //  std::cout << "FHF: Received message=" << message << std::endl;

    switch (type) {
    case GmshSocket::GMSH_START:
      _pid = atoi(message.c_str());
      _gmshServer = server;
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      _gmshServer = 0;
      break;
    case GmshSocket::GMSH_PARAMETER:
      {
        std::string version, type, name;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(onelab::parameter::version() != version){
          OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
	   message.c_str(), onelab::parameter::version().c_str(), version.c_str());
        }
        if(type == "number"){
          onelab::number p; p.fromChar(message); set(p);
        }
        else if(type == "string"){
          onelab::string p; p.fromChar(message); set(p);
        }
	else if(type == "region"){
          onelab::region p; p.fromChar(message); set(p);
        }
        else if(type == "function"){
          onelab::function p; p.fromChar(message); set(p);
        }
        else
          OLMsg::Error("FIXME query not done for this parameter type: <%s>",
		     message.c_str());
      }
      break;
    case GmshSocket::GMSH_PARAMETER_QUERY:
      {
        std::string version, type, name, reply;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(onelab::parameter::version() != version){
          OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
	   message.c_str(), onelab::parameter::version().c_str(), version.c_str());
        }
        else if(type == "number"){
          std::vector<onelab::number> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
	}
        else if(type == "string"){
          std::vector<onelab::string> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else if(type == "region"){
          std::vector<onelab::region> par; get(par, name);
          if(par.size() == 1) par[0].toChar();
        }
        else if(type == "function"){
          std::vector<onelab::function> par; get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else
          OLMsg::Error("Unknown OneLab parameter type in query: %s",
		     type.c_str());

        if(reply.size()){
          server->SendMessage(GmshSocket::GMSH_PARAMETER,
			      reply.size(), &reply[0]);
        }
        else{
          reply = "OneLab parameter '" + name + "' not found";
          server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
        }
      }
      break;
    case GmshSocket::GMSH_PARAM_QUERY_ALL:
      {
        std::string version, type, name, reply;
        std::vector<std::string> replies;
        onelab::parameter::getInfoFromChar(message, version, type, name);
	if(onelab::parameter::version() != version){
          OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
           message.c_str(), onelab::parameter::version().c_str(), version.c_str());
        }
	else if(type == "number"){
	  std::vector<onelab::number> numbers; get(numbers);
	  for(std::vector<onelab::number>::iterator it = numbers.begin();
	      it != numbers.end(); it++) replies.push_back((*it).toChar());
	}
	else if(type == "string"){
	  std::vector<onelab::string> strings; get(strings);
	  for(std::vector<onelab::string>::iterator it = strings.begin();
	      it != strings.end(); it++) replies.push_back((*it).toChar());
	}
        else if(type == "region"){
	  std::vector<onelab::region> regions; get(regions);
	  for(std::vector<onelab::region>::iterator it = regions.begin();
              it != regions.end(); it++) replies.push_back((*it).toChar());
        }
        else if(type == "function"){
	  std::vector<onelab::function> functions; get(functions);
	  for(std::vector<onelab::function>::iterator it = functions.begin();
              it != functions.end(); it++) replies.push_back((*it).toChar());
        }
        else
          OLMsg::Error("Unknown OneLab parameter type in query: %s",
		     type.c_str());

        for(unsigned int i = 0; i < replies.size(); i++)
          server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_ALL,
	     replies[i].size(), &replies[i][0]);
        reply = "Sent all OneLab " + type + "s";
        server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_END,
			    reply.size(), &reply[0]);
      }
      break;
    case GmshSocket::GMSH_PROGRESS:
      OLMsg::StatusBar(2, false, "%s %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_INFO:
      OLMsg::Direct("%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_WARNING:
      OLMsg::Direct(2, "%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_ERROR:
      //OLMsg::Direct(1, "%-8.8s: %s", _name.c_str(), message.c_str());
      OLMsg::Error("%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_MERGE_FILE:
      break;
    default:
      OLMsg::Warning("Received unknown message type (%d)", type);
      break;
    }
  }

  server->Shutdown();
  delete server;
  OLMsg::StatusBar(2, true, "Done running '%s'", _name.c_str());

  if(command.empty()){
    OLMsg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

  return true;
}

bool localNetworkSolverClient::kill()
{
  if(_pid > 0) {
    if(KillProcess(_pid)){
      OLMsg::Info("Killed '%s' (pid %d)", _name.c_str(), _pid);
      _pid = -1;
      return true;
    }
  }
  _pid = -1;
  return false;
}

// client LOCALSOLVERCLIENT

std::string localSolverClient::toChar(){
  std::ostringstream sstream;
  if(getCommandLine().size()){
    sstream << getName() << "." << "commandLine("
	    << getCommandLine() << ");\n";
  }
  return sstream.str();
}

const std::string localSolverClient::getString(const std::string what){
  std::string name=getName() + "/" + what;
  std::vector<onelab::string> strings;
  get(strings, name);
  if(strings.size())
    return strings[0].getValue();
  else{
    //OLMsg::Info("Undefined parameter <%s> in getString", name.c_str());
    return "";
  }
}

void localSolverClient::setAction(const std::string action){
  std::string name=getName() + "/Action";
  onelab::string s(name, action);
  s.setVisible(false);
  s.setNeverChanged(true);
  set(s);
}

const bool localSolverClient::getList(const std::string type, std::vector<std::string> &choices){
  std::vector<onelab::string> strings;
  get(strings, getName() + "/" + type);
  if(strings.size()){
    choices= strings[0].getChoices();
    return true;
  }
  else
    return false;
}

bool localSolverClient::checkCommandLine(){
  OLMsg::Info("Check command line <%s> for client <%s>",
	      getCommandLine().c_str(), getName().c_str());
  if(!isActive()) return true;

  if(!getCommandLine().empty()){
    if(isNative()){
      setAction("initialize");
      if(!run()){  // initializes native clients
	OLMsg::Error("Invalid commandline <%s> for client <%s>",
	   FixExecPath(getCommandLine()).c_str(), getName().c_str());
	//setCommandLine("");
	return false;
      }
    }
    else{
      std::string cmd,commandLine;
      char cbuf [1024];
      FILE *fp;
      commandLine.assign(FixExecPath(getCommandLine()));
      cmd.assign("which "+commandLine);
      fp = POPEN(cmd.c_str(), "r");
      if(fgets(cbuf, 1024, fp) == NULL){
	OLMsg::Error("The executable <%s> does not exist",
		       commandLine.c_str());
	PCLOSE(fp);
	return false;
      }
      OLMsg::Info("The executable <%s> exists", commandLine.c_str());
      PCLOSE(fp);
      return true;
    }
  }
  else{
    OLMsg::Error("No commandline for client <%s>", getName().c_str());
    if(OLMsg::hasGmsh) {
      return false; // exits metamodel and restores control to gmsh
    }
    else{ // asks the user in console mode
      std::cout << "\nONELAB:Enter the command line (with path) of the executable file of <" << getName() << ">" << std::endl;
      std::string cmdl;
      std::getline (std::cin,cmdl);
      setCommandLine(cmdl);
      return cmdl.size();
    }
  }
  return true;
}

bool localSolverClient::buildRmCommand(std::string &cmd){
  std::vector<std::string> choices;

  cmd.assign("");
  if(!getWorkingDir().empty())
    cmd.append("cd " + getWorkingDir() + cmdSep);

  if(getList("OutputFiles",choices)){
#if defined(WIN32)
    cmd.append("del ");
#else
    cmd.append("rm -rf ");
#endif
    if(choices.size()){
      for(unsigned int i = 0; i < choices.size(); i++)
	cmd.append(choices[i]+" ");
      return true;
    }
  }
  return false;
}

void localSolverClient::addNumberChoice(std::string name, double val)
{
  std::vector<double> choices;
  std::vector<onelab::number> ps;
  get(ps, name);
  if(ps.size()){
    choices = ps[0].getChoices();
  }
  else{
    ps.resize(1);
    ps[0].setName(name);
  }
  ps[0].setAttribute("Highlight","Coral");
  ps[0].setReadOnly(false);
  ps[0].setVisible(true);
  ps[0].setValue(val);
  choices.push_back(val);
  ps[0].setChoices(choices);
  set(ps[0]);
}

void localSolverClient::PostArray(std::vector<std::string> choices)
{
  unsigned int i=0;
  while( 4*(i+1) <= choices.size()){
    int lin= atof(choices[4*i+1].c_str())-1;
    int col= atof(choices[4*i+2].c_str())-1;
    std::string fileName = getWorkingDir()+choices[4*i];
      //checkIfPresent or make available locally
    double val=find_in_array(lin,col,read_array(fileName,' '));
    addNumberChoice(choices[4*i+3],val);
    OLMsg::Info("Upload parameter <%s>=%e from file <%s>",
		choices[4*i+3].c_str(),val,fileName.c_str());
    i++;
  }
}

void localSolverClient::GmshMerge(std::vector<std::string> choices)
{
  for(unsigned int i = 0; i < choices.size(); i++){
    std::string fileName=getWorkingDir()+choices[i];
    //checkIfPresent or make available locally
    OLMsg::Info("Send merge request <%s>",fileName.c_str());
    OLMsg::MergeFile(fileName);
  }
}

// REMOTE CLIENT

bool remoteClient::checkCommandLine(const std::string &commandLine){
  std::string cmd;
  char cbuf [1024];
  FILE *fp;

  cmd.assign("ssh "+getRemoteHost()+" 'mkdir -p "+getRemoteDir()+"'");
  mySystem(cmd);

  cmd.assign("ssh "+getRemoteHost()+" 'which "+commandLine+"'");
  fp = POPEN(cmd.c_str(), "r");
  if(fgets(cbuf, 1024, fp) == NULL){
    OLMsg::Warning("The executable <%s> does not exist",
		 commandLine.c_str());
    PCLOSE(fp);
    return false;
  }
  OLMsg::Info("The executable <%s> exists", commandLine.c_str());
  PCLOSE(fp);

  return true;
}

bool remoteClient::checkIfPresentRemote(const std::string &fileName){
  std::string cmd;
  char cbuf [1024];
  FILE *fp;

  cmd.assign("ssh "+_remoteHost+" 'cd "+_remoteDir+"; ls "+fileName+" 2>/dev/null'");
  //std::cout << "check remote<" << cmd << ">" << std::endl;
  fp = POPEN(cmd.c_str(), "r");
  if(fgets(cbuf, 1024, fp) == NULL){
    OLMsg::Error("The file <%s> is not present", fileName.c_str());
    PCLOSE(fp);
    return false;
  }
  OLMsg::Info("The file <%s> is present", fileName.c_str());
  PCLOSE(fp);
  return true;
}

bool remoteClient::syncInputFile(const std::string &wdir, const std::string &fileName){
  size_t pos;
  std::string cmd;
  if((pos=fileName.find(onelabExtension)) != std::string::npos){
    // .ol file => local
    // remove ext .ol
    std::string trueName =
      fileName.substr(fileName.find_first_not_of(" "),pos);
    std::string fullName = wdir+trueName;
    if(checkIfPresent(fullName)){
      cmd.assign("rsync -e ssh -auv "+fullName+" "+_remoteHost+":"+_remoteDir+"/"+trueName);
// #if defined(WIN32)
//       Sleep((int)(OLMsg::GetOnelabNumber("RSYNCDELAY")*1000));
// #else
//       sleep(OLMsg::GetOnelabNumber("RSYNCDELAY"));
// #endif
      SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
      return mySystem(cmd);
    }
    else{
      OLMsg::Error("The input file <%s> is not present", fullName.c_str());
      return false;
    }
  }
  else { // not a .ol file, apply the . rule
    if(!fileName.compare(fileName.find_first_not_of(" "),1,".")){
      //should be found local
      std::string fullName = wdir+fileName;
      if(checkIfPresent(fullName)){
	cmd.assign("rsync -e ssh -auv "+fullName+" " + _remoteHost);
	cmd.append(":" + _remoteDir + "/"+fileName);
	SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
	return mySystem(cmd);
      }
      else{
	OLMsg::Error("The input file <%s> is not present", fullName.c_str());
	return false;
      }
    }
    else { //should be found remote
      if(!checkIfPresentRemote(fileName)){
	OLMsg::Error("The input file <%s> is not present", fileName.c_str());
	return false;
      }
      else
	return true;
    }
  }
}

bool remoteClient::syncOutputFile(const std::string &wdir, const std::string &fileName){
  std::string cmd;

  if(checkIfPresentRemote(fileName)){
    size_t pos=fileName.find_first_not_of(" ");
    if(!fileName.compare(pos,1,".")){
      // the file must be copied back on local host
      cmd.assign("rsync -e ssh -auv "+_remoteHost+":"+_remoteDir+dirSep
		 +fileName.substr(pos,std::string::npos)+" .");
      if(!wdir.empty())
	cmd.append(dirSep+wdir);
      SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
      return mySystem(cmd);
    }
  }
  return false;
}

// client METAMODEL


bool MetaModel::checkCommandLines(){
  bool allDefined=true;
  for(citer it = _clients.begin(); it != _clients.end(); it++){
    allDefined = allDefined && (*it)->checkCommandLine();
  }
  saveCommandLines(genericNameFromArgs);
  return allDefined;
}

void MetaModel::construct()
{
  OLMsg::Info("Metamodel now CONSTRUCTING");
  openOnelabBlock();
  parse_onefile( genericNameFromArgs + onelabExtension + ".save",false);
  parse_onefile( genericNameFromArgs + onelabExtension);
  closeOnelabBlock();
  saveCommandLines(genericNameFromArgs);
}

void MetaModel::analyze() {
  OLMsg::Info("Metamodel now ANALYZING");
  std::string fileName = genericNameFromArgs + onelabExtension;
  openOnelabBlock();
  parse_onefile(fileName);
  closeOnelabBlock();
}


void MetaModel::compute() {
  OLMsg::Info("Metamodel now COMPUTING");
  std::string fileName = genericNameFromArgs + onelabExtension;
  openOnelabBlock();
  parse_onefile(fileName);
  closeOnelabBlock();
  onelab::server::instance()->setChanged(false);
}

void MetaModel::registerClient(const std::string &name, const std::string &type, const std::string &cmdl, const std::string &host, const std::string &rdir) {
  localSolverClient *c;

  // Clients are assigned by default the same working dir as the MetaModel
  // i.e. the working dir from args
  if(host.empty() || rdir.empty()){ //local client
    if(!type.compare(0,6,"interf"))
      c= new InterfacedClient(name,cmdl,getWorkingDir());
    else if(!type.compare(0,6,"native"))
      c= new NativeClient(name,cmdl,getWorkingDir());
    else if(!type.compare(0,6,"encaps"))
      c= new EncapsulatedClient(name,cmdl,getWorkingDir());
    else
      OLMsg::Error("Unknown client type", type.c_str());
  }
  else{ // remote client
    if(!type.compare(0,6,"interf"))
      c= new RemoteInterfacedClient(name,cmdl,getWorkingDir(),host,rdir);
    else if(!type.compare(0,6,"native"))
      c= new RemoteNativeClient(name,cmdl,getWorkingDir(),host,rdir);
    else if(!type.compare(0,6,"encaps"))
      c= new RemoteEncapsulatedClient(name,cmdl,getWorkingDir(),host,rdir);
    else
      OLMsg::Error("Unknown remote client type", type.c_str());
  }
  _clients.push_back(c);
}

void MetaModel::PostArray(std::vector<std::string> choices)
{
  unsigned int i=0;
  while( 4*(i+1) <= choices.size()){
    int lin= atof(choices[4*i+1].c_str())-1;
    int col= atof(choices[4*i+2].c_str())-1;
    std::string fileName =
      OLMsg::GetOnelabString("Arguments/WorkingDir")+choices[4*i];
    double val=find_in_array(lin,col,read_array(fileName,' '));
    addNumberChoice(choices[4*i+3],val);
    OLMsg::Info("PostArray <%s>=%e",choices[4*i+3].c_str(),val);
    i++;
  }
}

// INTERFACED client

void InterfacedClient::analyze() {
  size_t pos;
  std::vector<std::string> choices;

  OLMsg::Info("Analyze <%s> changed=%d", getName().c_str(),
	      onelab::server::instance()->getChanged(getName()));
  setAction("check");

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++){
    if((pos=choices[i].find(onelabExtension)) != std::string::npos){
      // if .ol file
      checkIfPresentLocal(choices[i]);
      parse_onefile(choices[i]);
    }
  }
  convert();
}

void InterfacedClient::convert() {
  size_t pos;
  std::vector<std::string> choices;

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++){
    if((pos=choices[i].find(onelabExtension)) != std::string::npos){
      checkIfPresentLocal(choices[i]);
      // remove .ol extension
      std::string ofileName = getWorkingDir() + choices[i].substr(0,pos);
      std::ofstream outfile(ofileName.c_str());
      if (outfile.is_open())
	convert_onefile(choices[i],outfile);
      else
	OLMsg::Error("The file <%s> cannot be opened",ofileName.c_str());
      outfile.close();
    }
  }
}

void InterfacedClient::compute(){
  std::string cmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      //remove .ol ext
      checkIfPresentLocal(
	 choices[i].substr(0,choices[i].find(onelabExtension)));
    }
  }

  if(buildRmCommand(cmd)) mySystem(cmd);

  cmd.assign("");
  if(!getWorkingDir().empty())
    cmd.append("cd " + getWorkingDir() + cmdSep);
  cmd.append(FixExecPath(getCommandLine()));
  cmd.append(" " + getString("Arguments"));

  if(cmd.size()) mySystem(cmd.c_str());

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      checkIfPresentLocal(choices[i]);
    }
  }
  OLMsg::Info("Client %s completed",getName().c_str());
}

// NATIVE Client

void NativeClient::analyze() {
  OLMsg::Info("Analyze <%s> changed=%d", getName().c_str(),
	      onelab::server::instance()->getChanged(getName()));
  setAction("check");
  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());
}

void NativeClient::compute() {
  std::string cmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(buildRmCommand(cmd)) mySystem(cmd);

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      checkIfPresentLocal(choices[i]);
    }
  }

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      checkIfPresentLocal(choices[i]);
    }
  }
  OLMsg::Info("Client %s completed",getName().c_str());
}

// ENCAPSULATED Client
// EncapsulatedClient's are InterfacedClient's called via the loader
// so that Gmsh sees them as a localNetworkClient

void EncapsulatedClient::analyze() {
  size_t pos;
  std::vector<std::string> choices;

  OLMsg::Info("Analyze <%s> changed=%d", getName().c_str(),
	      onelab::server::instance()->getChanged(getName()));
  setAction("check");

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++){
    if((pos=choices[i].find(onelabExtension)) != std::string::npos){
      // if .ol file
      checkIfPresentLocal(choices[i]);
      parse_onefile(choices[i]);
    }
  }
  convert();
}

void EncapsulatedClient::convert() {
  size_t pos;
  std::vector<std::string> choices;

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++){
    if((pos=choices[i].find(onelabExtension)) != std::string::npos){
      checkIfPresentLocal(choices[i]);
      // remove .ol extension
      std::string ofileName = getWorkingDir() + choices[i].substr(0,pos);
      std::ofstream outfile(ofileName.c_str());
      if (outfile.is_open())
	convert_onefile(choices[i],outfile);
      else
	OLMsg::Error("The file <%s> cannot be opened",ofileName.c_str());
      outfile.close();
    }
  }
}

std::string EncapsulatedClient::buildCommandLine(){
  std::string cmd= FixExecPath(OLMsg::GetOnelabString("LoaderPathName"));
  OLMsg::Info("command line=<%s>",cmd.c_str());
  return cmd;
}

void EncapsulatedClient::compute(){
  std::string cmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      //remove .ol ext
      checkIfPresentLocal(
	  choices[i].substr(0,choices[i].find(onelabExtension)));
    }
  }

  if(buildRmCommand(cmd)) mySystem(cmd);

  // the client command line is buit and stored in a onelab parameter
  cmd.assign("");
  if(!getWorkingDir().empty())
    cmd.append("cd " + getWorkingDir() + cmdSep);
  cmd.append(FixExecPath(getCommandLine()));
  cmd.append(" " + getString("Arguments"));
  OLMsg::SetOnelabString(getName()+"/FullCmdLine",cmd,false);

  // the encapsulating localNetworkClient is called
  OLMsg::Info("Command line=<%s>",cmd.c_str());

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++){
      checkIfPresentLocal(choices[i]);
    }
  }
  OLMsg::Info("Client %s completed",getName().c_str());
}

// REMOTE INTERFACED Client

bool RemoteInterfacedClient::checkCommandLine(){
  return remoteClient::checkCommandLine(getCommandLine());
}

void RemoteInterfacedClient::compute(){
  std::string cmd,rmcmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncInputFile(getWorkingDir(),choices[i]);
  }

  if(buildRmCommand(rmcmd)){
    cmd.assign("ssh "+getRemoteHost()+" 'cd "+getRemoteDir()+"; "+rmcmd+"'");
    mySystem(cmd);
  }

  cmd.assign("ssh "+getRemoteHost()+" 'cd "+getRemoteDir()+"; "
	     +getCommandLine()+" "+getString("Arguments")+"'");
  mySystem(cmd);

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncOutputFile(getWorkingDir(),choices[i]);
  }

  OLMsg::Info("Client %s completed",getName().c_str());
}


// REMOTE NATIVE Client

std::string RemoteNativeClient::buildCommandLine(){
  std::string command;
  command.assign("incomp_ssh -f "+getRemoteHost());
  command.append(" 'cd "+getRemoteDir()+"; ");
  command.append(FixExecPath(getCommandLine())+" ");
  return command;
}

bool RemoteNativeClient::checkCommandLine(){
  return remoteClient::checkCommandLine(getCommandLine());
}

void RemoteNativeClient::analyze(){
  std::string cmd,rmcmd;
  std::vector<std::string> choices;

  OLMsg::Info("Analyze <%s> changed=%d", getName().c_str(),
	      onelab::server::instance()->getChanged(getName()));
  setAction("check");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncInputFile(getWorkingDir(),choices[i]);
  }

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());
}


void RemoteNativeClient::compute(){
  std::string cmd,rmcmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s> changed=%d", getName().c_str());
  setAction("compute");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncInputFile(getWorkingDir(),choices[i]);
  }

  if(buildRmCommand(rmcmd)){
    cmd.assign("ssh "+getRemoteHost()+" 'cd "+getRemoteDir()+"; "+rmcmd+"'");
    mySystem(cmd);
  }

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncOutputFile(getWorkingDir(),choices[i]);
  }

  OLMsg::Info("Client %s completed",getName().c_str());
}


// REMOTE ENCAPSULATED Client

bool RemoteEncapsulatedClient::checkCommandLine(){
  return remoteClient::checkCommandLine(getCommandLine());
}

void RemoteEncapsulatedClient::compute(){
  std::string cmd,rmcmd;
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorNum()) return;
  OLMsg::Info("Computes <%s> changed=%d", getName().c_str());
  setAction("compute");

  if(getList("InputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncInputFile(getWorkingDir(),choices[i]);
  }

  if(buildRmCommand(rmcmd)){
    cmd.assign("ssh "+getRemoteHost()+" 'cd "+getRemoteDir()+"; "+rmcmd+"'");
    mySystem(cmd);
  }

  // the client command line is buit and stored in a onelab parameter
  cmd.assign("ssh "+getRemoteHost());
  if(!getRemoteDir().empty())
    cmd.append(" 'cd " + getRemoteDir() + ";");
  cmd.append(" "+FixExecPath(getCommandLine()));
  cmd.append(" " + getString("Arguments") + " '");
  OLMsg::SetOnelabString(getName()+"/FullCmdLine",cmd,false);

  // the encapsulating localNetworkClient is called
  OLMsg::Info("Command line=<%s>",cmd.c_str());

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
		 FixExecPath(getCommandLine()).c_str(), getName().c_str());

  if(getList("OutputFiles",choices)){
    for(unsigned int i = 0; i < choices.size(); i++)
      syncOutputFile(getWorkingDir(),choices[i]);
  }

  OLMsg::Info("Client %s completed",getName().c_str());
}



// ONELAB additional TOOLS (no access to server in tools)
// options for 'onelab_client'

int getOptions(int argc, char *argv[], parseMode &todo, std::string &commandLine, std::string &caseName, std::string &clientName, std::string &sockName){

  commandLine=argv[0];
  todo=COMPUTE;
  caseName="untitled";
  int i= 1;
  while(i < argc) {
    if(argv[i][0] == '-') {
      if(!strcmp(argv[i] + 1, "onelab")) {
	i++;
	clientName = argv[i];
        i++;
	sockName = argv[i];
        i++;
      }
      else if(!strcmp(argv[i] + 1, "a")) {
	i++;
	todo=ANALYZE;
      }
      else if(!strcmp(argv[i] + 1, "c")) {
	i++;
	std::cout << "\nONELAB: Present state of the onelab clients\n"
		  << std::endl;
	for(onelab::server::citer it=onelab::server::instance()->firstClient();
	    it != onelab::server::instance()->lastClient(); it++){
	  std::string name= it->second->getName();
	  std::cout << "<" << onelab::server::instance()->getChanged(name)
		    << "> " << name << std::endl;
	}
	todo=ANALYZE;
      }
      else {
	i++;
	printf("Usage: %s [-m num -a -c]\n", argv[0]);
	printf("Options are:\nm      model number\n");
	printf("a      analyze only\n");
	exit(1);
      }
    }
    else{
      caseName=argv[i];
      i++;
    }
  }
  return(1);
}

std::string itoa(const int i){
  std::ostringstream tmp;
  tmp << i ;
  return tmp.str();
}

std::string ftoa(const double x){
  std::stringstream Num;
  Num << x;
  return Num.str();
}

int mySystem(std::string commandLine){
  OLMsg::Info("Calling <%s>", commandLine.c_str());
  return SystemCall(commandLine.c_str(), true);
}

#include <sys/stat.h>
#include <ctime>
bool checkIfPresent(std::string fileName){
  struct stat buf;
  if (!stat(fileName.c_str(), &buf))
    return true;
  else{
    OLMsg::Error("The file <%s> is not present.",fileName.c_str());
    return false;
  }
}


#include <sys/types.h>

#if not defined WIN32
#include <unistd.h>
#include <pwd.h>
std::string getUserHomedir(){
  struct passwd *pw = getpwuid(getuid());
  std::string str(pw->pw_dir);
  str.append("/");
  return str;
}
#include <sys/param.h>
#else
#include <direct.h>
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif


std::string getCurrentWorkdir(){
  char path[MAXPATHLEN];
  getcwd(path, MAXPATHLEN);
  std::string str = path;
  return str;
}

std::string sanitize(const std::string &in)
{
  std::string out, forbidden(" ();");
  for(unsigned int i = 0; i < in.size(); i++)
    if ( forbidden.find(in[i]) == std::string::npos)
      out.push_back(in[i]);
  return out;
}

std::string quote(const std::string &in){
  return "\"" + in + "\"";
}
std::string unquote(const std::string &in)
{
  size_t pos0=in.find_first_not_of(" ");
  size_t pos=in.find_last_not_of(" ");
  if( (pos0 != std::string::npos) && (pos != std::string::npos))
    if(in.compare(pos0,1,"\"")) pos0++;
    if(in.compare(pos,1,"\"")) pos--;
    return in.substr(pos0,pos-pos0+1);
}

std::string FixWindowsQuotes(const std::string &in)
{
#if defined(WIN32)
  return "\"" + in + "\"";
#else
  return in;
#endif
}

std::string FixExecPath(const std::string &in)
{
  std::string cmd,split0,split1,split2;
  std::cout << "in=<" << in << ">" << std::endl;

  cmd.assign(removeBlanks(in));
  cmd.assign(FixWindowsPath(cmd));

  split0.assign(SplitFileName(cmd)[0]);
  split1.assign(SplitFileName(cmd)[1]);
  split2.assign(SplitFileName(cmd)[2]);
  // std::cout << "0=<" << split0 << ">" << std::endl;
  // std::cout << "1=<" << split1 << ">" << std::endl;
  // std::cout << "2=<" << split2 << ">" << std::endl;

  if(split2==".app")
    cmd.assign(cmd + "/Contents/MacOS/" + split1);
  
  if(split1.find("elmerfem") != std::string::npos){
#if not defined(WIN32)
    cmd.assign("ELMER_HOME=" + quote(split0.substr(0,split0.size()-4)) );
    cmd.append(cmdSep);
    cmd.append( quote("$ELMER_HOME/bin/"+split1) );
#endif
  }
  else
    if(cmd[0] != '\"') cmd.assign(quote(cmd));

  //std::cout << "cmd=<" << cmd << ">" << std::endl;
  return cmd;
}

std::string removeBlanks(const std::string &in)
{
  size_t pos0=in.find_first_not_of(" ");
  size_t pos=in.find_last_not_of(" ");
  if( (pos0 != std::string::npos) && (pos != std::string::npos))
    return in.substr(pos0,pos-pos0+1);
  else
    return "";
}
bool isPath(const std::string &in)
{
  size_t pos=in.find_last_not_of(" 0123456789");
  if(pos==std::string::npos) return true;
  if(in.compare(pos,1,"/")){
    OLMsg::Error("The argument <%s> is not a valid parameter path (must end with '/')",in.c_str());
    return false;
  }
  else
    return true;
}

// std::vector <double> extract_column(const unsigned int col, const array data){
//   std::vector<double> column;
//   for(unsigned int i=0; i<data.size(); i++)
//     if(col<=data[i].size())
//       column.push_back(data[i][col-1]);
//     else
//       OLMsg::Error("Column number (%d) out of range.",col);
//   return column;
// }

double find_in_array(int lin, int col, const std::vector <std::vector <double> > &data){
  if(lin<0) lin=(int)data.size()-1;
  if(lin<(int)data.size()){
    if ( col>=0 && col<(int)data[lin].size() )
      return data[lin][col];
  }
  OLMsg::Error("The value has not been calculated: (%d,%d) out of range",lin,col);
  return(0);
}

array read_array(std::string fileName, char sep){
  std::ifstream infile(sanitize(fileName).c_str());
  std::vector <std::vector <double> > array;

  size_t deb,end;
  double temp;
  while (infile){
    std::string s;
    if (!getline( infile, s )) break;
    std::vector <double> record;
    end=0;
    while ( (deb=s.find_first_not_of(" \t\n", end)) != std::string::npos ) {
      end=s.find_first_of(" \t\n",deb);
      temp=atof( s.substr(deb,end).c_str() );
      record.push_back( temp );
    }
    array.push_back( record );
  }
  if (!infile.eof()){
    std::cerr << "Error reading array\n";
  }
  return array;
}

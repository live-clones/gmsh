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

#if defined(WIN32)
static char dirSep = '\\';
static std::string cmdSep(" & ");
static std::string removeCmd("del ");
static std::string lsCmd("dir ");
#else
static char dirSep = '/';
static std::string cmdSep(" ; ");
static std::string removeCmd("rm -rf ");
static std::string lsCmd("ls ");
#endif

class onelabMetaModelServer : public GmshServer {
private:
  localNetworkSolverClient *_client;

public:
  onelabMetaModelServer(localNetworkSolverClient *client)
    : GmshServer(), _client(client)
  {
  }
  ~onelabMetaModelServer() {}

  int NonBlockingSystemCall(const std::string &exe, const std::string &args)
  {
    std::cout << "Calling now : " << exe << " " << args << std::endl;
    return SystemCallExe(exe, args);
  }
  int NonBlockingWait(double waitint, double timeout, int socket)
  {
    double start = TimeOfDay();
    while(1) {
      if(timeout > 0 && TimeOfDay() - start > timeout) return 2; // timeout

      if(_client->getPid() < 0 /*|| (_client->getCommandLine().empty())*/)
        return 1; // process has been killed

      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);

      if(ret == 0) { // nothing available
        // wait at most waitint seconds and respond to FLTK events
        void (*waitFct)(double) = OLMsg::GetGuiWaitFunction();
        if(waitFct) waitFct(waitint);
      }
      else if(ret > 0) {
        return 0; // data is there!
      }
      else { // ret<0 an error happened
        _client->setPid(-1);
        return 1;
      }
    }
  }
};

std::string localNetworkSolverClient::buildCommandLine()
{
  std::string command;
  command.assign("");
  if(!getWorkingDir().empty()) command.append("cd " + getWorkingDir() + cmdSep);
  command.append(QuoteExecPath(getCommandLine()));
  return command;
}

std::string localNetworkSolverClient::appendArguments()
{
  std::string action = getString("Action");
  std::string checkCommand = getString("9CheckCommand");
  std::string computeCommand = getString("9ComputeCommand");

  std::string command;
  if(action == "initialize") {
    command.assign(" " + getSocketSwitch() + " " + getName() + " %s");
  }
  else if(action == "check") {
    command.assign(" " + getString("Arguments") + " " + checkCommand);
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else if(action == "compute") {
    command.assign(" " + getString("Arguments") + " " + computeCommand);
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else
    OLMsg::Error("appendArguments: Unknown Action <%s>", action.c_str());
  return command;
}

bool localNetworkSolverClient::receiveMessage()
{
  double timer = TimeOfDay();

  if(!getGmshServer()) {
    OLMsg::Error("Abnormal server termination (no valid server)");
    return false;
  }

  int type, length, swap;
  if(!getGmshServer()->ReceiveHeader(&type, &length, &swap)) {
    OLMsg::Error(
      "Abnormal server termination (did not receive message header)");
    return false;
  }
  else if(_socketMsg)
    OLMsg::Info("Received header <%d>", type);

  std::string message(length, ' ');
  if(!getGmshServer()->ReceiveMessage(length, &message[0])) {
    OLMsg::Error("Abnormal server termination (did not receive message body)r");
    return false;
  }
  else if(_socketMsg)
    OLMsg::Info("Received message <%s>", message.c_str());

  switch(type) {
  case GmshSocket::GMSH_START: setPid(atoi(message.c_str())); break;
  case GmshSocket::GMSH_STOP: setPid(-1); break;
  case GmshSocket::GMSH_PARAMETER: {
    std::string version, type, name;
    onelab::parameter::getInfoFromChar(message, version, type, name);
    if(onelab::parameter::version() != version) {
      OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
                   message.c_str(), onelab::parameter::version().c_str(),
                   version.c_str());
    }
    if(type == "number") {
      onelab::number p;
      p.fromChar(message);
      set(p);
    }
    else if(type == "string") {
      onelab::string p;
      p.fromChar(message);
      set(p);
    }
    else
      OLMsg::Error("FIXME query not done for this parameter type: <%s>",
                   message.c_str());
  } break;
  case GmshSocket::GMSH_PARAMETER_QUERY: {
    std::string version, type, name, reply;
    onelab::parameter::getInfoFromChar(message, version, type, name);
    if(onelab::parameter::version() != version) {
      OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
                   message.c_str(), onelab::parameter::version().c_str(),
                   version.c_str());
    }
    else if(type == "number") {
      std::vector<onelab::number> par;
      get(par, name);
      if(par.size() == 1) reply = par[0].toChar();
    }
    else if(type == "string") {
      std::vector<onelab::string> par;
      get(par, name);
      if(par.size() == 1) reply = par[0].toChar();
    }
    else
      OLMsg::Error("Unknown OneLab parameter type in query: %s", type.c_str());

    if(reply.size()) {
      getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(),
                                   &reply[0]);
    }
    else {
      reply = "OneLab parameter '" + name + "' not found";
      getGmshServer()->SendMessage(GmshSocket::GMSH_INFO, reply.size(),
                                   &reply[0]);
    }
  } break;
  case GmshSocket::GMSH_PARAMETER_QUERY_ALL: {
    std::string version, type, name, reply;
    std::vector<std::string> replies;
    onelab::parameter::getInfoFromChar(message, version, type, name);
    if(onelab::parameter::version() != version) {
      OLMsg::Error("OneLab version mismatch for %s (server: %s / client: %s)",
                   message.c_str(), onelab::parameter::version().c_str(),
                   version.c_str());
    }
    else if(type == "number") {
      std::vector<onelab::number> numbers;
      get(numbers);
      for(std::vector<onelab::number>::iterator it = numbers.begin();
          it != numbers.end(); it++)
        replies.push_back((*it).toChar());
    }
    else if(type == "string") {
      std::vector<onelab::string> strings;
      get(strings);
      for(std::vector<onelab::string>::iterator it = strings.begin();
          it != strings.end(); it++)
        replies.push_back((*it).toChar());
    }
    else
      OLMsg::Error("Unknown OneLab parameter type in query: %s", type.c_str());

    for(unsigned int i = 0; i < replies.size(); i++)
      getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY_ALL,
                                   replies[i].size(), &replies[i][0]);
    reply = "Sent all OneLab " + type + "s";
    getGmshServer()->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY_END,
                                 reply.size(), &reply[0]);
  } break;
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
    OLMsg::Error("%-8.8s: %s", _name.c_str(), message.c_str());
    break;
  case GmshSocket::GMSH_MERGE_FILE:
    // if(CTX::instance()->solver.autoMergeFile){
    //   unsigned int n = PView::list.size();
    //   MergePostProcessingFile(message,
    //   CTX::instance()->solver.autoShowLastStep,
    //                           CTX::instance()->solver.autoHideNewViews,
    //                           true);
    //   drawContext::global()->draw();
    //   if(FlGui::available() && n != PView::list.size()){
    //     FlGui::instance()->rebuildTree();
    //     FlGui::instance()->openModule("Post-processing");
    //   }
    // }
    break;
  case GmshSocket::GMSH_PARSE_STRING:
    // ParseString(message);
    // drawContext::global()->draw();
    break;
  case GmshSocket::GMSH_SPEED_TEST:
    OLMsg::Info("got %d Mb message in %g seconds", length / 1024 / 1024,
                TimeOfDay() - timer);
    break;
  case GmshSocket::GMSH_VERTEX_ARRAY: {
    // int n = PView::list.size();
    // PView::fillVertexArray(this, length, &message[0], swap);
    // if(FlGui::available())
    //   FlGui::instance()->updateViews(n != (int)PView::list.size());
    // drawContext::global()->draw();
  } break;
  case GmshSocket::GMSH_CONNECT: {
    // const std::string clientName = message;
    // std::cout << "client name =" << clientName << std::endl;
    // onelab::localNetworkClient *subClient = findClient(clientName);
    // if (!subClient) {
    //   subClient = new gmshLocalNetworkClient(clientName, "");
    // }
    // else
    // 	std::cout << "Gmsh has " << addClient(subClient) << " clients\n";
    // subClient->getGmshServer()->LaunchClient();
  } break;
  case GmshSocket::GMSH_OLPARSE: {
#if defined(HAVE_ONELAB_METAMODEL)
    localSolverClient *c = new InterfacedClient("OLParser", "", "");
    std::string ofileName = message;
    std::ofstream outfile(ofileName.c_str());
    if(outfile.is_open())
      c->convert_onefile(ofileName + ".ol", outfile);
    else
      OLMsg::Error("The file <%s> cannot be opened", ofileName.c_str());
    outfile.close();
    delete c;
#endif
  } break;
  default: OLMsg::Warning("Received unknown message type (%d)", type); break;
  }
  return true;
}

bool localNetworkSolverClient::run()
{
  // new_connection:
  setPid(0);

  // Choose socket type (Unix or TCP/IP)
#if defined(WIN32)
  std::string socketName = ":";
#else
  std::string socketName;
  if(isRemote())
    socketName = ":";
  else
    socketName = getUserHomedir() + ".gmshsock";
#endif

  std::string sockname;
  std::ostringstream tmp;
  if(!strstr(socketName.c_str(), ":")) { // Unix socket
    tmp << socketName << getId();
    sockname = FixWindowsPath(tmp.str());
  }
  else { // TCP/IP socket
    if(socketName.size() && socketName[0] == ':')
      tmp << GetHostName(); // prepend hostname if only the port number is given
    tmp << socketName;
    sockname = tmp.str();
  }

  // Build the commande line
  std::string exe = buildCommandLine();
  std::string command(exe);
  if(command.size())
    command.append(appendArguments());
  else
    return false;

  // Create socket connection and launch client
  onelabMetaModelServer *socketConnection = new onelabMetaModelServer(this);

  std::cout << "commandline = " << command << std::endl;

  int sock;
  try {
    sock = socketConnection->Start(exe.c_str(), command.c_str(),
                                   sockname.c_str(), 10);
  } catch(const char *err) {
    OLMsg::Error("%s (on socket '%s')", err, sockname.c_str());
    sock = -1;
  }

  if(sock < 0) { // could not establish connection: aborting
    socketConnection->Shutdown();
    delete socketConnection;
    OLMsg::Error("Connection failed on socket <%s>", sockname.c_str());
    return false;
  }

  OLMsg::StatusBar(2, true, "Now running client <%s> on socket <%d>",
                   _name.c_str(), sock);
  _socketMsg = OLMsg::GetOnelabNumber("SHOWSOCKETMESSAGES") ? true : false;

  setGmshServer(socketConnection);

  while(1) {
    bool stop = false, haveData = false;

    if(getPid() < 0) {
      stop = true;
      break;
    }
    if(!getGmshServer()) {
      OLMsg::Error("Abnormal server termination (no valid server)");
      stop = true;
    }
    else if(!getGmshServer()->NonBlockingWait(0.001, 0., sock)) {
      haveData = true;
    }
    else { // an error occurred
      stop = true;
    }
    if(stop) break;
    if(haveData && !receiveMessage()) break;
    if(getPid() < 0) break;
  }

  socketConnection->Shutdown();
  delete socketConnection;
  setGmshServer(0);
  OLMsg::StatusBar(2, true, "Done running '%s'", _name.c_str());

  // if(command.empty()){
  //   OLMsg::Info("Client disconnected: starting new connection");
  //   goto new_connection;
  // }

  return true;
}

bool localNetworkSolverClient::kill()
{
  if(getPid() > 0) {
    if(KillProcess(getPid())) {
      OLMsg::Info("Killed '%s' (pid %d)", _name.c_str(), getPid());
      setPid(-1);
      return true;
    }
  }
  setPid(-1);
  return false;
}

// client LOCALSOLVERCLIENT

const std::string localSolverClient::getString(const std::string what)
{
  std::string name = getName() + "/" + what;
  std::vector<onelab::string> strings;
  get(strings, name);
  if(strings.size())
    return strings[0].getValue();
  else {
    // OLMsg::Info("Undefined parameter <%s> in getString", name.c_str());
    return "";
  }
}

void localSolverClient::setAction(const std::string action)
{
  std::string name = getName() + "/Action";
  onelab::string s(name, action);
  s.setVisible(false);
  s.setNeverChanged(true);
  set(s);
}

const bool localSolverClient::getList(const std::string type,
                                      std::vector<std::string> &choices)
{
  std::vector<onelab::string> strings;
  get(strings, getName() + "/" + type);
  if(strings.size()) {
    choices = strings[0].getChoices();
    return true;
  }
  else
    return false;
}

void localSolverClient::FixExecPath(const std::string &in)
{
  // only use with local clients
  std::string cmd;
  std::vector<std::string> split = SplitFileName(in);

  if(split[2] == ".app") {
    cmd.assign(in + "/Contents/MacOS/" + split[1]);
    setCommandLine(cmd);
  }

#if !defined(WIN32)
  // if(split[0].find("elmerfem") != std::string::npos){
  if(!split[1].compare("ElmerSolver") && split[2].empty() && split[0].size()) {
    std::string fileName = getWorkingDir() + getName() + ".sh";
    std::string elmerHome = split[0].substr(0, split[0].size() - 4);
    std::ofstream outfile(fileName.c_str());
    if(outfile.is_open()) {
      outfile << "#!/bin/bash" << std::endl;
      outfile << "export ELMER_HOME=\"" << elmerHome << "\"" << std::endl;
      outfile
        << "export DYLD_LIBRARY_PATH=\".:$ELMER_HOME/lib:$DYLD_LIBRARY_PATH\""
        << std::endl;
      outfile << in << std::endl;
    }
    else
      OLMsg::Error("The file <%s> cannot be opened", fileName.c_str());
    outfile.close();
    chmod(fileName);
    setCommandLine(fileName);
  }
#endif
}

bool localSolverClient::checkCommandLine()
{
  bool success = true;
  OLMsg::Info("Check command line <%s> for client <%s>",
              getCommandLine().c_str(), getName().c_str());

  if(getCommandLine().empty()) {
    if(OLMsg::hasGmsh) {
      OLMsg::Error("No command line for client <%s>", getName().c_str());
      return false; // restores control to gmsh
    }
    else { // asks the user in console mode
      std::cout << "\nONELAB: Enter pathname of the executable file for <"
                << getName() << ">" << std::endl;
      std::string cmdl;
      std::getline(std::cin, cmdl);
      setCommandLine(cmdl);
      return checkCommandLine();
    }
  }
  else {
    if(!isRemote()) FixExecPath(getCommandLine());

    if(isNative()) { // native clients checked by initializing
      setAction("initialize");
      if(!run()) { // initializes native clients, false otherwise
        success = false;
      }
    }
    else {
      std::string commandLine;
      commandLine.assign(QuoteExecPath(getCommandLine()));

      // check whether the executable exists as a file
      success = checkIfPresent(getCommandLine());

      // resolve a possible linux link
#if !defined(WIN32)
      if(!success) {
        char cbuf[1024];
        FILE *fp;
        std::string cmd;
        cmd.assign("which " + commandLine);
        fp = POPEN(cmd.c_str(), "r");
        if(fgets(cbuf, 1024, fp) == NULL) {
          PCLOSE(fp);
          success = false;
        }
        else {
          commandLine.assign(sanitizeString(cbuf, "\n"));
          success = true;
        }
        PCLOSE(fp);
      }
#else
      success = true;
#endif
    }
  }
  if(success) {
    OLMsg::SetVisible(getName() + "/CommandLine", false);
    OLMsg::SetVisible(getName() + "/HostName", false);
    OLMsg::SetVisible(getName() + "/RemoteDir", false);
    OLMsg::Info("Command line ok");
  }
  else {
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
    // setCommandLine("");
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), true);
  }
  return success;
}

bool localSolverClient::buildRmCommand(std::string &cmd)
{
  std::vector<std::string> choices, split;
  if(getList("OutputFiles", choices)) {
    cmd.assign(removeCmd); // defined in OnelabClients.h
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      cmd.append(split[1] + " ");
    }
    if(choices.size()) return true;
  }
  return false;
}

void localSolverClient::addNumberChoice(std::string name, double val,
                                        bool readOnly)
{
  std::vector<double> choices;
  std::vector<onelab::number> ps;
  get(ps, name);
  if(ps.size()) {
    choices = ps[0].getChoices();
    ps[0].setReadOnly(readOnly);
    ps[0].setValue(val);
    choices.push_back(val);
    ps[0].setChoices(choices);
    set(ps[0]);
  }
  else {
    OLMsg::Error("The parameter <%s> does not exist", name.c_str());
  }
}

void localSolverClient::PostArray(std::vector<std::string> choices)
{
  unsigned int i = 0;
  while(4 * (i + 1) <= choices.size()) {
    int lin = atof(choices[4 * i + 1].c_str()) - 1;
    int col = atof(choices[4 * i + 2].c_str()) - 1;
    std::string fileName = getWorkingDir() + choices[4 * i];
    // checkIfPresent or make available locally
    double val = find_in_array(lin, col, read_array(fileName, ' '));
    std::string paramName = choices[4 * i + 3];
    addNumberChoice(paramName, val, true);
    OLMsg::Info("Upload parameter <%s>=%e from file <%s>", paramName.c_str(),
                val, fileName.c_str());
    i++;
  }
}

void localSolverClient::GmshMerge(std::vector<std::string> choices)
{
  for(unsigned int i = 0; i < choices.size(); i++) {
    std::string fileName = getWorkingDir() + choices[i];
    // checkIfPresent or make available locally
    if(checkIfPresent(fileName)) {
      OLMsg::Info("Send merge request <%s>", fileName.c_str());
      OLMsg::MergeFile(fileName);
    }
  }
}

// REMOTE CLIENT

bool remoteClient::checkCommandLine(const std::string &commandLine)
{
  bool success = true;
  std::string cmd;

  cmd.assign("ssh " + getRemoteHost() + " 'mkdir -p " + getRemoteDir() + "'");
  mySystem(cmd);

  cmd.assign(QuoteExecPath(commandLine));

  // check whether the executable exists as a file
  success = checkIfPresentRemote(commandLine);

  // resolve a possible linux link
#if !defined(WIN32)
  if(!success) {
    char cbuf[1024];
    FILE *fp;
    std::string cmd;
    cmd.assign("ssh " + getRemoteHost() + " 'which " + commandLine + "'");
    fp = POPEN(cmd.c_str(), "r");
    if(fgets(cbuf, 1024, fp) == NULL)
      success = false;
    else
      success = true;
    PCLOSE(fp);
  }
#endif
  return success;
}

bool remoteClient::checkIfPresentRemote(const std::string &fileName)
{
  std::string cmd;
  char cbuf[1024];
  FILE *fp;

  cmd.assign("ssh " + _remoteHost + " 'cd " + _remoteDir + "; ");
  cmd.append(lsCmd + fileName + " 2>/dev/null'");
  // std::cout << "check remote<" << cmd << ">" << std::endl;
  fp = POPEN(cmd.c_str(), "r");
  if(fgets(cbuf, 1024, fp) == NULL) {
    // OLMsg::Warning("The file <%s> is not present", fileName.c_str());
    PCLOSE(fp);
    return false;
  }
  // OLMsg::Info("The file <%s> is present", fileName.c_str());
  PCLOSE(fp);
  return true;
}

bool remoteClient::syncInputFile(const std::string &wdir,
                                 const std::string &fileName)
{
  std::string cmd;
  std::vector<std::string> split;

  split = SplitOLFileName(fileName);
  std::string localName = wdir + split[1];

  OLMsg::Info("Sync input file <%s>", split[1].c_str());

  if(split[2].size()) { // .ol file => local
    if(checkIfPresent(localName)) {
      cmd.assign("rsync -e ssh -auv " + localName + " " + _remoteHost + ":");
      if(_remoteDir.size()) cmd.append(_remoteDir);
      cmd.append(split[1]);
      SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
      return mySystem(cmd);
    }
    else {
      // OLMsg::Error("The input file <%s> is not present", localName.c_str());
      return false;
    }
  }
  else { // not a .ol file, apply the "_" rule
    if(split[0].size()) { // should be found local
      if(checkIfPresent(localName)) {
        cmd.assign("rsync -e ssh -auv " + localName + " " + _remoteHost + ":");
        if(_remoteDir.size()) cmd.append(_remoteDir);
        cmd.append(split[1]);

        SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
        return mySystem(cmd);
      }
      else {
        OLMsg::Error("The local input file <%s> is not present",
                     localName.c_str());
        return false;
      }
    }
    else { // should be found remote
      if(!checkIfPresentRemote(split[1])) {
        OLMsg::Error("The remote input file <%s> is not present",
                     split[1].c_str());
        return false;
      }
      else
        return true;
    }
  }
}

bool remoteClient::syncOutputFile(const std::string &wdir,
                                  const std::string &fileName)
{
  std::string cmd;
  std::vector<std::string> split;

  split = SplitOLFileName(fileName);
  // std::string localName = wdir + split[1];

  OLMsg::Info("Sync output file <%s>", split[1].c_str());

  if(checkIfPresentRemote(split[1])) {
    if(split[0].size()) { // the file must be copied back on local host
      cmd.assign("rsync -e ssh -auv " + _remoteHost + ":");
      if(_remoteDir.size()) cmd.append(_remoteDir);
      cmd.append(split[1]);
      if(wdir.size())
        cmd.append(" " + wdir);
      else
        cmd.append(" .");
      SleepInSeconds(OLMsg::GetOnelabNumber("RSYNCDELAY"));
      return mySystem(cmd);
    }
  }
  return false;
}

// client METAMODEL

void MetaModel::construct()
{
  OLMsg::Info("===== CONSTRUCTING");
  std::string fileName =
    getWorkingDir() + genericNameFromArgs + onelabExtension;
  openOnelabBlock();
  parse_onefile(fileName);
  closeOnelabBlock();
  saveCommandLines();
  // onelab::server::instance()->setChanged(true, getName());
}

void MetaModel::analyze()
{
  OLMsg::Info("===== ANALYZING");
  std::string fileName =
    getWorkingDir() + genericNameFromArgs + onelabExtension;
  openOnelabBlock();
  OLMsg::Info("Parse file <%s> %s", fileName.c_str(),
              parse_onefile(fileName) ? "done" : "failed");
  closeOnelabBlock();
}

void MetaModel::compute()
{
  OLMsg::Info("===== COMPUTING");
  std::string fileName =
    getWorkingDir() + genericNameFromArgs + onelabExtension;
  openOnelabBlock();
  OLMsg::Info("Parse file <%s> %s", fileName.c_str(),
              parse_onefile(fileName) ? "done" : "failed");
  closeOnelabBlock();
  onelab::server::instance()->setChanged(false);
}

void MetaModel::registerClient(const std::string &name, const std::string &type,
                               const std::string &cmdl, const std::string &host,
                               const std::string &rdir)
{
  localSolverClient *c;

  // Clients are assigned by default the same (local) working dir
  // as the MetaModel, i.e. the working dir from args
  // A working (local relative) subdir (useful to organize submodels)
  // can be defined with the command: client.workingSubdir(subdir)
  if(host.empty() || !host.compare("localhost")) { // local client
    if(!type.compare(0, 6, "interf"))
      c = new InterfacedClient(name, cmdl, getWorkingDir());
    else if(!type.compare(0, 6, "native"))
      c = new NativeClient(name, cmdl, getWorkingDir());
    else if(!type.compare(0, 6, "encaps"))
      c = new EncapsulatedClient(name, cmdl, getWorkingDir());
    else
      OLMsg::Error("Unknown client type", type.c_str());
  }
  else { // remote client
    if(!type.compare(0, 6, "interf"))
      c = new RemoteInterfacedClient(name, cmdl, getWorkingDir(), host, rdir);
    else if(!type.compare(0, 6, "native"))
      c = new RemoteNativeClient(name, cmdl, getWorkingDir(), host, rdir);
    else if(!type.compare(0, 6, "encaps"))
      c = new RemoteEncapsulatedClient(name, cmdl, getWorkingDir(), host, rdir);
    else
      OLMsg::Error("Unknown remote client type", type.c_str());
  }
  _clients.push_back(c);
}

void MetaModel::PostArray(std::vector<std::string> choices)
{
  unsigned int i = 0;
  while(4 * (i + 1) <= choices.size()) {
    int lin = atof(choices[4 * i + 1].c_str()) - 1;
    int col = atof(choices[4 * i + 2].c_str()) - 1;
    std::string fileName =
      OLMsg::GetOnelabString("Arguments/WorkingDir") + choices[4 * i];
    double val = find_in_array(lin, col, read_array(fileName, ' '));
    addNumberChoice(choices[4 * i + 3], val);
    OLMsg::Info("PostArray <%s>=%e", choices[4 * i + 3].c_str(), val);
    i++;
  }
}

// INTERFACED client

void InterfacedClient::analyze()
{
  std::vector<std::string> choices, split;

  OLMsg::Info("Analyzes <%s> changed=%d", getName().c_str(),
              onelab::server::instance()->getChanged(getName()));
  setAction("check");

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++) {
    split = SplitOLFileName(choices[i]);
    if(split[2].size()) { // if .ol file
      std::string fileName = getWorkingDir() + split[1] + split[2];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
      OLMsg::Info("Parse file <%s> %s", fileName.c_str(),
                  parse_onefile(fileName) ? "done" : "failed");
    }
  }
  convert();
}

void InterfacedClient::convert()
{
  std::vector<std::string> choices, split;

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++) {
    split = SplitOLFileName(choices[i]);
    if(split[2].size()) { // if .ol file
      std::string fileName = getWorkingDir() + split[1] + split[2];
      std::string ofileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
      std::ofstream outfile(ofileName.c_str());
      if(outfile.is_open())
        convert_onefile(fileName, outfile);
      else
        OLMsg::Error("The file <%s> cannot be opened", ofileName.c_str());
      outfile.close();
    }
  }
}

void InterfacedClient::compute()
{
  std::vector<std::string> choices, split;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }

  std::string cdcmd = "";
  if(getWorkingDir().size()) cdcmd.assign("cd " + getWorkingDir() + cmdSep);

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) mySystem(cdcmd + rmcmd);

  std::string cmd;
  cmd.assign(QuoteExecPath(getCommandLine()) + " " + getString("Arguments"));
  mySystem(cdcmd + cmd);

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }
}

// NATIVE Client

void NativeClient::analyze()
{
  OLMsg::Info("Analyzes <%s> changed=%d", getName().c_str(),
              onelab::server::instance()->getChanged(getName()));
  setAction("check");
  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
}

void NativeClient::compute()
{
  std::vector<std::string> choices, split;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }

  std::string cdcmd = "";
  if(getWorkingDir().size()) cdcmd.append("cd " + getWorkingDir() + cmdSep);

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) mySystem(cdcmd + rmcmd);

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }
}

// ENCAPSULATED Client
// EncapsulatedClient's are InterfacedClient's called via the loader
// so that Gmsh sees them as a localNetworkClient

void EncapsulatedClient::analyze()
{
  std::vector<std::string> choices, split;

  OLMsg::Info("Analyzes <%s> changed=%d", getName().c_str(),
              onelab::server::instance()->getChanged(getName()));
  setAction("check");

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++) {
    split = SplitOLFileName(choices[i]);
    if(split[2].size()) { // if .ol file
      std::string fileName = getWorkingDir() + split[1] + split[2];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
      OLMsg::Info("Parse file <%s> %s", fileName.c_str(),
                  parse_onefile(fileName) ? "done" : "failed");
    }
  }
  convert();
}

void EncapsulatedClient::convert()
{
  std::vector<std::string> choices, split;

  getList("InputFiles", choices);
  for(unsigned int i = 0; i < choices.size(); i++) {
    split = SplitOLFileName(choices[i]);
    if(split[2].size()) { // if .ol file
      std::string fileName = getWorkingDir() + split[1] + split[2];
      std::string ofileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
      std::ofstream outfile(ofileName.c_str());
      if(outfile.is_open())
        convert_onefile(fileName, outfile);
      else
        OLMsg::Error("The file <%s> cannot be opened", ofileName.c_str());
      outfile.close();
    }
  }
}

std::string EncapsulatedClient::buildCommandLine()
{
  std::string cmd = OLMsg::GetOnelabString("LoaderPathName");
  OLMsg::Info("Loader pathname=<%s>", cmd.c_str());
  return cmd;
}

void EncapsulatedClient::compute()
{
  std::vector<std::string> choices, split;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }

  std::string cdcmd = "";
  if(getWorkingDir().size()) cdcmd.append("cd " + getWorkingDir() + cmdSep);

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) mySystem(cdcmd + rmcmd);

  // the client command line is built and stored in a onelab parameter
  std::string cmd;
  cmd.assign(cdcmd);
  cmd.append(QuoteExecPath(getCommandLine()) + " " + getString("Arguments"));
  OLMsg::SetOnelabString(getName() + "/FullCmdLine", cmd, false);
  OLMsg::Info("Command line=<%s>", cmd.c_str());

  if(!run()) // localNetworkClient::run() is called
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++) {
      split = SplitOLFileName(choices[i]);
      std::string fileName = getWorkingDir() + split[1];
      if(!checkIfPresent(fileName))
        OLMsg::Error("The file <%s> is not present", fileName.c_str());
    }
  }
}

// REMOTE INTERFACED Client

bool RemoteInterfacedClient::checkCommandLine()
{
  bool success;
  OLMsg::Info("Check command line <%s> for client <%s>",
              getCommandLine().c_str(), getName().c_str());
  if(getCommandLine().empty()) return false;
  success = remoteClient::checkCommandLine(getCommandLine());
  if(success) {
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), false);
    OLMsg::Info("Command line ok");
  }
  else {
    // setCommandLine("");
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), true);
    OLMsg::Error("Invalid command line <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
  }
  return success;
}

void RemoteInterfacedClient::compute()
{
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncInputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) {
    std::string cdcmd;
    // remove files on local machine
    if(getWorkingDir().size()) cdcmd.assign("cd " + getWorkingDir() + cmdSep);
    mySystem(cdcmd + rmcmd);

    // remove files on distant machine
    if(getRemoteDir().size()) cdcmd.assign("cd " + getRemoteDir() + cmdSep);
    mySystem("ssh " + getRemoteHost() + " '" + cdcmd + rmcmd + "'");
  }

  std::string cmd;
  cmd.assign("ssh " + getRemoteHost() + " '");
  if(getRemoteDir().size()) cmd.append("cd " + getRemoteDir() + cmdSep);
  cmd.append(" " + QuoteExecPath(getCommandLine()));
  cmd.append(" " + getString("Arguments") + " '");
  mySystem(cmd);

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncOutputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }
}

// REMOTE NATIVE Client

std::string RemoteNativeClient::buildCommandLine()
{
  std::string command;
  command.assign("incomp_ssh -f " + getRemoteHost() + " '");
  if(getRemoteDir().size()) command.append("cd " + getRemoteDir() + cmdSep);
  command.append(" " + QuoteExecPath(getCommandLine()) + " ");
  return command;
}

bool RemoteNativeClient::checkCommandLine()
{
  bool success;
  OLMsg::Info("Check command line <%s> for client <%s>",
              getCommandLine().c_str(), getName().c_str());
  if(getCommandLine().empty()) return false;
  success = remoteClient::checkCommandLine(getCommandLine());
  if(success) {
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), false);
    OLMsg::Info("Command line ok");
  }
  else {
    // setCommandLine("");
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), true);
    OLMsg::Error("Invalid command line <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
  }
  return success;
}

void RemoteNativeClient::analyze()
{
  std::string cmd, rmcmd;
  std::vector<std::string> choices;

  OLMsg::Info("Analyzes <%s> changed=%d", getName().c_str(),
              onelab::server::instance()->getChanged(getName()));
  setAction("check");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncInputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
}

void RemoteNativeClient::compute()
{
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncInputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) {
    std::string cdcmd;
    // remove files on local machine
    if(getWorkingDir().size()) cdcmd.assign("cd " + getWorkingDir() + cmdSep);
    mySystem(cdcmd + rmcmd);

    // remove files on distant machine
    if(getRemoteDir().size()) cdcmd.assign("cd " + getRemoteDir() + cmdSep);
    mySystem("ssh " + getRemoteHost() + " '" + cdcmd + rmcmd + "'");
  }

  if(!run())
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncOutputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }
}

// REMOTE ENCAPSULATED Client

// bool RemoteEncapsulatedClient::checkCommandLine(){
//   return remoteClient::checkCommandLine(getCommandLine());
// }

bool RemoteEncapsulatedClient::checkCommandLine()
{
  bool success;
  OLMsg::Info("Check command line <%s> for client <%s>",
              getCommandLine().c_str(), getName().c_str());
  if(getCommandLine().empty()) return false;
  success = remoteClient::checkCommandLine(getCommandLine());
  if(success) {
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), false);
    OLMsg::Info("Command line ok");
  }
  else {
    //   setCommandLine("");
    OLMsg::SetOnelabString(getName() + "/CommandLine", getCommandLine(), true);
    OLMsg::Error("Invalid command line <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());
  }
  return success;
}

std::string RemoteEncapsulatedClient::buildCommandLine()
{
  std::string cmd = OLMsg::GetOnelabString("LoaderPathName");
  OLMsg::Info("Loader pathname=<%s>", cmd.c_str());
  return cmd;
}

void RemoteEncapsulatedClient::compute()
{
  std::vector<std::string> choices;

  analyze();
  if(OLMsg::GetErrorCount()) return;
  OLMsg::Info("Computes <%s>", getName().c_str());
  setAction("compute");

  if(getList("InputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncInputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }

  std::string rmcmd = "";
  if(buildRmCommand(rmcmd)) {
    std::string cdcmd;
    // remove files on local machine
    if(getWorkingDir().size()) cdcmd.assign("cd " + getWorkingDir() + cmdSep);
    mySystem(cdcmd + rmcmd);

    // remove files on distant machine
    if(getRemoteDir().size()) cdcmd.assign("cd " + getRemoteDir() + cmdSep);
    mySystem("ssh " + getRemoteHost() + " '" + cdcmd + rmcmd + "'");
  }

  // the client command line is built and stored in a onelab parameter
  std::string cmd;
  cmd.assign("ssh " + getRemoteHost() + " '");
  if(getRemoteDir().size()) cmd.append("cd " + getRemoteDir() + cmdSep);
  cmd.append(" " + QuoteExecPath(getCommandLine()));
  cmd.append(" " + getString("Arguments") + " '");
  OLMsg::SetOnelabString(getName() + "/FullCmdLine", cmd, false);

  OLMsg::Info("Command line=<%s>", cmd.c_str());

  if(!run()) // localNetworkClient::run() is called
    OLMsg::Error("Invalid commandline <%s> for client <%s>",
                 getCommandLine().c_str(), getName().c_str());

  if(getList("OutputFiles", choices)) {
    for(unsigned int i = 0; i < choices.size(); i++)
      if(syncOutputFile(getWorkingDir(), choices[i])) OLMsg::Info("ok");
  }
}

// ONELAB additional TOOLS (no access to server, no messages)

std::string itoa(const int i)
{
  std::ostringstream tmp;
  tmp << i;
  return tmp.str();
}

std::string ftoa(const double x)
{
  std::stringstream Num;
  Num << x;
  return Num.str();
}

int mySystem(std::string commandLine)
{
  // Don't use OLMsg::Info here otherwise the message appears twice
  // in the Gmsh message window.
  if(OLMsg::GetVerbosity())
    std::cout << "Onelab: Calling <" << commandLine << ">" << std::endl;
  return SystemCall(commandLine.c_str(), true);
}

#include <sys/stat.h>
#include <ctime>
#if defined(WIN32)
#include <io.h>
#endif

bool checkIfPresent(std::string fileName)
{
  struct stat buf;
  if(!stat(fileName.c_str(), &buf))
    return true;
  else
    return false;
}
bool chmod(std::string fileName)
{
  struct stat info;
  stat(fileName.c_str(), &info);
  // chmod u=rwx
#if defined(WIN32)
  if(_chmod(fileName.c_str(), _S_IREAD | _S_IWRITE) != 0) {
#else
  if(chmod(fileName.c_str(), S_IRWXU) != 0) {
#endif
    perror("chmod() error");
    return false;
  }
  return true;
}

#include <sys/types.h>

#if !defined(WIN32)
#include <unistd.h>
#include <pwd.h>
std::string getUserHomedir()
{
  struct passwd *pw = getpwuid(getuid());
  std::string str(pw->pw_dir);
  str.append("/");
  return str;
}
#include <sys/param.h>
#else
#include <direct.h>
#endif

std::string sanitizeString(const std::string &in, const std::string &forbidden)
{
  std::string out;
  for(unsigned int i = 0; i < in.size(); i++)
    if(forbidden.find(in[i]) == std::string::npos) out.push_back(in[i]);
  return out;
}

std::string sanitize(const std::string &in)
{
  std::string out, forbidden(" ();\n");
  for(unsigned int i = 0; i < in.size(); i++)
    if(forbidden.find(in[i]) == std::string::npos) out.push_back(in[i]);
  return out;
}

std::string quote(const std::string &in) { return "\"" + in + "\""; }
std::string unquote(const std::string &in)
{
  if(in.empty()) return "";
  size_t pos0 = in.find_first_not_of(" ");
  size_t pos = in.find_last_not_of(" ");
  if((pos0 != std::string::npos) && (!in.compare(pos0, 1, "\""))) pos0++;
  if((pos != std::string::npos) && (!in.compare(pos, 1, "\""))) pos--;
  return in.substr(pos0, pos - pos0 + 1);
}

std::string FixWindowsQuotes(const std::string &in)
{
#if defined(WIN32)
  return "\"" + in + "\"";
#else
  return in;
#endif
}

std::string QuoteExecPath(const std::string &in)
{
  std::string cmd;
  cmd.assign(removeBlanks(in));
  cmd.assign(FixWindowsPath(cmd));
  if(cmd[0] != '\"') cmd.assign(quote(cmd));
  return cmd;
}

std::string removeBlanks(const std::string &in)
{
  size_t pos0 = in.find_first_not_of(" \t");
  size_t pos = in.find_last_not_of(" \t");
  if((pos0 != std::string::npos) && (pos != std::string::npos))
    return in.substr(pos0, pos - pos0 + 1);
  else
    return "";
}

std::vector<std::string> SplitOLFileName(const std::string &in)
{
  // returns [local file tag, baseName, ol extension]
  size_t posb = in.find(onelabExtension);
  size_t posa = in.find(localFileTag) + localFileTag.size();

  if(posb != in.size() - onelabExtension.size()) posb = in.size();
  if(posa != localFileTag.size()) posa = 0;

  std::vector<std::string> s(3);
  s[0] = in.substr(0, posa);
  s[1] = in.substr(posa, posb - posa);
  s[2] = in.substr(posb, in.size() - posb);

  // std::cout << "FHF in=<" << s[0] << "|" << s[1] << "|" << s[2] << ">" <<
  // std::endl;
  return s;
}

std::vector<std::string> SplitOLHostName(const std::string &in)
{
  // returns [ hostname, directory]
  std::vector<std::string> s(2);
  size_t pos = in.find(":");
  if(pos == std::string::npos) {
    s[0] = in;
    s[1] = "";
  }
  else {
    s[0] = in.substr(0, pos);
    s[1] = FixPathName(in.substr(pos + 1, in.size() - pos - 1));
  }
  // std::cout << "FHF in=<" << s[0] << "|" << s[1] << std::endl;
  return s;
}

std::string FixOLPath(const std::string &in)
{
  std::string out = in;
  if(out.size()) {
    size_t pos = out.find_last_not_of(" 0123456789");
    if((pos != std::string::npos) && (out.compare(pos, 1, "/")))
      out.insert(pos, "/");
  }
  return out;
}

std::string FixPathName(const std::string &in)
{
  std::string out = in;
  if(out.size())
    if(out[out.size() - 1] != dirSep) out.push_back(dirSep);
  return out;
}

// std::vector <double> extract_column(const unsigned int col, const array
// data){
//   std::vector<double> column;
//   for(unsigned int i=0; i<data.size(); i++)
//     if(col<=data[i].size())
//       column.push_back(data[i][col-1]);
//     else
//       OLMsg::Error("Column number (%d) out of range.",col);
//   return column;
// }

double find_in_array(int lin, int col,
                     const std::vector<std::vector<double> > &data)
{
  if(data.size()) {
    if(lin < 0) lin = (int)data.size() - 1;
    if(lin < (int)data.size()) {
      if(col >= 0 && col < (int)data[lin].size()) return data[lin][col];
    }
  }
  OLMsg::Error("Find in array: (%d,%d) out of range", lin, col);
  return (0);
}

array read_array(std::string fileName, char sep)
{
  std::ifstream infile(sanitize(fileName).c_str());
  std::vector<std::vector<double> > array;

  size_t deb, end;
  double temp;
  while(infile) {
    std::string s;
    if(!getline(infile, s)) break;
    std::vector<double> record;
    end = 0;
    while((deb = s.find_first_not_of(" \t\n", end)) != std::string::npos) {
      end = s.find_first_of(" \t\n", deb);
      temp = atof(s.substr(deb, end).c_str());
      record.push_back(temp);
    }
    array.push_back(record);
  }
  if(!infile.eof()) {
    OLMsg::Error("Error reading array\n");
    array.resize(0);
  }
  return array;
}

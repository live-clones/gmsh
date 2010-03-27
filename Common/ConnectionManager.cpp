// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "ConnectionManager.h"
#include "StringUtils.h"
#include "OS.h"
#include "Context.h"

std::map<int, ConnectionManager*> ConnectionManager::_all;

ConnectionManager::ConnectionManager()
  : clientServer(1), popupMessages(1), mergeViews(1), _pid(0), _server(0)
{
  // we need at least five for the solver menu
  buttonName.resize(5);
  buttonSwitch.resize(5);
  optionName.resize(5);
  optionValue.resize(5);
}

std::string ConnectionManager::getSocketName()
{
  // FIXME: this should be changed to incorporate info about the
  // connection number (i.e. the integer in the _all map) so that we
  // can have several connections active at the same time
  std::string sockname;
  if(!strstr(CTX::instance()->solver.socketName.c_str(), ":")){
    // Unix socket
    std::ostringstream tmp;
    tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName;
    sockname = FixWindowsPath(tmp.str());
  }
  else{
    // TCP/IP socket
    sockname = CTX::instance()->solver.socketName;
    // if only the port is given, prepend the host name
    if(sockname.size() && sockname[0] == ':')
      sockname = GetHostName() + sockname;
  }
  return sockname;
}

void ConnectionManager::runToGetOptions()
{
  if(inputFileName.empty()) return;
  
  std::string inputArg = inputFileName.empty() ? "" : ReplaceSubString
    ("%s", std::string("\"") + FixWindowsPath(inputFileName) + "\"", inputFileSwitch);
  std::string optionArg = ReplaceSubString("%s", "", optionSwitch);
  run(inputArg + " " + optionArg);
}

void ConnectionManager::runCommand(int commandIndex, int optionIndex, int optionChoice)
{
  std::string inputArg = inputFileName.empty() ? "" : ReplaceSubString
    ("%s", std::string("\"") + FixWindowsPath(inputFileName) + "\"", inputFileSwitch);

  std::string meshArg = meshFileName.empty() ? "" : ReplaceSubString
    ("%s", std::string("\"") + FixWindowsPath(meshFileName) + "\"", meshFileSwitch);

  if(commandIndex < 0 || commandIndex >= (int)buttonSwitch.size()){
    Msg::Error("Wrong command index");
    return;
  }

  if(optionIndex < 0 || optionIndex >= (int)optionValue.size()){
    Msg::Error("Wrong option index");
    return;
  }

  std::string commandArg;
  if(optionValue[optionIndex].size()){
    if(optionChoice < 0 || optionChoice >= (int)optionValue[optionIndex].size()){
      Msg::Error("Wrong option choice");
      return;
    }
    commandArg = ReplaceSubString
      ("%s", optionValue[optionIndex][optionChoice], buttonSwitch[commandIndex]);
  }
  else{ // no options
    commandArg = buttonSwitch[commandIndex];
  }

  run(inputArg + " " + meshArg + " " + commandArg + " " + extraArguments);
}

#if !defined(HAVE_FLTK)

void ConnectionManager::run(std::string args)
{
  Msg::Error("Gmsh has to be compiled with FLTK support to run remote apps");
}

#endif

void ConnectionManager::kill()
{
  if(_pid > 0) {
    if(KillProcess(_pid))
      Msg::Info("Killed '%s' (pid %d)", name.c_str(), _pid);
  }
  _pid = -1;
}

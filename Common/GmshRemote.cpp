// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshRemote.h"
#include "StringUtils.h"
#include "OS.h"
#include "Context.h"

std::map<int, GmshRemote*> GmshRemote::_all;

GmshRemote::GmshRemote()
  : clientServer(1), popupMessages(1), mergeViews(1), _pid(0), _server(0)
{
  // we need at least five for the solver menu
  buttonName.resize(5);
  buttonSwitch.resize(5);
  optionName.resize(5);
  optionValue.resize(5);
}

std::string GmshRemote::getSocketName()
{
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

void GmshRemote::runToGetOptions()
{
  if(inputFileName.empty()) return;
  
  std::string inputArg = inputFileName.empty() ? "" : ReplacePercentS
    (inputFileSwitch, std::string("\"") + FixWindowsPath(inputFileName) + "\"");
  std::string optionArg = ReplacePercentS(optionSwitch, "");
  run(inputArg + " " + optionArg);
}

void GmshRemote::runCommand(int commandIndex, int optionIndex, int optionChoice)
{
  std::string inputArg = inputFileName.empty() ? "" : ReplacePercentS
    (inputFileSwitch, std::string("\"") + FixWindowsPath(inputFileName) + "\"");

  std::string meshArg = meshFileName.empty() ? "" : ReplacePercentS
    (meshFileSwitch, std::string("\"") + FixWindowsPath(meshFileName) + "\"");

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
    commandArg = ReplacePercentS
      (buttonSwitch[commandIndex], optionValue[optionIndex][optionChoice]);
  }
  else{ // no options
    commandArg = buttonSwitch[commandIndex];
  }

  run(inputArg + " " + meshArg + " " + commandArg);
}

#if !defined(HAVE_FLTK)

void GmshRemote::run(std::string args)
{
  Msg::Error("Gmsh has to be compiled with FLTK support to run remote apps");
}

#endif

void GmshRemote::kill()
{
  if(_pid > 0) {
    if(KillProcess(_pid))
      Msg::Info("Killed %s pid %d", name.c_str(), _pid);
  }
  _pid = -1;
}

// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CONNECTION_MANAGER_H_
#define _CONNECTION_MANAGER_H_

#include <string>
#include <vector>
#include <map>

class GmshServer;

class ConnectionManager {
 public:
  // the name of the remote program (e.g. "GetDP")
  std::string name;
  // the executable command (e.g. "/usr/bin/getdp.exe")
  std::string executable;
  // the name of the input file for the remote program (e.g. "")
  std::string inputFileName;
  // the command line switch to specify the input file (e.g. "%s")
  std::string inputFileSwitch;
  // the standard extension of input file names for the remote program
  // (e.g. ".pro")
  std::string inputFileExtension;
  // the name of the mesh file used by the remote program (e.g. "")
  std::string meshFileName;
  // the command line switch used to specify the mesh file
  // (e.g. "-mesh %s")
  std::string meshFileSwitch;
  // the command line switch used to specify the socket (e.g. "-socket
  // %s")
  std::string socketSwitch;
  // the names of the action buttons in the GUI (e.g. "Pre", "Cal",
  // "Post")
  std::vector<std::string> buttonName;
  // the command line switches associated with the buttons (e.g. "-pre
  // %s", "-cal", "-pos %s"); each %s will consume one of the options,
  // in the order the buttons are defined
  std::vector<std::string> buttonSwitch;
  // the name of the options that can be passed to the remote program
  // (e.g. "Resolution", "PostOperation")
  std::vector<std::string> optionName;
  // the command line switch to get the available values for all the
  // options
  std::string optionSwitch;
  // the possible values for each option (these are normally
  // dynamically filled by calling the remote program with the
  // optionSwitch command line arg)
  std::vector<std::vector<std::string> > optionValue;
  // a help string describing the remote program
  std::string help;
  // set to true if the remote program should communicate with Gmsh
  // through a socket
  bool clientServer;
  // set to true if remote messages should pop up the message window
  bool popupMessages;
  // set to true if remotely generated post-processing files should be
  // merged by Gmsh
  bool mergeViews;
 private:
  // the process id number of the remote program while it is running,
  // or -1 when stopped
  int _pid;
  // a pointer to the server when the remote program is running, or 0
  // when stopped
  GmshServer *_server;
  // a static map of all available remote programs: values 0, 1, 2, 3,
  // 4 are reserved for the main solver menu; -1 is used when
  // permanently listening for incoming connections; 99 is used for
  // remote Gmsh
  static std::map<int, ConnectionManager*> _all;
 public:
  ConnectionManager();
  ~ConnectionManager(){}
  // get the name of the socket
  std::string getSocketName();
  // get/set the pid
  int getPid(){ return _pid; }
  void setPid(int pid){ _pid = pid; }
  // get/set the server
  GmshServer *getServer(){ return _server; }
  void setServer(GmshServer *server){ _server = server; }
  // get the num-th remote program; if it does not exist, create it
  static ConnectionManager *get(int num)
  {
    std::map<int, ConnectionManager*>::iterator it = _all.find(num);
    if(it == _all.end()){
      ConnectionManager *s = new ConnectionManager();
      _all[num] = s;
      return s;
    }
    return it->second;
  }
  // run the remote program to get its options
  void runToGetOptions();
  // run the commandIndex-th command (button), using the specified
  // option
  void runCommand(int commandIndex, int optionIndex, int optionChoice);
  // run the remote program with the given arguments
  void run(std::string args);
  // kill the remote program
  void kill();
};

#endif

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_UTILS_H
#define ONELAB_UTILS_H

#include "onelab.h"

// onelab utility routines used both in the FLTK onelab server and in other
// onelab servers

namespace onelabUtils {
  // a solver linked in the program (GetDP in the web app), run in-process
  // instead of through a socket: the function gets the command line of the
  // solver (with "-onelab name" and no socket) and the ONELAB server, as
  // getdp(args, server)
  typedef int (*inProcessSolver)(const std::vector<std::string> &args,
                                 void *server);
  void setInProcessSolver(const std::string &name, inProcessSolver solver);
  inProcessSolver getInProcessSolver(const std::string &name);
  std::vector<std::string> getCommandLine(onelab::client *c);
  std::string getMshFileName(onelab::client *c);
  void guessModelName(onelab::client *c);
  void initializeLoop(const std::string &level);
  bool incrementLoop(const std::string &level);
  std::vector<double> getRange(onelab::number &p);
  bool updateGraph(const std::string &graphNum);
  bool runGmshClient(const std::string &action, int meshAuto);
  void runClient(const std::string &name = "", const std::string &command = "");
  bool getFirstComputationFlag();
  void setFirstComputationFlag(bool val);
  bool haveSolverToRun();
  double updateNumber(onelab::number &x, onelab::number &y,
                      const bool readOnlyRange = false);
  std::string updateString(onelab::string &x, onelab::string &y);
  void initializeLoops();
  bool incrementLoops();
  void updateGraphs();
  std::string timeStamp();
  void saveDb(const std::string &fileName);
  void archiveOutputFiles(const std::string &fileName);
  void archiveSolutionFiles(const std::string &fileName);
  void loadDb(const std::string &name);
  void resetDb(bool runGmshClient);
} // namespace onelabUtils

#endif

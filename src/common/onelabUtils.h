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
  // the loops over parameters (see Loop in onelab.h) started, and the next
  // step of the innermost one taken: false when they are over
  void initializeLoops();
  bool incrementLoops();
  // the graphs of the parameters (their "Graph" attribute) made again: true
  // if views were added or changed, for the interface to show them
  bool updateGraphs();
  // The run loops of the interfaces (the graphical interface, the batch mode,
  // the web page) share these.
  // - Whether a client is a solver they run: not Gmsh itself, nor a client
  //   connecting on its own, nor one whose name says NoAutoRun.
  bool isAutoRunSolver(onelab::client *c);
  // - A solver about to run an action: its model name guessed, the action set.
  void setSolverAction(onelab::client *c, const std::string &action);
  // - A solver running an action; after a compute, the parameters are marked
  //   as unchanged for it.
  void runSolver(onelab::client *c, const std::string &action);
  // - The database file (Gmsh/DatabaseFileName, or the model's name with
  //   .db); after a compute, the output files archived and the database saved
  //   as the Solver options ask (true if one was).
  std::string dbFileName();
  bool afterCompute();

  std::string timeStamp();
  void saveDb(const std::string &fileName);
  void archiveOutputFiles(const std::string &fileName);
  void archiveSolutionFiles(const std::string &fileName);
  void loadDb(const std::string &name);
  void resetDb(bool runGmshClient);
  // what an interface does when the user changes a parameter, besides storing
  // it: the global action the parameter asks for ("ServerAction" attribute, or
  // "GmshOption" for backward compatibility: "ResetDatabase", "Reset" or
  // "Reset<names>"), true if one was performed (the interface then rebuilds
  // its list of parameters)...
  bool serverAction(const std::string &action);
  // ... the actions on other parameters ("ServerAction<Set, Show...>"
  // attributes) ...
  void performServerAction(const onelab::number &p);
  void performServerAction(const onelab::string &p);
  // ... the Gmsh option the parameter stands for ("GmshOption" attribute) ...
  void setGmshOption(const onelab::number &p);
  void setGmshOption(const onelab::string &p);
  // ... and whether to "check" the model, the value going from pold to pnew
  bool autoCheck(const onelab::number &pold, const onelab::number &pnew,
                 bool force = false);
  bool autoCheck(const onelab::string &pold, const onelab::string &pnew,
                 bool force = false);
  // all of this for a parameter changed in an interface (the tree of the
  // graphical interface, the web page), and its new value stored, in that
  // order; what the interface is to do next:
  enum {
    ParameterCheck = 1, // check the model (always if forced)
    ParameterRebuild = 2, // rebuild the list of parameters
    ParameterOption = 4 // redraw, a Gmsh option being set
  };
  int setParameter(onelab::number &p, bool force = false);
  int setParameter(onelab::string &p, bool force = false);
} // namespace onelabUtils

#endif

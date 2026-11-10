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
  // a file a solver asks to show, merged if Solver.AutoMergeFile is set: what
  // the merge changes in Gmsh's parameters (e.g. a view option given by a
  // parameter) is no reason to redo Gmsh's part, and each keeps its level of
  // change. Returns true if the file was merged
  bool mergeSolverFile(const std::string &fileName);
  // The loop of an action on the model ("initialize", "check", "check_always"
  // or "compute"), the same for every interface (the FLTK graphical user
  // interface, the batch mode, the web page): Gmsh's part of a pass, then the
  // solvers, pass after pass of the loops over the parameters when computing.
  // An interface steps it, to show what each step changes, to stop between
  // the steps, or to run the solvers elsewhere (the web page runs them in a
  // worker):
  //   onelabLoop loop(action);
  //   do {
  //     loop.runGmsh();
  //     for(onelab::client *c : loop.solvers()) loop.runSolver(c);
  //   } while(loop.nextPass());
  //   loop.finish();
  class onelabLoop {
    std::string _action;
    bool _graphsChanged = false;

  public:
    // the errors counted from here; when computing, the loops over the
    // parameters started
    onelabLoop(const std::string &action);
    const std::string &action() const { return _action; }
    // Gmsh's part of a pass: the model read again, and meshed, as the
    // parameters say; true if views changed (for the interface to draw them)
    bool runGmsh();
    // the solvers of this pass, each given the action (its model name
    // guessed): not Gmsh itself, nor a client connecting on its own, nor one
    // whose name says NoAutoRun
    std::vector<onelab::client *> solvers();
    // a solver run; or run by the interface, which then says so: after a
    // compute, the parameters are marked as unchanged for it
    void runSolver(onelab::client *c);
    void solverDone(onelab::client *c);
    // the end of a pass: the graphs made again, then, unless the interface
    // stops here, the loops over the parameters stepped: true if there is
    // another pass
    bool nextPass(bool goOn = true);
    // whether the graphs of the last pass added or changed views (for the
    // interface to show them)
    bool graphsChanged() const { return _graphsChanged; }
    // the end: after a compute, the output files archived and the database
    // saved as the Solver options ask (true if one was)
    bool finish();
  };
  // the database file (Gmsh/DatabaseFileName, or the model's name with .db)
  std::string dbFileName();

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

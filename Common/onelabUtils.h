// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _ONELAB_UTILS_H_
#define _ONELAB_UTILS_H_

#include "onelab.h"

// onelab utility routines used both in the FLTK onelab server and in other
// onelab servers

namespace onelabUtils {
  std::vector<std::string> getCommandLine(onelab::client *c);
  std::string getMshFileName(onelab::client *c);
  void guessModelName(onelab::client *c);
  void initializeLoop(const std::string &level);
  bool incrementLoop(const std::string &level);
  std::vector<double> getRange(onelab::number &p);
  bool updateGraph(const std::string &graphNum);
  bool runGmshClient(const std::string &action, int meshAuto);
  bool getFirstComputationFlag();
  void setFirstComputationFlag(bool val);
  bool haveSolverToRun();

  double updateNumber(onelab::number &x, onelab::number &y, const bool readOnlyRange=false);
  std::string updateString(onelab::string &x, onelab::string &y);
}

#endif

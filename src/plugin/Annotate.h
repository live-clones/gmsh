// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ANNOTATE_H
#define ANNOTATE_H

#include <string>
#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterAnnotatePlugin();
}

class GMSH_AnnotatePlugin : public GMSH_PostPlugin {
private:
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  static std::string callbackStr(int num, int action, const std::string &value,
                                 std::string &opt);

public:
  GMSH_AnnotatePlugin() {}
  std::string getName() const { return "Annotate"; }
  std::string getShortHelp() const { return "Add a text annotation"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);

  static double callbackX(int, int, double);
  static double callbackY(int, int, double);
  static double callbackZ(int, int, double);
  static double callback3D(int, int, double);
  static double callbackFontSize(int, int, double);
  static std::string callbackText(int, int, const std::string &);
  static std::string callbackFont(int, int, const std::string &);
  static std::string callbackAlign(int, int, const std::string &);
  static void draw(void *context);
};

#endif

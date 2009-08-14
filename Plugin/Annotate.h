// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ANNOTATE_H_
#define _ANNOTATE_H_

#include <string>
#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnnotatePlugin();
}

class GMSH_AnnotatePlugin : public GMSH_PostPlugin
{
 private:
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
  static std::string callbackStr(int num, int action, std::string value,
                                 std::string &opt);
 public:
  GMSH_AnnotatePlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *helpText) const;
  void catchErrorMessage(char *errorMessage) const;
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
  static std::string callbackText(int, int, std::string);
  static std::string callbackFont(int, int, std::string);
  static std::string callbackAlign(int, int, std::string);
  static void draw(void *context);
};

#endif

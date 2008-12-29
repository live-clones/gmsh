// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STREAM_LINES_H_
#define _STREAM_LINES_H

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStreamLinesPlugin ();
}

class GMSH_StreamLinesPlugin : public GMSH_Post_Plugin
{
  static double callback(int num, int action, double value, double *opt,
                         double step, double min, double max);
public:
  GMSH_StreamLinesPlugin(){}
  void getName(char *name) const;
  void getInfos(char *author, char *copyright, char *help_text) const;
  void catchErrorMessage(char *errorMessage) const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  PView *execute(PView *);

  static int getNbU();
  static int getNbV();
  static void getPoint(int iU, int iV, double *X);

  static double callbackX0(int, int, double);
  static double callbackY0(int, int, double);
  static double callbackZ0(int, int, double);
  static double callbackX1(int, int, double);
  static double callbackY1(int, int, double);
  static double callbackZ1(int, int, double);
  static double callbackX2(int, int, double);
  static double callbackY2(int, int, double);
  static double callbackZ2(int, int, double);
  static double callbackU(int, int, double);
  static double callbackV(int, int, double);
  static void draw(void *context);
};

#endif

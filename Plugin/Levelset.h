// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LEVELSET_H_
#define _LEVELSET_H_

#include "Plugin.h"

class GMSH_LevelsetPlugin : public GMSH_PostPlugin
{
 private:
  double _invert;
  void _addElement(int np, int numEdges, int numComp,
                   double xp[12], double yp[12], double zp[12],
                   double valp[12][9], PViewDataList *out,
                   bool firstStep);
  void _cutAndAddElements(PViewData *vdata, PViewData *wdata,
                          int ent, int ele, int step, int wstep,
                          double x[8], double y[8], double z[8],
                          double levels[8], double scalarValues[8],
                          PViewDataList *out);
 protected:
  double _ref[3], _targetError;
  int _valueTimeStep, _valueView, _valueIndependent, _recurLevel, _extractVolume;
  typedef enum {NONE, PLANE, SPHERE, MAP} ORIENTATION;
  ORIENTATION _orientation;
 public:
  GMSH_LevelsetPlugin();
  virtual double levelset(double x, double y, double z, double val) const = 0;
  virtual PView *execute(PView *);
  void assignSpecificVisibility() const;
};

#endif

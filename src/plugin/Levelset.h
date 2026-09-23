// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LEVELSET_H
#define LEVELSET_H

#include "Plugin.h"

class GMSH_LevelsetPlugin : public GMSH_PostPlugin {
private:
  double _invert;
  void _addElement(int np, int numEdges, int numComp, double xp[12],
                   double yp[12], double zp[12], double valp[12][9],
                   PViewDataList *out, bool firstStep);
  // cut the element (ent, ele), or one of the sub-simplices of a polytope if
  // simplexType >= 0: then numNodes, numEdges and nodeMap (the indices of the
  // nodes of the simplex in the polytope) describe the simplex
  void _cutAndAddElements(PViewData *vdata, PViewData *wdata, int ent, int ele,
                          int step, int wstep, double x[8], double y[8],
                          double z[8], double levels[8], double scalarValues[8],
                          PViewDataList *out, int simplexType = -1,
                          int numNodes = 0, int numEdges = 0,
                          const int *nodeMap = nullptr);
  void _cutPolytope(PViewData *vdata, PViewData *wdata, int ent, int ele,
                    int step, int wstep, PViewDataList *out);

protected:
  double _ref[3], _targetError;
  int _valueTimeStep, _valueView, _valueIndependent, _recurLevel;
  int _extractVolume, _visible;
  typedef enum { NONE, PLANE, SPHERE, MAP } ORIENTATION;
  ORIENTATION _orientation;

public:
  GMSH_LevelsetPlugin(const std::vector<StringXNumber> &numOptions = {},
                      const std::vector<StringXString> &strOptions = {});
  virtual double levelset(double x, double y, double z, double val) const = 0;
  virtual PView *execute(PView *);
  void assignSpecificVisibility(adaptiveElement *root) const;
};

#endif

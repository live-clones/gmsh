// MeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef MESH_OPT_H
#define MESH_OPT_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include "ObjectiveFunction.h"
#include "Patch.h"

class MeshOptParameters;

class MeshOpt {
public:
  Patch patch;
  MeshOpt(const std::map<MElement *, GEntity *> &element2entity,
          const std::map<MElement *, GEntity *> &bndEl2Ent,
          const std::set<MElement *> &els, std::set<MVertex *> &toFix,
          const std::set<MElement *> &bndEls, const MeshOptParameters &par);
  ~MeshOpt();
  int optimize(const MeshOptParameters &par);
  void updateMesh(const std::vector<double> &x);
  void updateResults();
  void evalObjGrad(const std::vector<double> &x, double &Obj,
                   std::vector<double> &gradObj);
  void printProgress(const std::vector<double> &x, double Obj);
  ObjectiveFunction *objFunction();

private:
  int _verbose;
  bool _nCurses;
  std::list<char *> _iterHistory, _optHistory;
  int _iPass;
  // Contributions to objective function for current pass
  std::vector<ObjectiveFunction> _allObjFunc;
  // Contributions to objective function for current pass
  ObjectiveFunction *_objFunc;
  // Current iteration, interval of iterations for reporting
  int _iter, _intervDisplay;
  // Values for reporting
  double _initObj;
  void calcScale(std::vector<double> &scale);
  void runOptim(std::vector<double> &x, const std::vector<double> &initGradObj,
                int itMax, int iBar);
};

#endif
